begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* echo-area.h -- Functions used in reading information from the echo area.    $Id: echo-area.h,v 1.3 1997/07/15 18:38:21 karl Exp $     This file is part of GNU Info, a program for reading online documentation    stored in Info format.     Copyright (C) 1993, 97 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFO_ECHO_AREA_H
end_ifndef

begin_define
define|#
directive|define
name|INFO_ECHO_AREA_H
end_define

begin_define
define|#
directive|define
name|EA_MAX_INPUT
value|256
end_define

begin_decl_stmt
specifier|extern
name|int
name|echo_area_is_active
decl_stmt|,
name|info_aborted_echo_area
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means that the last command executed while reading input    killed some text. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|echo_area_last_command_was_kill
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|inform_in_echo_area
argument_list|()
decl_stmt|,
name|echo_area_inform_of_deleted_window
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|echo_area_prep_read
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|VFunction
modifier|*
name|ea_last_executed_command
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read a line of text in the echo area.  Return a malloc ()'ed string,    or NULL if the user aborted out of this read.  WINDOW is the currently    active window, so that we can restore it when we need to.  PROMPT, if    non-null, is a prompt to print before reading the line. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|info_read_in_echo_area
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Read a line in the echo area with completion over COMPLETIONS.    Takes arguments of WINDOW, PROMPT, and COMPLETIONS, a REFERENCE **. */
end_comment

begin_function_decl
name|char
modifier|*
name|info_read_completing_in_echo_area
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Read a line in the echo area allowing completion over COMPLETIONS, but    not requiring it.  Takes arguments of WINDOW, PROMPT, and COMPLETIONS,    a REFERENCE **. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|info_read_maybe_completing
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|ea_insert
argument_list|()
decl_stmt|,
name|ea_quoted_insert
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ea_beg_of_line
argument_list|()
decl_stmt|,
name|ea_backward
argument_list|()
decl_stmt|,
name|ea_delete
argument_list|()
decl_stmt|,
name|ea_end_of_line
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ea_forward
argument_list|()
decl_stmt|,
name|ea_abort
argument_list|()
decl_stmt|,
name|ea_rubout
argument_list|()
decl_stmt|,
name|ea_complete
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ea_newline
argument_list|()
decl_stmt|,
name|ea_kill_line
argument_list|()
decl_stmt|,
name|ea_transpose_chars
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ea_yank
argument_list|()
decl_stmt|,
name|ea_tab_insert
argument_list|()
decl_stmt|,
name|ea_possible_completions
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ea_backward_word
argument_list|()
decl_stmt|,
name|ea_kill_word
argument_list|()
decl_stmt|,
name|ea_forward_word
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ea_yank_pop
argument_list|()
decl_stmt|,
name|ea_backward_kill_word
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|ea_scroll_completions_window
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not INFO_ECHO_AREA_H */
end_comment

end_unit

