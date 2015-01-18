begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK-LABEL: @test1
end_comment

begin_function
name|int
name|test1
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK: [[PTRINT1:%.+]] = ptrtoint
comment|// CHECK: [[MASKEDPTR1:%.+]] = and i64 [[PTRINT1]], 31
comment|// CHECK: [[MASKCOND1:%.+]] = icmp eq i64 [[MASKEDPTR1]], 0
comment|// CHECK: call void @llvm.assume(i1 [[MASKCOND1]])
name|a
operator|=
name|__builtin_assume_aligned
argument_list|(
name|a
argument_list|,
literal|32
argument_list|,
literal|0ull
argument_list|)
expr_stmt|;
return|return
name|a
index|[
literal|0
index|]
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test2
end_comment

begin_function
name|int
name|test2
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK: [[PTRINT2:%.+]] = ptrtoint
comment|// CHECK: [[MASKEDPTR2:%.+]] = and i64 [[PTRINT2]], 31
comment|// CHECK: [[MASKCOND2:%.+]] = icmp eq i64 [[MASKEDPTR2]], 0
comment|// CHECK: call void @llvm.assume(i1 [[MASKCOND2]])
name|a
operator|=
name|__builtin_assume_aligned
argument_list|(
name|a
argument_list|,
literal|32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
name|a
index|[
literal|0
index|]
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test3
end_comment

begin_function
name|int
name|test3
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK: [[PTRINT3:%.+]] = ptrtoint
comment|// CHECK: [[MASKEDPTR3:%.+]] = and i64 [[PTRINT3]], 31
comment|// CHECK: [[MASKCOND3:%.+]] = icmp eq i64 [[MASKEDPTR3]], 0
comment|// CHECK: call void @llvm.assume(i1 [[MASKCOND3]])
name|a
operator|=
name|__builtin_assume_aligned
argument_list|(
name|a
argument_list|,
literal|32
argument_list|)
expr_stmt|;
return|return
name|a
index|[
literal|0
index|]
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test4
end_comment

begin_function
name|int
name|test4
parameter_list|(
name|int
modifier|*
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
comment|// CHECK-DAG: [[PTRINT4:%.+]] = ptrtoint
comment|// CHECK-DAG: [[CONV4:%.+]] = sext i32
comment|// CHECK: [[OFFSETPTR4:%.+]] = sub i64 [[PTRINT4]], [[CONV4]]
comment|// CHECK: [[MASKEDPTR4:%.+]] = and i64 [[OFFSETPTR4]], 31
comment|// CHECK: [[MASKCOND4:%.+]] = icmp eq i64 [[MASKEDPTR4]], 0
comment|// CHECK: call void @llvm.assume(i1 [[MASKCOND4]])
name|a
operator|=
name|__builtin_assume_aligned
argument_list|(
name|a
argument_list|,
literal|32
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|a
index|[
literal|0
index|]
return|;
block|}
end_function

begin_function_decl
name|int
modifier|*
name|m1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(assume_aligned
parameter_list|(
function_decl|64
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK-LABEL: @test5
end_comment

begin_function
name|int
name|test5
parameter_list|()
block|{
return|return
operator|*
name|m1
argument_list|()
return|;
comment|// CHECK: [[PTRINT5:%.+]] = ptrtoint
comment|// CHECK: [[MASKEDPTR5:%.+]] = and i64 [[PTRINT5]], 63
comment|// CHECK: [[MASKCOND5:%.+]] = icmp eq i64 [[MASKEDPTR5]], 0
comment|// CHECK: call void @llvm.assume(i1 [[MASKCOND5]])
block|}
end_function

begin_function_decl
name|int
modifier|*
name|m2
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(assume_aligned
parameter_list|(
function_decl|64
operator|,
function_decl|12
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK-LABEL: @test6
end_comment

begin_function
name|int
name|test6
parameter_list|()
block|{
return|return
operator|*
name|m2
argument_list|()
return|;
comment|// CHECK: [[PTRINT6:%.+]] = ptrtoint
comment|// CHECK: [[OFFSETPTR6:%.+]] = sub i64 [[PTRINT6]], 12
comment|// CHECK: [[MASKEDPTR6:%.+]] = and i64 [[OFFSETPTR6]], 63
comment|// CHECK: [[MASKCOND6:%.+]] = icmp eq i64 [[MASKEDPTR6]], 0
comment|// CHECK: call void @llvm.assume(i1 [[MASKCOND6]])
block|}
end_function

end_unit

