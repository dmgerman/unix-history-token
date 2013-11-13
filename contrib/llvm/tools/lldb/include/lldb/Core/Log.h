begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Log.h ---------------------------------------------------*- C++ -*-===//
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
name|liblldb_Log_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Log_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Flags.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/PluginInterface.h"
end_include

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Logging types
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_define
define|#
directive|define
name|LLDB_LOG_FLAG_STDOUT
value|(1u<< 0)
end_define

begin_define
define|#
directive|define
name|LLDB_LOG_FLAG_STDERR
value|(1u<< 1)
end_define

begin_define
define|#
directive|define
name|LLDB_LOG_FLAG_FATAL
value|(1u<< 2)
end_define

begin_define
define|#
directive|define
name|LLDB_LOG_FLAG_ERROR
value|(1u<< 3)
end_define

begin_define
define|#
directive|define
name|LLDB_LOG_FLAG_WARNING
value|(1u<< 4)
end_define

begin_define
define|#
directive|define
name|LLDB_LOG_FLAG_DEBUG
value|(1u<< 5)
end_define

begin_define
define|#
directive|define
name|LLDB_LOG_FLAG_VERBOSE
value|(1u<< 6)
end_define

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Logging Options
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_define
define|#
directive|define
name|LLDB_LOG_OPTION_THREADSAFE
value|(1u<< 0)
end_define

begin_define
define|#
directive|define
name|LLDB_LOG_OPTION_VERBOSE
value|(1u<< 1)
end_define

begin_define
define|#
directive|define
name|LLDB_LOG_OPTION_DEBUG
value|(1u<< 2)
end_define

begin_define
define|#
directive|define
name|LLDB_LOG_OPTION_PREPEND_SEQUENCE
value|(1u<< 3)
end_define

begin_define
define|#
directive|define
name|LLDB_LOG_OPTION_PREPEND_TIMESTAMP
value|(1u<< 4)
end_define

begin_define
define|#
directive|define
name|LLDB_LOG_OPTION_PREPEND_PROC_AND_THREAD
value|(1u<< 5)
end_define

begin_define
define|#
directive|define
name|LLDB_LOG_OPTION_PREPEND_THREAD_NAME
value|(1U<< 6)
end_define

begin_define
define|#
directive|define
name|LLDB_LOG_OPTION_BACKTRACE
value|(1U<< 7)
end_define

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Logging Functions
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Log
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|// Callback definitions for abstracted plug-in log access.
comment|//------------------------------------------------------------------
typedef|typedef
name|void
function_decl|(
modifier|*
name|DisableCallback
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|categories
parameter_list|,
name|Stream
modifier|*
name|feedback_strm
parameter_list|)
function_decl|;
typedef|typedef
name|Log
operator|*
operator|(
operator|*
name|EnableCallback
operator|)
operator|(
name|lldb
operator|::
name|StreamSP
operator|&
name|log_stream_sp
operator|,
name|uint32_t
name|log_options
operator|,
specifier|const
name|char
operator|*
operator|*
name|categories
operator|,
name|Stream
operator|*
name|feedback_strm
operator|)
expr_stmt|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|ListCategoriesCallback
function_decl|)
parameter_list|(
name|Stream
modifier|*
name|strm
parameter_list|)
function_decl|;
struct|struct
name|Callbacks
block|{
name|DisableCallback
name|disable
decl_stmt|;
name|EnableCallback
name|enable
decl_stmt|;
name|ListCategoriesCallback
name|list_categories
decl_stmt|;
block|}
struct|;
comment|//------------------------------------------------------------------
comment|// Static accessors for logging channels
comment|//------------------------------------------------------------------
specifier|static
name|void
name|RegisterLogChannel
argument_list|(
specifier|const
name|ConstString
operator|&
name|channel
argument_list|,
specifier|const
name|Log
operator|::
name|Callbacks
operator|&
name|log_callbacks
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|UnregisterLogChannel
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|channel
parameter_list|)
function_decl|;
specifier|static
name|bool
name|GetLogChannelCallbacks
argument_list|(
specifier|const
name|ConstString
operator|&
name|channel
argument_list|,
name|Log
operator|::
name|Callbacks
operator|&
name|log_callbacks
argument_list|)
decl_stmt|;
specifier|static
name|void
name|EnableAllLogChannels
argument_list|(
name|lldb
operator|::
name|StreamSP
operator|&
name|log_stream_sp
argument_list|,
name|uint32_t
name|log_options
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|categories
argument_list|,
name|Stream
operator|*
name|feedback_strm
argument_list|)
decl_stmt|;
specifier|static
name|void
name|DisableAllLogChannels
parameter_list|(
name|Stream
modifier|*
name|feedback_strm
parameter_list|)
function_decl|;
specifier|static
name|void
name|ListAllLogChannels
parameter_list|(
name|Stream
modifier|*
name|strm
parameter_list|)
function_decl|;
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
comment|//------------------------------------------------------------------
comment|// Auto completion
comment|//------------------------------------------------------------------
specifier|static
name|void
name|AutoCompleteChannelName
parameter_list|(
specifier|const
name|char
modifier|*
name|channel_name
parameter_list|,
name|StringList
modifier|&
name|matches
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// Member functions
comment|//------------------------------------------------------------------
name|Log
argument_list|()
expr_stmt|;
name|Log
argument_list|(
specifier|const
name|lldb
operator|::
name|StreamSP
operator|&
name|stream_sp
argument_list|)
expr_stmt|;
operator|~
name|Log
argument_list|()
expr_stmt|;
name|void
name|PutCString
parameter_list|(
specifier|const
name|char
modifier|*
name|cstr
parameter_list|)
function_decl|;
name|void
name|Printf
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
block|)
decl_stmt|)
block|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|VAPrintf
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrintfWithFlags
parameter_list|(
name|uint32_t
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|LogIf
parameter_list|(
name|uint32_t
name|mask
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|Debug
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|DebugVerbose
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|Error
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|FatalError
parameter_list|(
name|int
name|err
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|Verbose
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|Warning
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|WarningVerbose
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|Flags
modifier|&
name|GetOptions
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|const
name|Flags
operator|&
name|GetOptions
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|Flags
modifier|&
name|GetMask
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|const
name|Flags
operator|&
name|GetMask
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|GetVerbose
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|GetDebug
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|SetStream
argument_list|(
specifier|const
name|lldb
operator|::
name|StreamSP
operator|&
name|stream_sp
argument_list|)
block|{
name|m_stream_sp
operator|=
name|stream_sp
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Member variables
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|lldb
operator|::
name|StreamSP
name|m_stream_sp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Flags
name|m_options
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Flags
name|m_mask_bits
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|PrintfWithFlagsVarArg
parameter_list|(
name|uint32_t
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Log
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|};
name|class
name|LogChannel
range|:
name|public
name|PluginInterface
block|{
name|public
operator|:
name|LogChannel
argument_list|()
block|;
name|virtual
operator|~
name|LogChannel
argument_list|()
block|;
specifier|static
name|lldb
operator|::
name|LogChannelSP
name|FindPlugin
argument_list|(
specifier|const
name|char
operator|*
name|plugin_name
argument_list|)
block|;
comment|// categories is a an array of chars that ends with a NULL element.
name|virtual
name|void
name|Disable
argument_list|(
specifier|const
name|char
operator|*
operator|*
name|categories
argument_list|,
name|Stream
operator|*
name|feedback_strm
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|Enable
argument_list|(
argument|lldb::StreamSP&log_stream_sp
argument_list|,
argument|uint32_t log_options
argument_list|,
argument|Stream *feedback_strm
argument_list|,
comment|// Feedback stream for argument errors etc
argument|const char **categories
argument_list|)
operator|=
literal|0
block|;
comment|// The categories to enable within this logging stream, if empty, enable default set
name|virtual
name|void
name|ListCategories
argument_list|(
name|Stream
operator|*
name|strm
argument_list|)
operator|=
literal|0
block|;
name|protected
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|Log
operator|>
name|m_log_ap
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|LogChannel
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Log_H_
end_comment

end_unit

