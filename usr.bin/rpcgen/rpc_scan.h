begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *   * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *   * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"@(#)rpc_scan.h 1.11     94/05/15 SMI"
end_pragma

begin_comment
comment|/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
end_comment

begin_comment
comment|/*	  All Rights Reserved  	*/
end_comment

begin_comment
comment|/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
end_comment

begin_comment
comment|/*	The copyright notice above does not evidence any   	*/
end_comment

begin_comment
comment|/*	actual or intended publication of such source code.	*/
end_comment

begin_comment
comment|/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++ *	PROPRIETARY NOTICE (Combined) * * This source code is unpublished proprietary information * constituting, or derived under license from AT&T's UNIX(r) System V. * In addition, portions of such source code were derived from Berkeley * 4.3 BSD under license from the Regents of the University of * California. * * * *	Copyright Notice  * * Notice of copyright on this source code product does not indicate  *  publication. * *	(c) 1986,1987,1988.1989  Sun Microsystems, Inc *	(c) 1983,1984,1985,1986,1987,1988,1989  AT&T. *          All rights reserved. */
end_comment

begin_comment
comment|/*      @(#)rpc_scan.h  1.3  90/08/29  (C) 1987 SMI   */
end_comment

begin_comment
comment|/*  * rpc_scan.h, Definitions for the RPCL scanner   */
end_comment

begin_comment
comment|/*  * kinds of tokens   */
end_comment

begin_enum
enum|enum
name|tok_kind
block|{
name|TOK_IDENT
block|,
name|TOK_CHARCONST
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
name|TOK_HYPER
block|,
name|TOK_UNSIGNED
block|,
name|TOK_FLOAT
block|,
name|TOK_DOUBLE
block|,
name|TOK_QUAD
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
comment|/*  * a token   */
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
comment|/*  * routine interface   */
end_comment

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

