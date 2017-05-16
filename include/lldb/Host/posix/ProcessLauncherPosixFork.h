begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcessLauncherPosixFork.h ------------------------------*- C++ -*-===//
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
name|lldb_Host_posix_ProcessLauncherPosixFork_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_posix_ProcessLauncherPosixFork_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/ProcessLauncher.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ProcessLauncherPosixFork
range|:
name|public
name|ProcessLauncher
block|{
name|public
operator|:
name|HostProcess
name|LaunchProcess
argument_list|(
argument|const ProcessLaunchInfo&launch_info
argument_list|,
argument|Status&error
argument_list|)
name|override
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

end_unit

