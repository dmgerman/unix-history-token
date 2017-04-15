begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2016-present, Yann Collet, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under the BSD-style license found in the  * LICENSE file in the root directory of this source tree. An additional grant  * of patent rights can be found in the PATENTS file in the same directory.  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* size_t */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* strlen */
end_comment

begin_comment
comment|/* symbol definition */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|XXH32
parameter_list|(
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|srcSize
parameter_list|,
name|unsigned
name|seed
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|exename
init|=
name|argv
index|[
literal|0
index|]
decl_stmt|;
name|unsigned
name|result
init|=
name|XXH32
argument_list|(
name|exename
argument_list|,
name|strlen
argument_list|(
name|exename
argument_list|)
argument_list|,
name|argc
argument_list|)
decl_stmt|;
return|return
operator|!
name|result
return|;
block|}
end_function

end_unit

