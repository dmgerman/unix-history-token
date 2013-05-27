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
file|"asan_fake_stack.h"
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
file|"sanitizer_common/sanitizer_libc.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_thread_registry.h"
end_include

begin_decl_stmt
name|namespace
name|__asan
block|{
specifier|const
name|u32
name|kInvalidTid
init|=
literal|0xffffff
decl_stmt|;
comment|// Must fit into 24 bits.
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
name|class
name|AsanThread
decl_stmt|;
comment|// These objects are created for every thread and are never deleted,
comment|// so we can find them by tid even if the thread is long dead.
name|class
name|AsanThreadContext
range|:
name|public
name|ThreadContextBase
block|{
name|public
operator|:
name|explicit
name|AsanThreadContext
argument_list|(
argument|int tid
argument_list|)
operator|:
name|ThreadContextBase
argument_list|(
name|tid
argument_list|)
block|,
name|announced
argument_list|(
name|false
argument_list|)
block|,
name|thread
argument_list|(
literal|0
argument_list|)
block|{
name|internal_memset
argument_list|(
operator|&
name|stack
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|stack
argument_list|)
argument_list|)
block|;   }
name|bool
name|announced
block|;
name|StackTrace
name|stack
block|;
name|AsanThread
operator|*
name|thread
block|;
name|void
name|OnCreated
argument_list|(
name|void
operator|*
name|arg
argument_list|)
block|;
name|void
name|OnFinished
argument_list|()
block|; }
decl_stmt|;
comment|// AsanThreadContext objects are never freed, so we need many of them.
name|COMPILER_CHECK
argument_list|(
sizeof|sizeof
argument_list|(
name|AsanThreadContext
argument_list|)
operator|<=
literal|4096
argument_list|)
expr_stmt|;
comment|// AsanThread are stored in TSD and destroyed when the thread dies.
name|class
name|AsanThread
block|{
name|public
label|:
specifier|static
name|AsanThread
modifier|*
name|Create
parameter_list|(
name|thread_callback_t
name|start_routine
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
specifier|static
name|void
name|TSDDtor
parameter_list|(
name|void
modifier|*
name|tsd
parameter_list|)
function_decl|;
name|void
name|Destroy
parameter_list|()
function_decl|;
name|void
name|Init
parameter_list|()
function_decl|;
comment|// Should be called from the thread itself.
name|thread_return_t
name|ThreadStart
parameter_list|(
name|uptr
name|os_id
parameter_list|)
function_decl|;
name|uptr
name|stack_top
parameter_list|()
block|{
return|return
name|stack_top_
return|;
block|}
name|uptr
name|stack_bottom
parameter_list|()
block|{
return|return
name|stack_bottom_
return|;
block|}
name|uptr
name|stack_size
parameter_list|()
block|{
return|return
name|stack_top_
operator|-
name|stack_bottom_
return|;
block|}
name|u32
name|tid
parameter_list|()
block|{
return|return
name|context_
operator|->
name|tid
return|;
block|}
name|AsanThreadContext
modifier|*
name|context
parameter_list|()
block|{
return|return
name|context_
return|;
block|}
name|void
name|set_context
parameter_list|(
name|AsanThreadContext
modifier|*
name|context
parameter_list|)
block|{
name|context_
operator|=
name|context
expr_stmt|;
block|}
specifier|const
name|char
modifier|*
name|GetFrameNameByAddr
parameter_list|(
name|uptr
name|addr
parameter_list|,
name|uptr
modifier|*
name|offset
parameter_list|,
name|uptr
modifier|*
name|frame_pc
parameter_list|)
function_decl|;
name|bool
name|AddrIsInStack
parameter_list|(
name|uptr
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
name|private
label|:
name|AsanThread
argument_list|()
block|{}
name|void
name|SetThreadStackTopAndBottom
parameter_list|()
function_decl|;
name|void
name|ClearShadowForThreadStack
parameter_list|()
function_decl|;
name|AsanThreadContext
modifier|*
name|context_
decl_stmt|;
name|thread_callback_t
name|start_routine_
decl_stmt|;
name|void
modifier|*
name|arg_
decl_stmt|;
name|uptr
name|stack_top_
decl_stmt|;
name|uptr
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
struct|struct
name|CreateThreadContextArgs
block|{
name|AsanThread
modifier|*
name|thread
decl_stmt|;
name|StackTrace
modifier|*
name|stack
decl_stmt|;
block|}
struct|;
comment|// Returns a single instance of registry.
name|ThreadRegistry
modifier|&
name|asanThreadRegistry
parameter_list|()
function_decl|;
comment|// Must be called under ThreadRegistryLock.
name|AsanThreadContext
modifier|*
name|GetThreadContextByTidLocked
parameter_list|(
name|u32
name|tid
parameter_list|)
function_decl|;
comment|// Get the current thread. May return 0.
name|AsanThread
modifier|*
name|GetCurrentThread
parameter_list|()
function_decl|;
name|void
name|SetCurrentThread
parameter_list|(
name|AsanThread
modifier|*
name|t
parameter_list|)
function_decl|;
name|u32
name|GetCurrentTidOrInvalid
parameter_list|()
function_decl|;
name|AsanThread
modifier|*
name|FindThreadByStackAddress
parameter_list|(
name|uptr
name|addr
parameter_list|)
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
comment|// ASAN_THREAD_H
end_comment

end_unit

