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
literal|"@(#)label.c	5.2 (Berkeley) 4/30/85"
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
comment|/*---------------------------------------------------------  *	This routine places a label starting at the current  *	position.  *  *	Results:	None.  *  *	Side Effects:  *	The string indicated by s starting at (curx, cury).  *	The current position is updated accordingly.  *---------------------------------------------------------  */
end_comment

begin_macro
name|label
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|setcolor
argument_list|(
literal|"02"
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
name|curx
operator|+
operator|(
literal|4096
operator|/
name|scale
operator|)
argument_list|,
name|cury
operator|+
operator|(
literal|4096
operator|/
name|scale
operator|)
argument_list|)
expr_stmt|;
name|putc
argument_list|(
literal|'\6'
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
name|s
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|putc
argument_list|(
literal|'\33'
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
operator|+=
operator|(
operator|(
literal|6
operator|*
literal|4096
operator|*
name|strlen
argument_list|(
name|s
argument_list|)
operator|)
operator|+
literal|4000
operator|)
operator|/
name|scale
expr_stmt|;
block|}
end_block

end_unit

