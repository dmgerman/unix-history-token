begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CommandReturnObject.h -----------------------------------*- C++ -*-===//
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
name|liblldb_CommandReturnObject_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CommandReturnObject_h_
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
file|"lldb/Core/STLUtils.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/StreamFile.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/StreamString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/StreamTee.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FormatVariadic.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|CommandReturnObject
block|{
name|public
label|:
name|CommandReturnObject
argument_list|()
expr_stmt|;
operator|~
name|CommandReturnObject
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|StringRef
name|GetOutputData
argument_list|()
block|{
name|lldb
operator|::
name|StreamSP
name|stream_sp
argument_list|(
name|m_out_stream
operator|.
name|GetStreamAtIndex
argument_list|(
name|eStreamStringIndex
argument_list|)
argument_list|)
block|;
if|if
condition|(
name|stream_sp
condition|)
return|return
name|static_pointer_cast
operator|<
name|StreamString
operator|>
operator|(
name|stream_sp
operator|)
operator|->
name|GetString
argument_list|()
return|;
return|return
name|llvm
operator|::
name|StringRef
argument_list|()
return|;
block|}
name|llvm
operator|::
name|StringRef
name|GetErrorData
argument_list|()
block|{
name|lldb
operator|::
name|StreamSP
name|stream_sp
argument_list|(
name|m_err_stream
operator|.
name|GetStreamAtIndex
argument_list|(
name|eStreamStringIndex
argument_list|)
argument_list|)
block|;
if|if
condition|(
name|stream_sp
condition|)
return|return
name|static_pointer_cast
operator|<
name|StreamString
operator|>
operator|(
name|stream_sp
operator|)
operator|->
name|GetString
argument_list|()
return|;
return|return
name|llvm
operator|::
name|StringRef
argument_list|()
return|;
block|}
end_decl_stmt

begin_function
name|Stream
modifier|&
name|GetOutputStream
parameter_list|()
block|{
comment|// Make sure we at least have our normal string stream output stream
name|lldb
operator|::
name|StreamSP
name|stream_sp
argument_list|(
name|m_out_stream
operator|.
name|GetStreamAtIndex
argument_list|(
name|eStreamStringIndex
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|stream_sp
condition|)
block|{
name|stream_sp
operator|.
name|reset
argument_list|(
argument|new StreamString()
argument_list|)
expr_stmt|;
name|m_out_stream
operator|.
name|SetStreamAtIndex
argument_list|(
name|eStreamStringIndex
argument_list|,
name|stream_sp
argument_list|)
expr_stmt|;
block|}
return|return
name|m_out_stream
return|;
block|}
end_function

begin_function
name|Stream
modifier|&
name|GetErrorStream
parameter_list|()
block|{
comment|// Make sure we at least have our normal string stream output stream
name|lldb
operator|::
name|StreamSP
name|stream_sp
argument_list|(
name|m_err_stream
operator|.
name|GetStreamAtIndex
argument_list|(
name|eStreamStringIndex
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|stream_sp
condition|)
block|{
name|stream_sp
operator|.
name|reset
argument_list|(
argument|new StreamString()
argument_list|)
expr_stmt|;
name|m_err_stream
operator|.
name|SetStreamAtIndex
argument_list|(
name|eStreamStringIndex
argument_list|,
name|stream_sp
argument_list|)
expr_stmt|;
block|}
return|return
name|m_err_stream
return|;
block|}
end_function

begin_function
name|void
name|SetImmediateOutputFile
parameter_list|(
name|FILE
modifier|*
name|fh
parameter_list|,
name|bool
name|transfer_fh_ownership
init|=
name|false
parameter_list|)
block|{
name|lldb
operator|::
name|StreamSP
name|stream_sp
argument_list|(
argument|new StreamFile(fh, transfer_fh_ownership)
argument_list|)
expr_stmt|;
name|m_out_stream
operator|.
name|SetStreamAtIndex
argument_list|(
name|eImmediateStreamIndex
argument_list|,
name|stream_sp
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|SetImmediateErrorFile
parameter_list|(
name|FILE
modifier|*
name|fh
parameter_list|,
name|bool
name|transfer_fh_ownership
init|=
name|false
parameter_list|)
block|{
name|lldb
operator|::
name|StreamSP
name|stream_sp
argument_list|(
argument|new StreamFile(fh, transfer_fh_ownership)
argument_list|)
expr_stmt|;
name|m_err_stream
operator|.
name|SetStreamAtIndex
argument_list|(
name|eImmediateStreamIndex
argument_list|,
name|stream_sp
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|SetImmediateOutputStream
argument_list|(
specifier|const
name|lldb
operator|::
name|StreamSP
operator|&
name|stream_sp
argument_list|)
block|{
name|m_out_stream
operator|.
name|SetStreamAtIndex
argument_list|(
name|eImmediateStreamIndex
argument_list|,
name|stream_sp
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|SetImmediateErrorStream
argument_list|(
specifier|const
name|lldb
operator|::
name|StreamSP
operator|&
name|stream_sp
argument_list|)
block|{
name|m_err_stream
operator|.
name|SetStreamAtIndex
argument_list|(
name|eImmediateStreamIndex
argument_list|,
name|stream_sp
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|StreamSP
name|GetImmediateOutputStream
argument_list|()
block|{
return|return
name|m_out_stream
operator|.
name|GetStreamAtIndex
argument_list|(
name|eImmediateStreamIndex
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|StreamSP
name|GetImmediateErrorStream
argument_list|()
block|{
return|return
name|m_err_stream
operator|.
name|GetStreamAtIndex
argument_list|(
name|eImmediateStreamIndex
argument_list|)
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|Clear
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|AppendMessage
argument_list|(
name|llvm
operator|::
name|StringRef
name|in_string
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|AppendMessageWithFormat
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
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|void
name|AppendRawWarning
argument_list|(
name|llvm
operator|::
name|StringRef
name|in_string
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|AppendWarning
argument_list|(
name|llvm
operator|::
name|StringRef
name|in_string
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|AppendWarningWithFormat
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
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|void
name|AppendError
argument_list|(
name|llvm
operator|::
name|StringRef
name|in_string
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|AppendRawError
argument_list|(
name|llvm
operator|::
name|StringRef
name|in_string
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|AppendErrorWithFormat
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
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|Args
operator|>
name|void
name|AppendMessageWithFormatv
argument_list|(
argument|const char *format
argument_list|,
argument|Args&&... args
argument_list|)
block|{
name|AppendMessage
argument_list|(
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
operator|.
name|str
argument_list|()
argument_list|)
block|;   }
name|template
operator|<
name|typename
operator|...
name|Args
operator|>
name|void
name|AppendWarningWithFormatv
argument_list|(
argument|const char *format
argument_list|,
argument|Args&&... args
argument_list|)
block|{
name|AppendWarning
argument_list|(
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
operator|.
name|str
argument_list|()
argument_list|)
block|;   }
name|template
operator|<
name|typename
operator|...
name|Args
operator|>
name|void
name|AppendErrorWithFormatv
argument_list|(
argument|const char *format
argument_list|,
argument|Args&&... args
argument_list|)
block|{
name|AppendError
argument_list|(
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
operator|.
name|str
argument_list|()
argument_list|)
block|;   }
name|void
name|SetError
argument_list|(
specifier|const
name|Error
operator|&
name|error
argument_list|,
specifier|const
name|char
operator|*
name|fallback_error_cstr
operator|=
name|nullptr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|SetError
argument_list|(
name|llvm
operator|::
name|StringRef
name|error_cstr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|ReturnStatus
name|GetStatus
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|SetStatus
argument_list|(
name|lldb
operator|::
name|ReturnStatus
name|status
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|Succeeded
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|HasResult
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|GetDidChangeProcessState
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetDidChangeProcessState
parameter_list|(
name|bool
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|bool
name|GetInteractive
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|SetInteractive
parameter_list|(
name|bool
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|bool
name|GetAbnormalStopWasExpected
argument_list|()
specifier|const
block|{
return|return
name|m_abnormal_stop_was_expected
return|;
block|}
end_expr_stmt

begin_function
name|void
name|SetAbnormalStopWasExpected
parameter_list|(
name|bool
name|signal_was_expected
parameter_list|)
block|{
name|m_abnormal_stop_was_expected
operator|=
name|signal_was_expected
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_enum
enum|enum
block|{
name|eStreamStringIndex
init|=
literal|0
block|,
name|eImmediateStreamIndex
init|=
literal|1
block|}
enum|;
end_enum

begin_decl_stmt
name|StreamTee
name|m_out_stream
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|StreamTee
name|m_err_stream
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|ReturnStatus
name|m_status
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|m_did_change_process_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_interactive
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If true, then the input handle from the debugger will
end_comment

begin_comment
comment|// be hooked up
end_comment

begin_decl_stmt
name|bool
name|m_abnormal_stop_was_expected
decl_stmt|;
end_decl_stmt

begin_comment
comment|// This is to support
end_comment

begin_comment
comment|// eHandleCommandFlagStopOnCrash vrs.
end_comment

begin_comment
comment|// attach.
end_comment

begin_comment
comment|// The attach command often ends up with the process stopped due to a signal.
end_comment

begin_comment
comment|// Normally that would mean stop on crash should halt batch execution, but we
end_comment

begin_comment
comment|// obviously don't want that for attach.  Using this flag, the attach command
end_comment

begin_comment
comment|// (and anything else for which this is relevant) can say that the signal is
end_comment

begin_comment
comment|// expected, and batch command execution can continue.
end_comment

begin_comment
unit|};  }
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_CommandReturnObject_h_
end_comment

end_unit

