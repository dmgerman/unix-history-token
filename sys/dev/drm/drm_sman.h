begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  *  * Copyright 2006 Tungsten Graphics, Inc., Bismarck, ND., USA.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the  * "Software"), to deal in the Software without restriction, including  * without limitation the rights to use, copy, modify, merge, publish,  * distribute, sub license, and/or sell copies of the Software, and to  * permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *  * The above copyright notice and this permission notice (including the  * next paragraph) shall be included in all copies or substantial portions  * of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS, AUTHORS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM,  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE  * USE OR OTHER DEALINGS IN THE SOFTWARE.  *  *  **************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Simple memory MANager interface that keeps track on allocate regions on a  * per "owner" basis. All regions associated with an "owner" can be released  * with a simple call. Typically if the "owner" exists. The owner is any  * "unsigned long" identifier. Can typically be a pointer to a file private  * struct or a context identifier.  *  * Authors:  * Thomas HellstrÃ¶m<thomas-at-tungstengraphics-dot-com>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DRM_SMAN_H
end_ifndef

begin_define
define|#
directive|define
name|DRM_SMAN_H
end_define

begin_include
include|#
directive|include
file|"dev/drm/drm_hashtab.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drm_linux_list.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drm_mm.h"
end_include

begin_comment
comment|/*  * A class that is an abstration of a simple memory allocator.  * The sman implementation provides a default such allocator  * using the drm_mm.c implementation. But the user can replace it.  * See the SiS implementation, which may use the SiS FB kernel module  * for memory management.  */
end_comment

begin_struct
struct|struct
name|drm_sman_mm
block|{
comment|/* private info. If allocated, needs to be destroyed by the destroy 	   function */
name|void
modifier|*
name|private
decl_stmt|;
comment|/* Allocate a memory block with given size and alignment. 	   Return an opaque reference to the memory block */
name|void
modifier|*
function_decl|(
modifier|*
name|allocate
function_decl|)
parameter_list|(
name|void
modifier|*
name|private
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|,
name|unsigned
name|alignment
parameter_list|)
function_decl|;
comment|/* Free a memory block. "ref" is the opaque reference that we got from 	   the "alloc" function */
name|void
function_decl|(
modifier|*
name|free
function_decl|)
parameter_list|(
name|void
modifier|*
name|private
parameter_list|,
name|void
modifier|*
name|ref
parameter_list|)
function_decl|;
comment|/* Free all resources associated with this allocator */
name|void
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|void
modifier|*
name|private
parameter_list|)
function_decl|;
comment|/* Return a memory offset from the opaque reference returned from the 	   "alloc" function */
name|unsigned
name|long
function_decl|(
modifier|*
name|offset
function_decl|)
parameter_list|(
name|void
modifier|*
name|private
parameter_list|,
name|void
modifier|*
name|ref
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_memblock_item
block|{
name|struct
name|list_head
name|owner_list
decl_stmt|;
name|struct
name|drm_hash_item
name|user_hash
decl_stmt|;
name|void
modifier|*
name|mm_info
decl_stmt|;
name|struct
name|drm_sman_mm
modifier|*
name|mm
decl_stmt|;
name|struct
name|drm_sman
modifier|*
name|sman
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_sman
block|{
name|struct
name|drm_sman_mm
modifier|*
name|mm
decl_stmt|;
name|int
name|num_managers
decl_stmt|;
name|struct
name|drm_open_hash
name|owner_hash_tab
decl_stmt|;
name|struct
name|drm_open_hash
name|user_hash_tab
decl_stmt|;
name|struct
name|list_head
name|owner_items
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Take down a memory manager. This function should only be called after a  * successful init and after a call to drm_sman_cleanup.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|drm_sman_takedown
parameter_list|(
name|struct
name|drm_sman
modifier|*
name|sman
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Allocate structures for a manager.  * num_managers are the number of memory pools to manage. (VRAM, AGP, ....)  * user_order is the log2 of the number of buckets in the user hash table.  *	    set this to approximately log2 of the max number of memory regions  *	    that will be allocated for _all_ pools together.  * owner_order is the log2 of the number of buckets in the owner hash table.  *	    set this to approximately log2 of  *	    the number of client file connections that will  *	    be using the manager.  *  */
end_comment

begin_function_decl
specifier|extern
name|int
name|drm_sman_init
parameter_list|(
name|struct
name|drm_sman
modifier|*
name|sman
parameter_list|,
name|unsigned
name|int
name|num_managers
parameter_list|,
name|unsigned
name|int
name|user_order
parameter_list|,
name|unsigned
name|int
name|owner_order
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialize a drm_mm.c allocator. Should be called only once for each  * manager unless a customized allogator is used.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|drm_sman_set_range
parameter_list|(
name|struct
name|drm_sman
modifier|*
name|sman
parameter_list|,
name|unsigned
name|int
name|manager
parameter_list|,
name|unsigned
name|long
name|start
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialize a customized allocator for one of the managers.  * (See the SiS module). The object pointed to by "allocator" is copied,  * so it can be destroyed after this call.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|drm_sman_set_manager
parameter_list|(
name|struct
name|drm_sman
modifier|*
name|sman
parameter_list|,
name|unsigned
name|int
name|mananger
parameter_list|,
name|struct
name|drm_sman_mm
modifier|*
name|allocator
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Allocate a memory block. Aligment is not implemented yet.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|drm_memblock_item
modifier|*
name|drm_sman_alloc
parameter_list|(
name|struct
name|drm_sman
modifier|*
name|sman
parameter_list|,
name|unsigned
name|int
name|manager
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|,
name|unsigned
name|alignment
parameter_list|,
name|unsigned
name|long
name|owner
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Free a memory block identified by its user hash key.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|drm_sman_free_key
parameter_list|(
name|struct
name|drm_sman
modifier|*
name|sman
parameter_list|,
name|unsigned
name|int
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * returns 1 iff there are no stale memory blocks associated with this owner.  * Typically called to determine if we need to idle the hardware and call  * drm_sman_owner_cleanup. If there are no stale memory blocks, it removes all  * resources associated with owner.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|drm_sman_owner_clean
parameter_list|(
name|struct
name|drm_sman
modifier|*
name|sman
parameter_list|,
name|unsigned
name|long
name|owner
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Frees all stale memory blocks associated with this owner. Note that this  * requires that the hardware is finished with all blocks, so the graphics engine  * should be idled before this call is made. This function also frees  * any resources associated with "owner" and should be called when owner  * is not going to be referenced anymore.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|drm_sman_owner_cleanup
parameter_list|(
name|struct
name|drm_sman
modifier|*
name|sman
parameter_list|,
name|unsigned
name|long
name|owner
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Frees all stale memory blocks associated with the memory manager.  * See idling above.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|drm_sman_cleanup
parameter_list|(
name|struct
name|drm_sman
modifier|*
name|sman
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

