begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1980 Regents of the University of California */
end_comment

begin_comment
comment|/* "@(#)astoks.h 4.1 %G%" */
end_comment

begin_comment
comment|/*  *	Message to the wary:  The order of tokens has been  *	hand optimized and assigned to that all switch statements  *	are implemented by a casel instruction on the VAX.   *	there are 4 switch statements that have to be worried about:  *	l)	Per character switch in the character scanner (scan_dot_s)  *	2)	Per token switch in the buffer manager (yylex)  *	3)	Per keyword switch in the parser (yyparse)  *	4)	Leading token switch for argments to opcodes  *	  *	You can't just add new tokens willy-nilly; make sure that you  *	add them into the proper order!  */
end_comment

begin_define
define|#
directive|define
name|FIRSTTOKEN
value|0
end_define

begin_comment
comment|/*  *	Tokens between ISPACE and INSTn are used by the per keyword switch  */
end_comment

begin_define
define|#
directive|define
name|ISPACE
value|1
end_define

begin_define
define|#
directive|define
name|IBYTE
value|2
end_define

begin_define
define|#
directive|define
name|IWORD
value|3
end_define

begin_define
define|#
directive|define
name|IINT
value|4
end_define

begin_define
define|#
directive|define
name|ILONG
value|5
end_define

begin_define
define|#
directive|define
name|IDATA
value|6
end_define

begin_define
define|#
directive|define
name|IGLOBAL
value|7
end_define

begin_define
define|#
directive|define
name|ISET
value|8
end_define

begin_define
define|#
directive|define
name|ITEXT
value|9
end_define

begin_define
define|#
directive|define
name|ICOMM
value|10
end_define

begin_define
define|#
directive|define
name|ILCOMM
value|11
end_define

begin_define
define|#
directive|define
name|IFLOAT
value|12
end_define

begin_define
define|#
directive|define
name|IDOUBLE
value|13
end_define

begin_define
define|#
directive|define
name|IORG
value|14
end_define

begin_define
define|#
directive|define
name|IASCII
value|15
end_define

begin_define
define|#
directive|define
name|IASCIZ
value|16
end_define

begin_define
define|#
directive|define
name|ILSYM
value|17
end_define

begin_define
define|#
directive|define
name|IFILE
value|18
end_define

begin_define
define|#
directive|define
name|ILINENO
value|19
end_define

begin_define
define|#
directive|define
name|IABORT
value|20
end_define

begin_define
define|#
directive|define
name|IFILL
value|21
end_define

begin_comment
comment|/*  *	Tokens between ISTAB and REG are used in the per token switch  */
end_comment

begin_define
define|#
directive|define
name|ISTAB
value|23
end_define

begin_define
define|#
directive|define
name|ISTABSTR
value|24
end_define

begin_define
define|#
directive|define
name|ISTABNONE
value|25
end_define

begin_define
define|#
directive|define
name|ISTABDOT
value|26
end_define

begin_define
define|#
directive|define
name|IJXXX
value|27
end_define

begin_define
define|#
directive|define
name|IALIGN
value|28
end_define

begin_define
define|#
directive|define
name|INST0
value|29
end_define

begin_define
define|#
directive|define
name|INSTn
value|30
end_define

begin_define
define|#
directive|define
name|BFINT
value|31
end_define

begin_define
define|#
directive|define
name|PARSEEOF
value|32
end_define

begin_define
define|#
directive|define
name|ILINESKIP
value|33
end_define

begin_define
define|#
directive|define
name|VOID
value|34
end_define

begin_define
define|#
directive|define
name|SKIP
value|35
end_define

begin_define
define|#
directive|define
name|INT
value|36
end_define

begin_define
define|#
directive|define
name|FLTNUM
value|37
end_define

begin_define
define|#
directive|define
name|NAME
value|38
end_define

begin_define
define|#
directive|define
name|STRING
value|39
end_define

begin_define
define|#
directive|define
name|QUAD
value|40
end_define

begin_comment
comment|/*  *	Tokens between SIZESPEC and REGOP are used in the instruction  *	argument switch  */
end_comment

begin_define
define|#
directive|define
name|SIZESPEC
value|41
end_define

begin_define
define|#
directive|define
name|REG
value|42
end_define

begin_define
define|#
directive|define
name|MUL
value|43
end_define

begin_define
define|#
directive|define
name|LITOP
value|44
end_define

begin_define
define|#
directive|define
name|LP
value|45
end_define

begin_define
define|#
directive|define
name|MP
value|46
end_define

begin_comment
comment|/*	  *	Tokens between REGOP and DIV are used in the per character switch  */
end_comment

begin_define
define|#
directive|define
name|NEEDSBUF
value|48
end_define

begin_comment
comment|/*signal refilling the input buffer*/
end_comment

begin_define
define|#
directive|define
name|REGOP
value|49
end_define

begin_comment
comment|/*the percent sign*/
end_comment

begin_define
define|#
directive|define
name|NL
value|50
end_define

begin_define
define|#
directive|define
name|SCANEOF
value|51
end_define

begin_define
define|#
directive|define
name|BADCHAR
value|52
end_define

begin_define
define|#
directive|define
name|SP
value|53
end_define

begin_define
define|#
directive|define
name|ALPH
value|54
end_define

begin_define
define|#
directive|define
name|DIG
value|55
end_define

begin_define
define|#
directive|define
name|SQ
value|56
end_define

begin_define
define|#
directive|define
name|DQ
value|57
end_define

begin_define
define|#
directive|define
name|SH
value|58
end_define

begin_define
define|#
directive|define
name|LSH
value|59
end_define

begin_define
define|#
directive|define
name|RSH
value|60
end_define

begin_define
define|#
directive|define
name|MINUS
value|61
end_define

begin_define
define|#
directive|define
name|SIZEQUOTE
value|62
end_define

begin_comment
comment|/*  *	Tokens between XOR and RP are used at random (primarily by the  *	expression analyzer), and not used in any switch  */
end_comment

begin_define
define|#
directive|define
name|XOR
value|64
end_define

begin_define
define|#
directive|define
name|DIV
value|65
end_define

begin_define
define|#
directive|define
name|SEMI
value|66
end_define

begin_define
define|#
directive|define
name|COLON
value|67
end_define

begin_define
define|#
directive|define
name|PLUS
value|68
end_define

begin_define
define|#
directive|define
name|IOR
value|69
end_define

begin_define
define|#
directive|define
name|AND
value|70
end_define

begin_define
define|#
directive|define
name|TILDE
value|71
end_define

begin_define
define|#
directive|define
name|ORNOT
value|72
end_define

begin_define
define|#
directive|define
name|CM
value|73
end_define

begin_define
define|#
directive|define
name|LB
value|74
end_define

begin_define
define|#
directive|define
name|RB
value|75
end_define

begin_define
define|#
directive|define
name|RP
value|76
end_define

begin_define
define|#
directive|define
name|LASTTOKEN
value|80
end_define

end_unit

