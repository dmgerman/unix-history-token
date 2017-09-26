begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_atomic_clang.h --------------------------------*- C++ -*-===//
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
name|SANITIZER_ATOMIC_CLANG_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_ATOMIC_CLANG_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"sanitizer_atomic_clang_x86.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"sanitizer_atomic_clang_other.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
comment|// We would like to just use compiler builtin atomic operations
comment|// for loads and stores, but they are mostly broken in clang:
comment|// - they lead to vastly inefficient code generation
comment|// (http://llvm.org/bugs/show_bug.cgi?id=17281)
comment|// - 64-bit atomic operations are not implemented on x86_32
comment|// (http://llvm.org/bugs/show_bug.cgi?id=15034)
comment|// - they are not implemented on ARM
comment|// error: undefined reference to '__atomic_load_4'
comment|// See http://www.cl.cam.ac.uk/~pes20/cpp/cpp0xmappings.html
comment|// for mappings of the memory model to different processors.
name|INLINE
name|void
name|atomic_signal_fence
parameter_list|(
name|memory_order
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("" ::: "memory");
block|}
name|INLINE
name|void
name|atomic_thread_fence
parameter_list|(
name|memory_order
parameter_list|)
block|{
name|__sync_synchronize
argument_list|()
expr_stmt|;
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
name|atomic_fetch_add
argument_list|(
argument|volatile T *a
argument_list|,
argument|typename T::Type v
argument_list|,
argument|memory_order mo
argument_list|)
block|{
operator|(
name|void
operator|)
name|mo
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
return|return
name|__sync_fetch_and_add
argument_list|(
operator|&
name|a
operator|->
name|val_dont_use
argument_list|,
name|v
argument_list|)
return|;
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
name|atomic_fetch_sub
argument_list|(
argument|volatile T *a
argument_list|,
argument|typename T::Type v
argument_list|,
argument|memory_order mo
argument_list|)
block|{
operator|(
name|void
operator|)
name|mo
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
return|return
name|__sync_fetch_and_add
argument_list|(
operator|&
name|a
operator|->
name|val_dont_use
argument_list|,
operator|-
name|v
argument_list|)
return|;
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
name|atomic_exchange
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
name|mo
operator|&
operator|(
name|memory_order_release
operator||
name|memory_order_acq_rel
operator||
name|memory_order_seq_cst
operator|)
condition|)
name|__sync_synchronize
argument_list|()
expr_stmt|;
name|v
operator|=
name|__sync_lock_test_and_set
argument_list|(
operator|&
name|a
operator|->
name|val_dont_use
argument_list|,
name|v
argument_list|)
expr_stmt|;
if|if
condition|(
name|mo
operator|==
name|memory_order_seq_cst
condition|)
name|__sync_synchronize
argument_list|()
expr_stmt|;
return|return
name|v
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|INLINE
name|bool
name|atomic_compare_exchange_strong
argument_list|(
argument|volatile T *a
argument_list|,
argument|typename T::Type *cmp
argument_list|,
argument|typename T::Type xchg
argument_list|,
argument|memory_order mo
argument_list|)
block|{
typedef|typedef
name|typename
name|T
operator|::
name|Type
name|Type
expr_stmt|;
name|Type
name|cmpv
operator|=
operator|*
name|cmp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Type
name|prev
decl_stmt|;
end_decl_stmt

begin_if
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
end_if

begin_if
if|if
condition|(
sizeof|sizeof
argument_list|(
operator|*
name|a
argument_list|)
operator|==
literal|8
condition|)
block|{
name|Type
specifier|volatile
modifier|*
name|val_ptr
init|=
name|const_cast
operator|<
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
decl_stmt|;
name|prev
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
name|cmpv
operator|,
operator|(
name|u64
operator|)
name|xchg
operator|)
expr_stmt|;
block|}
else|else
block|{
name|prev
operator|=
name|__sync_val_compare_and_swap
argument_list|(
operator|&
name|a
operator|->
name|val_dont_use
argument_list|,
name|cmpv
argument_list|,
name|xchg
argument_list|)
expr_stmt|;
block|}
end_if

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|prev
operator|=
name|__sync_val_compare_and_swap
argument_list|(
operator|&
name|a
operator|->
name|val_dont_use
argument_list|,
name|cmpv
argument_list|,
name|xchg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|if
condition|(
name|prev
operator|==
name|cmpv
condition|)
return|return
name|true
return|;
end_if

begin_expr_stmt
operator|*
name|cmp
operator|=
name|prev
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
name|INLINE
name|bool
name|atomic_compare_exchange_weak
argument_list|(
argument|volatile T *a
argument_list|,
argument|typename T::Type *cmp
argument_list|,
argument|typename T::Type xchg
argument_list|,
argument|memory_order mo
argument_list|)
block|{
return|return
name|atomic_compare_exchange_strong
argument_list|(
name|a
argument_list|,
name|cmp
argument_list|,
name|xchg
argument_list|,
name|mo
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// namespace __sanitizer
end_comment

begin_undef
undef|#
directive|undef
name|ATOMIC_ORDER
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_ATOMIC_CLANG_H
end_comment

end_unit

