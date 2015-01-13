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

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ProcessLaunchInfo.h"
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
block|{
name|public
label|:
specifier|static
specifier|const
name|lldb
operator|::
name|pid_t
name|kInvalidProcessId
expr_stmt|;
name|HostProcessPosix
argument_list|()
expr_stmt|;
operator|~
name|HostProcessPosix
argument_list|()
expr_stmt|;
name|Error
name|Signal
argument_list|(
name|int
name|signo
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|Error
name|Signal
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|,
name|int
name|signo
argument_list|)
decl_stmt|;
name|Error
name|Create
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|)
decl_stmt|;
name|Error
name|Terminate
parameter_list|(
name|int
name|signo
parameter_list|)
function_decl|;
name|Error
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
name|private
label|:
name|lldb
operator|::
name|pid_t
name|m_pid
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

