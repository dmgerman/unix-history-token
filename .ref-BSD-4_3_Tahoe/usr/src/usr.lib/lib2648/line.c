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
literal|"@(#)line.c	5.1 (Berkeley) 4/30/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * line: draw a line from point 1 to point 2.  */
end_comment

begin_include
include|#
directive|include
file|"2648.h"
end_include

begin_macro
name|line
argument_list|(
argument|x1
argument_list|,
argument|y1
argument_list|,
argument|x2
argument_list|,
argument|y2
argument_list|)
end_macro

begin_decl_stmt
name|int
name|x1
decl_stmt|,
name|y1
decl_stmt|,
name|x2
decl_stmt|,
name|y2
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|TRACE
if|if
condition|(
name|trace
condition|)
name|fprintf
argument_list|(
name|trace
argument_list|,
literal|"line((%d, %d), (%d, %d)),"
argument_list|,
name|x1
argument_list|,
name|y1
argument_list|,
name|x2
argument_list|,
name|y2
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|x1
operator|==
name|_penx
operator|&&
name|y1
operator|==
name|_peny
condition|)
block|{
comment|/* 		 * Get around a bug in the HP terminal where one point 		 * lines don't get drawn more than once. 		 */
name|move
argument_list|(
name|x1
argument_list|,
name|y1
operator|+
literal|1
argument_list|)
expr_stmt|;
name|sync
argument_list|()
expr_stmt|;
block|}
name|move
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|)
expr_stmt|;
name|draw
argument_list|(
name|x2
argument_list|,
name|y2
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

