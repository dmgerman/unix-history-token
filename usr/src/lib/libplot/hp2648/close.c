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
literal|"@(#)close.c	5.1 (Berkeley) 5/7/85"
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
file|"hp2648.h"
end_include

begin_macro
name|closepl
argument_list|()
end_macro

begin_block
block|{
name|putchar
argument_list|(
literal|'Z'
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
if|if
condition|(
name|shakehands
operator|==
name|TRUE
condition|)
block|{
name|stty
argument_list|(
name|fildes
argument_list|,
operator|&
name|sarg
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|fildes
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

