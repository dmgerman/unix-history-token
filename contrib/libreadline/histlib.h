begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* histlib.h -- internal definitions for the history library. */
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1992 Free Software Foundation, Inc.     This file contains the GNU History Library (the Library), a set of    routines for managing the text of previously typed lines.     The Library is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     The Library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    59 Temple Place, Suite 330, Boston, MA 02111 USA. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_HISTLIB_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_HISTLIB_H_
end_define

begin_comment
comment|/* Function pointers can be declared as (Function *)foo. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_FUNCTION_DEF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_FUNCTION_DEF
end_define

begin_typedef
typedef|typedef
name|int
name|Function
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|VFunction
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|CPFunction
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
modifier|*
name|CPPFunction
parameter_list|()
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FUNCTION_DEF */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STREQ
argument_list|)
end_if

begin_define
define|#
directive|define
name|STREQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)[0] == (b)[0])&& (strcmp ((a), (b)) == 0))
end_define

begin_define
define|#
directive|define
name|STREQN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|(((n) == 0) ? (1) \ 				    : ((a)[0] == (b)[0])&& (strncmp ((a), (b), (n)) == 0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|savestring
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|strcpy
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|savestring
parameter_list|(
name|x
parameter_list|)
value|strcpy (xmalloc (1 + strlen (x)), (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifndef
ifndef|#
directive|ifndef
name|_rl_digit_p
end_ifndef

begin_define
define|#
directive|define
name|_rl_digit_p
parameter_list|(
name|c
parameter_list|)
value|((c)>= '0'&& (c)<= '9')
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
name|c
parameter_list|)
value|((c) - '0')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|member
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|strchr
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|strchr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|member
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
value|((c) ? ((char *)strchr ((s), (c)) != (char *)NULL) : 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FREE
end_ifndef

begin_define
define|#
directive|define
name|FREE
parameter_list|(
name|x
parameter_list|)
value|if (x) free (x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Possible history errors passed to hist_error. */
end_comment

begin_define
define|#
directive|define
name|EVENT_NOT_FOUND
value|0
end_define

begin_define
define|#
directive|define
name|BAD_WORD_SPEC
value|1
end_define

begin_define
define|#
directive|define
name|SUBST_FAILED
value|2
end_define

begin_define
define|#
directive|define
name|BAD_MODIFIER
value|3
end_define

begin_define
define|#
directive|define
name|NO_PREV_SUBST
value|4
end_define

begin_comment
comment|/* Possible definitions for history starting point specification. */
end_comment

begin_define
define|#
directive|define
name|ANCHORED_SEARCH
value|1
end_define

begin_define
define|#
directive|define
name|NON_ANCHORED_SEARCH
value|0
end_define

begin_comment
comment|/* Possible definitions for what style of writing the history file we want. */
end_comment

begin_define
define|#
directive|define
name|HISTORY_APPEND
value|0
end_define

begin_define
define|#
directive|define
name|HISTORY_OVERWRITE
value|1
end_define

begin_comment
comment|/* Some variable definitions shared across history source files. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|history_offset
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_HISTLIB_H_ */
end_comment

end_unit

