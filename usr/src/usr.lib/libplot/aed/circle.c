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
literal|"@(#)circle.c	5.2 (Berkeley) 4/30/85"
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
comment|/*---------------------------------------------------------  *	Circle draws a circle.  *  *	Results:	None.  *  *	Side Effects:  *	A circle of radius r is drawn at (x,y).  *---------------------------------------------------------  */
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
name|char
name|buf
index|[
literal|3
index|]
decl_stmt|;
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
name|putc
argument_list|(
literal|'O'
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|chex
argument_list|(
operator|(
name|r
operator|*
name|scale
operator|)
operator|>>
literal|12
argument_list|,
name|buf
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
name|buf
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
block|}
end_block

end_unit

