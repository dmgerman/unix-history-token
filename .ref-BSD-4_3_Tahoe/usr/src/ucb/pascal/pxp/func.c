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
literal|"@(#)func.c	5.1 (Berkeley) 6/5/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * pxp - Pascal execution profiler  *  * Bill Joy UCB  * Version 1.2 January 1979  */
end_comment

begin_include
include|#
directive|include
file|"0.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_comment
comment|/*  * A function call  */
end_comment

begin_expr_stmt
name|funccod
argument_list|(
name|r
argument_list|)
specifier|register
name|int
operator|*
name|r
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|call
argument_list|(
name|r
index|[
literal|2
index|]
argument_list|,
name|r
index|[
literal|3
index|]
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

