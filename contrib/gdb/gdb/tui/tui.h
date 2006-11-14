begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* External/Public TUI Header File.     Copyright 1998, 1999, 2000, 2001, 2004 Free Software Foundation,    Inc.     Contributed by Hewlett-Packard Company.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TUI_H
end_ifndef

begin_define
define|#
directive|define
name|TUI_H
end_define

begin_struct_decl
struct_decl|struct
name|ui_file
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|strcat_to_buf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Types of error returns.  */
end_comment

begin_enum
enum|enum
name|tui_status
block|{
name|TUI_SUCCESS
block|,
name|TUI_FAILURE
block|}
enum|;
end_enum

begin_comment
comment|/* Types of windows */
end_comment

begin_enum
enum|enum
name|tui_win_type
block|{
name|SRC_WIN
init|=
literal|0
block|,
name|DISASSEM_WIN
block|,
name|DATA_WIN
block|,
name|CMD_WIN
block|,
comment|/* This must ALWAYS be AFTER the major windows last.  */
name|MAX_MAJOR_WINDOWS
block|,
comment|/* Auxillary windows.  */
name|LOCATOR_WIN
block|,
name|EXEC_INFO_WIN
block|,
name|DATA_ITEM_WIN
block|,
comment|/* This must ALWAYS be next to last.  */
name|MAX_WINDOWS
block|,
name|UNDEFINED_WIN
comment|/* LAST */
block|}
enum|;
end_enum

begin_comment
comment|/* GENERAL TUI FUNCTIONS */
end_comment

begin_comment
comment|/* tui.c */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|tui_get_low_disassembly_address
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tui_show_assembly
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tui_is_window_visible
parameter_list|(
name|enum
name|tui_win_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tui_get_command_dimension
parameter_list|(
name|int
modifier|*
name|width
parameter_list|,
name|int
modifier|*
name|height
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Initialize readline and configure the keymap for the switching    key shortcut.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|tui_initialize_readline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Enter in the tui mode (curses).  */
end_comment

begin_function_decl
specifier|extern
name|void
name|tui_enable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Leave the tui mode.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|tui_disable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|tui_key_mode
block|{
comment|/* Plain command mode to enter gdb commands.  */
name|TUI_COMMAND_MODE
block|,
comment|/* SingleKey mode with some keys bound to gdb commands.  */
name|TUI_SINGLE_KEY_MODE
block|,
comment|/* Read/edit one command and return to SingleKey after it's processed.  */
name|TUI_ONE_COMMAND_MODE
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|tui_key_mode
name|tui_current_key_mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Change the TUI key mode by installing the appropriate readline keymap.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|tui_set_key_mode
parameter_list|(
name|enum
name|tui_key_mode
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|tui_active
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|tui_show_source
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ui_out
modifier|*
name|tui_out_new
parameter_list|(
name|struct
name|ui_file
modifier|*
name|stream
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* tui-layout.c */
end_comment

begin_function_decl
specifier|extern
name|enum
name|tui_status
name|tui_set_layout_for_display_command
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

