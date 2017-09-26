begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- mmintrin.h - MMX intrinsics --------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MMINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__MMINTRIN_H
end_define

begin_typedef
typedef|typedef
name|long
name|long
name|__m64
name|__attribute__
typedef|((
name|__vector_size__
typedef|(8)));
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|__v1di
name|__attribute__
typedef|((
name|__vector_size__
typedef|(8)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|__v2si
name|__attribute__
typedef|((
name|__vector_size__
typedef|(8)));
end_typedef

begin_typedef
typedef|typedef
name|short
name|__v4hi
name|__attribute__
typedef|((
name|__vector_size__
typedef|(8)));
end_typedef

begin_typedef
typedef|typedef
name|char
name|__v8qi
name|__attribute__
typedef|((
name|__vector_size__
typedef|(8)));
end_typedef

begin_comment
comment|/* Define the default attributes for the functions in this file. */
end_comment

begin_define
define|#
directive|define
name|__DEFAULT_FN_ATTRS
value|__attribute__((__always_inline__, __nodebug__, __target__("mmx")))
end_define

begin_comment
comment|/// \brief Clears the MMX state by setting the state of the x87 stack registers
end_comment

begin_comment
comment|///    to empty.
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
comment|/// This intrinsic corresponds to the<c> EMMS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_empty
parameter_list|(
name|void
parameter_list|)
block|{
name|__builtin_ia32_emms
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 64-bit integer vector, setting the lower 32 bits to the
end_comment

begin_comment
comment|///    value of the 32-bit integer parameter and setting the upper 32 bits to 0.
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
comment|/// This intrinsic corresponds to the<c> VMOVD / MOVD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __i
end_comment

begin_comment
comment|///    A 32-bit integer value.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector. The lower 32 bits contain the value of the
end_comment

begin_comment
comment|///    parameter. The upper 32 bits are set to 0.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsi32_si64
parameter_list|(
name|int
name|__i
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_vec_init_v2si
argument_list|(
name|__i
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Returns the lower 32 bits of a 64-bit integer vector as a 32-bit
end_comment

begin_comment
comment|///    signed integer.
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
comment|/// This intrinsic corresponds to the<c> VMOVD / MOVD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m
end_comment

begin_comment
comment|///    A 64-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 32-bit signed integer value containing the lower 32 bits of the
end_comment

begin_comment
comment|///    parameter.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsi64_si32
parameter_list|(
name|__m64
name|__m
parameter_list|)
block|{
return|return
name|__builtin_ia32_vec_ext_v2si
argument_list|(
operator|(
name|__v2si
operator|)
name|__m
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Casts a 64-bit signed integer value into a 64-bit integer vector.
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
comment|/// This intrinsic corresponds to the<c> VMOVQ / MOVD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __i
end_comment

begin_comment
comment|///    A 64-bit signed integer.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the same bitwise pattern as the
end_comment

begin_comment
comment|///    parameter.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsi64_m64
parameter_list|(
name|long
name|long
name|__i
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__i
return|;
block|}
end_function

begin_comment
comment|/// \brief Casts a 64-bit integer vector into a 64-bit signed integer value.
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
comment|/// This intrinsic corresponds to the<c> VMOVQ / MOVD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m
end_comment

begin_comment
comment|///    A 64-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 64-bit signed integer containing the same bitwise pattern as the
end_comment

begin_comment
comment|///    parameter.
end_comment

begin_function
specifier|static
name|__inline__
name|long
name|long
name|__DEFAULT_FN_ATTRS
name|_mm_cvtm64_si64
parameter_list|(
name|__m64
name|__m
parameter_list|)
block|{
return|return
operator|(
name|long
name|long
operator|)
name|__m
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts 16-bit signed integers from both 64-bit integer vector
end_comment

begin_comment
comment|///    parameters of [4 x i16] into 8-bit signed integer values, and constructs
end_comment

begin_comment
comment|///    a 64-bit integer vector of [8 x i8] as the result. Positive values
end_comment

begin_comment
comment|///    greater than 0x7F are saturated to 0x7F. Negative values less than 0x80
end_comment

begin_comment
comment|///    are saturated to 0x80.
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
comment|/// This intrinsic corresponds to the<c> PACKSSWB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16]. Each 16-bit element is treated as a
end_comment

begin_comment
comment|///    16-bit signed integer and is converted to an 8-bit signed integer with
end_comment

begin_comment
comment|///    saturation. Positive values greater than 0x7F are saturated to 0x7F.
end_comment

begin_comment
comment|///    Negative values less than 0x80 are saturated to 0x80. The converted
end_comment

begin_comment
comment|///    [4 x i8] values are written to the lower 32 bits of the result.
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16]. Each 16-bit element is treated as a
end_comment

begin_comment
comment|///    16-bit signed integer and is converted to an 8-bit signed integer with
end_comment

begin_comment
comment|///    saturation. Positive values greater than 0x7F are saturated to 0x7F.
end_comment

begin_comment
comment|///    Negative values less than 0x80 are saturated to 0x80. The converted
end_comment

begin_comment
comment|///    [4 x i8] values are written to the upper 32 bits of the result.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [8 x i8] containing the converted
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_packs_pi16
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_packsswb
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m1
argument_list|,
operator|(
name|__v4hi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts 32-bit signed integers from both 64-bit integer vector
end_comment

begin_comment
comment|///    parameters of [2 x i32] into 16-bit signed integer values, and constructs
end_comment

begin_comment
comment|///    a 64-bit integer vector of [4 x i16] as the result. Positive values
end_comment

begin_comment
comment|///    greater than 0x7FFF are saturated to 0x7FFF. Negative values less than
end_comment

begin_comment
comment|///    0x8000 are saturated to 0x8000.
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
comment|/// This intrinsic corresponds to the<c> PACKSSDW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [2 x i32]. Each 32-bit element is treated as a
end_comment

begin_comment
comment|///    32-bit signed integer and is converted to a 16-bit signed integer with
end_comment

begin_comment
comment|///    saturation. Positive values greater than 0x7FFF are saturated to 0x7FFF.
end_comment

begin_comment
comment|///    Negative values less than 0x8000 are saturated to 0x8000. The converted
end_comment

begin_comment
comment|///    [2 x i16] values are written to the lower 32 bits of the result.
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [2 x i32]. Each 32-bit element is treated as a
end_comment

begin_comment
comment|///    32-bit signed integer and is converted to a 16-bit signed integer with
end_comment

begin_comment
comment|///    saturation. Positive values greater than 0x7FFF are saturated to 0x7FFF.
end_comment

begin_comment
comment|///    Negative values less than 0x8000 are saturated to 0x8000. The converted
end_comment

begin_comment
comment|///    [2 x i16] values are written to the upper 32 bits of the result.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [4 x i16] containing the converted
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_packs_pi32
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_packssdw
argument_list|(
operator|(
name|__v2si
operator|)
name|__m1
argument_list|,
operator|(
name|__v2si
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts 16-bit signed integers from both 64-bit integer vector
end_comment

begin_comment
comment|///    parameters of [4 x i16] into 8-bit unsigned integer values, and
end_comment

begin_comment
comment|///    constructs a 64-bit integer vector of [8 x i8] as the result. Values
end_comment

begin_comment
comment|///    greater than 0xFF are saturated to 0xFF. Values less than 0 are saturated
end_comment

begin_comment
comment|///    to 0.
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
comment|/// This intrinsic corresponds to the<c> PACKUSWB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16]. Each 16-bit element is treated as a
end_comment

begin_comment
comment|///    16-bit signed integer and is converted to an 8-bit unsigned integer with
end_comment

begin_comment
comment|///    saturation. Values greater than 0xFF are saturated to 0xFF. Values less
end_comment

begin_comment
comment|///    than 0 are saturated to 0. The converted [4 x i8] values are written to
end_comment

begin_comment
comment|///    the lower 32 bits of the result.
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16]. Each 16-bit element is treated as a
end_comment

begin_comment
comment|///    16-bit signed integer and is converted to an 8-bit unsigned integer with
end_comment

begin_comment
comment|///    saturation. Values greater than 0xFF are saturated to 0xFF. Values less
end_comment

begin_comment
comment|///    than 0 are saturated to 0. The converted [4 x i8] values are written to
end_comment

begin_comment
comment|///    the upper 32 bits of the result.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [8 x i8] containing the converted
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_packs_pu16
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_packuswb
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m1
argument_list|,
operator|(
name|__v4hi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Unpacks the upper 32 bits from two 64-bit integer vectors of [8 x i8]
end_comment

begin_comment
comment|///    and interleaves them into a 64-bit integer vector of [8 x i8].
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
comment|/// This intrinsic corresponds to the<c> PUNPCKHBW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [8 x i8]. \n
end_comment

begin_comment
comment|///    Bits [39:32] are written to bits [7:0] of the result. \n
end_comment

begin_comment
comment|///    Bits [47:40] are written to bits [23:16] of the result. \n
end_comment

begin_comment
comment|///    Bits [55:48] are written to bits [39:32] of the result. \n
end_comment

begin_comment
comment|///    Bits [63:56] are written to bits [55:48] of the result.
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [8 x i8].
end_comment

begin_comment
comment|///    Bits [39:32] are written to bits [15:8] of the result. \n
end_comment

begin_comment
comment|///    Bits [47:40] are written to bits [31:24] of the result. \n
end_comment

begin_comment
comment|///    Bits [55:48] are written to bits [47:40] of the result. \n
end_comment

begin_comment
comment|///    Bits [63:56] are written to bits [63:56] of the result.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [8 x i8] containing the interleaved
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_unpackhi_pi8
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_punpckhbw
argument_list|(
operator|(
name|__v8qi
operator|)
name|__m1
argument_list|,
operator|(
name|__v8qi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Unpacks the upper 32 bits from two 64-bit integer vectors of
end_comment

begin_comment
comment|///    [4 x i16] and interleaves them into a 64-bit integer vector of [4 x i16].
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
comment|/// This intrinsic corresponds to the<c> PUNPCKHWD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|///    Bits [47:32] are written to bits [15:0] of the result. \n
end_comment

begin_comment
comment|///    Bits [63:48] are written to bits [47:32] of the result.
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|///    Bits [47:32] are written to bits [31:16] of the result. \n
end_comment

begin_comment
comment|///    Bits [63:48] are written to bits [63:48] of the result.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [4 x i16] containing the interleaved
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_unpackhi_pi16
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_punpckhwd
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m1
argument_list|,
operator|(
name|__v4hi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Unpacks the upper 32 bits from two 64-bit integer vectors of
end_comment

begin_comment
comment|///    [2 x i32] and interleaves them into a 64-bit integer vector of [2 x i32].
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
comment|/// This intrinsic corresponds to the<c> PUNPCKHDQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [2 x i32]. The upper 32 bits are written to
end_comment

begin_comment
comment|///    the lower 32 bits of the result.
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [2 x i32]. The upper 32 bits are written to
end_comment

begin_comment
comment|///    the upper 32 bits of the result.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [2 x i32] containing the interleaved
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_unpackhi_pi32
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_punpckhdq
argument_list|(
operator|(
name|__v2si
operator|)
name|__m1
argument_list|,
operator|(
name|__v2si
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Unpacks the lower 32 bits from two 64-bit integer vectors of [8 x i8]
end_comment

begin_comment
comment|///    and interleaves them into a 64-bit integer vector of [8 x i8].
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
comment|/// This intrinsic corresponds to the<c> PUNPCKLBW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [8 x i8].
end_comment

begin_comment
comment|///    Bits [7:0] are written to bits [7:0] of the result. \n
end_comment

begin_comment
comment|///    Bits [15:8] are written to bits [23:16] of the result. \n
end_comment

begin_comment
comment|///    Bits [23:16] are written to bits [39:32] of the result. \n
end_comment

begin_comment
comment|///    Bits [31:24] are written to bits [55:48] of the result.
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [8 x i8].
end_comment

begin_comment
comment|///    Bits [7:0] are written to bits [15:8] of the result. \n
end_comment

begin_comment
comment|///    Bits [15:8] are written to bits [31:24] of the result. \n
end_comment

begin_comment
comment|///    Bits [23:16] are written to bits [47:40] of the result. \n
end_comment

begin_comment
comment|///    Bits [31:24] are written to bits [63:56] of the result.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [8 x i8] containing the interleaved
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_unpacklo_pi8
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_punpcklbw
argument_list|(
operator|(
name|__v8qi
operator|)
name|__m1
argument_list|,
operator|(
name|__v8qi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Unpacks the lower 32 bits from two 64-bit integer vectors of
end_comment

begin_comment
comment|///    [4 x i16] and interleaves them into a 64-bit integer vector of [4 x i16].
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
comment|/// This intrinsic corresponds to the<c> PUNPCKLWD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|///    Bits [15:0] are written to bits [15:0] of the result. \n
end_comment

begin_comment
comment|///    Bits [31:16] are written to bits [47:32] of the result.
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|///    Bits [15:0] are written to bits [31:16] of the result. \n
end_comment

begin_comment
comment|///    Bits [31:16] are written to bits [63:48] of the result.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [4 x i16] containing the interleaved
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_unpacklo_pi16
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_punpcklwd
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m1
argument_list|,
operator|(
name|__v4hi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Unpacks the lower 32 bits from two 64-bit integer vectors of
end_comment

begin_comment
comment|///    [2 x i32] and interleaves them into a 64-bit integer vector of [2 x i32].
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
comment|/// This intrinsic corresponds to the<c> PUNPCKLDQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [2 x i32]. The lower 32 bits are written to
end_comment

begin_comment
comment|///    the lower 32 bits of the result.
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [2 x i32]. The lower 32 bits are written to
end_comment

begin_comment
comment|///    the upper 32 bits of the result.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [2 x i32] containing the interleaved
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_unpacklo_pi32
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_punpckldq
argument_list|(
operator|(
name|__v2si
operator|)
name|__m1
argument_list|,
operator|(
name|__v2si
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds each 8-bit integer element of the first 64-bit integer vector
end_comment

begin_comment
comment|///    of [8 x i8] to the corresponding 8-bit integer element of the second
end_comment

begin_comment
comment|///    64-bit integer vector of [8 x i8]. The lower 8 bits of the results are
end_comment

begin_comment
comment|///    packed into a 64-bit integer vector of [8 x i8].
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
comment|/// This intrinsic corresponds to the<c> PADDB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [8 x i8].
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [8 x i8].
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [8 x i8] containing the sums of both
end_comment

begin_comment
comment|///    parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_add_pi8
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_paddb
argument_list|(
operator|(
name|__v8qi
operator|)
name|__m1
argument_list|,
operator|(
name|__v8qi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds each 16-bit integer element of the first 64-bit integer vector
end_comment

begin_comment
comment|///    of [4 x i16] to the corresponding 16-bit integer element of the second
end_comment

begin_comment
comment|///    64-bit integer vector of [4 x i16]. The lower 16 bits of the results are
end_comment

begin_comment
comment|///    packed into a 64-bit integer vector of [4 x i16].
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
comment|/// This intrinsic corresponds to the<c> PADDW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [4 x i16] containing the sums of both
end_comment

begin_comment
comment|///    parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_add_pi16
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_paddw
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m1
argument_list|,
operator|(
name|__v4hi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds each 32-bit integer element of the first 64-bit integer vector
end_comment

begin_comment
comment|///    of [2 x i32] to the corresponding 32-bit integer element of the second
end_comment

begin_comment
comment|///    64-bit integer vector of [2 x i32]. The lower 32 bits of the results are
end_comment

begin_comment
comment|///    packed into a 64-bit integer vector of [2 x i32].
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
comment|/// This intrinsic corresponds to the<c> PADDD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [2 x i32].
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [2 x i32].
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [2 x i32] containing the sums of both
end_comment

begin_comment
comment|///    parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_add_pi32
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_paddd
argument_list|(
operator|(
name|__v2si
operator|)
name|__m1
argument_list|,
operator|(
name|__v2si
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds each 8-bit signed integer element of the first 64-bit integer
end_comment

begin_comment
comment|///    vector of [8 x i8] to the corresponding 8-bit signed integer element of
end_comment

begin_comment
comment|///    the second 64-bit integer vector of [8 x i8]. Positive sums greater than
end_comment

begin_comment
comment|///    0x7F are saturated to 0x7F. Negative sums less than 0x80 are saturated to
end_comment

begin_comment
comment|///    0x80. The results are packed into a 64-bit integer vector of [8 x i8].
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
comment|/// This intrinsic corresponds to the<c> PADDSB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [8 x i8].
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [8 x i8].
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [8 x i8] containing the saturated sums
end_comment

begin_comment
comment|///    of both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_adds_pi8
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_paddsb
argument_list|(
operator|(
name|__v8qi
operator|)
name|__m1
argument_list|,
operator|(
name|__v8qi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds each 16-bit signed integer element of the first 64-bit integer
end_comment

begin_comment
comment|///    vector of [4 x i16] to the corresponding 16-bit signed integer element of
end_comment

begin_comment
comment|///    the second 64-bit integer vector of [4 x i16]. Positive sums greater than
end_comment

begin_comment
comment|///    0x7FFF are saturated to 0x7FFF. Negative sums less than 0x8000 are
end_comment

begin_comment
comment|///    saturated to 0x8000. The results are packed into a 64-bit integer vector
end_comment

begin_comment
comment|///    of [4 x i16].
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
comment|/// This intrinsic corresponds to the<c> PADDSW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [4 x i16] containing the saturated sums
end_comment

begin_comment
comment|///    of both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_adds_pi16
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_paddsw
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m1
argument_list|,
operator|(
name|__v4hi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds each 8-bit unsigned integer element of the first 64-bit integer
end_comment

begin_comment
comment|///    vector of [8 x i8] to the corresponding 8-bit unsigned integer element of
end_comment

begin_comment
comment|///    the second 64-bit integer vector of [8 x i8]. Sums greater than 0xFF are
end_comment

begin_comment
comment|///    saturated to 0xFF. The results are packed into a 64-bit integer vector of
end_comment

begin_comment
comment|///    [8 x i8].
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
comment|/// This intrinsic corresponds to the<c> PADDUSB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [8 x i8].
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [8 x i8].
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [8 x i8] containing the saturated
end_comment

begin_comment
comment|///    unsigned sums of both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_adds_pu8
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_paddusb
argument_list|(
operator|(
name|__v8qi
operator|)
name|__m1
argument_list|,
operator|(
name|__v8qi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds each 16-bit unsigned integer element of the first 64-bit integer
end_comment

begin_comment
comment|///    vector of [4 x i16] to the corresponding 16-bit unsigned integer element
end_comment

begin_comment
comment|///    of the second 64-bit integer vector of [4 x i16]. Sums greater than
end_comment

begin_comment
comment|///    0xFFFF are saturated to 0xFFFF. The results are packed into a 64-bit
end_comment

begin_comment
comment|///    integer vector of [4 x i16].
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
comment|/// This intrinsic corresponds to the<c> PADDUSW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [4 x i16] containing the saturated
end_comment

begin_comment
comment|///    unsigned sums of both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_adds_pu16
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_paddusw
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m1
argument_list|,
operator|(
name|__v4hi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts each 8-bit integer element of the second 64-bit integer
end_comment

begin_comment
comment|///    vector of [8 x i8] from the corresponding 8-bit integer element of the
end_comment

begin_comment
comment|///    first 64-bit integer vector of [8 x i8]. The lower 8 bits of the results
end_comment

begin_comment
comment|///    are packed into a 64-bit integer vector of [8 x i8].
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
comment|/// This intrinsic corresponds to the<c> PSUBB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [8 x i8] containing the minuends.
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [8 x i8] containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [8 x i8] containing the differences of
end_comment

begin_comment
comment|///    both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_sub_pi8
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psubb
argument_list|(
operator|(
name|__v8qi
operator|)
name|__m1
argument_list|,
operator|(
name|__v8qi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts each 16-bit integer element of the second 64-bit integer
end_comment

begin_comment
comment|///    vector of [4 x i16] from the corresponding 16-bit integer element of the
end_comment

begin_comment
comment|///    first 64-bit integer vector of [4 x i16]. The lower 16 bits of the
end_comment

begin_comment
comment|///    results are packed into a 64-bit integer vector of [4 x i16].
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
comment|/// This intrinsic corresponds to the<c> PSUBW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16] containing the minuends.
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16] containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [4 x i16] containing the differences of
end_comment

begin_comment
comment|///    both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_sub_pi16
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psubw
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m1
argument_list|,
operator|(
name|__v4hi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts each 32-bit integer element of the second 64-bit integer
end_comment

begin_comment
comment|///    vector of [2 x i32] from the corresponding 32-bit integer element of the
end_comment

begin_comment
comment|///    first 64-bit integer vector of [2 x i32]. The lower 32 bits of the
end_comment

begin_comment
comment|///    results are packed into a 64-bit integer vector of [2 x i32].
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
comment|/// This intrinsic corresponds to the<c> PSUBD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [2 x i32] containing the minuends.
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [2 x i32] containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [2 x i32] containing the differences of
end_comment

begin_comment
comment|///    both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_sub_pi32
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psubd
argument_list|(
operator|(
name|__v2si
operator|)
name|__m1
argument_list|,
operator|(
name|__v2si
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts each 8-bit signed integer element of the second 64-bit
end_comment

begin_comment
comment|///    integer vector of [8 x i8] from the corresponding 8-bit signed integer
end_comment

begin_comment
comment|///    element of the first 64-bit integer vector of [8 x i8]. Positive results
end_comment

begin_comment
comment|///    greater than 0x7F are saturated to 0x7F. Negative results less than 0x80
end_comment

begin_comment
comment|///    are saturated to 0x80. The results are packed into a 64-bit integer
end_comment

begin_comment
comment|///    vector of [8 x i8].
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
comment|/// This intrinsic corresponds to the<c> PSUBSB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [8 x i8] containing the minuends.
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [8 x i8] containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [8 x i8] containing the saturated
end_comment

begin_comment
comment|///    differences of both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_subs_pi8
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psubsb
argument_list|(
operator|(
name|__v8qi
operator|)
name|__m1
argument_list|,
operator|(
name|__v8qi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts each 16-bit signed integer element of the second 64-bit
end_comment

begin_comment
comment|///    integer vector of [4 x i16] from the corresponding 16-bit signed integer
end_comment

begin_comment
comment|///    element of the first 64-bit integer vector of [4 x i16]. Positive results
end_comment

begin_comment
comment|///    greater than 0x7FFF are saturated to 0x7FFF. Negative results less than
end_comment

begin_comment
comment|///    0x8000 are saturated to 0x8000. The results are packed into a 64-bit
end_comment

begin_comment
comment|///    integer vector of [4 x i16].
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
comment|/// This intrinsic corresponds to the<c> PSUBSW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16] containing the minuends.
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16] containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [4 x i16] containing the saturated
end_comment

begin_comment
comment|///    differences of both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_subs_pi16
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psubsw
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m1
argument_list|,
operator|(
name|__v4hi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts each 8-bit unsigned integer element of the second 64-bit
end_comment

begin_comment
comment|///    integer vector of [8 x i8] from the corresponding 8-bit unsigned integer
end_comment

begin_comment
comment|///    element of the first 64-bit integer vector of [8 x i8].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    If an element of the first vector is less than the corresponding element
end_comment

begin_comment
comment|///    of the second vector, the result is saturated to 0. The results are
end_comment

begin_comment
comment|///    packed into a 64-bit integer vector of [8 x i8].
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
comment|/// This intrinsic corresponds to the<c> PSUBUSB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [8 x i8] containing the minuends.
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [8 x i8] containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [8 x i8] containing the saturated
end_comment

begin_comment
comment|///    differences of both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_subs_pu8
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psubusb
argument_list|(
operator|(
name|__v8qi
operator|)
name|__m1
argument_list|,
operator|(
name|__v8qi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts each 16-bit unsigned integer element of the second 64-bit
end_comment

begin_comment
comment|///    integer vector of [4 x i16] from the corresponding 16-bit unsigned
end_comment

begin_comment
comment|///    integer element of the first 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    If an element of the first vector is less than the corresponding element
end_comment

begin_comment
comment|///    of the second vector, the result is saturated to 0. The results are
end_comment

begin_comment
comment|///    packed into a 64-bit integer vector of [4 x i16].
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
comment|/// This intrinsic corresponds to the<c> PSUBUSW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16] containing the minuends.
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16] containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [4 x i16] containing the saturated
end_comment

begin_comment
comment|///    differences of both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_subs_pu16
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psubusw
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m1
argument_list|,
operator|(
name|__v4hi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Multiplies each 16-bit signed integer element of the first 64-bit
end_comment

begin_comment
comment|///    integer vector of [4 x i16] by the corresponding 16-bit signed integer
end_comment

begin_comment
comment|///    element of the second 64-bit integer vector of [4 x i16] and get four
end_comment

begin_comment
comment|///    32-bit products. Adds adjacent pairs of products to get two 32-bit sums.
end_comment

begin_comment
comment|///    The lower 32 bits of these two sums are packed into a 64-bit integer
end_comment

begin_comment
comment|///    vector of [2 x i32].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    For example, bits [15:0] of both parameters are multiplied, bits [31:16]
end_comment

begin_comment
comment|///    of both parameters are multiplied, and the sum of both results is written
end_comment

begin_comment
comment|///    to bits [31:0] of the result.
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
comment|/// This intrinsic corresponds to the<c> PMADDWD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [2 x i32] containing the sums of
end_comment

begin_comment
comment|///    products of both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_madd_pi16
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_pmaddwd
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m1
argument_list|,
operator|(
name|__v4hi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Multiplies each 16-bit signed integer element of the first 64-bit
end_comment

begin_comment
comment|///    integer vector of [4 x i16] by the corresponding 16-bit signed integer
end_comment

begin_comment
comment|///    element of the second 64-bit integer vector of [4 x i16]. Packs the upper
end_comment

begin_comment
comment|///    16 bits of the 32-bit products into a 64-bit integer vector of [4 x i16].
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
comment|/// This intrinsic corresponds to the<c> PMULHW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [4 x i16] containing the upper 16 bits
end_comment

begin_comment
comment|///    of the products of both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_mulhi_pi16
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_pmulhw
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m1
argument_list|,
operator|(
name|__v4hi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Multiplies each 16-bit signed integer element of the first 64-bit
end_comment

begin_comment
comment|///    integer vector of [4 x i16] by the corresponding 16-bit signed integer
end_comment

begin_comment
comment|///    element of the second 64-bit integer vector of [4 x i16]. Packs the lower
end_comment

begin_comment
comment|///    16 bits of the 32-bit products into a 64-bit integer vector of [4 x i16].
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
comment|/// This intrinsic corresponds to the<c> PMULLW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [4 x i16] containing the lower 16 bits
end_comment

begin_comment
comment|///    of the products of both parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_mullo_pi16
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_pmullw
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m1
argument_list|,
operator|(
name|__v4hi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Left-shifts each 16-bit signed integer element of the first
end_comment

begin_comment
comment|///    parameter, which is a 64-bit integer vector of [4 x i16], by the number
end_comment

begin_comment
comment|///    of bits specified by the second parameter, which is a 64-bit integer. The
end_comment

begin_comment
comment|///    lower 16 bits of the results are packed into a 64-bit integer vector of
end_comment

begin_comment
comment|///    [4 x i16].
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
comment|/// This intrinsic corresponds to the<c> PSLLW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 64-bit integer vector interpreted as a single 64-bit integer.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [4 x i16] containing the left-shifted
end_comment

begin_comment
comment|///    values. If \a __count is greater or equal to 16, the result is set to all
end_comment

begin_comment
comment|///    0.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_sll_pi16
parameter_list|(
name|__m64
name|__m
parameter_list|,
name|__m64
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psllw
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Left-shifts each 16-bit signed integer element of a 64-bit integer
end_comment

begin_comment
comment|///    vector of [4 x i16] by the number of bits specified by a 32-bit integer.
end_comment

begin_comment
comment|///    The lower 16 bits of the results are packed into a 64-bit integer vector
end_comment

begin_comment
comment|///    of [4 x i16].
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
comment|/// This intrinsic corresponds to the<c> PSLLW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 32-bit integer value.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [4 x i16] containing the left-shifted
end_comment

begin_comment
comment|///    values. If \a __count is greater or equal to 16, the result is set to all
end_comment

begin_comment
comment|///    0.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_slli_pi16
parameter_list|(
name|__m64
name|__m
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psllwi
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Left-shifts each 32-bit signed integer element of the first
end_comment

begin_comment
comment|///    parameter, which is a 64-bit integer vector of [2 x i32], by the number
end_comment

begin_comment
comment|///    of bits specified by the second parameter, which is a 64-bit integer. The
end_comment

begin_comment
comment|///    lower 32 bits of the results are packed into a 64-bit integer vector of
end_comment

begin_comment
comment|///    [2 x i32].
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
comment|/// This intrinsic corresponds to the<c> PSLLD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m
end_comment

begin_comment
comment|///    A 64-bit integer vector of [2 x i32].
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 64-bit integer vector interpreted as a single 64-bit integer.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [2 x i32] containing the left-shifted
end_comment

begin_comment
comment|///    values. If \a __count is greater or equal to 32, the result is set to all
end_comment

begin_comment
comment|///    0.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_sll_pi32
parameter_list|(
name|__m64
name|__m
parameter_list|,
name|__m64
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_pslld
argument_list|(
operator|(
name|__v2si
operator|)
name|__m
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Left-shifts each 32-bit signed integer element of a 64-bit integer
end_comment

begin_comment
comment|///    vector of [2 x i32] by the number of bits specified by a 32-bit integer.
end_comment

begin_comment
comment|///    The lower 32 bits of the results are packed into a 64-bit integer vector
end_comment

begin_comment
comment|///    of [2 x i32].
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
comment|/// This intrinsic corresponds to the<c> PSLLD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m
end_comment

begin_comment
comment|///    A 64-bit integer vector of [2 x i32].
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 32-bit integer value.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [2 x i32] containing the left-shifted
end_comment

begin_comment
comment|///    values. If \a __count is greater or equal to 32, the result is set to all
end_comment

begin_comment
comment|///    0.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_slli_pi32
parameter_list|(
name|__m64
name|__m
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_pslldi
argument_list|(
operator|(
name|__v2si
operator|)
name|__m
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Left-shifts the first 64-bit integer parameter by the number of bits
end_comment

begin_comment
comment|///    specified by the second 64-bit integer parameter. The lower 64 bits of
end_comment

begin_comment
comment|///    result are returned.
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
comment|/// This intrinsic corresponds to the<c> PSLLQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m
end_comment

begin_comment
comment|///    A 64-bit integer vector interpreted as a single 64-bit integer.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 64-bit integer vector interpreted as a single 64-bit integer.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the left-shifted value. If
end_comment

begin_comment
comment|///     \a __count is greater or equal to 64, the result is set to 0.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_sll_si64
parameter_list|(
name|__m64
name|__m
parameter_list|,
name|__m64
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psllq
argument_list|(
operator|(
name|__v1di
operator|)
name|__m
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Left-shifts the first parameter, which is a 64-bit integer, by the
end_comment

begin_comment
comment|///    number of bits specified by the second parameter, which is a 32-bit
end_comment

begin_comment
comment|///    integer. The lower 64 bits of result are returned.
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
comment|/// This intrinsic corresponds to the<c> PSLLQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m
end_comment

begin_comment
comment|///    A 64-bit integer vector interpreted as a single 64-bit integer.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 32-bit integer value.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the left-shifted value. If
end_comment

begin_comment
comment|///     \a __count is greater or equal to 64, the result is set to 0.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_slli_si64
parameter_list|(
name|__m64
name|__m
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psllqi
argument_list|(
operator|(
name|__v1di
operator|)
name|__m
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each 16-bit integer element of the first parameter,
end_comment

begin_comment
comment|///    which is a 64-bit integer vector of [4 x i16], by the number of bits
end_comment

begin_comment
comment|///    specified by the second parameter, which is a 64-bit integer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    High-order bits are filled with the sign bit of the initial value of each
end_comment

begin_comment
comment|///    16-bit element. The 16-bit results are packed into a 64-bit integer
end_comment

begin_comment
comment|///    vector of [4 x i16].
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
comment|/// This intrinsic corresponds to the<c> PSRAW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 64-bit integer vector interpreted as a single 64-bit integer.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [4 x i16] containing the right-shifted
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_sra_pi16
parameter_list|(
name|__m64
name|__m
parameter_list|,
name|__m64
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psraw
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each 16-bit integer element of a 64-bit integer vector
end_comment

begin_comment
comment|///    of [4 x i16] by the number of bits specified by a 32-bit integer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    High-order bits are filled with the sign bit of the initial value of each
end_comment

begin_comment
comment|///    16-bit element. The 16-bit results are packed into a 64-bit integer
end_comment

begin_comment
comment|///    vector of [4 x i16].
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
comment|/// This intrinsic corresponds to the<c> PSRAW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 32-bit integer value.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [4 x i16] containing the right-shifted
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_srai_pi16
parameter_list|(
name|__m64
name|__m
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psrawi
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each 32-bit integer element of the first parameter,
end_comment

begin_comment
comment|///    which is a 64-bit integer vector of [2 x i32], by the number of bits
end_comment

begin_comment
comment|///    specified by the second parameter, which is a 64-bit integer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    High-order bits are filled with the sign bit of the initial value of each
end_comment

begin_comment
comment|///    32-bit element. The 32-bit results are packed into a 64-bit integer
end_comment

begin_comment
comment|///    vector of [2 x i32].
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
comment|/// This intrinsic corresponds to the<c> PSRAD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m
end_comment

begin_comment
comment|///    A 64-bit integer vector of [2 x i32].
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 64-bit integer vector interpreted as a single 64-bit integer.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [2 x i32] containing the right-shifted
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_sra_pi32
parameter_list|(
name|__m64
name|__m
parameter_list|,
name|__m64
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psrad
argument_list|(
operator|(
name|__v2si
operator|)
name|__m
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each 32-bit integer element of a 64-bit integer vector
end_comment

begin_comment
comment|///    of [2 x i32] by the number of bits specified by a 32-bit integer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    High-order bits are filled with the sign bit of the initial value of each
end_comment

begin_comment
comment|///    32-bit element. The 32-bit results are packed into a 64-bit integer
end_comment

begin_comment
comment|///    vector of [2 x i32].
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
comment|/// This intrinsic corresponds to the<c> PSRAD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m
end_comment

begin_comment
comment|///    A 64-bit integer vector of [2 x i32].
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 32-bit integer value.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [2 x i32] containing the right-shifted
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_srai_pi32
parameter_list|(
name|__m64
name|__m
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psradi
argument_list|(
operator|(
name|__v2si
operator|)
name|__m
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each 16-bit integer element of the first parameter,
end_comment

begin_comment
comment|///    which is a 64-bit integer vector of [4 x i16], by the number of bits
end_comment

begin_comment
comment|///    specified by the second parameter, which is a 64-bit integer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    High-order bits are cleared. The 16-bit results are packed into a 64-bit
end_comment

begin_comment
comment|///    integer vector of [4 x i16].
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
comment|/// This intrinsic corresponds to the<c> PSRLW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 64-bit integer vector interpreted as a single 64-bit integer.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [4 x i16] containing the right-shifted
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_srl_pi16
parameter_list|(
name|__m64
name|__m
parameter_list|,
name|__m64
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psrlw
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each 16-bit integer element of a 64-bit integer vector
end_comment

begin_comment
comment|///    of [4 x i16] by the number of bits specified by a 32-bit integer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    High-order bits are cleared. The 16-bit results are packed into a 64-bit
end_comment

begin_comment
comment|///    integer vector of [4 x i16].
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
comment|/// This intrinsic corresponds to the<c> PSRLW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 32-bit integer value.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [4 x i16] containing the right-shifted
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_srli_pi16
parameter_list|(
name|__m64
name|__m
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psrlwi
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each 32-bit integer element of the first parameter,
end_comment

begin_comment
comment|///    which is a 64-bit integer vector of [2 x i32], by the number of bits
end_comment

begin_comment
comment|///    specified by the second parameter, which is a 64-bit integer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    High-order bits are cleared. The 32-bit results are packed into a 64-bit
end_comment

begin_comment
comment|///    integer vector of [2 x i32].
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
comment|/// This intrinsic corresponds to the<c> PSRLD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m
end_comment

begin_comment
comment|///    A 64-bit integer vector of [2 x i32].
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 64-bit integer vector interpreted as a single 64-bit integer.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [2 x i32] containing the right-shifted
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_srl_pi32
parameter_list|(
name|__m64
name|__m
parameter_list|,
name|__m64
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psrld
argument_list|(
operator|(
name|__v2si
operator|)
name|__m
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each 32-bit integer element of a 64-bit integer vector
end_comment

begin_comment
comment|///    of [2 x i32] by the number of bits specified by a 32-bit integer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    High-order bits are cleared. The 32-bit results are packed into a 64-bit
end_comment

begin_comment
comment|///    integer vector of [2 x i32].
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
comment|/// This intrinsic corresponds to the<c> PSRLD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m
end_comment

begin_comment
comment|///    A 64-bit integer vector of [2 x i32].
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 32-bit integer value.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [2 x i32] containing the right-shifted
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_srli_pi32
parameter_list|(
name|__m64
name|__m
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psrldi
argument_list|(
operator|(
name|__v2si
operator|)
name|__m
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts the first 64-bit integer parameter by the number of bits
end_comment

begin_comment
comment|///    specified by the second 64-bit integer parameter.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    High-order bits are cleared.
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
comment|/// This intrinsic corresponds to the<c> PSRLQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m
end_comment

begin_comment
comment|///    A 64-bit integer vector interpreted as a single 64-bit integer.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 64-bit integer vector interpreted as a single 64-bit integer.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the right-shifted value.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_srl_si64
parameter_list|(
name|__m64
name|__m
parameter_list|,
name|__m64
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psrlq
argument_list|(
operator|(
name|__v1di
operator|)
name|__m
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts the first parameter, which is a 64-bit integer, by the
end_comment

begin_comment
comment|///    number of bits specified by the second parameter, which is a 32-bit
end_comment

begin_comment
comment|///    integer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    High-order bits are cleared.
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
comment|/// This intrinsic corresponds to the<c> PSRLQ</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m
end_comment

begin_comment
comment|///    A 64-bit integer vector interpreted as a single 64-bit integer.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 32-bit integer value.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the right-shifted value.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_srli_si64
parameter_list|(
name|__m64
name|__m
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psrlqi
argument_list|(
operator|(
name|__v1di
operator|)
name|__m
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise AND of two 64-bit integer vectors.
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
comment|/// This intrinsic corresponds to the<c> PAND</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector.
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the bitwise AND of both
end_comment

begin_comment
comment|///    parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_and_si64
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
name|__builtin_ia32_pand
argument_list|(
operator|(
name|__v1di
operator|)
name|__m1
argument_list|,
operator|(
name|__v1di
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise NOT of the first 64-bit integer vector, and then
end_comment

begin_comment
comment|///    performs a bitwise AND of the intermediate result and the second 64-bit
end_comment

begin_comment
comment|///    integer vector.
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
comment|/// This intrinsic corresponds to the<c> PANDN</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector. The one's complement of this parameter is used
end_comment

begin_comment
comment|///    in the bitwise AND.
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the bitwise AND of the second
end_comment

begin_comment
comment|///    parameter and the one's complement of the first parameter.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_andnot_si64
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
name|__builtin_ia32_pandn
argument_list|(
operator|(
name|__v1di
operator|)
name|__m1
argument_list|,
operator|(
name|__v1di
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise OR of two 64-bit integer vectors.
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
comment|/// This intrinsic corresponds to the<c> POR</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector.
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the bitwise OR of both
end_comment

begin_comment
comment|///    parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_or_si64
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
name|__builtin_ia32_por
argument_list|(
operator|(
name|__v1di
operator|)
name|__m1
argument_list|,
operator|(
name|__v1di
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise exclusive OR of two 64-bit integer vectors.
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
comment|/// This intrinsic corresponds to the<c> PXOR</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector.
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the bitwise exclusive OR of both
end_comment

begin_comment
comment|///    parameters.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_xor_si64
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
name|__builtin_ia32_pxor
argument_list|(
operator|(
name|__v1di
operator|)
name|__m1
argument_list|,
operator|(
name|__v1di
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the 8-bit integer elements of two 64-bit integer vectors of
end_comment

begin_comment
comment|///    [8 x i8] to determine if the element of the first vector is equal to the
end_comment

begin_comment
comment|///    corresponding element of the second vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    The comparison yields 0 for false, 0xFF for true.
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
comment|/// This intrinsic corresponds to the<c> PCMPEQB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [8 x i8].
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [8 x i8].
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [8 x i8] containing the comparison
end_comment

begin_comment
comment|///    results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_cmpeq_pi8
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_pcmpeqb
argument_list|(
operator|(
name|__v8qi
operator|)
name|__m1
argument_list|,
operator|(
name|__v8qi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the 16-bit integer elements of two 64-bit integer vectors of
end_comment

begin_comment
comment|///    [4 x i16] to determine if the element of the first vector is equal to the
end_comment

begin_comment
comment|///    corresponding element of the second vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    The comparison yields 0 for false, 0xFFFF for true.
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
comment|/// This intrinsic corresponds to the<c> PCMPEQW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [4 x i16] containing the comparison
end_comment

begin_comment
comment|///    results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_cmpeq_pi16
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_pcmpeqw
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m1
argument_list|,
operator|(
name|__v4hi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the 32-bit integer elements of two 64-bit integer vectors of
end_comment

begin_comment
comment|///    [2 x i32] to determine if the element of the first vector is equal to the
end_comment

begin_comment
comment|///    corresponding element of the second vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    The comparison yields 0 for false, 0xFFFFFFFF for true.
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
comment|/// This intrinsic corresponds to the<c> PCMPEQD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [2 x i32].
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [2 x i32].
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [2 x i32] containing the comparison
end_comment

begin_comment
comment|///    results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_cmpeq_pi32
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_pcmpeqd
argument_list|(
operator|(
name|__v2si
operator|)
name|__m1
argument_list|,
operator|(
name|__v2si
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the 8-bit integer elements of two 64-bit integer vectors of
end_comment

begin_comment
comment|///    [8 x i8] to determine if the element of the first vector is greater than
end_comment

begin_comment
comment|///    the corresponding element of the second vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    The comparison yields 0 for false, 0xFF for true.
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
comment|/// This intrinsic corresponds to the<c> PCMPGTB</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [8 x i8].
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [8 x i8].
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [8 x i8] containing the comparison
end_comment

begin_comment
comment|///    results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_cmpgt_pi8
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_pcmpgtb
argument_list|(
operator|(
name|__v8qi
operator|)
name|__m1
argument_list|,
operator|(
name|__v8qi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the 16-bit integer elements of two 64-bit integer vectors of
end_comment

begin_comment
comment|///    [4 x i16] to determine if the element of the first vector is greater than
end_comment

begin_comment
comment|///    the corresponding element of the second vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    The comparison yields 0 for false, 0xFFFF for true.
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
comment|/// This intrinsic corresponds to the<c> PCMPGTW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [4 x i16].
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [4 x i16] containing the comparison
end_comment

begin_comment
comment|///    results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_cmpgt_pi16
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_pcmpgtw
argument_list|(
operator|(
name|__v4hi
operator|)
name|__m1
argument_list|,
operator|(
name|__v4hi
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares the 32-bit integer elements of two 64-bit integer vectors of
end_comment

begin_comment
comment|///    [2 x i32] to determine if the element of the first vector is greater than
end_comment

begin_comment
comment|///    the corresponding element of the second vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    The comparison yields 0 for false, 0xFFFFFFFF for true.
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
comment|/// This intrinsic corresponds to the<c> PCMPGTD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __m1
end_comment

begin_comment
comment|///    A 64-bit integer vector of [2 x i32].
end_comment

begin_comment
comment|/// \param __m2
end_comment

begin_comment
comment|///    A 64-bit integer vector of [2 x i32].
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector of [2 x i32] containing the comparison
end_comment

begin_comment
comment|///    results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_cmpgt_pi32
parameter_list|(
name|__m64
name|__m1
parameter_list|,
name|__m64
name|__m2
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_pcmpgtd
argument_list|(
operator|(
name|__v2si
operator|)
name|__m1
argument_list|,
operator|(
name|__v2si
operator|)
name|__m2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 64-bit integer vector initialized to zero.
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
comment|/// This intrinsic corresponds to the<c> VXORPS / XORPS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns An initialized 64-bit integer vector with all elements set to zero.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_setzero_si64
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
block|{
literal|0LL
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 64-bit integer vector initialized with the specified
end_comment

begin_comment
comment|///    32-bit integer values.
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
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __i1
end_comment

begin_comment
comment|///    A 32-bit integer value used to initialize the upper 32 bits of the
end_comment

begin_comment
comment|///    result.
end_comment

begin_comment
comment|/// \param __i0
end_comment

begin_comment
comment|///    A 32-bit integer value used to initialize the lower 32 bits of the
end_comment

begin_comment
comment|///    result.
end_comment

begin_comment
comment|/// \returns An initialized 64-bit integer vector.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_set_pi32
parameter_list|(
name|int
name|__i1
parameter_list|,
name|int
name|__i0
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_vec_init_v2si
argument_list|(
name|__i0
argument_list|,
name|__i1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 64-bit integer vector initialized with the specified
end_comment

begin_comment
comment|///    16-bit integer values.
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
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __s3
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [63:48] of the result.
end_comment

begin_comment
comment|/// \param __s2
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [47:32] of the result.
end_comment

begin_comment
comment|/// \param __s1
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [31:16] of the result.
end_comment

begin_comment
comment|/// \param __s0
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [15:0] of the result.
end_comment

begin_comment
comment|/// \returns An initialized 64-bit integer vector.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_set_pi16
parameter_list|(
name|short
name|__s3
parameter_list|,
name|short
name|__s2
parameter_list|,
name|short
name|__s1
parameter_list|,
name|short
name|__s0
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_vec_init_v4hi
argument_list|(
name|__s0
argument_list|,
name|__s1
argument_list|,
name|__s2
argument_list|,
name|__s3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 64-bit integer vector initialized with the specified
end_comment

begin_comment
comment|///    8-bit integer values.
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
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __b7
end_comment

begin_comment
comment|///    An 8-bit integer value used to initialize bits [63:56] of the result.
end_comment

begin_comment
comment|/// \param __b6
end_comment

begin_comment
comment|///    An 8-bit integer value used to initialize bits [55:48] of the result.
end_comment

begin_comment
comment|/// \param __b5
end_comment

begin_comment
comment|///    An 8-bit integer value used to initialize bits [47:40] of the result.
end_comment

begin_comment
comment|/// \param __b4
end_comment

begin_comment
comment|///    An 8-bit integer value used to initialize bits [39:32] of the result.
end_comment

begin_comment
comment|/// \param __b3
end_comment

begin_comment
comment|///    An 8-bit integer value used to initialize bits [31:24] of the result.
end_comment

begin_comment
comment|/// \param __b2
end_comment

begin_comment
comment|///    An 8-bit integer value used to initialize bits [23:16] of the result.
end_comment

begin_comment
comment|/// \param __b1
end_comment

begin_comment
comment|///    An 8-bit integer value used to initialize bits [15:8] of the result.
end_comment

begin_comment
comment|/// \param __b0
end_comment

begin_comment
comment|///    An 8-bit integer value used to initialize bits [7:0] of the result.
end_comment

begin_comment
comment|/// \returns An initialized 64-bit integer vector.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_set_pi8
parameter_list|(
name|char
name|__b7
parameter_list|,
name|char
name|__b6
parameter_list|,
name|char
name|__b5
parameter_list|,
name|char
name|__b4
parameter_list|,
name|char
name|__b3
parameter_list|,
name|char
name|__b2
parameter_list|,
name|char
name|__b1
parameter_list|,
name|char
name|__b0
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_vec_init_v8qi
argument_list|(
name|__b0
argument_list|,
name|__b1
argument_list|,
name|__b2
argument_list|,
name|__b3
argument_list|,
name|__b4
argument_list|,
name|__b5
argument_list|,
name|__b6
argument_list|,
name|__b7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 64-bit integer vector of [2 x i32], with each of the
end_comment

begin_comment
comment|///    32-bit integer vector elements set to the specified 32-bit integer
end_comment

begin_comment
comment|///    value.
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
comment|/// This intrinsic corresponds to the<c> VPSHUFD / PSHUFD</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __i
end_comment

begin_comment
comment|///    A 32-bit integer value used to initialize each vector element of the
end_comment

begin_comment
comment|///    result.
end_comment

begin_comment
comment|/// \returns An initialized 64-bit integer vector of [2 x i32].
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_set1_pi32
parameter_list|(
name|int
name|__i
parameter_list|)
block|{
return|return
name|_mm_set_pi32
argument_list|(
name|__i
argument_list|,
name|__i
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 64-bit integer vector of [4 x i16], with each of the
end_comment

begin_comment
comment|///    16-bit integer vector elements set to the specified 16-bit integer
end_comment

begin_comment
comment|///    value.
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
comment|/// This intrinsic corresponds to the<c> VPSHUFLW / PSHUFLW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __w
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize each vector element of the
end_comment

begin_comment
comment|///    result.
end_comment

begin_comment
comment|/// \returns An initialized 64-bit integer vector of [4 x i16].
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_set1_pi16
parameter_list|(
name|short
name|__w
parameter_list|)
block|{
return|return
name|_mm_set_pi16
argument_list|(
name|__w
argument_list|,
name|__w
argument_list|,
name|__w
argument_list|,
name|__w
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 64-bit integer vector of [8 x i8], with each of the
end_comment

begin_comment
comment|///    8-bit integer vector elements set to the specified 8-bit integer value.
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
comment|/// This intrinsic corresponds to the<c> VPUNPCKLBW + VPSHUFLW / PUNPCKLBW +
end_comment

begin_comment
comment|///    PSHUFLW</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    An 8-bit integer value used to initialize each vector element of the
end_comment

begin_comment
comment|///    result.
end_comment

begin_comment
comment|/// \returns An initialized 64-bit integer vector of [8 x i8].
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_set1_pi8
parameter_list|(
name|char
name|__b
parameter_list|)
block|{
return|return
name|_mm_set_pi8
argument_list|(
name|__b
argument_list|,
name|__b
argument_list|,
name|__b
argument_list|,
name|__b
argument_list|,
name|__b
argument_list|,
name|__b
argument_list|,
name|__b
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 64-bit integer vector, initialized in reverse order with
end_comment

begin_comment
comment|///    the specified 32-bit integer values.
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
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __i0
end_comment

begin_comment
comment|///    A 32-bit integer value used to initialize the lower 32 bits of the
end_comment

begin_comment
comment|///    result.
end_comment

begin_comment
comment|/// \param __i1
end_comment

begin_comment
comment|///    A 32-bit integer value used to initialize the upper 32 bits of the
end_comment

begin_comment
comment|///    result.
end_comment

begin_comment
comment|/// \returns An initialized 64-bit integer vector.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_setr_pi32
parameter_list|(
name|int
name|__i0
parameter_list|,
name|int
name|__i1
parameter_list|)
block|{
return|return
name|_mm_set_pi32
argument_list|(
name|__i1
argument_list|,
name|__i0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 64-bit integer vector, initialized in reverse order with
end_comment

begin_comment
comment|///    the specified 16-bit integer values.
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
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __w0
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [15:0] of the result.
end_comment

begin_comment
comment|/// \param __w1
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [31:16] of the result.
end_comment

begin_comment
comment|/// \param __w2
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [47:32] of the result.
end_comment

begin_comment
comment|/// \param __w3
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [63:48] of the result.
end_comment

begin_comment
comment|/// \returns An initialized 64-bit integer vector.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_setr_pi16
parameter_list|(
name|short
name|__w0
parameter_list|,
name|short
name|__w1
parameter_list|,
name|short
name|__w2
parameter_list|,
name|short
name|__w3
parameter_list|)
block|{
return|return
name|_mm_set_pi16
argument_list|(
name|__w3
argument_list|,
name|__w2
argument_list|,
name|__w1
argument_list|,
name|__w0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Constructs a 64-bit integer vector, initialized in reverse order with
end_comment

begin_comment
comment|///    the specified 8-bit integer values.
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
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __b0
end_comment

begin_comment
comment|///    An 8-bit integer value used to initialize bits [7:0] of the result.
end_comment

begin_comment
comment|/// \param __b1
end_comment

begin_comment
comment|///    An 8-bit integer value used to initialize bits [15:8] of the result.
end_comment

begin_comment
comment|/// \param __b2
end_comment

begin_comment
comment|///    An 8-bit integer value used to initialize bits [23:16] of the result.
end_comment

begin_comment
comment|/// \param __b3
end_comment

begin_comment
comment|///    An 8-bit integer value used to initialize bits [31:24] of the result.
end_comment

begin_comment
comment|/// \param __b4
end_comment

begin_comment
comment|///    An 8-bit integer value used to initialize bits [39:32] of the result.
end_comment

begin_comment
comment|/// \param __b5
end_comment

begin_comment
comment|///    An 8-bit integer value used to initialize bits [47:40] of the result.
end_comment

begin_comment
comment|/// \param __b6
end_comment

begin_comment
comment|///    An 8-bit integer value used to initialize bits [55:48] of the result.
end_comment

begin_comment
comment|/// \param __b7
end_comment

begin_comment
comment|///    An 8-bit integer value used to initialize bits [63:56] of the result.
end_comment

begin_comment
comment|/// \returns An initialized 64-bit integer vector.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_setr_pi8
parameter_list|(
name|char
name|__b0
parameter_list|,
name|char
name|__b1
parameter_list|,
name|char
name|__b2
parameter_list|,
name|char
name|__b3
parameter_list|,
name|char
name|__b4
parameter_list|,
name|char
name|__b5
parameter_list|,
name|char
name|__b6
parameter_list|,
name|char
name|__b7
parameter_list|)
block|{
return|return
name|_mm_set_pi8
argument_list|(
name|__b7
argument_list|,
name|__b6
argument_list|,
name|__b5
argument_list|,
name|__b4
argument_list|,
name|__b3
argument_list|,
name|__b2
argument_list|,
name|__b1
argument_list|,
name|__b0
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|__DEFAULT_FN_ATTRS
end_undef

begin_comment
comment|/* Aliases for compatibility. */
end_comment

begin_define
define|#
directive|define
name|_m_empty
value|_mm_empty
end_define

begin_define
define|#
directive|define
name|_m_from_int
value|_mm_cvtsi32_si64
end_define

begin_define
define|#
directive|define
name|_m_from_int64
value|_mm_cvtsi64_m64
end_define

begin_define
define|#
directive|define
name|_m_to_int
value|_mm_cvtsi64_si32
end_define

begin_define
define|#
directive|define
name|_m_to_int64
value|_mm_cvtm64_si64
end_define

begin_define
define|#
directive|define
name|_m_packsswb
value|_mm_packs_pi16
end_define

begin_define
define|#
directive|define
name|_m_packssdw
value|_mm_packs_pi32
end_define

begin_define
define|#
directive|define
name|_m_packuswb
value|_mm_packs_pu16
end_define

begin_define
define|#
directive|define
name|_m_punpckhbw
value|_mm_unpackhi_pi8
end_define

begin_define
define|#
directive|define
name|_m_punpckhwd
value|_mm_unpackhi_pi16
end_define

begin_define
define|#
directive|define
name|_m_punpckhdq
value|_mm_unpackhi_pi32
end_define

begin_define
define|#
directive|define
name|_m_punpcklbw
value|_mm_unpacklo_pi8
end_define

begin_define
define|#
directive|define
name|_m_punpcklwd
value|_mm_unpacklo_pi16
end_define

begin_define
define|#
directive|define
name|_m_punpckldq
value|_mm_unpacklo_pi32
end_define

begin_define
define|#
directive|define
name|_m_paddb
value|_mm_add_pi8
end_define

begin_define
define|#
directive|define
name|_m_paddw
value|_mm_add_pi16
end_define

begin_define
define|#
directive|define
name|_m_paddd
value|_mm_add_pi32
end_define

begin_define
define|#
directive|define
name|_m_paddsb
value|_mm_adds_pi8
end_define

begin_define
define|#
directive|define
name|_m_paddsw
value|_mm_adds_pi16
end_define

begin_define
define|#
directive|define
name|_m_paddusb
value|_mm_adds_pu8
end_define

begin_define
define|#
directive|define
name|_m_paddusw
value|_mm_adds_pu16
end_define

begin_define
define|#
directive|define
name|_m_psubb
value|_mm_sub_pi8
end_define

begin_define
define|#
directive|define
name|_m_psubw
value|_mm_sub_pi16
end_define

begin_define
define|#
directive|define
name|_m_psubd
value|_mm_sub_pi32
end_define

begin_define
define|#
directive|define
name|_m_psubsb
value|_mm_subs_pi8
end_define

begin_define
define|#
directive|define
name|_m_psubsw
value|_mm_subs_pi16
end_define

begin_define
define|#
directive|define
name|_m_psubusb
value|_mm_subs_pu8
end_define

begin_define
define|#
directive|define
name|_m_psubusw
value|_mm_subs_pu16
end_define

begin_define
define|#
directive|define
name|_m_pmaddwd
value|_mm_madd_pi16
end_define

begin_define
define|#
directive|define
name|_m_pmulhw
value|_mm_mulhi_pi16
end_define

begin_define
define|#
directive|define
name|_m_pmullw
value|_mm_mullo_pi16
end_define

begin_define
define|#
directive|define
name|_m_psllw
value|_mm_sll_pi16
end_define

begin_define
define|#
directive|define
name|_m_psllwi
value|_mm_slli_pi16
end_define

begin_define
define|#
directive|define
name|_m_pslld
value|_mm_sll_pi32
end_define

begin_define
define|#
directive|define
name|_m_pslldi
value|_mm_slli_pi32
end_define

begin_define
define|#
directive|define
name|_m_psllq
value|_mm_sll_si64
end_define

begin_define
define|#
directive|define
name|_m_psllqi
value|_mm_slli_si64
end_define

begin_define
define|#
directive|define
name|_m_psraw
value|_mm_sra_pi16
end_define

begin_define
define|#
directive|define
name|_m_psrawi
value|_mm_srai_pi16
end_define

begin_define
define|#
directive|define
name|_m_psrad
value|_mm_sra_pi32
end_define

begin_define
define|#
directive|define
name|_m_psradi
value|_mm_srai_pi32
end_define

begin_define
define|#
directive|define
name|_m_psrlw
value|_mm_srl_pi16
end_define

begin_define
define|#
directive|define
name|_m_psrlwi
value|_mm_srli_pi16
end_define

begin_define
define|#
directive|define
name|_m_psrld
value|_mm_srl_pi32
end_define

begin_define
define|#
directive|define
name|_m_psrldi
value|_mm_srli_pi32
end_define

begin_define
define|#
directive|define
name|_m_psrlq
value|_mm_srl_si64
end_define

begin_define
define|#
directive|define
name|_m_psrlqi
value|_mm_srli_si64
end_define

begin_define
define|#
directive|define
name|_m_pand
value|_mm_and_si64
end_define

begin_define
define|#
directive|define
name|_m_pandn
value|_mm_andnot_si64
end_define

begin_define
define|#
directive|define
name|_m_por
value|_mm_or_si64
end_define

begin_define
define|#
directive|define
name|_m_pxor
value|_mm_xor_si64
end_define

begin_define
define|#
directive|define
name|_m_pcmpeqb
value|_mm_cmpeq_pi8
end_define

begin_define
define|#
directive|define
name|_m_pcmpeqw
value|_mm_cmpeq_pi16
end_define

begin_define
define|#
directive|define
name|_m_pcmpeqd
value|_mm_cmpeq_pi32
end_define

begin_define
define|#
directive|define
name|_m_pcmpgtb
value|_mm_cmpgt_pi8
end_define

begin_define
define|#
directive|define
name|_m_pcmpgtw
value|_mm_cmpgt_pi16
end_define

begin_define
define|#
directive|define
name|_m_pcmpgtd
value|_mm_cmpgt_pi32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MMINTRIN_H */
end_comment

end_unit

