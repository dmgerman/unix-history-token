begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcessPOSIXLog.h -----------------------------------------*- C++ -*-===//
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
file|"lldb/Core/Log.h"
end_include

begin_define
define|#
directive|define
name|POSIX_LOG_VERBOSE
value|(1u<< 0)
end_define

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
name|POSIX_LOG_PACKETS
value|(1u<< 3)
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
name|POSIX_LOG_MEMORY_DATA_SHORT
value|(1u<< 5)
end_define

begin_comment
comment|// Log short memory reads/writes bytes
end_comment

begin_define
define|#
directive|define
name|POSIX_LOG_MEMORY_DATA_LONG
value|(1u<< 6)
end_define

begin_comment
comment|// Log all memory reads/writes bytes
end_comment

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
name|POSIX_LOG_STEP
value|(1u<< 9)
end_define

begin_define
define|#
directive|define
name|POSIX_LOG_COMM
value|(1u<< 10)
end_define

begin_define
define|#
directive|define
name|POSIX_LOG_ASYNC
value|(1u<< 11)
end_define

begin_define
define|#
directive|define
name|POSIX_LOG_PTRACE
value|(1u<< 12)
end_define

begin_define
define|#
directive|define
name|POSIX_LOG_REGISTERS
value|(1u<< 13)
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
value|POSIX_LOG_PACKETS
end_define

begin_comment
comment|// The size which determines "short memory reads/writes".
end_comment

begin_define
define|#
directive|define
name|POSIX_LOG_MEMORY_SHORT_BYTES
value|(4 * sizeof(ptrdiff_t))
end_define

begin_decl_stmt
name|class
name|ProcessPOSIXLog
block|{
specifier|static
name|int
name|m_nestinglevel
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|m_pluginname
decl_stmt|;
name|public
label|:
specifier|static
name|void
name|RegisterPluginName
parameter_list|(
specifier|const
name|char
modifier|*
name|pluginName
parameter_list|)
block|{
name|m_pluginname
operator|=
name|pluginName
expr_stmt|;
block|}
specifier|static
name|void
name|RegisterPluginName
argument_list|(
name|lldb_private
operator|::
name|ConstString
name|pluginName
argument_list|)
block|{
name|m_pluginname
operator|=
name|pluginName
operator|.
name|GetCString
argument_list|()
expr_stmt|;
block|}
specifier|static
name|lldb_private
operator|::
name|Log
operator|*
name|GetLogIfAllCategoriesSet
argument_list|(
argument|uint32_t mask =
literal|0
argument_list|)
expr_stmt|;
specifier|static
name|void
name|DisableLog
argument_list|(
specifier|const
name|char
operator|*
operator|*
name|args
argument_list|,
name|lldb_private
operator|::
name|Stream
operator|*
name|feedback_strm
argument_list|)
decl_stmt|;
specifier|static
name|lldb_private
operator|::
name|Log
operator|*
name|EnableLog
argument_list|(
argument|lldb::StreamSP&log_stream_sp
argument_list|,
argument|uint32_t log_options
argument_list|,
argument|const char **args
argument_list|,
argument|lldb_private::Stream *feedback_strm
argument_list|)
expr_stmt|;
specifier|static
name|void
name|ListLogCategories
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|strm
argument_list|)
decl_stmt|;
specifier|static
name|void
name|LogIf
parameter_list|(
name|uint32_t
name|mask
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
comment|// The following functions can be used to enable the client to limit
comment|// logging to only the top level function calls.  This is useful for
comment|// recursive functions.  FIXME: not thread safe!
comment|//     Example:
comment|//     void NestingFunc() {
comment|//         LogSP log (ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_ALL));
comment|//         if (log)
comment|//         {
comment|//             ProcessPOSIXLog::IncNestLevel();
comment|//             if (ProcessPOSIXLog::AtTopNestLevel())
comment|//                 log->Print(msg);
comment|//         }
comment|//         NestingFunc();
comment|//         if (log)
comment|//             ProcessPOSIXLog::DecNestLevel();
comment|//     }
specifier|static
name|bool
name|AtTopNestLevel
parameter_list|()
block|{
return|return
name|m_nestinglevel
operator|==
literal|1
return|;
block|}
specifier|static
name|void
name|IncNestLevel
parameter_list|()
block|{
operator|++
name|m_nestinglevel
expr_stmt|;
block|}
specifier|static
name|void
name|DecNestLevel
parameter_list|()
block|{
operator|--
name|m_nestinglevel
expr_stmt|;
name|assert
argument_list|(
name|m_nestinglevel
operator|>=
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ProcessPOSIXLog_h_
end_comment

end_unit

