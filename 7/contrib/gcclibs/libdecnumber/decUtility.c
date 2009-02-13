begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Utility functions for decimal floating point support via decNumber.    Copyright (C) 2005 Free Software Foundation, Inc.    Contributed by IBM Corporation.  Author Mike Cowlishaw.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it under    the terms of the GNU General Public License as published by the Free    Software Foundation; either version 2, or (at your option) any later    version.     In addition to the permissions in the GNU General Public License,    the Free Software Foundation gives you unlimited permission to link    the compiled version of this file into combinations with other    programs, and to distribute those combinations without any    restriction coming from the use of this file.  (The General Public    License restrictions do apply in other respects; for example, they    cover modification of the file, and distribution when not linked    into a combine executable.)     GCC is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA    02110-1301, USA.  */
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
file|"decUtility.h"
end_include

begin_comment
comment|/* utility routines */
end_comment

begin_comment
comment|/* ================================================================== */
end_comment

begin_comment
comment|/* Shared utility routines                                            */
end_comment

begin_comment
comment|/* ================================================================== */
end_comment

begin_comment
comment|/* define and include the conversion tables to use */
end_comment

begin_define
define|#
directive|define
name|DEC_BIN2DPD
value|1
end_define

begin_comment
comment|/* used for all sizes */
end_comment

begin_if
if|#
directive|if
name|DECDPUN
operator|==
literal|3
end_if

begin_define
define|#
directive|define
name|DEC_DPD2BIN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEC_DPD2BCD
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"decDPD.h"
end_include

begin_comment
comment|/* lookup tables */
end_comment

begin_comment
comment|/* The maximum number of decNumberUnits we need for a working copy of */
end_comment

begin_comment
comment|/* the units array is the ceiling of digits/DECDPUN, where digits is */
end_comment

begin_comment
comment|/* the maximum number of digits in any of the formats for which this */
end_comment

begin_comment
comment|/* is used.  We do not want to include decimal128.h, so, as a very */
end_comment

begin_comment
comment|/* special case, that number is defined here. */
end_comment

begin_define
define|#
directive|define
name|DECMAX754
value|34
end_define

begin_define
define|#
directive|define
name|DECMAXUNITS
value|((DECMAX754+DECDPUN-1)/DECDPUN)
end_define

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decDensePackCoeff -- densely pack coefficient into DPD form        */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   dn is the source number (assumed valid, max DECMAX754 digits)    */
end_comment

begin_comment
comment|/*   bytes is the target's byte array                                 */
end_comment

begin_comment
comment|/*   len is length of target format's byte array                      */
end_comment

begin_comment
comment|/*   shift is the number of 0 digits to add on the right (normally 0) */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* The coefficient must be known small enough to fit, and is filled   */
end_comment

begin_comment
comment|/* in from the right (least significant first).  Note that the full   */
end_comment

begin_comment
comment|/* coefficient is copied, including the leading 'odd' digit.  This    */
end_comment

begin_comment
comment|/* digit is retrieved and packed into the combination field by the    */
end_comment

begin_comment
comment|/* caller.                                                            */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* shift is used for 'fold-down' padding.                             */
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
name|void
name|decDensePackCoeff
parameter_list|(
specifier|const
name|decNumber
modifier|*
name|dn
parameter_list|,
name|uByte
modifier|*
name|bytes
parameter_list|,
name|Int
name|len
parameter_list|,
name|Int
name|shift
parameter_list|)
block|{
name|Int
name|cut
decl_stmt|;
comment|/* work */
name|Int
name|n
decl_stmt|;
comment|/* output bunch counter */
name|Int
name|digits
init|=
name|dn
operator|->
name|digits
decl_stmt|;
comment|/* digit countdown */
name|uInt
name|dpd
decl_stmt|;
comment|/* densely packed decimal value */
name|uInt
name|bin
decl_stmt|;
comment|/* binary value 0-999 */
name|uByte
modifier|*
name|bout
decl_stmt|;
comment|/* -> current output byte */
specifier|const
name|Unit
modifier|*
name|inu
init|=
name|dn
operator|->
name|lsu
decl_stmt|;
comment|/* -> current input unit */
name|Unit
name|uar
index|[
name|DECMAXUNITS
index|]
decl_stmt|;
comment|/* working copy of units, iff shifted */
if|#
directive|if
name|DECDPUN
operator|!=
literal|3
comment|/* not fast path */
name|Unit
name|in
decl_stmt|;
comment|/* current input unit */
endif|#
directive|endif
if|if
condition|(
name|shift
operator|!=
literal|0
condition|)
block|{
comment|/* shift towards most significant required */
comment|/* shift the units array to the left by pad digits and copy */
comment|/* [this code is a special case of decShiftToMost, which could */
comment|/* be used instead if exposed and the array were copied first] */
name|Unit
modifier|*
name|target
decl_stmt|,
modifier|*
name|first
decl_stmt|;
comment|/* work */
specifier|const
name|Unit
modifier|*
name|source
decl_stmt|;
comment|/* work */
name|uInt
name|next
init|=
literal|0
decl_stmt|;
comment|/* work */
name|source
operator|=
name|dn
operator|->
name|lsu
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
comment|/* where msu will end up */
name|target
operator|=
name|uar
operator|+
name|D2U
argument_list|(
name|digits
argument_list|)
operator|-
literal|1
operator|+
name|D2U
argument_list|(
name|shift
argument_list|)
expr_stmt|;
comment|/* where upper part of first cut goes */
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
for|for
control|(
init|;
name|source
operator|>=
name|dn
operator|->
name|lsu
condition|;
name|source
operator|--
operator|,
name|target
operator|--
control|)
block|{
comment|/* split the source Unit and accumulate remainder for next */
name|uInt
name|rem
init|=
operator|*
name|source
operator|%
name|powers
index|[
name|cut
index|]
decl_stmt|;
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
comment|/* propagate remainder to one below and clear the rest */
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
name|digits
operator|+=
name|shift
expr_stmt|;
comment|/* add count (shift) of zeros added */
name|inu
operator|=
name|uar
expr_stmt|;
comment|/* use units in working array */
block|}
comment|/* densely pack the coefficient into the byte array, starting from      the right (optionally padded) */
name|bout
operator|=
operator|&
name|bytes
index|[
name|len
operator|-
literal|1
index|]
expr_stmt|;
comment|/* rightmost result byte for phase */
if|#
directive|if
name|DECDPUN
operator|!=
literal|3
comment|/* not fast path */
name|in
operator|=
operator|*
name|inu
expr_stmt|;
comment|/* prime */
name|cut
operator|=
literal|0
expr_stmt|;
comment|/* at lowest digit */
name|bin
operator|=
literal|0
expr_stmt|;
comment|/* [keep compiler quiet] */
endif|#
directive|endif
for|for
control|(
name|n
operator|=
literal|0
init|;
name|digits
operator|>
literal|0
condition|;
name|n
operator|++
control|)
block|{
comment|/* each output bunch */
if|#
directive|if
name|DECDPUN
operator|==
literal|3
comment|/* fast path, 3-at-a-time */
name|bin
operator|=
operator|*
name|inu
expr_stmt|;
comment|/* 3 ready for convert */
name|digits
operator|-=
literal|3
expr_stmt|;
comment|/* [may go negative] */
name|inu
operator|++
expr_stmt|;
comment|/* may need another */
else|#
directive|else
comment|/* must collect digit-by-digit */
name|Unit
name|dig
decl_stmt|;
comment|/* current digit */
name|Int
name|j
decl_stmt|;
comment|/* digit-in-bunch count */
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
literal|3
condition|;
name|j
operator|++
control|)
block|{
if|#
directive|if
name|DECDPUN
operator|<=
literal|4
name|Unit
name|temp
init|=
call|(
name|Unit
call|)
argument_list|(
call|(
name|uInt
call|)
argument_list|(
name|in
operator|*
literal|6554
argument_list|)
operator|>>
literal|16
argument_list|)
decl_stmt|;
name|dig
operator|=
call|(
name|Unit
call|)
argument_list|(
name|in
operator|-
name|X10
argument_list|(
name|temp
argument_list|)
argument_list|)
expr_stmt|;
name|in
operator|=
name|temp
expr_stmt|;
else|#
directive|else
name|dig
operator|=
name|in
operator|%
literal|10
expr_stmt|;
name|in
operator|=
name|in
operator|/
literal|10
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|j
operator|==
literal|0
condition|)
name|bin
operator|=
name|dig
expr_stmt|;
elseif|else
if|if
condition|(
name|j
operator|==
literal|1
condition|)
name|bin
operator|+=
name|X10
argument_list|(
name|dig
argument_list|)
expr_stmt|;
else|else
comment|/* j==2 */
name|bin
operator|+=
name|X100
argument_list|(
name|dig
argument_list|)
expr_stmt|;
name|digits
operator|--
expr_stmt|;
if|if
condition|(
name|digits
operator|==
literal|0
condition|)
break|break;
comment|/* [also protects *inu below] */
name|cut
operator|++
expr_stmt|;
if|if
condition|(
name|cut
operator|==
name|DECDPUN
condition|)
block|{
name|inu
operator|++
expr_stmt|;
name|in
operator|=
operator|*
name|inu
expr_stmt|;
name|cut
operator|=
literal|0
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* here we have 3 digits in bin, or have used all input digits */
name|dpd
operator|=
name|BIN2DPD
index|[
name|bin
index|]
expr_stmt|;
comment|/* write bunch (bcd) to byte array */
switch|switch
condition|(
name|n
operator|&
literal|0x03
condition|)
block|{
comment|/* phase 0-3 */
case|case
literal|0
case|:
operator|*
name|bout
operator|=
operator|(
name|uByte
operator|)
name|dpd
expr_stmt|;
comment|/* [top 2 bits truncated] */
name|bout
operator|--
expr_stmt|;
operator|*
name|bout
operator|=
call|(
name|uByte
call|)
argument_list|(
name|dpd
operator|>>
literal|8
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
operator|*
name|bout
operator||=
call|(
name|uByte
call|)
argument_list|(
name|dpd
operator|<<
literal|2
argument_list|)
expr_stmt|;
name|bout
operator|--
expr_stmt|;
operator|*
name|bout
operator|=
call|(
name|uByte
call|)
argument_list|(
name|dpd
operator|>>
literal|6
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
operator|*
name|bout
operator||=
call|(
name|uByte
call|)
argument_list|(
name|dpd
operator|<<
literal|4
argument_list|)
expr_stmt|;
name|bout
operator|--
expr_stmt|;
operator|*
name|bout
operator|=
call|(
name|uByte
call|)
argument_list|(
name|dpd
operator|>>
literal|4
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
operator|*
name|bout
operator||=
call|(
name|uByte
call|)
argument_list|(
name|dpd
operator|<<
literal|6
argument_list|)
expr_stmt|;
name|bout
operator|--
expr_stmt|;
operator|*
name|bout
operator|=
call|(
name|uByte
call|)
argument_list|(
name|dpd
operator|>>
literal|2
argument_list|)
expr_stmt|;
name|bout
operator|--
expr_stmt|;
break|break;
block|}
comment|/* switch */
block|}
comment|/* n bunches */
return|return;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decDenseUnpackCoeff -- unpack a format's coefficient               */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   byte is the source's byte array                                  */
end_comment

begin_comment
comment|/*   len is length of the source's byte array                         */
end_comment

begin_comment
comment|/*   dn is the target number, with 7, 16, or 34-digit space.          */
end_comment

begin_comment
comment|/*   bunches is the count of DPD groups in the decNumber (2, 5, or 11)*/
end_comment

begin_comment
comment|/*   odd is 1 if there is a non-zero leading 10-bit group containing  */
end_comment

begin_comment
comment|/*     a single digit, 0 otherwise                                    */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* (This routine works on a copy of the number, if necessary, where   */
end_comment

begin_comment
comment|/* an extra 10-bit group is prefixed to the coefficient continuation  */
end_comment

begin_comment
comment|/* to hold the most significant digit if the latter is non-0.)        */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* dn->digits is set, but not the sign or exponent.                   */
end_comment

begin_comment
comment|/* No error is possible [the redundant 888 codes are allowed].        */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|void
name|decDenseUnpackCoeff
parameter_list|(
specifier|const
name|uByte
modifier|*
name|bytes
parameter_list|,
name|Int
name|len
parameter_list|,
name|decNumber
modifier|*
name|dn
parameter_list|,
name|Int
name|bunches
parameter_list|,
name|Int
name|odd
parameter_list|)
block|{
name|uInt
name|dpd
init|=
literal|0
decl_stmt|;
comment|/* collector for 10 bits */
name|Int
name|n
decl_stmt|;
comment|/* counter */
specifier|const
name|uByte
modifier|*
name|bin
decl_stmt|;
comment|/* -> current input byte */
name|Unit
modifier|*
name|uout
init|=
name|dn
operator|->
name|lsu
decl_stmt|;
comment|/* -> current output unit */
name|Unit
name|out
init|=
literal|0
decl_stmt|;
comment|/* accumulator */
name|Int
name|cut
init|=
literal|0
decl_stmt|;
comment|/* power of ten in current unit */
name|Unit
modifier|*
name|last
init|=
name|uout
decl_stmt|;
comment|/* will be unit containing msd */
if|#
directive|if
name|DECDPUN
operator|!=
literal|3
name|uInt
name|bcd
decl_stmt|;
comment|/* BCD result */
name|uInt
name|nibble
decl_stmt|;
comment|/* work */
endif|#
directive|endif
comment|/* Expand the densely-packed integer, right to left */
name|bin
operator|=
operator|&
name|bytes
index|[
name|len
operator|-
literal|1
index|]
expr_stmt|;
comment|/* next input byte to use */
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|bunches
operator|+
name|odd
condition|;
name|n
operator|++
control|)
block|{
comment|/* N bunches of 10 bits */
comment|/* assemble the 10 bits */
switch|switch
condition|(
name|n
operator|&
literal|0x03
condition|)
block|{
comment|/* phase 0-3 */
case|case
literal|0
case|:
name|dpd
operator|=
operator|*
name|bin
expr_stmt|;
name|bin
operator|--
expr_stmt|;
name|dpd
operator||=
operator|(
operator|*
name|bin
operator|&
literal|0x03
operator|)
operator|<<
literal|8
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|dpd
operator|=
operator|(
name|unsigned
operator|)
operator|*
name|bin
operator|>>
literal|2
expr_stmt|;
name|bin
operator|--
expr_stmt|;
name|dpd
operator||=
operator|(
operator|*
name|bin
operator|&
literal|0x0F
operator|)
operator|<<
literal|6
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|dpd
operator|=
operator|(
name|unsigned
operator|)
operator|*
name|bin
operator|>>
literal|4
expr_stmt|;
name|bin
operator|--
expr_stmt|;
name|dpd
operator||=
operator|(
operator|*
name|bin
operator|&
literal|0x3F
operator|)
operator|<<
literal|4
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|dpd
operator|=
operator|(
name|unsigned
operator|)
operator|*
name|bin
operator|>>
literal|6
expr_stmt|;
name|bin
operator|--
expr_stmt|;
name|dpd
operator||=
operator|(
operator|*
name|bin
operator|)
operator|<<
literal|2
expr_stmt|;
name|bin
operator|--
expr_stmt|;
break|break;
block|}
comment|/*switch */
if|#
directive|if
name|DECDPUN
operator|==
literal|3
if|if
condition|(
name|dpd
operator|==
literal|0
condition|)
operator|*
name|uout
operator|=
literal|0
expr_stmt|;
else|else
block|{
operator|*
name|uout
operator|=
name|DPD2BIN
index|[
name|dpd
index|]
expr_stmt|;
comment|/* convert 10 bits to binary 0-999 */
name|last
operator|=
name|uout
expr_stmt|;
comment|/* record most significant unit */
block|}
name|uout
operator|++
expr_stmt|;
else|#
directive|else
comment|/* DECDPUN!=3 */
if|if
condition|(
name|dpd
operator|==
literal|0
condition|)
block|{
comment|/* fastpath [e.g., leading zeros] */
name|cut
operator|+=
literal|3
expr_stmt|;
for|for
control|(
init|;
name|cut
operator|>=
name|DECDPUN
condition|;
control|)
block|{
name|cut
operator|-=
name|DECDPUN
expr_stmt|;
operator|*
name|uout
operator|=
name|out
expr_stmt|;
name|uout
operator|++
expr_stmt|;
name|out
operator|=
literal|0
expr_stmt|;
block|}
continue|continue;
block|}
name|bcd
operator|=
name|DPD2BCD
index|[
name|dpd
index|]
expr_stmt|;
comment|/* convert 10 bits to 12 bits BCD */
comment|/* now split the 3 BCD nibbles into bytes, and accumulate into units */
comment|/* If this is the last bunch and it is an odd one, we only have one */
comment|/* nibble to handle [extras could overflow a Unit] */
name|nibble
operator|=
name|bcd
operator|&
literal|0x000f
expr_stmt|;
if|if
condition|(
name|nibble
condition|)
block|{
name|last
operator|=
name|uout
expr_stmt|;
name|out
operator|=
call|(
name|Unit
call|)
argument_list|(
name|out
operator|+
name|nibble
operator|*
name|powers
index|[
name|cut
index|]
argument_list|)
expr_stmt|;
block|}
name|cut
operator|++
expr_stmt|;
if|if
condition|(
name|cut
operator|==
name|DECDPUN
condition|)
block|{
operator|*
name|uout
operator|=
name|out
expr_stmt|;
name|uout
operator|++
expr_stmt|;
name|cut
operator|=
literal|0
expr_stmt|;
name|out
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|n
operator|<
name|bunches
condition|)
block|{
name|nibble
operator|=
name|bcd
operator|&
literal|0x00f0
expr_stmt|;
if|if
condition|(
name|nibble
condition|)
block|{
name|nibble
operator|>>=
literal|4
expr_stmt|;
name|last
operator|=
name|uout
expr_stmt|;
name|out
operator|=
call|(
name|Unit
call|)
argument_list|(
name|out
operator|+
name|nibble
operator|*
name|powers
index|[
name|cut
index|]
argument_list|)
expr_stmt|;
block|}
name|cut
operator|++
expr_stmt|;
if|if
condition|(
name|cut
operator|==
name|DECDPUN
condition|)
block|{
operator|*
name|uout
operator|=
name|out
expr_stmt|;
name|uout
operator|++
expr_stmt|;
name|cut
operator|=
literal|0
expr_stmt|;
name|out
operator|=
literal|0
expr_stmt|;
block|}
name|nibble
operator|=
name|bcd
operator|&
literal|0x0f00
expr_stmt|;
if|if
condition|(
name|nibble
condition|)
block|{
name|nibble
operator|>>=
literal|8
expr_stmt|;
name|last
operator|=
name|uout
expr_stmt|;
name|out
operator|=
call|(
name|Unit
call|)
argument_list|(
name|out
operator|+
name|nibble
operator|*
name|powers
index|[
name|cut
index|]
argument_list|)
expr_stmt|;
block|}
name|cut
operator|++
expr_stmt|;
if|if
condition|(
name|cut
operator|==
name|DECDPUN
condition|)
block|{
operator|*
name|uout
operator|=
name|out
expr_stmt|;
name|uout
operator|++
expr_stmt|;
name|cut
operator|=
literal|0
expr_stmt|;
name|out
operator|=
literal|0
expr_stmt|;
block|}
block|}
endif|#
directive|endif
block|}
comment|/* n */
if|if
condition|(
name|cut
operator|!=
literal|0
condition|)
operator|*
name|uout
operator|=
name|out
expr_stmt|;
comment|/* write out final unit */
comment|/* here, last points to the most significant unit with digits */
comment|/* we need to inspect it to get final digits count */
name|dn
operator|->
name|digits
operator|=
operator|(
name|last
operator|-
name|dn
operator|->
name|lsu
operator|)
operator|*
name|DECDPUN
expr_stmt|;
comment|/* floor of digits */
for|for
control|(
name|cut
operator|=
literal|0
init|;
name|cut
operator|<
name|DECDPUN
condition|;
name|cut
operator|++
control|)
block|{
if|if
condition|(
operator|*
name|last
operator|<
name|powers
index|[
name|cut
index|]
condition|)
break|break;
name|dn
operator|->
name|digits
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|dn
operator|->
name|digits
operator|==
literal|0
condition|)
name|dn
operator|->
name|digits
operator|++
expr_stmt|;
comment|/* zero has one digit */
return|return;
block|}
end_function

end_unit

