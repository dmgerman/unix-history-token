begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ClangUtilityFunction.h ----------------------------------*- C++ -*-===//
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
name|liblldb_ClangUtilityFunction_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ClangUtilityFunction_h_
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
file|<string>
end_include

begin_include
include|#
directive|include
file|<map>
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
file|"ClangExpressionHelper.h"
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

begin_include
include|#
directive|include
file|"lldb/Core/ClangForward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/UtilityFunction.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class ClangUtilityFunction ClangUtilityFunction.h "lldb/Expression/ClangUtilityFunction.h"
comment|/// @brief Encapsulates a single expression for use with Clang
comment|///
comment|/// LLDB uses expressions for various purposes, notably to call functions
comment|/// and as a backend for the expr command.  ClangUtilityFunction encapsulates
comment|/// a self-contained function meant to be used from other code.  Utility
comment|/// functions can perform error-checking for ClangUserExpressions, or can
comment|/// simply provide a way to push a function into the target for the debugger to
comment|/// call later on.
comment|//----------------------------------------------------------------------
name|class
name|ClangUtilityFunction
range|:
name|public
name|UtilityFunction
block|{
name|public
operator|:
name|class
name|ClangUtilityFunctionHelper
operator|:
name|public
name|ClangExpressionHelper
block|{
name|public
operator|:
name|ClangUtilityFunctionHelper
argument_list|()
block|{         }
operator|~
name|ClangUtilityFunctionHelper
argument_list|()
name|override
block|{}
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
block|;         }
name|void
name|ResetDeclMap
argument_list|(
argument|ExecutionContext& exe_ctx
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
block|{
return|return
name|nullptr
return|;
block|}
name|private
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|ClangExpressionDeclMap
operator|>
name|m_expr_decl_map_up
block|;     }
block|;
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|///
comment|/// @param[in] text
comment|///     The text of the function.  Must be a full translation unit.
comment|///
comment|/// @param[in] name
comment|///     The name of the function, as used in the text.
comment|//------------------------------------------------------------------
name|ClangUtilityFunction
argument_list|(
name|ExecutionContextScope
operator|&
name|exe_scope
argument_list|,
specifier|const
name|char
operator|*
name|text
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
operator|~
name|ClangUtilityFunction
argument_list|()
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
block|;     }
name|void
name|ResetDeclMap
argument_list|(
argument|ExecutionContext& exe_ctx
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
name|keep_result_in_memory
argument_list|)
block|;     }
name|bool
name|Install
argument_list|(
argument|Stream&error_stream
argument_list|,
argument|ExecutionContext&exe_ctx
argument_list|)
name|override
block|;
name|private
operator|:
name|ClangUtilityFunctionHelper
name|m_type_system_helper
block|;
comment|///< The map to use when parsing and materializing the expression.
block|}
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
comment|// liblldb_ClangUtilityFunction_h_
end_comment

end_unit

