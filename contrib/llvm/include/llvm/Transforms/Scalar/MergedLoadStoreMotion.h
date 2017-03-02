begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MergedLoadStoreMotion.h - merge and hoist/sink load/stores ---------===//
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
comment|//! \file
end_comment

begin_comment
comment|//! \brief This pass performs merges of loads and stores on both sides of a
end_comment

begin_comment
comment|//  diamond (hammock). It hoists the loads and sinks the stores.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The algorithm iteratively hoists two loads to the same address out of a
end_comment

begin_comment
comment|// diamond (hammock) and merges them into a single load in the header. Similar
end_comment

begin_comment
comment|// it sinks and merges two stores to the tail block (footer). The algorithm
end_comment

begin_comment
comment|// iterates over the instructions of one side of the diamond and attempts to
end_comment

begin_comment
comment|// find a matching load/store on the other side. It hoists / sinks when it
end_comment

begin_comment
comment|// thinks it safe to do so.  This optimization helps with eg. hiding load
end_comment

begin_comment
comment|// latencies, triggering if-conversion, and reducing static code size.
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
name|LLVM_TRANSFORMS_SCALAR_MERGEDLOADSTOREMOTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_MERGEDLOADSTOREMOTION_H
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
name|class
name|MergedLoadStoreMotionPass
range|:
name|public
name|PassInfoMixin
operator|<
name|MergedLoadStoreMotionPass
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_SCALAR_MERGEDLOADSTOREMOTION_H
end_comment

end_unit

