begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/* %Z%%M% %R%.%L% %D% %T% */
end_comment

begin_define
define|#
directive|define
name|readonly
end_define

begin_define
define|#
directive|define
name|NINST
value|300
end_define

begin_define
define|#
directive|define
name|NSYM
value|3000
end_define

begin_define
define|#
directive|define
name|NHASH
value|(NSYM+1)
end_define

begin_define
define|#
directive|define
name|NLOC
value|4
end_define

begin_comment
comment|/* number of location ctrs */
end_comment

begin_define
define|#
directive|define
name|NCPS
value|8
end_define

begin_comment
comment|/*  * Symbol types  */
end_comment

begin_define
define|#
directive|define
name|XUNDEF
value|0x0
end_define

begin_define
define|#
directive|define
name|XABS
value|0x2
end_define

begin_define
define|#
directive|define
name|XTEXT
value|0x4
end_define

begin_define
define|#
directive|define
name|XDATA
value|0x6
end_define

begin_define
define|#
directive|define
name|XBSS
value|0x8
end_define

begin_define
define|#
directive|define
name|XDATAO
value|0xA
end_define

begin_define
define|#
directive|define
name|XBSSO
value|0xC
end_define

begin_define
define|#
directive|define
name|XTEXTO
value|0xE
end_define

begin_define
define|#
directive|define
name|XABSO
value|0x10
end_define

begin_define
define|#
directive|define
name|XUNDEFO
value|0x12
end_define

begin_define
define|#
directive|define
name|XTXRN
value|0xA
end_define

begin_define
define|#
directive|define
name|XXTRN
value|0x1
end_define

begin_define
define|#
directive|define
name|XTYPE
value|0x1E
end_define

begin_define
define|#
directive|define
name|XFORW
value|0x20
end_define

begin_comment
comment|/* Was forward-referenced when undefined */
end_comment

begin_define
define|#
directive|define
name|ERR
value|(-1)
end_define

begin_define
define|#
directive|define
name|NBPW
value|32
end_define

begin_define
define|#
directive|define
name|AMASK
value|017
end_define

begin_comment
comment|/*  * Actual argument syntax types  */
end_comment

begin_define
define|#
directive|define
name|AREG
value|1
end_define

begin_comment
comment|/* %r */
end_comment

begin_define
define|#
directive|define
name|ABASE
value|2
end_define

begin_comment
comment|/* (%r) */
end_comment

begin_define
define|#
directive|define
name|ADECR
value|3
end_define

begin_comment
comment|/* -(%r) */
end_comment

begin_define
define|#
directive|define
name|AINCR
value|4
end_define

begin_comment
comment|/* (%r)+ */
end_comment

begin_define
define|#
directive|define
name|ADISP
value|5
end_define

begin_comment
comment|/* expr(%r) */
end_comment

begin_define
define|#
directive|define
name|AEXP
value|6
end_define

begin_comment
comment|/* expr */
end_comment

begin_define
define|#
directive|define
name|AIMM
value|7
end_define

begin_comment
comment|/* $ expr */
end_comment

begin_define
define|#
directive|define
name|ASTAR
value|8
end_define

begin_comment
comment|/* * */
end_comment

begin_define
define|#
directive|define
name|AINDX
value|16
end_define

begin_comment
comment|/* [%r] */
end_comment

begin_comment
comment|/*  * Argument access types  */
end_comment

begin_define
define|#
directive|define
name|ACCA
value|(8<<3)
end_define

begin_comment
comment|/* address only */
end_comment

begin_define
define|#
directive|define
name|ACCR
value|(1<<3)
end_define

begin_comment
comment|/* read */
end_comment

begin_define
define|#
directive|define
name|ACCW
value|(2<<3)
end_define

begin_comment
comment|/* write */
end_comment

begin_define
define|#
directive|define
name|ACCM
value|(3<<3)
end_define

begin_comment
comment|/* modify */
end_comment

begin_define
define|#
directive|define
name|ACCB
value|(4<<3)
end_define

begin_comment
comment|/* branch displacement */
end_comment

begin_define
define|#
directive|define
name|ACCI
value|(5<<3)
end_define

begin_comment
comment|/* XFC code */
end_comment

begin_comment
comment|/*  * Argument data types  */
end_comment

begin_define
define|#
directive|define
name|TYPB
value|0
end_define

begin_comment
comment|/* byte */
end_comment

begin_define
define|#
directive|define
name|TYPW
value|1
end_define

begin_comment
comment|/* word */
end_comment

begin_define
define|#
directive|define
name|TYPL
value|2
end_define

begin_comment
comment|/* long */
end_comment

begin_define
define|#
directive|define
name|TYPQ
value|3
end_define

begin_comment
comment|/* quad */
end_comment

begin_define
define|#
directive|define
name|TYPF
value|4
end_define

begin_comment
comment|/* floating */
end_comment

begin_define
define|#
directive|define
name|TYPD
value|5
end_define

begin_comment
comment|/* double floating */
end_comment

begin_define
define|#
directive|define
name|TYPMASK
value|7
end_define

begin_comment
comment|/* reference types for loader */
end_comment

begin_define
define|#
directive|define
name|PCREL
value|1
end_define

begin_define
define|#
directive|define
name|LEN1
value|2
end_define

begin_define
define|#
directive|define
name|LEN2
value|4
end_define

begin_define
define|#
directive|define
name|LEN4
value|6
end_define

begin_define
define|#
directive|define
name|LEN8
value|8
end_define

begin_define
define|#
directive|define
name|TMPC
value|7
end_define

begin_define
define|#
directive|define
name|HW
value|01
end_define

begin_define
define|#
directive|define
name|FW
value|03
end_define

begin_define
define|#
directive|define
name|DW
value|07
end_define

begin_define
define|#
directive|define
name|PAGRND
value|0x1FFL
end_define

begin_define
define|#
directive|define
name|round
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)+(y))& ~(y))
end_define

begin_define
define|#
directive|define
name|STABTYPS
value|0340
end_define

begin_struct
struct|struct
name|symtab
block|{
name|char
name|name
index|[
name|NCPS
index|]
decl_stmt|;
name|char
name|type
decl_stmt|;
name|char
name|tag
decl_stmt|;
name|short
name|index
decl_stmt|;
name|long
name|value
decl_stmt|;
name|char
name|ptype
decl_stmt|;
name|char
name|other
decl_stmt|;
name|short
name|desc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|instab
block|{
name|char
name|name
index|[
name|NCPS
index|]
decl_stmt|;
name|char
name|opcode
decl_stmt|;
comment|/* must have same offset as symtab.type */
name|char
name|tag
decl_stmt|;
comment|/* yacc-coded nargs (INST0, ...) or token # (IALIGN, ...) */
name|char
name|nargs
decl_stmt|;
name|char
name|argtyp
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|arg
block|{
name|char
name|atype
decl_stmt|;
name|char
name|areg1
decl_stmt|;
name|char
name|areg2
decl_stmt|;
name|struct
name|exp
modifier|*
name|xp
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|exp
block|{
name|char
name|xtype
decl_stmt|;
name|char
name|xloc
decl_stmt|;
name|long
name|xvalue
decl_stmt|;
name|long
name|yvalue
decl_stmt|;
comment|/* 2nd half of double floating */
name|struct
name|symtab
modifier|*
name|xname
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hdr
block|{
name|long
name|magic
decl_stmt|;
name|long
name|tsize
decl_stmt|;
name|long
name|dsize
decl_stmt|;
name|long
name|bsize
decl_stmt|;
name|long
name|ssize
decl_stmt|;
name|long
name|entry
decl_stmt|;
name|long
name|trsize
decl_stmt|;
name|long
name|drsize
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|symtab
modifier|*
name|symtab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|symtab
modifier|*
name|hshtab
index|[
name|NHASH
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|arg
name|arglist
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|exp
name|explist
index|[
literal|20
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hshused
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|usrname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lclname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symtab
modifier|*
name|nextsym
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|exp
name|usedot
index|[
name|NLOC
operator|+
name|NLOC
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|usefile
index|[
name|NLOC
operator|+
name|NLOC
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|rusefile
index|[
name|NLOC
operator|+
name|NLOC
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tmpn2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tmpn3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|exp
modifier|*
name|dotp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|loctr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|tsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|dsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|datbase
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bitoff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|bitfield
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|yytext
index|[
name|NCPS
operator|+
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|txtfil
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|tmpfil
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|relfil
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|passno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|argcnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|anyerrs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|brptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|instab
modifier|*
name|itab
index|[
name|NINST
index|]
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
name|int
name|curlen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gindex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|orgwarn
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|symtab
modifier|*
modifier|*
name|lookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|exp
modifier|*
name|combine
parameter_list|()
function_decl|;
end_function_decl

end_unit

