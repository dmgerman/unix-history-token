begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,debug.ExprInspection -analyzer-inline-max-stack-depth=3 -analyzer-config ipa-always-inline-size=3 -verify %s
end_comment

begin_function_decl
name|void
name|clang_analyzer_eval
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|nested5
parameter_list|()
block|{
if|if
condition|(
literal|5
operator|<
literal|3
condition|)
return|return
literal|0
return|;
elseif|else
if|if
condition|(
literal|3
operator|==
literal|3
condition|)
return|return
literal|0
return|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|nested4
parameter_list|()
block|{
return|return
name|nested5
argument_list|()
return|;
block|}
end_function

begin_function
name|int
name|nested3
parameter_list|()
block|{
return|return
name|nested4
argument_list|()
return|;
block|}
end_function

begin_function
name|int
name|nested2
parameter_list|()
block|{
return|return
name|nested3
argument_list|()
return|;
block|}
end_function

begin_function
name|int
name|nested1
parameter_list|()
block|{
return|return
name|nested2
argument_list|()
return|;
block|}
end_function

begin_function
name|void
name|testNested
parameter_list|()
block|{
name|clang_analyzer_eval
argument_list|(
name|nested1
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
block|}
end_function

begin_comment
comment|// Make sure we terminate a recursive path.
end_comment

begin_function
name|int
name|recursive
parameter_list|()
block|{
return|return
name|recursive
argument_list|()
return|;
block|}
end_function

begin_function
name|int
name|callRecursive
parameter_list|()
block|{
return|return
name|recursive
argument_list|()
return|;
block|}
end_function

begin_function_decl
name|int
name|mutuallyRecursive1
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|mutuallyRecursive2
parameter_list|()
block|{
return|return
name|mutuallyRecursive1
argument_list|()
return|;
block|}
end_function

begin_function
name|int
name|mutuallyRecursive1
parameter_list|()
block|{
return|return
name|mutuallyRecursive2
argument_list|()
return|;
block|}
end_function

begin_function
name|int
name|callMutuallyRecursive
parameter_list|()
block|{
return|return
name|mutuallyRecursive1
argument_list|()
return|;
block|}
end_function

end_unit

