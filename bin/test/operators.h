begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)operators.h	8.3 (Berkeley) 4/2/94  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|NOT
value|0
end_define

begin_define
define|#
directive|define
name|ISBLOCK
value|1
end_define

begin_define
define|#
directive|define
name|ISCHAR
value|2
end_define

begin_define
define|#
directive|define
name|ISDIR
value|3
end_define

begin_define
define|#
directive|define
name|ISEXIST
value|4
end_define

begin_define
define|#
directive|define
name|ISFILE
value|5
end_define

begin_define
define|#
directive|define
name|ISSETGID
value|6
end_define

begin_define
define|#
directive|define
name|ISSYMLINK
value|7
end_define

begin_define
define|#
directive|define
name|ISSTICKY
value|8
end_define

begin_define
define|#
directive|define
name|STRLEN
value|9
end_define

begin_define
define|#
directive|define
name|ISFIFO
value|10
end_define

begin_define
define|#
directive|define
name|ISREAD
value|11
end_define

begin_define
define|#
directive|define
name|ISSIZE
value|12
end_define

begin_define
define|#
directive|define
name|ISTTY
value|13
end_define

begin_define
define|#
directive|define
name|ISSETUID
value|14
end_define

begin_define
define|#
directive|define
name|ISWRITE
value|15
end_define

begin_define
define|#
directive|define
name|ISEXEC
value|16
end_define

begin_define
define|#
directive|define
name|NULSTR
value|17
end_define

begin_define
define|#
directive|define
name|FIRST_BINARY_OP
value|18
end_define

begin_define
define|#
directive|define
name|OR1
value|18
end_define

begin_define
define|#
directive|define
name|OR2
value|19
end_define

begin_define
define|#
directive|define
name|AND1
value|20
end_define

begin_define
define|#
directive|define
name|AND2
value|21
end_define

begin_define
define|#
directive|define
name|STREQ
value|22
end_define

begin_define
define|#
directive|define
name|STRNE
value|23
end_define

begin_define
define|#
directive|define
name|EQ
value|24
end_define

begin_define
define|#
directive|define
name|NE
value|25
end_define

begin_define
define|#
directive|define
name|GT
value|26
end_define

begin_define
define|#
directive|define
name|LT
value|27
end_define

begin_define
define|#
directive|define
name|LE
value|28
end_define

begin_define
define|#
directive|define
name|GE
value|29
end_define

begin_define
define|#
directive|define
name|OP_INT
value|1
end_define

begin_comment
comment|/* arguments to operator are integer */
end_comment

begin_define
define|#
directive|define
name|OP_STRING
value|2
end_define

begin_comment
comment|/* arguments to operator are string */
end_comment

begin_define
define|#
directive|define
name|OP_FILE
value|3
end_define

begin_comment
comment|/* argument is a file name */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|unary_op
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|binary_op
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|andor_op
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|op_priority
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|op_argflag
index|[]
decl_stmt|;
end_decl_stmt

end_unit

