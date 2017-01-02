begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===---------------------------- stdint.h --------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBCPP_STDINT_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_STDINT_H
end_define

begin_comment
comment|/*     stdint.h synopsis  Macros:      INT8_MIN     INT16_MIN     INT32_MIN     INT64_MIN      INT8_MAX     INT16_MAX     INT32_MAX     INT64_MAX      UINT8_MAX     UINT16_MAX     UINT32_MAX     UINT64_MAX      INT_LEAST8_MIN     INT_LEAST16_MIN     INT_LEAST32_MIN     INT_LEAST64_MIN      INT_LEAST8_MAX     INT_LEAST16_MAX     INT_LEAST32_MAX     INT_LEAST64_MAX      UINT_LEAST8_MAX     UINT_LEAST16_MAX     UINT_LEAST32_MAX     UINT_LEAST64_MAX      INT_FAST8_MIN     INT_FAST16_MIN     INT_FAST32_MIN     INT_FAST64_MIN      INT_FAST8_MAX     INT_FAST16_MAX     INT_FAST32_MAX     INT_FAST64_MAX      UINT_FAST8_MAX     UINT_FAST16_MAX     UINT_FAST32_MAX     UINT_FAST64_MAX      INTPTR_MIN     INTPTR_MAX     UINTPTR_MAX      INTMAX_MIN     INTMAX_MAX      UINTMAX_MAX      PTRDIFF_MIN     PTRDIFF_MAX      SIG_ATOMIC_MIN     SIG_ATOMIC_MAX      SIZE_MAX      WCHAR_MIN     WCHAR_MAX      WINT_MIN     WINT_MAX      INT8_C(value)     INT16_C(value)     INT32_C(value)     INT64_C(value)      UINT8_C(value)     UINT16_C(value)     UINT32_C(value)     UINT64_C(value)      INTMAX_C(value)     UINTMAX_C(value)  */
end_comment

begin_include
include|#
directive|include
file|<__config>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* C99 stdlib (e.g. glibc< 2.18) does not provide macros needed    for C++11 unless __STDC_LIMIT_MACROS and __STDC_CONSTANT_MACROS    are defined */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STDC_LIMIT_MACROS
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STDC_LIMIT_MACROS
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
name|__cplusplus
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STDC_CONSTANT_MACROS
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STDC_CONSTANT_MACROS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_empty
empty|#include_next<stdint.h>
end_empty

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_STDINT_H
end_comment

end_unit

