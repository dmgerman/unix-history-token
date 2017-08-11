begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vm_page.h	8.2 (Berkeley) 12/13/93  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $FreeBSD$  */
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
comment|/*  *	Management of resident (logical) pages.  *  *	A small structure is kept for each resident  *	page, indexed by page number.  Each structure  *	is an element of several collections:  *  *		A radix tree used to quickly  *		perform object/offset lookups  *  *		A list of all pages for a given object,  *		so they can be quickly deactivated at  *		time of deallocation.  *  *		An ordered list of pages due for pageout.  *  *	In addition, the structure contains the object  *	and offset to which this page belongs (for pageout),  *	and sundry status bits.  *  *	In general, operations on this structure's mutable fields are  *	synchronized using either one of or a combination of the lock on the  *	object that the page belongs to (O), the pool lock for the page (P),  *	or the lock for either the free or paging queue (Q).  If a field is  *	annotated below with two of these locks, then holding either lock is  *	sufficient for read access, but both locks are required for write  *	access.  *  *	In contrast, the synchronization of accesses to the page's  *	dirty field is machine dependent (M).  In the  *	machine-independent layer, the lock on the object that the  *	page belongs to must be held in order to operate on the field.  *	However, the pmap layer is permitted to set all bits within  *	the field without holding that lock.  If the underlying  *	architecture does not support atomic read-modify-write  *	operations on the field's type, then the machine-independent  *	layer uses a 32-bit atomic on the aligned 32-bit word that  *	contains the dirty field.  In the machine-independent layer,  *	the implementation of read-modify-write operations on the  *	field is encapsulated in vm_page_clear_dirty_mask().  */
end_comment

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

begin_typedef
typedef|typedef
name|uint8_t
name|vm_page_bits_t
typedef|;
end_typedef

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

begin_typedef
typedef|typedef
name|uint16_t
name|vm_page_bits_t
typedef|;
end_typedef

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

begin_typedef
typedef|typedef
name|uint32_t
name|vm_page_bits_t
typedef|;
end_typedef

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

begin_typedef
typedef|typedef
name|uint64_t
name|vm_page_bits_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|vm_page
block|{
union|union
block|{
name|TAILQ_ENTRY
argument_list|(
argument|vm_page
argument_list|)
name|q
expr_stmt|;
comment|/* page queue or free list (Q) */
struct|struct
block|{
name|SLIST_ENTRY
argument_list|(
argument|vm_page
argument_list|)
name|ss
expr_stmt|;
comment|/* private slists */
name|void
modifier|*
name|pv
decl_stmt|;
block|}
name|s
struct|;
struct|struct
block|{
name|u_long
name|p
decl_stmt|;
name|u_long
name|v
decl_stmt|;
block|}
name|memguard
struct|;
block|}
name|plinks
union|;
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
name|vm_paddr_t
name|phys_addr
decl_stmt|;
comment|/* physical address of page */
name|struct
name|md_page
name|md
decl_stmt|;
comment|/* machine dependent stuff */
name|u_int
name|wire_count
decl_stmt|;
comment|/* wired down maps refs (P) */
specifier|volatile
name|u_int
name|busy_lock
decl_stmt|;
comment|/* busy owners lock */
name|uint16_t
name|hold_count
decl_stmt|;
comment|/* page hold count (P) */
name|uint16_t
name|flags
decl_stmt|;
comment|/* page PG_* flags (P) */
name|uint8_t
name|aflags
decl_stmt|;
comment|/* access is atomic */
name|uint8_t
name|oflags
decl_stmt|;
comment|/* page VPO_* flags (O) */
name|uint8_t
name|queue
decl_stmt|;
comment|/* page queue index (P,Q) */
name|int8_t
name|psind
decl_stmt|;
comment|/* pagesizes[] index (O) */
name|int8_t
name|segind
decl_stmt|;
name|uint8_t
name|order
decl_stmt|;
comment|/* index of the buddy queue */
name|uint8_t
name|pool
decl_stmt|;
name|u_char
name|act_count
decl_stmt|;
comment|/* page usage count (P) */
comment|/* NOTE that these must support one bit per DEV_BSIZE in a page */
comment|/* so, on normal X86 kernels, they must be at least 8 bits wide */
name|vm_page_bits_t
name|valid
decl_stmt|;
comment|/* map of valid DEV_BSIZE chunks (O) */
name|vm_page_bits_t
name|dirty
decl_stmt|;
comment|/* map of dirty DEV_BSIZE chunks (M) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Page flags stored in oflags:  *  * Access to these page flags is synchronized by the lock on the object  * containing the page (O).  *  * Note: VPO_UNMANAGED (used by OBJT_DEVICE, OBJT_PHYS and OBJT_SG)  * 	 indicates that the page is not under PV management but  * 	 otherwise should be treated as a normal page.  Pages not  * 	 under PV management cannot be paged out via the  * 	 object/vm_page_t because there is no knowledge of their pte  * 	 mappings, and such pages are also not on any PQ queue.  *  */
end_comment

begin_define
define|#
directive|define
name|VPO_UNUSED01
value|0x01
end_define

begin_comment
comment|/* --available-- */
end_comment

begin_define
define|#
directive|define
name|VPO_SWAPSLEEP
value|0x02
end_define

begin_comment
comment|/* waiting for swap to finish */
end_comment

begin_define
define|#
directive|define
name|VPO_UNMANAGED
value|0x04
end_define

begin_comment
comment|/* no PV management for page */
end_comment

begin_define
define|#
directive|define
name|VPO_SWAPINPROG
value|0x08
end_define

begin_comment
comment|/* swap I/O in progress on page */
end_comment

begin_define
define|#
directive|define
name|VPO_NOSYNC
value|0x10
end_define

begin_comment
comment|/* do not collect for syncer */
end_comment

begin_comment
comment|/*  * Busy page implementation details.  * The algorithm is taken mostly by rwlock(9) and sx(9) locks implementation,  * even if the support for owner identity is removed because of size  * constraints.  Checks on lock recursion are then not possible, while the  * lock assertions effectiveness is someway reduced.  */
end_comment

begin_define
define|#
directive|define
name|VPB_BIT_SHARED
value|0x01
end_define

begin_define
define|#
directive|define
name|VPB_BIT_EXCLUSIVE
value|0x02
end_define

begin_define
define|#
directive|define
name|VPB_BIT_WAITERS
value|0x04
end_define

begin_define
define|#
directive|define
name|VPB_BIT_FLAGMASK
define|\
value|(VPB_BIT_SHARED | VPB_BIT_EXCLUSIVE | VPB_BIT_WAITERS)
end_define

begin_define
define|#
directive|define
name|VPB_SHARERS_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|VPB_SHARERS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& ~VPB_BIT_FLAGMASK)>> VPB_SHARERS_SHIFT)
end_define

begin_define
define|#
directive|define
name|VPB_SHARERS_WORD
parameter_list|(
name|x
parameter_list|)
value|((x)<< VPB_SHARERS_SHIFT | VPB_BIT_SHARED)
end_define

begin_define
define|#
directive|define
name|VPB_ONE_SHARER
value|(1<< VPB_SHARERS_SHIFT)
end_define

begin_define
define|#
directive|define
name|VPB_SINGLE_EXCLUSIVER
value|VPB_BIT_EXCLUSIVE
end_define

begin_define
define|#
directive|define
name|VPB_UNBUSIED
value|VPB_SHARERS_WORD(0)
end_define

begin_define
define|#
directive|define
name|PQ_NONE
value|255
end_define

begin_define
define|#
directive|define
name|PQ_INACTIVE
value|0
end_define

begin_define
define|#
directive|define
name|PQ_ACTIVE
value|1
end_define

begin_define
define|#
directive|define
name|PQ_LAUNDRY
value|2
end_define

begin_define
define|#
directive|define
name|PQ_UNSWAPPABLE
value|3
end_define

begin_define
define|#
directive|define
name|PQ_COUNT
value|4
end_define

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|pglist
argument_list|,
name|vm_page
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|spglist
argument_list|,
name|vm_page
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|vm_pagequeue
block|{
name|struct
name|mtx
name|pq_mutex
decl_stmt|;
name|struct
name|pglist
name|pq_pl
decl_stmt|;
name|int
name|pq_cnt
decl_stmt|;
name|u_int
modifier|*
specifier|const
name|pq_vcnt
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|pq_name
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|vm_domain
block|{
name|struct
name|vm_pagequeue
name|vmd_pagequeues
index|[
name|PQ_COUNT
index|]
decl_stmt|;
name|u_int
name|vmd_page_count
decl_stmt|;
name|u_int
name|vmd_free_count
decl_stmt|;
name|long
name|vmd_segs
decl_stmt|;
comment|/* bitmask of the segments */
name|boolean_t
name|vmd_oom
decl_stmt|;
name|int
name|vmd_oom_seq
decl_stmt|;
name|int
name|vmd_last_active_scan
decl_stmt|;
name|struct
name|vm_page
name|vmd_laundry_marker
decl_stmt|;
name|struct
name|vm_page
name|vmd_marker
decl_stmt|;
comment|/* marker for pagedaemon private use */
name|struct
name|vm_page
name|vmd_inacthead
decl_stmt|;
comment|/* marker for LRU-defeating insertions */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vm_domain
name|vm_dom
index|[
name|MAXMEMDOM
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|vm_pagequeue_assert_locked
parameter_list|(
name|pq
parameter_list|)
value|mtx_assert(&(pq)->pq_mutex, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|vm_pagequeue_lock
parameter_list|(
name|pq
parameter_list|)
value|mtx_lock(&(pq)->pq_mutex)
end_define

begin_define
define|#
directive|define
name|vm_pagequeue_lockptr
parameter_list|(
name|pq
parameter_list|)
value|(&(pq)->pq_mutex)
end_define

begin_define
define|#
directive|define
name|vm_pagequeue_unlock
parameter_list|(
name|pq
parameter_list|)
value|mtx_unlock(&(pq)->pq_mutex)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|vm_page_t
name|bogus_page
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|void
name|vm_pagequeue_cnt_add
parameter_list|(
name|struct
name|vm_pagequeue
modifier|*
name|pq
parameter_list|,
name|int
name|addend
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|notyet
name|vm_pagequeue_assert_locked
argument_list|(
name|pq
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|pq
operator|->
name|pq_cnt
operator|+=
name|addend
expr_stmt|;
name|atomic_add_int
argument_list|(
name|pq
operator|->
name|pq_vcnt
argument_list|,
name|addend
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|vm_pagequeue_cnt_inc
parameter_list|(
name|pq
parameter_list|)
value|vm_pagequeue_cnt_add((pq), 1)
end_define

begin_define
define|#
directive|define
name|vm_pagequeue_cnt_dec
parameter_list|(
name|pq
parameter_list|)
value|vm_pagequeue_cnt_add((pq), -1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mtx_padalign
name|vm_page_queue_free_mtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mtx_padalign
name|pa_lock
index|[]
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arm__
argument_list|)
end_if

begin_define
define|#
directive|define
name|PDRSHIFT
value|PDR_SHIFT
end_define

begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|PDRSHIFT
argument_list|)
end_elif

begin_define
define|#
directive|define
name|PDRSHIFT
value|21
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|pa_index
parameter_list|(
name|pa
parameter_list|)
value|((pa)>> PDRSHIFT)
end_define

begin_define
define|#
directive|define
name|PA_LOCKPTR
parameter_list|(
name|pa
parameter_list|)
value|((struct mtx *)(&pa_lock[pa_index(pa) % PA_LOCK_COUNT]))
end_define

begin_define
define|#
directive|define
name|PA_LOCKOBJPTR
parameter_list|(
name|pa
parameter_list|)
value|((struct lock_object *)PA_LOCKPTR((pa)))
end_define

begin_define
define|#
directive|define
name|PA_LOCK
parameter_list|(
name|pa
parameter_list|)
value|mtx_lock(PA_LOCKPTR(pa))
end_define

begin_define
define|#
directive|define
name|PA_TRYLOCK
parameter_list|(
name|pa
parameter_list|)
value|mtx_trylock(PA_LOCKPTR(pa))
end_define

begin_define
define|#
directive|define
name|PA_UNLOCK
parameter_list|(
name|pa
parameter_list|)
value|mtx_unlock(PA_LOCKPTR(pa))
end_define

begin_define
define|#
directive|define
name|PA_UNLOCK_COND
parameter_list|(
name|pa
parameter_list|)
define|\
value|do {		   			\ 		if ((pa) != 0) {		\ 			PA_UNLOCK((pa));	\ 			(pa) = 0;		\ 		}				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|PA_LOCK_ASSERT
parameter_list|(
name|pa
parameter_list|,
name|a
parameter_list|)
value|mtx_assert(PA_LOCKPTR(pa), (a))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KLD_MODULE
end_ifdef

begin_define
define|#
directive|define
name|vm_page_lock
parameter_list|(
name|m
parameter_list|)
value|vm_page_lock_KBI((m), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|vm_page_unlock
parameter_list|(
name|m
parameter_list|)
value|vm_page_unlock_KBI((m), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|vm_page_trylock
parameter_list|(
name|m
parameter_list|)
value|vm_page_trylock_KBI((m), LOCK_FILE, LOCK_LINE)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !KLD_MODULE */
end_comment

begin_define
define|#
directive|define
name|vm_page_lockptr
parameter_list|(
name|m
parameter_list|)
value|(PA_LOCKPTR(VM_PAGE_TO_PHYS((m))))
end_define

begin_define
define|#
directive|define
name|vm_page_lock
parameter_list|(
name|m
parameter_list|)
value|mtx_lock(vm_page_lockptr((m)))
end_define

begin_define
define|#
directive|define
name|vm_page_unlock
parameter_list|(
name|m
parameter_list|)
value|mtx_unlock(vm_page_lockptr((m)))
end_define

begin_define
define|#
directive|define
name|vm_page_trylock
parameter_list|(
name|m
parameter_list|)
value|mtx_trylock(vm_page_lockptr((m)))
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
name|INVARIANTS
argument_list|)
end_if

begin_define
define|#
directive|define
name|vm_page_assert_locked
parameter_list|(
name|m
parameter_list|)
define|\
value|vm_page_assert_locked_KBI((m), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|vm_page_lock_assert
parameter_list|(
name|m
parameter_list|,
name|a
parameter_list|)
define|\
value|vm_page_lock_assert_KBI((m), (a), __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vm_page_assert_locked
parameter_list|(
name|m
parameter_list|)
end_define

begin_define
define|#
directive|define
name|vm_page_lock_assert
parameter_list|(
name|m
parameter_list|,
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The vm_page's aflags are updated using atomic operations.  To set or clear  * these flags, the functions vm_page_aflag_set() and vm_page_aflag_clear()  * must be used.  Neither these flags nor these functions are part of the KBI.  *  * PGA_REFERENCED may be cleared only if the page is locked.  It is set by  * both the MI and MD VM layers.  However, kernel loadable modules should not  * directly set this flag.  They should call vm_page_reference() instead.  *  * PGA_WRITEABLE is set exclusively on managed pages by pmap_enter().  * When it does so, the object must be locked, or the page must be  * exclusive busied.  The MI VM layer must never access this flag  * directly.  Instead, it should call pmap_page_is_write_mapped().  *  * PGA_EXECUTABLE may be set by pmap routines, and indicates that a page has  * at least one executable mapping.  It is not consumed by the MI VM layer.  */
end_comment

begin_define
define|#
directive|define
name|PGA_WRITEABLE
value|0x01
end_define

begin_comment
comment|/* page may be mapped writeable */
end_comment

begin_define
define|#
directive|define
name|PGA_REFERENCED
value|0x02
end_define

begin_comment
comment|/* page has been referenced */
end_comment

begin_define
define|#
directive|define
name|PGA_EXECUTABLE
value|0x04
end_define

begin_comment
comment|/* page may be mapped executable */
end_comment

begin_comment
comment|/*  * Page flags.  If changed at any other time than page allocation or  * freeing, the modification must be protected by the vm_page lock.  */
end_comment

begin_define
define|#
directive|define
name|PG_FICTITIOUS
value|0x0004
end_define

begin_comment
comment|/* physical page doesn't exist */
end_comment

begin_define
define|#
directive|define
name|PG_ZERO
value|0x0008
end_define

begin_comment
comment|/* page is zeroed */
end_comment

begin_define
define|#
directive|define
name|PG_MARKER
value|0x0010
end_define

begin_comment
comment|/* special queue marker page */
end_comment

begin_define
define|#
directive|define
name|PG_NODUMP
value|0x0080
end_define

begin_comment
comment|/* don't include this page in a dump */
end_comment

begin_define
define|#
directive|define
name|PG_UNHOLDFREE
value|0x0100
end_define

begin_comment
comment|/* delayed free of a held page */
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
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_comment
comment|/*  * Each pageable resident page falls into one of five lists:  *  *	free  *		Available for allocation now.  *  *	inactive  *		Low activity, candidates for reclamation.  *		This list is approximately LRU ordered.  *  *	laundry  *		This is the list of pages that should be  *		paged out next.  *  *	unswappable  *		Dirty anonymous pages that cannot be paged  *		out because no swap device is configured.  *  *	active  *		Pages that are "active", i.e., they have been  *		recently referenced.  *  */
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

begin_comment
comment|/*  * PHYS_TO_VM_PAGE() returns the vm_page_t object that represents a memory  * page to which the given physical address belongs. The correct vm_page_t  * object is returned for addresses that are not page-aligned.  */
end_comment

begin_function_decl
name|vm_page_t
name|PHYS_TO_VM_PAGE
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Page allocation parameters for vm_page for the functions  * vm_page_alloc(), vm_page_grab(), vm_page_alloc_contig() and  * vm_page_alloc_freelist().  Some functions support only a subset  * of the flags, and ignore others, see the flags legend.  *  * The meaning of VM_ALLOC_ZERO differs slightly between the vm_page_alloc*()  * and the vm_page_grab*() functions.  See these functions for details.  *  * Bits 0 - 1 define class.  * Bits 2 - 15 dedicated for flags.  * Legend:  * (a) - vm_page_alloc() supports the flag.  * (c) - vm_page_alloc_contig() supports the flag.  * (f) - vm_page_alloc_freelist() supports the flag.  * (g) - vm_page_grab() supports the flag.  * (p) - vm_page_grab_pages() supports the flag.  * Bits above 15 define the count of additional pages that the caller  * intends to allocate.  */
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

begin_define
define|#
directive|define
name|VM_ALLOC_WIRED
value|0x0020
end_define

begin_comment
comment|/* (acfgp) Allocate a wired page */
end_comment

begin_define
define|#
directive|define
name|VM_ALLOC_ZERO
value|0x0040
end_define

begin_comment
comment|/* (acfgp) Allocate a prezeroed page */
end_comment

begin_define
define|#
directive|define
name|VM_ALLOC_NOOBJ
value|0x0100
end_define

begin_comment
comment|/* (acg) No associated object */
end_comment

begin_define
define|#
directive|define
name|VM_ALLOC_NOBUSY
value|0x0200
end_define

begin_comment
comment|/* (acgp) Do not excl busy the page */
end_comment

begin_define
define|#
directive|define
name|VM_ALLOC_IGN_SBUSY
value|0x1000
end_define

begin_comment
comment|/* (gp) Ignore shared busy flag */
end_comment

begin_define
define|#
directive|define
name|VM_ALLOC_NODUMP
value|0x2000
end_define

begin_comment
comment|/* (ag) don't include in dump */
end_comment

begin_define
define|#
directive|define
name|VM_ALLOC_SBUSY
value|0x4000
end_define

begin_comment
comment|/* (acgp) Shared busy the page */
end_comment

begin_define
define|#
directive|define
name|VM_ALLOC_NOWAIT
value|0x8000
end_define

begin_comment
comment|/* (g) Do not sleep, return NULL */
end_comment

begin_define
define|#
directive|define
name|VM_ALLOC_COUNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|VM_ALLOC_COUNT
parameter_list|(
name|count
parameter_list|)
value|((count)<< VM_ALLOC_COUNT_SHIFT)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|M_NOWAIT
end_ifdef

begin_function
specifier|static
specifier|inline
name|int
name|malloc2vm_flags
parameter_list|(
name|int
name|malloc_flags
parameter_list|)
block|{
name|int
name|pflags
decl_stmt|;
name|KASSERT
argument_list|(
operator|(
name|malloc_flags
operator|&
name|M_USE_RESERVE
operator|)
operator|==
literal|0
operator|||
operator|(
name|malloc_flags
operator|&
name|M_NOWAIT
operator|)
operator|!=
literal|0
argument_list|,
operator|(
literal|"M_USE_RESERVE requires M_NOWAIT"
operator|)
argument_list|)
expr_stmt|;
name|pflags
operator|=
operator|(
name|malloc_flags
operator|&
name|M_USE_RESERVE
operator|)
operator|!=
literal|0
condition|?
name|VM_ALLOC_INTERRUPT
else|:
name|VM_ALLOC_SYSTEM
expr_stmt|;
if|if
condition|(
operator|(
name|malloc_flags
operator|&
name|M_ZERO
operator|)
operator|!=
literal|0
condition|)
name|pflags
operator||=
name|VM_ALLOC_ZERO
expr_stmt|;
if|if
condition|(
operator|(
name|malloc_flags
operator|&
name|M_NODUMP
operator|)
operator|!=
literal|0
condition|)
name|pflags
operator||=
name|VM_ALLOC_NODUMP
expr_stmt|;
return|return
operator|(
name|pflags
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Predicates supported by vm_page_ps_test():  *  *	PS_ALL_DIRTY is true only if the entire (super)page is dirty.  *	However, it can be spuriously false when the (super)page has become  *	dirty in the pmap but that information has not been propagated to the  *	machine-independent layer.  */
end_comment

begin_define
define|#
directive|define
name|PS_ALL_DIRTY
value|0x1
end_define

begin_define
define|#
directive|define
name|PS_ALL_VALID
value|0x2
end_define

begin_define
define|#
directive|define
name|PS_NONE_BUSY
value|0x4
end_define

begin_function_decl
name|void
name|vm_page_busy_downgrade
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_busy_sleep
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
name|bool
name|nonshared
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
name|vm_page_activate
parameter_list|(
name|vm_page_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_advise
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|int
name|advice
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
name|vm_object_t
name|object
parameter_list|,
name|vm_pindex_t
name|pindex
parameter_list|,
name|int
name|req
parameter_list|,
name|u_long
name|npages
parameter_list|,
name|vm_paddr_t
name|low
parameter_list|,
name|vm_paddr_t
name|high
parameter_list|,
name|u_long
name|alignment
parameter_list|,
name|vm_paddr_t
name|boundary
parameter_list|,
name|vm_memattr_t
name|memattr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_page_t
name|vm_page_alloc_freelist
parameter_list|(
name|int
parameter_list|,
name|int
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
name|vm_page_grab_pages
parameter_list|(
name|vm_object_t
name|object
parameter_list|,
name|vm_pindex_t
name|pindex
parameter_list|,
name|int
name|allocflags
parameter_list|,
name|vm_page_t
modifier|*
name|ma
parameter_list|,
name|int
name|count
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
name|vm_page_deactivate
parameter_list|(
name|vm_page_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_deactivate_noreuse
parameter_list|(
name|vm_page_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_dequeue
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_dequeue_locked
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_page_t
name|vm_page_find_least
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_pindex_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_page_t
name|vm_page_getfake
parameter_list|(
name|vm_paddr_t
name|paddr
parameter_list|,
name|vm_memattr_t
name|memattr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_initfake
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|vm_paddr_t
name|paddr
parameter_list|,
name|vm_memattr_t
name|memattr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
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
name|void
name|vm_page_launder
parameter_list|(
name|vm_page_t
name|m
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
name|vm_page_t
name|vm_page_next
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_page_pa_tryrelock
parameter_list|(
name|pmap_t
parameter_list|,
name|vm_paddr_t
parameter_list|,
name|vm_paddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|vm_pagequeue
modifier|*
name|vm_page_pagequeue
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_page_t
name|vm_page_prev
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|vm_page_ps_test
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|int
name|flags
parameter_list|,
name|vm_page_t
name|skip_m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_putfake
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_readahead_finish
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|vm_page_reclaim_contig
parameter_list|(
name|int
name|req
parameter_list|,
name|u_long
name|npages
parameter_list|,
name|vm_paddr_t
name|low
parameter_list|,
name|vm_paddr_t
name|high
parameter_list|,
name|u_long
name|alignment
parameter_list|,
name|vm_paddr_t
name|boundary
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_reference
parameter_list|(
name|vm_page_t
name|m
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
name|int
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
name|vm_page_replace
parameter_list|(
name|vm_page_t
name|mnew
parameter_list|,
name|vm_object_t
name|object
parameter_list|,
name|vm_pindex_t
name|pindex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_requeue
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_requeue_locked
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_page_sbusied
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_page_t
name|vm_page_scan_contig
parameter_list|(
name|u_long
name|npages
parameter_list|,
name|vm_page_t
name|m_start
parameter_list|,
name|vm_page_t
name|m_end
parameter_list|,
name|u_long
name|alignment
parameter_list|,
name|vm_paddr_t
name|boundary
parameter_list|,
name|int
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_set_valid_range
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|int
name|base
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_page_sleep_if_busy
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
name|vm_page_sunbusy
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_page_trysbusy
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_unhold_pages
parameter_list|(
name|vm_page_t
modifier|*
name|ma
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_unswappable
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|vm_page_unwire
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|uint8_t
name|queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_updatefake
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|vm_paddr_t
name|paddr
parameter_list|,
name|vm_memattr_t
name|memattr
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
name|vm_page_xunbusy_hard
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_xunbusy_maybelocked
parameter_list|(
name|vm_page_t
name|m
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
name|vm_page_bits_t
name|vm_page_bits
parameter_list|(
name|int
name|base
parameter_list|,
name|int
name|size
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
name|vm_page_dirty_KBI
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_lock_KBI
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_unlock_KBI
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_page_trylock_KBI
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INVARIANTS
argument_list|)
operator|||
name|defined
argument_list|(
name|INVARIANT_SUPPORT
argument_list|)
end_if

begin_function_decl
name|void
name|vm_page_assert_locked_KBI
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_page_lock_assert_KBI
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|int
name|a
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|vm_page_assert_sbusied
parameter_list|(
name|m
parameter_list|)
define|\
value|KASSERT(vm_page_sbusied(m),					\ 	    ("vm_page_assert_sbusied: page %p not shared busy @ %s:%d", \ 	    (m), __FILE__, __LINE__))
end_define

begin_define
define|#
directive|define
name|vm_page_assert_unbusied
parameter_list|(
name|m
parameter_list|)
define|\
value|KASSERT(!vm_page_busied(m),					\ 	    ("vm_page_assert_unbusied: page %p busy @ %s:%d",		\ 	    (m), __FILE__, __LINE__))
end_define

begin_define
define|#
directive|define
name|vm_page_assert_xbusied
parameter_list|(
name|m
parameter_list|)
define|\
value|KASSERT(vm_page_xbusied(m),					\ 	    ("vm_page_assert_xbusied: page %p not exclusive busy @ %s:%d", \ 	    (m), __FILE__, __LINE__))
end_define

begin_define
define|#
directive|define
name|vm_page_busied
parameter_list|(
name|m
parameter_list|)
define|\
value|((m)->busy_lock != VPB_UNBUSIED)
end_define

begin_define
define|#
directive|define
name|vm_page_sbusy
parameter_list|(
name|m
parameter_list|)
value|do {						\ 	if (!vm_page_trysbusy(m))					\ 		panic("%s: page %p failed shared busying", __func__,	\ 		    (m));						\ } while (0)
end_define

begin_define
define|#
directive|define
name|vm_page_tryxbusy
parameter_list|(
name|m
parameter_list|)
define|\
value|(atomic_cmpset_acq_int(&(m)->busy_lock, VPB_UNBUSIED,		\ 	    VPB_SINGLE_EXCLUSIVER))
end_define

begin_define
define|#
directive|define
name|vm_page_xbusied
parameter_list|(
name|m
parameter_list|)
define|\
value|(((m)->busy_lock& VPB_SINGLE_EXCLUSIVER) != 0)
end_define

begin_define
define|#
directive|define
name|vm_page_xbusy
parameter_list|(
name|m
parameter_list|)
value|do {						\ 	if (!vm_page_tryxbusy(m))					\ 		panic("%s: page %p failed exclusive busying", __func__,	\ 		    (m));						\ } while (0)
end_define

begin_comment
comment|/* Note: page m's lock must not be owned by the caller. */
end_comment

begin_define
define|#
directive|define
name|vm_page_xunbusy
parameter_list|(
name|m
parameter_list|)
value|do {						\ 	if (!atomic_cmpset_rel_int(&(m)->busy_lock,			\ 	    VPB_SINGLE_EXCLUSIVER, VPB_UNBUSIED))			\ 		vm_page_xunbusy_hard(m);				\ } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_function_decl
name|void
name|vm_page_object_lock_assert
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|VM_PAGE_OBJECT_LOCK_ASSERT
parameter_list|(
name|m
parameter_list|)
value|vm_page_object_lock_assert(m)
end_define

begin_function_decl
name|void
name|vm_page_assert_pga_writeable
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|uint8_t
name|bits
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|VM_PAGE_ASSERT_PGA_WRITEABLE
parameter_list|(
name|m
parameter_list|,
name|bits
parameter_list|)
define|\
value|vm_page_assert_pga_writeable(m, bits)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VM_PAGE_OBJECT_LOCK_ASSERT
parameter_list|(
name|m
parameter_list|)
value|(void)0
end_define

begin_define
define|#
directive|define
name|VM_PAGE_ASSERT_PGA_WRITEABLE
parameter_list|(
name|m
parameter_list|,
name|bits
parameter_list|)
value|(void)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * We want to use atomic updates for the aflags field, which is 8 bits wide.  * However, not all architectures support atomic operations on 8-bit  * destinations.  In order that we can easily use a 32-bit operation, we  * require that the aflags field be 32-bit aligned.  */
end_comment

begin_expr_stmt
name|CTASSERT
argument_list|(
name|offsetof
argument_list|(
expr|struct
name|vm_page
argument_list|,
name|aflags
argument_list|)
operator|%
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  *	Clear the given bits in the specified page.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|vm_page_aflag_clear
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|uint8_t
name|bits
parameter_list|)
block|{
name|uint32_t
modifier|*
name|addr
decl_stmt|,
name|val
decl_stmt|;
comment|/* 	 * The PGA_REFERENCED flag can only be cleared if the page is locked. 	 */
if|if
condition|(
operator|(
name|bits
operator|&
name|PGA_REFERENCED
operator|)
operator|!=
literal|0
condition|)
name|vm_page_assert_locked
argument_list|(
name|m
argument_list|)
expr_stmt|;
comment|/* 	 * Access the whole 32-bit word containing the aflags field with an 	 * atomic update.  Parallel non-atomic updates to the other fields 	 * within this word are handled properly by the atomic update. 	 */
name|addr
operator|=
operator|(
name|void
operator|*
operator|)
operator|&
name|m
operator|->
name|aflags
expr_stmt|;
name|KASSERT
argument_list|(
operator|(
operator|(
name|uintptr_t
operator|)
name|addr
operator|&
operator|(
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
argument_list|,
operator|(
literal|"vm_page_aflag_clear: aflags is misaligned"
operator|)
argument_list|)
expr_stmt|;
name|val
operator|=
name|bits
expr_stmt|;
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|val
operator|<<=
literal|24
expr_stmt|;
endif|#
directive|endif
name|atomic_clear_32
argument_list|(
name|addr
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  *	Set the given bits in the specified page.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|vm_page_aflag_set
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|uint8_t
name|bits
parameter_list|)
block|{
name|uint32_t
modifier|*
name|addr
decl_stmt|,
name|val
decl_stmt|;
name|VM_PAGE_ASSERT_PGA_WRITEABLE
argument_list|(
name|m
argument_list|,
name|bits
argument_list|)
expr_stmt|;
comment|/* 	 * Access the whole 32-bit word containing the aflags field with an 	 * atomic update.  Parallel non-atomic updates to the other fields 	 * within this word are handled properly by the atomic update. 	 */
name|addr
operator|=
operator|(
name|void
operator|*
operator|)
operator|&
name|m
operator|->
name|aflags
expr_stmt|;
name|KASSERT
argument_list|(
operator|(
operator|(
name|uintptr_t
operator|)
name|addr
operator|&
operator|(
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
argument_list|,
operator|(
literal|"vm_page_aflag_set: aflags is misaligned"
operator|)
argument_list|)
expr_stmt|;
name|val
operator|=
name|bits
expr_stmt|;
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|val
operator|<<=
literal|24
expr_stmt|;
endif|#
directive|endif
name|atomic_set_32
argument_list|(
name|addr
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  *	vm_page_dirty:  *  *	Set all bits in the page's dirty field.  *  *	The object containing the specified page must be locked if the  *	call is made from the machine-independent layer.  *  *	See vm_page_clear_dirty_mask().  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|vm_page_dirty
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
block|{
comment|/* Use vm_page_dirty_KBI() under INVARIANTS to save memory. */
if|#
directive|if
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
operator|||
name|defined
argument_list|(
name|INVARIANTS
argument_list|)
name|vm_page_dirty_KBI
argument_list|(
name|m
argument_list|)
expr_stmt|;
else|#
directive|else
name|m
operator|->
name|dirty
operator|=
name|VM_PAGE_BITS_ALL
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  *	vm_page_remque:  *  *	If the given page is in a page queue, then remove it from that page  *	queue.  *  *	The page must be locked.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|vm_page_remque
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
block|{
if|if
condition|(
name|m
operator|->
name|queue
operator|!=
name|PQ_NONE
condition|)
name|vm_page_dequeue
argument_list|(
name|m
argument_list|)
expr_stmt|;
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
name|VM_PAGE_OBJECT_LOCK_ASSERT
argument_list|(
name|m
argument_list|)
expr_stmt|;
name|m
operator|->
name|dirty
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|vm_page_replace_checked
parameter_list|(
name|vm_page_t
name|mnew
parameter_list|,
name|vm_object_t
name|object
parameter_list|,
name|vm_pindex_t
name|pindex
parameter_list|,
name|vm_page_t
name|mold
parameter_list|)
block|{
name|vm_page_t
name|mret
decl_stmt|;
name|mret
operator|=
name|vm_page_replace
argument_list|(
name|mnew
argument_list|,
name|object
argument_list|,
name|pindex
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|mret
operator|==
name|mold
argument_list|,
operator|(
literal|"invalid page replacement, mold=%p, mret=%p"
operator|,
name|mold
operator|,
name|mret
operator|)
argument_list|)
expr_stmt|;
comment|/* Unused if !INVARIANTS. */
operator|(
name|void
operator|)
name|mold
expr_stmt|;
operator|(
name|void
operator|)
name|mret
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|bool
name|vm_page_active
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
block|{
return|return
operator|(
name|m
operator|->
name|queue
operator|==
name|PQ_ACTIVE
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|bool
name|vm_page_inactive
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
block|{
return|return
operator|(
name|m
operator|->
name|queue
operator|==
name|PQ_INACTIVE
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|bool
name|vm_page_in_laundry
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
block|{
return|return
operator|(
name|m
operator|->
name|queue
operator|==
name|PQ_LAUNDRY
operator|||
name|m
operator|->
name|queue
operator|==
name|PQ_UNSWAPPABLE
operator|)
return|;
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

