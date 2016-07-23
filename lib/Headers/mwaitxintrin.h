begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- mwaitxintrin.h - MONITORX/MWAITX intrinsics ----------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__X86INTRIN_H
end_ifndef

begin_error
error|#
directive|error
literal|"Never use<mwaitxintrin.h> directly; include<x86intrin.h> instead."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_MWAITXINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|_MWAITXINTRIN_H
end_define

begin_comment
comment|/* Define the default attributes for the functions in this file. */
end_comment

begin_define
define|#
directive|define
name|__DEFAULT_FN_ATTRS
value|__attribute__((__always_inline__, __nodebug__,  __target__("mwaitx")))
end_define

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_monitorx
parameter_list|(
name|void
specifier|const
modifier|*
name|__p
parameter_list|,
name|unsigned
name|__extensions
parameter_list|,
name|unsigned
name|__hints
parameter_list|)
block|{
name|__builtin_ia32_monitorx
argument_list|(
operator|(
name|void
operator|*
operator|)
name|__p
argument_list|,
name|__extensions
argument_list|,
name|__hints
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_mwaitx
parameter_list|(
name|unsigned
name|__extensions
parameter_list|,
name|unsigned
name|__hints
parameter_list|,
name|unsigned
name|__clock
parameter_list|)
block|{
name|__builtin_ia32_mwaitx
argument_list|(
name|__extensions
argument_list|,
name|__hints
argument_list|,
name|__clock
argument_list|)
expr_stmt|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|__DEFAULT_FN_ATTRS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MWAITXINTRIN_H */
end_comment

end_unit

