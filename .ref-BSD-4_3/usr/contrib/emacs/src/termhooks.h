begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Hooks by which low level terminal operations    can be made to call other routines.    Copyright (C) 1985 Richard M. Stallman.  This file is part of GNU Emacs.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Emacs General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU Emacs, but only under the conditions described in the GNU Emacs General Public License.   A copy of this license is supposed to have been given to you along with GNU Emacs so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|topos_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|raw_topos_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|clear_to_end_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|clear_screen_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|clear_end_of_line_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|ins_del_lines_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|change_line_highlight_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|reassert_line_highlight_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|insert_chars_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|write_chars_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|delete_chars_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|ring_bell_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|reset_terminal_modes_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|set_terminal_modes_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|update_begin_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|update_end_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|set_terminal_window_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|read_socket_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|fix_screen_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* If nonzero, send all terminal output characters to this stream also.  */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|termscript
decl_stmt|;
end_decl_stmt

end_unit

