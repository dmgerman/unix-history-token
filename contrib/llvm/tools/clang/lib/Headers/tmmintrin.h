begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- tmmintrin.h - SSSE3 intrinsics -----------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TMMINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__TMMINTRIN_H
end_define

begin_include
include|#
directive|include
file|<pmmintrin.h>
end_include

begin_comment
comment|/* Define the default attributes for the functions in this file. */
end_comment

begin_define
define|#
directive|define
name|__DEFAULT_FN_ATTRS
value|__attribute__((__always_inline__, __nodebug__, __target__("ssse3")))
end_define

begin_comment
comment|/// \brief Computes the absolute value of each of the packed 8-bit signed
end_comment

begin_comment
comment|///    integers in the source operand and stores the 8-bit unsigned integer
end_comment

begin_comment
comment|///    results in the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c PABSB instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit vector of [8 x i8].
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the absolute values of the
end_comment

begin_comment
comment|///    elements in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_abs_pi8
parameter_list|(
name|__m64
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_pabsb
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
comment|/// \brief Computes the absolute value of each of the packed 8-bit signed
end_comment

begin_comment
comment|///    integers in the source operand and stores the 8-bit unsigned integer
end_comment

begin_comment
comment|///    results in the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPABSB instruction.
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
comment|/// \returns A 128-bit integer vector containing the absolute values of the
end_comment

begin_comment
comment|///    elements in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_abs_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pabsb128
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
comment|/// \brief Computes the absolute value of each of the packed 16-bit signed
end_comment

begin_comment
comment|///    integers in the source operand and stores the 16-bit unsigned integer
end_comment

begin_comment
comment|///    results in the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c PABSW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit vector of [4 x i16].
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the absolute values of the
end_comment

begin_comment
comment|///    elements in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_abs_pi16
parameter_list|(
name|__m64
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_pabsw
argument_list|(
operator|(
name|__v4hi
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Computes the absolute value of each of the packed 16-bit signed
end_comment

begin_comment
comment|///    integers in the source operand and stores the 16-bit unsigned integer
end_comment

begin_comment
comment|///    results in the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPABSW instruction.
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
comment|/// \returns A 128-bit integer vector containing the absolute values of the
end_comment

begin_comment
comment|///    elements in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_abs_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pabsw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Computes the absolute value of each of the packed 32-bit signed
end_comment

begin_comment
comment|///    integers in the source operand and stores the 32-bit unsigned integer
end_comment

begin_comment
comment|///    results in the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c PABSD instruction.
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
comment|/// \returns A 64-bit integer vector containing the absolute values of the
end_comment

begin_comment
comment|///    elements in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_abs_pi32
parameter_list|(
name|__m64
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_pabsd
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
comment|/// \brief Computes the absolute value of each of the packed 32-bit signed
end_comment

begin_comment
comment|///    integers in the source operand and stores the 32-bit unsigned integer
end_comment

begin_comment
comment|///    results in the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPABSD instruction.
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
comment|/// \returns A 128-bit integer vector containing the absolute values of the
end_comment

begin_comment
comment|///    elements in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_abs_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pabsd128
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
comment|/// \brief Concatenates the two 128-bit integer vector operands, and
end_comment

begin_comment
comment|///    right-shifts the result by the number of bytes specified in the immediate
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
comment|/// \code
end_comment

begin_comment
comment|/// __m128i _mm_alignr_epi8(__m128i a, __m128i b, const int n);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c PALIGNR instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param a
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8] containing one of the source operands.
end_comment

begin_comment
comment|/// \param b
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8] containing one of the source operands.
end_comment

begin_comment
comment|/// \param n
end_comment

begin_comment
comment|///    An immediate operand specifying how many bytes to right-shift the result.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the concatenated right-shifted
end_comment

begin_comment
comment|///    value.
end_comment

begin_define
define|#
directive|define
name|_mm_alignr_epi8
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|__extension__ ({ \   (__m128i)__builtin_ia32_palignr128((__v16qi)(__m128i)(a), \                                      (__v16qi)(__m128i)(b), (n)); })
end_define

begin_comment
comment|/// \brief Concatenates the two 64-bit integer vector operands, and right-shifts
end_comment

begin_comment
comment|///    the result by the number of bytes specified in the immediate operand.
end_comment

begin_comment
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
comment|/// __m64 _mm_alignr_pi8(__m64 a, __m64 b, const int n);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c PALIGNR instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param a
end_comment

begin_comment
comment|///    A 64-bit vector of [8 x i8] containing one of the source operands.
end_comment

begin_comment
comment|/// \param b
end_comment

begin_comment
comment|///    A 64-bit vector of [8 x i8] containing one of the source operands.
end_comment

begin_comment
comment|/// \param n
end_comment

begin_comment
comment|///    An immediate operand specifying how many bytes to right-shift the result.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the concatenated right-shifted
end_comment

begin_comment
comment|///    value.
end_comment

begin_define
define|#
directive|define
name|_mm_alignr_pi8
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|__extension__ ({ \   (__m64)__builtin_ia32_palignr((__v8qi)(__m64)(a), (__v8qi)(__m64)(b), (n)); })
end_define

begin_comment
comment|/// \brief Horizontally adds the adjacent pairs of values contained in 2 packed
end_comment

begin_comment
comment|///    128-bit vectors of [8 x i16].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPHADDW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal sums of the values are stored in the lower bits of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal sums of the values are stored in the upper bits of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [8 x i16] containing the horizontal sums of
end_comment

begin_comment
comment|///    both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_hadd_epi16
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
name|__builtin_ia32_phaddw128
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
comment|/// \brief Horizontally adds the adjacent pairs of values contained in 2 packed
end_comment

begin_comment
comment|///    128-bit vectors of [4 x i32].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPHADDD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x i32] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal sums of the values are stored in the lower bits of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x i32] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal sums of the values are stored in the upper bits of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x i32] containing the horizontal sums of
end_comment

begin_comment
comment|///    both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_hadd_epi32
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
name|__builtin_ia32_phaddd128
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
comment|/// \brief Horizontally adds the adjacent pairs of values contained in 2 packed
end_comment

begin_comment
comment|///    64-bit vectors of [4 x i16].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c PHADDW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit vector of [4 x i16] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal sums of the values are stored in the lower bits of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit vector of [4 x i16] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal sums of the values are stored in the upper bits of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 64-bit vector of [4 x i16] containing the horizontal sums of both
end_comment

begin_comment
comment|///    operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_hadd_pi16
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
name|__builtin_ia32_phaddw
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
comment|/// \brief Horizontally adds the adjacent pairs of values contained in 2 packed
end_comment

begin_comment
comment|///    64-bit vectors of [2 x i32].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c PHADDD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit vector of [2 x i32] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal sums of the values are stored in the lower bits of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit vector of [2 x i32] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal sums of the values are stored in the upper bits of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 64-bit vector of [2 x i32] containing the horizontal sums of both
end_comment

begin_comment
comment|///    operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_hadd_pi32
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
name|__builtin_ia32_phaddd
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
comment|/// \brief Horizontally adds the adjacent pairs of values contained in 2 packed
end_comment

begin_comment
comment|///    128-bit vectors of [8 x i16]. Positive sums greater than 7FFFh are
end_comment

begin_comment
comment|///    saturated to 7FFFh. Negative sums less than 8000h are saturated to 8000h.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPHADDSW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal sums of the values are stored in the lower bits of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal sums of the values are stored in the upper bits of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [8 x i16] containing the horizontal saturated
end_comment

begin_comment
comment|///    sums of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_hadds_epi16
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
name|__builtin_ia32_phaddsw128
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
comment|/// \brief Horizontally adds the adjacent pairs of values contained in 2 packed
end_comment

begin_comment
comment|///    64-bit vectors of [4 x i16]. Positive sums greater than 7FFFh are
end_comment

begin_comment
comment|///    saturated to 7FFFh. Negative sums less than 8000h are saturated to 8000h.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c PHADDSW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit vector of [4 x i16] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal sums of the values are stored in the lower bits of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit vector of [4 x i16] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal sums of the values are stored in the upper bits of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 64-bit vector of [4 x i16] containing the horizontal saturated
end_comment

begin_comment
comment|///    sums of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_hadds_pi16
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
name|__builtin_ia32_phaddsw
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
comment|/// \brief Horizontally subtracts the adjacent pairs of values contained in 2
end_comment

begin_comment
comment|///    packed 128-bit vectors of [8 x i16].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPHSUBW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal differences between the values are stored in the lower bits of
end_comment

begin_comment
comment|///    the destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal differences between the values are stored in the upper bits of
end_comment

begin_comment
comment|///    the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [8 x i16] containing the horizontal differences
end_comment

begin_comment
comment|///    of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_hsub_epi16
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
name|__builtin_ia32_phsubw128
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
comment|/// \brief Horizontally subtracts the adjacent pairs of values contained in 2
end_comment

begin_comment
comment|///    packed 128-bit vectors of [4 x i32].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPHSUBD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x i32] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal differences between the values are stored in the lower bits of
end_comment

begin_comment
comment|///    the destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x i32] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal differences between the values are stored in the upper bits of
end_comment

begin_comment
comment|///    the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x i32] containing the horizontal differences
end_comment

begin_comment
comment|///    of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_hsub_epi32
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
name|__builtin_ia32_phsubd128
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
comment|/// \brief Horizontally subtracts the adjacent pairs of values contained in 2
end_comment

begin_comment
comment|///    packed 64-bit vectors of [4 x i16].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c PHSUBW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit vector of [4 x i16] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal differences between the values are stored in the lower bits of
end_comment

begin_comment
comment|///    the destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit vector of [4 x i16] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal differences between the values are stored in the upper bits of
end_comment

begin_comment
comment|///    the destination.
end_comment

begin_comment
comment|/// \returns A 64-bit vector of [4 x i16] containing the horizontal differences
end_comment

begin_comment
comment|///    of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_hsub_pi16
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
name|__builtin_ia32_phsubw
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
comment|/// \brief Horizontally subtracts the adjacent pairs of values contained in 2
end_comment

begin_comment
comment|///    packed 64-bit vectors of [2 x i32].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c PHSUBD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit vector of [2 x i32] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal differences between the values are stored in the lower bits of
end_comment

begin_comment
comment|///    the destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit vector of [2 x i32] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal differences between the values are stored in the upper bits of
end_comment

begin_comment
comment|///    the destination.
end_comment

begin_comment
comment|/// \returns A 64-bit vector of [2 x i32] containing the horizontal differences
end_comment

begin_comment
comment|///    of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_hsub_pi32
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
name|__builtin_ia32_phsubd
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
comment|/// \brief Horizontally subtracts the adjacent pairs of values contained in 2
end_comment

begin_comment
comment|///    packed 128-bit vectors of [8 x i16]. Positive differences greater than
end_comment

begin_comment
comment|///    7FFFh are saturated to 7FFFh. Negative differences less than 8000h are
end_comment

begin_comment
comment|///    saturated to 8000h.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPHSUBSW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal differences between the values are stored in the lower bits of
end_comment

begin_comment
comment|///    the destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal differences between the values are stored in the upper bits of
end_comment

begin_comment
comment|///    the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [8 x i16] containing the horizontal saturated
end_comment

begin_comment
comment|///    differences of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_hsubs_epi16
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
name|__builtin_ia32_phsubsw128
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
comment|/// \brief Horizontally subtracts the adjacent pairs of values contained in 2
end_comment

begin_comment
comment|///    packed 64-bit vectors of [4 x i16]. Positive differences greater than
end_comment

begin_comment
comment|///    7FFFh are saturated to 7FFFh. Negative differences less than 8000h are
end_comment

begin_comment
comment|///    saturated to 8000h.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c PHSUBSW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit vector of [4 x i16] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal differences between the values are stored in the lower bits of
end_comment

begin_comment
comment|///    the destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit vector of [4 x i16] containing one of the source operands. The
end_comment

begin_comment
comment|///    horizontal differences between the values are stored in the upper bits of
end_comment

begin_comment
comment|///    the destination.
end_comment

begin_comment
comment|/// \returns A 64-bit vector of [4 x i16] containing the horizontal saturated
end_comment

begin_comment
comment|///    differences of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_hsubs_pi16
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
name|__builtin_ia32_phsubsw
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
comment|/// \brief Multiplies corresponding pairs of packed 8-bit unsigned integer
end_comment

begin_comment
comment|///    values contained in the first source operand and packed 8-bit signed
end_comment

begin_comment
comment|///    integer values contained in the second source operand, adds pairs of
end_comment

begin_comment
comment|///    contiguous products with signed saturation, and writes the 16-bit sums to
end_comment

begin_comment
comment|///    the corresponding bits in the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    For example, bits [7:0] of both operands are multiplied, bits [15:8] of
end_comment

begin_comment
comment|///    both operands are multiplied, and the sum of both results is written to
end_comment

begin_comment
comment|///    bits [15:0] of the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPMADDUBSW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the first source operand.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the second source operand.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the sums of products of both
end_comment

begin_comment
comment|///    operands: \n
end_comment

begin_comment
comment|///    \a R0 := (\a __a0 * \a __b0) + (\a __a1 * \a __b1) \n
end_comment

begin_comment
comment|///    \a R1 := (\a __a2 * \a __b2) + (\a __a3 * \a __b3) \n
end_comment

begin_comment
comment|///    \a R2 := (\a __a4 * \a __b4) + (\a __a5 * \a __b5) \n
end_comment

begin_comment
comment|///    \a R3 := (\a __a6 * \a __b6) + (\a __a7 * \a __b7) \n
end_comment

begin_comment
comment|///    \a R4 := (\a __a8 * \a __b8) + (\a __a9 * \a __b9) \n
end_comment

begin_comment
comment|///    \a R5 := (\a __a10 * \a __b10) + (\a __a11 * \a __b11) \n
end_comment

begin_comment
comment|///    \a R6 := (\a __a12 * \a __b12) + (\a __a13 * \a __b13) \n
end_comment

begin_comment
comment|///    \a R7 := (\a __a14 * \a __b14) + (\a __a15 * \a __b15)
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_maddubs_epi16
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
name|__builtin_ia32_pmaddubsw128
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
comment|/// \brief Multiplies corresponding pairs of packed 8-bit unsigned integer
end_comment

begin_comment
comment|///    values contained in the first source operand and packed 8-bit signed
end_comment

begin_comment
comment|///    integer values contained in the second source operand, adds pairs of
end_comment

begin_comment
comment|///    contiguous products with signed saturation, and writes the 16-bit sums to
end_comment

begin_comment
comment|///    the corresponding bits in the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    For example, bits [7:0] of both operands are multiplied, bits [15:8] of
end_comment

begin_comment
comment|///    both operands are multiplied, and the sum of both results is written to
end_comment

begin_comment
comment|///    bits [15:0] of the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c PMADDUBSW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit integer vector containing the first source operand.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit integer vector containing the second source operand.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the sums of products of both
end_comment

begin_comment
comment|///    operands: \n
end_comment

begin_comment
comment|///    \a R0 := (\a __a0 * \a __b0) + (\a __a1 * \a __b1) \n
end_comment

begin_comment
comment|///    \a R1 := (\a __a2 * \a __b2) + (\a __a3 * \a __b3) \n
end_comment

begin_comment
comment|///    \a R2 := (\a __a4 * \a __b4) + (\a __a5 * \a __b5) \n
end_comment

begin_comment
comment|///    \a R3 := (\a __a6 * \a __b6) + (\a __a7 * \a __b7)
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_maddubs_pi16
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
name|__builtin_ia32_pmaddubsw
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
comment|/// \brief Multiplies packed 16-bit signed integer values, truncates the 32-bit
end_comment

begin_comment
comment|///    products to the 18 most significant bits by right-shifting, rounds the
end_comment

begin_comment
comment|///    truncated value by adding 1, and writes bits [16:1] to the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPMULHRSW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16] containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [8 x i16] containing the rounded and scaled
end_comment

begin_comment
comment|///    products of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_mulhrs_epi16
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
name|__builtin_ia32_pmulhrsw128
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
comment|/// \brief Multiplies packed 16-bit signed integer values, truncates the 32-bit
end_comment

begin_comment
comment|///    products to the 18 most significant bits by right-shifting, rounds the
end_comment

begin_comment
comment|///    truncated value by adding 1, and writes bits [16:1] to the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c PMULHRSW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit vector of [4 x i16] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit vector of [4 x i16] containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 64-bit vector of [4 x i16] containing the rounded and scaled
end_comment

begin_comment
comment|///    products of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_mulhrs_pi16
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
name|__builtin_ia32_pmulhrsw
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
comment|/// \brief Copies the 8-bit integers from a 128-bit integer vector to the
end_comment

begin_comment
comment|///    destination or clears 8-bit values in the destination, as specified by
end_comment

begin_comment
comment|///    the second source operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSHUFB instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the values to be copied.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing control bytes corresponding to
end_comment

begin_comment
comment|///    positions in the destination:
end_comment

begin_comment
comment|///    Bit 7: \n
end_comment

begin_comment
comment|///    1: Clear the corresponding byte in the destination. \n
end_comment

begin_comment
comment|///    0: Copy the selected source byte to the corresponding byte in the
end_comment

begin_comment
comment|///    destination. \n
end_comment

begin_comment
comment|///    Bits [6:4] Reserved.  \n
end_comment

begin_comment
comment|///    Bits [3:0] select the source byte to be copied.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the copied or cleared values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_shuffle_epi8
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
name|__builtin_ia32_pshufb128
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
comment|/// \brief Copies the 8-bit integers from a 64-bit integer vector to the
end_comment

begin_comment
comment|///    destination or clears 8-bit values in the destination, as specified by
end_comment

begin_comment
comment|///    the second source operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c PSHUFB instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit integer vector containing the values to be copied.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit integer vector containing control bytes corresponding to
end_comment

begin_comment
comment|///    positions in the destination:
end_comment

begin_comment
comment|///    Bit 7: \n
end_comment

begin_comment
comment|///    1: Clear the corresponding byte in the destination. \n
end_comment

begin_comment
comment|///    0: Copy the selected source byte to the corresponding byte in the
end_comment

begin_comment
comment|///    destination. \n
end_comment

begin_comment
comment|///    Bits [3:0] select the source byte to be copied.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the copied or cleared values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_shuffle_pi8
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
name|__builtin_ia32_pshufb
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
comment|/// \brief For each 8-bit integer in the first source operand, perform one of
end_comment

begin_comment
comment|///    the following actions as specified by the second source operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    If the byte in the second source is negative, calculate the two's
end_comment

begin_comment
comment|///    complement of the corresponding byte in the first source, and write that
end_comment

begin_comment
comment|///    value to the destination. If the byte in the second source is positive,
end_comment

begin_comment
comment|///    copy the corresponding byte from the first source to the destination. If
end_comment

begin_comment
comment|///    the byte in the second source is zero, clear the corresponding byte in
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
comment|/// This intrinsic corresponds to the \c VPSIGNB instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the values to be copied.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing control bytes corresponding to
end_comment

begin_comment
comment|///    positions in the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the resultant values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sign_epi8
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
name|__builtin_ia32_psignb128
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
comment|/// \brief For each 16-bit integer in the first source operand, perform one of
end_comment

begin_comment
comment|///    the following actions as specified by the second source operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    If the word in the second source is negative, calculate the two's
end_comment

begin_comment
comment|///    complement of the corresponding word in the first source, and write that
end_comment

begin_comment
comment|///    value to the destination. If the word in the second source is positive,
end_comment

begin_comment
comment|///    copy the corresponding word from the first source to the destination. If
end_comment

begin_comment
comment|///    the word in the second source is zero, clear the corresponding word in
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
comment|/// This intrinsic corresponds to the \c VPSIGNW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the values to be copied.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing control words corresponding to
end_comment

begin_comment
comment|///    positions in the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the resultant values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sign_epi16
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
name|__builtin_ia32_psignw128
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
comment|/// \brief For each 32-bit integer in the first source operand, perform one of
end_comment

begin_comment
comment|///    the following actions as specified by the second source operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    If the doubleword in the second source is negative, calculate the two's
end_comment

begin_comment
comment|///    complement of the corresponding word in the first source, and write that
end_comment

begin_comment
comment|///    value to the destination. If the doubleword in the second source is
end_comment

begin_comment
comment|///    positive, copy the corresponding word from the first source to the
end_comment

begin_comment
comment|///    destination. If the doubleword in the second source is zero, clear the
end_comment

begin_comment
comment|///    corresponding word in the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSIGND instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the values to be copied.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing control doublewords corresponding to
end_comment

begin_comment
comment|///    positions in the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the resultant values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sign_epi32
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
name|__builtin_ia32_psignd128
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
comment|/// \brief For each 8-bit integer in the first source operand, perform one of
end_comment

begin_comment
comment|///    the following actions as specified by the second source operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    If the byte in the second source is negative, calculate the two's
end_comment

begin_comment
comment|///    complement of the corresponding byte in the first source, and write that
end_comment

begin_comment
comment|///    value to the destination. If the byte in the second source is positive,
end_comment

begin_comment
comment|///    copy the corresponding byte from the first source to the destination. If
end_comment

begin_comment
comment|///    the byte in the second source is zero, clear the corresponding byte in
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
comment|/// This intrinsic corresponds to the \c PSIGNB instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit integer vector containing the values to be copied.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit integer vector containing control bytes corresponding to
end_comment

begin_comment
comment|///    positions in the destination.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the resultant values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_sign_pi8
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
name|__builtin_ia32_psignb
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
comment|/// \brief For each 16-bit integer in the first source operand, perform one of
end_comment

begin_comment
comment|///    the following actions as specified by the second source operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    If the word in the second source is negative, calculate the two's
end_comment

begin_comment
comment|///    complement of the corresponding word in the first source, and write that
end_comment

begin_comment
comment|///    value to the destination. If the word in the second source is positive,
end_comment

begin_comment
comment|///    copy the corresponding word from the first source to the destination. If
end_comment

begin_comment
comment|///    the word in the second source is zero, clear the corresponding word in
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
comment|/// This intrinsic corresponds to the \c PSIGNW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit integer vector containing the values to be copied.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit integer vector containing control words corresponding to
end_comment

begin_comment
comment|///    positions in the destination.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the resultant values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_sign_pi16
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
name|__builtin_ia32_psignw
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
comment|/// \brief For each 32-bit integer in the first source operand, perform one of
end_comment

begin_comment
comment|///    the following actions as specified by the second source operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    If the doubleword in the second source is negative, calculate the two's
end_comment

begin_comment
comment|///    complement of the corresponding doubleword in the first source, and
end_comment

begin_comment
comment|///    write that value to the destination. If the doubleword in the second
end_comment

begin_comment
comment|///    source is positive, copy the corresponding doubleword from the first
end_comment

begin_comment
comment|///    source to the destination. If the doubleword in the second source is
end_comment

begin_comment
comment|///    zero, clear the corresponding doubleword in the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c PSIGND instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit integer vector containing the values to be copied.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit integer vector containing two control doublewords corresponding
end_comment

begin_comment
comment|///    to positions in the destination.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the resultant values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_sign_pi32
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
name|__builtin_ia32_psignd
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
comment|/* __TMMINTRIN_H */
end_comment

end_unit

