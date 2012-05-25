begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- paritysi2.c - Implement __paritysi2 -------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __paritysi2 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
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
name|__paritysi2
parameter_list|(
name|si_int
name|a
parameter_list|)
block|{
name|su_int
name|x
init|=
operator|(
name|su_int
operator|)
name|a
decl_stmt|;
name|x
operator|^=
name|x
operator|>>
literal|16
expr_stmt|;
name|x
operator|^=
name|x
operator|>>
literal|8
expr_stmt|;
name|x
operator|^=
name|x
operator|>>
literal|4
expr_stmt|;
return|return
operator|(
literal|0x6996
operator|>>
operator|(
name|x
operator|&
literal|0xF
operator|)
operator|)
operator|&
literal|1
return|;
block|}
end_function

end_unit

