begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Decimal 32-bit format module for the decNumber C Library    Copyright (C) 2005 Free Software Foundation, Inc.    Contributed by IBM Corporation.  Author Mike Cowlishaw.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it under    the terms of the GNU General Public License as published by the Free    Software Foundation; either version 2, or (at your option) any later    version.     In addition to the permissions in the GNU General Public License,    the Free Software Foundation gives you unlimited permission to link    the compiled version of this file into combinations with other    programs, and to distribute those combinations without any    restriction coming from the use of this file.  (The General Public    License restrictions do apply in other respects; for example, they    cover modification of the file, and distribution when not linked    into a combine executable.)     GCC is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* This module comprises the routines for decimal32 format numbers.   */
end_comment

begin_comment
comment|/* Conversions are supplied to and from decNumber and String.         */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* No arithmetic routines are included; decNumber provides these.     */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* Error handling is the same as decNumber (qv.).                     */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* [for memset/memcpy] */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* [for printf] */
end_comment

begin_define
define|#
directive|define
name|DECNUMDIGITS
value|7
end_define

begin_comment
comment|/* we need decNumbers with space for 7 */
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

begin_include
include|#
directive|include
file|"decimal32.h"
end_include

begin_comment
comment|/* our primary include */
end_comment

begin_include
include|#
directive|include
file|"decUtility.h"
end_include

begin_comment
comment|/* utility routines */
end_comment

begin_if
if|#
directive|if
name|DECTRACE
operator|||
name|DECCHECK
end_if

begin_function_decl
name|void
name|decimal32Show
parameter_list|(
specifier|const
name|decimal32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* for debug */
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
comment|/* .. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Useful macro */
end_comment

begin_comment
comment|/* Clear a structure (e.g., a decNumber) */
end_comment

begin_define
define|#
directive|define
name|DEC_clear
parameter_list|(
name|d
parameter_list|)
value|memset(d, 0, sizeof(*d))
end_define

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decimal32FromNumber -- convert decNumber to decimal32              */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   ds is the target decimal32                                       */
end_comment

begin_comment
comment|/*   dn is the source number (assumed valid)                          */
end_comment

begin_comment
comment|/*   set is the context, used only for reporting errors               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* The set argument is used only for status reporting and for the     */
end_comment

begin_comment
comment|/* rounding mode (used if the coefficient is more than DECIMAL32_Pmax */
end_comment

begin_comment
comment|/* digits or an overflow is detected).  If the exponent is out of the */
end_comment

begin_comment
comment|/* valid range then Overflow or Underflow will be raised.             */
end_comment

begin_comment
comment|/* After Underflow a subnormal result is possible.                    */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* DEC_Clamped is set if the number has to be 'folded down' to fit,   */
end_comment

begin_comment
comment|/* by reducing its exponent and multiplying the coefficient by a      */
end_comment

begin_comment
comment|/* power of ten, or if the exponent on a zero had to be clamped.      */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decimal32
modifier|*
name|decimal32FromNumber
parameter_list|(
name|decimal32
modifier|*
name|d32
parameter_list|,
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
name|uInt
name|status
init|=
literal|0
decl_stmt|;
comment|/* status accumulator */
name|Int
name|pad
init|=
literal|0
decl_stmt|;
comment|/* coefficient pad digits */
name|decNumber
name|dw
decl_stmt|;
comment|/* work */
name|decContext
name|dc
decl_stmt|;
comment|/* .. */
name|uByte
name|isneg
init|=
name|dn
operator|->
name|bits
operator|&
name|DECNEG
decl_stmt|;
comment|/* non-0 if original sign set */
name|uInt
name|comb
decl_stmt|,
name|exp
decl_stmt|;
comment|/* work */
comment|/* If the number is finite, and has too many digits, or the exponent */
comment|/* could be out of range then we reduce the number under the */
comment|/* appropriate constraints */
if|if
condition|(
operator|!
operator|(
name|dn
operator|->
name|bits
operator|&
name|DECSPECIAL
operator|)
condition|)
block|{
comment|/* not a special value */
name|Int
name|ae
init|=
name|dn
operator|->
name|exponent
operator|+
name|dn
operator|->
name|digits
operator|-
literal|1
decl_stmt|;
comment|/* adjusted exponent */
if|if
condition|(
name|dn
operator|->
name|digits
operator|>
name|DECIMAL32_Pmax
comment|/* too many digits */
operator|||
name|ae
operator|>
name|DECIMAL32_Emax
comment|/* likely overflow */
operator|||
name|ae
operator|<
name|DECIMAL32_Emin
condition|)
block|{
comment|/* likely underflow */
name|decContextDefault
argument_list|(
operator|&
name|dc
argument_list|,
name|DEC_INIT_DECIMAL32
argument_list|)
expr_stmt|;
comment|/* [no traps] */
name|dc
operator|.
name|round
operator|=
name|set
operator|->
name|round
expr_stmt|;
comment|/* use supplied rounding */
name|decNumberPlus
argument_list|(
operator|&
name|dw
argument_list|,
name|dn
argument_list|,
operator|&
name|dc
argument_list|)
expr_stmt|;
comment|/* (round and check) */
comment|/* [this changes -0 to 0, but it will be restored below] */
name|status
operator||=
name|dc
operator|.
name|status
expr_stmt|;
comment|/* save status */
name|dn
operator|=
operator|&
name|dw
expr_stmt|;
comment|/* use the work number */
block|}
comment|/* [this could have pushed number to Infinity or zero, so this */
comment|/* rounding must be done before we generate the decimal32] */
block|}
name|DEC_clear
argument_list|(
name|d32
argument_list|)
expr_stmt|;
comment|/* clean the target */
if|if
condition|(
name|dn
operator|->
name|bits
operator|&
name|DECSPECIAL
condition|)
block|{
comment|/* a special value */
name|uByte
name|top
decl_stmt|;
comment|/* work */
if|if
condition|(
name|dn
operator|->
name|bits
operator|&
name|DECINF
condition|)
name|top
operator|=
name|DECIMAL_Inf
expr_stmt|;
else|else
block|{
comment|/* sNaN or qNaN */
if|if
condition|(
operator|(
operator|*
name|dn
operator|->
name|lsu
operator|!=
literal|0
operator|||
name|dn
operator|->
name|digits
operator|>
literal|1
operator|)
comment|/* non-zero coefficient */
operator|&&
operator|(
name|dn
operator|->
name|digits
operator|<
name|DECIMAL32_Pmax
operator|)
condition|)
block|{
comment|/* coefficient fits */
name|decDensePackCoeff
argument_list|(
name|dn
argument_list|,
name|d32
operator|->
name|bytes
argument_list|,
sizeof|sizeof
argument_list|(
name|d32
operator|->
name|bytes
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|dn
operator|->
name|bits
operator|&
name|DECNAN
condition|)
name|top
operator|=
name|DECIMAL_NaN
expr_stmt|;
else|else
name|top
operator|=
name|DECIMAL_sNaN
expr_stmt|;
block|}
name|d32
operator|->
name|bytes
index|[
literal|0
index|]
operator|=
name|top
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|decNumberIsZero
argument_list|(
name|dn
argument_list|)
condition|)
block|{
comment|/* a zero */
comment|/* set and clamp exponent */
if|if
condition|(
name|dn
operator|->
name|exponent
operator|<
operator|-
name|DECIMAL32_Bias
condition|)
block|{
name|exp
operator|=
literal|0
expr_stmt|;
name|status
operator||=
name|DEC_Clamped
expr_stmt|;
block|}
else|else
block|{
name|exp
operator|=
name|dn
operator|->
name|exponent
operator|+
name|DECIMAL32_Bias
expr_stmt|;
comment|/* bias exponent */
if|if
condition|(
name|exp
operator|>
name|DECIMAL32_Ehigh
condition|)
block|{
comment|/* top clamp */
name|exp
operator|=
name|DECIMAL32_Ehigh
expr_stmt|;
name|status
operator||=
name|DEC_Clamped
expr_stmt|;
block|}
block|}
name|comb
operator|=
operator|(
name|exp
operator|>>
literal|3
operator|)
operator|&
literal|0x18
expr_stmt|;
comment|/* combination field */
name|d32
operator|->
name|bytes
index|[
literal|0
index|]
operator|=
call|(
name|uByte
call|)
argument_list|(
name|comb
operator|<<
literal|2
argument_list|)
expr_stmt|;
name|exp
operator|&=
literal|0x3f
expr_stmt|;
comment|/* remaining exponent bits */
name|decimal32SetExpCon
argument_list|(
name|d32
argument_list|,
name|exp
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* non-zero finite number */
name|uInt
name|msd
decl_stmt|;
comment|/* work */
comment|/* we have a dn that fits, but it may need to be padded */
name|exp
operator|=
call|(
name|uInt
call|)
argument_list|(
name|dn
operator|->
name|exponent
operator|+
name|DECIMAL32_Bias
argument_list|)
expr_stmt|;
comment|/* bias exponent */
if|if
condition|(
name|exp
operator|>
name|DECIMAL32_Ehigh
condition|)
block|{
comment|/* fold-down case */
name|pad
operator|=
name|exp
operator|-
name|DECIMAL32_Ehigh
expr_stmt|;
name|exp
operator|=
name|DECIMAL32_Ehigh
expr_stmt|;
comment|/* [to maximum] */
name|status
operator||=
name|DEC_Clamped
expr_stmt|;
block|}
name|decDensePackCoeff
argument_list|(
name|dn
argument_list|,
name|d32
operator|->
name|bytes
argument_list|,
sizeof|sizeof
argument_list|(
name|d32
operator|->
name|bytes
argument_list|)
argument_list|,
name|pad
argument_list|)
expr_stmt|;
comment|/* save and clear the top digit */
name|msd
operator|=
operator|(
operator|(
name|unsigned
operator|)
name|d32
operator|->
name|bytes
index|[
literal|1
index|]
operator|>>
literal|4
operator|)
expr_stmt|;
name|d32
operator|->
name|bytes
index|[
literal|1
index|]
operator|&=
literal|0x0f
expr_stmt|;
comment|/* create the combination field */
if|if
condition|(
name|msd
operator|>=
literal|8
condition|)
name|comb
operator|=
literal|0x18
operator||
operator|(
name|msd
operator|&
literal|0x01
operator|)
operator||
operator|(
operator|(
name|exp
operator|>>
literal|5
operator|)
operator|&
literal|0x06
operator|)
expr_stmt|;
else|else
name|comb
operator|=
operator|(
name|msd
operator|&
literal|0x07
operator|)
operator||
operator|(
operator|(
name|exp
operator|>>
literal|3
operator|)
operator|&
literal|0x18
operator|)
expr_stmt|;
name|d32
operator|->
name|bytes
index|[
literal|0
index|]
operator|=
call|(
name|uByte
call|)
argument_list|(
name|comb
operator|<<
literal|2
argument_list|)
expr_stmt|;
name|exp
operator|&=
literal|0x3f
expr_stmt|;
comment|/* remaining exponent bits */
name|decimal32SetExpCon
argument_list|(
name|d32
argument_list|,
name|exp
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|isneg
condition|)
name|decimal32SetSign
argument_list|(
name|d32
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|decContextSetStatus
argument_list|(
name|set
argument_list|,
name|status
argument_list|)
expr_stmt|;
comment|/* pass on status */
comment|/*decimal32Show(d32); */
return|return
name|d32
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decimal32ToNumber -- convert decimal32 to decNumber                */
end_comment

begin_comment
comment|/*   d32 is the source decimal32                                      */
end_comment

begin_comment
comment|/*   dn is the target number, with appropriate space                  */
end_comment

begin_comment
comment|/* No error is possible.                                              */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decNumber
modifier|*
name|decimal32ToNumber
parameter_list|(
specifier|const
name|decimal32
modifier|*
name|d32
parameter_list|,
name|decNumber
modifier|*
name|dn
parameter_list|)
block|{
name|uInt
name|msd
decl_stmt|;
comment|/* coefficient MSD */
name|decimal32
name|wk
decl_stmt|;
comment|/* working copy, if needed */
name|uInt
name|top
init|=
name|d32
operator|->
name|bytes
index|[
literal|0
index|]
operator|&
literal|0x7f
decl_stmt|;
comment|/* top byte, less sign bit */
name|decNumberZero
argument_list|(
name|dn
argument_list|)
expr_stmt|;
comment|/* clean target */
comment|/* set the sign if negative */
if|if
condition|(
name|decimal32Sign
argument_list|(
name|d32
argument_list|)
condition|)
name|dn
operator|->
name|bits
operator|=
name|DECNEG
expr_stmt|;
if|if
condition|(
name|top
operator|>=
literal|0x78
condition|)
block|{
comment|/* is a special */
if|if
condition|(
operator|(
name|top
operator|&
literal|0x7c
operator|)
operator|==
operator|(
name|DECIMAL_Inf
operator|&
literal|0x7c
operator|)
condition|)
name|dn
operator|->
name|bits
operator||=
name|DECINF
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|top
operator|&
literal|0x7e
operator|)
operator|==
operator|(
name|DECIMAL_NaN
operator|&
literal|0x7e
operator|)
condition|)
name|dn
operator|->
name|bits
operator||=
name|DECNAN
expr_stmt|;
else|else
name|dn
operator|->
name|bits
operator||=
name|DECSNAN
expr_stmt|;
name|msd
operator|=
literal|0
expr_stmt|;
comment|/* no top digit */
block|}
else|else
block|{
comment|/* have a finite number */
name|uInt
name|comb
init|=
name|top
operator|>>
literal|2
decl_stmt|;
comment|/* combination field */
name|uInt
name|exp
decl_stmt|;
comment|/* working exponent */
if|if
condition|(
name|comb
operator|>=
literal|0x18
condition|)
block|{
name|msd
operator|=
literal|8
operator|+
operator|(
name|comb
operator|&
literal|0x01
operator|)
expr_stmt|;
name|exp
operator|=
operator|(
name|comb
operator|&
literal|0x06
operator|)
operator|<<
literal|5
expr_stmt|;
comment|/* MSBs */
block|}
else|else
block|{
name|msd
operator|=
name|comb
operator|&
literal|0x07
expr_stmt|;
name|exp
operator|=
operator|(
name|comb
operator|&
literal|0x18
operator|)
operator|<<
literal|3
expr_stmt|;
block|}
name|dn
operator|->
name|exponent
operator|=
name|exp
operator|+
name|decimal32ExpCon
argument_list|(
name|d32
argument_list|)
operator|-
name|DECIMAL32_Bias
expr_stmt|;
comment|/* remove bias */
block|}
comment|/* get the coefficient, unless infinite */
if|if
condition|(
operator|!
operator|(
name|dn
operator|->
name|bits
operator|&
name|DECINF
operator|)
condition|)
block|{
name|Int
name|bunches
init|=
name|DECIMAL32_Pmax
operator|/
literal|3
decl_stmt|;
comment|/* coefficient full bunches to convert */
name|Int
name|odd
init|=
literal|0
decl_stmt|;
comment|/* assume MSD is 0 (no odd bunch) */
if|if
condition|(
name|msd
operator|!=
literal|0
condition|)
block|{
comment|/* coefficient has leading non-0 digit */
comment|/* make a copy of the decimal32, with an extra bunch which has */
comment|/* the top digit ready for conversion */
name|wk
operator|=
operator|*
name|d32
expr_stmt|;
comment|/* take a copy */
name|wk
operator|.
name|bytes
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
comment|/* clear all but coecon */
name|wk
operator|.
name|bytes
index|[
literal|1
index|]
operator|&=
literal|0x0f
expr_stmt|;
comment|/* .. */
name|wk
operator|.
name|bytes
index|[
literal|1
index|]
operator||=
operator|(
name|msd
operator|<<
literal|4
operator|)
expr_stmt|;
comment|/* and prefix MSD */
name|odd
operator|++
expr_stmt|;
comment|/* indicate the extra */
name|d32
operator|=
operator|&
name|wk
expr_stmt|;
comment|/* use the work copy */
block|}
name|decDenseUnpackCoeff
argument_list|(
name|d32
operator|->
name|bytes
argument_list|,
sizeof|sizeof
argument_list|(
name|d32
operator|->
name|bytes
argument_list|)
argument_list|,
name|dn
argument_list|,
name|bunches
argument_list|,
name|odd
argument_list|)
expr_stmt|;
block|}
return|return
name|dn
return|;
block|}
end_function

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
comment|/*   decimal32ToString(d32, string);                                  */
end_comment

begin_comment
comment|/*   decimal32ToEngString(d32, string);                               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  d32 is the decimal32 format number to convert                     */
end_comment

begin_comment
comment|/*  string is the string where the result will be laid out            */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  string must be at least 24 characters                             */
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
name|decimal32ToString
parameter_list|(
specifier|const
name|decimal32
modifier|*
name|d32
parameter_list|,
name|char
modifier|*
name|string
parameter_list|)
block|{
name|decNumber
name|dn
decl_stmt|;
comment|/* work */
name|decimal32ToNumber
argument_list|(
name|d32
argument_list|,
operator|&
name|dn
argument_list|)
expr_stmt|;
name|decNumberToString
argument_list|(
operator|&
name|dn
argument_list|,
name|string
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
name|decimal32ToEngString
parameter_list|(
specifier|const
name|decimal32
modifier|*
name|d32
parameter_list|,
name|char
modifier|*
name|string
parameter_list|)
block|{
name|decNumber
name|dn
decl_stmt|;
comment|/* work */
name|decimal32ToNumber
argument_list|(
name|d32
argument_list|,
operator|&
name|dn
argument_list|)
expr_stmt|;
name|decNumberToEngString
argument_list|(
operator|&
name|dn
argument_list|,
name|string
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
comment|/*   decimal32FromString(result, string, set);                        */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  result  is the decimal32 format number which gets the result of   */
end_comment

begin_comment
comment|/*          the conversion                                            */
end_comment

begin_comment
comment|/*  *string is the character string which should contain a valid      */
end_comment

begin_comment
comment|/*          number (which may be a special value)                     */
end_comment

begin_comment
comment|/*  set     is the context                                            */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* The context is supplied to this routine is used for error handling */
end_comment

begin_comment
comment|/* (setting of status and traps) and for the rounding mode, only.     */
end_comment

begin_comment
comment|/* If an error occurs, the result will be a valid decimal32 NaN.      */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decimal32
modifier|*
name|decimal32FromString
parameter_list|(
name|decimal32
modifier|*
name|result
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|decContext
modifier|*
name|set
parameter_list|)
block|{
name|decContext
name|dc
decl_stmt|;
comment|/* work */
name|decNumber
name|dn
decl_stmt|;
comment|/* .. */
name|decContextDefault
argument_list|(
operator|&
name|dc
argument_list|,
name|DEC_INIT_DECIMAL32
argument_list|)
expr_stmt|;
comment|/* no traps, please */
name|dc
operator|.
name|round
operator|=
name|set
operator|->
name|round
expr_stmt|;
comment|/* use supplied rounding */
name|decNumberFromString
argument_list|(
operator|&
name|dn
argument_list|,
name|string
argument_list|,
operator|&
name|dc
argument_list|)
expr_stmt|;
comment|/* will round if needed */
name|decimal32FromNumber
argument_list|(
name|result
argument_list|,
operator|&
name|dn
argument_list|,
operator|&
name|dc
argument_list|)
expr_stmt|;
if|if
condition|(
name|dc
operator|.
name|status
operator|!=
literal|0
condition|)
block|{
comment|/* something happened */
name|decContextSetStatus
argument_list|(
name|set
argument_list|,
name|dc
operator|.
name|status
argument_list|)
expr_stmt|;
comment|/* .. pass it on */
block|}
return|return
name|result
return|;
block|}
end_function

begin_if
if|#
directive|if
name|DECTRACE
operator|||
name|DECCHECK
end_if

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decimal32Show -- display a single in hexadecimal [debug aid]       */
end_comment

begin_comment
comment|/*   d32 -- the number to show                                        */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Also shows sign/cob/expconfields extracted */
end_comment

begin_function
name|void
name|decimal32Show
parameter_list|(
specifier|const
name|decimal32
modifier|*
name|d32
parameter_list|)
block|{
name|char
name|buf
index|[
name|DECIMAL32_Bytes
operator|*
literal|2
operator|+
literal|1
index|]
decl_stmt|;
name|Int
name|i
decl_stmt|,
name|j
decl_stmt|;
name|j
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|DECIMAL32_Bytes
condition|;
name|i
operator|++
control|)
block|{
name|sprintf
argument_list|(
operator|&
name|buf
index|[
name|j
index|]
argument_list|,
literal|"%02x"
argument_list|,
name|d32
operator|->
name|bytes
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|j
operator|=
name|j
operator|+
literal|2
expr_stmt|;
block|}
name|printf
argument_list|(
literal|" D32> %s [S:%d Cb:%02x E:%d]\n"
argument_list|,
name|buf
argument_list|,
name|decimal32Sign
argument_list|(
name|d32
argument_list|)
argument_list|,
name|decimal32Comb
argument_list|(
name|d32
argument_list|)
argument_list|,
name|decimal32ExpCon
argument_list|(
name|d32
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

