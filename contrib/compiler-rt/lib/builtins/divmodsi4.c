begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- divmodsi4.c - Implement __divmodsi4 --------------------------------===  *  *                    The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __divmodsi4 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_comment
comment|/* Returns: a / b, *rem = a % b  */
end_comment

begin_function
name|COMPILER_RT_ABI
name|si_int
name|__divmodsi4
parameter_list|(
name|si_int
name|a
parameter_list|,
name|si_int
name|b
parameter_list|,
name|si_int
modifier|*
name|rem
parameter_list|)
block|{
name|si_int
name|d
init|=
name|__divsi3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
decl_stmt|;
operator|*
name|rem
operator|=
name|a
operator|-
operator|(
name|d
operator|*
name|b
operator|)
expr_stmt|;
return|return
name|d
return|;
block|}
end_function

end_unit

