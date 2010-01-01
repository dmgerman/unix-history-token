begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -emit-llvm -S -o %t %s
end_comment

begin_comment
comment|// RUN: not grep '@f0' %t
end_comment

begin_comment
comment|// RUN: not grep 'call ' %t
end_comment

begin_comment
comment|// RUN: %clang -mllvm -disable-llvm-optzns -emit-llvm -S -o %t %s
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

begin_comment
comment|// PR4372
end_comment

begin_function_decl
specifier|inline
name|int
name|f2
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(always_inline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|int
name|f2
parameter_list|()
block|{
return|return
literal|7
return|;
block|}
end_function

begin_function
name|int
name|f3
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|f2
argument_list|()
return|;
block|}
end_function

end_unit

