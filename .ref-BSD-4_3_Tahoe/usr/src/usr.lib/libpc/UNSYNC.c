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
literal|"@(#)UNSYNC.c 1.4 10/28/83"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_comment
comment|/*  * push back last char read to prepare for formatted read  */
end_comment

begin_expr_stmt
name|UNSYNC
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
if|if
condition|(
operator|(
name|curfile
operator|->
name|funit
operator|&
name|SYNC
operator|)
operator|==
literal|0
condition|)
block|{
name|ungetc
argument_list|(
operator|*
name|curfile
operator|->
name|fileptr
argument_list|,
name|curfile
operator|->
name|fbuf
argument_list|)
expr_stmt|;
block|}
name|curfile
operator|->
name|funit
operator|&=
operator|~
name|EOLN
expr_stmt|;
name|curfile
operator|->
name|funit
operator||=
name|SYNC
expr_stmt|;
block|}
end_block

end_unit

