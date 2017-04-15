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
file|"error_private.h"
end_include

begin_include
include|#
directive|include
file|"zbuff.h"
end_include

begin_comment
comment|/*-**************************************** *  ZBUFF Error Management  (deprecated) ******************************************/
end_comment

begin_comment
comment|/*! ZBUFF_isError() : *   tells if a return value is an error code */
end_comment

begin_function
name|unsigned
name|ZBUFF_isError
parameter_list|(
name|size_t
name|errorCode
parameter_list|)
block|{
return|return
name|ERR_isError
argument_list|(
name|errorCode
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*! ZBUFF_getErrorName() : *   provides error code string from function result (useful for debugging) */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|ZBUFF_getErrorName
parameter_list|(
name|size_t
name|errorCode
parameter_list|)
block|{
return|return
name|ERR_getErrorName
argument_list|(
name|errorCode
argument_list|)
return|;
block|}
end_function

end_unit

