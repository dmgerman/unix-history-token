begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- rtmintrin.h - RTM intrinsics -------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IMMINTRIN_H
end_ifndef

begin_error
error|#
directive|error
literal|"Never use<rtmintrin.h> directly; include<immintrin.h> instead."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__RTMINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__RTMINTRIN_H
end_define

begin_define
define|#
directive|define
name|_XBEGIN_STARTED
value|(~0u)
end_define

begin_define
define|#
directive|define
name|_XABORT_EXPLICIT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|_XABORT_RETRY
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|_XABORT_CONFLICT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|_XABORT_CAPACITY
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|_XABORT_DEBUG
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|_XABORT_NESTED
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|_XABORT_CODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0xFF)
end_define

begin_decl_stmt
specifier|static
name|__inline__
name|unsigned
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_xbegin
argument_list|(
name|void
argument_list|)
block|{
return|return
name|__builtin_ia32_xbegin
argument_list|()
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
name|_xend
argument_list|(
name|void
argument_list|)
block|{
name|__builtin_ia32_xend
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_define
define|#
directive|define
name|_xabort
parameter_list|(
name|imm
parameter_list|)
value|__builtin_ia32_xabort((imm))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __RTMINTRIN_H */
end_comment

end_unit

