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
literal|"@(#)FLUSH.c	1.3 (Berkeley) %G%"
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
name|FLUSH
argument_list|(
name|curfile
argument_list|)
specifier|register
expr|struct
name|iorec
operator|*
name|curfile
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|if
condition|(
name|curfile
operator|->
name|fblk
operator|>=
name|MAXFILES
operator|||
name|_actfile
index|[
name|curfile
operator|->
name|fblk
index|]
operator|!=
name|curfile
condition|)
block|{
name|ERROR
argument_list|(
literal|"Reference to an inactive file\n"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|curfile
operator|->
name|funit
operator|&
name|FWRITE
condition|)
block|{
name|fflush
argument_list|(
name|curfile
operator|->
name|fbuf
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

