begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|apl_h_Sccsid
index|[]
init|=
literal|"apl.h @(#)apl.h	1.5	2/16/84 Berkeley "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	UNIX APL\11  *  *  *	UNIX APL was originally written by Ken Thompson at Bell Labs.  *	It spent some time at Yale and finally arrived at Purdue  *	University.  Since 1976 it has been modified by Jim Besemer  *	and John Bruner at the School of Electrical Engineering, Purdue,  *	under the direction of Dr. Anthony P. Reeves.  It is currently  *	being developed and supported at Purdue/EE by J. Bruner and  *	A. Reeves on both PDP-11's and VAX-11/780's  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/*  *	New file system param.h defines MIN and MAX; we  *	have to undefine them to avoid conflicts  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MIN
end_ifdef

begin_undef
undef|#
directive|undef
name|MIN
end_undef

begin_endif
endif|#
directive|endif
endif|MIN
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MAX
end_ifdef

begin_undef
undef|#
directive|undef
name|MAX
end_undef

begin_endif
endif|#
directive|endif
endif|MAX
end_endif

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_comment
comment|/*  * Configuration information  *  * The C preprocessor will automatically supply "vax" if APL is compiled  * on a VAX-11/780.  *  * Other configuration parameters which may be specified are:  *  * PURDUE_EE		enable special Purdue/EE code  * VMUNIX		enable code for Berkeley virtual UNIX stuff  *  VFORK		use vfork() when possible (implied by VMUNIX)  *  VLIMIT		use 4.1bsd vlimit() (implied by VMUNIX)  *  NDIR		4.2bsd directory format (implied by VMUNIX)  * APL2			generate single-precision version  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMUNIX
end_ifdef

begin_define
define|#
directive|define
name|VLIMIT
end_define

begin_define
define|#
directive|define
name|VFORK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NFDS
value|20
end_define

begin_comment
comment|/* Number of available fd's */
end_comment

begin_define
define|#
directive|define
name|MAXEOT
value|8
end_define

begin_comment
comment|/* # of input EOT's before panic */
end_comment

begin_comment
comment|/*  * Temp file names  */
end_comment

begin_define
define|#
directive|define
name|WSFILE
value|ws_file
end_define

begin_comment
comment|/* work space file */
end_comment

begin_comment
comment|/*  * Magic Numbers  */
end_comment

begin_define
define|#
directive|define
name|MRANK
value|8
end_define

begin_define
define|#
directive|define
name|CANBS
value|300
end_define

begin_define
define|#
directive|define
name|STKS
value|500
end_define

begin_define
define|#
directive|define
name|NLS
value|200
end_define

begin_define
define|#
directive|define
name|NAMS
value|40
end_define

begin_define
define|#
directive|define
name|OBJS
value|500
end_define

begin_define
define|#
directive|define
name|MAXLAB
value|30
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|vax
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|APL2
end_ifdef

begin_define
define|#
directive|define
name|MAGIC
value|0101555
end_define

begin_comment
comment|/* PDP-11 single-precision format */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAGIC
value|0101554
end_define

begin_comment
comment|/* PDP-11 double-precision format */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|APL2
end_ifdef

begin_define
define|#
directive|define
name|MAGIC
value|0101557
end_define

begin_comment
comment|/* VAX single-precision format */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAGIC
value|0101556
end_define

begin_comment
comment|/* VAX double-precision format */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|APL2
end_ifdef

begin_define
define|#
directive|define
name|data
value|float
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|data
value|double
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * derived constants  */
end_comment

begin_define
define|#
directive|define
name|SDAT
value|sizeof(data)
end_define

begin_define
define|#
directive|define
name|SINT
value|sizeof(int)
end_define

begin_comment
comment|/*  * Interpreter Op Codes  */
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

begin_define
define|#
directive|define
name|LABEL
value|103
end_define

begin_comment
comment|/* statement label */
end_comment

begin_define
define|#
directive|define
name|PSI
value|104
end_define

begin_comment
comment|/* PSI input character */
end_comment

begin_define
define|#
directive|define
name|PSI1
value|105
end_define

begin_comment
comment|/* PSI monadic half */
end_comment

begin_define
define|#
directive|define
name|PSI2
value|106
end_define

begin_comment
comment|/* PSI dyadic half */
end_comment

begin_define
define|#
directive|define
name|ISP
value|107
end_define

begin_comment
comment|/* ISP input code */
end_comment

begin_define
define|#
directive|define
name|ISP1
value|108
end_define

begin_comment
comment|/* ISP monadic half */
end_comment

begin_define
define|#
directive|define
name|ISP2
value|109
end_define

begin_comment
comment|/* ISP dyadic half */
end_comment

begin_define
define|#
directive|define
name|QWID
value|110
end_define

begin_comment
comment|/* quad fn1 */
end_comment

begin_define
define|#
directive|define
name|QFUZZ
value|111
end_define

begin_define
define|#
directive|define
name|QRUN
value|112
end_define

begin_define
define|#
directive|define
name|QFORK
value|113
end_define

begin_define
define|#
directive|define
name|QWAIT
value|114
end_define

begin_define
define|#
directive|define
name|QEXEC
value|115
end_define

begin_define
define|#
directive|define
name|FDEF
value|116
end_define

begin_define
define|#
directive|define
name|QEXIT
value|117
end_define

begin_define
define|#
directive|define
name|QPIPE
value|118
end_define

begin_define
define|#
directive|define
name|QCHDIR
value|119
end_define

begin_define
define|#
directive|define
name|QOPEN
value|120
end_define

begin_define
define|#
directive|define
name|QCLOSE
value|121
end_define

begin_define
define|#
directive|define
name|QREAD
value|122
end_define

begin_define
define|#
directive|define
name|QWRITE
value|123
end_define

begin_define
define|#
directive|define
name|QCREAT
value|124
end_define

begin_define
define|#
directive|define
name|QSEEK
value|125
end_define

begin_define
define|#
directive|define
name|QUNLNK
value|126
end_define

begin_define
define|#
directive|define
name|QRD
value|127
end_define

begin_define
define|#
directive|define
name|QDUP
value|128
end_define

begin_define
define|#
directive|define
name|QAP
value|129
end_define

begin_define
define|#
directive|define
name|QKILL
value|130
end_define

begin_define
define|#
directive|define
name|QCRP
value|131
end_define

begin_define
define|#
directive|define
name|DFMT
value|132
end_define

begin_define
define|#
directive|define
name|MFMT
value|133
end_define

begin_define
define|#
directive|define
name|QNC
value|134
end_define

begin_define
define|#
directive|define
name|NILRET
value|135
end_define

begin_define
define|#
directive|define
name|XQUAD
value|136
end_define

begin_define
define|#
directive|define
name|SICLR
value|137
end_define

begin_define
define|#
directive|define
name|SICLR0
value|138
end_define

begin_define
define|#
directive|define
name|RVAL
value|139
end_define

begin_define
define|#
directive|define
name|QSIGNL
value|140
end_define

begin_define
define|#
directive|define
name|QFLOAT
value|141
end_define

begin_comment
comment|/* Float character string to data */
end_comment

begin_define
define|#
directive|define
name|QNL
value|142
end_define

begin_comment
comment|/* Produce namelist */
end_comment

begin_comment
comment|/*  * Immediate sub-op codes  */
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
name|EDIT
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

begin_define
define|#
directive|define
name|VSAVE
value|19
end_define

begin_define
define|#
directive|define
name|SCRIPT
value|20
end_define

begin_define
define|#
directive|define
name|EDITF
value|21
end_define

begin_define
define|#
directive|define
name|TRACE
value|22
end_define

begin_define
define|#
directive|define
name|UNTRACE
value|23
end_define

begin_define
define|#
directive|define
name|WRITE
value|24
end_define

begin_define
define|#
directive|define
name|RESET
value|25
end_define

begin_define
define|#
directive|define
name|SICOM
value|26
end_define

begin_define
define|#
directive|define
name|CODE
value|27
end_define

begin_define
define|#
directive|define
name|DEL
value|28
end_define

begin_define
define|#
directive|define
name|SHELL
value|29
end_define

begin_define
define|#
directive|define
name|LIST
value|30
end_define

begin_define
define|#
directive|define
name|PRWS
value|31
end_define

begin_struct
struct|struct
name|chrstrct
block|{
name|char
name|c
index|[
literal|2
index|]
decl_stmt|;
comment|/* Can't be 0 anymore (VAX) */
block|}
struct|;
end_struct

begin_union
union|union
name|uci
block|{
name|char
name|cv
index|[
sizeof|sizeof
argument_list|(
name|int
argument_list|)
index|]
decl_stmt|;
comment|/* character array */
name|unsigned
name|i
decl_stmt|;
comment|/* unsigned integer value */
block|}
union|;
end_union

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

begin_comment
comment|/* the largest value such that exp(maxexp) is defined */
end_comment

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
name|funtrace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* function trace enabled */
end_comment

begin_decl_stmt
name|int
name|labgen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* label processing being done */
end_comment

begin_decl_stmt
name|int
name|apl_term
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag set if apl terminal mapping req'd */
end_comment

begin_decl_stmt
name|jmp_buf
name|gbl_env
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Used for setexit/reset */
end_comment

begin_comment
comment|/*  * Several unrelated values, which appear  * together in the header of an apl workspace file.  */
end_comment

begin_struct
struct|struct
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
name|int
name|rl
decl_stmt|;
comment|/* Random Seed (Ph.A. S.B.B.) */
block|}
name|thread
struct|;
end_struct

begin_comment
comment|/*  * Data types  * Each new type should be accomodated for   * in dealloc [a0.c]  */
end_comment

begin_define
define|#
directive|define
name|DA
value|1
end_define

begin_define
define|#
directive|define
name|CH
value|2
end_define

begin_define
define|#
directive|define
name|LV
value|3
end_define

begin_define
define|#
directive|define
name|QD
value|4
end_define

begin_define
define|#
directive|define
name|QQ
value|5
end_define

begin_define
define|#
directive|define
name|IN
value|6
end_define

begin_define
define|#
directive|define
name|EL
value|7
end_define

begin_define
define|#
directive|define
name|NF
value|8
end_define

begin_define
define|#
directive|define
name|MF
value|9
end_define

begin_define
define|#
directive|define
name|DF
value|10
end_define

begin_define
define|#
directive|define
name|QC
value|11
end_define

begin_define
define|#
directive|define
name|QV
value|12
end_define

begin_comment
comment|/* quad variables */
end_comment

begin_define
define|#
directive|define
name|DU
value|13
end_define

begin_comment
comment|/* dummy -- causes fetch error except on print */
end_comment

begin_define
define|#
directive|define
name|QX
value|14
end_define

begin_comment
comment|/* latent expr. quad "Llx" */
end_comment

begin_define
define|#
directive|define
name|LBL
value|15
end_define

begin_comment
comment|/* locked label value */
end_comment

begin_define
define|#
directive|define
name|NTYPES
value|16
end_define

begin_comment
comment|/* number of defined types */
end_comment

begin_comment
comment|/*  * This is a descriptor for apl data, allocated by "newdat".  * The actual data starts at item.dim[item.rank], and thus  *&item.dim[item.rank] should always == item.datap.  * See the comment in "newdat" (a0.c) about "dim".  *  * A null item is a vector(!), and is rank==1, size==0.  *  * the stack is the operand stack, and sp is the pointer to the  * top of  the stack.  */
end_comment

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
modifier|*
name|stack
index|[
name|STKS
index|]
struct|,
modifier|*
modifier|*
name|sp
struct|;
end_struct

begin_comment
comment|/*  * variable/fn (and file name) descriptor block.  * contains useful information about all LVals.  * Also kludged up to handle file names (only nlist.namep   * is then used.)  *  * For fns, nlist.itemp is an array of pointers to character  * strings which are the compiled code for a line of the fn.  * (Itemp == 0) means that the fn has not yet been compiled .  * nlist.itemp[0] == the number of lines in the fn, and  * nlist.itemp[1] == the function startup code, and  * nlist.itemp[max] == the close down shop code.  */
end_comment

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
name|struct
name|item
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

begin_comment
comment|/*  * This is the structure used to implement the  * APL state indicator.  *  * The structure is allocated dynamically in ex_fun (ai.c),  * but not explicitly.   Ex_fun declares a single, local  * structure (allocated by C, itself), and links it to  * previous instances of the structure.  SI is used for  * two basic things:  *  *	1) error traceback (Including ")SI" stuff).  *	2) Restoration of the global variable environment  *	   (or any other, pending environment).  *  * The global variable "gsip" is a pointer to the  * head of a chain of these structures, one for each  * instance of an activated function.  (Gsip == 0) implies  * an empty list, (gsip->sip == 0) implies the end of the list,  * and (gsip->np == 0) implies a state indicator seperator.  * (A new function was evoked with an old one pending.)  *  * Note that "gsip->funlc" is the same as the old global  * variable "funlc", and   *  *	(gsip&& gsip->sip ? gsip->sip->funlc : 0)  *  * is the value of the old global, "ibeam36".  */
end_comment

begin_struct
struct|struct
name|si
block|{
name|int
name|suspended
decl_stmt|;
comment|/* fn is suspended<=1, pending<= 0 */
name|struct
name|si
modifier|*
name|sip
decl_stmt|;
comment|/* previous fn activation */
name|struct
name|nlist
modifier|*
name|np
decl_stmt|;
comment|/* current fn vital stats. */
name|int
name|funlc
decl_stmt|;
comment|/* current fn current line number */
name|struct
name|item
modifier|*
modifier|*
name|oldsp
decl_stmt|;
comment|/* top of operand stack upon fn entry */
name|char
modifier|*
name|oldpcp
decl_stmt|;
comment|/* execution string upon fn entry */
name|jmp_buf
name|env
decl_stmt|;
comment|/* for restoration of local 				 * fn activation record */
block|}
modifier|*
name|gsip
struct|;
end_struct

begin_comment
comment|/*  * exop[i] is the address of the i'th action routine.  * Because of a "symbol table overflow" problem with C,  * the table was moved from a1.c to its own at.c  */
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
name|fabs
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

begin_function_decl
name|char
modifier|*
name|rline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|compile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nlist
modifier|*
name|nlook
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|item
modifier|*
name|fetch
argument_list|()
decl_stmt|,
modifier|*
name|fetch1
argument_list|()
decl_stmt|,
modifier|*
name|fetch2
argument_list|()
decl_stmt|,
modifier|*
name|extend
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|item
modifier|*
name|newdat
argument_list|()
decl_stmt|,
modifier|*
name|dupdat
argument_list|()
decl_stmt|;
end_decl_stmt

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
name|offexit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if != 0, require ")off" to exit */
end_comment

begin_decl_stmt
name|int
name|prwsflg
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
name|long
name|stime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|pcp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global copy of arg to exec */
end_comment

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
name|int
name|aftrace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|mencptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|oldlb
index|[
name|MAXLAB
index|]
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
name|int
name|ibeam36
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|protofile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lastop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last (current) operator exec'ed */
end_comment

begin_decl_stmt
name|char
modifier|*
name|scr_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scratch file name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ws_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* apl workspace file */
end_comment

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

begin_comment
comment|/* Following are definitions for buffered I/O.  * To generate a version of APL without buffered I/O,  * leave NBUF undefined.  */
end_comment

begin_define
define|#
directive|define
name|NBUF
value|4
end_define

begin_comment
comment|/* Number of I/O buffers */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NBUF
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|BLEN
value|512
end_define

begin_comment
comment|/* Buffered I/O buffer length */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BLEN
value|256
end_define

begin_comment
comment|/* Buffered I/O buffer length */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|iobuf
block|{
comment|/* Buffered I/O buffer structure */
name|int
name|b_len
decl_stmt|;
comment|/* Buffer length */
name|int
name|b_next
decl_stmt|;
comment|/* Next available character */
name|int
name|b_fd
decl_stmt|;
comment|/* Assigned file descriptor */
name|char
name|b_buf
index|[
name|BLEN
index|]
decl_stmt|;
comment|/* Actual buffer */
block|}
modifier|*
name|iobuf
struct|;
end_struct

begin_struct
struct|struct
name|fds
block|{
name|dev_t
name|fd_dev
decl_stmt|;
comment|/* Device major/minor number */
name|ino_t
name|fd_ind
decl_stmt|;
comment|/* File inode number */
name|int
name|fd_pipe
decl_stmt|;
comment|/* (1=pipe, 0=not a pipe) */
name|int
name|fd_buf
decl_stmt|;
comment|/* Number of assigned buffer */
name|char
name|fd_lastop
decl_stmt|;
comment|/* Last operation (0=read, 1=write) */
name|char
name|fd_uniq
decl_stmt|;
comment|/* Unique flag (1=unique, 0=not unique) */
name|char
name|fd_dup
decl_stmt|;
comment|/* Principal fd for dups */
name|char
name|fd_open
decl_stmt|;
comment|/* (0=closed, 1=open) */
block|}
name|files
index|[
name|NFDS
index|]
struct|;
end_struct

begin_define
define|#
directive|define
name|READF
value|readf
end_define

begin_comment
comment|/* Buffered read routine */
end_comment

begin_define
define|#
directive|define
name|WRITEF
value|writef
end_define

begin_comment
comment|/* Buffered write routine */
end_comment

begin_define
define|#
directive|define
name|SEEKF
value|lseekf
end_define

begin_comment
comment|/* Buffered seek routine */
end_comment

begin_define
define|#
directive|define
name|OPENF
value|openf
end_define

begin_comment
comment|/* Buffered file open routine */
end_comment

begin_define
define|#
directive|define
name|CREATF
value|creatf
end_define

begin_comment
comment|/* Buffered file create routine */
end_comment

begin_define
define|#
directive|define
name|DUPF
value|dupf
end_define

begin_comment
comment|/* Buffered file dup routine */
end_comment

begin_define
define|#
directive|define
name|CLOSEF
value|closef
end_define

begin_comment
comment|/* Buffered file close routine */
end_comment

begin_define
define|#
directive|define
name|FSTATF
value|fstatf
end_define

begin_comment
comment|/* Buffered "fstat" call */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VFORK
end_ifndef

begin_define
define|#
directive|define
name|FORKF
parameter_list|(
name|x
parameter_list|)
value|(bflush(),fork())
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FORKF
parameter_list|(
name|x
parameter_list|)
value|(bflush(),(x) ? vfork() : fork())
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NBUF
end_ifndef

begin_define
define|#
directive|define
name|READF
value|read
end_define

begin_comment
comment|/* Normal read routine */
end_comment

begin_define
define|#
directive|define
name|WRITEF
value|write
end_define

begin_comment
comment|/* Normal write routine */
end_comment

begin_define
define|#
directive|define
name|SEEKF
value|lseek
end_define

begin_comment
comment|/* Normal seek routine */
end_comment

begin_define
define|#
directive|define
name|OPENF
value|open
end_define

begin_comment
comment|/* Normal file open routine */
end_comment

begin_define
define|#
directive|define
name|CREATF
value|creat
end_define

begin_comment
comment|/* Normal file create routine */
end_comment

begin_define
define|#
directive|define
name|DUPF
value|dup
end_define

begin_comment
comment|/* Normal file dup routine */
end_comment

begin_define
define|#
directive|define
name|CLOSEF
value|close
end_define

begin_comment
comment|/* Normal file close routine */
end_comment

begin_define
define|#
directive|define
name|FSTATF
value|fstat
end_define

begin_comment
comment|/* Normal "fstat" call */
end_comment

begin_define
define|#
directive|define
name|FORKF
parameter_list|(
name|x
parameter_list|)
value|fork()
end_define

begin_comment
comment|/* Normal "fork" call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|long
name|SEEKF
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* declare SEEKF properly */
end_comment

begin_define
define|#
directive|define
name|setexit
parameter_list|()
value|setjmp(gbl_env)
end_define

begin_comment
comment|/* "setexit" equivalent */
end_comment

begin_define
define|#
directive|define
name|reset
parameter_list|()
value|longjmp(gbl_env)
end_define

begin_comment
comment|/* "reset" equivalent */
end_comment

begin_define
define|#
directive|define
name|alloc
parameter_list|(
name|x
parameter_list|)
value|malloc(x)
end_define

end_unit

