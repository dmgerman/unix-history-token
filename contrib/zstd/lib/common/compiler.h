begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016-present, Yann Collet, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under both the BSD-style license (found in the  * LICENSE file in the root directory of this source tree) and the GPLv2 (found  * in the COPYING file in the root directory of this source tree).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ZSTD_COMPILER_H
end_ifndef

begin_define
define|#
directive|define
name|ZSTD_COMPILER_H
end_define

begin_comment
comment|/*-******************************************************* *  Compiler specifics *********************************************************/
end_comment

begin_comment
comment|/* force inlining */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|__STDC_VERSION__
argument_list|)
operator|&&
name|__STDC_VERSION__
operator|>=
literal|199901L
end_if

begin_comment
comment|/* C99 */
end_comment

begin_define
define|#
directive|define
name|INLINE_KEYWORD
value|inline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INLINE_KEYWORD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|FORCE_INLINE_ATTR
value|__attribute__((always_inline))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_define
define|#
directive|define
name|FORCE_INLINE_ATTR
value|__forceinline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FORCE_INLINE_ATTR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * FORCE_INLINE_TEMPLATE is used to define C "templates", which take constant  * parameters. They must be inlined for the compiler to elimininate the constant  * branches.  */
end_comment

begin_define
define|#
directive|define
name|FORCE_INLINE_TEMPLATE
value|static INLINE_KEYWORD FORCE_INLINE_ATTR
end_define

begin_comment
comment|/**  * HINT_INLINE is used to help the compiler generate better code. It is *not*  * used for "templates", so it can be tweaked based on the compilers  * performance.  *  * gcc-4.8 and gcc-4.9 have been shown to benefit from leaving off the  * always_inline attribute.  *  * clang up to 5.0.0 (trunk) benefit tremendously from the always_inline  * attribute.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__clang__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|__GNUC__
operator|>=
literal|4
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|8
operator|&&
name|__GNUC__
operator|<
literal|5
end_if

begin_define
define|#
directive|define
name|HINT_INLINE
value|static INLINE_KEYWORD
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HINT_INLINE
value|static INLINE_KEYWORD FORCE_INLINE_ATTR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* force no inlining */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_define
define|#
directive|define
name|FORCE_NOINLINE
value|static __declspec(noinline)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|FORCE_NOINLINE
value|static __attribute__((__noinline__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FORCE_NOINLINE
value|static
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* prefetch */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|_M_X64
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_I86
argument_list|)
operator|)
end_if

begin_comment
comment|/* _mm_prefetch() is not defined outside of x86/x64 */
end_comment

begin_include
include|#
directive|include
file|<mmintrin.h>
end_include

begin_comment
comment|/* https://msdn.microsoft.com/fr-fr/library/84szxsww(v=vs.90).aspx */
end_comment

begin_define
define|#
directive|define
name|PREFETCH
parameter_list|(
name|ptr
parameter_list|)
value|_mm_prefetch((const char*)ptr, _MM_HINT_T0)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|PREFETCH
parameter_list|(
name|ptr
parameter_list|)
value|__builtin_prefetch(ptr, 0, 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PREFETCH
parameter_list|(
name|ptr
parameter_list|)
end_define

begin_comment
comment|/* disabled */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* disable warnings */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_comment
comment|/* Visual Studio */
end_comment

begin_include
include|#
directive|include
file|<intrin.h>
end_include

begin_comment
comment|/* For Visual 2005 */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4100
name|)
end_pragma

begin_comment
comment|/* disable: C4100: unreferenced formal parameter */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4127
name|)
end_pragma

begin_comment
comment|/* disable: C4127: conditional expression is constant */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4204
name|)
end_pragma

begin_comment
comment|/* disable: C4204: non-constant aggregate initializer */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4214
name|)
end_pragma

begin_comment
comment|/* disable: C4214: non-int bitfields */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4324
name|)
end_pragma

begin_comment
comment|/* disable: C4324: padded structure */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ZSTD_COMPILER_H */
end_comment

end_unit

