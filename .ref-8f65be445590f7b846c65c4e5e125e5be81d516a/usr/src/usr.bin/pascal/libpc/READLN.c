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
literal|"@(#)READLN.c	1.5 (Berkeley) %G%"
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
name|READLN
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
do|do
block|{
name|IOSYNC
argument_list|(
name|curfile
argument_list|)
expr_stmt|;
name|curfile
operator|->
name|funit
operator||=
name|SYNC
expr_stmt|;
block|}
do|while
condition|(
operator|(
name|curfile
operator|->
name|funit
operator|&
name|EOLN
operator|)
operator|==
literal|0
condition|)
do|;
block|}
end_block

end_unit

