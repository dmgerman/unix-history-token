begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_poisoning.h ----------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is a part of AddressSanitizer, an address sanity checker.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Shadow memory poisoning by ASan RTL and by user application.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"asan_interceptors.h"
end_include

begin_include
include|#
directive|include
file|"asan_internal.h"
end_include

begin_include
include|#
directive|include
file|"asan_mapping.h"
end_include

begin_decl_stmt
name|namespace
name|__asan
block|{
comment|// Poisons the shadow memory for "size" bytes starting from "addr".
name|void
name|PoisonShadow
parameter_list|(
name|uptr
name|addr
parameter_list|,
name|uptr
name|size
parameter_list|,
name|u8
name|value
parameter_list|)
function_decl|;
comment|// Poisons the shadow memory for "redzone_size" bytes starting from
comment|// "addr + size".
name|void
name|PoisonShadowPartialRightRedzone
parameter_list|(
name|uptr
name|addr
parameter_list|,
name|uptr
name|size
parameter_list|,
name|uptr
name|redzone_size
parameter_list|,
name|u8
name|value
parameter_list|)
function_decl|;
comment|// Fast versions of PoisonShadow and PoisonShadowPartialRightRedzone that
comment|// assume that memory addresses are properly aligned. Use in
comment|// performance-critical code with care.
name|ALWAYS_INLINE
name|void
name|FastPoisonShadow
parameter_list|(
name|uptr
name|aligned_beg
parameter_list|,
name|uptr
name|aligned_size
parameter_list|,
name|u8
name|value
parameter_list|)
block|{
name|DCHECK
argument_list|(
name|flags
argument_list|()
operator|->
name|poison_heap
argument_list|)
expr_stmt|;
name|uptr
name|shadow_beg
init|=
name|MEM_TO_SHADOW
argument_list|(
name|aligned_beg
argument_list|)
decl_stmt|;
name|uptr
name|shadow_end
init|=
name|MEM_TO_SHADOW
argument_list|(
name|aligned_beg
operator|+
name|aligned_size
operator|-
name|SHADOW_GRANULARITY
argument_list|)
operator|+
literal|1
decl_stmt|;
name|REAL
argument_list|(
name|memset
argument_list|)
argument_list|(
operator|(
name|void
operator|*
operator|)
name|shadow_beg
argument_list|,
name|value
argument_list|,
name|shadow_end
operator|-
name|shadow_beg
argument_list|)
expr_stmt|;
block|}
name|ALWAYS_INLINE
name|void
name|FastPoisonShadowPartialRightRedzone
parameter_list|(
name|uptr
name|aligned_addr
parameter_list|,
name|uptr
name|size
parameter_list|,
name|uptr
name|redzone_size
parameter_list|,
name|u8
name|value
parameter_list|)
block|{
name|DCHECK
argument_list|(
name|flags
argument_list|()
operator|->
name|poison_heap
argument_list|)
expr_stmt|;
name|u8
modifier|*
name|shadow
init|=
operator|(
name|u8
operator|*
operator|)
name|MEM_TO_SHADOW
argument_list|(
name|aligned_addr
argument_list|)
decl_stmt|;
for|for
control|(
name|uptr
name|i
init|=
literal|0
init|;
name|i
operator|<
name|redzone_size
condition|;
name|i
operator|+=
name|SHADOW_GRANULARITY
operator|,
name|shadow
operator|++
control|)
block|{
if|if
condition|(
name|i
operator|+
name|SHADOW_GRANULARITY
operator|<=
name|size
condition|)
block|{
operator|*
name|shadow
operator|=
literal|0
expr_stmt|;
comment|// fully addressable
block|}
elseif|else
if|if
condition|(
name|i
operator|>=
name|size
condition|)
block|{
operator|*
name|shadow
operator|=
operator|(
name|SHADOW_GRANULARITY
operator|==
literal|128
operator|)
condition|?
literal|0xff
else|:
name|value
expr_stmt|;
comment|// unaddressable
block|}
else|else
block|{
operator|*
name|shadow
operator|=
name|size
operator|-
name|i
expr_stmt|;
comment|// first size-i bytes are addressable
block|}
block|}
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace __asan
end_comment

end_unit

