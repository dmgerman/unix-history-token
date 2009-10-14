begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm -o - -triple x86_64-apple-darwin10&&
end_comment

begin_comment
comment|// RUN: clang-cc -emit-llvm -o - -triple i386-apple-darwin10
end_comment

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|32
argument_list|)
operator|)
argument_list|)
name|ai
typedef|;
end_typedef

begin_function
name|void
name|f
parameter_list|()
block|{
specifier|__block
name|ai
name|a
init|=
literal|10
decl_stmt|;
lambda|^
block|{
name|a
operator|=
literal|20
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|g
parameter_list|()
block|{
specifier|__block
name|double
name|a
init|=
literal|10
decl_stmt|;
lambda|^
block|{
name|a
operator|=
literal|20
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

