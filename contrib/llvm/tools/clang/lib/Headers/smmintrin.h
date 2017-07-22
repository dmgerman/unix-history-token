begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- smmintrin.h - SSE4 intrinsics ------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMMINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|_SMMINTRIN_H
end_define

begin_include
include|#
directive|include
file|<tmmintrin.h>
end_include

begin_comment
comment|/* Define the default attributes for the functions in this file. */
end_comment

begin_define
define|#
directive|define
name|__DEFAULT_FN_ATTRS
value|__attribute__((__always_inline__, __nodebug__, __target__("sse4.1")))
end_define

begin_comment
comment|/* SSE4 Rounding macros. */
end_comment

begin_define
define|#
directive|define
name|_MM_FROUND_TO_NEAREST_INT
value|0x00
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_TO_NEG_INF
value|0x01
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_TO_POS_INF
value|0x02
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_TO_ZERO
value|0x03
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_CUR_DIRECTION
value|0x04
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_RAISE_EXC
value|0x00
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_NO_EXC
value|0x08
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_NINT
value|(_MM_FROUND_RAISE_EXC | _MM_FROUND_TO_NEAREST_INT)
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_FLOOR
value|(_MM_FROUND_RAISE_EXC | _MM_FROUND_TO_NEG_INF)
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_CEIL
value|(_MM_FROUND_RAISE_EXC | _MM_FROUND_TO_POS_INF)
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_TRUNC
value|(_MM_FROUND_RAISE_EXC | _MM_FROUND_TO_ZERO)
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_RINT
value|(_MM_FROUND_RAISE_EXC | _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_NEARBYINT
value|(_MM_FROUND_NO_EXC | _MM_FROUND_CUR_DIRECTION)
end_define

begin_comment
comment|/// \brief Rounds up each element of the 128-bit vector of [4 x float] to an
end_comment

begin_comment
comment|///    integer and returns the rounded values in a 128-bit vector of
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
comment|/// \code
end_comment

begin_comment
comment|/// __m128 _mm_ceil_ps(__m128 X);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VROUNDPS / ROUNDPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] values to be rounded up.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the rounded values.
end_comment

begin_define
define|#
directive|define
name|_mm_ceil_ps
parameter_list|(
name|X
parameter_list|)
value|_mm_round_ps((X), _MM_FROUND_CEIL)
end_define

begin_comment
comment|/// \brief Rounds up each element of the 128-bit vector of [2 x double] to an
end_comment

begin_comment
comment|///    integer and returns the rounded values in a 128-bit vector of
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
comment|/// \code
end_comment

begin_comment
comment|/// __m128d _mm_ceil_pd(__m128d X);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VROUNDPD / ROUNDPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] values to be rounded up.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the rounded values.
end_comment

begin_define
define|#
directive|define
name|_mm_ceil_pd
parameter_list|(
name|X
parameter_list|)
value|_mm_round_pd((X), _MM_FROUND_CEIL)
end_define

begin_comment
comment|/// \brief Copies three upper elements of the first 128-bit vector operand to
end_comment

begin_comment
comment|///    the corresponding three upper elements of the 128-bit result vector of
end_comment

begin_comment
comment|///    [4 x float]. Rounds up the lowest element of the second 128-bit vector
end_comment

begin_comment
comment|///    operand to an integer and copies it to the lowest element of the 128-bit
end_comment

begin_comment
comment|///    result vector of [4 x float].
end_comment

begin_comment
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
comment|/// __m128 _mm_ceil_ss(__m128 X, __m128 Y);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VROUNDSS / ROUNDSS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The values stored in bits [127:32] are
end_comment

begin_comment
comment|///    copied to the corresponding bits of the result.
end_comment

begin_comment
comment|/// \param Y
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The value stored in bits [31:0] is
end_comment

begin_comment
comment|///    rounded up to the nearest integer and copied to the corresponding bits
end_comment

begin_comment
comment|///    of the result.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the copied and rounded
end_comment

begin_comment
comment|///    values.
end_comment

begin_define
define|#
directive|define
name|_mm_ceil_ss
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|_mm_round_ss((X), (Y), _MM_FROUND_CEIL)
end_define

begin_comment
comment|/// \brief Copies the upper element of the first 128-bit vector operand to the
end_comment

begin_comment
comment|///    corresponding upper element of the 128-bit result vector of [2 x double].
end_comment

begin_comment
comment|///    Rounds up the lower element of the second 128-bit vector operand to an
end_comment

begin_comment
comment|///    integer and copies it to the lower element of the 128-bit result vector
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
comment|/// \code
end_comment

begin_comment
comment|/// __m128d _mm_ceil_sd(__m128d X, __m128d Y);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VROUNDSD / ROUNDSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The value stored in bits [127:64] is
end_comment

begin_comment
comment|///    copied to the corresponding bits of the result.
end_comment

begin_comment
comment|/// \param Y
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The value stored in bits [63:0] is
end_comment

begin_comment
comment|///    rounded up to the nearest integer and copied to the corresponding bits
end_comment

begin_comment
comment|///    of the result.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the copied and rounded
end_comment

begin_comment
comment|///    values.
end_comment

begin_define
define|#
directive|define
name|_mm_ceil_sd
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|_mm_round_sd((X), (Y), _MM_FROUND_CEIL)
end_define

begin_comment
comment|/// \brief Rounds down each element of the 128-bit vector of [4 x float] to an
end_comment

begin_comment
comment|///    an integer and returns the rounded values in a 128-bit vector of
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
comment|/// \code
end_comment

begin_comment
comment|/// __m128 _mm_floor_ps(__m128 X);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VROUNDPS / ROUNDPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] values to be rounded down.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the rounded values.
end_comment

begin_define
define|#
directive|define
name|_mm_floor_ps
parameter_list|(
name|X
parameter_list|)
value|_mm_round_ps((X), _MM_FROUND_FLOOR)
end_define

begin_comment
comment|/// \brief Rounds down each element of the 128-bit vector of [2 x double] to an
end_comment

begin_comment
comment|///    integer and returns the rounded values in a 128-bit vector of
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
comment|/// \code
end_comment

begin_comment
comment|/// __m128d _mm_floor_pd(__m128d X);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VROUNDPD / ROUNDPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the rounded values.
end_comment

begin_define
define|#
directive|define
name|_mm_floor_pd
parameter_list|(
name|X
parameter_list|)
value|_mm_round_pd((X), _MM_FROUND_FLOOR)
end_define

begin_comment
comment|/// \brief Copies three upper elements of the first 128-bit vector operand to
end_comment

begin_comment
comment|///    the corresponding three upper elements of the 128-bit result vector of
end_comment

begin_comment
comment|///    [4 x float]. Rounds down the lowest element of the second 128-bit vector
end_comment

begin_comment
comment|///    operand to an integer and copies it to the lowest element of the 128-bit
end_comment

begin_comment
comment|///    result vector of [4 x float].
end_comment

begin_comment
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
comment|/// __m128 _mm_floor_ss(__m128 X, __m128 Y);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VROUNDSS / ROUNDSS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The values stored in bits [127:32] are
end_comment

begin_comment
comment|///    copied to the corresponding bits of the result.
end_comment

begin_comment
comment|/// \param Y
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The value stored in bits [31:0] is
end_comment

begin_comment
comment|///    rounded down to the nearest integer and copied to the corresponding bits
end_comment

begin_comment
comment|///    of the result.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the copied and rounded
end_comment

begin_comment
comment|///    values.
end_comment

begin_define
define|#
directive|define
name|_mm_floor_ss
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|_mm_round_ss((X), (Y), _MM_FROUND_FLOOR)
end_define

begin_comment
comment|/// \brief Copies the upper element of the first 128-bit vector operand to the
end_comment

begin_comment
comment|///    corresponding upper element of the 128-bit result vector of [2 x double].
end_comment

begin_comment
comment|///    Rounds down the lower element of the second 128-bit vector operand to an
end_comment

begin_comment
comment|///    integer and copies it to the lower element of the 128-bit result vector
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
comment|/// \code
end_comment

begin_comment
comment|/// __m128d _mm_floor_sd(__m128d X, __m128d Y);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VROUNDSD / ROUNDSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The value stored in bits [127:64] is
end_comment

begin_comment
comment|///    copied to the corresponding bits of the result.
end_comment

begin_comment
comment|/// \param Y
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The value stored in bits [63:0] is
end_comment

begin_comment
comment|///    rounded down to the nearest integer and copied to the corresponding bits
end_comment

begin_comment
comment|///    of the result.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the copied and rounded
end_comment

begin_comment
comment|///    values.
end_comment

begin_define
define|#
directive|define
name|_mm_floor_sd
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|_mm_round_sd((X), (Y), _MM_FROUND_FLOOR)
end_define

begin_comment
comment|/// \brief Rounds each element of the 128-bit vector of [4 x float] to an
end_comment

begin_comment
comment|///    integer value according to the rounding control specified by the second
end_comment

begin_comment
comment|///    argument and returns the rounded values in a 128-bit vector of
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
comment|/// \code
end_comment

begin_comment
comment|/// __m128 _mm_round_ps(__m128 X, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VROUNDPS / ROUNDPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An integer value that specifies the rounding operation. \n
end_comment

begin_comment
comment|///    Bits [7:4] are reserved. \n
end_comment

begin_comment
comment|///    Bit [3] is a precision exception value: \n
end_comment

begin_comment
comment|///      0: A normal PE exception is used \n
end_comment

begin_comment
comment|///      1: The PE field is not updated \n
end_comment

begin_comment
comment|///    Bit [2] is the rounding control source: \n
end_comment

begin_comment
comment|///      0: Use bits [1:0] of \a M \n
end_comment

begin_comment
comment|///      1: Use the current MXCSR setting \n
end_comment

begin_comment
comment|///    Bits [1:0] contain the rounding control definition: \n
end_comment

begin_comment
comment|///      00: Nearest \n
end_comment

begin_comment
comment|///      01: Downward (toward negative infinity) \n
end_comment

begin_comment
comment|///      10: Upward (toward positive infinity) \n
end_comment

begin_comment
comment|///      11: Truncated
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the rounded values.
end_comment

begin_define
define|#
directive|define
name|_mm_round_ps
parameter_list|(
name|X
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m128)__builtin_ia32_roundps((__v4sf)(__m128)(X), (M)); })
end_define

begin_comment
comment|/// \brief Copies three upper elements of the first 128-bit vector operand to
end_comment

begin_comment
comment|///    the corresponding three upper elements of the 128-bit result vector of
end_comment

begin_comment
comment|///    [4 x float]. Rounds the lowest element of the second 128-bit vector
end_comment

begin_comment
comment|///    operand to an integer value according to the rounding control specified
end_comment

begin_comment
comment|///    by the third argument and copies it to the lowest element of the 128-bit
end_comment

begin_comment
comment|///    result vector of [4 x float].
end_comment

begin_comment
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
comment|/// __m128 _mm_round_ss(__m128 X, __m128 Y, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VROUNDSS / ROUNDSS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The values stored in bits [127:32] are
end_comment

begin_comment
comment|///    copied to the corresponding bits of the result.
end_comment

begin_comment
comment|/// \param Y
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. The value stored in bits [31:0] is
end_comment

begin_comment
comment|///    rounded to the nearest integer using the specified rounding control and
end_comment

begin_comment
comment|///    copied to the corresponding bits of the result.
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An integer value that specifies the rounding operation. \n
end_comment

begin_comment
comment|///    Bits [7:4] are reserved. \n
end_comment

begin_comment
comment|///    Bit [3] is a precision exception value: \n
end_comment

begin_comment
comment|///      0: A normal PE exception is used \n
end_comment

begin_comment
comment|///      1: The PE field is not updated \n
end_comment

begin_comment
comment|///    Bit [2] is the rounding control source: \n
end_comment

begin_comment
comment|///      0: Use bits [1:0] of \a M \n
end_comment

begin_comment
comment|///      1: Use the current MXCSR setting \n
end_comment

begin_comment
comment|///    Bits [1:0] contain the rounding control definition: \n
end_comment

begin_comment
comment|///      00: Nearest \n
end_comment

begin_comment
comment|///      01: Downward (toward negative infinity) \n
end_comment

begin_comment
comment|///      10: Upward (toward positive infinity) \n
end_comment

begin_comment
comment|///      11: Truncated
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the copied and rounded
end_comment

begin_comment
comment|///    values.
end_comment

begin_define
define|#
directive|define
name|_mm_round_ss
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m128)__builtin_ia32_roundss((__v4sf)(__m128)(X), \                                  (__v4sf)(__m128)(Y), (M)); })
end_define

begin_comment
comment|/// \brief Rounds each element of the 128-bit vector of [2 x double] to an
end_comment

begin_comment
comment|///    integer value according to the rounding control specified by the second
end_comment

begin_comment
comment|///    argument and returns the rounded values in a 128-bit vector of
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
comment|/// \code
end_comment

begin_comment
comment|/// __m128d _mm_round_pd(__m128d X, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VROUNDPD / ROUNDPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An integer value that specifies the rounding operation. \n
end_comment

begin_comment
comment|///    Bits [7:4] are reserved. \n
end_comment

begin_comment
comment|///    Bit [3] is a precision exception value: \n
end_comment

begin_comment
comment|///      0: A normal PE exception is used \n
end_comment

begin_comment
comment|///      1: The PE field is not updated \n
end_comment

begin_comment
comment|///    Bit [2] is the rounding control source: \n
end_comment

begin_comment
comment|///      0: Use bits [1:0] of \a M \n
end_comment

begin_comment
comment|///      1: Use the current MXCSR setting \n
end_comment

begin_comment
comment|///    Bits [1:0] contain the rounding control definition: \n
end_comment

begin_comment
comment|///      00: Nearest \n
end_comment

begin_comment
comment|///      01: Downward (toward negative infinity) \n
end_comment

begin_comment
comment|///      10: Upward (toward positive infinity) \n
end_comment

begin_comment
comment|///      11: Truncated
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the rounded values.
end_comment

begin_define
define|#
directive|define
name|_mm_round_pd
parameter_list|(
name|X
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m128d)__builtin_ia32_roundpd((__v2df)(__m128d)(X), (M)); })
end_define

begin_comment
comment|/// \brief Copies the upper element of the first 128-bit vector operand to the
end_comment

begin_comment
comment|///    corresponding upper element of the 128-bit result vector of [2 x double].
end_comment

begin_comment
comment|///    Rounds the lower element of the second 128-bit vector operand to an
end_comment

begin_comment
comment|///    integer value according to the rounding control specified by the third
end_comment

begin_comment
comment|///    argument and copies it to the lower element of the 128-bit result vector
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
comment|/// \code
end_comment

begin_comment
comment|/// __m128d _mm_round_sd(__m128d X, __m128d Y, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VROUNDSD / ROUNDSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The value stored in bits [127:64] is
end_comment

begin_comment
comment|///    copied to the corresponding bits of the result.
end_comment

begin_comment
comment|/// \param Y
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The value stored in bits [63:0] is
end_comment

begin_comment
comment|///    rounded to the nearest integer using the specified rounding control and
end_comment

begin_comment
comment|///    copied to the corresponding bits of the result.
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An integer value that specifies the rounding operation. \n
end_comment

begin_comment
comment|///    Bits [7:4] are reserved. \n
end_comment

begin_comment
comment|///    Bit [3] is a precision exception value: \n
end_comment

begin_comment
comment|///      0: A normal PE exception is used \n
end_comment

begin_comment
comment|///      1: The PE field is not updated \n
end_comment

begin_comment
comment|///    Bit [2] is the rounding control source: \n
end_comment

begin_comment
comment|///      0: Use bits [1:0] of \a M \n
end_comment

begin_comment
comment|///      1: Use the current MXCSR setting \n
end_comment

begin_comment
comment|///    Bits [1:0] contain the rounding control definition: \n
end_comment

begin_comment
comment|///      00: Nearest \n
end_comment

begin_comment
comment|///      01: Downward (toward negative infinity) \n
end_comment

begin_comment
comment|///      10: Upward (toward positive infinity) \n
end_comment

begin_comment
comment|///      11: Truncated
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the copied and rounded
end_comment

begin_comment
comment|///    values.
end_comment

begin_define
define|#
directive|define
name|_mm_round_sd
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m128d)__builtin_ia32_roundsd((__v2df)(__m128d)(X), \                                   (__v2df)(__m128d)(Y), (M)); })
end_define

begin_comment
comment|/* SSE4 Packed Blending Intrinsics.  */
end_comment

begin_comment
comment|/// \brief Returns a 128-bit vector of [2 x double] where the values are
end_comment

begin_comment
comment|///    selected from either the first or second operand as specified by the
end_comment

begin_comment
comment|///    third operand, the control mask.
end_comment

begin_comment
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
comment|/// __m128d _mm_blend_pd(__m128d V1, __m128d V2, const int M);
end_comment

begin_comment
comment|/// \endcode
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
comment|/// \param V1
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param V2
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An immediate integer operand, with mask bits [1:0] specifying how the
end_comment

begin_comment
comment|///    values are to be copied. The position of the mask bit corresponds to the
end_comment

begin_comment
comment|///    index of a copied value. When a mask bit is 0, the corresponding 64-bit
end_comment

begin_comment
comment|///    element in operand \a V1 is copied to the same position in the result.
end_comment

begin_comment
comment|///    When a mask bit is 1, the corresponding 64-bit element in operand \a V2
end_comment

begin_comment
comment|///    is copied to the same position in the result.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the copied values.
end_comment

begin_define
define|#
directive|define
name|_mm_blend_pd
parameter_list|(
name|V1
parameter_list|,
name|V2
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m128d)__builtin_shufflevector((__v2df)(__m128d)(V1), \                                    (__v2df)(__m128d)(V2), \                                    (((M)& 0x01) ? 2 : 0), \                                    (((M)& 0x02) ? 3 : 1)); })
end_define

begin_comment
comment|/// \brief Returns a 128-bit vector of [4 x float] where the values are selected
end_comment

begin_comment
comment|///    from either the first or second operand as specified by the third
end_comment

begin_comment
comment|///    operand, the control mask.
end_comment

begin_comment
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
comment|/// __m128 _mm_blend_ps(__m128 V1, __m128 V2, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VBLENDPS / BLENDPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param V1
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \param V2
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
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
comment|///    index of a copied value. When a mask bit is 0, the corresponding 32-bit
end_comment

begin_comment
comment|///    element in operand \a V1 is copied to the same position in the result.
end_comment

begin_comment
comment|///    When a mask bit is 1, the corresponding 32-bit element in operand \a V2
end_comment

begin_comment
comment|///    is copied to the same position in the result.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the copied values.
end_comment

begin_define
define|#
directive|define
name|_mm_blend_ps
parameter_list|(
name|V1
parameter_list|,
name|V2
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m128)__builtin_shufflevector((__v4sf)(__m128)(V1), (__v4sf)(__m128)(V2), \                                   (((M)& 0x01) ? 4 : 0), \                                   (((M)& 0x02) ? 5 : 1), \                                   (((M)& 0x04) ? 6 : 2), \                                   (((M)& 0x08) ? 7 : 3)); })
end_define

begin_comment
comment|/// \brief Returns a 128-bit vector of [2 x double] where the values are
end_comment

begin_comment
comment|///    selected from either the first or second operand as specified by the
end_comment

begin_comment
comment|///    third operand, the control mask.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VBLENDVPD / BLENDVPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V1
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param __V2
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param __M
end_comment

begin_comment
comment|///    A 128-bit vector operand, with mask bits 127 and 63 specifying how the
end_comment

begin_comment
comment|///    values are to be copied. The position of the mask bit corresponds to the
end_comment

begin_comment
comment|///    most significant bit of a copied value. When a mask bit is 0, the
end_comment

begin_comment
comment|///    corresponding 64-bit element in operand \a __V1 is copied to the same
end_comment

begin_comment
comment|///    position in the result. When a mask bit is 1, the corresponding 64-bit
end_comment

begin_comment
comment|///    element in operand \a __V2 is copied to the same position in the result.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the copied values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_blendv_pd
parameter_list|(
name|__m128d
name|__V1
parameter_list|,
name|__m128d
name|__V2
parameter_list|,
name|__m128d
name|__M
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_blendvpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__V1
argument_list|,
operator|(
name|__v2df
operator|)
name|__V2
argument_list|,
operator|(
name|__v2df
operator|)
name|__M
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Returns a 128-bit vector of [4 x float] where the values are
end_comment

begin_comment
comment|///    selected from either the first or second operand as specified by the
end_comment

begin_comment
comment|///    third operand, the control mask.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VBLENDVPS / BLENDVPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V1
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \param __V2
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \param __M
end_comment

begin_comment
comment|///    A 128-bit vector operand, with mask bits 127, 95, 63, and 31 specifying
end_comment

begin_comment
comment|///    how the values are to be copied. The position of the mask bit corresponds
end_comment

begin_comment
comment|///    to the most significant bit of a copied value. When a mask bit is 0, the
end_comment

begin_comment
comment|///    corresponding 32-bit element in operand \a __V1 is copied to the same
end_comment

begin_comment
comment|///    position in the result. When a mask bit is 1, the corresponding 32-bit
end_comment

begin_comment
comment|///    element in operand \a __V2 is copied to the same position in the result.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the copied values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_blendv_ps
parameter_list|(
name|__m128
name|__V1
parameter_list|,
name|__m128
name|__V2
parameter_list|,
name|__m128
name|__M
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_blendvps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__V1
argument_list|,
operator|(
name|__v4sf
operator|)
name|__V2
argument_list|,
operator|(
name|__v4sf
operator|)
name|__M
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Returns a 128-bit vector of [16 x i8] where the values are selected
end_comment

begin_comment
comment|///    from either of the first or second operand as specified by the third
end_comment

begin_comment
comment|///    operand, the control mask.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPBLENDVB / PBLENDVB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V1
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8].
end_comment

begin_comment
comment|/// \param __V2
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8].
end_comment

begin_comment
comment|/// \param __M
end_comment

begin_comment
comment|///    A 128-bit vector operand, with mask bits 127, 119, 111 ... 7 specifying
end_comment

begin_comment
comment|///    how the values are to be copied. The position of the mask bit corresponds
end_comment

begin_comment
comment|///    to the most significant bit of a copied value. When a mask bit is 0, the
end_comment

begin_comment
comment|///    corresponding 8-bit element in operand \a __V1 is copied to the same
end_comment

begin_comment
comment|///    position in the result. When a mask bit is 1, the corresponding 8-bit
end_comment

begin_comment
comment|///    element in operand \a __V2 is copied to the same position in the result.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [16 x i8] containing the copied values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_blendv_epi8
parameter_list|(
name|__m128i
name|__V1
parameter_list|,
name|__m128i
name|__V2
parameter_list|,
name|__m128i
name|__M
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pblendvb128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__V1
argument_list|,
operator|(
name|__v16qi
operator|)
name|__V2
argument_list|,
operator|(
name|__v16qi
operator|)
name|__M
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Returns a 128-bit vector of [8 x i16] where the values are selected
end_comment

begin_comment
comment|///    from either of the first or second operand as specified by the third
end_comment

begin_comment
comment|///    operand, the control mask.
end_comment

begin_comment
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
comment|/// __m128i _mm_blend_epi16(__m128i V1, __m128i V2, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPBLENDW / PBLENDW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param V1
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16].
end_comment

begin_comment
comment|/// \param V2
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16].
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
comment|///    index of a copied value. When a mask bit is 0, the corresponding 16-bit
end_comment

begin_comment
comment|///    element in operand \a V1 is copied to the same position in the result.
end_comment

begin_comment
comment|///    When a mask bit is 1, the corresponding 16-bit element in operand \a V2
end_comment

begin_comment
comment|///    is copied to the same position in the result.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [8 x i16] containing the copied values.
end_comment

begin_define
define|#
directive|define
name|_mm_blend_epi16
parameter_list|(
name|V1
parameter_list|,
name|V2
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m128i)__builtin_shufflevector((__v8hi)(__m128i)(V1), \                                    (__v8hi)(__m128i)(V2), \                                    (((M)& 0x01) ?  8 : 0), \                                    (((M)& 0x02) ?  9 : 1), \                                    (((M)& 0x04) ? 10 : 2), \                                    (((M)& 0x08) ? 11 : 3), \                                    (((M)& 0x10) ? 12 : 4), \                                    (((M)& 0x20) ? 13 : 5), \                                    (((M)& 0x40) ? 14 : 6), \                                    (((M)& 0x80) ? 15 : 7)); })
end_define

begin_comment
comment|/* SSE4 Dword Multiply Instructions.  */
end_comment

begin_comment
comment|/// \brief Multiples corresponding elements of two 128-bit vectors of [4 x i32]
end_comment

begin_comment
comment|///    and returns the lower 32 bits of the each product in a 128-bit vector of
end_comment

begin_comment
comment|///    [4 x i32].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMULLD / PMULLD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V1
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __V2
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the products of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_mullo_epi32
parameter_list|(
name|__m128i
name|__V1
parameter_list|,
name|__m128i
name|__V2
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
name|__V1
operator|*
operator|(
name|__v4su
operator|)
name|__V2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Multiplies corresponding even-indexed elements of two 128-bit
end_comment

begin_comment
comment|///    vectors of [4 x i32] and returns a 128-bit vector of [2 x i64]
end_comment

begin_comment
comment|///    containing the products.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMULDQ / PMULDQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V1
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x i32].
end_comment

begin_comment
comment|/// \param __V2
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x i32].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x i64] containing the products of both
end_comment

begin_comment
comment|///    operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_mul_epi32
parameter_list|(
name|__m128i
name|__V1
parameter_list|,
name|__m128i
name|__V2
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmuldq128
argument_list|(
operator|(
name|__v4si
operator|)
name|__V1
argument_list|,
operator|(
name|__v4si
operator|)
name|__V2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* SSE4 Floating Point Dot Product Instructions.  */
end_comment

begin_comment
comment|/// \brief Computes the dot product of the two 128-bit vectors of [4 x float]
end_comment

begin_comment
comment|///    and returns it in the elements of the 128-bit result vector of
end_comment

begin_comment
comment|///    [4 x float].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    The immediate integer operand controls which input elements
end_comment

begin_comment
comment|///    will contribute to the dot product, and where the final results are
end_comment

begin_comment
comment|///    returned.
end_comment

begin_comment
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
comment|/// __m128 _mm_dp_ps(__m128 X, __m128 Y, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VDPPS / DPPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \param Y
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An immediate integer operand. Mask bits [7:4] determine which elements
end_comment

begin_comment
comment|///    of the input vectors are used, with bit [4] corresponding to the lowest
end_comment

begin_comment
comment|///    element and bit [7] corresponding to the highest element of each [4 x
end_comment

begin_comment
comment|///    float] vector. If a bit is set, the corresponding elements from the two
end_comment

begin_comment
comment|///    input vectors are used as an input for dot product; otherwise that input
end_comment

begin_comment
comment|///    is treated as zero. Bits [3:0] determine which elements of the result
end_comment

begin_comment
comment|///    will receive a copy of the final dot product, with bit [0] corresponding
end_comment

begin_comment
comment|///    to the lowest element and bit [3] corresponding to the highest element of
end_comment

begin_comment
comment|///    each [4 x float] subvector. If a bit is set, the dot product is returned
end_comment

begin_comment
comment|///    in the corresponding element; otherwise that element is set to zero.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the dot product.
end_comment

begin_define
define|#
directive|define
name|_mm_dp_ps
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m128) __builtin_ia32_dpps((__v4sf)(__m128)(X), \                                (__v4sf)(__m128)(Y), (M)); })
end_define

begin_comment
comment|/// \brief Computes the dot product of the two 128-bit vectors of [2 x double]
end_comment

begin_comment
comment|///    and returns it in the elements of the 128-bit result vector of
end_comment

begin_comment
comment|///    [2 x double].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    The immediate integer operand controls which input
end_comment

begin_comment
comment|///    elements will contribute to the dot product, and where the final results
end_comment

begin_comment
comment|///    are returned.
end_comment

begin_comment
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
comment|/// __m128d _mm_dp_pd(__m128d X, __m128d Y, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VDPPD / DPPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param Y
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double].
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An immediate integer operand. Mask bits [5:4] determine which elements
end_comment

begin_comment
comment|///    of the input vectors are used, with bit [4] corresponding to the lowest
end_comment

begin_comment
comment|///    element and bit [5] corresponding to the highest element of each of [2 x
end_comment

begin_comment
comment|///    double] vector. If a bit is set, the corresponding elements from the two
end_comment

begin_comment
comment|///    input vectors are used as an input for dot product; otherwise that input
end_comment

begin_comment
comment|///    is treated as zero. Bits [1:0] determine which elements of the result
end_comment

begin_comment
comment|///    will receive a copy of the final dot product, with bit [0] corresponding
end_comment

begin_comment
comment|///    to the lowest element and bit [3] corresponding to the highest element of
end_comment

begin_comment
comment|///    each [2 x double] vector. If a bit is set, the dot product is returned in
end_comment

begin_comment
comment|///    the corresponding element; otherwise that element is set to zero.
end_comment

begin_define
define|#
directive|define
name|_mm_dp_pd
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({\   (__m128d) __builtin_ia32_dppd((__v2df)(__m128d)(X), \                                 (__v2df)(__m128d)(Y), (M)); })
end_define

begin_comment
comment|/* SSE4 Streaming Load Hint Instruction.  */
end_comment

begin_comment
comment|/// \brief Loads integer values from a 128-bit aligned memory location to a
end_comment

begin_comment
comment|///    128-bit integer vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVNTDQA / MOVNTDQA</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A pointer to a 128-bit aligned memory location that contains the integer
end_comment

begin_comment
comment|///    values.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the data stored at the
end_comment

begin_comment
comment|///    specified memory location.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_stream_load_si128
parameter_list|(
name|__m128i
specifier|const
modifier|*
name|__V
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_nontemporal_load
argument_list|(
operator|(
specifier|const
name|__v2di
operator|*
operator|)
name|__V
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* SSE4 Packed Integer Min/Max Instructions.  */
end_comment

begin_comment
comment|/// \brief Compares the corresponding elements of two 128-bit vectors of
end_comment

begin_comment
comment|///    [16 x i8] and returns a 128-bit vector of [16 x i8] containing the lesser
end_comment

begin_comment
comment|///    of the two values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMINSB / PMINSB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V1
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8].
end_comment

begin_comment
comment|/// \param __V2
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8]
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [16 x i8] containing the lesser values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_min_epi8
parameter_list|(
name|__m128i
name|__V1
parameter_list|,
name|__m128i
name|__V2
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pminsb128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__V1
argument_list|,
operator|(
name|__v16qi
operator|)
name|__V2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the corresponding elements of two 128-bit vectors of
end_comment

begin_comment
comment|///    [16 x i8] and returns a 128-bit vector of [16 x i8] containing the
end_comment

begin_comment
comment|///    greater value of the two.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMAXSB / PMAXSB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V1
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8].
end_comment

begin_comment
comment|/// \param __V2
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [16 x i8] containing the greater values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_max_epi8
parameter_list|(
name|__m128i
name|__V1
parameter_list|,
name|__m128i
name|__V2
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmaxsb128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__V1
argument_list|,
operator|(
name|__v16qi
operator|)
name|__V2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the corresponding elements of two 128-bit vectors of
end_comment

begin_comment
comment|///    [8 x u16] and returns a 128-bit vector of [8 x u16] containing the lesser
end_comment

begin_comment
comment|///    value of the two.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMINUW / PMINUW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V1
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x u16].
end_comment

begin_comment
comment|/// \param __V2
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x u16].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [8 x u16] containing the lesser values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_min_epu16
parameter_list|(
name|__m128i
name|__V1
parameter_list|,
name|__m128i
name|__V2
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pminuw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__V1
argument_list|,
operator|(
name|__v8hi
operator|)
name|__V2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the corresponding elements of two 128-bit vectors of
end_comment

begin_comment
comment|///    [8 x u16] and returns a 128-bit vector of [8 x u16] containing the
end_comment

begin_comment
comment|///    greater value of the two.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMAXUW / PMAXUW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V1
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x u16].
end_comment

begin_comment
comment|/// \param __V2
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x u16].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [8 x u16] containing the greater values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_max_epu16
parameter_list|(
name|__m128i
name|__V1
parameter_list|,
name|__m128i
name|__V2
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmaxuw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__V1
argument_list|,
operator|(
name|__v8hi
operator|)
name|__V2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the corresponding elements of two 128-bit vectors of
end_comment

begin_comment
comment|///    [4 x i32] and returns a 128-bit vector of [4 x i32] containing the lesser
end_comment

begin_comment
comment|///    value of the two.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMINSD / PMINSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V1
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x i32].
end_comment

begin_comment
comment|/// \param __V2
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x i32].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x i32] containing the lesser values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_min_epi32
parameter_list|(
name|__m128i
name|__V1
parameter_list|,
name|__m128i
name|__V2
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pminsd128
argument_list|(
operator|(
name|__v4si
operator|)
name|__V1
argument_list|,
operator|(
name|__v4si
operator|)
name|__V2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the corresponding elements of two 128-bit vectors of
end_comment

begin_comment
comment|///    [4 x i32] and returns a 128-bit vector of [4 x i32] containing the
end_comment

begin_comment
comment|///    greater value of the two.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMAXSD / PMAXSD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V1
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x i32].
end_comment

begin_comment
comment|/// \param __V2
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x i32].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x i32] containing the greater values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_max_epi32
parameter_list|(
name|__m128i
name|__V1
parameter_list|,
name|__m128i
name|__V2
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmaxsd128
argument_list|(
operator|(
name|__v4si
operator|)
name|__V1
argument_list|,
operator|(
name|__v4si
operator|)
name|__V2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the corresponding elements of two 128-bit vectors of
end_comment

begin_comment
comment|///    [4 x u32] and returns a 128-bit vector of [4 x u32] containing the lesser
end_comment

begin_comment
comment|///    value of the two.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMINUD / PMINUD</c>  instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V1
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x u32].
end_comment

begin_comment
comment|/// \param __V2
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x u32].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x u32] containing the lesser values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_min_epu32
parameter_list|(
name|__m128i
name|__V1
parameter_list|,
name|__m128i
name|__V2
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pminud128
argument_list|(
operator|(
name|__v4si
operator|)
name|__V1
argument_list|,
operator|(
name|__v4si
operator|)
name|__V2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the corresponding elements of two 128-bit vectors of
end_comment

begin_comment
comment|///    [4 x u32] and returns a 128-bit vector of [4 x u32] containing the
end_comment

begin_comment
comment|///    greater value of the two.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMAXUD / PMAXUD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V1
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x u32].
end_comment

begin_comment
comment|/// \param __V2
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x u32].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x u32] containing the greater values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_max_epu32
parameter_list|(
name|__m128i
name|__V1
parameter_list|,
name|__m128i
name|__V2
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmaxud128
argument_list|(
operator|(
name|__v4si
operator|)
name|__V1
argument_list|,
operator|(
name|__v4si
operator|)
name|__V2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* SSE4 Insertion and Extraction from XMM Register Instructions.  */
end_comment

begin_comment
comment|/// \brief Takes the first argument \a X and inserts an element from the second
end_comment

begin_comment
comment|///    argument \a Y as selected by the third argument \a N. That result then
end_comment

begin_comment
comment|///    has elements zeroed out also as selected by the third argument \a N. The
end_comment

begin_comment
comment|///    resulting 128-bit vector of [4 x float] is then returned.
end_comment

begin_comment
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
comment|/// __m128 _mm_insert_ps(__m128 X, __m128 Y, const int N);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VINSERTPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit vector source operand of [4 x float]. With the exception of
end_comment

begin_comment
comment|///    those bits in the result copied from parameter \a Y and zeroed by bits
end_comment

begin_comment
comment|///    [3:0] of \a N, all bits from this parameter are copied to the result.
end_comment

begin_comment
comment|/// \param Y
end_comment

begin_comment
comment|///    A 128-bit vector source operand of [4 x float]. One single-precision
end_comment

begin_comment
comment|///    floating-point element from this source, as determined by the immediate
end_comment

begin_comment
comment|///    parameter, is copied to the result.
end_comment

begin_comment
comment|/// \param N
end_comment

begin_comment
comment|///    Specifies which bits from operand \a Y will be copied, which bits in the
end_comment

begin_comment
comment|///    result they will be be copied to, and which bits in the result will be
end_comment

begin_comment
comment|///    cleared. The following assignments are made: \n
end_comment

begin_comment
comment|///    Bits [7:6] specify the bits to copy from operand \a Y: \n
end_comment

begin_comment
comment|///      00: Selects bits [31:0] from operand \a Y. \n
end_comment

begin_comment
comment|///      01: Selects bits [63:32] from operand \a Y. \n
end_comment

begin_comment
comment|///      10: Selects bits [95:64] from operand \a Y. \n
end_comment

begin_comment
comment|///      11: Selects bits [127:96] from operand \a Y. \n
end_comment

begin_comment
comment|///    Bits [5:4] specify the bits in the result to which the selected bits
end_comment

begin_comment
comment|///    from operand \a Y are copied: \n
end_comment

begin_comment
comment|///      00: Copies the selected bits from \a Y to result bits [31:0]. \n
end_comment

begin_comment
comment|///      01: Copies the selected bits from \a Y to result bits [63:32]. \n
end_comment

begin_comment
comment|///      10: Copies the selected bits from \a Y to result bits [95:64]. \n
end_comment

begin_comment
comment|///      11: Copies the selected bits from \a Y to result bits [127:96]. \n
end_comment

begin_comment
comment|///    Bits[3:0]: If any of these bits are set, the corresponding result
end_comment

begin_comment
comment|///    element is cleared.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the copied single-
end_comment

begin_comment
comment|///    precision floating point elements from the operands.
end_comment

begin_define
define|#
directive|define
name|_mm_insert_ps
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|N
parameter_list|)
value|__builtin_ia32_insertps128((X), (Y), (N))
end_define

begin_comment
comment|/// \brief Extracts a 32-bit integer from a 128-bit vector of [4 x float] and
end_comment

begin_comment
comment|///    returns it, using the immediate value parameter \a N as a selector.
end_comment

begin_comment
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
comment|/// int _mm_extract_ps(__m128 X, const int N);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VEXTRACTPS / EXTRACTPS</c>
end_comment

begin_comment
comment|/// instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \param N
end_comment

begin_comment
comment|///    An immediate value. Bits [1:0] determines which bits from the argument
end_comment

begin_comment
comment|///    \a X are extracted and returned: \n
end_comment

begin_comment
comment|///    00: Bits [31:0] of parameter \a X are returned. \n
end_comment

begin_comment
comment|///    01: Bits [63:32] of parameter \a X are returned. \n
end_comment

begin_comment
comment|///    10: Bits [95:64] of parameter \a X are returned. \n
end_comment

begin_comment
comment|///    11: Bits [127:96] of parameter \a X are returned.
end_comment

begin_comment
comment|/// \returns A 32-bit integer containing the extracted 32 bits of float data.
end_comment

begin_define
define|#
directive|define
name|_mm_extract_ps
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
value|(__extension__                      \                               ({ union { int __i; float __f; } __t;  \                                  __v4sf __a = (__v4sf)(__m128)(X);       \                                  __t.__f = __a[(N)& 3];                 \                                  __t.__i;}))
end_define

begin_comment
comment|/* Miscellaneous insert and extract macros.  */
end_comment

begin_comment
comment|/* Extract a single-precision float from X at index N into D.  */
end_comment

begin_define
define|#
directive|define
name|_MM_EXTRACT_FLOAT
parameter_list|(
name|D
parameter_list|,
name|X
parameter_list|,
name|N
parameter_list|)
value|(__extension__ ({ __v4sf __a = (__v4sf)(X); \                                                     (D) = __a[N]; }))
end_define

begin_comment
comment|/* Or together 2 sets of indexes (X and Y) with the zeroing bits (Z) to create    an index suitable for _mm_insert_ps.  */
end_comment

begin_define
define|#
directive|define
name|_MM_MK_INSERTPS_NDX
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|Z
parameter_list|)
value|(((X)<< 6) | ((Y)<< 4) | (Z))
end_define

begin_comment
comment|/* Extract a float from X at index N into the first index of the return.  */
end_comment

begin_define
define|#
directive|define
name|_MM_PICK_OUT_PS
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
value|_mm_insert_ps (_mm_setzero_ps(), (X),   \                                              _MM_MK_INSERTPS_NDX((N), 0, 0x0e))
end_define

begin_comment
comment|/* Insert int into packed integer array at index.  */
end_comment

begin_comment
comment|/// \brief Constructs a 128-bit vector of [16 x i8] by first making a copy of
end_comment

begin_comment
comment|///    the 128-bit integer vector parameter, and then inserting the lower 8 bits
end_comment

begin_comment
comment|///    of an integer parameter \a I into an offset specified by the immediate
end_comment

begin_comment
comment|///    value parameter \a N.
end_comment

begin_comment
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
comment|/// __m128i _mm_insert_epi8(__m128i X, int I, const int N);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPINSRB / PINSRB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit integer vector of [16 x i8]. This vector is copied to the
end_comment

begin_comment
comment|///    result and then one of the sixteen elements in the result vector is
end_comment

begin_comment
comment|///    replaced by the lower 8 bits of \a I.
end_comment

begin_comment
comment|/// \param I
end_comment

begin_comment
comment|///    An integer. The lower 8 bits of this operand are written to the result
end_comment

begin_comment
comment|///    beginning at the offset specified by \a N.
end_comment

begin_comment
comment|/// \param N
end_comment

begin_comment
comment|///    An immediate value. Bits [3:0] specify the bit offset in the result at
end_comment

begin_comment
comment|///    which the lower 8 bits of \a I are written. \n
end_comment

begin_comment
comment|///    0000: Bits [7:0] of the result are used for insertion. \n
end_comment

begin_comment
comment|///    0001: Bits [15:8] of the result are used for insertion. \n
end_comment

begin_comment
comment|///    0010: Bits [23:16] of the result are used for insertion. \n
end_comment

begin_comment
comment|///    0011: Bits [31:24] of the result are used for insertion. \n
end_comment

begin_comment
comment|///    0100: Bits [39:32] of the result are used for insertion. \n
end_comment

begin_comment
comment|///    0101: Bits [47:40] of the result are used for insertion. \n
end_comment

begin_comment
comment|///    0110: Bits [55:48] of the result are used for insertion. \n
end_comment

begin_comment
comment|///    0111: Bits [63:56] of the result are used for insertion. \n
end_comment

begin_comment
comment|///    1000: Bits [71:64] of the result are used for insertion. \n
end_comment

begin_comment
comment|///    1001: Bits [79:72] of the result are used for insertion. \n
end_comment

begin_comment
comment|///    1010: Bits [87:80] of the result are used for insertion. \n
end_comment

begin_comment
comment|///    1011: Bits [95:88] of the result are used for insertion. \n
end_comment

begin_comment
comment|///    1100: Bits [103:96] of the result are used for insertion. \n
end_comment

begin_comment
comment|///    1101: Bits [111:104] of the result are used for insertion. \n
end_comment

begin_comment
comment|///    1110: Bits [119:112] of the result are used for insertion. \n
end_comment

begin_comment
comment|///    1111: Bits [127:120] of the result are used for insertion.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the constructed values.
end_comment

begin_define
define|#
directive|define
name|_mm_insert_epi8
parameter_list|(
name|X
parameter_list|,
name|I
parameter_list|,
name|N
parameter_list|)
value|(__extension__                           \                                   ({ __v16qi __a = (__v16qi)(__m128i)(X); \                                      __a[(N)& 15] = (I);                 \                                      (__m128i)__a;}))
end_define

begin_comment
comment|/// \brief Constructs a 128-bit vector of [4 x i32] by first making a copy of
end_comment

begin_comment
comment|///    the 128-bit integer vector parameter, and then inserting the 32-bit
end_comment

begin_comment
comment|///    integer parameter \a I at the offset specified by the immediate value
end_comment

begin_comment
comment|///    parameter \a N.
end_comment

begin_comment
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
comment|/// __m128i _mm_insert_epi32(__m128i X, int I, const int N);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPINSRD / PINSRD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit integer vector of [4 x i32]. This vector is copied to the
end_comment

begin_comment
comment|///    result and then one of the four elements in the result vector is
end_comment

begin_comment
comment|///    replaced by \a I.
end_comment

begin_comment
comment|/// \param I
end_comment

begin_comment
comment|///    A 32-bit integer that is written to the result beginning at the offset
end_comment

begin_comment
comment|///    specified by \a N.
end_comment

begin_comment
comment|/// \param N
end_comment

begin_comment
comment|///    An immediate value. Bits [1:0] specify the bit offset in the result at
end_comment

begin_comment
comment|///    which the integer \a I is written. \n
end_comment

begin_comment
comment|///    00: Bits [31:0] of the result are used for insertion. \n
end_comment

begin_comment
comment|///    01: Bits [63:32] of the result are used for insertion. \n
end_comment

begin_comment
comment|///    10: Bits [95:64] of the result are used for insertion. \n
end_comment

begin_comment
comment|///    11: Bits [127:96] of the result are used for insertion.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the constructed values.
end_comment

begin_define
define|#
directive|define
name|_mm_insert_epi32
parameter_list|(
name|X
parameter_list|,
name|I
parameter_list|,
name|N
parameter_list|)
value|(__extension__                         \                                    ({ __v4si __a = (__v4si)(__m128i)(X); \                                       __a[(N)& 3] = (I);                \                                       (__m128i)__a;}))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_comment
comment|/// \brief Constructs a 128-bit vector of [2 x i64] by first making a copy of
end_comment

begin_comment
comment|///    the 128-bit integer vector parameter, and then inserting the 64-bit
end_comment

begin_comment
comment|///    integer parameter \a I, using the immediate value parameter \a N as an
end_comment

begin_comment
comment|///    insertion location selector.
end_comment

begin_comment
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
comment|/// __m128i _mm_insert_epi64(__m128i X, long long I, const int N);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPINSRQ / PINSRQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit integer vector of [2 x i64]. This vector is copied to the
end_comment

begin_comment
comment|///    result and then one of the two elements in the result vector is replaced
end_comment

begin_comment
comment|///    by \a I.
end_comment

begin_comment
comment|/// \param I
end_comment

begin_comment
comment|///    A 64-bit integer that is written to the result beginning at the offset
end_comment

begin_comment
comment|///    specified by \a N.
end_comment

begin_comment
comment|/// \param N
end_comment

begin_comment
comment|///    An immediate value. Bit [0] specifies the bit offset in the result at
end_comment

begin_comment
comment|///    which the integer \a I is written. \n
end_comment

begin_comment
comment|///    0: Bits [63:0] of the result are used for insertion. \n
end_comment

begin_comment
comment|///    1: Bits [127:64] of the result are used for insertion. \n
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the constructed values.
end_comment

begin_define
define|#
directive|define
name|_mm_insert_epi64
parameter_list|(
name|X
parameter_list|,
name|I
parameter_list|,
name|N
parameter_list|)
value|(__extension__                         \                                    ({ __v2di __a = (__v2di)(__m128i)(X); \                                       __a[(N)& 1] = (I);                \                                       (__m128i)__a;}))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __x86_64__ */
end_comment

begin_comment
comment|/* Extract int from packed integer array at index.  This returns the element  * as a zero extended value, so it is unsigned.  */
end_comment

begin_comment
comment|/// \brief Extracts an 8-bit element from the 128-bit integer vector of
end_comment

begin_comment
comment|///    [16 x i8], using the immediate value parameter \a N as a selector.
end_comment

begin_comment
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
comment|/// int _mm_extract_epi8(__m128i X, const int N);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPEXTRB / PEXTRB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param N
end_comment

begin_comment
comment|///    An immediate value. Bits [3:0] specify which 8-bit vector element from
end_comment

begin_comment
comment|///    the argument \a X to extract and copy to the result. \n
end_comment

begin_comment
comment|///    0000: Bits [7:0] of parameter \a X are extracted. \n
end_comment

begin_comment
comment|///    0001: Bits [15:8] of the parameter \a X are extracted. \n
end_comment

begin_comment
comment|///    0010: Bits [23:16] of the parameter \a X are extracted. \n
end_comment

begin_comment
comment|///    0011: Bits [31:24] of the parameter \a X are extracted. \n
end_comment

begin_comment
comment|///    0100: Bits [39:32] of the parameter \a X are extracted. \n
end_comment

begin_comment
comment|///    0101: Bits [47:40] of the parameter \a X are extracted. \n
end_comment

begin_comment
comment|///    0110: Bits [55:48] of the parameter \a X are extracted. \n
end_comment

begin_comment
comment|///    0111: Bits [63:56] of the parameter \a X are extracted. \n
end_comment

begin_comment
comment|///    1000: Bits [71:64] of the parameter \a X are extracted. \n
end_comment

begin_comment
comment|///    1001: Bits [79:72] of the parameter \a X are extracted. \n
end_comment

begin_comment
comment|///    1010: Bits [87:80] of the parameter \a X are extracted. \n
end_comment

begin_comment
comment|///    1011: Bits [95:88] of the parameter \a X are extracted. \n
end_comment

begin_comment
comment|///    1100: Bits [103:96] of the parameter \a X are extracted. \n
end_comment

begin_comment
comment|///    1101: Bits [111:104] of the parameter \a X are extracted. \n
end_comment

begin_comment
comment|///    1110: Bits [119:112] of the parameter \a X are extracted. \n
end_comment

begin_comment
comment|///    1111: Bits [127:120] of the parameter \a X are extracted.
end_comment

begin_comment
comment|/// \returns  An unsigned integer, whose lower 8 bits are selected from the
end_comment

begin_comment
comment|///    128-bit integer vector parameter and the remaining bits are assigned
end_comment

begin_comment
comment|///    zeros.
end_comment

begin_define
define|#
directive|define
name|_mm_extract_epi8
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
value|(__extension__                           \                                 ({ __v16qi __a = (__v16qi)(__m128i)(X); \                                    (int)(unsigned char) __a[(N)& 15];}))
end_define

begin_comment
comment|/// \brief Extracts a 32-bit element from the 128-bit integer vector of
end_comment

begin_comment
comment|///    [4 x i32], using the immediate value parameter \a N as a selector.
end_comment

begin_comment
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
comment|/// int _mm_extract_epi32(__m128i X, const int N);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPEXTRD / PEXTRD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param N
end_comment

begin_comment
comment|///    An immediate value. Bits [1:0] specify which 32-bit vector element from
end_comment

begin_comment
comment|///    the argument \a X to extract and copy to the result. \n
end_comment

begin_comment
comment|///    00: Bits [31:0] of the parameter \a X are extracted. \n
end_comment

begin_comment
comment|///    01: Bits [63:32] of the parameter \a X are extracted. \n
end_comment

begin_comment
comment|///    10: Bits [95:64] of the parameter \a X are extracted. \n
end_comment

begin_comment
comment|///    11: Bits [127:96] of the parameter \a X are exracted.
end_comment

begin_comment
comment|/// \returns  An integer, whose lower 32 bits are selected from the 128-bit
end_comment

begin_comment
comment|///    integer vector parameter and the remaining bits are assigned zeros.
end_comment

begin_define
define|#
directive|define
name|_mm_extract_epi32
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
value|(__extension__                         \                                  ({ __v4si __a = (__v4si)(__m128i)(X); \                                     (int)__a[(N)& 3];}))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_comment
comment|/// \brief Extracts a 64-bit element from the 128-bit integer vector of
end_comment

begin_comment
comment|///    [2 x i64], using the immediate value parameter \a N as a selector.
end_comment

begin_comment
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
comment|/// long long _mm_extract_epi64(__m128i X, const int N);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPEXTRQ / PEXTRQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param N
end_comment

begin_comment
comment|///    An immediate value. Bit [0] specifies which 64-bit vector element from
end_comment

begin_comment
comment|///    the argument \a X to return. \n
end_comment

begin_comment
comment|///    0: Bits [63:0] are returned. \n
end_comment

begin_comment
comment|///    1: Bits [127:64] are returned. \n
end_comment

begin_comment
comment|/// \returns  A 64-bit integer.
end_comment

begin_define
define|#
directive|define
name|_mm_extract_epi64
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
value|(__extension__                         \                                  ({ __v2di __a = (__v2di)(__m128i)(X); \                                     (long long)__a[(N)& 1];}))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __x86_64 */
end_comment

begin_comment
comment|/* SSE4 128-bit Packed Integer Comparisons.  */
end_comment

begin_comment
comment|/// \brief Tests whether the specified bits in a 128-bit integer vector are all
end_comment

begin_comment
comment|///    zeros.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPTEST / PTEST</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __M
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the bits to be tested.
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit integer vector selecting which bits to test in operand \a __M.
end_comment

begin_comment
comment|/// \returns TRUE if the specified bits are all zeros; FALSE otherwise.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_testz_si128
parameter_list|(
name|__m128i
name|__M
parameter_list|,
name|__m128i
name|__V
parameter_list|)
block|{
return|return
name|__builtin_ia32_ptestz128
argument_list|(
operator|(
name|__v2di
operator|)
name|__M
argument_list|,
operator|(
name|__v2di
operator|)
name|__V
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Tests whether the specified bits in a 128-bit integer vector are all
end_comment

begin_comment
comment|///    ones.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPTEST / PTEST</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __M
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the bits to be tested.
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit integer vector selecting which bits to test in operand \a __M.
end_comment

begin_comment
comment|/// \returns TRUE if the specified bits are all ones; FALSE otherwise.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_testc_si128
parameter_list|(
name|__m128i
name|__M
parameter_list|,
name|__m128i
name|__V
parameter_list|)
block|{
return|return
name|__builtin_ia32_ptestc128
argument_list|(
operator|(
name|__v2di
operator|)
name|__M
argument_list|,
operator|(
name|__v2di
operator|)
name|__V
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Tests whether the specified bits in a 128-bit integer vector are
end_comment

begin_comment
comment|///    neither all zeros nor all ones.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPTEST / PTEST</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __M
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the bits to be tested.
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit integer vector selecting which bits to test in operand \a __M.
end_comment

begin_comment
comment|/// \returns TRUE if the specified bits are neither all zeros nor all ones;
end_comment

begin_comment
comment|///    FALSE otherwise.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_testnzc_si128
parameter_list|(
name|__m128i
name|__M
parameter_list|,
name|__m128i
name|__V
parameter_list|)
block|{
return|return
name|__builtin_ia32_ptestnzc128
argument_list|(
operator|(
name|__v2di
operator|)
name|__M
argument_list|,
operator|(
name|__v2di
operator|)
name|__V
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Tests whether the specified bits in a 128-bit integer vector are all
end_comment

begin_comment
comment|///    ones.
end_comment

begin_comment
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
comment|/// int _mm_test_all_ones(__m128i V);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPTEST / PTEST</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param V
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the bits to be tested.
end_comment

begin_comment
comment|/// \returns TRUE if the bits specified in the operand are all set to 1; FALSE
end_comment

begin_comment
comment|///    otherwise.
end_comment

begin_define
define|#
directive|define
name|_mm_test_all_ones
parameter_list|(
name|V
parameter_list|)
value|_mm_testc_si128((V), _mm_cmpeq_epi32((V), (V)))
end_define

begin_comment
comment|/// \brief Tests whether the specified bits in a 128-bit integer vector are
end_comment

begin_comment
comment|///    neither all zeros nor all ones.
end_comment

begin_comment
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
comment|/// int _mm_test_mix_ones_zeros(__m128i M, __m128i V);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPTEST / PTEST</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the bits to be tested.
end_comment

begin_comment
comment|/// \param V
end_comment

begin_comment
comment|///    A 128-bit integer vector selecting which bits to test in operand \a M.
end_comment

begin_comment
comment|/// \returns TRUE if the specified bits are neither all zeros nor all ones;
end_comment

begin_comment
comment|///    FALSE otherwise.
end_comment

begin_define
define|#
directive|define
name|_mm_test_mix_ones_zeros
parameter_list|(
name|M
parameter_list|,
name|V
parameter_list|)
value|_mm_testnzc_si128((M), (V))
end_define

begin_comment
comment|/// \brief Tests whether the specified bits in a 128-bit integer vector are all
end_comment

begin_comment
comment|///    zeros.
end_comment

begin_comment
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
comment|/// int _mm_test_all_zeros(__m128i M, __m128i V);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPTEST / PTEST</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the bits to be tested.
end_comment

begin_comment
comment|/// \param V
end_comment

begin_comment
comment|///    A 128-bit integer vector selecting which bits to test in operand \a M.
end_comment

begin_comment
comment|/// \returns TRUE if the specified bits are all zeros; FALSE otherwise.
end_comment

begin_define
define|#
directive|define
name|_mm_test_all_zeros
parameter_list|(
name|M
parameter_list|,
name|V
parameter_list|)
value|_mm_testz_si128 ((M), (V))
end_define

begin_comment
comment|/* SSE4 64-bit Packed Integer Comparisons.  */
end_comment

begin_comment
comment|/// \brief Compares each of the corresponding 64-bit values of the 128-bit
end_comment

begin_comment
comment|///    integer vectors for equality.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPEQQ / PCMPEQQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V1
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __V2
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
name|_mm_cmpeq_epi64
parameter_list|(
name|__m128i
name|__V1
parameter_list|,
name|__m128i
name|__V2
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v2di
operator|)
name|__V1
operator|==
operator|(
name|__v2di
operator|)
name|__V2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* SSE4 Packed Integer Sign-Extension.  */
end_comment

begin_comment
comment|/// \brief Sign-extends each of the lower eight 8-bit integer elements of a
end_comment

begin_comment
comment|///    128-bit vector of [16 x i8] to 16-bit values and returns them in a
end_comment

begin_comment
comment|///    128-bit vector of [8 x i16]. The upper eight elements of the input vector
end_comment

begin_comment
comment|///    are unused.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMOVSXBW / PMOVSXBW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8]. The lower eight 8-bit elements are sign-
end_comment

begin_comment
comment|///    extended to 16-bit values.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [8 x i16] containing the sign-extended values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvtepi8_epi16
parameter_list|(
name|__m128i
name|__V
parameter_list|)
block|{
comment|/* This function always performs a signed extension, but __v16qi is a char      which may be signed or unsigned, so use __v16qs. */
return|return
operator|(
name|__m128i
operator|)
name|__builtin_convertvector
argument_list|(
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v16qs
operator|)
name|__V
argument_list|,
operator|(
name|__v16qs
operator|)
name|__V
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
argument_list|,
name|__v8hi
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Sign-extends each of the lower four 8-bit integer elements of a
end_comment

begin_comment
comment|///    128-bit vector of [16 x i8] to 32-bit values and returns them in a
end_comment

begin_comment
comment|///    128-bit vector of [4 x i32]. The upper twelve elements of the input
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
comment|/// This intrinsic corresponds to the<c> VPMOVSXBD / PMOVSXBD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8]. The lower four 8-bit elements are sign-
end_comment

begin_comment
comment|///    extended to 32-bit values.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x i32] containing the sign-extended values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvtepi8_epi32
parameter_list|(
name|__m128i
name|__V
parameter_list|)
block|{
comment|/* This function always performs a signed extension, but __v16qi is a char      which may be signed or unsigned, so use __v16qs. */
return|return
operator|(
name|__m128i
operator|)
name|__builtin_convertvector
argument_list|(
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v16qs
operator|)
name|__V
argument_list|,
operator|(
name|__v16qs
operator|)
name|__V
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
argument_list|,
name|__v4si
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Sign-extends each of the lower two 8-bit integer elements of a
end_comment

begin_comment
comment|///    128-bit integer vector of [16 x i8] to 64-bit values and returns them in
end_comment

begin_comment
comment|///    a 128-bit vector of [2 x i64]. The upper fourteen elements of the input
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
comment|/// This intrinsic corresponds to the<c> VPMOVSXBQ / PMOVSXBQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8]. The lower two 8-bit elements are sign-
end_comment

begin_comment
comment|///    extended to 64-bit values.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x i64] containing the sign-extended values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvtepi8_epi64
parameter_list|(
name|__m128i
name|__V
parameter_list|)
block|{
comment|/* This function always performs a signed extension, but __v16qi is a char      which may be signed or unsigned, so use __v16qs. */
return|return
operator|(
name|__m128i
operator|)
name|__builtin_convertvector
argument_list|(
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v16qs
operator|)
name|__V
argument_list|,
operator|(
name|__v16qs
operator|)
name|__V
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|,
name|__v2di
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Sign-extends each of the lower four 16-bit integer elements of a
end_comment

begin_comment
comment|///    128-bit integer vector of [8 x i16] to 32-bit values and returns them in
end_comment

begin_comment
comment|///    a 128-bit vector of [4 x i32]. The upper four elements of the input
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
comment|/// This intrinsic corresponds to the<c> VPMOVSXWD / PMOVSXWD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16]. The lower four 16-bit elements are sign-
end_comment

begin_comment
comment|///    extended to 32-bit values.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x i32] containing the sign-extended values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvtepi16_epi32
parameter_list|(
name|__m128i
name|__V
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_convertvector
argument_list|(
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v8hi
operator|)
name|__V
argument_list|,
operator|(
name|__v8hi
operator|)
name|__V
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
argument_list|,
name|__v4si
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Sign-extends each of the lower two 16-bit integer elements of a
end_comment

begin_comment
comment|///    128-bit integer vector of [8 x i16] to 64-bit values and returns them in
end_comment

begin_comment
comment|///    a 128-bit vector of [2 x i64]. The upper six elements of the input
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
comment|/// This intrinsic corresponds to the<c> VPMOVSXWQ / PMOVSXWQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16]. The lower two 16-bit elements are sign-
end_comment

begin_comment
comment|///    extended to 64-bit values.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x i64] containing the sign-extended values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvtepi16_epi64
parameter_list|(
name|__m128i
name|__V
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_convertvector
argument_list|(
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v8hi
operator|)
name|__V
argument_list|,
operator|(
name|__v8hi
operator|)
name|__V
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|,
name|__v2di
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Sign-extends each of the lower two 32-bit integer elements of a
end_comment

begin_comment
comment|///    128-bit integer vector of [4 x i32] to 64-bit values and returns them in
end_comment

begin_comment
comment|///    a 128-bit vector of [2 x i64]. The upper two elements of the input vector
end_comment

begin_comment
comment|///    are unused.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMOVSXDQ / PMOVSXDQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x i32]. The lower two 32-bit elements are sign-
end_comment

begin_comment
comment|///    extended to 64-bit values.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x i64] containing the sign-extended values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvtepi32_epi64
parameter_list|(
name|__m128i
name|__V
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_convertvector
argument_list|(
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v4si
operator|)
name|__V
argument_list|,
operator|(
name|__v4si
operator|)
name|__V
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|,
name|__v2di
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* SSE4 Packed Integer Zero-Extension.  */
end_comment

begin_comment
comment|/// \brief Zero-extends each of the lower eight 8-bit integer elements of a
end_comment

begin_comment
comment|///    128-bit vector of [16 x i8] to 16-bit values and returns them in a
end_comment

begin_comment
comment|///    128-bit vector of [8 x i16]. The upper eight elements of the input vector
end_comment

begin_comment
comment|///    are unused.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMOVZXBW / PMOVZXBW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8]. The lower eight 8-bit elements are zero-
end_comment

begin_comment
comment|///    extended to 16-bit values.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [8 x i16] containing the zero-extended values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvtepu8_epi16
parameter_list|(
name|__m128i
name|__V
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_convertvector
argument_list|(
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v16qu
operator|)
name|__V
argument_list|,
operator|(
name|__v16qu
operator|)
name|__V
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
argument_list|,
name|__v8hi
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Zero-extends each of the lower four 8-bit integer elements of a
end_comment

begin_comment
comment|///    128-bit vector of [16 x i8] to 32-bit values and returns them in a
end_comment

begin_comment
comment|///    128-bit vector of [4 x i32]. The upper twelve elements of the input
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
comment|/// This intrinsic corresponds to the<c> VPMOVZXBD / PMOVZXBD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8]. The lower four 8-bit elements are zero-
end_comment

begin_comment
comment|///    extended to 32-bit values.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x i32] containing the zero-extended values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvtepu8_epi32
parameter_list|(
name|__m128i
name|__V
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_convertvector
argument_list|(
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v16qu
operator|)
name|__V
argument_list|,
operator|(
name|__v16qu
operator|)
name|__V
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
argument_list|,
name|__v4si
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Zero-extends each of the lower two 8-bit integer elements of a
end_comment

begin_comment
comment|///    128-bit integer vector of [16 x i8] to 64-bit values and returns them in
end_comment

begin_comment
comment|///    a 128-bit vector of [2 x i64]. The upper fourteen elements of the input
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
comment|/// This intrinsic corresponds to the<c> VPMOVZXBQ / PMOVZXBQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8]. The lower two 8-bit elements are zero-
end_comment

begin_comment
comment|///    extended to 64-bit values.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x i64] containing the zero-extended values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvtepu8_epi64
parameter_list|(
name|__m128i
name|__V
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_convertvector
argument_list|(
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v16qu
operator|)
name|__V
argument_list|,
operator|(
name|__v16qu
operator|)
name|__V
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|,
name|__v2di
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Zero-extends each of the lower four 16-bit integer elements of a
end_comment

begin_comment
comment|///    128-bit integer vector of [8 x i16] to 32-bit values and returns them in
end_comment

begin_comment
comment|///    a 128-bit vector of [4 x i32]. The upper four elements of the input
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
comment|/// This intrinsic corresponds to the<c> VPMOVZXWD / PMOVZXWD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16]. The lower four 16-bit elements are zero-
end_comment

begin_comment
comment|///    extended to 32-bit values.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x i32] containing the zero-extended values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvtepu16_epi32
parameter_list|(
name|__m128i
name|__V
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_convertvector
argument_list|(
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v8hu
operator|)
name|__V
argument_list|,
operator|(
name|__v8hu
operator|)
name|__V
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
argument_list|,
name|__v4si
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Zero-extends each of the lower two 16-bit integer elements of a
end_comment

begin_comment
comment|///    128-bit integer vector of [8 x i16] to 64-bit values and returns them in
end_comment

begin_comment
comment|///    a 128-bit vector of [2 x i64]. The upper six elements of the input vector
end_comment

begin_comment
comment|///    are unused.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMOVZXWQ / PMOVZXWQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x i16]. The lower two 16-bit elements are zero-
end_comment

begin_comment
comment|///    extended to 64-bit values.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x i64] containing the zero-extended values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvtepu16_epi64
parameter_list|(
name|__m128i
name|__V
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_convertvector
argument_list|(
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v8hu
operator|)
name|__V
argument_list|,
operator|(
name|__v8hu
operator|)
name|__V
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|,
name|__v2di
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Zero-extends each of the lower two 32-bit integer elements of a
end_comment

begin_comment
comment|///    128-bit integer vector of [4 x i32] to 64-bit values and returns them in
end_comment

begin_comment
comment|///    a 128-bit vector of [2 x i64]. The upper two elements of the input vector
end_comment

begin_comment
comment|///    are unused.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPMOVZXDQ / PMOVZXDQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x i32]. The lower two 32-bit elements are zero-
end_comment

begin_comment
comment|///    extended to 64-bit values.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x i64] containing the zero-extended values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvtepu32_epi64
parameter_list|(
name|__m128i
name|__V
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_convertvector
argument_list|(
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v4su
operator|)
name|__V
argument_list|,
operator|(
name|__v4su
operator|)
name|__V
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|,
name|__v2di
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* SSE4 Pack with Unsigned Saturation.  */
end_comment

begin_comment
comment|/// \brief Converts 32-bit signed integers from both 128-bit integer vector
end_comment

begin_comment
comment|///    operands into 16-bit unsigned integers, and returns the packed result.
end_comment

begin_comment
comment|///    Values greater than 0xFFFF are saturated to 0xFFFF. Values less than
end_comment

begin_comment
comment|///    0x0000 are saturated to 0x0000.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPACKUSDW / PACKUSDW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V1
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x i32]. Each 32-bit element is treated as a
end_comment

begin_comment
comment|///    signed integer and is converted to a 16-bit unsigned integer with
end_comment

begin_comment
comment|///    saturation. Values greater than 0xFFFF are saturated to 0xFFFF. Values
end_comment

begin_comment
comment|///    less than 0x0000 are saturated to 0x0000. The converted [4 x i16] values
end_comment

begin_comment
comment|///    are written to the lower 64 bits of the result.
end_comment

begin_comment
comment|/// \param __V2
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x i32]. Each 32-bit element is treated as a
end_comment

begin_comment
comment|///    signed integer and is converted to a 16-bit unsigned integer with
end_comment

begin_comment
comment|///    saturation. Values greater than 0xFFFF are saturated to 0xFFFF. Values
end_comment

begin_comment
comment|///    less than 0x0000 are saturated to 0x0000. The converted [4 x i16] values
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
name|_mm_packus_epi32
parameter_list|(
name|__m128i
name|__V1
parameter_list|,
name|__m128i
name|__V2
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_packusdw128
argument_list|(
operator|(
name|__v4si
operator|)
name|__V1
argument_list|,
operator|(
name|__v4si
operator|)
name|__V2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* SSE4 Multiple Packed Sums of Absolute Difference.  */
end_comment

begin_comment
comment|/// \brief Subtracts 8-bit unsigned integer values and computes the absolute
end_comment

begin_comment
comment|///    values of the differences to the corresponding bits in the destination.
end_comment

begin_comment
comment|///    Then sums of the absolute differences are returned according to the bit
end_comment

begin_comment
comment|///    fields in the immediate operand.
end_comment

begin_comment
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
comment|/// __m128i _mm_mpsadbw_epu8(__m128i X, __m128i Y, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMPSADBW / MPSADBW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8].
end_comment

begin_comment
comment|/// \param Y
end_comment

begin_comment
comment|///    A 128-bit vector of [16 x i8].
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An 8-bit immediate operand specifying how the absolute differences are to
end_comment

begin_comment
comment|///    be calculated, according to the following algorithm:
end_comment

begin_comment
comment|///    \code
end_comment

begin_comment
comment|///    // M2 represents bit 2 of the immediate operand
end_comment

begin_comment
comment|///    // M10 represents bits [1:0] of the immediate operand
end_comment

begin_comment
comment|///    i = M2 * 4
end_comment

begin_comment
comment|///    j = M10 * 4
end_comment

begin_comment
comment|///    for (k = 0; k< 8; k = k + 1) {
end_comment

begin_comment
comment|///      d0 = abs(X[i + k + 0] - Y[j + 0])
end_comment

begin_comment
comment|///      d1 = abs(X[i + k + 1] - Y[j + 1])
end_comment

begin_comment
comment|///      d2 = abs(X[i + k + 2] - Y[j + 2])
end_comment

begin_comment
comment|///      d3 = abs(X[i + k + 3] - Y[j + 3])
end_comment

begin_comment
comment|///      r[k] = d0 + d1 + d2 + d3
end_comment

begin_comment
comment|///    }
end_comment

begin_comment
comment|///    \endcode
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the sums of the sets of
end_comment

begin_comment
comment|///    absolute differences between both operands.
end_comment

begin_define
define|#
directive|define
name|_mm_mpsadbw_epu8
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   (__m128i) __builtin_ia32_mpsadbw128((__v16qi)(__m128i)(X), \                                       (__v16qi)(__m128i)(Y), (M)); })
end_define

begin_comment
comment|/// \brief Finds the minimum unsigned 16-bit element in the input 128-bit
end_comment

begin_comment
comment|///    vector of [8 x u16] and returns it and along with its index.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPHMINPOSUW / PHMINPOSUW</c>
end_comment

begin_comment
comment|/// instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit vector of [8 x u16].
end_comment

begin_comment
comment|/// \returns A 128-bit value where bits [15:0] contain the minimum value found
end_comment

begin_comment
comment|///    in parameter \a __V, bits [18:16] contain the index of the minimum value
end_comment

begin_comment
comment|///    and the remaining bits are set to 0.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_minpos_epu16
parameter_list|(
name|__m128i
name|__V
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_phminposuw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__V
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Handle the sse4.2 definitions here. */
end_comment

begin_comment
comment|/* These definitions are normally in nmmintrin.h, but gcc puts them in here    so we'll do the same.  */
end_comment

begin_undef
undef|#
directive|undef
name|__DEFAULT_FN_ATTRS
end_undef

begin_define
define|#
directive|define
name|__DEFAULT_FN_ATTRS
value|__attribute__((__always_inline__, __nodebug__, __target__("sse4.2")))
end_define

begin_comment
comment|/* These specify the type of data that we're comparing.  */
end_comment

begin_define
define|#
directive|define
name|_SIDD_UBYTE_OPS
value|0x00
end_define

begin_define
define|#
directive|define
name|_SIDD_UWORD_OPS
value|0x01
end_define

begin_define
define|#
directive|define
name|_SIDD_SBYTE_OPS
value|0x02
end_define

begin_define
define|#
directive|define
name|_SIDD_SWORD_OPS
value|0x03
end_define

begin_comment
comment|/* These specify the type of comparison operation.  */
end_comment

begin_define
define|#
directive|define
name|_SIDD_CMP_EQUAL_ANY
value|0x00
end_define

begin_define
define|#
directive|define
name|_SIDD_CMP_RANGES
value|0x04
end_define

begin_define
define|#
directive|define
name|_SIDD_CMP_EQUAL_EACH
value|0x08
end_define

begin_define
define|#
directive|define
name|_SIDD_CMP_EQUAL_ORDERED
value|0x0c
end_define

begin_comment
comment|/* These macros specify the polarity of the operation.  */
end_comment

begin_define
define|#
directive|define
name|_SIDD_POSITIVE_POLARITY
value|0x00
end_define

begin_define
define|#
directive|define
name|_SIDD_NEGATIVE_POLARITY
value|0x10
end_define

begin_define
define|#
directive|define
name|_SIDD_MASKED_POSITIVE_POLARITY
value|0x20
end_define

begin_define
define|#
directive|define
name|_SIDD_MASKED_NEGATIVE_POLARITY
value|0x30
end_define

begin_comment
comment|/* These macros are used in _mm_cmpXstri() to specify the return.  */
end_comment

begin_define
define|#
directive|define
name|_SIDD_LEAST_SIGNIFICANT
value|0x00
end_define

begin_define
define|#
directive|define
name|_SIDD_MOST_SIGNIFICANT
value|0x40
end_define

begin_comment
comment|/* These macros are used in _mm_cmpXstri() to specify the return.  */
end_comment

begin_define
define|#
directive|define
name|_SIDD_BIT_MASK
value|0x00
end_define

begin_define
define|#
directive|define
name|_SIDD_UNIT_MASK
value|0x40
end_define

begin_comment
comment|/* SSE4.2 Packed Comparison Intrinsics.  */
end_comment

begin_comment
comment|/// \brief Uses the immediate operand \a M to perform a comparison of string
end_comment

begin_comment
comment|///    data with implicitly defined lengths that is contained in source operands
end_comment

begin_comment
comment|///    \a A and \a B. Returns a 128-bit integer vector representing the result
end_comment

begin_comment
comment|///    mask of the comparison.
end_comment

begin_comment
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
comment|/// __m128i _mm_cmpistrm(__m128i A, __m128i B, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPISTRM / PCMPISTRM</c>
end_comment

begin_comment
comment|/// instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param A
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param B
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An 8-bit immediate operand specifying whether the characters are bytes or
end_comment

begin_comment
comment|///    words, the type of comparison to perform, and the format of the return
end_comment

begin_comment
comment|///    value. \n
end_comment

begin_comment
comment|///    Bits [1:0]: Determine source data format. \n
end_comment

begin_comment
comment|///      00: 16 unsigned bytes \n
end_comment

begin_comment
comment|///      01: 8 unsigned words \n
end_comment

begin_comment
comment|///      10: 16 signed bytes \n
end_comment

begin_comment
comment|///      11: 8 signed words \n
end_comment

begin_comment
comment|///    Bits [3:2]: Determine comparison type and aggregation method. \n
end_comment

begin_comment
comment|///      00: Subset: Each character in \a B is compared for equality with all
end_comment

begin_comment
comment|///          the characters in \a A. \n
end_comment

begin_comment
comment|///      01: Ranges: Each character in \a B is compared to \a A. The comparison
end_comment

begin_comment
comment|///          basis is greater than or equal for even-indexed elements in \a A,
end_comment

begin_comment
comment|///          and less than or equal for odd-indexed elements in \a A. \n
end_comment

begin_comment
comment|///      10: Match: Compare each pair of corresponding characters in \a A and
end_comment

begin_comment
comment|///          \a B for equality. \n
end_comment

begin_comment
comment|///      11: Substring: Search \a B for substring matches of \a A. \n
end_comment

begin_comment
comment|///    Bits [5:4]: Determine whether to perform a one's complement on the bit
end_comment

begin_comment
comment|///                mask of the comparison results. \n
end_comment

begin_comment
comment|///      00: No effect. \n
end_comment

begin_comment
comment|///      01: Negate the bit mask. \n
end_comment

begin_comment
comment|///      10: No effect. \n
end_comment

begin_comment
comment|///      11: Negate the bit mask only for bits with an index less than or equal
end_comment

begin_comment
comment|///          to the size of \a A or \a B. \n
end_comment

begin_comment
comment|///    Bit [6]: Determines whether the result is zero-extended or expanded to 16
end_comment

begin_comment
comment|///             bytes. \n
end_comment

begin_comment
comment|///      0: The result is zero-extended to 16 bytes. \n
end_comment

begin_comment
comment|///      1: The result is expanded to 16 bytes (this expansion is performed by
end_comment

begin_comment
comment|///         repeating each bit 8 or 16 times).
end_comment

begin_comment
comment|/// \returns Returns a 128-bit integer vector representing the result mask of
end_comment

begin_comment
comment|///    the comparison.
end_comment

begin_define
define|#
directive|define
name|_mm_cmpistrm
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|M
parameter_list|)
define|\
value|(__m128i)__builtin_ia32_pcmpistrm128((__v16qi)(__m128i)(A), \                                        (__v16qi)(__m128i)(B), (int)(M))
end_define

begin_comment
comment|/// \brief Uses the immediate operand \a M to perform a comparison of string
end_comment

begin_comment
comment|///    data with implicitly defined lengths that is contained in source operands
end_comment

begin_comment
comment|///    \a A and \a B. Returns an integer representing the result index of the
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
comment|/// \code
end_comment

begin_comment
comment|/// int _mm_cmpistri(__m128i A, __m128i B, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPISTRI / PCMPISTRI</c>
end_comment

begin_comment
comment|/// instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param A
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param B
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An 8-bit immediate operand specifying whether the characters are bytes or
end_comment

begin_comment
comment|///    words, the type of comparison to perform, and the format of the return
end_comment

begin_comment
comment|///    value. \n
end_comment

begin_comment
comment|///    Bits [1:0]: Determine source data format. \n
end_comment

begin_comment
comment|///      00: 16 unsigned bytes \n
end_comment

begin_comment
comment|///      01: 8 unsigned words \n
end_comment

begin_comment
comment|///      10: 16 signed bytes \n
end_comment

begin_comment
comment|///      11: 8 signed words \n
end_comment

begin_comment
comment|///    Bits [3:2]: Determine comparison type and aggregation method. \n
end_comment

begin_comment
comment|///      00: Subset: Each character in \a B is compared for equality with all
end_comment

begin_comment
comment|///          the characters in \a A. \n
end_comment

begin_comment
comment|///      01: Ranges: Each character in \a B is compared to \a A. The comparison
end_comment

begin_comment
comment|///          basis is greater than or equal for even-indexed elements in \a A,
end_comment

begin_comment
comment|///          and less than or equal for odd-indexed elements in \a A. \n
end_comment

begin_comment
comment|///      10: Match: Compare each pair of corresponding characters in \a A and
end_comment

begin_comment
comment|///          \a B for equality. \n
end_comment

begin_comment
comment|///      11: Substring: Search B for substring matches of \a A. \n
end_comment

begin_comment
comment|///    Bits [5:4]: Determine whether to perform a one's complement on the bit
end_comment

begin_comment
comment|///                mask of the comparison results. \n
end_comment

begin_comment
comment|///      00: No effect. \n
end_comment

begin_comment
comment|///      01: Negate the bit mask. \n
end_comment

begin_comment
comment|///      10: No effect. \n
end_comment

begin_comment
comment|///      11: Negate the bit mask only for bits with an index less than or equal
end_comment

begin_comment
comment|///          to the size of \a A or \a B. \n
end_comment

begin_comment
comment|///    Bit [6]: Determines whether the index of the lowest set bit or the
end_comment

begin_comment
comment|///             highest set bit is returned. \n
end_comment

begin_comment
comment|///      0: The index of the least significant set bit. \n
end_comment

begin_comment
comment|///      1: The index of the most significant set bit. \n
end_comment

begin_comment
comment|/// \returns Returns an integer representing the result index of the comparison.
end_comment

begin_define
define|#
directive|define
name|_mm_cmpistri
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|M
parameter_list|)
define|\
value|(int)__builtin_ia32_pcmpistri128((__v16qi)(__m128i)(A), \                                    (__v16qi)(__m128i)(B), (int)(M))
end_define

begin_comment
comment|/// \brief Uses the immediate operand \a M to perform a comparison of string
end_comment

begin_comment
comment|///    data with explicitly defined lengths that is contained in source operands
end_comment

begin_comment
comment|///    \a A and \a B. Returns a 128-bit integer vector representing the result
end_comment

begin_comment
comment|///    mask of the comparison.
end_comment

begin_comment
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
comment|/// __m128i _mm_cmpestrm(__m128i A, int LA, __m128i B, int LB, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPESTRM / PCMPESTRM</c>
end_comment

begin_comment
comment|/// instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param A
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param LA
end_comment

begin_comment
comment|///    An integer that specifies the length of the string in \a A.
end_comment

begin_comment
comment|/// \param B
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param LB
end_comment

begin_comment
comment|///    An integer that specifies the length of the string in \a B.
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An 8-bit immediate operand specifying whether the characters are bytes or
end_comment

begin_comment
comment|///    words, the type of comparison to perform, and the format of the return
end_comment

begin_comment
comment|///    value. \n
end_comment

begin_comment
comment|///    Bits [1:0]: Determine source data format. \n
end_comment

begin_comment
comment|///      00: 16 unsigned bytes \n
end_comment

begin_comment
comment|///      01: 8 unsigned words \n
end_comment

begin_comment
comment|///      10: 16 signed bytes \n
end_comment

begin_comment
comment|///      11: 8 signed words \n
end_comment

begin_comment
comment|///    Bits [3:2]: Determine comparison type and aggregation method. \n
end_comment

begin_comment
comment|///      00: Subset: Each character in \a B is compared for equality with all
end_comment

begin_comment
comment|///          the characters in \a A. \n
end_comment

begin_comment
comment|///      01: Ranges: Each character in \a B is compared to \a A. The comparison
end_comment

begin_comment
comment|///          basis is greater than or equal for even-indexed elements in \a A,
end_comment

begin_comment
comment|///          and less than or equal for odd-indexed elements in \a A. \n
end_comment

begin_comment
comment|///      10: Match: Compare each pair of corresponding characters in \a A and
end_comment

begin_comment
comment|///          \a B for equality. \n
end_comment

begin_comment
comment|///      11: Substring: Search \a B for substring matches of \a A. \n
end_comment

begin_comment
comment|///    Bits [5:4]: Determine whether to perform a one's complement on the bit
end_comment

begin_comment
comment|///                mask of the comparison results. \n
end_comment

begin_comment
comment|///      00: No effect. \n
end_comment

begin_comment
comment|///      01: Negate the bit mask. \n
end_comment

begin_comment
comment|///      10: No effect. \n
end_comment

begin_comment
comment|///      11: Negate the bit mask only for bits with an index less than or equal
end_comment

begin_comment
comment|///          to the size of \a A or \a B. \n
end_comment

begin_comment
comment|///    Bit [6]: Determines whether the result is zero-extended or expanded to 16
end_comment

begin_comment
comment|///             bytes. \n
end_comment

begin_comment
comment|///      0: The result is zero-extended to 16 bytes. \n
end_comment

begin_comment
comment|///      1: The result is expanded to 16 bytes (this expansion is performed by
end_comment

begin_comment
comment|///         repeating each bit 8 or 16 times). \n
end_comment

begin_comment
comment|/// \returns Returns a 128-bit integer vector representing the result mask of
end_comment

begin_comment
comment|///    the comparison.
end_comment

begin_define
define|#
directive|define
name|_mm_cmpestrm
parameter_list|(
name|A
parameter_list|,
name|LA
parameter_list|,
name|B
parameter_list|,
name|LB
parameter_list|,
name|M
parameter_list|)
define|\
value|(__m128i)__builtin_ia32_pcmpestrm128((__v16qi)(__m128i)(A), (int)(LA), \                                        (__v16qi)(__m128i)(B), (int)(LB), \                                        (int)(M))
end_define

begin_comment
comment|/// \brief Uses the immediate operand \a M to perform a comparison of string
end_comment

begin_comment
comment|///    data with explicitly defined lengths that is contained in source operands
end_comment

begin_comment
comment|///    \a A and \a B. Returns an integer representing the result index of the
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
comment|/// \code
end_comment

begin_comment
comment|/// int _mm_cmpestri(__m128i A, int LA, __m128i B, int LB, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPESTRI / PCMPESTRI</c>
end_comment

begin_comment
comment|/// instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param A
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param LA
end_comment

begin_comment
comment|///    An integer that specifies the length of the string in \a A.
end_comment

begin_comment
comment|/// \param B
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param LB
end_comment

begin_comment
comment|///    An integer that specifies the length of the string in \a B.
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An 8-bit immediate operand specifying whether the characters are bytes or
end_comment

begin_comment
comment|///    words, the type of comparison to perform, and the format of the return
end_comment

begin_comment
comment|///    value. \n
end_comment

begin_comment
comment|///    Bits [1:0]: Determine source data format. \n
end_comment

begin_comment
comment|///      00: 16 unsigned bytes \n
end_comment

begin_comment
comment|///      01: 8 unsigned words \n
end_comment

begin_comment
comment|///      10: 16 signed bytes \n
end_comment

begin_comment
comment|///      11: 8 signed words \n
end_comment

begin_comment
comment|///    Bits [3:2]: Determine comparison type and aggregation method. \n
end_comment

begin_comment
comment|///      00: Subset: Each character in \a B is compared for equality with all
end_comment

begin_comment
comment|///          the characters in \a A. \n
end_comment

begin_comment
comment|///      01: Ranges: Each character in \a B is compared to \a A. The comparison
end_comment

begin_comment
comment|///          basis is greater than or equal for even-indexed elements in \a A,
end_comment

begin_comment
comment|///          and less than or equal for odd-indexed elements in \a A. \n
end_comment

begin_comment
comment|///      10: Match: Compare each pair of corresponding characters in \a A and
end_comment

begin_comment
comment|///          \a B for equality. \n
end_comment

begin_comment
comment|///      11: Substring: Search B for substring matches of \a A. \n
end_comment

begin_comment
comment|///    Bits [5:4]: Determine whether to perform a one's complement on the bit
end_comment

begin_comment
comment|///                mask of the comparison results. \n
end_comment

begin_comment
comment|///      00: No effect. \n
end_comment

begin_comment
comment|///      01: Negate the bit mask. \n
end_comment

begin_comment
comment|///      10: No effect. \n
end_comment

begin_comment
comment|///      11: Negate the bit mask only for bits with an index less than or equal
end_comment

begin_comment
comment|///          to the size of \a A or \a B. \n
end_comment

begin_comment
comment|///    Bit [6]: Determines whether the index of the lowest set bit or the
end_comment

begin_comment
comment|///             highest set bit is returned. \n
end_comment

begin_comment
comment|///      0: The index of the least significant set bit. \n
end_comment

begin_comment
comment|///      1: The index of the most significant set bit. \n
end_comment

begin_comment
comment|/// \returns Returns an integer representing the result index of the comparison.
end_comment

begin_define
define|#
directive|define
name|_mm_cmpestri
parameter_list|(
name|A
parameter_list|,
name|LA
parameter_list|,
name|B
parameter_list|,
name|LB
parameter_list|,
name|M
parameter_list|)
define|\
value|(int)__builtin_ia32_pcmpestri128((__v16qi)(__m128i)(A), (int)(LA), \                                    (__v16qi)(__m128i)(B), (int)(LB), \                                    (int)(M))
end_define

begin_comment
comment|/* SSE4.2 Packed Comparison Intrinsics and EFlag Reading.  */
end_comment

begin_comment
comment|/// \brief Uses the immediate operand \a M to perform a comparison of string
end_comment

begin_comment
comment|///    data with implicitly defined lengths that is contained in source operands
end_comment

begin_comment
comment|///    \a A and \a B. Returns 1 if the bit mask is zero and the length of the
end_comment

begin_comment
comment|///    string in \a B is the maximum, otherwise, returns 0.
end_comment

begin_comment
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
comment|/// int _mm_cmpistra(__m128i A, __m128i B, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPISTRI / PCMPISTRI</c>
end_comment

begin_comment
comment|/// instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param A
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param B
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An 8-bit immediate operand specifying whether the characters are bytes or
end_comment

begin_comment
comment|///    words and the type of comparison to perform. \n
end_comment

begin_comment
comment|///    Bits [1:0]: Determine source data format. \n
end_comment

begin_comment
comment|///      00: 16 unsigned bytes \n
end_comment

begin_comment
comment|///      01: 8 unsigned words \n
end_comment

begin_comment
comment|///      10: 16 signed bytes \n
end_comment

begin_comment
comment|///      11: 8 signed words \n
end_comment

begin_comment
comment|///    Bits [3:2]: Determine comparison type and aggregation method. \n
end_comment

begin_comment
comment|///      00: Subset: Each character in \a B is compared for equality with all
end_comment

begin_comment
comment|///          the characters in \a A. \n
end_comment

begin_comment
comment|///      01: Ranges: Each character in \a B is compared to \a A. The comparison
end_comment

begin_comment
comment|///          basis is greater than or equal for even-indexed elements in \a A,
end_comment

begin_comment
comment|///          and less than or equal for odd-indexed elements in \a A. \n
end_comment

begin_comment
comment|///      10: Match: Compare each pair of corresponding characters in \a A and
end_comment

begin_comment
comment|///          \a B for equality. \n
end_comment

begin_comment
comment|///      11: Substring: Search \a B for substring matches of \a A. \n
end_comment

begin_comment
comment|///    Bits [5:4]: Determine whether to perform a one's complement on the bit
end_comment

begin_comment
comment|///                mask of the comparison results. \n
end_comment

begin_comment
comment|///      00: No effect. \n
end_comment

begin_comment
comment|///      01: Negate the bit mask. \n
end_comment

begin_comment
comment|///      10: No effect. \n
end_comment

begin_comment
comment|///      11: Negate the bit mask only for bits with an index less than or equal
end_comment

begin_comment
comment|///          to the size of \a A or \a B. \n
end_comment

begin_comment
comment|/// \returns Returns 1 if the bit mask is zero and the length of the string in
end_comment

begin_comment
comment|///    \a B is the maximum; otherwise, returns 0.
end_comment

begin_define
define|#
directive|define
name|_mm_cmpistra
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|M
parameter_list|)
define|\
value|(int)__builtin_ia32_pcmpistria128((__v16qi)(__m128i)(A), \                                     (__v16qi)(__m128i)(B), (int)(M))
end_define

begin_comment
comment|/// \brief Uses the immediate operand \a M to perform a comparison of string
end_comment

begin_comment
comment|///    data with implicitly defined lengths that is contained in source operands
end_comment

begin_comment
comment|///    \a A and \a B. Returns 1 if the bit mask is non-zero, otherwise, returns
end_comment

begin_comment
comment|///    0.
end_comment

begin_comment
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
comment|/// int _mm_cmpistrc(__m128i A, __m128i B, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPISTRI / PCMPISTRI</c>
end_comment

begin_comment
comment|/// instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param A
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param B
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An 8-bit immediate operand specifying whether the characters are bytes or
end_comment

begin_comment
comment|///    words and the type of comparison to perform. \n
end_comment

begin_comment
comment|///    Bits [1:0]: Determine source data format. \n
end_comment

begin_comment
comment|///      00: 16 unsigned bytes \n
end_comment

begin_comment
comment|///      01: 8 unsigned words \n
end_comment

begin_comment
comment|///      10: 16 signed bytes \n
end_comment

begin_comment
comment|///      11: 8 signed words \n
end_comment

begin_comment
comment|///    Bits [3:2]: Determine comparison type and aggregation method. \n
end_comment

begin_comment
comment|///      00: Subset: Each character in \a B is compared for equality with all
end_comment

begin_comment
comment|///          the characters in \a A. \n
end_comment

begin_comment
comment|///      01: Ranges: Each character in \a B is compared to \a A. The comparison
end_comment

begin_comment
comment|///          basis is greater than or equal for even-indexed elements in \a A,
end_comment

begin_comment
comment|///          and less than or equal for odd-indexed elements in \a A. \n
end_comment

begin_comment
comment|///      10: Match: Compare each pair of corresponding characters in \a A and
end_comment

begin_comment
comment|///          \a B for equality. \n
end_comment

begin_comment
comment|///      11: Substring: Search B for substring matches of \a A. \n
end_comment

begin_comment
comment|///    Bits [5:4]: Determine whether to perform a one's complement on the bit
end_comment

begin_comment
comment|///                mask of the comparison results. \n
end_comment

begin_comment
comment|///      00: No effect. \n
end_comment

begin_comment
comment|///      01: Negate the bit mask. \n
end_comment

begin_comment
comment|///      10: No effect. \n
end_comment

begin_comment
comment|///      11: Negate the bit mask only for bits with an index less than or equal
end_comment

begin_comment
comment|///          to the size of \a A or \a B.
end_comment

begin_comment
comment|/// \returns Returns 1 if the bit mask is non-zero, otherwise, returns 0.
end_comment

begin_define
define|#
directive|define
name|_mm_cmpistrc
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|M
parameter_list|)
define|\
value|(int)__builtin_ia32_pcmpistric128((__v16qi)(__m128i)(A), \                                     (__v16qi)(__m128i)(B), (int)(M))
end_define

begin_comment
comment|/// \brief Uses the immediate operand \a M to perform a comparison of string
end_comment

begin_comment
comment|///    data with implicitly defined lengths that is contained in source operands
end_comment

begin_comment
comment|///    \a A and \a B. Returns bit 0 of the resulting bit mask.
end_comment

begin_comment
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
comment|/// int _mm_cmpistro(__m128i A, __m128i B, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPISTRI / PCMPISTRI</c>
end_comment

begin_comment
comment|/// instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param A
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param B
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An 8-bit immediate operand specifying whether the characters are bytes or
end_comment

begin_comment
comment|///    words and the type of comparison to perform. \n
end_comment

begin_comment
comment|///    Bits [1:0]: Determine source data format. \n
end_comment

begin_comment
comment|///      00: 16 unsigned bytes \n
end_comment

begin_comment
comment|///      01: 8 unsigned words \n
end_comment

begin_comment
comment|///      10: 16 signed bytes \n
end_comment

begin_comment
comment|///      11: 8 signed words \n
end_comment

begin_comment
comment|///    Bits [3:2]: Determine comparison type and aggregation method. \n
end_comment

begin_comment
comment|///      00: Subset: Each character in \a B is compared for equality with all
end_comment

begin_comment
comment|///          the characters in \a A. \n
end_comment

begin_comment
comment|///      01: Ranges: Each character in \a B is compared to \a A. The comparison
end_comment

begin_comment
comment|///          basis is greater than or equal for even-indexed elements in \a A,
end_comment

begin_comment
comment|///          and less than or equal for odd-indexed elements in \a A. \n
end_comment

begin_comment
comment|///      10: Match: Compare each pair of corresponding characters in \a A and
end_comment

begin_comment
comment|///          \a B for equality. \n
end_comment

begin_comment
comment|///      11: Substring: Search B for substring matches of \a A. \n
end_comment

begin_comment
comment|///    Bits [5:4]: Determine whether to perform a one's complement on the bit
end_comment

begin_comment
comment|///                mask of the comparison results. \n
end_comment

begin_comment
comment|///      00: No effect. \n
end_comment

begin_comment
comment|///      01: Negate the bit mask. \n
end_comment

begin_comment
comment|///      10: No effect. \n
end_comment

begin_comment
comment|///      11: Negate the bit mask only for bits with an index less than or equal
end_comment

begin_comment
comment|///          to the size of \a A or \a B. \n
end_comment

begin_comment
comment|/// \returns Returns bit 0 of the resulting bit mask.
end_comment

begin_define
define|#
directive|define
name|_mm_cmpistro
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|M
parameter_list|)
define|\
value|(int)__builtin_ia32_pcmpistrio128((__v16qi)(__m128i)(A), \                                     (__v16qi)(__m128i)(B), (int)(M))
end_define

begin_comment
comment|/// \brief Uses the immediate operand \a M to perform a comparison of string
end_comment

begin_comment
comment|///    data with implicitly defined lengths that is contained in source operands
end_comment

begin_comment
comment|///    \a A and \a B. Returns 1 if the length of the string in \a A is less than
end_comment

begin_comment
comment|///    the maximum, otherwise, returns 0.
end_comment

begin_comment
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
comment|/// int _mm_cmpistrs(__m128i A, __m128i B, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPISTRI / PCMPISTRI</c>
end_comment

begin_comment
comment|/// instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param A
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param B
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An 8-bit immediate operand specifying whether the characters are bytes or
end_comment

begin_comment
comment|///    words and the type of comparison to perform. \n
end_comment

begin_comment
comment|///    Bits [1:0]: Determine source data format. \n
end_comment

begin_comment
comment|///      00: 16 unsigned bytes \n
end_comment

begin_comment
comment|///      01: 8 unsigned words \n
end_comment

begin_comment
comment|///      10: 16 signed bytes \n
end_comment

begin_comment
comment|///      11: 8 signed words \n
end_comment

begin_comment
comment|///    Bits [3:2]: Determine comparison type and aggregation method. \n
end_comment

begin_comment
comment|///      00: Subset: Each character in \a B is compared for equality with all
end_comment

begin_comment
comment|///          the characters in \a A. \n
end_comment

begin_comment
comment|///      01: Ranges: Each character in \a B is compared to \a A. The comparison
end_comment

begin_comment
comment|///          basis is greater than or equal for even-indexed elements in \a A,
end_comment

begin_comment
comment|///          and less than or equal for odd-indexed elements in \a A. \n
end_comment

begin_comment
comment|///      10: Match: Compare each pair of corresponding characters in \a A and
end_comment

begin_comment
comment|///          \a B for equality. \n
end_comment

begin_comment
comment|///      11: Substring: Search \a B for substring matches of \a A. \n
end_comment

begin_comment
comment|///    Bits [5:4]: Determine whether to perform a one's complement on the bit
end_comment

begin_comment
comment|///                mask of the comparison results. \n
end_comment

begin_comment
comment|///      00: No effect. \n
end_comment

begin_comment
comment|///      01: Negate the bit mask. \n
end_comment

begin_comment
comment|///      10: No effect. \n
end_comment

begin_comment
comment|///      11: Negate the bit mask only for bits with an index less than or equal
end_comment

begin_comment
comment|///          to the size of \a A or \a B. \n
end_comment

begin_comment
comment|/// \returns Returns 1 if the length of the string in \a A is less than the
end_comment

begin_comment
comment|///    maximum, otherwise, returns 0.
end_comment

begin_define
define|#
directive|define
name|_mm_cmpistrs
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|M
parameter_list|)
define|\
value|(int)__builtin_ia32_pcmpistris128((__v16qi)(__m128i)(A), \                                     (__v16qi)(__m128i)(B), (int)(M))
end_define

begin_comment
comment|/// \brief Uses the immediate operand \a M to perform a comparison of string
end_comment

begin_comment
comment|///    data with implicitly defined lengths that is contained in source operands
end_comment

begin_comment
comment|///    \a A and \a B. Returns 1 if the length of the string in \a B is less than
end_comment

begin_comment
comment|///    the maximum, otherwise, returns 0.
end_comment

begin_comment
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
comment|/// int _mm_cmpistrz(__m128i A, __m128i B, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPISTRI / PCMPISTRI</c>
end_comment

begin_comment
comment|/// instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param A
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param B
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An 8-bit immediate operand specifying whether the characters are bytes or
end_comment

begin_comment
comment|///    words and the type of comparison to perform. \n
end_comment

begin_comment
comment|///    Bits [1:0]: Determine source data format. \n
end_comment

begin_comment
comment|///      00: 16 unsigned bytes \n
end_comment

begin_comment
comment|///      01: 8 unsigned words \n
end_comment

begin_comment
comment|///      10: 16 signed bytes \n
end_comment

begin_comment
comment|///      11: 8 signed words \n
end_comment

begin_comment
comment|///    Bits [3:2]: Determine comparison type and aggregation method. \n
end_comment

begin_comment
comment|///      00: Subset: Each character in \a B is compared for equality with all
end_comment

begin_comment
comment|///          the characters in \a A. \n
end_comment

begin_comment
comment|///      01: Ranges: Each character in \a B is compared to \a A. The comparison
end_comment

begin_comment
comment|///          basis is greater than or equal for even-indexed elements in \a A,
end_comment

begin_comment
comment|///          and less than or equal for odd-indexed elements in \a A. \n
end_comment

begin_comment
comment|///      10: Match: Compare each pair of corresponding characters in \a A and
end_comment

begin_comment
comment|///          \a B for equality. \n
end_comment

begin_comment
comment|///      11: Substring: Search \a B for substring matches of \a A. \n
end_comment

begin_comment
comment|///    Bits [5:4]: Determine whether to perform a one's complement on the bit
end_comment

begin_comment
comment|///                mask of the comparison results. \n
end_comment

begin_comment
comment|///      00: No effect. \n
end_comment

begin_comment
comment|///      01: Negate the bit mask. \n
end_comment

begin_comment
comment|///      10: No effect. \n
end_comment

begin_comment
comment|///      11: Negate the bit mask only for bits with an index less than or equal
end_comment

begin_comment
comment|///          to the size of \a A or \a B.
end_comment

begin_comment
comment|/// \returns Returns 1 if the length of the string in \a B is less than the
end_comment

begin_comment
comment|///    maximum, otherwise, returns 0.
end_comment

begin_define
define|#
directive|define
name|_mm_cmpistrz
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|M
parameter_list|)
define|\
value|(int)__builtin_ia32_pcmpistriz128((__v16qi)(__m128i)(A), \                                     (__v16qi)(__m128i)(B), (int)(M))
end_define

begin_comment
comment|/// \brief Uses the immediate operand \a M to perform a comparison of string
end_comment

begin_comment
comment|///    data with explicitly defined lengths that is contained in source operands
end_comment

begin_comment
comment|///    \a A and \a B. Returns 1 if the bit mask is zero and the length of the
end_comment

begin_comment
comment|///    string in \a B is the maximum, otherwise, returns 0.
end_comment

begin_comment
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
comment|/// int _mm_cmpestra(__m128i A, int LA, __m128i B, int LB, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPESTRI / PCMPESTRI</c>
end_comment

begin_comment
comment|/// instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param A
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param LA
end_comment

begin_comment
comment|///    An integer that specifies the length of the string in \a A.
end_comment

begin_comment
comment|/// \param B
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param LB
end_comment

begin_comment
comment|///    An integer that specifies the length of the string in \a B.
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An 8-bit immediate operand specifying whether the characters are bytes or
end_comment

begin_comment
comment|///    words and the type of comparison to perform. \n
end_comment

begin_comment
comment|///    Bits [1:0]: Determine source data format. \n
end_comment

begin_comment
comment|///      00: 16 unsigned bytes \n
end_comment

begin_comment
comment|///      01: 8 unsigned words \n
end_comment

begin_comment
comment|///      10: 16 signed bytes \n
end_comment

begin_comment
comment|///      11: 8 signed words \n
end_comment

begin_comment
comment|///    Bits [3:2]: Determine comparison type and aggregation method. \n
end_comment

begin_comment
comment|///      00: Subset: Each character in \a B is compared for equality with all
end_comment

begin_comment
comment|///          the characters in \a A. \n
end_comment

begin_comment
comment|///      01: Ranges: Each character in \a B is compared to \a A. The comparison
end_comment

begin_comment
comment|///          basis is greater than or equal for even-indexed elements in \a A,
end_comment

begin_comment
comment|///          and less than or equal for odd-indexed elements in \a A. \n
end_comment

begin_comment
comment|///      10: Match: Compare each pair of corresponding characters in \a A and
end_comment

begin_comment
comment|///          \a B for equality. \n
end_comment

begin_comment
comment|///      11: Substring: Search \a B for substring matches of \a A. \n
end_comment

begin_comment
comment|///    Bits [5:4]: Determine whether to perform a one's complement on the bit
end_comment

begin_comment
comment|///                mask of the comparison results. \n
end_comment

begin_comment
comment|///      00: No effect. \n
end_comment

begin_comment
comment|///      01: Negate the bit mask. \n
end_comment

begin_comment
comment|///      10: No effect. \n
end_comment

begin_comment
comment|///      11: Negate the bit mask only for bits with an index less than or equal
end_comment

begin_comment
comment|///          to the size of \a A or \a B.
end_comment

begin_comment
comment|/// \returns Returns 1 if the bit mask is zero and the length of the string in
end_comment

begin_comment
comment|///    \a B is the maximum, otherwise, returns 0.
end_comment

begin_define
define|#
directive|define
name|_mm_cmpestra
parameter_list|(
name|A
parameter_list|,
name|LA
parameter_list|,
name|B
parameter_list|,
name|LB
parameter_list|,
name|M
parameter_list|)
define|\
value|(int)__builtin_ia32_pcmpestria128((__v16qi)(__m128i)(A), (int)(LA), \                                     (__v16qi)(__m128i)(B), (int)(LB), \                                     (int)(M))
end_define

begin_comment
comment|/// \brief Uses the immediate operand \a M to perform a comparison of string
end_comment

begin_comment
comment|///    data with explicitly defined lengths that is contained in source operands
end_comment

begin_comment
comment|///    \a A and \a B. Returns 1 if the resulting mask is non-zero, otherwise,
end_comment

begin_comment
comment|///    returns 0.
end_comment

begin_comment
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
comment|/// int _mm_cmpestrc(__m128i A, int LA, __m128i B, int LB, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPESTRI / PCMPESTRI</c>
end_comment

begin_comment
comment|/// instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param A
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param LA
end_comment

begin_comment
comment|///    An integer that specifies the length of the string in \a A.
end_comment

begin_comment
comment|/// \param B
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param LB
end_comment

begin_comment
comment|///    An integer that specifies the length of the string in \a B.
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An 8-bit immediate operand specifying whether the characters are bytes or
end_comment

begin_comment
comment|///    words and the type of comparison to perform. \n
end_comment

begin_comment
comment|///    Bits [1:0]: Determine source data format. \n
end_comment

begin_comment
comment|///      00: 16 unsigned bytes \n
end_comment

begin_comment
comment|///      01: 8 unsigned words \n
end_comment

begin_comment
comment|///      10: 16 signed bytes \n
end_comment

begin_comment
comment|///      11: 8 signed words \n
end_comment

begin_comment
comment|///    Bits [3:2]: Determine comparison type and aggregation method. \n
end_comment

begin_comment
comment|///      00: Subset: Each character in \a B is compared for equality with all
end_comment

begin_comment
comment|///          the characters in \a A. \n
end_comment

begin_comment
comment|///      01: Ranges: Each character in \a B is compared to \a A. The comparison
end_comment

begin_comment
comment|///          basis is greater than or equal for even-indexed elements in \a A,
end_comment

begin_comment
comment|///          and less than or equal for odd-indexed elements in \a A. \n
end_comment

begin_comment
comment|///      10: Match: Compare each pair of corresponding characters in \a A and
end_comment

begin_comment
comment|///          \a B for equality. \n
end_comment

begin_comment
comment|///      11: Substring: Search \a B for substring matches of \a A. \n
end_comment

begin_comment
comment|///    Bits [5:4]: Determine whether to perform a one's complement on the bit
end_comment

begin_comment
comment|///                mask of the comparison results. \n
end_comment

begin_comment
comment|///      00: No effect. \n
end_comment

begin_comment
comment|///      01: Negate the bit mask. \n
end_comment

begin_comment
comment|///      10: No effect. \n
end_comment

begin_comment
comment|///      11: Negate the bit mask only for bits with an index less than or equal
end_comment

begin_comment
comment|///          to the size of \a A or \a B. \n
end_comment

begin_comment
comment|/// \returns Returns 1 if the resulting mask is non-zero, otherwise, returns 0.
end_comment

begin_define
define|#
directive|define
name|_mm_cmpestrc
parameter_list|(
name|A
parameter_list|,
name|LA
parameter_list|,
name|B
parameter_list|,
name|LB
parameter_list|,
name|M
parameter_list|)
define|\
value|(int)__builtin_ia32_pcmpestric128((__v16qi)(__m128i)(A), (int)(LA), \                                     (__v16qi)(__m128i)(B), (int)(LB), \                                     (int)(M))
end_define

begin_comment
comment|/// \brief Uses the immediate operand \a M to perform a comparison of string
end_comment

begin_comment
comment|///    data with explicitly defined lengths that is contained in source operands
end_comment

begin_comment
comment|///    \a A and \a B. Returns bit 0 of the resulting bit mask.
end_comment

begin_comment
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
comment|/// int _mm_cmpestro(__m128i A, int LA, __m128i B, int LB, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPESTRI / PCMPESTRI</c>
end_comment

begin_comment
comment|/// instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param A
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param LA
end_comment

begin_comment
comment|///    An integer that specifies the length of the string in \a A.
end_comment

begin_comment
comment|/// \param B
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param LB
end_comment

begin_comment
comment|///    An integer that specifies the length of the string in \a B.
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An 8-bit immediate operand specifying whether the characters are bytes or
end_comment

begin_comment
comment|///    words and the type of comparison to perform. \n
end_comment

begin_comment
comment|///    Bits [1:0]: Determine source data format. \n
end_comment

begin_comment
comment|///      00: 16 unsigned bytes \n
end_comment

begin_comment
comment|///      01: 8 unsigned words \n
end_comment

begin_comment
comment|///      10: 16 signed bytes \n
end_comment

begin_comment
comment|///      11: 8 signed words \n
end_comment

begin_comment
comment|///    Bits [3:2]: Determine comparison type and aggregation method. \n
end_comment

begin_comment
comment|///      00: Subset: Each character in \a B is compared for equality with all
end_comment

begin_comment
comment|///          the characters in \a A. \n
end_comment

begin_comment
comment|///      01: Ranges: Each character in \a B is compared to \a A. The comparison
end_comment

begin_comment
comment|///          basis is greater than or equal for even-indexed elements in \a A,
end_comment

begin_comment
comment|///          and less than or equal for odd-indexed elements in \a A. \n
end_comment

begin_comment
comment|///      10: Match: Compare each pair of corresponding characters in \a A and
end_comment

begin_comment
comment|///          \a B for equality. \n
end_comment

begin_comment
comment|///      11: Substring: Search \a B for substring matches of \a A. \n
end_comment

begin_comment
comment|///    Bits [5:4]: Determine whether to perform a one's complement on the bit
end_comment

begin_comment
comment|///                mask of the comparison results. \n
end_comment

begin_comment
comment|///      00: No effect. \n
end_comment

begin_comment
comment|///      01: Negate the bit mask. \n
end_comment

begin_comment
comment|///      10: No effect. \n
end_comment

begin_comment
comment|///      11: Negate the bit mask only for bits with an index less than or equal
end_comment

begin_comment
comment|///          to the size of \a A or \a B.
end_comment

begin_comment
comment|/// \returns Returns bit 0 of the resulting bit mask.
end_comment

begin_define
define|#
directive|define
name|_mm_cmpestro
parameter_list|(
name|A
parameter_list|,
name|LA
parameter_list|,
name|B
parameter_list|,
name|LB
parameter_list|,
name|M
parameter_list|)
define|\
value|(int)__builtin_ia32_pcmpestrio128((__v16qi)(__m128i)(A), (int)(LA), \                                     (__v16qi)(__m128i)(B), (int)(LB), \                                     (int)(M))
end_define

begin_comment
comment|/// \brief Uses the immediate operand \a M to perform a comparison of string
end_comment

begin_comment
comment|///    data with explicitly defined lengths that is contained in source operands
end_comment

begin_comment
comment|///    \a A and \a B. Returns 1 if the length of the string in \a A is less than
end_comment

begin_comment
comment|///    the maximum, otherwise, returns 0.
end_comment

begin_comment
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
comment|/// int _mm_cmpestrs(__m128i A, int LA, __m128i B, int LB, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPESTRI / PCMPESTRI</c>
end_comment

begin_comment
comment|/// instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param A
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param LA
end_comment

begin_comment
comment|///    An integer that specifies the length of the string in \a A.
end_comment

begin_comment
comment|/// \param B
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param LB
end_comment

begin_comment
comment|///    An integer that specifies the length of the string in \a B.
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An 8-bit immediate operand specifying whether the characters are bytes or
end_comment

begin_comment
comment|///    words and the type of comparison to perform. \n
end_comment

begin_comment
comment|///    Bits [1:0]: Determine source data format. \n
end_comment

begin_comment
comment|///      00: 16 unsigned bytes \n
end_comment

begin_comment
comment|///      01: 8 unsigned words \n
end_comment

begin_comment
comment|///      10: 16 signed bytes \n
end_comment

begin_comment
comment|///      11: 8 signed words \n
end_comment

begin_comment
comment|///    Bits [3:2]: Determine comparison type and aggregation method. \n
end_comment

begin_comment
comment|///      00: Subset: Each character in \a B is compared for equality with all
end_comment

begin_comment
comment|///          the characters in \a A. \n
end_comment

begin_comment
comment|///      01: Ranges: Each character in \a B is compared to \a A. The comparison
end_comment

begin_comment
comment|///          basis is greater than or equal for even-indexed elements in \a A,
end_comment

begin_comment
comment|///          and less than or equal for odd-indexed elements in \a A. \n
end_comment

begin_comment
comment|///      10: Match: Compare each pair of corresponding characters in \a A and
end_comment

begin_comment
comment|///          \a B for equality. \n
end_comment

begin_comment
comment|///      11: Substring: Search \a B for substring matches of \a A. \n
end_comment

begin_comment
comment|///    Bits [5:4]: Determine whether to perform a one's complement in the bit
end_comment

begin_comment
comment|///                mask of the comparison results. \n
end_comment

begin_comment
comment|///      00: No effect. \n
end_comment

begin_comment
comment|///      01: Negate the bit mask. \n
end_comment

begin_comment
comment|///      10: No effect. \n
end_comment

begin_comment
comment|///      11: Negate the bit mask only for bits with an index less than or equal
end_comment

begin_comment
comment|///          to the size of \a A or \a B. \n
end_comment

begin_comment
comment|/// \returns Returns 1 if the length of the string in \a A is less than the
end_comment

begin_comment
comment|///    maximum, otherwise, returns 0.
end_comment

begin_define
define|#
directive|define
name|_mm_cmpestrs
parameter_list|(
name|A
parameter_list|,
name|LA
parameter_list|,
name|B
parameter_list|,
name|LB
parameter_list|,
name|M
parameter_list|)
define|\
value|(int)__builtin_ia32_pcmpestris128((__v16qi)(__m128i)(A), (int)(LA), \                                     (__v16qi)(__m128i)(B), (int)(LB), \                                     (int)(M))
end_define

begin_comment
comment|/// \brief Uses the immediate operand \a M to perform a comparison of string
end_comment

begin_comment
comment|///    data with explicitly defined lengths that is contained in source operands
end_comment

begin_comment
comment|///    \a A and \a B. Returns 1 if the length of the string in \a B is less than
end_comment

begin_comment
comment|///    the maximum, otherwise, returns 0.
end_comment

begin_comment
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
comment|/// int _mm_cmpestrz(__m128i A, int LA, __m128i B, int LB, const int M);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPESTRI</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param A
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param LA
end_comment

begin_comment
comment|///    An integer that specifies the length of the string in \a A.
end_comment

begin_comment
comment|/// \param B
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands to be
end_comment

begin_comment
comment|///    compared.
end_comment

begin_comment
comment|/// \param LB
end_comment

begin_comment
comment|///    An integer that specifies the length of the string in \a B.
end_comment

begin_comment
comment|/// \param M
end_comment

begin_comment
comment|///    An 8-bit immediate operand specifying whether the characters are bytes or
end_comment

begin_comment
comment|///    words and the type of comparison to perform. \n
end_comment

begin_comment
comment|///    Bits [1:0]: Determine source data format. \n
end_comment

begin_comment
comment|///      00: 16 unsigned bytes  \n
end_comment

begin_comment
comment|///      01: 8 unsigned words \n
end_comment

begin_comment
comment|///      10: 16 signed bytes \n
end_comment

begin_comment
comment|///      11: 8 signed words \n
end_comment

begin_comment
comment|///    Bits [3:2]: Determine comparison type and aggregation method. \n
end_comment

begin_comment
comment|///      00: Subset: Each character in \a B is compared for equality with all
end_comment

begin_comment
comment|///          the characters in \a A. \n
end_comment

begin_comment
comment|///      01: Ranges: Each character in \a B is compared to \a A. The comparison
end_comment

begin_comment
comment|///          basis is greater than or equal for even-indexed elements in \a A,
end_comment

begin_comment
comment|///          and less than or equal for odd-indexed elements in \a A. \n
end_comment

begin_comment
comment|///      10: Match: Compare each pair of corresponding characters in \a A and
end_comment

begin_comment
comment|///          \a B for equality. \n
end_comment

begin_comment
comment|///      11: Substring: Search \a B for substring matches of \a A. \n
end_comment

begin_comment
comment|///    Bits [5:4]: Determine whether to perform a one's complement on the bit
end_comment

begin_comment
comment|///                mask of the comparison results. \n
end_comment

begin_comment
comment|///      00: No effect. \n
end_comment

begin_comment
comment|///      01: Negate the bit mask. \n
end_comment

begin_comment
comment|///      10: No effect. \n
end_comment

begin_comment
comment|///      11: Negate the bit mask only for bits with an index less than or equal
end_comment

begin_comment
comment|///          to the size of \a A or \a B.
end_comment

begin_comment
comment|/// \returns Returns 1 if the length of the string in \a B is less than the
end_comment

begin_comment
comment|///    maximum, otherwise, returns 0.
end_comment

begin_define
define|#
directive|define
name|_mm_cmpestrz
parameter_list|(
name|A
parameter_list|,
name|LA
parameter_list|,
name|B
parameter_list|,
name|LB
parameter_list|,
name|M
parameter_list|)
define|\
value|(int)__builtin_ia32_pcmpestriz128((__v16qi)(__m128i)(A), (int)(LA), \                                     (__v16qi)(__m128i)(B), (int)(LB), \                                     (int)(M))
end_define

begin_comment
comment|/* SSE4.2 Compare Packed Data -- Greater Than.  */
end_comment

begin_comment
comment|/// \brief Compares each of the corresponding 64-bit values of the 128-bit
end_comment

begin_comment
comment|///    integer vectors to determine if the values in the first operand are
end_comment

begin_comment
comment|///    greater than those in the second operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCMPGTQ / PCMPGTQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V1
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __V2
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
name|_mm_cmpgt_epi64
parameter_list|(
name|__m128i
name|__V1
parameter_list|,
name|__m128i
name|__V2
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v2di
operator|)
name|__V1
operator|>
operator|(
name|__v2di
operator|)
name|__V2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* SSE4.2 Accumulate CRC32.  */
end_comment

begin_comment
comment|/// \brief Adds the unsigned integer operand to the CRC-32C checksum of the
end_comment

begin_comment
comment|///    unsigned char operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> CRC32B</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __C
end_comment

begin_comment
comment|///    An unsigned integer operand to add to the CRC-32C checksum of operand
end_comment

begin_comment
comment|///    \a  __D.
end_comment

begin_comment
comment|/// \param __D
end_comment

begin_comment
comment|///    An unsigned 8-bit integer operand used to compute the CRC-32C checksum.
end_comment

begin_comment
comment|/// \returns The result of adding operand \a __C to the CRC-32C checksum of
end_comment

begin_comment
comment|///    operand \a __D.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_crc32_u8
parameter_list|(
name|unsigned
name|int
name|__C
parameter_list|,
name|unsigned
name|char
name|__D
parameter_list|)
block|{
return|return
name|__builtin_ia32_crc32qi
argument_list|(
name|__C
argument_list|,
name|__D
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds the unsigned integer operand to the CRC-32C checksum of the
end_comment

begin_comment
comment|///    unsigned short operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> CRC32W</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __C
end_comment

begin_comment
comment|///    An unsigned integer operand to add to the CRC-32C checksum of operand
end_comment

begin_comment
comment|///    \a __D.
end_comment

begin_comment
comment|/// \param __D
end_comment

begin_comment
comment|///    An unsigned 16-bit integer operand used to compute the CRC-32C checksum.
end_comment

begin_comment
comment|/// \returns The result of adding operand \a __C to the CRC-32C checksum of
end_comment

begin_comment
comment|///    operand \a __D.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_crc32_u16
parameter_list|(
name|unsigned
name|int
name|__C
parameter_list|,
name|unsigned
name|short
name|__D
parameter_list|)
block|{
return|return
name|__builtin_ia32_crc32hi
argument_list|(
name|__C
argument_list|,
name|__D
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds the first unsigned integer operand to the CRC-32C checksum of
end_comment

begin_comment
comment|///    the second unsigned integer operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> CRC32L</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __C
end_comment

begin_comment
comment|///    An unsigned integer operand to add to the CRC-32C checksum of operand
end_comment

begin_comment
comment|///    \a __D.
end_comment

begin_comment
comment|/// \param __D
end_comment

begin_comment
comment|///    An unsigned 32-bit integer operand used to compute the CRC-32C checksum.
end_comment

begin_comment
comment|/// \returns The result of adding operand \a __C to the CRC-32C checksum of
end_comment

begin_comment
comment|///    operand \a __D.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_crc32_u32
parameter_list|(
name|unsigned
name|int
name|__C
parameter_list|,
name|unsigned
name|int
name|__D
parameter_list|)
block|{
return|return
name|__builtin_ia32_crc32si
argument_list|(
name|__C
argument_list|,
name|__D
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
comment|/// \brief Adds the unsigned integer operand to the CRC-32C checksum of the
end_comment

begin_comment
comment|///    unsigned 64-bit integer operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> CRC32Q</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __C
end_comment

begin_comment
comment|///    An unsigned integer operand to add to the CRC-32C checksum of operand
end_comment

begin_comment
comment|///    \a __D.
end_comment

begin_comment
comment|/// \param __D
end_comment

begin_comment
comment|///    An unsigned 64-bit integer operand used to compute the CRC-32C checksum.
end_comment

begin_comment
comment|/// \returns The result of adding operand \a __C to the CRC-32C checksum of
end_comment

begin_comment
comment|///    operand \a __D.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|long
name|long
name|__DEFAULT_FN_ATTRS
name|_mm_crc32_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__C
parameter_list|,
name|unsigned
name|long
name|long
name|__D
parameter_list|)
block|{
return|return
name|__builtin_ia32_crc32di
argument_list|(
name|__C
argument_list|,
name|__D
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __x86_64__ */
end_comment

begin_undef
undef|#
directive|undef
name|__DEFAULT_FN_ATTRS
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__POPCNT__
end_ifdef

begin_include
include|#
directive|include
file|<popcntintrin.h>
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
comment|/* _SMMINTRIN_H */
end_comment

end_unit

