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
literal|"@(#)movecurs.c	5.1 (Berkeley) 4/26/85"
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
file|"2648.h"
end_include

begin_macro
name|movecurs
argument_list|(
argument|x
argument_list|,
argument|y
argument_list|)
end_macro

begin_block
block|{
name|char
name|mes
index|[
literal|20
index|]
decl_stmt|;
if|if
condition|(
name|x
operator|==
name|_curx
operator|&&
name|y
operator|==
name|_cury
condition|)
return|return;
name|sprintf
argument_list|(
name|mes
argument_list|,
literal|"%d,%do"
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|escseq
argument_list|(
name|ESCD
argument_list|)
expr_stmt|;
name|outstr
argument_list|(
name|mes
argument_list|)
expr_stmt|;
name|escseq
argument_list|(
name|NONE
argument_list|)
expr_stmt|;
name|_curx
operator|=
name|x
expr_stmt|;
name|_cury
operator|=
name|y
expr_stmt|;
block|}
end_block

end_unit

