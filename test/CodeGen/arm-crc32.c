begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv8-none-linux-gnueabi \
end_comment

begin_comment
comment|// RUN:  -disable-O0-optnone -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s
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
comment|// CHECK: call i32 @llvm.arm.crc32b(i32 %a, i32 [[T0]])
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
comment|// CHECK: call i32 @llvm.arm.crc32cb(i32 %a, i32 [[T0]])
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
comment|// CHECK: call i32 @llvm.arm.crc32h(i32 %a, i32 [[T0]])
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
comment|// CHECK: call i32 @llvm.arm.crc32ch(i32 %a, i32 [[T0]])
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
comment|// CHECK: call i32 @llvm.arm.crc32w(i32 %a, i32 %b)
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
comment|// CHECK: call i32 @llvm.arm.crc32cw(i32 %a, i32 %b)
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
comment|// CHECK: [[T0:%[0-9]+]] = trunc i64 %b to i32
comment|// CHECK: [[T1:%[0-9]+]] = lshr i64 %b, 32
comment|// CHECK: [[T2:%[0-9]+]] = trunc i64 [[T1]] to i32
comment|// CHECK: [[T3:%[0-9]+]] = call i32 @llvm.arm.crc32w(i32 %a, i32 [[T0]])
comment|// CHECK: call i32 @llvm.arm.crc32w(i32 [[T3]], i32 [[T2]])
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
comment|// CHECK: [[T0:%[0-9]+]] = trunc i64 %b to i32
comment|// CHECK: [[T1:%[0-9]+]] = lshr i64 %b, 32
comment|// CHECK: [[T2:%[0-9]+]] = trunc i64 [[T1]] to i32
comment|// CHECK: [[T3:%[0-9]+]] = call i32 @llvm.arm.crc32cw(i32 %a, i32 [[T0]])
comment|// CHECK: call i32 @llvm.arm.crc32cw(i32 [[T3]], i32 [[T2]])
block|}
end_function

end_unit

