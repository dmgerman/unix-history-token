begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions needed by most editing commands.    Copyright (C) 1985 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|Ctl
parameter_list|(
name|c
parameter_list|)
value|((c)&037)
end_define

begin_comment
comment|/* Define the names of keymaps, just so people can refer to them in calls to defkey */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vglobal_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vesc_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vctl_x_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vminibuffer_local_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vminibuffer_local_ns_map
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keymap used for minibuffers when doing completion */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vminibuffer_local_completion_map
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keymap used for minibuffers when doing completion and require a match */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vminibuffer_local_must_match_map
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last character of last key sequence.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|last_command_char
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Command character to be re-read, or -1 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|unread_command_char
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Previous command symbol found here for comparison */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|last_command
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means ^G can quit instantly */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|immediate_quit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vexecuting_macro
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if input is coming from the keyboard */
end_comment

begin_define
define|#
directive|define
name|FROM_KBD
value|(NULL (Vexecuting_macro)&& !noninteractive)
end_define

begin_comment
comment|/* Set this nonzero to force reconsideration of mode line. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|update_mode_lines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means reading single-character input with prompt    so put cursor on minibuffer after the prompt.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cursor_in_echo_area
decl_stmt|;
end_decl_stmt

end_unit

