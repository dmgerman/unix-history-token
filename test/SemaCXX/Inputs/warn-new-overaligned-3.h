begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_comment
comment|// This header file pretends to be<new> from the system library, for the
end_comment

begin_comment
comment|// purpose of the over-aligned warnings test.
end_comment

begin_function
name|void
modifier|*
name|operator
name|new
parameter_list|(
name|unsigned
name|long
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|operator
name|new
function|[]
parameter_list|(
name|unsigned
name|long
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|operator
name|new
parameter_list|(
name|unsigned
name|long
parameter_list|,
name|void
modifier|*
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|operator
name|new
function|[]
parameter_list|(
name|unsigned
name|long
parameter_list|,
name|void
modifier|*
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

