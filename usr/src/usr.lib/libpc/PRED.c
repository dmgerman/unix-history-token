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
literal|"@(#)PRED.c 1.4 6/10/81"
decl_stmt|;
end_decl_stmt

begin_function
name|long
name|PRED
parameter_list|(
name|value
parameter_list|,
name|lower
parameter_list|,
name|upper
parameter_list|)
name|long
name|value
decl_stmt|;
name|long
name|lower
decl_stmt|;
name|long
name|upper
decl_stmt|;
block|{
if|if
condition|(
name|value
operator|==
name|lower
condition|)
block|{
name|ERROR
argument_list|(
literal|"Cannot take pred of first element of a range\n"
argument_list|)
expr_stmt|;
return|return;
block|}
name|value
operator|--
expr_stmt|;
if|if
condition|(
name|value
operator|<
name|lower
operator|||
name|value
operator|>
name|upper
condition|)
block|{
name|ERROR
argument_list|(
literal|"Value of %D is out of range\n"
argument_list|,
name|value
argument_list|)
expr_stmt|;
return|return;
block|}
return|return
name|value
return|;
block|}
end_function

end_unit

