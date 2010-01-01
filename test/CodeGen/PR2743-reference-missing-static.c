begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o %t %s
end_comment

begin_comment
comment|// PR2743
end_comment

begin_comment
comment|//<rdr://6094512>
end_comment

begin_comment
comment|/* CodeGen should handle this even if it makes it past    sema. Unfortunately this test will become useless once sema starts    rejecting this. */
end_comment

begin_function_decl
specifier|static
name|void
name|e0
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|f0
parameter_list|()
block|{
name|e0
argument_list|()
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|inline
name|void
name|e1
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|f1
parameter_list|()
block|{
name|e1
argument_list|()
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|e2
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(weak
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|f2
parameter_list|()
block|{
name|e2
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

