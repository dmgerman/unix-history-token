begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- __wmmintrin_pclmul.h - PCMUL intrinsics ---------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WMMINTRIN_PCLMUL_H
end_ifndef

begin_define
define|#
directive|define
name|_WMMINTRIN_PCLMUL_H
end_define

begin_comment
comment|/// \brief Multiplies two 64-bit integer values, which are selected from source
end_comment

begin_comment
comment|///    operands using the immediate-value operand. The multiplication is a
end_comment

begin_comment
comment|///    carry-less multiplication, and the 128-bit integer product is stored in
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
comment|/// \code
end_comment

begin_comment
comment|/// __m128i _mm_clmulepi64_si128(__m128i __X, __m128i __Y, const int __I);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VPCLMULQDQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x i64] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __Y
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x i64] containing one of the source operands.
end_comment

begin_comment
comment|/// \param __I
end_comment

begin_comment
comment|///    An immediate value specifying which 64-bit values to select from the
end_comment

begin_comment
comment|///    operands. Bit 0 is used to select a value from operand \a __X, and bit
end_comment

begin_comment
comment|///    4 is used to select a value from operand \a __Y: \n
end_comment

begin_comment
comment|///    Bit[0]=0 indicates that bits[63:0] of operand \a __X are used. \n
end_comment

begin_comment
comment|///    Bit[0]=1 indicates that bits[127:64] of operand \a __X are used. \n
end_comment

begin_comment
comment|///    Bit[4]=0 indicates that bits[63:0] of operand \a __Y are used. \n
end_comment

begin_comment
comment|///    Bit[4]=1 indicates that bits[127:64] of operand \a __Y are used.
end_comment

begin_comment
comment|/// \returns The 128-bit integer vector containing the result of the carry-less
end_comment

begin_comment
comment|///    multiplication of the selected 64-bit values.
end_comment

begin_define
define|#
directive|define
name|_mm_clmulepi64_si128
parameter_list|(
name|__X
parameter_list|,
name|__Y
parameter_list|,
name|__I
parameter_list|)
define|\
value|((__m128i)__builtin_ia32_pclmulqdq128((__v2di)(__m128i)(__X), \                                         (__v2di)(__m128i)(__Y), (char)(__I)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _WMMINTRIN_PCLMUL_H */
end_comment

end_unit

