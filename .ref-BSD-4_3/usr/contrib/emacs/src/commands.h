begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions needed by most editing commands.    Copyright (C) 1985 Richard M. Stallman.  This file is part of GNU Emacs.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Emacs General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU Emacs, but only under the conditions described in the GNU Emacs General Public License.   A copy of this license is supposed to have been given to you along with GNU Emacs so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
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
name|struct
name|Lisp_Vector
modifier|*
name|GlobalMap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default global key bindings */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|Lisp_Vector
modifier|*
name|ESCmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The keymap used for globally bound 				   ESC-prefixed default commands */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|Lisp_Vector
modifier|*
name|CtlXmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The keymap used for globally bound 				   C-x-prefixed default commands */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vminibuffer_local_map
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The keymap used by the minibuf for 				   local bindings when spaces are allowed 				   in the minibuf */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vminibuffer_local_ns_map
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The keymap used by the minibuf for 				   local bindings when spaces are not 				   encouraged in the minibuf */
end_comment

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

begin_decl_stmt
specifier|extern
name|int
name|last_command_char
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The last key struck as a command */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|unread_command_char
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Command character to be re-read, or -1 */
end_comment

begin_comment
comment|/* Previous command symbol found here for comparison */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|last_command
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|immediate_quit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means ^G can quit instantly */
end_comment

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
name|INTERACTIVE
value|(NULL (Vexecuting_macro)&& !noninteractive)
end_define

begin_comment
comment|/* Set this nonzero to force reconsideration of mode line. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|RedoModes
decl_stmt|;
end_decl_stmt

end_unit

