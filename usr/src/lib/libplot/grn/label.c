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
literal|"@(#)label.c	6.1 (Berkeley) 8/29/86"
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
comment|/*---------------------------------------------------------  *	This routine places a label starting at the current  *	position.  *  *	Results:	None.  *  *	Side Effects:  *	The string indicated by s starting at (curx, cury).  *	The current position is NOT updated.  *---------------------------------------------------------  */
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
literal|"BOTLEFT\n"
argument_list|)
expr_stmt|;
name|outcurxy
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"*\n%d %d\n%d %s\n"
argument_list|,
name|FONTSTYLE
argument_list|,
name|FONTSIZE
argument_list|,
name|strlen
argument_list|(
name|s
argument_list|)
operator|-
literal|1
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

