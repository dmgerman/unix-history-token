begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* The following numbers are strange, and implementation-dependent */
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

begin_comment
comment|/* Integer constant */
end_comment

begin_define
define|#
directive|define
name|P2PLUS
value|6
end_define

begin_define
define|#
directive|define
name|P2PLUSEQ
value|7
end_define

begin_define
define|#
directive|define
name|P2MINUS
value|8
end_define

begin_define
define|#
directive|define
name|P2NEG
value|10
end_define

begin_define
define|#
directive|define
name|P2STAR
value|11
end_define

begin_define
define|#
directive|define
name|P2STAREQ
value|12
end_define

begin_define
define|#
directive|define
name|P2INDIRECT
value|13
end_define

begin_define
define|#
directive|define
name|P2BITAND
value|14
end_define

begin_define
define|#
directive|define
name|P2BITOR
value|17
end_define

begin_define
define|#
directive|define
name|P2BITXOR
value|19
end_define

begin_define
define|#
directive|define
name|P2QUEST
value|21
end_define

begin_define
define|#
directive|define
name|P2COLON
value|22
end_define

begin_define
define|#
directive|define
name|P2ANDAND
value|23
end_define

begin_define
define|#
directive|define
name|P2OROR
value|24
end_define

begin_define
define|#
directive|define
name|P2GOTO
value|37
end_define

begin_define
define|#
directive|define
name|P2LISTOP
value|56
end_define

begin_define
define|#
directive|define
name|P2ASSIGN
value|58
end_define

begin_define
define|#
directive|define
name|P2COMOP
value|59
end_define

begin_define
define|#
directive|define
name|P2SLASH
value|60
end_define

begin_define
define|#
directive|define
name|P2MOD
value|62
end_define

begin_define
define|#
directive|define
name|P2LSHIFT
value|64
end_define

begin_define
define|#
directive|define
name|P2RSHIFT
value|66
end_define

begin_define
define|#
directive|define
name|P2CALL
value|70
end_define

begin_define
define|#
directive|define
name|P2CALL0
value|72
end_define

begin_define
define|#
directive|define
name|P2NOT
value|76
end_define

begin_define
define|#
directive|define
name|P2BITNOT
value|77
end_define

begin_define
define|#
directive|define
name|P2EQ
value|80
end_define

begin_define
define|#
directive|define
name|P2NE
value|81
end_define

begin_define
define|#
directive|define
name|P2LE
value|82
end_define

begin_define
define|#
directive|define
name|P2LT
value|83
end_define

begin_define
define|#
directive|define
name|P2GE
value|84
end_define

begin_define
define|#
directive|define
name|P2GT
value|85
end_define

begin_define
define|#
directive|define
name|P2REG
value|94
end_define

begin_define
define|#
directive|define
name|P2OREG
value|95
end_define

begin_define
define|#
directive|define
name|P2CONV
value|104
end_define

begin_define
define|#
directive|define
name|P2FORCE
value|108
end_define

begin_define
define|#
directive|define
name|P2CBRANCH
value|109
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

