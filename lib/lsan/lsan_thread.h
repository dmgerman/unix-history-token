begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=-- lsan_thread.h -------------------------------------------------------===//
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
comment|// Thread registry for standalone LSan.
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
name|LSAN_THREAD_H
end_ifndef

begin_define
define|#
directive|define
name|LSAN_THREAD_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_thread_registry.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
struct_decl|struct
name|DTLS
struct_decl|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|__lsan
block|{
name|class
name|ThreadContext
range|:
name|public
name|ThreadContextBase
block|{
name|public
operator|:
name|explicit
name|ThreadContext
argument_list|(
argument|int tid
argument_list|)
block|;
name|void
name|OnStarted
argument_list|(
argument|void *arg
argument_list|)
name|override
block|;
name|void
name|OnFinished
argument_list|()
name|override
block|;
name|uptr
name|stack_begin
argument_list|()
block|{
return|return
name|stack_begin_
return|;
block|}
name|uptr
name|stack_end
argument_list|()
block|{
return|return
name|stack_end_
return|;
block|}
name|uptr
name|tls_begin
argument_list|()
block|{
return|return
name|tls_begin_
return|;
block|}
name|uptr
name|tls_end
argument_list|()
block|{
return|return
name|tls_end_
return|;
block|}
name|uptr
name|cache_begin
argument_list|()
block|{
return|return
name|cache_begin_
return|;
block|}
name|uptr
name|cache_end
argument_list|()
block|{
return|return
name|cache_end_
return|;
block|}
name|DTLS
operator|*
name|dtls
argument_list|()
block|{
return|return
name|dtls_
return|;
block|}
name|private
operator|:
name|uptr
name|stack_begin_
block|,
name|stack_end_
block|,
name|cache_begin_
block|,
name|cache_end_
block|,
name|tls_begin_
block|,
name|tls_end_
block|;
name|DTLS
operator|*
name|dtls_
block|; }
decl_stmt|;
name|void
name|InitializeThreadRegistry
parameter_list|()
function_decl|;
name|void
name|ThreadStart
parameter_list|(
name|u32
name|tid
parameter_list|,
name|tid_t
name|os_id
parameter_list|)
function_decl|;
name|void
name|ThreadFinish
parameter_list|()
function_decl|;
name|u32
name|ThreadCreate
parameter_list|(
name|u32
name|tid
parameter_list|,
name|uptr
name|uid
parameter_list|,
name|bool
name|detached
parameter_list|)
function_decl|;
name|void
name|ThreadJoin
parameter_list|(
name|u32
name|tid
parameter_list|)
function_decl|;
name|u32
name|ThreadTid
parameter_list|(
name|uptr
name|uid
parameter_list|)
function_decl|;
name|u32
name|GetCurrentThread
parameter_list|()
function_decl|;
name|void
name|SetCurrentThread
parameter_list|(
name|u32
name|tid
parameter_list|)
function_decl|;
name|ThreadContext
modifier|*
name|CurrentThreadContext
parameter_list|()
function_decl|;
name|void
name|EnsureMainThreadIDIsCorrect
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
comment|// LSAN_THREAD_H
end_comment

end_unit

