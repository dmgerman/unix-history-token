begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_persistent_allocator.h ------------------------*- C++ -*-===//
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
comment|// A fast memory allocator that does not support free() nor realloc().
end_comment

begin_comment
comment|// All allocations are forever.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_PERSISTENT_ALLOCATOR_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_PERSISTENT_ALLOCATOR_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_mutex.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_atomic.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
name|class
name|PersistentAllocator
block|{
name|public
label|:
name|void
modifier|*
name|alloc
parameter_list|(
name|uptr
name|size
parameter_list|)
function_decl|;
name|private
label|:
name|void
modifier|*
name|tryAlloc
parameter_list|(
name|uptr
name|size
parameter_list|)
function_decl|;
name|StaticSpinMutex
name|mtx
decl_stmt|;
comment|// Protects alloc of new blocks for region allocator.
name|atomic_uintptr_t
name|region_pos
decl_stmt|;
comment|// Region allocator for Node's.
name|atomic_uintptr_t
name|region_end
decl_stmt|;
block|}
empty_stmt|;
specifier|inline
name|void
operator|*
name|PersistentAllocator
operator|::
name|tryAlloc
argument_list|(
argument|uptr size
argument_list|)
block|{
comment|// Optimisic lock-free allocation, essentially try to bump the region ptr.
for|for
control|(
init|;
condition|;
control|)
block|{
name|uptr
name|cmp
init|=
name|atomic_load
argument_list|(
operator|&
name|region_pos
argument_list|,
name|memory_order_acquire
argument_list|)
decl_stmt|;
name|uptr
name|end
init|=
name|atomic_load
argument_list|(
operator|&
name|region_end
argument_list|,
name|memory_order_acquire
argument_list|)
decl_stmt|;
if|if
condition|(
name|cmp
operator|==
literal|0
operator|||
name|cmp
operator|+
name|size
operator|>
name|end
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|atomic_compare_exchange_weak
argument_list|(
operator|&
name|region_pos
argument_list|,
operator|&
name|cmp
argument_list|,
name|cmp
operator|+
name|size
argument_list|,
name|memory_order_acquire
argument_list|)
condition|)
return|return
operator|(
name|void
operator|*
operator|)
name|cmp
return|;
block|}
block|}
specifier|inline
name|void
operator|*
name|PersistentAllocator
operator|::
name|alloc
argument_list|(
argument|uptr size
argument_list|)
block|{
comment|// First, try to allocate optimisitically.
name|void
operator|*
name|s
operator|=
name|tryAlloc
argument_list|(
name|size
argument_list|)
block|;
if|if
condition|(
name|s
condition|)
return|return
name|s
return|;
comment|// If failed, lock, retry and alloc new superblock.
name|SpinMutexLock
name|l
argument_list|(
operator|&
name|mtx
argument_list|)
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|s
operator|=
name|tryAlloc
argument_list|(
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
condition|)
return|return
name|s
return|;
name|atomic_store
argument_list|(
operator|&
name|region_pos
argument_list|,
literal|0
argument_list|,
name|memory_order_relaxed
argument_list|)
expr_stmt|;
name|uptr
name|allocsz
init|=
literal|64
operator|*
literal|1024
decl_stmt|;
if|if
condition|(
name|allocsz
operator|<
name|size
condition|)
name|allocsz
operator|=
name|size
expr_stmt|;
name|uptr
name|mem
init|=
operator|(
name|uptr
operator|)
name|MmapOrDie
argument_list|(
name|allocsz
argument_list|,
literal|"stack depot"
argument_list|)
decl_stmt|;
name|atomic_store
argument_list|(
operator|&
name|region_end
argument_list|,
name|mem
operator|+
name|allocsz
argument_list|,
name|memory_order_release
argument_list|)
expr_stmt|;
name|atomic_store
argument_list|(
operator|&
name|region_pos
argument_list|,
name|mem
argument_list|,
name|memory_order_release
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PersistentAllocator
name|thePersistentAllocator
decl_stmt|;
end_decl_stmt

begin_function
specifier|inline
name|void
modifier|*
name|PersistentAlloc
parameter_list|(
name|uptr
name|sz
parameter_list|)
block|{
return|return
name|thePersistentAllocator
operator|.
name|alloc
argument_list|(
name|sz
argument_list|)
return|;
block|}
end_function

begin_comment
unit|}
comment|// namespace __sanitizer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_PERSISTENT_ALLOCATOR_H
end_comment

end_unit

