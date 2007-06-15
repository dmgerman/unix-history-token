begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991,1992,1993,1996,1997,1998,1999,2000,2001,2002,2003,2004 	Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_comment
comment|/* Enable GNU extensions in fnmatch.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GNU_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_GNU_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_define
define|#
directive|define
name|HAVE_ALLOCA
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
name|HAVE_ALLOCA_H
operator|||
name|defined
name|_LIBC
end_if

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|alloca
end_pragma

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|alloca
end_ifndef

begin_function_decl
name|char
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

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

begin_if
if|#
directive|if
operator|!
name|defined
name|__builtin_expect
operator|&&
name|__GNUC__
operator|<
literal|3
end_if

begin_define
define|#
directive|define
name|__builtin_expect
parameter_list|(
name|expr
parameter_list|,
name|expected
parameter_list|)
value|(expr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<fnmatch.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

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

begin_define
define|#
directive|define
name|WIDE_CHAR_SUPPORT
value|(HAVE_WCTYPE_H&& HAVE_WCHAR_H&& HAVE_BTOWC)
end_define

begin_comment
comment|/* For platform which support the ISO C amendement 1 functionality we    support user defined character classes.  */
end_comment

begin_if
if|#
directive|if
name|defined
name|_LIBC
operator|||
name|WIDE_CHAR_SUPPORT
end_if

begin_comment
comment|/* Solaris 2.5 has a bug:<wchar.h> must be included before<wctype.h>.  */
end_comment

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_include
include|#
directive|include
file|<wctype.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We need some of the locale data (the collation sequence information)    but there is no interface to get this information in general.  Therefore    we support a correct implementation only in glibc.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_include
include|#
directive|include
file|"../locale/localeinfo.h"
end_include

begin_include
include|#
directive|include
file|"../locale/elem-hash.h"
end_include

begin_include
include|#
directive|include
file|"../locale/coll-lookup.h"
end_include

begin_include
include|#
directive|include
file|<shlib-compat.h>
end_include

begin_define
define|#
directive|define
name|CONCAT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__CONCAT(a,b)
end_define

begin_define
define|#
directive|define
name|mbsrtowcs
value|__mbsrtowcs
end_define

begin_define
define|#
directive|define
name|fnmatch
value|__fnmatch
end_define

begin_function_decl
specifier|extern
name|int
name|fnmatch
parameter_list|(
specifier|const
name|char
modifier|*
name|pattern
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_MAX
end_ifndef

begin_define
define|#
directive|define
name|SIZE_MAX
value|((size_t) -1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We often have to test for FNM_FILE_NAME and FNM_PERIOD being both set.  */
end_comment

begin_define
define|#
directive|define
name|NO_LEADING_PERIOD
parameter_list|(
name|flags
parameter_list|)
define|\
value|((flags& (FNM_FILE_NAME | FNM_PERIOD)) == (FNM_FILE_NAME | FNM_PERIOD))
end_define

begin_comment
comment|/* Comment out all this code if we are using the GNU C Library, and are not    actually compiling the library itself, and have not detected a bug    in the library.  This code is part of the GNU C    Library, but also included in many other GNU distributions.  Compiling    and linking in this code is a waste when using the GNU C library    (especially if it is a shared library).  Rather than having every GNU    program understand `configure --with-gnu-libc' and omit the object files,    it is simpler to just do this in the source for each such file.  */
end_comment

begin_if
if|#
directive|if
name|defined
name|_LIBC
operator|||
operator|!
name|defined
name|__GNU_LIBRARY__
operator|||
operator|!
name|HAVE_FNMATCH_GNU
end_if

begin_if
if|#
directive|if
name|defined
name|STDC_HEADERS
operator|||
operator|!
name|defined
name|isascii
end_if

begin_define
define|#
directive|define
name|ISASCII
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
name|ISASCII
parameter_list|(
name|c
parameter_list|)
value|isascii(c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|isblank
end_ifdef

begin_define
define|#
directive|define
name|ISBLANK
parameter_list|(
name|c
parameter_list|)
value|(ISASCII (c)&& isblank (c))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISBLANK
parameter_list|(
name|c
parameter_list|)
value|((c) == ' ' || (c) == '\t')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|isgraph
end_ifdef

begin_define
define|#
directive|define
name|ISGRAPH
parameter_list|(
name|c
parameter_list|)
value|(ISASCII (c)&& isgraph (c))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISGRAPH
parameter_list|(
name|c
parameter_list|)
value|(ISASCII (c)&& isprint (c)&& !isspace (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISPRINT
parameter_list|(
name|c
parameter_list|)
value|(ISASCII (c)&& isprint (c))
end_define

begin_define
define|#
directive|define
name|ISDIGIT
parameter_list|(
name|c
parameter_list|)
value|(ISASCII (c)&& isdigit (c))
end_define

begin_define
define|#
directive|define
name|ISALNUM
parameter_list|(
name|c
parameter_list|)
value|(ISASCII (c)&& isalnum (c))
end_define

begin_define
define|#
directive|define
name|ISALPHA
parameter_list|(
name|c
parameter_list|)
value|(ISASCII (c)&& isalpha (c))
end_define

begin_define
define|#
directive|define
name|ISCNTRL
parameter_list|(
name|c
parameter_list|)
value|(ISASCII (c)&& iscntrl (c))
end_define

begin_define
define|#
directive|define
name|ISLOWER
parameter_list|(
name|c
parameter_list|)
value|(ISASCII (c)&& islower (c))
end_define

begin_define
define|#
directive|define
name|ISPUNCT
parameter_list|(
name|c
parameter_list|)
value|(ISASCII (c)&& ispunct (c))
end_define

begin_define
define|#
directive|define
name|ISSPACE
parameter_list|(
name|c
parameter_list|)
value|(ISASCII (c)&& isspace (c))
end_define

begin_define
define|#
directive|define
name|ISUPPER
parameter_list|(
name|c
parameter_list|)
value|(ISASCII (c)&& isupper (c))
end_define

begin_define
define|#
directive|define
name|ISXDIGIT
parameter_list|(
name|c
parameter_list|)
value|(ISASCII (c)&& isxdigit (c))
end_define

begin_define
define|#
directive|define
name|STREQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|((strcmp (s1, s2) == 0))
end_define

begin_if
if|#
directive|if
name|defined
name|_LIBC
operator|||
name|WIDE_CHAR_SUPPORT
end_if

begin_comment
comment|/* The GNU C library provides support for user-defined character classes    and the functions from ISO C amendement 1.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CHARCLASS_NAME_MAX
end_ifdef

begin_define
define|#
directive|define
name|CHAR_CLASS_MAX_LENGTH
value|CHARCLASS_NAME_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* This shouldn't happen but some implementation might still have this    problem.  Use a reasonable default value.  */
end_comment

begin_define
define|#
directive|define
name|CHAR_CLASS_MAX_LENGTH
value|256
end_define

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
name|IS_CHAR_CLASS
parameter_list|(
name|string
parameter_list|)
value|__wctype (string)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IS_CHAR_CLASS
parameter_list|(
name|string
parameter_list|)
value|wctype (string)
end_define

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
name|ISWCTYPE
parameter_list|(
name|WC
parameter_list|,
name|WT
parameter_list|)
value|__iswctype (WC, WT)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISWCTYPE
parameter_list|(
name|WC
parameter_list|,
name|WT
parameter_list|)
value|iswctype (WC, WT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|HAVE_MBSTATE_T
operator|&&
name|HAVE_MBSRTOWCS
operator|)
operator|||
name|_LIBC
end_if

begin_comment
comment|/* In this case we are implementing the multibyte character handling.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_MULTIBYTE
value|1
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
name|CHAR_CLASS_MAX_LENGTH
value|6
end_define

begin_comment
comment|/* Namely, `xdigit'.  */
end_comment

begin_define
define|#
directive|define
name|IS_CHAR_CLASS
parameter_list|(
name|string
parameter_list|)
define|\
value|(STREQ (string, "alpha") || STREQ (string, "upper")			      \     || STREQ (string, "lower") || STREQ (string, "digit")		      \     || STREQ (string, "alnum") || STREQ (string, "xdigit")		      \     || STREQ (string, "space") || STREQ (string, "print")		      \     || STREQ (string, "punct") || STREQ (string, "graph")		      \     || STREQ (string, "cntrl") || STREQ (string, "blank"))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Avoid depending on library functions or files    whose names are inconsistent.  */
end_comment

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

begin_comment
comment|/* Global variable.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|posixly_correct
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|internal_function
end_ifndef

begin_comment
comment|/* Inside GNU libc we mark some function in a special way.  In other    environments simply ignore the marking.  */
end_comment

begin_define
define|#
directive|define
name|internal_function
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Note that this evaluates C many times.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_define
define|#
directive|define
name|FOLD
parameter_list|(
name|c
parameter_list|)
value|((flags& FNM_CASEFOLD) ? tolower (c) : (c))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FOLD
parameter_list|(
name|c
parameter_list|)
value|((flags& FNM_CASEFOLD)&& ISUPPER (c) ? tolower (c) : (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CHAR
value|char
end_define

begin_define
define|#
directive|define
name|UCHAR
value|unsigned char
end_define

begin_define
define|#
directive|define
name|INT
value|int
end_define

begin_define
define|#
directive|define
name|FCT
value|internal_fnmatch
end_define

begin_define
define|#
directive|define
name|EXT
value|ext_match
end_define

begin_define
define|#
directive|define
name|END
value|end_pattern
end_define

begin_define
define|#
directive|define
name|L
parameter_list|(
name|CS
parameter_list|)
value|CS
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_define
define|#
directive|define
name|BTOWC
parameter_list|(
name|C
parameter_list|)
value|__btowc (C)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BTOWC
parameter_list|(
name|C
parameter_list|)
value|btowc (C)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STRLEN
parameter_list|(
name|S
parameter_list|)
value|strlen (S)
end_define

begin_define
define|#
directive|define
name|STRCAT
parameter_list|(
name|D
parameter_list|,
name|S
parameter_list|)
value|strcat (D, S)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_define
define|#
directive|define
name|MEMPCPY
parameter_list|(
name|D
parameter_list|,
name|S
parameter_list|,
name|N
parameter_list|)
value|__mempcpy (D, S, N)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_MEMPCPY
end_if

begin_define
define|#
directive|define
name|MEMPCPY
parameter_list|(
name|D
parameter_list|,
name|S
parameter_list|,
name|N
parameter_list|)
value|mempcpy (D, S, N)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MEMPCPY
parameter_list|(
name|D
parameter_list|,
name|S
parameter_list|,
name|N
parameter_list|)
value|((void *) ((char *) memcpy (D, S, N) + (N)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MEMCHR
parameter_list|(
name|S
parameter_list|,
name|C
parameter_list|,
name|N
parameter_list|)
value|memchr (S, C, N)
end_define

begin_define
define|#
directive|define
name|STRCOLL
parameter_list|(
name|S1
parameter_list|,
name|S2
parameter_list|)
value|strcoll (S1, S2)
end_define

begin_include
include|#
directive|include
file|"fnmatch_loop.c"
end_include

begin_if
if|#
directive|if
name|HANDLE_MULTIBYTE
end_if

begin_define
define|#
directive|define
name|FOLD
parameter_list|(
name|c
parameter_list|)
value|((flags& FNM_CASEFOLD) ? towlower (c) : (c))
end_define

begin_define
define|#
directive|define
name|CHAR
value|wchar_t
end_define

begin_define
define|#
directive|define
name|UCHAR
value|wint_t
end_define

begin_define
define|#
directive|define
name|INT
value|wint_t
end_define

begin_define
define|#
directive|define
name|FCT
value|internal_fnwmatch
end_define

begin_define
define|#
directive|define
name|EXT
value|ext_wmatch
end_define

begin_define
define|#
directive|define
name|END
value|end_wpattern
end_define

begin_define
define|#
directive|define
name|L
parameter_list|(
name|CS
parameter_list|)
value|L##CS
end_define

begin_define
define|#
directive|define
name|BTOWC
parameter_list|(
name|C
parameter_list|)
value|(C)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_define
define|#
directive|define
name|STRLEN
parameter_list|(
name|S
parameter_list|)
value|__wcslen (S)
end_define

begin_define
define|#
directive|define
name|STRCAT
parameter_list|(
name|D
parameter_list|,
name|S
parameter_list|)
value|__wcscat (D, S)
end_define

begin_define
define|#
directive|define
name|MEMPCPY
parameter_list|(
name|D
parameter_list|,
name|S
parameter_list|,
name|N
parameter_list|)
value|__wmempcpy (D, S, N)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STRLEN
parameter_list|(
name|S
parameter_list|)
value|wcslen (S)
end_define

begin_define
define|#
directive|define
name|STRCAT
parameter_list|(
name|D
parameter_list|,
name|S
parameter_list|)
value|wcscat (D, S)
end_define

begin_if
if|#
directive|if
name|HAVE_WMEMPCPY
end_if

begin_define
define|#
directive|define
name|MEMPCPY
parameter_list|(
name|D
parameter_list|,
name|S
parameter_list|,
name|N
parameter_list|)
value|wmempcpy (D, S, N)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MEMPCPY
parameter_list|(
name|D
parameter_list|,
name|S
parameter_list|,
name|N
parameter_list|)
value|(wmemcpy (D, S, N) + (N))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MEMCHR
parameter_list|(
name|S
parameter_list|,
name|C
parameter_list|,
name|N
parameter_list|)
value|wmemchr (S, C, N)
end_define

begin_define
define|#
directive|define
name|STRCOLL
parameter_list|(
name|S1
parameter_list|,
name|S2
parameter_list|)
value|wcscoll (S1, S2)
end_define

begin_define
define|#
directive|define
name|WIDE_CHAR_VERSION
value|1
end_define

begin_undef
undef|#
directive|undef
name|IS_CHAR_CLASS
end_undef

begin_comment
comment|/* We have to convert the wide character string in a multibyte string.  But    we know that the character class names consist of alphanumeric characters    from the portable character set, and since the wide character encoding    for a member of the portable character set is the same code point as    its single-byte encoding, we can use a simplified method to convert the    string to a multibyte character string.  */
end_comment

begin_function
specifier|static
name|wctype_t
name|is_char_class
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|wcs
parameter_list|)
block|{
name|char
name|s
index|[
name|CHAR_CLASS_MAX_LENGTH
operator|+
literal|1
index|]
decl_stmt|;
name|char
modifier|*
name|cp
init|=
name|s
decl_stmt|;
do|do
block|{
comment|/* Test for a printable character from the portable character set.  */
ifdef|#
directive|ifdef
name|_LIBC
if|if
condition|(
operator|*
name|wcs
operator|<
literal|0x20
operator|||
operator|*
name|wcs
operator|>
literal|0x7e
operator|||
operator|*
name|wcs
operator|==
literal|0x24
operator|||
operator|*
name|wcs
operator|==
literal|0x40
operator|||
operator|*
name|wcs
operator|==
literal|0x60
condition|)
return|return
operator|(
name|wctype_t
operator|)
literal|0
return|;
else|#
directive|else
switch|switch
condition|(
operator|*
name|wcs
condition|)
block|{
case|case
literal|L'
expr|'
case|:
case|case
literal|L'
expr|!'
case|:
case|case
literal|L'
expr|"'
case|:
case|case
literal|L'
expr|#'
case|:
case|case
literal|L'
expr|%'
case|:
case|case
literal|L'
expr|&'
case|:
case|case
literal|L'
expr|\''
case|:
case|case
literal|L'
expr|('
case|:
case|case
literal|L'
expr|)'
case|:
case|case
literal|L'
expr|*'
case|:
case|case
literal|L'
expr|+'
case|:
case|case
literal|L'
expr|,'
case|:
case|case
literal|L'
expr|-'
case|:
case|case
literal|L'
expr|.'
case|:
case|case
literal|L'
expr|/'
case|:
case|case
literal|L'
expr|0'
case|:
case|case
literal|L'
expr|1'
case|:
case|case
literal|L'
expr|2'
case|:
case|case
literal|L'
expr|3'
case|:
case|case
literal|L'
expr|4'
case|:
case|case
literal|L'
expr|5'
case|:
case|case
literal|L'
expr|6'
case|:
case|case
literal|L'
expr|7'
case|:
case|case
literal|L'
expr|8'
case|:
case|case
literal|L'
expr|9'
case|:
case|case
literal|L'
expr|:'
case|:
case|case
literal|L'
expr|;'
case|:
case|case
literal|L'
expr|<'
case|:
case|case
literal|L'
expr|='
case|:
case|case
literal|L'
expr|>'
case|:
case|case
literal|L'
expr|?'
case|:
case|case
literal|L'
expr|A'
case|:
case|case
literal|L'
expr|B'
case|:
case|case
literal|L'
expr|C'
case|:
case|case
literal|L'
expr|D'
case|:
case|case
literal|L'
expr|E'
case|:
case|case
literal|L'
expr|F'
case|:
case|case
literal|L'
expr|G'
case|:
case|case
literal|L'
expr|H'
case|:
case|case
literal|L'
expr|I'
case|:
case|case
literal|L'
expr|J'
case|:
case|case
literal|L'
expr|K'
case|:
case|case
literal|L'
expr|L'
case|:
case|case
literal|L'
expr|M'
case|:
case|case
literal|L'
expr|N'
case|:
case|case
literal|L'
expr|O'
case|:
case|case
literal|L'
expr|P'
case|:
case|case
literal|L'
expr|Q'
case|:
case|case
literal|L'
expr|R'
case|:
case|case
literal|L'
expr|S'
case|:
case|case
literal|L'
expr|T'
case|:
case|case
literal|L'
expr|U'
case|:
case|case
literal|L'
expr|V'
case|:
case|case
literal|L'
expr|W'
case|:
case|case
literal|L'
expr|X'
case|:
case|case
literal|L'
expr|Y'
case|:
case|case
literal|L'
expr|Z'
case|:
case|case
literal|L'
expr|['
case|:
case|case
literal|L'
expr|\\'
case|:
case|case
literal|L'
expr|]'
case|:
case|case
literal|L'
expr|^'
case|:
case|case
literal|L'
expr|_'
case|:
case|case
literal|L'
expr|a'
case|:
case|case
literal|L'
expr|b'
case|:
case|case
literal|L'
expr|c'
case|:
case|case
literal|L'
expr|d'
case|:
case|case
literal|L'
expr|e'
case|:
case|case
literal|L'
expr|f'
case|:
case|case
literal|L'
expr|g'
case|:
case|case
literal|L'
expr|h'
case|:
case|case
literal|L'
expr|i'
case|:
case|case
literal|L'
expr|j'
case|:
case|case
literal|L'
expr|k'
case|:
case|case
literal|L'
expr|l'
case|:
case|case
literal|L'
expr|m'
case|:
case|case
literal|L'
expr|n'
case|:
case|case
literal|L'
expr|o'
case|:
case|case
literal|L'
expr|p'
case|:
case|case
literal|L'
expr|q'
case|:
case|case
literal|L'
expr|r'
case|:
case|case
literal|L'
expr|s'
case|:
case|case
literal|L'
expr|t'
case|:
case|case
literal|L'
expr|u'
case|:
case|case
literal|L'
expr|v'
case|:
case|case
literal|L'
expr|w'
case|:
case|case
literal|L'
expr|x'
case|:
case|case
literal|L'
expr|y'
case|:
case|case
literal|L'
expr|z'
case|:
case|case
literal|L'
expr|{'
case|:
case|case
literal|L'
expr||'
case|:
case|case
literal|L'
expr|}'
case|:
case|case
literal|L'
expr|~'
case|:
break|break;
default|default:
return|return
operator|(
name|wctype_t
operator|)
literal|0
return|;
block|}
endif|#
directive|endif
comment|/* Avoid overrunning the buffer.  */
if|if
condition|(
name|cp
operator|==
name|s
operator|+
name|CHAR_CLASS_MAX_LENGTH
condition|)
return|return
operator|(
name|wctype_t
operator|)
literal|0
return|;
operator|*
name|cp
operator|++
operator|=
operator|(
name|char
operator|)
operator|*
name|wcs
operator|++
expr_stmt|;
block|}
do|while
condition|(
operator|*
name|wcs
operator|!=
literal|L'
expr|\0'
condition|)
do|;
operator|*
name|cp
operator|=
literal|'\0'
expr_stmt|;
ifdef|#
directive|ifdef
name|_LIBC
return|return
name|__wctype
argument_list|(
name|s
argument_list|)
return|;
else|#
directive|else
return|return
name|wctype
argument_list|(
name|s
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function

begin_define
define|#
directive|define
name|IS_CHAR_CLASS
parameter_list|(
name|string
parameter_list|)
value|is_char_class (string)
end_define

begin_include
include|#
directive|include
file|"fnmatch_loop.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|fnmatch
parameter_list|(
specifier|const
name|char
modifier|*
name|pattern
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
if|#
directive|if
name|HANDLE_MULTIBYTE
define|#
directive|define
name|ALLOCA_LIMIT
value|2000
if|if
condition|(
name|__builtin_expect
argument_list|(
name|MB_CUR_MAX
argument_list|,
literal|1
argument_list|)
operator|!=
literal|1
condition|)
block|{
name|mbstate_t
name|ps
decl_stmt|;
name|size_t
name|patsize
decl_stmt|;
name|size_t
name|strsize
decl_stmt|;
name|size_t
name|totsize
decl_stmt|;
name|wchar_t
modifier|*
name|wpattern
decl_stmt|;
name|wchar_t
modifier|*
name|wstring
decl_stmt|;
name|int
name|res
decl_stmt|;
comment|/* Calculate the size needed to convert the strings to 	 wide characters.  */
name|memset
argument_list|(
operator|&
name|ps
argument_list|,
literal|'\0'
argument_list|,
sizeof|sizeof
argument_list|(
name|ps
argument_list|)
argument_list|)
expr_stmt|;
name|patsize
operator|=
name|mbsrtowcs
argument_list|(
name|NULL
argument_list|,
operator|&
name|pattern
argument_list|,
literal|0
argument_list|,
operator|&
name|ps
argument_list|)
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|__builtin_expect
argument_list|(
name|patsize
operator|==
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
comment|/* Something wrong. 	   XXX Do we have to set `errno' to something which mbsrtows hasn't 	   already done?  */
return|return
operator|-
literal|1
return|;
name|assert
argument_list|(
name|mbsinit
argument_list|(
operator|&
name|ps
argument_list|)
argument_list|)
expr_stmt|;
name|strsize
operator|=
name|mbsrtowcs
argument_list|(
name|NULL
argument_list|,
operator|&
name|string
argument_list|,
literal|0
argument_list|,
operator|&
name|ps
argument_list|)
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|__builtin_expect
argument_list|(
name|strsize
operator|==
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
comment|/* Something wrong. 	   XXX Do we have to set `errno' to something which mbsrtows hasn't 	   already done?  */
return|return
operator|-
literal|1
return|;
name|assert
argument_list|(
name|mbsinit
argument_list|(
operator|&
name|ps
argument_list|)
argument_list|)
expr_stmt|;
name|totsize
operator|=
name|patsize
operator|+
name|strsize
expr_stmt|;
if|if
condition|(
name|__builtin_expect
argument_list|(
operator|!
operator|(
name|patsize
operator|<=
name|totsize
operator|&&
name|totsize
operator|<=
name|SIZE_MAX
operator|/
sizeof|sizeof
argument_list|(
name|wchar_t
argument_list|)
operator|)
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|errno
operator|=
name|ENOMEM
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
comment|/* Allocate room for the wide characters.  */
if|if
condition|(
name|__builtin_expect
argument_list|(
name|totsize
operator|<
name|ALLOCA_LIMIT
argument_list|,
literal|1
argument_list|)
condition|)
name|wpattern
operator|=
operator|(
name|wchar_t
operator|*
operator|)
name|alloca
argument_list|(
name|totsize
operator|*
sizeof|sizeof
argument_list|(
name|wchar_t
argument_list|)
argument_list|)
expr_stmt|;
else|else
block|{
name|wpattern
operator|=
name|malloc
argument_list|(
name|totsize
operator|*
sizeof|sizeof
argument_list|(
name|wchar_t
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|__builtin_expect
argument_list|(
operator|!
name|wpattern
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|errno
operator|=
name|ENOMEM
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
block|}
name|wstring
operator|=
name|wpattern
operator|+
name|patsize
expr_stmt|;
comment|/* Convert the strings into wide characters.  */
name|mbsrtowcs
argument_list|(
name|wpattern
argument_list|,
operator|&
name|pattern
argument_list|,
name|patsize
argument_list|,
operator|&
name|ps
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|mbsinit
argument_list|(
operator|&
name|ps
argument_list|)
argument_list|)
expr_stmt|;
name|mbsrtowcs
argument_list|(
name|wstring
argument_list|,
operator|&
name|string
argument_list|,
name|strsize
argument_list|,
operator|&
name|ps
argument_list|)
expr_stmt|;
name|res
operator|=
name|internal_fnwmatch
argument_list|(
name|wpattern
argument_list|,
name|wstring
argument_list|,
name|wstring
operator|+
name|strsize
operator|-
literal|1
argument_list|,
name|flags
operator|&
name|FNM_PERIOD
argument_list|,
name|flags
argument_list|)
expr_stmt|;
if|if
condition|(
name|__builtin_expect
argument_list|(
operator|!
operator|(
name|totsize
operator|<
name|ALLOCA_LIMIT
operator|)
argument_list|,
literal|0
argument_list|)
condition|)
name|free
argument_list|(
name|wpattern
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
endif|#
directive|endif
comment|/* HANDLE_MULTIBYTE */
return|return
name|internal_fnmatch
argument_list|(
name|pattern
argument_list|,
name|string
argument_list|,
name|string
operator|+
name|strlen
argument_list|(
name|string
argument_list|)
argument_list|,
name|flags
operator|&
name|FNM_PERIOD
argument_list|,
name|flags
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_undef
undef|#
directive|undef
name|fnmatch
end_undef

begin_expr_stmt
name|versioned_symbol
argument_list|(
name|libc
argument_list|,
name|__fnmatch
argument_list|,
name|fnmatch
argument_list|,
name|GLIBC_2_2_3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|SHLIB_COMPAT
argument_list|(
name|libc
operator|,
name|GLIBC_2_0
operator|,
name|GLIBC_2_2_3
argument_list|)
end_if

begin_macro
name|strong_alias
argument_list|(
argument|__fnmatch
argument_list|,
argument|__fnmatch_old
argument_list|)
end_macro

begin_expr_stmt
name|compat_symbol
argument_list|(
name|libc
argument_list|,
name|__fnmatch_old
argument_list|,
name|fnmatch
argument_list|,
name|GLIBC_2_0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|libc_hidden_ver
argument_list|(
argument|__fnmatch
argument_list|,
argument|fnmatch
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBC or not __GNU_LIBRARY__.  */
end_comment

end_unit

