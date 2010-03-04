begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vm_object.h	8.3 (Berkeley) 1/12/94  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *	Virtual memory object module definitions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VM_OBJECT_
end_ifndef

begin_define
define|#
directive|define
name|_VM_OBJECT_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_comment
comment|/*  *	Types defined:  *  *	vm_object_t		Virtual memory object.  *  * List of locks  *	(c)	const until freed  *  */
end_comment

begin_struct
struct|struct
name|vm_object
block|{
name|struct
name|mtx
name|mtx
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|vm_object
argument_list|)
name|object_list
expr_stmt|;
comment|/* list of all objects */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|vm_object
argument_list|)
name|shadow_head
expr_stmt|;
comment|/* objects that this is a shadow for */
name|LIST_ENTRY
argument_list|(
argument|vm_object
argument_list|)
name|shadow_list
expr_stmt|;
comment|/* chain of shadow objects */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|vm_page
argument_list|)
name|memq
expr_stmt|;
comment|/* list of resident pages */
name|vm_page_t
name|root
decl_stmt|;
comment|/* root of the resident page splay tree */
name|vm_pindex_t
name|size
decl_stmt|;
comment|/* Object size */
name|int
name|generation
decl_stmt|;
comment|/* generation ID */
name|int
name|ref_count
decl_stmt|;
comment|/* How many refs?? */
name|int
name|shadow_count
decl_stmt|;
comment|/* how many objects that this is a shadow for */
name|vm_memattr_t
name|memattr
decl_stmt|;
comment|/* default memory attribute for pages */
name|objtype_t
name|type
decl_stmt|;
comment|/* type of pager */
name|u_short
name|flags
decl_stmt|;
comment|/* see below */
name|u_short
name|pg_color
decl_stmt|;
comment|/* (c) color of first page in obj */
name|u_short
name|paging_in_progress
decl_stmt|;
comment|/* Paging (in or out) so don't collapse or destroy */
name|int
name|resident_page_count
decl_stmt|;
comment|/* number of resident pages */
name|struct
name|vm_object
modifier|*
name|backing_object
decl_stmt|;
comment|/* object that I'm a shadow of */
name|vm_ooffset_t
name|backing_object_offset
decl_stmt|;
comment|/* Offset in backing object */
name|TAILQ_ENTRY
argument_list|(
argument|vm_object
argument_list|)
name|pager_object_list
expr_stmt|;
comment|/* list of all objects of this pager type */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|vm_reserv
argument_list|)
name|rvq
expr_stmt|;
comment|/* list of reservations */
name|vm_page_t
name|cache
decl_stmt|;
comment|/* root of the cache page splay tree */
name|void
modifier|*
name|handle
decl_stmt|;
union|union
block|{
comment|/* 		 * VNode pager 		 * 		 *	vnp_size - current size of file 		 */
struct|struct
block|{
name|off_t
name|vnp_size
decl_stmt|;
block|}
name|vnp
struct|;
comment|/* 		 * Device pager 		 * 		 *	devp_pglist - list of allocated pages 		 */
struct|struct
block|{
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|vm_page
argument_list|)
name|devp_pglist
expr_stmt|;
block|}
name|devp
struct|;
comment|/* 		 * SG pager 		 * 		 *	sgp_pglist - list of allocated pages 		 */
struct|struct
block|{
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|vm_page
argument_list|)
name|sgp_pglist
expr_stmt|;
block|}
name|sgp
struct|;
comment|/* 		 * Swap pager 		 * 		 *	swp_bcount - number of swap 'swblock' metablocks, each 		 *		     contains up to 16 swapblk assignments. 		 *		     see vm/swap_pager.h 		 */
struct|struct
block|{
name|int
name|swp_bcount
decl_stmt|;
block|}
name|swp
struct|;
block|}
name|un_pager
union|;
name|struct
name|uidinfo
modifier|*
name|uip
decl_stmt|;
name|vm_ooffset_t
name|charge
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags  */
end_comment

begin_define
define|#
directive|define
name|OBJ_ACTIVE
value|0x0004
end_define

begin_comment
comment|/* active objects */
end_comment

begin_define
define|#
directive|define
name|OBJ_DEAD
value|0x0008
end_define

begin_comment
comment|/* dead objects (during rundown) */
end_comment

begin_define
define|#
directive|define
name|OBJ_NOSPLIT
value|0x0010
end_define

begin_comment
comment|/* dont split this object */
end_comment

begin_define
define|#
directive|define
name|OBJ_PIPWNT
value|0x0040
end_define

begin_comment
comment|/* paging in progress wanted */
end_comment

begin_define
define|#
directive|define
name|OBJ_MIGHTBEDIRTY
value|0x0100
end_define

begin_comment
comment|/* object might be dirty, only for vnode */
end_comment

begin_define
define|#
directive|define
name|OBJ_CLEANING
value|0x0200
end_define

begin_define
define|#
directive|define
name|OBJ_COLORED
value|0x1000
end_define

begin_comment
comment|/* pg_color is defined */
end_comment

begin_define
define|#
directive|define
name|OBJ_ONEMAPPING
value|0x2000
end_define

begin_comment
comment|/* One USE (a single, non-forked) mapping flag */
end_comment

begin_define
define|#
directive|define
name|OBJ_DISCONNECTWNT
value|0x4000
end_define

begin_comment
comment|/* disconnect from vnode wanted */
end_comment

begin_define
define|#
directive|define
name|IDX_TO_OFF
parameter_list|(
name|idx
parameter_list|)
value|(((vm_ooffset_t)(idx))<< PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|OFF_TO_IDX
parameter_list|(
name|off
parameter_list|)
value|((vm_pindex_t)(((vm_ooffset_t)(off))>> PAGE_SHIFT))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|OBJPC_SYNC
value|0x1
end_define

begin_comment
comment|/* sync I/O */
end_comment

begin_define
define|#
directive|define
name|OBJPC_INVAL
value|0x2
end_define

begin_comment
comment|/* invalidate */
end_comment

begin_define
define|#
directive|define
name|OBJPC_NOSYNC
value|0x4
end_define

begin_comment
comment|/* skip if PG_NOSYNC */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|object_q
argument_list|,
name|vm_object
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|object_q
name|vm_object_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of allocated objects */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|vm_object_list_mtx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lock for object list and count */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vm_object
name|kernel_object_store
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vm_object
name|kmem_object_store
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|kernel_object
value|(&kernel_object_store)
end_define

begin_define
define|#
directive|define
name|kmem_object
value|(&kmem_object_store)
end_define

begin_define
define|#
directive|define
name|VM_OBJECT_LOCK
parameter_list|(
name|object
parameter_list|)
value|mtx_lock(&(object)->mtx)
end_define

begin_define
define|#
directive|define
name|VM_OBJECT_LOCK_ASSERT
parameter_list|(
name|object
parameter_list|,
name|type
parameter_list|)
define|\
value|mtx_assert(&(object)->mtx, (type))
end_define

begin_define
define|#
directive|define
name|VM_OBJECT_LOCK_INIT
parameter_list|(
name|object
parameter_list|,
name|type
parameter_list|)
define|\
value|mtx_init(&(object)->mtx, "vm object", \ 					    (type), MTX_DEF | MTX_DUPOK)
end_define

begin_define
define|#
directive|define
name|VM_OBJECT_LOCKED
parameter_list|(
name|object
parameter_list|)
value|mtx_owned(&(object)->mtx)
end_define

begin_define
define|#
directive|define
name|VM_OBJECT_MTX
parameter_list|(
name|object
parameter_list|)
value|(&(object)->mtx)
end_define

begin_define
define|#
directive|define
name|VM_OBJECT_TRYLOCK
parameter_list|(
name|object
parameter_list|)
value|mtx_trylock(&(object)->mtx)
end_define

begin_define
define|#
directive|define
name|VM_OBJECT_UNLOCK
parameter_list|(
name|object
parameter_list|)
value|mtx_unlock(&(object)->mtx)
end_define

begin_comment
comment|/*  *	The object must be locked or thread private.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|vm_object_set_flag
parameter_list|(
name|vm_object_t
name|object
parameter_list|,
name|u_short
name|bits
parameter_list|)
block|{
name|object
operator|->
name|flags
operator||=
name|bits
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|vm_object_clear_flag
parameter_list|(
name|vm_object_t
name|object
parameter_list|,
name|u_short
name|bits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_pip_add
parameter_list|(
name|vm_object_t
name|object
parameter_list|,
name|short
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_pip_subtract
parameter_list|(
name|vm_object_t
name|object
parameter_list|,
name|short
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_pip_wakeup
parameter_list|(
name|vm_object_t
name|object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_pip_wakeupn
parameter_list|(
name|vm_object_t
name|object
parameter_list|,
name|short
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_pip_wait
parameter_list|(
name|vm_object_t
name|object
parameter_list|,
name|char
modifier|*
name|waitid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_object_t
name|vm_object_allocate
parameter_list|(
name|objtype_t
parameter_list|,
name|vm_pindex_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_vm_object_allocate
parameter_list|(
name|objtype_t
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|vm_object_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|vm_object_coalesce
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_ooffset_t
parameter_list|,
name|vm_size_t
parameter_list|,
name|vm_size_t
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_collapse
parameter_list|(
name|vm_object_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_deallocate
parameter_list|(
name|vm_object_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_destroy
parameter_list|(
name|vm_object_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_terminate
parameter_list|(
name|vm_object_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_set_writeable_dirty
parameter_list|(
name|vm_object_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_page_clean
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_page_remove
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|vm_object_populate
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|vm_pindex_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_reference
parameter_list|(
name|vm_object_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_reference_locked
parameter_list|(
name|vm_object_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_object_set_memattr
parameter_list|(
name|vm_object_t
name|object
parameter_list|,
name|vm_memattr_t
name|memattr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_shadow
parameter_list|(
name|vm_object_t
modifier|*
parameter_list|,
name|vm_ooffset_t
modifier|*
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_split
parameter_list|(
name|vm_map_entry_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_sync
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_ooffset_t
parameter_list|,
name|vm_size_t
parameter_list|,
name|boolean_t
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_madvise
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* _VM_OBJECT_ */
end_comment

end_unit

