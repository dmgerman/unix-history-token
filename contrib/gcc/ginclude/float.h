begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2002 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you include this header file into source    files compiled by GCC, this header file does not by itself cause    the resulting executable to be covered by the GNU General Public    License.  This exception does not however invalidate any other    reasons why the executable file might be covered by the GNU General    Public License.  */
end_comment

begin_comment
comment|/*  * ISO C Standard:  5.2.4.2.2  Characteristics of floating types<float.h>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FLOAT_H___
end_ifndef

begin_define
define|#
directive|define
name|_FLOAT_H___
end_define

begin_comment
comment|/* Radix of exponent representation, b. */
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
value|__FLT_RADIX__
end_define

begin_comment
comment|/* Number of base-FLT_RADIX digits in the significand, p.  */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_MANT_DIG
end_undef

begin_undef
undef|#
directive|undef
name|DBL_MANT_DIG
end_undef

begin_undef
undef|#
directive|undef
name|LDBL_MANT_DIG
end_undef

begin_define
define|#
directive|define
name|FLT_MANT_DIG
value|__FLT_MANT_DIG__
end_define

begin_define
define|#
directive|define
name|DBL_MANT_DIG
value|__DBL_MANT_DIG__
end_define

begin_define
define|#
directive|define
name|LDBL_MANT_DIG
value|__LDBL_MANT_DIG__
end_define

begin_comment
comment|/* Number of decimal digits, q, such that any floating-point number with q    decimal digits can be rounded into a floating-point number with p radix b    digits and back again without change to the q decimal digits,  	p * log10(b)			if b is a power of 10 	floor((p - 1) * log10(b))	otherwise */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_DIG
end_undef

begin_undef
undef|#
directive|undef
name|DBL_DIG
end_undef

begin_undef
undef|#
directive|undef
name|LDBL_DIG
end_undef

begin_define
define|#
directive|define
name|FLT_DIG
value|__FLT_DIG__
end_define

begin_define
define|#
directive|define
name|DBL_DIG
value|__DBL_DIG__
end_define

begin_define
define|#
directive|define
name|LDBL_DIG
value|__LDBL_DIG__
end_define

begin_comment
comment|/* Minimum int x such that FLT_RADIX**(x-1) is a normalized float, emin */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_MIN_EXP
end_undef

begin_undef
undef|#
directive|undef
name|DBL_MIN_EXP
end_undef

begin_undef
undef|#
directive|undef
name|LDBL_MIN_EXP
end_undef

begin_define
define|#
directive|define
name|FLT_MIN_EXP
value|__FLT_MIN_EXP__
end_define

begin_define
define|#
directive|define
name|DBL_MIN_EXP
value|__DBL_MIN_EXP__
end_define

begin_define
define|#
directive|define
name|LDBL_MIN_EXP
value|__LDBL_MIN_EXP__
end_define

begin_comment
comment|/* Minimum negative integer such that 10 raised to that power is in the    range of normalized floating-point numbers,  	ceil(log10(b) * (emin - 1)) */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_MIN_10_EXP
end_undef

begin_undef
undef|#
directive|undef
name|DBL_MIN_10_EXP
end_undef

begin_undef
undef|#
directive|undef
name|LDBL_MIN_10_EXP
end_undef

begin_define
define|#
directive|define
name|FLT_MIN_10_EXP
value|__FLT_MIN_10_EXP__
end_define

begin_define
define|#
directive|define
name|DBL_MIN_10_EXP
value|__DBL_MIN_10_EXP__
end_define

begin_define
define|#
directive|define
name|LDBL_MIN_10_EXP
value|__LDBL_MIN_10_EXP__
end_define

begin_comment
comment|/* Maximum int x such that FLT_RADIX**(x-1) is a representable float, emax.  */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_MAX_EXP
end_undef

begin_undef
undef|#
directive|undef
name|DBL_MAX_EXP
end_undef

begin_undef
undef|#
directive|undef
name|LDBL_MAX_EXP
end_undef

begin_define
define|#
directive|define
name|FLT_MAX_EXP
value|__FLT_MAX_EXP__
end_define

begin_define
define|#
directive|define
name|DBL_MAX_EXP
value|__DBL_MAX_EXP__
end_define

begin_define
define|#
directive|define
name|LDBL_MAX_EXP
value|__LDBL_MAX_EXP__
end_define

begin_comment
comment|/* Maximum integer such that 10 raised to that power is in the range of    representable finite floating-point numbers,  	floor(log10((1 - b**-p) * b**emax)) */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_MAX_10_EXP
end_undef

begin_undef
undef|#
directive|undef
name|DBL_MAX_10_EXP
end_undef

begin_undef
undef|#
directive|undef
name|LDBL_MAX_10_EXP
end_undef

begin_define
define|#
directive|define
name|FLT_MAX_10_EXP
value|__FLT_MAX_10_EXP__
end_define

begin_define
define|#
directive|define
name|DBL_MAX_10_EXP
value|__DBL_MAX_10_EXP__
end_define

begin_define
define|#
directive|define
name|LDBL_MAX_10_EXP
value|__LDBL_MAX_10_EXP__
end_define

begin_comment
comment|/* Maximum representable finite floating-point number,  	(1 - b**-p) * b**emax */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_MAX
end_undef

begin_undef
undef|#
directive|undef
name|DBL_MAX
end_undef

begin_undef
undef|#
directive|undef
name|LDBL_MAX
end_undef

begin_define
define|#
directive|define
name|FLT_MAX
value|__FLT_MAX__
end_define

begin_define
define|#
directive|define
name|DBL_MAX
value|__DBL_MAX__
end_define

begin_define
define|#
directive|define
name|LDBL_MAX
value|__LDBL_MAX__
end_define

begin_comment
comment|/* The difference between 1 and the least value greater than 1 that is    representable in the given floating point type, b**1-p.  */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_EPSILON
end_undef

begin_undef
undef|#
directive|undef
name|DBL_EPSILON
end_undef

begin_undef
undef|#
directive|undef
name|LDBL_EPSILON
end_undef

begin_define
define|#
directive|define
name|FLT_EPSILON
value|__FLT_EPSILON__
end_define

begin_define
define|#
directive|define
name|DBL_EPSILON
value|__DBL_EPSILON__
end_define

begin_define
define|#
directive|define
name|LDBL_EPSILON
value|__LDBL_EPSILON__
end_define

begin_comment
comment|/* Minimum normalized positive floating-point number, b**(emin - 1).  */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_MIN
end_undef

begin_undef
undef|#
directive|undef
name|DBL_MIN
end_undef

begin_undef
undef|#
directive|undef
name|LDBL_MIN
end_undef

begin_define
define|#
directive|define
name|FLT_MIN
value|__FLT_MIN__
end_define

begin_define
define|#
directive|define
name|DBL_MIN
value|__DBL_MIN__
end_define

begin_define
define|#
directive|define
name|LDBL_MIN
value|__LDBL_MIN__
end_define

begin_comment
comment|/* Addition rounds to 0: zero, 1: nearest, 2: +inf, 3: -inf, -1: unknown.  */
end_comment

begin_comment
comment|/* ??? This is supposed to change with calls to fesetround in<fenv.h>.  */
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

begin_if
if|#
directive|if
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
comment|/* The floating-point expression evaluation method.         -1  indeterminate          0  evaluate all operations and constants just to the range and             precision of the type          1  evaluate operations and constants of type float and double             to the range and precision of the double type, evaluate             long double operations and constants to the range and             precision of the long double type          2  evaluate all operations and constants to the range and             precision of the long double type     ??? This ought to change with the setting of the fp control word;    the value provided by the compiler assumes the widest setting.  */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_EVAL_METHOD
end_undef

begin_define
define|#
directive|define
name|FLT_EVAL_METHOD
value|__FLT_EVAL_METHOD__
end_define

begin_comment
comment|/* Number of decimal digits, n, such that any floating-point number in the    widest supported floating type with pmax radix b digits can be rounded    to a floating-point number with n decimal digits and back again without    change to the value,  	pmax * log10(b)			if b is a power of 10 	ceil(1 + pmax * log10(b))	otherwise */
end_comment

begin_undef
undef|#
directive|undef
name|DECIMAL_DIG
end_undef

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

begin_comment
comment|/* C99 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FLOAT_H___ */
end_comment

end_unit

