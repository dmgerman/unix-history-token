begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* DO NOT EDIT! GENERATED AUTOMATICALLY! */
end_comment

begin_comment
comment|/* A substitute for ISO C11<stdnoreturn.h>.     Copyright 2012-2014 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU Lesser General Public License as published by    the Free Software Foundation; either version 2.1, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU Lesser General Public License for more details.     You should have received a copy of the GNU Lesser General Public License    along with this program; if not, see<http://www.gnu.org/licenses/>.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|noreturn
end_ifndef

begin_comment
comment|/* ISO C11<stdnoreturn.h> for platforms that lack it.     References:    ISO C11 (latest free draft<http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf>)    section 7.23 */
end_comment

begin_comment
comment|/* The definition of _Noreturn is copied here.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
specifier|_Noreturn
operator|&&
name|__STDC_VERSION__
operator|<
literal|201112
end_if

begin_if
if|#
directive|if
operator|(
literal|3
operator|<=
name|__GNUC__
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
literal|8
operator|<=
name|__GNUC_MINOR__
operator|)
expr|\
operator|||
literal|0x5110
operator|<=
name|__SUNPRO_C
operator|)
end_if

begin_define
define|#
directive|define
name|_Noreturn
value|__attribute__ ((__noreturn__))
end_define

begin_elif
elif|#
directive|elif
literal|1200
operator|<=
name|_MSC_VER
end_elif

begin_define
define|#
directive|define
name|_Noreturn
value|__declspec (noreturn)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_Noreturn
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|1200
operator|<=
name|_MSC_VER
end_if

begin_comment
comment|/* Standard include files on this platform contain declarations like    "__declspec (noreturn) void abort (void);".  "#define noreturn    _Noreturn" would cause this declaration to be rewritten to the    invalid "__declspec (__declspec (noreturn)) void abort (void);".    Instead, define noreturn to empty, so that such declarations are    rewritten to "__declspec () void abort (void);", which is    equivalent to "void abort (void);"; this gives up on noreturn's    advice to the compiler but at least it is valid code.  */
end_comment

begin_define
define|#
directive|define
name|noreturn
end_define

begin_comment
comment|/*empty*/
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|noreturn
value|_Noreturn
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Did he ever return?    No he never returned    And his fate is still unlearn'd ...      -- Steiner J, Hawes BL.  M.T.A. (1949)  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* noreturn */
end_comment

end_unit

