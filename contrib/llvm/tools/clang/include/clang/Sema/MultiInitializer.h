begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- MultiInitializer.h - Initializer expression group ------*- C++ -*-===//
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
comment|// This file defines the MultiInitializer class, which can represent a list
end_comment

begin_comment
comment|// initializer or a parentheses-wrapped group of expressions in a C++ member
end_comment

begin_comment
comment|// initializer.
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
name|LLVM_CLANG_SEMA_MULTIINITIALIZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_MULTIINITIALIZER_H
end_define

begin_include
include|#
directive|include
file|"clang/Sema/Ownership.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|InitializationKind
decl_stmt|;
name|class
name|InitializedEntity
decl_stmt|;
name|class
name|InitListExpr
decl_stmt|;
name|class
name|Sema
decl_stmt|;
name|class
name|MultiInitializer
block|{
name|llvm
operator|::
name|PointerUnion
operator|<
name|Expr
operator|*
operator|,
name|Expr
operator|*
operator|*
operator|>
name|InitListOrExpressions
expr_stmt|;
name|unsigned
name|NumInitializers
decl_stmt|;
name|SourceLocation
name|LParenLoc
decl_stmt|;
name|SourceLocation
name|RParenLoc
decl_stmt|;
name|InitListExpr
operator|*
name|getInitList
argument_list|()
specifier|const
expr_stmt|;
name|Expr
operator|*
operator|*
name|getExpressions
argument_list|()
specifier|const
block|{
return|return
name|InitListOrExpressions
operator|.
name|get
operator|<
name|Expr
operator|*
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|public
label|:
name|MultiInitializer
argument_list|(
name|Expr
operator|*
name|InitList
argument_list|)
operator|:
name|InitListOrExpressions
argument_list|(
argument|InitList
argument_list|)
block|{}
name|MultiInitializer
argument_list|(
argument|SourceLocation LParenLoc
argument_list|,
argument|Expr **Exprs
argument_list|,
argument|unsigned NumInits
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
operator|:
name|InitListOrExpressions
argument_list|(
name|Exprs
argument_list|)
operator|,
name|NumInitializers
argument_list|(
name|NumInits
argument_list|)
operator|,
name|LParenLoc
argument_list|(
name|LParenLoc
argument_list|)
operator|,
name|RParenLoc
argument_list|(
argument|RParenLoc
argument_list|)
block|{}
name|bool
name|isInitializerList
argument_list|()
specifier|const
block|{
return|return
name|InitListOrExpressions
operator|.
name|is
operator|<
name|Expr
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|SourceLocation
name|getStartLoc
argument_list|()
specifier|const
expr_stmt|;
name|SourceLocation
name|getEndLoc
argument_list|()
specifier|const
expr_stmt|;
typedef|typedef
name|Expr
modifier|*
modifier|*
name|iterator
typedef|;
name|iterator
name|begin
argument_list|()
specifier|const
expr_stmt|;
name|iterator
name|end
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isTypeDependent
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|DiagnoseUnexpandedParameterPack
argument_list|(
name|Sema
operator|&
name|SemaRef
argument_list|)
decl|const
decl_stmt|;
comment|// Return the InitListExpr or create a ParenListExpr.
name|Expr
modifier|*
name|CreateInitExpr
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|,
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
name|ExprResult
name|PerformInit
argument_list|(
name|Sema
operator|&
name|SemaRef
argument_list|,
name|InitializedEntity
name|Entity
argument_list|,
name|InitializationKind
name|Kind
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

