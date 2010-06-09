begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- CFGRecStmtVisitor - Recursive visitor of CFG statements ---*- C++ --*-==//
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
comment|//
end_comment

begin_comment
comment|// This file implements the template class CFGRecStmtVisitor, which extends
end_comment

begin_comment
comment|// CFGStmtVisitor by implementing a default recursive visit of all statements.
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
name|LLVM_CLANG_ANALYSIS_CFG_REC_STMT_VISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_CFG_REC_STMT_VISITOR_H
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/Visitors/CFGStmtVisitor.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|template
operator|<
name|typename
name|ImplClass
operator|>
name|class
name|CFGRecStmtVisitor
operator|:
name|public
name|CFGStmtVisitor
operator|<
name|ImplClass
operator|,
name|void
operator|>
block|{
name|public
operator|:
name|void
name|VisitStmt
argument_list|(
argument|Stmt* S
argument_list|)
block|{
name|static_cast
operator|<
name|ImplClass
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|VisitChildren
argument_list|(
name|S
argument_list|)
block|;   }
name|void
name|VisitConditionVariableInit
argument_list|(
argument|Stmt *S
argument_list|)
block|{
name|assert
argument_list|(
name|S
operator|==
name|this
operator|->
name|getCurrentBlkStmt
argument_list|()
argument_list|)
block|;
name|VarDecl
operator|*
name|CondVar
operator|=
literal|0
block|;
switch|switch
condition|(
name|S
operator|->
name|getStmtClass
argument_list|()
condition|)
block|{
define|#
directive|define
name|CONDVAR_CASE
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|case Stmt::CLASS ## Class:\ CondVar = cast<CLASS>(S)->getConditionVariable();\ break;
name|CONDVAR_CASE
argument_list|(
argument|IfStmt
argument_list|)
name|CONDVAR_CASE
argument_list|(
argument|ForStmt
argument_list|)
name|CONDVAR_CASE
argument_list|(
argument|SwitchStmt
argument_list|)
name|CONDVAR_CASE
argument_list|(
argument|WhileStmt
argument_list|)
undef|#
directive|undef
name|CONDVAR_CASE
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Infeasible"
argument_list|)
expr_stmt|;
block|}
name|static_cast
operator|<
name|ImplClass
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|Visit
argument_list|(
name|CondVar
operator|->
name|getInit
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Defining operator() allows the visitor to be used as a C++ style functor.
name|void
name|operator
argument_list|()
operator|(
name|Stmt
operator|*
name|S
operator|)
block|{
name|static_cast
operator|<
name|ImplClass
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|BlockStmt_Visit
argument_list|(
name|S
argument_list|)
block|;}
block|}
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

