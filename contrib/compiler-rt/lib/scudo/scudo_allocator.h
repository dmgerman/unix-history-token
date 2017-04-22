begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- scudo_allocator.h ---------------------------------------*- C++ -*-===//
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
comment|/// Header for scudo_allocator.cpp.
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
name|SCUDO_ALLOCATOR_H_
end_ifndef

begin_define
define|#
directive|define
name|SCUDO_ALLOCATOR_H_
end_define

begin_include
include|#
directive|include
file|"scudo_flags.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_allocator.h"
end_include

begin_if
if|#
directive|if
operator|!
name|SANITIZER_LINUX
end_if

begin_error
error|#
directive|error
literal|"The Scudo hardened allocator is currently only supported on Linux."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|__scudo
block|{
enum|enum
name|AllocType
enum|:
name|u8
block|{
name|FromMalloc
init|=
literal|0
block|,
comment|// Memory block came from malloc, realloc, calloc, etc.
name|FromNew
init|=
literal|1
block|,
comment|// Memory block came from operator new.
name|FromNewArray
init|=
literal|2
block|,
comment|// Memory block came from operator new [].
name|FromMemalign
init|=
literal|3
block|,
comment|// Memory block came from memalign, posix_memalign, etc.
block|}
enum|;
enum|enum
name|ChunkState
enum|:
name|u8
block|{
name|ChunkAvailable
init|=
literal|0
block|,
name|ChunkAllocated
init|=
literal|1
block|,
name|ChunkQuarantine
init|=
literal|2
block|}
enum|;
comment|// Our header requires 64 bits of storage. Having the offset saves us from
comment|// using functions such as GetBlockBegin, that is fairly costly. Our first
comment|// implementation used the MetaData as well, which offers the advantage of
comment|// being stored away from the chunk itself, but accessing it was costly as
comment|// well. The header will be atomically loaded and stored.
typedef|typedef
name|u64
name|PackedHeader
typedef|;
struct|struct
name|UnpackedHeader
block|{
name|u64
name|Checksum
range|:
literal|16
decl_stmt|;
name|u64
name|SizeOrUnusedBytes
range|:
literal|19
decl_stmt|;
comment|// Size for Primary backed allocations, amount of
comment|// unused bytes in the chunk for Secondary ones.
name|u64
name|FromPrimary
range|:
literal|1
decl_stmt|;
name|u64
name|State
range|:
literal|2
decl_stmt|;
comment|// available, allocated, or quarantined
name|u64
name|AllocType
range|:
literal|2
decl_stmt|;
comment|// malloc, new, new[], or memalign
name|u64
name|Offset
range|:
literal|16
decl_stmt|;
comment|// Offset from the beginning of the backend
comment|// allocation to the beginning of the chunk
comment|// itself, in multiples of MinAlignment. See
comment|/// comment about its maximum value and in init().
name|u64
name|Salt
range|:
literal|8
decl_stmt|;
block|}
struct|;
typedef|typedef
name|atomic_uint64_t
name|AtomicPackedHeader
typedef|;
name|COMPILER_CHECK
argument_list|(
sizeof|sizeof
argument_list|(
name|UnpackedHeader
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|PackedHeader
argument_list|)
argument_list|)
expr_stmt|;
comment|// Minimum alignment of 8 bytes for 32-bit, 16 for 64-bit
specifier|const
name|uptr
name|MinAlignmentLog
init|=
name|FIRST_32_SECOND_64
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|)
decl_stmt|;
specifier|const
name|uptr
name|MaxAlignmentLog
init|=
literal|24
decl_stmt|;
comment|// 16 MB
specifier|const
name|uptr
name|MinAlignment
init|=
literal|1
operator|<<
name|MinAlignmentLog
decl_stmt|;
specifier|const
name|uptr
name|MaxAlignment
init|=
literal|1
operator|<<
name|MaxAlignmentLog
decl_stmt|;
specifier|const
name|uptr
name|ChunkHeaderSize
init|=
sizeof|sizeof
argument_list|(
name|PackedHeader
argument_list|)
decl_stmt|;
specifier|const
name|uptr
name|AlignedChunkHeaderSize
init|=
operator|(
name|ChunkHeaderSize
operator|+
name|MinAlignment
operator|-
literal|1
operator|)
operator|&
operator|~
operator|(
name|MinAlignment
operator|-
literal|1
operator|)
decl_stmt|;
struct|struct
name|AllocatorOptions
block|{
name|u32
name|QuarantineSizeMb
decl_stmt|;
name|u32
name|ThreadLocalQuarantineSizeKb
decl_stmt|;
name|bool
name|MayReturnNull
decl_stmt|;
name|s32
name|ReleaseToOSIntervalMs
decl_stmt|;
name|bool
name|DeallocationTypeMismatch
decl_stmt|;
name|bool
name|DeleteSizeMismatch
decl_stmt|;
name|bool
name|ZeroContents
decl_stmt|;
name|void
name|setFrom
parameter_list|(
specifier|const
name|Flags
modifier|*
name|f
parameter_list|,
specifier|const
name|CommonFlags
modifier|*
name|cf
parameter_list|)
function_decl|;
name|void
name|copyTo
argument_list|(
name|Flags
operator|*
name|f
argument_list|,
name|CommonFlags
operator|*
name|cf
argument_list|)
decl|const
decl_stmt|;
block|}
struct|;
name|void
name|initAllocator
parameter_list|(
specifier|const
name|AllocatorOptions
modifier|&
name|options
parameter_list|)
function_decl|;
name|void
name|drainQuarantine
parameter_list|()
function_decl|;
name|void
modifier|*
name|scudoMalloc
parameter_list|(
name|uptr
name|Size
parameter_list|,
name|AllocType
name|Type
parameter_list|)
function_decl|;
name|void
name|scudoFree
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|,
name|AllocType
name|Type
parameter_list|)
function_decl|;
name|void
name|scudoSizedFree
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|,
name|uptr
name|Size
parameter_list|,
name|AllocType
name|Type
parameter_list|)
function_decl|;
name|void
modifier|*
name|scudoRealloc
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|,
name|uptr
name|Size
parameter_list|)
function_decl|;
name|void
modifier|*
name|scudoCalloc
parameter_list|(
name|uptr
name|NMemB
parameter_list|,
name|uptr
name|Size
parameter_list|)
function_decl|;
name|void
modifier|*
name|scudoMemalign
parameter_list|(
name|uptr
name|Alignment
parameter_list|,
name|uptr
name|Size
parameter_list|)
function_decl|;
name|void
modifier|*
name|scudoValloc
parameter_list|(
name|uptr
name|Size
parameter_list|)
function_decl|;
name|void
modifier|*
name|scudoPvalloc
parameter_list|(
name|uptr
name|Size
parameter_list|)
function_decl|;
name|int
name|scudoPosixMemalign
parameter_list|(
name|void
modifier|*
modifier|*
name|MemPtr
parameter_list|,
name|uptr
name|Alignment
parameter_list|,
name|uptr
name|Size
parameter_list|)
function_decl|;
name|void
modifier|*
name|scudoAlignedAlloc
parameter_list|(
name|uptr
name|Alignment
parameter_list|,
name|uptr
name|Size
parameter_list|)
function_decl|;
name|uptr
name|scudoMallocUsableSize
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|)
function_decl|;
include|#
directive|include
file|"scudo_allocator_secondary.h"
block|}
end_decl_stmt

begin_comment
comment|// namespace __scudo
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SCUDO_ALLOCATOR_H_
end_comment

end_unit

