begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ExprEngine.h - Path-Sensitive Expression-Level Dataflow ---*- C++ -*-=//
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
comment|//  This file defines a meta-engine for path-sensitive dataflow analysis that
end_comment

begin_comment
comment|//  is built on CoreEngine, but provides the boilerplate to execute transfer
end_comment

begin_comment
comment|//  functions and build the ExplodedGraph at the expression level.
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
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_EXPRENGINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_EXPRENGINE_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/DomainSpecific/ObjCNoReturn.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/BugReporter/BugReporter.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/AnalysisManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/CoreEngine.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/ProgramState.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/ProgramStateTrait.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/SubEngine.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|AnalysisDeclContextManager
decl_stmt|;
name|class
name|CXXCatchStmt
decl_stmt|;
name|class
name|CXXConstructExpr
decl_stmt|;
name|class
name|CXXDeleteExpr
decl_stmt|;
name|class
name|CXXNewExpr
decl_stmt|;
name|class
name|CXXTemporaryObjectExpr
decl_stmt|;
name|class
name|CXXThisExpr
decl_stmt|;
name|class
name|MaterializeTemporaryExpr
decl_stmt|;
name|class
name|ObjCAtSynchronizedStmt
decl_stmt|;
name|class
name|ObjCForCollectionStmt
decl_stmt|;
name|namespace
name|ento
block|{
name|class
name|AnalysisManager
decl_stmt|;
name|class
name|CallEvent
decl_stmt|;
name|class
name|CXXConstructorCall
decl_stmt|;
name|class
name|ExprEngine
range|:
name|public
name|SubEngine
block|{
name|public
operator|:
comment|/// The modes of inlining, which override the default analysis-wide settings.
expr|enum
name|InliningModes
block|{
comment|/// Follow the default settings for inlining callees.
name|Inline_Regular
operator|=
literal|0
block|,
comment|/// Do minimal inlining of callees.
name|Inline_Minimal
operator|=
literal|0x1
block|}
block|;
name|private
operator|:
name|AnalysisManager
operator|&
name|AMgr
block|;
name|AnalysisDeclContextManager
operator|&
name|AnalysisDeclContexts
block|;
name|CoreEngine
name|Engine
block|;
comment|/// G - the simulation graph.
name|ExplodedGraph
operator|&
name|G
block|;
comment|/// StateMgr - Object that manages the data for all created states.
name|ProgramStateManager
name|StateMgr
block|;
comment|/// SymMgr - Object that manages the symbol information.
name|SymbolManager
operator|&
name|SymMgr
block|;
comment|/// svalBuilder - SValBuilder object that creates SVals from expressions.
name|SValBuilder
operator|&
name|svalBuilder
block|;
name|unsigned
name|int
name|currStmtIdx
block|;
specifier|const
name|NodeBuilderContext
operator|*
name|currBldrCtx
block|;
comment|/// Helper object to determine if an Objective-C message expression
comment|/// implicitly never returns.
name|ObjCNoReturn
name|ObjCNoRet
block|;
comment|/// Whether or not GC is enabled in this analysis.
name|bool
name|ObjCGCEnabled
block|;
comment|/// The BugReporter associated with this engine.  It is important that
comment|///  this object be placed at the very end of member variables so that its
comment|///  destructor is called before the rest of the ExprEngine is destroyed.
name|GRBugReporter
name|BR
block|;
comment|/// The functions which have been analyzed through inlining. This is owned by
comment|/// AnalysisConsumer. It can be null.
name|SetOfConstDecls
operator|*
name|VisitedCallees
block|;
comment|/// The flag, which specifies the mode of inlining for the engine.
name|InliningModes
name|HowToInline
block|;
name|public
operator|:
name|ExprEngine
argument_list|(
argument|AnalysisManager&mgr
argument_list|,
argument|bool gcEnabled
argument_list|,
argument|SetOfConstDecls *VisitedCalleesIn
argument_list|,
argument|FunctionSummariesTy *FS
argument_list|,
argument|InliningModes HowToInlineIn
argument_list|)
block|;
operator|~
name|ExprEngine
argument_list|()
name|override
block|;
comment|/// Returns true if there is still simulation state on the worklist.
name|bool
name|ExecuteWorkList
argument_list|(
argument|const LocationContext *L
argument_list|,
argument|unsigned Steps =
literal|150000
argument_list|)
block|{
return|return
name|Engine
operator|.
name|ExecuteWorkList
argument_list|(
name|L
argument_list|,
name|Steps
argument_list|,
name|nullptr
argument_list|)
return|;
block|}
comment|/// Execute the work list with an initial state. Nodes that reaches the exit
comment|/// of the function are added into the Dst set, which represent the exit
comment|/// state of the function call. Returns true if there is still simulation
comment|/// state on the worklist.
name|bool
name|ExecuteWorkListWithInitialState
argument_list|(
argument|const LocationContext *L
argument_list|,
argument|unsigned Steps
argument_list|,
argument|ProgramStateRef InitState
argument_list|,
argument|ExplodedNodeSet&Dst
argument_list|)
block|{
return|return
name|Engine
operator|.
name|ExecuteWorkListWithInitialState
argument_list|(
name|L
argument_list|,
name|Steps
argument_list|,
name|InitState
argument_list|,
name|Dst
argument_list|)
return|;
block|}
comment|/// getContext - Return the ASTContext associated with this analysis.
name|ASTContext
operator|&
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|AMgr
operator|.
name|getASTContext
argument_list|()
return|;
block|}
name|AnalysisManager
operator|&
name|getAnalysisManager
argument_list|()
name|override
block|{
return|return
name|AMgr
return|;
block|}
name|CheckerManager
operator|&
name|getCheckerManager
argument_list|()
specifier|const
block|{
return|return
operator|*
name|AMgr
operator|.
name|getCheckerManager
argument_list|()
return|;
block|}
name|SValBuilder
operator|&
name|getSValBuilder
argument_list|()
block|{
return|return
name|svalBuilder
return|;
block|}
name|BugReporter
operator|&
name|getBugReporter
argument_list|()
block|{
return|return
name|BR
return|;
block|}
specifier|const
name|NodeBuilderContext
operator|&
name|getBuilderContext
argument_list|()
block|{
name|assert
argument_list|(
name|currBldrCtx
argument_list|)
block|;
return|return
operator|*
name|currBldrCtx
return|;
block|}
name|bool
name|isObjCGCEnabled
argument_list|()
block|{
return|return
name|ObjCGCEnabled
return|;
block|}
specifier|const
name|Stmt
operator|*
name|getStmt
argument_list|()
specifier|const
block|;
name|void
name|GenerateAutoTransition
argument_list|(
name|ExplodedNode
operator|*
name|N
argument_list|)
block|;
name|void
name|enqueueEndOfPath
argument_list|(
name|ExplodedNodeSet
operator|&
name|S
argument_list|)
block|;
name|void
name|GenerateCallExitNode
argument_list|(
name|ExplodedNode
operator|*
name|N
argument_list|)
block|;
comment|/// Visualize the ExplodedGraph created by executing the simulation.
name|void
name|ViewGraph
argument_list|(
argument|bool trim = false
argument_list|)
block|;
comment|/// Visualize a trimmed ExplodedGraph that only contains paths to the given
comment|/// nodes.
name|void
name|ViewGraph
argument_list|(
name|ArrayRef
operator|<
specifier|const
name|ExplodedNode
operator|*
operator|>
name|Nodes
argument_list|)
block|;
comment|/// getInitialState - Return the initial state used for the root vertex
comment|///  in the ExplodedGraph.
name|ProgramStateRef
name|getInitialState
argument_list|(
argument|const LocationContext *InitLoc
argument_list|)
name|override
block|;
name|ExplodedGraph
operator|&
name|getGraph
argument_list|()
block|{
return|return
name|G
return|;
block|}
specifier|const
name|ExplodedGraph
operator|&
name|getGraph
argument_list|()
specifier|const
block|{
return|return
name|G
return|;
block|}
comment|/// \brief Run the analyzer's garbage collection - remove dead symbols and
comment|/// bindings from the state.
comment|///
comment|/// Checkers can participate in this process with two callbacks:
comment|/// \c checkLiveSymbols and \c checkDeadSymbols. See the CheckerDocumentation
comment|/// class for more information.
comment|///
comment|/// \param Node The predecessor node, from which the processing should start.
comment|/// \param Out The returned set of output nodes.
comment|/// \param ReferenceStmt The statement which is about to be processed.
comment|///        Everything needed for this statement should be considered live.
comment|///        A null statement means that everything in child LocationContexts
comment|///        is dead.
comment|/// \param LC The location context of the \p ReferenceStmt. A null location
comment|///        context means that we have reached the end of analysis and that
comment|///        all statements and local variables should be considered dead.
comment|/// \param DiagnosticStmt Used as a location for any warnings that should
comment|///        occur while removing the dead (e.g. leaks). By default, the
comment|///        \p ReferenceStmt is used.
comment|/// \param K Denotes whether this is a pre- or post-statement purge. This
comment|///        must only be ProgramPoint::PostStmtPurgeDeadSymbolsKind if an
comment|///        entire location context is being cleared, in which case the
comment|///        \p ReferenceStmt must either be a ReturnStmt or \c NULL. Otherwise,
comment|///        it must be ProgramPoint::PreStmtPurgeDeadSymbolsKind (the default)
comment|///        and \p ReferenceStmt must be valid (non-null).
name|void
name|removeDead
argument_list|(
argument|ExplodedNode *Node
argument_list|,
argument|ExplodedNodeSet&Out
argument_list|,
argument|const Stmt *ReferenceStmt
argument_list|,
argument|const LocationContext *LC
argument_list|,
argument|const Stmt *DiagnosticStmt = nullptr
argument_list|,
argument|ProgramPoint::Kind K = ProgramPoint::PreStmtPurgeDeadSymbolsKind
argument_list|)
block|;
comment|/// processCFGElement - Called by CoreEngine. Used to generate new successor
comment|///  nodes by processing the 'effects' of a CFG element.
name|void
name|processCFGElement
argument_list|(
argument|const CFGElement E
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|unsigned StmtIdx
argument_list|,
argument|NodeBuilderContext *Ctx
argument_list|)
name|override
block|;
name|void
name|ProcessStmt
argument_list|(
argument|const CFGStmt S
argument_list|,
argument|ExplodedNode *Pred
argument_list|)
block|;
name|void
name|ProcessInitializer
argument_list|(
argument|const CFGInitializer I
argument_list|,
argument|ExplodedNode *Pred
argument_list|)
block|;
name|void
name|ProcessImplicitDtor
argument_list|(
argument|const CFGImplicitDtor D
argument_list|,
argument|ExplodedNode *Pred
argument_list|)
block|;
name|void
name|ProcessNewAllocator
argument_list|(
specifier|const
name|CXXNewExpr
operator|*
name|NE
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|)
block|;
name|void
name|ProcessAutomaticObjDtor
argument_list|(
argument|const CFGAutomaticObjDtor D
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|ExplodedNodeSet&Dst
argument_list|)
block|;
name|void
name|ProcessDeleteDtor
argument_list|(
argument|const CFGDeleteDtor D
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|ExplodedNodeSet&Dst
argument_list|)
block|;
name|void
name|ProcessBaseDtor
argument_list|(
argument|const CFGBaseDtor D
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|ExplodedNodeSet&Dst
argument_list|)
block|;
name|void
name|ProcessMemberDtor
argument_list|(
argument|const CFGMemberDtor D
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|ExplodedNodeSet&Dst
argument_list|)
block|;
name|void
name|ProcessTemporaryDtor
argument_list|(
argument|const CFGTemporaryDtor D
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|ExplodedNodeSet&Dst
argument_list|)
block|;
comment|/// Called by CoreEngine when processing the entrance of a CFGBlock.
name|void
name|processCFGBlockEntrance
argument_list|(
argument|const BlockEdge&L
argument_list|,
argument|NodeBuilderWithSinks&nodeBuilder
argument_list|,
argument|ExplodedNode *Pred
argument_list|)
name|override
block|;
comment|/// ProcessBranch - Called by CoreEngine.  Used to generate successor
comment|///  nodes by processing the 'effects' of a branch condition.
name|void
name|processBranch
argument_list|(
argument|const Stmt *Condition
argument_list|,
argument|const Stmt *Term
argument_list|,
argument|NodeBuilderContext& BuilderCtx
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|ExplodedNodeSet&Dst
argument_list|,
argument|const CFGBlock *DstT
argument_list|,
argument|const CFGBlock *DstF
argument_list|)
name|override
block|;
comment|/// Called by CoreEngine.
comment|/// Used to generate successor nodes for temporary destructors depending
comment|/// on whether the corresponding constructor was visited.
name|void
name|processCleanupTemporaryBranch
argument_list|(
argument|const CXXBindTemporaryExpr *BTE
argument_list|,
argument|NodeBuilderContext&BldCtx
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|ExplodedNodeSet&Dst
argument_list|,
argument|const CFGBlock *DstT
argument_list|,
argument|const CFGBlock *DstF
argument_list|)
name|override
block|;
comment|/// Called by CoreEngine.  Used to processing branching behavior
comment|/// at static initializers.
name|void
name|processStaticInitializer
argument_list|(
argument|const DeclStmt *DS
argument_list|,
argument|NodeBuilderContext& BuilderCtx
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|ExplodedNodeSet&Dst
argument_list|,
argument|const CFGBlock *DstT
argument_list|,
argument|const CFGBlock *DstF
argument_list|)
name|override
block|;
comment|/// processIndirectGoto - Called by CoreEngine.  Used to generate successor
comment|///  nodes by processing the 'effects' of a computed goto jump.
name|void
name|processIndirectGoto
argument_list|(
argument|IndirectGotoNodeBuilder& builder
argument_list|)
name|override
block|;
comment|/// ProcessSwitch - Called by CoreEngine.  Used to generate successor
comment|///  nodes by processing the 'effects' of a switch statement.
name|void
name|processSwitch
argument_list|(
argument|SwitchNodeBuilder& builder
argument_list|)
name|override
block|;
comment|/// Called by CoreEngine.  Used to notify checkers that processing a
comment|/// function has begun. Called for both inlined and and top-level functions.
name|void
name|processBeginOfFunction
argument_list|(
argument|NodeBuilderContext&BC
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|ExplodedNodeSet&Dst
argument_list|,
argument|const BlockEdge&L
argument_list|)
name|override
block|;
comment|/// Called by CoreEngine.  Used to notify checkers that processing a
comment|/// function has ended. Called for both inlined and and top-level functions.
name|void
name|processEndOfFunction
argument_list|(
argument|NodeBuilderContext& BC
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|const ReturnStmt *RS = nullptr
argument_list|)
name|override
block|;
comment|/// Remove dead bindings/symbols before exiting a function.
name|void
name|removeDeadOnEndOfFunction
argument_list|(
name|NodeBuilderContext
operator|&
name|BC
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// Generate the entry node of the callee.
name|void
name|processCallEnter
argument_list|(
argument|NodeBuilderContext& BC
argument_list|,
argument|CallEnter CE
argument_list|,
argument|ExplodedNode *Pred
argument_list|)
name|override
block|;
comment|/// Generate the sequence of nodes that simulate the call exit and the post
comment|/// visit for CallExpr.
name|void
name|processCallExit
argument_list|(
argument|ExplodedNode *Pred
argument_list|)
name|override
block|;
comment|/// Called by CoreEngine when the analysis worklist has terminated.
name|void
name|processEndWorklist
argument_list|(
argument|bool hasWorkRemaining
argument_list|)
name|override
block|;
comment|/// evalAssume - Callback function invoked by the ConstraintManager when
comment|///  making assumptions about state values.
name|ProgramStateRef
name|processAssume
argument_list|(
argument|ProgramStateRef state
argument_list|,
argument|SVal cond
argument_list|,
argument|bool assumption
argument_list|)
name|override
block|;
comment|/// processRegionChanges - Called by ProgramStateManager whenever a change is made
comment|///  to the store. Used to update checkers that track region values.
name|ProgramStateRef
name|processRegionChanges
argument_list|(
argument|ProgramStateRef state
argument_list|,
argument|const InvalidatedSymbols *invalidated
argument_list|,
argument|ArrayRef<const MemRegion *> ExplicitRegions
argument_list|,
argument|ArrayRef<const MemRegion *> Regions
argument_list|,
argument|const LocationContext *LCtx
argument_list|,
argument|const CallEvent *Call
argument_list|)
name|override
block|;
comment|/// printState - Called by ProgramStateManager to print checker-specific data.
name|void
name|printState
argument_list|(
argument|raw_ostream&Out
argument_list|,
argument|ProgramStateRef State
argument_list|,
argument|const char *NL
argument_list|,
argument|const char *Sep
argument_list|)
name|override
block|;
name|ProgramStateManager
operator|&
name|getStateManager
argument_list|()
name|override
block|{
return|return
name|StateMgr
return|;
block|}
name|StoreManager
operator|&
name|getStoreManager
argument_list|()
block|{
return|return
name|StateMgr
operator|.
name|getStoreManager
argument_list|()
return|;
block|}
name|ConstraintManager
operator|&
name|getConstraintManager
argument_list|()
block|{
return|return
name|StateMgr
operator|.
name|getConstraintManager
argument_list|()
return|;
block|}
comment|// FIXME: Remove when we migrate over to just using SValBuilder.
name|BasicValueFactory
operator|&
name|getBasicVals
argument_list|()
block|{
return|return
name|StateMgr
operator|.
name|getBasicVals
argument_list|()
return|;
block|}
comment|// FIXME: Remove when we migrate over to just using ValueManager.
name|SymbolManager
operator|&
name|getSymbolManager
argument_list|()
block|{
return|return
name|SymMgr
return|;
block|}
specifier|const
name|SymbolManager
operator|&
name|getSymbolManager
argument_list|()
specifier|const
block|{
return|return
name|SymMgr
return|;
block|}
comment|// Functions for external checking of whether we have unfinished work
name|bool
name|wasBlocksExhausted
argument_list|()
specifier|const
block|{
return|return
name|Engine
operator|.
name|wasBlocksExhausted
argument_list|()
return|;
block|}
name|bool
name|hasEmptyWorkList
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Engine
operator|.
name|getWorkList
argument_list|()
operator|->
name|hasWork
argument_list|()
return|;
block|}
name|bool
name|hasWorkRemaining
argument_list|()
specifier|const
block|{
return|return
name|Engine
operator|.
name|hasWorkRemaining
argument_list|()
return|;
block|}
specifier|const
name|CoreEngine
operator|&
name|getCoreEngine
argument_list|()
specifier|const
block|{
return|return
name|Engine
return|;
block|}
name|public
operator|:
comment|/// Visit - Transfer function logic for all statements.  Dispatches to
comment|///  other functions that handle specific kinds of statements.
name|void
name|Visit
argument_list|(
specifier|const
name|Stmt
operator|*
name|S
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// VisitArraySubscriptExpr - Transfer function for array accesses.
name|void
name|VisitLvalArraySubscriptExpr
argument_list|(
specifier|const
name|ArraySubscriptExpr
operator|*
name|Ex
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// VisitGCCAsmStmt - Transfer function logic for inline asm.
name|void
name|VisitGCCAsmStmt
argument_list|(
specifier|const
name|GCCAsmStmt
operator|*
name|A
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// VisitMSAsmStmt - Transfer function logic for MS inline asm.
name|void
name|VisitMSAsmStmt
argument_list|(
specifier|const
name|MSAsmStmt
operator|*
name|A
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// VisitBlockExpr - Transfer function logic for BlockExprs.
name|void
name|VisitBlockExpr
argument_list|(
specifier|const
name|BlockExpr
operator|*
name|BE
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// VisitLambdaExpr - Transfer function logic for LambdaExprs.
name|void
name|VisitLambdaExpr
argument_list|(
specifier|const
name|LambdaExpr
operator|*
name|LE
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// VisitBinaryOperator - Transfer function logic for binary operators.
name|void
name|VisitBinaryOperator
argument_list|(
specifier|const
name|BinaryOperator
operator|*
name|B
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// VisitCall - Transfer function for function calls.
name|void
name|VisitCallExpr
argument_list|(
specifier|const
name|CallExpr
operator|*
name|CE
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// VisitCast - Transfer function logic for all casts (implicit and explicit).
name|void
name|VisitCast
argument_list|(
specifier|const
name|CastExpr
operator|*
name|CastE
argument_list|,
specifier|const
name|Expr
operator|*
name|Ex
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// VisitCompoundLiteralExpr - Transfer function logic for compound literals.
name|void
name|VisitCompoundLiteralExpr
argument_list|(
specifier|const
name|CompoundLiteralExpr
operator|*
name|CL
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// Transfer function logic for DeclRefExprs and BlockDeclRefExprs.
name|void
name|VisitCommonDeclRefExpr
argument_list|(
specifier|const
name|Expr
operator|*
name|DR
argument_list|,
specifier|const
name|NamedDecl
operator|*
name|D
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// VisitDeclStmt - Transfer function logic for DeclStmts.
name|void
name|VisitDeclStmt
argument_list|(
specifier|const
name|DeclStmt
operator|*
name|DS
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// VisitGuardedExpr - Transfer function logic for ?, __builtin_choose
name|void
name|VisitGuardedExpr
argument_list|(
specifier|const
name|Expr
operator|*
name|Ex
argument_list|,
specifier|const
name|Expr
operator|*
name|L
argument_list|,
specifier|const
name|Expr
operator|*
name|R
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
name|void
name|VisitInitListExpr
argument_list|(
specifier|const
name|InitListExpr
operator|*
name|E
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// VisitLogicalExpr - Transfer function logic for '&&', '||'
name|void
name|VisitLogicalExpr
argument_list|(
specifier|const
name|BinaryOperator
operator|*
name|B
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// VisitMemberExpr - Transfer function for member expressions.
name|void
name|VisitMemberExpr
argument_list|(
specifier|const
name|MemberExpr
operator|*
name|M
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// VisitMemberExpr - Transfer function for builtin atomic expressions
name|void
name|VisitAtomicExpr
argument_list|(
specifier|const
name|AtomicExpr
operator|*
name|E
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// Transfer function logic for ObjCAtSynchronizedStmts.
name|void
name|VisitObjCAtSynchronizedStmt
argument_list|(
specifier|const
name|ObjCAtSynchronizedStmt
operator|*
name|S
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// Transfer function logic for computing the lvalue of an Objective-C ivar.
name|void
name|VisitLvalObjCIvarRefExpr
argument_list|(
specifier|const
name|ObjCIvarRefExpr
operator|*
name|DR
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// VisitObjCForCollectionStmt - Transfer function logic for
comment|///  ObjCForCollectionStmt.
name|void
name|VisitObjCForCollectionStmt
argument_list|(
specifier|const
name|ObjCForCollectionStmt
operator|*
name|S
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
name|void
name|VisitObjCMessage
argument_list|(
specifier|const
name|ObjCMessageExpr
operator|*
name|ME
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// VisitReturnStmt - Transfer function logic for return statements.
name|void
name|VisitReturnStmt
argument_list|(
specifier|const
name|ReturnStmt
operator|*
name|R
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// VisitOffsetOfExpr - Transfer function for offsetof.
name|void
name|VisitOffsetOfExpr
argument_list|(
specifier|const
name|OffsetOfExpr
operator|*
name|Ex
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// VisitUnaryExprOrTypeTraitExpr - Transfer function for sizeof.
name|void
name|VisitUnaryExprOrTypeTraitExpr
argument_list|(
specifier|const
name|UnaryExprOrTypeTraitExpr
operator|*
name|Ex
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// VisitUnaryOperator - Transfer function logic for unary operators.
name|void
name|VisitUnaryOperator
argument_list|(
specifier|const
name|UnaryOperator
operator|*
name|B
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// Handle ++ and -- (both pre- and post-increment).
name|void
name|VisitIncrementDecrementOperator
argument_list|(
specifier|const
name|UnaryOperator
operator|*
name|U
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
name|void
name|VisitCXXBindTemporaryExpr
argument_list|(
specifier|const
name|CXXBindTemporaryExpr
operator|*
name|BTE
argument_list|,
name|ExplodedNodeSet
operator|&
name|PreVisit
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
name|void
name|VisitCXXCatchStmt
argument_list|(
specifier|const
name|CXXCatchStmt
operator|*
name|CS
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
name|void
name|VisitCXXThisExpr
argument_list|(
specifier|const
name|CXXThisExpr
operator|*
name|TE
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
name|void
name|VisitCXXConstructExpr
argument_list|(
specifier|const
name|CXXConstructExpr
operator|*
name|E
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
name|void
name|VisitCXXDestructor
argument_list|(
argument|QualType ObjectType
argument_list|,
argument|const MemRegion *Dest
argument_list|,
argument|const Stmt *S
argument_list|,
argument|bool IsBaseDtor
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|ExplodedNodeSet&Dst
argument_list|)
block|;
name|void
name|VisitCXXNewAllocatorCall
argument_list|(
specifier|const
name|CXXNewExpr
operator|*
name|CNE
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
name|void
name|VisitCXXNewExpr
argument_list|(
specifier|const
name|CXXNewExpr
operator|*
name|CNE
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
name|void
name|VisitCXXDeleteExpr
argument_list|(
specifier|const
name|CXXDeleteExpr
operator|*
name|CDE
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// Create a C++ temporary object for an rvalue.
name|void
name|CreateCXXTemporaryObject
argument_list|(
specifier|const
name|MaterializeTemporaryExpr
operator|*
name|ME
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|)
block|;
comment|/// evalEagerlyAssumeBinOpBifurcation - Given the nodes in 'Src', eagerly assume symbolic
comment|///  expressions of the form 'x != 0' and generate new nodes (stored in Dst)
comment|///  with those assumptions.
name|void
name|evalEagerlyAssumeBinOpBifurcation
argument_list|(
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|,
name|ExplodedNodeSet
operator|&
name|Src
argument_list|,
specifier|const
name|Expr
operator|*
name|Ex
argument_list|)
block|;
name|std
operator|::
name|pair
operator|<
specifier|const
name|ProgramPointTag
operator|*
block|,
specifier|const
name|ProgramPointTag
operator|*
operator|>
name|geteagerlyAssumeBinOpBifurcationTags
argument_list|()
block|;
name|SVal
name|evalMinus
argument_list|(
argument|SVal X
argument_list|)
block|{
return|return
name|X
operator|.
name|isValid
argument_list|()
operator|?
name|svalBuilder
operator|.
name|evalMinus
argument_list|(
name|X
operator|.
name|castAs
operator|<
name|NonLoc
operator|>
operator|(
operator|)
argument_list|)
operator|:
name|X
return|;
block|}
name|SVal
name|evalComplement
argument_list|(
argument|SVal X
argument_list|)
block|{
return|return
name|X
operator|.
name|isValid
argument_list|()
condition|?
name|svalBuilder
operator|.
name|evalComplement
argument_list|(
name|X
operator|.
name|castAs
operator|<
name|NonLoc
operator|>
operator|(
operator|)
argument_list|)
else|:
name|X
return|;
block|}
name|ProgramStateRef
name|handleLValueBitCast
argument_list|(
argument|ProgramStateRef state
argument_list|,
argument|const Expr *Ex
argument_list|,
argument|const LocationContext *LCtx
argument_list|,
argument|QualType T
argument_list|,
argument|QualType ExTy
argument_list|,
argument|const CastExpr *CastE
argument_list|,
argument|StmtNodeBuilder&Bldr
argument_list|,
argument|ExplodedNode *Pred
argument_list|)
block|;
name|ProgramStateRef
name|handleLVectorSplat
argument_list|(
argument|ProgramStateRef state
argument_list|,
argument|const LocationContext *LCtx
argument_list|,
argument|const CastExpr *CastE
argument_list|,
argument|StmtNodeBuilder&Bldr
argument_list|,
argument|ExplodedNode *Pred
argument_list|)
block|;
name|void
name|handleUOExtension
argument_list|(
argument|ExplodedNodeSet::iterator I
argument_list|,
argument|const UnaryOperator* U
argument_list|,
argument|StmtNodeBuilder&Bldr
argument_list|)
block|;
name|public
operator|:
name|SVal
name|evalBinOp
argument_list|(
argument|ProgramStateRef state
argument_list|,
argument|BinaryOperator::Opcode op
argument_list|,
argument|NonLoc L
argument_list|,
argument|NonLoc R
argument_list|,
argument|QualType T
argument_list|)
block|{
return|return
name|svalBuilder
operator|.
name|evalBinOpNN
argument_list|(
name|state
argument_list|,
name|op
argument_list|,
name|L
argument_list|,
name|R
argument_list|,
name|T
argument_list|)
return|;
block|}
name|SVal
name|evalBinOp
argument_list|(
argument|ProgramStateRef state
argument_list|,
argument|BinaryOperator::Opcode op
argument_list|,
argument|NonLoc L
argument_list|,
argument|SVal R
argument_list|,
argument|QualType T
argument_list|)
block|{
return|return
name|R
operator|.
name|isValid
argument_list|()
condition|?
name|svalBuilder
operator|.
name|evalBinOpNN
argument_list|(
name|state
argument_list|,
name|op
argument_list|,
name|L
argument_list|,
name|R
operator|.
name|castAs
operator|<
name|NonLoc
operator|>
operator|(
operator|)
argument_list|,
name|T
argument_list|)
else|:
name|R
return|;
block|}
name|SVal
name|evalBinOp
argument_list|(
argument|ProgramStateRef ST
argument_list|,
argument|BinaryOperator::Opcode Op
argument_list|,
argument|SVal LHS
argument_list|,
argument|SVal RHS
argument_list|,
argument|QualType T
argument_list|)
block|{
return|return
name|svalBuilder
operator|.
name|evalBinOp
argument_list|(
name|ST
argument_list|,
name|Op
argument_list|,
name|LHS
argument_list|,
name|RHS
argument_list|,
name|T
argument_list|)
return|;
block|}
name|protected
operator|:
comment|/// evalBind - Handle the semantics of binding a value to a specific location.
comment|///  This method is used by evalStore, VisitDeclStmt, and others.
name|void
name|evalBind
argument_list|(
argument|ExplodedNodeSet&Dst
argument_list|,
argument|const Stmt *StoreE
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|SVal location
argument_list|,
argument|SVal Val
argument_list|,
argument|bool atDeclInit = false
argument_list|,
argument|const ProgramPoint *PP = nullptr
argument_list|)
block|;
comment|/// Call PointerEscape callback when a value escapes as a result of bind.
name|ProgramStateRef
name|processPointerEscapedOnBind
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|SVal Loc
argument_list|,
argument|SVal Val
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
name|override
block|;
comment|/// Call PointerEscape callback when a value escapes as a result of
comment|/// region invalidation.
comment|/// \param[in] ITraits Specifies invalidation traits for regions/symbols.
name|ProgramStateRef
name|notifyCheckersOfPointerEscape
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|const InvalidatedSymbols *Invalidated
argument_list|,
argument|ArrayRef<const MemRegion *> ExplicitRegions
argument_list|,
argument|ArrayRef<const MemRegion *> Regions
argument_list|,
argument|const CallEvent *Call
argument_list|,
argument|RegionAndSymbolInvalidationTraits&ITraits
argument_list|)
name|override
block|;
name|public
operator|:
comment|// FIXME: 'tag' should be removed, and a LocationContext should be used
comment|// instead.
comment|// FIXME: Comment on the meaning of the arguments, when 'St' may not
comment|// be the same as Pred->state, and when 'location' may not be the
comment|// same as state->getLValue(Ex).
comment|/// Simulate a read of the result of Ex.
name|void
name|evalLoad
argument_list|(
argument|ExplodedNodeSet&Dst
argument_list|,
argument|const Expr *NodeEx
argument_list|,
comment|/* Eventually will be a CFGStmt */
argument|const Expr *BoundExpr
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|ProgramStateRef St
argument_list|,
argument|SVal location
argument_list|,
argument|const ProgramPointTag *tag = nullptr
argument_list|,
argument|QualType LoadTy = QualType()
argument_list|)
block|;
comment|// FIXME: 'tag' should be removed, and a LocationContext should be used
comment|// instead.
name|void
name|evalStore
argument_list|(
argument|ExplodedNodeSet&Dst
argument_list|,
argument|const Expr *AssignE
argument_list|,
argument|const Expr *StoreE
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|ProgramStateRef St
argument_list|,
argument|SVal TargetLV
argument_list|,
argument|SVal Val
argument_list|,
argument|const ProgramPointTag *tag = nullptr
argument_list|)
block|;
comment|/// \brief Create a new state in which the call return value is binded to the
comment|/// call origin expression.
name|ProgramStateRef
name|bindReturnValue
argument_list|(
argument|const CallEvent&Call
argument_list|,
argument|const LocationContext *LCtx
argument_list|,
argument|ProgramStateRef State
argument_list|)
block|;
comment|/// Evaluate a call, running pre- and post-call checks and allowing checkers
comment|/// to be responsible for handling the evaluation of the call itself.
name|void
name|evalCall
argument_list|(
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
specifier|const
name|CallEvent
operator|&
name|Call
argument_list|)
block|;
comment|/// \brief Default implementation of call evaluation.
name|void
name|defaultEvalCall
argument_list|(
name|NodeBuilder
operator|&
name|B
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
specifier|const
name|CallEvent
operator|&
name|Call
argument_list|)
block|;
name|private
operator|:
name|void
name|evalLoadCommon
argument_list|(
argument|ExplodedNodeSet&Dst
argument_list|,
argument|const Expr *NodeEx
argument_list|,
comment|/* Eventually will be a CFGStmt */
argument|const Expr *BoundEx
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|ProgramStateRef St
argument_list|,
argument|SVal location
argument_list|,
argument|const ProgramPointTag *tag
argument_list|,
argument|QualType LoadTy
argument_list|)
block|;
comment|// FIXME: 'tag' should be removed, and a LocationContext should be used
comment|// instead.
name|void
name|evalLocation
argument_list|(
argument|ExplodedNodeSet&Dst
argument_list|,
argument|const Stmt *NodeEx
argument_list|,
comment|/* This will eventually be a CFGStmt */
argument|const Stmt *BoundEx
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|ProgramStateRef St
argument_list|,
argument|SVal location
argument_list|,
argument|const ProgramPointTag *tag
argument_list|,
argument|bool isLoad
argument_list|)
block|;
comment|/// Count the stack depth and determine if the call is recursive.
name|void
name|examineStackFrames
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|,
specifier|const
name|LocationContext
operator|*
name|LCtx
argument_list|,
name|bool
operator|&
name|IsRecursive
argument_list|,
name|unsigned
operator|&
name|StackDepth
argument_list|)
block|;
comment|/// Checks our policies and decides weither the given call should be inlined.
name|bool
name|shouldInlineCall
argument_list|(
specifier|const
name|CallEvent
operator|&
name|Call
argument_list|,
specifier|const
name|Decl
operator|*
name|D
argument_list|,
specifier|const
name|ExplodedNode
operator|*
name|Pred
argument_list|)
block|;
name|bool
name|inlineCall
argument_list|(
argument|const CallEvent&Call
argument_list|,
argument|const Decl *D
argument_list|,
argument|NodeBuilder&Bldr
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|ProgramStateRef State
argument_list|)
block|;
comment|/// \brief Conservatively evaluate call by invalidating regions and binding
comment|/// a conjured return value.
name|void
name|conservativeEvalCall
argument_list|(
argument|const CallEvent&Call
argument_list|,
argument|NodeBuilder&Bldr
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|ProgramStateRef State
argument_list|)
block|;
comment|/// \brief Either inline or process the call conservatively (or both), based
comment|/// on DynamicDispatchBifurcation data.
name|void
name|BifurcateCall
argument_list|(
specifier|const
name|MemRegion
operator|*
name|BifurReg
argument_list|,
specifier|const
name|CallEvent
operator|&
name|Call
argument_list|,
specifier|const
name|Decl
operator|*
name|D
argument_list|,
name|NodeBuilder
operator|&
name|Bldr
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|)
block|;
name|bool
name|replayWithoutInlining
argument_list|(
name|ExplodedNode
operator|*
name|P
argument_list|,
specifier|const
name|LocationContext
operator|*
name|CalleeLC
argument_list|)
block|;
comment|/// Models a trivial copy or move constructor or trivial assignment operator
comment|/// call with a simple bind.
name|void
name|performTrivialCopy
argument_list|(
name|NodeBuilder
operator|&
name|Bldr
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|,
specifier|const
name|CallEvent
operator|&
name|Call
argument_list|)
block|;
comment|/// If the value of the given expression \p InitWithAdjustments is a NonLoc,
comment|/// copy it into a new temporary object region, and replace the value of the
comment|/// expression with that.
comment|///
comment|/// If \p Result is provided, the new region will be bound to this expression
comment|/// instead of \p InitWithAdjustments.
name|ProgramStateRef
name|createTemporaryRegionIfNeeded
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|const LocationContext *LC
argument_list|,
argument|const Expr *InitWithAdjustments
argument_list|,
argument|const Expr *Result = nullptr
argument_list|)
block|;
comment|/// For a DeclStmt or CXXInitCtorInitializer, walk backward in the current CFG
comment|/// block to find the constructor expression that directly constructed into
comment|/// the storage for this statement. Returns null if the constructor for this
comment|/// statement created a temporary object region rather than directly
comment|/// constructing into an existing region.
specifier|const
name|CXXConstructExpr
operator|*
name|findDirectConstructorForCurrentCFGElement
argument_list|()
block|;
comment|/// For a CXXConstructExpr, walk forward in the current CFG block to find the
comment|/// CFGElement for the DeclStmt or CXXInitCtorInitializer for which is
comment|/// directly constructed by this constructor. Returns None if the current
comment|/// constructor expression did not directly construct into an existing
comment|/// region.
name|Optional
operator|<
name|CFGElement
operator|>
name|findElementDirectlyInitializedByCurrentConstructor
argument_list|()
block|;
comment|/// For a given constructor, look forward in the current CFG block to
comment|/// determine the region into which an object will be constructed by \p CE.
comment|/// Returns either a field or local variable region if the object will be
comment|/// directly constructed in an existing region or a temporary object region
comment|/// if not.
specifier|const
name|MemRegion
operator|*
name|getRegionForConstructedObject
argument_list|(
specifier|const
name|CXXConstructExpr
operator|*
name|CE
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|)
block|; }
decl_stmt|;
comment|/// Traits for storing the call processing policy inside GDM.
comment|/// The GDM stores the corresponding CallExpr pointer.
comment|// FIXME: This does not use the nice trait macros because it must be accessible
comment|// from multiple translation units.
struct|struct
name|ReplayWithoutInlining
block|{}
struct|;
name|template
operator|<
operator|>
expr|struct
name|ProgramStateTrait
operator|<
name|ReplayWithoutInlining
operator|>
operator|:
name|public
name|ProgramStatePartialTrait
operator|<
specifier|const
name|void
operator|*
operator|>
block|{
specifier|static
name|void
operator|*
name|GDMIndex
argument_list|()
block|{
specifier|static
name|int
name|index
operator|=
literal|0
block|;
return|return
operator|&
name|index
return|;
block|}
expr|}
block|;  }
comment|// end ento namespace
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

