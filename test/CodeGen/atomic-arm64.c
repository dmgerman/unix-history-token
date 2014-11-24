begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple=arm64-apple-ios7 | FileCheck %s
end_comment

begin_comment
comment|// Memory ordering values.
end_comment

begin_enum
enum|enum
block|{
name|memory_order_relaxed
init|=
literal|0
block|,
name|memory_order_consume
init|=
literal|1
block|,
name|memory_order_acquire
init|=
literal|2
block|,
name|memory_order_release
init|=
literal|3
block|,
name|memory_order_acq_rel
init|=
literal|4
block|,
name|memory_order_seq_cst
init|=
literal|5
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|a
decl_stmt|,
modifier|*
name|b
decl_stmt|;
block|}
name|pointer_pair_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|a
decl_stmt|,
modifier|*
name|b
decl_stmt|,
modifier|*
name|c
decl_stmt|,
modifier|*
name|d
decl_stmt|;
block|}
name|pointer_quad_t
typedef|;
end_typedef

begin_comment
comment|// rdar://13489679
end_comment

begin_decl_stmt
specifier|extern
atomic|_Atomic
argument_list|(
name|_Bool
argument_list|)
name|a_bool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
atomic|_Atomic
argument_list|(
name|float
argument_list|)
name|a_float
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
atomic|_Atomic
argument_list|(
name|void
operator|*
argument_list|)
name|a_pointer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
atomic|_Atomic
argument_list|(
name|pointer_pair_t
argument_list|)
name|a_pointer_pair
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
atomic|_Atomic
argument_list|(
name|pointer_quad_t
argument_list|)
name|a_pointer_quad
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:    define void @test0()
end_comment

begin_comment
comment|// CHECK:      [[TEMP:%.*]] = alloca i8, align 1
end_comment

begin_comment
comment|// CHECK-NEXT: store i8 1, i8* [[TEMP]]
end_comment

begin_comment
comment|// CHECK-NEXT: [[T0:%.*]] = load i8* [[TEMP]], align 1
end_comment

begin_comment
comment|// CHECK-NEXT: store atomic i8 [[T0]], i8* @a_bool seq_cst, align 1
end_comment

begin_function
name|void
name|test0
parameter_list|()
block|{
name|__c11_atomic_store
argument_list|(
operator|&
name|a_bool
argument_list|,
literal|1
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK:    define void @test1()
end_comment

begin_comment
comment|// CHECK:      [[TEMP:%.*]] = alloca float, align 4
end_comment

begin_comment
comment|// CHECK-NEXT: store float 3.000000e+00, float* [[TEMP]]
end_comment

begin_comment
comment|// CHECK-NEXT: [[T0:%.*]] = bitcast float* [[TEMP]] to i32*
end_comment

begin_comment
comment|// CHECK-NEXT: [[T1:%.*]] = load i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK-NEXT: store atomic i32 [[T1]], i32* bitcast (float* @a_float to i32*) seq_cst, align 4
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
name|__c11_atomic_store
argument_list|(
operator|&
name|a_float
argument_list|,
literal|3
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK:    define void @test2()
end_comment

begin_comment
comment|// CHECK:      [[TEMP:%.*]] = alloca i8*, align 8
end_comment

begin_comment
comment|// CHECK-NEXT: store i8* @a_bool, i8** [[TEMP]]
end_comment

begin_comment
comment|// CHECK-NEXT: [[T0:%.*]] = bitcast i8** [[TEMP]] to i64*
end_comment

begin_comment
comment|// CHECK-NEXT: [[T1:%.*]] = load i64* [[T0]], align 8
end_comment

begin_comment
comment|// CHECK-NEXT: store atomic i64 [[T1]], i64* bitcast (i8** @a_pointer to i64*) seq_cst, align 8
end_comment

begin_function
name|void
name|test2
parameter_list|()
block|{
name|__c11_atomic_store
argument_list|(
operator|&
name|a_pointer
argument_list|,
operator|&
name|a_bool
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK:    define void @test3(
end_comment

begin_comment
comment|// CHECK:      [[PAIR:%.*]] = alloca [[PAIR_T:%.*]], align 8
end_comment

begin_comment
comment|// CHECK-NEXT: [[TEMP:%.*]] = alloca [[PAIR_T]], align 8
end_comment

begin_comment
comment|// CHECK:      llvm.memcpy
end_comment

begin_comment
comment|// CHECK-NEXT: [[T0:%.*]] = bitcast [[PAIR_T]]* [[TEMP]] to i128*
end_comment

begin_comment
comment|// CHECK-NEXT: [[T1:%.*]] = load i128* [[T0]], align 16
end_comment

begin_comment
comment|// CHECK-NEXT: store atomic i128 [[T1]], i128* bitcast ([[PAIR_T]]* @a_pointer_pair to i128*) seq_cst, align 16
end_comment

begin_function
name|void
name|test3
parameter_list|(
name|pointer_pair_t
name|pair
parameter_list|)
block|{
name|__c11_atomic_store
argument_list|(
operator|&
name|a_pointer_pair
argument_list|,
name|pair
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK:    define void @test4([[QUAD_T:%.*]]*
end_comment

begin_comment
comment|// CHECK:      [[TEMP:%.*]] = alloca [[QUAD_T:%.*]], align 8
end_comment

begin_comment
comment|// CHECK-NEXT: [[T0:%.*]] = bitcast [[QUAD_T]]* [[TEMP]] to i8*
end_comment

begin_comment
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast [[QUAD_T]]* {{%.*}} to i8*
end_comment

begin_comment
comment|// CHECK-NEXT: call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[T0]], i8* [[T1]], i64 32, i32 8, i1 false)
end_comment

begin_comment
comment|// CHECK-NEXT: [[T0:%.*]] = bitcast [[QUAD_T]]* [[TEMP]] to i8*
end_comment

begin_comment
comment|// CHECK-NEXT: call void @__atomic_store(i64 32, i8* bitcast ([[QUAD_T]]* @a_pointer_quad to i8*), i8* [[T0]], i32 5)
end_comment

begin_function
name|void
name|test4
parameter_list|(
name|pointer_quad_t
name|quad
parameter_list|)
block|{
name|__c11_atomic_store
argument_list|(
operator|&
name|a_pointer_quad
argument_list|,
name|quad
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

