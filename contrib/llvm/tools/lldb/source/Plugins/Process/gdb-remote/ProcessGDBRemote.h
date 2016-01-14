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
file|<atomic>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
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
file|"lldb/Core/LoadedModuleInfoList.h"
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
file|"lldb/Utility/StringExtractor.h"
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
file|"GDBRemoteRegisterContext.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_gdb_remote
block|{
name|class
name|ThreadGDBRemote
decl_stmt|;
name|class
name|ProcessGDBRemote
range|:
name|public
name|Process
block|{
name|public
operator|:
name|ProcessGDBRemote
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|Listener&listener
argument_list|)
block|;
operator|~
name|ProcessGDBRemote
argument_list|()
name|override
block|;
specifier|static
name|lldb
operator|::
name|ProcessSP
name|CreateInstance
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|Listener&listener
argument_list|,
argument|const FileSpec *crash_file_path
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
comment|// Check if a given Process
comment|//------------------------------------------------------------------
name|bool
name|CanDebug
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|bool plugin_specified_by_name
argument_list|)
name|override
block|;
name|CommandObject
operator|*
name|GetPluginCommandObject
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Creating a new process, or attaching to an existing one
comment|//------------------------------------------------------------------
name|Error
name|WillLaunch
argument_list|(
argument|Module* module
argument_list|)
name|override
block|;
name|Error
name|DoLaunch
argument_list|(
argument|Module *exe_module
argument_list|,
argument|ProcessLaunchInfo&launch_info
argument_list|)
name|override
block|;
name|void
name|DidLaunch
argument_list|()
name|override
block|;
name|Error
name|WillAttachToProcessWithID
argument_list|(
argument|lldb::pid_t pid
argument_list|)
name|override
block|;
name|Error
name|WillAttachToProcessWithName
argument_list|(
argument|const char *process_name
argument_list|,
argument|bool wait_for_launch
argument_list|)
name|override
block|;
name|Error
name|DoConnectRemote
argument_list|(
argument|Stream *strm
argument_list|,
argument|const char *remote_url
argument_list|)
name|override
block|;
name|Error
name|WillLaunchOrAttach
argument_list|()
block|;
name|Error
name|DoAttachToProcessWithID
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|const ProcessAttachInfo&attach_info
argument_list|)
name|override
block|;
name|Error
name|DoAttachToProcessWithName
argument_list|(
argument|const char *process_name
argument_list|,
argument|const ProcessAttachInfo&attach_info
argument_list|)
name|override
block|;
name|void
name|DidAttach
argument_list|(
argument|ArchSpec&process_arch
argument_list|)
name|override
block|;
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
name|ConstString
name|GetPluginName
argument_list|()
name|override
block|;
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Process Control
comment|//------------------------------------------------------------------
name|Error
name|WillResume
argument_list|()
name|override
block|;
name|Error
name|DoResume
argument_list|()
name|override
block|;
name|Error
name|DoHalt
argument_list|(
argument|bool&caused_stop
argument_list|)
name|override
block|;
name|Error
name|DoDetach
argument_list|(
argument|bool keep_stopped
argument_list|)
name|override
block|;
name|bool
name|DetachRequiresHalt
argument_list|()
name|override
block|{
return|return
name|true
return|;
block|}
name|Error
name|DoSignal
argument_list|(
argument|int signal
argument_list|)
name|override
block|;
name|Error
name|DoDestroy
argument_list|()
name|override
block|;
name|void
name|RefreshStateAfterStop
argument_list|()
name|override
block|;
name|void
name|SetUnixSignals
argument_list|(
specifier|const
name|lldb
operator|::
name|UnixSignalsSP
operator|&
name|signals_sp
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// Process Queries
comment|//------------------------------------------------------------------
name|bool
name|IsAlive
argument_list|()
name|override
block|;
name|lldb
operator|::
name|addr_t
name|GetImageInfoAddress
argument_list|()
name|override
block|;
name|void
name|WillPublicStop
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Process Memory
comment|//------------------------------------------------------------------
name|size_t
name|DoReadMemory
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|void *buf
argument_list|,
argument|size_t size
argument_list|,
argument|Error&error
argument_list|)
name|override
block|;
name|size_t
name|DoWriteMemory
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|const void *buf
argument_list|,
argument|size_t size
argument_list|,
argument|Error&error
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
argument|Error&error
argument_list|)
name|override
block|;
name|Error
name|GetMemoryRegionInfo
argument_list|(
argument|lldb::addr_t load_addr
argument_list|,
argument|MemoryRegionInfo&region_info
argument_list|)
name|override
block|;
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
name|size_t
name|PutSTDIN
argument_list|(
argument|const char *buf
argument_list|,
argument|size_t buf_size
argument_list|,
argument|Error&error
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|// Process Breakpoints
comment|//----------------------------------------------------------------------
name|Error
name|EnableBreakpointSite
argument_list|(
argument|BreakpointSite *bp_site
argument_list|)
name|override
block|;
name|Error
name|DisableBreakpointSite
argument_list|(
argument|BreakpointSite *bp_site
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|// Process Watchpoints
comment|//----------------------------------------------------------------------
name|Error
name|EnableWatchpoint
argument_list|(
argument|Watchpoint *wp
argument_list|,
argument|bool notify = true
argument_list|)
name|override
block|;
name|Error
name|DisableWatchpoint
argument_list|(
argument|Watchpoint *wp
argument_list|,
argument|bool notify = true
argument_list|)
name|override
block|;
name|Error
name|GetWatchpointSupportInfo
argument_list|(
argument|uint32_t&num
argument_list|)
name|override
block|;
name|Error
name|GetWatchpointSupportInfo
argument_list|(
argument|uint32_t&num
argument_list|,
argument|bool& after
argument_list|)
name|override
block|;
name|bool
name|StartNoticingNewThreads
argument_list|()
name|override
block|;
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
name|Error
name|SendEventData
argument_list|(
argument|const char *data
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|// Override DidExit so we can disconnect from the remote GDB server
comment|//----------------------------------------------------------------------
name|void
name|DidExit
argument_list|()
name|override
block|;
name|void
name|SetUserSpecifiedMaxMemoryTransferSize
argument_list|(
argument|uint64_t user_specified_max
argument_list|)
block|;
name|bool
name|GetModuleSpec
argument_list|(
argument|const FileSpec& module_file_spec
argument_list|,
argument|const ArchSpec& arch
argument_list|,
argument|ModuleSpec&module_spec
argument_list|)
name|override
block|;
name|bool
name|GetHostOSVersion
argument_list|(
argument|uint32_t&major
argument_list|,
argument|uint32_t&minor
argument_list|,
argument|uint32_t&update
argument_list|)
name|override
block|;
name|size_t
name|LoadModules
argument_list|(
argument|LoadedModuleInfoList&module_list
argument_list|)
name|override
block|;
name|size_t
name|LoadModules
argument_list|()
name|override
block|;
name|Error
name|GetFileLoadAddress
argument_list|(
argument|const FileSpec& file
argument_list|,
argument|bool& is_loaded
argument_list|,
argument|lldb::addr_t& load_addr
argument_list|)
name|override
block|;
name|void
name|ModulesDidLoad
argument_list|(
argument|ModuleList&module_list
argument_list|)
name|override
block|;
name|StructuredData
operator|::
name|ObjectSP
name|GetLoadedDynamicLibrariesInfos
argument_list|(
argument|lldb::addr_t image_list_address
argument_list|,
argument|lldb::addr_t image_count
argument_list|)
name|override
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
name|std
operator|::
name|vector
operator|<
name|StringExtractorGDBRemote
operator|>
name|m_stop_packet_stack
block|;
comment|// The stop packet stack replaces the last stop packet variable
name|Mutex
name|m_last_stop_packet_mutex
block|;
name|GDBRemoteDynamicRegisterInfo
name|m_register_info
block|;
name|Broadcaster
name|m_async_broadcaster
block|;
name|Listener
name|m_async_listener
block|;
name|HostThread
name|m_async_thread
block|;
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
typedef|typedef
name|std
operator|::
name|map
operator|<
name|uint32_t
operator|,
name|std
operator|::
name|string
operator|>
name|ExpeditedRegisterMap
expr_stmt|;
name|tid_collection
name|m_thread_ids
decl_stmt|;
comment|// Thread IDs for all threads. This list gets updated after stopping
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|addr_t
operator|>
name|m_thread_pcs
expr_stmt|;
comment|// PC values for all the threads.
name|StructuredData
operator|::
name|ObjectSP
name|m_jstopinfo_sp
expr_stmt|;
comment|// Stop info only for any threads that have valid stop infos
name|StructuredData
operator|::
name|ObjectSP
name|m_jthreadsinfo_sp
expr_stmt|;
comment|// Full stop info, expedited registers and memory for all threads if "jThreadsInfo" packet is supported
name|tid_collection
name|m_continue_c_tids
decl_stmt|;
comment|// 'c' for continue
name|tid_sig_collection
name|m_continue_C_tids
decl_stmt|;
comment|// 'C' for continue with signal
name|tid_collection
name|m_continue_s_tids
decl_stmt|;
comment|// 's' for step
name|tid_sig_collection
name|m_continue_S_tids
decl_stmt|;
comment|// 'S' for step with signal
name|uint64_t
name|m_max_memory_size
decl_stmt|;
comment|// The maximum number of bytes to read/write when reading and writing memory
name|uint64_t
name|m_remote_stub_max_memory_size
decl_stmt|;
comment|// The maximum memory size the remote gdb stub can handle
name|MMapMap
name|m_addr_to_mmap_size
decl_stmt|;
name|lldb
operator|::
name|BreakpointSP
name|m_thread_create_bp_sp
expr_stmt|;
name|bool
name|m_waiting_for_attach
decl_stmt|;
name|bool
name|m_destroy_tried_resuming
decl_stmt|;
name|lldb
operator|::
name|CommandObjectSP
name|m_command_sp
expr_stmt|;
name|int64_t
name|m_breakpoint_pc_offset
decl_stmt|;
name|lldb
operator|::
name|tid_t
name|m_initial_tid
expr_stmt|;
comment|// The initial thread ID, given by stub on attach
comment|//----------------------------------------------------------------------
comment|// Accessors
comment|//----------------------------------------------------------------------
name|bool
name|IsRunning
argument_list|(
name|lldb
operator|::
name|StateType
name|state
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
name|lldb
operator|::
name|StateType
name|state
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
name|lldb
operator|::
name|StateType
name|state
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
name|lldb
operator|::
name|StateType
name|state
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
expr_stmt|;
name|void
name|Clear
parameter_list|( )
function_decl|;
name|Flags
modifier|&
name|GetFlags
parameter_list|()
block|{
return|return
name|m_flags
return|;
block|}
specifier|const
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
name|bool
name|UpdateThreadList
argument_list|(
name|ThreadList
operator|&
name|old_thread_list
argument_list|,
name|ThreadList
operator|&
name|new_thread_list
argument_list|)
name|override
decl_stmt|;
name|Error
name|EstablishConnectionIfNeeded
parameter_list|(
specifier|const
name|ProcessInfo
modifier|&
name|process_info
parameter_list|)
function_decl|;
name|Error
name|LaunchAndConnectToDebugserver
parameter_list|(
specifier|const
name|ProcessInfo
modifier|&
name|process_info
parameter_list|)
function_decl|;
name|void
name|KillDebugserverProcess
parameter_list|()
function_decl|;
name|void
name|BuildDynamicRegisterInfo
parameter_list|(
name|bool
name|force
parameter_list|)
function_decl|;
name|void
name|SetLastStopPacket
parameter_list|(
specifier|const
name|StringExtractorGDBRemote
modifier|&
name|response
parameter_list|)
function_decl|;
name|bool
name|ParsePythonTargetDefinition
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|target_definition_fspec
parameter_list|)
function_decl|;
specifier|const
name|lldb
operator|::
name|DataBufferSP
name|GetAuxvData
argument_list|()
name|override
expr_stmt|;
name|StructuredData
operator|::
name|ObjectSP
name|GetExtendedInfoForThread
argument_list|(
argument|lldb::tid_t tid
argument_list|)
expr_stmt|;
name|void
name|GetMaxMemorySize
parameter_list|()
function_decl|;
name|bool
name|CalculateThreadStopInfo
parameter_list|(
name|ThreadGDBRemote
modifier|*
name|thread
parameter_list|)
function_decl|;
name|size_t
name|UpdateThreadPCsFromStopReplyThreadsValue
argument_list|(
name|std
operator|::
name|string
operator|&
name|value
argument_list|)
decl_stmt|;
name|size_t
name|UpdateThreadIDsFromStopReplyThreadsValue
argument_list|(
name|std
operator|::
name|string
operator|&
name|value
argument_list|)
decl_stmt|;
name|bool
name|HandleNotifyPacket
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
name|bool
name|StartAsyncThread
parameter_list|()
function_decl|;
name|void
name|StopAsyncThread
parameter_list|()
function_decl|;
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
name|bool
name|GetThreadStopInfoFromJSON
argument_list|(
name|ThreadGDBRemote
operator|*
name|thread
argument_list|,
specifier|const
name|StructuredData
operator|::
name|ObjectSP
operator|&
name|thread_infos_sp
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|ThreadSP
name|SetThreadStopInfo
argument_list|(
name|StructuredData
operator|::
name|Dictionary
operator|*
name|thread_dict
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|ThreadSP
name|SetThreadStopInfo
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|ExpeditedRegisterMap&expedited_register_map
argument_list|,
argument|uint8_t signo
argument_list|,
argument|const std::string&thread_name
argument_list|,
argument|const std::string&reason
argument_list|,
argument|const std::string&description
argument_list|,
argument|uint32_t exc_type
argument_list|,
argument|const std::vector<lldb::addr_t>&exc_data
argument_list|,
argument|lldb::addr_t thread_dispatch_qaddr
argument_list|,
argument|bool queue_vars_valid
argument_list|,
argument|lldb_private::LazyBool associated_with_libdispatch_queue
argument_list|,
argument|lldb::addr_t dispatch_queue_t
argument_list|,
argument|std::string&queue_name
argument_list|,
argument|lldb::QueueKind queue_kind
argument_list|,
argument|uint64_t queue_serial
argument_list|)
expr_stmt|;
name|void
name|HandleStopReplySequence
parameter_list|()
function_decl|;
name|void
name|ClearThreadIDList
parameter_list|()
function_decl|;
name|bool
name|UpdateThreadIDList
parameter_list|()
function_decl|;
name|void
name|DidLaunchOrAttach
parameter_list|(
name|ArchSpec
modifier|&
name|process_arch
parameter_list|)
function_decl|;
name|Error
name|ConnectToDebugserver
parameter_list|(
specifier|const
name|char
modifier|*
name|host_port
parameter_list|)
function_decl|;
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
name|DynamicLoader
operator|*
name|GetDynamicLoader
argument_list|()
name|override
expr_stmt|;
comment|// Query remote GDBServer for register information
name|bool
name|GetGDBServerRegisterInfo
parameter_list|()
function_decl|;
comment|// Query remote GDBServer for a detailed loaded library list
name|Error
name|GetLoadedModuleList
parameter_list|(
name|LoadedModuleInfoList
modifier|&
parameter_list|)
function_decl|;
name|lldb
operator|::
name|ModuleSP
name|LoadModuleAtAddress
argument_list|(
argument|const FileSpec&file
argument_list|,
argument|lldb::addr_t base_addr
argument_list|,
argument|bool value_is_offset
argument_list|)
expr_stmt|;
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For ProcessGDBRemote only
comment|//------------------------------------------------------------------
specifier|static
name|bool
name|NewThreadNotifyBreakpointHit
argument_list|(
name|void
operator|*
name|baton
argument_list|,
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
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ProcessGDBRemote
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace process_gdb_remote
end_comment

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ProcessGDBRemote_h_
end_comment

end_unit

