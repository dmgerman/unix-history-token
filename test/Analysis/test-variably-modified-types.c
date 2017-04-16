begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -analyze-function=testVariablyModifiedTypes -verify %s
end_comment

begin_comment
comment|// Test that we process variably modified type correctly - the call graph construction should pick up function_with_bug while recursively visiting test_variably_modifiable_types.
end_comment

begin_function
name|unsigned
name|getArraySize
parameter_list|(
name|int
modifier|*
name|x
parameter_list|)
block|{
if|if
condition|(
operator|!
name|x
condition|)
return|return
operator|*
name|x
return|;
comment|// expected-warning {{Dereference of null pointer}}
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|testVariablyModifiedTypes
parameter_list|(
name|int
modifier|*
name|x
parameter_list|)
block|{
name|int
name|mytype
index|[
name|getArraySize
argument_list|(
name|x
argument_list|)
index|]
decl_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

