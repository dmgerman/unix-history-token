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
file|"lldb/Core/Log.h"
end_include

begin_define
define|#
directive|define
name|WINDOWS_LOG_VERBOSE
value|(1u<< 0)
end_define

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

begin_define
define|#
directive|define
name|WINDOWS_LOG_ALL
value|(UINT32_MAX)
end_define

begin_decl_stmt
name|enum
name|class
name|LogMaskReq
block|{
name|All
operator|,
name|Any
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|ProcessWindowsLog
block|{
specifier|static
specifier|const
name|char
modifier|*
name|m_pluginname
decl_stmt|;
name|public
label|:
comment|// ---------------------------------------------------------------------
comment|// Public Static Methods
comment|// ---------------------------------------------------------------------
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
name|bool
name|TestLogFlags
parameter_list|(
name|uint32_t
name|mask
parameter_list|,
name|LogMaskReq
name|req
parameter_list|)
function_decl|;
specifier|static
name|lldb_private
operator|::
name|Log
operator|*
name|GetLog
argument_list|()
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|WINLOGF_IF
parameter_list|(
name|Flags
parameter_list|,
name|Req
parameter_list|,
name|Method
parameter_list|,
modifier|...
parameter_list|)
define|\
value|{                                                                            \     if (ProcessWindowsLog::TestLogFlags(Flags, Req)) {                         \       Log *log = ProcessWindowsLog::GetLog();                                  \       if (log)                                                                 \         log->Method(__VA_ARGS__);                                              \     }                                                                          \   }
end_define

begin_define
define|#
directive|define
name|WINLOG_IFANY
parameter_list|(
name|Flags
parameter_list|,
modifier|...
parameter_list|)
define|\
value|WINLOGF_IF(Flags, LogMaskReq::Any, Printf, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|WINLOG_IFALL
parameter_list|(
name|Flags
parameter_list|,
modifier|...
parameter_list|)
define|\
value|WINLOGF_IF(Flags, LogMaskReq::All, Printf, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|WINLOGV_IFANY
parameter_list|(
name|Flags
parameter_list|,
modifier|...
parameter_list|)
define|\
value|WINLOGF_IF(Flags, LogMaskReq::Any, Verbose, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|WINLOGV_IFALL
parameter_list|(
name|Flags
parameter_list|,
modifier|...
parameter_list|)
define|\
value|WINLOGF_IF(Flags, LogMaskReq::All, Verbose, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|WINLOGD_IFANY
parameter_list|(
name|Flags
parameter_list|,
modifier|...
parameter_list|)
define|\
value|WINLOGF_IF(Flags, LogMaskReq::Any, Debug, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|WINLOGD_IFALL
parameter_list|(
name|Flags
parameter_list|,
modifier|...
parameter_list|)
define|\
value|WINLOGF_IF(Flags, LogMaskReq::All, Debug, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|WINERR_IFANY
parameter_list|(
name|Flags
parameter_list|,
modifier|...
parameter_list|)
define|\
value|WINLOGF_IF(Flags, LogMaskReq::Any, Error, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|WINERR_IFALL
parameter_list|(
name|Flags
parameter_list|,
modifier|...
parameter_list|)
define|\
value|WINLOGF_IF(Flags, LogMaskReq::All, Error, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|WINWARN_IFANY
parameter_list|(
name|Flags
parameter_list|,
modifier|...
parameter_list|)
define|\
value|WINLOGF_IF(Flags, LogMaskReq::Any, Warning, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|WINWARN_IFALL
parameter_list|(
name|Flags
parameter_list|,
modifier|...
parameter_list|)
define|\
value|WINLOGF_IF(Flags, LogMaskReq::All, Warning, __VA_ARGS__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ProcessWindowsLog_h_
end_comment

end_unit

