begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/System/Threading.h - Control multithreading mode --*- C++ -*-===//
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
comment|// TThis file defines llvm_start_multithreaded() and friends.
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
name|LLVM_SYSTEM_THREADING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SYSTEM_THREADING_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// llvm_start_multithreaded - Allocate and initialize structures needed to
comment|/// make LLVM safe for multithreading.  The return value indicates whether
comment|/// multithreaded initialization succeeded.  LLVM will still be operational
comment|/// on "failed" return, and will still be safe for hosting threading
comment|/// applications in the JIT, but will not be safe for concurrent calls to the
comment|/// LLVM APIs.
comment|/// THIS MUST EXECUTE IN ISOLATION FROM ALL OTHER LLVM API CALLS.
name|bool
name|llvm_start_multithreaded
parameter_list|()
function_decl|;
comment|/// llvm_stop_multithreaded - Deallocate structures necessary to make LLVM
comment|/// safe for multithreading.
comment|/// THIS MUST EXECUTE IN ISOLATION FROM ALL OTHER LLVM API CALLS.
name|void
name|llvm_stop_multithreaded
parameter_list|()
function_decl|;
comment|/// llvm_is_multithreaded - Check whether LLVM is executing in thread-safe
comment|/// mode or not.
name|bool
name|llvm_is_multithreaded
parameter_list|()
function_decl|;
comment|/// acquire_global_lock - Acquire the global lock.  This is a no-op if called
comment|/// before llvm_start_multithreaded().
name|void
name|llvm_acquire_global_lock
parameter_list|()
function_decl|;
comment|/// release_global_lock - Release the global lock.  This is a no-op if called
comment|/// before llvm_start_multithreaded().
name|void
name|llvm_release_global_lock
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

