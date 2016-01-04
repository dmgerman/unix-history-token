begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PlatformFreeBSD.h ---------------------------------------*- C++ -*-===//
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
name|liblldb_PlatformFreeBSD_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_PlatformFreeBSD_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

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

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|platform_freebsd
block|{
name|class
name|PlatformFreeBSD
range|:
name|public
name|Platform
block|{
name|public
operator|:
name|PlatformFreeBSD
argument_list|(
argument|bool is_host
argument_list|)
block|;
operator|~
name|PlatformFreeBSD
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------
comment|// Class functions
comment|//------------------------------------------------------------
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
name|ConstString
name|GetPluginNameStatic
argument_list|(
argument|bool is_host
argument_list|)
block|;
specifier|static
specifier|const
name|char
operator|*
name|GetDescriptionStatic
argument_list|(
argument|bool is_host
argument_list|)
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
argument_list|(
name|IsHost
argument_list|()
argument_list|)
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
specifier|const
name|char
operator|*
name|GetDescription
argument_list|()
name|override
block|{
return|return
name|GetDescriptionStatic
argument_list|(
name|IsHost
argument_list|()
argument_list|)
return|;
block|}
comment|//------------------------------------------------------------
comment|// lldb_private::Platform functions
comment|//------------------------------------------------------------
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
name|Error
name|RunShellCommand
argument_list|(
argument|const char *command
argument_list|,
argument|const FileSpec&working_dir
argument_list|,
argument|int *status_ptr
argument_list|,
argument|int *signo_ptr
argument_list|,
argument|std::string *command_output
argument_list|,
argument|uint32_t timeout_sec
argument_list|)
name|override
block|;
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
argument|Error&error
argument_list|)
name|override
block|;
comment|// FreeBSD processes can not be launched by spawning and attaching.
name|bool
name|CanDebugProcess
argument_list|()
name|override
block|{
return|return
name|false
return|;
block|}
comment|// Only on PlatformMacOSX:
name|Error
name|GetFileWithUUID
argument_list|(
argument|const FileSpec&platform_file
argument_list|,
argument|const UUID* uuid
argument_list|,
argument|FileSpec&local_file
argument_list|)
name|override
block|;
name|Error
name|GetSharedModule
argument_list|(
argument|const ModuleSpec&module_spec
argument_list|,
argument|Process* process
argument_list|,
argument|lldb::ModuleSP&module_sp
argument_list|,
argument|const FileSpecList *module_search_paths_ptr
argument_list|,
argument|lldb::ModuleSP *old_module_sp_ptr
argument_list|,
argument|bool *did_create_ptr
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
name|void
name|GetStatus
argument_list|(
argument|Stream&strm
argument_list|)
name|override
block|;
name|void
name|CalculateTrapHandlerSymbolNames
argument_list|()
name|override
block|;
name|protected
operator|:
name|lldb
operator|::
name|PlatformSP
name|m_remote_platform_sp
block|;
comment|// Allow multiple ways to connect to a remote freebsd OS
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|PlatformFreeBSD
argument_list|)
block|;     }
decl_stmt|;
block|}
comment|// namespace platform_freebsd
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
comment|// liblldb_PlatformFreeBSD_h_
end_comment

end_unit

