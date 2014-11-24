begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple=armv5-unknown-freebsd -std=c11 | FileCheck %s
end_comment

begin_comment
comment|// Test that we are generating atomicrmw instructions, rather than
end_comment

begin_comment
comment|// compare-exchange loops for common atomic ops.  This makes a big difference
end_comment

begin_comment
comment|// on RISC platforms, where the compare-exchange loop becomes a ll/sc pair for
end_comment

begin_comment
comment|// the load and then another ll/sc in the loop, expanding to about 30
end_comment

begin_comment
comment|// instructions when it should be only 4.  It has a smaller, but still
end_comment

begin_comment
comment|// noticeable, impact on platforms like x86 and RISC-V, where there are atomic
end_comment

begin_comment
comment|// RMW instructions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// We currently emit cmpxchg loops for most operations on _Bools, because
end_comment

begin_comment
comment|// they're sufficiently rare that it's not worth making sure that the semantics
end_comment

begin_comment
comment|// are correct.
end_comment

begin_comment
comment|// CHECK: @testStructGlobal = global {{.*}} { i16 1, i16 2, i16 3, i16 4 }
end_comment

begin_comment
comment|// CHECK: @testPromotedStructGlobal = global {{.*}} { %{{.*}} { i16 1, i16 2, i16 3 }, [2 x i8] zeroinitializer }
end_comment

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
name|vector
typedef|;
end_typedef

begin_decl_stmt
atomic|_Atomic
argument_list|(
name|_Bool
argument_list|)
name|b
decl_stmt|;
end_decl_stmt

begin_decl_stmt
atomic|_Atomic
argument_list|(
name|int
argument_list|)
name|i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
atomic|_Atomic
argument_list|(
name|long
name|long
argument_list|)
name|l
decl_stmt|;
end_decl_stmt

begin_decl_stmt
atomic|_Atomic
argument_list|(
name|short
argument_list|)
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
atomic|_Atomic
argument_list|(
name|char
operator|*
argument_list|)
name|p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
atomic|_Atomic
argument_list|(
name|float
argument_list|)
name|f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
atomic|_Atomic
argument_list|(
name|vector
argument_list|)
name|v
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: testinc
end_comment

begin_function
name|void
name|testinc
parameter_list|(
name|void
parameter_list|)
block|{
comment|// Special case for suffix bool++, sets to true and returns the old value.
comment|// CHECK: atomicrmw xchg i8* @b, i8 1 seq_cst
name|b
operator|++
expr_stmt|;
comment|// CHECK: atomicrmw add i32* @i, i32 1 seq_cst
name|i
operator|++
expr_stmt|;
comment|// CHECK: atomicrmw add i64* @l, i64 1 seq_cst
name|l
operator|++
expr_stmt|;
comment|// CHECK: atomicrmw add i16* @s, i16 1 seq_cst
name|s
operator|++
expr_stmt|;
comment|// Prefix increment
comment|// Special case for bool: set to true and return true
comment|// CHECK: store atomic i8 1, i8* @b seq_cst, align 1
operator|++
name|b
expr_stmt|;
comment|// Currently, we have no variant of atomicrmw that returns the new value, so
comment|// we have to generate an atomic add, which returns the old value, and then a
comment|// non-atomic add.
comment|// CHECK: atomicrmw add i32* @i, i32 1 seq_cst
comment|// CHECK: add i32
operator|++
name|i
expr_stmt|;
comment|// CHECK: atomicrmw add i64* @l, i64 1 seq_cst
comment|// CHECK: add i64
operator|++
name|l
expr_stmt|;
comment|// CHECK: atomicrmw add i16* @s, i16 1 seq_cst
comment|// CHECK: add i16
operator|++
name|s
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: testdec
end_comment

begin_function
name|void
name|testdec
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: cmpxchg i8* @b
name|b
operator|--
expr_stmt|;
comment|// CHECK: atomicrmw sub i32* @i, i32 1 seq_cst
name|i
operator|--
expr_stmt|;
comment|// CHECK: atomicrmw sub i64* @l, i64 1 seq_cst
name|l
operator|--
expr_stmt|;
comment|// CHECK: atomicrmw sub i16* @s, i16 1 seq_cst
name|s
operator|--
expr_stmt|;
comment|// CHECK: cmpxchg i8* @b
operator|--
name|b
expr_stmt|;
comment|// CHECK: atomicrmw sub i32* @i, i32 1 seq_cst
comment|// CHECK: sub i32
operator|--
name|i
expr_stmt|;
comment|// CHECK: atomicrmw sub i64* @l, i64 1 seq_cst
comment|// CHECK: sub i64
operator|--
name|l
expr_stmt|;
comment|// CHECK: atomicrmw sub i16* @s, i16 1 seq_cst
comment|// CHECK: sub i16
operator|--
name|s
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: testaddeq
end_comment

begin_function
name|void
name|testaddeq
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: cmpxchg i8* @b
comment|// CHECK: atomicrmw add i32* @i, i32 42 seq_cst
comment|// CHECK: atomicrmw add i64* @l, i64 42 seq_cst
comment|// CHECK: atomicrmw add i16* @s, i16 42 seq_cst
name|b
operator|+=
literal|42
expr_stmt|;
name|i
operator|+=
literal|42
expr_stmt|;
name|l
operator|+=
literal|42
expr_stmt|;
name|s
operator|+=
literal|42
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: testsubeq
end_comment

begin_function
name|void
name|testsubeq
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: cmpxchg i8* @b
comment|// CHECK: atomicrmw sub i32* @i, i32 42 seq_cst
comment|// CHECK: atomicrmw sub i64* @l, i64 42 seq_cst
comment|// CHECK: atomicrmw sub i16* @s, i16 42 seq_cst
name|b
operator|-=
literal|42
expr_stmt|;
name|i
operator|-=
literal|42
expr_stmt|;
name|l
operator|-=
literal|42
expr_stmt|;
name|s
operator|-=
literal|42
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: testxoreq
end_comment

begin_function
name|void
name|testxoreq
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: cmpxchg i8* @b
comment|// CHECK: atomicrmw xor i32* @i, i32 42 seq_cst
comment|// CHECK: atomicrmw xor i64* @l, i64 42 seq_cst
comment|// CHECK: atomicrmw xor i16* @s, i16 42 seq_cst
name|b
operator|^=
literal|42
expr_stmt|;
name|i
operator|^=
literal|42
expr_stmt|;
name|l
operator|^=
literal|42
expr_stmt|;
name|s
operator|^=
literal|42
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: testoreq
end_comment

begin_function
name|void
name|testoreq
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: cmpxchg i8* @b
comment|// CHECK: atomicrmw or i32* @i, i32 42 seq_cst
comment|// CHECK: atomicrmw or i64* @l, i64 42 seq_cst
comment|// CHECK: atomicrmw or i16* @s, i16 42 seq_cst
name|b
operator||=
literal|42
expr_stmt|;
name|i
operator||=
literal|42
expr_stmt|;
name|l
operator||=
literal|42
expr_stmt|;
name|s
operator||=
literal|42
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: testandeq
end_comment

begin_function
name|void
name|testandeq
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: cmpxchg i8* @b
comment|// CHECK: atomicrmw and i32* @i, i32 42 seq_cst
comment|// CHECK: atomicrmw and i64* @l, i64 42 seq_cst
comment|// CHECK: atomicrmw and i16* @s, i16 42 seq_cst
name|b
operator|&=
literal|42
expr_stmt|;
name|i
operator|&=
literal|42
expr_stmt|;
name|l
operator|&=
literal|42
expr_stmt|;
name|s
operator|&=
literal|42
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define arm_aapcscc void @testFloat(float*
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
comment|// CHECK-NEXT: [[TMP0:%.*]] = alloca float
comment|// CHECK-NEXT: [[TMP1:%.*]] = alloca float
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
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast float* [[T0]] to i8*
comment|// CHECK-NEXT: [[T2:%.*]] = bitcast float* [[TMP0]] to i8*
comment|// CHECK-NEXT: call arm_aapcscc void @__atomic_load(i32 4, i8* [[T1]], i8* [[T2]], i32 5)
comment|// CHECK-NEXT: [[T3:%.*]] = load float* [[TMP0]], align 4
comment|// CHECK-NEXT: store float [[T3]], float* [[F]]
name|float
name|f
init|=
operator|*
name|fp
decl_stmt|;
comment|// CHECK-NEXT: [[T0:%.*]] = load float* [[F]], align 4
comment|// CHECK-NEXT: [[T1:%.*]] = load float** [[FP]], align 4
comment|// CHECK-NEXT: store float [[T0]], float* [[TMP1]], align 4
comment|// CHECK-NEXT: [[T2:%.*]] = bitcast float* [[T1]] to i8*
comment|// CHECK-NEXT: [[T3:%.*]] = bitcast float* [[TMP1]] to i8*
comment|// CHECK-NEXT: call arm_aapcscc void @__atomic_store(i32 4, i8* [[T2]], i8* [[T3]], i32 5)
operator|*
name|fp
operator|=
name|f
expr_stmt|;
comment|// CHECK-NEXT: ret void
block|}
end_function

begin_comment
comment|// CHECK: define arm_aapcscc void @testComplexFloat([[CF:{ float, float }]]*
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
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast [[CF]]* [[T0]] to i8*
comment|// CHECK-NEXT: [[T2:%.*]] = bitcast [[CF]]* [[TMP0]] to i8*
comment|// CHECK-NEXT: call arm_aapcscc void @__atomic_load(i32 8, i8* [[T1]], i8* [[T2]], i32 5)
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
comment|// CHECK-NEXT: [[T0:%.*]] = bitcast [[CF]]* [[DEST]] to i8*
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast [[CF]]* [[TMP1]] to i8*
comment|// CHECK-NEXT: call arm_aapcscc void @__atomic_store(i32 8, i8* [[T0]], i8* [[T1]], i32 5)
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

begin_decl_stmt
specifier|_Atomic
name|S
name|testStructGlobal
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
end_decl_stmt

begin_comment
comment|// CHECK: define arm_aapcscc void @testStruct([[S:.*]]*
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
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast [[S]]* [[T0]] to i8*
comment|// CHECK-NEXT: [[T2:%.*]] = bitcast [[S]]* [[F]] to i8*
comment|// CHECK-NEXT: call arm_aapcscc void @__atomic_load(i32 8, i8* [[T1]], i8* [[T2]], i32 5)
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
comment|// CHECK-NEXT: [[T3:%.*]] = bitcast [[S]]* [[T0]] to i8*
comment|// CHECK-NEXT: [[T4:%.*]] = bitcast [[S]]* [[TMP0]] to i8*
comment|// CHECK-NEXT: call arm_aapcscc void @__atomic_store(i32 8, i8* [[T3]], i8* [[T4]], i32 5)
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

begin_decl_stmt
specifier|_Atomic
name|PS
name|testPromotedStructGlobal
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
end_decl_stmt

begin_comment
comment|// CHECK: define arm_aapcscc void @testPromotedStruct([[APS:.*]]*
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
comment|// CHECK-NEXT: [[A:%.*]] = alloca i32, align 4
comment|// CHECK-NEXT: [[TMP2:%.*]] = alloca %struct.PS, align 2
comment|// CHECK-NEXT: [[TMP3:%.*]] = alloca [[APS]], align 8
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
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast [[APS]]* [[T0]] to i8*
comment|// CHECK-NEXT: [[T2:%.*]] = bitcast [[APS]]* [[TMP0]] to i8*
comment|// CHECK-NEXT: call arm_aapcscc void @__atomic_load(i32 8, i8* [[T1]], i8* [[T2]], i32 5)
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
comment|// CHECK-NEXT: [[T4:%.*]] = bitcast [[APS]]* [[T0]] to i8*
comment|// CHECK-NEXT: [[T5:%.*]] = bitcast [[APS]]* [[TMP1]] to i8*
comment|// CHECK-NEXT: call arm_aapcscc void @__atomic_store(i32 8, i8* [[T4]], i8* [[T5]], i32 5)
operator|*
name|fp
operator|=
name|f
expr_stmt|;
comment|// CHECK-NEXT: [[T0:%.*]] = load [[APS]]** [[FP]], align 4
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast [[APS]]* [[T0]] to i8*
comment|// CHECK-NEXT: [[T2:%.*]] = bitcast [[APS]]* [[TMP3]] to i8*
comment|// CHECK-NEXT: call arm_aapcscc void @__atomic_load(i32 8, i8* [[T1]], i8* [[T2]], i32 5)
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[APS]]* [[TMP3]], i32 0, i32 0
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast %struct.PS* [[TMP2]] to i8*
comment|// CHECK-NEXT: [[T2:%.*]] = bitcast %struct.PS* [[T0]] to i8*
comment|// CHECK-NEXT: call void @llvm.memcpy.p0i8.p0i8.i32(i8* [[T1]], i8* [[T2]], i32 6, i32 2, i1 false)
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds %struct.PS* [[TMP2]], i32 0, i32 0
comment|// CHECK-NEXT: [[T1:%.*]] = load i16* [[T0]], align 2
comment|// CHECK-NEXT: [[T2:%.*]] = sext i16 [[T1]] to i32
comment|// CHECK-NEXT: store i32 [[T2]], i32* [[A]], align 4
name|int
name|a
init|=
operator|(
operator|(
name|PS
operator|)
operator|*
name|fp
operator|)
operator|.
name|x
decl_stmt|;
comment|// CHECK-NEXT: ret void
block|}
end_function

begin_comment
comment|// CHECK: define arm_aapcscc void @testPromotedStructOps([[APS:.*]]*
end_comment

begin_comment
comment|// FIXME: none of these look right, but we can leave the "test" here
end_comment

begin_comment
comment|// to make sure they at least don't crash.
end_comment

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

