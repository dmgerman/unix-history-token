begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -ffreestanding %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -ffreestanding -fno-lax-vector-conversions %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -ffreestanding -x c++ %s -verify
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_comment
comment|// Pretend to enable all features.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__3dNOW__
end_ifndef

begin_define
define|#
directive|define
name|__3dNOW__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__BMI__
end_ifndef

begin_define
define|#
directive|define
name|__BMI__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__BMI2__
end_ifndef

begin_define
define|#
directive|define
name|__BMI2__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__LZCNT__
end_ifndef

begin_define
define|#
directive|define
name|__LZCNT__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__POPCNT__
end_ifndef

begin_define
define|#
directive|define
name|__POPCNT__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__RDSEED__
end_ifndef

begin_define
define|#
directive|define
name|__RDSEED__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__PRFCHW__
end_ifndef

begin_define
define|#
directive|define
name|__PRFCHW__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__SSE4A__
end_ifndef

begin_define
define|#
directive|define
name|__SSE4A__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__FMA4__
end_ifndef

begin_define
define|#
directive|define
name|__FMA4__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__XOP__
end_ifndef

begin_define
define|#
directive|define
name|__XOP__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__F16C__
end_ifndef

begin_define
define|#
directive|define
name|__F16C__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__MMX__
end_ifndef

begin_define
define|#
directive|define
name|__MMX__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__SSE__
end_ifndef

begin_define
define|#
directive|define
name|__SSE__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__SSE2__
end_ifndef

begin_define
define|#
directive|define
name|__SSE2__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__SSE3__
end_ifndef

begin_define
define|#
directive|define
name|__SSE3__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__SSSE3__
end_ifndef

begin_define
define|#
directive|define
name|__SSSE3__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__SSE4_1__
end_ifndef

begin_define
define|#
directive|define
name|__SSE4_1__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__SSE4_2__
end_ifndef

begin_define
define|#
directive|define
name|__SSE4_2__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__AES__
end_ifndef

begin_define
define|#
directive|define
name|__AES__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__AVX__
end_ifndef

begin_define
define|#
directive|define
name|__AVX__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__AVX2__
end_ifndef

begin_define
define|#
directive|define
name|__AVX2__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__BMI__
end_ifndef

begin_define
define|#
directive|define
name|__BMI__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__BMI2__
end_ifndef

begin_define
define|#
directive|define
name|__BMI2__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__LZCNT__
end_ifndef

begin_define
define|#
directive|define
name|__LZCNT__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__FMA__
end_ifndef

begin_define
define|#
directive|define
name|__FMA__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__RDRND__
end_ifndef

begin_define
define|#
directive|define
name|__RDRND__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__SHA__
end_ifndef

begin_define
define|#
directive|define
name|__SHA__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__ADX__
end_ifndef

begin_define
define|#
directive|define
name|__ADX__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__TBM__
end_ifndef

begin_define
define|#
directive|define
name|__TBM__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__RTM__
end_ifndef

begin_define
define|#
directive|define
name|__RTM__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__PCLMUL__
end_ifndef

begin_define
define|#
directive|define
name|__PCLMUL__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__FSGSBASE__
end_ifndef

begin_define
define|#
directive|define
name|__FSGSBASE__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__AVX512F__
end_ifndef

begin_define
define|#
directive|define
name|__AVX512F__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__AVX512VL__
end_ifndef

begin_define
define|#
directive|define
name|__AVX512VL__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__AVX512BW__
end_ifndef

begin_define
define|#
directive|define
name|__AVX512BW__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__AVX512ER__
end_ifndef

begin_define
define|#
directive|define
name|__AVX512ER__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__AVX512PF__
end_ifndef

begin_define
define|#
directive|define
name|__AVX512PF__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__AVX512DQ__
end_ifndef

begin_define
define|#
directive|define
name|__AVX512DQ__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__AVX512CD__
end_ifndef

begin_define
define|#
directive|define
name|__AVX512CD__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Now include the metaheader that includes all x86 intrinsic headers.
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

