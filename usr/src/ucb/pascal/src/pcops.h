begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_comment
comment|/* static	char sccsid[] = "@(#)pcops.h 1.2 2/1/83"; */
end_comment

begin_comment
comment|/*      *	tree node operators      */
end_comment

begin_define
define|#
directive|define
name|P2UNDEFINED
value|1
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
name|P2STRING
value|3
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
name|P2FCON
value|5
end_define

begin_define
define|#
directive|define
name|P2PLUS
value|6
end_define

begin_define
define|#
directive|define
name|P2MINUS
value|8
end_define

begin_comment
comment|/* also unary == P2NEG */
end_comment

begin_define
define|#
directive|define
name|P2MUL
value|11
end_define

begin_comment
comment|/* also unary == P2INDIRECT */
end_comment

begin_define
define|#
directive|define
name|P2AND
value|14
end_define

begin_comment
comment|/* also unary */
end_comment

begin_define
define|#
directive|define
name|P2OR
value|17
end_define

begin_define
define|#
directive|define
name|P2ER
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

begin_comment
comment|/*      *	yacc operator classes, reserved words, little symbols, etc.      *	operators 25 .. 57 not used, except 56      */
end_comment

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
name|P2DIV
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
name|P2LS
value|64
end_define

begin_define
define|#
directive|define
name|P2RS
value|66
end_define

begin_define
define|#
directive|define
name|P2DOT
value|68
end_define

begin_define
define|#
directive|define
name|P2STREF
value|69
end_define

begin_define
define|#
directive|define
name|P2CALL
value|70
end_define

begin_comment
comment|/* also unary */
end_comment

begin_define
define|#
directive|define
name|P2FORTCALL
value|73
end_define

begin_comment
comment|/* also unary */
end_comment

begin_define
define|#
directive|define
name|P2NOT
value|76
end_define

begin_define
define|#
directive|define
name|P2COMPL
value|77
end_define

begin_define
define|#
directive|define
name|P2INCR
value|78
end_define

begin_define
define|#
directive|define
name|P2DECR
value|79
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
name|P2ULE
value|86
end_define

begin_define
define|#
directive|define
name|P2ULT
value|87
end_define

begin_define
define|#
directive|define
name|P2UGE
value|88
end_define

begin_define
define|#
directive|define
name|P2UGT
value|89
end_define

begin_define
define|#
directive|define
name|P2SETBIT
value|90
end_define

begin_define
define|#
directive|define
name|P2TESTBIT
value|91
end_define

begin_define
define|#
directive|define
name|P2RESETBIT
value|92
end_define

begin_define
define|#
directive|define
name|P2ARS
value|93
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
name|P2CCODES
value|96
end_define

begin_define
define|#
directive|define
name|P2FREE
value|97
end_define

begin_define
define|#
directive|define
name|P2STASG
value|98
end_define

begin_define
define|#
directive|define
name|P2STARG
value|99
end_define

begin_define
define|#
directive|define
name|P2STCALL
value|100
end_define

begin_comment
comment|/* also unary */
end_comment

begin_comment
comment|/*      *	some conversion operators      */
end_comment

begin_define
define|#
directive|define
name|P2FLD
value|103
end_define

begin_define
define|#
directive|define
name|P2SCONV
value|104
end_define

begin_define
define|#
directive|define
name|P2PCONV
value|105
end_define

begin_define
define|#
directive|define
name|P2PMCONV
value|106
end_define

begin_define
define|#
directive|define
name|P2PVCONV
value|107
end_define

begin_comment
comment|/*      *	special node operators, used for special contexts      */
end_comment

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

begin_define
define|#
directive|define
name|P2INIT
value|110
end_define

begin_define
define|#
directive|define
name|P2CAST
value|111
end_define

begin_comment
comment|/*      *	prefix unary operator modifier      */
end_comment

begin_define
define|#
directive|define
name|P2ASG
value|1+
end_define

begin_define
define|#
directive|define
name|P2UNARY
value|2+
end_define

begin_comment
comment|/*      *	these borrowed from /usr/src/cmd/mip/fort.c      *	to use the binary interface.      *	only FTEXT, FEXPR, FLBRAC, FRBRAC, and FEOF are used      */
end_comment

begin_define
define|#
directive|define
name|P2FTEXT
value|200
end_define

begin_define
define|#
directive|define
name|P2FEXPR
value|201
end_define

begin_define
define|#
directive|define
name|P2FLBRAC
value|203
end_define

begin_define
define|#
directive|define
name|P2FRBRAC
value|204
end_define

begin_define
define|#
directive|define
name|P2FEOF
value|205
end_define

begin_comment
comment|/*      *	type names      */
end_comment

begin_define
define|#
directive|define
name|P2UNDEF
value|0
end_define

begin_define
define|#
directive|define
name|P2FARG
value|1
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
name|P2SHORT
value|3
end_define

begin_define
define|#
directive|define
name|P2INT
value|4
end_define

begin_comment
comment|/* this is also used for booleans */
end_comment

begin_define
define|#
directive|define
name|P2LONG
value|5
end_define

begin_comment
comment|/* don't use these, the second pass chokes */
end_comment

begin_define
define|#
directive|define
name|P2FLOAT
value|6
end_define

begin_define
define|#
directive|define
name|P2DOUBLE
value|7
end_define

begin_define
define|#
directive|define
name|P2STRTY
value|8
end_define

begin_define
define|#
directive|define
name|P2UNIONTY
value|9
end_define

begin_define
define|#
directive|define
name|P2ENUMTY
value|10
end_define

begin_define
define|#
directive|define
name|P2MOETY
value|11
end_define

begin_define
define|#
directive|define
name|P2UCHAR
value|12
end_define

begin_define
define|#
directive|define
name|P2USHORT
value|13
end_define

begin_define
define|#
directive|define
name|P2UNSIGNED
value|14
end_define

begin_define
define|#
directive|define
name|P2ULONG
value|15
end_define

begin_comment
comment|/*      *	type modifiers      */
end_comment

begin_define
define|#
directive|define
name|P2PTR
value|020
end_define

begin_define
define|#
directive|define
name|P2FTN
value|040
end_define

begin_define
define|#
directive|define
name|P2ARY
value|060
end_define

begin_comment
comment|/*      *	see the comment for p2type for an explanation of c type words      */
end_comment

begin_define
define|#
directive|define
name|P2BASETYPE
value|017
end_define

begin_define
define|#
directive|define
name|P2TYPESHIFT
value|2
end_define

begin_comment
comment|/*      *	add a most significant type modifier, m, to a type, t      */
end_comment

begin_define
define|#
directive|define
name|ADDTYPE
parameter_list|(
name|t
parameter_list|,
name|m
parameter_list|)
value|( ( ( ( t )& ~P2BASETYPE )<< P2TYPESHIFT )	\ 		  | ( m )						\ 		  | ( ( t )& P2BASETYPE ) )
end_define

end_unit

