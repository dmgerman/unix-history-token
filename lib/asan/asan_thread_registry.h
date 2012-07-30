begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_thread_registry.h ----------------------------------*- C++ -*-===//
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
comment|// ASan-private header for asan_thread_registry.cc
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_THREAD_REGISTRY_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_THREAD_REGISTRY_H
end_define

begin_include
include|#
directive|include
file|"asan_lock.h"
end_include

begin_include
include|#
directive|include
file|"asan_stack.h"
end_include

begin_include
include|#
directive|include
file|"asan_stats.h"
end_include

begin_include
include|#
directive|include
file|"asan_thread.h"
end_include

begin_decl_stmt
name|namespace
name|__asan
block|{
comment|// Stores summaries of all created threads, returns current thread,
comment|// thread by tid, thread by stack address. There is a single instance
comment|// of AsanThreadRegistry for the whole program.
comment|// AsanThreadRegistry is thread-safe.
name|class
name|AsanThreadRegistry
block|{
name|public
label|:
name|explicit
name|AsanThreadRegistry
parameter_list|(
name|LinkerInitialized
parameter_list|)
function_decl|;
name|void
name|Init
parameter_list|()
function_decl|;
name|void
name|RegisterThread
parameter_list|(
name|AsanThread
modifier|*
name|thread
parameter_list|)
function_decl|;
name|void
name|UnregisterThread
parameter_list|(
name|AsanThread
modifier|*
name|thread
parameter_list|)
function_decl|;
name|AsanThread
modifier|*
name|GetMain
parameter_list|()
function_decl|;
comment|// Get the current thread. May return 0.
name|AsanThread
modifier|*
name|GetCurrent
parameter_list|()
function_decl|;
name|void
name|SetCurrent
parameter_list|(
name|AsanThread
modifier|*
name|t
parameter_list|)
function_decl|;
name|u32
name|GetCurrentTidOrInvalid
parameter_list|()
block|{
if|if
condition|(
operator|!
name|inited_
condition|)
return|return
literal|0
return|;
name|AsanThread
modifier|*
name|t
init|=
name|GetCurrent
argument_list|()
decl_stmt|;
return|return
name|t
condition|?
name|t
operator|->
name|tid
argument_list|()
else|:
name|kInvalidTid
return|;
block|}
comment|// Returns stats for GetCurrent(), or stats for
comment|// T0 if GetCurrent() returns 0.
name|AsanStats
modifier|&
name|GetCurrentThreadStats
parameter_list|()
function_decl|;
comment|// Flushes all thread-local stats to accumulated stats, and returns
comment|// a copy of accumulated stats.
name|AsanStats
name|GetAccumulatedStats
parameter_list|()
function_decl|;
name|uptr
name|GetCurrentAllocatedBytes
parameter_list|()
function_decl|;
name|uptr
name|GetHeapSize
parameter_list|()
function_decl|;
name|uptr
name|GetFreeBytes
parameter_list|()
function_decl|;
name|AsanThreadSummary
modifier|*
name|FindByTid
parameter_list|(
name|u32
name|tid
parameter_list|)
function_decl|;
name|AsanThread
modifier|*
name|FindThreadByStackAddress
parameter_list|(
name|uptr
name|addr
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|UpdateAccumulatedStatsUnlocked
parameter_list|()
function_decl|;
comment|// Adds values of all counters in "stats" to accumulated stats,
comment|// and fills "stats" with zeroes.
name|void
name|FlushToAccumulatedStatsUnlocked
parameter_list|(
name|AsanStats
modifier|*
name|stats
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|u32
name|kMaxNumberOfThreads
init|=
operator|(
literal|1
operator|<<
literal|22
operator|)
decl_stmt|;
comment|// 4M
name|AsanThreadSummary
modifier|*
name|thread_summaries_
index|[
name|kMaxNumberOfThreads
index|]
decl_stmt|;
name|AsanThread
name|main_thread_
decl_stmt|;
name|AsanThreadSummary
name|main_thread_summary_
decl_stmt|;
name|AsanStats
name|accumulated_stats_
decl_stmt|;
name|u32
name|n_threads_
decl_stmt|;
name|AsanLock
name|mu_
decl_stmt|;
name|bool
name|inited_
decl_stmt|;
block|}
empty_stmt|;
comment|// Returns a single instance of registry.
name|AsanThreadRegistry
modifier|&
name|asanThreadRegistry
parameter_list|()
function_decl|;
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
comment|// ASAN_THREAD_REGISTRY_H
end_comment

end_unit

