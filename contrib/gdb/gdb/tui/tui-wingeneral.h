begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* General window behavior.     Copyright 1998, 1999, 2000, 2001, 2002, 2004 Free Software    Foundation, Inc.     Contributed by Hewlett-Packard Company.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TUI_WINGENERAL_H
end_ifndef

begin_define
define|#
directive|define
name|TUI_WINGENERAL_H
end_define

begin_struct_decl
struct_decl|struct
name|tui_win_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tui_gen_win_info
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|tui_unhighlight_win
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
name|tui_make_visible
parameter_list|(
name|struct
name|tui_gen_win_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_make_invisible
parameter_list|(
name|struct
name|tui_gen_win_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_make_all_visible
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_make_all_invisible
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_make_window
parameter_list|(
name|struct
name|tui_gen_win_info
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tui_win_info
modifier|*
name|tui_copy_win
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
name|tui_box_win
parameter_list|(
name|struct
name|tui_gen_win_info
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_highlight_win
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
name|tui_check_and_display_highlight_if_needed
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
name|tui_refresh_all
parameter_list|(
name|struct
name|tui_win_info
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_delete_win
parameter_list|(
name|WINDOW
modifier|*
name|window
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_refresh_win
parameter_list|(
name|struct
name|tui_gen_win_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

