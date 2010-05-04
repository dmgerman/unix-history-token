begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fcatch-undefined-behavior -emit-llvm-only %s
end_comment

begin_comment
comment|// PR6805
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
union|union
block|{
name|int
name|i
decl_stmt|;
block|}
name|u
union|;
name|u
operator|.
name|i
operator|=
literal|1
expr_stmt|;
block|}
end_function

end_unit

