begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +neon \
end_comment

begin_comment
comment|// RUN:   -target-feature +crypto -S -O3 -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +neon \
end_comment

begin_comment
comment|// RUN:   -S -O3 -o - %s 2>&1 | FileCheck --check-prefix=CHECK-NO-CRYPTO %s
end_comment

begin_comment
comment|// Test new aarch64 intrinsics and types
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|uint8x16_t
name|test_vaeseq_u8
parameter_list|(
name|uint8x16_t
name|data
parameter_list|,
name|uint8x16_t
name|key
parameter_list|)
block|{
comment|// CHECK: test_vaeseq_u8
comment|// CHECK-NO-CRYPTO: warning: implicit declaration of function 'vaeseq_u8' is invalid in C99
return|return
name|vaeseq_u8
argument_list|(
name|data
argument_list|,
name|key
argument_list|)
return|;
comment|// CHECK: aese {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vaesdq_u8
parameter_list|(
name|uint8x16_t
name|data
parameter_list|,
name|uint8x16_t
name|key
parameter_list|)
block|{
comment|// CHECK: test_vaesdq_u8
return|return
name|vaesdq_u8
argument_list|(
name|data
argument_list|,
name|key
argument_list|)
return|;
comment|// CHECK: aesd {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vaesmcq_u8
parameter_list|(
name|uint8x16_t
name|data
parameter_list|)
block|{
comment|// CHECK: test_vaesmcq_u8
return|return
name|vaesmcq_u8
argument_list|(
name|data
argument_list|)
return|;
comment|// CHECK: aesmc {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vaesimcq_u8
parameter_list|(
name|uint8x16_t
name|data
parameter_list|)
block|{
comment|// CHECK: test_vaesimcq_u8
return|return
name|vaesimcq_u8
argument_list|(
name|data
argument_list|)
return|;
comment|// CHECK: aesimc {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint32_t
name|test_vsha1h_u32
parameter_list|(
name|uint32_t
name|hash_e
parameter_list|)
block|{
comment|// CHECK: test_vsha1h_u32
return|return
name|vsha1h_u32
argument_list|(
name|hash_e
argument_list|)
return|;
comment|// CHECK: sha1h {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsha1su1q_u32
parameter_list|(
name|uint32x4_t
name|tw0_3
parameter_list|,
name|uint32x4_t
name|w12_15
parameter_list|)
block|{
comment|// CHECK: test_vsha1su1q_u32
return|return
name|vsha1su1q_u32
argument_list|(
name|tw0_3
argument_list|,
name|w12_15
argument_list|)
return|;
comment|// CHECK: sha1su1 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsha256su0q_u32
parameter_list|(
name|uint32x4_t
name|w0_3
parameter_list|,
name|uint32x4_t
name|w4_7
parameter_list|)
block|{
comment|// CHECK: test_vsha256su0q_u32
return|return
name|vsha256su0q_u32
argument_list|(
name|w0_3
argument_list|,
name|w4_7
argument_list|)
return|;
comment|// CHECK: sha256su0 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsha1cq_u32
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
comment|// CHECK: test_vsha1cq_u32
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
comment|// CHECK: sha1c {{q[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsha1pq_u32
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
comment|// CHECK: test_vsha1pq_u32
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
comment|// CHECK: sha1p {{q[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsha1mq_u32
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
comment|// CHECK: test_vsha1mq_u32
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
comment|// CHECK: sha1m {{q[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsha1su0q_u32
parameter_list|(
name|uint32x4_t
name|w0_3
parameter_list|,
name|uint32x4_t
name|w4_7
parameter_list|,
name|uint32x4_t
name|w8_11
parameter_list|)
block|{
comment|// CHECK: test_vsha1su0q_u32
return|return
name|vsha1su0q_u32
argument_list|(
name|w0_3
argument_list|,
name|w4_7
argument_list|,
name|w8_11
argument_list|)
return|;
comment|// CHECK: sha1su0 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsha256hq_u32
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
comment|// CHECK: test_vsha256hq_u32
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
comment|// CHECK: sha256h {{q[0-9]+}}, {{q[0-9]+}}, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsha256h2q_u32
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
comment|// CHECK: test_vsha256h2q_u32
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
comment|// CHECK: sha256h2 {{q[0-9]+}}, {{q[0-9]+}}, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsha256su1q_u32
parameter_list|(
name|uint32x4_t
name|tw0_3
parameter_list|,
name|uint32x4_t
name|w8_11
parameter_list|,
name|uint32x4_t
name|w12_15
parameter_list|)
block|{
comment|// CHECK: test_vsha256su1q_u32
return|return
name|vsha256su1q_u32
argument_list|(
name|tw0_3
argument_list|,
name|w8_11
argument_list|,
name|w12_15
argument_list|)
return|;
comment|// CHECK: sha256su1 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

end_unit

