begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Compile with $CC -nostdlib -shared TestModule.c -o TestModule.so
end_comment

begin_comment
comment|// The actual contents of the test module is not important here. I am using this
end_comment

begin_comment
comment|// because it
end_comment

begin_comment
comment|// produces an extremely tiny (but still perfectly valid) module.
end_comment

begin_function
name|void
name|boom
parameter_list|(
name|void
parameter_list|)
block|{
name|char
modifier|*
name|BOOM
decl_stmt|;
operator|*
name|BOOM
operator|=
literal|47
expr_stmt|;
block|}
end_function

end_unit

