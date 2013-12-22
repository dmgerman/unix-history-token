begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -ftrapv %s -emit-llvm -o - | FileCheck %s
end_comment

begin_decl_stmt
name|unsigned
name|int
name|ui
decl_stmt|,
name|uj
decl_stmt|,
name|uk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i
decl_stmt|,
name|j
decl_stmt|,
name|k
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @test0()
end_comment

begin_function
name|void
name|test0
parameter_list|()
block|{
comment|// -ftrapv doesn't affect unsigned arithmetic.
comment|// CHECK:      [[T1:%.*]] = load i32* @uj
comment|// CHECK-NEXT: [[T2:%.*]] = load i32* @uk
comment|// CHECK-NEXT: [[T3:%.*]] = add i32 [[T1]], [[T2]]
comment|// CHECK-NEXT: store i32 [[T3]], i32* @ui
name|ui
operator|=
name|uj
operator|+
name|uk
expr_stmt|;
comment|// CHECK:      [[T1:%.*]] = load i32* @j
comment|// CHECK-NEXT: [[T2:%.*]] = load i32* @k
comment|// CHECK-NEXT: [[T3:%.*]] = call { i32, i1 } @llvm.sadd.with.overflow.i32(i32 [[T1]], i32 [[T2]])
comment|// CHECK-NEXT: [[T4:%.*]] = extractvalue { i32, i1 } [[T3]], 0
comment|// CHECK-NEXT: [[T5:%.*]] = extractvalue { i32, i1 } [[T3]], 1
comment|// CHECK-NEXT: [[T6:%.*]] = xor i1 [[T5]], true
comment|// CHECK-NEXT: br i1 [[T6]]
comment|// CHECK:      call void @llvm.trap()
name|i
operator|=
name|j
operator|+
name|k
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test1()
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
specifier|extern
name|void
name|opaque
argument_list|(
name|int
argument_list|)
decl_stmt|;
name|opaque
argument_list|(
name|i
operator|++
argument_list|)
expr_stmt|;
comment|// CHECK:      [[T1:%.*]] = load i32* @i
comment|// CHECK-NEXT: [[T2:%.*]] = call { i32, i1 } @llvm.sadd.with.overflow.i32(i32 [[T1]], i32 1)
comment|// CHECK-NEXT: [[T3:%.*]] = extractvalue { i32, i1 } [[T2]], 0
comment|// CHECK-NEXT: [[T4:%.*]] = extractvalue { i32, i1 } [[T2]], 1
comment|// CHECK-NEXT: [[T5:%.*]] = xor i1 [[T4]], true
comment|// CHECK-NEXT: br i1 [[T5]]
comment|// CHECK:      call void @llvm.trap()
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test2()
end_comment

begin_function
name|void
name|test2
parameter_list|()
block|{
specifier|extern
name|void
name|opaque
argument_list|(
name|int
argument_list|)
decl_stmt|;
name|opaque
argument_list|(
operator|++
name|i
argument_list|)
expr_stmt|;
comment|// CHECK:      [[T1:%.*]] = load i32* @i
comment|// CHECK-NEXT: [[T2:%.*]] = call { i32, i1 } @llvm.sadd.with.overflow.i32(i32 [[T1]], i32 1)
comment|// CHECK-NEXT: [[T3:%.*]] = extractvalue { i32, i1 } [[T2]], 0
comment|// CHECK-NEXT: [[T4:%.*]] = extractvalue { i32, i1 } [[T2]], 1
comment|// CHECK-NEXT: [[T5:%.*]] = xor i1 [[T4]], true
comment|// CHECK-NEXT: br i1 [[T5]]
comment|// CHECK:      call void @llvm.trap()
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test3(
end_comment

begin_function
name|void
name|test3
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|,
name|float
name|c
parameter_list|,
name|float
name|d
parameter_list|)
block|{
comment|// CHECK-NOT:  @llvm.trap
call|(
name|void
call|)
argument_list|(
name|a
operator|/
name|b
argument_list|)
expr_stmt|;
call|(
name|void
call|)
argument_list|(
name|a
operator|%
name|b
argument_list|)
expr_stmt|;
call|(
name|void
call|)
argument_list|(
name|c
operator|/
name|d
argument_list|)
expr_stmt|;
comment|// CHECK: }
block|}
end_function

end_unit

