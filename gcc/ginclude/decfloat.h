begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2005 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you include this header file into source    files compiled by GCC, this header file does not by itself cause    the resulting executable to be covered by the GNU General Public    License.  This exception does not however invalidate any other    reasons why the executable file might be covered by the GNU General    Public License.  */
end_comment

begin_comment
comment|/*  * Draft C Extension to support decimal floating-pointing arithmetic:    * Characteristics of decimal floating types<decfloat.h>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DECFLOAT_H___
end_ifndef

begin_define
define|#
directive|define
name|_DECFLOAT_H___
end_define

begin_comment
comment|/* Number of base-FLT_RADIX digits in the significand, p.  */
end_comment

begin_undef
undef|#
directive|undef
name|DEC32_MANT_DIG
end_undef

begin_undef
undef|#
directive|undef
name|DEC64_MANT_DIG
end_undef

begin_undef
undef|#
directive|undef
name|DEC128_MANT_DIG
end_undef

begin_define
define|#
directive|define
name|DEC32_MANT_DIG
value|__DEC32_MANT_DIG__
end_define

begin_define
define|#
directive|define
name|DEC64_MANT_DIG
value|__DEC64_MANT_DIG__
end_define

begin_define
define|#
directive|define
name|DEC128_MANT_DIG
value|__DEC128_MANT_DIG__
end_define

begin_comment
comment|/* Minimum exponent. */
end_comment

begin_undef
undef|#
directive|undef
name|DEC32_MIN_EXP
end_undef

begin_undef
undef|#
directive|undef
name|DEC64_MIN_EXP
end_undef

begin_undef
undef|#
directive|undef
name|DEC128_MIN_EXP
end_undef

begin_define
define|#
directive|define
name|DEC32_MIN_EXP
value|__DEC32_MIN_EXP__
end_define

begin_define
define|#
directive|define
name|DEC64_MIN_EXP
value|__DEC64_MIN_EXP__
end_define

begin_define
define|#
directive|define
name|DEC128_MIN_EXP
value|__DEC128_MIN_EXP__
end_define

begin_comment
comment|/* Maximum exponent. */
end_comment

begin_undef
undef|#
directive|undef
name|DEC32_MAX_EXP
end_undef

begin_undef
undef|#
directive|undef
name|DEC64_MAX_EXP
end_undef

begin_undef
undef|#
directive|undef
name|DEC128_MAX_EXP
end_undef

begin_define
define|#
directive|define
name|DEC32_MAX_EXP
value|__DEC32_MAX_EXP__
end_define

begin_define
define|#
directive|define
name|DEC64_MAX_EXP
value|__DEC64_MAX_EXP__
end_define

begin_define
define|#
directive|define
name|DEC128_MAX_EXP
value|__DEC128_MAX_EXP__
end_define

begin_comment
comment|/* Maximum representable finite decimal floating-point number    (there are 6, 15, and 33 9s after the decimal points respectively). */
end_comment

begin_undef
undef|#
directive|undef
name|DEC32_MAX
end_undef

begin_undef
undef|#
directive|undef
name|DEC64_MAX
end_undef

begin_undef
undef|#
directive|undef
name|DEC128_MAX
end_undef

begin_define
define|#
directive|define
name|DEC32_MAX
value|__DEC32_MAX__
end_define

begin_define
define|#
directive|define
name|DEC64_MAX
value|__DEC64_MAX__
end_define

begin_define
define|#
directive|define
name|DEC128_MAX
value|__DEC128_MAX__
end_define

begin_comment
comment|/* The difference between 1 and the least value greater than 1 that is    representable in the given floating point type. */
end_comment

begin_undef
undef|#
directive|undef
name|DEC32_EPSILON
end_undef

begin_undef
undef|#
directive|undef
name|DEC64_EPSILON
end_undef

begin_undef
undef|#
directive|undef
name|DEC128_EPSILON
end_undef

begin_define
define|#
directive|define
name|DEC32_EPSILON
value|__DEC32_EPSILON__
end_define

begin_define
define|#
directive|define
name|DEC64_EPSILON
value|__DEC64_EPSILON__
end_define

begin_define
define|#
directive|define
name|DEC128_EPSILON
value|__DEC128_EPSILON__
end_define

begin_comment
comment|/* Minimum normalized positive floating-point number. */
end_comment

begin_undef
undef|#
directive|undef
name|DEC32_MIN
end_undef

begin_undef
undef|#
directive|undef
name|DEC64_MIN
end_undef

begin_undef
undef|#
directive|undef
name|DEC128_MIN
end_undef

begin_define
define|#
directive|define
name|DEC32_MIN
value|__DEC32_MIN__
end_define

begin_define
define|#
directive|define
name|DEC64_MIN
value|__DEC64_MIN__
end_define

begin_define
define|#
directive|define
name|DEC128_MIN
value|__DEC128_MIN__
end_define

begin_comment
comment|/* Minimum denormalized positive floating-point number. */
end_comment

begin_undef
undef|#
directive|undef
name|DEC32_DEN
end_undef

begin_undef
undef|#
directive|undef
name|DEC64_DEN
end_undef

begin_undef
undef|#
directive|undef
name|DEC128_DEN
end_undef

begin_define
define|#
directive|define
name|DEC32_DEN
value|__DEC32_DEN__
end_define

begin_define
define|#
directive|define
name|DEC64_DEN
value|__DEC64_DEN__
end_define

begin_define
define|#
directive|define
name|DEC128_DEN
value|__DEC128_DEN__
end_define

begin_comment
comment|/* The floating-point expression evaluation method.          -1  indeterminate          0  evaluate all operations and constants just to the range and             precision of the type          1  evaluate operations and constants of type _Decimal32  	    and _Decimal64 to the range and precision of the _Decimal64              type, evaluate _Decimal128 operations and constants to the  	    range and precision of the _Decimal128 type; 	 2  evaluate all operations and constants to the range and 	    precision of the _Decimal128 type. */
end_comment

begin_undef
undef|#
directive|undef
name|DECFLT_EVAL_METHOD
end_undef

begin_define
define|#
directive|define
name|DECFLT_EVAL_METHOD
value|__DECFLT_EVAL_METHOD__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DECFLOAT_H___ */
end_comment

end_unit

