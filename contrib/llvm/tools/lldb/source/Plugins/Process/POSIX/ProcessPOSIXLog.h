begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcessPOSIXLog.h -----------------------------------------*- C++
end_comment

begin_comment
comment|//-*-===//
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
name|liblldb_ProcessPOSIXLog_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ProcessPOSIXLog_h_
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
file|"lldb/Utility/Log.h"
end_include

begin_define
define|#
directive|define
name|POSIX_LOG_PROCESS
value|(1u<< 1)
end_define

begin_define
define|#
directive|define
name|POSIX_LOG_THREAD
value|(1u<< 2)
end_define

begin_define
define|#
directive|define
name|POSIX_LOG_MEMORY
value|(1u<< 4)
end_define

begin_comment
comment|// Log memory reads/writes calls
end_comment

begin_define
define|#
directive|define
name|POSIX_LOG_PTRACE
value|(1u<< 5)
end_define

begin_define
define|#
directive|define
name|POSIX_LOG_REGISTERS
value|(1u<< 6)
end_define

begin_define
define|#
directive|define
name|POSIX_LOG_BREAKPOINTS
value|(1u<< 7)
end_define

begin_define
define|#
directive|define
name|POSIX_LOG_WATCHPOINTS
value|(1u<< 8)
end_define

begin_define
define|#
directive|define
name|POSIX_LOG_ALL
value|(UINT32_MAX)
end_define

begin_define
define|#
directive|define
name|POSIX_LOG_DEFAULT
value|POSIX_LOG_PROCESS
end_define

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ProcessPOSIXLog
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
name|Log
modifier|*
name|GetLogIfAllCategoriesSet
parameter_list|(
name|uint32_t
name|mask
parameter_list|)
block|{
return|return
name|g_channel
operator|.
name|GetLogIfAll
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
comment|// liblldb_ProcessPOSIXLog_h_
end_comment

end_unit

