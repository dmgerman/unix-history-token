begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* headers */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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
file|<stdarg.h>
end_include

begin_comment
comment|/* defines */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ALIGN_T
end_ifndef

begin_typedef
typedef|typedef
name|long
name|ALIGN_T
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIG_ATOMIC_T
end_ifndef

begin_define
define|#
directive|define
name|SIG_ATOMIC_T
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEFAULTPATH
value|"", "/bin", "/usr/bin"
end_define

begin_comment
comment|/* datatypes */
end_comment

begin_typedef
typedef|typedef
name|void
name|builtin_t
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Block
name|Block
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Dup
name|Dup
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Estack
name|Estack
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Function
name|Function
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Hq
name|Hq
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Htab
name|Htab
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Jbwrap
name|Jbwrap
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|List
name|List
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Node
name|Node
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Pipe
name|Pipe
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Redir
name|Redir
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Rq
name|Rq
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Variable
name|Variable
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Word
name|Word
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Format
name|Format
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|Edata
name|Edata
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|nodetype
block|{
name|nAndalso
block|,
name|nAssign
block|,
name|nBackq
block|,
name|nBang
block|,
name|nBody
block|,
name|nCbody
block|,
name|nNowait
block|,
name|nBrace
block|,
name|nConcat
block|,
name|nCount
block|,
name|nElse
block|,
name|nFlat
block|,
name|nDup
block|,
name|nEpilog
block|,
name|nNewfn
block|,
name|nForin
block|,
name|nIf
block|,
name|nQword
block|,
name|nOrelse
block|,
name|nPipe
block|,
name|nPre
block|,
name|nRedir
block|,
name|nRmfn
block|,
name|nArgs
block|,
name|nSubshell
block|,
name|nCase
block|,
name|nSwitch
block|,
name|nMatch
block|,
name|nVar
block|,
name|nVarsub
block|,
name|nWhile
block|,
name|nWord
block|,
name|nLappend
block|,
name|nNmpipe
block|}
name|nodetype
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|ecodes
block|{
name|eError
block|,
name|eBreak
block|,
name|eReturn
block|,
name|eVarstack
block|,
name|eArena
block|,
name|eFifo
block|,
name|eFd
block|}
name|ecodes
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|bool
block|{
name|FALSE
block|,
name|TRUE
block|}
name|bool
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|inputtype
block|{
name|iFd
block|,
name|iString
block|}
name|inputtype
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|redirtype
block|{
name|rFrom
block|,
name|rCreate
block|,
name|rAppend
block|,
name|rHeredoc
block|,
name|rHerestring
block|}
name|redirtype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|bool
function_decl|(
modifier|*
name|Conv
function_decl|)
parameter_list|(
name|Format
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_union
union|union
name|Edata
block|{
name|Jbwrap
modifier|*
name|jb
decl_stmt|;
name|Block
modifier|*
name|b
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|fd
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|Estack
block|{
name|ecodes
name|e
decl_stmt|;
name|bool
name|interactive
decl_stmt|;
name|Edata
name|data
decl_stmt|;
name|Estack
modifier|*
name|prev
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|List
block|{
name|char
modifier|*
name|w
decl_stmt|,
modifier|*
name|m
decl_stmt|;
name|List
modifier|*
name|n
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Node
block|{
name|nodetype
name|type
decl_stmt|;
union|union
block|{
name|char
modifier|*
name|s
decl_stmt|;
name|int
name|i
decl_stmt|;
name|Node
modifier|*
name|p
decl_stmt|;
block|}
name|u
index|[
literal|4
index|]
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Pipe
block|{
name|int
name|left
decl_stmt|,
name|right
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Dup
block|{
name|redirtype
name|type
decl_stmt|;
name|int
name|left
decl_stmt|,
name|right
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Redir
block|{
name|redirtype
name|type
decl_stmt|;
name|int
name|fd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Word
block|{
name|char
modifier|*
name|w
decl_stmt|,
modifier|*
name|m
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Rq
block|{
name|Node
modifier|*
name|r
decl_stmt|;
name|struct
name|Rq
modifier|*
name|n
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Function
block|{
name|Node
modifier|*
name|def
decl_stmt|;
name|char
modifier|*
name|extdef
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Variable
block|{
name|List
modifier|*
name|def
decl_stmt|;
name|char
modifier|*
name|extdef
decl_stmt|;
name|Variable
modifier|*
name|n
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Htab
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|void
modifier|*
name|p
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Format
block|{
comment|/* for the formatting routines */
name|va_list
name|args
decl_stmt|;
name|long
name|flags
decl_stmt|,
name|f1
decl_stmt|,
name|f2
decl_stmt|;
comment|/* for the buffer maintainence routines */
name|char
modifier|*
name|buf
decl_stmt|,
modifier|*
name|bufbegin
decl_stmt|,
modifier|*
name|bufend
decl_stmt|;
name|int
name|flushed
decl_stmt|;
name|void
function_decl|(
modifier|*
name|grow
function_decl|)
parameter_list|(
name|Format
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
union|union
block|{
name|int
name|n
decl_stmt|;
name|void
modifier|*
name|p
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* Format->flags values */
end_comment

begin_enum
enum|enum
block|{
name|FMT_long
init|=
literal|1
block|,
comment|/* %l */
name|FMT_short
init|=
literal|2
block|,
comment|/* %h */
name|FMT_unsigned
init|=
literal|4
block|,
comment|/* %u */
name|FMT_zeropad
init|=
literal|8
block|,
comment|/* %0 */
name|FMT_leftside
init|=
literal|16
block|,
comment|/* %- */
name|FMT_altform
init|=
literal|32
block|,
comment|/* %# */
name|FMT_f1set
init|=
literal|64
block|,
comment|/* %<n> */
name|FMT_f2set
init|=
literal|128
comment|/* %.<n> */
block|}
enum|;
end_enum

begin_comment
comment|/* macros */
end_comment

begin_define
define|#
directive|define
name|EOF
value|(-1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|a2u
parameter_list|(
name|x
parameter_list|)
value|n2u(x, 10)
end_define

begin_define
define|#
directive|define
name|o2u
parameter_list|(
name|x
parameter_list|)
value|n2u(x, 8)
end_define

begin_define
define|#
directive|define
name|arraysize
parameter_list|(
name|a
parameter_list|)
value|((int)(sizeof(a)/sizeof(*a)))
end_define

begin_define
define|#
directive|define
name|enew
parameter_list|(
name|x
parameter_list|)
value|((x *) ealloc(sizeof(x)))
end_define

begin_define
define|#
directive|define
name|ecpy
parameter_list|(
name|x
parameter_list|)
value|strcpy((char *) ealloc(strlen(x) + 1), x)
end_define

begin_define
define|#
directive|define
name|lookup_fn
parameter_list|(
name|s
parameter_list|)
value|((Function *) lookup(s, fp))
end_define

begin_define
define|#
directive|define
name|lookup_var
parameter_list|(
name|s
parameter_list|)
value|((Variable *) lookup(s, vp))
end_define

begin_define
define|#
directive|define
name|nnew
parameter_list|(
name|x
parameter_list|)
value|((x *) nalloc(sizeof(x)))
end_define

begin_define
define|#
directive|define
name|ncpy
parameter_list|(
name|x
parameter_list|)
value|(strcpy((char *) nalloc(strlen(x) + 1), x))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|offsetof
end_ifndef

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|t
parameter_list|,
name|m
parameter_list|)
value|((size_t) (((char *)&((t *) 0)->m) - (char *)0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|streq
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(*(x) == *(y)&& strcmp(x, y) == 0)
end_define

begin_define
define|#
directive|define
name|conststrlen
parameter_list|(
name|x
parameter_list|)
value|(sizeof (x) - 1)
end_define

begin_comment
comment|/* rc prototypes */
end_comment

begin_comment
comment|/* main.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|prompt
decl_stmt|,
modifier|*
name|prompt2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Rq
modifier|*
name|redirq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|dashdee
decl_stmt|,
name|dashee
decl_stmt|,
name|dashvee
decl_stmt|,
name|dashex
decl_stmt|,
name|dashell
decl_stmt|,
name|dasheye
decl_stmt|,
name|dashen
decl_stmt|,
name|dashpee
decl_stmt|,
name|interactive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rc_pid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* builtins.c */
end_comment

begin_function_decl
specifier|extern
name|builtin_t
modifier|*
name|isbuiltin
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|b_exec
argument_list|(
name|char
operator|*
operator|*
argument_list|)
decl_stmt|,
name|funcall
argument_list|(
name|char
operator|*
operator|*
argument_list|)
decl_stmt|,
name|b_dot
argument_list|(
name|char
operator|*
operator|*
argument_list|)
decl_stmt|,
name|b_builtin
argument_list|(
name|char
operator|*
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|which
parameter_list|(
name|char
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* except.c */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|nl_on_intr
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|bool
name|outstanding_cmdarg
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_cmdarg
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rc_raise
parameter_list|(
name|ecodes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|except
parameter_list|(
name|ecodes
parameter_list|,
name|Edata
parameter_list|,
name|Estack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unexcept
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rc_error
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sigint
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* exec.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|exec
parameter_list|(
name|List
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doredirs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* footobar.c */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|fun2str
parameter_list|(
name|char
modifier|*
parameter_list|,
name|Node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|list2str
parameter_list|(
name|char
modifier|*
parameter_list|,
name|List
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|list2array
parameter_list|(
name|List
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|get_name
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|List
modifier|*
name|parse_var
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Node
modifier|*
name|parse_fn
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|initprint
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rc_exit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* here for odd reasons; user-defined signal handlers are kept in fn.c */
end_comment

begin_comment
comment|/* getopt.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|rc_getopt
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|rc_optind
decl_stmt|,
name|rc_opterr
decl_stmt|,
name|rc_optopt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rc_optarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* glob.c */
end_comment

begin_function_decl
specifier|extern
name|bool
name|lmatch
parameter_list|(
name|List
modifier|*
parameter_list|,
name|List
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|List
modifier|*
name|glob
parameter_list|(
name|List
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* glom.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|assign
parameter_list|(
name|List
modifier|*
parameter_list|,
name|List
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qredir
parameter_list|(
name|Node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|List
modifier|*
name|append
parameter_list|(
name|List
modifier|*
parameter_list|,
name|List
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|List
modifier|*
name|flatten
parameter_list|(
name|List
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|List
modifier|*
name|glom
parameter_list|(
name|Node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|List
modifier|*
name|concat
parameter_list|(
name|List
modifier|*
parameter_list|,
name|List
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|List
modifier|*
name|varsub
parameter_list|(
name|List
modifier|*
parameter_list|,
name|List
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|List
modifier|*
name|word
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* hash.c */
end_comment

begin_decl_stmt
specifier|extern
name|Htab
modifier|*
name|fp
decl_stmt|,
modifier|*
name|vp
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
modifier|*
name|lookup
parameter_list|(
name|char
modifier|*
parameter_list|,
name|Htab
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Function
modifier|*
name|get_fn_place
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|List
modifier|*
name|varlookup
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Node
modifier|*
name|fnlookup
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Variable
modifier|*
name|get_var_place
parameter_list|(
name|char
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|varassign_string
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|makeenv
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|fnlookup_string
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|varlookup_string
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|alias
parameter_list|(
name|char
modifier|*
parameter_list|,
name|List
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|starassign
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|delete_fn
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|delete_var
parameter_list|(
name|char
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fnassign
parameter_list|(
name|char
modifier|*
parameter_list|,
name|Node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fnassign_string
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fnrm
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|initenv
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|inithash
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setsigdefaults
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|inithandler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|varassign
parameter_list|(
name|char
modifier|*
parameter_list|,
name|List
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|varrm
parameter_list|(
name|char
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|whatare_all_vars
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|whatare_all_signals
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|prettyprint_var
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|List
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|prettyprint_fn
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|Node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* heredoc.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|heredoc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|qdoc
parameter_list|(
name|Node
modifier|*
parameter_list|,
name|Node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|Hq
modifier|*
name|hq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|initinput
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Node
modifier|*
name|parseline
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gchar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ugchar
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Node
modifier|*
name|doit
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|flushu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pushfd
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pushstring
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|popinput
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|closefds
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|last
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|rcrc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lex.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|yylex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|inityy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|yyerror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scanerror
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_prompt2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|nw
index|[]
decl_stmt|,
name|dnw
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|listfree
parameter_list|(
name|List
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|List
modifier|*
name|listcpy
parameter_list|(
name|List
modifier|*
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|size_t
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|listlen
parameter_list|(
name|List
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|listnel
parameter_list|(
name|List
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* match.c */
end_comment

begin_function_decl
specifier|extern
name|bool
name|match
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* alloc.c */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|ealloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|erealloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|efree
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Block
modifier|*
name|newblock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|nalloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nfree
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|restoreblock
parameter_list|(
name|Block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* open.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|rc_open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|redirtype
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* print.c */
end_comment

begin_comment
comment|/*    The following prototype should be: extern Conv fmtinstall(int, Conv);    but this freaks out SGI's compiler under IRIX3.3.2 */
end_comment

begin_extern
extern|extern bool (*fmtinstall(int
operator|,
extern|bool (*
end_extern

begin_expr_stmt
unit|)
operator|(
name|Format
operator|*
operator|,
name|int
operator|)
end_expr_stmt

begin_expr_stmt
unit|))
operator|(
name|Format
operator|*
operator|,
name|int
operator|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|extern
name|int
name|printfmt
parameter_list|(
name|Format
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fmtprint
parameter_list|(
name|Format
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fmtappend
parameter_list|(
name|Format
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fmtcat
parameter_list|(
name|Format
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fprint
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|mprint
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|nprint
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*    the following macro should by rights be coded as an expression, not    a statement, but certain compilers (notably DEC) have trouble with    void expressions inside the ?: operator. (sheesh, give me a break!) */
end_comment

begin_define
define|#
directive|define
name|fmtputc
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|)
value|{\ 	if ((f)->buf>= (f)->bufend)\ 		(*(f)->grow)((f), (size_t)1);\ 	*(f)->buf++ = (c);\ }
end_define

begin_comment
comment|/* y.tab.c (parse.y) */
end_comment

begin_decl_stmt
specifier|extern
name|Node
modifier|*
name|parsetree
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|yyparse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|initparse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* redir.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|doredirs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* signal.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|initsignal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|catcher
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sigchk
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern void (*rc_signal(int
operator|,
extern|void (*
end_extern

begin_expr_stmt
unit|)
operator|(
name|int
operator|)
end_expr_stmt

begin_expr_stmt
unit|))
operator|(
name|int
operator|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|sighandlers
index|[]
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|volatile
name|SIG_ATOMIC_T
name|slow
decl_stmt|,
name|interrupt_happened
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SIGCHK
value|sigchk()
end_define

begin_comment
comment|/* status.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|istrue
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getstatus
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setstatus
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|List
modifier|*
name|sgetstatus
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setpipestatus
parameter_list|(
name|int
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|statprint
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ssetstatus
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* tree.c */
end_comment

begin_function_decl
specifier|extern
name|Node
modifier|*
name|mk
parameter_list|(
name|int
comment|/*nodetype*/
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Node
modifier|*
name|treecpy
parameter_list|(
name|Node
modifier|*
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|size_t
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|treefree
parameter_list|(
name|Node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* utils.c */
end_comment

begin_function_decl
specifier|extern
name|bool
name|isabsolute
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|n2u
parameter_list|(
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rc_read
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mvfd
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|starstrcmp
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pr_error
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|clear
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|panic
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|uerror
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|writeall
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* wait.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|rc_fork
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rc_wait4
parameter_list|(
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|List
modifier|*
name|sgetapids
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|waitforall
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|bool
name|forked
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* walk.c */
end_comment

begin_function_decl
specifier|extern
name|bool
name|walk
parameter_list|(
name|Node
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|bool
name|cond
decl_stmt|;
end_decl_stmt

end_unit

