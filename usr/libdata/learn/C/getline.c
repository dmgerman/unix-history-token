begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  */
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
literal|"@(#)getline.c	8.1 (Berkeley) 6/6/93"
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
file|<stdio.h>
end_include

begin_macro
name|getline
argument_list|(
argument|s
argument_list|,
argument|lim
argument_list|)
end_macro

begin_comment
comment|/* get line into s, return length */
end_comment

begin_decl_stmt
name|char
name|s
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lim
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|c
decl_stmt|,
name|i
decl_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|--
name|lim
operator|>
literal|0
operator|&&
operator|(
name|c
operator|=
name|getchar
argument_list|()
operator|)
operator|!=
name|EOF
operator|&&
name|c
operator|!=
literal|'\n'
condition|)
name|s
index|[
name|i
operator|++
index|]
operator|=
name|c
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'\n'
condition|)
name|s
index|[
name|i
operator|++
index|]
operator|=
name|c
expr_stmt|;
name|s
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|i
operator|)
return|;
block|}
end_block

end_unit

