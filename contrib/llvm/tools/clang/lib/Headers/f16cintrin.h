begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- f16cintrin.h - F16C intrinsics -----------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|__X86INTRIN_H
operator|&&
operator|!
name|defined
name|__EMMINTRIN_H
operator|&&
operator|!
name|defined
name|__IMMINTRIN_H
end_if

begin_error
error|#
directive|error
literal|"Never use<f16cintrin.h> directly; include<emmintrin.h> instead."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__F16CINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__F16CINTRIN_H
end_define

begin_comment
comment|/* Define the default attributes for the functions in this file. */
end_comment

begin_define
define|#
directive|define
name|__DEFAULT_FN_ATTRS
define|\
value|__attribute__((__always_inline__, __nodebug__, __target__("f16c")))
end_define

begin_comment
comment|/// \brief Converts a 16-bit half-precision float value into a 32-bit float
end_comment

begin_comment
comment|///    value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTPH2PS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 16-bit half-precision float value.
end_comment

begin_comment
comment|/// \returns The converted 32-bit float value.
end_comment

begin_function
specifier|static
name|__inline
name|float
name|__DEFAULT_FN_ATTRS
name|_cvtsh_ss
parameter_list|(
name|unsigned
name|short
name|__a
parameter_list|)
block|{
name|__v8hi
name|v
init|=
block|{
operator|(
name|short
operator|)
name|__a
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
decl_stmt|;
name|__v4sf
name|r
init|=
name|__builtin_ia32_vcvtph2ps
argument_list|(
name|v
argument_list|)
decl_stmt|;
return|return
name|r
index|[
literal|0
index|]
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts a 32-bit single-precision float value to a 16-bit
end_comment

begin_comment
comment|///    half-precision float value.
end_comment

begin_comment
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
comment|/// unsigned short _cvtss_sh(float a, const int imm);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTPS2PH</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param a
end_comment

begin_comment
comment|///    A 32-bit single-precision float value to be converted to a 16-bit
end_comment

begin_comment
comment|///    half-precision float value.
end_comment

begin_comment
comment|/// \param imm
end_comment

begin_comment
comment|///    An immediate value controlling rounding using bits [2:0]: \n
end_comment

begin_comment
comment|///    000: Nearest \n
end_comment

begin_comment
comment|///    001: Down \n
end_comment

begin_comment
comment|///    010: Up \n
end_comment

begin_comment
comment|///    011: Truncate \n
end_comment

begin_comment
comment|///    1XX: Use MXCSR.RC for rounding
end_comment

begin_comment
comment|/// \returns The converted 16-bit half-precision float value.
end_comment

begin_define
define|#
directive|define
name|_cvtss_sh
parameter_list|(
name|a
parameter_list|,
name|imm
parameter_list|)
value|__extension__ ({ \   (unsigned short)(((__v8hi)__builtin_ia32_vcvtps2ph((__v4sf){a, 0, 0, 0}, \                                                      (imm)))[0]); })
end_define

begin_comment
comment|/// \brief Converts a 128-bit vector containing 32-bit float values into a
end_comment

begin_comment
comment|///    128-bit vector containing 16-bit half-precision float values.
end_comment

begin_comment
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
comment|/// __m128i _mm_cvtps_ph(__m128 a, const int imm);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTPS2PH</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param a
end_comment

begin_comment
comment|///    A 128-bit vector containing 32-bit float values.
end_comment

begin_comment
comment|/// \param imm
end_comment

begin_comment
comment|///    An immediate value controlling rounding using bits [2:0]: \n
end_comment

begin_comment
comment|///    000: Nearest \n
end_comment

begin_comment
comment|///    001: Down \n
end_comment

begin_comment
comment|///    010: Up \n
end_comment

begin_comment
comment|///    011: Truncate \n
end_comment

begin_comment
comment|///    1XX: Use MXCSR.RC for rounding
end_comment

begin_comment
comment|/// \returns A 128-bit vector containing converted 16-bit half-precision float
end_comment

begin_comment
comment|///    values. The lower 64 bits are used to store the converted 16-bit
end_comment

begin_comment
comment|///    half-precision floating-point values.
end_comment

begin_define
define|#
directive|define
name|_mm_cvtps_ph
parameter_list|(
name|a
parameter_list|,
name|imm
parameter_list|)
value|__extension__ ({ \   (__m128i)__builtin_ia32_vcvtps2ph((__v4sf)(__m128)(a), (imm)); })
end_define

begin_comment
comment|/// \brief Converts a 128-bit vector containing 16-bit half-precision float
end_comment

begin_comment
comment|///    values into a 128-bit vector containing 32-bit float values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTPH2PS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector containing 16-bit half-precision float values. The lower
end_comment

begin_comment
comment|///    64 bits are used in the conversion.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing converted float values.
end_comment

begin_function
specifier|static
name|__inline
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cvtph_ps
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_vcvtph2ps
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
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
comment|/* __F16CINTRIN_H */
end_comment

end_unit

