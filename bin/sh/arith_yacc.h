begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 2007  *	Herbert Xu<herbert@gondor.apana.org.au>.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|ARITH_ASS
value|1
end_define

begin_define
define|#
directive|define
name|ARITH_OR
value|2
end_define

begin_define
define|#
directive|define
name|ARITH_AND
value|3
end_define

begin_define
define|#
directive|define
name|ARITH_BAD
value|4
end_define

begin_define
define|#
directive|define
name|ARITH_NUM
value|5
end_define

begin_define
define|#
directive|define
name|ARITH_VAR
value|6
end_define

begin_define
define|#
directive|define
name|ARITH_NOT
value|7
end_define

begin_define
define|#
directive|define
name|ARITH_BINOP_MIN
value|8
end_define

begin_define
define|#
directive|define
name|ARITH_LE
value|8
end_define

begin_define
define|#
directive|define
name|ARITH_GE
value|9
end_define

begin_define
define|#
directive|define
name|ARITH_LT
value|10
end_define

begin_define
define|#
directive|define
name|ARITH_GT
value|11
end_define

begin_define
define|#
directive|define
name|ARITH_EQ
value|12
end_define

begin_define
define|#
directive|define
name|ARITH_REM
value|13
end_define

begin_define
define|#
directive|define
name|ARITH_BAND
value|14
end_define

begin_define
define|#
directive|define
name|ARITH_LSHIFT
value|15
end_define

begin_define
define|#
directive|define
name|ARITH_RSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ARITH_MUL
value|17
end_define

begin_define
define|#
directive|define
name|ARITH_ADD
value|18
end_define

begin_define
define|#
directive|define
name|ARITH_BOR
value|19
end_define

begin_define
define|#
directive|define
name|ARITH_SUB
value|20
end_define

begin_define
define|#
directive|define
name|ARITH_BXOR
value|21
end_define

begin_define
define|#
directive|define
name|ARITH_DIV
value|22
end_define

begin_define
define|#
directive|define
name|ARITH_NE
value|23
end_define

begin_define
define|#
directive|define
name|ARITH_BINOP_MAX
value|24
end_define

begin_define
define|#
directive|define
name|ARITH_ASS_MIN
value|24
end_define

begin_define
define|#
directive|define
name|ARITH_REMASS
value|24
end_define

begin_define
define|#
directive|define
name|ARITH_BANDASS
value|25
end_define

begin_define
define|#
directive|define
name|ARITH_LSHIFTASS
value|26
end_define

begin_define
define|#
directive|define
name|ARITH_RSHIFTASS
value|27
end_define

begin_define
define|#
directive|define
name|ARITH_MULASS
value|28
end_define

begin_define
define|#
directive|define
name|ARITH_ADDASS
value|29
end_define

begin_define
define|#
directive|define
name|ARITH_BORASS
value|30
end_define

begin_define
define|#
directive|define
name|ARITH_SUBASS
value|31
end_define

begin_define
define|#
directive|define
name|ARITH_BXORASS
value|32
end_define

begin_define
define|#
directive|define
name|ARITH_DIVASS
value|33
end_define

begin_define
define|#
directive|define
name|ARITH_ASS_MAX
value|34
end_define

begin_define
define|#
directive|define
name|ARITH_LPAREN
value|34
end_define

begin_define
define|#
directive|define
name|ARITH_RPAREN
value|35
end_define

begin_define
define|#
directive|define
name|ARITH_BNOT
value|36
end_define

begin_define
define|#
directive|define
name|ARITH_QMARK
value|37
end_define

begin_define
define|#
directive|define
name|ARITH_COLON
value|38
end_define

begin_union
union|union
name|yystype
block|{
name|arith_t
name|val
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
union|;
end_union

begin_decl_stmt
specifier|extern
name|union
name|yystype
name|yylval
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|yylex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

