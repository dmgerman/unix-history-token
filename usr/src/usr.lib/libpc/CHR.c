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
literal|"@(#)CHR.c 1.4 11/12/82"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|ECHR
index|[]
init|=
literal|"Argument to chr of %D is out of range\n"
decl_stmt|;
end_decl_stmt

begin_function
name|char
name|CHR
parameter_list|(
name|value
parameter_list|)
name|unsigned
name|long
name|value
decl_stmt|;
block|{
if|if
condition|(
name|value
operator|>
literal|127
condition|)
block|{
name|ERROR
argument_list|(
name|ECHR
argument_list|,
name|value
argument_list|)
expr_stmt|;
return|return;
block|}
return|return
operator|(
name|char
operator|)
name|value
return|;
block|}
end_function

end_unit

