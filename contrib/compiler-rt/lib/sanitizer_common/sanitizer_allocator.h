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
comment|// Since flags are immutable and allocator behavior can be changed at runtime
comment|// (unit tests or ASan on Android are some examples), allocator_may_return_null
comment|// flag value is cached here and can be altered later.
name|bool
name|AllocatorMayReturnNull
parameter_list|()
function_decl|;
name|void
name|SetAllocatorMayReturnNull
parameter_list|(
name|bool
name|may_return_null
parameter_list|)
function_decl|;
comment|// Allocator failure handling policies:
comment|// Implements AllocatorMayReturnNull policy, returns null when the flag is set,
comment|// dies otherwise.
struct|struct
name|ReturnNullOrDieOnFailure
block|{
specifier|static
name|void
modifier|*
name|OnBadRequest
parameter_list|()
function_decl|;
specifier|static
name|void
modifier|*
name|OnOOM
parameter_list|()
function_decl|;
block|}
struct|;
comment|// Always dies on the failure.
struct|struct
name|DieOnFailure
block|{
specifier|static
name|void
name|NORETURN
modifier|*
name|OnBadRequest
parameter_list|()
function_decl|;
specifier|static
name|void
name|NORETURN
modifier|*
name|OnOOM
parameter_list|()
function_decl|;
block|}
struct|;
comment|// Returns true if allocator detected OOM condition. Can be used to avoid memory
comment|// hungry operations. Set when AllocatorReturnNullOrDieOnOOM() is called.
name|bool
name|IsAllocatorOutOfMemory
parameter_list|()
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

