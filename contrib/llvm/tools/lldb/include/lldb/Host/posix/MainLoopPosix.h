begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MainLoopPosix.h -----------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|lldb_Host_posix_MainLoopPosix_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_posix_MainLoopPosix_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/MainLoopBase.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|// Posix implementation of the MainLoopBase class. It can monitor file descriptors for
comment|// readability using pselect. In addition to the common base, this class provides the ability to
comment|// invoke a given handler when a signal is received.
comment|//
comment|// Since this class is primarily intended to be used for single-threaded processing, it does not
comment|// attempt to perform any internal synchronisation and any concurrent accesses must be protected
comment|// externally. However, it is perfectly legitimate to have more than one instance of this class
comment|// running on separate threads, or even a single thread (with some limitations on signal
comment|// monitoring).
comment|// TODO: Add locking if this class is to be used in a multi-threaded context.
name|class
name|MainLoopPosix
range|:
name|public
name|MainLoopBase
block|{
name|private
operator|:
name|class
name|SignalHandle
block|;
name|public
operator|:
typedef|typedef
name|std
operator|::
name|unique_ptr
operator|<
name|SignalHandle
operator|>
name|SignalHandleUP
expr_stmt|;
operator|~
name|MainLoopPosix
argument_list|()
name|override
decl_stmt|;
name|ReadHandleUP
name|RegisterReadObject
argument_list|(
specifier|const
name|lldb
operator|::
name|IOObjectSP
operator|&
name|object_sp
argument_list|,
specifier|const
name|Callback
operator|&
name|callback
argument_list|,
name|Error
operator|&
name|error
argument_list|)
name|override
decl_stmt|;
comment|// Listening for signals from multiple MainLoopPosix instances is perfectly safe as long as they
comment|// don't try to listen for the same signal. The callback function is invoked when the control
comment|// returns to the Run() function, not when the hander is executed. This means that you can
comment|// treat the callback as a normal function and perform things which would not be safe in a
comment|// signal handler. However, since the callback is not invoked synchronously, you cannot use
comment|// this mechanism to handle SIGSEGV and the like.
name|SignalHandleUP
name|RegisterSignal
parameter_list|(
name|int
name|signo
parameter_list|,
specifier|const
name|Callback
modifier|&
name|callback
parameter_list|,
name|Error
modifier|&
name|error
parameter_list|)
function_decl|;
name|Error
name|Run
argument_list|()
name|override
expr_stmt|;
comment|// This should only be performed from a callback. Do not attempt to terminate the processing
comment|// from another thread.
comment|// TODO: Add synchronization if we want to be terminated from another thread.
name|void
name|RequestTermination
parameter_list|()
function|override
block|{
name|m_terminate_request
operator|=
name|true
expr_stmt|;
block|}
name|protected
label|:
name|void
name|UnregisterReadObject
argument_list|(
name|IOObject
operator|::
name|WaitableHandle
name|handle
argument_list|)
name|override
decl_stmt|;
name|void
name|UnregisterSignal
parameter_list|(
name|int
name|signo
parameter_list|)
function_decl|;
name|private
label|:
name|class
name|SignalHandle
block|{
name|public
label|:
operator|~
name|SignalHandle
argument_list|()
block|{
name|m_mainloop
operator|.
name|UnregisterSignal
argument_list|(
name|m_signo
argument_list|)
block|; }
name|private
operator|:
name|SignalHandle
argument_list|(
argument|MainLoopPosix&mainloop
argument_list|,
argument|int signo
argument_list|)
operator|:
name|m_mainloop
argument_list|(
name|mainloop
argument_list|)
operator|,
name|m_signo
argument_list|(
argument|signo
argument_list|)
block|{ }
name|MainLoopPosix
operator|&
name|m_mainloop
expr_stmt|;
name|int
name|m_signo
decl_stmt|;
name|friend
name|class
name|MainLoopPosix
decl_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|SignalHandle
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
struct|struct
name|SignalInfo
block|{
name|Callback
name|callback
decl_stmt|;
name|struct
name|sigaction
name|old_action
decl_stmt|;
name|bool
name|was_blocked
range|:
literal|1
decl_stmt|;
block|}
struct|;
name|llvm
operator|::
name|DenseMap
operator|<
name|IOObject
operator|::
name|WaitableHandle
operator|,
name|Callback
operator|>
name|m_read_fds
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
name|int
operator|,
name|SignalInfo
operator|>
name|m_signals
expr_stmt|;
name|bool
name|m_terminate_request
range|:
literal|1
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_Host_posix_MainLoopPosix_h_
end_comment

end_unit

