begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -O1 -no-integrated-as \
end_comment

begin_comment
comment|// RUN:     -S -o - %s | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|long
name|long
name|int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|x86_reg
typedef|;
end_typedef

begin_function
name|void
name|avg_pixels8_mmx2
parameter_list|(
name|uint8_t
modifier|*
name|block
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|pixels
parameter_list|,
name|int
name|line_size
parameter_list|,
name|int
name|h
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|("# %0 %1 %2 %3"      :"+g"(h), "+S"(pixels), "+D"(block)      :"r" ((x86_reg)line_size)               :"%""rax", "memory");
comment|// CHECK: # %ecx %rsi %rdi %rdx
block|}
end_function

end_unit

