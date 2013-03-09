begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  *  * Copyright (c) 2006-2009 VMware, Inc., Palo Alto, CA., USA  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the  * "Software"), to deal in the Software without restriction, including  * without limitation the rights to use, copy, modify, merge, publish,  * distribute, sub license, and/or sell copies of the Software, and to  * permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *  * The above copyright notice and this permission notice (including the  * next paragraph) shall be included in all copies or substantial portions  * of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS, AUTHORS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM,  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE  * USE OR OTHER DEALINGS IN THE SOFTWARE.  *  **************************************************************************/
end_comment

begin_comment
comment|/*  * Authors: Thomas Hellstrom<thellstrom-at-vmware-dot-com>  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TTM_EXECBUF_UTIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_TTM_EXECBUF_UTIL_H_
end_define

begin_include
include|#
directive|include
file|<dev/drm2/ttm/ttm_bo_api.h>
end_include

begin_comment
comment|/**  * struct ttm_validate_buffer  *  * @head:           list head for thread-private list.  * @bo:             refcounted buffer object pointer.  * @reserved:       Indicates whether @bo has been reserved for validation.  * @removed:        Indicates whether @bo has been removed from lru lists.  * @put_count:      Number of outstanding references on bo::list_kref.  * @old_sync_obj:   Pointer to a sync object about to be unreferenced  */
end_comment

begin_struct
struct|struct
name|ttm_validate_buffer
block|{
name|struct
name|list_head
name|head
decl_stmt|;
name|struct
name|ttm_buffer_object
modifier|*
name|bo
decl_stmt|;
name|bool
name|reserved
decl_stmt|;
name|bool
name|removed
decl_stmt|;
name|int
name|put_count
decl_stmt|;
name|void
modifier|*
name|old_sync_obj
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * function ttm_eu_backoff_reservation  *  * @list:     thread private list of ttm_validate_buffer structs.  *  * Undoes all buffer validation reservations for bos pointed to by  * the list entries.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ttm_eu_backoff_reservation
parameter_list|(
name|struct
name|list_head
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * function ttm_eu_reserve_buffers  *  * @list:    thread private list of ttm_validate_buffer structs.  *  * Tries to reserve bos pointed to by the list entries for validation.  * If the function returns 0, all buffers are marked as "unfenced",  * taken off the lru lists and are not synced for write CPU usage.  *  * If the function detects a deadlock due to multiple threads trying to  * reserve the same buffers in reverse order, all threads except one will  * back off and retry. This function may sleep while waiting for  * CPU write reservations to be cleared, and for other threads to  * unreserve their buffers.  *  * This function may return -ERESTART or -EAGAIN if the calling process  * receives a signal while waiting. In that case, no buffers on the list  * will be reserved upon return.  *  * Buffers reserved by this function should be unreserved by  * a call to either ttm_eu_backoff_reservation() or  * ttm_eu_fence_buffer_objects() when command submission is complete or  * has failed.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ttm_eu_reserve_buffers
parameter_list|(
name|struct
name|list_head
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * function ttm_eu_fence_buffer_objects.  *  * @list:        thread private list of ttm_validate_buffer structs.  * @sync_obj:    The new sync object for the buffers.  *  * This function should be called when command submission is complete, and  * it will add a new sync object to bos pointed to by entries on @list.  * It also unreserves all buffers, putting them on lru lists.  *  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ttm_eu_fence_buffer_objects
parameter_list|(
name|struct
name|list_head
modifier|*
name|list
parameter_list|,
name|void
modifier|*
name|sync_obj
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

