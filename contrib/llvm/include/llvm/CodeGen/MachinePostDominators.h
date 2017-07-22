begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- llvm/CodeGen/MachineDominators.h ----------------------------*- C++ -*-==//
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
comment|// This file exposes interfaces to post dominance information for
end_comment

begin_comment
comment|// target-specific code.
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
name|LLVM_CODEGEN_MACHINEPOSTDOMINATORS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEPOSTDOMINATORS_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineDominators.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|///
comment|/// PostDominatorTree Class - Concrete subclass of DominatorTree that is used
comment|/// to compute the post-dominator tree.
comment|///
name|struct
name|MachinePostDominatorTree
range|:
name|public
name|MachineFunctionPass
block|{
name|private
operator|:
name|PostDomTreeBase
operator|<
name|MachineBasicBlock
operator|>
operator|*
name|DT
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|MachinePostDominatorTree
argument_list|()
block|;
operator|~
name|MachinePostDominatorTree
argument_list|()
name|override
block|;
name|FunctionPass
operator|*
name|createMachinePostDominatorTreePass
argument_list|()
block|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|MachineBasicBlock
operator|*
operator|>
operator|&
name|getRoots
argument_list|()
specifier|const
block|{
return|return
name|DT
operator|->
name|getRoots
argument_list|()
return|;
block|}
name|MachineDomTreeNode
operator|*
name|getRootNode
argument_list|()
specifier|const
block|{
return|return
name|DT
operator|->
name|getRootNode
argument_list|()
return|;
block|}
name|MachineDomTreeNode
operator|*
name|operator
index|[]
operator|(
name|MachineBasicBlock
operator|*
name|BB
operator|)
specifier|const
block|{
return|return
name|DT
operator|->
name|getNode
argument_list|(
name|BB
argument_list|)
return|;
block|}
name|MachineDomTreeNode
operator|*
name|getNode
argument_list|(
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|{
return|return
name|DT
operator|->
name|getNode
argument_list|(
name|BB
argument_list|)
return|;
block|}
name|bool
name|dominates
argument_list|(
argument|const MachineDomTreeNode *A
argument_list|,
argument|const MachineDomTreeNode *B
argument_list|)
specifier|const
block|{
return|return
name|DT
operator|->
name|dominates
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
name|bool
name|dominates
argument_list|(
argument|const MachineBasicBlock *A
argument_list|,
argument|const MachineBasicBlock *B
argument_list|)
specifier|const
block|{
return|return
name|DT
operator|->
name|dominates
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
name|bool
name|properlyDominates
argument_list|(
argument|const MachineDomTreeNode *A
argument_list|,
argument|const MachineDomTreeNode *B
argument_list|)
specifier|const
block|{
return|return
name|DT
operator|->
name|properlyDominates
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
name|bool
name|properlyDominates
argument_list|(
argument|const MachineBasicBlock *A
argument_list|,
argument|const MachineBasicBlock *B
argument_list|)
specifier|const
block|{
return|return
name|DT
operator|->
name|properlyDominates
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
name|MachineBasicBlock
operator|*
name|findNearestCommonDominator
argument_list|(
argument|MachineBasicBlock *A
argument_list|,
argument|MachineBasicBlock *B
argument_list|)
block|{
return|return
name|DT
operator|->
name|findNearestCommonDominator
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
name|void
name|print
argument_list|(
argument|llvm::raw_ostream&OS
argument_list|,
argument|const Module *M = nullptr
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|//end of namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

