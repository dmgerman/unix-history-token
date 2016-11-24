begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- avxintrin.h - AVX intrinsics -------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IMMINTRIN_H
end_ifndef

begin_error
error|#
directive|error
literal|"Never use<avxintrin.h> directly; include<immintrin.h> instead."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__AVXINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__AVXINTRIN_H
end_define

begin_typedef
typedef|typedef
name|double
name|__v4df
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|__v8sf
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|__v4di
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|__v8si
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
name|short
name|__v16hi
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
name|char
name|__v32qi
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_comment
comment|/* Unsigned types */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|__v4du
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|__v8su
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|__v16hu
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|__v32qu
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_comment
comment|/* We need an explicitly signed variant for char. Note that this shouldn't  * appear in the interface though. */
end_comment

begin_typedef
typedef|typedef
name|signed
name|char
name|__v32qs
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|__m256
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
name|double
name|__m256d
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|__m256i
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_comment
comment|/* Define the default attributes for the functions in this file. */
end_comment

begin_define
define|#
directive|define
name|__DEFAULT_FN_ATTRS
value|__attribute__((__always_inline__, __nodebug__, __target__("avx")))
end_define

begin_comment
comment|/* Arithmetic */
end_comment

begin_comment
comment|/// \brief Adds two 256-bit vectors of [4 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VADDPD / ADDPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the sums of both
end_comment

begin_comment
comment|///    operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_add_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m256d
call|)
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
operator|+
operator|(
name|__v4df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds two 256-bit vectors of [8 x float].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VADDPS / ADDPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the sums of both
end_comment

begin_comment
comment|///    operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_add_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m256
call|)
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
operator|+
operator|(
name|__v8sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts two 256-bit vectors of [4 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VSUBPD / SUBPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing the minuend.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing the subtrahend.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the differences between
end_comment

begin_comment
comment|///    both operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_sub_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m256d
call|)
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
operator|-
operator|(
name|__v4df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts two 256-bit vectors of [8 x float].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VSUBPS / SUBPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing the minuend.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing the subtrahend.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the differences between
end_comment

begin_comment
comment|///    both operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_sub_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m256
call|)
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
operator|-
operator|(
name|__v8sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds the even-indexed values and subtracts the odd-indexed values of
end_comment

begin_comment
comment|///    two 256-bit vectors of [4 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VADDSUBPD / ADDSUBPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing the left source operand.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing the right source operand.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the alternating sums
end_comment

begin_comment
comment|///    and differences between both operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_addsub_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m256d
operator|)
name|__builtin_ia32_addsubpd256
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
argument_list|,
operator|(
name|__v4df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds the even-indexed values and subtracts the odd-indexed values of
end_comment

begin_comment
comment|///    two 256-bit vectors of [8 x float].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VADDSUBPS / ADDSUBPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing the left source operand.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing the right source operand.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the alternating sums and
end_comment

begin_comment
comment|///    differences between both operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_addsub_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m256
operator|)
name|__builtin_ia32_addsubps256
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|,
operator|(
name|__v8sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Divides two 256-bit vectors of [4 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VDIVPD / DIVPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing the dividend.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing the divisor.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the quotients of both
end_comment

begin_comment
comment|///    operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_div_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m256d
call|)
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
operator|/
operator|(
name|__v4df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Divides two 256-bit vectors of [8 x float].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VDIVPS / DIVPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing the dividend.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing the divisor.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the quotients of both
end_comment

begin_comment
comment|///    operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_div_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m256
call|)
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
operator|/
operator|(
name|__v8sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 256-bit vectors of [4 x double] and returns the greater
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
comment|/// This intrinsic corresponds to the \c VMAXPD / MAXPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing one of the operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing one of the operands.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the maximum values
end_comment

begin_comment
comment|///    between both operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_max_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m256d
operator|)
name|__builtin_ia32_maxpd256
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
argument_list|,
operator|(
name|__v4df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 256-bit vectors of [8 x float] and returns the greater
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
comment|/// This intrinsic corresponds to the \c VMAXPS / MAXPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing one of the operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing one of the operands.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the maximum values
end_comment

begin_comment
comment|///    between both operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_max_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m256
operator|)
name|__builtin_ia32_maxps256
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|,
operator|(
name|__v8sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 256-bit vectors of [4 x double] and returns the lesser
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
comment|/// This intrinsic corresponds to the \c VMINPD / MINPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing one of the operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing one of the operands.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the minimum values
end_comment

begin_comment
comment|///    between both operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_min_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m256d
operator|)
name|__builtin_ia32_minpd256
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
argument_list|,
operator|(
name|__v4df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares two 256-bit vectors of [8 x float] and returns the lesser
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
comment|/// This intrinsic corresponds to the \c VMINPS / MINPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing one of the operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing one of the operands.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the minimum values
end_comment

begin_comment
comment|///    between both operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_min_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m256
operator|)
name|__builtin_ia32_minps256
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|,
operator|(
name|__v8sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Multiplies two 256-bit vectors of [4 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VMULPD / MULPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing one of the operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing one of the operands.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the products of both
end_comment

begin_comment
comment|///    operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_mul_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m256d
call|)
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
operator|*
operator|(
name|__v4df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Multiplies two 256-bit vectors of [8 x float].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VMULPS / MULPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing one of the operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing one of the operands.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the products of both
end_comment

begin_comment
comment|///    operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_mul_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m256
call|)
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
operator|*
operator|(
name|__v8sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Calculates the square roots of the values in a 256-bit vector of
end_comment

begin_comment
comment|///    [4 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VSQRTPD / SQRTPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double].
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the square roots of the
end_comment

begin_comment
comment|///    values in the operand.
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_sqrt_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m256d
operator|)
name|__builtin_ia32_sqrtpd256
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Calculates the square roots of the values in a 256-bit vector of
end_comment

begin_comment
comment|///    [8 x float].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VSQRTPS / SQRTPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float].
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the square roots of the
end_comment

begin_comment
comment|///    values in the operand.
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_sqrt_ps
parameter_list|(
name|__m256
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m256
operator|)
name|__builtin_ia32_sqrtps256
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Calculates the reciprocal square roots of the values in a 256-bit
end_comment

begin_comment
comment|///    vector of [8 x float].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VRSQRTPS / RSQRTPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float].
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the reciprocal square
end_comment

begin_comment
comment|///    roots of the values in the operand.
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_rsqrt_ps
parameter_list|(
name|__m256
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m256
operator|)
name|__builtin_ia32_rsqrtps256
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Calculates the reciprocals of the values in a 256-bit vector of
end_comment

begin_comment
comment|///    [8 x float].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VRCPPS / RCPPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float].
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the reciprocals of the
end_comment

begin_comment
comment|///    values in the operand.
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_rcp_ps
parameter_list|(
name|__m256
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m256
operator|)
name|__builtin_ia32_rcpps256
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Rounds the values in a 256-bit vector of [4 x double] as specified
end_comment

begin_comment
comment|///    by the byte operand. The source values are rounded to integer values and
end_comment

begin_comment
comment|///    returned as 64-bit double-precision floating-point values.
end_comment

begin_comment
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
comment|/// __m256d _mm256_round_pd(__m256d V, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VROUNDPD / ROUNDPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param V
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double].
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An integer value that specifies the rounding operation.
end_comment

begin_comment
comment|///    Bits [7:4] are reserved.
end_comment

begin_comment
comment|///    Bit [3] is a precision exception value:
end_comment

begin_comment
comment|///    0: A normal PE exception is used.
end_comment

begin_comment
comment|///    1: The PE field is not updated.
end_comment

begin_comment
comment|///    Bit [2] is the rounding control source:
end_comment

begin_comment
comment|///    0: Use bits [1:0] of M.
end_comment

begin_comment
comment|///    1: Use the current MXCSR setting.
end_comment

begin_comment
comment|///    Bits [1:0] contain the rounding control definition:
end_comment

begin_comment
comment|///    00: Nearest.
end_comment

begin_comment
comment|///    01: Downward (toward negative infinity).
end_comment

begin_comment
comment|///    10: Upward (toward positive infinity).
end_comment

begin_comment
comment|///    11: Truncated.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the rounded values.
end_comment

begin_define
define|#
directive|define
name|_mm256_round_pd
parameter_list|(
name|V
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \     (__m256d)__builtin_ia32_roundpd256((__v4df)(__m256d)(V), (M)); })
end_define

begin_comment
comment|/// \brief Rounds the values stored in a 256-bit vector of [8 x float] as
end_comment

begin_comment
comment|///    specified by the byte operand. The source values are rounded to integer
end_comment

begin_comment
comment|///    values and returned as floating-point values.
end_comment

begin_comment
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
comment|/// __m256 _mm256_round_ps(__m256 V, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VROUNDPS / ROUNDPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param V
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float].
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An integer value that specifies the rounding operation.
end_comment

begin_comment
comment|///    Bits [7:4] are reserved.
end_comment

begin_comment
comment|///    Bit [3] is a precision exception value:
end_comment

begin_comment
comment|///    0: A normal PE exception is used.
end_comment

begin_comment
comment|///    1: The PE field is not updated.
end_comment

begin_comment
comment|///    Bit [2] is the rounding control source:
end_comment

begin_comment
comment|///    0: Use bits [1:0] of M.
end_comment

begin_comment
comment|///    1: Use the current MXCSR setting.
end_comment

begin_comment
comment|///    Bits [1:0] contain the rounding control definition:
end_comment

begin_comment
comment|///    00: Nearest.
end_comment

begin_comment
comment|///    01: Downward (toward negative infinity).
end_comment

begin_comment
comment|///    10: Upward (toward positive infinity).
end_comment

begin_comment
comment|///    11: Truncated.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the rounded values.
end_comment

begin_define
define|#
directive|define
name|_mm256_round_ps
parameter_list|(
name|V
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m256)__builtin_ia32_roundps256((__v8sf)(__m256)(V), (M)); })
end_define

begin_comment
comment|/// \brief Rounds up the values stored in a 256-bit vector of [4 x double]. The
end_comment

begin_comment
comment|///    source values are rounded up to integer values and returned as 64-bit
end_comment

begin_comment
comment|///    double-precision floating-point values.
end_comment

begin_comment
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
comment|/// __m256d _mm256_ceil_pd(__m256d V);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VROUNDPD / ROUNDPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param V
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double].
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the rounded up values.
end_comment

begin_define
define|#
directive|define
name|_mm256_ceil_pd
parameter_list|(
name|V
parameter_list|)
value|_mm256_round_pd((V), _MM_FROUND_CEIL)
end_define

begin_comment
comment|/// \brief Rounds down the values stored in a 256-bit vector of [4 x double].
end_comment

begin_comment
comment|///    The source values are rounded down to integer values and returned as
end_comment

begin_comment
comment|///    64-bit double-precision floating-point values.
end_comment

begin_comment
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
comment|/// __m256d _mm256_floor_pd(__m256d V);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VROUNDPD / ROUNDPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param V
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double].
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the rounded down
end_comment

begin_comment
comment|///    values.
end_comment

begin_define
define|#
directive|define
name|_mm256_floor_pd
parameter_list|(
name|V
parameter_list|)
value|_mm256_round_pd((V), _MM_FROUND_FLOOR)
end_define

begin_comment
comment|/// \brief Rounds up the values stored in a 256-bit vector of [8 x float]. The
end_comment

begin_comment
comment|///    source values are rounded up to integer values and returned as
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
comment|/// \code
end_comment

begin_comment
comment|/// __m256 _mm256_ceil_ps(__m256 V);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VROUNDPS / ROUNDPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param V
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float].
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the rounded up values.
end_comment

begin_define
define|#
directive|define
name|_mm256_ceil_ps
parameter_list|(
name|V
parameter_list|)
value|_mm256_round_ps((V), _MM_FROUND_CEIL)
end_define

begin_comment
comment|/// \brief Rounds down the values stored in a 256-bit vector of [8 x float]. The
end_comment

begin_comment
comment|///    source values are rounded down to integer values and returned as
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
comment|/// \code
end_comment

begin_comment
comment|/// __m256 _mm256_floor_ps(__m256 V);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VROUNDPS / ROUNDPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param V
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float].
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the rounded down values.
end_comment

begin_define
define|#
directive|define
name|_mm256_floor_ps
parameter_list|(
name|V
parameter_list|)
value|_mm256_round_ps((V), _MM_FROUND_FLOOR)
end_define

begin_comment
comment|/* Logical */
end_comment

begin_comment
comment|/// \brief Performs a bitwise AND of two 256-bit vectors of [4 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VANDPD / ANDPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the bitwise AND of the
end_comment

begin_comment
comment|///    values between both operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_and_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m256d
call|)
argument_list|(
operator|(
name|__v4du
operator|)
name|__a
operator|&
operator|(
name|__v4du
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise AND of two 256-bit vectors of [8 x float].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VANDPS / ANDPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the bitwise AND of the
end_comment

begin_comment
comment|///    values between both operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_and_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m256
call|)
argument_list|(
operator|(
name|__v8su
operator|)
name|__a
operator|&
operator|(
name|__v8su
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise AND of two 256-bit vectors of [4 x double], using
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
comment|/// This intrinsic corresponds to the \c VANDNPD / ANDNPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing the left source operand. The
end_comment

begin_comment
comment|///    one's complement of this value is used in the bitwise AND.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing the right source operand.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the bitwise AND of the
end_comment

begin_comment
comment|///    values of the second operand and the one's complement of the first
end_comment

begin_comment
comment|///    operand.
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_andnot_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m256d
call|)
argument_list|(
operator|~
operator|(
name|__v4du
operator|)
name|__a
operator|&
operator|(
name|__v4du
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise AND of two 256-bit vectors of [8 x float], using
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
comment|/// This intrinsic corresponds to the \c VANDNPS / ANDNPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing the left source operand. The
end_comment

begin_comment
comment|///    one's complement of this value is used in the bitwise AND.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing the right source operand.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the bitwise AND of the
end_comment

begin_comment
comment|///    values of the second operand and the one's complement of the first
end_comment

begin_comment
comment|///    operand.
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_andnot_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m256
call|)
argument_list|(
operator|~
operator|(
name|__v8su
operator|)
name|__a
operator|&
operator|(
name|__v8su
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise OR of two 256-bit vectors of [4 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VORPD / ORPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the bitwise OR of the
end_comment

begin_comment
comment|///    values between both operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_or_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m256d
call|)
argument_list|(
operator|(
name|__v4du
operator|)
name|__a
operator||
operator|(
name|__v4du
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise OR of two 256-bit vectors of [8 x float].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VORPS / ORPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the bitwise OR of the
end_comment

begin_comment
comment|///    values between both operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_or_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m256
call|)
argument_list|(
operator|(
name|__v8su
operator|)
name|__a
operator||
operator|(
name|__v8su
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise XOR of two 256-bit vectors of [4 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VXORPD / XORPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the bitwise XOR of the
end_comment

begin_comment
comment|///    values between both operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_xor_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m256d
call|)
argument_list|(
operator|(
name|__v4du
operator|)
name|__a
operator|^
operator|(
name|__v4du
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise XOR of two 256-bit vectors of [8 x float].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VXORPS / XORPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the bitwise XOR of the
end_comment

begin_comment
comment|///    values between both operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_xor_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m256
call|)
argument_list|(
operator|(
name|__v8su
operator|)
name|__a
operator|^
operator|(
name|__v8su
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Horizontal arithmetic */
end_comment

begin_comment
comment|/// \brief Horizontally adds the adjacent pairs of values contained in two
end_comment

begin_comment
comment|///    256-bit vectors of [4 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VHADDPD / HADDPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing one of the source operands.
end_comment

begin_comment
comment|///    The horizontal sums of the values are returned in the even-indexed
end_comment

begin_comment
comment|///    elements of a vector of [4 x double].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing one of the source operands.
end_comment

begin_comment
comment|///    The horizontal sums of the values are returned in the odd-indexed
end_comment

begin_comment
comment|///    elements of a vector of [4 x double].
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the horizontal sums of
end_comment

begin_comment
comment|///    both operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_hadd_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m256d
operator|)
name|__builtin_ia32_haddpd256
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
argument_list|,
operator|(
name|__v4df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Horizontally adds the adjacent pairs of values contained in two
end_comment

begin_comment
comment|///    256-bit vectors of [8 x float].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VHADDPS / HADDPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing one of the source operands.
end_comment

begin_comment
comment|///    The horizontal sums of the values are returned in the elements with
end_comment

begin_comment
comment|///    index 0, 1, 4, 5 of a vector of [8 x float].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing one of the source operands.
end_comment

begin_comment
comment|///    The horizontal sums of the values are returned in the elements with
end_comment

begin_comment
comment|///    index 2, 3, 6, 7 of a vector of [8 x float].
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the horizontal sums of
end_comment

begin_comment
comment|///    both operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_hadd_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m256
operator|)
name|__builtin_ia32_haddps256
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|,
operator|(
name|__v8sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Horizontally subtracts the adjacent pairs of values contained in two
end_comment

begin_comment
comment|///    256-bit vectors of [4 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VHSUBPD / HSUBPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing one of the source operands.
end_comment

begin_comment
comment|///    The horizontal differences between the values are returned in the
end_comment

begin_comment
comment|///    even-indexed elements of a vector of [4 x double].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double] containing one of the source operands.
end_comment

begin_comment
comment|///    The horizontal differences between the values are returned in the
end_comment

begin_comment
comment|///    odd-indexed elements of a vector of [4 x double].
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the horizontal
end_comment

begin_comment
comment|///    differences of both operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_hsub_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m256d
operator|)
name|__builtin_ia32_hsubpd256
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
argument_list|,
operator|(
name|__v4df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Horizontally subtracts the adjacent pairs of values contained in two
end_comment

begin_comment
comment|///    256-bit vectors of [8 x float].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VHSUBPS / HSUBPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing one of the source operands.
end_comment

begin_comment
comment|///    The horizontal differences between the values are returned in the
end_comment

begin_comment
comment|///    elements with index 0, 1, 4, 5 of a vector of [8 x float].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float] containing one of the source operands.
end_comment

begin_comment
comment|///    The horizontal differences between the values are returned in the
end_comment

begin_comment
comment|///    elements with index 2, 3, 6, 7 of a vector of [8 x float].
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the horizontal
end_comment

begin_comment
comment|///    differences of both operands.
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_hsub_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m256
operator|)
name|__builtin_ia32_hsubps256
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|,
operator|(
name|__v8sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Vector permutations */
end_comment

begin_comment
comment|/// \brief Copies the values in a 128-bit vector of [2 x double] as specified
end_comment

begin_comment
comment|///    by the 128-bit integer vector operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPERMILPD / PERMILPD instruction.
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
comment|/// \param __c
end_comment

begin_comment
comment|///    A 128-bit integer vector operand specifying how the values are to be
end_comment

begin_comment
comment|///    copied.
end_comment

begin_comment
comment|///    Bit [1]:
end_comment

begin_comment
comment|///    0: Bits [63:0] of the source are copied to bits [63:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    1: Bits [127:64] of the source are copied to bits [63:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bit [65]:
end_comment

begin_comment
comment|///    0: Bits [63:0] of the source are copied to bits [127:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    1: Bits [127:64] of the source are copied to bits [127:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the copied values.
end_comment

begin_function
specifier|static
name|__inline
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_permutevar_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128i
name|__c
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_vpermilvarpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2di
operator|)
name|__c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Copies the values in a 256-bit vector of [4 x double] as
end_comment

begin_comment
comment|///    specified by the 256-bit integer vector operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPERMILPD / PERMILPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double].
end_comment

begin_comment
comment|/// \param __c
end_comment

begin_comment
comment|///    A 256-bit integer vector operand specifying how the values are to be
end_comment

begin_comment
comment|///    copied.
end_comment

begin_comment
comment|///    Bit [1]:
end_comment

begin_comment
comment|///    0: Bits [63:0] of the source are copied to bits [63:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    1: Bits [127:64] of the source are copied to bits [63:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bit [65]:
end_comment

begin_comment
comment|///    0: Bits [63:0] of the source are copied to bits [127:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    1: Bits [127:64] of the source are copied to bits [127:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bit [129]:
end_comment

begin_comment
comment|///    0: Bits [191:128] of the source are copied to bits [191:128] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    1: Bits [255:192] of the source are copied to bits [191:128] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bit [193]:
end_comment

begin_comment
comment|///    0: Bits [191:128] of the source are copied to bits [255:192] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    1: Bits [255:192] of the source are copied to bits [255:192] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the copied values.
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_permutevar_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256i
name|__c
parameter_list|)
block|{
return|return
operator|(
name|__m256d
operator|)
name|__builtin_ia32_vpermilvarpd256
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
argument_list|,
operator|(
name|__v4di
operator|)
name|__c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Copies the values stored in a 128-bit vector of [4 x float] as
end_comment

begin_comment
comment|///    specified by the 128-bit integer vector operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPERMILPS / PERMILPS instruction.
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
comment|/// \param __c
end_comment

begin_comment
comment|///    A 128-bit integer vector operand specifying how the values are to be
end_comment

begin_comment
comment|///    copied.
end_comment

begin_comment
comment|///    Bits [1:0]:
end_comment

begin_comment
comment|///    00: Bits [31:0] of the source are copied to bits [31:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [63:32] of the source are copied to bits [31:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [95:64] of the source are copied to bits [31:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [127:96] of the source are copied to bits [31:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bits [33:32]:
end_comment

begin_comment
comment|///    00: Bits [31:0] of the source are copied to bits [63:32] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [63:32] of the source are copied to bits [63:32] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [95:64] of the source are copied to bits [63:32] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [127:96] of the source are copied to bits [63:32] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bits [65:64]:
end_comment

begin_comment
comment|///    00: Bits [31:0] of the source are copied to bits [95:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [63:32] of the source are copied to bits [95:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [95:64] of the source are copied to bits [95:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [127:96] of the source are copied to bits [95:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bits [97:96]:
end_comment

begin_comment
comment|///    00: Bits [31:0] of the source are copied to bits [127:96] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [63:32] of the source are copied to bits [127:96] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [95:64] of the source are copied to bits [127:96] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [127:96] of the source are copied to bits [127:96] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the copied values.
end_comment

begin_function
specifier|static
name|__inline
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_permutevar_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128i
name|__c
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_vpermilvarps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4si
operator|)
name|__c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Copies the values stored in a 256-bit vector of [8 x float] as
end_comment

begin_comment
comment|///    specified by the 256-bit integer vector operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPERMILPS / PERMILPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float].
end_comment

begin_comment
comment|/// \param __c
end_comment

begin_comment
comment|///    A 256-bit integer vector operand specifying how the values are to be
end_comment

begin_comment
comment|///    copied.
end_comment

begin_comment
comment|///    Bits [1:0]:
end_comment

begin_comment
comment|///    00: Bits [31:0] of the source are copied to bits [31:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [63:32] of the source are copied to bits [31:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [95:64] of the source are copied to bits [31:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [127:96] of the source are copied to bits [31:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bits [33:32]:
end_comment

begin_comment
comment|///    00: Bits [31:0] of the source are copied to bits [63:32] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [63:32] of the source are copied to bits [63:32] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [95:64] of the source are copied to bits [63:32] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [127:96] of the source are copied to bits [63:32] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bits [65:64]:
end_comment

begin_comment
comment|///    00: Bits [31:0] of the source are copied to bits [95:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [63:32] of the source are copied to bits [95:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [95:64] of the source are copied to bits [95:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [127:96] of the source are copied to bits [95:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bits [97:96]:
end_comment

begin_comment
comment|///    00: Bits [31:0] of the source are copied to bits [127:96] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [63:32] of the source are copied to bits [127:96] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [95:64] of the source are copied to bits [127:96] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [127:96] of the source are copied to bits [127:96] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bits [129:128]:
end_comment

begin_comment
comment|///    00: Bits [159:128] of the source are copied to bits [159:128] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [191:160] of the source are copied to bits [159:128] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [223:192] of the source are copied to bits [159:128] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [255:224] of the source are copied to bits [159:128] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bits [161:160]:
end_comment

begin_comment
comment|///    00: Bits [159:128] of the source are copied to bits [191:160] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [191:160] of the source are copied to bits [191:160] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [223:192] of the source are copied to bits [191:160] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [255:224] of the source are copied to bits [191:160] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bits [193:192]:
end_comment

begin_comment
comment|///    00: Bits [159:128] of the source are copied to bits [223:192] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [191:160] of the source are copied to bits [223:192] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [223:192] of the source are copied to bits [223:192] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [255:224] of the source are copied to bits [223:192] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bits [225:224]:
end_comment

begin_comment
comment|///    00: Bits [159:128] of the source are copied to bits [255:224] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [191:160] of the source are copied to bits [255:224] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [223:192] of the source are copied to bits [255:224] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [255:224] of the source are copied to bits [255:224] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the copied values.
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_permutevar_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256i
name|__c
parameter_list|)
block|{
return|return
operator|(
name|__m256
operator|)
name|__builtin_ia32_vpermilvarps256
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|,
operator|(
name|__v8si
operator|)
name|__c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Copies the values in a 128-bit vector of [2 x double] as
end_comment

begin_comment
comment|///    specified by the immediate integer operand.
end_comment

begin_comment
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
comment|/// __m128d _mm_permute_pd(__m128d A, const int C);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPERMILPD / PERMILPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param A
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param C
end_comment

begin_comment
comment|///    An immediate integer operand specifying how the values are to be copied.
end_comment

begin_comment
comment|///    Bit [0]:
end_comment

begin_comment
comment|///    0: Bits [63:0] of the source are copied to bits [63:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    1: Bits [127:64] of the source are copied to bits [63:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bit [1]:
end_comment

begin_comment
comment|///    0: Bits [63:0] of the source are copied to bits [127:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    1: Bits [127:64] of the source are copied to bits [127:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the copied values.
end_comment

begin_define
define|#
directive|define
name|_mm_permute_pd
parameter_list|(
name|A
parameter_list|,
name|C
parameter_list|)
value|__extension__ ({ \   (__m128d)__builtin_shufflevector((__v2df)(__m128d)(A), \                                    (__v2df)_mm_undefined_pd(), \                                    ((C)>> 0)& 0x1, ((C)>> 1)& 0x1); })
end_define

begin_comment
comment|/// \brief Copies the values in a 256-bit vector of [4 x double] as
end_comment

begin_comment
comment|///    specified by the immediate integer operand.
end_comment

begin_comment
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
comment|/// __m256d _mm256_permute_pd(__m256d A, const int C);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPERMILPD / PERMILPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param A
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double].
end_comment

begin_comment
comment|/// \param C
end_comment

begin_comment
comment|///    An immediate integer operand specifying how the values are to be copied.
end_comment

begin_comment
comment|///    Bit [0]:
end_comment

begin_comment
comment|///    0: Bits [63:0] of the source are copied to bits [63:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    1: Bits [127:64] of the source are copied to bits [63:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bit [1]:
end_comment

begin_comment
comment|///    0: Bits [63:0] of the source are copied to bits [127:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    1: Bits [127:64] of the source are copied to bits [127:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bit [2]:
end_comment

begin_comment
comment|///    0: Bits [191:128] of the source are copied to bits [191:128] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    1: Bits [255:192] of the source are copied to bits [191:128] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bit [3]:
end_comment

begin_comment
comment|///    0: Bits [191:128] of the source are copied to bits [255:192] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    1: Bits [255:192] of the source are copied to bits [255:192] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the copied values.
end_comment

begin_define
define|#
directive|define
name|_mm256_permute_pd
parameter_list|(
name|A
parameter_list|,
name|C
parameter_list|)
value|__extension__ ({ \   (__m256d)__builtin_shufflevector((__v4df)(__m256d)(A), \                                    (__v4df)_mm256_undefined_pd(), \                                    0 + (((C)>> 0)& 0x1), \                                    0 + (((C)>> 1)& 0x1), \                                    2 + (((C)>> 2)& 0x1), \                                    2 + (((C)>> 3)& 0x1)); })
end_define

begin_comment
comment|/// \brief Copies the values in a 128-bit vector of [4 x float] as
end_comment

begin_comment
comment|///    specified by the immediate integer operand.
end_comment

begin_comment
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
comment|/// __m128 _mm_permute_ps(__m128 A, const int C);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPERMILPS / PERMILPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param A
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \param C
end_comment

begin_comment
comment|///    An immediate integer operand specifying how the values are to be copied.
end_comment

begin_comment
comment|///    Bits [1:0]:
end_comment

begin_comment
comment|///    00: Bits [31:0] of the source are copied to bits [31:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [63:32] of the source are copied to bits [31:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [95:64] of the source are copied to bits [31:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [127:96] of the source are copied to bits [31:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bits [3:2]:
end_comment

begin_comment
comment|///    00: Bits [31:0] of the source are copied to bits [63:32] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [63:32] of the source are copied to bits [63:32] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [95:64] of the source are copied to bits [63:32] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [127:96] of the source are copied to bits [63:32] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bits [5:4]:
end_comment

begin_comment
comment|///    00: Bits [31:0] of the source are copied to bits [95:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [63:32] of the source are copied to bits [95:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [95:64] of the source are copied to bits [95:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [127:96] of the source are copied to bits [95:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bits [7:6]:
end_comment

begin_comment
comment|///    00: Bits [31:0] of the source are copied to bits [127:96] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [63:32] of the source are copied to bits [127:96] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [95:64] of the source are copied to bits [127:96] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [127:96] of the source are copied to bits [127:96] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the copied values.
end_comment

begin_define
define|#
directive|define
name|_mm_permute_ps
parameter_list|(
name|A
parameter_list|,
name|C
parameter_list|)
value|__extension__ ({ \   (__m128)__builtin_shufflevector((__v4sf)(__m128)(A), \                                   (__v4sf)_mm_undefined_ps(), \                                   ((C)>> 0)& 0x3, ((C)>> 2)& 0x3, \                                   ((C)>> 4)& 0x3, ((C)>> 6)& 0x3); })
end_define

begin_comment
comment|/// \brief Copies the values in a 256-bit vector of [8 x float] as
end_comment

begin_comment
comment|///    specified by the immediate integer operand.
end_comment

begin_comment
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
comment|/// __m256 _mm256_permute_ps(__m256 A, const int C);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPERMILPS / PERMILPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param A
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float].
end_comment

begin_comment
comment|/// \param C
end_comment

begin_comment
comment|///    An immediate integer operand specifying how the values are to be copied.
end_comment

begin_comment
comment|///    Bits [1:0]:
end_comment

begin_comment
comment|///    00: Bits [31:0] of the source are copied to bits [31:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [63:32] of the source are copied to bits [31:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [95:64] of the source are copied to bits [31:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [127:96] of the source are copied to bits [31:0] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bits [3:2]:
end_comment

begin_comment
comment|///    00: Bits [31:0] of the source are copied to bits [63:32] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [63:32] of the source are copied to bits [63:32] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [95:64] of the source are copied to bits [63:32] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [127:96] of the source are copied to bits [63:32] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bits [5:4]:
end_comment

begin_comment
comment|///    00: Bits [31:0] of the source are copied to bits [95:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [63:32] of the source are copied to bits [95:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [95:64] of the source are copied to bits [95:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [127:96] of the source are copied to bits [95:64] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bits [7:6]:
end_comment

begin_comment
comment|///    00: Bits [31:0] of the source are copied to bits [127:96] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [63:32] of the source are copied to bits [127:96] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [95:64] of the source are copied to bits [127:96] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [127:96] of the source are copied to bits [127:96] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bits [1:0]:
end_comment

begin_comment
comment|///    00: Bits [159:128] of the source are copied to bits [159:128] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [191:160] of the source are copied to bits [159:128] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [223:192] of the source are copied to bits [159:128] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [255:224] of the source are copied to bits [159:128] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bits [3:2]:
end_comment

begin_comment
comment|///    00: Bits [159:128] of the source are copied to bits [191:160] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [191:160] of the source are copied to bits [191:160] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [223:192] of the source are copied to bits [191:160] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [255:224] of the source are copied to bits [191:160] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bits [5:4]:
end_comment

begin_comment
comment|///    00: Bits [159:128] of the source are copied to bits [223:192] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [191:160] of the source are copied to bits [223:192] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [223:192] of the source are copied to bits [223:192] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [255:224] of the source are copied to bits [223:192] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    Bits [7:6]:
end_comment

begin_comment
comment|///    00: Bits [159:128] of the source are copied to bits [255:224] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    01: Bits [191:160] of the source are copied to bits [255:224] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    10: Bits [223:192] of the source are copied to bits [255:224] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|///    11: Bits [255:224] of the source are copied to bits [255:224] of the
end_comment

begin_comment
comment|///    returned vector.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the copied values.
end_comment

begin_define
define|#
directive|define
name|_mm256_permute_ps
parameter_list|(
name|A
parameter_list|,
name|C
parameter_list|)
value|__extension__ ({ \   (__m256)__builtin_shufflevector((__v8sf)(__m256)(A), \                                   (__v8sf)_mm256_undefined_ps(), \                                   0 + (((C)>> 0)& 0x3), \                                   0 + (((C)>> 2)& 0x3), \                                   0 + (((C)>> 4)& 0x3), \                                   0 + (((C)>> 6)& 0x3), \                                   4 + (((C)>> 0)& 0x3), \                                   4 + (((C)>> 2)& 0x3), \                                   4 + (((C)>> 4)& 0x3), \                                   4 + (((C)>> 6)& 0x3)); })
end_define

begin_comment
comment|/// \brief Permutes 128-bit data values stored in two 256-bit vectors of
end_comment

begin_comment
comment|///    [4 x double], as specified by the immediate integer operand.
end_comment

begin_comment
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
comment|/// __m256d _mm256_permute2f128_pd(__m256d V1, __m256d V2, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPERM2F128 / PERM2F128 instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param V1
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double].
end_comment

begin_comment
comment|/// \param V2
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double.
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An immediate integer operand specifying how the values are to be
end_comment

begin_comment
comment|///    permuted.
end_comment

begin_comment
comment|///    Bits [1:0]:
end_comment

begin_comment
comment|///    00: Bits [127:0] of operand V1 are copied to bits [127:0] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    01: Bits [255:128] of operand V1 are copied to bits [127:0] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    10: Bits [127:0] of operand V2 are copied to bits [127:0] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    11: Bits [255:128] of operand V2 are copied to bits [127:0] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    Bits [5:4]:
end_comment

begin_comment
comment|///    00: Bits [127:0] of operand V1 are copied to bits [255:128] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    01: Bits [255:128] of operand V1 are copied to bits [255:128] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    10: Bits [127:0] of operand V2 are copied to bits [255:128] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    11: Bits [255:128] of operand V2 are copied to bits [255:128] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the copied values.
end_comment

begin_define
define|#
directive|define
name|_mm256_permute2f128_pd
parameter_list|(
name|V1
parameter_list|,
name|V2
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m256d)__builtin_ia32_vperm2f128_pd256((__v4df)(__m256d)(V1), \                                            (__v4df)(__m256d)(V2), (M)); })
end_define

begin_comment
comment|/// \brief Permutes 128-bit data values stored in two 256-bit vectors of
end_comment

begin_comment
comment|///    [8 x float], as specified by the immediate integer operand.
end_comment

begin_comment
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
comment|/// __m256 _mm256_permute2f128_ps(__m256 V1, __m256 V2, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPERM2F128 / PERM2F128 instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param V1
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float].
end_comment

begin_comment
comment|/// \param V2
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float].
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An immediate integer operand specifying how the values are to be
end_comment

begin_comment
comment|///    permuted.
end_comment

begin_comment
comment|///    Bits [1:0]:
end_comment

begin_comment
comment|///    00: Bits [127:0] of operand V1 are copied to bits [127:0] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    01: Bits [255:128] of operand V1 are copied to bits [127:0] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    10: Bits [127:0] of operand V2 are copied to bits [127:0] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    11: Bits [255:128] of operand V2 are copied to bits [127:0] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    Bits [5:4]:
end_comment

begin_comment
comment|///    00: Bits [127:0] of operand V1 are copied to bits [255:128] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    01: Bits [255:128] of operand V1 are copied to bits [255:128] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    10: Bits [127:0] of operand V2 are copied to bits [255:128] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    11: Bits [255:128] of operand V2 are copied to bits [255:128] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the copied values.
end_comment

begin_define
define|#
directive|define
name|_mm256_permute2f128_ps
parameter_list|(
name|V1
parameter_list|,
name|V2
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m256)__builtin_ia32_vperm2f128_ps256((__v8sf)(__m256)(V1), \                                           (__v8sf)(__m256)(V2), (M)); })
end_define

begin_comment
comment|/// \brief Permutes 128-bit data values stored in two 256-bit integer vectors,
end_comment

begin_comment
comment|///    as specified by the immediate integer operand.
end_comment

begin_comment
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
comment|/// __m256i _mm256_permute2f128_si256(__m256i V1, __m256i V2, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPERM2F128 / PERM2F128 instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param V1
end_comment

begin_comment
comment|///    A 256-bit integer vector.
end_comment

begin_comment
comment|/// \param V2
end_comment

begin_comment
comment|///    A 256-bit integer vector.
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An immediate integer operand specifying how the values are to be copied.
end_comment

begin_comment
comment|///    Bits [1:0]:
end_comment

begin_comment
comment|///    00: Bits [127:0] of operand V1 are copied to bits [127:0] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    01: Bits [255:128] of operand V1 are copied to bits [127:0] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    10: Bits [127:0] of operand V2 are copied to bits [127:0] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    11: Bits [255:128] of operand V2 are copied to bits [127:0] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    Bits [5:4]:
end_comment

begin_comment
comment|///    00: Bits [127:0] of operand V1 are copied to bits [255:128] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    01: Bits [255:128] of operand V1 are copied to bits [255:128] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    10: Bits [127:0] of operand V2 are copied to bits [255:128] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    11: Bits [255:128] of operand V2 are copied to bits [255:128] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 256-bit integer vector containing the copied values.
end_comment

begin_define
define|#
directive|define
name|_mm256_permute2f128_si256
parameter_list|(
name|V1
parameter_list|,
name|V2
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m256i)__builtin_ia32_vperm2f128_si256((__v8si)(__m256i)(V1), \                                            (__v8si)(__m256i)(V2), (M)); })
end_define

begin_comment
comment|/* Vector Blend */
end_comment

begin_comment
comment|/// \brief Merges 64-bit double-precision data values stored in either of the
end_comment

begin_comment
comment|///    two 256-bit vectors of [4 x double], as specified by the immediate
end_comment

begin_comment
comment|///    integer operand.
end_comment

begin_comment
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
comment|/// __m256d _mm256_blend_pd(__m256d V1, __m256d V2, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VBLENDPD / BLENDPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param V1
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double].
end_comment

begin_comment
comment|/// \param V2
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double].
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An immediate integer operand, with mask bits [3:0] specifying how the
end_comment

begin_comment
comment|///    values are to be copied. The position of the mask bit corresponds to the
end_comment

begin_comment
comment|///    index of a copied value. When a mask bit is 0, the corresponding 64-bit
end_comment

begin_comment
comment|///    element in operand V1 is copied to the same position in the destination.
end_comment

begin_comment
comment|///    When a mask bit is 1, the corresponding 64-bit element in operand V2 is
end_comment

begin_comment
comment|///    copied to the same position in the destination.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the copied values.
end_comment

begin_define
define|#
directive|define
name|_mm256_blend_pd
parameter_list|(
name|V1
parameter_list|,
name|V2
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m256d)__builtin_shufflevector((__v4df)(__m256d)(V1), \                                    (__v4df)(__m256d)(V2), \                                    (((M)& 0x01) ? 4 : 0), \                                    (((M)& 0x02) ? 5 : 1), \                                    (((M)& 0x04) ? 6 : 2), \                                    (((M)& 0x08) ? 7 : 3)); })
end_define

begin_comment
comment|/// \brief Merges 32-bit single-precision data values stored in either of the
end_comment

begin_comment
comment|///    two 256-bit vectors of [8 x float], as specified by the immediate
end_comment

begin_comment
comment|///    integer operand.
end_comment

begin_comment
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
comment|/// __m256 _mm256_blend_ps(__m256 V1, __m256 V2, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VBLENDPS / BLENDPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param V1
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float].
end_comment

begin_comment
comment|/// \param V2
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float].
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An immediate integer operand, with mask bits [7:0] specifying how the
end_comment

begin_comment
comment|///    values are to be copied. The position of the mask bit corresponds to the
end_comment

begin_comment
comment|///    index of a copied value. When a mask bit is 0, the corresponding 32-bit
end_comment

begin_comment
comment|///    element in operand V1 is copied to the same position in the destination.
end_comment

begin_comment
comment|///    When a mask bit is 1, the corresponding 32-bit element in operand V2 is
end_comment

begin_comment
comment|///    copied to the same position in the destination.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the copied values.
end_comment

begin_define
define|#
directive|define
name|_mm256_blend_ps
parameter_list|(
name|V1
parameter_list|,
name|V2
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m256)__builtin_shufflevector((__v8sf)(__m256)(V1), \                                   (__v8sf)(__m256)(V2), \                                   (((M)& 0x01) ?  8 : 0), \                                   (((M)& 0x02) ?  9 : 1), \                                   (((M)& 0x04) ? 10 : 2), \                                   (((M)& 0x08) ? 11 : 3), \                                   (((M)& 0x10) ? 12 : 4), \                                   (((M)& 0x20) ? 13 : 5), \                                   (((M)& 0x40) ? 14 : 6), \                                   (((M)& 0x80) ? 15 : 7)); })
end_define

begin_comment
comment|/// \brief Merges 64-bit double-precision data values stored in either of the
end_comment

begin_comment
comment|///    two 256-bit vectors of [4 x double], as specified by the 256-bit vector
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
comment|/// This intrinsic corresponds to the \c VBLENDVPD / BLENDVPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double].
end_comment

begin_comment
comment|/// \param __c
end_comment

begin_comment
comment|///    A 256-bit vector operand, with mask bits 255, 191, 127, and 63 specifying
end_comment

begin_comment
comment|///    how the values are to be copied. The position of the mask bit corresponds
end_comment

begin_comment
comment|///    to the most significant bit of a copied value. When a mask bit is 0, the
end_comment

begin_comment
comment|///    corresponding 64-bit element in operand __a is copied to the same
end_comment

begin_comment
comment|///    position in the destination. When a mask bit is 1, the corresponding
end_comment

begin_comment
comment|///    64-bit element in operand __b is copied to the same position in the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the copied values.
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_blendv_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|,
name|__m256d
name|__c
parameter_list|)
block|{
return|return
operator|(
name|__m256d
operator|)
name|__builtin_ia32_blendvpd256
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
argument_list|,
operator|(
name|__v4df
operator|)
name|__b
argument_list|,
operator|(
name|__v4df
operator|)
name|__c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Merges 32-bit single-precision data values stored in either of the
end_comment

begin_comment
comment|///    two 256-bit vectors of [8 x float], as specified by the 256-bit vector
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
comment|/// This intrinsic corresponds to the \c VBLENDVPS / BLENDVPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float].
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float].
end_comment

begin_comment
comment|/// \param __c
end_comment

begin_comment
comment|///    A 256-bit vector operand, with mask bits 255, 223, 191, 159, 127, 95, 63,
end_comment

begin_comment
comment|///    and 31 specifying how the values are to be copied. The position of the
end_comment

begin_comment
comment|///    mask bit corresponds to the most significant bit of a copied value. When
end_comment

begin_comment
comment|///    a mask bit is 0, the corresponding 32-bit element in operand __a is
end_comment

begin_comment
comment|///    copied to the same position in the destination. When a mask bit is 1, the
end_comment

begin_comment
comment|///    corresponding 32-bit element in operand __b is copied to the same
end_comment

begin_comment
comment|///    position in the destination.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the copied values.
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_blendv_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256
name|__b
parameter_list|,
name|__m256
name|__c
parameter_list|)
block|{
return|return
operator|(
name|__m256
operator|)
name|__builtin_ia32_blendvps256
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|,
operator|(
name|__v8sf
operator|)
name|__b
argument_list|,
operator|(
name|__v8sf
operator|)
name|__c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Vector Dot Product */
end_comment

begin_comment
comment|/// \brief Computes two dot products in parallel, using the lower and upper
end_comment

begin_comment
comment|///    halves of two [8 x float] vectors as input to the two computations, and
end_comment

begin_comment
comment|///    returning the two dot products in the lower and upper halves of the
end_comment

begin_comment
comment|///    [8 x float] result. The immediate integer operand controls which
end_comment

begin_comment
comment|///    input elements will contribute to the dot product, and where the final
end_comment

begin_comment
comment|///    results are returned. In general, for each dot product, the four
end_comment

begin_comment
comment|///    corresponding elements of the input vectors are multiplied; the first
end_comment

begin_comment
comment|///    two and second two products are summed, then the two sums are added to
end_comment

begin_comment
comment|///    form the final result.
end_comment

begin_comment
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
comment|/// __m256 _mm256_dp_ps(__m256 V1, __m256 V2, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VDPPS / DPPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param V1
end_comment

begin_comment
comment|///    A vector of [8 x float] values, treated as two [4 x float] vectors.
end_comment

begin_comment
comment|/// \param V2
end_comment

begin_comment
comment|///    A vector of [8 x float] values, treated as two [4 x float] vectors.
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An immediate integer argument. Bits [7:4] determine which elements of
end_comment

begin_comment
comment|///    the input vectors are used, with bit [4] corresponding to the lowest
end_comment

begin_comment
comment|///    element and bit [7] corresponding to the highest element of each [4 x
end_comment

begin_comment
comment|///    float] subvector. If a bit is set, the corresponding elements from the
end_comment

begin_comment
comment|///    two input vectors are used as an input for dot product; otherwise that
end_comment

begin_comment
comment|///    input is treated as zero. Bits [3:0] determine which elements of the
end_comment

begin_comment
comment|///    result will receive a copy of the final dot product, with bit [0]
end_comment

begin_comment
comment|///    corresponding to the lowest element and bit [3] corresponding to the
end_comment

begin_comment
comment|///    highest element of each [4 x float] subvector. If a bit is set, the dot
end_comment

begin_comment
comment|///    product is returned in the corresponding element; otherwise that element
end_comment

begin_comment
comment|///    is set to zero. The bitmask is applied in the same way to each of the
end_comment

begin_comment
comment|///    two parallel dot product computations.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the two dot products.
end_comment

begin_define
define|#
directive|define
name|_mm256_dp_ps
parameter_list|(
name|V1
parameter_list|,
name|V2
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m256)__builtin_ia32_dpps256((__v8sf)(__m256)(V1), \                                  (__v8sf)(__m256)(V2), (M)); })
end_define

begin_comment
comment|/* Vector shuffle */
end_comment

begin_comment
comment|/// \brief Selects 8 float values from the 256-bit operands of [8 x float], as
end_comment

begin_comment
comment|///    specified by the immediate value operand. The four selected elements in
end_comment

begin_comment
comment|///    each operand are copied to the destination according to the bits
end_comment

begin_comment
comment|///    specified in the immediate operand. The selected elements from the first
end_comment

begin_comment
comment|///    256-bit operand are copied to bits [63:0] and bits [191:128] of the
end_comment

begin_comment
comment|///    destination, and the selected elements from the second 256-bit operand
end_comment

begin_comment
comment|///    are copied to bits [127:64] and bits [255:192] of the destination. For
end_comment

begin_comment
comment|///    example, if bits [7:0] of the immediate operand contain a value of 0xFF,
end_comment

begin_comment
comment|///    the 256-bit destination vector would contain the following values: b[7],
end_comment

begin_comment
comment|///    b[7], a[7], a[7], b[3], b[3], a[3], a[3].
end_comment

begin_comment
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
comment|/// __m256 _mm256_shuffle_ps(__m256 a, __m256 b, const int mask);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VSHUFPS / SHUFPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float]. The four selected elements in this
end_comment

begin_comment
comment|///    operand are copied to bits [63:0] and bits [191:128] in the destination,
end_comment

begin_comment
comment|///    according to the bits specified in the immediate operand.
end_comment

begin_comment
comment|/// \param b
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float]. The four selected elements in this
end_comment

begin_comment
comment|///    operand are copied to bits [127:64] and bits [255:192] in the
end_comment

begin_comment
comment|///    destination, according to the bits specified in the immediate operand.
end_comment

begin_comment
comment|/// \param mask
end_comment

begin_comment
comment|///    An immediate value containing an 8-bit value specifying which elements to
end_comment

begin_comment
comment|///    copy from a and b. Bits [3:0] specify the values copied from operand a.
end_comment

begin_comment
comment|///    Bits [7:4] specify the values copied from operand b.
end_comment

begin_comment
comment|///    The destinations within the 256-bit destination are assigned values as
end_comment

begin_comment
comment|///    follows, according to the bit value assignments described below:
end_comment

begin_comment
comment|///    Bits [1:0] are used to assign values to bits [31:0] and [159:128] in the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    Bits [3:2] are used to assign values to bits [63:32] and [191:160] in the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    Bits [5:4] are used to assign values to bits [95:64] and [223:192] in the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    Bits [7:6] are used to assign values to bits [127:96] and [255:224] in
end_comment

begin_comment
comment|///    the destination.
end_comment

begin_comment
comment|///    Bit value assignments:
end_comment

begin_comment
comment|///    00: Bits [31:0] and [159:128] are copied from the selected operand.
end_comment

begin_comment
comment|///    01: Bits [63:32] and [191:160] are copied from the selected operand.
end_comment

begin_comment
comment|///    10: Bits [95:64] and [223:192] are copied from the selected operand.
end_comment

begin_comment
comment|///    11: Bits [127:96] and [255:224] are copied from the selected operand.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the shuffled values.
end_comment

begin_define
define|#
directive|define
name|_mm256_shuffle_ps
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|mask
parameter_list|)
value|__extension__ ({ \   (__m256)__builtin_shufflevector((__v8sf)(__m256)(a), \                                   (__v8sf)(__m256)(b), \                                   0  + (((mask)>> 0)& 0x3), \                                   0  + (((mask)>> 2)& 0x3), \                                   8  + (((mask)>> 4)& 0x3), \                                   8  + (((mask)>> 6)& 0x3), \                                   4  + (((mask)>> 0)& 0x3), \                                   4  + (((mask)>> 2)& 0x3), \                                   12 + (((mask)>> 4)& 0x3), \                                   12 + (((mask)>> 6)& 0x3)); })
end_define

begin_comment
comment|/// \brief Selects four double-precision values from the 256-bit operands of
end_comment

begin_comment
comment|///    [4 x double], as specified by the immediate value operand. The selected
end_comment

begin_comment
comment|///    elements from the first 256-bit operand are copied to bits [63:0] and
end_comment

begin_comment
comment|///    bits [191:128] in the destination, and the selected elements from the
end_comment

begin_comment
comment|///    second 256-bit operand are copied to bits [127:64] and bits [255:192] in
end_comment

begin_comment
comment|///    the destination. For example, if bits [3:0] of the immediate operand
end_comment

begin_comment
comment|///    contain a value of 0xF, the 256-bit destination vector would contain the
end_comment

begin_comment
comment|///    following values: b[3], a[3], b[1], a[1].
end_comment

begin_comment
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
comment|/// __m256d _mm256_shuffle_pd(__m256d a, __m256d b, const int mask);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VSHUFPD / SHUFPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param a
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double].
end_comment

begin_comment
comment|/// \param b
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double].
end_comment

begin_comment
comment|/// \param mask
end_comment

begin_comment
comment|///    An immediate value containing 8-bit values specifying which elements to
end_comment

begin_comment
comment|///    copy from a and b:
end_comment

begin_comment
comment|///    Bit [0]=0: Bits [63:0] are copied from a to bits [63:0] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    Bit [0]=1: Bits [127:64] are copied from a to bits [63:0] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    Bit [1]=0: Bits [63:0] are copied from b to bits [127:64] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    Bit [1]=1: Bits [127:64] are copied from b to bits [127:64] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    Bit [2]=0: Bits [191:128] are copied from a to bits [191:128] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    Bit [2]=1: Bits [255:192] are copied from a to bits [191:128] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    Bit [3]=0: Bits [191:128] are copied from b to bits [255:192] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|///    Bit [3]=1: Bits [255:192] are copied from b to bits [255:192] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the shuffled values.
end_comment

begin_define
define|#
directive|define
name|_mm256_shuffle_pd
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|mask
parameter_list|)
value|__extension__ ({ \   (__m256d)__builtin_shufflevector((__v4df)(__m256d)(a), \                                    (__v4df)(__m256d)(b), \                                    0 + (((mask)>> 0)& 0x1), \                                    4 + (((mask)>> 1)& 0x1), \                                    2 + (((mask)>> 2)& 0x1), \                                    6 + (((mask)>> 3)& 0x1)); })
end_define

begin_comment
comment|/* Compare */
end_comment

begin_define
define|#
directive|define
name|_CMP_EQ_OQ
value|0x00
end_define

begin_comment
comment|/* Equal (ordered, non-signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_LT_OS
value|0x01
end_define

begin_comment
comment|/* Less-than (ordered, signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_LE_OS
value|0x02
end_define

begin_comment
comment|/* Less-than-or-equal (ordered, signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_UNORD_Q
value|0x03
end_define

begin_comment
comment|/* Unordered (non-signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_NEQ_UQ
value|0x04
end_define

begin_comment
comment|/* Not-equal (unordered, non-signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_NLT_US
value|0x05
end_define

begin_comment
comment|/* Not-less-than (unordered, signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_NLE_US
value|0x06
end_define

begin_comment
comment|/* Not-less-than-or-equal (unordered, signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_ORD_Q
value|0x07
end_define

begin_comment
comment|/* Ordered (nonsignaling)   */
end_comment

begin_define
define|#
directive|define
name|_CMP_EQ_UQ
value|0x08
end_define

begin_comment
comment|/* Equal (unordered, non-signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_NGE_US
value|0x09
end_define

begin_comment
comment|/* Not-greater-than-or-equal (unord, signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_NGT_US
value|0x0a
end_define

begin_comment
comment|/* Not-greater-than (unordered, signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_FALSE_OQ
value|0x0b
end_define

begin_comment
comment|/* False (ordered, non-signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_NEQ_OQ
value|0x0c
end_define

begin_comment
comment|/* Not-equal (ordered, non-signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_GE_OS
value|0x0d
end_define

begin_comment
comment|/* Greater-than-or-equal (ordered, signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_GT_OS
value|0x0e
end_define

begin_comment
comment|/* Greater-than (ordered, signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_TRUE_UQ
value|0x0f
end_define

begin_comment
comment|/* True (unordered, non-signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_EQ_OS
value|0x10
end_define

begin_comment
comment|/* Equal (ordered, signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_LT_OQ
value|0x11
end_define

begin_comment
comment|/* Less-than (ordered, non-signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_LE_OQ
value|0x12
end_define

begin_comment
comment|/* Less-than-or-equal (ordered, non-signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_UNORD_S
value|0x13
end_define

begin_comment
comment|/* Unordered (signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_NEQ_US
value|0x14
end_define

begin_comment
comment|/* Not-equal (unordered, signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_NLT_UQ
value|0x15
end_define

begin_comment
comment|/* Not-less-than (unordered, non-signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_NLE_UQ
value|0x16
end_define

begin_comment
comment|/* Not-less-than-or-equal (unord, non-signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_ORD_S
value|0x17
end_define

begin_comment
comment|/* Ordered (signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_EQ_US
value|0x18
end_define

begin_comment
comment|/* Equal (unordered, signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_NGE_UQ
value|0x19
end_define

begin_comment
comment|/* Not-greater-than-or-equal (unord, non-sign)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_NGT_UQ
value|0x1a
end_define

begin_comment
comment|/* Not-greater-than (unordered, non-signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_FALSE_OS
value|0x1b
end_define

begin_comment
comment|/* False (ordered, signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_NEQ_OS
value|0x1c
end_define

begin_comment
comment|/* Not-equal (ordered, signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_GE_OQ
value|0x1d
end_define

begin_comment
comment|/* Greater-than-or-equal (ordered, non-signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_GT_OQ
value|0x1e
end_define

begin_comment
comment|/* Greater-than (ordered, non-signaling)  */
end_comment

begin_define
define|#
directive|define
name|_CMP_TRUE_US
value|0x1f
end_define

begin_comment
comment|/* True (unordered, signaling)  */
end_comment

begin_comment
comment|/// \brief Compares each of the corresponding double-precision values of two
end_comment

begin_comment
comment|///    128-bit vectors of [2 x double], using the operation specified by the
end_comment

begin_comment
comment|///    immediate integer operand. Returns a [2 x double] vector consisting of
end_comment

begin_comment
comment|///    two doubles corresponding to the two comparison results: zero if the
end_comment

begin_comment
comment|///    comparison is false, and all 1's if the comparison is true.
end_comment

begin_comment
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
comment|/// __m128d _mm_cmp_pd(__m128d a, __m128d b, const int c);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VCMPPD / CMPPD instruction.
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
comment|/// \param c
end_comment

begin_comment
comment|///    An immediate integer operand, with bits [4:0] specifying which comparison
end_comment

begin_comment
comment|///    operation to use:
end_comment

begin_comment
comment|///    00h, 08h, 10h, 18h: Equal
end_comment

begin_comment
comment|///    01h, 09h, 11h, 19h: Less than
end_comment

begin_comment
comment|///    02h, 0Ah, 12h, 1Ah: Less than or equal / Greater than or equal (swapped
end_comment

begin_comment
comment|///                        operands)
end_comment

begin_comment
comment|///    03h, 0Bh, 13h, 1Bh: Unordered
end_comment

begin_comment
comment|///    04h, 0Ch, 14h, 1Ch: Not equal
end_comment

begin_comment
comment|///    05h, 0Dh, 15h, 1Dh: Not less than / Not greater than (swapped operands)
end_comment

begin_comment
comment|///    06h, 0Eh, 16h, 1Eh: Not less than or equal / Not greater than or equal
end_comment

begin_comment
comment|///                        (swapped operands)
end_comment

begin_comment
comment|///    07h, 0Fh, 17h, 1Fh: Ordered
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the comparison results.
end_comment

begin_define
define|#
directive|define
name|_mm_cmp_pd
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__extension__ ({ \   (__m128d)__builtin_ia32_cmppd((__v2df)(__m128d)(a), \                                 (__v2df)(__m128d)(b), (c)); })
end_define

begin_comment
comment|/// \brief Compares each of the corresponding values of two 128-bit vectors of
end_comment

begin_comment
comment|///    [4 x float], using the operation specified by the immediate integer
end_comment

begin_comment
comment|///    operand. Returns a [4 x float] vector consisting of four floats
end_comment

begin_comment
comment|///    corresponding to the four comparison results: zero if the comparison is
end_comment

begin_comment
comment|///    false, and all 1's if the comparison is true.
end_comment

begin_comment
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
comment|/// __m128 _mm_cmp_ps(__m128 a, __m128 b, const int c);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VCMPPS / CMPPS instruction.
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
comment|/// \param c
end_comment

begin_comment
comment|///    An immediate integer operand, with bits [4:0] specifying which comparison
end_comment

begin_comment
comment|///    operation to use:
end_comment

begin_comment
comment|///    00h, 08h, 10h, 18h: Equal
end_comment

begin_comment
comment|///    01h, 09h, 11h, 19h: Less than
end_comment

begin_comment
comment|///    02h, 0Ah, 12h, 1Ah: Less than or equal / Greater than or equal (swapped
end_comment

begin_comment
comment|///                        operands)
end_comment

begin_comment
comment|///    03h, 0Bh, 13h, 1Bh: Unordered
end_comment

begin_comment
comment|///    04h, 0Ch, 14h, 1Ch: Not equal
end_comment

begin_comment
comment|///    05h, 0Dh, 15h, 1Dh: Not less than / Not greater than (swapped operands)
end_comment

begin_comment
comment|///    06h, 0Eh, 16h, 1Eh: Not less than or equal / Not greater than or equal
end_comment

begin_comment
comment|///                       (swapped operands)
end_comment

begin_comment
comment|///    07h, 0Fh, 17h, 1Fh: Ordered
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results.
end_comment

begin_define
define|#
directive|define
name|_mm_cmp_ps
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__extension__ ({ \   (__m128)__builtin_ia32_cmpps((__v4sf)(__m128)(a), \                                (__v4sf)(__m128)(b), (c)); })
end_define

begin_comment
comment|/// \brief Compares each of the corresponding double-precision values of two
end_comment

begin_comment
comment|///    256-bit vectors of [4 x double], using the operation specified by the
end_comment

begin_comment
comment|///    immediate integer operand. Returns a [4 x double] vector consisting of
end_comment

begin_comment
comment|///    four doubles corresponding to the four comparison results: zero if the
end_comment

begin_comment
comment|///    comparison is false, and all 1's if the comparison is true.
end_comment

begin_comment
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
comment|/// __m256d _mm256_cmp_pd(__m256d a, __m256d b, const int c);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VCMPPD / CMPPD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param a
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double].
end_comment

begin_comment
comment|/// \param b
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double].
end_comment

begin_comment
comment|/// \param c
end_comment

begin_comment
comment|///    An immediate integer operand, with bits [4:0] specifying which comparison
end_comment

begin_comment
comment|///    operation to use:
end_comment

begin_comment
comment|///    00h, 08h, 10h, 18h: Equal
end_comment

begin_comment
comment|///    01h, 09h, 11h, 19h: Less than
end_comment

begin_comment
comment|///    02h, 0Ah, 12h, 1Ah: Less than or equal / Greater than or equal (swapped
end_comment

begin_comment
comment|///                        operands)
end_comment

begin_comment
comment|///    03h, 0Bh, 13h, 1Bh: Unordered
end_comment

begin_comment
comment|///    04h, 0Ch, 14h, 1Ch: Not equal
end_comment

begin_comment
comment|///    05h, 0Dh, 15h, 1Dh: Not less than / Not greater than (swapped operands)
end_comment

begin_comment
comment|///    06h, 0Eh, 16h, 1Eh: Not less than or equal / Not greater than or equal
end_comment

begin_comment
comment|///                        (swapped operands)
end_comment

begin_comment
comment|///    07h, 0Fh, 17h, 1Fh: Ordered
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the comparison results.
end_comment

begin_define
define|#
directive|define
name|_mm256_cmp_pd
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__extension__ ({ \   (__m256d)__builtin_ia32_cmppd256((__v4df)(__m256d)(a), \                                    (__v4df)(__m256d)(b), (c)); })
end_define

begin_comment
comment|/// \brief Compares each of the corresponding values of two 256-bit vectors of
end_comment

begin_comment
comment|///    [8 x float], using the operation specified by the immediate integer
end_comment

begin_comment
comment|///    operand. Returns a [8 x float] vector consisting of eight floats
end_comment

begin_comment
comment|///    corresponding to the eight comparison results: zero if the comparison is
end_comment

begin_comment
comment|///    false, and all 1's if the comparison is true.
end_comment

begin_comment
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
comment|/// __m256 _mm256_cmp_ps(__m256 a, __m256 b, const int c);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VCMPPS / CMPPS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float].
end_comment

begin_comment
comment|/// \param b
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float].
end_comment

begin_comment
comment|/// \param c
end_comment

begin_comment
comment|///    An immediate integer operand, with bits [4:0] specifying which comparison
end_comment

begin_comment
comment|///    operation to use:
end_comment

begin_comment
comment|///    00h, 08h, 10h, 18h: Equal
end_comment

begin_comment
comment|///    01h, 09h, 11h, 19h: Less than
end_comment

begin_comment
comment|///    02h, 0Ah, 12h, 1Ah: Less than or equal / Greater than or equal (swapped
end_comment

begin_comment
comment|///                        operands)
end_comment

begin_comment
comment|///    03h, 0Bh, 13h, 1Bh: Unordered
end_comment

begin_comment
comment|///    04h, 0Ch, 14h, 1Ch: Not equal
end_comment

begin_comment
comment|///    05h, 0Dh, 15h, 1Dh: Not less than / Not greater than (swapped operands)
end_comment

begin_comment
comment|///    06h, 0Eh, 16h, 1Eh: Not less than or equal / Not greater than or equal
end_comment

begin_comment
comment|///                       (swapped operands)
end_comment

begin_comment
comment|///    07h, 0Fh, 17h, 1Fh: Ordered
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the comparison results.
end_comment

begin_define
define|#
directive|define
name|_mm256_cmp_ps
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__extension__ ({ \   (__m256)__builtin_ia32_cmpps256((__v8sf)(__m256)(a), \                                   (__v8sf)(__m256)(b), (c)); })
end_define

begin_comment
comment|/// \brief Compares each of the corresponding scalar double-precision values of
end_comment

begin_comment
comment|///    two 128-bit vectors of [2 x double], using the operation specified by the
end_comment

begin_comment
comment|///    immediate integer operand. If the result is true, all 64 bits of the
end_comment

begin_comment
comment|///    destination vector are set; otherwise they are cleared.
end_comment

begin_comment
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
comment|/// __m128d _mm_cmp_sd(__m128d a, __m128d b, const int c);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VCMPSD / CMPSD instruction.
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
comment|/// \param c
end_comment

begin_comment
comment|///    An immediate integer operand, with bits [4:0] specifying which comparison
end_comment

begin_comment
comment|///    operation to use:
end_comment

begin_comment
comment|///    00h, 08h, 10h, 18h: Equal
end_comment

begin_comment
comment|///    01h, 09h, 11h, 19h: Less than
end_comment

begin_comment
comment|///    02h, 0Ah, 12h, 1Ah: Less than or equal / Greater than or equal (swapped
end_comment

begin_comment
comment|///                        operands)
end_comment

begin_comment
comment|///    03h, 0Bh, 13h, 1Bh: Unordered
end_comment

begin_comment
comment|///    04h, 0Ch, 14h, 1Ch: Not equal
end_comment

begin_comment
comment|///    05h, 0Dh, 15h, 1Dh: Not less than / Not greater than (swapped operands)
end_comment

begin_comment
comment|///    06h, 0Eh, 16h, 1Eh: Not less than or equal / Not greater than or equal
end_comment

begin_comment
comment|///                       (swapped operands)
end_comment

begin_comment
comment|///    07h, 0Fh, 17h, 1Fh: Ordered
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the comparison results.
end_comment

begin_define
define|#
directive|define
name|_mm_cmp_sd
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__extension__ ({ \   (__m128d)__builtin_ia32_cmpsd((__v2df)(__m128d)(a), \                                 (__v2df)(__m128d)(b), (c)); })
end_define

begin_comment
comment|/// \brief Compares each of the corresponding scalar values of two 128-bit
end_comment

begin_comment
comment|///    vectors of [4 x float], using the operation specified by the immediate
end_comment

begin_comment
comment|///    integer operand. If the result is true, all 32 bits of the destination
end_comment

begin_comment
comment|///    vector are set; otherwise they are cleared.
end_comment

begin_comment
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
comment|/// __m128 _mm_cmp_ss(__m128 a, __m128 b, const int c);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VCMPSS / CMPSS instruction.
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
comment|/// \param c
end_comment

begin_comment
comment|///    An immediate integer operand, with bits [4:0] specifying which comparison
end_comment

begin_comment
comment|///    operation to use:
end_comment

begin_comment
comment|///    00h, 08h, 10h, 18h: Equal
end_comment

begin_comment
comment|///    01h, 09h, 11h, 19h: Less than
end_comment

begin_comment
comment|///    02h, 0Ah, 12h, 1Ah: Less than or equal / Greater than or equal (swapped
end_comment

begin_comment
comment|///                        operands)
end_comment

begin_comment
comment|///    03h, 0Bh, 13h, 1Bh: Unordered
end_comment

begin_comment
comment|///    04h, 0Ch, 14h, 1Ch: Not equal
end_comment

begin_comment
comment|///    05h, 0Dh, 15h, 1Dh: Not less than / Not greater than (swapped operands)
end_comment

begin_comment
comment|///    06h, 0Eh, 16h, 1Eh: Not less than or equal / Not greater than or equal
end_comment

begin_comment
comment|///                       (swapped operands)
end_comment

begin_comment
comment|///    07h, 0Fh, 17h, 1Fh: Ordered
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the comparison results.
end_comment

begin_define
define|#
directive|define
name|_mm_cmp_ss
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__extension__ ({ \   (__m128)__builtin_ia32_cmpss((__v4sf)(__m128)(a), \                                (__v4sf)(__m128)(b), (c)); })
end_define

begin_comment
comment|/// \brief Takes a [8 x i32] vector and returns the vector element value
end_comment

begin_comment
comment|///    indexed by the immediate constant operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VEXTRACTF128+COMPOSITE /
end_comment

begin_comment
comment|///   EXTRACTF128+COMPOSITE instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x i32].
end_comment

begin_comment
comment|/// \param __imm
end_comment

begin_comment
comment|///    An immediate integer operand with bits [2:0] determining which vector
end_comment

begin_comment
comment|///    element is extracted and returned.
end_comment

begin_comment
comment|/// \returns A 32-bit integer containing the extracted 32 bits of extended
end_comment

begin_comment
comment|///    packed data.
end_comment

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm256_extract_epi32
parameter_list|(
name|__m256i
name|__a
parameter_list|,
specifier|const
name|int
name|__imm
parameter_list|)
block|{
name|__v8si
name|__b
init|=
operator|(
name|__v8si
operator|)
name|__a
decl_stmt|;
return|return
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
comment|/// \brief Takes a [16 x i16] vector and returns the vector element value
end_comment

begin_comment
comment|///    indexed by the immediate constant operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VEXTRACTF128+COMPOSITE /
end_comment

begin_comment
comment|///    EXTRACTF128+COMPOSITE instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit integer vector of [16 x i16].
end_comment

begin_comment
comment|/// \param __imm
end_comment

begin_comment
comment|///    An immediate integer operand with bits [3:0] determining which vector
end_comment

begin_comment
comment|///    element is extracted and returned.
end_comment

begin_comment
comment|/// \returns A 32-bit integer containing the extracted 16 bits of zero extended
end_comment

begin_comment
comment|///    packed data.
end_comment

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm256_extract_epi16
parameter_list|(
name|__m256i
name|__a
parameter_list|,
specifier|const
name|int
name|__imm
parameter_list|)
block|{
name|__v16hi
name|__b
init|=
operator|(
name|__v16hi
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
literal|15
index|]
return|;
block|}
end_function

begin_comment
comment|/// \brief Takes a [32 x i8] vector and returns the vector element value
end_comment

begin_comment
comment|///    indexed by the immediate constant operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VEXTRACTF128+COMPOSITE /
end_comment

begin_comment
comment|///    EXTRACTF128+COMPOSITE instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit integer vector of [32 x i8].
end_comment

begin_comment
comment|/// \param __imm
end_comment

begin_comment
comment|///    An immediate integer operand with bits [4:0] determining which vector
end_comment

begin_comment
comment|///    element is extracted and returned.
end_comment

begin_comment
comment|/// \returns A 32-bit integer containing the extracted 8 bits of zero extended
end_comment

begin_comment
comment|///    packed data.
end_comment

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm256_extract_epi8
parameter_list|(
name|__m256i
name|__a
parameter_list|,
specifier|const
name|int
name|__imm
parameter_list|)
block|{
name|__v32qi
name|__b
init|=
operator|(
name|__v32qi
operator|)
name|__a
decl_stmt|;
return|return
operator|(
name|unsigned
name|char
operator|)
name|__b
index|[
name|__imm
operator|&
literal|31
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
comment|/// \brief Takes a [4 x i64] vector and returns the vector element value
end_comment

begin_comment
comment|///    indexed by the immediate constant operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VEXTRACTF128+COMPOSITE /
end_comment

begin_comment
comment|///    EXTRACTF128+COMPOSITE instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit integer vector of [4 x i64].
end_comment

begin_comment
comment|/// \param __imm
end_comment

begin_comment
comment|///    An immediate integer operand with bits [1:0] determining which vector
end_comment

begin_comment
comment|///    element is extracted and returned.
end_comment

begin_comment
comment|/// \returns A 64-bit integer containing the extracted 64 bits of extended
end_comment

begin_comment
comment|///    packed data.
end_comment

begin_function
specifier|static
name|__inline
name|long
name|long
name|__DEFAULT_FN_ATTRS
name|_mm256_extract_epi64
parameter_list|(
name|__m256i
name|__a
parameter_list|,
specifier|const
name|int
name|__imm
parameter_list|)
block|{
name|__v4di
name|__b
init|=
operator|(
name|__v4di
operator|)
name|__a
decl_stmt|;
return|return
name|__b
index|[
name|__imm
operator|&
literal|3
index|]
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \brief Takes a [8 x i32] vector and replaces the vector element value
end_comment

begin_comment
comment|///    indexed by the immediate constant operand by a new value. Returns the
end_comment

begin_comment
comment|///    modified vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VINSERTF128+COMPOSITE /
end_comment

begin_comment
comment|///    INSERTF128+COMPOSITE instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A vector of [8 x i32] to be used by the insert operation.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    An integer value. The replacement value for the insert operation.
end_comment

begin_comment
comment|/// \param __imm
end_comment

begin_comment
comment|///    An immediate integer specifying the index of the vector element to be
end_comment

begin_comment
comment|///    replaced.
end_comment

begin_comment
comment|/// \returns A copy of vector __a, after replacing its element indexed by __imm
end_comment

begin_comment
comment|///     with __b.
end_comment

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_insert_epi32
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|int
name|__b
parameter_list|,
name|int
specifier|const
name|__imm
parameter_list|)
block|{
name|__v8si
name|__c
init|=
operator|(
name|__v8si
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
name|__m256i
operator|)
name|__c
return|;
block|}
end_function

begin_comment
comment|/// \brief Takes a [16 x i16] vector and replaces the vector element value
end_comment

begin_comment
comment|///    indexed by the immediate constant operand with a new value. Returns the
end_comment

begin_comment
comment|///    modified vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VINSERTF128+COMPOSITE /
end_comment

begin_comment
comment|///    INSERTF128+COMPOSITE instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A vector of [16 x i16] to be used by the insert operation.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    An i16 integer value. The replacement value for the insert operation.
end_comment

begin_comment
comment|/// \param __imm
end_comment

begin_comment
comment|///    An immediate integer specifying the index of the vector element to be
end_comment

begin_comment
comment|///    replaced.
end_comment

begin_comment
comment|/// \returns A copy of vector __a, after replacing its element indexed by __imm
end_comment

begin_comment
comment|///     with __b.
end_comment

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_insert_epi16
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|int
name|__b
parameter_list|,
name|int
specifier|const
name|__imm
parameter_list|)
block|{
name|__v16hi
name|__c
init|=
operator|(
name|__v16hi
operator|)
name|__a
decl_stmt|;
name|__c
index|[
name|__imm
operator|&
literal|15
index|]
operator|=
name|__b
expr_stmt|;
return|return
operator|(
name|__m256i
operator|)
name|__c
return|;
block|}
end_function

begin_comment
comment|/// \brief Takes a [32 x i8] vector and replaces the vector element value
end_comment

begin_comment
comment|///    indexed by the immediate constant operand with a new value. Returns the
end_comment

begin_comment
comment|///    modified vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VINSERTF128+COMPOSITE /
end_comment

begin_comment
comment|///    INSERTF128+COMPOSITE instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A vector of [32 x i8] to be used by the insert operation.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    An i8 integer value. The replacement value for the insert operation.
end_comment

begin_comment
comment|/// \param __imm
end_comment

begin_comment
comment|///    An immediate integer specifying the index of the vector element to be
end_comment

begin_comment
comment|///    replaced.
end_comment

begin_comment
comment|/// \returns A copy of vector __a, after replacing its element indexed by __imm
end_comment

begin_comment
comment|///    with __b.
end_comment

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_insert_epi8
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|int
name|__b
parameter_list|,
name|int
specifier|const
name|__imm
parameter_list|)
block|{
name|__v32qi
name|__c
init|=
operator|(
name|__v32qi
operator|)
name|__a
decl_stmt|;
name|__c
index|[
name|__imm
operator|&
literal|31
index|]
operator|=
name|__b
expr_stmt|;
return|return
operator|(
name|__m256i
operator|)
name|__c
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_comment
comment|/// \brief Takes a [4 x i64] vector and replaces the vector element value
end_comment

begin_comment
comment|///    indexed by the immediate constant operand with a new value. Returns the
end_comment

begin_comment
comment|///    modified vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VINSERTF128+COMPOSITE /
end_comment

begin_comment
comment|///    INSERTF128+COMPOSITE instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A vector of [4 x i64] to be used by the insert operation.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit integer value. The replacement value for the insert operation.
end_comment

begin_comment
comment|/// \param __imm
end_comment

begin_comment
comment|///    An immediate integer specifying the index of the vector element to be
end_comment

begin_comment
comment|///    replaced.
end_comment

begin_comment
comment|/// \returns A copy of vector __a, after replacing its element indexed by __imm
end_comment

begin_comment
comment|///     with __b.
end_comment

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_insert_epi64
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|long
name|long
name|__b
parameter_list|,
name|int
specifier|const
name|__imm
parameter_list|)
block|{
name|__v4di
name|__c
init|=
operator|(
name|__v4di
operator|)
name|__a
decl_stmt|;
name|__c
index|[
name|__imm
operator|&
literal|3
index|]
operator|=
name|__b
expr_stmt|;
return|return
operator|(
name|__m256i
operator|)
name|__c
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Conversion */
end_comment

begin_comment
comment|/// \brief Converts a vector of [4 x i32] into a vector of [4 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VCVTDQ2PD / CVTDQ2PD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector of [4 x i32].
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [4 x double] containing the converted values.
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_cvtepi32_pd
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m256d
operator|)
name|__builtin_convertvector
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
name|__v4df
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts a vector of [8 x i32] into a vector of [8 x float].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VCVTDQ2PS / CVTDQ2PS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 256-bit vector of [8 x float] containing the converted values.
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_cvtepi32_ps
parameter_list|(
name|__m256i
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m256
operator|)
name|__builtin_ia32_cvtdq2ps256
argument_list|(
operator|(
name|__v8si
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts a 256-bit vector of [4 x double] into a 128-bit vector of
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
comment|/// This intrinsic corresponds to the \c VCVTPD2PS / CVTPD2PS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [4 x double].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the converted values.
end_comment

begin_function
specifier|static
name|__inline
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm256_cvtpd_ps
parameter_list|(
name|__m256d
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cvtpd2ps256
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts a vector of [8 x float] into a vector of [8 x i32].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VCVTPS2DQ / CVTPS2DQ instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 256-bit vector of [8 x float].
end_comment

begin_comment
comment|/// \returns A 256-bit integer vector containing the converted values.
end_comment

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_cvtps_epi32
parameter_list|(
name|__m256
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
name|__builtin_ia32_cvtps2dq256
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_cvtps_pd
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m256d
operator|)
name|__builtin_convertvector
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
name|__v4df
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm256_cvttpd_epi32
parameter_list|(
name|__m256d
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_cvttpd2dq256
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm256_cvtpd_epi32
parameter_list|(
name|__m256d
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_cvtpd2dq256
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_cvttps_epi32
parameter_list|(
name|__m256
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
name|__builtin_ia32_cvttps2dq256
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|double
name|__DEFAULT_FN_ATTRS
name|_mm256_cvtsd_f64
parameter_list|(
name|__m256d
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

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm256_cvtsi256_si32
parameter_list|(
name|__m256i
name|__a
parameter_list|)
block|{
name|__v8si
name|__b
init|=
operator|(
name|__v8si
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

begin_function
specifier|static
name|__inline
name|float
name|__DEFAULT_FN_ATTRS
name|_mm256_cvtss_f32
parameter_list|(
name|__m256
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
comment|/* Vector replicate */
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_movehdup_ps
parameter_list|(
name|__m256
name|__a
parameter_list|)
block|{
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|,
operator|(
name|__v8sf
operator|)
name|__a
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|,
literal|7
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_moveldup_ps
parameter_list|(
name|__m256
name|__a
parameter_list|)
block|{
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|,
operator|(
name|__v8sf
operator|)
name|__a
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|,
literal|6
argument_list|,
literal|6
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_movedup_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|)
block|{
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
argument_list|,
operator|(
name|__v4df
operator|)
name|__a
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Unpack and Interleave */
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_unpackhi_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
argument_list|,
operator|(
name|__v4df
operator|)
name|__b
argument_list|,
literal|1
argument_list|,
literal|5
argument_list|,
literal|1
operator|+
literal|2
argument_list|,
literal|5
operator|+
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_unpacklo_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
argument_list|,
operator|(
name|__v4df
operator|)
name|__b
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
operator|+
literal|2
argument_list|,
literal|4
operator|+
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_unpackhi_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256
name|__b
parameter_list|)
block|{
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|,
operator|(
name|__v8sf
operator|)
name|__b
argument_list|,
literal|2
argument_list|,
literal|10
argument_list|,
literal|2
operator|+
literal|1
argument_list|,
literal|10
operator|+
literal|1
argument_list|,
literal|6
argument_list|,
literal|14
argument_list|,
literal|6
operator|+
literal|1
argument_list|,
literal|14
operator|+
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_unpacklo_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256
name|__b
parameter_list|)
block|{
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|,
operator|(
name|__v8sf
operator|)
name|__b
argument_list|,
literal|0
argument_list|,
literal|8
argument_list|,
literal|0
operator|+
literal|1
argument_list|,
literal|8
operator|+
literal|1
argument_list|,
literal|4
argument_list|,
literal|12
argument_list|,
literal|4
operator|+
literal|1
argument_list|,
literal|12
operator|+
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Bit Test */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_testz_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_vtestzpd
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

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_testc_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_vtestcpd
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

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_testnzc_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_vtestnzcpd
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

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_testz_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_vtestzps
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

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_testc_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_vtestcps
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

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_testnzc_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_vtestnzcps
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

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm256_testz_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_vtestzpd256
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
argument_list|,
operator|(
name|__v4df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm256_testc_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_vtestcpd256
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
argument_list|,
operator|(
name|__v4df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm256_testnzc_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_vtestnzcpd256
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
argument_list|,
operator|(
name|__v4df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm256_testz_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_vtestzps256
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|,
operator|(
name|__v8sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm256_testc_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_vtestcps256
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|,
operator|(
name|__v8sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm256_testnzc_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_vtestnzcps256
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|,
operator|(
name|__v8sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm256_testz_si256
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ptestz256
argument_list|(
operator|(
name|__v4di
operator|)
name|__a
argument_list|,
operator|(
name|__v4di
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm256_testc_si256
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ptestc256
argument_list|(
operator|(
name|__v4di
operator|)
name|__a
argument_list|,
operator|(
name|__v4di
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm256_testnzc_si256
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ptestnzc256
argument_list|(
operator|(
name|__v4di
operator|)
name|__a
argument_list|,
operator|(
name|__v4di
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Vector extract sign mask */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm256_movemask_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_movmskpd256
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|__DEFAULT_FN_ATTRS
name|_mm256_movemask_ps
parameter_list|(
name|__m256
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_movmskps256
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Vector __zero */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|__DEFAULT_FN_ATTRS
name|_mm256_zeroall
parameter_list|(
name|void
parameter_list|)
block|{
name|__builtin_ia32_vzeroall
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__DEFAULT_FN_ATTRS
name|_mm256_zeroupper
parameter_list|(
name|void
parameter_list|)
block|{
name|__builtin_ia32_vzeroupper
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Vector load with broadcast */
end_comment

begin_function
specifier|static
name|__inline
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_broadcast_ss
parameter_list|(
name|float
specifier|const
modifier|*
name|__a
parameter_list|)
block|{
name|float
name|__f
init|=
operator|*
name|__a
decl_stmt|;
return|return
operator|(
name|__m128
operator|)
operator|(
name|__v4sf
operator|)
block|{
name|__f
block|,
name|__f
block|,
name|__f
block|,
name|__f
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_broadcast_sd
parameter_list|(
name|double
specifier|const
modifier|*
name|__a
parameter_list|)
block|{
name|double
name|__d
init|=
operator|*
name|__a
decl_stmt|;
return|return
operator|(
name|__m256d
operator|)
operator|(
name|__v4df
operator|)
block|{
name|__d
block|,
name|__d
block|,
name|__d
block|,
name|__d
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_broadcast_ss
parameter_list|(
name|float
specifier|const
modifier|*
name|__a
parameter_list|)
block|{
name|float
name|__f
init|=
operator|*
name|__a
decl_stmt|;
return|return
operator|(
name|__m256
operator|)
operator|(
name|__v8sf
operator|)
block|{
name|__f
block|,
name|__f
block|,
name|__f
block|,
name|__f
block|,
name|__f
block|,
name|__f
block|,
name|__f
block|,
name|__f
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_broadcast_pd
parameter_list|(
name|__m128d
specifier|const
modifier|*
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m256d
operator|)
name|__builtin_ia32_vbroadcastf128_pd256
argument_list|(
operator|(
name|__v2df
specifier|const
operator|*
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_broadcast_ps
parameter_list|(
name|__m128
specifier|const
modifier|*
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m256
operator|)
name|__builtin_ia32_vbroadcastf128_ps256
argument_list|(
operator|(
name|__v4sf
specifier|const
operator|*
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* SIMD load ops */
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_load_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|__p
parameter_list|)
block|{
return|return
operator|*
operator|(
name|__m256d
operator|*
operator|)
name|__p
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_load_ps
parameter_list|(
name|float
specifier|const
modifier|*
name|__p
parameter_list|)
block|{
return|return
operator|*
operator|(
name|__m256
operator|*
operator|)
name|__p
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_loadu_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|__p
parameter_list|)
block|{
struct|struct
name|__loadu_pd
block|{
name|__m256d
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
name|__p
operator|)
operator|->
name|__v
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_loadu_ps
parameter_list|(
name|float
specifier|const
modifier|*
name|__p
parameter_list|)
block|{
struct|struct
name|__loadu_ps
block|{
name|__m256
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

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_load_si256
parameter_list|(
name|__m256i
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

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_loadu_si256
parameter_list|(
name|__m256i
specifier|const
modifier|*
name|__p
parameter_list|)
block|{
struct|struct
name|__loadu_si256
block|{
name|__m256i
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
name|__loadu_si256
operator|*
operator|)
name|__p
operator|)
operator|->
name|__v
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_lddqu_si256
parameter_list|(
name|__m256i
specifier|const
modifier|*
name|__p
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
name|__builtin_ia32_lddqu256
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
name|__p
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* SIMD store ops */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|__DEFAULT_FN_ATTRS
name|_mm256_store_pd
parameter_list|(
name|double
modifier|*
name|__p
parameter_list|,
name|__m256d
name|__a
parameter_list|)
block|{
operator|*
operator|(
name|__m256d
operator|*
operator|)
name|__p
operator|=
name|__a
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__DEFAULT_FN_ATTRS
name|_mm256_store_ps
parameter_list|(
name|float
modifier|*
name|__p
parameter_list|,
name|__m256
name|__a
parameter_list|)
block|{
operator|*
operator|(
name|__m256
operator|*
operator|)
name|__p
operator|=
name|__a
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__DEFAULT_FN_ATTRS
name|_mm256_storeu_pd
parameter_list|(
name|double
modifier|*
name|__p
parameter_list|,
name|__m256d
name|__a
parameter_list|)
block|{
struct|struct
name|__storeu_pd
block|{
name|__m256d
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
name|__p
operator|)
operator|->
name|__v
operator|=
name|__a
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__DEFAULT_FN_ATTRS
name|_mm256_storeu_ps
parameter_list|(
name|float
modifier|*
name|__p
parameter_list|,
name|__m256
name|__a
parameter_list|)
block|{
struct|struct
name|__storeu_ps
block|{
name|__m256
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

begin_function
specifier|static
name|__inline
name|void
name|__DEFAULT_FN_ATTRS
name|_mm256_store_si256
parameter_list|(
name|__m256i
modifier|*
name|__p
parameter_list|,
name|__m256i
name|__a
parameter_list|)
block|{
operator|*
name|__p
operator|=
name|__a
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__DEFAULT_FN_ATTRS
name|_mm256_storeu_si256
parameter_list|(
name|__m256i
modifier|*
name|__p
parameter_list|,
name|__m256i
name|__a
parameter_list|)
block|{
struct|struct
name|__storeu_si256
block|{
name|__m256i
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
name|__storeu_si256
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
comment|/* Conditional load ops */
end_comment

begin_function
specifier|static
name|__inline
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_maskload_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|__p
parameter_list|,
name|__m128i
name|__m
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_maskloadpd
argument_list|(
operator|(
specifier|const
name|__v2df
operator|*
operator|)
name|__p
argument_list|,
operator|(
name|__v2di
operator|)
name|__m
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_maskload_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|__p
parameter_list|,
name|__m256i
name|__m
parameter_list|)
block|{
return|return
operator|(
name|__m256d
operator|)
name|__builtin_ia32_maskloadpd256
argument_list|(
operator|(
specifier|const
name|__v4df
operator|*
operator|)
name|__p
argument_list|,
operator|(
name|__v4di
operator|)
name|__m
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_maskload_ps
parameter_list|(
name|float
specifier|const
modifier|*
name|__p
parameter_list|,
name|__m128i
name|__m
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_maskloadps
argument_list|(
operator|(
specifier|const
name|__v4sf
operator|*
operator|)
name|__p
argument_list|,
operator|(
name|__v4si
operator|)
name|__m
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_maskload_ps
parameter_list|(
name|float
specifier|const
modifier|*
name|__p
parameter_list|,
name|__m256i
name|__m
parameter_list|)
block|{
return|return
operator|(
name|__m256
operator|)
name|__builtin_ia32_maskloadps256
argument_list|(
operator|(
specifier|const
name|__v8sf
operator|*
operator|)
name|__p
argument_list|,
operator|(
name|__v8si
operator|)
name|__m
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Conditional store ops */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|__DEFAULT_FN_ATTRS
name|_mm256_maskstore_ps
parameter_list|(
name|float
modifier|*
name|__p
parameter_list|,
name|__m256i
name|__m
parameter_list|,
name|__m256
name|__a
parameter_list|)
block|{
name|__builtin_ia32_maskstoreps256
argument_list|(
operator|(
name|__v8sf
operator|*
operator|)
name|__p
argument_list|,
operator|(
name|__v8si
operator|)
name|__m
argument_list|,
operator|(
name|__v8sf
operator|)
name|__a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_maskstore_pd
parameter_list|(
name|double
modifier|*
name|__p
parameter_list|,
name|__m128i
name|__m
parameter_list|,
name|__m128d
name|__a
parameter_list|)
block|{
name|__builtin_ia32_maskstorepd
argument_list|(
operator|(
name|__v2df
operator|*
operator|)
name|__p
argument_list|,
operator|(
name|__v2di
operator|)
name|__m
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__DEFAULT_FN_ATTRS
name|_mm256_maskstore_pd
parameter_list|(
name|double
modifier|*
name|__p
parameter_list|,
name|__m256i
name|__m
parameter_list|,
name|__m256d
name|__a
parameter_list|)
block|{
name|__builtin_ia32_maskstorepd256
argument_list|(
operator|(
name|__v4df
operator|*
operator|)
name|__p
argument_list|,
operator|(
name|__v4di
operator|)
name|__m
argument_list|,
operator|(
name|__v4df
operator|)
name|__a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_maskstore_ps
parameter_list|(
name|float
modifier|*
name|__p
parameter_list|,
name|__m128i
name|__m
parameter_list|,
name|__m128
name|__a
parameter_list|)
block|{
name|__builtin_ia32_maskstoreps
argument_list|(
operator|(
name|__v4sf
operator|*
operator|)
name|__p
argument_list|,
operator|(
name|__v4si
operator|)
name|__m
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
comment|/* Cacheability support ops */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|__DEFAULT_FN_ATTRS
name|_mm256_stream_si256
parameter_list|(
name|__m256i
modifier|*
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
name|__builtin_nontemporal_store
argument_list|(
operator|(
name|__v4di
operator|)
name|__b
argument_list|,
operator|(
name|__v4di
operator|*
operator|)
name|__a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__DEFAULT_FN_ATTRS
name|_mm256_stream_pd
parameter_list|(
name|double
modifier|*
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|)
block|{
name|__builtin_nontemporal_store
argument_list|(
operator|(
name|__v4df
operator|)
name|__b
argument_list|,
operator|(
name|__v4df
operator|*
operator|)
name|__a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__DEFAULT_FN_ATTRS
name|_mm256_stream_ps
parameter_list|(
name|float
modifier|*
name|__p
parameter_list|,
name|__m256
name|__a
parameter_list|)
block|{
name|__builtin_nontemporal_store
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|,
operator|(
name|__v8sf
operator|*
operator|)
name|__p
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Create vectors */
end_comment

begin_function
specifier|static
name|__inline__
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_undefined_pd
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|__m256d
operator|)
name|__builtin_ia32_undef256
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_undefined_ps
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|__m256
operator|)
name|__builtin_ia32_undef256
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_undefined_si256
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
name|__builtin_ia32_undef256
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_set_pd
parameter_list|(
name|double
name|__a
parameter_list|,
name|double
name|__b
parameter_list|,
name|double
name|__c
parameter_list|,
name|double
name|__d
parameter_list|)
block|{
return|return
operator|(
name|__m256d
operator|)
block|{
name|__d
block|,
name|__c
block|,
name|__b
block|,
name|__a
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_set_ps
parameter_list|(
name|float
name|__a
parameter_list|,
name|float
name|__b
parameter_list|,
name|float
name|__c
parameter_list|,
name|float
name|__d
parameter_list|,
name|float
name|__e
parameter_list|,
name|float
name|__f
parameter_list|,
name|float
name|__g
parameter_list|,
name|float
name|__h
parameter_list|)
block|{
return|return
operator|(
name|__m256
operator|)
block|{
name|__h
block|,
name|__g
block|,
name|__f
block|,
name|__e
block|,
name|__d
block|,
name|__c
block|,
name|__b
block|,
name|__a
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_set_epi32
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
parameter_list|,
name|int
name|__i4
parameter_list|,
name|int
name|__i5
parameter_list|,
name|int
name|__i6
parameter_list|,
name|int
name|__i7
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
operator|(
name|__v8si
operator|)
block|{
name|__i7
block|,
name|__i6
block|,
name|__i5
block|,
name|__i4
block|,
name|__i3
block|,
name|__i2
block|,
name|__i1
block|,
name|__i0
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_set_epi16
parameter_list|(
name|short
name|__w15
parameter_list|,
name|short
name|__w14
parameter_list|,
name|short
name|__w13
parameter_list|,
name|short
name|__w12
parameter_list|,
name|short
name|__w11
parameter_list|,
name|short
name|__w10
parameter_list|,
name|short
name|__w09
parameter_list|,
name|short
name|__w08
parameter_list|,
name|short
name|__w07
parameter_list|,
name|short
name|__w06
parameter_list|,
name|short
name|__w05
parameter_list|,
name|short
name|__w04
parameter_list|,
name|short
name|__w03
parameter_list|,
name|short
name|__w02
parameter_list|,
name|short
name|__w01
parameter_list|,
name|short
name|__w00
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
operator|(
name|__v16hi
operator|)
block|{
name|__w00
block|,
name|__w01
block|,
name|__w02
block|,
name|__w03
block|,
name|__w04
block|,
name|__w05
block|,
name|__w06
block|,
name|__w07
block|,
name|__w08
block|,
name|__w09
block|,
name|__w10
block|,
name|__w11
block|,
name|__w12
block|,
name|__w13
block|,
name|__w14
block|,
name|__w15
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_set_epi8
parameter_list|(
name|char
name|__b31
parameter_list|,
name|char
name|__b30
parameter_list|,
name|char
name|__b29
parameter_list|,
name|char
name|__b28
parameter_list|,
name|char
name|__b27
parameter_list|,
name|char
name|__b26
parameter_list|,
name|char
name|__b25
parameter_list|,
name|char
name|__b24
parameter_list|,
name|char
name|__b23
parameter_list|,
name|char
name|__b22
parameter_list|,
name|char
name|__b21
parameter_list|,
name|char
name|__b20
parameter_list|,
name|char
name|__b19
parameter_list|,
name|char
name|__b18
parameter_list|,
name|char
name|__b17
parameter_list|,
name|char
name|__b16
parameter_list|,
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
name|__b09
parameter_list|,
name|char
name|__b08
parameter_list|,
name|char
name|__b07
parameter_list|,
name|char
name|__b06
parameter_list|,
name|char
name|__b05
parameter_list|,
name|char
name|__b04
parameter_list|,
name|char
name|__b03
parameter_list|,
name|char
name|__b02
parameter_list|,
name|char
name|__b01
parameter_list|,
name|char
name|__b00
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
operator|(
name|__v32qi
operator|)
block|{
name|__b00
block|,
name|__b01
block|,
name|__b02
block|,
name|__b03
block|,
name|__b04
block|,
name|__b05
block|,
name|__b06
block|,
name|__b07
block|,
name|__b08
block|,
name|__b09
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
block|,
name|__b16
block|,
name|__b17
block|,
name|__b18
block|,
name|__b19
block|,
name|__b20
block|,
name|__b21
block|,
name|__b22
block|,
name|__b23
block|,
name|__b24
block|,
name|__b25
block|,
name|__b26
block|,
name|__b27
block|,
name|__b28
block|,
name|__b29
block|,
name|__b30
block|,
name|__b31
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_set_epi64x
parameter_list|(
name|long
name|long
name|__a
parameter_list|,
name|long
name|long
name|__b
parameter_list|,
name|long
name|long
name|__c
parameter_list|,
name|long
name|long
name|__d
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
operator|(
name|__v4di
operator|)
block|{
name|__d
block|,
name|__c
block|,
name|__b
block|,
name|__a
block|}
return|;
block|}
end_function

begin_comment
comment|/* Create vectors with elements in reverse order */
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_setr_pd
parameter_list|(
name|double
name|__a
parameter_list|,
name|double
name|__b
parameter_list|,
name|double
name|__c
parameter_list|,
name|double
name|__d
parameter_list|)
block|{
return|return
operator|(
name|__m256d
operator|)
block|{
name|__a
block|,
name|__b
block|,
name|__c
block|,
name|__d
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_setr_ps
parameter_list|(
name|float
name|__a
parameter_list|,
name|float
name|__b
parameter_list|,
name|float
name|__c
parameter_list|,
name|float
name|__d
parameter_list|,
name|float
name|__e
parameter_list|,
name|float
name|__f
parameter_list|,
name|float
name|__g
parameter_list|,
name|float
name|__h
parameter_list|)
block|{
return|return
operator|(
name|__m256
operator|)
block|{
name|__a
block|,
name|__b
block|,
name|__c
block|,
name|__d
block|,
name|__e
block|,
name|__f
block|,
name|__g
block|,
name|__h
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_setr_epi32
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
parameter_list|,
name|int
name|__i4
parameter_list|,
name|int
name|__i5
parameter_list|,
name|int
name|__i6
parameter_list|,
name|int
name|__i7
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
operator|(
name|__v8si
operator|)
block|{
name|__i0
block|,
name|__i1
block|,
name|__i2
block|,
name|__i3
block|,
name|__i4
block|,
name|__i5
block|,
name|__i6
block|,
name|__i7
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_setr_epi16
parameter_list|(
name|short
name|__w15
parameter_list|,
name|short
name|__w14
parameter_list|,
name|short
name|__w13
parameter_list|,
name|short
name|__w12
parameter_list|,
name|short
name|__w11
parameter_list|,
name|short
name|__w10
parameter_list|,
name|short
name|__w09
parameter_list|,
name|short
name|__w08
parameter_list|,
name|short
name|__w07
parameter_list|,
name|short
name|__w06
parameter_list|,
name|short
name|__w05
parameter_list|,
name|short
name|__w04
parameter_list|,
name|short
name|__w03
parameter_list|,
name|short
name|__w02
parameter_list|,
name|short
name|__w01
parameter_list|,
name|short
name|__w00
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
operator|(
name|__v16hi
operator|)
block|{
name|__w15
block|,
name|__w14
block|,
name|__w13
block|,
name|__w12
block|,
name|__w11
block|,
name|__w10
block|,
name|__w09
block|,
name|__w08
block|,
name|__w07
block|,
name|__w06
block|,
name|__w05
block|,
name|__w04
block|,
name|__w03
block|,
name|__w02
block|,
name|__w01
block|,
name|__w00
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_setr_epi8
parameter_list|(
name|char
name|__b31
parameter_list|,
name|char
name|__b30
parameter_list|,
name|char
name|__b29
parameter_list|,
name|char
name|__b28
parameter_list|,
name|char
name|__b27
parameter_list|,
name|char
name|__b26
parameter_list|,
name|char
name|__b25
parameter_list|,
name|char
name|__b24
parameter_list|,
name|char
name|__b23
parameter_list|,
name|char
name|__b22
parameter_list|,
name|char
name|__b21
parameter_list|,
name|char
name|__b20
parameter_list|,
name|char
name|__b19
parameter_list|,
name|char
name|__b18
parameter_list|,
name|char
name|__b17
parameter_list|,
name|char
name|__b16
parameter_list|,
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
name|__b09
parameter_list|,
name|char
name|__b08
parameter_list|,
name|char
name|__b07
parameter_list|,
name|char
name|__b06
parameter_list|,
name|char
name|__b05
parameter_list|,
name|char
name|__b04
parameter_list|,
name|char
name|__b03
parameter_list|,
name|char
name|__b02
parameter_list|,
name|char
name|__b01
parameter_list|,
name|char
name|__b00
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
operator|(
name|__v32qi
operator|)
block|{
name|__b31
block|,
name|__b30
block|,
name|__b29
block|,
name|__b28
block|,
name|__b27
block|,
name|__b26
block|,
name|__b25
block|,
name|__b24
block|,
name|__b23
block|,
name|__b22
block|,
name|__b21
block|,
name|__b20
block|,
name|__b19
block|,
name|__b18
block|,
name|__b17
block|,
name|__b16
block|,
name|__b15
block|,
name|__b14
block|,
name|__b13
block|,
name|__b12
block|,
name|__b11
block|,
name|__b10
block|,
name|__b09
block|,
name|__b08
block|,
name|__b07
block|,
name|__b06
block|,
name|__b05
block|,
name|__b04
block|,
name|__b03
block|,
name|__b02
block|,
name|__b01
block|,
name|__b00
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_setr_epi64x
parameter_list|(
name|long
name|long
name|__a
parameter_list|,
name|long
name|long
name|__b
parameter_list|,
name|long
name|long
name|__c
parameter_list|,
name|long
name|long
name|__d
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
operator|(
name|__v4di
operator|)
block|{
name|__a
block|,
name|__b
block|,
name|__c
block|,
name|__d
block|}
return|;
block|}
end_function

begin_comment
comment|/* Create vectors with repeated elements */
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_set1_pd
parameter_list|(
name|double
name|__w
parameter_list|)
block|{
return|return
operator|(
name|__m256d
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

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_set1_ps
parameter_list|(
name|float
name|__w
parameter_list|)
block|{
return|return
operator|(
name|__m256
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

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_set1_epi32
parameter_list|(
name|int
name|__i
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
operator|(
name|__v8si
operator|)
block|{
name|__i
block|,
name|__i
block|,
name|__i
block|,
name|__i
block|,
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

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_set1_epi16
parameter_list|(
name|short
name|__w
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
operator|(
name|__v16hi
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
block|,
name|__w
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_set1_epi8
parameter_list|(
name|char
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
operator|(
name|__v32qi
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
block|,
name|__b
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_set1_epi64x
parameter_list|(
name|long
name|long
name|__q
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
operator|(
name|__v4di
operator|)
block|{
name|__q
block|,
name|__q
block|,
name|__q
block|,
name|__q
block|}
return|;
block|}
end_function

begin_comment
comment|/* Create __zeroed vectors */
end_comment

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_setzero_pd
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|__m256d
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

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_setzero_ps
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|__m256
operator|)
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
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

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_setzero_si256
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
block|{
literal|0LL
block|,
literal|0LL
block|,
literal|0LL
block|,
literal|0LL
block|}
return|;
block|}
end_function

begin_comment
comment|/* Cast between vector types */
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_castpd_ps
parameter_list|(
name|__m256d
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m256
operator|)
name|__a
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_castpd_si256
parameter_list|(
name|__m256d
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
name|__a
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_castps_pd
parameter_list|(
name|__m256
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m256d
operator|)
name|__a
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_castps_si256
parameter_list|(
name|__m256
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
name|__a
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_castsi256_ps
parameter_list|(
name|__m256i
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m256
operator|)
name|__a
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_castsi256_pd
parameter_list|(
name|__m256i
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m256d
operator|)
name|__a
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm256_castpd256_pd128
parameter_list|(
name|__m256d
name|__a
parameter_list|)
block|{
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v4df
operator|)
name|__a
argument_list|,
operator|(
name|__v4df
operator|)
name|__a
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm256_castps256_ps128
parameter_list|(
name|__m256
name|__a
parameter_list|)
block|{
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v8sf
operator|)
name|__a
argument_list|,
operator|(
name|__v8sf
operator|)
name|__a
argument_list|,
literal|0
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

begin_function
specifier|static
name|__inline
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm256_castsi256_si128
parameter_list|(
name|__m256i
name|__a
parameter_list|)
block|{
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v4di
operator|)
name|__a
argument_list|,
operator|(
name|__v4di
operator|)
name|__a
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_castpd128_pd256
parameter_list|(
name|__m128d
name|__a
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
name|__a
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_castps128_ps256
parameter_list|(
name|__m128
name|__a
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
name|__a
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_castsi128_si256
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
name|__v2di
operator|)
name|__a
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*    Vector insert.    We use macros rather than inlines because we only want to accept    invocations where the immediate M is a constant expression. */
end_comment

begin_define
define|#
directive|define
name|_mm256_insertf128_ps
parameter_list|(
name|V1
parameter_list|,
name|V2
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m256)__builtin_shufflevector( \     (__v8sf)(__m256)(V1), \     (__v8sf)_mm256_castps128_ps256((__m128)(V2)), \     (((M)& 1) ?  0 :  8), \     (((M)& 1) ?  1 :  9), \     (((M)& 1) ?  2 : 10), \     (((M)& 1) ?  3 : 11), \     (((M)& 1) ?  8 :  4), \     (((M)& 1) ?  9 :  5), \     (((M)& 1) ? 10 :  6), \     (((M)& 1) ? 11 :  7) );})
end_define

begin_define
define|#
directive|define
name|_mm256_insertf128_pd
parameter_list|(
name|V1
parameter_list|,
name|V2
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m256d)__builtin_shufflevector( \     (__v4df)(__m256d)(V1), \     (__v4df)_mm256_castpd128_pd256((__m128d)(V2)), \     (((M)& 1) ? 0 : 4), \     (((M)& 1) ? 1 : 5), \     (((M)& 1) ? 4 : 2), \     (((M)& 1) ? 5 : 3) );})
end_define

begin_define
define|#
directive|define
name|_mm256_insertf128_si256
parameter_list|(
name|V1
parameter_list|,
name|V2
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m256i)__builtin_shufflevector( \     (__v4di)(__m256i)(V1), \     (__v4di)_mm256_castsi128_si256((__m128i)(V2)), \     (((M)& 1) ? 0 : 4), \     (((M)& 1) ? 1 : 5), \     (((M)& 1) ? 4 : 2), \     (((M)& 1) ? 5 : 3) );})
end_define

begin_comment
comment|/*    Vector extract.    We use macros rather than inlines because we only want to accept    invocations where the immediate M is a constant expression. */
end_comment

begin_define
define|#
directive|define
name|_mm256_extractf128_ps
parameter_list|(
name|V
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m128)__builtin_shufflevector( \     (__v8sf)(__m256)(V), \     (__v8sf)(_mm256_undefined_ps()), \     (((M)& 1) ? 4 : 0), \     (((M)& 1) ? 5 : 1), \     (((M)& 1) ? 6 : 2), \     (((M)& 1) ? 7 : 3) );})
end_define

begin_define
define|#
directive|define
name|_mm256_extractf128_pd
parameter_list|(
name|V
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m128d)__builtin_shufflevector( \     (__v4df)(__m256d)(V), \     (__v4df)(_mm256_undefined_pd()), \     (((M)& 1) ? 2 : 0), \     (((M)& 1) ? 3 : 1) );})
end_define

begin_define
define|#
directive|define
name|_mm256_extractf128_si256
parameter_list|(
name|V
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m128i)__builtin_shufflevector( \     (__v4di)(__m256i)(V), \     (__v4di)(_mm256_undefined_si256()), \     (((M)& 1) ? 2 : 0), \     (((M)& 1) ? 3 : 1) );})
end_define

begin_comment
comment|/* SIMD load ops (unaligned) */
end_comment

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_loadu2_m128
parameter_list|(
name|float
specifier|const
modifier|*
name|__addr_hi
parameter_list|,
name|float
specifier|const
modifier|*
name|__addr_lo
parameter_list|)
block|{
name|__m256
name|__v256
init|=
name|_mm256_castps128_ps256
argument_list|(
name|_mm_loadu_ps
argument_list|(
name|__addr_lo
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|_mm256_insertf128_ps
argument_list|(
name|__v256
argument_list|,
name|_mm_loadu_ps
argument_list|(
name|__addr_hi
argument_list|)
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_loadu2_m128d
parameter_list|(
name|double
specifier|const
modifier|*
name|__addr_hi
parameter_list|,
name|double
specifier|const
modifier|*
name|__addr_lo
parameter_list|)
block|{
name|__m256d
name|__v256
init|=
name|_mm256_castpd128_pd256
argument_list|(
name|_mm_loadu_pd
argument_list|(
name|__addr_lo
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|_mm256_insertf128_pd
argument_list|(
name|__v256
argument_list|,
name|_mm_loadu_pd
argument_list|(
name|__addr_hi
argument_list|)
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_loadu2_m128i
parameter_list|(
name|__m128i
specifier|const
modifier|*
name|__addr_hi
parameter_list|,
name|__m128i
specifier|const
modifier|*
name|__addr_lo
parameter_list|)
block|{
name|__m256i
name|__v256
init|=
name|_mm256_castsi128_si256
argument_list|(
name|_mm_loadu_si128
argument_list|(
name|__addr_lo
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|_mm256_insertf128_si256
argument_list|(
name|__v256
argument_list|,
name|_mm_loadu_si128
argument_list|(
name|__addr_hi
argument_list|)
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* SIMD store ops (unaligned) */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|__DEFAULT_FN_ATTRS
name|_mm256_storeu2_m128
parameter_list|(
name|float
modifier|*
name|__addr_hi
parameter_list|,
name|float
modifier|*
name|__addr_lo
parameter_list|,
name|__m256
name|__a
parameter_list|)
block|{
name|__m128
name|__v128
decl_stmt|;
name|__v128
operator|=
name|_mm256_castps256_ps128
argument_list|(
name|__a
argument_list|)
expr_stmt|;
name|_mm_storeu_ps
argument_list|(
name|__addr_lo
argument_list|,
name|__v128
argument_list|)
expr_stmt|;
name|__v128
operator|=
name|_mm256_extractf128_ps
argument_list|(
name|__a
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|_mm_storeu_ps
argument_list|(
name|__addr_hi
argument_list|,
name|__v128
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__DEFAULT_FN_ATTRS
name|_mm256_storeu2_m128d
parameter_list|(
name|double
modifier|*
name|__addr_hi
parameter_list|,
name|double
modifier|*
name|__addr_lo
parameter_list|,
name|__m256d
name|__a
parameter_list|)
block|{
name|__m128d
name|__v128
decl_stmt|;
name|__v128
operator|=
name|_mm256_castpd256_pd128
argument_list|(
name|__a
argument_list|)
expr_stmt|;
name|_mm_storeu_pd
argument_list|(
name|__addr_lo
argument_list|,
name|__v128
argument_list|)
expr_stmt|;
name|__v128
operator|=
name|_mm256_extractf128_pd
argument_list|(
name|__a
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|_mm_storeu_pd
argument_list|(
name|__addr_hi
argument_list|,
name|__v128
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__DEFAULT_FN_ATTRS
name|_mm256_storeu2_m128i
parameter_list|(
name|__m128i
modifier|*
name|__addr_hi
parameter_list|,
name|__m128i
modifier|*
name|__addr_lo
parameter_list|,
name|__m256i
name|__a
parameter_list|)
block|{
name|__m128i
name|__v128
decl_stmt|;
name|__v128
operator|=
name|_mm256_castsi256_si128
argument_list|(
name|__a
argument_list|)
expr_stmt|;
name|_mm_storeu_si128
argument_list|(
name|__addr_lo
argument_list|,
name|__v128
argument_list|)
expr_stmt|;
name|__v128
operator|=
name|_mm256_extractf128_si256
argument_list|(
name|__a
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|_mm_storeu_si128
argument_list|(
name|__addr_hi
argument_list|,
name|__v128
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_set_m128
parameter_list|(
name|__m128
name|__hi
parameter_list|,
name|__m128
name|__lo
parameter_list|)
block|{
return|return
operator|(
name|__m256
operator|)
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v4sf
operator|)
name|__lo
argument_list|,
operator|(
name|__v4sf
operator|)
name|__hi
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_set_m128d
parameter_list|(
name|__m128d
name|__hi
parameter_list|,
name|__m128d
name|__lo
parameter_list|)
block|{
return|return
operator|(
name|__m256d
operator|)
name|_mm256_set_m128
argument_list|(
operator|(
name|__m128
operator|)
name|__hi
argument_list|,
operator|(
name|__m128
operator|)
name|__lo
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_set_m128i
parameter_list|(
name|__m128i
name|__hi
parameter_list|,
name|__m128i
name|__lo
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
name|_mm256_set_m128
argument_list|(
operator|(
name|__m128
operator|)
name|__hi
argument_list|,
operator|(
name|__m128
operator|)
name|__lo
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256
name|__DEFAULT_FN_ATTRS
name|_mm256_setr_m128
parameter_list|(
name|__m128
name|__lo
parameter_list|,
name|__m128
name|__hi
parameter_list|)
block|{
return|return
name|_mm256_set_m128
argument_list|(
name|__hi
argument_list|,
name|__lo
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256d
name|__DEFAULT_FN_ATTRS
name|_mm256_setr_m128d
parameter_list|(
name|__m128d
name|__lo
parameter_list|,
name|__m128d
name|__hi
parameter_list|)
block|{
return|return
operator|(
name|__m256d
operator|)
name|_mm256_set_m128
argument_list|(
operator|(
name|__m128
operator|)
name|__hi
argument_list|,
operator|(
name|__m128
operator|)
name|__lo
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__m256i
name|__DEFAULT_FN_ATTRS
name|_mm256_setr_m128i
parameter_list|(
name|__m128i
name|__lo
parameter_list|,
name|__m128i
name|__hi
parameter_list|)
block|{
return|return
operator|(
name|__m256i
operator|)
name|_mm256_set_m128
argument_list|(
operator|(
name|__m128
operator|)
name|__hi
argument_list|,
operator|(
name|__m128
operator|)
name|__lo
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|__DEFAULT_FN_ATTRS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AVXINTRIN_H */
end_comment

end_unit

