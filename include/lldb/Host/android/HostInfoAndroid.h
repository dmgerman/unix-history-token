begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HostInfoAndroid.h ---------------------------------------*- C++ -*-===//
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
name|lldb_Host_android_HostInfoAndroid_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_android_HostInfoAndroid_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/linux/HostInfoLinux.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|HostInfoAndroid
range|:
name|public
name|HostInfoLinux
block|{
name|friend
name|class
name|HostInfoBase
block|;
name|public
operator|:
specifier|static
name|FileSpec
name|GetDefaultShell
argument_list|()
block|;
specifier|static
name|FileSpec
name|ResolveLibraryPath
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|path
argument_list|,
specifier|const
name|ArchSpec
operator|&
name|arch
argument_list|)
block|;
name|protected
operator|:
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
block|;
specifier|static
name|bool
name|ComputeTempFileBaseDirectory
argument_list|(
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end of namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef lldb_Host_android_HostInfoAndroid_h_
end_comment

end_unit

