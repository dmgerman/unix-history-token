begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu \
end_comment

begin_comment
comment|// RUN:  -disable-O0-optnone -S -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s
end_comment

begin_function
name|int
name|crc32b
parameter_list|(
name|int
name|a
parameter_list|,
name|char
name|b
parameter_list|)
block|{
return|return
name|__builtin_arm_crc32b
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: [[T0:%[0-9]+]] = zext i8 %b to i32
comment|// CHECK: call i32 @llvm.aarch64.crc32b(i32 %a, i32 [[T0]])
block|}
end_function

begin_function
name|int
name|crc32cb
parameter_list|(
name|int
name|a
parameter_list|,
name|char
name|b
parameter_list|)
block|{
return|return
name|__builtin_arm_crc32cb
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: [[T0:%[0-9]+]] = zext i8 %b to i32
comment|// CHECK: call i32 @llvm.aarch64.crc32cb(i32 %a, i32 [[T0]])
block|}
end_function

begin_function
name|int
name|crc32h
parameter_list|(
name|int
name|a
parameter_list|,
name|short
name|b
parameter_list|)
block|{
return|return
name|__builtin_arm_crc32h
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: [[T0:%[0-9]+]] = zext i16 %b to i32
comment|// CHECK: call i32 @llvm.aarch64.crc32h(i32 %a, i32 [[T0]])
block|}
end_function

begin_function
name|int
name|crc32ch
parameter_list|(
name|int
name|a
parameter_list|,
name|short
name|b
parameter_list|)
block|{
return|return
name|__builtin_arm_crc32ch
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: [[T0:%[0-9]+]] = zext i16 %b to i32
comment|// CHECK: call i32 @llvm.aarch64.crc32ch(i32 %a, i32 [[T0]])
block|}
end_function

begin_function
name|int
name|crc32w
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
name|__builtin_arm_crc32w
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: call i32 @llvm.aarch64.crc32w(i32 %a, i32 %b)
block|}
end_function

begin_function
name|int
name|crc32cw
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
name|__builtin_arm_crc32cw
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: call i32 @llvm.aarch64.crc32cw(i32 %a, i32 %b)
block|}
end_function

begin_function
name|int
name|crc32d
parameter_list|(
name|int
name|a
parameter_list|,
name|long
name|b
parameter_list|)
block|{
return|return
name|__builtin_arm_crc32d
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: call i32 @llvm.aarch64.crc32x(i32 %a, i64 %b)
block|}
end_function

begin_function
name|int
name|crc32cd
parameter_list|(
name|int
name|a
parameter_list|,
name|long
name|b
parameter_list|)
block|{
return|return
name|__builtin_arm_crc32cd
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: call i32 @llvm.aarch64.crc32cx(i32 %a, i64 %b)
block|}
end_function

end_unit

