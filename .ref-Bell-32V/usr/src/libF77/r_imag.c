begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"complex"
end_include

begin_function
name|double
name|r_imag
parameter_list|(
name|z
parameter_list|)
name|complex
modifier|*
name|z
decl_stmt|;
block|{
return|return
operator|(
name|z
operator|->
name|imag
operator|)
return|;
block|}
end_function

end_unit

