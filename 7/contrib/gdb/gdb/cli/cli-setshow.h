begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Header file for GDB CLI set and show commands implementation.    Copyright 2000, 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CLI_SETSHOW_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|CLI_SETSHOW_H
value|1
end_define

begin_struct_decl
struct_decl|struct
name|cmd_list_element
struct_decl|;
end_struct_decl

begin_comment
comment|/* Exported to cli/cli-cmds.c and gdb/top.c */
end_comment

begin_comment
comment|/* Do a "set" or "show" command.  ARG is NULL if no argument, or the text    of the argument, and FROM_TTY is nonzero if this command is being entered    directly by the user (i.e. these are just like any other    command).  C is the command list element for the command.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|do_setshow_command
parameter_list|(
name|char
modifier|*
name|arg
parameter_list|,
name|int
name|from_tty
parameter_list|,
name|struct
name|cmd_list_element
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Exported to cli/cli-cmds.c and gdb/top.c, language.c and valprint.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|cmd_show_list
parameter_list|(
name|struct
name|cmd_list_element
modifier|*
name|list
parameter_list|,
name|int
name|from_tty
parameter_list|,
name|char
modifier|*
name|prefix
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (CLI_SETSHOW_H) */
end_comment

end_unit

