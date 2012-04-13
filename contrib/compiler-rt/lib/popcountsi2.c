begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- popcountsi2.c - Implement __popcountsi2 ---------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __popcountsi2 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_comment
comment|/* Returns: count of 1 bits */
end_comment

begin_function
name|COMPILER_RT_ABI
name|si_int
name|__popcountsi2
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
operator|=
name|x
operator|-
operator|(
operator|(
name|x
operator|>>
literal|1
operator|)
operator|&
literal|0x55555555
operator|)
expr_stmt|;
comment|/* Every 2 bits holds the sum of every pair of bits */
name|x
operator|=
operator|(
operator|(
name|x
operator|>>
literal|2
operator|)
operator|&
literal|0x33333333
operator|)
operator|+
operator|(
name|x
operator|&
literal|0x33333333
operator|)
expr_stmt|;
comment|/* Every 4 bits holds the sum of every 4-set of bits (3 significant bits) */
name|x
operator|=
operator|(
name|x
operator|+
operator|(
name|x
operator|>>
literal|4
operator|)
operator|)
operator|&
literal|0x0F0F0F0F
expr_stmt|;
comment|/* Every 8 bits holds the sum of every 8-set of bits (4 significant bits) */
name|x
operator|=
operator|(
name|x
operator|+
operator|(
name|x
operator|>>
literal|16
operator|)
operator|)
expr_stmt|;
comment|/* The lower 16 bits hold two 8 bit sums (5 significant bits).*/
comment|/*    Upper 16 bits are garbage */
return|return
operator|(
name|x
operator|+
operator|(
name|x
operator|>>
literal|8
operator|)
operator|)
operator|&
literal|0x0000003F
return|;
comment|/* (6 significant bits) */
block|}
end_function

end_unit

