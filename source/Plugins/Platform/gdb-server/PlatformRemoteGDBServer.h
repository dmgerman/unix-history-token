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
name|namespace
name|lldb_private
block|{
name|namespace
name|platform_gdb_server
block|{
name|class
name|PlatformRemoteGDBServer
range|:
name|public
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
name|lldb
operator|::
name|PlatformSP
name|CreateInstance
argument_list|(
argument|bool force
argument_list|,
argument|const ArchSpec *arch
argument_list|)
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
name|ConstString
name|GetPluginName
argument_list|()
name|override
block|{
return|return
name|GetPluginNameStatic
argument_list|()
return|;
block|}
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
block|{
return|return
literal|1
return|;
block|}
comment|//------------------------------------------------------------
comment|// lldb_private::Platform functions
comment|//------------------------------------------------------------
name|Error
name|ResolveExecutable
argument_list|(
argument|const ModuleSpec&module_spec
argument_list|,
argument|lldb::ModuleSP&module_sp
argument_list|,
argument|const FileSpecList *module_search_paths_ptr
argument_list|)
name|override
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
specifier|const
name|char
operator|*
name|GetDescription
argument_list|()
name|override
block|;
name|Error
name|GetFileWithUUID
argument_list|(
argument|const FileSpec&platform_file
argument_list|,
argument|const UUID *uuid_ptr
argument_list|,
argument|FileSpec&local_file
argument_list|)
name|override
block|;
name|bool
name|GetProcessInfo
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|ProcessInstanceInfo&proc_info
argument_list|)
name|override
block|;
name|uint32_t
name|FindProcesses
argument_list|(
argument|const ProcessInstanceInfoMatch&match_info
argument_list|,
argument|ProcessInstanceInfoList&process_infos
argument_list|)
name|override
block|;
name|Error
name|LaunchProcess
argument_list|(
argument|ProcessLaunchInfo&launch_info
argument_list|)
name|override
block|;
name|Error
name|KillProcess
argument_list|(
argument|const lldb::pid_t pid
argument_list|)
name|override
block|;
name|lldb
operator|::
name|ProcessSP
name|DebugProcess
argument_list|(
argument|ProcessLaunchInfo&launch_info
argument_list|,
argument|Debugger&debugger
argument_list|,
argument|Target *target
argument_list|,
comment|// Can be NULL, if NULL create a new target, else use existing one
argument|Error&error
argument_list|)
name|override
block|;
name|lldb
operator|::
name|ProcessSP
name|Attach
argument_list|(
argument|ProcessAttachInfo&attach_info
argument_list|,
argument|Debugger&debugger
argument_list|,
argument|Target *target
argument_list|,
comment|// Can be NULL, if NULL create a new target, else use existing one
argument|Error&error
argument_list|)
name|override
block|;
name|bool
name|GetSupportedArchitectureAtIndex
argument_list|(
argument|uint32_t idx
argument_list|,
argument|ArchSpec&arch
argument_list|)
name|override
block|;
name|size_t
name|GetSoftwareBreakpointTrapOpcode
argument_list|(
argument|Target&target
argument_list|,
argument|BreakpointSite *bp_site
argument_list|)
name|override
block|;
name|bool
name|GetRemoteOSVersion
argument_list|()
name|override
block|;
name|bool
name|GetRemoteOSBuildString
argument_list|(
argument|std::string&s
argument_list|)
name|override
block|;
name|bool
name|GetRemoteOSKernelDescription
argument_list|(
argument|std::string&s
argument_list|)
name|override
block|;
comment|// Remote Platform subclasses need to override this function
name|ArchSpec
name|GetRemoteSystemArchitecture
argument_list|()
name|override
block|;
name|FileSpec
name|GetRemoteWorkingDirectory
argument_list|()
name|override
block|;
name|bool
name|SetRemoteWorkingDirectory
argument_list|(
argument|const FileSpec&working_dir
argument_list|)
name|override
block|;
comment|// Remote subclasses should override this and return a valid instance
comment|// name if connected.
specifier|const
name|char
operator|*
name|GetHostname
argument_list|()
name|override
block|;
specifier|const
name|char
operator|*
name|GetUserName
argument_list|(
argument|uint32_t uid
argument_list|)
name|override
block|;
specifier|const
name|char
operator|*
name|GetGroupName
argument_list|(
argument|uint32_t gid
argument_list|)
name|override
block|;
name|bool
name|IsConnected
argument_list|()
specifier|const
name|override
block|;
name|Error
name|ConnectRemote
argument_list|(
argument|Args& args
argument_list|)
name|override
block|;
name|Error
name|DisconnectRemote
argument_list|()
name|override
block|;
name|Error
name|MakeDirectory
argument_list|(
argument|const FileSpec&file_spec
argument_list|,
argument|uint32_t file_permissions
argument_list|)
name|override
block|;
name|Error
name|GetFilePermissions
argument_list|(
argument|const FileSpec&file_spec
argument_list|,
argument|uint32_t&file_permissions
argument_list|)
name|override
block|;
name|Error
name|SetFilePermissions
argument_list|(
argument|const FileSpec&file_spec
argument_list|,
argument|uint32_t file_permissions
argument_list|)
name|override
block|;
name|lldb
operator|::
name|user_id_t
name|OpenFile
argument_list|(
argument|const FileSpec& file_spec
argument_list|,
argument|uint32_t flags
argument_list|,
argument|uint32_t mode
argument_list|,
argument|Error&error
argument_list|)
name|override
block|;
name|bool
name|CloseFile
argument_list|(
argument|lldb::user_id_t fd
argument_list|,
argument|Error&error
argument_list|)
name|override
block|;
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
argument|Error&error
argument_list|)
name|override
block|;
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
argument|Error&error
argument_list|)
name|override
block|;
name|lldb
operator|::
name|user_id_t
name|GetFileSize
argument_list|(
argument|const FileSpec& file_spec
argument_list|)
name|override
block|;
name|Error
name|PutFile
argument_list|(
argument|const FileSpec& source
argument_list|,
argument|const FileSpec& destination
argument_list|,
argument|uint32_t uid = UINT32_MAX
argument_list|,
argument|uint32_t gid = UINT32_MAX
argument_list|)
name|override
block|;
name|Error
name|CreateSymlink
argument_list|(
argument|const FileSpec&src
argument_list|,
argument|const FileSpec&dst
argument_list|)
name|override
block|;
name|bool
name|GetFileExists
argument_list|(
argument|const FileSpec& file_spec
argument_list|)
name|override
block|;
name|Error
name|Unlink
argument_list|(
argument|const FileSpec&path
argument_list|)
name|override
block|;
name|Error
name|RunShellCommand
argument_list|(
argument|const char *command
argument_list|,
comment|// Shouldn't be NULL
argument|const FileSpec&working_dir
argument_list|,
comment|// Pass empty FileSpec to use the current working directory
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
name|override
block|;
comment|// Timeout in seconds to wait for shell program to finish
name|void
name|CalculateTrapHandlerSymbolNames
argument_list|()
name|override
block|;
name|protected
operator|:
name|process_gdb_remote
operator|::
name|GDBRemoteCommunicationClient
name|m_gdb_client
block|;
name|std
operator|::
name|string
name|m_platform_description
block|;
comment|// After we connect we can get a more complete description of what we are connected to
name|std
operator|::
name|string
name|m_platform_scheme
block|;
name|std
operator|::
name|string
name|m_platform_hostname
block|;
comment|// Launch the lldb-gdbserver on the remote host and return the port it is listening on or 0 on
comment|// failure. Subclasses should override this method if they want to do extra actions before or
comment|// after launching the lldb-gdbserver.
name|virtual
name|uint16_t
name|LaunchGDBserverAndGetPort
argument_list|(
name|lldb
operator|::
name|pid_t
operator|&
name|pid
argument_list|)
block|;
name|virtual
name|bool
name|KillSpawnedProcess
argument_list|(
argument|lldb::pid_t pid
argument_list|)
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|PlatformRemoteGDBServer
argument_list|)
block|;  }
decl_stmt|;
block|}
comment|// namespace platform_gdb_server
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
comment|// liblldb_PlatformRemoteGDBServer_h_
end_comment

end_unit

