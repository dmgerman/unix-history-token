begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- x86intrin.h - X86 intrinsics -------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__X86INTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__X86INTRIN_H
end_define

begin_include
include|#
directive|include
file|<ia32intrin.h>
end_include

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__3dNOW__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<mm3dnow.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__BMI__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<bmiintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__BMI2__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<bmi2intrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__LZCNT__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<lzcntintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__POPCNT__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<popcntintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__RDSEED__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<rdseedintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__PRFCHW__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<prfchwintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__SSE4A__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<ammintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__FMA4__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<fma4intrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__XOP__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<xopintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__TBM__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<tbmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__LWP__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<lwpintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__F16C__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<f16cintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__MWAITX__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<mwaitxintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__CLZERO__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<clzerointrin.h>
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
comment|/* __X86INTRIN_H */
end_comment

end_unit

