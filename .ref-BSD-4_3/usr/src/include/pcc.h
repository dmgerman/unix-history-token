begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)pcc.h	5.1 (Berkeley) 5/30/85  */
end_comment

begin_comment
comment|/*  * This file contains definitions for all the constants and structures  *	needed to use the intermediate code files generated and read by  *	the Portable C Compiler and related compilers.  *  * Rules for changing this code:  *   1)	All op values must be integer constants -- this permits us to run  *	a 'sed' script on this file to create %term declarations for yacc.  *   2)	Because the PCC uses fancy ASG and UNARY macros, assignment  *	operators must have values 1 greater than corresponding normal  *	operators, and unary operators must have values 2 greater ditto.  *   3) Ops used only by f1 must have values>= 150 (PCCF_FORTOPS).  *   4)	Other language-dependent ops must have values>= 200.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCC_TOKENS
end_ifndef

begin_define
define|#
directive|define
name|PCC_TOKENS
value|0
end_define

begin_define
define|#
directive|define
name|PCC_ERROR
value|1
end_define

begin_comment
comment|/* an error node */
end_comment

begin_define
define|#
directive|define
name|PCC_FREE
value|2
end_define

begin_comment
comment|/* an unused node */
end_comment

begin_comment
comment|/*  * Constants.  */
end_comment

begin_define
define|#
directive|define
name|PCC_STRING
value|3
end_define

begin_comment
comment|/* a string constant */
end_comment

begin_define
define|#
directive|define
name|PCC_ICON
value|4
end_define

begin_comment
comment|/* an integer constant */
end_comment

begin_define
define|#
directive|define
name|PCC_FCON
value|5
end_define

begin_comment
comment|/* a floating point constant */
end_comment

begin_define
define|#
directive|define
name|PCC_DCON
value|6
end_define

begin_comment
comment|/* a double precision f.p. constant */
end_comment

begin_comment
comment|/*  * Leaf types.  */
end_comment

begin_define
define|#
directive|define
name|PCC_NAME
value|7
end_define

begin_comment
comment|/* an identifier */
end_comment

begin_define
define|#
directive|define
name|PCC_REG
value|8
end_define

begin_comment
comment|/* a register */
end_comment

begin_define
define|#
directive|define
name|PCC_OREG
value|9
end_define

begin_comment
comment|/* register and offset */
end_comment

begin_define
define|#
directive|define
name|PCC_CCODES
value|10
end_define

begin_comment
comment|/* condition codes */
end_comment

begin_define
define|#
directive|define
name|PCC_FLD
value|11
end_define

begin_comment
comment|/* a bit field */
end_comment

begin_comment
comment|/*  * Arithmetic operators.  */
end_comment

begin_define
define|#
directive|define
name|PCC_PLUS
value|12
end_define

begin_comment
comment|/* + */
end_comment

begin_define
define|#
directive|define
name|PCC_PLUSEQ
value|13
end_define

begin_comment
comment|/* += */
end_comment

begin_define
define|#
directive|define
name|PCC_UPLUS
value|14
end_define

begin_comment
comment|/* unary + (for completeness) */
end_comment

begin_define
define|#
directive|define
name|PCC_MINUS
value|15
end_define

begin_comment
comment|/* - */
end_comment

begin_define
define|#
directive|define
name|PCC_MINUSEQ
value|16
end_define

begin_comment
comment|/* -= */
end_comment

begin_define
define|#
directive|define
name|PCC_UMINUS
value|17
end_define

begin_comment
comment|/* unary - */
end_comment

begin_define
define|#
directive|define
name|PCC_MUL
value|18
end_define

begin_comment
comment|/* * */
end_comment

begin_define
define|#
directive|define
name|PCC_MULEQ
value|19
end_define

begin_comment
comment|/* *= */
end_comment

begin_comment
comment|/* Reserve a slot for 'unary *', which is PCC jargon for PCC_DEREF (yech) */
end_comment

begin_define
define|#
directive|define
name|PCC_DIV
value|21
end_define

begin_comment
comment|/* / */
end_comment

begin_define
define|#
directive|define
name|PCC_DIVEQ
value|22
end_define

begin_comment
comment|/* /= */
end_comment

begin_define
define|#
directive|define
name|PCC_MOD
value|23
end_define

begin_comment
comment|/* % */
end_comment

begin_define
define|#
directive|define
name|PCC_MODEQ
value|24
end_define

begin_comment
comment|/* %= */
end_comment

begin_define
define|#
directive|define
name|PCC_INCR
value|25
end_define

begin_comment
comment|/* ++ */
end_comment

begin_define
define|#
directive|define
name|PCC_DECR
value|26
end_define

begin_comment
comment|/* -- */
end_comment

begin_define
define|#
directive|define
name|PCC_ASSIGN
value|27
end_define

begin_comment
comment|/* = (these last 3 are stretching it) */
end_comment

begin_comment
comment|/*  * Bit operators.  */
end_comment

begin_define
define|#
directive|define
name|PCC_AND
value|28
end_define

begin_comment
comment|/*& */
end_comment

begin_define
define|#
directive|define
name|PCC_ANDEQ
value|29
end_define

begin_comment
comment|/*&= */
end_comment

begin_comment
comment|/* Reserve a slot for 'unary&', jargon for PCC_ADDROF */
end_comment

begin_define
define|#
directive|define
name|PCC_OR
value|31
end_define

begin_comment
comment|/* | */
end_comment

begin_define
define|#
directive|define
name|PCC_OREQ
value|32
end_define

begin_comment
comment|/* |= */
end_comment

begin_define
define|#
directive|define
name|PCC_ER
value|33
end_define

begin_comment
comment|/* ^ */
end_comment

begin_define
define|#
directive|define
name|PCC_EREQ
value|34
end_define

begin_comment
comment|/* ^= */
end_comment

begin_define
define|#
directive|define
name|PCC_LS
value|35
end_define

begin_comment
comment|/*<< */
end_comment

begin_define
define|#
directive|define
name|PCC_LSEQ
value|36
end_define

begin_comment
comment|/*<<= */
end_comment

begin_define
define|#
directive|define
name|PCC_RS
value|37
end_define

begin_comment
comment|/*>> */
end_comment

begin_define
define|#
directive|define
name|PCC_RSEQ
value|38
end_define

begin_comment
comment|/*>>= */
end_comment

begin_define
define|#
directive|define
name|PCC_COMPL
value|39
end_define

begin_comment
comment|/* ~ */
end_comment

begin_comment
comment|/*  * Booleans.  */
end_comment

begin_define
define|#
directive|define
name|PCC_EQ
value|40
end_define

begin_comment
comment|/* == */
end_comment

begin_define
define|#
directive|define
name|PCC_NE
value|41
end_define

begin_comment
comment|/* != */
end_comment

begin_define
define|#
directive|define
name|PCC_LE
value|42
end_define

begin_comment
comment|/*<= */
end_comment

begin_define
define|#
directive|define
name|PCC_LT
value|43
end_define

begin_comment
comment|/*< */
end_comment

begin_define
define|#
directive|define
name|PCC_GE
value|44
end_define

begin_comment
comment|/*>= */
end_comment

begin_define
define|#
directive|define
name|PCC_GT
value|45
end_define

begin_comment
comment|/*> */
end_comment

begin_define
define|#
directive|define
name|PCC_ULE
value|46
end_define

begin_comment
comment|/* unsigned<= */
end_comment

begin_define
define|#
directive|define
name|PCC_ULT
value|47
end_define

begin_comment
comment|/* unsigned< */
end_comment

begin_define
define|#
directive|define
name|PCC_UGE
value|48
end_define

begin_comment
comment|/* unsigned>= */
end_comment

begin_define
define|#
directive|define
name|PCC_UGT
value|49
end_define

begin_comment
comment|/* unsigned> */
end_comment

begin_define
define|#
directive|define
name|PCC_QUEST
value|50
end_define

begin_comment
comment|/* ? (for conditional expressions) */
end_comment

begin_define
define|#
directive|define
name|PCC_COLON
value|51
end_define

begin_comment
comment|/* : (for conditional expressions) */
end_comment

begin_define
define|#
directive|define
name|PCC_ANDAND
value|52
end_define

begin_comment
comment|/*&& */
end_comment

begin_define
define|#
directive|define
name|PCC_OROR
value|53
end_define

begin_comment
comment|/* || */
end_comment

begin_define
define|#
directive|define
name|PCC_NOT
value|54
end_define

begin_comment
comment|/* ! */
end_comment

begin_comment
comment|/*  * Function calls.  */
end_comment

begin_define
define|#
directive|define
name|PCC_CALL
value|55
end_define

begin_comment
comment|/* call by value */
end_comment

begin_comment
comment|/* no ASG */
end_comment

begin_define
define|#
directive|define
name|PCC_UCALL
value|57
end_define

begin_comment
comment|/* call with no arguments */
end_comment

begin_define
define|#
directive|define
name|PCC_FORTCALL
value|58
end_define

begin_comment
comment|/* call by reference? */
end_comment

begin_comment
comment|/* no ASG */
end_comment

begin_define
define|#
directive|define
name|PCC_UFORTCALL
value|60
end_define

begin_comment
comment|/* ??? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INLINE
end_ifdef

begin_define
define|#
directive|define
name|PCC_INLINE
value|61
end_define

begin_comment
comment|/* inline function */
end_comment

begin_comment
comment|/* no ASG */
end_comment

begin_define
define|#
directive|define
name|PCC_UINLINE
value|63
end_define

begin_comment
comment|/* inline with no arguments */
end_comment

begin_endif
endif|#
directive|endif
endif|INLINE
end_endif

begin_comment
comment|/*  * Referencing and dereferencing.  */
end_comment

begin_define
define|#
directive|define
name|PCC_DEREF
value|20
end_define

begin_comment
comment|/* * */
end_comment

begin_define
define|#
directive|define
name|PCC_ADDROF
value|30
end_define

begin_comment
comment|/*& */
end_comment

begin_comment
comment|/*  * Special structure operators.  */
end_comment

begin_define
define|#
directive|define
name|PCC_DOT
value|64
end_define

begin_comment
comment|/* . */
end_comment

begin_define
define|#
directive|define
name|PCC_STREF
value|65
end_define

begin_comment
comment|/* -> */
end_comment

begin_define
define|#
directive|define
name|PCC_STASG
value|66
end_define

begin_comment
comment|/* structure assignment */
end_comment

begin_define
define|#
directive|define
name|PCC_STARG
value|67
end_define

begin_comment
comment|/* an argument of type structure */
end_comment

begin_define
define|#
directive|define
name|PCC_STCALL
value|68
end_define

begin_comment
comment|/* a function of type structure */
end_comment

begin_comment
comment|/* no ASG */
end_comment

begin_define
define|#
directive|define
name|PCC_USTCALL
value|70
end_define

begin_comment
comment|/* unary structure function */
end_comment

begin_comment
comment|/*  * Conversions.  */
end_comment

begin_define
define|#
directive|define
name|PCC_SCONV
value|71
end_define

begin_comment
comment|/* scalar conversion */
end_comment

begin_define
define|#
directive|define
name|PCC_PCONV
value|72
end_define

begin_comment
comment|/* pointer conversion */
end_comment

begin_define
define|#
directive|define
name|PCC_PMCONV
value|73
end_define

begin_comment
comment|/* pointer multiply conversion */
end_comment

begin_define
define|#
directive|define
name|PCC_PVCONV
value|74
end_define

begin_comment
comment|/* pointer divide conversion */
end_comment

begin_define
define|#
directive|define
name|PCC_CAST
value|75
end_define

begin_comment
comment|/* redundant? */
end_comment

begin_comment
comment|/*  * Bracket types.  */
end_comment

begin_define
define|#
directive|define
name|PCC_LB
value|76
end_define

begin_comment
comment|/* [ */
end_comment

begin_define
define|#
directive|define
name|PCC_RB
value|77
end_define

begin_comment
comment|/* ] */
end_comment

begin_comment
comment|/*  * Comma nodes.  */
end_comment

begin_define
define|#
directive|define
name|PCC_COMOP
value|78
end_define

begin_comment
comment|/* , (in expressions) */
end_comment

begin_define
define|#
directive|define
name|PCC_CM
value|79
end_define

begin_comment
comment|/* , (in argument lists) */
end_comment

begin_comment
comment|/*  * Miscellaneous.  */
end_comment

begin_define
define|#
directive|define
name|PCC_FORCE
value|80
end_define

begin_comment
comment|/* result of last expression goes in r0 */
end_comment

begin_define
define|#
directive|define
name|PCC_GOTO
value|81
end_define

begin_comment
comment|/* unconditional goto */
end_comment

begin_define
define|#
directive|define
name|PCC_CBRANCH
value|82
end_define

begin_comment
comment|/* goto label if !test */
end_comment

begin_define
define|#
directive|define
name|PCC_RETURN
value|83
end_define

begin_comment
comment|/* return from function */
end_comment

begin_define
define|#
directive|define
name|PCC_INIT
value|84
end_define

begin_comment
comment|/* initialized data */
end_comment

begin_define
define|#
directive|define
name|PCC_TYPE
value|85
end_define

begin_comment
comment|/* a type */
end_comment

begin_define
define|#
directive|define
name|PCC_CLASS
value|86
end_define

begin_comment
comment|/* a storage class */
end_comment

begin_define
define|#
directive|define
name|PCC_MAXOP
value|86
end_define

begin_comment
comment|/* highest numbered PCC op */
end_comment

begin_comment
comment|/*  * Special codes for interfacing to /lib/f1.  */
end_comment

begin_define
define|#
directive|define
name|PCCF_FORTOPS
value|150
end_define

begin_define
define|#
directive|define
name|PCCF_FTEXT
value|150
end_define

begin_comment
comment|/* pass literal assembler text */
end_comment

begin_define
define|#
directive|define
name|PCCF_FEXPR
value|151
end_define

begin_comment
comment|/* a statement */
end_comment

begin_define
define|#
directive|define
name|PCCF_FSWITCH
value|152
end_define

begin_comment
comment|/* not implemented */
end_comment

begin_define
define|#
directive|define
name|PCCF_FLBRAC
value|153
end_define

begin_comment
comment|/* beginning of subroutine */
end_comment

begin_define
define|#
directive|define
name|PCCF_FRBRAC
value|154
end_define

begin_comment
comment|/* end of subroutine */
end_comment

begin_define
define|#
directive|define
name|PCCF_FEOF
value|155
end_define

begin_comment
comment|/* end of file */
end_comment

begin_define
define|#
directive|define
name|PCCF_FARIF
value|156
end_define

begin_comment
comment|/* not implemented */
end_comment

begin_define
define|#
directive|define
name|PCCF_FLABEL
value|157
end_define

begin_comment
comment|/* an f77 label */
end_comment

begin_endif
endif|#
directive|endif
endif|PCC_TOKENS
end_endif

begin_comment
comment|/*  * Types, as encoded in intermediate file cookies.  */
end_comment

begin_define
define|#
directive|define
name|PCCT_UNDEF
value|0
end_define

begin_define
define|#
directive|define
name|PCCT_FARG
value|1
end_define

begin_comment
comment|/* function argument */
end_comment

begin_define
define|#
directive|define
name|PCCT_CHAR
value|2
end_define

begin_define
define|#
directive|define
name|PCCT_SHORT
value|3
end_define

begin_define
define|#
directive|define
name|PCCT_INT
value|4
end_define

begin_define
define|#
directive|define
name|PCCT_LONG
value|5
end_define

begin_define
define|#
directive|define
name|PCCT_FLOAT
value|6
end_define

begin_define
define|#
directive|define
name|PCCT_DOUBLE
value|7
end_define

begin_define
define|#
directive|define
name|PCCT_STRTY
value|8
end_define

begin_define
define|#
directive|define
name|PCCT_UNIONTY
value|9
end_define

begin_define
define|#
directive|define
name|PCCT_ENUMTY
value|10
end_define

begin_define
define|#
directive|define
name|PCCT_MOETY
value|11
end_define

begin_comment
comment|/* member of enum */
end_comment

begin_define
define|#
directive|define
name|PCCT_UCHAR
value|12
end_define

begin_define
define|#
directive|define
name|PCCT_USHORT
value|13
end_define

begin_define
define|#
directive|define
name|PCCT_UNSIGNED
value|14
end_define

begin_define
define|#
directive|define
name|PCCT_ULONG
value|15
end_define

begin_comment
comment|/*  * Type modifiers.  */
end_comment

begin_define
define|#
directive|define
name|PCCTM_PTR
value|020
end_define

begin_define
define|#
directive|define
name|PCCTM_FTN
value|040
end_define

begin_define
define|#
directive|define
name|PCCTM_ARY
value|060
end_define

begin_define
define|#
directive|define
name|PCCTM_BASETYPE
value|017
end_define

begin_define
define|#
directive|define
name|PCCTM_TYPESHIFT
value|2
end_define

begin_comment
comment|/*  * Useful macros.  'PCCOM' macros apply to ops.  */
end_comment

begin_define
define|#
directive|define
name|PCCOM_ASG
value|1+
end_define

begin_define
define|#
directive|define
name|PCCOM_UNARY
value|2+
end_define

begin_define
define|#
directive|define
name|PCCOM_NOASG
value|(-1)+
end_define

begin_define
define|#
directive|define
name|PCCOM_NOUNARY
value|(-2)+
end_define

begin_define
define|#
directive|define
name|PCCM_TRIPLE
parameter_list|(
name|op
parameter_list|,
name|var
parameter_list|,
name|type
parameter_list|)
define|\
value|((op) | ((var)<< 8) | (long) (type)<< 16)
end_define

begin_define
define|#
directive|define
name|PCCM_TEXT
parameter_list|(
name|s
parameter_list|)
define|\
value|PCCM_TRIPLE(PCCF_FTEXT, (strlen(s) + 3) / 4, 0)
end_define

begin_define
define|#
directive|define
name|PCCM_ADDTYPE
parameter_list|(
name|t
parameter_list|,
name|m
parameter_list|)
define|\
value|((((t)&~ PCCTM_BASETYPE)<< PCCTM_TYPESHIFT) | \ 	(m) | ((t)& PCCTM_BASETYPE))
end_define

end_unit

