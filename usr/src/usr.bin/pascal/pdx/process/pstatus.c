begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1982 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)pstatus.c 1.2 %G%"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * process status routines  */
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
file|"breakpoint.h"
end_include

begin_include
include|#
directive|include
file|"source.h"
end_include

begin_include
include|#
directive|include
file|"object.h"
end_include

begin_include
include|#
directive|include
file|"process.rep"
end_include

begin_comment
comment|/*  * Print the status of the process.  * This routine does not return.  */
end_comment

begin_macro
name|printstatus
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|process
operator|->
name|signo
operator|==
name|SIGINT
condition|)
block|{
name|isstopped
operator|=
name|TRUE
expr_stmt|;
name|printerror
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|isbperr
argument_list|()
operator|&&
name|isstopped
condition|)
block|{
name|printf
argument_list|(
literal|"stopped at "
argument_list|)
expr_stmt|;
if|if
condition|(
name|curline
operator|>
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"line %d"
argument_list|,
name|curline
argument_list|)
expr_stmt|;
if|if
condition|(
name|nlhdr
operator|.
name|nfiles
operator|>
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|" in file %s"
argument_list|,
name|cursource
argument_list|)
expr_stmt|;
block|}
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
name|printlines
argument_list|(
name|curline
argument_list|,
name|curline
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|#
directive|if
operator|(
name|isvaxpx
operator|)
name|printf
argument_list|(
literal|"location %d\n"
argument_list|,
name|pc
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"location 0x%x\n"
argument_list|,
name|pc
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|printinst
argument_list|(
name|pc
argument_list|,
name|pc
argument_list|)
expr_stmt|;
block|}
name|erecover
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|isstopped
operator|=
name|FALSE
expr_stmt|;
name|fixbps
argument_list|()
expr_stmt|;
name|fixintr
argument_list|()
expr_stmt|;
if|if
condition|(
name|process
operator|->
name|status
operator|==
name|FINISHED
condition|)
block|{
name|quit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printerror
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_block

begin_comment
comment|/*  * Return TRUE if the process is finished.  */
end_comment

begin_function
name|BOOLEAN
name|isfinished
parameter_list|(
name|p
parameter_list|)
name|PROCESS
modifier|*
name|p
decl_stmt|;
block|{
return|return
operator|(
name|p
operator|->
name|status
operator|==
name|FINISHED
operator|)
return|;
block|}
end_function

end_unit

