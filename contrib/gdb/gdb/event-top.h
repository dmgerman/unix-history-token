begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions used by event-top.c, for GDB, the GNU debugger.     Copyright 1999, 2001, 2003 Free Software Foundation, Inc.     Written by Elena Zannoni<ezannoni@cygnus.com> of Cygnus Solutions.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVENT_TOP_H
end_ifndef

begin_define
define|#
directive|define
name|EVENT_TOP_H
end_define

begin_struct_decl
struct_decl|struct
name|cmd_list_element
struct_decl|;
end_struct_decl

begin_comment
comment|/* Stack for prompts.  Each prompt is composed as a prefix, a prompt    and a suffix.  The prompt to be displayed at any given time is the    one on top of the stack.  A stack is necessary because of cases in    which the execution of a gdb command requires further input from    the user, like for instance 'commands' for breakpoints and    'actions' for tracepoints.  In these cases, the prompt is '>' and    gdb should process input using the asynchronous readline interface    and the event loop.  In order to achieve this, we need to save    somewhere the state of GDB, i.e. that it is processing user input    as part of a command and not as part of the top level command loop.    The prompt stack represents part of the saved state.  Another part    would be the function that readline would invoke after a whole line    of input has ben entered.  This second piece would be something    like, for instance, where to return within the code for the actions    commands after a line has been read.  This latter portion has not    beeen implemented yet.  The need for a 3-part prompt arises from    the annotation level.  When this is set to 2, the prompt is    actually composed of a prefix, the prompt itself and a suffix.  */
end_comment

begin_comment
comment|/* At any particular time there will be always at least one prompt on    the stack, the one being currently displayed by gdb.  If gdb is    using annotation level equal 2, there will be 2 prompts on the    stack: the usual one, w/o prefix and suffix (at top - 1), and the    'composite' one with prefix and suffix added (at top).  At this    time, this is the only use of the prompt stack.  Resetting annotate    to 0 or 1, pops the top of the stack, resetting its size to one    element.  The MAXPROMPTS limit is safe, for now.  Once other cases    are dealt with (like the different prompts used for 'commands' or    'actions') this array implementation of the prompt stack may have    to change.  */
end_comment

begin_define
define|#
directive|define
name|MAXPROMPTS
value|10
end_define

begin_struct
struct|struct
name|prompts
block|{
struct|struct
block|{
name|char
modifier|*
name|prefix
decl_stmt|;
name|char
modifier|*
name|prompt
decl_stmt|;
name|char
modifier|*
name|suffix
decl_stmt|;
block|}
name|prompt_stack
index|[
name|MAXPROMPTS
index|]
struct|;
name|int
name|top
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PROMPT
parameter_list|(
name|X
parameter_list|)
value|the_prompts.prompt_stack[the_prompts.top + X].prompt
end_define

begin_define
define|#
directive|define
name|PREFIX
parameter_list|(
name|X
parameter_list|)
value|the_prompts.prompt_stack[the_prompts.top + X].prefix
end_define

begin_define
define|#
directive|define
name|SUFFIX
parameter_list|(
name|X
parameter_list|)
value|the_prompts.prompt_stack[the_prompts.top + X].suffix
end_define

begin_comment
comment|/* Exported functions from event-top.c.     FIXME: these should really go into top.h.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|display_gdb_prompt
parameter_list|(
name|char
modifier|*
name|new_prompt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gdb_setup_readline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gdb_disable_readline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|async_init_signals
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_async_editing_command
parameter_list|(
name|char
modifier|*
name|args
parameter_list|,
name|int
name|from_tty
parameter_list|,
name|struct
name|cmd_list_element
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_async_annotation_level
parameter_list|(
name|char
modifier|*
name|args
parameter_list|,
name|int
name|from_tty
parameter_list|,
name|struct
name|cmd_list_element
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_async_prompt
parameter_list|(
name|char
modifier|*
name|args
parameter_list|,
name|int
name|from_tty
parameter_list|,
name|struct
name|cmd_list_element
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Signal to catch ^Z typed while reading a command: SIGTSTP or SIGCONT.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STOP_SIGNAL
end_ifndef

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SIGTSTP
end_ifdef

begin_define
define|#
directive|define
name|STOP_SIGNAL
value|SIGTSTP
end_define

begin_function_decl
specifier|extern
name|void
name|handle_stop_sig
parameter_list|(
name|int
name|sig
parameter_list|)
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

begin_function_decl
specifier|extern
name|void
name|handle_sigint
parameter_list|(
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_prompt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_prompt
parameter_list|(
name|char
modifier|*
name|prefix
parameter_list|,
name|char
modifier|*
name|prompt
parameter_list|,
name|char
modifier|*
name|suffix
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gdb_readline2
parameter_list|(
name|void
modifier|*
name|client_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mark_async_signal_handler_wrapper
parameter_list|(
name|void
modifier|*
name|token
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|async_request_quit
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stdin_event_handler
parameter_list|(
name|int
name|error
parameter_list|,
name|void
modifier|*
name|client_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|async_disable_stdin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|async_enable_stdin
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Exported variables from event-top.c.    FIXME: these should really go into top.h.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|async_command_editing_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|exec_done_display_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|async_annotation_suffix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|new_async_prompt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|prompts
name|the_prompts
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|call_readline
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|input_handler
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|input_fd
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|after_char_processing_hook
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cli_command_loop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

