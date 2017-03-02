begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- lzcntintrin.h - LZCNT intrinsics ---------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|__X86INTRIN_H
operator|&&
operator|!
name|defined
name|__IMMINTRIN_H
end_if

begin_error
error|#
directive|error
literal|"Never use<lzcntintrin.h> directly; include<x86intrin.h> instead."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__LZCNTINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__LZCNTINTRIN_H
end_define

begin_comment
comment|/* Define the default attributes for the functions in this file. */
end_comment

begin_define
define|#
directive|define
name|__DEFAULT_FN_ATTRS
value|__attribute__((__always_inline__, __nodebug__, __target__("lzcnt")))
end_define

begin_comment
comment|/// \brief Counts the number of leading zero bits in the operand.
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
comment|/// This intrinsic corresponds to the \c LZCNT instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned 16-bit integer whose leading zeros are to be counted.
end_comment

begin_comment
comment|/// \returns An unsigned 16-bit integer containing the number of leading zero
end_comment

begin_comment
comment|///    bits in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|short
name|__DEFAULT_FN_ATTRS
name|__lzcnt16
parameter_list|(
name|unsigned
name|short
name|__X
parameter_list|)
block|{
return|return
name|__X
condition|?
name|__builtin_clzs
argument_list|(
name|__X
argument_list|)
else|:
literal|16
return|;
block|}
end_function

begin_comment
comment|/// \brief Counts the number of leading zero bits in the operand.
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
comment|/// This intrinsic corresponds to the \c LZCNT instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned 32-bit integer whose leading zeros are to be counted.
end_comment

begin_comment
comment|/// \returns An unsigned 32-bit integer containing the number of leading zero
end_comment

begin_comment
comment|///    bits in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|__DEFAULT_FN_ATTRS
name|__lzcnt32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|)
block|{
return|return
name|__X
condition|?
name|__builtin_clz
argument_list|(
name|__X
argument_list|)
else|:
literal|32
return|;
block|}
end_function

begin_comment
comment|/// \brief Counts the number of leading zero bits in the operand.
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
comment|/// This intrinsic corresponds to the \c LZCNT instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned 32-bit integer whose leading zeros are to be counted.
end_comment

begin_comment
comment|/// \returns An unsigned 32-bit integer containing the number of leading zero
end_comment

begin_comment
comment|///    bits in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|__DEFAULT_FN_ATTRS
name|_lzcnt_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|)
block|{
return|return
name|__X
condition|?
name|__builtin_clz
argument_list|(
name|__X
argument_list|)
else|:
literal|32
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_comment
comment|/// \brief Counts the number of leading zero bits in the operand.
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
comment|/// This intrinsic corresponds to the \c LZCNT instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned 64-bit integer whose leading zeros are to be counted.
end_comment

begin_comment
comment|/// \returns An unsigned 64-bit integer containing the number of leading zero
end_comment

begin_comment
comment|///    bits in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|long
name|long
name|__DEFAULT_FN_ATTRS
name|__lzcnt64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|)
block|{
return|return
name|__X
condition|?
name|__builtin_clzll
argument_list|(
name|__X
argument_list|)
else|:
literal|64
return|;
block|}
end_function

begin_comment
comment|/// \brief Counts the number of leading zero bits in the operand.
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
comment|/// This intrinsic corresponds to the \c LZCNT instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned 64-bit integer whose leading zeros are to be counted.
end_comment

begin_comment
comment|/// \returns An unsigned 64-bit integer containing the number of leading zero
end_comment

begin_comment
comment|///    bits in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|long
name|long
name|__DEFAULT_FN_ATTRS
name|_lzcnt_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|)
block|{
return|return
name|__X
condition|?
name|__builtin_clzll
argument_list|(
name|__X
argument_list|)
else|:
literal|64
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

begin_comment
comment|/* __LZCNTINTRIN_H */
end_comment

end_unit

