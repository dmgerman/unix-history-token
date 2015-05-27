begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- paritydi2.c - Implement __paritydi2 -------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __paritydi2 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_comment
comment|/* Returns: 1 if number of bits is odd else returns 0 */
end_comment

begin_function
name|COMPILER_RT_ABI
name|si_int
name|__paritydi2
parameter_list|(
name|di_int
name|a
parameter_list|)
block|{
name|dwords
name|x
decl_stmt|;
name|x
operator|.
name|all
operator|=
name|a
expr_stmt|;
return|return
name|__paritysi2
argument_list|(
name|x
operator|.
name|s
operator|.
name|high
operator|^
name|x
operator|.
name|s
operator|.
name|low
argument_list|)
return|;
block|}
end_function

end_unit

