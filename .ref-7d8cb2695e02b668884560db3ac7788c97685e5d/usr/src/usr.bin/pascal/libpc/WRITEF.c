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
literal|"@(#)WRITEF.c	1.5 (Berkeley) %G%"
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
name|WRITEF
argument_list|(
name|curfile
argument_list|,
name|d1
argument_list|,
name|d2
argument_list|,
name|d3
argument_list|,
name|d4
argument_list|,
name|d5
argument_list|,
name|d6
argument_list|,
name|d7
argument_list|,
name|d8
argument_list|)
specifier|register
expr|struct
name|iorec
operator|*
name|curfile
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|FILE
modifier|*
name|d1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|d2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|d3
decl_stmt|,
name|d4
decl_stmt|,
name|d5
decl_stmt|,
name|d6
decl_stmt|,
name|d7
decl_stmt|,
name|d8
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|curfile
operator|->
name|funit
operator|&
name|FREAD
condition|)
block|{
name|ERROR
argument_list|(
literal|"%s: Attempt to write, but open for reading\n"
argument_list|,
name|curfile
operator|->
name|pfname
argument_list|)
expr_stmt|;
return|return;
block|}
name|fprintf
argument_list|(
name|d1
argument_list|,
name|d2
argument_list|,
name|d3
argument_list|,
name|d4
argument_list|,
name|d5
argument_list|,
name|d6
argument_list|,
name|d7
argument_list|,
name|d8
argument_list|)
expr_stmt|;
if|if
condition|(
name|ferror
argument_list|(
name|curfile
operator|->
name|fbuf
argument_list|)
condition|)
block|{
name|PERROR
argument_list|(
literal|"Could not write to "
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

