begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"monitor.h"
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
argument|@(#)quit.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  QUIT INGRES ** **	This routine starts the death of the other processes.  It **	then prints out the logout message, and then waits for the **	rest of the system to die.  Note, however, that no relations **	are removed; this must be done using the PURGE command. ** **	Trace Flags: **		35 */
end_comment

begin_comment
comment|/* list of fatal signals */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Siglist
index|[]
init|=
block|{
literal|"Signal 0"
block|,
literal|"hangup"
block|,
literal|"interrupt"
block|,
literal|"quit"
block|,
literal|"illegal instruction"
block|,
literal|"trace trap"
block|,
literal|"IOT"
block|,
literal|"EMT"
block|,
literal|"floating point exception"
block|,
literal|"killed"
block|,
literal|"bus error"
block|,
literal|"segmentation violation"
block|,
literal|"bad system call"
block|,
literal|"broken pipe"
block|,
literal|"alarm"
block|, }
decl_stmt|;
end_decl_stmt

begin_macro
name|quit
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|ndx
decl_stmt|;
specifier|register
name|int
name|pidptr
decl_stmt|;
specifier|register
name|int
name|err
decl_stmt|;
name|char
name|buf
index|[
literal|100
index|]
decl_stmt|;
name|int
name|status
decl_stmt|;
name|int
name|pidlist
index|[
literal|50
index|]
decl_stmt|;
specifier|extern
name|int
function_decl|(
modifier|*
name|ExitFn
function_decl|)
parameter_list|()
function_decl|;
extern|extern		exit(
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|indexx
index|[
literal|0400
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|SysIdent
index|[]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|xMTR1
end_ifdef

begin_if
if|if
condition|(
name|tTf
argument_list|(
literal|35
argument_list|,
operator|-
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"entered quit\n"
argument_list|)
expr_stmt|;
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INTERCEPT ALL FURTHER INTERRUPTS */
end_comment

begin_expr_stmt
name|signal
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|signal
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ExitFn
operator|=
name|exit
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|cm_close
argument_list|()
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|xMTR3
end_ifdef

begin_if
if|if
condition|(
name|tTf
argument_list|(
literal|35
argument_list|,
literal|2
argument_list|)
condition|)
name|printf
argument_list|(
literal|"unlinking %s\n"
argument_list|,
name|Qbname
argument_list|)
expr_stmt|;
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REMOVE THE QUERY-BUFFER FILE */
end_comment

begin_expr_stmt
name|fclose
argument_list|(
name|Qryiop
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|unlink
argument_list|(
name|Qbname
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|Trapfile
operator|!=
name|NULL
condition|)
name|fclose
argument_list|(
name|Trapfile
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|pidptr
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|err
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* clear out the system error index table */
end_comment

begin_for
for|for
control|(
name|ndx
operator|=
literal|0
init|;
name|ndx
operator|<
literal|0400
condition|;
name|ndx
operator|++
control|)
name|indexx
index|[
name|ndx
index|]
operator|=
literal|0
expr_stmt|;
end_for

begin_comment
comment|/* wait for all process to terminate */
end_comment

begin_while
while|while
condition|(
operator|(
name|ndx
operator|=
name|wait
argument_list|(
operator|&
name|status
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
block|{
ifdef|#
directive|ifdef
name|xMTR2
if|if
condition|(
name|tTf
argument_list|(
literal|35
argument_list|,
literal|5
argument_list|)
condition|)
name|printf
argument_list|(
literal|"quit: pid %u: %d/%d\n"
argument_list|,
name|ndx
argument_list|,
name|status
operator|>>
literal|8
argument_list|,
name|status
operator|&
literal|0177
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|pidlist
index|[
name|pidptr
operator|++
index|]
operator|=
name|ndx
expr_stmt|;
if|if
condition|(
operator|(
name|status
operator|&
literal|0177
operator|)
operator|!=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"%d: "
argument_list|,
name|ndx
argument_list|)
expr_stmt|;
name|ndx
operator|=
name|status
operator|&
literal|0177
expr_stmt|;
if|if
condition|(
name|ndx
operator|>
sizeof|sizeof
name|Siglist
operator|/
sizeof|sizeof
name|Siglist
index|[
literal|0
index|]
condition|)
name|printf
argument_list|(
literal|"Abnormal Termination %d"
argument_list|,
name|ndx
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|Siglist
index|[
name|ndx
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|status
operator|&
literal|0200
operator|)
operator|!=
literal|0
condition|)
name|printf
argument_list|(
literal|" -- Core Dumped"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|err
operator|++
expr_stmt|;
name|indexx
index|[
literal|0377
operator|-
name|ndx
index|]
operator|++
expr_stmt|;
block|}
else|else
block|{
name|indexx
index|[
operator|(
name|status
operator|>>
literal|8
operator|)
operator|&
literal|0377
index|]
operator|++
expr_stmt|;
block|}
block|}
end_while

begin_if
if|if
condition|(
name|err
condition|)
block|{
name|printf
argument_list|(
literal|"pid list:"
argument_list|)
expr_stmt|;
for|for
control|(
name|ndx
operator|=
literal|0
init|;
name|ndx
operator|<
name|pidptr
condition|;
name|ndx
operator|++
control|)
name|printf
argument_list|(
literal|" %u"
argument_list|,
name|pidlist
index|[
name|ndx
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_if

begin_comment
comment|/* print index of system errors */
end_comment

begin_expr_stmt
name|err
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|ndx
operator|=
literal|1
init|;
name|ndx
operator|<=
literal|0377
condition|;
name|ndx
operator|++
control|)
block|{
if|if
condition|(
name|indexx
index|[
name|ndx
index|]
operator|==
literal|0
condition|)
continue|continue;
if|if
condition|(
name|ndx
operator|<=
name|sys_nerr
condition|)
block|{
if|if
condition|(
name|err
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"\nUNIX error dictionary:\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%3d: %s\n"
argument_list|,
name|ndx
argument_list|,
name|sys_errlist
index|[
name|ndx
index|]
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|err
operator|==
literal|0
condition|)
name|err
operator|=
name|ndx
expr_stmt|;
block|}
end_for

begin_if
if|if
condition|(
name|err
operator|>
literal|0
operator|&&
name|err
operator|<=
name|sys_nerr
condition|)
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/* PRINT LOGOUT CUE ? */
end_comment

begin_if
if|if
condition|(
name|Nodayfile
operator|>=
literal|0
condition|)
block|{
name|time
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s logout\n%s"
argument_list|,
name|SysIdent
argument_list|,
name|ctime
argument_list|(
name|buf
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|getuser
argument_list|(
name|Usercode
argument_list|,
name|buf
argument_list|)
operator|==
literal|0
condition|)
block|{
for|for
control|(
name|ndx
operator|=
literal|0
init|;
name|buf
index|[
name|ndx
index|]
condition|;
name|ndx
operator|++
control|)
if|if
condition|(
name|buf
index|[
name|ndx
index|]
operator|==
literal|':'
condition|)
break|break;
name|buf
index|[
name|ndx
index|]
operator|=
literal|0
expr_stmt|;
name|printf
argument_list|(
literal|"goodbye %s "
argument_list|,
name|buf
argument_list|)
expr_stmt|;
block|}
else|else
name|printf
argument_list|(
literal|"goodbye "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-- come again\n"
argument_list|)
expr_stmt|;
block|}
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|xMTR1
end_ifdef

begin_if
if|if
condition|(
name|tTf
argument_list|(
literal|35
argument_list|,
literal|3
argument_list|)
condition|)
name|printf
argument_list|(
literal|"quit: exit(%d)\n"
argument_list|,
name|err
argument_list|)
expr_stmt|;
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|exit
argument_list|(
name|err
argument_list|)
expr_stmt|;
end_expr_stmt

unit|}
end_unit

