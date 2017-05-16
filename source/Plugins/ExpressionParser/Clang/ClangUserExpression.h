begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ClangUserExpression.h -----------------------------------*- C++ -*-===//
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
name|liblldb_ClangUserExpression_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ClangUserExpression_h_
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
file|"ASTResultSynthesizer.h"
end_include

begin_include
include|#
directive|include
file|"ASTStructExtractor.h"
end_include

begin_include
include|#
directive|include
file|"ClangExpressionDeclMap.h"
end_include

begin_include
include|#
directive|include
file|"ClangExpressionHelper.h"
end_include

begin_include
include|#
directive|include
file|"ClangExpressionVariable.h"
end_include

begin_include
include|#
directive|include
file|"IRForTarget.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Address.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ClangForward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/LLVMUserExpression.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/Materializer.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ExecutionContext.h"
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
comment|//----------------------------------------------------------------------
comment|/// @class ClangUserExpression ClangUserExpression.h
comment|/// "lldb/Expression/ClangUserExpression.h"
comment|/// @brief Encapsulates a single expression for use with Clang
comment|///
comment|/// LLDB uses expressions for various purposes, notably to call functions
comment|/// and as a backend for the expr command.  ClangUserExpression encapsulates
comment|/// the objects needed to parse and interpret or JIT an expression.  It
comment|/// uses the Clang parser to produce LLVM IR from the expression.
comment|//----------------------------------------------------------------------
name|class
name|ClangUserExpression
range|:
name|public
name|LLVMUserExpression
block|{
name|public
operator|:
expr|enum
block|{
name|kDefaultTimeout
operator|=
literal|500000u
block|}
block|;
name|class
name|ClangUserExpressionHelper
operator|:
name|public
name|ClangExpressionHelper
block|{
name|public
operator|:
name|ClangUserExpressionHelper
argument_list|(
argument|Target&target
argument_list|,
argument|bool top_level
argument_list|)
operator|:
name|m_target
argument_list|(
name|target
argument_list|)
block|,
name|m_top_level
argument_list|(
argument|top_level
argument_list|)
block|{}
operator|~
name|ClangUserExpressionHelper
argument_list|()
name|override
operator|=
expr|default
block|;
comment|//------------------------------------------------------------------
comment|/// Return the object that the parser should use when resolving external
comment|/// values.  May be NULL if everything should be self-contained.
comment|//------------------------------------------------------------------
name|ClangExpressionDeclMap
operator|*
name|DeclMap
argument_list|()
name|override
block|{
return|return
name|m_expr_decl_map_up
operator|.
name|get
argument_list|()
return|;
block|}
name|void
name|ResetDeclMap
argument_list|()
block|{
name|m_expr_decl_map_up
operator|.
name|reset
argument_list|()
block|; }
name|void
name|ResetDeclMap
argument_list|(
argument|ExecutionContext&exe_ctx
argument_list|,
argument|Materializer::PersistentVariableDelegate&result_delegate
argument_list|,
argument|bool keep_result_in_memory
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Return the object that the parser should allow to access ASTs.
comment|/// May be NULL if the ASTs do not need to be transformed.
comment|///
comment|/// @param[in] passthrough
comment|///     The ASTConsumer that the returned transformer should send
comment|///     the ASTs to after transformation.
comment|//------------------------------------------------------------------
name|clang
operator|::
name|ASTConsumer
operator|*
name|ASTTransformer
argument_list|(
argument|clang::ASTConsumer *passthrough
argument_list|)
name|override
block|;
name|void
name|CommitPersistentDecls
argument_list|()
name|override
block|;
name|private
operator|:
name|Target
operator|&
name|m_target
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|ClangExpressionDeclMap
operator|>
name|m_expr_decl_map_up
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|ASTStructExtractor
operator|>
name|m_struct_extractor_up
block|;
comment|///< The class
comment|///that generates
comment|///the argument
comment|///struct layout.
name|std
operator|::
name|unique_ptr
operator|<
name|ASTResultSynthesizer
operator|>
name|m_result_synthesizer_up
block|;
name|bool
name|m_top_level
block|;   }
block|;
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|///
comment|/// @param[in] expr
comment|///     The expression to parse.
comment|///
comment|/// @param[in] expr_prefix
comment|///     If non-NULL, a C string containing translation-unit level
comment|///     definitions to be included when the expression is parsed.
comment|///
comment|/// @param[in] language
comment|///     If not eLanguageTypeUnknown, a language to use when parsing
comment|///     the expression.  Currently restricted to those languages
comment|///     supported by Clang.
comment|///
comment|/// @param[in] desired_type
comment|///     If not eResultTypeAny, the type to use for the expression
comment|///     result.
comment|//------------------------------------------------------------------
name|ClangUserExpression
argument_list|(
argument|ExecutionContextScope&exe_scope
argument_list|,
argument|llvm::StringRef expr
argument_list|,
argument|llvm::StringRef prefix
argument_list|,
argument|lldb::LanguageType language
argument_list|,
argument|ResultType desired_type
argument_list|,
argument|const EvaluateExpressionOptions&options
argument_list|)
block|;
operator|~
name|ClangUserExpression
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// Parse the expression
comment|///
comment|/// @param[in] diagnostic_manager
comment|///     A diagnostic manager to report parse errors and warnings to.
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to use when looking up entities that
comment|///     are needed for parsing (locations of functions, types of
comment|///     variables, persistent variables, etc.)
comment|///
comment|/// @param[in] execution_policy
comment|///     Determines whether interpretation is possible or mandatory.
comment|///
comment|/// @param[in] keep_result_in_memory
comment|///     True if the resulting persistent variable should reside in
comment|///     target memory, if applicable.
comment|///
comment|/// @return
comment|///     True on success (no errors); false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|Parse
argument_list|(
argument|DiagnosticManager&diagnostic_manager
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
name|ExpressionTypeSystemHelper
operator|*
name|GetTypeSystemHelper
argument_list|()
name|override
block|{
return|return
operator|&
name|m_type_system_helper
return|;
block|}
name|ClangExpressionDeclMap
operator|*
name|DeclMap
argument_list|()
block|{
return|return
name|m_type_system_helper
operator|.
name|DeclMap
argument_list|()
return|;
block|}
name|void
name|ResetDeclMap
argument_list|()
block|{
name|m_type_system_helper
operator|.
name|ResetDeclMap
argument_list|()
block|; }
name|void
name|ResetDeclMap
argument_list|(
argument|ExecutionContext&exe_ctx
argument_list|,
argument|Materializer::PersistentVariableDelegate&result_delegate
argument_list|,
argument|bool keep_result_in_memory
argument_list|)
block|{
name|m_type_system_helper
operator|.
name|ResetDeclMap
argument_list|(
name|exe_ctx
argument_list|,
name|result_delegate
argument_list|,
name|keep_result_in_memory
argument_list|)
block|;   }
name|lldb
operator|::
name|ExpressionVariableSP
name|GetResultAfterDematerialization
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|)
name|override
block|;
name|private
operator|:
comment|//------------------------------------------------------------------
comment|/// Populate m_in_cplusplus_method and m_in_objectivec_method based on the
comment|/// environment.
comment|//------------------------------------------------------------------
name|void
name|ScanContext
argument_list|(
argument|ExecutionContext&exe_ctx
argument_list|,
argument|lldb_private::Status&err
argument_list|)
name|override
block|;
name|bool
name|AddArguments
argument_list|(
argument|ExecutionContext&exe_ctx
argument_list|,
argument|std::vector<lldb::addr_t>&args
argument_list|,
argument|lldb::addr_t struct_address
argument_list|,
argument|DiagnosticManager&diagnostic_manager
argument_list|)
name|override
block|;
name|ClangUserExpressionHelper
name|m_type_system_helper
block|;
name|class
name|ResultDelegate
operator|:
name|public
name|Materializer
operator|::
name|PersistentVariableDelegate
block|{
name|public
operator|:
name|ResultDelegate
argument_list|()
block|;
name|ConstString
name|GetName
argument_list|()
name|override
block|;
name|void
name|DidDematerialize
argument_list|(
argument|lldb::ExpressionVariableSP&variable
argument_list|)
name|override
block|;
name|void
name|RegisterPersistentState
argument_list|(
name|PersistentExpressionState
operator|*
name|persistent_state
argument_list|)
block|;
name|lldb
operator|::
name|ExpressionVariableSP
operator|&
name|GetVariable
argument_list|()
block|;
name|private
operator|:
name|PersistentExpressionState
operator|*
name|m_persistent_state
block|;
name|lldb
operator|::
name|ExpressionVariableSP
name|m_variable
block|;   }
block|;
name|ResultDelegate
name|m_result_delegate
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
comment|// liblldb_ClangUserExpression_h_
end_comment

end_unit

