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
literal|"@(#)circle.c	5.1 (Berkeley) 5/7/85"
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
name|circle
argument_list|(
argument|xc
argument_list|,
argument|yc
argument_list|,
argument|r
argument_list|)
end_macro

begin_decl_stmt
name|int
name|xc
decl_stmt|,
name|yc
decl_stmt|,
name|r
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|r
operator|<
literal|1
condition|)
block|{
name|point
argument_list|(
name|xc
argument_list|,
name|yc
argument_list|)
expr_stmt|;
return|return;
block|}
name|move
argument_list|(
name|xc
argument_list|,
name|yc
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"C[%d]"
argument_list|,
name|r
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

