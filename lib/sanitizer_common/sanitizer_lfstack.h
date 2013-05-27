begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_lfstack.h -=-----------------------------------*- C++ -*-===//
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
comment|// Lock-free stack.
end_comment

begin_comment
comment|// Uses 32/17 bits as ABA-counter on 32/64-bit platforms.
end_comment

begin_comment
comment|// The memory passed to Push() must not be ever munmap'ed.
end_comment

begin_comment
comment|// The type T must contain T *next field.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_LFSTACK_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_LFSTACK_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_atomic.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|LFStack
block|{
name|void
name|Clear
argument_list|()
block|{
name|atomic_store
argument_list|(
operator|&
name|head_
argument_list|,
literal|0
argument_list|,
name|memory_order_relaxed
argument_list|)
block|;   }
name|bool
name|Empty
argument_list|()
specifier|const
block|{
return|return
operator|(
name|atomic_load
argument_list|(
operator|&
name|head_
argument_list|,
name|memory_order_relaxed
argument_list|)
operator|&
name|kPtrMask
operator|)
operator|==
literal|0
return|;
block|}
name|void
name|Push
argument_list|(
argument|T *p
argument_list|)
block|{
name|u64
name|cmp
operator|=
name|atomic_load
argument_list|(
operator|&
name|head_
argument_list|,
name|memory_order_relaxed
argument_list|)
block|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|u64
name|cnt
init|=
operator|(
name|cmp
operator|&
name|kCounterMask
operator|)
operator|+
name|kCounterInc
decl_stmt|;
name|u64
name|xch
init|=
operator|(
name|u64
operator|)
operator|(
name|uptr
operator|)
name|p
operator||
name|cnt
decl_stmt|;
name|p
operator|->
name|next
operator|=
operator|(
name|T
operator|*
operator|)
call|(
name|uptr
call|)
argument_list|(
name|cmp
operator|&
name|kPtrMask
argument_list|)
expr_stmt|;
if|if
condition|(
name|atomic_compare_exchange_weak
argument_list|(
operator|&
name|head_
argument_list|,
operator|&
name|cmp
argument_list|,
name|xch
argument_list|,
name|memory_order_release
argument_list|)
condition|)
break|break;
block|}
block|}
name|T
operator|*
name|Pop
argument_list|()
block|{
name|u64
name|cmp
operator|=
name|atomic_load
argument_list|(
operator|&
name|head_
argument_list|,
name|memory_order_acquire
argument_list|)
block|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|T
modifier|*
name|cur
init|=
operator|(
name|T
operator|*
operator|)
call|(
name|uptr
call|)
argument_list|(
name|cmp
operator|&
name|kPtrMask
argument_list|)
decl_stmt|;
if|if
condition|(
name|cur
operator|==
literal|0
condition|)
return|return
literal|0
return|;
name|T
modifier|*
name|nxt
init|=
name|cur
operator|->
name|next
decl_stmt|;
name|u64
name|cnt
init|=
operator|(
name|cmp
operator|&
name|kCounterMask
operator|)
decl_stmt|;
name|u64
name|xch
init|=
operator|(
name|u64
operator|)
operator|(
name|uptr
operator|)
name|nxt
operator||
name|cnt
decl_stmt|;
if|if
condition|(
name|atomic_compare_exchange_weak
argument_list|(
operator|&
name|head_
argument_list|,
operator|&
name|cmp
argument_list|,
name|xch
argument_list|,
name|memory_order_acquire
argument_list|)
condition|)
return|return
name|cur
return|;
block|}
block|}
comment|// private:
specifier|static
specifier|const
name|int
name|kCounterBits
operator|=
name|FIRST_32_SECOND_64
argument_list|(
literal|32
argument_list|,
literal|17
argument_list|)
block|;
specifier|static
specifier|const
name|u64
name|kPtrMask
operator|=
operator|(
operator|(
name|u64
operator|)
operator|-
literal|1
operator|)
operator|>>
name|kCounterBits
block|;
specifier|static
specifier|const
name|u64
name|kCounterMask
operator|=
operator|~
name|kPtrMask
block|;
specifier|static
specifier|const
name|u64
name|kCounterInc
operator|=
name|kPtrMask
operator|+
literal|1
block|;
name|atomic_uint64_t
name|head_
block|; }
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef SANITIZER_LFSTACK_H
end_comment

end_unit

