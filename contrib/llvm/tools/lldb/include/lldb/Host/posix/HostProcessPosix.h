begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HostProcessPosix.h --------------------------------------*- C++ -*-===//
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
name|lldb_Host_HostProcesPosix_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_HostProcesPosix_h_
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
file|"lldb/Host/HostNativeProcessBase.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Error.h"
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
name|FileSpec
decl_stmt|;
name|class
name|HostProcessPosix
range|:
name|public
name|HostNativeProcessBase
block|{
name|public
operator|:
name|HostProcessPosix
argument_list|()
block|;
name|HostProcessPosix
argument_list|(
argument|lldb::process_t process
argument_list|)
block|;
operator|~
name|HostProcessPosix
argument_list|()
name|override
block|;
name|virtual
name|Error
name|Signal
argument_list|(
argument|int signo
argument_list|)
specifier|const
block|;
specifier|static
name|Error
name|Signal
argument_list|(
argument|lldb::process_t process
argument_list|,
argument|int signo
argument_list|)
block|;
name|Error
name|Terminate
argument_list|()
name|override
block|;
name|Error
name|GetMainModule
argument_list|(
argument|FileSpec&file_spec
argument_list|)
specifier|const
name|override
block|;
name|lldb
operator|::
name|pid_t
name|GetProcessId
argument_list|()
specifier|const
name|override
block|;
name|bool
name|IsRunning
argument_list|()
specifier|const
name|override
block|;
name|HostThread
name|StartMonitoring
argument_list|(
argument|const Host::MonitorChildProcessCallback&callback
argument_list|,
argument|bool monitor_signals
argument_list|)
name|override
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
comment|// lldb_Host_HostProcesPosix_h_
end_comment

end_unit

