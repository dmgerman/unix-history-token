begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vm_object.h	8.3 (Berkeley) 1/12/94  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $Id: vm_object.h,v 1.46 1998/02/25 03:55:52 dyson Exp $  */
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

begin_enum
enum|enum
name|obj_type
block|{
name|OBJT_DEFAULT
block|,
name|OBJT_SWAP
block|,
name|OBJT_VNODE
block|,
name|OBJT_DEVICE
block|,
name|OBJT_DEAD
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|obj_type
name|objtype_t
typedef|;
end_typedef

begin_comment
comment|/*  *	Types defined:  *  *	vm_object_t		Virtual memory object.  */
end_comment

begin_struct
struct|struct
name|vm_object
block|{
name|TAILQ_ENTRY
argument_list|(
argument|vm_object
argument_list|)
name|object_list
expr_stmt|;
comment|/* list of all objects */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|vm_object
argument_list|)
name|shadow_head
expr_stmt|;
comment|/* objects that this is a shadow for */
name|TAILQ_ENTRY
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
name|int
name|generation
decl_stmt|;
comment|/* generation ID */
name|objtype_t
name|type
decl_stmt|;
comment|/* type of pager */
name|vm_size_t
name|size
decl_stmt|;
comment|/* Object size */
name|int
name|ref_count
decl_stmt|;
comment|/* How many refs?? */
name|int
name|shadow_count
decl_stmt|;
comment|/* how many objects that this is a shadow for */
name|int
name|pg_color
decl_stmt|;
comment|/* color of first page in obj */
name|u_short
name|flags
decl_stmt|;
comment|/* see below */
name|u_short
name|paging_in_progress
decl_stmt|;
comment|/* Paging (in or out) so don't collapse or destroy */
name|u_short
name|behavior
decl_stmt|;
comment|/* see below */
name|int
name|resident_page_count
decl_stmt|;
comment|/* number of resident pages */
name|int
name|cache_count
decl_stmt|;
comment|/* number of cached pages */
name|int
name|wire_count
decl_stmt|;
comment|/* number of wired pages */
name|vm_ooffset_t
name|paging_offset
decl_stmt|;
comment|/* Offset into paging space */
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
name|vm_offset_t
name|last_read
decl_stmt|;
comment|/* last read in object -- detect seq behavior */
name|vm_page_t
name|page_hint
decl_stmt|;
comment|/* hint for last looked-up or allocated page */
name|TAILQ_ENTRY
argument_list|(
argument|vm_object
argument_list|)
name|pager_object_list
expr_stmt|;
comment|/* list of all objects of this pager type */
name|void
modifier|*
name|handle
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|off_t
name|vnp_size
decl_stmt|;
comment|/* Current size of file */
block|}
name|vnp
struct|;
struct|struct
block|{
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|vm_page
argument_list|)
name|devp_pglist
expr_stmt|;
comment|/* list of pages allocated */
block|}
name|devp
struct|;
struct|struct
block|{
name|int
name|swp_nblocks
decl_stmt|;
name|int
name|swp_allocsize
decl_stmt|;
name|struct
name|swblock
modifier|*
name|swp_blocks
decl_stmt|;
name|short
name|swp_poip
decl_stmt|;
block|}
name|swp
struct|;
block|}
name|un_pager
union|;
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
name|OBJ_PIPWNT
value|0x0040
end_define

begin_comment
comment|/* paging in progress wanted */
end_comment

begin_define
define|#
directive|define
name|OBJ_WRITEABLE
value|0x0080
end_define

begin_comment
comment|/* object has been made writable */
end_comment

begin_define
define|#
directive|define
name|OBJ_MIGHTBEDIRTY
value|0x0100
end_define

begin_comment
comment|/* object might be dirty */
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
name|OBJ_OPT
value|0x1000
end_define

begin_comment
comment|/* I/O optimization */
end_comment

begin_define
define|#
directive|define
name|OBJ_NORMAL
value|0x0
end_define

begin_comment
comment|/* default behavior */
end_comment

begin_define
define|#
directive|define
name|OBJ_SEQUENTIAL
value|0x1
end_define

begin_comment
comment|/* expect sequential accesses */
end_comment

begin_define
define|#
directive|define
name|OBJ_RANDOM
value|0x2
end_define

begin_comment
comment|/* expect random accesses */
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
name|KERNEL
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

begin_comment
comment|/* lock for object list and count */
end_comment

begin_decl_stmt
specifier|extern
name|vm_object_t
name|kernel_object
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the single kernel object */
end_comment

begin_decl_stmt
specifier|extern
name|vm_object_t
name|kmem_object
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function
specifier|static
name|__inline
name|void
name|vm_object_pip_wakeup
parameter_list|(
name|vm_object_t
name|object
parameter_list|)
block|{
name|object
operator|->
name|paging_in_progress
operator|--
expr_stmt|;
if|if
condition|(
operator|(
name|object
operator|->
name|flags
operator|&
name|OBJ_PIPWNT
operator|)
operator|&&
name|object
operator|->
name|paging_in_progress
operator|==
literal|0
condition|)
block|{
name|object
operator|->
name|flags
operator|&=
operator|~
name|OBJ_PIPWNT
expr_stmt|;
name|wakeup
argument_list|(
name|object
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|vm_object_pip_sleep
parameter_list|(
name|vm_object_t
name|object
parameter_list|,
name|char
modifier|*
name|waitid
parameter_list|)
block|{
name|int
name|s
decl_stmt|;
if|if
condition|(
name|object
operator|->
name|paging_in_progress
condition|)
block|{
name|s
operator|=
name|splvm
argument_list|()
expr_stmt|;
if|if
condition|(
name|object
operator|->
name|paging_in_progress
condition|)
block|{
name|object
operator|->
name|flags
operator||=
name|OBJ_PIPWNT
expr_stmt|;
name|tsleep
argument_list|(
name|object
argument_list|,
name|PVM
argument_list|,
name|waitid
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
block|}
block|}
end_function

begin_function
specifier|static
name|__inline
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
block|{
while|while
condition|(
name|object
operator|->
name|paging_in_progress
condition|)
name|vm_object_pip_sleep
argument_list|(
name|object
argument_list|,
name|waitid
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|vm_object_t
name|vm_object_allocate
name|__P
argument_list|(
operator|(
name|objtype_t
operator|,
name|vm_size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_vm_object_allocate
name|__P
argument_list|(
operator|(
name|objtype_t
operator|,
name|vm_size_t
operator|,
name|vm_object_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|vm_object_coalesce
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|,
name|vm_pindex_t
operator|,
name|vm_size_t
operator|,
name|vm_size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_object_collapse
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_object_copy
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|,
name|vm_pindex_t
operator|,
name|vm_object_t
operator|*
operator|,
name|vm_pindex_t
operator|*
operator|,
name|boolean_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_object_deallocate
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_object_terminate
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_object_vndeallocate
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_object_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_object_page_clean
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|,
name|vm_pindex_t
operator|,
name|vm_pindex_t
operator|,
name|boolean_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_object_page_remove
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|,
name|vm_pindex_t
operator|,
name|vm_pindex_t
operator|,
name|boolean_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_object_pmap_copy
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|,
name|vm_pindex_t
operator|,
name|vm_pindex_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_object_pmap_copy_1
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|,
name|vm_pindex_t
operator|,
name|vm_pindex_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_object_pmap_remove
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|,
name|vm_pindex_t
operator|,
name|vm_pindex_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_object_reference
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_object_shadow
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|*
operator|,
name|vm_ooffset_t
operator|*
operator|,
name|vm_size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vm_object_madvise
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|,
name|vm_pindex_t
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
name|vm_object_init2
name|__P
argument_list|(
operator|(
name|void
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
comment|/* _VM_OBJECT_ */
end_comment

end_unit

