begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HostInfoPosix.h -----------------------------------------*- C++ -*-===//
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
name|lldb_Host_posix_HostInfoPosix_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_posix_HostInfoPosix_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/HostInfoBase.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|HostInfoPosix
range|:
name|public
name|HostInfoBase
block|{
name|friend
name|class
name|HostInfoBase
block|;
name|public
operator|:
specifier|static
name|size_t
name|GetPageSize
argument_list|()
block|;
specifier|static
name|bool
name|GetHostname
argument_list|(
name|std
operator|::
name|string
operator|&
name|s
argument_list|)
block|;
specifier|static
specifier|const
name|char
operator|*
name|LookupUserName
argument_list|(
argument|uint32_t uid
argument_list|,
argument|std::string&user_name
argument_list|)
block|;
specifier|static
specifier|const
name|char
operator|*
name|LookupGroupName
argument_list|(
argument|uint32_t gid
argument_list|,
argument|std::string&group_name
argument_list|)
block|;
specifier|static
name|uint32_t
name|GetUserID
argument_list|()
block|;
specifier|static
name|uint32_t
name|GetGroupID
argument_list|()
block|;
specifier|static
name|uint32_t
name|GetEffectiveUserID
argument_list|()
block|;
specifier|static
name|uint32_t
name|GetEffectiveGroupID
argument_list|()
block|;
specifier|static
name|FileSpec
name|GetDefaultShell
argument_list|()
block|;
specifier|static
name|bool
name|GetEnvironmentVar
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|var_name
argument_list|,
name|std
operator|::
name|string
operator|&
name|var
argument_list|)
block|;
name|protected
operator|:
specifier|static
name|bool
name|ComputeSupportExeDirectory
argument_list|(
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
specifier|static
name|bool
name|ComputeHeaderDirectory
argument_list|(
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
specifier|static
name|bool
name|ComputePythonDirectory
argument_list|(
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
specifier|static
name|bool
name|ComputeClangDirectory
argument_list|(
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
specifier|static
name|bool
name|ComputePathRelativeToLibrary
argument_list|(
argument|FileSpec&file_spec
argument_list|,
argument|llvm::StringRef dir
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

