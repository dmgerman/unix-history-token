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
literal|"@(#)TELL.c 1.2 %G%"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_comment
comment|/*  * Find current location  */
end_comment

begin_function
name|long
name|TELL
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
name|long
name|loc
decl_stmt|;
name|loc
operator|=
name|ftell
argument_list|(
name|curfile
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|curfile
operator|->
name|funit
operator||
name|SYNC
operator|)
operator|==
literal|0
condition|)
name|loc
operator|+=
literal|1
expr_stmt|;
return|return
name|loc
return|;
block|}
end_function

end_unit

