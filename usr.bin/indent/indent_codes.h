begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Sun Microsystems, Inc.  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)indent_codes.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

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

