begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PlatformRemoteiOS.h -------------------------------------*- C++ -*-===//
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
name|liblldb_PlatformRemoteiOS_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_PlatformRemoteiOS_h_
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
file|"PlatformRemoteDarwinDevice.h"
end_include

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

begin_decl_stmt
name|class
name|PlatformRemoteiOS
range|:
name|public
name|PlatformRemoteDarwinDevice
block|{
name|public
operator|:
name|PlatformRemoteiOS
argument_list|()
block|;
operator|~
name|PlatformRemoteiOS
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
name|GetDescriptionStatic
argument_list|()
return|;
block|}
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
name|bool
name|GetSupportedArchitectureAtIndex
argument_list|(
argument|uint32_t idx
argument_list|,
argument|lldb_private::ArchSpec&arch
argument_list|)
name|override
block|;
name|protected
operator|:
comment|//------------------------------------------------------------
comment|// lldb_private::PlatformRemoteDarwinDevice functions
comment|//------------------------------------------------------------
name|void
name|GetDeviceSupportDirectoryNames
argument_list|(
argument|std::vector<std::string>&dirnames
argument_list|)
name|override
block|;
name|std
operator|::
name|string
name|GetPlatformName
argument_list|()
name|override
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|PlatformRemoteiOS
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_PlatformRemoteiOS_h_
end_comment

end_unit

