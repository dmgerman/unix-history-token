begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* chardefs.h -- Character definitions for readline. */
end_comment

begin_comment
comment|/* Copyright (C) 1994 Free Software Foundation, Inc.     This file is part of the GNU Readline Library, a library for    reading lines of text with interactive input and history editing.     The GNU Readline Library is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public License    as published by the Free Software Foundation; either version 1, or    (at your option) any later version.     The GNU Readline Library is distributed in the hope that it will be    useful, but WITHOUT ANY WARRANTY; without even the implied warranty    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CHARDEFS_H
end_ifndef

begin_define
define|#
directive|define
name|_CHARDEFS_H
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
name|HAVE_STRING_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

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
comment|/* HAVE_STRING_H */
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
value|((c)< control_character_threshold)
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
value|to_upper(((c)|control_character_bit))
end_define

begin_comment
comment|/* Old versions #define lowercase_p(c) (((c)> ('a' - 1)&& (c)< ('z' + 1))) #define uppercase_p(c) (((c)> ('A' - 1)&& (c)< ('Z' + 1))) #define digit_p(c)  ((c)>= '0'&& (c)<= '9') */
end_comment

begin_define
define|#
directive|define
name|lowercase_p
parameter_list|(
name|c
parameter_list|)
value|(islower(c))
end_define

begin_define
define|#
directive|define
name|uppercase_p
parameter_list|(
name|c
parameter_list|)
value|(isupper(c))
end_define

begin_define
define|#
directive|define
name|digit_p
parameter_list|(
name|x
parameter_list|)
value|(isdigit (x))
end_define

begin_define
define|#
directive|define
name|pure_alphabetic
parameter_list|(
name|c
parameter_list|)
value|(lowercase_p(c) || uppercase_p(c))
end_define

begin_comment
comment|/* Old versions #  define to_upper(c) (lowercase_p(c) ? ((c) - 32) : (c)) #  define to_lower(c) (uppercase_p(c) ? ((c) + 32) : (c)) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|to_upper
end_ifndef

begin_define
define|#
directive|define
name|to_upper
parameter_list|(
name|c
parameter_list|)
value|(islower(c) ? toupper(c) : (c))
end_define

begin_define
define|#
directive|define
name|to_lower
parameter_list|(
name|c
parameter_list|)
value|(isupper(c) ? tolower(c) : (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|digit_value
end_ifndef

begin_define
define|#
directive|define
name|digit_value
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
comment|/* _CHARDEFS_H */
end_comment

end_unit

