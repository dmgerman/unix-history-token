begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- MachineBranchProbabilityInfo.h - Branch Probability Analysis -*- C++ -*-=//
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
comment|// This pass is used to evaluate branch probabilties on machine basic blocks.
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
name|LLVM_CODEGEN_MACHINEBRANCHPROBABILITYINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEBRANCHPROBABILITYINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BranchProbability.h"
end_include

begin_include
include|#
directive|include
file|<climits>
end_include

begin_include
include|#
directive|include
file|<numeric>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineBranchProbabilityInfo
range|:
name|public
name|ImmutablePass
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|// Default weight value. Used when we don't have information about the edge.
comment|// TODO: DEFAULT_WEIGHT makes sense during static predication, when none of
comment|// the successors have a weight yet. But it doesn't make sense when providing
comment|// weight to an edge that may have siblings with non-zero weights. This can
comment|// be handled various ways, but it's probably fine for an edge with unknown
comment|// weight to just "inherit" the non-zero weight of an adjacent successor.
specifier|static
specifier|const
name|uint32_t
name|DEFAULT_WEIGHT
operator|=
literal|16
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|MachineBranchProbabilityInfo
argument_list|()
operator|:
name|ImmutablePass
argument_list|(
argument|ID
argument_list|)
block|{
name|PassRegistry
operator|&
name|Registry
operator|=
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
block|;
name|initializeMachineBranchProbabilityInfoPass
argument_list|(
name|Registry
argument_list|)
block|;   }
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|{
name|AU
operator|.
name|setPreservesAll
argument_list|()
block|;   }
comment|// Return edge probability.
name|BranchProbability
name|getEdgeProbability
argument_list|(
argument|const MachineBasicBlock *Src
argument_list|,
argument|const MachineBasicBlock *Dst
argument_list|)
specifier|const
block|;
comment|// Same as above, but using a const_succ_iterator from Src. This is faster
comment|// when the iterator is already available.
name|BranchProbability
name|getEdgeProbability
argument_list|(
argument|const MachineBasicBlock *Src
argument_list|,
argument|MachineBasicBlock::const_succ_iterator Dst
argument_list|)
specifier|const
block|;
comment|// A 'Hot' edge is an edge which probability is>= 80%.
name|bool
name|isEdgeHot
argument_list|(
argument|const MachineBasicBlock *Src
argument_list|,
argument|const MachineBasicBlock *Dst
argument_list|)
specifier|const
block|;
comment|// Return a hot successor for the block BB or null if there isn't one.
comment|// NB: This routine's complexity is linear on the number of successors.
name|MachineBasicBlock
operator|*
name|getHotSucc
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
comment|// Print value between 0 (0% probability) and 1 (100% probability),
comment|// however the value is never equal to 0, and can be 1 only iff SRC block
comment|// has only one successor.
name|raw_ostream
operator|&
name|printEdgeProbability
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const MachineBasicBlock *Src
argument_list|,
argument|const MachineBasicBlock *Dst
argument_list|)
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

