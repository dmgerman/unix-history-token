begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* TUI display source/assembly window.     Copyright 1998, 1999, 2000, 2001, 2002, 2004 Free Software    Foundation, Inc.     Contributed by Hewlett-Packard Company.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TUI_SOURCEWIN_H
end_ifndef

begin_define
define|#
directive|define
name|TUI_SOURCEWIN_H
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

begin_comment
comment|/* Update the execution windows to show the active breakpoints.  This    is called whenever a breakpoint is inserted, removed or has its    state changed.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|tui_update_all_breakpoint_info
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Scan the source window and the breakpoints to update the hasBreak    information for each line.  Returns 1 if something changed and the    execution window must be refreshed.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|tui_update_breakpoint_info
parameter_list|(
name|struct
name|tui_win_info
modifier|*
name|win
parameter_list|,
name|int
name|current_only
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Function to display the "main" routine.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|tui_display_main
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_update_source_window
parameter_list|(
name|struct
name|tui_win_info
modifier|*
parameter_list|,
name|struct
name|symtab
modifier|*
parameter_list|,
name|union
name|tui_line_or_address
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_update_source_window_as_is
parameter_list|(
name|struct
name|tui_win_info
modifier|*
parameter_list|,
name|struct
name|symtab
modifier|*
parameter_list|,
name|union
name|tui_line_or_address
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_update_source_windows_with_addr
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_update_source_windows_with_line
parameter_list|(
name|struct
name|symtab
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_clear_source_content
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
name|tui_erase_source_content
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
name|tui_show_source_content
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
name|tui_horizontal_source_scroll
parameter_list|(
name|struct
name|tui_win_info
modifier|*
parameter_list|,
name|enum
name|tui_scroll_direction
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|tui_status
name|tui_set_exec_info_content
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
name|tui_show_exec_info_content
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
name|tui_erase_exec_info_content
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
name|tui_clear_exec_info_content
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
name|tui_update_exec_info
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
name|tui_set_is_exec_point_at
parameter_list|(
name|union
name|tui_line_or_address
parameter_list|,
name|struct
name|tui_win_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|tui_status
name|tui_alloc_source_buffer
parameter_list|(
name|struct
name|tui_win_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tui_line_is_displayed
parameter_list|(
name|int
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
name|int
name|tui_addr_is_displayed
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|struct
name|tui_win_info
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Constant definitions. */
end_comment

begin_define
define|#
directive|define
name|SCROLL_THRESHOLD
value|2
end_define

begin_comment
comment|/* threshold for lazy scroll */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

