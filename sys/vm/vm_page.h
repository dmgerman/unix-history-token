begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vm_page.h	8.2 (Berkeley) 12/13/93  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $FreeBSD$  */
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
end_if

begin_include
include|#
directive|include
file|"opt_vmpage.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
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
name|struct
name|vm_page
modifier|*
name|hnext
decl_stmt|;
comment|/* hash table link (O,P)	*/
name|TAILQ_ENTRY
argument_list|(
argument|vm_page
argument_list|)
name|listq
expr_stmt|;
comment|/* pages in same object (O) 	*/
name|vm_object_t
name|object
decl_stmt|;
comment|/* which object am I in (O,P)*/
name|vm_pindex_t
name|pindex
decl_stmt|;
comment|/* offset into object (O,P) */
name|vm_offset_t
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
if|#
directive|if
name|PAGE_SIZE
operator|==
literal|4096
name|u_char
name|valid
decl_stmt|;
comment|/* map of valid DEV_BSIZE chunks */
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
comment|/* map of valid DEV_BSIZE chunks */
name|u_short
name|dirty
decl_stmt|;
comment|/* map of dirty DEV_BSIZE chunks */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * note: currently use SWAPBLK_NONE as an absolute value rather then   * a flag bit.  */
end_comment

begin_define
define|#
directive|define
name|SWAPBLK_MASK
value|((daddr_t)((u_daddr_t)-1>> 1))
end_define

begin_comment
comment|/* mask */
end_comment

begin_define
define|#
directive|define
name|SWAPBLK_NONE
value|((daddr_t)((u_daddr_t)SWAPBLK_MASK + 1))
end_define

begin_comment
comment|/* flag */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
end_if

begin_comment
comment|/*  * Page coloring parameters  */
end_comment

begin_comment
comment|/* Each of PQ_FREE, and PQ_CACHE have PQ_HASH_SIZE entries */
end_comment

begin_comment
comment|/* Backward compatibility for existing PQ_*CACHE config options. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PQ_CACHESIZE
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PQ_HUGECACHE
argument_list|)
end_if

begin_define
define|#
directive|define
name|PQ_CACHESIZE
value|1024
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|PQ_LARGECACHE
argument_list|)
end_elif

begin_define
define|#
directive|define
name|PQ_CACHESIZE
value|512
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|PQ_MEDIUMCACHE
argument_list|)
end_elif

begin_define
define|#
directive|define
name|PQ_CACHESIZE
value|256
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|PQ_NORMALCACHE
argument_list|)
end_elif

begin_define
define|#
directive|define
name|PQ_CACHESIZE
value|64
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|PQ_NOOPT
argument_list|)
end_elif

begin_define
define|#
directive|define
name|PQ_CACHESIZE
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PQ_CACHESIZE
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|PQ_CACHESIZE
operator|>=
literal|1024
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
name|PQ_L2_SIZE
value|256
end_define

begin_comment
comment|/* A number of colors opt for 1M cache */
end_comment

begin_elif
elif|#
directive|elif
name|PQ_CACHESIZE
operator|>=
literal|512
end_elif

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
name|PQ_L2_SIZE
value|128
end_define

begin_comment
comment|/* A number of colors opt for 512K cache */
end_comment

begin_elif
elif|#
directive|elif
name|PQ_CACHESIZE
operator|>=
literal|256
end_elif

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
name|PQ_L2_SIZE
value|64
end_define

begin_comment
comment|/* A number of colors opt for 256K cache */
end_comment

begin_elif
elif|#
directive|elif
name|PQ_CACHESIZE
operator|>=
literal|128
end_elif

begin_define
define|#
directive|define
name|PQ_PRIME1
value|9
end_define

begin_comment
comment|/* Produces a good PQ_L2_SIZE/3 + PQ_PRIME1 */
end_comment

begin_define
define|#
directive|define
name|PQ_PRIME2
value|5
end_define

begin_comment
comment|/* Prime number somewhat less than PQ_HASH_SIZE */
end_comment

begin_define
define|#
directive|define
name|PQ_L2_SIZE
value|32
end_define

begin_comment
comment|/* A number of colors opt for 128k cache */
end_comment

begin_elif
elif|#
directive|elif
name|PQ_CACHESIZE
operator|>=
literal|64
end_elif

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
name|PQ_L2_SIZE
value|16
end_define

begin_comment
comment|/* A reasonable number of colors (opt for 64K cache) */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PQ_PRIME1
value|1
end_define

begin_comment
comment|/* Disable page coloring. */
end_comment

begin_define
define|#
directive|define
name|PQ_PRIME2
value|1
end_define

begin_define
define|#
directive|define
name|PQ_L2_SIZE
value|1
end_define

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

begin_if
if|#
directive|if
literal|1
end_if

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
value|(1 + 1*PQ_L2_SIZE)
end_define

begin_define
define|#
directive|define
name|PQ_ACTIVE
value|(2 + 1*PQ_L2_SIZE)
end_define

begin_define
define|#
directive|define
name|PQ_CACHE
value|(3 + 1*PQ_L2_SIZE)
end_define

begin_define
define|#
directive|define
name|PQ_COUNT
value|(3 + 2*PQ_L2_SIZE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PQ_NONE
value|PQ_COUNT
end_define

begin_define
define|#
directive|define
name|PQ_FREE
value|0
end_define

begin_define
define|#
directive|define
name|PQ_INACTIVE
value|PQ_L2_SIZE
end_define

begin_define
define|#
directive|define
name|PQ_ACTIVE
value|(1 +   PQ_L2_SIZE)
end_define

begin_define
define|#
directive|define
name|PQ_CACHE
value|(2 +   PQ_L2_SIZE)
end_define

begin_define
define|#
directive|define
name|PQ_COUNT
value|(2 + 2*PQ_L2_SIZE)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_decl_stmt
specifier|extern
name|struct
name|vpgqueues
name|vm_page_queues
index|[
name|PQ_COUNT
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * These are the flags defined for vm_page.  *  * Note: PG_FILLED and PG_DIRTY are added for the filesystems.  *  * Note: PG_UNMANAGED (used by OBJT_PHYS) indicates that the page is  * 	 not under PV management but otherwise should be treated as a  *	 normal page.  Pages not under PV management cannot be paged out  *	 via the object/vm_page_t because there is no knowledge of their  *	 pte mappings, nor can they be removed from their objects via   *	 the object, and such pages are also not on any PQ queue.  */
end_comment

begin_define
define|#
directive|define
name|PG_BUSY
value|0x0001
end_define

begin_comment
comment|/* page is in transit (O) */
end_comment

begin_define
define|#
directive|define
name|PG_WANTED
value|0x0002
end_define

begin_comment
comment|/* someone is waiting for page (O) */
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
name|PG_MAPPED
value|0x0020
end_define

begin_comment
comment|/* page is mapped */
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
name|PG_CLEANCHK
value|0x0100
end_define

begin_comment
comment|/* page will be checked for cleaning */
end_comment

begin_define
define|#
directive|define
name|PG_SWAPINPROG
value|0x0200
end_define

begin_comment
comment|/* swap I/O in progress on page	     */
end_comment

begin_define
define|#
directive|define
name|PG_NOSYNC
value|0x0400
end_define

begin_comment
comment|/* do not collect for syncer */
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
name|_KERNEL
end_ifdef

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

begin_function
specifier|static
name|__inline
name|void
name|vm_page_flag_set
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|unsigned
name|int
name|bits
parameter_list|)
block|{
name|atomic_set_short
argument_list|(
operator|&
operator|(
name|m
operator|)
operator|->
name|flags
argument_list|,
name|bits
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|vm_page_flag_clear
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|unsigned
name|int
name|bits
parameter_list|)
block|{
name|atomic_clear_short
argument_list|(
operator|&
operator|(
name|m
operator|)
operator|->
name|flags
argument_list|,
name|bits
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static __inline void vm_page_assert_wait(vm_page_t m, int interruptible) { 	vm_page_flag_set(m, PG_WANTED); 	assert_wait((int) m, interruptible); }
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|void
name|vm_page_busy
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
block|{
name|KASSERT
argument_list|(
operator|(
name|m
operator|->
name|flags
operator|&
name|PG_BUSY
operator|)
operator|==
literal|0
argument_list|,
operator|(
literal|"vm_page_busy: page already busy!!!"
operator|)
argument_list|)
expr_stmt|;
name|vm_page_flag_set
argument_list|(
name|m
argument_list|,
name|PG_BUSY
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  *	vm_page_flash:  *  *	wakeup anyone waiting for the page.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|vm_page_flash
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
block|{
if|if
condition|(
name|m
operator|->
name|flags
operator|&
name|PG_WANTED
condition|)
block|{
name|vm_page_flag_clear
argument_list|(
name|m
argument_list|,
name|PG_WANTED
argument_list|)
expr_stmt|;
name|wakeup
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  *	vm_page_wakeup:  *  *	clear the PG_BUSY flag and wakeup anyone waiting for the  *	page.  *  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|vm_page_wakeup
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
block|{
name|KASSERT
argument_list|(
name|m
operator|->
name|flags
operator|&
name|PG_BUSY
argument_list|,
operator|(
literal|"vm_page_wakeup: page not busy!!!"
operator|)
argument_list|)
expr_stmt|;
name|vm_page_flag_clear
argument_list|(
name|m
argument_list|,
name|PG_BUSY
argument_list|)
expr_stmt|;
name|vm_page_flash
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  *  *  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|vm_page_io_start
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
block|{
name|atomic_add_char
argument_list|(
operator|&
operator|(
name|m
operator|)
operator|->
name|busy
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|vm_page_io_finish
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
block|{
name|atomic_subtract_char
argument_list|(
operator|&
name|m
operator|->
name|busy
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|->
name|busy
operator|==
literal|0
condition|)
name|vm_page_flash
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
end_function

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
name|int
name|vm_page_try_to_cache
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
name|vm_page_try_to_free
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
name|vm_page_dontneed
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
specifier|static
name|__inline
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
specifier|static
name|__inline
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
name|vm_page_t
name|vm_add_new_page
name|__P
argument_list|(
operator|(
name|vm_offset_t
name|pa
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_page_unmanage
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
name|vm_page_unwire
name|__P
argument_list|(
operator|(
name|vm_page_t
operator|,
name|int
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
name|vm_page_set_dirty
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
name|vm_page_clear_dirty
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
name|_vm_page_list_find
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

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|int vm_page_sleep(vm_page_t m, char *msg, char *busy); int vm_page_asleep(vm_page_t m, char *msg, char *busy);
endif|#
directive|endif
end_endif

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
operator|--
name|mem
operator|->
name|hold_count
expr_stmt|;
name|KASSERT
argument_list|(
name|mem
operator|->
name|hold_count
operator|>=
literal|0
argument_list|,
operator|(
literal|"vm_page_unhold: hold count< 0!!!"
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * 	vm_page_protect:  *  *	Reduce the protection of a page.  This routine never raises the   *	protection and therefore can be safely called if the page is already  *	at VM_PROT_NONE (it will be a NOP effectively ).  */
end_comment

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
name|mem
argument_list|,
name|VM_PROT_NONE
argument_list|)
expr_stmt|;
name|vm_page_flag_clear
argument_list|(
name|mem
argument_list|,
name|PG_WRITEABLE
operator||
name|PG_MAPPED
argument_list|)
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
name|mem
argument_list|,
name|VM_PROT_READ
argument_list|)
expr_stmt|;
name|vm_page_flag_clear
argument_list|(
name|mem
argument_list|,
name|PG_WRITEABLE
argument_list|)
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

begin_comment
comment|/*  *	vm_page_free:  *  *	Free a page  *  *	The clearing of PG_ZERO is a temporary safety until the code can be  *	reviewed to determine that PG_ZERO is being properly cleared on  *	write faults or maps.  PG_ZERO was previously cleared in   *	vm_page_alloc().  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|vm_page_free
parameter_list|(
name|m
parameter_list|)
name|vm_page_t
name|m
decl_stmt|;
block|{
name|vm_page_flag_clear
argument_list|(
name|m
argument_list|,
name|PG_ZERO
argument_list|)
expr_stmt|;
name|vm_page_free_toq
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  *	vm_page_free_zero:  *  *	Free a page to the zerod-pages queue  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|vm_page_free_zero
parameter_list|(
name|m
parameter_list|)
name|vm_page_t
name|m
decl_stmt|;
block|{
name|vm_page_flag_set
argument_list|(
name|m
argument_list|,
name|PG_ZERO
argument_list|)
expr_stmt|;
name|vm_page_free_toq
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  *	vm_page_sleep_busy:  *  *	Wait until page is no longer PG_BUSY or (if also_m_busy is TRUE)  *	m->busy is zero.  Returns TRUE if it had to sleep ( including if   *	it almost had to sleep and made temporary spl*() mods), FALSE   *	otherwise.  *  *	This routine assumes that interrupts can only remove the busy  *	status from a page, not set the busy status or change it from  *	PG_BUSY to m->busy or vise versa (which would create a timing  *	window).  *  *	Note that being an inline, this code will be well optimized.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|vm_page_sleep_busy
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
name|flags
operator|&
name|PG_BUSY
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
name|int
name|s
init|=
name|splvm
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|m
operator|->
name|flags
operator|&
name|PG_BUSY
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
comment|/* 			 * Page is busy. Wait and retry. 			 */
name|vm_page_flag_set
argument_list|(
name|m
argument_list|,
name|PG_WANTED
operator||
name|PG_REFERENCED
argument_list|)
expr_stmt|;
name|tsleep
argument_list|(
name|m
argument_list|,
name|PVM
argument_list|,
name|msg
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|TRUE
operator|)
return|;
comment|/* not reached */
block|}
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  *	vm_page_dirty:  *  *	make page all dirty  */
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
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
name|KASSERT
argument_list|(
name|m
operator|->
name|queue
operator|-
name|m
operator|->
name|pc
operator|!=
name|PQ_CACHE
argument_list|,
operator|(
literal|"vm_page_dirty: page in cache!"
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|m
operator|->
name|dirty
operator|=
name|VM_PAGE_BITS_ALL
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  *	vm_page_undirty:  *  *	Set page to not be dirty.  Note: does not clear pmap modify bits   */
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
end_if

begin_function
specifier|static
name|__inline
name|vm_page_t
name|vm_page_list_find
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
block|{
name|vm_page_t
name|m
decl_stmt|;
if|#
directive|if
name|PQ_L2_SIZE
operator|>
literal|1
if|if
condition|(
name|prefer_zero
condition|)
block|{
name|m
operator|=
name|TAILQ_LAST
argument_list|(
operator|&
name|vm_page_queues
index|[
name|basequeue
operator|+
name|index
index|]
operator|.
name|pl
argument_list|,
name|pglist
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m
operator|=
name|TAILQ_FIRST
argument_list|(
operator|&
name|vm_page_queues
index|[
name|basequeue
operator|+
name|index
index|]
operator|.
name|pl
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|m
operator|==
name|NULL
condition|)
name|m
operator|=
name|_vm_page_list_find
argument_list|(
name|basequeue
argument_list|,
name|index
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|prefer_zero
condition|)
block|{
name|m
operator|=
name|TAILQ_LAST
argument_list|(
operator|&
name|vm_page_queues
index|[
name|basequeue
index|]
operator|.
name|pl
argument_list|,
name|pglist
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m
operator|=
name|TAILQ_FIRST
argument_list|(
operator|&
name|vm_page_queues
index|[
name|basequeue
index|]
operator|.
name|pl
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
return|return
operator|(
name|m
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

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

