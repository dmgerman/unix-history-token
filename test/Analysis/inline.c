begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-check-objc-mem -analyzer-inline-call -analyzer-store region -verify %s
end_comment

begin_function
name|int
name|test1_f1
parameter_list|()
block|{
name|int
name|y
init|=
literal|1
decl_stmt|;
name|y
operator|++
expr_stmt|;
return|return
name|y
return|;
block|}
end_function

begin_function
name|void
name|test1_f2
parameter_list|()
block|{
name|int
name|x
init|=
literal|1
decl_stmt|;
name|x
operator|=
name|test1_f1
argument_list|()
expr_stmt|;
if|if
condition|(
name|x
operator|==
literal|1
condition|)
block|{
name|int
modifier|*
name|p
init|=
literal|0
decl_stmt|;
operator|*
name|p
operator|=
literal|3
expr_stmt|;
comment|// no-warning
block|}
if|if
condition|(
name|x
operator|==
literal|2
condition|)
block|{
name|int
modifier|*
name|p
init|=
literal|0
decl_stmt|;
operator|*
name|p
operator|=
literal|3
expr_stmt|;
comment|// expected-warning{{Dereference of null pointer (loaded from variable 'p')}}
block|}
block|}
end_function

begin_comment
comment|// Test that inlining works when the declared function has less arguments
end_comment

begin_comment
comment|// than the actual number in the declaration.
end_comment

begin_function
name|void
name|test2_f1
parameter_list|()
block|{}
end_function

begin_function_decl
name|int
name|test2_f2
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test2_f3
parameter_list|()
block|{
name|test2_f1
argument_list|(
name|test2_f2
argument_list|()
argument_list|)
expr_stmt|;
comment|// expected-warning{{too many arguments in call to 'test2_f1'}}
block|}
end_function

end_unit

