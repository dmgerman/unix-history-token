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
name|template
operator|<
name|typename
operator|>
name|class
name|Ptr
operator|,
name|typename
name|ImplClass
operator|>
name|class
name|EvaluatedExprVisitorBase
operator|:
name|public
name|StmtVisitorBase
operator|<
name|Ptr
operator|,
name|ImplClass
operator|,
name|void
operator|>
block|{
name|protected
operator|:
specifier|const
name|ASTContext
operator|&
name|Context
block|;
name|public
operator|:
define|#
directive|define
name|PTR
parameter_list|(
name|CLASS
parameter_list|)
value|typename Ptr<CLASS>::type
name|explicit
name|EvaluatedExprVisitorBase
argument_list|(
specifier|const
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
argument|PTR(DeclRefExpr) E
argument_list|)
block|{ }
name|void
name|VisitOffsetOfExpr
argument_list|(
argument|PTR(OffsetOfExpr) E
argument_list|)
block|{ }
name|void
name|VisitUnaryExprOrTypeTraitExpr
argument_list|(
argument|PTR(UnaryExprOrTypeTraitExpr) E
argument_list|)
block|{ }
name|void
name|VisitExpressionTraitExpr
argument_list|(
argument|PTR(ExpressionTraitExpr) E
argument_list|)
block|{ }
name|void
name|VisitBlockExpr
argument_list|(
argument|PTR(BlockExpr) E
argument_list|)
block|{ }
name|void
name|VisitCXXUuidofExpr
argument_list|(
argument|PTR(CXXUuidofExpr) E
argument_list|)
block|{ }
name|void
name|VisitCXXNoexceptExpr
argument_list|(
argument|PTR(CXXNoexceptExpr) E
argument_list|)
block|{ }
name|void
name|VisitMemberExpr
argument_list|(
argument|PTR(MemberExpr) E
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
argument|PTR(ChooseExpr) E
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
name|VisitGenericSelectionExpr
argument_list|(
name|PTR
argument_list|(
argument|GenericSelectionExpr
argument_list|)
name|E
argument_list|)
block|{
comment|// The controlling expression of a generic selection is not evaluated.
comment|// Don't visit either child expression if the condition is type-dependent.
if|if
condition|(
name|E
operator|->
name|isResultDependent
argument_list|()
condition|)
return|return;
comment|// Only the selected subexpression matters; the other subexpressions and the
comment|// controlling expression are not evaluated.
return|return
name|this
operator|->
name|Visit
argument_list|(
name|E
operator|->
name|getResultExpr
argument_list|()
argument_list|)
return|;
block|}
name|void
name|VisitDesignatedInitExpr
argument_list|(
name|PTR
argument_list|(
argument|DesignatedInitExpr
argument_list|)
name|E
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
name|PTR
argument_list|(
argument|CXXTypeidExpr
argument_list|)
name|E
argument_list|)
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
argument_list|(
name|PTR
argument_list|(
argument|CallExpr
argument_list|)
name|CE
argument_list|)
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
argument_list|(
name|PTR
argument_list|(
argument|LambdaExpr
argument_list|)
name|LE
argument_list|)
block|{
comment|// Only visit the capture initializers, and not the body.
for|for
control|(
name|LambdaExpr
operator|::
name|const_capture_init_iterator
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
argument_list|(
name|PTR
argument_list|(
argument|Stmt
argument_list|)
name|S
argument_list|)
block|{
for|for
control|(
name|auto
operator|*
name|SubStmt
operator|:
name|S
operator|->
name|children
argument_list|()
control|)
if|if
condition|(
name|SubStmt
condition|)
name|this
operator|->
name|Visit
argument_list|(
name|SubStmt
argument_list|)
expr_stmt|;
block|}
undef|#
directive|undef
name|PTR
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// EvaluatedExprVisitor - This class visits 'Expr *'s
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|ImplClass
operator|>
name|class
name|EvaluatedExprVisitor
operator|:
name|public
name|EvaluatedExprVisitorBase
operator|<
name|make_ptr
operator|,
name|ImplClass
operator|>
block|{
name|public
operator|:
name|explicit
name|EvaluatedExprVisitor
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|)
operator|:
name|EvaluatedExprVisitorBase
operator|<
name|make_ptr
block|,
name|ImplClass
operator|>
operator|(
name|Context
operator|)
block|{ }
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// ConstEvaluatedExprVisitor - This class visits 'const Expr *'s.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|ImplClass
operator|>
name|class
name|ConstEvaluatedExprVisitor
operator|:
name|public
name|EvaluatedExprVisitorBase
operator|<
name|make_const_ptr
operator|,
name|ImplClass
operator|>
block|{
name|public
operator|:
name|explicit
name|ConstEvaluatedExprVisitor
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|)
operator|:
name|EvaluatedExprVisitorBase
operator|<
name|make_const_ptr
block|,
name|ImplClass
operator|>
operator|(
name|Context
operator|)
block|{ }
block|}
expr_stmt|;
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_AST_EVALUATEDEXPRVISITOR_H
end_comment

end_unit

