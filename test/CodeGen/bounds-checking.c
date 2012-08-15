begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fbounds-checking=4 -emit-llvm -triple x86_64-apple-darwin10< %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @f
end_comment

begin_function
name|double
name|f
parameter_list|(
name|int
name|b
parameter_list|,
name|int
name|i
parameter_list|)
block|{
name|double
name|a
index|[
name|b
index|]
decl_stmt|;
comment|// CHECK: trap
return|return
name|a
index|[
name|i
index|]
return|;
block|}
end_function

begin_comment
comment|// CHECK: @f2
end_comment

begin_function
name|void
name|f2
parameter_list|()
block|{
comment|// everything is constant; no trap possible
comment|// CHECK-NOT: trap
name|int
name|a
index|[
literal|2
index|]
decl_stmt|;
name|a
index|[
literal|1
index|]
operator|=
literal|42
expr_stmt|;
name|short
modifier|*
name|b
init|=
name|malloc
argument_list|(
literal|64
argument_list|)
decl_stmt|;
name|b
index|[
literal|5
index|]
operator|=
operator|*
name|a
operator|+
name|a
index|[
literal|1
index|]
operator|+
literal|2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @f3
end_comment

begin_function
name|void
name|f3
parameter_list|()
block|{
name|int
name|a
index|[
literal|1
index|]
decl_stmt|;
comment|// CHECK: trap
name|a
index|[
literal|2
index|]
operator|=
literal|1
expr_stmt|;
block|}
end_function

end_unit

