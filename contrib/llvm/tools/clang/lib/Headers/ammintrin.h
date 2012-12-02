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

begin_ifndef
ifndef|#
directive|ifndef
name|__SSE4A__
end_ifndef

begin_error
error|#
directive|error
literal|"SSE4A instruction set not enabled"
end_error

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<pmmintrin.h>
end_include

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

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_extract_si64
argument_list|(
name|__m128i
name|__x
argument_list|,
name|__m128i
name|__y
argument_list|)
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
end_decl_stmt

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

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_insert_si64
argument_list|(
name|__m128i
name|__x
argument_list|,
name|__m128i
name|__y
argument_list|)
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
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|void
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_stream_sd
argument_list|(
name|double
operator|*
name|__p
argument_list|,
name|__m128d
name|__a
argument_list|)
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
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|void
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_stream_ss
argument_list|(
name|float
operator|*
name|__p
argument_list|,
name|__m128
name|__a
argument_list|)
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
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SSE4A__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AMMINTRIN_H */
end_comment

end_unit

