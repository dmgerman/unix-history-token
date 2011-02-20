begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -O0 -S -o - -fno-inline -fno-unit-at-a-time %s | \
end_comment

begin_comment
comment|// RUN:   grep {call float @foo}
end_comment

begin_comment
comment|// Make sure the call to foo is compiled as:
end_comment

begin_comment
comment|//  call float @foo()
end_comment

begin_comment
comment|// not
end_comment

begin_comment
comment|//  call float (...)* bitcast (float ()* @foo to float (...)*)( )
end_comment

begin_function
specifier|static
name|float
name|foo
parameter_list|()
block|{
return|return
literal|0.0
return|;
block|}
end_function

begin_function
name|float
name|bar
parameter_list|()
block|{
return|return
name|foo
argument_list|()
operator|*
literal|10.0
return|;
block|}
end_function

end_unit

