begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* callback.c -- functions to use readline as an X `callback' mechanism. */
end_comment

begin_comment
comment|/* Copyright (C) 1987, 1989, 1992 Free Software Foundation, Inc.     This file is part of the GNU Readline Library, a library for    reading lines of text with interactive input and history editing.     The GNU Readline Library is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public License    as published by the Free Software Foundation; either version 2, or    (at your option) any later version.     The GNU Readline Library is distributed in the hope that it will be    useful, but WITHOUT ANY WARRANTY; without even the implied warranty    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    59 Temple Place, Suite 330, Boston, MA 02111 USA. */
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
file|"rlconf.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|READLINE_CALLBACKS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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

begin_include
include|#
directive|include
file|"readline.h"
end_include

begin_include
include|#
directive|include
file|"rlprivate.h"
end_include

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*			Callback Readline Functions                 */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* Allow using readline in situations where a program may have multiple    things to handle at once, and dispatches them via select().  Call    rl_callback_handler_install() with the prompt and a function to call    whenever a complete line of input is ready.  The user must then    call rl_callback_read_char() every time some input is available, and     rl_callback_read_char() will call the user's function with the complete    text read in at each end of line.  The terminal is kept prepped and    signals handled all the time, except during calls to the user's function. */
end_comment

begin_decl_stmt
name|VFunction
modifier|*
name|rl_linefunc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user callback function */
end_comment

begin_decl_stmt
specifier|static
name|int
name|in_handler
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* terminal_prepped and signals set? */
end_comment

begin_comment
comment|/* Make sure the terminal is set up, initialize readline, and prompt. */
end_comment

begin_function
specifier|static
name|void
name|_rl_callback_newline
parameter_list|()
block|{
name|rl_initialize
argument_list|()
expr_stmt|;
if|if
condition|(
name|in_handler
operator|==
literal|0
condition|)
block|{
name|in_handler
operator|=
literal|1
expr_stmt|;
call|(
modifier|*
name|rl_prep_term_function
call|)
argument_list|(
name|_rl_meta_flag
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HANDLE_SIGNALS
argument_list|)
name|rl_set_signals
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
name|readline_internal_setup
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Install a readline handler, set up the terminal, and issue the prompt. */
end_comment

begin_function
name|void
name|rl_callback_handler_install
parameter_list|(
name|prompt
parameter_list|,
name|linefunc
parameter_list|)
name|char
modifier|*
name|prompt
decl_stmt|;
name|VFunction
modifier|*
name|linefunc
decl_stmt|;
block|{
name|rl_prompt
operator|=
name|prompt
expr_stmt|;
name|rl_visible_prompt_length
operator|=
name|rl_prompt
condition|?
name|rl_expand_prompt
argument_list|(
name|rl_prompt
argument_list|)
else|:
literal|0
expr_stmt|;
name|rl_linefunc
operator|=
name|linefunc
expr_stmt|;
name|_rl_callback_newline
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Read one character, and dispatch to the handler if it ends the line. */
end_comment

begin_function
name|void
name|rl_callback_read_char
parameter_list|()
block|{
name|char
modifier|*
name|line
decl_stmt|;
name|int
name|eof
decl_stmt|;
if|if
condition|(
name|rl_linefunc
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"readline: readline_callback_read_char() called with no handler!\r\n"
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
name|eof
operator|=
name|readline_internal_char
argument_list|()
expr_stmt|;
if|if
condition|(
name|rl_done
condition|)
block|{
name|line
operator|=
name|readline_internal_teardown
argument_list|(
name|eof
argument_list|)
expr_stmt|;
call|(
modifier|*
name|rl_deprep_term_function
call|)
argument_list|()
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HANDLE_SIGNALS
argument_list|)
name|rl_clear_signals
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|in_handler
operator|=
literal|0
expr_stmt|;
call|(
modifier|*
name|rl_linefunc
call|)
argument_list|(
name|line
argument_list|)
expr_stmt|;
comment|/* If the user did not clear out the line, do it for him. */
if|if
condition|(
name|rl_line_buffer
index|[
literal|0
index|]
condition|)
name|_rl_init_line_state
argument_list|()
expr_stmt|;
comment|/* Redisplay the prompt if readline_handler_{install,remove} not called. */
if|if
condition|(
name|in_handler
operator|==
literal|0
operator|&&
name|rl_linefunc
condition|)
name|_rl_callback_newline
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* Remove the handler, and make sure the terminal is in its normal state. */
end_comment

begin_function
name|void
name|rl_callback_handler_remove
parameter_list|()
block|{
name|rl_linefunc
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|in_handler
condition|)
block|{
name|in_handler
operator|=
literal|0
expr_stmt|;
call|(
modifier|*
name|rl_deprep_term_function
call|)
argument_list|()
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HANDLE_SIGNALS
argument_list|)
name|rl_clear_signals
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

