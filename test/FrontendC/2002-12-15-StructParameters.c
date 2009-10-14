begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|stack
decl_stmt|;
name|unsigned
name|size
decl_stmt|;
name|unsigned
name|avail
decl_stmt|;
block|}
name|compile_stack_type
typedef|;
end_typedef

begin_function_decl
name|void
name|foo
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bar
parameter_list|(
name|compile_stack_type
name|T
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test
parameter_list|()
block|{
name|compile_stack_type
name|CST
decl_stmt|;
name|foo
argument_list|(
operator|&
name|CST
argument_list|)
expr_stmt|;
name|bar
argument_list|(
name|CST
argument_list|,
literal|12
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

