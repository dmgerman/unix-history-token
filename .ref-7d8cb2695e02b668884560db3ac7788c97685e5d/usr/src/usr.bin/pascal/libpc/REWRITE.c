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
literal|"@(#)REWRITE.c	1.4 (Berkeley) %G%"
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
name|REWRITE
argument_list|(
name|filep
argument_list|,
name|name
argument_list|,
name|maxnamlen
argument_list|,
name|datasize
argument_list|)
specifier|register
expr|struct
name|iorec
operator|*
name|filep
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|maxnamlen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|datasize
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|filep
operator|=
name|GETNAME
argument_list|(
name|filep
argument_list|,
name|name
argument_list|,
name|maxnamlen
argument_list|,
name|datasize
argument_list|)
expr_stmt|;
name|filep
operator|->
name|fbuf
operator|=
name|fopen
argument_list|(
name|filep
operator|->
name|fname
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
if|if
condition|(
name|filep
operator|->
name|fbuf
operator|==
name|NULL
condition|)
block|{
name|PERROR
argument_list|(
literal|"Could not create "
argument_list|,
name|filep
operator|->
name|pfname
argument_list|)
expr_stmt|;
return|return;
block|}
name|filep
operator|->
name|funit
operator||=
operator|(
name|EOFF
operator||
name|FWRITE
operator|)
expr_stmt|;
if|if
condition|(
name|filep
operator|->
name|fblk
operator|>
name|PREDEF
condition|)
block|{
name|setbuf
argument_list|(
name|filep
operator|->
name|fbuf
argument_list|,
operator|&
name|filep
operator|->
name|buf
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

