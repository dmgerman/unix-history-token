begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	pass2.h	4.4	87/12/10	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PASS2_
end_ifndef

begin_define
define|#
directive|define
name|_PASS2_
end_define

begin_include
include|#
directive|include
file|"macdefs.h"
end_include

begin_include
include|#
directive|include
file|"mac2defs.h"
end_include

begin_include
include|#
directive|include
file|"manifest.h"
end_include

begin_comment
comment|/* cookies, used as arguments to codgen */
end_comment

begin_define
define|#
directive|define
name|FOREFF
value|01
end_define

begin_comment
comment|/* compute for effects only */
end_comment

begin_define
define|#
directive|define
name|INAREG
value|02
end_define

begin_comment
comment|/* compute into a register */
end_comment

begin_define
define|#
directive|define
name|INTAREG
value|04
end_define

begin_comment
comment|/* compute into a scratch register */
end_comment

begin_define
define|#
directive|define
name|INBREG
value|010
end_define

begin_comment
comment|/* compute into a lvalue register */
end_comment

begin_define
define|#
directive|define
name|INTBREG
value|020
end_define

begin_comment
comment|/* compute into a scratch lvalue register */
end_comment

begin_define
define|#
directive|define
name|FORCC
value|040
end_define

begin_comment
comment|/* compute for condition codes only */
end_comment

begin_define
define|#
directive|define
name|INTEMP
value|010000
end_define

begin_comment
comment|/* compute into a temporary location */
end_comment

begin_define
define|#
directive|define
name|FORARG
value|020000
end_define

begin_comment
comment|/* compute for an argument of a function */
end_comment

begin_define
define|#
directive|define
name|FORREW
value|040000
end_define

begin_comment
comment|/* search the table for a rewrite rule */
end_comment

begin_comment
comment|/*  * OP descriptors,  * the ASG operator may be used on some of these  */
end_comment

begin_define
define|#
directive|define
name|OPSIMP
value|010000
end_define

begin_comment
comment|/* +, -,&, |, ^ */
end_comment

begin_define
define|#
directive|define
name|OPCOMM
value|010002
end_define

begin_comment
comment|/* +,&, |, ^ */
end_comment

begin_define
define|#
directive|define
name|OPMUL
value|010004
end_define

begin_comment
comment|/* *, / */
end_comment

begin_define
define|#
directive|define
name|OPDIV
value|010006
end_define

begin_comment
comment|/* /, % */
end_comment

begin_define
define|#
directive|define
name|OPUNARY
value|010010
end_define

begin_comment
comment|/* unary ops */
end_comment

begin_define
define|#
directive|define
name|OPLEAF
value|010012
end_define

begin_comment
comment|/* leaves */
end_comment

begin_define
define|#
directive|define
name|OPANY
value|010014
end_define

begin_comment
comment|/* any op... */
end_comment

begin_define
define|#
directive|define
name|OPLOG
value|010016
end_define

begin_comment
comment|/* logical ops */
end_comment

begin_define
define|#
directive|define
name|OPFLOAT
value|010020
end_define

begin_comment
comment|/* +, -, *, or / (for floats) */
end_comment

begin_define
define|#
directive|define
name|OPSHFT
value|010022
end_define

begin_comment
comment|/*<<,>> */
end_comment

begin_define
define|#
directive|define
name|OPLTYPE
value|010024
end_define

begin_comment
comment|/* leaf type nodes (e.g, NAME, ICON, etc.) */
end_comment

begin_comment
comment|/* match returns */
end_comment

begin_define
define|#
directive|define
name|MNOPE
value|010000
end_define

begin_comment
comment|/* no match generated */
end_comment

begin_define
define|#
directive|define
name|MDONE
value|010001
end_define

begin_comment
comment|/* done evalution */
end_comment

begin_comment
comment|/* shapes */
end_comment

begin_define
define|#
directive|define
name|SANY
value|01
end_define

begin_comment
comment|/* same as FOREFF */
end_comment

begin_define
define|#
directive|define
name|SAREG
value|02
end_define

begin_comment
comment|/* same as INAREG */
end_comment

begin_define
define|#
directive|define
name|STAREG
value|04
end_define

begin_comment
comment|/* same as INTAREG */
end_comment

begin_define
define|#
directive|define
name|SBREG
value|010
end_define

begin_comment
comment|/* same as INBREG */
end_comment

begin_define
define|#
directive|define
name|STBREG
value|020
end_define

begin_comment
comment|/* same as INTBREG */
end_comment

begin_define
define|#
directive|define
name|SCC
value|040
end_define

begin_comment
comment|/* same as FORCC */
end_comment

begin_define
define|#
directive|define
name|SNAME
value|0100
end_define

begin_comment
comment|/* name */
end_comment

begin_define
define|#
directive|define
name|SCON
value|0200
end_define

begin_comment
comment|/* constant */
end_comment

begin_define
define|#
directive|define
name|SFLD
value|0400
end_define

begin_comment
comment|/* field */
end_comment

begin_define
define|#
directive|define
name|SOREG
value|01000
end_define

begin_comment
comment|/* offset from register */
end_comment

begin_comment
comment|/* indirection or wild card shapes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WCARD1
end_ifndef

begin_define
define|#
directive|define
name|STARNM
value|02000
end_define

begin_comment
comment|/* indirect through name */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WCARD2
end_ifndef

begin_define
define|#
directive|define
name|STARREG
value|04000
end_define

begin_comment
comment|/* indirect through register */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SWADD
value|040000
end_define

begin_comment
comment|/* word address */
end_comment

begin_define
define|#
directive|define
name|SPECIAL
value|0100000
end_define

begin_comment
comment|/* special stuff (follows) */
end_comment

begin_define
define|#
directive|define
name|SZERO
value|SPECIAL
end_define

begin_comment
comment|/* constant zero */
end_comment

begin_define
define|#
directive|define
name|SONE
value|(SPECIAL|1)
end_define

begin_comment
comment|/* constant +1 */
end_comment

begin_define
define|#
directive|define
name|SMONE
value|(SPECIAL|2)
end_define

begin_comment
comment|/* constant -1 */
end_comment

begin_define
define|#
directive|define
name|SCCON
value|(SPECIAL|3)
end_define

begin_comment
comment|/* -256<= constant< 256 */
end_comment

begin_define
define|#
directive|define
name|SSCON
value|(SPECIAL|4)
end_define

begin_comment
comment|/* -32768<= constant< 32768 */
end_comment

begin_define
define|#
directive|define
name|SSOREG
value|(SPECIAL|5)
end_define

begin_comment
comment|/* non-indexed OREG */
end_comment

begin_define
define|#
directive|define
name|SMCON
value|(SPECIAL|6)
end_define

begin_comment
comment|/* constant< 0 */
end_comment

begin_comment
comment|/* FORARG and INTEMP are carefully not conflicting with shapes */
end_comment

begin_comment
comment|/* types */
end_comment

begin_define
define|#
directive|define
name|TCHAR
value|01
end_define

begin_comment
comment|/* char */
end_comment

begin_define
define|#
directive|define
name|TSHORT
value|02
end_define

begin_comment
comment|/* short */
end_comment

begin_define
define|#
directive|define
name|TINT
value|04
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|TLONG
value|010
end_define

begin_comment
comment|/* long */
end_comment

begin_define
define|#
directive|define
name|TFLOAT
value|020
end_define

begin_comment
comment|/* float */
end_comment

begin_define
define|#
directive|define
name|TDOUBLE
value|040
end_define

begin_comment
comment|/* double */
end_comment

begin_define
define|#
directive|define
name|TPOINT
value|0100
end_define

begin_comment
comment|/* pointer to something */
end_comment

begin_define
define|#
directive|define
name|TUCHAR
value|0200
end_define

begin_comment
comment|/* unsigned char */
end_comment

begin_define
define|#
directive|define
name|TUSHORT
value|0400
end_define

begin_comment
comment|/* unsigned short */
end_comment

begin_define
define|#
directive|define
name|TUNSIGNED
value|01000
end_define

begin_comment
comment|/* unsigned int */
end_comment

begin_define
define|#
directive|define
name|TULONG
value|02000
end_define

begin_comment
comment|/* unsigned long */
end_comment

begin_define
define|#
directive|define
name|TPTRTO
value|04000
end_define

begin_comment
comment|/* pointer to one of the above */
end_comment

begin_define
define|#
directive|define
name|TANY
value|010000
end_define

begin_comment
comment|/* matches anything within reason */
end_comment

begin_define
define|#
directive|define
name|TSTRUCT
value|020000
end_define

begin_comment
comment|/* structure or union */
end_comment

begin_comment
comment|/* reclamation cookies */
end_comment

begin_define
define|#
directive|define
name|RNULL
value|0
end_define

begin_comment
comment|/* clobber result */
end_comment

begin_define
define|#
directive|define
name|RLEFT
value|01
end_define

begin_comment
comment|/* reclaim left resource */
end_comment

begin_define
define|#
directive|define
name|RRIGHT
value|02
end_define

begin_comment
comment|/* reclaim right resource */
end_comment

begin_define
define|#
directive|define
name|RESC1
value|04
end_define

begin_comment
comment|/* reclaim resource allocated #1 */
end_comment

begin_define
define|#
directive|define
name|RESC2
value|010
end_define

begin_comment
comment|/* reclaim resource allocated #2 */
end_comment

begin_define
define|#
directive|define
name|RESC3
value|020
end_define

begin_comment
comment|/* reclaim resource allocated #3 */
end_comment

begin_define
define|#
directive|define
name|RESCC
value|04000
end_define

begin_comment
comment|/* reclaim condition codes */
end_comment

begin_define
define|#
directive|define
name|RNOP
value|010000
end_define

begin_comment
comment|/* DANGER: can cause loops.. */
end_comment

begin_comment
comment|/* needs */
end_comment

begin_define
define|#
directive|define
name|NAREG
value|01
end_define

begin_comment
comment|/* need an A register */
end_comment

begin_define
define|#
directive|define
name|NACOUNT
value|03
end_define

begin_comment
comment|/* count mask of A registers */
end_comment

begin_define
define|#
directive|define
name|NAMASK
value|017
end_define

begin_comment
comment|/* A register need field mask */
end_comment

begin_define
define|#
directive|define
name|NASL
value|04
end_define

begin_comment
comment|/* need A register shared with left resource */
end_comment

begin_define
define|#
directive|define
name|NASR
value|010
end_define

begin_comment
comment|/* need A register shared with right resource */
end_comment

begin_define
define|#
directive|define
name|NBREG
value|020
end_define

begin_comment
comment|/* need a B register */
end_comment

begin_define
define|#
directive|define
name|NBCOUNT
value|060
end_define

begin_comment
comment|/* count mask of B register */
end_comment

begin_define
define|#
directive|define
name|NBMASK
value|0360
end_define

begin_comment
comment|/* B register need field mask */
end_comment

begin_define
define|#
directive|define
name|NBSL
value|0100
end_define

begin_comment
comment|/* need B register shared with left resource */
end_comment

begin_define
define|#
directive|define
name|NBSR
value|0200
end_define

begin_comment
comment|/* need B register shared with right resource */
end_comment

begin_define
define|#
directive|define
name|NTEMP
value|0400
end_define

begin_comment
comment|/* need temporary storage location */
end_comment

begin_define
define|#
directive|define
name|NTMASK
value|07400
end_define

begin_comment
comment|/* count mask of temporary storage locations */
end_comment

begin_define
define|#
directive|define
name|REWRITE
value|010000
end_define

begin_comment
comment|/* need rewrite */
end_comment

begin_define
define|#
directive|define
name|EITHER
value|040000
end_define

begin_comment
comment|/* allocate all resources or nothing */
end_comment

begin_define
define|#
directive|define
name|MUSTDO
value|010000
end_define

begin_comment
comment|/* force register requirements */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOPREF
end_ifndef

begin_comment
comment|/* also defined in onepass.h */
end_comment

begin_define
define|#
directive|define
name|NOPREF
value|020000
end_define

begin_comment
comment|/* no preference for register assignment */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NEVEN
value|0100000
end_define

begin_comment
comment|/* even register required */
end_comment

begin_comment
comment|/* register allocation */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rstatus
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* register status info */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|busy
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* register use info */
end_comment

begin_struct
specifier|extern
struct|struct
name|respref
block|{
name|int
name|cform
decl_stmt|;
name|int
name|mform
decl_stmt|;
block|}
name|respref
index|[]
struct|;
end_struct

begin_comment
comment|/* resource preference rules */
end_comment

begin_define
define|#
directive|define
name|isbreg
parameter_list|(
name|r
parameter_list|)
value|(rstatus[r]&SBREG)
end_define

begin_define
define|#
directive|define
name|istreg
parameter_list|(
name|r
parameter_list|)
value|(rstatus[r]&(STBREG|STAREG))
end_define

begin_define
define|#
directive|define
name|istnode
parameter_list|(
name|p
parameter_list|)
value|(p->in.op==REG&& istreg(p->tn.rval))
end_define

begin_define
define|#
directive|define
name|TBUSY
value|01000
end_define

begin_comment
comment|/* register temporarily busy (during alloc) */
end_comment

begin_define
define|#
directive|define
name|PBUSY
value|02000
end_define

begin_comment
comment|/* this reg and next one are used as a pair */
end_comment

begin_define
define|#
directive|define
name|ISBUSY
parameter_list|(
name|r
parameter_list|)
value|(((busy[r])&(PBUSY-1))> 1)
end_define

begin_define
define|#
directive|define
name|REGLOOP
parameter_list|(
name|i
parameter_list|)
value|for (i = 0; i< REGSZ; ++i)
end_define

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|deltrees
index|[
name|DELAYS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trees held for delayed evaluation */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|deli
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mmmmm */
end_comment

begin_define
define|#
directive|define
name|SETSTO
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(stotree = (x), stocook = (y))
end_define

begin_decl_stmt
specifier|extern
name|int
name|stocook
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|stotree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|callflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fregs
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|ONEPASS
end_ifndef

begin_include
include|#
directive|include
file|"ndu.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|NODE
name|node
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* code tables */
end_comment

begin_struct
specifier|extern
struct|struct
name|optab
block|{
name|int
name|op
decl_stmt|;
comment|/* operator to match */
name|int
name|visit
decl_stmt|;
comment|/* goal to match */
name|int
name|lshape
decl_stmt|;
comment|/* left shape to match */
name|int
name|ltype
decl_stmt|;
comment|/* left type to match */
name|int
name|rshape
decl_stmt|;
comment|/* right shape to match */
name|int
name|rtype
decl_stmt|;
comment|/* right type to match */
name|int
name|needs
decl_stmt|;
comment|/* resource required */
name|int
name|rewrite
decl_stmt|;
comment|/* how to rewrite afterwards */
name|char
modifier|*
name|cstring
decl_stmt|;
comment|/* code generation template */
block|}
name|table
index|[]
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|NODE
name|resc
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|OFFSZ
name|tmpoff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|OFFSZ
name|maxoff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|OFFSZ
name|baseoff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|OFFSZ
name|maxtemp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxtreg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ftnno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rtyflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nrecur
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag to keep track of recursions */
end_comment

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|talloc
argument_list|()
decl_stmt|,
modifier|*
name|eread
argument_list|()
decl_stmt|,
modifier|*
name|tcopy
argument_list|()
decl_stmt|,
modifier|*
name|getlr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|CONSZ
name|rdin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|eprint
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rnames
index|[]
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
name|char
name|filename
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fldshf
decl_stmt|,
name|fldsz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lflag
decl_stmt|,
name|xdebug
decl_stmt|,
name|udebug
decl_stmt|,
name|edebug
decl_stmt|,
name|odebug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rdebug
decl_stmt|,
name|radebug
decl_stmt|,
name|tdebug
decl_stmt|,
name|sdebug
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|FORT
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|Oflag
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|callchk
end_ifndef

begin_define
define|#
directive|define
name|callchk
parameter_list|(
name|x
parameter_list|)
value|allchk()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUTCHAR
end_ifndef

begin_define
define|#
directive|define
name|PUTCHAR
parameter_list|(
name|x
parameter_list|)
value|putchar(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* macros for doing double indexing */
end_comment

begin_define
define|#
directive|define
name|R2PACK
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(0200*((x)+1)+y+040000*z)
end_define

begin_comment
comment|/* pack 3 regs */
end_comment

begin_define
define|#
directive|define
name|R2UPK1
parameter_list|(
name|x
parameter_list|)
value|((((x)>>7)-1)&0177)
end_define

begin_comment
comment|/* unpack reg 1 */
end_comment

begin_define
define|#
directive|define
name|R2UPK2
parameter_list|(
name|x
parameter_list|)
value|((x)&0177)
end_define

begin_comment
comment|/* unpack reg 2 */
end_comment

begin_define
define|#
directive|define
name|R2UPK3
parameter_list|(
name|x
parameter_list|)
value|(x>>14)
end_define

begin_comment
comment|/* unpack reg 3 */
end_comment

begin_define
define|#
directive|define
name|R2TEST
parameter_list|(
name|x
parameter_list|)
value|((x)>=0200)
end_define

begin_comment
comment|/* test if packed */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MULTILEVEL
end_ifdef

begin_union
union|union
name|mltemplate
block|{
struct|struct
name|ml_head
block|{
name|int
name|tag
decl_stmt|;
comment|/* tree class */
name|int
name|subtag
decl_stmt|;
comment|/* subclass of tree */
name|union
name|mltemplate
modifier|*
name|nexthead
decl_stmt|;
comment|/* linked by mlinit() */
block|}
name|mlhead
struct|;
struct|struct
name|ml_node
block|{
name|int
name|op
decl_stmt|;
comment|/* operator or op description */
name|int
name|nshape
decl_stmt|;
comment|/* node shape */
comment|/* 		 * Both op and nshape must match the node. 		 * where the work is to be done entirely by 		 * op, nshape can be SANY, visa versa, op can 		 * be OPANY. 		 */
name|int
name|ntype
decl_stmt|;
comment|/* type descriptor */
block|}
name|mlnode
struct|;
block|}
union|;
end_union

begin_decl_stmt
specifier|extern
name|union
name|mltemplate
name|mltree
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

