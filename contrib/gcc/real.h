begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of floating-point access for GNU compiler.    Copyright (C) 1989, 1991, 1994, 1996, 1997, 1998, 1999,    2000, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it under    the terms of the GNU General Public License as published by the Free    Software Foundation; either version 2, or (at your option) any later    version.     GCC is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_REAL_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_REAL_H
end_define

begin_include
include|#
directive|include
file|"machmode.h"
end_include

begin_comment
comment|/* An expanded form of the represented number.  */
end_comment

begin_comment
comment|/* Enumerate the special cases of numbers that we encounter.  */
end_comment

begin_enum
enum|enum
name|real_value_class
block|{
name|rvc_zero
block|,
name|rvc_normal
block|,
name|rvc_inf
block|,
name|rvc_nan
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|SIGNIFICAND_BITS
value|(128 + HOST_BITS_PER_LONG)
end_define

begin_define
define|#
directive|define
name|EXP_BITS
value|(32 - 6)
end_define

begin_define
define|#
directive|define
name|MAX_EXP
value|((1<< (EXP_BITS - 1)) - 1)
end_define

begin_define
define|#
directive|define
name|SIGSZ
value|(SIGNIFICAND_BITS / HOST_BITS_PER_LONG)
end_define

begin_define
define|#
directive|define
name|SIG_MSB
value|((unsigned long)1<< (HOST_BITS_PER_LONG - 1))
end_define

begin_decl_stmt
name|struct
name|real_value
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* Use the same underlying type for all bit-fields, so as to make      sure they're packed together, otherwise REAL_VALUE_TYPE_SIZE will      be miscomputed.  */
name|unsigned
name|int
comment|/* ENUM_BITFIELD (real_value_class) */
name|cl
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|decimal
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|sign
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|signalling
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|canonical
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|uexp
range|:
name|EXP_BITS
decl_stmt|;
name|unsigned
name|long
name|sig
index|[
name|SIGSZ
index|]
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|REAL_EXP
parameter_list|(
name|REAL
parameter_list|)
define|\
value|((int)((REAL)->uexp ^ (unsigned int)(1<< (EXP_BITS - 1))) \    - (1<< (EXP_BITS - 1)))
end_define

begin_define
define|#
directive|define
name|SET_REAL_EXP
parameter_list|(
name|REAL
parameter_list|,
name|EXP
parameter_list|)
define|\
value|((REAL)->uexp = ((unsigned int)(EXP)& (unsigned int)((1<< EXP_BITS) - 1)))
end_define

begin_comment
comment|/* Various headers condition prototypes on #ifdef REAL_VALUE_TYPE, so it    needs to be a macro.  We do need to continue to have a structure tag    so that other headers can forward declare it.  */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_TYPE
value|struct real_value
end_define

begin_comment
comment|/* We store a REAL_VALUE_TYPE into an rtx, and we do this by putting it in    consecutive "w" slots.  Moreover, we've got to compute the number of "w"    slots at preprocessor time, which means we can't use sizeof.  Guess.  */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_TYPE_SIZE
value|(SIGNIFICAND_BITS + 32)
end_define

begin_define
define|#
directive|define
name|REAL_WIDTH
define|\
value|(REAL_VALUE_TYPE_SIZE/HOST_BITS_PER_WIDE_INT \    + (REAL_VALUE_TYPE_SIZE%HOST_BITS_PER_WIDE_INT ? 1 : 0))
end_define

begin_comment
comment|/* round up */
end_comment

begin_comment
comment|/* Verify the guess.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|test_real_width
index|[
sizeof|sizeof
argument_list|(
name|REAL_VALUE_TYPE
argument_list|)
operator|<=
name|REAL_WIDTH
operator|*
sizeof|sizeof
argument_list|(
name|HOST_WIDE_INT
argument_list|)
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Calculate the format for CONST_DOUBLE.  We need as many slots as    are necessary to overlay a REAL_VALUE_TYPE on them.  This could be    as many as four (32-bit HOST_WIDE_INT, 128-bit REAL_VALUE_TYPE).     A number of places assume that there are always at least two 'w'    slots in a CONST_DOUBLE, so we provide them even if one would suffice.  */
end_comment

begin_if
if|#
directive|if
name|REAL_WIDTH
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|CONST_DOUBLE_FORMAT
value|"ww"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|REAL_WIDTH
operator|==
literal|2
end_if

begin_define
define|#
directive|define
name|CONST_DOUBLE_FORMAT
value|"ww"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|REAL_WIDTH
operator|==
literal|3
end_if

begin_define
define|#
directive|define
name|CONST_DOUBLE_FORMAT
value|"www"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|REAL_WIDTH
operator|==
literal|4
end_if

begin_define
define|#
directive|define
name|CONST_DOUBLE_FORMAT
value|"wwww"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|REAL_WIDTH
operator|==
literal|5
end_if

begin_define
define|#
directive|define
name|CONST_DOUBLE_FORMAT
value|"wwwww"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|REAL_WIDTH
operator|==
literal|6
end_if

begin_define
define|#
directive|define
name|CONST_DOUBLE_FORMAT
value|"wwwwww"
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"REAL_WIDTH> 6 not supported"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Describes the properties of the specific target format in use.  */
end_comment

begin_struct
struct|struct
name|real_format
block|{
comment|/* Move to and from the target bytes.  */
name|void
function_decl|(
modifier|*
name|encode
function_decl|)
parameter_list|(
specifier|const
name|struct
name|real_format
modifier|*
parameter_list|,
name|long
modifier|*
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|decode
function_decl|)
parameter_list|(
specifier|const
name|struct
name|real_format
modifier|*
parameter_list|,
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
specifier|const
name|long
modifier|*
parameter_list|)
function_decl|;
comment|/* The radix of the exponent and digits of the significand.  */
name|int
name|b
decl_stmt|;
comment|/* log2(b).  */
name|int
name|log2_b
decl_stmt|;
comment|/* Size of the significand in digits of radix B.  */
name|int
name|p
decl_stmt|;
comment|/* Size of the significant of a NaN, in digits of radix B.  */
name|int
name|pnan
decl_stmt|;
comment|/* The minimum negative integer, x, such that b**(x-1) is normalized.  */
name|int
name|emin
decl_stmt|;
comment|/* The maximum integer, x, such that b**(x-1) is representable.  */
name|int
name|emax
decl_stmt|;
comment|/* The bit position of the sign bit, for determining whether a value      is positive/negative, or -1 for a complex encoding.  */
name|int
name|signbit_ro
decl_stmt|;
comment|/* The bit position of the sign bit, for changing the sign of a number,      or -1 for a complex encoding.  */
name|int
name|signbit_rw
decl_stmt|;
comment|/* Properties of the format.  */
name|bool
name|has_nans
decl_stmt|;
name|bool
name|has_inf
decl_stmt|;
name|bool
name|has_denorm
decl_stmt|;
name|bool
name|has_signed_zero
decl_stmt|;
name|bool
name|qnan_msb_set
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The target format used for each floating point mode.    Float modes are followed by decimal float modes, with entries for    float modes indexed by (MODE - first float mode), and entries for    decimal float modes indexed by (MODE - first decimal float mode) +    the number of float modes.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
modifier|*
name|real_format_for_mode
index|[
name|MAX_MODE_FLOAT
operator|-
name|MIN_MODE_FLOAT
operator|+
literal|1
operator|+
name|MAX_MODE_DECIMAL_FLOAT
operator|-
name|MIN_MODE_DECIMAL_FLOAT
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|REAL_MODE_FORMAT
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(real_format_for_mode[DECIMAL_FLOAT_MODE_P (MODE)			\ 			? ((MODE - MIN_MODE_DECIMAL_FLOAT)		\ 			   + (MAX_MODE_FLOAT - MIN_MODE_FLOAT + 1))	\ 			: (MODE - MIN_MODE_FLOAT)])
end_define

begin_comment
comment|/* The following macro determines whether the floating point format is    composite, i.e. may contain non-consecutive mantissa bits, in which    case compile-time FP overflow may not model run-time overflow.  */
end_comment

begin_define
define|#
directive|define
name|REAL_MODE_FORMAT_COMPOSITE_P
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((REAL_MODE_FORMAT(MODE))->pnan< (REAL_MODE_FORMAT (MODE))->p)
end_define

begin_comment
comment|/* Declare functions in real.c.  */
end_comment

begin_comment
comment|/* Binary or unary arithmetic on tree_code.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|real_arithmetic
parameter_list|(
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Compare reals by tree_code.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|real_compare
parameter_list|(
name|int
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Determine whether a floating-point value X is infinite.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|real_isinf
parameter_list|(
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Determine whether a floating-point value X is a NaN.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|real_isnan
parameter_list|(
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Determine whether a floating-point value X is negative.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|real_isneg
parameter_list|(
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Determine whether a floating-point value X is minus zero.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|real_isnegzero
parameter_list|(
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Compare two floating-point objects for bitwise identity.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|real_identical
parameter_list|(
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Extend or truncate to a new mode.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|real_convert
parameter_list|(
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if truncating to NEW is exact.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|exact_real_truncate
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Render R as a decimal floating point constant.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|real_to_decimal
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Render R as a hexadecimal floating point constant.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|real_to_hexadecimal
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Render R as an integer.  */
end_comment

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|real_to_integer
parameter_list|(
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|real_to_integer2
parameter_list|(
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|HOST_WIDE_INT
modifier|*
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Initialize R from a decimal or hexadecimal string.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|real_from_string
parameter_list|(
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Wrapper to allow different internal representation for decimal floats. */
end_comment

begin_function_decl
specifier|extern
name|void
name|real_from_string3
parameter_list|(
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|enum
name|machine_mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Initialize R from an integer pair HIGH/LOW.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|real_from_integer
parameter_list|(
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|real_to_target_fmt
parameter_list|(
name|long
modifier|*
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
specifier|const
name|struct
name|real_format
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|real_to_target
parameter_list|(
name|long
modifier|*
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
name|enum
name|machine_mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|real_from_target_fmt
parameter_list|(
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
specifier|const
name|long
modifier|*
parameter_list|,
specifier|const
name|struct
name|real_format
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|real_from_target
parameter_list|(
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
specifier|const
name|long
modifier|*
parameter_list|,
name|enum
name|machine_mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|real_inf
parameter_list|(
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|real_nan
parameter_list|(
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|enum
name|machine_mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|real_maxval
parameter_list|(
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
name|int
parameter_list|,
name|enum
name|machine_mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|real_2expN
parameter_list|(
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|real_hash
parameter_list|(
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Target formats defined in real.c.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|ieee_single_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|mips_single_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|ieee_double_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|mips_double_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|ieee_extended_motorola_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|ieee_extended_intel_96_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|ieee_extended_intel_96_round_53_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|ieee_extended_intel_128_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|ibm_extended_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|mips_extended_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|ieee_quad_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|mips_quad_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|vax_f_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|vax_d_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|vax_g_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|i370_single_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|i370_double_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|c4x_single_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|c4x_extended_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|real_internal_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|decimal_single_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|decimal_double_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|real_format
name|decimal_quad_format
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ====================================================================== */
end_comment

begin_comment
comment|/* Crap.  */
end_comment

begin_define
define|#
directive|define
name|REAL_ARITHMETIC
parameter_list|(
name|value
parameter_list|,
name|code
parameter_list|,
name|d1
parameter_list|,
name|d2
parameter_list|)
define|\
value|real_arithmetic (&(value), code,&(d1),&(d2))
end_define

begin_define
define|#
directive|define
name|REAL_VALUES_IDENTICAL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|real_identical (&(x),&(y))
end_define

begin_define
define|#
directive|define
name|REAL_VALUES_EQUAL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|real_compare (EQ_EXPR,&(x),&(y))
end_define

begin_define
define|#
directive|define
name|REAL_VALUES_LESS
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|real_compare (LT_EXPR,&(x),&(y))
end_define

begin_comment
comment|/* Determine whether a floating-point value X is infinite.  */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_ISINF
parameter_list|(
name|x
parameter_list|)
value|real_isinf (&(x))
end_define

begin_comment
comment|/* Determine whether a floating-point value X is a NaN.  */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_ISNAN
parameter_list|(
name|x
parameter_list|)
value|real_isnan (&(x))
end_define

begin_comment
comment|/* Determine whether a floating-point value X is negative.  */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_NEGATIVE
parameter_list|(
name|x
parameter_list|)
value|real_isneg (&(x))
end_define

begin_comment
comment|/* Determine whether a floating-point value X is minus zero.  */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_MINUS_ZERO
parameter_list|(
name|x
parameter_list|)
value|real_isnegzero (&(x))
end_define

begin_comment
comment|/* IN is a REAL_VALUE_TYPE.  OUT is an array of longs.  */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_TO_TARGET_LONG_DOUBLE
parameter_list|(
name|IN
parameter_list|,
name|OUT
parameter_list|)
define|\
value|real_to_target (OUT,&(IN),						\ 		  mode_for_size (LONG_DOUBLE_TYPE_SIZE, MODE_FLOAT, 0))
end_define

begin_define
define|#
directive|define
name|REAL_VALUE_TO_TARGET_DOUBLE
parameter_list|(
name|IN
parameter_list|,
name|OUT
parameter_list|)
define|\
value|real_to_target (OUT,&(IN), mode_for_size (64, MODE_FLOAT, 0))
end_define

begin_comment
comment|/* IN is a REAL_VALUE_TYPE.  OUT is a long.  */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_TO_TARGET_SINGLE
parameter_list|(
name|IN
parameter_list|,
name|OUT
parameter_list|)
define|\
value|((OUT) = real_to_target (NULL,&(IN), mode_for_size (32, MODE_FLOAT, 0)))
end_define

begin_define
define|#
directive|define
name|REAL_VALUE_FROM_INT
parameter_list|(
name|r
parameter_list|,
name|lo
parameter_list|,
name|hi
parameter_list|,
name|mode
parameter_list|)
define|\
value|real_from_integer (&(r), mode, lo, hi, 0)
end_define

begin_define
define|#
directive|define
name|REAL_VALUE_FROM_UNSIGNED_INT
parameter_list|(
name|r
parameter_list|,
name|lo
parameter_list|,
name|hi
parameter_list|,
name|mode
parameter_list|)
define|\
value|real_from_integer (&(r), mode, lo, hi, 1)
end_define

begin_comment
comment|/* Real values to IEEE 754R decimal floats.  */
end_comment

begin_comment
comment|/* IN is a REAL_VALUE_TYPE.  OUT is an array of longs.  */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_TO_TARGET_DECIMAL128
parameter_list|(
name|IN
parameter_list|,
name|OUT
parameter_list|)
define|\
value|real_to_target (OUT,&(IN), mode_for_size (128, MODE_DECIMAL_FLOAT, 0))
end_define

begin_define
define|#
directive|define
name|REAL_VALUE_TO_TARGET_DECIMAL64
parameter_list|(
name|IN
parameter_list|,
name|OUT
parameter_list|)
define|\
value|real_to_target (OUT,&(IN), mode_for_size (64, MODE_DECIMAL_FLOAT, 0))
end_define

begin_comment
comment|/* IN is a REAL_VALUE_TYPE.  OUT is a long.  */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_TO_TARGET_DECIMAL32
parameter_list|(
name|IN
parameter_list|,
name|OUT
parameter_list|)
define|\
value|((OUT) = real_to_target (NULL,&(IN), mode_for_size (32, MODE_DECIMAL_FLOAT, 0)))
end_define

begin_function_decl
specifier|extern
name|REAL_VALUE_TYPE
name|real_value_truncate
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|REAL_VALUE_TYPE
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|REAL_VALUE_TO_INT
parameter_list|(
name|plow
parameter_list|,
name|phigh
parameter_list|,
name|r
parameter_list|)
define|\
value|real_to_integer2 (plow, phigh,&(r))
end_define

begin_function_decl
specifier|extern
name|REAL_VALUE_TYPE
name|real_arithmetic2
parameter_list|(
name|int
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|REAL_VALUE_NEGATE
parameter_list|(
name|X
parameter_list|)
define|\
value|real_arithmetic2 (NEGATE_EXPR,&(X), NULL)
end_define

begin_define
define|#
directive|define
name|REAL_VALUE_ABS
parameter_list|(
name|X
parameter_list|)
define|\
value|real_arithmetic2 (ABS_EXPR,&(X), NULL)
end_define

begin_function_decl
specifier|extern
name|int
name|significand_size
parameter_list|(
name|enum
name|machine_mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|REAL_VALUE_TYPE
name|real_from_string2
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|enum
name|machine_mode
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|REAL_VALUE_ATOF
parameter_list|(
name|s
parameter_list|,
name|m
parameter_list|)
define|\
value|real_from_string2 (s, m)
end_define

begin_define
define|#
directive|define
name|CONST_DOUBLE_ATOF
parameter_list|(
name|s
parameter_list|,
name|m
parameter_list|)
define|\
value|CONST_DOUBLE_FROM_REAL_VALUE (real_from_string2 (s, m), m)
end_define

begin_define
define|#
directive|define
name|REAL_VALUE_FIX
parameter_list|(
name|r
parameter_list|)
define|\
value|real_to_integer (&(r))
end_define

begin_comment
comment|/* ??? Not quite right.  */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_UNSIGNED_FIX
parameter_list|(
name|r
parameter_list|)
define|\
value|real_to_integer (&(r))
end_define

begin_comment
comment|/* ??? These were added for Paranoia support.  */
end_comment

begin_comment
comment|/* Return floor log2(R).  */
end_comment

begin_function_decl
specifier|extern
name|int
name|real_exponent
parameter_list|(
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* R = A * 2**EXP.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|real_ldexp
parameter_list|(
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* **** End of software floating point emulator interface macros **** */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Constant real values 0, 1, 2, 3, 10, -1, -2, 0.5 and 1/3.  */
end_comment

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|dconst0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|dconst1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|dconst2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|dconst3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|dconst10
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|dconstm1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|dconstm2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|dconsthalf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|dconstthird
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|dconstpi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|dconste
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function to return a real value (not a tree node)    from a given integer constant.  */
end_comment

begin_function_decl
name|REAL_VALUE_TYPE
name|real_value_from_int_cst
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given a CONST_DOUBLE in FROM, store into TO the value it represents.  */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_FROM_CONST_DOUBLE
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|)
define|\
value|((to) = *CONST_DOUBLE_REAL_VALUE (from))
end_define

begin_comment
comment|/* Return a CONST_DOUBLE with value R and mode M.  */
end_comment

begin_define
define|#
directive|define
name|CONST_DOUBLE_FROM_REAL_VALUE
parameter_list|(
name|r
parameter_list|,
name|m
parameter_list|)
define|\
value|const_double_from_real_value (r, m)
end_define

begin_function_decl
specifier|extern
name|rtx
name|const_double_from_real_value
parameter_list|(
name|REAL_VALUE_TYPE
parameter_list|,
name|enum
name|machine_mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Replace R by 1/R in the given machine mode, if the result is exact.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|exact_real_inverse
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree.c: wrap up a REAL_VALUE_TYPE in a tree node.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|build_real
parameter_list|(
name|tree
parameter_list|,
name|REAL_VALUE_TYPE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Calculate R as the square root of X in the given machine mode.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|real_sqrt
parameter_list|(
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Calculate R as X raised to the integer exponent N in mode MODE.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|real_powi
parameter_list|(
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Standard round to integer value functions.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|real_trunc
parameter_list|(
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|real_floor
parameter_list|(
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|real_ceil
parameter_list|(
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|real_round
parameter_list|(
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the sign of R to the sign of X.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|real_copysign
parameter_list|(
name|REAL_VALUE_TYPE
modifier|*
parameter_list|,
specifier|const
name|REAL_VALUE_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_REAL_H */
end_comment

end_unit

