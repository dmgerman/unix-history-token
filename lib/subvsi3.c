begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- subvsi3.c - Implement __subvsi3 -----------------------------------===  *  *      	       The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __subvsi3 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* Returns: a - b */
end_comment

begin_comment
comment|/* Effects: aborts if a - b overflows */
end_comment

begin_function
name|si_int
name|__subvsi3
parameter_list|(
name|si_int
name|a
parameter_list|,
name|si_int
name|b
parameter_list|)
block|{
name|si_int
name|s
init|=
name|a
operator|-
name|b
decl_stmt|;
if|if
condition|(
name|b
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
name|s
operator|>
name|a
condition|)
name|compilerrt_abort
argument_list|()
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|s
operator|<=
name|a
condition|)
name|compilerrt_abort
argument_list|()
expr_stmt|;
block|}
return|return
name|s
return|;
block|}
end_function

end_unit

