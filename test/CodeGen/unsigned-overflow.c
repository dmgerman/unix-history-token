begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -fsanitize=unsigned-integer-overflow %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// Verify checked operations are emitted for integers and longs.
end_comment

begin_comment
comment|// unsigned short/char's tested in unsigned-promotion.c
end_comment

begin_decl_stmt
name|unsigned
name|long
name|li
decl_stmt|,
name|lj
decl_stmt|,
name|lk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|ii
decl_stmt|,
name|ij
decl_stmt|,
name|ik
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|opaquelong
parameter_list|(
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|opaqueint
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: define void @testlongadd()
end_comment

begin_function
name|void
name|testlongadd
parameter_list|()
block|{
comment|// CHECK:      [[T1:%.*]] = load i64* @lj
comment|// CHECK-NEXT: [[T2:%.*]] = load i64* @lk
comment|// CHECK-NEXT: [[T3:%.*]] = call { i64, i1 } @llvm.uadd.with.overflow.i64(i64 [[T1]], i64 [[T2]])
comment|// CHECK-NEXT: [[T4:%.*]] = extractvalue { i64, i1 } [[T3]], 0
comment|// CHECK-NEXT: [[T5:%.*]] = extractvalue { i64, i1 } [[T3]], 1
comment|// CHECK: call void @__ubsan_handle_add_overflow
name|li
operator|=
name|lj
operator|+
name|lk
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @testlongsub()
end_comment

begin_function
name|void
name|testlongsub
parameter_list|()
block|{
comment|// CHECK:      [[T1:%.*]] = load i64* @lj
comment|// CHECK-NEXT: [[T2:%.*]] = load i64* @lk
comment|// CHECK-NEXT: [[T3:%.*]] = call { i64, i1 } @llvm.usub.with.overflow.i64(i64 [[T1]], i64 [[T2]])
comment|// CHECK-NEXT: [[T4:%.*]] = extractvalue { i64, i1 } [[T3]], 0
comment|// CHECK-NEXT: [[T5:%.*]] = extractvalue { i64, i1 } [[T3]], 1
comment|// CHECK: call void @__ubsan_handle_sub_overflow
name|li
operator|=
name|lj
operator|-
name|lk
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @testlongmul()
end_comment

begin_function
name|void
name|testlongmul
parameter_list|()
block|{
comment|// CHECK:      [[T1:%.*]] = load i64* @lj
comment|// CHECK-NEXT: [[T2:%.*]] = load i64* @lk
comment|// CHECK-NEXT: [[T3:%.*]] = call { i64, i1 } @llvm.umul.with.overflow.i64(i64 [[T1]], i64 [[T2]])
comment|// CHECK-NEXT: [[T4:%.*]] = extractvalue { i64, i1 } [[T3]], 0
comment|// CHECK-NEXT: [[T5:%.*]] = extractvalue { i64, i1 } [[T3]], 1
comment|// CHECK: call void @__ubsan_handle_mul_overflow
name|li
operator|=
name|lj
operator|*
name|lk
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @testlongpostinc()
end_comment

begin_function
name|void
name|testlongpostinc
parameter_list|()
block|{
name|opaquelong
argument_list|(
name|li
operator|++
argument_list|)
expr_stmt|;
comment|// CHECK:      [[T1:%.*]] = load i64* @li
comment|// CHECK-NEXT: [[T2:%.*]] = call { i64, i1 } @llvm.uadd.with.overflow.i64(i64 [[T1]], i64 1)
comment|// CHECK-NEXT: [[T3:%.*]] = extractvalue { i64, i1 } [[T2]], 0
comment|// CHECK-NEXT: [[T4:%.*]] = extractvalue { i64, i1 } [[T2]], 1
comment|// CHECK:      call void @__ubsan_handle_add_overflow
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @testlongpreinc()
end_comment

begin_function
name|void
name|testlongpreinc
parameter_list|()
block|{
name|opaquelong
argument_list|(
operator|++
name|li
argument_list|)
expr_stmt|;
comment|// CHECK:      [[T1:%.*]] = load i64* @li
comment|// CHECK-NEXT: [[T2:%.*]] = call { i64, i1 } @llvm.uadd.with.overflow.i64(i64 [[T1]], i64 1)
comment|// CHECK-NEXT: [[T3:%.*]] = extractvalue { i64, i1 } [[T2]], 0
comment|// CHECK-NEXT: [[T4:%.*]] = extractvalue { i64, i1 } [[T2]], 1
comment|// CHECK:      call void @__ubsan_handle_add_overflow
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @testintadd()
end_comment

begin_function
name|void
name|testintadd
parameter_list|()
block|{
comment|// CHECK:      [[T1:%.*]] = load i32* @ij
comment|// CHECK-NEXT: [[T2:%.*]] = load i32* @ik
comment|// CHECK-NEXT: [[T3:%.*]] = call { i32, i1 } @llvm.uadd.with.overflow.i32(i32 [[T1]], i32 [[T2]])
comment|// CHECK-NEXT: [[T4:%.*]] = extractvalue { i32, i1 } [[T3]], 0
comment|// CHECK-NEXT: [[T5:%.*]] = extractvalue { i32, i1 } [[T3]], 1
comment|// CHECK:      call void @__ubsan_handle_add_overflow
name|ii
operator|=
name|ij
operator|+
name|ik
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @testintsub()
end_comment

begin_function
name|void
name|testintsub
parameter_list|()
block|{
comment|// CHECK:      [[T1:%.*]] = load i32* @ij
comment|// CHECK-NEXT: [[T2:%.*]] = load i32* @ik
comment|// CHECK-NEXT: [[T3:%.*]] = call { i32, i1 } @llvm.usub.with.overflow.i32(i32 [[T1]], i32 [[T2]])
comment|// CHECK-NEXT: [[T4:%.*]] = extractvalue { i32, i1 } [[T3]], 0
comment|// CHECK-NEXT: [[T5:%.*]] = extractvalue { i32, i1 } [[T3]], 1
comment|// CHECK:      call void @__ubsan_handle_sub_overflow
name|ii
operator|=
name|ij
operator|-
name|ik
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @testintmul()
end_comment

begin_function
name|void
name|testintmul
parameter_list|()
block|{
comment|// CHECK:      [[T1:%.*]] = load i32* @ij
comment|// CHECK-NEXT: [[T2:%.*]] = load i32* @ik
comment|// CHECK-NEXT: [[T3:%.*]] = call { i32, i1 } @llvm.umul.with.overflow.i32(i32 [[T1]], i32 [[T2]])
comment|// CHECK-NEXT: [[T4:%.*]] = extractvalue { i32, i1 } [[T3]], 0
comment|// CHECK-NEXT: [[T5:%.*]] = extractvalue { i32, i1 } [[T3]], 1
comment|// CHECK:      call void @__ubsan_handle_mul_overflow
name|ii
operator|=
name|ij
operator|*
name|ik
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @testintpostinc()
end_comment

begin_function
name|void
name|testintpostinc
parameter_list|()
block|{
name|opaqueint
argument_list|(
name|ii
operator|++
argument_list|)
expr_stmt|;
comment|// CHECK:      [[T1:%.*]] = load i32* @ii
comment|// CHECK-NEXT: [[T2:%.*]] = call { i32, i1 } @llvm.uadd.with.overflow.i32(i32 [[T1]], i32 1)
comment|// CHECK-NEXT: [[T3:%.*]] = extractvalue { i32, i1 } [[T2]], 0
comment|// CHECK-NEXT: [[T4:%.*]] = extractvalue { i32, i1 } [[T2]], 1
comment|// CHECK:      call void @__ubsan_handle_add_overflow
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @testintpreinc()
end_comment

begin_function
name|void
name|testintpreinc
parameter_list|()
block|{
name|opaqueint
argument_list|(
operator|++
name|ii
argument_list|)
expr_stmt|;
comment|// CHECK:      [[T1:%.*]] = load i32* @ii
comment|// CHECK-NEXT: [[T2:%.*]] = call { i32, i1 } @llvm.uadd.with.overflow.i32(i32 [[T1]], i32 1)
comment|// CHECK-NEXT: [[T3:%.*]] = extractvalue { i32, i1 } [[T2]], 0
comment|// CHECK-NEXT: [[T4:%.*]] = extractvalue { i32, i1 } [[T2]], 1
comment|// CHECK:      call void @__ubsan_handle_add_overflow
block|}
end_function

end_unit

