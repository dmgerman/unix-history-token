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
literal|"@(#)label.c	5.1 (Berkeley) 5/7/85"
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
file|"dumb.h"
end_include

begin_macro
name|label
argument_list|(
argument|string
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|string
decl_stmt|;
end_decl_stmt

begin_block
block|{
while|while
condition|(
operator|*
name|string
operator|!=
literal|'\0'
operator|&&
name|currentx
operator|<
name|COLS
condition|)
block|{
name|screenmat
index|[
name|currentx
index|]
index|[
name|currenty
index|]
operator|=
operator|*
name|string
operator|++
expr_stmt|;
name|currentx
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|currentx
operator|==
name|COLS
condition|)
name|currentx
operator|=
name|currentx
operator|-
literal|1
expr_stmt|;
block|}
end_block

end_unit

