begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// clang -c dsym-test.c -g
end_comment

begin_comment
comment|// clang dsym-test.o -g -o dsym-test-exe
end_comment

begin_comment
comment|// dsymutil dsym-test-exe
end_comment

begin_comment
comment|// clang dsym-test.o -g -o dsym-test-exe-second
end_comment

begin_comment
comment|// dsymutil dsym-test-exe-second -o dsym-test-exe-differentname.dSYM
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

