begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PlatformPOSIX.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_PlatformPOSIX_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_PlatformPOSIX_h_
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
file|<map>
end_include

begin_include
include|#
directive|include
file|<memory>
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
file|"lldb/Interpreter/Options.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Platform.h"
end_include

begin_decl_stmt
name|class
name|PlatformPOSIX
range|:
name|public
name|lldb_private
operator|::
name|Platform
block|{
name|public
operator|:
name|PlatformPOSIX
argument_list|(
argument|bool is_host
argument_list|)
block|;
operator|~
name|PlatformPOSIX
argument_list|()
name|override
block|;
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
name|lldb_private
operator|::
name|OptionGroupOptions
operator|*
name|GetConnectionOptions
argument_list|(
argument|lldb_private::CommandInterpreter&interpreter
argument_list|)
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
name|lldb_private
operator|::
name|Error
name|PutFile
argument_list|(
argument|const lldb_private::FileSpec&source
argument_list|,
argument|const lldb_private::FileSpec&destination
argument_list|,
argument|uint32_t uid = UINT32_MAX
argument_list|,
argument|uint32_t gid = UINT32_MAX
argument_list|)
name|override
block|;
name|lldb
operator|::
name|user_id_t
name|OpenFile
argument_list|(
argument|const lldb_private::FileSpec&file_spec
argument_list|,
argument|uint32_t flags
argument_list|,
argument|uint32_t mode
argument_list|,
argument|lldb_private::Error&error
argument_list|)
name|override
block|;
name|bool
name|CloseFile
argument_list|(
argument|lldb::user_id_t fd
argument_list|,
argument|lldb_private::Error&error
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
argument|void *dst
argument_list|,
argument|uint64_t dst_len
argument_list|,
argument|lldb_private::Error&error
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
argument|const void *src
argument_list|,
argument|uint64_t src_len
argument_list|,
argument|lldb_private::Error&error
argument_list|)
name|override
block|;
name|lldb
operator|::
name|user_id_t
name|GetFileSize
argument_list|(
argument|const lldb_private::FileSpec&file_spec
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|CreateSymlink
argument_list|(
argument|const lldb_private::FileSpec&src
argument_list|,
argument|const lldb_private::FileSpec&dst
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|GetFile
argument_list|(
argument|const lldb_private::FileSpec&source
argument_list|,
argument|const lldb_private::FileSpec&destination
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|FileSpec
name|GetRemoteWorkingDirectory
argument_list|()
name|override
block|;
name|bool
name|SetRemoteWorkingDirectory
argument_list|(
argument|const lldb_private::FileSpec&working_dir
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
name|lldb_private
operator|::
name|ArchSpec
name|GetRemoteSystemArchitecture
argument_list|()
name|override
block|;
specifier|const
name|lldb
operator|::
name|UnixSignalsSP
operator|&
name|GetRemoteUnixSignals
argument_list|()
name|override
block|;
name|size_t
name|GetEnvironment
argument_list|(
argument|lldb_private::StringList&environment
argument_list|)
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
name|Error
name|RunShellCommand
argument_list|(
argument|const char *command
argument_list|,
comment|// Shouldn't be nullptr
argument|const lldb_private::FileSpec&working_dir
argument_list|,
comment|// Pass empty FileSpec to use
comment|// the current working
comment|// directory
argument|int *status_ptr
argument_list|,
comment|// Pass nullptr if you don't want the process exit status
argument|int *signo_ptr
argument_list|,
comment|// Pass nullptr if you don't want the signal that caused
comment|// the process to exit
argument|std::string           *command_output
argument_list|,
comment|// Pass nullptr if you don't want the command output
argument|uint32_t timeout_sec
argument_list|)
name|override
block|;
comment|// Timeout in seconds to wait for shell program to finish
name|lldb_private
operator|::
name|Error
name|ResolveExecutable
argument_list|(
argument|const lldb_private::ModuleSpec&module_spec
argument_list|,
argument|lldb::ModuleSP&module_sp
argument_list|,
argument|const lldb_private::FileSpecList *module_search_paths_ptr
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
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
name|Error
name|MakeDirectory
argument_list|(
argument|const lldb_private::FileSpec&file_spec
argument_list|,
argument|uint32_t mode
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|GetFilePermissions
argument_list|(
argument|const lldb_private::FileSpec&file_spec
argument_list|,
argument|uint32_t&file_permissions
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|SetFilePermissions
argument_list|(
argument|const lldb_private::FileSpec&file_spec
argument_list|,
argument|uint32_t file_permissions
argument_list|)
name|override
block|;
name|bool
name|GetFileExists
argument_list|(
argument|const lldb_private::FileSpec&file_spec
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|Unlink
argument_list|(
argument|const lldb_private::FileSpec&file_spec
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|LaunchProcess
argument_list|(
argument|lldb_private::ProcessLaunchInfo&launch_info
argument_list|)
name|override
block|;
name|lldb_private
operator|::
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
name|Attach
argument_list|(
argument|lldb_private::ProcessAttachInfo&attach_info
argument_list|,
argument|lldb_private::Debugger&debugger
argument_list|,
argument|lldb_private::Target *target
argument_list|,
comment|// Can be nullptr, if
comment|// nullptr create a new
comment|// target, else use
comment|// existing one
argument|lldb_private::Error&error
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
comment|// Can be nullptr,
comment|// if nullptr
comment|// create a new
comment|// target, else use
comment|// existing one
argument|lldb_private::Error&error
argument_list|)
name|override
block|;
name|std
operator|::
name|string
name|GetPlatformSpecificConnectionInformation
argument_list|()
name|override
block|;
name|bool
name|CalculateMD5
argument_list|(
argument|const lldb_private::FileSpec&file_spec
argument_list|,
argument|uint64_t&low
argument_list|,
argument|uint64_t&high
argument_list|)
name|override
block|;
name|void
name|CalculateTrapHandlerSymbolNames
argument_list|()
name|override
block|;
name|lldb_private
operator|::
name|Error
name|ConnectRemote
argument_list|(
argument|lldb_private::Args&args
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|DisconnectRemote
argument_list|()
name|override
block|;
name|uint32_t
name|DoLoadImage
argument_list|(
argument|lldb_private::Process *process
argument_list|,
argument|const lldb_private::FileSpec&remote_file
argument_list|,
argument|lldb_private::Error&error
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|UnloadImage
argument_list|(
argument|lldb_private::Process *process
argument_list|,
argument|uint32_t image_token
argument_list|)
name|override
block|;
name|lldb
operator|::
name|ProcessSP
name|ConnectProcess
argument_list|(
argument|llvm::StringRef connect_url
argument_list|,
argument|llvm::StringRef plugin_name
argument_list|,
argument|lldb_private::Debugger&debugger
argument_list|,
argument|lldb_private::Target *target
argument_list|,
argument|lldb_private::Error&error
argument_list|)
name|override
block|;
name|size_t
name|ConnectToWaitingProcesses
argument_list|(
argument|lldb_private::Debugger&debugger
argument_list|,
argument|lldb_private::Error&error
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|ConstString
name|GetFullNameForDylib
argument_list|(
argument|lldb_private::ConstString basename
argument_list|)
name|override
block|;
name|protected
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|OptionGroupPlatformRSync
operator|>
name|m_option_group_platform_rsync
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|OptionGroupPlatformSSH
operator|>
name|m_option_group_platform_ssh
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|OptionGroupPlatformCaching
operator|>
name|m_option_group_platform_caching
block|;
name|std
operator|::
name|map
operator|<
name|lldb_private
operator|::
name|CommandInterpreter
operator|*
block|,
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|OptionGroupOptions
operator|>>
name|m_options
block|;
name|lldb
operator|::
name|PlatformSP
name|m_remote_platform_sp
block|;
comment|// Allow multiple ways to connect to a
comment|// remote POSIX-compliant OS
name|lldb_private
operator|::
name|Error
name|EvaluateLibdlExpression
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|,
specifier|const
name|char
operator|*
name|expr_cstr
argument_list|,
specifier|const
name|char
operator|*
name|expr_prefix
argument_list|,
name|lldb
operator|::
name|ValueObjectSP
operator|&
name|result_valobj_sp
argument_list|)
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetLibdlFunctionDeclarations
argument_list|()
specifier|const
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|PlatformPOSIX
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_PlatformPOSIX_h_
end_comment

end_unit

