begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* copy.c - copy a string and return pointer to NULL terminator */
end_comment

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
continue|continue;
return|return
operator|(
name|to
operator|-
literal|1
operator|)
return|;
block|}
end_block

end_unit

