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
if|#
directive|if
name|SANITIZER_WORDSIZE
operator|==
literal|32
specifier|static
specifier|const
name|u64
name|kInternalAllocatorSize
init|=
operator|(
literal|1ULL
operator|<<
literal|32
operator|)
decl_stmt|;
specifier|static
specifier|const
name|uptr
name|kInternalAllocatorRegionSizeLog
init|=
literal|20
decl_stmt|;
else|#
directive|else
specifier|static
specifier|const
name|u64
name|kInternalAllocatorSize
init|=
operator|(
literal|1ULL
operator|<<
literal|47
operator|)
decl_stmt|;
specifier|static
specifier|const
name|uptr
name|kInternalAllocatorRegionSizeLog
init|=
literal|24
decl_stmt|;
endif|#
directive|endif
specifier|static
specifier|const
name|uptr
name|kInternalAllocatorFlatByteMapSize
init|=
name|kInternalAllocatorSize
operator|>>
name|kInternalAllocatorRegionSizeLog
decl_stmt|;
typedef|typedef
name|SizeClassAllocator32
operator|<
name|kInternalAllocatorSpace
operator|,
name|kInternalAllocatorSize
operator|,
literal|16
operator|,
name|InternalSizeClassMap
operator|,
name|kInternalAllocatorRegionSizeLog
operator|,
name|FlatByteMap
operator|<
name|kInternalAllocatorFlatByteMapSize
operator|>
expr|>
name|PrimaryInternalAllocator
expr_stmt|;
typedef|typedef
name|SizeClassAllocatorLocalCache
operator|<
name|PrimaryInternalAllocator
operator|>
name|InternalAllocatorCache
expr_stmt|;
comment|// We don't want our internal allocator to do any map/unmap operations.
struct|struct
name|CrashOnMapUnmap
block|{
name|void
name|OnMap
argument_list|(
name|uptr
name|p
argument_list|,
name|uptr
name|size
argument_list|)
decl|const
block|{
name|RAW_CHECK_MSG
argument_list|(
literal|0
argument_list|,
literal|"Unexpected mmap in InternalAllocator!"
argument_list|)
expr_stmt|;
block|}
name|void
name|OnUnmap
argument_list|(
name|uptr
name|p
argument_list|,
name|uptr
name|size
argument_list|)
decl|const
block|{
name|RAW_CHECK_MSG
argument_list|(
literal|0
argument_list|,
literal|"Unexpected munmap in InternalAllocator!"
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
typedef|typedef
name|CombinedAllocator
operator|<
name|PrimaryInternalAllocator
operator|,
name|InternalAllocatorCache
operator|,
name|LargeMmapAllocator
operator|<
name|CrashOnMapUnmap
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
comment|// SANITIZER_ALLOCATOR_INTERNAL_H
end_comment

end_unit

