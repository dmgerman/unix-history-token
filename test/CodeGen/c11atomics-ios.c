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
comment|// CHECK-NEXT: [[T0:%.*]] = load float*, float** [[FP]]
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
comment|// CHECK-NEXT: [[T0:%.*]] = load float*, float** [[FP]]
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast float* [[T0]] to i32*
comment|// CHECK-NEXT: [[T2:%.*]] = load atomic i32, i32* [[T1]] seq_cst, align 4
comment|// CHECK-NEXT: [[T3:%.*]] = bitcast i32 [[T2]] to float
comment|// CHECK-NEXT: store float [[T3]], float* [[F]]
name|float
name|f
init|=
operator|*
name|fp
decl_stmt|;
comment|// CHECK-NEXT: [[T0:%.*]] = load float, float* [[F]], align 4
comment|// CHECK-NEXT: [[T1:%.*]] = load float*, float** [[FP]], align 4
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
comment|// CHECK-NEXT: [[P:%.*]] = load [[CF]]*, [[CF]]** [[FP]]
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[CF]], [[CF]]* [[P]], i32 0, i32 0
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[CF]], [[CF]]* [[P]], i32 0, i32 1
comment|// CHECK-NEXT: store float 1.000000e+00, float* [[T0]]
comment|// CHECK-NEXT: store float 0.000000e+00, float* [[T1]]
name|__c11_atomic_init
argument_list|(
name|fp
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[CF]], [[CF]]* [[X]], i32 0, i32 0
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[CF]], [[CF]]* [[X]], i32 0, i32 1
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
comment|// CHECK-NEXT: [[T0:%.*]] = load [[CF]]*, [[CF]]** [[FP]]
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast [[CF]]* [[T0]] to i64*
comment|// CHECK-NEXT: [[T2:%.*]] = load atomic i64, i64* [[T1]] seq_cst, align 8
comment|// CHECK-NEXT: [[T3:%.*]] = bitcast [[CF]]* [[TMP0]] to i64*
comment|// CHECK-NEXT: store i64 [[T2]], i64* [[T3]], align 8
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[CF]], [[CF]]* [[TMP0]], i32 0, i32 0
comment|// CHECK-NEXT: [[R:%.*]] = load float, float* [[T0]]
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[CF]], [[CF]]* [[TMP0]], i32 0, i32 1
comment|// CHECK-NEXT: [[I:%.*]] = load float, float* [[T0]]
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[CF]], [[CF]]* [[F]], i32 0, i32 0
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[CF]], [[CF]]* [[F]], i32 0, i32 1
comment|// CHECK-NEXT: store float [[R]], float* [[T0]]
comment|// CHECK-NEXT: store float [[I]], float* [[T1]]
specifier|_Complex
name|float
name|f
init|=
operator|*
name|fp
decl_stmt|;
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[CF]], [[CF]]* [[F]], i32 0, i32 0
comment|// CHECK-NEXT: [[R:%.*]] = load float, float* [[T0]]
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[CF]], [[CF]]* [[F]], i32 0, i32 1
comment|// CHECK-NEXT: [[I:%.*]] = load float, float* [[T0]]
comment|// CHECK-NEXT: [[DEST:%.*]] = load [[CF]]*, [[CF]]** [[FP]], align 4
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[CF]], [[CF]]* [[TMP1]], i32 0, i32 0
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[CF]], [[CF]]* [[TMP1]], i32 0, i32 1
comment|// CHECK-NEXT: store float [[R]], float* [[T0]]
comment|// CHECK-NEXT: store float [[I]], float* [[T1]]
comment|// CHECK-NEXT: [[T0:%.*]] = bitcast [[CF]]* [[TMP1]] to i64*
comment|// CHECK-NEXT: [[T1:%.*]] = load i64, i64* [[T0]], align 8
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
comment|// CHECK-NEXT: [[P:%.*]] = load [[S]]*, [[S]]** [[FP]]
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[S]], [[S]]* [[P]], i32 0, i32 0
comment|// CHECK-NEXT: store i16 1, i16* [[T0]], align 8
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[S]], [[S]]* [[P]], i32 0, i32 1
comment|// CHECK-NEXT: store i16 2, i16* [[T0]], align 2
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[S]], [[S]]* [[P]], i32 0, i32 2
comment|// CHECK-NEXT: store i16 3, i16* [[T0]], align 4
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[S]], [[S]]* [[P]], i32 0, i32 3
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
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[S]], [[S]]* [[X]], i32 0, i32 0
comment|// CHECK-NEXT: store i16 1, i16* [[T0]], align 8
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[S]], [[S]]* [[X]], i32 0, i32 1
comment|// CHECK-NEXT: store i16 2, i16* [[T0]], align 2
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[S]], [[S]]* [[X]], i32 0, i32 2
comment|// CHECK-NEXT: store i16 3, i16* [[T0]], align 4
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[S]], [[S]]* [[X]], i32 0, i32 3
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
comment|// CHECK-NEXT: [[T0:%.*]] = load [[S]]*, [[S]]** [[FP]]
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast [[S]]* [[T0]] to i64*
comment|// CHECK-NEXT: [[T2:%.*]] = load atomic i64, i64* [[T1]] seq_cst, align 8
comment|// CHECK-NEXT: [[T3:%.*]] = bitcast [[S]]* [[F]] to i64*
comment|// CHECK-NEXT: store i64 [[T2]], i64* [[T3]], align 2
name|S
name|f
init|=
operator|*
name|fp
decl_stmt|;
comment|// CHECK-NEXT: [[T0:%.*]] = load [[S]]*, [[S]]** [[FP]]
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast [[S]]* [[TMP0]] to i8*
comment|// CHECK-NEXT: [[T2:%.*]] = bitcast [[S]]* [[F]] to i8*
comment|// CHECK-NEXT: call void @llvm.memcpy.p0i8.p0i8.i32(i8* [[T1]], i8* [[T2]], i32 8, i32 2, i1 false)
comment|// CHECK-NEXT: [[T3:%.*]] = bitcast [[S]]* [[TMP0]] to i64*
comment|// CHECK-NEXT: [[T4:%.*]] = load i64, i64* [[T3]], align 8
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
comment|// CHECK-NEXT: [[P:%.*]] = load [[APS]]*, [[APS]]** [[FP]]
comment|// CHECK-NEXT: [[T0:%.*]] = bitcast [[APS]]* [[P]] to i8*
comment|// CHECK-NEXT: call void @llvm.memset.p0i8.i64(i8* [[T0]], i8 0, i64 8, i32 8, i1 false)
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[APS]], [[APS]]* [[P]], i32 0, i32 0
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[PS]], [[PS]]* [[T0]], i32 0, i32 0
comment|// CHECK-NEXT: store i16 1, i16* [[T1]], align 8
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[PS]], [[PS]]* [[T0]], i32 0, i32 1
comment|// CHECK-NEXT: store i16 2, i16* [[T1]], align 2
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[PS]], [[PS]]* [[T0]], i32 0, i32 2
comment|// CHECK-NEXT: store i16 3, i16* [[T1]], align 4
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
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[APS]], [[APS]]* [[X]], i32 0, i32 0
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[PS]], [[PS]]* [[T0]], i32 0, i32 0
comment|// CHECK-NEXT: store i16 1, i16* [[T1]], align 8
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[PS]], [[PS]]* [[T0]], i32 0, i32 1
comment|// CHECK-NEXT: store i16 2, i16* [[T1]], align 2
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[PS]], [[PS]]* [[T0]], i32 0, i32 2
comment|// CHECK-NEXT: store i16 3, i16* [[T1]], align 4
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
comment|// CHECK-NEXT: [[T0:%.*]] = load [[APS]]*, [[APS]]** [[FP]]
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast [[APS]]* [[T0]] to i64*
comment|// CHECK-NEXT: [[T2:%.*]] = load atomic i64, i64* [[T1]] seq_cst, align 8
comment|// CHECK-NEXT: [[T3:%.*]] = bitcast [[APS]]* [[TMP0]] to i64*
comment|// CHECK-NEXT: store i64 [[T2]], i64* [[T3]], align 8
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[APS]], [[APS]]* [[TMP0]], i32 0, i32 0
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast [[PS]]* [[F]] to i8*
comment|// CHECK-NEXT: [[T2:%.*]] = bitcast [[PS]]* [[T0]] to i8*
comment|// CHECK-NEXT: call void @llvm.memcpy.p0i8.p0i8.i32(i8* [[T1]], i8* [[T2]], i32 6, i32 2, i1 false)
name|PS
name|f
init|=
operator|*
name|fp
decl_stmt|;
comment|// CHECK-NEXT: [[T0:%.*]] = load [[APS]]*, [[APS]]** [[FP]]
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast { %struct.PS, [2 x i8] }* [[TMP1]] to i8*
comment|// CHECK-NEXT: call void @llvm.memset.p0i8.i32(i8* [[T1]], i8 0, i32 8, i32 8, i1 false)
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [[APS]], [[APS]]* [[TMP1]], i32 0, i32 0
comment|// CHECK-NEXT: [[T2:%.*]] = bitcast [[PS]]* [[T1]] to i8*
comment|// CHECK-NEXT: [[T3:%.*]] = bitcast [[PS]]* [[F]] to i8*
comment|// CHECK-NEXT: call void @llvm.memcpy.p0i8.p0i8.i32(i8* [[T2]], i8* [[T3]], i32 6, i32 2, i1 false)
comment|// CHECK-NEXT: [[T4:%.*]] = bitcast [[APS]]* [[TMP1]] to i64*
comment|// CHECK-NEXT: [[T5:%.*]] = load i64, i64* [[T4]], align 8
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
name|PS
name|test_promoted_load
parameter_list|(
atomic|_Atomic
argument_list|(
name|PS
argument_list|)
modifier|*
name|addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_promoted_load(%struct.PS* noalias sret %agg.result, { %struct.PS, [2 x i8] }* %addr)
comment|// CHECK:   [[ADDR_ARG:%.*]] = alloca { %struct.PS, [2 x i8] }*, align 4
comment|// CHECK:   [[ATOMIC_RES:%.*]] = alloca { %struct.PS, [2 x i8] }, align 8
comment|// CHECK:   store { %struct.PS, [2 x i8] }* %addr, { %struct.PS, [2 x i8] }** [[ADDR_ARG]], align 4
comment|// CHECK:   [[ADDR:%.*]] = load { %struct.PS, [2 x i8] }*, { %struct.PS, [2 x i8] }** [[ADDR_ARG]], align 4
comment|// CHECK:   [[ADDR64:%.*]] = bitcast { %struct.PS, [2 x i8] }* [[ADDR]] to i64*
comment|// CHECK:   [[ATOMIC_RES64:%.*]] = bitcast { %struct.PS, [2 x i8] }* [[ATOMIC_RES]] to i64*
comment|// CHECK:   [[VAL:%.*]] = load atomic i64, i64* [[ADDR64]] seq_cst, align 8
comment|// CHECK:   store i64 [[VAL]], i64* [[ATOMIC_RES64]], align 8
comment|// CHECK:   [[ATOMIC_RES_STRUCT:%.*]] = bitcast i64* [[ATOMIC_RES64]] to %struct.PS*
comment|// CHECK:   [[AGG_RESULT8:%.*]] = bitcast %struct.PS* %agg.result to i8*
comment|// CHECK:   [[ATOMIC_RES8:%.*]] = bitcast %struct.PS* [[ATOMIC_RES_STRUCT]] to i8*
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i32(i8* [[AGG_RESULT8]], i8* [[ATOMIC_RES8]], i32 6, i32 2, i1 false)
return|return
name|__c11_atomic_load
argument_list|(
name|addr
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_promoted_store
parameter_list|(
atomic|_Atomic
argument_list|(
name|PS
argument_list|)
modifier|*
name|addr
parameter_list|,
name|PS
modifier|*
name|val
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_promoted_store({ %struct.PS, [2 x i8] }* %addr, %struct.PS* %val)
comment|// CHECK:   [[ADDR_ARG:%.*]] = alloca { %struct.PS, [2 x i8] }*, align 4
comment|// CHECK:   [[VAL_ARG:%.*]] = alloca %struct.PS*, align 4
comment|// CHECK:   [[NONATOMIC_TMP:%.*]] = alloca %struct.PS, align 2
comment|// CHECK:   [[ATOMIC_VAL:%.*]] = alloca { %struct.PS, [2 x i8] }, align 8
comment|// CHECK:   store { %struct.PS, [2 x i8] }* %addr, { %struct.PS, [2 x i8] }** [[ADDR_ARG]], align 4
comment|// CHECK:   store %struct.PS* %val, %struct.PS** [[VAL_ARG]], align 4
comment|// CHECK:   [[ADDR:%.*]] = load { %struct.PS, [2 x i8] }*, { %struct.PS, [2 x i8] }** [[ADDR_ARG]], align 4
comment|// CHECK:   [[VAL:%.*]] = load %struct.PS*, %struct.PS** [[VAL_ARG]], align 4
comment|// CHECK:   [[NONATOMIC_TMP8:%.*]] = bitcast %struct.PS* [[NONATOMIC_TMP]] to i8*
comment|// CHECK:   [[VAL8:%.*]] = bitcast %struct.PS* [[VAL]] to i8*
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i32(i8* [[NONATOMIC_TMP8]], i8* [[VAL8]], i32 6, i32 2, i1 false)
comment|// CHECK:   [[ADDR64:%.*]] = bitcast { %struct.PS, [2 x i8] }* [[ADDR]] to i64*
comment|// CHECK:   [[ATOMIC_VAL8:%.*]] = bitcast { %struct.PS, [2 x i8] }* [[ATOMIC_VAL]] to i8*
comment|// CHECK:   [[NONATOMIC_TMP8:%.*]] = bitcast %struct.PS* [[NONATOMIC_TMP]] to i8*
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[ATOMIC_VAL8]], i8* [[NONATOMIC_TMP8]], i64 6, i32 2, i1 false)
comment|// CHECK:   [[ATOMIC_VAL64:%.*]] = bitcast { %struct.PS, [2 x i8] }* [[ATOMIC_VAL]] to i64*
comment|// CHECK:   [[VAL64:%.*]] = load i64, i64* [[ATOMIC_VAL64]], align 8
comment|// CHECK:   store atomic i64 [[VAL64]], i64* [[ADDR64]] seq_cst, align 8
name|__c11_atomic_store
argument_list|(
name|addr
argument_list|,
operator|*
name|val
argument_list|,
literal|5
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|PS
name|test_promoted_exchange
parameter_list|(
atomic|_Atomic
argument_list|(
name|PS
argument_list|)
modifier|*
name|addr
parameter_list|,
name|PS
modifier|*
name|val
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_promoted_exchange(%struct.PS* noalias sret %agg.result, { %struct.PS, [2 x i8] }* %addr, %struct.PS* %val)
comment|// CHECK:   [[ADDR_ARG:%.*]] = alloca { %struct.PS, [2 x i8] }*, align 4
comment|// CHECK:   [[VAL_ARG:%.*]] = alloca %struct.PS*, align 4
comment|// CHECK:   [[NONATOMIC_TMP:%.*]] = alloca %struct.PS, align 2
comment|// CHECK:   [[ATOMIC_VAL:%.*]] = alloca { %struct.PS, [2 x i8] }, align 8
comment|// CHECK:   [[ATOMIC_RES:%.*]] = alloca { %struct.PS, [2 x i8] }, align 8
comment|// CHECK:   store { %struct.PS, [2 x i8] }* %addr, { %struct.PS, [2 x i8] }** [[ADDR_ARG]], align 4
comment|// CHECK:   store %struct.PS* %val, %struct.PS** [[VAL_ARG]], align 4
comment|// CHECK:   [[ADDR:%.*]] = load { %struct.PS, [2 x i8] }*, { %struct.PS, [2 x i8] }** [[ADDR_ARG]], align 4
comment|// CHECK:   [[VAL:%.*]] = load %struct.PS*, %struct.PS** [[VAL_ARG]], align 4
comment|// CHECK:   [[NONATOMIC_TMP8:%.*]] = bitcast %struct.PS* [[NONATOMIC_TMP]] to i8*
comment|// CHECK:   [[VAL8:%.*]] = bitcast %struct.PS* [[VAL]] to i8*
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i32(i8* [[NONATOMIC_TMP8]], i8* [[VAL8]], i32 6, i32 2, i1 false)
comment|// CHECK:   [[ADDR64:%.*]] = bitcast { %struct.PS, [2 x i8] }* [[ADDR]] to i64*
comment|// CHECK:   [[ATOMIC_VAL8:%.*]] = bitcast { %struct.PS, [2 x i8] }* [[ATOMIC_VAL]] to i8*
comment|// CHECK:   [[NONATOMIC_TMP8:%.*]] = bitcast %struct.PS* [[NONATOMIC_TMP]] to i8*
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[ATOMIC_VAL8]], i8* [[NONATOMIC_TMP8]], i64 6, i32 2, i1 false)
comment|// CHECK:   [[ATOMIC_VAL64:%.*]] = bitcast { %struct.PS, [2 x i8] }* [[ATOMIC_VAL]] to i64*
comment|// CHECK:   [[ATOMIC_RES64:%.*]] = bitcast { %struct.PS, [2 x i8] }* [[ATOMIC_RES]] to i64*
comment|// CHECK:   [[VAL64:%.*]] = load i64, i64* [[ATOMIC_VAL64]], align 8
comment|// CHECK:   [[RES:%.*]] = atomicrmw xchg i64* [[ADDR64]], i64 [[VAL64]] seq_cst
comment|// CHECK:   store i64 [[RES]], i64* [[ATOMIC_RES64]], align 8
comment|// CHECK:   [[ATOMIC_RES_STRUCT:%.*]] = bitcast i64* [[ATOMIC_RES64]] to %struct.PS*
comment|// CHECK:   [[AGG_RESULT8:%.*]] = bitcast %struct.PS* %agg.result to i8*
comment|// CHECK:   [[ATOMIC_RES8:%.*]] = bitcast %struct.PS* [[ATOMIC_RES_STRUCT]] to i8*
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i32(i8* [[AGG_RESULT8]], i8* [[ATOMIC_RES8]], i32 6, i32 2, i1 false)
return|return
name|__c11_atomic_exchange
argument_list|(
name|addr
argument_list|,
operator|*
name|val
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|_Bool
name|test_promoted_cmpxchg
parameter_list|(
atomic|_Atomic
argument_list|(
name|PS
argument_list|)
modifier|*
name|addr
parameter_list|,
name|PS
modifier|*
name|desired
parameter_list|,
name|PS
modifier|*
name|new
parameter_list|)
block|{
comment|// CHECK:   define zeroext i1 @test_promoted_cmpxchg({ %struct.PS, [2 x i8] }* %addr, %struct.PS* %desired, %struct.PS* %new) #0 {
comment|// CHECK:   [[ADDR_ARG:%.*]] = alloca { %struct.PS, [2 x i8] }*, align 4
comment|// CHECK:   [[DESIRED_ARG:%.*]] = alloca %struct.PS*, align 4
comment|// CHECK:   [[NEW_ARG:%.*]] = alloca %struct.PS*, align 4
comment|// CHECK:   [[NONATOMIC_TMP:%.*]] = alloca %struct.PS, align 2
comment|// CHECK:   [[ATOMIC_DESIRED:%.*]] = alloca { %struct.PS, [2 x i8] }, align 8
comment|// CHECK:   [[ATOMIC_NEW:%.*]] = alloca { %struct.PS, [2 x i8] }, align 8
comment|// CHECK:   [[RES_ADDR:%.*]] = alloca i8, align 1
comment|// CHECK:   store { %struct.PS, [2 x i8] }* %addr, { %struct.PS, [2 x i8] }** [[ADDR_ARG]], align 4
comment|// CHECK:   store %struct.PS* %desired, %struct.PS** [[DESIRED_ARG]], align 4
comment|// CHECK:   store %struct.PS* %new, %struct.PS** [[NEW_ARG]], align 4
comment|// CHECK:   [[ADDR:%.*]] = load { %struct.PS, [2 x i8] }*, { %struct.PS, [2 x i8] }** [[ADDR_ARG]], align 4
comment|// CHECK:   [[DESIRED:%.*]] = load %struct.PS*, %struct.PS** [[DESIRED_ARG]], align 4
comment|// CHECK:   [[NEW:%.*]] = load %struct.PS*, %struct.PS** [[NEW_ARG]], align 4
comment|// CHECK:   [[NONATOMIC_TMP8:%.*]] = bitcast %struct.PS* [[NONATOMIC_TMP]] to i8*
comment|// CHECK:   [[NEW8:%.*]] = bitcast %struct.PS* [[NEW]] to i8*
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i32(i8* [[NONATOMIC_TMP8]], i8* [[NEW8]], i32 6, i32 2, i1 false)
comment|// CHECK:   [[ADDR64:%.*]] = bitcast { %struct.PS, [2 x i8] }* [[ADDR]] to i64*
comment|// CHECK:   [[ATOMIC_DESIRED8:%.*]] = bitcast { %struct.PS, [2 x i8] }* [[ATOMIC_DESIRED:%.*]] to i8*
comment|// CHECK:   [[DESIRED8:%.*]] = bitcast %struct.PS* [[DESIRED]] to i8*
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[ATOMIC_DESIRED8]], i8* [[DESIRED8]], i64 6, i32 2, i1 false)
comment|// CHECK:   [[ATOMIC_DESIRED64:%.*]] = bitcast { %struct.PS, [2 x i8] }* [[ATOMIC_DESIRED:%.*]] to i64*
comment|// CHECK:   [[ATOMIC_NEW8:%.*]] = bitcast { %struct.PS, [2 x i8] }* [[ATOMIC_NEW]] to i8*
comment|// CHECK:   [[NONATOMIC_TMP8:%.*]] = bitcast %struct.PS* [[NONATOMIC_TMP]] to i8*
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[ATOMIC_NEW8]], i8* [[NONATOMIC_TMP8]], i64 6, i32 2, i1 false)
comment|// CHECK:   [[ATOMIC_NEW64:%.*]] = bitcast { %struct.PS, [2 x i8] }* [[ATOMIC_NEW]] to i64*
comment|// CHECK:   [[ATOMIC_DESIRED_VAL64:%.*]] = load i64, i64* [[ATOMIC_DESIRED64]], align 8
comment|// CHECK:   [[ATOMIC_NEW_VAL64:%.*]] = load i64, i64* [[ATOMIC_NEW64]], align 8
comment|// CHECK:   [[RES:%.*]] = cmpxchg i64* [[ADDR64]], i64 [[ATOMIC_DESIRED_VAL64]], i64 [[ATOMIC_NEW_VAL64]] seq_cst seq_cst
comment|// CHECK:   [[RES_VAL64:%.*]] = extractvalue { i64, i1 } [[RES]], 0
comment|// CHECK:   [[RES_BOOL:%.*]] = extractvalue { i64, i1 } [[RES]], 1
comment|// CHECK:   br i1 [[RES_BOOL]], label {{%.*}}, label {{%.*}}
comment|// CHECK:   store i64 [[RES_VAL64]], i64* [[ATOMIC_DESIRED64]], align 8
comment|// CHECK:   br label {{%.*}}
comment|// CHECK:   [[RES_BOOL8:%.*]] = zext i1 [[RES_BOOL]] to i8
comment|// CHECK:   store i8 [[RES_BOOL8]], i8* [[RES_ADDR]], align 1
comment|// CHECK:   [[RES_BOOL8:%.*]] = load i8, i8* [[RES_ADDR]], align 1
comment|// CHECK:   [[RETVAL:%.*]] = trunc i8 [[RES_BOOL8]] to i1
comment|// CHECK:   ret i1 [[RETVAL]]
return|return
name|__c11_atomic_compare_exchange_strong
argument_list|(
name|addr
argument_list|,
name|desired
argument_list|,
operator|*
name|new
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

end_unit

