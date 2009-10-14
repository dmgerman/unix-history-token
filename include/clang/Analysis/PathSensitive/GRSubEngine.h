begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== GRSubEngine.h - Interface of the subengine of GRCoreEngine ----*- C++ -*-//
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
comment|// This file defines the interface of a subengine of the GRCoreEngine.
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
name|LLVM_CLANG_ANALYSIS_GRSUBENGINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_GRSUBENGINE_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Stmt
decl_stmt|;
name|class
name|CFGBlock
decl_stmt|;
name|class
name|GRState
decl_stmt|;
name|class
name|GRStateManager
decl_stmt|;
name|class
name|GRBlockCounter
decl_stmt|;
name|class
name|GRStmtNodeBuilder
decl_stmt|;
name|class
name|GRBranchNodeBuilder
decl_stmt|;
name|class
name|GRIndirectGotoNodeBuilder
decl_stmt|;
name|class
name|GRSwitchNodeBuilder
decl_stmt|;
name|class
name|GREndPathNodeBuilder
decl_stmt|;
name|class
name|LocationContext
decl_stmt|;
name|class
name|GRSubEngine
block|{
name|public
label|:
name|virtual
operator|~
name|GRSubEngine
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
name|GRStateManager
modifier|&
name|getStateManager
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// ProcessStmt - Called by GRCoreEngine. Used to generate new successor
comment|///  nodes by processing the 'effects' of a block-level statement.
name|virtual
name|void
name|ProcessStmt
parameter_list|(
name|Stmt
modifier|*
name|S
parameter_list|,
name|GRStmtNodeBuilder
modifier|&
name|builder
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// ProcessBlockEntrance - Called by GRCoreEngine when start processing
comment|///  a CFGBlock.  This method returns true if the analysis should continue
comment|///  exploring the given path, and false otherwise.
name|virtual
name|bool
name|ProcessBlockEntrance
parameter_list|(
name|CFGBlock
modifier|*
name|B
parameter_list|,
specifier|const
name|GRState
modifier|*
name|St
parameter_list|,
name|GRBlockCounter
name|BC
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// ProcessBranch - Called by GRCoreEngine.  Used to generate successor
comment|///  nodes by processing the 'effects' of a branch condition.
name|virtual
name|void
name|ProcessBranch
parameter_list|(
name|Stmt
modifier|*
name|Condition
parameter_list|,
name|Stmt
modifier|*
name|Term
parameter_list|,
name|GRBranchNodeBuilder
modifier|&
name|builder
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// ProcessIndirectGoto - Called by GRCoreEngine.  Used to generate successor
comment|///  nodes by processing the 'effects' of a computed goto jump.
name|virtual
name|void
name|ProcessIndirectGoto
parameter_list|(
name|GRIndirectGotoNodeBuilder
modifier|&
name|builder
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// ProcessSwitch - Called by GRCoreEngine.  Used to generate successor
comment|///  nodes by processing the 'effects' of a switch statement.
name|virtual
name|void
name|ProcessSwitch
parameter_list|(
name|GRSwitchNodeBuilder
modifier|&
name|builder
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// ProcessEndPath - Called by GRCoreEngine.  Used to generate end-of-path
comment|///  nodes when the control reaches the end of a function.
name|virtual
name|void
name|ProcessEndPath
parameter_list|(
name|GREndPathNodeBuilder
modifier|&
name|builder
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

