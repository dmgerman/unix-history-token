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
literal|"@(#)point.c	5.1 (Berkeley) 5/7/85"
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
file|"gigi.h"
end_include

begin_macro
name|point
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
if|if
condition|(
name|xsc
argument_list|(
name|xi
argument_list|)
operator|!=
name|currentx
operator|||
name|ysc
argument_list|(
name|yi
argument_list|)
operator|!=
name|currenty
condition|)
name|move
argument_list|(
name|xi
argument_list|,
name|yi
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"V[]"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

