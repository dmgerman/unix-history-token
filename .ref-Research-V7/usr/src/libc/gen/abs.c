begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_macro
name|abs
argument_list|(
argument|arg
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|arg
operator|<
literal|0
condition|)
name|arg
operator|=
operator|-
name|arg
expr_stmt|;
return|return
operator|(
name|arg
operator|)
return|;
block|}
end_block

end_unit

