begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  */
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
literal|"@(#)move.c	8.1 (Berkeley) 6/4/93"
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
file|"gigi.h"
end_include

begin_macro
name|move
argument_list|(
argument|xi
argument_list|,
argument|yi
argument_list|)
end_macro

begin_decl_stmt
name|int
name|xi
decl_stmt|,
name|yi
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|currentx
operator|=
name|xsc
argument_list|(
name|xi
argument_list|)
expr_stmt|;
name|currenty
operator|=
name|ysc
argument_list|(
name|yi
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"P[%d,%d]"
argument_list|,
name|currentx
argument_list|,
name|currenty
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

