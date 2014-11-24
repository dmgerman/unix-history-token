begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - -emit-llvm %s | FileCheck %s
end_comment

begin_comment
comment|// Test ARM64 SIMD fused multiply add intrinsics
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|int64x2_t
name|test_vabsq_s64
parameter_list|(
name|int64x2_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vabsq_s64
return|return
name|vabsq_s64
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.abs.v2i64
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|int64_t
name|test_vceqd_s64
parameter_list|(
name|int64_t
name|a1
parameter_list|,
name|int64_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vceqd_s64
return|return
name|vceqd_s64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK: [[BIT:%[0-9a-zA-Z.]+]] = icmp eq i64 %a1, %a2
comment|// CHECK: sext i1 [[BIT]] to i64
block|}
end_function

begin_function
name|int64_t
name|test_vceqd_f64
parameter_list|(
name|float64_t
name|a1
parameter_list|,
name|float64_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vceqd_f64
return|return
name|vceqd_f64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK: [[BIT:%[0-9a-zA-Z.]+]] = fcmp oeq double %a1, %a2
comment|// CHECK: sext i1 [[BIT]] to i64
block|}
end_function

begin_function
name|uint64_t
name|test_vcgtd_u64
parameter_list|(
name|uint64_t
name|a1
parameter_list|,
name|uint64_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vcgtd_u64
return|return
name|vcgtd_u64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK: [[BIT:%[0-9a-zA-Z.]+]] = icmp ugt i64 %a1, %a2
comment|// CHECK: sext i1 [[BIT]] to i64
block|}
end_function

begin_function
name|uint64_t
name|test_vcled_u64
parameter_list|(
name|uint64_t
name|a1
parameter_list|,
name|uint64_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vcled_u64
return|return
name|vcled_u64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK: [[BIT:%[0-9a-zA-Z.]+]] = icmp ule i64 %a1, %a2
comment|// CHECK: sext i1 [[BIT]] to i64
block|}
end_function

begin_function
name|int64_t
name|test_vceqzd_s64
parameter_list|(
name|int64_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vceqzd_s64
return|return
name|vceqzd_s64
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: [[BIT:%[0-9a-zA-Z.]+]] = icmp eq i64 %a1, 0
comment|// CHECK: sext i1 [[BIT]] to i64
block|}
end_function

begin_function
name|uint64x2_t
name|test_vceqq_u64
parameter_list|(
name|uint64x2_t
name|a1
parameter_list|,
name|uint64x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vceqq_u64
return|return
name|vceqq_u64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK:  icmp eq<2 x i64> %a1, %a2
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcgeq_s64
parameter_list|(
name|int64x2_t
name|a1
parameter_list|,
name|int64x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vcgeq_s64
return|return
name|vcgeq_s64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK:  icmp sge<2 x i64> %a1, %a2
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcgeq_u64
parameter_list|(
name|uint64x2_t
name|a1
parameter_list|,
name|uint64x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vcgeq_u64
return|return
name|vcgeq_u64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK:  icmp uge<2 x i64> %a1, %a2
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcgtq_s64
parameter_list|(
name|int64x2_t
name|a1
parameter_list|,
name|int64x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vcgtq_s64
return|return
name|vcgtq_s64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK: icmp sgt<2 x i64> %a1, %a2
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcgtq_u64
parameter_list|(
name|uint64x2_t
name|a1
parameter_list|,
name|uint64x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vcgtq_u64
return|return
name|vcgtq_u64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK: icmp ugt<2 x i64> %a1, %a2
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcleq_s64
parameter_list|(
name|int64x2_t
name|a1
parameter_list|,
name|int64x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vcleq_s64
return|return
name|vcleq_s64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK: icmp sle<2 x i64> %a1, %a2
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcleq_u64
parameter_list|(
name|uint64x2_t
name|a1
parameter_list|,
name|uint64x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vcleq_u64
return|return
name|vcleq_u64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK: icmp ule<2 x i64> %a1, %a2
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcltq_s64
parameter_list|(
name|int64x2_t
name|a1
parameter_list|,
name|int64x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vcltq_s64
return|return
name|vcltq_s64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK: icmp slt<2 x i64> %a1, %a2
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcltq_u64
parameter_list|(
name|uint64x2_t
name|a1
parameter_list|,
name|uint64x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vcltq_u64
return|return
name|vcltq_u64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK: icmp ult<2 x i64> %a1, %a2
block|}
end_function

begin_function
name|int64x2_t
name|test_vqabsq_s64
parameter_list|(
name|int64x2_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vqabsq_s64
return|return
name|vqabsq_s64
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.sqabs.v2i64(<2 x i64> %a1)
comment|// CHECK-NEXT: ret
block|}
end_function

end_unit

