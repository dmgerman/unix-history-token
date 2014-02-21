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
name|__IMMINTRIN_H
end_if

begin_error
error|#
directive|error
literal|"Never use<f16cintrin.h> directly; include<x86intrin.h> instead."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__F16C__
end_ifndef

begin_error
error|#
directive|error
literal|"F16C instruction is not enabled"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __F16C__ */
end_comment

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
name|float
name|__m256
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_define
define|#
directive|define
name|_mm_cvtps_ph
parameter_list|(
name|a
parameter_list|,
name|imm
parameter_list|)
value|__extension__ ({ \   __m128 __a = (a); \  (__m128i)__builtin_ia32_vcvtps2ph((__v4sf)__a, (imm)); })
end_define

begin_define
define|#
directive|define
name|_mm256_cvtps_ph
parameter_list|(
name|a
parameter_list|,
name|imm
parameter_list|)
value|__extension__ ({ \   __m256 __a = (a); \  (__m128i)__builtin_ia32_vcvtps2ph256((__v8sf)__a, (imm)); })
end_define

begin_decl_stmt
specifier|static
name|__inline
name|__m128
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_cvtph_ps
argument_list|(
name|__m128i
name|__a
argument_list|)
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
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|__m256
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm256_cvtph_ps
argument_list|(
name|__m128i
name|__a
argument_list|)
block|{
return|return
operator|(
name|__m256
operator|)
name|__builtin_ia32_vcvtph2ps256
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|)
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __F16CINTRIN_H */
end_comment

end_unit

