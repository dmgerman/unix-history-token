begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	pass1.h	4.2	85/08/22	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PASS1_
end_ifndef

begin_define
define|#
directive|define
name|_PASS1_
end_define

begin_include
include|#
directive|include
file|"macdefs.h"
end_include

begin_include
include|#
directive|include
file|"manifest.h"
end_include

begin_comment
comment|/*  * Symbol table definition.  *  * Colliding entries are moved down with a standard  * probe (no quadratic rehash here) and moved back when  * entries are cleared.  */
end_comment

begin_struct
struct|struct
name|symtab
block|{
ifndef|#
directive|ifndef
name|FLEXNAMES
name|char
name|sname
index|[
name|NCHNAM
index|]
decl_stmt|;
else|#
directive|else
name|char
modifier|*
name|sname
decl_stmt|;
endif|#
directive|endif
name|struct
name|symtab
modifier|*
name|snext
decl_stmt|;
comment|/* link to other symbols in the same scope */
name|TWORD
name|stype
decl_stmt|;
comment|/* type word */
name|char
name|sclass
decl_stmt|;
comment|/* storage class */
name|char
name|slevel
decl_stmt|;
comment|/* scope level */
name|char
name|sflags
decl_stmt|;
comment|/* flags, see below */
name|int
name|offset
decl_stmt|;
comment|/* offset or value */
name|short
name|dimoff
decl_stmt|;
comment|/* offset into the dimension table */
name|short
name|sizoff
decl_stmt|;
comment|/* offset into the size table */
name|int
name|suse
decl_stmt|;
comment|/* line number of last use of the variable */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Storage classes  */
end_comment

begin_define
define|#
directive|define
name|SNULL
value|0
end_define

begin_comment
comment|/* initial value */
end_comment

begin_define
define|#
directive|define
name|AUTO
value|1
end_define

begin_comment
comment|/* automatic (on stack) */
end_comment

begin_define
define|#
directive|define
name|EXTERN
value|2
end_define

begin_comment
comment|/* external reference */
end_comment

begin_define
define|#
directive|define
name|STATIC
value|3
end_define

begin_comment
comment|/* static scope */
end_comment

begin_define
define|#
directive|define
name|REGISTER
value|4
end_define

begin_comment
comment|/* register requested */
end_comment

begin_define
define|#
directive|define
name|EXTDEF
value|5
end_define

begin_comment
comment|/* external definition */
end_comment

begin_define
define|#
directive|define
name|LABEL
value|6
end_define

begin_comment
comment|/* label definition */
end_comment

begin_define
define|#
directive|define
name|ULABEL
value|7
end_define

begin_comment
comment|/* undefined label reference */
end_comment

begin_define
define|#
directive|define
name|MOS
value|8
end_define

begin_comment
comment|/* member of structure */
end_comment

begin_define
define|#
directive|define
name|PARAM
value|9
end_define

begin_comment
comment|/* parameter */
end_comment

begin_define
define|#
directive|define
name|STNAME
value|10
end_define

begin_comment
comment|/* structure name */
end_comment

begin_define
define|#
directive|define
name|MOU
value|11
end_define

begin_comment
comment|/* member of union */
end_comment

begin_define
define|#
directive|define
name|UNAME
value|12
end_define

begin_comment
comment|/* union name */
end_comment

begin_define
define|#
directive|define
name|TYPEDEF
value|13
end_define

begin_comment
comment|/* typedef name */
end_comment

begin_define
define|#
directive|define
name|FORTRAN
value|14
end_define

begin_comment
comment|/* fortran function */
end_comment

begin_define
define|#
directive|define
name|ENAME
value|15
end_define

begin_comment
comment|/* enumeration name */
end_comment

begin_define
define|#
directive|define
name|MOE
value|16
end_define

begin_comment
comment|/* member of enumeration */
end_comment

begin_define
define|#
directive|define
name|UFORTRAN
value|17
end_define

begin_comment
comment|/* undefined fortran reference */
end_comment

begin_define
define|#
directive|define
name|USTATIC
value|18
end_define

begin_comment
comment|/* undefined static reference */
end_comment

begin_comment
comment|/* field size is ORed in */
end_comment

begin_define
define|#
directive|define
name|FIELD
value|0100
end_define

begin_define
define|#
directive|define
name|FLDSIZ
value|077
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BUG1
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|scnames
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Symbol table flags  */
end_comment

begin_define
define|#
directive|define
name|SMOS
value|01
end_define

begin_comment
comment|/* member of structure */
end_comment

begin_define
define|#
directive|define
name|SHIDDEN
value|02
end_define

begin_comment
comment|/* hidden in current scope */
end_comment

begin_define
define|#
directive|define
name|SHIDES
value|04
end_define

begin_comment
comment|/* hides symbol in outer scope */
end_comment

begin_define
define|#
directive|define
name|SSET
value|010
end_define

begin_comment
comment|/* symbol assigned to */
end_comment

begin_define
define|#
directive|define
name|SREF
value|020
end_define

begin_comment
comment|/* symbol referenced */
end_comment

begin_define
define|#
directive|define
name|SNONUNIQ
value|040
end_define

begin_comment
comment|/* non-unique structure member */
end_comment

begin_define
define|#
directive|define
name|STAG
value|0100
end_define

begin_comment
comment|/* structure tag name */
end_comment

begin_comment
comment|/*  * Location counters  */
end_comment

begin_define
define|#
directive|define
name|PROG
value|0
end_define

begin_comment
comment|/* program segment */
end_comment

begin_define
define|#
directive|define
name|DATA
value|1
end_define

begin_comment
comment|/* data segment */
end_comment

begin_define
define|#
directive|define
name|ADATA
value|2
end_define

begin_comment
comment|/* array data segment */
end_comment

begin_define
define|#
directive|define
name|STRNG
value|3
end_define

begin_comment
comment|/* string data segment */
end_comment

begin_define
define|#
directive|define
name|ISTRNG
value|4
end_define

begin_comment
comment|/* initialized string segment */
end_comment

begin_define
define|#
directive|define
name|STAB
value|5
end_define

begin_comment
comment|/* symbol table segment */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|FIXDEF
end_ifndef

begin_define
define|#
directive|define
name|FIXDEF
parameter_list|(
name|p
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FIXARG
end_ifndef

begin_define
define|#
directive|define
name|FIXARG
parameter_list|(
name|p
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FIXSTRUCT
end_ifndef

begin_define
define|#
directive|define
name|FIXSTRUCT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* alignment of initialized quantities */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AL_INIT
end_ifndef

begin_define
define|#
directive|define
name|AL_INIT
value|ALINT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * External definitions  */
end_comment

begin_struct
struct|struct
name|sw
block|{
comment|/* switch table */
name|CONSZ
name|sval
decl_stmt|;
comment|/* case value */
name|int
name|slab
decl_stmt|;
comment|/* associated label */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|sw
name|swtab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sw
modifier|*
name|swp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|swx
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
name|blevel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|instruct
decl_stmt|,
name|stwart
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|,
name|nerrors
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CONSZ
name|lastcon
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|fcon
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|dcon
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|ftitle
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|ititle
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symtab
name|stab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|curftn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|curclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|curdim
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dimtab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|paramstk
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|paramno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|autooff
decl_stmt|,
name|argoff
decl_stmt|,
name|strucoff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|regvar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|minrvar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|brkflag
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
union|union
block|{
name|int
name|intval
decl_stmt|;
name|NODE
modifier|*
name|nodep
decl_stmt|;
block|}
name|YYSTYPE
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|YYSTYPE
name|yylval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|yytext
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|strflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|OFFSZ
name|inoff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|reached
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tunnel to buildtree for name id's */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|idname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
name|node
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|lastfree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cflag
decl_stmt|,
name|hflag
decl_stmt|,
name|pflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* various labels */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|brklab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|contlab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flostat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|retlab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|retstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|asavbc
index|[]
decl_stmt|,
modifier|*
name|psavbc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* declarations of various functions */
end_comment

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|buildtree
argument_list|()
decl_stmt|,
modifier|*
name|bdty
argument_list|()
decl_stmt|,
modifier|*
name|mkty
argument_list|()
decl_stmt|,
modifier|*
name|rstruct
argument_list|()
decl_stmt|,
modifier|*
name|dclstruct
argument_list|()
decl_stmt|,
modifier|*
name|getstr
argument_list|()
decl_stmt|,
modifier|*
name|tymerge
argument_list|()
decl_stmt|,
modifier|*
name|stref
argument_list|()
decl_stmt|,
modifier|*
name|offcon
argument_list|()
decl_stmt|,
modifier|*
name|bcon
argument_list|()
decl_stmt|,
modifier|*
name|bpsize
argument_list|()
decl_stmt|,
modifier|*
name|convert
argument_list|()
decl_stmt|,
modifier|*
name|pconvert
argument_list|()
decl_stmt|,
modifier|*
name|oconvert
argument_list|()
decl_stmt|,
modifier|*
name|ptmatch
argument_list|()
decl_stmt|,
modifier|*
name|tymatch
argument_list|()
decl_stmt|,
modifier|*
name|makety
argument_list|()
decl_stmt|,
modifier|*
name|block
argument_list|()
decl_stmt|,
modifier|*
name|doszof
argument_list|()
decl_stmt|,
modifier|*
name|talloc
argument_list|()
decl_stmt|,
modifier|*
name|optim
argument_list|()
decl_stmt|,
modifier|*
name|fixargs
argument_list|()
decl_stmt|,
modifier|*
name|clocal
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OFFSZ
name|tsize
argument_list|()
decl_stmt|,
name|psize
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|TWORD
name|types
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|atof
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|exname
argument_list|()
decl_stmt|,
modifier|*
name|exdcon
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|checkst
parameter_list|(
name|x
parameter_list|)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CHARCAST
end_ifndef

begin_comment
comment|/* to make character constants into character connstants */
end_comment

begin_comment
comment|/* this is a macro to defend against cross-compilers, etc. */
end_comment

begin_define
define|#
directive|define
name|CHARCAST
parameter_list|(
name|x
parameter_list|)
value|(char)(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Flags used in structures/unions  */
end_comment

begin_define
define|#
directive|define
name|SEENAME
value|01
end_define

begin_define
define|#
directive|define
name|INSTRUCT
value|02
end_define

begin_define
define|#
directive|define
name|INUNION
value|04
end_define

begin_define
define|#
directive|define
name|FUNNYNAME
value|010
end_define

begin_define
define|#
directive|define
name|TAGNAME
value|020
end_define

begin_comment
comment|/*  * Flags used in the (elementary) flow analysis ...  */
end_comment

begin_define
define|#
directive|define
name|FBRK
value|02
end_define

begin_define
define|#
directive|define
name|FCONT
value|04
end_define

begin_define
define|#
directive|define
name|FDEF
value|010
end_define

begin_define
define|#
directive|define
name|FLOOP
value|020
end_define

begin_comment
comment|/*  * Flags used for return status  */
end_comment

begin_define
define|#
directive|define
name|RETVAL
value|1
end_define

begin_define
define|#
directive|define
name|NRETVAL
value|2
end_define

begin_define
define|#
directive|define
name|NONAME
value|040000
end_define

begin_comment
comment|/* marks constant w/o name field */
end_comment

begin_define
define|#
directive|define
name|NOOFFSET
value|(-10201)
end_define

begin_comment
comment|/* mark an offset which is undefined */
end_comment

end_unit

