begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- prfchwintrin.h - PREFETCHW intrinsic -----------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__X86INTRIN_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_MM3DNOW_H_INCLUDED
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Never use<prfchwintrin.h> directly; include<x86intrin.h> or<mm3dnow.h> instead."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__PRFCHWINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__PRFCHWINTRIN_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__PRFCHW__
argument_list|)
operator|||
name|defined
argument_list|(
name|__3dNOW__
argument_list|)
end_if

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
name|_m_prefetchw
argument_list|(
name|void
operator|*
name|__P
argument_list|)
block|{
name|__builtin_prefetch
argument_list|(
name|__P
argument_list|,
literal|1
argument_list|,
literal|3
comment|/* _MM_HINT_T0 */
argument_list|)
expr_stmt|;
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
comment|/* __PRFCHWINTRIN_H */
end_comment

end_unit

