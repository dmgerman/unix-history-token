begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- ffssi2.c - Implement __ffssi2 -------------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __ffssi2 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_comment
comment|/* Returns: the index of the least significant 1-bit in a, or  * the value zero if a is zero. The least significant bit is index one.  */
end_comment

begin_function
name|COMPILER_RT_ABI
name|si_int
name|__ffssi2
parameter_list|(
name|si_int
name|a
parameter_list|)
block|{
if|if
condition|(
name|a
operator|==
literal|0
condition|)
block|{
return|return
literal|0
return|;
block|}
return|return
name|__builtin_ctz
argument_list|(
name|a
argument_list|)
operator|+
literal|1
return|;
block|}
end_function

end_unit

