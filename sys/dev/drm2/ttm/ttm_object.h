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

begin_comment
comment|/** @file ttm_object.h  *  * Base- and reference object implementation for the various  * ttm objects. Implements reference counting, minimal security checks  * and release on file close.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TTM_OBJECT_H_
end_ifndef

begin_define
define|#
directive|define
name|_TTM_OBJECT_H_
end_define

begin_include
include|#
directive|include
file|<dev/drm2/drm_hashtab.h>
end_include

begin_include
include|#
directive|include
file|<dev/drm2/ttm/ttm_memory.h>
end_include

begin_comment
comment|/**  * enum ttm_ref_type  *  * Describes what type of reference a ref object holds.  *  * TTM_REF_USAGE is a simple refcount on a base object.  *  * TTM_REF_SYNCCPU_READ is a SYNCCPU_READ reference on a  * buffer object.  *  * TTM_REF_SYNCCPU_WRITE is a SYNCCPU_WRITE reference on a  * buffer object.  *  */
end_comment

begin_enum
enum|enum
name|ttm_ref_type
block|{
name|TTM_REF_USAGE
block|,
name|TTM_REF_SYNCCPU_READ
block|,
name|TTM_REF_SYNCCPU_WRITE
block|,
name|TTM_REF_NUM
block|}
enum|;
end_enum

begin_comment
comment|/**  * enum ttm_object_type  *  * One entry per ttm object type.  * Device-specific types should use the  * ttm_driver_typex types.  */
end_comment

begin_enum
enum|enum
name|ttm_object_type
block|{
name|ttm_fence_type
block|,
name|ttm_buffer_type
block|,
name|ttm_lock_type
block|,
name|ttm_driver_type0
init|=
literal|256
block|,
name|ttm_driver_type1
block|,
name|ttm_driver_type2
block|,
name|ttm_driver_type3
block|,
name|ttm_driver_type4
block|,
name|ttm_driver_type5
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|ttm_object_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ttm_object_device
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * struct ttm_base_object  *  * @hash: hash entry for the per-device object hash.  * @type: derived type this object is base class for.  * @shareable: Other ttm_object_files can access this object.  *  * @tfile: Pointer to ttm_object_file of the creator.  * NULL if the object was not created by a user request.  * (kernel object).  *  * @refcount: Number of references to this object, not  * including the hash entry. A reference to a base object can  * only be held by a ref object.  *  * @refcount_release: A function to be called when there are  * no more references to this object. This function should  * destroy the object (or make sure destruction eventually happens),  * and when it is called, the object has  * already been taken out of the per-device hash. The parameter  * "base" should be set to NULL by the function.  *  * @ref_obj_release: A function to be called when a reference object  * with another ttm_ref_type than TTM_REF_USAGE is deleted.  * This function may, for example, release a lock held by a user-space  * process.  *  * This struct is intended to be used as a base struct for objects that  * are visible to user-space. It provides a global name, race-safe  * access and refcounting, minimal access contol and hooks for unref actions.  */
end_comment

begin_struct
struct|struct
name|ttm_base_object
block|{
comment|/* struct rcu_head rhead;XXXKIB */
name|struct
name|drm_hash_item
name|hash
decl_stmt|;
name|enum
name|ttm_object_type
name|object_type
decl_stmt|;
name|bool
name|shareable
decl_stmt|;
name|struct
name|ttm_object_file
modifier|*
name|tfile
decl_stmt|;
name|u_int
name|refcount
decl_stmt|;
name|void
function_decl|(
modifier|*
name|refcount_release
function_decl|)
parameter_list|(
name|struct
name|ttm_base_object
modifier|*
modifier|*
name|base
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ref_obj_release
function_decl|)
parameter_list|(
name|struct
name|ttm_base_object
modifier|*
name|base
parameter_list|,
name|enum
name|ttm_ref_type
name|ref_type
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * ttm_base_object_init  *  * @tfile: Pointer to a struct ttm_object_file.  * @base: The struct ttm_base_object to initialize.  * @shareable: This object is shareable with other applcations.  * (different @tfile pointers.)  * @type: The object type.  * @refcount_release: See the struct ttm_base_object description.  * @ref_obj_release: See the struct ttm_base_object description.  *  * Initializes a struct ttm_base_object.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ttm_base_object_init
parameter_list|(
name|struct
name|ttm_object_file
modifier|*
name|tfile
parameter_list|,
name|struct
name|ttm_base_object
modifier|*
name|base
parameter_list|,
name|bool
name|shareable
parameter_list|,
name|enum
name|ttm_object_type
name|type
parameter_list|,
name|void
function_decl|(
modifier|*
name|refcount_release
function_decl|)
parameter_list|(
name|struct
name|ttm_base_object
modifier|*
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|ref_obj_release
function_decl|)
parameter_list|(
name|struct
name|ttm_base_object
modifier|*
parameter_list|,
name|enum
name|ttm_ref_type
name|ref_type
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_base_object_lookup  *  * @tfile: Pointer to a struct ttm_object_file.  * @key: Hash key  *  * Looks up a struct ttm_base_object with the key @key.  * Also verifies that the object is visible to the application, by  * comparing the @tfile argument and checking the object shareable flag.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|ttm_base_object
modifier|*
name|ttm_base_object_lookup
parameter_list|(
name|struct
name|ttm_object_file
modifier|*
name|tfile
parameter_list|,
name|uint32_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_base_object_unref  *  * @p_base: Pointer to a pointer referencing a struct ttm_base_object.  *  * Decrements the base object refcount and clears the pointer pointed to by  * p_base.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ttm_base_object_unref
parameter_list|(
name|struct
name|ttm_base_object
modifier|*
modifier|*
name|p_base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_ref_object_add.  *  * @tfile: A struct ttm_object_file representing the application owning the  * ref_object.  * @base: The base object to reference.  * @ref_type: The type of reference.  * @existed: Upon completion, indicates that an identical reference object  * already existed, and the refcount was upped on that object instead.  *  * Adding a ref object to a base object is basically like referencing the  * base object, but a user-space application holds the reference. When the  * file corresponding to @tfile is closed, all its reference objects are  * deleted. A reference object can have different types depending on what  * it's intended for. It can be refcounting to prevent object destruction,  * When user-space takes a lock, it can add a ref object to that lock to  * make sure the lock is released if the application dies. A ref object  * will hold a single reference on a base object.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ttm_ref_object_add
parameter_list|(
name|struct
name|ttm_object_file
modifier|*
name|tfile
parameter_list|,
name|struct
name|ttm_base_object
modifier|*
name|base
parameter_list|,
name|enum
name|ttm_ref_type
name|ref_type
parameter_list|,
name|bool
modifier|*
name|existed
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_ref_object_base_unref  *  * @key: Key representing the base object.  * @ref_type: Ref type of the ref object to be dereferenced.  *  * Unreference a ref object with type @ref_type  * on the base object identified by @key. If there are no duplicate  * references, the ref object will be destroyed and the base object  * will be unreferenced.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ttm_ref_object_base_unref
parameter_list|(
name|struct
name|ttm_object_file
modifier|*
name|tfile
parameter_list|,
name|unsigned
name|long
name|key
parameter_list|,
name|enum
name|ttm_ref_type
name|ref_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_object_file_init - initialize a struct ttm_object file  *  * @tdev: A struct ttm_object device this file is initialized on.  * @hash_order: Order of the hash table used to hold the reference objects.  *  * This is typically called by the file_ops::open function.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|ttm_object_file
modifier|*
name|ttm_object_file_init
parameter_list|(
name|struct
name|ttm_object_device
modifier|*
name|tdev
parameter_list|,
name|unsigned
name|int
name|hash_order
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_object_file_release - release data held by a ttm_object_file  *  * @p_tfile: Pointer to pointer to the ttm_object_file object to release.  * *p_tfile will be set to NULL by this function.  *  * Releases all data associated by a ttm_object_file.  * Typically called from file_ops::release. The caller must  * ensure that there are no concurrent users of tfile.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ttm_object_file_release
parameter_list|(
name|struct
name|ttm_object_file
modifier|*
modifier|*
name|p_tfile
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_object device init - initialize a struct ttm_object_device  *  * @hash_order: Order of hash table used to hash the base objects.  *  * This function is typically called on device initialization to prepare  * data structures needed for ttm base and ref objects.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|ttm_object_device
modifier|*
name|ttm_object_device_init
parameter_list|(
name|struct
name|ttm_mem_global
modifier|*
name|mem_glob
parameter_list|,
name|unsigned
name|int
name|hash_order
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_object_device_release - release data held by a ttm_object_device  *  * @p_tdev: Pointer to pointer to the ttm_object_device object to release.  * *p_tdev will be set to NULL by this function.  *  * Releases all data associated by a ttm_object_device.  * Typically called from driver::unload before the destruction of the  * device private data structure.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ttm_object_device_release
parameter_list|(
name|struct
name|ttm_object_device
modifier|*
modifier|*
name|p_tdev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

