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
literal|"@(#)ROUND.c 1.3 3/7/81"
decl_stmt|;
end_decl_stmt

begin_function
name|long
name|ROUND
parameter_list|(
name|value
parameter_list|)
name|double
name|value
decl_stmt|;
block|{
if|if
condition|(
name|value
operator|>=
literal|0.0
condition|)
return|return
call|(
name|long
call|)
argument_list|(
name|value
operator|+
literal|0.5
argument_list|)
return|;
return|return
call|(
name|long
call|)
argument_list|(
name|value
operator|-
literal|0.5
argument_list|)
return|;
block|}
end_function

end_unit

