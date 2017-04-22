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
operator|=
expr|default
expr_stmt|;
comment|// Can't declare pure virtual functions in sanitizer runtimes:
comment|// __cxa_pure_virtual might be unavailable. Use UNIMPLEMENTED() instead.
name|virtual
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
block|{
name|UNIMPLEMENTED
argument_list|()
expr_stmt|;
block|}
comment|// The buffer in GetRegistersAndSP should be at least this big.
name|virtual
name|uptr
name|RegisterCount
argument_list|()
specifier|const
block|{
name|UNIMPLEMENTED
argument_list|()
block|; }
name|virtual
name|uptr
name|ThreadCount
argument_list|()
specifier|const
block|{
name|UNIMPLEMENTED
argument_list|()
block|; }
name|virtual
name|tid_t
name|GetThreadID
argument_list|(
argument|uptr index
argument_list|)
specifier|const
block|{
name|UNIMPLEMENTED
argument_list|()
block|; }
name|private
operator|:
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

