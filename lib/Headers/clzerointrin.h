begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===----------------------- clzerointrin.h - CLZERO ----------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__X86INTRIN_H
end_ifndef

begin_error
error|#
directive|error
literal|"Never use<clzerointrin.h> directly; include<x86intrin.h> instead."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_CLZEROINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|_CLZEROINTRIN_H
end_define

begin_comment
comment|/* Define the default attributes for the functions in this file. */
end_comment

begin_define
define|#
directive|define
name|__DEFAULT_FN_ATTRS
define|\
value|__attribute__((__always_inline__, __nodebug__,  __target__("clzero")))
end_define

begin_comment
comment|/// \brief Loads the cache line address and zero's out the cacheline
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<clzerointrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> CLZERO</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __line
end_comment

begin_comment
comment|///    A pointer to a cacheline which needs to be zeroed out.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_clzero
parameter_list|(
name|void
modifier|*
name|__line
parameter_list|)
block|{
name|__builtin_ia32_clzero
argument_list|(
operator|(
name|void
operator|*
operator|)
name|__line
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
comment|/* _CLZEROINTRIN_H */
end_comment

end_unit

