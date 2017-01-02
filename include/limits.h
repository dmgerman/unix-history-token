begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===--------------------------- limits.h ---------------------------------===//
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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
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
name|_LIBCPP_LIMITS_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_LIMITS_H
end_define

begin_comment
comment|/*     limits.h synopsis  Macros:      CHAR_BIT     SCHAR_MIN     SCHAR_MAX     UCHAR_MAX     CHAR_MIN     CHAR_MAX     MB_LEN_MAX     SHRT_MIN     SHRT_MAX     USHRT_MAX     INT_MIN     INT_MAX     UINT_MAX     LONG_MIN     LONG_MAX     ULONG_MAX     LLONG_MIN   // C99     LLONG_MAX   // C99     ULLONG_MAX  // C99  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_empty
empty|#include_next<limits.h>
end_empty

begin_else
else|#
directive|else
end_else

begin_comment
comment|// GCC header limits.h recursively includes itself through another header called
end_comment

begin_comment
comment|// syslimits.h for some reason. This setup breaks down if we directly
end_comment

begin_comment
comment|// #include_next GCC's limits.h (reasons not entirely clear to me). Therefore,
end_comment

begin_comment
comment|// we manually re-create the necessary include sequence below:
end_comment

begin_comment
comment|// Get the system limits.h defines (force recurse into the next level)
end_comment

begin_define
define|#
directive|define
name|_GCC_LIMITS_H_
end_define

begin_define
define|#
directive|define
name|_GCC_NEXT_LIMITS_H
end_define

begin_empty
empty|#include_next<limits.h>
end_empty

begin_comment
comment|// Get the ISO C defines
end_comment

begin_undef
undef|#
directive|undef
name|_GCC_LIMITS_H_
end_undef

begin_empty
empty|#include_next<limits.h>
end_empty

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __GNUC__
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_LIMITS_H
end_comment

end_unit

