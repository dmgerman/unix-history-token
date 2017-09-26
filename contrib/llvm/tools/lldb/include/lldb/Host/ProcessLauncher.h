begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcessLauncher.h ---------------------------------------*- C++ -*-===//
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
name|lldb_Host_ProcessLauncher_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_ProcessLauncher_h_
end_define

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ProcessLaunchInfo
decl_stmt|;
name|class
name|Status
decl_stmt|;
name|class
name|HostProcess
decl_stmt|;
name|class
name|ProcessLauncher
block|{
name|public
label|:
name|virtual
operator|~
name|ProcessLauncher
argument_list|()
block|{}
name|virtual
name|HostProcess
name|LaunchProcess
argument_list|(
specifier|const
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|,
name|Status
operator|&
name|error
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

