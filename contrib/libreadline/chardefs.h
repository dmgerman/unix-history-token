begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* chardefs.h -- Character definitions for readline. */
end_comment

begin_comment
comment|/* Copyright (C) 1994 Free Software Foundation, Inc.     This file is part of the GNU Readline Library, a library for    reading lines of text with interactive input and history editing.     The GNU Readline Library is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public License    as published by the Free Software Foundation; either version 2, or    (at your option) any later version.     The GNU Readline Library is distributed in the hope that it will be    useful, but WITHOUT ANY WARRANTY; without even the implied warranty    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    59 Temple Place, Suite 330, Boston, MA 02111 USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CHARDEFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_CHARDEFS_H_
end_define

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CONFIG_H
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STRING_H
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STDC_HEADERS
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_MEMORY_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STRING_H */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STRINGS_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STRINGS_H */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_CONFIG_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|whitespace
end_ifndef

begin_define
define|#
directive|define
name|whitespace
parameter_list|(
name|c
parameter_list|)
value|(((c) == ' ') || ((c) == '\t'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CTRL
end_ifdef

begin_undef
undef|#
directive|undef
name|CTRL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UNCTRL
end_ifdef

begin_undef
undef|#
directive|undef
name|UNCTRL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some character stuff. */
end_comment

begin_define
define|#
directive|define
name|control_character_threshold
value|0x020
end_define

begin_comment
comment|/* Smaller than this is control. */
end_comment

begin_define
define|#
directive|define
name|control_character_mask
value|0x1f
end_define

begin_comment
comment|/* 0x20 - 1 */
end_comment

begin_define
define|#
directive|define
name|meta_character_threshold
value|0x07f
end_define

begin_comment
comment|/* Larger than this is Meta. */
end_comment

begin_define
define|#
directive|define
name|control_character_bit
value|0x40
end_define

begin_comment
comment|/* 0x000000, must be off. */
end_comment

begin_define
define|#
directive|define
name|meta_character_bit
value|0x080
end_define

begin_comment
comment|/* x0000000, must be on. */
end_comment

begin_define
define|#
directive|define
name|largest_char
value|255
end_define

begin_comment
comment|/* Largest character value. */
end_comment

begin_define
define|#
directive|define
name|CTRL_CHAR
parameter_list|(
name|c
parameter_list|)
value|((c)< control_character_threshold&& (((c)& 0x80) == 0))
end_define

begin_define
define|#
directive|define
name|META_CHAR
parameter_list|(
name|c
parameter_list|)
value|((c)> meta_character_threshold&& (c)<= largest_char)
end_define

begin_define
define|#
directive|define
name|CTRL
parameter_list|(
name|c
parameter_list|)
value|((c)& control_character_mask)
end_define

begin_define
define|#
directive|define
name|META
parameter_list|(
name|c
parameter_list|)
value|((c) | meta_character_bit)
end_define

begin_define
define|#
directive|define
name|UNMETA
parameter_list|(
name|c
parameter_list|)
value|((c)& (~meta_character_bit))
end_define

begin_define
define|#
directive|define
name|UNCTRL
parameter_list|(
name|c
parameter_list|)
value|_rl_to_upper(((c)|control_character_bit))
end_define

begin_if
if|#
directive|if
name|defined
name|STDC_HEADERS
operator|||
operator|(
operator|!
name|defined
argument_list|(
name|isascii
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ISASCII
argument_list|)
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|isxdigit
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ISXDIGIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|isxdigit
parameter_list|(
name|c
parameter_list|)
value|(isdigit((c)) || ((c)>= 'a'&& (c)<= 'f') || ((c)>= 'A'&& (c)<= 'F'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CTYPE_NON_ASCII
argument_list|)
end_if

begin_define
define|#
directive|define
name|NON_NEGATIVE
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
name|NON_NEGATIVE
parameter_list|(
name|c
parameter_list|)
value|((unsigned char)(c) == (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some systems define these; we want our definitions. */
end_comment

begin_undef
undef|#
directive|undef
name|ISPRINT
end_undef

begin_comment
comment|/* Beware:  these only work with single-byte ASCII characters. */
end_comment

begin_define
define|#
directive|define
name|ISALNUM
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isalnum (c))
end_define

begin_define
define|#
directive|define
name|ISALPHA
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isalpha (c))
end_define

begin_define
define|#
directive|define
name|ISDIGIT
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isdigit (c))
end_define

begin_define
define|#
directive|define
name|ISLOWER
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& islower (c))
end_define

begin_define
define|#
directive|define
name|ISPRINT
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isprint (c))
end_define

begin_define
define|#
directive|define
name|ISUPPER
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isupper (c))
end_define

begin_define
define|#
directive|define
name|ISXDIGIT
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isxdigit (c))
end_define

begin_define
define|#
directive|define
name|_rl_lowercase_p
parameter_list|(
name|c
parameter_list|)
value|(NON_NEGATIVE(c)&& ISLOWER(c))
end_define

begin_define
define|#
directive|define
name|_rl_uppercase_p
parameter_list|(
name|c
parameter_list|)
value|(NON_NEGATIVE(c)&& ISUPPER(c))
end_define

begin_define
define|#
directive|define
name|_rl_digit_p
parameter_list|(
name|c
parameter_list|)
value|((c)>= '0'&& (c)<= '9')
end_define

begin_define
define|#
directive|define
name|_rl_pure_alphabetic
parameter_list|(
name|c
parameter_list|)
value|(NON_NEGATIVE(c)&& ISALPHA(c))
end_define

begin_define
define|#
directive|define
name|ALPHABETIC
parameter_list|(
name|c
parameter_list|)
value|(NON_NEGATIVE(c)&& ISALNUM(c))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_rl_to_upper
end_ifndef

begin_define
define|#
directive|define
name|_rl_to_upper
parameter_list|(
name|c
parameter_list|)
value|(_rl_lowercase_p(c) ? toupper((unsigned char)c) : (c))
end_define

begin_define
define|#
directive|define
name|_rl_to_lower
parameter_list|(
name|c
parameter_list|)
value|(_rl_uppercase_p(c) ? tolower((unsigned char)c) : (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_rl_digit_value
end_ifndef

begin_define
define|#
directive|define
name|_rl_digit_value
parameter_list|(
name|x
parameter_list|)
value|((x) - '0')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_rl_isident
end_ifndef

begin_define
define|#
directive|define
name|_rl_isident
parameter_list|(
name|c
parameter_list|)
value|(ISALNUM(c) || (c) == '_')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISOCTAL
end_ifndef

begin_define
define|#
directive|define
name|ISOCTAL
parameter_list|(
name|c
parameter_list|)
value|((c)>= '0'&& (c)<= '7')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OCTVALUE
parameter_list|(
name|c
parameter_list|)
value|((c) - '0')
end_define

begin_define
define|#
directive|define
name|HEXVALUE
parameter_list|(
name|c
parameter_list|)
define|\
value|(((c)>= 'a'&& (c)<= 'f') \   	? (c)-'a'+10 \   	: (c)>= 'A'&& (c)<= 'F' ? (c)-'A'+10 : (c)-'0')
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NEWLINE
end_ifndef

begin_define
define|#
directive|define
name|NEWLINE
value|'\n'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RETURN
end_ifndef

begin_define
define|#
directive|define
name|RETURN
value|CTRL('M')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RUBOUT
end_ifndef

begin_define
define|#
directive|define
name|RUBOUT
value|0x7f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TAB
end_ifndef

begin_define
define|#
directive|define
name|TAB
value|'\t'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ABORT_CHAR
end_ifdef

begin_undef
undef|#
directive|undef
name|ABORT_CHAR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ABORT_CHAR
value|CTRL('G')
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PAGE
end_ifdef

begin_undef
undef|#
directive|undef
name|PAGE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PAGE
value|CTRL('L')
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SPACE
end_ifdef

begin_undef
undef|#
directive|undef
name|SPACE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SPACE
value|' '
end_define

begin_comment
comment|/* XXX - was 0x20 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ESC
end_ifdef

begin_undef
undef|#
directive|undef
name|ESC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ESC
value|CTRL('[')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CHARDEFS_H_ */
end_comment

end_unit

