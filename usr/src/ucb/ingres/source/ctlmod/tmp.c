begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"ctlmod.h"
end_include

begin_include
include|#
directive|include
file|"pipes.h"
end_include

begin_include
include|#
directive|include
file|<resp.h>
end_include

begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<aux.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|%W%	%G%
argument_list|)
end_macro

begin_comment
comment|/* **  MAIN -- initialize control module ** **	Called only once, this routine sets everything up. ** **	The format of the argv is as follows: **		argv[0] -- pathname **		argv[1] -- file descriptor for input pipe or'ed with **			0100 to make it printable in a 'ps'. **		argv[2] -- Fileset **		argv[3] -- Usercode **		argv[4] -- Database **		argv[5] -- Pathname ** **	Parameters: **		argc, argv -- as usual ** **	Returns: **		none ** **	Side Effects: **		Many; see code. **		Proc_name is set to the working process name. **		Fileset, Database, Usercode -- set from argv. **		Trace vectors are initialized. ** **	Requires: **		markopen -- to mark the open files. **		The input pipe must have the Cm struct in it as **			the first data. ** **	Trace Flags: **		1 */
end_comment

begin_decl_stmt
name|struct
name|resp
name|Resp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* State response structure */
end_comment

begin_decl_stmt
name|struct
name|_cm_t
name|Cm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the system topography map */
end_comment

begin_decl_stmt
name|struct
name|_ctx_t
name|Ctx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the current context */
end_comment

begin_decl_stmt
name|int
name|Syncs
index|[
name|CM_MAXPROC
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expected SYNC's from each proc */
end_comment

begin_comment
comment|/* General System Information */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Proc_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the 'name' of the currently running proc */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Fileset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a unique string to make filenames from */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Database
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the name of the current database */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Usercode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the code of the current user */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Pathname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the pathname of the root of INGRES */
end_comment

begin_decl_stmt
name|int
name|Equel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if running an Equel program */
end_comment

begin_decl_stmt
name|int
name|RubLevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rubout level, -1 if ignored */
end_comment

begin_decl_stmt
name|struct
name|out_arg
name|Out_arg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output arguments */
end_comment

begin_decl_stmt
name|jmp_buf
name|CmReset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* restart addr on interrupt */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|xMONITOR
end_ifdef

begin_decl_stmt
name|struct
name|monitor
name|CmMonBuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* monitor buffer for CM overhead */
end_comment

begin_endif
endif|#
directive|endif
endif|xMONITOR
end_endif

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|struct
name|fn_def
modifier|*
name|f
decl_stmt|;
specifier|register
name|char
modifier|*
modifier|*
name|q
decl_stmt|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
name|pb_t
name|pb
decl_stmt|;
specifier|static
name|int
name|reenter
decl_stmt|;
extern|extern		rubcatch(
block|)
function|;
end_function

begin_extern
extern|extern		error(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|bool
name|nobuffer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pb_t
modifier|*
name|MonPpb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|CmOfiles
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined in markopen.c */
end_comment

begin_expr_stmt
name|Ctx
operator|.
name|ctx_name
operator|=
name|Proc_name
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|argv
index|[
name|argc
index|]
operator|=
name|NULL
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|nobuffer
operator|=
name|tTrace
argument_list|(
name|argv
argument_list|,
name|argv
index|[
literal|1
index|]
index|[
literal|1
index|]
argument_list|,
name|FuncVect
index|[
literal|0
index|]
operator|->
name|fn_tvect
argument_list|,
literal|30
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Ctx
operator|.
name|ctx_tvect
operator|=
name|tT
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|reenter
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|setjmp
argument_list|(
name|CmReset
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|reenter
operator|++
condition|)
name|exit
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
end_if

begin_if
if|if
condition|(
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
operator|==
name|SIG_DFL
condition|)
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|rubcatch
argument_list|)
expr_stmt|;
else|else
name|RubLevel
operator|=
operator|-
literal|1
expr_stmt|;
end_if

begin_expr_stmt
name|MonPpb
operator|=
operator|&
name|pb
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* mark all currently open files */
end_comment

begin_expr_stmt
name|acc_init
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|markopen
argument_list|(
operator|&
name|CmOfiles
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|tTf
argument_list|(
literal|23
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"debug flag 23 is ON!!!!\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
end_if

begin_comment
comment|/* 	**  Process argument vector. 	**	The easy ones just involve saving a pointer. 	**	argv[1] is used to get a file descriptor; this 	**		becomes the initial input.  This file 	**		is read to fill in the Cm (configuration) 	**		structure. 	*/
end_comment

begin_if
if|if
condition|(
name|tTf
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
operator|||
name|argc
operator|<
literal|6
condition|)
name|prargs
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
end_if

begin_if
if|if
condition|(
name|argc
operator|<
literal|6
condition|)
name|syserr
argument_list|(
literal|"main: argc=%d"
argument_list|,
name|argc
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|q
operator|=
operator|&
name|argv
index|[
literal|2
index|]
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Fileset
operator|=
operator|*
name|q
operator|++
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Usercode
operator|=
operator|*
name|q
operator|++
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Database
operator|=
operator|*
name|q
operator|++
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Pathname
operator|=
operator|*
name|q
operator|++
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|i
operator|=
name|read
argument_list|(
name|argv
index|[
literal|1
index|]
index|[
literal|0
index|]
operator|&
literal|077
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|Cm
argument_list|,
sizeof|sizeof
name|Cm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|i
operator|!=
sizeof|sizeof
name|Cm
condition|)
name|syserr
argument_list|(
literal|"main: read %d"
argument_list|,
name|i
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/* set up other globals */
end_comment

begin_expr_stmt
name|Ctx
operator|.
name|ctx_name
operator|=
name|Proc_name
operator|=
name|Cm
operator|.
name|cm_myname
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|initbuf
argument_list|(
name|Qbuf
argument_list|,
name|QbufSize
argument_list|,
name|ERR_QBUF
argument_list|,
name|error
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Ctx
operator|.
name|ctx_cmark
operator|=
name|Ctx
operator|.
name|ctx_pmark
operator|=
name|markbuf
argument_list|(
name|Qbuf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* process flags */
end_comment

begin_for
for|for
control|(
init|;
operator|(
name|p
operator|=
operator|*
name|q
operator|)
operator|!=
name|NULL
condition|;
name|q
operator|++
control|)
block|{
if|if
condition|(
name|p
index|[
literal|0
index|]
operator|!=
literal|'-'
condition|)
continue|continue;
switch|switch
condition|(
name|p
index|[
literal|1
index|]
condition|)
block|{
case|case
literal|'&'
case|:
comment|/* equel program */
name|Equel
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|p
index|[
literal|6
index|]
operator|!=
literal|'\0'
condition|)
name|Equel
operator|=
literal|2
expr_stmt|;
break|break;
case|case
literal|'c'
case|:
comment|/* c0 sizes */
name|atoi
argument_list|(
operator|&
name|p
index|[
literal|2
index|]
argument_list|,
operator|&
name|Out_arg
operator|.
name|c0width
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'i'
case|:
comment|/* iNsizes */
switch|switch
condition|(
name|p
index|[
literal|2
index|]
condition|)
block|{
case|case
literal|'1'
case|:
name|atoi
argument_list|(
operator|&
name|p
index|[
literal|3
index|]
argument_list|,
operator|&
name|Out_arg
operator|.
name|i1width
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'2'
case|:
name|atoi
argument_list|(
operator|&
name|p
index|[
literal|3
index|]
argument_list|,
operator|&
name|Out_arg
operator|.
name|i2width
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'4'
case|:
name|atoi
argument_list|(
operator|&
name|p
index|[
literal|3
index|]
argument_list|,
operator|&
name|Out_arg
operator|.
name|i4width
argument_list|)
expr_stmt|;
break|break;
block|}
break|break;
case|case
literal|'f'
case|:
comment|/* fN sizes */
name|p
operator|=
operator|&
name|p
index|[
literal|3
index|]
expr_stmt|;
name|i
operator|=
operator|*
name|p
operator|++
expr_stmt|;
while|while
condition|(
operator|*
name|p
operator|!=
literal|'.'
condition|)
name|p
operator|++
expr_stmt|;
operator|*
name|p
operator|++
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|q
operator|)
index|[
literal|2
index|]
operator|==
literal|'4'
condition|)
block|{
name|atoi
argument_list|(
operator|&
operator|(
operator|*
name|q
operator|)
index|[
literal|4
index|]
argument_list|,
operator|&
name|Out_arg
operator|.
name|f4width
argument_list|)
expr_stmt|;
name|atoi
argument_list|(
name|p
argument_list|,
operator|&
name|Out_arg
operator|.
name|f4prec
argument_list|)
expr_stmt|;
name|Out_arg
operator|.
name|f4style
operator|=
name|i
expr_stmt|;
block|}
else|else
block|{
name|atoi
argument_list|(
operator|&
operator|(
operator|*
name|q
operator|)
index|[
literal|4
index|]
argument_list|,
operator|&
name|Out_arg
operator|.
name|f8width
argument_list|)
expr_stmt|;
name|atoi
argument_list|(
name|p
argument_list|,
operator|&
name|Out_arg
operator|.
name|f8prec
argument_list|)
expr_stmt|;
name|Out_arg
operator|.
name|f8style
operator|=
name|i
expr_stmt|;
block|}
operator|*
operator|--
name|p
operator|=
literal|'.'
expr_stmt|;
comment|/* restore parm for dbu's */
break|break;
case|case
literal|'v'
case|:
comment|/* vertical seperator */
name|Out_arg
operator|.
name|coldelim
operator|=
name|p
index|[
literal|2
index|]
expr_stmt|;
break|break;
block|}
block|}
end_for

begin_comment
comment|/* set up trace flags */
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
name|NumFunc
condition|;
name|i
operator|++
control|)
block|{
name|f
operator|=
name|FuncVect
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|f
operator|->
name|fn_tflag
operator|!=
literal|'\0'
condition|)
name|nobuffer
operator||=
name|tTrace
argument_list|(
name|argv
argument_list|,
name|f
operator|->
name|fn_tflag
argument_list|,
name|f
operator|->
name|fn_tvect
argument_list|,
name|f
operator|->
name|fn_tsize
argument_list|)
expr_stmt|;
name|Ctx
operator|.
name|ctx_name
operator|=
name|Proc_name
operator|=
name|f
operator|->
name|fn_name
expr_stmt|;
call|(
modifier|*
name|f
operator|->
name|fn_initfn
call|)
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
block|}
end_for

begin_if
if|if
condition|(
name|tTf
argument_list|(
literal|23
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"debug flag 23 is ON!!!! after trace stuff.\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
end_if

begin_comment
comment|/* 	**  Buffer standard output 	** 	**	Since VM/UNIX always buffers, we force non-buffered 	**	output if any trace flags are set. 	*/
end_comment

begin_if
if|if
condition|(
operator|!
name|nobuffer
condition|)
name|set_so_buf
argument_list|()
expr_stmt|;
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
comment|/* if Equel, tell the program to go ahead */
end_comment

begin_if
if|if
condition|(
name|Equel
operator|&&
name|Cm
operator|.
name|cm_myproc
operator|==
literal|1
condition|)
block|{
name|pb_prime
argument_list|(
operator|&
name|pb
argument_list|,
name|PB_REG
argument_list|)
expr_stmt|;
name|pb
operator|.
name|pb_st
operator|=
name|PB_FRONT
expr_stmt|;
name|pb_flush
argument_list|(
operator|&
name|pb
argument_list|)
expr_stmt|;
block|}
end_if

begin_comment
comment|/* 	**  Start executing routines. 	** 	**	Do_seq knows to exit if we get an EOF on the input pipe. 	*/
end_comment

begin_expr_stmt
name|i
operator|=
name|setjmp
argument_list|(
name|CmReset
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|xMONITOR
end_ifdef

begin_expr_stmt
name|markperf
argument_list|(
operator|&
name|CmMonBuf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
endif|xMONITOR
end_endif

begin_expr_stmt
name|initbuf
argument_list|(
name|Qbuf
argument_list|,
name|QbufSize
argument_list|,
name|ERR_QBUF
argument_list|,
name|error
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|clrmem
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|Ctx
argument_list|,
sizeof|sizeof
name|Ctx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Ctx
operator|.
name|ctx_cmark
operator|=
name|Ctx
operator|.
name|ctx_pmark
operator|=
name|markbuf
argument_list|(
name|Qbuf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Ctx
operator|.
name|ctx_name
operator|=
name|Proc_name
operator|=
name|Cm
operator|.
name|cm_myname
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Ctx
operator|.
name|ctx_tvect
operator|=
name|tT
operator|=
name|FuncVect
index|[
literal|0
index|]
operator|->
name|fn_tvect
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|xCTR2
end_ifdef

begin_if
if|if
condition|(
name|tTf
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
condition|)
name|lprintf
argument_list|(
literal|"main: setjmp: %d\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|if
condition|(
name|RubLevel
operator|>=
literal|0
condition|)
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|rubcatch
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|closeall
argument_list|(
name|FALSE
argument_list|,
name|CmOfiles
argument_list|)
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
init|;
condition|;
control|)
block|{
name|Cm
operator|.
name|cm_input
operator|=
name|Cm
operator|.
name|cm_rinput
expr_stmt|;
name|pb
operator|.
name|pb_st
operator|=
name|PB_UNKNOWN
expr_stmt|;
name|do_seq
argument_list|(
operator|&
name|pb
argument_list|)
expr_stmt|;
block|}
end_for

begin_escape
unit|}
end_escape

begin_comment
comment|/* **  RUBPROC -- process rubout signals ** **	This routine does the processing needed on rubouts **	when running with the control module.  It basically **	flushes pipes. ** **	Parameters: **		none. ** **	Returns: **		never ** **	Side Effects: **		Flushes pipes, etc. */
end_comment

begin_expr_stmt
unit|rubproc
operator|(
operator|)
block|{
specifier|register
name|int
name|i
block|;
name|pb_t
name|pb
block|;
specifier|register
name|int
name|stat
block|;
comment|/* 	**  Update the world for consistency. 	*/
name|fflush
argument_list|(
name|stdout
argument_list|)
block|;
name|closecatalog
argument_list|(
name|FALSE
argument_list|)
block|;
name|i
operator|=
name|pageflush
argument_list|(
name|NULL
argument_list|)
block|;
if|if
condition|(
name|i
operator|!=
literal|0
condition|)
name|syserr
argument_list|(
literal|"rubproc: pageflush %d"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|/* 	**  Send SYNC blocks to all processes that are adjacent 	**	in the write direction. 	**  Arrange to ignore blocks from all processes that 	**	are adjacent in the read direction. 	*/
name|pb_prime
argument_list|(
operator|&
name|pb
argument_list|,
name|PB_SYNC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|CM_MAXPROC
condition|;
name|i
operator|++
control|)
block|{
name|stat
operator|=
name|Cm
operator|.
name|cm_proc
index|[
name|i
index|]
operator|.
name|pr_stat
expr_stmt|;
if|if
condition|(
operator|(
name|stat
operator|&
name|PR_RADJCT
operator|)
operator|!=
literal|0
condition|)
name|Syncs
index|[
name|i
index|]
operator|++
expr_stmt|;
if|if
condition|(
operator|(
name|stat
operator|&
name|PR_WADJCT
operator|)
operator|!=
literal|0
condition|)
block|{
name|pb
operator|.
name|pb_proc
operator|=
name|i
expr_stmt|;
name|pb_write
argument_list|(
operator|&
name|pb
argument_list|)
expr_stmt|;
block|}
block|}
end_for

begin_comment
comment|/* 	**  Cleanup and exit. 	*/
end_comment

begin_expr_stmt
name|cm_cleanup
argument_list|(
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

unit|}
end_unit

