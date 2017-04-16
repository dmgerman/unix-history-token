begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PlatformRemoteAppleTV.h ---------------------------------*- C++ -*-===//
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
name|liblldb_PlatformRemoteAppleTV_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_PlatformRemoteAppleTV_h_
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
file|"lldb/Utility/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FileSystem.h"
end_include

begin_include
include|#
directive|include
file|"PlatformDarwin.h"
end_include

begin_decl_stmt
name|class
name|PlatformRemoteAppleTV
range|:
name|public
name|PlatformDarwin
block|{
name|public
operator|:
name|PlatformRemoteAppleTV
argument_list|()
block|;
operator|~
name|PlatformRemoteAppleTV
argument_list|()
name|override
operator|=
expr|default
block|;
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
name|Error
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
name|Error
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
name|iPhoneOS
argument_list|)
return|;
block|}
name|protected
operator|:
expr|struct
name|SDKDirectoryInfo
block|{
name|SDKDirectoryInfo
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|sdk_dir_spec
argument_list|)
block|;
name|lldb_private
operator|::
name|FileSpec
name|directory
block|;
name|lldb_private
operator|::
name|ConstString
name|build
block|;
name|uint32_t
name|version_major
block|;
name|uint32_t
name|version_minor
block|;
name|uint32_t
name|version_update
block|;
name|bool
name|user_cached
block|;   }
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|SDKDirectoryInfo
operator|>
name|SDKDirectoryInfoCollection
expr_stmt|;
name|std
operator|::
name|mutex
name|m_sdk_dir_mutex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDKDirectoryInfoCollection
name|m_sdk_directory_infos
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|m_device_support_directory
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|m_device_support_directory_for_os_version
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|m_build_update
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|uint32_t
name|m_last_module_sdk_idx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|m_connected_module_sdk_idx
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|UpdateSDKDirectoryInfosIfNeeded
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|GetDeviceSupportDirectory
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|GetDeviceSupportDirectoryForOSVersion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|SDKDirectoryInfo
modifier|*
name|GetSDKDirectoryForLatestOSVersion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|SDKDirectoryInfo
modifier|*
name|GetSDKDirectoryForCurrentOSVersion
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|static
name|lldb_private
operator|::
name|FileSpec
operator|::
name|EnumerateDirectoryResult
name|GetContainedFilesIntoVectorOfStringsCallback
argument_list|(
argument|void *baton
argument_list|,
argument|llvm::sys::fs::file_type ft
argument_list|,
argument|const lldb_private::FileSpec&file_spec
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|uint32_t
name|FindFileInAllSDKs
argument_list|(
specifier|const
name|char
operator|*
name|platform_file_path
argument_list|,
name|lldb_private
operator|::
name|FileSpecList
operator|&
name|file_list
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|GetFileInSDK
argument_list|(
specifier|const
name|char
operator|*
name|platform_file_path
argument_list|,
name|uint32_t
name|sdk_idx
argument_list|,
name|lldb_private
operator|::
name|FileSpec
operator|&
name|local_file
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|FindFileInAllSDKs
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|platform_file
argument_list|,
name|lldb_private
operator|::
name|FileSpecList
operator|&
name|file_list
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|uint32_t
name|GetConnectedSDKIndex
parameter_list|()
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|PlatformRemoteAppleTV
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_PlatformRemoteAppleTV_h_
end_comment

end_unit

