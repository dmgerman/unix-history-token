begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=-- lsan_allocator.h ----------------------------------------------------===//
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
comment|// This file is a part of LeakSanitizer.
end_comment

begin_comment
comment|// Allocator for standalone LSan.
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
name|LSAN_ALLOCATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LSAN_ALLOCATOR_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_common.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_internal_defs.h"
end_include

begin_decl_stmt
name|namespace
name|__lsan
block|{
name|void
modifier|*
name|Allocate
parameter_list|(
specifier|const
name|StackTrace
modifier|&
name|stack
parameter_list|,
name|uptr
name|size
parameter_list|,
name|uptr
name|alignment
parameter_list|,
name|bool
name|cleared
parameter_list|)
function_decl|;
name|void
name|Deallocate
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
name|void
modifier|*
name|Reallocate
parameter_list|(
specifier|const
name|StackTrace
modifier|&
name|stack
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
function_decl|;
name|uptr
name|GetMallocUsableSize
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
name|template
operator|<
name|typename
name|Callable
operator|>
name|void
name|ForEachChunk
argument_list|(
specifier|const
name|Callable
operator|&
name|callback
argument_list|)
expr_stmt|;
name|void
name|GetAllocatorCacheRange
parameter_list|(
name|uptr
modifier|*
name|begin
parameter_list|,
name|uptr
modifier|*
name|end
parameter_list|)
function_decl|;
name|void
name|AllocatorThreadFinish
parameter_list|()
function_decl|;
name|void
name|InitializeAllocator
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __lsan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LSAN_ALLOCATOR_H
end_comment

end_unit

