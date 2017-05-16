begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PlatformAppleTVSimulator.h ------------------------------*- C++ -*-===//
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
name|liblldb_PlatformAppleTVSimulator_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_PlatformAppleTVSimulator_h_
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
file|"PlatformDarwin.h"
end_include

begin_decl_stmt
name|class
name|PlatformAppleTVSimulator
range|:
name|public
name|PlatformDarwin
block|{
name|public
operator|:
comment|//------------------------------------------------------------
comment|// Class Functions
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
name|GetDescriptionStatic
argument_list|()
block|;
comment|//------------------------------------------------------------
comment|// Class Methods
comment|//------------------------------------------------------------
name|PlatformAppleTVSimulator
argument_list|()
block|;
name|virtual
operator|~
name|PlatformAppleTVSimulator
argument_list|()
block|;
comment|//------------------------------------------------------------
comment|// lldb_private::PluginInterface functions
comment|//------------------------------------------------------------
name|lldb_private
operator|::
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
name|lldb_private
operator|::
name|Status
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
specifier|const
name|char
operator|*
name|GetDescription
argument_list|()
name|override
block|{
return|return
name|GetDescriptionStatic
argument_list|()
return|;
block|}
name|void
name|GetStatus
argument_list|(
argument|lldb_private::Stream&strm
argument_list|)
name|override
block|;
name|virtual
name|lldb_private
operator|::
name|Status
name|GetSymbolFile
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
name|uint32_t
name|FindProcesses
argument_list|(
argument|const lldb_private::ProcessInstanceInfoMatch&match_info
argument_list|,
argument|lldb_private::ProcessInstanceInfoList&process_infos
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
name|AddClangModuleCompilationOptions
argument_list|(
argument|lldb_private::Target *target
argument_list|,
argument|std::vector<std::string>&options
argument_list|)
name|override
block|{
return|return
name|PlatformDarwin
operator|::
name|AddClangModuleCompilationOptionsForSDKType
argument_list|(
name|target
argument_list|,
name|options
argument_list|,
name|PlatformDarwin
operator|::
name|SDKType
operator|::
name|iPhoneSimulator
argument_list|)
return|;
block|}
name|protected
operator|:
name|std
operator|::
name|mutex
name|m_sdk_dir_mutex
block|;
name|std
operator|::
name|string
name|m_sdk_directory
block|;
name|std
operator|::
name|string
name|m_build_update
block|;
specifier|const
name|char
operator|*
name|GetSDKDirectoryAsCString
argument_list|()
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|PlatformAppleTVSimulator
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_PlatformAppleTVSimulator_h_
end_comment

end_unit

