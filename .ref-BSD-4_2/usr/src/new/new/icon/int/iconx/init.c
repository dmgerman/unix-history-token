begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
comment|/* max len of #! line 		    */
end_comment

begin_define
define|#
directive|define
name|MAXHDR
value|1024L
end_define

begin_comment
comment|/* size of autoloading header--!! must 					   agree with that in link/ulink.c */
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
comment|/* source program file name         */
end_comment

begin_decl_stmt
name|int
name|line
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* source program line number       */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INT
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|code
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interpreter code buffer	    */
end_comment

begin_decl_stmt
name|int
modifier|*
name|records
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to record procedure blocks   */
end_comment

begin_decl_stmt
name|int
modifier|*
name|ftab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to record/field table	    */
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
comment|/* ptr to global variables	    */
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
comment|/* ptr to global variable names	    */
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
comment|/* ptr to static variables	    */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ident
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to identifier table	    */
end_comment

begin_endif
endif|#
directive|endif
endif|INT
end_endif

begin_decl_stmt
name|int
modifier|*
name|monbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* monitor buffer for profiling     */
end_comment

begin_decl_stmt
name|int
name|monres
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* resolution of monitor buffer     */
end_comment

begin_decl_stmt
name|int
name|monsize
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of monitor buffer           */
end_comment

begin_decl_stmt
name|int
name|numbufs
init|=
name|NUMBUF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of i/o buffers            */
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
comment|/* pointer to buffers               */
end_comment

begin_decl_stmt
name|FILE
modifier|*
modifier|*
name|bufused
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to buffer use markers    */
end_comment

begin_decl_stmt
name|int
name|nstacks
init|=
name|MAXSTACKS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial number of coexpr stacks  */
end_comment

begin_decl_stmt
name|int
name|stksize
init|=
name|STACKSIZE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* coexpression stack size          */
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
comment|/* start of stack space             */
end_comment

begin_decl_stmt
name|int
modifier|*
name|estacks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of stack space               */
end_comment

begin_decl_stmt
name|int
modifier|*
name|esfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stack space free list pointer    */
end_comment

begin_decl_stmt
name|int
name|ssize
init|=
name|MAXSTRSPACE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial string space size (bytes)*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|strings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start of string space            */
end_comment

begin_decl_stmt
name|char
modifier|*
name|estrings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of string space              */
end_comment

begin_decl_stmt
name|char
modifier|*
name|sfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string space free pointer        */
end_comment

begin_decl_stmt
name|int
name|hpsize
init|=
name|MAXHEAPSIZE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial heap size (bytes)        */
end_comment

begin_decl_stmt
name|char
modifier|*
name|hpbase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start of heap                    */
end_comment

begin_decl_stmt
name|char
modifier|*
name|maxheap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of heap storage              */
end_comment

begin_decl_stmt
name|char
modifier|*
name|hpfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* heap free space pointer          */
end_comment

begin_decl_stmt
name|unsigned
name|heapneed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stated need for heap space       */
end_comment

begin_decl_stmt
name|unsigned
name|strneed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stated need for string space     */
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
comment|/* string qualifier list            */
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
comment|/* s. q. list free pointer          */
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
comment|/* end of s. q. list                */
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

begin_decl_stmt
name|struct
name|b_cset
name|k_ascii
init|=
block|{
comment|/*&ascii         */
name|T_CSET
block|,
comment|/*   type         */
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
comment|/*   128 bits on  */
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
comment|/*   128 bits off */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|b_cset
name|k_cset
init|=
block|{
comment|/*&cset          */
name|T_CSET
block|,
comment|/*   type         */
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
comment|/*   256 bits on  */
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

begin_decl_stmt
name|struct
name|b_file
name|k_errout
init|=
block|{
comment|/*&errout               */
name|T_FILE
block|,
comment|/*   type                */
name|stderr
block|,
comment|/*   stream              */
name|FS_WRITE
block|,
comment|/*   status              */
literal|7
block|,
comment|/*   length of file name */
comment|/*"&errout",*/
comment|/*   file name, fix in init */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|b_file
name|k_input
init|=
block|{
comment|/*&input                */
name|T_FILE
block|,
comment|/*   type                */
name|stdin
block|,
comment|/*   stream              */
name|FS_READ
block|,
comment|/*   status              */
literal|6
block|,
comment|/*   length of file name */
comment|/*"&input",*/
comment|/*   file name, fix in init */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|b_cset
name|k_lcase
init|=
block|{
comment|/*&lcase         */
name|T_CSET
block|,
comment|/*   type         */
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
comment|/*   lower case   */
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
comment|/*   letters only */
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
comment|/*&main  */
end_comment

begin_decl_stmt
name|int
name|k_pos
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*&pos   */
end_comment

begin_decl_stmt
name|struct
name|b_file
name|k_output
init|=
block|{
comment|/*&output               */
name|T_FILE
block|,
comment|/*   type                */
name|stdout
block|,
comment|/*   stream              */
name|FS_WRITE
block|,
comment|/*   status              */
literal|7
block|,
comment|/*   length of file name */
comment|/*"&output",*/
comment|/*   file name, fix in init */
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
comment|/*&subject          */
literal|0
block|,
comment|/*   string length   */
comment|/*1,*/
comment|/*   string location */
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|INT
end_ifdef

begin_decl_stmt
name|int
name|k_trace
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|INT
end_endif

begin_decl_stmt
name|struct
name|b_cset
name|k_ucase
init|=
block|{
comment|/*&ucase         */
name|T_CSET
block|,
comment|/*   type         */
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
comment|/*   upper case   */
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
comment|/*   letters only */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|descrip
name|maps2
init|=
block|{
comment|/* save space for 2nd arg to map() */
name|D_NULL
block|,
comment|/*   string length                 */
comment|/*0,*/
comment|/*   string location               */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|descrip
name|maps3
init|=
block|{
comment|/* save space for 3rd arg to map() */
name|D_NULL
block|,
comment|/*   string length                 */
comment|/*0,*/
comment|/*   string location               */
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

begin_comment
comment|/* universal&null */
end_comment

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

begin_comment
comment|/* universal 0     */
end_comment

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

begin_comment
comment|/* universal 1     */
end_comment

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

begin_comment
comment|/* universal null string */
end_comment

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

begin_comment
comment|/* universal blank */
end_comment

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

begin_comment
comment|/* universal letter 'r' */
end_comment

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

begin_comment
comment|/* universal input file */
end_comment

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

begin_comment
comment|/* universal error file */
end_comment

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

begin_comment
comment|/* universal lower case */
end_comment

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

begin_comment
comment|/* universal upper case */
end_comment

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
comment|/*  * init - initialize memory and prepare for Icon execution  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INT
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

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|INT
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CMP
end_ifdef

begin_macro
name|init
argument_list|()
end_macro

begin_endif
endif|#
directive|endif
endif|CMP
end_endif

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
ifdef|#
directive|ifdef
name|INT
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
struct|struct
name|header
block|{
name|int
name|size
decl_stmt|;
name|int
name|trace
decl_stmt|;
name|int
name|records
decl_stmt|;
name|int
name|ftab
decl_stmt|;
name|int
name|globals
decl_stmt|;
name|int
name|gnames
decl_stmt|;
name|int
name|statics
decl_stmt|;
name|int
name|ident
decl_stmt|;
block|}
name|hdr
struct|;
endif|#
directive|endif
endif|INT
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

begin_expr_stmt
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|fpetrap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* catch floating point traps */
end_comment

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
comment|/* catch memory faults */
end_comment

begin_comment
comment|/* initialization fix-ups */
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

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

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
literal|0x7fffffff
operator|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
endif|VAX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PDP11
end_ifdef

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
literal|0177776
operator|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
endif|PDP11
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|INT
end_ifdef

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
literal|"#! "
argument_list|,
literal|3
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
literal|"#! "
argument_list|,
literal|3
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

begin_expr_stmt
name|code
operator|=
operator|&
name|end
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
name|code
operator|+
name|hdr
operator|.
name|records
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ftab
operator|=
name|code
operator|+
name|hdr
operator|.
name|ftab
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|globals
operator|=
name|code
operator|+
name|hdr
operator|.
name|globals
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|gnames
operator|=
name|eglobals
operator|=
name|code
operator|+
name|hdr
operator|.
name|gnames
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|statics
operator|=
name|egnames
operator|=
name|code
operator|+
name|hdr
operator|.
name|statics
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ident
operator|=
name|estatics
operator|=
name|code
operator|+
name|hdr
operator|.
name|ident
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
endif|INT
end_endif

begin_expr_stmt
name|envlook
argument_list|()
expr_stmt|;
end_expr_stmt

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

begin_ifdef
ifdef|#
directive|ifdef
name|INT
end_ifdef

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
comment|/* ??-whm */
end_comment

begin_endif
endif|#
directive|endif
endif|INT
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CMP
end_ifdef

begin_expr_stmt
name|monbuf
operator|=
operator|&
name|end
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
endif|CMP
end_endif

begin_expr_stmt
name|bufs
operator|=
name|monbuf
operator|+
name|monsize
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bufused
operator|=
name|bufs
operator|+
name|numbufs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|stacks
operator|=
operator|(
name|char
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

begin_if
if|if
condition|(
name|brk
argument_list|(
name|esqlist
argument_list|)
condition|)
ifdef|#
directive|ifdef
name|INT
name|error
argument_list|(
literal|"insufficient memory"
argument_list|)
expr_stmt|;
end_if

begin_endif
endif|#
directive|endif
endif|INT
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CMP
end_ifdef

begin_expr_stmt
name|syserr
argument_list|(
literal|"insufficient memory"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
endif|CMP
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INT
end_ifdef

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

begin_expr_stmt
name|resolve
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* resolve references from ucode to runtime system */
end_comment

begin_endif
endif|#
directive|endif
endif|INT
end_endif

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
comment|/* set stack space free list */
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
name|ADDRSIZE
operator|)
operator|)
operator|=
name|T_ESTACK
expr_stmt|;
block|}
end_for

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
comment|/*  * We're going to try buffering stdout even if it's a terminal,  *  whm--Fri Feb 25 02:00:08 1983  *  * if (!isatty(fileno(stdout))&& numbufs>= 2) {  */
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
comment|/*     * Going to try buffering stderr for a while,     *  whm--Tue Mar  1 02:01:48 1983     *   setbuf(stderr, NULL);     */
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

begin_expr_stmt
name|k_main
operator|.
name|type
operator|=
name|D_ESTACK
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* point to expression stack header for main */
end_comment

begin_expr_stmt
name|BLKLOC
argument_list|(
name|k_main
argument_list|)
operator|=
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

begin_comment
comment|/* start in expression stack for main procedure */
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

begin_expr_stmt
name|times
argument_list|(
operator|&
name|tp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* get startup time */
end_comment

begin_expr_stmt
name|starttime
operator|=
name|tp
operator|.
name|tms_utime
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  envlook
operator|(
operator|)
block|{
specifier|register
name|char
operator|*
name|p
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
comment|/* catch floating point traps */
name|signal
argument_list|(
name|SIGSEGV
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
comment|/* catch memory faults */
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

begin_expr_stmt
unit|}  fpetrap
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
ifdef|#
directive|ifdef
name|INT
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

begin_endif
endif|#
directive|endif
endif|INT
end_endif

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
ifdef|#
directive|ifdef
name|INT
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
endif|#
directive|endif
endif|INT
ifdef|#
directive|ifdef
name|CMP
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
endif|#
directive|endif
endif|CMP
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

begin_ifdef
ifdef|#
directive|ifdef
name|INT
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|b_proc
name|Babs
decl_stmt|,
name|Bany
decl_stmt|,
name|Bbal
decl_stmt|,
name|Bcenter
decl_stmt|,
name|Bclose
decl_stmt|,
name|Bcopy
decl_stmt|,
name|Bcset
decl_stmt|,
name|Bdisplay
decl_stmt|,
name|Bexit
decl_stmt|,
name|Bfind
decl_stmt|,
name|Bget
decl_stmt|,
name|Bimage
decl_stmt|,
name|Binteger
decl_stmt|,
name|Bleft
decl_stmt|,
name|Blist
decl_stmt|,
name|Bmany
decl_stmt|,
name|Bmap
decl_stmt|,
name|Bmatch
decl_stmt|,
name|Bmove
decl_stmt|,
name|Bnumeric
decl_stmt|,
name|Bopen
decl_stmt|,
name|Bpop
decl_stmt|,
name|Bpos
decl_stmt|,
name|Bpull
decl_stmt|,
name|Bpush
decl_stmt|,
name|Bput
decl_stmt|,
name|Bread
decl_stmt|,
name|Breads
decl_stmt|,
name|Breal
decl_stmt|,
name|Brepl
decl_stmt|,
name|Breverse
decl_stmt|,
name|Bright
decl_stmt|,
ifdef|#
directive|ifdef
name|EXT
name|Bseq
decl_stmt|,
endif|#
directive|endif
endif|EXT
name|Bsort
decl_stmt|,
name|Bstop
decl_stmt|,
name|Bstring
decl_stmt|,
name|Bsystem
decl_stmt|,
name|Btab
decl_stmt|,
name|Btable
decl_stmt|,
name|Btrim
decl_stmt|,
name|Btype
decl_stmt|,
name|Bupto
decl_stmt|,
name|Bwrite
decl_stmt|,
name|Bwrites
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|b_proc
modifier|*
name|functab
index|[]
init|=
block|{
operator|&
name|Babs
block|,
operator|&
name|Bany
block|,
operator|&
name|Bbal
block|,
operator|&
name|Bcenter
block|,
operator|&
name|Bclose
block|,
operator|&
name|Bcopy
block|,
operator|&
name|Bcset
block|,
operator|&
name|Bdisplay
block|,
operator|&
name|Bexit
block|,
operator|&
name|Bfind
block|,
operator|&
name|Bget
block|,
operator|&
name|Bimage
block|,
operator|&
name|Binteger
block|,
operator|&
name|Bleft
block|,
operator|&
name|Blist
block|,
operator|&
name|Bmany
block|,
operator|&
name|Bmap
block|,
operator|&
name|Bmatch
block|,
operator|&
name|Bmove
block|,
operator|&
name|Bnumeric
block|,
operator|&
name|Bopen
block|,
operator|&
name|Bpop
block|,
operator|&
name|Bpos
block|,
operator|&
name|Bpull
block|,
operator|&
name|Bpush
block|,
operator|&
name|Bput
block|,
operator|&
name|Bread
block|,
operator|&
name|Breads
block|,
operator|&
name|Breal
block|,
operator|&
name|Brepl
block|,
operator|&
name|Breverse
block|,
operator|&
name|Bright
block|,
ifdef|#
directive|ifdef
name|EXT
operator|&
name|Bseq
block|,
endif|#
directive|endif
endif|EXT
operator|&
name|Bsort
block|,
operator|&
name|Bstop
block|,
operator|&
name|Bstring
block|,
operator|&
name|Bsystem
block|,
operator|&
name|Btab
block|,
operator|&
name|Btable
block|,
operator|&
name|Btrim
block|,
operator|&
name|Btype
block|,
operator|&
name|Bupto
block|,
operator|&
name|Bwrite
block|,
operator|&
name|Bwrites
block|}
decl_stmt|;
end_decl_stmt

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
comment|/* adjust global variables to point to procedure and function blocks */
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
comment|/* function */
comment|/* set pointer to proper procedure block */
name|BLKLOC
argument_list|(
operator|*
name|dp
argument_list|)
operator|=
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
comment|/* procedure or record */
comment|/* relocate pointer to procedure block */
comment|/* if record, set entry point to mkrec() */
comment|/* if procedure, relocate entry point */
comment|/* relocate pointers to identifier table */
name|pp
operator|=
name|code
operator|+
name|i
expr_stmt|;
name|BLKLOC
argument_list|(
operator|*
name|dp
argument_list|)
operator|=
name|pp
expr_stmt|;
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
name|pp
operator|->
name|entryp
operator|=
name|EntryPoint
argument_list|(
name|mkrec
argument_list|)
expr_stmt|;
comment|/* jump past entry mask of mkrec */
else|else
block|{
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
comment|/* ??-whm */
block|}
block|}
block|}
end_for

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

begin_comment
comment|/* ??-whm */
end_comment

begin_endif
unit|}
endif|#
directive|endif
endif|INT
end_endif

end_unit

