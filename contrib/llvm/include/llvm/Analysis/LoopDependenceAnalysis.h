begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/LoopDependenceAnalysis.h --------------- -*- C++ -*---===//
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
comment|// LoopDependenceAnalysis is an LLVM pass that analyses dependences in memory
end_comment

begin_comment
comment|// accesses in loops.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Please note that this is work in progress and the interface is subject to
end_comment

begin_comment
comment|// change.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TODO: adapt as interface progresses
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
name|LLVM_ANALYSIS_LOOP_DEPENDENCE_ANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LOOP_DEPENDENCE_ANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AliasAnalysis
decl_stmt|;
name|class
name|AnalysisUsage
decl_stmt|;
name|class
name|ScalarEvolution
decl_stmt|;
name|class
name|SCEV
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|LoopDependenceAnalysis
range|:
name|public
name|LoopPass
block|{
name|AliasAnalysis
operator|*
name|AA
block|;
name|ScalarEvolution
operator|*
name|SE
block|;
comment|/// L - The loop we are currently analysing.
name|Loop
operator|*
name|L
block|;
comment|/// TODO: doc
block|enum
name|DependenceResult
block|{
name|Independent
operator|=
literal|0
block|,
name|Dependent
operator|=
literal|1
block|,
name|Unknown
operator|=
literal|2
block|}
block|;
comment|/// TODO: doc
block|struct
name|Subscript
block|{
comment|/// TODO: Add distance, direction, breaking conditions, ...
block|}
block|;
comment|/// DependencePair - Represents a data dependence relation between to memory
comment|/// reference instructions.
block|struct
name|DependencePair
operator|:
name|public
name|FastFoldingSetNode
block|{
name|Value
operator|*
name|A
block|;
name|Value
operator|*
name|B
block|;
name|DependenceResult
name|Result
block|;
name|SmallVector
operator|<
name|Subscript
block|,
literal|4
operator|>
name|Subscripts
block|;
name|DependencePair
argument_list|(
specifier|const
name|FoldingSetNodeID
operator|&
name|ID
argument_list|,
name|Value
operator|*
name|a
argument_list|,
name|Value
operator|*
name|b
argument_list|)
operator|:
name|FastFoldingSetNode
argument_list|(
name|ID
argument_list|)
block|,
name|A
argument_list|(
name|a
argument_list|)
block|,
name|B
argument_list|(
name|b
argument_list|)
block|,
name|Result
argument_list|(
name|Unknown
argument_list|)
block|,
name|Subscripts
argument_list|()
block|{}
block|}
block|;
comment|/// findOrInsertDependencePair - Return true if a DependencePair for the
comment|/// given Values already exists, false if a new DependencePair had to be
comment|/// created. The third argument is set to the pair found or created.
name|bool
name|findOrInsertDependencePair
argument_list|(
name|Value
operator|*
argument_list|,
name|Value
operator|*
argument_list|,
name|DependencePair
operator|*
operator|&
argument_list|)
block|;
comment|/// getLoops - Collect all loops of the loop nest L in which
comment|/// a given SCEV is variant.
name|void
name|getLoops
argument_list|(
argument|const SCEV*
argument_list|,
argument|DenseSet<const Loop*>*
argument_list|)
specifier|const
block|;
comment|/// isLoopInvariant - True if a given SCEV is invariant in all loops of the
comment|/// loop nest starting at the innermost loop L.
name|bool
name|isLoopInvariant
argument_list|(
argument|const SCEV*
argument_list|)
specifier|const
block|;
comment|/// isAffine - An SCEV is affine with respect to the loop nest starting at
comment|/// the innermost loop L if it is of the form A+B*X where A, B are invariant
comment|/// in the loop nest and X is a induction variable in the loop nest.
name|bool
name|isAffine
argument_list|(
argument|const SCEV*
argument_list|)
specifier|const
block|;
comment|/// TODO: doc
name|bool
name|isZIVPair
argument_list|(
argument|const SCEV*
argument_list|,
argument|const SCEV*
argument_list|)
specifier|const
block|;
name|bool
name|isSIVPair
argument_list|(
argument|const SCEV*
argument_list|,
argument|const SCEV*
argument_list|)
specifier|const
block|;
name|DependenceResult
name|analyseZIV
argument_list|(
argument|const SCEV*
argument_list|,
argument|const SCEV*
argument_list|,
argument|Subscript*
argument_list|)
specifier|const
block|;
name|DependenceResult
name|analyseSIV
argument_list|(
argument|const SCEV*
argument_list|,
argument|const SCEV*
argument_list|,
argument|Subscript*
argument_list|)
specifier|const
block|;
name|DependenceResult
name|analyseMIV
argument_list|(
argument|const SCEV*
argument_list|,
argument|const SCEV*
argument_list|,
argument|Subscript*
argument_list|)
specifier|const
block|;
name|DependenceResult
name|analyseSubscript
argument_list|(
argument|const SCEV*
argument_list|,
argument|const SCEV*
argument_list|,
argument|Subscript*
argument_list|)
specifier|const
block|;
name|DependenceResult
name|analysePair
argument_list|(
argument|DependencePair*
argument_list|)
specifier|const
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Class identification, replacement for typeinfo
name|LoopDependenceAnalysis
argument_list|()
operator|:
name|LoopPass
argument_list|(
argument|&ID
argument_list|)
block|{}
comment|/// isDependencePair - Check whether two values can possibly give rise to
comment|/// a data dependence: that is the case if both are instructions accessing
comment|/// memory and at least one of those accesses is a write.
name|bool
name|isDependencePair
argument_list|(
argument|const Value*
argument_list|,
argument|const Value*
argument_list|)
specifier|const
block|;
comment|/// depends - Return a boolean indicating if there is a data dependence
comment|/// between two instructions.
name|bool
name|depends
argument_list|(
name|Value
operator|*
argument_list|,
name|Value
operator|*
argument_list|)
block|;
name|bool
name|runOnLoop
argument_list|(
name|Loop
operator|*
argument_list|,
name|LPPassManager
operator|&
argument_list|)
block|;
name|virtual
name|void
name|releaseMemory
argument_list|()
block|;
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&
argument_list|)
specifier|const
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&
argument_list|,
argument|const Module* =
literal|0
argument_list|)
specifier|const
block|;
name|private
operator|:
name|FoldingSet
operator|<
name|DependencePair
operator|>
name|Pairs
block|;
name|BumpPtrAllocator
name|PairAllocator
block|; }
decl_stmt|;
comment|// class LoopDependenceAnalysis
comment|// createLoopDependenceAnalysisPass - This creates an instance of the
comment|// LoopDependenceAnalysis pass.
comment|//
name|LoopPass
modifier|*
name|createLoopDependenceAnalysisPass
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LLVM_ANALYSIS_LOOP_DEPENDENCE_ANALYSIS_H */
end_comment

end_unit

