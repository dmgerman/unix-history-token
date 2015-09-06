begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===--------------------- support/ibm/limits.h ---------------------------===//
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
name|_LIBCPP_SUPPORT_IBM_LIMITS_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_SUPPORT_IBM_LIMITS_H
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_AIX
argument_list|)
end_if

begin_comment
comment|// Linux
end_comment

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_comment
comment|// for HUGE_VAL, HUGE_VALF, HUGE_VALL, and NAN
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|int
name|_QNAN_F
init|=
literal|0x7fc00000
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NANF
value|(*((float *)(&_QNAN_F)))
end_define

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|int
name|_QNAN_LDBL128
index|[
literal|4
index|]
init|=
block|{
literal|0x7ff80000
block|,
literal|0x0
block|,
literal|0x0
block|,
literal|0x0
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NANL
value|(*((long double *)(&_QNAN_LDBL128)))
end_define

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|int
name|_SNAN_F
init|=
literal|0x7f855555
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NANSF
value|(*((float *)(&_SNAN_F)))
end_define

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|int
name|_SNAN_D
index|[
literal|2
index|]
init|=
block|{
literal|0x7ff55555
block|,
literal|0x55555555
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NANS
value|(*((double *)(&_SNAN_D)))
end_define

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|int
name|_SNAN_LDBL128
index|[
literal|4
index|]
init|=
block|{
literal|0x7ff55555
block|,
literal|0x55555555
block|,
literal|0x0
block|,
literal|0x0
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NANSL
value|(*((long double *)(&_SNAN_LDBL128)))
end_define

begin_define
define|#
directive|define
name|__builtin_huge_val
parameter_list|()
value|HUGE_VAL
end_define

begin_define
define|#
directive|define
name|__builtin_huge_valf
parameter_list|()
value|HUGE_VALF
end_define

begin_define
define|#
directive|define
name|__builtin_huge_vall
parameter_list|()
value|HUGE_VALL
end_define

begin_define
define|#
directive|define
name|__builtin_nan
parameter_list|(
name|__dummy
parameter_list|)
value|NAN
end_define

begin_define
define|#
directive|define
name|__builtin_nanf
parameter_list|(
name|__dummy
parameter_list|)
value|NANF
end_define

begin_define
define|#
directive|define
name|__builtin_nanl
parameter_list|(
name|__dummy
parameter_list|)
value|NANL
end_define

begin_define
define|#
directive|define
name|__builtin_nans
parameter_list|(
name|__dummy
parameter_list|)
value|NANS
end_define

begin_define
define|#
directive|define
name|__builtin_nansf
parameter_list|(
name|__dummy
parameter_list|)
value|NANSF
end_define

begin_define
define|#
directive|define
name|__builtin_nansl
parameter_list|(
name|__dummy
parameter_list|)
value|NANSL
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_include
include|#
directive|include
file|<float.h>
end_include

begin_comment
comment|// limit constants
end_comment

begin_define
define|#
directive|define
name|__builtin_huge_val
parameter_list|()
value|HUGE_VAL
end_define

begin_comment
comment|//0x7ff0000000000000
end_comment

begin_define
define|#
directive|define
name|__builtin_huge_valf
parameter_list|()
value|HUGE_VALF
end_define

begin_comment
comment|//0x7f800000
end_comment

begin_define
define|#
directive|define
name|__builtin_huge_vall
parameter_list|()
value|HUGE_VALL
end_define

begin_comment
comment|//0x7ff0000000000000
end_comment

begin_define
define|#
directive|define
name|__builtin_nan
parameter_list|(
name|__dummy
parameter_list|)
value|nan(__dummy)
end_define

begin_comment
comment|//0x7ff8000000000000
end_comment

begin_define
define|#
directive|define
name|__builtin_nanf
parameter_list|(
name|__dummy
parameter_list|)
value|nanf(__dummy)
end_define

begin_comment
comment|// 0x7ff80000
end_comment

begin_define
define|#
directive|define
name|__builtin_nanl
parameter_list|(
name|__dummy
parameter_list|)
value|nanl(__dummy)
end_define

begin_comment
comment|//0x7ff8000000000000
end_comment

begin_define
define|#
directive|define
name|__builtin_nans
parameter_list|(
name|__dummy
parameter_list|)
value|DBL_SNAN
end_define

begin_comment
comment|//0x7ff5555555555555
end_comment

begin_define
define|#
directive|define
name|__builtin_nansf
parameter_list|(
name|__dummy
parameter_list|)
value|FLT_SNAN
end_define

begin_comment
comment|//0x7f855555
end_comment

begin_define
define|#
directive|define
name|__builtin_nansl
parameter_list|(
name|__dummy
parameter_list|)
value|DBL_SNAN
end_define

begin_comment
comment|//0x7ff5555555555555
end_comment

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
comment|// predefined by XLC on LoP
end_comment

begin_define
define|#
directive|define
name|__FLT_DENORM_MIN__
value|1.40129846e-45F
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
comment|// predefined by XLC on LoP
end_comment

begin_define
define|#
directive|define
name|__DBL_DENORM_MIN__
value|4.9406564584124654e-324
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
comment|// predefined by XLC on LoP
end_comment

begin_if
if|#
directive|if
name|__LONGDOUBLE128
end_if

begin_define
define|#
directive|define
name|__LDBL_DENORM_MIN__
value|4.94065645841246544176568792868221e-324L
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__LDBL_DENORM_MIN__
value|4.9406564584124654e-324L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// predefined by XLC on LoP
end_comment

begin_define
define|#
directive|define
name|__CHAR_BIT__
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _AIX
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_SUPPORT_IBM_LIMITS_H
end_comment

end_unit

