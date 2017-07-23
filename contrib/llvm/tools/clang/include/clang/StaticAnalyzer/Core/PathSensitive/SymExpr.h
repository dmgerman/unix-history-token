begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== SymExpr.h - Management of Symbolic Values ------------------*- C++ -*--==//
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
comment|//  This file defines SymExpr and SymbolData.
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
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_SYMEXPR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_SYMEXPR_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
name|class
name|MemRegion
decl_stmt|;
comment|/// \brief Symbolic value. These values used to capture symbolic execution of
comment|/// the program.
name|class
name|SymExpr
range|:
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
expr|enum
name|Kind
block|{
define|#
directive|define
name|SYMBOL
parameter_list|(
name|Id
parameter_list|,
name|Parent
parameter_list|)
value|Id##Kind,
define|#
directive|define
name|SYMBOL_RANGE
parameter_list|(
name|Id
parameter_list|,
name|First
parameter_list|,
name|Last
parameter_list|)
value|BEGIN_##Id = First, END_##Id = Last,
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/Symbols.def"
block|}
block|;
name|private
operator|:
name|Kind
name|K
block|;
name|protected
operator|:
name|SymExpr
argument_list|(
argument|Kind k
argument_list|)
operator|:
name|K
argument_list|(
argument|k
argument_list|)
block|{}
specifier|static
name|bool
name|isValidTypeForSymbol
argument_list|(
argument|QualType T
argument_list|)
block|{
comment|// FIXME: Depending on whether we choose to deprecate structural symbols,
comment|// this may become much stricter.
return|return
operator|!
name|T
operator|.
name|isNull
argument_list|()
operator|&&
operator|!
name|T
operator|->
name|isVoidType
argument_list|()
return|;
block|}
name|public
operator|:
name|virtual
operator|~
name|SymExpr
argument_list|()
block|{}
name|Kind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|K
return|;
block|}
name|virtual
name|void
name|dump
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|dumpToStream
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
block|{}
name|virtual
name|QualType
name|getType
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|profile
argument_list|)
operator|=
literal|0
block|;
comment|/// \brief Iterator over symbols that the current symbol depends on.
comment|///
comment|/// For SymbolData, it's the symbol itself; for expressions, it's the
comment|/// expression symbol and all the operands in it. Note, SymbolDerived is
comment|/// treated as SymbolData - the iterator will NOT visit the parent region.
name|class
name|symbol_iterator
block|{
name|SmallVector
operator|<
specifier|const
name|SymExpr
operator|*
block|,
literal|5
operator|>
name|itr
block|;
name|void
name|expand
argument_list|()
block|;
name|public
operator|:
name|symbol_iterator
argument_list|()
block|{}
name|symbol_iterator
argument_list|(
specifier|const
name|SymExpr
operator|*
name|SE
argument_list|)
block|;
name|symbol_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|;
specifier|const
name|SymExpr
operator|*
name|operator
operator|*
operator|(
operator|)
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|symbol_iterator
operator|&
name|X
operator|)
specifier|const
block|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|symbol_iterator
operator|&
name|X
operator|)
specifier|const
block|;   }
block|;
name|symbol_iterator
name|symbol_begin
argument_list|()
specifier|const
block|{
return|return
name|symbol_iterator
argument_list|(
name|this
argument_list|)
return|;
block|}
specifier|static
name|symbol_iterator
name|symbol_end
argument_list|()
block|{
return|return
name|symbol_iterator
argument_list|()
return|;
block|}
name|unsigned
name|computeComplexity
argument_list|()
specifier|const
block|;
comment|/// \brief Find the region from which this symbol originates.
comment|///
comment|/// Whenever the symbol was constructed to denote an unknown value of
comment|/// a certain memory region, return this region. This method
comment|/// allows checkers to make decisions depending on the origin of the symbol.
comment|/// Symbol classes for which the origin region is known include
comment|/// SymbolRegionValue which denotes the value of the region before
comment|/// the beginning of the analysis, and SymbolDerived which denotes the value
comment|/// of a certain memory region after its super region (a memory space or
comment|/// a larger record region) is default-bound with a certain symbol.
name|virtual
specifier|const
name|MemRegion
operator|*
name|getOriginRegion
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
expr|}
block|;
typedef|typedef
specifier|const
name|SymExpr
modifier|*
name|SymbolRef
typedef|;
typedef|typedef
name|SmallVector
operator|<
name|SymbolRef
operator|,
literal|2
operator|>
name|SymbolRefSmallVectorTy
expr_stmt|;
typedef|typedef
name|unsigned
name|SymbolID
typedef|;
comment|/// \brief A symbol representing data which can be stored in a memory location
comment|/// (region).
name|class
name|SymbolData
range|:
name|public
name|SymExpr
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
specifier|const
name|SymbolID
name|Sym
block|;
name|protected
operator|:
name|SymbolData
argument_list|(
argument|Kind k
argument_list|,
argument|SymbolID sym
argument_list|)
operator|:
name|SymExpr
argument_list|(
name|k
argument_list|)
block|,
name|Sym
argument_list|(
argument|sym
argument_list|)
block|{
name|assert
argument_list|(
name|classof
argument_list|(
name|this
argument_list|)
argument_list|)
block|;   }
name|public
operator|:
operator|~
name|SymbolData
argument_list|()
name|override
block|{}
name|SymbolID
name|getSymbolID
argument_list|()
specifier|const
block|{
return|return
name|Sym
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
name|BEGIN_SYMBOLS
operator|&&
name|k
operator|<=
name|END_SYMBOLS
return|;
block|}
expr|}
block|;  }
comment|// namespace ento
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

