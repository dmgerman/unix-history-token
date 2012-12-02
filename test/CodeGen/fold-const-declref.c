begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -emit-llvm-only %s
end_comment

begin_comment
comment|// PR7242: Check that this doesn't crash.
end_comment

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|__negative
init|=
literal|1
decl_stmt|;
specifier|const
name|int
name|__max
init|=
name|__negative
operator|&&
literal|0
decl_stmt|;
name|__max
operator|/
literal|0
expr_stmt|;
comment|// expected-warning{{expression result unused}} expected-warning{{division by zero is undefined}}
block|}
end_function

end_unit

