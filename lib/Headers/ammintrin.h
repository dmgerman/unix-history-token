begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- ammintrin.h - SSE4a intrinsics -----------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AMMINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__AMMINTRIN_H
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
value|__attribute__((__always_inline__, __nodebug__, __target__("sse4a")))
end_define

begin_comment
comment|/// \brief Extracts the specified bits from the lower 64 bits of the 128-bit
end_comment

begin_comment
comment|///    integer vector operand at the index idx and of the length len.
end_comment

begin_comment
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
comment|/// __m128i _mm_extracti_si64(__m128i x, const int len, const int idx);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c EXTRQ instruction.
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param x
end_comment

begin_comment
comment|///    The value from which bits are extracted.
end_comment

begin_comment
comment|/// \param len
end_comment

begin_comment
comment|///    Bits [5:0] specify the length; the other bits are ignored. If bits [5:0]
end_comment

begin_comment
comment|///    are zero, the length is interpreted as 64.
end_comment

begin_comment
comment|/// \param idx
end_comment

begin_comment
comment|///    Bits [5:0] specify the index of the least significant bit; the other
end_comment

begin_comment
comment|///    bits are ignored. If the sum of the index and length is greater than
end_comment

begin_comment
comment|///    64, the result is undefined. If the length and index are both zero,
end_comment

begin_comment
comment|///    bits [63:0] of parameter x are extracted. If the length is zero
end_comment

begin_comment
comment|///    but the index is non-zero, the result is undefined.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector whose lower 64 bits contain the bits
end_comment

begin_comment
comment|///    extracted from the source operand.
end_comment

begin_define
define|#
directive|define
name|_mm_extracti_si64
parameter_list|(
name|x
parameter_list|,
name|len
parameter_list|,
name|idx
parameter_list|)
define|\
value|((__m128i)__builtin_ia32_extrqi((__v2di)(__m128i)(x), \                                   (char)(len), (char)(idx)))
end_define

begin_comment
comment|/// \brief Extracts the specified bits from the lower 64 bits of the 128-bit
end_comment

begin_comment
comment|///    integer vector operand at the index and of the length specified by __y.
end_comment

begin_comment
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
comment|/// This intrinsic corresponds to the \c EXTRQ instruction.
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __x
end_comment

begin_comment
comment|///    The value from which bits are extracted.
end_comment

begin_comment
comment|/// \param __y
end_comment

begin_comment
comment|///    Specifies the index of the least significant bit at [13:8]
end_comment

begin_comment
comment|///    and the length at [5:0]; all other bits are ignored.
end_comment

begin_comment
comment|///    If bits [5:0] are zero, the length is interpreted as 64.
end_comment

begin_comment
comment|///    If the sum of the index and length is greater than 64, the result is
end_comment

begin_comment
comment|///    undefined. If the length and index are both zero, bits [63:0] of
end_comment

begin_comment
comment|///    parameter __x are extracted. If the length is zero but the index is
end_comment

begin_comment
comment|///    non-zero, the result is undefined.
end_comment

begin_comment
comment|/// \returns A 128-bit vector whose lower 64 bits contain the bits extracted
end_comment

begin_comment
comment|///    from the source operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_extract_si64
parameter_list|(
name|__m128i
name|__x
parameter_list|,
name|__m128i
name|__y
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_extrq
argument_list|(
operator|(
name|__v2di
operator|)
name|__x
argument_list|,
operator|(
name|__v16qi
operator|)
name|__y
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Inserts bits of a specified length from the source integer vector
end_comment

begin_comment
comment|///    y into the lower 64 bits of the destination integer vector x at the
end_comment

begin_comment
comment|///    index idx and of the length len.
end_comment

begin_comment
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
comment|/// __m128i _mm_inserti_si64(__m128i x, __m128i y, const int len,
end_comment

begin_comment
comment|/// const int idx);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c INSERTQ instruction.
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param x
end_comment

begin_comment
comment|///    The destination operand where bits will be inserted. The inserted bits
end_comment

begin_comment
comment|///    are defined by the length len and by the index idx specifying the least
end_comment

begin_comment
comment|///    significant bit.
end_comment

begin_comment
comment|/// \param y
end_comment

begin_comment
comment|///    The source operand containing the bits to be extracted. The extracted
end_comment

begin_comment
comment|///    bits are the least significant bits of operand y of length len.
end_comment

begin_comment
comment|/// \param len
end_comment

begin_comment
comment|///    Bits [5:0] specify the length; the other bits are ignored. If bits [5:0]
end_comment

begin_comment
comment|///    are zero, the length is interpreted as 64.
end_comment

begin_comment
comment|/// \param idx
end_comment

begin_comment
comment|///    Bits [5:0] specify the index of the least significant bit; the other
end_comment

begin_comment
comment|///    bits are ignored. If the sum of the index and length is greater than
end_comment

begin_comment
comment|///    64, the result is undefined. If the length and index are both zero,
end_comment

begin_comment
comment|///    bits [63:0] of parameter y are inserted into parameter x. If the
end_comment

begin_comment
comment|///    length is zero but the index is non-zero, the result is undefined.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the original lower 64-bits
end_comment

begin_comment
comment|///    of destination operand x with the specified bitfields replaced by the
end_comment

begin_comment
comment|///    lower bits of source operand y. The upper 64 bits of the return value
end_comment

begin_comment
comment|///    are undefined.
end_comment

begin_define
define|#
directive|define
name|_mm_inserti_si64
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|len
parameter_list|,
name|idx
parameter_list|)
define|\
value|((__m128i)__builtin_ia32_insertqi((__v2di)(__m128i)(x), \                                     (__v2di)(__m128i)(y), \                                     (char)(len), (char)(idx)))
end_define

begin_comment
comment|/// \brief Inserts bits of a specified length from the source integer vector
end_comment

begin_comment
comment|///    __y into the lower 64 bits of the destination integer vector __x at
end_comment

begin_comment
comment|///    the index and of the length specified by __y.
end_comment

begin_comment
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
comment|/// This intrinsic corresponds to the \c INSERTQ instruction.
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __x
end_comment

begin_comment
comment|///    The destination operand where bits will be inserted. The inserted bits
end_comment

begin_comment
comment|///    are defined by the length and by the index of the least significant bit
end_comment

begin_comment
comment|///    specified by operand __y.
end_comment

begin_comment
comment|/// \param __y
end_comment

begin_comment
comment|///    The source operand containing the bits to be extracted. The extracted
end_comment

begin_comment
comment|///    bits are the least significant bits of operand __y with length specified
end_comment

begin_comment
comment|///    by bits [69:64]. These are inserted into the destination at the index
end_comment

begin_comment
comment|///    specified by bits [77:72]; all other bits are ignored.
end_comment

begin_comment
comment|///    If bits [69:64] are zero, the length is interpreted as 64.
end_comment

begin_comment
comment|///    If the sum of the index and length is greater than 64, the result is
end_comment

begin_comment
comment|///    undefined. If the length and index are both zero, bits [63:0] of
end_comment

begin_comment
comment|///    parameter __y are inserted into parameter __x. If the length
end_comment

begin_comment
comment|///    is zero but the index is non-zero, the result is undefined.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the original lower 64-bits
end_comment

begin_comment
comment|///    of destination operand __x with the specified bitfields replaced by the
end_comment

begin_comment
comment|///    lower bits of source operand __y. The upper 64 bits of the return value
end_comment

begin_comment
comment|///    are undefined.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_insert_si64
parameter_list|(
name|__m128i
name|__x
parameter_list|,
name|__m128i
name|__y
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_insertq
argument_list|(
operator|(
name|__v2di
operator|)
name|__x
argument_list|,
operator|(
name|__v2di
operator|)
name|__y
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Stores a 64-bit double-precision value in a 64-bit memory location.
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
comment|/// \code
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c MOVNTSD instruction.
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    The 64-bit memory location used to store the register value.
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    The 64-bit double-precision floating-point register value to
end_comment

begin_comment
comment|///    be stored.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_stream_sd
parameter_list|(
name|double
modifier|*
name|__p
parameter_list|,
name|__m128d
name|__a
parameter_list|)
block|{
name|__builtin_ia32_movntsd
argument_list|(
name|__p
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Stores a 32-bit single-precision floating-point value in a 32-bit
end_comment

begin_comment
comment|///    memory location. To minimize caching, the data is flagged as
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
comment|/// \code
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c MOVNTSS instruction.
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    The 32-bit memory location used to store the register value.
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    The 32-bit single-precision floating-point register value to
end_comment

begin_comment
comment|///    be stored.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_stream_ss
parameter_list|(
name|float
modifier|*
name|__p
parameter_list|,
name|__m128
name|__a
parameter_list|)
block|{
name|__builtin_ia32_movntss
argument_list|(
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
comment|/* __AMMINTRIN_H */
end_comment

end_unit

