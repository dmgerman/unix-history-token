begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- JumpThreading.h - thread control through conditional BBs -*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// See the comments on JumpThreadingPass.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TRANSFORMS_SCALAR_JUMPTHREADING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_JUMPTHREADING_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/BlockFrequencyInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/BlockFrequencyInfoImpl.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/BranchProbabilityInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/LazyValueInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/TargetLibraryInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/IntrinsicInst.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// A private "module" namespace for types and utilities used by
comment|/// JumpThreading.
comment|/// These are implementation details and should not be used by clients.
name|namespace
name|jumpthreading
block|{
comment|// These are at global scope so static functions can use them too.
typedef|typedef
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|Constant
operator|*
operator|,
name|BasicBlock
operator|*
operator|>>
name|PredValueInfo
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|Constant
operator|*
operator|,
name|BasicBlock
operator|*
operator|>
operator|,
literal|8
operator|>
name|PredValueInfoTy
expr_stmt|;
comment|// This is used to keep track of what kind of constant we're currently hoping
comment|// to find.
enum|enum
name|ConstantPreference
block|{
name|WantInteger
block|,
name|WantBlockAddress
block|}
enum|;
block|}
comment|/// This pass performs 'jump threading', which looks at blocks that have
comment|/// multiple predecessors and multiple successors.  If one or more of the
comment|/// predecessors of the block can be proven to always jump to one of the
comment|/// successors, we forward the edge from the predecessor to the successor by
comment|/// duplicating the contents of this block.
comment|///
comment|/// An example of when this can occur is code like this:
comment|///
comment|///   if () { ...
comment|///     X = 4;
comment|///   }
comment|///   if (X< 3) {
comment|///
comment|/// In this case, the unconditional branch at the end of the first if can be
comment|/// revectored to the false side of the second if.
comment|///
name|class
name|JumpThreadingPass
range|:
name|public
name|PassInfoMixin
operator|<
name|JumpThreadingPass
operator|>
block|{
name|TargetLibraryInfo
operator|*
name|TLI
block|;
name|LazyValueInfo
operator|*
name|LVI
block|;
name|AliasAnalysis
operator|*
name|AA
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|BlockFrequencyInfo
operator|>
name|BFI
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|BranchProbabilityInfo
operator|>
name|BPI
block|;
name|bool
name|HasProfileData
operator|=
name|false
block|;
name|bool
name|HasGuards
operator|=
name|false
block|;
ifdef|#
directive|ifdef
name|NDEBUG
name|SmallPtrSet
operator|<
specifier|const
name|BasicBlock
operator|*
block|,
literal|16
operator|>
name|LoopHeaders
block|;
else|#
directive|else
name|SmallSet
operator|<
name|AssertingVH
operator|<
specifier|const
name|BasicBlock
operator|>
block|,
literal|16
operator|>
name|LoopHeaders
block|;
endif|#
directive|endif
name|DenseSet
operator|<
name|std
operator|::
name|pair
operator|<
name|Value
operator|*
block|,
name|BasicBlock
operator|*
operator|>>
name|RecursionSet
block|;
name|unsigned
name|BBDupThreshold
block|;
comment|// RAII helper for updating the recursion stack.
block|struct
name|RecursionSetRemover
block|{
name|DenseSet
operator|<
name|std
operator|::
name|pair
operator|<
name|Value
operator|*
block|,
name|BasicBlock
operator|*
operator|>>
operator|&
name|TheSet
block|;
name|std
operator|::
name|pair
operator|<
name|Value
operator|*
block|,
name|BasicBlock
operator|*
operator|>
name|ThePair
block|;
name|RecursionSetRemover
argument_list|(
name|DenseSet
operator|<
name|std
operator|::
name|pair
operator|<
name|Value
operator|*
argument_list|,
name|BasicBlock
operator|*
operator|>>
operator|&
name|S
argument_list|,
name|std
operator|::
name|pair
operator|<
name|Value
operator|*
argument_list|,
name|BasicBlock
operator|*
operator|>
name|P
argument_list|)
operator|:
name|TheSet
argument_list|(
name|S
argument_list|)
block|,
name|ThePair
argument_list|(
argument|P
argument_list|)
block|{}
operator|~
name|RecursionSetRemover
argument_list|()
block|{
name|TheSet
operator|.
name|erase
argument_list|(
name|ThePair
argument_list|)
block|; }
block|}
block|;
name|public
operator|:
name|JumpThreadingPass
argument_list|(
argument|int T = -
literal|1
argument_list|)
block|;
comment|// Glue for old PM.
name|bool
name|runImpl
argument_list|(
argument|Function&F
argument_list|,
argument|TargetLibraryInfo *TLI_
argument_list|,
argument|LazyValueInfo *LVI_
argument_list|,
argument|AliasAnalysis *AA_
argument_list|,
argument|bool HasProfileData_
argument_list|,
argument|std::unique_ptr<BlockFrequencyInfo> BFI_
argument_list|,
argument|std::unique_ptr<BranchProbabilityInfo> BPI_
argument_list|)
block|;
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
block|;
name|void
name|releaseMemory
argument_list|()
block|{
name|BFI
operator|.
name|reset
argument_list|()
block|;
name|BPI
operator|.
name|reset
argument_list|()
block|;   }
name|void
name|FindLoopHeaders
argument_list|(
name|Function
operator|&
name|F
argument_list|)
block|;
name|bool
name|ProcessBlock
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
name|bool
name|ThreadEdge
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|BasicBlock
operator|*
operator|>
operator|&
name|PredBBs
argument_list|,
name|BasicBlock
operator|*
name|SuccBB
argument_list|)
block|;
name|bool
name|DuplicateCondBranchOnPHIIntoPred
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|BasicBlock
operator|*
operator|>
operator|&
name|PredBBs
argument_list|)
block|;
name|bool
name|ComputeValueKnownInPredecessors
argument_list|(
argument|Value *V
argument_list|,
argument|BasicBlock *BB
argument_list|,
argument|jumpthreading::PredValueInfo&Result
argument_list|,
argument|jumpthreading::ConstantPreference Preference
argument_list|,
argument|Instruction *CxtI = nullptr
argument_list|)
block|;
name|bool
name|ProcessThreadableEdges
argument_list|(
argument|Value *Cond
argument_list|,
argument|BasicBlock *BB
argument_list|,
argument|jumpthreading::ConstantPreference Preference
argument_list|,
argument|Instruction *CxtI = nullptr
argument_list|)
block|;
name|bool
name|ProcessBranchOnPHI
argument_list|(
name|PHINode
operator|*
name|PN
argument_list|)
block|;
name|bool
name|ProcessBranchOnXOR
argument_list|(
name|BinaryOperator
operator|*
name|BO
argument_list|)
block|;
name|bool
name|ProcessImpliedCondition
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
name|bool
name|SimplifyPartiallyRedundantLoad
argument_list|(
name|LoadInst
operator|*
name|LI
argument_list|)
block|;
name|bool
name|TryToUnfoldSelect
argument_list|(
name|CmpInst
operator|*
name|CondCmp
argument_list|,
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
name|bool
name|TryToUnfoldSelectInCurrBB
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
name|bool
name|ProcessGuards
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
name|bool
name|ThreadGuard
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|,
name|IntrinsicInst
operator|*
name|Guard
argument_list|,
name|BranchInst
operator|*
name|BI
argument_list|)
block|;
name|private
operator|:
name|BasicBlock
operator|*
name|SplitBlockPreds
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|,
name|ArrayRef
operator|<
name|BasicBlock
operator|*
operator|>
name|Preds
argument_list|,
specifier|const
name|char
operator|*
name|Suffix
argument_list|)
block|;
name|void
name|UpdateBlockFreqAndEdgeWeight
argument_list|(
name|BasicBlock
operator|*
name|PredBB
argument_list|,
name|BasicBlock
operator|*
name|BB
argument_list|,
name|BasicBlock
operator|*
name|NewBB
argument_list|,
name|BasicBlock
operator|*
name|SuccBB
argument_list|)
block|;
comment|/// Check if the block has profile metadata for its outgoing edges.
name|bool
name|doesBlockHaveProfileData
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

