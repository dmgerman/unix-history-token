begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)move.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"aed.h"
end_include

begin_comment
comment|/*---------------------------------------------------------  *	This routine moves the current point to (x,y).  *  *	Results:	None.  *	Side Effects:	As above.  *---------------------------------------------------------  */
end_comment

begin_macro
name|move
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

