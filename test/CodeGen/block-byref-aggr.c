begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -fblocks -triple x86_64-apple-darwin10 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: [[AGG:%.*]] = type { i32 }
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|v
decl_stmt|;
block|}
name|Agg
typedef|;
end_typedef

begin_function_decl
name|Agg
name|makeAgg
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// When assigning into a __block variable, ensure that we compute that
end_comment

begin_comment
comment|// address *after* evaluating the RHS when the RHS has the capacity to
end_comment

begin_comment
comment|// cause a block copy.  rdar://9309454
end_comment

begin_function
name|void
name|test0
parameter_list|()
block|{
specifier|__block
name|Agg
name|a
init|=
block|{
literal|100
block|}
decl_stmt|;
name|a
operator|=
name|makeAgg
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL:    define void @test0()
end_comment

begin_comment
comment|// CHECK:      [[A:%.*]] = alloca [[BYREF:%.*]], align 8
end_comment

begin_comment
comment|// CHECK-NEXT: [[TEMP:%.*]] = alloca [[AGG]], align 4
end_comment

begin_comment
comment|// CHECK:      [[RESULT:%.*]] = call i32 @makeAgg()
end_comment

begin_comment
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr [[AGG]]* [[TEMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK-NEXT: store i32 [[RESULT]], i32* [[T0]]
end_comment

begin_comment
comment|//   Check that we properly assign into the forwarding pointer.
end_comment

begin_comment
comment|// CHECK-NEXT: [[A_FORWARDING:%.*]] = getelementptr inbounds [[BYREF]]* [[A]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK-NEXT: [[T0:%.*]] = load [[BYREF]]** [[A_FORWARDING]]
end_comment

begin_comment
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[BYREF]]* [[T0]], i32 0, i32 4
end_comment

begin_comment
comment|// CHECK-NEXT: [[T2:%.*]] = bitcast [[AGG]]* [[T1]] to i8*
end_comment

begin_comment
comment|// CHECK-NEXT: [[T3:%.*]] = bitcast [[AGG]]* [[TEMP]] to i8*
end_comment

begin_comment
comment|// CHECK-NEXT: call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[T2]], i8* [[T3]], i64 4, i32 4, i1 false)
end_comment

begin_comment
comment|//   Verify that there's nothing else significant in the function.
end_comment

begin_comment
comment|// CHECK-NEXT: [[T0:%.*]] = bitcast [[BYREF]]* [[A]] to i8*
end_comment

begin_comment
comment|// CHECK-NEXT: call void @_Block_object_dispose(i8* [[T0]], i32 8)
end_comment

begin_comment
comment|// CHECK-NEXT: ret void
end_comment

begin_comment
comment|// When chaining assignments into __block variables, make sure we
end_comment

begin_comment
comment|// propagate the actual value into the outer variable.
end_comment

begin_comment
comment|// rdar://11757470
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
specifier|__block
name|Agg
name|a
decl_stmt|,
name|b
decl_stmt|;
name|a
operator|=
name|b
operator|=
name|makeAgg
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL:    define void @test1()
end_comment

begin_comment
comment|// CHECK:      [[A:%.*]] = alloca [[A_BYREF:%.*]], align 8
end_comment

begin_comment
comment|// CHECK-NEXT: [[B:%.*]] = alloca [[B_BYREF:%.*]], align 8
end_comment

begin_comment
comment|// CHECK-NEXT: [[TEMP:%.*]] = alloca [[AGG]], align 4
end_comment

begin_comment
comment|// CHECK:      [[RESULT:%.*]] = call i32 @makeAgg()
end_comment

begin_comment
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr [[AGG]]* [[TEMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK-NEXT: store i32 [[RESULT]], i32* [[T0]]
end_comment

begin_comment
comment|//   Check that we properly assign into the forwarding pointer, first for b:
end_comment

begin_comment
comment|// CHECK-NEXT: [[B_FORWARDING:%.*]] = getelementptr inbounds [[B_BYREF]]* [[B]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK-NEXT: [[T0:%.*]] = load [[B_BYREF]]** [[B_FORWARDING]]
end_comment

begin_comment
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[B_BYREF]]* [[T0]], i32 0, i32 4
end_comment

begin_comment
comment|// CHECK-NEXT: [[T2:%.*]] = bitcast [[AGG]]* [[T1]] to i8*
end_comment

begin_comment
comment|// CHECK-NEXT: [[T3:%.*]] = bitcast [[AGG]]* [[TEMP]] to i8*
end_comment

begin_comment
comment|// CHECK-NEXT: call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[T2]], i8* [[T3]], i64 4, i32 4, i1 false)
end_comment

begin_comment
comment|//   Then for 'a':
end_comment

begin_comment
comment|// CHECK-NEXT: [[A_FORWARDING:%.*]] = getelementptr inbounds [[A_BYREF]]* [[A]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK-NEXT: [[T0:%.*]] = load [[A_BYREF]]** [[A_FORWARDING]]
end_comment

begin_comment
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[A_BYREF]]* [[T0]], i32 0, i32 4
end_comment

begin_comment
comment|// CHECK-NEXT: [[T2:%.*]] = bitcast [[AGG]]* [[T1]] to i8*
end_comment

begin_comment
comment|// CHECK-NEXT: [[T3:%.*]] = bitcast [[AGG]]* [[TEMP]] to i8*
end_comment

begin_comment
comment|// CHECK-NEXT: call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[T2]], i8* [[T3]], i64 4, i32 4, i1 false)
end_comment

begin_comment
comment|//   Verify that there's nothing else significant in the function.
end_comment

begin_comment
comment|// CHECK-NEXT: [[T0:%.*]] = bitcast [[B_BYREF]]* [[B]] to i8*
end_comment

begin_comment
comment|// CHECK-NEXT: call void @_Block_object_dispose(i8* [[T0]], i32 8)
end_comment

begin_comment
comment|// CHECK-NEXT: [[T0:%.*]] = bitcast [[A_BYREF]]* [[A]] to i8*
end_comment

begin_comment
comment|// CHECK-NEXT: call void @_Block_object_dispose(i8* [[T0]], i32 8)
end_comment

begin_comment
comment|// CHECK-NEXT: ret void
end_comment

end_unit

