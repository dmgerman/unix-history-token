begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of floating-point access for GNU compiler.    Copyright (C) 1989, 91, 94, 96-98, 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_define
define|#
directive|define
name|IBM_FLOAT_FORMAT
value|3
end_define

begin_define
define|#
directive|define
name|C4X_FLOAT_FORMAT
value|4
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

begin_comment
comment|/* If FLOAT_WORDS_BIG_ENDIAN and HOST_FLOAT_WORDS_BIG_ENDIAN are not defined    in the header files, then this implies the word-endianness is the same as    for integers.  */
end_comment

begin_comment
comment|/* This is defined 0 or 1, like WORDS_BIG_ENDIAN.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FLOAT_WORDS_BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|FLOAT_WORDS_BIG_ENDIAN
value|WORDS_BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is defined 0 or 1, unlike HOST_WORDS_BIG_ENDIAN.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_FLOAT_WORDS_BIG_ENDIAN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HOST_WORDS_BIG_ENDIAN
end_ifdef

begin_define
define|#
directive|define
name|HOST_FLOAT_WORDS_BIG_ENDIAN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HOST_FLOAT_WORDS_BIG_ENDIAN
value|0
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
comment|/* Defining REAL_ARITHMETIC invokes a floating point emulator    that can produce a target machine format differing by more    than just endian-ness from the host's format.  The emulator    is also used to support extended real XFmode.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LONG_DOUBLE_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|LONG_DOUBLE_TYPE_SIZE
operator|==
literal|96
operator|)
operator|||
operator|(
name|LONG_DOUBLE_TYPE_SIZE
operator|==
literal|128
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_ARITHMETIC
end_ifndef

begin_define
define|#
directive|define
name|REAL_ARITHMETIC
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* **** Start of software floating point emulator interface macros **** */
end_comment

begin_comment
comment|/* Support 80-bit extended real XFmode if LONG_DOUBLE_TYPE_SIZE    has been defined to be 96 in the tm.h machine file. */
end_comment

begin_if
if|#
directive|if
operator|(
name|LONG_DOUBLE_TYPE_SIZE
operator|==
literal|96
operator|)
end_if

begin_define
define|#
directive|define
name|REAL_IS_NOT_DOUBLE
end_define

begin_define
define|#
directive|define
name|REAL_ARITHMETIC
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|HOST_WIDE_INT
name|r
index|[
operator|(
literal|11
operator|+
sizeof|sizeof
argument_list|(
name|HOST_WIDE_INT
argument_list|)
operator|)
operator|/
operator|(
sizeof|sizeof
argument_list|(
name|HOST_WIDE_INT
argument_list|)
operator|)
index|]
decl_stmt|;
block|}
name|realvaluetype
typedef|;
end_typedef

begin_define
define|#
directive|define
name|REAL_VALUE_TYPE
value|realvaluetype
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no XFmode support */
end_comment

begin_if
if|#
directive|if
operator|(
name|LONG_DOUBLE_TYPE_SIZE
operator|==
literal|128
operator|)
end_if

begin_define
define|#
directive|define
name|REAL_IS_NOT_DOUBLE
end_define

begin_define
define|#
directive|define
name|REAL_ARITHMETIC
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|HOST_WIDE_INT
name|r
index|[
operator|(
literal|19
operator|+
sizeof|sizeof
argument_list|(
name|HOST_WIDE_INT
argument_list|)
operator|)
operator|/
operator|(
sizeof|sizeof
argument_list|(
name|HOST_WIDE_INT
argument_list|)
operator|)
index|]
decl_stmt|;
block|}
name|realvaluetype
typedef|;
end_typedef

begin_define
define|#
directive|define
name|REAL_VALUE_TYPE
value|realvaluetype
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not TFmode */
end_comment

begin_if
if|#
directive|if
name|HOST_FLOAT_FORMAT
operator|!=
name|TARGET_FLOAT_FORMAT
end_if

begin_comment
comment|/* If no XFmode support, then a REAL_VALUE_TYPE is 64 bits wide    but it is not necessarily a host machine double. */
end_comment

begin_define
define|#
directive|define
name|REAL_IS_NOT_DOUBLE
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|HOST_WIDE_INT
name|r
index|[
operator|(
literal|7
operator|+
sizeof|sizeof
argument_list|(
name|HOST_WIDE_INT
argument_list|)
operator|)
operator|/
operator|(
sizeof|sizeof
argument_list|(
name|HOST_WIDE_INT
argument_list|)
operator|)
index|]
decl_stmt|;
block|}
name|realvaluetype
typedef|;
end_typedef

begin_define
define|#
directive|define
name|REAL_VALUE_TYPE
value|realvaluetype
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* If host and target formats are compatible, then a REAL_VALUE_TYPE    is actually a host machine double. */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_TYPE
value|double
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
comment|/* no TFmode support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no XFmode support */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|significand_size
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If emulation has been enabled by defining REAL_ARITHMETIC or by    setting LONG_DOUBLE_TYPE_SIZE to 96 or 128, then define macros so that    they invoke emulator functions. This will succeed only if the machine    files have been updated to use these macros in place of any    references to host machine `double' or `float' types.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_undef
undef|#
directive|undef
name|REAL_ARITHMETIC
end_undef

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
value|earith (&(value), (code),&(d1),&(d2))
end_define

begin_comment
comment|/* Declare functions in real.c. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|earith
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|*
operator|,
name|int
operator|,
name|REAL_VALUE_TYPE
operator|*
operator|,
name|REAL_VALUE_TYPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|etrunci
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|etruncui
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|ereal_atof
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|ereal_negate
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|HOST_WIDE_INT
name|efixi
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|HOST_WIDE_INT
name|efixui
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ereal_from_int
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|*
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ereal_from_uint
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|*
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ereal_to_int
name|PROTO
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|*
operator|,
name|HOST_WIDE_INT
operator|*
operator|,
name|REAL_VALUE_TYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|ereal_ldexp
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|etartdouble
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|,
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|etarldouble
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|,
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|etardouble
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|,
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|etarsingle
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ereal_to_decimal
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ereal_cmp
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|,
name|REAL_VALUE_TYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ereal_isneg
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|ereal_unto_float
name|PROTO
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|ereal_unto_double
name|PROTO
argument_list|(
operator|(
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|ereal_from_float
name|PROTO
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|ereal_from_double
name|PROTO
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|REAL_VALUES_EQUAL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(ereal_cmp ((x), (y)) == 0)
end_define

begin_comment
comment|/* true if x< y : */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUES_LESS
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(ereal_cmp ((x), (y)) == -1)
end_define

begin_define
define|#
directive|define
name|REAL_VALUE_LDEXP
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|ereal_ldexp (x, n)
end_define

begin_comment
comment|/* These return REAL_VALUE_TYPE: */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_RNDZINT
parameter_list|(
name|x
parameter_list|)
value|(etrunci (x))
end_define

begin_define
define|#
directive|define
name|REAL_VALUE_UNSIGNED_RNDZINT
parameter_list|(
name|x
parameter_list|)
value|(etruncui (x))
end_define

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|real_value_truncate
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|REAL_VALUE_TYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|REAL_VALUE_TRUNCATE
parameter_list|(
name|mode
parameter_list|,
name|x
parameter_list|)
value|real_value_truncate (mode, x)
end_define

begin_comment
comment|/* These return HOST_WIDE_INT: */
end_comment

begin_comment
comment|/* Convert a floating-point value to integer, rounding toward zero.  */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_FIX
parameter_list|(
name|x
parameter_list|)
value|(efixi (x))
end_define

begin_comment
comment|/* Convert a floating-point value to unsigned integer, rounding    toward zero. */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_UNSIGNED_FIX
parameter_list|(
name|x
parameter_list|)
value|(efixui (x))
end_define

begin_comment
comment|/* Convert ASCII string S to floating point in mode M.    Decimal input uses ATOF.  Hexadecimal uses HTOF.  */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_ATOF
value|ereal_atof
end_define

begin_define
define|#
directive|define
name|REAL_VALUE_HTOF
value|ereal_atof
end_define

begin_define
define|#
directive|define
name|REAL_VALUE_NEGATE
value|ereal_negate
end_define

begin_define
define|#
directive|define
name|REAL_VALUE_MINUS_ZERO
parameter_list|(
name|x
parameter_list|)
define|\
value|((ereal_cmp (x, dconst0) == 0)&& (ereal_isneg (x) != 0 ))
end_define

begin_define
define|#
directive|define
name|REAL_VALUE_TO_INT
value|ereal_to_int
end_define

begin_comment
comment|/* Here the cast to HOST_WIDE_INT sign-extends arguments such as ~0.  */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_FROM_INT
parameter_list|(
name|d
parameter_list|,
name|lo
parameter_list|,
name|hi
parameter_list|,
name|mode
parameter_list|)
define|\
value|ereal_from_int (&d, (HOST_WIDE_INT) (lo), (HOST_WIDE_INT) (hi), mode)
end_define

begin_define
define|#
directive|define
name|REAL_VALUE_FROM_UNSIGNED_INT
parameter_list|(
name|d
parameter_list|,
name|lo
parameter_list|,
name|hi
parameter_list|,
name|mode
parameter_list|)
define|\
value|ereal_from_uint (&d, lo, hi, mode)
end_define

begin_comment
comment|/* IN is a REAL_VALUE_TYPE.  OUT is an array of longs. */
end_comment

begin_if
if|#
directive|if
name|LONG_DOUBLE_TYPE_SIZE
operator|==
literal|96
end_if

begin_define
define|#
directive|define
name|REAL_VALUE_TO_TARGET_LONG_DOUBLE
parameter_list|(
name|IN
parameter_list|,
name|OUT
parameter_list|)
value|(etarldouble ((IN), (OUT)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REAL_VALUE_TO_TARGET_LONG_DOUBLE
parameter_list|(
name|IN
parameter_list|,
name|OUT
parameter_list|)
value|(etartdouble ((IN), (OUT)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|REAL_VALUE_TO_TARGET_DOUBLE
parameter_list|(
name|IN
parameter_list|,
name|OUT
parameter_list|)
value|(etardouble ((IN), (OUT)))
end_define

begin_comment
comment|/* IN is a REAL_VALUE_TYPE.  OUT is a long. */
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
value|((OUT) = etarsingle ((IN)))
end_define

begin_comment
comment|/* Inverse of REAL_VALUE_TO_TARGET_DOUBLE. */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_UNTO_TARGET_DOUBLE
parameter_list|(
name|d
parameter_list|)
value|(ereal_unto_double (d))
end_define

begin_comment
comment|/* Inverse of REAL_VALUE_TO_TARGET_SINGLE. */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_UNTO_TARGET_SINGLE
parameter_list|(
name|f
parameter_list|)
value|(ereal_unto_float (f))
end_define

begin_comment
comment|/* d is an array of HOST_WIDE_INT that holds a double precision    value in the target computer's floating point format. */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_FROM_TARGET_DOUBLE
parameter_list|(
name|d
parameter_list|)
value|(ereal_from_double (d))
end_define

begin_comment
comment|/* f is a HOST_WIDE_INT containing a single precision target float value. */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_FROM_TARGET_SINGLE
parameter_list|(
name|f
parameter_list|)
value|(ereal_from_float (f))
end_define

begin_comment
comment|/* Conversions to decimal ASCII string.  */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_TO_DECIMAL
parameter_list|(
name|r
parameter_list|,
name|fmt
parameter_list|,
name|s
parameter_list|)
value|(ereal_to_decimal (r, s))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REAL_ARITHMETIC defined */
end_comment

begin_comment
comment|/* **** End of software floating point emulator interface macros **** */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* No XFmode or TFmode and REAL_ARITHMETIC not defined */
end_comment

begin_comment
comment|/* old interface */
end_comment

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

begin_typedef
typedef|typedef
struct|struct
block|{
name|HOST_WIDE_INT
name|r
index|[
sizeof|sizeof
argument_list|(
name|double
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|HOST_WIDE_INT
argument_list|)
index|]
decl_stmt|;
block|}
name|realvaluetype
typedef|;
end_typedef

begin_define
define|#
directive|define
name|REAL_VALUE_TYPE
value|realvaluetype
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* emulator not used */
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

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_TO_TARGET_SINGLE
end_ifndef

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
value|do {							\   union {						\     float f;						\     HOST_WIDE_INT l;					\   } u;							\   if (sizeof(HOST_WIDE_INT)< sizeof(float))		\     abort();						\   u.l = 0;						\   u.f = (IN);						\   (OUT) = u.l;						\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Convert a type `double' value in host format to a pair of type `long'    values which is its bitwise equivalent, but put the two words into    proper word order for the target.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_TO_TARGET_DOUBLE
end_ifndef

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
value|do {									\   union {								\     REAL_VALUE_TYPE f;							\     HOST_WIDE_INT l[2];							\   } u;									\   if (sizeof(HOST_WIDE_INT) * 2< sizeof(REAL_VALUE_TYPE))		\     abort();								\   u.l[0] = u.l[1] = 0;							\   u.f = (IN);								\   if (HOST_FLOAT_WORDS_BIG_ENDIAN == FLOAT_WORDS_BIG_ENDIAN)		\     (OUT)[0] = u.l[0], (OUT)[1] = u.l[1];				\   else									\     (OUT)[1] = u.l[0], (OUT)[0] = u.l[1];				\ } while (0)
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
comment|/* In this configuration, double and long double are the same. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_TO_TARGET_LONG_DOUBLE
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_TO_TARGET_LONG_DOUBLE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|REAL_VALUE_TO_TARGET_DOUBLE (a, b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Compare two floating-point objects for bitwise identity.    This is not the same as comparing for equality on IEEE hosts:    -0.0 equals 0.0 but they are not identical, and conversely    two NaNs might be identical but they cannot be equal.  */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUES_IDENTICAL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|(!bcmp ((char *)&(x), (char *)&(y), sizeof (REAL_VALUE_TYPE)))
end_define

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
comment|/* Truncate toward zero to an integer floating-point value.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_RNDZINT
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_RNDZINT
parameter_list|(
name|x
parameter_list|)
value|((double) ((int) (x)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Truncate toward zero to an unsigned integer floating-point value.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_UNSIGNED_RNDZINT
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_UNSIGNED_RNDZINT
parameter_list|(
name|x
parameter_list|)
value|((double) ((unsigned int) (x)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Convert a floating-point value to integer, rounding toward zero.  */
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
comment|/* Convert a floating-point value to unsigned integer, rounding    toward zero. */
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

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|/* Use real.c to convert decimal numbers to binary, ... */
end_comment

begin_function_decl
name|REAL_VALUE_TYPE
name|ereal_atof
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|REAL_VALUE_ATOF
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|)
value|ereal_atof (x, s)
end_define

begin_comment
comment|/* Could use ereal_atof here for hexadecimal floats too, but real_hex_to_f    is OK and it uses faster native fp arithmetic.  */
end_comment

begin_comment
comment|/* #define REAL_VALUE_HTOF(x, s) ereal_atof (x, s) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ... or, if you like the host computer's atof, go ahead and use it: */
end_comment

begin_define
define|#
directive|define
name|REAL_VALUE_ATOF
parameter_list|(
name|x
parameter_list|,
name|s
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Hexadecimal floating constant input for use with host computer's    fp arithmetic.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_HTOF
end_ifndef

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|real_hex_to_f
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|REAL_VALUE_HTOF
parameter_list|(
name|s
parameter_list|,
name|m
parameter_list|)
value|real_hex_to_f(s,m)
end_define

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

begin_decl_stmt
specifier|extern
name|REAL_VALUE_TYPE
name|real_value_truncate
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|REAL_VALUE_TYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|int
name|target_isnan
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|target_isinf
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|target_negative
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/* Given a CONST_DOUBLE in FROM, store into TO the value it represents.  */
end_comment

begin_comment
comment|/* Function to return a real value (not a tree node)    from a given integer constant.  */
end_comment

begin_union_decl
union_decl|union
name|tree_node
union_decl|;
end_union_decl

begin_decl_stmt
name|REAL_VALUE_TYPE
name|real_value_from_int_cst
name|PROTO
argument_list|(
operator|(
expr|union
name|tree_node
operator|*
operator|,
expr|union
name|tree_node
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|do { union real_extract u;				\      bcopy ((char *)&CONST_DOUBLE_LOW ((from)), (char *)&u, sizeof u); \      to = u.d; } while (0)
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
value|immed_real_const_1 (r,  m)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|immed_real_const_1
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Convert a floating point value `r', that can be interpreted    as a host machine float or double, to a decimal ASCII string `s'    using printf format string `fmt'.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_TO_DECIMAL
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_TO_DECIMAL
parameter_list|(
name|r
parameter_list|,
name|fmt
parameter_list|,
name|s
parameter_list|)
value|(sprintf (s, fmt, r))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Replace R by 1/R in the given machine mode, if the result is exact.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|exact_real_inverse
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|REAL_VALUE_TYPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|debug_real
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In varasm.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_real
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Not REAL_H_INCLUDED */
end_comment

end_unit

