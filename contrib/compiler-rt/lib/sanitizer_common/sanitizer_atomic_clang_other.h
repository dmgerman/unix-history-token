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
comment|// MIPS32 does not support atomic> 4 bytes. To address this lack of
comment|// functionality, the sanitizer library provides helper methods which use an
comment|// internal spin lock mechanism to emulate atomic oprations when the size is
comment|// 8 bytes.
if|#
directive|if
name|defined
argument_list|(
name|_MIPS_SIM
argument_list|)
operator|&&
name|_MIPS_SIM
operator|==
name|_ABIO32
specifier|static
name|void
name|__spin_lock
parameter_list|(
specifier|volatile
name|int
modifier|*
name|lock
parameter_list|)
block|{
while|while
condition|(
name|__sync_lock_test_and_set
argument_list|(
name|lock
argument_list|,
literal|1
argument_list|)
condition|)
while|while
condition|(
operator|*
name|lock
condition|)
block|{     }
block|}
specifier|static
name|void
name|__spin_unlock
parameter_list|(
specifier|volatile
name|int
modifier|*
name|lock
parameter_list|)
block|{
name|__sync_lock_release
argument_list|(
name|lock
argument_list|)
expr_stmt|;
block|}
comment|// Make sure the lock is on its own cache line to prevent false sharing.
comment|// Put it inside a struct that is aligned and padded to the typical MIPS
comment|// cacheline which is 32 bytes.
specifier|static
struct|struct
block|{
name|int
name|lock
decl_stmt|;
name|char
name|pad
index|[
literal|32
operator|-
sizeof|sizeof
argument_list|(
name|int
argument_list|)
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|32
argument_list|)
operator|)
argument_list|)
name|lock
init|=
block|{
literal|0
block|}
struct|;
name|template
operator|<
name|class
name|T
operator|>
name|T
name|__mips_sync_fetch_and_add
argument_list|(
argument|volatile T *ptr
argument_list|,
argument|T val
argument_list|)
block|{
name|T
name|ret
block|;
name|__spin_lock
argument_list|(
operator|&
name|lock
operator|.
name|lock
argument_list|)
block|;
name|ret
operator|=
operator|*
name|ptr
block|;
operator|*
name|ptr
operator|=
name|ret
operator|+
name|val
block|;
name|__spin_unlock
argument_list|(
operator|&
name|lock
operator|.
name|lock
argument_list|)
block|;
return|return
name|ret
return|;
block|}
name|template
operator|<
name|class
name|T
operator|>
name|T
name|__mips_sync_val_compare_and_swap
argument_list|(
argument|volatile T *ptr
argument_list|,
argument|T oldval
argument_list|,
argument|T newval
argument_list|)
block|{
name|T
name|ret
block|;
name|__spin_lock
argument_list|(
operator|&
name|lock
operator|.
name|lock
argument_list|)
block|;
name|ret
operator|=
operator|*
name|ptr
block|;
if|if
condition|(
name|ret
operator|==
name|oldval
condition|)
operator|*
name|ptr
operator|=
name|newval
expr_stmt|;
name|__spin_unlock
argument_list|(
operator|&
name|lock
operator|.
name|lock
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_elseif
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
end_elseif

begin_elseif
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
end_elseif

begin_else
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
end_else

begin_block
unit|} else
block|{
comment|// 64-bit load on 32-bit platform.
comment|// Gross, but simple and reliable.
comment|// Assume that it is not in read-only memory.
if|#
directive|if
name|defined
argument_list|(
name|_MIPS_SIM
argument_list|)
operator|&&
name|_MIPS_SIM
operator|==
name|_ABIO32
name|typename
name|T
operator|::
name|Type
specifier|volatile
operator|*
name|val_ptr
operator|=
name|const_cast
operator|<
name|typename
name|T
operator|::
name|Type
specifier|volatile
operator|*
operator|>
operator|(
operator|&
name|a
operator|->
name|val_dont_use
operator|)
expr_stmt|;
name|v
operator|=
name|__mips_sync_fetch_and_add
operator|<
name|u64
operator|>
operator|(
name|reinterpret_cast
operator|<
name|u64
specifier|volatile
operator|*
operator|>
operator|(
name|val_ptr
operator|)
operator|,
literal|0
operator|)
expr_stmt|;
else|#
directive|else
name|v
operator|=
name|__sync_fetch_and_add
argument_list|(
argument|const_cast<typename T::Type volatile *>(&a->val_dont_use)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_block

begin_return
return|return
name|v
return|;
end_return

begin_expr_stmt
unit|}  template
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
end_expr_stmt

begin_elseif
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
end_elseif

begin_else
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
end_else

begin_block
unit|} else
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
if|#
directive|if
name|defined
argument_list|(
name|_MIPS_SIM
argument_list|)
operator|&&
name|_MIPS_SIM
operator|==
name|_ABIO32
name|typename
name|T
operator|::
name|Type
specifier|volatile
operator|*
name|val_ptr
operator|=
name|const_cast
operator|<
name|typename
name|T
operator|::
name|Type
specifier|volatile
operator|*
operator|>
operator|(
operator|&
name|a
operator|->
name|val_dont_use
operator|)
expr_stmt|;
name|cur
operator|=
name|__mips_sync_val_compare_and_swap
operator|<
name|u64
operator|>
operator|(
name|reinterpret_cast
operator|<
name|u64
specifier|volatile
operator|*
operator|>
operator|(
name|val_ptr
operator|)
operator|,
operator|(
name|u64
operator|)
name|cmp
operator|,
operator|(
name|u64
operator|)
name|v
operator|)
expr_stmt|;
else|#
directive|else
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
endif|#
directive|endif
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
end_block

begin_comment
unit|}  }
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

