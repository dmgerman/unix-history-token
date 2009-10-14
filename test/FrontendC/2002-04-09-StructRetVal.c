begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_struct
struct|struct
name|S
block|{
name|int
name|i
decl_stmt|;
name|short
name|s1
decl_stmt|,
name|s2
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|S
name|func_returning_struct
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|loop
parameter_list|(
name|void
parameter_list|)
block|{
name|func_returning_struct
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

