begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- fixunsxfdi.c - Implement __fixunsxfdi -----------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __fixunsxfdi for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_if
if|#
directive|if
operator|!
name|_ARCH_PPC
end_if

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_comment
comment|/* Returns: convert a to a unsigned long long, rounding toward zero.  *          Negative values all become zero.  */
end_comment

begin_comment
comment|/* Assumption: long double is an intel 80 bit floating point type padded with 6 bytes  *             du_int is a 64 bit integral type  *             value in long double is representable in du_int or is negative   *                 (no range checking performed)  */
end_comment

begin_comment
comment|/* gggg gggg gggg gggg gggg gggg gggg gggg | gggg gggg gggg gggg seee eeee eeee eeee |  * 1mmm mmmm mmmm mmmm mmmm mmmm mmmm mmmm | mmmm mmmm mmmm mmmm mmmm mmmm mmmm mmmm  */
end_comment

begin_function
name|COMPILER_RT_ABI
name|du_int
name|__fixunsxfdi
parameter_list|(
name|long
name|double
name|a
parameter_list|)
block|{
name|long_double_bits
name|fb
decl_stmt|;
name|fb
operator|.
name|f
operator|=
name|a
expr_stmt|;
name|int
name|e
init|=
operator|(
name|fb
operator|.
name|u
operator|.
name|high
operator|.
name|s
operator|.
name|low
operator|&
literal|0x00007FFF
operator|)
operator|-
literal|16383
decl_stmt|;
if|if
condition|(
name|e
operator|<
literal|0
operator|||
operator|(
name|fb
operator|.
name|u
operator|.
name|high
operator|.
name|s
operator|.
name|low
operator|&
literal|0x00008000
operator|)
condition|)
return|return
literal|0
return|;
return|return
name|fb
operator|.
name|u
operator|.
name|low
operator|.
name|all
operator|>>
operator|(
literal|63
operator|-
name|e
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

