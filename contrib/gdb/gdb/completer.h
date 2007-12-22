begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Header for GDB line completion.    Copyright 2000 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|COMPLETER_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|COMPLETER_H
value|1
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|complete_line
parameter_list|(
specifier|const
name|char
modifier|*
name|text
parameter_list|,
name|char
modifier|*
name|line_buffer
parameter_list|,
name|int
name|point
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|readline_line_completion_function
parameter_list|(
specifier|const
name|char
modifier|*
name|text
parameter_list|,
name|int
name|matches
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|noop_completer
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|filename_completer
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|location_completer
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|command_completer
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|get_gdb_completer_quote_characters
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Exported to linespec.c */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|skip_quoted_chars
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|skip_quoted
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (COMPLETER_H) */
end_comment

end_unit

