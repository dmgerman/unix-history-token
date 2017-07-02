begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ConstantHoisting.h - Prepare code for expensive constants ---------===//
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
comment|// This pass identifies expensive constants to hoist and coalesces them to
end_comment

begin_comment
comment|// better prepare it for SelectionDAG-based code generation. This works around
end_comment

begin_comment
comment|// the limitations of the basic-block-at-a-time approach.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// First it scans all instructions for integer constants and calculates its
end_comment

begin_comment
comment|// cost. If the constant can be folded into the instruction (the cost is
end_comment

begin_comment
comment|// TCC_Free) or the cost is just a simple operation (TCC_BASIC), then we don't
end_comment

begin_comment
comment|// consider it expensive and leave it alone. This is the default behavior and
end_comment

begin_comment
comment|// the default implementation of getIntImmCost will always return TCC_Free.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If the cost is more than TCC_BASIC, then the integer constant can't be folded
end_comment

begin_comment
comment|// into the instruction and it might be beneficial to hoist the constant.
end_comment

begin_comment
comment|// Similar constants are coalesced to reduce register pressure and
end_comment

begin_comment
comment|// materialization code.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// When a constant is hoisted, it is also hidden behind a bitcast to force it to
end_comment

begin_comment
comment|// be live-out of the basic block. Otherwise the constant would be just
end_comment

begin_comment
comment|// duplicated and each basic block would have its own copy in the SelectionDAG.
end_comment

begin_comment
comment|// The SelectionDAG recognizes such constants as opaque and doesn't perform
end_comment

begin_comment
comment|// certain transformations on them, which would create a new expensive constant.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This optimization is only applied to integer constants in instructions and
end_comment

begin_comment
comment|// simple (this means not nested) constant cast expressions. For example:
end_comment

begin_comment
comment|// %0 = load i64* inttoptr (i64 big_constant to i64*)
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TRANSFORMS_SCALAR_CONSTANTHOISTING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_CONSTANTHOISTING_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/BlockFrequencyInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/TargetTransformInfo.h"
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
comment|/// A private "module" namespace for types and utilities used by
comment|/// ConstantHoisting. These are implementation details and should not be used by
comment|/// clients.
name|namespace
name|consthoist
block|{
comment|/// \brief Keeps track of the user of a constant and the operand index where the
comment|/// constant is used.
struct|struct
name|ConstantUser
block|{
name|Instruction
modifier|*
name|Inst
decl_stmt|;
name|unsigned
name|OpndIdx
decl_stmt|;
name|ConstantUser
argument_list|(
argument|Instruction *Inst
argument_list|,
argument|unsigned Idx
argument_list|)
block|:
name|Inst
argument_list|(
name|Inst
argument_list|)
operator|,
name|OpndIdx
argument_list|(
argument|Idx
argument_list|)
block|{ }
block|}
struct|;
typedef|typedef
name|SmallVector
operator|<
name|ConstantUser
operator|,
literal|8
operator|>
name|ConstantUseListType
expr_stmt|;
comment|/// \brief Keeps track of a constant candidate and its uses.
struct|struct
name|ConstantCandidate
block|{
name|ConstantUseListType
name|Uses
decl_stmt|;
name|ConstantInt
modifier|*
name|ConstInt
decl_stmt|;
name|unsigned
name|CumulativeCost
decl_stmt|;
name|ConstantCandidate
argument_list|(
name|ConstantInt
operator|*
name|ConstInt
argument_list|)
operator|:
name|ConstInt
argument_list|(
name|ConstInt
argument_list|)
operator|,
name|CumulativeCost
argument_list|(
literal|0
argument_list|)
block|{ }
comment|/// \brief Add the user to the use list and update the cost.
name|void
name|addUser
argument_list|(
argument|Instruction *Inst
argument_list|,
argument|unsigned Idx
argument_list|,
argument|unsigned Cost
argument_list|)
block|{
name|CumulativeCost
operator|+=
name|Cost
block|;
name|Uses
operator|.
name|push_back
argument_list|(
name|ConstantUser
argument_list|(
name|Inst
argument_list|,
name|Idx
argument_list|)
argument_list|)
block|;   }
block|}
struct|;
comment|/// \brief This represents a constant that has been rebased with respect to a
comment|/// base constant. The difference to the base constant is recorded in Offset.
struct|struct
name|RebasedConstantInfo
block|{
name|ConstantUseListType
name|Uses
decl_stmt|;
name|Constant
modifier|*
name|Offset
decl_stmt|;
name|RebasedConstantInfo
argument_list|(
name|ConstantUseListType
operator|&&
name|Uses
argument_list|,
name|Constant
operator|*
name|Offset
argument_list|)
operator|:
name|Uses
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Uses
argument_list|)
argument_list|)
operator|,
name|Offset
argument_list|(
argument|Offset
argument_list|)
block|{ }
block|}
struct|;
typedef|typedef
name|SmallVector
operator|<
name|RebasedConstantInfo
operator|,
literal|4
operator|>
name|RebasedConstantListType
expr_stmt|;
comment|/// \brief A base constant and all its rebased constants.
struct|struct
name|ConstantInfo
block|{
name|ConstantInt
modifier|*
name|BaseConstant
decl_stmt|;
name|RebasedConstantListType
name|RebasedConstants
decl_stmt|;
block|}
struct|;
block|}
name|class
name|ConstantHoistingPass
range|:
name|public
name|PassInfoMixin
operator|<
name|ConstantHoistingPass
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
block|;
comment|// Glue for old PM.
name|bool
name|runImpl
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|TargetTransformInfo
operator|&
name|TTI
argument_list|,
name|DominatorTree
operator|&
name|DT
argument_list|,
name|BlockFrequencyInfo
operator|*
name|BFI
argument_list|,
name|BasicBlock
operator|&
name|Entry
argument_list|)
block|;
name|void
name|releaseMemory
argument_list|()
block|{
name|ConstantVec
operator|.
name|clear
argument_list|()
block|;
name|ClonedCastMap
operator|.
name|clear
argument_list|()
block|;
name|ConstCandVec
operator|.
name|clear
argument_list|()
block|;   }
name|private
operator|:
typedef|typedef
name|DenseMap
operator|<
name|ConstantInt
operator|*
operator|,
name|unsigned
operator|>
name|ConstCandMapType
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|consthoist
operator|::
name|ConstantCandidate
operator|>
name|ConstCandVecType
expr_stmt|;
specifier|const
name|TargetTransformInfo
modifier|*
name|TTI
decl_stmt|;
name|DominatorTree
modifier|*
name|DT
decl_stmt|;
name|BlockFrequencyInfo
modifier|*
name|BFI
decl_stmt|;
name|BasicBlock
modifier|*
name|Entry
decl_stmt|;
comment|/// Keeps track of constant candidates found in the function.
name|ConstCandVecType
name|ConstCandVec
decl_stmt|;
comment|/// Keep track of cast instructions we already cloned.
name|SmallDenseMap
operator|<
name|Instruction
operator|*
operator|,
name|Instruction
operator|*
operator|>
name|ClonedCastMap
expr_stmt|;
comment|/// These are the final constants we decided to hoist.
name|SmallVector
operator|<
name|consthoist
operator|::
name|ConstantInfo
operator|,
literal|8
operator|>
name|ConstantVec
expr_stmt|;
name|Instruction
modifier|*
name|findMatInsertPt
argument_list|(
name|Instruction
operator|*
name|Inst
argument_list|,
name|unsigned
name|Idx
operator|=
operator|~
literal|0U
argument_list|)
decl|const
decl_stmt|;
name|SmallPtrSet
operator|<
name|Instruction
operator|*
operator|,
literal|8
operator|>
name|findConstantInsertionPoint
argument_list|(
argument|const consthoist::ConstantInfo&ConstInfo
argument_list|)
specifier|const
expr_stmt|;
name|void
name|collectConstantCandidates
parameter_list|(
name|ConstCandMapType
modifier|&
name|ConstCandMap
parameter_list|,
name|Instruction
modifier|*
name|Inst
parameter_list|,
name|unsigned
name|Idx
parameter_list|,
name|ConstantInt
modifier|*
name|ConstInt
parameter_list|)
function_decl|;
name|void
name|collectConstantCandidates
parameter_list|(
name|ConstCandMapType
modifier|&
name|ConstCandMap
parameter_list|,
name|Instruction
modifier|*
name|Inst
parameter_list|,
name|unsigned
name|Idx
parameter_list|)
function_decl|;
name|void
name|collectConstantCandidates
parameter_list|(
name|ConstCandMapType
modifier|&
name|ConstCandMap
parameter_list|,
name|Instruction
modifier|*
name|Inst
parameter_list|)
function_decl|;
name|void
name|collectConstantCandidates
parameter_list|(
name|Function
modifier|&
name|Fn
parameter_list|)
function_decl|;
name|void
name|findAndMakeBaseConstant
argument_list|(
name|ConstCandVecType
operator|::
name|iterator
name|S
argument_list|,
name|ConstCandVecType
operator|::
name|iterator
name|E
argument_list|)
decl_stmt|;
name|unsigned
name|maximizeConstantsInRange
argument_list|(
name|ConstCandVecType
operator|::
name|iterator
name|S
argument_list|,
name|ConstCandVecType
operator|::
name|iterator
name|E
argument_list|,
name|ConstCandVecType
operator|::
name|iterator
operator|&
name|MaxCostItr
argument_list|)
decl_stmt|;
name|void
name|findBaseConstants
parameter_list|()
function_decl|;
name|void
name|emitBaseConstants
argument_list|(
name|Instruction
operator|*
name|Base
argument_list|,
name|Constant
operator|*
name|Offset
argument_list|,
specifier|const
name|consthoist
operator|::
name|ConstantUser
operator|&
name|ConstUser
argument_list|)
decl_stmt|;
name|bool
name|emitBaseConstants
parameter_list|()
function_decl|;
name|void
name|deleteDeadCastInst
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|optimizeConstants
parameter_list|(
name|Function
modifier|&
name|Fn
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_SCALAR_CONSTANTHOISTING_H
end_comment

end_unit

