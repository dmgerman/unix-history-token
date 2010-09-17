begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- nmmintrin.h - SSE4 intrinsics ------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NMMINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|_NMMINTRIN_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__SSE4_2__
end_ifndef

begin_error
error|#
directive|error
literal|"SSE4.2 instruction set not enabled"
end_error

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* To match expectations of gcc we put the sse4.2 definitions into smmintrin.h,    just include it now then.  */
end_comment

begin_include
include|#
directive|include
file|<smmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SSE4_2__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NMMINTRIN_H */
end_comment

end_unit

