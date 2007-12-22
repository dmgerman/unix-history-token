begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* C language support definitions for GDB, the GNU debugger.    Copyright 1992, 1994, 1995, 1996, 1997, 1998, 2000, 2002    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|C_LANG_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|C_LANG_H
value|1
end_define

begin_struct_decl
struct_decl|struct
name|ui_file
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|"value.h"
end_include

begin_include
include|#
directive|include
file|"macroexp.h"
end_include

begin_function_decl
specifier|extern
name|int
name|c_parse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in c-exp.y */
end_comment

begin_function_decl
specifier|extern
name|void
name|c_error
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in c-exp.y */
end_comment

begin_comment
comment|/* Defined in c-typeprint.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|c_print_type
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
name|c_val_print
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
name|c_value_print
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

begin_comment
comment|/* These are in c-lang.c: */
end_comment

begin_function_decl
specifier|extern
name|void
name|c_printchar
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
name|c_printstr
parameter_list|(
name|struct
name|ui_file
modifier|*
name|stream
parameter_list|,
name|char
modifier|*
name|string
parameter_list|,
name|unsigned
name|int
name|length
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|force_ellipses
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scan_macro_expansion
parameter_list|(
name|char
modifier|*
name|expansion
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scanning_macro_expansion
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finished_macro_expansion
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|macro_lookup_ftype
modifier|*
name|expression_macro_lookup_func
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|expression_macro_lookup_baton
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|c_create_fundamental_type
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
name|c_builtin_types
function_decl|[]
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* These are in c-typeprint.c: */
end_comment

begin_function_decl
specifier|extern
name|void
name|c_type_print_base
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
name|cp_print_class_member
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
name|cp_print_class_method
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
name|cp_print_value_fields
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|,
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
name|cp_is_vtbl_ptr_type
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
name|cp_is_vtbl_member
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (C_LANG_H) */
end_comment

end_unit

