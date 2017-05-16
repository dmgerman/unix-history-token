begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NativeThreadLinux.h ----------------------------------- -*- C++ -*-===//
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
name|liblldb_NativeThreadLinux_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_NativeThreadLinux_H_
end_define

begin_include
include|#
directive|include
file|"SingleStepCheck.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/common/NativeThreadProtocol.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private-forward.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

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

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_linux
block|{
name|class
name|NativeProcessLinux
decl_stmt|;
name|class
name|NativeThreadLinux
range|:
name|public
name|NativeThreadProtocol
block|{
name|friend
name|class
name|NativeProcessLinux
block|;
name|public
operator|:
name|NativeThreadLinux
argument_list|(
argument|NativeProcessLinux *process
argument_list|,
argument|lldb::tid_t tid
argument_list|)
block|;
comment|// ---------------------------------------------------------------------
comment|// NativeThreadProtocol Interface
comment|// ---------------------------------------------------------------------
name|std
operator|::
name|string
name|GetName
argument_list|()
name|override
block|;
name|lldb
operator|::
name|StateType
name|GetState
argument_list|()
name|override
block|;
name|bool
name|GetStopReason
argument_list|(
argument|ThreadStopInfo&stop_info
argument_list|,
argument|std::string&description
argument_list|)
name|override
block|;
name|NativeRegisterContextSP
name|GetRegisterContext
argument_list|()
name|override
block|;
name|Status
name|SetWatchpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|,
argument|uint32_t watch_flags
argument_list|,
argument|bool hardware
argument_list|)
name|override
block|;
name|Status
name|RemoveWatchpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|)
name|override
block|;
name|Status
name|SetHardwareBreakpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|)
name|override
block|;
name|Status
name|RemoveHardwareBreakpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|)
name|override
block|;
name|private
operator|:
comment|// ---------------------------------------------------------------------
comment|// Interface for friend classes
comment|// ---------------------------------------------------------------------
comment|/// Resumes the thread.  If @p signo is anything but
comment|/// LLDB_INVALID_SIGNAL_NUMBER, deliver that signal to the thread.
name|Status
name|Resume
argument_list|(
argument|uint32_t signo
argument_list|)
block|;
comment|/// Single steps the thread.  If @p signo is anything but
comment|/// LLDB_INVALID_SIGNAL_NUMBER, deliver that signal to the thread.
name|Status
name|SingleStep
argument_list|(
argument|uint32_t signo
argument_list|)
block|;
name|void
name|SetStoppedBySignal
argument_list|(
argument|uint32_t signo
argument_list|,
argument|const siginfo_t *info = nullptr
argument_list|)
block|;
comment|/// Return true if the thread is stopped.
comment|/// If stopped by a signal, indicate the signo in the signo argument.
comment|/// Otherwise, return LLDB_INVALID_SIGNAL_NUMBER.
name|bool
name|IsStopped
argument_list|(
name|int
operator|*
name|signo
argument_list|)
block|;
name|void
name|SetStoppedByExec
argument_list|()
block|;
name|void
name|SetStoppedByBreakpoint
argument_list|()
block|;
name|void
name|SetStoppedByWatchpoint
argument_list|(
argument|uint32_t wp_index
argument_list|)
block|;
name|bool
name|IsStoppedAtBreakpoint
argument_list|()
block|;
name|bool
name|IsStoppedAtWatchpoint
argument_list|()
block|;
name|void
name|SetStoppedByTrace
argument_list|()
block|;
name|void
name|SetStoppedWithNoReason
argument_list|()
block|;
name|void
name|SetExited
argument_list|()
block|;
name|Status
name|RequestStop
argument_list|()
block|;
comment|// ---------------------------------------------------------------------
comment|// Private interface
comment|// ---------------------------------------------------------------------
name|void
name|MaybeLogStateChange
argument_list|(
argument|lldb::StateType new_state
argument_list|)
block|;
name|NativeProcessLinux
operator|&
name|GetProcess
argument_list|()
block|;
name|void
name|SetStopped
argument_list|()
block|;
comment|// ---------------------------------------------------------------------
comment|// Member Variables
comment|// ---------------------------------------------------------------------
name|lldb
operator|::
name|StateType
name|m_state
block|;
name|ThreadStopInfo
name|m_stop_info
block|;
name|NativeRegisterContextSP
name|m_reg_context_sp
block|;
name|std
operator|::
name|string
name|m_stop_description
block|;
name|using
name|WatchpointIndexMap
operator|=
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|addr_t
block|,
name|uint32_t
operator|>
block|;
name|WatchpointIndexMap
name|m_watchpoint_index_map
block|;
name|WatchpointIndexMap
name|m_hw_break_index_map
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|SingleStepWorkaround
operator|>
name|m_step_workaround
block|; }
decl_stmt|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|NativeThreadLinux
operator|>
name|NativeThreadLinuxSP
expr_stmt|;
block|}
comment|// namespace process_linux
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_NativeThreadLinux_H_
end_comment

end_unit

