begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LCSSA.h - Loop-closed SSA transform Pass -----------------*- C++ -*-===//
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
comment|// This pass transforms loops by placing phi nodes at the end of the loops for
end_comment

begin_comment
comment|// all values that are live across the loop boundary.  For example, it turns
end_comment

begin_comment
comment|// the left into the right code:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// for (...)                for (...)
end_comment

begin_comment
comment|//   if (c)                   if (c)
end_comment

begin_comment
comment|//     X1 = ...                 X1 = ...
end_comment

begin_comment
comment|//   else                     else
end_comment

begin_comment
comment|//     X2 = ...                 X2 = ...
end_comment

begin_comment
comment|//   X3 = phi(X1, X2)         X3 = phi(X1, X2)
end_comment

begin_comment
comment|// ... = X3 + 4             X4 = phi(X3)
end_comment

begin_comment
comment|//                          ... = X4 + 4
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This is still valid LLVM; the extra phi nodes are purely redundant, and will
end_comment

begin_comment
comment|// be trivially eliminated by InstCombine.  The major benefit of this
end_comment

begin_comment
comment|// transformation is that it makes many other loop optimizations, such as
end_comment

begin_comment
comment|// LoopUnswitching, simpler.
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
name|LLVM_TRANSFORMS_UTILS_LCSSA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_LCSSA_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Converts loops into loop-closed SSA form.
name|class
name|LCSSAPass
range|:
name|public
name|PassInfoMixin
operator|<
name|LCSSAPass
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
comment|// LLVM_TRANSFORMS_UTILS_LCSSA_H
end_comment

end_unit

