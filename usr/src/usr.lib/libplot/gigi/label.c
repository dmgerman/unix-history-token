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
file|"gigi.h"
end_include

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
name|printf
argument_list|(
literal|"T(S0 H2 D0 I0) \""
argument_list|)
expr_stmt|;
for|for
control|(
init|;
operator|*
name|s
operator|!=
literal|'\0'
condition|;
name|s
operator|++
control|)
block|{
name|putchar
argument_list|(
operator|*
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|s
operator|==
literal|'"'
condition|)
name|putchar
argument_list|(
literal|'"'
argument_list|)
expr_stmt|;
block|}
name|putchar
argument_list|(
literal|'"'
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

