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
name|LINESPEC_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|LINESPEC_H
value|1
end_define

begin_struct_decl
struct_decl|struct
name|symtab
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|struct
name|symtabs_and_lines
name|decode_line_1
parameter_list|(
name|char
modifier|*
modifier|*
name|argptr
parameter_list|,
name|int
name|funfirstline
parameter_list|,
name|struct
name|symtab
modifier|*
name|default_symtab
parameter_list|,
name|int
name|default_line
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|canonical
parameter_list|,
name|int
modifier|*
name|not_found_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (LINESPEC_H) */
end_comment

end_unit

