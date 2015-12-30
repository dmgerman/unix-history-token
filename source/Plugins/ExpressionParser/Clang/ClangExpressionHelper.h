begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ClangExpression.h ---------------------------------------*- C++ -*-===//
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
name|liblldb_ClangExpression_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ClangExpression_h_
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
file|"lldb/Expression/ExpressionTypeSystemHelper.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|RecordingMemoryManager
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|// ClangExpressionHelper
comment|//----------------------------------------------------------------------
name|class
name|ClangExpressionHelper
range|:
name|public
name|ExpressionTypeSystemHelper
block|{
name|public
operator|:
specifier|static
name|bool
name|classof
argument_list|(
argument|const ExpressionTypeSystemHelper *ts
argument_list|)
block|{
return|return
name|ts
operator|->
name|getKind
argument_list|()
operator|==
name|eKindClangHelper
return|;
block|}
name|ClangExpressionHelper
argument_list|()
operator|:
name|ExpressionTypeSystemHelper
argument_list|(
argument|ExpressionTypeSystemHelper::LLVMCastKind::eKindClangHelper
argument_list|)
block|{     }
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|//------------------------------------------------------------------
name|virtual
operator|~
name|ClangExpressionHelper
argument_list|()
block|{     }
comment|//------------------------------------------------------------------
comment|/// Return the object that the parser should use when resolving external
comment|/// values.  May be NULL if everything should be self-contained.
comment|//------------------------------------------------------------------
name|virtual
name|ClangExpressionDeclMap
operator|*
name|DeclMap
argument_list|()
operator|=
literal|0
block|;
comment|//------------------------------------------------------------------
comment|/// Return the object that the parser should allow to access ASTs.
comment|/// May be NULL if the ASTs do not need to be transformed.
comment|///
comment|/// @param[in] passthrough
comment|///     The ASTConsumer that the returned transformer should send
comment|///     the ASTs to after transformation.
comment|//------------------------------------------------------------------
name|virtual
name|clang
operator|::
name|ASTConsumer
operator|*
name|ASTTransformer
argument_list|(
name|clang
operator|::
name|ASTConsumer
operator|*
name|passthrough
argument_list|)
operator|=
literal|0
block|;
name|protected
operator|:
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
comment|// liblldb_ClangExpression_h_
end_comment

end_unit

