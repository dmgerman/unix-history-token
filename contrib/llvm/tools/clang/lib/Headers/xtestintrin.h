begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- xtestintrin.h - XTEST intrinsic ---------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IMMINTRIN_H
end_ifndef

begin_error
error|#
directive|error
literal|"Never use<xtestintrin.h> directly; include<immintrin.h> instead."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__XTESTINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__XTESTINTRIN_H
end_define

begin_comment
comment|/* xtest returns non-zero if the instruction is executed within an RTM or active  * HLE region. */
end_comment

begin_comment
comment|/* FIXME: This can be an either or for RTM/HLE. Deal with this when HLE is  * supported. */
end_comment

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
operator|,
name|__target__
argument_list|(
literal|"rtm"
argument_list|)
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

end_unit

