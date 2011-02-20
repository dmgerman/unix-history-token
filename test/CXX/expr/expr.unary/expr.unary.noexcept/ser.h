begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Serialization testing helper for noexcept, included by cg.cpp.
end_comment

begin_function
specifier|inline
name|bool
name|f1
parameter_list|()
block|{
return|return
name|noexcept
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|bool
name|f2
parameter_list|()
block|{
return|return
name|noexcept
argument_list|(
name|throw
literal|0
argument_list|)
return|;
block|}
end_function

end_unit

