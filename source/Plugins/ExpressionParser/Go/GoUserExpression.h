begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GoUserExpression.h --------------------------------------*- C++ -*-===//
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
name|liblldb_GoUserExpression_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_GoUserExpression_h_
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
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/UserExpression.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/ExpressionVariable.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ExecutionContext.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|GoParser
decl_stmt|;
name|class
name|GoPersistentExpressionState
range|:
name|public
name|PersistentExpressionState
block|{
name|public
operator|:
name|GoPersistentExpressionState
argument_list|()
block|;
name|ConstString
name|GetNextPersistentVariableName
argument_list|()
name|override
block|;
name|void
name|RemovePersistentVariable
argument_list|(
argument|lldb::ExpressionVariableSP variable
argument_list|)
name|override
block|;
name|lldb
operator|::
name|addr_t
name|LookupSymbol
argument_list|(
argument|const ConstString&name
argument_list|)
name|override
block|{
return|return
name|LLDB_INVALID_ADDRESS
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const PersistentExpressionState *pv
argument_list|)
block|{
return|return
name|pv
operator|->
name|getKind
argument_list|()
operator|==
name|PersistentExpressionState
operator|::
name|eKindGo
return|;
block|}
name|private
operator|:
name|uint32_t
name|m_next_persistent_variable_id
block|;
comment|///< The counter used by GetNextResultName().
block|}
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class GoUserExpression GoUserExpression.h "lldb/Expression/GoUserExpression.h"
comment|/// @brief Encapsulates a single expression for use with Go
comment|///
comment|/// LLDB uses expressions for various purposes, notably to call functions
comment|/// and as a backend for the expr command.  GoUserExpression encapsulates
comment|/// the objects needed to parse and interpret an expression.
comment|//----------------------------------------------------------------------
name|class
name|GoUserExpression
range|:
name|public
name|UserExpression
block|{
name|public
operator|:
name|GoUserExpression
argument_list|(
argument|ExecutionContextScope&exe_scope
argument_list|,
argument|const char *expr
argument_list|,
argument|const char *expr_prefix
argument_list|,
argument|lldb::LanguageType language
argument_list|,
argument|ResultType desired_type
argument_list|,
argument|const EvaluateExpressionOptions&options
argument_list|)
block|;
name|bool
name|Parse
argument_list|(
argument|Stream&error_stream
argument_list|,
argument|ExecutionContext&exe_ctx
argument_list|,
argument|lldb_private::ExecutionPolicy execution_policy
argument_list|,
argument|bool keep_result_in_memory
argument_list|,
argument|bool generate_debug_info
argument_list|)
name|override
block|;
name|lldb
operator|::
name|ExpressionResults
name|Execute
argument_list|(
argument|Stream&error_stream
argument_list|,
argument|ExecutionContext&exe_ctx
argument_list|,
argument|const EvaluateExpressionOptions&options
argument_list|,
argument|lldb::UserExpressionSP&shared_ptr_to_me
argument_list|,
argument|lldb::ExpressionVariableSP&result
argument_list|)
name|override
block|;
name|bool
name|CanInterpret
argument_list|()
name|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|FinalizeJITExecution
argument_list|(
argument|Stream&error_stream
argument_list|,
argument|ExecutionContext&exe_ctx
argument_list|,
argument|lldb::ExpressionVariableSP&result
argument_list|,
argument|lldb::addr_t function_stack_bottom = LLDB_INVALID_ADDRESS
argument_list|,
argument|lldb::addr_t function_stack_top = LLDB_INVALID_ADDRESS
argument_list|)
name|override
block|{
return|return
name|true
return|;
block|}
name|private
operator|:
name|class
name|GoInterpreter
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|GoInterpreter
operator|>
name|m_interpreter
block|; }
decl_stmt|;
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
comment|// liblldb_GoUserExpression_h_
end_comment

end_unit

