begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Logging.h -----------------------------------------------*- C++ -*-===//
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
name|LLDB_UTILITY_LOGGING_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_UTILITY_LOGGING_H
end_define

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Log Bits specific to logging in lldb
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_define
define|#
directive|define
name|LIBLLDB_LOG_PROCESS
value|(1u<< 1)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_THREAD
value|(1u<< 2)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_DYNAMIC_LOADER
value|(1u<< 3)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_EVENTS
value|(1u<< 4)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_BREAKPOINTS
value|(1u<< 5)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_WATCHPOINTS
value|(1u<< 6)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_STEP
value|(1u<< 7)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_EXPRESSIONS
value|(1u<< 8)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_TEMPORARY
value|(1u<< 9)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_STATE
value|(1u<< 10)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_OBJECT
value|(1u<< 11)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_COMMUNICATION
value|(1u<< 12)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_CONNECTION
value|(1u<< 13)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_HOST
value|(1u<< 14)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_UNWIND
value|(1u<< 15)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_API
value|(1u<< 16)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_SCRIPT
value|(1u<< 17)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_COMMANDS
value|(1U<< 18)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_TYPES
value|(1u<< 19)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_SYMBOLS
value|(1u<< 20)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_MODULES
value|(1u<< 21)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_TARGET
value|(1u<< 22)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_MMAP
value|(1u<< 23)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_OS
value|(1u<< 24)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_PLATFORM
value|(1u<< 25)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_SYSTEM_RUNTIME
value|(1u<< 26)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_JIT_LOADER
value|(1u<< 27)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_LANGUAGE
value|(1u<< 28)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_DATAFORMATTERS
value|(1u<< 29)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_DEMANGLE
value|(1u<< 30)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_ALL
value|(UINT32_MAX)
end_define

begin_define
define|#
directive|define
name|LIBLLDB_LOG_DEFAULT
define|\
value|(LIBLLDB_LOG_PROCESS | LIBLLDB_LOG_THREAD | LIBLLDB_LOG_DYNAMIC_LOADER |     \    LIBLLDB_LOG_BREAKPOINTS | LIBLLDB_LOG_WATCHPOINTS | LIBLLDB_LOG_STEP |      \    LIBLLDB_LOG_STATE | LIBLLDB_LOG_SYMBOLS | LIBLLDB_LOG_TARGET |              \    LIBLLDB_LOG_COMMANDS)
end_define

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Log
decl_stmt|;
name|void
name|LogIfAnyCategoriesSet
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
name|Log
modifier|*
name|GetLogIfAllCategoriesSet
parameter_list|(
name|uint32_t
name|mask
parameter_list|)
function_decl|;
name|Log
modifier|*
name|GetLogIfAnyCategoriesSet
parameter_list|(
name|uint32_t
name|mask
parameter_list|)
function_decl|;
name|void
name|InitializeLog
parameter_list|()
function_decl|;
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
comment|// LLDB_UTILITY_LOGGING_H
end_comment

end_unit

