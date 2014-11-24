begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O3 -triple arm64-apple-ios7 -target-feature +neon -S -ffreestanding %s -o - -target-cpu cyclone | FileCheck %s
end_comment

begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// test code generation for<rdar://problem/11487757>
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function_decl
name|unsigned
name|bar
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Branch if any lane of V0 is zero; 64 bit => !min
end_comment

begin_function
name|unsigned
name|anyZero64
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK: anyZero64:
comment|// CHECK: uminv.8b b[[REGNO1:[0-9]+]], v0
comment|// CHECK-NEXT: fmov w[[REGNO2:[0-9]+]], s[[REGNO1]]
comment|// CHECK-NEXT: cbz w[[REGNO2]], [[LABEL:[.A-Z_0-9]+]]
comment|// CHECK: [[LABEL]]:
comment|// CHECK-NEXT: b {{_bar|bar}}
if|if
condition|(
operator|!
name|vminv_u8
argument_list|(
name|a
argument_list|)
condition|)
return|return
name|bar
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// Branch if any lane of V0 is zero; 128 bit => !min
end_comment

begin_function
name|unsigned
name|anyZero128
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK: anyZero128:
comment|// CHECK: uminv.16b b[[REGNO1:[0-9]+]], v0
comment|// CHECK-NEXT: fmov w[[REGNO2:[0-9]+]], s[[REGNO1]]
comment|// CHECK-NEXT: cbz w[[REGNO2]], [[LABEL:[.A-Z_0-9]+]]
comment|// CHECK: [[LABEL]]:
comment|// CHECK-NEXT: b {{_bar|bar}}
if|if
condition|(
operator|!
name|vminvq_u8
argument_list|(
name|a
argument_list|)
condition|)
return|return
name|bar
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// Branch if any lane of V0 is non-zero; 64 bit => max
end_comment

begin_function
name|unsigned
name|anyNonZero64
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK: anyNonZero64:
comment|// CHECK: umaxv.8b b[[REGNO1:[0-9]+]], v0
comment|// CHECK-NEXT: fmov w[[REGNO2:[0-9]+]], s[[REGNO1]]
comment|// CHECK-NEXT: cbz w[[REGNO2]], [[LABEL:[.A-Z_0-9]+]]
comment|// CHECK: [[LABEL]]:
comment|// CHECK-NEXT: movz w0, #0
if|if
condition|(
name|vmaxv_u8
argument_list|(
name|a
argument_list|)
condition|)
return|return
name|bar
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// Branch if any lane of V0 is non-zero; 128 bit => max
end_comment

begin_function
name|unsigned
name|anyNonZero128
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK: anyNonZero128:
comment|// CHECK: umaxv.16b b[[REGNO1:[0-9]+]], v0
comment|// CHECK-NEXT: fmov w[[REGNO2:[0-9]+]], s[[REGNO1]]
comment|// CHECK-NEXT: cbz w[[REGNO2]], [[LABEL:[.A-Z_0-9]+]]
comment|// CHECK: [[LABEL]]:
comment|// CHECK-NEXT: movz w0, #0
if|if
condition|(
name|vmaxvq_u8
argument_list|(
name|a
argument_list|)
condition|)
return|return
name|bar
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// Branch if all lanes of V0 are zero; 64 bit => !max
end_comment

begin_function
name|unsigned
name|allZero64
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK: allZero64:
comment|// CHECK: umaxv.8b b[[REGNO1:[0-9]+]], v0
comment|// CHECK-NEXT: fmov w[[REGNO2:[0-9]+]], s[[REGNO1]]
comment|// CHECK-NEXT: cbz w[[REGNO2]], [[LABEL:[.A-Z_0-9]+]]
comment|// CHECK: [[LABEL]]:
comment|// CHECK-NEXT: b {{_bar|bar}}
if|if
condition|(
operator|!
name|vmaxv_u8
argument_list|(
name|a
argument_list|)
condition|)
return|return
name|bar
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// Branch if all lanes of V0 are zero; 128 bit => !max
end_comment

begin_function
name|unsigned
name|allZero128
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK: allZero128:
comment|// CHECK: umaxv.16b b[[REGNO1:[0-9]+]], v0
comment|// CHECK-NEXT: fmov w[[REGNO2:[0-9]+]], s[[REGNO1]]
comment|// CHECK-NEXT: cbz w[[REGNO2]], [[LABEL:[.A-Z_0-9]+]]
comment|// CHECK: [[LABEL]]:
comment|// CHECK-NEXT: b {{_bar|bar}}
if|if
condition|(
operator|!
name|vmaxvq_u8
argument_list|(
name|a
argument_list|)
condition|)
return|return
name|bar
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// Branch if all lanes of V0 are non-zero; 64 bit => min
end_comment

begin_function
name|unsigned
name|allNonZero64
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK: allNonZero64:
comment|// CHECK: uminv.8b b[[REGNO1:[0-9]+]], v0
comment|// CHECK-NEXT: fmov w[[REGNO2:[0-9]+]], s[[REGNO1]]
comment|// CHECK-NEXT: cbz w[[REGNO2]], [[LABEL:[.A-Z_0-9]+]]
comment|// CHECK: [[LABEL]]:
comment|// CHECK-NEXT: movz w0, #0
if|if
condition|(
name|vminv_u8
argument_list|(
name|a
argument_list|)
condition|)
return|return
name|bar
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// Branch if all lanes of V0 are non-zero; 128 bit => min
end_comment

begin_function
name|unsigned
name|allNonZero128
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK: allNonZero128:
comment|// CHECK: uminv.16b b[[REGNO1:[0-9]+]], v0
comment|// CHECK-NEXT: fmov w[[REGNO2:[0-9]+]], s[[REGNO1]]
comment|// CHECK-NEXT: cbz w[[REGNO2]], [[LABEL:[.A-Z_0-9]+]]
comment|// CHECK: [[LABEL]]:
comment|// CHECK-NEXT: movz w0, #0
if|if
condition|(
name|vminvq_u8
argument_list|(
name|a
argument_list|)
condition|)
return|return
name|bar
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function

end_unit

