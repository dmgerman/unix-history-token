begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HostInfoLinux.h -----------------------------------------*- C++ -*-===//
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
name|lldb_Host_linux_HostInfoLinux_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_linux_HostInfoLinux_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/posix/HostInfoPosix.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|HostInfoLinux
range|:
name|public
name|HostInfoPosix
block|{
name|friend
name|class
name|HostInfoBase
block|;
name|private
operator|:
comment|// Static class, unconstructable.
name|HostInfoLinux
argument_list|()
block|;
operator|~
name|HostInfoLinux
argument_list|()
block|;
name|public
operator|:
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|bool
name|GetOSVersion
argument_list|(
name|uint32_t
operator|&
name|major
argument_list|,
name|uint32_t
operator|&
name|minor
argument_list|,
name|uint32_t
operator|&
name|update
argument_list|)
block|;
specifier|static
name|bool
name|GetOSBuildString
argument_list|(
name|std
operator|::
name|string
operator|&
name|s
argument_list|)
block|;
specifier|static
name|bool
name|GetOSKernelDescription
argument_list|(
name|std
operator|::
name|string
operator|&
name|s
argument_list|)
block|;
specifier|static
name|llvm
operator|::
name|StringRef
name|GetDistributionId
argument_list|()
block|;
specifier|static
name|FileSpec
name|GetProgramFileSpec
argument_list|()
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
name|ComputeSystemPluginsDirectory
argument_list|(
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
specifier|static
name|bool
name|ComputeUserPluginsDirectory
argument_list|(
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
specifier|static
name|void
name|ComputeHostArchitectureSupport
argument_list|(
name|ArchSpec
operator|&
name|arch_32
argument_list|,
name|ArchSpec
operator|&
name|arch_64
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

