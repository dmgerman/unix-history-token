begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vm_object.h	8.3 (Berkeley) 1/12/94  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $Id: vm_object.h,v 1.23 1995/11/05 20:46:01 dyson Exp $  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_comment
comment|/* XXX for wakeup() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
name|TAILQ_ENTRY
argument_list|(
argument|vm_object
argument_list|)
name|cached_list
expr_stmt|;
comment|/* list of cached (persistent) objects */
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
name|u_short
name|flags
decl_stmt|;
comment|/* see below */
name|u_short
name|paging_in_progress
decl_stmt|;
comment|/* Paging (in or out) so don't collapse or destroy */
name|int
name|resident_page_count
decl_stmt|;
comment|/* number of resident pages */
name|vm_offset_t
name|paging_offset
decl_stmt|;
comment|/* Offset into paging space */
name|struct
name|vm_object
modifier|*
name|backing_object
decl_stmt|;
comment|/* object that I'm a shadow of */
name|vm_offset_t
name|backing_object_offset
decl_stmt|;
comment|/* Offset in backing object */
name|vm_offset_t
name|last_read
decl_stmt|;
comment|/* last read in object -- detect seq behavior */
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
name|vm_size_t
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
name|OBJ_CANPERSIST
value|0x0001
end_define

begin_comment
comment|/* allow to persist */
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|vm_object_cache_max
decl_stmt|;
end_decl_stmt

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
name|vm_object_cached_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of objects persisting */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vm_object_cached
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of cached list */
end_comment

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
name|long
name|vm_object_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count of all objects */
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
name|vm_object_cache_clear
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
name|vm_object_cache_trim
name|__P
argument_list|(
operator|(
name|void
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
name|vm_object_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
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
name|vm_offset_t
operator|,
name|vm_size_t
operator|,
name|vm_object_t
operator|*
operator|,
name|vm_offset_t
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
name|vm_object_deactivate_pages
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
name|vm_object_init
name|__P
argument_list|(
operator|(
name|vm_size_t
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
name|vm_offset_t
operator|,
name|vm_offset_t
operator|,
name|boolean_t
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
name|vm_offset_t
operator|,
name|vm_offset_t
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
name|vm_offset_t
operator|,
name|vm_offset_t
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
name|vm_offset_t
operator|,
name|vm_offset_t
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
name|vm_offset_t
operator|*
operator|,
name|vm_size_t
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

