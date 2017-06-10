begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- bmiintrin.h - BMI intrinsics -------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
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
literal|"Never use<bmiintrin.h> directly; include<x86intrin.h> instead."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__BMIINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__BMIINTRIN_H
end_define

begin_define
define|#
directive|define
name|_tzcnt_u16
parameter_list|(
name|a
parameter_list|)
value|(__tzcnt_u16((a)))
end_define

begin_define
define|#
directive|define
name|_andn_u32
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(__andn_u32((a), (b)))
end_define

begin_comment
comment|/* _bextr_u32 != __bextr_u32 */
end_comment

begin_define
define|#
directive|define
name|_blsi_u32
parameter_list|(
name|a
parameter_list|)
value|(__blsi_u32((a)))
end_define

begin_define
define|#
directive|define
name|_blsmsk_u32
parameter_list|(
name|a
parameter_list|)
value|(__blsmsk_u32((a)))
end_define

begin_define
define|#
directive|define
name|_blsr_u32
parameter_list|(
name|a
parameter_list|)
value|(__blsr_u32((a)))
end_define

begin_define
define|#
directive|define
name|_tzcnt_u32
parameter_list|(
name|a
parameter_list|)
value|(__tzcnt_u32((a)))
end_define

begin_comment
comment|/* Define the default attributes for the functions in this file. */
end_comment

begin_define
define|#
directive|define
name|__DEFAULT_FN_ATTRS
value|__attribute__((__always_inline__, __nodebug__, __target__("bmi")))
end_define

begin_comment
comment|/* Allow using the tzcnt intrinsics even for non-BMI targets. Since the TZCNT    instruction behaves as BSF on non-BMI targets, there is code that expects    to use it as a potentially faster version of BSF. */
end_comment

begin_define
define|#
directive|define
name|__RELAXED_FN_ATTRS
value|__attribute__((__always_inline__, __nodebug__))
end_define

begin_comment
comment|/// \brief Counts the number of trailing zero bits in the operand.
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
comment|/// This intrinsic corresponds to the<c> TZCNT</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned 16-bit integer whose trailing zeros are to be counted.
end_comment

begin_comment
comment|/// \returns An unsigned 16-bit integer containing the number of trailing zero
end_comment

begin_comment
comment|///    bits in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|short
name|__RELAXED_FN_ATTRS
name|__tzcnt_u16
parameter_list|(
name|unsigned
name|short
name|__X
parameter_list|)
block|{
return|return
name|__X
condition|?
name|__builtin_ctzs
argument_list|(
name|__X
argument_list|)
else|:
literal|16
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise AND of the second operand with the one's
end_comment

begin_comment
comment|///    complement of the first operand.
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
comment|/// This intrinsic corresponds to the<c> ANDN</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned integer containing one of the operands.
end_comment

begin_comment
comment|/// \param __Y
end_comment

begin_comment
comment|///    An unsigned integer containing one of the operands.
end_comment

begin_comment
comment|/// \returns An unsigned integer containing the bitwise AND of the second
end_comment

begin_comment
comment|///    operand with the one's complement of the first operand.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|__DEFAULT_FN_ATTRS
name|__andn_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|,
name|unsigned
name|int
name|__Y
parameter_list|)
block|{
return|return
operator|~
name|__X
operator|&
name|__Y
return|;
block|}
end_function

begin_comment
comment|/* AMD-specified, double-leading-underscore version of BEXTR */
end_comment

begin_comment
comment|/// \brief Extracts the specified bits from the first operand and returns them
end_comment

begin_comment
comment|///    in the least significant bits of the result.
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
comment|/// This intrinsic corresponds to the<c> BEXTR</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned integer whose bits are to be extracted.
end_comment

begin_comment
comment|/// \param __Y
end_comment

begin_comment
comment|///    An unsigned integer used to specify which bits are extracted. Bits [7:0]
end_comment

begin_comment
comment|///    specify the index of the least significant bit. Bits [15:8] specify the
end_comment

begin_comment
comment|///    number of bits to be extracted.
end_comment

begin_comment
comment|/// \returns An unsigned integer whose least significant bits contain the
end_comment

begin_comment
comment|///    extracted bits.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|__DEFAULT_FN_ATTRS
name|__bextr_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|,
name|unsigned
name|int
name|__Y
parameter_list|)
block|{
return|return
name|__builtin_ia32_bextr_u32
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Intel-specified, single-leading-underscore version of BEXTR */
end_comment

begin_comment
comment|/// \brief Extracts the specified bits from the first operand and returns them
end_comment

begin_comment
comment|///    in the least significant bits of the result.
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
comment|/// This intrinsic corresponds to the<c> BEXTR</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned integer whose bits are to be extracted.
end_comment

begin_comment
comment|/// \param __Y
end_comment

begin_comment
comment|///    An unsigned integer used to specify the index of the least significant
end_comment

begin_comment
comment|///    bit for the bits to be extracted. Bits [7:0] specify the index.
end_comment

begin_comment
comment|/// \param __Z
end_comment

begin_comment
comment|///    An unsigned integer used to specify the number of bits to be extracted.
end_comment

begin_comment
comment|///    Bits [7:0] specify the number of bits.
end_comment

begin_comment
comment|/// \returns An unsigned integer whose least significant bits contain the
end_comment

begin_comment
comment|///    extracted bits.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|__DEFAULT_FN_ATTRS
name|_bextr_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|,
name|unsigned
name|int
name|__Y
parameter_list|,
name|unsigned
name|int
name|__Z
parameter_list|)
block|{
return|return
name|__builtin_ia32_bextr_u32
argument_list|(
name|__X
argument_list|,
operator|(
operator|(
name|__Y
operator|&
literal|0xff
operator|)
operator||
operator|(
operator|(
name|__Z
operator|&
literal|0xff
operator|)
operator|<<
literal|8
operator|)
operator|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Clears all bits in the source except for the least significant bit
end_comment

begin_comment
comment|///    containing a value of 1 and returns the result.
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
comment|/// This intrinsic corresponds to the<c> BLSI</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned integer whose bits are to be cleared.
end_comment

begin_comment
comment|/// \returns An unsigned integer containing the result of clearing the bits from
end_comment

begin_comment
comment|///    the source operand.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|__DEFAULT_FN_ATTRS
name|__blsi_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|)
block|{
return|return
name|__X
operator|&
operator|-
name|__X
return|;
block|}
end_function

begin_comment
comment|/// \brief Creates a mask whose bits are set to 1, using bit 0 up to and
end_comment

begin_comment
comment|///    including the least significant bit that is set to 1 in the source
end_comment

begin_comment
comment|///    operand and returns the result.
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
comment|/// This intrinsic corresponds to the<c> BLSMSK</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned integer used to create the mask.
end_comment

begin_comment
comment|/// \returns An unsigned integer containing the newly created mask.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|__DEFAULT_FN_ATTRS
name|__blsmsk_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|)
block|{
return|return
name|__X
operator|^
operator|(
name|__X
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Clears the least significant bit that is set to 1 in the source
end_comment

begin_comment
comment|///    operand and returns the result.
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
comment|/// This intrinsic corresponds to the<c> BLSR</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned integer containing the operand to be cleared.
end_comment

begin_comment
comment|/// \returns An unsigned integer containing the result of clearing the source
end_comment

begin_comment
comment|///    operand.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|__DEFAULT_FN_ATTRS
name|__blsr_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|)
block|{
return|return
name|__X
operator|&
operator|(
name|__X
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Counts the number of trailing zero bits in the operand.
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
comment|/// This intrinsic corresponds to the<c> TZCNT</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned 32-bit integer whose trailing zeros are to be counted.
end_comment

begin_comment
comment|/// \returns An unsigned 32-bit integer containing the number of trailing zero
end_comment

begin_comment
comment|///    bits in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|__RELAXED_FN_ATTRS
name|__tzcnt_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|)
block|{
return|return
name|__X
condition|?
name|__builtin_ctz
argument_list|(
name|__X
argument_list|)
else|:
literal|32
return|;
block|}
end_function

begin_comment
comment|/// \brief Counts the number of trailing zero bits in the operand.
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
comment|/// This intrinsic corresponds to the<c> TZCNT</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned 32-bit integer whose trailing zeros are to be counted.
end_comment

begin_comment
comment|/// \returns An 32-bit integer containing the number of trailing zero bits in
end_comment

begin_comment
comment|///    the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__RELAXED_FN_ATTRS
name|_mm_tzcnt_32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|)
block|{
return|return
name|__X
condition|?
name|__builtin_ctz
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

begin_define
define|#
directive|define
name|_andn_u64
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(__andn_u64((a), (b)))
end_define

begin_comment
comment|/* _bextr_u64 != __bextr_u64 */
end_comment

begin_define
define|#
directive|define
name|_blsi_u64
parameter_list|(
name|a
parameter_list|)
value|(__blsi_u64((a)))
end_define

begin_define
define|#
directive|define
name|_blsmsk_u64
parameter_list|(
name|a
parameter_list|)
value|(__blsmsk_u64((a)))
end_define

begin_define
define|#
directive|define
name|_blsr_u64
parameter_list|(
name|a
parameter_list|)
value|(__blsr_u64((a)))
end_define

begin_define
define|#
directive|define
name|_tzcnt_u64
parameter_list|(
name|a
parameter_list|)
value|(__tzcnt_u64((a)))
end_define

begin_comment
comment|/// \brief Performs a bitwise AND of the second operand with the one's
end_comment

begin_comment
comment|///    complement of the first operand.
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
comment|/// This intrinsic corresponds to the<c> ANDN</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned 64-bit integer containing one of the operands.
end_comment

begin_comment
comment|/// \param __Y
end_comment

begin_comment
comment|///    An unsigned 64-bit integer containing one of the operands.
end_comment

begin_comment
comment|/// \returns An unsigned 64-bit integer containing the bitwise AND of the second
end_comment

begin_comment
comment|///    operand with the one's complement of the first operand.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|long
name|long
name|__DEFAULT_FN_ATTRS
name|__andn_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|,
name|unsigned
name|long
name|long
name|__Y
parameter_list|)
block|{
return|return
operator|~
name|__X
operator|&
name|__Y
return|;
block|}
end_function

begin_comment
comment|/* AMD-specified, double-leading-underscore version of BEXTR */
end_comment

begin_comment
comment|/// \brief Extracts the specified bits from the first operand and returns them
end_comment

begin_comment
comment|///    in the least significant bits of the result.
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
comment|/// This intrinsic corresponds to the<c> BEXTR</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned 64-bit integer whose bits are to be extracted.
end_comment

begin_comment
comment|/// \param __Y
end_comment

begin_comment
comment|///    An unsigned 64-bit integer used to specify which bits are extracted. Bits
end_comment

begin_comment
comment|///    [7:0] specify the index of the least significant bit. Bits [15:8] specify
end_comment

begin_comment
comment|///    the number of bits to be extracted.
end_comment

begin_comment
comment|/// \returns An unsigned 64-bit integer whose least significant bits contain the
end_comment

begin_comment
comment|///    extracted bits.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|long
name|long
name|__DEFAULT_FN_ATTRS
name|__bextr_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|,
name|unsigned
name|long
name|long
name|__Y
parameter_list|)
block|{
return|return
name|__builtin_ia32_bextr_u64
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Intel-specified, single-leading-underscore version of BEXTR */
end_comment

begin_comment
comment|/// \brief Extracts the specified bits from the first operand and returns them
end_comment

begin_comment
comment|///     in the least significant bits of the result.
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
comment|/// This intrinsic corresponds to the<c> BEXTR</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned 64-bit integer whose bits are to be extracted.
end_comment

begin_comment
comment|/// \param __Y
end_comment

begin_comment
comment|///    An unsigned integer used to specify the index of the least significant
end_comment

begin_comment
comment|///    bit for the bits to be extracted. Bits [7:0] specify the index.
end_comment

begin_comment
comment|/// \param __Z
end_comment

begin_comment
comment|///    An unsigned integer used to specify the number of bits to be extracted.
end_comment

begin_comment
comment|///    Bits [7:0] specify the number of bits.
end_comment

begin_comment
comment|/// \returns An unsigned 64-bit integer whose least significant bits contain the
end_comment

begin_comment
comment|///    extracted bits.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|long
name|long
name|__DEFAULT_FN_ATTRS
name|_bextr_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|,
name|unsigned
name|int
name|__Y
parameter_list|,
name|unsigned
name|int
name|__Z
parameter_list|)
block|{
return|return
name|__builtin_ia32_bextr_u64
argument_list|(
name|__X
argument_list|,
operator|(
operator|(
name|__Y
operator|&
literal|0xff
operator|)
operator||
operator|(
operator|(
name|__Z
operator|&
literal|0xff
operator|)
operator|<<
literal|8
operator|)
operator|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Clears all bits in the source except for the least significant bit
end_comment

begin_comment
comment|///    containing a value of 1 and returns the result.
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
comment|/// This intrinsic corresponds to the<c> BLSI</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned 64-bit integer whose bits are to be cleared.
end_comment

begin_comment
comment|/// \returns An unsigned 64-bit integer containing the result of clearing the
end_comment

begin_comment
comment|///    bits from the source operand.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|long
name|long
name|__DEFAULT_FN_ATTRS
name|__blsi_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|)
block|{
return|return
name|__X
operator|&
operator|-
name|__X
return|;
block|}
end_function

begin_comment
comment|/// \brief Creates a mask whose bits are set to 1, using bit 0 up to and
end_comment

begin_comment
comment|///    including the least significant bit that is set to 1 in the source
end_comment

begin_comment
comment|///    operand and returns the result.
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
comment|/// This intrinsic corresponds to the<c> BLSMSK</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned 64-bit integer used to create the mask.
end_comment

begin_comment
comment|/// \returns A unsigned 64-bit integer containing the newly created mask.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|long
name|long
name|__DEFAULT_FN_ATTRS
name|__blsmsk_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|)
block|{
return|return
name|__X
operator|^
operator|(
name|__X
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Clears the least significant bit that is set to 1 in the source
end_comment

begin_comment
comment|///    operand and returns the result.
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
comment|/// This intrinsic corresponds to the<c> BLSR</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned 64-bit integer containing the operand to be cleared.
end_comment

begin_comment
comment|/// \returns An unsigned 64-bit integer containing the result of clearing the
end_comment

begin_comment
comment|///    source operand.
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|long
name|long
name|__DEFAULT_FN_ATTRS
name|__blsr_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|)
block|{
return|return
name|__X
operator|&
operator|(
name|__X
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Counts the number of trailing zero bits in the operand.
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
comment|/// This intrinsic corresponds to the<c> TZCNT</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned 64-bit integer whose trailing zeros are to be counted.
end_comment

begin_comment
comment|/// \returns An unsigned 64-bit integer containing the number of trailing zero
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
name|__RELAXED_FN_ATTRS
name|__tzcnt_u64
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
name|__builtin_ctzll
argument_list|(
name|__X
argument_list|)
else|:
literal|64
return|;
block|}
end_function

begin_comment
comment|/// \brief Counts the number of trailing zero bits in the operand.
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
comment|/// This intrinsic corresponds to the<c> TZCNT</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __X
end_comment

begin_comment
comment|///    An unsigned 64-bit integer whose trailing zeros are to be counted.
end_comment

begin_comment
comment|/// \returns An 64-bit integer containing the number of trailing zero bits in
end_comment

begin_comment
comment|///    the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|long
name|long
name|__RELAXED_FN_ATTRS
name|_mm_tzcnt_64
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
name|__builtin_ctzll
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

begin_comment
comment|/* __x86_64__ */
end_comment

begin_undef
undef|#
directive|undef
name|__DEFAULT_FN_ATTRS
end_undef

begin_undef
undef|#
directive|undef
name|__RELAXED_FN_ATTRS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BMIINTRIN_H */
end_comment

end_unit

