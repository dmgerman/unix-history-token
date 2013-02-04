begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- udivti3.c - Implement __udivti3 -----------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __udivti3 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_if
if|#
directive|if
name|__x86_64
end_if

begin_function_decl
name|tu_int
name|__udivmodti4
parameter_list|(
name|tu_int
name|a
parameter_list|,
name|tu_int
name|b
parameter_list|,
name|tu_int
modifier|*
name|rem
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns: a / b */
end_comment

begin_function
name|tu_int
name|__udivti3
parameter_list|(
name|tu_int
name|a
parameter_list|,
name|tu_int
name|b
parameter_list|)
block|{
return|return
name|__udivmodti4
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __x86_64 */
end_comment

end_unit

