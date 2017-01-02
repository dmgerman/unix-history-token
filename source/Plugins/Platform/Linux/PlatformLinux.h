begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PlatformLinux.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_PlatformLinux_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_PlatformLinux_h_
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
file|"Plugins/Platform/POSIX/PlatformPOSIX.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|platform_linux
block|{
name|class
name|PlatformLinux
range|:
name|public
name|PlatformPOSIX
block|{
name|public
operator|:
name|PlatformLinux
argument_list|(
argument|bool is_host
argument_list|)
block|;
operator|~
name|PlatformLinux
argument_list|()
name|override
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
argument|const ArchSpec *arch
argument_list|)
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
name|GetPluginDescriptionStatic
argument_list|(
argument|bool is_host
argument_list|)
block|;
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
name|void
name|GetStatus
argument_list|(
argument|Stream&strm
argument_list|)
name|override
block|;
name|Error
name|GetFileWithUUID
argument_list|(
argument|const FileSpec&platform_file
argument_list|,
argument|const UUID *uuid
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
name|bool
name|GetSupportedArchitectureAtIndex
argument_list|(
argument|uint32_t idx
argument_list|,
argument|ArchSpec&arch
argument_list|)
name|override
block|;
name|int32_t
name|GetResumeCountForLaunchInfo
argument_list|(
argument|ProcessLaunchInfo&launch_info
argument_list|)
name|override
block|;
name|bool
name|CanDebugProcess
argument_list|()
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
argument|Error&error
argument_list|)
name|override
block|;
name|void
name|CalculateTrapHandlerSymbolNames
argument_list|()
name|override
block|;
name|uint64_t
name|ConvertMmapFlagsToPlatform
argument_list|(
argument|const ArchSpec&arch
argument_list|,
argument|unsigned flags
argument_list|)
name|override
block|;
name|ConstString
name|GetFullNameForDylib
argument_list|(
argument|ConstString basename
argument_list|)
name|override
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|PlatformLinux
argument_list|)
block|; }
decl_stmt|;
block|}
comment|// namespace platform_linux
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
comment|// liblldb_PlatformLinux_h_
end_comment

end_unit

