begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcessKDP.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_ProcessKDP_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ProcessKDP_h_
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
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Status.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/StreamString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/StringList.h"
end_include

begin_include
include|#
directive|include
file|"CommunicationKDP.h"
end_include

begin_decl_stmt
name|class
name|ThreadKDP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|ProcessKDP
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
name|ProcessKDP
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|lldb::ListenerSP listener
argument_list|)
block|;
operator|~
name|ProcessKDP
argument_list|()
name|override
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
name|lldb_private
operator|::
name|Status
name|WillLaunch
argument_list|(
argument|lldb_private::Module *module
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Status
name|DoLaunch
argument_list|(
argument|lldb_private::Module *exe_module
argument_list|,
argument|lldb_private::ProcessLaunchInfo&launch_info
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Status
name|WillAttachToProcessWithID
argument_list|(
argument|lldb::pid_t pid
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Status
name|WillAttachToProcessWithName
argument_list|(
argument|const char *process_name
argument_list|,
argument|bool wait_for_launch
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Status
name|DoConnectRemote
argument_list|(
argument|lldb_private::Stream *strm
argument_list|,
argument|llvm::StringRef remote_url
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Status
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
name|Status
name|DoAttachToProcessWithName
argument_list|(
argument|const char *process_name
argument_list|,
argument|const lldb_private::ProcessAttachInfo&attach_info
argument_list|)
name|override
block|;
name|void
name|DidAttach
argument_list|(
argument|lldb_private::ArchSpec&process_arch
argument_list|)
name|override
block|;
name|lldb
operator|::
name|addr_t
name|GetImageInfoAddress
argument_list|()
name|override
block|;
name|lldb_private
operator|::
name|DynamicLoader
operator|*
name|GetDynamicLoader
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
name|lldb_private
operator|::
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
name|lldb_private
operator|::
name|Status
name|WillResume
argument_list|()
name|override
block|;
name|lldb_private
operator|::
name|Status
name|DoResume
argument_list|()
name|override
block|;
name|lldb_private
operator|::
name|Status
name|DoHalt
argument_list|(
argument|bool&caused_stop
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Status
name|DoDetach
argument_list|(
argument|bool keep_stopped
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Status
name|DoSignal
argument_list|(
argument|int signal
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Status
name|DoDestroy
argument_list|()
name|override
block|;
name|void
name|RefreshStateAfterStop
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Process Queries
comment|//------------------------------------------------------------------
name|bool
name|IsAlive
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
argument|lldb_private::Status&error
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
argument|lldb_private::Status&error
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
argument|lldb_private::Status&error
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Status
name|DoDeallocateMemory
argument_list|(
argument|lldb::addr_t ptr
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|// Process Breakpoints
comment|//----------------------------------------------------------------------
name|lldb_private
operator|::
name|Status
name|EnableBreakpointSite
argument_list|(
argument|lldb_private::BreakpointSite *bp_site
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Status
name|DisableBreakpointSite
argument_list|(
argument|lldb_private::BreakpointSite *bp_site
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|// Process Watchpoints
comment|//----------------------------------------------------------------------
name|lldb_private
operator|::
name|Status
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
name|Status
name|DisableWatchpoint
argument_list|(
argument|lldb_private::Watchpoint *wp
argument_list|,
argument|bool notify = true
argument_list|)
name|override
block|;
name|CommunicationKDP
operator|&
name|GetCommunication
argument_list|()
block|{
return|return
name|m_comm
return|;
block|}
name|protected
operator|:
name|friend
name|class
name|ThreadKDP
block|;
name|friend
name|class
name|CommunicationKDP
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
name|GetHostArchitecture
argument_list|(
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|)
block|;
name|bool
name|ProcessIDIsValid
argument_list|()
specifier|const
block|;
name|void
name|Clear
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
block|;    enum
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
block|}
block|;
name|lldb
operator|::
name|ThreadSP
name|GetKernelThread
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Broadcaster event bits definitions.
comment|//------------------------------------------------------------------
name|CommunicationKDP
name|m_comm
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
name|ConstString
name|m_dyld_plugin_name
block|;
name|lldb
operator|::
name|addr_t
name|m_kernel_load_addr
block|;
name|lldb
operator|::
name|CommandObjectSP
name|m_command_sp
block|;
name|lldb
operator|::
name|ThreadWP
name|m_kernel_thread_wp
block|;
name|bool
name|StartAsyncThread
argument_list|()
block|;
name|void
name|StopAsyncThread
argument_list|()
block|;
specifier|static
name|void
operator|*
name|AsyncThread
argument_list|(
name|void
operator|*
name|arg
argument_list|)
block|;
name|private
operator|:
comment|//------------------------------------------------------------------
comment|// For ProcessKDP only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ProcessKDP
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ProcessKDP_h_
end_comment

end_unit

