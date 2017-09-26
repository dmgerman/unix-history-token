begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SimpleLoopUnswitch.h - Hoist loop-invariant control flow -*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TRANSFORMS_SCALAR_SIMPLELOOPUNSWITCH_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_SIMPLELOOPUNSWITCH_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopAnalysisManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/Scalar/LoopPassManager.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// This pass transforms loops that contain branches on loop-invariant
comment|/// conditions to have multiple loops. For example, it turns the left into the
comment|/// right code:
comment|///
comment|///  for (...)                  if (lic)
comment|///    A                          for (...)
comment|///    if (lic)                     A; B; C
comment|///      B                      else
comment|///    C                          for (...)
comment|///                                 A; C
comment|///
comment|/// This can increase the size of the code exponentially (doubling it every time
comment|/// a loop is unswitched) so we only unswitch if the resultant code will be
comment|/// smaller than a threshold.
comment|///
comment|/// This pass expects LICM to be run before it to hoist invariant conditions out
comment|/// of the loop, to make the unswitching opportunity obvious.
comment|///
name|class
name|SimpleLoopUnswitchPass
range|:
name|public
name|PassInfoMixin
operator|<
name|SimpleLoopUnswitchPass
operator|>
block|{
name|public
operator|:
name|SimpleLoopUnswitchPass
argument_list|()
operator|=
expr|default
block|;
name|PreservedAnalyses
name|run
argument_list|(
name|Loop
operator|&
name|L
argument_list|,
name|LoopAnalysisManager
operator|&
name|AM
argument_list|,
name|LoopStandardAnalysisResults
operator|&
name|AR
argument_list|,
name|LPMUpdater
operator|&
name|U
argument_list|)
block|; }
decl_stmt|;
comment|/// Create the legacy pass object for the simple loop unswitcher.
comment|///
comment|/// See the documentaion for `SimpleLoopUnswitchPass` for details.
name|Pass
modifier|*
name|createSimpleLoopUnswitchLegacyPass
parameter_list|()
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
comment|// LLVM_TRANSFORMS_SCALAR_SIMPLELOOPUNSWITCH_H
end_comment

end_unit

