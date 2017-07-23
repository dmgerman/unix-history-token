begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HostProcess.h ------------------------------------------*- C++ -*-===//
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
name|lldb_Host_HostProcess_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_HostProcess_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/Host.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|/// @class HostInfo HostInfo.h "lldb/Host/HostProcess.h"
end_comment

begin_comment
comment|/// @brief A class that represents a running process on the host machine.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// HostProcess allows querying and manipulation of processes running on the
end_comment

begin_comment
comment|/// host machine.  It is not intended to be represent a process which is
end_comment

begin_comment
comment|/// being debugged, although the native debug engine of a platform may likely
end_comment

begin_comment
comment|/// back inferior processes by a HostProcess.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// HostProcess is implemented using static polymorphism so that on any given
end_comment

begin_comment
comment|/// platform, an instance of HostProcess will always be able to bind statically
end_comment

begin_comment
comment|/// to the concrete Process implementation for that platform.  See HostInfo
end_comment

begin_comment
comment|/// for more details.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|HostNativeProcessBase
decl_stmt|;
name|class
name|HostThread
decl_stmt|;
name|class
name|HostProcess
block|{
name|public
label|:
name|HostProcess
argument_list|()
expr_stmt|;
name|HostProcess
argument_list|(
argument|lldb::process_t process
argument_list|)
empty_stmt|;
operator|~
name|HostProcess
argument_list|()
expr_stmt|;
name|Status
name|Terminate
parameter_list|()
function_decl|;
name|Status
name|GetMainModule
argument_list|(
name|FileSpec
operator|&
name|file_spec
argument_list|)
decl|const
decl_stmt|;
name|lldb
operator|::
name|pid_t
name|GetProcessId
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsRunning
argument_list|()
specifier|const
expr_stmt|;
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
decl_stmt|;
name|HostNativeProcessBase
modifier|&
name|GetNativeProcess
parameter_list|()
function_decl|;
specifier|const
name|HostNativeProcessBase
operator|&
name|GetNativeProcess
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|std
operator|::
name|shared_ptr
operator|<
name|HostNativeProcessBase
operator|>
name|m_native_process
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

