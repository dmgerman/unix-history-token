begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- floatundixf.c - Implement __floatundixf ---------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __floatundixf for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
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
comment|/* Returns: convert a to a long double, rounding toward even. */
end_comment

begin_comment
comment|/* Assumption: long double is a IEEE 80 bit floating point type padded to 128 bits  *             du_int is a 64 bit integral type  */
end_comment

begin_comment
comment|/* gggg gggg gggg gggg gggg gggg gggg gggg | gggg gggg gggg gggg seee eeee eeee eeee |  * 1mmm mmmm mmmm mmmm mmmm mmmm mmmm mmmm | mmmm mmmm mmmm mmmm mmmm mmmm mmmm mmmm  */
end_comment

begin_function
name|COMPILER_RT_ABI
name|long
name|double
name|__floatundixf
parameter_list|(
name|du_int
name|a
parameter_list|)
block|{
if|if
condition|(
name|a
operator|==
literal|0
condition|)
return|return
literal|0.0
return|;
specifier|const
name|unsigned
name|N
init|=
sizeof|sizeof
argument_list|(
name|du_int
argument_list|)
operator|*
name|CHAR_BIT
decl_stmt|;
name|int
name|clz
init|=
name|__builtin_clzll
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|int
name|e
init|=
operator|(
name|N
operator|-
literal|1
operator|)
operator|-
name|clz
decl_stmt|;
comment|/* exponent */
name|long_double_bits
name|fb
decl_stmt|;
name|fb
operator|.
name|u
operator|.
name|high
operator|.
name|s
operator|.
name|low
operator|=
operator|(
name|e
operator|+
literal|16383
operator|)
expr_stmt|;
comment|/* exponent */
name|fb
operator|.
name|u
operator|.
name|low
operator|.
name|all
operator|=
name|a
operator|<<
name|clz
expr_stmt|;
comment|/* mantissa */
return|return
name|fb
operator|.
name|f
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARCH_PPC */
end_comment

end_unit

