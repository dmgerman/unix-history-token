begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  *  * Copyright 2010 Pauli Nieminen.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the  * "Software"), to deal in the Software without restriction, including  * without limitation the rights to use, copy, modify, merge, publish,  * distribute, sub license, and/or sell copies of the Software, and to  * permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *  * The above copyright notice and this permission notice (including the  * next paragraph) shall be included in all copies or substantial portions  * of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS, AUTHORS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM,  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE  * USE OR OTHER DEALINGS IN THE SOFTWARE.  *  *  **************************************************************************/
end_comment

begin_comment
comment|/*  * Multipart buffer for coping data which is larger than the page size.  *  * Authors:  * Pauli Nieminen<suokkos-at-gmail-dot-com>  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|_DRM_BUFFER_H_
end_ifndef

begin_define
define|#
directive|define
name|_DRM_BUFFER_H_
end_define

begin_include
include|#
directive|include
file|<dev/drm2/drmP.h>
end_include

begin_struct
struct|struct
name|drm_buffer
block|{
name|int
name|iterator
decl_stmt|;
name|int
name|size
decl_stmt|;
name|char
modifier|*
name|data
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Return the index of page that buffer is currently pointing at.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|drm_buffer_page
parameter_list|(
name|struct
name|drm_buffer
modifier|*
name|buf
parameter_list|)
block|{
return|return
name|buf
operator|->
name|iterator
operator|/
name|PAGE_SIZE
return|;
block|}
end_function

begin_comment
comment|/**  * Return the index of the current byte in the page  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|drm_buffer_index
parameter_list|(
name|struct
name|drm_buffer
modifier|*
name|buf
parameter_list|)
block|{
return|return
name|buf
operator|->
name|iterator
operator|&
operator|(
name|PAGE_SIZE
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Return number of bytes that is left to process  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|drm_buffer_unprocessed
parameter_list|(
name|struct
name|drm_buffer
modifier|*
name|buf
parameter_list|)
block|{
return|return
name|buf
operator|->
name|size
operator|-
name|buf
operator|->
name|iterator
return|;
block|}
end_function

begin_comment
comment|/**  * Advance the buffer iterator number of bytes that is given.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|drm_buffer_advance
parameter_list|(
name|struct
name|drm_buffer
modifier|*
name|buf
parameter_list|,
name|int
name|bytes
parameter_list|)
block|{
name|buf
operator|->
name|iterator
operator|+=
name|bytes
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * Allocate the drm buffer object.  *  *   buf: A pointer to a pointer where the object is stored.  *   size: The number of bytes to allocate.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|drm_buffer_alloc
parameter_list|(
name|struct
name|drm_buffer
modifier|*
modifier|*
name|buf
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Copy the user data to the begin of the buffer and reset the processing  * iterator.  *  *   user_data: A pointer the data that is copied to the buffer.  *   size: The Number of bytes to copy.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|drm_buffer_copy_from_user
parameter_list|(
name|struct
name|drm_buffer
modifier|*
name|buf
parameter_list|,
name|void
name|__user
modifier|*
name|user_data
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Free the drm buffer object  */
end_comment

begin_function_decl
specifier|extern
name|void
name|drm_buffer_free
parameter_list|(
name|struct
name|drm_buffer
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Read an object from buffer that may be split to multiple parts. If object  * is not split function just returns the pointer to object in buffer. But in  * case of split object data is copied to given stack object that is suplied  * by caller.  *  * The processing location of the buffer is also advanced to the next byte  * after the object.  *  *   objsize: The size of the objet in bytes.  *   stack_obj: A pointer to a memory location where object can be copied.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|drm_buffer_read_object
parameter_list|(
name|struct
name|drm_buffer
modifier|*
name|buf
parameter_list|,
name|int
name|objsize
parameter_list|,
name|void
modifier|*
name|stack_obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Returns the pointer to the dword which is offset number of elements from the  * current processing location.  *  * Caller must make sure that dword is not split in the buffer. This  * requirement is easily met if all the sizes of objects in buffer are  * multiples of dword and PAGE_SIZE is multiple dword.  *  * Call to this function doesn't change the processing location.  *  *   offset: The index of the dword relative to the internat iterator.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|drm_buffer_pointer_to_dword
parameter_list|(
name|struct
name|drm_buffer
modifier|*
name|buffer
parameter_list|,
name|int
name|offset
parameter_list|)
block|{
name|int
name|iter
init|=
name|buffer
operator|->
name|iterator
operator|+
name|offset
operator|*
literal|4
decl_stmt|;
return|return
operator|&
name|buffer
operator|->
name|data
index|[
name|iter
operator|/
name|PAGE_SIZE
index|]
index|[
name|iter
operator|&
operator|(
name|PAGE_SIZE
operator|-
literal|1
operator|)
index|]
return|;
block|}
end_function

begin_comment
comment|/**  * Returns the pointer to the dword which is offset number of elements from  * the current processing location.  *  * Call to this function doesn't change the processing location.  *  *   offset: The index of the byte relative to the internat iterator.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|drm_buffer_pointer_to_byte
parameter_list|(
name|struct
name|drm_buffer
modifier|*
name|buffer
parameter_list|,
name|int
name|offset
parameter_list|)
block|{
name|int
name|iter
init|=
name|buffer
operator|->
name|iterator
operator|+
name|offset
decl_stmt|;
return|return
operator|&
name|buffer
operator|->
name|data
index|[
name|iter
operator|/
name|PAGE_SIZE
index|]
index|[
name|iter
operator|&
operator|(
name|PAGE_SIZE
operator|-
literal|1
operator|)
index|]
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

