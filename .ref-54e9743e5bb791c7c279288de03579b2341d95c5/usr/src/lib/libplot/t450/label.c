begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)label.c	8.1 (Berkeley) %G%"
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
file|"con.h"
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
name|int
name|i
decl_stmt|,
name|c
decl_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
operator|*
name|s
operator|++
operator|)
operator|!=
literal|'\0'
condition|)
block|{
name|xnow
operator|+=
literal|6
expr_stmt|;
name|spew
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
end_block

end_unit

