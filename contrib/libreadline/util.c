begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* util.c -- readline utility functions */
end_comment

begin_comment
comment|/* Copyright (C) 1987, 1989, 1992 Free Software Foundation, Inc.     This file is part of the GNU Readline Library, a library for    reading lines of text with interactive input and history editing.     The GNU Readline Library is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public License    as published by the Free Software Foundation; either version 1, or    (at your option) any later version.     The GNU Readline Library is distributed in the hope that it will be    useful, but WITHOUT ANY WARRANTY; without even the implied warranty    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_define
define|#
directive|define
name|READLINE_LIBRARY
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
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

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
name|HAVE_UNISTD_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/* for _POSIX_VERSION */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_UNISTD_H */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STDLIB_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"ansi_stdlib.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STDLIB_H */
end_comment

begin_comment
comment|/* System-specific feature definitions and include files. */
end_comment

begin_include
include|#
directive|include
file|"rldefs.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TIOCSTAT_IN_SYS_IOCTL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TIOCSTAT_IN_SYS_IOCTL */
end_comment

begin_comment
comment|/* Some standard library routines. */
end_comment

begin_include
include|#
directive|include
file|"readline.h"
end_include

begin_define
define|#
directive|define
name|SWAP
parameter_list|(
name|s
parameter_list|,
name|e
parameter_list|)
value|do { int t; t = s; s = e; e = t; } while (0)
end_define

begin_comment
comment|/* Pseudo-globals imported from readline.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|readline_echoing_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|jmp_buf
name|readline_top_level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rl_line_buffer_len
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Function
modifier|*
name|rl_last_func
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_defining_kbd_macro
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_rl_executing_macro
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pseudo-global functions imported from other library files. */
end_comment

begin_function_decl
specifier|extern
name|void
name|_rl_pop_executing_macro
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_rl_set_the_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_rl_init_argument
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xmalloc
argument_list|()
decl_stmt|,
modifier|*
name|xrealloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*			Utility Functions			    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* Return 0 if C is not a member of the class of characters that belong    in words, or 1 if it is. */
end_comment

begin_decl_stmt
name|int
name|_rl_allow_pathname_alphabetic_chars
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|pathname_alphabetic_chars
init|=
literal|"/-_=~.#$"
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|alphabetic
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
block|{
if|if
condition|(
name|ALPHABETIC
argument_list|(
name|c
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
name|_rl_allow_pathname_alphabetic_chars
operator|&&
name|strchr
argument_list|(
name|pathname_alphabetic_chars
argument_list|,
name|c
argument_list|)
operator|!=
name|NULL
operator|)
return|;
block|}
end_function

begin_comment
comment|/* How to abort things. */
end_comment

begin_function
name|int
name|_rl_abort_internal
parameter_list|()
block|{
name|ding
argument_list|()
expr_stmt|;
name|rl_clear_message
argument_list|()
expr_stmt|;
name|_rl_init_argument
argument_list|()
expr_stmt|;
name|rl_pending_input
operator|=
literal|0
expr_stmt|;
name|_rl_defining_kbd_macro
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|_rl_executing_macro
condition|)
name|_rl_pop_executing_macro
argument_list|()
expr_stmt|;
name|rl_last_func
operator|=
operator|(
name|Function
operator|*
operator|)
name|NULL
expr_stmt|;
name|longjmp
argument_list|(
name|readline_top_level
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|rl_abort
parameter_list|(
name|count
parameter_list|,
name|key
parameter_list|)
name|int
name|count
decl_stmt|,
name|key
decl_stmt|;
block|{
return|return
operator|(
name|_rl_abort_internal
argument_list|()
operator|)
return|;
block|}
end_function

begin_function
name|int
name|rl_tty_status
parameter_list|(
name|count
parameter_list|,
name|key
parameter_list|)
name|int
name|count
decl_stmt|,
name|key
decl_stmt|;
block|{
if|#
directive|if
name|defined
argument_list|(
name|TIOCSTAT
argument_list|)
name|ioctl
argument_list|(
literal|1
argument_list|,
name|TIOCSTAT
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|rl_refresh_line
argument_list|()
expr_stmt|;
else|#
directive|else
name|ding
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Return a copy of the string between FROM and TO.    FROM is inclusive, TO is not. */
end_comment

begin_function
name|char
modifier|*
name|rl_copy_text
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
name|int
name|from
decl_stmt|,
name|to
decl_stmt|;
block|{
specifier|register
name|int
name|length
decl_stmt|;
name|char
modifier|*
name|copy
decl_stmt|;
comment|/* Fix it if the caller is confused. */
if|if
condition|(
name|from
operator|>
name|to
condition|)
name|SWAP
argument_list|(
name|from
argument_list|,
name|to
argument_list|)
expr_stmt|;
name|length
operator|=
name|to
operator|-
name|from
expr_stmt|;
name|copy
operator|=
name|xmalloc
argument_list|(
literal|1
operator|+
name|length
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
name|copy
argument_list|,
name|rl_line_buffer
operator|+
name|from
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|copy
index|[
name|length
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|copy
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Increase the size of RL_LINE_BUFFER until it has enough space to hold    LEN characters. */
end_comment

begin_function
name|void
name|rl_extend_line_buffer
parameter_list|(
name|len
parameter_list|)
name|int
name|len
decl_stmt|;
block|{
while|while
condition|(
name|len
operator|>=
name|rl_line_buffer_len
condition|)
block|{
name|rl_line_buffer_len
operator|+=
name|DEFAULT_BUFFER_SIZE
expr_stmt|;
name|rl_line_buffer
operator|=
name|xrealloc
argument_list|(
name|rl_line_buffer
argument_list|,
name|rl_line_buffer_len
argument_list|)
expr_stmt|;
block|}
name|_rl_set_the_line
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*			String Utility Functions		    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* Determine if s2 occurs in s1.  If so, return a pointer to the    match in s1.  The compare is case insensitive. */
end_comment

begin_function
name|char
modifier|*
name|_rl_strindex
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
specifier|register
name|char
modifier|*
name|s1
decl_stmt|,
decl|*
name|s2
decl_stmt|;
end_function

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|,
name|l
decl_stmt|,
name|len
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|l
operator|=
name|strlen
argument_list|(
name|s2
argument_list|)
operator|,
name|len
operator|=
name|strlen
argument_list|(
name|s1
argument_list|)
init|;
operator|(
name|len
operator|-
name|i
operator|)
operator|>=
name|l
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|_rl_strnicmp
argument_list|(
name|s1
operator|+
name|i
argument_list|,
name|s2
argument_list|,
name|l
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|s1
operator|+
name|i
operator|)
return|;
return|return
operator|(
operator|(
name|char
operator|*
operator|)
name|NULL
operator|)
return|;
block|}
end_block

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_STRCASECMP
argument_list|)
end_if

begin_comment
comment|/* Compare at most COUNT characters from string1 to string2.  Case    doesn't matter. */
end_comment

begin_function
name|int
name|_rl_strnicmp
parameter_list|(
name|string1
parameter_list|,
name|string2
parameter_list|,
name|count
parameter_list|)
name|char
modifier|*
name|string1
decl_stmt|,
decl|*
name|string2
decl_stmt|;
end_function

begin_decl_stmt
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
name|ch1
decl_stmt|,
name|ch2
decl_stmt|;
while|while
condition|(
name|count
condition|)
block|{
name|ch1
operator|=
operator|*
name|string1
operator|++
expr_stmt|;
name|ch2
operator|=
operator|*
name|string2
operator|++
expr_stmt|;
if|if
condition|(
name|_rl_to_upper
argument_list|(
name|ch1
argument_list|)
operator|==
name|_rl_to_upper
argument_list|(
name|ch2
argument_list|)
condition|)
name|count
operator|--
expr_stmt|;
else|else
break|break;
block|}
return|return
operator|(
name|count
operator|)
return|;
block|}
end_block

begin_comment
comment|/* strcmp (), but caseless. */
end_comment

begin_function
name|int
name|_rl_stricmp
parameter_list|(
name|string1
parameter_list|,
name|string2
parameter_list|)
name|char
modifier|*
name|string1
decl_stmt|,
decl|*
name|string2
decl_stmt|;
end_function

begin_block
block|{
specifier|register
name|char
name|ch1
decl_stmt|,
name|ch2
decl_stmt|;
while|while
condition|(
operator|*
name|string1
operator|&&
operator|*
name|string2
condition|)
block|{
name|ch1
operator|=
operator|*
name|string1
operator|++
expr_stmt|;
name|ch2
operator|=
operator|*
name|string2
operator|++
expr_stmt|;
if|if
condition|(
name|_rl_to_upper
argument_list|(
name|ch1
argument_list|)
operator|!=
name|_rl_to_upper
argument_list|(
name|ch2
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
block|}
return|return
operator|(
operator|*
name|string1
operator|-
operator|*
name|string2
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_STRCASECMP */
end_comment

begin_comment
comment|/* Stupid comparison routine for qsort () ing strings. */
end_comment

begin_function
name|int
name|_rl_qsort_string_compare
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
name|char
modifier|*
modifier|*
name|s1
decl_stmt|,
decl|*
modifier|*
name|s2
decl_stmt|;
end_function

begin_block
block|{
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STRCOLL
argument_list|)
return|return
operator|(
name|strcoll
argument_list|(
operator|*
name|s1
argument_list|,
operator|*
name|s2
argument_list|)
operator|)
return|;
else|#
directive|else
name|int
name|result
decl_stmt|;
name|result
operator|=
operator|*
operator|*
name|s1
operator|-
operator|*
operator|*
name|s2
expr_stmt|;
if|if
condition|(
name|result
operator|==
literal|0
condition|)
name|result
operator|=
name|strcmp
argument_list|(
operator|*
name|s1
argument_list|,
operator|*
name|s2
argument_list|)
expr_stmt|;
return|return
name|result
return|;
endif|#
directive|endif
block|}
end_block

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SHELL
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|savestring
end_ifdef

begin_undef
undef|#
directive|undef
name|savestring
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Backwards compatibility, now that savestring has been removed from    all `public' readline header files. */
end_comment

begin_function
name|char
modifier|*
name|savestring
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|char
operator|*
operator|)
name|strcpy
argument_list|(
name|xmalloc
argument_list|(
literal|1
operator|+
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s
argument_list|)
argument_list|)
argument_list|,
operator|(
name|s
operator|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SHELL */
end_comment

begin_comment
comment|/* Function equivalents for the macros defined in chartypes.h. */
end_comment

begin_undef
undef|#
directive|undef
name|_rl_uppercase_p
end_undef

begin_function
name|int
name|_rl_uppercase_p
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
block|{
return|return
operator|(
name|isupper
argument_list|(
name|c
argument_list|)
operator|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|_rl_lowercase_p
end_undef

begin_function
name|int
name|_rl_lowercase_p
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
block|{
return|return
operator|(
name|islower
argument_list|(
name|c
argument_list|)
operator|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|_rl_pure_alphabetic
end_undef

begin_function
name|int
name|_rl_pure_alphabetic
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
block|{
return|return
operator|(
name|isupper
argument_list|(
name|c
argument_list|)
operator|||
name|islower
argument_list|(
name|c
argument_list|)
operator|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|_rl_digit_p
end_undef

begin_function
name|int
name|_rl_digit_p
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
block|{
return|return
operator|(
name|isdigit
argument_list|(
name|c
argument_list|)
operator|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|_rl_to_lower
end_undef

begin_function
name|int
name|_rl_to_lower
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
block|{
return|return
operator|(
name|isupper
argument_list|(
name|c
argument_list|)
condition|?
name|tolower
argument_list|(
name|c
argument_list|)
else|:
name|c
operator|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|_rl_to_upper
end_undef

begin_function
name|int
name|_rl_to_upper
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
block|{
return|return
operator|(
name|islower
argument_list|(
name|c
argument_list|)
condition|?
name|toupper
argument_list|(
name|c
argument_list|)
else|:
name|c
operator|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|_rl_digit_value
end_undef

begin_function
name|int
name|_rl_digit_value
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
block|{
return|return
operator|(
name|isdigit
argument_list|(
name|c
argument_list|)
condition|?
name|c
operator|-
literal|'0'
else|:
name|c
operator|)
return|;
block|}
end_function

end_unit

