begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* readline.c -- a general facility for reading lines of input    with emacs style editing and completion. */
end_comment

begin_comment
comment|/* Copyright (C) 1987-2002 Free Software Foundation, Inc.     This file is part of the GNU Readline Library, a library for    reading lines of text with interactive input and history editing.     The GNU Readline Library is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public License    as published by the Free Software Foundation; either version 2, or    (at your option) any later version.     The GNU Readline Library is distributed in the hope that it will be    useful, but WITHOUT ANY WARRANTY; without even the implied warranty    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    59 Temple Place, Suite 330, Boston, MA 02111 USA. */
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

begin_include
include|#
directive|include
file|"posixstat.h"
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYS_FILE_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FILE_H */
end_comment

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_LOCALE_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<locale.h>
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
file|"posixjmp.h"
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
file|"rlmbutil.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__EMX__
argument_list|)
end_if

begin_define
define|#
directive|define
name|INCL_DOSPROCESS
end_define

begin_include
include|#
directive|include
file|<os2.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __EMX__ */
end_comment

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
file|"rlshell.h"
end_include

begin_include
include|#
directive|include
file|"xmalloc.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|RL_LIBRARY_VERSION
end_ifndef

begin_define
define|#
directive|define
name|RL_LIBRARY_VERSION
value|"5.0"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RL_READLINE_VERSION
end_ifndef

begin_define
define|#
directive|define
name|RL_READLINE_VERSION
value|0x0500
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|_rl_free_history_entry
name|PARAMS
argument_list|(
operator|(
name|HIST_ENTRY
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Forward declarations used in this file. */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|readline_internal
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|readline_initialize_everything
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|bind_arrow_keys_internal
name|PARAMS
argument_list|(
operator|(
name|Keymap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|bind_arrow_keys
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|readline_default_bindings
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|reset_default_bindings
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*			Line editing input utility		    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|rl_library_version
init|=
name|RL_LIBRARY_VERSION
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rl_readline_version
init|=
name|RL_READLINE_VERSION
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if this is `real' readline as opposed to some stub substitute. */
end_comment

begin_decl_stmt
name|int
name|rl_gnu_readline_p
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A pointer to the keymap that is currently in use.    By default, it is the standard emacs keymap. */
end_comment

begin_decl_stmt
name|Keymap
name|_rl_keymap
init|=
name|emacs_standard_keymap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The current style of editing. */
end_comment

begin_decl_stmt
name|int
name|rl_editing_mode
init|=
name|emacs_mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The current insert mode:  input (the default) or overwrite */
end_comment

begin_decl_stmt
name|int
name|rl_insert_mode
init|=
name|RL_IM_DEFAULT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero if we called this function from _rl_dispatch().  It's present    so functions can find out whether they were called from a key binding    or directly from an application. */
end_comment

begin_decl_stmt
name|int
name|rl_dispatching
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero if the previous command was a kill command. */
end_comment

begin_decl_stmt
name|int
name|_rl_last_command_was_kill
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The current value of the numeric argument specified by the user. */
end_comment

begin_decl_stmt
name|int
name|rl_numeric_arg
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero if an argument was typed. */
end_comment

begin_decl_stmt
name|int
name|rl_explicit_arg
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Temporary value used while generating the argument. */
end_comment

begin_decl_stmt
name|int
name|rl_arg_sign
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means we have been called at least once before. */
end_comment

begin_decl_stmt
specifier|static
name|int
name|rl_initialized
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* If non-zero, this program is running in an EMACS buffer. */
end_comment

begin_endif
unit|static int running_in_emacs;
endif|#
directive|endif
end_endif

begin_comment
comment|/* Flags word encapsulating the current readline state. */
end_comment

begin_decl_stmt
name|int
name|rl_readline_state
init|=
name|RL_STATE_NONE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The current offset in the current input line. */
end_comment

begin_decl_stmt
name|int
name|rl_point
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Mark in the current input line. */
end_comment

begin_decl_stmt
name|int
name|rl_mark
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Length of the current input line. */
end_comment

begin_decl_stmt
name|int
name|rl_end
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make this non-zero to return the current input_line. */
end_comment

begin_decl_stmt
name|int
name|rl_done
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The last function executed by readline. */
end_comment

begin_decl_stmt
name|rl_command_func_t
modifier|*
name|rl_last_func
init|=
operator|(
name|rl_command_func_t
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Top level environment for readline_internal (). */
end_comment

begin_decl_stmt
name|procenv_t
name|readline_top_level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The streams we interact with. */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|_rl_in_stream
decl_stmt|,
modifier|*
name|_rl_out_stream
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The names of the streams that we do input and output to. */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|rl_instream
init|=
operator|(
name|FILE
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|rl_outstream
init|=
operator|(
name|FILE
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means echo characters as they are read.  Defaults to no echo;    set to 1 if there is a controlling terminal, we can get its attributes,    and the attributes include `echo'.  Look at rltty.c:prepare_terminal_settings    for the code that sets it. */
end_comment

begin_decl_stmt
name|int
name|readline_echoing_p
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current prompt. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|rl_prompt
init|=
operator|(
name|char
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rl_visible_prompt_length
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set to non-zero by calling application if it has already printed rl_prompt    and does not want readline to do it the first time. */
end_comment

begin_decl_stmt
name|int
name|rl_already_prompted
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The number of characters read in order to type this complete command. */
end_comment

begin_decl_stmt
name|int
name|rl_key_sequence_length
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If non-zero, then this is the address of a function to call just    before readline_internal_setup () prints the first prompt. */
end_comment

begin_decl_stmt
name|rl_hook_func_t
modifier|*
name|rl_startup_hook
init|=
operator|(
name|rl_hook_func_t
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If non-zero, this is the address of a function to call just before    readline_internal_setup () returns and readline_internal starts    reading input characters. */
end_comment

begin_decl_stmt
name|rl_hook_func_t
modifier|*
name|rl_pre_input_hook
init|=
operator|(
name|rl_hook_func_t
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* What we use internally.  You should always refer to RL_LINE_BUFFER. */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|the_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The character that can generate an EOF.  Really read from    the terminal driver... just defaulted here. */
end_comment

begin_decl_stmt
name|int
name|_rl_eof_char
init|=
name|CTRL
argument_list|(
literal|'D'
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero makes this the next keystroke to read. */
end_comment

begin_decl_stmt
name|int
name|rl_pending_input
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to a useful terminal name. */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|rl_terminal_name
init|=
operator|(
specifier|const
name|char
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means to always use horizontal scrolling in line display. */
end_comment

begin_decl_stmt
name|int
name|_rl_horizontal_scroll_mode
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means to display an asterisk at the starts of history lines    which have been modified. */
end_comment

begin_decl_stmt
name|int
name|_rl_mark_modified_lines
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The style of `bell' notification preferred.  This can be set to NO_BELL,    AUDIBLE_BELL, or VISIBLE_BELL. */
end_comment

begin_decl_stmt
name|int
name|_rl_bell_preference
init|=
name|AUDIBLE_BELL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* String inserted into the line by rl_insert_comment (). */
end_comment

begin_decl_stmt
name|char
modifier|*
name|_rl_comment_begin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Keymap holding the function currently being executed. */
end_comment

begin_decl_stmt
name|Keymap
name|rl_executing_keymap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means to erase entire line, including prompt, on empty input lines. */
end_comment

begin_decl_stmt
name|int
name|rl_erase_empty_line
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means to read only this many characters rather than up to a    character bound to accept-line. */
end_comment

begin_decl_stmt
name|int
name|rl_num_chars_to_read
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Line buffer and maintenence. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|rl_line_buffer
init|=
operator|(
name|char
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rl_line_buffer_len
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Forward declarations used by the display, termcap, and history code. */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*			`Forward' declarations  		    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* Non-zero means do not parse any lines other than comments and    parser directives. */
end_comment

begin_decl_stmt
name|unsigned
name|char
name|_rl_parsing_conditionalized_out
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means to convert characters with the meta bit set to    escape-prefixed characters so we can indirect through    emacs_meta_keymap or vi_escape_keymap. */
end_comment

begin_decl_stmt
name|int
name|_rl_convert_meta_chars_to_ascii
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means to output characters with the meta bit set directly    rather than as a meta-prefixed escape sequence. */
end_comment

begin_decl_stmt
name|int
name|_rl_output_meta_chars
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
comment|/*			Top Level Functions			    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* Non-zero means treat 0200 bit in terminal input as Meta bit. */
end_comment

begin_decl_stmt
name|int
name|_rl_meta_flag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Forward declaration */
end_comment

begin_comment
comment|/* Set up the prompt and expand it.  Called from readline() and    rl_callback_handler_install (). */
end_comment

begin_function
name|int
name|rl_set_prompt
parameter_list|(
name|prompt
parameter_list|)
specifier|const
name|char
modifier|*
name|prompt
decl_stmt|;
block|{
name|FREE
argument_list|(
name|rl_prompt
argument_list|)
expr_stmt|;
name|rl_prompt
operator|=
name|prompt
condition|?
name|savestring
argument_list|(
name|prompt
argument_list|)
else|:
operator|(
name|char
operator|*
operator|)
name|NULL
expr_stmt|;
name|rl_visible_prompt_length
operator|=
name|rl_expand_prompt
argument_list|(
name|rl_prompt
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Read a line of input.  Prompt with PROMPT.  An empty PROMPT means    none.  A return value of NULL means that EOF was encountered. */
end_comment

begin_function
name|char
modifier|*
name|readline
parameter_list|(
name|prompt
parameter_list|)
specifier|const
name|char
modifier|*
name|prompt
decl_stmt|;
block|{
name|char
modifier|*
name|value
decl_stmt|;
comment|/* If we are at EOF return a NULL string. */
if|if
condition|(
name|rl_pending_input
operator|==
name|EOF
condition|)
block|{
name|rl_clear_pending_input
argument_list|()
expr_stmt|;
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
name|rl_set_prompt
argument_list|(
name|prompt
argument_list|)
expr_stmt|;
name|rl_initialize
argument_list|()
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
name|value
operator|=
name|readline_internal
argument_list|()
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
return|return
operator|(
name|value
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|READLINE_CALLBACKS
argument_list|)
end_if

begin_define
define|#
directive|define
name|STATIC_CALLBACK
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STATIC_CALLBACK
value|static
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|STATIC_CALLBACK
name|void
name|readline_internal_setup
parameter_list|()
block|{
name|char
modifier|*
name|nprompt
decl_stmt|;
name|_rl_in_stream
operator|=
name|rl_instream
expr_stmt|;
name|_rl_out_stream
operator|=
name|rl_outstream
expr_stmt|;
if|if
condition|(
name|rl_startup_hook
condition|)
call|(
modifier|*
name|rl_startup_hook
call|)
argument_list|()
expr_stmt|;
comment|/* If we're not echoing, we still want to at least print a prompt, because      rl_redisplay will not do it for us.  If the calling application has a      custom redisplay function, though, let that function handle it. */
if|if
condition|(
name|readline_echoing_p
operator|==
literal|0
operator|&&
name|rl_redisplay_function
operator|==
name|rl_redisplay
condition|)
block|{
if|if
condition|(
name|rl_prompt
operator|&&
name|rl_already_prompted
operator|==
literal|0
condition|)
block|{
name|nprompt
operator|=
name|_rl_strip_prompt
argument_list|(
name|rl_prompt
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|_rl_out_stream
argument_list|,
literal|"%s"
argument_list|,
name|nprompt
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|_rl_out_stream
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|nprompt
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|rl_prompt
operator|&&
name|rl_already_prompted
condition|)
name|rl_on_new_line_with_prompt
argument_list|()
expr_stmt|;
else|else
name|rl_on_new_line
argument_list|()
expr_stmt|;
call|(
modifier|*
name|rl_redisplay_function
call|)
argument_list|()
expr_stmt|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|VI_MODE
argument_list|)
if|if
condition|(
name|rl_editing_mode
operator|==
name|vi_mode
condition|)
name|rl_vi_insertion_mode
argument_list|(
literal|1
argument_list|,
literal|'i'
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* VI_MODE */
if|if
condition|(
name|rl_pre_input_hook
condition|)
call|(
modifier|*
name|rl_pre_input_hook
call|)
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|STATIC_CALLBACK
name|char
modifier|*
name|readline_internal_teardown
parameter_list|(
name|eof
parameter_list|)
name|int
name|eof
decl_stmt|;
block|{
name|char
modifier|*
name|temp
decl_stmt|;
name|HIST_ENTRY
modifier|*
name|entry
decl_stmt|;
comment|/* Restore the original of this history line, iff the line that we      are editing was originally in the history, AND the line has changed. */
name|entry
operator|=
name|current_history
argument_list|()
expr_stmt|;
if|if
condition|(
name|entry
operator|&&
name|rl_undo_list
condition|)
block|{
name|temp
operator|=
name|savestring
argument_list|(
name|the_line
argument_list|)
expr_stmt|;
name|rl_revert_line
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|entry
operator|=
name|replace_history_entry
argument_list|(
name|where_history
argument_list|()
argument_list|,
name|the_line
argument_list|,
operator|(
name|histdata_t
operator|)
name|NULL
argument_list|)
expr_stmt|;
name|_rl_free_history_entry
argument_list|(
name|entry
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|the_line
argument_list|,
name|temp
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|temp
argument_list|)
expr_stmt|;
block|}
comment|/* At any rate, it is highly likely that this line has an undo list.  Get      rid of it now. */
if|if
condition|(
name|rl_undo_list
condition|)
name|rl_free_undo_list
argument_list|()
expr_stmt|;
comment|/* Restore normal cursor, if available. */
name|_rl_set_insert_mode
argument_list|(
name|RL_IM_INSERT
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|eof
condition|?
operator|(
name|char
operator|*
operator|)
name|NULL
else|:
name|savestring
argument_list|(
name|the_line
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|STATIC_CALLBACK
name|int
if|#
directive|if
name|defined
argument_list|(
name|READLINE_CALLBACKS
argument_list|)
name|readline_internal_char
parameter_list|()
else|#
directive|else
function|readline_internal_charloop
parameter_list|()
endif|#
directive|endif
block|{
specifier|static
name|int
name|lastc
decl_stmt|,
name|eof_found
decl_stmt|;
name|int
name|c
decl_stmt|,
name|code
decl_stmt|,
name|lk
decl_stmt|;
name|lastc
operator|=
operator|-
literal|1
expr_stmt|;
name|eof_found
operator|=
literal|0
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|READLINE_CALLBACKS
argument_list|)
while|while
condition|(
name|rl_done
operator|==
literal|0
condition|)
block|{
endif|#
directive|endif
name|lk
operator|=
name|_rl_last_command_was_kill
expr_stmt|;
name|code
operator|=
name|setjmp
argument_list|(
name|readline_top_level
argument_list|)
expr_stmt|;
if|if
condition|(
name|code
condition|)
call|(
modifier|*
name|rl_redisplay_function
call|)
argument_list|()
expr_stmt|;
if|if
condition|(
name|rl_pending_input
operator|==
literal|0
condition|)
block|{
comment|/* Then initialize the argument and number of keys read. */
name|_rl_init_argument
argument_list|()
expr_stmt|;
name|rl_key_sequence_length
operator|=
literal|0
expr_stmt|;
block|}
name|RL_SETSTATE
argument_list|(
name|RL_STATE_READCMD
argument_list|)
expr_stmt|;
name|c
operator|=
name|rl_read_key
argument_list|()
expr_stmt|;
name|RL_UNSETSTATE
argument_list|(
name|RL_STATE_READCMD
argument_list|)
expr_stmt|;
comment|/* EOF typed to a non-blank line is a<NL>. */
if|if
condition|(
name|c
operator|==
name|EOF
operator|&&
name|rl_end
condition|)
name|c
operator|=
name|NEWLINE
expr_stmt|;
comment|/* The character _rl_eof_char typed to blank line, and not as the 	 previous character is interpreted as EOF. */
if|if
condition|(
operator|(
operator|(
name|c
operator|==
name|_rl_eof_char
operator|&&
name|lastc
operator|!=
name|c
operator|)
operator|||
name|c
operator|==
name|EOF
operator|)
operator|&&
operator|!
name|rl_end
condition|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|READLINE_CALLBACKS
argument_list|)
name|RL_SETSTATE
argument_list|(
name|RL_STATE_DONE
argument_list|)
expr_stmt|;
return|return
operator|(
name|rl_done
operator|=
literal|1
operator|)
return|;
else|#
directive|else
name|eof_found
operator|=
literal|1
expr_stmt|;
break|break;
endif|#
directive|endif
block|}
name|lastc
operator|=
name|c
expr_stmt|;
name|_rl_dispatch
argument_list|(
operator|(
name|unsigned
name|char
operator|)
name|c
argument_list|,
name|_rl_keymap
argument_list|)
expr_stmt|;
comment|/* If there was no change in _rl_last_command_was_kill, then no kill 	 has taken place.  Note that if input is pending we are reading 	 a prefix command, so nothing has changed yet. */
if|if
condition|(
name|rl_pending_input
operator|==
literal|0
operator|&&
name|lk
operator|==
name|_rl_last_command_was_kill
condition|)
name|_rl_last_command_was_kill
operator|=
literal|0
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|VI_MODE
argument_list|)
comment|/* In vi mode, when you exit insert mode, the cursor moves back 	 over the previous character.  We explicitly check for that here. */
if|if
condition|(
name|rl_editing_mode
operator|==
name|vi_mode
operator|&&
name|_rl_keymap
operator|==
name|vi_movement_keymap
condition|)
name|rl_vi_check
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* VI_MODE */
if|if
condition|(
name|rl_num_chars_to_read
operator|&&
name|rl_end
operator|>=
name|rl_num_chars_to_read
condition|)
block|{
call|(
modifier|*
name|rl_redisplay_function
call|)
argument_list|()
expr_stmt|;
name|rl_newline
argument_list|(
literal|1
argument_list|,
literal|'\n'
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|rl_done
operator|==
literal|0
condition|)
call|(
modifier|*
name|rl_redisplay_function
call|)
argument_list|()
expr_stmt|;
comment|/* If the application writer has told us to erase the entire line if 	  the only character typed was something bound to rl_newline, do so. */
if|if
condition|(
name|rl_erase_empty_line
operator|&&
name|rl_done
operator|&&
name|rl_last_func
operator|==
name|rl_newline
operator|&&
name|rl_point
operator|==
literal|0
operator|&&
name|rl_end
operator|==
literal|0
condition|)
name|_rl_erase_entire_line
argument_list|()
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|READLINE_CALLBACKS
argument_list|)
return|return
literal|0
return|;
else|#
directive|else
block|}
return|return
operator|(
name|eof_found
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|READLINE_CALLBACKS
argument_list|)
end_if

begin_function
specifier|static
name|int
name|readline_internal_charloop
parameter_list|()
block|{
name|int
name|eof
init|=
literal|1
decl_stmt|;
while|while
condition|(
name|rl_done
operator|==
literal|0
condition|)
name|eof
operator|=
name|readline_internal_char
argument_list|()
expr_stmt|;
return|return
operator|(
name|eof
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* READLINE_CALLBACKS */
end_comment

begin_comment
comment|/* Read a line of input from the global rl_instream, doing output on    the global rl_outstream.    If rl_prompt is non-null, then that is our prompt. */
end_comment

begin_function
specifier|static
name|char
modifier|*
name|readline_internal
parameter_list|()
block|{
name|int
name|eof
decl_stmt|;
name|readline_internal_setup
argument_list|()
expr_stmt|;
name|eof
operator|=
name|readline_internal_charloop
argument_list|()
expr_stmt|;
return|return
operator|(
name|readline_internal_teardown
argument_list|(
name|eof
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|void
name|_rl_init_line_state
parameter_list|()
block|{
name|rl_point
operator|=
name|rl_end
operator|=
name|rl_mark
operator|=
literal|0
expr_stmt|;
name|the_line
operator|=
name|rl_line_buffer
expr_stmt|;
name|the_line
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
name|void
name|_rl_set_the_line
parameter_list|()
block|{
name|the_line
operator|=
name|rl_line_buffer
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Do the command associated with KEY in MAP.    If the associated command is really a keymap, then read    another key, and dispatch into that map. */
end_comment

begin_function
name|int
name|_rl_dispatch
parameter_list|(
name|key
parameter_list|,
name|map
parameter_list|)
specifier|register
name|int
name|key
decl_stmt|;
name|Keymap
name|map
decl_stmt|;
block|{
return|return
name|_rl_dispatch_subseq
argument_list|(
name|key
argument_list|,
name|map
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|_rl_dispatch_subseq
parameter_list|(
name|key
parameter_list|,
name|map
parameter_list|,
name|got_subseq
parameter_list|)
specifier|register
name|int
name|key
decl_stmt|;
name|Keymap
name|map
decl_stmt|;
name|int
name|got_subseq
decl_stmt|;
block|{
name|int
name|r
decl_stmt|,
name|newkey
decl_stmt|;
name|char
modifier|*
name|macro
decl_stmt|;
name|rl_command_func_t
modifier|*
name|func
decl_stmt|;
if|if
condition|(
name|META_CHAR
argument_list|(
name|key
argument_list|)
operator|&&
name|_rl_convert_meta_chars_to_ascii
condition|)
block|{
if|if
condition|(
name|map
index|[
name|ESC
index|]
operator|.
name|type
operator|==
name|ISKMAP
condition|)
block|{
if|if
condition|(
name|RL_ISSTATE
argument_list|(
name|RL_STATE_MACRODEF
argument_list|)
condition|)
name|_rl_add_macro_char
argument_list|(
name|ESC
argument_list|)
expr_stmt|;
name|map
operator|=
name|FUNCTION_TO_KEYMAP
argument_list|(
name|map
argument_list|,
name|ESC
argument_list|)
expr_stmt|;
name|key
operator|=
name|UNMETA
argument_list|(
name|key
argument_list|)
expr_stmt|;
name|rl_key_sequence_length
operator|+=
literal|2
expr_stmt|;
return|return
operator|(
name|_rl_dispatch
argument_list|(
name|key
argument_list|,
name|map
argument_list|)
operator|)
return|;
block|}
else|else
name|rl_ding
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
if|if
condition|(
name|RL_ISSTATE
argument_list|(
name|RL_STATE_MACRODEF
argument_list|)
condition|)
name|_rl_add_macro_char
argument_list|(
name|key
argument_list|)
expr_stmt|;
name|r
operator|=
literal|0
expr_stmt|;
switch|switch
condition|(
name|map
index|[
name|key
index|]
operator|.
name|type
condition|)
block|{
case|case
name|ISFUNC
case|:
name|func
operator|=
name|map
index|[
name|key
index|]
operator|.
name|function
expr_stmt|;
if|if
condition|(
name|func
condition|)
block|{
comment|/* Special case rl_do_lowercase_version (). */
if|if
condition|(
name|func
operator|==
name|rl_do_lowercase_version
condition|)
return|return
operator|(
name|_rl_dispatch
argument_list|(
name|_rl_to_lower
argument_list|(
name|key
argument_list|)
argument_list|,
name|map
argument_list|)
operator|)
return|;
name|rl_executing_keymap
operator|=
name|map
expr_stmt|;
if|#
directive|if
literal|0
block|_rl_suppress_redisplay = (map[key].function == rl_insert)&& _rl_input_available ();
endif|#
directive|endif
name|rl_dispatching
operator|=
literal|1
expr_stmt|;
name|RL_SETSTATE
argument_list|(
name|RL_STATE_DISPATCHING
argument_list|)
expr_stmt|;
name|r
operator|=
operator|(
operator|*
name|map
index|[
name|key
index|]
operator|.
name|function
operator|)
operator|(
name|rl_numeric_arg
operator|*
name|rl_arg_sign
operator|,
name|key
operator|)
expr_stmt|;
name|RL_UNSETSTATE
argument_list|(
name|RL_STATE_DISPATCHING
argument_list|)
expr_stmt|;
name|rl_dispatching
operator|=
literal|0
expr_stmt|;
comment|/* If we have input pending, then the last command was a prefix 	     command.  Don't change the state of rl_last_func.  Otherwise, 	     remember the last command executed in this variable. */
if|if
condition|(
name|rl_pending_input
operator|==
literal|0
operator|&&
name|map
index|[
name|key
index|]
operator|.
name|function
operator|!=
name|rl_digit_argument
condition|)
name|rl_last_func
operator|=
name|map
index|[
name|key
index|]
operator|.
name|function
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|map
index|[
name|ANYOTHERKEY
index|]
operator|.
name|function
condition|)
block|{
comment|/* OK, there's no function bound in this map, but there is a 	     shadow function that was overridden when the current keymap 	     was created.  Return -2 to note  that. */
name|_rl_unget_char
argument_list|(
name|key
argument_list|)
expr_stmt|;
return|return
operator|-
literal|2
return|;
block|}
elseif|else
if|if
condition|(
name|got_subseq
condition|)
block|{
comment|/* Return -1 to note that we're in a subsequence, but  we don't 	     have a matching key, nor was one overridden.  This means 	     we need to back up the recursion chain and find the last 	     subsequence that is bound to a function. */
name|_rl_unget_char
argument_list|(
name|key
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
else|else
block|{
name|_rl_abort_internal
argument_list|()
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
break|break;
case|case
name|ISKMAP
case|:
if|if
condition|(
name|map
index|[
name|key
index|]
operator|.
name|function
operator|!=
literal|0
condition|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|VI_MODE
argument_list|)
comment|/* The only way this test will be true is if a subsequence has been 	     bound starting with ESC, generally the arrow keys.  What we do is 	     check whether there's input in the queue, which there generally 	     will be if an arrow key has been pressed, and, if there's not, 	     just dispatch to (what we assume is) rl_vi_movement_mode right 	     away.  This is essentially an input test with a zero timeout. */
if|if
condition|(
name|rl_editing_mode
operator|==
name|vi_mode
operator|&&
name|key
operator|==
name|ESC
operator|&&
name|map
operator|==
name|vi_insertion_keymap
operator|&&
name|_rl_input_queued
argument_list|(
literal|0
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|_rl_dispatch
argument_list|(
name|ANYOTHERKEY
argument_list|,
name|FUNCTION_TO_KEYMAP
argument_list|(
name|map
argument_list|,
name|key
argument_list|)
argument_list|)
operator|)
return|;
endif|#
directive|endif
name|rl_key_sequence_length
operator|++
expr_stmt|;
if|if
condition|(
name|key
operator|==
name|ESC
condition|)
name|RL_SETSTATE
argument_list|(
name|RL_STATE_METANEXT
argument_list|)
expr_stmt|;
name|RL_SETSTATE
argument_list|(
name|RL_STATE_MOREINPUT
argument_list|)
expr_stmt|;
name|newkey
operator|=
name|rl_read_key
argument_list|()
expr_stmt|;
name|RL_UNSETSTATE
argument_list|(
name|RL_STATE_MOREINPUT
argument_list|)
expr_stmt|;
if|if
condition|(
name|key
operator|==
name|ESC
condition|)
name|RL_UNSETSTATE
argument_list|(
name|RL_STATE_METANEXT
argument_list|)
expr_stmt|;
if|if
condition|(
name|newkey
operator|<
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
name|r
operator|=
name|_rl_dispatch_subseq
argument_list|(
name|newkey
argument_list|,
name|FUNCTION_TO_KEYMAP
argument_list|(
name|map
argument_list|,
name|key
argument_list|)
argument_list|,
name|got_subseq
operator|||
name|map
index|[
name|ANYOTHERKEY
index|]
operator|.
name|function
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|==
operator|-
literal|2
condition|)
comment|/* We didn't match anything, and the keymap we're indexed into 	       shadowed a function previously bound to that prefix.  Call 	       the function.  The recursive call to _rl_dispatch_subseq has 	       already taken care of pushing any necessary input back onto 	       the input queue with _rl_unget_char. */
block|{
if|#
directive|if
literal|0
block|r = _rl_dispatch (ANYOTHERKEY, FUNCTION_TO_KEYMAP (map, key));
else|#
directive|else
comment|/* XXX - experimental code -- might never be executed.  Save 		 for later. */
name|Keymap
name|m
init|=
name|FUNCTION_TO_KEYMAP
argument_list|(
name|map
argument_list|,
name|key
argument_list|)
decl_stmt|;
name|int
name|type
init|=
name|m
index|[
name|ANYOTHERKEY
index|]
operator|.
name|type
decl_stmt|;
name|func
operator|=
name|m
index|[
name|ANYOTHERKEY
index|]
operator|.
name|function
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|ISFUNC
operator|&&
name|func
operator|==
name|rl_do_lowercase_version
condition|)
name|r
operator|=
name|_rl_dispatch
argument_list|(
name|_rl_to_lower
argument_list|(
name|key
argument_list|)
argument_list|,
name|map
argument_list|)
expr_stmt|;
else|else
name|r
operator|=
name|_rl_dispatch
argument_list|(
name|ANYOTHERKEY
argument_list|,
name|m
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
elseif|else
if|if
condition|(
name|r
operator|&&
name|map
index|[
name|ANYOTHERKEY
index|]
operator|.
name|function
condition|)
block|{
comment|/* We didn't match (r is probably -1), so return something to 		 tell the caller that it should try ANYOTHERKEY for an 		 overridden function. */
name|_rl_unget_char
argument_list|(
name|key
argument_list|)
expr_stmt|;
return|return
operator|-
literal|2
return|;
block|}
elseif|else
if|if
condition|(
name|r
operator|&&
name|got_subseq
condition|)
block|{
comment|/* OK, back up the chain. */
name|_rl_unget_char
argument_list|(
name|key
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
block|}
else|else
block|{
name|_rl_abort_internal
argument_list|()
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
break|break;
case|case
name|ISMACR
case|:
if|if
condition|(
name|map
index|[
name|key
index|]
operator|.
name|function
operator|!=
literal|0
condition|)
block|{
name|macro
operator|=
name|savestring
argument_list|(
operator|(
name|char
operator|*
operator|)
name|map
index|[
name|key
index|]
operator|.
name|function
argument_list|)
expr_stmt|;
name|_rl_with_macro_input
argument_list|(
name|macro
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
break|break;
block|}
if|#
directive|if
name|defined
argument_list|(
name|VI_MODE
argument_list|)
if|if
condition|(
name|rl_editing_mode
operator|==
name|vi_mode
operator|&&
name|_rl_keymap
operator|==
name|vi_movement_keymap
operator|&&
name|key
operator|!=
name|ANYOTHERKEY
operator|&&
name|_rl_vi_textmod_command
argument_list|(
name|key
argument_list|)
condition|)
name|_rl_vi_set_last
argument_list|(
name|key
argument_list|,
name|rl_numeric_arg
argument_list|,
name|rl_arg_sign
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|r
operator|)
return|;
block|}
end_function

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*			Initializations 			    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* Initialize readline (and terminal if not already). */
end_comment

begin_function
name|int
name|rl_initialize
parameter_list|()
block|{
comment|/* If we have never been called before, initialize the      terminal and data structures. */
if|if
condition|(
operator|!
name|rl_initialized
condition|)
block|{
name|RL_SETSTATE
argument_list|(
name|RL_STATE_INITIALIZING
argument_list|)
expr_stmt|;
name|readline_initialize_everything
argument_list|()
expr_stmt|;
name|RL_UNSETSTATE
argument_list|(
name|RL_STATE_INITIALIZING
argument_list|)
expr_stmt|;
name|rl_initialized
operator|++
expr_stmt|;
name|RL_SETSTATE
argument_list|(
name|RL_STATE_INITIALIZED
argument_list|)
expr_stmt|;
block|}
comment|/* Initalize the current line information. */
name|_rl_init_line_state
argument_list|()
expr_stmt|;
comment|/* We aren't done yet.  We haven't even gotten started yet! */
name|rl_done
operator|=
literal|0
expr_stmt|;
name|RL_UNSETSTATE
argument_list|(
name|RL_STATE_DONE
argument_list|)
expr_stmt|;
comment|/* Tell the history routines what is going on. */
name|_rl_start_using_history
argument_list|()
expr_stmt|;
comment|/* Make the display buffer match the state of the line. */
name|rl_reset_line_state
argument_list|()
expr_stmt|;
comment|/* No such function typed yet. */
name|rl_last_func
operator|=
operator|(
name|rl_command_func_t
operator|*
operator|)
name|NULL
expr_stmt|;
comment|/* Parsing of key-bindings begins in an enabled state. */
name|_rl_parsing_conditionalized_out
operator|=
literal|0
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|VI_MODE
argument_list|)
if|if
condition|(
name|rl_editing_mode
operator|==
name|vi_mode
condition|)
name|_rl_vi_initialize_line
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* Each line starts in insert mode (the default). */
name|_rl_set_insert_mode
argument_list|(
name|RL_IM_DEFAULT
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__EMX__
argument_list|)
end_if

begin_endif
unit|static void _emx_build_environ () {   TIB *tibp;   PIB *pibp;   char *t, **tp;   int c;    DosGetInfoBlocks (&tibp,&pibp);   t = pibp->pib_pchenv;   for (c = 1; *t; c++)     t += strlen (t) + 1;   tp = environ = (char **)xmalloc ((c + 1) * sizeof (char *));   t = pibp->pib_pchenv;   while (*t)     {       *tp++ = t;       t += strlen (t) + 1;     }   *tp = 0; }
endif|#
directive|endif
end_endif

begin_comment
comment|/* __EMX__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Initialize the entire state of the world. */
end_comment

begin_function
specifier|static
name|void
name|readline_initialize_everything
parameter_list|()
block|{
if|#
directive|if
literal|0
if|#
directive|if
name|defined
argument_list|(
name|__EMX__
argument_list|)
block|if (environ == 0)     _emx_build_environ ();
endif|#
directive|endif
endif|#
directive|endif
if|#
directive|if
literal|0
comment|/* Find out if we are running in Emacs -- UNUSED. */
block|running_in_emacs = sh_get_env_value ("EMACS") != (char *)0;
endif|#
directive|endif
comment|/* Set up input and output if they are not already set up. */
if|if
condition|(
operator|!
name|rl_instream
condition|)
name|rl_instream
operator|=
name|stdin
expr_stmt|;
if|if
condition|(
operator|!
name|rl_outstream
condition|)
name|rl_outstream
operator|=
name|stdout
expr_stmt|;
comment|/* Bind _rl_in_stream and _rl_out_stream immediately.  These values      may change, but they may also be used before readline_internal ()      is called. */
name|_rl_in_stream
operator|=
name|rl_instream
expr_stmt|;
name|_rl_out_stream
operator|=
name|rl_outstream
expr_stmt|;
comment|/* Allocate data structures. */
if|if
condition|(
name|rl_line_buffer
operator|==
literal|0
condition|)
name|rl_line_buffer
operator|=
operator|(
name|char
operator|*
operator|)
name|xmalloc
argument_list|(
name|rl_line_buffer_len
operator|=
name|DEFAULT_BUFFER_SIZE
argument_list|)
expr_stmt|;
comment|/* Initialize the terminal interface. */
if|if
condition|(
name|rl_terminal_name
operator|==
literal|0
condition|)
name|rl_terminal_name
operator|=
name|sh_get_env_value
argument_list|(
literal|"TERM"
argument_list|)
expr_stmt|;
name|_rl_init_terminal_io
argument_list|(
name|rl_terminal_name
argument_list|)
expr_stmt|;
comment|/* Bind tty characters to readline functions. */
name|readline_default_bindings
argument_list|()
expr_stmt|;
comment|/* Initialize the function names. */
name|rl_initialize_funmap
argument_list|()
expr_stmt|;
comment|/* Decide whether we should automatically go into eight-bit mode. */
name|_rl_init_eightbit
argument_list|()
expr_stmt|;
comment|/* Read in the init file. */
name|rl_read_init_file
argument_list|(
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
comment|/* XXX */
if|if
condition|(
name|_rl_horizontal_scroll_mode
operator|&&
name|_rl_term_autowrap
condition|)
block|{
name|_rl_screenwidth
operator|--
expr_stmt|;
name|_rl_screenchars
operator|-=
name|_rl_screenheight
expr_stmt|;
block|}
comment|/* Override the effect of any `set keymap' assignments in the      inputrc file. */
name|rl_set_keymap_from_edit_mode
argument_list|()
expr_stmt|;
comment|/* Try to bind a common arrow key prefix, if not already bound. */
name|bind_arrow_keys
argument_list|()
expr_stmt|;
comment|/* Enable the meta key, if this terminal has one. */
if|if
condition|(
name|_rl_enable_meta
condition|)
name|_rl_enable_meta_key
argument_list|()
expr_stmt|;
comment|/* If the completion parser's default word break characters haven't      been set yet, then do so now. */
if|if
condition|(
name|rl_completer_word_break_characters
operator|==
operator|(
name|char
operator|*
operator|)
name|NULL
condition|)
name|rl_completer_word_break_characters
operator|=
operator|(
name|char
operator|*
operator|)
name|rl_basic_word_break_characters
expr_stmt|;
block|}
end_function

begin_comment
comment|/* If this system allows us to look at the values of the regular    input editing characters, then bind them to their readline    equivalents, iff the characters are not bound to keymaps. */
end_comment

begin_function
specifier|static
name|void
name|readline_default_bindings
parameter_list|()
block|{
name|rl_tty_set_default_bindings
argument_list|(
name|_rl_keymap
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Reset the default bindings for the terminal special characters we're    interested in back to rl_insert and read the new ones. */
end_comment

begin_function
specifier|static
name|void
name|reset_default_bindings
parameter_list|()
block|{
name|rl_tty_unset_default_bindings
argument_list|(
name|_rl_keymap
argument_list|)
expr_stmt|;
name|rl_tty_set_default_bindings
argument_list|(
name|_rl_keymap
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Bind some common arrow key sequences in MAP. */
end_comment

begin_function
specifier|static
name|void
name|bind_arrow_keys_internal
parameter_list|(
name|map
parameter_list|)
name|Keymap
name|map
decl_stmt|;
block|{
name|Keymap
name|xkeymap
decl_stmt|;
name|xkeymap
operator|=
name|_rl_keymap
expr_stmt|;
name|_rl_keymap
operator|=
name|map
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
name|rl_bind_keyseq_if_unbound
argument_list|(
literal|"\033[0A"
argument_list|,
name|rl_get_previous_history
argument_list|)
expr_stmt|;
name|rl_bind_keyseq_if_unbound
argument_list|(
literal|"\033[0B"
argument_list|,
name|rl_backward_char
argument_list|)
expr_stmt|;
name|rl_bind_keyseq_if_unbound
argument_list|(
literal|"\033[0C"
argument_list|,
name|rl_forward_char
argument_list|)
expr_stmt|;
name|rl_bind_keyseq_if_unbound
argument_list|(
literal|"\033[0D"
argument_list|,
name|rl_get_next_history
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|rl_bind_keyseq_if_unbound
argument_list|(
literal|"\033[A"
argument_list|,
name|rl_get_previous_history
argument_list|)
expr_stmt|;
name|rl_bind_keyseq_if_unbound
argument_list|(
literal|"\033[B"
argument_list|,
name|rl_get_next_history
argument_list|)
expr_stmt|;
name|rl_bind_keyseq_if_unbound
argument_list|(
literal|"\033[C"
argument_list|,
name|rl_forward_char
argument_list|)
expr_stmt|;
name|rl_bind_keyseq_if_unbound
argument_list|(
literal|"\033[D"
argument_list|,
name|rl_backward_char
argument_list|)
expr_stmt|;
name|rl_bind_keyseq_if_unbound
argument_list|(
literal|"\033[H"
argument_list|,
name|rl_beg_of_line
argument_list|)
expr_stmt|;
name|rl_bind_keyseq_if_unbound
argument_list|(
literal|"\033[F"
argument_list|,
name|rl_end_of_line
argument_list|)
expr_stmt|;
name|rl_bind_keyseq_if_unbound
argument_list|(
literal|"\033OA"
argument_list|,
name|rl_get_previous_history
argument_list|)
expr_stmt|;
name|rl_bind_keyseq_if_unbound
argument_list|(
literal|"\033OB"
argument_list|,
name|rl_get_next_history
argument_list|)
expr_stmt|;
name|rl_bind_keyseq_if_unbound
argument_list|(
literal|"\033OC"
argument_list|,
name|rl_forward_char
argument_list|)
expr_stmt|;
name|rl_bind_keyseq_if_unbound
argument_list|(
literal|"\033OD"
argument_list|,
name|rl_backward_char
argument_list|)
expr_stmt|;
name|rl_bind_keyseq_if_unbound
argument_list|(
literal|"\033OH"
argument_list|,
name|rl_beg_of_line
argument_list|)
expr_stmt|;
name|rl_bind_keyseq_if_unbound
argument_list|(
literal|"\033OF"
argument_list|,
name|rl_end_of_line
argument_list|)
expr_stmt|;
name|_rl_keymap
operator|=
name|xkeymap
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Try and bind the common arrow key prefixes after giving termcap and    the inputrc file a chance to bind them and create `real' keymaps    for the arrow key prefix. */
end_comment

begin_function
specifier|static
name|void
name|bind_arrow_keys
parameter_list|()
block|{
name|bind_arrow_keys_internal
argument_list|(
name|emacs_standard_keymap
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|VI_MODE
argument_list|)
name|bind_arrow_keys_internal
argument_list|(
name|vi_movement_keymap
argument_list|)
expr_stmt|;
name|bind_arrow_keys_internal
argument_list|(
name|vi_insertion_keymap
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*		Saving and Restoring Readline's state		    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_function
name|int
name|rl_save_state
parameter_list|(
name|sp
parameter_list|)
name|struct
name|readline_state
modifier|*
name|sp
decl_stmt|;
block|{
if|if
condition|(
name|sp
operator|==
literal|0
condition|)
return|return
operator|-
literal|1
return|;
name|sp
operator|->
name|point
operator|=
name|rl_point
expr_stmt|;
name|sp
operator|->
name|end
operator|=
name|rl_end
expr_stmt|;
name|sp
operator|->
name|mark
operator|=
name|rl_mark
expr_stmt|;
name|sp
operator|->
name|buffer
operator|=
name|rl_line_buffer
expr_stmt|;
name|sp
operator|->
name|buflen
operator|=
name|rl_line_buffer_len
expr_stmt|;
name|sp
operator|->
name|ul
operator|=
name|rl_undo_list
expr_stmt|;
name|sp
operator|->
name|prompt
operator|=
name|rl_prompt
expr_stmt|;
name|sp
operator|->
name|rlstate
operator|=
name|rl_readline_state
expr_stmt|;
name|sp
operator|->
name|done
operator|=
name|rl_done
expr_stmt|;
name|sp
operator|->
name|kmap
operator|=
name|_rl_keymap
expr_stmt|;
name|sp
operator|->
name|lastfunc
operator|=
name|rl_last_func
expr_stmt|;
name|sp
operator|->
name|insmode
operator|=
name|rl_insert_mode
expr_stmt|;
name|sp
operator|->
name|edmode
operator|=
name|rl_editing_mode
expr_stmt|;
name|sp
operator|->
name|kseqlen
operator|=
name|rl_key_sequence_length
expr_stmt|;
name|sp
operator|->
name|inf
operator|=
name|rl_instream
expr_stmt|;
name|sp
operator|->
name|outf
operator|=
name|rl_outstream
expr_stmt|;
name|sp
operator|->
name|pendingin
operator|=
name|rl_pending_input
expr_stmt|;
name|sp
operator|->
name|macro
operator|=
name|rl_executing_macro
expr_stmt|;
name|sp
operator|->
name|catchsigs
operator|=
name|rl_catch_signals
expr_stmt|;
name|sp
operator|->
name|catchsigwinch
operator|=
name|rl_catch_sigwinch
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
name|rl_restore_state
parameter_list|(
name|sp
parameter_list|)
name|struct
name|readline_state
modifier|*
name|sp
decl_stmt|;
block|{
if|if
condition|(
name|sp
operator|==
literal|0
condition|)
return|return
operator|-
literal|1
return|;
name|rl_point
operator|=
name|sp
operator|->
name|point
expr_stmt|;
name|rl_end
operator|=
name|sp
operator|->
name|end
expr_stmt|;
name|rl_mark
operator|=
name|sp
operator|->
name|mark
expr_stmt|;
name|the_line
operator|=
name|rl_line_buffer
operator|=
name|sp
operator|->
name|buffer
expr_stmt|;
name|rl_line_buffer_len
operator|=
name|sp
operator|->
name|buflen
expr_stmt|;
name|rl_undo_list
operator|=
name|sp
operator|->
name|ul
expr_stmt|;
name|rl_prompt
operator|=
name|sp
operator|->
name|prompt
expr_stmt|;
name|rl_readline_state
operator|=
name|sp
operator|->
name|rlstate
expr_stmt|;
name|rl_done
operator|=
name|sp
operator|->
name|done
expr_stmt|;
name|_rl_keymap
operator|=
name|sp
operator|->
name|kmap
expr_stmt|;
name|rl_last_func
operator|=
name|sp
operator|->
name|lastfunc
expr_stmt|;
name|rl_insert_mode
operator|=
name|sp
operator|->
name|insmode
expr_stmt|;
name|rl_editing_mode
operator|=
name|sp
operator|->
name|edmode
expr_stmt|;
name|rl_key_sequence_length
operator|=
name|sp
operator|->
name|kseqlen
expr_stmt|;
name|rl_instream
operator|=
name|sp
operator|->
name|inf
expr_stmt|;
name|rl_outstream
operator|=
name|sp
operator|->
name|outf
expr_stmt|;
name|rl_pending_input
operator|=
name|sp
operator|->
name|pendingin
expr_stmt|;
name|rl_executing_macro
operator|=
name|sp
operator|->
name|macro
expr_stmt|;
name|rl_catch_signals
operator|=
name|sp
operator|->
name|catchsigs
expr_stmt|;
name|rl_catch_sigwinch
operator|=
name|sp
operator|->
name|catchsigwinch
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

