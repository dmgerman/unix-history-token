begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|double
modifier|*
name|test1
decl_stmt|;
end_decl_stmt

begin_function_decl
name|double
name|gamma
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  *  A P L  */
end_comment

begin_comment
comment|/*  *  Magic numbers  */
end_comment

begin_define
define|#
directive|define
name|OPERBOXSIZE
value|75
end_define

begin_define
define|#
directive|define
name|MRANK
value|8
end_define

begin_comment
comment|/* Size of dimension buffer	*/
end_comment

begin_define
define|#
directive|define
name|CANBS
value|300
end_define

begin_comment
comment|/* Size of input buffer		*/
end_comment

begin_define
define|#
directive|define
name|STKS
value|50
end_define

begin_comment
comment|/* Size of stack increment	*/
end_comment

begin_define
define|#
directive|define
name|NLS
value|100
end_define

begin_comment
comment|/* Size of namelist		*/
end_comment

begin_define
define|#
directive|define
name|NAMS
value|23
end_define

begin_comment
comment|/* Size of name buffer		*/
end_comment

begin_define
define|#
directive|define
name|OBJS
value|500
end_define

begin_comment
comment|/* Size of compiled expr buffer	*/
end_comment

begin_define
define|#
directive|define
name|MAGIC
value|0100554
end_define

begin_comment
comment|/* Magic word for WS file	*/
end_comment

begin_comment
comment|/*  *  Magic words  */
end_comment

begin_define
define|#
directive|define
name|EDIT_ED
value|"/usr/bin/ed"
end_define

begin_define
define|#
directive|define
name|EDIT_EX
value|"/usr/bin/ex"
end_define

begin_define
define|#
directive|define
name|EDIT_VI
value|"/usr/bin/vi"
end_define

begin_comment
comment|/*  *  Debug modes  */
end_comment

begin_define
define|#
directive|define
name|FULLD
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FULLD
end_ifdef

begin_define
define|#
directive|define
name|SOMED
value|SOMED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SHORTD
end_ifdef

begin_define
define|#
directive|define
name|SOMED
value|SOMED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *  Derived constants  */
end_comment

begin_define
define|#
directive|define
name|SDAT
value|sizeof datum
end_define

begin_define
define|#
directive|define
name|SINT
value|sizeof integ
end_define

begin_comment
comment|/*  *  Interpreter Op Codes  */
end_comment

begin_define
define|#
directive|define
name|EOF
value|(-1)
end_define

begin_define
define|#
directive|define
name|EOL
value|0
end_define

begin_define
define|#
directive|define
name|ADD
value|1
end_define

begin_define
define|#
directive|define
name|PLUS
value|2
end_define

begin_define
define|#
directive|define
name|SUB
value|3
end_define

begin_define
define|#
directive|define
name|MINUS
value|4
end_define

begin_define
define|#
directive|define
name|MUL
value|5
end_define

begin_define
define|#
directive|define
name|SGN
value|6
end_define

begin_define
define|#
directive|define
name|DIV
value|7
end_define

begin_define
define|#
directive|define
name|RECIP
value|8
end_define

begin_define
define|#
directive|define
name|MOD
value|9
end_define

begin_define
define|#
directive|define
name|ABS
value|10
end_define

begin_define
define|#
directive|define
name|MIN
value|11
end_define

begin_define
define|#
directive|define
name|FLOOR
value|12
end_define

begin_define
define|#
directive|define
name|MAX
value|13
end_define

begin_define
define|#
directive|define
name|CEIL
value|14
end_define

begin_define
define|#
directive|define
name|PWR
value|15
end_define

begin_define
define|#
directive|define
name|EXP
value|16
end_define

begin_define
define|#
directive|define
name|LOG
value|17
end_define

begin_define
define|#
directive|define
name|LOGE
value|18
end_define

begin_define
define|#
directive|define
name|CIR
value|19
end_define

begin_define
define|#
directive|define
name|PI
value|20
end_define

begin_define
define|#
directive|define
name|COMB
value|21
end_define

begin_define
define|#
directive|define
name|FAC
value|22
end_define

begin_define
define|#
directive|define
name|DEAL
value|23
end_define

begin_define
define|#
directive|define
name|RAND
value|24
end_define

begin_define
define|#
directive|define
name|DRHO
value|25
end_define

begin_define
define|#
directive|define
name|MRHO
value|26
end_define

begin_define
define|#
directive|define
name|DIOT
value|27
end_define

begin_define
define|#
directive|define
name|MIOT
value|28
end_define

begin_define
define|#
directive|define
name|ROT0
value|29
end_define

begin_define
define|#
directive|define
name|REV0
value|30
end_define

begin_define
define|#
directive|define
name|DTRN
value|31
end_define

begin_define
define|#
directive|define
name|MTRN
value|32
end_define

begin_define
define|#
directive|define
name|DIBM
value|33
end_define

begin_define
define|#
directive|define
name|MIBM
value|34
end_define

begin_define
define|#
directive|define
name|GDU
value|35
end_define

begin_define
define|#
directive|define
name|GDUK
value|36
end_define

begin_define
define|#
directive|define
name|GDD
value|37
end_define

begin_define
define|#
directive|define
name|GDDK
value|38
end_define

begin_define
define|#
directive|define
name|EXD
value|39
end_define

begin_define
define|#
directive|define
name|SCAN
value|40
end_define

begin_define
define|#
directive|define
name|EXDK
value|41
end_define

begin_define
define|#
directive|define
name|SCANK
value|42
end_define

begin_define
define|#
directive|define
name|IPROD
value|43
end_define

begin_define
define|#
directive|define
name|OPROD
value|44
end_define

begin_define
define|#
directive|define
name|QUAD
value|45
end_define

begin_define
define|#
directive|define
name|QQUAD
value|46
end_define

begin_define
define|#
directive|define
name|BRAN0
value|47
end_define

begin_define
define|#
directive|define
name|BRAN
value|48
end_define

begin_define
define|#
directive|define
name|DDOM
value|49
end_define

begin_define
define|#
directive|define
name|MDOM
value|50
end_define

begin_define
define|#
directive|define
name|COM
value|51
end_define

begin_define
define|#
directive|define
name|RED
value|52
end_define

begin_define
define|#
directive|define
name|COMK
value|53
end_define

begin_define
define|#
directive|define
name|REDK
value|54
end_define

begin_define
define|#
directive|define
name|ROT
value|55
end_define

begin_define
define|#
directive|define
name|REV
value|56
end_define

begin_define
define|#
directive|define
name|ROTK
value|57
end_define

begin_define
define|#
directive|define
name|REVK
value|58
end_define

begin_define
define|#
directive|define
name|CAT
value|59
end_define

begin_define
define|#
directive|define
name|RAV
value|60
end_define

begin_define
define|#
directive|define
name|CATK
value|61
end_define

begin_define
define|#
directive|define
name|RAVK
value|62
end_define

begin_define
define|#
directive|define
name|PRINT
value|63
end_define

begin_define
define|#
directive|define
name|QUOT
value|64
end_define

begin_define
define|#
directive|define
name|ELID
value|65
end_define

begin_define
define|#
directive|define
name|CQUAD
value|66
end_define

begin_define
define|#
directive|define
name|COMNT
value|67
end_define

begin_define
define|#
directive|define
name|INDEX
value|68
end_define

begin_define
define|#
directive|define
name|HPRINT
value|69
end_define

begin_define
define|#
directive|define
name|LT
value|71
end_define

begin_define
define|#
directive|define
name|LE
value|72
end_define

begin_define
define|#
directive|define
name|GT
value|73
end_define

begin_define
define|#
directive|define
name|GE
value|74
end_define

begin_define
define|#
directive|define
name|EQ
value|75
end_define

begin_define
define|#
directive|define
name|NE
value|76
end_define

begin_define
define|#
directive|define
name|AND
value|77
end_define

begin_define
define|#
directive|define
name|OR
value|78
end_define

begin_define
define|#
directive|define
name|NAND
value|79
end_define

begin_define
define|#
directive|define
name|NOR
value|80
end_define

begin_define
define|#
directive|define
name|NOT
value|81
end_define

begin_define
define|#
directive|define
name|EPS
value|82
end_define

begin_define
define|#
directive|define
name|MEPS
value|83
end_define

begin_define
define|#
directive|define
name|REP
value|84
end_define

begin_define
define|#
directive|define
name|TAKE
value|85
end_define

begin_define
define|#
directive|define
name|DROP
value|86
end_define

begin_define
define|#
directive|define
name|ASGN
value|88
end_define

begin_define
define|#
directive|define
name|IMMED
value|89
end_define

begin_define
define|#
directive|define
name|NAME
value|90
end_define

begin_define
define|#
directive|define
name|CONST
value|91
end_define

begin_define
define|#
directive|define
name|FUN
value|92
end_define

begin_define
define|#
directive|define
name|ARG1
value|93
end_define

begin_define
define|#
directive|define
name|ARG2
value|94
end_define

begin_define
define|#
directive|define
name|AUTO
value|95
end_define

begin_define
define|#
directive|define
name|REST
value|96
end_define

begin_define
define|#
directive|define
name|COM0
value|97
end_define

begin_define
define|#
directive|define
name|RED0
value|98
end_define

begin_define
define|#
directive|define
name|EXD0
value|99
end_define

begin_define
define|#
directive|define
name|SCAN0
value|100
end_define

begin_define
define|#
directive|define
name|BASE
value|101
end_define

begin_define
define|#
directive|define
name|MENC
value|102
end_define

begin_comment
comment|/*	monadic	encode	*/
end_comment

begin_comment
comment|/*  *  Immediate sub-op codes  */
end_comment

begin_define
define|#
directive|define
name|CLEAR
value|1
end_define

begin_define
define|#
directive|define
name|DIGITS
value|2
end_define

begin_define
define|#
directive|define
name|ED_IT
value|3
end_define

begin_define
define|#
directive|define
name|ERASE
value|4
end_define

begin_define
define|#
directive|define
name|FNS
value|5
end_define

begin_define
define|#
directive|define
name|FUZZ
value|6
end_define

begin_define
define|#
directive|define
name|READ
value|7
end_define

begin_define
define|#
directive|define
name|ORIGIN
value|8
end_define

begin_define
define|#
directive|define
name|VARS
value|9
end_define

begin_define
define|#
directive|define
name|WIDTH
value|10
end_define

begin_define
define|#
directive|define
name|DEBUG
value|11
end_define

begin_define
define|#
directive|define
name|OFF
value|12
end_define

begin_define
define|#
directive|define
name|LOAD
value|13
end_define

begin_define
define|#
directive|define
name|SAVE
value|14
end_define

begin_define
define|#
directive|define
name|COPY
value|15
end_define

begin_define
define|#
directive|define
name|CONTIN
value|16
end_define

begin_define
define|#
directive|define
name|LIB
value|17
end_define

begin_define
define|#
directive|define
name|DROPC
value|18
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SOMED
end_ifdef

begin_define
define|#
directive|define
name|SYMBOLS
value|19
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EX_IT
value|20
end_define

begin_define
define|#
directive|define
name|EX_VI
value|21
end_define

begin_define
define|#
directive|define
name|ASCII
value|22
end_define

begin_define
define|#
directive|define
name|APL
value|23
end_define

begin_comment
comment|/*  *  Types  */
end_comment

begin_define
define|#
directive|define
name|DA
value|1
end_define

begin_comment
comment|/* Numeric data (?) */
end_comment

begin_define
define|#
directive|define
name|CH
value|2
end_define

begin_comment
comment|/* Character data (?) */
end_comment

begin_define
define|#
directive|define
name|LV
value|3
end_define

begin_comment
comment|/* Used for most data items */
end_comment

begin_define
define|#
directive|define
name|QD
value|4
end_define

begin_comment
comment|/* Quad (assignment to (?)) */
end_comment

begin_define
define|#
directive|define
name|QQ
value|5
end_define

begin_comment
comment|/* Quote-quad */
end_comment

begin_define
define|#
directive|define
name|IN
value|6
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|EL
value|7
end_define

begin_comment
comment|/* Literal data (??) */
end_comment

begin_define
define|#
directive|define
name|NF
value|8
end_define

begin_comment
comment|/* Name of function with no args */
end_comment

begin_define
define|#
directive|define
name|MF
value|9
end_define

begin_comment
comment|/* Monadic function */
end_comment

begin_define
define|#
directive|define
name|DF
value|10
end_define

begin_comment
comment|/* Dyadic function */
end_comment

begin_define
define|#
directive|define
name|QC
value|11
end_define

begin_comment
comment|/*  *  Idiosyncracies  */
end_comment

begin_define
define|#
directive|define
name|data
value|double
end_define

begin_define
define|#
directive|define
name|unsignd
value|unsigned
end_define

begin_comment
comment|/*  *  Structures  */
end_comment

begin_struct
struct|struct
block|{
name|char
name|c
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|env
block|{
name|double
name|fuzz
decl_stmt|;
name|int
name|iorg
decl_stmt|;
name|int
name|digits
decl_stmt|;
name|int
name|width
decl_stmt|;
block|}
name|thread
struct|;
end_struct

begin_struct
struct|struct
name|item
block|{
name|char
name|rank
decl_stmt|;
name|char
name|type
decl_stmt|;
name|int
name|size
decl_stmt|;
name|int
name|index
decl_stmt|;
name|data
modifier|*
name|datap
decl_stmt|;
name|int
name|dim
index|[
name|MRANK
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nlist
block|{
name|char
name|use
decl_stmt|;
name|char
name|type
decl_stmt|;
comment|/* == LV */
name|int
modifier|*
name|itemp
decl_stmt|;
name|char
modifier|*
name|namep
decl_stmt|;
name|int
name|label
decl_stmt|;
block|}
name|nlist
index|[
name|NLS
index|]
struct|;
end_struct

begin_struct
struct|struct
name|lablist
block|{
name|char
modifier|*
name|lname
decl_stmt|;
name|int
name|lno
decl_stmt|;
name|struct
name|lablist
modifier|*
name|nextll
decl_stmt|;
block|}
name|labldefs
struct|;
end_struct

begin_struct
struct|struct
block|{
name|char
name|rank
decl_stmt|;
name|char
name|type
decl_stmt|;
name|int
name|size
decl_stmt|;
name|int
name|dimk
decl_stmt|;
name|int
name|delk
decl_stmt|;
name|int
name|dim
index|[
name|MRANK
index|]
decl_stmt|;
name|int
name|del
index|[
name|MRANK
index|]
decl_stmt|;
name|int
name|idx
index|[
name|MRANK
index|]
decl_stmt|;
block|}
name|idx
struct|;
end_struct

begin_struct
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|line
decl_stmt|;
block|}
name|now_xeq
struct|;
end_struct

begin_decl_stmt
name|struct
name|item
modifier|*
modifier|*
name|sp
decl_stmt|,
modifier|*
modifier|*
name|stack
decl_stmt|,
modifier|*
modifier|*
name|staktop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Internal run-time stack */
end_comment

begin_comment
comment|/*  *  Externals  */
end_comment

begin_decl_stmt
name|data
name|zero
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|data
name|one
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|data
name|pi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|data
name|maxexp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|data
name|datum
decl_stmt|;
end_decl_stmt

begin_function_decl
name|data
name|getdat
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|cs_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current stack size	   */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|exop
index|[]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|floor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|ceil
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|log
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|sin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|cos
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|atan
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|atan2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|sqrt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|exp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|gamma
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|ltod
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|integ
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|signgam
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|column
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|intflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|echoflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ifile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ofile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|funlc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttystat
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|stime
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|pcp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rowsz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mencflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|mencptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|memstart
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|syze
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pas1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|continu
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|charbox
block|{
name|char
name|a1
decl_stmt|,
name|a2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|asoperbox
block|{
name|unsigned
name|char
name|letters
index|[
literal|2
index|]
decl_stmt|;
name|int
name|returnchar
block|}
struct|;
end_struct

end_unit

