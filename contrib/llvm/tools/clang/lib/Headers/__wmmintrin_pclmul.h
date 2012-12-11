begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- __wmmintrin_pclmul.h - AES intrinsics ----------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__PCLMUL__
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"PCLMUL instruction is not enabled"
end_error

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _WMMINTRIN_PCLMUL_H */
end_comment

end_unit

