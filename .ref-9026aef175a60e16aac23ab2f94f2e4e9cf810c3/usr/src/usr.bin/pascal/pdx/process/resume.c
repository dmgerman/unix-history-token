begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)resume.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * Resume execution, first setting appropriate registers.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"process.h"
end_include

begin_include
include|#
directive|include
file|"machine.h"
end_include

begin_include
include|#
directive|include
file|"main.h"
end_include

begin_include
include|#
directive|include
file|"process.rep"
end_include

begin_include
include|#
directive|include
file|"runtime/frame.rep"
end_include

begin_include
include|#
directive|include
file|"machine/pxerrors.h"
end_include

begin_include
include|#
directive|include
file|"pxinfo.h"
end_include

begin_comment
comment|/*  * Resume execution, set (get) pcode location counter before (after) resuming.  */
end_comment

begin_macro
name|resume
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|PROCESS
modifier|*
name|p
decl_stmt|;
name|p
operator|=
name|process
expr_stmt|;
do|do
block|{
if|if
condition|(
name|option
argument_list|(
literal|'e'
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"execution resumes at pc 0x%x, lc %d\n"
argument_list|,
name|process
operator|->
name|pc
argument_list|,
name|pc
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
name|pcont
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|dread
argument_list|(
operator|&
name|pc
argument_list|,
name|PCADDR
argument_list|,
sizeof|sizeof
argument_list|(
name|pc
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Get pcode pc */
if|if
condition|(
name|option
argument_list|(
literal|'e'
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"execution stops at pc 0x%x, lc %d on sig %d\n"
argument_list|,
name|process
operator|->
name|pc
argument_list|,
name|pc
argument_list|,
name|p
operator|->
name|signo
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
block|}
do|while
condition|(
name|p
operator|->
name|signo
operator|==
name|SIGCONT
condition|)
do|;
if|if
condition|(
name|option
argument_list|(
literal|'r'
argument_list|)
operator|&&
name|p
operator|->
name|signo
operator|!=
literal|0
condition|)
block|{
name|choose
argument_list|()
expr_stmt|;
block|}
comment|/*      * If px implements a breakpoint by executing a halt instruction      * the real pc must be incremented to skip over it.      *      * Currently, px sends itself a signal so no incrementing is needed.      * 	if (isbperr()) { 	    p->pc++; 	}      */
block|}
end_block

begin_comment
comment|/*  * Under the -r option, we offer the opportunity to just get  * the px traceback and not actually enter the debugger.  *  * If the standard input is not a tty but standard error is,  * change standard input to be /dev/tty.  */
end_comment

begin_function
name|LOCAL
name|choose
parameter_list|()
block|{
specifier|register
name|int
name|c
decl_stmt|;
if|if
condition|(
operator|!
name|isterm
argument_list|(
name|stdin
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|isterm
argument_list|(
name|stderr
argument_list|)
operator|||
name|freopen
argument_list|(
literal|"/dev/tty"
argument_list|,
literal|"r"
argument_list|,
name|stdin
argument_list|)
operator|==
name|NIL
condition|)
block|{
name|unsetsigtraces
argument_list|(
name|process
argument_list|)
expr_stmt|;
name|pcont
argument_list|(
name|process
argument_list|)
expr_stmt|;
name|quit
argument_list|(
name|process
operator|->
name|exitval
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\nProgram error"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\nDo you wish to enter the debugger? "
argument_list|)
expr_stmt|;
name|c
operator|=
name|getchar
argument_list|()
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'n'
condition|)
block|{
name|unsetsigtraces
argument_list|(
name|process
argument_list|)
expr_stmt|;
name|pcont
argument_list|(
name|process
argument_list|)
expr_stmt|;
name|quit
argument_list|(
name|process
operator|->
name|exitval
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
name|c
operator|!=
literal|'\n'
operator|&&
name|c
operator|!=
name|EOF
condition|)
block|{
name|c
operator|=
name|getchar
argument_list|()
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\nEntering debugger ..."
argument_list|)
expr_stmt|;
name|init
argument_list|()
expr_stmt|;
name|option
argument_list|(
literal|'r'
argument_list|)
operator|=
name|FALSE
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|" type 'help' for help.\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

