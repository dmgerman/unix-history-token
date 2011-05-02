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
name|LLVM_CLANG_GR_EXPRENGINE
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_GR_EXPRENGINE
end_define

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/AnalysisManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/SubEngine.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/CoreEngine.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/GRState.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/TransferFuncs.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/BugReporter/BugReporter.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExprObjC.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExprCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/StmtObjC.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
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
name|ExprEngine
range|:
name|public
name|SubEngine
block|{
name|AnalysisManager
operator|&
name|AMgr
block|;
name|CoreEngine
name|Engine
block|;
comment|/// G - the simulation graph.
name|ExplodedGraph
operator|&
name|G
block|;
comment|/// Builder - The current StmtNodeBuilder which is used when building the
comment|///  nodes for a given statement.
name|StmtNodeBuilder
operator|*
name|Builder
block|;
comment|/// StateMgr - Object that manages the data for all created states.
name|GRStateManager
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
comment|/// EntryNode - The immediate predecessor node.
name|ExplodedNode
operator|*
name|EntryNode
block|;
comment|/// CleanedState - The state for EntryNode "cleaned" of all dead
comment|///  variables and symbols (as determined by a liveness analysis).
specifier|const
name|GRState
operator|*
name|CleanedState
block|;
comment|/// currentStmt - The current block-level statement.
specifier|const
name|Stmt
operator|*
name|currentStmt
block|;
comment|// Obj-C Class Identifiers.
name|IdentifierInfo
operator|*
name|NSExceptionII
block|;
comment|// Obj-C Selectors.
name|Selector
operator|*
name|NSExceptionInstanceRaiseSelectors
block|;
name|Selector
name|RaiseSel
block|;
comment|/// The BugReporter associated with this engine.  It is important that
comment|///  this object be placed at the very end of member variables so that its
comment|///  destructor is called before the rest of the ExprEngine is destroyed.
name|GRBugReporter
name|BR
block|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|TransferFuncs
operator|>
name|TF
block|;
name|public
operator|:
name|ExprEngine
argument_list|(
name|AnalysisManager
operator|&
name|mgr
argument_list|,
name|TransferFuncs
operator|*
name|tf
argument_list|)
block|;
operator|~
name|ExprEngine
argument_list|()
block|;
name|void
name|ExecuteWorkList
argument_list|(
argument|const LocationContext *L
argument_list|,
argument|unsigned Steps =
literal|150000
argument_list|)
block|{
name|Engine
operator|.
name|ExecuteWorkList
argument_list|(
name|L
argument_list|,
name|Steps
argument_list|,
literal|0
argument_list|)
block|;   }
comment|/// Execute the work list with an initial state. Nodes that reaches the exit
comment|/// of the function are added into the Dst set, which represent the exit
comment|/// state of the function call.
name|void
name|ExecuteWorkListWithInitialState
argument_list|(
argument|const LocationContext *L
argument_list|,
argument|unsigned Steps
argument_list|,
argument|const GRState *InitState
argument_list|,
argument|ExplodedNodeSet&Dst
argument_list|)
block|{
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
block|;   }
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
name|virtual
name|AnalysisManager
operator|&
name|getAnalysisManager
argument_list|()
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
name|TransferFuncs
operator|&
name|getTF
argument_list|()
block|{
return|return
operator|*
name|TF
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
name|StmtNodeBuilder
operator|&
name|getBuilder
argument_list|()
block|{
name|assert
argument_list|(
name|Builder
argument_list|)
block|;
return|return
operator|*
name|Builder
return|;
block|}
comment|// FIXME: Remove once TransferFuncs is no longer referenced.
name|void
name|setTransferFunction
argument_list|(
name|TransferFuncs
operator|*
name|tf
argument_list|)
block|;
comment|/// ViewGraph - Visualize the ExplodedGraph created by executing the
comment|///  simulation.
name|void
name|ViewGraph
argument_list|(
argument|bool trim = false
argument_list|)
block|;
name|void
name|ViewGraph
argument_list|(
name|ExplodedNode
operator|*
operator|*
name|Beg
argument_list|,
name|ExplodedNode
operator|*
operator|*
name|End
argument_list|)
block|;
comment|/// getInitialState - Return the initial state used for the root vertex
comment|///  in the ExplodedGraph.
specifier|const
name|GRState
operator|*
name|getInitialState
argument_list|(
specifier|const
name|LocationContext
operator|*
name|InitLoc
argument_list|)
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
comment|/// processCFGElement - Called by CoreEngine. Used to generate new successor
comment|///  nodes by processing the 'effects' of a CFG element.
name|void
name|processCFGElement
argument_list|(
argument|const CFGElement E
argument_list|,
argument|StmtNodeBuilder& builder
argument_list|)
block|;
name|void
name|ProcessStmt
argument_list|(
argument|const CFGStmt S
argument_list|,
argument|StmtNodeBuilder&builder
argument_list|)
block|;
name|void
name|ProcessInitializer
argument_list|(
argument|const CFGInitializer I
argument_list|,
argument|StmtNodeBuilder&builder
argument_list|)
block|;
name|void
name|ProcessImplicitDtor
argument_list|(
argument|const CFGImplicitDtor D
argument_list|,
argument|StmtNodeBuilder&builder
argument_list|)
block|;
name|void
name|ProcessAutomaticObjDtor
argument_list|(
argument|const CFGAutomaticObjDtor D
argument_list|,
argument|StmtNodeBuilder&builder
argument_list|)
block|;
name|void
name|ProcessBaseDtor
argument_list|(
argument|const CFGBaseDtor D
argument_list|,
argument|StmtNodeBuilder&builder
argument_list|)
block|;
name|void
name|ProcessMemberDtor
argument_list|(
argument|const CFGMemberDtor D
argument_list|,
argument|StmtNodeBuilder&builder
argument_list|)
block|;
name|void
name|ProcessTemporaryDtor
argument_list|(
argument|const CFGTemporaryDtor D
argument_list|,
argument|StmtNodeBuilder&builder
argument_list|)
block|;
comment|/// Called by CoreEngine when processing the entrance of a CFGBlock.
name|virtual
name|void
name|processCFGBlockEntrance
argument_list|(
name|ExplodedNodeSet
operator|&
name|dstNodes
argument_list|,
name|GenericNodeBuilder
operator|<
name|BlockEntrance
operator|>
operator|&
name|nodeBuilder
argument_list|)
block|;
comment|/// ProcessBranch - Called by CoreEngine.  Used to generate successor
comment|///  nodes by processing the 'effects' of a branch condition.
name|void
name|processBranch
argument_list|(
specifier|const
name|Stmt
operator|*
name|Condition
argument_list|,
specifier|const
name|Stmt
operator|*
name|Term
argument_list|,
name|BranchNodeBuilder
operator|&
name|builder
argument_list|)
block|;
comment|/// processIndirectGoto - Called by CoreEngine.  Used to generate successor
comment|///  nodes by processing the 'effects' of a computed goto jump.
name|void
name|processIndirectGoto
argument_list|(
name|IndirectGotoNodeBuilder
operator|&
name|builder
argument_list|)
block|;
comment|/// ProcessSwitch - Called by CoreEngine.  Used to generate successor
comment|///  nodes by processing the 'effects' of a switch statement.
name|void
name|processSwitch
argument_list|(
name|SwitchNodeBuilder
operator|&
name|builder
argument_list|)
block|;
comment|/// ProcessEndPath - Called by CoreEngine.  Used to generate end-of-path
comment|///  nodes when the control reaches the end of a function.
name|void
name|processEndOfFunction
argument_list|(
name|EndOfFunctionNodeBuilder
operator|&
name|builder
argument_list|)
block|;
comment|/// Generate the entry node of the callee.
name|void
name|processCallEnter
argument_list|(
name|CallEnterNodeBuilder
operator|&
name|builder
argument_list|)
block|;
comment|/// Generate the first post callsite node.
name|void
name|processCallExit
argument_list|(
name|CallExitNodeBuilder
operator|&
name|builder
argument_list|)
block|;
comment|/// Called by CoreEngine when the analysis worklist has terminated.
name|void
name|processEndWorklist
argument_list|(
argument|bool hasWorkRemaining
argument_list|)
block|;
comment|/// evalAssume - Callback function invoked by the ConstraintManager when
comment|///  making assumptions about state values.
specifier|const
name|GRState
operator|*
name|processAssume
argument_list|(
argument|const GRState *state
argument_list|,
argument|SVal cond
argument_list|,
argument|bool assumption
argument_list|)
block|;
comment|/// wantsRegionChangeUpdate - Called by GRStateManager to determine if a
comment|///  region change should trigger a processRegionChanges update.
name|bool
name|wantsRegionChangeUpdate
argument_list|(
specifier|const
name|GRState
operator|*
name|state
argument_list|)
block|;
comment|/// processRegionChanges - Called by GRStateManager whenever a change is made
comment|///  to the store. Used to update checkers that track region values.
specifier|const
name|GRState
operator|*
name|processRegionChanges
argument_list|(
specifier|const
name|GRState
operator|*
name|state
argument_list|,
specifier|const
name|MemRegion
operator|*
specifier|const
operator|*
name|Begin
argument_list|,
specifier|const
name|MemRegion
operator|*
specifier|const
operator|*
name|End
argument_list|)
block|;
name|virtual
name|GRStateManager
operator|&
name|getStateManager
argument_list|()
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
specifier|const
name|BasicValueFactory
operator|&
name|getBasicVals
argument_list|()
specifier|const
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
name|protected
operator|:
specifier|const
name|GRState
operator|*
name|GetState
argument_list|(
argument|ExplodedNode* N
argument_list|)
block|{
return|return
name|N
operator|==
name|EntryNode
operator|?
name|CleanedState
operator|:
name|N
operator|->
name|getState
argument_list|()
return|;
block|}
name|public
operator|:
name|ExplodedNode
operator|*
name|MakeNode
argument_list|(
argument|ExplodedNodeSet& Dst
argument_list|,
argument|const Stmt* S
argument_list|,
argument|ExplodedNode* Pred
argument_list|,
argument|const GRState* St
argument_list|,
argument|ProgramPoint::Kind K = ProgramPoint::PostStmtKind
argument_list|,
argument|const void *tag =
literal|0
argument_list|)
block|;
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
comment|/// VisitAsmStmt - Transfer function logic for inline asm.
name|void
name|VisitAsmStmt
argument_list|(
specifier|const
name|AsmStmt
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
name|void
name|VisitAsmStmtHelperOutputs
argument_list|(
argument|const AsmStmt* A
argument_list|,
argument|AsmStmt::const_outputs_iterator I
argument_list|,
argument|AsmStmt::const_outputs_iterator E
argument_list|,
argument|ExplodedNode* Pred
argument_list|,
argument|ExplodedNodeSet& Dst
argument_list|)
block|;
name|void
name|VisitAsmStmtHelperInputs
argument_list|(
argument|const AsmStmt* A
argument_list|,
argument|AsmStmt::const_inputs_iterator I
argument_list|,
argument|AsmStmt::const_inputs_iterator E
argument_list|,
argument|ExplodedNode* Pred
argument_list|,
argument|ExplodedNodeSet& Dst
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
name|void
name|VisitObjCPropertyRefExpr
argument_list|(
specifier|const
name|ObjCPropertyRefExpr
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
name|VisitObjCForCollectionStmtAux
argument_list|(
argument|const ObjCForCollectionStmt* S
argument_list|,
argument|ExplodedNode* Pred
argument_list|,
argument|ExplodedNodeSet& Dst
argument_list|,
argument|SVal ElementV
argument_list|)
block|;
comment|/// VisitObjCMessageExpr - Transfer function for ObjC message expressions.
name|void
name|VisitObjCMessageExpr
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
name|void
name|VisitObjCMessage
argument_list|(
specifier|const
name|ObjCMessage
operator|&
name|msg
argument_list|,
name|ExplodedNodeSet
operator|&
name|Src
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
name|VisitCXXTemporaryObjectExpr
argument_list|(
argument|const CXXTemporaryObjectExpr *expr
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|ExplodedNodeSet&Dst
argument_list|)
block|{
name|VisitCXXConstructExpr
argument_list|(
name|expr
argument_list|,
literal|0
argument_list|,
name|Pred
argument_list|,
name|Dst
argument_list|)
block|;   }
name|void
name|VisitCXXConstructExpr
argument_list|(
specifier|const
name|CXXConstructExpr
operator|*
name|E
argument_list|,
specifier|const
name|MemRegion
operator|*
name|Dest
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
specifier|const
name|CXXDestructorDecl
operator|*
name|DD
argument_list|,
specifier|const
name|MemRegion
operator|*
name|Dest
argument_list|,
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
name|void
name|VisitAggExpr
argument_list|(
specifier|const
name|Expr
operator|*
name|E
argument_list|,
specifier|const
name|MemRegion
operator|*
name|Dest
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
comment|/// Synthesize CXXThisRegion.
specifier|const
name|CXXThisRegion
operator|*
name|getCXXThisRegion
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|,
specifier|const
name|StackFrameContext
operator|*
name|SFC
argument_list|)
block|;
specifier|const
name|CXXThisRegion
operator|*
name|getCXXThisRegion
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|decl
argument_list|,
specifier|const
name|StackFrameContext
operator|*
name|frameCtx
argument_list|)
block|;
comment|/// Evaluate arguments with a work list algorithm.
name|void
name|evalArguments
argument_list|(
argument|ConstExprIterator AI
argument_list|,
argument|ConstExprIterator AE
argument_list|,
argument|const FunctionProtoType *FnType
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|ExplodedNodeSet&Dst
argument_list|,
argument|bool FstArgAsLValue = false
argument_list|)
block|;
comment|/// Evaluate callee expression (for a function call).
name|void
name|evalCallee
argument_list|(
specifier|const
name|CallExpr
operator|*
name|callExpr
argument_list|,
specifier|const
name|ExplodedNodeSet
operator|&
name|src
argument_list|,
name|ExplodedNodeSet
operator|&
name|dest
argument_list|)
block|;
comment|/// evalEagerlyAssume - Given the nodes in 'Src', eagerly assume symbolic
comment|///  expressions of the form 'x != 0' and generate new nodes (stored in Dst)
comment|///  with those assumptions.
name|void
name|evalEagerlyAssume
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
condition|?
name|svalBuilder
operator|.
name|evalMinus
argument_list|(
name|cast
operator|<
name|NonLoc
operator|>
operator|(
name|X
operator|)
argument_list|)
else|:
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
name|cast
operator|<
name|NonLoc
operator|>
operator|(
name|X
operator|)
argument_list|)
else|:
name|X
return|;
block|}
name|public
operator|:
name|SVal
name|evalBinOp
argument_list|(
argument|const GRState *state
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
argument|const GRState *state
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
name|cast
operator|<
name|NonLoc
operator|>
operator|(
name|R
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
argument|const GRState *ST
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
name|void
name|evalObjCMessage
argument_list|(
argument|ExplodedNodeSet& Dst
argument_list|,
argument|const ObjCMessage&msg
argument_list|,
argument|ExplodedNode* Pred
argument_list|,
argument|const GRState *state
argument_list|)
block|{
name|assert
argument_list|(
name|Builder
operator|&&
literal|"StmtNodeBuilder must be defined."
argument_list|)
block|;
name|getTF
argument_list|()
operator|.
name|evalObjCMessage
argument_list|(
name|Dst
argument_list|,
operator|*
name|this
argument_list|,
operator|*
name|Builder
argument_list|,
name|msg
argument_list|,
name|Pred
argument_list|,
name|state
argument_list|)
block|;   }
specifier|const
name|GRState
operator|*
name|MarkBranch
argument_list|(
argument|const GRState* St
argument_list|,
argument|const Stmt* Terminator
argument_list|,
argument|bool branchTaken
argument_list|)
block|;
comment|/// evalBind - Handle the semantics of binding a value to a specific location.
comment|///  This method is used by evalStore, VisitDeclStmt, and others.
name|void
name|evalBind
argument_list|(
argument|ExplodedNodeSet& Dst
argument_list|,
argument|const Stmt* StoreE
argument_list|,
argument|ExplodedNode* Pred
argument_list|,
argument|const GRState* St
argument_list|,
argument|SVal location
argument_list|,
argument|SVal Val
argument_list|,
argument|bool atDeclInit = false
argument_list|)
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
argument|ExplodedNodeSet& Dst
argument_list|,
argument|const Expr* Ex
argument_list|,
argument|ExplodedNode* Pred
argument_list|,
argument|const GRState* St
argument_list|,
argument|SVal location
argument_list|,
argument|const void *tag =
literal|0
argument_list|,
argument|QualType LoadTy = QualType()
argument_list|)
block|;
comment|// FIXME: 'tag' should be removed, and a LocationContext should be used
comment|// instead.
name|void
name|evalStore
argument_list|(
argument|ExplodedNodeSet& Dst
argument_list|,
argument|const Expr* AssignE
argument_list|,
argument|const Expr* StoreE
argument_list|,
argument|ExplodedNode* Pred
argument_list|,
argument|const GRState* St
argument_list|,
argument|SVal TargetLV
argument_list|,
argument|SVal Val
argument_list|,
argument|const void *tag =
literal|0
argument_list|)
block|;
name|private
operator|:
name|void
name|evalLoadCommon
argument_list|(
argument|ExplodedNodeSet& Dst
argument_list|,
argument|const Expr* Ex
argument_list|,
argument|ExplodedNode* Pred
argument_list|,
argument|const GRState* St
argument_list|,
argument|SVal location
argument_list|,
argument|const void *tag
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
argument|const Stmt *S
argument_list|,
argument|ExplodedNode* Pred
argument_list|,
argument|const GRState* St
argument_list|,
argument|SVal location
argument_list|,
argument|const void *tag
argument_list|,
argument|bool isLoad
argument_list|)
block|;
name|bool
name|InlineCall
argument_list|(
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|,
specifier|const
name|CallExpr
operator|*
name|CE
argument_list|,
name|ExplodedNode
operator|*
name|Pred
argument_list|)
block|; }
decl_stmt|;
block|}
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

