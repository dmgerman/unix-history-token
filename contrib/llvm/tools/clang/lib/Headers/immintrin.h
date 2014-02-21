begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- immintrin.h - Intel intrinsics -----------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IMMINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__IMMINTRIN_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__MMX__
end_ifdef

begin_include
include|#
directive|include
file|<mmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__SSE__
end_ifdef

begin_include
include|#
directive|include
file|<xmmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__SSE2__
end_ifdef

begin_include
include|#
directive|include
file|<emmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__SSE3__
end_ifdef

begin_include
include|#
directive|include
file|<pmmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__SSSE3__
end_ifdef

begin_include
include|#
directive|include
file|<tmmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SSE4_2__
argument_list|)
operator|||
name|defined
argument_list|(
name|__SSE4_1__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<smmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__AES__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<wmmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__AVX__
end_ifdef

begin_include
include|#
directive|include
file|<avxintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__AVX2__
end_ifdef

begin_include
include|#
directive|include
file|<avx2intrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__BMI__
end_ifdef

begin_include
include|#
directive|include
file|<bmiintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__BMI2__
end_ifdef

begin_include
include|#
directive|include
file|<bmi2intrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__LZCNT__
end_ifdef

begin_include
include|#
directive|include
file|<lzcntintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__FMA__
end_ifdef

begin_include
include|#
directive|include
file|<fmaintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__RDRND__
end_ifdef

begin_decl_stmt
specifier|static
name|__inline__
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_rdrand16_step
argument_list|(
name|unsigned
name|short
operator|*
name|__p
argument_list|)
block|{
return|return
name|__builtin_ia32_rdrand16_step
argument_list|(
name|__p
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_rdrand32_step
argument_list|(
name|unsigned
name|int
operator|*
name|__p
argument_list|)
block|{
return|return
name|__builtin_ia32_rdrand32_step
argument_list|(
name|__p
argument_list|)
return|;
block|}
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_decl_stmt
specifier|static
name|__inline__
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_rdrand64_step
argument_list|(
name|unsigned
name|long
name|long
operator|*
name|__p
argument_list|)
block|{
return|return
name|__builtin_ia32_rdrand64_step
argument_list|(
name|__p
argument_list|)
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __RDRND__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__RTM__
end_ifdef

begin_include
include|#
directive|include
file|<rtmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FIXME: check __HLE__ as well when HLE is supported. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__RTM__
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|__inline__
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_xtest
argument_list|(
name|void
argument_list|)
block|{
return|return
name|__builtin_ia32_xtest
argument_list|()
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__SHA__
end_ifdef

begin_include
include|#
directive|include
file|<shaintrin.h>
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
comment|/* __IMMINTRIN_H */
end_comment

end_unit

