begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* float.h for target sh3e with optional IEEE 32 bit double format */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FLOAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_FLOAT_H_
end_define

begin_comment
comment|/* Produced by enquire version 4.3, CWI, Amsterdam */
end_comment

begin_comment
comment|/* Radix of exponent representation */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_RADIX
end_undef

begin_define
define|#
directive|define
name|FLT_RADIX
value|2
end_define

begin_comment
comment|/* Number of base-FLT_RADIX digits in the significand of a float */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_MANT_DIG
end_undef

begin_define
define|#
directive|define
name|FLT_MANT_DIG
value|24
end_define

begin_comment
comment|/* Number of decimal digits of precision in a float */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_DIG
end_undef

begin_define
define|#
directive|define
name|FLT_DIG
value|6
end_define

begin_comment
comment|/* Addition rounds to 0: zero, 1: nearest, 2: +inf, 3: -inf, -1: unknown */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_ROUNDS
end_undef

begin_define
define|#
directive|define
name|FLT_ROUNDS
value|1
end_define

begin_comment
comment|/* Difference between 1.0 and the minimum float greater than 1.0 */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_EPSILON
end_undef

begin_define
define|#
directive|define
name|FLT_EPSILON
value|1.19209290e-07F
end_define

begin_comment
comment|/* Minimum int x such that FLT_RADIX**(x-1) is a normalised float */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_MIN_EXP
end_undef

begin_define
define|#
directive|define
name|FLT_MIN_EXP
value|(-125)
end_define

begin_comment
comment|/* Minimum normalised float */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_MIN
end_undef

begin_define
define|#
directive|define
name|FLT_MIN
value|1.17549435e-38F
end_define

begin_comment
comment|/* Minimum int x such that 10**x is a normalised float */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_MIN_10_EXP
end_undef

begin_define
define|#
directive|define
name|FLT_MIN_10_EXP
value|(-37)
end_define

begin_comment
comment|/* Maximum int x such that FLT_RADIX**(x-1) is a representable float */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_MAX_EXP
end_undef

begin_define
define|#
directive|define
name|FLT_MAX_EXP
value|128
end_define

begin_comment
comment|/* Maximum float */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_MAX
end_undef

begin_define
define|#
directive|define
name|FLT_MAX
value|3.40282347e+38F
end_define

begin_comment
comment|/* Maximum int x such that 10**x is a representable float */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_MAX_10_EXP
end_undef

begin_define
define|#
directive|define
name|FLT_MAX_10_EXP
value|38
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SH3E__
argument_list|)
operator|||
name|defined
argument_list|(
name|__SH4_SINGLE_ONLY__
argument_list|)
end_if

begin_comment
comment|/* Number of base-FLT_RADIX digits in the significand of a double */
end_comment

begin_undef
undef|#
directive|undef
name|DBL_MANT_DIG
end_undef

begin_define
define|#
directive|define
name|DBL_MANT_DIG
value|24
end_define

begin_comment
comment|/* Number of decimal digits of precision in a double */
end_comment

begin_undef
undef|#
directive|undef
name|DBL_DIG
end_undef

begin_define
define|#
directive|define
name|DBL_DIG
value|6
end_define

begin_comment
comment|/* Difference between 1.0 and the minimum double greater than 1.0 */
end_comment

begin_undef
undef|#
directive|undef
name|DBL_EPSILON
end_undef

begin_define
define|#
directive|define
name|DBL_EPSILON
value|1.19209290e-07F
end_define

begin_comment
comment|/* Minimum int x such that FLT_RADIX**(x-1) is a normalised double */
end_comment

begin_undef
undef|#
directive|undef
name|DBL_MIN_EXP
end_undef

begin_define
define|#
directive|define
name|DBL_MIN_EXP
value|(-125)
end_define

begin_comment
comment|/* Minimum normalised double */
end_comment

begin_undef
undef|#
directive|undef
name|DBL_MIN
end_undef

begin_define
define|#
directive|define
name|DBL_MIN
value|1.17549435e-38F
end_define

begin_comment
comment|/* Minimum int x such that 10**x is a normalised double */
end_comment

begin_undef
undef|#
directive|undef
name|DBL_MIN_10_EXP
end_undef

begin_define
define|#
directive|define
name|DBL_MIN_10_EXP
value|(-37)
end_define

begin_comment
comment|/* Maximum int x such that FLT_RADIX**(x-1) is a representable double */
end_comment

begin_undef
undef|#
directive|undef
name|DBL_MAX_EXP
end_undef

begin_define
define|#
directive|define
name|DBL_MAX_EXP
value|128
end_define

begin_comment
comment|/* Maximum double */
end_comment

begin_undef
undef|#
directive|undef
name|DBL_MAX
end_undef

begin_define
define|#
directive|define
name|DBL_MAX
value|3.40282347e+38F
end_define

begin_comment
comment|/* Maximum int x such that 10**x is a representable double */
end_comment

begin_undef
undef|#
directive|undef
name|DBL_MAX_10_EXP
end_undef

begin_define
define|#
directive|define
name|DBL_MAX_10_EXP
value|38
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Number of base-FLT_RADIX digits in the significand of a double */
end_comment

begin_undef
undef|#
directive|undef
name|DBL_MANT_DIG
end_undef

begin_define
define|#
directive|define
name|DBL_MANT_DIG
value|53
end_define

begin_comment
comment|/* Number of decimal digits of precision in a double */
end_comment

begin_undef
undef|#
directive|undef
name|DBL_DIG
end_undef

begin_define
define|#
directive|define
name|DBL_DIG
value|15
end_define

begin_comment
comment|/* Difference between 1.0 and the minimum double greater than 1.0 */
end_comment

begin_undef
undef|#
directive|undef
name|DBL_EPSILON
end_undef

begin_define
define|#
directive|define
name|DBL_EPSILON
value|2.2204460492503131e-16
end_define

begin_comment
comment|/* Minimum int x such that FLT_RADIX**(x-1) is a normalised double */
end_comment

begin_undef
undef|#
directive|undef
name|DBL_MIN_EXP
end_undef

begin_define
define|#
directive|define
name|DBL_MIN_EXP
value|(-1021)
end_define

begin_comment
comment|/* Minimum normalised double */
end_comment

begin_undef
undef|#
directive|undef
name|DBL_MIN
end_undef

begin_define
define|#
directive|define
name|DBL_MIN
value|2.2250738585072014e-308
end_define

begin_comment
comment|/* Minimum int x such that 10**x is a normalised double */
end_comment

begin_undef
undef|#
directive|undef
name|DBL_MIN_10_EXP
end_undef

begin_define
define|#
directive|define
name|DBL_MIN_10_EXP
value|(-307)
end_define

begin_comment
comment|/* Maximum int x such that FLT_RADIX**(x-1) is a representable double */
end_comment

begin_undef
undef|#
directive|undef
name|DBL_MAX_EXP
end_undef

begin_define
define|#
directive|define
name|DBL_MAX_EXP
value|1024
end_define

begin_comment
comment|/* Maximum double */
end_comment

begin_undef
undef|#
directive|undef
name|DBL_MAX
end_undef

begin_define
define|#
directive|define
name|DBL_MAX
value|1.7976931348623157e+308
end_define

begin_comment
comment|/* Maximum int x such that 10**x is a representable double */
end_comment

begin_undef
undef|#
directive|undef
name|DBL_MAX_10_EXP
end_undef

begin_define
define|#
directive|define
name|DBL_MAX_10_EXP
value|308
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of base-FLT_RADIX digits in the significand of a long double */
end_comment

begin_undef
undef|#
directive|undef
name|LDBL_MANT_DIG
end_undef

begin_define
define|#
directive|define
name|LDBL_MANT_DIG
value|53
end_define

begin_comment
comment|/* Number of decimal digits of precision in a long double */
end_comment

begin_undef
undef|#
directive|undef
name|LDBL_DIG
end_undef

begin_define
define|#
directive|define
name|LDBL_DIG
value|15
end_define

begin_comment
comment|/* Difference between 1.0 and the minimum long double greater than 1.0 */
end_comment

begin_undef
undef|#
directive|undef
name|LDBL_EPSILON
end_undef

begin_define
define|#
directive|define
name|LDBL_EPSILON
value|2.2204460492503131e-16
end_define

begin_comment
comment|/* Minimum int x such that FLT_RADIX**(x-1) is a normalised long double */
end_comment

begin_undef
undef|#
directive|undef
name|LDBL_MIN_EXP
end_undef

begin_define
define|#
directive|define
name|LDBL_MIN_EXP
value|(-1021)
end_define

begin_comment
comment|/* Minimum normalised long double */
end_comment

begin_undef
undef|#
directive|undef
name|LDBL_MIN
end_undef

begin_define
define|#
directive|define
name|LDBL_MIN
value|2.2250738585072014e-308
end_define

begin_comment
comment|/* Minimum int x such that 10**x is a normalised long double */
end_comment

begin_undef
undef|#
directive|undef
name|LDBL_MIN_10_EXP
end_undef

begin_define
define|#
directive|define
name|LDBL_MIN_10_EXP
value|(-307)
end_define

begin_comment
comment|/* Maximum int x such that FLT_RADIX**(x-1) is a representable long double */
end_comment

begin_undef
undef|#
directive|undef
name|LDBL_MAX_EXP
end_undef

begin_define
define|#
directive|define
name|LDBL_MAX_EXP
value|1024
end_define

begin_comment
comment|/* Maximum long double */
end_comment

begin_undef
undef|#
directive|undef
name|LDBL_MAX
end_undef

begin_define
define|#
directive|define
name|LDBL_MAX
value|1.7976931348623157e+308
end_define

begin_comment
comment|/* Maximum int x such that 10**x is a representable long double */
end_comment

begin_undef
undef|#
directive|undef
name|LDBL_MAX_10_EXP
end_undef

begin_define
define|#
directive|define
name|LDBL_MAX_10_EXP
value|308
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  _FLOAT_H_ */
end_comment

end_unit

