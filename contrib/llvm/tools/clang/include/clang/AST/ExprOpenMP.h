begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ExprOpenMP.h - Classes for representing expressions ----*- C++ -*-===//
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
comment|//  This file defines the Expr interface and subclasses.
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
name|LLVM_CLANG_AST_EXPROPENMP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_EXPROPENMP_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief OpenMP 4.0 [2.4, Array Sections].
comment|/// To specify an array section in an OpenMP construct, array subscript
comment|/// expressions are extended with the following syntax:
comment|/// \code
comment|/// [ lower-bound : length ]
comment|/// [ lower-bound : ]
comment|/// [ : length ]
comment|/// [ : ]
comment|/// \endcode
comment|/// The array section must be a subset of the original array.
comment|/// Array sections are allowed on multidimensional arrays. Base language array
comment|/// subscript expressions can be used to specify length-one dimensions of
comment|/// multidimensional array sections.
comment|/// The lower-bound and length are integral type expressions. When evaluated
comment|/// they represent a set of integer values as follows:
comment|/// \code
comment|/// { lower-bound, lower-bound + 1, lower-bound + 2,... , lower-bound + length -
comment|/// 1 }
comment|/// \endcode
comment|/// The lower-bound and length must evaluate to non-negative integers.
comment|/// When the size of the array dimension is not known, the length must be
comment|/// specified explicitly.
comment|/// When the length is absent, it defaults to the size of the array dimension
comment|/// minus the lower-bound.
comment|/// When the lower-bound is absent it defaults to 0.
name|class
name|OMPArraySectionExpr
range|:
name|public
name|Expr
block|{   enum
block|{
name|BASE
block|,
name|LOWER_BOUND
block|,
name|LENGTH
block|,
name|END_EXPR
block|}
block|;
name|Stmt
operator|*
name|SubExprs
index|[
name|END_EXPR
index|]
block|;
name|SourceLocation
name|ColonLoc
block|;
name|SourceLocation
name|RBracketLoc
block|;
name|public
operator|:
name|OMPArraySectionExpr
argument_list|(
argument|Expr *Base
argument_list|,
argument|Expr *LowerBound
argument_list|,
argument|Expr *Length
argument_list|,
argument|QualType Type
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
argument_list|,
argument|SourceLocation ColonLoc
argument_list|,
argument|SourceLocation RBracketLoc
argument_list|)
operator|:
name|Expr
argument_list|(
name|OMPArraySectionExprClass
argument_list|,
name|Type
argument_list|,
name|VK
argument_list|,
name|OK
argument_list|,
name|Base
operator|->
name|isTypeDependent
argument_list|()
operator|||
operator|(
name|LowerBound
operator|&&
name|LowerBound
operator|->
name|isTypeDependent
argument_list|()
operator|)
operator|||
operator|(
name|Length
operator|&&
name|Length
operator|->
name|isTypeDependent
argument_list|()
operator|)
argument_list|,
name|Base
operator|->
name|isValueDependent
argument_list|()
operator|||
operator|(
name|LowerBound
operator|&&
name|LowerBound
operator|->
name|isValueDependent
argument_list|()
operator|)
operator|||
operator|(
name|Length
operator|&&
name|Length
operator|->
name|isValueDependent
argument_list|()
operator|)
argument_list|,
name|Base
operator|->
name|isInstantiationDependent
argument_list|()
operator|||
operator|(
name|LowerBound
operator|&&
name|LowerBound
operator|->
name|isInstantiationDependent
argument_list|()
operator|)
operator|||
operator|(
name|Length
operator|&&
name|Length
operator|->
name|isInstantiationDependent
argument_list|()
operator|)
argument_list|,
name|Base
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|||
operator|(
name|LowerBound
operator|&&
name|LowerBound
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|)
operator|||
operator|(
name|Length
operator|&&
name|Length
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|)
argument_list|)
block|,
name|ColonLoc
argument_list|(
name|ColonLoc
argument_list|)
block|,
name|RBracketLoc
argument_list|(
argument|RBracketLoc
argument_list|)
block|{
name|SubExprs
index|[
name|BASE
index|]
operator|=
name|Base
block|;
name|SubExprs
index|[
name|LOWER_BOUND
index|]
operator|=
name|LowerBound
block|;
name|SubExprs
index|[
name|LENGTH
index|]
operator|=
name|Length
block|;   }
comment|/// \brief Create an empty array section expression.
name|explicit
name|OMPArraySectionExpr
argument_list|(
argument|EmptyShell Shell
argument_list|)
operator|:
name|Expr
argument_list|(
argument|OMPArraySectionExprClass
argument_list|,
argument|Shell
argument_list|)
block|{}
comment|/// An array section can be written only as Base[LowerBound:Length].
comment|/// \brief Get base of the array section.
name|Expr
operator|*
name|getBase
argument_list|()
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|BASE
index|]
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getBase
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|BASE
index|]
operator|)
return|;
block|}
comment|/// \brief Set base of the array section.
name|void
name|setBase
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|SubExprs
index|[
name|BASE
index|]
operator|=
name|E
block|; }
comment|/// \brief Return original type of the base expression for array section.
specifier|static
name|QualType
name|getBaseOriginalType
argument_list|(
name|Expr
operator|*
name|Base
argument_list|)
block|;
comment|/// \brief Get lower bound of array section.
name|Expr
operator|*
name|getLowerBound
argument_list|()
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|LOWER_BOUND
index|]
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getLowerBound
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|LOWER_BOUND
index|]
operator|)
return|;
block|}
comment|/// \brief Set lower bound of the array section.
name|void
name|setLowerBound
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|SubExprs
index|[
name|LOWER_BOUND
index|]
operator|=
name|E
block|; }
comment|/// \brief Get length of array section.
name|Expr
operator|*
name|getLength
argument_list|()
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|LENGTH
index|]
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getLength
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|LENGTH
index|]
operator|)
return|;
block|}
comment|/// \brief Set length of the array section.
name|void
name|setLength
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|SubExprs
index|[
name|LENGTH
index|]
operator|=
name|E
block|; }
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|getBase
argument_list|()
operator|->
name|getLocStart
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|RBracketLoc
return|;
block|}
name|SourceLocation
name|getColonLoc
argument_list|()
specifier|const
block|{
return|return
name|ColonLoc
return|;
block|}
name|void
name|setColonLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|ColonLoc
operator|=
name|L
block|; }
name|SourceLocation
name|getRBracketLoc
argument_list|()
specifier|const
block|{
return|return
name|RBracketLoc
return|;
block|}
name|void
name|setRBracketLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|RBracketLoc
operator|=
name|L
block|; }
name|SourceLocation
name|getExprLoc
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|getBase
argument_list|()
operator|->
name|getExprLoc
argument_list|()
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPArraySectionExprClass
return|;
block|}
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
operator|&
name|SubExprs
index|[
name|BASE
index|]
argument_list|,
operator|&
name|SubExprs
index|[
name|END_EXPR
index|]
argument_list|)
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

