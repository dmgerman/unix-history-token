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
literal|"@(#)circle.c	6.1 (Berkeley) 8/29/86"
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
comment|/*---------------------------------------------------------  *	Circle draws a circle.  *  *	Results:	None.  *  *	Side Effects:  *	A circle of radius r is drawn at (x,y).  *	The current position is set to (x,y);  *---------------------------------------------------------  */
end_comment

begin_macro
name|circle
argument_list|(
argument|x
argument_list|,
argument|y
argument_list|,
argument|r
argument_list|)
end_macro

begin_decl_stmt
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|r
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|!
name|ingrnfile
condition|)
name|erase
argument_list|()
expr_stmt|;
name|endvector
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"ARC\n"
argument_list|)
expr_stmt|;
name|outxy
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|outxy
argument_list|(
name|x
operator|+
name|r
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|outxy
argument_list|(
name|x
argument_list|,
name|y
operator|+
name|r
argument_list|)
expr_stmt|;
name|outxy
argument_list|(
name|x
argument_list|,
name|y
operator|-
name|r
argument_list|)
expr_stmt|;
name|outxy
argument_list|(
name|x
operator|+
name|r
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|outxy
argument_list|(
name|x
operator|-
name|r
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"*\n%d 0\n0\n"
argument_list|,
name|linestyle
argument_list|)
expr_stmt|;
name|curx
operator|=
name|x
expr_stmt|;
name|cury
operator|=
name|y
expr_stmt|;
block|}
end_block

end_unit

