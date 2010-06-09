begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LiveValues.h - Liveness information for LLVM IR Values. ------------===//
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
comment|// This file defines the interface for the LLVM IR Value liveness
end_comment

begin_comment
comment|// analysis pass.
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
name|LLVM_ANALYSIS_LIVEVALUES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LIVEVALUES_H
end_define

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DominatorTree
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// LiveValues - Analysis that provides liveness information for
comment|/// LLVM IR Values.
comment|///
name|class
name|LiveValues
range|:
name|public
name|FunctionPass
block|{
name|DominatorTree
operator|*
name|DT
block|;
name|LoopInfo
operator|*
name|LI
block|;
comment|/// Memo - A bunch of state to be associated with a value.
comment|///
block|struct
name|Memo
block|{
comment|/// Used - The set of blocks which contain a use of the value.
comment|///
name|SmallPtrSet
operator|<
specifier|const
name|BasicBlock
operator|*
block|,
literal|4
operator|>
name|Used
block|;
comment|/// LiveThrough - A conservative approximation of the set of blocks in
comment|/// which the value is live-through, meaning blocks properly dominated
comment|/// by the definition, and from which blocks containing uses of the
comment|/// value are reachable.
comment|///
name|SmallPtrSet
operator|<
specifier|const
name|BasicBlock
operator|*
block|,
literal|4
operator|>
name|LiveThrough
block|;
comment|/// Killed - A conservative approximation of the set of blocks in which
comment|/// the value is used and not live-out.
comment|///
name|SmallPtrSet
operator|<
specifier|const
name|BasicBlock
operator|*
block|,
literal|4
operator|>
name|Killed
block|;   }
block|;
comment|/// Memos - Remembers the Memo for each Value. This is populated on
comment|/// demand.
comment|///
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
block|,
name|Memo
operator|>
name|Memos
block|;
comment|/// getMemo - Retrieve an existing Memo for the given value if one
comment|/// is available, otherwise compute a new one.
comment|///
name|Memo
operator|&
name|getMemo
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
block|;
comment|/// compute - Compute a new Memo for the given value.
comment|///
name|Memo
operator|&
name|compute
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|LiveValues
argument_list|()
block|;
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|runOnFunction
argument_list|(
name|Function
operator|&
name|F
argument_list|)
block|;
name|virtual
name|void
name|releaseMemory
argument_list|()
block|;
comment|/// isUsedInBlock - Test if the given value is used in the given block.
comment|///
name|bool
name|isUsedInBlock
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|,
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
comment|/// isLiveThroughBlock - Test if the given value is known to be
comment|/// live-through the given block, meaning that the block is properly
comment|/// dominated by the value's definition, and there exists a block
comment|/// reachable from it that contains a use. This uses a conservative
comment|/// approximation that errs on the side of returning false.
comment|///
name|bool
name|isLiveThroughBlock
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|,
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
comment|/// isKilledInBlock - Test if the given value is known to be killed in
comment|/// the given block, meaning that the block contains a use of the value,
comment|/// and no blocks reachable from the block contain a use. This uses a
comment|/// conservative approximation that errs on the side of returning false.
comment|///
name|bool
name|isKilledInBlock
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|,
specifier|const
name|BasicBlock
operator|*
name|BB
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

end_unit

