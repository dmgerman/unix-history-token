begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_atomic_clang_x86.h ----------------------------*- C++ -*-===//
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
name|SANITIZER_ATOMIC_CLANG_X86_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_ATOMIC_CLANG_X86_H
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
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|cnt
condition|;
name|i
operator|++
control|)
asm|__asm__
specifier|__volatile__
asm|("pause");
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
comment|// On x86 loads are implicitly acquire.
asm|__asm__
specifier|__volatile__
asm|("" ::: "memory");
block|}
else|else
block|{
comment|// seq_cst
comment|// On x86 plain MOV is enough for seq_cst store.
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
block|}
else|else
block|{
comment|// 64-bit load on 32-bit platform.
asm|__asm__
specifier|__volatile__
asm|(         "movq %1, %%mm0;"
comment|// Use mmx reg for 64-bit atomic moves
asm|"movq %%mm0, %0;"
comment|// (ptr could be read-only)
asm|"emms;"
comment|// Empty mmx state/Reset FP regs
asm|: "=m" (v)         : "m" (a->val_dont_use)         :
comment|// mark the FP stack and mmx registers as clobbered
asm|"st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)",
ifdef|#
directive|ifdef
name|__MMX__
asm|"mm0", "mm1", "mm2", "mm3", "mm4", "mm5", "mm6", "mm7",
endif|#
directive|endif
comment|// #ifdef __MMX__
asm|"memory");
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
comment|// On x86 stores are implicitly release.
asm|__asm__
specifier|__volatile__
asm|("" ::: "memory");
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
comment|// On x86 stores are implicitly release.
asm|__asm__
specifier|__volatile__
asm|("" ::: "memory");
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
asm|__asm__
specifier|__volatile__
asm|(         "movq %1, %%mm0;"
comment|// Use mmx reg for 64-bit atomic moves
asm|"movq %%mm0, %0;"         "emms;"
comment|// Empty mmx state/Reset FP regs
asm|: "=m" (a->val_dont_use)         : "m" (v)         :
comment|// mark the FP stack and mmx registers as clobbered
asm|"st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)",
ifdef|#
directive|ifdef
name|__MMX__
asm|"mm0", "mm1", "mm2", "mm3", "mm4", "mm5", "mm6", "mm7",
endif|#
directive|endif
comment|// #ifdef __MMX__
asm|"memory");
if|if
condition|(
name|mo
operator|==
name|memory_order_seq_cst
condition|)
name|__sync_synchronize
argument_list|()
expr_stmt|;
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
comment|// #ifndef SANITIZER_ATOMIC_CLANG_X86_H
end_comment

end_unit

