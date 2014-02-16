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
file|<immintrin.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__3dNOW__
end_ifdef

begin_include
include|#
directive|include
file|<mm3dnow.h>
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

begin_ifdef
ifdef|#
directive|ifdef
name|__RDSEED__
end_ifdef

begin_include
include|#
directive|include
file|<rdseedintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__PRFCHW__
end_ifdef

begin_include
include|#
directive|include
file|<prfchwintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__SSE4A__
end_ifdef

begin_include
include|#
directive|include
file|<ammintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__FMA4__
end_ifdef

begin_include
include|#
directive|include
file|<fma4intrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__XOP__
end_ifdef

begin_include
include|#
directive|include
file|<xopintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__TBM__
end_ifdef

begin_include
include|#
directive|include
file|<tbmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__F16C__
end_ifdef

begin_include
include|#
directive|include
file|<f16cintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// FIXME: LWP
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __X86INTRIN_H */
end_comment

end_unit

