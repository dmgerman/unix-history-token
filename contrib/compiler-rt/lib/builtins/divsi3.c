begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- divsi3.c - Implement __divsi3 -------------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __divsi3 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
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
name|si_int
name|__divsi3
parameter_list|(
name|si_int
name|a
parameter_list|,
name|si_int
name|b
parameter_list|)
block|{
specifier|const
name|int
name|bits_in_word_m1
init|=
call|(
name|int
call|)
argument_list|(
sizeof|sizeof
argument_list|(
name|si_int
argument_list|)
operator|*
name|CHAR_BIT
argument_list|)
operator|-
literal|1
decl_stmt|;
name|si_int
name|s_a
init|=
name|a
operator|>>
name|bits_in_word_m1
decl_stmt|;
comment|/* s_a = a< 0 ? -1 : 0 */
name|si_int
name|s_b
init|=
name|b
operator|>>
name|bits_in_word_m1
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
comment|/* sign of quotient */
comment|/*      * On CPUs without unsigned hardware division support,      *  this calls __udivsi3 (notice the cast to su_int).      * On CPUs with unsigned hardware division support,      *  this uses the unsigned division instruction.      */
return|return
operator|(
operator|(
name|su_int
operator|)
name|a
operator|/
operator|(
name|su_int
operator|)
name|b
operator|^
name|s_a
operator|)
operator|-
name|s_a
return|;
comment|/* negate if s_a == -1 */
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_EABI__
argument_list|)
end_if

begin_function
name|AEABI_RTABI
name|si_int
name|__aeabi_idiv
parameter_list|(
name|si_int
name|a
parameter_list|,
name|si_int
name|b
parameter_list|)
block|{
return|return
name|__divsi3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

