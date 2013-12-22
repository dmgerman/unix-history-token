begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - -triple x86_64-apple-darwin10 %s | FileCheck %s
end_comment

begin_comment
comment|// Ensure that we don't emit available_externally functions at -O0.
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_function
specifier|inline
name|void
name|f0
parameter_list|(
name|int
name|y
parameter_list|)
block|{
name|x
operator|=
name|y
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test()
end_comment

begin_comment
comment|// CHECK: declare void @f0(i32)
end_comment

begin_function
name|void
name|test
parameter_list|()
block|{
name|f0
argument_list|(
literal|17
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|inline
name|int
name|__attribute__
argument_list|(
operator|(
name|always_inline
operator|)
argument_list|)
name|f1
argument_list|(
name|int
name|x
argument_list|)
block|{
name|int
name|blarg
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|x
condition|;
operator|++
name|i
control|)
name|blarg
operator|=
name|blarg
operator|+
name|x
operator|*
name|i
expr_stmt|;
return|return
name|blarg
return|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK: @test1
end_comment

begin_function
name|int
name|test1
parameter_list|(
name|int
name|x
parameter_list|)
block|{
comment|// CHECK: br i1
comment|// CHECK-NOT: call {{.*}} @f1
comment|// CHECK: ret i32
return|return
name|f1
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

end_unit

