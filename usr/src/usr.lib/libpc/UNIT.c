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
literal|"@(#)UNIT.c 1.2 6/10/81"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_function
name|struct
name|iorec
modifier|*
name|UNIT
parameter_list|(
name|curfile
parameter_list|)
specifier|register
name|struct
name|iorec
modifier|*
name|curfile
decl_stmt|;
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
name|FDEF
condition|)
block|{
name|ERROR
argument_list|(
literal|"%s: Reference to an inactive file\n"
argument_list|,
name|curfile
operator|->
name|pfname
argument_list|)
expr_stmt|;
return|return;
block|}
return|return
name|curfile
return|;
block|}
end_function

end_unit

