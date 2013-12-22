begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Wall -Werror -triple thumbv7-linux-gnueabi -fno-signed-char -O3 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Make sure the canonical use works before going into smaller details:
end_comment

begin_function
name|int
name|atomic_inc
parameter_list|(
name|int
modifier|*
name|addr
parameter_list|)
block|{
name|int
name|Failure
decl_stmt|,
name|OldVal
decl_stmt|;
do|do
block|{
name|OldVal
operator|=
name|__builtin_arm_ldrex
argument_list|(
name|addr
argument_list|)
expr_stmt|;
name|Failure
operator|=
name|__builtin_arm_strex
argument_list|(
name|OldVal
operator|+
literal|1
argument_list|,
name|addr
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|Failure
condition|)
do|;
return|return
name|OldVal
return|;
block|}
end_function

begin_comment
comment|// CHECK: @atomic_inc
end_comment

begin_comment
comment|// CHECK:   [[OLDVAL:%.*]] = tail call i32 @llvm.arm.ldrex.p0i32(i32* %addr)
end_comment

begin_comment
comment|// CHECK:   [[INC:%.*]] = add nsw i32 [[OLDVAL]], 1
end_comment

begin_comment
comment|// CHECK:   [[FAILURE:%.*]] = tail call i32 @llvm.arm.strex.p0i32(i32 [[INC]], i32* %addr)
end_comment

begin_comment
comment|// CHECK:   [[TST:%.*]] = icmp eq i32 [[FAILURE]], 0
end_comment

begin_comment
comment|// CHECK:   br i1 [[TST]], label {{%[a-zA-Z0-9.]+}}, label {{%[a-zA-Z0-9.]+}}
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
comment|// CHECK: @test_ldrex
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
comment|// CHECK: [[INTRES:%.*]] = tail call i32 @llvm.arm.ldrex.p0i8(i8* %addr)
comment|// CHECK: and i32 [[INTRES]], 255
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
comment|// CHECK: [[INTRES:%.*]] = tail call i32 @llvm.arm.ldrex.p0i16(i16* [[ADDR16]])
comment|// CHECK: [[TMPSEXT:%.*]] = shl i32 [[INTRES]], 16
comment|// CHECK: ashr exact i32 [[TMPSEXT]], 16
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
comment|// CHECK:  call i32 @llvm.arm.ldrex.p0i32(i32* [[ADDR32]])
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
comment|// CHECK: call { i32, i32 } @llvm.arm.ldrexd(i8* %addr)
name|sum
operator|+=
name|__builtin_arm_ldrex
argument_list|(
name|addr64
argument_list|)
expr_stmt|;
comment|// CHECK: [[ADDR64_AS8:%.*]] = bitcast i64* %addr64 to i8*
comment|// CHECK: call { i32, i32 } @llvm.arm.ldrexd(i8* [[ADDR64_AS8]])
name|sum
operator|+=
name|__builtin_arm_ldrex
argument_list|(
name|addrfloat
argument_list|)
expr_stmt|;
comment|// CHECK: [[INTADDR:%.*]] = bitcast float* %addrfloat to i32*
comment|// CHECK: [[INTRES:%.*]] = tail call i32 @llvm.arm.ldrex.p0i32(i32* [[INTADDR]])
comment|// CHECK: bitcast i32 [[INTRES]] to float
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
comment|// CHECK: [[STRUCTRES:%.*]] = tail call { i32, i32 } @llvm.arm.ldrexd(i8* %addr)
comment|// CHECK: [[RESHI:%.*]] = extractvalue { i32, i32 } [[STRUCTRES]], 1
comment|// CHECK: [[RESLO:%.*]] = extractvalue { i32, i32 } [[STRUCTRES]], 0
comment|// CHECK: [[RESHI64:%.*]] = zext i32 [[RESHI]] to i64
comment|// CHECK: [[RESLO64:%.*]] = zext i32 [[RESLO]] to i64
comment|// CHECK: [[RESHIHI:%.*]] = shl nuw i64 [[RESHI64]], 32
comment|// CHECK: [[INTRES:%.*]] = or i64 [[RESHIHI]], [[RESLO64]]
comment|// CHECK: bitcast i64 [[INTRES]] to double
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
comment|// CHECK: [[INTRES:%.*]] = tail call i32 @llvm.arm.ldrex.p0i32(i32* [[ADDR32]])
comment|// CHECK: inttoptr i32 [[INTRES]] to i32*
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
comment|// CHECK: [[INTRES:%.*]] = tail call i32 @llvm.arm.ldrex.p0i32(i32* [[ADDR32]])
comment|// CHECK: inttoptr i32 [[INTRES]] to %struct.Simple*
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
comment|// CHECK: @test_strex
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
comment|// CHECK: call i32 @llvm.arm.strexd(i32 42, i32 0, i8* %addr)
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
comment|// CHECK: call i32 @llvm.arm.strex.p0i32(i32 1076754509, i32* [[ADDR32]])
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
comment|// CHECK: call i32 @llvm.arm.strexd(i32 -266631570, i32 1074340345, i8* %addr)
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
comment|// CHECK: [[INTVAL:%.*]] = ptrtoint i16* %var to i32
comment|// CHECK: call i32 @llvm.arm.strex.p0i32(i32 [[INTVAL]], i32* [[ADDR32]])
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
comment|// CHECK: @test_clrex
name|__builtin_arm_clrex
argument_list|()
expr_stmt|;
comment|// CHECK: call void @llvm.arm.clrex()
block|}
end_function

end_unit

