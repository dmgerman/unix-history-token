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
literal|"@(#)PUT.c 1.3 6/10/81"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_expr_stmt
name|PUT
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
name|fwrite
argument_list|(
name|curfile
operator|->
name|fileptr
argument_list|,
operator|(
name|int
operator|)
name|curfile
operator|->
name|fsize
argument_list|,
literal|1
argument_list|,
name|curfile
operator|->
name|fbuf
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

