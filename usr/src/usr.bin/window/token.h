begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)token.h	3.8 (Berkeley) %G%  */
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

