begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* PR 39639: writing "long double" gave "long int" */
end_comment

begin_function
name|int
name|fail
parameter_list|(
name|long
name|double
modifier|*
name|a
parameter_list|,
name|long
name|int
modifier|*
name|b
parameter_list|)
block|{
return|return
name|a
operator|==
name|b
return|;
block|}
end_function

end_unit

