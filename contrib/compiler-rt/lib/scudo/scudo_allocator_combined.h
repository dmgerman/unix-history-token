begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- scudo_allocator_combined.h ------------------------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// Scudo Combined Allocator, dispatches allocation& deallocation requests to
end_comment

begin_comment
comment|/// the Primary or the Secondary backend allocators.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCUDO_ALLOCATOR_COMBINED_H_
end_ifndef

begin_define
define|#
directive|define
name|SCUDO_ALLOCATOR_COMBINED_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SCUDO_ALLOCATOR_H_
end_ifndef

begin_error
error|#
directive|error
literal|"This file must be included inside scudo_allocator.h."
end_error

begin_endif
endif|#
directive|endif
end_endif

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
name|class
name|ScudoCombinedAllocator
block|{
name|public
operator|:
name|void
name|init
argument_list|(
argument|s32 ReleaseToOSIntervalMs
argument_list|)
block|{
name|Primary
operator|.
name|Init
argument_list|(
name|ReleaseToOSIntervalMs
argument_list|)
block|;
name|Secondary
operator|.
name|Init
argument_list|()
block|;
name|Stats
operator|.
name|Init
argument_list|()
block|;   }
comment|// Primary allocations are always MinAlignment aligned, and as such do not
comment|// require an Alignment parameter.
name|void
operator|*
name|allocatePrimary
argument_list|(
argument|AllocatorCache *Cache
argument_list|,
argument|uptr Size
argument_list|)
block|{
return|return
name|Cache
operator|->
name|Allocate
argument_list|(
operator|&
name|Primary
argument_list|,
name|Primary
operator|.
name|ClassID
argument_list|(
name|Size
argument_list|)
argument_list|)
return|;
block|}
comment|// Secondary allocations do not require a Cache, but do require an Alignment
comment|// parameter.
name|void
operator|*
name|allocateSecondary
argument_list|(
argument|uptr Size
argument_list|,
argument|uptr Alignment
argument_list|)
block|{
return|return
name|Secondary
operator|.
name|Allocate
argument_list|(
operator|&
name|Stats
argument_list|,
name|Size
argument_list|,
name|Alignment
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|void
name|deallocatePrimary
parameter_list|(
name|AllocatorCache
modifier|*
name|Cache
parameter_list|,
name|void
modifier|*
name|Ptr
parameter_list|)
block|{
name|Cache
operator|->
name|Deallocate
argument_list|(
operator|&
name|Primary
argument_list|,
name|Primary
operator|.
name|GetSizeClass
argument_list|(
name|Ptr
argument_list|)
argument_list|,
name|Ptr
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|deallocateSecondary
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|)
block|{
name|Secondary
operator|.
name|Deallocate
argument_list|(
operator|&
name|Stats
argument_list|,
name|Ptr
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|uptr
name|getActuallyAllocatedSize
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|,
name|bool
name|FromPrimary
parameter_list|)
block|{
if|if
condition|(
name|FromPrimary
condition|)
return|return
name|PrimaryAllocator
operator|::
name|ClassIdToSize
argument_list|(
name|Primary
operator|.
name|GetSizeClass
argument_list|(
name|Ptr
argument_list|)
argument_list|)
return|;
return|return
name|Secondary
operator|.
name|GetActuallyAllocatedSize
argument_list|(
name|Ptr
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|initCache
parameter_list|(
name|AllocatorCache
modifier|*
name|Cache
parameter_list|)
block|{
name|Cache
operator|->
name|Init
argument_list|(
operator|&
name|Stats
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|destroyCache
parameter_list|(
name|AllocatorCache
modifier|*
name|Cache
parameter_list|)
block|{
name|Cache
operator|->
name|Destroy
argument_list|(
operator|&
name|Primary
argument_list|,
operator|&
name|Stats
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|getStats
argument_list|(
name|AllocatorStatCounters
name|StatType
argument_list|)
decl|const
block|{
name|Stats
operator|.
name|Get
argument_list|(
name|StatType
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|PrimaryAllocator
name|Primary
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SecondaryAllocator
name|Secondary
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|AllocatorGlobalStats
name|Stats
decl_stmt|;
end_decl_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// SCUDO_ALLOCATOR_COMBINED_H_
end_comment

end_unit

