begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- AlignmentFromAssumptions.h ----------------------------*- C++ -*-===//
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
comment|// This file implements a ScalarEvolution-based transformation to set
end_comment

begin_comment
comment|// the alignments of load, stores and memory intrinsics based on the truth
end_comment

begin_comment
comment|// expressions of assume intrinsics. The primary motivation is to handle
end_comment

begin_comment
comment|// complex alignment assumptions that apply to vector loads and stores that
end_comment

begin_comment
comment|// appear after vectorization and unrolling.
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
name|LLVM_TRANSFORMS_SCALAR_ALIGNMENTFROMASSUMPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_ALIGNMENTFROMASSUMPTIONS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/ScalarEvolution.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/IntrinsicInst.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|struct
name|AlignmentFromAssumptionsPass
range|:
name|public
name|PassInfoMixin
operator|<
name|AlignmentFromAssumptionsPass
operator|>
block|{
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
comment|// Glue for old PM.
name|bool
name|runImpl
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|AssumptionCache
operator|&
name|AC
argument_list|,
name|ScalarEvolution
operator|*
name|SE_
argument_list|,
name|DominatorTree
operator|*
name|DT_
argument_list|)
block|;
comment|// For memory transfers, we need a common alignment for both the source and
comment|// destination. If we have a new alignment for only one operand of a transfer
comment|// instruction, save it in these maps.  If we reach the other operand through
comment|// another assumption later, then we may change the alignment at that point.
name|DenseMap
operator|<
name|MemTransferInst
operator|*
block|,
name|unsigned
operator|>
name|NewDestAlignments
block|,
name|NewSrcAlignments
block|;
name|ScalarEvolution
operator|*
name|SE
operator|=
name|nullptr
block|;
name|DominatorTree
operator|*
name|DT
operator|=
name|nullptr
block|;
name|bool
name|extractAlignmentInfo
argument_list|(
name|CallInst
operator|*
name|I
argument_list|,
name|Value
operator|*
operator|&
name|AAPtr
argument_list|,
specifier|const
name|SCEV
operator|*
operator|&
name|AlignSCEV
argument_list|,
specifier|const
name|SCEV
operator|*
operator|&
name|OffSCEV
argument_list|)
block|;
name|bool
name|processAssumption
argument_list|(
name|CallInst
operator|*
name|I
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_SCALAR_ALIGNMENTFROMASSUMPTIONS_H
end_comment

end_unit

