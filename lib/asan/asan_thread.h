begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_thread.h -------------------------------------------*- C++ -*-===//
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
comment|// ASan-private header for asan_thread.cc.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_THREAD_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_THREAD_H
end_define

begin_include
include|#
directive|include
file|"asan_allocator.h"
end_include

begin_include
include|#
directive|include
file|"asan_internal.h"
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

begin_decl_stmt
name|namespace
name|__asan
block|{
specifier|const
name|size_t
name|kMaxThreadStackSize
init|=
literal|16
operator|*
operator|(
literal|1
operator|<<
literal|20
operator|)
decl_stmt|;
comment|// 16M
name|class
name|AsanThread
decl_stmt|;
comment|// These objects are created for every thread and are never deleted,
comment|// so we can find them by tid even if the thread is long dead.
name|class
name|AsanThreadSummary
block|{
name|public
label|:
name|explicit
name|AsanThreadSummary
parameter_list|(
name|LinkerInitialized
parameter_list|)
block|{ }
comment|// for T0.
name|AsanThreadSummary
argument_list|(
argument|int tid
argument_list|,
argument|int parent_tid
argument_list|,
argument|AsanStackTrace *stack
argument_list|)
block|:
name|tid_
argument_list|(
name|tid
argument_list|)
operator|,
name|parent_tid_
argument_list|(
name|parent_tid
argument_list|)
operator|,
name|announced_
argument_list|(
argument|false
argument_list|)
block|{
if|if
condition|(
name|stack
condition|)
block|{
name|stack_
operator|=
operator|*
name|stack
expr_stmt|;
block|}
name|thread_
operator|=
literal|0
expr_stmt|;
block|}
name|void
name|Announce
parameter_list|()
block|{
if|if
condition|(
name|tid_
operator|==
literal|0
condition|)
return|return;
comment|// no need to announce the main thread.
if|if
condition|(
operator|!
name|announced_
condition|)
block|{
name|announced_
operator|=
name|true
expr_stmt|;
name|Printf
argument_list|(
literal|"Thread T%d created by T%d here:\n"
argument_list|,
name|tid_
argument_list|,
name|parent_tid_
argument_list|)
expr_stmt|;
name|stack_
operator|.
name|PrintStack
argument_list|()
expr_stmt|;
block|}
block|}
name|int
name|tid
parameter_list|()
block|{
return|return
name|tid_
return|;
block|}
name|AsanThread
modifier|*
name|thread
parameter_list|()
block|{
return|return
name|thread_
return|;
block|}
name|void
name|set_thread
parameter_list|(
name|AsanThread
modifier|*
name|thread
parameter_list|)
block|{
name|thread_
operator|=
name|thread
expr_stmt|;
block|}
name|private
label|:
name|int
name|tid_
decl_stmt|;
name|int
name|parent_tid_
decl_stmt|;
name|bool
name|announced_
decl_stmt|;
name|AsanStackTrace
name|stack_
decl_stmt|;
name|AsanThread
modifier|*
name|thread_
decl_stmt|;
block|}
empty_stmt|;
comment|// AsanThread are stored in TSD and destroyed when the thread dies.
name|class
name|AsanThread
block|{
name|public
label|:
name|explicit
name|AsanThread
parameter_list|(
name|LinkerInitialized
parameter_list|)
function_decl|;
comment|// for T0.
name|AsanThread
argument_list|(
argument|int parent_tid
argument_list|,
argument|void *(*start_routine) (void *)
argument_list|,
argument|void *arg
argument_list|,
argument|AsanStackTrace *stack
argument_list|)
empty_stmt|;
operator|~
name|AsanThread
argument_list|()
expr_stmt|;
name|void
name|Init
parameter_list|()
function_decl|;
comment|// Should be called from the thread itself.
name|void
modifier|*
name|ThreadStart
parameter_list|()
function_decl|;
name|uintptr_t
name|stack_top
parameter_list|()
block|{
return|return
name|stack_top_
return|;
block|}
name|uintptr_t
name|stack_bottom
parameter_list|()
block|{
return|return
name|stack_bottom_
return|;
block|}
name|size_t
name|stack_size
parameter_list|()
block|{
return|return
name|stack_top_
operator|-
name|stack_bottom_
return|;
block|}
name|int
name|tid
parameter_list|()
block|{
return|return
name|summary_
operator|->
name|tid
argument_list|()
return|;
block|}
name|AsanThreadSummary
modifier|*
name|summary
parameter_list|()
block|{
return|return
name|summary_
return|;
block|}
name|void
name|set_summary
parameter_list|(
name|AsanThreadSummary
modifier|*
name|summary
parameter_list|)
block|{
name|summary_
operator|=
name|summary
expr_stmt|;
block|}
specifier|const
name|char
modifier|*
name|GetFrameNameByAddr
parameter_list|(
name|uintptr_t
name|addr
parameter_list|,
name|uintptr_t
modifier|*
name|offset
parameter_list|)
function_decl|;
name|bool
name|AddrIsInStack
parameter_list|(
name|uintptr_t
name|addr
parameter_list|)
block|{
return|return
name|addr
operator|>=
name|stack_bottom_
operator|&&
name|addr
operator|<
name|stack_top_
return|;
block|}
name|FakeStack
modifier|&
name|fake_stack
parameter_list|()
block|{
return|return
name|fake_stack_
return|;
block|}
name|AsanThreadLocalMallocStorage
modifier|&
name|malloc_storage
parameter_list|()
block|{
return|return
name|malloc_storage_
return|;
block|}
name|AsanStats
modifier|&
name|stats
parameter_list|()
block|{
return|return
name|stats_
return|;
block|}
specifier|static
specifier|const
name|int
name|kInvalidTid
init|=
operator|-
literal|1
decl_stmt|;
name|private
label|:
name|void
name|SetThreadStackTopAndBottom
parameter_list|()
function_decl|;
name|void
name|ClearShadowForThreadStack
parameter_list|()
function_decl|;
name|AsanThreadSummary
modifier|*
name|summary_
decl_stmt|;
name|void
modifier|*
function_decl|(
modifier|*
name|start_routine_
function_decl|)
parameter_list|(
name|void
modifier|*
name|param
parameter_list|)
function_decl|;
name|void
modifier|*
name|arg_
decl_stmt|;
name|uintptr_t
name|stack_top_
decl_stmt|;
name|uintptr_t
name|stack_bottom_
decl_stmt|;
name|FakeStack
name|fake_stack_
decl_stmt|;
name|AsanThreadLocalMallocStorage
name|malloc_storage_
decl_stmt|;
name|AsanStats
name|stats_
decl_stmt|;
block|}
empty_stmt|;
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
comment|// ASAN_THREAD_H
end_comment

end_unit

