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
literal|"@(#)GET.c	1.3 (Berkeley) %G%"
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
name|GET
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
name|funit
operator|&
name|FWRITE
condition|)
block|{
name|ERROR
argument_list|(
literal|"%s: Attempt to read, but open for writing\n"
argument_list|,
name|curfile
operator|->
name|pfname
argument_list|)
expr_stmt|;
return|return;
block|}
name|IOSYNC
argument_list|(
name|curfile
argument_list|)
expr_stmt|;
if|if
condition|(
name|curfile
operator|->
name|funit
operator|&
name|EOFF
condition|)
block|{
name|ERROR
argument_list|(
literal|"%s: Tried to read past end of file\n"
argument_list|,
name|curfile
operator|->
name|pfname
argument_list|)
expr_stmt|;
return|return;
block|}
name|curfile
operator|->
name|funit
operator||=
name|SYNC
expr_stmt|;
block|}
end_block

end_unit

