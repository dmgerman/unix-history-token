begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * Copyright (c) 1976 Board of Trustees of the University of Illinois.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley and the University  * of Illinois, Urbana.  The name of either  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)indent_codes.h	5.5 (Berkeley) 6/29/88  */
end_comment

begin_comment
comment|/* FILE NAME: 	indent_codes.h  PURPOSE: 	This include file contains defines for codes used within indent.  They 	are here so that codes passed between and within routines can be 	referenced symbolically.  GLOBALS: 	No global variables, just a bunch of defines  FUNCTIONS: 	None */
end_comment

begin_escape
end_escape

begin_define
define|#
directive|define
name|newline
value|1
end_define

begin_define
define|#
directive|define
name|lparen
value|2
end_define

begin_define
define|#
directive|define
name|rparen
value|3
end_define

begin_define
define|#
directive|define
name|unary_op
value|4
end_define

begin_define
define|#
directive|define
name|binary_op
value|5
end_define

begin_define
define|#
directive|define
name|postop
value|6
end_define

begin_define
define|#
directive|define
name|question
value|7
end_define

begin_define
define|#
directive|define
name|casestmt
value|8
end_define

begin_define
define|#
directive|define
name|colon
value|9
end_define

begin_define
define|#
directive|define
name|semicolon
value|10
end_define

begin_define
define|#
directive|define
name|lbrace
value|11
end_define

begin_define
define|#
directive|define
name|rbrace
value|12
end_define

begin_define
define|#
directive|define
name|ident
value|13
end_define

begin_define
define|#
directive|define
name|comma
value|14
end_define

begin_define
define|#
directive|define
name|comment
value|15
end_define

begin_define
define|#
directive|define
name|swstmt
value|16
end_define

begin_define
define|#
directive|define
name|preesc
value|17
end_define

begin_define
define|#
directive|define
name|form_feed
value|18
end_define

begin_define
define|#
directive|define
name|decl
value|19
end_define

begin_define
define|#
directive|define
name|sp_paren
value|20
end_define

begin_define
define|#
directive|define
name|sp_nparen
value|21
end_define

begin_define
define|#
directive|define
name|ifstmt
value|22
end_define

begin_define
define|#
directive|define
name|whilestmt
value|23
end_define

begin_define
define|#
directive|define
name|forstmt
value|24
end_define

begin_define
define|#
directive|define
name|stmt
value|25
end_define

begin_define
define|#
directive|define
name|stmtl
value|26
end_define

begin_define
define|#
directive|define
name|elselit
value|27
end_define

begin_define
define|#
directive|define
name|dolit
value|28
end_define

begin_define
define|#
directive|define
name|dohead
value|29
end_define

begin_define
define|#
directive|define
name|ifhead
value|30
end_define

begin_define
define|#
directive|define
name|elsehead
value|31
end_define

begin_define
define|#
directive|define
name|period
value|32
end_define

end_unit

