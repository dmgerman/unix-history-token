begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Header file for GDB CLI command implementation library.    Copyright 2000, 2002 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CLI_SCRIPT_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|CLI_SCRIPT_H
value|1
end_define

begin_struct_decl
struct_decl|struct
name|ui_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|command_line
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|cmd_list_element
struct_decl|;
end_struct_decl

begin_comment
comment|/* Exported to cli/cli-cmds.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|script_from_file
parameter_list|(
name|FILE
modifier|*
name|stream
parameter_list|,
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|document_command
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|define_command
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|while_command
parameter_list|(
name|char
modifier|*
name|arg
parameter_list|,
name|int
name|from_tty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|if_command
parameter_list|(
name|char
modifier|*
name|arg
parameter_list|,
name|int
name|from_tty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|show_user_1
parameter_list|(
name|struct
name|cmd_list_element
modifier|*
name|c
parameter_list|,
name|struct
name|ui_file
modifier|*
name|stream
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Exported to gdb/breakpoint.c */
end_comment

begin_function_decl
specifier|extern
name|enum
name|command_control_type
name|execute_control_command
parameter_list|(
name|struct
name|command_line
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_command_lines
parameter_list|(
name|struct
name|ui_out
modifier|*
parameter_list|,
name|struct
name|command_line
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|command_line
modifier|*
name|copy_command_lines
parameter_list|(
name|struct
name|command_line
modifier|*
name|cmds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cleanup
modifier|*
name|make_cleanup_free_command_lines
parameter_list|(
name|struct
name|command_line
modifier|*
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Exported to gdb/infrun.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|execute_user_command
parameter_list|(
name|struct
name|cmd_list_element
modifier|*
name|c
parameter_list|,
name|char
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (CLI_SCRIPT_H) */
end_comment

end_unit

