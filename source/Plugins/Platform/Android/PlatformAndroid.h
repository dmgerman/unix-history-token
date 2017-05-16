begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PlatformAndroid.h ---------------------------------------*- C++ -*-===//
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
name|liblldb_PlatformAndroid_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_PlatformAndroid_h_
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
file|<memory>
end_include

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
file|"Plugins/Platform/Linux/PlatformLinux.h"
end_include

begin_include
include|#
directive|include
file|"AdbClient.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|platform_android
block|{
name|class
name|PlatformAndroid
range|:
name|public
name|platform_linux
operator|::
name|PlatformLinux
block|{
name|public
operator|:
name|PlatformAndroid
argument_list|(
argument|bool is_host
argument_list|)
block|;
operator|~
name|PlatformAndroid
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
name|Status
name|ConnectRemote
argument_list|(
argument|Args&args
argument_list|)
name|override
block|;
name|Status
name|GetFile
argument_list|(
argument|const FileSpec&source
argument_list|,
argument|const FileSpec&destination
argument_list|)
name|override
block|;
name|Status
name|PutFile
argument_list|(
argument|const FileSpec&source
argument_list|,
argument|const FileSpec&destination
argument_list|,
argument|uint32_t uid = UINT32_MAX
argument_list|,
argument|uint32_t gid = UINT32_MAX
argument_list|)
name|override
block|;
name|uint32_t
name|GetSdkVersion
argument_list|()
block|;
name|bool
name|GetRemoteOSVersion
argument_list|()
name|override
block|;
name|Status
name|DisconnectRemote
argument_list|()
name|override
block|;
name|uint32_t
name|GetDefaultMemoryCacheLineSize
argument_list|()
name|override
block|;
name|protected
operator|:
specifier|const
name|char
operator|*
name|GetCacheHostname
argument_list|()
name|override
block|;
name|Status
name|DownloadModuleSlice
argument_list|(
argument|const FileSpec&src_file_spec
argument_list|,
argument|const uint64_t src_offset
argument_list|,
argument|const uint64_t src_size
argument_list|,
argument|const FileSpec&dst_file_spec
argument_list|)
name|override
block|;
name|Status
name|DownloadSymbolFile
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|,
argument|const FileSpec&dst_file_spec
argument_list|)
name|override
block|;
specifier|const
name|char
operator|*
name|GetLibdlFunctionDeclarations
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
name|AdbClient
operator|::
name|SyncService
operator|*
name|GetSyncService
argument_list|(
name|Status
operator|&
name|error
argument_list|)
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|AdbClient
operator|::
name|SyncService
operator|>
name|m_adb_sync_svc
block|;
name|std
operator|::
name|string
name|m_device_id
block|;
name|uint32_t
name|m_sdk_version
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|PlatformAndroid
argument_list|)
block|; }
decl_stmt|;
block|}
comment|// namespace platofor_android
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
comment|// liblldb_PlatformAndroid_h_
end_comment

end_unit

