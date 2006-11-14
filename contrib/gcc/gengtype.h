begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Process source files and output type information.    Copyright (C) 2002, 2003 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* A file position, mostly for error messages.      The FILE element may be compared using pointer equality.  */
end_comment

begin_struct
struct|struct
name|fileloc
block|{
specifier|const
name|char
modifier|*
name|file
decl_stmt|;
name|int
name|line
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Kinds of types we can understand.  */
end_comment

begin_enum
enum|enum
name|typekind
block|{
name|TYPE_SCALAR
block|,
name|TYPE_STRING
block|,
name|TYPE_STRUCT
block|,
name|TYPE_UNION
block|,
name|TYPE_POINTER
block|,
name|TYPE_ARRAY
block|,
name|TYPE_LANG_STRUCT
block|,
name|TYPE_PARAM_STRUCT
block|}
enum|;
end_enum

begin_comment
comment|/* A way to pass data through to the output end.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|options
block|{
name|struct
name|options
modifier|*
name|next
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|void
modifier|*
name|info
decl_stmt|;
block|}
typedef|*
name|options_p
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pair
modifier|*
name|pair_p
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|type
modifier|*
name|type_p
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|lang_bitmap
typedef|;
end_typedef

begin_comment
comment|/* A name and a type.  */
end_comment

begin_struct
struct|struct
name|pair
block|{
name|pair_p
name|next
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|type_p
name|type
decl_stmt|;
name|struct
name|fileloc
name|line
decl_stmt|;
name|options_p
name|opt
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NUM_PARAM
value|10
end_define

begin_comment
comment|/* A description of a type.  */
end_comment

begin_struct
struct|struct
name|type
block|{
name|enum
name|typekind
name|kind
decl_stmt|;
name|type_p
name|next
decl_stmt|;
name|type_p
name|pointer_to
decl_stmt|;
enum|enum
name|gc_used_enum
block|{
name|GC_UNUSED
init|=
literal|0
block|,
name|GC_USED
block|,
name|GC_MAYBE_POINTED_TO
block|,
name|GC_POINTED_TO
block|}
name|gc_used
enum|;
union|union
block|{
name|type_p
name|p
decl_stmt|;
struct|struct
block|{
specifier|const
name|char
modifier|*
name|tag
decl_stmt|;
name|struct
name|fileloc
name|line
decl_stmt|;
name|pair_p
name|fields
decl_stmt|;
name|options_p
name|opt
decl_stmt|;
name|lang_bitmap
name|bitmap
decl_stmt|;
name|type_p
name|lang_struct
decl_stmt|;
block|}
name|s
struct|;
name|char
modifier|*
name|sc
decl_stmt|;
struct|struct
block|{
name|type_p
name|p
decl_stmt|;
specifier|const
name|char
modifier|*
name|len
decl_stmt|;
block|}
name|a
struct|;
struct|struct
block|{
name|type_p
name|stru
decl_stmt|;
name|type_p
name|param
index|[
name|NUM_PARAM
index|]
decl_stmt|;
name|struct
name|fileloc
name|line
decl_stmt|;
block|}
name|param_struct
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNION_P
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)->kind == TYPE_UNION || 				\   ((x)->kind == TYPE_LANG_STRUCT 			\&& (x)->u.s.lang_struct->kind == TYPE_UNION))
end_define

begin_define
define|#
directive|define
name|UNION_OR_STRUCT_P
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)->kind == TYPE_UNION 			\   || (x)->kind == TYPE_STRUCT 			\   || (x)->kind == TYPE_LANG_STRUCT)
end_define

begin_comment
comment|/* The one and only TYPE_STRING.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|type
name|string_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variables used to communicate between the lexer and the parser.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lexer_toplevel_done
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fileloc
name|lexer_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print an error message.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|error_at_line
argument_list|(
expr|struct
name|fileloc
operator|*
name|pos
argument_list|,
specifier|const
name|char
operator|*
name|msg
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_PRINTF_2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Combines xmalloc() and vasprintf().  */
end_comment

begin_function_decl
specifier|extern
name|int
name|xvasprintf
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|ATTRIBUTE_PRINTF
parameter_list|(
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Like the above, but more convenient for quick coding.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xasprintf
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_PRINTF_1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Constructor routines for types.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|do_typedef
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|type_p
name|t
parameter_list|,
name|struct
name|fileloc
modifier|*
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|type_p
name|resolve_typedef
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|struct
name|fileloc
modifier|*
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|new_structure
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|isunion
parameter_list|,
name|struct
name|fileloc
modifier|*
name|pos
parameter_list|,
name|pair_p
name|fields
parameter_list|,
name|options_p
name|o
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|type_p
name|find_structure
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|isunion
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|type_p
name|create_scalar_type
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|size_t
name|name_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|type_p
name|create_pointer
parameter_list|(
name|type_p
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|type_p
name|create_array
parameter_list|(
name|type_p
name|t
parameter_list|,
specifier|const
name|char
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|type_p
name|adjust_field_type
parameter_list|(
name|type_p
parameter_list|,
name|options_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|note_variable
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|type_p
name|t
parameter_list|,
name|options_p
name|o
parameter_list|,
name|struct
name|fileloc
modifier|*
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|note_yacc_type
parameter_list|(
name|options_p
name|o
parameter_list|,
name|pair_p
name|fields
parameter_list|,
name|pair_p
name|typeinfo
parameter_list|,
name|struct
name|fileloc
modifier|*
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Lexer and parser routines, most automatically generated.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|yylex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|yyerror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|yyparse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|parse_file
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Output file handling.  */
end_comment

begin_comment
comment|/* Structure representing an output file.  */
end_comment

begin_struct
struct|struct
name|outf
block|{
name|struct
name|outf
modifier|*
name|next
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|size_t
name|buflength
decl_stmt|;
name|size_t
name|bufused
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|outf
modifier|*
name|outf_p
typedef|;
end_typedef

begin_comment
comment|/* The output header file that is included into pretty much every    source file.  */
end_comment

begin_decl_stmt
specifier|extern
name|outf_p
name|header_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* An output file, suitable for definitions, that can see declarations    made in INPUT_FILE and is linked into every language that uses    INPUT_FILE.  */
end_comment

begin_function_decl
specifier|extern
name|outf_p
name|get_output_file_with_visibility
parameter_list|(
specifier|const
name|char
modifier|*
name|input_file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|get_output_file_name
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* A list of output files suitable for definitions.  There is one    BASE_FILES entry for each language.  */
end_comment

begin_decl_stmt
specifier|extern
name|outf_p
name|base_files
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A bitmap that specifies which of BASE_FILES should be used to    output a definition that is different for each language and must be    defined once in each language that uses INPUT_FILE.  */
end_comment

begin_function_decl
specifier|extern
name|lang_bitmap
name|get_base_file_bitmap
parameter_list|(
specifier|const
name|char
modifier|*
name|input_file
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print, like fprintf, to O.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|oprintf
argument_list|(
name|outf_p
name|o
argument_list|,
specifier|const
name|char
operator|*
name|S
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_PRINTF_2
decl_stmt|;
end_decl_stmt

end_unit

