begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* flags.c -- Everything about flags except the `set' command.  That    is in builtins.c */
end_comment

begin_comment
comment|/* Copyright (C) 1987,1989 Free Software Foundation, Inc.  This file is part of GNU Bash, the Bourne Again SHell.  Bash is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  Bash is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with Bash; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_comment
comment|/* Flags hacking. */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"flags.h"
end_include

begin_include
include|#
directive|include
file|"general.h"
end_include

begin_include
include|#
directive|include
file|"quit.h"
end_include

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*			The Standard Sh Flags.			    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* Non-zero means automatically mark variables which are modified or created    as auto export variables. */
end_comment

begin_decl_stmt
name|int
name|mark_modified_vars
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero causes asynchronous job notification.  Otherwise, job state    notification only takes place just before a primary prompt is printed. */
end_comment

begin_decl_stmt
name|int
name|asynchronous_notification
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means exit immediately if a command exits with a non-zero    exit status. */
end_comment

begin_decl_stmt
name|int
name|exit_immediately_on_error
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means disable filename globbing. */
end_comment

begin_decl_stmt
name|int
name|disallow_filename_globbing
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means to locate and remember function commands as functions are    defined.  Function commands are normally located when the function is    executed. */
end_comment

begin_decl_stmt
name|int
name|locate_commands_in_functions
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means that all keyword arguments are placed into the environment    for a command, not just those that appear on the line before the command    name. */
end_comment

begin_decl_stmt
name|int
name|place_keywords_in_env
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means read commands, but don't execute tham.  This is useful    for debugging shell scripts that should do something hairy and possibly    desctructive. */
end_comment

begin_decl_stmt
name|int
name|read_but_dont_execute
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means end of file is after one command. */
end_comment

begin_decl_stmt
name|int
name|just_one_command
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means don't overwrite existing files while doing redirections. */
end_comment

begin_decl_stmt
name|int
name|noclobber
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means trying to get the value of $i where $i is undefined    causes an error, instead of a null substitution. */
end_comment

begin_decl_stmt
name|int
name|unbound_vars_is_error
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means type out input lines after you read them. */
end_comment

begin_decl_stmt
name|int
name|echo_input_at_read
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means type out the command definition after reading, but    before executing. */
end_comment

begin_decl_stmt
name|int
name|echo_command_at_execute
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means turn off the job control features. */
end_comment

begin_decl_stmt
name|int
name|jobs_m_flag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means this shell is interactive, even if running under a    pipe. */
end_comment

begin_decl_stmt
name|int
name|forced_interactive
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*		     Non-Standard Flags Follow Here.		    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* Non-zero means do lexical scoping in the body of a FOR command. */
end_comment

begin_decl_stmt
name|int
name|lexical_scoping
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means no such thing as invisible variables. */
end_comment

begin_decl_stmt
name|int
name|no_invisible_vars
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means don't look up or remember command names in a hash table, */
end_comment

begin_decl_stmt
name|int
name|hashing_disabled
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means that we are doing history expansion.  The default.    This means !22 gets the 22nd line of history. */
end_comment

begin_decl_stmt
name|int
name|history_expansion
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*			The Flags ALIST.			    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_decl_stmt
name|struct
name|flags_alist
name|shell_flags
index|[]
init|=
block|{
comment|/* Standard sh flags. */
block|{
literal|"a"
block|,
operator|&
name|mark_modified_vars
block|}
block|,
if|#
directive|if
name|defined
argument_list|(
name|JOB_CONTROL
argument_list|)
block|{
literal|"b"
block|,
operator|&
name|asynchronous_notification
block|}
block|,
endif|#
directive|endif
comment|/* JOB_CONTROL */
block|{
literal|"e"
block|,
operator|&
name|exit_immediately_on_error
block|}
block|,
block|{
literal|"f"
block|,
operator|&
name|disallow_filename_globbing
block|}
block|,
block|{
literal|"h"
block|,
operator|&
name|locate_commands_in_functions
block|}
block|,
comment|/* Oh, yeah, good mnemonic. */
block|{
literal|"i"
block|,
operator|&
name|forced_interactive
block|}
block|,
block|{
literal|"k"
block|,
operator|&
name|place_keywords_in_env
block|}
block|,
block|{
literal|"n"
block|,
operator|&
name|read_but_dont_execute
block|}
block|,
block|{
literal|"t"
block|,
operator|&
name|just_one_command
block|}
block|,
block|{
literal|"u"
block|,
operator|&
name|unbound_vars_is_error
block|}
block|,
block|{
literal|"v"
block|,
operator|&
name|echo_input_at_read
block|}
block|,
block|{
literal|"x"
block|,
operator|&
name|echo_command_at_execute
block|}
block|,
block|{
literal|"C"
block|,
operator|&
name|noclobber
block|}
block|,
if|#
directive|if
name|defined
argument_list|(
name|JOB_CONTROL
argument_list|)
block|{
literal|"m"
block|,
operator|&
name|jobs_m_flag
block|}
block|,
endif|#
directive|endif
comment|/* New flags that control non-standard things. */
block|{
literal|"l"
block|,
operator|&
name|lexical_scoping
block|}
block|,
block|{
literal|"I"
block|,
operator|&
name|no_invisible_vars
block|}
block|,
comment|/* I want `h', but locate_commands_in_functions has it.  Great. */
block|{
literal|"d"
block|,
operator|&
name|hashing_disabled
block|}
block|,
comment|/* Once again, we don't have the right mnemonic. */
block|{
literal|"H"
block|,
operator|&
name|history_expansion
block|}
block|,
block|{
operator|(
name|char
operator|*
operator|)
name|NULL
block|,
operator|(
name|int
operator|*
operator|)
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
modifier|*
name|find_flag
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|shell_flags
index|[
name|i
index|]
operator|.
name|name
condition|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|shell_flags
index|[
name|i
index|]
operator|.
name|name
argument_list|,
name|name
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|shell_flags
index|[
name|i
index|]
operator|.
name|value
operator|)
return|;
name|i
operator|++
expr_stmt|;
block|}
return|return
operator|(
operator|(
name|int
operator|*
operator|)
name|FLAG_ERROR
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Change the state of a flag, and return it's original value, or return    FLAG_ERROR if there is no flag called NAME.  ON_OR_OFF should be one    of FLAG_ON or FLAG_OFF. */
end_comment

begin_comment
comment|/* With FLAG being a character. */
end_comment

begin_macro
name|change_flag_char
argument_list|(
argument|flag
argument_list|,
argument|on_or_off
argument_list|)
end_macro

begin_decl_stmt
name|int
name|flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|on_or_off
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|name
index|[
literal|2
index|]
decl_stmt|;
name|name
index|[
literal|0
index|]
operator|=
name|flag
expr_stmt|;
name|name
index|[
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|change_flag
argument_list|(
name|name
argument_list|,
name|on_or_off
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/* With FLAG being a string. */
end_comment

begin_macro
name|change_flag
argument_list|(
argument|flag
argument_list|,
argument|on_or_off
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|on_or_off
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
modifier|*
name|value
init|=
name|find_flag
argument_list|(
name|flag
argument_list|)
decl_stmt|;
name|int
name|old_value
decl_stmt|;
if|if
condition|(
name|value
operator|==
operator|(
name|int
operator|*
operator|)
name|FLAG_ERROR
condition|)
return|return
operator|(
name|FLAG_ERROR
operator|)
return|;
else|else
name|old_value
operator|=
operator|*
name|value
expr_stmt|;
if|if
condition|(
name|on_or_off
operator|==
name|FLAG_ON
condition|)
operator|*
name|value
operator|=
literal|1
expr_stmt|;
else|else
block|{
if|if
condition|(
name|on_or_off
operator|==
name|FLAG_OFF
condition|)
operator|*
name|value
operator|=
literal|0
expr_stmt|;
else|else
return|return
operator|(
name|FLAG_ERROR
operator|)
return|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|JOB_CONTROL
argument_list|)
comment|/* Special hack for the -m flag. */
if|if
condition|(
name|value
operator|==
operator|&
name|jobs_m_flag
condition|)
block|{
extern|extern set_job_control (
block|)
empty_stmt|;
name|set_job_control
argument_list|(
name|on_or_off
operator|==
literal|'-'
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JOB_CONTROL */
end_comment

begin_return
return|return
operator|(
name|old_value
operator|)
return|;
end_return

begin_comment
unit|}
comment|/* Return a string which is the names of all the currently    set shell flags. */
end_comment

begin_expr_stmt
unit|char
operator|*
name|which_set_flags
argument_list|()
block|{
name|char
operator|*
name|temp
operator|=
operator|(
name|char
operator|*
operator|)
name|xmalloc
argument_list|(
literal|1
operator|+
sizeof|sizeof
argument_list|(
name|shell_flags
argument_list|)
operator|/
operator|(
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|char
operator|*
argument_list|)
operator|)
argument_list|)
block|;
name|int
name|index
block|,
name|string_index
operator|=
literal|0
block|;
for|for
control|(
name|index
operator|=
literal|0
init|;
name|shell_flags
index|[
name|index
index|]
operator|.
name|name
condition|;
name|index
operator|++
control|)
if|if
condition|(
operator|*
operator|(
name|shell_flags
index|[
name|index
index|]
operator|.
name|value
operator|)
condition|)
name|temp
index|[
name|string_index
operator|++
index|]
operator|=
operator|*
operator|(
name|shell_flags
index|[
name|index
index|]
operator|.
name|name
operator|)
expr_stmt|;
name|temp
index|[
name|string_index
index|]
operator|=
literal|'\0'
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|temp
operator|)
return|;
end_return

unit|}
end_unit

