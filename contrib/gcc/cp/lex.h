begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define constants and variables for communication with parse.y.    Copyright (C) 1987, 1992, 1993, 1994, 1995, 1996, 1997, 1998,    2000 Free Software Foundation, Inc.    Hacked by Michael Tiemann (tiemann@cygnus.com)    and by Brendan Kehoe (brendan@cygnus.com).  This file is part of GNU CC.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU CC General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU CC, but only under the conditions described in the GNU CC General Public License.   A copy of this license is supposed to have been given to you along with GNU CC so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_CP_LEX_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_CP_LEX_H
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Formerly, the RID_* values used as mask bits did not fit into a    single 32-bit word.  Now they do, but let's preserve the old logic    in case they ever stop fitting again.  -zw, 8 Aug 2000 */
end_comment

begin_comment
comment|/* The type that can represent all values of RIDBIT.  */
end_comment

begin_comment
comment|/* We assume that we can stick in at least 32 bits into this.  */
end_comment

begin_comment
unit|typedef struct { unsigned long idata[2]; }      RID_BIT_TYPE;
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

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|long
name|RID_BIT_TYPE
typedef|;
end_typedef

begin_comment
comment|/* assumed at least 32 bits */
end_comment

begin_define
define|#
directive|define
name|RIDBIT_OF
parameter_list|(
name|R
parameter_list|)
value|((unsigned long)1<< (int) (R))
end_define

begin_define
define|#
directive|define
name|RIDBIT_SETP
parameter_list|(
name|N
parameter_list|,
name|V
parameter_list|)
value|((V)& RIDBIT_OF (N))
end_define

begin_define
define|#
directive|define
name|RIDBIT_NOTSETP
parameter_list|(
name|N
parameter_list|,
name|V
parameter_list|)
value|(! ((V)& RIDBIT_OF (N)))
end_define

begin_define
define|#
directive|define
name|RIDBIT_ANY_SET
parameter_list|(
name|V
parameter_list|)
value|(V)
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
value|do { (V) |= RIDBIT_OF (N); } while (0)
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
value|do { (V)&= ~RIDBIT_OF (N); } while (0)
end_define

begin_define
define|#
directive|define
name|RIDBIT_RESET_ALL
parameter_list|(
name|V
parameter_list|)
value|do { (V) = 0; } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* the declaration found for the last IDENTIFIER token read in.    yylex must look this up to detect typedefs, which get token type TYPENAME,    so it is left around in case the identifier is not a typedef but is    used in a context which makes it a reference to a variable.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|lastiddecl
decl_stmt|;
end_decl_stmt

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
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_CP_LEX_H */
end_comment

end_unit

