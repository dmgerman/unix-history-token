begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* TUI display registers in window.     Copyright 1998, 1999, 2000, 2001, 2004 Free Software Foundation,    Inc.     Contributed by Hewlett-Packard Company.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TUI_REGS_H
end_ifndef

begin_define
define|#
directive|define
name|TUI_REGS_H
end_define

begin_include
include|#
directive|include
file|"tui/tui-data.h"
end_include

begin_comment
comment|/* For struct tui_register_display_type.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|tui_check_register_values
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
name|tui_show_registers
parameter_list|(
name|struct
name|reggroup
modifier|*
name|group
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_display_registers_from
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tui_display_registers_from_line
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tui_last_regs_line_no
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tui_first_reg_element_inline
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tui_line_from_reg_element_no
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tui_first_reg_element_no_inline
parameter_list|(
name|int
name|lineno
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

