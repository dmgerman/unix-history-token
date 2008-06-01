begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Decimal 128-bit format module header for the decNumber C Library    Copyright (C) 2005 Free Software Foundation, Inc.    Contributed by IBM Corporation.  Author Mike Cowlishaw.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it under    the terms of the GNU General Public License as published by the Free    Software Foundation; either version 2, or (at your option) any later    version.     In addition to the permissions in the GNU General Public License,    the Free Software Foundation gives you unlimited permission to link    the compiled version of this file into combinations with other    programs, and to distribute those combinations without any    restriction coming from the use of this file.  (The General Public    License restrictions do apply in other respects; for example, they    cover modification of the file, and distribution when not linked    into a combine executable.)     GCC is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DECIMAL128
argument_list|)
end_if

begin_define
define|#
directive|define
name|DECIMAL128
end_define

begin_define
define|#
directive|define
name|DEC128NAME
value|"decimal128"
end_define

begin_comment
comment|/* Short name */
end_comment

begin_define
define|#
directive|define
name|DEC128FULLNAME
value|"Decimal 128-bit Number"
end_define

begin_comment
comment|/* Verbose name */
end_comment

begin_define
define|#
directive|define
name|DEC128AUTHOR
value|"Mike Cowlishaw"
end_define

begin_comment
comment|/* Who to blame */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DECIMAL32
argument_list|)
end_if

begin_error
error|#
directive|error
error|decimal128.h must precede decimal32.h for correct DECNUMDIGITS
end_error

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DECIMAL64
argument_list|)
end_if

begin_error
error|#
directive|error
error|decimal128.h must precede decimal64.h for correct DECNUMDIGITS
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* parameters for decimal128s */
end_comment

begin_define
define|#
directive|define
name|DECIMAL128_Bytes
value|16
end_define

begin_comment
comment|/* length */
end_comment

begin_define
define|#
directive|define
name|DECIMAL128_Pmax
value|34
end_define

begin_comment
comment|/* maximum precision (digits) */
end_comment

begin_define
define|#
directive|define
name|DECIMAL128_Emax
value|6144
end_define

begin_comment
comment|/* maximum adjusted exponent */
end_comment

begin_define
define|#
directive|define
name|DECIMAL128_Emin
value|-6143
end_define

begin_comment
comment|/* minimum adjusted exponent */
end_comment

begin_define
define|#
directive|define
name|DECIMAL128_Bias
value|6176
end_define

begin_comment
comment|/* bias for the exponent */
end_comment

begin_define
define|#
directive|define
name|DECIMAL128_String
value|43
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
name|DECIMAL128_Ehigh
value|(DECIMAL128_Emax+DECIMAL128_Bias-DECIMAL128_Pmax+1)
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
value|DECIMAL128_Pmax
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
comment|/* Decimal 128-bit type, accessible by bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|bytes
index|[
name|DECIMAL128_Bytes
index|]
decl_stmt|;
comment|/* decimal128: 1, 5, 12, 110 bits */
block|}
name|decimal128
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
comment|/* Macros for accessing decimal128 fields.  These assume the argument      is a reference (pointer) to the decimal128 structure */
end_comment

begin_comment
comment|/* Get sign */
end_comment

begin_define
define|#
directive|define
name|decimal128Sign
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
name|decimal128Comb
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
name|decimal128ExpCon
parameter_list|(
name|d
parameter_list|)
value|((((d)->bytes[0]& 0x03)<<10)       \                                 | ((unsigned)(d)->bytes[1]<<2)        \                                 | ((unsigned)(d)->bytes[2]>>6))
end_define

begin_comment
comment|/* Set sign [this assumes sign previously 0] */
end_comment

begin_define
define|#
directive|define
name|decimal128SetSign
parameter_list|(
name|d
parameter_list|,
name|b
parameter_list|)
value|{                                   \     (d)->bytes[0]|=((unsigned)(b)<<7);}
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
name|decimal128SetExpCon
parameter_list|(
name|d
parameter_list|,
name|e
parameter_list|)
value|{                                 \     (d)->bytes[0]|=(uint8_t)((e)>>10);                                \     (d)->bytes[1] =(uint8_t)(((e)&0x3fc)>>2);                         \     (d)->bytes[2]|=(uint8_t)(((e)&0x03)<<6);}
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
name|decimal128FromString
value|__decimal128FromString
end_define

begin_define
define|#
directive|define
name|decimal128ToString
value|__decimal128ToString
end_define

begin_define
define|#
directive|define
name|decimal128ToEngString
value|__decimal128ToEngString
end_define

begin_define
define|#
directive|define
name|decimal128FromNumber
value|__decimal128FromNumber
end_define

begin_define
define|#
directive|define
name|decimal128ToNumber
value|__decimal128ToNumber
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* String conversions */
end_comment

begin_function_decl
name|decimal128
modifier|*
name|decimal128FromString
parameter_list|(
name|decimal128
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
name|decimal128ToString
parameter_list|(
specifier|const
name|decimal128
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
name|decimal128ToEngString
parameter_list|(
specifier|const
name|decimal128
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* decNumber conversions */
end_comment

begin_function_decl
name|decimal128
modifier|*
name|decimal128FromNumber
parameter_list|(
name|decimal128
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
name|decimal128ToNumber
parameter_list|(
specifier|const
name|decimal128
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

