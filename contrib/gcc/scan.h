begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* scan.h - Utility declarations for scan-decls and fix-header programs.    Copyright (C) 1993, 1998, 1999, 2003 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|sstring
block|{
name|char
modifier|*
name|base
decl_stmt|;
name|char
modifier|*
name|ptr
decl_stmt|;
name|char
modifier|*
name|limit
decl_stmt|;
block|}
name|sstring
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INIT_SSTRING
parameter_list|(
name|STR
parameter_list|)
value|((STR)->base = 0, (STR)->ptr = 0, (STR)->limit = 0)
end_define

begin_define
define|#
directive|define
name|FREE_SSTRING
parameter_list|(
name|STR
parameter_list|)
value|do { if ((STR)->base) free (STR)->base; } while(0)
end_define

begin_define
define|#
directive|define
name|SSTRING_PUT
parameter_list|(
name|STR
parameter_list|,
name|C
parameter_list|)
value|do {\   if ((STR)->limit<= (STR)->ptr) make_sstring_space (STR, 1); \   *(STR)->ptr++ = (C); } while (0)
end_define

begin_define
define|#
directive|define
name|SSTRING_LENGTH
parameter_list|(
name|STR
parameter_list|)
value|((STR)->ptr - (STR)->base)
end_define

begin_define
define|#
directive|define
name|MAKE_SSTRING_SPACE
parameter_list|(
name|STR
parameter_list|,
name|COUNT
parameter_list|)
define|\
value|if ((STR)->limit - (STR)->ptr< (COUNT)) make_sstring_space (STR, COUNT);
end_define

begin_struct_decl
struct_decl|struct
name|partial_proto
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|fn_decl
block|{
specifier|const
name|char
modifier|*
name|fname
decl_stmt|;
specifier|const
name|char
modifier|*
name|rtype
decl_stmt|;
specifier|const
name|char
modifier|*
name|params
decl_stmt|;
name|struct
name|partial_proto
modifier|*
name|partial
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|cpp_token
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|sstring_append
parameter_list|(
name|sstring
modifier|*
parameter_list|,
name|sstring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|make_sstring_space
parameter_list|(
name|sstring
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|skip_spaces
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scan_ident
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|sstring
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scan_string
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|sstring
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|read_upto
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|sstring
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|hash
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|recognized_function
parameter_list|(
specifier|const
name|struct
name|cpp_token
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
name|void
name|recognized_extern
parameter_list|(
specifier|const
name|struct
name|cpp_token
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|hashstr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scan_decls
parameter_list|(
name|struct
name|cpp_reader
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get_token is a simple C lexer.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_TOKEN
value|300
end_define

begin_define
define|#
directive|define
name|CHAR_TOKEN
value|301
end_define

begin_define
define|#
directive|define
name|STRING_TOKEN
value|302
end_define

begin_define
define|#
directive|define
name|INT_TOKEN
value|303
end_define

begin_function_decl
specifier|extern
name|int
name|get_token
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|sstring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Current file and line numer, taking #-directives into account */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|source_lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|sstring
name|source_filename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current physical line number */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

end_unit

