begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- SValVisitor.h - Visitor for SVal subclasses ------------*- C++ -*-===//
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
comment|//  This file defines the SValVisitor, SymExprVisitor, and MemRegionVisitor
end_comment

begin_comment
comment|//  interfaces, and also FullSValVisitor, which visits all three hierarchies.
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
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_SVALVISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_SVALVISITOR_H
end_define

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/SVals.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/SymbolManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/MemRegion.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
comment|/// SValVisitor - this class implements a simple visitor for SVal
comment|/// subclasses.
name|template
operator|<
name|typename
name|ImplClass
operator|,
name|typename
name|RetTy
operator|=
name|void
operator|>
name|class
name|SValVisitor
block|{
name|public
operator|:
define|#
directive|define
name|DISPATCH
parameter_list|(
name|NAME
parameter_list|,
name|CLASS
parameter_list|)
define|\
value|return static_cast<ImplClass *>(this)->Visit ## NAME(V.castAs<CLASS>())
name|RetTy
name|Visit
argument_list|(
argument|SVal V
argument_list|)
block|{
comment|// Dispatch to VisitFooVal for each FooVal.
comment|// Take namespaces (loc:: and nonloc::) into account.
switch|switch
condition|(
name|V
operator|.
name|getBaseKind
argument_list|()
condition|)
block|{
define|#
directive|define
name|BASIC_SVAL
parameter_list|(
name|Id
parameter_list|,
name|Parent
parameter_list|)
value|case SVal::Id ## Kind: DISPATCH(Id, Id);
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/SVals.def"
case|case
name|SVal
operator|::
name|LocKind
case|:
switch|switch
condition|(
name|V
operator|.
name|getSubKind
argument_list|()
condition|)
block|{
define|#
directive|define
name|LOC_SVAL
parameter_list|(
name|Id
parameter_list|,
name|Parent
parameter_list|)
define|\
value|case loc::Id ## Kind: DISPATCH(Loc ## Id, loc :: Id);
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/SVals.def"
block|}
name|llvm_unreachable
argument_list|(
literal|"Unknown Loc sub-kind!"
argument_list|)
expr_stmt|;
case|case
name|SVal
operator|::
name|NonLocKind
case|:
switch|switch
condition|(
name|V
operator|.
name|getSubKind
argument_list|()
condition|)
block|{
define|#
directive|define
name|NONLOC_SVAL
parameter_list|(
name|Id
parameter_list|,
name|Parent
parameter_list|)
define|\
value|case nonloc::Id ## Kind: DISPATCH(NonLoc ## Id, nonloc :: Id);
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/SVals.def"
block|}
name|llvm_unreachable
argument_list|(
literal|"Unknown NonLoc sub-kind!"
argument_list|)
expr_stmt|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Unknown SVal kind!"
argument_list|)
expr_stmt|;
block|}
define|#
directive|define
name|BASIC_SVAL
parameter_list|(
name|Id
parameter_list|,
name|Parent
parameter_list|)
define|\
value|RetTy Visit ## Id(Id V) { DISPATCH(Parent, Id); }
define|#
directive|define
name|ABSTRACT_SVAL
parameter_list|(
name|Id
parameter_list|,
name|Parent
parameter_list|)
define|\
value|BASIC_SVAL(Id, Parent)
define|#
directive|define
name|LOC_SVAL
parameter_list|(
name|Id
parameter_list|,
name|Parent
parameter_list|)
define|\
value|RetTy VisitLoc ## Id(loc::Id V) { DISPATCH(Parent, Parent); }
define|#
directive|define
name|NONLOC_SVAL
parameter_list|(
name|Id
parameter_list|,
name|Parent
parameter_list|)
define|\
value|RetTy VisitNonLoc ## Id(nonloc::Id V) { DISPATCH(Parent, Parent); }
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/SVals.def"
comment|// Base case, ignore it. :)
name|RetTy
name|VisitSVal
argument_list|(
argument|SVal V
argument_list|)
block|{
return|return
name|RetTy
argument_list|()
return|;
block|}
undef|#
directive|undef
name|DISPATCH
expr|}
block|;
comment|/// SymExprVisitor - this class implements a simple visitor for SymExpr
comment|/// subclasses.
name|template
operator|<
name|typename
name|ImplClass
block|,
name|typename
name|RetTy
operator|=
name|void
operator|>
name|class
name|SymExprVisitor
block|{
name|public
operator|:
define|#
directive|define
name|DISPATCH
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|return static_cast<ImplClass *>(this)->Visit ## CLASS(cast<CLASS>(S))
name|RetTy
name|Visit
argument_list|(
argument|SymbolRef S
argument_list|)
block|{
comment|// Dispatch to VisitSymbolFoo for each SymbolFoo.
switch|switch
condition|(
name|S
operator|->
name|getKind
argument_list|()
condition|)
block|{
define|#
directive|define
name|SYMBOL
parameter_list|(
name|Id
parameter_list|,
name|Parent
parameter_list|)
define|\
value|case SymExpr::Id ## Kind: DISPATCH(Id);
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/Symbols.def"
block|}
name|llvm_unreachable
argument_list|(
literal|"Unknown SymExpr kind!"
argument_list|)
expr_stmt|;
block|}
comment|// If the implementation chooses not to implement a certain visit method, fall
comment|// back on visiting the superclass.
define|#
directive|define
name|SYMBOL
parameter_list|(
name|Id
parameter_list|,
name|Parent
parameter_list|)
value|RetTy Visit ## Id(const Id *S) { DISPATCH(Parent); }
define|#
directive|define
name|ABSTRACT_SYMBOL
parameter_list|(
name|Id
parameter_list|,
name|Parent
parameter_list|)
value|SYMBOL(Id, Parent)
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/Symbols.def"
comment|// Base case, ignore it. :)
name|RetTy
name|VisitSymExpr
argument_list|(
argument|SymbolRef S
argument_list|)
block|{
return|return
name|RetTy
argument_list|()
return|;
block|}
undef|#
directive|undef
name|DISPATCH
expr|}
block|;
comment|/// MemRegionVisitor - this class implements a simple visitor for MemRegion
comment|/// subclasses.
name|template
operator|<
name|typename
name|ImplClass
block|,
name|typename
name|RetTy
operator|=
name|void
operator|>
name|class
name|MemRegionVisitor
block|{
name|public
operator|:
define|#
directive|define
name|DISPATCH
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|return static_cast<ImplClass *>(this)->Visit ## CLASS(cast<CLASS>(R))
name|RetTy
name|Visit
argument_list|(
argument|const MemRegion *R
argument_list|)
block|{
comment|// Dispatch to VisitFooRegion for each FooRegion.
switch|switch
condition|(
name|R
operator|->
name|getKind
argument_list|()
condition|)
block|{
define|#
directive|define
name|REGION
parameter_list|(
name|Id
parameter_list|,
name|Parent
parameter_list|)
value|case MemRegion::Id ## Kind: DISPATCH(Id);
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/Regions.def"
block|}
name|llvm_unreachable
argument_list|(
literal|"Unknown MemRegion kind!"
argument_list|)
expr_stmt|;
block|}
comment|// If the implementation chooses not to implement a certain visit method, fall
comment|// back on visiting the superclass.
define|#
directive|define
name|REGION
parameter_list|(
name|Id
parameter_list|,
name|Parent
parameter_list|)
define|\
value|RetTy Visit ## Id(const Id *R) { DISPATCH(Parent); }
define|#
directive|define
name|ABSTRACT_REGION
parameter_list|(
name|Id
parameter_list|,
name|Parent
parameter_list|)
define|\
value|REGION(Id, Parent)
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/Regions.def"
comment|// Base case, ignore it. :)
name|RetTy
name|VisitMemRegion
argument_list|(
argument|const MemRegion *R
argument_list|)
block|{
return|return
name|RetTy
argument_list|()
return|;
block|}
undef|#
directive|undef
name|DISPATCH
expr|}
block|;
comment|/// FullSValVisitor - a convenient mixed visitor for all three:
comment|/// SVal, SymExpr and MemRegion subclasses.
name|template
operator|<
name|typename
name|ImplClass
block|,
name|typename
name|RetTy
operator|=
name|void
operator|>
name|class
name|FullSValVisitor
operator|:
name|public
name|SValVisitor
operator|<
name|ImplClass
block|,
name|RetTy
operator|>
block|,
name|public
name|SymExprVisitor
operator|<
name|ImplClass
block|,
name|RetTy
operator|>
block|,
name|public
name|MemRegionVisitor
operator|<
name|ImplClass
block|,
name|RetTy
operator|>
block|{
name|public
operator|:
name|using
name|SValVisitor
operator|<
name|ImplClass
block|,
name|RetTy
operator|>
operator|::
name|Visit
block|;
name|using
name|SymExprVisitor
operator|<
name|ImplClass
block|,
name|RetTy
operator|>
operator|::
name|Visit
block|;
name|using
name|MemRegionVisitor
operator|<
name|ImplClass
block|,
name|RetTy
operator|>
operator|::
name|Visit
block|; }
block|;  }
comment|// end namespace ento
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

