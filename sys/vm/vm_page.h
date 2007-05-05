begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vm_page.h	8.2 (Berkeley) 12/13/93  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $FreeBSD$  */
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
comment|/*  *	Management of resident (logical) pages.  *  *	A small structure is kept for each resident  *	page, indexed by page number.  Each structure  *	is an element of several lists:  *  *		A hash table bucket used to quickly  *		perform object/offset lookups  *  *		A list of all pages for a given object,  *		so they can be quickly deactivated at  *		time of deallocation.  *  *		An ordered list of pages due for pageout.  *  *	In addition, the structure contains the object  *	and offset to which this page belongs (for pageout),  *	and sundry status bits.  *  *	Fields in this structure are locked either by the lock on the  *	object that the page belongs to (O) or by the lock on the page  *	queues (P).  *  *	The 'valid' and 'dirty' fields are distinct.  A page may have dirty  *	bits set without having associated valid bits set.  This is used by  *	NFS to implement piecemeal writes.  */
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
name|listq
expr_stmt|;
comment|/* pages in same object (O) 	*/
name|struct
name|vm_page
modifier|*
name|left
decl_stmt|;
comment|/* splay tree link (O)		*/
name|struct
name|vm_page
modifier|*
name|right
decl_stmt|;
comment|/* splay tree link (O)		*/
name|vm_object_t
name|object
decl_stmt|;
comment|/* which object am I in (O,P)*/
name|vm_pindex_t
name|pindex
decl_stmt|;
comment|/* offset into object (O,P) */
name|vm_paddr_t
name|phys_addr
decl_stmt|;
comment|/* physical address of page */
name|struct
name|md_page
name|md
decl_stmt|;
comment|/* machine dependant stuff */
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
name|u_int
name|cow
decl_stmt|;
comment|/* page cow mapping count */
name|short
name|hold_count
decl_stmt|;
comment|/* page hold count */
name|u_short
name|oflags
decl_stmt|;
comment|/* page flags (O) */
name|u_char
name|act_count
decl_stmt|;
comment|/* page usage count */
name|u_char
name|busy
decl_stmt|;
comment|/* page busy count (O) */
comment|/* NOTE that these must support one bit per DEV_BSIZE in a page!!! */
comment|/* so, on normal X86 kernels, they must be at least 8 bits wide */
if|#
directive|if
name|PAGE_SIZE
operator|==
literal|4096
name|u_char
name|valid
decl_stmt|;
comment|/* map of valid DEV_BSIZE chunks (O) */
name|u_char
name|dirty
decl_stmt|;
comment|/* map of dirty DEV_BSIZE chunks */
elif|#
directive|elif
name|PAGE_SIZE
operator|==
literal|8192
name|u_short
name|valid
decl_stmt|;
comment|/* map of valid DEV_BSIZE chunks (O) */
name|u_short
name|dirty
decl_stmt|;
comment|/* map of dirty DEV_BSIZE chunks */
elif|#
directive|elif
name|PAGE_SIZE
operator|==
literal|16384
name|u_int
name|valid
decl_stmt|;
comment|/* map of valid DEV_BSIZE chunks (O) */
name|u_int
name|dirty
decl_stmt|;
comment|/* map of dirty DEV_BSIZE chunks */
elif|#
directive|elif
name|PAGE_SIZE
operator|==
literal|32768
name|u_long
name|valid
decl_stmt|;
comment|/* map of valid DEV_BSIZE chunks (O) */
name|u_long
name|dirty
decl_stmt|;
comment|/* map of dirty DEV_BSIZE chunks */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Page flags stored in oflags:  *  * Access to these page flags is synchronized by the lock on the object  * containing the page (O).  */
end_comment

begin_define
define|#
directive|define
name|VPO_BUSY
value|0x0001
end_define

begin_comment
comment|/* page is in transit */
end_comment

begin_define
define|#
directive|define
name|VPO_WANTED
value|0x0002
end_define

begin_comment
comment|/* someone is waiting for page */
end_comment

begin_define
define|#
directive|define
name|VPO_CLEANCHK
value|0x0100
end_define

begin_comment
comment|/* page will be checked for cleaning */
end_comment

begin_define
define|#
directive|define
name|VPO_SWAPINPROG
value|0x0200
end_define

begin_comment
comment|/* swap I/O in progress on page */
end_comment

begin_define
define|#
directive|define
name|VPO_NOSYNC
value|0x0400
end_define

begin_comment
comment|/* do not collect for syncer */
end_comment

begin_comment
comment|/* Make sure that u_long is at least 64 bits when PAGE_SIZE is 32K. */
end_comment

begin_if
if|#
directive|if
name|PAGE_SIZE
operator|==
literal|32768
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|CTASSERT
end_ifdef

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|u_long
argument_list|)
operator|>=
literal|8
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PQ_CACHE and PQ_FREE represents a PQ_NUMCOLORS consecutive queue. */
end_comment

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
name|PQ_INACTIVE
value|(page_queue_coloring.inactive)
end_define

begin_define
define|#
directive|define
name|PQ_ACTIVE
value|(page_queue_coloring.active)
end_define

begin_define
define|#
directive|define
name|PQ_CACHE
value|(page_queue_coloring.cache)
end_define

begin_define
define|#
directive|define
name|PQ_HOLD
value|(page_queue_coloring.hold)
end_define

begin_define
define|#
directive|define
name|PQ_COUNT
value|(page_queue_coloring.count)
end_define

begin_define
define|#
directive|define
name|PQ_MAXCOLORS
value|1024
end_define

begin_define
define|#
directive|define
name|PQ_MAXCOUNT
value|(4 + 2 * PQ_MAXCOLORS)
end_define

begin_define
define|#
directive|define
name|PQ_NUMCOLORS
value|(page_queue_coloring.numcolors)
end_define

begin_define
define|#
directive|define
name|PQ_PRIME1
value|(page_queue_coloring.prime1)
end_define

begin_define
define|#
directive|define
name|PQ_PRIME2
value|(page_queue_coloring.prime2)
end_define

begin_define
define|#
directive|define
name|PQ_COLORMASK
value|(page_queue_coloring.colormask)
end_define

begin_define
define|#
directive|define
name|PQ_MAXLENGTH
value|(page_queue_coloring.maxlength)
end_define

begin_comment
comment|/* Returns the real queue a page is on. */
end_comment

begin_define
define|#
directive|define
name|VM_PAGE_GETQUEUE
parameter_list|(
name|m
parameter_list|)
value|((m)->queue)
end_define

begin_comment
comment|/* Returns the well known queue a page is on. */
end_comment

begin_define
define|#
directive|define
name|VM_PAGE_GETKNOWNQUEUE1
parameter_list|(
name|m
parameter_list|)
value|((m)->queue - (m)->pc)
end_define

begin_define
define|#
directive|define
name|VM_PAGE_GETKNOWNQUEUE2
parameter_list|(
name|m
parameter_list|)
value|VM_PAGE_GETQUEUE(m)
end_define

begin_comment
comment|/* Given the real queue number and a page color return the well know queue. */
end_comment

begin_define
define|#
directive|define
name|VM_PAGE_RESOLVEQUEUE
parameter_list|(
name|m
parameter_list|,
name|q
parameter_list|)
value|((q) - (m)->pc)
end_define

begin_comment
comment|/* Returns true if the page is in the named well known queue. */
end_comment

begin_define
define|#
directive|define
name|VM_PAGE_INQUEUE1
parameter_list|(
name|m
parameter_list|,
name|q
parameter_list|)
value|(VM_PAGE_GETKNOWNQUEUE1(m) == (q))
end_define

begin_define
define|#
directive|define
name|VM_PAGE_INQUEUE2
parameter_list|(
name|m
parameter_list|,
name|q
parameter_list|)
value|(VM_PAGE_GETKNOWNQUEUE2(m) == (q))
end_define

begin_comment
comment|/* Sets the queue a page is on. */
end_comment

begin_define
define|#
directive|define
name|VM_PAGE_SETQUEUE1
parameter_list|(
name|m
parameter_list|,
name|q
parameter_list|)
value|(VM_PAGE_GETQUEUE(m) = (q) + (m)->pc)
end_define

begin_define
define|#
directive|define
name|VM_PAGE_SETQUEUE2
parameter_list|(
name|m
parameter_list|,
name|q
parameter_list|)
value|(VM_PAGE_GETQUEUE(m) = (q))
end_define

begin_struct
struct|struct
name|vpgqueues
block|{
name|struct
name|pglist
name|pl
decl_stmt|;
name|int
modifier|*
name|cnt
decl_stmt|;
name|int
name|lcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pq_coloring
block|{
name|int
name|numcolors
decl_stmt|;
name|int
name|colormask
decl_stmt|;
name|int
name|prime1
decl_stmt|;
name|int
name|prime2
decl_stmt|;
name|int
name|inactive
decl_stmt|;
name|int
name|active
decl_stmt|;
name|int
name|cache
decl_stmt|;
name|int
name|hold
decl_stmt|;
name|int
name|count
decl_stmt|;
name|int
name|maxlength
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vpgqueues
name|vm_page_queues
index|[
name|PQ_MAXCOUNT
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|vm_page_queue_free_mtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pq_coloring
name|page_queue_coloring
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * These are the flags defined for vm_page.  *  * Note: PG_UNMANAGED (used by OBJT_PHYS) indicates that the page is  * 	 not under PV management but otherwise should be treated as a  *	 normal page.  Pages not under PV management cannot be paged out  *	 via the object/vm_page_t because there is no knowledge of their  *	 pte mappings, nor can they be removed from their objects via   *	 the object, and such pages are also not on any PQ queue.  */
end_comment

begin_define
define|#
directive|define
name|PG_WINATCFLS
value|0x0004
end_define

begin_comment
comment|/* flush dirty page on inactive q */
end_comment

begin_define
define|#
directive|define
name|PG_FICTITIOUS
value|0x0008
end_define

begin_comment
comment|/* physical page doesn't exist (O) */
end_comment

begin_define
define|#
directive|define
name|PG_WRITEABLE
value|0x0010
end_define

begin_comment
comment|/* page is mapped writeable */
end_comment

begin_define
define|#
directive|define
name|PG_ZERO
value|0x0040
end_define

begin_comment
comment|/* page is zeroed */
end_comment

begin_define
define|#
directive|define
name|PG_REFERENCED
value|0x0080
end_define

begin_comment
comment|/* page has been referenced */
end_comment

begin_define
define|#
directive|define
name|PG_UNMANAGED
value|0x0800
end_define

begin_comment
comment|/* No PV management for page */
end_comment

begin_define
define|#
directive|define
name|PG_MARKER
value|0x1000
end_define

begin_comment
comment|/* special queue marker page */
end_comment

begin_define
define|#
directive|define
name|PG_SLAB
value|0x2000
end_define

begin_comment
comment|/* object pointer is actually a slab */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_comment
comment|/*  * Each pageable resident page falls into one of four lists:  *  *	free  *		Available for allocation now.  *  * The following are all LRU sorted:  *  *	cache  *		Almost available for allocation. Still in an  *		object, but clean and immediately freeable at  *		non-interrupt times.  *  *	inactive  *		Low activity, candidates for reclamation.  *		This is the list of pages that should be  *		paged out next.  *  *	active  *		Pages that are "active" i.e. they have been  *		recently referenced.  *  *	zero  *		Pages that are really free and have been pre-zeroed  *  */
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
name|int
name|vm_page_array_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of vm_page_t's */
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

begin_define
define|#
directive|define
name|VM_PAGE_TO_PHYS
parameter_list|(
name|entry
parameter_list|)
value|((entry)->phys_addr)
end_define

begin_function_decl
specifier|static
name|__inline
name|vm_page_t
name|PHYS_TO_VM_PAGE
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|vm_page_t
name|PHYS_TO_VM_PAGE
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|VM_PHYSSEG_SPARSE
name|int
name|i
decl_stmt|,
name|j
init|=
literal|0
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|phys_avail
index|[
name|i
operator|+
literal|1
index|]
operator|<=
name|pa
operator|||
name|phys_avail
index|[
name|i
index|]
operator|>
name|pa
condition|;
name|i
operator|+=
literal|2
control|)
name|j
operator|+=
name|atop
argument_list|(
name|phys_avail
index|[
name|i
operator|+
literal|1
index|]
operator|-
name|phys_avail
index|[
name|i
index|]
argument_list|)
expr_stmt|;
return|return
operator|(
operator|&
name|vm_page_array
index|[
name|j
operator|+
name|atop
argument_list|(
name|pa
operator|-
name|phys_avail
index|[
name|i
index|]
argument_list|)
index|]
operator|)
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|VM_PHYSSEG_DENSE
argument_list|)
return|return
operator|(
operator|&
name|vm_page_array
index|[
name|atop
argument_list|(
name|pa
argument_list|)
operator|-
name|first_page
index|]
operator|)
return|;
else|#
directive|else
error|#
directive|error
literal|"Either VM_PHYSSEG_DENSE or VM_PHYSSEG_SPARSE must be defined."
endif|#
directive|endif
block|}
end_function

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|vm_page_queue_mtx
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|vm_page_lock_queues
parameter_list|()
value|mtx_lock(&vm_page_queue_mtx)
end_define

begin_define
define|#
directive|define
name|vm_page_unlock_queues
parameter_list|()
value|mtx_unlock(&vm_page_queue_mtx)
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
value|0xffu
end_define

begin_elif
elif|#
directive|elif
name|PAGE_SIZE
operator|==
literal|8192
end_elif

begin_define
define|#
directive|define
name|VM_PAGE_BITS_ALL
value|0xffffu
end_define

begin_elif
elif|#
directive|elif
name|PAGE_SIZE
operator|==
literal|16384
end_elif

begin_define
define|#
directive|define
name|VM_PAGE_BITS_ALL
value|0xffffffffu
end_define

begin_elif
elif|#
directive|elif
name|PAGE_SIZE
operator|==
literal|32768
end_elif

begin_define
define|#
directive|define
name|VM_PAGE_BITS_ALL
value|0xfffffffffffffffflu
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* page allocation classes: */
end_comment

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
name|VM_ALLOC_CLASS_MASK
value|3
end_define

begin_comment
comment|/* page allocation flags: */
end_comment

begin_define
define|#
directive|define
name|VM_ALLOC_WIRED
value|0x0020
end_define

begin_comment
comment|/* non pageable */
end_comment

begin_define
define|#
directive|define
name|VM_ALLOC_ZERO
value|0x0040
end_define

begin_comment
comment|/* Try to obtain a zeroed page */
end_comment

begin_define
define|#
directive|define
name|VM_ALLOC_RETRY
value|0x0080
end_define

begin_comment
comment|/* vm_page_grab() only */
end_comment

begin_define
define|#
directive|define
name|VM_ALLOC_NOOBJ
value|0x0100
end_define

begin_comment
comment|/* No associated object */
end_comment

begin_define
define|#
directive|define
name|VM_ALLOC_NOBUSY
value|0x0200
end_define

begin_comment
comment|/* Do not busy the page */
end_comment

begin_function_decl
name|void
name|vm_page_flag_set
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|unsigned
name|short
name|bits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_flag_clear
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|unsigned
name|short
name|bits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_busy
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_flash
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_io_start
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_io_finish
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_hold
parameter_list|(
name|vm_page_t
name|mem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_unhold
parameter_list|(
name|vm_page_t
name|mem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_free
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_free_zero
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_dirty
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_wakeup
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_pageq_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_pageq_add_new_page
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_pageq_enqueue
parameter_list|(
name|int
name|queue
parameter_list|,
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_pageq_remove_nowakeup
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_pageq_remove
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_page_t
name|vm_pageq_find
parameter_list|(
name|int
name|basequeue
parameter_list|,
name|int
name|index
parameter_list|,
name|boolean_t
name|prefer_zero
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_pageq_requeue
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_activate
parameter_list|(
name|vm_page_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_page_t
name|vm_page_alloc
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_page_t
name|vm_page_alloc_contig
parameter_list|(
name|vm_pindex_t
parameter_list|,
name|vm_paddr_t
parameter_list|,
name|vm_paddr_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_page_t
name|vm_page_grab
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_cache
parameter_list|(
specifier|register
name|vm_page_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_page_try_to_cache
parameter_list|(
name|vm_page_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_page_try_to_free
parameter_list|(
name|vm_page_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_dontneed
parameter_list|(
specifier|register
name|vm_page_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_deactivate
parameter_list|(
name|vm_page_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_insert
parameter_list|(
name|vm_page_t
parameter_list|,
name|vm_object_t
parameter_list|,
name|vm_pindex_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_page_t
name|vm_page_lookup
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_pindex_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_remove
parameter_list|(
name|vm_page_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_rename
parameter_list|(
name|vm_page_t
parameter_list|,
name|vm_object_t
parameter_list|,
name|vm_pindex_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_page_t
name|vm_page_select_cache
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_sleep
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_page_t
name|vm_page_splay
parameter_list|(
name|vm_pindex_t
parameter_list|,
name|vm_page_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|vm_page_startup
parameter_list|(
name|vm_offset_t
name|vaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_unwire
parameter_list|(
name|vm_page_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_wire
parameter_list|(
name|vm_page_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_set_validclean
parameter_list|(
name|vm_page_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_clear_dirty
parameter_list|(
name|vm_page_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_set_invalid
parameter_list|(
name|vm_page_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_page_is_valid
parameter_list|(
name|vm_page_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_test_dirty
parameter_list|(
name|vm_page_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_page_bits
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_zero_invalid
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|boolean_t
name|setvalid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_free_toq
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_zero_idle_wakeup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_cowfault
parameter_list|(
name|vm_page_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_cowsetup
parameter_list|(
name|vm_page_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_cowclear
parameter_list|(
name|vm_page_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	vm_page_sleep_if_busy:  *  *	Sleep and release the page queues lock if VPO_BUSY is set or,  *	if also_m_busy is TRUE, busy is non-zero.  Returns TRUE if the  *	thread slept and the page queues lock was released.  *	Otherwise, retains the page queues lock and returns FALSE.  *  *	The object containing the given page must be locked.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|vm_page_sleep_if_busy
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|int
name|also_m_busy
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
block|{
if|if
condition|(
operator|(
name|m
operator|->
name|oflags
operator|&
name|VPO_BUSY
operator|)
operator|||
operator|(
name|also_m_busy
operator|&&
name|m
operator|->
name|busy
operator|)
condition|)
block|{
name|vm_page_sleep
argument_list|(
name|m
argument_list|,
name|msg
argument_list|)
expr_stmt|;
return|return
operator|(
name|TRUE
operator|)
return|;
block|}
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  *	vm_page_undirty:  *  *	Set page to not be dirty.  Note: does not clear pmap modify bits  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|vm_page_undirty
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
block|{
name|m
operator|->
name|dirty
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_VM_PAGE_ */
end_comment

end_unit

