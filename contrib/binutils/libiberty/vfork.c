begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Emulate vfork using just plain fork, for systems without a real vfork.    This function is in the public domain. */
end_comment

begin_function
name|int
name|vfork
parameter_list|()
block|{
return|return
operator|(
name|fork
argument_list|()
operator|)
return|;
block|}
end_function

end_unit

