begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SCCP.h - Sparse Conditional Constant Propagation ---------*- C++ -*-===//
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
comment|// This pass implements  interprocedural sparse conditional constant
end_comment

begin_comment
comment|// propagation and merging.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Specifically, this:
end_comment

begin_comment
comment|//   * Assumes values are constant unless proven otherwise
end_comment

begin_comment
comment|//   * Assumes BasicBlocks are dead unless proven otherwise
end_comment

begin_comment
comment|//   * Proves values to be constant, and replaces them with constants
end_comment

begin_comment
comment|//   * Proves conditional branches to be unconditional
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
name|LLVM_TRANSFORMS_IPO_SCCP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_IPO_SCCP_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
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
comment|/// Pass to perform interprocedural constant propagation.
name|class
name|IPSCCPPass
range|:
name|public
name|PassInfoMixin
operator|<
name|IPSCCPPass
operator|>
block|{
name|public
operator|:
name|PreservedAnalyses
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
operator|&
name|AM
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
comment|// LLVM_TRANSFORMS_IPO_SCCP_H
end_comment

end_unit

