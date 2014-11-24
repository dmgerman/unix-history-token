begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios7.0 -target-feature +neon -target-feature +crypto -ffreestanding -Os -S -o - %s | FileCheck %s
end_comment

begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|uint8x16_t
name|test_aese
parameter_list|(
name|uint8x16_t
name|data
parameter_list|,
name|uint8x16_t
name|key
parameter_list|)
block|{
comment|// CHECK-LABEL: test_aese:
comment|// CHECK: aese.16b v0, v1
return|return
name|vaeseq_u8
argument_list|(
name|data
argument_list|,
name|key
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8x16_t
name|test_aesd
parameter_list|(
name|uint8x16_t
name|data
parameter_list|,
name|uint8x16_t
name|key
parameter_list|)
block|{
comment|// CHECK-LABEL: test_aesd:
comment|// CHECK: aesd.16b v0, v1
return|return
name|vaesdq_u8
argument_list|(
name|data
argument_list|,
name|key
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8x16_t
name|test_aesmc
parameter_list|(
name|uint8x16_t
name|data
parameter_list|,
name|uint8x16_t
name|key
parameter_list|)
block|{
comment|// CHECK-LABEL: test_aesmc:
comment|// CHECK: aesmc.16b v0, v0
return|return
name|vaesmcq_u8
argument_list|(
name|data
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8x16_t
name|test_aesimc
parameter_list|(
name|uint8x16_t
name|data
parameter_list|,
name|uint8x16_t
name|key
parameter_list|)
block|{
comment|// CHECK-LABEL: test_aesimc:
comment|// CHECK: aesimc.16b v0, v0
return|return
name|vaesimcq_u8
argument_list|(
name|data
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x4_t
name|test_sha1c
parameter_list|(
name|uint32x4_t
name|hash_abcd
parameter_list|,
name|uint32_t
name|hash_e
parameter_list|,
name|uint32x4_t
name|wk
parameter_list|)
block|{
comment|// CHECK-LABEL: test_sha1c:
comment|// CHECK: fmov [[HASH_E:s[0-9]+]], w0
comment|// CHECK: sha1c.4s q0, [[HASH_E]], v1
return|return
name|vsha1cq_u32
argument_list|(
name|hash_abcd
argument_list|,
name|hash_e
argument_list|,
name|wk
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x4_t
name|test_sha1p
parameter_list|(
name|uint32x4_t
name|hash_abcd
parameter_list|,
name|uint32_t
name|hash_e
parameter_list|,
name|uint32x4_t
name|wk
parameter_list|)
block|{
comment|// CHECK-LABEL: test_sha1p:
comment|// CHECK: fmov [[HASH_E:s[0-9]+]], w0
comment|// CHECK: sha1p.4s q0, [[HASH_E]], v1
return|return
name|vsha1pq_u32
argument_list|(
name|hash_abcd
argument_list|,
name|hash_e
argument_list|,
name|wk
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x4_t
name|test_sha1m
parameter_list|(
name|uint32x4_t
name|hash_abcd
parameter_list|,
name|uint32_t
name|hash_e
parameter_list|,
name|uint32x4_t
name|wk
parameter_list|)
block|{
comment|// CHECK-LABEL: test_sha1m:
comment|// CHECK: fmov [[HASH_E:s[0-9]+]], w0
comment|// CHECK: sha1m.4s q0, [[HASH_E]], v1
return|return
name|vsha1mq_u32
argument_list|(
name|hash_abcd
argument_list|,
name|hash_e
argument_list|,
name|wk
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_sha1h
parameter_list|(
name|uint32_t
name|hash_e
parameter_list|)
block|{
comment|// CHECK-LABEL: test_sha1h:
comment|// CHECK: fmov [[HASH_E:s[0-9]+]], w0
comment|// CHECK: sha1h [[RES:s[0-9]+]], [[HASH_E]]
comment|// CHECK: fmov w0, [[RES]]
return|return
name|vsha1h_u32
argument_list|(
name|hash_e
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x4_t
name|test_sha1su0
parameter_list|(
name|uint32x4_t
name|wk0_3
parameter_list|,
name|uint32x4_t
name|wk4_7
parameter_list|,
name|uint32x4_t
name|wk8_11
parameter_list|)
block|{
comment|// CHECK-LABEL: test_sha1su0:
comment|// CHECK: sha1su0.4s v0, v1, v2
return|return
name|vsha1su0q_u32
argument_list|(
name|wk0_3
argument_list|,
name|wk4_7
argument_list|,
name|wk8_11
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x4_t
name|test_sha1su1
parameter_list|(
name|uint32x4_t
name|wk0_3
parameter_list|,
name|uint32x4_t
name|wk12_15
parameter_list|)
block|{
comment|// CHECK-LABEL: test_sha1su1:
comment|// CHECK: sha1su1.4s v0, v1
return|return
name|vsha1su1q_u32
argument_list|(
name|wk0_3
argument_list|,
name|wk12_15
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x4_t
name|test_sha256h
parameter_list|(
name|uint32x4_t
name|hash_abcd
parameter_list|,
name|uint32x4_t
name|hash_efgh
parameter_list|,
name|uint32x4_t
name|wk
parameter_list|)
block|{
comment|// CHECK-LABEL: test_sha256h:
comment|// CHECK: sha256h.4s q0, q1, v2
return|return
name|vsha256hq_u32
argument_list|(
name|hash_abcd
argument_list|,
name|hash_efgh
argument_list|,
name|wk
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x4_t
name|test_sha256h2
parameter_list|(
name|uint32x4_t
name|hash_efgh
parameter_list|,
name|uint32x4_t
name|hash_abcd
parameter_list|,
name|uint32x4_t
name|wk
parameter_list|)
block|{
comment|// CHECK-LABEL: test_sha256h2:
comment|// CHECK: sha256h2.4s q0, q1, v2
return|return
name|vsha256h2q_u32
argument_list|(
name|hash_efgh
argument_list|,
name|hash_abcd
argument_list|,
name|wk
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x4_t
name|test_sha256su0
parameter_list|(
name|uint32x4_t
name|w0_3
parameter_list|,
name|uint32x4_t
name|w4_7
parameter_list|)
block|{
comment|// CHECK-LABEL: test_sha256su0:
comment|// CHECK: sha256su0.4s v0, v1
return|return
name|vsha256su0q_u32
argument_list|(
name|w0_3
argument_list|,
name|w4_7
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x4_t
name|test_sha256su1
parameter_list|(
name|uint32x4_t
name|w0_3
parameter_list|,
name|uint32x4_t
name|w8_11
parameter_list|,
name|uint32x4_t
name|w12_15
parameter_list|)
block|{
comment|// CHECK-LABEL: test_sha256su1:
comment|// CHECK: sha256su1.4s v0, v1, v2
return|return
name|vsha256su1q_u32
argument_list|(
name|w0_3
argument_list|,
name|w8_11
argument_list|,
name|w12_15
argument_list|)
return|;
block|}
end_function

end_unit

