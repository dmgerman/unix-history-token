begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that this unreachable code warning is
end_comment

begin_comment
comment|// not reported because it is in a header.
end_comment

begin_function
name|void
name|foo_unreachable_header
parameter_list|()
block|{
return|return;
name|foo_unreachable_header
argument_list|()
expr_stmt|;
comment|// no-warning
block|}
end_function

end_unit

