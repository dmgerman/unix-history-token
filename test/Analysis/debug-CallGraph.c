begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-checker=debug.DumpCallGraph %s 2>&1 | FileCheck %s
end_comment

begin_function
specifier|static
name|void
name|mmm
parameter_list|(
name|int
name|y
parameter_list|)
block|{
if|if
condition|(
name|y
operator|!=
literal|0
condition|)
name|y
operator|++
expr_stmt|;
name|y
operator|=
name|y
operator|/
literal|0
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|foo
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|mmm
argument_list|(
name|y
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|!=
literal|0
condition|)
name|x
operator|++
expr_stmt|;
return|return
literal|5
operator|/
name|x
return|;
block|}
end_function

begin_function
name|void
name|aaa
parameter_list|()
block|{
name|foo
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK:--- Call graph Dump ---
end_comment

begin_comment
comment|// CHECK: Function:< root> calls: aaa
end_comment

end_unit

