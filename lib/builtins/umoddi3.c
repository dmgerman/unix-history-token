begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- umoddi3.c - Implement __umoddi3 -----------------------------------===  *  *                    The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __umoddi3 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
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
name|du_int
name|__umoddi3
parameter_list|(
name|du_int
name|a
parameter_list|,
name|du_int
name|b
parameter_list|)
block|{
name|du_int
name|r
decl_stmt|;
name|__udivmoddi4
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
operator|&
name|r
argument_list|)
expr_stmt|;
return|return
name|r
return|;
block|}
end_function

end_unit

