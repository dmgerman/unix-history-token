begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vm_page.h	8.3 (Berkeley) 1/9/95  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
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

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|pglist
argument_list|,
name|vm_page
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|vm_page
block|{
name|TAILQ_ENTRY
argument_list|(
argument|vm_page
argument_list|)
name|pageq
expr_stmt|;
comment|/* queue info for FIFO 						 * queue or free list (P) */
name|TAILQ_ENTRY
argument_list|(
argument|vm_page
argument_list|)
name|hashq
expr_stmt|;
comment|/* hash table links (O)*/
name|TAILQ_ENTRY
argument_list|(
argument|vm_page
argument_list|)
name|listq
expr_stmt|;
comment|/* pages in same object (O)*/
name|vm_object_t
name|object
decl_stmt|;
comment|/* which object am I in (O,P)*/
name|vm_offset_t
name|offset
decl_stmt|;
comment|/* offset into object (O,P) */
name|u_short
name|wire_count
decl_stmt|;
comment|/* wired down maps refs (P) */
name|u_short
name|flags
decl_stmt|;
comment|/* see below */
name|vm_offset_t
name|phys_addr
decl_stmt|;
comment|/* physical address of page */
block|}
struct|;
end_struct

begin_comment
comment|/*  * These are the flags defined for vm_page.  *  * Note: PG_FILLED and PG_DIRTY are added for the filesystems.  */
end_comment

begin_define
define|#
directive|define
name|PG_INACTIVE
value|0x0001
end_define

begin_comment
comment|/* page is in inactive list (P) */
end_comment

begin_define
define|#
directive|define
name|PG_ACTIVE
value|0x0002
end_define

begin_comment
comment|/* page is in active list (P) */
end_comment

begin_define
define|#
directive|define
name|PG_LAUNDRY
value|0x0004
end_define

begin_comment
comment|/* page is being cleaned now (P)*/
end_comment

begin_define
define|#
directive|define
name|PG_CLEAN
value|0x0008
end_define

begin_comment
comment|/* page has not been modified */
end_comment

begin_define
define|#
directive|define
name|PG_BUSY
value|0x0010
end_define

begin_comment
comment|/* page is in transit (O) */
end_comment

begin_define
define|#
directive|define
name|PG_WANTED
value|0x0020
end_define

begin_comment
comment|/* someone is waiting for page (O) */
end_comment

begin_define
define|#
directive|define
name|PG_TABLED
value|0x0040
end_define

begin_comment
comment|/* page is in VP table (O) */
end_comment

begin_define
define|#
directive|define
name|PG_COPYONWRITE
value|0x0080
end_define

begin_comment
comment|/* must copy page before changing (O) */
end_comment

begin_define
define|#
directive|define
name|PG_FICTITIOUS
value|0x0100
end_define

begin_comment
comment|/* physical page doesn't exist (O) */
end_comment

begin_define
define|#
directive|define
name|PG_FAKE
value|0x0200
end_define

begin_comment
comment|/* page is placeholder for pagein (O) */
end_comment

begin_define
define|#
directive|define
name|PG_FILLED
value|0x0400
end_define

begin_comment
comment|/* client flag to set when filled */
end_comment

begin_define
define|#
directive|define
name|PG_DIRTY
value|0x0800
end_define

begin_comment
comment|/* client flag to set when dirty */
end_comment

begin_define
define|#
directive|define
name|PG_PAGEROWNED
value|0x4000
end_define

begin_comment
comment|/* DEBUG: async paging op in progress */
end_comment

begin_define
define|#
directive|define
name|PG_PTPAGE
value|0x8000
end_define

begin_comment
comment|/* DEBUG: is a user page table page */
end_comment

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
value|{ \ 	if ((((unsigned int) mem)< ((unsigned int)&vm_page_array[0])) || \ 	    (((unsigned int) mem)> \ 		((unsigned int)&vm_page_array[last_page-first_page])) || \ 	    ((mem->flags& (PG_ACTIVE | PG_INACTIVE)) == \ 		(PG_ACTIVE | PG_INACTIVE))) \ 		panic("vm_page_check: not valid!"); \ }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* VM_PAGE_DEBUG */
end_comment

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
end_endif

begin_comment
comment|/* VM_PAGE_DEBUG */
end_comment

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
name|struct
name|pglist
name|vm_page_queue_free
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* memory free queue */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pglist
name|vm_page_queue_active
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* active memory queue */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pglist
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
comment|/* lock on free page queue */
name|simple_lock_data_t
name|vm_page_queue_free_lock
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
value|{ \ 				(m)->flags |= PG_WANTED; \ 				assert_wait((m), (interruptible)); \ 			}
end_define

begin_define
define|#
directive|define
name|PAGE_WAKEUP
parameter_list|(
name|m
parameter_list|)
value|{ \ 				(m)->flags&= ~PG_BUSY; \ 				if ((m)->flags& PG_WANTED) { \ 					(m)->flags&= ~PG_WANTED; \ 					thread_wakeup((m)); \ 				} \ 			}
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
value|{ (m)->flags&= ~PG_CLEAN; }
end_define

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
value|{ \ 	(mem)->flags = PG_BUSY | PG_CLEAN | PG_FAKE; \ 	vm_page_insert((mem), (object), (offset)); \ 	(mem)->wire_count = 0; \ }
end_define

begin_decl_stmt
name|void
name|vm_page_activate
name|__P
argument_list|(
operator|(
name|vm_page_t
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
operator|,
name|vm_offset_t
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
operator|,
name|vm_page_t
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_page_insert
name|__P
argument_list|(
operator|(
name|vm_page_t
operator|,
name|vm_object_t
operator|,
name|vm_offset_t
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
operator|,
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_page_remove
name|__P
argument_list|(
operator|(
name|vm_page_t
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
operator|,
name|vm_object_t
operator|,
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_page_startup
name|__P
argument_list|(
operator|(
name|vm_offset_t
operator|*
operator|,
name|vm_offset_t
operator|*
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_VM_PAGE_ */
end_comment

end_unit

