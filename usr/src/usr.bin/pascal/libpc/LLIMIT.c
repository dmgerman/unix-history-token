begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1979 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)LLIMIT.c	1.4 (Berkeley) %G%"
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
file|"h00vars.h"
end_include

begin_expr_stmt
name|LLIMIT
argument_list|(
name|curfile
argument_list|,
name|limit
argument_list|)
specifier|register
expr|struct
name|iorec
operator|*
name|curfile
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|long
name|limit
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|limit
operator|<=
literal|0
condition|)
name|limit
operator|=
literal|0x7fffffff
expr_stmt|;
name|curfile
operator|->
name|llimit
operator|=
name|limit
expr_stmt|;
if|if
condition|(
name|curfile
operator|->
name|lcount
operator|>=
name|curfile
operator|->
name|llimit
condition|)
block|{
name|ERROR
argument_list|(
literal|"%s: Line limit exceeded\n"
argument_list|,
name|curfile
operator|->
name|pfname
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
end_block

end_unit

