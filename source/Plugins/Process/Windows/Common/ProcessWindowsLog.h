begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcessWindowsLog.h -------------------------------------*- C++ -*-===//
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
name|liblldb_ProcessWindowsLog_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ProcessWindowsLog_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/Log.h"
end_include

begin_define
define|#
directive|define
name|WINDOWS_LOG_PROCESS
value|(1u<< 1)
end_define

begin_comment
comment|// Log process operations
end_comment

begin_define
define|#
directive|define
name|WINDOWS_LOG_EXCEPTION
value|(1u<< 1)
end_define

begin_comment
comment|// Log exceptions
end_comment

begin_define
define|#
directive|define
name|WINDOWS_LOG_THREAD
value|(1u<< 2)
end_define

begin_comment
comment|// Log thread operations
end_comment

begin_define
define|#
directive|define
name|WINDOWS_LOG_MEMORY
value|(1u<< 3)
end_define

begin_comment
comment|// Log memory reads/writes calls
end_comment

begin_define
define|#
directive|define
name|WINDOWS_LOG_BREAKPOINTS
value|(1u<< 4)
end_define

begin_comment
comment|// Log breakpoint operations
end_comment

begin_define
define|#
directive|define
name|WINDOWS_LOG_STEP
value|(1u<< 5)
end_define

begin_comment
comment|// Log step operations
end_comment

begin_define
define|#
directive|define
name|WINDOWS_LOG_REGISTERS
value|(1u<< 6)
end_define

begin_comment
comment|// Log register operations
end_comment

begin_define
define|#
directive|define
name|WINDOWS_LOG_EVENT
value|(1u<< 7)
end_define

begin_comment
comment|// Low level debug events
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ProcessWindowsLog
block|{
specifier|static
name|Log
operator|::
name|Channel
name|g_channel
expr_stmt|;
name|public
label|:
specifier|static
name|void
name|Initialize
parameter_list|()
function_decl|;
specifier|static
name|void
name|Terminate
parameter_list|()
function_decl|;
specifier|static
name|Log
modifier|*
name|GetLogIfAny
parameter_list|(
name|uint32_t
name|mask
parameter_list|)
block|{
return|return
name|g_channel
operator|.
name|GetLogIfAny
argument_list|(
name|mask
argument_list|)
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ProcessWindowsLog_h_
end_comment

end_unit

