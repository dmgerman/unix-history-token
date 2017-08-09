begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PlatformNetBSD.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_PlatformNetBSD_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_PlatformNetBSD_h_
end_define

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
name|platform_netbsd
block|{
name|class
name|PlatformNetBSD
range|:
name|public
name|PlatformPOSIX
block|{
name|public
operator|:
name|PlatformNetBSD
argument_list|(
argument|bool is_host
argument_list|)
block|;
operator|~
name|PlatformNetBSD
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
argument|Status&error
argument_list|)
name|override
block|;
name|void
name|CalculateTrapHandlerSymbolNames
argument_list|()
name|override
block|;
name|MmapArgList
name|GetMmapArgumentList
argument_list|(
argument|const ArchSpec&arch
argument_list|,
argument|lldb::addr_t addr
argument_list|,
argument|lldb::addr_t length
argument_list|,
argument|unsigned prot
argument_list|,
argument|unsigned flags
argument_list|,
argument|lldb::addr_t fd
argument_list|,
argument|lldb::addr_t offset
argument_list|)
name|override
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|PlatformNetBSD
argument_list|)
block|; }
decl_stmt|;
block|}
comment|// namespace platform_netbsd
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
comment|// liblldb_PlatformNetBSD_h_
end_comment

end_unit

