begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple=armv7-apple-ios -std=c11 | FileCheck %s
end_comment

begin_comment
comment|// There isn't really anything special about iOS; it just happens to
end_comment

begin_comment
comment|// only deploy on processors with native atomics support, so it's a good
end_comment

begin_comment
comment|// way to test those code-paths.
end_comment

begin_comment
comment|// This work was done in pursuit of<rdar://13338582>.
end_comment

begin_comment
comment|// CHECK-LABEL: define void @testFloat(float*
end_comment

begin_function
name|void
name|testFloat
parameter_list|(
atomic|_Atomic
argument_list|(
name|float
argument_list|)
modifier|*
name|fp
parameter_list|)
block|{
comment|// CHECK:      [[FP:%.*]] = alloca float*
comment|// CHECK-NEXT: [[X:%.*]] = alloca float
comment|// CHECK-NEXT: [[F:%.*]] = alloca float
comment|// CHECK-NEXT: store float* {{%.*}}, float** [[FP]]
comment|// CHECK-NEXT: [[T0:%.*]] = load float** [[FP]]
comment|// CHECK-NEXT: store float 1.000000e+00, float* [[T0]], align 4
name|__c11_atomic_init
argument_list|(
name|fp
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: store float 2.000000e+00, float* [[X]], align 4
atomic|_Atomic
argument_list|(
name|float
argument_list|)
name|x
init|=
literal|2.0f
decl_stmt|;
comment|// CHECK-NEXT: [[T0:%.*]] = load float** [[FP]]
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast float* [[T0]] to i32*
comment|// CHECK-NEXT: [[T2:%.*]] = load atomic i32* [[T1]] seq_cst, align 4
comment|// CHECK-NEXT: [[T3:%.*]] = bitcast i32 [[T2]] to float
comment|// CHECK-NEXT: store float [[T3]], float* [[F]]
name|float
name|f
init|=
operator|*
name|fp
decl_stmt|;
comment|// CHECK-NEXT: [[T0:%.*]] = load float* [[F]], align 4
comment|// CHECK-NEXT: [[T1:%.*]] = load float** [[FP]], align 4
comment|// CHECK-NEXT: [[T2:%.*]] = bitcast float [[T0]] to i32
comment|// CHECK-NEXT: [[T3:%.*]] = bitcast float* [[T1]] to i32*
comment|// CHECK-NEXT: store atomic i32 [[T2]], i32* [[T3]] seq_cst, align 4
operator|*
name|fp
operator|=
name|f
expr_stmt|;
comment|// CHECK-NEXT: ret void
block|}
end_function

begin_comment
comment|// CHECK: define void @testComplexFloat([[CF:{ float, float }]]*
end_comment

begin_function
name|void
name|testComplexFloat
parameter_list|(
atomic|_Atomic
argument_list|(
specifier|_Complex
name|float
argument_list|)
modifier|*
name|fp
parameter_list|)
block|{
comment|// CHECK:      [[FP:%.*]] = alloca [[CF]]*, align 4
comment|// CHECK-NEXT: [[X:%.*]] = alloca [[CF]], align 8
comment|// CHECK-NEXT: [[F:%.*]] = alloca [[CF]], align 4
comment|// CHECK-NEXT: [[TMP0:%.*]] = alloca [[CF]], align 8
comment|// CHECK-NEXT: [[TMP1:%.*]] = alloca [[CF]], align 8
comment|// CHECK-NEXT: store [[CF]]*
comment|// CHECK-NEXT: [[P:%.*]] = load [[CF]]** [[FP]]
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[CF]]* [[P]], i32 0, i32 0
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[CF]]* [[P]], i32 0, i32 1
comment|// CHECK-NEXT: store float 1.000000e+00, float* [[T0]]
comment|// CHECK-NEXT: store float 0.000000e+00, float* [[T1]]
name|__c11_atomic_init
argument_list|(
name|fp
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[CF]]* [[X]], i32 0, i32 0
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[CF]]* [[X]], i32 0, i32 1
comment|// CHECK-NEXT: store float 2.000000e+00, float* [[T0]]
comment|// CHECK-NEXT: store float 0.000000e+00, float* [[T1]]
atomic|_Atomic
argument_list|(
specifier|_Complex
name|float
argument_list|)
name|x
init|=
literal|2.0f
decl_stmt|;
comment|// CHECK-NEXT: [[T0:%.*]] = load [[CF]]** [[FP]]
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast [[CF]]* [[T0]] to i64*
comment|// CHECK-NEXT: [[T2:%.*]] = load atomic i64* [[T1]] seq_cst, align 8
comment|// CHECK-NEXT: [[T3:%.*]] = bitcast [[CF]]* [[TMP0]] to i64*
comment|// CHECK-NEXT: store i64 [[T2]], i64* [[T3]], align 8
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[CF]]* [[TMP0]], i32 0, i32 0
comment|// CHECK-NEXT: [[R:%.*]] = load float* [[T0]]
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[CF]]* [[TMP0]], i32 0, i32 1
comment|// CHECK-NEXT: [[I:%.*]] = load float* [[T0]]
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[CF]]* [[F]], i32 0, i32 0
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[CF]]* [[F]], i32 0, i32 1
comment|// CHECK-NEXT: store float [[R]], float* [[T0]]
comment|// CHECK-NEXT: store float [[I]], float* [[T1]]
specifier|_Complex
name|float
name|f
init|=
operator|*
name|fp
decl_stmt|;
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[CF]]* [[F]], i32 0, i32 0
comment|// CHECK-NEXT: [[R:%.*]] = load float* [[T0]]
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[CF]]* [[F]], i32 0, i32 1
comment|// CHECK-NEXT: [[I:%.*]] = load float* [[T0]]
comment|// CHECK-NEXT: [[DEST:%.*]] = load [[CF]]** [[FP]], align 4
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[CF]]* [[TMP1]], i32 0, i32 0
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[CF]]* [[TMP1]], i32 0, i32 1
comment|// CHECK-NEXT: store float [[R]], float* [[T0]]
comment|// CHECK-NEXT: store float [[I]], float* [[T1]]
comment|// CHECK-NEXT: [[T0:%.*]] = bitcast [[CF]]* [[TMP1]] to i64*
comment|// CHECK-NEXT: [[T1:%.*]] = load i64* [[T0]], align 8
comment|// CHECK-NEXT: [[T2:%.*]] = bitcast [[CF]]* [[DEST]] to i64*
comment|// CHECK-NEXT: store atomic i64 [[T1]], i64* [[T2]] seq_cst, align 8
operator|*
name|fp
operator|=
name|f
expr_stmt|;
comment|// CHECK-NEXT: ret void
block|}
end_function

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|,
name|w
decl_stmt|;
block|}
name|S
typedef|;
end_typedef

begin_comment
comment|// CHECK: define void @testStruct([[S:.*]]*
end_comment

begin_function
name|void
name|testStruct
parameter_list|(
atomic|_Atomic
argument_list|(
name|S
argument_list|)
modifier|*
name|fp
parameter_list|)
block|{
comment|// CHECK:      [[FP:%.*]] = alloca [[S]]*, align 4
comment|// CHECK-NEXT: [[X:%.*]] = alloca [[S]], align 8
comment|// CHECK-NEXT: [[F:%.*]] = alloca [[S:%.*]], align 2
comment|// CHECK-NEXT: [[TMP0:%.*]] = alloca [[S]], align 8
comment|// CHECK-NEXT: store [[S]]*
comment|// CHECK-NEXT: [[P:%.*]] = load [[S]]** [[FP]]
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[S]]* [[P]], i32 0, i32 0
comment|// CHECK-NEXT: store i16 1, i16* [[T0]], align 2
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[S]]* [[P]], i32 0, i32 1
comment|// CHECK-NEXT: store i16 2, i16* [[T0]], align 2
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[S]]* [[P]], i32 0, i32 2
comment|// CHECK-NEXT: store i16 3, i16* [[T0]], align 2
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[S]]* [[P]], i32 0, i32 3
comment|// CHECK-NEXT: store i16 4, i16* [[T0]], align 2
name|__c11_atomic_init
argument_list|(
name|fp
argument_list|,
operator|(
name|S
operator|)
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[S]]* [[X]], i32 0, i32 0
comment|// CHECK-NEXT: store i16 1, i16* [[T0]], align 2
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[S]]* [[X]], i32 0, i32 1
comment|// CHECK-NEXT: store i16 2, i16* [[T0]], align 2
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[S]]* [[X]], i32 0, i32 2
comment|// CHECK-NEXT: store i16 3, i16* [[T0]], align 2
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[S]]* [[X]], i32 0, i32 3
comment|// CHECK-NEXT: store i16 4, i16* [[T0]], align 2
atomic|_Atomic
argument_list|(
name|S
argument_list|)
name|x
init|=
operator|(
name|S
operator|)
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
comment|// CHECK-NEXT: [[T0:%.*]] = load [[S]]** [[FP]]
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast [[S]]* [[T0]] to i64*
comment|// CHECK-NEXT: [[T2:%.*]] = load atomic i64* [[T1]] seq_cst, align 8
comment|// CHECK-NEXT: [[T3:%.*]] = bitcast [[S]]* [[F]] to i64*
comment|// CHECK-NEXT: store i64 [[T2]], i64* [[T3]], align 2
name|S
name|f
init|=
operator|*
name|fp
decl_stmt|;
comment|// CHECK-NEXT: [[T0:%.*]] = load [[S]]** [[FP]]
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast [[S]]* [[TMP0]] to i8*
comment|// CHECK-NEXT: [[T2:%.*]] = bitcast [[S]]* [[F]] to i8*
comment|// CHECK-NEXT: call void @llvm.memcpy.p0i8.p0i8.i32(i8* [[T1]], i8* [[T2]], i32 8, i32 2, i1 false)
comment|// CHECK-NEXT: [[T3:%.*]] = bitcast [[S]]* [[TMP0]] to i64*
comment|// CHECK-NEXT: [[T4:%.*]] = load i64* [[T3]], align 8
comment|// CHECK-NEXT: [[T5:%.*]] = bitcast [[S]]* [[T0]] to i64*
comment|// CHECK-NEXT: store atomic i64 [[T4]], i64* [[T5]] seq_cst, align 8
operator|*
name|fp
operator|=
name|f
expr_stmt|;
comment|// CHECK-NEXT: ret void
block|}
end_function

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
block|}
name|PS
typedef|;
end_typedef

begin_comment
comment|// CHECK: define void @testPromotedStruct([[APS:.*]]*
end_comment

begin_function
name|void
name|testPromotedStruct
parameter_list|(
atomic|_Atomic
argument_list|(
name|PS
argument_list|)
modifier|*
name|fp
parameter_list|)
block|{
comment|// CHECK:      [[FP:%.*]] = alloca [[APS]]*, align 4
comment|// CHECK-NEXT: [[X:%.*]] = alloca [[APS]], align 8
comment|// CHECK-NEXT: [[F:%.*]] = alloca [[PS:%.*]], align 2
comment|// CHECK-NEXT: [[TMP0:%.*]] = alloca [[APS]], align 8
comment|// CHECK-NEXT: [[TMP1:%.*]] = alloca [[APS]], align 8
comment|// CHECK-NEXT: store [[APS]]*
comment|// CHECK-NEXT: [[P:%.*]] = load [[APS]]** [[FP]]
comment|// CHECK-NEXT: [[T0:%.*]] = bitcast [[APS]]* [[P]] to i8*
comment|// CHECK-NEXT: call void @llvm.memset.p0i8.i64(i8* [[T0]], i8 0, i64 8, i32 8, i1 false)
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[APS]]* [[P]], i32 0, i32 0
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[PS]]* [[T0]], i32 0, i32 0
comment|// CHECK-NEXT: store i16 1, i16* [[T1]], align 2
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[PS]]* [[T0]], i32 0, i32 1
comment|// CHECK-NEXT: store i16 2, i16* [[T1]], align 2
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[PS]]* [[T0]], i32 0, i32 2
comment|// CHECK-NEXT: store i16 3, i16* [[T1]], align 2
name|__c11_atomic_init
argument_list|(
name|fp
argument_list|,
operator|(
name|PS
operator|)
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|}
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: [[T0:%.*]] = bitcast [[APS]]* [[X]] to i8*
comment|// CHECK-NEXT: call void @llvm.memset.p0i8.i32(i8* [[T0]], i8 0, i32 8, i32 8, i1 false)
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[APS]]* [[X]], i32 0, i32 0
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[PS]]* [[T0]], i32 0, i32 0
comment|// CHECK-NEXT: store i16 1, i16* [[T1]], align 2
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[PS]]* [[T0]], i32 0, i32 1
comment|// CHECK-NEXT: store i16 2, i16* [[T1]], align 2
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[PS]]* [[T0]], i32 0, i32 2
comment|// CHECK-NEXT: store i16 3, i16* [[T1]], align 2
atomic|_Atomic
argument_list|(
name|PS
argument_list|)
name|x
init|=
operator|(
name|PS
operator|)
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|}
decl_stmt|;
comment|// CHECK-NEXT: [[T0:%.*]] = load [[APS]]** [[FP]]
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast [[APS]]* [[T0]] to i64*
comment|// CHECK-NEXT: [[T2:%.*]] = load atomic i64* [[T1]] seq_cst, align 8
comment|// CHECK-NEXT: [[T3:%.*]] = bitcast [[APS]]* [[TMP0]] to i64*
comment|// CHECK-NEXT: store i64 [[T2]], i64* [[T3]], align 2
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[APS]]* [[TMP0]], i32 0, i32 0
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast [[PS]]* [[F]] to i8*
comment|// CHECK-NEXT: [[T2:%.*]] = bitcast [[PS]]* [[T0]] to i8*
comment|// CHECK-NEXT: call void @llvm.memcpy.p0i8.p0i8.i32(i8* [[T1]], i8* [[T2]], i32 6, i32 2, i1 false)
name|PS
name|f
init|=
operator|*
name|fp
decl_stmt|;
comment|// CHECK-NEXT: [[T0:%.*]] = load [[APS]]** [[FP]]
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast { %struct.PS, [2 x i8] }* [[TMP1]] to i8*
comment|// CHECK-NEXT: call void @llvm.memset.p0i8.i32(i8* [[T1]], i8 0, i32 8, i32 8, i1 false)
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[APS]]* [[TMP1]], i32 0, i32 0
comment|// CHECK-NEXT: [[T2:%.*]] = bitcast [[PS]]* [[T1]] to i8*
comment|// CHECK-NEXT: [[T3:%.*]] = bitcast [[PS]]* [[F]] to i8*
comment|// CHECK-NEXT: call void @llvm.memcpy.p0i8.p0i8.i32(i8* [[T2]], i8* [[T3]], i32 6, i32 2, i1 false)
comment|// CHECK-NEXT: [[T4:%.*]] = bitcast [[APS]]* [[TMP1]] to i64*
comment|// CHECK-NEXT: [[T5:%.*]] = load i64* [[T4]], align 8
comment|// CHECK-NEXT: [[T6:%.*]] = bitcast [[APS]]* [[T0]] to i64*
comment|// CHECK-NEXT: store atomic i64 [[T5]], i64* [[T6]] seq_cst, align 8
operator|*
name|fp
operator|=
name|f
expr_stmt|;
comment|// CHECK-NEXT: ret void
block|}
end_function

begin_function
name|void
name|testPromotedStructOps
parameter_list|(
atomic|_Atomic
argument_list|(
name|PS
argument_list|)
modifier|*
name|p
parameter_list|)
block|{
name|PS
name|a
init|=
name|__c11_atomic_load
argument_list|(
name|p
argument_list|,
literal|5
argument_list|)
decl_stmt|;
name|__c11_atomic_store
argument_list|(
name|p
argument_list|,
name|a
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|PS
name|b
init|=
name|__c11_atomic_exchange
argument_list|(
name|p
argument_list|,
name|a
argument_list|,
literal|5
argument_list|)
decl_stmt|;
name|_Bool
name|v
init|=
name|__c11_atomic_compare_exchange_strong
argument_list|(
name|p
argument_list|,
operator|&
name|b
argument_list|,
name|a
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
decl_stmt|;
name|v
operator|=
name|__c11_atomic_compare_exchange_weak
argument_list|(
name|p
argument_list|,
operator|&
name|b
argument_list|,
name|a
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

