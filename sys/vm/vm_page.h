begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vm_page.h	8.2 (Berkeley) 12/13/93  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $Id: vm_page.h,v 1.37 1998/03/01 04:18:26 dyson Exp $  */
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

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

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
comment|/* queue info for FIFO queue or free list (P) */
name|TAILQ_ENTRY
argument_list|(
argument|vm_page
argument_list|)
name|hashq
expr_stmt|;
comment|/* hash table links (O) */
name|TAILQ_ENTRY
argument_list|(
argument|vm_page
argument_list|)
name|listq
expr_stmt|;
comment|/* pages in same object (O) */
name|vm_object_t
name|object
decl_stmt|;
comment|/* which object am I in (O,P) */
name|vm_pindex_t
name|pindex
decl_stmt|;
comment|/* offset into object (O,P) */
name|vm_offset_t
name|phys_addr
decl_stmt|;
comment|/* physical address of page */
name|u_short
name|queue
decl_stmt|;
comment|/* page queue index */
name|u_short
name|flags
decl_stmt|,
comment|/* see below */
name|pc
decl_stmt|;
comment|/* page color */
name|u_short
name|wire_count
decl_stmt|;
comment|/* wired down maps refs (P) */
name|short
name|hold_count
decl_stmt|;
comment|/* page hold count */
name|u_char
name|act_count
decl_stmt|;
comment|/* page usage count */
name|u_char
name|busy
decl_stmt|;
comment|/* page busy count */
comment|/* NOTE that these must support one bit per DEV_BSIZE in a page!!! */
comment|/* so, on normal X86 kernels, they must be at least 8 bits wide */
name|u_char
name|valid
decl_stmt|;
comment|/* map of valid DEV_BSIZE chunks */
name|u_char
name|dirty
decl_stmt|;
comment|/* map of dirty DEV_BSIZE chunks */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Page coloring parameters  */
end_comment

begin_comment
comment|/* Each of PQ_FREE, PQ_ZERO and PQ_CACHE have PQ_HASH_SIZE entries */
end_comment

begin_comment
comment|/* Define one of the following */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PQ_LARGECACHE
argument_list|)
end_if

begin_define
define|#
directive|define
name|PQ_PRIME1
value|31
end_define

begin_comment
comment|/* Prime number somewhat less than PQ_HASH_SIZE */
end_comment

begin_define
define|#
directive|define
name|PQ_PRIME2
value|23
end_define

begin_comment
comment|/* Prime number somewhat less than PQ_HASH_SIZE */
end_comment

begin_define
define|#
directive|define
name|PQ_PRIME3
value|17
end_define

begin_comment
comment|/* Prime number somewhat less than PQ_HASH_SIZE */
end_comment

begin_define
define|#
directive|define
name|PQ_L2_SIZE
value|128
end_define

begin_comment
comment|/* A number of colors opt for 512K cache */
end_comment

begin_define
define|#
directive|define
name|PQ_L1_SIZE
value|2
end_define

begin_comment
comment|/* Two page L1 cache */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Use 'options PQ_NOOPT' to disable page coloring  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PQ_NOOPT
argument_list|)
end_if

begin_define
define|#
directive|define
name|PQ_PRIME1
value|1
end_define

begin_define
define|#
directive|define
name|PQ_PRIME2
value|1
end_define

begin_define
define|#
directive|define
name|PQ_PRIME3
value|1
end_define

begin_define
define|#
directive|define
name|PQ_L2_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|PQ_L1_SIZE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PQ_NORMALCACHE
argument_list|)
end_if

begin_define
define|#
directive|define
name|PQ_PRIME1
value|5
end_define

begin_comment
comment|/* Prime number somewhat less than PQ_HASH_SIZE */
end_comment

begin_define
define|#
directive|define
name|PQ_PRIME2
value|3
end_define

begin_comment
comment|/* Prime number somewhat less than PQ_HASH_SIZE */
end_comment

begin_define
define|#
directive|define
name|PQ_PRIME3
value|11
end_define

begin_comment
comment|/* Prime number somewhat less than PQ_HASH_SIZE */
end_comment

begin_define
define|#
directive|define
name|PQ_L2_SIZE
value|16
end_define

begin_comment
comment|/* A reasonable number of colors (opt for 64K cache) */
end_comment

begin_define
define|#
directive|define
name|PQ_L1_SIZE
value|2
end_define

begin_comment
comment|/* Two page L1 cache */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PQ_MEDIUMCACHE
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|PQ_L2_SIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|PQ_PRIME1
value|13
end_define

begin_comment
comment|/* Prime number somewhat less than PQ_HASH_SIZE */
end_comment

begin_define
define|#
directive|define
name|PQ_PRIME2
value|7
end_define

begin_comment
comment|/* Prime number somewhat less than PQ_HASH_SIZE */
end_comment

begin_define
define|#
directive|define
name|PQ_PRIME3
value|5
end_define

begin_comment
comment|/* Prime number somewhat less than PQ_HASH_SIZE */
end_comment

begin_define
define|#
directive|define
name|PQ_L2_SIZE
value|64
end_define

begin_comment
comment|/* A number of colors opt for 256K cache */
end_comment

begin_define
define|#
directive|define
name|PQ_L1_SIZE
value|2
end_define

begin_comment
comment|/* Two page L1 cache */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PQ_L2_MASK
value|(PQ_L2_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|PQ_NONE
value|0
end_define

begin_define
define|#
directive|define
name|PQ_FREE
value|1
end_define

begin_define
define|#
directive|define
name|PQ_ZERO
value|(1 + PQ_L2_SIZE)
end_define

begin_define
define|#
directive|define
name|PQ_INACTIVE
value|(1 + 2*PQ_L2_SIZE)
end_define

begin_define
define|#
directive|define
name|PQ_ACTIVE
value|(2 + 2*PQ_L2_SIZE)
end_define

begin_define
define|#
directive|define
name|PQ_CACHE
value|(3 + 2*PQ_L2_SIZE)
end_define

begin_define
define|#
directive|define
name|PQ_COUNT
value|(3 + 3*PQ_L2_SIZE)
end_define

begin_struct
specifier|extern
struct|struct
name|vpgqueues
block|{
name|struct
name|pglist
modifier|*
name|pl
decl_stmt|;
name|int
modifier|*
name|cnt
decl_stmt|;
name|int
modifier|*
name|lcnt
decl_stmt|;
block|}
name|vm_page_queues
index|[
name|PQ_COUNT
index|]
struct|;
end_struct

begin_comment
comment|/*  * These are the flags defined for vm_page.  *  * Note: PG_FILLED and PG_DIRTY are added for the filesystems.  */
end_comment

begin_define
define|#
directive|define
name|PG_BUSY
value|0x01
end_define

begin_comment
comment|/* page is in transit (O) */
end_comment

begin_define
define|#
directive|define
name|PG_WANTED
value|0x02
end_define

begin_comment
comment|/* someone is waiting for page (O) */
end_comment

begin_define
define|#
directive|define
name|PG_TABLED
value|0x04
end_define

begin_comment
comment|/* page is in VP table (O) */
end_comment

begin_define
define|#
directive|define
name|PG_FICTITIOUS
value|0x08
end_define

begin_comment
comment|/* physical page doesn't exist (O) */
end_comment

begin_define
define|#
directive|define
name|PG_WRITEABLE
value|0x10
end_define

begin_comment
comment|/* page is mapped writeable */
end_comment

begin_define
define|#
directive|define
name|PG_MAPPED
value|0x20
end_define

begin_comment
comment|/* page is mapped */
end_comment

begin_define
define|#
directive|define
name|PG_ZERO
value|0x40
end_define

begin_comment
comment|/* page is zeroed */
end_comment

begin_define
define|#
directive|define
name|PG_REFERENCED
value|0x80
end_define

begin_comment
comment|/* page has been referenced */
end_comment

begin_define
define|#
directive|define
name|PG_CLEANCHK
value|0x100
end_define

begin_comment
comment|/* page has been checked for cleaning */
end_comment

begin_comment
comment|/*  * Misc constants.  */
end_comment

begin_define
define|#
directive|define
name|ACT_DECLINE
value|1
end_define

begin_define
define|#
directive|define
name|ACT_ADVANCE
value|3
end_define

begin_define
define|#
directive|define
name|ACT_INIT
value|5
end_define

begin_define
define|#
directive|define
name|ACT_MAX
value|64
end_define

begin_define
define|#
directive|define
name|PFCLUSTER_BEHIND
value|3
end_define

begin_define
define|#
directive|define
name|PFCLUSTER_AHEAD
value|3
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Each pageable resident page falls into one of four lists:  *  *	free  *		Available for allocation now.  *  * The following are all LRU sorted:  *  *	cache  *		Almost available for allocation. Still in an  *		object, but clean and immediately freeable at  *		non-interrupt times.  *  *	inactive  *		Low activity, candidates for reclamation.  *		This is the list of pages that should be  *		paged out next.  *  *	active  *		Pages that are "active" i.e. they have been  *		recently referenced.  *  *	zero  *		Pages that are really free and have been pre-zeroed  *  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pglist
name|vm_page_queue_free
index|[
name|PQ_L2_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* memory free queue */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pglist
name|vm_page_queue_zero
index|[
name|PQ_L2_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* zeroed memory free queue */
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
name|struct
name|pglist
name|vm_page_queue_cache
index|[
name|PQ_L2_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cache memory queue */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vm_page_zero_count
decl_stmt|;
end_decl_stmt

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
value|{ \ 	(m)->flags |= PG_WANTED; \ 	assert_wait((int) (m), (interruptible)); \ }
end_define

begin_define
define|#
directive|define
name|PAGE_WAKEUP
parameter_list|(
name|m
parameter_list|)
value|{ \ 	(m)->flags&= ~PG_BUSY; \ 	if (((m)->flags& PG_WANTED)&& ((m)->busy == 0)) { \ 		(m)->flags&= ~PG_WANTED; \ 		wakeup((m)); \ 	} \ }
end_define

begin_define
define|#
directive|define
name|PAGE_BWAKEUP
parameter_list|(
name|m
parameter_list|)
value|{ \ 	(m)->busy--; \ 	if ((((m)->flags& (PG_WANTED | PG_BUSY)) == PG_WANTED)&& \ 		((m)->busy == 0)) { \ 		(m)->flags&= ~PG_WANTED; \ 		wakeup((m)); \ 	} \ }
end_define

begin_if
if|#
directive|if
name|PAGE_SIZE
operator|==
literal|4096
end_if

begin_define
define|#
directive|define
name|VM_PAGE_BITS_ALL
value|0xff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|PAGE_SIZE
operator|==
literal|8192
end_if

begin_define
define|#
directive|define
name|VM_PAGE_BITS_ALL
value|0xffff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VM_ALLOC_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|VM_ALLOC_INTERRUPT
value|1
end_define

begin_define
define|#
directive|define
name|VM_ALLOC_SYSTEM
value|2
end_define

begin_define
define|#
directive|define
name|VM_ALLOC_ZERO
value|3
end_define

begin_define
define|#
directive|define
name|VM_ALLOC_RETRY
value|0x80
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
name|vm_pindex_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_page_t
name|vm_page_grab
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|,
name|vm_pindex_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_page_cache
name|__P
argument_list|(
operator|(
specifier|register
name|vm_page_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
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
name|vm_page_free_zero
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
name|vm_pindex_t
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
name|vm_pindex_t
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
name|vm_pindex_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_offset_t
name|vm_page_startup
name|__P
argument_list|(
operator|(
name|vm_offset_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
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
name|void
name|vm_page_unqueue
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
name|vm_page_unqueue_nowakeup
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
name|vm_page_set_validclean
name|__P
argument_list|(
operator|(
name|vm_page_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_page_set_invalid
name|__P
argument_list|(
operator|(
name|vm_page_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
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

begin_decl_stmt
name|int
name|vm_page_is_valid
name|__P
argument_list|(
operator|(
name|vm_page_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_page_test_dirty
name|__P
argument_list|(
operator|(
name|vm_page_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_page_bits
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_page_t
name|vm_page_list_find
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vm_page_queue_index
name|__P
argument_list|(
operator|(
name|vm_offset_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_page_t
name|vm_page_select
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|,
name|vm_pindex_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|vm_page_sleep
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|char
modifier|*
name|msg
parameter_list|,
name|char
modifier|*
name|busy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Keep page from being freed by the page daemon  * much of the same effect as wiring, except much lower  * overhead and should be used only for *very* temporary  * holding ("wiring").  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|vm_page_hold
parameter_list|(
name|vm_page_t
name|mem
parameter_list|)
block|{
name|mem
operator|->
name|hold_count
operator|++
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|DIAGNOSTIC
end_ifdef

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_comment
comment|/* make GCC shut up */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|void
name|vm_page_unhold
parameter_list|(
name|vm_page_t
name|mem
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|DIAGNOSTIC
if|if
condition|(
operator|--
name|mem
operator|->
name|hold_count
operator|<
literal|0
condition|)
name|panic
argument_list|(
literal|"vm_page_unhold: hold count< 0!!!"
argument_list|)
expr_stmt|;
else|#
directive|else
operator|--
name|mem
operator|->
name|hold_count
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|vm_page_protect
parameter_list|(
name|vm_page_t
name|mem
parameter_list|,
name|int
name|prot
parameter_list|)
block|{
if|if
condition|(
name|prot
operator|==
name|VM_PROT_NONE
condition|)
block|{
if|if
condition|(
name|mem
operator|->
name|flags
operator|&
operator|(
name|PG_WRITEABLE
operator||
name|PG_MAPPED
operator|)
condition|)
block|{
name|pmap_page_protect
argument_list|(
name|VM_PAGE_TO_PHYS
argument_list|(
name|mem
argument_list|)
argument_list|,
name|VM_PROT_NONE
argument_list|)
expr_stmt|;
name|mem
operator|->
name|flags
operator|&=
operator|~
operator|(
name|PG_WRITEABLE
operator||
name|PG_MAPPED
operator|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
operator|(
name|prot
operator|==
name|VM_PROT_READ
operator|)
operator|&&
operator|(
name|mem
operator|->
name|flags
operator|&
name|PG_WRITEABLE
operator|)
condition|)
block|{
name|pmap_page_protect
argument_list|(
name|VM_PAGE_TO_PHYS
argument_list|(
name|mem
argument_list|)
argument_list|,
name|VM_PROT_READ
argument_list|)
expr_stmt|;
name|mem
operator|->
name|flags
operator|&=
operator|~
name|PG_WRITEABLE
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  *	vm_page_zero_fill:  *  *	Zero-fill the specified page.  *	Written as a standard pagein routine, to  *	be used by the zero-fill object.  */
end_comment

begin_function
specifier|static
name|__inline
name|boolean_t
name|vm_page_zero_fill
parameter_list|(
name|m
parameter_list|)
name|vm_page_t
name|m
decl_stmt|;
block|{
name|pmap_zero_page
argument_list|(
name|VM_PAGE_TO_PHYS
argument_list|(
name|m
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|TRUE
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  *	vm_page_copy:  *  *	Copy one page to another  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|vm_page_copy
parameter_list|(
name|src_m
parameter_list|,
name|dest_m
parameter_list|)
name|vm_page_t
name|src_m
decl_stmt|;
name|vm_page_t
name|dest_m
decl_stmt|;
block|{
name|pmap_copy_page
argument_list|(
name|VM_PAGE_TO_PHYS
argument_list|(
name|src_m
argument_list|)
argument_list|,
name|VM_PAGE_TO_PHYS
argument_list|(
name|dest_m
argument_list|)
argument_list|)
expr_stmt|;
name|dest_m
operator|->
name|valid
operator|=
name|VM_PAGE_BITS_ALL
expr_stmt|;
block|}
end_function

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

