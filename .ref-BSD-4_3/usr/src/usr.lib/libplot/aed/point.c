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
literal|"@(#)point.c	5.2 (Berkeley) 4/30/85"
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
file|"aed.h"
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
name|setcolor
argument_list|(
literal|"01"
argument_list|)
expr_stmt|;
name|putc
argument_list|(
literal|'Q'
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|outxy20
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"O01"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|stdout
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

