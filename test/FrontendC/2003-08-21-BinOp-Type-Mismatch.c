begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_struct_decl
struct_decl|struct
name|bar
struct_decl|;
end_struct_decl

begin_function
name|void
name|foo
parameter_list|()
block|{
name|unsigned
name|int
name|frame
decl_stmt|,
name|focus
decl_stmt|;
operator|(
expr|struct
name|bar
operator|*
operator|)
name|focus
operator|==
operator|(
name|focus
condition|?
operator|(
operator|(
expr|struct
name|bar
operator|*
operator|)
name|frame
operator|)
else|:
literal|0
operator|)
expr_stmt|;
block|}
end_function

end_unit

