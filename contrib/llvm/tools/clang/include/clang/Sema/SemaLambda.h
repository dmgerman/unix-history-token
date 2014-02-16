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
name|LLVM_CLANG_SEMA_LAMBDA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_LAMBDA_H
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
comment|// Given a lambda's call operator and a variable (or null for 'this'),
comment|// compute the nearest enclosing lambda that is capture-ready (i.e
comment|// the enclosing context is not dependent, and all intervening lambdas can
comment|// either implicitly or explicitly capture Var)
comment|//
comment|// Return the CallOperator of the capturable lambda and set function scope
comment|// index to the correct index within the function scope stack to correspond
comment|// to the capturable lambda.
comment|// If VarDecl *VD is null, we check for 'this' capture.
name|CXXMethodDecl
modifier|*
name|GetInnermostEnclosingCapturableLambda
argument_list|(
name|ArrayRef
operator|<
name|sema
operator|::
name|FunctionScopeInfo
operator|*
operator|>
name|FunctionScopes
argument_list|,
name|unsigned
operator|&
name|FunctionScopeIndex
argument_list|,
name|DeclContext
operator|*
specifier|const
name|CurContext
argument_list|,
name|VarDecl
operator|*
name|VD
argument_list|,
name|Sema
operator|&
name|S
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_SEMA_LAMBDA_H
end_comment

end_unit

