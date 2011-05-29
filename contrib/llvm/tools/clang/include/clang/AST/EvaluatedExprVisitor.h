begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- EvaluatedExprVisitor.h - Evaluated expression visitor --*- C++ -*-===//
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
comment|//  This file defines the EvaluatedExprVisitor class template, which visits
end_comment

begin_comment
comment|//  the potentially-evaluated subexpressions of a potentially-evaluated
end_comment

begin_comment
comment|//  expression.
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
name|LLVM_CLANG_AST_EVALUATEDEXPRVISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_EVALUATEDEXPRVISITOR_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/StmtVisitor.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExprCXX.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
comment|/// \begin Given a potentially-evaluated expression, this visitor visits all
comment|/// of its potentially-evaluated subexpressions, recursively.
name|template
operator|<
name|typename
name|ImplClass
operator|>
name|class
name|EvaluatedExprVisitor
operator|:
name|public
name|StmtVisitor
operator|<
name|ImplClass
operator|>
block|{
name|ASTContext
operator|&
name|Context
block|;
name|public
operator|:
name|explicit
name|EvaluatedExprVisitor
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|)
operator|:
name|Context
argument_list|(
argument|Context
argument_list|)
block|{ }
comment|// Expressions that have no potentially-evaluated subexpressions (but may have
comment|// other sub-expressions).
name|void
name|VisitDeclRefExpr
argument_list|(
argument|DeclRefExpr *E
argument_list|)
block|{ }
name|void
name|VisitOffsetOfExpr
argument_list|(
argument|OffsetOfExpr *E
argument_list|)
block|{ }
name|void
name|VisitUnaryExprOrTypeTraitExpr
argument_list|(
argument|UnaryExprOrTypeTraitExpr *E
argument_list|)
block|{ }
name|void
name|VisitExpressionTraitExpr
argument_list|(
argument|ExpressionTraitExpr *E
argument_list|)
block|{ }
name|void
name|VisitBlockExpr
argument_list|(
argument|BlockExpr *E
argument_list|)
block|{ }
name|void
name|VisitCXXUuidofExpr
argument_list|(
argument|CXXUuidofExpr *E
argument_list|)
block|{ }
name|void
name|VisitCXXNoexceptExpr
argument_list|(
argument|CXXNoexceptExpr *E
argument_list|)
block|{ }
name|void
name|VisitMemberExpr
argument_list|(
argument|MemberExpr *E
argument_list|)
block|{
comment|// Only the base matters.
return|return
name|this
operator|->
name|Visit
argument_list|(
name|E
operator|->
name|getBase
argument_list|()
argument_list|)
return|;
block|}
name|void
name|VisitChooseExpr
argument_list|(
argument|ChooseExpr *E
argument_list|)
block|{
comment|// Only the selected subexpression matters; the other one is not evaluated.
return|return
name|this
operator|->
name|Visit
argument_list|(
name|E
operator|->
name|getChosenSubExpr
argument_list|(
name|Context
argument_list|)
argument_list|)
return|;
block|}
name|void
name|VisitDesignatedInitExpr
argument_list|(
argument|DesignatedInitExpr *E
argument_list|)
block|{
comment|// Only the actual initializer matters; the designators are all constant
comment|// expressions.
return|return
name|this
operator|->
name|Visit
argument_list|(
name|E
operator|->
name|getInit
argument_list|()
argument_list|)
return|;
block|}
name|void
name|VisitCXXTypeidExpr
argument_list|(
argument|CXXTypeidExpr *E
argument_list|)
block|{
comment|// typeid(expression) is potentially evaluated when the argument is
comment|// a glvalue of polymorphic type. (C++ 5.2.8p2-3)
if|if
condition|(
operator|!
name|E
operator|->
name|isTypeOperand
argument_list|()
operator|&&
name|E
operator|->
name|Classify
argument_list|(
name|Context
argument_list|)
operator|.
name|isGLValue
argument_list|()
condition|)
if|if
condition|(
specifier|const
name|RecordType
modifier|*
name|Record
init|=
name|E
operator|->
name|getExprOperand
argument_list|()
operator|->
name|getType
argument_list|()
operator|->
name|template
name|getAs
operator|<
name|RecordType
operator|>
operator|(
operator|)
condition|)
if|if
condition|(
name|cast
operator|<
name|CXXRecordDecl
operator|>
operator|(
name|Record
operator|->
name|getDecl
argument_list|()
operator|)
operator|->
name|isPolymorphic
argument_list|()
condition|)
return|return
name|this
operator|->
name|Visit
argument_list|(
name|E
operator|->
name|getExprOperand
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief The basis case walks all of the children of the statement or
comment|/// expression, assuming they are all potentially evaluated.
name|void
name|VisitStmt
argument_list|(
argument|Stmt *S
argument_list|)
block|{
for|for
control|(
name|Stmt
operator|::
name|child_range
name|C
operator|=
name|S
operator|->
name|children
argument_list|()
init|;
name|C
condition|;
operator|++
name|C
control|)
if|if
condition|(
operator|*
name|C
condition|)
name|this
operator|->
name|Visit
argument_list|(
operator|*
name|C
argument_list|)
expr_stmt|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_AST_EVALUATEDEXPRVISITOR_H
end_comment

end_unit

