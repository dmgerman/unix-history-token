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
name|LLVM_CLANG_STATICANALYZER_CORE_BUGREPORTER_BUGREPORTERVISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_BUGREPORTER_BUGREPORTERVISITOR_H
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
name|std
operator|::
name|unique_ptr
operator|<
name|BugReporterVisitor
operator|>
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
name|Succ
argument_list|,
specifier|const
name|ExplodedNode
operator|*
name|Pred
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
name|std
operator|::
name|unique_ptr
operator|<
name|PathDiagnosticPiece
operator|>
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
name|std
operator|::
name|unique_ptr
operator|<
name|PathDiagnosticPiece
operator|>
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
block|; }
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
name|std
operator|::
name|unique_ptr
operator|<
name|BugReporterVisitor
operator|>
name|clone
argument_list|()
specifier|const
name|override
block|{
return|return
name|llvm
operator|::
name|make_unique
operator|<
name|DERIVED
operator|>
operator|(
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
operator|)
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
name|Satisfied
block|;
comment|/// If the visitor is tracking the value directly responsible for the
comment|/// bug, we are going to employ false positive suppression.
name|bool
name|EnableNullFPSuppression
block|;
name|public
operator|:
comment|/// Creates a visitor for every VarDecl inside a Stmt and registers it with
comment|/// the BugReport.
specifier|static
name|void
name|registerStatementVarDecls
argument_list|(
argument|BugReport&BR
argument_list|,
argument|const Stmt *S
argument_list|,
argument|bool EnableNullFPSuppression
argument_list|)
block|;
name|FindLastStoreBRVisitor
argument_list|(
argument|KnownSVal V
argument_list|,
argument|const MemRegion *R
argument_list|,
argument|bool InEnableNullFPSuppression
argument_list|)
operator|:
name|R
argument_list|(
name|R
argument_list|)
block|,
name|V
argument_list|(
name|V
argument_list|)
block|,
name|Satisfied
argument_list|(
name|false
argument_list|)
block|,
name|EnableNullFPSuppression
argument_list|(
argument|InEnableNullFPSuppression
argument_list|)
block|{}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
specifier|const
name|override
block|;
name|PathDiagnosticPiece
operator|*
name|VisitNode
argument_list|(
argument|const ExplodedNode *N
argument_list|,
argument|const ExplodedNode *PrevN
argument_list|,
argument|BugReporterContext&BRC
argument_list|,
argument|BugReport&BR
argument_list|)
name|override
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
name|bool
name|Assumption
block|;
name|bool
name|IsSatisfied
block|;
name|bool
name|IsZeroCheck
block|;
comment|/// We should start tracking from the last node along the path in which the
comment|/// value is constrained.
name|bool
name|IsTrackingTurnedOn
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
name|IsSatisfied
argument_list|(
name|false
argument_list|)
block|,
name|IsZeroCheck
argument_list|(
operator|!
name|Assumption
operator|&&
name|Constraint
operator|.
name|getAs
operator|<
name|Loc
operator|>
operator|(
operator|)
argument_list|)
block|,
name|IsTrackingTurnedOn
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
name|override
block|;
comment|/// Return the tag associated with this visitor.  This tag will be used
comment|/// to make all PathDiagnosticPieces created by this visitor.
specifier|static
specifier|const
name|char
operator|*
name|getTag
argument_list|()
block|;
name|PathDiagnosticPiece
operator|*
name|VisitNode
argument_list|(
argument|const ExplodedNode *N
argument_list|,
argument|const ExplodedNode *PrevN
argument_list|,
argument|BugReporterContext&BRC
argument_list|,
argument|BugReport&BR
argument_list|)
name|override
block|;
name|private
operator|:
comment|/// Checks if the constraint is valid in the current state.
name|bool
name|isUnderconstrained
argument_list|(
argument|const ExplodedNode *N
argument_list|)
specifier|const
block|;  }
block|;
comment|/// \class NilReceiverBRVisitor
comment|/// \brief Prints path notes when a message is sent to a nil receiver.
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
name|override
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
argument|const ExplodedNode *N
argument_list|,
argument|const ExplodedNode *PrevN
argument_list|,
argument|BugReporterContext&BRC
argument_list|,
argument|BugReport&BR
argument_list|)
name|override
block|;
comment|/// If the statement is a message send expression with nil receiver, returns
comment|/// the receiver expression. Returns NULL otherwise.
specifier|static
specifier|const
name|Expr
operator|*
name|getNilReceiver
argument_list|(
specifier|const
name|Stmt
operator|*
name|S
argument_list|,
specifier|const
name|ExplodedNode
operator|*
name|N
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
name|override
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
comment|/// Return the tag associated with this visitor.  This tag will be used
comment|/// to make all PathDiagnosticPieces created by this visitor.
specifier|static
specifier|const
name|char
operator|*
name|getTag
argument_list|()
block|;
name|PathDiagnosticPiece
operator|*
name|VisitNode
argument_list|(
argument|const ExplodedNode *N
argument_list|,
argument|const ExplodedNode *Prev
argument_list|,
argument|BugReporterContext&BRC
argument_list|,
argument|BugReport&BR
argument_list|)
name|override
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
name|Optional
operator|<
name|bool
operator|>
operator|&
name|prunable
argument_list|)
block|; }
block|;
comment|/// \brief Suppress reports that might lead to known false positives.
comment|///
comment|/// Currently this suppresses reports based on locations of bugs.
name|class
name|LikelyFalsePositiveSuppressionBRVisitor
operator|:
name|public
name|BugReporterVisitorImpl
operator|<
name|LikelyFalsePositiveSuppressionBRVisitor
operator|>
block|{
name|public
operator|:
specifier|static
name|void
operator|*
name|getTag
argument_list|()
block|{
specifier|static
name|int
name|Tag
operator|=
literal|0
block|;
return|return
name|static_cast
operator|<
name|void
operator|*
operator|>
operator|(
operator|&
name|Tag
operator|)
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
specifier|const
name|override
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|getTag
argument_list|()
argument_list|)
block|;   }
name|PathDiagnosticPiece
operator|*
name|VisitNode
argument_list|(
argument|const ExplodedNode *N
argument_list|,
argument|const ExplodedNode *Prev
argument_list|,
argument|BugReporterContext&BRC
argument_list|,
argument|BugReport&BR
argument_list|)
name|override
block|{
return|return
name|nullptr
return|;
block|}
name|std
operator|::
name|unique_ptr
operator|<
name|PathDiagnosticPiece
operator|>
name|getEndPath
argument_list|(
argument|BugReporterContext&BRC
argument_list|,
argument|const ExplodedNode *N
argument_list|,
argument|BugReport&BR
argument_list|)
name|override
block|; }
block|;
comment|/// \brief When a region containing undefined value or '0' value is passed
comment|/// as an argument in a call, marks the call as interesting.
comment|///
comment|/// As a result, BugReporter will not prune the path through the function even
comment|/// if the region's contents are not modified/accessed by the call.
name|class
name|UndefOrNullArgVisitor
operator|:
name|public
name|BugReporterVisitorImpl
operator|<
name|UndefOrNullArgVisitor
operator|>
block|{
comment|/// The interesting memory region this visitor is tracking.
specifier|const
name|MemRegion
operator|*
name|R
block|;
name|public
operator|:
name|UndefOrNullArgVisitor
argument_list|(
specifier|const
name|MemRegion
operator|*
name|InR
argument_list|)
operator|:
name|R
argument_list|(
argument|InR
argument_list|)
block|{}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
specifier|const
name|override
block|{
specifier|static
name|int
name|Tag
operator|=
literal|0
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
operator|&
name|Tag
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|R
argument_list|)
block|;   }
name|PathDiagnosticPiece
operator|*
name|VisitNode
argument_list|(
argument|const ExplodedNode *N
argument_list|,
argument|const ExplodedNode *PrevN
argument_list|,
argument|BugReporterContext&BRC
argument_list|,
argument|BugReport&BR
argument_list|)
name|override
block|; }
block|;
name|class
name|SuppressInlineDefensiveChecksVisitor
operator|:
name|public
name|BugReporterVisitorImpl
operator|<
name|SuppressInlineDefensiveChecksVisitor
operator|>
block|{
comment|/// The symbolic value for which we are tracking constraints.
comment|/// This value is constrained to null in the end of path.
name|DefinedSVal
name|V
block|;
comment|/// Track if we found the node where the constraint was first added.
name|bool
name|IsSatisfied
block|;
comment|/// Since the visitors can be registered on nodes previous to the last
comment|/// node in the BugReport, but the path traversal always starts with the last
comment|/// node, the visitor invariant (that we start with a node in which V is null)
comment|/// might not hold when node visitation starts. We are going to start tracking
comment|/// from the last node in which the value is null.
name|bool
name|IsTrackingTurnedOn
block|;
name|public
operator|:
name|SuppressInlineDefensiveChecksVisitor
argument_list|(
argument|DefinedSVal Val
argument_list|,
argument|const ExplodedNode *N
argument_list|)
block|;
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
specifier|const
name|override
block|;
comment|/// Return the tag associated with this visitor.  This tag will be used
comment|/// to make all PathDiagnosticPieces created by this visitor.
specifier|static
specifier|const
name|char
operator|*
name|getTag
argument_list|()
block|;
name|PathDiagnosticPiece
operator|*
name|VisitNode
argument_list|(
argument|const ExplodedNode *Succ
argument_list|,
argument|const ExplodedNode *Pred
argument_list|,
argument|BugReporterContext&BRC
argument_list|,
argument|BugReport&BR
argument_list|)
name|override
block|; }
block|;
name|namespace
name|bugreporter
block|{
comment|/// Attempts to add visitors to trace a null or undefined value back to its
comment|/// point of origin, whether it is a symbol constrained to null or an explicit
comment|/// assignment.
comment|///
comment|/// \param N A node "downstream" from the evaluation of the statement.
comment|/// \param S The statement whose value is null or undefined.
comment|/// \param R The bug report to which visitors should be attached.
comment|/// \param IsArg Whether the statement is an argument to an inlined function.
comment|///              If this is the case, \p N \em must be the CallEnter node for
comment|///              the function.
comment|/// \param EnableNullFPSuppression Whether we should employ false positive
comment|///         suppression (inlined defensive checks, returned null).
comment|///
comment|/// \return Whether or not the function was able to add visitors for this
comment|///         statement. Note that returning \c true does not actually imply
comment|///         that any visitors were added.
name|bool
name|trackNullOrUndefValue
argument_list|(
argument|const ExplodedNode *N
argument_list|,
argument|const Stmt *S
argument_list|,
argument|BugReport&R
argument_list|,
argument|bool IsArg = false
argument_list|,
argument|bool EnableNullFPSuppression = true
argument_list|)
block|;
specifier|const
name|Expr
operator|*
name|getDerefExpr
argument_list|(
specifier|const
name|Stmt
operator|*
name|S
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
name|GetRetValExpr
argument_list|(
specifier|const
name|ExplodedNode
operator|*
name|N
argument_list|)
block|;
name|bool
name|isDeclRefExprToReference
argument_list|(
specifier|const
name|Expr
operator|*
name|E
argument_list|)
block|;   }
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

end_unit

