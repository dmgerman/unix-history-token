begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBError.h -----------------------------------------------*- C++ -*-===//
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
name|LLDB_SBError_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBError_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|LLDB_API
name|SBError
block|{
name|public
label|:
name|SBError
argument_list|()
expr_stmt|;
name|SBError
argument_list|(
specifier|const
name|lldb
operator|::
name|SBError
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|SBError
argument_list|()
expr_stmt|;
specifier|const
name|SBError
modifier|&
name|operator
init|=
operator|(
specifier|const
name|lldb
operator|::
name|SBError
operator|&
name|rhs
operator|)
decl_stmt|;
specifier|const
name|char
operator|*
name|GetCString
argument_list|()
specifier|const
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|bool
name|Fail
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|Success
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|GetError
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|ErrorType
name|GetType
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetError
argument_list|(
name|uint32_t
name|err
argument_list|,
name|lldb
operator|::
name|ErrorType
name|type
argument_list|)
decl_stmt|;
name|void
name|SetErrorToErrno
parameter_list|()
function_decl|;
name|void
name|SetErrorToGenericError
parameter_list|()
function_decl|;
name|void
name|SetErrorString
parameter_list|(
specifier|const
name|char
modifier|*
name|err_str
parameter_list|)
function_decl|;
name|int
name|SetErrorStringWithFormat
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

begin_expr_stmt
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|GetDescription
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|description
argument_list|)
decl_stmt|;
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|friend
name|class
name|SBCommandReturnObject
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBData
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBDebugger
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBCommunication
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBHostOS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBPlatform
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBProcess
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBStructuredData
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBThread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBTrace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBTarget
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBValue
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBWatchpoint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBBreakpoint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBBreakpointLocation
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Error
operator|*
name|get
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Error
operator|*
name|operator
operator|->
expr|(
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|const
name|lldb_private
operator|::
name|Error
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Error
operator|&
name|ref
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|SetError
argument_list|(
specifier|const
name|lldb_private
operator|::
name|Error
operator|&
name|lldb_error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|Error
operator|>
name|m_opaque_ap
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|CreateIfNeeded
parameter_list|()
function_decl|;
end_function_decl

begin_comment
unit|};  }
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBError_h_
end_comment

end_unit

