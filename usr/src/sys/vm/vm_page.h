begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * %sccs.include.redist.c%  *  *	@(#)vm_page.h	7.6 (Berkeley) %G%  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  *	Resident memory system definitions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VM_PAGE_
end_ifndef

begin_define
define|#
directive|define
name|_VM_PAGE_
end_define

begin_comment
comment|/*  *	Management of resident (logical) pages.  *  *	A small structure is kept for each resident  *	page, indexed by page number.  Each structure  *	is an element of several lists:  *  *		A hash table bucket used to quickly  *		perform object/offset lookups  *  *		A list of all pages for a given object,  *		so they can be quickly deactivated at  *		time of deallocation.  *  *		An ordered list of pages due for pageout.  *  *	In addition, the structure contains the object  *	and offset to which this page belongs (for pageout),  *	and sundry status bits.  *  *	Fields in this structure are locked either by the lock on the  *	object that the page belongs to (O) or by the lock on the page  *	queues (P).  */
end_comment

begin_struct
struct|struct
name|vm_page
block|{
name|queue_chain_t
name|pageq
decl_stmt|;
comment|/* queue info for FIFO 					 * queue or free list (P) */
name|queue_chain_t
name|hashq
decl_stmt|;
comment|/* hash table links (O)*/
name|queue_chain_t
name|listq
decl_stmt|;
comment|/* all pages in same object (O)*/
name|vm_object_t
name|object
decl_stmt|;
comment|/* which object am I in (O,P)*/
name|vm_offset_t
name|offset
decl_stmt|;
comment|/* offset into that object (O,P) */
name|unsigned
name|int
name|wire_count
range|:
literal|16
decl_stmt|,
comment|/* how many wired down maps use me? 					   (P) */
comment|/* boolean_t */
name|inactive
range|:
literal|1
decl_stmt|,
comment|/* page is in inactive list (P) */
name|active
range|:
literal|1
decl_stmt|,
comment|/* page is in active list (P) */
name|laundry
range|:
literal|1
decl_stmt|,
comment|/* page is being cleaned now (P)*/
ifdef|#
directive|ifdef
name|DEBUG
name|pagerowned
range|:
literal|1
decl_stmt|,
comment|/* async paging op in progress */
name|ptpage
range|:
literal|1
decl_stmt|,
comment|/* is a user page table page */
endif|#
directive|endif
range|:
literal|0
decl_stmt|;
comment|/* (force to 'long' boundary) */
ifdef|#
directive|ifdef
name|ns32000
name|int
name|pad
decl_stmt|;
comment|/* extra space for ns32000 bit ops */
endif|#
directive|endif
endif|ns32000
name|boolean_t
name|clean
decl_stmt|;
comment|/* page has not been modified */
name|unsigned
name|int
comment|/* boolean_t */
name|busy
range|:
literal|1
decl_stmt|,
comment|/* page is in transit (O) */
name|wanted
range|:
literal|1
decl_stmt|,
comment|/* someone is waiting for page (O) */
name|tabled
range|:
literal|1
decl_stmt|,
comment|/* page is in VP table (O) */
name|copy_on_write
range|:
literal|1
decl_stmt|,
comment|/* page must be copied before being 					   changed (O) */
name|fictitious
range|:
literal|1
decl_stmt|,
comment|/* physical page doesn't exist (O) */
name|absent
range|:
literal|1
decl_stmt|,
comment|/* virtual page doesn't exist (O) */
name|fake
range|:
literal|1
decl_stmt|,
comment|/* page is a placeholder for page-in 					   (O) */
range|:
literal|0
decl_stmt|;
name|vm_offset_t
name|phys_addr
decl_stmt|;
comment|/* physical address of page */
name|vm_prot_t
name|page_lock
decl_stmt|;
comment|/* Uses prohibited by data manager */
name|vm_prot_t
name|unlock_request
decl_stmt|;
comment|/* Outstanding unlock request */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vm_page
modifier|*
name|vm_page_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|VM_PAGE_DEBUG
end_if

begin_define
define|#
directive|define
name|VM_PAGE_CHECK
parameter_list|(
name|mem
parameter_list|)
value|{ \ 		if ( (((unsigned int) mem)< ((unsigned int)&vm_page_array[0])) || \ 		     (((unsigned int) mem)> ((unsigned int)&vm_page_array[last_page-first_page])) || \ 		     (mem->active&& mem->inactive) \ 		    ) panic("vm_page_check: not valid!"); \ 		}
end_define

begin_else
else|#
directive|else
else|VM_PAGE_DEBUG
end_else

begin_define
define|#
directive|define
name|VM_PAGE_CHECK
parameter_list|(
name|mem
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
endif|VM_PAGE_DEBUG
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  *	Each pageable resident page falls into one of three lists:  *  *	free	  *		Available for allocation now.  *	inactive  *		Not referenced in any map, but still has an  *		object/offset-page mapping, and may be dirty.  *		This is the list of pages that should be  *		paged out next.  *	active  *		A list of pages which have been placed in  *		at least one physical map.  This list is  *		ordered, in LRU-like fashion.  */
end_comment

begin_decl_stmt
specifier|extern
name|queue_head_t
name|vm_page_queue_free
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* memory free queue */
end_comment

begin_decl_stmt
specifier|extern
name|queue_head_t
name|vm_page_queue_active
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* active memory queue */
end_comment

begin_decl_stmt
specifier|extern
name|queue_head_t
name|vm_page_queue_inactive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* inactive memory queue */
end_comment

begin_decl_stmt
specifier|extern
name|vm_page_t
name|vm_page_array
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* First resident page in table */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|first_page
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* first physical page number */
end_comment

begin_comment
comment|/* ... represented in vm_page_array */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|last_page
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last physical page number */
end_comment

begin_comment
comment|/* ... represented in vm_page_array */
end_comment

begin_comment
comment|/* [INCLUSIVE] */
end_comment

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|first_phys_addr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* physical address for first_page */
end_comment

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|last_phys_addr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* physical address for last_page */
end_comment

begin_define
define|#
directive|define
name|VM_PAGE_TO_PHYS
parameter_list|(
name|entry
parameter_list|)
value|((entry)->phys_addr)
end_define

begin_define
define|#
directive|define
name|IS_VM_PHYSADDR
parameter_list|(
name|pa
parameter_list|)
define|\
value|((pa)>= first_phys_addr&& (pa)<= last_phys_addr)
end_define

begin_define
define|#
directive|define
name|PHYS_TO_VM_PAGE
parameter_list|(
name|pa
parameter_list|)
define|\
value|(&vm_page_array[atop(pa) - first_page ])
end_define

begin_decl_stmt
specifier|extern
name|simple_lock_data_t
name|vm_page_queue_lock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lock on active and inactive 						   page queues */
end_comment

begin_decl_stmt
specifier|extern
name|simple_lock_data_t
name|vm_page_queue_free_lock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lock on free page queue */
end_comment

begin_decl_stmt
name|void
name|vm_page_startup
name|__P
argument_list|(
operator|(
name|vm_offset_t
operator|*
name|start
operator|,
name|vm_offset_t
operator|*
name|end
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_page_t
name|vm_page_lookup
name|__P
argument_list|(
operator|(
name|vm_object_t
name|object
operator|,
name|vm_offset_t
name|offset
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_page_t
name|vm_page_alloc
name|__P
argument_list|(
operator|(
name|vm_object_t
name|object
operator|,
name|vm_offset_t
name|offset
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_page_free
name|__P
argument_list|(
operator|(
name|vm_page_t
name|mem
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_page_activate
name|__P
argument_list|(
operator|(
name|vm_page_t
name|mem
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_page_deactivate
name|__P
argument_list|(
operator|(
name|vm_page_t
name|mem
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_page_rename
name|__P
argument_list|(
operator|(
name|vm_page_t
name|mem
operator|,
name|vm_object_t
name|new_object
operator|,
name|vm_offset_t
name|new_offset
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|vm_page_zero_fill
name|__P
argument_list|(
operator|(
name|vm_page_t
name|mem
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_page_copy
name|__P
argument_list|(
operator|(
name|vm_page_t
name|src_mem
operator|,
name|vm_page_t
name|dst_mem
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_page_wire
name|__P
argument_list|(
operator|(
name|vm_page_t
name|mem
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_page_unwire
name|__P
argument_list|(
operator|(
name|vm_page_t
name|mem
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_set_page_size
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	Functions implemented as macros  */
end_comment

begin_define
define|#
directive|define
name|PAGE_ASSERT_WAIT
parameter_list|(
name|m
parameter_list|,
name|interruptible
parameter_list|)
value|{ \ 				(m)->wanted = TRUE; \ 				assert_wait((int) (m), (interruptible)); \ 			}
end_define

begin_define
define|#
directive|define
name|PAGE_WAKEUP
parameter_list|(
name|m
parameter_list|)
value|{ \ 				(m)->busy = FALSE; \ 				if ((m)->wanted) { \ 					(m)->wanted = FALSE; \ 					thread_wakeup((int) (m)); \ 				} \ 			}
end_define

begin_define
define|#
directive|define
name|vm_page_lock_queues
parameter_list|()
value|simple_lock(&vm_page_queue_lock)
end_define

begin_define
define|#
directive|define
name|vm_page_unlock_queues
parameter_list|()
value|simple_unlock(&vm_page_queue_lock)
end_define

begin_define
define|#
directive|define
name|vm_page_set_modified
parameter_list|(
name|m
parameter_list|)
value|{ (m)->clean = FALSE; }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|VM_PAGE_DEBUG_INIT
parameter_list|(
name|m
parameter_list|)
value|((m)->pagerowned = 0, (m)->ptpage = 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VM_PAGE_DEBUG_INIT
parameter_list|(
name|m
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VM_PAGE_INIT
parameter_list|(
name|mem
parameter_list|,
name|object
parameter_list|,
name|offset
parameter_list|)
value|{ \ 	(mem)->busy = TRUE; \ 	(mem)->tabled = FALSE; \ 	vm_page_insert((mem), (object), (offset)); \ 	(mem)->absent = FALSE; \ 	(mem)->fictitious = FALSE; \ 	(mem)->page_lock = VM_PROT_NONE; \ 	(mem)->unlock_request = VM_PROT_NONE; \ 	(mem)->laundry = FALSE; \ 	(mem)->active = FALSE; \ 	(mem)->inactive = FALSE; \ 	(mem)->wire_count = 0; \ 	(mem)->clean = TRUE; \ 	(mem)->copy_on_write = FALSE; \ 	(mem)->fake = TRUE; \ 	VM_PAGE_DEBUG_INIT(mem); \ }
end_define

begin_endif
endif|#
directive|endif
endif|KERNEL
end_endif

begin_endif
endif|#
directive|endif
endif|_VM_PAGE_
end_endif

end_unit

