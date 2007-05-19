begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for IBM S/390    Copyright (C) 1999, 2000, 2001 Free Software Foundation, Inc.    Contributed by Hartmut Penner (hpenner@de.ibm.com) and                   Ulrich Weigand (uweigand@de.ibm.com).  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixunstfdi
end_ifdef

begin_define
define|#
directive|define
name|EXPD
parameter_list|(
name|fp
parameter_list|)
value|(((fp.l.i[0])>> 16)& 0x7FFF)
end_define

begin_define
define|#
directive|define
name|EXPONENT_BIAS
value|16383
end_define

begin_define
define|#
directive|define
name|MANTISSA_BITS
value|112
end_define

begin_define
define|#
directive|define
name|PRECISION
value|(MANTISSA_BITS + 1)
end_define

begin_define
define|#
directive|define
name|SIGNBIT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SIGND
parameter_list|(
name|fp
parameter_list|)
value|((fp.l.i[0])& SIGNBIT)
end_define

begin_define
define|#
directive|define
name|MANTD_HIGH_LL
parameter_list|(
name|fp
parameter_list|)
value|((fp.ll[0]& HIGH_LL_FRAC_MASK) | HIGH_LL_UNIT_BIT)
end_define

begin_define
define|#
directive|define
name|MANTD_LOW_LL
parameter_list|(
name|fp
parameter_list|)
value|(fp.ll[1])
end_define

begin_define
define|#
directive|define
name|FRACD_ZERO_P
parameter_list|(
name|fp
parameter_list|)
value|(!fp.ll[1]&& !(fp.ll[0]& HIGH_LL_FRAC_MASK))
end_define

begin_define
define|#
directive|define
name|HIGH_LL_FRAC_BITS
value|48
end_define

begin_define
define|#
directive|define
name|HIGH_LL_UNIT_BIT
value|((UDItype_x)1<< HIGH_LL_FRAC_BITS)
end_define

begin_define
define|#
directive|define
name|HIGH_LL_FRAC_MASK
value|(HIGH_LL_UNIT_BIT - 1)
end_define

begin_typedef
typedef|typedef
name|int
name|DItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UDItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|SItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|USItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_union
union|union
name|double_long
block|{
name|long
name|double
name|d
decl_stmt|;
struct|struct
block|{
name|SItype_x
name|i
index|[
literal|4
index|]
decl_stmt|;
comment|/* 32 bit parts: 0 upper ... 3 lowest */
block|}
name|l
struct|;
name|UDItype_x
name|ll
index|[
literal|2
index|]
decl_stmt|;
comment|/* 64 bit parts: 0 upper, 1 lower */
block|}
union|;
end_union

begin_function_decl
name|UDItype_x
name|__fixunstfdi
parameter_list|(
name|long
name|double
name|a1
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* convert double to unsigned int */
end_comment

begin_function
name|UDItype_x
name|__fixunstfdi
parameter_list|(
name|long
name|double
name|a1
parameter_list|)
block|{
specifier|register
name|union
name|double_long
name|dl1
decl_stmt|;
specifier|register
name|int
name|exp
decl_stmt|;
specifier|register
name|UDItype_x
name|l
decl_stmt|;
name|dl1
operator|.
name|d
operator|=
name|a1
expr_stmt|;
comment|/* +/- 0, denormalized, negative */
if|if
condition|(
operator|!
name|EXPD
argument_list|(
name|dl1
argument_list|)
operator|||
name|SIGND
argument_list|(
name|dl1
argument_list|)
condition|)
return|return
literal|0
return|;
comment|/* The exponent - considered the binary point at the right end of         the mantissa.  */
name|exp
operator|=
name|EXPD
argument_list|(
name|dl1
argument_list|)
operator|-
name|EXPONENT_BIAS
operator|-
name|MANTISSA_BITS
expr_stmt|;
comment|/* number< 1: If the mantissa would need to be right-shifted more bits than        its size (plus the implied one bit on the left) the result would be         zero.  */
if|if
condition|(
name|exp
operator|<=
operator|-
name|PRECISION
condition|)
return|return
literal|0
return|;
comment|/* NaN: All exponent bits set and a nonzero fraction.  */
if|if
condition|(
operator|(
name|EXPD
argument_list|(
name|dl1
argument_list|)
operator|==
literal|0x7fff
operator|)
operator|&&
operator|!
name|FRACD_ZERO_P
argument_list|(
name|dl1
argument_list|)
condition|)
return|return
literal|0x0ULL
return|;
comment|/* If the upper ll part of the mantissa isn't        zeroed out after shifting the number would be to large.  */
if|if
condition|(
name|exp
operator|>=
operator|-
name|HIGH_LL_FRAC_BITS
condition|)
return|return
literal|0xFFFFFFFFFFFFFFFFULL
return|;
name|exp
operator|+=
name|HIGH_LL_FRAC_BITS
operator|+
literal|1
expr_stmt|;
name|l
operator|=
name|MANTD_LOW_LL
argument_list|(
name|dl1
argument_list|)
operator|>>
operator|(
name|HIGH_LL_FRAC_BITS
operator|+
literal|1
operator|)
operator||
name|MANTD_HIGH_LL
argument_list|(
name|dl1
argument_list|)
operator|<<
operator|(
literal|64
operator|-
operator|(
name|HIGH_LL_FRAC_BITS
operator|+
literal|1
operator|)
operator|)
expr_stmt|;
return|return
name|l
operator|>>
operator|-
name|exp
return|;
block|}
end_function

begin_define
define|#
directive|define
name|__fixunstfdi
value|___fixunstfdi
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|L_fixunstfdi
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixtfdi
end_ifdef

begin_define
define|#
directive|define
name|EXPD
parameter_list|(
name|fp
parameter_list|)
value|(((fp.l.i[0])>> 16)& 0x7FFF)
end_define

begin_define
define|#
directive|define
name|EXPONENT_BIAS
value|16383
end_define

begin_define
define|#
directive|define
name|MANTISSA_BITS
value|112
end_define

begin_define
define|#
directive|define
name|PRECISION
value|(MANTISSA_BITS + 1)
end_define

begin_define
define|#
directive|define
name|SIGNBIT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SIGND
parameter_list|(
name|fp
parameter_list|)
value|((fp.l.i[0])& SIGNBIT)
end_define

begin_define
define|#
directive|define
name|MANTD_HIGH_LL
parameter_list|(
name|fp
parameter_list|)
value|((fp.ll[0]& HIGH_LL_FRAC_MASK) | HIGH_LL_UNIT_BIT)
end_define

begin_define
define|#
directive|define
name|MANTD_LOW_LL
parameter_list|(
name|fp
parameter_list|)
value|(fp.ll[1])
end_define

begin_define
define|#
directive|define
name|FRACD_ZERO_P
parameter_list|(
name|fp
parameter_list|)
value|(!fp.ll[1]&& !(fp.ll[0]& HIGH_LL_FRAC_MASK))
end_define

begin_define
define|#
directive|define
name|HIGH_LL_FRAC_BITS
value|48
end_define

begin_define
define|#
directive|define
name|HIGH_LL_UNIT_BIT
value|((UDItype_x)1<< HIGH_LL_FRAC_BITS)
end_define

begin_define
define|#
directive|define
name|HIGH_LL_FRAC_MASK
value|(HIGH_LL_UNIT_BIT - 1)
end_define

begin_typedef
typedef|typedef
name|int
name|DItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UDItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|SItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|USItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_union
union|union
name|double_long
block|{
name|long
name|double
name|d
decl_stmt|;
struct|struct
block|{
name|SItype_x
name|i
index|[
literal|4
index|]
decl_stmt|;
comment|/* 32 bit parts: 0 upper ... 3 lowest */
block|}
name|l
struct|;
name|DItype_x
name|ll
index|[
literal|2
index|]
decl_stmt|;
comment|/* 64 bit parts: 0 upper, 1 lower */
block|}
union|;
end_union

begin_function_decl
name|DItype_x
name|__fixtfdi
parameter_list|(
name|long
name|double
name|a1
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* convert double to unsigned int */
end_comment

begin_function
name|DItype_x
name|__fixtfdi
parameter_list|(
name|long
name|double
name|a1
parameter_list|)
block|{
specifier|register
name|union
name|double_long
name|dl1
decl_stmt|;
specifier|register
name|int
name|exp
decl_stmt|;
specifier|register
name|UDItype_x
name|l
decl_stmt|;
name|dl1
operator|.
name|d
operator|=
name|a1
expr_stmt|;
comment|/* +/- 0, denormalized */
if|if
condition|(
operator|!
name|EXPD
argument_list|(
name|dl1
argument_list|)
condition|)
return|return
literal|0
return|;
comment|/* The exponent - considered the binary point at the right end of         the mantissa.  */
name|exp
operator|=
name|EXPD
argument_list|(
name|dl1
argument_list|)
operator|-
name|EXPONENT_BIAS
operator|-
name|MANTISSA_BITS
expr_stmt|;
comment|/* number< 1: If the mantissa would need to be right-shifted more bits than        its size the result would be zero.  */
if|if
condition|(
name|exp
operator|<=
operator|-
name|PRECISION
condition|)
return|return
literal|0
return|;
comment|/* NaN: All exponent bits set and a nonzero fraction.  */
if|if
condition|(
operator|(
name|EXPD
argument_list|(
name|dl1
argument_list|)
operator|==
literal|0x7fff
operator|)
operator|&&
operator|!
name|FRACD_ZERO_P
argument_list|(
name|dl1
argument_list|)
condition|)
return|return
literal|0x8000000000000000ULL
return|;
comment|/* If the upper ll part of the mantissa isn't        zeroed out after shifting the number would be to large.  */
if|if
condition|(
name|exp
operator|>=
operator|-
name|HIGH_LL_FRAC_BITS
condition|)
block|{
name|l
operator|=
operator|(
name|long
name|long
operator|)
literal|1
operator|<<
literal|63
expr_stmt|;
comment|/* long int min */
return|return
name|SIGND
argument_list|(
name|dl1
argument_list|)
condition|?
name|l
else|:
name|l
operator|-
literal|1
return|;
block|}
comment|/* The extra bit is needed for the sign bit.  */
name|exp
operator|+=
name|HIGH_LL_FRAC_BITS
operator|+
literal|1
expr_stmt|;
name|l
operator|=
name|MANTD_LOW_LL
argument_list|(
name|dl1
argument_list|)
operator|>>
operator|(
name|HIGH_LL_FRAC_BITS
operator|+
literal|1
operator|)
operator||
name|MANTD_HIGH_LL
argument_list|(
name|dl1
argument_list|)
operator|<<
operator|(
literal|64
operator|-
operator|(
name|HIGH_LL_FRAC_BITS
operator|+
literal|1
operator|)
operator|)
expr_stmt|;
return|return
name|SIGND
argument_list|(
name|dl1
argument_list|)
condition|?
operator|-
operator|(
name|l
operator|>>
operator|-
name|exp
operator|)
else|:
name|l
operator|>>
operator|-
name|exp
return|;
block|}
end_function

begin_define
define|#
directive|define
name|__fixtfdi
value|___fixtfdi
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|L_fixtfdi
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixunsdfdi
end_ifdef

begin_define
define|#
directive|define
name|EXPD
parameter_list|(
name|fp
parameter_list|)
value|(((fp.l.upper)>> 20)& 0x7FF)
end_define

begin_define
define|#
directive|define
name|EXCESSD
value|1022
end_define

begin_define
define|#
directive|define
name|SIGNBIT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SIGND
parameter_list|(
name|fp
parameter_list|)
value|((fp.l.upper)& SIGNBIT)
end_define

begin_define
define|#
directive|define
name|MANTD_LL
parameter_list|(
name|fp
parameter_list|)
value|((fp.ll& (HIDDEND_LL-1)) | HIDDEND_LL)
end_define

begin_define
define|#
directive|define
name|FRACD_LL
parameter_list|(
name|fp
parameter_list|)
value|(fp.ll& (HIDDEND_LL-1))
end_define

begin_define
define|#
directive|define
name|HIDDEND_LL
value|((UDItype_x)1<< 52)
end_define

begin_typedef
typedef|typedef
name|int
name|DItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UDItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|SItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|USItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_union
union|union
name|double_long
block|{
name|double
name|d
decl_stmt|;
struct|struct
block|{
name|SItype_x
name|upper
decl_stmt|;
name|USItype_x
name|lower
decl_stmt|;
block|}
name|l
struct|;
name|UDItype_x
name|ll
decl_stmt|;
block|}
union|;
end_union

begin_function_decl
name|UDItype_x
name|__fixunsdfdi
parameter_list|(
name|double
name|a1
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* convert double to unsigned int */
end_comment

begin_function
name|UDItype_x
name|__fixunsdfdi
parameter_list|(
name|double
name|a1
parameter_list|)
block|{
specifier|register
name|union
name|double_long
name|dl1
decl_stmt|;
specifier|register
name|int
name|exp
decl_stmt|;
specifier|register
name|UDItype_x
name|l
decl_stmt|;
name|dl1
operator|.
name|d
operator|=
name|a1
expr_stmt|;
comment|/* +/- 0, denormalized, negative */
if|if
condition|(
operator|!
name|EXPD
argument_list|(
name|dl1
argument_list|)
operator|||
name|SIGND
argument_list|(
name|dl1
argument_list|)
condition|)
return|return
literal|0
return|;
name|exp
operator|=
name|EXPD
argument_list|(
name|dl1
argument_list|)
operator|-
name|EXCESSD
operator|-
literal|53
expr_stmt|;
comment|/* number< 1 */
if|if
condition|(
name|exp
operator|<
operator|-
literal|53
condition|)
return|return
literal|0
return|;
comment|/* NaN */
if|if
condition|(
operator|(
name|EXPD
argument_list|(
name|dl1
argument_list|)
operator|==
literal|0x7ff
operator|)
operator|&&
operator|(
name|FRACD_LL
argument_list|(
name|dl1
argument_list|)
operator|!=
literal|0
operator|)
condition|)
comment|/* NaN */
return|return
literal|0x0ULL
return|;
comment|/* Number big number& + inf */
if|if
condition|(
name|exp
operator|>=
literal|12
condition|)
block|{
return|return
literal|0xFFFFFFFFFFFFFFFFULL
return|;
block|}
name|l
operator|=
name|MANTD_LL
argument_list|(
name|dl1
argument_list|)
expr_stmt|;
comment|/* shift down until exp< 12 or l = 0 */
if|if
condition|(
name|exp
operator|>
literal|0
condition|)
name|l
operator|<<=
name|exp
expr_stmt|;
else|else
name|l
operator|>>=
operator|-
name|exp
expr_stmt|;
return|return
name|l
return|;
block|}
end_function

begin_define
define|#
directive|define
name|__fixunsdfdi
value|___fixunsdfdi
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|L_fixunsdfdi
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixdfdi
end_ifdef

begin_define
define|#
directive|define
name|EXPD
parameter_list|(
name|fp
parameter_list|)
value|(((fp.l.upper)>> 20)& 0x7FF)
end_define

begin_define
define|#
directive|define
name|EXCESSD
value|1022
end_define

begin_define
define|#
directive|define
name|SIGNBIT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SIGND
parameter_list|(
name|fp
parameter_list|)
value|((fp.l.upper)& SIGNBIT)
end_define

begin_define
define|#
directive|define
name|MANTD_LL
parameter_list|(
name|fp
parameter_list|)
value|((fp.ll& (HIDDEND_LL-1)) | HIDDEND_LL)
end_define

begin_define
define|#
directive|define
name|FRACD_LL
parameter_list|(
name|fp
parameter_list|)
value|(fp.ll& (HIDDEND_LL-1))
end_define

begin_define
define|#
directive|define
name|HIDDEND_LL
value|((UDItype_x)1<< 52)
end_define

begin_typedef
typedef|typedef
name|int
name|DItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UDItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|SItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|USItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_union
union|union
name|double_long
block|{
name|double
name|d
decl_stmt|;
struct|struct
block|{
name|SItype_x
name|upper
decl_stmt|;
name|USItype_x
name|lower
decl_stmt|;
block|}
name|l
struct|;
name|UDItype_x
name|ll
decl_stmt|;
block|}
union|;
end_union

begin_function_decl
name|DItype_x
name|__fixdfdi
parameter_list|(
name|double
name|a1
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* convert double to int */
end_comment

begin_function
name|DItype_x
name|__fixdfdi
parameter_list|(
name|double
name|a1
parameter_list|)
block|{
specifier|register
name|union
name|double_long
name|dl1
decl_stmt|;
specifier|register
name|int
name|exp
decl_stmt|;
specifier|register
name|DItype_x
name|l
decl_stmt|;
name|dl1
operator|.
name|d
operator|=
name|a1
expr_stmt|;
comment|/* +/- 0, denormalized */
if|if
condition|(
operator|!
name|EXPD
argument_list|(
name|dl1
argument_list|)
condition|)
return|return
literal|0
return|;
name|exp
operator|=
name|EXPD
argument_list|(
name|dl1
argument_list|)
operator|-
name|EXCESSD
operator|-
literal|53
expr_stmt|;
comment|/* number< 1 */
if|if
condition|(
name|exp
operator|<
operator|-
literal|53
condition|)
return|return
literal|0
return|;
comment|/* NaN */
if|if
condition|(
operator|(
name|EXPD
argument_list|(
name|dl1
argument_list|)
operator|==
literal|0x7ff
operator|)
operator|&&
operator|(
name|FRACD_LL
argument_list|(
name|dl1
argument_list|)
operator|!=
literal|0
operator|)
condition|)
comment|/* NaN */
return|return
literal|0x8000000000000000ULL
return|;
comment|/* Number big number& +/- inf */
if|if
condition|(
name|exp
operator|>=
literal|11
condition|)
block|{
name|l
operator|=
operator|(
name|long
name|long
operator|)
literal|1
operator|<<
literal|63
expr_stmt|;
if|if
condition|(
operator|!
name|SIGND
argument_list|(
name|dl1
argument_list|)
condition|)
name|l
operator|--
expr_stmt|;
return|return
name|l
return|;
block|}
name|l
operator|=
name|MANTD_LL
argument_list|(
name|dl1
argument_list|)
expr_stmt|;
comment|/* shift down until exp< 12 or l = 0 */
if|if
condition|(
name|exp
operator|>
literal|0
condition|)
name|l
operator|<<=
name|exp
expr_stmt|;
else|else
name|l
operator|>>=
operator|-
name|exp
expr_stmt|;
return|return
operator|(
name|SIGND
argument_list|(
name|dl1
argument_list|)
condition|?
operator|-
name|l
else|:
name|l
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|__fixdfdi
value|___fixdfdi
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|L_fixdfdi
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixunssfdi
end_ifdef

begin_define
define|#
directive|define
name|EXP
parameter_list|(
name|fp
parameter_list|)
value|(((fp.l)>> 23)& 0xFF)
end_define

begin_define
define|#
directive|define
name|EXCESS
value|126
end_define

begin_define
define|#
directive|define
name|SIGNBIT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SIGN
parameter_list|(
name|fp
parameter_list|)
value|((fp.l)& SIGNBIT)
end_define

begin_define
define|#
directive|define
name|HIDDEN
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|MANT
parameter_list|(
name|fp
parameter_list|)
value|(((fp.l)& 0x7FFFFF) | HIDDEN)
end_define

begin_define
define|#
directive|define
name|FRAC
parameter_list|(
name|fp
parameter_list|)
value|((fp.l)& 0x7FFFFF)
end_define

begin_typedef
typedef|typedef
name|int
name|DItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UDItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|SItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|USItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_union
union|union
name|float_long
block|{
name|float
name|f
decl_stmt|;
name|USItype_x
name|l
decl_stmt|;
block|}
union|;
end_union

begin_function_decl
name|UDItype_x
name|__fixunssfdi
parameter_list|(
name|float
name|a1
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* convert float to unsigned int */
end_comment

begin_function
name|UDItype_x
name|__fixunssfdi
parameter_list|(
name|float
name|a1
parameter_list|)
block|{
specifier|register
name|union
name|float_long
name|fl1
decl_stmt|;
specifier|register
name|int
name|exp
decl_stmt|;
specifier|register
name|UDItype_x
name|l
decl_stmt|;
name|fl1
operator|.
name|f
operator|=
name|a1
expr_stmt|;
comment|/* +/- 0, denormalized, negative */
if|if
condition|(
operator|!
name|EXP
argument_list|(
name|fl1
argument_list|)
operator|||
name|SIGN
argument_list|(
name|fl1
argument_list|)
condition|)
return|return
literal|0
return|;
name|exp
operator|=
name|EXP
argument_list|(
name|fl1
argument_list|)
operator|-
name|EXCESS
operator|-
literal|24
expr_stmt|;
comment|/* number< 1 */
if|if
condition|(
name|exp
operator|<
operator|-
literal|24
condition|)
return|return
literal|0
return|;
comment|/* NaN */
if|if
condition|(
operator|(
name|EXP
argument_list|(
name|fl1
argument_list|)
operator|==
literal|0xff
operator|)
operator|&&
operator|(
name|FRAC
argument_list|(
name|fl1
argument_list|)
operator|!=
literal|0
operator|)
condition|)
comment|/* NaN */
return|return
literal|0x0ULL
return|;
comment|/* Number big number& + inf */
if|if
condition|(
name|exp
operator|>=
literal|41
condition|)
block|{
return|return
literal|0xFFFFFFFFFFFFFFFFULL
return|;
block|}
name|l
operator|=
name|MANT
argument_list|(
name|fl1
argument_list|)
expr_stmt|;
if|if
condition|(
name|exp
operator|>
literal|0
condition|)
name|l
operator|<<=
name|exp
expr_stmt|;
else|else
name|l
operator|>>=
operator|-
name|exp
expr_stmt|;
return|return
name|l
return|;
block|}
end_function

begin_define
define|#
directive|define
name|__fixunssfdi
value|___fixunssfdi
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|L_fixunssfdi
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixsfdi
end_ifdef

begin_define
define|#
directive|define
name|EXP
parameter_list|(
name|fp
parameter_list|)
value|(((fp.l)>> 23)& 0xFF)
end_define

begin_define
define|#
directive|define
name|EXCESS
value|126
end_define

begin_define
define|#
directive|define
name|SIGNBIT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SIGN
parameter_list|(
name|fp
parameter_list|)
value|((fp.l)& SIGNBIT)
end_define

begin_define
define|#
directive|define
name|HIDDEN
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|MANT
parameter_list|(
name|fp
parameter_list|)
value|(((fp.l)& 0x7FFFFF) | HIDDEN)
end_define

begin_define
define|#
directive|define
name|FRAC
parameter_list|(
name|fp
parameter_list|)
value|((fp.l)& 0x7FFFFF)
end_define

begin_typedef
typedef|typedef
name|int
name|DItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UDItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|SItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|USItype_x
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_union
union|union
name|float_long
block|{
name|float
name|f
decl_stmt|;
name|USItype_x
name|l
decl_stmt|;
block|}
union|;
end_union

begin_function_decl
name|DItype_x
name|__fixsfdi
parameter_list|(
name|float
name|a1
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* convert double to int */
end_comment

begin_function
name|DItype_x
name|__fixsfdi
parameter_list|(
name|float
name|a1
parameter_list|)
block|{
specifier|register
name|union
name|float_long
name|fl1
decl_stmt|;
specifier|register
name|int
name|exp
decl_stmt|;
specifier|register
name|DItype_x
name|l
decl_stmt|;
name|fl1
operator|.
name|f
operator|=
name|a1
expr_stmt|;
comment|/* +/- 0, denormalized */
if|if
condition|(
operator|!
name|EXP
argument_list|(
name|fl1
argument_list|)
condition|)
return|return
literal|0
return|;
name|exp
operator|=
name|EXP
argument_list|(
name|fl1
argument_list|)
operator|-
name|EXCESS
operator|-
literal|24
expr_stmt|;
comment|/* number< 1 */
if|if
condition|(
name|exp
operator|<
operator|-
literal|24
condition|)
return|return
literal|0
return|;
comment|/* NaN */
if|if
condition|(
operator|(
name|EXP
argument_list|(
name|fl1
argument_list|)
operator|==
literal|0xff
operator|)
operator|&&
operator|(
name|FRAC
argument_list|(
name|fl1
argument_list|)
operator|!=
literal|0
operator|)
condition|)
comment|/* NaN */
return|return
literal|0x8000000000000000ULL
return|;
comment|/* Number big number& +/- inf */
if|if
condition|(
name|exp
operator|>=
literal|40
condition|)
block|{
name|l
operator|=
operator|(
name|long
name|long
operator|)
literal|1
operator|<<
literal|63
expr_stmt|;
if|if
condition|(
operator|!
name|SIGN
argument_list|(
name|fl1
argument_list|)
condition|)
name|l
operator|--
expr_stmt|;
return|return
name|l
return|;
block|}
name|l
operator|=
name|MANT
argument_list|(
name|fl1
argument_list|)
expr_stmt|;
if|if
condition|(
name|exp
operator|>
literal|0
condition|)
name|l
operator|<<=
name|exp
expr_stmt|;
else|else
name|l
operator|>>=
operator|-
name|exp
expr_stmt|;
return|return
operator|(
name|SIGN
argument_list|(
name|fl1
argument_list|)
condition|?
operator|-
name|l
else|:
name|l
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|__fixsfdi
value|___fixsfdi
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|L_fixsfdi
end_undef

end_unit

