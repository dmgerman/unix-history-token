begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	C pass 2 header  */
end_comment

begin_define
define|#
directive|define
name|swsiz
value|200
end_define

begin_define
define|#
directive|define
name|ossiz
value|500
end_define

begin_struct
struct|struct
name|tnode
block|{
name|int
name|op
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|degree
decl_stmt|;
name|struct
name|tnode
modifier|*
name|tr1
decl_stmt|,
modifier|*
name|tr2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bnode
block|{
name|int
name|bop
decl_stmt|;
name|struct
name|tnode
modifier|*
name|btree
decl_stmt|;
name|int
name|lbl
decl_stmt|;
name|int
name|cond
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tname
block|{
name|int
name|nop
decl_stmt|;
name|int
name|ntype
decl_stmt|;
name|int
name|elsize
decl_stmt|;
name|char
name|class
decl_stmt|;
name|char
name|regno
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|int
name|nloc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * for field selections  */
end_comment

begin_struct
struct|struct
name|tsel
block|{
name|int
name|op
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|degree
decl_stmt|;
name|struct
name|tnode
modifier|*
name|tr1
decl_stmt|;
name|char
name|flen
decl_stmt|;
name|char
name|bitoffs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tconst
block|{
name|int
name|cop
decl_stmt|;
name|int
name|ctype
decl_stmt|;
name|int
name|cdeg
decl_stmt|;
name|int
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|optab
block|{
name|char
name|tabdeg1
decl_stmt|;
name|char
name|tabtyp1
decl_stmt|;
name|char
name|tabdeg2
decl_stmt|;
name|char
name|tabtyp2
decl_stmt|;
name|char
modifier|*
name|tabstring
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|table
block|{
name|int
name|tabop
decl_stmt|;
name|struct
name|optab
modifier|*
name|tabp
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|instab
block|{
name|int
name|iop
decl_stmt|;
name|char
modifier|*
name|str1
decl_stmt|;
name|char
modifier|*
name|str2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|swtab
block|{
name|int
name|swlab
decl_stmt|;
name|int
name|swval
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|char
name|maprel
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|notrel
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nreg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|namsiz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|ascbuf
index|[
literal|518
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nerror
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|table
name|cctab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|table
name|efftab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|table
name|regtab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|table
name|sptab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|table
name|lsptab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|instab
name|instab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|instab
name|branchtab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|opdope
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|opntab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nstack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfloat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|spacep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|treespace
index|[
name|ossiz
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eolflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tconst
name|czero
decl_stmt|,
name|cone
decl_stmt|,
name|fczero
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 	operators */
end_comment

begin_define
define|#
directive|define
name|EOF
value|0
end_define

begin_define
define|#
directive|define
name|SEMI
value|1
end_define

begin_define
define|#
directive|define
name|LBRACE
value|2
end_define

begin_define
define|#
directive|define
name|RBRACE
value|3
end_define

begin_define
define|#
directive|define
name|LBRACK
value|4
end_define

begin_define
define|#
directive|define
name|RBRACK
value|5
end_define

begin_define
define|#
directive|define
name|LPARN
value|6
end_define

begin_define
define|#
directive|define
name|RPARN
value|7
end_define

begin_define
define|#
directive|define
name|COLON
value|8
end_define

begin_define
define|#
directive|define
name|COMMA
value|9
end_define

begin_define
define|#
directive|define
name|FSEL
value|10
end_define

begin_define
define|#
directive|define
name|KEYW
value|19
end_define

begin_define
define|#
directive|define
name|NAME
value|20
end_define

begin_define
define|#
directive|define
name|CON
value|21
end_define

begin_define
define|#
directive|define
name|STRING
value|22
end_define

begin_define
define|#
directive|define
name|FCON
value|23
end_define

begin_define
define|#
directive|define
name|SFCON
value|24
end_define

begin_define
define|#
directive|define
name|AUTOI
value|27
end_define

begin_define
define|#
directive|define
name|AUTOD
value|28
end_define

begin_define
define|#
directive|define
name|INCBEF
value|30
end_define

begin_define
define|#
directive|define
name|DECBEF
value|31
end_define

begin_define
define|#
directive|define
name|INCAFT
value|32
end_define

begin_define
define|#
directive|define
name|DECAFT
value|33
end_define

begin_define
define|#
directive|define
name|EXCLA
value|34
end_define

begin_define
define|#
directive|define
name|AMPER
value|35
end_define

begin_define
define|#
directive|define
name|STAR
value|36
end_define

begin_define
define|#
directive|define
name|NEG
value|37
end_define

begin_define
define|#
directive|define
name|COMPL
value|38
end_define

begin_define
define|#
directive|define
name|DOT
value|39
end_define

begin_define
define|#
directive|define
name|PLUS
value|40
end_define

begin_define
define|#
directive|define
name|MINUS
value|41
end_define

begin_define
define|#
directive|define
name|TIMES
value|42
end_define

begin_define
define|#
directive|define
name|DIVIDE
value|43
end_define

begin_define
define|#
directive|define
name|MOD
value|44
end_define

begin_define
define|#
directive|define
name|RSHIFT
value|45
end_define

begin_define
define|#
directive|define
name|LSHIFT
value|46
end_define

begin_define
define|#
directive|define
name|AND
value|47
end_define

begin_define
define|#
directive|define
name|NAND
value|55
end_define

begin_define
define|#
directive|define
name|OR
value|48
end_define

begin_define
define|#
directive|define
name|EXOR
value|49
end_define

begin_define
define|#
directive|define
name|ARROW
value|50
end_define

begin_define
define|#
directive|define
name|ITOF
value|51
end_define

begin_define
define|#
directive|define
name|FTOI
value|52
end_define

begin_define
define|#
directive|define
name|LOGAND
value|53
end_define

begin_define
define|#
directive|define
name|LOGOR
value|54
end_define

begin_define
define|#
directive|define
name|FTOL
value|56
end_define

begin_define
define|#
directive|define
name|LTOF
value|57
end_define

begin_define
define|#
directive|define
name|ITOL
value|58
end_define

begin_define
define|#
directive|define
name|LTOI
value|59
end_define

begin_define
define|#
directive|define
name|EQUAL
value|60
end_define

begin_define
define|#
directive|define
name|NEQUAL
value|61
end_define

begin_define
define|#
directive|define
name|LESSEQ
value|62
end_define

begin_define
define|#
directive|define
name|LESS
value|63
end_define

begin_define
define|#
directive|define
name|GREATEQ
value|64
end_define

begin_define
define|#
directive|define
name|GREAT
value|65
end_define

begin_define
define|#
directive|define
name|LESSEQP
value|66
end_define

begin_define
define|#
directive|define
name|LESSP
value|67
end_define

begin_define
define|#
directive|define
name|GREATQP
value|68
end_define

begin_define
define|#
directive|define
name|GREATP
value|69
end_define

begin_define
define|#
directive|define
name|ASPLUS
value|70
end_define

begin_define
define|#
directive|define
name|ASMINUS
value|71
end_define

begin_define
define|#
directive|define
name|ASTIMES
value|72
end_define

begin_define
define|#
directive|define
name|ASDIV
value|73
end_define

begin_define
define|#
directive|define
name|ASMOD
value|74
end_define

begin_define
define|#
directive|define
name|ASRSH
value|75
end_define

begin_define
define|#
directive|define
name|ASLSH
value|76
end_define

begin_define
define|#
directive|define
name|ASSAND
value|77
end_define

begin_define
define|#
directive|define
name|ASOR
value|78
end_define

begin_define
define|#
directive|define
name|ASXOR
value|79
end_define

begin_define
define|#
directive|define
name|ASSIGN
value|80
end_define

begin_define
define|#
directive|define
name|TAND
value|81
end_define

begin_define
define|#
directive|define
name|LTIMES
value|82
end_define

begin_define
define|#
directive|define
name|LDIV
value|83
end_define

begin_define
define|#
directive|define
name|LMOD
value|84
end_define

begin_define
define|#
directive|define
name|ASSNAND
value|85
end_define

begin_define
define|#
directive|define
name|LASTIMES
value|86
end_define

begin_define
define|#
directive|define
name|LASDIV
value|87
end_define

begin_define
define|#
directive|define
name|LASMOD
value|88
end_define

begin_define
define|#
directive|define
name|QUEST
value|90
end_define

begin_define
define|#
directive|define
name|LLSHIFT
value|91
end_define

begin_define
define|#
directive|define
name|ASLSHL
value|92
end_define

begin_define
define|#
directive|define
name|CALL1
value|98
end_define

begin_define
define|#
directive|define
name|CALL2
value|99
end_define

begin_define
define|#
directive|define
name|CALL
value|100
end_define

begin_define
define|#
directive|define
name|MCALL
value|101
end_define

begin_define
define|#
directive|define
name|JUMP
value|102
end_define

begin_define
define|#
directive|define
name|CBRANCH
value|103
end_define

begin_define
define|#
directive|define
name|INIT
value|104
end_define

begin_define
define|#
directive|define
name|SETREG
value|105
end_define

begin_define
define|#
directive|define
name|LOAD
value|106
end_define

begin_define
define|#
directive|define
name|RFORCE
value|110
end_define

begin_comment
comment|/*  * Intermediate code operators  */
end_comment

begin_define
define|#
directive|define
name|BRANCH
value|111
end_define

begin_define
define|#
directive|define
name|LABEL
value|112
end_define

begin_define
define|#
directive|define
name|NLABEL
value|113
end_define

begin_define
define|#
directive|define
name|RLABEL
value|114
end_define

begin_define
define|#
directive|define
name|BDATA
value|200
end_define

begin_define
define|#
directive|define
name|WDATA
value|201
end_define

begin_define
define|#
directive|define
name|PROG
value|202
end_define

begin_define
define|#
directive|define
name|DATA
value|203
end_define

begin_define
define|#
directive|define
name|BSS
value|204
end_define

begin_define
define|#
directive|define
name|CSPACE
value|205
end_define

begin_define
define|#
directive|define
name|SSPACE
value|206
end_define

begin_define
define|#
directive|define
name|SYMDEF
value|207
end_define

begin_define
define|#
directive|define
name|SAVE
value|208
end_define

begin_define
define|#
directive|define
name|RETRN
value|209
end_define

begin_define
define|#
directive|define
name|EVEN
value|210
end_define

begin_define
define|#
directive|define
name|PROFIL
value|212
end_define

begin_define
define|#
directive|define
name|SWIT
value|213
end_define

begin_define
define|#
directive|define
name|EXPR
value|214
end_define

begin_define
define|#
directive|define
name|SNAME
value|215
end_define

begin_define
define|#
directive|define
name|RNAME
value|216
end_define

begin_define
define|#
directive|define
name|ANAME
value|217
end_define

begin_define
define|#
directive|define
name|NULL
value|218
end_define

begin_comment
comment|/*  *	types  */
end_comment

begin_define
define|#
directive|define
name|INT
value|0
end_define

begin_define
define|#
directive|define
name|CHAR
value|1
end_define

begin_define
define|#
directive|define
name|FLOAT
value|2
end_define

begin_define
define|#
directive|define
name|DOUBLE
value|3
end_define

begin_define
define|#
directive|define
name|STRUCT
value|4
end_define

begin_define
define|#
directive|define
name|RSTRUCT
value|5
end_define

begin_define
define|#
directive|define
name|LONG
value|6
end_define

begin_define
define|#
directive|define
name|TYLEN
value|2
end_define

begin_define
define|#
directive|define
name|TYPE
value|07
end_define

begin_define
define|#
directive|define
name|XTYPE
value|(03<<3)
end_define

begin_define
define|#
directive|define
name|PTR
value|010
end_define

begin_define
define|#
directive|define
name|FUNC
value|020
end_define

begin_define
define|#
directive|define
name|ARRAY
value|030
end_define

begin_comment
comment|/* 	storage	classes */
end_comment

begin_define
define|#
directive|define
name|KEYWC
value|1
end_define

begin_define
define|#
directive|define
name|MOS
value|10
end_define

begin_define
define|#
directive|define
name|AUTO
value|11
end_define

begin_define
define|#
directive|define
name|EXTERN
value|12
end_define

begin_define
define|#
directive|define
name|STATIC
value|13
end_define

begin_define
define|#
directive|define
name|REG
value|14
end_define

begin_define
define|#
directive|define
name|STRTAG
value|15
end_define

begin_define
define|#
directive|define
name|ARG
value|16
end_define

begin_define
define|#
directive|define
name|OFFS
value|20
end_define

begin_define
define|#
directive|define
name|XOFFS
value|21
end_define

begin_define
define|#
directive|define
name|SOFFS
value|22
end_define

begin_comment
comment|/* 	Flag	bits */
end_comment

begin_define
define|#
directive|define
name|BINARY
value|01
end_define

begin_define
define|#
directive|define
name|LVALUE
value|02
end_define

begin_define
define|#
directive|define
name|RELAT
value|04
end_define

begin_define
define|#
directive|define
name|ASSGOP
value|010
end_define

begin_define
define|#
directive|define
name|LWORD
value|020
end_define

begin_define
define|#
directive|define
name|RWORD
value|040
end_define

begin_define
define|#
directive|define
name|COMMUTE
value|0100
end_define

begin_define
define|#
directive|define
name|RASSOC
value|0200
end_define

begin_define
define|#
directive|define
name|LEAF
value|0400
end_define

begin_define
define|#
directive|define
name|CNVRT
value|01000
end_define

end_unit

