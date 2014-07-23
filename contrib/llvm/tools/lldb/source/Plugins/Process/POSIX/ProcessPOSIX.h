begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcessPOSIX.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_ProcessPOSIX_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ProcessPOSIX_H_
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
file|<queue>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/UnixSignals.h"
end_include

begin_include
include|#
directive|include
file|"ProcessMessage.h"
end_include

begin_decl_stmt
name|class
name|ProcessMonitor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|POSIXThread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|ProcessPOSIX
range|:
name|public
name|lldb_private
operator|::
name|Process
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and destructors
comment|//------------------------------------------------------------------
name|ProcessPOSIX
argument_list|(
name|lldb_private
operator|::
name|Target
operator|&
name|target
argument_list|,
name|lldb_private
operator|::
name|Listener
operator|&
name|listener
argument_list|)
block|;
name|virtual
operator|~
name|ProcessPOSIX
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|// Process protocol.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|Finalize
argument_list|()
block|;
name|virtual
name|bool
name|CanDebug
argument_list|(
argument|lldb_private::Target&target
argument_list|,
argument|bool plugin_specified_by_name
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|WillLaunch
argument_list|(
name|lldb_private
operator|::
name|Module
operator|*
name|module
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DoAttachToProcessWithID
argument_list|(
argument|lldb::pid_t pid
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DoAttachToProcessWithID
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|const lldb_private::ProcessAttachInfo&attach_info
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DoLaunch
argument_list|(
name|lldb_private
operator|::
name|Module
operator|*
name|exe_module
argument_list|,
name|lldb_private
operator|::
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|)
block|;
name|virtual
name|void
name|DidLaunch
argument_list|()
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DoResume
argument_list|()
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DoHalt
argument_list|(
name|bool
operator|&
name|caused_stop
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DoDetach
argument_list|(
argument|bool keep_stopped
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DoSignal
argument_list|(
argument|int signal
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DoDestroy
argument_list|()
block|;
name|virtual
name|void
name|DoDidExec
argument_list|()
block|;
name|virtual
name|void
name|RefreshStateAfterStop
argument_list|()
block|;
name|virtual
name|bool
name|IsAlive
argument_list|()
block|;
name|virtual
name|size_t
name|DoReadMemory
argument_list|(
argument|lldb::addr_t vm_addr
argument_list|,
argument|void *buf
argument_list|,
argument|size_t size
argument_list|,
argument|lldb_private::Error&error
argument_list|)
block|;
name|virtual
name|size_t
name|DoWriteMemory
argument_list|(
argument|lldb::addr_t vm_addr
argument_list|,
argument|const void *buf
argument_list|,
argument|size_t size
argument_list|,
argument|lldb_private::Error&error
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|addr_t
name|DoAllocateMemory
argument_list|(
argument|size_t size
argument_list|,
argument|uint32_t permissions
argument_list|,
argument|lldb_private::Error&error
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DoDeallocateMemory
argument_list|(
argument|lldb::addr_t ptr
argument_list|)
block|;
name|virtual
name|size_t
name|GetSoftwareBreakpointTrapOpcode
argument_list|(
name|lldb_private
operator|::
name|BreakpointSite
operator|*
name|bp_site
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|EnableBreakpointSite
argument_list|(
name|lldb_private
operator|::
name|BreakpointSite
operator|*
name|bp_site
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DisableBreakpointSite
argument_list|(
name|lldb_private
operator|::
name|BreakpointSite
operator|*
name|bp_site
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|EnableWatchpoint
argument_list|(
argument|lldb_private::Watchpoint *wp
argument_list|,
argument|bool notify = true
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DisableWatchpoint
argument_list|(
argument|lldb_private::Watchpoint *wp
argument_list|,
argument|bool notify = true
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|GetWatchpointSupportInfo
argument_list|(
name|uint32_t
operator|&
name|num
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|GetWatchpointSupportInfo
argument_list|(
name|uint32_t
operator|&
name|num
argument_list|,
name|bool
operator|&
name|after
argument_list|)
block|;
name|virtual
name|uint32_t
name|UpdateThreadListIfNeeded
argument_list|()
block|;
name|virtual
name|bool
name|UpdateThreadList
argument_list|(
name|lldb_private
operator|::
name|ThreadList
operator|&
name|old_thread_list
argument_list|,
name|lldb_private
operator|::
name|ThreadList
operator|&
name|new_thread_list
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
specifier|const
block|;
name|virtual
name|lldb
operator|::
name|addr_t
name|GetImageInfoAddress
argument_list|()
block|;
name|virtual
name|size_t
name|PutSTDIN
argument_list|(
argument|const char *buf
argument_list|,
argument|size_t len
argument_list|,
argument|lldb_private::Error&error
argument_list|)
block|;
comment|//--------------------------------------------------------------------------
comment|// ProcessPOSIX internal API.
comment|/// Registers the given message with this process.
name|virtual
name|void
name|SendMessage
argument_list|(
specifier|const
name|ProcessMessage
operator|&
name|message
argument_list|)
block|;
name|ProcessMonitor
operator|&
name|GetMonitor
argument_list|()
block|{
name|assert
argument_list|(
name|m_monitor
argument_list|)
block|;
return|return
operator|*
name|m_monitor
return|;
block|}
name|lldb_private
operator|::
name|UnixSignals
operator|&
name|GetUnixSignals
argument_list|()
block|;
specifier|const
name|char
operator|*
name|GetFilePath
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ProcessLaunchInfo
operator|::
name|FileAction
operator|*
name|file_action
argument_list|,
specifier|const
name|char
operator|*
name|default_path
argument_list|)
block|;
comment|/// Stops all threads in the process.
comment|/// The \p stop_tid parameter indicates the thread which initiated the stop.
name|virtual
name|void
name|StopAllThreads
argument_list|(
argument|lldb::tid_t stop_tid
argument_list|)
block|;
comment|/// Adds the thread to the list of threads for which we have received the initial stopping signal.
comment|/// The \p stop_tid paramter indicates the thread which the stop happened for.
name|bool
name|AddThreadForInitialStopIfNeeded
argument_list|(
argument|lldb::tid_t stop_tid
argument_list|)
block|;
name|bool
name|WaitingForInitialStop
argument_list|(
argument|lldb::tid_t stop_tid
argument_list|)
block|;
name|virtual
name|POSIXThread
operator|*
name|CreateNewPOSIXThread
argument_list|(
argument|lldb_private::Process&process
argument_list|,
argument|lldb::tid_t tid
argument_list|)
block|;
name|protected
operator|:
comment|/// Target byte order.
name|lldb
operator|::
name|ByteOrder
name|m_byte_order
block|;
comment|/// Process monitor;
name|ProcessMonitor
operator|*
name|m_monitor
block|;
comment|/// The module we are executing.
name|lldb_private
operator|::
name|Module
operator|*
name|m_module
block|;
comment|/// Message queue notifying this instance of inferior process state changes.
name|lldb_private
operator|::
name|Mutex
name|m_message_mutex
block|;
name|std
operator|::
name|queue
operator|<
name|ProcessMessage
operator|>
name|m_message_queue
block|;
comment|/// Drive any exit events to completion.
name|bool
name|m_exit_now
block|;
comment|/// OS-specific signal set.
name|lldb_private
operator|::
name|UnixSignals
name|m_signals
block|;
comment|/// Returns true if the process has exited.
name|bool
name|HasExited
argument_list|()
block|;
comment|/// Returns true if the process is stopped.
name|bool
name|IsStopped
argument_list|()
block|;
comment|/// Returns true if at least one running is currently running
name|bool
name|IsAThreadRunning
argument_list|()
block|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|lldb
operator|::
name|addr_t
operator|>
name|MMapMap
expr_stmt|;
name|MMapMap
name|m_addr_to_mmap_size
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|set
operator|<
name|lldb
operator|::
name|tid_t
operator|>
name|ThreadStopSet
expr_stmt|;
end_typedef

begin_comment
comment|/// Every thread begins with a stop signal. This keeps track
end_comment

begin_comment
comment|/// of the threads for which we have received the stop signal.
end_comment

begin_decl_stmt
name|ThreadStopSet
name|m_seen_initial_stop
decl_stmt|;
end_decl_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_MacOSXProcess_H_
end_comment

end_unit

