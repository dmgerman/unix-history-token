begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)move.c	5.1 (Berkeley) 9/21/85"
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
file|"imp.h"
end_include

begin_macro
name|move
argument_list|(
argument|xi
argument_list|,
argument|yi
argument_list|)
end_macro

begin_block
block|{
name|imPx
operator|=
name|xi
expr_stmt|;
name|imPy
operator|=
name|yi
expr_stmt|;
block|}
end_block

end_unit

