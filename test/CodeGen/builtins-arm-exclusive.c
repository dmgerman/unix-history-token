begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Wall -Werror -triple thumbv8-linux-gnueabi -fno-signed-char -disable-O0-optnone -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Wall -Werror -triple arm64-apple-ios7.0 -disable-O0-optnone -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s --check-prefix=CHECK-ARM64
end_comment

begin_struct
struct|struct
name|Simple
block|{
name|char
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|test_ldrex
parameter_list|(
name|char
modifier|*
name|addr
parameter_list|,
name|long
name|long
modifier|*
name|addr64
parameter_list|,
name|float
modifier|*
name|addrfloat
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_ldrex
comment|// CHECK-ARM64-LABEL: @test_ldrex
name|int
name|sum
init|=
literal|0
decl_stmt|;
name|sum
operator|+=
name|__builtin_arm_ldrex
argument_list|(
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: [[INTRES:%.*]] = call i32 @llvm.arm.ldrex.p0i8(i8* %addr)
comment|// CHECK: trunc i32 [[INTRES]] to i8
comment|// CHECK-ARM64: [[INTRES:%.*]] = call i64 @llvm.aarch64.ldxr.p0i8(i8* %addr)
comment|// CHECK-ARM64: trunc i64 [[INTRES]] to i8
name|sum
operator|+=
name|__builtin_arm_ldrex
argument_list|(
operator|(
name|short
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: [[ADDR16:%.*]] = bitcast i8* %addr to i16*
comment|// CHECK: [[INTRES:%.*]] = call i32 @llvm.arm.ldrex.p0i16(i16* [[ADDR16]])
comment|// CHECK: trunc i32 [[INTRES]] to i16
comment|// CHECK-ARM64: [[ADDR16:%.*]] = bitcast i8* %addr to i16*
comment|// CHECK-ARM64: [[INTRES:%.*]] = call i64 @llvm.aarch64.ldxr.p0i16(i16* [[ADDR16]])
comment|// CHECK-ARM64: trunc i64 [[INTRES]] to i16
name|sum
operator|+=
name|__builtin_arm_ldrex
argument_list|(
operator|(
name|int
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: [[ADDR32:%.*]] = bitcast i8* %addr to i32*
comment|// CHECK: call i32 @llvm.arm.ldrex.p0i32(i32* [[ADDR32]])
comment|// CHECK-ARM64: [[ADDR32:%.*]] = bitcast i8* %addr to i32*
comment|// CHECK-ARM64: [[INTRES:%.*]] = call i64 @llvm.aarch64.ldxr.p0i32(i32* [[ADDR32]])
comment|// CHECK-ARM64: trunc i64 [[INTRES]] to i32
name|sum
operator|+=
name|__builtin_arm_ldrex
argument_list|(
operator|(
name|long
name|long
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: [[TMP4:%.*]] = bitcast i8* %addr to i64*
comment|// CHECK: [[TMP5:%.*]] = bitcast i64* [[TMP4]] to i8*
comment|// CHECK: call { i32, i32 } @llvm.arm.ldrexd(i8* [[TMP5]])
comment|// CHECK-ARM64: [[ADDR64:%.*]] = bitcast i8* %addr to i64*
comment|// CHECK-ARM64: call i64 @llvm.aarch64.ldxr.p0i64(i64* [[ADDR64]])
name|sum
operator|+=
name|__builtin_arm_ldrex
argument_list|(
name|addr64
argument_list|)
expr_stmt|;
comment|// CHECK: [[ADDR64_AS8:%.*]] = bitcast i64* %addr64 to i8*
comment|// CHECK: call { i32, i32 } @llvm.arm.ldrexd(i8* [[ADDR64_AS8]])
comment|// CHECK-ARM64: call i64 @llvm.aarch64.ldxr.p0i64(i64* %addr64)
name|sum
operator|+=
name|__builtin_arm_ldrex
argument_list|(
name|addrfloat
argument_list|)
expr_stmt|;
comment|// CHECK: [[INTADDR:%.*]] = bitcast float* %addrfloat to i32*
comment|// CHECK: [[INTRES:%.*]] = call i32 @llvm.arm.ldrex.p0i32(i32* [[INTADDR]])
comment|// CHECK: bitcast i32 [[INTRES]] to float
comment|// CHECK-ARM64: [[INTADDR:%.*]] = bitcast float* %addrfloat to i32*
comment|// CHECK-ARM64: [[INTRES:%.*]] = call i64 @llvm.aarch64.ldxr.p0i32(i32* [[INTADDR]])
comment|// CHECK-ARM64: [[TRUNCRES:%.*]] = trunc i64 [[INTRES]] to i32
comment|// CHECK-ARM64: bitcast i32 [[TRUNCRES]] to float
name|sum
operator|+=
name|__builtin_arm_ldrex
argument_list|(
operator|(
name|double
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: [[TMP4:%.*]] = bitcast i8* %addr to double*
comment|// CHECK: [[TMP5:%.*]] = bitcast double* [[TMP4]] to i8*
comment|// CHECK: [[STRUCTRES:%.*]] = call { i32, i32 } @llvm.arm.ldrexd(i8* [[TMP5]])
comment|// CHECK: [[RESHI:%.*]] = extractvalue { i32, i32 } [[STRUCTRES]], 1
comment|// CHECK: [[RESLO:%.*]] = extractvalue { i32, i32 } [[STRUCTRES]], 0
comment|// CHECK: [[RESHI64:%.*]] = zext i32 [[RESHI]] to i64
comment|// CHECK: [[RESLO64:%.*]] = zext i32 [[RESLO]] to i64
comment|// CHECK: [[RESHIHI:%.*]] = shl nuw i64 [[RESHI64]], 32
comment|// CHECK: [[INTRES:%.*]] = or i64 [[RESHIHI]], [[RESLO64]]
comment|// CHECK: bitcast i64 [[INTRES]] to double
comment|// CHECK-ARM64: [[TMP4:%.*]] = bitcast i8* %addr to double*
comment|// CHECK-ARM64: [[TMP5:%.*]] = bitcast double* [[TMP4]] to i64*
comment|// CHECK-ARM64: [[INTRES:%.*]] = call i64 @llvm.aarch64.ldxr.p0i64(i64* [[TMP5]])
comment|// CHECK-ARM64: bitcast i64 [[INTRES]] to double
name|sum
operator|+=
operator|*
name|__builtin_arm_ldrex
argument_list|(
operator|(
name|int
operator|*
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: [[TMP4:%.*]] = bitcast i8* %addr to i32**
comment|// CHECK: [[TMP5:%.*]] = bitcast i32** [[TMP4]] to i32*
comment|// CHECK: [[INTRES:%.*]] = call i32 @llvm.arm.ldrex.p0i32(i32* [[TMP5]])
comment|// CHECK: inttoptr i32 [[INTRES]] to i32*
comment|// CHECK-ARM64: [[TMP4:%.*]] = bitcast i8* %addr to i32**
comment|// CHECK-ARM64: [[TMP5:%.*]] = bitcast i32** [[TMP4]] to i64*
comment|// CHECK-ARM64: [[INTRES:%.*]] = call i64 @llvm.aarch64.ldxr.p0i64(i64* [[TMP5]])
comment|// CHECK-ARM64: inttoptr i64 [[INTRES]] to i32*
name|sum
operator|+=
name|__builtin_arm_ldrex
argument_list|(
operator|(
expr|struct
name|Simple
operator|*
operator|*
operator|)
name|addr
argument_list|)
operator|->
name|a
expr_stmt|;
comment|// CHECK: [[TMP4:%.*]] = bitcast i8* %addr to %struct.Simple**
comment|// CHECK: [[TMP5:%.*]] = bitcast %struct.Simple** [[TMP4]] to i32*
comment|// CHECK: [[INTRES:%.*]] = call i32 @llvm.arm.ldrex.p0i32(i32* [[TMP5]])
comment|// CHECK: inttoptr i32 [[INTRES]] to %struct.Simple*
comment|// CHECK-ARM64: [[TMP4:%.*]] = bitcast i8* %addr to %struct.Simple**
comment|// CHECK-ARM64: [[TMP5:%.*]] = bitcast %struct.Simple** [[TMP4]] to i64*
comment|// CHECK-ARM64: [[INTRES:%.*]] = call i64 @llvm.aarch64.ldxr.p0i64(i64* [[TMP5]])
comment|// CHECK-ARM64: inttoptr i64 [[INTRES]] to %struct.Simple*
return|return
name|sum
return|;
block|}
end_function

begin_function
name|int
name|test_ldaex
parameter_list|(
name|char
modifier|*
name|addr
parameter_list|,
name|long
name|long
modifier|*
name|addr64
parameter_list|,
name|float
modifier|*
name|addrfloat
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_ldaex
comment|// CHECK-ARM64-LABEL: @test_ldaex
name|int
name|sum
init|=
literal|0
decl_stmt|;
name|sum
operator|+=
name|__builtin_arm_ldaex
argument_list|(
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: [[INTRES:%.*]] = call i32 @llvm.arm.ldaex.p0i8(i8* %addr)
comment|// CHECK: trunc i32 [[INTRES]] to i8
comment|// CHECK-ARM64: [[INTRES:%.*]] = call i64 @llvm.aarch64.ldaxr.p0i8(i8* %addr)
comment|// CHECK-ARM64: trunc i64 [[INTRES]] to i8
name|sum
operator|+=
name|__builtin_arm_ldaex
argument_list|(
operator|(
name|short
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: [[ADDR16:%.*]] = bitcast i8* %addr to i16*
comment|// CHECK: [[INTRES:%.*]] = call i32 @llvm.arm.ldaex.p0i16(i16* [[ADDR16]])
comment|// CHECK: trunc i32 [[INTRES]] to i16
comment|// CHECK-ARM64: [[ADDR16:%.*]] = bitcast i8* %addr to i16*
comment|// CHECK-ARM64: [[INTRES:%.*]] = call i64 @llvm.aarch64.ldaxr.p0i16(i16* [[ADDR16]])
comment|// CHECK-ARM64: [[TRUNCRES:%.*]] = trunc i64 [[INTRES]] to i16
name|sum
operator|+=
name|__builtin_arm_ldaex
argument_list|(
operator|(
name|int
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: [[ADDR32:%.*]] = bitcast i8* %addr to i32*
comment|// CHECK:  call i32 @llvm.arm.ldaex.p0i32(i32* [[ADDR32]])
comment|// CHECK-ARM64: [[ADDR32:%.*]] = bitcast i8* %addr to i32*
comment|// CHECK-ARM64: [[INTRES:%.*]] = call i64 @llvm.aarch64.ldaxr.p0i32(i32* [[ADDR32]])
comment|// CHECK-ARM64: trunc i64 [[INTRES]] to i32
name|sum
operator|+=
name|__builtin_arm_ldaex
argument_list|(
operator|(
name|long
name|long
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: [[TMP4:%.*]] = bitcast i8* %addr to i64*
comment|// CHECK: [[TMP5:%.*]] = bitcast i64* [[TMP4]] to i8*
comment|// CHECK: call { i32, i32 } @llvm.arm.ldaexd(i8* [[TMP5]])
comment|// CHECK-ARM64: [[ADDR64:%.*]] = bitcast i8* %addr to i64*
comment|// CHECK-ARM64: call i64 @llvm.aarch64.ldaxr.p0i64(i64* [[ADDR64]])
name|sum
operator|+=
name|__builtin_arm_ldaex
argument_list|(
name|addr64
argument_list|)
expr_stmt|;
comment|// CHECK: [[ADDR64_AS8:%.*]] = bitcast i64* %addr64 to i8*
comment|// CHECK: call { i32, i32 } @llvm.arm.ldaexd(i8* [[ADDR64_AS8]])
comment|// CHECK-ARM64: call i64 @llvm.aarch64.ldaxr.p0i64(i64* %addr64)
name|sum
operator|+=
name|__builtin_arm_ldaex
argument_list|(
name|addrfloat
argument_list|)
expr_stmt|;
comment|// CHECK: [[INTADDR:%.*]] = bitcast float* %addrfloat to i32*
comment|// CHECK: [[INTRES:%.*]] = call i32 @llvm.arm.ldaex.p0i32(i32* [[INTADDR]])
comment|// CHECK: bitcast i32 [[INTRES]] to float
comment|// CHECK-ARM64: [[INTADDR:%.*]] = bitcast float* %addrfloat to i32*
comment|// CHECK-ARM64: [[INTRES:%.*]] = call i64 @llvm.aarch64.ldaxr.p0i32(i32* [[INTADDR]])
comment|// CHECK-ARM64: [[TRUNCRES:%.*]] = trunc i64 [[INTRES]] to i32
comment|// CHECK-ARM64: bitcast i32 [[TRUNCRES]] to float
name|sum
operator|+=
name|__builtin_arm_ldaex
argument_list|(
operator|(
name|double
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: [[TMP4:%.*]] = bitcast i8* %addr to double*
comment|// CHECK: [[TMP5:%.*]] = bitcast double* [[TMP4]] to i8*
comment|// CHECK: [[STRUCTRES:%.*]] = call { i32, i32 } @llvm.arm.ldaexd(i8* [[TMP5]])
comment|// CHECK: [[RESHI:%.*]] = extractvalue { i32, i32 } [[STRUCTRES]], 1
comment|// CHECK: [[RESLO:%.*]] = extractvalue { i32, i32 } [[STRUCTRES]], 0
comment|// CHECK: [[RESHI64:%.*]] = zext i32 [[RESHI]] to i64
comment|// CHECK: [[RESLO64:%.*]] = zext i32 [[RESLO]] to i64
comment|// CHECK: [[RESHIHI:%.*]] = shl nuw i64 [[RESHI64]], 32
comment|// CHECK: [[INTRES:%.*]] = or i64 [[RESHIHI]], [[RESLO64]]
comment|// CHECK: bitcast i64 [[INTRES]] to double
comment|// CHECK-ARM64: [[TMP4:%.*]] = bitcast i8* %addr to double*
comment|// CHECK-ARM64: [[TMP5:%.*]] = bitcast double* [[TMP4]] to i64*
comment|// CHECK-ARM64: [[INTRES:%.*]] = call i64 @llvm.aarch64.ldaxr.p0i64(i64* [[TMP5]])
comment|// CHECK-ARM64: bitcast i64 [[INTRES]] to double
name|sum
operator|+=
operator|*
name|__builtin_arm_ldaex
argument_list|(
operator|(
name|int
operator|*
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: [[TMP4:%.*]] = bitcast i8* %addr to i32**
comment|// CHECK: [[TMP5:%.*]] = bitcast i32** [[TMP4]] to i32*
comment|// CHECK: [[INTRES:%.*]] = call i32 @llvm.arm.ldaex.p0i32(i32* [[TMP5]])
comment|// CHECK: inttoptr i32 [[INTRES]] to i32*
comment|// CHECK-ARM64: [[TMP4:%.*]] = bitcast i8* %addr to i32**
comment|// CHECK-ARM64: [[TMP5:%.*]] = bitcast i32** [[TMP4]] to i64*
comment|// CHECK-ARM64: [[INTRES:%.*]] = call i64 @llvm.aarch64.ldaxr.p0i64(i64* [[TMP5]])
comment|// CHECK-ARM64: inttoptr i64 [[INTRES]] to i32*
name|sum
operator|+=
name|__builtin_arm_ldaex
argument_list|(
operator|(
expr|struct
name|Simple
operator|*
operator|*
operator|)
name|addr
argument_list|)
operator|->
name|a
expr_stmt|;
comment|// CHECK: [[TMP4:%.*]] = bitcast i8* %addr to %struct.Simple**
comment|// CHECK: [[TMP5:%.*]] = bitcast %struct.Simple** [[TMP4]] to i32*
comment|// CHECK: [[INTRES:%.*]] = call i32 @llvm.arm.ldaex.p0i32(i32* [[TMP5]])
comment|// CHECK: inttoptr i32 [[INTRES]] to %struct.Simple*
comment|// CHECK-ARM64: [[TMP4:%.*]] = bitcast i8* %addr to %struct.Simple**
comment|// CHECK-ARM64: [[TMP5:%.*]] = bitcast %struct.Simple** [[TMP4]] to i64*
comment|// CHECK-ARM64: [[INTRES:%.*]] = call i64 @llvm.aarch64.ldaxr.p0i64(i64* [[TMP5]])
comment|// CHECK-ARM64: inttoptr i64 [[INTRES]] to %struct.Simple*
return|return
name|sum
return|;
block|}
end_function

begin_function
name|int
name|test_strex
parameter_list|(
name|char
modifier|*
name|addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_strex
comment|// CHECK-ARM64-LABEL: @test_strex
name|int
name|res
init|=
literal|0
decl_stmt|;
name|struct
name|Simple
name|var
init|=
block|{
literal|0
block|}
decl_stmt|;
name|res
operator||=
name|__builtin_arm_strex
argument_list|(
literal|4
argument_list|,
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.arm.strex.p0i8(i32 4, i8* %addr)
comment|// CHECK-ARM64: call i32 @llvm.aarch64.stxr.p0i8(i64 4, i8* %addr)
name|res
operator||=
name|__builtin_arm_strex
argument_list|(
literal|42
argument_list|,
operator|(
name|short
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: [[ADDR16:%.*]] = bitcast i8* %addr to i16*
comment|// CHECK:  call i32 @llvm.arm.strex.p0i16(i32 42, i16* [[ADDR16]])
comment|// CHECK-ARM64: [[ADDR16:%.*]] = bitcast i8* %addr to i16*
comment|// CHECK-ARM64:  call i32 @llvm.aarch64.stxr.p0i16(i64 42, i16* [[ADDR16]])
name|res
operator||=
name|__builtin_arm_strex
argument_list|(
literal|42
argument_list|,
operator|(
name|int
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: [[ADDR32:%.*]] = bitcast i8* %addr to i32*
comment|// CHECK: call i32 @llvm.arm.strex.p0i32(i32 42, i32* [[ADDR32]])
comment|// CHECK-ARM64: [[ADDR32:%.*]] = bitcast i8* %addr to i32*
comment|// CHECK-ARM64: call i32 @llvm.aarch64.stxr.p0i32(i64 42, i32* [[ADDR32]])
name|res
operator||=
name|__builtin_arm_strex
argument_list|(
literal|42
argument_list|,
operator|(
name|long
name|long
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: store i64 42, i64* [[TMP:%.*]], align 8
comment|// CHECK: [[LOHI_ADDR:%.*]] = bitcast i64* [[TMP]] to { i32, i32 }*
comment|// CHECK: [[LOHI:%.*]] = load { i32, i32 }, { i32, i32 }* [[LOHI_ADDR]]
comment|// CHECK: [[LO:%.*]] = extractvalue { i32, i32 } [[LOHI]], 0
comment|// CHECK: [[HI:%.*]] = extractvalue { i32, i32 } [[LOHI]], 1
comment|// CHECK: [[TMP4:%.*]] = bitcast i8* %addr to i64*
comment|// CHECK: [[TMP5:%.*]] = bitcast i64* [[TMP4]] to i8*
comment|// CHECK: call i32 @llvm.arm.strexd(i32 [[LO]], i32 [[HI]], i8* [[TMP5]])
comment|// CHECK-ARM64: [[ADDR64:%.*]] = bitcast i8* %addr to i64*
comment|// CHECK-ARM64: call i32 @llvm.aarch64.stxr.p0i64(i64 42, i64* [[ADDR64]])
name|res
operator||=
name|__builtin_arm_strex
argument_list|(
literal|2.71828f
argument_list|,
operator|(
name|float
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: [[TMP4:%.*]] = bitcast i8* %addr to float*
comment|// CHECK: [[TMP5:%.*]] = bitcast float* [[TMP4]] to i32*
comment|// CHECK: call i32 @llvm.arm.strex.p0i32(i32 1076754509, i32* [[TMP5]])
comment|// CHECK-ARM64: [[TMP4:%.*]] = bitcast i8* %addr to float*
comment|// CHECK-ARM64: [[TMP5:%.*]] = bitcast float* [[TMP4]] to i32*
comment|// CHECK-ARM64: call i32 @llvm.aarch64.stxr.p0i32(i64 1076754509, i32* [[TMP5]])
name|res
operator||=
name|__builtin_arm_strex
argument_list|(
literal|3.14159
argument_list|,
operator|(
name|double
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: store double 3.141590e+00, double* [[TMP:%.*]], align 8
comment|// CHECK: [[LOHI_ADDR:%.*]] = bitcast double* [[TMP]] to { i32, i32 }*
comment|// CHECK: [[LOHI:%.*]] = load { i32, i32 }, { i32, i32 }* [[LOHI_ADDR]]
comment|// CHECK: [[LO:%.*]] = extractvalue { i32, i32 } [[LOHI]], 0
comment|// CHECK: [[HI:%.*]] = extractvalue { i32, i32 } [[LOHI]], 1
comment|// CHECK: [[TMP4:%.*]] = bitcast i8* %addr to double*
comment|// CHECK: [[TMP5:%.*]] = bitcast double* [[TMP4]] to i8*
comment|// CHECK: call i32 @llvm.arm.strexd(i32 [[LO]], i32 [[HI]], i8* [[TMP5]])
comment|// CHECK-ARM64: [[TMP4:%.*]] = bitcast i8* %addr to double*
comment|// CHECK-ARM64: [[TMP5:%.*]] = bitcast double* [[TMP4]] to i64*
comment|// CHECK-ARM64: call i32 @llvm.aarch64.stxr.p0i64(i64 4614256650576692846, i64* [[TMP5]])
name|res
operator||=
name|__builtin_arm_strex
argument_list|(
operator|&
name|var
argument_list|,
operator|(
expr|struct
name|Simple
operator|*
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: [[TMP4:%.*]] = bitcast i8* %addr to %struct.Simple**
comment|// CHECK: [[TMP5:%.*]] = bitcast %struct.Simple** [[TMP4]] to i32*
comment|// CHECK: [[INTVAL:%.*]] = ptrtoint %struct.Simple* %var to i32
comment|// CHECK: call i32 @llvm.arm.strex.p0i32(i32 [[INTVAL]], i32* [[TMP5]])
comment|// CHECK-ARM64: [[TMP4:%.*]] = bitcast i8* %addr to %struct.Simple**
comment|// CHECK-ARM64: [[TMP5:%.*]] = bitcast %struct.Simple** [[TMP4]] to i64*
comment|// CHECK-ARM64: [[INTVAL:%.*]] = ptrtoint %struct.Simple* %var to i64
comment|// CHECK-ARM64: call i32 @llvm.aarch64.stxr.p0i64(i64 [[INTVAL]], i64* [[TMP5]])
return|return
name|res
return|;
block|}
end_function

begin_function
name|int
name|test_stlex
parameter_list|(
name|char
modifier|*
name|addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_stlex
comment|// CHECK-ARM64-LABEL: @test_stlex
name|int
name|res
init|=
literal|0
decl_stmt|;
name|struct
name|Simple
name|var
init|=
block|{
literal|0
block|}
decl_stmt|;
name|res
operator||=
name|__builtin_arm_stlex
argument_list|(
literal|4
argument_list|,
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.arm.stlex.p0i8(i32 4, i8* %addr)
comment|// CHECK-ARM64: call i32 @llvm.aarch64.stlxr.p0i8(i64 4, i8* %addr)
name|res
operator||=
name|__builtin_arm_stlex
argument_list|(
literal|42
argument_list|,
operator|(
name|short
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: [[ADDR16:%.*]] = bitcast i8* %addr to i16*
comment|// CHECK:  call i32 @llvm.arm.stlex.p0i16(i32 42, i16* [[ADDR16]])
comment|// CHECK-ARM64: [[ADDR16:%.*]] = bitcast i8* %addr to i16*
comment|// CHECK-ARM64:  call i32 @llvm.aarch64.stlxr.p0i16(i64 42, i16* [[ADDR16]])
name|res
operator||=
name|__builtin_arm_stlex
argument_list|(
literal|42
argument_list|,
operator|(
name|int
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: [[ADDR32:%.*]] = bitcast i8* %addr to i32*
comment|// CHECK: call i32 @llvm.arm.stlex.p0i32(i32 42, i32* [[ADDR32]])
comment|// CHECK-ARM64: [[ADDR32:%.*]] = bitcast i8* %addr to i32*
comment|// CHECK-ARM64: call i32 @llvm.aarch64.stlxr.p0i32(i64 42, i32* [[ADDR32]])
name|res
operator||=
name|__builtin_arm_stlex
argument_list|(
literal|42
argument_list|,
operator|(
name|long
name|long
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: store i64 42, i64* [[TMP:%.*]], align 8
comment|// CHECK: [[LOHI_ADDR:%.*]] = bitcast i64* [[TMP]] to { i32, i32 }*
comment|// CHECK: [[LOHI:%.*]] = load { i32, i32 }, { i32, i32 }* [[LOHI_ADDR]]
comment|// CHECK: [[LO:%.*]] = extractvalue { i32, i32 } [[LOHI]], 0
comment|// CHECK: [[HI:%.*]] = extractvalue { i32, i32 } [[LOHI]], 1
comment|// CHECK: [[TMP4:%.*]] = bitcast i8* %addr to i64*
comment|// CHECK: [[TMP5:%.*]] = bitcast i64* [[TMP4]] to i8*
comment|// CHECK: call i32 @llvm.arm.stlexd(i32 [[LO]], i32 [[HI]], i8* [[TMP5]])
comment|// CHECK-ARM64: [[ADDR64:%.*]] = bitcast i8* %addr to i64*
comment|// CHECK-ARM64: call i32 @llvm.aarch64.stlxr.p0i64(i64 42, i64* [[ADDR64]])
name|res
operator||=
name|__builtin_arm_stlex
argument_list|(
literal|2.71828f
argument_list|,
operator|(
name|float
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: [[TMP4:%.*]] = bitcast i8* %addr to float*
comment|// CHECK: [[TMP5:%.*]] = bitcast float* [[TMP4]] to i32*
comment|// CHECK: call i32 @llvm.arm.stlex.p0i32(i32 1076754509, i32* [[TMP5]])
comment|// CHECK-ARM64: [[TMP4:%.*]] = bitcast i8* %addr to float*
comment|// CHECK-ARM64: [[TMP5:%.*]] = bitcast float* [[TMP4]] to i32*
comment|// CHECK-ARM64: call i32 @llvm.aarch64.stlxr.p0i32(i64 1076754509, i32* [[TMP5]])
name|res
operator||=
name|__builtin_arm_stlex
argument_list|(
literal|3.14159
argument_list|,
operator|(
name|double
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: store double 3.141590e+00, double* [[TMP:%.*]], align 8
comment|// CHECK: [[LOHI_ADDR:%.*]] = bitcast double* [[TMP]] to { i32, i32 }*
comment|// CHECK: [[LOHI:%.*]] = load { i32, i32 }, { i32, i32 }* [[LOHI_ADDR]]
comment|// CHECK: [[LO:%.*]] = extractvalue { i32, i32 } [[LOHI]], 0
comment|// CHECK: [[HI:%.*]] = extractvalue { i32, i32 } [[LOHI]], 1
comment|// CHECK: [[TMP4:%.*]] = bitcast i8* %addr to double*
comment|// CHECK: [[TMP5:%.*]] = bitcast double* [[TMP4]] to i8*
comment|// CHECK: call i32 @llvm.arm.stlexd(i32 [[LO]], i32 [[HI]], i8* [[TMP5]])
comment|// CHECK-ARM64: [[TMP4:%.*]] = bitcast i8* %addr to double*
comment|// CHECK-ARM64: [[TMP5:%.*]] = bitcast double* [[TMP4]] to i64*
comment|// CHECK-ARM64: call i32 @llvm.aarch64.stlxr.p0i64(i64 4614256650576692846, i64* [[TMP5]])
name|res
operator||=
name|__builtin_arm_stlex
argument_list|(
operator|&
name|var
argument_list|,
operator|(
expr|struct
name|Simple
operator|*
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
comment|// CHECK: [[TMP4:%.*]] = bitcast i8* %addr to %struct.Simple**
comment|// CHECK: [[TMP5:%.*]] = bitcast %struct.Simple** [[TMP4]] to i32*
comment|// CHECK: [[INTVAL:%.*]] = ptrtoint %struct.Simple* %var to i32
comment|// CHECK: call i32 @llvm.arm.stlex.p0i32(i32 [[INTVAL]], i32* [[TMP5]])
comment|// CHECK-ARM64: [[TMP4:%.*]] = bitcast i8* %addr to %struct.Simple**
comment|// CHECK-ARM64: [[TMP5:%.*]] = bitcast %struct.Simple** [[TMP4]] to i64*
comment|// CHECK-ARM64: [[INTVAL:%.*]] = ptrtoint %struct.Simple* %var to i64
comment|// CHECK-ARM64: call i32 @llvm.aarch64.stlxr.p0i64(i64 [[INTVAL]], i64* [[TMP5]])
return|return
name|res
return|;
block|}
end_function

begin_function
name|void
name|test_clrex
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_clrex
comment|// CHECK-ARM64-LABEL: @test_clrex
name|__builtin_arm_clrex
argument_list|()
expr_stmt|;
comment|// CHECK: call void @llvm.arm.clrex()
comment|// CHECK-ARM64: call void @llvm.aarch64.clrex()
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__aarch64__
end_ifdef

begin_comment
comment|// 128-bit tests
end_comment

begin_function
name|__int128
name|test_ldrex_128
parameter_list|(
name|__int128
modifier|*
name|addr
parameter_list|)
block|{
comment|// CHECK-ARM64-LABEL: @test_ldrex_128
return|return
name|__builtin_arm_ldrex
argument_list|(
name|addr
argument_list|)
return|;
comment|// CHECK-ARM64: [[ADDR8:%.*]] = bitcast i128* %addr to i8*
comment|// CHECK-ARM64: [[STRUCTRES:%.*]] = call { i64, i64 } @llvm.aarch64.ldxp(i8* [[ADDR8]])
comment|// CHECK-ARM64: [[RESHI:%.*]] = extractvalue { i64, i64 } [[STRUCTRES]], 1
comment|// CHECK-ARM64: [[RESLO:%.*]] = extractvalue { i64, i64 } [[STRUCTRES]], 0
comment|// CHECK-ARM64: [[RESHI64:%.*]] = zext i64 [[RESHI]] to i128
comment|// CHECK-ARM64: [[RESLO64:%.*]] = zext i64 [[RESLO]] to i128
comment|// CHECK-ARM64: [[RESHIHI:%.*]] = shl nuw i128 [[RESHI64]], 64
comment|// CHECK-ARM64: [[INTRES:%.*]] = or i128 [[RESHIHI]], [[RESLO64]]
comment|// CHECK-ARM64: ret i128 [[INTRES]]
block|}
end_function

begin_function
name|int
name|test_strex_128
parameter_list|(
name|__int128
modifier|*
name|addr
parameter_list|,
name|__int128
name|val
parameter_list|)
block|{
comment|// CHECK-ARM64-LABEL: @test_strex_128
return|return
name|__builtin_arm_strex
argument_list|(
name|val
argument_list|,
name|addr
argument_list|)
return|;
comment|// CHECK-ARM64: store i128 %val, i128* [[TMP:%.*]], align 16
comment|// CHECK-ARM64: [[LOHI_ADDR:%.*]] = bitcast i128* [[TMP]] to { i64, i64 }*
comment|// CHECK-ARM64: [[LOHI:%.*]] = load { i64, i64 }, { i64, i64 }* [[LOHI_ADDR]]
comment|// CHECK-ARM64: [[LO:%.*]] = extractvalue { i64, i64 } [[LOHI]], 0
comment|// CHECK-ARM64: [[HI:%.*]] = extractvalue { i64, i64 } [[LOHI]], 1
comment|// CHECK-ARM64: [[ADDR8:%.*]] = bitcast i128* %addr to i8*
comment|// CHECK-ARM64: call i32 @llvm.aarch64.stxp(i64 [[LO]], i64 [[HI]], i8* [[ADDR8]])
block|}
end_function

begin_function
name|__int128
name|test_ldaex_128
parameter_list|(
name|__int128
modifier|*
name|addr
parameter_list|)
block|{
comment|// CHECK-ARM64-LABEL: @test_ldaex_128
return|return
name|__builtin_arm_ldaex
argument_list|(
name|addr
argument_list|)
return|;
comment|// CHECK-ARM64: [[ADDR8:%.*]] = bitcast i128* %addr to i8*
comment|// CHECK-ARM64: [[STRUCTRES:%.*]] = call { i64, i64 } @llvm.aarch64.ldaxp(i8* [[ADDR8]])
comment|// CHECK-ARM64: [[RESHI:%.*]] = extractvalue { i64, i64 } [[STRUCTRES]], 1
comment|// CHECK-ARM64: [[RESLO:%.*]] = extractvalue { i64, i64 } [[STRUCTRES]], 0
comment|// CHECK-ARM64: [[RESHI64:%.*]] = zext i64 [[RESHI]] to i128
comment|// CHECK-ARM64: [[RESLO64:%.*]] = zext i64 [[RESLO]] to i128
comment|// CHECK-ARM64: [[RESHIHI:%.*]] = shl nuw i128 [[RESHI64]], 64
comment|// CHECK-ARM64: [[INTRES:%.*]] = or i128 [[RESHIHI]], [[RESLO64]]
comment|// CHECK-ARM64: ret i128 [[INTRES]]
block|}
end_function

begin_function
name|int
name|test_stlex_128
parameter_list|(
name|__int128
modifier|*
name|addr
parameter_list|,
name|__int128
name|val
parameter_list|)
block|{
comment|// CHECK-ARM64-LABEL: @test_stlex_128
return|return
name|__builtin_arm_stlex
argument_list|(
name|val
argument_list|,
name|addr
argument_list|)
return|;
comment|// CHECK-ARM64: store i128 %val, i128* [[TMP:%.*]], align 16
comment|// CHECK-ARM64: [[LOHI_ADDR:%.*]] = bitcast i128* [[TMP]] to { i64, i64 }*
comment|// CHECK-ARM64: [[LOHI:%.*]] = load { i64, i64 }, { i64, i64 }* [[LOHI_ADDR]]
comment|// CHECK-ARM64: [[LO:%.*]] = extractvalue { i64, i64 } [[LOHI]], 0
comment|// CHECK-ARM64: [[HI:%.*]] = extractvalue { i64, i64 } [[LOHI]], 1
comment|// CHECK-ARM64: [[ADDR8:%.*]] = bitcast i128* %addr to i8*
comment|// CHECK-ARM64: [[RES:%.*]] = call i32 @llvm.aarch64.stlxp(i64 [[LO]], i64 [[HI]], i8* [[ADDR8]])
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

