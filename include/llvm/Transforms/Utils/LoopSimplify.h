begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LoopSimplify.h - Loop Canonicalization Pass --------------*- C++ -*-===//
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
comment|// This pass performs several transformations to transform natural loops into a
end_comment

begin_comment
comment|// simpler form, which makes subsequent analyses and transformations simpler and
end_comment

begin_comment
comment|// more effective.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Loop pre-header insertion guarantees that there is a single, non-critical
end_comment

begin_comment
comment|// entry edge from outside of the loop to the loop header.  This simplifies a
end_comment

begin_comment
comment|// number of analyses and transformations, such as LICM.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Loop exit-block insertion guarantees that all exit blocks from the loop
end_comment

begin_comment
comment|// (blocks which are outside of the loop that have predecessors inside of the
end_comment

begin_comment
comment|// loop) only have predecessors from inside of the loop (and are thus dominated
end_comment

begin_comment
comment|// by the loop header).  This simplifies transformations such as store-sinking
end_comment

begin_comment
comment|// that are built into LICM.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This pass also guarantees that loops will have exactly one backedge.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Indirectbr instructions introduce several complications. If the loop
end_comment

begin_comment
comment|// contains or is entered by an indirectbr instruction, it may not be possible
end_comment

begin_comment
comment|// to transform the loop and make these guarantees. Client code should check
end_comment

begin_comment
comment|// that these conditions are true before relying on them.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that the simplifycfg pass will clean up blocks which are split out but
end_comment

begin_comment
comment|// end up being unnecessary, so usage of this pass should not pessimize
end_comment

begin_comment
comment|// generated code.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This pass obviously modifies the CFG, but updates loop information and
end_comment

begin_comment
comment|// dominator information.
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
name|LLVM_TRANSFORMS_UTILS_LOOPSIMPLIFY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_LOOPSIMPLIFY_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/AssumptionCache.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/ScalarEvolution.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Dominators.h"
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
comment|/// This pass is responsible for loop canonicalization.
name|class
name|LoopSimplifyPass
range|:
name|public
name|PassInfoMixin
operator|<
name|LoopSimplifyPass
operator|>
block|{
name|public
operator|:
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
block|; }
decl_stmt|;
comment|/// \brief Simplify each loop in a loop nest recursively.
comment|///
comment|/// This takes a potentially un-simplified loop L (and its children) and turns
comment|/// it into a simplified loop nest with preheaders and single backedges. It will
comment|/// update \c AliasAnalysis and \c ScalarEvolution analyses if they're non-null.
name|bool
name|simplifyLoop
parameter_list|(
name|Loop
modifier|*
name|L
parameter_list|,
name|DominatorTree
modifier|*
name|DT
parameter_list|,
name|LoopInfo
modifier|*
name|LI
parameter_list|,
name|ScalarEvolution
modifier|*
name|SE
parameter_list|,
name|AssumptionCache
modifier|*
name|AC
parameter_list|,
name|bool
name|PreserveLCSSA
parameter_list|)
function_decl|;
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
comment|// LLVM_TRANSFORMS_UTILS_LOOPSIMPLIFY_H
end_comment

end_unit

