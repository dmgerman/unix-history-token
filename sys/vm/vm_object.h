begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vm_object.h	8.3 (Berkeley) 1/12/94  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_pager.h>
end_include

begin_comment
comment|/*  *	Types defined:  *  *	vm_object_t		Virtual memory object.  */
end_comment

begin_struct
struct|struct
name|vm_object
block|{
name|struct
name|pglist
name|memq
decl_stmt|;
comment|/* Resident memory */
name|TAILQ_HEAD
argument_list|(
argument|rslist
argument_list|,
argument|vm_object
argument_list|)
name|reverse_shadow_head
expr_stmt|;
comment|/* objects that this is a shadow for */
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
name|reverse_shadow_list
expr_stmt|;
comment|/* chain of objects that are shadowed */
name|TAILQ_ENTRY
argument_list|(
argument|vm_object
argument_list|)
name|cached_list
expr_stmt|;
comment|/* for persistence */
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
name|vm_pager_t
name|pager
decl_stmt|;
comment|/* Where to get data */
name|vm_offset_t
name|paging_offset
decl_stmt|;
comment|/* Offset into paging space */
name|struct
name|vm_object
modifier|*
name|shadow
decl_stmt|;
comment|/* My shadow */
name|vm_offset_t
name|shadow_offset
decl_stmt|;
comment|/* Offset in shadow */
name|struct
name|vm_object
modifier|*
name|copy
decl_stmt|;
comment|/* Object that holds copies of my changed pages */
name|vm_offset_t
name|last_read
decl_stmt|;
comment|/* last read in object -- detect seq behavior */
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
name|OBJ_INTERNAL
value|0x0002
end_define

begin_comment
comment|/* internally created object */
end_comment

begin_define
define|#
directive|define
name|OBJ_ACTIVE
value|0x0004
end_define

begin_comment
comment|/* used to mark active objects */
end_comment

begin_define
define|#
directive|define
name|OBJ_DEAD
value|0x0008
end_define

begin_comment
comment|/* used to mark dead objects during rundown */
end_comment

begin_define
define|#
directive|define
name|OBJ_ILOCKED
value|0x0010
end_define

begin_comment
comment|/* lock from modification */
end_comment

begin_define
define|#
directive|define
name|OBJ_ILOCKWT
value|0x0020
end_define

begin_comment
comment|/* wait for lock from modification */
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
comment|/* object has been made writeable */
end_comment

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|vm_object_hash_head
argument_list|,
name|vm_object_hash_entry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|vm_object_hash_entry
block|{
name|LIST_ENTRY
argument_list|(
argument|vm_object_hash_entry
argument_list|)
name|hash_links
expr_stmt|;
comment|/* hash chain links */
name|vm_object_t
name|object
decl_stmt|;
comment|/* object represened */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vm_object_hash_entry
modifier|*
name|vm_object_hash_entry_t
typedef|;
end_typedef

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
name|struct
name|object_q
name|vm_object_cached_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of objects persisting */
end_comment

begin_decl_stmt
name|int
name|vm_object_cached
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of cached list */
end_comment

begin_decl_stmt
name|simple_lock_data_t
name|vm_cache_lock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lock for object cache */
end_comment

begin_decl_stmt
name|struct
name|object_q
name|vm_object_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of allocated objects */
end_comment

begin_decl_stmt
name|long
name|vm_object_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count of all objects */
end_comment

begin_decl_stmt
name|simple_lock_data_t
name|vm_object_list_lock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lock for object list and count */
end_comment

begin_decl_stmt
name|vm_object_t
name|kernel_object
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the single kernel object */
end_comment

begin_decl_stmt
name|vm_object_t
name|kmem_object
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|vm_object_cache_lock
parameter_list|()
value|simple_lock(&vm_cache_lock)
end_define

begin_define
define|#
directive|define
name|vm_object_cache_unlock
parameter_list|()
value|simple_unlock(&vm_cache_lock)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_define
define|#
directive|define
name|vm_object_lock_init
parameter_list|(
name|object
parameter_list|)
value|simple_lock_init(&(object)->Lock)
end_define

begin_define
define|#
directive|define
name|vm_object_lock
parameter_list|(
name|object
parameter_list|)
value|simple_lock(&(object)->Lock)
end_define

begin_define
define|#
directive|define
name|vm_object_unlock
parameter_list|(
name|object
parameter_list|)
value|simple_unlock(&(object)->Lock)
end_define

begin_define
define|#
directive|define
name|vm_object_lock_try
parameter_list|(
name|object
parameter_list|)
value|simple_lock_try(&(object)->Lock)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|vm_object_enter
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|,
name|vm_pager_t
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
name|vm_object_t
name|vm_object_lookup
name|__P
argument_list|(
operator|(
name|vm_pager_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_vm_object_page_clean
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
name|vm_object_print
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|,
name|boolean_t
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
name|vm_object_remove
name|__P
argument_list|(
operator|(
name|vm_pager_t
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

