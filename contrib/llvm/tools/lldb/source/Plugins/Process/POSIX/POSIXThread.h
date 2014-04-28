begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- POSIXThread.h -------------------------------------------*- C++ -*-===//
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
name|liblldb_POSIXThread_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_POSIXThread_H_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Target/Thread.h"
end_include

begin_include
include|#
directive|include
file|"RegisterContextPOSIX.h"
end_include

begin_decl_stmt
name|class
name|ProcessMessage
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|ProcessMonitor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|POSIXBreakpointProtocol
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------------------
end_comment

begin_comment
comment|// @class POSIXThread
end_comment

begin_comment
comment|// @brief Abstraction of a POSIX thread.
end_comment

begin_decl_stmt
name|class
name|POSIXThread
range|:
name|public
name|lldb_private
operator|::
name|Thread
block|{
name|public
operator|:
name|POSIXThread
argument_list|(
argument|lldb_private::Process&process
argument_list|,
argument|lldb::tid_t tid
argument_list|)
block|;
name|virtual
operator|~
name|POSIXThread
argument_list|()
block|;
name|void
name|RefreshStateAfterStop
argument_list|()
block|;
name|virtual
name|void
name|WillResume
argument_list|(
argument|lldb::StateType resume_state
argument_list|)
block|;
comment|// This notifies the thread when a private stop occurs.
name|virtual
name|void
name|DidStop
argument_list|()
block|;
specifier|const
name|char
operator|*
name|GetInfo
argument_list|()
block|;
name|void
name|SetName
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
specifier|const
name|char
operator|*
name|GetName
argument_list|()
block|;
name|virtual
name|lldb
operator|::
name|RegisterContextSP
name|GetRegisterContext
argument_list|()
block|;
name|virtual
name|lldb
operator|::
name|RegisterContextSP
name|CreateRegisterContextForFrame
argument_list|(
name|lldb_private
operator|::
name|StackFrame
operator|*
name|frame
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|addr_t
name|GetThreadPointer
argument_list|()
block|;
comment|//--------------------------------------------------------------------------
comment|// These functions provide a mapping from the register offset
comment|// back to the register index or name for use in debugging or log
comment|// output.
name|unsigned
name|GetRegisterIndexFromOffset
argument_list|(
argument|unsigned offset
argument_list|)
block|;
specifier|const
name|char
operator|*
name|GetRegisterName
argument_list|(
argument|unsigned reg
argument_list|)
block|;
specifier|const
name|char
operator|*
name|GetRegisterNameFromOffset
argument_list|(
argument|unsigned offset
argument_list|)
block|;
comment|//--------------------------------------------------------------------------
comment|// These methods form a specialized interface to POSIX threads.
comment|//
name|bool
name|Resume
argument_list|()
block|;
name|void
name|Notify
argument_list|(
specifier|const
name|ProcessMessage
operator|&
name|message
argument_list|)
block|;
comment|//--------------------------------------------------------------------------
comment|// These methods provide an interface to watchpoints
comment|//
name|bool
name|EnableHardwareWatchpoint
argument_list|(
name|lldb_private
operator|::
name|Watchpoint
operator|*
name|wp
argument_list|)
block|;
name|bool
name|DisableHardwareWatchpoint
argument_list|(
name|lldb_private
operator|::
name|Watchpoint
operator|*
name|wp
argument_list|)
block|;
name|uint32_t
name|NumSupportedHardwareWatchpoints
argument_list|()
block|;
name|uint32_t
name|FindVacantWatchpointIndex
argument_list|()
block|;
name|protected
operator|:
name|POSIXBreakpointProtocol
operator|*
name|GetPOSIXBreakpointProtocol
argument_list|()
block|{
if|if
condition|(
operator|!
name|m_reg_context_sp
condition|)
name|m_reg_context_sp
operator|=
name|GetRegisterContext
argument_list|()
expr_stmt|;
return|return
name|m_posix_thread
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|StackFrame
operator|>
name|m_frame_ap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|BreakpointSiteSP
name|m_breakpoint
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|m_thread_name_valid
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|m_thread_name
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|POSIXBreakpointProtocol
modifier|*
name|m_posix_thread
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ProcessMonitor
modifier|&
name|GetMonitor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|bool
name|CalculateStopInfo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|BreakNotify
parameter_list|(
specifier|const
name|ProcessMessage
modifier|&
name|message
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|WatchNotify
parameter_list|(
specifier|const
name|ProcessMessage
modifier|&
name|message
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|TraceNotify
parameter_list|(
specifier|const
name|ProcessMessage
modifier|&
name|message
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|LimboNotify
parameter_list|(
specifier|const
name|ProcessMessage
modifier|&
name|message
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SignalNotify
parameter_list|(
specifier|const
name|ProcessMessage
modifier|&
name|message
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SignalDeliveredNotify
parameter_list|(
specifier|const
name|ProcessMessage
modifier|&
name|message
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CrashNotify
parameter_list|(
specifier|const
name|ProcessMessage
modifier|&
name|message
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ThreadNotify
parameter_list|(
specifier|const
name|ProcessMessage
modifier|&
name|message
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ExitNotify
parameter_list|(
specifier|const
name|ProcessMessage
modifier|&
name|message
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ExecNotify
parameter_list|(
specifier|const
name|ProcessMessage
modifier|&
name|message
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|lldb_private
operator|::
name|Unwind
operator|*
name|GetUnwinder
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_POSIXThread_H_
end_comment

end_unit

