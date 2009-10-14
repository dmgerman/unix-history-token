begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_struct_decl
struct_decl|struct
name|fu
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|foo
parameter_list|(
name|struct
name|fu
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|bar
parameter_list|()
block|{
name|foo
expr_stmt|;
block|}
end_function

end_unit

