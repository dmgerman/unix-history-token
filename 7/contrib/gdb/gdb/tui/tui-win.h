begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* TUI window generic functions.     Copyright 1998, 1999, 2000, 2001, 2002, 2004 Free Software    Foundation, Inc.     Contributed by Hewlett-Packard Company.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TUI_WIN_H
end_ifndef

begin_define
define|#
directive|define
name|TUI_WIN_H
end_define

begin_include
include|#
directive|include
file|"tui/tui-data.h"
end_include

begin_struct_decl
struct_decl|struct
name|tui_win_info
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|tui_scroll_forward
parameter_list|(
name|struct
name|tui_win_info
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_scroll_backward
parameter_list|(
name|struct
name|tui_win_info
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_scroll_left
parameter_list|(
name|struct
name|tui_win_info
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_scroll_right
parameter_list|(
name|struct
name|tui_win_info
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_scroll
parameter_list|(
name|enum
name|tui_scroll_direction
parameter_list|,
name|struct
name|tui_win_info
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_set_win_focus_to
parameter_list|(
name|struct
name|tui_win_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_resize_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_refresh_all_win
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_sigwinch_handler
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|chtype
name|tui_border_ulcorner
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|chtype
name|tui_border_urcorner
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|chtype
name|tui_border_lrcorner
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|chtype
name|tui_border_llcorner
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|chtype
name|tui_border_vline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|chtype
name|tui_border_hline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tui_border_attrs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tui_active_border_attrs
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|tui_update_variables
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Update gdb's knowledge of the terminal size.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|tui_update_gdb_sizes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create or get the TUI command list.  */
end_comment

begin_function_decl
name|struct
name|cmd_list_element
modifier|*
modifier|*
name|tui_get_cmd_list
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

