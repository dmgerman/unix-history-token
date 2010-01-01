begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o -
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
name|void
modifier|*
name|addr
decl_stmt|;
name|addr
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
operator|(
operator|(
name|long
name|int
operator|)
name|addr
operator|+
literal|7L
operator|)
operator|)
expr_stmt|;
block|}
end_function

end_unit

