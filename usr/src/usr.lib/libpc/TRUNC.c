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
literal|"@(#)TRUNC.c 1.2 3/7/81"
decl_stmt|;
end_decl_stmt

begin_function
name|long
name|TRUNC
parameter_list|(
name|value
parameter_list|)
name|double
name|value
decl_stmt|;
block|{
return|return
call|(
name|long
call|)
argument_list|(
name|value
argument_list|)
return|;
block|}
end_function

end_unit

