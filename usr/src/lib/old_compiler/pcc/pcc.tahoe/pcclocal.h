begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|TOKENS
end_ifndef

begin_define
define|#
directive|define
name|TOKENS
value|0
end_define

begin_define
define|#
directive|define
name|ERROR
value|1
end_define

begin_comment
comment|/* an error node */
end_comment

begin_define
define|#
directive|define
name|FREE
value|2
end_define

begin_comment
comment|/* an unused node */
end_comment

begin_define
define|#
directive|define
name|STRING
value|3
end_define

begin_comment
comment|/* a string constant */
end_comment

begin_define
define|#
directive|define
name|ICON
value|4
end_define

begin_comment
comment|/* an integer constant */
end_comment

begin_define
define|#
directive|define
name|FCON
value|5
end_define

begin_comment
comment|/* a floating point constant */
end_comment

begin_define
define|#
directive|define
name|DCON
value|6
end_define

begin_comment
comment|/* a double precision f.p. constant */
end_comment

begin_define
define|#
directive|define
name|NAME
value|7
end_define

begin_comment
comment|/* an identifier */
end_comment

begin_define
define|#
directive|define
name|REG
value|8
end_define

begin_comment
comment|/* a register */
end_comment

begin_define
define|#
directive|define
name|OREG
value|9
end_define

begin_comment
comment|/* register and offset */
end_comment

begin_define
define|#
directive|define
name|CCODES
value|10
end_define

begin_comment
comment|/* condition codes */
end_comment

begin_define
define|#
directive|define
name|FLD
value|11
end_define

begin_comment
comment|/* a bit field */
end_comment

begin_define
define|#
directive|define
name|PLUS
value|12
end_define

begin_comment
comment|/* + */
end_comment

begin_define
define|#
directive|define
name|PLUSEQ
value|13
end_define

begin_comment
comment|/* += */
end_comment

begin_define
define|#
directive|define
name|UPLUS
value|14
end_define

begin_comment
comment|/* unary + (for completeness) */
end_comment

begin_define
define|#
directive|define
name|MINUS
value|15
end_define

begin_comment
comment|/* - */
end_comment

begin_define
define|#
directive|define
name|MINUSEQ
value|16
end_define

begin_comment
comment|/* -= */
end_comment

begin_define
define|#
directive|define
name|UMINUS
value|17
end_define

begin_comment
comment|/* unary - */
end_comment

begin_define
define|#
directive|define
name|MUL
value|18
end_define

begin_comment
comment|/* * */
end_comment

begin_define
define|#
directive|define
name|MULEQ
value|19
end_define

begin_comment
comment|/* *= */
end_comment

begin_define
define|#
directive|define
name|DIV
value|21
end_define

begin_comment
comment|/* / */
end_comment

begin_define
define|#
directive|define
name|DIVEQ
value|22
end_define

begin_comment
comment|/* /= */
end_comment

begin_define
define|#
directive|define
name|MOD
value|23
end_define

begin_comment
comment|/* % */
end_comment

begin_define
define|#
directive|define
name|MODEQ
value|24
end_define

begin_comment
comment|/* %= */
end_comment

begin_define
define|#
directive|define
name|INCR
value|25
end_define

begin_comment
comment|/* ++ */
end_comment

begin_define
define|#
directive|define
name|DECR
value|26
end_define

begin_comment
comment|/* -- */
end_comment

begin_define
define|#
directive|define
name|ASSIGN
value|27
end_define

begin_comment
comment|/* = (these last 3 are stretching it) */
end_comment

begin_define
define|#
directive|define
name|AND
value|28
end_define

begin_comment
comment|/*& */
end_comment

begin_define
define|#
directive|define
name|ANDEQ
value|29
end_define

begin_comment
comment|/*&= */
end_comment

begin_define
define|#
directive|define
name|OR
value|31
end_define

begin_comment
comment|/* | */
end_comment

begin_define
define|#
directive|define
name|OREQ
value|32
end_define

begin_comment
comment|/* |= */
end_comment

begin_define
define|#
directive|define
name|ER
value|33
end_define

begin_comment
comment|/* ^ */
end_comment

begin_define
define|#
directive|define
name|EREQ
value|34
end_define

begin_comment
comment|/* ^= */
end_comment

begin_define
define|#
directive|define
name|LS
value|35
end_define

begin_comment
comment|/*<< */
end_comment

begin_define
define|#
directive|define
name|LSEQ
value|36
end_define

begin_comment
comment|/*<<= */
end_comment

begin_define
define|#
directive|define
name|RS
value|37
end_define

begin_comment
comment|/*>> */
end_comment

begin_define
define|#
directive|define
name|RSEQ
value|38
end_define

begin_comment
comment|/*>>= */
end_comment

begin_define
define|#
directive|define
name|COMPL
value|39
end_define

begin_comment
comment|/* ~ */
end_comment

begin_define
define|#
directive|define
name|EQ
value|40
end_define

begin_comment
comment|/* == */
end_comment

begin_define
define|#
directive|define
name|NE
value|41
end_define

begin_comment
comment|/* != */
end_comment

begin_define
define|#
directive|define
name|LE
value|42
end_define

begin_comment
comment|/*<= */
end_comment

begin_define
define|#
directive|define
name|LT
value|43
end_define

begin_comment
comment|/*< */
end_comment

begin_define
define|#
directive|define
name|GE
value|44
end_define

begin_comment
comment|/*>= */
end_comment

begin_define
define|#
directive|define
name|GT
value|45
end_define

begin_comment
comment|/*> */
end_comment

begin_define
define|#
directive|define
name|ULE
value|46
end_define

begin_comment
comment|/* unsigned<= */
end_comment

begin_define
define|#
directive|define
name|ULT
value|47
end_define

begin_comment
comment|/* unsigned< */
end_comment

begin_define
define|#
directive|define
name|UGE
value|48
end_define

begin_comment
comment|/* unsigned>= */
end_comment

begin_define
define|#
directive|define
name|UGT
value|49
end_define

begin_comment
comment|/* unsigned> */
end_comment

begin_define
define|#
directive|define
name|QUEST
value|50
end_define

begin_comment
comment|/* ? (for conditional expressions) */
end_comment

begin_define
define|#
directive|define
name|COLON
value|51
end_define

begin_comment
comment|/* : (for conditional expressions) */
end_comment

begin_define
define|#
directive|define
name|ANDAND
value|52
end_define

begin_comment
comment|/*&& */
end_comment

begin_define
define|#
directive|define
name|OROR
value|53
end_define

begin_comment
comment|/* || */
end_comment

begin_define
define|#
directive|define
name|NOT
value|54
end_define

begin_comment
comment|/* ! */
end_comment

begin_define
define|#
directive|define
name|CALL
value|55
end_define

begin_comment
comment|/* call by value */
end_comment

begin_define
define|#
directive|define
name|UCALL
value|57
end_define

begin_comment
comment|/* call with no arguments */
end_comment

begin_define
define|#
directive|define
name|FORTCALL
value|58
end_define

begin_comment
comment|/* call by reference? */
end_comment

begin_define
define|#
directive|define
name|UFORTCALL
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
name|INLINE
value|61
end_define

begin_comment
comment|/* inline function */
end_comment

begin_define
define|#
directive|define
name|UINLINE
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

begin_define
define|#
directive|define
name|DEREF
value|20
end_define

begin_comment
comment|/* * */
end_comment

begin_define
define|#
directive|define
name|ADDROF
value|30
end_define

begin_comment
comment|/*& */
end_comment

begin_define
define|#
directive|define
name|DOT
value|64
end_define

begin_comment
comment|/* . */
end_comment

begin_define
define|#
directive|define
name|STREF
value|65
end_define

begin_comment
comment|/* -> */
end_comment

begin_define
define|#
directive|define
name|STASG
value|66
end_define

begin_comment
comment|/* structure assignment */
end_comment

begin_define
define|#
directive|define
name|STARG
value|67
end_define

begin_comment
comment|/* an argument of type structure */
end_comment

begin_define
define|#
directive|define
name|STCALL
value|68
end_define

begin_comment
comment|/* a function of type structure */
end_comment

begin_define
define|#
directive|define
name|USTCALL
value|70
end_define

begin_comment
comment|/* unary structure function */
end_comment

begin_define
define|#
directive|define
name|SCONV
value|71
end_define

begin_comment
comment|/* scalar conversion */
end_comment

begin_define
define|#
directive|define
name|PCONV
value|72
end_define

begin_comment
comment|/* pointer conversion */
end_comment

begin_define
define|#
directive|define
name|PMCONV
value|73
end_define

begin_comment
comment|/* pointer multiply conversion */
end_comment

begin_define
define|#
directive|define
name|PVCONV
value|74
end_define

begin_comment
comment|/* pointer divide conversion */
end_comment

begin_define
define|#
directive|define
name|CAST
value|75
end_define

begin_comment
comment|/* redundant? */
end_comment

begin_define
define|#
directive|define
name|LB
value|76
end_define

begin_comment
comment|/* [ */
end_comment

begin_define
define|#
directive|define
name|RB
value|77
end_define

begin_comment
comment|/* ] */
end_comment

begin_define
define|#
directive|define
name|COMOP
value|78
end_define

begin_comment
comment|/* , (in expressions) */
end_comment

begin_define
define|#
directive|define
name|CM
value|79
end_define

begin_comment
comment|/* , (in argument lists) */
end_comment

begin_define
define|#
directive|define
name|FORCE
value|80
end_define

begin_comment
comment|/* result of last expression goes in r0 */
end_comment

begin_define
define|#
directive|define
name|GOTO
value|81
end_define

begin_comment
comment|/* unconditional goto */
end_comment

begin_define
define|#
directive|define
name|CBRANCH
value|82
end_define

begin_comment
comment|/* goto label if !test */
end_comment

begin_define
define|#
directive|define
name|RETURN
value|83
end_define

begin_comment
comment|/* return from function */
end_comment

begin_define
define|#
directive|define
name|INIT
value|84
end_define

begin_comment
comment|/* initialized data */
end_comment

begin_define
define|#
directive|define
name|TYPE
value|85
end_define

begin_comment
comment|/* a type */
end_comment

begin_define
define|#
directive|define
name|CLASS
value|86
end_define

begin_comment
comment|/* a storage class */
end_comment

begin_define
define|#
directive|define
name|MAXOP
value|86
end_define

begin_comment
comment|/* highest numbered PCC op */
end_comment

begin_define
define|#
directive|define
name|FORTOPS
value|150
end_define

begin_define
define|#
directive|define
name|FTEXT
value|150
end_define

begin_comment
comment|/* pass literal assembler text */
end_comment

begin_define
define|#
directive|define
name|FEXPR
value|151
end_define

begin_comment
comment|/* a statement */
end_comment

begin_define
define|#
directive|define
name|FSWITCH
value|152
end_define

begin_comment
comment|/* not implemented */
end_comment

begin_define
define|#
directive|define
name|FLBRAC
value|153
end_define

begin_comment
comment|/* beginning of subroutine */
end_comment

begin_define
define|#
directive|define
name|FRBRAC
value|154
end_define

begin_comment
comment|/* end of subroutine */
end_comment

begin_define
define|#
directive|define
name|FEOF
value|155
end_define

begin_comment
comment|/* end of file */
end_comment

begin_define
define|#
directive|define
name|FARIF
value|156
end_define

begin_comment
comment|/* not implemented */
end_comment

begin_define
define|#
directive|define
name|FLABEL
value|157
end_define

begin_comment
comment|/* an f77 label */
end_comment

begin_endif
endif|#
directive|endif
endif|TOKENS
end_endif

begin_define
define|#
directive|define
name|UNDEF
value|0
end_define

begin_define
define|#
directive|define
name|FARG
value|1
end_define

begin_comment
comment|/* function argument */
end_comment

begin_define
define|#
directive|define
name|CHAR
value|2
end_define

begin_define
define|#
directive|define
name|SHORT
value|3
end_define

begin_define
define|#
directive|define
name|INT
value|4
end_define

begin_define
define|#
directive|define
name|LONG
value|5
end_define

begin_define
define|#
directive|define
name|FLOAT
value|6
end_define

begin_define
define|#
directive|define
name|DOUBLE
value|7
end_define

begin_define
define|#
directive|define
name|STRTY
value|8
end_define

begin_define
define|#
directive|define
name|UNIONTY
value|9
end_define

begin_define
define|#
directive|define
name|ENUMTY
value|10
end_define

begin_define
define|#
directive|define
name|MOETY
value|11
end_define

begin_comment
comment|/* member of enum */
end_comment

begin_define
define|#
directive|define
name|UCHAR
value|12
end_define

begin_define
define|#
directive|define
name|USHORT
value|13
end_define

begin_define
define|#
directive|define
name|UNSIGNED
value|14
end_define

begin_define
define|#
directive|define
name|ULONG
value|15
end_define

begin_define
define|#
directive|define
name|PTR
value|020
end_define

begin_define
define|#
directive|define
name|FTN
value|040
end_define

begin_define
define|#
directive|define
name|ARY
value|060
end_define

begin_define
define|#
directive|define
name|BASETYPE
value|017
end_define

begin_define
define|#
directive|define
name|TYPESHIFT
value|2
end_define

begin_define
define|#
directive|define
name|ASG
value|1+
end_define

begin_define
define|#
directive|define
name|UNARY
value|2+
end_define

begin_define
define|#
directive|define
name|NOASG
value|(-1)+
end_define

begin_define
define|#
directive|define
name|NOUNARY
value|(-2)+
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCALTOKENS
end_ifndef

begin_define
define|#
directive|define
name|LOCALTOKENS
value|100
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_PASS1_
end_ifdef

begin_define
define|#
directive|define
name|ASOP
value|100
end_define

begin_comment
comment|/* assignment ops */
end_comment

begin_define
define|#
directive|define
name|RELOP
value|101
end_define

begin_comment
comment|/*<=,<,>=,> */
end_comment

begin_define
define|#
directive|define
name|EQUOP
value|102
end_define

begin_comment
comment|/* ==, != */
end_comment

begin_define
define|#
directive|define
name|DIVOP
value|103
end_define

begin_comment
comment|/* /, % */
end_comment

begin_define
define|#
directive|define
name|SHIFTOP
value|104
end_define

begin_comment
comment|/*<<,>> */
end_comment

begin_define
define|#
directive|define
name|INCOP
value|105
end_define

begin_comment
comment|/* ++, -- */
end_comment

begin_define
define|#
directive|define
name|UNOP
value|106
end_define

begin_comment
comment|/* !, ~ */
end_comment

begin_define
define|#
directive|define
name|STROP
value|107
end_define

begin_comment
comment|/* ., -> */
end_comment

begin_define
define|#
directive|define
name|LP
value|108
end_define

begin_comment
comment|/* ( */
end_comment

begin_define
define|#
directive|define
name|RP
value|109
end_define

begin_comment
comment|/* ) */
end_comment

begin_define
define|#
directive|define
name|LC
value|110
end_define

begin_comment
comment|/* { */
end_comment

begin_define
define|#
directive|define
name|RC
value|111
end_define

begin_comment
comment|/* } */
end_comment

begin_endif
endif|#
directive|endif
endif|_PASS1_
end_endif

begin_define
define|#
directive|define
name|STRUCT
value|112
end_define

begin_define
define|#
directive|define
name|IF
value|113
end_define

begin_define
define|#
directive|define
name|ELSE
value|114
end_define

begin_define
define|#
directive|define
name|SWITCH
value|115
end_define

begin_define
define|#
directive|define
name|BREAK
value|116
end_define

begin_define
define|#
directive|define
name|CONTINUE
value|117
end_define

begin_define
define|#
directive|define
name|WHILE
value|118
end_define

begin_define
define|#
directive|define
name|DO
value|119
end_define

begin_define
define|#
directive|define
name|FOR
value|120
end_define

begin_define
define|#
directive|define
name|DEFAULT
value|121
end_define

begin_define
define|#
directive|define
name|CASE
value|122
end_define

begin_define
define|#
directive|define
name|SIZEOF
value|123
end_define

begin_define
define|#
directive|define
name|ENUM
value|124
end_define

begin_define
define|#
directive|define
name|SM
value|125
end_define

begin_endif
endif|#
directive|endif
endif|LOCALTOKENS
end_endif

end_unit

