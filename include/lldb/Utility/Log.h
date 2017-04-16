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
name|LLDB_UTILITY_LOG_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_UTILITY_LOG_H
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/Flags.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Logging.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_comment
comment|// for StringMap
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_comment
comment|// for StringRef, StringLiteral
end_comment

begin_include
include|#
directive|include
file|"llvm/Support/FormatVariadic.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/RWMutex.h"
end_include

begin_include
include|#
directive|include
file|<atomic>
end_include

begin_include
include|#
directive|include
file|<cstdarg>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_comment
comment|// for shared_ptr
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// for string
end_comment

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_comment
comment|// for forward
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|class
name|C
operator|>
name|class
name|ManagedStatic
expr_stmt|;
block|}
end_decl_stmt

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

begin_define
define|#
directive|define
name|LLDB_LOG_OPTION_APPEND
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|LLDB_LOG_OPTION_PREPEND_FILE_FUNCTION
value|(1U<< 9)
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
name|final
block|{
name|public
label|:
comment|// Description of a log channel category.
struct|struct
name|Category
block|{
name|llvm
operator|::
name|StringLiteral
name|name
expr_stmt|;
name|llvm
operator|::
name|StringLiteral
name|description
expr_stmt|;
name|uint32_t
name|flag
decl_stmt|;
block|}
struct|;
comment|// This class describes a log channel. It also encapsulates the behavior
comment|// necessary to enable a log channel in an atomic manner.
name|class
name|Channel
block|{
name|std
operator|::
name|atomic
operator|<
name|Log
operator|*
operator|>
name|log_ptr
expr_stmt|;
name|friend
name|class
name|Log
decl_stmt|;
name|public
label|:
specifier|const
name|llvm
operator|::
name|ArrayRef
operator|<
name|Category
operator|>
name|categories
expr_stmt|;
specifier|const
name|uint32_t
name|default_flags
decl_stmt|;
name|constexpr
name|Channel
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
name|Log
operator|::
name|Category
operator|>
name|categories
argument_list|,
name|uint32_t
name|default_flags
argument_list|)
range|:
name|log_ptr
argument_list|(
name|nullptr
argument_list|)
decl_stmt|,
name|categories
argument_list|(
name|categories
argument_list|)
decl_stmt|,
name|default_flags
argument_list|(
name|default_flags
argument_list|)
block|{}
comment|// This function is safe to call at any time
comment|// If the channel is disabled after (or concurrently with) this function
comment|// returning a non-null Log pointer, it is still safe to attempt to write to
comment|// the Log object -- the output will be discarded.
name|Log
modifier|*
name|GetLogIfAll
parameter_list|(
name|uint32_t
name|mask
parameter_list|)
block|{
name|Log
modifier|*
name|log
init|=
name|log_ptr
operator|.
name|load
argument_list|(
name|std
operator|::
name|memory_order_relaxed
argument_list|)
decl_stmt|;
if|if
condition|(
name|log
operator|&&
name|log
operator|->
name|GetMask
argument_list|()
operator|.
name|AllSet
argument_list|(
name|mask
argument_list|)
condition|)
return|return
name|log
return|;
return|return
name|nullptr
return|;
block|}
comment|// This function is safe to call at any time
comment|// If the channel is disabled after (or concurrently with) this function
comment|// returning a non-null Log pointer, it is still safe to attempt to write to
comment|// the Log object -- the output will be discarded.
name|Log
modifier|*
name|GetLogIfAny
parameter_list|(
name|uint32_t
name|mask
parameter_list|)
block|{
name|Log
modifier|*
name|log
init|=
name|log_ptr
operator|.
name|load
argument_list|(
name|std
operator|::
name|memory_order_relaxed
argument_list|)
decl_stmt|;
if|if
condition|(
name|log
operator|&&
name|log
operator|->
name|GetMask
argument_list|()
operator|.
name|AnySet
argument_list|(
name|mask
argument_list|)
condition|)
return|return
name|log
return|;
return|return
name|nullptr
return|;
block|}
block|}
empty_stmt|;
comment|//------------------------------------------------------------------
comment|// Static accessors for logging channels
comment|//------------------------------------------------------------------
specifier|static
name|void
name|Register
argument_list|(
name|llvm
operator|::
name|StringRef
name|name
argument_list|,
name|Channel
operator|&
name|channel
argument_list|)
decl_stmt|;
specifier|static
name|void
name|Unregister
argument_list|(
name|llvm
operator|::
name|StringRef
name|name
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|EnableLogChannel
argument_list|(
specifier|const
name|std
operator|::
name|shared_ptr
operator|<
name|llvm
operator|::
name|raw_ostream
operator|>
operator|&
name|log_stream_sp
argument_list|,
name|uint32_t
name|log_options
argument_list|,
name|llvm
operator|::
name|StringRef
name|channel
argument_list|,
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|categories
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|&
name|error_stream
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|DisableLogChannel
argument_list|(
name|llvm
operator|::
name|StringRef
name|channel
argument_list|,
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|categories
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|&
name|error_stream
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|ListChannelCategories
argument_list|(
name|llvm
operator|::
name|StringRef
name|channel
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|&
name|stream
argument_list|)
decl_stmt|;
specifier|static
name|void
name|DisableAllLogChannels
parameter_list|()
function_decl|;
specifier|static
name|void
name|ListAllLogChannels
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|stream
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// Member functions
comment|//
comment|// These functions are safe to call at any time you have a Log* obtained from
comment|// the Channel class. If logging is disabled between you obtaining the Log
comment|// object and writing to it, the output will be silently discarded.
comment|//------------------------------------------------------------------
name|Log
argument_list|(
name|Channel
operator|&
name|channel
argument_list|)
operator|:
name|m_channel
argument_list|(
argument|channel
argument_list|)
block|{}
operator|~
name|Log
argument_list|()
operator|=
expr|default
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
name|PutString
argument_list|(
name|llvm
operator|::
name|StringRef
name|str
argument_list|)
decl_stmt|;
name|template
operator|<
name|typename
operator|...
name|Args
operator|>
name|void
name|Format
argument_list|(
argument|llvm::StringRef file
argument_list|,
argument|llvm::StringRef function
argument_list|,
argument|const char *format
argument_list|,
argument|Args&&... args
argument_list|)
block|{
name|Format
argument_list|(
name|file
argument_list|,
name|function
argument_list|,
name|llvm
operator|::
name|formatv
argument_list|(
name|format
argument_list|,
name|std
operator|::
name|forward
operator|<
name|Args
operator|>
operator|(
name|args
operator|)
operator|...
argument_list|)
argument_list|)
block|;   }
name|void
name|Printf
argument_list|(
argument|const char *format
argument_list|,
argument|...
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
operator|)
argument_list|)
expr_stmt|;
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
block|)
decl_stmt|)
block|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|VAError
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

begin_expr_stmt
specifier|const
name|Flags
name|GetOptions
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|Flags
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

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|Channel
modifier|&
name|m_channel
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The mutex makes sure enable/disable operations are thread-safe. The options
end_comment

begin_comment
comment|// and mask variables are atomic to enable their reading in
end_comment

begin_comment
comment|// Channel::GetLogIfAny without taking the mutex to speed up the fast path.
end_comment

begin_comment
comment|// Their modification however, is still protected by this mutex.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|sys
operator|::
name|RWMutex
name|m_mutex
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|shared_ptr
operator|<
name|llvm
operator|::
name|raw_ostream
operator|>
name|m_stream_sp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|atomic
operator|<
name|uint32_t
operator|>
name|m_options
block|{
literal|0
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|atomic
operator|<
name|uint32_t
operator|>
name|m_mask
block|{
literal|0
block|}
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|WriteHeader
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
argument_list|,
name|llvm
operator|::
name|StringRef
name|file
argument_list|,
name|llvm
operator|::
name|StringRef
name|function
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|WriteMessage
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|message
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Format
argument_list|(
name|llvm
operator|::
name|StringRef
name|file
argument_list|,
name|llvm
operator|::
name|StringRef
name|function
argument_list|,
specifier|const
name|llvm
operator|::
name|formatv_object_base
operator|&
name|payload
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|shared_ptr
operator|<
name|llvm
operator|::
name|raw_ostream
operator|>
name|GetStream
argument_list|()
block|{
name|llvm
operator|::
name|sys
operator|::
name|ScopedReader
name|lock
argument_list|(
name|m_mutex
argument_list|)
block|;
return|return
name|m_stream_sp
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|Enable
argument_list|(
specifier|const
name|std
operator|::
name|shared_ptr
operator|<
name|llvm
operator|::
name|raw_ostream
operator|>
operator|&
name|stream_sp
argument_list|,
name|uint32_t
name|options
argument_list|,
name|uint32_t
name|flags
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|Disable
parameter_list|(
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|llvm
operator|::
name|StringMap
operator|<
name|Log
operator|>
name|ChannelMap
expr_stmt|;
end_typedef

begin_expr_stmt
specifier|static
name|llvm
operator|::
name|ManagedStatic
operator|<
name|ChannelMap
operator|>
name|g_channel_map
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|void
name|ListCategories
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|stream
argument_list|,
specifier|const
name|ChannelMap
operator|::
name|value_type
operator|&
name|entry
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|uint32_t
name|GetFlags
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|stream
argument_list|,
specifier|const
name|ChannelMap
operator|::
name|value_type
operator|&
name|entry
argument_list|,
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|categories
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|Log
argument_list|(
specifier|const
name|Log
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|operator
init|=
operator|(
specifier|const
name|Log
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
comment|// namespace lldb_private
end_comment

begin_define
define|#
directive|define
name|LLDB_LOG
parameter_list|(
name|log
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {                                                                         \     ::lldb_private::Log *log_private = (log);                                  \     if (log_private)                                                           \       log_private->Format(__FILE__, __FUNCTION__, __VA_ARGS__);                \   } while (0)
end_define

begin_define
define|#
directive|define
name|LLDB_LOGV
parameter_list|(
name|log
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {                                                                         \     ::lldb_private::Log *log_private = (log);                                  \     if (log_private&& log_private->GetVerbose())                              \       log_private->Format(__FILE__, __FUNCTION__, __VA_ARGS__);                \   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_UTILITY_LOG_H
end_comment

end_unit

