begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define constants and variables for communication with parse.y.    Copyright (C) 1987, 92-97, 1998 Free Software Foundation, Inc.    Hacked by Michael Tiemann (tiemann@cygnus.com)    and by Brendan Kehoe (brendan@cygnus.com).  This file is part of GNU CC.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU CC General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU CC, but only under the conditions described in the GNU CC General Public License.   A copy of this license is supposed to have been given to you along with GNU CC so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_enum
enum|enum
name|rid
block|{
name|RID_UNUSED
block|,
name|RID_INT
block|,
name|RID_BOOL
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
name|RID_EXPLICIT
block|,
name|RID_EXPORT
block|,
name|RID_SIGNED
block|,
name|RID_AUTO
block|,
name|RID_MUTABLE
block|,
name|RID_COMPLEX
block|,
name|RID_RESTRICT
block|,
comment|/* This is where grokdeclarator ends its search when setting the      specbits.  */
name|RID_PUBLIC
block|,
name|RID_PRIVATE
block|,
name|RID_PROTECTED
block|,
name|RID_EXCEPTION
block|,
name|RID_TEMPLATE
block|,
name|RID_SIGNATURE
block|,
name|RID_NULL
block|,
comment|/* Before adding enough to get up to 64, the RIDBIT_* macros      will have to be changed a little.  */
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

begin_define
define|#
directive|define
name|RID_LAST_MODIFIER
value|RID_COMPLEX
end_define

begin_comment
comment|/* The type that can represent all values of RIDBIT.  */
end_comment

begin_comment
comment|/* We assume that we can stick in at least 32 bits into this.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|idata
index|[
literal|2
index|]
decl_stmt|;
block|}
name|RID_BIT_TYPE
typedef|;
end_typedef

begin_comment
comment|/* Be careful, all these modify N twice.  */
end_comment

begin_define
define|#
directive|define
name|RIDBIT_SETP
parameter_list|(
name|N
parameter_list|,
name|V
parameter_list|)
value|(((unsigned long)1<< (int) ((N)%32))		      \& (V).idata[(N)/32])
end_define

begin_define
define|#
directive|define
name|RIDBIT_NOTSETP
parameter_list|(
name|NN
parameter_list|,
name|VV
parameter_list|)
value|(! RIDBIT_SETP (NN, VV))
end_define

begin_define
define|#
directive|define
name|RIDBIT_SET
parameter_list|(
name|N
parameter_list|,
name|V
parameter_list|)
value|do {						      \ 				(V).idata[(N)/32]			      \ 				  |= ((unsigned long)1<< (int) ((N)%32));    \ 			      } while (0)
end_define

begin_define
define|#
directive|define
name|RIDBIT_RESET
parameter_list|(
name|N
parameter_list|,
name|V
parameter_list|)
value|do {						      \ 				  (V).idata[(N)/32]			      \&= ~((unsigned long)1<< (int) ((N)%32)); \ 				} while (0)
end_define

begin_define
define|#
directive|define
name|RIDBIT_RESET_ALL
parameter_list|(
name|V
parameter_list|)
value|do {					      \ 				   (V).idata[0] = 0;     		      \ 				   (V).idata[1] = 0;			      \ 				 } while (0)
end_define

begin_define
define|#
directive|define
name|RIDBIT_ANY_SET
parameter_list|(
name|V
parameter_list|)
value|((V).idata[0] || (V).idata[1])
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
name|int
name|looking_for_template
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tell the lexer where to look for names.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|got_scope
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|got_object
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pending language change.    Positive is push count, negative is pop count.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pending_lang_change
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yylex
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

