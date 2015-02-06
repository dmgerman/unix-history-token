begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MonitoringProcessLauncher.h -----------------------------*- C++ -*-===//
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
name|lldb_Host_MonitoringProcessLauncher_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_MonitoringProcessLauncher_h_
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
name|MonitoringProcessLauncher
range|:
name|public
name|ProcessLauncher
block|{
name|public
operator|:
name|explicit
name|MonitoringProcessLauncher
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|ProcessLauncher
operator|>
name|delegate_launcher
argument_list|)
block|;
name|virtual
name|HostProcess
name|LaunchProcess
argument_list|(
specifier|const
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|,
name|Error
operator|&
name|error
argument_list|)
block|;
name|private
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|ProcessLauncher
operator|>
name|m_delegate_launcher
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

