begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcessFreeBSD.h ------------------------------------------*- C++
end_comment

begin_comment
comment|//-*-===//
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
name|liblldb_ProcessFreeBSD_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ProcessFreeBSD_H_
end_define

begin_include
include|#
directive|include
file|"Plugins/Process/POSIX/ProcessMessage.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ThreadList.h"
end_include

begin_include
include|#
directive|include
file|<mutex>
end_include

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

begin_decl_stmt
name|class
name|ProcessMonitor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|FreeBSDThread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|ProcessFreeBSD
range|:
name|public
name|lldb_private
operator|::
name|Process
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Static functions.
comment|//------------------------------------------------------------------
specifier|static
name|lldb
operator|::
name|ProcessSP
name|CreateInstance
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|lldb::ListenerSP listener_sp
argument_list|,
argument|const lldb_private::FileSpec *crash_file_path
argument_list|)
block|;
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|void
name|Terminate
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
block|;
specifier|static
specifier|const
name|char
operator|*
name|GetPluginDescriptionStatic
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|// Constructors and destructors
comment|//------------------------------------------------------------------
name|ProcessFreeBSD
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|lldb::ListenerSP listener_sp
argument_list|,
argument|lldb::UnixSignalsSP&unix_signals_sp
argument_list|)
block|;
operator|~
name|ProcessFreeBSD
argument_list|()
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|WillResume
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
name|override
block|;
name|virtual
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
block|;
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Process protocol.
comment|//------------------------------------------------------------------
name|void
name|Finalize
argument_list|()
name|override
block|;
name|bool
name|CanDebug
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|bool plugin_specified_by_name
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|WillLaunch
argument_list|(
argument|lldb_private::Module *module
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|DoAttachToProcessWithID
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|const lldb_private::ProcessAttachInfo&attach_info
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|DoLaunch
argument_list|(
argument|lldb_private::Module *exe_module
argument_list|,
argument|lldb_private::ProcessLaunchInfo&launch_info
argument_list|)
name|override
block|;
name|void
name|DidLaunch
argument_list|()
name|override
block|;
name|lldb_private
operator|::
name|Error
name|DoResume
argument_list|()
name|override
block|;
name|lldb_private
operator|::
name|Error
name|DoHalt
argument_list|(
argument|bool&caused_stop
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|DoDetach
argument_list|(
argument|bool keep_stopped
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|DoSignal
argument_list|(
argument|int signal
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|DoDestroy
argument_list|()
name|override
block|;
name|void
name|DoDidExec
argument_list|()
name|override
block|;
name|void
name|RefreshStateAfterStop
argument_list|()
name|override
block|;
name|bool
name|IsAlive
argument_list|()
name|override
block|;
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
name|override
block|;
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
name|override
block|;
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
name|override
block|;
name|lldb_private
operator|::
name|Error
name|DoDeallocateMemory
argument_list|(
argument|lldb::addr_t ptr
argument_list|)
name|override
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
name|lldb_private
operator|::
name|Error
name|EnableBreakpointSite
argument_list|(
argument|lldb_private::BreakpointSite *bp_site
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|DisableBreakpointSite
argument_list|(
argument|lldb_private::BreakpointSite *bp_site
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|EnableWatchpoint
argument_list|(
argument|lldb_private::Watchpoint *wp
argument_list|,
argument|bool notify = true
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|DisableWatchpoint
argument_list|(
argument|lldb_private::Watchpoint *wp
argument_list|,
argument|bool notify = true
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|GetWatchpointSupportInfo
argument_list|(
argument|uint32_t&num
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|GetWatchpointSupportInfo
argument_list|(
argument|uint32_t&num
argument_list|,
argument|bool&after
argument_list|)
name|override
block|;
name|virtual
name|uint32_t
name|UpdateThreadListIfNeeded
argument_list|()
block|;
name|bool
name|UpdateThreadList
argument_list|(
argument|lldb_private::ThreadList&old_thread_list
argument_list|,
argument|lldb_private::ThreadList&new_thread_list
argument_list|)
name|override
block|;
name|virtual
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
specifier|const
block|;
name|lldb
operator|::
name|addr_t
name|GetImageInfoAddress
argument_list|()
name|override
block|;
name|size_t
name|PutSTDIN
argument_list|(
argument|const char *buf
argument_list|,
argument|size_t len
argument_list|,
argument|lldb_private::Error&error
argument_list|)
name|override
block|;
specifier|const
name|lldb
operator|::
name|DataBufferSP
name|GetAuxvData
argument_list|()
name|override
block|;
comment|//--------------------------------------------------------------------------
comment|// ProcessFreeBSD internal API.
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
name|FileSpec
name|GetFileSpec
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileAction
operator|*
name|file_action
argument_list|,
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|default_file_spec
argument_list|,
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|dbg_pts_file_spec
argument_list|)
block|;
comment|/// Adds the thread to the list of threads for which we have received the
comment|/// initial stopping signal.
comment|/// The \p stop_tid parameter indicates the thread which the stop happened
comment|/// for.
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
name|FreeBSDThread
operator|*
name|CreateNewFreeBSDThread
argument_list|(
argument|lldb_private::Process&process
argument_list|,
argument|lldb::tid_t tid
argument_list|)
block|;
specifier|static
name|bool
name|SingleStepBreakpointHit
argument_list|(
argument|void *baton
argument_list|,
argument|lldb_private::StoppointCallbackContext *context
argument_list|,
argument|lldb::user_id_t break_id
argument_list|,
argument|lldb::user_id_t break_loc_id
argument_list|)
block|;
name|lldb_private
operator|::
name|Error
name|SetupSoftwareSingleStepping
argument_list|(
argument|lldb::tid_t tid
argument_list|)
block|;
name|lldb_private
operator|::
name|Error
name|SetSoftwareSingleStepBreakpoint
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|lldb::addr_t addr
argument_list|)
block|;
name|bool
name|IsSoftwareStepBreakpoint
argument_list|(
argument|lldb::tid_t tid
argument_list|)
block|;
name|bool
name|SupportHardwareSingleStepping
argument_list|()
specifier|const
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|tid_t
operator|>
name|tid_collection
expr_stmt|;
name|tid_collection
operator|&
name|GetStepTids
argument_list|()
block|{
return|return
name|m_step_tids
return|;
block|}
name|protected
operator|:
specifier|static
specifier|const
name|size_t
name|MAX_TRAP_OPCODE_SIZE
operator|=
literal|8
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Target byte order.
end_comment

begin_expr_stmt
name|lldb
operator|::
name|ByteOrder
name|m_byte_order
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Process monitor;
end_comment

begin_decl_stmt
name|ProcessMonitor
modifier|*
name|m_monitor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The module we are executing.
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|Module
operator|*
name|m_module
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Message queue notifying this instance of inferior process state changes.
end_comment

begin_expr_stmt
name|std
operator|::
name|recursive_mutex
name|m_message_mutex
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|queue
operator|<
name|ProcessMessage
operator|>
name|m_message_queue
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Drive any exit events to completion.
end_comment

begin_decl_stmt
name|bool
name|m_exit_now
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Returns true if the process has exited.
end_comment

begin_function_decl
name|bool
name|HasExited
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Returns true if the process is stopped.
end_comment

begin_function_decl
name|bool
name|IsStopped
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Returns true if at least one running is currently running
end_comment

begin_function_decl
name|bool
name|IsAThreadRunning
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
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
end_typedef

begin_decl_stmt
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

begin_decl_stmt
name|friend
name|class
name|FreeBSDThread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tid_collection
name|m_suspend_tids
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tid_collection
name|m_run_tids
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tid_collection
name|m_step_tids
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|tid_t
operator|,
name|lldb
operator|::
name|break_id_t
operator|>
name|m_threads_stepping_with_breakpoint
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|m_resume_signo
decl_stmt|;
end_decl_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ProcessFreeBSD_H_
end_comment

end_unit

