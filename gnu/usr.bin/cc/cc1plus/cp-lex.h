begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define constants and variables for communication with cp-parse.y.    Copyright (C) 1987, 1992, 1993 Free Software Foundation, Inc.    Hacked by Michael Tiemann (tiemann@cygnus.com)    and by Brendan Kehoe (brendan@cygnus.com).  This file is part of GNU CC.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU CC General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU CC, but only under the conditions described in the GNU CC General Public License.   A copy of this license is supposed to have been given to you along with GNU CC so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
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
name|RID_WCHAR
block|,
name|RID_FLOAT
block|,
name|RID_DOUBLE
block|,
name|RID_VOID
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
comment|/* This is where grokdeclarator starts its search when setting the specbits.      The first seven are in the order of most frequently used, as found      building libg++.  */
name|RID_EXTERN
block|,
name|RID_CONST
block|,
name|RID_LONG
block|,
name|RID_TYPEDEF
block|,
name|RID_UNSIGNED
block|,
name|RID_SHORT
block|,
name|RID_INLINE
block|,
name|RID_STATIC
block|,
name|RID_REGISTER
block|,
name|RID_VOLATILE
block|,
name|RID_FRIEND
block|,
name|RID_VIRTUAL
block|,
name|RID_PUBLIC
block|,
name|RID_PRIVATE
block|,
name|RID_PROTECTED
block|,
name|RID_SIGNED
block|,
name|RID_EXCEPTION
block|,
name|RID_RAISES
block|,
name|RID_AUTO
block|,
comment|/* Note this is 31, and is unusable in shifts where ints are 32 bits.      As soon as a new rid has to be added to this enum, you have to      stop and come up with a better way to do all of this than by      doing `specbits& (1<< (int) RID_FOO)', since you'll end up      with an integer overflow.  */
name|RID_UNUSED1
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
value|RID_EXTERN
end_define

begin_comment
comment|/* The integral type that can represent all values of RIDBIT.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|RID_BIT_TYPE
typedef|;
end_typedef

begin_comment
comment|/* A bit that represents the given RID_... value.  */
end_comment

begin_define
define|#
directive|define
name|RIDBIT
parameter_list|(
name|N
parameter_list|)
value|((RID_BIT_TYPE) 1<< (int) (N))
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

