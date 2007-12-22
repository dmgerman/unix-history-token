begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* MI Command Set - MI Command Parser.    Copyright 2000 Free Software Foundation, Inc.    Contributed by Cygnus Solutions (a Red Hat company).     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MI_PARSE_H
end_ifndef

begin_define
define|#
directive|define
name|MI_PARSE_H
end_define

begin_comment
comment|/* MI parser */
end_comment

begin_enum
enum|enum
name|mi_command_type
block|{
name|MI_COMMAND
block|,
name|CLI_COMMAND
block|}
enum|;
end_enum

begin_struct
struct|struct
name|mi_parse
block|{
name|enum
name|mi_command_type
name|op
decl_stmt|;
name|char
modifier|*
name|command
decl_stmt|;
name|char
modifier|*
name|token
decl_stmt|;
specifier|const
name|struct
name|mi_cmd
modifier|*
name|cmd
decl_stmt|;
name|char
modifier|*
name|args
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
name|int
name|argc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Attempts to parse CMD returning a ``struct mi_command''.  If CMD is    invalid, an error mesage is reported (MI format) and NULL is    returned. For a CLI_COMMAND, COMMAND, TOKEN and OP are initialized.    For an MI_COMMAND COMMAND, TOKEN, ARGS and OP are    initialized. Un-initialized fields are zero. */
end_comment

begin_function_decl
specifier|extern
name|struct
name|mi_parse
modifier|*
name|mi_parse
parameter_list|(
name|char
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free a command returned by mi_parse_command. */
end_comment

begin_function_decl
specifier|extern
name|void
name|mi_parse_free
parameter_list|(
name|struct
name|mi_parse
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

