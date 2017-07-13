begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -triple x86_64-unknown-unknown -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// PR33722
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -triple x86_64-unknown-unknown -D_MSC_VER -emit-llvm -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_function
name|int
name|test_bit_scan_forward
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|_bit_scan_forward
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: @test_bit_scan_forward
comment|// CHECK: %[[call:.*]] = call i32 @llvm.cttz.i32(
comment|// CHECK: ret i32 %[[call]]
block|}
end_function

begin_function
name|int
name|test_bit_scan_reverse
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|_bit_scan_reverse
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK:  %[[call:.*]] = call i32 @llvm.ctlz.i32(
comment|// CHECK:  %[[sub:.*]] = sub nsw i32 31, %[[call]]
comment|// CHECK: ret i32 %[[sub]]
block|}
end_function

end_unit

