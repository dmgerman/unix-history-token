begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -emit-llvm -S -o %t %s&&
end_comment

begin_comment
comment|// RUN: grep '@f0' %t | count 0&&
end_comment

begin_comment
comment|// RUN: clang -mllvm -disable-llvm-optzns -emit-llvm -S -o %t %s&&
end_comment

begin_comment
comment|// RUN: grep '@f0' %t | count 2
end_comment

begin_comment
comment|//static int f0() {
end_comment

begin_decl_stmt
specifier|static
name|int
name|__attribute__
argument_list|(
operator|(
name|always_inline
operator|)
argument_list|)
name|f0
argument_list|()
block|{
return|return
literal|1
return|;
block|}
end_decl_stmt

begin_function
name|int
name|f1
parameter_list|()
block|{
return|return
name|f0
argument_list|()
return|;
block|}
end_function

end_unit

