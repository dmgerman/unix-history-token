begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===--------------------------- float.h ----------------------------------===//
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
name|_LIBCPP_FLOAT_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_FLOAT_H
end_define

begin_comment
comment|/*     float.h synopsis  Macros:      FLT_ROUNDS     FLT_EVAL_METHOD     // C99     FLT_RADIX      FLT_MANT_DIG     DBL_MANT_DIG     LDBL_MANT_DIG      DECIMAL_DIG         // C99      FLT_DIG     DBL_DIG     LDBL_DIG      FLT_MIN_EXP     DBL_MIN_EXP     LDBL_MIN_EXP      FLT_MIN_10_EXP     DBL_MIN_10_EXP     LDBL_MIN_10_EXP      FLT_MAX_EXP     DBL_MAX_EXP     LDBL_MAX_EXP      FLT_MAX_10_EXP     DBL_MAX_10_EXP     LDBL_MAX_10_EXP      FLT_MAX     DBL_MAX     LDBL_MAX      FLT_EPSILON     DBL_EPSILON     LDBL_EPSILON      FLT_MIN     DBL_MIN     LDBL_MIN  */
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

begin_empty
empty|#include_next<float.h>
end_empty

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|FLT_EVAL_METHOD
end_ifndef

begin_define
define|#
directive|define
name|FLT_EVAL_METHOD
value|__FLT_EVAL_METHOD__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DECIMAL_DIG
end_ifndef

begin_define
define|#
directive|define
name|DECIMAL_DIG
value|__DECIMAL_DIG__
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
comment|// __cplusplus
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_FLOAT_H
end_comment

end_unit

