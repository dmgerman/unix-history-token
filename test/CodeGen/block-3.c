begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -fblocks -triple x86_64-apple-darwin10
end_comment

begin_comment
comment|// rdar://10001085
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
lambda|^
block|{
name|__attribute__
argument_list|(
argument|(__blocks__(byref))
argument_list|)
name|int
name|index
init|=
operator|(
block|{
name|int
name|__a
decl_stmt|;
name|int
name|__b
decl_stmt|;
name|__a
operator|<
name|__b
condition|?
name|__b
else|:
name|__a
expr_stmt|;
block|}
block|)
expr_stmt|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

unit|}
end_unit

