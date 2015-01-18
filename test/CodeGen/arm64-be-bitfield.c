begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN:  %clang_cc1 -triple aarch64_be-linux-gnu -ffreestanding -emit-llvm -O0 -o - %s | FileCheck --check-prefix IR %s
end_comment

begin_comment
comment|// RUN:  %clang_cc1 -triple aarch64_be-linux-gnu -ffreestanding -S -O1 -o - %s | FileCheck --check-prefix ARM %s
end_comment

begin_struct
struct|struct
name|bt3
block|{
name|signed
name|b2
range|:
literal|10
decl_stmt|;
name|signed
name|b3
range|:
literal|10
decl_stmt|;
block|}
name|b16
struct|;
end_struct

begin_comment
comment|// Get the high 32-bits and then shift appropriately for big-endian.
end_comment

begin_function
name|signed
name|callee_b0f
parameter_list|(
name|struct
name|bt3
name|bp11
parameter_list|)
block|{
comment|// IR: callee_b0f(i64 [[ARG:%.*]])
comment|// IR: store i64 [[ARG]], i64* [[PTR:%.*]]
comment|// IR: [[BITCAST:%.*]] = bitcast i64* [[PTR]] to i8*
comment|// IR: call void @llvm.memcpy.p0i8.p0i8.i64(i8* {{.*}}, i8* [[BITCAST]], i64 4
comment|// ARM: asr x0, x0, #54
return|return
name|bp11
operator|.
name|b2
return|;
block|}
end_function

end_unit

