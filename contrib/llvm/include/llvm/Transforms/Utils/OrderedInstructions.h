begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Transforms/Utils/OrderedInstructions.h -------------*- C++ -*-===//
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
comment|// This file defines an efficient way to check for dominance relation between 2
end_comment

begin_comment
comment|// instructions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This interface dispatches to appropriate dominance check given 2
end_comment

begin_comment
comment|// instructions, i.e. in case the instructions are in the same basic block,
end_comment

begin_comment
comment|// OrderedBasicBlock (with instruction numbering and caching) are used.
end_comment

begin_comment
comment|// Otherwise, dominator tree is used.
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
name|LLVM_TRANSFORMS_UTILS_ORDEREDINSTRUCTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_ORDEREDINSTRUCTIONS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/OrderedBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Dominators.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Operator.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|OrderedInstructions
block|{
comment|/// Used to check dominance for instructions in same basic block.
name|mutable
name|DenseMap
operator|<
specifier|const
name|BasicBlock
operator|*
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|OrderedBasicBlock
operator|>>
name|OBBMap
expr_stmt|;
comment|/// The dominator tree of the parent function.
name|DominatorTree
modifier|*
name|DT
decl_stmt|;
name|public
label|:
comment|/// Constructor.
name|OrderedInstructions
argument_list|(
name|DominatorTree
operator|*
name|DT
argument_list|)
operator|:
name|DT
argument_list|(
argument|DT
argument_list|)
block|{}
comment|/// Return true if first instruction dominates the second.
name|bool
name|dominates
argument_list|(
argument|const Instruction *
argument_list|,
argument|const Instruction *
argument_list|)
specifier|const
expr_stmt|;
comment|/// Invalidate the OrderedBasicBlock cache when its basic block changes.
name|void
name|invalidateBlock
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
name|OBBMap
operator|.
name|erase
argument_list|(
name|BB
argument_list|)
expr_stmt|;
block|}
block|}
empty_stmt|;
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
comment|// LLVM_TRANSFORMS_UTILS_ORDEREDINSTRUCTIONS_H
end_comment

end_unit

