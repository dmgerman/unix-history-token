begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Initialization and error routines.  */
end_comment

begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_include
include|#
directive|include
file|"../h/gc.h"
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/times.h>
end_include

begin_define
define|#
directive|define
name|MAXHDRLN
value|100
end_define

begin_comment
comment|/* max len of #! line */
end_comment

begin_define
define|#
directive|define
name|MAXHDR
value|1024L
end_define

begin_comment
comment|/* size of autoloading header--!! must 					    agree with that in link/ilink.c */
end_comment

begin_decl_stmt
name|char
modifier|*
name|file
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* source program file name */
end_comment

begin_decl_stmt
name|int
name|line
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* source program line number */
end_comment

begin_decl_stmt
name|char
modifier|*
name|code
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interpreter code buffer */
end_comment

begin_decl_stmt
name|int
modifier|*
name|records
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to record procedure blocks */
end_comment

begin_decl_stmt
name|int
modifier|*
name|ftab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to record/field table */
end_comment

begin_decl_stmt
name|struct
name|descrip
modifier|*
name|globals
decl_stmt|,
modifier|*
name|eglobals
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to global variables */
end_comment

begin_decl_stmt
name|struct
name|descrip
modifier|*
name|gnames
decl_stmt|,
modifier|*
name|egnames
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to global variable names */
end_comment

begin_decl_stmt
name|struct
name|descrip
modifier|*
name|statics
decl_stmt|,
modifier|*
name|estatics
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to static variables */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ident
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to identifier table */
end_comment

begin_decl_stmt
name|int
modifier|*
name|monbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* monitor buffer for profiling */
end_comment

begin_decl_stmt
name|int
name|monres
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* resolution of monitor buffer */
end_comment

begin_decl_stmt
name|int
name|monsize
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of monitor buffer */
end_comment

begin_decl_stmt
name|int
name|numbufs
init|=
name|NUMBUF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of i/o buffers */
end_comment

begin_expr_stmt
name|char
argument_list|(
operator|*
name|bufs
argument_list|)
index|[
name|BUFSIZ
index|]
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* pointer to buffers */
end_comment

begin_decl_stmt
name|FILE
modifier|*
modifier|*
name|bufused
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to buffer use markers */
end_comment

begin_decl_stmt
name|int
name|nstacks
init|=
name|MAXSTACKS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial number of coexpr stacks */
end_comment

begin_decl_stmt
name|int
name|stksize
init|=
name|STACKSIZE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* coexpression stack size */
end_comment

begin_decl_stmt
name|int
name|dodump
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if non-zero, core dump on error */
end_comment

begin_decl_stmt
name|int
name|noerrbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if non-zero, DON'T buffer stderr */
end_comment

begin_decl_stmt
name|int
modifier|*
name|stacks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start of stack space */
end_comment

begin_decl_stmt
name|int
modifier|*
name|estacks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of stack space */
end_comment

begin_decl_stmt
name|int
modifier|*
name|esfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stack space free list pointer */
end_comment

begin_decl_stmt
name|int
name|ssize
init|=
name|MAXSTRSPACE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial string space size (bytes) */
end_comment

begin_decl_stmt
name|char
modifier|*
name|strings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start of string space */
end_comment

begin_decl_stmt
name|char
modifier|*
name|estrings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of string space */
end_comment

begin_decl_stmt
name|char
modifier|*
name|sfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string space free pointer */
end_comment

begin_decl_stmt
name|int
name|hpsize
init|=
name|MAXHEAPSIZE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial heap size (bytes) */
end_comment

begin_decl_stmt
name|char
modifier|*
name|hpbase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start of heap */
end_comment

begin_decl_stmt
name|char
modifier|*
name|maxheap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of heap storage */
end_comment

begin_decl_stmt
name|char
modifier|*
name|hpfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* heap free space pointer */
end_comment

begin_decl_stmt
name|unsigned
name|heapneed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stated need for heap space */
end_comment

begin_decl_stmt
name|unsigned
name|strneed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stated need for string space */
end_comment

begin_decl_stmt
name|struct
name|descrip
modifier|*
modifier|*
name|sqlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string qualifier list */
end_comment

begin_decl_stmt
name|struct
name|descrip
modifier|*
modifier|*
name|sqfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* s. q. list free pointer */
end_comment

begin_decl_stmt
name|struct
name|descrip
modifier|*
modifier|*
name|esqlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of s. q. list */
end_comment

begin_decl_stmt
name|struct
name|descrip
name|current
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current expression stack pointer */
end_comment

begin_comment
comment|/*  *&ascii cset, first 128 bits on, second 128 bits off.  */
end_comment

begin_decl_stmt
name|struct
name|b_cset
name|k_ascii
init|=
block|{
name|T_CSET
block|,
name|cset_display
argument_list|(
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *&cset cset, all 256 bits on.  */
end_comment

begin_decl_stmt
name|struct
name|b_cset
name|k_cset
init|=
block|{
name|T_CSET
block|,
name|cset_display
argument_list|(
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|,
argument|~
literal|0
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * File block for&errout.  */
end_comment

begin_decl_stmt
name|struct
name|b_file
name|k_errout
init|=
block|{
name|T_FILE
block|,
name|stderr
block|,
name|FS_WRITE
block|,
literal|7
block|,
comment|/*"&errout", */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * File block for&input.  */
end_comment

begin_decl_stmt
name|struct
name|b_file
name|k_input
init|=
block|{
name|T_FILE
block|,
name|stdin
block|,
name|FS_READ
block|,
literal|6
block|,
comment|/*"&input",*/
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * cset for&lcase, bits corresponding to lowercase letters are on.  */
end_comment

begin_decl_stmt
name|struct
name|b_cset
name|k_lcase
init|=
block|{
name|T_CSET
block|,
name|cset_display
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
argument|~
literal|01
argument_list|,
literal|03777
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|k_level
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*&level */
end_comment

begin_decl_stmt
name|struct
name|descrip
name|k_main
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*&main */
end_comment

begin_decl_stmt
name|int
name|k_pos
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*&pos */
end_comment

begin_comment
comment|/*  * File block for&output.  */
end_comment

begin_decl_stmt
name|struct
name|b_file
name|k_output
init|=
block|{
name|T_FILE
block|,
name|stdout
block|,
name|FS_WRITE
block|,
literal|7
block|,
comment|/*"&output",*/
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|k_random
init|=
literal|0L
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*&random */
end_comment

begin_decl_stmt
name|struct
name|descrip
name|k_subject
init|=
block|{
comment|/*&subject */
literal|0
block|,
comment|/*1,*/
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|k_trace
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * cset for&ucase, bits corresponding to uppercase characters are on.  */
end_comment

begin_decl_stmt
name|struct
name|b_cset
name|k_ucase
init|=
block|{
name|T_CSET
block|,
name|cset_display
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
argument|~
literal|01
argument_list|,
literal|03777
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * maps2 and maps3 are used by the map function as caches.  */
end_comment

begin_decl_stmt
name|struct
name|descrip
name|maps2
init|=
block|{
name|D_NULL
block|,
comment|/*0,*/
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|descrip
name|maps3
init|=
block|{
name|D_NULL
block|,
comment|/*0,*/
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|starttime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* starttime of job in milliseconds */
end_comment

begin_decl_stmt
name|struct
name|descrip
name|nulldesc
init|=
block|{
name|D_NULL
block|,
comment|/*0*/
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|descrip
name|zerodesc
init|=
block|{
name|D_INTEGER
block|,
comment|/*0*/
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|descrip
name|onedesc
init|=
block|{
name|D_INTEGER
block|,
comment|/*1*/
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|descrip
name|nullstr
init|=
block|{
literal|0
block|,
comment|/*""*/
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|descrip
name|blank
init|=
block|{
literal|1
block|,
comment|/*" "*/
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|descrip
name|letr
init|=
block|{
literal|1
block|,
comment|/*"r"*/
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|descrip
name|input
init|=
block|{
name|D_FILE
block|,
comment|/*&k_input*/
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|descrip
name|errout
init|=
block|{
name|D_FILE
block|,
comment|/*&k_errout*/
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|descrip
name|lcase
init|=
block|{
literal|26
block|,
comment|/*lowercase*/
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|descrip
name|ucase
init|=
block|{
literal|26
block|,
comment|/*uppercase*/
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|b_estack
name|mainhead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expression stack head for main */
end_comment

begin_comment
comment|/*  * init - initialize memory and prepare for Icon execution.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_macro
name|init
argument_list|(
argument|name
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
endif|VAX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PORT
end_ifdef

begin_macro
name|init
argument_list|(
argument|name
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
endif|PORT
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PDP11
end_ifdef

begin_macro
name|init
argument_list|(
argument|nargs
argument_list|,
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|int
name|nargs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|PDP11
end_endif

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|int
name|cbread
decl_stmt|;
name|int
name|f
decl_stmt|;
name|FILE
modifier|*
name|ufile
decl_stmt|;
name|char
name|uheader
index|[
name|MAXHDRLN
index|]
decl_stmt|;
name|int
name|directex
decl_stmt|;
comment|/*     * Interpretable file header     */
struct|struct
name|header
block|{
name|int
name|size
decl_stmt|;
comment|/* size of icode file */
name|int
name|trace
decl_stmt|;
comment|/* initial value of&trace */
name|int
name|records
decl_stmt|;
comment|/* records */
name|int
name|ftab
decl_stmt|;
comment|/* record field table */
name|int
name|globals
decl_stmt|;
comment|/* global array */
name|int
name|gnames
decl_stmt|;
comment|/* global name array */
name|int
name|statics
decl_stmt|;
comment|/* static array */
name|int
name|ident
decl_stmt|;
comment|/* strings for identifiers, etc. */
block|}
name|hdr
struct|;
name|struct
name|tms
name|tp
decl_stmt|;
specifier|extern
name|char
modifier|*
name|brk
argument_list|()
decl_stmt|,
name|end
decl_stmt|;
specifier|extern
name|char
name|Pstart
decl_stmt|,
name|Pstop
decl_stmt|;
extern|extern fpetrap(
block|)
end_block

begin_operator
operator|,
end_operator

begin_expr_stmt
name|segvtrap
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*     * Catch floating point traps and memory faults.     */
end_comment

begin_expr_stmt
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|fpetrap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|signal
argument_list|(
name|SIGSEGV
argument_list|,
name|segvtrap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*     * Initializations that can't be performed statically.     */
end_comment

begin_expr_stmt
name|STRLOC
argument_list|(
name|k_errout
operator|.
name|fname
argument_list|)
operator|=
literal|"&errout"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STRLOC
argument_list|(
name|k_input
operator|.
name|fname
argument_list|)
operator|=
literal|"&input"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STRLOC
argument_list|(
name|k_output
operator|.
name|fname
argument_list|)
operator|=
literal|"&output"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STRLOC
argument_list|(
name|k_subject
argument_list|)
operator|=
operator|(
name|char
operator|*
operator|)
literal|1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STRLOC
argument_list|(
name|maps2
argument_list|)
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STRLOC
argument_list|(
name|maps3
argument_list|)
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STRLOC
argument_list|(
name|nulldesc
argument_list|)
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|INTVAL
argument_list|(
name|zerodesc
argument_list|)
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|INTVAL
argument_list|(
name|onedesc
argument_list|)
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STRLOC
argument_list|(
name|nullstr
argument_list|)
operator|=
literal|""
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STRLOC
argument_list|(
name|blank
argument_list|)
operator|=
literal|" "
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STRLOC
argument_list|(
name|letr
argument_list|)
operator|=
literal|"r"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BLKLOC
argument_list|(
name|input
argument_list|)
operator|=
operator|(
expr|union
name|block
operator|*
operator|)
operator|&
name|k_input
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BLKLOC
argument_list|(
name|errout
argument_list|)
operator|=
operator|(
expr|union
name|block
operator|*
operator|)
operator|&
name|k_errout
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STRLOC
argument_list|(
name|lcase
argument_list|)
operator|=
literal|"abcdefghijklmnopqrstuvwxyz"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STRLOC
argument_list|(
name|ucase
argument_list|)
operator|=
literal|"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*     * Initialize&main.     */
end_comment

begin_expr_stmt
name|mainhead
operator|.
name|type
operator|=
name|T_ESTACK
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|mainhead
operator|.
name|activator
operator|.
name|type
operator|=
name|D_NULL
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STRLOC
argument_list|(
name|mainhead
operator|.
name|activator
argument_list|)
operator|=
name|NULL
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|mainhead
operator|.
name|sbase
operator|=
operator|(
name|int
operator|*
operator|)
operator|(
name|STKBASE
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|mainhead
operator|.
name|sp
operator|=
name|NULL
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|mainhead
operator|.
name|boundary
operator|=
name|NULL
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|mainhead
operator|.
name|nresults
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|mainhead
operator|.
name|freshblk
operator|.
name|type
operator|=
name|D_NULL
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STRLOC
argument_list|(
name|mainhead
operator|.
name|freshblk
argument_list|)
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*     * Open the interpretable file and read the header.     */
end_comment

begin_expr_stmt
name|i
operator|=
name|strlen
argument_list|(
name|name
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|f
operator|=
name|open
argument_list|(
name|name
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|f
operator|<
literal|0
condition|)
name|error
argument_list|(
literal|"can't open interpreter file"
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/*     * We check to see if the header starts with #! and if so, we assume     *  that it is being directly executed and seek past the header.     */
end_comment

begin_expr_stmt
name|ufile
operator|=
name|fdopen
argument_list|(
name|f
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|fgets
argument_list|(
name|uheader
argument_list|,
name|MAXHDRLN
argument_list|,
name|ufile
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|strncmp
argument_list|(
name|uheader
argument_list|,
literal|"#!"
argument_list|,
literal|2
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|fseek
argument_list|(
name|ufile
argument_list|,
name|MAXHDR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|fgets
argument_list|(
name|uheader
argument_list|,
name|MAXHDRLN
argument_list|,
name|ufile
argument_list|)
expr_stmt|;
if|if
condition|(
name|strncmp
argument_list|(
name|uheader
argument_list|,
literal|"#!"
argument_list|,
literal|2
argument_list|)
operator|==
literal|0
condition|)
name|lseek
argument_list|(
name|f
argument_list|,
name|MAXHDR
operator|+
operator|(
name|long
operator|)
name|strlen
argument_list|(
name|uheader
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
name|error
argument_list|(
literal|"invalid format for interpretable file"
argument_list|)
expr_stmt|;
block|}
else|else
name|lseek
argument_list|(
name|f
argument_list|,
operator|(
name|long
operator|)
name|strlen
argument_list|(
name|uheader
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_if

begin_if
if|if
condition|(
name|read
argument_list|(
name|f
argument_list|,
operator|&
name|hdr
argument_list|,
sizeof|sizeof
name|hdr
argument_list|)
operator|!=
sizeof|sizeof
name|hdr
condition|)
name|error
argument_list|(
literal|"can't read interpreter file header"
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/*     * Establish pointers to data regions.     */
end_comment

begin_expr_stmt
name|code
operator|=
operator|(
name|char
operator|*
operator|)
name|sbrk
argument_list|(
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|k_trace
operator|=
name|hdr
operator|.
name|trace
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|records
operator|=
operator|(
name|int
operator|*
operator|)
operator|(
name|code
operator|+
name|hdr
operator|.
name|records
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ftab
operator|=
operator|(
name|int
operator|*
operator|)
operator|(
name|code
operator|+
name|hdr
operator|.
name|ftab
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|globals
operator|=
operator|(
expr|struct
name|descrip
operator|*
operator|)
operator|(
name|code
operator|+
name|hdr
operator|.
name|globals
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|gnames
operator|=
name|eglobals
operator|=
operator|(
expr|struct
name|descrip
operator|*
operator|)
operator|(
name|code
operator|+
name|hdr
operator|.
name|gnames
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|statics
operator|=
name|egnames
operator|=
operator|(
expr|struct
name|descrip
operator|*
operator|)
operator|(
name|code
operator|+
name|hdr
operator|.
name|statics
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|estatics
operator|=
operator|(
expr|struct
name|descrip
operator|*
operator|)
operator|(
name|code
operator|+
name|hdr
operator|.
name|ident
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ident
operator|=
operator|(
name|char
operator|*
operator|)
name|estatics
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*     * Examine the environment and make appropriate settings.     */
end_comment

begin_expr_stmt
name|envlook
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*     * Set up stuff for monitoring.     */
end_comment

begin_if
if|if
condition|(
name|monres
operator|>
literal|0
condition|)
name|monsize
operator|=
operator|(
operator|&
name|Pstop
operator|-
operator|&
name|Pstart
operator|+
name|monres
operator|-
literal|1
operator|)
operator|/
name|monres
expr_stmt|;
end_if

begin_expr_stmt
name|monbuf
operator|=
operator|(
name|int
operator|*
operator|)
operator|(
call|(
name|int
call|)
argument_list|(
name|code
operator|+
name|hdr
operator|.
name|size
operator|+
literal|1
argument_list|)
operator|&
operator|~
literal|01
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*     * Set up allocated memory.  The regions are:     *	Monitoring buffer     *	Co-expression stacks     *	String space     *	Heap     *	String qualifier list     */
end_comment

begin_expr_stmt
name|bufs
operator|=
operator|(
name|char
operator|*
operator|*
operator|)
operator|(
name|monbuf
operator|+
name|monsize
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bufused
operator|=
operator|(
name|FILE
operator|*
operator|*
operator|)
operator|(
name|bufs
operator|+
name|numbufs
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|stacks
operator|=
operator|(
name|int
operator|*
operator|)
operator|(
operator|(
call|(
name|int
call|)
argument_list|(
name|bufused
operator|+
name|numbufs
argument_list|)
operator|+
literal|63
operator|)
operator|&
operator|~
literal|077
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|estacks
operator|=
name|stacks
operator|+
name|nstacks
operator|*
name|stksize
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|sfree
operator|=
name|strings
operator|=
operator|(
name|char
operator|*
operator|)
operator|(
call|(
name|int
call|)
argument_list|(
name|estacks
operator|+
literal|63
argument_list|)
operator|&
operator|~
literal|077
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|hpfree
operator|=
name|hpbase
operator|=
name|estrings
operator|=
operator|(
name|char
operator|*
operator|)
operator|(
call|(
name|int
call|)
argument_list|(
name|strings
operator|+
name|ssize
operator|+
literal|63
argument_list|)
operator|&
operator|~
literal|077
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|sqlist
operator|=
name|sqfree
operator|=
name|esqlist
operator|=
operator|(
expr|struct
name|descrip
operator|*
operator|*
operator|)
operator|(
name|maxheap
operator|=
operator|(
name|char
operator|*
operator|)
operator|(
call|(
name|int
call|)
argument_list|(
name|hpbase
operator|+
name|hpsize
operator|+
literal|63
argument_list|)
operator|&
operator|~
literal|077
operator|)
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*     * Try to move the break back to the end of memory to allocate (the     *  end of the string qualifier list) and die if the space isn't     *  available.     */
end_comment

begin_if
if|if
condition|(
name|brk
argument_list|(
name|esqlist
argument_list|)
condition|)
name|error
argument_list|(
literal|"insufficient memory"
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/*     * Read the interpretable code and data into memory.     */
end_comment

begin_if
if|if
condition|(
operator|(
name|cbread
operator|=
name|read
argument_list|(
name|f
argument_list|,
name|code
argument_list|,
name|hdr
operator|.
name|size
argument_list|)
operator|)
operator|!=
name|hdr
operator|.
name|size
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Tried to read %d bytes of code, and got %d\n"
argument_list|,
name|hdr
operator|.
name|size
argument_list|,
name|cbread
argument_list|)
expr_stmt|;
name|error
argument_list|(
literal|"can't read interpreter code"
argument_list|)
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|close
argument_list|(
name|f
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*     * Resolve references from icode to runtime system.     */
end_comment

begin_expr_stmt
name|resolve
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*     * Establish linked list of free co-expression stacks.  esfree     *  is the base.     */
end_comment

begin_expr_stmt
name|esfree
operator|=
name|NULL
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|i
operator|=
name|nstacks
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
name|i
operator|--
control|)
block|{
operator|*
operator|(
name|stacks
operator|+
operator|(
name|i
operator|*
name|stksize
operator|)
operator|)
operator|=
operator|(
name|int
operator|)
name|esfree
expr_stmt|;
name|esfree
operator|=
name|stacks
operator|+
operator|(
name|i
operator|*
name|stksize
operator|)
expr_stmt|;
operator|*
operator|(
name|esfree
operator|+
operator|(
name|stksize
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|b_estack
argument_list|)
operator|/
name|WORDSIZE
operator|)
operator|)
operator|=
name|T_ESTACK
expr_stmt|;
block|}
end_for

begin_comment
comment|/*     * Mark all buffers as available.     */
end_comment

begin_for
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|numbufs
condition|;
name|i
operator|++
control|)
name|bufused
index|[
name|i
index|]
operator|=
name|NULL
expr_stmt|;
end_for

begin_comment
comment|/*     * Buffer stdin if a buffer is available.     */
end_comment

begin_if
if|if
condition|(
name|numbufs
operator|>=
literal|1
condition|)
block|{
name|setbuf
argument_list|(
name|stdin
argument_list|,
name|bufs
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|bufused
index|[
literal|0
index|]
operator|=
name|stdin
expr_stmt|;
block|}
else|else
name|setbuf
argument_list|(
name|stdin
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/*     * Buffer stdout if a buffer is available.     */
end_comment

begin_if
if|if
condition|(
name|numbufs
operator|>=
literal|2
condition|)
block|{
name|setbuf
argument_list|(
name|stdout
argument_list|,
name|bufs
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|bufused
index|[
literal|1
index|]
operator|=
name|stdout
expr_stmt|;
block|}
else|else
name|setbuf
argument_list|(
name|stdout
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/*     * Buffer stderr if a buffer is available.     */
end_comment

begin_if
if|if
condition|(
name|numbufs
operator|>=
literal|3
operator|&&
operator|!
name|noerrbuf
condition|)
block|{
name|setbuf
argument_list|(
name|stderr
argument_list|,
name|bufs
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|bufused
index|[
literal|2
index|]
operator|=
name|stderr
expr_stmt|;
block|}
else|else
name|setbuf
argument_list|(
name|stderr
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/*     * Point&main at the stack for the main procedure and set current,     *  the pointer to the current co-expression to&main.     */
end_comment

begin_expr_stmt
name|k_main
operator|.
name|type
operator|=
name|D_ESTACK
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BLKLOC
argument_list|(
name|k_main
argument_list|)
operator|=
operator|(
expr|union
name|block
operator|*
operator|)
operator|&
name|mainhead
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|current
operator|=
name|k_main
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|AZ_NEVER
end_ifdef

begin_comment
comment|/*     * Turn on monitoring if so directed.     */
end_comment

begin_if
if|if
condition|(
name|monres
operator|>
literal|0
condition|)
name|monitor
argument_list|(
operator|&
name|Pstart
argument_list|,
operator|&
name|Pstop
argument_list|,
name|monbuf
argument_list|,
name|monsize
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_if

begin_endif
endif|#
directive|endif
endif|AZ_NEVER
end_endif

begin_comment
comment|/*     * Get startup time.     */
end_comment

begin_expr_stmt
name|times
argument_list|(
operator|&
name|tp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|starttime
operator|=
name|tp
operator|.
name|tms_utime
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/*  * Check for environment variables that Icon uses and set system  *  values as is appropriate.  */
end_comment

begin_expr_stmt
unit|envlook
operator|(
operator|)
block|{
specifier|register
name|char
operator|*
name|p
block|;
specifier|extern
name|char
operator|*
name|getenv
argument_list|()
block|;
if|if
condition|(
operator|(
name|p
operator|=
name|getenv
argument_list|(
literal|"TRACE"
argument_list|)
operator|)
operator|!=
name|NULL
operator|&&
operator|*
name|p
operator|!=
literal|'\0'
condition|)
name|k_trace
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|(
name|p
operator|=
name|getenv
argument_list|(
literal|"NBUFS"
argument_list|)
operator|)
operator|!=
name|NULL
operator|&&
operator|*
name|p
operator|!=
literal|'\0'
condition|)
name|numbufs
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
end_if

begin_if
if|if
condition|(
operator|(
name|p
operator|=
name|getenv
argument_list|(
literal|"NSTACKS"
argument_list|)
operator|)
operator|!=
name|NULL
operator|&&
operator|*
name|p
operator|!=
literal|'\0'
condition|)
name|nstacks
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
end_if

begin_if
if|if
condition|(
operator|(
name|p
operator|=
name|getenv
argument_list|(
literal|"STKSIZE"
argument_list|)
operator|)
operator|!=
name|NULL
operator|&&
operator|*
name|p
operator|!=
literal|'\0'
condition|)
name|stksize
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
end_if

begin_if
if|if
condition|(
operator|(
name|p
operator|=
name|getenv
argument_list|(
literal|"STRSIZE"
argument_list|)
operator|)
operator|!=
name|NULL
operator|&&
operator|*
name|p
operator|!=
literal|'\0'
condition|)
name|ssize
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
end_if

begin_if
if|if
condition|(
operator|(
name|p
operator|=
name|getenv
argument_list|(
literal|"HEAPSIZE"
argument_list|)
operator|)
operator|!=
name|NULL
operator|&&
operator|*
name|p
operator|!=
literal|'\0'
condition|)
name|hpsize
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|AZ_NEVER
end_ifdef

begin_if
if|if
condition|(
operator|(
name|p
operator|=
name|getenv
argument_list|(
literal|"PROFILE"
argument_list|)
operator|)
operator|!=
name|NULL
operator|&&
operator|*
name|p
operator|!=
literal|'\0'
condition|)
name|monres
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
end_if

begin_endif
endif|#
directive|endif
endif|AZ_NEVER
end_endif

begin_if
if|if
condition|(
operator|(
name|p
operator|=
name|getenv
argument_list|(
literal|"ICONCORE"
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGSEGV
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|dodump
operator|++
expr_stmt|;
block|}
end_if

begin_if
if|if
condition|(
operator|(
name|p
operator|=
name|getenv
argument_list|(
literal|"NOERRBUF"
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
name|noerrbuf
operator|++
expr_stmt|;
end_if

begin_comment
unit|}
comment|/*  * Produce run-time error 204 on floating point traps.  */
end_comment

begin_expr_stmt
unit|fpetrap
operator|(
operator|)
block|{
name|runerr
argument_list|(
literal|204
argument_list|,
name|NULL
argument_list|)
block|;    }
comment|/*  * Produce run-time error 304 on segmentation faults.  */
name|segvtrap
argument_list|()
block|{
name|runerr
argument_list|(
literal|304
argument_list|,
name|NULL
argument_list|)
block|;    }
comment|/*  * error - print error message s, used only in startup code.  */
name|error
argument_list|(
argument|s
argument_list|)
name|char
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|if
condition|(
name|line
operator|>
literal|0
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"error at line %d in %s\n%s\n"
argument_list|,
name|line
argument_list|,
name|file
argument_list|,
name|s
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"error in startup code\n%s\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
if|if
condition|(
name|dodump
condition|)
name|abort
argument_list|()
expr_stmt|;
name|c_exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * syserr - print s as a system error.  */
end_comment

begin_macro
name|syserr
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|line
operator|>
literal|0
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"System error at line %d in %s\n%s\n"
argument_list|,
name|line
argument_list|,
name|file
argument_list|,
name|s
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"System error in startup code\n%s\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
if|if
condition|(
name|dodump
condition|)
name|abort
argument_list|()
expr_stmt|;
name|c_exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * errtab maps run-time error numbers into messages.  */
end_comment

begin_struct
struct|struct
name|errtab
block|{
name|int
name|errno
decl_stmt|;
name|char
modifier|*
name|errmsg
decl_stmt|;
block|}
name|errtab
index|[]
init|=
block|{
include|#
directive|include
file|"../h/err.h"
literal|0
block|,
literal|0
block|}
struct|;
end_struct

begin_comment
comment|/*  * runerr - print message corresponding to error n and if v is non-null,  *  print it as the offending value.  */
end_comment

begin_expr_stmt
name|runerr
argument_list|(
name|n
argument_list|,
name|v
argument_list|)
specifier|register
name|int
name|n
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|descrip
modifier|*
name|v
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|errtab
modifier|*
name|p
decl_stmt|;
if|if
condition|(
name|line
operator|>
literal|0
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Run-time error %d at line %d in %s\n"
argument_list|,
name|n
argument_list|,
name|line
argument_list|,
name|file
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Run-time error %d in startup code\n"
argument_list|,
name|n
argument_list|)
expr_stmt|;
for|for
control|(
name|p
operator|=
name|errtab
init|;
name|p
operator|->
name|errno
operator|>
literal|0
condition|;
name|p
operator|++
control|)
if|if
condition|(
name|p
operator|->
name|errno
operator|==
name|n
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|p
operator|->
name|errmsg
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|v
operator|!=
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"offending value: "
argument_list|)
expr_stmt|;
name|outimage
argument_list|(
name|stderr
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
if|if
condition|(
name|dodump
condition|)
name|abort
argument_list|()
expr_stmt|;
name|c_exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * External declarations for blocks of built-in procedures.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|b_proc
define|#
directive|define
name|PDEF
parameter_list|(
name|p
parameter_list|)
value|B
comment|/**/
value|p,
include|#
directive|include
file|"../h/pdef.h"
name|interp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hack to avoid ,; at end */
end_comment

begin_undef
undef|#
directive|undef
name|PDEF
end_undef

begin_comment
comment|/*  * Array of addresses of blocks for built-in procedures.  It is important  *  that this table and the one in link/builtin.c agree; the linker  *  supplies iconx with indices into this array.  */
end_comment

begin_decl_stmt
name|struct
name|b_proc
modifier|*
name|functab
index|[]
init|=
block|{
define|#
directive|define
name|PDEF
parameter_list|(
name|p
parameter_list|)
value|&B
comment|/**/
value|p,
include|#
directive|include
file|"../h/pdef.h"
undef|#
directive|undef
name|PDEF
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * resolve - perform various fixups on the data read from the interpretable  *  file.  */
end_comment

begin_macro
name|resolve
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
specifier|register
name|struct
name|b_proc
modifier|*
name|pp
decl_stmt|;
specifier|register
name|struct
name|descrip
modifier|*
name|dp
decl_stmt|;
extern|extern mkrec(
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*     * Scan the global variable list for procedures and fill in appropriate     *  addresses.     */
end_comment

begin_for
for|for
control|(
name|dp
operator|=
name|globals
init|;
name|dp
operator|<
name|eglobals
condition|;
name|dp
operator|++
control|)
block|{
if|if
condition|(
name|TYPE
argument_list|(
operator|*
name|dp
argument_list|)
operator|!=
name|T_PROC
condition|)
continue|continue;
comment|/*        * The second word of the descriptor for procedure variables tells        *  where the procedure is.  Negative values are used for built-in        *  procedures and positive values are used for Icon procedures.        */
name|i
operator|=
name|INTVAL
argument_list|(
operator|*
name|dp
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|<
literal|0
condition|)
block|{
comment|/*           * *dp names a built-in function, negate i and use it as an index           *  into functab to get the location of the procedure block.           */
name|BLKLOC
argument_list|(
operator|*
name|dp
argument_list|)
operator|=
operator|(
expr|union
name|block
operator|*
operator|)
name|functab
index|[
operator|-
name|i
operator|-
literal|1
index|]
expr_stmt|;
block|}
else|else
block|{
comment|/*           * *dp names an Icon procedure or a record.  i is an offset to           *  location of the procedure block in the code section.  Point           *  pp at the block and replace BLKLOC(*dp).           */
name|pp
operator|=
operator|(
expr|struct
name|b_proc
operator|*
operator|)
operator|(
name|code
operator|+
name|i
operator|)
expr_stmt|;
name|BLKLOC
argument_list|(
operator|*
name|dp
argument_list|)
operator|=
operator|(
expr|union
name|block
operator|*
operator|)
name|pp
expr_stmt|;
comment|/*           * Relocate the address of the name of the procedure.           */
name|STRLOC
argument_list|(
name|pp
operator|->
name|pname
argument_list|)
operator|+=
operator|(
name|int
operator|)
name|ident
expr_stmt|;
if|if
condition|(
name|pp
operator|->
name|ndynam
operator|==
operator|-
literal|2
condition|)
comment|/*              * This procedure is a record constructor.  Make its entry point              *  be the entry point of mkrec().              */
name|pp
operator|->
name|entryp
operator|=
name|EntryPoint
argument_list|(
name|mkrec
argument_list|)
expr_stmt|;
else|else
block|{
comment|/*              * This is an Icon procedure.  Relocate the entry point and              *  the names of the parameters, locals, and static variables.              */
name|pp
operator|->
name|entryp
operator|=
name|code
operator|+
operator|(
name|int
operator|)
name|pp
operator|->
name|entryp
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|pp
operator|->
name|nparam
operator|+
name|pp
operator|->
name|ndynam
operator|+
name|pp
operator|->
name|nstatic
condition|;
name|i
operator|++
control|)
name|STRLOC
argument_list|(
name|pp
operator|->
name|lnames
index|[
name|i
index|]
argument_list|)
operator|+=
operator|(
name|int
operator|)
name|ident
expr_stmt|;
block|}
block|}
block|}
end_for

begin_comment
comment|/*     * Relocate the names of the global variables.     */
end_comment

begin_for
for|for
control|(
name|dp
operator|=
name|gnames
init|;
name|dp
operator|<
name|egnames
condition|;
name|dp
operator|++
control|)
name|STRLOC
argument_list|(
operator|*
name|dp
argument_list|)
operator|+=
operator|(
name|int
operator|)
name|ident
expr_stmt|;
end_for

unit|}
end_unit

