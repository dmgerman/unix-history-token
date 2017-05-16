begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OptionGroupPlatform.h -----------------------------------*- C++ -*-===//
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
name|liblldb_OptionGroupPlatform_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionGroupPlatform_h_
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
file|"lldb/Interpreter/Options.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//-------------------------------------------------------------------------
comment|// PlatformOptionGroup
comment|//
comment|// Make platform options available to any commands that need the settings.
comment|//-------------------------------------------------------------------------
name|class
name|OptionGroupPlatform
range|:
name|public
name|OptionGroup
block|{
name|public
operator|:
name|OptionGroupPlatform
argument_list|(
argument|bool include_platform_option
argument_list|)
operator|:
name|OptionGroup
argument_list|()
block|,
name|m_platform_name
argument_list|()
block|,
name|m_sdk_sysroot
argument_list|()
block|,
name|m_os_version_major
argument_list|(
name|UINT32_MAX
argument_list|)
block|,
name|m_os_version_minor
argument_list|(
name|UINT32_MAX
argument_list|)
block|,
name|m_os_version_update
argument_list|(
name|UINT32_MAX
argument_list|)
block|,
name|m_include_platform_option
argument_list|(
argument|include_platform_option
argument_list|)
block|{}
operator|~
name|OptionGroupPlatform
argument_list|()
name|override
operator|=
expr|default
block|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|OptionDefinition
operator|>
name|GetDefinitions
argument_list|()
name|override
block|;
name|Status
name|SetOptionValue
argument_list|(
argument|uint32_t option_idx
argument_list|,
argument|llvm::StringRef option_value
argument_list|,
argument|ExecutionContext *execution_context
argument_list|)
name|override
block|;
name|Status
name|SetOptionValue
argument_list|(
name|uint32_t
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|ExecutionContext
operator|*
argument_list|)
operator|=
name|delete
block|;
name|void
name|OptionParsingStarting
argument_list|(
argument|ExecutionContext *execution_context
argument_list|)
name|override
block|;
name|lldb
operator|::
name|PlatformSP
name|CreatePlatformWithOptions
argument_list|(
argument|CommandInterpreter&interpreter
argument_list|,
argument|const ArchSpec&arch
argument_list|,
argument|bool make_selected
argument_list|,
argument|Status&error
argument_list|,
argument|ArchSpec&platform_arch
argument_list|)
specifier|const
block|;
name|bool
name|PlatformWasSpecified
argument_list|()
specifier|const
block|{
return|return
operator|!
name|m_platform_name
operator|.
name|empty
argument_list|()
return|;
block|}
name|void
name|SetPlatformName
argument_list|(
argument|const char *platform_name
argument_list|)
block|{
if|if
condition|(
name|platform_name
operator|&&
name|platform_name
index|[
literal|0
index|]
condition|)
name|m_platform_name
operator|.
name|assign
argument_list|(
name|platform_name
argument_list|)
expr_stmt|;
else|else
name|m_platform_name
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
specifier|const
name|ConstString
operator|&
name|GetSDKRootDirectory
argument_list|()
specifier|const
block|{
return|return
name|m_sdk_sysroot
return|;
block|}
name|void
name|SetSDKRootDirectory
argument_list|(
argument|const ConstString&sdk_root_directory
argument_list|)
block|{
name|m_sdk_sysroot
operator|=
name|sdk_root_directory
block|;   }
specifier|const
name|ConstString
operator|&
name|GetSDKBuild
argument_list|()
specifier|const
block|{
return|return
name|m_sdk_build
return|;
block|}
name|void
name|SetSDKBuild
argument_list|(
argument|const ConstString&sdk_build
argument_list|)
block|{
name|m_sdk_build
operator|=
name|sdk_build
block|; }
name|bool
name|PlatformMatches
argument_list|(
argument|const lldb::PlatformSP&platform_sp
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|std
operator|::
name|string
name|m_platform_name
block|;
name|ConstString
name|m_sdk_sysroot
block|;
name|ConstString
name|m_sdk_build
block|;
name|uint32_t
name|m_os_version_major
block|;
name|uint32_t
name|m_os_version_minor
block|;
name|uint32_t
name|m_os_version_update
block|;
name|bool
name|m_include_platform_option
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
comment|// liblldb_OptionGroupPlatform_h_
end_comment

end_unit

