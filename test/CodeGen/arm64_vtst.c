begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - -emit-llvm %s | FileCheck %s
end_comment

begin_comment
comment|// Test ARM64 SIMD comparison test intrinsics
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|uint64x2_t
name|test_vtstq_s64
parameter_list|(
name|int64x2_t
name|a1
parameter_list|,
name|int64x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vtstq_s64
return|return
name|vtstq_s64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK: [[COMMONBITS:%[A-Za-z0-9.]+]] = and<2 x i64> %a1, %a2
comment|// CHECK: [[MASK:%[A-Za-z0-9.]+]] = icmp ne<2 x i64> [[COMMONBITS]], zeroinitializer
comment|// CHECK: [[RES:%[A-Za-z0-9.]+]] = sext<2 x i1> [[MASK]] to<2 x i64>
comment|// CHECK: ret<2 x i64> [[RES]]
block|}
end_function

begin_function
name|uint64x2_t
name|test_vtstq_u64
parameter_list|(
name|uint64x2_t
name|a1
parameter_list|,
name|uint64x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vtstq_u64
return|return
name|vtstq_u64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK: [[COMMONBITS:%[A-Za-z0-9.]+]] = and<2 x i64> %a1, %a2
comment|// CHECK: [[MASK:%[A-Za-z0-9.]+]] = icmp ne<2 x i64> [[COMMONBITS]], zeroinitializer
comment|// CHECK: [[RES:%[A-Za-z0-9.]+]] = sext<2 x i1> [[MASK]] to<2 x i64>
comment|// CHECK: ret<2 x i64> [[RES]]
block|}
end_function

end_unit

