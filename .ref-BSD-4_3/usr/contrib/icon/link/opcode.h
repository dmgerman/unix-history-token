begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Opcode table structure.  */
end_comment

begin_struct
struct|struct
name|opentry
block|{
name|char
modifier|*
name|op_name
decl_stmt|;
comment|/* name of opcode */
name|int
name|op_code
decl_stmt|;
comment|/* opcode number */
block|}
struct|;
end_struct

begin_comment
comment|/*  * External definitions.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|opentry
name|optable
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|NOPCODES
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Opcode definitions used in icode.  These values must agree with those  *  used in iconx/interp.s.  */
end_comment

begin_comment
comment|/* Operators. */
end_comment

begin_define
define|#
directive|define
name|OP_ASGN
value|1
end_define

begin_define
define|#
directive|define
name|OP_BANG
value|2
end_define

begin_define
define|#
directive|define
name|OP_CAT
value|3
end_define

begin_define
define|#
directive|define
name|OP_COMPL
value|4
end_define

begin_define
define|#
directive|define
name|OP_DIFF
value|5
end_define

begin_define
define|#
directive|define
name|OP_DIV
value|6
end_define

begin_define
define|#
directive|define
name|OP_EQV
value|7
end_define

begin_define
define|#
directive|define
name|OP_INTER
value|8
end_define

begin_define
define|#
directive|define
name|OP_LCONCAT
value|9
end_define

begin_define
define|#
directive|define
name|OP_LEXEQ
value|10
end_define

begin_define
define|#
directive|define
name|OP_LEXGE
value|11
end_define

begin_define
define|#
directive|define
name|OP_LEXGT
value|12
end_define

begin_define
define|#
directive|define
name|OP_LEXLE
value|13
end_define

begin_define
define|#
directive|define
name|OP_LEXLT
value|14
end_define

begin_define
define|#
directive|define
name|OP_LEXNE
value|15
end_define

begin_define
define|#
directive|define
name|OP_MINUS
value|16
end_define

begin_define
define|#
directive|define
name|OP_MOD
value|17
end_define

begin_define
define|#
directive|define
name|OP_MULT
value|18
end_define

begin_define
define|#
directive|define
name|OP_NEG
value|19
end_define

begin_define
define|#
directive|define
name|OP_NEQV
value|20
end_define

begin_define
define|#
directive|define
name|OP_NONNULL
value|21
end_define

begin_define
define|#
directive|define
name|OP_NULL
value|22
end_define

begin_define
define|#
directive|define
name|OP_NUMBER
value|23
end_define

begin_define
define|#
directive|define
name|OP_NUMEQ
value|24
end_define

begin_define
define|#
directive|define
name|OP_NUMGE
value|25
end_define

begin_define
define|#
directive|define
name|OP_NUMGT
value|26
end_define

begin_define
define|#
directive|define
name|OP_NUMLE
value|27
end_define

begin_define
define|#
directive|define
name|OP_NUMLT
value|28
end_define

begin_define
define|#
directive|define
name|OP_NUMNE
value|29
end_define

begin_define
define|#
directive|define
name|OP_PLUS
value|30
end_define

begin_define
define|#
directive|define
name|OP_POWER
value|31
end_define

begin_define
define|#
directive|define
name|OP_RANDOM
value|32
end_define

begin_define
define|#
directive|define
name|OP_RASGN
value|33
end_define

begin_define
define|#
directive|define
name|OP_REFRESH
value|34
end_define

begin_define
define|#
directive|define
name|OP_RSWAP
value|35
end_define

begin_define
define|#
directive|define
name|OP_SECT
value|36
end_define

begin_define
define|#
directive|define
name|OP_SIZE
value|37
end_define

begin_define
define|#
directive|define
name|OP_SUBSC
value|38
end_define

begin_define
define|#
directive|define
name|OP_SWAP
value|39
end_define

begin_define
define|#
directive|define
name|OP_TABMAT
value|40
end_define

begin_define
define|#
directive|define
name|OP_TOBY
value|41
end_define

begin_define
define|#
directive|define
name|OP_UNIONCS
value|42
end_define

begin_define
define|#
directive|define
name|OP_VALUE
value|43
end_define

begin_comment
comment|/* Instructions. */
end_comment

begin_define
define|#
directive|define
name|OP_BSCAN
value|44
end_define

begin_define
define|#
directive|define
name|OP_CCASE
value|45
end_define

begin_define
define|#
directive|define
name|OP_CHFAIL
value|46
end_define

begin_define
define|#
directive|define
name|OP_COACT
value|47
end_define

begin_define
define|#
directive|define
name|OP_COFAIL
value|48
end_define

begin_define
define|#
directive|define
name|OP_CORET
value|49
end_define

begin_define
define|#
directive|define
name|OP_CREATE
value|50
end_define

begin_define
define|#
directive|define
name|OP_CSET
value|51
end_define

begin_define
define|#
directive|define
name|OP_DUP
value|52
end_define

begin_define
define|#
directive|define
name|OP_EFAIL
value|53
end_define

begin_define
define|#
directive|define
name|OP_ERET
value|54
end_define

begin_define
define|#
directive|define
name|OP_ESCAN
value|55
end_define

begin_define
define|#
directive|define
name|OP_ESUSP
value|56
end_define

begin_define
define|#
directive|define
name|OP_FIELD
value|57
end_define

begin_define
define|#
directive|define
name|OP_FILE
value|58
end_define

begin_define
define|#
directive|define
name|OP_GOTO
value|59
end_define

begin_define
define|#
directive|define
name|OP_INCRES
value|60
end_define

begin_define
define|#
directive|define
name|OP_INIT
value|61
end_define

begin_define
define|#
directive|define
name|OP_INT
value|62
end_define

begin_define
define|#
directive|define
name|OP_INVOKE
value|63
end_define

begin_define
define|#
directive|define
name|OP_KEYWD
value|64
end_define

begin_define
define|#
directive|define
name|OP_LAB
value|65
end_define

begin_define
define|#
directive|define
name|OP_LIMIT
value|66
end_define

begin_define
define|#
directive|define
name|OP_LINE
value|67
end_define

begin_define
define|#
directive|define
name|OP_LLIST
value|68
end_define

begin_define
define|#
directive|define
name|OP_LSUSP
value|69
end_define

begin_define
define|#
directive|define
name|OP_MARK
value|70
end_define

begin_define
define|#
directive|define
name|OP_PFAIL
value|71
end_define

begin_define
define|#
directive|define
name|OP_PNULL
value|72
end_define

begin_define
define|#
directive|define
name|OP_POP
value|73
end_define

begin_define
define|#
directive|define
name|OP_PRET
value|74
end_define

begin_define
define|#
directive|define
name|OP_PSUSP
value|75
end_define

begin_define
define|#
directive|define
name|OP_PUSH1
value|76
end_define

begin_define
define|#
directive|define
name|OP_PUSHN1
value|77
end_define

begin_define
define|#
directive|define
name|OP_REAL
value|78
end_define

begin_define
define|#
directive|define
name|OP_SDUP
value|79
end_define

begin_define
define|#
directive|define
name|OP_STR
value|80
end_define

begin_define
define|#
directive|define
name|OP_UNMARK
value|81
end_define

begin_define
define|#
directive|define
name|OP_VAR
value|82
end_define

begin_comment
comment|/* Declarations. */
end_comment

begin_define
define|#
directive|define
name|OP_PROC
value|83
end_define

begin_define
define|#
directive|define
name|OP_LOCAL
value|84
end_define

begin_define
define|#
directive|define
name|OP_CON
value|85
end_define

begin_define
define|#
directive|define
name|OP_DECLEND
value|86
end_define

begin_define
define|#
directive|define
name|OP_END
value|87
end_define

begin_comment
comment|/* See below for OP_LINK. */
end_comment

begin_comment
comment|/* Global symbol table declarations. */
end_comment

begin_define
define|#
directive|define
name|OP_RECORD
value|88
end_define

begin_define
define|#
directive|define
name|OP_IMPL
value|89
end_define

begin_define
define|#
directive|define
name|OP_ERROR
value|90
end_define

begin_define
define|#
directive|define
name|OP_TRACE
value|91
end_define

begin_define
define|#
directive|define
name|OP_GLOBAL
value|92
end_define

begin_comment
comment|/* Interpreter instructions not defined above. */
end_comment

begin_define
define|#
directive|define
name|OP_ARG
value|93
end_define

begin_define
define|#
directive|define
name|OP_STATIC
value|94
end_define

begin_define
define|#
directive|define
name|OP_MARK0
value|95
end_define

begin_define
define|#
directive|define
name|OP_LINK
value|96
end_define

begin_comment
comment|/*  * The following opcodes cannot be renumbered easily, for example, the  *  interpreter assumes that OP_GLOBX is a multiple of 16.  */
end_comment

begin_define
define|#
directive|define
name|OP_GLOBX
value|112
end_define

begin_comment
comment|/* 16 opcodes */
end_comment

begin_define
define|#
directive|define
name|OP_LOCX
value|128
end_define

begin_comment
comment|/* 16 opcodes */
end_comment

begin_define
define|#
directive|define
name|OP_INTX
value|144
end_define

begin_comment
comment|/* 16 opcodes */
end_comment

begin_define
define|#
directive|define
name|OP_STATX
value|160
end_define

begin_comment
comment|/*  8 opcodes */
end_comment

begin_define
define|#
directive|define
name|OP_ARGX
value|168
end_define

begin_comment
comment|/*  8 opcodes */
end_comment

begin_define
define|#
directive|define
name|OP_UNMKX
value|176
end_define

begin_comment
comment|/*  8 opcodes */
end_comment

begin_define
define|#
directive|define
name|OP_INVKX
value|184
end_define

begin_comment
comment|/*  8 opcodes */
end_comment

begin_define
define|#
directive|define
name|OP_LINEX
value|192
end_define

begin_comment
comment|/* 64 opcodes */
end_comment

end_unit

