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
literal|"@(#)ACTFILE.c 1.1 10/30/80"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_function
name|FILE
modifier|*
name|ACTFILE
parameter_list|(
name|curfile
parameter_list|)
name|struct
name|iorec
modifier|*
name|curfile
decl_stmt|;
block|{
return|return
name|curfile
operator|->
name|fbuf
return|;
block|}
end_function

end_unit

