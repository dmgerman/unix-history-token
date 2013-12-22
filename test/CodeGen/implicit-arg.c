begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm     -o -
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -O1 -o -
end_comment

begin_comment
comment|// rdar://6518089
end_comment

begin_function_decl
specifier|static
name|int
name|bar
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|()
block|{
name|int
name|a
init|=
name|bar
argument_list|()
decl_stmt|;
block|}
end_function

begin_function
name|int
name|bar
parameter_list|(
name|unsigned
name|a
parameter_list|)
block|{ }
end_function

end_unit

