begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_stoptheworld.h --------------------------------*- C++ -*-===//
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
comment|// Defines the StopTheWorld function which suspends the execution of the current
end_comment

begin_comment
comment|// process and runs the user-supplied callback in the same address space.
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
name|SANITIZER_STOPTHEWORLD_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_STOPTHEWORLD_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
typedef|typedef
name|int
name|SuspendedThreadID
typedef|;
enum|enum
name|PtraceRegistersStatus
block|{
name|REGISTERS_UNAVAILABLE_FATAL
init|=
operator|-
literal|1
block|,
name|REGISTERS_UNAVAILABLE
init|=
literal|0
block|,
name|REGISTERS_AVAILABLE
init|=
literal|1
block|}
enum|;
comment|// Holds the list of suspended threads and provides an interface to dump their
comment|// register contexts.
name|class
name|SuspendedThreadsList
block|{
name|public
label|:
name|SuspendedThreadsList
argument_list|()
operator|:
name|thread_ids_
argument_list|(
literal|1024
argument_list|)
block|{}
name|SuspendedThreadID
name|GetThreadID
argument_list|(
argument|uptr index
argument_list|)
specifier|const
block|{
name|CHECK_LT
argument_list|(
name|index
argument_list|,
name|thread_ids_
operator|.
name|size
argument_list|()
argument_list|)
block|;
return|return
name|thread_ids_
index|[
name|index
index|]
return|;
block|}
name|PtraceRegistersStatus
name|GetRegistersAndSP
argument_list|(
name|uptr
name|index
argument_list|,
name|uptr
operator|*
name|buffer
argument_list|,
name|uptr
operator|*
name|sp
argument_list|)
decl|const
decl_stmt|;
comment|// The buffer in GetRegistersAndSP should be at least this big.
specifier|static
name|uptr
name|RegisterCount
parameter_list|()
function_decl|;
name|uptr
name|thread_count
argument_list|()
specifier|const
block|{
return|return
name|thread_ids_
operator|.
name|size
argument_list|()
return|;
block|}
name|bool
name|Contains
argument_list|(
name|SuspendedThreadID
name|thread_id
argument_list|)
decl|const
block|{
for|for
control|(
name|uptr
name|i
init|=
literal|0
init|;
name|i
operator|<
name|thread_ids_
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|thread_ids_
index|[
name|i
index|]
operator|==
name|thread_id
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
name|void
name|Append
parameter_list|(
name|SuspendedThreadID
name|thread_id
parameter_list|)
block|{
name|thread_ids_
operator|.
name|push_back
argument_list|(
name|thread_id
argument_list|)
expr_stmt|;
block|}
name|private
label|:
name|InternalMmapVector
operator|<
name|SuspendedThreadID
operator|>
name|thread_ids_
expr_stmt|;
comment|// Prohibit copy and assign.
name|SuspendedThreadsList
argument_list|(
specifier|const
name|SuspendedThreadsList
operator|&
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|SuspendedThreadsList
operator|&
operator|)
decl_stmt|;
block|}
empty_stmt|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|StopTheWorldCallback
function_decl|)
parameter_list|(
specifier|const
name|SuspendedThreadsList
modifier|&
name|suspended_threads_list
parameter_list|,
name|void
modifier|*
name|argument
parameter_list|)
function_decl|;
comment|// Suspend all threads in the current process and run the callback on the list
comment|// of suspended threads. This function will resume the threads before returning.
comment|// The callback should not call any libc functions. The callback must not call
comment|// exit() nor _exit() and instead return to the caller.
comment|// This function should NOT be called from multiple threads simultaneously.
name|void
name|StopTheWorld
parameter_list|(
name|StopTheWorldCallback
name|callback
parameter_list|,
name|void
modifier|*
name|argument
parameter_list|)
function_decl|;
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
comment|// SANITIZER_STOPTHEWORLD_H
end_comment

end_unit

