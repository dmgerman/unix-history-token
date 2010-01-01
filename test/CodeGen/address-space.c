begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s | grep '@foo.*global.*addrspace(1)'
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s | grep '@ban.*global.*addrspace(1)'
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s | grep 'load.*addrspace(1)' | count 2
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s | grep 'load.*addrspace(2).. @A'
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s | grep 'load.*addrspace(2).. @B'
end_comment

begin_decl_stmt
name|int
name|foo
name|__attribute__
argument_list|(
operator|(
name|address_space
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ban
index|[
literal|10
index|]
name|__attribute__
argument_list|(
operator|(
name|address_space
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|bar
parameter_list|()
block|{
return|return
name|foo
return|;
block|}
end_function

begin_function
name|int
name|baz
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|ban
index|[
name|i
index|]
return|;
block|}
end_function

begin_comment
comment|// Both A and B point into addrspace(2).
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(address_space(
literal|2
argument|))
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|A
decl_stmt|,
modifier|*
name|B
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test3
parameter_list|()
block|{
operator|*
name|A
operator|=
operator|*
name|B
expr_stmt|;
block|}
end_function

end_unit

