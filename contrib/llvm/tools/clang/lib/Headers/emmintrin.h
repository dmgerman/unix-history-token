begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- emmintrin.h - SSE2 intrinsics ------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EMMINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__EMMINTRIN_H
end_define

begin_include
include|#
directive|include
file|<xmmintrin.h>
end_include

begin_typedef
typedef|typedef
name|double
name|__m128d
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|__m128i
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_comment
comment|/* Type defines.  */
end_comment

begin_typedef
typedef|typedef
name|double
name|__v2df
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|__v2di
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|short
name|__v8hi
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|char
name|__v16qi
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_comment
comment|/* Unsigned types */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|__v2du
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|__v8hu
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|__v16qu
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_comment
comment|/* We need an explicitly signed variant for char. Note that this shouldn't  * appear in the interface though. */
end_comment

begin_typedef
typedef|typedef
name|signed
name|char
name|__v16qs
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_include
include|#
directive|include
file|<f16cintrin.h>
end_include

begin_comment
comment|/* Define the default attributes for the functions in this file. */
end_comment

begin_define
define|#
directive|define
name|__DEFAULT_FN_ATTRS
value|__attribute__((__always_inline__, __nodebug__, __target__("sse2")))
end_define

begin_comment
comment|/// \brief Adds lower double-precision values in both operands and returns the
end_comment

begin_comment
comment|///    sum in the lower 64 bits of the result. The upper 64 bits of the result
end_comment

begin_comment
comment|///    are copied from the upper double-precision value of the first operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VADDSD / ADDSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] whose lower 64 bits contain the
end_comment

begin_comment
comment|///    sum of the lower 64 bits of both operands. The upper 64 bits are copied
end_comment

begin_comment
comment|///    from the upper 64 bits of the first source operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_add_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
name|__a
index|[
literal|0
index|]
operator|+=
name|__b
index|[
literal|0
index|]
expr_stmt|;
return|return
name|__a
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds two 128-bit vectors of [2 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VADDPD / ADDPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the sums of both
end_comment

begin_comment
comment|///    operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_add_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128d
call|)
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
operator|+
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts the lower double-precision value of the second operand
end_comment

begin_comment
comment|///    from the lower double-precision value of the first operand and returns
end_comment

begin_comment
comment|///    the difference in the lower 64 bits of the result. The upper 64 bits of
end_comment

begin_comment
comment|///    the result are copied from the upper double-precision value of the first
end_comment

begin_comment
comment|///    operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VSUBSD / SUBSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing the minuend.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing the subtrahend.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] whose lower 64 bits contain the
end_comment

begin_comment
comment|///    difference of the lower 64 bits of both operands. The upper 64 bits are
end_comment

begin_comment
comment|///    copied from the upper 64 bits of the first source operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_sub_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
name|__a
index|[
literal|0
index|]
operator|-=
name|__b
index|[
literal|0
index|]
expr_stmt|;
return|return
name|__a
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts two 128-bit vectors of [2 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VSUBPD / SUBPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing the minuend.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing the subtrahend.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the differences between
end_comment

begin_comment
comment|///    both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_sub_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128d
call|)
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
operator|-
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Multiplies lower double-precision values in both operands and returns
end_comment

begin_comment
comment|///    the product in the lower 64 bits of the result. The upper 64 bits of the
end_comment

begin_comment
comment|///    result are copied from the upper double-precision value of the first
end_comment

begin_comment
comment|///    operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMULSD / MULSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] whose lower 64 bits contain the
end_comment

begin_comment
comment|///    product of the lower 64 bits of both operands. The upper 64 bits are
end_comment

begin_comment
comment|///    copied from the upper 64 bits of the first source operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_mul_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
name|__a
index|[
literal|0
index|]
operator|*=
name|__b
index|[
literal|0
index|]
expr_stmt|;
return|return
name|__a
return|;
block|}
end_function

begin_comment
comment|/// \brief Multiplies two 128-bit vectors of [2 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMULPD / MULPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the operands.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the products of both
end_comment

begin_comment
comment|///    operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_mul_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128d
call|)
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
operator|*
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Divides the lower double-precision value of the first operand by the
end_comment

begin_comment
comment|///    lower double-precision value of the second operand and returns the
end_comment

begin_comment
comment|///    quotient in the lower 64 bits of the result. The upper 64 bits of the
end_comment

begin_comment
comment|///    result are copied from the upper double-precision value of the first
end_comment

begin_comment
comment|///    operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VDIVSD / DIVSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing the dividend.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing divisor.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] whose lower 64 bits contain the
end_comment

begin_comment
comment|///    quotient of the lower 64 bits of both operands. The upper 64 bits are
end_comment

begin_comment
comment|///    copied from the upper 64 bits of the first source operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_div_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
name|__a
index|[
literal|0
index|]
operator|/=
name|__b
index|[
literal|0
index|]
expr_stmt|;
return|return
name|__a
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs an element-by-element division of two 128-bit vectors of
end_comment

begin_comment
comment|///    [2 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VDIVPD / DIVPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing the dividend.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing the divisor.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the quotients of both
end_comment

begin_comment
comment|///    operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_div_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128d
call|)
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
operator|/
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Calculates the square root of the lower double-precision value of
end_comment

begin_comment
comment|///    the second operand and returns it in the lower 64 bits of the result.
end_comment

begin_comment
comment|///    The upper 64 bits of the result are copied from the upper double-
end_comment

begin_comment
comment|///    precision value of the first operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VSQRTSD / SQRTSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the operands. The
end_comment

begin_comment
comment|///    upper 64 bits of this operand are copied to the upper 64 bits of the
end_comment

begin_comment
comment|///    result.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the operands. The
end_comment

begin_comment
comment|///    square root is calculated using the lower 64 bits of this operand.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] whose lower 64 bits contain the
end_comment

begin_comment
comment|///    square root of the lower 64 bits of operand \a __b, and whose upper 64
end_comment

begin_comment
comment|///    bits are copied from the upper 64 bits of operand \a __a.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_sqrt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
name|__m128d
name|__c
init|=
name|__builtin_ia32_sqrtsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
decl_stmt|;
return|return
operator|(
name|__m128d
operator|)
block|{
name|__c
index|[
literal|0
index|]
block|,
name|__a
index|[
literal|1
index|]
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Calculates the square root of the each of two values stored in a
end_comment

begin_comment
comment|///    128-bit vector of [2 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VSQRTPD / SQRTPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the square roots of the
end_comment

begin_comment
comment|///    values in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_sqrt_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_sqrtpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares lower 64-bit double-precision values of both operands, and
end_comment

begin_comment
comment|///    returns the lesser of the pair of values in the lower 64-bits of the
end_comment

begin_comment
comment|///    result. The upper 64 bits of the result are copied from the upper double-
end_comment

begin_comment
comment|///    precision value of the first operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMINSD / MINSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the operands. The
end_comment

begin_comment
comment|///    lower 64 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the operands. The
end_comment

begin_comment
comment|///    lower 64 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] whose lower 64 bits contain the
end_comment

begin_comment
comment|///    minimum value between both operands. The upper 64 bits are copied from
end_comment

begin_comment
comment|///    the upper 64 bits of the first source operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_min_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_minsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs element-by-element comparison of the two 128-bit vectors of
end_comment

begin_comment
comment|///    [2 x double] and returns the vector containing the lesser of each pair of
end_comment

begin_comment
comment|///    values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMINPD / MINPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the operands.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the minimum values
end_comment

begin_comment
comment|///    between both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_min_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_minpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares lower 64-bits double-precision values of both operands, and
end_comment

begin_comment
comment|///    returns the greater of the pair of values in the lower 64-bits of the
end_comment

begin_comment
comment|///    result. The upper 64 bits of the result are copied from the upper double-
end_comment

begin_comment
comment|///    precision value of the first operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMAXSD / MAXSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the operands. The
end_comment

begin_comment
comment|///    lower 64 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the operands. The
end_comment

begin_comment
comment|///    lower 64 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] whose lower 64 bits contain the
end_comment

begin_comment
comment|///    maximum value between both operands. The upper 64 bits are copied from
end_comment

begin_comment
comment|///    the upper 64 bits of the first source operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_max_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_maxsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs element-by-element comparison of the two 128-bit vectors of
end_comment

begin_comment
comment|///    [2 x double] and returns the vector containing the greater of each pair
end_comment

begin_comment
comment|///    of values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMAXPD / MAXPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the operands.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the maximum values
end_comment

begin_comment
comment|///    between both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_max_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_maxpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise AND of two 128-bit vectors of [2 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPAND / PAND</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the bitwise AND of the
end_comment

begin_comment
comment|///    values between both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_and_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128d
call|)
argument_list|(
operator|(
name|__v2du
operator|)
name|__a
operator|&
operator|(
name|__v2du
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise AND of two 128-bit vectors of [2 x double], using
end_comment

begin_comment
comment|///    the one's complement of the values contained in the first source operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPANDN / PANDN</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing the left source operand. The
end_comment

begin_comment
comment|///    one's complement of this value is used in the bitwise AND.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing the right source operand.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the bitwise AND of the
end_comment

begin_comment
comment|///    values in the second operand and the one's complement of the first
end_comment

begin_comment
comment|///    operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_andnot_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128d
call|)
argument_list|(
operator|~
operator|(
name|__v2du
operator|)
name|__a
operator|&
operator|(
name|__v2du
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise OR of two 128-bit vectors of [2 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPOR / POR</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the bitwise OR of the
end_comment

begin_comment
comment|///    values between both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_or_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128d
call|)
argument_list|(
operator|(
name|__v2du
operator|)
name|__a
operator||
operator|(
name|__v2du
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise XOR of two 128-bit vectors of [2 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPXOR / PXOR</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the bitwise XOR of the
end_comment

begin_comment
comment|///    values between both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_xor_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128d
call|)
argument_list|(
operator|(
name|__v2du
operator|)
name|__a
operator|^
operator|(
name|__v2du
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding double-precision values of the
end_comment

begin_comment
comment|///    128-bit vectors of [2 x double] for equality. Each comparison yields 0h
end_comment

begin_comment
comment|///    for false, FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPEQPD / CMPEQPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 128-bit vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpeq_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpeqpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding double-precision values of the
end_comment

begin_comment
comment|///    128-bit vectors of [2 x double] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are less than those in the second operand. Each comparison
end_comment

begin_comment
comment|///    yields 0h for false, FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPLTPD / CMPLTPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 128-bit vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmplt_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpltpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding double-precision values of the
end_comment

begin_comment
comment|///    128-bit vectors of [2 x double] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are less than or equal to those in the second operand. Each
end_comment

begin_comment
comment|///    comparison yields 0h for false, FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPLEPD / CMPLEPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 128-bit vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmple_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmplepd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding double-precision values of the
end_comment

begin_comment
comment|///    128-bit vectors of [2 x double] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are greater than those in the second operand. Each comparison
end_comment

begin_comment
comment|///    yields 0h for false, FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPLTPD / CMPLTPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 128-bit vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpgt_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpltpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__b
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding double-precision values of the
end_comment

begin_comment
comment|///    128-bit vectors of [2 x double] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are greater than or equal to those in the second operand. Each
end_comment

begin_comment
comment|///    comparison yields 0h for false, FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPLEPD / CMPLEPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 128-bit vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpge_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmplepd
argument_list|(
operator|(
name|__v2df
operator|)
name|__b
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding double-precision values of the
end_comment

begin_comment
comment|///    128-bit vectors of [2 x double] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are ordered with respect to those in the second operand. A pair
end_comment

begin_comment
comment|///    of double-precision values are "ordered" with respect to each other if
end_comment

begin_comment
comment|///    neither value is a NaN. Each comparison yields 0h for false,
end_comment

begin_comment
comment|///    FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPORDPD / CMPORDPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 128-bit vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpord_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpordpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding double-precision values of the
end_comment

begin_comment
comment|///    128-bit vectors of [2 x double] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are unordered with respect to those in the second operand. A pair
end_comment

begin_comment
comment|///    of double-precision values are "unordered" with respect to each other if
end_comment

begin_comment
comment|///    one or both values are NaN. Each comparison yields 0h for false,
end_comment

begin_comment
comment|///    FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPUNORDPD / CMPUNORDPD</c>
end_comment

begin_comment
comment|///   instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 128-bit vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpunord_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpunordpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding double-precision values of the
end_comment

begin_comment
comment|///    128-bit vectors of [2 x double] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are unequal to those in the second operand. Each comparison
end_comment

begin_comment
comment|///    yields 0h for false, FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPNEQPD / CMPNEQPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 128-bit vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpneq_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpneqpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding double-precision values of the
end_comment

begin_comment
comment|///    128-bit vectors of [2 x double] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are not less than those in the second operand. Each comparison
end_comment

begin_comment
comment|///    yields 0h for false, FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPNLTPD / CMPNLTPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 128-bit vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpnlt_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpnltpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding double-precision values of the
end_comment

begin_comment
comment|///    128-bit vectors of [2 x double] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are not less than or equal to those in the second operand. Each
end_comment

begin_comment
comment|///    comparison yields 0h for false, FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPNLEPD / CMPNLEPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 128-bit vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpnle_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpnlepd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding double-precision values of the
end_comment

begin_comment
comment|///    128-bit vectors of [2 x double] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are not greater than those in the second operand. Each
end_comment

begin_comment
comment|///    comparison yields 0h for false, FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPNLTPD / CMPNLTPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 128-bit vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpngt_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpnltpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__b
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding double-precision values of the
end_comment

begin_comment
comment|///    128-bit vectors of [2 x double] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are not greater than or equal to those in the second operand.
end_comment

begin_comment
comment|///    Each comparison yields 0h for false, FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPNLEPD / CMPNLEPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 128-bit vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpnge_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpnlepd
argument_list|(
operator|(
name|__v2df
operator|)
name|__b
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] for equality. The
end_comment

begin_comment
comment|///    comparison yields 0h for false, FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPEQSD / CMPEQSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit vector. The lower 64 bits contains the comparison
end_comment

begin_comment
comment|///    results. The upper 64 bits are copied from the upper 64 bits of \a __a.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpeq_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpeqsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is less than the corresponding value in
end_comment

begin_comment
comment|///    the second parameter. The comparison yields 0h for false,
end_comment

begin_comment
comment|///    FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPLTSD / CMPLTSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit vector. The lower 64 bits contains the comparison
end_comment

begin_comment
comment|///    results. The upper 64 bits are copied from the upper 64 bits of \a __a.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmplt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpltsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is less than or equal to the
end_comment

begin_comment
comment|///    corresponding value in the second parameter. The comparison yields 0h for
end_comment

begin_comment
comment|///    false, FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPLESD / CMPLESD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit vector. The lower 64 bits contains the comparison
end_comment

begin_comment
comment|///    results. The upper 64 bits are copied from the upper 64 bits of \a __a.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmple_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmplesd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is greater than the corresponding value
end_comment

begin_comment
comment|///    in the second parameter. The comparison yields 0h for false,
end_comment

begin_comment
comment|///    FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPLTSD / CMPLTSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///     A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///     compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///     A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///     compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit vector. The lower 64 bits contains the comparison
end_comment

begin_comment
comment|///     results. The upper 64 bits are copied from the upper 64 bits of \a __a.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpgt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
name|__m128d
name|__c
init|=
name|__builtin_ia32_cmpltsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__b
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
decl_stmt|;
return|return
operator|(
name|__m128d
operator|)
block|{
name|__c
index|[
literal|0
index|]
block|,
name|__a
index|[
literal|1
index|]
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is greater than or equal to the
end_comment

begin_comment
comment|///    corresponding value in the second parameter. The comparison yields 0h for
end_comment

begin_comment
comment|///    false, FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPLESD / CMPLESD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit vector. The lower 64 bits contains the comparison
end_comment

begin_comment
comment|///    results. The upper 64 bits are copied from the upper 64 bits of \a __a.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpge_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
name|__m128d
name|__c
init|=
name|__builtin_ia32_cmplesd
argument_list|(
operator|(
name|__v2df
operator|)
name|__b
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
decl_stmt|;
return|return
operator|(
name|__m128d
operator|)
block|{
name|__c
index|[
literal|0
index|]
block|,
name|__a
index|[
literal|1
index|]
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is "ordered" with respect to the
end_comment

begin_comment
comment|///    corresponding value in the second parameter. The comparison yields 0h for
end_comment

begin_comment
comment|///    false, FFFFFFFFFFFFFFFFh for true. A pair of double-precision values are
end_comment

begin_comment
comment|///    "ordered" with respect to each other if neither value is a NaN.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPORDSD / CMPORDSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit vector. The lower 64 bits contains the comparison
end_comment

begin_comment
comment|///    results. The upper 64 bits are copied from the upper 64 bits of \a __a.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpord_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpordsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is "unordered" with respect to the
end_comment

begin_comment
comment|///    corresponding value in the second parameter. The comparison yields 0h
end_comment

begin_comment
comment|///    for false, FFFFFFFFFFFFFFFFh for true. A pair of double-precision values
end_comment

begin_comment
comment|///    are "unordered" with respect to each other if one or both values are NaN.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPUNORDSD / CMPUNORDSD</c>
end_comment

begin_comment
comment|///   instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit vector. The lower 64 bits contains the comparison
end_comment

begin_comment
comment|///    results. The upper 64 bits are copied from the upper 64 bits of \a __a.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpunord_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpunordsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is unequal to the corresponding value in
end_comment

begin_comment
comment|///    the second parameter. The comparison yields 0h for false,
end_comment

begin_comment
comment|///    FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPNEQSD / CMPNEQSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit vector. The lower 64 bits contains the comparison
end_comment

begin_comment
comment|///    results. The upper 64 bits are copied from the upper 64 bits of \a __a.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpneq_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpneqsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is not less than the corresponding
end_comment

begin_comment
comment|///    value in the second parameter. The comparison yields 0h for false,
end_comment

begin_comment
comment|///    FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPNLTSD / CMPNLTSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit vector. The lower 64 bits contains the comparison
end_comment

begin_comment
comment|///    results. The upper 64 bits are copied from the upper 64 bits of \a __a.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpnlt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpnltsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is not less than or equal to the
end_comment

begin_comment
comment|///    corresponding value in the second parameter. The comparison yields 0h
end_comment

begin_comment
comment|///    for false, FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPNLESD / CMPNLESD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns  A 128-bit vector. The lower 64 bits contains the comparison
end_comment

begin_comment
comment|///    results. The upper 64 bits are copied from the upper 64 bits of \a __a.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpnle_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpnlesd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is not greater than the corresponding
end_comment

begin_comment
comment|///    value in the second parameter. The comparison yields 0h for false,
end_comment

begin_comment
comment|///    FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPNLTSD / CMPNLTSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit vector. The lower 64 bits contains the comparison
end_comment

begin_comment
comment|///    results. The upper 64 bits are copied from the upper 64 bits of \a __a.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpngt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
name|__m128d
name|__c
init|=
name|__builtin_ia32_cmpnltsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__b
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
decl_stmt|;
return|return
operator|(
name|__m128d
operator|)
block|{
name|__c
index|[
literal|0
index|]
block|,
name|__a
index|[
literal|1
index|]
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is not greater than or equal to the
end_comment

begin_comment
comment|///    corresponding value in the second parameter. The comparison yields 0h
end_comment

begin_comment
comment|///    for false, FFFFFFFFFFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCMPNLESD / CMPNLESD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit vector. The lower 64 bits contains the comparison
end_comment

begin_comment
comment|///    results. The upper 64 bits are copied from the upper 64 bits of \a __a.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpnge_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
name|__m128d
name|__c
init|=
name|__builtin_ia32_cmpnlesd
argument_list|(
operator|(
name|__v2df
operator|)
name|__b
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
decl_stmt|;
return|return
operator|(
name|__m128d
operator|)
block|{
name|__c
index|[
literal|0
index|]
block|,
name|__a
index|[
literal|1
index|]
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] for equality. The
end_comment

begin_comment
comment|///    comparison yields 0 for false, 1 for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCOMISD / COMISD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_comieq_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_comisdeq
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is less than the corresponding value in
end_comment

begin_comment
comment|///    the second parameter. The comparison yields 0 for false, 1 for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCOMISD / COMISD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_comilt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_comisdlt
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is less than or equal to the
end_comment

begin_comment
comment|///    corresponding value in the second parameter. The comparison yields 0 for
end_comment

begin_comment
comment|///    false, 1 for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCOMISD / COMISD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///     A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///     compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_comile_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_comisdle
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is greater than the corresponding value
end_comment

begin_comment
comment|///    in the second parameter. The comparison yields 0 for false, 1 for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCOMISD / COMISD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_comigt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_comisdgt
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is greater than or equal to the
end_comment

begin_comment
comment|///    corresponding value in the second parameter. The comparison yields 0 for
end_comment

begin_comment
comment|///    false, 1 for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCOMISD / COMISD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_comige_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_comisdge
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is unequal to the corresponding value in
end_comment

begin_comment
comment|///    the second parameter. The comparison yields 0 for false, 1 for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCOMISD / COMISD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_comineq_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_comisdneq
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] for equality. The
end_comment

begin_comment
comment|///    comparison yields 0 for false, 1 for true. If either of the two lower
end_comment

begin_comment
comment|///    double-precision values is NaN, 1 is returned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VUCOMISD / UCOMISD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results. If either of the two
end_comment

begin_comment
comment|///    lower double-precision values is NaN, 1 is returned.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_ucomieq_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ucomisdeq
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is less than the corresponding value in
end_comment

begin_comment
comment|///    the second parameter. The comparison yields 0 for false, 1 for true. If
end_comment

begin_comment
comment|///    either of the two lower double-precision values is NaN, 1 is returned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VUCOMISD / UCOMISD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results. If either of the two
end_comment

begin_comment
comment|///    lower double-precision values is NaN, 1 is returned.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_ucomilt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ucomisdlt
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is less than or equal to the
end_comment

begin_comment
comment|///    corresponding value in the second parameter. The comparison yields 0 for
end_comment

begin_comment
comment|///    false, 1 for true. If either of the two lower double-precision values is
end_comment

begin_comment
comment|///    NaN, 1 is returned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VUCOMISD / UCOMISD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///     A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///     compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results. If either of the two
end_comment

begin_comment
comment|///     lower double-precision values is NaN, 1 is returned.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_ucomile_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ucomisdle
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is greater than the corresponding value
end_comment

begin_comment
comment|///    in the second parameter. The comparison yields 0 for false, 1 for true.
end_comment

begin_comment
comment|///    If either of the two lower double-precision values is NaN, 0 is returned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VUCOMISD / UCOMISD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///     A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///     compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results. If either of the two
end_comment

begin_comment
comment|///     lower double-precision values is NaN, 0 is returned.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_ucomigt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ucomisdgt
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is greater than or equal to the
end_comment

begin_comment
comment|///    corresponding value in the second parameter. The comparison yields 0 for
end_comment

begin_comment
comment|///    false, 1 for true.  If either of the two lower double-precision values
end_comment

begin_comment
comment|///    is NaN, 0 is returned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VUCOMISD / UCOMISD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results. If either of the two
end_comment

begin_comment
comment|///    lower double-precision values is NaN, 0 is returned.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_ucomige_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ucomisdge
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the lower double-precision floating-point values in each of
end_comment

begin_comment
comment|///    the two 128-bit floating-point vectors of [2 x double] to determine if
end_comment

begin_comment
comment|///    the value in the first parameter is unequal to the corresponding value in
end_comment

begin_comment
comment|///    the second parameter. The comparison yields 0 for false, 1 for true. If
end_comment

begin_comment
comment|///    either of the two lower double-precision values is NaN, 0 is returned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VUCOMISD / UCOMISD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision value is
end_comment

begin_comment
comment|///    compared to the lower double-precision value of \a __a.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison result. If either of the two
end_comment

begin_comment
comment|///    lower double-precision values is NaN, 0 is returned.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_ucomineq_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ucomisdneq
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts the two double-precision floating-point elements of a
end_comment

begin_comment
comment|///    128-bit vector of [2 x double] into two single-precision floating-point
end_comment

begin_comment
comment|///    values, returned in the lower 64 bits of a 128-bit vector of [4 x float].
end_comment

begin_comment
comment|///    The upper 64 bits of the result vector are set to zero.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTPD2PS / CVTPD2PS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] whose lower 64 bits contain the
end_comment

begin_comment
comment|///    converted values. The upper 64 bits are set to zero.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cvtpd_ps
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvtpd2ps
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts the lower two single-precision floating-point elements of a
end_comment

begin_comment
comment|///    128-bit vector of [4 x float] into two double-precision floating-point
end_comment

begin_comment
comment|///    values, returned in a 128-bit vector of [2 x double]. The upper two
end_comment

begin_comment
comment|///    elements of the input vector are unused.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTPS2PD / CVTPS2PD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower two single-precision
end_comment

begin_comment
comment|///    floating-point elements are converted to double-precision values. The
end_comment

begin_comment
comment|///    upper two elements are unused.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the converted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cvtps_pd
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_convertvector
argument_list|(
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|,
name|__v2df
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts the lower two integer elements of a 128-bit vector of
end_comment

begin_comment
comment|///    [4 x i32] into two double-precision floating-point values, returned in a
end_comment

begin_comment
comment|///    128-bit vector of [2 x double]. The upper two elements of the input
end_comment

begin_comment
comment|///    vector are unused.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTDQ2PD / CVTDQ2PD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector of [4 x i32]. The lower two integer elements are
end_comment

begin_comment
comment|///    converted to double-precision values. The upper two elements are unused.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the converted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cvtepi32_pd
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_convertvector
argument_list|(
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|,
name|__v2df
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts the two double-precision floating-point elements of a
end_comment

begin_comment
comment|///    128-bit vector of [2 x double] into two signed 32-bit integer values,
end_comment

begin_comment
comment|///    returned in the lower 64 bits of a 128-bit vector of [4 x i32]. The upper
end_comment

begin_comment
comment|///    64 bits of the result vector are set to zero.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTPD2DQ / CVTPD2DQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x i32] whose lower 64 bits contain the
end_comment

begin_comment
comment|///    converted values. The upper 64 bits are set to zero.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvtpd_epi32
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvtpd2dq
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts the low-order element of a 128-bit vector of [2 x double]
end_comment

begin_comment
comment|///    into a 32-bit signed integer value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTSD2SI / CVTSD2SI</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower 64 bits are used in the
end_comment

begin_comment
comment|///    conversion.
end_comment

begin_comment
comment|/// \returns A 32-bit signed integer containing the converted value.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsd_si32
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvtsd2si
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts the lower double-precision floating-point element of a
end_comment

begin_comment
comment|///    128-bit vector of [2 x double], in the second parameter, into a
end_comment

begin_comment
comment|///    single-precision floating-point value, returned in the lower 32 bits of a
end_comment

begin_comment
comment|///    128-bit vector of [4 x float]. The upper 96 bits of the result vector are
end_comment

begin_comment
comment|///    copied from the upper 96 bits of the first parameter.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTSD2SS / CVTSD2SS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The upper 96 bits of this parameter are
end_comment

begin_comment
comment|///    copied to the upper 96 bits of the result.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower double-precision
end_comment

begin_comment
comment|///    floating-point element is used in the conversion.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float]. The lower 32 bits contain the
end_comment

begin_comment
comment|///    converted value from the second parameter. The upper 96 bits are copied
end_comment

begin_comment
comment|///    from the upper 96 bits of the first parameter.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsd_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cvtsd2ss
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts a 32-bit signed integer value, in the second parameter, into
end_comment

begin_comment
comment|///    a double-precision floating-point value, returned in the lower 64 bits of
end_comment

begin_comment
comment|///    a 128-bit vector of [2 x double]. The upper 64 bits of the result vector
end_comment

begin_comment
comment|///    are copied from the upper 64 bits of the first parameter.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTSI2SD / CVTSI2SD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The upper 64 bits of this parameter are
end_comment

begin_comment
comment|///    copied to the upper 64 bits of the result.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 32-bit signed integer containing the value to be converted.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double]. The lower 64 bits contain the
end_comment

begin_comment
comment|///    converted value from the second parameter. The upper 64 bits are copied
end_comment

begin_comment
comment|///    from the upper 64 bits of the first parameter.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsi32_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|int
name|__b
parameter_list|)
block|{
name|__a
index|[
literal|0
index|]
operator|=
name|__b
expr_stmt|;
return|return
name|__a
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts the lower single-precision floating-point element of a
end_comment

begin_comment
comment|///    128-bit vector of [4 x float], in the second parameter, into a
end_comment

begin_comment
comment|///    double-precision floating-point value, returned in the lower 64 bits of
end_comment

begin_comment
comment|///    a 128-bit vector of [2 x double]. The upper 64 bits of the result vector
end_comment

begin_comment
comment|///    are copied from the upper 64 bits of the first parameter.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTSS2SD / CVTSS2SD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The upper 64 bits of this parameter are
end_comment

begin_comment
comment|///    copied to the upper 64 bits of the result.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower single-precision
end_comment

begin_comment
comment|///    floating-point element is used in the conversion.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double]. The lower 64 bits contain the
end_comment

begin_comment
comment|///    converted value from the second parameter. The upper 64 bits are copied
end_comment

begin_comment
comment|///    from the upper 64 bits of the first parameter.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cvtss_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
name|__a
index|[
literal|0
index|]
operator|=
name|__b
index|[
literal|0
index|]
expr_stmt|;
return|return
name|__a
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts the two double-precision floating-point elements of a
end_comment

begin_comment
comment|///    128-bit vector of [2 x double] into two signed 32-bit integer values,
end_comment

begin_comment
comment|///    returned in the lower 64 bits of a 128-bit vector of [4 x i32]. If the
end_comment

begin_comment
comment|///    result of either conversion is inexact, the result is truncated (rounded
end_comment

begin_comment
comment|///    towards zero) regardless of the current MXCSR setting. The upper 64 bits
end_comment

begin_comment
comment|///    of the result vector are set to zero.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTTPD2DQ / CVTTPD2DQ</c>
end_comment

begin_comment
comment|///   instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x i32] whose lower 64 bits contain the
end_comment

begin_comment
comment|///    converted values. The upper 64 bits are set to zero.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvttpd_epi32
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_cvttpd2dq
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts the low-order element of a [2 x double] vector into a 32-bit
end_comment

begin_comment
comment|///    signed integer value, truncating the result when it is inexact.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTTSD2SI / CVTTSD2SI</c>
end_comment

begin_comment
comment|///   instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower 64 bits are used in the
end_comment

begin_comment
comment|///    conversion.
end_comment

begin_comment
comment|/// \returns A 32-bit signed integer containing the converted value.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_cvttsd_si32
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvttsd2si
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts the two double-precision floating-point elements of a
end_comment

begin_comment
comment|///    128-bit vector of [2 x double] into two signed 32-bit integer values,
end_comment

begin_comment
comment|///    returned in a 64-bit vector of [2 x i32].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> CVTPD2PI</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 64-bit vector of [2 x i32] containing the converted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_cvtpd_pi32
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_cvtpd2pi
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts the two double-precision floating-point elements of a
end_comment

begin_comment
comment|///    128-bit vector of [2 x double] into two signed 32-bit integer values,
end_comment

begin_comment
comment|///    returned in a 64-bit vector of [2 x i32]. If the result of either
end_comment

begin_comment
comment|///    conversion is inexact, the result is truncated (rounded towards zero)
end_comment

begin_comment
comment|///    regardless of the current MXCSR setting.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> CVTTPD2PI</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 64-bit vector of [2 x i32] containing the converted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_cvttpd_pi32
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_cvttpd2pi
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts the two signed 32-bit integer elements of a 64-bit vector of
end_comment

begin_comment
comment|///    [2 x i32] into two double-precision floating-point values, returned in a
end_comment

begin_comment
comment|///    128-bit vector of [2 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> CVTPI2PD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit vector of [2 x i32].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the converted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cvtpi32_pd
parameter_list|(
name|__m64
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvtpi2pd
argument_list|(
operator|(
name|__v2si
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Returns the low-order element of a 128-bit vector of [2 x double] as
end_comment

begin_comment
comment|///    a double-precision floating-point value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic has no corresponding instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower 64 bits are returned.
end_comment

begin_comment
comment|/// \returns A double-precision floating-point value copied from the lower 64
end_comment

begin_comment
comment|///    bits of \a __a.
end_comment

begin_function
specifier|static
name|__inline__
name|double
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsd_f64
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|__a
index|[
literal|0
index|]
return|;
block|}
end_function

begin_comment
comment|/// \brief Loads a 128-bit floating-point vector of [2 x double] from an aligned
end_comment

begin_comment
comment|///    memory location.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVAPD / MOVAPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __dp
end_comment

begin_comment
comment|///    A pointer to a 128-bit memory location. The address of the memory
end_comment

begin_comment
comment|///    location has to be 16-byte aligned.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the loaded values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_load_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|__dp
parameter_list|)
block|{
return|return
operator|*
operator|(
name|__m128d
operator|*
operator|)
name|__dp
return|;
block|}
end_function

begin_comment
comment|/// \brief Loads a double-precision floating-point value from a specified memory
end_comment

begin_comment
comment|///    location and duplicates it to both vector elements of a 128-bit vector of
end_comment

begin_comment
comment|///    [2 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVDDUP / MOVDDUP</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __dp
end_comment

begin_comment
comment|///    A pointer to a memory location containing a double-precision value.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the loaded and
end_comment

begin_comment
comment|///    duplicated values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_load1_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|__dp
parameter_list|)
block|{
struct|struct
name|__mm_load1_pd_struct
block|{
name|double
name|__u
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
name|double
name|__u
init|=
operator|(
operator|(
expr|struct
name|__mm_load1_pd_struct
operator|*
operator|)
name|__dp
operator|)
operator|->
name|__u
decl_stmt|;
return|return
operator|(
name|__m128d
operator|)
block|{
name|__u
block|,
name|__u
block|}
return|;
block|}
end_function

begin_define
define|#
directive|define
name|_mm_load_pd1
parameter_list|(
name|dp
parameter_list|)
value|_mm_load1_pd(dp)
end_define

begin_comment
comment|/// \brief Loads two double-precision values, in reverse order, from an aligned
end_comment

begin_comment
comment|///    memory location into a 128-bit vector of [2 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVAPD / MOVAPD</c> instruction +
end_comment

begin_comment
comment|/// needed shuffling instructions. In AVX mode, the shuffling may be combined
end_comment

begin_comment
comment|/// with the \c VMOVAPD, resulting in only a \c VPERMILPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __dp
end_comment

begin_comment
comment|///    A 16-byte aligned pointer to an array of double-precision values to be
end_comment

begin_comment
comment|///    loaded in reverse order.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the reversed loaded
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_loadr_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|__dp
parameter_list|)
block|{
name|__m128d
name|__u
init|=
operator|*
operator|(
name|__m128d
operator|*
operator|)
name|__dp
decl_stmt|;
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v2df
operator|)
name|__u
argument_list|,
operator|(
name|__v2df
operator|)
name|__u
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Loads a 128-bit floating-point vector of [2 x double] from an
end_comment

begin_comment
comment|///    unaligned memory location.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVUPD / MOVUPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __dp
end_comment

begin_comment
comment|///    A pointer to a 128-bit memory location. The address of the memory
end_comment

begin_comment
comment|///    location does not have to be aligned.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the loaded values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_loadu_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|__dp
parameter_list|)
block|{
struct|struct
name|__loadu_pd
block|{
name|__m128d
name|__v
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
return|return
operator|(
operator|(
expr|struct
name|__loadu_pd
operator|*
operator|)
name|__dp
operator|)
operator|->
name|__v
return|;
block|}
end_function

begin_comment
comment|/// \brief Loads a 64-bit integer value to the low element of a 128-bit integer
end_comment

begin_comment
comment|///    vector and clears the upper element.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVQ / MOVQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __dp
end_comment

begin_comment
comment|///    A pointer to a 64-bit memory location. The address of the memory
end_comment

begin_comment
comment|///    location does not have to be aligned.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x i64] containing the loaded value.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_loadu_si64
parameter_list|(
name|void
specifier|const
modifier|*
name|__a
parameter_list|)
block|{
struct|struct
name|__loadu_si64
block|{
name|long
name|long
name|__v
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
name|long
name|long
name|__u
init|=
operator|(
operator|(
expr|struct
name|__loadu_si64
operator|*
operator|)
name|__a
operator|)
operator|->
name|__v
decl_stmt|;
return|return
operator|(
name|__m128i
operator|)
block|{
name|__u
block|,
literal|0L
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Loads a 64-bit double-precision value to the low element of a
end_comment

begin_comment
comment|///    128-bit integer vector and clears the upper element.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVSD / MOVSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __dp
end_comment

begin_comment
comment|///    An pointer to a memory location containing a double-precision value.
end_comment

begin_comment
comment|///    The address of the memory location does not have to be aligned.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the loaded value.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_load_sd
parameter_list|(
name|double
specifier|const
modifier|*
name|__dp
parameter_list|)
block|{
struct|struct
name|__mm_load_sd_struct
block|{
name|double
name|__u
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
name|double
name|__u
init|=
operator|(
operator|(
expr|struct
name|__mm_load_sd_struct
operator|*
operator|)
name|__dp
operator|)
operator|->
name|__u
decl_stmt|;
return|return
operator|(
name|__m128d
operator|)
block|{
name|__u
block|,
literal|0
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Loads a double-precision value into the high-order bits of a 128-bit
end_comment

begin_comment
comment|///    vector of [2 x double]. The low-order bits are copied from the low-order
end_comment

begin_comment
comment|///    bits of the first operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVHPD / MOVHPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. \n
end_comment

begin_comment
comment|///    Bits [63:0] are written to bits [63:0] of the result.
end_comment

begin_comment
comment|/// \param __dp
end_comment

begin_comment
comment|///    A pointer to a 64-bit memory location containing a double-precision
end_comment

begin_comment
comment|///    floating-point value that is loaded. The loaded value is written to bits
end_comment

begin_comment
comment|///    [127:64] of the result. The address of the memory location does not have
end_comment

begin_comment
comment|///    to be aligned.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the moved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_loadh_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|double
specifier|const
modifier|*
name|__dp
parameter_list|)
block|{
struct|struct
name|__mm_loadh_pd_struct
block|{
name|double
name|__u
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
name|double
name|__u
init|=
operator|(
operator|(
expr|struct
name|__mm_loadh_pd_struct
operator|*
operator|)
name|__dp
operator|)
operator|->
name|__u
decl_stmt|;
return|return
operator|(
name|__m128d
operator|)
block|{
name|__a
index|[
literal|0
index|]
block|,
name|__u
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Loads a double-precision value into the low-order bits of a 128-bit
end_comment

begin_comment
comment|///    vector of [2 x double]. The high-order bits are copied from the
end_comment

begin_comment
comment|///    high-order bits of the first operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVLPD / MOVLPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. \n
end_comment

begin_comment
comment|///    Bits [127:64] are written to bits [127:64] of the result.
end_comment

begin_comment
comment|/// \param __dp
end_comment

begin_comment
comment|///    A pointer to a 64-bit memory location containing a double-precision
end_comment

begin_comment
comment|///    floating-point value that is loaded. The loaded value is written to bits
end_comment

begin_comment
comment|///    [63:0] of the result. The address of the memory location does not have to
end_comment

begin_comment
comment|///    be aligned.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the moved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_loadl_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|double
specifier|const
modifier|*
name|__dp
parameter_list|)
block|{
struct|struct
name|__mm_loadl_pd_struct
block|{
name|double
name|__u
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
name|double
name|__u
init|=
operator|(
operator|(
expr|struct
name|__mm_loadl_pd_struct
operator|*
operator|)
name|__dp
operator|)
operator|->
name|__u
decl_stmt|;
return|return
operator|(
name|__m128d
operator|)
block|{
name|__u
block|,
name|__a
index|[
literal|1
index|]
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit floating-point vector of [2 x double] with
end_comment

begin_comment
comment|///    unspecified content. This could be used as an argument to another
end_comment

begin_comment
comment|///    intrinsic function where the argument is required but the value is not
end_comment

begin_comment
comment|///    actually used.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic has no corresponding instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns A 128-bit floating-point vector of [2 x double] with unspecified
end_comment

begin_comment
comment|///    content.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_undefined_pd
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_undef128
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit floating-point vector of [2 x double]. The lower
end_comment

begin_comment
comment|///    64 bits of the vector are initialized with the specified double-precision
end_comment

begin_comment
comment|///    floating-point value. The upper 64 bits are set to zero.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVQ / MOVQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __w
end_comment

begin_comment
comment|///    A double-precision floating-point value used to initialize the lower 64
end_comment

begin_comment
comment|///    bits of the result.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit floating-point vector of [2 x double]. The
end_comment

begin_comment
comment|///    lower 64 bits contain the value of the parameter. The upper 64 bits are
end_comment

begin_comment
comment|///    set to zero.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_set_sd
parameter_list|(
name|double
name|__w
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
block|{
name|__w
block|,
literal|0
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit floating-point vector of [2 x double], with each
end_comment

begin_comment
comment|///    of the two double-precision floating-point vector elements set to the
end_comment

begin_comment
comment|///    specified double-precision floating-point value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVDDUP / MOVLHPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __w
end_comment

begin_comment
comment|///    A double-precision floating-point value used to initialize each vector
end_comment

begin_comment
comment|///    element of the result.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit floating-point vector of [2 x double].
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_set1_pd
parameter_list|(
name|double
name|__w
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
block|{
name|__w
block|,
name|__w
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit floating-point vector of [2 x double], with each
end_comment

begin_comment
comment|///    of the two double-precision floating-point vector elements set to the
end_comment

begin_comment
comment|///    specified double-precision floating-point value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVDDUP / MOVLHPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __w
end_comment

begin_comment
comment|///    A double-precision floating-point value used to initialize each vector
end_comment

begin_comment
comment|///    element of the result.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit floating-point vector of [2 x double].
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_set_pd1
parameter_list|(
name|double
name|__w
parameter_list|)
block|{
return|return
name|_mm_set1_pd
argument_list|(
name|__w
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit floating-point vector of [2 x double]
end_comment

begin_comment
comment|///    initialized with the specified double-precision floating-point values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VUNPCKLPD / UNPCKLPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __w
end_comment

begin_comment
comment|///    A double-precision floating-point value used to initialize the upper 64
end_comment

begin_comment
comment|///    bits of the result.
end_comment

begin_comment
comment|/// \param __x
end_comment

begin_comment
comment|///    A double-precision floating-point value used to initialize the lower 64
end_comment

begin_comment
comment|///    bits of the result.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit floating-point vector of [2 x double].
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_set_pd
parameter_list|(
name|double
name|__w
parameter_list|,
name|double
name|__x
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
block|{
name|__x
block|,
name|__w
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit floating-point vector of [2 x double],
end_comment

begin_comment
comment|///    initialized in reverse order with the specified double-precision
end_comment

begin_comment
comment|///    floating-point values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VUNPCKLPD / UNPCKLPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __w
end_comment

begin_comment
comment|///    A double-precision floating-point value used to initialize the lower 64
end_comment

begin_comment
comment|///    bits of the result.
end_comment

begin_comment
comment|/// \param __x
end_comment

begin_comment
comment|///    A double-precision floating-point value used to initialize the upper 64
end_comment

begin_comment
comment|///    bits of the result.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit floating-point vector of [2 x double].
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_setr_pd
parameter_list|(
name|double
name|__w
parameter_list|,
name|double
name|__x
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
block|{
name|__w
block|,
name|__x
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit floating-point vector of [2 x double]
end_comment

begin_comment
comment|///    initialized to zero.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VXORPS / XORPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns An initialized 128-bit floating-point vector of [2 x double] with
end_comment

begin_comment
comment|///    all elements set to zero.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_setzero_pd
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
block|{
literal|0
block|,
literal|0
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit floating-point vector of [2 x double]. The lower
end_comment

begin_comment
comment|///    64 bits are set to the lower 64 bits of the second parameter. The upper
end_comment

begin_comment
comment|///    64 bits are set to the upper 64 bits of the first parameter.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VBLENDPD / BLENDPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The upper 64 bits are written to the
end_comment

begin_comment
comment|///    upper 64 bits of the result.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower 64 bits are written to the
end_comment

begin_comment
comment|///    lower 64 bits of the result.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the moved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_move_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
block|{
name|__b
index|[
literal|0
index|]
block|,
name|__a
index|[
literal|1
index|]
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Stores the lower 64 bits of a 128-bit vector of [2 x double] to a
end_comment

begin_comment
comment|///    memory location.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVSD / MOVSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __dp
end_comment

begin_comment
comment|///    A pointer to a 64-bit memory location.
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing the value to be stored.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_store_sd
parameter_list|(
name|double
modifier|*
name|__dp
parameter_list|,
name|__m128d
name|__a
parameter_list|)
block|{
struct|struct
name|__mm_store_sd_struct
block|{
name|double
name|__u
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
operator|(
operator|(
expr|struct
name|__mm_store_sd_struct
operator|*
operator|)
name|__dp
operator|)
operator|->
name|__u
operator|=
name|__a
index|[
literal|0
index|]
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_store_pd
parameter_list|(
name|double
modifier|*
name|__dp
parameter_list|,
name|__m128d
name|__a
parameter_list|)
block|{
operator|*
operator|(
name|__m128d
operator|*
operator|)
name|__dp
operator|=
name|__a
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_store1_pd
parameter_list|(
name|double
modifier|*
name|__dp
parameter_list|,
name|__m128d
name|__a
parameter_list|)
block|{
name|__a
operator|=
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|_mm_store_pd
argument_list|(
name|__dp
argument_list|,
name|__a
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Stores a 128-bit vector of [2 x double] into an aligned memory
end_comment

begin_comment
comment|///    location.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVAPD / MOVAPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __dp
end_comment

begin_comment
comment|///    A pointer to a 128-bit memory location. The address of the memory
end_comment

begin_comment
comment|///    location has to be 16-byte aligned.
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing the values to be stored.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_store_pd1
parameter_list|(
name|double
modifier|*
name|__dp
parameter_list|,
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|_mm_store1_pd
argument_list|(
name|__dp
argument_list|,
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Stores a 128-bit vector of [2 x double] into an unaligned memory
end_comment

begin_comment
comment|///    location.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVUPD / MOVUPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __dp
end_comment

begin_comment
comment|///    A pointer to a 128-bit memory location. The address of the memory
end_comment

begin_comment
comment|///    location does not have to be aligned.
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing the values to be stored.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_storeu_pd
parameter_list|(
name|double
modifier|*
name|__dp
parameter_list|,
name|__m128d
name|__a
parameter_list|)
block|{
struct|struct
name|__storeu_pd
block|{
name|__m128d
name|__v
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
operator|(
operator|(
expr|struct
name|__storeu_pd
operator|*
operator|)
name|__dp
operator|)
operator|->
name|__v
operator|=
name|__a
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Stores two double-precision values, in reverse order, from a 128-bit
end_comment

begin_comment
comment|///    vector of [2 x double] to a 16-byte aligned memory location.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to a shuffling instruction followed by a
end_comment

begin_comment
comment|///<c> VMOVAPD / MOVAPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __dp
end_comment

begin_comment
comment|///    A pointer to a 16-byte aligned memory location that can store two
end_comment

begin_comment
comment|///    double-precision values.
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing the values to be reversed and
end_comment

begin_comment
comment|///    stored.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_storer_pd
parameter_list|(
name|double
modifier|*
name|__dp
parameter_list|,
name|__m128d
name|__a
parameter_list|)
block|{
name|__a
operator|=
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
operator|*
operator|(
name|__m128d
operator|*
operator|)
name|__dp
operator|=
name|__a
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Stores the upper 64 bits of a 128-bit vector of [2 x double] to a
end_comment

begin_comment
comment|///    memory location.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVHPD / MOVHPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __dp
end_comment

begin_comment
comment|///    A pointer to a 64-bit memory location.
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing the value to be stored.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_storeh_pd
parameter_list|(
name|double
modifier|*
name|__dp
parameter_list|,
name|__m128d
name|__a
parameter_list|)
block|{
struct|struct
name|__mm_storeh_pd_struct
block|{
name|double
name|__u
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
operator|(
operator|(
expr|struct
name|__mm_storeh_pd_struct
operator|*
operator|)
name|__dp
operator|)
operator|->
name|__u
operator|=
name|__a
index|[
literal|1
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Stores the lower 64 bits of a 128-bit vector of [2 x double] to a
end_comment

begin_comment
comment|///    memory location.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVLPD / MOVLPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __dp
end_comment

begin_comment
comment|///    A pointer to a 64-bit memory location.
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing the value to be stored.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_storel_pd
parameter_list|(
name|double
modifier|*
name|__dp
parameter_list|,
name|__m128d
name|__a
parameter_list|)
block|{
struct|struct
name|__mm_storeh_pd_struct
block|{
name|double
name|__u
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
operator|(
operator|(
expr|struct
name|__mm_storeh_pd_struct
operator|*
operator|)
name|__dp
operator|)
operator|->
name|__u
operator|=
name|__a
index|[
literal|0
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Adds the corresponding elements of two 128-bit vectors of [16 x i8],
end_comment

begin_comment
comment|///    saving the lower 8 bits of each sum in the corresponding element of a
end_comment

begin_comment
comment|///    128-bit result vector of [16 x i8]. The integer elements of both
end_comment

begin_comment
comment|///    parameters can be either signed or unsigned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPADDB / PADDB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [16 x i8] containing the sums of both
end_comment

begin_comment
comment|///    parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_add_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v16qu
operator|)
name|__a
operator|+
operator|(
name|__v16qu
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds the corresponding elements of two 128-bit vectors of [8 x i16],
end_comment

begin_comment
comment|///    saving the lower 16 bits of each sum in the corresponding element of a
end_comment

begin_comment
comment|///    128-bit result vector of [8 x i16]. The integer elements of both
end_comment

begin_comment
comment|///    parameters can be either signed or unsigned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPADDW / PADDW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [8 x i16] containing the sums of both
end_comment

begin_comment
comment|///    parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_add_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v8hu
operator|)
name|__a
operator|+
operator|(
name|__v8hu
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds the corresponding elements of two 128-bit vectors of [4 x i32],
end_comment

begin_comment
comment|///    saving the lower 32 bits of each sum in the corresponding element of a
end_comment

begin_comment
comment|///    128-bit result vector of [4 x i32]. The integer elements of both
end_comment

begin_comment
comment|///    parameters can be either signed or unsigned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPADDD / PADDD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x i32].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x i32].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x i32] containing the sums of both
end_comment

begin_comment
comment|///    parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_add_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v4su
operator|)
name|__a
operator|+
operator|(
name|__v4su
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds two signed or unsigned 64-bit integer values, returning the
end_comment

begin_comment
comment|///    lower 64 bits of the sum.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> PADDQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit integer.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit integer.
end_comment

begin_comment
comment|/// \returns A 64-bit integer containing the sum of both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_add_si64
parameter_list|(
name|__m64
name|__a
parameter_list|,
name|__m64
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_paddq
argument_list|(
operator|(
name|__v1di
operator|)
name|__a
argument_list|,
operator|(
name|__v1di
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds the corresponding elements of two 128-bit vectors of [2 x i64],
end_comment

begin_comment
comment|///    saving the lower 64 bits of each sum in the corresponding element of a
end_comment

begin_comment
comment|///    128-bit result vector of [2 x i64]. The integer elements of both
end_comment

begin_comment
comment|///    parameters can be either signed or unsigned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPADDQ / PADDQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x i64].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x i64].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x i64] containing the sums of both
end_comment

begin_comment
comment|///    parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_add_epi64
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v2du
operator|)
name|__a
operator|+
operator|(
name|__v2du
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds, with saturation, the corresponding elements of two 128-bit
end_comment

begin_comment
comment|///    signed [16 x i8] vectors, saving each sum in the corresponding element of
end_comment

begin_comment
comment|///    a 128-bit result vector of [16 x i8]. Positive sums greater than 7Fh are
end_comment

begin_comment
comment|///    saturated to 7Fh. Negative sums less than 80h are saturated to 80h.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPADDSB / PADDSB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit signed [16 x i8] vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit signed [16 x i8] vector.
end_comment

begin_comment
comment|/// \returns A 128-bit signed [16 x i8] vector containing the saturated sums of
end_comment

begin_comment
comment|///    both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_adds_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_paddsb128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|,
operator|(
name|__v16qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds, with saturation, the corresponding elements of two 128-bit
end_comment

begin_comment
comment|///    signed [8 x i16] vectors, saving each sum in the corresponding element of
end_comment

begin_comment
comment|///    a 128-bit result vector of [8 x i16]. Positive sums greater than 7FFFh
end_comment

begin_comment
comment|///    are saturated to 7FFFh. Negative sums less than 8000h are saturated to
end_comment

begin_comment
comment|///    8000h.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPADDSW / PADDSW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit signed [8 x i16] vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit signed [8 x i16] vector.
end_comment

begin_comment
comment|/// \returns A 128-bit signed [8 x i16] vector containing the saturated sums of
end_comment

begin_comment
comment|///    both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_adds_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_paddsw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds, with saturation, the corresponding elements of two 128-bit
end_comment

begin_comment
comment|///    unsigned [16 x i8] vectors, saving each sum in the corresponding element
end_comment

begin_comment
comment|///    of a 128-bit result vector of [16 x i8]. Positive sums greater than FFh
end_comment

begin_comment
comment|///    are saturated to FFh. Negative sums are saturated to 00h.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPADDUSB / PADDUSB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit unsigned [16 x i8] vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit unsigned [16 x i8] vector.
end_comment

begin_comment
comment|/// \returns A 128-bit unsigned [16 x i8] vector containing the saturated sums
end_comment

begin_comment
comment|///    of both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_adds_epu8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_paddusb128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|,
operator|(
name|__v16qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds, with saturation, the corresponding elements of two 128-bit
end_comment

begin_comment
comment|///    unsigned [8 x i16] vectors, saving each sum in the corresponding element
end_comment

begin_comment
comment|///    of a 128-bit result vector of [8 x i16]. Positive sums greater than FFFFh
end_comment

begin_comment
comment|///    are saturated to FFFFh. Negative sums are saturated to 0000h.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPADDUSB / PADDUSB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit unsigned [8 x i16] vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit unsigned [8 x i16] vector.
end_comment

begin_comment
comment|/// \returns A 128-bit unsigned [8 x i16] vector containing the saturated sums
end_comment

begin_comment
comment|///    of both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_adds_epu16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_paddusw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Computes the rounded avarages of corresponding elements of two
end_comment

begin_comment
comment|///    128-bit unsigned [16 x i8] vectors, saving each result in the
end_comment

begin_comment
comment|///    corresponding element of a 128-bit result vector of [16 x i8].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPAVGB / PAVGB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit unsigned [16 x i8] vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit unsigned [16 x i8] vector.
end_comment

begin_comment
comment|/// \returns A 128-bit unsigned [16 x i8] vector containing the rounded
end_comment

begin_comment
comment|///    averages of both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_avg_epu8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pavgb128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|,
operator|(
name|__v16qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Computes the rounded avarages of corresponding elements of two
end_comment

begin_comment
comment|///    128-bit unsigned [8 x i16] vectors, saving each result in the
end_comment

begin_comment
comment|///    corresponding element of a 128-bit result vector of [8 x i16].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPAVGW / PAVGW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit unsigned [8 x i16] vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit unsigned [8 x i16] vector.
end_comment

begin_comment
comment|/// \returns A 128-bit unsigned [8 x i16] vector containing the rounded
end_comment

begin_comment
comment|///    averages of both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_avg_epu16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pavgw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Multiplies the corresponding elements of two 128-bit signed [8 x i16]
end_comment

begin_comment
comment|///    vectors, producing eight intermediate 32-bit signed integer products, and
end_comment

begin_comment
comment|///    adds the consecutive pairs of 32-bit products to form a 128-bit signed
end_comment

begin_comment
comment|///    [4 x i32] vector. For example, bits [15:0] of both parameters are
end_comment

begin_comment
comment|///    multiplied producing a 32-bit product, bits [31:16] of both parameters
end_comment

begin_comment
comment|///    are multiplied producing a 32-bit product, and the sum of those two
end_comment

begin_comment
comment|///    products becomes bits [31:0] of the result.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMADDWD / PMADDWD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit signed [8 x i16] vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit signed [8 x i16] vector.
end_comment

begin_comment
comment|/// \returns A 128-bit signed [4 x i32] vector containing the sums of products
end_comment

begin_comment
comment|///    of both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_madd_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmaddwd128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares corresponding elements of two 128-bit signed [8 x i16]
end_comment

begin_comment
comment|///    vectors, saving the greater value from each comparison in the
end_comment

begin_comment
comment|///    corresponding element of a 128-bit result vector of [8 x i16].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMAXSW / PMAXSW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit signed [8 x i16] vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit signed [8 x i16] vector.
end_comment

begin_comment
comment|/// \returns A 128-bit signed [8 x i16] vector containing the greater value of
end_comment

begin_comment
comment|///    each comparison.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_max_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmaxsw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares corresponding elements of two 128-bit unsigned [16 x i8]
end_comment

begin_comment
comment|///    vectors, saving the greater value from each comparison in the
end_comment

begin_comment
comment|///    corresponding element of a 128-bit result vector of [16 x i8].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMAXUB / PMAXUB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit unsigned [16 x i8] vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit unsigned [16 x i8] vector.
end_comment

begin_comment
comment|/// \returns A 128-bit unsigned [16 x i8] vector containing the greater value of
end_comment

begin_comment
comment|///    each comparison.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_max_epu8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmaxub128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|,
operator|(
name|__v16qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares corresponding elements of two 128-bit signed [8 x i16]
end_comment

begin_comment
comment|///    vectors, saving the smaller value from each comparison in the
end_comment

begin_comment
comment|///    corresponding element of a 128-bit result vector of [8 x i16].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMINSW / PMINSW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit signed [8 x i16] vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit signed [8 x i16] vector.
end_comment

begin_comment
comment|/// \returns A 128-bit signed [8 x i16] vector containing the smaller value of
end_comment

begin_comment
comment|///    each comparison.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_min_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pminsw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares corresponding elements of two 128-bit unsigned [16 x i8]
end_comment

begin_comment
comment|///    vectors, saving the smaller value from each comparison in the
end_comment

begin_comment
comment|///    corresponding element of a 128-bit result vector of [16 x i8].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMINUB / PMINUB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit unsigned [16 x i8] vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit unsigned [16 x i8] vector.
end_comment

begin_comment
comment|/// \returns A 128-bit unsigned [16 x i8] vector containing the smaller value of
end_comment

begin_comment
comment|///    each comparison.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_min_epu8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pminub128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|,
operator|(
name|__v16qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Multiplies the corresponding elements of two signed [8 x i16]
end_comment

begin_comment
comment|///    vectors, saving the upper 16 bits of each 32-bit product in the
end_comment

begin_comment
comment|///    corresponding element of a 128-bit signed [8 x i16] result vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMULHW / PMULHW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit signed [8 x i16] vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit signed [8 x i16] vector.
end_comment

begin_comment
comment|/// \returns A 128-bit signed [8 x i16] vector containing the upper 16 bits of
end_comment

begin_comment
comment|///    each of the eight 32-bit products.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_mulhi_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmulhw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Multiplies the corresponding elements of two unsigned [8 x i16]
end_comment

begin_comment
comment|///    vectors, saving the upper 16 bits of each 32-bit product in the
end_comment

begin_comment
comment|///    corresponding element of a 128-bit unsigned [8 x i16] result vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMULHUW / PMULHUW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit unsigned [8 x i16] vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit unsigned [8 x i16] vector.
end_comment

begin_comment
comment|/// \returns A 128-bit unsigned [8 x i16] vector containing the upper 16 bits
end_comment

begin_comment
comment|///    of each of the eight 32-bit products.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_mulhi_epu16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmulhuw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Multiplies the corresponding elements of two signed [8 x i16]
end_comment

begin_comment
comment|///    vectors, saving the lower 16 bits of each 32-bit product in the
end_comment

begin_comment
comment|///    corresponding element of a 128-bit signed [8 x i16] result vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMULLW / PMULLW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit signed [8 x i16] vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit signed [8 x i16] vector.
end_comment

begin_comment
comment|/// \returns A 128-bit signed [8 x i16] vector containing the lower 16 bits of
end_comment

begin_comment
comment|///    each of the eight 32-bit products.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_mullo_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v8hu
operator|)
name|__a
operator|*
operator|(
name|__v8hu
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Multiplies 32-bit unsigned integer values contained in the lower bits
end_comment

begin_comment
comment|///    of the two 64-bit integer vectors and returns the 64-bit unsigned
end_comment

begin_comment
comment|///    product.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> PMULUDQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit integer containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit integer containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the product of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_mul_su32
parameter_list|(
name|__m64
name|__a
parameter_list|,
name|__m64
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_pmuludq
argument_list|(
operator|(
name|__v2si
operator|)
name|__a
argument_list|,
operator|(
name|__v2si
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Multiplies 32-bit unsigned integer values contained in the lower
end_comment

begin_comment
comment|///    bits of the corresponding elements of two [2 x i64] vectors, and returns
end_comment

begin_comment
comment|///    the 64-bit products in the corresponding elements of a [2 x i64] vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMULUDQ / PMULUDQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A [2 x i64] vector containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A [2 x i64] vector containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A [2 x i64] vector containing the product of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_mul_epu32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_pmuludq128
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
operator|(
name|__v4si
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Computes the absolute differences of corresponding 8-bit integer
end_comment

begin_comment
comment|///    values in two 128-bit vectors. Sums the first 8 absolute differences, and
end_comment

begin_comment
comment|///    separately sums the second 8 absolute differences. Packs these two
end_comment

begin_comment
comment|///    unsigned 16-bit integer sums into the upper and lower elements of a
end_comment

begin_comment
comment|///    [2 x i64] vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSADBW / PSADBW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A [2 x i64] vector containing the sums of the sets of absolute
end_comment

begin_comment
comment|///    differences between both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sad_epu8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_psadbw128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|,
operator|(
name|__v16qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts the corresponding 8-bit integer values in the operands.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSUBB / PSUBB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the minuends.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the differences of the values
end_comment

begin_comment
comment|///    in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sub_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v16qu
operator|)
name|__a
operator|-
operator|(
name|__v16qu
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts the corresponding 16-bit integer values in the operands.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSUBW / PSUBW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the minuends.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the differences of the values
end_comment

begin_comment
comment|///    in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sub_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v8hu
operator|)
name|__a
operator|-
operator|(
name|__v8hu
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts the corresponding 32-bit integer values in the operands.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSUBD / PSUBD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the minuends.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the differences of the values
end_comment

begin_comment
comment|///    in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sub_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v4su
operator|)
name|__a
operator|-
operator|(
name|__v4su
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts signed or unsigned 64-bit integer values and writes the
end_comment

begin_comment
comment|///    difference to the corresponding bits in the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> PSUBQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit integer vector containing the minuend.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit integer vector containing the subtrahend.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the difference of the values in
end_comment

begin_comment
comment|///    the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_sub_si64
parameter_list|(
name|__m64
name|__a
parameter_list|,
name|__m64
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psubq
argument_list|(
operator|(
name|__v1di
operator|)
name|__a
argument_list|,
operator|(
name|__v1di
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts the corresponding elements of two [2 x i64] vectors.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSUBQ / PSUBQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the minuends.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the differences of the values
end_comment

begin_comment
comment|///    in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sub_epi64
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v2du
operator|)
name|__a
operator|-
operator|(
name|__v2du
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts corresponding 8-bit signed integer values in the input and
end_comment

begin_comment
comment|///    returns the differences in the corresponding bytes in the destination.
end_comment

begin_comment
comment|///    Differences greater than 7Fh are saturated to 7Fh, and differences less
end_comment

begin_comment
comment|///    than 80h are saturated to 80h.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSUBSB / PSUBSB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the minuends.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the differences of the values
end_comment

begin_comment
comment|///    in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_subs_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psubsb128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|,
operator|(
name|__v16qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts corresponding 16-bit signed integer values in the input and
end_comment

begin_comment
comment|///    returns the differences in the corresponding bytes in the destination.
end_comment

begin_comment
comment|///    Differences greater than 7FFFh are saturated to 7FFFh, and values less
end_comment

begin_comment
comment|///    than 8000h are saturated to 8000h.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSUBSW / PSUBSW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the minuends.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the differences of the values
end_comment

begin_comment
comment|///    in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_subs_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psubsw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts corresponding 8-bit unsigned integer values in the input
end_comment

begin_comment
comment|///    and returns the differences in the corresponding bytes in the
end_comment

begin_comment
comment|///    destination. Differences less than 00h are saturated to 00h.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSUBUSB / PSUBUSB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the minuends.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the unsigned integer
end_comment

begin_comment
comment|///    differences of the values in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_subs_epu8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psubusb128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|,
operator|(
name|__v16qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts corresponding 16-bit unsigned integer values in the input
end_comment

begin_comment
comment|///    and returns the differences in the corresponding bytes in the
end_comment

begin_comment
comment|///    destination. Differences less than 0000h are saturated to 0000h.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSUBUSW / PSUBUSW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the minuends.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the unsigned integer
end_comment

begin_comment
comment|///    differences of the values in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_subs_epu16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psubusw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise AND of two 128-bit integer vectors.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPAND / PAND</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the bitwise AND of the values
end_comment

begin_comment
comment|///    in both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_and_si128
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v2du
operator|)
name|__a
operator|&
operator|(
name|__v2du
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise AND of two 128-bit integer vectors, using the
end_comment

begin_comment
comment|///    one's complement of the values contained in the first source operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPANDN / PANDN</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector containing the left source operand. The one's complement
end_comment

begin_comment
comment|///    of this value is used in the bitwise AND.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector containing the right source operand.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the bitwise AND of the one's
end_comment

begin_comment
comment|///    complement of the first operand and the values in the second operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_andnot_si128
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|~
operator|(
name|__v2du
operator|)
name|__a
operator|&
operator|(
name|__v2du
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise OR of two 128-bit integer vectors.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPOR / POR</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the bitwise OR of the values
end_comment

begin_comment
comment|///    in both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_or_si128
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v2du
operator|)
name|__a
operator||
operator|(
name|__v2du
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise exclusive OR of two 128-bit integer vectors.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPXOR / PXOR</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the bitwise exclusive OR of the
end_comment

begin_comment
comment|///    values in both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_xor_si128
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v2du
operator|)
name|__a
operator|^
operator|(
name|__v2du
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Left-shifts the 128-bit integer vector operand by the specified
end_comment

begin_comment
comment|///    number of bytes. Low-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// __m128i _mm_slli_si128(__m128i a, const int imm);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSLLDQ / PSLLDQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param imm
end_comment

begin_comment
comment|///    An immediate value specifying the number of bytes to left-shift operand
end_comment

begin_comment
comment|///    \a a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the left-shifted value.
end_comment

begin_define
define|#
directive|define
name|_mm_slli_si128
parameter_list|(
name|a
parameter_list|,
name|imm
parameter_list|)
value|__extension__ ({                              \   (__m128i)__builtin_shufflevector(                                          \                                  (__v16qi)_mm_setzero_si128(),               \                                  (__v16qi)(__m128i)(a),                      \                                  ((char)(imm)&0xF0) ?  0 : 16 - (char)(imm), \                                  ((char)(imm)&0xF0) ?  1 : 17 - (char)(imm), \                                  ((char)(imm)&0xF0) ?  2 : 18 - (char)(imm), \                                  ((char)(imm)&0xF0) ?  3 : 19 - (char)(imm), \                                  ((char)(imm)&0xF0) ?  4 : 20 - (char)(imm), \                                  ((char)(imm)&0xF0) ?  5 : 21 - (char)(imm), \                                  ((char)(imm)&0xF0) ?  6 : 22 - (char)(imm), \                                  ((char)(imm)&0xF0) ?  7 : 23 - (char)(imm), \                                  ((char)(imm)&0xF0) ?  8 : 24 - (char)(imm), \                                  ((char)(imm)&0xF0) ?  9 : 25 - (char)(imm), \                                  ((char)(imm)&0xF0) ? 10 : 26 - (char)(imm), \                                  ((char)(imm)&0xF0) ? 11 : 27 - (char)(imm), \                                  ((char)(imm)&0xF0) ? 12 : 28 - (char)(imm), \                                  ((char)(imm)&0xF0) ? 13 : 29 - (char)(imm), \                                  ((char)(imm)&0xF0) ? 14 : 30 - (char)(imm), \                                  ((char)(imm)&0xF0) ? 15 : 31 - (char)(imm)); })
end_define

begin_define
define|#
directive|define
name|_mm_bslli_si128
parameter_list|(
name|a
parameter_list|,
name|imm
parameter_list|)
define|\
value|_mm_slli_si128((a), (imm))
end_define

begin_comment
comment|/// \brief Left-shifts each 16-bit value in the 128-bit integer vector operand
end_comment

begin_comment
comment|///    by the specified number of bits. Low-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSLLW / PSLLW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    An integer value specifying the number of bits to left-shift each value
end_comment

begin_comment
comment|///    in operand \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the left-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_slli_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psllwi128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Left-shifts each 16-bit value in the 128-bit integer vector operand
end_comment

begin_comment
comment|///    by the specified number of bits. Low-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSLLW / PSLLW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 128-bit integer vector in which bits [63:0] specify the number of bits
end_comment

begin_comment
comment|///    to left-shift each value in operand \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the left-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sll_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psllw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Left-shifts each 32-bit value in the 128-bit integer vector operand
end_comment

begin_comment
comment|///    by the specified number of bits. Low-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSLLD / PSLLD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    An integer value specifying the number of bits to left-shift each value
end_comment

begin_comment
comment|///    in operand \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the left-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_slli_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pslldi128
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Left-shifts each 32-bit value in the 128-bit integer vector operand
end_comment

begin_comment
comment|///    by the specified number of bits. Low-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSLLD / PSLLD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 128-bit integer vector in which bits [63:0] specify the number of bits
end_comment

begin_comment
comment|///    to left-shift each value in operand \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the left-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sll_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pslld128
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
operator|(
name|__v4si
operator|)
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Left-shifts each 64-bit value in the 128-bit integer vector operand
end_comment

begin_comment
comment|///    by the specified number of bits. Low-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSLLQ / PSLLQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    An integer value specifying the number of bits to left-shift each value
end_comment

begin_comment
comment|///    in operand \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the left-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_slli_epi64
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
name|__builtin_ia32_psllqi128
argument_list|(
operator|(
name|__v2di
operator|)
name|__a
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Left-shifts each 64-bit value in the 128-bit integer vector operand
end_comment

begin_comment
comment|///    by the specified number of bits. Low-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSLLQ / PSLLQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 128-bit integer vector in which bits [63:0] specify the number of bits
end_comment

begin_comment
comment|///    to left-shift each value in operand \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the left-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sll_epi64
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__count
parameter_list|)
block|{
return|return
name|__builtin_ia32_psllq128
argument_list|(
operator|(
name|__v2di
operator|)
name|__a
argument_list|,
operator|(
name|__v2di
operator|)
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each 16-bit value in the 128-bit integer vector operand
end_comment

begin_comment
comment|///    by the specified number of bits. High-order bits are filled with the sign
end_comment

begin_comment
comment|///    bit of the initial value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSRAW / PSRAW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    An integer value specifying the number of bits to right-shift each value
end_comment

begin_comment
comment|///    in operand \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_srai_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psrawi128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each 16-bit value in the 128-bit integer vector operand
end_comment

begin_comment
comment|///    by the specified number of bits. High-order bits are filled with the sign
end_comment

begin_comment
comment|///    bit of the initial value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSRAW / PSRAW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 128-bit integer vector in which bits [63:0] specify the number of bits
end_comment

begin_comment
comment|///    to right-shift each value in operand \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sra_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psraw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each 32-bit value in the 128-bit integer vector operand
end_comment

begin_comment
comment|///    by the specified number of bits. High-order bits are filled with the sign
end_comment

begin_comment
comment|///    bit of the initial value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSRAD / PSRAD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    An integer value specifying the number of bits to right-shift each value
end_comment

begin_comment
comment|///    in operand \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_srai_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psradi128
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each 32-bit value in the 128-bit integer vector operand
end_comment

begin_comment
comment|///    by the specified number of bits. High-order bits are filled with the sign
end_comment

begin_comment
comment|///    bit of the initial value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSRAD / PSRAD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 128-bit integer vector in which bits [63:0] specify the number of bits
end_comment

begin_comment
comment|///    to right-shift each value in operand \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sra_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psrad128
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
operator|(
name|__v4si
operator|)
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts the 128-bit integer vector operand by the specified
end_comment

begin_comment
comment|///    number of bytes. High-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// __m128i _mm_srli_si128(__m128i a, const int imm);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSRLDQ / PSRLDQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param imm
end_comment

begin_comment
comment|///    An immediate value specifying the number of bytes to right-shift operand
end_comment

begin_comment
comment|///    \a a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted value.
end_comment

begin_define
define|#
directive|define
name|_mm_srli_si128
parameter_list|(
name|a
parameter_list|,
name|imm
parameter_list|)
value|__extension__ ({                              \   (__m128i)__builtin_shufflevector(                                          \                                  (__v16qi)(__m128i)(a),                      \                                  (__v16qi)_mm_setzero_si128(),               \                                  ((char)(imm)&0xF0) ? 16 : (char)(imm) + 0,  \                                  ((char)(imm)&0xF0) ? 17 : (char)(imm) + 1,  \                                  ((char)(imm)&0xF0) ? 18 : (char)(imm) + 2,  \                                  ((char)(imm)&0xF0) ? 19 : (char)(imm) + 3,  \                                  ((char)(imm)&0xF0) ? 20 : (char)(imm) + 4,  \                                  ((char)(imm)&0xF0) ? 21 : (char)(imm) + 5,  \                                  ((char)(imm)&0xF0) ? 22 : (char)(imm) + 6,  \                                  ((char)(imm)&0xF0) ? 23 : (char)(imm) + 7,  \                                  ((char)(imm)&0xF0) ? 24 : (char)(imm) + 8,  \                                  ((char)(imm)&0xF0) ? 25 : (char)(imm) + 9,  \                                  ((char)(imm)&0xF0) ? 26 : (char)(imm) + 10, \                                  ((char)(imm)&0xF0) ? 27 : (char)(imm) + 11, \                                  ((char)(imm)&0xF0) ? 28 : (char)(imm) + 12, \                                  ((char)(imm)&0xF0) ? 29 : (char)(imm) + 13, \                                  ((char)(imm)&0xF0) ? 30 : (char)(imm) + 14, \                                  ((char)(imm)&0xF0) ? 31 : (char)(imm) + 15); })
end_define

begin_define
define|#
directive|define
name|_mm_bsrli_si128
parameter_list|(
name|a
parameter_list|,
name|imm
parameter_list|)
define|\
value|_mm_srli_si128((a), (imm))
end_define

begin_comment
comment|/// \brief Right-shifts each of 16-bit values in the 128-bit integer vector
end_comment

begin_comment
comment|///    operand by the specified number of bits. High-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSRLW / PSRLW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    An integer value specifying the number of bits to right-shift each value
end_comment

begin_comment
comment|///    in operand \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_srli_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psrlwi128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each of 16-bit values in the 128-bit integer vector
end_comment

begin_comment
comment|///    operand by the specified number of bits. High-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSRLW / PSRLW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 128-bit integer vector in which bits [63:0] specify the number of bits
end_comment

begin_comment
comment|///    to right-shift each value in operand \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_srl_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psrlw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each of 32-bit values in the 128-bit integer vector
end_comment

begin_comment
comment|///    operand by the specified number of bits. High-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSRLD / PSRLD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    An integer value specifying the number of bits to right-shift each value
end_comment

begin_comment
comment|///    in operand \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_srli_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psrldi128
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each of 32-bit values in the 128-bit integer vector
end_comment

begin_comment
comment|///    operand by the specified number of bits. High-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSRLD / PSRLD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 128-bit integer vector in which bits [63:0] specify the number of bits
end_comment

begin_comment
comment|///    to right-shift each value in operand \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_srl_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psrld128
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
operator|(
name|__v4si
operator|)
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each of 64-bit values in the 128-bit integer vector
end_comment

begin_comment
comment|///    operand by the specified number of bits. High-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSRLQ / PSRLQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    An integer value specifying the number of bits to right-shift each value
end_comment

begin_comment
comment|///    in operand \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_srli_epi64
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
name|__builtin_ia32_psrlqi128
argument_list|(
operator|(
name|__v2di
operator|)
name|__a
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each of 64-bit values in the 128-bit integer vector
end_comment

begin_comment
comment|///    operand by the specified number of bits. High-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSRLQ / PSRLQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 128-bit integer vector in which bits [63:0] specify the number of bits
end_comment

begin_comment
comment|///    to right-shift each value in operand \a __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_srl_epi64
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__count
parameter_list|)
block|{
return|return
name|__builtin_ia32_psrlq128
argument_list|(
operator|(
name|__v2di
operator|)
name|__a
argument_list|,
operator|(
name|__v2di
operator|)
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding 8-bit values of the 128-bit
end_comment

begin_comment
comment|///    integer vectors for equality. Each comparison yields 0h for false, FFh
end_comment

begin_comment
comment|///    for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPEQB / PCMPEQB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cmpeq_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
operator|==
operator|(
name|__v16qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding 16-bit values of the 128-bit
end_comment

begin_comment
comment|///    integer vectors for equality. Each comparison yields 0h for false, FFFFh
end_comment

begin_comment
comment|///    for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPEQW / PCMPEQW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cmpeq_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
operator|==
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding 32-bit values of the 128-bit
end_comment

begin_comment
comment|///    integer vectors for equality. Each comparison yields 0h for false,
end_comment

begin_comment
comment|///    FFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPEQD / PCMPEQD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cmpeq_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
operator|==
operator|(
name|__v4si
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding signed 8-bit values of the 128-bit
end_comment

begin_comment
comment|///    integer vectors to determine if the values in the first operand are
end_comment

begin_comment
comment|///    greater than those in the second operand. Each comparison yields 0h for
end_comment

begin_comment
comment|///    false, FFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPGTB / PCMPGTB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cmpgt_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|/* This function always performs a signed comparison, but __v16qi is a char      which may be signed or unsigned, so use __v16qs. */
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v16qs
operator|)
name|__a
operator|>
operator|(
name|__v16qs
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding signed 16-bit values of the
end_comment

begin_comment
comment|///    128-bit integer vectors to determine if the values in the first operand
end_comment

begin_comment
comment|///    are greater than those in the second operand. Each comparison yields 0h
end_comment

begin_comment
comment|///    for false, FFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPGTW / PCMPGTW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cmpgt_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
operator|>
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding signed 32-bit values of the
end_comment

begin_comment
comment|///    128-bit integer vectors to determine if the values in the first operand
end_comment

begin_comment
comment|///    are greater than those in the second operand. Each comparison yields 0h
end_comment

begin_comment
comment|///    for false, FFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPGTD / PCMPGTD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cmpgt_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
operator|>
operator|(
name|__v4si
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding signed 8-bit values of the 128-bit
end_comment

begin_comment
comment|///    integer vectors to determine if the values in the first operand are less
end_comment

begin_comment
comment|///    than those in the second operand. Each comparison yields 0h for false,
end_comment

begin_comment
comment|///    FFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPGTB / PCMPGTB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cmplt_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
name|_mm_cmpgt_epi8
argument_list|(
name|__b
argument_list|,
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding signed 16-bit values of the
end_comment

begin_comment
comment|///    128-bit integer vectors to determine if the values in the first operand
end_comment

begin_comment
comment|///    are less than those in the second operand. Each comparison yields 0h for
end_comment

begin_comment
comment|///    false, FFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPGTW / PCMPGTW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cmplt_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
name|_mm_cmpgt_epi16
argument_list|(
name|__b
argument_list|,
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding signed 32-bit values of the
end_comment

begin_comment
comment|///    128-bit integer vectors to determine if the values in the first operand
end_comment

begin_comment
comment|///    are less than those in the second operand. Each comparison yields 0h for
end_comment

begin_comment
comment|///    false, FFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPGTD / PCMPGTD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cmplt_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
name|_mm_cmpgt_epi32
argument_list|(
name|__b
argument_list|,
name|__a
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_comment
comment|/// \brief Converts a 64-bit signed integer value from the second operand into a
end_comment

begin_comment
comment|///    double-precision value and returns it in the lower element of a [2 x
end_comment

begin_comment
comment|///    double] vector; the upper element of the returned vector is copied from
end_comment

begin_comment
comment|///    the upper element of the first operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTSI2SD / CVTSI2SD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The upper 64 bits of this operand are
end_comment

begin_comment
comment|///    copied to the upper 64 bits of the destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit signed integer operand containing the value to be converted.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] whose lower 64 bits contain the
end_comment

begin_comment
comment|///    converted value of the second operand. The upper 64 bits are copied from
end_comment

begin_comment
comment|///    the upper 64 bits of the first operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsi64_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|long
name|long
name|__b
parameter_list|)
block|{
name|__a
index|[
literal|0
index|]
operator|=
name|__b
expr_stmt|;
return|return
name|__a
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts the first (lower) element of a vector of [2 x double] into a
end_comment

begin_comment
comment|///    64-bit signed integer value, according to the current rounding mode.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTSD2SI / CVTSD2SI</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower 64 bits are used in the
end_comment

begin_comment
comment|///    conversion.
end_comment

begin_comment
comment|/// \returns A 64-bit signed integer containing the converted value.
end_comment

begin_function
specifier|static
name|__inline__
name|long
name|long
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsd_si64
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvtsd2si64
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts the first (lower) element of a vector of [2 x double] into a
end_comment

begin_comment
comment|///    64-bit signed integer value, truncating the result when it is inexact.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTTSD2SI / CVTTSD2SI</c>
end_comment

begin_comment
comment|///   instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower 64 bits are used in the
end_comment

begin_comment
comment|///    conversion.
end_comment

begin_comment
comment|/// \returns A 64-bit signed integer containing the converted value.
end_comment

begin_function
specifier|static
name|__inline__
name|long
name|long
name|__DEFAULT_FN_ATTRS
name|_mm_cvttsd_si64
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvttsd2si64
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \brief Converts a vector of [4 x i32] into a vector of [4 x float].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTDQ2PS / CVTDQ2PS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the converted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cvtepi32_ps
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvtdq2ps
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts a vector of [4 x float] into a vector of [4 x i32].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTPS2DQ / CVTPS2DQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector of [4 x i32] containing the converted
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvtps_epi32
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_cvtps2dq
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts a vector of [4 x float] into a vector of [4 x i32],
end_comment

begin_comment
comment|///    truncating the result when it is inexact.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTTPS2DQ / CVTTPS2DQ</c>
end_comment

begin_comment
comment|///   instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x i32] containing the converted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvttps_epi32
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_cvttps2dq
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Returns a vector of [4 x i32] where the lowest element is the input
end_comment

begin_comment
comment|///    operand and the remaining elements are zero.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVD / MOVD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 32-bit signed integer operand.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x i32].
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsi32_si128
parameter_list|(
name|int
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
operator|(
name|__v4si
operator|)
block|{
name|__a
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_comment
comment|/// \brief Returns a vector of [2 x i64] where the lower element is the input
end_comment

begin_comment
comment|///    operand and the upper element is zero.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVQ / MOVQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit signed integer operand containing the value to be converted.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x i64] containing the converted value.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsi64_si128
parameter_list|(
name|long
name|long
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
block|{
name|__a
block|,
literal|0
block|}
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \brief Moves the least significant 32 bits of a vector of [4 x i32] to a
end_comment

begin_comment
comment|///    32-bit signed integer value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVD / MOVD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A vector of [4 x i32]. The least significant 32 bits are moved to the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 32-bit signed integer containing the moved value.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsi128_si32
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
name|__v4si
name|__b
init|=
operator|(
name|__v4si
operator|)
name|__a
decl_stmt|;
return|return
name|__b
index|[
literal|0
index|]
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_comment
comment|/// \brief Moves the least significant 64 bits of a vector of [2 x i64] to a
end_comment

begin_comment
comment|///    64-bit signed integer value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVQ / MOVQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A vector of [2 x i64]. The least significant 64 bits are moved to the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 64-bit signed integer containing the moved value.
end_comment

begin_function
specifier|static
name|__inline__
name|long
name|long
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsi128_si64
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
name|__a
index|[
literal|0
index|]
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \brief Moves packed integer values from an aligned 128-bit memory location
end_comment

begin_comment
comment|///    to elements in a 128-bit integer vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVDQA / MOVDQA</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    An aligned pointer to a memory location containing integer values.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the moved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_load_si128
parameter_list|(
name|__m128i
specifier|const
modifier|*
name|__p
parameter_list|)
block|{
return|return
operator|*
name|__p
return|;
block|}
end_function

begin_comment
comment|/// \brief Moves packed integer values from an unaligned 128-bit memory location
end_comment

begin_comment
comment|///    to elements in a 128-bit integer vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVDQU / MOVDQU</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to a memory location containing integer values.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the moved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_loadu_si128
parameter_list|(
name|__m128i
specifier|const
modifier|*
name|__p
parameter_list|)
block|{
struct|struct
name|__loadu_si128
block|{
name|__m128i
name|__v
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
return|return
operator|(
operator|(
expr|struct
name|__loadu_si128
operator|*
operator|)
name|__p
operator|)
operator|->
name|__v
return|;
block|}
end_function

begin_comment
comment|/// \brief Returns a vector of [2 x i64] where the lower element is taken from
end_comment

begin_comment
comment|///    the lower element of the operand, and the upper element is zero.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVQ / MOVQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x i64]. Bits [63:0] are written to bits [63:0] of
end_comment

begin_comment
comment|///    the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x i64]. The lower order bits contain the
end_comment

begin_comment
comment|///    moved value. The higher order bits are cleared.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_loadl_epi64
parameter_list|(
name|__m128i
specifier|const
modifier|*
name|__p
parameter_list|)
block|{
struct|struct
name|__mm_loadl_epi64_struct
block|{
name|long
name|long
name|__u
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
return|return
operator|(
name|__m128i
operator|)
block|{
operator|(
operator|(
expr|struct
name|__mm_loadl_epi64_struct
operator|*
operator|)
name|__p
operator|)
operator|->
name|__u
block|,
literal|0
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Generates a 128-bit vector of [4 x i32] with unspecified content.
end_comment

begin_comment
comment|///    This could be used as an argument to another intrinsic function where the
end_comment

begin_comment
comment|///    argument is required but the value is not actually used.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic has no corresponding instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x i32] with unspecified content.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_undefined_si128
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_undef128
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Initializes both 64-bit values in a 128-bit vector of [2 x i64] with
end_comment

begin_comment
comment|///    the specified 64-bit integer values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __q1
end_comment

begin_comment
comment|///    A 64-bit integer value used to initialize the upper 64 bits of the
end_comment

begin_comment
comment|///    destination vector of [2 x i64].
end_comment

begin_comment
comment|/// \param __q0
end_comment

begin_comment
comment|///    A 64-bit integer value used to initialize the lower 64 bits of the
end_comment

begin_comment
comment|///    destination vector of [2 x i64].
end_comment

begin_comment
comment|/// \returns An initialized 128-bit vector of [2 x i64] containing the values
end_comment

begin_comment
comment|///    provided in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_set_epi64x
parameter_list|(
name|long
name|long
name|__q1
parameter_list|,
name|long
name|long
name|__q0
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
block|{
name|__q0
block|,
name|__q1
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Initializes both 64-bit values in a 128-bit vector of [2 x i64] with
end_comment

begin_comment
comment|///    the specified 64-bit integer values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __q1
end_comment

begin_comment
comment|///    A 64-bit integer value used to initialize the upper 64 bits of the
end_comment

begin_comment
comment|///    destination vector of [2 x i64].
end_comment

begin_comment
comment|/// \param __q0
end_comment

begin_comment
comment|///    A 64-bit integer value used to initialize the lower 64 bits of the
end_comment

begin_comment
comment|///    destination vector of [2 x i64].
end_comment

begin_comment
comment|/// \returns An initialized 128-bit vector of [2 x i64] containing the values
end_comment

begin_comment
comment|///    provided in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_set_epi64
parameter_list|(
name|__m64
name|__q1
parameter_list|,
name|__m64
name|__q0
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
block|{
operator|(
name|long
name|long
operator|)
name|__q0
block|,
operator|(
name|long
name|long
operator|)
name|__q1
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Initializes the 32-bit values in a 128-bit vector of [4 x i32] with
end_comment

begin_comment
comment|///    the specified 32-bit integer values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __i3
end_comment

begin_comment
comment|///    A 32-bit integer value used to initialize bits [127:96] of the
end_comment

begin_comment
comment|///    destination vector.
end_comment

begin_comment
comment|/// \param __i2
end_comment

begin_comment
comment|///    A 32-bit integer value used to initialize bits [95:64] of the destination
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \param __i1
end_comment

begin_comment
comment|///    A 32-bit integer value used to initialize bits [63:32] of the destination
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \param __i0
end_comment

begin_comment
comment|///    A 32-bit integer value used to initialize bits [31:0] of the destination
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit vector of [4 x i32] containing the values
end_comment

begin_comment
comment|///    provided in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_set_epi32
parameter_list|(
name|int
name|__i3
parameter_list|,
name|int
name|__i2
parameter_list|,
name|int
name|__i1
parameter_list|,
name|int
name|__i0
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
operator|(
name|__v4si
operator|)
block|{
name|__i0
block|,
name|__i1
block|,
name|__i2
block|,
name|__i3
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Initializes the 16-bit values in a 128-bit vector of [8 x i16] with
end_comment

begin_comment
comment|///    the specified 16-bit integer values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __w7
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [127:112] of the
end_comment

begin_comment
comment|///    destination vector.
end_comment

begin_comment
comment|/// \param __w6
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [111:96] of the
end_comment

begin_comment
comment|///    destination vector.
end_comment

begin_comment
comment|/// \param __w5
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [95:80] of the destination
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \param __w4
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [79:64] of the destination
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \param __w3
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [63:48] of the destination
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \param __w2
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [47:32] of the destination
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \param __w1
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [31:16] of the destination
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \param __w0
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [15:0] of the destination
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit vector of [8 x i16] containing the values
end_comment

begin_comment
comment|///    provided in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_set_epi16
parameter_list|(
name|short
name|__w7
parameter_list|,
name|short
name|__w6
parameter_list|,
name|short
name|__w5
parameter_list|,
name|short
name|__w4
parameter_list|,
name|short
name|__w3
parameter_list|,
name|short
name|__w2
parameter_list|,
name|short
name|__w1
parameter_list|,
name|short
name|__w0
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
operator|(
name|__v8hi
operator|)
block|{
name|__w0
block|,
name|__w1
block|,
name|__w2
block|,
name|__w3
block|,
name|__w4
block|,
name|__w5
block|,
name|__w6
block|,
name|__w7
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Initializes the 8-bit values in a 128-bit vector of [16 x i8] with
end_comment

begin_comment
comment|///    the specified 8-bit integer values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __b15
end_comment

begin_comment
comment|///    Initializes bits [127:120] of the destination vector.
end_comment

begin_comment
comment|/// \param __b14
end_comment

begin_comment
comment|///    Initializes bits [119:112] of the destination vector.
end_comment

begin_comment
comment|/// \param __b13
end_comment

begin_comment
comment|///    Initializes bits [111:104] of the destination vector.
end_comment

begin_comment
comment|/// \param __b12
end_comment

begin_comment
comment|///    Initializes bits [103:96] of the destination vector.
end_comment

begin_comment
comment|/// \param __b11
end_comment

begin_comment
comment|///    Initializes bits [95:88] of the destination vector.
end_comment

begin_comment
comment|/// \param __b10
end_comment

begin_comment
comment|///    Initializes bits [87:80] of the destination vector.
end_comment

begin_comment
comment|/// \param __b9
end_comment

begin_comment
comment|///    Initializes bits [79:72] of the destination vector.
end_comment

begin_comment
comment|/// \param __b8
end_comment

begin_comment
comment|///    Initializes bits [71:64] of the destination vector.
end_comment

begin_comment
comment|/// \param __b7
end_comment

begin_comment
comment|///    Initializes bits [63:56] of the destination vector.
end_comment

begin_comment
comment|/// \param __b6
end_comment

begin_comment
comment|///    Initializes bits [55:48] of the destination vector.
end_comment

begin_comment
comment|/// \param __b5
end_comment

begin_comment
comment|///    Initializes bits [47:40] of the destination vector.
end_comment

begin_comment
comment|/// \param __b4
end_comment

begin_comment
comment|///    Initializes bits [39:32] of the destination vector.
end_comment

begin_comment
comment|/// \param __b3
end_comment

begin_comment
comment|///    Initializes bits [31:24] of the destination vector.
end_comment

begin_comment
comment|/// \param __b2
end_comment

begin_comment
comment|///    Initializes bits [23:16] of the destination vector.
end_comment

begin_comment
comment|/// \param __b1
end_comment

begin_comment
comment|///    Initializes bits [15:8] of the destination vector.
end_comment

begin_comment
comment|/// \param __b0
end_comment

begin_comment
comment|///    Initializes bits [7:0] of the destination vector.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit vector of [16 x i8] containing the values
end_comment

begin_comment
comment|///    provided in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_set_epi8
parameter_list|(
name|char
name|__b15
parameter_list|,
name|char
name|__b14
parameter_list|,
name|char
name|__b13
parameter_list|,
name|char
name|__b12
parameter_list|,
name|char
name|__b11
parameter_list|,
name|char
name|__b10
parameter_list|,
name|char
name|__b9
parameter_list|,
name|char
name|__b8
parameter_list|,
name|char
name|__b7
parameter_list|,
name|char
name|__b6
parameter_list|,
name|char
name|__b5
parameter_list|,
name|char
name|__b4
parameter_list|,
name|char
name|__b3
parameter_list|,
name|char
name|__b2
parameter_list|,
name|char
name|__b1
parameter_list|,
name|char
name|__b0
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
operator|(
name|__v16qi
operator|)
block|{
name|__b0
block|,
name|__b1
block|,
name|__b2
block|,
name|__b3
block|,
name|__b4
block|,
name|__b5
block|,
name|__b6
block|,
name|__b7
block|,
name|__b8
block|,
name|__b9
block|,
name|__b10
block|,
name|__b11
block|,
name|__b12
block|,
name|__b13
block|,
name|__b14
block|,
name|__b15
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Initializes both values in a 128-bit integer vector with the
end_comment

begin_comment
comment|///    specified 64-bit integer value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __q
end_comment

begin_comment
comment|///    Integer value used to initialize the elements of the destination integer
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit integer vector of [2 x i64] with both
end_comment

begin_comment
comment|///    elements containing the value provided in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_set1_epi64x
parameter_list|(
name|long
name|long
name|__q
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
block|{
name|__q
block|,
name|__q
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Initializes both values in a 128-bit vector of [2 x i64] with the
end_comment

begin_comment
comment|///    specified 64-bit value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __q
end_comment

begin_comment
comment|///    A 64-bit value used to initialize the elements of the destination integer
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit vector of [2 x i64] with all elements
end_comment

begin_comment
comment|///    containing the value provided in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_set1_epi64
parameter_list|(
name|__m64
name|__q
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
block|{
operator|(
name|long
name|long
operator|)
name|__q
block|,
operator|(
name|long
name|long
operator|)
name|__q
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Initializes all values in a 128-bit vector of [4 x i32] with the
end_comment

begin_comment
comment|///    specified 32-bit value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __i
end_comment

begin_comment
comment|///    A 32-bit value used to initialize the elements of the destination integer
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit vector of [4 x i32] with all elements
end_comment

begin_comment
comment|///    containing the value provided in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_set1_epi32
parameter_list|(
name|int
name|__i
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
operator|(
name|__v4si
operator|)
block|{
name|__i
block|,
name|__i
block|,
name|__i
block|,
name|__i
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Initializes all values in a 128-bit vector of [8 x i16] with the
end_comment

begin_comment
comment|///    specified 16-bit value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __w
end_comment

begin_comment
comment|///    A 16-bit value used to initialize the elements of the destination integer
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit vector of [8 x i16] with all elements
end_comment

begin_comment
comment|///    containing the value provided in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_set1_epi16
parameter_list|(
name|short
name|__w
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
operator|(
name|__v8hi
operator|)
block|{
name|__w
block|,
name|__w
block|,
name|__w
block|,
name|__w
block|,
name|__w
block|,
name|__w
block|,
name|__w
block|,
name|__w
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Initializes all values in a 128-bit vector of [16 x i8] with the
end_comment

begin_comment
comment|///    specified 8-bit value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    An 8-bit value used to initialize the elements of the destination integer
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit vector of [16 x i8] with all elements
end_comment

begin_comment
comment|///    containing the value provided in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_set1_epi8
parameter_list|(
name|char
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
operator|(
name|__v16qi
operator|)
block|{
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit integer vector, initialized in reverse order
end_comment

begin_comment
comment|///     with the specified 64-bit integral values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPUNPCKLQDQ / PUNPCKLQDQ</c>
end_comment

begin_comment
comment|///   instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __q0
end_comment

begin_comment
comment|///    A 64-bit integral value used to initialize the lower 64 bits of the
end_comment

begin_comment
comment|///    result.
end_comment

begin_comment
comment|/// \param __q1
end_comment

begin_comment
comment|///    A 64-bit integral value used to initialize the upper 64 bits of the
end_comment

begin_comment
comment|///    result.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit integer vector.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_setr_epi64
parameter_list|(
name|__m64
name|__q0
parameter_list|,
name|__m64
name|__q1
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
block|{
operator|(
name|long
name|long
operator|)
name|__q0
block|,
operator|(
name|long
name|long
operator|)
name|__q1
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit integer vector, initialized in reverse order
end_comment

begin_comment
comment|///     with the specified 32-bit integral values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __i0
end_comment

begin_comment
comment|///    A 32-bit integral value used to initialize bits [31:0] of the result.
end_comment

begin_comment
comment|/// \param __i1
end_comment

begin_comment
comment|///    A 32-bit integral value used to initialize bits [63:32] of the result.
end_comment

begin_comment
comment|/// \param __i2
end_comment

begin_comment
comment|///    A 32-bit integral value used to initialize bits [95:64] of the result.
end_comment

begin_comment
comment|/// \param __i3
end_comment

begin_comment
comment|///    A 32-bit integral value used to initialize bits [127:96] of the result.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit integer vector.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_setr_epi32
parameter_list|(
name|int
name|__i0
parameter_list|,
name|int
name|__i1
parameter_list|,
name|int
name|__i2
parameter_list|,
name|int
name|__i3
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
operator|(
name|__v4si
operator|)
block|{
name|__i0
block|,
name|__i1
block|,
name|__i2
block|,
name|__i3
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit integer vector, initialized in reverse order
end_comment

begin_comment
comment|///     with the specified 16-bit integral values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __w0
end_comment

begin_comment
comment|///    A 16-bit integral value used to initialize bits [15:0] of the result.
end_comment

begin_comment
comment|/// \param __w1
end_comment

begin_comment
comment|///    A 16-bit integral value used to initialize bits [31:16] of the result.
end_comment

begin_comment
comment|/// \param __w2
end_comment

begin_comment
comment|///    A 16-bit integral value used to initialize bits [47:32] of the result.
end_comment

begin_comment
comment|/// \param __w3
end_comment

begin_comment
comment|///    A 16-bit integral value used to initialize bits [63:48] of the result.
end_comment

begin_comment
comment|/// \param __w4
end_comment

begin_comment
comment|///    A 16-bit integral value used to initialize bits [79:64] of the result.
end_comment

begin_comment
comment|/// \param __w5
end_comment

begin_comment
comment|///    A 16-bit integral value used to initialize bits [95:80] of the result.
end_comment

begin_comment
comment|/// \param __w6
end_comment

begin_comment
comment|///    A 16-bit integral value used to initialize bits [111:96] of the result.
end_comment

begin_comment
comment|/// \param __w7
end_comment

begin_comment
comment|///    A 16-bit integral value used to initialize bits [127:112] of the result.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit integer vector.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_setr_epi16
parameter_list|(
name|short
name|__w0
parameter_list|,
name|short
name|__w1
parameter_list|,
name|short
name|__w2
parameter_list|,
name|short
name|__w3
parameter_list|,
name|short
name|__w4
parameter_list|,
name|short
name|__w5
parameter_list|,
name|short
name|__w6
parameter_list|,
name|short
name|__w7
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
operator|(
name|__v8hi
operator|)
block|{
name|__w0
block|,
name|__w1
block|,
name|__w2
block|,
name|__w3
block|,
name|__w4
block|,
name|__w5
block|,
name|__w6
block|,
name|__w7
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit integer vector, initialized in reverse order
end_comment

begin_comment
comment|///     with the specified 8-bit integral values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __b0
end_comment

begin_comment
comment|///    An 8-bit integral value used to initialize bits [7:0] of the result.
end_comment

begin_comment
comment|/// \param __b1
end_comment

begin_comment
comment|///    An 8-bit integral value used to initialize bits [15:8] of the result.
end_comment

begin_comment
comment|/// \param __b2
end_comment

begin_comment
comment|///    An 8-bit integral value used to initialize bits [23:16] of the result.
end_comment

begin_comment
comment|/// \param __b3
end_comment

begin_comment
comment|///    An 8-bit integral value used to initialize bits [31:24] of the result.
end_comment

begin_comment
comment|/// \param __b4
end_comment

begin_comment
comment|///    An 8-bit integral value used to initialize bits [39:32] of the result.
end_comment

begin_comment
comment|/// \param __b5
end_comment

begin_comment
comment|///    An 8-bit integral value used to initialize bits [47:40] of the result.
end_comment

begin_comment
comment|/// \param __b6
end_comment

begin_comment
comment|///    An 8-bit integral value used to initialize bits [55:48] of the result.
end_comment

begin_comment
comment|/// \param __b7
end_comment

begin_comment
comment|///    An 8-bit integral value used to initialize bits [63:56] of the result.
end_comment

begin_comment
comment|/// \param __b8
end_comment

begin_comment
comment|///    An 8-bit integral value used to initialize bits [71:64] of the result.
end_comment

begin_comment
comment|/// \param __b9
end_comment

begin_comment
comment|///    An 8-bit integral value used to initialize bits [79:72] of the result.
end_comment

begin_comment
comment|/// \param __b10
end_comment

begin_comment
comment|///    An 8-bit integral value used to initialize bits [87:80] of the result.
end_comment

begin_comment
comment|/// \param __b11
end_comment

begin_comment
comment|///    An 8-bit integral value used to initialize bits [95:88] of the result.
end_comment

begin_comment
comment|/// \param __b12
end_comment

begin_comment
comment|///    An 8-bit integral value used to initialize bits [103:96] of the result.
end_comment

begin_comment
comment|/// \param __b13
end_comment

begin_comment
comment|///    An 8-bit integral value used to initialize bits [111:104] of the result.
end_comment

begin_comment
comment|/// \param __b14
end_comment

begin_comment
comment|///    An 8-bit integral value used to initialize bits [119:112] of the result.
end_comment

begin_comment
comment|/// \param __b15
end_comment

begin_comment
comment|///    An 8-bit integral value used to initialize bits [127:120] of the result.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit integer vector.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_setr_epi8
parameter_list|(
name|char
name|__b0
parameter_list|,
name|char
name|__b1
parameter_list|,
name|char
name|__b2
parameter_list|,
name|char
name|__b3
parameter_list|,
name|char
name|__b4
parameter_list|,
name|char
name|__b5
parameter_list|,
name|char
name|__b6
parameter_list|,
name|char
name|__b7
parameter_list|,
name|char
name|__b8
parameter_list|,
name|char
name|__b9
parameter_list|,
name|char
name|__b10
parameter_list|,
name|char
name|__b11
parameter_list|,
name|char
name|__b12
parameter_list|,
name|char
name|__b13
parameter_list|,
name|char
name|__b14
parameter_list|,
name|char
name|__b15
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
operator|(
name|__v16qi
operator|)
block|{
name|__b0
block|,
name|__b1
block|,
name|__b2
block|,
name|__b3
block|,
name|__b4
block|,
name|__b5
block|,
name|__b6
block|,
name|__b7
block|,
name|__b8
block|,
name|__b9
block|,
name|__b10
block|,
name|__b11
block|,
name|__b12
block|,
name|__b13
block|,
name|__b14
block|,
name|__b15
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Creates a 128-bit integer vector initialized to zero.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VXORPS / XORPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns An initialized 128-bit integer vector with all elements set to
end_comment

begin_comment
comment|///    zero.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_setzero_si128
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
block|{
literal|0LL
block|,
literal|0LL
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Stores a 128-bit integer vector to a memory location aligned on a
end_comment

begin_comment
comment|///    128-bit boundary.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVAPS / MOVAPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to an aligned memory location that will receive the integer
end_comment

begin_comment
comment|///    values.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the values to be moved.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_store_si128
parameter_list|(
name|__m128i
modifier|*
name|__p
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
operator|*
name|__p
operator|=
name|__b
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Stores a 128-bit integer vector to an unaligned memory location.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVUPS / MOVUPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to a memory location that will receive the integer values.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the values to be moved.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_storeu_si128
parameter_list|(
name|__m128i
modifier|*
name|__p
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
struct|struct
name|__storeu_si128
block|{
name|__m128i
name|__v
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
operator|(
operator|(
expr|struct
name|__storeu_si128
operator|*
operator|)
name|__p
operator|)
operator|->
name|__v
operator|=
name|__b
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Moves bytes selected by the mask from the first operand to the
end_comment

begin_comment
comment|///    specified unaligned memory location. When a mask bit is 1, the
end_comment

begin_comment
comment|///    corresponding byte is written, otherwise it is not written. To minimize
end_comment

begin_comment
comment|///    caching, the date is flagged as non-temporal (unlikely to be used again
end_comment

begin_comment
comment|///    soon). Exception and trap behavior for elements not selected for storage
end_comment

begin_comment
comment|///    to memory are implementation dependent.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMASKMOVDQU / MASKMOVDQU</c>
end_comment

begin_comment
comment|///   instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __d
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the values to be moved.
end_comment

begin_comment
comment|/// \param __n
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the mask. The most significant bit of
end_comment

begin_comment
comment|///    each byte represents the mask bits.
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to an unaligned 128-bit memory location where the specified
end_comment

begin_comment
comment|///    values are moved.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_maskmoveu_si128
parameter_list|(
name|__m128i
name|__d
parameter_list|,
name|__m128i
name|__n
parameter_list|,
name|char
modifier|*
name|__p
parameter_list|)
block|{
name|__builtin_ia32_maskmovdqu
argument_list|(
operator|(
name|__v16qi
operator|)
name|__d
argument_list|,
operator|(
name|__v16qi
operator|)
name|__n
argument_list|,
name|__p
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Stores the lower 64 bits of a 128-bit integer vector of [2 x i64] to
end_comment

begin_comment
comment|///    a memory location.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVLPS / MOVLPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to a 64-bit memory location that will receive the lower 64 bits
end_comment

begin_comment
comment|///    of the integer vector parameter.
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector of [2 x i64]. The lower 64 bits contain the
end_comment

begin_comment
comment|///    value to be stored.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_storel_epi64
parameter_list|(
name|__m128i
modifier|*
name|__p
parameter_list|,
name|__m128i
name|__a
parameter_list|)
block|{
struct|struct
name|__mm_storel_epi64_struct
block|{
name|long
name|long
name|__u
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
operator|(
operator|(
expr|struct
name|__mm_storel_epi64_struct
operator|*
operator|)
name|__p
operator|)
operator|->
name|__u
operator|=
name|__a
index|[
literal|0
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Stores a 128-bit floating point vector of [2 x double] to a 128-bit
end_comment

begin_comment
comment|///    aligned memory location. To minimize caching, the data is flagged as
end_comment

begin_comment
comment|///    non-temporal (unlikely to be used again soon).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVNTPS / MOVNTPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to the 128-bit aligned memory location used to store the value.
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A vector of [2 x double] containing the 64-bit values to be stored.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_stream_pd
parameter_list|(
name|double
modifier|*
name|__p
parameter_list|,
name|__m128d
name|__a
parameter_list|)
block|{
name|__builtin_nontemporal_store
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|*
operator|)
name|__p
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Stores a 128-bit integer vector to a 128-bit aligned memory location.
end_comment

begin_comment
comment|///    To minimize caching, the data is flagged as non-temporal (unlikely to be
end_comment

begin_comment
comment|///    used again soon).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVNTPS / MOVNTPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to the 128-bit aligned memory location used to store the value.
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the values to be stored.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_stream_si128
parameter_list|(
name|__m128i
modifier|*
name|__p
parameter_list|,
name|__m128i
name|__a
parameter_list|)
block|{
name|__builtin_nontemporal_store
argument_list|(
operator|(
name|__v2di
operator|)
name|__a
argument_list|,
operator|(
name|__v2di
operator|*
operator|)
name|__p
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Stores a 32-bit integer value in the specified memory location. To
end_comment

begin_comment
comment|///    minimize caching, the data is flagged as non-temporal (unlikely to be
end_comment

begin_comment
comment|///    used again soon).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> MOVNTI</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to the 32-bit memory location used to store the value.
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 32-bit integer containing the value to be stored.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_stream_si32
parameter_list|(
name|int
modifier|*
name|__p
parameter_list|,
name|int
name|__a
parameter_list|)
block|{
name|__builtin_ia32_movnti
argument_list|(
name|__p
argument_list|,
name|__a
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_comment
comment|/// \brief Stores a 64-bit integer value in the specified memory location. To
end_comment

begin_comment
comment|///    minimize caching, the data is flagged as non-temporal (unlikely to be
end_comment

begin_comment
comment|///    used again soon).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> MOVNTIQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to the 64-bit memory location used to store the value.
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit integer containing the value to be stored.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_stream_si64
parameter_list|(
name|long
name|long
modifier|*
name|__p
parameter_list|,
name|long
name|long
name|__a
parameter_list|)
block|{
name|__builtin_ia32_movnti64
argument_list|(
name|__p
argument_list|,
name|__a
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/// \brief The cache line containing \a __p is flushed and invalidated from all
comment|///    caches in the coherency domain.
comment|///
comment|/// \headerfile<x86intrin.h>
comment|///
comment|/// This intrinsic corresponds to the<c> CLFLUSH</c> instruction.
comment|///
comment|/// \param __p
comment|///    A pointer to the memory location used to identify the cache line to be
comment|///    flushed.
name|void
name|_mm_clflush
parameter_list|(
name|void
specifier|const
modifier|*
name|__p
parameter_list|)
function_decl|;
comment|/// \brief Forces strong memory ordering (serialization) between load
comment|///    instructions preceding this instruction and load instructions following
comment|///    this instruction, ensuring the system completes all previous loads before
comment|///    executing subsequent loads.
comment|///
comment|/// \headerfile<x86intrin.h>
comment|///
comment|/// This intrinsic corresponds to the<c> LFENCE</c> instruction.
comment|///
name|void
name|_mm_lfence
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/// \brief Forces strong memory ordering (serialization) between load and store
comment|///    instructions preceding this instruction and load and store instructions
comment|///    following this instruction, ensuring that the system completes all
comment|///    previous memory accesses before executing subsequent memory accesses.
comment|///
comment|/// \headerfile<x86intrin.h>
comment|///
comment|/// This intrinsic corresponds to the<c> MFENCE</c> instruction.
comment|///
name|void
name|_mm_mfence
parameter_list|(
name|void
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \brief Converts 16-bit signed integers from both 128-bit integer vector
end_comment

begin_comment
comment|///    operands into 8-bit signed integers, and packs the results into the
end_comment

begin_comment
comment|///    destination. Positive values greater than 0x7F are saturated to 0x7F.
end_comment

begin_comment
comment|///    Negative values less than 0x80 are saturated to 0x80.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPACKSSWB / PACKSSWB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///   A 128-bit integer vector of [8 x i16]. Each 16-bit element is treated as
end_comment

begin_comment
comment|///   a signed integer and is converted to a 8-bit signed integer with
end_comment

begin_comment
comment|///   saturation. Values greater than 0x7F are saturated to 0x7F. Values less
end_comment

begin_comment
comment|///   than 0x80 are saturated to 0x80. The converted [8 x i8] values are
end_comment

begin_comment
comment|///   written to the lower 64 bits of the result.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///   A 128-bit integer vector of [8 x i16]. Each 16-bit element is treated as
end_comment

begin_comment
comment|///   a signed integer and is converted to a 8-bit signed integer with
end_comment

begin_comment
comment|///   saturation. Values greater than 0x7F are saturated to 0x7F. Values less
end_comment

begin_comment
comment|///   than 0x80 are saturated to 0x80. The converted [8 x i8] values are
end_comment

begin_comment
comment|///   written to the higher 64 bits of the result.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [16 x i8] containing the converted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_packs_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_packsswb128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts 32-bit signed integers from both 128-bit integer vector
end_comment

begin_comment
comment|///    operands into 16-bit signed integers, and packs the results into the
end_comment

begin_comment
comment|///    destination. Positive values greater than 0x7FFF are saturated to 0x7FFF.
end_comment

begin_comment
comment|///    Negative values less than 0x8000 are saturated to 0x8000.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPACKSSDW / PACKSSDW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector of [4 x i32]. Each 32-bit element is treated as
end_comment

begin_comment
comment|///    a signed integer and is converted to a 16-bit signed integer with
end_comment

begin_comment
comment|///    saturation. Values greater than 0x7FFF are saturated to 0x7FFF. Values
end_comment

begin_comment
comment|///    less than 0x8000 are saturated to 0x8000. The converted [4 x i16] values
end_comment

begin_comment
comment|///    are written to the lower 64 bits of the result.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector of [4 x i32]. Each 32-bit element is treated as
end_comment

begin_comment
comment|///    a signed integer and is converted to a 16-bit signed integer with
end_comment

begin_comment
comment|///    saturation. Values greater than 0x7FFF are saturated to 0x7FFF. Values
end_comment

begin_comment
comment|///    less than 0x8000 are saturated to 0x8000. The converted [4 x i16] values
end_comment

begin_comment
comment|///    are written to the higher 64 bits of the result.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [8 x i16] containing the converted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_packs_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_packssdw128
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
operator|(
name|__v4si
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts 16-bit signed integers from both 128-bit integer vector
end_comment

begin_comment
comment|///    operands into 8-bit unsigned integers, and packs the results into the
end_comment

begin_comment
comment|///    destination. Values greater than 0xFF are saturated to 0xFF. Values less
end_comment

begin_comment
comment|///    than 0x00 are saturated to 0x00.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPACKUSWB / PACKUSWB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector of [8 x i16]. Each 16-bit element is treated as
end_comment

begin_comment
comment|///    a signed integer and is converted to an 8-bit unsigned integer with
end_comment

begin_comment
comment|///    saturation. Values greater than 0xFF are saturated to 0xFF. Values less
end_comment

begin_comment
comment|///    than 0x00 are saturated to 0x00. The converted [8 x i8] values are
end_comment

begin_comment
comment|///    written to the lower 64 bits of the result.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector of [8 x i16]. Each 16-bit element is treated as
end_comment

begin_comment
comment|///    a signed integer and is converted to an 8-bit unsigned integer with
end_comment

begin_comment
comment|///    saturation. Values greater than 0xFF are saturated to 0xFF. Values less
end_comment

begin_comment
comment|///    than 0x00 are saturated to 0x00. The converted [8 x i8] values are
end_comment

begin_comment
comment|///    written to the higher 64 bits of the result.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [16 x i8] containing the converted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_packus_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_packuswb128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Extracts 16 bits from a 128-bit integer vector of [8 x i16], using
end_comment

begin_comment
comment|///    the immediate-value parameter as a selector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPEXTRW / PEXTRW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __imm
end_comment

begin_comment
comment|///    An immediate value. Bits [2:0] selects values from \a __a to be assigned
end_comment

begin_comment
comment|///    to bits[15:0] of the result. \n
end_comment

begin_comment
comment|///    000: assign values from bits [15:0] of \a __a. \n
end_comment

begin_comment
comment|///    001: assign values from bits [31:16] of \a __a. \n
end_comment

begin_comment
comment|///    010: assign values from bits [47:32] of \a __a. \n
end_comment

begin_comment
comment|///    011: assign values from bits [63:48] of \a __a. \n
end_comment

begin_comment
comment|///    100: assign values from bits [79:64] of \a __a. \n
end_comment

begin_comment
comment|///    101: assign values from bits [95:80] of \a __a. \n
end_comment

begin_comment
comment|///    110: assign values from bits [111:96] of \a __a. \n
end_comment

begin_comment
comment|///    111: assign values from bits [127:112] of \a __a.
end_comment

begin_comment
comment|/// \returns An integer, whose lower 16 bits are selected from the 128-bit
end_comment

begin_comment
comment|///    integer vector parameter and the remaining bits are assigned zeros.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_extract_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|__imm
parameter_list|)
block|{
name|__v8hi
name|__b
init|=
operator|(
name|__v8hi
operator|)
name|__a
decl_stmt|;
return|return
operator|(
name|unsigned
name|short
operator|)
name|__b
index|[
name|__imm
operator|&
literal|7
index|]
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit integer vector by first making a copy of the
end_comment

begin_comment
comment|///    128-bit integer vector parameter, and then inserting the lower 16 bits
end_comment

begin_comment
comment|///    of an integer parameter into an offset specified by the immediate-value
end_comment

begin_comment
comment|///    parameter.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPINSRW / PINSRW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector of [8 x i16]. This vector is copied to the
end_comment

begin_comment
comment|///    result and then one of the eight elements in the result is replaced by
end_comment

begin_comment
comment|///    the lower 16 bits of \a __b.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    An integer. The lower 16 bits of this parameter are written to the
end_comment

begin_comment
comment|///    result beginning at an offset specified by \a __imm.
end_comment

begin_comment
comment|/// \param __imm
end_comment

begin_comment
comment|///    An immediate value specifying the bit offset in the result at which the
end_comment

begin_comment
comment|///    lower 16 bits of \a __b are written.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the constructed values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_insert_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|__b
parameter_list|,
name|int
name|__imm
parameter_list|)
block|{
name|__v8hi
name|__c
init|=
operator|(
name|__v8hi
operator|)
name|__a
decl_stmt|;
name|__c
index|[
name|__imm
operator|&
literal|7
index|]
operator|=
name|__b
expr_stmt|;
return|return
operator|(
name|__m128i
operator|)
name|__c
return|;
block|}
end_function

begin_comment
comment|/// \brief Copies the values of the most significant bits from each 8-bit
end_comment

begin_comment
comment|///    element in a 128-bit integer vector of [16 x i8] to create a 16-bit mask
end_comment

begin_comment
comment|///    value, zero-extends the value, and writes it to the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMOVMSKB / PMOVMSKB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the values with bits to be extracted.
end_comment

begin_comment
comment|/// \returns The most significant bits from each 8-bit element in \a __a,
end_comment

begin_comment
comment|///    written to bits [15:0]. The other bits are assigned zeros.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_movemask_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_pmovmskb128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit integer vector by shuffling four 32-bit
end_comment

begin_comment
comment|///    elements of a 128-bit integer vector parameter, using the immediate-value
end_comment

begin_comment
comment|///    parameter as a specifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// __m128i _mm_shuffle_epi32(__m128i a, const int imm);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSHUFD / PSHUFD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the values to be copied.
end_comment

begin_comment
comment|/// \param imm
end_comment

begin_comment
comment|///    An immediate value containing an 8-bit value specifying which elements to
end_comment

begin_comment
comment|///    copy from a. The destinations within the 128-bit destination are assigned
end_comment

begin_comment
comment|///    values as follows: \n
end_comment

begin_comment
comment|///    Bits [1:0] are used to assign values to bits [31:0] of the result. \n
end_comment

begin_comment
comment|///    Bits [3:2] are used to assign values to bits [63:32] of the result. \n
end_comment

begin_comment
comment|///    Bits [5:4] are used to assign values to bits [95:64] of the result. \n
end_comment

begin_comment
comment|///    Bits [7:6] are used to assign values to bits [127:96] of the result. \n
end_comment

begin_comment
comment|///    Bit value assignments: \n
end_comment

begin_comment
comment|///    00: assign values from bits [31:0] of \a a. \n
end_comment

begin_comment
comment|///    01: assign values from bits [63:32] of \a a. \n
end_comment

begin_comment
comment|///    10: assign values from bits [95:64] of \a a. \n
end_comment

begin_comment
comment|///    11: assign values from bits [127:96] of \a a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the shuffled values.
end_comment

begin_define
define|#
directive|define
name|_mm_shuffle_epi32
parameter_list|(
name|a
parameter_list|,
name|imm
parameter_list|)
value|__extension__ ({ \   (__m128i)__builtin_shufflevector((__v4si)(__m128i)(a), \                                    (__v4si)_mm_undefined_si128(), \                                    ((imm)>> 0)& 0x3, ((imm)>> 2)& 0x3, \                                    ((imm)>> 4)& 0x3, ((imm)>> 6)& 0x3); })
end_define

begin_comment
comment|/// \brief Constructs a 128-bit integer vector by shuffling four lower 16-bit
end_comment

begin_comment
comment|///    elements of a 128-bit integer vector of [8 x i16], using the immediate
end_comment

begin_comment
comment|///    value parameter as a specifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// __m128i _mm_shufflelo_epi16(__m128i a, const int imm);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSHUFLW / PSHUFLW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param a
end_comment

begin_comment
comment|///    A 128-bit integer vector of [8 x i16]. Bits [127:64] are copied to bits
end_comment

begin_comment
comment|///    [127:64] of the result.
end_comment

begin_comment
comment|/// \param imm
end_comment

begin_comment
comment|///    An 8-bit immediate value specifying which elements to copy from \a a. \n
end_comment

begin_comment
comment|///    Bits[1:0] are used to assign values to bits [15:0] of the result. \n
end_comment

begin_comment
comment|///    Bits[3:2] are used to assign values to bits [31:16] of the result. \n
end_comment

begin_comment
comment|///    Bits[5:4] are used to assign values to bits [47:32] of the result. \n
end_comment

begin_comment
comment|///    Bits[7:6] are used to assign values to bits [63:48] of the result. \n
end_comment

begin_comment
comment|///    Bit value assignments: \n
end_comment

begin_comment
comment|///    00: assign values from bits [15:0] of \a a. \n
end_comment

begin_comment
comment|///    01: assign values from bits [31:16] of \a a. \n
end_comment

begin_comment
comment|///    10: assign values from bits [47:32] of \a a. \n
end_comment

begin_comment
comment|///    11: assign values from bits [63:48] of \a a. \n
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the shuffled values.
end_comment

begin_define
define|#
directive|define
name|_mm_shufflelo_epi16
parameter_list|(
name|a
parameter_list|,
name|imm
parameter_list|)
value|__extension__ ({ \   (__m128i)__builtin_shufflevector((__v8hi)(__m128i)(a), \                                    (__v8hi)_mm_undefined_si128(), \                                    ((imm)>> 0)& 0x3, ((imm)>> 2)& 0x3, \                                    ((imm)>> 4)& 0x3, ((imm)>> 6)& 0x3, \                                    4, 5, 6, 7); })
end_define

begin_comment
comment|/// \brief Constructs a 128-bit integer vector by shuffling four upper 16-bit
end_comment

begin_comment
comment|///    elements of a 128-bit integer vector of [8 x i16], using the immediate
end_comment

begin_comment
comment|///    value parameter as a specifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// __m128i _mm_shufflehi_epi16(__m128i a, const int imm);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPSHUFHW / PSHUFHW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param a
end_comment

begin_comment
comment|///    A 128-bit integer vector of [8 x i16]. Bits [63:0] are copied to bits
end_comment

begin_comment
comment|///    [63:0] of the result.
end_comment

begin_comment
comment|/// \param imm
end_comment

begin_comment
comment|///    An 8-bit immediate value specifying which elements to copy from \a a. \n
end_comment

begin_comment
comment|///    Bits[1:0] are used to assign values to bits [79:64] of the result. \n
end_comment

begin_comment
comment|///    Bits[3:2] are used to assign values to bits [95:80] of the result. \n
end_comment

begin_comment
comment|///    Bits[5:4] are used to assign values to bits [111:96] of the result. \n
end_comment

begin_comment
comment|///    Bits[7:6] are used to assign values to bits [127:112] of the result. \n
end_comment

begin_comment
comment|///    Bit value assignments: \n
end_comment

begin_comment
comment|///    00: assign values from bits [79:64] of \a a. \n
end_comment

begin_comment
comment|///    01: assign values from bits [95:80] of \a a. \n
end_comment

begin_comment
comment|///    10: assign values from bits [111:96] of \a a. \n
end_comment

begin_comment
comment|///    11: assign values from bits [127:112] of \a a. \n
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the shuffled values.
end_comment

begin_define
define|#
directive|define
name|_mm_shufflehi_epi16
parameter_list|(
name|a
parameter_list|,
name|imm
parameter_list|)
value|__extension__ ({ \   (__m128i)__builtin_shufflevector((__v8hi)(__m128i)(a), \                                    (__v8hi)_mm_undefined_si128(), \                                    0, 1, 2, 3, \                                    4 + (((imm)>> 0)& 0x3), \                                    4 + (((imm)>> 2)& 0x3), \                                    4 + (((imm)>> 4)& 0x3), \                                    4 + (((imm)>> 6)& 0x3)); })
end_define

begin_comment
comment|/// \brief Unpacks the high-order (index 8-15) values from two 128-bit vectors
end_comment

begin_comment
comment|///    of [16 x i8] and interleaves them into a 128-bit vector of [16 x i8].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPUNPCKHBW / PUNPCKHBW</c>
end_comment

begin_comment
comment|///   instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8].
end_comment

begin_comment
comment|///    Bits [71:64] are written to bits [7:0] of the result. \n
end_comment

begin_comment
comment|///    Bits [79:72] are written to bits [23:16] of the result. \n
end_comment

begin_comment
comment|///    Bits [87:80] are written to bits [39:32] of the result. \n
end_comment

begin_comment
comment|///    Bits [95:88] are written to bits [55:48] of the result. \n
end_comment

begin_comment
comment|///    Bits [103:96] are written to bits [71:64] of the result. \n
end_comment

begin_comment
comment|///    Bits [111:104] are written to bits [87:80] of the result. \n
end_comment

begin_comment
comment|///    Bits [119:112] are written to bits [103:96] of the result. \n
end_comment

begin_comment
comment|///    Bits [127:120] are written to bits [119:112] of the result.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8]. \n
end_comment

begin_comment
comment|///    Bits [71:64] are written to bits [15:8] of the result. \n
end_comment

begin_comment
comment|///    Bits [79:72] are written to bits [31:24] of the result. \n
end_comment

begin_comment
comment|///    Bits [87:80] are written to bits [47:40] of the result. \n
end_comment

begin_comment
comment|///    Bits [95:88] are written to bits [63:56] of the result. \n
end_comment

begin_comment
comment|///    Bits [103:96] are written to bits [79:72] of the result. \n
end_comment

begin_comment
comment|///    Bits [111:104] are written to bits [95:88] of the result. \n
end_comment

begin_comment
comment|///    Bits [119:112] are written to bits [111:104] of the result. \n
end_comment

begin_comment
comment|///    Bits [127:120] are written to bits [127:120] of the result.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [16 x i8] containing the interleaved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_unpackhi_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|,
operator|(
name|__v16qi
operator|)
name|__b
argument_list|,
literal|8
argument_list|,
literal|16
operator|+
literal|8
argument_list|,
literal|9
argument_list|,
literal|16
operator|+
literal|9
argument_list|,
literal|10
argument_list|,
literal|16
operator|+
literal|10
argument_list|,
literal|11
argument_list|,
literal|16
operator|+
literal|11
argument_list|,
literal|12
argument_list|,
literal|16
operator|+
literal|12
argument_list|,
literal|13
argument_list|,
literal|16
operator|+
literal|13
argument_list|,
literal|14
argument_list|,
literal|16
operator|+
literal|14
argument_list|,
literal|15
argument_list|,
literal|16
operator|+
literal|15
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Unpacks the high-order (index 4-7) values from two 128-bit vectors of
end_comment

begin_comment
comment|///    [8 x i16] and interleaves them into a 128-bit vector of [8 x i16].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPUNPCKHWD / PUNPCKHWD</c>
end_comment

begin_comment
comment|///   instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16].
end_comment

begin_comment
comment|///    Bits [79:64] are written to bits [15:0] of the result. \n
end_comment

begin_comment
comment|///    Bits [95:80] are written to bits [47:32] of the result. \n
end_comment

begin_comment
comment|///    Bits [111:96] are written to bits [79:64] of the result. \n
end_comment

begin_comment
comment|///    Bits [127:112] are written to bits [111:96] of the result.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16].
end_comment

begin_comment
comment|///    Bits [79:64] are written to bits [31:16] of the result. \n
end_comment

begin_comment
comment|///    Bits [95:80] are written to bits [63:48] of the result. \n
end_comment

begin_comment
comment|///    Bits [111:96] are written to bits [95:80] of the result. \n
end_comment

begin_comment
comment|///    Bits [127:112] are written to bits [127:112] of the result.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [8 x i16] containing the interleaved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_unpackhi_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|,
literal|4
argument_list|,
literal|8
operator|+
literal|4
argument_list|,
literal|5
argument_list|,
literal|8
operator|+
literal|5
argument_list|,
literal|6
argument_list|,
literal|8
operator|+
literal|6
argument_list|,
literal|7
argument_list|,
literal|8
operator|+
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Unpacks the high-order (index 2,3) values from two 128-bit vectors of
end_comment

begin_comment
comment|///    [4 x i32] and interleaves them into a 128-bit vector of [4 x i32].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPUNPCKHDQ / PUNPCKHDQ</c>
end_comment

begin_comment
comment|///   instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x i32]. \n
end_comment

begin_comment
comment|///    Bits [95:64] are written to bits [31:0] of the destination. \n
end_comment

begin_comment
comment|///    Bits [127:96] are written to bits [95:64] of the destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x i32]. \n
end_comment

begin_comment
comment|///    Bits [95:64] are written to bits [64:32] of the destination. \n
end_comment

begin_comment
comment|///    Bits [127:96] are written to bits [127:96] of the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x i32] containing the interleaved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_unpackhi_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
operator|(
name|__v4si
operator|)
name|__b
argument_list|,
literal|2
argument_list|,
literal|4
operator|+
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
operator|+
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Unpacks the high-order (odd-indexed) values from two 128-bit vectors
end_comment

begin_comment
comment|///    of [2 x i64] and interleaves them into a 128-bit vector of [2 x i64].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPUNPCKHQDQ / PUNPCKHQDQ</c>
end_comment

begin_comment
comment|///   instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x i64]. \n
end_comment

begin_comment
comment|///    Bits [127:64] are written to bits [63:0] of the destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x i64]. \n
end_comment

begin_comment
comment|///    Bits [127:64] are written to bits [127:64] of the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x i64] containing the interleaved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_unpackhi_epi64
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v2di
operator|)
name|__a
argument_list|,
operator|(
name|__v2di
operator|)
name|__b
argument_list|,
literal|1
argument_list|,
literal|2
operator|+
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Unpacks the low-order (index 0-7) values from two 128-bit vectors of
end_comment

begin_comment
comment|///    [16 x i8] and interleaves them into a 128-bit vector of [16 x i8].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPUNPCKLBW / PUNPCKLBW</c>
end_comment

begin_comment
comment|///   instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8]. \n
end_comment

begin_comment
comment|///    Bits [7:0] are written to bits [7:0] of the result. \n
end_comment

begin_comment
comment|///    Bits [15:8] are written to bits [23:16] of the result. \n
end_comment

begin_comment
comment|///    Bits [23:16] are written to bits [39:32] of the result. \n
end_comment

begin_comment
comment|///    Bits [31:24] are written to bits [55:48] of the result. \n
end_comment

begin_comment
comment|///    Bits [39:32] are written to bits [71:64] of the result. \n
end_comment

begin_comment
comment|///    Bits [47:40] are written to bits [87:80] of the result. \n
end_comment

begin_comment
comment|///    Bits [55:48] are written to bits [103:96] of the result. \n
end_comment

begin_comment
comment|///    Bits [63:56] are written to bits [119:112] of the result.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8].
end_comment

begin_comment
comment|///    Bits [7:0] are written to bits [15:8] of the result. \n
end_comment

begin_comment
comment|///    Bits [15:8] are written to bits [31:24] of the result. \n
end_comment

begin_comment
comment|///    Bits [23:16] are written to bits [47:40] of the result. \n
end_comment

begin_comment
comment|///    Bits [31:24] are written to bits [63:56] of the result. \n
end_comment

begin_comment
comment|///    Bits [39:32] are written to bits [79:72] of the result. \n
end_comment

begin_comment
comment|///    Bits [47:40] are written to bits [95:88] of the result. \n
end_comment

begin_comment
comment|///    Bits [55:48] are written to bits [111:104] of the result. \n
end_comment

begin_comment
comment|///    Bits [63:56] are written to bits [127:120] of the result.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [16 x i8] containing the interleaved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_unpacklo_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|,
operator|(
name|__v16qi
operator|)
name|__b
argument_list|,
literal|0
argument_list|,
literal|16
operator|+
literal|0
argument_list|,
literal|1
argument_list|,
literal|16
operator|+
literal|1
argument_list|,
literal|2
argument_list|,
literal|16
operator|+
literal|2
argument_list|,
literal|3
argument_list|,
literal|16
operator|+
literal|3
argument_list|,
literal|4
argument_list|,
literal|16
operator|+
literal|4
argument_list|,
literal|5
argument_list|,
literal|16
operator|+
literal|5
argument_list|,
literal|6
argument_list|,
literal|16
operator|+
literal|6
argument_list|,
literal|7
argument_list|,
literal|16
operator|+
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Unpacks the low-order (index 0-3) values from each of the two 128-bit
end_comment

begin_comment
comment|///    vectors of [8 x i16] and interleaves them into a 128-bit vector of
end_comment

begin_comment
comment|///    [8 x i16].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPUNPCKLWD / PUNPCKLWD</c>
end_comment

begin_comment
comment|///   instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16].
end_comment

begin_comment
comment|///    Bits [15:0] are written to bits [15:0] of the result. \n
end_comment

begin_comment
comment|///    Bits [31:16] are written to bits [47:32] of the result. \n
end_comment

begin_comment
comment|///    Bits [47:32] are written to bits [79:64] of the result. \n
end_comment

begin_comment
comment|///    Bits [63:48] are written to bits [111:96] of the result.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16].
end_comment

begin_comment
comment|///    Bits [15:0] are written to bits [31:16] of the result. \n
end_comment

begin_comment
comment|///    Bits [31:16] are written to bits [63:48] of the result. \n
end_comment

begin_comment
comment|///    Bits [47:32] are written to bits [95:80] of the result. \n
end_comment

begin_comment
comment|///    Bits [63:48] are written to bits [127:112] of the result.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [8 x i16] containing the interleaved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_unpacklo_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|,
literal|0
argument_list|,
literal|8
operator|+
literal|0
argument_list|,
literal|1
argument_list|,
literal|8
operator|+
literal|1
argument_list|,
literal|2
argument_list|,
literal|8
operator|+
literal|2
argument_list|,
literal|3
argument_list|,
literal|8
operator|+
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Unpacks the low-order (index 0,1) values from two 128-bit vectors of
end_comment

begin_comment
comment|///    [4 x i32] and interleaves them into a 128-bit vector of [4 x i32].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPUNPCKLDQ / PUNPCKLDQ</c>
end_comment

begin_comment
comment|///   instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x i32]. \n
end_comment

begin_comment
comment|///    Bits [31:0] are written to bits [31:0] of the destination. \n
end_comment

begin_comment
comment|///    Bits [63:32] are written to bits [95:64] of the destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x i32]. \n
end_comment

begin_comment
comment|///    Bits [31:0] are written to bits [64:32] of the destination. \n
end_comment

begin_comment
comment|///    Bits [63:32] are written to bits [127:96] of the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x i32] containing the interleaved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_unpacklo_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
operator|(
name|__v4si
operator|)
name|__b
argument_list|,
literal|0
argument_list|,
literal|4
operator|+
literal|0
argument_list|,
literal|1
argument_list|,
literal|4
operator|+
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Unpacks the low-order 64-bit elements from two 128-bit vectors of
end_comment

begin_comment
comment|///    [2 x i64] and interleaves them into a 128-bit vector of [2 x i64].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPUNPCKLQDQ / PUNPCKLQDQ</c>
end_comment

begin_comment
comment|///   instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x i64]. \n
end_comment

begin_comment
comment|///    Bits [63:0] are written to bits [63:0] of the destination. \n
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x i64]. \n
end_comment

begin_comment
comment|///    Bits [63:0] are written to bits [127:64] of the destination. \n
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x i64] containing the interleaved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_unpacklo_epi64
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v2di
operator|)
name|__a
argument_list|,
operator|(
name|__v2di
operator|)
name|__b
argument_list|,
literal|0
argument_list|,
literal|2
operator|+
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Returns the lower 64 bits of a 128-bit integer vector as a 64-bit
end_comment

begin_comment
comment|///    integer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic has no corresponding instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector operand. The lower 64 bits are moved to the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 64-bit integer containing the lower 64 bits of the parameter.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_movepi64_pi64
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__a
index|[
literal|0
index|]
return|;
block|}
end_function

begin_comment
comment|/// \brief Moves the 64-bit operand to a 128-bit integer vector, zeroing the
end_comment

begin_comment
comment|///    upper bits.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVQ / MOVQ / MOVD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit value.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector. The lower 64 bits contain the value from
end_comment

begin_comment
comment|///    the operand. The upper 64 bits are assigned zeros.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_movpi64_epi64
parameter_list|(
name|__m64
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
block|{
operator|(
name|long
name|long
operator|)
name|__a
block|,
literal|0
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Moves the lower 64 bits of a 128-bit integer vector to a 128-bit
end_comment

begin_comment
comment|///    integer vector, zeroing the upper bits.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVQ / MOVQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector operand. The lower 64 bits are moved to the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector. The lower 64 bits contain the value from
end_comment

begin_comment
comment|///    the operand. The upper 64 bits are assigned zeros.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_move_epi64
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v2di
operator|)
name|__a
argument_list|,
operator|(
name|__m128i
operator|)
block|{
literal|0
block|}
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Unpacks the high-order (odd-indexed) values from two 128-bit vectors
end_comment

begin_comment
comment|///    of [2 x double] and interleaves them into a 128-bit vector of [2 x
end_comment

begin_comment
comment|///    double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VUNPCKHPD / UNPCKHPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. \n
end_comment

begin_comment
comment|///    Bits [127:64] are written to bits [63:0] of the destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. \n
end_comment

begin_comment
comment|///    Bits [127:64] are written to bits [127:64] of the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the interleaved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_unpackhi_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|,
literal|1
argument_list|,
literal|2
operator|+
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Unpacks the low-order (even-indexed) values from two 128-bit vectors
end_comment

begin_comment
comment|///    of [2 x double] and interleaves them into a 128-bit vector of [2 x
end_comment

begin_comment
comment|///    double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VUNPCKLPD / UNPCKLPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. \n
end_comment

begin_comment
comment|///    Bits [63:0] are written to bits [63:0] of the destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. \n
end_comment

begin_comment
comment|///    Bits [63:0] are written to bits [127:64] of the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the interleaved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_unpacklo_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|,
literal|0
argument_list|,
literal|2
operator|+
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Extracts the sign bits of the double-precision values in the 128-bit
end_comment

begin_comment
comment|///    vector of [2 x double], zero-extends the value, and writes it to the
end_comment

begin_comment
comment|///    low-order bits of the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVMSKPD / MOVMSKPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing the values with sign bits to
end_comment

begin_comment
comment|///    be extracted.
end_comment

begin_comment
comment|/// \returns The sign bits from each of the double-precision elements in \a __a,
end_comment

begin_comment
comment|///    written to bits [1:0]. The remaining bits are assigned values of zero.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_movemask_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_movmskpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit floating-point vector of [2 x double] from two
end_comment

begin_comment
comment|///    128-bit vector parameters of [2 x double], using the immediate-value
end_comment

begin_comment
comment|///     parameter as a specifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// __m128d _mm_shuffle_pd(__m128d a, __m128d b, const int i);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VSHUFPD / SHUFPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param i
end_comment

begin_comment
comment|///    An 8-bit immediate value. The least significant two bits specify which
end_comment

begin_comment
comment|///    elements to copy from a and b: \n
end_comment

begin_comment
comment|///    Bit[0] = 0: lower element of a copied to lower element of result. \n
end_comment

begin_comment
comment|///    Bit[0] = 1: upper element of a copied to lower element of result. \n
end_comment

begin_comment
comment|///    Bit[1] = 0: lower element of \a b copied to upper element of result. \n
end_comment

begin_comment
comment|///    Bit[1] = 1: upper element of \a b copied to upper element of result. \n
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the shuffled values.
end_comment

begin_define
define|#
directive|define
name|_mm_shuffle_pd
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|i
parameter_list|)
value|__extension__ ({ \   (__m128d)__builtin_shufflevector((__v2df)(__m128d)(a), (__v2df)(__m128d)(b), \                                    0 + (((i)>> 0)& 0x1), \                                    2 + (((i)>> 1)& 0x1)); })
end_define

begin_comment
comment|/// \brief Casts a 128-bit floating-point vector of [2 x double] into a 128-bit
end_comment

begin_comment
comment|///    floating-point vector of [4 x float].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic has no corresponding instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit floating-point vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 128-bit floating-point vector of [4 x float] containing the same
end_comment

begin_comment
comment|///    bitwise pattern as the parameter.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_castpd_ps
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__a
return|;
block|}
end_function

begin_comment
comment|/// \brief Casts a 128-bit floating-point vector of [2 x double] into a 128-bit
end_comment

begin_comment
comment|///    integer vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic has no corresponding instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit floating-point vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the same bitwise pattern as the
end_comment

begin_comment
comment|///    parameter.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_castpd_si128
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__a
return|;
block|}
end_function

begin_comment
comment|/// \brief Casts a 128-bit floating-point vector of [4 x float] into a 128-bit
end_comment

begin_comment
comment|///    floating-point vector of [2 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic has no corresponding instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit floating-point vector of [4 x float].
end_comment

begin_comment
comment|/// \returns A 128-bit floating-point vector of [2 x double] containing the same
end_comment

begin_comment
comment|///    bitwise pattern as the parameter.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_castps_pd
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__a
return|;
block|}
end_function

begin_comment
comment|/// \brief Casts a 128-bit floating-point vector of [4 x float] into a 128-bit
end_comment

begin_comment
comment|///    integer vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic has no corresponding instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit floating-point vector of [4 x float].
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the same bitwise pattern as the
end_comment

begin_comment
comment|///    parameter.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_castps_si128
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__a
return|;
block|}
end_function

begin_comment
comment|/// \brief Casts a 128-bit integer vector into a 128-bit floating-point vector
end_comment

begin_comment
comment|///    of [4 x float].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic has no corresponding instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit floating-point vector of [4 x float] containing the same
end_comment

begin_comment
comment|///    bitwise pattern as the parameter.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_castsi128_ps
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__a
return|;
block|}
end_function

begin_comment
comment|/// \brief Casts a 128-bit integer vector into a 128-bit floating-point vector
end_comment

begin_comment
comment|///    of [2 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic has no corresponding instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit floating-point vector of [2 x double] containing the same
end_comment

begin_comment
comment|///    bitwise pattern as the parameter.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_castsi128_pd
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__a
return|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/// \brief Indicates that a spin loop is being executed for the purposes of
comment|///    optimizing power consumption during the loop.
comment|///
comment|/// \headerfile<x86intrin.h>
comment|///
comment|/// This intrinsic corresponds to the<c> PAUSE</c> instruction.
comment|///
name|void
name|_mm_pause
parameter_list|(
name|void
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|__DEFAULT_FN_ATTRS
end_undef

begin_define
define|#
directive|define
name|_MM_SHUFFLE2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)<< 1) | (y))
end_define

begin_define
define|#
directive|define
name|_MM_DENORMALS_ZERO_ON
value|(0x0040)
end_define

begin_define
define|#
directive|define
name|_MM_DENORMALS_ZERO_OFF
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|_MM_DENORMALS_ZERO_MASK
value|(0x0040)
end_define

begin_define
define|#
directive|define
name|_MM_GET_DENORMALS_ZERO_MODE
parameter_list|()
value|(_mm_getcsr()& _MM_DENORMALS_ZERO_MASK)
end_define

begin_define
define|#
directive|define
name|_MM_SET_DENORMALS_ZERO_MODE
parameter_list|(
name|x
parameter_list|)
value|(_mm_setcsr((_mm_getcsr()& ~_MM_DENORMALS_ZERO_MASK) | (x)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __EMMINTRIN_H */
end_comment

end_unit

