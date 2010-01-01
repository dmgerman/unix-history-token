begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o %t -fblocks
end_comment

begin_function_decl
name|void
name|foo
parameter_list|(
name|void
function_decl|(
modifier|^
function_decl|)
parameter_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
name|foo
argument_list|(
lambda|^
parameter_list|()
block|{ }
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

