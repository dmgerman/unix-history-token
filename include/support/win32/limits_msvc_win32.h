begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===------------------ support/win32/limits_msvc_win32.h -----------------===//
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
name|_LIBCPP_SUPPORT_WIN32_LIMITS_MSVC_WIN32_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_SUPPORT_WIN32_LIMITS_MSVC_WIN32_H
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_LIBCPP_MSVCRT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"This header complements the Microsoft C Runtime library, and should not be included otherwise."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__clang__
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"This header should only be included when using Microsofts C1XX frontend"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_comment
comment|// CHAR_BIT
end_comment

begin_include
include|#
directive|include
file|<float.h>
end_include

begin_comment
comment|// limit constants
end_comment

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_comment
comment|// HUGE_VAL
end_comment

begin_include
include|#
directive|include
file|<ymath.h>
end_include

begin_comment
comment|// internal MSVC header providing the needed functionality
end_comment

begin_define
define|#
directive|define
name|__CHAR_BIT__
value|CHAR_BIT
end_define

begin_define
define|#
directive|define
name|__FLT_MANT_DIG__
value|FLT_MANT_DIG
end_define

begin_define
define|#
directive|define
name|__FLT_DIG__
value|FLT_DIG
end_define

begin_define
define|#
directive|define
name|__FLT_RADIX__
value|FLT_RADIX
end_define

begin_define
define|#
directive|define
name|__FLT_MIN_EXP__
value|FLT_MIN_EXP
end_define

begin_define
define|#
directive|define
name|__FLT_MIN_10_EXP__
value|FLT_MIN_10_EXP
end_define

begin_define
define|#
directive|define
name|__FLT_MAX_EXP__
value|FLT_MAX_EXP
end_define

begin_define
define|#
directive|define
name|__FLT_MAX_10_EXP__
value|FLT_MAX_10_EXP
end_define

begin_define
define|#
directive|define
name|__FLT_MIN__
value|FLT_MIN
end_define

begin_define
define|#
directive|define
name|__FLT_MAX__
value|FLT_MAX
end_define

begin_define
define|#
directive|define
name|__FLT_EPSILON__
value|FLT_EPSILON
end_define

begin_comment
comment|// predefined by MinGW GCC
end_comment

begin_define
define|#
directive|define
name|__FLT_DENORM_MIN__
value|1.40129846432481707092e-45F
end_define

begin_define
define|#
directive|define
name|__DBL_MANT_DIG__
value|DBL_MANT_DIG
end_define

begin_define
define|#
directive|define
name|__DBL_DIG__
value|DBL_DIG
end_define

begin_define
define|#
directive|define
name|__DBL_RADIX__
value|DBL_RADIX
end_define

begin_define
define|#
directive|define
name|__DBL_MIN_EXP__
value|DBL_MIN_EXP
end_define

begin_define
define|#
directive|define
name|__DBL_MIN_10_EXP__
value|DBL_MIN_10_EXP
end_define

begin_define
define|#
directive|define
name|__DBL_MAX_EXP__
value|DBL_MAX_EXP
end_define

begin_define
define|#
directive|define
name|__DBL_MAX_10_EXP__
value|DBL_MAX_10_EXP
end_define

begin_define
define|#
directive|define
name|__DBL_MIN__
value|DBL_MIN
end_define

begin_define
define|#
directive|define
name|__DBL_MAX__
value|DBL_MAX
end_define

begin_define
define|#
directive|define
name|__DBL_EPSILON__
value|DBL_EPSILON
end_define

begin_comment
comment|// predefined by MinGW GCC
end_comment

begin_define
define|#
directive|define
name|__DBL_DENORM_MIN__
value|double(4.94065645841246544177e-324L)
end_define

begin_define
define|#
directive|define
name|__LDBL_MANT_DIG__
value|LDBL_MANT_DIG
end_define

begin_define
define|#
directive|define
name|__LDBL_DIG__
value|LDBL_DIG
end_define

begin_define
define|#
directive|define
name|__LDBL_RADIX__
value|LDBL_RADIX
end_define

begin_define
define|#
directive|define
name|__LDBL_MIN_EXP__
value|LDBL_MIN_EXP
end_define

begin_define
define|#
directive|define
name|__LDBL_MIN_10_EXP__
value|LDBL_MIN_10_EXP
end_define

begin_define
define|#
directive|define
name|__LDBL_MAX_EXP__
value|LDBL_MAX_EXP
end_define

begin_define
define|#
directive|define
name|__LDBL_MAX_10_EXP__
value|LDBL_MAX_10_EXP
end_define

begin_define
define|#
directive|define
name|__LDBL_MIN__
value|LDBL_MIN
end_define

begin_define
define|#
directive|define
name|__LDBL_MAX__
value|LDBL_MAX
end_define

begin_define
define|#
directive|define
name|__LDBL_EPSILON__
value|LDBL_EPSILON
end_define

begin_comment
comment|// predefined by MinGW GCC
end_comment

begin_define
define|#
directive|define
name|__LDBL_DENORM_MIN__
value|3.64519953188247460253e-4951L
end_define

begin_comment
comment|// __builtin replacements/workarounds
end_comment

begin_define
define|#
directive|define
name|__builtin_huge_vall
parameter_list|()
value|_LInf._Long_double
end_define

begin_define
define|#
directive|define
name|__builtin_nanl
parameter_list|(
name|__dummmy
parameter_list|)
value|_LNan._Long_double
end_define

begin_define
define|#
directive|define
name|__builtin_nansl
parameter_list|(
name|__dummy
parameter_list|)
value|_LSnan._Long_double
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_SUPPORT_WIN32_LIMITS_MSVC_WIN32_H
end_comment

end_unit

