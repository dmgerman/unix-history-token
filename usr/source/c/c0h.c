begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/*  	C compiler-- pass 1 header   */
end_comment

begin_comment
comment|/*   parameters */
end_comment

begin_define
define|#
directive|define
name|ncps
value|8
end_define

begin_define
define|#
directive|define
name|hshsiz
value|200
end_define

begin_define
define|#
directive|define
name|cmsiz
value|40
end_define

begin_define
define|#
directive|define
name|swsiz
value|200
end_define

begin_define
define|#
directive|define
name|OSSIZ
value|500
end_define

begin_define
define|#
directive|define
name|dimsiz
value|100
end_define

begin_define
define|#
directive|define
name|NBPW
value|16
end_define

begin_define
define|#
directive|define
name|NBPC
value|8
end_define

begin_define
define|#
directive|define
name|NCPW
value|2
end_define

begin_define
define|#
directive|define
name|STRSIZ
value|256
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
name|dimp
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
block|{
name|int
name|op
decl_stmt|;
name|int
name|type
decl_stmt|;
name|char
name|ssp
decl_stmt|;
comment|/* subscript list */
name|char
name|lenp
decl_stmt|;
comment|/* structure length */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tname
block|{
name|int
name|op
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|dimp
decl_stmt|;
name|int
name|class
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

begin_struct
struct|struct
name|txname
block|{
name|int
name|op
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|dimp
decl_stmt|;
name|int
name|class
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|char
name|nname
index|[
name|ncps
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tconst
block|{
name|int
name|op
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|dimp
decl_stmt|;
name|int
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hshtab
block|{
name|char
name|hclass
decl_stmt|;
name|char
name|hflag
decl_stmt|;
name|int
name|htype
decl_stmt|;
name|int
name|hdimp
decl_stmt|;
name|int
name|hoffset
decl_stmt|;
name|char
name|name
index|[
name|ncps
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
block|{
name|char
name|hclass
decl_stmt|;
name|char
name|hflag
decl_stmt|;
name|int
name|htype
decl_stmt|;
name|char
name|flen
decl_stmt|;
comment|/* Field length */
name|char
name|bitoffs
decl_stmt|;
comment|/* Offset of field */
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

begin_decl_stmt
name|char
name|cvtab
index|[
literal|4
index|]
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|savstr
index|[
name|STRSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|strptr
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
name|ctab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|symbuf
index|[
name|ncps
operator|+
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hshused
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|hshtab
name|hshtab
index|[
name|hshsiz
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|space
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|cp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cmst
index|[
name|cmsiz
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|swtab
name|swtab
index|[
name|swsiz
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|swtab
modifier|*
name|swp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|contlab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|brklab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|retlab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|deflab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nauto
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|autolen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|peeksym
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|peekc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eof
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|osspace
index|[
name|OSSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|treespace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|hshtab
modifier|*
name|defsym
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|hshtab
modifier|*
name|funcsym
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xdflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|proflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|stflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|hshtab
modifier|*
name|csym
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|fcval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nchstr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nerror
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|hshtab
modifier|*
name|paraml
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|hshtab
modifier|*
name|parame
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|strflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mosflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|initflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|inhdr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dimtab
index|[
name|dimsiz
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|obuf
index|[
literal|518
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|sbuf
index|[
literal|518
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dimp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|regvar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bitoffs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tname
name|funcblk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   operators */
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
name|SIZEOF
value|91
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
name|QUEST
value|90
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
name|RFORCE
value|110
end_define

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

begin_comment
comment|/*   types */
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
name|NOTYPE
value|7
end_define

begin_comment
comment|/* used internally */
end_comment

begin_define
define|#
directive|define
name|ALIGN
value|01
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
name|TYLEN
value|2
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
comment|/*   storage classes */
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
name|ARG1
value|17
end_define

begin_define
define|#
directive|define
name|FMOS
value|18
end_define

begin_comment
comment|/*   keywords */
end_comment

begin_define
define|#
directive|define
name|GOTO
value|20
end_define

begin_define
define|#
directive|define
name|RETURN
value|21
end_define

begin_define
define|#
directive|define
name|IF
value|22
end_define

begin_define
define|#
directive|define
name|WHILE
value|23
end_define

begin_define
define|#
directive|define
name|ELSE
value|24
end_define

begin_define
define|#
directive|define
name|SWITCH
value|25
end_define

begin_define
define|#
directive|define
name|CASE
value|26
end_define

begin_define
define|#
directive|define
name|BREAK
value|27
end_define

begin_define
define|#
directive|define
name|CONTIN
value|28
end_define

begin_define
define|#
directive|define
name|DO
value|29
end_define

begin_define
define|#
directive|define
name|DEFAULT
value|30
end_define

begin_define
define|#
directive|define
name|FOR
value|31
end_define

begin_comment
comment|/*   characters */
end_comment

begin_define
define|#
directive|define
name|INSERT
value|119
end_define

begin_define
define|#
directive|define
name|PERIOD
value|120
end_define

begin_define
define|#
directive|define
name|SQUOTE
value|121
end_define

begin_define
define|#
directive|define
name|DQUOTE
value|122
end_define

begin_define
define|#
directive|define
name|LETTER
value|123
end_define

begin_define
define|#
directive|define
name|DIGIT
value|124
end_define

begin_define
define|#
directive|define
name|NEWLN
value|125
end_define

begin_define
define|#
directive|define
name|SPACE
value|126
end_define

begin_define
define|#
directive|define
name|UNKN
value|127
end_define

begin_comment
comment|/*  * Special operators in intermediate code  */
end_comment

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
comment|/*   Flag bits */
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

begin_comment
comment|/*  * Conversion codes  */
end_comment

begin_define
define|#
directive|define
name|ITF
value|1
end_define

begin_define
define|#
directive|define
name|ITL
value|2
end_define

begin_define
define|#
directive|define
name|LTF
value|3
end_define

begin_define
define|#
directive|define
name|ITP
value|4
end_define

begin_define
define|#
directive|define
name|PTI
value|5
end_define

begin_define
define|#
directive|define
name|FTI
value|6
end_define

begin_define
define|#
directive|define
name|LTI
value|7
end_define

begin_define
define|#
directive|define
name|FTL
value|8
end_define

begin_define
define|#
directive|define
name|XX
value|15
end_define

begin_comment
comment|/*  * symbol table flags  */
end_comment

begin_define
define|#
directive|define
name|FNDEL
value|01
end_define

begin_define
define|#
directive|define
name|FNUND
value|02
end_define

begin_define
define|#
directive|define
name|FKEYW
value|04
end_define

begin_define
define|#
directive|define
name|FFIELD
value|020
end_define

end_unit

