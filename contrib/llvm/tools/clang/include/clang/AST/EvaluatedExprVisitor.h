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

begin_include
include|#
directive|include
file|"clang/AST/StmtVisitor.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
comment|/// \brief Given a potentially-evaluated expression, this visitor visits all
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
comment|// Don't visit either child expression if the condition is dependent.
if|if
condition|(
name|E
operator|->
name|getCond
argument_list|()
operator|->
name|isValueDependent
argument_list|()
condition|)
return|return;
comment|// Only the selected subexpression matters; the other one is not evaluated.
return|return
name|this
operator|->
name|Visit
argument_list|(
name|E
operator|->
name|getChosenSubExpr
argument_list|()
argument_list|)
return|;
block|}
name|void
name|VisitDesignatedInitExpr
parameter_list|(
name|DesignatedInitExpr
modifier|*
name|E
parameter_list|)
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
parameter_list|(
name|CXXTypeidExpr
modifier|*
name|E
parameter_list|)
block|{
if|if
condition|(
name|E
operator|->
name|isPotentiallyEvaluated
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
name|void
name|VisitCallExpr
parameter_list|(
name|CallExpr
modifier|*
name|CE
parameter_list|)
block|{
if|if
condition|(
operator|!
name|CE
operator|->
name|isUnevaluatedBuiltinCall
argument_list|(
name|Context
argument_list|)
condition|)
return|return
name|static_cast
operator|<
name|ImplClass
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|VisitExpr
argument_list|(
name|CE
argument_list|)
return|;
block|}
name|void
name|VisitLambdaExpr
parameter_list|(
name|LambdaExpr
modifier|*
name|LE
parameter_list|)
block|{
comment|// Only visit the capture initializers, and not the body.
for|for
control|(
name|LambdaExpr
operator|::
name|capture_init_iterator
name|I
operator|=
name|LE
operator|->
name|capture_init_begin
argument_list|()
operator|,
name|E
operator|=
name|LE
operator|->
name|capture_init_end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
if|if
condition|(
operator|*
name|I
condition|)
name|this
operator|->
name|Visit
argument_list|(
operator|*
name|I
argument_list|)
expr_stmt|;
block|}
comment|/// \brief The basis case walks all of the children of the statement or
comment|/// expression, assuming they are all potentially evaluated.
name|void
name|VisitStmt
parameter_list|(
name|Stmt
modifier|*
name|S
parameter_list|)
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_AST_EVALUATEDEXPRVISITOR_H
end_comment

end_unit

