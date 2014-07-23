begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PlatformRemoteGDBServer.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_PlatformRemoteGDBServer_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_PlatformRemoteGDBServer_h_
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
file|<string>
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
file|"lldb/Target/Platform.h"
end_include

begin_include
include|#
directive|include
file|"../../Process/gdb-remote/GDBRemoteCommunicationClient.h"
end_include

begin_decl_stmt
name|class
name|PlatformRemoteGDBServer
range|:
name|public
name|lldb_private
operator|::
name|Platform
block|{
name|public
operator|:
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
name|Platform
operator|*
name|CreateInstance
argument_list|(
argument|bool force
argument_list|,
argument|const lldb_private::ArchSpec *arch
argument_list|)
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
name|GetDescriptionStatic
argument_list|()
block|;
name|PlatformRemoteGDBServer
argument_list|()
block|;
name|virtual
operator|~
name|PlatformRemoteGDBServer
argument_list|()
block|;
comment|//------------------------------------------------------------
comment|// lldb_private::PluginInterface functions
comment|//------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
block|{
return|return
name|GetPluginNameStatic
argument_list|()
return|;
block|}
name|virtual
name|uint32_t
name|GetPluginVersion
argument_list|()
block|{
return|return
literal|1
return|;
block|}
comment|//------------------------------------------------------------
comment|// lldb_private::Platform functions
comment|//------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|Error
name|ResolveExecutable
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|exe_file
argument_list|,
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|,
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|,
specifier|const
name|lldb_private
operator|::
name|FileSpecList
operator|*
name|module_search_paths_ptr
argument_list|)
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetDescription
argument_list|()
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|GetFileWithUUID
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|platform_file
argument_list|,
specifier|const
name|lldb_private
operator|::
name|UUID
operator|*
name|uuid_ptr
argument_list|,
name|lldb_private
operator|::
name|FileSpec
operator|&
name|local_file
argument_list|)
block|;
name|virtual
name|bool
name|GetProcessInfo
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|lldb_private::ProcessInstanceInfo&proc_info
argument_list|)
block|;
name|virtual
name|uint32_t
name|FindProcesses
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ProcessInstanceInfoMatch
operator|&
name|match_info
argument_list|,
name|lldb_private
operator|::
name|ProcessInstanceInfoList
operator|&
name|process_infos
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|LaunchProcess
argument_list|(
name|lldb_private
operator|::
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|ProcessSP
name|DebugProcess
argument_list|(
name|lldb_private
operator|::
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|,
name|lldb_private
operator|::
name|Debugger
operator|&
name|debugger
argument_list|,
name|lldb_private
operator|::
name|Target
operator|*
name|target
argument_list|,
comment|// Can be NULL, if NULL create a new target, else use existing one
name|lldb_private
operator|::
name|Listener
operator|&
name|listener
argument_list|,
name|lldb_private
operator|::
name|Error
operator|&
name|error
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|ProcessSP
name|Attach
argument_list|(
name|lldb_private
operator|::
name|ProcessAttachInfo
operator|&
name|attach_info
argument_list|,
name|lldb_private
operator|::
name|Debugger
operator|&
name|debugger
argument_list|,
name|lldb_private
operator|::
name|Target
operator|*
name|target
argument_list|,
comment|// Can be NULL, if NULL create a new target, else use existing one
name|lldb_private
operator|::
name|Listener
operator|&
name|listener
argument_list|,
name|lldb_private
operator|::
name|Error
operator|&
name|error
argument_list|)
block|;
name|virtual
name|bool
name|GetSupportedArchitectureAtIndex
argument_list|(
argument|uint32_t idx
argument_list|,
argument|lldb_private::ArchSpec&arch
argument_list|)
block|;
name|virtual
name|size_t
name|GetSoftwareBreakpointTrapOpcode
argument_list|(
name|lldb_private
operator|::
name|Target
operator|&
name|target
argument_list|,
name|lldb_private
operator|::
name|BreakpointSite
operator|*
name|bp_site
argument_list|)
block|;
name|virtual
name|bool
name|GetRemoteOSVersion
argument_list|()
block|;
name|virtual
name|bool
name|GetRemoteOSBuildString
argument_list|(
name|std
operator|::
name|string
operator|&
name|s
argument_list|)
block|;
name|virtual
name|bool
name|GetRemoteOSKernelDescription
argument_list|(
name|std
operator|::
name|string
operator|&
name|s
argument_list|)
block|;
comment|// Remote Platform subclasses need to override this function
name|virtual
name|lldb_private
operator|::
name|ArchSpec
name|GetRemoteSystemArchitecture
argument_list|()
block|;
name|virtual
name|lldb_private
operator|::
name|ConstString
name|GetRemoteWorkingDirectory
argument_list|()
block|;
name|virtual
name|bool
name|SetRemoteWorkingDirectory
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ConstString
operator|&
name|path
argument_list|)
block|;
comment|// Remote subclasses should override this and return a valid instance
comment|// name if connected.
name|virtual
specifier|const
name|char
operator|*
name|GetHostname
argument_list|()
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetUserName
argument_list|(
argument|uint32_t uid
argument_list|)
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetGroupName
argument_list|(
argument|uint32_t gid
argument_list|)
block|;
name|virtual
name|bool
name|IsConnected
argument_list|()
specifier|const
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|ConnectRemote
argument_list|(
name|lldb_private
operator|::
name|Args
operator|&
name|args
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DisconnectRemote
argument_list|()
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|MakeDirectory
argument_list|(
argument|const char *path
argument_list|,
argument|uint32_t file_permissions
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|GetFilePermissions
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|,
name|uint32_t
operator|&
name|file_permissions
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|SetFilePermissions
argument_list|(
argument|const char *path
argument_list|,
argument|uint32_t file_permissions
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|user_id_t
name|OpenFile
argument_list|(
argument|const lldb_private::FileSpec& file_spec
argument_list|,
argument|uint32_t flags
argument_list|,
argument|uint32_t mode
argument_list|,
argument|lldb_private::Error&error
argument_list|)
block|;
name|virtual
name|bool
name|CloseFile
argument_list|(
argument|lldb::user_id_t fd
argument_list|,
argument|lldb_private::Error&error
argument_list|)
block|;
name|virtual
name|uint64_t
name|ReadFile
argument_list|(
argument|lldb::user_id_t fd
argument_list|,
argument|uint64_t offset
argument_list|,
argument|void *data_ptr
argument_list|,
argument|uint64_t len
argument_list|,
argument|lldb_private::Error&error
argument_list|)
block|;
name|virtual
name|uint64_t
name|WriteFile
argument_list|(
argument|lldb::user_id_t fd
argument_list|,
argument|uint64_t offset
argument_list|,
argument|const void* data
argument_list|,
argument|uint64_t len
argument_list|,
argument|lldb_private::Error&error
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|user_id_t
name|GetFileSize
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|PutFile
argument_list|(
argument|const lldb_private::FileSpec& source
argument_list|,
argument|const lldb_private::FileSpec& destination
argument_list|,
argument|uint32_t uid = UINT32_MAX
argument_list|,
argument|uint32_t gid = UINT32_MAX
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|CreateSymlink
argument_list|(
specifier|const
name|char
operator|*
name|src
argument_list|,
specifier|const
name|char
operator|*
name|dst
argument_list|)
block|;
name|virtual
name|bool
name|GetFileExists
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|Unlink
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|RunShellCommand
argument_list|(
argument|const char *command
argument_list|,
comment|// Shouldn't be NULL
argument|const char *working_dir
argument_list|,
comment|// Pass NULL to use the current working directory
argument|int *status_ptr
argument_list|,
comment|// Pass NULL if you don't want the process exit status
argument|int *signo_ptr
argument_list|,
comment|// Pass NULL if you don't want the signal that caused the process to exit
argument|std::string *command_output
argument_list|,
comment|// Pass NULL if you don't want the command output
argument|uint32_t timeout_sec
argument_list|)
block|;
comment|// Timeout in seconds to wait for shell program to finish
name|virtual
name|void
name|CalculateTrapHandlerSymbolNames
argument_list|()
block|;
name|protected
operator|:
name|GDBRemoteCommunicationClient
name|m_gdb_client
block|;
name|std
operator|::
name|string
name|m_platform_description
block|;
comment|// After we connect we can get a more complete description of what we are connected to
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|PlatformRemoteGDBServer
argument_list|)
block|;  }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_PlatformRemoteGDBServer_h_
end_comment

end_unit

