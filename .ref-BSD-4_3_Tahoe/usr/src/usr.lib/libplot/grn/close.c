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
literal|"@(#)close.c	6.1 (Berkeley) 8/29/86"
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
comment|/*---------------------------------------------------------  *	Closepl ends the gremlin file  *  *	Results:	None.  *  *	Side Effects:  *---------------------------------------------------------  */
end_comment

begin_macro
name|closepl
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
operator|!
name|ingrnfile
condition|)
return|return;
name|endvector
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"-1\n"
argument_list|)
expr_stmt|;
name|ingrnfile
operator|=
literal|0
expr_stmt|;
block|}
end_block

end_unit

