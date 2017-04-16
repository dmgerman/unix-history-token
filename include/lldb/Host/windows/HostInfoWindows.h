begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HostInfoWindows.h ---------------------------------------*- C++ -*-===//
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
name|lldb_Host_windows_HostInfoWindows_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_windows_HostInfoWindows_h_
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
name|HostInfoWindows
range|:
name|public
name|HostInfoBase
block|{
name|friend
name|class
name|HostInfoBase
block|;
name|private
operator|:
comment|// Static class, unconstructable.
name|HostInfoWindows
argument_list|()
block|;
operator|~
name|HostInfoWindows
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
name|void
name|Terminate
argument_list|()
block|;
specifier|static
name|size_t
name|GetPageSize
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
name|FileSpec
name|GetProgramFileSpec
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
name|ComputePythonDirectory
argument_list|(
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
name|private
operator|:
specifier|static
name|FileSpec
name|m_program_filespec
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

