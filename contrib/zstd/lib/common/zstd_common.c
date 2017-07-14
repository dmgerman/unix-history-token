begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2016-present, Yann Collet, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under the BSD-style license found in the  * LICENSE file in the root directory of this source tree. An additional grant  * of patent rights can be found in the PATENTS file in the same directory.  */
end_comment

begin_comment
comment|/*-************************************* *  Dependencies ***************************************/
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* malloc, calloc, free */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* memset */
end_comment

begin_include
include|#
directive|include
file|"error_private.h"
end_include

begin_define
define|#
directive|define
name|ZSTD_STATIC_LINKING_ONLY
end_define

begin_include
include|#
directive|include
file|"zstd.h"
end_include

begin_comment
comment|/*-**************************************** *  Version ******************************************/
end_comment

begin_function
name|unsigned
name|ZSTD_versionNumber
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|ZSTD_VERSION_NUMBER
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|ZSTD_versionString
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|ZSTD_VERSION_STRING
return|;
block|}
end_function

begin_comment
comment|/*-**************************************** *  ZSTD Error Management ******************************************/
end_comment

begin_comment
comment|/*! ZSTD_isError() : *   tells if a return value is an error code */
end_comment

begin_function
name|unsigned
name|ZSTD_isError
parameter_list|(
name|size_t
name|code
parameter_list|)
block|{
return|return
name|ERR_isError
argument_list|(
name|code
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*! ZSTD_getErrorName() : *   provides error code string from function result (useful for debugging) */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|ZSTD_getErrorName
parameter_list|(
name|size_t
name|code
parameter_list|)
block|{
return|return
name|ERR_getErrorName
argument_list|(
name|code
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*! ZSTD_getError() : *   convert a `size_t` function result into a proper ZSTD_errorCode enum */
end_comment

begin_function
name|ZSTD_ErrorCode
name|ZSTD_getErrorCode
parameter_list|(
name|size_t
name|code
parameter_list|)
block|{
return|return
name|ERR_getErrorCode
argument_list|(
name|code
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*! ZSTD_getErrorString() : *   provides error code string from enum */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|ZSTD_getErrorString
parameter_list|(
name|ZSTD_ErrorCode
name|code
parameter_list|)
block|{
return|return
name|ERR_getErrorString
argument_list|(
name|code
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*=************************************************************** *  Custom allocator ****************************************************************/
end_comment

begin_function
name|void
modifier|*
name|ZSTD_malloc
parameter_list|(
name|size_t
name|size
parameter_list|,
name|ZSTD_customMem
name|customMem
parameter_list|)
block|{
if|if
condition|(
name|customMem
operator|.
name|customAlloc
condition|)
return|return
name|customMem
operator|.
name|customAlloc
argument_list|(
name|customMem
operator|.
name|opaque
argument_list|,
name|size
argument_list|)
return|;
return|return
name|malloc
argument_list|(
name|size
argument_list|)
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|ZSTD_calloc
parameter_list|(
name|size_t
name|size
parameter_list|,
name|ZSTD_customMem
name|customMem
parameter_list|)
block|{
if|if
condition|(
name|customMem
operator|.
name|customAlloc
condition|)
block|{
comment|/* calloc implemented as malloc+memset;          * not as efficient as calloc, but next best guess for custom malloc */
name|void
modifier|*
specifier|const
name|ptr
init|=
name|customMem
operator|.
name|customAlloc
argument_list|(
name|customMem
operator|.
name|opaque
argument_list|,
name|size
argument_list|)
decl_stmt|;
name|memset
argument_list|(
name|ptr
argument_list|,
literal|0
argument_list|,
name|size
argument_list|)
expr_stmt|;
return|return
name|ptr
return|;
block|}
return|return
name|calloc
argument_list|(
literal|1
argument_list|,
name|size
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|ZSTD_free
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|ZSTD_customMem
name|customMem
parameter_list|)
block|{
if|if
condition|(
name|ptr
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|customMem
operator|.
name|customFree
condition|)
name|customMem
operator|.
name|customFree
argument_list|(
name|customMem
operator|.
name|opaque
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
else|else
name|free
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

