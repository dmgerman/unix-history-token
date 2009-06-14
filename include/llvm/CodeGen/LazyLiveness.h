begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LazyLiveness.h - Lazy, CFG-invariant liveness information ----------===//
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
comment|// This pass implements a lazy liveness analysis as per "Fast Liveness Checking
end_comment

begin_comment
comment|// for SSA-form Programs," by Boissinot, et al.
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
name|LLVM_CODEGEN_LAZYLIVENESS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_LAZYLIVENESS_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineDominators.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SparseBitVector.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|LazyLiveness
range|:
name|public
name|MachineFunctionPass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid
name|LazyLiveness
argument_list|()
operator|:
name|MachineFunctionPass
argument_list|(
argument|&ID
argument_list|)
block|{ }
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|{
name|AU
operator|.
name|setPreservesAll
argument_list|()
block|;
name|AU
operator|.
name|addRequired
operator|<
name|MachineDominatorTree
operator|>
operator|(
operator|)
block|;   }
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|mf
argument_list|)
block|;
name|bool
name|vregLiveIntoMBB
argument_list|(
argument|unsigned vreg
argument_list|,
argument|MachineBasicBlock* MBB
argument_list|)
block|;
name|private
operator|:
name|void
name|computeBackedgeChain
argument_list|(
name|MachineFunction
operator|&
name|mf
argument_list|,
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
block|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|MachineBasicBlock
operator|*
operator|,
name|MachineBasicBlock
operator|*
operator|>
name|edge_t
expr_stmt|;
name|MachineRegisterInfo
operator|*
name|MRI
decl_stmt|;
name|DenseMap
operator|<
name|MachineBasicBlock
operator|*
operator|,
name|unsigned
operator|>
name|preorder
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|MachineBasicBlock
operator|*
operator|>
name|rev_preorder
expr_stmt|;
name|DenseMap
operator|<
name|MachineBasicBlock
operator|*
operator|,
name|SparseBitVector
operator|<
literal|128
operator|>
expr|>
name|rv
expr_stmt|;
name|DenseMap
operator|<
name|MachineBasicBlock
operator|*
operator|,
name|SparseBitVector
operator|<
literal|128
operator|>
expr|>
name|tv
expr_stmt|;
name|DenseSet
operator|<
name|edge_t
operator|>
name|backedges
expr_stmt|;
name|SparseBitVector
operator|<
literal|128
operator|>
name|backedge_source
expr_stmt|;
name|SparseBitVector
operator|<
literal|128
operator|>
name|backedge_target
expr_stmt|;
name|SparseBitVector
operator|<
literal|128
operator|>
name|calculated
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

