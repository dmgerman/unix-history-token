begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- msan_allocator.h ----------------------------------------*- C++ -*-===//
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
comment|// This file is a part of MemorySanitizer.
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
name|MSAN_ALLOCATOR_H
end_ifndef

begin_define
define|#
directive|define
name|MSAN_ALLOCATOR_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_common.h"
end_include

begin_decl_stmt
name|namespace
name|__msan
block|{
struct|struct
name|MsanThreadLocalMallocStorage
block|{
name|uptr
name|quarantine_cache
index|[
literal|16
index|]
decl_stmt|;
comment|// Allocator cache contains atomic_uint64_t which must be 8-byte aligned.
name|ALIGNED
argument_list|(
literal|8
argument_list|)
name|uptr
name|allocator_cache
index|[
literal|96
operator|*
operator|(
literal|512
operator|*
literal|8
operator|+
literal|16
operator|)
index|]
decl_stmt|;
comment|// Opaque.
name|void
name|CommitBack
parameter_list|()
function_decl|;
name|private
label|:
comment|// These objects are allocated via mmap() and are zero-initialized.
name|MsanThreadLocalMallocStorage
argument_list|()
block|{}
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __msan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// MSAN_ALLOCATOR_H
end_comment

end_unit

