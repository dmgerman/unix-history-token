begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- divmoddi4.c - Implement __divmoddi4 --------------------------------===  *  *                    The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __divmoddi4 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_function_decl
specifier|extern
name|COMPILER_RT_ABI
name|di_int
name|__divdi3
parameter_list|(
name|di_int
name|a
parameter_list|,
name|di_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns: a / b, *rem = a % b  */
end_comment

begin_function
name|COMPILER_RT_ABI
name|di_int
name|__divmoddi4
parameter_list|(
name|di_int
name|a
parameter_list|,
name|di_int
name|b
parameter_list|,
name|di_int
modifier|*
name|rem
parameter_list|)
block|{
name|di_int
name|d
init|=
name|__divdi3
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

