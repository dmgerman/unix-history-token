begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PlatformWindows.h ---------------------------------------*- C++ -*-===//
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
name|liblldb_PlatformWindows_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_PlatformWindows_h_
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
name|class
name|PlatformWindows
range|:
name|public
name|Platform
block|{
name|public
operator|:
name|PlatformWindows
argument_list|(
argument|bool is_host
argument_list|)
block|;
operator|~
name|PlatformWindows
argument_list|()
name|override
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
comment|//------------------------------------------------------------
comment|// lldb_private::PluginInterface functions
comment|//------------------------------------------------------------
specifier|static
name|lldb
operator|::
name|PlatformSP
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
argument_list|(
argument|bool is_host
argument_list|)
block|;
specifier|static
specifier|const
name|char
operator|*
name|GetPluginDescriptionStatic
argument_list|(
argument|bool is_host
argument_list|)
block|;
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
block|{
return|return
literal|1
return|;
block|}
comment|//------------------------------------------------------------
comment|// lldb_private::Platform functions
comment|//------------------------------------------------------------
name|bool
name|GetModuleSpec
argument_list|(
argument|const lldb_private::FileSpec&module_file_spec
argument_list|,
argument|const lldb_private::ArchSpec&arch
argument_list|,
argument|lldb_private::ModuleSpec&module_spec
argument_list|)
name|override
block|;
name|Status
name|ResolveExecutable
argument_list|(
argument|const lldb_private::ModuleSpec&module_spec
argument_list|,
argument|lldb::ModuleSP&module_sp
argument_list|,
argument|const FileSpecList *module_search_paths_ptr
argument_list|)
name|override
block|;
specifier|const
name|char
operator|*
name|GetDescription
argument_list|()
name|override
block|{
return|return
name|GetPluginDescriptionStatic
argument_list|(
name|IsHost
argument_list|()
argument_list|)
return|;
block|}
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
name|lldb_private
operator|::
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
name|lldb_private
operator|::
name|Status
name|ConnectRemote
argument_list|(
argument|lldb_private::Args&args
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Status
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
argument|lldb_private::ProcessInstanceInfo&proc_info
argument_list|)
name|override
block|;
name|uint32_t
name|FindProcesses
argument_list|(
argument|const lldb_private::ProcessInstanceInfoMatch&match_info
argument_list|,
argument|lldb_private::ProcessInstanceInfoList&process_infos
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Status
name|LaunchProcess
argument_list|(
argument|lldb_private::ProcessLaunchInfo&launch_info
argument_list|)
name|override
block|;
name|lldb
operator|::
name|ProcessSP
name|DebugProcess
argument_list|(
argument|lldb_private::ProcessLaunchInfo&launch_info
argument_list|,
argument|lldb_private::Debugger&debugger
argument_list|,
argument|lldb_private::Target *target
argument_list|,
argument|lldb_private::Status&error
argument_list|)
name|override
block|;
name|lldb
operator|::
name|ProcessSP
name|Attach
argument_list|(
argument|lldb_private::ProcessAttachInfo&attach_info
argument_list|,
argument|lldb_private::Debugger&debugger
argument_list|,
argument|lldb_private::Target *target
argument_list|,
argument|lldb_private::Status&error
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Status
name|GetFileWithUUID
argument_list|(
argument|const lldb_private::FileSpec&platform_file
argument_list|,
argument|const lldb_private::UUID *uuid
argument_list|,
argument|lldb_private::FileSpec&local_file
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Status
name|GetSharedModule
argument_list|(
argument|const lldb_private::ModuleSpec&module_spec
argument_list|,
argument|lldb_private::Process *process
argument_list|,
argument|lldb::ModuleSP&module_sp
argument_list|,
argument|const lldb_private::FileSpecList *module_search_paths_ptr
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
argument|lldb_private::ArchSpec&arch
argument_list|)
name|override
block|;
name|void
name|GetStatus
argument_list|(
argument|lldb_private::Stream&strm
argument_list|)
name|override
block|;
name|bool
name|CanDebugProcess
argument_list|()
name|override
block|;
name|size_t
name|GetEnvironment
argument_list|(
argument|StringList&env
argument_list|)
name|override
block|;
comment|// FIXME not sure what the _sigtramp equivalent would be on this platform
name|void
name|CalculateTrapHandlerSymbolNames
argument_list|()
name|override
block|{}
name|ConstString
name|GetFullNameForDylib
argument_list|(
argument|ConstString basename
argument_list|)
name|override
block|;
name|protected
operator|:
name|lldb
operator|::
name|PlatformSP
name|m_remote_platform_sp
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|PlatformWindows
argument_list|)
block|; }
decl_stmt|;
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
comment|// liblldb_PlatformWindows_h_
end_comment

end_unit

