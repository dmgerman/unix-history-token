begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---  BugReporterVisitor.h - Generate PathDiagnostics -------*- C++ -*-===//
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
comment|//  This file declares BugReporterVisitors, which are used to generate enhanced
end_comment

begin_comment
comment|//  diagnostic traces.
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
name|LLVM_CLANG_GR_BUGREPORTERVISITOR
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_GR_BUGREPORTERVISITOR
end_define

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/SVals.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
name|class
name|BugReport
decl_stmt|;
name|class
name|BugReporterContext
decl_stmt|;
name|class
name|ExplodedNode
decl_stmt|;
name|class
name|MemRegion
decl_stmt|;
name|class
name|PathDiagnosticPiece
decl_stmt|;
comment|/// \brief BugReporterVisitors are used to add custom diagnostics along a path.
comment|///
comment|/// Custom visitors should subclass the BugReporterVisitorImpl class for a
comment|/// default implementation of the clone() method.
comment|/// (Warning: if you have a deep subclass of BugReporterVisitorImpl, the
comment|/// default implementation of clone() will NOT do the right thing, and you
comment|/// will have to provide your own implementation.)
name|class
name|BugReporterVisitor
range|:
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|public
operator|:
name|virtual
operator|~
name|BugReporterVisitor
argument_list|()
block|;
comment|/// \brief Returns a copy of this BugReporter.
comment|///
comment|/// Custom BugReporterVisitors should not override this method directly.
comment|/// Instead, they should inherit from BugReporterVisitorImpl and provide
comment|/// a protected or public copy constructor.
comment|///
comment|/// (Warning: if you have a deep subclass of BugReporterVisitorImpl, the
comment|/// default implementation of clone() will NOT do the right thing, and you
comment|/// will have to provide your own implementation.)
name|virtual
name|BugReporterVisitor
operator|*
name|clone
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// \brief Return a diagnostic piece which should be associated with the
comment|/// given node.
comment|///
comment|/// The last parameter can be used to register a new visitor with the given
comment|/// BugReport while processing a node.
name|virtual
name|PathDiagnosticPiece
operator|*
name|VisitNode
argument_list|(
specifier|const
name|ExplodedNode
operator|*
name|N
argument_list|,
specifier|const
name|ExplodedNode
operator|*
name|PrevN
argument_list|,
name|BugReporterContext
operator|&
name|BRC
argument_list|,
name|BugReport
operator|&
name|BR
argument_list|)
operator|=
literal|0
block|;
comment|/// \brief Provide custom definition for the final diagnostic piece on the
comment|/// path - the piece, which is displayed before the path is expanded.
comment|///
comment|/// If returns NULL the default implementation will be used.
comment|/// Also note that at most one visitor of a BugReport should generate a
comment|/// non-NULL end of path diagnostic piece.
name|virtual
name|PathDiagnosticPiece
operator|*
name|getEndPath
argument_list|(
name|BugReporterContext
operator|&
name|BRC
argument_list|,
specifier|const
name|ExplodedNode
operator|*
name|N
argument_list|,
name|BugReport
operator|&
name|BR
argument_list|)
block|;
name|virtual
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// \brief Generates the default final diagnostic piece.
specifier|static
name|PathDiagnosticPiece
operator|*
name|getDefaultEndPath
argument_list|(
name|BugReporterContext
operator|&
name|BRC
argument_list|,
specifier|const
name|ExplodedNode
operator|*
name|N
argument_list|,
name|BugReport
operator|&
name|BR
argument_list|)
block|;  }
decl_stmt|;
comment|/// This class provides a convenience implementation for clone() using the
comment|/// Curiously-Recurring Template Pattern. If you are implementing a custom
comment|/// BugReporterVisitor, subclass BugReporterVisitorImpl and provide a public
comment|/// or protected copy constructor.
comment|///
comment|/// (Warning: if you have a deep subclass of BugReporterVisitorImpl, the
comment|/// default implementation of clone() will NOT do the right thing, and you
comment|/// will have to provide your own implementation.)
name|template
operator|<
name|class
name|DERIVED
operator|>
name|class
name|BugReporterVisitorImpl
operator|:
name|public
name|BugReporterVisitor
block|{
name|virtual
name|BugReporterVisitor
operator|*
name|clone
argument_list|()
specifier|const
block|{
return|return
name|new
name|DERIVED
argument_list|(
operator|*
name|static_cast
operator|<
specifier|const
name|DERIVED
operator|*
operator|>
operator|(
name|this
operator|)
argument_list|)
return|;
block|}
expr|}
block|;
name|class
name|FindLastStoreBRVisitor
operator|:
name|public
name|BugReporterVisitorImpl
operator|<
name|FindLastStoreBRVisitor
operator|>
block|{
specifier|const
name|MemRegion
operator|*
name|R
block|;
name|SVal
name|V
block|;
name|bool
name|satisfied
block|;
specifier|const
name|ExplodedNode
operator|*
name|StoreSite
block|;
name|public
operator|:
comment|/// \brief Convenience method to create a visitor given only the MemRegion.
comment|/// Returns NULL if the visitor cannot be created. For example, when the
comment|/// corresponding value is unknown.
specifier|static
name|BugReporterVisitor
operator|*
name|createVisitorObject
argument_list|(
specifier|const
name|ExplodedNode
operator|*
name|N
argument_list|,
specifier|const
name|MemRegion
operator|*
name|R
argument_list|)
block|;
comment|/// Creates a visitor for every VarDecl inside a Stmt and registers it with
comment|/// the BugReport.
specifier|static
name|void
name|registerStatementVarDecls
argument_list|(
name|BugReport
operator|&
name|BR
argument_list|,
specifier|const
name|Stmt
operator|*
name|S
argument_list|)
block|;
name|FindLastStoreBRVisitor
argument_list|(
argument|SVal v
argument_list|,
argument|const MemRegion *r
argument_list|)
operator|:
name|R
argument_list|(
name|r
argument_list|)
block|,
name|V
argument_list|(
name|v
argument_list|)
block|,
name|satisfied
argument_list|(
name|false
argument_list|)
block|,
name|StoreSite
argument_list|(
literal|0
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|V
operator|.
name|isUnknown
argument_list|()
operator|&&
literal|"Cannot track unknown value."
argument_list|)
block|;
comment|// TODO: Does it make sense to allow undef values here?
comment|// (If not, also see UndefCapturedBlockVarChecker)?
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
specifier|const
block|;
name|PathDiagnosticPiece
operator|*
name|VisitNode
argument_list|(
specifier|const
name|ExplodedNode
operator|*
name|N
argument_list|,
specifier|const
name|ExplodedNode
operator|*
name|PrevN
argument_list|,
name|BugReporterContext
operator|&
name|BRC
argument_list|,
name|BugReport
operator|&
name|BR
argument_list|)
block|; }
block|;
name|class
name|TrackConstraintBRVisitor
operator|:
name|public
name|BugReporterVisitorImpl
operator|<
name|TrackConstraintBRVisitor
operator|>
block|{
name|DefinedSVal
name|Constraint
block|;
specifier|const
name|bool
name|Assumption
block|;
name|bool
name|isSatisfied
block|;
name|public
operator|:
name|TrackConstraintBRVisitor
argument_list|(
argument|DefinedSVal constraint
argument_list|,
argument|bool assumption
argument_list|)
operator|:
name|Constraint
argument_list|(
name|constraint
argument_list|)
block|,
name|Assumption
argument_list|(
name|assumption
argument_list|)
block|,
name|isSatisfied
argument_list|(
argument|false
argument_list|)
block|{}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
specifier|const
block|;
name|PathDiagnosticPiece
operator|*
name|VisitNode
argument_list|(
specifier|const
name|ExplodedNode
operator|*
name|N
argument_list|,
specifier|const
name|ExplodedNode
operator|*
name|PrevN
argument_list|,
name|BugReporterContext
operator|&
name|BRC
argument_list|,
name|BugReport
operator|&
name|BR
argument_list|)
block|; }
block|;
name|class
name|NilReceiverBRVisitor
operator|:
name|public
name|BugReporterVisitorImpl
operator|<
name|NilReceiverBRVisitor
operator|>
block|{
name|public
operator|:
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
specifier|const
block|{
specifier|static
name|int
name|x
operator|=
literal|0
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
operator|&
name|x
argument_list|)
block|;   }
name|PathDiagnosticPiece
operator|*
name|VisitNode
argument_list|(
specifier|const
name|ExplodedNode
operator|*
name|N
argument_list|,
specifier|const
name|ExplodedNode
operator|*
name|PrevN
argument_list|,
name|BugReporterContext
operator|&
name|BRC
argument_list|,
name|BugReport
operator|&
name|BR
argument_list|)
block|; }
block|;
comment|/// Visitor that tries to report interesting diagnostics from conditions.
name|class
name|ConditionBRVisitor
operator|:
name|public
name|BugReporterVisitorImpl
operator|<
name|ConditionBRVisitor
operator|>
block|{
name|public
operator|:
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
specifier|const
block|{
specifier|static
name|int
name|x
operator|=
literal|0
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
operator|&
name|x
argument_list|)
block|;   }
name|virtual
name|PathDiagnosticPiece
operator|*
name|VisitNode
argument_list|(
specifier|const
name|ExplodedNode
operator|*
name|N
argument_list|,
specifier|const
name|ExplodedNode
operator|*
name|Prev
argument_list|,
name|BugReporterContext
operator|&
name|BRC
argument_list|,
name|BugReport
operator|&
name|BR
argument_list|)
block|;
name|PathDiagnosticPiece
operator|*
name|VisitNodeImpl
argument_list|(
specifier|const
name|ExplodedNode
operator|*
name|N
argument_list|,
specifier|const
name|ExplodedNode
operator|*
name|Prev
argument_list|,
name|BugReporterContext
operator|&
name|BRC
argument_list|,
name|BugReport
operator|&
name|BR
argument_list|)
block|;
name|PathDiagnosticPiece
operator|*
name|VisitTerminator
argument_list|(
specifier|const
name|Stmt
operator|*
name|Term
argument_list|,
specifier|const
name|ExplodedNode
operator|*
name|N
argument_list|,
specifier|const
name|CFGBlock
operator|*
name|srcBlk
argument_list|,
specifier|const
name|CFGBlock
operator|*
name|dstBlk
argument_list|,
name|BugReport
operator|&
name|R
argument_list|,
name|BugReporterContext
operator|&
name|BRC
argument_list|)
block|;
name|PathDiagnosticPiece
operator|*
name|VisitTrueTest
argument_list|(
argument|const Expr *Cond
argument_list|,
argument|bool tookTrue
argument_list|,
argument|BugReporterContext&BRC
argument_list|,
argument|BugReport&R
argument_list|,
argument|const ExplodedNode *N
argument_list|)
block|;
name|PathDiagnosticPiece
operator|*
name|VisitTrueTest
argument_list|(
argument|const Expr *Cond
argument_list|,
argument|const DeclRefExpr *DR
argument_list|,
argument|const bool tookTrue
argument_list|,
argument|BugReporterContext&BRC
argument_list|,
argument|BugReport&R
argument_list|,
argument|const ExplodedNode *N
argument_list|)
block|;
name|PathDiagnosticPiece
operator|*
name|VisitTrueTest
argument_list|(
argument|const Expr *Cond
argument_list|,
argument|const BinaryOperator *BExpr
argument_list|,
argument|const bool tookTrue
argument_list|,
argument|BugReporterContext&BRC
argument_list|,
argument|BugReport&R
argument_list|,
argument|const ExplodedNode *N
argument_list|)
block|;
name|PathDiagnosticPiece
operator|*
name|VisitConditionVariable
argument_list|(
argument|StringRef LhsString
argument_list|,
argument|const Expr *CondVarExpr
argument_list|,
argument|const bool tookTrue
argument_list|,
argument|BugReporterContext&BRC
argument_list|,
argument|BugReport&R
argument_list|,
argument|const ExplodedNode *N
argument_list|)
block|;
name|bool
name|patternMatch
argument_list|(
specifier|const
name|Expr
operator|*
name|Ex
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|&
name|Out
argument_list|,
name|BugReporterContext
operator|&
name|BRC
argument_list|,
name|BugReport
operator|&
name|R
argument_list|,
specifier|const
name|ExplodedNode
operator|*
name|N
argument_list|,
name|llvm
operator|::
name|Optional
operator|<
name|bool
operator|>
operator|&
name|prunable
argument_list|)
block|; }
block|;
name|namespace
name|bugreporter
block|{
name|BugReporterVisitor
operator|*
name|getTrackNullOrUndefValueVisitor
argument_list|(
specifier|const
name|ExplodedNode
operator|*
name|N
argument_list|,
specifier|const
name|Stmt
operator|*
name|S
argument_list|,
name|BugReport
operator|*
name|R
argument_list|)
block|;
specifier|const
name|Stmt
operator|*
name|GetDerefExpr
argument_list|(
specifier|const
name|ExplodedNode
operator|*
name|N
argument_list|)
block|;
specifier|const
name|Stmt
operator|*
name|GetDenomExpr
argument_list|(
specifier|const
name|ExplodedNode
operator|*
name|N
argument_list|)
block|;
specifier|const
name|Stmt
operator|*
name|GetCalleeExpr
argument_list|(
specifier|const
name|ExplodedNode
operator|*
name|N
argument_list|)
block|;
specifier|const
name|Stmt
operator|*
name|GetRetValExpr
argument_list|(
specifier|const
name|ExplodedNode
operator|*
name|N
argument_list|)
block|;  }
comment|// end namespace clang
block|}
comment|// end namespace ento
block|}
end_decl_stmt

begin_comment
comment|// end namespace bugreporter
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//LLVM_CLANG_GR__BUGREPORTERVISITOR
end_comment

end_unit

