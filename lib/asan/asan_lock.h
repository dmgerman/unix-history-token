begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_lock.h ---------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of AddressSanitizer, an address sanity checker.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A wrapper for a simple lock.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_LOCK_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_LOCK_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_mutex.h"
end_include

begin_include
include|#
directive|include
file|"asan_internal.h"
end_include

begin_comment
comment|// The locks in ASan are global objects and they are never destroyed to avoid
end_comment

begin_comment
comment|// at-exit races (that is, a lock is being used by other threads while the main
end_comment

begin_comment
comment|// thread is doing atexit destructors).
end_comment

begin_comment
comment|// We define the class using opaque storage to avoid including system headers.
end_comment

begin_decl_stmt
name|namespace
name|__asan
block|{
name|class
name|AsanLock
block|{
name|public
label|:
name|explicit
name|AsanLock
parameter_list|(
name|LinkerInitialized
parameter_list|)
function_decl|;
name|void
name|Lock
parameter_list|()
function_decl|;
name|void
name|Unlock
parameter_list|()
function_decl|;
name|bool
name|IsLocked
parameter_list|()
block|{
return|return
name|owner_
operator|!=
literal|0
return|;
block|}
name|private
label|:
name|uptr
name|opaque_storage_
index|[
literal|10
index|]
decl_stmt|;
name|uptr
name|owner_
decl_stmt|;
comment|// for debugging and for malloc_introspection_t interface
block|}
empty_stmt|;
typedef|typedef
name|GenericScopedLock
operator|<
name|AsanLock
operator|>
name|ScopedLock
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __asan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_LOCK_H
end_comment

end_unit

