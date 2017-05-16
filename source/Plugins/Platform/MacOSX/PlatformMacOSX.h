begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PlatformMacOSX.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_PlatformMacOSX_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_PlatformMacOSX_h_
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
name|PlatformMacOSX
range|:
name|public
name|PlatformDarwin
block|{
name|public
operator|:
name|PlatformMacOSX
argument_list|(
argument|bool is_host
argument_list|)
block|;
operator|~
name|PlatformMacOSX
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
name|lldb_private
operator|::
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
name|GetFile
argument_list|(
argument|const lldb_private::FileSpec&source
argument_list|,
argument|const lldb_private::FileSpec&destination
argument_list|)
name|override
block|{
return|return
name|PlatformDarwin
operator|::
name|GetFile
argument_list|(
name|source
argument_list|,
name|destination
argument_list|)
return|;
block|}
name|lldb_private
operator|::
name|Status
name|GetFileWithUUID
argument_list|(
argument|const lldb_private::FileSpec&platform_file
argument_list|,
argument|const lldb_private::UUID *uuid_ptr
argument_list|,
argument|lldb_private::FileSpec&local_file
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
name|lldb_private
operator|::
name|ConstString
name|GetSDKDirectory
argument_list|(
argument|lldb_private::Target&target
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
name|MacOSX
argument_list|)
return|;
block|}
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|PlatformMacOSX
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_PlatformMacOSX_h_
end_comment

end_unit

