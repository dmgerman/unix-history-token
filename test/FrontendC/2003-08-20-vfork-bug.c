begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_function_decl
specifier|extern
name|int
name|vfork
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|test
argument_list|()
end_macro

begin_block
block|{
name|vfork
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

