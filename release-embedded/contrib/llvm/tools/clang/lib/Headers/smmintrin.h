begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- smmintrin.h - SSE4 intrinsics ------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMMINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|_SMMINTRIN_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__SSE4_1__
end_ifndef

begin_error
error|#
directive|error
literal|"SSE4.1 instruction set not enabled"
end_error

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<tmmintrin.h>
end_include

begin_comment
comment|/* SSE4 Rounding macros. */
end_comment

begin_define
define|#
directive|define
name|_MM_FROUND_TO_NEAREST_INT
value|0x00
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_TO_NEG_INF
value|0x01
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_TO_POS_INF
value|0x02
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_TO_ZERO
value|0x03
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_CUR_DIRECTION
value|0x04
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_RAISE_EXC
value|0x00
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_NO_EXC
value|0x08
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_NINT
value|(_MM_FROUND_RAISE_EXC | _MM_FROUND_TO_NEAREST_INT)
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_FLOOR
value|(_MM_FROUND_RAISE_EXC | _MM_FROUND_TO_NEG_INF)
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_CEIL
value|(_MM_FROUND_RAISE_EXC | _MM_FROUND_TO_POS_INF)
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_TRUNC
value|(_MM_FROUND_RAISE_EXC | _MM_FROUND_TO_ZERO)
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_RINT
value|(_MM_FROUND_RAISE_EXC | _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_MM_FROUND_NEARBYINT
value|(_MM_FROUND_NO_EXC | _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm_ceil_ps
parameter_list|(
name|X
parameter_list|)
value|_mm_round_ps((X), _MM_FROUND_CEIL)
end_define

begin_define
define|#
directive|define
name|_mm_ceil_pd
parameter_list|(
name|X
parameter_list|)
value|_mm_round_pd((X), _MM_FROUND_CEIL)
end_define

begin_define
define|#
directive|define
name|_mm_ceil_ss
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|_mm_round_ss((X), (Y), _MM_FROUND_CEIL)
end_define

begin_define
define|#
directive|define
name|_mm_ceil_sd
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|_mm_round_sd((X), (Y), _MM_FROUND_CEIL)
end_define

begin_define
define|#
directive|define
name|_mm_floor_ps
parameter_list|(
name|X
parameter_list|)
value|_mm_round_ps((X), _MM_FROUND_FLOOR)
end_define

begin_define
define|#
directive|define
name|_mm_floor_pd
parameter_list|(
name|X
parameter_list|)
value|_mm_round_pd((X), _MM_FROUND_FLOOR)
end_define

begin_define
define|#
directive|define
name|_mm_floor_ss
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|_mm_round_ss((X), (Y), _MM_FROUND_FLOOR)
end_define

begin_define
define|#
directive|define
name|_mm_floor_sd
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|_mm_round_sd((X), (Y), _MM_FROUND_FLOOR)
end_define

begin_define
define|#
directive|define
name|_mm_round_ps
parameter_list|(
name|X
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   __m128 __X = (X); \   (__m128) __builtin_ia32_roundps((__v4sf)__X, (M)); })
end_define

begin_define
define|#
directive|define
name|_mm_round_ss
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   __m128 __X = (X); \   __m128 __Y = (Y); \   (__m128) __builtin_ia32_roundss((__v4sf)__X, (__v4sf)__Y, (M)); })
end_define

begin_define
define|#
directive|define
name|_mm_round_pd
parameter_list|(
name|X
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   __m128d __X = (X); \   (__m128d) __builtin_ia32_roundpd((__v2df)__X, (M)); })
end_define

begin_define
define|#
directive|define
name|_mm_round_sd
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   __m128d __X = (X); \   __m128d __Y = (Y); \   (__m128d) __builtin_ia32_roundsd((__v2df)__X, (__v2df)__Y, (M)); })
end_define

begin_comment
comment|/* SSE4 Packed Blending Intrinsics.  */
end_comment

begin_define
define|#
directive|define
name|_mm_blend_pd
parameter_list|(
name|V1
parameter_list|,
name|V2
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   __m128d __V1 = (V1); \   __m128d __V2 = (V2); \   (__m128d) __builtin_ia32_blendpd ((__v2df)__V1, (__v2df)__V2, (M)); })
end_define

begin_define
define|#
directive|define
name|_mm_blend_ps
parameter_list|(
name|V1
parameter_list|,
name|V2
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   __m128 __V1 = (V1); \   __m128 __V2 = (V2); \   (__m128) __builtin_ia32_blendps ((__v4sf)__V1, (__v4sf)__V2, (M)); })
end_define

begin_decl_stmt
specifier|static
name|__inline__
name|__m128d
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_blendv_pd
argument_list|(
name|__m128d
name|__V1
argument_list|,
name|__m128d
name|__V2
argument_list|,
name|__m128d
name|__M
argument_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_blendvpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__V1
argument_list|,
operator|(
name|__v2df
operator|)
name|__V2
argument_list|,
operator|(
name|__v2df
operator|)
name|__M
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__m128
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_blendv_ps
argument_list|(
name|__m128
name|__V1
argument_list|,
name|__m128
name|__V2
argument_list|,
name|__m128
name|__M
argument_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_blendvps
argument_list|(
operator|(
name|__v4sf
operator|)
name|__V1
argument_list|,
operator|(
name|__v4sf
operator|)
name|__V2
argument_list|,
operator|(
name|__v4sf
operator|)
name|__M
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_blendv_epi8
argument_list|(
name|__m128i
name|__V1
argument_list|,
name|__m128i
name|__V2
argument_list|,
name|__m128i
name|__M
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pblendvb128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__V1
argument_list|,
operator|(
name|__v16qi
operator|)
name|__V2
argument_list|,
operator|(
name|__v16qi
operator|)
name|__M
argument_list|)
return|;
block|}
end_decl_stmt

begin_define
define|#
directive|define
name|_mm_blend_epi16
parameter_list|(
name|V1
parameter_list|,
name|V2
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   __m128i __V1 = (V1); \   __m128i __V2 = (V2); \   (__m128i) __builtin_ia32_pblendw128 ((__v8hi)__V1, (__v8hi)__V2, (M)); })
end_define

begin_comment
comment|/* SSE4 Dword Multiply Instructions.  */
end_comment

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_mullo_epi32
argument_list|(
name|__m128i
name|__V1
argument_list|,
name|__m128i
name|__V2
argument_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v4si
operator|)
name|__V1
operator|*
operator|(
name|__v4si
operator|)
name|__V2
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_mul_epi32
argument_list|(
name|__m128i
name|__V1
argument_list|,
name|__m128i
name|__V2
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmuldq128
argument_list|(
operator|(
name|__v4si
operator|)
name|__V1
argument_list|,
operator|(
name|__v4si
operator|)
name|__V2
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/* SSE4 Floating Point Dot Product Instructions.  */
end_comment

begin_define
define|#
directive|define
name|_mm_dp_ps
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   __m128 __X = (X); \   __m128 __Y = (Y); \   (__m128) __builtin_ia32_dpps((__v4sf)__X, (__v4sf)__Y, (M)); })
end_define

begin_define
define|#
directive|define
name|_mm_dp_pd
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({\   __m128d __X = (X); \   __m128d __Y = (Y); \   (__m128d) __builtin_ia32_dppd((__v2df)__X, (__v2df)__Y, (M)); })
end_define

begin_comment
comment|/* SSE4 Streaming Load Hint Instruction.  */
end_comment

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_stream_load_si128
argument_list|(
name|__m128i
operator|*
name|__V
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_movntdqa
argument_list|(
operator|(
name|__v2di
operator|*
operator|)
name|__V
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/* SSE4 Packed Integer Min/Max Instructions.  */
end_comment

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_min_epi8
argument_list|(
name|__m128i
name|__V1
argument_list|,
name|__m128i
name|__V2
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pminsb128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__V1
argument_list|,
operator|(
name|__v16qi
operator|)
name|__V2
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_max_epi8
argument_list|(
name|__m128i
name|__V1
argument_list|,
name|__m128i
name|__V2
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmaxsb128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__V1
argument_list|,
operator|(
name|__v16qi
operator|)
name|__V2
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_min_epu16
argument_list|(
name|__m128i
name|__V1
argument_list|,
name|__m128i
name|__V2
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pminuw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__V1
argument_list|,
operator|(
name|__v8hi
operator|)
name|__V2
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_max_epu16
argument_list|(
name|__m128i
name|__V1
argument_list|,
name|__m128i
name|__V2
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmaxuw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__V1
argument_list|,
operator|(
name|__v8hi
operator|)
name|__V2
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_min_epi32
argument_list|(
name|__m128i
name|__V1
argument_list|,
name|__m128i
name|__V2
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pminsd128
argument_list|(
operator|(
name|__v4si
operator|)
name|__V1
argument_list|,
operator|(
name|__v4si
operator|)
name|__V2
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_max_epi32
argument_list|(
name|__m128i
name|__V1
argument_list|,
name|__m128i
name|__V2
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmaxsd128
argument_list|(
operator|(
name|__v4si
operator|)
name|__V1
argument_list|,
operator|(
name|__v4si
operator|)
name|__V2
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_min_epu32
argument_list|(
name|__m128i
name|__V1
argument_list|,
name|__m128i
name|__V2
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pminud128
argument_list|(
operator|(
name|__v4si
operator|)
name|__V1
argument_list|,
operator|(
name|__v4si
operator|)
name|__V2
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_max_epu32
argument_list|(
name|__m128i
name|__V1
argument_list|,
name|__m128i
name|__V2
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmaxud128
argument_list|(
operator|(
name|__v4si
operator|)
name|__V1
argument_list|,
operator|(
name|__v4si
operator|)
name|__V2
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/* SSE4 Insertion and Extraction from XMM Register Instructions.  */
end_comment

begin_define
define|#
directive|define
name|_mm_insert_ps
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|N
parameter_list|)
value|__builtin_ia32_insertps128((X), (Y), (N))
end_define

begin_define
define|#
directive|define
name|_mm_extract_ps
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
value|(__extension__                      \                               ({ union { int __i; float __f; } __t;  \                                  __v4sf __a = (__v4sf)(X);       \                                  __t.__f = __a[(N)& 3];                 \                                  __t.__i;}))
end_define

begin_comment
comment|/* Miscellaneous insert and extract macros.  */
end_comment

begin_comment
comment|/* Extract a single-precision float from X at index N into D.  */
end_comment

begin_define
define|#
directive|define
name|_MM_EXTRACT_FLOAT
parameter_list|(
name|D
parameter_list|,
name|X
parameter_list|,
name|N
parameter_list|)
value|(__extension__ ({ __v4sf __a = (__v4sf)(X); \                                                     (D) = __a[N]; }))
end_define

begin_comment
comment|/* Or together 2 sets of indexes (X and Y) with the zeroing bits (Z) to create    an index suitable for _mm_insert_ps.  */
end_comment

begin_define
define|#
directive|define
name|_MM_MK_INSERTPS_NDX
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|Z
parameter_list|)
value|(((X)<< 6) | ((Y)<< 4) | (Z))
end_define

begin_comment
comment|/* Extract a float from X at index N into the first index of the return.  */
end_comment

begin_define
define|#
directive|define
name|_MM_PICK_OUT_PS
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
value|_mm_insert_ps (_mm_setzero_ps(), (X),   \                                              _MM_MK_INSERTPS_NDX((N), 0, 0x0e))
end_define

begin_comment
comment|/* Insert int into packed integer array at index.  */
end_comment

begin_define
define|#
directive|define
name|_mm_insert_epi8
parameter_list|(
name|X
parameter_list|,
name|I
parameter_list|,
name|N
parameter_list|)
value|(__extension__ ({ __v16qi __a = (__v16qi)(X); \                                                    __a[(N)& 15] = (I);             \                                                    __a;}))
end_define

begin_define
define|#
directive|define
name|_mm_insert_epi32
parameter_list|(
name|X
parameter_list|,
name|I
parameter_list|,
name|N
parameter_list|)
value|(__extension__ ({ __v4si __a = (__v4si)(X); \                                                     __a[(N)& 3] = (I);           \                                                     __a;}))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_define
define|#
directive|define
name|_mm_insert_epi64
parameter_list|(
name|X
parameter_list|,
name|I
parameter_list|,
name|N
parameter_list|)
value|(__extension__ ({ __v2di __a = (__v2di)(X); \                                                     __a[(N)& 1] = (I);           \                                                     __a;}))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __x86_64__ */
end_comment

begin_comment
comment|/* Extract int from packed integer array at index.  This returns the element  * as a zero extended value, so it is unsigned.  */
end_comment

begin_define
define|#
directive|define
name|_mm_extract_epi8
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
value|(__extension__ ({ __v16qi __a = (__v16qi)(X); \                                                  (int)(unsigned char) \                                                      __a[(N)& 15];}))
end_define

begin_define
define|#
directive|define
name|_mm_extract_epi32
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
value|(__extension__ ({ __v4si __a = (__v4si)(X); \                                                   __a[(N)& 3];}))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_define
define|#
directive|define
name|_mm_extract_epi64
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
value|(__extension__ ({ __v2di __a = (__v2di)(X); \                                                   __a[(N)& 1];}))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __x86_64 */
end_comment

begin_comment
comment|/* SSE4 128-bit Packed Integer Comparisons.  */
end_comment

begin_decl_stmt
specifier|static
name|__inline__
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_testz_si128
argument_list|(
name|__m128i
name|__M
argument_list|,
name|__m128i
name|__V
argument_list|)
block|{
return|return
name|__builtin_ia32_ptestz128
argument_list|(
operator|(
name|__v2di
operator|)
name|__M
argument_list|,
operator|(
name|__v2di
operator|)
name|__V
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_testc_si128
argument_list|(
name|__m128i
name|__M
argument_list|,
name|__m128i
name|__V
argument_list|)
block|{
return|return
name|__builtin_ia32_ptestc128
argument_list|(
operator|(
name|__v2di
operator|)
name|__M
argument_list|,
operator|(
name|__v2di
operator|)
name|__V
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_testnzc_si128
argument_list|(
name|__m128i
name|__M
argument_list|,
name|__m128i
name|__V
argument_list|)
block|{
return|return
name|__builtin_ia32_ptestnzc128
argument_list|(
operator|(
name|__v2di
operator|)
name|__M
argument_list|,
operator|(
name|__v2di
operator|)
name|__V
argument_list|)
return|;
block|}
end_decl_stmt

begin_define
define|#
directive|define
name|_mm_test_all_ones
parameter_list|(
name|V
parameter_list|)
value|_mm_testc_si128((V), _mm_cmpeq_epi32((V), (V)))
end_define

begin_define
define|#
directive|define
name|_mm_test_mix_ones_zeros
parameter_list|(
name|M
parameter_list|,
name|V
parameter_list|)
value|_mm_testnzc_si128((M), (V))
end_define

begin_define
define|#
directive|define
name|_mm_test_all_zeros
parameter_list|(
name|M
parameter_list|,
name|V
parameter_list|)
value|_mm_testz_si128 ((M), (V))
end_define

begin_comment
comment|/* SSE4 64-bit Packed Integer Comparisons.  */
end_comment

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_cmpeq_epi64
argument_list|(
name|__m128i
name|__V1
argument_list|,
name|__m128i
name|__V2
argument_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v2di
operator|)
name|__V1
operator|==
operator|(
name|__v2di
operator|)
name|__V2
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/* SSE4 Packed Integer Sign-Extension.  */
end_comment

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_cvtepi8_epi16
argument_list|(
name|__m128i
name|__V
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmovsxbw128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__V
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_cvtepi8_epi32
argument_list|(
name|__m128i
name|__V
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmovsxbd128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__V
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_cvtepi8_epi64
argument_list|(
name|__m128i
name|__V
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmovsxbq128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__V
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_cvtepi16_epi32
argument_list|(
name|__m128i
name|__V
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmovsxwd128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__V
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_cvtepi16_epi64
argument_list|(
name|__m128i
name|__V
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmovsxwq128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__V
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_cvtepi32_epi64
argument_list|(
name|__m128i
name|__V
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmovsxdq128
argument_list|(
operator|(
name|__v4si
operator|)
name|__V
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/* SSE4 Packed Integer Zero-Extension.  */
end_comment

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_cvtepu8_epi16
argument_list|(
name|__m128i
name|__V
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmovzxbw128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__V
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_cvtepu8_epi32
argument_list|(
name|__m128i
name|__V
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmovzxbd128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__V
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_cvtepu8_epi64
argument_list|(
name|__m128i
name|__V
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmovzxbq128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__V
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_cvtepu16_epi32
argument_list|(
name|__m128i
name|__V
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmovzxwd128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__V
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_cvtepu16_epi64
argument_list|(
name|__m128i
name|__V
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmovzxwq128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__V
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_cvtepu32_epi64
argument_list|(
name|__m128i
name|__V
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmovzxdq128
argument_list|(
operator|(
name|__v4si
operator|)
name|__V
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/* SSE4 Pack with Unsigned Saturation.  */
end_comment

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_packus_epi32
argument_list|(
name|__m128i
name|__V1
argument_list|,
name|__m128i
name|__V2
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_packusdw128
argument_list|(
operator|(
name|__v4si
operator|)
name|__V1
argument_list|,
operator|(
name|__v4si
operator|)
name|__V2
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/* SSE4 Multiple Packed Sums of Absolute Difference.  */
end_comment

begin_define
define|#
directive|define
name|_mm_mpsadbw_epu8
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|M
parameter_list|)
value|__extension__ ({ \   __m128i __X = (X); \   __m128i __Y = (Y); \   (__m128i) __builtin_ia32_mpsadbw128((__v16qi)__X, (__v16qi)__Y, (M)); })
end_define

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_minpos_epu16
argument_list|(
name|__m128i
name|__V
argument_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_phminposuw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__V
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/* These definitions are normally in nmmintrin.h, but gcc puts them in here    so we'll do the same.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__SSE4_2__
end_ifdef

begin_comment
comment|/* These specify the type of data that we're comparing.  */
end_comment

begin_define
define|#
directive|define
name|_SIDD_UBYTE_OPS
value|0x00
end_define

begin_define
define|#
directive|define
name|_SIDD_UWORD_OPS
value|0x01
end_define

begin_define
define|#
directive|define
name|_SIDD_SBYTE_OPS
value|0x02
end_define

begin_define
define|#
directive|define
name|_SIDD_SWORD_OPS
value|0x03
end_define

begin_comment
comment|/* These specify the type of comparison operation.  */
end_comment

begin_define
define|#
directive|define
name|_SIDD_CMP_EQUAL_ANY
value|0x00
end_define

begin_define
define|#
directive|define
name|_SIDD_CMP_RANGES
value|0x04
end_define

begin_define
define|#
directive|define
name|_SIDD_CMP_EQUAL_EACH
value|0x08
end_define

begin_define
define|#
directive|define
name|_SIDD_CMP_EQUAL_ORDERED
value|0x0c
end_define

begin_comment
comment|/* These macros specify the polarity of the operation.  */
end_comment

begin_define
define|#
directive|define
name|_SIDD_POSITIVE_POLARITY
value|0x00
end_define

begin_define
define|#
directive|define
name|_SIDD_NEGATIVE_POLARITY
value|0x10
end_define

begin_define
define|#
directive|define
name|_SIDD_MASKED_POSITIVE_POLARITY
value|0x20
end_define

begin_define
define|#
directive|define
name|_SIDD_MASKED_NEGATIVE_POLARITY
value|0x30
end_define

begin_comment
comment|/* These macros are used in _mm_cmpXstri() to specify the return.  */
end_comment

begin_define
define|#
directive|define
name|_SIDD_LEAST_SIGNIFICANT
value|0x00
end_define

begin_define
define|#
directive|define
name|_SIDD_MOST_SIGNIFICANT
value|0x40
end_define

begin_comment
comment|/* These macros are used in _mm_cmpXstri() to specify the return.  */
end_comment

begin_define
define|#
directive|define
name|_SIDD_BIT_MASK
value|0x00
end_define

begin_define
define|#
directive|define
name|_SIDD_UNIT_MASK
value|0x40
end_define

begin_comment
comment|/* SSE4.2 Packed Comparison Intrinsics.  */
end_comment

begin_define
define|#
directive|define
name|_mm_cmpistrm
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|M
parameter_list|)
value|__builtin_ia32_pcmpistrm128((A), (B), (M))
end_define

begin_define
define|#
directive|define
name|_mm_cmpistri
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|M
parameter_list|)
value|__builtin_ia32_pcmpistri128((A), (B), (M))
end_define

begin_define
define|#
directive|define
name|_mm_cmpestrm
parameter_list|(
name|A
parameter_list|,
name|LA
parameter_list|,
name|B
parameter_list|,
name|LB
parameter_list|,
name|M
parameter_list|)
define|\
value|__builtin_ia32_pcmpestrm128((A), (LA), (B), (LB), (M))
end_define

begin_define
define|#
directive|define
name|_mm_cmpestri
parameter_list|(
name|A
parameter_list|,
name|LA
parameter_list|,
name|B
parameter_list|,
name|LB
parameter_list|,
name|M
parameter_list|)
define|\
value|__builtin_ia32_pcmpestri128((A), (LA), (B), (LB), (M))
end_define

begin_comment
comment|/* SSE4.2 Packed Comparison Intrinsics and EFlag Reading.  */
end_comment

begin_define
define|#
directive|define
name|_mm_cmpistra
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|M
parameter_list|)
define|\
value|__builtin_ia32_pcmpistria128((A), (B), (M))
end_define

begin_define
define|#
directive|define
name|_mm_cmpistrc
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|M
parameter_list|)
define|\
value|__builtin_ia32_pcmpistric128((A), (B), (M))
end_define

begin_define
define|#
directive|define
name|_mm_cmpistro
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|M
parameter_list|)
define|\
value|__builtin_ia32_pcmpistrio128((A), (B), (M))
end_define

begin_define
define|#
directive|define
name|_mm_cmpistrs
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|M
parameter_list|)
define|\
value|__builtin_ia32_pcmpistris128((A), (B), (M))
end_define

begin_define
define|#
directive|define
name|_mm_cmpistrz
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|M
parameter_list|)
define|\
value|__builtin_ia32_pcmpistriz128((A), (B), (M))
end_define

begin_define
define|#
directive|define
name|_mm_cmpestra
parameter_list|(
name|A
parameter_list|,
name|LA
parameter_list|,
name|B
parameter_list|,
name|LB
parameter_list|,
name|M
parameter_list|)
define|\
value|__builtin_ia32_pcmpestria128((A), (LA), (B), (LB), (M))
end_define

begin_define
define|#
directive|define
name|_mm_cmpestrc
parameter_list|(
name|A
parameter_list|,
name|LA
parameter_list|,
name|B
parameter_list|,
name|LB
parameter_list|,
name|M
parameter_list|)
define|\
value|__builtin_ia32_pcmpestric128((A), (LA), (B), (LB), (M))
end_define

begin_define
define|#
directive|define
name|_mm_cmpestro
parameter_list|(
name|A
parameter_list|,
name|LA
parameter_list|,
name|B
parameter_list|,
name|LB
parameter_list|,
name|M
parameter_list|)
define|\
value|__builtin_ia32_pcmpestrio128((A), (LA), (B), (LB), (M))
end_define

begin_define
define|#
directive|define
name|_mm_cmpestrs
parameter_list|(
name|A
parameter_list|,
name|LA
parameter_list|,
name|B
parameter_list|,
name|LB
parameter_list|,
name|M
parameter_list|)
define|\
value|__builtin_ia32_pcmpestris128((A), (LA), (B), (LB), (M))
end_define

begin_define
define|#
directive|define
name|_mm_cmpestrz
parameter_list|(
name|A
parameter_list|,
name|LA
parameter_list|,
name|B
parameter_list|,
name|LB
parameter_list|,
name|M
parameter_list|)
define|\
value|__builtin_ia32_pcmpestriz128((A), (LA), (B), (LB), (M))
end_define

begin_comment
comment|/* SSE4.2 Compare Packed Data -- Greater Than.  */
end_comment

begin_decl_stmt
specifier|static
name|__inline__
name|__m128i
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_cmpgt_epi64
argument_list|(
name|__m128i
name|__V1
argument_list|,
name|__m128i
name|__V2
argument_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v2di
operator|)
name|__V1
operator|>
operator|(
name|__v2di
operator|)
name|__V2
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/* SSE4.2 Accumulate CRC32.  */
end_comment

begin_decl_stmt
specifier|static
name|__inline__
name|unsigned
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_crc32_u8
argument_list|(
name|unsigned
name|int
name|__C
argument_list|,
name|unsigned
name|char
name|__D
argument_list|)
block|{
return|return
name|__builtin_ia32_crc32qi
argument_list|(
name|__C
argument_list|,
name|__D
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|unsigned
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_crc32_u16
argument_list|(
name|unsigned
name|int
name|__C
argument_list|,
name|unsigned
name|short
name|__D
argument_list|)
block|{
return|return
name|__builtin_ia32_crc32hi
argument_list|(
name|__C
argument_list|,
name|__D
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|unsigned
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_crc32_u32
argument_list|(
name|unsigned
name|int
name|__C
argument_list|,
name|unsigned
name|int
name|__D
argument_list|)
block|{
return|return
name|__builtin_ia32_crc32si
argument_list|(
name|__C
argument_list|,
name|__D
argument_list|)
return|;
block|}
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_decl_stmt
specifier|static
name|__inline__
name|unsigned
name|long
name|long
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_crc32_u64
argument_list|(
name|unsigned
name|long
name|long
name|__C
argument_list|,
name|unsigned
name|long
name|long
name|__D
argument_list|)
block|{
return|return
name|__builtin_ia32_crc32di
argument_list|(
name|__C
argument_list|,
name|__D
argument_list|)
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __x86_64__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__POPCNT__
end_ifdef

begin_include
include|#
directive|include
file|<popcntintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SSE4_2__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SSE4_1__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SMMINTRIN_H */
end_comment

end_unit

