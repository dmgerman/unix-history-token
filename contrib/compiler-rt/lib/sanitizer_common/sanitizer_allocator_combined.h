begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_allocator_combined.h --------------------------*- C++ -*-===//
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
comment|// Part of the Sanitizer Allocator.
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
name|SANITIZER_ALLOCATOR_H
end_ifndef

begin_error
error|#
directive|error
error|This file must be included inside sanitizer_allocator.h
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// This class implements a complete memory allocator by using two
end_comment

begin_comment
comment|// internal allocators:
end_comment

begin_comment
comment|// PrimaryAllocator is efficient, but may not allocate some sizes (alignments).
end_comment

begin_comment
comment|//  When allocating 2^x bytes it should return 2^x aligned chunk.
end_comment

begin_comment
comment|// PrimaryAllocator is used via a local AllocatorCache.
end_comment

begin_comment
comment|// SecondaryAllocator can allocate anything, but is not efficient.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|PrimaryAllocator
operator|,
name|class
name|AllocatorCache
operator|,
name|class
name|SecondaryAllocator
operator|>
comment|// NOLINT
name|class
name|CombinedAllocator
block|{
name|public
operator|:
typedef|typedef
name|typename
name|SecondaryAllocator
operator|::
name|FailureHandler
name|FailureHandler
expr_stmt|;
name|void
name|InitLinkerInitialized
argument_list|(
argument|s32 release_to_os_interval_ms
argument_list|)
block|{
name|primary_
operator|.
name|Init
argument_list|(
name|release_to_os_interval_ms
argument_list|)
block|;
name|secondary_
operator|.
name|InitLinkerInitialized
argument_list|()
block|;
name|stats_
operator|.
name|InitLinkerInitialized
argument_list|()
block|;   }
name|void
name|Init
argument_list|(
argument|s32 release_to_os_interval_ms
argument_list|)
block|{
name|primary_
operator|.
name|Init
argument_list|(
name|release_to_os_interval_ms
argument_list|)
block|;
name|secondary_
operator|.
name|Init
argument_list|()
block|;
name|stats_
operator|.
name|Init
argument_list|()
block|;   }
name|void
operator|*
name|Allocate
argument_list|(
argument|AllocatorCache *cache
argument_list|,
argument|uptr size
argument_list|,
argument|uptr alignment
argument_list|)
block|{
comment|// Returning 0 on malloc(0) may break a lot of code.
if|if
condition|(
name|size
operator|==
literal|0
condition|)
name|size
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|size
operator|+
name|alignment
operator|<
name|size
condition|)
return|return
name|FailureHandler
operator|::
name|OnBadRequest
argument_list|()
return|;
end_if

begin_decl_stmt
name|uptr
name|original_size
init|=
name|size
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If alignment requirements are to be fulfilled by the frontend allocator
end_comment

begin_comment
comment|// rather than by the primary or secondary, passing an alignment lower than
end_comment

begin_comment
comment|// or equal to 8 will prevent any further rounding up, as well as the later
end_comment

begin_comment
comment|// alignment check.
end_comment

begin_if
if|if
condition|(
name|alignment
operator|>
literal|8
condition|)
name|size
operator|=
name|RoundUpTo
argument_list|(
name|size
argument_list|,
name|alignment
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|// The primary allocator should return a 2^x aligned allocation when
end_comment

begin_comment
comment|// requested 2^x bytes, hence using the rounded up 'size' when being
end_comment

begin_comment
comment|// serviced by the primary (this is no longer true when the primary is
end_comment

begin_comment
comment|// using a non-fixed base address). The secondary takes care of the
end_comment

begin_comment
comment|// alignment without such requirement, and allocating 'size' would use
end_comment

begin_comment
comment|// extraneous memory, so we employ 'original_size'.
end_comment

begin_decl_stmt
name|void
modifier|*
name|res
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|primary_
operator|.
name|CanAllocate
argument_list|(
name|size
argument_list|,
name|alignment
argument_list|)
condition|)
name|res
operator|=
name|cache
operator|->
name|Allocate
argument_list|(
operator|&
name|primary_
argument_list|,
name|primary_
operator|.
name|ClassID
argument_list|(
name|size
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|res
operator|=
name|secondary_
operator|.
name|Allocate
argument_list|(
operator|&
name|stats_
argument_list|,
name|original_size
argument_list|,
name|alignment
argument_list|)
expr_stmt|;
end_if

begin_if
if|if
condition|(
operator|!
name|res
condition|)
return|return
name|FailureHandler
operator|::
name|OnOOM
argument_list|()
return|;
end_if

begin_if
if|if
condition|(
name|alignment
operator|>
literal|8
condition|)
name|CHECK_EQ
argument_list|(
name|reinterpret_cast
operator|<
name|uptr
operator|>
operator|(
name|res
operator|)
operator|&
operator|(
name|alignment
operator|-
literal|1
operator|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_if

begin_return
return|return
name|res
return|;
end_return

begin_macro
unit|}    s32
name|ReleaseToOSIntervalMs
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|primary_
operator|.
name|ReleaseToOSIntervalMs
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|void
name|SetReleaseToOSIntervalMs
parameter_list|(
name|s32
name|release_to_os_interval_ms
parameter_list|)
block|{
name|primary_
operator|.
name|SetReleaseToOSIntervalMs
argument_list|(
name|release_to_os_interval_ms
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|Deallocate
parameter_list|(
name|AllocatorCache
modifier|*
name|cache
parameter_list|,
name|void
modifier|*
name|p
parameter_list|)
block|{
if|if
condition|(
operator|!
name|p
condition|)
return|return;
if|if
condition|(
name|primary_
operator|.
name|PointerIsMine
argument_list|(
name|p
argument_list|)
condition|)
name|cache
operator|->
name|Deallocate
argument_list|(
operator|&
name|primary_
argument_list|,
name|primary_
operator|.
name|GetSizeClass
argument_list|(
name|p
argument_list|)
argument_list|,
name|p
argument_list|)
expr_stmt|;
else|else
name|secondary_
operator|.
name|Deallocate
argument_list|(
operator|&
name|stats_
argument_list|,
name|p
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
modifier|*
name|Reallocate
parameter_list|(
name|AllocatorCache
modifier|*
name|cache
parameter_list|,
name|void
modifier|*
name|p
parameter_list|,
name|uptr
name|new_size
parameter_list|,
name|uptr
name|alignment
parameter_list|)
block|{
if|if
condition|(
operator|!
name|p
condition|)
return|return
name|Allocate
argument_list|(
name|cache
argument_list|,
name|new_size
argument_list|,
name|alignment
argument_list|)
return|;
if|if
condition|(
operator|!
name|new_size
condition|)
block|{
name|Deallocate
argument_list|(
name|cache
argument_list|,
name|p
argument_list|)
expr_stmt|;
return|return
name|nullptr
return|;
block|}
name|CHECK
argument_list|(
name|PointerIsMine
argument_list|(
name|p
argument_list|)
argument_list|)
expr_stmt|;
name|uptr
name|old_size
init|=
name|GetActuallyAllocatedSize
argument_list|(
name|p
argument_list|)
decl_stmt|;
name|uptr
name|memcpy_size
init|=
name|Min
argument_list|(
name|new_size
argument_list|,
name|old_size
argument_list|)
decl_stmt|;
name|void
modifier|*
name|new_p
init|=
name|Allocate
argument_list|(
name|cache
argument_list|,
name|new_size
argument_list|,
name|alignment
argument_list|)
decl_stmt|;
if|if
condition|(
name|new_p
condition|)
name|internal_memcpy
argument_list|(
name|new_p
argument_list|,
name|p
argument_list|,
name|memcpy_size
argument_list|)
expr_stmt|;
name|Deallocate
argument_list|(
name|cache
argument_list|,
name|p
argument_list|)
expr_stmt|;
return|return
name|new_p
return|;
block|}
end_function

begin_function
name|bool
name|PointerIsMine
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
if|if
condition|(
name|primary_
operator|.
name|PointerIsMine
argument_list|(
name|p
argument_list|)
condition|)
return|return
name|true
return|;
return|return
name|secondary_
operator|.
name|PointerIsMine
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

begin_function
name|bool
name|FromPrimary
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
return|return
name|primary_
operator|.
name|PointerIsMine
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|GetMetaData
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
block|{
if|if
condition|(
name|primary_
operator|.
name|PointerIsMine
argument_list|(
name|p
argument_list|)
condition|)
return|return
name|primary_
operator|.
name|GetMetaData
argument_list|(
name|p
argument_list|)
return|;
return|return
name|secondary_
operator|.
name|GetMetaData
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|GetBlockBegin
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
block|{
if|if
condition|(
name|primary_
operator|.
name|PointerIsMine
argument_list|(
name|p
argument_list|)
condition|)
return|return
name|primary_
operator|.
name|GetBlockBegin
argument_list|(
name|p
argument_list|)
return|;
return|return
name|secondary_
operator|.
name|GetBlockBegin
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// This function does the same as GetBlockBegin, but is much faster.
end_comment

begin_comment
comment|// Must be called with the allocator locked.
end_comment

begin_function
name|void
modifier|*
name|GetBlockBeginFastLocked
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
if|if
condition|(
name|primary_
operator|.
name|PointerIsMine
argument_list|(
name|p
argument_list|)
condition|)
return|return
name|primary_
operator|.
name|GetBlockBegin
argument_list|(
name|p
argument_list|)
return|;
return|return
name|secondary_
operator|.
name|GetBlockBeginFastLocked
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

begin_function
name|uptr
name|GetActuallyAllocatedSize
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
if|if
condition|(
name|primary_
operator|.
name|PointerIsMine
argument_list|(
name|p
argument_list|)
condition|)
return|return
name|primary_
operator|.
name|GetActuallyAllocatedSize
argument_list|(
name|p
argument_list|)
return|;
return|return
name|secondary_
operator|.
name|GetActuallyAllocatedSize
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

begin_function
name|uptr
name|TotalMemoryUsed
parameter_list|()
block|{
return|return
name|primary_
operator|.
name|TotalMemoryUsed
argument_list|()
operator|+
name|secondary_
operator|.
name|TotalMemoryUsed
argument_list|()
return|;
block|}
end_function

begin_function
name|void
name|TestOnlyUnmap
parameter_list|()
block|{
name|primary_
operator|.
name|TestOnlyUnmap
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|InitCache
parameter_list|(
name|AllocatorCache
modifier|*
name|cache
parameter_list|)
block|{
name|cache
operator|->
name|Init
argument_list|(
operator|&
name|stats_
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|DestroyCache
parameter_list|(
name|AllocatorCache
modifier|*
name|cache
parameter_list|)
block|{
name|cache
operator|->
name|Destroy
argument_list|(
operator|&
name|primary_
argument_list|,
operator|&
name|stats_
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|SwallowCache
parameter_list|(
name|AllocatorCache
modifier|*
name|cache
parameter_list|)
block|{
name|cache
operator|->
name|Drain
argument_list|(
operator|&
name|primary_
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|GetStats
argument_list|(
name|AllocatorStatCounters
name|s
argument_list|)
decl|const
block|{
name|stats_
operator|.
name|Get
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_function
name|void
name|PrintStats
parameter_list|()
block|{
name|primary_
operator|.
name|PrintStats
argument_list|()
expr_stmt|;
name|secondary_
operator|.
name|PrintStats
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// ForceLock() and ForceUnlock() are needed to implement Darwin malloc zone
end_comment

begin_comment
comment|// introspection API.
end_comment

begin_function
name|void
name|ForceLock
parameter_list|()
block|{
name|primary_
operator|.
name|ForceLock
argument_list|()
expr_stmt|;
name|secondary_
operator|.
name|ForceLock
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|ForceUnlock
parameter_list|()
block|{
name|secondary_
operator|.
name|ForceUnlock
argument_list|()
expr_stmt|;
name|primary_
operator|.
name|ForceUnlock
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// Iterate over all existing chunks.
end_comment

begin_comment
comment|// The allocator must be locked when calling this function.
end_comment

begin_function
name|void
name|ForEachChunk
parameter_list|(
name|ForEachChunkCallback
name|callback
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|primary_
operator|.
name|ForEachChunk
argument_list|(
name|callback
argument_list|,
name|arg
argument_list|)
expr_stmt|;
name|secondary_
operator|.
name|ForEachChunk
argument_list|(
name|callback
argument_list|,
name|arg
argument_list|)
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|PrimaryAllocator
name|primary_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SecondaryAllocator
name|secondary_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|AllocatorGlobalStats
name|stats_
decl_stmt|;
end_decl_stmt

unit|};
end_unit

