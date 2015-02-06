begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcessGDBRemote.h --------------------------------------*- C++ -*-===//
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
name|liblldb_ProcessGDBRemote_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ProcessGDBRemote_h_
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
file|<list>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Broadcaster.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/StreamString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/StringList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/StructuredData.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ThreadSafeValue.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/HostThread.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Thread.h"
end_include

begin_include
include|#
directive|include
file|"GDBRemoteCommunicationClient.h"
end_include

begin_include
include|#
directive|include
file|"Utility/StringExtractor.h"
end_include

begin_include
include|#
directive|include
file|"GDBRemoteRegisterContext.h"
end_include

begin_decl_stmt
name|class
name|ThreadGDBRemote
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|ProcessGDBRemote
range|:
name|public
name|lldb_private
operator|::
name|Process
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
specifier|static
name|lldb
operator|::
name|ProcessSP
name|CreateInstance
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
argument_list|,
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|*
name|crash_file_path
argument_list|)
block|;
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|void
name|DebuggerInitialize
argument_list|(
name|lldb_private
operator|::
name|Debugger
operator|&
name|debugger
argument_list|)
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
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|ProcessGDBRemote
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
name|ProcessGDBRemote
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|// Check if a given Process
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|CanDebug
argument_list|(
argument|lldb_private::Target&target
argument_list|,
argument|bool plugin_specified_by_name
argument_list|)
name|override
block|;
name|virtual
name|lldb_private
operator|::
name|CommandObject
operator|*
name|GetPluginCommandObject
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Creating a new process, or attaching to an existing one
comment|//------------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|Error
name|WillLaunch
argument_list|(
argument|lldb_private::Module* module
argument_list|)
name|override
block|;
name|virtual
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
name|virtual
name|void
name|DidLaunch
argument_list|()
name|override
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|WillAttachToProcessWithID
argument_list|(
argument|lldb::pid_t pid
argument_list|)
name|override
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|WillAttachToProcessWithName
argument_list|(
argument|const char *process_name
argument_list|,
argument|bool wait_for_launch
argument_list|)
name|override
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DoConnectRemote
argument_list|(
argument|lldb_private::Stream *strm
argument_list|,
argument|const char *remote_url
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|WillLaunchOrAttach
argument_list|()
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DoAttachToProcessWithID
argument_list|(
argument|lldb::pid_t pid
argument_list|)
name|override
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
name|override
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DoAttachToProcessWithName
argument_list|(
argument|const char *process_name
argument_list|,
argument|const lldb_private::ProcessAttachInfo&attach_info
argument_list|)
name|override
block|;
name|virtual
name|void
name|DidAttach
argument_list|(
argument|lldb_private::ArchSpec&process_arch
argument_list|)
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
comment|//------------------------------------------------------------------
comment|// Process Control
comment|//------------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|Error
name|WillResume
argument_list|()
name|override
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DoResume
argument_list|()
name|override
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DoHalt
argument_list|(
argument|bool&caused_stop
argument_list|)
name|override
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DoDetach
argument_list|(
argument|bool keep_stopped
argument_list|)
name|override
block|;
name|virtual
name|bool
name|DetachRequiresHalt
argument_list|()
name|override
block|{
return|return
name|true
return|;
block|}
name|virtual
name|lldb_private
operator|::
name|Error
name|DoSignal
argument_list|(
argument|int signal
argument_list|)
name|override
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DoDestroy
argument_list|()
name|override
block|;
name|virtual
name|void
name|RefreshStateAfterStop
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Process Queries
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|IsAlive
argument_list|()
name|override
block|;
name|virtual
name|lldb
operator|::
name|addr_t
name|GetImageInfoAddress
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Process Memory
comment|//------------------------------------------------------------------
name|virtual
name|size_t
name|DoReadMemory
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|void *buf
argument_list|,
argument|size_t size
argument_list|,
argument|lldb_private::Error&error
argument_list|)
name|override
block|;
name|virtual
name|size_t
name|DoWriteMemory
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|const void *buf
argument_list|,
argument|size_t size
argument_list|,
argument|lldb_private::Error&error
argument_list|)
name|override
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
name|override
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|GetMemoryRegionInfo
argument_list|(
argument|lldb::addr_t load_addr
argument_list|,
argument|lldb_private::MemoryRegionInfo&region_info
argument_list|)
name|override
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DoDeallocateMemory
argument_list|(
argument|lldb::addr_t ptr
argument_list|)
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Process STDIO
comment|//------------------------------------------------------------------
name|virtual
name|size_t
name|PutSTDIN
argument_list|(
argument|const char *buf
argument_list|,
argument|size_t buf_size
argument_list|,
argument|lldb_private::Error&error
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|// Process Breakpoints
comment|//----------------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|Error
name|EnableBreakpointSite
argument_list|(
argument|lldb_private::BreakpointSite *bp_site
argument_list|)
name|override
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DisableBreakpointSite
argument_list|(
argument|lldb_private::BreakpointSite *bp_site
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|// Process Watchpoints
comment|//----------------------------------------------------------------------
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
name|override
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
name|override
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|GetWatchpointSupportInfo
argument_list|(
argument|uint32_t&num
argument_list|)
name|override
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|GetWatchpointSupportInfo
argument_list|(
argument|uint32_t&num
argument_list|,
argument|bool& after
argument_list|)
name|override
block|;
name|virtual
name|bool
name|StartNoticingNewThreads
argument_list|()
name|override
block|;
name|virtual
name|bool
name|StopNoticingNewThreads
argument_list|()
name|override
block|;
name|GDBRemoteCommunicationClient
operator|&
name|GetGDBRemote
argument_list|()
block|{
return|return
name|m_gdb_comm
return|;
block|}
name|virtual
name|lldb_private
operator|::
name|Error
name|SendEventData
argument_list|(
argument|const char *data
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|// Override SetExitStatus so we can disconnect from the remote GDB server
comment|//----------------------------------------------------------------------
name|virtual
name|bool
name|SetExitStatus
argument_list|(
argument|int exit_status
argument_list|,
argument|const char *cstr
argument_list|)
name|override
block|;
name|void
name|SetUserSpecifiedMaxMemoryTransferSize
argument_list|(
argument|uint64_t user_specified_max
argument_list|)
block|;
name|protected
operator|:
name|friend
name|class
name|ThreadGDBRemote
block|;
name|friend
name|class
name|GDBRemoteCommunicationClient
block|;
name|friend
name|class
name|GDBRemoteRegisterContext
block|;
comment|//----------------------------------------------------------------------
comment|// Accessors
comment|//----------------------------------------------------------------------
name|bool
name|IsRunning
argument_list|(
argument|lldb::StateType state
argument_list|)
block|{
return|return
name|state
operator|==
name|lldb
operator|::
name|eStateRunning
operator|||
name|IsStepping
argument_list|(
name|state
argument_list|)
return|;
block|}
name|bool
name|IsStepping
argument_list|(
argument|lldb::StateType state
argument_list|)
block|{
return|return
name|state
operator|==
name|lldb
operator|::
name|eStateStepping
return|;
block|}
name|bool
name|CanResume
argument_list|(
argument|lldb::StateType state
argument_list|)
block|{
return|return
name|state
operator|==
name|lldb
operator|::
name|eStateStopped
return|;
block|}
name|bool
name|HasExited
argument_list|(
argument|lldb::StateType state
argument_list|)
block|{
return|return
name|state
operator|==
name|lldb
operator|::
name|eStateExited
return|;
block|}
name|bool
name|ProcessIDIsValid
argument_list|( )
specifier|const
block|;
name|void
name|Clear
argument_list|( )
block|;
name|lldb_private
operator|::
name|Flags
operator|&
name|GetFlags
argument_list|()
block|{
return|return
name|m_flags
return|;
block|}
specifier|const
name|lldb_private
operator|::
name|Flags
operator|&
name|GetFlags
argument_list|()
specifier|const
block|{
return|return
name|m_flags
return|;
block|}
name|virtual
name|bool
name|UpdateThreadList
argument_list|(
argument|lldb_private::ThreadList&old_thread_list
argument_list|,
argument|lldb_private::ThreadList&new_thread_list
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|LaunchAndConnectToDebugserver
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ProcessInfo
operator|&
name|process_info
argument_list|)
block|;
name|void
name|KillDebugserverProcess
argument_list|()
block|;
name|void
name|BuildDynamicRegisterInfo
argument_list|(
argument|bool force
argument_list|)
block|;
name|void
name|SetLastStopPacket
argument_list|(
specifier|const
name|StringExtractorGDBRemote
operator|&
name|response
argument_list|)
block|;
name|bool
name|ParsePythonTargetDefinition
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|target_definition_fspec
argument_list|)
block|;
name|bool
name|ParseRegisters
argument_list|(
name|lldb_private
operator|::
name|ScriptInterpreterObject
operator|*
name|registers_array
argument_list|)
block|;
specifier|const
name|lldb
operator|::
name|DataBufferSP
name|GetAuxvData
argument_list|()
name|override
block|;
name|lldb_private
operator|::
name|StructuredData
operator|::
name|ObjectSP
name|GetExtendedInfoForThread
argument_list|(
argument|lldb::tid_t tid
argument_list|)
block|;
name|void
name|GetMaxMemorySize
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Broadcaster event bits definitions.
comment|//------------------------------------------------------------------
block|enum
block|{
name|eBroadcastBitAsyncContinue
operator|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|eBroadcastBitAsyncThreadShouldExit
operator|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|eBroadcastBitAsyncThreadDidExit
operator|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|}
block|;
name|lldb_private
operator|::
name|Flags
name|m_flags
block|;
comment|// Process specific flags (see eFlags enums)
name|GDBRemoteCommunicationClient
name|m_gdb_comm
block|;
name|std
operator|::
name|atomic
operator|<
name|lldb
operator|::
name|pid_t
operator|>
name|m_debugserver_pid
block|;
name|StringExtractorGDBRemote
name|m_last_stop_packet
block|;
name|lldb_private
operator|::
name|Mutex
name|m_last_stop_packet_mutex
block|;
name|GDBRemoteDynamicRegisterInfo
name|m_register_info
block|;
name|lldb_private
operator|::
name|Broadcaster
name|m_async_broadcaster
block|;
name|lldb_private
operator|::
name|HostThread
name|m_async_thread
block|;
name|lldb_private
operator|::
name|Mutex
name|m_async_thread_state_mutex
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
end_decl_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|lldb
operator|::
name|tid_t
operator|,
name|int
operator|>
expr|>
name|tid_sig_collection
expr_stmt|;
end_typedef

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
name|tid_collection
name|m_thread_ids
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Thread IDs for all threads. This list gets updated after stopping
end_comment

begin_decl_stmt
name|tid_collection
name|m_continue_c_tids
decl_stmt|;
end_decl_stmt

begin_comment
comment|// 'c' for continue
end_comment

begin_decl_stmt
name|tid_sig_collection
name|m_continue_C_tids
decl_stmt|;
end_decl_stmt

begin_comment
comment|// 'C' for continue with signal
end_comment

begin_decl_stmt
name|tid_collection
name|m_continue_s_tids
decl_stmt|;
end_decl_stmt

begin_comment
comment|// 's' for step
end_comment

begin_decl_stmt
name|tid_sig_collection
name|m_continue_S_tids
decl_stmt|;
end_decl_stmt

begin_comment
comment|// 'S' for step with signal
end_comment

begin_decl_stmt
name|uint64_t
name|m_max_memory_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The maximum number of bytes to read/write when reading and writing memory
end_comment

begin_decl_stmt
name|uint64_t
name|m_remote_stub_max_memory_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The maximum memory size the remote gdb stub can handle
end_comment

begin_decl_stmt
name|MMapMap
name|m_addr_to_mmap_size
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|BreakpointSP
name|m_thread_create_bp_sp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|m_waiting_for_attach
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_destroy_tried_resuming
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|CommandObjectSP
name|m_command_sp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int64_t
name|m_breakpoint_pc_offset
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|StartAsyncThread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|StopAsyncThread
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|static
name|lldb
operator|::
name|thread_result_t
name|AsyncThread
argument_list|(
name|void
operator|*
name|arg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|bool
name|MonitorDebugserverProcess
argument_list|(
name|void
operator|*
name|callback_baton
argument_list|,
name|lldb
operator|::
name|pid_t
name|pid
argument_list|,
name|bool
name|exited
argument_list|,
name|int
name|signo
argument_list|,
name|int
name|exit_status
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|StateType
name|SetThreadStopInfo
argument_list|(
name|StringExtractor
operator|&
name|stop_packet
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|ClearThreadIDList
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|UpdateThreadIDList
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|DidLaunchOrAttach
argument_list|(
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|process_arch
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Error
name|ConnectToDebugserver
argument_list|(
specifier|const
name|char
operator|*
name|host_port
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|GetDispatchQueueNameForThread
argument_list|(
name|lldb
operator|::
name|addr_t
name|thread_dispatch_qaddr
argument_list|,
name|std
operator|::
name|string
operator|&
name|dispatch_queue_name
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|DynamicLoader
operator|*
name|GetDynamicLoader
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// For ProcessGDBRemote only
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
specifier|static
name|bool
name|NewThreadNotifyBreakpointHit
argument_list|(
name|void
operator|*
name|baton
argument_list|,
name|lldb_private
operator|::
name|StoppointCallbackContext
operator|*
name|context
argument_list|,
name|lldb
operator|::
name|user_id_t
name|break_id
argument_list|,
name|lldb
operator|::
name|user_id_t
name|break_loc_id
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ProcessGDBRemote
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ProcessGDBRemote_h_
end_comment

end_unit

