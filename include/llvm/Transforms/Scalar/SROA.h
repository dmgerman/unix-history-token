begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SROA.h - Scalar Replacement Of Aggregates ----------------*- C++ -*-===//
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
comment|/// This file provides the interface for LLVM's Scalar Replacement of
end_comment

begin_comment
comment|/// Aggregates pass. This pass provides both aggregate splitting and the
end_comment

begin_comment
comment|/// primary SSA formation used in the compiler.
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
name|LLVM_TRANSFORMS_SCALAR_SROA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_SROA_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AssumptionCache.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Dominators.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
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
comment|/// A private "module" namespace for types and utilities used by SROA. These
comment|/// are implementation details and should not be used by clients.
name|namespace
name|sroa
name|LLVM_LIBRARY_VISIBILITY
block|{
name|class
name|AllocaSliceRewriter
decl_stmt|;
name|class
name|AllocaSlices
decl_stmt|;
name|class
name|Partition
decl_stmt|;
name|class
name|SROALegacyPass
decl_stmt|;
block|}
comment|// end namespace sroa
comment|/// \brief An optimization pass providing Scalar Replacement of Aggregates.
comment|///
comment|/// This pass takes allocations which can be completely analyzed (that is, they
comment|/// don't escape) and tries to turn them into scalar SSA values. There are
comment|/// a few steps to this process.
comment|///
comment|/// 1) It takes allocations of aggregates and analyzes the ways in which they
comment|///    are used to try to split them into smaller allocations, ideally of
comment|///    a single scalar data type. It will split up memcpy and memset accesses
comment|///    as necessary and try to isolate individual scalar accesses.
comment|/// 2) It will transform accesses into forms which are suitable for SSA value
comment|///    promotion. This can be replacing a memset with a scalar store of an
comment|///    integer value, or it can involve speculating operations on a PHI or
comment|///    select to be a PHI or select of the results.
comment|/// 3) Finally, this will try to detect a pattern of accesses which map cleanly
comment|///    onto insert and extract operations on a vector value, and convert them to
comment|///    this form. By doing so, it will enable promotion of vector aggregates to
comment|///    SSA vector values.
name|class
name|SROA
range|:
name|public
name|PassInfoMixin
operator|<
name|SROA
operator|>
block|{
name|LLVMContext
operator|*
name|C
operator|=
name|nullptr
block|;
name|DominatorTree
operator|*
name|DT
operator|=
name|nullptr
block|;
name|AssumptionCache
operator|*
name|AC
operator|=
name|nullptr
block|;
comment|/// \brief Worklist of alloca instructions to simplify.
comment|///
comment|/// Each alloca in the function is added to this. Each new alloca formed gets
comment|/// added to it as well to recursively simplify unless that alloca can be
comment|/// directly promoted. Finally, each time we rewrite a use of an alloca other
comment|/// the one being actively rewritten, we add it back onto the list if not
comment|/// already present to ensure it is re-visited.
name|SetVector
operator|<
name|AllocaInst
operator|*
block|,
name|SmallVector
operator|<
name|AllocaInst
operator|*
block|,
literal|16
operator|>>
name|Worklist
block|;
comment|/// \brief A collection of instructions to delete.
comment|/// We try to batch deletions to simplify code and make things a bit more
comment|/// efficient.
name|SetVector
operator|<
name|Instruction
operator|*
block|,
name|SmallVector
operator|<
name|Instruction
operator|*
block|,
literal|8
operator|>>
name|DeadInsts
block|;
comment|/// \brief Post-promotion worklist.
comment|///
comment|/// Sometimes we discover an alloca which has a high probability of becoming
comment|/// viable for SROA after a round of promotion takes place. In those cases,
comment|/// the alloca is enqueued here for re-processing.
comment|///
comment|/// Note that we have to be very careful to clear allocas out of this list in
comment|/// the event they are deleted.
name|SetVector
operator|<
name|AllocaInst
operator|*
block|,
name|SmallVector
operator|<
name|AllocaInst
operator|*
block|,
literal|16
operator|>>
name|PostPromotionWorklist
block|;
comment|/// \brief A collection of alloca instructions we can directly promote.
name|std
operator|::
name|vector
operator|<
name|AllocaInst
operator|*
operator|>
name|PromotableAllocas
block|;
comment|/// \brief A worklist of PHIs to speculate prior to promoting allocas.
comment|///
comment|/// All of these PHIs have been checked for the safety of speculation and by
comment|/// being speculated will allow promoting allocas currently in the promotable
comment|/// queue.
name|SetVector
operator|<
name|PHINode
operator|*
block|,
name|SmallVector
operator|<
name|PHINode
operator|*
block|,
literal|2
operator|>>
name|SpeculatablePHIs
block|;
comment|/// \brief A worklist of select instructions to speculate prior to promoting
comment|/// allocas.
comment|///
comment|/// All of these select instructions have been checked for the safety of
comment|/// speculation and by being speculated will allow promoting allocas
comment|/// currently in the promotable queue.
name|SetVector
operator|<
name|SelectInst
operator|*
block|,
name|SmallVector
operator|<
name|SelectInst
operator|*
block|,
literal|2
operator|>>
name|SpeculatableSelects
block|;
name|public
operator|:
name|SROA
argument_list|()
operator|=
expr|default
block|;
comment|/// \brief Run the pass over the function.
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
name|private
operator|:
name|friend
name|class
name|sroa
operator|::
name|AllocaSliceRewriter
block|;
name|friend
name|class
name|sroa
operator|::
name|SROALegacyPass
block|;
comment|/// Helper used by both the public run method and by the legacy pass.
name|PreservedAnalyses
name|runImpl
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|DominatorTree
operator|&
name|RunDT
argument_list|,
name|AssumptionCache
operator|&
name|RunAC
argument_list|)
block|;
name|bool
name|presplitLoadsAndStores
argument_list|(
name|AllocaInst
operator|&
name|AI
argument_list|,
name|sroa
operator|::
name|AllocaSlices
operator|&
name|AS
argument_list|)
block|;
name|AllocaInst
operator|*
name|rewritePartition
argument_list|(
name|AllocaInst
operator|&
name|AI
argument_list|,
name|sroa
operator|::
name|AllocaSlices
operator|&
name|AS
argument_list|,
name|sroa
operator|::
name|Partition
operator|&
name|P
argument_list|)
block|;
name|bool
name|splitAlloca
argument_list|(
name|AllocaInst
operator|&
name|AI
argument_list|,
name|sroa
operator|::
name|AllocaSlices
operator|&
name|AS
argument_list|)
block|;
name|bool
name|runOnAlloca
argument_list|(
name|AllocaInst
operator|&
name|AI
argument_list|)
block|;
name|void
name|clobberUse
argument_list|(
name|Use
operator|&
name|U
argument_list|)
block|;
name|void
name|deleteDeadInstructions
argument_list|(
name|SmallPtrSetImpl
operator|<
name|AllocaInst
operator|*
operator|>
operator|&
name|DeletedAllocas
argument_list|)
block|;
name|bool
name|promoteAllocas
argument_list|(
name|Function
operator|&
name|F
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

begin_comment
comment|// LLVM_TRANSFORMS_SCALAR_SROA_H
end_comment

end_unit

