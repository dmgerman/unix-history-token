begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Header for PCH test cxx1z-init-statement.cpp
end_comment

begin_function
name|constexpr
name|int
name|test_if
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|int
name|a
init|=
operator|++
name|x
condition|;
name|a
operator|==
literal|0
block|)
block|{
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_elseif
elseif|else
if|if
condition|(
operator|++
name|a
empty_stmt|;
end_elseif

begin_expr_stmt
name|a
operator|==
literal|2
end_expr_stmt

begin_block
unit|)
block|{
return|return
literal|0
return|;
block|}
end_block

begin_return
return|return
literal|2
return|;
end_return

begin_function
unit|}  constexpr
name|int
name|test_switch
parameter_list|(
name|int
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|int
name|a
init|=
operator|++
name|x
condition|; a)
block|{
case|case
literal|0
case|:
return|return
operator|-
literal|1
return|;
case|case
literal|1
case|:
return|return
literal|0
return|;
case|case
literal|2
case|:
return|return
literal|1
return|;
block|}
return|return
literal|2
return|;
block|}
end_function

end_unit

