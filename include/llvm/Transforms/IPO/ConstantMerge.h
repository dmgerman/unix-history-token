begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ConstantMerge.h - Merge duplicate global constants -------*- C++ -*-===//
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
comment|// This file defines the interface to a pass that merges duplicate global
end_comment

begin_comment
comment|// constants together into a single constant that is shared.  This is useful
end_comment

begin_comment
comment|// because some passes (ie TraceValues) insert a lot of string constants into
end_comment

begin_comment
comment|// the program, regardless of whether or not an existing string is available.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Algorithm: ConstantMerge is designed to build up a map of available constants
end_comment

begin_comment
comment|// and eliminate duplicates when it is initialized.
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
name|LLVM_TRANSFORMS_IPO_CONSTANTMERGE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_IPO_CONSTANTMERGE_H
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
comment|/// A pass that merges duplicate global constants into a single constant.
name|class
name|ConstantMergePass
range|:
name|public
name|PassInfoMixin
operator|<
name|ConstantMergePass
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
comment|// LLVM_TRANSFORMS_IPO_CONSTANTMERGE_H
end_comment

end_unit

