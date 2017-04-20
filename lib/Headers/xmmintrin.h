begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- xmmintrin.h - SSE intrinsics -------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XMMINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__XMMINTRIN_H
end_define

begin_include
include|#
directive|include
file|<mmintrin.h>
end_include

begin_typedef
typedef|typedef
name|int
name|__v4si
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|__v4sf
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|__m128
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
name|int
name|__v4su
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_comment
comment|/* This header should only be included in a hosted environment as it depends on  * a standard library to provide allocation routines. */
end_comment

begin_if
if|#
directive|if
name|__STDC_HOSTED__
end_if

begin_include
include|#
directive|include
file|<mm_malloc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the default attributes for the functions in this file. */
end_comment

begin_define
define|#
directive|define
name|__DEFAULT_FN_ATTRS
value|__attribute__((__always_inline__, __nodebug__, __target__("sse")))
end_define

begin_comment
comment|/// \brief Adds the 32-bit float values in the low-order bits of the operands.
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
comment|/// This intrinsic corresponds to the<c> VADDSS / ADDSS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the source operands.
end_comment

begin_comment
comment|///    The lower 32 bits of this operand are used in the calculation.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the source operands.
end_comment

begin_comment
comment|///    The lower 32 bits of this operand are used in the calculation.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] whose lower 32 bits contain the sum
end_comment

begin_comment
comment|///    of the lower 32 bits of both operands. The upper 96 bits are copied from
end_comment

begin_comment
comment|///    the upper 96 bits of the first source operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_add_ss
parameter_list|(
name|__m128
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
comment|/// \brief Adds two 128-bit vectors of [4 x float], and returns the results of
end_comment

begin_comment
comment|///    the addition.
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
comment|/// This intrinsic corresponds to the<c> VADDPS / ADDPS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the sums of both
end_comment

begin_comment
comment|///    operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_add_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128
call|)
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
operator|+
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts the 32-bit float value in the low-order bits of the second
end_comment

begin_comment
comment|///    operand from the corresponding value in the first operand.
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
comment|/// This intrinsic corresponds to the<c> VSUBSS / SUBSS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing the minuend. The lower 32 bits
end_comment

begin_comment
comment|///    of this operand are used in the calculation.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing the subtrahend. The lower 32
end_comment

begin_comment
comment|///    bits of this operand are used in the calculation.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] whose lower 32 bits contain the
end_comment

begin_comment
comment|///    difference of the lower 32 bits of both operands. The upper 96 bits are
end_comment

begin_comment
comment|///    copied from the upper 96 bits of the first source operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_sub_ss
parameter_list|(
name|__m128
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
comment|/// \brief Subtracts each of the values of the second operand from the first
end_comment

begin_comment
comment|///    operand, both of which are 128-bit vectors of [4 x float] and returns
end_comment

begin_comment
comment|///    the results of the subtraction.
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
comment|/// This intrinsic corresponds to the<c> VSUBPS / SUBPS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing the minuend.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing the subtrahend.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the differences between
end_comment

begin_comment
comment|///    both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_sub_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128
call|)
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
operator|-
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Multiplies two 32-bit float values in the low-order bits of the
end_comment

begin_comment
comment|///    operands.
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
comment|/// This intrinsic corresponds to the<c> VMULSS / MULSS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the source operands.
end_comment

begin_comment
comment|///    The lower 32 bits of this operand are used in the calculation.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the source operands.
end_comment

begin_comment
comment|///    The lower 32 bits of this operand are used in the calculation.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the product of the lower
end_comment

begin_comment
comment|///    32 bits of both operands. The upper 96 bits are copied from the upper 96
end_comment

begin_comment
comment|///    bits of the first source operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_mul_ss
parameter_list|(
name|__m128
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
comment|/// \brief Multiplies two 128-bit vectors of [4 x float] and returns the
end_comment

begin_comment
comment|///    results of the multiplication.
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
comment|/// This intrinsic corresponds to the<c> VMULPS / MULPS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the products of both
end_comment

begin_comment
comment|///    operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_mul_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128
call|)
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
operator|*
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Divides the value in the low-order 32 bits of the first operand by
end_comment

begin_comment
comment|///    the corresponding value in the second operand.
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
comment|/// This intrinsic corresponds to the<c> VDIVSS / DIVSS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing the dividend. The lower 32
end_comment

begin_comment
comment|///    bits of this operand are used in the calculation.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing the divisor. The lower 32 bits
end_comment

begin_comment
comment|///    of this operand are used in the calculation.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the quotients of the
end_comment

begin_comment
comment|///    lower 32 bits of both operands. The upper 96 bits are copied from the
end_comment

begin_comment
comment|///    upper 96 bits of the first source operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_div_ss
parameter_list|(
name|__m128
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
comment|/// \brief Divides two 128-bit vectors of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VDIVPS / DIVPS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing the dividend.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing the divisor.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the quotients of both
end_comment

begin_comment
comment|///    operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_div_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128
call|)
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
operator|/
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Calculates the square root of the value stored in the low-order bits
end_comment

begin_comment
comment|///    of a 128-bit vector of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VSQRTSS / SQRTSS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the calculation.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the square root of the
end_comment

begin_comment
comment|///    value in the low-order bits of the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_sqrt_ss
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
name|__m128
name|__c
init|=
name|__builtin_ia32_sqrtss
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|)
decl_stmt|;
return|return
operator|(
name|__m128
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
block|,
name|__a
index|[
literal|2
index|]
block|,
name|__a
index|[
literal|3
index|]
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Calculates the square roots of the values stored in a 128-bit vector
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
comment|/// This intrinsic corresponds to the<c> VSQRTPS / SQRTPS</c> instructions.
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
comment|/// \returns A 128-bit vector of [4 x float] containing the square roots of the
end_comment

begin_comment
comment|///    values in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_sqrt_ps
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_sqrtps
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
comment|/// \brief Calculates the approximate reciprocal of the value stored in the
end_comment

begin_comment
comment|///    low-order bits of a 128-bit vector of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VRCPSS / RCPSS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the calculation.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the approximate
end_comment

begin_comment
comment|///    reciprocal of the value in the low-order bits of the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_rcp_ss
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
name|__m128
name|__c
init|=
name|__builtin_ia32_rcpss
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|)
decl_stmt|;
return|return
operator|(
name|__m128
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
block|,
name|__a
index|[
literal|2
index|]
block|,
name|__a
index|[
literal|3
index|]
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Calculates the approximate reciprocals of the values stored in a
end_comment

begin_comment
comment|///    128-bit vector of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VRCPPS / RCPPS</c> instructions.
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
comment|/// \returns A 128-bit vector of [4 x float] containing the approximate
end_comment

begin_comment
comment|///    reciprocals of the values in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_rcp_ps
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_rcpps
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
comment|/// \brief Calculates the approximate reciprocal of the square root of the value
end_comment

begin_comment
comment|///    stored in the low-order bits of a 128-bit vector of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VRSQRTSS / RSQRTSS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the calculation.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the approximate
end_comment

begin_comment
comment|///    reciprocal of the square root of the value in the low-order bits of the
end_comment

begin_comment
comment|///    operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_rsqrt_ss
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
name|__m128
name|__c
init|=
name|__builtin_ia32_rsqrtss
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|)
decl_stmt|;
return|return
operator|(
name|__m128
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
block|,
name|__a
index|[
literal|2
index|]
block|,
name|__a
index|[
literal|3
index|]
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Calculates the approximate reciprocals of the square roots of the
end_comment

begin_comment
comment|///    values stored in a 128-bit vector of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VRSQRTPS / RSQRTPS</c> instructions.
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
comment|/// \returns A 128-bit vector of [4 x float] containing the approximate
end_comment

begin_comment
comment|///    reciprocals of the square roots of the values in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_rsqrt_ps
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_rsqrtps
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
comment|/// \brief Compares two 32-bit float values in the low-order bits of both
end_comment

begin_comment
comment|///    operands and returns the lesser value in the low-order bits of the
end_comment

begin_comment
comment|///    vector of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VMINSS / MINSS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] whose lower 32 bits contain the
end_comment

begin_comment
comment|///    minimum value between both operands. The upper 96 bits are copied from
end_comment

begin_comment
comment|///    the upper 96 bits of the first source operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_min_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_minss
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 128-bit vectors of [4 x float] and returns the lesser
end_comment

begin_comment
comment|///    of each pair of values.
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
comment|/// This intrinsic corresponds to the<c> VMINPS / MINPS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the minimum values
end_comment

begin_comment
comment|///    between both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_min_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_minps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 32-bit float values in the low-order bits of both
end_comment

begin_comment
comment|///    operands and returns the greater value in the low-order bits of a 128-bit
end_comment

begin_comment
comment|///    vector of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VMAXSS / MAXSS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] whose lower 32 bits contain the
end_comment

begin_comment
comment|///    maximum value between both operands. The upper 96 bits are copied from
end_comment

begin_comment
comment|///    the upper 96 bits of the first source operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_max_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_maxss
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 128-bit vectors of [4 x float] and returns the greater
end_comment

begin_comment
comment|///    of each pair of values.
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
comment|/// This intrinsic corresponds to the<c> VMAXPS / MAXPS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the maximum values
end_comment

begin_comment
comment|///    between both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_max_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_maxps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise AND of two 128-bit vectors of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VANDPS / ANDPS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the bitwise AND of the
end_comment

begin_comment
comment|///    values between both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_and_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128
call|)
argument_list|(
operator|(
name|__v4su
operator|)
name|__a
operator|&
operator|(
name|__v4su
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise AND of two 128-bit vectors of [4 x float], using
end_comment

begin_comment
comment|///    the one's complement of the values contained in the first source
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
comment|/// This intrinsic corresponds to the<c> VANDNPS / ANDNPS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing the first source operand. The
end_comment

begin_comment
comment|///    one's complement of this value is used in the bitwise AND.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing the second source operand.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the bitwise AND of the
end_comment

begin_comment
comment|///    one's complement of the first operand and the values in the second
end_comment

begin_comment
comment|///    operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_andnot_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128
call|)
argument_list|(
operator|~
operator|(
name|__v4su
operator|)
name|__a
operator|&
operator|(
name|__v4su
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise OR of two 128-bit vectors of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VORPS / ORPS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the bitwise OR of the
end_comment

begin_comment
comment|///    values between both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_or_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128
call|)
argument_list|(
operator|(
name|__v4su
operator|)
name|__a
operator||
operator|(
name|__v4su
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise exclusive OR of two 128-bit vectors of
end_comment

begin_comment
comment|///    [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VXORPS / XORPS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the bitwise exclusive OR
end_comment

begin_comment
comment|///    of the values between both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_xor_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128
call|)
argument_list|(
operator|(
name|__v4su
operator|)
name|__a
operator|^
operator|(
name|__v4su
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 32-bit float values in the low-order bits of both
end_comment

begin_comment
comment|///    operands for equality and returns the result of the comparison in the
end_comment

begin_comment
comment|///    low-order bits of a vector [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VCMPEQSS / CMPEQSS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results
end_comment

begin_comment
comment|///    in the low-order bits.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmpeq_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cmpeqss
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding 32-bit float values of the
end_comment

begin_comment
comment|///    128-bit vectors of [4 x float] for equality.
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
comment|/// This intrinsic corresponds to the<c> VCMPEQPS / CMPEQPS</c> instructions.
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
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmpeq_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cmpeqps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 32-bit float values in the low-order bits of both
end_comment

begin_comment
comment|///    operands to determine if the value in the first operand is less than the
end_comment

begin_comment
comment|///    corresponding value in the second operand and returns the result of the
end_comment

begin_comment
comment|///    comparison in the low-order bits of a vector of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VCMPLTSS / CMPLTSS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results
end_comment

begin_comment
comment|///    in the low-order bits.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmplt_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cmpltss
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding 32-bit float values of the
end_comment

begin_comment
comment|///    128-bit vectors of [4 x float] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are less than those in the second operand.
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
comment|/// This intrinsic corresponds to the<c> VCMPLTPS / CMPLTPS</c> instructions.
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
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmplt_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cmpltps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 32-bit float values in the low-order bits of both
end_comment

begin_comment
comment|///    operands to determine if the value in the first operand is less than or
end_comment

begin_comment
comment|///    equal to the corresponding value in the second operand and returns the
end_comment

begin_comment
comment|///    result of the comparison in the low-order bits of a vector of
end_comment

begin_comment
comment|///    [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VCMPLESS / CMPLESS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results
end_comment

begin_comment
comment|///    in the low-order bits.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmple_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cmpless
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding 32-bit float values of the
end_comment

begin_comment
comment|///    128-bit vectors of [4 x float] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are less than or equal to those in the second operand.
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
comment|/// This intrinsic corresponds to the<c> VCMPLEPS / CMPLEPS</c> instructions.
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
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmple_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cmpleps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 32-bit float values in the low-order bits of both
end_comment

begin_comment
comment|///    operands to determine if the value in the first operand is greater than
end_comment

begin_comment
comment|///    the corresponding value in the second operand and returns the result of
end_comment

begin_comment
comment|///    the comparison in the low-order bits of a vector of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VCMPLTSS / CMPLTSS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results
end_comment

begin_comment
comment|///    in the low-order bits.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmpgt_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
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
name|__builtin_ia32_cmpltss
argument_list|(
operator|(
name|__v4sf
operator|)
name|__b
argument_list|,
operator|(
name|__v4sf
operator|)
name|__a
argument_list|)
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding 32-bit float values of the
end_comment

begin_comment
comment|///    128-bit vectors of [4 x float] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are greater than those in the second operand.
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
comment|/// This intrinsic corresponds to the<c> VCMPLTPS / CMPLTPS</c> instructions.
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
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmpgt_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cmpltps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__b
argument_list|,
operator|(
name|__v4sf
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 32-bit float values in the low-order bits of both
end_comment

begin_comment
comment|///    operands to determine if the value in the first operand is greater than
end_comment

begin_comment
comment|///    or equal to the corresponding value in the second operand and returns
end_comment

begin_comment
comment|///    the result of the comparison in the low-order bits of a vector of
end_comment

begin_comment
comment|///    [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VCMPLESS / CMPLESS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results
end_comment

begin_comment
comment|///    in the low-order bits.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmpge_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
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
name|__builtin_ia32_cmpless
argument_list|(
operator|(
name|__v4sf
operator|)
name|__b
argument_list|,
operator|(
name|__v4sf
operator|)
name|__a
argument_list|)
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding 32-bit float values of the
end_comment

begin_comment
comment|///    128-bit vectors of [4 x float] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are greater than or equal to those in the second operand.
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
comment|/// This intrinsic corresponds to the<c> VCMPLEPS / CMPLEPS</c> instructions.
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
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmpge_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cmpleps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__b
argument_list|,
operator|(
name|__v4sf
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 32-bit float values in the low-order bits of both
end_comment

begin_comment
comment|///    operands for inequality and returns the result of the comparison in the
end_comment

begin_comment
comment|///    low-order bits of a vector of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VCMPNEQSS / CMPNEQSS</c>
end_comment

begin_comment
comment|///   instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results
end_comment

begin_comment
comment|///    in the low-order bits.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmpneq_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cmpneqss
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding 32-bit float values of the
end_comment

begin_comment
comment|///    128-bit vectors of [4 x float] for inequality.
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
comment|/// This intrinsic corresponds to the<c> VCMPNEQPS / CMPNEQPS</c>
end_comment

begin_comment
comment|///   instructions.
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
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmpneq_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cmpneqps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 32-bit float values in the low-order bits of both
end_comment

begin_comment
comment|///    operands to determine if the value in the first operand is not less than
end_comment

begin_comment
comment|///    the corresponding value in the second operand and returns the result of
end_comment

begin_comment
comment|///    the comparison in the low-order bits of a vector of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VCMPNLTSS / CMPNLTSS</c>
end_comment

begin_comment
comment|///   instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results
end_comment

begin_comment
comment|///    in the low-order bits.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmpnlt_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cmpnltss
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding 32-bit float values of the
end_comment

begin_comment
comment|///    128-bit vectors of [4 x float] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are not less than those in the second operand.
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
comment|/// This intrinsic corresponds to the<c> VCMPNLTPS / CMPNLTPS</c>
end_comment

begin_comment
comment|///   instructions.
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
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmpnlt_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cmpnltps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 32-bit float values in the low-order bits of both
end_comment

begin_comment
comment|///    operands to determine if the value in the first operand is not less than
end_comment

begin_comment
comment|///    or equal to the corresponding value in the second operand and returns
end_comment

begin_comment
comment|///    the result of the comparison in the low-order bits of a vector of
end_comment

begin_comment
comment|///    [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VCMPNLESS / CMPNLESS</c>
end_comment

begin_comment
comment|///   instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results
end_comment

begin_comment
comment|///    in the low-order bits.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmpnle_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cmpnless
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding 32-bit float values of the
end_comment

begin_comment
comment|///    128-bit vectors of [4 x float] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are not less than or equal to those in the second operand.
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
comment|/// This intrinsic corresponds to the<c> VCMPNLEPS / CMPNLEPS</c>
end_comment

begin_comment
comment|///   instructions.
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
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmpnle_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cmpnleps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 32-bit float values in the low-order bits of both
end_comment

begin_comment
comment|///    operands to determine if the value in the first operand is not greater
end_comment

begin_comment
comment|///    than the corresponding value in the second operand and returns the
end_comment

begin_comment
comment|///    result of the comparison in the low-order bits of a vector of
end_comment

begin_comment
comment|///    [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VCMPNLTSS / CMPNLTSS</c>
end_comment

begin_comment
comment|///   instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results
end_comment

begin_comment
comment|///    in the low-order bits.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmpngt_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
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
name|__builtin_ia32_cmpnltss
argument_list|(
operator|(
name|__v4sf
operator|)
name|__b
argument_list|,
operator|(
name|__v4sf
operator|)
name|__a
argument_list|)
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding 32-bit float values of the
end_comment

begin_comment
comment|///    128-bit vectors of [4 x float] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are not greater than those in the second operand.
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
comment|/// This intrinsic corresponds to the<c> VCMPNLTPS / CMPNLTPS</c>
end_comment

begin_comment
comment|///   instructions.
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
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmpngt_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cmpnltps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__b
argument_list|,
operator|(
name|__v4sf
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 32-bit float values in the low-order bits of both
end_comment

begin_comment
comment|///    operands to determine if the value in the first operand is not greater
end_comment

begin_comment
comment|///    than or equal to the corresponding value in the second operand and
end_comment

begin_comment
comment|///    returns the result of the comparison in the low-order bits of a vector
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
comment|/// This intrinsic corresponds to the<c> VCMPNLESS / CMPNLESS</c>
end_comment

begin_comment
comment|///   instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results
end_comment

begin_comment
comment|///    in the low-order bits.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmpnge_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
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
name|__builtin_ia32_cmpnless
argument_list|(
operator|(
name|__v4sf
operator|)
name|__b
argument_list|,
operator|(
name|__v4sf
operator|)
name|__a
argument_list|)
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding 32-bit float values of the
end_comment

begin_comment
comment|///    128-bit vectors of [4 x float] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are not greater than or equal to those in the second operand.
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
comment|/// This intrinsic corresponds to the<c> VCMPNLEPS / CMPNLEPS</c>
end_comment

begin_comment
comment|///   instructions.
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
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmpnge_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cmpnleps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__b
argument_list|,
operator|(
name|__v4sf
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 32-bit float values in the low-order bits of both
end_comment

begin_comment
comment|///    operands to determine if the value in the first operand is ordered with
end_comment

begin_comment
comment|///    respect to the corresponding value in the second operand and returns the
end_comment

begin_comment
comment|///    result of the comparison in the low-order bits of a vector of
end_comment

begin_comment
comment|///    [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VCMPORDSS / CMPORDSS</c>
end_comment

begin_comment
comment|///   instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results
end_comment

begin_comment
comment|///    in the low-order bits.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmpord_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cmpordss
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding 32-bit float values of the
end_comment

begin_comment
comment|///    128-bit vectors of [4 x float] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are ordered with respect to those in the second operand.
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
comment|/// This intrinsic corresponds to the<c> VCMPORDPS / CMPORDPS</c>
end_comment

begin_comment
comment|///   instructions.
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
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmpord_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cmpordps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 32-bit float values in the low-order bits of both
end_comment

begin_comment
comment|///    operands to determine if the value in the first operand is unordered
end_comment

begin_comment
comment|///    with respect to the corresponding value in the second operand and
end_comment

begin_comment
comment|///    returns the result of the comparison in the low-order bits of a vector
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
comment|/// This intrinsic corresponds to the<c> VCMPUNORDSS / CMPUNORDSS</c>
end_comment

begin_comment
comment|///   instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the operands. The lower
end_comment

begin_comment
comment|///    32 bits of this operand are used in the comparison.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results
end_comment

begin_comment
comment|///    in the low-order bits.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmpunord_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cmpunordss
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding 32-bit float values of the
end_comment

begin_comment
comment|///    128-bit vectors of [4 x float] to determine if the values in the first
end_comment

begin_comment
comment|///    operand are unordered with respect to those in the second operand.
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
comment|/// This intrinsic corresponds to the<c> VCMPUNORDPS / CMPUNORDPS</c>
end_comment

begin_comment
comment|///   instructions.
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
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cmpunord_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cmpunordps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 32-bit float values in the low-order bits of both
end_comment

begin_comment
comment|///    operands for equality and returns the result of the comparison.
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
comment|/// This intrinsic corresponds to the<c> VCOMISS / COMISS</c>
end_comment

begin_comment
comment|///   instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_comieq_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_comieq
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 32-bit float values in the low-order bits of both
end_comment

begin_comment
comment|///    operands to determine if the first operand is less than the second
end_comment

begin_comment
comment|///    operand and returns the result of the comparison.
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
comment|/// This intrinsic corresponds to the<c> VCOMISS / COMISS</c>
end_comment

begin_comment
comment|///   instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_comilt_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_comilt
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 32-bit float values in the low-order bits of both
end_comment

begin_comment
comment|///    operands to determine if the first operand is less than or equal to the
end_comment

begin_comment
comment|///    second operand and returns the result of the comparison.
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
comment|/// This intrinsic corresponds to the<c> VCOMISS / COMISS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_comile_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_comile
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 32-bit float values in the low-order bits of both
end_comment

begin_comment
comment|///    operands to determine if the first operand is greater than the second
end_comment

begin_comment
comment|///    operand and returns the result of the comparison.
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
comment|/// This intrinsic corresponds to the<c> VCOMISS / COMISS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_comigt_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_comigt
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 32-bit float values in the low-order bits of both
end_comment

begin_comment
comment|///    operands to determine if the first operand is greater than or equal to
end_comment

begin_comment
comment|///    the second operand and returns the result of the comparison.
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
comment|/// This intrinsic corresponds to the<c> VCOMISS / COMISS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_comige_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_comige
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 32-bit float values in the low-order bits of both
end_comment

begin_comment
comment|///    operands to determine if the first operand is not equal to the second
end_comment

begin_comment
comment|///    operand and returns the result of the comparison.
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
comment|/// This intrinsic corresponds to the<c> VCOMISS / COMISS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_comineq_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_comineq
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs an unordered comparison of two 32-bit float values using
end_comment

begin_comment
comment|///    the low-order bits of both operands to determine equality and returns
end_comment

begin_comment
comment|///    the result of the comparison.
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
comment|/// This intrinsic corresponds to the<c> VUCOMISS / UCOMISS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_ucomieq_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ucomieq
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs an unordered comparison of two 32-bit float values using
end_comment

begin_comment
comment|///    the low-order bits of both operands to determine if the first operand is
end_comment

begin_comment
comment|///    less than the second operand and returns the result of the comparison.
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
comment|/// This intrinsic corresponds to the<c> VUCOMISS / UCOMISS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_ucomilt_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ucomilt
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs an unordered comparison of two 32-bit float values using
end_comment

begin_comment
comment|///    the low-order bits of both operands to determine if the first operand is
end_comment

begin_comment
comment|///    less than or equal to the second operand and returns the result of the
end_comment

begin_comment
comment|///    comparison.
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
comment|/// This intrinsic corresponds to the<c> VUCOMISS / UCOMISS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_ucomile_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ucomile
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs an unordered comparison of two 32-bit float values using
end_comment

begin_comment
comment|///    the low-order bits of both operands to determine if the first operand is
end_comment

begin_comment
comment|///    greater than the second operand and returns the result of the
end_comment

begin_comment
comment|///    comparison.
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
comment|/// This intrinsic corresponds to the<c> VUCOMISS / UCOMISS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_ucomigt_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ucomigt
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs an unordered comparison of two 32-bit float values using
end_comment

begin_comment
comment|///    the low-order bits of both operands to determine if the first operand is
end_comment

begin_comment
comment|///    greater than or equal to the second operand and returns the result of
end_comment

begin_comment
comment|///    the comparison.
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
comment|/// This intrinsic corresponds to the<c> VUCOMISS / UCOMISS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_ucomige_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ucomige
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs an unordered comparison of two 32-bit float values using
end_comment

begin_comment
comment|///    the low-order bits of both operands to determine inequality and returns
end_comment

begin_comment
comment|///    the result of the comparison.
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
comment|/// This intrinsic corresponds to the<c> VUCOMISS / UCOMISS</c> instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the comparison.
end_comment

begin_comment
comment|/// \returns An integer containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_ucomineq_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ucomineq
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts a float value contained in the lower 32 bits of a vector of
end_comment

begin_comment
comment|///    [4 x float] into a 32-bit integer.
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
comment|/// This intrinsic corresponds to the<c> VCVTSS2SI / CVTSS2SI</c>
end_comment

begin_comment
comment|///   instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the conversion.
end_comment

begin_comment
comment|/// \returns A 32-bit integer containing the converted value.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_cvtss_si32
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvtss2si
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
comment|/// \brief Converts a float value contained in the lower 32 bits of a vector of
end_comment

begin_comment
comment|///    [4 x float] into a 32-bit integer.
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
comment|/// This intrinsic corresponds to the<c> VCVTSS2SI / CVTSS2SI</c>
end_comment

begin_comment
comment|///   instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the conversion.
end_comment

begin_comment
comment|/// \returns A 32-bit integer containing the converted value.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_cvt_ss2si
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
name|_mm_cvtss_si32
argument_list|(
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
comment|/// \brief Converts a float value contained in the lower 32 bits of a vector of
end_comment

begin_comment
comment|///    [4 x float] into a 64-bit integer.
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
comment|/// This intrinsic corresponds to the<c> VCVTSS2SI / CVTSS2SI</c>
end_comment

begin_comment
comment|///   instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the conversion.
end_comment

begin_comment
comment|/// \returns A 64-bit integer containing the converted value.
end_comment

begin_function
specifier|static
name|__inline__
name|long
name|long
name|__DEFAULT_FN_ATTRS
name|_mm_cvtss_si64
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvtss2si64
argument_list|(
operator|(
name|__v4sf
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
comment|/// \brief Converts two low-order float values in a 128-bit vector of
end_comment

begin_comment
comment|///    [4 x float] into a 64-bit vector of [2 x i32].
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
comment|/// This intrinsic corresponds to the<c> CVTPS2PI</c> instruction.
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
comment|/// \returns A 64-bit integer vector containing the converted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_cvtps_pi32
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_cvtps2pi
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
comment|/// \brief Converts two low-order float values in a 128-bit vector of
end_comment

begin_comment
comment|///    [4 x float] into a 64-bit vector of [2 x i32].
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
comment|/// This intrinsic corresponds to the<c> CVTPS2PI</c> instruction.
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
comment|/// \returns A 64-bit integer vector containing the converted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_cvt_ps2pi
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
name|_mm_cvtps_pi32
argument_list|(
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts a float value contained in the lower 32 bits of a vector of
end_comment

begin_comment
comment|///    [4 x float] into a 32-bit integer, truncating the result when it is
end_comment

begin_comment
comment|///    inexact.
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
comment|/// This intrinsic corresponds to the<c> VCVTTSS2SI / CVTTSS2SI</c>
end_comment

begin_comment
comment|///   instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the conversion.
end_comment

begin_comment
comment|/// \returns A 32-bit integer containing the converted value.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_cvttss_si32
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvttss2si
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
comment|/// \brief Converts a float value contained in the lower 32 bits of a vector of
end_comment

begin_comment
comment|///    [4 x float] into a 32-bit integer, truncating the result when it is
end_comment

begin_comment
comment|///    inexact.
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
comment|/// This intrinsic corresponds to the<c> VCVTTSS2SI / CVTTSS2SI</c>
end_comment

begin_comment
comment|///   instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the conversion.
end_comment

begin_comment
comment|/// \returns A 32-bit integer containing the converted value.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_cvtt_ss2si
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
name|_mm_cvttss_si32
argument_list|(
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
comment|/// \brief Converts a float value contained in the lower 32 bits of a vector of
end_comment

begin_comment
comment|///    [4 x float] into a 64-bit integer, truncating the result when it is
end_comment

begin_comment
comment|///    inexact.
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
comment|/// This intrinsic corresponds to the<c> VCVTTSS2SI / CVTTSS2SI</c>
end_comment

begin_comment
comment|///   instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the conversion.
end_comment

begin_comment
comment|/// \returns A 64-bit integer containing the converted value.
end_comment

begin_function
specifier|static
name|__inline__
name|long
name|long
name|__DEFAULT_FN_ATTRS
name|_mm_cvttss_si64
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvttss2si64
argument_list|(
operator|(
name|__v4sf
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
comment|/// \brief Converts two low-order float values in a 128-bit vector of
end_comment

begin_comment
comment|///    [4 x float] into a 64-bit vector of [2 x i32], truncating the result
end_comment

begin_comment
comment|///    when it is inexact.
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
comment|/// This intrinsic corresponds to the<c> CVTTPS2PI / VTTPS2PI</c>
end_comment

begin_comment
comment|///   instructions.
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
comment|/// \returns A 64-bit integer vector containing the converted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_cvttps_pi32
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_cvttps2pi
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
comment|/// \brief Converts two low-order float values in a 128-bit vector of [4 x
end_comment

begin_comment
comment|///    float] into a 64-bit vector of [2 x i32], truncating the result when it
end_comment

begin_comment
comment|///    is inexact.
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
comment|/// This intrinsic corresponds to the<c> CVTTPS2PI</c> instruction.
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
comment|/// \returns A 64-bit integer vector containing the converted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_cvtt_ps2pi
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
name|_mm_cvttps_pi32
argument_list|(
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts a 32-bit signed integer value into a floating point value
end_comment

begin_comment
comment|///    and writes it to the lower 32 bits of the destination. The remaining
end_comment

begin_comment
comment|///    higher order elements of the destination vector are copied from the
end_comment

begin_comment
comment|///    corresponding elements in the first operand.
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
comment|/// This intrinsic corresponds to the<c> VCVTSI2SS / CVTSI2SS</c> instruction.
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
comment|/// \param __b
end_comment

begin_comment
comment|///    A 32-bit signed integer operand containing the value to be converted.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] whose lower 32 bits contain the
end_comment

begin_comment
comment|///    converted value of the second operand. The upper 96 bits are copied from
end_comment

begin_comment
comment|///    the upper 96 bits of the first operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsi32_ss
parameter_list|(
name|__m128
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
comment|/// \brief Converts a 32-bit signed integer value into a floating point value
end_comment

begin_comment
comment|///    and writes it to the lower 32 bits of the destination. The remaining
end_comment

begin_comment
comment|///    higher order elements of the destination are copied from the
end_comment

begin_comment
comment|///    corresponding elements in the first operand.
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
comment|/// This intrinsic corresponds to the<c> VCVTSI2SS / CVTSI2SS</c> instruction.
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
comment|/// \param __b
end_comment

begin_comment
comment|///    A 32-bit signed integer operand containing the value to be converted.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] whose lower 32 bits contain the
end_comment

begin_comment
comment|///    converted value of the second operand. The upper 96 bits are copied from
end_comment

begin_comment
comment|///    the upper 96 bits of the first operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cvt_si2ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|int
name|__b
parameter_list|)
block|{
return|return
name|_mm_cvtsi32_ss
argument_list|(
name|__a
argument_list|,
name|__b
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
comment|/// \brief Converts a 64-bit signed integer value into a floating point value
end_comment

begin_comment
comment|///    and writes it to the lower 32 bits of the destination. The remaining
end_comment

begin_comment
comment|///    higher order elements of the destination are copied from the
end_comment

begin_comment
comment|///    corresponding elements in the first operand.
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
comment|/// This intrinsic corresponds to the<c> VCVTSI2SS / CVTSI2SS</c> instruction.
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
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit signed integer operand containing the value to be converted.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] whose lower 32 bits contain the
end_comment

begin_comment
comment|///    converted value of the second operand. The upper 96 bits are copied from
end_comment

begin_comment
comment|///    the upper 96 bits of the first operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsi64_ss
parameter_list|(
name|__m128
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \brief Converts two elements of a 64-bit vector of [2 x i32] into two
end_comment

begin_comment
comment|///    floating point values and writes them to the lower 64-bits of the
end_comment

begin_comment
comment|///    destination. The remaining higher order elements of the destination are
end_comment

begin_comment
comment|///    copied from the corresponding elements in the first operand.
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
comment|/// This intrinsic corresponds to the<c> CVTPI2PS</c> instruction.
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
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit vector of [2 x i32]. The elements in this vector are converted
end_comment

begin_comment
comment|///    and written to the corresponding low-order elements in the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] whose lower 64 bits contain the
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
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cvtpi32_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m64
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvtpi2ps
argument_list|(
operator|(
name|__v4sf
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
comment|/// \brief Converts two elements of a 64-bit vector of [2 x i32] into two
end_comment

begin_comment
comment|///    floating point values and writes them to the lower 64-bits of the
end_comment

begin_comment
comment|///    destination. The remaining higher order elements of the destination are
end_comment

begin_comment
comment|///    copied from the corresponding elements in the first operand.
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
comment|/// This intrinsic corresponds to the<c> CVTPI2PS</c> instruction.
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
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit vector of [2 x i32]. The elements in this vector are converted
end_comment

begin_comment
comment|///    and written to the corresponding low-order elements in the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] whose lower 64 bits contain the
end_comment

begin_comment
comment|///    converted value from the second operand. The upper 64 bits are copied
end_comment

begin_comment
comment|///    from the upper 64 bits of the first operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cvt_pi2ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m64
name|__b
parameter_list|)
block|{
return|return
name|_mm_cvtpi32_ps
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Extracts a float value contained in the lower 32 bits of a vector of
end_comment

begin_comment
comment|///    [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VMOVSS / MOVSS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The lower 32 bits of this operand are
end_comment

begin_comment
comment|///    used in the extraction.
end_comment

begin_comment
comment|/// \returns A 32-bit float containing the extracted value.
end_comment

begin_function
specifier|static
name|__inline__
name|float
name|__DEFAULT_FN_ATTRS
name|_mm_cvtss_f32
parameter_list|(
name|__m128
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
comment|/// \brief Loads two packed float values from the address \a __p into the
end_comment

begin_comment
comment|///     high-order bits of a 128-bit vector of [4 x float]. The low-order bits
end_comment

begin_comment
comment|///     are copied from the low-order bits of the first operand.
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
comment|///    A 128-bit vector of [4 x float]. Bits [63:0] are written to bits [63:0]
end_comment

begin_comment
comment|///    of the destination.
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to two packed float values. Bits [63:0] are written to bits
end_comment

begin_comment
comment|///    [127:64] of the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the moved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_loadh_pi
parameter_list|(
name|__m128
name|__a
parameter_list|,
specifier|const
name|__m64
modifier|*
name|__p
parameter_list|)
block|{
typedef|typedef
name|float
name|__mm_loadh_pi_v2f32
name|__attribute__
typedef|((
name|__vector_size__
typedef|(8)));
struct|struct
name|__mm_loadh_pi_struct
block|{
name|__mm_loadh_pi_v2f32
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
name|__mm_loadh_pi_v2f32
name|__b
init|=
operator|(
operator|(
expr|struct
name|__mm_loadh_pi_struct
operator|*
operator|)
name|__p
operator|)
operator|->
name|__u
decl_stmt|;
name|__m128
name|__bb
init|=
name|__builtin_shufflevector
argument_list|(
name|__b
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
decl_stmt|;
return|return
name|__builtin_shufflevector
argument_list|(
name|__a
argument_list|,
name|__bb
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Loads two packed float values from the address \a __p into the
end_comment

begin_comment
comment|///    low-order bits of a 128-bit vector of [4 x float]. The high-order bits
end_comment

begin_comment
comment|///    are copied from the high-order bits of the first operand.
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
comment|///    A 128-bit vector of [4 x float]. Bits [127:64] are written to bits
end_comment

begin_comment
comment|///    [127:64] of the destination.
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to two packed float values. Bits [63:0] are written to bits
end_comment

begin_comment
comment|///    [63:0] of the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the moved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_loadl_pi
parameter_list|(
name|__m128
name|__a
parameter_list|,
specifier|const
name|__m64
modifier|*
name|__p
parameter_list|)
block|{
typedef|typedef
name|float
name|__mm_loadl_pi_v2f32
name|__attribute__
typedef|((
name|__vector_size__
typedef|(8)));
struct|struct
name|__mm_loadl_pi_struct
block|{
name|__mm_loadl_pi_v2f32
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
name|__mm_loadl_pi_v2f32
name|__b
init|=
operator|(
operator|(
expr|struct
name|__mm_loadl_pi_struct
operator|*
operator|)
name|__p
operator|)
operator|->
name|__u
decl_stmt|;
name|__m128
name|__bb
init|=
name|__builtin_shufflevector
argument_list|(
name|__b
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
decl_stmt|;
return|return
name|__builtin_shufflevector
argument_list|(
name|__a
argument_list|,
name|__bb
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit floating-point vector of [4 x float]. The lower
end_comment

begin_comment
comment|///    32 bits of the vector are initialized with the single-precision
end_comment

begin_comment
comment|///    floating-point value loaded from a specified memory location. The upper
end_comment

begin_comment
comment|///    96 bits are set to zero.
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
comment|/// This intrinsic corresponds to the<c> VMOVSS / MOVSS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to a 32-bit memory location containing a single-precision
end_comment

begin_comment
comment|///    floating-point value.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit floating-point vector of [4 x float]. The
end_comment

begin_comment
comment|///    lower 32 bits contain the value loaded from the memory location. The
end_comment

begin_comment
comment|///    upper 96 bits are set to zero.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_load_ss
parameter_list|(
specifier|const
name|float
modifier|*
name|__p
parameter_list|)
block|{
struct|struct
name|__mm_load_ss_struct
block|{
name|float
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
name|float
name|__u
init|=
operator|(
operator|(
expr|struct
name|__mm_load_ss_struct
operator|*
operator|)
name|__p
operator|)
operator|->
name|__u
decl_stmt|;
return|return
operator|(
name|__m128
operator|)
block|{
name|__u
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

begin_comment
comment|/// \brief Loads a 32-bit float value and duplicates it to all four vector
end_comment

begin_comment
comment|///    elements of a 128-bit vector of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VMOVSS / MOVSS + shuffling</c>
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to a float value to be loaded and duplicated.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the loaded and
end_comment

begin_comment
comment|///    duplicated values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_load1_ps
parameter_list|(
specifier|const
name|float
modifier|*
name|__p
parameter_list|)
block|{
struct|struct
name|__mm_load1_ps_struct
block|{
name|float
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
name|float
name|__u
init|=
operator|(
operator|(
expr|struct
name|__mm_load1_ps_struct
operator|*
operator|)
name|__p
operator|)
operator|->
name|__u
decl_stmt|;
return|return
operator|(
name|__m128
operator|)
block|{
name|__u
block|,
name|__u
block|,
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
name|_mm_load_ps1
parameter_list|(
name|p
parameter_list|)
value|_mm_load1_ps(p)
end_define

begin_comment
comment|/// \brief Loads a 128-bit floating-point vector of [4 x float] from an aligned
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
comment|/// This intrinsic corresponds to the<c> VMOVAPS / MOVAPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to a 128-bit memory location. The address of the memory
end_comment

begin_comment
comment|///    location has to be 128-bit aligned.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the loaded valus.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_load_ps
parameter_list|(
specifier|const
name|float
modifier|*
name|__p
parameter_list|)
block|{
return|return
operator|*
operator|(
name|__m128
operator|*
operator|)
name|__p
return|;
block|}
end_function

begin_comment
comment|/// \brief Loads a 128-bit floating-point vector of [4 x float] from an
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
comment|/// This intrinsic corresponds to the<c> VMOVUPS / MOVUPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to a 128-bit memory location. The address of the memory
end_comment

begin_comment
comment|///    location does not have to be aligned.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the loaded values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_loadu_ps
parameter_list|(
specifier|const
name|float
modifier|*
name|__p
parameter_list|)
block|{
struct|struct
name|__loadu_ps
block|{
name|__m128
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
name|__loadu_ps
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
comment|/// \brief Loads four packed float values, in reverse order, from an aligned
end_comment

begin_comment
comment|///    memory location to 32-bit elements in a 128-bit vector of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VMOVAPS / MOVAPS + shuffling</c>
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to a 128-bit memory location. The address of the memory
end_comment

begin_comment
comment|///    location has to be 128-bit aligned.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the moved values, loaded
end_comment

begin_comment
comment|///    in reverse order.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_loadr_ps
parameter_list|(
specifier|const
name|float
modifier|*
name|__p
parameter_list|)
block|{
name|__m128
name|__a
init|=
name|_mm_load_ps
argument_list|(
name|__p
argument_list|)
decl_stmt|;
return|return
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
literal|3
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Create a 128-bit vector of [4 x float] with undefined values.
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
comment|/// \returns A 128-bit vector of [4 x float] containing undefined values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_undefined_ps
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_undef128
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit floating-point vector of [4 x float]. The lower
end_comment

begin_comment
comment|///    32 bits of the vector are initialized with the specified single-precision
end_comment

begin_comment
comment|///    floating-point value. The upper 96 bits are set to zero.
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
comment|/// This intrinsic corresponds to the<c> VMOVSS / MOVSS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __w
end_comment

begin_comment
comment|///    A single-precision floating-point value used to initialize the lower 32
end_comment

begin_comment
comment|///    bits of the result.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit floating-point vector of [4 x float]. The
end_comment

begin_comment
comment|///    lower 32 bits contain the value provided in the source operand. The
end_comment

begin_comment
comment|///    upper 96 bits are set to zero.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_set_ss
parameter_list|(
name|float
name|__w
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
block|{
name|__w
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

begin_comment
comment|/// \brief Constructs a 128-bit floating-point vector of [4 x float], with each
end_comment

begin_comment
comment|///    of the four single-precision floating-point vector elements set to the
end_comment

begin_comment
comment|///    specified single-precision floating-point value.
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
comment|/// This intrinsic corresponds to the<c> VPERMILPS / PERMILPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __w
end_comment

begin_comment
comment|///    A single-precision floating-point value used to initialize each vector
end_comment

begin_comment
comment|///    element of the result.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit floating-point vector of [4 x float].
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_set1_ps
parameter_list|(
name|float
name|__w
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
block|{
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
comment|/* Microsoft specific. */
end_comment

begin_comment
comment|/// \brief Constructs a 128-bit floating-point vector of [4 x float], with each
end_comment

begin_comment
comment|///    of the four single-precision floating-point vector elements set to the
end_comment

begin_comment
comment|///    specified single-precision floating-point value.
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
comment|/// This intrinsic corresponds to the<c> VPERMILPS / PERMILPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __w
end_comment

begin_comment
comment|///    A single-precision floating-point value used to initialize each vector
end_comment

begin_comment
comment|///    element of the result.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit floating-point vector of [4 x float].
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_set_ps1
parameter_list|(
name|float
name|__w
parameter_list|)
block|{
return|return
name|_mm_set1_ps
argument_list|(
name|__w
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit floating-point vector of [4 x float]
end_comment

begin_comment
comment|///    initialized with the specified single-precision floating-point values.
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
comment|/// \param __z
end_comment

begin_comment
comment|///    A single-precision floating-point value used to initialize bits [127:96]
end_comment

begin_comment
comment|///    of the result.
end_comment

begin_comment
comment|/// \param __y
end_comment

begin_comment
comment|///    A single-precision floating-point value used to initialize bits [95:64]
end_comment

begin_comment
comment|///    of the result.
end_comment

begin_comment
comment|/// \param __x
end_comment

begin_comment
comment|///    A single-precision floating-point value used to initialize bits [63:32]
end_comment

begin_comment
comment|///    of the result.
end_comment

begin_comment
comment|/// \param __w
end_comment

begin_comment
comment|///    A single-precision floating-point value used to initialize bits [31:0]
end_comment

begin_comment
comment|///    of the result.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit floating-point vector of [4 x float].
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_set_ps
parameter_list|(
name|float
name|__z
parameter_list|,
name|float
name|__y
parameter_list|,
name|float
name|__x
parameter_list|,
name|float
name|__w
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
block|{
name|__w
block|,
name|__x
block|,
name|__y
block|,
name|__z
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit floating-point vector of [4 x float],
end_comment

begin_comment
comment|///    initialized in reverse order with the specified 32-bit single-precision
end_comment

begin_comment
comment|///    float-point values.
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
comment|/// \param __z
end_comment

begin_comment
comment|///    A single-precision floating-point value used to initialize bits [31:0]
end_comment

begin_comment
comment|///    of the result.
end_comment

begin_comment
comment|/// \param __y
end_comment

begin_comment
comment|///    A single-precision floating-point value used to initialize bits [63:32]
end_comment

begin_comment
comment|///    of the result.
end_comment

begin_comment
comment|/// \param __x
end_comment

begin_comment
comment|///    A single-precision floating-point value used to initialize bits [95:64]
end_comment

begin_comment
comment|///    of the result.
end_comment

begin_comment
comment|/// \param __w
end_comment

begin_comment
comment|///    A single-precision floating-point value used to initialize bits [127:96]
end_comment

begin_comment
comment|///    of the result.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit floating-point vector of [4 x float].
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_setr_ps
parameter_list|(
name|float
name|__z
parameter_list|,
name|float
name|__y
parameter_list|,
name|float
name|__x
parameter_list|,
name|float
name|__w
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
block|{
name|__z
block|,
name|__y
block|,
name|__x
block|,
name|__w
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit floating-point vector of [4 x float] initialized
end_comment

begin_comment
comment|///    to zero.
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
comment|/// \returns An initialized 128-bit floating-point vector of [4 x float] with
end_comment

begin_comment
comment|///    all elements set to zero.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_setzero_ps
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
block|{
literal|0
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

begin_comment
comment|/// \brief Stores the upper 64 bits of a 128-bit vector of [4 x float] to a
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
comment|/// This intrinsic corresponds to the<c> VPEXTRQ / MOVQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to a 64-bit memory location.
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing the values to be stored.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_storeh_pi
parameter_list|(
name|__m64
modifier|*
name|__p
parameter_list|,
name|__m128
name|__a
parameter_list|)
block|{
name|__builtin_ia32_storehps
argument_list|(
operator|(
name|__v2si
operator|*
operator|)
name|__p
argument_list|,
operator|(
name|__v4sf
operator|)
name|__a
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Stores the lower 64 bits of a 128-bit vector of [4 x float] to a
end_comment

begin_comment
comment|///     memory location.
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
comment|///    A pointer to a memory location that will receive the float values.
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing the values to be stored.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_storel_pi
parameter_list|(
name|__m64
modifier|*
name|__p
parameter_list|,
name|__m128
name|__a
parameter_list|)
block|{
name|__builtin_ia32_storelps
argument_list|(
operator|(
name|__v2si
operator|*
operator|)
name|__p
argument_list|,
operator|(
name|__v4sf
operator|)
name|__a
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Stores the lower 32 bits of a 128-bit vector of [4 x float] to a
end_comment

begin_comment
comment|///     memory location.
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
comment|/// This intrinsic corresponds to the<c> VMOVSS / MOVSS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to a 32-bit memory location.
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing the value to be stored.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_store_ss
parameter_list|(
name|float
modifier|*
name|__p
parameter_list|,
name|__m128
name|__a
parameter_list|)
block|{
struct|struct
name|__mm_store_ss_struct
block|{
name|float
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
name|__mm_store_ss_struct
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
comment|/// \brief Stores a 128-bit vector of [4 x float] to an unaligned memory
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
comment|/// This intrinsic corresponds to the<c> VMOVUPS / MOVUPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
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
comment|///    A 128-bit vector of [4 x float] containing the values to be stored.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_storeu_ps
parameter_list|(
name|float
modifier|*
name|__p
parameter_list|,
name|__m128
name|__a
parameter_list|)
block|{
struct|struct
name|__storeu_ps
block|{
name|__m128
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
name|__storeu_ps
operator|*
operator|)
name|__p
operator|)
operator|->
name|__v
operator|=
name|__a
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Stores a 128-bit vector of [4 x float] into an aligned memory
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
comment|/// This intrinsic corresponds to the<c> VMOVAPS / MOVAPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
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
comment|///    A 128-bit vector of [4 x float] containing the values to be stored.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_store_ps
parameter_list|(
name|float
modifier|*
name|__p
parameter_list|,
name|__m128
name|__a
parameter_list|)
block|{
operator|*
operator|(
name|__m128
operator|*
operator|)
name|__p
operator|=
name|__a
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Stores the lower 32 bits of a 128-bit vector of [4 x float] into
end_comment

begin_comment
comment|///    four contiguous elements in an aligned memory location.
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
comment|/// This intrinsic corresponds to<c> VMOVAPS / MOVAPS + shuffling</c>
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to a 128-bit memory location.
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] whose lower 32 bits are stored to each
end_comment

begin_comment
comment|///    of the four contiguous elements pointed by \a __p.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_store1_ps
parameter_list|(
name|float
modifier|*
name|__p
parameter_list|,
name|__m128
name|__a
parameter_list|)
block|{
name|__a
operator|=
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
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|_mm_store_ps
argument_list|(
name|__p
argument_list|,
name|__a
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Stores the lower 32 bits of a 128-bit vector of [4 x float] into
end_comment

begin_comment
comment|///    four contiguous elements in an aligned memory location.
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
comment|/// This intrinsic corresponds to<c> VMOVAPS / MOVAPS + shuffling</c>
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to a 128-bit memory location.
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] whose lower 32 bits are stored to each
end_comment

begin_comment
comment|///    of the four contiguous elements pointed by \a __p.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_store_ps1
parameter_list|(
name|float
modifier|*
name|__p
parameter_list|,
name|__m128
name|__a
parameter_list|)
block|{
return|return
name|_mm_store1_ps
argument_list|(
name|__p
argument_list|,
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Stores float values from a 128-bit vector of [4 x float] to an
end_comment

begin_comment
comment|///    aligned memory location in reverse order.
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
comment|/// This intrinsic corresponds to the<c> VMOVAPS / MOVAPS + shuffling</c>
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to a 128-bit memory location. The address of the memory
end_comment

begin_comment
comment|///    location has to be 128-bit aligned.
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing the values to be stored.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_storer_ps
parameter_list|(
name|float
modifier|*
name|__p
parameter_list|,
name|__m128
name|__a
parameter_list|)
block|{
name|__a
operator|=
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
literal|3
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|_mm_store_ps
argument_list|(
name|__p
argument_list|,
name|__a
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|_MM_HINT_T0
value|3
end_define

begin_define
define|#
directive|define
name|_MM_HINT_T1
value|2
end_define

begin_define
define|#
directive|define
name|_MM_HINT_T2
value|1
end_define

begin_define
define|#
directive|define
name|_MM_HINT_NTA
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_MSC_VER
end_ifndef

begin_comment
comment|/* FIXME: We have to #define this because "sel" must be a constant integer, and    Sema doesn't do any form of constant propagation yet. */
end_comment

begin_comment
comment|/// \brief Loads one cache line of data from the specified address to a location
end_comment

begin_comment
comment|///    closer to the processor.
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
comment|/// void _mm_prefetch(const void * a, const int sel);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> PREFETCHNTA</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param a
end_comment

begin_comment
comment|///    A pointer to a memory location containing a cache line of data.
end_comment

begin_comment
comment|/// \param sel
end_comment

begin_comment
comment|///    A predefined integer constant specifying the type of prefetch
end_comment

begin_comment
comment|///    operation: \n
end_comment

begin_comment
comment|///    _MM_HINT_NTA: Move data using the non-temporal access (NTA) hint. The
end_comment

begin_comment
comment|///    PREFETCHNTA instruction will be generated. \n
end_comment

begin_comment
comment|///    _MM_HINT_T0: Move data using the T0 hint. The PREFETCHT0 instruction will
end_comment

begin_comment
comment|///    be generated. \n
end_comment

begin_comment
comment|///    _MM_HINT_T1: Move data using the T1 hint. The PREFETCHT1 instruction will
end_comment

begin_comment
comment|///    be generated. \n
end_comment

begin_comment
comment|///    _MM_HINT_T2: Move data using the T2 hint. The PREFETCHT2 instruction will
end_comment

begin_comment
comment|///    be generated.
end_comment

begin_define
define|#
directive|define
name|_mm_prefetch
parameter_list|(
name|a
parameter_list|,
name|sel
parameter_list|)
value|(__builtin_prefetch((void *)(a), 0, (sel)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \brief Stores a 64-bit integer in the specified aligned memory location. To
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
comment|/// This intrinsic corresponds to the<c> MOVNTQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to an aligned memory location used to store the register value.
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
name|_mm_stream_pi
parameter_list|(
name|__m64
modifier|*
name|__p
parameter_list|,
name|__m64
name|__a
parameter_list|)
block|{
name|__builtin_ia32_movntq
argument_list|(
name|__p
argument_list|,
name|__a
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Moves packed float values from a 128-bit vector of [4 x float] to a
end_comment

begin_comment
comment|///    128-bit aligned memory location. To minimize caching, the data is flagged
end_comment

begin_comment
comment|///    as non-temporal (unlikely to be used again soon).
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
comment|///    A pointer to a 128-bit aligned memory location that will receive the
end_comment

begin_comment
comment|///    integer values.
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing the values to be moved.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_stream_ps
parameter_list|(
name|float
modifier|*
name|__p
parameter_list|,
name|__m128
name|__a
parameter_list|)
block|{
name|__builtin_nontemporal_store
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|*
operator|)
name|__p
argument_list|)
expr_stmt|;
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
comment|/// \brief Forces strong memory ordering (serialization) between store
comment|///    instructions preceding this instruction and store instructions following
comment|///    this instruction, ensuring the system completes all previous stores
comment|///    before executing subsequent stores.
comment|///
comment|/// \headerfile<x86intrin.h>
comment|///
comment|/// This intrinsic corresponds to the<c> SFENCE</c> instruction.
comment|///
name|void
name|_mm_sfence
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
comment|/// \brief Extracts 16-bit element from a 64-bit vector of [4 x i16] and
end_comment

begin_comment
comment|///    returns it, as specified by the immediate integer operand.
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
comment|/// void _mm_extract_pi(__m64 a, int n);
end_comment

begin_comment
comment|/// \endcode
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
comment|/// \param a
end_comment

begin_comment
comment|///    A 64-bit vector of [4 x i16].
end_comment

begin_comment
comment|/// \param n
end_comment

begin_comment
comment|///    An immediate integer operand that determines which bits are extracted: \n
end_comment

begin_comment
comment|///    0: Bits [15:0] are copied to the destination. \n
end_comment

begin_comment
comment|///    1: Bits [31:16] are copied to the destination. \n
end_comment

begin_comment
comment|///    2: Bits [47:32] are copied to the destination. \n
end_comment

begin_comment
comment|///    3: Bits [63:48] are copied to the destination.
end_comment

begin_comment
comment|/// \returns A 16-bit integer containing the extracted 16 bits of packed data.
end_comment

begin_define
define|#
directive|define
name|_mm_extract_pi16
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|__extension__ ({ \   (int)__builtin_ia32_vec_ext_v4hi((__m64)a, (int)n); })
end_define

begin_comment
comment|/// \brief Copies data from the 64-bit vector of [4 x i16] to the destination,
end_comment

begin_comment
comment|///    and inserts the lower 16-bits of an integer operand at the 16-bit offset
end_comment

begin_comment
comment|///    specified by the immediate operand \a n.
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
comment|/// void _mm_insert_pi(__m64 a, int d, int n);
end_comment

begin_comment
comment|/// \endcode
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
comment|/// \param a
end_comment

begin_comment
comment|///    A 64-bit vector of [4 x i16].
end_comment

begin_comment
comment|/// \param d
end_comment

begin_comment
comment|///    An integer. The lower 16-bit value from this operand is written to the
end_comment

begin_comment
comment|///    destination at the offset specified by operand \a n.
end_comment

begin_comment
comment|/// \param n
end_comment

begin_comment
comment|///    An immediate integer operant that determines which the bits to be used
end_comment

begin_comment
comment|///    in the destination. \n
end_comment

begin_comment
comment|///    0: Bits [15:0] are copied to the destination. \n
end_comment

begin_comment
comment|///    1: Bits [31:16] are copied to the destination. \n
end_comment

begin_comment
comment|///    2: Bits [47:32] are copied to the destination. \n
end_comment

begin_comment
comment|///    3: Bits [63:48] are copied to the destination.  \n
end_comment

begin_comment
comment|///    The remaining bits in the destination are copied from the corresponding
end_comment

begin_comment
comment|///    bits in operand \a a.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the copied packed data from the
end_comment

begin_comment
comment|///    operands.
end_comment

begin_define
define|#
directive|define
name|_mm_insert_pi16
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|,
name|n
parameter_list|)
value|__extension__ ({ \   (__m64)__builtin_ia32_vec_set_v4hi((__m64)a, (int)d, (int)n); })
end_define

begin_comment
comment|/// \brief Compares each of the corresponding packed 16-bit integer values of
end_comment

begin_comment
comment|///    the 64-bit integer vectors, and writes the greater value to the
end_comment

begin_comment
comment|///    corresponding bits in the destination.
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
comment|/// This intrinsic corresponds to the<c> PMAXSW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_max_pi16
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
name|__builtin_ia32_pmaxsw
argument_list|(
operator|(
name|__v4hi
operator|)
name|__a
argument_list|,
operator|(
name|__v4hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding packed 8-bit unsigned integer
end_comment

begin_comment
comment|///    values of the 64-bit integer vectors, and writes the greater value to the
end_comment

begin_comment
comment|///    corresponding bits in the destination.
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
comment|/// This intrinsic corresponds to the<c> PMAXUB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_max_pu8
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
name|__builtin_ia32_pmaxub
argument_list|(
operator|(
name|__v8qi
operator|)
name|__a
argument_list|,
operator|(
name|__v8qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding packed 16-bit integer values of
end_comment

begin_comment
comment|///    the 64-bit integer vectors, and writes the lesser value to the
end_comment

begin_comment
comment|///    corresponding bits in the destination.
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
comment|/// This intrinsic corresponds to the<c> PMINSW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_min_pi16
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
name|__builtin_ia32_pminsw
argument_list|(
operator|(
name|__v4hi
operator|)
name|__a
argument_list|,
operator|(
name|__v4hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding packed 8-bit unsigned integer
end_comment

begin_comment
comment|///    values of the 64-bit integer vectors, and writes the lesser value to the
end_comment

begin_comment
comment|///    corresponding bits in the destination.
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
comment|/// This intrinsic corresponds to the<c> PMINUB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_min_pu8
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
name|__builtin_ia32_pminub
argument_list|(
operator|(
name|__v8qi
operator|)
name|__a
argument_list|,
operator|(
name|__v8qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Takes the most significant bit from each 8-bit element in a 64-bit
end_comment

begin_comment
comment|///    integer vector to create a 16-bit mask value. Zero-extends the value to
end_comment

begin_comment
comment|///    32-bit integer and writes it to the destination.
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
comment|/// This intrinsic corresponds to the<c> PMOVMSKB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit integer vector containing the values with bits to be extracted.
end_comment

begin_comment
comment|/// \returns The most significant bit from each 8-bit element in the operand,
end_comment

begin_comment
comment|///    written to bits [15:0].
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_movemask_pi8
parameter_list|(
name|__m64
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_pmovmskb
argument_list|(
operator|(
name|__v8qi
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Multiplies packed 16-bit unsigned integer values and writes the
end_comment

begin_comment
comment|///    high-order 16 bits of each 32-bit product to the corresponding bits in
end_comment

begin_comment
comment|///    the destination.
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
comment|/// This intrinsic corresponds to the<c> PMULHUW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the products of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_mulhi_pu16
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
name|__builtin_ia32_pmulhuw
argument_list|(
operator|(
name|__v4hi
operator|)
name|__a
argument_list|,
operator|(
name|__v4hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Shuffles the 4 16-bit integers from a 64-bit integer vector to the
end_comment

begin_comment
comment|///    destination, as specified by the immediate value operand.
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
comment|/// __m64 _mm_shuffle_pi16(__m64 a, const int n);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> PSHUFW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param a
end_comment

begin_comment
comment|///    A 64-bit integer vector containing the values to be shuffled.
end_comment

begin_comment
comment|/// \param n
end_comment

begin_comment
comment|///    An immediate value containing an 8-bit value specifying which elements to
end_comment

begin_comment
comment|///    copy from \a a. The destinations within the 64-bit destination are
end_comment

begin_comment
comment|///    assigned values as follows: \n
end_comment

begin_comment
comment|///    Bits [1:0] are used to assign values to bits [15:0] in the
end_comment

begin_comment
comment|///    destination. \n
end_comment

begin_comment
comment|///    Bits [3:2] are used to assign values to bits [31:16] in the
end_comment

begin_comment
comment|///    destination. \n
end_comment

begin_comment
comment|///    Bits [5:4] are used to assign values to bits [47:32] in the
end_comment

begin_comment
comment|///    destination. \n
end_comment

begin_comment
comment|///    Bits [7:6] are used to assign values to bits [63:48] in the
end_comment

begin_comment
comment|///    destination. \n
end_comment

begin_comment
comment|///    Bit value assignments: \n
end_comment

begin_comment
comment|///    00: assigned from bits [15:0] of \a a. \n
end_comment

begin_comment
comment|///    01: assigned from bits [31:16] of \a a. \n
end_comment

begin_comment
comment|///    10: assigned from bits [47:32] of \a a. \n
end_comment

begin_comment
comment|///    11: assigned from bits [63:48] of \a a.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the shuffled values.
end_comment

begin_define
define|#
directive|define
name|_mm_shuffle_pi16
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|__extension__ ({ \   (__m64)__builtin_ia32_pshufw((__v4hi)(__m64)(a), (n)); })
end_define

begin_comment
comment|/// \brief Conditionally copies the values from each 8-bit element in the first
end_comment

begin_comment
comment|///    64-bit integer vector operand to the specified memory location, as
end_comment

begin_comment
comment|///    specified by the most significant bit in the corresponding element in the
end_comment

begin_comment
comment|///    second 64-bit integer vector operand. To minimize caching, the data is
end_comment

begin_comment
comment|///    flagged as non-temporal (unlikely to be used again soon).
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
comment|/// This intrinsic corresponds to the<c> MASKMOVQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __d
end_comment

begin_comment
comment|///    A 64-bit integer vector containing the values with elements to be copied.
end_comment

begin_comment
comment|/// \param __n
end_comment

begin_comment
comment|///    A 64-bit integer vector operand. The most significant bit from each 8-bit
end_comment

begin_comment
comment|///    element determines whether the corresponding element in operand \a __d
end_comment

begin_comment
comment|///    is copied. If the most significant bit of a given element is 1, the
end_comment

begin_comment
comment|///    corresponding element in operand \a __d is copied.
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to a 64-bit memory location that will receive the conditionally
end_comment

begin_comment
comment|///    copied integer values. The address of the memory location does not have
end_comment

begin_comment
comment|///    to be aligned.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_maskmove_si64
parameter_list|(
name|__m64
name|__d
parameter_list|,
name|__m64
name|__n
parameter_list|,
name|char
modifier|*
name|__p
parameter_list|)
block|{
name|__builtin_ia32_maskmovq
argument_list|(
operator|(
name|__v8qi
operator|)
name|__d
argument_list|,
operator|(
name|__v8qi
operator|)
name|__n
argument_list|,
name|__p
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Computes the rounded averages of the packed unsigned 8-bit integer
end_comment

begin_comment
comment|///    values and writes the averages to the corresponding bits in the
end_comment

begin_comment
comment|///    destination.
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
comment|/// This intrinsic corresponds to the<c> PAVGB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the averages of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_avg_pu8
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
name|__builtin_ia32_pavgb
argument_list|(
operator|(
name|__v8qi
operator|)
name|__a
argument_list|,
operator|(
name|__v8qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Computes the rounded averages of the packed unsigned 16-bit integer
end_comment

begin_comment
comment|///    values and writes the averages to the corresponding bits in the
end_comment

begin_comment
comment|///    destination.
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
comment|/// This intrinsic corresponds to the<c> PAVGW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the averages of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_avg_pu16
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
name|__builtin_ia32_pavgw
argument_list|(
operator|(
name|__v4hi
operator|)
name|__a
argument_list|,
operator|(
name|__v4hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts the corresponding 8-bit unsigned integer values of the two
end_comment

begin_comment
comment|///    64-bit vector operands and computes the absolute value for each of the
end_comment

begin_comment
comment|///    difference. Then sum of the 8 absolute differences is written to the
end_comment

begin_comment
comment|///    bits [15:0] of the destination; the remaining bits [63:16] are cleared.
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
comment|/// This intrinsic corresponds to the<c> PSADBW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector whose lower 16 bits contain the sums of the
end_comment

begin_comment
comment|///    sets of absolute differences between both operands. The upper bits are
end_comment

begin_comment
comment|///    cleared.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_sad_pu8
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
name|__builtin_ia32_psadbw
argument_list|(
operator|(
name|__v8qi
operator|)
name|__a
argument_list|,
operator|(
name|__v8qi
operator|)
name|__b
argument_list|)
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
comment|/// \brief Returns the contents of the MXCSR register as a 32-bit unsigned
comment|///    integer value.
comment|///
comment|///    There are several groups of macros associated with this
comment|///    intrinsic, including:
comment|///<ul>
comment|///<li>
comment|///      For checking exception states: _MM_EXCEPT_INVALID, _MM_EXCEPT_DIV_ZERO,
comment|///      _MM_EXCEPT_DENORM, _MM_EXCEPT_OVERFLOW, _MM_EXCEPT_UNDERFLOW,
comment|///      _MM_EXCEPT_INEXACT. There is a convenience wrapper
comment|///      _MM_GET_EXCEPTION_STATE().
comment|///</li>
comment|///<li>
comment|///      For checking exception masks: _MM_MASK_UNDERFLOW, _MM_MASK_OVERFLOW,
comment|///      _MM_MASK_INVALID, _MM_MASK_DENORM, _MM_MASK_DIV_ZERO, _MM_MASK_INEXACT.
comment|///      There is a convenience wrapper _MM_GET_EXCEPTION_MASK().
comment|///</li>
comment|///<li>
comment|///      For checking rounding modes: _MM_ROUND_NEAREST, _MM_ROUND_DOWN,
comment|///      _MM_ROUND_UP, _MM_ROUND_TOWARD_ZERO. There is a convenience wrapper
comment|///      _MM_GET_ROUNDING_MODE(x) where x is one of these macros.
comment|///</li>
comment|///<li>
comment|///      For checking flush-to-zero mode: _MM_FLUSH_ZERO_ON, _MM_FLUSH_ZERO_OFF.
comment|///      There is a convenience wrapper _MM_GET_FLUSH_ZERO_MODE().
comment|///</li>
comment|///<li>
comment|///      For checking denormals-are-zero mode: _MM_DENORMALS_ZERO_ON,
comment|///      _MM_DENORMALS_ZERO_OFF. There is a convenience wrapper
comment|///      _MM_GET_DENORMALS_ZERO_MODE().
comment|///</li>
comment|///</ul>
comment|///
comment|///    For example, the expression below checks if an overflow exception has
comment|///    occurred:
comment|///      ( _mm_getcsr()& _MM_EXCEPT_OVERFLOW )
comment|///
comment|///    The following example gets the current rounding mode:
comment|///      _MM_GET_ROUNDING_MODE()
comment|///
comment|/// \headerfile<x86intrin.h>
comment|///
comment|/// This intrinsic corresponds to the<c> VSTMXCSR / STMXCSR</c> instruction.
comment|///
comment|/// \returns A 32-bit unsigned integer containing the contents of the MXCSR
comment|///    register.
name|unsigned
name|int
name|_mm_getcsr
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/// \brief Sets the MXCSR register with the 32-bit unsigned integer value.
comment|///
comment|///    There are several groups of macros associated with this intrinsic,
comment|///    including:
comment|///<ul>
comment|///<li>
comment|///      For setting exception states: _MM_EXCEPT_INVALID, _MM_EXCEPT_DIV_ZERO,
comment|///      _MM_EXCEPT_DENORM, _MM_EXCEPT_OVERFLOW, _MM_EXCEPT_UNDERFLOW,
comment|///      _MM_EXCEPT_INEXACT. There is a convenience wrapper
comment|///      _MM_SET_EXCEPTION_STATE(x) where x is one of these macros.
comment|///</li>
comment|///<li>
comment|///      For setting exception masks: _MM_MASK_UNDERFLOW, _MM_MASK_OVERFLOW,
comment|///      _MM_MASK_INVALID, _MM_MASK_DENORM, _MM_MASK_DIV_ZERO, _MM_MASK_INEXACT.
comment|///      There is a convenience wrapper _MM_SET_EXCEPTION_MASK(x) where x is one
comment|///      of these macros.
comment|///</li>
comment|///<li>
comment|///      For setting rounding modes: _MM_ROUND_NEAREST, _MM_ROUND_DOWN,
comment|///      _MM_ROUND_UP, _MM_ROUND_TOWARD_ZERO. There is a convenience wrapper
comment|///      _MM_SET_ROUNDING_MODE(x) where x is one of these macros.
comment|///</li>
comment|///<li>
comment|///      For setting flush-to-zero mode: _MM_FLUSH_ZERO_ON, _MM_FLUSH_ZERO_OFF.
comment|///      There is a convenience wrapper _MM_SET_FLUSH_ZERO_MODE(x) where x is
comment|///      one of these macros.
comment|///</li>
comment|///<li>
comment|///      For setting denormals-are-zero mode: _MM_DENORMALS_ZERO_ON,
comment|///      _MM_DENORMALS_ZERO_OFF. There is a convenience wrapper
comment|///      _MM_SET_DENORMALS_ZERO_MODE(x) where x is one of these macros.
comment|///</li>
comment|///</ul>
comment|///
comment|///    For example, the following expression causes subsequent floating-point
comment|///    operations to round up:
comment|///      _mm_setcsr(_mm_getcsr() | _MM_ROUND_UP)
comment|///
comment|///    The following example sets the DAZ and FTZ flags:
comment|///      void setFlags() {
comment|///        _MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON)
comment|///        _MM_SET_DENORMALS_ZERO_MODE(_MM_DENORMALS_ZERO_ON)
comment|///      }
comment|///
comment|/// \headerfile<x86intrin.h>
comment|///
comment|/// This intrinsic corresponds to the<c> VLDMXCSR / LDMXCSR</c> instruction.
comment|///
comment|/// \param __i
comment|///    A 32-bit unsigned integer value to be written to the MXCSR register.
name|void
name|_mm_setcsr
parameter_list|(
name|unsigned
name|int
name|__i
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
comment|/// \brief Selects 4 float values from the 128-bit operands of [4 x float], as
end_comment

begin_comment
comment|///    specified by the immediate value operand.
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
comment|/// __m128 _mm_shuffle_ps(__m128 a, __m128 b, const int mask);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VSHUFPS / SHUFPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \param b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \param mask
end_comment

begin_comment
comment|///    An immediate value containing an 8-bit value specifying which elements to
end_comment

begin_comment
comment|///    copy from \a a and \a b. \n
end_comment

begin_comment
comment|///    Bits [3:0] specify the values copied from operand \a a. \n
end_comment

begin_comment
comment|///    Bits [7:4] specify the values copied from operand \a b. \n
end_comment

begin_comment
comment|///    The destinations within the 128-bit destination are assigned values as
end_comment

begin_comment
comment|///    follows: \n
end_comment

begin_comment
comment|///    Bits [1:0] are used to assign values to bits [31:0] in the
end_comment

begin_comment
comment|///    destination. \n
end_comment

begin_comment
comment|///    Bits [3:2] are used to assign values to bits [63:32] in the
end_comment

begin_comment
comment|///    destination. \n
end_comment

begin_comment
comment|///    Bits [5:4] are used to assign values to bits [95:64] in the
end_comment

begin_comment
comment|///    destination. \n
end_comment

begin_comment
comment|///    Bits [7:6] are used to assign values to bits [127:96] in the
end_comment

begin_comment
comment|///    destination. \n
end_comment

begin_comment
comment|///    Bit value assignments: \n
end_comment

begin_comment
comment|///    00: Bits [31:0] copied from the specified operand. \n
end_comment

begin_comment
comment|///    01: Bits [63:32] copied from the specified operand. \n
end_comment

begin_comment
comment|///    10: Bits [95:64] copied from the specified operand. \n
end_comment

begin_comment
comment|///    11: Bits [127:96] copied from the specified operand.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the shuffled values.
end_comment

begin_define
define|#
directive|define
name|_mm_shuffle_ps
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|mask
parameter_list|)
value|__extension__ ({ \   (__m128)__builtin_shufflevector((__v4sf)(__m128)(a), (__v4sf)(__m128)(b), \                                   0 + (((mask)>> 0)& 0x3), \                                   0 + (((mask)>> 2)& 0x3), \                                   4 + (((mask)>> 4)& 0x3), \                                   4 + (((mask)>> 6)& 0x3)); })
end_define

begin_comment
comment|/// \brief Unpacks the high-order (index 2,3) values from two 128-bit vectors of
end_comment

begin_comment
comment|///    [4 x float] and interleaves them into a 128-bit vector of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VUNPCKHPS / UNPCKHPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. \n
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
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|///    Bits [95:64] are written to bits [63:32] of the destination. \n
end_comment

begin_comment
comment|///    Bits [127:96] are written to bits [127:96] of the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the interleaved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_unpackhi_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
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
name|__b
argument_list|,
literal|2
argument_list|,
literal|6
argument_list|,
literal|3
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Unpacks the low-order (index 0,1) values from two 128-bit vectors of
end_comment

begin_comment
comment|///    [4 x float] and interleaves them into a 128-bit vector of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VUNPCKLPS / UNPCKLPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. \n
end_comment

begin_comment
comment|///    Bits [31:0] are written to bits [31:0] of the destination.  \n
end_comment

begin_comment
comment|///    Bits [63:32] are written to bits [95:64] of the destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. \n
end_comment

begin_comment
comment|///    Bits [31:0] are written to bits [63:32] of the destination. \n
end_comment

begin_comment
comment|///    Bits [63:32] are written to bits [127:96] of the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the interleaved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_unpacklo_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
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
name|__b
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit floating-point vector of [4 x float]. The lower
end_comment

begin_comment
comment|///    32 bits are set to the lower 32 bits of the second parameter. The upper
end_comment

begin_comment
comment|///    96 bits are set to the upper 96 bits of the first parameter.
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
comment|/// This intrinsic corresponds to the<c> VMOVSS / MOVSS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit floating-point vector of [4 x float]. The upper 96 bits are
end_comment

begin_comment
comment|///    written to the upper 96 bits of the result.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit floating-point vector of [4 x float]. The lower 32 bits are
end_comment

begin_comment
comment|///    written to the lower 32 bits of the result.
end_comment

begin_comment
comment|/// \returns A 128-bit floating-point vector of [4 x float].
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_move_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
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
name|__b
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit floating-point vector of [4 x float]. The lower
end_comment

begin_comment
comment|///    64 bits are set to the upper 64 bits of the second parameter. The upper
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
comment|/// This intrinsic corresponds to the<c> VUNPCKHPD / UNPCKHPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit floating-point vector of [4 x float]. The upper 64 bits are
end_comment

begin_comment
comment|///    written to the upper 64 bits of the result.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit floating-point vector of [4 x float]. The upper 64 bits are
end_comment

begin_comment
comment|///    written to the lower 64 bits of the result.
end_comment

begin_comment
comment|/// \returns A 128-bit floating-point vector of [4 x float].
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_movehl_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
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
name|__b
argument_list|,
literal|6
argument_list|,
literal|7
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 128-bit floating-point vector of [4 x float]. The lower
end_comment

begin_comment
comment|///    64 bits are set to the lower 64 bits of the first parameter. The upper
end_comment

begin_comment
comment|///    64 bits are set to the lower 64 bits of the second parameter.
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
comment|///    A 128-bit floating-point vector of [4 x float]. The lower 64 bits are
end_comment

begin_comment
comment|///    written to the lower 64 bits of the result.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit floating-point vector of [4 x float]. The lower 64 bits are
end_comment

begin_comment
comment|///    written to the upper 64 bits of the result.
end_comment

begin_comment
comment|/// \returns A 128-bit floating-point vector of [4 x float].
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_movelh_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
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
name|__b
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts a 64-bit vector of [4 x i16] into a 128-bit vector of [4 x
end_comment

begin_comment
comment|///    float].
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
comment|/// This intrinsic corresponds to the<c> CVTPI2PS + \c COMPOSITE</c>
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
comment|///    A 64-bit vector of [4 x i16]. The elements of the destination are copied
end_comment

begin_comment
comment|///    from the corresponding elements in this operand.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the copied and converted
end_comment

begin_comment
comment|///    values from the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cvtpi16_ps
parameter_list|(
name|__m64
name|__a
parameter_list|)
block|{
name|__m64
name|__b
decl_stmt|,
name|__c
decl_stmt|;
name|__m128
name|__r
decl_stmt|;
name|__b
operator|=
name|_mm_setzero_si64
argument_list|()
expr_stmt|;
name|__b
operator|=
name|_mm_cmpgt_pi16
argument_list|(
name|__b
argument_list|,
name|__a
argument_list|)
expr_stmt|;
name|__c
operator|=
name|_mm_unpackhi_pi16
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
expr_stmt|;
name|__r
operator|=
name|_mm_setzero_ps
argument_list|()
expr_stmt|;
name|__r
operator|=
name|_mm_cvtpi32_ps
argument_list|(
name|__r
argument_list|,
name|__c
argument_list|)
expr_stmt|;
name|__r
operator|=
name|_mm_movelh_ps
argument_list|(
name|__r
argument_list|,
name|__r
argument_list|)
expr_stmt|;
name|__c
operator|=
name|_mm_unpacklo_pi16
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
expr_stmt|;
name|__r
operator|=
name|_mm_cvtpi32_ps
argument_list|(
name|__r
argument_list|,
name|__c
argument_list|)
expr_stmt|;
return|return
name|__r
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts a 64-bit vector of 16-bit unsigned integer values into a
end_comment

begin_comment
comment|///    128-bit vector of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> CVTPI2PS + \c COMPOSITE</c>
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
comment|///    A 64-bit vector of 16-bit unsigned integer values. The elements of the
end_comment

begin_comment
comment|///    destination are copied from the corresponding elements in this operand.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the copied and converted
end_comment

begin_comment
comment|///    values from the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cvtpu16_ps
parameter_list|(
name|__m64
name|__a
parameter_list|)
block|{
name|__m64
name|__b
decl_stmt|,
name|__c
decl_stmt|;
name|__m128
name|__r
decl_stmt|;
name|__b
operator|=
name|_mm_setzero_si64
argument_list|()
expr_stmt|;
name|__c
operator|=
name|_mm_unpackhi_pi16
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
expr_stmt|;
name|__r
operator|=
name|_mm_setzero_ps
argument_list|()
expr_stmt|;
name|__r
operator|=
name|_mm_cvtpi32_ps
argument_list|(
name|__r
argument_list|,
name|__c
argument_list|)
expr_stmt|;
name|__r
operator|=
name|_mm_movelh_ps
argument_list|(
name|__r
argument_list|,
name|__r
argument_list|)
expr_stmt|;
name|__c
operator|=
name|_mm_unpacklo_pi16
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
expr_stmt|;
name|__r
operator|=
name|_mm_cvtpi32_ps
argument_list|(
name|__r
argument_list|,
name|__c
argument_list|)
expr_stmt|;
return|return
name|__r
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts the lower four 8-bit values from a 64-bit vector of [8 x i8]
end_comment

begin_comment
comment|///    into a 128-bit vector of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> CVTPI2PS + \c COMPOSITE</c>
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
comment|///    A 64-bit vector of [8 x i8]. The elements of the destination are copied
end_comment

begin_comment
comment|///    from the corresponding lower 4 elements in this operand.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the copied and converted
end_comment

begin_comment
comment|///    values from the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cvtpi8_ps
parameter_list|(
name|__m64
name|__a
parameter_list|)
block|{
name|__m64
name|__b
decl_stmt|;
name|__b
operator|=
name|_mm_setzero_si64
argument_list|()
expr_stmt|;
name|__b
operator|=
name|_mm_cmpgt_pi8
argument_list|(
name|__b
argument_list|,
name|__a
argument_list|)
expr_stmt|;
name|__b
operator|=
name|_mm_unpacklo_pi8
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
expr_stmt|;
return|return
name|_mm_cvtpi16_ps
argument_list|(
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts the lower four unsigned 8-bit integer values from a 64-bit
end_comment

begin_comment
comment|///    vector of [8 x u8] into a 128-bit vector of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> CVTPI2PS + \c COMPOSITE</c>
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
comment|///    A 64-bit vector of unsigned 8-bit integer values. The elements of the
end_comment

begin_comment
comment|///    destination are copied from the corresponding lower 4 elements in this
end_comment

begin_comment
comment|///    operand.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the copied and converted
end_comment

begin_comment
comment|///    values from the source operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cvtpu8_ps
parameter_list|(
name|__m64
name|__a
parameter_list|)
block|{
name|__m64
name|__b
decl_stmt|;
name|__b
operator|=
name|_mm_setzero_si64
argument_list|()
expr_stmt|;
name|__b
operator|=
name|_mm_unpacklo_pi8
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
expr_stmt|;
return|return
name|_mm_cvtpi16_ps
argument_list|(
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts the two 32-bit signed integer values from each 64-bit vector
end_comment

begin_comment
comment|///    operand of [2 x i32] into a 128-bit vector of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> CVTPI2PS + \c COMPOSITE</c>
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
comment|///    A 64-bit vector of [2 x i32]. The lower elements of the destination are
end_comment

begin_comment
comment|///    copied from the elements in this operand.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit vector of [2 x i32]. The upper elements of the destination are
end_comment

begin_comment
comment|///    copied from the elements in this operand.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] whose lower 64 bits contain the
end_comment

begin_comment
comment|///    copied and converted values from the first operand. The upper 64 bits
end_comment

begin_comment
comment|///    contain the copied and converted values from the second operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cvtpi32x2_ps
parameter_list|(
name|__m64
name|__a
parameter_list|,
name|__m64
name|__b
parameter_list|)
block|{
name|__m128
name|__c
decl_stmt|;
name|__c
operator|=
name|_mm_setzero_ps
argument_list|()
expr_stmt|;
name|__c
operator|=
name|_mm_cvtpi32_ps
argument_list|(
name|__c
argument_list|,
name|__b
argument_list|)
expr_stmt|;
name|__c
operator|=
name|_mm_movelh_ps
argument_list|(
name|__c
argument_list|,
name|__c
argument_list|)
expr_stmt|;
return|return
name|_mm_cvtpi32_ps
argument_list|(
name|__c
argument_list|,
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts each single-precision floating-point element of a 128-bit
end_comment

begin_comment
comment|///    floating-point vector of [4 x float] into a 16-bit signed integer, and
end_comment

begin_comment
comment|///    packs the results into a 64-bit integer vector of [4 x i16]. If the
end_comment

begin_comment
comment|///    floating-point element is NaN or infinity, or if the floating-point
end_comment

begin_comment
comment|///    element is greater than 0x7FFFFFFF or less than -0x8000, it is converted
end_comment

begin_comment
comment|///    to 0x8000. Otherwise if the floating-point element is greater than
end_comment

begin_comment
comment|///    0x7FFF, it is converted to 0x7FFF.
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
comment|/// This intrinsic corresponds to the<c> CVTPS2PI + \c COMPOSITE</c>
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
comment|///    A 128-bit floating-point vector of [4 x float].
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [4 x i16] containing the converted
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_cvtps_pi16
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
name|__m64
name|__b
decl_stmt|,
name|__c
decl_stmt|;
name|__b
operator|=
name|_mm_cvtps_pi32
argument_list|(
name|__a
argument_list|)
expr_stmt|;
name|__a
operator|=
name|_mm_movehl_ps
argument_list|(
name|__a
argument_list|,
name|__a
argument_list|)
expr_stmt|;
name|__c
operator|=
name|_mm_cvtps_pi32
argument_list|(
name|__a
argument_list|)
expr_stmt|;
return|return
name|_mm_packs_pi32
argument_list|(
name|__b
argument_list|,
name|__c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts each single-precision floating-point element of a 128-bit
end_comment

begin_comment
comment|///    floating-point vector of [4 x float] into an 8-bit signed integer, and
end_comment

begin_comment
comment|///    packs the results into the lower 32 bits of a 64-bit integer vector of
end_comment

begin_comment
comment|///    [8 x i8]. The upper 32 bits of the vector are set to 0. If the
end_comment

begin_comment
comment|///    floating-point element is NaN or infinity, or if the floating-point
end_comment

begin_comment
comment|///    element is greater than 0x7FFFFFFF or less than -0x80, it is converted
end_comment

begin_comment
comment|///    to 0x80. Otherwise if the floating-point element is greater than 0x7F,
end_comment

begin_comment
comment|///    it is converted to 0x7F.
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
comment|/// This intrinsic corresponds to the<c> CVTPS2PI + \c COMPOSITE</c>
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
comment|///    128-bit floating-point vector of [4 x float].
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [8 x i8]. The lower 32 bits contain the
end_comment

begin_comment
comment|///    converted values and the uppper 32 bits are set to zero.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_cvtps_pi8
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
name|__m64
name|__b
decl_stmt|,
name|__c
decl_stmt|;
name|__b
operator|=
name|_mm_cvtps_pi16
argument_list|(
name|__a
argument_list|)
expr_stmt|;
name|__c
operator|=
name|_mm_setzero_si64
argument_list|()
expr_stmt|;
return|return
name|_mm_packs_pi16
argument_list|(
name|__b
argument_list|,
name|__c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Extracts the sign bits from each single-precision floating-point
end_comment

begin_comment
comment|///    element of a 128-bit floating-point vector of [4 x float] and returns the
end_comment

begin_comment
comment|///    sign bits in bits [0:3] of the result. Bits [31:4] of the result are set
end_comment

begin_comment
comment|///    to zero.
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
comment|/// This intrinsic corresponds to the<c> VMOVMSKPS / MOVMSKPS</c> instruction.
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
comment|/// \returns A 32-bit integer value. Bits [3:0] contain the sign bits from each
end_comment

begin_comment
comment|///    single-precision floating-point element of the parameter. Bits [31:4] are
end_comment

begin_comment
comment|///    set to zero.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_movemask_ps
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_movmskps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|_MM_ALIGN16
value|__attribute__((aligned(16)))
end_define

begin_define
define|#
directive|define
name|_MM_SHUFFLE
parameter_list|(
name|z
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|,
name|w
parameter_list|)
value|(((z)<< 6) | ((y)<< 4) | ((x)<< 2) | (w))
end_define

begin_define
define|#
directive|define
name|_MM_EXCEPT_INVALID
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|_MM_EXCEPT_DENORM
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|_MM_EXCEPT_DIV_ZERO
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|_MM_EXCEPT_OVERFLOW
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|_MM_EXCEPT_UNDERFLOW
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|_MM_EXCEPT_INEXACT
value|(0x0020)
end_define

begin_define
define|#
directive|define
name|_MM_EXCEPT_MASK
value|(0x003f)
end_define

begin_define
define|#
directive|define
name|_MM_MASK_INVALID
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|_MM_MASK_DENORM
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|_MM_MASK_DIV_ZERO
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|_MM_MASK_OVERFLOW
value|(0x0400)
end_define

begin_define
define|#
directive|define
name|_MM_MASK_UNDERFLOW
value|(0x0800)
end_define

begin_define
define|#
directive|define
name|_MM_MASK_INEXACT
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|_MM_MASK_MASK
value|(0x1f80)
end_define

begin_define
define|#
directive|define
name|_MM_ROUND_NEAREST
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|_MM_ROUND_DOWN
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|_MM_ROUND_UP
value|(0x4000)
end_define

begin_define
define|#
directive|define
name|_MM_ROUND_TOWARD_ZERO
value|(0x6000)
end_define

begin_define
define|#
directive|define
name|_MM_ROUND_MASK
value|(0x6000)
end_define

begin_define
define|#
directive|define
name|_MM_FLUSH_ZERO_MASK
value|(0x8000)
end_define

begin_define
define|#
directive|define
name|_MM_FLUSH_ZERO_ON
value|(0x8000)
end_define

begin_define
define|#
directive|define
name|_MM_FLUSH_ZERO_OFF
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|_MM_GET_EXCEPTION_MASK
parameter_list|()
value|(_mm_getcsr()& _MM_MASK_MASK)
end_define

begin_define
define|#
directive|define
name|_MM_GET_EXCEPTION_STATE
parameter_list|()
value|(_mm_getcsr()& _MM_EXCEPT_MASK)
end_define

begin_define
define|#
directive|define
name|_MM_GET_FLUSH_ZERO_MODE
parameter_list|()
value|(_mm_getcsr()& _MM_FLUSH_ZERO_MASK)
end_define

begin_define
define|#
directive|define
name|_MM_GET_ROUNDING_MODE
parameter_list|()
value|(_mm_getcsr()& _MM_ROUND_MASK)
end_define

begin_define
define|#
directive|define
name|_MM_SET_EXCEPTION_MASK
parameter_list|(
name|x
parameter_list|)
value|(_mm_setcsr((_mm_getcsr()& ~_MM_MASK_MASK) | (x)))
end_define

begin_define
define|#
directive|define
name|_MM_SET_EXCEPTION_STATE
parameter_list|(
name|x
parameter_list|)
value|(_mm_setcsr((_mm_getcsr()& ~_MM_EXCEPT_MASK) | (x)))
end_define

begin_define
define|#
directive|define
name|_MM_SET_FLUSH_ZERO_MODE
parameter_list|(
name|x
parameter_list|)
value|(_mm_setcsr((_mm_getcsr()& ~_MM_FLUSH_ZERO_MASK) | (x)))
end_define

begin_define
define|#
directive|define
name|_MM_SET_ROUNDING_MODE
parameter_list|(
name|x
parameter_list|)
value|(_mm_setcsr((_mm_getcsr()& ~_MM_ROUND_MASK) | (x)))
end_define

begin_define
define|#
directive|define
name|_MM_TRANSPOSE4_PS
parameter_list|(
name|row0
parameter_list|,
name|row1
parameter_list|,
name|row2
parameter_list|,
name|row3
parameter_list|)
define|\
value|do { \   __m128 tmp3, tmp2, tmp1, tmp0; \   tmp0 = _mm_unpacklo_ps((row0), (row1)); \   tmp2 = _mm_unpacklo_ps((row2), (row3)); \   tmp1 = _mm_unpackhi_ps((row0), (row1)); \   tmp3 = _mm_unpackhi_ps((row2), (row3)); \   (row0) = _mm_movelh_ps(tmp0, tmp2); \   (row1) = _mm_movehl_ps(tmp2, tmp0); \   (row2) = _mm_movelh_ps(tmp1, tmp3); \   (row3) = _mm_movehl_ps(tmp3, tmp1); \ } while (0)
end_define

begin_comment
comment|/* Aliases for compatibility. */
end_comment

begin_define
define|#
directive|define
name|_m_pextrw
value|_mm_extract_pi16
end_define

begin_define
define|#
directive|define
name|_m_pinsrw
value|_mm_insert_pi16
end_define

begin_define
define|#
directive|define
name|_m_pmaxsw
value|_mm_max_pi16
end_define

begin_define
define|#
directive|define
name|_m_pmaxub
value|_mm_max_pu8
end_define

begin_define
define|#
directive|define
name|_m_pminsw
value|_mm_min_pi16
end_define

begin_define
define|#
directive|define
name|_m_pminub
value|_mm_min_pu8
end_define

begin_define
define|#
directive|define
name|_m_pmovmskb
value|_mm_movemask_pi8
end_define

begin_define
define|#
directive|define
name|_m_pmulhuw
value|_mm_mulhi_pu16
end_define

begin_define
define|#
directive|define
name|_m_pshufw
value|_mm_shuffle_pi16
end_define

begin_define
define|#
directive|define
name|_m_maskmovq
value|_mm_maskmove_si64
end_define

begin_define
define|#
directive|define
name|_m_pavgb
value|_mm_avg_pu8
end_define

begin_define
define|#
directive|define
name|_m_pavgw
value|_mm_avg_pu16
end_define

begin_define
define|#
directive|define
name|_m_psadbw
value|_mm_sad_pu8
end_define

begin_define
define|#
directive|define
name|_m_
value|_mm_
end_define

begin_define
define|#
directive|define
name|_m_
value|_mm_
end_define

begin_undef
undef|#
directive|undef
name|__DEFAULT_FN_ATTRS
end_undef

begin_comment
comment|/* Ugly hack for backwards-compatibility (compatible with gcc) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SSE2__
argument_list|)
operator|&&
operator|!
name|__building_module
argument_list|(
name|_Builtin_intrinsics
argument_list|)
end_if

begin_include
include|#
directive|include
file|<emmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XMMINTRIN_H */
end_comment

end_unit

