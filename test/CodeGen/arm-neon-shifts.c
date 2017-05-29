begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-apple-darwin \
end_comment

begin_comment
comment|// RUN:   -disable-O0-optnone \
end_comment

begin_comment
comment|// RUN:   -target-cpu cortex-a8 \
end_comment

begin_comment
comment|// RUN:   -ffreestanding \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -w -o - %s | opt -S -mem2reg | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|uint8x8_t
name|test_shift_vshr
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_shift_vshr
comment|// CHECK: %{{.*}} = lshr<8 x i8> %a,<i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5>
return|return
name|vshr_n_u8
argument_list|(
name|a
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|int8x8_t
name|test_shift_vshr_smax
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_shift_vshr_smax
comment|// CHECK: %{{.*}} = ashr<8 x i8> %a,<i8 7, i8 7, i8 7, i8 7, i8 7, i8 7, i8 7, i8 7>
return|return
name|vshr_n_s8
argument_list|(
name|a
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8x8_t
name|test_shift_vshr_umax
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_shift_vshr_umax
comment|// CHECK: ret<8 x i8> zeroinitializer
return|return
name|vshr_n_u8
argument_list|(
name|a
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8x8_t
name|test_shift_vsra
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_shift_vsra
comment|// CHECK: %[[SHR:.*]] = lshr<8 x i8> %b,<i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5>
comment|// CHECK: %{{.*}} = add<8 x i8> %a, %[[SHR]]
return|return
name|vsra_n_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|int8x8_t
name|test_shift_vsra_smax
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_shift_vsra_smax
comment|// CHECK: %[[SHR:.*]] = ashr<8 x i8> %b,<i8 7, i8 7, i8 7, i8 7, i8 7, i8 7, i8 7, i8 7>
comment|// CHECK: %{{.*}} = add<8 x i8> %a, %[[SHR]]
return|return
name|vsra_n_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8x8_t
name|test_shift_vsra_umax
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_shift_vsra_umax
comment|// CHECK: [[RES:%.*]] = add<8 x i8> %a, zeroinitializer
comment|// CHECK: ret<8 x i8> [[RES]]
return|return
name|vsra_n_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

end_unit

