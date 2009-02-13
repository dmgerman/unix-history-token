begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Decimal Number module header for the decNumber C Library    Copyright (C) 2005 Free Software Foundation, Inc.    Contributed by IBM Corporation.  Author Mike Cowlishaw.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it under    the terms of the GNU General Public License as published by the Free    Software Foundation; either version 2, or (at your option) any later    version.     In addition to the permissions in the GNU General Public License,    the Free Software Foundation gives you unlimited permission to link    the compiled version of this file into combinations with other    programs, and to distribute those combinations without any    restriction coming from the use of this file.  (The General Public    License restrictions do apply in other respects; for example, they    cover modification of the file, and distribution when not linked    into a combine executable.)     GCC is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DECNUMBER
argument_list|)
end_if

begin_define
define|#
directive|define
name|DECNUMBER
end_define

begin_define
define|#
directive|define
name|DECNAME
value|"decNumber"
end_define

begin_comment
comment|/* Short name */
end_comment

begin_define
define|#
directive|define
name|DECVERSION
value|"decNumber 3.24"
end_define

begin_comment
comment|/* Version [16 max.] */
end_comment

begin_define
define|#
directive|define
name|DECFULLNAME
value|"Decimal Number Module"
end_define

begin_comment
comment|/* Verbose name */
end_comment

begin_define
define|#
directive|define
name|DECAUTHOR
value|"Mike Cowlishaw"
end_define

begin_comment
comment|/* Who to blame */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DECCONTEXT
argument_list|)
end_if

begin_include
include|#
directive|include
file|"decContext.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Bit settings for decNumber.bits */
end_comment

begin_define
define|#
directive|define
name|DECNEG
value|0x80
end_define

begin_comment
comment|/* Sign; 1=negative, 0=positive or zero */
end_comment

begin_define
define|#
directive|define
name|DECINF
value|0x40
end_define

begin_comment
comment|/* 1=Infinity */
end_comment

begin_define
define|#
directive|define
name|DECNAN
value|0x20
end_define

begin_comment
comment|/* 1=NaN */
end_comment

begin_define
define|#
directive|define
name|DECSNAN
value|0x10
end_define

begin_comment
comment|/* 1=sNaN */
end_comment

begin_comment
comment|/* The remaining bits are reserved; they must be 0 */
end_comment

begin_define
define|#
directive|define
name|DECSPECIAL
value|(DECINF|DECNAN|DECSNAN)
end_define

begin_comment
comment|/* any special value */
end_comment

begin_comment
comment|/* DECNUMDIGITS is the default number of digits we can hold in the */
end_comment

begin_comment
comment|/* structure.  If undefined, 1 is assumed and it is assumed that the */
end_comment

begin_comment
comment|/* structure will be immediately followed by extra space (if */
end_comment

begin_comment
comment|/* required).  DECNUMDIGITS is always>0. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DECNUMDIGITS
argument_list|)
end_if

begin_define
define|#
directive|define
name|DECNUMDIGITS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the decNumber data structure.  The size and shape of the */
end_comment

begin_comment
comment|/* units array in the structure is determined by the following */
end_comment

begin_comment
comment|/* constant.  This must not be changed without recompiling the */
end_comment

begin_comment
comment|/* decNumber library modules. */
end_comment

begin_define
define|#
directive|define
name|DECDPUN
value|4
end_define

begin_comment
comment|/* Decimal Digits Per UNit [must be in */
end_comment

begin_comment
comment|/* range 1-9; power of 2 recommended]. */
end_comment

begin_comment
comment|/* The size (integer data type) of each unit is determined by the */
end_comment

begin_comment
comment|/* number of digits it will hold. */
end_comment

begin_if
if|#
directive|if
name|DECDPUN
operator|<=
literal|2
end_if

begin_define
define|#
directive|define
name|decNumberUnit
value|uint8_t
end_define

begin_elif
elif|#
directive|elif
name|DECDPUN
operator|<=
literal|4
end_elif

begin_define
define|#
directive|define
name|decNumberUnit
value|uint16_t
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|decNumberUnit
value|uint32_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The number of decNumberUnits we need is ceiling of DECNUMDIGITS/DECDPUN */
end_comment

begin_define
define|#
directive|define
name|DECNUMUNITS
value|((DECNUMDIGITS+DECDPUN-1)/DECDPUN)
end_define

begin_comment
comment|/* The data structure... */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int32_t
name|digits
decl_stmt|;
comment|/* Count of digits in the coefficient;>0 */
name|int32_t
name|exponent
decl_stmt|;
comment|/* Unadjusted exponent, unbiased, in */
comment|/* range: -1999999997 through 999999999 */
name|uint8_t
name|bits
decl_stmt|;
comment|/* Indicator bits (see above) */
name|decNumberUnit
name|lsu
index|[
name|DECNUMUNITS
index|]
decl_stmt|;
comment|/* Coefficient, from least significant unit */
block|}
name|decNumber
typedef|;
end_typedef

begin_comment
comment|/* Notes: */
end_comment

begin_comment
comment|/* 1. If digits is> DECDPUN then there will be more than one */
end_comment

begin_comment
comment|/*    decNumberUnits immediately following the first element of lsu. */
end_comment

begin_comment
comment|/*    These contain the remaining (more significant) digits of the */
end_comment

begin_comment
comment|/*    number, and may be in the lsu array, or may be guaranteed by */
end_comment

begin_comment
comment|/*    some other mechanism (such as being contained in another */
end_comment

begin_comment
comment|/*    structure, or being overlaid on dynamically allocated storage). */
end_comment

begin_comment
comment|/* */
end_comment

begin_comment
comment|/*    Each integer of the coefficient (except the possibly the last) */
end_comment

begin_comment
comment|/*    contains DECDPUN digits (e.g., a value in the range 0 through */
end_comment

begin_comment
comment|/*    99999999 if DECDPUN is 8, or 0 through 9999 if DECDPUN is 4). */
end_comment

begin_comment
comment|/* */
end_comment

begin_comment
comment|/* 2. A decNumber converted to a string may need up to digits+14 */
end_comment

begin_comment
comment|/*    characters.  The worst cases (non-exponential and exponential */
end_comment

begin_comment
comment|/*    formats) are: -0.00000{9...}# */
end_comment

begin_comment
comment|/*             and: -9.{9...}E+999999999#   (where # is '\0') */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumber public functions and macros                              */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IN_LIBGCC2
end_ifdef

begin_define
define|#
directive|define
name|decNumberFromString
value|__decNumberFromString
end_define

begin_define
define|#
directive|define
name|decNumberToString
value|__decNumberToString
end_define

begin_define
define|#
directive|define
name|decNumberToEngString
value|__decNumberToEngString
end_define

begin_define
define|#
directive|define
name|decNumberAbs
value|__decNumberAbs
end_define

begin_define
define|#
directive|define
name|decNumberAdd
value|__decNumberAdd
end_define

begin_define
define|#
directive|define
name|decNumberCompare
value|__decNumberCompare
end_define

begin_define
define|#
directive|define
name|decNumberDivide
value|__decNumberDivide
end_define

begin_define
define|#
directive|define
name|decNumberDivideInteger
value|__decNumberDivideInteger
end_define

begin_define
define|#
directive|define
name|decNumberMax
value|__decNumberMax
end_define

begin_define
define|#
directive|define
name|decNumberMin
value|__decNumberMin
end_define

begin_define
define|#
directive|define
name|decNumberMinus
value|__decNumberMinus
end_define

begin_define
define|#
directive|define
name|decNumberMultiply
value|__decNumberMultiply
end_define

begin_define
define|#
directive|define
name|decNumberNormalize
value|__decNumberNormalize
end_define

begin_define
define|#
directive|define
name|decNumberPlus
value|__decNumberPlus
end_define

begin_define
define|#
directive|define
name|decNumberPower
value|__decNumberPower
end_define

begin_define
define|#
directive|define
name|decNumberQuantize
value|__decNumberQuantize
end_define

begin_define
define|#
directive|define
name|decNumberRemainder
value|__decNumberRemainder
end_define

begin_define
define|#
directive|define
name|decNumberRemainderNear
value|__decNumberRemainderNear
end_define

begin_define
define|#
directive|define
name|decNumberRescale
value|__decNumberRescale
end_define

begin_define
define|#
directive|define
name|decNumberSameQuantum
value|__decNumberSameQuantum
end_define

begin_define
define|#
directive|define
name|decNumberSquareRoot
value|__decNumberSquareRoot
end_define

begin_define
define|#
directive|define
name|decNumberSubtract
value|__decNumberSubtract
end_define

begin_define
define|#
directive|define
name|decNumberToIntegralValue
value|__decNumberToIntegralValue
end_define

begin_define
define|#
directive|define
name|decNumberCopy
value|__decNumberCopy
end_define

begin_define
define|#
directive|define
name|decNumberTrim
value|__decNumberTrim
end_define

begin_define
define|#
directive|define
name|decNumberVersion
value|__decNumberVersion
end_define

begin_define
define|#
directive|define
name|decNumberZero
value|__decNumberZero
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Conversions */
end_comment

begin_function_decl
name|decNumber
modifier|*
name|decNumberFromString
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|decNumberToString
parameter_list|(
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|decNumberToEngString
parameter_list|(
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Operators */
end_comment

begin_function_decl
name|decNumber
modifier|*
name|decNumberAbs
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberAdd
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberCompare
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberDivide
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberDivideInteger
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberMax
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberMin
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberMinus
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberMultiply
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberNormalize
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberPlus
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberPower
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberQuantize
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberRemainder
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberRemainderNear
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberRescale
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberSameQuantum
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberSquareRoot
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberSubtract
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberToIntegralValue
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Utilities */
end_comment

begin_function_decl
name|decNumber
modifier|*
name|decNumberCopy
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
specifier|const
name|decNumber
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberTrim
parameter_list|(
name|decNumber
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|decNumberVersion
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decNumber
modifier|*
name|decNumberZero
parameter_list|(
name|decNumber
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Macros */
end_comment

begin_define
define|#
directive|define
name|decNumberIsZero
parameter_list|(
name|dn
parameter_list|)
value|(*(dn)->lsu==0 \&& (dn)->digits==1 \&& (((dn)->bits&DECSPECIAL)==0))
end_define

begin_define
define|#
directive|define
name|decNumberIsNegative
parameter_list|(
name|dn
parameter_list|)
value|(((dn)->bits&DECNEG)!=0)
end_define

begin_define
define|#
directive|define
name|decNumberIsNaN
parameter_list|(
name|dn
parameter_list|)
value|(((dn)->bits&(DECNAN|DECSNAN))!=0)
end_define

begin_define
define|#
directive|define
name|decNumberIsInfinite
parameter_list|(
name|dn
parameter_list|)
value|(((dn)->bits&DECINF)!=0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

