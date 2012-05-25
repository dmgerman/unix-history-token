begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- udivdi3.c - Implement __udivdi3 -----------------------------------===  *  *                    The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __udivdi3 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_function_decl
name|du_int
name|COMPILER_RT_ABI
name|__udivmoddi4
parameter_list|(
name|du_int
name|a
parameter_list|,
name|du_int
name|b
parameter_list|,
name|du_int
modifier|*
name|rem
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns: a / b */
end_comment

begin_function
name|COMPILER_RT_ABI
name|du_int
name|__udivdi3
parameter_list|(
name|du_int
name|a
parameter_list|,
name|du_int
name|b
parameter_list|)
block|{
return|return
name|__udivmoddi4
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

end_unit

