begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)point.c	6.1 (Berkeley) 8/29/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|"grnplot.h"
end_include

begin_comment
comment|/*---------------------------------------------------------  *	This routine plots a single point.  *  *	Results:	None.  *  *	Side Effects:  *	A single point is displayed on the screen.  *	The point is made the current point.  *---------------------------------------------------------  */
end_comment

begin_macro
name|point
argument_list|(
argument|x
argument_list|,
argument|y
argument_list|)
end_macro

begin_decl_stmt
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|move
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|label
argument_list|(
name|POINTSTRING
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

