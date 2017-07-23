begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Reassociate.h - Reassociate binary expressions -----------*- C++ -*-===//
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
comment|// This pass reassociates commutative expressions in an order that is designed
end_comment

begin_comment
comment|// to promote better constant propagation, GCSE, LICM, PRE, etc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For example: 4 + (x + 5) -> x + (4 + 5)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// In the implementation of this algorithm, constants are assigned rank = 0,
end_comment

begin_comment
comment|// function arguments are rank = 1, and other values are assigned ranks
end_comment

begin_comment
comment|// corresponding to the reverse post order traversal of current function
end_comment

begin_comment
comment|// (starting at 2), which effectively gives values in deep loops higher rank
end_comment

begin_comment
comment|// than values not in loops.
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
name|LLVM_TRANSFORMS_SCALAR_REASSOCIATE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_REASSOCIATE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/PostOrderIterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/IRBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Operator.h"
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
comment|/// A private "module" namespace for types and utilities used by Reassociate.
comment|/// These are implementation details and should not be used by clients.
name|namespace
name|reassociate
block|{
struct|struct
name|ValueEntry
block|{
name|unsigned
name|Rank
decl_stmt|;
name|Value
modifier|*
name|Op
decl_stmt|;
name|ValueEntry
argument_list|(
argument|unsigned R
argument_list|,
argument|Value *O
argument_list|)
block|:
name|Rank
argument_list|(
name|R
argument_list|)
operator|,
name|Op
argument_list|(
argument|O
argument_list|)
block|{}
block|}
struct|;
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|ValueEntry
operator|&
name|LHS
operator|,
specifier|const
name|ValueEntry
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|Rank
operator|>
name|RHS
operator|.
name|Rank
return|;
comment|// Sort so that highest rank goes to start.
block|}
comment|/// \brief Utility class representing a base and exponent pair which form one
comment|/// factor of some product.
struct|struct
name|Factor
block|{
name|Value
modifier|*
name|Base
decl_stmt|;
name|unsigned
name|Power
decl_stmt|;
name|Factor
argument_list|(
argument|Value *Base
argument_list|,
argument|unsigned Power
argument_list|)
block|:
name|Base
argument_list|(
name|Base
argument_list|)
operator|,
name|Power
argument_list|(
argument|Power
argument_list|)
block|{}
block|}
struct|;
name|class
name|XorOpnd
decl_stmt|;
block|}
comment|/// Reassociate commutative expressions.
name|class
name|ReassociatePass
range|:
name|public
name|PassInfoMixin
operator|<
name|ReassociatePass
operator|>
block|{
name|DenseMap
operator|<
name|BasicBlock
operator|*
block|,
name|unsigned
operator|>
name|RankMap
block|;
name|DenseMap
operator|<
name|AssertingVH
operator|<
name|Value
operator|>
block|,
name|unsigned
operator|>
name|ValueRankMap
block|;
name|SetVector
operator|<
name|AssertingVH
operator|<
name|Instruction
operator|>>
name|RedoInsts
block|;
name|bool
name|MadeChange
block|;
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
argument_list|)
block|;
name|private
operator|:
name|void
name|BuildRankMap
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|ReversePostOrderTraversal
operator|<
name|Function
operator|*
operator|>
operator|&
name|RPOT
argument_list|)
block|;
name|unsigned
name|getRank
argument_list|(
name|Value
operator|*
name|V
argument_list|)
block|;
name|void
name|canonicalizeOperands
argument_list|(
name|Instruction
operator|*
name|I
argument_list|)
block|;
name|void
name|ReassociateExpression
argument_list|(
name|BinaryOperator
operator|*
name|I
argument_list|)
block|;
name|void
name|RewriteExprTree
argument_list|(
name|BinaryOperator
operator|*
name|I
argument_list|,
name|SmallVectorImpl
operator|<
name|reassociate
operator|::
name|ValueEntry
operator|>
operator|&
name|Ops
argument_list|)
block|;
name|Value
operator|*
name|OptimizeExpression
argument_list|(
name|BinaryOperator
operator|*
name|I
argument_list|,
name|SmallVectorImpl
operator|<
name|reassociate
operator|::
name|ValueEntry
operator|>
operator|&
name|Ops
argument_list|)
block|;
name|Value
operator|*
name|OptimizeAdd
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
name|SmallVectorImpl
operator|<
name|reassociate
operator|::
name|ValueEntry
operator|>
operator|&
name|Ops
argument_list|)
block|;
name|Value
operator|*
name|OptimizeXor
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
name|SmallVectorImpl
operator|<
name|reassociate
operator|::
name|ValueEntry
operator|>
operator|&
name|Ops
argument_list|)
block|;
name|bool
name|CombineXorOpnd
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
name|reassociate
operator|::
name|XorOpnd
operator|*
name|Opnd1
argument_list|,
name|APInt
operator|&
name|ConstOpnd
argument_list|,
name|Value
operator|*
operator|&
name|Res
argument_list|)
block|;
name|bool
name|CombineXorOpnd
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
name|reassociate
operator|::
name|XorOpnd
operator|*
name|Opnd1
argument_list|,
name|reassociate
operator|::
name|XorOpnd
operator|*
name|Opnd2
argument_list|,
name|APInt
operator|&
name|ConstOpnd
argument_list|,
name|Value
operator|*
operator|&
name|Res
argument_list|)
block|;
name|Value
operator|*
name|buildMinimalMultiplyDAG
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|Builder
argument_list|,
name|SmallVectorImpl
operator|<
name|reassociate
operator|::
name|Factor
operator|>
operator|&
name|Factors
argument_list|)
block|;
name|Value
operator|*
name|OptimizeMul
argument_list|(
name|BinaryOperator
operator|*
name|I
argument_list|,
name|SmallVectorImpl
operator|<
name|reassociate
operator|::
name|ValueEntry
operator|>
operator|&
name|Ops
argument_list|)
block|;
name|Value
operator|*
name|RemoveFactorFromExpression
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|Value
operator|*
name|Factor
argument_list|)
block|;
name|void
name|EraseInst
argument_list|(
name|Instruction
operator|*
name|I
argument_list|)
block|;
name|void
name|RecursivelyEraseDeadInsts
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
name|SetVector
operator|<
name|AssertingVH
operator|<
name|Instruction
operator|>>
operator|&
name|Insts
argument_list|)
block|;
name|void
name|OptimizeInst
argument_list|(
name|Instruction
operator|*
name|I
argument_list|)
block|;
name|Instruction
operator|*
name|canonicalizeNegConstExpr
argument_list|(
name|Instruction
operator|*
name|I
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
comment|// LLVM_TRANSFORMS_SCALAR_REASSOCIATE_H
end_comment

end_unit

