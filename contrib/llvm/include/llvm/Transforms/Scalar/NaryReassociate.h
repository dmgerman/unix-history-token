begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- NaryReassociate.h - Reassociate n-ary expressions ------------------===//
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
comment|// This pass reassociates n-ary add expressions and eliminates the redundancy
end_comment

begin_comment
comment|// exposed by the reassociation.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A motivating example:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   void foo(int a, int b) {
end_comment

begin_comment
comment|//     bar(a + b);
end_comment

begin_comment
comment|//     bar((a + 2) + b);
end_comment

begin_comment
comment|//   }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// An ideal compiler should reassociate (a + 2) + b to (a + b) + 2 and simplify
end_comment

begin_comment
comment|// the above code to
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   int t = a + b;
end_comment

begin_comment
comment|//   bar(t);
end_comment

begin_comment
comment|//   bar(t + 2);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// However, the Reassociate pass is unable to do that because it processes each
end_comment

begin_comment
comment|// instruction individually and believes (a + 2) + b is the best form according
end_comment

begin_comment
comment|// to its rank system.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// To address this limitation, NaryReassociate reassociates an expression in a
end_comment

begin_comment
comment|// form that reuses existing instructions. As a result, NaryReassociate can
end_comment

begin_comment
comment|// reassociate (a + 2) + b in the example to (a + b) + 2 because it detects that
end_comment

begin_comment
comment|// (a + b) is computed before.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NaryReassociate works as follows. For every instruction in the form of (a +
end_comment

begin_comment
comment|// b) + c, it checks whether a + c or b + c is already computed by a dominating
end_comment

begin_comment
comment|// instruction. If so, it then reassociates (a + b) + c into (a + c) + b or (b +
end_comment

begin_comment
comment|// c) + a and removes the redundancy accordingly. To efficiently look up whether
end_comment

begin_comment
comment|// an expression is computed before, we store each instruction seen and its SCEV
end_comment

begin_comment
comment|// into an SCEV-to-instruction map.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Although the algorithm pattern-matches only ternary additions, it
end_comment

begin_comment
comment|// automatically handles many>3-ary expressions by walking through the function
end_comment

begin_comment
comment|// in the depth-first order. For example, given
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   (a + c) + d
end_comment

begin_comment
comment|//   ((a + b) + c) + d
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NaryReassociate first rewrites (a + b) + c to (a + c) + b, and then rewrites
end_comment

begin_comment
comment|// ((a + c) + b) + d into ((a + c) + d) + b.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Finally, the above dominator-based algorithm may need to be run multiple
end_comment

begin_comment
comment|// iterations before emitting optimal code. One source of this need is that we
end_comment

begin_comment
comment|// only split an operand when it is used only once. The above algorithm can
end_comment

begin_comment
comment|// eliminate an instruction and decrease the usage count of its operands. As a
end_comment

begin_comment
comment|// result, an instruction that previously had multiple uses may become a
end_comment

begin_comment
comment|// single-use instruction and thus eligible for split consideration. For
end_comment

begin_comment
comment|// example,
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   ac = a + c
end_comment

begin_comment
comment|//   ab = a + b
end_comment

begin_comment
comment|//   abc = ab + c
end_comment

begin_comment
comment|//   ab2 = ab + b
end_comment

begin_comment
comment|//   ab2c = ab2 + c
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// In the first iteration, we cannot reassociate abc to ac+b because ab is used
end_comment

begin_comment
comment|// twice. However, we can reassociate ab2c to abc+b in the first iteration. As a
end_comment

begin_comment
comment|// result, ab2 becomes dead and ab will be used only once in the second
end_comment

begin_comment
comment|// iteration.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Limitations and TODO items:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 1) We only considers n-ary adds and muls for now. This should be extended
end_comment

begin_comment
comment|// and generalized.
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
name|LLVM_TRANSFORMS_SCALAR_NARYREASSOCIATE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_NARYREASSOCIATE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AssumptionCache.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/ScalarEvolution.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/TargetLibraryInfo.h"
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
file|"llvm/IR/Function.h"
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
name|NaryReassociatePass
range|:
name|public
name|PassInfoMixin
operator|<
name|NaryReassociatePass
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
name|AssumptionCache
operator|*
name|AC_
argument_list|,
name|DominatorTree
operator|*
name|DT_
argument_list|,
name|ScalarEvolution
operator|*
name|SE_
argument_list|,
name|TargetLibraryInfo
operator|*
name|TLI_
argument_list|,
name|TargetTransformInfo
operator|*
name|TTI_
argument_list|)
block|;
name|private
operator|:
comment|// Runs only one iteration of the dominator-based algorithm. See the header
comment|// comments for why we need multiple iterations.
name|bool
name|doOneIteration
argument_list|(
name|Function
operator|&
name|F
argument_list|)
block|;
comment|// Reassociates I for better CSE.
name|Instruction
operator|*
name|tryReassociate
argument_list|(
name|Instruction
operator|*
name|I
argument_list|)
block|;
comment|// Reassociate GEP for better CSE.
name|Instruction
operator|*
name|tryReassociateGEP
argument_list|(
name|GetElementPtrInst
operator|*
name|GEP
argument_list|)
block|;
comment|// Try splitting GEP at the I-th index and see whether either part can be
comment|// CSE'ed. This is a helper function for tryReassociateGEP.
comment|//
comment|// \p IndexedType The element type indexed by GEP's I-th index. This is
comment|//                equivalent to
comment|//                  GEP->getIndexedType(GEP->getPointerOperand(), 0-th index,
comment|//                                      ..., i-th index).
name|GetElementPtrInst
operator|*
name|tryReassociateGEPAtIndex
argument_list|(
argument|GetElementPtrInst *GEP
argument_list|,
argument|unsigned I
argument_list|,
argument|Type *IndexedType
argument_list|)
block|;
comment|// Given GEP's I-th index = LHS + RHS, see whether&Base[..][LHS][..] or
comment|//&Base[..][RHS][..] can be CSE'ed and rewrite GEP accordingly.
name|GetElementPtrInst
operator|*
name|tryReassociateGEPAtIndex
argument_list|(
argument|GetElementPtrInst *GEP
argument_list|,
argument|unsigned I
argument_list|,
argument|Value *LHS
argument_list|,
argument|Value *RHS
argument_list|,
argument|Type *IndexedType
argument_list|)
block|;
comment|// Reassociate binary operators for better CSE.
name|Instruction
operator|*
name|tryReassociateBinaryOp
argument_list|(
name|BinaryOperator
operator|*
name|I
argument_list|)
block|;
comment|// A helper function for tryReassociateBinaryOp. LHS and RHS are explicitly
comment|// passed.
name|Instruction
operator|*
name|tryReassociateBinaryOp
argument_list|(
name|Value
operator|*
name|LHS
argument_list|,
name|Value
operator|*
name|RHS
argument_list|,
name|BinaryOperator
operator|*
name|I
argument_list|)
block|;
comment|// Rewrites I to (LHS op RHS) if LHS is computed already.
name|Instruction
operator|*
name|tryReassociatedBinaryOp
argument_list|(
specifier|const
name|SCEV
operator|*
name|LHS
argument_list|,
name|Value
operator|*
name|RHS
argument_list|,
name|BinaryOperator
operator|*
name|I
argument_list|)
block|;
comment|// Tries to match Op1 and Op2 by using V.
name|bool
name|matchTernaryOp
argument_list|(
name|BinaryOperator
operator|*
name|I
argument_list|,
name|Value
operator|*
name|V
argument_list|,
name|Value
operator|*
operator|&
name|Op1
argument_list|,
name|Value
operator|*
operator|&
name|Op2
argument_list|)
block|;
comment|// Gets SCEV for (LHS op RHS).
specifier|const
name|SCEV
operator|*
name|getBinarySCEV
argument_list|(
name|BinaryOperator
operator|*
name|I
argument_list|,
specifier|const
name|SCEV
operator|*
name|LHS
argument_list|,
specifier|const
name|SCEV
operator|*
name|RHS
argument_list|)
block|;
comment|// Returns the closest dominator of \c Dominatee that computes
comment|// \c CandidateExpr. Returns null if not found.
name|Instruction
operator|*
name|findClosestMatchingDominator
argument_list|(
specifier|const
name|SCEV
operator|*
name|CandidateExpr
argument_list|,
name|Instruction
operator|*
name|Dominatee
argument_list|)
block|;
comment|// GetElementPtrInst implicitly sign-extends an index if the index is shorter
comment|// than the pointer size. This function returns whether Index is shorter than
comment|// GEP's pointer size, i.e., whether Index needs to be sign-extended in order
comment|// to be an index of GEP.
name|bool
name|requiresSignExtension
argument_list|(
name|Value
operator|*
name|Index
argument_list|,
name|GetElementPtrInst
operator|*
name|GEP
argument_list|)
block|;
name|AssumptionCache
operator|*
name|AC
block|;
specifier|const
name|DataLayout
operator|*
name|DL
block|;
name|DominatorTree
operator|*
name|DT
block|;
name|ScalarEvolution
operator|*
name|SE
block|;
name|TargetLibraryInfo
operator|*
name|TLI
block|;
name|TargetTransformInfo
operator|*
name|TTI
block|;
comment|// A lookup table quickly telling which instructions compute the given SCEV.
comment|// Note that there can be multiple instructions at different locations
comment|// computing to the same SCEV, so we map a SCEV to an instruction list.  For
comment|// example,
comment|//
comment|//   if (p1)
comment|//     foo(a + b);
comment|//   if (p2)
comment|//     bar(a + b);
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
block|,
name|SmallVector
operator|<
name|WeakTrackingVH
block|,
literal|2
operator|>>
name|SeenExprs
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_SCALAR_NARYREASSOCIATE_H
end_comment

end_unit

