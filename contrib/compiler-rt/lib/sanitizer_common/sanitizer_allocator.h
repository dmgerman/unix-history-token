begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_allocator.h -----------------------------------*- C++ -*-===//
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
comment|// Specialized memory allocator for ThreadSanitizer, MemorySanitizer, etc.
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

begin_define
define|#
directive|define
name|SANITIZER_ALLOCATOR_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_libc.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_list.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_mutex.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_lfstack.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_procmaps.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
comment|// Returns true if ReportAllocatorCannotReturnNull(true) was called.
comment|// Can be use to avoid memory hungry operations.
name|bool
name|IsReportingOOM
parameter_list|()
function_decl|;
comment|// Prints error message and kills the program.
name|void
name|NORETURN
name|ReportAllocatorCannotReturnNull
parameter_list|(
name|bool
name|out_of_memory
parameter_list|)
function_decl|;
comment|// Allocators call these callbacks on mmap/munmap.
struct|struct
name|NoOpMapUnmapCallback
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
block|{ }
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
block|{ }
block|}
struct|;
comment|// Callback type for iterating over chunks.
typedef|typedef
name|void
function_decl|(
modifier|*
name|ForEachChunkCallback
function_decl|)
parameter_list|(
name|uptr
name|chunk
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|// Returns true if calloc(size, n) should return 0 due to overflow in size*n.
name|bool
name|CallocShouldReturnNullDueToOverflow
parameter_list|(
name|uptr
name|size
parameter_list|,
name|uptr
name|n
parameter_list|)
function_decl|;
include|#
directive|include
file|"sanitizer_allocator_size_class_map.h"
include|#
directive|include
file|"sanitizer_allocator_stats.h"
include|#
directive|include
file|"sanitizer_allocator_primary64.h"
include|#
directive|include
file|"sanitizer_allocator_bytemap.h"
include|#
directive|include
file|"sanitizer_allocator_primary32.h"
include|#
directive|include
file|"sanitizer_allocator_local_cache.h"
include|#
directive|include
file|"sanitizer_allocator_secondary.h"
include|#
directive|include
file|"sanitizer_allocator_combined.h"
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
comment|// SANITIZER_ALLOCATOR_H
end_comment

end_unit

