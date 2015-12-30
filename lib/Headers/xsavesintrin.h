begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- xsavesintrin.h - XSAVES intrinsic ------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IMMINTRIN_H
end_ifndef

begin_error
error|#
directive|error
literal|"Never use<xsavesintrin.h> directly; include<immintrin.h> instead."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__XSAVESINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__XSAVESINTRIN_H
end_define

begin_comment
comment|/* Define the default attributes for the functions in this file. */
end_comment

begin_define
define|#
directive|define
name|__DEFAULT_FN_ATTRS
value|__attribute__((__always_inline__, __nodebug__,  __target__("xsaves")))
end_define

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_xsaves
parameter_list|(
name|void
modifier|*
name|__p
parameter_list|,
name|unsigned
name|long
name|long
name|__m
parameter_list|)
block|{
name|__builtin_ia32_xsaves
argument_list|(
name|__p
argument_list|,
name|__m
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_xrstors
parameter_list|(
name|void
modifier|*
name|__p
parameter_list|,
name|unsigned
name|long
name|long
name|__m
parameter_list|)
block|{
name|__builtin_ia32_xrstors
argument_list|(
name|__p
argument_list|,
name|__m
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_xrstors64
parameter_list|(
name|void
modifier|*
name|__p
parameter_list|,
name|unsigned
name|long
name|long
name|__m
parameter_list|)
block|{
name|__builtin_ia32_xrstors64
argument_list|(
name|__p
argument_list|,
name|__m
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_xsaves64
parameter_list|(
name|void
modifier|*
name|__p
parameter_list|,
name|unsigned
name|long
name|long
name|__m
parameter_list|)
block|{
name|__builtin_ia32_xsaves64
argument_list|(
name|__p
argument_list|,
name|__m
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|__DEFAULT_FN_ATTRS
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

