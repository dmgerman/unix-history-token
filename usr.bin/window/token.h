begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Edward Wang at The University of California, Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)token.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|token
value|(cx.x_token)
end_define

begin_define
define|#
directive|define
name|token_num
value|(cx.x_val.v_num)
end_define

begin_define
define|#
directive|define
name|token_str
value|(cx.x_val.v_str)
end_define

begin_define
define|#
directive|define
name|T_EOL
value|1
end_define

begin_define
define|#
directive|define
name|T_EOF
value|2
end_define

begin_define
define|#
directive|define
name|T_COMP
value|3
end_define

begin_define
define|#
directive|define
name|T_PLUS
value|4
end_define

begin_define
define|#
directive|define
name|T_MINUS
value|5
end_define

begin_define
define|#
directive|define
name|T_MUL
value|6
end_define

begin_define
define|#
directive|define
name|T_DIV
value|7
end_define

begin_define
define|#
directive|define
name|T_LP
value|8
end_define

begin_define
define|#
directive|define
name|T_RP
value|9
end_define

begin_define
define|#
directive|define
name|T_LB
value|10
end_define

begin_define
define|#
directive|define
name|T_RB
value|11
end_define

begin_define
define|#
directive|define
name|T_DOLLAR
value|12
end_define

begin_define
define|#
directive|define
name|T_COMMA
value|13
end_define

begin_define
define|#
directive|define
name|T_QUEST
value|14
end_define

begin_define
define|#
directive|define
name|T_COLON
value|15
end_define

begin_define
define|#
directive|define
name|T_CHAR
value|16
end_define

begin_define
define|#
directive|define
name|T_STR
value|17
end_define

begin_define
define|#
directive|define
name|T_NUM
value|18
end_define

begin_define
define|#
directive|define
name|T_MOD
value|19
end_define

begin_define
define|#
directive|define
name|T_XOR
value|20
end_define

begin_define
define|#
directive|define
name|T_DQ
value|21
end_define

begin_comment
comment|/* $? */
end_comment

begin_define
define|#
directive|define
name|T_GE
value|22
end_define

begin_define
define|#
directive|define
name|T_RS
value|23
end_define

begin_define
define|#
directive|define
name|T_GT
value|24
end_define

begin_define
define|#
directive|define
name|T_LE
value|25
end_define

begin_define
define|#
directive|define
name|T_LS
value|26
end_define

begin_define
define|#
directive|define
name|T_LT
value|27
end_define

begin_define
define|#
directive|define
name|T_EQ
value|28
end_define

begin_define
define|#
directive|define
name|T_ASSIGN
value|29
end_define

begin_define
define|#
directive|define
name|T_NE
value|30
end_define

begin_define
define|#
directive|define
name|T_NOT
value|31
end_define

begin_define
define|#
directive|define
name|T_ANDAND
value|32
end_define

begin_define
define|#
directive|define
name|T_AND
value|33
end_define

begin_define
define|#
directive|define
name|T_OROR
value|34
end_define

begin_define
define|#
directive|define
name|T_OR
value|35
end_define

begin_define
define|#
directive|define
name|T_IF
value|40
end_define

begin_define
define|#
directive|define
name|T_THEN
value|41
end_define

begin_define
define|#
directive|define
name|T_ELSIF
value|42
end_define

begin_define
define|#
directive|define
name|T_ELSE
value|43
end_define

begin_define
define|#
directive|define
name|T_ENDIF
value|44
end_define

end_unit

