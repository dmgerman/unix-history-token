begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/OrderedBasicBlock.h --------------------- -*- C++ -*-===//
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
comment|// This file defines the OrderedBasicBlock class. OrderedBasicBlock maintains
end_comment

begin_comment
comment|// an interface where clients can query if one instruction comes before another
end_comment

begin_comment
comment|// in a BasicBlock. Since BasicBlock currently lacks a reliable way to query
end_comment

begin_comment
comment|// relative position between instructions one can use OrderedBasicBlock to do
end_comment

begin_comment
comment|// such queries. OrderedBasicBlock is lazily built on a source BasicBlock and
end_comment

begin_comment
comment|// maintains an internal Instruction -> Position map. A OrderedBasicBlock
end_comment

begin_comment
comment|// instance should be discarded whenever the source BasicBlock changes.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// It's currently used by the CaptureTracker in order to find relative
end_comment

begin_comment
comment|// positions of a pair of instructions inside a BasicBlock.
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
name|LLVM_ANALYSIS_ORDEREDBASICBLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_ORDEREDBASICBLOCK_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/BasicBlock.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Instruction
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|OrderedBasicBlock
block|{
name|private
label|:
comment|/// \brief Map a instruction to its position in a BasicBlock.
name|SmallDenseMap
operator|<
specifier|const
name|Instruction
operator|*
operator|,
name|unsigned
operator|,
literal|32
operator|>
name|NumberedInsts
expr_stmt|;
comment|/// \brief Keep track of last instruction inserted into \p NumberedInsts.
comment|/// It speeds up queries for uncached instructions by providing a start point
comment|/// for new queries in OrderedBasicBlock::comesBefore.
name|BasicBlock
operator|::
name|const_iterator
name|LastInstFound
expr_stmt|;
comment|/// \brief The position/number to tag the next instruction to be found.
name|unsigned
name|NextInstPos
decl_stmt|;
comment|/// \brief The source BasicBlock to map.
specifier|const
name|BasicBlock
modifier|*
name|BB
decl_stmt|;
comment|/// \brief Given no cached results, find if \p A comes before \p B in \p BB.
comment|/// Cache and number out instruction while walking \p BB.
name|bool
name|comesBefore
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|A
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|B
parameter_list|)
function_decl|;
name|public
label|:
name|OrderedBasicBlock
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BasicB
argument_list|)
expr_stmt|;
comment|/// \brief Find out whether \p A dominates \p B, meaning whether \p A
comment|/// comes before \p B in \p BB. This is a simplification that considers
comment|/// cached instruction positions and ignores other basic blocks, being
comment|/// only relevant to compare relative instructions positions inside \p BB.
comment|/// Returns false for A == B.
name|bool
name|dominates
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|A
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|B
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

