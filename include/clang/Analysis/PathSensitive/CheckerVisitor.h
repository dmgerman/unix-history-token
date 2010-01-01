begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== CheckerVisitor.h - Abstract visitor for checkers ------------*- C++ -*--=//
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
comment|//  This file defines CheckerVisitor.
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
name|LLVM_CLANG_ANALYSIS_CHECKERVISITOR
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_CHECKERVISITOR
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/Checker.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|//===----------------------------------------------------------------------===//
comment|// Checker visitor interface.  Used by subclasses of Checker to specify their
comment|// own checker visitor logic.
comment|//===----------------------------------------------------------------------===//
comment|/// CheckerVisitor - This class implements a simple visitor for Stmt subclasses.
comment|/// Since Expr derives from Stmt, this also includes support for visiting Exprs.
name|template
operator|<
name|typename
name|ImplClass
operator|>
name|class
name|CheckerVisitor
operator|:
name|public
name|Checker
block|{
name|public
operator|:
name|virtual
name|void
name|_PreVisit
argument_list|(
argument|CheckerContext&C
argument_list|,
argument|const Stmt *S
argument_list|)
block|{
name|PreVisit
argument_list|(
name|C
argument_list|,
name|S
argument_list|)
block|;   }
name|virtual
name|void
name|_PostVisit
argument_list|(
argument|CheckerContext&C
argument_list|,
argument|const Stmt *S
argument_list|)
block|{
name|PostVisit
argument_list|(
name|C
argument_list|,
name|S
argument_list|)
block|;   }
name|void
name|PreVisit
argument_list|(
argument|CheckerContext&C
argument_list|,
argument|const Stmt *S
argument_list|)
block|{
switch|switch
condition|(
name|S
operator|->
name|getStmtClass
argument_list|()
condition|)
block|{
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Unsupport statement."
argument_list|)
expr_stmt|;
return|return;
case|case
name|Stmt
operator|::
name|ImplicitCastExprClass
case|:
case|case
name|Stmt
operator|::
name|ExplicitCastExprClass
case|:
case|case
name|Stmt
operator|::
name|CStyleCastExprClass
case|:
name|static_cast
operator|<
name|ImplClass
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|PreVisitCastExpr
argument_list|(
name|C
argument_list|,
name|static_cast
operator|<
specifier|const
name|CastExpr
operator|*
operator|>
operator|(
name|S
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|Stmt
operator|::
name|CompoundAssignOperatorClass
case|:
name|static_cast
operator|<
name|ImplClass
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|PreVisitBinaryOperator
argument_list|(
name|C
argument_list|,
name|static_cast
operator|<
specifier|const
name|BinaryOperator
operator|*
operator|>
operator|(
name|S
operator|)
argument_list|)
expr_stmt|;
break|break;
define|#
directive|define
name|PREVISIT
parameter_list|(
name|NAME
parameter_list|,
name|FALLBACK
parameter_list|)
define|\
value|case Stmt::NAME ## Class:\ static_cast<ImplClass*>(this)->PreVisit ## NAME(C,static_cast<const NAME*>(S));\ break;
include|#
directive|include
file|"clang/Analysis/PathSensitive/CheckerVisitor.def"
block|}
block|}
name|void
name|PostVisit
argument_list|(
argument|CheckerContext&C
argument_list|,
argument|const Stmt *S
argument_list|)
block|{
switch|switch
condition|(
name|S
operator|->
name|getStmtClass
argument_list|()
condition|)
block|{
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Unsupport statement."
argument_list|)
expr_stmt|;
return|return;
define|#
directive|define
name|POSTVISIT
parameter_list|(
name|NAME
parameter_list|,
name|FALLBACK
parameter_list|)
define|\
value|case Stmt::NAME ## Class:\ static_cast<ImplClass*>(this)->\ PostVisit ## NAME(C,static_cast<const NAME*>(S));\ break;
include|#
directive|include
file|"clang/Analysis/PathSensitive/CheckerVisitor.def"
block|}
block|}
name|void
name|PreVisitStmt
argument_list|(
argument|CheckerContext&C
argument_list|,
argument|const Stmt *S
argument_list|)
block|{}
name|void
name|PostVisitStmt
argument_list|(
argument|CheckerContext&C
argument_list|,
argument|const Stmt *S
argument_list|)
block|{}
define|#
directive|define
name|PREVISIT
parameter_list|(
name|NAME
parameter_list|,
name|FALLBACK
parameter_list|)
define|\
value|void PreVisit ## NAME(CheckerContext&C, const NAME* S) {\   PreVisit ## FALLBACK(C, S);\ }
include|#
directive|include
file|"clang/Analysis/PathSensitive/CheckerVisitor.def"
define|#
directive|define
name|POSTVISIT
parameter_list|(
name|NAME
parameter_list|,
name|FALLBACK
parameter_list|)
define|\
value|void PostVisit ## NAME(CheckerContext&C, const NAME* S) {\   PostVisit ## FALLBACK(C, S);\ }
include|#
directive|include
file|"clang/Analysis/PathSensitive/CheckerVisitor.def"
block|}
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

