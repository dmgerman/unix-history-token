begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Pascal language support definitions for GDB, the GNU debugger.    Copyright 2000 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file is derived from c-lang.h */
end_comment

begin_struct_decl
struct_decl|struct
name|value
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|pascal_parse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in p-exp.y */
end_comment

begin_function_decl
specifier|extern
name|void
name|pascal_error
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in p-exp.y */
end_comment

begin_comment
comment|/* Defined in p-typeprint.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|pascal_print_type
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pascal_val_print
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|CORE_ADDR
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|val_prettyprint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pascal_value_print
parameter_list|(
name|struct
name|value
modifier|*
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|,
name|int
parameter_list|,
name|enum
name|val_prettyprint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pascal_type_print_method_args
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* These are in p-lang.c: */
end_comment

begin_function_decl
specifier|extern
name|int
name|is_pascal_string_type
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pascal_printchar
parameter_list|(
name|int
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pascal_printstr
parameter_list|(
name|struct
name|ui_file
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|pascal_create_fundamental_type
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
modifier|*
function_decl|const (
name|pascal_builtin_types
function_decl|[]
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* These are in p-typeprint.c: */
end_comment

begin_function_decl
specifier|extern
name|void
name|pascal_type_print_base
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pascal_type_print_varspec_prefix
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* These are in cp-valprint.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vtblprint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Controls printing of vtbl's */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|static_field_print
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|pascal_object_print_class_member
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|type
modifier|*
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pascal_object_print_class_method
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|type
modifier|*
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pascal_object_print_value_fields
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|CORE_ADDR
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|val_prettyprint
parameter_list|,
name|struct
name|type
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pascal_object_is_vtbl_ptr_type
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pascal_object_is_vtbl_member
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

