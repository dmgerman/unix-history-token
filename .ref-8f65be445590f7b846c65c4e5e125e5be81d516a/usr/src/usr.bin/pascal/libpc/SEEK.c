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
literal|"@(#)SEEK.c	1.5 (Berkeley) %G%"
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

begin_comment
comment|/*  * Random access routine  */
end_comment

begin_expr_stmt
name|SEEK
argument_list|(
name|curfile
argument_list|,
name|loc
argument_list|)
specifier|register
expr|struct
name|iorec
operator|*
name|curfile
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|seekptr
modifier|*
name|loc
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|curfile
operator|->
name|funit
operator||=
name|SYNC
expr_stmt|;
name|curfile
operator|->
name|funit
operator|&=
operator|~
operator|(
name|EOFF
operator||
name|EOLN
operator||
name|SPEOLN
operator|)
expr_stmt|;
if|if
condition|(
name|fseek
argument_list|(
name|curfile
operator|->
name|fbuf
argument_list|,
name|loc
operator|->
name|cnt
argument_list|,
literal|0
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|PERROR
argument_list|(
literal|"Could not seek "
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

