begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|char
modifier|*
name|copy
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
specifier|register
name|char
modifier|*
name|from
decl_stmt|,
decl|*
name|to
decl_stmt|;
end_function

begin_block
block|{
while|while
condition|(
operator|*
name|to
operator|++
operator|=
operator|*
name|from
operator|++
condition|)
empty_stmt|;
return|return
name|to
operator|-
literal|1
return|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

