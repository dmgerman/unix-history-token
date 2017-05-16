begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NativeThreadDarwin.h ---------------------------------- -*- C++ -*-===//
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
name|NativeThreadDarwin_H
end_ifndef

begin_define
define|#
directive|define
name|NativeThreadDarwin_H
end_define

begin_comment
comment|// C includes
end_comment

begin_include
include|#
directive|include
file|<mach/mach_types.h>
end_include

begin_include
include|#
directive|include
file|<sched.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc_info.h>
end_include

begin_comment
comment|// C++ includes
end_comment

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

begin_comment
comment|// LLDB includes
end_comment

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
file|"MachException.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_darwin
block|{
name|class
name|NativeProcessDarwin
decl_stmt|;
name|using
name|NativeProcessDarwinSP
init|=
name|std
operator|::
name|shared_ptr
operator|<
name|NativeProcessDarwin
operator|>
decl_stmt|;
name|class
name|NativeThreadListDarwin
decl_stmt|;
name|class
name|NativeThreadDarwin
range|:
name|public
name|NativeThreadProtocol
block|{
name|friend
name|class
name|NativeProcessDarwin
block|;
name|friend
name|class
name|NativeThreadListDarwin
block|;
name|public
operator|:
specifier|static
name|uint64_t
name|GetGloballyUniqueThreadIDForMachPortID
argument_list|(
argument|::thread_t mach_port_id
argument_list|)
block|;
name|NativeThreadDarwin
argument_list|(
argument|NativeProcessDarwin *process
argument_list|,
argument|bool is_64_bit
argument_list|,
argument|lldb::tid_t unique_thread_id =
literal|0
argument_list|,
argument|::thread_t mach_thread_port =
literal|0
argument_list|)
block|;
comment|// -----------------------------------------------------------------
comment|// NativeThreadProtocol Interface
comment|// -----------------------------------------------------------------
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
comment|// -----------------------------------------------------------------
comment|// New methods that are fine for others to call.
comment|// -----------------------------------------------------------------
name|void
name|Dump
argument_list|(
argument|Stream&stream
argument_list|)
specifier|const
block|;
name|private
operator|:
comment|// -----------------------------------------------------------------
comment|// Interface for friend classes
comment|// -----------------------------------------------------------------
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
name|bool
name|NotifyException
argument_list|(
name|MachException
operator|::
name|Data
operator|&
name|exc
argument_list|)
block|;
name|bool
name|ShouldStop
argument_list|(
argument|bool&step_more
argument_list|)
specifier|const
block|;
name|void
name|ThreadDidStop
argument_list|()
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
comment|/// If stopped by a signal, indicate the signo in the signo
comment|/// argument.  Otherwise, return LLDB_INVALID_SIGNAL_NUMBER.
name|bool
name|IsStopped
argument_list|(
name|int
operator|*
name|signo
argument_list|)
block|;
specifier|const
expr|struct
name|thread_basic_info
operator|*
name|GetBasicInfo
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|GetBasicInfo
argument_list|(
argument|::thread_t thread
argument_list|,
argument|struct thread_basic_info *basicInfoPtr
argument_list|)
block|;
name|bool
name|IsUserReady
argument_list|()
specifier|const
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
comment|// -------------------------------------------------------------------------
comment|/// Return the mach thread port number for this thread.
comment|///
comment|/// @return
comment|///     The mach port number for this thread.  Returns NULL_THREAD
comment|///     when the thread is invalid.
comment|// -------------------------------------------------------------------------
name|thread_t
name|GetMachPortNumber
argument_list|()
specifier|const
block|{
return|return
name|m_mach_thread_port
return|;
block|}
specifier|static
name|bool
name|MachPortNumberIsValid
argument_list|(
argument|::thread_t thread
argument_list|)
block|;
comment|// ---------------------------------------------------------------------
comment|// Private interface
comment|// ---------------------------------------------------------------------
name|bool
name|GetIdentifierInfo
argument_list|()
block|;
name|void
name|MaybeLogStateChange
argument_list|(
argument|lldb::StateType new_state
argument_list|)
block|;
name|NativeProcessDarwinSP
name|GetNativeProcessDarwinSP
argument_list|()
block|;
name|void
name|SetStopped
argument_list|()
block|;
specifier|inline
name|void
name|MaybePrepareSingleStepWorkaround
argument_list|()
block|;
specifier|inline
name|void
name|MaybeCleanupSingleStepWorkaround
argument_list|()
block|;
comment|// -----------------------------------------------------------------
comment|// Member Variables
comment|// -----------------------------------------------------------------
comment|// The mach thread port for the thread.
operator|::
name|thread_t
name|m_mach_thread_port
block|;
comment|// The most recently-retrieved thread basic info.
name|mutable
operator|::
name|thread_basic_info
name|m_basic_info
block|;    struct
name|proc_threadinfo
name|m_proc_threadinfo
block|;
name|thread_identifier_info_data_t
name|m_ident_info
block|;
if|#
directive|if
literal|0
block|lldb::StateType m_state;     ThreadStopInfo m_stop_info;     NativeRegisterContextSP m_reg_context_sp;     std::string m_stop_description;     using WatchpointIndexMap = std::map<lldb::addr_t, uint32_t>;     WatchpointIndexMap m_watchpoint_index_map;
comment|// cpu_set_t m_original_cpu_set; // For single-step workaround.
endif|#
directive|endif
block|}
decl_stmt|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|NativeThreadDarwin
operator|>
name|NativeThreadDarwinSP
expr_stmt|;
block|}
comment|// namespace process_darwin
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
comment|// #ifndef NativeThreadDarwin_H
end_comment

end_unit

