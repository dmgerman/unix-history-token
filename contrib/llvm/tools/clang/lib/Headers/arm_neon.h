begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- arm_neon.h - NEON intrinsics --------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ARM_NEON_H
end_ifndef

begin_define
define|#
directive|define
name|__ARM_NEON_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__ARM_NEON__
end_ifndef

begin_error
error|#
directive|error
literal|"NEON support not enabled"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// NEON document appears to be specified in terms of stdint types.
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// Define some NEON-specific scalar types for floats and polynomials.
end_comment

begin_typedef
typedef|typedef
name|float
name|float32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|poly8_t
typedef|;
end_typedef

begin_comment
comment|// FIXME: probably need a 'poly' attribute or something for correct codegen to
end_comment

begin_comment
comment|//        disambiguate from uint16_t.
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|poly16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|8
argument|) )
argument_list|)
name|int8_t
name|__neon_int8x8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|16
argument|) )
argument_list|)
name|int8_t
name|__neon_int8x16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|8
argument|) )
argument_list|)
name|int16_t
name|__neon_int16x4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|16
argument|) )
argument_list|)
name|int16_t
name|__neon_int16x8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|8
argument|) )
argument_list|)
name|int32_t
name|__neon_int32x2_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|16
argument|) )
argument_list|)
name|int32_t
name|__neon_int32x4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|8
argument|) )
argument_list|)
name|int64_t
name|__neon_int64x1_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|16
argument|) )
argument_list|)
name|int64_t
name|__neon_int64x2_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|8
argument|) )
argument_list|)
name|uint8_t
name|__neon_uint8x8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|16
argument|) )
argument_list|)
name|uint8_t
name|__neon_uint8x16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|8
argument|) )
argument_list|)
name|uint16_t
name|__neon_uint16x4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|16
argument|) )
argument_list|)
name|uint16_t
name|__neon_uint16x8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|8
argument|) )
argument_list|)
name|uint32_t
name|__neon_uint32x2_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|16
argument|) )
argument_list|)
name|uint32_t
name|__neon_uint32x4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|8
argument|) )
argument_list|)
name|uint64_t
name|__neon_uint64x1_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|16
argument|) )
argument_list|)
name|uint64_t
name|__neon_uint64x2_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|8
argument|) )
argument_list|)
name|uint16_t
name|__neon_float16x4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|16
argument|) )
argument_list|)
name|uint16_t
name|__neon_float16x8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|8
argument|) )
argument_list|)
name|float32_t
name|__neon_float32x2_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|16
argument|) )
argument_list|)
name|float32_t
name|__neon_float32x4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|8
argument|) )
argument_list|)
name|poly8_t
name|__neon_poly8x8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|16
argument|) )
argument_list|)
name|poly8_t
name|__neon_poly8x16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|8
argument|) )
argument_list|)
name|poly16_t
name|__neon_poly16x4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|16
argument|) )
argument_list|)
name|poly16_t
name|__neon_poly16x8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__int8x8_t
block|{
name|__neon_int8x8_t
name|val
decl_stmt|;
block|}
name|int8x8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__int8x16_t
block|{
name|__neon_int8x16_t
name|val
decl_stmt|;
block|}
name|int8x16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__int16x4_t
block|{
name|__neon_int16x4_t
name|val
decl_stmt|;
block|}
name|int16x4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__int16x8_t
block|{
name|__neon_int16x8_t
name|val
decl_stmt|;
block|}
name|int16x8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__int32x2_t
block|{
name|__neon_int32x2_t
name|val
decl_stmt|;
block|}
name|int32x2_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__int32x4_t
block|{
name|__neon_int32x4_t
name|val
decl_stmt|;
block|}
name|int32x4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__int64x1_t
block|{
name|__neon_int64x1_t
name|val
decl_stmt|;
block|}
name|int64x1_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__int64x2_t
block|{
name|__neon_int64x2_t
name|val
decl_stmt|;
block|}
name|int64x2_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__uint8x8_t
block|{
name|__neon_uint8x8_t
name|val
decl_stmt|;
block|}
name|uint8x8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__uint8x16_t
block|{
name|__neon_uint8x16_t
name|val
decl_stmt|;
block|}
name|uint8x16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__uint16x4_t
block|{
name|__neon_uint16x4_t
name|val
decl_stmt|;
block|}
name|uint16x4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__uint16x8_t
block|{
name|__neon_uint16x8_t
name|val
decl_stmt|;
block|}
name|uint16x8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__uint32x2_t
block|{
name|__neon_uint32x2_t
name|val
decl_stmt|;
block|}
name|uint32x2_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__uint32x4_t
block|{
name|__neon_uint32x4_t
name|val
decl_stmt|;
block|}
name|uint32x4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__uint64x1_t
block|{
name|__neon_uint64x1_t
name|val
decl_stmt|;
block|}
name|uint64x1_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__uint64x2_t
block|{
name|__neon_uint64x2_t
name|val
decl_stmt|;
block|}
name|uint64x2_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__float16x4_t
block|{
name|__neon_float16x4_t
name|val
decl_stmt|;
block|}
name|float16x4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__float16x8_t
block|{
name|__neon_float16x8_t
name|val
decl_stmt|;
block|}
name|float16x8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__float32x2_t
block|{
name|__neon_float32x2_t
name|val
decl_stmt|;
block|}
name|float32x2_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__float32x4_t
block|{
name|__neon_float32x4_t
name|val
decl_stmt|;
block|}
name|float32x4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__poly8x8_t
block|{
name|__neon_poly8x8_t
name|val
decl_stmt|;
block|}
name|poly8x8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__poly8x16_t
block|{
name|__neon_poly8x16_t
name|val
decl_stmt|;
block|}
name|poly8x16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__poly16x4_t
block|{
name|__neon_poly16x4_t
name|val
decl_stmt|;
block|}
name|poly16x4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__poly16x8_t
block|{
name|__neon_poly16x8_t
name|val
decl_stmt|;
block|}
name|poly16x8_t
typedef|;
end_typedef

begin_comment
comment|// FIXME: write tool to stamp out the structure-of-array types, possibly gen this whole file.
end_comment

begin_comment
comment|// Intrinsics, per ARM document DUI0348B
end_comment

begin_define
define|#
directive|define
name|__ai
value|static __attribute__((__always_inline__))
end_define

begin_define
define|#
directive|define
name|INTTYPES_WIDE
parameter_list|(
name|op
parameter_list|,
name|builtin
parameter_list|)
define|\
value|__ai int16x8_t op##_s8(int16x8_t a, int8x8_t b) { return (int16x8_t){ builtin(a.val, b.val) }; } \   __ai int32x4_t op##_s16(int32x4_t a, int16x4_t b) { return (int32x4_t){ builtin(a.val, b.val) }; } \   __ai int64x2_t op##_s32(int64x2_t a, int32x2_t b) { return (int64x2_t){ builtin(a.val, b.val) }; } \   __ai uint16x8_t op##_u8(uint16x8_t a, uint8x8_t b) { return (uint16x8_t){ builtin(a.val, b.val) }; } \   __ai uint32x4_t op##_u16(uint32x4_t a, uint16x4_t b) { return (uint32x4_t){ builtin(a.val, b.val) }; } \   __ai uint64x2_t op##_u32(uint64x2_t a, uint32x2_t b) { return (uint64x2_t){ builtin(a.val, b.val) }; }
end_define

begin_define
define|#
directive|define
name|INTTYPES_WIDENING
parameter_list|(
name|op
parameter_list|,
name|builtin
parameter_list|)
define|\
value|__ai int16x8_t op##_s8(int8x8_t a, int8x8_t b) { return (int16x8_t){ builtin(a.val, b.val) }; } \   __ai int32x4_t op##_s16(int16x4_t a, int16x4_t b) { return (int32x4_t){ builtin(a.val, b.val) }; } \   __ai int64x2_t op##_s32(int32x2_t a, int32x2_t b) { return (int64x2_t){ builtin(a.val, b.val) }; } \   __ai uint16x8_t op##_u8(uint8x8_t a, uint8x8_t b) { return (uint16x8_t){ builtin(a.val, b.val) }; } \   __ai uint32x4_t op##_u16(uint16x4_t a, uint16x4_t b) { return (uint32x4_t){ builtin(a.val, b.val) }; } \   __ai uint64x2_t op##_u32(uint32x2_t a, uint32x2_t b) { return (uint64x2_t){ builtin(a.val, b.val) }; }
end_define

begin_define
define|#
directive|define
name|INTTYPES_WIDENING_MUL
parameter_list|(
name|op
parameter_list|,
name|builtin
parameter_list|)
define|\
value|__ai int16x8_t op##_s8(int16x8_t a, int8x8_t b, int8x8_t c) { return (int16x8_t){ builtin(a.val, b.val, c.val) }; } \   __ai int32x4_t op##_s16(int32x4_t a, int16x4_t b, int16x4_t c) { return (int32x4_t){ builtin(a.val, b.val, c.val) }; } \   __ai int64x2_t op##_s32(int64x2_t a, int32x2_t b, int32x2_t c) { return (int64x2_t){ builtin(a.val, b.val, c.val) }; } \   __ai uint16x8_t op##_u8(uint16x8_t a, uint8x8_t b, uint8x8_t c) { return (uint16x8_t){ builtin(a.val, b.val, c.val) }; } \   __ai uint32x4_t op##_u16(uint32x4_t a, uint16x4_t b, uint16x4_t c) { return (uint32x4_t){ builtin(a.val, b.val, c.val) }; } \   __ai uint64x2_t op##_u32(uint64x2_t a, uint32x2_t b, uint32x2_t c) { return (uint64x2_t){ builtin(a.val, b.val, c.val) }; }
end_define

begin_define
define|#
directive|define
name|INTTYPES_NARROWING
parameter_list|(
name|op
parameter_list|,
name|builtin
parameter_list|)
define|\
value|__ai int8x8_t op##_s16(int16x8_t a, int16x8_t b) { return (int8x8_t){ builtin(a.val, b.val) }; } \   __ai int16x4_t op##_s32(int32x4_t a, int32x4_t b) { return (int16x4_t){ builtin(a.val, b.val) }; } \   __ai int32x2_t op##_s64(int64x2_t a, int64x2_t b) { return (int32x2_t){ builtin(a.val, b.val) }; } \   __ai uint8x8_t op##_u16(uint16x8_t a, uint16x8_t b) { return (uint8x8_t){ builtin(a.val, b.val) }; } \   __ai uint16x4_t op##_u32(uint32x4_t a, uint32x4_t b) { return (uint16x4_t){ builtin(a.val, b.val) }; } \   __ai uint32x2_t op##_u64(uint64x2_t a, uint64x2_t b) { return (uint32x2_t){ builtin(a.val, b.val) }; }
end_define

begin_define
define|#
directive|define
name|INTTYPES_ADD_32
parameter_list|(
name|op
parameter_list|,
name|builtin
parameter_list|)
define|\
value|__ai int8x8_t op##_s8(int8x8_t a, int8x8_t b) { return (int8x8_t){ builtin(a.val, b.val) }; } \   __ai int16x4_t op##_s16(int16x4_t a, int16x4_t b) { return (int16x4_t){ builtin(a.val, b.val) }; } \   __ai int32x2_t op##_s32(int32x2_t a, int32x2_t b) { return (int32x2_t){ builtin(a.val, b.val) }; } \   __ai uint8x8_t op##_u8(uint8x8_t a, uint8x8_t b) { return (uint8x8_t){ builtin(a.val, b.val) }; } \   __ai uint16x4_t op##_u16(uint16x4_t a, uint16x4_t b) { return (uint16x4_t){ builtin(a.val, b.val) }; } \   __ai uint32x2_t op##_u32(uint32x2_t a, uint32x2_t b) { return (uint32x2_t){ builtin(a.val, b.val) }; } \   __ai int8x16_t op##q_s8(int8x16_t a, int8x16_t b) { return (int8x16_t){ builtin(a.val, b.val) }; } \   __ai int16x8_t op##q_s16(int16x8_t a, int16x8_t b) { return (int16x8_t){ builtin(a.val, b.val) }; } \   __ai int32x4_t op##q_s32(int32x4_t a, int32x4_t b) { return (int32x4_t){ builtin(a.val, b.val) }; } \   __ai uint8x16_t op##q_u8(uint8x16_t a, uint8x16_t b) { return (uint8x16_t){ builtin(a.val, b.val) }; } \   __ai uint16x8_t op##q_u16(uint16x8_t a, uint16x8_t b) { return (uint16x8_t){ builtin(a.val, b.val) }; } \   __ai uint32x4_t op##q_u32(uint32x4_t a, uint32x4_t b) { return (uint32x4_t){ builtin(a.val, b.val) }; }
end_define

begin_define
define|#
directive|define
name|INTTYPES_ADD_64
parameter_list|(
name|op
parameter_list|,
name|builtin
parameter_list|)
define|\
value|__ai int64x1_t op##_s64(int64x1_t a, int64x1_t b) { return (int64x1_t){ builtin(a.val, b.val) }; } \   __ai uint64x1_t op##_u64(uint64x1_t a, uint64x1_t b) { return (uint64x1_t){ builtin(a.val, b.val) }; } \   __ai int64x2_t op##q_s64(int64x2_t a, int64x2_t b) { return (int64x2_t){ builtin(a.val, b.val) }; } \   __ai uint64x2_t op##q_u64(uint64x2_t a, uint64x2_t b) { return (uint64x2_t){ builtin(a.val, b.val) }; }
end_define

begin_define
define|#
directive|define
name|FLOATTYPES_CMP
parameter_list|(
name|op
parameter_list|,
name|builtin
parameter_list|)
define|\
value|__ai uint32x2_t op##_f32(float32x2_t a, float32x2_t b) { return (uint32x2_t){ builtin(a.val, b.val) }; } \   __ai uint32x4_t op##q_f32(float32x4_t a, float32x4_t b) { return (uint32x4_t){ builtin(a.val, b.val) }; }
end_define

begin_define
define|#
directive|define
name|INT_FLOAT_CMP_OP
parameter_list|(
name|op
parameter_list|,
name|cc
parameter_list|)
define|\
value|__ai uint8x8_t op##_s8(int8x8_t a, int8x8_t b) { return (uint8x8_t){(__neon_uint8x8_t)(a.val cc b.val)}; } \   __ai uint16x4_t op##_s16(int16x4_t a, int16x4_t b) { return (uint16x4_t){(__neon_uint16x4_t)(a.val cc b.val)}; } \   __ai uint32x2_t op##_s32(int32x2_t a, int32x2_t b) { return (uint32x2_t){(__neon_uint32x2_t)(a.val cc b.val)}; } \   __ai uint32x2_t op##_f32(float32x2_t a, float32x2_t b) { return (uint32x2_t){(__neon_uint32x2_t)(a.val cc b.val)}; } \   __ai uint8x8_t op##_u8(uint8x8_t a, uint8x8_t b) { return (uint8x8_t){a.val cc b.val}; } \   __ai uint16x4_t op##_u16(uint16x4_t a, uint16x4_t b) { return (uint16x4_t){a.val cc b.val}; } \   __ai uint32x2_t op##_u32(uint32x2_t a, uint32x2_t b) { return (uint32x2_t){a.val cc b.val}; } \   __ai uint8x16_t op##q_s8(int8x16_t a, int8x16_t b) { return (uint8x16_t){(__neon_uint8x16_t)(a.val cc b.val)}; } \   __ai uint16x8_t op##q_s16(int16x8_t a, int16x8_t b) { return (uint16x8_t){(__neon_uint16x8_t)(a.val cc b.val)}; } \   __ai uint32x4_t op##q_s32(int32x4_t a, int32x4_t b) { return (uint32x4_t){(__neon_uint32x4_t)(a.val cc b.val)}; } \   __ai uint32x4_t op##q_f32(float32x4_t a, float32x4_t b) { return (uint32x4_t){(__neon_uint32x4_t)(a.val cc b.val)}; } \   __ai uint8x16_t op##q_u8(uint8x16_t a, uint8x16_t b) { return (uint8x16_t){a.val cc b.val}; } \   __ai uint16x8_t op##q_u16(uint16x8_t a, uint16x8_t b) { return (uint16x8_t){a.val cc b.val}; } \   __ai uint32x4_t op##q_u32(uint32x4_t a, uint32x4_t b) { return (uint32x4_t){a.val cc b.val}; }
end_define

begin_define
define|#
directive|define
name|INT_UNARY
parameter_list|(
name|op
parameter_list|,
name|builtin
parameter_list|)
define|\
value|__ai int8x8_t op##_s8(int8x8_t a) { return (int8x8_t){ builtin(a.val) }; } \   __ai int16x4_t op##_s16(int16x4_t a) { return (int16x4_t){ builtin(a.val) }; } \   __ai int32x2_t op##_s32(int32x2_t a) { return (int32x2_t){ builtin(a.val) }; } \   __ai int8x16_t op##q_s8(int8x16_t a) { return (int8x16_t){ builtin(a.val) }; } \   __ai int16x8_t op##q_s16(int16x8_t a) { return (int16x8_t){ builtin(a.val) }; } \   __ai int32x4_t op##q_s32(int32x4_t a) { return (int32x4_t){ builtin(a.val) }; }
end_define

begin_define
define|#
directive|define
name|FP_UNARY
parameter_list|(
name|op
parameter_list|,
name|builtin
parameter_list|)
define|\
value|__ai float32x2_t op##_f32(float32x2_t a) { return (float32x2_t){ builtin(a.val) }; } \   __ai float32x4_t op##q_f32(float32x4_t a) { return (float32x4_t){ builtin(a.val) }; }
end_define

begin_define
define|#
directive|define
name|FP_BINARY
parameter_list|(
name|op
parameter_list|,
name|builtin
parameter_list|)
define|\
value|__ai float32x2_t op##_f32(float32x2_t a, float32x2_t b) { return (float32x2_t){ builtin(a.val, b.val) }; } \   __ai float32x4_t op##q_f32(float32x4_t a, float32x4_t b) { return (float32x4_t){ builtin(a.val, b.val) }; }
end_define

begin_define
define|#
directive|define
name|INT_FP_PAIRWISE_ADD
parameter_list|(
name|op
parameter_list|,
name|builtin
parameter_list|)
define|\
value|__ai int8x8_t op##_s8(int8x8_t a, int8x8_t b) { return (int8x8_t){ builtin(a.val, b.val) }; } \   __ai int16x4_t op##_s16(int16x4_t a, int16x4_t b) { return (int16x4_t){ builtin(a.val, b.val) }; } \   __ai int32x2_t op##_s32(int32x2_t a, int32x2_t b) { return (int32x2_t){ builtin(a.val, b.val) }; } \   __ai uint8x8_t op##_u8(uint8x8_t a, uint8x8_t b) { return (uint8x8_t){ builtin(a.val, b.val) }; } \   __ai uint16x4_t op##_u16(uint16x4_t a, uint16x4_t b) { return (uint16x4_t){ builtin(a.val, b.val) }; } \   __ai uint32x2_t op##_u32(uint32x2_t a, uint32x2_t b) { return (uint32x2_t){ builtin(a.val, b.val) }; } \   __ai float32x2_t op##_f32(float32x2_t a, float32x2_t b) { return (float32x2_t){ builtin(a.val, b.val) }; }
end_define

begin_define
define|#
directive|define
name|INT_LOGICAL_OP
parameter_list|(
name|op
parameter_list|,
name|lop
parameter_list|)
define|\
value|__ai int8x8_t op##_s8(int8x8_t a, int8x8_t b) { return (int8x8_t){ a.val lop b.val }; } \   __ai int16x4_t op##_s16(int16x4_t a, int16x4_t b) { return (int16x4_t){ a.val lop b.val }; } \   __ai int32x2_t op##_s32(int32x2_t a, int32x2_t b) { return (int32x2_t){ a.val lop b.val }; } \   __ai int64x1_t op##_s64(int64x1_t a, int64x1_t b) { return (int64x1_t){ a.val lop b.val }; } \   __ai uint8x8_t op##_u8(uint8x8_t a, uint8x8_t b) { return (uint8x8_t){ a.val lop b.val }; } \   __ai uint16x4_t op##_u16(uint16x4_t a, uint16x4_t b) { return (uint16x4_t){ a.val lop b.val }; } \   __ai uint32x2_t op##_u32(uint32x2_t a, uint32x2_t b) { return (uint32x2_t){ a.val lop b.val }; } \   __ai uint64x1_t op##_u64(uint64x1_t a, uint64x1_t b) { return (uint64x1_t){ a.val lop b.val }; } \   __ai int8x16_t op##q_s8(int8x16_t a, int8x16_t b) { return (int8x16_t){ a.val lop b.val }; } \   __ai int16x8_t op##q_s16(int16x8_t a, int16x8_t b) { return (int16x8_t){ a.val lop b.val }; } \   __ai int32x4_t op##q_s32(int32x4_t a, int32x4_t b) { return (int32x4_t){ a.val lop b.val }; } \   __ai int64x2_t op##q_s64(int64x2_t a, int64x2_t b) { return (int64x2_t){ a.val lop b.val }; } \   __ai uint8x16_t op##q_u8(uint8x16_t a, uint8x16_t b) { return (uint8x16_t){ a.val lop b.val }; } \   __ai uint16x8_t op##q_u16(uint16x8_t a, uint16x8_t b) { return (uint16x8_t){ a.val lop b.val }; } \   __ai uint32x4_t op##q_u32(uint32x4_t a, uint32x4_t b) { return (uint32x4_t){ a.val lop b.val }; } \   __ai uint64x2_t op##q_u64(uint64x2_t a, uint64x2_t b) { return (uint64x2_t){ a.val lop b.val }; }
end_define

begin_comment
comment|// vector add
end_comment

begin_function
name|__ai
name|int8x8_t
name|vadd_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|int8x8_t
operator|)
block|{
name|a
operator|.
name|val
operator|+
name|b
operator|.
name|val
block|}
return|;
block|}
end_function

begin_function
name|__ai
name|int16x4_t
name|vadd_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|int16x4_t
operator|)
block|{
name|a
operator|.
name|val
operator|+
name|b
operator|.
name|val
block|}
return|;
block|}
end_function

begin_function
name|__ai
name|int32x2_t
name|vadd_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|int32x2_t
operator|)
block|{
name|a
operator|.
name|val
operator|+
name|b
operator|.
name|val
block|}
return|;
block|}
end_function

begin_function
name|__ai
name|int64x1_t
name|vadd_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|int64x1_t
operator|)
block|{
name|a
operator|.
name|val
operator|+
name|b
operator|.
name|val
block|}
return|;
block|}
end_function

begin_function
name|__ai
name|float32x2_t
name|vadd_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|float32x2_t
operator|)
block|{
name|a
operator|.
name|val
operator|+
name|b
operator|.
name|val
block|}
return|;
block|}
end_function

begin_function
name|__ai
name|uint8x8_t
name|vadd_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|uint8x8_t
operator|)
block|{
name|a
operator|.
name|val
operator|+
name|b
operator|.
name|val
block|}
return|;
block|}
end_function

begin_function
name|__ai
name|uint16x4_t
name|vadd_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|uint16x4_t
operator|)
block|{
name|a
operator|.
name|val
operator|+
name|b
operator|.
name|val
block|}
return|;
block|}
end_function

begin_function
name|__ai
name|uint32x2_t
name|vadd_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|uint32x2_t
operator|)
block|{
name|a
operator|.
name|val
operator|+
name|b
operator|.
name|val
block|}
return|;
block|}
end_function

begin_function
name|__ai
name|uint64x1_t
name|vadd_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|uint64x1_t
operator|)
block|{
name|a
operator|.
name|val
operator|+
name|b
operator|.
name|val
block|}
return|;
block|}
end_function

begin_function
name|__ai
name|int8x16_t
name|vaddq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|int8x16_t
operator|)
block|{
name|a
operator|.
name|val
operator|+
name|b
operator|.
name|val
block|}
return|;
block|}
end_function

begin_function
name|__ai
name|int16x8_t
name|vaddq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|int16x8_t
operator|)
block|{
name|a
operator|.
name|val
operator|+
name|b
operator|.
name|val
block|}
return|;
block|}
end_function

begin_function
name|__ai
name|int32x4_t
name|vaddq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|int32x4_t
operator|)
block|{
name|a
operator|.
name|val
operator|+
name|b
operator|.
name|val
block|}
return|;
block|}
end_function

begin_function
name|__ai
name|int64x2_t
name|vaddq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|int64x2_t
operator|)
block|{
name|a
operator|.
name|val
operator|+
name|b
operator|.
name|val
block|}
return|;
block|}
end_function

begin_function
name|__ai
name|float32x4_t
name|vaddq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|float32x4_t
operator|)
block|{
name|a
operator|.
name|val
operator|+
name|b
operator|.
name|val
block|}
return|;
block|}
end_function

begin_function
name|__ai
name|uint8x16_t
name|vaddq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|uint8x16_t
operator|)
block|{
name|a
operator|.
name|val
operator|+
name|b
operator|.
name|val
block|}
return|;
block|}
end_function

begin_function
name|__ai
name|uint16x8_t
name|vaddq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|uint16x8_t
operator|)
block|{
name|a
operator|.
name|val
operator|+
name|b
operator|.
name|val
block|}
return|;
block|}
end_function

begin_function
name|__ai
name|uint32x4_t
name|vaddq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|uint32x4_t
operator|)
block|{
name|a
operator|.
name|val
operator|+
name|b
operator|.
name|val
block|}
return|;
block|}
end_function

begin_function
name|__ai
name|uint64x2_t
name|vaddq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|uint64x2_t
operator|)
block|{
name|a
operator|.
name|val
operator|+
name|b
operator|.
name|val
block|}
return|;
block|}
end_function

begin_comment
comment|// vector long add
end_comment

begin_macro
name|INTTYPES_WIDENING
argument_list|(
argument|vaddl
argument_list|,
argument|__builtin_neon_vaddl
argument_list|)
end_macro

begin_comment
comment|// vector wide add
end_comment

begin_macro
name|INTTYPES_WIDE
argument_list|(
argument|vaddw
argument_list|,
argument|__builtin_neon_vaddw
argument_list|)
end_macro

begin_comment
comment|// halving add
end_comment

begin_comment
comment|// rounding halving add
end_comment

begin_macro
name|INTTYPES_ADD_32
argument_list|(
argument|vhadd
argument_list|,
argument|__builtin_neon_vhadd
argument_list|)
end_macro

begin_macro
name|INTTYPES_ADD_32
argument_list|(
argument|vrhadd
argument_list|,
argument|__builtin_neon_vrhadd
argument_list|)
end_macro

begin_comment
comment|// saturating add
end_comment

begin_macro
name|INTTYPES_ADD_32
argument_list|(
argument|vqadd
argument_list|,
argument|__builtin_neon_vqadd
argument_list|)
end_macro

begin_macro
name|INTTYPES_ADD_64
argument_list|(
argument|vqadd
argument_list|,
argument|__builtin_neon_vqadd
argument_list|)
end_macro

begin_comment
comment|// add high half
end_comment

begin_comment
comment|// rounding add high half
end_comment

begin_macro
name|INTTYPES_NARROWING
argument_list|(
argument|vaddhn
argument_list|,
argument|__builtin_neon_vaddhn
argument_list|)
end_macro

begin_macro
name|INTTYPES_NARROWING
argument_list|(
argument|vraddhn
argument_list|,
argument|__builtin_neon_vraddhn
argument_list|)
end_macro

begin_comment
comment|// multiply
end_comment

begin_comment
comment|// mul-poly
end_comment

begin_comment
comment|// multiple accumulate
end_comment

begin_comment
comment|// multiple subtract
end_comment

begin_comment
comment|// multiple accumulate long
end_comment

begin_comment
comment|// multiple subtract long
end_comment

begin_macro
name|INTTYPES_WIDENING_MUL
argument_list|(
argument|vmlal
argument_list|,
argument|__builtin_neon_vmlal
argument_list|)
end_macro

begin_macro
name|INTTYPES_WIDENING_MUL
argument_list|(
argument|vmlsl
argument_list|,
argument|__builtin_neon_vmlsl
argument_list|)
end_macro

begin_comment
comment|// saturating doubling multiply high
end_comment

begin_comment
comment|// saturating rounding doubling multiply high
end_comment

begin_comment
comment|// saturating doubling multiply accumulate long
end_comment

begin_comment
comment|// saturating doubling multiply subtract long
end_comment

begin_comment
comment|// long multiply
end_comment

begin_comment
comment|// long multiply-poly
end_comment

begin_macro
name|INTTYPES_WIDENING
argument_list|(
argument|vmull
argument_list|,
argument|__builtin_neon_vmull
argument_list|)
end_macro

begin_function
name|__ai
name|poly16x8_t
name|vmull_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|poly16x8_t
operator|)
block|{
name|__builtin_neon_vmull
argument_list|(
argument|a.val
argument_list|,
argument|b.val
argument_list|)
block|}
return|;
block|}
end_function

begin_comment
comment|// saturating doubling long multiply
end_comment

begin_comment
comment|// subtract
end_comment

begin_comment
comment|// long subtract
end_comment

begin_macro
name|INTTYPES_WIDENING
argument_list|(
argument|vsubl
argument_list|,
argument|__builtin_neon_vsubl
argument_list|)
end_macro

begin_comment
comment|// wide subtract
end_comment

begin_macro
name|INTTYPES_WIDE
argument_list|(
argument|vsubw
argument_list|,
argument|__builtin_neon_vsubw
argument_list|)
end_macro

begin_comment
comment|// saturating subtract
end_comment

begin_macro
name|INTTYPES_ADD_32
argument_list|(
argument|vqsub
argument_list|,
argument|__builtin_neon_vqsub
argument_list|)
end_macro

begin_macro
name|INTTYPES_ADD_64
argument_list|(
argument|vqsub
argument_list|,
argument|__builtin_neon_vqsub
argument_list|)
end_macro

begin_comment
comment|// halving subtract
end_comment

begin_macro
name|INTTYPES_ADD_32
argument_list|(
argument|vhsub
argument_list|,
argument|__builtin_neon_vhsub
argument_list|)
end_macro

begin_comment
comment|// subtract high half
end_comment

begin_comment
comment|// rounding subtract high half
end_comment

begin_macro
name|INTTYPES_NARROWING
argument_list|(
argument|vsubhn
argument_list|,
argument|__builtin_neon_vsubhn
argument_list|)
end_macro

begin_macro
name|INTTYPES_NARROWING
argument_list|(
argument|vrsubhn
argument_list|,
argument|__builtin_neon_vrsubhn
argument_list|)
end_macro

begin_comment
comment|// compare eq
end_comment

begin_comment
comment|// compare ge
end_comment

begin_comment
comment|// compare le
end_comment

begin_comment
comment|// compare gt
end_comment

begin_comment
comment|// compare lt
end_comment

begin_macro
name|INT_FLOAT_CMP_OP
argument_list|(
argument|vceq
argument_list|,
argument|==
argument_list|)
end_macro

begin_macro
name|INT_FLOAT_CMP_OP
argument_list|(
argument|vcge
argument_list|,
argument|>=
argument_list|)
end_macro

begin_macro
name|INT_FLOAT_CMP_OP
argument_list|(
argument|vcle
argument_list|,
argument|<=
argument_list|)
end_macro

begin_macro
name|INT_FLOAT_CMP_OP
argument_list|(
argument|vcgt
argument_list|,
argument|>
argument_list|)
end_macro

begin_macro
name|INT_FLOAT_CMP_OP
argument_list|(
argument|vclt
argument_list|,
argument|<
argument_list|)
end_macro

begin_comment
comment|// compare eq-poly
end_comment

begin_comment
comment|// compare abs ge
end_comment

begin_comment
comment|// compare abs le
end_comment

begin_comment
comment|// compare abs gt
end_comment

begin_comment
comment|// compare abs lt
end_comment

begin_macro
name|FLOATTYPES_CMP
argument_list|(
argument|vcage
argument_list|,
argument|__builtin_neon_vcage
argument_list|)
end_macro

begin_macro
name|FLOATTYPES_CMP
argument_list|(
argument|vcale
argument_list|,
argument|__builtin_neon_vcale
argument_list|)
end_macro

begin_macro
name|FLOATTYPES_CMP
argument_list|(
argument|vcagt
argument_list|,
argument|__builtin_neon_vcagt
argument_list|)
end_macro

begin_macro
name|FLOATTYPES_CMP
argument_list|(
argument|vcalt
argument_list|,
argument|__builtin_neon_vcalt
argument_list|)
end_macro

begin_comment
comment|// test bits
end_comment

begin_comment
comment|// abs diff
end_comment

begin_macro
name|INTTYPES_ADD_32
argument_list|(
argument|vabd
argument_list|,
argument|__builtin_neon_vabd
argument_list|)
end_macro

begin_macro
name|FP_BINARY
argument_list|(
argument|vabd
argument_list|,
argument|__builtin_neon_vabd
argument_list|)
end_macro

begin_comment
comment|// abs diff long
end_comment

begin_macro
name|INTTYPES_WIDENING
argument_list|(
argument|vabdl
argument_list|,
argument|__builtin_neon_vabdl
argument_list|)
end_macro

begin_comment
comment|// abs diff accumulate
end_comment

begin_comment
comment|// abs diff accumulate long
end_comment

begin_comment
comment|// max
end_comment

begin_comment
comment|// min
end_comment

begin_macro
name|INTTYPES_ADD_32
argument_list|(
argument|vmax
argument_list|,
argument|__builtin_neon_vmax
argument_list|)
end_macro

begin_macro
name|FP_BINARY
argument_list|(
argument|vmax
argument_list|,
argument|__builtin_neon_vmax
argument_list|)
end_macro

begin_macro
name|INTTYPES_ADD_32
argument_list|(
argument|vmin
argument_list|,
argument|__builtin_neon_vmin
argument_list|)
end_macro

begin_macro
name|FP_BINARY
argument_list|(
argument|vmin
argument_list|,
argument|__builtin_neon_vmin
argument_list|)
end_macro

begin_comment
comment|// pairwise add
end_comment

begin_comment
comment|// pairwise max
end_comment

begin_comment
comment|// pairwise min
end_comment

begin_macro
name|INT_FP_PAIRWISE_ADD
argument_list|(
argument|vpadd
argument_list|,
argument|__builtin_neon_vpadd
argument_list|)
end_macro

begin_macro
name|INT_FP_PAIRWISE_ADD
argument_list|(
argument|vpmax
argument_list|,
argument|__builtin_neon_vpmax
argument_list|)
end_macro

begin_macro
name|INT_FP_PAIRWISE_ADD
argument_list|(
argument|vpmin
argument_list|,
argument|__builtin_neon_vpmin
argument_list|)
end_macro

begin_comment
comment|// long pairwise add
end_comment

begin_comment
comment|// long pairwise add accumulate
end_comment

begin_comment
comment|// recip
end_comment

begin_comment
comment|// recip sqrt
end_comment

begin_macro
name|FP_BINARY
argument_list|(
argument|vrecps
argument_list|,
argument|__builtin_neon_vrecps
argument_list|)
end_macro

begin_macro
name|FP_BINARY
argument_list|(
argument|vrsqrts
argument_list|,
argument|__builtin_neon_vrsqrts
argument_list|)
end_macro

begin_comment
comment|// shl by vec
end_comment

begin_comment
comment|// saturating shl by vec
end_comment

begin_comment
comment|// rounding shl by vec
end_comment

begin_comment
comment|// saturating rounding shl by vec
end_comment

begin_comment
comment|// shr by constant
end_comment

begin_comment
comment|// shl by constant
end_comment

begin_comment
comment|// rounding shr by constant
end_comment

begin_comment
comment|// shr by constant and accumulate
end_comment

begin_comment
comment|// rounding shr by constant and accumulate
end_comment

begin_comment
comment|// saturating shl by constant
end_comment

begin_comment
comment|// s->u saturating shl by constant
end_comment

begin_comment
comment|// narrowing saturating shr by constant
end_comment

begin_comment
comment|// s->u narrowing saturating shr by constant
end_comment

begin_comment
comment|// s->u rounding narrowing saturating shr by constant
end_comment

begin_comment
comment|// narrowing saturating shr by constant
end_comment

begin_comment
comment|// rounding narrowing shr by constant
end_comment

begin_comment
comment|// rounding narrowing saturating shr by constant
end_comment

begin_comment
comment|// widening shl by constant
end_comment

begin_comment
comment|// shr and insert
end_comment

begin_comment
comment|// shl and insert
end_comment

begin_comment
comment|// loads and stores, single vector
end_comment

begin_comment
comment|// loads and stores, lane
end_comment

begin_comment
comment|// loads, dupe
end_comment

begin_comment
comment|// loads and stores, arrays
end_comment

begin_comment
comment|// vget,vgetq lane
end_comment

begin_comment
comment|// vset, vsetq lane
end_comment

begin_comment
comment|// vcreate
end_comment

begin_comment
comment|// vdup, vdupq
end_comment

begin_comment
comment|// vmov, vmovq
end_comment

begin_comment
comment|// vdup_lane, vdupq_lane
end_comment

begin_comment
comment|// vcombine
end_comment

begin_comment
comment|// vget_high, vget_low
end_comment

begin_comment
comment|// vcvt {u,s}<-> f, f<-> f16
end_comment

begin_comment
comment|// narrow
end_comment

begin_comment
comment|// long move (unpack)
end_comment

begin_comment
comment|// saturating narrow
end_comment

begin_comment
comment|// saturating narrow s->u
end_comment

begin_comment
comment|// table lookup
end_comment

begin_comment
comment|// extended table lookup
end_comment

begin_comment
comment|// mla with scalar
end_comment

begin_comment
comment|// widening mla with scalar
end_comment

begin_comment
comment|// widening saturating doubling mla with scalar
end_comment

begin_comment
comment|// mls with scalar
end_comment

begin_comment
comment|// widening mls with scalar
end_comment

begin_comment
comment|// widening saturating doubling mls with scalar
end_comment

begin_comment
comment|// mul by scalar
end_comment

begin_comment
comment|// long mul with scalar
end_comment

begin_comment
comment|// long mul by scalar
end_comment

begin_comment
comment|// saturating doubling long mul with scalar
end_comment

begin_comment
comment|// saturating doubling long mul by scalar
end_comment

begin_comment
comment|// saturating doubling mul high with scalar
end_comment

begin_comment
comment|// saturating doubling mul high by scalar
end_comment

begin_comment
comment|// saturating rounding doubling mul high with scalar
end_comment

begin_comment
comment|// saturating rounding doubling mul high by scalar
end_comment

begin_comment
comment|// mla with scalar
end_comment

begin_comment
comment|// widening mla with sclar
end_comment

begin_comment
comment|// widening saturating doubling mla with scalar
end_comment

begin_comment
comment|// mls with scalar
end_comment

begin_comment
comment|// widening mls with scalar
end_comment

begin_comment
comment|// widening saturating doubling mls with scalar
end_comment

begin_comment
comment|// extract
end_comment

begin_comment
comment|// endian swap (vrev)
end_comment

begin_comment
comment|// negate
end_comment

begin_comment
comment|// abs
end_comment

begin_comment
comment|// saturating abs
end_comment

begin_comment
comment|// saturating negate
end_comment

begin_comment
comment|// count leading signs
end_comment

begin_macro
name|INT_UNARY
argument_list|(
argument|vabs
argument_list|,
argument|__builtin_neon_vabs
argument_list|)
end_macro

begin_macro
name|FP_UNARY
argument_list|(
argument|vabs
argument_list|,
argument|__builtin_neon_vabs
argument_list|)
end_macro

begin_macro
name|INT_UNARY
argument_list|(
argument|vqabs
argument_list|,
argument|__builtin_neon_vqabs
argument_list|)
end_macro

begin_macro
name|INT_UNARY
argument_list|(
argument|vqneg
argument_list|,
argument|__builtin_neon_vqneg
argument_list|)
end_macro

begin_macro
name|INT_UNARY
argument_list|(
argument|vcls
argument_list|,
argument|__builtin_neon_vcls
argument_list|)
end_macro

begin_comment
comment|// count leading zeroes
end_comment

begin_comment
comment|// popcount
end_comment

begin_comment
comment|// recip_est
end_comment

begin_comment
comment|// recip_sqrt_est
end_comment

begin_comment
comment|// not-poly
end_comment

begin_comment
comment|// not
end_comment

begin_comment
comment|// and
end_comment

begin_comment
comment|// or
end_comment

begin_comment
comment|// xor
end_comment

begin_comment
comment|// andn
end_comment

begin_comment
comment|// orn
end_comment

begin_macro
name|INT_LOGICAL_OP
argument_list|(
argument|vand
argument_list|,
argument|&
argument_list|)
end_macro

begin_macro
name|INT_LOGICAL_OP
argument_list|(
argument|vorr
argument_list|,
argument||
argument_list|)
end_macro

begin_macro
name|INT_LOGICAL_OP
argument_list|(
argument|veor
argument_list|,
argument|^
argument_list|)
end_macro

begin_macro
name|INT_LOGICAL_OP
argument_list|(
argument|vbic
argument_list|,
argument|&~
argument_list|)
end_macro

begin_macro
name|INT_LOGICAL_OP
argument_list|(
argument|vorn
argument_list|,
argument||~
argument_list|)
end_macro

begin_comment
comment|// bitselect
end_comment

begin_comment
comment|// transpose elts
end_comment

begin_comment
comment|// interleave elts
end_comment

begin_comment
comment|// deinterleave elts
end_comment

begin_comment
comment|// vreinterpret
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ARM_NEON_H */
end_comment

end_unit

