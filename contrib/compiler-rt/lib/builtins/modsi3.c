begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- modsi3.c - Implement __modsi3 -------------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __modsi3 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_comment
comment|/* Returns: a % b */
end_comment

begin_function
name|COMPILER_RT_ABI
name|si_int
name|__modsi3
parameter_list|(
name|si_int
name|a
parameter_list|,
name|si_int
name|b
parameter_list|)
block|{
return|return
name|a
operator|-
name|__divsi3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
operator|*
name|b
return|;
block|}
end_function

end_unit

