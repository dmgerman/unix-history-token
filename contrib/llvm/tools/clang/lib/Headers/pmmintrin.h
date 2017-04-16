begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- pmmintrin.h - SSE3 intrinsics ------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PMMINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__PMMINTRIN_H
end_define

begin_include
include|#
directive|include
file|<emmintrin.h>
end_include

begin_comment
comment|/* Define the default attributes for the functions in this file. */
end_comment

begin_define
define|#
directive|define
name|__DEFAULT_FN_ATTRS
define|\
value|__attribute__((__always_inline__, __nodebug__, __target__("sse3")))
end_define

begin_comment
comment|/// \brief Loads data from an unaligned memory location to elements in a 128-bit
end_comment

begin_comment
comment|///    vector. If the address of the data is not 16-byte aligned, the
end_comment

begin_comment
comment|///    instruction may read two adjacent aligned blocks of memory to retrieve
end_comment

begin_comment
comment|///    the requested data.
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
comment|/// This intrinsic corresponds to the<c> VLDDQU</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to a 128-bit integer vector containing integer values.
end_comment

begin_comment
comment|/// \returns A 128-bit vector containing the moved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_lddqu_si128
parameter_list|(
name|__m128i
specifier|const
modifier|*
name|__p
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_lddqu
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
name|__p
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds the even-indexed values and subtracts the odd-indexed values of
end_comment

begin_comment
comment|///    two 128-bit vectors of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VADDSUBPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing the left source operand.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing the right source operand.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the alternating sums and
end_comment

begin_comment
comment|///    differences of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_addsub_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_addsubps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Horizontally adds the adjacent pairs of values contained in two
end_comment

begin_comment
comment|///    128-bit vectors of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VHADDPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the source operands.
end_comment

begin_comment
comment|///    The horizontal sums of the values are stored in the lower bits of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the source operands.
end_comment

begin_comment
comment|///    The horizontal sums of the values are stored in the upper bits of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the horizontal sums of
end_comment

begin_comment
comment|///    both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_hadd_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_haddps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Horizontally subtracts the adjacent pairs of values contained in two
end_comment

begin_comment
comment|///    128-bit vectors of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VHSUBPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the source operands.
end_comment

begin_comment
comment|///    The horizontal differences between the values are stored in the lower
end_comment

begin_comment
comment|///    bits of the destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] containing one of the source operands.
end_comment

begin_comment
comment|///    The horizontal differences between the values are stored in the upper
end_comment

begin_comment
comment|///    bits of the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the horizontal
end_comment

begin_comment
comment|///    differences of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_hsub_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_hsubps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Moves and duplicates high-order (odd-indexed) values from a 128-bit
end_comment

begin_comment
comment|///    vector of [4 x float] to float values stored in a 128-bit vector of
end_comment

begin_comment
comment|///    [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VMOVSHDUP</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float]. \n
end_comment

begin_comment
comment|///    Bits [127:96] of the source are written to bits [127:96] and [95:64] of
end_comment

begin_comment
comment|///    the destination. \n
end_comment

begin_comment
comment|///    Bits [63:32] of the source are written to bits [63:32] and [31:0] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the moved and duplicated
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_movehdup_ps
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Duplicates low-order (even-indexed) values from a 128-bit vector of
end_comment

begin_comment
comment|///    [4 x float] to float values stored in a 128-bit vector of [4 x float].
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
comment|/// This intrinsic corresponds to the<c> VMOVSLDUP</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float] \n
end_comment

begin_comment
comment|///    Bits [95:64] of the source are written to bits [127:96] and [95:64] of
end_comment

begin_comment
comment|///    the destination. \n
end_comment

begin_comment
comment|///    Bits [31:0] of the source are written to bits [63:32] and [31:0] of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the moved and duplicated
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_moveldup_ps
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds the even-indexed values and subtracts the odd-indexed values of
end_comment

begin_comment
comment|///    two 128-bit vectors of [2 x double].
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
comment|/// This intrinsic corresponds to the<c> VADDSUBPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing the left source operand.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing the right source operand.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the alternating sums
end_comment

begin_comment
comment|///    and differences of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_addsub_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_addsubpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Horizontally adds the pairs of values contained in two 128-bit
end_comment

begin_comment
comment|///    vectors of [2 x double].
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
comment|/// This intrinsic corresponds to the<c> VHADDPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the source operands.
end_comment

begin_comment
comment|///    The horizontal sum of the values is stored in the lower bits of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the source operands.
end_comment

begin_comment
comment|///    The horizontal sum of the values is stored in the upper bits of the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the horizontal sums of
end_comment

begin_comment
comment|///    both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_hadd_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_haddpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Horizontally subtracts the pairs of values contained in two 128-bit
end_comment

begin_comment
comment|///    vectors of [2 x double].
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
comment|/// This intrinsic corresponds to the<c> VHSUBPD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the source operands.
end_comment

begin_comment
comment|///    The horizontal difference of the values is stored in the lower bits of
end_comment

begin_comment
comment|///    the destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double] containing one of the source operands.
end_comment

begin_comment
comment|///    The horizontal difference of the values is stored in the upper bits of
end_comment

begin_comment
comment|///    the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the horizontal
end_comment

begin_comment
comment|///    differences of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_hsub_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_hsubpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Moves and duplicates one double-precision value to double-precision
end_comment

begin_comment
comment|///    values stored in a 128-bit vector of [2 x double].
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
comment|/// \code
end_comment

begin_comment
comment|/// __m128d _mm_loaddup_pd(double const * dp);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VMOVDDUP</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param dp
end_comment

begin_comment
comment|///    A pointer to a double-precision value to be moved and duplicated.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the moved and
end_comment

begin_comment
comment|///    duplicated values.
end_comment

begin_define
define|#
directive|define
name|_mm_loaddup_pd
parameter_list|(
name|dp
parameter_list|)
value|_mm_load1_pd(dp)
end_define

begin_comment
comment|/// \brief Moves and duplicates the double-precision value in the lower bits of
end_comment

begin_comment
comment|///    a 128-bit vector of [2 x double] to double-precision values stored in a
end_comment

begin_comment
comment|///    128-bit vector of [2 x double].
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
comment|/// This intrinsic corresponds to the<c> VMOVDDUP</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. Bits [63:0] are written to bits
end_comment

begin_comment
comment|///    [127:64] and [63:0] of the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] containing the moved and
end_comment

begin_comment
comment|///    duplicated values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_movedup_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Establishes a linear address memory range to be monitored and puts
end_comment

begin_comment
comment|///    the processor in the monitor event pending state. Data stored in the
end_comment

begin_comment
comment|///    monitored address range causes the processor to exit the pending state.
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
comment|/// This intrinsic corresponds to the<c> MONITOR</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    The memory range to be monitored. The size of the range is determined by
end_comment

begin_comment
comment|///    CPUID function 0000_0005h.
end_comment

begin_comment
comment|/// \param __extensions
end_comment

begin_comment
comment|///    Optional extensions for the monitoring state.
end_comment

begin_comment
comment|/// \param __hints
end_comment

begin_comment
comment|///    Optional hints for the monitoring state.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_monitor
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
name|__builtin_ia32_monitor
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

begin_comment
comment|/// \brief Used with the MONITOR instruction to wait while the processor is in
end_comment

begin_comment
comment|///    the monitor event pending state. Data stored in the monitored address
end_comment

begin_comment
comment|///    range causes the processor to exit the pending state.
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
comment|/// This intrinsic corresponds to the<c> MWAIT</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __extensions
end_comment

begin_comment
comment|///    Optional extensions for the monitoring state, which may vary by
end_comment

begin_comment
comment|///    processor.
end_comment

begin_comment
comment|/// \param __hints
end_comment

begin_comment
comment|///    Optional hints for the monitoring state, which may vary by processor.
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_mwait
parameter_list|(
name|unsigned
name|__extensions
parameter_list|,
name|unsigned
name|__hints
parameter_list|)
block|{
name|__builtin_ia32_mwait
argument_list|(
name|__extensions
argument_list|,
name|__hints
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
comment|/* __PMMINTRIN_H */
end_comment

end_unit

