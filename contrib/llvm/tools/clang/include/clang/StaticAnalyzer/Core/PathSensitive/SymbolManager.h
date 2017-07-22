begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== SymbolManager.h - Management of Symbolic Values ------------*- C++ -*--==//
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
comment|//  This file defines SymbolManager, a class that manages symbolic values
end_comment

begin_comment
comment|//  created for use by ExprEngine and related classes.
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
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_SYMBOLMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_SYMBOLMANAGER_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/AnalysisContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/MemRegion.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/StoreRef.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/SymExpr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|StackFrameContext
decl_stmt|;
name|namespace
name|ento
block|{
name|class
name|BasicValueFactory
decl_stmt|;
name|class
name|SubRegion
decl_stmt|;
name|class
name|TypedValueRegion
decl_stmt|;
name|class
name|VarRegion
decl_stmt|;
comment|///\brief A symbol representing the value stored at a MemRegion.
name|class
name|SymbolRegionValue
range|:
name|public
name|SymbolData
block|{
specifier|const
name|TypedValueRegion
operator|*
name|R
block|;
name|public
operator|:
name|SymbolRegionValue
argument_list|(
argument|SymbolID sym
argument_list|,
argument|const TypedValueRegion *r
argument_list|)
operator|:
name|SymbolData
argument_list|(
name|SymbolRegionValueKind
argument_list|,
name|sym
argument_list|)
block|,
name|R
argument_list|(
argument|r
argument_list|)
block|{
name|assert
argument_list|(
name|r
argument_list|)
block|;
name|assert
argument_list|(
name|isValidTypeForSymbol
argument_list|(
name|r
operator|->
name|getValueType
argument_list|()
argument_list|)
argument_list|)
block|;   }
specifier|const
name|TypedValueRegion
operator|*
name|getRegion
argument_list|()
specifier|const
block|{
return|return
name|R
return|;
block|}
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID& profile
argument_list|,
argument|const TypedValueRegion* R
argument_list|)
block|{
name|profile
operator|.
name|AddInteger
argument_list|(
operator|(
name|unsigned
operator|)
name|SymbolRegionValueKind
argument_list|)
block|;
name|profile
operator|.
name|AddPointer
argument_list|(
name|R
argument_list|)
block|;   }
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID& profile
argument_list|)
name|override
block|{
name|Profile
argument_list|(
name|profile
argument_list|,
name|R
argument_list|)
block|;   }
name|void
name|dumpToStream
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|MemRegion
operator|*
name|getOriginRegion
argument_list|()
specifier|const
name|override
block|{
return|return
name|getRegion
argument_list|()
return|;
block|}
name|QualType
name|getType
argument_list|()
specifier|const
name|override
block|;
comment|// Implement isa<T> support.
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SymExpr *SE
argument_list|)
block|{
return|return
name|SE
operator|->
name|getKind
argument_list|()
operator|==
name|SymbolRegionValueKind
return|;
block|}
expr|}
block|;
comment|/// A symbol representing the result of an expression in the case when we do
comment|/// not know anything about what the expression is.
name|class
name|SymbolConjured
operator|:
name|public
name|SymbolData
block|{
specifier|const
name|Stmt
operator|*
name|S
block|;
name|QualType
name|T
block|;
name|unsigned
name|Count
block|;
specifier|const
name|LocationContext
operator|*
name|LCtx
block|;
specifier|const
name|void
operator|*
name|SymbolTag
block|;
name|public
operator|:
name|SymbolConjured
argument_list|(
argument|SymbolID sym
argument_list|,
argument|const Stmt *s
argument_list|,
argument|const LocationContext *lctx
argument_list|,
argument|QualType t
argument_list|,
argument|unsigned count
argument_list|,
argument|const void *symbolTag
argument_list|)
operator|:
name|SymbolData
argument_list|(
name|SymbolConjuredKind
argument_list|,
name|sym
argument_list|)
block|,
name|S
argument_list|(
name|s
argument_list|)
block|,
name|T
argument_list|(
name|t
argument_list|)
block|,
name|Count
argument_list|(
name|count
argument_list|)
block|,
name|LCtx
argument_list|(
name|lctx
argument_list|)
block|,
name|SymbolTag
argument_list|(
argument|symbolTag
argument_list|)
block|{
comment|// FIXME: 's' might be a nullptr if we're conducting invalidation
comment|// that was caused by a destructor call on a temporary object,
comment|// which has no statement associated with it.
comment|// Due to this, we might be creating the same invalidation symbol for
comment|// two different invalidation passes (for two different temporaries).
name|assert
argument_list|(
name|lctx
argument_list|)
block|;
name|assert
argument_list|(
name|isValidTypeForSymbol
argument_list|(
name|t
argument_list|)
argument_list|)
block|;   }
specifier|const
name|Stmt
operator|*
name|getStmt
argument_list|()
specifier|const
block|{
return|return
name|S
return|;
block|}
name|unsigned
name|getCount
argument_list|()
specifier|const
block|{
return|return
name|Count
return|;
block|}
specifier|const
name|void
operator|*
name|getTag
argument_list|()
specifier|const
block|{
return|return
name|SymbolTag
return|;
block|}
name|QualType
name|getType
argument_list|()
specifier|const
name|override
block|;
name|void
name|dumpToStream
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID& profile
argument_list|,
argument|const Stmt *S
argument_list|,
argument|QualType T
argument_list|,
argument|unsigned Count
argument_list|,
argument|const LocationContext *LCtx
argument_list|,
argument|const void *SymbolTag
argument_list|)
block|{
name|profile
operator|.
name|AddInteger
argument_list|(
operator|(
name|unsigned
operator|)
name|SymbolConjuredKind
argument_list|)
block|;
name|profile
operator|.
name|AddPointer
argument_list|(
name|S
argument_list|)
block|;
name|profile
operator|.
name|AddPointer
argument_list|(
name|LCtx
argument_list|)
block|;
name|profile
operator|.
name|Add
argument_list|(
name|T
argument_list|)
block|;
name|profile
operator|.
name|AddInteger
argument_list|(
name|Count
argument_list|)
block|;
name|profile
operator|.
name|AddPointer
argument_list|(
name|SymbolTag
argument_list|)
block|;   }
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID& profile
argument_list|)
name|override
block|{
name|Profile
argument_list|(
name|profile
argument_list|,
name|S
argument_list|,
name|T
argument_list|,
name|Count
argument_list|,
name|LCtx
argument_list|,
name|SymbolTag
argument_list|)
block|;   }
comment|// Implement isa<T> support.
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SymExpr *SE
argument_list|)
block|{
return|return
name|SE
operator|->
name|getKind
argument_list|()
operator|==
name|SymbolConjuredKind
return|;
block|}
expr|}
block|;
comment|/// A symbol representing the value of a MemRegion whose parent region has
comment|/// symbolic value.
name|class
name|SymbolDerived
operator|:
name|public
name|SymbolData
block|{
name|SymbolRef
name|parentSymbol
block|;
specifier|const
name|TypedValueRegion
operator|*
name|R
block|;
name|public
operator|:
name|SymbolDerived
argument_list|(
argument|SymbolID sym
argument_list|,
argument|SymbolRef parent
argument_list|,
argument|const TypedValueRegion *r
argument_list|)
operator|:
name|SymbolData
argument_list|(
name|SymbolDerivedKind
argument_list|,
name|sym
argument_list|)
block|,
name|parentSymbol
argument_list|(
name|parent
argument_list|)
block|,
name|R
argument_list|(
argument|r
argument_list|)
block|{
name|assert
argument_list|(
name|parent
argument_list|)
block|;
name|assert
argument_list|(
name|r
argument_list|)
block|;
name|assert
argument_list|(
name|isValidTypeForSymbol
argument_list|(
name|r
operator|->
name|getValueType
argument_list|()
argument_list|)
argument_list|)
block|;   }
name|SymbolRef
name|getParentSymbol
argument_list|()
specifier|const
block|{
return|return
name|parentSymbol
return|;
block|}
specifier|const
name|TypedValueRegion
operator|*
name|getRegion
argument_list|()
specifier|const
block|{
return|return
name|R
return|;
block|}
name|QualType
name|getType
argument_list|()
specifier|const
name|override
block|;
name|void
name|dumpToStream
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|MemRegion
operator|*
name|getOriginRegion
argument_list|()
specifier|const
name|override
block|{
return|return
name|getRegion
argument_list|()
return|;
block|}
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID& profile
argument_list|,
argument|SymbolRef parent
argument_list|,
argument|const TypedValueRegion *r
argument_list|)
block|{
name|profile
operator|.
name|AddInteger
argument_list|(
operator|(
name|unsigned
operator|)
name|SymbolDerivedKind
argument_list|)
block|;
name|profile
operator|.
name|AddPointer
argument_list|(
name|r
argument_list|)
block|;
name|profile
operator|.
name|AddPointer
argument_list|(
name|parent
argument_list|)
block|;   }
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID& profile
argument_list|)
name|override
block|{
name|Profile
argument_list|(
name|profile
argument_list|,
name|parentSymbol
argument_list|,
name|R
argument_list|)
block|;   }
comment|// Implement isa<T> support.
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SymExpr *SE
argument_list|)
block|{
return|return
name|SE
operator|->
name|getKind
argument_list|()
operator|==
name|SymbolDerivedKind
return|;
block|}
expr|}
block|;
comment|/// SymbolExtent - Represents the extent (size in bytes) of a bounded region.
comment|///  Clients should not ask the SymbolManager for a region's extent. Always use
comment|///  SubRegion::getExtent instead -- the value returned may not be a symbol.
name|class
name|SymbolExtent
operator|:
name|public
name|SymbolData
block|{
specifier|const
name|SubRegion
operator|*
name|R
block|;
name|public
operator|:
name|SymbolExtent
argument_list|(
argument|SymbolID sym
argument_list|,
argument|const SubRegion *r
argument_list|)
operator|:
name|SymbolData
argument_list|(
name|SymbolExtentKind
argument_list|,
name|sym
argument_list|)
block|,
name|R
argument_list|(
argument|r
argument_list|)
block|{
name|assert
argument_list|(
name|r
argument_list|)
block|;   }
specifier|const
name|SubRegion
operator|*
name|getRegion
argument_list|()
specifier|const
block|{
return|return
name|R
return|;
block|}
name|QualType
name|getType
argument_list|()
specifier|const
name|override
block|;
name|void
name|dumpToStream
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID& profile
argument_list|,
argument|const SubRegion *R
argument_list|)
block|{
name|profile
operator|.
name|AddInteger
argument_list|(
operator|(
name|unsigned
operator|)
name|SymbolExtentKind
argument_list|)
block|;
name|profile
operator|.
name|AddPointer
argument_list|(
name|R
argument_list|)
block|;   }
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID& profile
argument_list|)
name|override
block|{
name|Profile
argument_list|(
name|profile
argument_list|,
name|R
argument_list|)
block|;   }
comment|// Implement isa<T> support.
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SymExpr *SE
argument_list|)
block|{
return|return
name|SE
operator|->
name|getKind
argument_list|()
operator|==
name|SymbolExtentKind
return|;
block|}
expr|}
block|;
comment|/// SymbolMetadata - Represents path-dependent metadata about a specific region.
comment|///  Metadata symbols remain live as long as they are marked as in use before
comment|///  dead-symbol sweeping AND their associated regions are still alive.
comment|///  Intended for use by checkers.
name|class
name|SymbolMetadata
operator|:
name|public
name|SymbolData
block|{
specifier|const
name|MemRegion
operator|*
name|R
block|;
specifier|const
name|Stmt
operator|*
name|S
block|;
name|QualType
name|T
block|;
specifier|const
name|LocationContext
operator|*
name|LCtx
block|;
name|unsigned
name|Count
block|;
specifier|const
name|void
operator|*
name|Tag
block|;
name|public
operator|:
name|SymbolMetadata
argument_list|(
argument|SymbolID sym
argument_list|,
argument|const MemRegion* r
argument_list|,
argument|const Stmt *s
argument_list|,
argument|QualType t
argument_list|,
argument|const LocationContext *LCtx
argument_list|,
argument|unsigned count
argument_list|,
argument|const void *tag
argument_list|)
operator|:
name|SymbolData
argument_list|(
name|SymbolMetadataKind
argument_list|,
name|sym
argument_list|)
block|,
name|R
argument_list|(
name|r
argument_list|)
block|,
name|S
argument_list|(
name|s
argument_list|)
block|,
name|T
argument_list|(
name|t
argument_list|)
block|,
name|LCtx
argument_list|(
name|LCtx
argument_list|)
block|,
name|Count
argument_list|(
name|count
argument_list|)
block|,
name|Tag
argument_list|(
argument|tag
argument_list|)
block|{
name|assert
argument_list|(
name|r
argument_list|)
block|;
name|assert
argument_list|(
name|s
argument_list|)
block|;
name|assert
argument_list|(
name|isValidTypeForSymbol
argument_list|(
name|t
argument_list|)
argument_list|)
block|;
name|assert
argument_list|(
name|LCtx
argument_list|)
block|;
name|assert
argument_list|(
name|tag
argument_list|)
block|;     }
specifier|const
name|MemRegion
operator|*
name|getRegion
argument_list|()
specifier|const
block|{
return|return
name|R
return|;
block|}
specifier|const
name|Stmt
operator|*
name|getStmt
argument_list|()
specifier|const
block|{
return|return
name|S
return|;
block|}
specifier|const
name|LocationContext
operator|*
name|getLocationContext
argument_list|()
specifier|const
block|{
return|return
name|LCtx
return|;
block|}
name|unsigned
name|getCount
argument_list|()
specifier|const
block|{
return|return
name|Count
return|;
block|}
specifier|const
name|void
operator|*
name|getTag
argument_list|()
specifier|const
block|{
return|return
name|Tag
return|;
block|}
name|QualType
name|getType
argument_list|()
specifier|const
name|override
block|;
name|void
name|dumpToStream
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID& profile
argument_list|,
argument|const MemRegion *R
argument_list|,
argument|const Stmt *S
argument_list|,
argument|QualType T
argument_list|,
argument|const LocationContext *LCtx
argument_list|,
argument|unsigned Count
argument_list|,
argument|const void *Tag
argument_list|)
block|{
name|profile
operator|.
name|AddInteger
argument_list|(
operator|(
name|unsigned
operator|)
name|SymbolMetadataKind
argument_list|)
block|;
name|profile
operator|.
name|AddPointer
argument_list|(
name|R
argument_list|)
block|;
name|profile
operator|.
name|AddPointer
argument_list|(
name|S
argument_list|)
block|;
name|profile
operator|.
name|Add
argument_list|(
name|T
argument_list|)
block|;
name|profile
operator|.
name|AddPointer
argument_list|(
name|LCtx
argument_list|)
block|;
name|profile
operator|.
name|AddInteger
argument_list|(
name|Count
argument_list|)
block|;
name|profile
operator|.
name|AddPointer
argument_list|(
name|Tag
argument_list|)
block|;   }
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID& profile
argument_list|)
name|override
block|{
name|Profile
argument_list|(
name|profile
argument_list|,
name|R
argument_list|,
name|S
argument_list|,
name|T
argument_list|,
name|LCtx
argument_list|,
name|Count
argument_list|,
name|Tag
argument_list|)
block|;   }
comment|// Implement isa<T> support.
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SymExpr *SE
argument_list|)
block|{
return|return
name|SE
operator|->
name|getKind
argument_list|()
operator|==
name|SymbolMetadataKind
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a cast expression.
name|class
name|SymbolCast
operator|:
name|public
name|SymExpr
block|{
specifier|const
name|SymExpr
operator|*
name|Operand
block|;
comment|/// Type of the operand.
name|QualType
name|FromTy
block|;
comment|/// The type of the result.
name|QualType
name|ToTy
block|;
name|public
operator|:
name|SymbolCast
argument_list|(
argument|const SymExpr *In
argument_list|,
argument|QualType From
argument_list|,
argument|QualType To
argument_list|)
operator|:
name|SymExpr
argument_list|(
name|SymbolCastKind
argument_list|)
block|,
name|Operand
argument_list|(
name|In
argument_list|)
block|,
name|FromTy
argument_list|(
name|From
argument_list|)
block|,
name|ToTy
argument_list|(
argument|To
argument_list|)
block|{
name|assert
argument_list|(
name|In
argument_list|)
block|;
name|assert
argument_list|(
name|isValidTypeForSymbol
argument_list|(
name|From
argument_list|)
argument_list|)
block|;
comment|// FIXME: GenericTaintChecker creates symbols of void type.
comment|// Otherwise, 'To' should also be a valid type.
block|}
name|QualType
name|getType
argument_list|()
specifier|const
name|override
block|{
return|return
name|ToTy
return|;
block|}
specifier|const
name|SymExpr
operator|*
name|getOperand
argument_list|()
specifier|const
block|{
return|return
name|Operand
return|;
block|}
name|void
name|dumpToStream
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID& ID
argument_list|,
argument|const SymExpr *In
argument_list|,
argument|QualType From
argument_list|,
argument|QualType To
argument_list|)
block|{
name|ID
operator|.
name|AddInteger
argument_list|(
operator|(
name|unsigned
operator|)
name|SymbolCastKind
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|In
argument_list|)
block|;
name|ID
operator|.
name|Add
argument_list|(
name|From
argument_list|)
block|;
name|ID
operator|.
name|Add
argument_list|(
name|To
argument_list|)
block|;   }
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID& ID
argument_list|)
name|override
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|Operand
argument_list|,
name|FromTy
argument_list|,
name|ToTy
argument_list|)
block|;   }
comment|// Implement isa<T> support.
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SymExpr *SE
argument_list|)
block|{
return|return
name|SE
operator|->
name|getKind
argument_list|()
operator|==
name|SymbolCastKind
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a symbolic expression involving a binary operator
name|class
name|BinarySymExpr
operator|:
name|public
name|SymExpr
block|{
name|BinaryOperator
operator|::
name|Opcode
name|Op
block|;
name|QualType
name|T
block|;
name|protected
operator|:
name|BinarySymExpr
argument_list|(
argument|Kind k
argument_list|,
argument|BinaryOperator::Opcode op
argument_list|,
argument|QualType t
argument_list|)
operator|:
name|SymExpr
argument_list|(
name|k
argument_list|)
block|,
name|Op
argument_list|(
name|op
argument_list|)
block|,
name|T
argument_list|(
argument|t
argument_list|)
block|{
name|assert
argument_list|(
name|classof
argument_list|(
name|this
argument_list|)
argument_list|)
block|;
name|assert
argument_list|(
name|isValidTypeForSymbol
argument_list|(
name|t
argument_list|)
argument_list|)
block|;   }
name|public
operator|:
comment|// FIXME: We probably need to make this out-of-line to avoid redundant
comment|// generation of virtual functions.
name|QualType
name|getType
argument_list|()
specifier|const
name|override
block|{
return|return
name|T
return|;
block|}
name|BinaryOperator
operator|::
name|Opcode
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|Op
return|;
block|}
comment|// Implement isa<T> support.
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SymExpr *SE
argument_list|)
block|{
name|Kind
name|k
operator|=
name|SE
operator|->
name|getKind
argument_list|()
block|;
return|return
name|k
operator|>=
name|BEGIN_BINARYSYMEXPRS
operator|&&
name|k
operator|<=
name|END_BINARYSYMEXPRS
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a symbolic expression like 'x' + 3.
name|class
name|SymIntExpr
operator|:
name|public
name|BinarySymExpr
block|{
specifier|const
name|SymExpr
operator|*
name|LHS
block|;
specifier|const
name|llvm
operator|::
name|APSInt
operator|&
name|RHS
block|;
name|public
operator|:
name|SymIntExpr
argument_list|(
argument|const SymExpr *lhs
argument_list|,
argument|BinaryOperator::Opcode op
argument_list|,
argument|const llvm::APSInt&rhs
argument_list|,
argument|QualType t
argument_list|)
operator|:
name|BinarySymExpr
argument_list|(
name|SymIntExprKind
argument_list|,
name|op
argument_list|,
name|t
argument_list|)
block|,
name|LHS
argument_list|(
name|lhs
argument_list|)
block|,
name|RHS
argument_list|(
argument|rhs
argument_list|)
block|{
name|assert
argument_list|(
name|lhs
argument_list|)
block|;   }
name|void
name|dumpToStream
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|SymExpr
operator|*
name|getLHS
argument_list|()
specifier|const
block|{
return|return
name|LHS
return|;
block|}
specifier|const
name|llvm
operator|::
name|APSInt
operator|&
name|getRHS
argument_list|()
specifier|const
block|{
return|return
name|RHS
return|;
block|}
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID& ID
argument_list|,
argument|const SymExpr *lhs
argument_list|,
argument|BinaryOperator::Opcode op
argument_list|,
argument|const llvm::APSInt& rhs
argument_list|,
argument|QualType t
argument_list|)
block|{
name|ID
operator|.
name|AddInteger
argument_list|(
operator|(
name|unsigned
operator|)
name|SymIntExprKind
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|lhs
argument_list|)
block|;
name|ID
operator|.
name|AddInteger
argument_list|(
name|op
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
operator|&
name|rhs
argument_list|)
block|;
name|ID
operator|.
name|Add
argument_list|(
name|t
argument_list|)
block|;   }
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID& ID
argument_list|)
name|override
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|LHS
argument_list|,
name|getOpcode
argument_list|()
argument_list|,
name|RHS
argument_list|,
name|getType
argument_list|()
argument_list|)
block|;   }
comment|// Implement isa<T> support.
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SymExpr *SE
argument_list|)
block|{
return|return
name|SE
operator|->
name|getKind
argument_list|()
operator|==
name|SymIntExprKind
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a symbolic expression like 3 - 'x'.
name|class
name|IntSymExpr
operator|:
name|public
name|BinarySymExpr
block|{
specifier|const
name|llvm
operator|::
name|APSInt
operator|&
name|LHS
block|;
specifier|const
name|SymExpr
operator|*
name|RHS
block|;
name|public
operator|:
name|IntSymExpr
argument_list|(
argument|const llvm::APSInt&lhs
argument_list|,
argument|BinaryOperator::Opcode op
argument_list|,
argument|const SymExpr *rhs
argument_list|,
argument|QualType t
argument_list|)
operator|:
name|BinarySymExpr
argument_list|(
name|IntSymExprKind
argument_list|,
name|op
argument_list|,
name|t
argument_list|)
block|,
name|LHS
argument_list|(
name|lhs
argument_list|)
block|,
name|RHS
argument_list|(
argument|rhs
argument_list|)
block|{
name|assert
argument_list|(
name|rhs
argument_list|)
block|;   }
name|void
name|dumpToStream
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|SymExpr
operator|*
name|getRHS
argument_list|()
specifier|const
block|{
return|return
name|RHS
return|;
block|}
specifier|const
name|llvm
operator|::
name|APSInt
operator|&
name|getLHS
argument_list|()
specifier|const
block|{
return|return
name|LHS
return|;
block|}
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID& ID
argument_list|,
argument|const llvm::APSInt& lhs
argument_list|,
argument|BinaryOperator::Opcode op
argument_list|,
argument|const SymExpr *rhs
argument_list|,
argument|QualType t
argument_list|)
block|{
name|ID
operator|.
name|AddInteger
argument_list|(
operator|(
name|unsigned
operator|)
name|IntSymExprKind
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
operator|&
name|lhs
argument_list|)
block|;
name|ID
operator|.
name|AddInteger
argument_list|(
name|op
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|rhs
argument_list|)
block|;
name|ID
operator|.
name|Add
argument_list|(
name|t
argument_list|)
block|;   }
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID& ID
argument_list|)
name|override
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|LHS
argument_list|,
name|getOpcode
argument_list|()
argument_list|,
name|RHS
argument_list|,
name|getType
argument_list|()
argument_list|)
block|;   }
comment|// Implement isa<T> support.
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SymExpr *SE
argument_list|)
block|{
return|return
name|SE
operator|->
name|getKind
argument_list|()
operator|==
name|IntSymExprKind
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a symbolic expression like 'x' + 'y'.
name|class
name|SymSymExpr
operator|:
name|public
name|BinarySymExpr
block|{
specifier|const
name|SymExpr
operator|*
name|LHS
block|;
specifier|const
name|SymExpr
operator|*
name|RHS
block|;
name|public
operator|:
name|SymSymExpr
argument_list|(
argument|const SymExpr *lhs
argument_list|,
argument|BinaryOperator::Opcode op
argument_list|,
argument|const SymExpr *rhs
argument_list|,
argument|QualType t
argument_list|)
operator|:
name|BinarySymExpr
argument_list|(
name|SymSymExprKind
argument_list|,
name|op
argument_list|,
name|t
argument_list|)
block|,
name|LHS
argument_list|(
name|lhs
argument_list|)
block|,
name|RHS
argument_list|(
argument|rhs
argument_list|)
block|{
name|assert
argument_list|(
name|lhs
argument_list|)
block|;
name|assert
argument_list|(
name|rhs
argument_list|)
block|;   }
specifier|const
name|SymExpr
operator|*
name|getLHS
argument_list|()
specifier|const
block|{
return|return
name|LHS
return|;
block|}
specifier|const
name|SymExpr
operator|*
name|getRHS
argument_list|()
specifier|const
block|{
return|return
name|RHS
return|;
block|}
name|void
name|dumpToStream
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID& ID
argument_list|,
argument|const SymExpr *lhs
argument_list|,
argument|BinaryOperator::Opcode op
argument_list|,
argument|const SymExpr *rhs
argument_list|,
argument|QualType t
argument_list|)
block|{
name|ID
operator|.
name|AddInteger
argument_list|(
operator|(
name|unsigned
operator|)
name|SymSymExprKind
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|lhs
argument_list|)
block|;
name|ID
operator|.
name|AddInteger
argument_list|(
name|op
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|rhs
argument_list|)
block|;
name|ID
operator|.
name|Add
argument_list|(
name|t
argument_list|)
block|;   }
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID& ID
argument_list|)
name|override
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|LHS
argument_list|,
name|getOpcode
argument_list|()
argument_list|,
name|RHS
argument_list|,
name|getType
argument_list|()
argument_list|)
block|;   }
comment|// Implement isa<T> support.
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SymExpr *SE
argument_list|)
block|{
return|return
name|SE
operator|->
name|getKind
argument_list|()
operator|==
name|SymSymExprKind
return|;
block|}
expr|}
block|;
name|class
name|SymbolManager
block|{
typedef|typedef
name|llvm
operator|::
name|FoldingSet
operator|<
name|SymExpr
operator|>
name|DataSetTy
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|SymbolRef
operator|,
name|SymbolRefSmallVectorTy
operator|*
operator|>
name|SymbolDependTy
expr_stmt|;
name|DataSetTy
name|DataSet
block|;
comment|/// Stores the extra dependencies between symbols: the data should be kept
comment|/// alive as long as the key is live.
name|SymbolDependTy
name|SymbolDependencies
block|;
name|unsigned
name|SymbolCounter
block|;
name|llvm
operator|::
name|BumpPtrAllocator
operator|&
name|BPAlloc
block|;
name|BasicValueFactory
operator|&
name|BV
block|;
name|ASTContext
operator|&
name|Ctx
block|;
name|public
operator|:
name|SymbolManager
argument_list|(
name|ASTContext
operator|&
name|ctx
argument_list|,
name|BasicValueFactory
operator|&
name|bv
argument_list|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|&
name|bpalloc
argument_list|)
operator|:
name|SymbolDependencies
argument_list|(
literal|16
argument_list|)
block|,
name|SymbolCounter
argument_list|(
literal|0
argument_list|)
block|,
name|BPAlloc
argument_list|(
name|bpalloc
argument_list|)
block|,
name|BV
argument_list|(
name|bv
argument_list|)
block|,
name|Ctx
argument_list|(
argument|ctx
argument_list|)
block|{}
operator|~
name|SymbolManager
argument_list|()
block|;
specifier|static
name|bool
name|canSymbolicate
argument_list|(
argument|QualType T
argument_list|)
block|;
comment|/// \brief Make a unique symbol for MemRegion R according to its kind.
specifier|const
name|SymbolRegionValue
operator|*
name|getRegionValueSymbol
argument_list|(
specifier|const
name|TypedValueRegion
operator|*
name|R
argument_list|)
block|;
specifier|const
name|SymbolConjured
operator|*
name|conjureSymbol
argument_list|(
argument|const Stmt *E
argument_list|,
argument|const LocationContext *LCtx
argument_list|,
argument|QualType T
argument_list|,
argument|unsigned VisitCount
argument_list|,
argument|const void *SymbolTag = nullptr
argument_list|)
block|;
specifier|const
name|SymbolConjured
operator|*
name|conjureSymbol
argument_list|(
argument|const Expr *E
argument_list|,
argument|const LocationContext *LCtx
argument_list|,
argument|unsigned VisitCount
argument_list|,
argument|const void *SymbolTag = nullptr
argument_list|)
block|{
return|return
name|conjureSymbol
argument_list|(
name|E
argument_list|,
name|LCtx
argument_list|,
name|E
operator|->
name|getType
argument_list|()
argument_list|,
name|VisitCount
argument_list|,
name|SymbolTag
argument_list|)
return|;
block|}
specifier|const
name|SymbolDerived
operator|*
name|getDerivedSymbol
argument_list|(
argument|SymbolRef parentSymbol
argument_list|,
argument|const TypedValueRegion *R
argument_list|)
block|;
specifier|const
name|SymbolExtent
operator|*
name|getExtentSymbol
argument_list|(
specifier|const
name|SubRegion
operator|*
name|R
argument_list|)
block|;
comment|/// \brief Creates a metadata symbol associated with a specific region.
comment|///
comment|/// VisitCount can be used to differentiate regions corresponding to
comment|/// different loop iterations, thus, making the symbol path-dependent.
specifier|const
name|SymbolMetadata
operator|*
name|getMetadataSymbol
argument_list|(
argument|const MemRegion *R
argument_list|,
argument|const Stmt *S
argument_list|,
argument|QualType T
argument_list|,
argument|const LocationContext *LCtx
argument_list|,
argument|unsigned VisitCount
argument_list|,
argument|const void *SymbolTag = nullptr
argument_list|)
block|;
specifier|const
name|SymbolCast
operator|*
name|getCastSymbol
argument_list|(
argument|const SymExpr *Operand
argument_list|,
argument|QualType From
argument_list|,
argument|QualType To
argument_list|)
block|;
specifier|const
name|SymIntExpr
operator|*
name|getSymIntExpr
argument_list|(
argument|const SymExpr *lhs
argument_list|,
argument|BinaryOperator::Opcode op
argument_list|,
argument|const llvm::APSInt& rhs
argument_list|,
argument|QualType t
argument_list|)
block|;
specifier|const
name|SymIntExpr
operator|*
name|getSymIntExpr
argument_list|(
argument|const SymExpr&lhs
argument_list|,
argument|BinaryOperator::Opcode op
argument_list|,
argument|const llvm::APSInt& rhs
argument_list|,
argument|QualType t
argument_list|)
block|{
return|return
name|getSymIntExpr
argument_list|(
operator|&
name|lhs
argument_list|,
name|op
argument_list|,
name|rhs
argument_list|,
name|t
argument_list|)
return|;
block|}
specifier|const
name|IntSymExpr
operator|*
name|getIntSymExpr
argument_list|(
argument|const llvm::APSInt& lhs
argument_list|,
argument|BinaryOperator::Opcode op
argument_list|,
argument|const SymExpr *rhs
argument_list|,
argument|QualType t
argument_list|)
block|;
specifier|const
name|SymSymExpr
operator|*
name|getSymSymExpr
argument_list|(
argument|const SymExpr *lhs
argument_list|,
argument|BinaryOperator::Opcode op
argument_list|,
argument|const SymExpr *rhs
argument_list|,
argument|QualType t
argument_list|)
block|;
name|QualType
name|getType
argument_list|(
argument|const SymExpr *SE
argument_list|)
specifier|const
block|{
return|return
name|SE
operator|->
name|getType
argument_list|()
return|;
block|}
comment|/// \brief Add artificial symbol dependency.
comment|///
comment|/// The dependent symbol should stay alive as long as the primary is alive.
name|void
name|addSymbolDependency
argument_list|(
argument|const SymbolRef Primary
argument_list|,
argument|const SymbolRef Dependent
argument_list|)
block|;
specifier|const
name|SymbolRefSmallVectorTy
operator|*
name|getDependentSymbols
argument_list|(
argument|const SymbolRef Primary
argument_list|)
block|;
name|ASTContext
operator|&
name|getContext
argument_list|()
block|{
return|return
name|Ctx
return|;
block|}
name|BasicValueFactory
operator|&
name|getBasicVals
argument_list|()
block|{
return|return
name|BV
return|;
block|}
expr|}
block|;
comment|/// \brief A class responsible for cleaning up unused symbols.
name|class
name|SymbolReaper
block|{   enum
name|SymbolStatus
block|{
name|NotProcessed
block|,
name|HaveMarkedDependents
block|}
block|;
typedef|typedef
name|llvm
operator|::
name|DenseSet
operator|<
name|SymbolRef
operator|>
name|SymbolSetTy
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|SymbolRef
operator|,
name|SymbolStatus
operator|>
name|SymbolMapTy
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseSet
operator|<
specifier|const
name|MemRegion
operator|*
operator|>
name|RegionSetTy
expr_stmt|;
name|SymbolMapTy
name|TheLiving
block|;
name|SymbolSetTy
name|MetadataInUse
block|;
name|SymbolSetTy
name|TheDead
block|;
name|RegionSetTy
name|RegionRoots
block|;
specifier|const
name|StackFrameContext
operator|*
name|LCtx
block|;
specifier|const
name|Stmt
operator|*
name|Loc
block|;
name|SymbolManager
operator|&
name|SymMgr
block|;
name|StoreRef
name|reapedStore
block|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|MemRegion
operator|*
block|,
name|unsigned
operator|>
name|includedRegionCache
block|;
name|public
operator|:
comment|/// \brief Construct a reaper object, which removes everything which is not
comment|/// live before we execute statement s in the given location context.
comment|///
comment|/// If the statement is NULL, everything is this and parent contexts is
comment|/// considered live.
comment|/// If the stack frame context is NULL, everything on stack is considered
comment|/// dead.
name|SymbolReaper
argument_list|(
specifier|const
name|StackFrameContext
operator|*
name|Ctx
argument_list|,
specifier|const
name|Stmt
operator|*
name|s
argument_list|,
name|SymbolManager
operator|&
name|symmgr
argument_list|,
name|StoreManager
operator|&
name|storeMgr
argument_list|)
operator|:
name|LCtx
argument_list|(
name|Ctx
argument_list|)
block|,
name|Loc
argument_list|(
name|s
argument_list|)
block|,
name|SymMgr
argument_list|(
name|symmgr
argument_list|)
block|,
name|reapedStore
argument_list|(
argument|nullptr
argument_list|,
argument|storeMgr
argument_list|)
block|{}
specifier|const
name|LocationContext
operator|*
name|getLocationContext
argument_list|()
specifier|const
block|{
return|return
name|LCtx
return|;
block|}
name|bool
name|isLive
argument_list|(
argument|SymbolRef sym
argument_list|)
block|;
name|bool
name|isLiveRegion
argument_list|(
specifier|const
name|MemRegion
operator|*
name|region
argument_list|)
block|;
name|bool
name|isLive
argument_list|(
argument|const Stmt *ExprVal
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
specifier|const
block|;
name|bool
name|isLive
argument_list|(
argument|const VarRegion *VR
argument_list|,
argument|bool includeStoreBindings = false
argument_list|)
specifier|const
block|;
comment|/// \brief Unconditionally marks a symbol as live.
comment|///
comment|/// This should never be
comment|/// used by checkers, only by the state infrastructure such as the store and
comment|/// environment. Checkers should instead use metadata symbols and markInUse.
name|void
name|markLive
argument_list|(
argument|SymbolRef sym
argument_list|)
block|;
comment|/// \brief Marks a symbol as important to a checker.
comment|///
comment|/// For metadata symbols,
comment|/// this will keep the symbol alive as long as its associated region is also
comment|/// live. For other symbols, this has no effect; checkers are not permitted
comment|/// to influence the life of other symbols. This should be used before any
comment|/// symbol marking has occurred, i.e. in the MarkLiveSymbols callback.
name|void
name|markInUse
argument_list|(
argument|SymbolRef sym
argument_list|)
block|;
comment|/// \brief If a symbol is known to be live, marks the symbol as live.
comment|///
comment|///  Otherwise, if the symbol cannot be proven live, it is marked as dead.
comment|///  Returns true if the symbol is dead, false if live.
name|bool
name|maybeDead
argument_list|(
argument|SymbolRef sym
argument_list|)
block|;
typedef|typedef
name|SymbolSetTy
operator|::
name|const_iterator
name|dead_iterator
expr_stmt|;
name|dead_iterator
name|dead_begin
argument_list|()
specifier|const
block|{
return|return
name|TheDead
operator|.
name|begin
argument_list|()
return|;
block|}
name|dead_iterator
name|dead_end
argument_list|()
specifier|const
block|{
return|return
name|TheDead
operator|.
name|end
argument_list|()
return|;
block|}
name|bool
name|hasDeadSymbols
argument_list|()
specifier|const
block|{
return|return
operator|!
name|TheDead
operator|.
name|empty
argument_list|()
return|;
block|}
typedef|typedef
name|RegionSetTy
operator|::
name|const_iterator
name|region_iterator
expr_stmt|;
name|region_iterator
name|region_begin
argument_list|()
specifier|const
block|{
return|return
name|RegionRoots
operator|.
name|begin
argument_list|()
return|;
block|}
name|region_iterator
name|region_end
argument_list|()
specifier|const
block|{
return|return
name|RegionRoots
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// \brief Returns whether or not a symbol has been confirmed dead.
comment|///
comment|/// This should only be called once all marking of dead symbols has completed.
comment|/// (For checkers, this means only in the evalDeadSymbols callback.)
name|bool
name|isDead
argument_list|(
argument|SymbolRef sym
argument_list|)
specifier|const
block|{
return|return
name|TheDead
operator|.
name|count
argument_list|(
name|sym
argument_list|)
return|;
block|}
name|void
name|markLive
argument_list|(
specifier|const
name|MemRegion
operator|*
name|region
argument_list|)
block|;
name|void
name|markElementIndicesLive
argument_list|(
specifier|const
name|MemRegion
operator|*
name|region
argument_list|)
block|;
comment|/// \brief Set to the value of the symbolic store after
comment|/// StoreManager::removeDeadBindings has been called.
name|void
name|setReapedStore
argument_list|(
argument|StoreRef st
argument_list|)
block|{
name|reapedStore
operator|=
name|st
block|; }
name|private
operator|:
comment|/// Mark the symbols dependent on the input symbol as live.
name|void
name|markDependentsLive
argument_list|(
argument|SymbolRef sym
argument_list|)
block|; }
block|;
name|class
name|SymbolVisitor
block|{
name|protected
operator|:
operator|~
name|SymbolVisitor
argument_list|()
operator|=
expr|default
block|;
name|public
operator|:
name|SymbolVisitor
argument_list|()
operator|=
expr|default
block|;
name|SymbolVisitor
argument_list|(
specifier|const
name|SymbolVisitor
operator|&
argument_list|)
operator|=
expr|default
block|;
name|SymbolVisitor
argument_list|(
argument|SymbolVisitor&&
argument_list|)
block|{}
comment|/// \brief A visitor method invoked by ProgramStateManager::scanReachableSymbols.
comment|///
comment|/// The method returns \c true if symbols should continue be scanned and \c
comment|/// false otherwise.
name|virtual
name|bool
name|VisitSymbol
argument_list|(
argument|SymbolRef sym
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|VisitMemRegion
argument_list|(
argument|const MemRegion *region
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;  }
comment|// end GR namespace
block|}
comment|// end clang namespace
name|namespace
name|llvm
block|{
specifier|static
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|os
expr|,
specifier|const
name|clang
operator|::
name|ento
operator|::
name|SymExpr
operator|*
name|SE
operator|)
block|{
name|SE
operator|->
name|dumpToStream
argument_list|(
name|os
argument_list|)
block|;
return|return
name|os
return|;
block|}
expr|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

