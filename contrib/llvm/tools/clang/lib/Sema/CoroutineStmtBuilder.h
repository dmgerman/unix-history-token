begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CoroutineStmtBuilder.h - Implicit coroutine stmt builder -*- C++ -*-===//
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
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file defines CoroutineStmtBuilder, a class for building the implicit
end_comment

begin_comment
comment|//  statements required for building a coroutine body.
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
name|LLVM_CLANG_LIB_SEMA_COROUTINESTMTBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_SEMA_COROUTINESTMTBUILDER_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExprCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/StmtCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/Preprocessor.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/SemaInternal.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CoroutineStmtBuilder
range|:
name|public
name|CoroutineBodyStmt
operator|::
name|CtorArgs
block|{
name|Sema
operator|&
name|S
block|;
name|FunctionDecl
operator|&
name|FD
block|;
name|sema
operator|::
name|FunctionScopeInfo
operator|&
name|Fn
block|;
name|bool
name|IsValid
operator|=
name|true
block|;
name|SourceLocation
name|Loc
block|;
name|SmallVector
operator|<
name|Stmt
operator|*
block|,
literal|4
operator|>
name|ParamMovesVector
block|;
specifier|const
name|bool
name|IsPromiseDependentType
block|;
name|CXXRecordDecl
operator|*
name|PromiseRecordDecl
operator|=
name|nullptr
block|;
name|public
operator|:
comment|/// \brief Construct a CoroutineStmtBuilder and initialize the promise
comment|/// statement and initial/final suspends from the FunctionScopeInfo.
name|CoroutineStmtBuilder
argument_list|(
name|Sema
operator|&
name|S
argument_list|,
name|FunctionDecl
operator|&
name|FD
argument_list|,
name|sema
operator|::
name|FunctionScopeInfo
operator|&
name|Fn
argument_list|,
name|Stmt
operator|*
name|Body
argument_list|)
block|;
comment|/// \brief Build the coroutine body statements, including the
comment|/// "promise dependent" statements when the promise type is not dependent.
name|bool
name|buildStatements
argument_list|()
block|;
comment|/// \brief Build the coroutine body statements that require a non-dependent
comment|/// promise type in order to construct.
comment|///
comment|/// For example different new/delete overloads are selected depending on
comment|/// if the promise type provides `unhandled_exception()`, and therefore they
comment|/// cannot be built until the promise type is complete so that we can perform
comment|/// name lookup.
name|bool
name|buildDependentStatements
argument_list|()
block|;
comment|/// \brief Build just parameter moves. To use for rebuilding in TreeTransform.
name|bool
name|buildParameterMoves
argument_list|()
block|;
name|bool
name|isInvalid
argument_list|()
specifier|const
block|{
return|return
operator|!
name|this
operator|->
name|IsValid
return|;
block|}
name|private
operator|:
name|bool
name|makePromiseStmt
argument_list|()
block|;
name|bool
name|makeInitialAndFinalSuspend
argument_list|()
block|;
name|bool
name|makeNewAndDeleteExpr
argument_list|()
block|;
name|bool
name|makeOnFallthrough
argument_list|()
block|;
name|bool
name|makeOnException
argument_list|()
block|;
name|bool
name|makeReturnObject
argument_list|()
block|;
name|bool
name|makeGroDeclAndReturnStmt
argument_list|()
block|;
name|bool
name|makeReturnOnAllocFailure
argument_list|()
block|;
name|bool
name|makeParamMoves
argument_list|()
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_LIB_SEMA_COROUTINESTMTBUILDER_H
end_comment

end_unit

