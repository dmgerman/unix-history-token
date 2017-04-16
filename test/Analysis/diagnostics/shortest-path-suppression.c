begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -analyzer-config suppress-null-return-paths=true -analyzer-output=text -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_function
name|int
modifier|*
name|returnNull
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
name|int
name|coin
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Use a float parameter to ensure that the value is unknown. This will create
end_comment

begin_comment
comment|// a cycle in the generated ExplodedGraph.
end_comment

begin_function
name|void
name|testCycle
parameter_list|(
name|float
name|i
parameter_list|)
block|{
name|int
modifier|*
name|x
init|=
name|returnNull
argument_list|()
decl_stmt|;
name|int
name|y
decl_stmt|;
while|while
condition|(
name|i
operator|>
literal|0
condition|)
block|{
name|x
operator|=
name|returnNull
argument_list|()
expr_stmt|;
name|y
operator|=
literal|2
expr_stmt|;
name|i
operator|-=
literal|1
expr_stmt|;
block|}
operator|*
name|x
operator|=
literal|1
expr_stmt|;
comment|// no-warning
name|y
operator|+=
literal|1
expr_stmt|;
block|}
end_function

end_unit

