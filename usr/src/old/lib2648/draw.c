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
literal|"@(#)draw.c	5.1 (Berkeley) 4/26/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * draw a line from the current place to (x,y).  Such lines are  * supposed to be horizontal, and are affected by the current mode.  */
end_comment

begin_include
include|#
directive|include
file|"2648.h"
end_include

begin_macro
name|draw
argument_list|(
argument|x
argument_list|,
argument|y
argument_list|)
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|TRACE
if|if
condition|(
name|trace
condition|)
block|{
name|fprintf
argument_list|(
name|trace
argument_list|,
literal|"draw(%d,%d)\n"
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|sync
argument_list|()
expr_stmt|;
name|escseq
argument_list|(
name|ESCP
argument_list|)
expr_stmt|;
name|motion
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|_supx
operator|=
name|x
expr_stmt|;
name|_supy
operator|=
name|y
expr_stmt|;
block|}
end_block

end_unit

