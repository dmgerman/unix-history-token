begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios7.0 -target-feature +neon  \
end_comment

begin_comment
comment|// RUN:   -S -O1 -o - -ffreestanding %s | FileCheck %s
end_comment

begin_comment
comment|// We're explicitly using arm_neon.h here: some types probably don't match
end_comment

begin_comment
comment|// the ACLE definitions, but we want to check current codegen.
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|float
name|test_vrsqrtss_f32
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{
comment|// CHECK: test_vrsqrtss_f32
return|return
name|vrsqrtss_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: frsqrts {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_function
name|double
name|test_vrsqrtsd_f64
parameter_list|(
name|double
name|a
parameter_list|,
name|double
name|b
parameter_list|)
block|{
comment|// CHECK: test_vrsqrtsd_f64
return|return
name|vrsqrtsd_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: frsqrts {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|int64x1_t
name|test_vrshl_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK: test_vrshl_s64
return|return
name|vrshl_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: srshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint64x1_t
name|test_vrshl_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK: test_vrshl_u64
return|return
name|vrshl_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: urshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vrshld_s64
end_comment

begin_function
name|int64_t
name|test_vrshld_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
return|return
name|vrshld_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: srshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vrshld_u64
end_comment

begin_function
name|uint64_t
name|test_vrshld_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
return|return
name|vrshld_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: urshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqrshlb_s8
end_comment

begin_function
name|int8_t
name|test_vqrshlb_s8
parameter_list|(
name|int8_t
name|a
parameter_list|,
name|int8_t
name|b
parameter_list|)
block|{
return|return
name|vqrshlb_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrshl.8b {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqrshlh_s16
end_comment

begin_function
name|int16_t
name|test_vqrshlh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vqrshlh_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrshl.4h {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqrshls_s32
end_comment

begin_function
name|int32_t
name|test_vqrshls_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vqrshls_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrshl {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqrshld_s64
end_comment

begin_function
name|int64_t
name|test_vqrshld_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
return|return
name|vqrshld_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqrshlb_u8
end_comment

begin_function
name|uint8_t
name|test_vqrshlb_u8
parameter_list|(
name|uint8_t
name|a
parameter_list|,
name|uint8_t
name|b
parameter_list|)
block|{
return|return
name|vqrshlb_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqrshl.8b {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqrshlh_u16
end_comment

begin_function
name|uint16_t
name|test_vqrshlh_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
return|return
name|vqrshlh_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqrshl.4h {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqrshls_u32
end_comment

begin_function
name|uint32_t
name|test_vqrshls_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
return|return
name|vqrshls_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqrshl {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqrshld_u64
end_comment

begin_function
name|uint64_t
name|test_vqrshld_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
return|return
name|vqrshld_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqrshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqshlb_s8
end_comment

begin_function
name|int8_t
name|test_vqshlb_s8
parameter_list|(
name|int8_t
name|a
parameter_list|,
name|int8_t
name|b
parameter_list|)
block|{
return|return
name|vqshlb_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqshl.8b {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqshlh_s16
end_comment

begin_function
name|int16_t
name|test_vqshlh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vqshlh_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqshl.4h {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqshls_s32
end_comment

begin_function
name|int32_t
name|test_vqshls_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vqshls_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqshl {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqshld_s64
end_comment

begin_function
name|int64_t
name|test_vqshld_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
return|return
name|vqshld_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqshld_s64_i
end_comment

begin_function
name|int64_t
name|test_vqshld_s64_i
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
return|return
name|vqshld_s64
argument_list|(
name|a
argument_list|,
literal|36
argument_list|)
return|;
comment|// CHECK: sqshl {{d[0-9]+}}, {{d[0-9]+}}, #36
block|}
end_function

begin_comment
comment|// CHECK: test_vqshlb_u8
end_comment

begin_function
name|uint8_t
name|test_vqshlb_u8
parameter_list|(
name|uint8_t
name|a
parameter_list|,
name|uint8_t
name|b
parameter_list|)
block|{
return|return
name|vqshlb_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqshl.8b {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqshlh_u16
end_comment

begin_function
name|uint16_t
name|test_vqshlh_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
return|return
name|vqshlh_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqshl.4h {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqshls_u32
end_comment

begin_function
name|uint32_t
name|test_vqshls_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
return|return
name|vqshls_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqshl {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqshld_u64
end_comment

begin_function
name|uint64_t
name|test_vqshld_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
return|return
name|vqshld_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqshld_u64_i
end_comment

begin_function
name|uint64_t
name|test_vqshld_u64_i
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
return|return
name|vqshld_u64
argument_list|(
name|a
argument_list|,
literal|36
argument_list|)
return|;
comment|// CHECK: uqshl {{d[0-9]+}}, {{d[0-9]+}}, #36
block|}
end_function

begin_comment
comment|// CHECK: test_vshld_u64
end_comment

begin_function
name|uint64_t
name|test_vshld_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
return|return
name|vshld_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ushl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vshld_s64
end_comment

begin_function
name|int64_t
name|test_vshld_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
return|return
name|vshld_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqdmullh_s16
end_comment

begin_function
name|int32_t
name|test_vqdmullh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vqdmullh_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqdmull.4s {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqdmulls_s32
end_comment

begin_function
name|int64_t
name|test_vqdmulls_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulls_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqdmull {{d[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqaddb_s8
end_comment

begin_function
name|int8_t
name|test_vqaddb_s8
parameter_list|(
name|int8_t
name|a
parameter_list|,
name|int8_t
name|b
parameter_list|)
block|{
return|return
name|vqaddb_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqadd.8b {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqaddh_s16
end_comment

begin_function
name|int16_t
name|test_vqaddh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vqaddh_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqadd.4h {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqadds_s32
end_comment

begin_function
name|int32_t
name|test_vqadds_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vqadds_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqadd {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqaddd_s64
end_comment

begin_function
name|int64_t
name|test_vqaddd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
return|return
name|vqaddd_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqadd {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqaddb_u8
end_comment

begin_function
name|uint8_t
name|test_vqaddb_u8
parameter_list|(
name|uint8_t
name|a
parameter_list|,
name|uint8_t
name|b
parameter_list|)
block|{
return|return
name|vqaddb_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqadd.8b {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqaddh_u16
end_comment

begin_function
name|uint16_t
name|test_vqaddh_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
return|return
name|vqaddh_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqadd.4h {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqadds_u32
end_comment

begin_function
name|uint32_t
name|test_vqadds_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
return|return
name|vqadds_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqadd {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqaddd_u64
end_comment

begin_function
name|uint64_t
name|test_vqaddd_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
return|return
name|vqaddd_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqadd {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqsubb_s8
end_comment

begin_function
name|int8_t
name|test_vqsubb_s8
parameter_list|(
name|int8_t
name|a
parameter_list|,
name|int8_t
name|b
parameter_list|)
block|{
return|return
name|vqsubb_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqsub.8b {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqsubh_s16
end_comment

begin_function
name|int16_t
name|test_vqsubh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vqsubh_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqsub.4h {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqsubs_s32
end_comment

begin_function
name|int32_t
name|test_vqsubs_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vqsubs_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqsub {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqsubd_s64
end_comment

begin_function
name|int64_t
name|test_vqsubd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
return|return
name|vqsubd_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqsub {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqsubb_u8
end_comment

begin_function
name|uint8_t
name|test_vqsubb_u8
parameter_list|(
name|uint8_t
name|a
parameter_list|,
name|uint8_t
name|b
parameter_list|)
block|{
return|return
name|vqsubb_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqsub.8b {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqsubh_u16
end_comment

begin_function
name|uint16_t
name|test_vqsubh_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
return|return
name|vqsubh_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqsub.4h {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqsubs_u32
end_comment

begin_function
name|uint32_t
name|test_vqsubs_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
return|return
name|vqsubs_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqsub {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqsubd_u64
end_comment

begin_function
name|uint64_t
name|test_vqsubd_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
return|return
name|vqsubd_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqsub {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqmovnh_s16
end_comment

begin_function
name|int8_t
name|test_vqmovnh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|)
block|{
return|return
name|vqmovnh_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqxtn.8b {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqmovnh_u16
end_comment

begin_function
name|uint8_t
name|test_vqmovnh_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|)
block|{
return|return
name|vqmovnh_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uqxtn.8b {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqmovns_s32
end_comment

begin_function
name|int16_t
name|test_vqmovns_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
return|return
name|vqmovns_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqxtn.4h {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqmovns_u32
end_comment

begin_function
name|uint16_t
name|test_vqmovns_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|)
block|{
return|return
name|vqmovns_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uqxtn.4h {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqmovnd_s64
end_comment

begin_function
name|int32_t
name|test_vqmovnd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
return|return
name|vqmovnd_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqxtn {{s[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqmovnd_u64
end_comment

begin_function
name|uint32_t
name|test_vqmovnd_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
return|return
name|vqmovnd_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uqxtn {{s[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqmovunh_s16
end_comment

begin_function
name|int8_t
name|test_vqmovunh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|)
block|{
return|return
name|vqmovunh_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqxtun.8b {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqmovuns_s32
end_comment

begin_function
name|int16_t
name|test_vqmovuns_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
return|return
name|vqmovuns_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqxtun.4h {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqmovund_s64
end_comment

begin_function
name|int32_t
name|test_vqmovund_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
return|return
name|vqmovund_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqxtun {{s[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqabsb_s8
end_comment

begin_function
name|int8_t
name|test_vqabsb_s8
parameter_list|(
name|int8_t
name|a
parameter_list|)
block|{
return|return
name|vqabsb_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqabs.8b {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqabsh_s16
end_comment

begin_function
name|int16_t
name|test_vqabsh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|)
block|{
return|return
name|vqabsh_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqabs.4h {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqabss_s32
end_comment

begin_function
name|int32_t
name|test_vqabss_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
return|return
name|vqabss_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqabs {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqabsd_s64
end_comment

begin_function
name|int64_t
name|test_vqabsd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
return|return
name|vqabsd_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqabs {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqnegb_s8
end_comment

begin_function
name|int8_t
name|test_vqnegb_s8
parameter_list|(
name|int8_t
name|a
parameter_list|)
block|{
return|return
name|vqnegb_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqneg.8b {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqnegh_s16
end_comment

begin_function
name|int16_t
name|test_vqnegh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|)
block|{
return|return
name|vqnegh_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqneg.4h {{v[0-9]+}}, {{v[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqnegs_s32
end_comment

begin_function
name|int32_t
name|test_vqnegs_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
return|return
name|vqnegs_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqneg {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vqnegd_s64
end_comment

begin_function
name|int64_t
name|test_vqnegd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
return|return
name|vqnegd_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqneg {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vcvts_n_f32_s32
end_comment

begin_function
name|float32_t
name|test_vcvts_n_f32_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
return|return
name|vcvts_n_f32_s32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: scvtf {{s[0-9]+}}, {{s[0-9]+}}, #3
block|}
end_function

begin_comment
comment|// CHECK: test_vcvts_n_f32_u32
end_comment

begin_function
name|float32_t
name|test_vcvts_n_f32_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|)
block|{
return|return
name|vcvts_n_f32_u32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ucvtf {{s[0-9]+}}, {{s[0-9]+}}, #3
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtd_n_f64_s64
end_comment

begin_function
name|float64_t
name|test_vcvtd_n_f64_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
return|return
name|vcvtd_n_f64_s64
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: scvtf {{d[0-9]+}}, {{d[0-9]+}}, #3
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtd_n_f64_u64
end_comment

begin_function
name|float64_t
name|test_vcvtd_n_f64_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
return|return
name|vcvtd_n_f64_u64
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ucvtf {{d[0-9]+}}, {{d[0-9]+}}, #3
block|}
end_function

begin_comment
comment|// CHECK: test_vcvts_n_s32_f32
end_comment

begin_function
name|int32_t
name|test_vcvts_n_s32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
name|vcvts_n_s32_f32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: fcvtzs {{s[0-9]+}}, {{s[0-9]+}}, #3
block|}
end_function

begin_comment
comment|// CHECK: test_vcvts_n_u32_f32
end_comment

begin_function
name|uint32_t
name|test_vcvts_n_u32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
name|vcvts_n_u32_f32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: fcvtzu {{s[0-9]+}}, {{s[0-9]+}}, #3
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtd_n_s64_f64
end_comment

begin_function
name|int64_t
name|test_vcvtd_n_s64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
name|vcvtd_n_s64_f64
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: fcvtzs {{d[0-9]+}}, {{d[0-9]+}}, #3
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtd_n_u64_f64
end_comment

begin_function
name|uint64_t
name|test_vcvtd_n_u64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
name|vcvtd_n_u64_f64
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: fcvtzu {{d[0-9]+}}, {{d[0-9]+}}, #3
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtas_s32_f32
end_comment

begin_function
name|int32_t
name|test_vcvtas_s32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
name|vcvtas_s32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtas {{w[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtas_u32_f32
end_comment

begin_function
name|uint32_t
name|test_vcvtas_u32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
name|vcvtas_u32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtau {{w[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtad_s64_f64
end_comment

begin_function
name|int64_t
name|test_vcvtad_s64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
name|vcvtad_s64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtas {{x[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtad_u64_f64
end_comment

begin_function
name|uint64_t
name|test_vcvtad_u64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
name|vcvtad_u64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtau {{x[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtms_s32_f32
end_comment

begin_function
name|int32_t
name|test_vcvtms_s32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
name|vcvtms_s32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtms {{w[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtms_u32_f32
end_comment

begin_function
name|uint32_t
name|test_vcvtms_u32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
name|vcvtms_u32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtmu {{w[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtmd_s64_f64
end_comment

begin_function
name|int64_t
name|test_vcvtmd_s64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
name|vcvtmd_s64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtms {{x[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtmd_u64_f64
end_comment

begin_function
name|uint64_t
name|test_vcvtmd_u64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
name|vcvtmd_u64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtmu {{x[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtns_s32_f32
end_comment

begin_function
name|int32_t
name|test_vcvtns_s32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
name|vcvtns_s32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtns {{w[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtns_u32_f32
end_comment

begin_function
name|uint32_t
name|test_vcvtns_u32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
name|vcvtns_u32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtnu {{w[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtnd_s64_f64
end_comment

begin_function
name|int64_t
name|test_vcvtnd_s64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
name|vcvtnd_s64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtns {{x[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtnd_u64_f64
end_comment

begin_function
name|uint64_t
name|test_vcvtnd_u64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
name|vcvtnd_u64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtnu {{x[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtps_s32_f32
end_comment

begin_function
name|int32_t
name|test_vcvtps_s32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
name|vcvtps_s32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtps {{w[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtps_u32_f32
end_comment

begin_function
name|uint32_t
name|test_vcvtps_u32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
name|vcvtps_u32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtpu {{w[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtpd_s64_f64
end_comment

begin_function
name|int64_t
name|test_vcvtpd_s64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
name|vcvtpd_s64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtps {{x[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtpd_u64_f64
end_comment

begin_function
name|uint64_t
name|test_vcvtpd_u64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
name|vcvtpd_u64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtpu {{x[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vcvtxd_f32_f64
end_comment

begin_function
name|float32_t
name|test_vcvtxd_f32_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
name|vcvtxd_f32_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtxn {{s[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vabds_f32
end_comment

begin_function
name|float32_t
name|test_vabds_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
return|return
name|vabds_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fabd {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vabdd_f64
end_comment

begin_function
name|float64_t
name|test_vabdd_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|)
block|{
return|return
name|vabdd_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fabd {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vmulxs_f32
end_comment

begin_function
name|float32_t
name|test_vmulxs_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
return|return
name|vmulxs_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmulx {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vmulxd_f64
end_comment

begin_function
name|float64_t
name|test_vmulxd_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|)
block|{
return|return
name|vmulxd_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmulx {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

end_unit

