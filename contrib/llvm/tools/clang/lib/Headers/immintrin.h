begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- immintrin.h - Intel intrinsics -----------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IMMINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__IMMINTRIN_H
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__MMX__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<mmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__SSE__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<xmmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__SSE2__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<emmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__SSE3__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<pmmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__SSSE3__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<tmmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__SSE4_2__
argument_list|)
operator|||
name|defined
argument_list|(
name|__SSE4_1__
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|<smmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__AES__
argument_list|)
operator|||
name|defined
argument_list|(
name|__PCLMUL__
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|<wmmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__CLFLUSHOPT__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<clflushoptintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__AVX__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<avxintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__AVX2__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<avx2intrin.h>
end_include

begin_comment
comment|/* The 256-bit versions of functions in f16cintrin.h.    Intel documents these as being in immintrin.h, and    they depend on typedefs from avxintrin.h. */
end_comment

begin_comment
comment|/// \brief Converts a 256-bit vector of [8 x float] into a 128-bit vector
end_comment

begin_comment
comment|///    containing 16-bit half-precision float values.
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
comment|/// __m128i _mm256_cvtps_ph(__m256 a, const int imm);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the<c> VCVTPS2PH</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param a
end_comment

begin_comment
comment|///    A 256-bit vector containing 32-bit single-precision float values to be
end_comment

begin_comment
comment|///    converted to 16-bit half-precision float values.
end_comment

begin_comment
comment|/// \param imm
end_comment

begin_comment
comment|///    An immediate value controlling rounding using bits [2:0]: \n
end_comment

begin_comment
comment|///    000: Nearest \n
end_comment

begin_comment
comment|///    001: Down \n
end_comment

begin_comment
comment|///    010: Up \n
end_comment

begin_comment
comment|///    011: Truncate \n
end_comment

begin_comment
comment|///    1XX: Use MXCSR.RC for rounding
end_comment

begin_comment
comment|/// \returns A 128-bit vector containing the converted 16-bit half-precision
end_comment

begin_comment
comment|///    float values.
end_comment

begin_define
define|#
directive|define
name|_mm256_cvtps_ph
parameter_list|(
name|a
parameter_list|,
name|imm
parameter_list|)
value|__extension__ ({ \  (__m128i)__builtin_ia32_vcvtps2ph256((__v8sf)(__m256)(a), (imm)); })
end_define

begin_comment
comment|/// \brief Converts a 128-bit vector containing 16-bit half-precision float
end_comment

begin_comment
comment|///    values into a 256-bit vector of [8 x float].
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
comment|/// This intrinsic corresponds to the<c> VCVTPH2PS</c> instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector containing 16-bit half-precision float values to be
end_comment

begin_comment
comment|///    converted to 32-bit single-precision float values.
end_comment

begin_comment
comment|/// \returns A vector of [8 x float] containing the converted 32-bit
end_comment

begin_comment
comment|///    single-precision float values.
end_comment

begin_decl_stmt
specifier|static
name|__inline
name|__m256
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|,
name|__target__
argument_list|(
literal|"f16c"
argument_list|)
operator|)
argument_list|)
name|_mm256_cvtph_ps
argument_list|(
name|__m128i
name|__a
argument_list|)
block|{
return|return
operator|(
name|__m256
operator|)
name|__builtin_ia32_vcvtph2ps256
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|)
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AVX2__ */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__BMI__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<bmiintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__BMI2__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<bmi2intrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__LZCNT__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<lzcntintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__FMA__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<fmaintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__AVX512F__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<avx512fintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__AVX512VL__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<avx512vlintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__AVX512BW__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<avx512bwintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__AVX512CD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<avx512cdintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__AVX512VPOPCNTDQ__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<avx512vpopcntdqintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__AVX512DQ__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<avx512dqintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__AVX512VL__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__AVX512BW__
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|<avx512vlbwintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__AVX512VL__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__AVX512CD__
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|<avx512vlcdintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__AVX512VL__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__AVX512DQ__
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|<avx512vldqintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__AVX512ER__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<avx512erintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__AVX512IFMA__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<avx512ifmaintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__AVX512IFMA__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__AVX512VL__
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|<avx512ifmavlintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__AVX512VBMI__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<avx512vbmiintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__AVX512VBMI__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__AVX512VL__
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|<avx512vbmivlintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__AVX512PF__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<avx512pfintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__PKU__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<pkuintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__RDRND__
argument_list|)
end_if

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
operator|,
name|__target__
argument_list|(
literal|"rdrnd"
argument_list|)
operator|)
argument_list|)
name|_rdrand16_step
argument_list|(
name|unsigned
name|short
operator|*
name|__p
argument_list|)
block|{
return|return
name|__builtin_ia32_rdrand16_step
argument_list|(
name|__p
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
operator|,
name|__target__
argument_list|(
literal|"rdrnd"
argument_list|)
operator|)
argument_list|)
name|_rdrand32_step
argument_list|(
name|unsigned
name|int
operator|*
name|__p
argument_list|)
block|{
return|return
name|__builtin_ia32_rdrand32_step
argument_list|(
name|__p
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
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|,
name|__target__
argument_list|(
literal|"rdrnd"
argument_list|)
operator|)
argument_list|)
name|_rdrand64_step
argument_list|(
name|unsigned
name|long
name|long
operator|*
name|__p
argument_list|)
block|{
return|return
name|__builtin_ia32_rdrand64_step
argument_list|(
name|__p
argument_list|)
return|;
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
comment|/* __RDRND__ */
end_comment

begin_comment
comment|/* __bit_scan_forward */
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
name|_bit_scan_forward
argument_list|(
name|int
name|__A
argument_list|)
block|{
return|return
name|__builtin_ctz
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/* __bit_scan_reverse */
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
name|_bit_scan_reverse
argument_list|(
name|int
name|__A
argument_list|)
block|{
return|return
literal|31
operator|-
name|__builtin_clz
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__FSGSBASE__
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

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
operator|,
name|__target__
argument_list|(
literal|"fsgsbase"
argument_list|)
operator|)
argument_list|)
name|_readfsbase_u32
argument_list|(
name|void
argument_list|)
block|{
return|return
name|__builtin_ia32_rdfsbase32
argument_list|()
return|;
block|}
end_decl_stmt

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
operator|,
name|__target__
argument_list|(
literal|"fsgsbase"
argument_list|)
operator|)
argument_list|)
name|_readfsbase_u64
argument_list|(
name|void
argument_list|)
block|{
return|return
name|__builtin_ia32_rdfsbase64
argument_list|()
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
operator|,
name|__target__
argument_list|(
literal|"fsgsbase"
argument_list|)
operator|)
argument_list|)
name|_readgsbase_u32
argument_list|(
name|void
argument_list|)
block|{
return|return
name|__builtin_ia32_rdgsbase32
argument_list|()
return|;
block|}
end_decl_stmt

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
operator|,
name|__target__
argument_list|(
literal|"fsgsbase"
argument_list|)
operator|)
argument_list|)
name|_readgsbase_u64
argument_list|(
name|void
argument_list|)
block|{
return|return
name|__builtin_ia32_rdgsbase64
argument_list|()
return|;
block|}
end_decl_stmt

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
operator|,
name|__target__
argument_list|(
literal|"fsgsbase"
argument_list|)
operator|)
argument_list|)
name|_writefsbase_u32
argument_list|(
name|unsigned
name|int
name|__V
argument_list|)
block|{
return|return
name|__builtin_ia32_wrfsbase32
argument_list|(
name|__V
argument_list|)
return|;
block|}
end_decl_stmt

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
operator|,
name|__target__
argument_list|(
literal|"fsgsbase"
argument_list|)
operator|)
argument_list|)
name|_writefsbase_u64
argument_list|(
name|unsigned
name|long
name|long
name|__V
argument_list|)
block|{
return|return
name|__builtin_ia32_wrfsbase64
argument_list|(
name|__V
argument_list|)
return|;
block|}
end_decl_stmt

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
operator|,
name|__target__
argument_list|(
literal|"fsgsbase"
argument_list|)
operator|)
argument_list|)
name|_writegsbase_u32
argument_list|(
name|unsigned
name|int
name|__V
argument_list|)
block|{
return|return
name|__builtin_ia32_wrgsbase32
argument_list|(
name|__V
argument_list|)
return|;
block|}
end_decl_stmt

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
operator|,
name|__target__
argument_list|(
literal|"fsgsbase"
argument_list|)
operator|)
argument_list|)
name|_writegsbase_u64
argument_list|(
name|unsigned
name|long
name|long
name|__V
argument_list|)
block|{
return|return
name|__builtin_ia32_wrgsbase64
argument_list|(
name|__V
argument_list|)
return|;
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
comment|/* __FSGSBASE__ */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__RTM__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<rtmintrin.h>
end_include

begin_include
include|#
directive|include
file|<xtestintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__SHA__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<shaintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__FXSR__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<fxsrintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__XSAVE__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<xsaveintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__XSAVEOPT__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<xsaveoptintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__XSAVEC__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<xsavecintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
operator|||
name|defined
argument_list|(
name|__XSAVES__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<xsavesintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some intrinsics inside adxintrin.h are available only on processors with ADX,  * whereas others are also available at all times. */
end_comment

begin_include
include|#
directive|include
file|<adxintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IMMINTRIN_H */
end_comment

end_unit

