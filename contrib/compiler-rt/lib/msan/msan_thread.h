begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- msan_thread.h -------------------------------------------*- C++ -*-===//
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
name|MSAN_THREAD_H
end_ifndef

begin_define
define|#
directive|define
name|MSAN_THREAD_H
end_define

begin_include
include|#
directive|include
file|"msan_allocator.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_common.h"
end_include

begin_decl_stmt
name|namespace
name|__msan
block|{
name|class
name|MsanThread
block|{
name|public
label|:
specifier|static
name|MsanThread
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
parameter_list|()
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
name|tls_begin
parameter_list|()
block|{
return|return
name|tls_begin_
return|;
block|}
name|uptr
name|tls_end
parameter_list|()
block|{
return|return
name|tls_end_
return|;
block|}
name|bool
name|IsMainThread
parameter_list|()
block|{
return|return
name|start_routine_
operator|==
literal|0
return|;
block|}
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
name|bool
name|InSignalHandler
parameter_list|()
block|{
return|return
name|in_signal_handler_
return|;
block|}
name|void
name|EnterSignalHandler
parameter_list|()
block|{
name|in_signal_handler_
operator|++
expr_stmt|;
block|}
name|void
name|LeaveSignalHandler
parameter_list|()
block|{
name|in_signal_handler_
operator|--
expr_stmt|;
block|}
name|MsanThreadLocalMallocStorage
modifier|&
name|malloc_storage
parameter_list|()
block|{
return|return
name|malloc_storage_
return|;
block|}
name|int
name|destructor_iterations_
decl_stmt|;
name|private
label|:
comment|// NOTE: There is no MsanThread constructor. It is allocated
comment|// via mmap() and *must* be valid in zero-initialized state.
name|void
name|SetThreadStackAndTls
parameter_list|()
function_decl|;
name|void
name|ClearShadowForThreadStackAndTLS
parameter_list|()
function_decl|;
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
name|uptr
name|tls_begin_
decl_stmt|;
name|uptr
name|tls_end_
decl_stmt|;
name|unsigned
name|in_signal_handler_
decl_stmt|;
name|MsanThreadLocalMallocStorage
name|malloc_storage_
decl_stmt|;
block|}
empty_stmt|;
name|MsanThread
modifier|*
name|GetCurrentThread
parameter_list|()
function_decl|;
name|void
name|SetCurrentThread
parameter_list|(
name|MsanThread
modifier|*
name|t
parameter_list|)
function_decl|;
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
comment|// MSAN_THREAD_H
end_comment

end_unit

