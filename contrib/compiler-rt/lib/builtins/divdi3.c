begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- divdi3.c - Implement __divdi3 -------------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __divdi3 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_comment
comment|/* Returns: a / b */
end_comment

begin_function
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
block|{
specifier|const
name|int
name|bits_in_dword_m1
init|=
call|(
name|int
call|)
argument_list|(
sizeof|sizeof
argument_list|(
name|di_int
argument_list|)
operator|*
name|CHAR_BIT
argument_list|)
operator|-
literal|1
decl_stmt|;
name|di_int
name|s_a
init|=
name|a
operator|>>
name|bits_in_dword_m1
decl_stmt|;
comment|/* s_a = a< 0 ? -1 : 0 */
name|di_int
name|s_b
init|=
name|b
operator|>>
name|bits_in_dword_m1
decl_stmt|;
comment|/* s_b = b< 0 ? -1 : 0 */
name|a
operator|=
operator|(
name|a
operator|^
name|s_a
operator|)
operator|-
name|s_a
expr_stmt|;
comment|/* negate if s_a == -1 */
name|b
operator|=
operator|(
name|b
operator|^
name|s_b
operator|)
operator|-
name|s_b
expr_stmt|;
comment|/* negate if s_b == -1 */
name|s_a
operator|^=
name|s_b
expr_stmt|;
comment|/*sign of quotient */
return|return
operator|(
name|__udivmoddi4
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
operator|(
name|du_int
operator|*
operator|)
literal|0
argument_list|)
operator|^
name|s_a
operator|)
operator|-
name|s_a
return|;
comment|/* negate if s_a == -1 */
block|}
end_function

end_unit

