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
literal|"@(#)printnews.c	5.1 (Berkeley) 6/5/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * Print out news during single step tracing.  *  * We have to handle all the single stepping possibilities,  * including combinations.  A combination of single stepping  * by line and by instruction causes "curline" to be 0 but  * "ss_lines" to be TRUE.  We avoid trying to print lines in this case.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"breakpoint.h"
end_include

begin_include
include|#
directive|include
file|"sym.h"
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
file|"machine.h"
end_include

begin_macro
name|printnews
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|ss_variables
condition|)
block|{
name|prvarnews
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|trcond
argument_list|()
condition|)
block|{
if|if
condition|(
name|ss_lines
operator|&&
name|curline
operator|>
literal|0
condition|)
block|{
name|skimsource
argument_list|(
name|srcfilename
argument_list|(
name|pc
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"trace:  "
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
if|if
condition|(
name|ss_instructions
condition|)
block|{
name|printf
argument_list|(
literal|"inst trace: "
argument_list|)
expr_stmt|;
name|printinst
argument_list|(
name|pc
argument_list|,
name|pc
argument_list|)
expr_stmt|;
block|}
block|}
name|bpact
argument_list|()
expr_stmt|;
if|if
condition|(
name|stopcond
argument_list|()
condition|)
block|{
name|isstopped
operator|=
name|TRUE
expr_stmt|;
name|curline
operator|=
name|srcline
argument_list|(
name|pc
argument_list|)
expr_stmt|;
name|printstatus
argument_list|()
expr_stmt|;
block|}
block|}
end_block

end_unit

