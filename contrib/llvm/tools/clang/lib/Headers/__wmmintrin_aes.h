begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- __wmmintrin_aes.h - AES intrinsics -------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WMMINTRIN_AES_H
end_ifndef

begin_define
define|#
directive|define
name|_WMMINTRIN_AES_H
end_define

begin_include
include|#
directive|include
file|<emmintrin.h>
end_include

begin_comment
comment|/* Define the default attributes for the functions in this file. */
end_comment

begin_define
define|#
directive|define
name|__DEFAULT_FN_ATTRS
value|__attribute__((__always_inline__, __nodebug__, __target__("aes")))
end_define

begin_comment
comment|/// \brief Performs a single round of AES encryption using the Equivalent
end_comment

begin_comment
comment|///    Inverse Cipher, transforming the state value from the first source
end_comment

begin_comment
comment|///    operand using a 128-bit round key value contained in the second source
end_comment

begin_comment
comment|///    operand, and writes the result to the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VAESENC</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the state value.
end_comment

begin_comment
comment|/// \param __R
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the round key value.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the encrypted value.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_aesenc_si128
parameter_list|(
name|__m128i
name|__V
parameter_list|,
name|__m128i
name|__R
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_aesenc128
argument_list|(
operator|(
name|__v2di
operator|)
name|__V
argument_list|,
operator|(
name|__v2di
operator|)
name|__R
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs the final round of AES encryption using the Equivalent
end_comment

begin_comment
comment|///    Inverse Cipher, transforming the state value from the first source
end_comment

begin_comment
comment|///    operand using a 128-bit round key value contained in the second source
end_comment

begin_comment
comment|///    operand, and writes the result to the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VAESENCLAST</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the state value.
end_comment

begin_comment
comment|/// \param __R
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the round key value.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the encrypted value.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_aesenclast_si128
parameter_list|(
name|__m128i
name|__V
parameter_list|,
name|__m128i
name|__R
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_aesenclast128
argument_list|(
operator|(
name|__v2di
operator|)
name|__V
argument_list|,
operator|(
name|__v2di
operator|)
name|__R
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a single round of AES decryption using the Equivalent
end_comment

begin_comment
comment|///    Inverse Cipher, transforming the state value from the first source
end_comment

begin_comment
comment|///    operand using a 128-bit round key value contained in the second source
end_comment

begin_comment
comment|///    operand, and writes the result to the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VAESDEC</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the state value.
end_comment

begin_comment
comment|/// \param __R
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the round key value.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the decrypted value.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_aesdec_si128
parameter_list|(
name|__m128i
name|__V
parameter_list|,
name|__m128i
name|__R
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_aesdec128
argument_list|(
operator|(
name|__v2di
operator|)
name|__V
argument_list|,
operator|(
name|__v2di
operator|)
name|__R
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs the final round of AES decryption using the Equivalent
end_comment

begin_comment
comment|///    Inverse Cipher, transforming the state value from the first source
end_comment

begin_comment
comment|///    operand using a 128-bit round key value contained in the second source
end_comment

begin_comment
comment|///    operand, and writes the result to the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VAESDECLAST</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the state value.
end_comment

begin_comment
comment|/// \param __R
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the round key value.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the decrypted value.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_aesdeclast_si128
parameter_list|(
name|__m128i
name|__V
parameter_list|,
name|__m128i
name|__R
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_aesdeclast128
argument_list|(
operator|(
name|__v2di
operator|)
name|__V
argument_list|,
operator|(
name|__v2di
operator|)
name|__R
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Applies the AES InvMixColumns() transformation to an expanded key
end_comment

begin_comment
comment|///    contained in the source operand, and writes the result to the
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
comment|/// This intrinsic corresponds to the<c> VAESIMC</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __V
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the expanded key.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the transformed value.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_aesimc_si128
parameter_list|(
name|__m128i
name|__V
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_aesimc128
argument_list|(
operator|(
name|__v2di
operator|)
name|__V
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Generates a round key for AES encyption, operating on 128-bit data
end_comment

begin_comment
comment|///    specified in the first source operand and using an 8-bit round constant
end_comment

begin_comment
comment|///    specified by the second source operand, and writes the result to the
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
comment|/// \code
end_comment

begin_comment
comment|/// __m128i _mm_aeskeygenassist_si128(__m128i C, const int R);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> AESKEYGENASSIST</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param C
end_comment

begin_comment
comment|///    A 128-bit integer vector that is used to generate the AES encryption key.
end_comment

begin_comment
comment|/// \param R
end_comment

begin_comment
comment|///    An 8-bit round constant used to generate the AES encryption key.
end_comment

begin_comment
comment|/// \returns A 128-bit round key for AES encryption.
end_comment

begin_define
define|#
directive|define
name|_mm_aeskeygenassist_si128
parameter_list|(
name|C
parameter_list|,
name|R
parameter_list|)
define|\
value|(__m128i)__builtin_ia32_aeskeygenassist128((__v2di)(__m128i)(C), (int)(R))
end_define

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
comment|/* _WMMINTRIN_AES_H */
end_comment

end_unit

