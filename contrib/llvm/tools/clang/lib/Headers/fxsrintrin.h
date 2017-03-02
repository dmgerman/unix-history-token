begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- fxsrintrin.h - FXSR intrinsic ------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IMMINTRIN_H
end_ifndef

begin_error
error|#
directive|error
literal|"Never use<fxsrintrin.h> directly; include<immintrin.h> instead."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__FXSRINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__FXSRINTRIN_H
end_define

begin_define
define|#
directive|define
name|__DEFAULT_FN_ATTRS
value|__attribute__((__always_inline__, __nodebug__,  __target__("fxsr")))
end_define

begin_comment
comment|/// \brief Saves the XMM, MMX, MXCSR and x87 FPU registers into a 512-byte
end_comment

begin_comment
comment|///    memory region pointed to by the input parameter \a __p.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> FXSAVE</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to a 512-byte memory region. The beginning of this memory
end_comment

begin_comment
comment|///    region should be aligned on a 16-byte boundary.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_fxsave
parameter_list|(
name|void
modifier|*
name|__p
parameter_list|)
block|{
return|return
name|__builtin_ia32_fxsave
argument_list|(
name|__p
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Restores the XMM, MMX, MXCSR and x87 FPU registers from the 512-byte
end_comment

begin_comment
comment|///    memory region pointed to by the input parameter \a __p. The contents of
end_comment

begin_comment
comment|///    this memory region should have been written to by a previous \c _fxsave
end_comment

begin_comment
comment|///    or \c _fxsave64 intrinsic.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> FXRSTOR</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to a 512-byte memory region. The beginning of this memory
end_comment

begin_comment
comment|///    region should be aligned on a 16-byte boundary.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_fxrstor
parameter_list|(
name|void
modifier|*
name|__p
parameter_list|)
block|{
return|return
name|__builtin_ia32_fxrstor
argument_list|(
name|__p
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_comment
comment|/// \brief Saves the XMM, MMX, MXCSR and x87 FPU registers into a 512-byte
end_comment

begin_comment
comment|///    memory region pointed to by the input parameter \a __p.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> FXSAVE64</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to a 512-byte memory region. The beginning of this memory
end_comment

begin_comment
comment|///    region should be aligned on a 16-byte boundary.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_fxsave64
parameter_list|(
name|void
modifier|*
name|__p
parameter_list|)
block|{
return|return
name|__builtin_ia32_fxsave64
argument_list|(
name|__p
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Restores the XMM, MMX, MXCSR and x87 FPU registers from the 512-byte
end_comment

begin_comment
comment|///    memory region pointed to by the input parameter \a __p. The contents of
end_comment

begin_comment
comment|///    this memory region should have been written to by a previous \c _fxsave
end_comment

begin_comment
comment|///    or \c _fxsave64 intrinsic.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> FXRSTOR64</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to a 512-byte memory region. The beginning of this memory
end_comment

begin_comment
comment|///    region should be aligned on a 16-byte boundary.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_fxrstor64
parameter_list|(
name|void
modifier|*
name|__p
parameter_list|)
block|{
return|return
name|__builtin_ia32_fxrstor64
argument_list|(
name|__p
argument_list|)
return|;
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

