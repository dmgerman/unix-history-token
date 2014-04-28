begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Internal demangler interface for g++ V3 ABI.    Copyright (C) 2003, 2004 Free Software Foundation, Inc.    Written by Ian Lance Taylor<ian@wasabisystems.com>.     This file is part of the libiberty library, which is part of GCC.     This file is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     In addition to the permissions in the GNU General Public License, the    Free Software Foundation gives you unlimited permission to link the    compiled version of this file into combinations with other programs,    and to distribute those combinations without any restriction coming    from the use of this file.  (The General Public License restrictions    do apply in other respects; for example, they cover modification of    the file, and distribution when not linked into a combined    executable.)     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* This file provides some definitions shared by cp-demangle.c and    cp-demint.c.  It should not be included by any other files.  */
end_comment

begin_comment
comment|/* Information we keep for operators.  */
end_comment

begin_struct
struct|struct
name|demangle_operator_info
block|{
comment|/* Mangled name.  */
specifier|const
name|char
modifier|*
name|code
decl_stmt|;
comment|/* Real name.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Length of real name.  */
name|int
name|len
decl_stmt|;
comment|/* Number of arguments.  */
name|int
name|args
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* How to print the value of a builtin type.  */
end_comment

begin_enum
enum|enum
name|d_builtin_type_print
block|{
comment|/* Print as (type)val.  */
name|D_PRINT_DEFAULT
block|,
comment|/* Print as integer.  */
name|D_PRINT_INT
block|,
comment|/* Print as unsigned integer, with trailing "u".  */
name|D_PRINT_UNSIGNED
block|,
comment|/* Print as long, with trailing "l".  */
name|D_PRINT_LONG
block|,
comment|/* Print as unsigned long, with trailing "ul".  */
name|D_PRINT_UNSIGNED_LONG
block|,
comment|/* Print as long long, with trailing "ll".  */
name|D_PRINT_LONG_LONG
block|,
comment|/* Print as unsigned long long, with trailing "ull".  */
name|D_PRINT_UNSIGNED_LONG_LONG
block|,
comment|/* Print as bool.  */
name|D_PRINT_BOOL
block|,
comment|/* Print as float--put value in square brackets.  */
name|D_PRINT_FLOAT
block|,
comment|/* Print in usual way, but here to detect void.  */
name|D_PRINT_VOID
block|}
enum|;
end_enum

begin_comment
comment|/* Information we keep for a builtin type.  */
end_comment

begin_struct
struct|struct
name|demangle_builtin_type_info
block|{
comment|/* Type name.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Length of type name.  */
name|int
name|len
decl_stmt|;
comment|/* Type name when using Java.  */
specifier|const
name|char
modifier|*
name|java_name
decl_stmt|;
comment|/* Length of java name.  */
name|int
name|java_len
decl_stmt|;
comment|/* How to print a value of this type.  */
name|enum
name|d_builtin_type_print
name|print
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The information structure we pass around.  */
end_comment

begin_struct
struct|struct
name|d_info
block|{
comment|/* The string we are demangling.  */
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
comment|/* The end of the string we are demangling.  */
specifier|const
name|char
modifier|*
name|send
decl_stmt|;
comment|/* The options passed to the demangler.  */
name|int
name|options
decl_stmt|;
comment|/* The next character in the string to consider.  */
specifier|const
name|char
modifier|*
name|n
decl_stmt|;
comment|/* The array of components.  */
name|struct
name|demangle_component
modifier|*
name|comps
decl_stmt|;
comment|/* The index of the next available component.  */
name|int
name|next_comp
decl_stmt|;
comment|/* The number of available component structures.  */
name|int
name|num_comps
decl_stmt|;
comment|/* The array of substitutions.  */
name|struct
name|demangle_component
modifier|*
modifier|*
name|subs
decl_stmt|;
comment|/* The index of the next substitution.  */
name|int
name|next_sub
decl_stmt|;
comment|/* The number of available entries in the subs array.  */
name|int
name|num_subs
decl_stmt|;
comment|/* The number of substitutions which we actually made from the subs      array, plus the number of template parameter references we      saw.  */
name|int
name|did_subs
decl_stmt|;
comment|/* The last name we saw, for constructors and destructors.  */
name|struct
name|demangle_component
modifier|*
name|last_name
decl_stmt|;
comment|/* A running total of the length of large expansions from the      mangled name to the demangled name, such as standard      substitutions and builtin types.  */
name|int
name|expansion
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* To avoid running past the ending '\0', don't:    - call d_peek_next_char if d_peek_char returned '\0'    - call d_advance with an 'i' that is too large    - call d_check_char(di, '\0')    Everything else is safe.  */
end_comment

begin_define
define|#
directive|define
name|d_peek_char
parameter_list|(
name|di
parameter_list|)
value|(*((di)->n))
end_define

begin_define
define|#
directive|define
name|d_peek_next_char
parameter_list|(
name|di
parameter_list|)
value|((di)->n[1])
end_define

begin_define
define|#
directive|define
name|d_advance
parameter_list|(
name|di
parameter_list|,
name|i
parameter_list|)
value|((di)->n += (i))
end_define

begin_define
define|#
directive|define
name|d_check_char
parameter_list|(
name|di
parameter_list|,
name|c
parameter_list|)
value|(d_peek_char(di) == c ? ((di)->n++, 1) : 0)
end_define

begin_define
define|#
directive|define
name|d_next_char
parameter_list|(
name|di
parameter_list|)
value|(d_peek_char(di) == '\0' ? '\0' : *((di)->n++))
end_define

begin_define
define|#
directive|define
name|d_str
parameter_list|(
name|di
parameter_list|)
value|((di)->n)
end_define

begin_comment
comment|/* Functions and arrays in cp-demangle.c which are referenced by    functions in cp-demint.c.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IN_GLIBCPP_V3
end_ifdef

begin_define
define|#
directive|define
name|CP_STATIC_IF_GLIBCPP_V3
value|static
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CP_STATIC_IF_GLIBCPP_V3
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|CP_STATIC_IF_GLIBCPP_V3
specifier|const
expr|struct
name|demangle_operator_info
name|cplus_demangle_operators
index|[]
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|D_BUILTIN_TYPE_COUNT
value|(26)
end_define

begin_expr_stmt
name|CP_STATIC_IF_GLIBCPP_V3
specifier|const
expr|struct
name|demangle_builtin_type_info
name|cplus_demangle_builtin_types
index|[
name|D_BUILTIN_TYPE_COUNT
index|]
expr_stmt|;
end_expr_stmt

begin_function_decl
name|CP_STATIC_IF_GLIBCPP_V3
name|struct
name|demangle_component
modifier|*
name|cplus_demangle_mangled_name
parameter_list|(
name|struct
name|d_info
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CP_STATIC_IF_GLIBCPP_V3
name|struct
name|demangle_component
modifier|*
name|cplus_demangle_type
parameter_list|(
name|struct
name|d_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cplus_demangle_init_info
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|d_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* cp-demangle.c needs to define this a little differently */
end_comment

begin_undef
undef|#
directive|undef
name|CP_STATIC_IF_GLIBCPP_V3
end_undef

end_unit

