begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_thread_registry.h -----------------------------*- C++ -*-===//
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
comment|// This file is shared between sanitizer tools.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// General thread bookkeeping functionality.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_THREAD_REGISTRY_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_THREAD_REGISTRY_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common.h"
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

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
enum|enum
name|ThreadStatus
block|{
name|ThreadStatusInvalid
block|,
comment|// Non-existent thread, data is invalid.
name|ThreadStatusCreated
block|,
comment|// Created but not yet running.
name|ThreadStatusRunning
block|,
comment|// The thread is currently running.
name|ThreadStatusFinished
block|,
comment|// Joinable thread is finished but not yet joined.
name|ThreadStatusDead
comment|// Joined, but some info is still available.
block|}
enum|;
comment|// Generic thread context. Specific sanitizer tools may inherit from it.
comment|// If thread is dead, context may optionally be reused for a new thread.
name|class
name|ThreadContextBase
block|{
name|public
label|:
name|explicit
name|ThreadContextBase
parameter_list|(
name|u32
name|tid
parameter_list|)
function_decl|;
operator|~
name|ThreadContextBase
argument_list|()
expr_stmt|;
comment|// Should never be called.
specifier|const
name|u32
name|tid
decl_stmt|;
comment|// Thread ID. Main thread should have tid = 0.
name|u64
name|unique_id
decl_stmt|;
comment|// Unique thread ID.
name|u32
name|reuse_count
decl_stmt|;
comment|// Number of times this tid was reused.
name|tid_t
name|os_id
decl_stmt|;
comment|// PID (used for reporting).
name|uptr
name|user_id
decl_stmt|;
comment|// Some opaque user thread id (e.g. pthread_t).
name|char
name|name
index|[
literal|64
index|]
decl_stmt|;
comment|// As annotated by user.
name|ThreadStatus
name|status
decl_stmt|;
name|bool
name|detached
decl_stmt|;
name|bool
name|workerthread
decl_stmt|;
name|u32
name|parent_tid
decl_stmt|;
name|ThreadContextBase
modifier|*
name|next
decl_stmt|;
comment|// For storing thread contexts in a list.
name|void
name|SetName
parameter_list|(
specifier|const
name|char
modifier|*
name|new_name
parameter_list|)
function_decl|;
name|void
name|SetDead
parameter_list|()
function_decl|;
name|void
name|SetJoined
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
name|SetFinished
parameter_list|()
function_decl|;
name|void
name|SetStarted
parameter_list|(
name|tid_t
name|_os_id
parameter_list|,
name|bool
name|_workerthread
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
name|SetCreated
parameter_list|(
name|uptr
name|_user_id
parameter_list|,
name|u64
name|_unique_id
parameter_list|,
name|bool
name|_detached
parameter_list|,
name|u32
name|_parent_tid
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
name|Reset
parameter_list|()
function_decl|;
comment|// The following methods may be overriden by subclasses.
comment|// Some of them take opaque arg that may be optionally be used
comment|// by subclasses.
name|virtual
name|void
name|OnDead
parameter_list|()
block|{}
name|virtual
name|void
name|OnJoined
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{}
name|virtual
name|void
name|OnFinished
parameter_list|()
block|{}
name|virtual
name|void
name|OnStarted
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{}
name|virtual
name|void
name|OnCreated
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{}
name|virtual
name|void
name|OnReset
parameter_list|()
block|{}
name|virtual
name|void
name|OnDetached
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{}
block|}
empty_stmt|;
typedef|typedef
name|ThreadContextBase
modifier|*
function_decl|(
modifier|*
name|ThreadContextFactory
function_decl|)
parameter_list|(
name|u32
name|tid
parameter_list|)
function_decl|;
name|class
name|ThreadRegistry
block|{
name|public
label|:
specifier|static
specifier|const
name|u32
name|kUnknownTid
decl_stmt|;
name|ThreadRegistry
argument_list|(
argument|ThreadContextFactory factory
argument_list|,
argument|u32 max_threads
argument_list|,
argument|u32 thread_quarantine_size
argument_list|,
argument|u32 max_reuse =
literal|0
argument_list|)
empty_stmt|;
name|void
name|GetNumberOfThreads
parameter_list|(
name|uptr
modifier|*
name|total
init|=
name|nullptr
parameter_list|,
name|uptr
modifier|*
name|running
init|=
name|nullptr
parameter_list|,
name|uptr
modifier|*
name|alive
init|=
name|nullptr
parameter_list|)
function_decl|;
name|uptr
name|GetMaxAliveThreads
parameter_list|()
function_decl|;
name|void
name|Lock
parameter_list|()
block|{
name|mtx_
operator|.
name|Lock
argument_list|()
expr_stmt|;
block|}
name|void
name|CheckLocked
parameter_list|()
block|{
name|mtx_
operator|.
name|CheckLocked
argument_list|()
expr_stmt|;
block|}
name|void
name|Unlock
parameter_list|()
block|{
name|mtx_
operator|.
name|Unlock
argument_list|()
expr_stmt|;
block|}
comment|// Should be guarded by ThreadRegistryLock.
name|ThreadContextBase
modifier|*
name|GetThreadLocked
parameter_list|(
name|u32
name|tid
parameter_list|)
block|{
name|DCHECK_LT
argument_list|(
name|tid
argument_list|,
name|n_contexts_
argument_list|)
expr_stmt|;
return|return
name|threads_
index|[
name|tid
index|]
return|;
block|}
name|u32
name|CreateThread
parameter_list|(
name|uptr
name|user_id
parameter_list|,
name|bool
name|detached
parameter_list|,
name|u32
name|parent_tid
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|ThreadCallback
function_decl|)
parameter_list|(
name|ThreadContextBase
modifier|*
name|tctx
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|// Invokes callback with a specified arg for each thread context.
comment|// Should be guarded by ThreadRegistryLock.
name|void
name|RunCallbackForEachThreadLocked
parameter_list|(
name|ThreadCallback
name|cb
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
typedef|typedef
name|bool
function_decl|(
modifier|*
name|FindThreadCallback
function_decl|)
parameter_list|(
name|ThreadContextBase
modifier|*
name|tctx
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|// Finds a thread using the provided callback. Returns kUnknownTid if no
comment|// thread is found.
name|u32
name|FindThread
parameter_list|(
name|FindThreadCallback
name|cb
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|// Should be guarded by ThreadRegistryLock. Return 0 if no thread
comment|// is found.
name|ThreadContextBase
modifier|*
name|FindThreadContextLocked
parameter_list|(
name|FindThreadCallback
name|cb
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|ThreadContextBase
modifier|*
name|FindThreadContextByOsIDLocked
parameter_list|(
name|tid_t
name|os_id
parameter_list|)
function_decl|;
name|void
name|SetThreadName
parameter_list|(
name|u32
name|tid
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|void
name|SetThreadNameByUserId
parameter_list|(
name|uptr
name|user_id
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|void
name|DetachThread
parameter_list|(
name|u32
name|tid
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
name|JoinThread
parameter_list|(
name|u32
name|tid
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
name|FinishThread
parameter_list|(
name|u32
name|tid
parameter_list|)
function_decl|;
name|void
name|StartThread
parameter_list|(
name|u32
name|tid
parameter_list|,
name|tid_t
name|os_id
parameter_list|,
name|bool
name|workerthread
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|private
label|:
specifier|const
name|ThreadContextFactory
name|context_factory_
decl_stmt|;
specifier|const
name|u32
name|max_threads_
decl_stmt|;
specifier|const
name|u32
name|thread_quarantine_size_
decl_stmt|;
specifier|const
name|u32
name|max_reuse_
decl_stmt|;
name|BlockingMutex
name|mtx_
decl_stmt|;
name|u32
name|n_contexts_
decl_stmt|;
comment|// Number of created thread contexts,
comment|// at most max_threads_.
name|u64
name|total_threads_
decl_stmt|;
comment|// Total number of created threads. May be greater than
comment|// max_threads_ if contexts were reused.
name|uptr
name|alive_threads_
decl_stmt|;
comment|// Created or running.
name|uptr
name|max_alive_threads_
decl_stmt|;
name|uptr
name|running_threads_
decl_stmt|;
name|ThreadContextBase
modifier|*
modifier|*
name|threads_
decl_stmt|;
comment|// Array of thread contexts is leaked.
name|IntrusiveList
operator|<
name|ThreadContextBase
operator|>
name|dead_threads_
expr_stmt|;
name|IntrusiveList
operator|<
name|ThreadContextBase
operator|>
name|invalid_threads_
expr_stmt|;
name|void
name|QuarantinePush
parameter_list|(
name|ThreadContextBase
modifier|*
name|tctx
parameter_list|)
function_decl|;
name|ThreadContextBase
modifier|*
name|QuarantinePop
parameter_list|()
function_decl|;
block|}
empty_stmt|;
typedef|typedef
name|GenericScopedLock
operator|<
name|ThreadRegistry
operator|>
name|ThreadRegistryLock
expr_stmt|;
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
comment|// SANITIZER_THREAD_REGISTRY_H
end_comment

end_unit

