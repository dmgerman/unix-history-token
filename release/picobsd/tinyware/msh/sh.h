begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_comment
comment|/* Need a way to have void used for ANSI, nothing for K&R. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ANSI
end_ifndef

begin_undef
undef|#
directive|undef
name|_VOID
end_undef

begin_define
define|#
directive|define
name|_VOID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* -------- sh.h -------- */
end_comment

begin_comment
comment|/*  * shell  */
end_comment

begin_define
define|#
directive|define
name|LINELIM
value|2100
end_define

begin_define
define|#
directive|define
name|NPUSH
value|8
end_define

begin_comment
comment|/* limit to input nesting */
end_comment

begin_define
define|#
directive|define
name|NOFILE
value|20
end_define

begin_comment
comment|/* Number of open files */
end_comment

begin_define
define|#
directive|define
name|NUFILE
value|10
end_define

begin_comment
comment|/* Number of user-accessible files */
end_comment

begin_define
define|#
directive|define
name|FDBASE
value|10
end_define

begin_comment
comment|/* First file usable by Shell */
end_comment

begin_comment
comment|/*  * values returned by wait  */
end_comment

begin_define
define|#
directive|define
name|WAITSIG
parameter_list|(
name|s
parameter_list|)
value|((s)&0177)
end_define

begin_define
define|#
directive|define
name|WAITVAL
parameter_list|(
name|s
parameter_list|)
value|(((s)>>8)&0377)
end_define

begin_define
define|#
directive|define
name|WAITCORE
parameter_list|(
name|s
parameter_list|)
value|(((s)&0200)!=0)
end_define

begin_comment
comment|/*  * library and system defintions  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_typedef
typedef|typedef
name|void
name|xint
typedef|;
end_typedef

begin_comment
comment|/* base type of jmp_buf, for not broken compilers */
end_comment

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
modifier|*
name|xint
typedef|;
end_typedef

begin_comment
comment|/* base type of jmp_buf, for broken compilers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * shell components  */
end_comment

begin_comment
comment|/* #include "area.h" */
end_comment

begin_comment
comment|/* #include "word.h" */
end_comment

begin_comment
comment|/* #include "io.h" */
end_comment

begin_comment
comment|/* #include "var.h" */
end_comment

begin_define
define|#
directive|define
name|QUOTE
value|0200
end_define

begin_define
define|#
directive|define
name|NOBLOCK
value|((struct op *)NULL)
end_define

begin_define
define|#
directive|define
name|NOWORD
value|((char *)NULL)
end_define

begin_define
define|#
directive|define
name|NOWORDS
value|((char **)NULL)
end_define

begin_define
define|#
directive|define
name|NOPIPE
value|((int *)NULL)
end_define

begin_comment
comment|/*  * Description of a command or an operation on commands.  * Might eventually use a union.  */
end_comment

begin_struct
struct|struct
name|op
block|{
name|int
name|type
decl_stmt|;
comment|/* operation type, see below */
name|char
modifier|*
modifier|*
name|words
decl_stmt|;
comment|/* arguments to a command */
name|struct
name|ioword
modifier|*
modifier|*
name|ioact
decl_stmt|;
comment|/* IO actions (eg,<>>>) */
name|struct
name|op
modifier|*
name|left
decl_stmt|;
name|struct
name|op
modifier|*
name|right
decl_stmt|;
name|char
modifier|*
name|str
decl_stmt|;
comment|/* identifier for case and for */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TCOM
value|1
end_define

begin_comment
comment|/* command */
end_comment

begin_define
define|#
directive|define
name|TPAREN
value|2
end_define

begin_comment
comment|/* (c-list) */
end_comment

begin_define
define|#
directive|define
name|TPIPE
value|3
end_define

begin_comment
comment|/* a | b */
end_comment

begin_define
define|#
directive|define
name|TLIST
value|4
end_define

begin_comment
comment|/* a [&;] b */
end_comment

begin_define
define|#
directive|define
name|TOR
value|5
end_define

begin_comment
comment|/* || */
end_comment

begin_define
define|#
directive|define
name|TAND
value|6
end_define

begin_comment
comment|/*&& */
end_comment

begin_define
define|#
directive|define
name|TFOR
value|7
end_define

begin_define
define|#
directive|define
name|TDO
value|8
end_define

begin_define
define|#
directive|define
name|TCASE
value|9
end_define

begin_define
define|#
directive|define
name|TIF
value|10
end_define

begin_define
define|#
directive|define
name|TWHILE
value|11
end_define

begin_define
define|#
directive|define
name|TUNTIL
value|12
end_define

begin_define
define|#
directive|define
name|TELIF
value|13
end_define

begin_define
define|#
directive|define
name|TPAT
value|14
end_define

begin_comment
comment|/* pattern in case */
end_comment

begin_define
define|#
directive|define
name|TBRACE
value|15
end_define

begin_comment
comment|/* {c-list} */
end_comment

begin_define
define|#
directive|define
name|TASYNC
value|16
end_define

begin_comment
comment|/* c& */
end_comment

begin_comment
comment|/*  * actions determining the environment of a process  */
end_comment

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|i
parameter_list|)
value|(1<<(i))
end_define

begin_define
define|#
directive|define
name|FEXEC
value|BIT(0)
end_define

begin_comment
comment|/* execute without forking */
end_comment

begin_comment
comment|/*  * flags to control evaluation of words  */
end_comment

begin_define
define|#
directive|define
name|DOSUB
value|1
end_define

begin_comment
comment|/* interpret $, `, and quotes */
end_comment

begin_define
define|#
directive|define
name|DOBLANK
value|2
end_define

begin_comment
comment|/* perform blank interpretation */
end_comment

begin_define
define|#
directive|define
name|DOGLOB
value|4
end_define

begin_comment
comment|/* interpret [?* */
end_comment

begin_define
define|#
directive|define
name|DOKEY
value|8
end_define

begin_comment
comment|/* move words with `=' to 2nd arg. list */
end_comment

begin_define
define|#
directive|define
name|DOTRIM
value|16
end_define

begin_comment
comment|/* trim resulting string */
end_comment

begin_define
define|#
directive|define
name|DOALL
value|(DOSUB|DOBLANK|DOGLOB|DOKEY|DOTRIM)
end_define

begin_decl_stmt
name|Extern
name|char
modifier|*
modifier|*
name|dolv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Extern
name|int
name|dolc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Extern
name|int
name|exstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Extern
name|char
name|gflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Extern
name|int
name|talking
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interactive (talking-type wireless) */
end_comment

begin_decl_stmt
name|Extern
name|int
name|execflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Extern
name|int
name|multiline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* \n changed to ; */
end_comment

begin_decl_stmt
name|Extern
name|struct
name|op
modifier|*
name|outtree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* result from parser */
end_comment

begin_decl_stmt
name|Extern
name|xint
modifier|*
name|failpt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Extern
name|xint
modifier|*
name|errpt
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|brkcon
block|{
name|jmp_buf
name|brkpt
decl_stmt|;
name|struct
name|brkcon
modifier|*
name|nextlev
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|Extern
name|struct
name|brkcon
modifier|*
name|brklist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Extern
name|int
name|isbreak
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * redirection  */
end_comment

begin_struct
struct|struct
name|ioword
block|{
name|short
name|io_unit
decl_stmt|;
comment|/* unit affected */
name|short
name|io_flag
decl_stmt|;
comment|/* action (below) */
name|char
modifier|*
name|io_name
decl_stmt|;
comment|/* file name */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IOREAD
value|1
end_define

begin_comment
comment|/*< */
end_comment

begin_define
define|#
directive|define
name|IOHERE
value|2
end_define

begin_comment
comment|/*<< (here file) */
end_comment

begin_define
define|#
directive|define
name|IOWRITE
value|4
end_define

begin_comment
comment|/*> */
end_comment

begin_define
define|#
directive|define
name|IOCAT
value|8
end_define

begin_comment
comment|/*>> */
end_comment

begin_define
define|#
directive|define
name|IOXHERE
value|16
end_define

begin_comment
comment|/* ${}, ` in<< */
end_comment

begin_define
define|#
directive|define
name|IODUP
value|32
end_define

begin_comment
comment|/*>&digit */
end_comment

begin_define
define|#
directive|define
name|IOCLOSE
value|64
end_define

begin_comment
comment|/*>&- */
end_comment

begin_define
define|#
directive|define
name|IODEFAULT
value|(-1)
end_define

begin_comment
comment|/* token for default IO unit */
end_comment

begin_decl_stmt
name|Extern
name|struct
name|wdblock
modifier|*
name|wdlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Extern
name|struct
name|wdblock
modifier|*
name|iolist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * parsing& execution environment  */
end_comment

begin_struct
specifier|extern
struct|struct
name|env
block|{
name|char
modifier|*
name|linep
decl_stmt|;
name|struct
name|io
modifier|*
name|iobase
decl_stmt|;
name|struct
name|io
modifier|*
name|iop
decl_stmt|;
name|xint
modifier|*
name|errpt
decl_stmt|;
name|int
name|iofd
decl_stmt|;
name|struct
name|env
modifier|*
name|oenv
decl_stmt|;
block|}
name|e
struct|;
end_struct

begin_comment
comment|/*  * flags:  * -e: quit on error  * -k: look for name=value everywhere on command line  * -n: no execution  * -t: exit after reading and executing one command  * -v: echo as read  * -x: trace  * -u: unset variables net diagnostic  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|null
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* null value for variable */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|intr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interrupt pending */
end_comment

begin_decl_stmt
name|Extern
name|char
modifier|*
name|trap
index|[
name|_NSIG
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Extern
name|char
name|ourtrap
index|[
name|_NSIG
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Extern
name|int
name|trapset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trap pending */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|heedint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* heed interrupt signals */
end_comment

begin_decl_stmt
name|Extern
name|int
name|yynerrs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* yacc */
end_comment

begin_decl_stmt
name|Extern
name|char
name|line
index|[
name|LINELIM
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|elinep
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * other functions  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_expr_stmt
name|int
argument_list|(
operator|*
name|inbuilt
argument_list|(
name|char
operator|*
name|s
argument_list|)
argument_list|)
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|int
argument_list|(
operator|*
name|inbuilt
argument_list|()
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|_PROTOTYPE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x ## y
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
name|rexecve
argument_list|,
operator|(
name|char
operator|*
name|c
operator|,
name|char
operator|*
operator|*
name|v
operator|,
name|char
operator|*
operator|*
name|envp
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
name|space
argument_list|,
operator|(
name|int
name|n
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
name|strsave
argument_list|,
operator|(
name|char
operator|*
name|s
operator|,
name|int
name|a
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
name|evalstr
argument_list|,
operator|(
name|char
operator|*
name|cp
operator|,
name|int
name|f
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
name|putn
argument_list|,
operator|(
name|int
name|n
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
name|itoa
argument_list|,
operator|(
name|unsigned
name|u
operator|,
name|int
name|n
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
name|unquote
argument_list|,
operator|(
name|char
operator|*
name|as
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
expr|struct
name|var
operator|*
name|lookup
argument_list|,
operator|(
name|char
operator|*
name|n
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int rlookup
argument_list|,
argument|(char *n )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
expr|struct
name|wdblock
operator|*
name|glob
argument_list|,
operator|(
name|char
operator|*
name|cp
operator|,
expr|struct
name|wdblock
operator|*
name|wb
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int subgetc
argument_list|,
argument|(int ec , int quoted )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
operator|*
name|makenv
argument_list|,
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
operator|*
name|eval
argument_list|,
operator|(
name|char
operator|*
operator|*
name|ap
operator|,
name|int
name|f
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int setstatus
argument_list|,
argument|(int s )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int waitfor
argument_list|,
argument|(int lastpid , int canintr )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void onintr
argument_list|,
argument|(int s )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* SIGINT handler */
end_comment

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int newenv
argument_list|,
argument|(int f )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void quitenv
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void err
argument_list|,
argument|(char *s )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int anys
argument_list|,
argument|(char *s1 , char *s2 )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int any
argument_list|,
argument|(int c , char *s )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void next
argument_list|,
argument|(int f )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void setdash
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void onecommand
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void runtrap
argument_list|,
argument|(int i )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void xfree
argument_list|,
argument|(char *s )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int letter
argument_list|,
argument|(int c )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int digit
argument_list|,
argument|(int c )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int letnum
argument_list|,
argument|(int c )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int gmatch
argument_list|,
argument|(char *s , char *p )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * error handling  */
end_comment

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void leave
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* abort shell (or fail in subshell) */
end_comment

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void fail
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* fail but return to process next command */
end_comment

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void warn
argument_list|,
argument|(char *s )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void sig
argument_list|,
argument|(int i )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* default signal handler */
end_comment

begin_comment
comment|/* -------- var.h -------- */
end_comment

begin_struct
struct|struct
name|var
block|{
name|char
modifier|*
name|value
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|var
modifier|*
name|next
decl_stmt|;
name|char
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|COPYV
value|1
end_define

begin_comment
comment|/* flag to setval, suggesting copy */
end_comment

begin_define
define|#
directive|define
name|RONLY
value|01
end_define

begin_comment
comment|/* variable is read-only */
end_comment

begin_define
define|#
directive|define
name|EXPORT
value|02
end_define

begin_comment
comment|/* variable is to be exported */
end_comment

begin_define
define|#
directive|define
name|GETCELL
value|04
end_define

begin_comment
comment|/* name& value space was got with getcell */
end_comment

begin_decl_stmt
name|Extern
name|struct
name|var
modifier|*
name|vlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dictionary */
end_comment

begin_decl_stmt
name|Extern
name|struct
name|var
modifier|*
name|homedir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* home directory */
end_comment

begin_decl_stmt
name|Extern
name|struct
name|var
modifier|*
name|prompt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* main prompt */
end_comment

begin_decl_stmt
name|Extern
name|struct
name|var
modifier|*
name|cprompt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* continuation prompt */
end_comment

begin_decl_stmt
name|Extern
name|struct
name|var
modifier|*
name|path
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* search path for commands */
end_comment

begin_decl_stmt
name|Extern
name|struct
name|var
modifier|*
name|shell
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* shell to interpret command files */
end_comment

begin_decl_stmt
name|Extern
name|struct
name|var
modifier|*
name|ifs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* field separators */
end_comment

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int yyparse
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
expr|struct
name|var
operator|*
name|lookup
argument_list|,
operator|(
name|char
operator|*
name|n
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void setval
argument_list|,
argument|(struct var *vp , char *val )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void nameval
argument_list|,
argument|(struct var *vp , char *val , char *name )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void export
argument_list|,
argument|(struct var *vp )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void ronly
argument_list|,
argument|(struct var *vp )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int isassign
argument_list|,
argument|(char *s )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int checkname
argument_list|,
argument|(char *cp )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int assign
argument_list|,
argument|(char *s , int cf )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void putvlist
argument_list|,
argument|(int f , int out )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int eqname
argument_list|,
argument|(char *n1 , char *n2 )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int execute
argument_list|,
argument|(struct op *t , int *pin , int *pout , int act )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* -------- io.h -------- */
end_comment

begin_comment
comment|/* io buffer */
end_comment

begin_struct
struct|struct
name|iobuf
block|{
name|unsigned
name|id
decl_stmt|;
comment|/* buffer id */
name|char
name|buf
index|[
literal|512
index|]
decl_stmt|;
comment|/* buffer */
name|char
modifier|*
name|bufp
decl_stmt|;
comment|/* pointer into buffer */
name|char
modifier|*
name|ebufp
decl_stmt|;
comment|/* pointer to end of buffer */
block|}
struct|;
end_struct

begin_comment
comment|/* possible arguments to an IO function */
end_comment

begin_struct
struct|struct
name|ioarg
block|{
name|char
modifier|*
name|aword
decl_stmt|;
name|char
modifier|*
modifier|*
name|awordlist
decl_stmt|;
name|int
name|afile
decl_stmt|;
comment|/* file descriptor */
name|unsigned
name|afid
decl_stmt|;
comment|/* buffer id */
name|long
name|afpos
decl_stmt|;
comment|/* file position */
name|struct
name|iobuf
modifier|*
name|afbuf
decl_stmt|;
comment|/* buffer for this file */
block|}
struct|;
end_struct

begin_decl_stmt
name|Extern
name|struct
name|ioarg
name|ioargstack
index|[
name|NPUSH
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AFID_NOBUF
value|(~0)
end_define

begin_define
define|#
directive|define
name|AFID_ID
value|0
end_define

begin_comment
comment|/* an input generator's state */
end_comment

begin_struct
struct|struct
name|io
block|{
name|int
function_decl|(
modifier|*
name|iofn
function_decl|)
parameter_list|(
name|_VOID
parameter_list|)
function_decl|;
name|struct
name|ioarg
modifier|*
name|argp
decl_stmt|;
name|int
name|peekc
decl_stmt|;
name|char
name|prev
decl_stmt|;
comment|/* previous character read by readc() */
name|char
name|nlcount
decl_stmt|;
comment|/* for `'s */
name|char
name|xchar
decl_stmt|;
comment|/* for `'s */
name|char
name|task
decl_stmt|;
comment|/* reason for pushed IO */
block|}
struct|;
end_struct

begin_decl_stmt
name|Extern
name|struct
name|io
name|iostack
index|[
name|NPUSH
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|XOTHER
value|0
end_define

begin_comment
comment|/* none of the below */
end_comment

begin_define
define|#
directive|define
name|XDOLL
value|1
end_define

begin_comment
comment|/* expanding ${} */
end_comment

begin_define
define|#
directive|define
name|XGRAVE
value|2
end_define

begin_comment
comment|/* expanding `'s */
end_comment

begin_define
define|#
directive|define
name|XIO
value|3
end_define

begin_comment
comment|/* file IO */
end_comment

begin_comment
comment|/* in substitution */
end_comment

begin_define
define|#
directive|define
name|INSUB
parameter_list|()
value|(e.iop->task == XGRAVE || e.iop->task == XDOLL)
end_define

begin_comment
comment|/*  * input generators for IO structure  */
end_comment

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int nlchar
argument_list|,
argument|(struct ioarg *ap )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int strchar
argument_list|,
argument|(struct ioarg *ap )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int qstrchar
argument_list|,
argument|(struct ioarg *ap )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int filechar
argument_list|,
argument|(struct ioarg *ap )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int herechar
argument_list|,
argument|(struct ioarg *ap )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int linechar
argument_list|,
argument|(struct ioarg *ap )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int gravechar
argument_list|,
argument|(struct ioarg *ap , struct io *iop )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int qgravechar
argument_list|,
argument|(struct ioarg *ap , struct io *iop )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int dolchar
argument_list|,
argument|(struct ioarg *ap )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int wdchar
argument_list|,
argument|(struct ioarg *ap )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void scraphere
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void freehere
argument_list|,
argument|(int area )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void gethere
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void markhere
argument_list|,
argument|(char *s , struct ioword *iop )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int herein
argument_list|,
argument|(char *hname , int xdoll )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int run
argument_list|,
argument|(struct ioarg *argp , int (*f)(_VOID))
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * IO functions  */
end_comment

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int eofc
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int getc
argument_list|,
argument|(int ec )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int readc
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void unget
argument_list|,
argument|(int c )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void ioecho
argument_list|,
argument|(int c )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void prs
argument_list|,
argument|(char *s )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void putc
argument_list|,
argument|(int c )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void prn
argument_list|,
argument|(unsigned u )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void closef
argument_list|,
argument|(int i )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void closeall
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * IO control  */
end_comment

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void pushio
argument_list|,
argument|(struct ioarg *argp , int (*fn)(_VOID))
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int remap
argument_list|,
argument|(int fd )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int openpipe
argument_list|,
argument|(int *pv )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void closepipe
argument_list|,
argument|(int *pv )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
expr|struct
name|io
operator|*
name|setbase
argument_list|,
operator|(
expr|struct
name|io
operator|*
name|ip
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ioarg
name|temparg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temporary for PUSHIO */
end_comment

begin_define
define|#
directive|define
name|PUSHIO
parameter_list|(
name|what
parameter_list|,
name|arg
parameter_list|,
name|gen
parameter_list|)
value|((temparg.what = (arg)),pushio(&temparg,(gen)))
end_define

begin_define
define|#
directive|define
name|RUN
parameter_list|(
name|what
parameter_list|,
name|arg
parameter_list|,
name|gen
parameter_list|)
value|((temparg.what = (arg)), run(&temparg,(gen)))
end_define

begin_comment
comment|/* -------- word.h -------- */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WORD_H
end_ifndef

begin_define
define|#
directive|define
name|WORD_H
value|1
end_define

begin_struct
struct|struct
name|wdblock
block|{
name|short
name|w_bsize
decl_stmt|;
name|short
name|w_nword
decl_stmt|;
comment|/* bounds are arbitrary */
name|char
modifier|*
name|w_words
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
expr|struct
name|wdblock
operator|*
name|addword
argument_list|,
operator|(
name|char
operator|*
name|wd
operator|,
expr|struct
name|wdblock
operator|*
name|wb
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
expr|struct
name|wdblock
operator|*
name|newword
argument_list|,
operator|(
name|int
name|nw
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
operator|*
name|getwords
argument_list|,
operator|(
expr|struct
name|wdblock
operator|*
name|wb
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* -------- area.h -------- */
end_comment

begin_comment
comment|/*  * storage allocation  */
end_comment

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
name|getcell
argument_list|,
operator|(
name|unsigned
name|nbytes
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void garbage
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void setarea
argument_list|,
argument|(char *cp , int a )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int getarea
argument_list|,
argument|(char *cp )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void freearea
argument_list|,
argument|(int a )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void freecell
argument_list|,
argument|(char *cp )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|Extern
name|int
name|areanum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current allocation area */
end_comment

begin_define
define|#
directive|define
name|NEW
parameter_list|(
name|type
parameter_list|)
value|(type *)getcell(sizeof(type))
end_define

begin_define
define|#
directive|define
name|DELETE
parameter_list|(
name|obj
parameter_list|)
value|freecell((char *)obj)
end_define

end_unit

