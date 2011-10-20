begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | grep volatile
end_comment

begin_comment
comment|// PR1647
end_comment

begin_function
name|void
name|foo
parameter_list|(
specifier|volatile
name|int
modifier|*
name|p
parameter_list|)
block|{
name|p
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

