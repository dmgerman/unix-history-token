begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  **	returns true if running in foreground, zero if in background  **/
end_comment

begin_macro
name|intss
argument_list|()
end_macro

begin_block
block|{
name|int
name|a
index|[
literal|3
index|]
decl_stmt|;
if|if
condition|(
name|gtty
argument_list|(
literal|0
argument_list|,
name|a
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

