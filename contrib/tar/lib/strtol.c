begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Convert string representation of a number into an integer value.    Copyright (C) 1991, 92, 94, 95, 96, 97, 98, 99 Free Software Foundation, Inc.    NOTE: The canonical source of this file is maintained with the GNU C    Library.  Bugs can be reported to bug-glibc@gnu.org.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by the    Free Software Foundation; either version 2, or (at your option) any    later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_define
define|#
directive|define
name|USE_NUMBER_GROUPING
end_define

begin_define
define|#
directive|define
name|STDC_HEADERS
end_define

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|errno
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__set_errno
end_ifndef

begin_define
define|#
directive|define
name|__set_errno
parameter_list|(
name|Val
parameter_list|)
value|errno = (Val)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIMITS_H
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|STDC_HEADERS
end_ifdef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_NUMBER_GROUPING
end_ifdef

begin_include
include|#
directive|include
file|"../locale/localeinfo.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Nonzero if we are defining `strtoul' or `strtoull', operating on    unsigned integers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNSIGNED
end_ifndef

begin_define
define|#
directive|define
name|UNSIGNED
value|0
end_define

begin_define
define|#
directive|define
name|INT
value|LONG int
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INT
value|unsigned LONG int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Determine the name.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_IN_EXTENDED_LOCALE_MODEL
end_ifdef

begin_if
if|#
directive|if
name|UNSIGNED
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|USE_WIDE_CHAR
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|QUAD
end_ifdef

begin_define
define|#
directive|define
name|strtol
value|__wcstoull_l
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|strtol
value|__wcstoul_l
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|QUAD
end_ifdef

begin_define
define|#
directive|define
name|strtol
value|__strtoull_l
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|strtol
value|__strtoul_l
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|USE_WIDE_CHAR
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|QUAD
end_ifdef

begin_define
define|#
directive|define
name|strtol
value|__wcstoll_l
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|strtol
value|__wcstol_l
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|QUAD
end_ifdef

begin_define
define|#
directive|define
name|strtol
value|__strtoll_l
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|strtol
value|__strtol_l
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|UNSIGNED
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|USE_WIDE_CHAR
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|QUAD
end_ifdef

begin_define
define|#
directive|define
name|strtol
value|wcstoull
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|strtol
value|wcstoul
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|QUAD
end_ifdef

begin_define
define|#
directive|define
name|strtol
value|strtoull
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|strtol
value|strtoul
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|USE_WIDE_CHAR
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|QUAD
end_ifdef

begin_define
define|#
directive|define
name|strtol
value|wcstoll
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|strtol
value|wcstol
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|QUAD
end_ifdef

begin_define
define|#
directive|define
name|strtol
value|strtoll
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If QUAD is defined, we are defining `strtoll' or `strtoull',    operating on `long long int's.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|QUAD
end_ifdef

begin_define
define|#
directive|define
name|LONG
value|long long
end_define

begin_define
define|#
directive|define
name|STRTOL_LONG_MIN
value|LONG_LONG_MIN
end_define

begin_define
define|#
directive|define
name|STRTOL_LONG_MAX
value|LONG_LONG_MAX
end_define

begin_define
define|#
directive|define
name|STRTOL_ULONG_MAX
value|ULONG_LONG_MAX
end_define

begin_comment
comment|/* The extra casts work around common compiler bugs,    e.g. Cray C 5.0.3.0 when t == time_t.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_SIGNED
end_ifndef

begin_define
define|#
directive|define
name|TYPE_SIGNED
parameter_list|(
name|t
parameter_list|)
value|(! ((t) 0< (t) -1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_MINIMUM
end_ifndef

begin_define
define|#
directive|define
name|TYPE_MINIMUM
parameter_list|(
name|t
parameter_list|)
value|((t) (TYPE_SIGNED (t) \ 				? ~ (t) 0<< (sizeof (t) * CHAR_BIT - 1) \ 				: (t) 0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_MAXIMUM
end_ifndef

begin_define
define|#
directive|define
name|TYPE_MAXIMUM
parameter_list|(
name|t
parameter_list|)
value|((t) (~ (t) 0 - TYPE_MINIMUM (t)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ULONG_LONG_MAX
end_ifndef

begin_define
define|#
directive|define
name|ULONG_LONG_MAX
value|TYPE_MAXIMUM (unsigned long long)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LONG_LONG_MAX
end_ifndef

begin_define
define|#
directive|define
name|LONG_LONG_MAX
value|TYPE_MAXIMUM (long long int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LONG_LONG_MIN
end_ifndef

begin_define
define|#
directive|define
name|LONG_LONG_MIN
value|TYPE_MINIMUM (long long int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|7
end_if

begin_comment
comment|/* Work around gcc bug with using this constant.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|long
name|long
name|int
name|maxquad
init|=
name|ULONG_LONG_MAX
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|STRTOL_ULONG_MAX
end_undef

begin_define
define|#
directive|define
name|STRTOL_ULONG_MAX
value|maxquad
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LONG
value|long
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ULONG_MAX
end_ifndef

begin_define
define|#
directive|define
name|ULONG_MAX
value|((unsigned long) ~(unsigned long) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LONG_MAX
end_ifndef

begin_define
define|#
directive|define
name|LONG_MAX
value|((long int) (ULONG_MAX>> 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STRTOL_LONG_MIN
value|LONG_MIN
end_define

begin_define
define|#
directive|define
name|STRTOL_LONG_MAX
value|LONG_MAX
end_define

begin_define
define|#
directive|define
name|STRTOL_ULONG_MAX
value|ULONG_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We use this code also for the extended locale handling where the    function gets as an additional argument the locale which has to be    used.  To access the values we have to redefine the _NL_CURRENT    macro.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_IN_EXTENDED_LOCALE_MODEL
end_ifdef

begin_undef
undef|#
directive|undef
name|_NL_CURRENT
end_undef

begin_define
define|#
directive|define
name|_NL_CURRENT
parameter_list|(
name|category
parameter_list|,
name|item
parameter_list|)
define|\
value|(current->values[_NL_ITEM_INDEX (item)].string)
end_define

begin_define
define|#
directive|define
name|LOCALE_PARAM
value|, loc
end_define

begin_define
define|#
directive|define
name|LOCALE_PARAM_DECL
value|__locale_t loc;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOCALE_PARAM
end_define

begin_define
define|#
directive|define
name|LOCALE_PARAM_DECL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
name|_LIBC
operator|||
name|defined
name|HAVE_WCHAR_H
end_if

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_WIDE_CHAR
end_ifdef

begin_include
include|#
directive|include
file|<wctype.h>
end_include

begin_define
define|#
directive|define
name|L_
parameter_list|(
name|Ch
parameter_list|)
value|L##Ch
end_define

begin_define
define|#
directive|define
name|UCHAR_TYPE
value|wint_t
end_define

begin_define
define|#
directive|define
name|STRING_TYPE
value|wchar_t
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_IN_EXTENDED_LOCALE_MODEL
end_ifdef

begin_define
define|#
directive|define
name|ISSPACE
parameter_list|(
name|Ch
parameter_list|)
value|__iswspace_l ((Ch), loc)
end_define

begin_define
define|#
directive|define
name|ISALPHA
parameter_list|(
name|Ch
parameter_list|)
value|__iswalpha_l ((Ch), loc)
end_define

begin_define
define|#
directive|define
name|TOUPPER
parameter_list|(
name|Ch
parameter_list|)
value|__towupper_l ((Ch), loc)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISSPACE
parameter_list|(
name|Ch
parameter_list|)
value|iswspace (Ch)
end_define

begin_define
define|#
directive|define
name|ISALPHA
parameter_list|(
name|Ch
parameter_list|)
value|iswalpha (Ch)
end_define

begin_define
define|#
directive|define
name|TOUPPER
parameter_list|(
name|Ch
parameter_list|)
value|towupper (Ch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
name|STDC_HEADERS
operator|||
operator|(
operator|!
name|defined
name|isascii
operator|&&
operator|!
name|defined
name|HAVE_ISASCII
operator|)
end_if

begin_define
define|#
directive|define
name|IN_CTYPE_DOMAIN
parameter_list|(
name|c
parameter_list|)
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IN_CTYPE_DOMAIN
parameter_list|(
name|c
parameter_list|)
value|isascii(c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|L_
parameter_list|(
name|Ch
parameter_list|)
value|Ch
end_define

begin_define
define|#
directive|define
name|UCHAR_TYPE
value|unsigned char
end_define

begin_define
define|#
directive|define
name|STRING_TYPE
value|char
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_IN_EXTENDED_LOCALE_MODEL
end_ifdef

begin_define
define|#
directive|define
name|ISSPACE
parameter_list|(
name|Ch
parameter_list|)
value|__isspace_l ((Ch), loc)
end_define

begin_define
define|#
directive|define
name|ISALPHA
parameter_list|(
name|Ch
parameter_list|)
value|__isalpha_l ((Ch), loc)
end_define

begin_define
define|#
directive|define
name|TOUPPER
parameter_list|(
name|Ch
parameter_list|)
value|__toupper_l ((Ch), loc)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISSPACE
parameter_list|(
name|Ch
parameter_list|)
value|(IN_CTYPE_DOMAIN (Ch)&& isspace (Ch))
end_define

begin_define
define|#
directive|define
name|ISALPHA
parameter_list|(
name|Ch
parameter_list|)
value|(IN_CTYPE_DOMAIN (Ch)&& isalpha (Ch))
end_define

begin_define
define|#
directive|define
name|TOUPPER
parameter_list|(
name|Ch
parameter_list|)
value|(IN_CTYPE_DOMAIN (Ch) ? toupper (Ch) : (Ch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For compilers which are ansi but don't define __STDC__, like SGI    Irix-4.0.5 cc, also check whether PROTOTYPES is defined. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|PROTOTYPES
argument_list|)
end_if

begin_define
define|#
directive|define
name|INTERNAL
parameter_list|(
name|X
parameter_list|)
value|INTERNAL1(X)
end_define

begin_define
define|#
directive|define
name|INTERNAL1
parameter_list|(
name|X
parameter_list|)
value|__##X##_internal
end_define

begin_define
define|#
directive|define
name|WEAKNAME
parameter_list|(
name|X
parameter_list|)
value|WEAKNAME1(X)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INTERNAL
parameter_list|(
name|X
parameter_list|)
value|__
comment|/**/
value|X
comment|/**/
value|_internal
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_NUMBER_GROUPING
end_ifdef

begin_comment
comment|/* This file defines a function to check for correct grouping.  */
end_comment

begin_include
include|#
directive|include
file|"grouping.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Convert NPTR to an `unsigned long int' or `long int' in base BASE.    If BASE is 0 the base is determined by the presence of a leading    zero, indicating octal or a leading "0x" or "0X", indicating hexadecimal.    If BASE is< 2 or> 36, it is reset to 10.    If ENDPTR is not NULL, a pointer to the character after the last    one converted is stored in *ENDPTR.  */
end_comment

begin_function
name|INT
name|INTERNAL
function|(
name|strtol
function|)
parameter_list|(
name|nptr
parameter_list|,
name|endptr
parameter_list|,
name|base
parameter_list|,
name|group
name|LOCALE_PARAM
parameter_list|)
specifier|const
name|STRING_TYPE
modifier|*
name|nptr
decl_stmt|;
name|STRING_TYPE
modifier|*
modifier|*
name|endptr
decl_stmt|;
name|int
name|base
decl_stmt|;
name|int
name|group
decl_stmt|;
function|LOCALE_PARAM_DECL
block|{
name|int
name|negative
decl_stmt|;
specifier|register
name|unsigned
name|LONG
name|int
name|cutoff
decl_stmt|;
specifier|register
name|unsigned
name|int
name|cutlim
decl_stmt|;
specifier|register
name|unsigned
name|LONG
name|int
name|i
decl_stmt|;
specifier|register
specifier|const
name|STRING_TYPE
modifier|*
name|s
decl_stmt|;
specifier|register
name|UCHAR_TYPE
name|c
decl_stmt|;
specifier|const
name|STRING_TYPE
modifier|*
name|save
decl_stmt|,
modifier|*
name|end
decl_stmt|;
name|int
name|overflow
decl_stmt|;
ifdef|#
directive|ifdef
name|USE_NUMBER_GROUPING
ifdef|#
directive|ifdef
name|USE_IN_EXTENDED_LOCALE_MODEL
name|struct
name|locale_data
modifier|*
name|current
init|=
name|loc
operator|->
name|__locales
index|[
name|LC_NUMERIC
index|]
decl_stmt|;
endif|#
directive|endif
comment|/* The thousands character of the current locale.  */
name|wchar_t
name|thousands
init|=
literal|L'
expr|\0'
decl_stmt|;
comment|/* The numeric grouping specification of the current locale,      in the format described in<locale.h>.  */
specifier|const
name|char
modifier|*
name|grouping
decl_stmt|;
if|if
condition|(
name|group
condition|)
block|{
name|grouping
operator|=
name|_NL_CURRENT
argument_list|(
name|LC_NUMERIC
argument_list|,
name|GROUPING
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|grouping
operator|<=
literal|0
operator|||
operator|*
name|grouping
operator|==
name|CHAR_MAX
condition|)
name|grouping
operator|=
name|NULL
expr_stmt|;
else|else
block|{
comment|/* Figure out the thousands separator character.  */
if|#
directive|if
name|defined
name|_LIBC
operator|||
name|defined
name|_HAVE_BTOWC
name|thousands
operator|=
name|__btowc
argument_list|(
operator|*
name|_NL_CURRENT
argument_list|(
name|LC_NUMERIC
argument_list|,
name|THOUSANDS_SEP
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|thousands
operator|==
name|WEOF
condition|)
name|thousands
operator|=
literal|L'
expr|\0'
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|thousands
operator|==
literal|L'
expr|\0'
condition|)
name|grouping
operator|=
name|NULL
expr_stmt|;
block|}
block|}
else|else
name|grouping
operator|=
name|NULL
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|base
operator|<
literal|0
operator|||
name|base
operator|==
literal|1
operator|||
name|base
operator|>
literal|36
condition|)
block|{
name|__set_errno
argument_list|(
name|EINVAL
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|save
operator|=
name|s
operator|=
name|nptr
expr_stmt|;
comment|/* Skip white space.  */
while|while
condition|(
name|ISSPACE
argument_list|(
operator|*
name|s
argument_list|)
condition|)
operator|++
name|s
expr_stmt|;
if|if
condition|(
operator|*
name|s
operator|==
name|L_
argument_list|(
literal|'\0'
argument_list|)
condition|)
goto|goto
name|noconv
goto|;
comment|/* Check for a sign.  */
if|if
condition|(
operator|*
name|s
operator|==
name|L_
argument_list|(
literal|'-'
argument_list|)
condition|)
block|{
name|negative
operator|=
literal|1
expr_stmt|;
operator|++
name|s
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|*
name|s
operator|==
name|L_
argument_list|(
literal|'+'
argument_list|)
condition|)
block|{
name|negative
operator|=
literal|0
expr_stmt|;
operator|++
name|s
expr_stmt|;
block|}
else|else
name|negative
operator|=
literal|0
expr_stmt|;
comment|/* Recognize number prefix and if BASE is zero, figure it out ourselves.  */
if|if
condition|(
operator|*
name|s
operator|==
name|L_
argument_list|(
literal|'0'
argument_list|)
condition|)
block|{
if|if
condition|(
operator|(
name|base
operator|==
literal|0
operator|||
name|base
operator|==
literal|16
operator|)
operator|&&
name|TOUPPER
argument_list|(
name|s
index|[
literal|1
index|]
argument_list|)
operator|==
name|L_
argument_list|(
literal|'X'
argument_list|)
condition|)
block|{
name|s
operator|+=
literal|2
expr_stmt|;
name|base
operator|=
literal|16
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|base
operator|==
literal|0
condition|)
name|base
operator|=
literal|8
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|base
operator|==
literal|0
condition|)
name|base
operator|=
literal|10
expr_stmt|;
comment|/* Save the pointer so we can check later if anything happened.  */
name|save
operator|=
name|s
expr_stmt|;
ifdef|#
directive|ifdef
name|USE_NUMBER_GROUPING
if|if
condition|(
name|group
condition|)
block|{
comment|/* Find the end of the digit string and check its grouping.  */
name|end
operator|=
name|s
expr_stmt|;
for|for
control|(
name|c
operator|=
operator|*
name|end
init|;
name|c
operator|!=
name|L_
argument_list|(
literal|'\0'
argument_list|)
condition|;
name|c
operator|=
operator|*
operator|++
name|end
control|)
if|if
condition|(
operator|(
name|wchar_t
operator|)
name|c
operator|!=
name|thousands
operator|&&
operator|(
operator|(
name|wchar_t
operator|)
name|c
operator|<
name|L_
argument_list|(
literal|'0'
argument_list|)
operator|||
operator|(
name|wchar_t
operator|)
name|c
operator|>
name|L_
argument_list|(
literal|'9'
argument_list|)
operator|)
operator|&&
operator|(
operator|!
name|ISALPHA
argument_list|(
name|c
argument_list|)
operator|||
call|(
name|int
call|)
argument_list|(
name|TOUPPER
argument_list|(
name|c
argument_list|)
operator|-
name|L_
argument_list|(
literal|'A'
argument_list|)
operator|+
literal|10
argument_list|)
operator|>=
name|base
operator|)
condition|)
break|break;
if|if
condition|(
operator|*
name|s
operator|==
name|thousands
condition|)
name|end
operator|=
name|s
expr_stmt|;
else|else
name|end
operator|=
name|correctly_grouped_prefix
argument_list|(
name|s
argument_list|,
name|end
argument_list|,
name|thousands
argument_list|,
name|grouping
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
name|end
operator|=
name|NULL
expr_stmt|;
name|cutoff
operator|=
name|STRTOL_ULONG_MAX
operator|/
operator|(
name|unsigned
name|LONG
name|int
operator|)
name|base
expr_stmt|;
name|cutlim
operator|=
name|STRTOL_ULONG_MAX
operator|%
operator|(
name|unsigned
name|LONG
name|int
operator|)
name|base
expr_stmt|;
name|overflow
operator|=
literal|0
expr_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|c
operator|=
operator|*
name|s
init|;
name|c
operator|!=
name|L_
argument_list|(
literal|'\0'
argument_list|)
condition|;
name|c
operator|=
operator|*
operator|++
name|s
control|)
block|{
if|if
condition|(
name|s
operator|==
name|end
condition|)
break|break;
if|if
condition|(
name|c
operator|>=
name|L_
argument_list|(
literal|'0'
argument_list|)
operator|&&
name|c
operator|<=
name|L_
argument_list|(
literal|'9'
argument_list|)
condition|)
name|c
operator|-=
name|L_
argument_list|(
literal|'0'
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|ISALPHA
argument_list|(
name|c
argument_list|)
condition|)
name|c
operator|=
name|TOUPPER
argument_list|(
name|c
argument_list|)
operator|-
name|L_
argument_list|(
literal|'A'
argument_list|)
operator|+
literal|10
expr_stmt|;
else|else
break|break;
if|if
condition|(
operator|(
name|int
operator|)
name|c
operator|>=
name|base
condition|)
break|break;
comment|/* Check for overflow.  */
if|if
condition|(
name|i
operator|>
name|cutoff
operator|||
operator|(
name|i
operator|==
name|cutoff
operator|&&
name|c
operator|>
name|cutlim
operator|)
condition|)
name|overflow
operator|=
literal|1
expr_stmt|;
else|else
block|{
name|i
operator|*=
operator|(
name|unsigned
name|LONG
name|int
operator|)
name|base
expr_stmt|;
name|i
operator|+=
name|c
expr_stmt|;
block|}
block|}
comment|/* Check if anything actually happened.  */
if|if
condition|(
name|s
operator|==
name|save
condition|)
goto|goto
name|noconv
goto|;
comment|/* Store in ENDPTR the address of one character      past the last character we converted.  */
if|if
condition|(
name|endptr
operator|!=
name|NULL
condition|)
operator|*
name|endptr
operator|=
operator|(
name|STRING_TYPE
operator|*
operator|)
name|s
expr_stmt|;
if|#
directive|if
operator|!
name|UNSIGNED
comment|/* Check for a value that is within the range of      `unsigned LONG int', but outside the range of `LONG int'.  */
if|if
condition|(
name|overflow
operator|==
literal|0
operator|&&
name|i
operator|>
operator|(
name|negative
condition|?
operator|-
operator|(
call|(
name|unsigned
name|LONG
name|int
call|)
argument_list|(
name|STRTOL_LONG_MIN
operator|+
literal|1
argument_list|)
operator|)
operator|+
literal|1
else|:
operator|(
name|unsigned
name|LONG
name|int
operator|)
name|STRTOL_LONG_MAX
operator|)
condition|)
name|overflow
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|overflow
condition|)
block|{
name|__set_errno
argument_list|(
name|ERANGE
argument_list|)
expr_stmt|;
if|#
directive|if
name|UNSIGNED
return|return
name|STRTOL_ULONG_MAX
return|;
else|#
directive|else
return|return
name|negative
condition|?
name|STRTOL_LONG_MIN
else|:
name|STRTOL_LONG_MAX
return|;
endif|#
directive|endif
block|}
comment|/* Return the result of the appropriate sign.  */
return|return
name|negative
condition|?
operator|-
name|i
else|:
name|i
return|;
name|noconv
label|:
comment|/* We must handle a special case here: the base is 0 or 16 and the      first two characters are '0' and 'x', but the rest are no      hexadecimal digits.  This is no error case.  We return 0 and      ENDPTR points to the `x`.  */
if|if
condition|(
name|endptr
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|save
operator|-
name|nptr
operator|>=
literal|2
operator|&&
name|TOUPPER
argument_list|(
name|save
index|[
operator|-
literal|1
index|]
argument_list|)
operator|==
name|L_
argument_list|(
literal|'X'
argument_list|)
operator|&&
name|save
index|[
operator|-
literal|2
index|]
operator|==
name|L_
argument_list|(
literal|'0'
argument_list|)
condition|)
operator|*
name|endptr
operator|=
operator|(
name|STRING_TYPE
operator|*
operator|)
operator|&
name|save
index|[
operator|-
literal|1
index|]
expr_stmt|;
else|else
comment|/*  There was no number to convert.  */
operator|*
name|endptr
operator|=
operator|(
name|STRING_TYPE
operator|*
operator|)
name|nptr
expr_stmt|;
block|}
return|return
literal|0L
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* External user entry point.  */
end_comment

begin_if
if|#
directive|if
name|_LIBC
operator|-
literal|0
operator|==
literal|0
end_if

begin_undef
undef|#
directive|undef
name|PARAMS
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
name|__STDC__
end_if

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|Args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Prototype.  */
end_comment

begin_decl_stmt
name|INT
name|strtol
name|PARAMS
argument_list|(
operator|(
specifier|const
name|STRING_TYPE
operator|*
name|nptr
operator|,
name|STRING_TYPE
operator|*
operator|*
name|endptr
operator|,
name|int
name|base
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|INT
ifdef|#
directive|ifdef
name|weak_function
name|weak_function
endif|#
directive|endif
name|strtol
parameter_list|(
name|nptr
parameter_list|,
name|endptr
parameter_list|,
name|base
name|LOCALE_PARAM
parameter_list|)
specifier|const
name|STRING_TYPE
modifier|*
name|nptr
decl_stmt|;
name|STRING_TYPE
modifier|*
modifier|*
name|endptr
decl_stmt|;
name|int
name|base
decl_stmt|;
function|LOCALE_PARAM_DECL
block|{
return|return
name|INTERNAL
argument_list|(
name|strtol
argument_list|)
argument_list|(
name|nptr
argument_list|,
name|endptr
argument_list|,
name|base
argument_list|,
literal|0
name|LOCALE_PARAM
argument_list|)
return|;
block|}
end_function

end_unit

