begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_macro
name|calloc
argument_list|(
argument|n
argument_list|,
argument|s
argument_list|)
end_macro

begin_block
block|{
return|return
operator|(
name|alloc
argument_list|(
name|n
operator|*
name|s
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

