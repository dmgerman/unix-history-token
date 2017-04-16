begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
name|void
name|f1
parameter_list|(
name|int
modifier|&
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|f2
parameter_list|()
block|{}
end_function

begin_function
specifier|inline
name|void
name|foo
parameter_list|()
block|{
specifier|static
name|int
name|i
decl_stmt|;
name|f1
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|f2
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
name|void
name|foo2
parameter_list|()
block|{ }
end_function

begin_function
name|void
name|foo_ext
parameter_list|()
block|{}
end_function

end_unit

