begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Front-end tree definitions for GNU compiler.    Copyright (C) 1989, 1991 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|REAL_H_INCLUDED
end_define

begin_comment
comment|/* Define codes for all the float formats that we know of.  */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN_FLOAT_FORMAT
value|0
end_define

begin_define
define|#
directive|define
name|IEEE_FLOAT_FORMAT
value|1
end_define

begin_define
define|#
directive|define
name|VAX_FLOAT_FORMAT
value|2
end_define

begin_comment
comment|/* Default to IEEE float if not specified.  Nearly all machines use it.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_FLOAT_FORMAT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_FLOAT_FORMAT
value|IEEE_FLOAT_FORMAT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_FLOAT_FORMAT
end_ifndef

begin_define
define|#
directive|define
name|HOST_FLOAT_FORMAT
value|IEEE_FLOAT_FORMAT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET_FLOAT_FORMAT
operator|==
name|IEEE_FLOAT_FORMAT
end_if

begin_define
define|#
directive|define
name|REAL_INFINITY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_comment
comment|/* Defining REAL_IS_NOT_DOUBLE breaks certain initializations    when REAL_ARITHMETIC etc. are not defined.  */
end_comment

begin_comment
comment|/* Now see if the host and target machines use the same format.     If not, define REAL_IS_NOT_DOUBLE (even if we end up representing    reals as doubles because we have no better way in this cross compiler.)    This turns off various optimizations that can happen when we know the    compiler's float format matches the target's float format.    */
end_comment

begin_if
if|#
directive|if
name|HOST_FLOAT_FORMAT
operator|!=
name|TARGET_FLOAT_FORMAT
end_if

begin_define
define|#
directive|define
name|REAL_IS_NOT_DOUBLE
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_TYPE
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_TYPE
define|\
value|struct real_value{ HOST_WIDE_INT i[sizeof (double)/sizeof (HOST_WIDE_INT)]; }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no REAL_VALUE_TYPE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* formats differ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_comment
comment|/* If we are not cross-compiling, use a `double' to represent the    floating-point value.  Otherwise, use some other type    (probably a struct containing an array of longs).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_TYPE
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_TYPE
value|double
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REAL_IS_NOT_DOUBLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HOST_FLOAT_FORMAT
operator|==
name|TARGET_FLOAT_FORMAT
end_if

begin_comment
comment|/* Convert a type `double' value in host format first to a type `float'    value in host format and then to a single type `long' value which    is the bitwise equivalent of the `float' value.  */
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
value|do { float f = (float) (IN);						\      (OUT) = *(long *)&f;						\   } while (0)
end_define

begin_comment
comment|/* Convert a type `double' value in host format to a pair of type `long'    values which is its bitwise equivalent, but put the two words into    proper word order for the target.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HOST_WORDS_BIG_ENDIAN
argument_list|)
operator|==
name|WORDS_BIG_ENDIAN
end_if

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
value|do { REAL_VALUE_TYPE in = (IN);
comment|/* Make sure it's not in a register.  */
value|\      (OUT)[0] = ((long *)&in)[0];					\      (OUT)[1] = ((long *)&in)[1];					\    } while (0)
end_define

begin_else
else|#
directive|else
end_else

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
value|do { REAL_VALUE_TYPE in = (IN);
comment|/* Make sure it's not in a register.  */
value|\      (OUT)[1] = ((long *)&in)[0];					\      (OUT)[0] = ((long *)&in)[1];					\    } while (0)
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
comment|/* HOST_FLOAT_FORMAT == TARGET_FLOAT_FORMAT */
end_comment

begin_comment
comment|/* Compare two floating-point values for equality.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUES_EQUAL
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUES_EQUAL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) == (y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Compare two floating-point values for less than.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUES_LESS
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUES_LESS
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)< (y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Convert a floating-point value to integer by truncating.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_FIX_TRUNCATE
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_FIX_TRUNCATE
parameter_list|(
name|x
parameter_list|)
value|((int) (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Convert a floating-point value to unsigned integer by truncating.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_UNSIGNED_FIX_TRUNCATE
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_UNSIGNED_FIX_TRUNCATE
parameter_list|(
name|x
parameter_list|)
value|((unsigned int) (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Convert a floating-point value to integer, using any rounding mode.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_FIX
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_FIX
parameter_list|(
name|x
parameter_list|)
value|((int) (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Convert a floating-point value to unsigned integer, using any rounding    mode.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_UNSIGNED_FIX
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_UNSIGNED_FIX
parameter_list|(
name|x
parameter_list|)
value|((unsigned int) (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Scale X by Y powers of 2.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_LDEXP
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_LDEXP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|ldexp (x, y)
end_define

begin_function_decl
specifier|extern
name|double
name|ldexp
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Convert the string X to a floating-point value.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_ATOF
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_ATOF
parameter_list|(
name|x
parameter_list|)
value|atof (x)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MIPSEL
argument_list|)
operator|||
name|defined
argument_list|(
name|MIPSEB
argument_list|)
end_if

begin_comment
comment|/* MIPS compiler can't handle parens around the function name.    This problem *does not* appear to be connected with any    macro definition for atof.  It does not seem there is one.  */
end_comment

begin_function_decl
specifier|extern
name|double
name|atof
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|double
function_decl|(
name|atof
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Negate the floating-point value X.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_NEGATE
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_NEGATE
parameter_list|(
name|x
parameter_list|)
value|(- (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Truncate the floating-point value X to mode MODE.  This is correct only    for the most common case where the host and target have objects of the same    size and where `float' is SFmode.  */
end_comment

begin_comment
comment|/* Don't use REAL_VALUE_TRUNCATE directly--always call real_value_truncate.  */
end_comment

begin_function_decl
specifier|extern
name|REAL_VALUE_TYPE
name|real_value_truncate
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_TRUNCATE
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_TRUNCATE
parameter_list|(
name|mode
parameter_list|,
name|x
parameter_list|)
define|\
value|(GET_MODE_BITSIZE (mode) == sizeof (float) * HOST_BITS_PER_CHAR	\   ? (float) (x) : (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Determine whether a floating-point value X is infinite. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_ISINF
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_ISINF
parameter_list|(
name|x
parameter_list|)
value|(target_isinf (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Determine whether a floating-point value X is a NaN. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_ISNAN
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_ISNAN
parameter_list|(
name|x
parameter_list|)
value|(target_isnan (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Determine whether a floating-point value X is negative. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_NEGATIVE
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_NEGATIVE
parameter_list|(
name|x
parameter_list|)
value|(target_negative (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Determine whether a floating-point value X is minus 0. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_MINUS_ZERO
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_MINUS_ZERO
parameter_list|(
name|x
parameter_list|)
value|((x) == 0&& REAL_VALUE_NEGATIVE (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Constant real values 0, 1, 2, and -1.  */
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
name|dconstm1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Union type used for extracting real values from CONST_DOUBLEs    or putting them in.  */
end_comment

begin_union
union|union
name|real_extract
block|{
name|REAL_VALUE_TYPE
name|d
decl_stmt|;
name|HOST_WIDE_INT
name|i
index|[
sizeof|sizeof
argument_list|(
name|REAL_VALUE_TYPE
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|HOST_WIDE_INT
argument_list|)
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* For a CONST_DOUBLE:    The usual two ints that hold the value.    For a DImode, that is all there are;     and CONST_DOUBLE_LOW is the low-order word and ..._HIGH the high-order.    For a float, the number of ints varies,     and CONST_DOUBLE_LOW is the one that should come first *in memory*.     So use&CONST_DOUBLE_LOW(r) as the address of an array of ints.  */
end_comment

begin_define
define|#
directive|define
name|CONST_DOUBLE_LOW
parameter_list|(
name|r
parameter_list|)
value|XWINT (r, 2)
end_define

begin_define
define|#
directive|define
name|CONST_DOUBLE_HIGH
parameter_list|(
name|r
parameter_list|)
value|XWINT (r, 3)
end_define

begin_comment
comment|/* Link for chain of all CONST_DOUBLEs in use in current function.  */
end_comment

begin_define
define|#
directive|define
name|CONST_DOUBLE_CHAIN
parameter_list|(
name|r
parameter_list|)
value|XEXP (r, 1)
end_define

begin_comment
comment|/* The MEM which represents this CONST_DOUBLE's value in memory,    or const0_rtx if no MEM has been made for it yet,    or cc0_rtx if it is not on the chain.  */
end_comment

begin_define
define|#
directive|define
name|CONST_DOUBLE_MEM
parameter_list|(
name|r
parameter_list|)
value|XEXP (r, 0)
end_define

begin_comment
comment|/* Function to return a real value (not a tree node)    from a given integer constant.  */
end_comment

begin_function_decl
name|REAL_VALUE_TYPE
name|real_value_from_int_cst
parameter_list|()
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
value|do { union real_extract u;				\      bcopy (&CONST_DOUBLE_LOW ((from)),&u, sizeof u);	\      to = u.d; } while (0)
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
value|immed_real_const_1 (r, m)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Not REAL_H_INCLUDED */
end_comment

end_unit

