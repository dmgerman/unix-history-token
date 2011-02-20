begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -o - | llvm-as | llvm-dis | \
end_comment

begin_comment
comment|// RUN:   grep llvm.used | grep foo | grep X
end_comment

begin_decl_stmt
name|int
name|X
name|__attribute__
argument_list|(
operator|(
name|used
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Y
decl_stmt|;
end_decl_stmt

begin_macro
name|__attribute__
argument_list|(
argument|(used)
argument_list|)
end_macro

begin_function
name|void
name|foo
parameter_list|()
block|{}
end_function

end_unit

