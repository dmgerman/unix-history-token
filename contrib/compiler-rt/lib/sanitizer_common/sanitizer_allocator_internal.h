begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_allocator_internal.h -------------------------- C++ -----===//
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
comment|// This allocator is used inside run-times.
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
name|SANITIZER_ALLOCATOR_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_ALLOCATOR_INTERNAL_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_allocator.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
comment|// FIXME: Check if we may use even more compact size class map for internal
comment|// purposes.
typedef|typedef
name|CompactSizeClassMap
name|InternalSizeClassMap
typedef|;
specifier|static
specifier|const
name|uptr
name|kInternalAllocatorSpace
init|=
literal|0
decl_stmt|;
specifier|static
specifier|const
name|u64
name|kInternalAllocatorSize
init|=
name|SANITIZER_MMAP_RANGE_SIZE
decl_stmt|;
specifier|static
specifier|const
name|uptr
name|kInternalAllocatorRegionSizeLog
init|=
literal|20
decl_stmt|;
if|#
directive|if
name|SANITIZER_WORDSIZE
operator|==
literal|32
specifier|static
specifier|const
name|uptr
name|kInternalAllocatorNumRegions
init|=
name|kInternalAllocatorSize
operator|>>
name|kInternalAllocatorRegionSizeLog
decl_stmt|;
typedef|typedef
name|FlatByteMap
operator|<
name|kInternalAllocatorNumRegions
operator|>
name|ByteMap
expr_stmt|;
else|#
directive|else
specifier|static
specifier|const
name|uptr
name|kInternalAllocatorNumRegions
init|=
name|kInternalAllocatorSize
operator|>>
name|kInternalAllocatorRegionSizeLog
decl_stmt|;
typedef|typedef
name|TwoLevelByteMap
operator|<
operator|(
name|kInternalAllocatorNumRegions
operator|>>
literal|12
operator|)
operator|,
literal|1
operator|<<
literal|12
operator|>
name|ByteMap
expr_stmt|;
endif|#
directive|endif
typedef|typedef
name|SizeClassAllocator32
operator|<
name|kInternalAllocatorSpace
operator|,
name|kInternalAllocatorSize
operator|,
literal|0
operator|,
name|InternalSizeClassMap
operator|,
name|kInternalAllocatorRegionSizeLog
operator|,
name|ByteMap
operator|>
name|PrimaryInternalAllocator
expr_stmt|;
typedef|typedef
name|SizeClassAllocatorLocalCache
operator|<
name|PrimaryInternalAllocator
operator|>
name|InternalAllocatorCache
expr_stmt|;
typedef|typedef
name|CombinedAllocator
operator|<
name|PrimaryInternalAllocator
operator|,
name|InternalAllocatorCache
operator|,
name|LargeMmapAllocator
operator|<
operator|>
expr|>
name|InternalAllocator
expr_stmt|;
name|void
modifier|*
name|InternalAlloc
parameter_list|(
name|uptr
name|size
parameter_list|,
name|InternalAllocatorCache
modifier|*
name|cache
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|InternalFree
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|InternalAllocatorCache
modifier|*
name|cache
init|=
literal|0
parameter_list|)
function_decl|;
name|InternalAllocator
modifier|*
name|internal_allocator
parameter_list|()
function_decl|;
enum|enum
name|InternalAllocEnum
block|{
name|INTERNAL_ALLOC
block|}
enum|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_decl_stmt
specifier|inline
name|void
modifier|*
name|operator
name|new
argument_list|(
name|__sanitizer
operator|::
name|operator_new_size_type
name|size
argument_list|,
name|InternalAllocEnum
argument_list|)
block|{
return|return
name|InternalAlloc
argument_list|(
name|size
argument_list|)
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_ALLOCATOR_INTERNAL_H
end_comment

end_unit

