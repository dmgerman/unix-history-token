begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- SemaLambda.h - Lambda Helper Functions --------------*- C++ -*-===//
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

begin_comment
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file provides some common utility functions for processing
end_comment

begin_comment
comment|/// Lambdas.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_SEMA_SEMALAMBDA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_SEMALAMBDA_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/ASTLambda.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/ScopeInfo.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Examines the FunctionScopeInfo stack to determine the nearest
comment|/// enclosing lambda (to the current lambda) that is 'capture-capable' for
comment|/// the variable referenced in the current lambda (i.e. \p VarToCapture).
comment|/// If successful, returns the index into Sema's FunctionScopeInfo stack
comment|/// of the capture-capable lambda's LambdaScopeInfo.
comment|/// See Implementation for more detailed comments.
name|Optional
operator|<
name|unsigned
operator|>
name|getStackIndexOfNearestEnclosingCaptureCapableLambda
argument_list|(
name|ArrayRef
operator|<
specifier|const
name|sema
operator|::
name|FunctionScopeInfo
operator|*
operator|>
name|FunctionScopes
argument_list|,
name|VarDecl
operator|*
name|VarToCapture
argument_list|,
name|Sema
operator|&
name|S
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

