begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)pccdefs.h	5.1 (Berkeley) 6/7/85  */
end_comment

begin_define
define|#
directive|define
name|P2BAD
value|-1
end_define

begin_define
define|#
directive|define
name|P2NAME
value|2
end_define

begin_define
define|#
directive|define
name|P2ICON
value|4
end_define

begin_define
define|#
directive|define
name|P2PLUS
value|9
end_define

begin_define
define|#
directive|define
name|P2PLUSEQ
value|10
end_define

begin_define
define|#
directive|define
name|P2MINUS
value|11
end_define

begin_define
define|#
directive|define
name|P2NEG
value|13
end_define

begin_define
define|#
directive|define
name|P2STAR
value|14
end_define

begin_define
define|#
directive|define
name|P2STAREQ
value|15
end_define

begin_define
define|#
directive|define
name|P2INDIRECT
value|16
end_define

begin_define
define|#
directive|define
name|P2BITAND
value|17
end_define

begin_define
define|#
directive|define
name|P2BITOR
value|20
end_define

begin_define
define|#
directive|define
name|P2BITXOR
value|22
end_define

begin_define
define|#
directive|define
name|P2QUEST
value|24
end_define

begin_define
define|#
directive|define
name|P2COLON
value|25
end_define

begin_define
define|#
directive|define
name|P2ANDAND
value|26
end_define

begin_define
define|#
directive|define
name|P2OROR
value|27
end_define

begin_define
define|#
directive|define
name|P2GOTO
value|40
end_define

begin_define
define|#
directive|define
name|P2LISTOP
value|59
end_define

begin_define
define|#
directive|define
name|P2ASSIGN
value|61
end_define

begin_define
define|#
directive|define
name|P2COMOP
value|62
end_define

begin_define
define|#
directive|define
name|P2SLASH
value|63
end_define

begin_define
define|#
directive|define
name|P2MOD
value|65
end_define

begin_define
define|#
directive|define
name|P2LSHIFT
value|67
end_define

begin_define
define|#
directive|define
name|P2RSHIFT
value|69
end_define

begin_define
define|#
directive|define
name|P2CALL
value|73
end_define

begin_define
define|#
directive|define
name|P2CALL0
value|75
end_define

begin_define
define|#
directive|define
name|P2NOT
value|79
end_define

begin_define
define|#
directive|define
name|P2BITNOT
value|80
end_define

begin_define
define|#
directive|define
name|P2EQ
value|83
end_define

begin_define
define|#
directive|define
name|P2NE
value|84
end_define

begin_define
define|#
directive|define
name|P2LE
value|85
end_define

begin_define
define|#
directive|define
name|P2LT
value|86
end_define

begin_define
define|#
directive|define
name|P2GE
value|87
end_define

begin_define
define|#
directive|define
name|P2GT
value|88
end_define

begin_define
define|#
directive|define
name|P2REG
value|97
end_define

begin_define
define|#
directive|define
name|P2OREG
value|98
end_define

begin_define
define|#
directive|define
name|P2CONV
value|107
end_define

begin_define
define|#
directive|define
name|P2FORCE
value|111
end_define

begin_define
define|#
directive|define
name|P2CBRANCH
value|112
end_define

begin_comment
comment|/* special operators included only for fortran's use */
end_comment

begin_define
define|#
directive|define
name|P2PASS
value|200
end_define

begin_define
define|#
directive|define
name|P2STMT
value|201
end_define

begin_define
define|#
directive|define
name|P2SWITCH
value|202
end_define

begin_define
define|#
directive|define
name|P2LBRACKET
value|203
end_define

begin_define
define|#
directive|define
name|P2RBRACKET
value|204
end_define

begin_define
define|#
directive|define
name|P2EOF
value|205
end_define

begin_define
define|#
directive|define
name|P2ARIF
value|206
end_define

begin_define
define|#
directive|define
name|P2LABEL
value|207
end_define

begin_if
if|#
directive|if
name|TARGET
operator|==
name|PDP11
end_if

begin_define
define|#
directive|define
name|P2SHORT
value|4
end_define

begin_define
define|#
directive|define
name|P2INT
value|4
end_define

begin_define
define|#
directive|define
name|P2LONG
value|5
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P2SHORT
value|3
end_define

begin_define
define|#
directive|define
name|P2INT
value|4
end_define

begin_define
define|#
directive|define
name|P2LONG
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|P2CHAR
value|2
end_define

begin_define
define|#
directive|define
name|P2REAL
value|6
end_define

begin_define
define|#
directive|define
name|P2DREAL
value|7
end_define

begin_define
define|#
directive|define
name|P2PTR
value|020
end_define

begin_define
define|#
directive|define
name|P2FUNCT
value|040
end_define

end_unit

