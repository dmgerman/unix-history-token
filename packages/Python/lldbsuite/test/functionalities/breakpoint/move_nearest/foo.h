begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|LLDB_TEST_API
specifier|inline
name|int
name|foo1
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|// !BR1
end_comment

begin_function
name|LLDB_TEST_API
specifier|inline
name|int
name|foo2
parameter_list|()
block|{
return|return
literal|2
return|;
block|}
end_function

begin_comment
comment|// !BR2
end_comment

begin_function_decl
name|LLDB_TEST_API
specifier|extern
name|int
name|call_foo1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|LLDB_TEST_API
specifier|extern
name|int
name|call_foo2
parameter_list|()
function_decl|;
end_function_decl

end_unit

