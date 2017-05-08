begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MainLoop.h ----------------------------------------------*- C++ -*-===//
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
name|lldb_Host_MainLoop_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_MainLoop_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/Config.h"
end_include

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

begin_if
if|#
directive|if
operator|!
name|HAVE_PPOLL
operator|&&
operator|!
name|HAVE_SYS_EVENT_H
end_if

begin_define
define|#
directive|define
name|SIGNAL_POLLING_UNSUPPORTED
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|// Implementation of the MainLoopBase class. It can monitor file descriptors for
comment|// readability using ppoll, kqueue, poll or WSAPoll. On Windows it only supports
comment|// polling sockets, and will not work on generic file handles or pipes. On
comment|// systems without kqueue or ppoll handling singnals is not supported. In
comment|// addition to the common base, this class provides the ability to invoke a
comment|// given handler when a signal is received.
comment|//
comment|// Since this class is primarily intended to be used for single-threaded
comment|// processing, it does not attempt to perform any internal synchronisation and
comment|// any concurrent accesses must be protected  externally. However, it is
comment|// perfectly legitimate to have more than one instance of this class running on
comment|// separate threads, or even a single thread (with some limitations on signal
comment|// monitoring).
comment|// TODO: Add locking if this class is to be used in a multi-threaded context.
name|class
name|MainLoop
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
name|MainLoop
argument_list|()
decl_stmt|;
operator|~
name|MainLoop
argument_list|()
name|override
expr_stmt|;
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
comment|// Listening for signals from multiple MainLoop instances is perfectly safe as
comment|// long as they don't try to listen for the same signal. The callback function
comment|// is invoked when the control returns to the Run() function, not when the
comment|// hander is executed. This mean that you can treat the callback as a normal
comment|// function and perform things which would not be safe in a signal handler.
comment|// However, since the callback is not invoked synchronously, you cannot use
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
comment|// This should only be performed from a callback. Do not attempt to terminate
comment|// the processing from another thread.
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
name|void
name|ProcessReadObject
argument_list|(
name|IOObject
operator|::
name|WaitableHandle
name|handle
argument_list|)
decl_stmt|;
name|void
name|ProcessSignal
parameter_list|(
name|int
name|signo
parameter_list|)
function_decl|;
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
argument|MainLoop&mainloop
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
block|{}
name|MainLoop
operator|&
name|m_mainloop
expr_stmt|;
name|int
name|m_signo
decl_stmt|;
name|friend
name|class
name|MainLoop
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
if|#
directive|if
name|HAVE_SIGACTION
name|struct
name|sigaction
name|old_action
decl_stmt|;
endif|#
directive|endif
name|bool
name|was_blocked
range|:
literal|1
decl_stmt|;
block|}
struct|;
name|class
name|RunImpl
decl_stmt|;
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
if|#
directive|if
name|HAVE_SYS_EVENT_H
name|int
name|m_kqueue
decl_stmt|;
endif|#
directive|endif
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
comment|// lldb_Host_MainLoop_h_
end_comment

end_unit

