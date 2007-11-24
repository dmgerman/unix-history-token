begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GDB variable objects API.    Copyright 1999, 2000 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VAROBJ_H
end_ifndef

begin_define
define|#
directive|define
name|VAROBJ_H
value|1
end_define

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_include
include|#
directive|include
file|"gdbtypes.h"
end_include

begin_comment
comment|/* Enumeration for the format types */
end_comment

begin_enum
enum|enum
name|varobj_display_formats
block|{
name|FORMAT_NATURAL
block|,
comment|/* What gdb actually calls 'natural' */
name|FORMAT_BINARY
block|,
comment|/* Binary display                    */
name|FORMAT_DECIMAL
block|,
comment|/* Decimal display                   */
name|FORMAT_HEXADECIMAL
block|,
comment|/* Hex display                       */
name|FORMAT_OCTAL
comment|/* Octal display                     */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|varobj_type
block|{
name|USE_SPECIFIED_FRAME
block|,
comment|/* Use the frame passed to varobj_create */
name|USE_CURRENT_FRAME
block|,
comment|/* Use the current frame */
name|USE_SELECTED_FRAME
comment|/* Always reevaluate in selected frame */
block|}
enum|;
end_enum

begin_comment
comment|/* String representations of gdb's format codes (defined in varobj.c) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|varobj_format_string
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Languages supported by this variable objects system. */
end_comment

begin_enum
enum|enum
name|varobj_languages
block|{
name|vlang_unknown
init|=
literal|0
block|,
name|vlang_c
block|,
name|vlang_cplus
block|,
name|vlang_java
block|,
name|vlang_end
block|}
enum|;
end_enum

begin_comment
comment|/* String representations of gdb's known languages (defined in varobj.c) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|varobj_language_string
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Struct thar describes a variable object instance */
end_comment

begin_struct_decl
struct_decl|struct
name|varobj
struct_decl|;
end_struct_decl

begin_comment
comment|/* API functions */
end_comment

begin_function_decl
specifier|extern
name|struct
name|varobj
modifier|*
name|varobj_create
parameter_list|(
name|char
modifier|*
name|objname
parameter_list|,
name|char
modifier|*
name|expression
parameter_list|,
name|CORE_ADDR
name|frame
parameter_list|,
name|enum
name|varobj_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|varobj_gen_name
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|varobj
modifier|*
name|varobj_get_handle
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|varobj_get_objname
parameter_list|(
name|struct
name|varobj
modifier|*
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|varobj_get_expression
parameter_list|(
name|struct
name|varobj
modifier|*
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|varobj_delete
parameter_list|(
name|struct
name|varobj
modifier|*
name|var
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|dellist
parameter_list|,
name|int
name|only_children
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|varobj_display_formats
name|varobj_set_display_format
parameter_list|(
name|struct
name|varobj
modifier|*
name|var
parameter_list|,
name|enum
name|varobj_display_formats
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|varobj_display_formats
name|varobj_get_display_format
parameter_list|(
name|struct
name|varobj
modifier|*
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|varobj_get_num_children
parameter_list|(
name|struct
name|varobj
modifier|*
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|varobj_list_children
parameter_list|(
name|struct
name|varobj
modifier|*
name|var
parameter_list|,
name|struct
name|varobj
modifier|*
modifier|*
modifier|*
name|childlist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|varobj_get_type
parameter_list|(
name|struct
name|varobj
modifier|*
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|varobj_languages
name|varobj_get_language
parameter_list|(
name|struct
name|varobj
modifier|*
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|varobj_get_attributes
parameter_list|(
name|struct
name|varobj
modifier|*
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|varobj_get_value
parameter_list|(
name|struct
name|varobj
modifier|*
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|varobj_set_value
parameter_list|(
name|struct
name|varobj
modifier|*
name|var
parameter_list|,
name|char
modifier|*
name|expression
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|varobj_list
parameter_list|(
name|struct
name|varobj
modifier|*
modifier|*
modifier|*
name|rootlist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|varobj_update
parameter_list|(
name|struct
name|varobj
modifier|*
modifier|*
name|varp
parameter_list|,
name|struct
name|varobj
modifier|*
modifier|*
modifier|*
name|changelist
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VAROBJ_H */
end_comment

end_unit

