begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  *  *	from: @(#)rpc_scan.h 1.3 87/03/09 (C) 1987 SMI  *	from: @(#)rpc_scan.h	2.1 88/08/01 4.0 RPCSRC  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * rpc_scan.h, Definitions for the RPCL scanner  * Copyright (C) 1987, Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * kinds of tokens  */
end_comment

begin_enum
enum|enum
name|tok_kind
block|{
name|TOK_IDENT
block|,
name|TOK_STRCONST
block|,
name|TOK_LPAREN
block|,
name|TOK_RPAREN
block|,
name|TOK_LBRACE
block|,
name|TOK_RBRACE
block|,
name|TOK_LBRACKET
block|,
name|TOK_RBRACKET
block|,
name|TOK_LANGLE
block|,
name|TOK_RANGLE
block|,
name|TOK_STAR
block|,
name|TOK_COMMA
block|,
name|TOK_EQUAL
block|,
name|TOK_COLON
block|,
name|TOK_SEMICOLON
block|,
name|TOK_CONST
block|,
name|TOK_STRUCT
block|,
name|TOK_UNION
block|,
name|TOK_SWITCH
block|,
name|TOK_CASE
block|,
name|TOK_DEFAULT
block|,
name|TOK_ENUM
block|,
name|TOK_TYPEDEF
block|,
name|TOK_INT
block|,
name|TOK_SHORT
block|,
name|TOK_LONG
block|,
name|TOK_UNSIGNED
block|,
name|TOK_FLOAT
block|,
name|TOK_DOUBLE
block|,
name|TOK_OPAQUE
block|,
name|TOK_CHAR
block|,
name|TOK_STRING
block|,
name|TOK_BOOL
block|,
name|TOK_VOID
block|,
name|TOK_PROGRAM
block|,
name|TOK_VERSION
block|,
name|TOK_EOF
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|tok_kind
name|tok_kind
typedef|;
end_typedef

begin_comment
comment|/*  * a token  */
end_comment

begin_struct
struct|struct
name|token
block|{
name|tok_kind
name|kind
decl_stmt|;
name|char
modifier|*
name|str
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|token
name|token
typedef|;
end_typedef

begin_comment
comment|/*  * routine interface  */
end_comment

begin_function_decl
name|void
name|scanprint
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|scan
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|scan2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|scan3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|scan_num
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|peek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|peekscan
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_token
parameter_list|()
function_decl|;
end_function_decl

end_unit

