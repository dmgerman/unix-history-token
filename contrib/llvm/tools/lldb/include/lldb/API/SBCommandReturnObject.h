begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBCommandReturnObject.h ---------------------------------*- C++ -*-===//
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
name|LLDB_SBCommandReturnObject_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBCommandReturnObject_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<memory>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

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
name|SBCommandReturnObject
block|{
name|public
label|:
name|SBCommandReturnObject
argument_list|()
expr_stmt|;
name|SBCommandReturnObject
argument_list|(
specifier|const
name|lldb
operator|::
name|SBCommandReturnObject
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|SBCommandReturnObject
argument_list|()
expr_stmt|;
specifier|const
name|lldb
operator|::
name|SBCommandReturnObject
operator|&
name|operator
operator|=
operator|(
specifier|const
name|lldb
operator|::
name|SBCommandReturnObject
operator|&
name|rhs
operator|)
expr_stmt|;
name|SBCommandReturnObject
argument_list|(
name|lldb_private
operator|::
name|CommandReturnObject
operator|*
name|ptr
argument_list|)
expr_stmt|;
name|lldb_private
operator|::
name|CommandReturnObject
operator|*
name|Release
argument_list|()
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
modifier|*
name|GetOutput
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|GetError
parameter_list|()
function_decl|;
name|size_t
name|PutOutput
parameter_list|(
name|FILE
modifier|*
name|fh
parameter_list|)
function_decl|;
name|size_t
name|GetOutputSize
parameter_list|()
function_decl|;
name|size_t
name|GetErrorSize
parameter_list|()
function_decl|;
name|size_t
name|PutError
parameter_list|(
name|FILE
modifier|*
name|fh
parameter_list|)
function_decl|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|lldb
operator|::
name|ReturnStatus
name|GetStatus
argument_list|()
expr_stmt|;
name|void
name|SetStatus
argument_list|(
name|lldb
operator|::
name|ReturnStatus
name|status
argument_list|)
decl_stmt|;
name|bool
name|Succeeded
parameter_list|()
function_decl|;
name|bool
name|HasResult
parameter_list|()
function_decl|;
name|void
name|AppendMessage
parameter_list|(
specifier|const
name|char
modifier|*
name|message
parameter_list|)
function_decl|;
name|void
name|AppendWarning
parameter_list|(
specifier|const
name|char
modifier|*
name|message
parameter_list|)
function_decl|;
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
name|void
name|SetImmediateOutputFile
parameter_list|(
name|FILE
modifier|*
name|fh
parameter_list|)
function_decl|;
name|void
name|SetImmediateErrorFile
parameter_list|(
name|FILE
modifier|*
name|fh
parameter_list|)
function_decl|;
name|void
name|PutCString
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|int
name|len
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
name|size_t
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
specifier|const
name|char
modifier|*
name|GetOutput
parameter_list|(
name|bool
name|only_if_no_immediate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|GetError
parameter_list|(
name|bool
name|only_if_no_immediate
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|SetError
argument_list|(
name|lldb
operator|::
name|SBError
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
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|SetError
parameter_list|(
specifier|const
name|char
modifier|*
name|error_cstr
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|friend
name|class
name|SBCommandInterpreter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBOptions
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|CommandReturnObject
operator|*
name|operator
operator|->
expr|(
end_expr_stmt

begin_decl_stmt
unit|)
specifier|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|CommandReturnObject
operator|*
name|get
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|CommandReturnObject
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
name|CommandReturnObject
operator|&
name|ref
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|SetLLDBObjectPtr
argument_list|(
name|lldb_private
operator|::
name|CommandReturnObject
operator|*
name|ptr
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
name|CommandReturnObject
operator|>
name|m_opaque_ap
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBCommandReturnObject_h_
end_comment

end_unit

