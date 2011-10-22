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
name|class
name|FindLastStoreBRVisitor
range|:
name|public
name|BugReporterVisitor
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
decl_stmt|;
name|class
name|TrackConstraintBRVisitor
range|:
name|public
name|BugReporterVisitor
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
decl_stmt|;
name|class
name|NilReceiverBRVisitor
range|:
name|public
name|BugReporterVisitor
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
decl_stmt|;
comment|/// Visitor that tries to report interesting diagnostics from conditions.
name|class
name|ConditionBRVisitor
range|:
name|public
name|BugReporterVisitor
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
argument|const LocationContext *LC
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
argument|const LocationContext *LC
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
argument|const LocationContext *LC
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
argument_list|)
block|; }
decl_stmt|;
name|namespace
name|bugreporter
block|{
name|BugReporterVisitor
modifier|*
name|getTrackNullOrUndefValueVisitor
parameter_list|(
specifier|const
name|ExplodedNode
modifier|*
name|N
parameter_list|,
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
specifier|const
name|Stmt
modifier|*
name|GetDerefExpr
parameter_list|(
specifier|const
name|ExplodedNode
modifier|*
name|N
parameter_list|)
function_decl|;
specifier|const
name|Stmt
modifier|*
name|GetDenomExpr
parameter_list|(
specifier|const
name|ExplodedNode
modifier|*
name|N
parameter_list|)
function_decl|;
specifier|const
name|Stmt
modifier|*
name|GetCalleeExpr
parameter_list|(
specifier|const
name|ExplodedNode
modifier|*
name|N
parameter_list|)
function_decl|;
specifier|const
name|Stmt
modifier|*
name|GetRetValExpr
parameter_list|(
specifier|const
name|ExplodedNode
modifier|*
name|N
parameter_list|)
function_decl|;
block|}
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

