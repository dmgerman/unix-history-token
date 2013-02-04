begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- wmmintrin.h - AES intrinsics ------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WMMINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|_WMMINTRIN_H
end_define

begin_include
include|#
directive|include
file|<emmintrin.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__AES__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__PCLMUL__
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"AES/PCLMUL instructions not enabled"
end_error

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__AES__
end_ifdef

begin_include
include|#
directive|include
file|<__wmmintrin_aes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AES__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__PCLMUL__
end_ifdef

begin_include
include|#
directive|include
file|<__wmmintrin_pclmul.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PCLMUL__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AES__ || __PCLMUL__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _WMMINTRIN_H */
end_comment

end_unit

