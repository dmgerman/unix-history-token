begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This code is derived from software copyrighted by the Free Software  * Foundation.  *  * Modified 1991 by Donn Seeley at UUNET Technologies, Inc.  *  *	@(#)lib.h	6.4 (Berkeley) 5/8/91  */
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1990 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.uucp)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file LICENSE.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_comment
comment|/* This file is included in both C and C++ compilations. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
comment|// const char *strerror(int);
comment|// const char *itoa(int);
comment|// const char *iftoa(int, int);
block|}
end_extern

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|const
name|char
modifier|*
name|itoa
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|iftoa
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strsave
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|interpret_lf_args
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|inline
name|int
name|illegal_input_char
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|c
operator|==
literal|000
operator|||
operator|(
name|c
operator|>
literal|012
operator|&&
name|c
operator|<
literal|040
operator|)
operator|||
operator|(
name|c
operator|>=
literal|0200
operator|&&
name|c
operator|<
literal|0240
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INT_MAX
end_ifndef

begin_define
define|#
directive|define
name|INT_MAX
value|2147483647
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* It's not safe to rely on people getting INT_MIN right (ie signed). */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INT_MIN
end_ifdef

begin_undef
undef|#
directive|undef
name|INT_MIN
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CFRONT_ANSI_BUG
end_ifdef

begin_comment
comment|/* This works around a bug in cfront 2.0 used with ANSI C compilers. */
end_comment

begin_define
define|#
directive|define
name|INT_MIN
value|((long)(-INT_MAX-1))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CFRONT_ANSI_BUG */
end_comment

begin_define
define|#
directive|define
name|INT_MIN
value|(-INT_MAX-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CFRONT_ANSI_BUG */
end_comment

begin_comment
comment|/* Maximum number of digits in the decimal representation of an int (not including the -). */
end_comment

begin_define
define|#
directive|define
name|INT_DIGITS
value|10
end_define

begin_comment
comment|/* From the old GNU math.h; does some standard actually require these? */
end_comment

begin_define
define|#
directive|define
name|M_E
value|2.7182818284590452354
end_define

begin_define
define|#
directive|define
name|M_LOG2E
value|1.4426950408889634074
end_define

begin_define
define|#
directive|define
name|M_LOG10E
value|0.43429448190325182765
end_define

begin_define
define|#
directive|define
name|M_LN2
value|0.69314718055994530942
end_define

begin_define
define|#
directive|define
name|M_LN10
value|2.30258509299404568402
end_define

begin_define
define|#
directive|define
name|M_PI
value|3.14159265358979323846
end_define

begin_define
define|#
directive|define
name|M_PI_2
value|1.57079632679489661923
end_define

begin_define
define|#
directive|define
name|M_1_PI
value|0.31830988618379067154
end_define

begin_define
define|#
directive|define
name|M_PI_4
value|0.78539816339744830962
end_define

begin_define
define|#
directive|define
name|M_2_PI
value|0.63661977236758134308
end_define

begin_define
define|#
directive|define
name|M_2_SQRTPI
value|1.12837916709551257390
end_define

begin_define
define|#
directive|define
name|M_SQRT2
value|1.41421356237309504880
end_define

begin_define
define|#
directive|define
name|M_SQRT1_2
value|0.70710678118654752440
end_define

begin_define
define|#
directive|define
name|PI
value|M_PI
end_define

begin_define
define|#
directive|define
name|PI2
value|M_PI_2
end_define

end_unit

