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
literal|"@(#)WRITEC.c 1.4 6/10/81"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_expr_stmt
name|WRITEC
argument_list|(
name|curfile
argument_list|,
name|d1
argument_list|,
name|d2
argument_list|)
specifier|register
expr|struct
name|iorec
operator|*
name|curfile
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
name|d1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|d2
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
name|fputc
argument_list|(
name|d1
argument_list|,
name|d2
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

