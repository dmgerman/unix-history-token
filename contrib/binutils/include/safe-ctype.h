begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*<ctype.h> replacement macros.     Copyright (C) 2000, 2001 Free Software Foundation, Inc.    Contributed by Zack Weinberg<zackw@stanford.edu>.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This is a compatible replacement of the standard C library's<ctype.h>    with the following properties:     - Implements all isxxx() macros required by C99.    - Also implements some character classes useful when      parsing C-like languages.    - Does not change behavior depending on the current locale.    - Behaves properly for all values in the range of a signed or      unsigned char.     To avoid conflicts, this header defines the isxxx functions in upper    case, e.g. ISALPHA not isalpha.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SAFE_CTYPE_H
end_ifndef

begin_define
define|#
directive|define
name|SAFE_CTYPE_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|isalpha
end_ifdef

begin_error
error|#
directive|error
literal|"safe-ctype.h and ctype.h may not be used simultaneously"
end_error

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Categories.  */
end_comment

begin_enum
enum|enum
block|{
comment|/* In C99 */
name|_sch_isblank
init|=
literal|0x0001
block|,
comment|/* space \t */
name|_sch_iscntrl
init|=
literal|0x0002
block|,
comment|/* nonprinting characters */
name|_sch_isdigit
init|=
literal|0x0004
block|,
comment|/* 0-9 */
name|_sch_islower
init|=
literal|0x0008
block|,
comment|/* a-z */
name|_sch_isprint
init|=
literal|0x0010
block|,
comment|/* any printing character including ' ' */
name|_sch_ispunct
init|=
literal|0x0020
block|,
comment|/* all punctuation */
name|_sch_isspace
init|=
literal|0x0040
block|,
comment|/* space \t \n \r \f \v */
name|_sch_isupper
init|=
literal|0x0080
block|,
comment|/* A-Z */
name|_sch_isxdigit
init|=
literal|0x0100
block|,
comment|/* 0-9A-Fa-f */
comment|/* Extra categories useful to cpplib.  */
name|_sch_isidst
init|=
literal|0x0200
block|,
comment|/* A-Za-z_ */
name|_sch_isvsp
init|=
literal|0x0400
block|,
comment|/* \n \r */
name|_sch_isnvsp
init|=
literal|0x0800
block|,
comment|/* space \t \f \v \0 */
comment|/* Combinations of the above.  */
name|_sch_isalpha
init|=
name|_sch_isupper
operator||
name|_sch_islower
block|,
comment|/* A-Za-z */
name|_sch_isalnum
init|=
name|_sch_isalpha
operator||
name|_sch_isdigit
block|,
comment|/* A-Za-z0-9 */
name|_sch_isidnum
init|=
name|_sch_isidst
operator||
name|_sch_isdigit
block|,
comment|/* A-Za-z0-9_ */
name|_sch_isgraph
init|=
name|_sch_isalnum
operator||
name|_sch_ispunct
block|,
comment|/* isprint and not space */
name|_sch_iscppsp
init|=
name|_sch_isvsp
operator||
name|_sch_isnvsp
comment|/* isspace + \0 */
block|}
enum|;
end_enum

begin_comment
comment|/* Character classification.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|short
name|_sch_istable
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|_sch_test
parameter_list|(
name|c
parameter_list|,
name|bit
parameter_list|)
value|(_sch_istable[(c)& 0xff]& (bit))
end_define

begin_define
define|#
directive|define
name|ISALPHA
parameter_list|(
name|c
parameter_list|)
value|_sch_test(c, _sch_isalpha)
end_define

begin_define
define|#
directive|define
name|ISALNUM
parameter_list|(
name|c
parameter_list|)
value|_sch_test(c, _sch_isalnum)
end_define

begin_define
define|#
directive|define
name|ISBLANK
parameter_list|(
name|c
parameter_list|)
value|_sch_test(c, _sch_isblank)
end_define

begin_define
define|#
directive|define
name|ISCNTRL
parameter_list|(
name|c
parameter_list|)
value|_sch_test(c, _sch_iscntrl)
end_define

begin_define
define|#
directive|define
name|ISDIGIT
parameter_list|(
name|c
parameter_list|)
value|_sch_test(c, _sch_isdigit)
end_define

begin_define
define|#
directive|define
name|ISGRAPH
parameter_list|(
name|c
parameter_list|)
value|_sch_test(c, _sch_isgraph)
end_define

begin_define
define|#
directive|define
name|ISLOWER
parameter_list|(
name|c
parameter_list|)
value|_sch_test(c, _sch_islower)
end_define

begin_define
define|#
directive|define
name|ISPRINT
parameter_list|(
name|c
parameter_list|)
value|_sch_test(c, _sch_isprint)
end_define

begin_define
define|#
directive|define
name|ISPUNCT
parameter_list|(
name|c
parameter_list|)
value|_sch_test(c, _sch_ispunct)
end_define

begin_define
define|#
directive|define
name|ISSPACE
parameter_list|(
name|c
parameter_list|)
value|_sch_test(c, _sch_isspace)
end_define

begin_define
define|#
directive|define
name|ISUPPER
parameter_list|(
name|c
parameter_list|)
value|_sch_test(c, _sch_isupper)
end_define

begin_define
define|#
directive|define
name|ISXDIGIT
parameter_list|(
name|c
parameter_list|)
value|_sch_test(c, _sch_isxdigit)
end_define

begin_define
define|#
directive|define
name|ISIDNUM
parameter_list|(
name|c
parameter_list|)
value|_sch_test(c, _sch_isidnum)
end_define

begin_define
define|#
directive|define
name|ISIDST
parameter_list|(
name|c
parameter_list|)
value|_sch_test(c, _sch_isidst)
end_define

begin_define
define|#
directive|define
name|IS_VSPACE
parameter_list|(
name|c
parameter_list|)
value|_sch_test(c, _sch_isvsp)
end_define

begin_define
define|#
directive|define
name|IS_NVSPACE
parameter_list|(
name|c
parameter_list|)
value|_sch_test(c, _sch_isnvsp)
end_define

begin_define
define|#
directive|define
name|IS_SPACE_OR_NUL
parameter_list|(
name|c
parameter_list|)
value|_sch_test(c, _sch_iscppsp)
end_define

begin_comment
comment|/* Character transformation.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|_sch_toupper
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|_sch_tolower
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TOUPPER
parameter_list|(
name|c
parameter_list|)
value|_sch_toupper[(c)& 0xff]
end_define

begin_define
define|#
directive|define
name|TOLOWER
parameter_list|(
name|c
parameter_list|)
value|_sch_tolower[(c)& 0xff]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no ctype.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SAFE_CTYPE_H */
end_comment

end_unit

