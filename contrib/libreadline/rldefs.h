begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rldefs.h -- an attempt to isolate some of the system-specific defines    for readline.  This should be included after any files that define    system-specific constants like _POSIX_VERSION or USG. */
end_comment

begin_comment
comment|/* Copyright (C) 1987,1989 Free Software Foundation, Inc.     This file contains the Readline Library (the Library), a set of    routines for providing Emacs style line input to programs that ask    for it.     The Library is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     The Library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    59 Temple Place, Suite 330, Boston, MA 02111 USA. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_RLDEFS_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_RLDEFS_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CONFIG_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"rlstdc.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|TERMIOS_MISSING
argument_list|)
end_if

begin_define
define|#
directive|define
name|TERMIOS_TTY_DRIVER
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_TERMIO_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|TERMIO_TTY_DRIVER
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NEW_TTY_DRIVER
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
comment|/* Posix macro to check file in statbuf for directory-ness.    This requires that<sys/stat.h> be included before this test. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFDIR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_ISDIR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|(((m)&S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Decide which flavor of the header file describing the C library    string functions to include and include it. */
end_comment

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

begin_comment
comment|/* !HAVE_STRING_H */
end_comment

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
comment|/* !HAVE_STRING_H */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|strchr
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strchr
argument_list|()
decl_stmt|,
modifier|*
name|strrchr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !strchr&& !__STDC__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PREFER_STDARG
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PREFER_VARARGS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<varargs.h>
end_include

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
name|defined
argument_list|(
name|HAVE_STRCASECMP
argument_list|)
end_if

begin_define
define|#
directive|define
name|_rl_stricmp
value|strcasecmp
end_define

begin_define
define|#
directive|define
name|_rl_strnicmp
value|strncasecmp
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|_rl_stricmp
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|;
specifier|extern
name|int
name|_rl_strnicmp
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
argument_list|;
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|emacs_mode
argument_list|)
define|#
directive|define
name|no_mode
value|-1
define|#
directive|define
name|vi_mode
value|0
define|#
directive|define
name|emacs_mode
value|1
endif|#
directive|endif
comment|/* If you cast map[key].function to type (Keymap) on a Cray,    the compiler takes the value of map[key].function and    divides it by 4 to convert between pointer types (pointers    to functions and pointers to structs are different sizes).    This is not what is wanted. */
if|#
directive|if
name|defined
argument_list|(
name|CRAY
argument_list|)
define|#
directive|define
name|FUNCTION_TO_KEYMAP
parameter_list|(
name|map
parameter_list|,
name|key
parameter_list|)
value|(Keymap)((int)map[key].function)
define|#
directive|define
name|KEYMAP_TO_FUNCTION
parameter_list|(
name|data
parameter_list|)
value|(rl_command_func_t *)((int)(data))
else|#
directive|else
define|#
directive|define
name|FUNCTION_TO_KEYMAP
parameter_list|(
name|map
parameter_list|,
name|key
parameter_list|)
value|(Keymap)(map[key].function)
define|#
directive|define
name|KEYMAP_TO_FUNCTION
parameter_list|(
name|data
parameter_list|)
value|(rl_command_func_t *)(data)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|savestring
specifier|extern
name|char
operator|*
name|xmalloc
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
argument_list|;
end_decl_stmt

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

begin_comment
comment|/* Possible values for _rl_bell_preference. */
end_comment

begin_define
define|#
directive|define
name|NO_BELL
value|0
end_define

begin_define
define|#
directive|define
name|AUDIBLE_BELL
value|1
end_define

begin_define
define|#
directive|define
name|VISIBLE_BELL
value|2
end_define

begin_comment
comment|/* Definitions used when searching the line for characters. */
end_comment

begin_comment
comment|/* NOTE: it is necessary that opposite directions are inverses */
end_comment

begin_define
define|#
directive|define
name|FTO
value|1
end_define

begin_comment
comment|/* forward to */
end_comment

begin_define
define|#
directive|define
name|BTO
value|-1
end_define

begin_comment
comment|/* backward to */
end_comment

begin_define
define|#
directive|define
name|FFIND
value|2
end_define

begin_comment
comment|/* forward find */
end_comment

begin_define
define|#
directive|define
name|BFIND
value|-2
end_define

begin_comment
comment|/* backward find */
end_comment

begin_comment
comment|/* Possible values for the found_quote flags word used by the completion    functions.  It says what kind of (shell-like) quoting we found anywhere    in the line. */
end_comment

begin_define
define|#
directive|define
name|RL_QF_SINGLE_QUOTE
value|0x1
end_define

begin_define
define|#
directive|define
name|RL_QF_DOUBLE_QUOTE
value|0x2
end_define

begin_define
define|#
directive|define
name|RL_QF_BACKSLASH
value|0x4
end_define

begin_comment
comment|/* Default readline line buffer length. */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_BUFFER_SIZE
value|256
end_define

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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FREE
argument_list|)
end_if

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
comment|/* CONFIGURATION SECTION */
end_comment

begin_include
include|#
directive|include
file|"rlconf.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RLDEFS_H_ */
end_comment

end_unit

