begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Data/register window display.     Copyright 1998, 1999, 2000, 2001, 2004 Free Software Foundation,    Inc.     Contributed by Hewlett-Packard Company.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TUI_WINDATA_H
end_ifndef

begin_define
define|#
directive|define
name|TUI_WINDATA_H
end_define

begin_include
include|#
directive|include
file|"tui/tui-data.h"
end_include

begin_function_decl
specifier|extern
name|void
name|tui_erase_data_content
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_display_all_data
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_check_data_values
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_display_data_from_line
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tui_first_data_item_displayed
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tui_first_data_element_no_in_line
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_delete_data_content_windows
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_refresh_data_win
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_display_data_from
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_vertical_data_scroll
parameter_list|(
name|enum
name|tui_scroll_direction
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

