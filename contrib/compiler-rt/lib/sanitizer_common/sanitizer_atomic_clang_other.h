begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_atomic_clang_other.h --------------------------*- C++ -*-===//
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
comment|// This file is a part of ThreadSanitizer/AddressSanitizer runtime.
end_comment

begin_comment
comment|// Not intended for direct inclusion. Include sanitizer_atomic.h.
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
name|SANITIZER_ATOMIC_CLANG_OTHER_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_ATOMIC_CLANG_OTHER_H
end_define

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
name|INLINE
name|void
name|proc_yield
parameter_list|(
name|int
name|cnt
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("" ::: "memory");
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|INLINE
name|typename
name|T
operator|::
name|Type
name|atomic_load
argument_list|(
argument|const volatile T *a
argument_list|,
argument|memory_order mo
argument_list|)
block|{
name|DCHECK
argument_list|(
name|mo
operator|&
operator|(
name|memory_order_relaxed
operator||
name|memory_order_consume
operator||
name|memory_order_acquire
operator||
name|memory_order_seq_cst
operator|)
argument_list|)
block|;
name|DCHECK
argument_list|(
operator|!
operator|(
operator|(
name|uptr
operator|)
name|a
operator|%
sizeof|sizeof
argument_list|(
operator|*
name|a
argument_list|)
operator|)
argument_list|)
block|;
name|typename
name|T
operator|::
name|Type
name|v
block|;
if|if
condition|(
sizeof|sizeof
argument_list|(
operator|*
name|a
argument_list|)
operator|<
literal|8
operator|||
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|==
literal|8
condition|)
block|{
comment|// Assume that aligned loads are atomic.
if|if
condition|(
name|mo
operator|==
name|memory_order_relaxed
condition|)
block|{
name|v
operator|=
name|a
operator|->
name|val_dont_use
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|mo
operator|==
name|memory_order_consume
condition|)
block|{
comment|// Assume that processor respects data dependencies
comment|// (and that compiler won't break them).
asm|__asm__
specifier|__volatile__
asm|("" ::: "memory");
name|v
operator|=
name|a
operator|->
name|val_dont_use
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|("" ::: "memory");
block|}
elseif|else
if|if
condition|(
name|mo
operator|==
name|memory_order_acquire
condition|)
block|{
asm|__asm__
specifier|__volatile__
asm|("" ::: "memory");
name|v
operator|=
name|a
operator|->
name|val_dont_use
expr_stmt|;
name|__sync_synchronize
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|// seq_cst
comment|// E.g. on POWER we need a hw fence even before the store.
name|__sync_synchronize
argument_list|()
expr_stmt|;
name|v
operator|=
name|a
operator|->
name|val_dont_use
expr_stmt|;
name|__sync_synchronize
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// 64-bit load on 32-bit platform.
comment|// Gross, but simple and reliable.
comment|// Assume that it is not in read-only memory.
name|v
operator|=
name|__sync_fetch_and_add
argument_list|(
argument|const_cast<typename T::Type volatile *>(&a->val_dont_use)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
return|return
name|v
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|INLINE
name|void
name|atomic_store
argument_list|(
argument|volatile T *a
argument_list|,
argument|typename T::Type v
argument_list|,
argument|memory_order mo
argument_list|)
block|{
name|DCHECK
argument_list|(
name|mo
operator|&
operator|(
name|memory_order_relaxed
operator||
name|memory_order_release
operator||
name|memory_order_seq_cst
operator|)
argument_list|)
block|;
name|DCHECK
argument_list|(
operator|!
operator|(
operator|(
name|uptr
operator|)
name|a
operator|%
sizeof|sizeof
argument_list|(
operator|*
name|a
argument_list|)
operator|)
argument_list|)
block|;
if|if
condition|(
sizeof|sizeof
argument_list|(
operator|*
name|a
argument_list|)
operator|<
literal|8
operator|||
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|==
literal|8
condition|)
block|{
comment|// Assume that aligned loads are atomic.
if|if
condition|(
name|mo
operator|==
name|memory_order_relaxed
condition|)
block|{
name|a
operator|->
name|val_dont_use
operator|=
name|v
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|mo
operator|==
name|memory_order_release
condition|)
block|{
name|__sync_synchronize
argument_list|()
expr_stmt|;
name|a
operator|->
name|val_dont_use
operator|=
name|v
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|("" ::: "memory");
block|}
else|else
block|{
comment|// seq_cst
name|__sync_synchronize
argument_list|()
expr_stmt|;
name|a
operator|->
name|val_dont_use
operator|=
name|v
expr_stmt|;
name|__sync_synchronize
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// 64-bit store on 32-bit platform.
comment|// Gross, but simple and reliable.
name|typename
name|T
operator|::
name|Type
name|cmp
operator|=
name|a
operator|->
name|val_dont_use
expr_stmt|;
name|typename
name|T
operator|::
name|Type
name|cur
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|cur
operator|=
name|__sync_val_compare_and_swap
argument_list|(
operator|&
name|a
operator|->
name|val_dont_use
argument_list|,
name|cmp
argument_list|,
name|v
argument_list|)
expr_stmt|;
if|if
condition|(
name|cmp
operator|==
name|v
condition|)
break|break;
name|cmp
operator|=
name|cur
expr_stmt|;
block|}
block|}
block|}
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
comment|// #ifndef SANITIZER_ATOMIC_CLANG_OTHER_H
end_comment

end_unit

