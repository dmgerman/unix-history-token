begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)printerror.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * Print out an execution time error.  */
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
file|"machine.h"
end_include

begin_include
include|#
directive|include
file|"sym.h"
end_include

begin_include
include|#
directive|include
file|"process.h"
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
file|"mappings.h"
end_include

begin_include
include|#
directive|include
file|"pxerrors.h"
end_include

begin_include
include|#
directive|include
file|"process/process.rep"
end_include

begin_macro
name|printerror
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|PROCESS
modifier|*
name|p
decl_stmt|;
name|char
modifier|*
name|filename
decl_stmt|;
name|int
name|c
decl_stmt|;
name|p
operator|=
name|process
expr_stmt|;
if|if
condition|(
name|p
operator|->
name|signo
operator|!=
name|ESIGNAL
operator|&&
name|p
operator|->
name|signo
operator|!=
name|SIGINT
condition|)
block|{
name|error
argument_list|(
literal|"signal %d at px pc %d, lc %d"
argument_list|,
name|p
operator|->
name|signo
argument_list|,
name|p
operator|->
name|pc
argument_list|,
name|pc
argument_list|)
expr_stmt|;
block|}
name|curline
operator|=
name|srcline
argument_list|(
name|pc
argument_list|)
expr_stmt|;
name|curfunc
operator|=
name|whatblock
argument_list|(
name|pc
argument_list|)
expr_stmt|;
name|skimsource
argument_list|(
name|srcfilename
argument_list|(
name|pc
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|->
name|signo
operator|==
name|ESIGNAL
condition|)
block|{
name|printf
argument_list|(
literal|"\nerror at "
argument_list|)
expr_stmt|;
name|printwhere
argument_list|(
name|curline
argument_list|,
name|cursource
argument_list|)
expr_stmt|;
if|if
condition|(
name|errnum
operator|!=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|":  %s"
argument_list|,
name|pxerrmsg
index|[
name|errnum
index|]
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|printf
argument_list|(
literal|"\n\ninterrupt at "
argument_list|)
expr_stmt|;
name|printwhere
argument_list|(
name|curline
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
name|erecover
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

