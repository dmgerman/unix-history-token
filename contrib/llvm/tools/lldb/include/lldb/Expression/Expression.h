begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Expression.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_Expression_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Expression_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
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
file|"lldb/Expression/ExpressionTypeSystemHelper.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|RecordingMemoryManager
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class Expression Expression.h "lldb/Expression/Expression.h"
comment|/// @brief Encapsulates a single expression for use in lldb
comment|///
comment|/// LLDB uses expressions for various purposes, notably to call functions
comment|/// and as a backend for the expr command.  Expression encapsulates
comment|/// the objects needed to parse and interpret or JIT an expression.  It
comment|/// uses the expression parser appropriate to the language of the expression
comment|/// to produce LLVM IR from the expression.
comment|//----------------------------------------------------------------------
name|class
name|Expression
block|{
name|public
label|:
enum|enum
name|ResultType
block|{
name|eResultTypeAny
block|,
name|eResultTypeId
block|}
enum|;
name|Expression
argument_list|(
name|Target
operator|&
name|target
argument_list|)
expr_stmt|;
name|Expression
argument_list|(
name|ExecutionContextScope
operator|&
name|exe_scope
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|//------------------------------------------------------------------
name|virtual
operator|~
name|Expression
argument_list|()
block|{}
comment|//------------------------------------------------------------------
comment|/// Return the string that the parser should parse.  Must be a full
comment|/// translation unit.
comment|//------------------------------------------------------------------
name|virtual
specifier|const
name|char
operator|*
name|Text
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the function name that should be used for executing the
comment|/// expression.  Text() should contain the definition of this
comment|/// function.
comment|//------------------------------------------------------------------
name|virtual
specifier|const
name|char
modifier|*
name|FunctionName
parameter_list|()
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Return the language that should be used when parsing.  To use
comment|/// the default, return eLanguageTypeUnknown.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|LanguageType
name|Language
argument_list|()
block|{
return|return
name|lldb
operator|::
name|eLanguageTypeUnknown
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the desired result type of the function, or
comment|/// eResultTypeAny if indifferent.
comment|//------------------------------------------------------------------
name|virtual
name|ResultType
name|DesiredResultType
parameter_list|()
block|{
return|return
name|eResultTypeAny
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Flags
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Return true if validation code should be inserted into the
comment|/// expression.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|NeedsValidation
parameter_list|()
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Return true if external variables in the expression should be
comment|/// resolved.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|NeedsVariableResolution
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|EvaluateExpressionOptions
modifier|*
name|GetOptions
parameter_list|()
block|{
return|return
name|nullptr
return|;
block|}
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the address of the function's JIT-compiled code, or
comment|/// LLDB_INVALID_ADDRESS if the function is not JIT compiled
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|StartAddress
argument_list|()
block|{
return|return
name|m_jit_start_addr
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Called to notify the expression that it is about to be executed.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|WillStartExecuting
parameter_list|()
block|{}
comment|//------------------------------------------------------------------
comment|/// Called to notify the expression that its execution has finished.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DidFinishExecuting
parameter_list|()
block|{}
name|virtual
name|ExpressionTypeSystemHelper
modifier|*
name|GetTypeSystemHelper
parameter_list|()
block|{
return|return
name|nullptr
return|;
block|}
name|protected
label|:
name|lldb
operator|::
name|TargetWP
name|m_target_wp
expr_stmt|;
comment|/// Expression's always have to have a target...
name|lldb
operator|::
name|ProcessWP
name|m_jit_process_wp
expr_stmt|;
comment|/// An expression might have a process, but
comment|/// it doesn't need to (e.g. calculator
comment|/// mode.)
name|lldb
operator|::
name|addr_t
name|m_jit_start_addr
expr_stmt|;
comment|///< The address of the JITted function within
comment|///the JIT allocation.  LLDB_INVALID_ADDRESS if
comment|///invalid.
name|lldb
operator|::
name|addr_t
name|m_jit_end_addr
expr_stmt|;
comment|///< The address of the JITted function within
comment|///the JIT allocation.  LLDB_INVALID_ADDRESS if
comment|///invalid.
block|}
empty_stmt|;
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
comment|// liblldb_Expression_h_
end_comment

end_unit

