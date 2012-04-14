begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== SubEngine.h - Interface of the subengine of CoreEngine --------*- C++ -*-//
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
comment|// This file defines the interface of a subengine of the CoreEngine.
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
name|LLVM_CLANG_GR_SUBENGINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_GR_SUBENGINE_H
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/ProgramPoint.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/SVals.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/Store.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CFGBlock
decl_stmt|;
name|class
name|CFGElement
decl_stmt|;
name|class
name|LocationContext
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|namespace
name|ento
block|{
struct_decl|struct
name|NodeBuilderContext
struct_decl|;
name|class
name|AnalysisManager
decl_stmt|;
name|class
name|ExplodedNodeSet
decl_stmt|;
name|class
name|ExplodedNode
decl_stmt|;
name|class
name|ProgramState
decl_stmt|;
name|class
name|ProgramStateManager
decl_stmt|;
name|class
name|BlockCounter
decl_stmt|;
name|class
name|BranchNodeBuilder
decl_stmt|;
name|class
name|IndirectGotoNodeBuilder
decl_stmt|;
name|class
name|SwitchNodeBuilder
decl_stmt|;
name|class
name|EndOfFunctionNodeBuilder
decl_stmt|;
name|class
name|NodeBuilderWithSinks
decl_stmt|;
name|class
name|MemRegion
decl_stmt|;
name|class
name|SubEngine
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
name|virtual
operator|~
name|SubEngine
argument_list|()
block|{}
name|virtual
name|ProgramStateRef
name|getInitialState
argument_list|(
specifier|const
name|LocationContext
operator|*
name|InitLoc
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|AnalysisManager
modifier|&
name|getAnalysisManager
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|ProgramStateManager
modifier|&
name|getStateManager
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// Called by CoreEngine. Used to generate new successor
comment|/// nodes by processing the 'effects' of a block-level statement.
name|virtual
name|void
name|processCFGElement
parameter_list|(
specifier|const
name|CFGElement
name|E
parameter_list|,
name|ExplodedNode
modifier|*
name|Pred
parameter_list|,
name|unsigned
name|StmtIdx
parameter_list|,
name|NodeBuilderContext
modifier|*
name|Ctx
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Called by CoreEngine when it starts processing a CFGBlock.  The
comment|/// SubEngine is expected to populate dstNodes with new nodes representing
comment|/// updated analysis state, or generate no nodes at all if it doesn't.
name|virtual
name|void
name|processCFGBlockEntrance
parameter_list|(
specifier|const
name|BlockEdge
modifier|&
name|L
parameter_list|,
name|NodeBuilderWithSinks
modifier|&
name|nodeBuilder
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Called by CoreEngine.  Used to generate successor
comment|///  nodes by processing the 'effects' of a branch condition.
name|virtual
name|void
name|processBranch
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|Condition
parameter_list|,
specifier|const
name|Stmt
modifier|*
name|Term
parameter_list|,
name|NodeBuilderContext
modifier|&
name|BuilderCtx
parameter_list|,
name|ExplodedNode
modifier|*
name|Pred
parameter_list|,
name|ExplodedNodeSet
modifier|&
name|Dst
parameter_list|,
specifier|const
name|CFGBlock
modifier|*
name|DstT
parameter_list|,
specifier|const
name|CFGBlock
modifier|*
name|DstF
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Called by CoreEngine.  Used to generate successor
comment|/// nodes by processing the 'effects' of a computed goto jump.
name|virtual
name|void
name|processIndirectGoto
parameter_list|(
name|IndirectGotoNodeBuilder
modifier|&
name|builder
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Called by CoreEngine.  Used to generate successor
comment|/// nodes by processing the 'effects' of a switch statement.
name|virtual
name|void
name|processSwitch
parameter_list|(
name|SwitchNodeBuilder
modifier|&
name|builder
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Called by CoreEngine.  Used to generate end-of-path
comment|/// nodes when the control reaches the end of a function.
name|virtual
name|void
name|processEndOfFunction
parameter_list|(
name|NodeBuilderContext
modifier|&
name|BC
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Generate the entry node of the callee.
name|virtual
name|void
name|processCallEnter
parameter_list|(
name|CallEnter
name|CE
parameter_list|,
name|ExplodedNode
modifier|*
name|Pred
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Generate the first post callsite node.
name|virtual
name|void
name|processCallExit
parameter_list|(
name|ExplodedNode
modifier|*
name|Pred
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Called by ConstraintManager. Used to call checker-specific
comment|/// logic for handling assumptions on symbolic values.
name|virtual
name|ProgramStateRef
name|processAssume
parameter_list|(
name|ProgramStateRef
name|state
parameter_list|,
name|SVal
name|cond
parameter_list|,
name|bool
name|assumption
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// wantsRegionChangeUpdate - Called by ProgramStateManager to determine if a
comment|///  region change should trigger a processRegionChanges update.
name|virtual
name|bool
name|wantsRegionChangeUpdate
parameter_list|(
name|ProgramStateRef
name|state
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// processRegionChanges - Called by ProgramStateManager whenever a change is
comment|/// made to the store. Used to update checkers that track region values.
name|virtual
name|ProgramStateRef
name|processRegionChanges
argument_list|(
name|ProgramStateRef
name|state
argument_list|,
specifier|const
name|StoreManager
operator|::
name|InvalidatedSymbols
operator|*
name|invalidated
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|MemRegion
operator|*
operator|>
name|ExplicitRegions
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|MemRegion
operator|*
operator|>
name|Regions
argument_list|,
specifier|const
name|CallOrObjCMessage
operator|*
name|Call
argument_list|)
init|=
literal|0
decl_stmt|;
specifier|inline
name|ProgramStateRef
name|processRegionChange
parameter_list|(
name|ProgramStateRef
name|state
parameter_list|,
specifier|const
name|MemRegion
modifier|*
name|MR
parameter_list|)
block|{
return|return
name|processRegionChanges
argument_list|(
name|state
argument_list|,
literal|0
argument_list|,
name|MR
argument_list|,
name|MR
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|/// printState - Called by ProgramStateManager to print checker-specific data.
name|virtual
name|void
name|printState
parameter_list|(
name|raw_ostream
modifier|&
name|Out
parameter_list|,
name|ProgramStateRef
name|State
parameter_list|,
specifier|const
name|char
modifier|*
name|NL
parameter_list|,
specifier|const
name|char
modifier|*
name|Sep
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Called by CoreEngine when the analysis worklist is either empty or the
comment|//  maximum number of analysis steps have been reached.
name|virtual
name|void
name|processEndWorklist
parameter_list|(
name|bool
name|hasWorkRemaining
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
comment|// end GR namespace
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

