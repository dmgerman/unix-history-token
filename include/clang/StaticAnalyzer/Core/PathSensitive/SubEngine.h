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
name|template
operator|<
name|typename
name|PP
operator|>
name|class
name|GenericNodeBuilder
expr_stmt|;
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
name|GRState
decl_stmt|;
name|class
name|GRStateManager
decl_stmt|;
name|class
name|BlockCounter
decl_stmt|;
name|class
name|StmtNodeBuilder
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
name|CallEnterNodeBuilder
decl_stmt|;
name|class
name|CallExitNodeBuilder
decl_stmt|;
name|class
name|MemRegion
decl_stmt|;
name|class
name|SubEngine
block|{
name|public
label|:
name|virtual
operator|~
name|SubEngine
argument_list|()
block|{}
name|virtual
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
name|GRStateManager
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
name|StmtNodeBuilder
modifier|&
name|builder
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
init|=
literal|0
decl_stmt|;
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
name|BranchNodeBuilder
modifier|&
name|builder
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
name|EndOfFunctionNodeBuilder
modifier|&
name|builder
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Generate the entry node of the callee.
name|virtual
name|void
name|processCallEnter
parameter_list|(
name|CallEnterNodeBuilder
modifier|&
name|builder
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Generate the first post callsite node.
name|virtual
name|void
name|processCallExit
parameter_list|(
name|CallExitNodeBuilder
modifier|&
name|builder
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Called by ConstraintManager. Used to call checker-specific
comment|/// logic for handling assumptions on symbolic values.
name|virtual
specifier|const
name|GRState
modifier|*
name|processAssume
parameter_list|(
specifier|const
name|GRState
modifier|*
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
comment|/// wantsRegionChangeUpdate - Called by GRStateManager to determine if a
comment|///  region change should trigger a processRegionChanges update.
name|virtual
name|bool
name|wantsRegionChangeUpdate
parameter_list|(
specifier|const
name|GRState
modifier|*
name|state
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// processRegionChanges - Called by GRStateManager whenever a change is made
comment|///  to the store. Used to update checkers that track region values.
name|virtual
specifier|const
name|GRState
modifier|*
name|processRegionChanges
parameter_list|(
specifier|const
name|GRState
modifier|*
name|state
parameter_list|,
specifier|const
name|MemRegion
modifier|*
specifier|const
modifier|*
name|Begin
parameter_list|,
specifier|const
name|MemRegion
modifier|*
specifier|const
modifier|*
name|End
parameter_list|)
init|=
literal|0
function_decl|;
specifier|inline
specifier|const
name|GRState
modifier|*
name|processRegionChange
parameter_list|(
specifier|const
name|GRState
modifier|*
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
operator|&
name|MR
argument_list|,
operator|&
name|MR
operator|+
literal|1
argument_list|)
return|;
block|}
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

