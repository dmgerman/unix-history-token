begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * %sccs.include.redist.c%  *  *	@(#)vm_object.h	7.4 (Berkeley) %G%  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
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
file|<vm/vm_pager.h>
end_include

begin_comment
comment|/*  *	Types defined:  *  *	vm_object_t		Virtual memory object.  */
end_comment

begin_struct
struct|struct
name|vm_object
block|{
name|queue_chain_t
name|memq
decl_stmt|;
comment|/* Resident memory */
name|queue_chain_t
name|object_list
decl_stmt|;
comment|/* list of all objects */
name|u_short
name|flags
decl_stmt|;
comment|/* see below */
name|u_short
name|paging_in_progress
decl_stmt|;
comment|/* Paging (in or out) so 						    don't collapse or destroy */
name|simple_lock_data_t
name|Lock
decl_stmt|;
comment|/* Synchronization */
name|int
name|LockHolder
decl_stmt|;
name|int
name|ref_count
decl_stmt|;
comment|/* How many refs?? */
name|vm_size_t
name|size
decl_stmt|;
comment|/* Object size */
name|int
name|resident_page_count
decl_stmt|;
comment|/* number of resident pages */
name|struct
name|vm_object
modifier|*
name|copy
decl_stmt|;
comment|/* Object that holds copies of 						   my changed pages */
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
name|queue_chain_t
name|cached_list
decl_stmt|;
comment|/* for persistence */
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

begin_typedef
typedef|typedef
name|struct
name|vm_object
modifier|*
name|vm_object_t
typedef|;
end_typedef

begin_struct
struct|struct
name|vm_object_hash_entry
block|{
name|queue_chain_t
name|hash_links
decl_stmt|;
comment|/* hash chain links */
name|vm_object_t
name|object
decl_stmt|;
comment|/* object we represent */
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
name|queue_head_t
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
name|queue_head_t
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
endif|KERNEL
end_endif

begin_comment
comment|/*  *	Declare procedures that operate on VM objects.  */
end_comment

begin_function_decl
name|void
name|vm_object_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_terminate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|vm_object_t
name|vm_object_allocate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_reference
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_deallocate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_pmap_copy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_pmap_remove
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_page_remove
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_shadow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_copy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_collapse
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|vm_object_t
name|vm_object_lookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_enter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_setpager
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|vm_object_cache
parameter_list|(
name|pager
parameter_list|)
value|pager_cache(vm_object_lookup(pager),TRUE)
end_define

begin_define
define|#
directive|define
name|vm_object_uncache
parameter_list|(
name|pager
parameter_list|)
value|pager_cache(vm_object_lookup(pager),FALSE)
end_define

begin_function_decl
name|void
name|vm_object_cache_clear
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_object_print
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|VM_OBJECT_DEBUG
end_if

begin_define
define|#
directive|define
name|vm_object_lock_init
parameter_list|(
name|object
parameter_list|)
value|{ simple_lock_init(&(object)->Lock); (object)->LockHolder = 0; }
end_define

begin_define
define|#
directive|define
name|vm_object_lock
parameter_list|(
name|object
parameter_list|)
value|{ simple_lock(&(object)->Lock); (object)->LockHolder = (int) current_thread(); }
end_define

begin_define
define|#
directive|define
name|vm_object_unlock
parameter_list|(
name|object
parameter_list|)
value|{ (object)->LockHolder = 0; simple_unlock(&(object)->Lock); }
end_define

begin_define
define|#
directive|define
name|vm_object_lock_try
parameter_list|(
name|object
parameter_list|)
value|(simple_lock_try(&(object)->Lock) ? ( ((object)->LockHolder = (int) current_thread()) , TRUE) : FALSE)
end_define

begin_define
define|#
directive|define
name|vm_object_sleep
parameter_list|(
name|event
parameter_list|,
name|object
parameter_list|,
name|interruptible
parameter_list|)
define|\
value|{ (object)->LockHolder = 0; thread_sleep((event),&(object)->Lock, (interruptible)); }
end_define

begin_else
else|#
directive|else
else|VM_OBJECT_DEBUG
end_else

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

begin_define
define|#
directive|define
name|vm_object_sleep
parameter_list|(
name|event
parameter_list|,
name|object
parameter_list|,
name|interruptible
parameter_list|)
define|\
value|thread_sleep((event),&(object)->Lock, (interruptible))
end_define

begin_endif
endif|#
directive|endif
endif|VM_OBJECT_DEBUG
end_endif

begin_endif
endif|#
directive|endif
endif|_VM_OBJECT_
end_endif

end_unit

