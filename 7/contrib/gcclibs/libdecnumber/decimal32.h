begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Decimal 32-bit format module header for the decNumber C Library    Copyright (C) 2005 Free Software Foundation, Inc.    Contributed by IBM Corporation.  Author Mike Cowlishaw.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it under    the terms of the GNU General Public License as published by the Free    Software Foundation; either version 2, or (at your option) any later    version.     In addition to the permissions in the GNU General Public License,    the Free Software Foundation gives you unlimited permission to link    the compiled version of this file into combinations with other    programs, and to distribute those combinations without any    restriction coming from the use of this file.  (The General Public    License restrictions do apply in other respects; for example, they    cover modification of the file, and distribution when not linked    into a combine executable.)     GCC is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DECIMAL32
argument_list|)
end_if

begin_define
define|#
directive|define
name|DECIMAL32
end_define

begin_define
define|#
directive|define
name|DEC32NAME
value|"decimal32"
end_define

begin_comment
comment|/* Short name */
end_comment

begin_define
define|#
directive|define
name|DEC32FULLNAME
value|"Decimal 32-bit Number"
end_define

begin_comment
comment|/* Verbose name */
end_comment

begin_define
define|#
directive|define
name|DEC32AUTHOR
value|"Mike Cowlishaw"
end_define

begin_comment
comment|/* Who to blame */
end_comment

begin_comment
comment|/* parameters for decimal32s */
end_comment

begin_define
define|#
directive|define
name|DECIMAL32_Bytes
value|4
end_define

begin_comment
comment|/* length */
end_comment

begin_define
define|#
directive|define
name|DECIMAL32_Pmax
value|7
end_define

begin_comment
comment|/* maximum precision (digits) */
end_comment

begin_define
define|#
directive|define
name|DECIMAL32_Emax
value|96
end_define

begin_comment
comment|/* maximum adjusted exponent */
end_comment

begin_define
define|#
directive|define
name|DECIMAL32_Emin
value|-95
end_define

begin_comment
comment|/* minimum adjusted exponent */
end_comment

begin_define
define|#
directive|define
name|DECIMAL32_Bias
value|101
end_define

begin_comment
comment|/* bias for the exponent */
end_comment

begin_define
define|#
directive|define
name|DECIMAL32_String
value|15
end_define

begin_comment
comment|/* maximum string length, +1 */
end_comment

begin_comment
comment|/* highest biased exponent (Elimit-1) */
end_comment

begin_define
define|#
directive|define
name|DECIMAL32_Ehigh
value|(DECIMAL32_Emax+DECIMAL32_Bias-DECIMAL32_Pmax+1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DECNUMDIGITS
end_ifndef

begin_define
define|#
directive|define
name|DECNUMDIGITS
value|DECIMAL32_Pmax
end_define

begin_comment
comment|/* size if not already defined */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DECNUMBER
end_ifndef

begin_include
include|#
directive|include
file|"decNumber.h"
end_include

begin_comment
comment|/* context and number library */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Decimal 32-bit type, accessible by bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|bytes
index|[
name|DECIMAL32_Bytes
index|]
decl_stmt|;
comment|/* decimal32: 1, 5, 6, 20 bits */
block|}
name|decimal32
typedef|;
end_typedef

begin_comment
comment|/* special values [top byte excluding sign bit; last two bits are      don't-care for Infinity on input, last bit don't-care for NaN] */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DECIMAL_NaN
argument_list|)
end_if

begin_define
define|#
directive|define
name|DECIMAL_NaN
value|0x7c
end_define

begin_comment
comment|/* 0 11111 00 NaN */
end_comment

begin_define
define|#
directive|define
name|DECIMAL_sNaN
value|0x7e
end_define

begin_comment
comment|/* 0 11111 10 sNaN */
end_comment

begin_define
define|#
directive|define
name|DECIMAL_Inf
value|0x78
end_define

begin_comment
comment|/* 0 11110 00 Infinity */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Macros for accessing decimal32 fields.  These assume the argument      is a reference (pointer) to the decimal32 structure */
end_comment

begin_comment
comment|/* Get sign */
end_comment

begin_define
define|#
directive|define
name|decimal32Sign
parameter_list|(
name|d
parameter_list|)
value|((unsigned)(d)->bytes[0]>>7)
end_define

begin_comment
comment|/* Get combination field */
end_comment

begin_define
define|#
directive|define
name|decimal32Comb
parameter_list|(
name|d
parameter_list|)
value|(((d)->bytes[0]& 0x7c)>>2)
end_define

begin_comment
comment|/* Get exponent continuation [does not remove bias] */
end_comment

begin_define
define|#
directive|define
name|decimal32ExpCon
parameter_list|(
name|d
parameter_list|)
value|((((d)->bytes[0]& 0x03)<<4)         \                                | ((unsigned)(d)->bytes[1]>>4))
end_define

begin_comment
comment|/* Set sign [this assumes sign previously 0] */
end_comment

begin_define
define|#
directive|define
name|decimal32SetSign
parameter_list|(
name|d
parameter_list|,
name|b
parameter_list|)
value|{                                    \     (d)->bytes[0]|=((unsigned)(b)<<7);}
end_define

begin_comment
comment|/* Set exponent continuation [does not apply bias] */
end_comment

begin_comment
comment|/* This assumes range has been checked and exponent previously 0; */
end_comment

begin_comment
comment|/* type of exponent must be unsigned */
end_comment

begin_define
define|#
directive|define
name|decimal32SetExpCon
parameter_list|(
name|d
parameter_list|,
name|e
parameter_list|)
value|{                                  \     (d)->bytes[0]|=(uint8_t)((e)>>4);                                 \     (d)->bytes[1]|=(uint8_t)(((e)&0x0F)<<4);}
end_define

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Routines                                                           */
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
name|decimal32FromString
value|__decimal32FromString
end_define

begin_define
define|#
directive|define
name|decimal32ToString
value|__decimal32ToString
end_define

begin_define
define|#
directive|define
name|decimal32ToEngString
value|__decimal32ToEngString
end_define

begin_define
define|#
directive|define
name|decimal32FromNumber
value|__decimal32FromNumber
end_define

begin_define
define|#
directive|define
name|decimal32ToNumber
value|__decimal32ToNumber
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* String conversions.  */
end_comment

begin_function_decl
name|decimal32
modifier|*
name|decimal32FromString
parameter_list|(
name|decimal32
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
name|decimal32ToString
parameter_list|(
specifier|const
name|decimal32
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
name|decimal32ToEngString
parameter_list|(
specifier|const
name|decimal32
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* decNumber conversions.  */
end_comment

begin_function_decl
name|decimal32
modifier|*
name|decimal32FromNumber
parameter_list|(
name|decimal32
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
name|decimal32ToNumber
parameter_list|(
specifier|const
name|decimal32
modifier|*
parameter_list|,
name|decNumber
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

