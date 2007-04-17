begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* macro.c -- keyboard macros for readline. */
end_comment

begin_comment
comment|/* Copyright (C) 1994 Free Software Foundation, Inc.     This file is part of the GNU Readline Library, a library for    reading lines of text with interactive input and history editing.     The GNU Readline Library is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public License    as published by the Free Software Foundation; either version 2, or    (at your option) any later version.     The GNU Readline Library is distributed in the hope that it will be    useful, but WITHOUT ANY WARRANTY; without even the implied warranty    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    59 Temple Place, Suite 330, Boston, MA 02111 USA. */
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
file|<sys/types.h>
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

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* System-specific feature definitions and include files. */
end_comment

begin_include
include|#
directive|include
file|"rldefs.h"
end_include

begin_comment
comment|/* Some standard library routines. */
end_comment

begin_include
include|#
directive|include
file|"readline.h"
end_include

begin_include
include|#
directive|include
file|"history.h"
end_include

begin_include
include|#
directive|include
file|"rlprivate.h"
end_include

begin_include
include|#
directive|include
file|"xmalloc.h"
end_include

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*			Hacking Keyboard Macros 		    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* The currently executing macro string.  If this is non-zero,    then it is a malloc ()'ed string where input is coming from. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|rl_executing_macro
init|=
operator|(
name|char
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The offset in the above string to the next character to be read. */
end_comment

begin_decl_stmt
specifier|static
name|int
name|executing_macro_index
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The current macro string being built.  Characters get stuffed    in here by add_macro_char (). */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|current_macro
init|=
operator|(
name|char
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The size of the buffer allocated to current_macro. */
end_comment

begin_decl_stmt
specifier|static
name|int
name|current_macro_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The index at which characters are being added to current_macro. */
end_comment

begin_decl_stmt
specifier|static
name|int
name|current_macro_index
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A structure used to save nested macro strings.    It is a linked list of string/index for each saved macro. */
end_comment

begin_struct
struct|struct
name|saved_macro
block|{
name|struct
name|saved_macro
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|string
decl_stmt|;
name|int
name|sindex
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The list of saved macros. */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|saved_macro
modifier|*
name|macro_list
init|=
operator|(
expr|struct
name|saved_macro
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set up to read subsequent input from STRING.    STRING is free ()'ed when we are done with it. */
end_comment

begin_function
name|void
name|_rl_with_macro_input
parameter_list|(
name|string
parameter_list|)
name|char
modifier|*
name|string
decl_stmt|;
block|{
name|_rl_push_executing_macro
argument_list|()
expr_stmt|;
name|rl_executing_macro
operator|=
name|string
expr_stmt|;
name|executing_macro_index
operator|=
literal|0
expr_stmt|;
name|RL_SETSTATE
argument_list|(
name|RL_STATE_MACROINPUT
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Return the next character available from a macro, or 0 if    there are no macro characters. */
end_comment

begin_function
name|int
name|_rl_next_macro_key
parameter_list|()
block|{
name|int
name|c
decl_stmt|;
if|if
condition|(
name|rl_executing_macro
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|rl_executing_macro
index|[
name|executing_macro_index
index|]
operator|==
literal|0
condition|)
block|{
name|_rl_pop_executing_macro
argument_list|()
expr_stmt|;
return|return
operator|(
name|_rl_next_macro_key
argument_list|()
operator|)
return|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|READLINE_CALLBACKS
argument_list|)
name|c
operator|=
name|rl_executing_macro
index|[
name|executing_macro_index
operator|++
index|]
expr_stmt|;
if|if
condition|(
name|RL_ISSTATE
argument_list|(
name|RL_STATE_CALLBACK
argument_list|)
operator|&&
name|RL_ISSTATE
argument_list|(
name|RL_STATE_READCMD
operator||
name|RL_STATE_MOREINPUT
argument_list|)
operator|&&
name|rl_executing_macro
index|[
name|executing_macro_index
index|]
operator|==
literal|0
condition|)
name|_rl_pop_executing_macro
argument_list|()
expr_stmt|;
return|return
name|c
return|;
else|#
directive|else
return|return
operator|(
name|rl_executing_macro
index|[
name|executing_macro_index
operator|++
index|]
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* Save the currently executing macro on a stack of saved macros. */
end_comment

begin_function
name|void
name|_rl_push_executing_macro
parameter_list|()
block|{
name|struct
name|saved_macro
modifier|*
name|saver
decl_stmt|;
name|saver
operator|=
operator|(
expr|struct
name|saved_macro
operator|*
operator|)
name|xmalloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|saved_macro
argument_list|)
argument_list|)
expr_stmt|;
name|saver
operator|->
name|next
operator|=
name|macro_list
expr_stmt|;
name|saver
operator|->
name|sindex
operator|=
name|executing_macro_index
expr_stmt|;
name|saver
operator|->
name|string
operator|=
name|rl_executing_macro
expr_stmt|;
name|macro_list
operator|=
name|saver
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Discard the current macro, replacing it with the one    on the top of the stack of saved macros. */
end_comment

begin_function
name|void
name|_rl_pop_executing_macro
parameter_list|()
block|{
name|struct
name|saved_macro
modifier|*
name|macro
decl_stmt|;
name|FREE
argument_list|(
name|rl_executing_macro
argument_list|)
expr_stmt|;
name|rl_executing_macro
operator|=
operator|(
name|char
operator|*
operator|)
name|NULL
expr_stmt|;
name|executing_macro_index
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|macro_list
condition|)
block|{
name|macro
operator|=
name|macro_list
expr_stmt|;
name|rl_executing_macro
operator|=
name|macro_list
operator|->
name|string
expr_stmt|;
name|executing_macro_index
operator|=
name|macro_list
operator|->
name|sindex
expr_stmt|;
name|macro_list
operator|=
name|macro_list
operator|->
name|next
expr_stmt|;
name|free
argument_list|(
name|macro
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|rl_executing_macro
operator|==
literal|0
condition|)
name|RL_UNSETSTATE
argument_list|(
name|RL_STATE_MACROINPUT
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Add a character to the macro being built. */
end_comment

begin_function
name|void
name|_rl_add_macro_char
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
block|{
if|if
condition|(
name|current_macro_index
operator|+
literal|1
operator|>=
name|current_macro_size
condition|)
block|{
if|if
condition|(
name|current_macro
operator|==
literal|0
condition|)
name|current_macro
operator|=
operator|(
name|char
operator|*
operator|)
name|xmalloc
argument_list|(
name|current_macro_size
operator|=
literal|25
argument_list|)
expr_stmt|;
else|else
name|current_macro
operator|=
operator|(
name|char
operator|*
operator|)
name|xrealloc
argument_list|(
name|current_macro
argument_list|,
name|current_macro_size
operator|+=
literal|25
argument_list|)
expr_stmt|;
block|}
name|current_macro
index|[
name|current_macro_index
operator|++
index|]
operator|=
name|c
expr_stmt|;
name|current_macro
index|[
name|current_macro_index
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
end_function

begin_function
name|void
name|_rl_kill_kbd_macro
parameter_list|()
block|{
if|if
condition|(
name|current_macro
condition|)
block|{
name|free
argument_list|(
name|current_macro
argument_list|)
expr_stmt|;
name|current_macro
operator|=
operator|(
name|char
operator|*
operator|)
name|NULL
expr_stmt|;
block|}
name|current_macro_size
operator|=
name|current_macro_index
operator|=
literal|0
expr_stmt|;
name|FREE
argument_list|(
name|rl_executing_macro
argument_list|)
expr_stmt|;
name|rl_executing_macro
operator|=
operator|(
name|char
operator|*
operator|)
name|NULL
expr_stmt|;
name|executing_macro_index
operator|=
literal|0
expr_stmt|;
name|RL_UNSETSTATE
argument_list|(
name|RL_STATE_MACRODEF
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Begin defining a keyboard macro.    Keystrokes are recorded as they are executed.    End the definition with rl_end_kbd_macro ().    If a numeric argument was explicitly typed, then append this    definition to the end of the existing macro, and start by    re-executing the existing macro. */
end_comment

begin_function
name|int
name|rl_start_kbd_macro
parameter_list|(
name|ignore1
parameter_list|,
name|ignore2
parameter_list|)
name|int
name|ignore1
decl_stmt|,
name|ignore2
decl_stmt|;
block|{
if|if
condition|(
name|RL_ISSTATE
argument_list|(
name|RL_STATE_MACRODEF
argument_list|)
condition|)
block|{
name|_rl_abort_internal
argument_list|()
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|rl_explicit_arg
condition|)
block|{
if|if
condition|(
name|current_macro
condition|)
name|_rl_with_macro_input
argument_list|(
name|savestring
argument_list|(
name|current_macro
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
name|current_macro_index
operator|=
literal|0
expr_stmt|;
name|RL_SETSTATE
argument_list|(
name|RL_STATE_MACRODEF
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Stop defining a keyboard macro.    A numeric argument says to execute the macro right now,    that many times, counting the definition as the first time. */
end_comment

begin_function
name|int
name|rl_end_kbd_macro
parameter_list|(
name|count
parameter_list|,
name|ignore
parameter_list|)
name|int
name|count
decl_stmt|,
name|ignore
decl_stmt|;
block|{
if|if
condition|(
name|RL_ISSTATE
argument_list|(
name|RL_STATE_MACRODEF
argument_list|)
operator|==
literal|0
condition|)
block|{
name|_rl_abort_internal
argument_list|()
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
name|current_macro_index
operator|-=
name|rl_key_sequence_length
operator|-
literal|1
expr_stmt|;
name|current_macro
index|[
name|current_macro_index
index|]
operator|=
literal|'\0'
expr_stmt|;
name|RL_UNSETSTATE
argument_list|(
name|RL_STATE_MACRODEF
argument_list|)
expr_stmt|;
return|return
operator|(
name|rl_call_last_kbd_macro
argument_list|(
operator|--
name|count
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Execute the most recently defined keyboard macro.    COUNT says how many times to execute it. */
end_comment

begin_function
name|int
name|rl_call_last_kbd_macro
parameter_list|(
name|count
parameter_list|,
name|ignore
parameter_list|)
name|int
name|count
decl_stmt|,
name|ignore
decl_stmt|;
block|{
if|if
condition|(
name|current_macro
operator|==
literal|0
condition|)
name|_rl_abort_internal
argument_list|()
expr_stmt|;
if|if
condition|(
name|RL_ISSTATE
argument_list|(
name|RL_STATE_MACRODEF
argument_list|)
condition|)
block|{
name|rl_ding
argument_list|()
expr_stmt|;
comment|/* no recursive macros */
name|current_macro
index|[
operator|--
name|current_macro_index
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* erase this char */
return|return
literal|0
return|;
block|}
while|while
condition|(
name|count
operator|--
condition|)
name|_rl_with_macro_input
argument_list|(
name|savestring
argument_list|(
name|current_macro
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|rl_push_macro_input
parameter_list|(
name|macro
parameter_list|)
name|char
modifier|*
name|macro
decl_stmt|;
block|{
name|_rl_with_macro_input
argument_list|(
name|macro
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

