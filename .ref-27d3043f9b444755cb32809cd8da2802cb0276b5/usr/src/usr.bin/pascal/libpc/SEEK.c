begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)SEEK.c 1.1 %G%"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_include
include|#
directive|include
file|"h01errs.h"
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
name|long
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
if|if
condition|(
name|fseek
argument_list|(
name|curfile
operator|->
name|fbuf
argument_list|,
name|loc
argument_list|,
literal|0
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|ERROR
argument_list|(
name|ESEEK
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

