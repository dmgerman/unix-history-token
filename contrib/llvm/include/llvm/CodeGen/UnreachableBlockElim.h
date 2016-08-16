begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- UnreachableBlockElim.h - Remove unreachable blocks for codegen --===//
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
comment|// This pass is an extremely simple version of the SimplifyCFG pass.  Its sole
end_comment

begin_comment
comment|// job is to delete LLVM basic blocks that are not reachable from the entry
end_comment

begin_comment
comment|// node.  To do this, it performs a simple depth first traversal of the CFG,
end_comment

begin_comment
comment|// then deletes any unvisited nodes.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that this pass is really a hack.  In particular, the instruction
end_comment

begin_comment
comment|// selectors for various targets should just not generate code for unreachable
end_comment

begin_comment
comment|// blocks.  Until LLVM has a more systematic way of defining instruction
end_comment

begin_comment
comment|// selectors, however, we cannot really expect them to handle additional
end_comment

begin_comment
comment|// complexity.
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
name|LLVM_LIB_CODEGEN_UNREACHABLEBLOCKELIM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_UNREACHABLEBLOCKELIM_H
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
name|class
name|UnreachableBlockElimPass
range|:
name|public
name|PassInfoMixin
operator|<
name|UnreachableBlockElimPass
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
comment|// LLVM_LIB_CODEGEN_UNREACHABLEBLOCKELIM_H
end_comment

end_unit

