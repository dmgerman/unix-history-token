begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* TUI layout window management.     Copyright 1998, 1999, 2000, 2001, 2002, 2004 Free Software    Foundation, Inc.     Contributed by Hewlett-Packard Company.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TUI_LAYOUT_H
end_ifndef

begin_define
define|#
directive|define
name|TUI_LAYOUT_H
end_define

begin_include
include|#
directive|include
file|"tui/tui.h"
end_include

begin_include
include|#
directive|include
file|"tui/tui-data.h"
end_include

begin_function_decl
specifier|extern
name|void
name|tui_add_win_to_layout
parameter_list|(
name|enum
name|tui_win_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tui_default_win_height
parameter_list|(
name|enum
name|tui_win_type
parameter_list|,
name|enum
name|tui_layout_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tui_default_win_viewport_height
parameter_list|(
name|enum
name|tui_win_type
parameter_list|,
name|enum
name|tui_layout_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|tui_status
name|tui_set_layout
parameter_list|(
name|enum
name|tui_layout_type
parameter_list|,
name|enum
name|tui_register_display_type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*TUI_LAYOUT_H */
end_comment

end_unit

