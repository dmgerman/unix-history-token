begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O3 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - %s | FileCheck %s
end_comment

begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|/// Test vqmov[u]n_high_<su>{16,32,64) ARM64 intrinsics
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// vqmovn_high_s16 -> UQXTN2 Vd.16b,Vn.8h
end_comment

begin_function
name|int8x16_t
name|test_vqmovn_high_s16
parameter_list|(
name|int8x8_t
name|Vdlow
parameter_list|,
name|int16x8_t
name|Vn
parameter_list|)
block|{
return|return
name|vqmovn_high_s16
argument_list|(
name|Vdlow
argument_list|,
name|Vn
argument_list|)
return|;
comment|// CHECK: test_vqmovn_high_s16:
comment|// CHECK: sqxtn2.16b {{v[0-9][0-9]*}}, {{v[0-9][0-9]*}}
block|}
end_function

begin_comment
comment|// vqmovun_high_s16 -> UQXTN2 Vd.16b,Vn.8h
end_comment

begin_function
name|uint8x16_t
name|test_vqmovun_high_s16
parameter_list|(
name|uint8x8_t
name|Vdlow
parameter_list|,
name|uint16x8_t
name|Vn
parameter_list|)
block|{
return|return
name|vqmovun_high_s16
argument_list|(
name|Vdlow
argument_list|,
name|Vn
argument_list|)
return|;
comment|// CHECK: test_vqmovun_high_s16:
comment|// CHECK: sqxtun2.16b {{v[0-9][0-9]*}}, {{v[0-9][0-9]*}}
block|}
end_function

begin_comment
comment|// vqmovn_high_s32 -> SQXTN2 Vd.8h,Vn.4s
end_comment

begin_function
name|int16x8_t
name|test_vqmovn_high_s32
parameter_list|(
name|int16x4_t
name|Vdlow
parameter_list|,
name|int32x4_t
name|Vn
parameter_list|)
block|{
return|return
name|vqmovn_high_s32
argument_list|(
name|Vdlow
argument_list|,
name|Vn
argument_list|)
return|;
comment|// CHECK: test_vqmovn_high_s32:
comment|// CHECK: sqxtn2.8h {{v[0-9][0-9]*}}, {{v[0-9][0-9]*}}
block|}
end_function

begin_comment
comment|// vqmovn_high_u32 -> UQXTN2 Vd.8h,Vn.4s
end_comment

begin_function
name|uint16x8_t
name|test_vqmovn_high_u32
parameter_list|(
name|uint16x4_t
name|Vdlow
parameter_list|,
name|uint32x4_t
name|Vn
parameter_list|)
block|{
return|return
name|vqmovn_high_u32
argument_list|(
name|Vdlow
argument_list|,
name|Vn
argument_list|)
return|;
comment|// CHECK: test_vqmovn_high_u32:
comment|// CHECK: uqxtn2.8h {{v[0-9][0-9]*}}, {{v[0-9][0-9]*}}
block|}
end_function

begin_comment
comment|// vqmovn_high_s64 -> SQXTN2 Vd.4s,Vn.2d
end_comment

begin_function
name|int32x4_t
name|test_vqmovn_high_s64
parameter_list|(
name|int32x2_t
name|Vdlow
parameter_list|,
name|int64x2_t
name|Vn
parameter_list|)
block|{
return|return
name|vqmovn_high_s64
argument_list|(
name|Vdlow
argument_list|,
name|Vn
argument_list|)
return|;
comment|// CHECK: test_vqmovn_high_s64:
comment|// CHECK: sqxtn2.4s {{v[0-9][0-9]*}}, {{v[0-9][0-9]*}}
block|}
end_function

begin_comment
comment|// vqmovn_high_u64 -> UQXTN2 Vd.4s,Vn.2d
end_comment

begin_function
name|uint32x4_t
name|test_vqmovn_high_u64
parameter_list|(
name|uint32x2_t
name|Vdlow
parameter_list|,
name|uint64x2_t
name|Vn
parameter_list|)
block|{
return|return
name|vqmovn_high_u64
argument_list|(
name|Vdlow
argument_list|,
name|Vn
argument_list|)
return|;
comment|// CHECK: test_vqmovn_high_u64:
comment|// CHECK: uqxtn2.4s {{v[0-9][0-9]*}}, {{v[0-9][0-9]*}}
block|}
end_function

begin_comment
comment|// vqmovn_high_u16 -> UQXTN2 Vd.16b,Vn.8h
end_comment

begin_function
name|uint8x16_t
name|test_vqmovn_high_u16
parameter_list|(
name|uint8x8_t
name|Vdlow
parameter_list|,
name|uint16x8_t
name|Vn
parameter_list|)
block|{
return|return
name|vqmovn_high_u16
argument_list|(
name|Vdlow
argument_list|,
name|Vn
argument_list|)
return|;
comment|// CHECK: test_vqmovn_high_u16:
comment|// CHECK: uqxtn2.16b {{v[0-9][0-9]*}}, {{v[0-9][0-9]*}}
block|}
end_function

begin_comment
comment|// vqmovun_high_s32 -> SQXTUN2 Vd.8h,Vn.4s
end_comment

begin_function
name|uint16x8_t
name|test_vqmovun_high_s32
parameter_list|(
name|uint16x4_t
name|Vdlow
parameter_list|,
name|uint32x4_t
name|Vn
parameter_list|)
block|{
return|return
name|vqmovun_high_s32
argument_list|(
name|Vdlow
argument_list|,
name|Vn
argument_list|)
return|;
comment|// CHECK: test_vqmovun_high_s32:
comment|// CHECK: sqxtun2.8h {{v[0-9][0-9]*}}, {{v[0-9][0-9]*}}
block|}
end_function

begin_comment
comment|// vqmovun_high_s64 -> SQXTUN2  Vd.4s,Vn.2d
end_comment

begin_function
name|uint32x4_t
name|test_vqmovun_high_s64
parameter_list|(
name|uint32x2_t
name|Vdlow
parameter_list|,
name|uint64x2_t
name|Vn
parameter_list|)
block|{
return|return
name|vqmovun_high_s64
argument_list|(
name|Vdlow
argument_list|,
name|Vn
argument_list|)
return|;
comment|// CHECK: test_vqmovun_high_s64:
comment|// CHECK: sqxtun2.4s {{v[0-9][0-9]*}}, {{v[0-9][0-9]*}}
block|}
end_function

end_unit

