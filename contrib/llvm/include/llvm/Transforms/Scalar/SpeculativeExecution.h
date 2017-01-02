begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SpeculativeExecution.h -----------------------------------*- C++ -*-===//
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
comment|// This pass hoists instructions to enable speculative execution on
end_comment

begin_comment
comment|// targets where branches are expensive. This is aimed at GPUs. It
end_comment

begin_comment
comment|// currently works on simple if-then and if-then-else
end_comment

begin_comment
comment|// patterns.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Removing branches is not the only motivation for this
end_comment

begin_comment
comment|// pass. E.g. consider this code and assume that there is no
end_comment

begin_comment
comment|// addressing mode for multiplying by sizeof(*a):
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   if (b> 0)
end_comment

begin_comment
comment|//     c = a[i + 1]
end_comment

begin_comment
comment|//   if (d> 0)
end_comment

begin_comment
comment|//     e = a[i + 2]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// turns into
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   p =&a[i + 1];
end_comment

begin_comment
comment|//   if (b> 0)
end_comment

begin_comment
comment|//     c = *p;
end_comment

begin_comment
comment|//   q =&a[i + 2];
end_comment

begin_comment
comment|//   if (d> 0)
end_comment

begin_comment
comment|//     e = *q;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// which could later be optimized to
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   r =&a[i];
end_comment

begin_comment
comment|//   if (b> 0)
end_comment

begin_comment
comment|//     c = r[1];
end_comment

begin_comment
comment|//   if (d> 0)
end_comment

begin_comment
comment|//     e = r[2];
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Later passes sink back much of the speculated code that did not enable
end_comment

begin_comment
comment|// further optimization.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This pass is more aggressive than the function SpeculativeyExecuteBB in
end_comment

begin_comment
comment|// SimplifyCFG. SimplifyCFG will not speculate if no selects are introduced and
end_comment

begin_comment
comment|// it will speculate at most one instruction. It also will not speculate if
end_comment

begin_comment
comment|// there is a value defined in the if-block that is only used in the then-block.
end_comment

begin_comment
comment|// These restrictions make sense since the speculation in SimplifyCFG seems
end_comment

begin_comment
comment|// aimed at introducing cheap selects, while this pass is intended to do more
end_comment

begin_comment
comment|// aggressive speculation while counting on later passes to either capitalize on
end_comment

begin_comment
comment|// that or clean it up.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If the pass was created by calling
end_comment

begin_comment
comment|// createSpeculativeExecutionIfHasBranchDivergencePass or the
end_comment

begin_comment
comment|// -spec-exec-only-if-divergent-target option is present, this pass only has an
end_comment

begin_comment
comment|// effect on targets where TargetTransformInfo::hasBranchDivergence() is true;
end_comment

begin_comment
comment|// on other targets, it is a nop.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This lets you include this pass unconditionally in the IR pass pipeline, but
end_comment

begin_comment
comment|// only enable it for relevant targets.
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
name|LLVM_TRANSFORMS_SCALAR_SPECULATIVEEXECUTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_SPECULATIVEEXECUTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/TargetTransformInfo.h"
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
name|class
name|SpeculativeExecutionPass
range|:
name|public
name|PassInfoMixin
operator|<
name|SpeculativeExecutionPass
operator|>
block|{
name|public
operator|:
name|SpeculativeExecutionPass
argument_list|(
argument|bool OnlyIfDivergentTarget = false
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
comment|// Glue for old PM
name|bool
name|runImpl
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|TargetTransformInfo
operator|*
name|TTI
argument_list|)
block|;
name|private
operator|:
name|bool
name|runOnBasicBlock
argument_list|(
name|BasicBlock
operator|&
name|B
argument_list|)
block|;
name|bool
name|considerHoistingFromTo
argument_list|(
name|BasicBlock
operator|&
name|FromBlock
argument_list|,
name|BasicBlock
operator|&
name|ToBlock
argument_list|)
block|;
comment|// If true, this pass is a nop unless the target architecture has branch
comment|// divergence.
specifier|const
name|bool
name|OnlyIfDivergentTarget
operator|=
name|false
block|;
name|TargetTransformInfo
operator|*
name|TTI
operator|=
name|nullptr
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//LLVM_TRANSFORMS_SCALAR_SPECULATIVEEXECUTION_H
end_comment

end_unit

