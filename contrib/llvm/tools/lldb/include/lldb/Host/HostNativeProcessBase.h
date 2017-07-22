begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HostNativeProcessBase.h ---------------------------------*- C++ -*-===//
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
name|lldb_Host_HostNativeProcessBase_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_HostNativeProcessBase_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/HostProcess.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Status.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|HostThread
decl_stmt|;
name|class
name|HostNativeProcessBase
block|{
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|HostNativeProcessBase
argument_list|)
expr_stmt|;
name|public
label|:
name|HostNativeProcessBase
argument_list|()
operator|:
name|m_process
argument_list|(
argument|LLDB_INVALID_PROCESS
argument_list|)
block|{}
name|explicit
name|HostNativeProcessBase
argument_list|(
argument|lldb::process_t process
argument_list|)
operator|:
name|m_process
argument_list|(
argument|process
argument_list|)
block|{}
name|virtual
operator|~
name|HostNativeProcessBase
argument_list|()
block|{}
name|virtual
name|Status
name|Terminate
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|Status
name|GetMainModule
argument_list|(
name|FileSpec
operator|&
name|file_spec
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|lldb
operator|::
name|pid_t
name|GetProcessId
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|IsRunning
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|lldb
operator|::
name|process_t
name|GetSystemHandle
argument_list|()
specifier|const
block|{
return|return
name|m_process
return|;
block|}
name|virtual
name|HostThread
name|StartMonitoring
argument_list|(
specifier|const
name|Host
operator|::
name|MonitorChildProcessCallback
operator|&
name|callback
argument_list|,
name|bool
name|monitor_signals
argument_list|)
init|=
literal|0
decl_stmt|;
name|protected
label|:
name|lldb
operator|::
name|process_t
name|m_process
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

