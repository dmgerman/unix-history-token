begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define constants and variables for communication with cp-parse.y.    Copyright (C) 1987, 1992 Free Software Foundation, Inc.    Hacked by Michael Tiemann (tiemann@mcc.com)  This file is part of GNU CC.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU CC General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU CC, but only under the conditions described in the GNU CC General Public License.   A copy of this license is supposed to have been given to you along with GNU CC so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
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
comment|/* C++ extension */
name|RID_CLASS
block|,
name|RID_RECORD
block|,
name|RID_UNION
block|,
name|RID_ENUM
block|,
name|RID_LONGLONG
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
name|RID_WCHAR
block|,
comment|/* extensions */
name|RID_FRIEND
block|,
name|RID_VIRTUAL
block|,
name|RID_EXCEPTION
block|,
name|RID_RAISES
block|,
name|RID_PUBLIC
block|,
name|RID_PRIVATE
block|,
name|RID_PROTECTED
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

begin_comment
comment|/* Back-door communication channel to the lexer.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|looking_for_typename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|make_pointer_declarator
argument_list|()
decl_stmt|,
name|make_reference_declarator
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|reinit_parse_for_function
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reinit_parse_for_method
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

end_unit

