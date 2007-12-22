begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Decimal Number module for the decNumber C Library    Copyright (C) 2005 Free Software Foundation, Inc.    Contributed by IBM Corporation.  Author Mike Cowlishaw.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it under    the terms of the GNU General Public License as published by the Free    Software Foundation; either version 2, or (at your option) any later    version.     In addition to the permissions in the GNU General Public License,    the Free Software Foundation gives you unlimited permission to link    the compiled version of this file into combinations with other    programs, and to distribute those combinations without any    restriction coming from the use of this file.  (The General Public    License restrictions do apply in other respects; for example, they    cover modification of the file, and distribution when not linked    into a combine executable.)     GCC is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* This module comprises the routines for Standard Decimal Arithmetic */
end_comment

begin_comment
comment|/* as defined in the specification which may be found on the          */
end_comment

begin_comment
comment|/* http://www2.hursley.ibm.com/decimal web pages.  It implements both */
end_comment

begin_comment
comment|/* the full ('extended') arithmetic and the simpler ('subset')        */
end_comment

begin_comment
comment|/* arithmetic.                                                        */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* Usage notes:                                                       */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* 1. This code is ANSI C89 except:                                   */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*    a) Line comments (double forward slash) are used.  (Most C      */
end_comment

begin_comment
comment|/*       compilers accept these.  If yours does not, a simple script  */
end_comment

begin_comment
comment|/*       can be used to convert them to ANSI C comments.)             */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*    b) Types from C99 stdint.h are used.  If you do not have this   */
end_comment

begin_comment
comment|/*       header file, see the User's Guide section of the decNumber   */
end_comment

begin_comment
comment|/*       documentation; this lists the necessary definitions.         */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*    c) If DECDPUN>4, non-ANSI 64-bit 'long long' types are used.    */
end_comment

begin_comment
comment|/*       To avoid these, set DECDPUN<= 4 (see documentation).        */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* 2. The decNumber format which this library uses is optimized for   */
end_comment

begin_comment
comment|/*    efficient processing of relatively short numbers; in particular */
end_comment

begin_comment
comment|/*    it allows the use of fixed sized structures and minimizes copy  */
end_comment

begin_comment
comment|/*    and move operations.  It does, however, support arbitrary       */
end_comment

begin_comment
comment|/*    precision (up to 999,999,999 digits) and arbitrary exponent     */
end_comment

begin_comment
comment|/*    range (Emax in the range 0 through 999,999,999 and Emin in the  */
end_comment

begin_comment
comment|/*    range -999,999,999 through 0).                                  */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* 3. Operands to operator functions are never modified unless they   */
end_comment

begin_comment
comment|/*    are also specified to be the result number (which is always     */
end_comment

begin_comment
comment|/*    permitted).  Other than that case, operands may not overlap.    */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* 4. Error handling: the type of the error is ORed into the status   */
end_comment

begin_comment
comment|/*    flags in the current context (decContext structure).  The       */
end_comment

begin_comment
comment|/*    SIGFPE signal is then raised if the corresponding trap-enabler  */
end_comment

begin_comment
comment|/*    flag in the decContext is set (is 1).                           */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*    It is the responsibility of the caller to clear the status      */
end_comment

begin_comment
comment|/*    flags as required.                                              */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*    The result of any routine which returns a number will always    */
end_comment

begin_comment
comment|/*    be a valid number (which may be a special value, such as an     */
end_comment

begin_comment
comment|/*    Infinity or NaN).                                               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* 5. The decNumber format is not an exchangeable concrete            */
end_comment

begin_comment
comment|/*    representation as it comprises fields which may be machine-     */
end_comment

begin_comment
comment|/*    dependent (big-endian or little-endian, for example).           */
end_comment

begin_comment
comment|/*    Canonical conversions to and from strings are provided; other   */
end_comment

begin_comment
comment|/*    conversions are available in separate modules.                  */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* 6. Normally, input operands are assumed to be valid.  Set DECCHECK */
end_comment

begin_comment
comment|/*    to 1 for extended operand checking (including NULL operands).   */
end_comment

begin_comment
comment|/*    Results are undefined if a badly-formed structure (or a NULL    */
end_comment

begin_comment
comment|/*    NULL pointer to a structure) is provided, though with DECCHECK  */
end_comment

begin_comment
comment|/*    enabled the operator routines are protected against exceptions. */
end_comment

begin_comment
comment|/*    (Except if the result pointer is NULL, which is unrecoverable.) */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*    However, the routines will never cause exceptions if they are   */
end_comment

begin_comment
comment|/*    given well-formed operands, even if the value of the operands   */
end_comment

begin_comment
comment|/*    is inappropriate for the operation and DECCHECK is not set.     */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* 7. Subset arithmetic is available only if DECSUBSET is set to 1.   */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Implementation notes for maintenance of this module:               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* 1. Storage leak protection:  Routines which use malloc are not     */
end_comment

begin_comment
comment|/*    permitted to use return for fastpath or error exits (i.e.,      */
end_comment

begin_comment
comment|/*    they follow strict structured programming conventions).         */
end_comment

begin_comment
comment|/*    Instead they have a do{}while(0); construct surrounding the     */
end_comment

begin_comment
comment|/*    code which is protected -- break may be used from this.         */
end_comment

begin_comment
comment|/*    Other routines are allowed to use the return statement inline.  */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*    Storage leak accounting can be enabled using DECALLOC.          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* 2. All loops use the for(;;) construct.  Any do construct is for   */
end_comment

begin_comment
comment|/*    protection as just described.                                   */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* 3. Setting status in the context must always be the very last      */
end_comment

begin_comment
comment|/*    action in a routine, as non-0 status may raise a trap and hence */
end_comment

begin_comment
comment|/*    the call to set status may not return (if the handler uses long */
end_comment

begin_comment
comment|/*    jump).  Therefore all cleanup must be done first.  In general,  */
end_comment

begin_comment
comment|/*    to achieve this we accumulate status and only finally apply it  */
end_comment

begin_comment
comment|/*    by calling decContextSetStatus (via decStatus).                 */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*    Routines which allocate storage cannot, therefore, use the      */
end_comment

begin_comment
comment|/*    'top level' routines which could cause a non-returning          */
end_comment

begin_comment
comment|/*    transfer of control.  The decXxxxOp routines are safe (do not   */
end_comment

begin_comment
comment|/*    call decStatus even if traps are set in the context) and should */
end_comment

begin_comment
comment|/*    be used instead (they are also a little faster).                */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* 4. Exponent checking is minimized by allowing the exponent to      */
end_comment

begin_comment
comment|/*    grow outside its limits during calculations, provided that      */
end_comment

begin_comment
comment|/*    the decFinalize function is called later.  Multiplication and   */
end_comment

begin_comment
comment|/*    division, and intermediate calculations in exponentiation,      */
end_comment

begin_comment
comment|/*    require more careful checks because of the risk of 31-bit       */
end_comment

begin_comment
comment|/*    overflow (the most negative valid exponent is -1999999997, for  */
end_comment

begin_comment
comment|/*    a 999999999-digit number with adjusted exponent of -999999999). */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* 5. Rounding is deferred until finalization of results, with any    */
end_comment

begin_comment
comment|/*    'off to the right' data being represented as a single digit     */
end_comment

begin_comment
comment|/*    residue (in the range -1 through 9).  This avoids any double-   */
end_comment

begin_comment
comment|/*    rounding when more than one shortening takes place (for         */
end_comment

begin_comment
comment|/*    example, when a result is subnormal).                           */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* 6. The digits count is allowed to rise to a multiple of DECDPUN    */
end_comment

begin_comment
comment|/*    during many operations, so whole Units are handled and exact    */
end_comment

begin_comment
comment|/*    accounting of digits is not needed.  The correct digits value   */
end_comment

begin_comment
comment|/*    is found by decGetDigits, which accounts for leading zeros.     */
end_comment

begin_comment
comment|/*    This must be called before any rounding if the number of digits */
end_comment

begin_comment
comment|/*    is not known exactly.                                           */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* 7. We use the multiply-by-reciprocal 'trick' for partitioning      */
end_comment

begin_comment
comment|/*    numbers up to four digits, using appropriate constants.  This   */
end_comment

begin_comment
comment|/*    is not useful for longer numbers because overflow of 32 bits    */
end_comment

begin_comment
comment|/*    would lead to 4 multiplies, which is almost as expensive as     */
end_comment

begin_comment
comment|/*    a divide (unless we assumed floating-point multiply available). */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* 8. Unusual abbreviations possibly used in the commentary:          */
end_comment

begin_comment
comment|/*      lhs -- left hand side (operand, of an operation)              */
end_comment

begin_comment
comment|/*      lsd -- least significant digit (of coefficient)               */
end_comment

begin_comment
comment|/*      lsu -- least significant Unit (of coefficient)                */
end_comment

begin_comment
comment|/*      msd -- most significant digit (of coefficient)                */
end_comment

begin_comment
comment|/*      msu -- most significant Unit (of coefficient)                 */
end_comment

begin_comment
comment|/*      rhs -- right hand side (operand, of an operation)             */
end_comment

begin_comment
comment|/*      +ve -- positive                                               */
end_comment

begin_comment
comment|/*      -ve -- negative                                               */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Some of glibc's string inlines cause warnings.  Plus we'd rather    rely on (and therefore test) GCC's string builtins.  */
end_comment

begin_define
define|#
directive|define
name|__NO_STRING_INLINES
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* for malloc, free, etc. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* for printf [if needed] */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* for strcpy */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_comment
comment|/* for lower */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"decNumber.h"
end_include

begin_comment
comment|/* base number library */
end_comment

begin_include
include|#
directive|include
file|"decNumberLocal.h"
end_include

begin_comment
comment|/* decNumber local types, etc. */
end_comment

begin_comment
comment|/* Constants */
end_comment

begin_comment
comment|/* Public constant array: powers of ten (powers[n]==10**n) */
end_comment

begin_decl_stmt
specifier|const
name|uInt
name|powers
index|[]
init|=
block|{
literal|1
block|,
literal|10
block|,
literal|100
block|,
literal|1000
block|,
literal|10000
block|,
literal|100000
block|,
literal|1000000
block|,
literal|10000000
block|,
literal|100000000
block|,
literal|1000000000
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Local constants */
end_comment

begin_define
define|#
directive|define
name|DIVIDE
value|0x80
end_define

begin_comment
comment|/* Divide operators */
end_comment

begin_define
define|#
directive|define
name|REMAINDER
value|0x40
end_define

begin_comment
comment|/* .. */
end_comment

begin_define
define|#
directive|define
name|DIVIDEINT
value|0x20
end_define

begin_comment
comment|/* .. */
end_comment

begin_define
define|#
directive|define
name|REMNEAR
value|0x10
end_define

begin_comment
comment|/* .. */
end_comment

begin_define
define|#
directive|define
name|COMPARE
value|0x01
end_define

begin_comment
comment|/* Compare operators */
end_comment

begin_define
define|#
directive|define
name|COMPMAX
value|0x02
end_define

begin_comment
comment|/* .. */
end_comment

begin_define
define|#
directive|define
name|COMPMIN
value|0x03
end_define

begin_comment
comment|/* .. */
end_comment

begin_define
define|#
directive|define
name|COMPNAN
value|0x04
end_define

begin_comment
comment|/* .. [NaN processing] */
end_comment

begin_define
define|#
directive|define
name|DEC_sNaN
value|0x40000000
end_define

begin_comment
comment|/* local status: sNaN signal */
end_comment

begin_define
define|#
directive|define
name|BADINT
value|(Int)0x80000000
end_define

begin_comment
comment|/* most-negative Int; error indicator */
end_comment

begin_decl_stmt
specifier|static
name|Unit
name|one
index|[]
init|=
block|{
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Unit array of 1, used for incrementing */
end_comment

begin_comment
comment|/* Granularity-dependent code */
end_comment

begin_if
if|#
directive|if
name|DECDPUN
operator|<=
literal|4
end_if

begin_define
define|#
directive|define
name|eInt
value|Int
end_define

begin_comment
comment|/* extended integer */
end_comment

begin_define
define|#
directive|define
name|ueInt
value|uInt
end_define

begin_comment
comment|/* unsigned extended integer */
end_comment

begin_comment
comment|/* Constant multipliers for divide-by-power-of five using reciprocal */
end_comment

begin_comment
comment|/* multiply, after removing powers of 2 by shifting, and final shift */
end_comment

begin_comment
comment|/* of 17 [we only need up to **4] */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|uInt
name|multies
index|[]
init|=
block|{
literal|131073
block|,
literal|26215
block|,
literal|5243
block|,
literal|1049
block|,
literal|210
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* QUOT10 -- macro to return the quotient of unit u divided by 10**n */
end_comment

begin_define
define|#
directive|define
name|QUOT10
parameter_list|(
name|u
parameter_list|,
name|n
parameter_list|)
value|((((uInt)(u)>>(n))*multies[n])>>17)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* For DECDPUN>4 we currently use non-ANSI 64-bit types.  These could */
end_comment

begin_comment
comment|/* be replaced by subroutine calls later. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|long
end_ifdef

begin_undef
undef|#
directive|undef
name|long
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|signed
name|long
name|long
name|Long
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|uLong
typedef|;
end_typedef

begin_define
define|#
directive|define
name|eInt
value|Long
end_define

begin_comment
comment|/* extended integer */
end_comment

begin_define
define|#
directive|define
name|ueInt
value|uLong
end_define

begin_comment
comment|/* unsigned extended integer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Local routines */
end_comment

begin_function_decl
specifier|static
name|decNumber
modifier|*
name|decAddOp
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
parameter_list|,
name|uByte
parameter_list|,
name|uInt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|decApplyRound
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|,
name|Int
parameter_list|,
name|uInt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|Int
name|decCompare
parameter_list|(
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|decNumber
modifier|*
name|decCompareOp
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
parameter_list|,
name|Flag
parameter_list|,
name|uInt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|decCopyFit
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
parameter_list|,
name|Int
modifier|*
parameter_list|,
name|uInt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|decNumber
modifier|*
name|decDivideOp
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
parameter_list|,
name|Flag
parameter_list|,
name|uInt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|decFinalize
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|,
name|Int
modifier|*
parameter_list|,
name|uInt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|Int
name|decGetDigits
parameter_list|(
specifier|const
name|Unit
modifier|*
parameter_list|,
name|Int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|DECSUBSET
end_if

begin_function_decl
specifier|static
name|Int
name|decGetInt
parameter_list|(
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|static
name|Int
name|decGetInt
parameter_list|(
specifier|const
name|decNumber
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|decNumber
modifier|*
name|decMultiplyOp
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
parameter_list|,
name|uInt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|decNumber
modifier|*
name|decNaNs
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
name|uInt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|decNumber
modifier|*
name|decQuantizeOp
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
parameter_list|,
name|Flag
parameter_list|,
name|uInt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|decSetCoeff
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|,
specifier|const
name|Unit
modifier|*
parameter_list|,
name|Int
parameter_list|,
name|Int
modifier|*
parameter_list|,
name|uInt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|decSetOverflow
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|,
name|uInt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|decSetSubnormal
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|,
name|Int
modifier|*
parameter_list|,
name|uInt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|Int
name|decShiftToLeast
parameter_list|(
name|Unit
modifier|*
parameter_list|,
name|Int
parameter_list|,
name|Int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|Int
name|decShiftToMost
parameter_list|(
name|Unit
modifier|*
parameter_list|,
name|Int
parameter_list|,
name|Int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|decStatus
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
name|uInt
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|Flag
name|decStrEq
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|decToString
parameter_list|(
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|char
index|[]
parameter_list|,
name|Flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|decNumber
modifier|*
name|decTrim
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
name|Flag
parameter_list|,
name|Int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|Int
name|decUnitAddSub
parameter_list|(
specifier|const
name|Unit
modifier|*
parameter_list|,
name|Int
parameter_list|,
specifier|const
name|Unit
modifier|*
parameter_list|,
name|Int
parameter_list|,
name|Int
parameter_list|,
name|Unit
modifier|*
parameter_list|,
name|Int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|Int
name|decUnitCompare
parameter_list|(
specifier|const
name|Unit
modifier|*
parameter_list|,
name|Int
parameter_list|,
specifier|const
name|Unit
modifier|*
parameter_list|,
name|Int
parameter_list|,
name|Int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|!
name|DECSUBSET
end_if

begin_comment
comment|/* decFinish == decFinalize when no subset arithmetic needed */
end_comment

begin_define
define|#
directive|define
name|decFinish
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|decFinalize(a,b,c,d)
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|static
name|void
name|decFinish
parameter_list|(
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|,
name|Int
modifier|*
parameter_list|,
name|uInt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|decNumber
modifier|*
name|decRoundOperand
parameter_list|(
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|,
name|uInt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Diagnostic macros, etc. */
end_comment

begin_if
if|#
directive|if
name|DECALLOC
end_if

begin_comment
comment|/* Handle malloc/free accounting.  If enabled, our accountable routines */
end_comment

begin_comment
comment|/* are used; otherwise the code just goes straight to the system malloc */
end_comment

begin_comment
comment|/* and free routines. */
end_comment

begin_define
define|#
directive|define
name|malloc
parameter_list|(
name|a
parameter_list|)
value|decMalloc(a)
end_define

begin_define
define|#
directive|define
name|free
parameter_list|(
name|a
parameter_list|)
value|decFree(a)
end_define

begin_define
define|#
directive|define
name|DECFENCE
value|0x5a
end_define

begin_comment
comment|/* corruption detector */
end_comment

begin_comment
comment|/* 'Our' malloc and free: */
end_comment

begin_function_decl
specifier|static
name|void
modifier|*
name|decMalloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|decFree
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|uInt
name|decAllocBytes
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count of bytes allocated */
end_comment

begin_comment
comment|/* Note that DECALLOC code only checks for storage buffer overflow. */
end_comment

begin_comment
comment|/* To check for memory leaks, the decAllocBytes variable should be */
end_comment

begin_comment
comment|/* checked to be 0 at appropriate times (e.g., after the test */
end_comment

begin_comment
comment|/* harness completes a set of tests).  This checking may be unreliable */
end_comment

begin_comment
comment|/* if the testing is done in a multi-thread environment. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|DECCHECK
end_if

begin_comment
comment|/* Optional operand checking routines.  Enabling these means that */
end_comment

begin_comment
comment|/* decNumber and decContext operands to operator routines are checked */
end_comment

begin_comment
comment|/* for correctness.  This roughly doubles the execution time of the */
end_comment

begin_comment
comment|/* fastest routines (and adds 600+ bytes), so should not normally be */
end_comment

begin_comment
comment|/* used in 'production'. */
end_comment

begin_define
define|#
directive|define
name|DECUNUSED
value|(void *)(0xffffffff)
end_define

begin_function_decl
specifier|static
name|Flag
name|decCheckOperands
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
specifier|static
name|Flag
name|decCheckNumber
parameter_list|(
specifier|const
name|decNumber
modifier|*
parameter_list|,
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|DECTRACE
operator|||
name|DECCHECK
end_if

begin_comment
comment|/* Optional trace/debugging routines. */
end_comment

begin_function_decl
name|void
name|decNumberShow
parameter_list|(
specifier|const
name|decNumber
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* displays the components of a number */
end_comment

begin_function_decl
specifier|static
name|void
name|decDumpAr
parameter_list|(
name|char
parameter_list|,
specifier|const
name|Unit
modifier|*
parameter_list|,
name|Int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ================================================================== */
end_comment

begin_comment
comment|/* Conversions                                                        */
end_comment

begin_comment
comment|/* ================================================================== */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* to-scientific-string -- conversion to numeric string               */
end_comment

begin_comment
comment|/* to-engineering-string -- conversion to numeric string              */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   decNumberToString(dn, string);                                   */
end_comment

begin_comment
comment|/*   decNumberToEngString(dn, string);                                */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  dn is the decNumber to convert                                    */
end_comment

begin_comment
comment|/*  string is the string where the result will be laid out            */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  string must be at least dn->digits+14 characters long             */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  No error is possible, and no status can be set.                   */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|char
modifier|*
name|decNumberToString
parameter_list|(
specifier|const
name|decNumber
modifier|*
name|dn
parameter_list|,
name|char
modifier|*
name|string
parameter_list|)
block|{
name|decToString
argument_list|(
name|dn
argument_list|,
name|string
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
name|string
return|;
block|}
end_function

begin_function
name|char
modifier|*
name|decNumberToEngString
parameter_list|(
specifier|const
name|decNumber
modifier|*
name|dn
parameter_list|,
name|char
modifier|*
name|string
parameter_list|)
block|{
name|decToString
argument_list|(
name|dn
argument_list|,
name|string
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
name|string
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* to-number -- conversion from numeric string                        */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* decNumberFromString -- convert string to decNumber                 */
end_comment

begin_comment
comment|/*   dn        -- the number structure to fill                        */
end_comment

begin_comment
comment|/*   chars[]   -- the string to convert ('\0' terminated)             */
end_comment

begin_comment
comment|/*   set       -- the context used for processing any error,          */
end_comment

begin_comment
comment|/*                determining the maximum precision available         */
end_comment

begin_comment
comment|/*                (set.digits), determining the maximum and minimum   */
end_comment

begin_comment
comment|/*                exponent (set.emax and set.emin), determining if    */
end_comment

begin_comment
comment|/*                extended values are allowed, and checking the       */
end_comment

begin_comment
comment|/*                rounding mode if overflow occurs or rounding is     */
end_comment

begin_comment
comment|/*                needed.                                             */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* The length of the coefficient and the size of the exponent are     */
end_comment

begin_comment
comment|/* checked by this routine, so the correct error (Underflow or        */
end_comment

begin_comment
comment|/* Overflow) can be reported or rounding applied, as necessary.       */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* If bad syntax is detected, the result will be a quiet NaN.         */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberFromString
parameter_list|(
name|decNumber
modifier|*
name|dn
parameter_list|,
specifier|const
name|char
name|chars
index|[]
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|Int
name|exponent
init|=
literal|0
decl_stmt|;
comment|/* working exponent [assume 0] */
name|uByte
name|bits
init|=
literal|0
decl_stmt|;
comment|/* working flags [assume +ve] */
name|Unit
modifier|*
name|res
decl_stmt|;
comment|/* where result will be built */
name|Unit
name|resbuff
index|[
name|D2U
argument_list|(
name|DECBUFFER
operator|+
literal|1
argument_list|)
index|]
decl_stmt|;
comment|/* local buffer in case need temporary */
name|Unit
modifier|*
name|allocres
init|=
name|NULL
decl_stmt|;
comment|/* -> allocated result, iff allocated */
name|Int
name|need
decl_stmt|;
comment|/* units needed for result */
name|Int
name|d
init|=
literal|0
decl_stmt|;
comment|/* count of digits found in decimal part */
specifier|const
name|char
modifier|*
name|dotchar
init|=
name|NULL
decl_stmt|;
comment|/* where dot was found */
specifier|const
name|char
modifier|*
name|cfirst
decl_stmt|;
comment|/* -> first character of decimal part */
specifier|const
name|char
modifier|*
name|last
init|=
name|NULL
decl_stmt|;
comment|/* -> last digit of decimal part */
specifier|const
name|char
modifier|*
name|firstexp
decl_stmt|;
comment|/* -> first significant exponent digit */
specifier|const
name|char
modifier|*
name|c
decl_stmt|;
comment|/* work */
name|Unit
modifier|*
name|up
decl_stmt|;
comment|/* .. */
if|#
directive|if
name|DECDPUN
operator|>
literal|1
name|Int
name|i
decl_stmt|;
comment|/* .. */
endif|#
directive|endif
name|Int
name|residue
init|=
literal|0
decl_stmt|;
comment|/* rounding residue */
name|uInt
name|status
init|=
literal|0
decl_stmt|;
comment|/* error code */
if|#
directive|if
name|DECCHECK
if|if
condition|(
name|decCheckOperands
argument_list|(
name|DECUNUSED
argument_list|,
name|DECUNUSED
argument_list|,
name|DECUNUSED
argument_list|,
name|set
argument_list|)
condition|)
return|return
name|decNumberZero
argument_list|(
name|dn
argument_list|)
return|;
endif|#
directive|endif
do|do
block|{
comment|/* status& malloc protection */
name|c
operator|=
name|chars
expr_stmt|;
comment|/* -> input character */
if|if
condition|(
operator|*
name|c
operator|==
literal|'-'
condition|)
block|{
comment|/* handle leading '-' */
name|bits
operator|=
name|DECNEG
expr_stmt|;
name|c
operator|++
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|*
name|c
operator|==
literal|'+'
condition|)
name|c
operator|++
expr_stmt|;
comment|/* step over leading '+' */
comment|/* We're at the start of the number [we think] */
name|cfirst
operator|=
name|c
expr_stmt|;
comment|/* save */
for|for
control|(
init|;
condition|;
name|c
operator|++
control|)
block|{
if|if
condition|(
operator|*
name|c
operator|>=
literal|'0'
operator|&&
operator|*
name|c
operator|<=
literal|'9'
condition|)
block|{
comment|/* test for Arabic digit */
name|last
operator|=
name|c
expr_stmt|;
name|d
operator|++
expr_stmt|;
comment|/* count of real digits */
continue|continue;
comment|/* still in decimal part */
block|}
if|if
condition|(
operator|*
name|c
operator|!=
literal|'.'
condition|)
break|break;
comment|/* done with decimal part */
comment|/* dot: record, check, and ignore */
if|if
condition|(
name|dotchar
operator|!=
name|NULL
condition|)
block|{
comment|/* two dots */
name|last
operator|=
name|NULL
expr_stmt|;
comment|/* indicate bad */
break|break;
block|}
comment|/* .. and go report */
name|dotchar
operator|=
name|c
expr_stmt|;
comment|/* offset into decimal part */
block|}
comment|/* c */
if|if
condition|(
name|last
operator|==
name|NULL
condition|)
block|{
comment|/* no decimal digits, or>1 . */
if|#
directive|if
name|DECSUBSET
comment|/* If subset then infinities and NaNs are not allowed */
if|if
condition|(
operator|!
name|set
operator|->
name|extended
condition|)
block|{
name|status
operator|=
name|DEC_Conversion_syntax
expr_stmt|;
break|break;
comment|/* all done */
block|}
else|else
block|{
endif|#
directive|endif
comment|/* Infinities and NaNs are possible, here */
name|decNumberZero
argument_list|(
name|dn
argument_list|)
expr_stmt|;
comment|/* be optimistic */
if|if
condition|(
name|decStrEq
argument_list|(
name|c
argument_list|,
literal|"Infinity"
argument_list|)
operator|||
name|decStrEq
argument_list|(
name|c
argument_list|,
literal|"Inf"
argument_list|)
condition|)
block|{
name|dn
operator|->
name|bits
operator|=
name|bits
operator||
name|DECINF
expr_stmt|;
break|break;
comment|/* all done */
block|}
else|else
block|{
comment|/* a NaN expected */
comment|/* 2003.09.10 NaNs are now permitted to have a sign */
name|status
operator|=
name|DEC_Conversion_syntax
expr_stmt|;
comment|/* assume the worst */
name|dn
operator|->
name|bits
operator|=
name|bits
operator||
name|DECNAN
expr_stmt|;
comment|/* assume simple NaN */
if|if
condition|(
operator|*
name|c
operator|==
literal|'s'
operator|||
operator|*
name|c
operator|==
literal|'S'
condition|)
block|{
comment|/* looks like an` sNaN */
name|c
operator|++
expr_stmt|;
name|dn
operator|->
name|bits
operator|=
name|bits
operator||
name|DECSNAN
expr_stmt|;
block|}
if|if
condition|(
operator|*
name|c
operator|!=
literal|'n'
operator|&&
operator|*
name|c
operator|!=
literal|'N'
condition|)
break|break;
comment|/* check caseless "NaN" */
name|c
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|c
operator|!=
literal|'a'
operator|&&
operator|*
name|c
operator|!=
literal|'A'
condition|)
break|break;
comment|/* .. */
name|c
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|c
operator|!=
literal|'n'
operator|&&
operator|*
name|c
operator|!=
literal|'N'
condition|)
break|break;
comment|/* .. */
name|c
operator|++
expr_stmt|;
comment|/* now nothing, or nnnn, expected */
comment|/* -> start of integer and skip leading 0s [including plain 0] */
for|for
control|(
name|cfirst
operator|=
name|c
init|;
operator|*
name|cfirst
operator|==
literal|'0'
condition|;
control|)
name|cfirst
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|cfirst
operator|==
literal|'\0'
condition|)
block|{
comment|/* "NaN" or "sNaN", maybe with all 0s */
name|status
operator|=
literal|0
expr_stmt|;
comment|/* it's good */
break|break;
comment|/* .. */
block|}
comment|/* something other than 0s; setup last and d as usual [no dots] */
for|for
control|(
name|c
operator|=
name|cfirst
init|;
condition|;
name|c
operator|++
operator|,
name|d
operator|++
control|)
block|{
if|if
condition|(
operator|*
name|c
operator|<
literal|'0'
operator|||
operator|*
name|c
operator|>
literal|'9'
condition|)
break|break;
comment|/* test for Arabic digit */
name|last
operator|=
name|c
expr_stmt|;
block|}
if|if
condition|(
operator|*
name|c
operator|!=
literal|'\0'
condition|)
break|break;
comment|/* not all digits */
if|if
condition|(
name|d
operator|>
name|set
operator|->
name|digits
condition|)
break|break;
comment|/* too many digits */
comment|/* good; drop through and convert the integer */
name|status
operator|=
literal|0
expr_stmt|;
name|bits
operator|=
name|dn
operator|->
name|bits
expr_stmt|;
comment|/* for copy-back */
block|}
comment|/* NaN expected */
if|#
directive|if
name|DECSUBSET
block|}
endif|#
directive|endif
block|}
comment|/* last==NULL */
if|if
condition|(
operator|*
name|c
operator|!=
literal|'\0'
condition|)
block|{
comment|/* more there; exponent expected... */
name|Flag
name|nege
init|=
literal|0
decl_stmt|;
comment|/* 1=negative exponent */
if|if
condition|(
operator|*
name|c
operator|!=
literal|'e'
operator|&&
operator|*
name|c
operator|!=
literal|'E'
condition|)
block|{
name|status
operator|=
name|DEC_Conversion_syntax
expr_stmt|;
break|break;
block|}
comment|/* Found 'e' or 'E' -- now process explicit exponent */
comment|/* 1998.07.11: sign no longer required */
name|c
operator|++
expr_stmt|;
comment|/* to (expected) sign */
if|if
condition|(
operator|*
name|c
operator|==
literal|'-'
condition|)
block|{
name|nege
operator|=
literal|1
expr_stmt|;
name|c
operator|++
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|*
name|c
operator|==
literal|'+'
condition|)
name|c
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|c
operator|==
literal|'\0'
condition|)
block|{
name|status
operator|=
name|DEC_Conversion_syntax
expr_stmt|;
break|break;
block|}
for|for
control|(
init|;
operator|*
name|c
operator|==
literal|'0'
operator|&&
operator|*
operator|(
name|c
operator|+
literal|1
operator|)
operator|!=
literal|'\0'
condition|;
control|)
name|c
operator|++
expr_stmt|;
comment|/* strip insignificant zeros */
name|firstexp
operator|=
name|c
expr_stmt|;
comment|/* save exponent digit place */
for|for
control|(
init|;
condition|;
name|c
operator|++
control|)
block|{
if|if
condition|(
operator|*
name|c
operator|<
literal|'0'
operator|||
operator|*
name|c
operator|>
literal|'9'
condition|)
break|break;
comment|/* not a digit */
name|exponent
operator|=
name|X10
argument_list|(
name|exponent
argument_list|)
operator|+
operator|(
name|Int
operator|)
operator|*
name|c
operator|-
operator|(
name|Int
operator|)
literal|'0'
expr_stmt|;
block|}
comment|/* c */
comment|/* if we didn't end on '\0' must not be a digit */
if|if
condition|(
operator|*
name|c
operator|!=
literal|'\0'
condition|)
block|{
name|status
operator|=
name|DEC_Conversion_syntax
expr_stmt|;
break|break;
block|}
comment|/* (this next test must be after the syntax check) */
comment|/* if it was too long the exponent may have wrapped, so check */
comment|/* carefully and set it to a certain overflow if wrap possible */
if|if
condition|(
name|c
operator|>=
name|firstexp
operator|+
literal|9
operator|+
literal|1
condition|)
block|{
if|if
condition|(
name|c
operator|>
name|firstexp
operator|+
literal|9
operator|+
literal|1
operator|||
operator|*
name|firstexp
operator|>
literal|'1'
condition|)
name|exponent
operator|=
name|DECNUMMAXE
operator|*
literal|2
expr_stmt|;
comment|/* [up to 1999999999 is OK, for example 1E-1000000998] */
block|}
if|if
condition|(
name|nege
condition|)
name|exponent
operator|=
operator|-
name|exponent
expr_stmt|;
comment|/* was negative */
block|}
comment|/* had exponent */
comment|/* Here when all inspected; syntax is good */
comment|/* Handle decimal point... */
if|if
condition|(
name|dotchar
operator|!=
name|NULL
operator|&&
name|dotchar
operator|<
name|last
condition|)
comment|/* embedded . found, so */
name|exponent
operator|=
name|exponent
operator|-
operator|(
name|last
operator|-
name|dotchar
operator|)
expr_stmt|;
comment|/* .. adjust exponent */
comment|/* [we can now ignore the .] */
comment|/* strip leading zeros/dot (leave final if all 0's) */
for|for
control|(
name|c
operator|=
name|cfirst
init|;
name|c
operator|<
name|last
condition|;
name|c
operator|++
control|)
block|{
if|if
condition|(
operator|*
name|c
operator|==
literal|'0'
condition|)
name|d
operator|--
expr_stmt|;
comment|/* 0 stripped */
elseif|else
if|if
condition|(
operator|*
name|c
operator|!=
literal|'.'
condition|)
break|break;
name|cfirst
operator|++
expr_stmt|;
comment|/* step past leader */
block|}
comment|/* c */
if|#
directive|if
name|DECSUBSET
comment|/* We can now make a rapid exit for zeros if !extended */
if|if
condition|(
operator|*
name|cfirst
operator|==
literal|'0'
operator|&&
operator|!
name|set
operator|->
name|extended
condition|)
block|{
name|decNumberZero
argument_list|(
name|dn
argument_list|)
expr_stmt|;
comment|/* clean result */
break|break;
comment|/* [could be return] */
block|}
endif|#
directive|endif
comment|/* OK, the digits string is good.  Copy to the decNumber, or to          a temporary decNumber if rounding is needed */
if|if
condition|(
name|d
operator|<=
name|set
operator|->
name|digits
condition|)
name|res
operator|=
name|dn
operator|->
name|lsu
expr_stmt|;
comment|/* fits into given decNumber */
else|else
block|{
comment|/* rounding needed */
name|need
operator|=
name|D2U
argument_list|(
name|d
argument_list|)
expr_stmt|;
comment|/* units needed */
name|res
operator|=
name|resbuff
expr_stmt|;
comment|/* assume use local buffer */
if|if
condition|(
name|need
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|resbuff
argument_list|)
condition|)
block|{
comment|/* too big for local */
name|allocres
operator|=
operator|(
name|Unit
operator|*
operator|)
name|malloc
argument_list|(
name|need
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|allocres
operator|==
name|NULL
condition|)
block|{
name|status
operator||=
name|DEC_Insufficient_storage
expr_stmt|;
break|break;
block|}
name|res
operator|=
name|allocres
expr_stmt|;
block|}
block|}
comment|/* res now -> number lsu, buffer, or allocated storage for Unit array */
comment|/* Place the coefficient into the selected Unit array */
if|#
directive|if
name|DECDPUN
operator|>
literal|1
name|i
operator|=
name|d
operator|%
name|DECDPUN
expr_stmt|;
comment|/* digits in top unit */
if|if
condition|(
name|i
operator|==
literal|0
condition|)
name|i
operator|=
name|DECDPUN
expr_stmt|;
name|up
operator|=
name|res
operator|+
name|D2U
argument_list|(
name|d
argument_list|)
operator|-
literal|1
expr_stmt|;
comment|/* -> msu */
operator|*
name|up
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|c
operator|=
name|cfirst
init|;
condition|;
name|c
operator|++
control|)
block|{
comment|/* along the digits */
if|if
condition|(
operator|*
name|c
operator|==
literal|'.'
condition|)
block|{
comment|/* ignore . [don't decrement i] */
if|if
condition|(
name|c
operator|!=
name|last
condition|)
continue|continue;
break|break;
block|}
operator|*
name|up
operator|=
call|(
name|Unit
call|)
argument_list|(
name|X10
argument_list|(
operator|*
name|up
argument_list|)
operator|+
operator|(
name|Int
operator|)
operator|*
name|c
operator|-
operator|(
name|Int
operator|)
literal|'0'
argument_list|)
expr_stmt|;
name|i
operator|--
expr_stmt|;
if|if
condition|(
name|i
operator|>
literal|0
condition|)
continue|continue;
comment|/* more for this unit */
if|if
condition|(
name|up
operator|==
name|res
condition|)
break|break;
comment|/* just filled the last unit */
name|i
operator|=
name|DECDPUN
expr_stmt|;
name|up
operator|--
expr_stmt|;
operator|*
name|up
operator|=
literal|0
expr_stmt|;
block|}
comment|/* c */
else|#
directive|else
comment|/* DECDPUN==1 */
name|up
operator|=
name|res
expr_stmt|;
comment|/* -> lsu */
for|for
control|(
name|c
operator|=
name|last
init|;
name|c
operator|>=
name|cfirst
condition|;
name|c
operator|--
control|)
block|{
comment|/* over each character, from least */
if|if
condition|(
operator|*
name|c
operator|==
literal|'.'
condition|)
continue|continue;
comment|/* ignore . [don't step b] */
operator|*
name|up
operator|=
call|(
name|Unit
call|)
argument_list|(
operator|(
name|Int
operator|)
operator|*
name|c
operator|-
operator|(
name|Int
operator|)
literal|'0'
argument_list|)
expr_stmt|;
name|up
operator|++
expr_stmt|;
block|}
comment|/* c */
endif|#
directive|endif
name|dn
operator|->
name|bits
operator|=
name|bits
expr_stmt|;
name|dn
operator|->
name|exponent
operator|=
name|exponent
expr_stmt|;
name|dn
operator|->
name|digits
operator|=
name|d
expr_stmt|;
comment|/* if not in number (too long) shorten into the number */
if|if
condition|(
name|d
operator|>
name|set
operator|->
name|digits
condition|)
name|decSetCoeff
argument_list|(
name|dn
argument_list|,
name|set
argument_list|,
name|res
argument_list|,
name|d
argument_list|,
operator|&
name|residue
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
comment|/* Finally check for overflow or subnormal and round as needed */
name|decFinalize
argument_list|(
name|dn
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
comment|/* decNumberShow(dn); */
block|}
do|while
condition|(
literal|0
condition|)
do|;
comment|/* [for break] */
if|if
condition|(
name|allocres
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|allocres
argument_list|)
expr_stmt|;
comment|/* drop any storage we used */
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decStatus
argument_list|(
name|dn
argument_list|,
name|status
argument_list|,
name|set
argument_list|)
expr_stmt|;
return|return
name|dn
return|;
block|}
end_function

begin_comment
comment|/* ================================================================== */
end_comment

begin_comment
comment|/* Operators                                                          */
end_comment

begin_comment
comment|/* ================================================================== */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberAbs -- absolute value operator                            */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = abs(A)                                         */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A                                */
end_comment

begin_comment
comment|/*   rhs is A                                                         */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* This has the same effect as decNumberPlus unless A is negative,    */
end_comment

begin_comment
comment|/* in which case it has the same effect as decNumberMinus.            */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberAbs
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|decNumber
name|dzero
decl_stmt|;
comment|/* for 0 */
name|uInt
name|status
init|=
literal|0
decl_stmt|;
comment|/* accumulator */
if|#
directive|if
name|DECCHECK
if|if
condition|(
name|decCheckOperands
argument_list|(
name|res
argument_list|,
name|DECUNUSED
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|)
condition|)
return|return
name|res
return|;
endif|#
directive|endif
name|decNumberZero
argument_list|(
operator|&
name|dzero
argument_list|)
expr_stmt|;
comment|/* set 0 */
name|dzero
operator|.
name|exponent
operator|=
name|rhs
operator|->
name|exponent
expr_stmt|;
comment|/* [no coefficient expansion] */
name|decAddOp
argument_list|(
name|res
argument_list|,
operator|&
name|dzero
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|,
call|(
name|uByte
call|)
argument_list|(
name|rhs
operator|->
name|bits
operator|&
name|DECNEG
argument_list|)
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decStatus
argument_list|(
name|res
argument_list|,
name|status
argument_list|,
name|set
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberAdd -- add two Numbers                                    */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = A + B                                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A and/or B (e.g., X=X+X)         */
end_comment

begin_comment
comment|/*   lhs is A                                                         */
end_comment

begin_comment
comment|/*   rhs is B                                                         */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* This just calls the routine shared with Subtract                   */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberAdd
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|uInt
name|status
init|=
literal|0
decl_stmt|;
comment|/* accumulator */
name|decAddOp
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|,
literal|0
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decStatus
argument_list|(
name|res
argument_list|,
name|status
argument_list|,
name|set
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberCompare -- compare two Numbers                            */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = A ? B                                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A and/or B (e.g., X=X?X)         */
end_comment

begin_comment
comment|/*   lhs is A                                                         */
end_comment

begin_comment
comment|/*   rhs is B                                                         */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for one digit.                                   */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberCompare
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|uInt
name|status
init|=
literal|0
decl_stmt|;
comment|/* accumulator */
name|decCompareOp
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|,
name|COMPARE
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decStatus
argument_list|(
name|res
argument_list|,
name|status
argument_list|,
name|set
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberDivide -- divide one number by another                    */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = A / B                                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A and/or B (e.g., X=X/X)         */
end_comment

begin_comment
comment|/*   lhs is A                                                         */
end_comment

begin_comment
comment|/*   rhs is B                                                         */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberDivide
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|uInt
name|status
init|=
literal|0
decl_stmt|;
comment|/* accumulator */
name|decDivideOp
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|,
name|DIVIDE
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decStatus
argument_list|(
name|res
argument_list|,
name|status
argument_list|,
name|set
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberDivideInteger -- divide and return integer quotient       */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = A # B, where # is the integer divide operator  */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A and/or B (e.g., X=X#X)         */
end_comment

begin_comment
comment|/*   lhs is A                                                         */
end_comment

begin_comment
comment|/*   rhs is B                                                         */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberDivideInteger
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|uInt
name|status
init|=
literal|0
decl_stmt|;
comment|/* accumulator */
name|decDivideOp
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|,
name|DIVIDEINT
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decStatus
argument_list|(
name|res
argument_list|,
name|status
argument_list|,
name|set
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberMax -- compare two Numbers and return the maximum         */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = A ? B, returning the maximum or A if equal     */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A and/or B (e.g., X=X?X)         */
end_comment

begin_comment
comment|/*   lhs is A                                                         */
end_comment

begin_comment
comment|/*   rhs is B                                                         */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberMax
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|uInt
name|status
init|=
literal|0
decl_stmt|;
comment|/* accumulator */
name|decCompareOp
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|,
name|COMPMAX
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decStatus
argument_list|(
name|res
argument_list|,
name|status
argument_list|,
name|set
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberMin -- compare two Numbers and return the minimum         */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = A ? B, returning the minimum or A if equal     */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A and/or B (e.g., X=X?X)         */
end_comment

begin_comment
comment|/*   lhs is A                                                         */
end_comment

begin_comment
comment|/*   rhs is B                                                         */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberMin
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|uInt
name|status
init|=
literal|0
decl_stmt|;
comment|/* accumulator */
name|decCompareOp
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|,
name|COMPMIN
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decStatus
argument_list|(
name|res
argument_list|,
name|status
argument_list|,
name|set
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberMinus -- prefix minus operator                            */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = 0 - A                                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A                                */
end_comment

begin_comment
comment|/*   rhs is A                                                         */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* We simply use AddOp for the subtract, which will do the necessary. */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberMinus
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|decNumber
name|dzero
decl_stmt|;
name|uInt
name|status
init|=
literal|0
decl_stmt|;
comment|/* accumulator */
if|#
directive|if
name|DECCHECK
if|if
condition|(
name|decCheckOperands
argument_list|(
name|res
argument_list|,
name|DECUNUSED
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|)
condition|)
return|return
name|res
return|;
endif|#
directive|endif
name|decNumberZero
argument_list|(
operator|&
name|dzero
argument_list|)
expr_stmt|;
comment|/* make 0 */
name|dzero
operator|.
name|exponent
operator|=
name|rhs
operator|->
name|exponent
expr_stmt|;
comment|/* [no coefficient expansion] */
name|decAddOp
argument_list|(
name|res
argument_list|,
operator|&
name|dzero
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|,
name|DECNEG
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decStatus
argument_list|(
name|res
argument_list|,
name|status
argument_list|,
name|set
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberPlus -- prefix plus operator                              */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = 0 + A                                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A                                */
end_comment

begin_comment
comment|/*   rhs is A                                                         */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* We simply use AddOp; Add will take fast path after preparing A.    */
end_comment

begin_comment
comment|/* Performance is a concern here, as this routine is often used to    */
end_comment

begin_comment
comment|/* check operands and apply rounding and overflow/underflow testing.  */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberPlus
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|decNumber
name|dzero
decl_stmt|;
name|uInt
name|status
init|=
literal|0
decl_stmt|;
comment|/* accumulator */
if|#
directive|if
name|DECCHECK
if|if
condition|(
name|decCheckOperands
argument_list|(
name|res
argument_list|,
name|DECUNUSED
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|)
condition|)
return|return
name|res
return|;
endif|#
directive|endif
name|decNumberZero
argument_list|(
operator|&
name|dzero
argument_list|)
expr_stmt|;
comment|/* make 0 */
name|dzero
operator|.
name|exponent
operator|=
name|rhs
operator|->
name|exponent
expr_stmt|;
comment|/* [no coefficient expansion] */
name|decAddOp
argument_list|(
name|res
argument_list|,
operator|&
name|dzero
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|,
literal|0
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decStatus
argument_list|(
name|res
argument_list|,
name|status
argument_list|,
name|set
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberMultiply -- multiply two Numbers                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = A x B                                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A and/or B (e.g., X=X+X)         */
end_comment

begin_comment
comment|/*   lhs is A                                                         */
end_comment

begin_comment
comment|/*   rhs is B                                                         */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberMultiply
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|uInt
name|status
init|=
literal|0
decl_stmt|;
comment|/* accumulator */
name|decMultiplyOp
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decStatus
argument_list|(
name|res
argument_list|,
name|status
argument_list|,
name|set
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberNormalize -- remove trailing zeros                        */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = 0 + A, and normalizes the result               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A                                */
end_comment

begin_comment
comment|/*   rhs is A                                                         */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberNormalize
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|decNumber
modifier|*
name|allocrhs
init|=
name|NULL
decl_stmt|;
comment|/* non-NULL if rounded rhs allocated */
name|uInt
name|status
init|=
literal|0
decl_stmt|;
comment|/* as usual */
name|Int
name|residue
init|=
literal|0
decl_stmt|;
comment|/* as usual */
name|Int
name|dropped
decl_stmt|;
comment|/* work */
if|#
directive|if
name|DECCHECK
if|if
condition|(
name|decCheckOperands
argument_list|(
name|res
argument_list|,
name|DECUNUSED
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|)
condition|)
return|return
name|res
return|;
endif|#
directive|endif
do|do
block|{
comment|/* protect allocated storage */
if|#
directive|if
name|DECSUBSET
if|if
condition|(
operator|!
name|set
operator|->
name|extended
condition|)
block|{
comment|/* reduce operand and set lostDigits status, as needed */
if|if
condition|(
name|rhs
operator|->
name|digits
operator|>
name|set
operator|->
name|digits
condition|)
block|{
name|allocrhs
operator|=
name|decRoundOperand
argument_list|(
name|rhs
argument_list|,
name|set
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|allocrhs
operator|==
name|NULL
condition|)
break|break;
name|rhs
operator|=
name|allocrhs
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* [following code does not require input rounding] */
comment|/* specials copy through, except NaNs need care */
if|if
condition|(
name|decNumberIsNaN
argument_list|(
name|rhs
argument_list|)
condition|)
block|{
name|decNaNs
argument_list|(
name|res
argument_list|,
name|rhs
argument_list|,
name|NULL
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* reduce result to the requested length and copy to result */
name|decCopyFit
argument_list|(
name|res
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
comment|/* copy& round */
name|decFinish
argument_list|(
name|res
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
comment|/* cleanup/set flags */
name|decTrim
argument_list|(
name|res
argument_list|,
literal|1
argument_list|,
operator|&
name|dropped
argument_list|)
expr_stmt|;
comment|/* normalize in place */
block|}
do|while
condition|(
literal|0
condition|)
do|;
comment|/* end protected */
if|if
condition|(
name|allocrhs
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|allocrhs
argument_list|)
expr_stmt|;
comment|/* .. */
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decStatus
argument_list|(
name|res
argument_list|,
name|status
argument_list|,
name|set
argument_list|)
expr_stmt|;
comment|/* then report status */
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberPower -- raise a number to an integer power               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = A ** B                                         */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A and/or B (e.g., X=X**X)        */
end_comment

begin_comment
comment|/*   lhs is A                                                         */
end_comment

begin_comment
comment|/*   rhs is B                                                         */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* Specification restriction: abs(n) must be<=999999999              */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberPower
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|decNumber
modifier|*
name|alloclhs
init|=
name|NULL
decl_stmt|;
comment|/* non-NULL if rounded lhs allocated */
name|decNumber
modifier|*
name|allocrhs
init|=
name|NULL
decl_stmt|;
comment|/* .., rhs */
name|decNumber
modifier|*
name|allocdac
init|=
name|NULL
decl_stmt|;
comment|/* -> allocated acc buffer, iff used */
specifier|const
name|decNumber
modifier|*
name|inrhs
init|=
name|rhs
decl_stmt|;
comment|/* save original rhs */
name|Int
name|reqdigits
init|=
name|set
operator|->
name|digits
decl_stmt|;
comment|/* requested DIGITS */
name|Int
name|n
decl_stmt|;
comment|/* RHS in binary */
name|Int
name|i
decl_stmt|;
comment|/* work */
if|#
directive|if
name|DECSUBSET
name|Int
name|dropped
decl_stmt|;
comment|/* .. */
endif|#
directive|endif
name|uInt
name|needbytes
decl_stmt|;
comment|/* buffer size needed */
name|Flag
name|seenbit
decl_stmt|;
comment|/* seen a bit while powering */
name|Int
name|residue
init|=
literal|0
decl_stmt|;
comment|/* rounding residue */
name|uInt
name|status
init|=
literal|0
decl_stmt|;
comment|/* accumulator */
name|uByte
name|bits
init|=
literal|0
decl_stmt|;
comment|/* result sign if errors */
name|decContext
name|workset
decl_stmt|;
comment|/* working context */
name|decNumber
name|dnOne
decl_stmt|;
comment|/* work value 1... */
comment|/* local accumulator buffer [a decNumber, with digits+elength+1 digits] */
name|uByte
name|dacbuff
index|[
sizeof|sizeof
argument_list|(
name|decNumber
argument_list|)
operator|+
name|D2U
argument_list|(
name|DECBUFFER
operator|+
literal|9
argument_list|)
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
index|]
decl_stmt|;
comment|/* same again for possible 1/lhs calculation */
name|uByte
name|lhsbuff
index|[
sizeof|sizeof
argument_list|(
name|decNumber
argument_list|)
operator|+
name|D2U
argument_list|(
name|DECBUFFER
operator|+
literal|9
argument_list|)
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
index|]
decl_stmt|;
name|decNumber
modifier|*
name|dac
init|=
operator|(
name|decNumber
operator|*
operator|)
name|dacbuff
decl_stmt|;
comment|/* -> result accumulator */
if|#
directive|if
name|DECCHECK
if|if
condition|(
name|decCheckOperands
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|)
condition|)
return|return
name|res
return|;
endif|#
directive|endif
do|do
block|{
comment|/* protect allocated storage */
if|#
directive|if
name|DECSUBSET
if|if
condition|(
operator|!
name|set
operator|->
name|extended
condition|)
block|{
comment|/* reduce operands and set lostDigits status, as needed */
if|if
condition|(
name|lhs
operator|->
name|digits
operator|>
name|reqdigits
condition|)
block|{
name|alloclhs
operator|=
name|decRoundOperand
argument_list|(
name|lhs
argument_list|,
name|set
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|alloclhs
operator|==
name|NULL
condition|)
break|break;
name|lhs
operator|=
name|alloclhs
expr_stmt|;
block|}
comment|/* rounding won't affect the result, but we might signal lostDigits */
comment|/* as well as the error for non-integer [x**y would need this too] */
if|if
condition|(
name|rhs
operator|->
name|digits
operator|>
name|reqdigits
condition|)
block|{
name|allocrhs
operator|=
name|decRoundOperand
argument_list|(
name|rhs
argument_list|,
name|set
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|allocrhs
operator|==
name|NULL
condition|)
break|break;
name|rhs
operator|=
name|allocrhs
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* [following code does not require input rounding] */
comment|/* handle rhs Infinity */
if|if
condition|(
name|decNumberIsInfinite
argument_list|(
name|rhs
argument_list|)
condition|)
block|{
name|status
operator||=
name|DEC_Invalid_operation
expr_stmt|;
comment|/* bad */
break|break;
block|}
comment|/* handle NaNs */
if|if
condition|(
operator|(
name|lhs
operator|->
name|bits
operator||
name|rhs
operator|->
name|bits
operator|)
operator|&
operator|(
name|DECNAN
operator||
name|DECSNAN
operator|)
condition|)
block|{
name|decNaNs
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* Original rhs must be an integer that fits and is in range */
if|#
directive|if
name|DECSUBSET
name|n
operator|=
name|decGetInt
argument_list|(
name|inrhs
argument_list|,
name|set
argument_list|)
expr_stmt|;
else|#
directive|else
name|n
operator|=
name|decGetInt
argument_list|(
name|inrhs
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|n
operator|==
name|BADINT
operator|||
name|n
operator|>
literal|999999999
operator|||
name|n
operator|<
operator|-
literal|999999999
condition|)
block|{
name|status
operator||=
name|DEC_Invalid_operation
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|n
operator|<
literal|0
condition|)
block|{
comment|/* negative */
name|n
operator|=
operator|-
name|n
expr_stmt|;
comment|/* use the absolute value */
block|}
if|if
condition|(
name|decNumberIsNegative
argument_list|(
name|lhs
argument_list|)
comment|/* -x .. */
operator|&&
operator|(
name|n
operator|&
literal|0x00000001
operator|)
condition|)
name|bits
operator|=
name|DECNEG
expr_stmt|;
comment|/* .. to an odd power */
comment|/* handle LHS infinity */
if|if
condition|(
name|decNumberIsInfinite
argument_list|(
name|lhs
argument_list|)
condition|)
block|{
comment|/* [NaNs already handled] */
name|uByte
name|rbits
init|=
name|rhs
operator|->
name|bits
decl_stmt|;
comment|/* save */
name|decNumberZero
argument_list|(
name|res
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|==
literal|0
condition|)
operator|*
name|res
operator|->
name|lsu
operator|=
literal|1
expr_stmt|;
comment|/* [-]Inf**0 => 1 */
else|else
block|{
if|if
condition|(
operator|!
operator|(
name|rbits
operator|&
name|DECNEG
operator|)
condition|)
name|bits
operator||=
name|DECINF
expr_stmt|;
comment|/* was not a **-n */
comment|/* [otherwise will be 0 or -0] */
name|res
operator|->
name|bits
operator|=
name|bits
expr_stmt|;
block|}
break|break;
block|}
comment|/* clone the context */
name|workset
operator|=
operator|*
name|set
expr_stmt|;
comment|/* copy all fields */
comment|/* calculate the working DIGITS */
name|workset
operator|.
name|digits
operator|=
name|reqdigits
operator|+
operator|(
name|inrhs
operator|->
name|digits
operator|+
name|inrhs
operator|->
name|exponent
operator|)
operator|+
literal|1
expr_stmt|;
comment|/* it's an error if this is more than we can handle */
if|if
condition|(
name|workset
operator|.
name|digits
operator|>
name|DECNUMMAXP
condition|)
block|{
name|status
operator||=
name|DEC_Invalid_operation
expr_stmt|;
break|break;
block|}
comment|/* workset.digits is the count of digits for the accumulator we need */
comment|/* if accumulator is too long for local storage, then allocate */
name|needbytes
operator|=
sizeof|sizeof
argument_list|(
name|decNumber
argument_list|)
operator|+
operator|(
name|D2U
argument_list|(
name|workset
operator|.
name|digits
argument_list|)
operator|-
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
expr_stmt|;
comment|/* [needbytes also used below if 1/lhs needed] */
if|if
condition|(
name|needbytes
operator|>
sizeof|sizeof
argument_list|(
name|dacbuff
argument_list|)
condition|)
block|{
name|allocdac
operator|=
operator|(
name|decNumber
operator|*
operator|)
name|malloc
argument_list|(
name|needbytes
argument_list|)
expr_stmt|;
if|if
condition|(
name|allocdac
operator|==
name|NULL
condition|)
block|{
comment|/* hopeless -- abandon */
name|status
operator||=
name|DEC_Insufficient_storage
expr_stmt|;
break|break;
block|}
name|dac
operator|=
name|allocdac
expr_stmt|;
comment|/* use the allocated space */
block|}
name|decNumberZero
argument_list|(
name|dac
argument_list|)
expr_stmt|;
comment|/* acc=1 */
operator|*
name|dac
operator|->
name|lsu
operator|=
literal|1
expr_stmt|;
comment|/* .. */
if|if
condition|(
name|n
operator|==
literal|0
condition|)
block|{
comment|/* x**0 is usually 1 */
comment|/* 0**0 is bad unless subset, when it becomes 1 */
if|if
condition|(
name|ISZERO
argument_list|(
name|lhs
argument_list|)
if|#
directive|if
name|DECSUBSET
operator|&&
name|set
operator|->
name|extended
endif|#
directive|endif
condition|)
name|status
operator||=
name|DEC_Invalid_operation
expr_stmt|;
else|else
name|decNumberCopy
argument_list|(
name|res
argument_list|,
name|dac
argument_list|)
expr_stmt|;
comment|/* copy the 1 */
break|break;
block|}
comment|/* if a negative power we'll need the constant 1, and if not subset */
comment|/* we'll invert the lhs now rather than inverting the result later */
if|if
condition|(
name|decNumberIsNegative
argument_list|(
name|rhs
argument_list|)
condition|)
block|{
comment|/* was a **-n [hence digits>0] */
name|decNumber
modifier|*
name|newlhs
decl_stmt|;
name|decNumberCopy
argument_list|(
operator|&
name|dnOne
argument_list|,
name|dac
argument_list|)
expr_stmt|;
comment|/* dnOne=1;  [needed now or later] */
if|#
directive|if
name|DECSUBSET
if|if
condition|(
name|set
operator|->
name|extended
condition|)
block|{
comment|/* need to calculate 1/lhs */
endif|#
directive|endif
comment|/* divide lhs into 1, putting result in dac [dac=1/dac] */
name|decDivideOp
argument_list|(
name|dac
argument_list|,
operator|&
name|dnOne
argument_list|,
name|lhs
argument_list|,
operator|&
name|workset
argument_list|,
name|DIVIDE
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|alloclhs
operator|!=
name|NULL
condition|)
block|{
name|free
argument_list|(
name|alloclhs
argument_list|)
expr_stmt|;
comment|/* done with intermediate */
name|alloclhs
operator|=
name|NULL
expr_stmt|;
comment|/* indicate freed */
block|}
comment|/* now locate or allocate space for the inverted lhs */
if|if
condition|(
name|needbytes
operator|>
sizeof|sizeof
argument_list|(
name|lhsbuff
argument_list|)
condition|)
block|{
name|alloclhs
operator|=
operator|(
name|decNumber
operator|*
operator|)
name|malloc
argument_list|(
name|needbytes
argument_list|)
expr_stmt|;
if|if
condition|(
name|alloclhs
operator|==
name|NULL
condition|)
block|{
comment|/* hopeless -- abandon */
name|status
operator||=
name|DEC_Insufficient_storage
expr_stmt|;
break|break;
block|}
name|newlhs
operator|=
name|alloclhs
expr_stmt|;
comment|/* use the allocated space */
block|}
else|else
name|newlhs
operator|=
operator|(
name|decNumber
operator|*
operator|)
name|lhsbuff
expr_stmt|;
comment|/* use stack storage */
comment|/* [lhs now points to buffer or allocated storage] */
name|decNumberCopy
argument_list|(
name|newlhs
argument_list|,
name|dac
argument_list|)
expr_stmt|;
comment|/* copy the 1/lhs */
name|decNumberCopy
argument_list|(
name|dac
argument_list|,
operator|&
name|dnOne
argument_list|)
expr_stmt|;
comment|/* restore acc=1 */
name|lhs
operator|=
name|newlhs
expr_stmt|;
if|#
directive|if
name|DECSUBSET
block|}
endif|#
directive|endif
block|}
comment|/* Raise-to-the-power loop... */
name|seenbit
operator|=
literal|0
expr_stmt|;
comment|/* set once we've seen a 1-bit */
for|for
control|(
name|i
operator|=
literal|1
init|;
condition|;
name|i
operator|++
control|)
block|{
comment|/* for each bit [top bit ignored] */
comment|/* abandon if we have had overflow or terminal underflow */
if|if
condition|(
name|status
operator|&
operator|(
name|DEC_Overflow
operator||
name|DEC_Underflow
operator|)
condition|)
block|{
comment|/* interesting? */
if|if
condition|(
name|status
operator|&
name|DEC_Overflow
operator|||
name|ISZERO
argument_list|(
name|dac
argument_list|)
condition|)
break|break;
block|}
comment|/* [the following two lines revealed an optimizer bug in a C++ */
comment|/* compiler, with symptom: 5**3 -> 25, when n=n+n was used] */
name|n
operator|=
name|n
operator|<<
literal|1
expr_stmt|;
comment|/* move next bit to testable position */
if|if
condition|(
name|n
operator|<
literal|0
condition|)
block|{
comment|/* top bit is set */
name|seenbit
operator|=
literal|1
expr_stmt|;
comment|/* OK, we're off */
name|decMultiplyOp
argument_list|(
name|dac
argument_list|,
name|dac
argument_list|,
name|lhs
argument_list|,
operator|&
name|workset
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
comment|/* dac=dac*x */
block|}
if|if
condition|(
name|i
operator|==
literal|31
condition|)
break|break;
comment|/* that was the last bit */
if|if
condition|(
operator|!
name|seenbit
condition|)
continue|continue;
comment|/* we don't have to square 1 */
name|decMultiplyOp
argument_list|(
name|dac
argument_list|,
name|dac
argument_list|,
name|dac
argument_list|,
operator|&
name|workset
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
comment|/* dac=dac*dac [square] */
block|}
comment|/*i */
comment|/* 32 bits */
comment|/* complete internal overflow or underflow processing */
if|if
condition|(
name|status
operator|&
operator|(
name|DEC_Overflow
operator||
name|DEC_Subnormal
operator|)
condition|)
block|{
if|#
directive|if
name|DECSUBSET
comment|/* If subset, and power was negative, reverse the kind of -erflow */
comment|/* [1/x not yet done] */
if|if
condition|(
operator|!
name|set
operator|->
name|extended
operator|&&
name|decNumberIsNegative
argument_list|(
name|rhs
argument_list|)
condition|)
block|{
if|if
condition|(
name|status
operator|&
name|DEC_Overflow
condition|)
name|status
operator|^=
name|DEC_Overflow
operator||
name|DEC_Underflow
operator||
name|DEC_Subnormal
expr_stmt|;
else|else
block|{
comment|/* trickier -- Underflow may or may not be set */
name|status
operator|&=
operator|~
operator|(
name|DEC_Underflow
operator||
name|DEC_Subnormal
operator|)
expr_stmt|;
comment|/* [one or both] */
name|status
operator||=
name|DEC_Overflow
expr_stmt|;
block|}
block|}
endif|#
directive|endif
name|dac
operator|->
name|bits
operator|=
operator|(
name|dac
operator|->
name|bits
operator|&
operator|~
name|DECNEG
operator|)
operator||
name|bits
expr_stmt|;
comment|/* force correct sign */
comment|/* round subnormals [to set.digits rather than workset.digits] */
comment|/* or set overflow result similarly as required */
name|decFinalize
argument_list|(
name|dac
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
name|decNumberCopy
argument_list|(
name|res
argument_list|,
name|dac
argument_list|)
expr_stmt|;
comment|/* copy to result (is now OK length) */
break|break;
block|}
if|#
directive|if
name|DECSUBSET
if|if
condition|(
operator|!
name|set
operator|->
name|extended
operator|&&
comment|/* subset math */
name|decNumberIsNegative
argument_list|(
name|rhs
argument_list|)
condition|)
block|{
comment|/* was a **-n [hence digits>0] */
comment|/* so divide result into 1 [dac=1/dac] */
name|decDivideOp
argument_list|(
name|dac
argument_list|,
operator|&
name|dnOne
argument_list|,
name|dac
argument_list|,
operator|&
name|workset
argument_list|,
name|DIVIDE
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* reduce result to the requested length and copy to result */
name|decCopyFit
argument_list|(
name|res
argument_list|,
name|dac
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
name|decFinish
argument_list|(
name|res
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
comment|/* final cleanup */
if|#
directive|if
name|DECSUBSET
if|if
condition|(
operator|!
name|set
operator|->
name|extended
condition|)
name|decTrim
argument_list|(
name|res
argument_list|,
literal|0
argument_list|,
operator|&
name|dropped
argument_list|)
expr_stmt|;
comment|/* trailing zeros */
endif|#
directive|endif
block|}
do|while
condition|(
literal|0
condition|)
do|;
comment|/* end protected */
if|if
condition|(
name|allocdac
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|allocdac
argument_list|)
expr_stmt|;
comment|/* drop any storage we used */
if|if
condition|(
name|allocrhs
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|allocrhs
argument_list|)
expr_stmt|;
comment|/* .. */
if|if
condition|(
name|alloclhs
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|alloclhs
argument_list|)
expr_stmt|;
comment|/* .. */
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decStatus
argument_list|(
name|res
argument_list|,
name|status
argument_list|,
name|set
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberQuantize -- force exponent to requested value             */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = op(A, B), where op adjusts the coefficient     */
end_comment

begin_comment
comment|/*   of C (by rounding or shifting) such that the exponent (-scale)   */
end_comment

begin_comment
comment|/*   of C has exponent of B.  The numerical value of C will equal A,  */
end_comment

begin_comment
comment|/*   except for the effects of any rounding that occurred.            */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A or B                           */
end_comment

begin_comment
comment|/*   lhs is A, the number to adjust                                   */
end_comment

begin_comment
comment|/*   rhs is B, the number with exponent to match                      */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* Unless there is an error or the result is infinite, the exponent   */
end_comment

begin_comment
comment|/* after the operation is guaranteed to be equal to that of B.        */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberQuantize
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|uInt
name|status
init|=
literal|0
decl_stmt|;
comment|/* accumulator */
name|decQuantizeOp
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|,
literal|1
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decStatus
argument_list|(
name|res
argument_list|,
name|status
argument_list|,
name|set
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberRescale -- force exponent to requested value              */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = op(A, B), where op adjusts the coefficient     */
end_comment

begin_comment
comment|/*   of C (by rounding or shifting) such that the exponent (-scale)   */
end_comment

begin_comment
comment|/*   of C has the value B.  The numerical value of C will equal A,    */
end_comment

begin_comment
comment|/*   except for the effects of any rounding that occurred.            */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A or B                           */
end_comment

begin_comment
comment|/*   lhs is A, the number to adjust                                   */
end_comment

begin_comment
comment|/*   rhs is B, the requested exponent                                 */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* Unless there is an error or the result is infinite, the exponent   */
end_comment

begin_comment
comment|/* after the operation is guaranteed to be equal to B.                */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberRescale
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|uInt
name|status
init|=
literal|0
decl_stmt|;
comment|/* accumulator */
name|decQuantizeOp
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|,
literal|0
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decStatus
argument_list|(
name|res
argument_list|,
name|status
argument_list|,
name|set
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberRemainder -- divide and return remainder                  */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = A % B                                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A and/or B (e.g., X=X%X)         */
end_comment

begin_comment
comment|/*   lhs is A                                                         */
end_comment

begin_comment
comment|/*   rhs is B                                                         */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberRemainder
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|uInt
name|status
init|=
literal|0
decl_stmt|;
comment|/* accumulator */
name|decDivideOp
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|,
name|REMAINDER
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decStatus
argument_list|(
name|res
argument_list|,
name|status
argument_list|,
name|set
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberRemainderNear -- divide and return remainder from nearest */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = A % B, where % is the IEEE remainder operator  */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A and/or B (e.g., X=X%X)         */
end_comment

begin_comment
comment|/*   lhs is A                                                         */
end_comment

begin_comment
comment|/*   rhs is B                                                         */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberRemainderNear
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|uInt
name|status
init|=
literal|0
decl_stmt|;
comment|/* accumulator */
name|decDivideOp
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|,
name|REMNEAR
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decStatus
argument_list|(
name|res
argument_list|,
name|status
argument_list|,
name|set
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberSameQuantum -- test for equal exponents                   */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is the result number, which will contain either 0 or 1       */
end_comment

begin_comment
comment|/*   lhs is a number to test                                          */
end_comment

begin_comment
comment|/*   rhs is the second (usually a pattern)                            */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* No errors are possible and no context is needed.                   */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberSameQuantum
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|)
block|{
name|uByte
name|merged
decl_stmt|;
comment|/* merged flags */
name|Unit
name|ret
init|=
literal|0
decl_stmt|;
comment|/* return value */
if|#
directive|if
name|DECCHECK
if|if
condition|(
name|decCheckOperands
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|DECUNUSED
argument_list|)
condition|)
return|return
name|res
return|;
endif|#
directive|endif
name|merged
operator|=
operator|(
name|lhs
operator|->
name|bits
operator||
name|rhs
operator|->
name|bits
operator|)
operator|&
name|DECSPECIAL
expr_stmt|;
if|if
condition|(
name|merged
condition|)
block|{
if|if
condition|(
name|decNumberIsNaN
argument_list|(
name|lhs
argument_list|)
operator|&&
name|decNumberIsNaN
argument_list|(
name|rhs
argument_list|)
condition|)
name|ret
operator|=
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
name|decNumberIsInfinite
argument_list|(
name|lhs
argument_list|)
operator|&&
name|decNumberIsInfinite
argument_list|(
name|rhs
argument_list|)
condition|)
name|ret
operator|=
literal|1
expr_stmt|;
comment|/* [anything else with a special gives 0] */
block|}
elseif|else
if|if
condition|(
name|lhs
operator|->
name|exponent
operator|==
name|rhs
operator|->
name|exponent
condition|)
name|ret
operator|=
literal|1
expr_stmt|;
name|decNumberZero
argument_list|(
name|res
argument_list|)
expr_stmt|;
comment|/* OK to overwrite an operand */
operator|*
name|res
operator|->
name|lsu
operator|=
name|ret
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberSquareRoot -- square root operator                        */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = squareroot(A)                                  */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A                                */
end_comment

begin_comment
comment|/*   rhs is A                                                         */
end_comment

begin_comment
comment|/*   set is the context; note that rounding mode has no effect        */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* This uses the following varying-precision algorithm in:            */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   Properly Rounded Variable Precision Square Root, T. E. Hull and  */
end_comment

begin_comment
comment|/*   A. Abrham, ACM Transactions on Mathematical Software, Vol 11 #3, */
end_comment

begin_comment
comment|/*   pp229-237, ACM, September 1985.                                  */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* % [Reformatted original Numerical Turing source code follows.]     */
end_comment

begin_comment
comment|/* function sqrt(x : real) : real                                     */
end_comment

begin_comment
comment|/* % sqrt(x) returns the properly rounded approximation to the square */
end_comment

begin_comment
comment|/* % root of x, in the precision of the calling environment, or it    */
end_comment

begin_comment
comment|/* % fails if x< 0.                                                  */
end_comment

begin_comment
comment|/* % t e hull and a abrham, august, 1984                              */
end_comment

begin_comment
comment|/* if x<= 0 then                                                     */
end_comment

begin_comment
comment|/*   if x< 0 then                                                    */
end_comment

begin_comment
comment|/*     assert false                                                   */
end_comment

begin_comment
comment|/*   else                                                             */
end_comment

begin_comment
comment|/*     result 0                                                       */
end_comment

begin_comment
comment|/*   end if                                                           */
end_comment

begin_comment
comment|/* end if                                                             */
end_comment

begin_comment
comment|/* var f := setexp(x, 0)  % fraction part of x   [0.1<= x< 1]       */
end_comment

begin_comment
comment|/* var e := getexp(x)     % exponent part of x                        */
end_comment

begin_comment
comment|/* var approx : real                                                  */
end_comment

begin_comment
comment|/* if e mod 2 = 0  then                                               */
end_comment

begin_comment
comment|/*   approx := .259 + .819 * f   % approx to root of f                */
end_comment

begin_comment
comment|/* else                                                               */
end_comment

begin_comment
comment|/*   f := f/l0                   % adjustments                        */
end_comment

begin_comment
comment|/*   e := e + 1                  %   for odd                          */
end_comment

begin_comment
comment|/*   approx := .0819 + 2.59 * f  %   exponent                         */
end_comment

begin_comment
comment|/* end if                                                             */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* var p:= 3                                                          */
end_comment

begin_comment
comment|/* const maxp := currentprecision + 2                                 */
end_comment

begin_comment
comment|/* loop                                                               */
end_comment

begin_comment
comment|/*   p := min(2*p - 2, maxp)     % p = 4,6,10, . . . , maxp           */
end_comment

begin_comment
comment|/*   precision p                                                      */
end_comment

begin_comment
comment|/*   approx := .5 * (approx + f/approx)                               */
end_comment

begin_comment
comment|/*   exit when p = maxp                                               */
end_comment

begin_comment
comment|/* end loop                                                           */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* % approx is now within 1 ulp of the properly rounded square root   */
end_comment

begin_comment
comment|/* % of f; to ensure proper rounding, compare squares of (approx -    */
end_comment

begin_comment
comment|/* % l/2 ulp) and (approx + l/2 ulp) with f.                          */
end_comment

begin_comment
comment|/* p := currentprecision                                              */
end_comment

begin_comment
comment|/* begin                                                              */
end_comment

begin_comment
comment|/*   precision p + 2                                                  */
end_comment

begin_comment
comment|/*   const approxsubhalf := approx - setexp(.5, -p)                   */
end_comment

begin_comment
comment|/*   if mulru(approxsubhalf, approxsubhalf)> f then                  */
end_comment

begin_comment
comment|/*     approx := approx - setexp(.l, -p + 1)                          */
end_comment

begin_comment
comment|/*   else                                                             */
end_comment

begin_comment
comment|/*     const approxaddhalf := approx + setexp(.5, -p)                 */
end_comment

begin_comment
comment|/*     if mulrd(approxaddhalf, approxaddhalf)< f then                */
end_comment

begin_comment
comment|/*       approx := approx + setexp(.l, -p + 1)                        */
end_comment

begin_comment
comment|/*     end if                                                         */
end_comment

begin_comment
comment|/*   end if                                                           */
end_comment

begin_comment
comment|/* end                                                                */
end_comment

begin_comment
comment|/* result setexp(approx, e div 2)  % fix exponent                     */
end_comment

begin_comment
comment|/* end sqrt                                                           */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberSquareRoot
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|decContext
name|workset
decl_stmt|,
name|approxset
decl_stmt|;
comment|/* work contexts */
name|decNumber
name|dzero
decl_stmt|;
comment|/* used for constant zero */
name|Int
name|maxp
init|=
name|set
operator|->
name|digits
operator|+
literal|2
decl_stmt|;
comment|/* largest working precision */
name|Int
name|residue
init|=
literal|0
decl_stmt|;
comment|/* rounding residue */
name|uInt
name|status
init|=
literal|0
decl_stmt|,
name|ignore
init|=
literal|0
decl_stmt|;
comment|/* status accumulators */
name|Int
name|exp
decl_stmt|;
comment|/* working exponent */
name|Int
name|ideal
decl_stmt|;
comment|/* ideal (preferred) exponent */
name|uInt
name|needbytes
decl_stmt|;
comment|/* work */
name|Int
name|dropped
decl_stmt|;
comment|/* .. */
name|decNumber
modifier|*
name|allocrhs
init|=
name|NULL
decl_stmt|;
comment|/* non-NULL if rounded rhs allocated */
comment|/* buffer for f [needs +1 in case DECBUFFER 0] */
name|uByte
name|buff
index|[
sizeof|sizeof
argument_list|(
name|decNumber
argument_list|)
operator|+
operator|(
name|D2U
argument_list|(
name|DECBUFFER
operator|+
literal|1
argument_list|)
operator|-
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
index|]
decl_stmt|;
comment|/* buffer for a [needs +2 to match maxp] */
name|uByte
name|bufa
index|[
sizeof|sizeof
argument_list|(
name|decNumber
argument_list|)
operator|+
operator|(
name|D2U
argument_list|(
name|DECBUFFER
operator|+
literal|2
argument_list|)
operator|-
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
index|]
decl_stmt|;
comment|/* buffer for temporary, b [must be same size as a] */
name|uByte
name|bufb
index|[
sizeof|sizeof
argument_list|(
name|decNumber
argument_list|)
operator|+
operator|(
name|D2U
argument_list|(
name|DECBUFFER
operator|+
literal|2
argument_list|)
operator|-
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
index|]
decl_stmt|;
name|decNumber
modifier|*
name|allocbuff
init|=
name|NULL
decl_stmt|;
comment|/* -> allocated buff, iff allocated */
name|decNumber
modifier|*
name|allocbufa
init|=
name|NULL
decl_stmt|;
comment|/* -> allocated bufa, iff allocated */
name|decNumber
modifier|*
name|allocbufb
init|=
name|NULL
decl_stmt|;
comment|/* -> allocated bufb, iff allocated */
name|decNumber
modifier|*
name|f
init|=
operator|(
name|decNumber
operator|*
operator|)
name|buff
decl_stmt|;
comment|/* reduced fraction */
name|decNumber
modifier|*
name|a
init|=
operator|(
name|decNumber
operator|*
operator|)
name|bufa
decl_stmt|;
comment|/* approximation to result */
name|decNumber
modifier|*
name|b
init|=
operator|(
name|decNumber
operator|*
operator|)
name|bufb
decl_stmt|;
comment|/* intermediate result */
comment|/* buffer for temporary variable, up to 3 digits */
name|uByte
name|buft
index|[
sizeof|sizeof
argument_list|(
name|decNumber
argument_list|)
operator|+
operator|(
name|D2U
argument_list|(
literal|3
argument_list|)
operator|-
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
index|]
decl_stmt|;
name|decNumber
modifier|*
name|t
init|=
operator|(
name|decNumber
operator|*
operator|)
name|buft
decl_stmt|;
comment|/* up-to-3-digit constant or work */
if|#
directive|if
name|DECCHECK
if|if
condition|(
name|decCheckOperands
argument_list|(
name|res
argument_list|,
name|DECUNUSED
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|)
condition|)
return|return
name|res
return|;
endif|#
directive|endif
do|do
block|{
comment|/* protect allocated storage */
if|#
directive|if
name|DECSUBSET
if|if
condition|(
operator|!
name|set
operator|->
name|extended
condition|)
block|{
comment|/* reduce operand and set lostDigits status, as needed */
if|if
condition|(
name|rhs
operator|->
name|digits
operator|>
name|set
operator|->
name|digits
condition|)
block|{
name|allocrhs
operator|=
name|decRoundOperand
argument_list|(
name|rhs
argument_list|,
name|set
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|allocrhs
operator|==
name|NULL
condition|)
break|break;
comment|/* [Note: 'f' allocation below could reuse this buffer if */
comment|/* used, but as this is rare we keep them separate for clarity.] */
name|rhs
operator|=
name|allocrhs
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* [following code does not require input rounding] */
comment|/* handle infinities and NaNs */
if|if
condition|(
name|rhs
operator|->
name|bits
operator|&
name|DECSPECIAL
condition|)
block|{
if|if
condition|(
name|decNumberIsInfinite
argument_list|(
name|rhs
argument_list|)
condition|)
block|{
comment|/* an infinity */
if|if
condition|(
name|decNumberIsNegative
argument_list|(
name|rhs
argument_list|)
condition|)
name|status
operator||=
name|DEC_Invalid_operation
expr_stmt|;
else|else
name|decNumberCopy
argument_list|(
name|res
argument_list|,
name|rhs
argument_list|)
expr_stmt|;
comment|/* +Infinity */
block|}
else|else
name|decNaNs
argument_list|(
name|res
argument_list|,
name|rhs
argument_list|,
name|NULL
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
comment|/* a NaN */
break|break;
block|}
comment|/* calculate the ideal (preferred) exponent [floor(exp/2)] */
comment|/* [We would like to write: ideal=rhs->exponent>>1, but this */
comment|/* generates a compiler warning.  Generated code is the same.] */
name|ideal
operator|=
operator|(
name|rhs
operator|->
name|exponent
operator|&
operator|~
literal|1
operator|)
operator|/
literal|2
expr_stmt|;
comment|/* target */
comment|/* handle zeros */
if|if
condition|(
name|ISZERO
argument_list|(
name|rhs
argument_list|)
condition|)
block|{
name|decNumberCopy
argument_list|(
name|res
argument_list|,
name|rhs
argument_list|)
expr_stmt|;
comment|/* could be 0 or -0 */
name|res
operator|->
name|exponent
operator|=
name|ideal
expr_stmt|;
comment|/* use the ideal [safe] */
break|break;
block|}
comment|/* any other -x is an oops */
if|if
condition|(
name|decNumberIsNegative
argument_list|(
name|rhs
argument_list|)
condition|)
block|{
name|status
operator||=
name|DEC_Invalid_operation
expr_stmt|;
break|break;
block|}
comment|/* we need space for three working variables */
comment|/*   f -- the same precision as the RHS, reduced to 0.01->0.99... */
comment|/*   a -- Hull's approx -- precision, when assigned, is */
comment|/*        currentprecision (we allow +2 for use as temporary) */
comment|/*   b -- intermediate temporary result */
comment|/* if any is too long for local storage, then allocate */
name|needbytes
operator|=
sizeof|sizeof
argument_list|(
name|decNumber
argument_list|)
operator|+
operator|(
name|D2U
argument_list|(
name|rhs
operator|->
name|digits
argument_list|)
operator|-
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
expr_stmt|;
if|if
condition|(
name|needbytes
operator|>
sizeof|sizeof
argument_list|(
name|buff
argument_list|)
condition|)
block|{
name|allocbuff
operator|=
operator|(
name|decNumber
operator|*
operator|)
name|malloc
argument_list|(
name|needbytes
argument_list|)
expr_stmt|;
if|if
condition|(
name|allocbuff
operator|==
name|NULL
condition|)
block|{
comment|/* hopeless -- abandon */
name|status
operator||=
name|DEC_Insufficient_storage
expr_stmt|;
break|break;
block|}
name|f
operator|=
name|allocbuff
expr_stmt|;
comment|/* use the allocated space */
block|}
comment|/* a and b both need to be able to hold a maxp-length number */
name|needbytes
operator|=
sizeof|sizeof
argument_list|(
name|decNumber
argument_list|)
operator|+
operator|(
name|D2U
argument_list|(
name|maxp
argument_list|)
operator|-
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
expr_stmt|;
if|if
condition|(
name|needbytes
operator|>
sizeof|sizeof
argument_list|(
name|bufa
argument_list|)
condition|)
block|{
comment|/* [same applies to b] */
name|allocbufa
operator|=
operator|(
name|decNumber
operator|*
operator|)
name|malloc
argument_list|(
name|needbytes
argument_list|)
expr_stmt|;
name|allocbufb
operator|=
operator|(
name|decNumber
operator|*
operator|)
name|malloc
argument_list|(
name|needbytes
argument_list|)
expr_stmt|;
if|if
condition|(
name|allocbufa
operator|==
name|NULL
operator|||
name|allocbufb
operator|==
name|NULL
condition|)
block|{
comment|/* hopeless */
name|status
operator||=
name|DEC_Insufficient_storage
expr_stmt|;
break|break;
block|}
name|a
operator|=
name|allocbufa
expr_stmt|;
comment|/* use the allocated space */
name|b
operator|=
name|allocbufb
expr_stmt|;
comment|/* .. */
block|}
comment|/* copy rhs -> f, save exponent, and reduce so 0.1<= f< 1 */
name|decNumberCopy
argument_list|(
name|f
argument_list|,
name|rhs
argument_list|)
expr_stmt|;
name|exp
operator|=
name|f
operator|->
name|exponent
operator|+
name|f
operator|->
name|digits
expr_stmt|;
comment|/* adjusted to Hull rules */
name|f
operator|->
name|exponent
operator|=
operator|-
operator|(
name|f
operator|->
name|digits
operator|)
expr_stmt|;
comment|/* to range */
comment|/* set up working contexts (the second is used for Numerical */
comment|/* Turing assignment) */
name|decContextDefault
argument_list|(
operator|&
name|workset
argument_list|,
name|DEC_INIT_DECIMAL64
argument_list|)
expr_stmt|;
name|decContextDefault
argument_list|(
operator|&
name|approxset
argument_list|,
name|DEC_INIT_DECIMAL64
argument_list|)
expr_stmt|;
name|approxset
operator|.
name|digits
operator|=
name|set
operator|->
name|digits
expr_stmt|;
comment|/* approx's length */
comment|/* [Until further notice, no error is possible and status bits */
comment|/* (Rounded, etc.) should be ignored, not accumulated.] */
comment|/* Calculate initial approximation, and allow for odd exponent */
name|workset
operator|.
name|digits
operator|=
name|set
operator|->
name|digits
expr_stmt|;
comment|/* p for initial calculation */
name|t
operator|->
name|bits
operator|=
literal|0
expr_stmt|;
name|t
operator|->
name|digits
operator|=
literal|3
expr_stmt|;
name|a
operator|->
name|bits
operator|=
literal|0
expr_stmt|;
name|a
operator|->
name|digits
operator|=
literal|3
expr_stmt|;
if|if
condition|(
operator|(
name|exp
operator|&
literal|1
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* even exponent */
comment|/* Set t=0.259, a=0.819 */
name|t
operator|->
name|exponent
operator|=
operator|-
literal|3
expr_stmt|;
name|a
operator|->
name|exponent
operator|=
operator|-
literal|3
expr_stmt|;
if|#
directive|if
name|DECDPUN
operator|>=
literal|3
name|t
operator|->
name|lsu
index|[
literal|0
index|]
operator|=
literal|259
expr_stmt|;
name|a
operator|->
name|lsu
index|[
literal|0
index|]
operator|=
literal|819
expr_stmt|;
elif|#
directive|elif
name|DECDPUN
operator|==
literal|2
name|t
operator|->
name|lsu
index|[
literal|0
index|]
operator|=
literal|59
expr_stmt|;
name|t
operator|->
name|lsu
index|[
literal|1
index|]
operator|=
literal|2
expr_stmt|;
name|a
operator|->
name|lsu
index|[
literal|0
index|]
operator|=
literal|19
expr_stmt|;
name|a
operator|->
name|lsu
index|[
literal|1
index|]
operator|=
literal|8
expr_stmt|;
else|#
directive|else
name|t
operator|->
name|lsu
index|[
literal|0
index|]
operator|=
literal|9
expr_stmt|;
name|t
operator|->
name|lsu
index|[
literal|1
index|]
operator|=
literal|5
expr_stmt|;
name|t
operator|->
name|lsu
index|[
literal|2
index|]
operator|=
literal|2
expr_stmt|;
name|a
operator|->
name|lsu
index|[
literal|0
index|]
operator|=
literal|9
expr_stmt|;
name|a
operator|->
name|lsu
index|[
literal|1
index|]
operator|=
literal|1
expr_stmt|;
name|a
operator|->
name|lsu
index|[
literal|2
index|]
operator|=
literal|8
expr_stmt|;
endif|#
directive|endif
block|}
else|else
block|{
comment|/* odd exponent */
comment|/* Set t=0.0819, a=2.59 */
name|f
operator|->
name|exponent
operator|--
expr_stmt|;
comment|/* f=f/10 */
name|exp
operator|++
expr_stmt|;
comment|/* e=e+1 */
name|t
operator|->
name|exponent
operator|=
operator|-
literal|4
expr_stmt|;
name|a
operator|->
name|exponent
operator|=
operator|-
literal|2
expr_stmt|;
if|#
directive|if
name|DECDPUN
operator|>=
literal|3
name|t
operator|->
name|lsu
index|[
literal|0
index|]
operator|=
literal|819
expr_stmt|;
name|a
operator|->
name|lsu
index|[
literal|0
index|]
operator|=
literal|259
expr_stmt|;
elif|#
directive|elif
name|DECDPUN
operator|==
literal|2
name|t
operator|->
name|lsu
index|[
literal|0
index|]
operator|=
literal|19
expr_stmt|;
name|t
operator|->
name|lsu
index|[
literal|1
index|]
operator|=
literal|8
expr_stmt|;
name|a
operator|->
name|lsu
index|[
literal|0
index|]
operator|=
literal|59
expr_stmt|;
name|a
operator|->
name|lsu
index|[
literal|1
index|]
operator|=
literal|2
expr_stmt|;
else|#
directive|else
name|t
operator|->
name|lsu
index|[
literal|0
index|]
operator|=
literal|9
expr_stmt|;
name|t
operator|->
name|lsu
index|[
literal|1
index|]
operator|=
literal|1
expr_stmt|;
name|t
operator|->
name|lsu
index|[
literal|2
index|]
operator|=
literal|8
expr_stmt|;
name|a
operator|->
name|lsu
index|[
literal|0
index|]
operator|=
literal|9
expr_stmt|;
name|a
operator|->
name|lsu
index|[
literal|1
index|]
operator|=
literal|5
expr_stmt|;
name|a
operator|->
name|lsu
index|[
literal|2
index|]
operator|=
literal|2
expr_stmt|;
endif|#
directive|endif
block|}
name|decMultiplyOp
argument_list|(
name|a
argument_list|,
name|a
argument_list|,
name|f
argument_list|,
operator|&
name|workset
argument_list|,
operator|&
name|ignore
argument_list|)
expr_stmt|;
comment|/* a=a*f */
name|decAddOp
argument_list|(
name|a
argument_list|,
name|a
argument_list|,
name|t
argument_list|,
operator|&
name|workset
argument_list|,
literal|0
argument_list|,
operator|&
name|ignore
argument_list|)
expr_stmt|;
comment|/* ..+t */
comment|/* [a is now the initial approximation for sqrt(f), calculated with */
comment|/* currentprecision, which is also a's precision.] */
comment|/* the main calculation loop */
name|decNumberZero
argument_list|(
operator|&
name|dzero
argument_list|)
expr_stmt|;
comment|/* make 0 */
name|decNumberZero
argument_list|(
name|t
argument_list|)
expr_stmt|;
comment|/* set t = 0.5 */
name|t
operator|->
name|lsu
index|[
literal|0
index|]
operator|=
literal|5
expr_stmt|;
comment|/* .. */
name|t
operator|->
name|exponent
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* .. */
name|workset
operator|.
name|digits
operator|=
literal|3
expr_stmt|;
comment|/* initial p */
for|for
control|(
init|;
condition|;
control|)
block|{
comment|/* set p to min(2*p - 2, maxp)  [hence 3; or: 4, 6, 10, ... , maxp] */
name|workset
operator|.
name|digits
operator|=
name|workset
operator|.
name|digits
operator|*
literal|2
operator|-
literal|2
expr_stmt|;
if|if
condition|(
name|workset
operator|.
name|digits
operator|>
name|maxp
condition|)
name|workset
operator|.
name|digits
operator|=
name|maxp
expr_stmt|;
comment|/* a = 0.5 * (a + f/a) */
comment|/* [calculated at p then rounded to currentprecision] */
name|decDivideOp
argument_list|(
name|b
argument_list|,
name|f
argument_list|,
name|a
argument_list|,
operator|&
name|workset
argument_list|,
name|DIVIDE
argument_list|,
operator|&
name|ignore
argument_list|)
expr_stmt|;
comment|/* b=f/a */
name|decAddOp
argument_list|(
name|b
argument_list|,
name|b
argument_list|,
name|a
argument_list|,
operator|&
name|workset
argument_list|,
literal|0
argument_list|,
operator|&
name|ignore
argument_list|)
expr_stmt|;
comment|/* b=b+a */
name|decMultiplyOp
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|t
argument_list|,
operator|&
name|workset
argument_list|,
operator|&
name|ignore
argument_list|)
expr_stmt|;
comment|/* a=b*0.5 */
comment|/* assign to approx [round to length] */
name|decAddOp
argument_list|(
name|a
argument_list|,
operator|&
name|dzero
argument_list|,
name|a
argument_list|,
operator|&
name|approxset
argument_list|,
literal|0
argument_list|,
operator|&
name|ignore
argument_list|)
expr_stmt|;
if|if
condition|(
name|workset
operator|.
name|digits
operator|==
name|maxp
condition|)
break|break;
comment|/* just did final */
block|}
comment|/* loop */
comment|/* a is now at currentprecision and within 1 ulp of the properly */
comment|/* rounded square root of f; to ensure proper rounding, compare */
comment|/* squares of (a - l/2 ulp) and (a + l/2 ulp) with f. */
comment|/* Here workset.digits=maxp and t=0.5 */
name|workset
operator|.
name|digits
operator|--
expr_stmt|;
comment|/* maxp-1 is OK now */
name|t
operator|->
name|exponent
operator|=
operator|-
name|set
operator|->
name|digits
operator|-
literal|1
expr_stmt|;
comment|/* make 0.5 ulp */
name|decNumberCopy
argument_list|(
name|b
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|decAddOp
argument_list|(
name|b
argument_list|,
name|b
argument_list|,
name|t
argument_list|,
operator|&
name|workset
argument_list|,
name|DECNEG
argument_list|,
operator|&
name|ignore
argument_list|)
expr_stmt|;
comment|/* b = a - 0.5 ulp */
name|workset
operator|.
name|round
operator|=
name|DEC_ROUND_UP
expr_stmt|;
name|decMultiplyOp
argument_list|(
name|b
argument_list|,
name|b
argument_list|,
name|b
argument_list|,
operator|&
name|workset
argument_list|,
operator|&
name|ignore
argument_list|)
expr_stmt|;
comment|/* b = mulru(b, b) */
name|decCompareOp
argument_list|(
name|b
argument_list|,
name|f
argument_list|,
name|b
argument_list|,
operator|&
name|workset
argument_list|,
name|COMPARE
argument_list|,
operator|&
name|ignore
argument_list|)
expr_stmt|;
comment|/* b ? f, reversed */
if|if
condition|(
name|decNumberIsNegative
argument_list|(
name|b
argument_list|)
condition|)
block|{
comment|/* f< b [i.e., b> f] */
comment|/* this is the more common adjustment, though both are rare */
name|t
operator|->
name|exponent
operator|++
expr_stmt|;
comment|/* make 1.0 ulp */
name|t
operator|->
name|lsu
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
comment|/* .. */
name|decAddOp
argument_list|(
name|a
argument_list|,
name|a
argument_list|,
name|t
argument_list|,
operator|&
name|workset
argument_list|,
name|DECNEG
argument_list|,
operator|&
name|ignore
argument_list|)
expr_stmt|;
comment|/* a = a - 1 ulp */
comment|/* assign to approx [round to length] */
name|decAddOp
argument_list|(
name|a
argument_list|,
operator|&
name|dzero
argument_list|,
name|a
argument_list|,
operator|&
name|approxset
argument_list|,
literal|0
argument_list|,
operator|&
name|ignore
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|decNumberCopy
argument_list|(
name|b
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|decAddOp
argument_list|(
name|b
argument_list|,
name|b
argument_list|,
name|t
argument_list|,
operator|&
name|workset
argument_list|,
literal|0
argument_list|,
operator|&
name|ignore
argument_list|)
expr_stmt|;
comment|/* b = a + 0.5 ulp */
name|workset
operator|.
name|round
operator|=
name|DEC_ROUND_DOWN
expr_stmt|;
name|decMultiplyOp
argument_list|(
name|b
argument_list|,
name|b
argument_list|,
name|b
argument_list|,
operator|&
name|workset
argument_list|,
operator|&
name|ignore
argument_list|)
expr_stmt|;
comment|/* b = mulrd(b, b) */
name|decCompareOp
argument_list|(
name|b
argument_list|,
name|b
argument_list|,
name|f
argument_list|,
operator|&
name|workset
argument_list|,
name|COMPARE
argument_list|,
operator|&
name|ignore
argument_list|)
expr_stmt|;
comment|/* b ? f */
if|if
condition|(
name|decNumberIsNegative
argument_list|(
name|b
argument_list|)
condition|)
block|{
comment|/* b< f */
name|t
operator|->
name|exponent
operator|++
expr_stmt|;
comment|/* make 1.0 ulp */
name|t
operator|->
name|lsu
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
comment|/* .. */
name|decAddOp
argument_list|(
name|a
argument_list|,
name|a
argument_list|,
name|t
argument_list|,
operator|&
name|workset
argument_list|,
literal|0
argument_list|,
operator|&
name|ignore
argument_list|)
expr_stmt|;
comment|/* a = a + 1 ulp */
comment|/* assign to approx [round to length] */
name|decAddOp
argument_list|(
name|a
argument_list|,
operator|&
name|dzero
argument_list|,
name|a
argument_list|,
operator|&
name|approxset
argument_list|,
literal|0
argument_list|,
operator|&
name|ignore
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* [no errors are possible in the above, and rounding/inexact during */
comment|/* estimation are irrelevant, so status was not accumulated] */
comment|/* Here, 0.1<= a< 1  [Hull] */
name|a
operator|->
name|exponent
operator|+=
name|exp
operator|/
literal|2
expr_stmt|;
comment|/* set correct exponent */
comment|/* Process Subnormals */
name|decFinalize
argument_list|(
name|a
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
comment|/* count dropable zeros [after any subnormal rounding] */
name|decNumberCopy
argument_list|(
name|b
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|decTrim
argument_list|(
name|b
argument_list|,
literal|1
argument_list|,
operator|&
name|dropped
argument_list|)
expr_stmt|;
comment|/* [drops trailing zeros] */
comment|/* Finally set Inexact and Rounded.  The answer can only be exact if */
comment|/* it is short enough so that squaring it could fit in set->digits, */
comment|/* so this is the only (relatively rare) time we have to check */
comment|/* carefully */
if|if
condition|(
name|b
operator|->
name|digits
operator|*
literal|2
operator|-
literal|1
operator|>
name|set
operator|->
name|digits
condition|)
block|{
comment|/* cannot fit */
name|status
operator||=
name|DEC_Inexact
operator||
name|DEC_Rounded
expr_stmt|;
block|}
else|else
block|{
comment|/* could be exact/unrounded */
name|uInt
name|mstatus
init|=
literal|0
decl_stmt|;
comment|/* local status */
name|decMultiplyOp
argument_list|(
name|b
argument_list|,
name|b
argument_list|,
name|b
argument_list|,
operator|&
name|workset
argument_list|,
operator|&
name|mstatus
argument_list|)
expr_stmt|;
comment|/* try the multiply */
if|if
condition|(
name|mstatus
operator|!=
literal|0
condition|)
block|{
comment|/* result won't fit */
name|status
operator||=
name|DEC_Inexact
operator||
name|DEC_Rounded
expr_stmt|;
block|}
else|else
block|{
comment|/* plausible */
name|decCompareOp
argument_list|(
name|t
argument_list|,
name|b
argument_list|,
name|rhs
argument_list|,
operator|&
name|workset
argument_list|,
name|COMPARE
argument_list|,
operator|&
name|mstatus
argument_list|)
expr_stmt|;
comment|/* b ? rhs */
if|if
condition|(
operator|!
name|ISZERO
argument_list|(
name|t
argument_list|)
condition|)
block|{
name|status
operator||=
name|DEC_Inexact
operator||
name|DEC_Rounded
expr_stmt|;
block|}
else|else
block|{
comment|/* is Exact */
comment|/* here, dropped is the count of trailing zeros in 'a' */
comment|/* use closest exponent to ideal... */
name|Int
name|todrop
init|=
name|ideal
operator|-
name|a
operator|->
name|exponent
decl_stmt|;
comment|/* most we can drop */
if|if
condition|(
name|todrop
operator|<
literal|0
condition|)
block|{
comment|/* ideally would add 0s */
name|status
operator||=
name|DEC_Rounded
expr_stmt|;
block|}
else|else
block|{
comment|/* unrounded */
if|if
condition|(
name|dropped
operator|<
name|todrop
condition|)
name|todrop
operator|=
name|dropped
expr_stmt|;
comment|/* clamp to those available */
if|if
condition|(
name|todrop
operator|>
literal|0
condition|)
block|{
comment|/* OK, some to drop */
name|decShiftToLeast
argument_list|(
name|a
operator|->
name|lsu
argument_list|,
name|D2U
argument_list|(
name|a
operator|->
name|digits
argument_list|)
argument_list|,
name|todrop
argument_list|)
expr_stmt|;
name|a
operator|->
name|exponent
operator|+=
name|todrop
expr_stmt|;
comment|/* maintain numerical value */
name|a
operator|->
name|digits
operator|-=
name|todrop
expr_stmt|;
comment|/* new length */
block|}
block|}
block|}
block|}
block|}
name|decNumberCopy
argument_list|(
name|res
argument_list|,
name|a
argument_list|)
expr_stmt|;
comment|/* assume this is the result */
block|}
do|while
condition|(
literal|0
condition|)
do|;
comment|/* end protected */
if|if
condition|(
name|allocbuff
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|allocbuff
argument_list|)
expr_stmt|;
comment|/* drop any storage we used */
if|if
condition|(
name|allocbufa
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|allocbufa
argument_list|)
expr_stmt|;
comment|/* .. */
if|if
condition|(
name|allocbufb
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|allocbufb
argument_list|)
expr_stmt|;
comment|/* .. */
if|if
condition|(
name|allocrhs
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|allocrhs
argument_list|)
expr_stmt|;
comment|/* .. */
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decStatus
argument_list|(
name|res
argument_list|,
name|status
argument_list|,
name|set
argument_list|)
expr_stmt|;
comment|/* then report status */
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberSubtract -- subtract two Numbers                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = A - B                                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A and/or B (e.g., X=X-X)         */
end_comment

begin_comment
comment|/*   lhs is A                                                         */
end_comment

begin_comment
comment|/*   rhs is B                                                         */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberSubtract
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|uInt
name|status
init|=
literal|0
decl_stmt|;
comment|/* accumulator */
name|decAddOp
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|,
name|DECNEG
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decStatus
argument_list|(
name|res
argument_list|,
name|status
argument_list|,
name|set
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberToIntegralValue -- round-to-integral-value                */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is the result                                                */
end_comment

begin_comment
comment|/*   rhs is input number                                              */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* res must have space for any value of rhs.                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* This implements the IEEE special operator and therefore treats     */
end_comment

begin_comment
comment|/* special values as valid, and also never sets Inexact.  For finite  */
end_comment

begin_comment
comment|/* numbers it returns rescale(rhs, 0) if rhs->exponent is<0.         */
end_comment

begin_comment
comment|/* Otherwise the result is rhs (so no error is possible).             */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* The context is used for rounding mode and status after sNaN, but   */
end_comment

begin_comment
comment|/* the digits setting is ignored.                                     */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberToIntegralValue
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|decNumber
name|dn
decl_stmt|;
name|decContext
name|workset
decl_stmt|;
comment|/* working context */
if|#
directive|if
name|DECCHECK
if|if
condition|(
name|decCheckOperands
argument_list|(
name|res
argument_list|,
name|DECUNUSED
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|)
condition|)
return|return
name|res
return|;
endif|#
directive|endif
comment|/* handle infinities and NaNs */
if|if
condition|(
name|rhs
operator|->
name|bits
operator|&
name|DECSPECIAL
condition|)
block|{
name|uInt
name|status
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|decNumberIsInfinite
argument_list|(
name|rhs
argument_list|)
condition|)
name|decNumberCopy
argument_list|(
name|res
argument_list|,
name|rhs
argument_list|)
expr_stmt|;
comment|/* an Infinity */
else|else
name|decNaNs
argument_list|(
name|res
argument_list|,
name|rhs
argument_list|,
name|NULL
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
comment|/* a NaN */
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decStatus
argument_list|(
name|res
argument_list|,
name|status
argument_list|,
name|set
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
comment|/* we have a finite number; no error possible */
if|if
condition|(
name|rhs
operator|->
name|exponent
operator|>=
literal|0
condition|)
return|return
name|decNumberCopy
argument_list|(
name|res
argument_list|,
name|rhs
argument_list|)
return|;
comment|/* that was easy, but if negative exponent we have work to do... */
name|workset
operator|=
operator|*
name|set
expr_stmt|;
comment|/* clone rounding, etc. */
name|workset
operator|.
name|digits
operator|=
name|rhs
operator|->
name|digits
expr_stmt|;
comment|/* no length rounding */
name|workset
operator|.
name|traps
operator|=
literal|0
expr_stmt|;
comment|/* no traps */
name|decNumberZero
argument_list|(
operator|&
name|dn
argument_list|)
expr_stmt|;
comment|/* make a number with exponent 0 */
return|return
name|decNumberQuantize
argument_list|(
name|res
argument_list|,
name|rhs
argument_list|,
operator|&
name|dn
argument_list|,
operator|&
name|workset
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* ================================================================== */
end_comment

begin_comment
comment|/* Utility routines                                                   */
end_comment

begin_comment
comment|/* ================================================================== */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberCopy -- copy a number                                     */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   dest is the target decNumber                                     */
end_comment

begin_comment
comment|/*   src  is the source decNumber                                     */
end_comment

begin_comment
comment|/*   returns dest                                                     */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* (dest==src is allowed and is a no-op)                              */
end_comment

begin_comment
comment|/* All fields are updated as required.  This is a utility operation,  */
end_comment

begin_comment
comment|/* so special values are unchanged and no error is possible.          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberCopy
parameter_list|(
name|decNumber
modifier|*
name|dest
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|src
parameter_list|)
block|{
if|#
directive|if
name|DECCHECK
if|if
condition|(
name|src
operator|==
name|NULL
condition|)
return|return
name|decNumberZero
argument_list|(
name|dest
argument_list|)
return|;
endif|#
directive|endif
if|if
condition|(
name|dest
operator|==
name|src
condition|)
return|return
name|dest
return|;
comment|/* no copy required */
comment|/* We use explicit assignments here as structure assignment can copy */
comment|/* more than just the lsu (for small DECDPUN).  This would not affect */
comment|/* the value of the results, but would disturb test harness spill */
comment|/* checking. */
name|dest
operator|->
name|bits
operator|=
name|src
operator|->
name|bits
expr_stmt|;
name|dest
operator|->
name|exponent
operator|=
name|src
operator|->
name|exponent
expr_stmt|;
name|dest
operator|->
name|digits
operator|=
name|src
operator|->
name|digits
expr_stmt|;
name|dest
operator|->
name|lsu
index|[
literal|0
index|]
operator|=
name|src
operator|->
name|lsu
index|[
literal|0
index|]
expr_stmt|;
if|if
condition|(
name|src
operator|->
name|digits
operator|>
name|DECDPUN
condition|)
block|{
comment|/* more Units to come */
name|Unit
modifier|*
name|d
decl_stmt|;
comment|/* work */
specifier|const
name|Unit
modifier|*
name|s
decl_stmt|,
modifier|*
name|smsup
decl_stmt|;
comment|/* work */
comment|/* memcpy for the remaining Units would be safe as they cannot */
comment|/* overlap.  However, this explicit loop is faster in short cases. */
name|d
operator|=
name|dest
operator|->
name|lsu
operator|+
literal|1
expr_stmt|;
comment|/* -> first destination */
name|smsup
operator|=
name|src
operator|->
name|lsu
operator|+
name|D2U
argument_list|(
name|src
operator|->
name|digits
argument_list|)
expr_stmt|;
comment|/* -> source msu+1 */
for|for
control|(
name|s
operator|=
name|src
operator|->
name|lsu
operator|+
literal|1
init|;
name|s
operator|<
name|smsup
condition|;
name|s
operator|++
operator|,
name|d
operator|++
control|)
operator|*
name|d
operator|=
operator|*
name|s
expr_stmt|;
block|}
return|return
name|dest
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberTrim -- remove insignificant zeros                        */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   dn is the number to trim                                         */
end_comment

begin_comment
comment|/*   returns dn                                                       */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* All fields are updated as required.  This is a utility operation,  */
end_comment

begin_comment
comment|/* so special values are unchanged and no error is possible.          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberTrim
parameter_list|(
name|decNumber
modifier|*
name|dn
parameter_list|)
block|{
name|Int
name|dropped
decl_stmt|;
comment|/* work */
return|return
name|decTrim
argument_list|(
name|dn
argument_list|,
literal|0
argument_list|,
operator|&
name|dropped
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberVersion -- return the name and version of this module     */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* No error is possible.                                              */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|decNumberVersion
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|DECVERSION
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decNumberZero -- set a number to 0                                 */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   dn is the number to set, with space for one digit                */
end_comment

begin_comment
comment|/*   returns dn                                                       */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* No error is possible.                                              */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Memset is not used as it is much slower in some environments. */
end_comment

begin_function
name|decNumber
modifier|*
name|decNumberZero
parameter_list|(
name|decNumber
modifier|*
name|dn
parameter_list|)
block|{
if|#
directive|if
name|DECCHECK
if|if
condition|(
name|decCheckOperands
argument_list|(
name|dn
argument_list|,
name|DECUNUSED
argument_list|,
name|DECUNUSED
argument_list|,
name|DECUNUSED
argument_list|)
condition|)
return|return
name|dn
return|;
endif|#
directive|endif
name|dn
operator|->
name|bits
operator|=
literal|0
expr_stmt|;
name|dn
operator|->
name|exponent
operator|=
literal|0
expr_stmt|;
name|dn
operator|->
name|digits
operator|=
literal|1
expr_stmt|;
name|dn
operator|->
name|lsu
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
return|return
name|dn
return|;
block|}
end_function

begin_comment
comment|/* ================================================================== */
end_comment

begin_comment
comment|/* Local routines                                                     */
end_comment

begin_comment
comment|/* ================================================================== */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decToString -- lay out a number into a string                      */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   dn     is the number to lay out                                  */
end_comment

begin_comment
comment|/*   string is where to lay out the number                            */
end_comment

begin_comment
comment|/*   eng    is 1 if Engineering, 0 if Scientific                      */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* str must be at least dn->digits+14 characters long                 */
end_comment

begin_comment
comment|/* No error is possible.                                              */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* Note that this routine can generate a -0 or 0.000.  These are      */
end_comment

begin_comment
comment|/* never generated in subset to-number or arithmetic, but can occur   */
end_comment

begin_comment
comment|/* in non-subset arithmetic (e.g., -1*0 or 1.234-1.234).              */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* If DECCHECK is enabled the string "?" is returned if a number is */
end_comment

begin_comment
comment|/* invalid. */
end_comment

begin_comment
comment|/* TODIGIT -- macro to remove the leading digit from the unsigned */
end_comment

begin_comment
comment|/* integer u at column cut (counting from the right, LSD=0) and place */
end_comment

begin_comment
comment|/* it as an ASCII character into the character pointed to by c.  Note */
end_comment

begin_comment
comment|/* that cut must be<= 9, and the maximum value for u is 2,000,000,000 */
end_comment

begin_comment
comment|/* (as is needed for negative exponents of subnormals).  The unsigned */
end_comment

begin_comment
comment|/* integer pow is used as a temporary variable. */
end_comment

begin_define
define|#
directive|define
name|TODIGIT
parameter_list|(
name|u
parameter_list|,
name|cut
parameter_list|,
name|c
parameter_list|)
value|{            \   *(c)='0';                             \   pow=powers[cut]*2;                    \   if ((u)>pow) {                        \     pow*=4;                             \     if ((u)>=pow) {(u)-=pow; *(c)+=8;}  \     pow/=2;                             \     if ((u)>=pow) {(u)-=pow; *(c)+=4;}  \     pow/=2;                             \     }                                   \   if ((u)>=pow) {(u)-=pow; *(c)+=2;}    \   pow/=2;                               \   if ((u)>=pow) {(u)-=pow; *(c)+=1;}    \   }
end_define

begin_function
specifier|static
name|void
name|decToString
parameter_list|(
specifier|const
name|decNumber
modifier|*
name|dn
parameter_list|,
name|char
modifier|*
name|string
parameter_list|,
name|Flag
name|eng
parameter_list|)
block|{
name|Int
name|exp
init|=
name|dn
operator|->
name|exponent
decl_stmt|;
comment|/* local copy */
name|Int
name|e
decl_stmt|;
comment|/* E-part value */
name|Int
name|pre
decl_stmt|;
comment|/* digits before the '.' */
name|Int
name|cut
decl_stmt|;
comment|/* for counting digits in a Unit */
name|char
modifier|*
name|c
init|=
name|string
decl_stmt|;
comment|/* work [output pointer] */
specifier|const
name|Unit
modifier|*
name|up
init|=
name|dn
operator|->
name|lsu
operator|+
name|D2U
argument_list|(
name|dn
operator|->
name|digits
argument_list|)
operator|-
literal|1
decl_stmt|;
comment|/* -> msu [input pointer] */
name|uInt
name|u
decl_stmt|,
name|pow
decl_stmt|;
comment|/* work */
if|#
directive|if
name|DECCHECK
if|if
condition|(
name|decCheckOperands
argument_list|(
name|DECUNUSED
argument_list|,
name|dn
argument_list|,
name|DECUNUSED
argument_list|,
name|DECUNUSED
argument_list|)
condition|)
block|{
name|strcpy
argument_list|(
name|string
argument_list|,
literal|"?"
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
if|if
condition|(
name|decNumberIsNegative
argument_list|(
name|dn
argument_list|)
condition|)
block|{
comment|/* Negatives get a minus (except */
operator|*
name|c
operator|=
literal|'-'
expr_stmt|;
comment|/* NaNs, which remove the '-' below) */
name|c
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|dn
operator|->
name|bits
operator|&
name|DECSPECIAL
condition|)
block|{
comment|/* Is a special value */
if|if
condition|(
name|decNumberIsInfinite
argument_list|(
name|dn
argument_list|)
condition|)
block|{
name|strcpy
argument_list|(
name|c
argument_list|,
literal|"Infinity"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* a NaN */
if|if
condition|(
name|dn
operator|->
name|bits
operator|&
name|DECSNAN
condition|)
block|{
comment|/* signalling NaN */
operator|*
name|c
operator|=
literal|'s'
expr_stmt|;
name|c
operator|++
expr_stmt|;
block|}
name|strcpy
argument_list|(
name|c
argument_list|,
literal|"NaN"
argument_list|)
expr_stmt|;
name|c
operator|+=
literal|3
expr_stmt|;
comment|/* step past */
comment|/* if not a clean non-zero coefficient, that's all we have in a */
comment|/* NaN string */
if|if
condition|(
name|exp
operator|!=
literal|0
operator|||
operator|(
operator|*
name|dn
operator|->
name|lsu
operator|==
literal|0
operator|&&
name|dn
operator|->
name|digits
operator|==
literal|1
operator|)
condition|)
return|return;
comment|/* [drop through to add integer] */
block|}
comment|/* calculate how many digits in msu, and hence first cut */
name|cut
operator|=
name|dn
operator|->
name|digits
operator|%
name|DECDPUN
expr_stmt|;
if|if
condition|(
name|cut
operator|==
literal|0
condition|)
name|cut
operator|=
name|DECDPUN
expr_stmt|;
comment|/* msu is full */
name|cut
operator|--
expr_stmt|;
comment|/* power of ten for digit */
if|if
condition|(
name|exp
operator|==
literal|0
condition|)
block|{
comment|/* simple integer [common fastpath, */
comment|/*   used for NaNs, too] */
for|for
control|(
init|;
name|up
operator|>=
name|dn
operator|->
name|lsu
condition|;
name|up
operator|--
control|)
block|{
comment|/* each Unit from msu */
name|u
operator|=
operator|*
name|up
expr_stmt|;
comment|/* contains DECDPUN digits to lay out */
for|for
control|(
init|;
name|cut
operator|>=
literal|0
condition|;
name|c
operator|++
operator|,
name|cut
operator|--
control|)
name|TODIGIT
argument_list|(
name|u
argument_list|,
name|cut
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|cut
operator|=
name|DECDPUN
operator|-
literal|1
expr_stmt|;
comment|/* next Unit has all digits */
block|}
operator|*
name|c
operator|=
literal|'\0'
expr_stmt|;
comment|/* terminate the string */
return|return;
block|}
comment|/* non-0 exponent -- assume plain form */
name|pre
operator|=
name|dn
operator|->
name|digits
operator|+
name|exp
expr_stmt|;
comment|/* digits before '.' */
name|e
operator|=
literal|0
expr_stmt|;
comment|/* no E */
if|if
condition|(
operator|(
name|exp
operator|>
literal|0
operator|)
operator|||
operator|(
name|pre
operator|<
operator|-
literal|5
operator|)
condition|)
block|{
comment|/* need exponential form */
name|e
operator|=
name|exp
operator|+
name|dn
operator|->
name|digits
operator|-
literal|1
expr_stmt|;
comment|/* calculate E value */
name|pre
operator|=
literal|1
expr_stmt|;
comment|/* assume one digit before '.' */
if|if
condition|(
name|eng
operator|&&
operator|(
name|e
operator|!=
literal|0
operator|)
condition|)
block|{
comment|/* may need to adjust */
name|Int
name|adj
decl_stmt|;
comment|/* adjustment */
comment|/* The C remainder operator is undefined for negative numbers, so */
comment|/* we must use positive remainder calculation here */
if|if
condition|(
name|e
operator|<
literal|0
condition|)
block|{
name|adj
operator|=
operator|(
operator|-
name|e
operator|)
operator|%
literal|3
expr_stmt|;
if|if
condition|(
name|adj
operator|!=
literal|0
condition|)
name|adj
operator|=
literal|3
operator|-
name|adj
expr_stmt|;
block|}
else|else
block|{
comment|/* e>0 */
name|adj
operator|=
name|e
operator|%
literal|3
expr_stmt|;
block|}
name|e
operator|=
name|e
operator|-
name|adj
expr_stmt|;
comment|/* if we are dealing with zero we will use exponent which is a */
comment|/* multiple of three, as expected, but there will only be the */
comment|/* one zero before the E, still.  Otherwise note the padding. */
if|if
condition|(
operator|!
name|ISZERO
argument_list|(
name|dn
argument_list|)
condition|)
name|pre
operator|+=
name|adj
expr_stmt|;
else|else
block|{
comment|/* is zero */
if|if
condition|(
name|adj
operator|!=
literal|0
condition|)
block|{
comment|/* 0.00Esnn needed */
name|e
operator|=
name|e
operator|+
literal|3
expr_stmt|;
name|pre
operator|=
operator|-
operator|(
literal|2
operator|-
name|adj
operator|)
expr_stmt|;
block|}
block|}
comment|/* zero */
block|}
comment|/* eng */
block|}
comment|/* lay out the digits of the coefficient, adding 0s and . as needed */
name|u
operator|=
operator|*
name|up
expr_stmt|;
if|if
condition|(
name|pre
operator|>
literal|0
condition|)
block|{
comment|/* xxx.xxx or xx00 (engineering) form */
for|for
control|(
init|;
name|pre
operator|>
literal|0
condition|;
name|pre
operator|--
operator|,
name|c
operator|++
operator|,
name|cut
operator|--
control|)
block|{
if|if
condition|(
name|cut
operator|<
literal|0
condition|)
block|{
comment|/* need new Unit */
if|if
condition|(
name|up
operator|==
name|dn
operator|->
name|lsu
condition|)
break|break;
comment|/* out of input digits (pre>digits) */
name|up
operator|--
expr_stmt|;
name|cut
operator|=
name|DECDPUN
operator|-
literal|1
expr_stmt|;
name|u
operator|=
operator|*
name|up
expr_stmt|;
block|}
name|TODIGIT
argument_list|(
name|u
argument_list|,
name|cut
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|up
operator|>
name|dn
operator|->
name|lsu
operator|||
operator|(
name|up
operator|==
name|dn
operator|->
name|lsu
operator|&&
name|cut
operator|>=
literal|0
operator|)
condition|)
block|{
comment|/* more to come, after '.' */
operator|*
name|c
operator|=
literal|'.'
expr_stmt|;
name|c
operator|++
expr_stmt|;
for|for
control|(
init|;
condition|;
name|c
operator|++
operator|,
name|cut
operator|--
control|)
block|{
if|if
condition|(
name|cut
operator|<
literal|0
condition|)
block|{
comment|/* need new Unit */
if|if
condition|(
name|up
operator|==
name|dn
operator|->
name|lsu
condition|)
break|break;
comment|/* out of input digits */
name|up
operator|--
expr_stmt|;
name|cut
operator|=
name|DECDPUN
operator|-
literal|1
expr_stmt|;
name|u
operator|=
operator|*
name|up
expr_stmt|;
block|}
name|TODIGIT
argument_list|(
name|u
argument_list|,
name|cut
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
block|}
else|else
for|for
control|(
init|;
name|pre
operator|>
literal|0
condition|;
name|pre
operator|--
operator|,
name|c
operator|++
control|)
operator|*
name|c
operator|=
literal|'0'
expr_stmt|;
comment|/* 0 padding (for engineering) needed */
block|}
else|else
block|{
comment|/* 0.xxx or 0.000xxx form */
operator|*
name|c
operator|=
literal|'0'
expr_stmt|;
name|c
operator|++
expr_stmt|;
operator|*
name|c
operator|=
literal|'.'
expr_stmt|;
name|c
operator|++
expr_stmt|;
for|for
control|(
init|;
name|pre
operator|<
literal|0
condition|;
name|pre
operator|++
operator|,
name|c
operator|++
control|)
operator|*
name|c
operator|=
literal|'0'
expr_stmt|;
comment|/* add any 0's after '.' */
for|for
control|(
init|;
condition|;
name|c
operator|++
operator|,
name|cut
operator|--
control|)
block|{
if|if
condition|(
name|cut
operator|<
literal|0
condition|)
block|{
comment|/* need new Unit */
if|if
condition|(
name|up
operator|==
name|dn
operator|->
name|lsu
condition|)
break|break;
comment|/* out of input digits */
name|up
operator|--
expr_stmt|;
name|cut
operator|=
name|DECDPUN
operator|-
literal|1
expr_stmt|;
name|u
operator|=
operator|*
name|up
expr_stmt|;
block|}
name|TODIGIT
argument_list|(
name|u
argument_list|,
name|cut
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* Finally add the E-part, if needed.  It will never be 0, has a      base maximum and minimum of +999999999 through -999999999, but      could range down to -1999999998 for subnormal numbers */
if|if
condition|(
name|e
operator|!=
literal|0
condition|)
block|{
name|Flag
name|had
init|=
literal|0
decl_stmt|;
comment|/* 1=had non-zero */
operator|*
name|c
operator|=
literal|'E'
expr_stmt|;
name|c
operator|++
expr_stmt|;
operator|*
name|c
operator|=
literal|'+'
expr_stmt|;
name|c
operator|++
expr_stmt|;
comment|/* assume positive */
name|u
operator|=
name|e
expr_stmt|;
comment|/* .. */
if|if
condition|(
name|e
operator|<
literal|0
condition|)
block|{
operator|*
operator|(
name|c
operator|-
literal|1
operator|)
operator|=
literal|'-'
expr_stmt|;
comment|/* oops, need - */
name|u
operator|=
operator|-
name|e
expr_stmt|;
comment|/* uInt, please */
block|}
comment|/* layout the exponent (_itoa is not ANSI C) */
for|for
control|(
name|cut
operator|=
literal|9
init|;
name|cut
operator|>=
literal|0
condition|;
name|cut
operator|--
control|)
block|{
name|TODIGIT
argument_list|(
name|u
argument_list|,
name|cut
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|c
operator|==
literal|'0'
operator|&&
operator|!
name|had
condition|)
continue|continue;
comment|/* skip leading zeros */
name|had
operator|=
literal|1
expr_stmt|;
comment|/* had non-0 */
name|c
operator|++
expr_stmt|;
comment|/* step for next */
block|}
comment|/* cut */
block|}
operator|*
name|c
operator|=
literal|'\0'
expr_stmt|;
comment|/* terminate the string (all paths) */
return|return;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decAddOp -- add/subtract operation                                 */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = A + B                                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A and/or B (e.g., X=X+X)         */
end_comment

begin_comment
comment|/*   lhs is A                                                         */
end_comment

begin_comment
comment|/*   rhs is B                                                         */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*   negate is DECNEG if rhs should be negated, or 0 otherwise        */
end_comment

begin_comment
comment|/*   status accumulates status for the caller                         */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* If possible, we calculate the coefficient directly into C.         */
end_comment

begin_comment
comment|/* However, if:                                                       */
end_comment

begin_comment
comment|/*   -- we need a digits+1 calculation because numbers are unaligned  */
end_comment

begin_comment
comment|/*      and span more than set->digits digits                         */
end_comment

begin_comment
comment|/*   -- a carry to digits+1 digits looks possible                     */
end_comment

begin_comment
comment|/*   -- C is the same as A or B, and the result would destructively   */
end_comment

begin_comment
comment|/*      overlap the A or B coefficient                                */
end_comment

begin_comment
comment|/* then we must calculate into a temporary buffer.  In this latter    */
end_comment

begin_comment
comment|/* case we use the local (stack) buffer if possible, and only if too  */
end_comment

begin_comment
comment|/* long for that do we resort to malloc.                              */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* Misalignment is handled as follows:                                */
end_comment

begin_comment
comment|/*   Apad: (AExp>BExp) Swap operands and proceed as for BExp>AExp.    */
end_comment

begin_comment
comment|/*   BPad: Apply the padding by a combination of shifting (whole      */
end_comment

begin_comment
comment|/*         units) and multiplication (part units).                    */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* Addition, especially x=x+1, is speed-critical, so we take pains    */
end_comment

begin_comment
comment|/* to make returning as fast as possible, by flagging any allocation. */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|decNumber
modifier|*
name|decAddOp
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|,
name|uByte
name|negate
parameter_list|,
name|uInt
modifier|*
name|status
parameter_list|)
block|{
name|decNumber
modifier|*
name|alloclhs
init|=
name|NULL
decl_stmt|;
comment|/* non-NULL if rounded lhs allocated */
name|decNumber
modifier|*
name|allocrhs
init|=
name|NULL
decl_stmt|;
comment|/* .., rhs */
name|Int
name|rhsshift
decl_stmt|;
comment|/* working shift (in Units) */
name|Int
name|maxdigits
decl_stmt|;
comment|/* longest logical length */
name|Int
name|mult
decl_stmt|;
comment|/* multiplier */
name|Int
name|residue
decl_stmt|;
comment|/* rounding accumulator */
name|uByte
name|bits
decl_stmt|;
comment|/* result bits */
name|Flag
name|diffsign
decl_stmt|;
comment|/* non-0 if arguments have different sign */
name|Unit
modifier|*
name|acc
decl_stmt|;
comment|/* accumulator for result */
name|Unit
name|accbuff
index|[
name|D2U
argument_list|(
name|DECBUFFER
operator|+
literal|1
argument_list|)
index|]
decl_stmt|;
comment|/* local buffer [+1 is for possible */
comment|/* final carry digit or DECBUFFER=0] */
name|Unit
modifier|*
name|allocacc
init|=
name|NULL
decl_stmt|;
comment|/* -> allocated acc buffer, iff allocated */
name|Flag
name|alloced
init|=
literal|0
decl_stmt|;
comment|/* set non-0 if any allocations */
name|Int
name|reqdigits
init|=
name|set
operator|->
name|digits
decl_stmt|;
comment|/* local copy; requested DIGITS */
name|uByte
name|merged
decl_stmt|;
comment|/* merged flags */
name|Int
name|padding
decl_stmt|;
comment|/* work */
if|#
directive|if
name|DECCHECK
if|if
condition|(
name|decCheckOperands
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|)
condition|)
return|return
name|res
return|;
endif|#
directive|endif
do|do
block|{
comment|/* protect allocated storage */
if|#
directive|if
name|DECSUBSET
if|if
condition|(
operator|!
name|set
operator|->
name|extended
condition|)
block|{
comment|/* reduce operands and set lostDigits status, as needed */
if|if
condition|(
name|lhs
operator|->
name|digits
operator|>
name|reqdigits
condition|)
block|{
name|alloclhs
operator|=
name|decRoundOperand
argument_list|(
name|lhs
argument_list|,
name|set
argument_list|,
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|alloclhs
operator|==
name|NULL
condition|)
break|break;
name|lhs
operator|=
name|alloclhs
expr_stmt|;
name|alloced
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|rhs
operator|->
name|digits
operator|>
name|reqdigits
condition|)
block|{
name|allocrhs
operator|=
name|decRoundOperand
argument_list|(
name|rhs
argument_list|,
name|set
argument_list|,
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|allocrhs
operator|==
name|NULL
condition|)
break|break;
name|rhs
operator|=
name|allocrhs
expr_stmt|;
name|alloced
operator|=
literal|1
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* [following code does not require input rounding] */
comment|/* note whether signs differ */
name|diffsign
operator|=
call|(
name|Flag
call|)
argument_list|(
operator|(
name|lhs
operator|->
name|bits
operator|^
name|rhs
operator|->
name|bits
operator|^
name|negate
operator|)
operator|&
name|DECNEG
argument_list|)
expr_stmt|;
comment|/* handle infinities and NaNs */
name|merged
operator|=
operator|(
name|lhs
operator|->
name|bits
operator||
name|rhs
operator|->
name|bits
operator|)
operator|&
name|DECSPECIAL
expr_stmt|;
if|if
condition|(
name|merged
condition|)
block|{
comment|/* a special bit set */
if|if
condition|(
name|merged
operator|&
operator|(
name|DECSNAN
operator||
name|DECNAN
operator|)
condition|)
comment|/* a NaN */
name|decNaNs
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|status
argument_list|)
expr_stmt|;
else|else
block|{
comment|/* one or two infinities */
if|if
condition|(
name|decNumberIsInfinite
argument_list|(
name|lhs
argument_list|)
condition|)
block|{
comment|/* LHS is infinity */
comment|/* two infinities with different signs is invalid */
if|if
condition|(
name|decNumberIsInfinite
argument_list|(
name|rhs
argument_list|)
operator|&&
name|diffsign
condition|)
block|{
operator|*
name|status
operator||=
name|DEC_Invalid_operation
expr_stmt|;
break|break;
block|}
name|bits
operator|=
name|lhs
operator|->
name|bits
operator|&
name|DECNEG
expr_stmt|;
comment|/* get sign from LHS */
block|}
else|else
name|bits
operator|=
operator|(
name|rhs
operator|->
name|bits
operator|^
name|negate
operator|)
operator|&
name|DECNEG
expr_stmt|;
comment|/* RHS must be Infinity */
name|bits
operator||=
name|DECINF
expr_stmt|;
name|decNumberZero
argument_list|(
name|res
argument_list|)
expr_stmt|;
name|res
operator|->
name|bits
operator|=
name|bits
expr_stmt|;
comment|/* set +/- infinity */
block|}
comment|/* an infinity */
break|break;
block|}
comment|/* Quick exit for add 0s; return the non-0, modified as need be */
if|if
condition|(
name|ISZERO
argument_list|(
name|lhs
argument_list|)
condition|)
block|{
name|Int
name|adjust
decl_stmt|;
comment|/* work */
name|Int
name|lexp
init|=
name|lhs
operator|->
name|exponent
decl_stmt|;
comment|/* save in case LHS==RES */
name|bits
operator|=
name|lhs
operator|->
name|bits
expr_stmt|;
comment|/* .. */
name|residue
operator|=
literal|0
expr_stmt|;
comment|/* clear accumulator */
name|decCopyFit
argument_list|(
name|res
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
comment|/* copy (as needed) */
name|res
operator|->
name|bits
operator|^=
name|negate
expr_stmt|;
comment|/* flip if rhs was negated */
if|#
directive|if
name|DECSUBSET
if|if
condition|(
name|set
operator|->
name|extended
condition|)
block|{
comment|/* exponents on zeros count */
endif|#
directive|endif
comment|/* exponent will be the lower of the two */
name|adjust
operator|=
name|lexp
operator|-
name|res
operator|->
name|exponent
expr_stmt|;
comment|/* adjustment needed [if -ve] */
if|if
condition|(
name|ISZERO
argument_list|(
name|res
argument_list|)
condition|)
block|{
comment|/* both 0: special IEEE 854 rules */
if|if
condition|(
name|adjust
operator|<
literal|0
condition|)
name|res
operator|->
name|exponent
operator|=
name|lexp
expr_stmt|;
comment|/* set exponent */
comment|/* 0-0 gives +0 unless rounding to -infinity, and -0-0 gives -0 */
if|if
condition|(
name|diffsign
condition|)
block|{
if|if
condition|(
name|set
operator|->
name|round
operator|!=
name|DEC_ROUND_FLOOR
condition|)
name|res
operator|->
name|bits
operator|=
literal|0
expr_stmt|;
else|else
name|res
operator|->
name|bits
operator|=
name|DECNEG
expr_stmt|;
comment|/* preserve 0 sign */
block|}
block|}
else|else
block|{
comment|/* non-0 res */
if|if
condition|(
name|adjust
operator|<
literal|0
condition|)
block|{
comment|/* 0-padding needed */
if|if
condition|(
operator|(
name|res
operator|->
name|digits
operator|-
name|adjust
operator|)
operator|>
name|set
operator|->
name|digits
condition|)
block|{
name|adjust
operator|=
name|res
operator|->
name|digits
operator|-
name|set
operator|->
name|digits
expr_stmt|;
comment|/* to fit exactly */
operator|*
name|status
operator||=
name|DEC_Rounded
expr_stmt|;
comment|/* [but exact] */
block|}
name|res
operator|->
name|digits
operator|=
name|decShiftToMost
argument_list|(
name|res
operator|->
name|lsu
argument_list|,
name|res
operator|->
name|digits
argument_list|,
operator|-
name|adjust
argument_list|)
expr_stmt|;
name|res
operator|->
name|exponent
operator|+=
name|adjust
expr_stmt|;
comment|/* set the exponent. */
block|}
block|}
comment|/* non-0 res */
if|#
directive|if
name|DECSUBSET
block|}
comment|/* extended */
endif|#
directive|endif
name|decFinish
argument_list|(
name|res
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
comment|/* clean and finalize */
break|break;
block|}
if|if
condition|(
name|ISZERO
argument_list|(
name|rhs
argument_list|)
condition|)
block|{
comment|/* [lhs is non-zero] */
name|Int
name|adjust
decl_stmt|;
comment|/* work */
name|Int
name|rexp
init|=
name|rhs
operator|->
name|exponent
decl_stmt|;
comment|/* save in case RHS==RES */
name|bits
operator|=
name|rhs
operator|->
name|bits
expr_stmt|;
comment|/* be clean */
name|residue
operator|=
literal|0
expr_stmt|;
comment|/* clear accumulator */
name|decCopyFit
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
comment|/* copy (as needed) */
if|#
directive|if
name|DECSUBSET
if|if
condition|(
name|set
operator|->
name|extended
condition|)
block|{
comment|/* exponents on zeros count */
endif|#
directive|endif
comment|/* exponent will be the lower of the two */
comment|/* [0-0 case handled above] */
name|adjust
operator|=
name|rexp
operator|-
name|res
operator|->
name|exponent
expr_stmt|;
comment|/* adjustment needed [if -ve] */
if|if
condition|(
name|adjust
operator|<
literal|0
condition|)
block|{
comment|/* 0-padding needed */
if|if
condition|(
operator|(
name|res
operator|->
name|digits
operator|-
name|adjust
operator|)
operator|>
name|set
operator|->
name|digits
condition|)
block|{
name|adjust
operator|=
name|res
operator|->
name|digits
operator|-
name|set
operator|->
name|digits
expr_stmt|;
comment|/* to fit exactly */
operator|*
name|status
operator||=
name|DEC_Rounded
expr_stmt|;
comment|/* [but exact] */
block|}
name|res
operator|->
name|digits
operator|=
name|decShiftToMost
argument_list|(
name|res
operator|->
name|lsu
argument_list|,
name|res
operator|->
name|digits
argument_list|,
operator|-
name|adjust
argument_list|)
expr_stmt|;
name|res
operator|->
name|exponent
operator|+=
name|adjust
expr_stmt|;
comment|/* set the exponent. */
block|}
if|#
directive|if
name|DECSUBSET
block|}
comment|/* extended */
endif|#
directive|endif
name|decFinish
argument_list|(
name|res
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
comment|/* clean and finalize */
break|break;
block|}
comment|/* [both fastpath and mainpath code below assume these cases */
comment|/* (notably 0-0) have already been handled] */
comment|/* calculate the padding needed to align the operands */
name|padding
operator|=
name|rhs
operator|->
name|exponent
operator|-
name|lhs
operator|->
name|exponent
expr_stmt|;
comment|/* Fastpath cases where the numbers are aligned and normal, the RHS */
comment|/* is all in one unit, no operand rounding is needed, and no carry, */
comment|/* lengthening, or borrow is needed */
if|if
condition|(
name|rhs
operator|->
name|digits
operator|<=
name|DECDPUN
operator|&&
name|padding
operator|==
literal|0
operator|&&
name|rhs
operator|->
name|exponent
operator|>=
name|set
operator|->
name|emin
comment|/* [some normals drop through] */
operator|&&
name|rhs
operator|->
name|digits
operator|<=
name|reqdigits
operator|&&
name|lhs
operator|->
name|digits
operator|<=
name|reqdigits
condition|)
block|{
name|Int
name|partial
init|=
operator|*
name|lhs
operator|->
name|lsu
decl_stmt|;
if|if
condition|(
operator|!
name|diffsign
condition|)
block|{
comment|/* adding */
name|Int
name|maxv
init|=
name|DECDPUNMAX
decl_stmt|;
comment|/* highest no-overflow */
if|if
condition|(
name|lhs
operator|->
name|digits
operator|<
name|DECDPUN
condition|)
name|maxv
operator|=
name|powers
index|[
name|lhs
operator|->
name|digits
index|]
operator|-
literal|1
expr_stmt|;
name|partial
operator|+=
operator|*
name|rhs
operator|->
name|lsu
expr_stmt|;
if|if
condition|(
name|partial
operator|<=
name|maxv
condition|)
block|{
comment|/* no carry */
if|if
condition|(
name|res
operator|!=
name|lhs
condition|)
name|decNumberCopy
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|)
expr_stmt|;
comment|/* not in place */
operator|*
name|res
operator|->
name|lsu
operator|=
operator|(
name|Unit
operator|)
name|partial
expr_stmt|;
comment|/* [copy could have overwritten RHS] */
break|break;
block|}
comment|/* else drop out for careful add */
block|}
else|else
block|{
comment|/* signs differ */
name|partial
operator|-=
operator|*
name|rhs
operator|->
name|lsu
expr_stmt|;
if|if
condition|(
name|partial
operator|>
literal|0
condition|)
block|{
comment|/* no borrow needed, and non-0 result */
if|if
condition|(
name|res
operator|!=
name|lhs
condition|)
name|decNumberCopy
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|)
expr_stmt|;
comment|/* not in place */
operator|*
name|res
operator|->
name|lsu
operator|=
operator|(
name|Unit
operator|)
name|partial
expr_stmt|;
comment|/* this could have reduced digits [but result>0] */
name|res
operator|->
name|digits
operator|=
name|decGetDigits
argument_list|(
name|res
operator|->
name|lsu
argument_list|,
name|D2U
argument_list|(
name|res
operator|->
name|digits
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* else drop out for careful subtract */
block|}
block|}
comment|/* Now align (pad) the lhs or rhs so we can add or subtract them, as          necessary.  If one number is much larger than the other (that is,          if in plain form there is a least one digit between the lowest          digit or one and the highest of the other) we need to pad with up          to DIGITS-1 trailing zeros, and then apply rounding (as exotic          rounding modes may be affected by the residue).        */
name|rhsshift
operator|=
literal|0
expr_stmt|;
comment|/* rhs shift to left (padding) in Units */
name|bits
operator|=
name|lhs
operator|->
name|bits
expr_stmt|;
comment|/* assume sign is that of LHS */
name|mult
operator|=
literal|1
expr_stmt|;
comment|/* likely multiplier */
comment|/* if padding==0 the operands are aligned; no padding needed */
if|if
condition|(
name|padding
operator|!=
literal|0
condition|)
block|{
comment|/* some padding needed */
comment|/* We always pad the RHS, as we can then effect any required */
comment|/* padding by a combination of shifts and a multiply */
name|Flag
name|swapped
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|padding
operator|<
literal|0
condition|)
block|{
comment|/* LHS needs the padding */
specifier|const
name|decNumber
modifier|*
name|t
decl_stmt|;
name|padding
operator|=
operator|-
name|padding
expr_stmt|;
comment|/* will be +ve */
name|bits
operator|=
call|(
name|uByte
call|)
argument_list|(
name|rhs
operator|->
name|bits
operator|^
name|negate
argument_list|)
expr_stmt|;
comment|/* assumed sign is now that of RHS */
name|t
operator|=
name|lhs
expr_stmt|;
name|lhs
operator|=
name|rhs
expr_stmt|;
name|rhs
operator|=
name|t
expr_stmt|;
name|swapped
operator|=
literal|1
expr_stmt|;
block|}
comment|/* If, after pad, rhs would be longer than lhs by digits+1 or */
comment|/* more then lhs cannot affect the answer, except as a residue, */
comment|/* so we only need to pad up to a length of DIGITS+1. */
if|if
condition|(
name|rhs
operator|->
name|digits
operator|+
name|padding
operator|>
name|lhs
operator|->
name|digits
operator|+
name|reqdigits
operator|+
literal|1
condition|)
block|{
comment|/* The RHS is sufficient */
comment|/* for residue we use the relative sign indication... */
name|Int
name|shift
init|=
name|reqdigits
operator|-
name|rhs
operator|->
name|digits
decl_stmt|;
comment|/* left shift needed */
name|residue
operator|=
literal|1
expr_stmt|;
comment|/* residue for rounding */
if|if
condition|(
name|diffsign
condition|)
name|residue
operator|=
operator|-
name|residue
expr_stmt|;
comment|/* signs differ */
comment|/* copy, shortening if necessary */
name|decCopyFit
argument_list|(
name|res
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
comment|/* if it was already shorter, then need to pad with zeros */
if|if
condition|(
name|shift
operator|>
literal|0
condition|)
block|{
name|res
operator|->
name|digits
operator|=
name|decShiftToMost
argument_list|(
name|res
operator|->
name|lsu
argument_list|,
name|res
operator|->
name|digits
argument_list|,
name|shift
argument_list|)
expr_stmt|;
name|res
operator|->
name|exponent
operator|-=
name|shift
expr_stmt|;
comment|/* adjust the exponent. */
block|}
comment|/* flip the result sign if unswapped and rhs was negated */
if|if
condition|(
operator|!
name|swapped
condition|)
name|res
operator|->
name|bits
operator|^=
name|negate
expr_stmt|;
name|decFinish
argument_list|(
name|res
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
comment|/* done */
break|break;
block|}
comment|/* LHS digits may affect result */
name|rhsshift
operator|=
name|D2U
argument_list|(
name|padding
operator|+
literal|1
argument_list|)
operator|-
literal|1
expr_stmt|;
comment|/* this much by Unit shift .. */
name|mult
operator|=
name|powers
index|[
name|padding
operator|-
operator|(
name|rhsshift
operator|*
name|DECDPUN
operator|)
index|]
expr_stmt|;
comment|/* .. this by multiplication */
block|}
comment|/* padding needed */
if|if
condition|(
name|diffsign
condition|)
name|mult
operator|=
operator|-
name|mult
expr_stmt|;
comment|/* signs differ */
comment|/* determine the longer operand */
name|maxdigits
operator|=
name|rhs
operator|->
name|digits
operator|+
name|padding
expr_stmt|;
comment|/* virtual length of RHS */
if|if
condition|(
name|lhs
operator|->
name|digits
operator|>
name|maxdigits
condition|)
name|maxdigits
operator|=
name|lhs
operator|->
name|digits
expr_stmt|;
comment|/* Decide on the result buffer to use; if possible place directly */
comment|/* into result. */
name|acc
operator|=
name|res
operator|->
name|lsu
expr_stmt|;
comment|/* assume build direct */
comment|/* If destructive overlap, or the number is too long, or a carry or */
comment|/* borrow to DIGITS+1 might be possible we must use a buffer. */
comment|/* [Might be worth more sophisticated tests when maxdigits==reqdigits] */
if|if
condition|(
operator|(
name|maxdigits
operator|>=
name|reqdigits
operator|)
comment|/* is, or could be, too large */
operator|||
operator|(
name|res
operator|==
name|rhs
operator|&&
name|rhsshift
operator|>
literal|0
operator|)
condition|)
block|{
comment|/* destructive overlap */
comment|/* buffer needed; choose it */
comment|/* we'll need units for maxdigits digits, +1 Unit for carry or borrow */
name|Int
name|need
init|=
name|D2U
argument_list|(
name|maxdigits
argument_list|)
operator|+
literal|1
decl_stmt|;
name|acc
operator|=
name|accbuff
expr_stmt|;
comment|/* assume use local buffer */
if|if
condition|(
name|need
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|accbuff
argument_list|)
condition|)
block|{
name|allocacc
operator|=
operator|(
name|Unit
operator|*
operator|)
name|malloc
argument_list|(
name|need
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|allocacc
operator|==
name|NULL
condition|)
block|{
comment|/* hopeless -- abandon */
operator|*
name|status
operator||=
name|DEC_Insufficient_storage
expr_stmt|;
break|break;
block|}
name|acc
operator|=
name|allocacc
expr_stmt|;
name|alloced
operator|=
literal|1
expr_stmt|;
block|}
block|}
name|res
operator|->
name|bits
operator|=
call|(
name|uByte
call|)
argument_list|(
name|bits
operator|&
name|DECNEG
argument_list|)
expr_stmt|;
comment|/* it's now safe to overwrite.. */
name|res
operator|->
name|exponent
operator|=
name|lhs
operator|->
name|exponent
expr_stmt|;
comment|/* .. operands (even if aliased) */
if|#
directive|if
name|DECTRACE
name|decDumpAr
argument_list|(
literal|'A'
argument_list|,
name|lhs
operator|->
name|lsu
argument_list|,
name|D2U
argument_list|(
name|lhs
operator|->
name|digits
argument_list|)
argument_list|)
expr_stmt|;
name|decDumpAr
argument_list|(
literal|'B'
argument_list|,
name|rhs
operator|->
name|lsu
argument_list|,
name|D2U
argument_list|(
name|rhs
operator|->
name|digits
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  :h: %d %d\n"
argument_list|,
name|rhsshift
argument_list|,
name|mult
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* add [A+B*m] or subtract [A+B*(-m)] */
name|res
operator|->
name|digits
operator|=
name|decUnitAddSub
argument_list|(
name|lhs
operator|->
name|lsu
argument_list|,
name|D2U
argument_list|(
name|lhs
operator|->
name|digits
argument_list|)
argument_list|,
name|rhs
operator|->
name|lsu
argument_list|,
name|D2U
argument_list|(
name|rhs
operator|->
name|digits
argument_list|)
argument_list|,
name|rhsshift
argument_list|,
name|acc
argument_list|,
name|mult
argument_list|)
operator|*
name|DECDPUN
expr_stmt|;
comment|/* [units -> digits] */
if|if
condition|(
name|res
operator|->
name|digits
operator|<
literal|0
condition|)
block|{
comment|/* we borrowed */
name|res
operator|->
name|digits
operator|=
operator|-
name|res
operator|->
name|digits
expr_stmt|;
name|res
operator|->
name|bits
operator|^=
name|DECNEG
expr_stmt|;
comment|/* flip the sign */
block|}
if|#
directive|if
name|DECTRACE
name|decDumpAr
argument_list|(
literal|'+'
argument_list|,
name|acc
argument_list|,
name|D2U
argument_list|(
name|res
operator|->
name|digits
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* If we used a buffer we need to copy back, possibly shortening */
comment|/* (If we didn't use buffer it must have fit, so can't need rounding */
comment|/* and residue must be 0.) */
name|residue
operator|=
literal|0
expr_stmt|;
comment|/* clear accumulator */
if|if
condition|(
name|acc
operator|!=
name|res
operator|->
name|lsu
condition|)
block|{
if|#
directive|if
name|DECSUBSET
if|if
condition|(
name|set
operator|->
name|extended
condition|)
block|{
comment|/* round from first significant digit */
endif|#
directive|endif
comment|/* remove leading zeros that we added due to rounding up to */
comment|/* integral Units -- before the test for rounding. */
if|if
condition|(
name|res
operator|->
name|digits
operator|>
name|reqdigits
condition|)
name|res
operator|->
name|digits
operator|=
name|decGetDigits
argument_list|(
name|acc
argument_list|,
name|D2U
argument_list|(
name|res
operator|->
name|digits
argument_list|)
argument_list|)
expr_stmt|;
name|decSetCoeff
argument_list|(
name|res
argument_list|,
name|set
argument_list|,
name|acc
argument_list|,
name|res
operator|->
name|digits
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
if|#
directive|if
name|DECSUBSET
block|}
else|else
block|{
comment|/* subset arithmetic rounds from original significant digit */
comment|/* We may have an underestimate.  This only occurs when both */
comment|/* numbers fit in DECDPUN digits and we are padding with a */
comment|/* negative multiple (-10, -100...) and the top digit(s) become */
comment|/* 0.  (This only matters if we are using X3.274 rules where the */
comment|/* leading zero could be included in the rounding.) */
if|if
condition|(
name|res
operator|->
name|digits
operator|<
name|maxdigits
condition|)
block|{
operator|*
operator|(
name|acc
operator|+
name|D2U
argument_list|(
name|res
operator|->
name|digits
argument_list|)
operator|)
operator|=
literal|0
expr_stmt|;
comment|/* ensure leading 0 is there */
name|res
operator|->
name|digits
operator|=
name|maxdigits
expr_stmt|;
block|}
else|else
block|{
comment|/* remove leading zeros that we added due to rounding up to */
comment|/* integral Units (but only those in excess of the original */
comment|/* maxdigits length, unless extended) before test for rounding. */
if|if
condition|(
name|res
operator|->
name|digits
operator|>
name|reqdigits
condition|)
block|{
name|res
operator|->
name|digits
operator|=
name|decGetDigits
argument_list|(
name|acc
argument_list|,
name|D2U
argument_list|(
name|res
operator|->
name|digits
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|res
operator|->
name|digits
operator|<
name|maxdigits
condition|)
name|res
operator|->
name|digits
operator|=
name|maxdigits
expr_stmt|;
block|}
block|}
name|decSetCoeff
argument_list|(
name|res
argument_list|,
name|set
argument_list|,
name|acc
argument_list|,
name|res
operator|->
name|digits
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
comment|/* Now apply rounding if needed before removing leading zeros. */
comment|/* This is safe because subnormals are not a possibility */
if|if
condition|(
name|residue
operator|!=
literal|0
condition|)
block|{
name|decApplyRound
argument_list|(
name|res
argument_list|,
name|set
argument_list|,
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
name|residue
operator|=
literal|0
expr_stmt|;
comment|/* we did what we had to do */
block|}
block|}
comment|/* subset */
endif|#
directive|endif
block|}
comment|/* used buffer */
comment|/* strip leading zeros [these were left on in case of subset subtract] */
name|res
operator|->
name|digits
operator|=
name|decGetDigits
argument_list|(
name|res
operator|->
name|lsu
argument_list|,
name|D2U
argument_list|(
name|res
operator|->
name|digits
argument_list|)
argument_list|)
expr_stmt|;
comment|/* apply checks and rounding */
name|decFinish
argument_list|(
name|res
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
comment|/* "When the sum of two operands with opposite signs is exactly */
comment|/* zero, the sign of that sum shall be '+' in all rounding modes */
comment|/* except round toward -Infinity, in which mode that sign shall be */
comment|/* '-'."  [Subset zeros also never have '-', set by decFinish.] */
if|if
condition|(
name|ISZERO
argument_list|(
name|res
argument_list|)
operator|&&
name|diffsign
if|#
directive|if
name|DECSUBSET
operator|&&
name|set
operator|->
name|extended
endif|#
directive|endif
operator|&&
operator|(
operator|*
name|status
operator|&
name|DEC_Inexact
operator|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|set
operator|->
name|round
operator|==
name|DEC_ROUND_FLOOR
condition|)
name|res
operator|->
name|bits
operator||=
name|DECNEG
expr_stmt|;
comment|/* sign - */
else|else
name|res
operator|->
name|bits
operator|&=
operator|~
name|DECNEG
expr_stmt|;
comment|/* sign + */
block|}
block|}
do|while
condition|(
literal|0
condition|)
do|;
comment|/* end protected */
if|if
condition|(
name|alloced
condition|)
block|{
if|if
condition|(
name|allocacc
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|allocacc
argument_list|)
expr_stmt|;
comment|/* drop any storage we used */
if|if
condition|(
name|allocrhs
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|allocrhs
argument_list|)
expr_stmt|;
comment|/* .. */
if|if
condition|(
name|alloclhs
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|alloclhs
argument_list|)
expr_stmt|;
comment|/* .. */
block|}
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decDivideOp -- division operation                                  */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  This routine performs the calculations for all four division      */
end_comment

begin_comment
comment|/*  operators (divide, divideInteger, remainder, remainderNear).      */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  C=A op B                                                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A and/or B (e.g., X=X/X)         */
end_comment

begin_comment
comment|/*   lhs is A                                                         */
end_comment

begin_comment
comment|/*   rhs is B                                                         */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*   op  is DIVIDE, DIVIDEINT, REMAINDER, or REMNEAR respectively.    */
end_comment

begin_comment
comment|/*   status is the usual accumulator                                  */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/*   The underlying algorithm of this routine is the same as in the   */
end_comment

begin_comment
comment|/*   1981 S/370 implementation, that is, non-restoring long division  */
end_comment

begin_comment
comment|/*   with bi-unit (rather than bi-digit) estimation for each unit     */
end_comment

begin_comment
comment|/*   multiplier.  In this pseudocode overview, complications for the  */
end_comment

begin_comment
comment|/*   Remainder operators and division residues for exact rounding are */
end_comment

begin_comment
comment|/*   omitted for clarity.                                             */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*     Prepare operands and handle special values                     */
end_comment

begin_comment
comment|/*     Test for x/0 and then 0/x                                      */
end_comment

begin_comment
comment|/*     Exp =Exp1 - Exp2                                               */
end_comment

begin_comment
comment|/*     Exp =Exp +len(var1) -len(var2)                                 */
end_comment

begin_comment
comment|/*     Sign=Sign1 * Sign2                                             */
end_comment

begin_comment
comment|/*     Pad accumulator (Var1) to double-length with 0's (pad1)        */
end_comment

begin_comment
comment|/*     Pad Var2 to same length as Var1                                */
end_comment

begin_comment
comment|/*     msu2pair/plus=1st 2 or 1 units of var2, +1 to allow for round  */
end_comment

begin_comment
comment|/*     have=0                                                         */
end_comment

begin_comment
comment|/*     Do until (have=digits+1 OR residue=0)                          */
end_comment

begin_comment
comment|/*       if exp<0 then if integer divide/residue then leave           */
end_comment

begin_comment
comment|/*       this_unit=0                                                  */
end_comment

begin_comment
comment|/*       Do forever                                                   */
end_comment

begin_comment
comment|/*          compare numbers                                           */
end_comment

begin_comment
comment|/*          if<0 then leave inner_loop                               */
end_comment

begin_comment
comment|/*          if =0 then (* quick exit without subtract *) do           */
end_comment

begin_comment
comment|/*             this_unit=this_unit+1; output this_unit                */
end_comment

begin_comment
comment|/*             leave outer_loop; end                                  */
end_comment

begin_comment
comment|/*          Compare lengths of numbers (mantissae):                   */
end_comment

begin_comment
comment|/*          If same then tops2=msu2pair -- {units 1&2 of var2}        */
end_comment

begin_comment
comment|/*                  else tops2=msu2plus -- {0, unit 1 of var2}        */
end_comment

begin_comment
comment|/*          tops1=first_unit_of_Var1*10**DECDPUN +second_unit_of_var1 */
end_comment

begin_comment
comment|/*          mult=tops1/tops2  -- Good and safe guess at divisor       */
end_comment

begin_comment
comment|/*          if mult=0 then mult=1                                     */
end_comment

begin_comment
comment|/*          this_unit=this_unit+mult                                  */
end_comment

begin_comment
comment|/*          subtract                                                  */
end_comment

begin_comment
comment|/*          end inner_loop                                            */
end_comment

begin_comment
comment|/*        if have\=0 | this_unit\=0 then do                           */
end_comment

begin_comment
comment|/*          output this_unit                                          */
end_comment

begin_comment
comment|/*          have=have+1; end                                          */
end_comment

begin_comment
comment|/*        var2=var2/10                                                */
end_comment

begin_comment
comment|/*        exp=exp-1                                                   */
end_comment

begin_comment
comment|/*        end outer_loop                                              */
end_comment

begin_comment
comment|/*     exp=exp+1   -- set the proper exponent                         */
end_comment

begin_comment
comment|/*     if have=0 then generate answer=0                               */
end_comment

begin_comment
comment|/*     Return (Result is defined by Var1)                             */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* We need two working buffers during the long division; one (digits+ */
end_comment

begin_comment
comment|/* 1) to accumulate the result, and the other (up to 2*digits+1) for  */
end_comment

begin_comment
comment|/* long subtractions.  These are acc and var1 respectively.           */
end_comment

begin_comment
comment|/* var1 is a copy of the lhs coefficient, var2 is the rhs coefficient.*/
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|decNumber
modifier|*
name|decDivideOp
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|,
name|Flag
name|op
parameter_list|,
name|uInt
modifier|*
name|status
parameter_list|)
block|{
name|decNumber
modifier|*
name|alloclhs
init|=
name|NULL
decl_stmt|;
comment|/* non-NULL if rounded lhs allocated */
name|decNumber
modifier|*
name|allocrhs
init|=
name|NULL
decl_stmt|;
comment|/* .., rhs */
name|Unit
name|accbuff
index|[
name|D2U
argument_list|(
name|DECBUFFER
operator|+
name|DECDPUN
argument_list|)
index|]
decl_stmt|;
comment|/* local buffer */
name|Unit
modifier|*
name|acc
init|=
name|accbuff
decl_stmt|;
comment|/* -> accumulator array for result */
name|Unit
modifier|*
name|allocacc
init|=
name|NULL
decl_stmt|;
comment|/* -> allocated buffer, iff allocated */
name|Unit
modifier|*
name|accnext
decl_stmt|;
comment|/* -> where next digit will go */
name|Int
name|acclength
decl_stmt|;
comment|/* length of acc needed [Units] */
name|Int
name|accunits
decl_stmt|;
comment|/* count of units accumulated */
name|Int
name|accdigits
decl_stmt|;
comment|/* count of digits accumulated */
name|Unit
name|varbuff
index|[
name|D2U
argument_list|(
name|DECBUFFER
operator|*
literal|2
operator|+
name|DECDPUN
argument_list|)
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
index|]
decl_stmt|;
comment|/* buffer for var1 */
name|Unit
modifier|*
name|var1
init|=
name|varbuff
decl_stmt|;
comment|/* -> var1 array for long subtraction */
name|Unit
modifier|*
name|varalloc
init|=
name|NULL
decl_stmt|;
comment|/* -> allocated buffer, iff used */
specifier|const
name|Unit
modifier|*
name|var2
decl_stmt|;
comment|/* -> var2 array */
name|Int
name|var1units
decl_stmt|,
name|var2units
decl_stmt|;
comment|/* actual lengths */
name|Int
name|var2ulen
decl_stmt|;
comment|/* logical length (units) */
name|Int
name|var1initpad
init|=
literal|0
decl_stmt|;
comment|/* var1 initial padding (digits) */
name|Unit
modifier|*
name|msu1
decl_stmt|;
comment|/* -> msu of each var */
specifier|const
name|Unit
modifier|*
name|msu2
decl_stmt|;
comment|/* -> msu of each var */
name|Int
name|msu2plus
decl_stmt|;
comment|/* msu2 plus one [does not vary] */
name|eInt
name|msu2pair
decl_stmt|;
comment|/* msu2 pair plus one [does not vary] */
name|Int
name|maxdigits
decl_stmt|;
comment|/* longest LHS or required acc length */
name|Int
name|mult
decl_stmt|;
comment|/* multiplier for subtraction */
name|Unit
name|thisunit
decl_stmt|;
comment|/* current unit being accumulated */
name|Int
name|residue
decl_stmt|;
comment|/* for rounding */
name|Int
name|reqdigits
init|=
name|set
operator|->
name|digits
decl_stmt|;
comment|/* requested DIGITS */
name|Int
name|exponent
decl_stmt|;
comment|/* working exponent */
name|Int
name|maxexponent
init|=
literal|0
decl_stmt|;
comment|/* DIVIDE maximum exponent if unrounded */
name|uByte
name|bits
decl_stmt|;
comment|/* working sign */
name|uByte
name|merged
decl_stmt|;
comment|/* merged flags */
name|Unit
modifier|*
name|target
decl_stmt|;
comment|/* work */
specifier|const
name|Unit
modifier|*
name|source
decl_stmt|;
comment|/* work */
name|uInt
specifier|const
modifier|*
name|pow
decl_stmt|;
comment|/* .. */
name|Int
name|shift
decl_stmt|,
name|cut
decl_stmt|;
comment|/* .. */
if|#
directive|if
name|DECSUBSET
name|Int
name|dropped
decl_stmt|;
comment|/* work */
endif|#
directive|endif
if|#
directive|if
name|DECCHECK
if|if
condition|(
name|decCheckOperands
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|)
condition|)
return|return
name|res
return|;
endif|#
directive|endif
do|do
block|{
comment|/* protect allocated storage */
if|#
directive|if
name|DECSUBSET
if|if
condition|(
operator|!
name|set
operator|->
name|extended
condition|)
block|{
comment|/* reduce operands and set lostDigits status, as needed */
if|if
condition|(
name|lhs
operator|->
name|digits
operator|>
name|reqdigits
condition|)
block|{
name|alloclhs
operator|=
name|decRoundOperand
argument_list|(
name|lhs
argument_list|,
name|set
argument_list|,
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|alloclhs
operator|==
name|NULL
condition|)
break|break;
name|lhs
operator|=
name|alloclhs
expr_stmt|;
block|}
if|if
condition|(
name|rhs
operator|->
name|digits
operator|>
name|reqdigits
condition|)
block|{
name|allocrhs
operator|=
name|decRoundOperand
argument_list|(
name|rhs
argument_list|,
name|set
argument_list|,
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|allocrhs
operator|==
name|NULL
condition|)
break|break;
name|rhs
operator|=
name|allocrhs
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* [following code does not require input rounding] */
name|bits
operator|=
operator|(
name|lhs
operator|->
name|bits
operator|^
name|rhs
operator|->
name|bits
operator|)
operator|&
name|DECNEG
expr_stmt|;
comment|/* assumed sign for divisions */
comment|/* handle infinities and NaNs */
name|merged
operator|=
operator|(
name|lhs
operator|->
name|bits
operator||
name|rhs
operator|->
name|bits
operator|)
operator|&
name|DECSPECIAL
expr_stmt|;
if|if
condition|(
name|merged
condition|)
block|{
comment|/* a special bit set */
if|if
condition|(
name|merged
operator|&
operator|(
name|DECSNAN
operator||
name|DECNAN
operator|)
condition|)
block|{
comment|/* one or two NaNs */
name|decNaNs
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|status
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* one or two infinities */
if|if
condition|(
name|decNumberIsInfinite
argument_list|(
name|lhs
argument_list|)
condition|)
block|{
comment|/* LHS (dividend) is infinite */
if|if
condition|(
name|decNumberIsInfinite
argument_list|(
name|rhs
argument_list|)
operator|||
comment|/* two infinities are invalid .. */
name|op
operator|&
operator|(
name|REMAINDER
operator||
name|REMNEAR
operator|)
condition|)
block|{
comment|/* as is remainder of infinity */
operator|*
name|status
operator||=
name|DEC_Invalid_operation
expr_stmt|;
break|break;
block|}
comment|/* [Note that infinity/0 raises no exceptions] */
name|decNumberZero
argument_list|(
name|res
argument_list|)
expr_stmt|;
name|res
operator|->
name|bits
operator|=
name|bits
operator||
name|DECINF
expr_stmt|;
comment|/* set +/- infinity */
break|break;
block|}
else|else
block|{
comment|/* RHS (divisor) is infinite */
name|residue
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|op
operator|&
operator|(
name|REMAINDER
operator||
name|REMNEAR
operator|)
condition|)
block|{
comment|/* result is [finished clone of] lhs */
name|decCopyFit
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* a division */
name|decNumberZero
argument_list|(
name|res
argument_list|)
expr_stmt|;
name|res
operator|->
name|bits
operator|=
name|bits
expr_stmt|;
comment|/* set +/- zero */
comment|/* for DIVIDEINT the exponent is always 0.  For DIVIDE, result */
comment|/* is a 0 with infinitely negative exponent, clamped to minimum */
if|if
condition|(
name|op
operator|&
name|DIVIDE
condition|)
block|{
name|res
operator|->
name|exponent
operator|=
name|set
operator|->
name|emin
operator|-
name|set
operator|->
name|digits
operator|+
literal|1
expr_stmt|;
operator|*
name|status
operator||=
name|DEC_Clamped
expr_stmt|;
block|}
block|}
name|decFinish
argument_list|(
name|res
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
comment|/* handle 0 rhs (x/0) */
if|if
condition|(
name|ISZERO
argument_list|(
name|rhs
argument_list|)
condition|)
block|{
comment|/* x/0 is always exceptional */
if|if
condition|(
name|ISZERO
argument_list|(
name|lhs
argument_list|)
condition|)
block|{
name|decNumberZero
argument_list|(
name|res
argument_list|)
expr_stmt|;
comment|/* [after lhs test] */
operator|*
name|status
operator||=
name|DEC_Division_undefined
expr_stmt|;
comment|/* 0/0 will become NaN */
block|}
else|else
block|{
name|decNumberZero
argument_list|(
name|res
argument_list|)
expr_stmt|;
if|if
condition|(
name|op
operator|&
operator|(
name|REMAINDER
operator||
name|REMNEAR
operator|)
condition|)
operator|*
name|status
operator||=
name|DEC_Invalid_operation
expr_stmt|;
else|else
block|{
operator|*
name|status
operator||=
name|DEC_Division_by_zero
expr_stmt|;
comment|/* x/0 */
name|res
operator|->
name|bits
operator|=
name|bits
operator||
name|DECINF
expr_stmt|;
comment|/* .. is +/- Infinity */
block|}
block|}
break|break;
block|}
comment|/* handle 0 lhs (0/x) */
if|if
condition|(
name|ISZERO
argument_list|(
name|lhs
argument_list|)
condition|)
block|{
comment|/* 0/x [x!=0] */
if|#
directive|if
name|DECSUBSET
if|if
condition|(
operator|!
name|set
operator|->
name|extended
condition|)
name|decNumberZero
argument_list|(
name|res
argument_list|)
expr_stmt|;
else|else
block|{
endif|#
directive|endif
if|if
condition|(
name|op
operator|&
name|DIVIDE
condition|)
block|{
name|residue
operator|=
literal|0
expr_stmt|;
name|exponent
operator|=
name|lhs
operator|->
name|exponent
operator|-
name|rhs
operator|->
name|exponent
expr_stmt|;
comment|/* ideal exponent */
name|decNumberCopy
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|)
expr_stmt|;
comment|/* [zeros always fit] */
name|res
operator|->
name|bits
operator|=
name|bits
expr_stmt|;
comment|/* sign as computed */
name|res
operator|->
name|exponent
operator|=
name|exponent
expr_stmt|;
comment|/* exponent, too */
name|decFinalize
argument_list|(
name|res
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
comment|/* check exponent */
block|}
elseif|else
if|if
condition|(
name|op
operator|&
name|DIVIDEINT
condition|)
block|{
name|decNumberZero
argument_list|(
name|res
argument_list|)
expr_stmt|;
comment|/* integer 0 */
name|res
operator|->
name|bits
operator|=
name|bits
expr_stmt|;
comment|/* sign as computed */
block|}
else|else
block|{
comment|/* a remainder */
name|exponent
operator|=
name|rhs
operator|->
name|exponent
expr_stmt|;
comment|/* [save in case overwrite] */
name|decNumberCopy
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|)
expr_stmt|;
comment|/* [zeros always fit] */
if|if
condition|(
name|exponent
operator|<
name|res
operator|->
name|exponent
condition|)
name|res
operator|->
name|exponent
operator|=
name|exponent
expr_stmt|;
comment|/* use lower */
block|}
if|#
directive|if
name|DECSUBSET
block|}
endif|#
directive|endif
break|break;
block|}
comment|/* Precalculate exponent.  This starts off adjusted (and hence fits */
comment|/* in 31 bits) and becomes the usual unadjusted exponent as the */
comment|/* division proceeds.  The order of evaluation is important, here, */
comment|/* to avoid wrap. */
name|exponent
operator|=
operator|(
name|lhs
operator|->
name|exponent
operator|+
name|lhs
operator|->
name|digits
operator|)
operator|-
operator|(
name|rhs
operator|->
name|exponent
operator|+
name|rhs
operator|->
name|digits
operator|)
expr_stmt|;
comment|/* If the working exponent is -ve, then some quick exits are */
comment|/* possible because the quotient is known to be<1 */
comment|/* [for REMNEAR, it needs to be< -1, as -0.5 could need work] */
if|if
condition|(
name|exponent
operator|<
literal|0
operator|&&
operator|!
operator|(
name|op
operator|==
name|DIVIDE
operator|)
condition|)
block|{
if|if
condition|(
name|op
operator|&
name|DIVIDEINT
condition|)
block|{
name|decNumberZero
argument_list|(
name|res
argument_list|)
expr_stmt|;
comment|/* integer part is 0 */
if|#
directive|if
name|DECSUBSET
if|if
condition|(
name|set
operator|->
name|extended
condition|)
endif|#
directive|endif
name|res
operator|->
name|bits
operator|=
name|bits
expr_stmt|;
comment|/* set +/- zero */
break|break;
block|}
comment|/* we can fastpath remainders so long as the lhs has the */
comment|/* smaller (or equal) exponent */
if|if
condition|(
name|lhs
operator|->
name|exponent
operator|<=
name|rhs
operator|->
name|exponent
condition|)
block|{
if|if
condition|(
name|op
operator|&
name|REMAINDER
operator|||
name|exponent
operator|<
operator|-
literal|1
condition|)
block|{
comment|/* It is REMAINDER or safe REMNEAR; result is [finished */
comment|/* clone of] lhs  (r = x - 0*y) */
name|residue
operator|=
literal|0
expr_stmt|;
name|decCopyFit
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
name|decFinish
argument_list|(
name|res
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* [unsafe REMNEAR drops through] */
block|}
block|}
comment|/* fastpaths */
comment|/* We need long (slow) division; roll up the sleeves... */
comment|/* The accumulator will hold the quotient of the division. */
comment|/* If it needs to be too long for stack storage, then allocate. */
name|acclength
operator|=
name|D2U
argument_list|(
name|reqdigits
operator|+
name|DECDPUN
argument_list|)
expr_stmt|;
comment|/* in Units */
if|if
condition|(
name|acclength
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|accbuff
argument_list|)
condition|)
block|{
name|allocacc
operator|=
operator|(
name|Unit
operator|*
operator|)
name|malloc
argument_list|(
name|acclength
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|allocacc
operator|==
name|NULL
condition|)
block|{
comment|/* hopeless -- abandon */
operator|*
name|status
operator||=
name|DEC_Insufficient_storage
expr_stmt|;
break|break;
block|}
name|acc
operator|=
name|allocacc
expr_stmt|;
comment|/* use the allocated space */
block|}
comment|/* var1 is the padded LHS ready for subtractions. */
comment|/* If it needs to be too long for stack storage, then allocate. */
comment|/* The maximum units we need for var1 (long subtraction) is: */
comment|/* Enough for */
comment|/*     (rhs->digits+reqdigits-1) -- to allow full slide to right */
comment|/* or  (lhs->digits)             -- to allow for long lhs */
comment|/* whichever is larger */
comment|/*   +1                -- for rounding of slide to right */
comment|/*   +1                -- for leading 0s */
comment|/*   +1                -- for pre-adjust if a remainder or DIVIDEINT */
comment|/* [Note: unused units do not participate in decUnitAddSub data] */
name|maxdigits
operator|=
name|rhs
operator|->
name|digits
operator|+
name|reqdigits
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|lhs
operator|->
name|digits
operator|>
name|maxdigits
condition|)
name|maxdigits
operator|=
name|lhs
operator|->
name|digits
expr_stmt|;
name|var1units
operator|=
name|D2U
argument_list|(
name|maxdigits
argument_list|)
operator|+
literal|2
expr_stmt|;
comment|/* allocate a guard unit above msu1 for REMAINDERNEAR */
if|if
condition|(
operator|!
operator|(
name|op
operator|&
name|DIVIDE
operator|)
condition|)
name|var1units
operator|++
expr_stmt|;
if|if
condition|(
operator|(
name|var1units
operator|+
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|varbuff
argument_list|)
condition|)
block|{
name|varalloc
operator|=
operator|(
name|Unit
operator|*
operator|)
name|malloc
argument_list|(
operator|(
name|var1units
operator|+
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|varalloc
operator|==
name|NULL
condition|)
block|{
comment|/* hopeless -- abandon */
operator|*
name|status
operator||=
name|DEC_Insufficient_storage
expr_stmt|;
break|break;
block|}
name|var1
operator|=
name|varalloc
expr_stmt|;
comment|/* use the allocated space */
block|}
comment|/* Extend the lhs and rhs to full long subtraction length.  The lhs */
comment|/* is truly extended into the var1 buffer, with 0 padding, so we can */
comment|/* subtract in place.  The rhs (var2) has virtual padding */
comment|/* (implemented by decUnitAddSub). */
comment|/* We allocated one guard unit above msu1 for rem=rem+rem in REMAINDERNEAR */
name|msu1
operator|=
name|var1
operator|+
name|var1units
operator|-
literal|1
expr_stmt|;
comment|/* msu of var1 */
name|source
operator|=
name|lhs
operator|->
name|lsu
operator|+
name|D2U
argument_list|(
name|lhs
operator|->
name|digits
argument_list|)
operator|-
literal|1
expr_stmt|;
comment|/* msu of input array */
for|for
control|(
name|target
operator|=
name|msu1
init|;
name|source
operator|>=
name|lhs
operator|->
name|lsu
condition|;
name|source
operator|--
operator|,
name|target
operator|--
control|)
operator|*
name|target
operator|=
operator|*
name|source
expr_stmt|;
for|for
control|(
init|;
name|target
operator|>=
name|var1
condition|;
name|target
operator|--
control|)
operator|*
name|target
operator|=
literal|0
expr_stmt|;
comment|/* rhs (var2) is left-aligned with var1 at the start */
name|var2ulen
operator|=
name|var1units
expr_stmt|;
comment|/* rhs logical length (units) */
name|var2units
operator|=
name|D2U
argument_list|(
name|rhs
operator|->
name|digits
argument_list|)
expr_stmt|;
comment|/* rhs actual length (units) */
name|var2
operator|=
name|rhs
operator|->
name|lsu
expr_stmt|;
comment|/* -> rhs array */
name|msu2
operator|=
name|var2
operator|+
name|var2units
operator|-
literal|1
expr_stmt|;
comment|/* -> msu of var2 [never changes] */
comment|/* now set up the variables which we'll use for estimating the */
comment|/* multiplication factor.  If these variables are not exact, we add */
comment|/* 1 to make sure that we never overestimate the multiplier. */
name|msu2plus
operator|=
operator|*
name|msu2
expr_stmt|;
comment|/* it's value .. */
if|if
condition|(
name|var2units
operator|>
literal|1
condition|)
name|msu2plus
operator|++
expr_stmt|;
comment|/* .. +1 if any more */
name|msu2pair
operator|=
operator|(
name|eInt
operator|)
operator|*
name|msu2
operator|*
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
expr_stmt|;
comment|/* top two pair .. */
if|if
condition|(
name|var2units
operator|>
literal|1
condition|)
block|{
comment|/* .. [else treat 2nd as 0] */
name|msu2pair
operator|+=
operator|*
operator|(
name|msu2
operator|-
literal|1
operator|)
expr_stmt|;
comment|/* .. */
if|if
condition|(
name|var2units
operator|>
literal|2
condition|)
name|msu2pair
operator|++
expr_stmt|;
comment|/* .. +1 if any more */
block|}
comment|/* Since we are working in units, the units may have leading zeros, */
comment|/* but we calculated the exponent on the assumption that they are */
comment|/* both left-aligned.  Adjust the exponent to compensate: add the */
comment|/* number of leading zeros in var1 msu and subtract those in var2 msu. */
comment|/* [We actually do this by counting the digits and negating, as */
comment|/* lead1=DECDPUN-digits1, and similarly for lead2.] */
for|for
control|(
name|pow
operator|=
operator|&
name|powers
index|[
literal|1
index|]
init|;
operator|*
name|msu1
operator|>=
operator|*
name|pow
condition|;
name|pow
operator|++
control|)
name|exponent
operator|--
expr_stmt|;
for|for
control|(
name|pow
operator|=
operator|&
name|powers
index|[
literal|1
index|]
init|;
operator|*
name|msu2
operator|>=
operator|*
name|pow
condition|;
name|pow
operator|++
control|)
name|exponent
operator|++
expr_stmt|;
comment|/* Now, if doing an integer divide or remainder, we want to ensure */
comment|/* that the result will be Unit-aligned.  To do this, we shift the */
comment|/* var1 accumulator towards least if need be.  (It's much easier to */
comment|/* do this now than to reassemble the residue afterwards, if we are */
comment|/* doing a remainder.)  Also ensure the exponent is not negative. */
if|if
condition|(
operator|!
operator|(
name|op
operator|&
name|DIVIDE
operator|)
condition|)
block|{
name|Unit
modifier|*
name|u
decl_stmt|;
comment|/* save the initial 'false' padding of var1, in digits */
name|var1initpad
operator|=
operator|(
name|var1units
operator|-
name|D2U
argument_list|(
name|lhs
operator|->
name|digits
argument_list|)
operator|)
operator|*
name|DECDPUN
expr_stmt|;
comment|/* Determine the shift to do. */
if|if
condition|(
name|exponent
operator|<
literal|0
condition|)
name|cut
operator|=
operator|-
name|exponent
expr_stmt|;
else|else
name|cut
operator|=
name|DECDPUN
operator|-
name|exponent
operator|%
name|DECDPUN
expr_stmt|;
name|decShiftToLeast
argument_list|(
name|var1
argument_list|,
name|var1units
argument_list|,
name|cut
argument_list|)
expr_stmt|;
name|exponent
operator|+=
name|cut
expr_stmt|;
comment|/* maintain numerical value */
name|var1initpad
operator|-=
name|cut
expr_stmt|;
comment|/* .. and reduce padding */
comment|/* clean any most-significant units we just emptied */
for|for
control|(
name|u
operator|=
name|msu1
init|;
name|cut
operator|>=
name|DECDPUN
condition|;
name|cut
operator|-=
name|DECDPUN
operator|,
name|u
operator|--
control|)
operator|*
name|u
operator|=
literal|0
expr_stmt|;
block|}
comment|/* align */
else|else
block|{
comment|/* is DIVIDE */
name|maxexponent
operator|=
name|lhs
operator|->
name|exponent
operator|-
name|rhs
operator|->
name|exponent
expr_stmt|;
comment|/* save */
comment|/* optimization: if the first iteration will just produce 0, */
comment|/* preadjust to skip it [valid for DIVIDE only] */
if|if
condition|(
operator|*
name|msu1
operator|<
operator|*
name|msu2
condition|)
block|{
name|var2ulen
operator|--
expr_stmt|;
comment|/* shift down */
name|exponent
operator|-=
name|DECDPUN
expr_stmt|;
comment|/* update the exponent */
block|}
block|}
comment|/* ---- start the long-division loops ------------------------------ */
name|accunits
operator|=
literal|0
expr_stmt|;
comment|/* no units accumulated yet */
name|accdigits
operator|=
literal|0
expr_stmt|;
comment|/* .. or digits */
name|accnext
operator|=
name|acc
operator|+
name|acclength
operator|-
literal|1
expr_stmt|;
comment|/* -> msu of acc [NB: allows digits+1] */
for|for
control|(
init|;
condition|;
control|)
block|{
comment|/* outer forever loop */
name|thisunit
operator|=
literal|0
expr_stmt|;
comment|/* current unit assumed 0 */
comment|/* find the next unit */
for|for
control|(
init|;
condition|;
control|)
block|{
comment|/* inner forever loop */
comment|/* strip leading zero units [from either pre-adjust or from */
comment|/* subtract last time around].  Leave at least one unit. */
for|for
control|(
init|;
operator|*
name|msu1
operator|==
literal|0
operator|&&
name|msu1
operator|>
name|var1
condition|;
name|msu1
operator|--
control|)
name|var1units
operator|--
expr_stmt|;
if|if
condition|(
name|var1units
operator|<
name|var2ulen
condition|)
break|break;
comment|/* var1 too low for subtract */
if|if
condition|(
name|var1units
operator|==
name|var2ulen
condition|)
block|{
comment|/* unit-by-unit compare needed */
comment|/* compare the two numbers, from msu */
name|Unit
modifier|*
name|pv1
decl_stmt|,
name|v2
decl_stmt|;
comment|/* units to compare */
specifier|const
name|Unit
modifier|*
name|pv2
decl_stmt|;
comment|/* units to compare */
name|pv2
operator|=
name|msu2
expr_stmt|;
comment|/* -> msu */
for|for
control|(
name|pv1
operator|=
name|msu1
init|;
condition|;
name|pv1
operator|--
operator|,
name|pv2
operator|--
control|)
block|{
comment|/* v1=*pv1 -- always OK */
name|v2
operator|=
literal|0
expr_stmt|;
comment|/* assume in padding */
if|if
condition|(
name|pv2
operator|>=
name|var2
condition|)
name|v2
operator|=
operator|*
name|pv2
expr_stmt|;
comment|/* in range */
if|if
condition|(
operator|*
name|pv1
operator|!=
name|v2
condition|)
break|break;
comment|/* no longer the same */
if|if
condition|(
name|pv1
operator|==
name|var1
condition|)
break|break;
comment|/* done; leave pv1 as is */
block|}
comment|/* here when all inspected or a difference seen */
if|if
condition|(
operator|*
name|pv1
operator|<
name|v2
condition|)
break|break;
comment|/* var1 too low to subtract */
if|if
condition|(
operator|*
name|pv1
operator|==
name|v2
condition|)
block|{
comment|/* var1 == var2 */
comment|/* reach here if var1 and var2 are identical; subtraction */
comment|/* would increase digit by one, and the residue will be 0 so */
comment|/* we are done; leave the loop with residue set to 0. */
name|thisunit
operator|++
expr_stmt|;
comment|/* as though subtracted */
operator|*
name|var1
operator|=
literal|0
expr_stmt|;
comment|/* set var1 to 0 */
name|var1units
operator|=
literal|1
expr_stmt|;
comment|/* .. */
break|break;
comment|/* from inner */
block|}
comment|/* var1 == var2 */
comment|/* *pv1>v2.  Prepare for real subtraction; the lengths are equal */
comment|/* Estimate the multiplier (there's always a msu1-1)... */
comment|/* Bring in two units of var2 to provide a good estimate. */
name|mult
operator|=
call|(
name|Int
call|)
argument_list|(
operator|(
operator|(
name|eInt
operator|)
operator|*
name|msu1
operator|*
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
operator|+
operator|*
operator|(
name|msu1
operator|-
literal|1
operator|)
operator|)
operator|/
name|msu2pair
argument_list|)
expr_stmt|;
block|}
comment|/* lengths the same */
else|else
block|{
comment|/* var1units> var2ulen, so subtraction is safe */
comment|/* The var2 msu is one unit towards the lsu of the var1 msu, */
comment|/* so we can only use one unit for var2. */
name|mult
operator|=
call|(
name|Int
call|)
argument_list|(
operator|(
operator|(
name|eInt
operator|)
operator|*
name|msu1
operator|*
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
operator|+
operator|*
operator|(
name|msu1
operator|-
literal|1
operator|)
operator|)
operator|/
name|msu2plus
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|mult
operator|==
literal|0
condition|)
name|mult
operator|=
literal|1
expr_stmt|;
comment|/* must always be at least 1 */
comment|/* subtraction needed; var1 is> var2 */
name|thisunit
operator|=
call|(
name|Unit
call|)
argument_list|(
name|thisunit
operator|+
name|mult
argument_list|)
expr_stmt|;
comment|/* accumulate */
comment|/* subtract var1-var2, into var1; only the overlap needs */
comment|/* processing, as we are in place */
name|shift
operator|=
name|var2ulen
operator|-
name|var2units
expr_stmt|;
if|#
directive|if
name|DECTRACE
name|decDumpAr
argument_list|(
literal|'1'
argument_list|,
operator|&
name|var1
index|[
name|shift
index|]
argument_list|,
name|var1units
operator|-
name|shift
argument_list|)
expr_stmt|;
name|decDumpAr
argument_list|(
literal|'2'
argument_list|,
name|var2
argument_list|,
name|var2units
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"m=%d\n"
argument_list|,
operator|-
name|mult
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|decUnitAddSub
argument_list|(
operator|&
name|var1
index|[
name|shift
index|]
argument_list|,
name|var1units
operator|-
name|shift
argument_list|,
name|var2
argument_list|,
name|var2units
argument_list|,
literal|0
argument_list|,
operator|&
name|var1
index|[
name|shift
index|]
argument_list|,
operator|-
name|mult
argument_list|)
expr_stmt|;
if|#
directive|if
name|DECTRACE
name|decDumpAr
argument_list|(
literal|'#'
argument_list|,
operator|&
name|var1
index|[
name|shift
index|]
argument_list|,
name|var1units
operator|-
name|shift
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* var1 now probably has leading zeros; these are removed at the */
comment|/* top of the inner loop. */
block|}
comment|/* inner loop */
comment|/* We have the next unit; unless it's a leading zero, add to acc */
if|if
condition|(
name|accunits
operator|!=
literal|0
operator|||
name|thisunit
operator|!=
literal|0
condition|)
block|{
comment|/* put the unit we got */
operator|*
name|accnext
operator|=
name|thisunit
expr_stmt|;
comment|/* store in accumulator */
comment|/* account exactly for the digits we got */
if|if
condition|(
name|accunits
operator|==
literal|0
condition|)
block|{
name|accdigits
operator|++
expr_stmt|;
comment|/* at least one */
for|for
control|(
name|pow
operator|=
operator|&
name|powers
index|[
literal|1
index|]
init|;
name|thisunit
operator|>=
operator|*
name|pow
condition|;
name|pow
operator|++
control|)
name|accdigits
operator|++
expr_stmt|;
block|}
else|else
name|accdigits
operator|+=
name|DECDPUN
expr_stmt|;
name|accunits
operator|++
expr_stmt|;
comment|/* update count */
name|accnext
operator|--
expr_stmt|;
comment|/* ready for next */
if|if
condition|(
name|accdigits
operator|>
name|reqdigits
condition|)
break|break;
comment|/* we have all we need */
block|}
comment|/* if the residue is zero, we're done (unless divide or */
comment|/* divideInteger and we haven't got enough digits yet) */
if|if
condition|(
operator|*
name|var1
operator|==
literal|0
operator|&&
name|var1units
operator|==
literal|1
condition|)
block|{
comment|/* residue is 0 */
if|if
condition|(
name|op
operator|&
operator|(
name|REMAINDER
operator||
name|REMNEAR
operator|)
condition|)
break|break;
if|if
condition|(
operator|(
name|op
operator|&
name|DIVIDE
operator|)
operator|&&
operator|(
name|exponent
operator|<=
name|maxexponent
operator|)
condition|)
break|break;
comment|/* [drop through if divideInteger] */
block|}
comment|/* we've also done enough if calculating remainder or integer */
comment|/* divide and we just did the last ('units') unit */
if|if
condition|(
name|exponent
operator|==
literal|0
operator|&&
operator|!
operator|(
name|op
operator|&
name|DIVIDE
operator|)
condition|)
break|break;
comment|/* to get here, var1 is less than var2, so divide var2 by the per- */
comment|/* Unit power of ten and go for the next digit */
name|var2ulen
operator|--
expr_stmt|;
comment|/* shift down */
name|exponent
operator|-=
name|DECDPUN
expr_stmt|;
comment|/* update the exponent */
block|}
comment|/* outer loop */
comment|/* ---- division is complete --------------------------------------- */
comment|/* here: acc      has at least reqdigits+1 of good results (or fewer */
comment|/*                if early stop), starting at accnext+1 (its lsu) */
comment|/*       var1     has any residue at the stopping point */
comment|/*       accunits is the number of digits we collected in acc */
if|if
condition|(
name|accunits
operator|==
literal|0
condition|)
block|{
comment|/* acc is 0 */
name|accunits
operator|=
literal|1
expr_stmt|;
comment|/* show we have one .. */
name|accdigits
operator|=
literal|1
expr_stmt|;
comment|/* .. */
operator|*
name|accnext
operator|=
literal|0
expr_stmt|;
comment|/* .. whose value is 0 */
block|}
else|else
name|accnext
operator|++
expr_stmt|;
comment|/* back to last placed */
comment|/* accnext now -> lowest unit of result */
name|residue
operator|=
literal|0
expr_stmt|;
comment|/* assume no residue */
if|if
condition|(
name|op
operator|&
name|DIVIDE
condition|)
block|{
comment|/* record the presence of any residue, for rounding */
if|if
condition|(
operator|*
name|var1
operator|!=
literal|0
operator|||
name|var1units
operator|>
literal|1
condition|)
name|residue
operator|=
literal|1
expr_stmt|;
else|else
block|{
comment|/* no residue */
comment|/* We had an exact division; clean up spurious trailing 0s. */
comment|/* There will be at most DECDPUN-1, from the final multiply, */
comment|/* and then only if the result is non-0 (and even) and the */
comment|/* exponent is 'loose'. */
if|#
directive|if
name|DECDPUN
operator|>
literal|1
name|Unit
name|lsu
init|=
operator|*
name|accnext
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|lsu
operator|&
literal|0x01
operator|)
operator|&&
operator|(
name|lsu
operator|!=
literal|0
operator|)
condition|)
block|{
comment|/* count the trailing zeros */
name|Int
name|drop
init|=
literal|0
decl_stmt|;
for|for
control|(
init|;
condition|;
name|drop
operator|++
control|)
block|{
comment|/* [will terminate because lsu!=0] */
if|if
condition|(
name|exponent
operator|>=
name|maxexponent
condition|)
break|break;
comment|/* don't chop real 0s */
if|#
directive|if
name|DECDPUN
operator|<=
literal|4
if|if
condition|(
operator|(
name|lsu
operator|-
name|QUOT10
argument_list|(
name|lsu
argument_list|,
name|drop
operator|+
literal|1
argument_list|)
operator|*
name|powers
index|[
name|drop
operator|+
literal|1
index|]
operator|)
operator|!=
literal|0
condition|)
break|break;
comment|/* found non-0 digit */
else|#
directive|else
if|if
condition|(
name|lsu
operator|%
name|powers
index|[
name|drop
operator|+
literal|1
index|]
operator|!=
literal|0
condition|)
break|break;
comment|/* found non-0 digit */
endif|#
directive|endif
name|exponent
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|drop
operator|>
literal|0
condition|)
block|{
name|accunits
operator|=
name|decShiftToLeast
argument_list|(
name|accnext
argument_list|,
name|accunits
argument_list|,
name|drop
argument_list|)
expr_stmt|;
name|accdigits
operator|=
name|decGetDigits
argument_list|(
name|accnext
argument_list|,
name|accunits
argument_list|)
expr_stmt|;
name|accunits
operator|=
name|D2U
argument_list|(
name|accdigits
argument_list|)
expr_stmt|;
comment|/* [exponent was adjusted in the loop] */
block|}
block|}
comment|/* neither odd nor 0 */
endif|#
directive|endif
block|}
comment|/* exact divide */
block|}
comment|/* divide */
else|else
comment|/* op!=DIVIDE */
block|{
comment|/* check for coefficient overflow */
if|if
condition|(
name|accdigits
operator|+
name|exponent
operator|>
name|reqdigits
condition|)
block|{
operator|*
name|status
operator||=
name|DEC_Division_impossible
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|op
operator|&
operator|(
name|REMAINDER
operator||
name|REMNEAR
operator|)
condition|)
block|{
comment|/* [Here, the exponent will be 0, because we adjusted var1 */
comment|/* appropriately.] */
name|Int
name|postshift
decl_stmt|;
comment|/* work */
name|Flag
name|wasodd
init|=
literal|0
decl_stmt|;
comment|/* integer was odd */
name|Unit
modifier|*
name|quotlsu
decl_stmt|;
comment|/* for save */
name|Int
name|quotdigits
decl_stmt|;
comment|/* .. */
comment|/* Fastpath when residue is truly 0 is worthwhile [and */
comment|/* simplifies the code below] */
if|if
condition|(
operator|*
name|var1
operator|==
literal|0
operator|&&
name|var1units
operator|==
literal|1
condition|)
block|{
comment|/* residue is 0 */
name|Int
name|exp
init|=
name|lhs
operator|->
name|exponent
decl_stmt|;
comment|/* save min(exponents) */
if|if
condition|(
name|rhs
operator|->
name|exponent
operator|<
name|exp
condition|)
name|exp
operator|=
name|rhs
operator|->
name|exponent
expr_stmt|;
name|decNumberZero
argument_list|(
name|res
argument_list|)
expr_stmt|;
comment|/* 0 coefficient */
if|#
directive|if
name|DECSUBSET
if|if
condition|(
name|set
operator|->
name|extended
condition|)
endif|#
directive|endif
name|res
operator|->
name|exponent
operator|=
name|exp
expr_stmt|;
comment|/* .. with proper exponent */
break|break;
block|}
comment|/* note if the quotient was odd */
if|if
condition|(
operator|*
name|accnext
operator|&
literal|0x01
condition|)
name|wasodd
operator|=
literal|1
expr_stmt|;
comment|/* acc is odd */
name|quotlsu
operator|=
name|accnext
expr_stmt|;
comment|/* save in case need to reinspect */
name|quotdigits
operator|=
name|accdigits
expr_stmt|;
comment|/* .. */
comment|/* treat the residue, in var1, as the value to return, via acc */
comment|/* calculate the unused zero digits.  This is the smaller of: */
comment|/*   var1 initial padding (saved above) */
comment|/*   var2 residual padding, which happens to be given by: */
name|postshift
operator|=
name|var1initpad
operator|+
name|exponent
operator|-
name|lhs
operator|->
name|exponent
operator|+
name|rhs
operator|->
name|exponent
expr_stmt|;
comment|/* [the 'exponent' term accounts for the shifts during divide] */
if|if
condition|(
name|var1initpad
operator|<
name|postshift
condition|)
name|postshift
operator|=
name|var1initpad
expr_stmt|;
comment|/* shift var1 the requested amount, and adjust its digits */
name|var1units
operator|=
name|decShiftToLeast
argument_list|(
name|var1
argument_list|,
name|var1units
argument_list|,
name|postshift
argument_list|)
expr_stmt|;
name|accnext
operator|=
name|var1
expr_stmt|;
name|accdigits
operator|=
name|decGetDigits
argument_list|(
name|var1
argument_list|,
name|var1units
argument_list|)
expr_stmt|;
name|accunits
operator|=
name|D2U
argument_list|(
name|accdigits
argument_list|)
expr_stmt|;
name|exponent
operator|=
name|lhs
operator|->
name|exponent
expr_stmt|;
comment|/* exponent is smaller of lhs& rhs */
if|if
condition|(
name|rhs
operator|->
name|exponent
operator|<
name|exponent
condition|)
name|exponent
operator|=
name|rhs
operator|->
name|exponent
expr_stmt|;
name|bits
operator|=
name|lhs
operator|->
name|bits
expr_stmt|;
comment|/* remainder sign is always as lhs */
comment|/* Now correct the result if we are doing remainderNear; if it */
comment|/* (looking just at coefficients) is> rhs/2, or == rhs/2 and */
comment|/* the integer was odd then the result should be rem-rhs. */
if|if
condition|(
name|op
operator|&
name|REMNEAR
condition|)
block|{
name|Int
name|compare
decl_stmt|,
name|tarunits
decl_stmt|;
comment|/* work */
name|Unit
modifier|*
name|up
decl_stmt|;
comment|/* .. */
comment|/* calculate remainder*2 into the var1 buffer (which has */
comment|/* 'headroom' of an extra unit and hence enough space) */
comment|/* [a dedicated 'double' loop would be faster, here] */
name|tarunits
operator|=
name|decUnitAddSub
argument_list|(
name|accnext
argument_list|,
name|accunits
argument_list|,
name|accnext
argument_list|,
name|accunits
argument_list|,
literal|0
argument_list|,
name|accnext
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* decDumpAr('r', accnext, tarunits); */
comment|/* Here, accnext (var1) holds tarunits Units with twice the */
comment|/* remainder's coefficient, which we must now compare to the */
comment|/* RHS.  The remainder's exponent may be smaller than the RHS's. */
name|compare
operator|=
name|decUnitCompare
argument_list|(
name|accnext
argument_list|,
name|tarunits
argument_list|,
name|rhs
operator|->
name|lsu
argument_list|,
name|D2U
argument_list|(
name|rhs
operator|->
name|digits
argument_list|)
argument_list|,
name|rhs
operator|->
name|exponent
operator|-
name|exponent
argument_list|)
expr_stmt|;
if|if
condition|(
name|compare
operator|==
name|BADINT
condition|)
block|{
comment|/* deep trouble */
operator|*
name|status
operator||=
name|DEC_Insufficient_storage
expr_stmt|;
break|break;
block|}
comment|/* now restore the remainder by dividing by two; we know the */
comment|/* lsu is even. */
for|for
control|(
name|up
operator|=
name|accnext
init|;
name|up
operator|<
name|accnext
operator|+
name|tarunits
condition|;
name|up
operator|++
control|)
block|{
name|Int
name|half
decl_stmt|;
comment|/* half to add to lower unit */
name|half
operator|=
operator|*
name|up
operator|&
literal|0x01
expr_stmt|;
operator|*
name|up
operator|/=
literal|2
expr_stmt|;
comment|/* [shift] */
if|if
condition|(
operator|!
name|half
condition|)
continue|continue;
operator|*
operator|(
name|up
operator|-
literal|1
operator|)
operator|+=
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
operator|/
literal|2
expr_stmt|;
block|}
comment|/* [accunits still describes the original remainder length] */
if|if
condition|(
name|compare
operator|>
literal|0
operator|||
operator|(
name|compare
operator|==
literal|0
operator|&&
name|wasodd
operator|)
condition|)
block|{
comment|/* adjustment needed */
name|Int
name|exp
decl_stmt|,
name|expunits
decl_stmt|,
name|exprem
decl_stmt|;
comment|/* work */
comment|/* This is effectively causing round-up of the quotient, */
comment|/* so if it was the rare case where it was full and all */
comment|/* nines, it would overflow and hence division-impossible */
comment|/* should be raised */
name|Flag
name|allnines
init|=
literal|0
decl_stmt|;
comment|/* 1 if quotient all nines */
if|if
condition|(
name|quotdigits
operator|==
name|reqdigits
condition|)
block|{
comment|/* could be borderline */
for|for
control|(
name|up
operator|=
name|quotlsu
init|;
condition|;
name|up
operator|++
control|)
block|{
if|if
condition|(
name|quotdigits
operator|>
name|DECDPUN
condition|)
block|{
if|if
condition|(
operator|*
name|up
operator|!=
name|DECDPUNMAX
condition|)
break|break;
comment|/* non-nines */
block|}
else|else
block|{
comment|/* this is the last Unit */
if|if
condition|(
operator|*
name|up
operator|==
name|powers
index|[
name|quotdigits
index|]
operator|-
literal|1
condition|)
name|allnines
operator|=
literal|1
expr_stmt|;
break|break;
block|}
name|quotdigits
operator|-=
name|DECDPUN
expr_stmt|;
comment|/* checked those digits */
block|}
comment|/* up */
block|}
comment|/* borderline check */
if|if
condition|(
name|allnines
condition|)
block|{
operator|*
name|status
operator||=
name|DEC_Division_impossible
expr_stmt|;
break|break;
block|}
comment|/* we need rem-rhs; the sign will invert.  Again we can */
comment|/* safely use var1 for the working Units array. */
name|exp
operator|=
name|rhs
operator|->
name|exponent
operator|-
name|exponent
expr_stmt|;
comment|/* RHS padding needed */
comment|/* Calculate units and remainder from exponent. */
name|expunits
operator|=
name|exp
operator|/
name|DECDPUN
expr_stmt|;
name|exprem
operator|=
name|exp
operator|%
name|DECDPUN
expr_stmt|;
comment|/* subtract [A+B*(-m)]; the result will always be negative */
name|accunits
operator|=
operator|-
name|decUnitAddSub
argument_list|(
name|accnext
argument_list|,
name|accunits
argument_list|,
name|rhs
operator|->
name|lsu
argument_list|,
name|D2U
argument_list|(
name|rhs
operator|->
name|digits
argument_list|)
argument_list|,
name|expunits
argument_list|,
name|accnext
argument_list|,
operator|-
operator|(
name|Int
operator|)
name|powers
index|[
name|exprem
index|]
argument_list|)
expr_stmt|;
name|accdigits
operator|=
name|decGetDigits
argument_list|(
name|accnext
argument_list|,
name|accunits
argument_list|)
expr_stmt|;
comment|/* count digits exactly */
name|accunits
operator|=
name|D2U
argument_list|(
name|accdigits
argument_list|)
expr_stmt|;
comment|/* and recalculate the units for copy */
comment|/* [exponent is as for original remainder] */
name|bits
operator|^=
name|DECNEG
expr_stmt|;
comment|/* flip the sign */
block|}
block|}
comment|/* REMNEAR */
block|}
comment|/* REMAINDER or REMNEAR */
block|}
comment|/* not DIVIDE */
comment|/* Set exponent and bits */
name|res
operator|->
name|exponent
operator|=
name|exponent
expr_stmt|;
name|res
operator|->
name|bits
operator|=
call|(
name|uByte
call|)
argument_list|(
name|bits
operator|&
name|DECNEG
argument_list|)
expr_stmt|;
comment|/* [cleaned] */
comment|/* Now the coefficient. */
name|decSetCoeff
argument_list|(
name|res
argument_list|,
name|set
argument_list|,
name|accnext
argument_list|,
name|accdigits
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
name|decFinish
argument_list|(
name|res
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
comment|/* final cleanup */
if|#
directive|if
name|DECSUBSET
comment|/* If a divide then strip trailing zeros if subset [after round] */
if|if
condition|(
operator|!
name|set
operator|->
name|extended
operator|&&
operator|(
name|op
operator|==
name|DIVIDE
operator|)
condition|)
name|decTrim
argument_list|(
name|res
argument_list|,
literal|0
argument_list|,
operator|&
name|dropped
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
do|while
condition|(
literal|0
condition|)
do|;
comment|/* end protected */
if|if
condition|(
name|varalloc
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|varalloc
argument_list|)
expr_stmt|;
comment|/* drop any storage we used */
if|if
condition|(
name|allocacc
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|allocacc
argument_list|)
expr_stmt|;
comment|/* .. */
if|if
condition|(
name|allocrhs
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|allocrhs
argument_list|)
expr_stmt|;
comment|/* .. */
if|if
condition|(
name|alloclhs
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|alloclhs
argument_list|)
expr_stmt|;
comment|/* .. */
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decMultiplyOp -- multiplication operation                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  This routine performs the multiplication C=A x B.                 */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A and/or B (e.g., X=X*X)         */
end_comment

begin_comment
comment|/*   lhs is A                                                         */
end_comment

begin_comment
comment|/*   rhs is B                                                         */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*   status is the usual accumulator                                  */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Note: We use 'long' multiplication rather than Karatsuba, as the   */
end_comment

begin_comment
comment|/* latter would give only a minor improvement for the short numbers   */
end_comment

begin_comment
comment|/* we expect to handle most (and uses much more memory).              */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* We always have to use a buffer for the accumulator.                */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|decNumber
modifier|*
name|decMultiplyOp
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|,
name|uInt
modifier|*
name|status
parameter_list|)
block|{
name|decNumber
modifier|*
name|alloclhs
init|=
name|NULL
decl_stmt|;
comment|/* non-NULL if rounded lhs allocated */
name|decNumber
modifier|*
name|allocrhs
init|=
name|NULL
decl_stmt|;
comment|/* .., rhs */
name|Unit
name|accbuff
index|[
name|D2U
argument_list|(
name|DECBUFFER
operator|*
literal|2
operator|+
literal|1
argument_list|)
index|]
decl_stmt|;
comment|/* local buffer (+1 in case DECBUFFER==0) */
name|Unit
modifier|*
name|acc
init|=
name|accbuff
decl_stmt|;
comment|/* -> accumulator array for exact result */
name|Unit
modifier|*
name|allocacc
init|=
name|NULL
decl_stmt|;
comment|/* -> allocated buffer, iff allocated */
specifier|const
name|Unit
modifier|*
name|mer
decl_stmt|,
modifier|*
name|mermsup
decl_stmt|;
comment|/* work */
name|Int
name|accunits
decl_stmt|;
comment|/* Units of accumulator in use */
name|Int
name|madlength
decl_stmt|;
comment|/* Units in multiplicand */
name|Int
name|shift
decl_stmt|;
comment|/* Units to shift multiplicand by */
name|Int
name|need
decl_stmt|;
comment|/* Accumulator units needed */
name|Int
name|exponent
decl_stmt|;
comment|/* work */
name|Int
name|residue
init|=
literal|0
decl_stmt|;
comment|/* rounding residue */
name|uByte
name|bits
decl_stmt|;
comment|/* result sign */
name|uByte
name|merged
decl_stmt|;
comment|/* merged flags */
if|#
directive|if
name|DECCHECK
if|if
condition|(
name|decCheckOperands
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|)
condition|)
return|return
name|res
return|;
endif|#
directive|endif
do|do
block|{
comment|/* protect allocated storage */
if|#
directive|if
name|DECSUBSET
if|if
condition|(
operator|!
name|set
operator|->
name|extended
condition|)
block|{
comment|/* reduce operands and set lostDigits status, as needed */
if|if
condition|(
name|lhs
operator|->
name|digits
operator|>
name|set
operator|->
name|digits
condition|)
block|{
name|alloclhs
operator|=
name|decRoundOperand
argument_list|(
name|lhs
argument_list|,
name|set
argument_list|,
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|alloclhs
operator|==
name|NULL
condition|)
break|break;
name|lhs
operator|=
name|alloclhs
expr_stmt|;
block|}
if|if
condition|(
name|rhs
operator|->
name|digits
operator|>
name|set
operator|->
name|digits
condition|)
block|{
name|allocrhs
operator|=
name|decRoundOperand
argument_list|(
name|rhs
argument_list|,
name|set
argument_list|,
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|allocrhs
operator|==
name|NULL
condition|)
break|break;
name|rhs
operator|=
name|allocrhs
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* [following code does not require input rounding] */
comment|/* precalculate result sign */
name|bits
operator|=
call|(
name|uByte
call|)
argument_list|(
operator|(
name|lhs
operator|->
name|bits
operator|^
name|rhs
operator|->
name|bits
operator|)
operator|&
name|DECNEG
argument_list|)
expr_stmt|;
comment|/* handle infinities and NaNs */
name|merged
operator|=
operator|(
name|lhs
operator|->
name|bits
operator||
name|rhs
operator|->
name|bits
operator|)
operator|&
name|DECSPECIAL
expr_stmt|;
if|if
condition|(
name|merged
condition|)
block|{
comment|/* a special bit set */
if|if
condition|(
name|merged
operator|&
operator|(
name|DECSNAN
operator||
name|DECNAN
operator|)
condition|)
block|{
comment|/* one or two NaNs */
name|decNaNs
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|status
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* one or two infinities. Infinity * 0 is invalid */
if|if
condition|(
operator|(
operator|(
name|lhs
operator|->
name|bits
operator|&
name|DECSPECIAL
operator|)
operator|==
literal|0
operator|&&
name|ISZERO
argument_list|(
name|lhs
argument_list|)
operator|)
operator|||
operator|(
operator|(
name|rhs
operator|->
name|bits
operator|&
name|DECSPECIAL
operator|)
operator|==
literal|0
operator|&&
name|ISZERO
argument_list|(
name|rhs
argument_list|)
operator|)
condition|)
block|{
operator|*
name|status
operator||=
name|DEC_Invalid_operation
expr_stmt|;
break|break;
block|}
name|decNumberZero
argument_list|(
name|res
argument_list|)
expr_stmt|;
name|res
operator|->
name|bits
operator|=
name|bits
operator||
name|DECINF
expr_stmt|;
comment|/* infinity */
break|break;
block|}
comment|/* For best speed, as in DMSRCN, we use the shorter number as the */
comment|/* multiplier (rhs) and the longer as the multiplicand (lhs) */
if|if
condition|(
name|lhs
operator|->
name|digits
operator|<
name|rhs
operator|->
name|digits
condition|)
block|{
comment|/* swap... */
specifier|const
name|decNumber
modifier|*
name|hold
init|=
name|lhs
decl_stmt|;
name|lhs
operator|=
name|rhs
expr_stmt|;
name|rhs
operator|=
name|hold
expr_stmt|;
block|}
comment|/* if accumulator is too long for local storage, then allocate */
name|need
operator|=
name|D2U
argument_list|(
name|lhs
operator|->
name|digits
argument_list|)
operator|+
name|D2U
argument_list|(
name|rhs
operator|->
name|digits
argument_list|)
expr_stmt|;
comment|/* maximum units in result */
if|if
condition|(
name|need
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|accbuff
argument_list|)
condition|)
block|{
name|allocacc
operator|=
operator|(
name|Unit
operator|*
operator|)
name|malloc
argument_list|(
name|need
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|allocacc
operator|==
name|NULL
condition|)
block|{
operator|*
name|status
operator||=
name|DEC_Insufficient_storage
expr_stmt|;
break|break;
block|}
name|acc
operator|=
name|allocacc
expr_stmt|;
comment|/* use the allocated space */
block|}
comment|/* Now the main long multiplication loop */
comment|/* Unlike the equivalent in the IBM Java implementation, there */
comment|/* is no advantage in calculating from msu to lsu.  So we do it */
comment|/* by the book, as it were. */
comment|/* Each iteration calculates ACC=ACC+MULTAND*MULT */
name|accunits
operator|=
literal|1
expr_stmt|;
comment|/* accumulator starts at '0' */
operator|*
name|acc
operator|=
literal|0
expr_stmt|;
comment|/* .. (lsu=0) */
name|shift
operator|=
literal|0
expr_stmt|;
comment|/* no multiplicand shift at first */
name|madlength
operator|=
name|D2U
argument_list|(
name|lhs
operator|->
name|digits
argument_list|)
expr_stmt|;
comment|/* we know this won't change */
name|mermsup
operator|=
name|rhs
operator|->
name|lsu
operator|+
name|D2U
argument_list|(
name|rhs
operator|->
name|digits
argument_list|)
expr_stmt|;
comment|/* -> msu+1 of multiplier */
for|for
control|(
name|mer
operator|=
name|rhs
operator|->
name|lsu
init|;
name|mer
operator|<
name|mermsup
condition|;
name|mer
operator|++
control|)
block|{
comment|/* Here, *mer is the next Unit in the multiplier to use */
comment|/* If non-zero [optimization] add it... */
if|if
condition|(
operator|*
name|mer
operator|!=
literal|0
condition|)
block|{
name|accunits
operator|=
name|decUnitAddSub
argument_list|(
operator|&
name|acc
index|[
name|shift
index|]
argument_list|,
name|accunits
operator|-
name|shift
argument_list|,
name|lhs
operator|->
name|lsu
argument_list|,
name|madlength
argument_list|,
literal|0
argument_list|,
operator|&
name|acc
index|[
name|shift
index|]
argument_list|,
operator|*
name|mer
argument_list|)
operator|+
name|shift
expr_stmt|;
block|}
else|else
block|{
comment|/* extend acc with a 0; we'll use it shortly */
comment|/* [this avoids length of<=0 later] */
operator|*
operator|(
name|acc
operator|+
name|accunits
operator|)
operator|=
literal|0
expr_stmt|;
name|accunits
operator|++
expr_stmt|;
block|}
comment|/* multiply multiplicand by 10**DECDPUN for next Unit to left */
name|shift
operator|++
expr_stmt|;
comment|/* add this for 'logical length' */
block|}
comment|/* n */
if|#
directive|if
name|DECTRACE
comment|/* Show exact result */
name|decDumpAr
argument_list|(
literal|'*'
argument_list|,
name|acc
argument_list|,
name|accunits
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* acc now contains the exact result of the multiplication */
comment|/* Build a decNumber from it, noting if any residue */
name|res
operator|->
name|bits
operator|=
name|bits
expr_stmt|;
comment|/* set sign */
name|res
operator|->
name|digits
operator|=
name|decGetDigits
argument_list|(
name|acc
argument_list|,
name|accunits
argument_list|)
expr_stmt|;
comment|/* count digits exactly */
comment|/* We might have a 31-bit wrap in calculating the exponent. */
comment|/* This can only happen if both input exponents are negative and */
comment|/* both their magnitudes are large.  If we did wrap, we set a safe */
comment|/* very negative exponent, from which decFinalize() will raise a */
comment|/* hard underflow. */
name|exponent
operator|=
name|lhs
operator|->
name|exponent
operator|+
name|rhs
operator|->
name|exponent
expr_stmt|;
comment|/* calculate exponent */
if|if
condition|(
name|lhs
operator|->
name|exponent
operator|<
literal|0
operator|&&
name|rhs
operator|->
name|exponent
operator|<
literal|0
operator|&&
name|exponent
operator|>
literal|0
condition|)
name|exponent
operator|=
operator|-
literal|2
operator|*
name|DECNUMMAXE
expr_stmt|;
comment|/* force underflow */
name|res
operator|->
name|exponent
operator|=
name|exponent
expr_stmt|;
comment|/* OK to overwrite now */
comment|/* Set the coefficient.  If any rounding, residue records */
name|decSetCoeff
argument_list|(
name|res
argument_list|,
name|set
argument_list|,
name|acc
argument_list|,
name|res
operator|->
name|digits
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
name|decFinish
argument_list|(
name|res
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
comment|/* final cleanup */
block|}
do|while
condition|(
literal|0
condition|)
do|;
comment|/* end protected */
if|if
condition|(
name|allocacc
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|allocacc
argument_list|)
expr_stmt|;
comment|/* drop any storage we used */
if|if
condition|(
name|allocrhs
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|allocrhs
argument_list|)
expr_stmt|;
comment|/* .. */
if|if
condition|(
name|alloclhs
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|alloclhs
argument_list|)
expr_stmt|;
comment|/* .. */
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decQuantizeOp  -- force exponent to requested value                */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = op(A, B), where op adjusts the coefficient     */
end_comment

begin_comment
comment|/*   of C (by rounding or shifting) such that the exponent (-scale)   */
end_comment

begin_comment
comment|/*   of C has the value B or matches the exponent of B.               */
end_comment

begin_comment
comment|/*   The numerical value of C will equal A, except for the effects of */
end_comment

begin_comment
comment|/*   any rounding that occurred.                                      */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A or B                           */
end_comment

begin_comment
comment|/*   lhs is A, the number to adjust                                   */
end_comment

begin_comment
comment|/*   rhs is B, the requested exponent                                 */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*   quant is 1 for quantize or 0 for rescale                         */
end_comment

begin_comment
comment|/*   status is the status accumulator (this can be called without     */
end_comment

begin_comment
comment|/*          risk of control loss)                                     */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for set->digits digits.                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* Unless there is an error or the result is infinite, the exponent   */
end_comment

begin_comment
comment|/* after the operation is guaranteed to be that requested.            */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|decNumber
modifier|*
name|decQuantizeOp
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|,
name|Flag
name|quant
parameter_list|,
name|uInt
modifier|*
name|status
parameter_list|)
block|{
name|decNumber
modifier|*
name|alloclhs
init|=
name|NULL
decl_stmt|;
comment|/* non-NULL if rounded lhs allocated */
name|decNumber
modifier|*
name|allocrhs
init|=
name|NULL
decl_stmt|;
comment|/* .., rhs */
specifier|const
name|decNumber
modifier|*
name|inrhs
init|=
name|rhs
decl_stmt|;
comment|/* save original rhs */
name|Int
name|reqdigits
init|=
name|set
operator|->
name|digits
decl_stmt|;
comment|/* requested DIGITS */
name|Int
name|reqexp
decl_stmt|;
comment|/* requested exponent [-scale] */
name|Int
name|residue
init|=
literal|0
decl_stmt|;
comment|/* rounding residue */
name|uByte
name|merged
decl_stmt|;
comment|/* merged flags */
name|Int
name|etiny
init|=
name|set
operator|->
name|emin
operator|-
operator|(
name|set
operator|->
name|digits
operator|-
literal|1
operator|)
decl_stmt|;
if|#
directive|if
name|DECCHECK
if|if
condition|(
name|decCheckOperands
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|)
condition|)
return|return
name|res
return|;
endif|#
directive|endif
do|do
block|{
comment|/* protect allocated storage */
if|#
directive|if
name|DECSUBSET
if|if
condition|(
operator|!
name|set
operator|->
name|extended
condition|)
block|{
comment|/* reduce operands and set lostDigits status, as needed */
if|if
condition|(
name|lhs
operator|->
name|digits
operator|>
name|reqdigits
condition|)
block|{
name|alloclhs
operator|=
name|decRoundOperand
argument_list|(
name|lhs
argument_list|,
name|set
argument_list|,
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|alloclhs
operator|==
name|NULL
condition|)
break|break;
name|lhs
operator|=
name|alloclhs
expr_stmt|;
block|}
if|if
condition|(
name|rhs
operator|->
name|digits
operator|>
name|reqdigits
condition|)
block|{
comment|/* [this only checks lostDigits] */
name|allocrhs
operator|=
name|decRoundOperand
argument_list|(
name|rhs
argument_list|,
name|set
argument_list|,
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|allocrhs
operator|==
name|NULL
condition|)
break|break;
name|rhs
operator|=
name|allocrhs
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* [following code does not require input rounding] */
comment|/* Handle special values */
name|merged
operator|=
operator|(
name|lhs
operator|->
name|bits
operator||
name|rhs
operator|->
name|bits
operator|)
operator|&
name|DECSPECIAL
expr_stmt|;
if|if
condition|(
operator|(
name|lhs
operator|->
name|bits
operator||
name|rhs
operator|->
name|bits
operator|)
operator|&
name|DECSPECIAL
condition|)
block|{
comment|/* NaNs get usual processing */
if|if
condition|(
name|merged
operator|&
operator|(
name|DECSNAN
operator||
name|DECNAN
operator|)
condition|)
name|decNaNs
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|status
argument_list|)
expr_stmt|;
comment|/* one infinity but not both is bad */
elseif|else
if|if
condition|(
operator|(
name|lhs
operator|->
name|bits
operator|^
name|rhs
operator|->
name|bits
operator|)
operator|&
name|DECINF
condition|)
operator|*
name|status
operator||=
name|DEC_Invalid_operation
expr_stmt|;
comment|/* both infinity: return lhs */
else|else
name|decNumberCopy
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|)
expr_stmt|;
comment|/* [nop if in place] */
break|break;
block|}
comment|/* set requested exponent */
if|if
condition|(
name|quant
condition|)
name|reqexp
operator|=
name|inrhs
operator|->
name|exponent
expr_stmt|;
comment|/* quantize -- match exponents */
else|else
block|{
comment|/* rescale -- use value of rhs */
comment|/* Original rhs must be an integer that fits and is in range */
if|#
directive|if
name|DECSUBSET
name|reqexp
operator|=
name|decGetInt
argument_list|(
name|inrhs
argument_list|,
name|set
argument_list|)
expr_stmt|;
else|#
directive|else
name|reqexp
operator|=
name|decGetInt
argument_list|(
name|inrhs
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
if|#
directive|if
name|DECSUBSET
if|if
condition|(
operator|!
name|set
operator|->
name|extended
condition|)
name|etiny
operator|=
name|set
operator|->
name|emin
expr_stmt|;
comment|/* no subnormals */
endif|#
directive|endif
if|if
condition|(
name|reqexp
operator|==
name|BADINT
comment|/* bad (rescale only) or .. */
operator|||
operator|(
name|reqexp
operator|<
name|etiny
operator|)
comment|/*< lowest */
operator|||
operator|(
name|reqexp
operator|>
name|set
operator|->
name|emax
operator|)
condition|)
block|{
comment|/*> Emax */
operator|*
name|status
operator||=
name|DEC_Invalid_operation
expr_stmt|;
break|break;
block|}
comment|/* we've processed the RHS, so we can overwrite it now if necessary */
if|if
condition|(
name|ISZERO
argument_list|(
name|lhs
argument_list|)
condition|)
block|{
comment|/* zero coefficient unchanged */
name|decNumberCopy
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|)
expr_stmt|;
comment|/* [nop if in place] */
name|res
operator|->
name|exponent
operator|=
name|reqexp
expr_stmt|;
comment|/* .. just set exponent */
if|#
directive|if
name|DECSUBSET
if|if
condition|(
operator|!
name|set
operator|->
name|extended
condition|)
name|res
operator|->
name|bits
operator|=
literal|0
expr_stmt|;
comment|/* subset specification; no -0 */
endif|#
directive|endif
block|}
else|else
block|{
comment|/* non-zero lhs */
name|Int
name|adjust
init|=
name|reqexp
operator|-
name|lhs
operator|->
name|exponent
decl_stmt|;
comment|/* digit adjustment needed */
comment|/* if adjusted coefficient will not fit, give up now */
if|if
condition|(
operator|(
name|lhs
operator|->
name|digits
operator|-
name|adjust
operator|)
operator|>
name|reqdigits
condition|)
block|{
operator|*
name|status
operator||=
name|DEC_Invalid_operation
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|adjust
operator|>
literal|0
condition|)
block|{
comment|/* increasing exponent */
comment|/* this will decrease the length of the coefficient by adjust */
comment|/* digits, and must round as it does so */
name|decContext
name|workset
decl_stmt|;
comment|/* work */
name|workset
operator|=
operator|*
name|set
expr_stmt|;
comment|/* clone rounding, etc. */
name|workset
operator|.
name|digits
operator|=
name|lhs
operator|->
name|digits
operator|-
name|adjust
expr_stmt|;
comment|/* set requested length */
comment|/* [note that the latter can be<1, here] */
name|decCopyFit
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
operator|&
name|workset
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
comment|/* fit to result */
name|decApplyRound
argument_list|(
name|res
argument_list|,
operator|&
name|workset
argument_list|,
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
comment|/* .. and round */
name|residue
operator|=
literal|0
expr_stmt|;
comment|/* [used] */
comment|/* If we rounded a 999s case, exponent will be off by one; */
comment|/* adjust back if so. */
if|if
condition|(
name|res
operator|->
name|exponent
operator|>
name|reqexp
condition|)
block|{
name|res
operator|->
name|digits
operator|=
name|decShiftToMost
argument_list|(
name|res
operator|->
name|lsu
argument_list|,
name|res
operator|->
name|digits
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* shift */
name|res
operator|->
name|exponent
operator|--
expr_stmt|;
comment|/* (re)adjust the exponent. */
block|}
if|#
directive|if
name|DECSUBSET
if|if
condition|(
name|ISZERO
argument_list|(
name|res
argument_list|)
operator|&&
operator|!
name|set
operator|->
name|extended
condition|)
name|res
operator|->
name|bits
operator|=
literal|0
expr_stmt|;
comment|/* subset; no -0 */
endif|#
directive|endif
block|}
comment|/* increase */
else|else
comment|/* adjust<=0 */
block|{
comment|/* decreasing or = exponent */
comment|/* this will increase the length of the coefficient by -adjust */
comment|/* digits, by adding trailing zeros. */
name|decNumberCopy
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|)
expr_stmt|;
comment|/* [it will fit] */
comment|/* if padding needed (adjust<0), add it now... */
if|if
condition|(
name|adjust
operator|<
literal|0
condition|)
block|{
name|res
operator|->
name|digits
operator|=
name|decShiftToMost
argument_list|(
name|res
operator|->
name|lsu
argument_list|,
name|res
operator|->
name|digits
argument_list|,
operator|-
name|adjust
argument_list|)
expr_stmt|;
name|res
operator|->
name|exponent
operator|+=
name|adjust
expr_stmt|;
comment|/* adjust the exponent */
block|}
block|}
comment|/* decrease */
block|}
comment|/* non-zero */
comment|/* Check for overflow [do not use Finalize in this case, as an */
comment|/* overflow here is a "don't fit" situation] */
if|if
condition|(
name|res
operator|->
name|exponent
operator|>
name|set
operator|->
name|emax
operator|-
name|res
operator|->
name|digits
operator|+
literal|1
condition|)
block|{
comment|/* too big */
operator|*
name|status
operator||=
name|DEC_Invalid_operation
expr_stmt|;
break|break;
block|}
else|else
block|{
name|decFinalize
argument_list|(
name|res
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
comment|/* set subnormal flags */
operator|*
name|status
operator|&=
operator|~
name|DEC_Underflow
expr_stmt|;
comment|/* suppress Underflow [754r] */
block|}
block|}
do|while
condition|(
literal|0
condition|)
do|;
comment|/* end protected */
if|if
condition|(
name|allocrhs
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|allocrhs
argument_list|)
expr_stmt|;
comment|/* drop any storage we used */
if|if
condition|(
name|alloclhs
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|alloclhs
argument_list|)
expr_stmt|;
comment|/* .. */
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decCompareOp -- compare, min, or max two Numbers                   */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   This computes C = A ? B and returns the signum (as a Number)     */
end_comment

begin_comment
comment|/*   for COMPARE or the maximum or minimum (for COMPMAX and COMPMIN). */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   res is C, the result.  C may be A and/or B (e.g., X=X?X)         */
end_comment

begin_comment
comment|/*   lhs is A                                                         */
end_comment

begin_comment
comment|/*   rhs is B                                                         */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*   op  is the operation flag                                        */
end_comment

begin_comment
comment|/*   status is the usual accumulator                                  */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* C must have space for one digit for COMPARE or set->digits for     */
end_comment

begin_comment
comment|/* COMPMAX and COMPMIN.                                               */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* The emphasis here is on speed for common cases, and avoiding       */
end_comment

begin_comment
comment|/* coefficient comparison if possible.                                */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decCompareOp
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|,
name|Flag
name|op
parameter_list|,
name|uInt
modifier|*
name|status
parameter_list|)
block|{
name|decNumber
modifier|*
name|alloclhs
init|=
name|NULL
decl_stmt|;
comment|/* non-NULL if rounded lhs allocated */
name|decNumber
modifier|*
name|allocrhs
init|=
name|NULL
decl_stmt|;
comment|/* .., rhs */
name|Int
name|result
init|=
literal|0
decl_stmt|;
comment|/* default result value */
name|uByte
name|merged
decl_stmt|;
comment|/* merged flags */
name|uByte
name|bits
init|=
literal|0
decl_stmt|;
comment|/* non-0 for NaN */
if|#
directive|if
name|DECCHECK
if|if
condition|(
name|decCheckOperands
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|set
argument_list|)
condition|)
return|return
name|res
return|;
endif|#
directive|endif
do|do
block|{
comment|/* protect allocated storage */
if|#
directive|if
name|DECSUBSET
if|if
condition|(
operator|!
name|set
operator|->
name|extended
condition|)
block|{
comment|/* reduce operands and set lostDigits status, as needed */
if|if
condition|(
name|lhs
operator|->
name|digits
operator|>
name|set
operator|->
name|digits
condition|)
block|{
name|alloclhs
operator|=
name|decRoundOperand
argument_list|(
name|lhs
argument_list|,
name|set
argument_list|,
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|alloclhs
operator|==
name|NULL
condition|)
block|{
name|result
operator|=
name|BADINT
expr_stmt|;
break|break;
block|}
name|lhs
operator|=
name|alloclhs
expr_stmt|;
block|}
if|if
condition|(
name|rhs
operator|->
name|digits
operator|>
name|set
operator|->
name|digits
condition|)
block|{
name|allocrhs
operator|=
name|decRoundOperand
argument_list|(
name|rhs
argument_list|,
name|set
argument_list|,
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|allocrhs
operator|==
name|NULL
condition|)
block|{
name|result
operator|=
name|BADINT
expr_stmt|;
break|break;
block|}
name|rhs
operator|=
name|allocrhs
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* [following code does not require input rounding] */
comment|/* handle NaNs now; let infinities drop through */
comment|/* +++ review sNaN handling with 754r, for now assumes sNaN */
comment|/* (even just one) leads to NaN. */
name|merged
operator|=
operator|(
name|lhs
operator|->
name|bits
operator||
name|rhs
operator|->
name|bits
operator|)
operator|&
operator|(
name|DECSNAN
operator||
name|DECNAN
operator|)
expr_stmt|;
if|if
condition|(
name|merged
condition|)
block|{
comment|/* a NaN bit set */
if|if
condition|(
name|op
operator|==
name|COMPARE
condition|)
empty_stmt|;
elseif|else
if|if
condition|(
name|merged
operator|&
name|DECSNAN
condition|)
empty_stmt|;
else|else
block|{
comment|/* 754r rules for MIN and MAX ignore single NaN */
comment|/* here if MIN or MAX, and one or two quiet NaNs */
if|if
condition|(
name|lhs
operator|->
name|bits
operator|&
name|rhs
operator|->
name|bits
operator|&
name|DECNAN
condition|)
empty_stmt|;
else|else
block|{
comment|/* just one quiet NaN */
comment|/* force choice to be the non-NaN operand */
name|op
operator|=
name|COMPMAX
expr_stmt|;
if|if
condition|(
name|lhs
operator|->
name|bits
operator|&
name|DECNAN
condition|)
name|result
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* pick rhs */
else|else
name|result
operator|=
operator|+
literal|1
expr_stmt|;
comment|/* pick lhs */
break|break;
block|}
block|}
name|op
operator|=
name|COMPNAN
expr_stmt|;
comment|/* use special path */
name|decNaNs
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
name|status
argument_list|)
expr_stmt|;
break|break;
block|}
name|result
operator|=
name|decCompare
argument_list|(
name|lhs
argument_list|,
name|rhs
argument_list|)
expr_stmt|;
comment|/* we have numbers */
block|}
do|while
condition|(
literal|0
condition|)
do|;
comment|/* end protected */
if|if
condition|(
name|result
operator|==
name|BADINT
condition|)
operator|*
name|status
operator||=
name|DEC_Insufficient_storage
expr_stmt|;
comment|/* rare */
else|else
block|{
if|if
condition|(
name|op
operator|==
name|COMPARE
condition|)
block|{
comment|/* return signum */
name|decNumberZero
argument_list|(
name|res
argument_list|)
expr_stmt|;
comment|/* [always a valid result] */
if|if
condition|(
name|result
operator|==
literal|0
condition|)
name|res
operator|->
name|bits
operator|=
name|bits
expr_stmt|;
comment|/* (maybe qNaN) */
else|else
block|{
operator|*
name|res
operator|->
name|lsu
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|result
operator|<
literal|0
condition|)
name|res
operator|->
name|bits
operator|=
name|DECNEG
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|op
operator|==
name|COMPNAN
condition|)
empty_stmt|;
comment|/* special, drop through */
else|else
block|{
comment|/* MAX or MIN, non-NaN result */
name|Int
name|residue
init|=
literal|0
decl_stmt|;
comment|/* rounding accumulator */
comment|/* choose the operand for the result */
specifier|const
name|decNumber
modifier|*
name|choice
decl_stmt|;
if|if
condition|(
name|result
operator|==
literal|0
condition|)
block|{
comment|/* operands are numerically equal */
comment|/* choose according to sign then exponent (see 754r) */
name|uByte
name|slhs
init|=
operator|(
name|lhs
operator|->
name|bits
operator|&
name|DECNEG
operator|)
decl_stmt|;
name|uByte
name|srhs
init|=
operator|(
name|rhs
operator|->
name|bits
operator|&
name|DECNEG
operator|)
decl_stmt|;
if|#
directive|if
name|DECSUBSET
if|if
condition|(
operator|!
name|set
operator|->
name|extended
condition|)
block|{
comment|/* subset: force left-hand */
name|op
operator|=
name|COMPMAX
expr_stmt|;
name|result
operator|=
operator|+
literal|1
expr_stmt|;
block|}
elseif|else
endif|#
directive|endif
if|if
condition|(
name|slhs
operator|!=
name|srhs
condition|)
block|{
comment|/* signs differ */
if|if
condition|(
name|slhs
condition|)
name|result
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* rhs is max */
else|else
name|result
operator|=
operator|+
literal|1
expr_stmt|;
comment|/* lhs is max */
block|}
elseif|else
if|if
condition|(
name|slhs
operator|&&
name|srhs
condition|)
block|{
comment|/* both negative */
if|if
condition|(
name|lhs
operator|->
name|exponent
operator|<
name|rhs
operator|->
name|exponent
condition|)
name|result
operator|=
operator|+
literal|1
expr_stmt|;
else|else
name|result
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* [if equal, we use lhs, technically identical] */
block|}
else|else
block|{
comment|/* both positive */
if|if
condition|(
name|lhs
operator|->
name|exponent
operator|>
name|rhs
operator|->
name|exponent
condition|)
name|result
operator|=
operator|+
literal|1
expr_stmt|;
else|else
name|result
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* [ditto] */
block|}
block|}
comment|/* numerically equal */
comment|/* here result will be non-0 */
if|if
condition|(
name|op
operator|==
name|COMPMIN
condition|)
name|result
operator|=
operator|-
name|result
expr_stmt|;
comment|/* reverse if looking for MIN */
name|choice
operator|=
operator|(
name|result
operator|>
literal|0
condition|?
name|lhs
else|:
name|rhs
operator|)
expr_stmt|;
comment|/* choose */
comment|/* copy chosen to result, rounding if need be */
name|decCopyFit
argument_list|(
name|res
argument_list|,
name|choice
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
name|decFinish
argument_list|(
name|res
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|allocrhs
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|allocrhs
argument_list|)
expr_stmt|;
comment|/* free any storage we used */
if|if
condition|(
name|alloclhs
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|alloclhs
argument_list|)
expr_stmt|;
comment|/* .. */
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decCompare -- compare two decNumbers by numerical value            */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  This routine compares A ? B without altering them.                */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  Arg1 is A, a decNumber which is not a NaN                         */
end_comment

begin_comment
comment|/*  Arg2 is B, a decNumber which is not a NaN                         */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  returns -1, 0, or 1 for A<B, A==B, or A>B, or BADINT if failure   */
end_comment

begin_comment
comment|/*  (the only possible failure is an allocation error)                */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* This could be merged into decCompareOp */
end_comment

begin_function
specifier|static
name|Int
name|decCompare
parameter_list|(
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|)
block|{
name|Int
name|result
decl_stmt|;
comment|/* result value */
name|Int
name|sigr
decl_stmt|;
comment|/* rhs signum */
name|Int
name|compare
decl_stmt|;
comment|/* work */
name|result
operator|=
literal|1
expr_stmt|;
comment|/* assume signum(lhs) */
if|if
condition|(
name|ISZERO
argument_list|(
name|lhs
argument_list|)
condition|)
name|result
operator|=
literal|0
expr_stmt|;
elseif|else
if|if
condition|(
name|decNumberIsNegative
argument_list|(
name|lhs
argument_list|)
condition|)
name|result
operator|=
operator|-
literal|1
expr_stmt|;
name|sigr
operator|=
literal|1
expr_stmt|;
comment|/* compute signum(rhs) */
if|if
condition|(
name|ISZERO
argument_list|(
name|rhs
argument_list|)
condition|)
name|sigr
operator|=
literal|0
expr_stmt|;
elseif|else
if|if
condition|(
name|decNumberIsNegative
argument_list|(
name|rhs
argument_list|)
condition|)
name|sigr
operator|=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|result
operator|>
name|sigr
condition|)
return|return
operator|+
literal|1
return|;
comment|/* L> R, return 1 */
if|if
condition|(
name|result
operator|<
name|sigr
condition|)
return|return
operator|-
literal|1
return|;
comment|/* R< L, return -1 */
comment|/* signums are the same */
if|if
condition|(
name|result
operator|==
literal|0
condition|)
return|return
literal|0
return|;
comment|/* both 0 */
comment|/* Both non-zero */
if|if
condition|(
operator|(
name|lhs
operator|->
name|bits
operator||
name|rhs
operator|->
name|bits
operator|)
operator|&
name|DECINF
condition|)
block|{
comment|/* one or more infinities */
if|if
condition|(
name|lhs
operator|->
name|bits
operator|==
name|rhs
operator|->
name|bits
condition|)
name|result
operator|=
literal|0
expr_stmt|;
comment|/* both the same */
elseif|else
if|if
condition|(
name|decNumberIsInfinite
argument_list|(
name|rhs
argument_list|)
condition|)
name|result
operator|=
operator|-
name|result
expr_stmt|;
return|return
name|result
return|;
block|}
comment|/* we must compare the coefficients, allowing for exponents */
if|if
condition|(
name|lhs
operator|->
name|exponent
operator|>
name|rhs
operator|->
name|exponent
condition|)
block|{
comment|/* LHS exponent larger */
comment|/* swap sides, and sign */
specifier|const
name|decNumber
modifier|*
name|temp
init|=
name|lhs
decl_stmt|;
name|lhs
operator|=
name|rhs
expr_stmt|;
name|rhs
operator|=
name|temp
expr_stmt|;
name|result
operator|=
operator|-
name|result
expr_stmt|;
block|}
name|compare
operator|=
name|decUnitCompare
argument_list|(
name|lhs
operator|->
name|lsu
argument_list|,
name|D2U
argument_list|(
name|lhs
operator|->
name|digits
argument_list|)
argument_list|,
name|rhs
operator|->
name|lsu
argument_list|,
name|D2U
argument_list|(
name|rhs
operator|->
name|digits
argument_list|)
argument_list|,
name|rhs
operator|->
name|exponent
operator|-
name|lhs
operator|->
name|exponent
argument_list|)
expr_stmt|;
if|if
condition|(
name|compare
operator|!=
name|BADINT
condition|)
name|compare
operator|*=
name|result
expr_stmt|;
comment|/* comparison succeeded */
return|return
name|compare
return|;
comment|/* what we got */
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decUnitCompare -- compare two>=0 integers in Unit arrays          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  This routine compares A ? B*10**E where A and B are unit arrays   */
end_comment

begin_comment
comment|/*  A is a plain integer                                              */
end_comment

begin_comment
comment|/*  B has an exponent of E (which must be non-negative)               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  Arg1 is A first Unit (lsu)                                        */
end_comment

begin_comment
comment|/*  Arg2 is A length in Units                                         */
end_comment

begin_comment
comment|/*  Arg3 is B first Unit (lsu)                                        */
end_comment

begin_comment
comment|/*  Arg4 is B length in Units                                         */
end_comment

begin_comment
comment|/*  Arg5 is E                                                         */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  returns -1, 0, or 1 for A<B, A==B, or A>B, or BADINT if failure   */
end_comment

begin_comment
comment|/*  (the only possible failure is an allocation error)                */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|Int
name|decUnitCompare
parameter_list|(
specifier|const
name|Unit
modifier|*
name|a
parameter_list|,
name|Int
name|alength
parameter_list|,
specifier|const
name|Unit
modifier|*
name|b
parameter_list|,
name|Int
name|blength
parameter_list|,
name|Int
name|exp
parameter_list|)
block|{
name|Unit
modifier|*
name|acc
decl_stmt|;
comment|/* accumulator for result */
name|Unit
name|accbuff
index|[
name|D2U
argument_list|(
name|DECBUFFER
operator|+
literal|1
argument_list|)
index|]
decl_stmt|;
comment|/* local buffer */
name|Unit
modifier|*
name|allocacc
init|=
name|NULL
decl_stmt|;
comment|/* -> allocated acc buffer, iff allocated */
name|Int
name|accunits
decl_stmt|,
name|need
decl_stmt|;
comment|/* units in use or needed for acc */
specifier|const
name|Unit
modifier|*
name|l
decl_stmt|,
modifier|*
name|r
decl_stmt|,
modifier|*
name|u
decl_stmt|;
comment|/* work */
name|Int
name|expunits
decl_stmt|,
name|exprem
decl_stmt|,
name|result
decl_stmt|;
comment|/* .. */
if|if
condition|(
name|exp
operator|==
literal|0
condition|)
block|{
comment|/* aligned; fastpath */
if|if
condition|(
name|alength
operator|>
name|blength
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|alength
operator|<
name|blength
condition|)
return|return
operator|-
literal|1
return|;
comment|/* same number of units in both -- need unit-by-unit compare */
name|l
operator|=
name|a
operator|+
name|alength
operator|-
literal|1
expr_stmt|;
name|r
operator|=
name|b
operator|+
name|alength
operator|-
literal|1
expr_stmt|;
for|for
control|(
init|;
name|l
operator|>=
name|a
condition|;
name|l
operator|--
operator|,
name|r
operator|--
control|)
block|{
if|if
condition|(
operator|*
name|l
operator|>
operator|*
name|r
condition|)
return|return
literal|1
return|;
if|if
condition|(
operator|*
name|l
operator|<
operator|*
name|r
condition|)
return|return
operator|-
literal|1
return|;
block|}
return|return
literal|0
return|;
comment|/* all units match */
block|}
comment|/* aligned */
comment|/* Unaligned.  If one is>1 unit longer than the other, padded */
comment|/* approximately, then we can return easily */
if|if
condition|(
name|alength
operator|>
name|blength
operator|+
operator|(
name|Int
operator|)
name|D2U
argument_list|(
name|exp
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|alength
operator|+
literal|1
operator|<
name|blength
operator|+
operator|(
name|Int
operator|)
name|D2U
argument_list|(
name|exp
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
comment|/* We need to do a real subtract.  For this, we need a result buffer */
comment|/* even though we only are interested in the sign.  Its length needs */
comment|/* to be the larger of alength and padded blength, +2 */
name|need
operator|=
name|blength
operator|+
name|D2U
argument_list|(
name|exp
argument_list|)
expr_stmt|;
comment|/* maximum real length of B */
if|if
condition|(
name|need
operator|<
name|alength
condition|)
name|need
operator|=
name|alength
expr_stmt|;
name|need
operator|+=
literal|2
expr_stmt|;
name|acc
operator|=
name|accbuff
expr_stmt|;
comment|/* assume use local buffer */
if|if
condition|(
name|need
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|accbuff
argument_list|)
condition|)
block|{
name|allocacc
operator|=
operator|(
name|Unit
operator|*
operator|)
name|malloc
argument_list|(
name|need
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|allocacc
operator|==
name|NULL
condition|)
return|return
name|BADINT
return|;
comment|/* hopeless -- abandon */
name|acc
operator|=
name|allocacc
expr_stmt|;
block|}
comment|/* Calculate units and remainder from exponent. */
name|expunits
operator|=
name|exp
operator|/
name|DECDPUN
expr_stmt|;
name|exprem
operator|=
name|exp
operator|%
name|DECDPUN
expr_stmt|;
comment|/* subtract [A+B*(-m)] */
name|accunits
operator|=
name|decUnitAddSub
argument_list|(
name|a
argument_list|,
name|alength
argument_list|,
name|b
argument_list|,
name|blength
argument_list|,
name|expunits
argument_list|,
name|acc
argument_list|,
operator|-
operator|(
name|Int
operator|)
name|powers
index|[
name|exprem
index|]
argument_list|)
expr_stmt|;
comment|/* [UnitAddSub result may have leading zeros, even on zero] */
if|if
condition|(
name|accunits
operator|<
literal|0
condition|)
name|result
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* negative result */
else|else
block|{
comment|/* non-negative result */
comment|/* check units of the result before freeing any storage */
for|for
control|(
name|u
operator|=
name|acc
init|;
name|u
operator|<
name|acc
operator|+
name|accunits
operator|-
literal|1
operator|&&
operator|*
name|u
operator|==
literal|0
condition|;
control|)
name|u
operator|++
expr_stmt|;
name|result
operator|=
operator|(
operator|*
name|u
operator|==
literal|0
condition|?
literal|0
else|:
operator|+
literal|1
operator|)
expr_stmt|;
block|}
comment|/* clean up and return the result */
if|if
condition|(
name|allocacc
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|allocacc
argument_list|)
expr_stmt|;
comment|/* drop any storage we used */
return|return
name|result
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decUnitAddSub -- add or subtract two>=0 integers in Unit arrays   */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  This routine performs the calculation:                            */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  C=A+(B*M)                                                         */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  Where M is in the range -DECDPUNMAX through +DECDPUNMAX.          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  A may be shorter or longer than B.                                */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  Leading zeros are not removed after a calculation.  The result is */
end_comment

begin_comment
comment|/*  either the same length as the longer of A and B (adding any       */
end_comment

begin_comment
comment|/*  shift), or one Unit longer than that (if a Unit carry occurred).  */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  A and B content are not altered unless C is also A or B.          */
end_comment

begin_comment
comment|/*  C may be the same array as A or B, but only if no zero padding is */
end_comment

begin_comment
comment|/*  requested (that is, C may be B only if bshift==0).                */
end_comment

begin_comment
comment|/*  C is filled from the lsu; only those units necessary to complete  */
end_comment

begin_comment
comment|/*  the calculation are referenced.                                   */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  Arg1 is A first Unit (lsu)                                        */
end_comment

begin_comment
comment|/*  Arg2 is A length in Units                                         */
end_comment

begin_comment
comment|/*  Arg3 is B first Unit (lsu)                                        */
end_comment

begin_comment
comment|/*  Arg4 is B length in Units                                         */
end_comment

begin_comment
comment|/*  Arg5 is B shift in Units  (>=0; pads with 0 units if positive)    */
end_comment

begin_comment
comment|/*  Arg6 is C first Unit (lsu)                                        */
end_comment

begin_comment
comment|/*  Arg7 is M, the multiplier                                         */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  returns the count of Units written to C, which will be non-zero   */
end_comment

begin_comment
comment|/*  and negated if the result is negative.  That is, the sign of the  */
end_comment

begin_comment
comment|/*  returned Int is the sign of the result (positive for zero) and    */
end_comment

begin_comment
comment|/*  the absolute value of the Int is the count of Units.              */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  It is the caller's responsibility to make sure that C size is     */
end_comment

begin_comment
comment|/*  safe, allowing space if necessary for a one-Unit carry.           */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  This routine is severely performance-critical; *any* change here  */
end_comment

begin_comment
comment|/*  must be measured (timed) to assure no performance degradation.    */
end_comment

begin_comment
comment|/*  In particular, trickery here tends to be counter-productive, as   */
end_comment

begin_comment
comment|/*  increased complexity of code hurts register optimizations on      */
end_comment

begin_comment
comment|/*  register-poor architectures.  Avoiding divisions is nearly        */
end_comment

begin_comment
comment|/*  always a Good Idea, however.                                      */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* Special thanks to Rick McGuire (IBM Cambridge, MA) and Dave Clark  */
end_comment

begin_comment
comment|/* (IBM Warwick, UK) for some of the ideas used in this routine.      */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|Int
name|decUnitAddSub
parameter_list|(
specifier|const
name|Unit
modifier|*
name|a
parameter_list|,
name|Int
name|alength
parameter_list|,
specifier|const
name|Unit
modifier|*
name|b
parameter_list|,
name|Int
name|blength
parameter_list|,
name|Int
name|bshift
parameter_list|,
name|Unit
modifier|*
name|c
parameter_list|,
name|Int
name|m
parameter_list|)
block|{
specifier|const
name|Unit
modifier|*
name|alsu
init|=
name|a
decl_stmt|;
comment|/* A lsu [need to remember it] */
name|Unit
modifier|*
name|clsu
init|=
name|c
decl_stmt|;
comment|/* C ditto */
name|Unit
modifier|*
name|minC
decl_stmt|;
comment|/* low water mark for C */
name|Unit
modifier|*
name|maxC
decl_stmt|;
comment|/* high water mark for C */
name|eInt
name|carry
init|=
literal|0
decl_stmt|;
comment|/* carry integer (could be Long) */
name|Int
name|add
decl_stmt|;
comment|/* work */
if|#
directive|if
name|DECDPUN
operator|==
literal|4
comment|/* myriadal */
name|Int
name|est
decl_stmt|;
comment|/* estimated quotient */
endif|#
directive|endif
if|#
directive|if
name|DECTRACE
if|if
condition|(
name|alength
operator|<
literal|1
operator|||
name|blength
operator|<
literal|1
condition|)
name|printf
argument_list|(
literal|"decUnitAddSub: alen blen m %d %d [%d]\n"
argument_list|,
name|alength
argument_list|,
name|blength
argument_list|,
name|m
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|maxC
operator|=
name|c
operator|+
name|alength
expr_stmt|;
comment|/* A is usually the longer */
name|minC
operator|=
name|c
operator|+
name|blength
expr_stmt|;
comment|/* .. and B the shorter */
if|if
condition|(
name|bshift
operator|!=
literal|0
condition|)
block|{
comment|/* B is shifted; low As copy across */
name|minC
operator|+=
name|bshift
expr_stmt|;
comment|/* if in place [common], skip copy unless there's a gap [rare] */
if|if
condition|(
name|a
operator|==
name|c
operator|&&
name|bshift
operator|<=
name|alength
condition|)
block|{
name|c
operator|+=
name|bshift
expr_stmt|;
name|a
operator|+=
name|bshift
expr_stmt|;
block|}
else|else
for|for
control|(
init|;
name|c
operator|<
name|clsu
operator|+
name|bshift
condition|;
name|a
operator|++
operator|,
name|c
operator|++
control|)
block|{
comment|/* copy needed */
if|if
condition|(
name|a
operator|<
name|alsu
operator|+
name|alength
condition|)
operator|*
name|c
operator|=
operator|*
name|a
expr_stmt|;
else|else
operator|*
name|c
operator|=
literal|0
expr_stmt|;
block|}
block|}
if|if
condition|(
name|minC
operator|>
name|maxC
condition|)
block|{
comment|/* swap */
name|Unit
modifier|*
name|hold
init|=
name|minC
decl_stmt|;
name|minC
operator|=
name|maxC
expr_stmt|;
name|maxC
operator|=
name|hold
expr_stmt|;
block|}
comment|/* For speed, we do the addition as two loops; the first where both A */
comment|/* and B contribute, and the second (if necessary) where only one or */
comment|/* other of the numbers contribute. */
comment|/* Carry handling is the same (i.e., duplicated) in each case. */
for|for
control|(
init|;
name|c
operator|<
name|minC
condition|;
name|c
operator|++
control|)
block|{
name|carry
operator|+=
operator|*
name|a
expr_stmt|;
name|a
operator|++
expr_stmt|;
name|carry
operator|+=
operator|(
operator|(
name|eInt
operator|)
operator|*
name|b
operator|)
operator|*
name|m
expr_stmt|;
comment|/* [special-casing m=1/-1 */
name|b
operator|++
expr_stmt|;
comment|/* here is not a win] */
comment|/* here carry is new Unit of digits; it could be +ve or -ve */
if|if
condition|(
operator|(
name|ueInt
operator|)
name|carry
operator|<=
name|DECDPUNMAX
condition|)
block|{
comment|/* fastpath 0-DECDPUNMAX */
operator|*
name|c
operator|=
operator|(
name|Unit
operator|)
name|carry
expr_stmt|;
name|carry
operator|=
literal|0
expr_stmt|;
continue|continue;
block|}
comment|/* remainder operator is undefined if negative, so we must test */
if|#
directive|if
name|DECDPUN
operator|==
literal|4
comment|/* use divide-by-multiply */
if|if
condition|(
name|carry
operator|>=
literal|0
condition|)
block|{
name|est
operator|=
operator|(
operator|(
operator|(
name|ueInt
operator|)
name|carry
operator|>>
literal|11
operator|)
operator|*
literal|53687
operator|)
operator|>>
literal|18
expr_stmt|;
operator|*
name|c
operator|=
call|(
name|Unit
call|)
argument_list|(
name|carry
operator|-
name|est
operator|*
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
argument_list|)
expr_stmt|;
comment|/* remainder */
name|carry
operator|=
name|est
expr_stmt|;
comment|/* likely quotient [89%] */
if|if
condition|(
operator|*
name|c
operator|<
name|DECDPUNMAX
operator|+
literal|1
condition|)
continue|continue;
comment|/* estimate was correct */
name|carry
operator|++
expr_stmt|;
operator|*
name|c
operator|-=
name|DECDPUNMAX
operator|+
literal|1
expr_stmt|;
continue|continue;
block|}
comment|/* negative case */
name|carry
operator|=
name|carry
operator|+
call|(
name|eInt
call|)
argument_list|(
name|DECDPUNMAX
operator|+
literal|1
argument_list|)
operator|*
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
expr_stmt|;
comment|/* make positive */
name|est
operator|=
operator|(
operator|(
operator|(
name|ueInt
operator|)
name|carry
operator|>>
literal|11
operator|)
operator|*
literal|53687
operator|)
operator|>>
literal|18
expr_stmt|;
operator|*
name|c
operator|=
call|(
name|Unit
call|)
argument_list|(
name|carry
operator|-
name|est
operator|*
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
argument_list|)
expr_stmt|;
name|carry
operator|=
name|est
operator|-
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
expr_stmt|;
comment|/* correctly negative */
if|if
condition|(
operator|*
name|c
operator|<
name|DECDPUNMAX
operator|+
literal|1
condition|)
continue|continue;
comment|/* was OK */
name|carry
operator|++
expr_stmt|;
operator|*
name|c
operator|-=
name|DECDPUNMAX
operator|+
literal|1
expr_stmt|;
else|#
directive|else
if|if
condition|(
operator|(
name|ueInt
operator|)
name|carry
operator|<
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
operator|*
literal|2
condition|)
block|{
comment|/* fastpath carry +1 */
operator|*
name|c
operator|=
call|(
name|Unit
call|)
argument_list|(
name|carry
operator|-
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
argument_list|)
expr_stmt|;
comment|/* [helps additions] */
name|carry
operator|=
literal|1
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|carry
operator|>=
literal|0
condition|)
block|{
operator|*
name|c
operator|=
call|(
name|Unit
call|)
argument_list|(
name|carry
operator|%
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
argument_list|)
expr_stmt|;
name|carry
operator|=
name|carry
operator|/
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
expr_stmt|;
continue|continue;
block|}
comment|/* negative case */
name|carry
operator|=
name|carry
operator|+
call|(
name|eInt
call|)
argument_list|(
name|DECDPUNMAX
operator|+
literal|1
argument_list|)
operator|*
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
expr_stmt|;
comment|/* make positive */
operator|*
name|c
operator|=
call|(
name|Unit
call|)
argument_list|(
name|carry
operator|%
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
argument_list|)
expr_stmt|;
name|carry
operator|=
name|carry
operator|/
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
operator|-
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|/* c */
comment|/* we now may have one or other to complete */
comment|/* [pretest to avoid loop setup/shutdown] */
if|if
condition|(
name|c
operator|<
name|maxC
condition|)
for|for
control|(
init|;
name|c
operator|<
name|maxC
condition|;
name|c
operator|++
control|)
block|{
if|if
condition|(
name|a
operator|<
name|alsu
operator|+
name|alength
condition|)
block|{
comment|/* still in A */
name|carry
operator|+=
operator|*
name|a
expr_stmt|;
name|a
operator|++
expr_stmt|;
block|}
else|else
block|{
comment|/* inside B */
name|carry
operator|+=
operator|(
operator|(
name|eInt
operator|)
operator|*
name|b
operator|)
operator|*
name|m
expr_stmt|;
name|b
operator|++
expr_stmt|;
block|}
comment|/* here carry is new Unit of digits; it could be +ve or -ve and */
comment|/* magnitude up to DECDPUNMAX squared */
if|if
condition|(
operator|(
name|ueInt
operator|)
name|carry
operator|<=
name|DECDPUNMAX
condition|)
block|{
comment|/* fastpath 0-DECDPUNMAX */
operator|*
name|c
operator|=
operator|(
name|Unit
operator|)
name|carry
expr_stmt|;
name|carry
operator|=
literal|0
expr_stmt|;
continue|continue;
block|}
comment|/* result for this unit is negative or>DECDPUNMAX */
if|#
directive|if
name|DECDPUN
operator|==
literal|4
comment|/* use divide-by-multiply */
comment|/* remainder is undefined if negative, so we must test */
if|if
condition|(
name|carry
operator|>=
literal|0
condition|)
block|{
name|est
operator|=
operator|(
operator|(
operator|(
name|ueInt
operator|)
name|carry
operator|>>
literal|11
operator|)
operator|*
literal|53687
operator|)
operator|>>
literal|18
expr_stmt|;
operator|*
name|c
operator|=
call|(
name|Unit
call|)
argument_list|(
name|carry
operator|-
name|est
operator|*
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
argument_list|)
expr_stmt|;
comment|/* remainder */
name|carry
operator|=
name|est
expr_stmt|;
comment|/* likely quotient [79.7%] */
if|if
condition|(
operator|*
name|c
operator|<
name|DECDPUNMAX
operator|+
literal|1
condition|)
continue|continue;
comment|/* estimate was correct */
name|carry
operator|++
expr_stmt|;
operator|*
name|c
operator|-=
name|DECDPUNMAX
operator|+
literal|1
expr_stmt|;
continue|continue;
block|}
comment|/* negative case */
name|carry
operator|=
name|carry
operator|+
call|(
name|eInt
call|)
argument_list|(
name|DECDPUNMAX
operator|+
literal|1
argument_list|)
operator|*
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
expr_stmt|;
comment|/* make positive */
name|est
operator|=
operator|(
operator|(
operator|(
name|ueInt
operator|)
name|carry
operator|>>
literal|11
operator|)
operator|*
literal|53687
operator|)
operator|>>
literal|18
expr_stmt|;
operator|*
name|c
operator|=
call|(
name|Unit
call|)
argument_list|(
name|carry
operator|-
name|est
operator|*
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
argument_list|)
expr_stmt|;
name|carry
operator|=
name|est
operator|-
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
expr_stmt|;
comment|/* correctly negative */
if|if
condition|(
operator|*
name|c
operator|<
name|DECDPUNMAX
operator|+
literal|1
condition|)
continue|continue;
comment|/* was OK */
name|carry
operator|++
expr_stmt|;
operator|*
name|c
operator|-=
name|DECDPUNMAX
operator|+
literal|1
expr_stmt|;
else|#
directive|else
if|if
condition|(
operator|(
name|ueInt
operator|)
name|carry
operator|<
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
operator|*
literal|2
condition|)
block|{
comment|/* fastpath carry 1 */
operator|*
name|c
operator|=
call|(
name|Unit
call|)
argument_list|(
name|carry
operator|-
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
argument_list|)
expr_stmt|;
name|carry
operator|=
literal|1
expr_stmt|;
continue|continue;
block|}
comment|/* remainder is undefined if negative, so we must test */
if|if
condition|(
name|carry
operator|>=
literal|0
condition|)
block|{
operator|*
name|c
operator|=
call|(
name|Unit
call|)
argument_list|(
name|carry
operator|%
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
argument_list|)
expr_stmt|;
name|carry
operator|=
name|carry
operator|/
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
expr_stmt|;
continue|continue;
block|}
comment|/* negative case */
name|carry
operator|=
name|carry
operator|+
call|(
name|eInt
call|)
argument_list|(
name|DECDPUNMAX
operator|+
literal|1
argument_list|)
operator|*
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
expr_stmt|;
comment|/* make positive */
operator|*
name|c
operator|=
call|(
name|Unit
call|)
argument_list|(
name|carry
operator|%
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
argument_list|)
expr_stmt|;
name|carry
operator|=
name|carry
operator|/
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
operator|-
operator|(
name|DECDPUNMAX
operator|+
literal|1
operator|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|/* c */
comment|/* OK, all A and B processed; might still have carry or borrow */
comment|/* return number of Units in the result, negated if a borrow */
if|if
condition|(
name|carry
operator|==
literal|0
condition|)
return|return
name|c
operator|-
name|clsu
return|;
comment|/* no carry, we're done */
if|if
condition|(
name|carry
operator|>
literal|0
condition|)
block|{
comment|/* positive carry */
operator|*
name|c
operator|=
operator|(
name|Unit
operator|)
name|carry
expr_stmt|;
comment|/* place as new unit */
name|c
operator|++
expr_stmt|;
comment|/* .. */
return|return
name|c
operator|-
name|clsu
return|;
block|}
comment|/* -ve carry: it's a borrow; complement needed */
name|add
operator|=
literal|1
expr_stmt|;
comment|/* temporary carry... */
for|for
control|(
name|c
operator|=
name|clsu
init|;
name|c
operator|<
name|maxC
condition|;
name|c
operator|++
control|)
block|{
name|add
operator|=
name|DECDPUNMAX
operator|+
name|add
operator|-
operator|*
name|c
expr_stmt|;
if|if
condition|(
name|add
operator|<=
name|DECDPUNMAX
condition|)
block|{
operator|*
name|c
operator|=
operator|(
name|Unit
operator|)
name|add
expr_stmt|;
name|add
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
operator|*
name|c
operator|=
literal|0
expr_stmt|;
name|add
operator|=
literal|1
expr_stmt|;
block|}
block|}
comment|/* add an extra unit iff it would be non-zero */
if|#
directive|if
name|DECTRACE
name|printf
argument_list|(
literal|"UAS borrow: add %d, carry %d\n"
argument_list|,
name|add
argument_list|,
name|carry
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|(
name|add
operator|-
name|carry
operator|-
literal|1
operator|)
operator|!=
literal|0
condition|)
block|{
operator|*
name|c
operator|=
call|(
name|Unit
call|)
argument_list|(
name|add
operator|-
name|carry
operator|-
literal|1
argument_list|)
expr_stmt|;
name|c
operator|++
expr_stmt|;
comment|/* interesting, include it */
block|}
return|return
name|clsu
operator|-
name|c
return|;
comment|/* -ve result indicates borrowed */
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decTrim -- trim trailing zeros or normalize                        */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   dn is the number to trim or normalize                            */
end_comment

begin_comment
comment|/*   all is 1 to remove all trailing zeros, 0 for just fraction ones  */
end_comment

begin_comment
comment|/*   dropped returns the number of discarded trailing zeros           */
end_comment

begin_comment
comment|/*   returns dn                                                       */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* All fields are updated as required.  This is a utility operation,  */
end_comment

begin_comment
comment|/* so special values are unchanged and no error is possible.          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|decNumber
modifier|*
name|decTrim
parameter_list|(
name|decNumber
modifier|*
name|dn
parameter_list|,
name|Flag
name|all
parameter_list|,
name|Int
modifier|*
name|dropped
parameter_list|)
block|{
name|Int
name|d
decl_stmt|,
name|exp
decl_stmt|;
comment|/* work */
name|uInt
name|cut
decl_stmt|;
comment|/* .. */
name|Unit
modifier|*
name|up
decl_stmt|;
comment|/* -> current Unit */
if|#
directive|if
name|DECCHECK
if|if
condition|(
name|decCheckOperands
argument_list|(
name|dn
argument_list|,
name|DECUNUSED
argument_list|,
name|DECUNUSED
argument_list|,
name|DECUNUSED
argument_list|)
condition|)
return|return
name|dn
return|;
endif|#
directive|endif
operator|*
name|dropped
operator|=
literal|0
expr_stmt|;
comment|/* assume no zeros dropped */
if|if
condition|(
operator|(
name|dn
operator|->
name|bits
operator|&
name|DECSPECIAL
operator|)
comment|/* fast exit if special .. */
operator|||
operator|(
operator|*
name|dn
operator|->
name|lsu
operator|&
literal|0x01
operator|)
condition|)
return|return
name|dn
return|;
comment|/* .. or odd */
if|if
condition|(
name|ISZERO
argument_list|(
name|dn
argument_list|)
condition|)
block|{
comment|/* .. or 0 */
name|dn
operator|->
name|exponent
operator|=
literal|0
expr_stmt|;
comment|/* (sign is preserved) */
return|return
name|dn
return|;
block|}
comment|/* we have a finite number which is even */
name|exp
operator|=
name|dn
operator|->
name|exponent
expr_stmt|;
name|cut
operator|=
literal|1
expr_stmt|;
comment|/* digit (1-DECDPUN) in Unit */
name|up
operator|=
name|dn
operator|->
name|lsu
expr_stmt|;
comment|/* -> current Unit */
for|for
control|(
name|d
operator|=
literal|0
init|;
name|d
operator|<
name|dn
operator|->
name|digits
operator|-
literal|1
condition|;
name|d
operator|++
control|)
block|{
comment|/* [don't strip the final digit] */
comment|/* slice by powers */
if|#
directive|if
name|DECDPUN
operator|<=
literal|4
name|uInt
name|quot
init|=
name|QUOT10
argument_list|(
operator|*
name|up
argument_list|,
name|cut
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
operator|*
name|up
operator|-
name|quot
operator|*
name|powers
index|[
name|cut
index|]
operator|)
operator|!=
literal|0
condition|)
break|break;
comment|/* found non-0 digit */
else|#
directive|else
if|if
condition|(
operator|*
name|up
operator|%
name|powers
index|[
name|cut
index|]
operator|!=
literal|0
condition|)
break|break;
comment|/* found non-0 digit */
endif|#
directive|endif
comment|/* have a trailing 0 */
if|if
condition|(
operator|!
name|all
condition|)
block|{
comment|/* trimming */
comment|/* [if exp>0 then all trailing 0s are significant for trim] */
if|if
condition|(
name|exp
operator|<=
literal|0
condition|)
block|{
comment|/* if digit might be significant */
if|if
condition|(
name|exp
operator|==
literal|0
condition|)
break|break;
comment|/* then quit */
name|exp
operator|++
expr_stmt|;
comment|/* next digit might be significant */
block|}
block|}
name|cut
operator|++
expr_stmt|;
comment|/* next power */
if|if
condition|(
name|cut
operator|>
name|DECDPUN
condition|)
block|{
comment|/* need new Unit */
name|up
operator|++
expr_stmt|;
name|cut
operator|=
literal|1
expr_stmt|;
block|}
block|}
comment|/* d */
if|if
condition|(
name|d
operator|==
literal|0
condition|)
return|return
name|dn
return|;
comment|/* none dropped */
comment|/* effect the drop */
name|decShiftToLeast
argument_list|(
name|dn
operator|->
name|lsu
argument_list|,
name|D2U
argument_list|(
name|dn
operator|->
name|digits
argument_list|)
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|dn
operator|->
name|exponent
operator|+=
name|d
expr_stmt|;
comment|/* maintain numerical value */
name|dn
operator|->
name|digits
operator|-=
name|d
expr_stmt|;
comment|/* new length */
operator|*
name|dropped
operator|=
name|d
expr_stmt|;
comment|/* report the count */
return|return
name|dn
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decShiftToMost -- shift digits in array towards most significant   */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   uar    is the array                                              */
end_comment

begin_comment
comment|/*   digits is the count of digits in use in the array                */
end_comment

begin_comment
comment|/*   shift  is the number of zeros to pad with (least significant);   */
end_comment

begin_comment
comment|/*     it must be zero or positive                                    */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   returns the new length of the integer in the array, in digits    */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* No overflow is permitted (that is, the uar array must be known to  */
end_comment

begin_comment
comment|/* be large enough to hold the result, after shifting).               */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|Int
name|decShiftToMost
parameter_list|(
name|Unit
modifier|*
name|uar
parameter_list|,
name|Int
name|digits
parameter_list|,
name|Int
name|shift
parameter_list|)
block|{
name|Unit
modifier|*
name|target
decl_stmt|,
modifier|*
name|source
decl_stmt|,
modifier|*
name|first
decl_stmt|;
comment|/* work */
name|uInt
name|rem
decl_stmt|;
comment|/* for division */
name|Int
name|cut
decl_stmt|;
comment|/* odd 0's to add */
name|uInt
name|next
decl_stmt|;
comment|/* work */
if|if
condition|(
name|shift
operator|==
literal|0
condition|)
return|return
name|digits
return|;
comment|/* [fastpath] nothing to do */
if|if
condition|(
operator|(
name|digits
operator|+
name|shift
operator|)
operator|<=
name|DECDPUN
condition|)
block|{
comment|/* [fastpath] single-unit case */
operator|*
name|uar
operator|=
call|(
name|Unit
call|)
argument_list|(
operator|*
name|uar
operator|*
name|powers
index|[
name|shift
index|]
argument_list|)
expr_stmt|;
return|return
name|digits
operator|+
name|shift
return|;
block|}
name|cut
operator|=
operator|(
name|DECDPUN
operator|-
name|shift
operator|%
name|DECDPUN
operator|)
operator|%
name|DECDPUN
expr_stmt|;
name|source
operator|=
name|uar
operator|+
name|D2U
argument_list|(
name|digits
argument_list|)
operator|-
literal|1
expr_stmt|;
comment|/* where msu comes from */
name|first
operator|=
name|uar
operator|+
name|D2U
argument_list|(
name|digits
operator|+
name|shift
argument_list|)
operator|-
literal|1
expr_stmt|;
comment|/* where msu of source will end up */
name|target
operator|=
name|source
operator|+
name|D2U
argument_list|(
name|shift
argument_list|)
expr_stmt|;
comment|/* where upper part of first cut goes */
name|next
operator|=
literal|0
expr_stmt|;
for|for
control|(
init|;
name|source
operator|>=
name|uar
condition|;
name|source
operator|--
operator|,
name|target
operator|--
control|)
block|{
comment|/* split the source Unit and accumulate remainder for next */
if|#
directive|if
name|DECDPUN
operator|<=
literal|4
name|uInt
name|quot
init|=
name|QUOT10
argument_list|(
operator|*
name|source
argument_list|,
name|cut
argument_list|)
decl_stmt|;
name|rem
operator|=
operator|*
name|source
operator|-
name|quot
operator|*
name|powers
index|[
name|cut
index|]
expr_stmt|;
name|next
operator|+=
name|quot
expr_stmt|;
else|#
directive|else
name|rem
operator|=
operator|*
name|source
operator|%
name|powers
index|[
name|cut
index|]
expr_stmt|;
name|next
operator|+=
operator|*
name|source
operator|/
name|powers
index|[
name|cut
index|]
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|target
operator|<=
name|first
condition|)
operator|*
name|target
operator|=
operator|(
name|Unit
operator|)
name|next
expr_stmt|;
comment|/* write to target iff valid */
name|next
operator|=
name|rem
operator|*
name|powers
index|[
name|DECDPUN
operator|-
name|cut
index|]
expr_stmt|;
comment|/* save remainder for next Unit */
block|}
comment|/* propagate to one below and clear the rest */
for|for
control|(
init|;
name|target
operator|>=
name|uar
condition|;
name|target
operator|--
control|)
block|{
operator|*
name|target
operator|=
operator|(
name|Unit
operator|)
name|next
expr_stmt|;
name|next
operator|=
literal|0
expr_stmt|;
block|}
return|return
name|digits
operator|+
name|shift
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decShiftToLeast -- shift digits in array towards least significant */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   uar   is the array                                               */
end_comment

begin_comment
comment|/*   units is length of the array, in units                           */
end_comment

begin_comment
comment|/*   shift is the number of digits to remove from the lsu end; it     */
end_comment

begin_comment
comment|/*     must be zero or positive and less than units*DECDPUN.          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   returns the new length of the integer in the array, in units     */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* Removed digits are discarded (lost).  Units not required to hold   */
end_comment

begin_comment
comment|/* the final result are unchanged.                                    */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|Int
name|decShiftToLeast
parameter_list|(
name|Unit
modifier|*
name|uar
parameter_list|,
name|Int
name|units
parameter_list|,
name|Int
name|shift
parameter_list|)
block|{
name|Unit
modifier|*
name|target
decl_stmt|,
modifier|*
name|up
decl_stmt|;
comment|/* work */
name|Int
name|cut
decl_stmt|,
name|count
decl_stmt|;
comment|/* work */
name|Int
name|quot
decl_stmt|,
name|rem
decl_stmt|;
comment|/* for division */
if|if
condition|(
name|shift
operator|==
literal|0
condition|)
return|return
name|units
return|;
comment|/* [fastpath] nothing to do */
name|up
operator|=
name|uar
operator|+
name|shift
operator|/
name|DECDPUN
expr_stmt|;
comment|/* source; allow for whole Units */
name|cut
operator|=
name|shift
operator|%
name|DECDPUN
expr_stmt|;
comment|/* odd 0's to drop */
name|target
operator|=
name|uar
expr_stmt|;
comment|/* both paths */
if|if
condition|(
name|cut
operator|==
literal|0
condition|)
block|{
comment|/* whole units shift */
for|for
control|(
init|;
name|up
operator|<
name|uar
operator|+
name|units
condition|;
name|target
operator|++
operator|,
name|up
operator|++
control|)
operator|*
name|target
operator|=
operator|*
name|up
expr_stmt|;
return|return
name|target
operator|-
name|uar
return|;
block|}
comment|/* messier */
name|count
operator|=
name|units
operator|*
name|DECDPUN
operator|-
name|shift
expr_stmt|;
comment|/* the maximum new length */
if|#
directive|if
name|DECDPUN
operator|<=
literal|4
name|quot
operator|=
name|QUOT10
argument_list|(
operator|*
name|up
argument_list|,
name|cut
argument_list|)
expr_stmt|;
else|#
directive|else
name|quot
operator|=
operator|*
name|up
operator|/
name|powers
index|[
name|cut
index|]
expr_stmt|;
endif|#
directive|endif
for|for
control|(
init|;
condition|;
name|target
operator|++
control|)
block|{
operator|*
name|target
operator|=
operator|(
name|Unit
operator|)
name|quot
expr_stmt|;
name|count
operator|-=
operator|(
name|DECDPUN
operator|-
name|cut
operator|)
expr_stmt|;
if|if
condition|(
name|count
operator|<=
literal|0
condition|)
break|break;
name|up
operator|++
expr_stmt|;
name|quot
operator|=
operator|*
name|up
expr_stmt|;
if|#
directive|if
name|DECDPUN
operator|<=
literal|4
name|quot
operator|=
name|QUOT10
argument_list|(
name|quot
argument_list|,
name|cut
argument_list|)
expr_stmt|;
name|rem
operator|=
operator|*
name|up
operator|-
name|quot
operator|*
name|powers
index|[
name|cut
index|]
expr_stmt|;
else|#
directive|else
name|rem
operator|=
name|quot
operator|%
name|powers
index|[
name|cut
index|]
expr_stmt|;
name|quot
operator|=
name|quot
operator|/
name|powers
index|[
name|cut
index|]
expr_stmt|;
endif|#
directive|endif
operator|*
name|target
operator|=
call|(
name|Unit
call|)
argument_list|(
operator|*
name|target
operator|+
name|rem
operator|*
name|powers
index|[
name|DECDPUN
operator|-
name|cut
index|]
argument_list|)
expr_stmt|;
name|count
operator|-=
name|cut
expr_stmt|;
if|if
condition|(
name|count
operator|<=
literal|0
condition|)
break|break;
block|}
return|return
name|target
operator|-
name|uar
operator|+
literal|1
return|;
block|}
end_function

begin_if
if|#
directive|if
name|DECSUBSET
end_if

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decRoundOperand -- round an operand  [used for subset only]        */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   dn is the number to round (dn->digits is> set->digits)          */
end_comment

begin_comment
comment|/*   set is the relevant context                                      */
end_comment

begin_comment
comment|/*   status is the status accumulator                                 */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   returns an allocated decNumber with the rounded result.          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* lostDigits and other status may be set by this.                    */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* Since the input is an operand, we are not permitted to modify it.  */
end_comment

begin_comment
comment|/* We therefore return an allocated decNumber, rounded as required.   */
end_comment

begin_comment
comment|/* It is the caller's responsibility to free the allocated storage.   */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* If no storage is available then the result cannot be used, so NULL */
end_comment

begin_comment
comment|/* is returned.                                                       */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|decNumber
modifier|*
name|decRoundOperand
parameter_list|(
specifier|const
name|decNumber
modifier|*
name|dn
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|,
name|uInt
modifier|*
name|status
parameter_list|)
block|{
name|decNumber
modifier|*
name|res
decl_stmt|;
comment|/* result structure */
name|uInt
name|newstatus
init|=
literal|0
decl_stmt|;
comment|/* status from round */
name|Int
name|residue
init|=
literal|0
decl_stmt|;
comment|/* rounding accumulator */
comment|/* Allocate storage for the returned decNumber, big enough for the */
comment|/* length specified by the context */
name|res
operator|=
operator|(
name|decNumber
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|decNumber
argument_list|)
operator|+
operator|(
name|D2U
argument_list|(
name|set
operator|->
name|digits
argument_list|)
operator|-
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|Unit
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|res
operator|==
name|NULL
condition|)
block|{
operator|*
name|status
operator||=
name|DEC_Insufficient_storage
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|decCopyFit
argument_list|(
name|res
argument_list|,
name|dn
argument_list|,
name|set
argument_list|,
operator|&
name|residue
argument_list|,
operator|&
name|newstatus
argument_list|)
expr_stmt|;
name|decApplyRound
argument_list|(
name|res
argument_list|,
name|set
argument_list|,
name|residue
argument_list|,
operator|&
name|newstatus
argument_list|)
expr_stmt|;
comment|/* If that set Inexact then we "lost digits" */
if|if
condition|(
name|newstatus
operator|&
name|DEC_Inexact
condition|)
name|newstatus
operator||=
name|DEC_Lost_digits
expr_stmt|;
operator|*
name|status
operator||=
name|newstatus
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decCopyFit -- copy a number, shortening the coefficient if needed  */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   dest is the target decNumber                                     */
end_comment

begin_comment
comment|/*   src  is the source decNumber                                     */
end_comment

begin_comment
comment|/*   set is the context [used for length (digits) and rounding mode]  */
end_comment

begin_comment
comment|/*   residue is the residue accumulator                               */
end_comment

begin_comment
comment|/*   status contains the current status to be updated                 */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* (dest==src is allowed and will be a no-op if fits)                 */
end_comment

begin_comment
comment|/* All fields are updated as required.                                */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|void
name|decCopyFit
parameter_list|(
name|decNumber
modifier|*
name|dest
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|src
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|,
name|Int
modifier|*
name|residue
parameter_list|,
name|uInt
modifier|*
name|status
parameter_list|)
block|{
name|dest
operator|->
name|bits
operator|=
name|src
operator|->
name|bits
expr_stmt|;
name|dest
operator|->
name|exponent
operator|=
name|src
operator|->
name|exponent
expr_stmt|;
name|decSetCoeff
argument_list|(
name|dest
argument_list|,
name|set
argument_list|,
name|src
operator|->
name|lsu
argument_list|,
name|src
operator|->
name|digits
argument_list|,
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decSetCoeff -- set the coefficient of a number                     */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   dn    is the number whose coefficient array is to be set.        */
end_comment

begin_comment
comment|/*         It must have space for set->digits digits                  */
end_comment

begin_comment
comment|/*   set   is the context [for size]                                  */
end_comment

begin_comment
comment|/*   lsu   -> lsu of the source coefficient [may be dn->lsu]          */
end_comment

begin_comment
comment|/*   len   is digits in the source coefficient [may be dn->digits]    */
end_comment

begin_comment
comment|/*   residue is the residue accumulator.  This has values as in       */
end_comment

begin_comment
comment|/*         decApplyRound, and will be unchanged unless the            */
end_comment

begin_comment
comment|/*         target size is less than len.  In this case, the           */
end_comment

begin_comment
comment|/*         coefficient is truncated and the residue is updated to     */
end_comment

begin_comment
comment|/*         reflect the previous residue and the dropped digits.       */
end_comment

begin_comment
comment|/*   status is the status accumulator, as usual                       */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* The coefficient may already be in the number, or it can be an      */
end_comment

begin_comment
comment|/* external intermediate array.  If it is in the number, lsu must ==  */
end_comment

begin_comment
comment|/* dn->lsu and len must == dn->digits.                                */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* Note that the coefficient length (len) may be< set->digits, and   */
end_comment

begin_comment
comment|/* in this case this merely copies the coefficient (or is a no-op     */
end_comment

begin_comment
comment|/* if dn->lsu==lsu).                                                  */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* Note also that (only internally, from decNumberRescale and         */
end_comment

begin_comment
comment|/* decSetSubnormal) the value of set->digits may be less than one,    */
end_comment

begin_comment
comment|/* indicating a round to left.                                        */
end_comment

begin_comment
comment|/* This routine handles that case correctly; caller ensures space.    */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* dn->digits, dn->lsu (and as required), and dn->exponent are        */
end_comment

begin_comment
comment|/* updated as necessary.   dn->bits (sign) is unchanged.              */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* DEC_Rounded status is set if any digits are discarded.             */
end_comment

begin_comment
comment|/* DEC_Inexact status is set if any non-zero digits are discarded, or */
end_comment

begin_comment
comment|/*                       incoming residue was non-0 (implies rounded) */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* mapping array: maps 0-9 to canonical residues, so that we can */
end_comment

begin_comment
comment|/* adjust by a residue in range [-1, +1] and achieve correct rounding */
end_comment

begin_comment
comment|/*                             0  1  2  3  4  5  6  7  8  9 */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|uByte
name|resmap
index|[
literal|10
index|]
init|=
block|{
literal|0
block|,
literal|3
block|,
literal|3
block|,
literal|3
block|,
literal|3
block|,
literal|5
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|decSetCoeff
parameter_list|(
name|decNumber
modifier|*
name|dn
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|,
specifier|const
name|Unit
modifier|*
name|lsu
parameter_list|,
name|Int
name|len
parameter_list|,
name|Int
modifier|*
name|residue
parameter_list|,
name|uInt
modifier|*
name|status
parameter_list|)
block|{
name|Int
name|discard
decl_stmt|;
comment|/* number of digits to discard */
name|uInt
name|discard1
decl_stmt|;
comment|/* first discarded digit */
name|uInt
name|cut
decl_stmt|;
comment|/* cut point in Unit */
name|uInt
name|quot
decl_stmt|,
name|rem
decl_stmt|;
comment|/* for divisions */
name|Unit
modifier|*
name|target
decl_stmt|;
comment|/* work */
specifier|const
name|Unit
modifier|*
name|up
decl_stmt|;
comment|/* work */
name|Int
name|count
decl_stmt|;
comment|/* .. */
if|#
directive|if
name|DECDPUN
operator|<=
literal|4
name|uInt
name|temp
decl_stmt|;
comment|/* .. */
endif|#
directive|endif
name|discard
operator|=
name|len
operator|-
name|set
operator|->
name|digits
expr_stmt|;
comment|/* digits to discard */
if|if
condition|(
name|discard
operator|<=
literal|0
condition|)
block|{
comment|/* no digits are being discarded */
if|if
condition|(
name|dn
operator|->
name|lsu
operator|!=
name|lsu
condition|)
block|{
comment|/* copy needed */
comment|/* copy the coefficient array to the result number; no shift needed */
name|up
operator|=
name|lsu
expr_stmt|;
for|for
control|(
name|target
operator|=
name|dn
operator|->
name|lsu
init|;
name|target
operator|<
name|dn
operator|->
name|lsu
operator|+
name|D2U
argument_list|(
name|len
argument_list|)
condition|;
name|target
operator|++
operator|,
name|up
operator|++
control|)
block|{
operator|*
name|target
operator|=
operator|*
name|up
expr_stmt|;
block|}
name|dn
operator|->
name|digits
operator|=
name|len
expr_stmt|;
comment|/* set the new length */
block|}
comment|/* dn->exponent and residue are unchanged */
if|if
condition|(
operator|*
name|residue
operator|!=
literal|0
condition|)
operator|*
name|status
operator||=
operator|(
name|DEC_Inexact
operator||
name|DEC_Rounded
operator|)
expr_stmt|;
comment|/* record inexactitude */
return|return;
block|}
comment|/* we have to discard some digits */
operator|*
name|status
operator||=
name|DEC_Rounded
expr_stmt|;
comment|/* accumulate Rounded status */
if|if
condition|(
operator|*
name|residue
operator|>
literal|1
condition|)
operator|*
name|residue
operator|=
literal|1
expr_stmt|;
comment|/* previous residue now to right, so -1 to +1 */
if|if
condition|(
name|discard
operator|>
name|len
condition|)
block|{
comment|/* everything, +1, is being discarded */
comment|/* guard digit is 0 */
comment|/* residue is all the number [NB could be all 0s] */
if|if
condition|(
operator|*
name|residue
operator|<=
literal|0
condition|)
for|for
control|(
name|up
operator|=
name|lsu
operator|+
name|D2U
argument_list|(
name|len
argument_list|)
operator|-
literal|1
init|;
name|up
operator|>=
name|lsu
condition|;
name|up
operator|--
control|)
block|{
if|if
condition|(
operator|*
name|up
operator|!=
literal|0
condition|)
block|{
comment|/* found a non-0 */
operator|*
name|residue
operator|=
literal|1
expr_stmt|;
break|break;
comment|/* no need to check any others */
block|}
block|}
if|if
condition|(
operator|*
name|residue
operator|!=
literal|0
condition|)
operator|*
name|status
operator||=
name|DEC_Inexact
expr_stmt|;
comment|/* record inexactitude */
operator|*
name|dn
operator|->
name|lsu
operator|=
literal|0
expr_stmt|;
comment|/* coefficient will now be 0 */
name|dn
operator|->
name|digits
operator|=
literal|1
expr_stmt|;
comment|/* .. */
name|dn
operator|->
name|exponent
operator|+=
name|discard
expr_stmt|;
comment|/* maintain numerical value */
return|return;
block|}
comment|/* total discard */
comment|/* partial discard [most common case] */
comment|/* here, at least the first (most significant) discarded digit exists */
comment|/* spin up the number, noting residue as we pass, until we get to */
comment|/* the Unit with the first discarded digit.  When we get there, */
comment|/* extract it and remember where we're at */
name|count
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|up
operator|=
name|lsu
init|;
condition|;
name|up
operator|++
control|)
block|{
name|count
operator|+=
name|DECDPUN
expr_stmt|;
if|if
condition|(
name|count
operator|>=
name|discard
condition|)
break|break;
comment|/* full ones all checked */
if|if
condition|(
operator|*
name|up
operator|!=
literal|0
condition|)
operator|*
name|residue
operator|=
literal|1
expr_stmt|;
block|}
comment|/* up */
comment|/* here up -> Unit with discarded digit */
name|cut
operator|=
name|discard
operator|-
operator|(
name|count
operator|-
name|DECDPUN
operator|)
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|cut
operator|==
name|DECDPUN
operator|-
literal|1
condition|)
block|{
comment|/* discard digit is at top */
if|#
directive|if
name|DECDPUN
operator|<=
literal|4
name|discard1
operator|=
name|QUOT10
argument_list|(
operator|*
name|up
argument_list|,
name|DECDPUN
operator|-
literal|1
argument_list|)
expr_stmt|;
name|rem
operator|=
operator|*
name|up
operator|-
name|discard1
operator|*
name|powers
index|[
name|DECDPUN
operator|-
literal|1
index|]
expr_stmt|;
else|#
directive|else
name|rem
operator|=
operator|*
name|up
operator|%
name|powers
index|[
name|DECDPUN
operator|-
literal|1
index|]
expr_stmt|;
name|discard1
operator|=
operator|*
name|up
operator|/
name|powers
index|[
name|DECDPUN
operator|-
literal|1
index|]
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|rem
operator|!=
literal|0
condition|)
operator|*
name|residue
operator|=
literal|1
expr_stmt|;
name|up
operator|++
expr_stmt|;
comment|/* move to next */
name|cut
operator|=
literal|0
expr_stmt|;
comment|/* bottom digit of result */
name|quot
operator|=
literal|0
expr_stmt|;
comment|/* keep a certain compiler happy */
block|}
else|else
block|{
comment|/* discard digit is in low digit(s), not top digit */
if|if
condition|(
name|cut
operator|==
literal|0
condition|)
name|quot
operator|=
operator|*
name|up
expr_stmt|;
else|else
comment|/* cut>0 */
block|{
comment|/* it's not at bottom of Unit */
if|#
directive|if
name|DECDPUN
operator|<=
literal|4
name|quot
operator|=
name|QUOT10
argument_list|(
operator|*
name|up
argument_list|,
name|cut
argument_list|)
expr_stmt|;
name|rem
operator|=
operator|*
name|up
operator|-
name|quot
operator|*
name|powers
index|[
name|cut
index|]
expr_stmt|;
else|#
directive|else
name|rem
operator|=
operator|*
name|up
operator|%
name|powers
index|[
name|cut
index|]
expr_stmt|;
name|quot
operator|=
operator|*
name|up
operator|/
name|powers
index|[
name|cut
index|]
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|rem
operator|!=
literal|0
condition|)
operator|*
name|residue
operator|=
literal|1
expr_stmt|;
block|}
comment|/* discard digit is now at bottom of quot */
if|#
directive|if
name|DECDPUN
operator|<=
literal|4
name|temp
operator|=
operator|(
name|quot
operator|*
literal|6554
operator|)
operator|>>
literal|16
expr_stmt|;
comment|/* fast /10 */
comment|/* Vowels algorithm here not a win (9 instructions) */
name|discard1
operator|=
name|quot
operator|-
name|X10
argument_list|(
name|temp
argument_list|)
expr_stmt|;
name|quot
operator|=
name|temp
expr_stmt|;
else|#
directive|else
name|discard1
operator|=
name|quot
operator|%
literal|10
expr_stmt|;
name|quot
operator|=
name|quot
operator|/
literal|10
expr_stmt|;
endif|#
directive|endif
name|cut
operator|++
expr_stmt|;
comment|/* update cut */
block|}
comment|/* here: up -> Unit of the array with discarded digit */
comment|/*       cut is the division point for each Unit */
comment|/*       quot holds the uncut high-order digits for the current */
comment|/*            Unit, unless cut==0 in which case it's still in *up */
comment|/* copy the coefficient array to the result number, shifting as we go */
name|count
operator|=
name|set
operator|->
name|digits
expr_stmt|;
comment|/* digits to end up with */
if|if
condition|(
name|count
operator|<=
literal|0
condition|)
block|{
comment|/* special for Rescale/Subnormal :-( */
operator|*
name|dn
operator|->
name|lsu
operator|=
literal|0
expr_stmt|;
comment|/* .. result is 0 */
name|dn
operator|->
name|digits
operator|=
literal|1
expr_stmt|;
comment|/* .. */
block|}
else|else
block|{
comment|/* shift to least */
comment|/* [this is similar to decShiftToLeast code, with copy] */
name|dn
operator|->
name|digits
operator|=
name|count
expr_stmt|;
comment|/* set the new length */
if|if
condition|(
name|cut
operator|==
literal|0
condition|)
block|{
comment|/* on unit boundary, so simple shift down copy loop suffices */
for|for
control|(
name|target
operator|=
name|dn
operator|->
name|lsu
init|;
name|target
operator|<
name|dn
operator|->
name|lsu
operator|+
name|D2U
argument_list|(
name|count
argument_list|)
condition|;
name|target
operator|++
operator|,
name|up
operator|++
control|)
block|{
operator|*
name|target
operator|=
operator|*
name|up
expr_stmt|;
block|}
block|}
else|else
for|for
control|(
name|target
operator|=
name|dn
operator|->
name|lsu
init|;
condition|;
name|target
operator|++
control|)
block|{
operator|*
name|target
operator|=
operator|(
name|Unit
operator|)
name|quot
expr_stmt|;
name|count
operator|-=
operator|(
name|DECDPUN
operator|-
name|cut
operator|)
expr_stmt|;
if|if
condition|(
name|count
operator|<=
literal|0
condition|)
break|break;
name|up
operator|++
expr_stmt|;
name|quot
operator|=
operator|*
name|up
expr_stmt|;
if|#
directive|if
name|DECDPUN
operator|<=
literal|4
name|quot
operator|=
name|QUOT10
argument_list|(
name|quot
argument_list|,
name|cut
argument_list|)
expr_stmt|;
name|rem
operator|=
operator|*
name|up
operator|-
name|quot
operator|*
name|powers
index|[
name|cut
index|]
expr_stmt|;
else|#
directive|else
name|rem
operator|=
name|quot
operator|%
name|powers
index|[
name|cut
index|]
expr_stmt|;
name|quot
operator|=
name|quot
operator|/
name|powers
index|[
name|cut
index|]
expr_stmt|;
endif|#
directive|endif
operator|*
name|target
operator|=
call|(
name|Unit
call|)
argument_list|(
operator|*
name|target
operator|+
name|rem
operator|*
name|powers
index|[
name|DECDPUN
operator|-
name|cut
index|]
argument_list|)
expr_stmt|;
name|count
operator|-=
name|cut
expr_stmt|;
if|if
condition|(
name|count
operator|<=
literal|0
condition|)
break|break;
block|}
block|}
comment|/* shift to least needed */
name|dn
operator|->
name|exponent
operator|+=
name|discard
expr_stmt|;
comment|/* maintain numerical value */
comment|/* here, discard1 is the guard digit, and residue is everything else */
comment|/* [use mapping to accumulate residue safely] */
operator|*
name|residue
operator|+=
name|resmap
index|[
name|discard1
index|]
expr_stmt|;
if|if
condition|(
operator|*
name|residue
operator|!=
literal|0
condition|)
operator|*
name|status
operator||=
name|DEC_Inexact
expr_stmt|;
comment|/* record inexactitude */
return|return;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decApplyRound -- apply pending rounding to a number                */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   dn    is the number, with space for set->digits digits           */
end_comment

begin_comment
comment|/*   set   is the context [for size and rounding mode]                */
end_comment

begin_comment
comment|/*   residue indicates pending rounding, being any accumulated        */
end_comment

begin_comment
comment|/*         guard and sticky information.  It may be:                  */
end_comment

begin_comment
comment|/*         6-9: rounding digit is>5                                  */
end_comment

begin_comment
comment|/*         5:   rounding digit is exactly half-way                    */
end_comment

begin_comment
comment|/*         1-4: rounding digit is<5 and>0                           */
end_comment

begin_comment
comment|/*         0:   the coefficient is exact                              */
end_comment

begin_comment
comment|/*        -1:   as 1, but the hidden digits are subtractive, that     */
end_comment

begin_comment
comment|/*              is, of the opposite sign to dn.  In this case the     */
end_comment

begin_comment
comment|/*              coefficient must be non-0.                            */
end_comment

begin_comment
comment|/*   status is the status accumulator, as usual                       */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* This routine applies rounding while keeping the length of the      */
end_comment

begin_comment
comment|/* coefficient constant.  The exponent and status are unchanged       */
end_comment

begin_comment
comment|/* except if:                                                         */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   -- the coefficient was increased and is all nines (in which      */
end_comment

begin_comment
comment|/*      case Overflow could occur, and is handled directly here so    */
end_comment

begin_comment
comment|/*      the caller does not need to re-test for overflow)             */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   -- the coefficient was decreased and becomes all nines (in which */
end_comment

begin_comment
comment|/*      case Underflow could occur, and is also handled directly).    */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* All fields in dn are updated as required.                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|void
name|decApplyRound
parameter_list|(
name|decNumber
modifier|*
name|dn
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|,
name|Int
name|residue
parameter_list|,
name|uInt
modifier|*
name|status
parameter_list|)
block|{
name|Int
name|bump
decl_stmt|;
comment|/* 1 if coefficient needs to be incremented */
comment|/* -1 if coefficient needs to be decremented */
if|if
condition|(
name|residue
operator|==
literal|0
condition|)
return|return;
comment|/* nothing to apply */
name|bump
operator|=
literal|0
expr_stmt|;
comment|/* assume a smooth ride */
comment|/* now decide whether, and how, to round, depending on mode */
switch|switch
condition|(
name|set
operator|->
name|round
condition|)
block|{
case|case
name|DEC_ROUND_DOWN
case|:
block|{
comment|/* no change, except if negative residue */
if|if
condition|(
name|residue
operator|<
literal|0
condition|)
name|bump
operator|=
operator|-
literal|1
expr_stmt|;
break|break;
block|}
comment|/* r-d */
case|case
name|DEC_ROUND_HALF_DOWN
case|:
block|{
if|if
condition|(
name|residue
operator|>
literal|5
condition|)
name|bump
operator|=
literal|1
expr_stmt|;
break|break;
block|}
comment|/* r-h-d */
case|case
name|DEC_ROUND_HALF_EVEN
case|:
block|{
if|if
condition|(
name|residue
operator|>
literal|5
condition|)
name|bump
operator|=
literal|1
expr_stmt|;
comment|/*>0.5 goes up */
elseif|else
if|if
condition|(
name|residue
operator|==
literal|5
condition|)
block|{
comment|/* exactly 0.5000... */
comment|/* 0.5 goes up iff [new] lsd is odd */
if|if
condition|(
operator|*
name|dn
operator|->
name|lsu
operator|&
literal|0x01
condition|)
name|bump
operator|=
literal|1
expr_stmt|;
block|}
break|break;
block|}
comment|/* r-h-e */
case|case
name|DEC_ROUND_HALF_UP
case|:
block|{
if|if
condition|(
name|residue
operator|>=
literal|5
condition|)
name|bump
operator|=
literal|1
expr_stmt|;
break|break;
block|}
comment|/* r-h-u */
case|case
name|DEC_ROUND_UP
case|:
block|{
if|if
condition|(
name|residue
operator|>
literal|0
condition|)
name|bump
operator|=
literal|1
expr_stmt|;
break|break;
block|}
comment|/* r-u */
case|case
name|DEC_ROUND_CEILING
case|:
block|{
comment|/* same as _UP for positive numbers, and as _DOWN for negatives */
comment|/* [negative residue cannot occur on 0] */
if|if
condition|(
name|decNumberIsNegative
argument_list|(
name|dn
argument_list|)
condition|)
block|{
if|if
condition|(
name|residue
operator|<
literal|0
condition|)
name|bump
operator|=
operator|-
literal|1
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|residue
operator|>
literal|0
condition|)
name|bump
operator|=
literal|1
expr_stmt|;
block|}
break|break;
block|}
comment|/* r-c */
case|case
name|DEC_ROUND_FLOOR
case|:
block|{
comment|/* same as _UP for negative numbers, and as _DOWN for positive */
comment|/* [negative residue cannot occur on 0] */
if|if
condition|(
operator|!
name|decNumberIsNegative
argument_list|(
name|dn
argument_list|)
condition|)
block|{
if|if
condition|(
name|residue
operator|<
literal|0
condition|)
name|bump
operator|=
operator|-
literal|1
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|residue
operator|>
literal|0
condition|)
name|bump
operator|=
literal|1
expr_stmt|;
block|}
break|break;
block|}
comment|/* r-f */
default|default:
block|{
comment|/* e.g., DEC_ROUND_MAX */
operator|*
name|status
operator||=
name|DEC_Invalid_context
expr_stmt|;
if|#
directive|if
name|DECTRACE
name|printf
argument_list|(
literal|"Unknown rounding mode: %d\n"
argument_list|,
name|set
operator|->
name|round
argument_list|)
expr_stmt|;
endif|#
directive|endif
break|break;
block|}
block|}
comment|/* switch */
comment|/* now bump the number, up or down, if need be */
if|if
condition|(
name|bump
operator|==
literal|0
condition|)
return|return;
comment|/* no action required */
comment|/* Simply use decUnitAddSub unless we are bumping up and the number */
comment|/* is all nines.  In this special case we set to 1000... and adjust */
comment|/* the exponent by one (as otherwise we could overflow the array) */
comment|/* Similarly handle all-nines result if bumping down. */
if|if
condition|(
name|bump
operator|>
literal|0
condition|)
block|{
name|Unit
modifier|*
name|up
decl_stmt|;
comment|/* work */
name|uInt
name|count
init|=
name|dn
operator|->
name|digits
decl_stmt|;
comment|/* digits to be checked */
for|for
control|(
name|up
operator|=
name|dn
operator|->
name|lsu
init|;
condition|;
name|up
operator|++
control|)
block|{
if|if
condition|(
name|count
operator|<=
name|DECDPUN
condition|)
block|{
comment|/* this is the last Unit (the msu) */
if|if
condition|(
operator|*
name|up
operator|!=
name|powers
index|[
name|count
index|]
operator|-
literal|1
condition|)
break|break;
comment|/* not still 9s */
comment|/* here if it, too, is all nines */
operator|*
name|up
operator|=
operator|(
name|Unit
operator|)
name|powers
index|[
name|count
operator|-
literal|1
index|]
expr_stmt|;
comment|/* here 999 -> 100 etc. */
for|for
control|(
name|up
operator|=
name|up
operator|-
literal|1
init|;
name|up
operator|>=
name|dn
operator|->
name|lsu
condition|;
name|up
operator|--
control|)
operator|*
name|up
operator|=
literal|0
expr_stmt|;
comment|/* others all to 0 */
name|dn
operator|->
name|exponent
operator|++
expr_stmt|;
comment|/* and bump exponent */
comment|/* [which, very rarely, could cause Overflow...] */
if|if
condition|(
operator|(
name|dn
operator|->
name|exponent
operator|+
name|dn
operator|->
name|digits
operator|)
operator|>
name|set
operator|->
name|emax
operator|+
literal|1
condition|)
block|{
name|decSetOverflow
argument_list|(
name|dn
argument_list|,
name|set
argument_list|,
name|status
argument_list|)
expr_stmt|;
block|}
return|return;
comment|/* done */
block|}
comment|/* a full unit to check, with more to come */
if|if
condition|(
operator|*
name|up
operator|!=
name|DECDPUNMAX
condition|)
break|break;
comment|/* not still 9s */
name|count
operator|-=
name|DECDPUN
expr_stmt|;
block|}
comment|/* up */
block|}
comment|/* bump>0 */
else|else
block|{
comment|/* -1 */
comment|/* here we are lookng for a pre-bump of 1000... (leading 1, */
comment|/* all other digits zero) */
name|Unit
modifier|*
name|up
decl_stmt|,
modifier|*
name|sup
decl_stmt|;
comment|/* work */
name|uInt
name|count
init|=
name|dn
operator|->
name|digits
decl_stmt|;
comment|/* digits to be checked */
for|for
control|(
name|up
operator|=
name|dn
operator|->
name|lsu
init|;
condition|;
name|up
operator|++
control|)
block|{
if|if
condition|(
name|count
operator|<=
name|DECDPUN
condition|)
block|{
comment|/* this is the last Unit (the msu) */
if|if
condition|(
operator|*
name|up
operator|!=
name|powers
index|[
name|count
operator|-
literal|1
index|]
condition|)
break|break;
comment|/* not 100.. */
comment|/* here if we have the 1000... case */
name|sup
operator|=
name|up
expr_stmt|;
comment|/* save msu pointer */
operator|*
name|up
operator|=
operator|(
name|Unit
operator|)
name|powers
index|[
name|count
index|]
operator|-
literal|1
expr_stmt|;
comment|/* here 100 in msu -> 999 */
comment|/* others all to all-nines, too */
for|for
control|(
name|up
operator|=
name|up
operator|-
literal|1
init|;
name|up
operator|>=
name|dn
operator|->
name|lsu
condition|;
name|up
operator|--
control|)
operator|*
name|up
operator|=
operator|(
name|Unit
operator|)
name|powers
index|[
name|DECDPUN
index|]
operator|-
literal|1
expr_stmt|;
name|dn
operator|->
name|exponent
operator|--
expr_stmt|;
comment|/* and bump exponent */
comment|/* iff the number was at the subnormal boundary (exponent=etiny) */
comment|/* then the exponent is now out of range, so it will in fact get */
comment|/* clamped to etiny and the final 9 dropped. */
comment|/* printf(">> emin=%d exp=%d sdig=%d\n", set->emin, */
comment|/*        dn->exponent, set->digits); */
if|if
condition|(
name|dn
operator|->
name|exponent
operator|+
literal|1
operator|==
name|set
operator|->
name|emin
operator|-
name|set
operator|->
name|digits
operator|+
literal|1
condition|)
block|{
if|if
condition|(
name|count
operator|==
literal|1
operator|&&
name|dn
operator|->
name|digits
operator|==
literal|1
condition|)
operator|*
name|sup
operator|=
literal|0
expr_stmt|;
comment|/* here 9 -> 0[.9] */
else|else
block|{
operator|*
name|sup
operator|=
operator|(
name|Unit
operator|)
name|powers
index|[
name|count
operator|-
literal|1
index|]
operator|-
literal|1
expr_stmt|;
comment|/* here 999.. in msu -> 99.. */
name|dn
operator|->
name|digits
operator|--
expr_stmt|;
block|}
name|dn
operator|->
name|exponent
operator|++
expr_stmt|;
operator|*
name|status
operator||=
name|DEC_Underflow
operator||
name|DEC_Subnormal
operator||
name|DEC_Inexact
operator||
name|DEC_Rounded
expr_stmt|;
block|}
return|return;
comment|/* done */
block|}
comment|/* a full unit to check, with more to come */
if|if
condition|(
operator|*
name|up
operator|!=
literal|0
condition|)
break|break;
comment|/* not still 0s */
name|count
operator|-=
name|DECDPUN
expr_stmt|;
block|}
comment|/* up */
block|}
comment|/* bump<0 */
comment|/* Actual bump needed.  Do it. */
name|decUnitAddSub
argument_list|(
name|dn
operator|->
name|lsu
argument_list|,
name|D2U
argument_list|(
name|dn
operator|->
name|digits
argument_list|)
argument_list|,
name|one
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
name|dn
operator|->
name|lsu
argument_list|,
name|bump
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
name|DECSUBSET
end_if

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decFinish -- finish processing a number                            */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   dn is the number                                                 */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*   residue is the rounding accumulator (as in decApplyRound)        */
end_comment

begin_comment
comment|/*   status is the accumulator                                        */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* This finishes off the current number by:                           */
end_comment

begin_comment
comment|/*    1. If not extended:                                             */
end_comment

begin_comment
comment|/*       a. Converting a zero result to clean '0'                     */
end_comment

begin_comment
comment|/*       b. Reducing positive exponents to 0, if would fit in digits  */
end_comment

begin_comment
comment|/*    2. Checking for overflow and subnormals (always)                */
end_comment

begin_comment
comment|/* Note this is just Finalize when no subset arithmetic.              */
end_comment

begin_comment
comment|/* All fields are updated as required.                                */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|void
name|decFinish
parameter_list|(
name|decNumber
modifier|*
name|dn
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|,
name|Int
modifier|*
name|residue
parameter_list|,
name|uInt
modifier|*
name|status
parameter_list|)
block|{
if|if
condition|(
operator|!
name|set
operator|->
name|extended
condition|)
block|{
if|if ISZERO
condition|(
name|dn
condition|)
block|{
comment|/* value is zero */
name|dn
operator|->
name|exponent
operator|=
literal|0
expr_stmt|;
comment|/* clean exponent .. */
name|dn
operator|->
name|bits
operator|=
literal|0
expr_stmt|;
comment|/* .. and sign */
return|return;
comment|/* no error possible */
block|}
if|if
condition|(
name|dn
operator|->
name|exponent
operator|>=
literal|0
condition|)
block|{
comment|/* non-negative exponent */
comment|/*>0; reduce to integer if possible */
if|if
condition|(
name|set
operator|->
name|digits
operator|>=
operator|(
name|dn
operator|->
name|exponent
operator|+
name|dn
operator|->
name|digits
operator|)
condition|)
block|{
name|dn
operator|->
name|digits
operator|=
name|decShiftToMost
argument_list|(
name|dn
operator|->
name|lsu
argument_list|,
name|dn
operator|->
name|digits
argument_list|,
name|dn
operator|->
name|exponent
argument_list|)
expr_stmt|;
name|dn
operator|->
name|exponent
operator|=
literal|0
expr_stmt|;
block|}
block|}
block|}
comment|/* !extended */
name|decFinalize
argument_list|(
name|dn
argument_list|,
name|set
argument_list|,
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decFinalize -- final check, clamp, and round of a number           */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   dn is the number                                                 */
end_comment

begin_comment
comment|/*   set is the context                                               */
end_comment

begin_comment
comment|/*   residue is the rounding accumulator (as in decApplyRound)        */
end_comment

begin_comment
comment|/*   status is the status accumulator                                 */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* This finishes off the current number by checking for subnormal     */
end_comment

begin_comment
comment|/* results, applying any pending rounding, checking for overflow,     */
end_comment

begin_comment
comment|/* and applying any clamping.                                         */
end_comment

begin_comment
comment|/* Underflow and overflow conditions are raised as appropriate.       */
end_comment

begin_comment
comment|/* All fields are updated as required.                                */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|void
name|decFinalize
parameter_list|(
name|decNumber
modifier|*
name|dn
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|,
name|Int
modifier|*
name|residue
parameter_list|,
name|uInt
modifier|*
name|status
parameter_list|)
block|{
name|Int
name|shift
decl_stmt|;
comment|/* shift needed if clamping */
comment|/* We have to be careful when checking the exponent as the adjusted */
comment|/* exponent could overflow 31 bits [because it may already be up */
comment|/* to twice the expected]. */
comment|/* First test for subnormal.  This must be done before any final */
comment|/* round as the result could be rounded to Nmin or 0. */
if|if
condition|(
name|dn
operator|->
name|exponent
operator|<
literal|0
comment|/* negative exponent */
operator|&&
operator|(
name|dn
operator|->
name|exponent
operator|<
name|set
operator|->
name|emin
operator|-
name|dn
operator|->
name|digits
operator|+
literal|1
operator|)
condition|)
block|{
comment|/* Go handle subnormals; this will apply round if needed. */
name|decSetSubnormal
argument_list|(
name|dn
argument_list|,
name|set
argument_list|,
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* now apply any pending round (this could raise overflow). */
if|if
condition|(
operator|*
name|residue
operator|!=
literal|0
condition|)
name|decApplyRound
argument_list|(
name|dn
argument_list|,
name|set
argument_list|,
operator|*
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
comment|/* Check for overflow [redundant in the 'rare' case] or clamp */
if|if
condition|(
name|dn
operator|->
name|exponent
operator|<=
name|set
operator|->
name|emax
operator|-
name|set
operator|->
name|digits
operator|+
literal|1
condition|)
return|return;
comment|/* neither needed */
comment|/* here when we might have an overflow or clamp to do */
if|if
condition|(
name|dn
operator|->
name|exponent
operator|>
name|set
operator|->
name|emax
operator|-
name|dn
operator|->
name|digits
operator|+
literal|1
condition|)
block|{
comment|/* too big */
name|decSetOverflow
argument_list|(
name|dn
argument_list|,
name|set
argument_list|,
name|status
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* here when the result is normal but in clamp range */
if|if
condition|(
operator|!
name|set
operator|->
name|clamp
condition|)
return|return;
comment|/* here when we need to apply the IEEE exponent clamp (fold-down) */
name|shift
operator|=
name|dn
operator|->
name|exponent
operator|-
operator|(
name|set
operator|->
name|emax
operator|-
name|set
operator|->
name|digits
operator|+
literal|1
operator|)
expr_stmt|;
comment|/* shift coefficient (if non-zero) */
if|if
condition|(
operator|!
name|ISZERO
argument_list|(
name|dn
argument_list|)
condition|)
block|{
name|dn
operator|->
name|digits
operator|=
name|decShiftToMost
argument_list|(
name|dn
operator|->
name|lsu
argument_list|,
name|dn
operator|->
name|digits
argument_list|,
name|shift
argument_list|)
expr_stmt|;
block|}
name|dn
operator|->
name|exponent
operator|-=
name|shift
expr_stmt|;
comment|/* adjust the exponent to match */
operator|*
name|status
operator||=
name|DEC_Clamped
expr_stmt|;
comment|/* and record the dirty deed */
return|return;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decSetOverflow -- set number to proper overflow value              */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   dn is the number (used for sign [only] and result)               */
end_comment

begin_comment
comment|/*   set is the context [used for the rounding mode]                  */
end_comment

begin_comment
comment|/*   status contains the current status to be updated                 */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* This sets the sign of a number and sets its value to either        */
end_comment

begin_comment
comment|/* Infinity or the maximum finite value, depending on the sign of     */
end_comment

begin_comment
comment|/* dn and therounding mode, following IEEE 854 rules.                 */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|void
name|decSetOverflow
parameter_list|(
name|decNumber
modifier|*
name|dn
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|,
name|uInt
modifier|*
name|status
parameter_list|)
block|{
name|Flag
name|needmax
init|=
literal|0
decl_stmt|;
comment|/* result is maximum finite value */
name|uByte
name|sign
init|=
name|dn
operator|->
name|bits
operator|&
name|DECNEG
decl_stmt|;
comment|/* clean and save sign bit */
if|if
condition|(
name|ISZERO
argument_list|(
name|dn
argument_list|)
condition|)
block|{
comment|/* zero does not overflow magnitude */
name|Int
name|emax
init|=
name|set
operator|->
name|emax
decl_stmt|;
comment|/* limit value */
if|if
condition|(
name|set
operator|->
name|clamp
condition|)
name|emax
operator|-=
name|set
operator|->
name|digits
operator|-
literal|1
expr_stmt|;
comment|/* lower if clamping */
if|if
condition|(
name|dn
operator|->
name|exponent
operator|>
name|emax
condition|)
block|{
comment|/* clamp required */
name|dn
operator|->
name|exponent
operator|=
name|emax
expr_stmt|;
operator|*
name|status
operator||=
name|DEC_Clamped
expr_stmt|;
block|}
return|return;
block|}
name|decNumberZero
argument_list|(
name|dn
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|set
operator|->
name|round
condition|)
block|{
case|case
name|DEC_ROUND_DOWN
case|:
block|{
name|needmax
operator|=
literal|1
expr_stmt|;
comment|/* never Infinity */
break|break;
block|}
comment|/* r-d */
case|case
name|DEC_ROUND_CEILING
case|:
block|{
if|if
condition|(
name|sign
condition|)
name|needmax
operator|=
literal|1
expr_stmt|;
comment|/* Infinity if non-negative */
break|break;
block|}
comment|/* r-c */
case|case
name|DEC_ROUND_FLOOR
case|:
block|{
if|if
condition|(
operator|!
name|sign
condition|)
name|needmax
operator|=
literal|1
expr_stmt|;
comment|/* Infinity if negative */
break|break;
block|}
comment|/* r-f */
default|default:
break|break;
comment|/* Infinity in all other cases */
block|}
if|if
condition|(
name|needmax
condition|)
block|{
name|Unit
modifier|*
name|up
decl_stmt|;
comment|/* work */
name|Int
name|count
init|=
name|set
operator|->
name|digits
decl_stmt|;
comment|/* nines to add */
name|dn
operator|->
name|digits
operator|=
name|count
expr_stmt|;
comment|/* fill in all nines to set maximum value */
for|for
control|(
name|up
operator|=
name|dn
operator|->
name|lsu
init|;
condition|;
name|up
operator|++
control|)
block|{
if|if
condition|(
name|count
operator|>
name|DECDPUN
condition|)
operator|*
name|up
operator|=
name|DECDPUNMAX
expr_stmt|;
comment|/* unit full o'nines */
else|else
block|{
comment|/* this is the msu */
operator|*
name|up
operator|=
call|(
name|Unit
call|)
argument_list|(
name|powers
index|[
name|count
index|]
operator|-
literal|1
argument_list|)
expr_stmt|;
break|break;
block|}
name|count
operator|-=
name|DECDPUN
expr_stmt|;
comment|/* we filled those digits */
block|}
comment|/* up */
name|dn
operator|->
name|bits
operator|=
name|sign
expr_stmt|;
comment|/* sign */
name|dn
operator|->
name|exponent
operator|=
name|set
operator|->
name|emax
operator|-
name|set
operator|->
name|digits
operator|+
literal|1
expr_stmt|;
block|}
else|else
name|dn
operator|->
name|bits
operator|=
name|sign
operator||
name|DECINF
expr_stmt|;
comment|/* Value is +/-Infinity */
operator|*
name|status
operator||=
name|DEC_Overflow
operator||
name|DEC_Inexact
operator||
name|DEC_Rounded
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decSetSubnormal -- process value whose exponent is<Emin           */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   dn is the number (used as input as well as output; it may have   */
end_comment

begin_comment
comment|/*         an allowed subnormal value, which may need to be rounded)  */
end_comment

begin_comment
comment|/*   set is the context [used for the rounding mode]                  */
end_comment

begin_comment
comment|/*   residue is any pending residue                                   */
end_comment

begin_comment
comment|/*   status contains the current status to be updated                 */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* If subset mode, set result to zero and set Underflow flags.        */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* Value may be zero with a low exponent; this does not set Subnormal */
end_comment

begin_comment
comment|/* but the exponent will be clamped to Etiny.                         */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* Otherwise ensure exponent is not out of range, and round as        */
end_comment

begin_comment
comment|/* necessary.  Underflow is set if the result is Inexact.             */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|void
name|decSetSubnormal
parameter_list|(
name|decNumber
modifier|*
name|dn
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|,
name|Int
modifier|*
name|residue
parameter_list|,
name|uInt
modifier|*
name|status
parameter_list|)
block|{
name|decContext
name|workset
decl_stmt|;
comment|/* work */
name|Int
name|etiny
decl_stmt|,
name|adjust
decl_stmt|;
comment|/* .. */
if|#
directive|if
name|DECSUBSET
comment|/* simple set to zero and 'hard underflow' for subset */
if|if
condition|(
operator|!
name|set
operator|->
name|extended
condition|)
block|{
name|decNumberZero
argument_list|(
name|dn
argument_list|)
expr_stmt|;
comment|/* always full overflow */
operator|*
name|status
operator||=
name|DEC_Underflow
operator||
name|DEC_Subnormal
operator||
name|DEC_Inexact
operator||
name|DEC_Rounded
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
comment|/* Full arithmetic -- allow subnormals, rounded to minimum exponent */
comment|/* (Etiny) if needed */
name|etiny
operator|=
name|set
operator|->
name|emin
operator|-
operator|(
name|set
operator|->
name|digits
operator|-
literal|1
operator|)
expr_stmt|;
comment|/* smallest allowed exponent */
if|if ISZERO
condition|(
name|dn
condition|)
block|{
comment|/* value is zero */
comment|/* residue can never be non-zero here */
if|#
directive|if
name|DECCHECK
if|if
condition|(
operator|*
name|residue
operator|!=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"++ Subnormal 0 residue %d\n"
argument_list|,
operator|*
name|residue
argument_list|)
expr_stmt|;
operator|*
name|status
operator||=
name|DEC_Invalid_operation
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|dn
operator|->
name|exponent
operator|<
name|etiny
condition|)
block|{
comment|/* clamp required */
name|dn
operator|->
name|exponent
operator|=
name|etiny
expr_stmt|;
operator|*
name|status
operator||=
name|DEC_Clamped
expr_stmt|;
block|}
return|return;
block|}
operator|*
name|status
operator||=
name|DEC_Subnormal
expr_stmt|;
comment|/* we have a non-zero subnormal */
name|adjust
operator|=
name|etiny
operator|-
name|dn
operator|->
name|exponent
expr_stmt|;
comment|/* calculate digits to remove */
if|if
condition|(
name|adjust
operator|<=
literal|0
condition|)
block|{
comment|/* not out of range; unrounded */
comment|/* residue can never be non-zero here, so fast-path out */
if|#
directive|if
name|DECCHECK
if|if
condition|(
operator|*
name|residue
operator|!=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"++ Subnormal no-adjust residue %d\n"
argument_list|,
operator|*
name|residue
argument_list|)
expr_stmt|;
operator|*
name|status
operator||=
name|DEC_Invalid_operation
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* it may already be inexact (from setting the coefficient) */
if|if
condition|(
operator|*
name|status
operator|&
name|DEC_Inexact
condition|)
operator|*
name|status
operator||=
name|DEC_Underflow
expr_stmt|;
return|return;
block|}
comment|/* adjust>0.  we need to rescale the result so exponent becomes Etiny */
comment|/* [this code is similar to that in rescale] */
name|workset
operator|=
operator|*
name|set
expr_stmt|;
comment|/* clone rounding, etc. */
name|workset
operator|.
name|digits
operator|=
name|dn
operator|->
name|digits
operator|-
name|adjust
expr_stmt|;
comment|/* set requested length */
name|workset
operator|.
name|emin
operator|-=
name|adjust
expr_stmt|;
comment|/* and adjust emin to match */
comment|/* [note that the latter can be<1, here, similar to Rescale case] */
name|decSetCoeff
argument_list|(
name|dn
argument_list|,
operator|&
name|workset
argument_list|,
name|dn
operator|->
name|lsu
argument_list|,
name|dn
operator|->
name|digits
argument_list|,
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
name|decApplyRound
argument_list|(
name|dn
argument_list|,
operator|&
name|workset
argument_list|,
operator|*
name|residue
argument_list|,
name|status
argument_list|)
expr_stmt|;
comment|/* Use 754R/854 default rule: Underflow is set iff Inexact */
comment|/* [independent of whether trapped] */
if|if
condition|(
operator|*
name|status
operator|&
name|DEC_Inexact
condition|)
operator|*
name|status
operator||=
name|DEC_Underflow
expr_stmt|;
comment|/* if we rounded up a 999s case, exponent will be off by one; adjust */
comment|/* back if so [it will fit, because we shortened] */
if|if
condition|(
name|dn
operator|->
name|exponent
operator|>
name|etiny
condition|)
block|{
name|dn
operator|->
name|digits
operator|=
name|decShiftToMost
argument_list|(
name|dn
operator|->
name|lsu
argument_list|,
name|dn
operator|->
name|digits
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|dn
operator|->
name|exponent
operator|--
expr_stmt|;
comment|/* (re)adjust the exponent. */
block|}
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decGetInt -- get integer from a number                             */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   dn is the number [which will not be altered]                     */
end_comment

begin_comment
comment|/*   set is the context [requested digits], subset only               */
end_comment

begin_comment
comment|/*   returns the converted integer, or BADINT if error                */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* This checks and gets a whole number from the input decNumber.      */
end_comment

begin_comment
comment|/* The magnitude of the integer must be<2^31.                        */
end_comment

begin_comment
comment|/* Any discarded fractional part must be 0.                           */
end_comment

begin_comment
comment|/* If subset it must also fit in set->digits                          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_if
if|#
directive|if
name|DECSUBSET
end_if

begin_function
specifier|static
name|Int
name|decGetInt
parameter_list|(
specifier|const
name|decNumber
modifier|*
name|dn
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
else|#
directive|else
specifier|static
name|Int
name|decGetInt
parameter_list|(
specifier|const
name|decNumber
modifier|*
name|dn
parameter_list|)
block|{
endif|#
directive|endif
name|Int
name|theInt
decl_stmt|;
comment|/* result accumulator */
specifier|const
name|Unit
modifier|*
name|up
decl_stmt|;
comment|/* work */
name|Int
name|got
decl_stmt|;
comment|/* digits (real or not) processed */
name|Int
name|ilength
init|=
name|dn
operator|->
name|digits
operator|+
name|dn
operator|->
name|exponent
decl_stmt|;
comment|/* integral length */
comment|/* The number must be an integer that fits in 10 digits */
comment|/* Assert, here, that 10 is enough for any rescale Etiny */
if|#
directive|if
name|DEC_MAX_EMAX
operator|>
literal|999999999
error|#
directive|error
error|GetInt may need updating [for Emax]
endif|#
directive|endif
if|#
directive|if
name|DEC_MIN_EMIN
operator|<
operator|-
literal|999999999
error|#
directive|error
error|GetInt may need updating [for Emin]
endif|#
directive|endif
if|if
condition|(
name|ISZERO
argument_list|(
name|dn
argument_list|)
condition|)
return|return
literal|0
return|;
comment|/* zeros are OK, with any exponent */
if|if
condition|(
name|ilength
operator|>
literal|10
condition|)
return|return
name|BADINT
return|;
comment|/* always too big */
if|#
directive|if
name|DECSUBSET
if|if
condition|(
operator|!
name|set
operator|->
name|extended
operator|&&
name|ilength
operator|>
name|set
operator|->
name|digits
condition|)
return|return
name|BADINT
return|;
endif|#
directive|endif
name|up
operator|=
name|dn
operator|->
name|lsu
expr_stmt|;
comment|/* ready for lsu */
name|theInt
operator|=
literal|0
expr_stmt|;
comment|/* ready to accumulate */
if|if
condition|(
name|dn
operator|->
name|exponent
operator|>=
literal|0
condition|)
block|{
comment|/* relatively easy */
comment|/* no fractional part [usual]; allow for positive exponent */
name|got
operator|=
name|dn
operator|->
name|exponent
expr_stmt|;
block|}
else|else
block|{
comment|/* -ve exponent; some fractional part to check and discard */
name|Int
name|count
init|=
operator|-
name|dn
operator|->
name|exponent
decl_stmt|;
comment|/* digits to discard */
comment|/* spin up whole units until we get to the Unit with the unit digit */
for|for
control|(
init|;
name|count
operator|>=
name|DECDPUN
condition|;
name|up
operator|++
control|)
block|{
if|if
condition|(
operator|*
name|up
operator|!=
literal|0
condition|)
return|return
name|BADINT
return|;
comment|/* non-zero Unit to discard */
name|count
operator|-=
name|DECDPUN
expr_stmt|;
block|}
if|if
condition|(
name|count
operator|==
literal|0
condition|)
name|got
operator|=
literal|0
expr_stmt|;
comment|/* [a multiple of DECDPUN] */
else|else
block|{
comment|/* [not multiple of DECDPUN] */
name|Int
name|rem
decl_stmt|;
comment|/* work */
comment|/* slice off fraction digits and check for non-zero */
if|#
directive|if
name|DECDPUN
operator|<=
literal|4
name|theInt
operator|=
name|QUOT10
argument_list|(
operator|*
name|up
argument_list|,
name|count
argument_list|)
expr_stmt|;
name|rem
operator|=
operator|*
name|up
operator|-
name|theInt
operator|*
name|powers
index|[
name|count
index|]
expr_stmt|;
else|#
directive|else
name|rem
operator|=
operator|*
name|up
operator|%
name|powers
index|[
name|count
index|]
expr_stmt|;
comment|/* slice off discards */
name|theInt
operator|=
operator|*
name|up
operator|/
name|powers
index|[
name|count
index|]
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|rem
operator|!=
literal|0
condition|)
return|return
name|BADINT
return|;
comment|/* non-zero fraction */
comment|/* OK, we're good */
name|got
operator|=
name|DECDPUN
operator|-
name|count
expr_stmt|;
comment|/* number of digits so far */
name|up
operator|++
expr_stmt|;
comment|/* ready for next */
block|}
block|}
comment|/* collect the rest */
for|for
control|(
init|;
name|got
operator|<
name|ilength
condition|;
name|up
operator|++
control|)
block|{
name|theInt
operator|+=
operator|*
name|up
operator|*
name|powers
index|[
name|got
index|]
expr_stmt|;
name|got
operator|+=
name|DECDPUN
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|ilength
operator|==
literal|10
operator|)
comment|/* check no wrap */
operator|&&
operator|(
name|theInt
operator|/
operator|(
name|Int
operator|)
name|powers
index|[
name|got
operator|-
name|DECDPUN
index|]
operator|!=
operator|*
operator|(
name|up
operator|-
literal|1
operator|)
operator|)
condition|)
return|return
name|BADINT
return|;
comment|/* [that test also disallows the BADINT result case] */
comment|/* apply any sign and return */
if|if
condition|(
name|decNumberIsNegative
argument_list|(
name|dn
argument_list|)
condition|)
name|theInt
operator|=
operator|-
name|theInt
expr_stmt|;
return|return
name|theInt
return|;
block|}
comment|/* ------------------------------------------------------------------ */
comment|/* decStrEq -- caseless comparison of strings                         */
comment|/*                                                                    */
comment|/*   str1 is one of the strings to compare                            */
comment|/*   str2 is the other                                                */
comment|/*                                                                    */
comment|/*   returns 1 if strings caseless-compare equal, 0 otherwise         */
comment|/*                                                                    */
comment|/* Note that the strings must be the same length if they are to       */
comment|/* compare equal; there is no padding.                                */
comment|/* ------------------------------------------------------------------ */
comment|/* [strcmpi is not in ANSI C] */
specifier|static
name|Flag
name|decStrEq
parameter_list|(
specifier|const
name|char
modifier|*
name|str1
parameter_list|,
specifier|const
name|char
modifier|*
name|str2
parameter_list|)
block|{
for|for
control|(
init|;
condition|;
name|str1
operator|++
operator|,
name|str2
operator|++
control|)
block|{
name|unsigned
name|char
name|u1
init|=
operator|(
name|unsigned
name|char
operator|)
operator|*
name|str1
decl_stmt|;
name|unsigned
name|char
name|u2
init|=
operator|(
name|unsigned
name|char
operator|)
operator|*
name|str2
decl_stmt|;
if|if
condition|(
name|u1
operator|==
name|u2
condition|)
block|{
if|if
condition|(
name|u1
operator|==
literal|'\0'
condition|)
break|break;
block|}
else|else
block|{
if|if
condition|(
name|tolower
argument_list|(
name|u1
argument_list|)
operator|!=
name|tolower
argument_list|(
name|u2
argument_list|)
condition|)
return|return
literal|0
return|;
block|}
block|}
comment|/* stepping */
return|return
literal|1
return|;
block|}
comment|/* ------------------------------------------------------------------ */
comment|/* decNaNs -- handle NaN operand or operands                          */
comment|/*                                                                    */
comment|/*   res    is the result number                                      */
comment|/*   lhs    is the first operand                                      */
comment|/*   rhs    is the second operand, or NULL if none                    */
comment|/*   status contains the current status                               */
comment|/*   returns res in case convenient                                   */
comment|/*                                                                    */
comment|/* Called when one or both operands is a NaN, and propagates the      */
comment|/* appropriate result to res.  When an sNaN is found, it is changed   */
comment|/* to a qNaN and Invalid operation is set.                            */
comment|/* ------------------------------------------------------------------ */
specifier|static
name|decNumber
modifier|*
name|decNaNs
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|uInt
modifier|*
name|status
parameter_list|)
block|{
comment|/* This decision tree ends up with LHS being the source pointer, */
comment|/* and status updated if need be */
if|if
condition|(
name|lhs
operator|->
name|bits
operator|&
name|DECSNAN
condition|)
operator|*
name|status
operator||=
name|DEC_Invalid_operation
operator||
name|DEC_sNaN
expr_stmt|;
elseif|else
if|if
condition|(
name|rhs
operator|==
name|NULL
condition|)
empty_stmt|;
elseif|else
if|if
condition|(
name|rhs
operator|->
name|bits
operator|&
name|DECSNAN
condition|)
block|{
name|lhs
operator|=
name|rhs
expr_stmt|;
operator|*
name|status
operator||=
name|DEC_Invalid_operation
operator||
name|DEC_sNaN
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|lhs
operator|->
name|bits
operator|&
name|DECNAN
condition|)
empty_stmt|;
else|else
name|lhs
operator|=
name|rhs
expr_stmt|;
name|decNumberCopy
argument_list|(
name|res
argument_list|,
name|lhs
argument_list|)
expr_stmt|;
name|res
operator|->
name|bits
operator|&=
operator|~
name|DECSNAN
expr_stmt|;
comment|/* convert any sNaN to NaN, while */
name|res
operator|->
name|bits
operator||=
name|DECNAN
expr_stmt|;
comment|/* .. preserving sign */
name|res
operator|->
name|exponent
operator|=
literal|0
expr_stmt|;
comment|/* clean exponent */
comment|/* [coefficient was copied] */
return|return
name|res
return|;
block|}
comment|/* ------------------------------------------------------------------ */
comment|/* decStatus -- apply non-zero status                                 */
comment|/*                                                                    */
comment|/*   dn     is the number to set if error                             */
comment|/*   status contains the current status (not yet in context)          */
comment|/*   set    is the context                                            */
comment|/*                                                                    */
comment|/* If the status is an error status, the number is set to a NaN,      */
comment|/* unless the error was an overflow, divide-by-zero, or underflow,    */
comment|/* in which case the number will have already been set.               */
comment|/*                                                                    */
comment|/* The context status is then updated with the new status.  Note that */
comment|/* this may raise a signal, so control may never return from this     */
comment|/* routine (hence resources must be recovered before it is called).   */
comment|/* ------------------------------------------------------------------ */
specifier|static
name|void
name|decStatus
parameter_list|(
name|decNumber
modifier|*
name|dn
parameter_list|,
name|uInt
name|status
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
if|if
condition|(
name|status
operator|&
name|DEC_NaNs
condition|)
block|{
comment|/* error status -> NaN */
comment|/* if cause was an sNaN, clear and propagate [NaN is already set up] */
if|if
condition|(
name|status
operator|&
name|DEC_sNaN
condition|)
name|status
operator|&=
operator|~
name|DEC_sNaN
expr_stmt|;
else|else
block|{
name|decNumberZero
argument_list|(
name|dn
argument_list|)
expr_stmt|;
comment|/* other error: clean throughout */
name|dn
operator|->
name|bits
operator|=
name|DECNAN
expr_stmt|;
comment|/* and make a quiet NaN */
block|}
block|}
name|decContextSetStatus
argument_list|(
name|set
argument_list|,
name|status
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* ------------------------------------------------------------------ */
comment|/* decGetDigits -- count digits in a Units array                      */
comment|/*                                                                    */
comment|/*   uar is the Unit array holding the number [this is often an       */
comment|/*          accumulator of some sort]                                 */
comment|/*   len is the length of the array in units                          */
comment|/*                                                                    */
comment|/*   returns the number of (significant) digits in the array          */
comment|/*                                                                    */
comment|/* All leading zeros are excluded, except the last if the array has   */
comment|/* only zero Units.                                                   */
comment|/* ------------------------------------------------------------------ */
comment|/* This may be called twice during some operations. */
specifier|static
name|Int
name|decGetDigits
parameter_list|(
specifier|const
name|Unit
modifier|*
name|uar
parameter_list|,
name|Int
name|len
parameter_list|)
block|{
specifier|const
name|Unit
modifier|*
name|up
init|=
name|uar
operator|+
name|len
operator|-
literal|1
decl_stmt|;
comment|/* -> msu */
name|Int
name|digits
init|=
name|len
operator|*
name|DECDPUN
decl_stmt|;
comment|/* maximum possible digits */
name|uInt
specifier|const
modifier|*
name|pow
decl_stmt|;
comment|/* work */
for|for
control|(
init|;
name|up
operator|>=
name|uar
condition|;
name|up
operator|--
control|)
block|{
name|digits
operator|-=
name|DECDPUN
expr_stmt|;
if|if
condition|(
operator|*
name|up
operator|==
literal|0
condition|)
block|{
comment|/* unit is 0 */
if|if
condition|(
name|digits
operator|!=
literal|0
condition|)
continue|continue;
comment|/* more to check */
comment|/* all units were 0 */
name|digits
operator|++
expr_stmt|;
comment|/* .. so bump digits to 1 */
break|break;
block|}
comment|/* found the first non-zero Unit */
name|digits
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|up
operator|<
literal|10
condition|)
break|break;
comment|/* fastpath 1-9 */
name|digits
operator|++
expr_stmt|;
for|for
control|(
name|pow
operator|=
operator|&
name|powers
index|[
literal|2
index|]
init|;
operator|*
name|up
operator|>=
operator|*
name|pow
condition|;
name|pow
operator|++
control|)
name|digits
operator|++
expr_stmt|;
break|break;
block|}
comment|/* up */
return|return
name|digits
return|;
block|}
if|#
directive|if
name|DECTRACE
operator||
name|DECCHECK
comment|/* ------------------------------------------------------------------ */
comment|/* decNumberShow -- display a number [debug aid]                      */
comment|/*   dn is the number to show                                         */
comment|/*                                                                    */
comment|/* Shows: sign, exponent, coefficient (msu first), digits             */
comment|/*    or: sign, special-value                                         */
comment|/* ------------------------------------------------------------------ */
comment|/* this is public so other modules can use it */
name|void
name|decNumberShow
parameter_list|(
specifier|const
name|decNumber
modifier|*
name|dn
parameter_list|)
block|{
specifier|const
name|Unit
modifier|*
name|up
decl_stmt|;
comment|/* work */
name|uInt
name|u
decl_stmt|,
name|d
decl_stmt|;
comment|/* .. */
name|Int
name|cut
decl_stmt|;
comment|/* .. */
name|char
name|isign
init|=
literal|'+'
decl_stmt|;
comment|/* main sign */
if|if
condition|(
name|dn
operator|==
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"NULL\n"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|decNumberIsNegative
argument_list|(
name|dn
argument_list|)
condition|)
name|isign
operator|=
literal|'-'
expr_stmt|;
name|printf
argument_list|(
literal|">> %c "
argument_list|,
name|isign
argument_list|)
expr_stmt|;
if|if
condition|(
name|dn
operator|->
name|bits
operator|&
name|DECSPECIAL
condition|)
block|{
comment|/* Is a special value */
if|if
condition|(
name|decNumberIsInfinite
argument_list|(
name|dn
argument_list|)
condition|)
name|printf
argument_list|(
literal|"Infinity"
argument_list|)
expr_stmt|;
else|else
block|{
comment|/* a NaN */
if|if
condition|(
name|dn
operator|->
name|bits
operator|&
name|DECSNAN
condition|)
name|printf
argument_list|(
literal|"sNaN"
argument_list|)
expr_stmt|;
comment|/* signalling NaN */
else|else
name|printf
argument_list|(
literal|"NaN"
argument_list|)
expr_stmt|;
block|}
comment|/* if coefficient and exponent are 0, we're done */
if|if
condition|(
name|dn
operator|->
name|exponent
operator|==
literal|0
operator|&&
name|dn
operator|->
name|digits
operator|==
literal|1
operator|&&
operator|*
name|dn
operator|->
name|lsu
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* drop through to report other information */
name|printf
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
block|}
comment|/* now carefully display the coefficient */
name|up
operator|=
name|dn
operator|->
name|lsu
operator|+
name|D2U
argument_list|(
name|dn
operator|->
name|digits
argument_list|)
operator|-
literal|1
expr_stmt|;
comment|/* msu */
name|printf
argument_list|(
literal|"%d"
argument_list|,
operator|*
name|up
argument_list|)
expr_stmt|;
for|for
control|(
name|up
operator|=
name|up
operator|-
literal|1
init|;
name|up
operator|>=
name|dn
operator|->
name|lsu
condition|;
name|up
operator|--
control|)
block|{
name|u
operator|=
operator|*
name|up
expr_stmt|;
name|printf
argument_list|(
literal|":"
argument_list|)
expr_stmt|;
for|for
control|(
name|cut
operator|=
name|DECDPUN
operator|-
literal|1
init|;
name|cut
operator|>=
literal|0
condition|;
name|cut
operator|--
control|)
block|{
name|d
operator|=
name|u
operator|/
name|powers
index|[
name|cut
index|]
expr_stmt|;
name|u
operator|-=
name|d
operator|*
name|powers
index|[
name|cut
index|]
expr_stmt|;
name|printf
argument_list|(
literal|"%d"
argument_list|,
name|d
argument_list|)
expr_stmt|;
block|}
comment|/* cut */
block|}
comment|/* up */
if|if
condition|(
name|dn
operator|->
name|exponent
operator|!=
literal|0
condition|)
block|{
name|char
name|esign
init|=
literal|'+'
decl_stmt|;
if|if
condition|(
name|dn
operator|->
name|exponent
operator|<
literal|0
condition|)
name|esign
operator|=
literal|'-'
expr_stmt|;
name|printf
argument_list|(
literal|" E%c%d"
argument_list|,
name|esign
argument_list|,
name|abs
argument_list|(
name|dn
operator|->
name|exponent
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|" [%d]\n"
argument_list|,
name|dn
operator|->
name|digits
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|#
directive|if
name|DECTRACE
operator|||
name|DECCHECK
comment|/* ------------------------------------------------------------------ */
comment|/* decDumpAr -- display a unit array [debug aid]                      */
comment|/*   name is a single-character tag name                              */
comment|/*   ar   is the array to display                                     */
comment|/*   len  is the length of the array in Units                         */
comment|/* ------------------------------------------------------------------ */
specifier|static
name|void
name|decDumpAr
parameter_list|(
name|char
name|name
parameter_list|,
specifier|const
name|Unit
modifier|*
name|ar
parameter_list|,
name|Int
name|len
parameter_list|)
block|{
name|Int
name|i
decl_stmt|;
if|#
directive|if
name|DECDPUN
operator|==
literal|4
specifier|const
name|char
modifier|*
name|spec
init|=
literal|"%04d "
decl_stmt|;
else|#
directive|else
specifier|const
name|char
modifier|*
name|spec
init|=
literal|"%d "
decl_stmt|;
endif|#
directive|endif
name|printf
argument_list|(
literal|"  :%c: "
argument_list|,
name|name
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|len
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
name|i
operator|--
control|)
block|{
if|if
condition|(
name|i
operator|==
name|len
operator|-
literal|1
condition|)
name|printf
argument_list|(
literal|"%d "
argument_list|,
name|ar
index|[
name|i
index|]
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
name|spec
argument_list|,
name|ar
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
if|#
directive|if
name|DECCHECK
comment|/* ------------------------------------------------------------------ */
comment|/* decCheckOperands -- check operand(s) to a routine                  */
comment|/*   res is the result structure (not checked; it will be set to      */
comment|/*          quiet NaN if error found (and it is not NULL))            */
comment|/*   lhs is the first operand (may be DECUNUSED)                      */
comment|/*   rhs is the second (may be DECUNUSED)                             */
comment|/*   set is the context (may be DECUNUSED)                            */
comment|/*   returns 0 if both operands, and the context are clean, or 1      */
comment|/*     otherwise (in which case the context will show an error,       */
comment|/*     unless NULL).  Note that res is not cleaned; caller should     */
comment|/*     handle this so res=NULL case is safe.                          */
comment|/* The caller is expected to abandon immediately if 1 is returned.    */
comment|/* ------------------------------------------------------------------ */
specifier|static
name|Flag
name|decCheckOperands
parameter_list|(
name|decNumber
modifier|*
name|res
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|lhs
parameter_list|,
specifier|const
name|decNumber
modifier|*
name|rhs
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|Flag
name|bad
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|set
operator|==
name|NULL
condition|)
block|{
comment|/* oops; hopeless */
if|#
directive|if
name|DECTRACE
name|printf
argument_list|(
literal|"Context is NULL.\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|bad
operator|=
literal|1
expr_stmt|;
return|return
literal|1
return|;
block|}
elseif|else
if|if
condition|(
name|set
operator|!=
name|DECUNUSED
operator|&&
operator|(
name|set
operator|->
name|digits
operator|<
literal|1
operator|||
name|set
operator|->
name|round
operator|<
literal|0
operator|||
name|set
operator|->
name|round
operator|>=
name|DEC_ROUND_MAX
operator|)
condition|)
block|{
name|bad
operator|=
literal|1
expr_stmt|;
if|#
directive|if
name|DECTRACE
name|printf
argument_list|(
literal|"Bad context [digits=%d round=%d].\n"
argument_list|,
name|set
operator|->
name|digits
argument_list|,
name|set
operator|->
name|round
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
else|else
block|{
if|if
condition|(
name|res
operator|==
name|NULL
condition|)
block|{
name|bad
operator|=
literal|1
expr_stmt|;
if|#
directive|if
name|DECTRACE
name|printf
argument_list|(
literal|"Bad result [is NULL].\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
if|if
condition|(
operator|!
name|bad
operator|&&
name|lhs
operator|!=
name|DECUNUSED
condition|)
name|bad
operator|=
operator|(
name|decCheckNumber
argument_list|(
name|lhs
argument_list|,
name|set
argument_list|)
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|bad
operator|&&
name|rhs
operator|!=
name|DECUNUSED
condition|)
name|bad
operator|=
operator|(
name|decCheckNumber
argument_list|(
name|rhs
argument_list|,
name|set
argument_list|)
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|bad
condition|)
block|{
if|if
condition|(
name|set
operator|!=
name|DECUNUSED
condition|)
name|decContextSetStatus
argument_list|(
name|set
argument_list|,
name|DEC_Invalid_operation
argument_list|)
expr_stmt|;
if|if
condition|(
name|res
operator|!=
name|DECUNUSED
operator|&&
name|res
operator|!=
name|NULL
condition|)
block|{
name|decNumberZero
argument_list|(
name|res
argument_list|)
expr_stmt|;
name|res
operator|->
name|bits
operator|=
name|DECNAN
expr_stmt|;
comment|/* qNaN */
block|}
block|}
return|return
name|bad
return|;
block|}
comment|/* ------------------------------------------------------------------ */
comment|/* decCheckNumber -- check a number                                   */
comment|/*   dn is the number to check                                        */
comment|/*   set is the context (may be DECUNUSED)                            */
comment|/*   returns 0 if the number is clean, or 1 otherwise                 */
comment|/*                                                                    */
comment|/* The number is considered valid if it could be a result from some   */
comment|/* operation in some valid context (not necessarily the current one). */
comment|/* ------------------------------------------------------------------ */
name|Flag
name|decCheckNumber
parameter_list|(
specifier|const
name|decNumber
modifier|*
name|dn
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
specifier|const
name|Unit
modifier|*
name|up
decl_stmt|;
comment|/* work */
name|uInt
name|maxuint
decl_stmt|;
comment|/* .. */
name|Int
name|ae
decl_stmt|,
name|d
decl_stmt|,
name|digits
decl_stmt|;
comment|/* .. */
name|Int
name|emin
decl_stmt|,
name|emax
decl_stmt|;
comment|/* .. */
if|if
condition|(
name|dn
operator|==
name|NULL
condition|)
block|{
comment|/* hopeless */
if|#
directive|if
name|DECTRACE
name|printf
argument_list|(
literal|"Reference to decNumber is NULL.\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|1
return|;
block|}
comment|/* check special values */
if|if
condition|(
name|dn
operator|->
name|bits
operator|&
name|DECSPECIAL
condition|)
block|{
if|if
condition|(
name|dn
operator|->
name|exponent
operator|!=
literal|0
condition|)
block|{
if|#
directive|if
name|DECTRACE
name|printf
argument_list|(
literal|"Exponent %d (not 0) for a special value.\n"
argument_list|,
name|dn
operator|->
name|exponent
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|1
return|;
block|}
comment|/* 2003.09.08: NaNs may now have coefficients, so next tests Inf only */
if|if
condition|(
name|decNumberIsInfinite
argument_list|(
name|dn
argument_list|)
condition|)
block|{
if|if
condition|(
name|dn
operator|->
name|digits
operator|!=
literal|1
condition|)
block|{
if|#
directive|if
name|DECTRACE
name|printf
argument_list|(
literal|"Digits %d (not 1) for an infinity.\n"
argument_list|,
name|dn
operator|->
name|digits
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|1
return|;
block|}
if|if
condition|(
operator|*
name|dn
operator|->
name|lsu
operator|!=
literal|0
condition|)
block|{
if|#
directive|if
name|DECTRACE
name|printf
argument_list|(
literal|"LSU %d (not 0) for an infinity.\n"
argument_list|,
operator|*
name|dn
operator|->
name|lsu
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|1
return|;
block|}
block|}
comment|/* Inf */
comment|/* 2002.12.26: negative NaNs can now appear through proposed IEEE */
comment|/*             concrete formats (decimal64, etc.), though they are */
comment|/*             never visible in strings. */
return|return
literal|0
return|;
comment|/* if ((dn->bits& DECINF) || (dn->bits& DECNEG)==0) return 0; */
comment|/* #if DECTRACE */
comment|/* printf("Negative NaN in number.\n"); */
comment|/* #endif */
comment|/* return 1; */
block|}
comment|/* check the coefficient */
if|if
condition|(
name|dn
operator|->
name|digits
operator|<
literal|1
operator|||
name|dn
operator|->
name|digits
operator|>
name|DECNUMMAXP
condition|)
block|{
if|#
directive|if
name|DECTRACE
name|printf
argument_list|(
literal|"Digits %d in number.\n"
argument_list|,
name|dn
operator|->
name|digits
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|1
return|;
block|}
name|d
operator|=
name|dn
operator|->
name|digits
expr_stmt|;
for|for
control|(
name|up
operator|=
name|dn
operator|->
name|lsu
init|;
name|d
operator|>
literal|0
condition|;
name|up
operator|++
control|)
block|{
if|if
condition|(
name|d
operator|>
name|DECDPUN
condition|)
name|maxuint
operator|=
name|DECDPUNMAX
expr_stmt|;
else|else
block|{
comment|/* we are at the msu */
name|maxuint
operator|=
name|powers
index|[
name|d
index|]
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|dn
operator|->
name|digits
operator|>
literal|1
operator|&&
operator|*
name|up
operator|<
name|powers
index|[
name|d
operator|-
literal|1
index|]
condition|)
block|{
if|#
directive|if
name|DECTRACE
name|printf
argument_list|(
literal|"Leading 0 in number.\n"
argument_list|)
expr_stmt|;
name|decNumberShow
argument_list|(
name|dn
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|1
return|;
block|}
block|}
if|if
condition|(
operator|*
name|up
operator|>
name|maxuint
condition|)
block|{
if|#
directive|if
name|DECTRACE
name|printf
argument_list|(
literal|"Bad Unit [%08x] in number at offset %d [maxuint %d].\n"
argument_list|,
operator|*
name|up
argument_list|,
name|up
operator|-
name|dn
operator|->
name|lsu
argument_list|,
name|maxuint
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|1
return|;
block|}
name|d
operator|-=
name|DECDPUN
expr_stmt|;
block|}
comment|/* check the exponent.  Note that input operands can have exponents */
comment|/* which are out of the set->emin/set->emax and set->digits range */
comment|/* (just as they can have more digits than set->digits). */
name|ae
operator|=
name|dn
operator|->
name|exponent
operator|+
name|dn
operator|->
name|digits
operator|-
literal|1
expr_stmt|;
comment|/* adjusted exponent */
name|emax
operator|=
name|DECNUMMAXE
expr_stmt|;
name|emin
operator|=
name|DECNUMMINE
expr_stmt|;
name|digits
operator|=
name|DECNUMMAXP
expr_stmt|;
if|if
condition|(
name|ae
operator|<
name|emin
operator|-
operator|(
name|digits
operator|-
literal|1
operator|)
condition|)
block|{
if|#
directive|if
name|DECTRACE
name|printf
argument_list|(
literal|"Adjusted exponent underflow [%d].\n"
argument_list|,
name|ae
argument_list|)
expr_stmt|;
name|decNumberShow
argument_list|(
name|dn
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|1
return|;
block|}
if|if
condition|(
name|ae
operator|>
operator|+
name|emax
condition|)
block|{
if|#
directive|if
name|DECTRACE
name|printf
argument_list|(
literal|"Adjusted exponent overflow [%d].\n"
argument_list|,
name|ae
argument_list|)
expr_stmt|;
name|decNumberShow
argument_list|(
name|dn
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|1
return|;
block|}
return|return
literal|0
return|;
comment|/* it's OK */
block|}
endif|#
directive|endif
if|#
directive|if
name|DECALLOC
undef|#
directive|undef
name|malloc
undef|#
directive|undef
name|free
comment|/* ------------------------------------------------------------------ */
comment|/* decMalloc -- accountable allocation routine                        */
comment|/*   n is the number of bytes to allocate                             */
comment|/*                                                                    */
comment|/* Semantics is the same as the stdlib malloc routine, but bytes      */
comment|/* allocated are accounted for globally, and corruption fences are    */
comment|/* added before and after the 'actual' storage.                       */
comment|/* ------------------------------------------------------------------ */
comment|/* This routine allocates storage with an extra twelve bytes; 8 are   */
comment|/* at the start and hold:                                             */
comment|/*   0-3 the original length requested                                */
comment|/*   4-7 buffer corruption detection fence (DECFENCE, x4)             */
comment|/* The 4 bytes at the end also hold a corruption fence (DECFENCE, x4) */
comment|/* ------------------------------------------------------------------ */
specifier|static
name|void
modifier|*
name|decMalloc
parameter_list|(
name|uInt
name|n
parameter_list|)
block|{
name|uInt
name|size
init|=
name|n
operator|+
literal|12
decl_stmt|;
comment|/* true size */
name|void
modifier|*
name|alloc
decl_stmt|;
comment|/* -> allocated storage */
name|uInt
modifier|*
name|j
decl_stmt|;
comment|/* work */
name|uByte
modifier|*
name|b
decl_stmt|,
modifier|*
name|b0
decl_stmt|;
comment|/* .. */
name|alloc
operator|=
name|malloc
argument_list|(
name|size
argument_list|)
expr_stmt|;
comment|/* -> allocated storage */
if|if
condition|(
name|alloc
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
comment|/* out of strorage */
name|b0
operator|=
operator|(
name|uByte
operator|*
operator|)
name|alloc
expr_stmt|;
comment|/* as bytes */
name|decAllocBytes
operator|+=
name|n
expr_stmt|;
comment|/* account for storage */
name|j
operator|=
operator|(
name|uInt
operator|*
operator|)
name|alloc
expr_stmt|;
comment|/* -> first four bytes */
operator|*
name|j
operator|=
name|n
expr_stmt|;
comment|/* save n */
comment|/* printf("++ alloc(%d)\n", n); */
for|for
control|(
name|b
operator|=
name|b0
operator|+
literal|4
init|;
name|b
operator|<
name|b0
operator|+
literal|8
condition|;
name|b
operator|++
control|)
operator|*
name|b
operator|=
name|DECFENCE
expr_stmt|;
for|for
control|(
name|b
operator|=
name|b0
operator|+
name|n
operator|+
literal|8
init|;
name|b
operator|<
name|b0
operator|+
name|n
operator|+
literal|12
condition|;
name|b
operator|++
control|)
operator|*
name|b
operator|=
name|DECFENCE
expr_stmt|;
return|return
name|b0
operator|+
literal|8
return|;
comment|/* -> play area */
block|}
comment|/* ------------------------------------------------------------------ */
comment|/* decFree -- accountable free routine                                */
comment|/*   alloc is the storage to free                                     */
comment|/*                                                                    */
comment|/* Semantics is the same as the stdlib malloc routine, except that    */
comment|/* the global storage accounting is updated and the fences are        */
comment|/* checked to ensure that no routine has written 'out of bounds'.     */
comment|/* ------------------------------------------------------------------ */
comment|/* This routine first checks that the fences have not been corrupted. */
comment|/* It then frees the storage using the 'truw' storage address (that   */
comment|/* is, offset by 8).                                                  */
comment|/* ------------------------------------------------------------------ */
specifier|static
name|void
name|decFree
parameter_list|(
name|void
modifier|*
name|alloc
parameter_list|)
block|{
name|uInt
modifier|*
name|j
decl_stmt|,
name|n
decl_stmt|;
comment|/* pointer, original length */
name|uByte
modifier|*
name|b
decl_stmt|,
modifier|*
name|b0
decl_stmt|;
comment|/* work */
if|if
condition|(
name|alloc
operator|==
name|NULL
condition|)
return|return;
comment|/* allowed; it's a nop */
name|b0
operator|=
operator|(
name|uByte
operator|*
operator|)
name|alloc
expr_stmt|;
comment|/* as bytes */
name|b0
operator|-=
literal|8
expr_stmt|;
comment|/* -> true start of storage */
name|j
operator|=
operator|(
name|uInt
operator|*
operator|)
name|b0
expr_stmt|;
comment|/* -> first four bytes */
name|n
operator|=
operator|*
name|j
expr_stmt|;
comment|/* lift */
for|for
control|(
name|b
operator|=
name|b0
operator|+
literal|4
init|;
name|b
operator|<
name|b0
operator|+
literal|8
condition|;
name|b
operator|++
control|)
if|if
condition|(
operator|*
name|b
operator|!=
name|DECFENCE
condition|)
name|printf
argument_list|(
literal|"=== Corrupt byte [%02x] at offset %d from %d ===\n"
argument_list|,
operator|*
name|b
argument_list|,
name|b
operator|-
name|b0
operator|-
literal|8
argument_list|,
operator|(
name|Int
operator|)
name|b0
argument_list|)
expr_stmt|;
for|for
control|(
name|b
operator|=
name|b0
operator|+
name|n
operator|+
literal|8
init|;
name|b
operator|<
name|b0
operator|+
name|n
operator|+
literal|12
condition|;
name|b
operator|++
control|)
if|if
condition|(
operator|*
name|b
operator|!=
name|DECFENCE
condition|)
name|printf
argument_list|(
literal|"=== Corrupt byte [%02x] at offset +%d from %d, n=%d ===\n"
argument_list|,
operator|*
name|b
argument_list|,
name|b
operator|-
name|b0
operator|-
literal|8
argument_list|,
operator|(
name|Int
operator|)
name|b0
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|b0
argument_list|)
expr_stmt|;
comment|/* drop the storage */
name|decAllocBytes
operator|-=
name|n
expr_stmt|;
comment|/* account for storage */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

