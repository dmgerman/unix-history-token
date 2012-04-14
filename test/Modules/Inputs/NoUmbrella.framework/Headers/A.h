begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|int
name|no_umbrella_A
decl_stmt|;
end_decl_stmt

begin_function
specifier|inline
name|int
name|has_warning
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|x
operator|>
literal|0
condition|)
return|return
name|x
return|;
comment|// Note: warning here is suppressed because this module is considered a
comment|// "system" module.
block|}
end_function

end_unit

