begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|val
decl_stmt|;
block|}
name|structty
typedef|;
end_typedef

begin_function_decl
name|void
name|bar
parameter_list|(
name|structty
name|new_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|foo
parameter_list|()
block|{
name|bar
argument_list|(
argument|({ structty mask; mask; })
argument_list|)
empty_stmt|;
block|}
end_function

end_unit

