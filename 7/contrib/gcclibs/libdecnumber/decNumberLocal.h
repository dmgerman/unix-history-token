begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* decNumber package local type, tuning, and macro definitions.    Copyright (C) 2005 Free Software Foundation, Inc.    Contributed by IBM Corporation.  Author Mike Cowlishaw.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it under    the terms of the GNU General Public License as published by the Free    Software Foundation; either version 2, or (at your option) any later    version.     In addition to the permissions in the GNU General Public License,    the Free Software Foundation gives you unlimited permission to link    the compiled version of this file into combinations with other    programs, and to distribute those combinations without any    restriction coming from the use of this file.  (The General Public    License restrictions do apply in other respects; for example, they    cover modification of the file, and distribution when not linked    into a combine executable.)     GCC is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* This header file is included by all modules in the decNumber       */
end_comment

begin_comment
comment|/* library, and contains local type definitions, tuning parameters,   */
end_comment

begin_comment
comment|/* etc.  It must only be included once, and should not need to be     */
end_comment

begin_comment
comment|/* used by application programs.  decNumber.h must be included first. */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DECNUMBERLOC
argument_list|)
end_if

begin_define
define|#
directive|define
name|DECNUMBERLOC
end_define

begin_define
define|#
directive|define
name|DECNLAUTHOR
value|"Mike Cowlishaw"
end_define

begin_comment
comment|/* Who to blame */
end_comment

begin_comment
comment|/* Local names for common types -- decNumber modules do not use int or      long directly */
end_comment

begin_define
define|#
directive|define
name|Flag
value|uint8_t
end_define

begin_define
define|#
directive|define
name|Byte
value|int8_t
end_define

begin_define
define|#
directive|define
name|uByte
value|uint8_t
end_define

begin_define
define|#
directive|define
name|Short
value|int16_t
end_define

begin_define
define|#
directive|define
name|uShort
value|uint16_t
end_define

begin_define
define|#
directive|define
name|Int
value|int32_t
end_define

begin_define
define|#
directive|define
name|uInt
value|uint32_t
end_define

begin_define
define|#
directive|define
name|Unit
value|decNumberUnit
end_define

begin_comment
comment|/* Tuning parameter */
end_comment

begin_define
define|#
directive|define
name|DECBUFFER
value|36
end_define

begin_comment
comment|/* Maximum size basis for local buffers. */
end_comment

begin_comment
comment|/* Should be a common maximum precision */
end_comment

begin_comment
comment|/* rounded up to a multiple of 4; must */
end_comment

begin_comment
comment|/* be non-negative. */
end_comment

begin_comment
comment|/* Conditional code flags -- set these to 0 for best performance */
end_comment

begin_define
define|#
directive|define
name|DECCHECK
value|0
end_define

begin_comment
comment|/* 1 to enable robust checking */
end_comment

begin_define
define|#
directive|define
name|DECALLOC
value|0
end_define

begin_comment
comment|/* 1 to enable memory allocation accounting */
end_comment

begin_define
define|#
directive|define
name|DECTRACE
value|0
end_define

begin_comment
comment|/* 1 to trace critical intermediates, etc. */
end_comment

begin_comment
comment|/* Development use defines */
end_comment

begin_if
if|#
directive|if
name|DECALLOC
end_if

begin_comment
comment|/* if these interfere with your C includes, just comment them out */
end_comment

begin_define
define|#
directive|define
name|int
value|?
end_define

begin_comment
comment|/* enable to ensure we do not use plain C */
end_comment

begin_define
define|#
directive|define
name|long
value|??
end_define

begin_comment
comment|/* .. 'int' or 'long' types from here on */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Limits and constants */
end_comment

begin_define
define|#
directive|define
name|DECNUMMAXP
value|999999999
end_define

begin_comment
comment|/* maximum precision we can handle (9 digits) */
end_comment

begin_define
define|#
directive|define
name|DECNUMMAXE
value|999999999
end_define

begin_comment
comment|/* maximum adjusted exponent ditto (9 digits) */
end_comment

begin_define
define|#
directive|define
name|DECNUMMINE
value|-999999999
end_define

begin_comment
comment|/* minimum adjusted exponent ditto (9 digits) */
end_comment

begin_if
if|#
directive|if
operator|(
name|DECNUMMAXP
operator|!=
name|DEC_MAX_DIGITS
operator|)
end_if

begin_error
error|#
directive|error
error|Maximum digits mismatch
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|DECNUMMAXE
operator|!=
name|DEC_MAX_EMAX
operator|)
end_if

begin_error
error|#
directive|error
error|Maximum exponent mismatch
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|DECNUMMINE
operator|!=
name|DEC_MIN_EMIN
operator|)
end_if

begin_error
error|#
directive|error
error|Minimum exponent mismatch
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set DECDPUNMAX -- the maximum integer that fits in DECDPUN digits */
end_comment

begin_if
if|#
directive|if
name|DECDPUN
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|DECDPUNMAX
value|9
end_define

begin_elif
elif|#
directive|elif
name|DECDPUN
operator|==
literal|2
end_elif

begin_define
define|#
directive|define
name|DECDPUNMAX
value|99
end_define

begin_elif
elif|#
directive|elif
name|DECDPUN
operator|==
literal|3
end_elif

begin_define
define|#
directive|define
name|DECDPUNMAX
value|999
end_define

begin_elif
elif|#
directive|elif
name|DECDPUN
operator|==
literal|4
end_elif

begin_define
define|#
directive|define
name|DECDPUNMAX
value|9999
end_define

begin_elif
elif|#
directive|elif
name|DECDPUN
operator|==
literal|5
end_elif

begin_define
define|#
directive|define
name|DECDPUNMAX
value|99999
end_define

begin_elif
elif|#
directive|elif
name|DECDPUN
operator|==
literal|6
end_elif

begin_define
define|#
directive|define
name|DECDPUNMAX
value|999999
end_define

begin_elif
elif|#
directive|elif
name|DECDPUN
operator|==
literal|7
end_elif

begin_define
define|#
directive|define
name|DECDPUNMAX
value|9999999
end_define

begin_elif
elif|#
directive|elif
name|DECDPUN
operator|==
literal|8
end_elif

begin_define
define|#
directive|define
name|DECDPUNMAX
value|99999999
end_define

begin_elif
elif|#
directive|elif
name|DECDPUN
operator|==
literal|9
end_elif

begin_define
define|#
directive|define
name|DECDPUNMAX
value|999999999
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|DECDPUN
argument_list|)
end_elif

begin_error
error|#
directive|error
error|DECDPUN must be in the range 1-9
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ----- Shared data ----- */
end_comment

begin_comment
comment|/* The powers of of ten array (powers[n]==10**n, 0<=n<=10) */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|uInt
name|powers
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ----- Macros ----- */
end_comment

begin_comment
comment|/* ISZERO -- return true if decNumber dn is a zero */
end_comment

begin_comment
comment|/* [performance-critical in some situations] */
end_comment

begin_define
define|#
directive|define
name|ISZERO
parameter_list|(
name|dn
parameter_list|)
value|decNumberIsZero(dn)
end_define

begin_comment
comment|/* now just a local name */
end_comment

begin_comment
comment|/* X10 and X100 -- multiply integer i by 10 or 100 */
end_comment

begin_comment
comment|/* [shifts are usually faster than multiply; could be conditional] */
end_comment

begin_define
define|#
directive|define
name|X10
parameter_list|(
name|i
parameter_list|)
value|(((i)<<1)+((i)<<3))
end_define

begin_define
define|#
directive|define
name|X100
parameter_list|(
name|i
parameter_list|)
value|(((i)<<2)+((i)<<5)+((i)<<6))
end_define

begin_comment
comment|/* D2U -- return the number of Units needed to hold d digits */
end_comment

begin_if
if|#
directive|if
name|DECDPUN
operator|==
literal|8
end_if

begin_define
define|#
directive|define
name|D2U
parameter_list|(
name|d
parameter_list|)
value|((unsigned)((d)+7)>>3)
end_define

begin_elif
elif|#
directive|elif
name|DECDPUN
operator|==
literal|4
end_elif

begin_define
define|#
directive|define
name|D2U
parameter_list|(
name|d
parameter_list|)
value|((unsigned)((d)+3)>>2)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|D2U
parameter_list|(
name|d
parameter_list|)
value|(((d)+DECDPUN-1)/DECDPUN)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|decNumberLocal included more than once
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

