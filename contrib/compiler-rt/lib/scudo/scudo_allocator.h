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

begin_ifndef
ifndef|#
directive|ifndef
name|__x86_64__
end_ifndef

begin_error
error|#
directive|error
literal|"The Scudo hardened allocator currently only supports x86_64."
end_error

begin_endif
endif|#
directive|endif
end_endif

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

