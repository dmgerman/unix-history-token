begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define constants for communication with c-parse.y.    Copyright (C) 1987, 1992 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_enum
enum|enum
name|rid
block|{
name|RID_UNUSED
block|,
name|RID_INT
block|,
name|RID_CHAR
block|,
name|RID_FLOAT
block|,
name|RID_DOUBLE
block|,
name|RID_VOID
block|,
name|RID_UNUSED1
block|,
name|RID_UNSIGNED
block|,
name|RID_SHORT
block|,
name|RID_LONG
block|,
name|RID_AUTO
block|,
name|RID_STATIC
block|,
name|RID_EXTERN
block|,
name|RID_REGISTER
block|,
name|RID_TYPEDEF
block|,
name|RID_SIGNED
block|,
name|RID_CONST
block|,
name|RID_VOLATILE
block|,
name|RID_INLINE
block|,
name|RID_NOALIAS
block|,
name|RID_ITERATOR
block|,
name|RID_COMPLEX
block|,
name|RID_IN
block|,
name|RID_OUT
block|,
name|RID_INOUT
block|,
name|RID_BYCOPY
block|,
name|RID_ONEWAY
block|,
name|RID_ID
block|,
name|RID_MAX
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|NORID
value|RID_UNUSED
end_define

begin_define
define|#
directive|define
name|RID_FIRST_MODIFIER
value|RID_UNSIGNED
end_define

begin_comment
comment|/* The elements of `ridpointers' are identifier nodes    for the reserved type names and storage classes.    It is indexed by a RID_... value.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|ridpointers
index|[
operator|(
name|int
operator|)
name|RID_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the declaration found for the last IDENTIFIER token read in.    yylex must look this up to detect typedefs, which get token type TYPENAME,    so it is left around in case the identifier is not a typedef but is    used in a context which makes it a reference to a variable.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|lastiddecl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|token_buffer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to token buffer.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|make_pointer_declarator
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reinit_parse_for_function
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|yylex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|get_directive_line
parameter_list|()
function_decl|;
end_function_decl

end_unit

