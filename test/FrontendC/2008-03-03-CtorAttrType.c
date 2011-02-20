begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -o - | grep llvm.global_ctors
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|constructor
operator|)
argument_list|)
name|foo
argument_list|(
name|void
argument_list|)
block|{
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|constructor
operator|)
argument_list|)
name|bar
argument_list|(
name|void
argument_list|)
block|{}
end_decl_stmt

end_unit

