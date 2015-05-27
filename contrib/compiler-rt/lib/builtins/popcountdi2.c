begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- popcountdi2.c - Implement __popcountdi2 ----------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __popcountdi2 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
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
name|__popcountdi2
parameter_list|(
name|di_int
name|a
parameter_list|)
block|{
name|du_int
name|x2
init|=
operator|(
name|du_int
operator|)
name|a
decl_stmt|;
name|x2
operator|=
name|x2
operator|-
operator|(
operator|(
name|x2
operator|>>
literal|1
operator|)
operator|&
literal|0x5555555555555555uLL
operator|)
expr_stmt|;
comment|/* Every 2 bits holds the sum of every pair of bits (32) */
name|x2
operator|=
operator|(
operator|(
name|x2
operator|>>
literal|2
operator|)
operator|&
literal|0x3333333333333333uLL
operator|)
operator|+
operator|(
name|x2
operator|&
literal|0x3333333333333333uLL
operator|)
expr_stmt|;
comment|/* Every 4 bits holds the sum of every 4-set of bits (3 significant bits) (16) */
name|x2
operator|=
operator|(
name|x2
operator|+
operator|(
name|x2
operator|>>
literal|4
operator|)
operator|)
operator|&
literal|0x0F0F0F0F0F0F0F0FuLL
expr_stmt|;
comment|/* Every 8 bits holds the sum of every 8-set of bits (4 significant bits) (8) */
name|su_int
name|x
init|=
call|(
name|su_int
call|)
argument_list|(
name|x2
operator|+
operator|(
name|x2
operator|>>
literal|32
operator|)
argument_list|)
decl_stmt|;
comment|/* The lower 32 bits hold four 16 bit sums (5 significant bits). */
comment|/*   Upper 32 bits are garbage */
name|x
operator|=
name|x
operator|+
operator|(
name|x
operator|>>
literal|16
operator|)
expr_stmt|;
comment|/* The lower 16 bits hold two 32 bit sums (6 significant bits). */
comment|/*   Upper 16 bits are garbage */
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
literal|0x0000007F
return|;
comment|/* (7 significant bits) */
block|}
end_function

end_unit

