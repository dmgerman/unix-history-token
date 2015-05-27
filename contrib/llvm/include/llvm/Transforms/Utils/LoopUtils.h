begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Transforms/Utils/LoopUtils.h - Loop utilities -*- C++ -*-=========//
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
comment|// This file defines some loop transformation utilities.
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
name|LLVM_TRANSFORMS_UTILS_LOOPUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_LOOPUTILS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Dominators.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/IRBuilder.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AliasAnalysis
decl_stmt|;
name|class
name|AliasSet
decl_stmt|;
name|class
name|AliasSetTracker
decl_stmt|;
name|class
name|AssumptionCache
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|DominatorTree
decl_stmt|;
name|class
name|Loop
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
name|class
name|Pass
decl_stmt|;
name|class
name|PredIteratorCache
decl_stmt|;
name|class
name|ScalarEvolution
decl_stmt|;
name|class
name|TargetLibraryInfo
decl_stmt|;
comment|/// \brief Captures loop safety information.
comment|/// It keep information for loop& its header may throw exception.
struct|struct
name|LICMSafetyInfo
block|{
name|bool
name|MayThrow
decl_stmt|;
comment|// The current loop contains an instruction which
comment|// may throw.
name|bool
name|HeaderMayThrow
decl_stmt|;
comment|// Same as previous, but specific to loop header
name|LICMSafetyInfo
argument_list|()
operator|:
name|MayThrow
argument_list|(
name|false
argument_list|)
operator|,
name|HeaderMayThrow
argument_list|(
argument|false
argument_list|)
block|{}
block|}
struct|;
comment|/// This POD struct holds information about a potential reduction operation.
name|class
name|ReductionInstDesc
block|{
name|public
label|:
comment|// This enum represents the kind of minmax reduction.
enum|enum
name|MinMaxReductionKind
block|{
name|MRK_Invalid
block|,
name|MRK_UIntMin
block|,
name|MRK_UIntMax
block|,
name|MRK_SIntMin
block|,
name|MRK_SIntMax
block|,
name|MRK_FloatMin
block|,
name|MRK_FloatMax
block|}
enum|;
name|ReductionInstDesc
argument_list|(
argument|bool IsRedux
argument_list|,
argument|Instruction *I
argument_list|)
block|:
name|IsReduction
argument_list|(
name|IsRedux
argument_list|)
operator|,
name|PatternLastInst
argument_list|(
name|I
argument_list|)
operator|,
name|MinMaxKind
argument_list|(
argument|MRK_Invalid
argument_list|)
block|{}
name|ReductionInstDesc
argument_list|(
argument|Instruction *I
argument_list|,
argument|MinMaxReductionKind K
argument_list|)
operator|:
name|IsReduction
argument_list|(
name|true
argument_list|)
operator|,
name|PatternLastInst
argument_list|(
name|I
argument_list|)
operator|,
name|MinMaxKind
argument_list|(
argument|K
argument_list|)
block|{}
name|bool
name|isReduction
argument_list|()
block|{
return|return
name|IsReduction
return|;
block|}
name|MinMaxReductionKind
name|getMinMaxKind
parameter_list|()
block|{
return|return
name|MinMaxKind
return|;
block|}
name|Instruction
modifier|*
name|getPatternInst
parameter_list|()
block|{
return|return
name|PatternLastInst
return|;
block|}
name|private
label|:
comment|// Is this instruction a reduction candidate.
name|bool
name|IsReduction
decl_stmt|;
comment|// The last instruction in a min/max pattern (select of the select(icmp())
comment|// pattern), or the current reduction instruction otherwise.
name|Instruction
modifier|*
name|PatternLastInst
decl_stmt|;
comment|// If this is a min/max pattern the comparison predicate.
name|MinMaxReductionKind
name|MinMaxKind
decl_stmt|;
block|}
empty_stmt|;
comment|/// This struct holds information about reduction variables.
name|class
name|ReductionDescriptor
block|{
name|public
label|:
comment|/// This enum represents the kinds of reductions that we support.
enum|enum
name|ReductionKind
block|{
name|RK_NoReduction
block|,
comment|///< Not a reduction.
name|RK_IntegerAdd
block|,
comment|///< Sum of integers.
name|RK_IntegerMult
block|,
comment|///< Product of integers.
name|RK_IntegerOr
block|,
comment|///< Bitwise or logical OR of numbers.
name|RK_IntegerAnd
block|,
comment|///< Bitwise or logical AND of numbers.
name|RK_IntegerXor
block|,
comment|///< Bitwise or logical XOR of numbers.
name|RK_IntegerMinMax
block|,
comment|///< Min/max implemented in terms of select(cmp()).
name|RK_FloatAdd
block|,
comment|///< Sum of floats.
name|RK_FloatMult
block|,
comment|///< Product of floats.
name|RK_FloatMinMax
comment|///< Min/max implemented in terms of select(cmp()).
block|}
enum|;
name|ReductionDescriptor
argument_list|()
operator|:
name|StartValue
argument_list|(
name|nullptr
argument_list|)
operator|,
name|LoopExitInstr
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Kind
argument_list|(
name|RK_NoReduction
argument_list|)
operator|,
name|MinMaxKind
argument_list|(
argument|ReductionInstDesc::MRK_Invalid
argument_list|)
block|{}
name|ReductionDescriptor
argument_list|(
argument|Value *Start
argument_list|,
argument|Instruction *Exit
argument_list|,
argument|ReductionKind K
argument_list|,
argument|ReductionInstDesc::MinMaxReductionKind MK
argument_list|)
operator|:
name|StartValue
argument_list|(
name|Start
argument_list|)
operator|,
name|LoopExitInstr
argument_list|(
name|Exit
argument_list|)
operator|,
name|Kind
argument_list|(
name|K
argument_list|)
operator|,
name|MinMaxKind
argument_list|(
argument|MK
argument_list|)
block|{}
comment|/// Returns a struct describing if the instruction 'I' can be a reduction
comment|/// variable of type 'Kind'. If the reduction is a min/max pattern of
comment|/// select(icmp()) this function advances the instruction pointer 'I' from the
comment|/// compare instruction to the select instruction and stores this pointer in
comment|/// 'PatternLastInst' member of the returned struct.
specifier|static
name|ReductionInstDesc
name|isReductionInstr
argument_list|(
argument|Instruction *I
argument_list|,
argument|ReductionKind Kind
argument_list|,
argument|ReductionInstDesc&Prev
argument_list|,
argument|bool HasFunNoNaNAttr
argument_list|)
expr_stmt|;
comment|/// Returns true if instuction I has multiple uses in Insts
specifier|static
name|bool
name|hasMultipleUsesOf
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
name|SmallPtrSetImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|Insts
argument_list|)
decl_stmt|;
comment|/// Returns true if all uses of the instruction I is within the Set.
specifier|static
name|bool
name|areAllUsesIn
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
name|SmallPtrSetImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|Set
argument_list|)
decl_stmt|;
comment|/// Returns a struct describing if the instruction if the instruction is a
comment|/// Select(ICmp(X, Y), X, Y) instruction pattern corresponding to a min(X, Y)
comment|/// or max(X, Y).
specifier|static
name|ReductionInstDesc
name|isMinMaxSelectCmpPattern
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|,
name|ReductionInstDesc
modifier|&
name|Prev
parameter_list|)
function_decl|;
comment|/// Returns identity corresponding to the ReductionKind.
specifier|static
name|Constant
modifier|*
name|getReductionIdentity
parameter_list|(
name|ReductionKind
name|K
parameter_list|,
name|Type
modifier|*
name|Tp
parameter_list|)
function_decl|;
comment|/// Returns the opcode of binary operation corresponding to the ReductionKind.
specifier|static
name|unsigned
name|getReductionBinOp
parameter_list|(
name|ReductionKind
name|Kind
parameter_list|)
function_decl|;
comment|/// Returns a Min/Max operation corresponding to MinMaxReductionKind.
specifier|static
name|Value
modifier|*
name|createMinMaxOp
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|Builder
argument_list|,
name|ReductionInstDesc
operator|::
name|MinMaxReductionKind
name|RK
argument_list|,
name|Value
operator|*
name|Left
argument_list|,
name|Value
operator|*
name|Right
argument_list|)
decl_stmt|;
comment|/// Returns true if Phi is a reduction of type Kind and adds it to the
comment|/// ReductionDescriptor.
specifier|static
name|bool
name|AddReductionVar
parameter_list|(
name|PHINode
modifier|*
name|Phi
parameter_list|,
name|ReductionKind
name|Kind
parameter_list|,
name|Loop
modifier|*
name|TheLoop
parameter_list|,
name|bool
name|HasFunNoNaNAttr
parameter_list|,
name|ReductionDescriptor
modifier|&
name|RedDes
parameter_list|)
function_decl|;
comment|/// Returns true if Phi is a reduction in TheLoop. The ReductionDescriptor is
comment|/// returned in RedDes.
specifier|static
name|bool
name|isReductionPHI
parameter_list|(
name|PHINode
modifier|*
name|Phi
parameter_list|,
name|Loop
modifier|*
name|TheLoop
parameter_list|,
name|ReductionDescriptor
modifier|&
name|RedDes
parameter_list|)
function_decl|;
name|ReductionKind
name|getReductionKind
parameter_list|()
block|{
return|return
name|Kind
return|;
block|}
name|ReductionInstDesc
operator|::
name|MinMaxReductionKind
name|getMinMaxReductionKind
argument_list|()
block|{
return|return
name|MinMaxKind
return|;
block|}
name|TrackingVH
operator|<
name|Value
operator|>
name|getReductionStartValue
argument_list|()
block|{
return|return
name|StartValue
return|;
block|}
name|Instruction
modifier|*
name|getLoopExitInstr
parameter_list|()
block|{
return|return
name|LoopExitInstr
return|;
block|}
name|private
label|:
comment|// The starting value of the reduction.
comment|// It does not have to be zero!
name|TrackingVH
operator|<
name|Value
operator|>
name|StartValue
expr_stmt|;
comment|// The instruction who's value is used outside the loop.
name|Instruction
modifier|*
name|LoopExitInstr
decl_stmt|;
comment|// The kind of the reduction.
name|ReductionKind
name|Kind
decl_stmt|;
comment|// If this a min/max reduction the kind of reduction.
name|ReductionInstDesc
operator|::
name|MinMaxReductionKind
name|MinMaxKind
expr_stmt|;
block|}
empty_stmt|;
name|BasicBlock
modifier|*
name|InsertPreheaderForLoop
parameter_list|(
name|Loop
modifier|*
name|L
parameter_list|,
name|Pass
modifier|*
name|P
parameter_list|)
function_decl|;
comment|/// \brief Simplify each loop in a loop nest recursively.
comment|///
comment|/// This takes a potentially un-simplified loop L (and its children) and turns
comment|/// it into a simplified loop nest with preheaders and single backedges. It
comment|/// will optionally update \c AliasAnalysis and \c ScalarEvolution analyses if
comment|/// passed into it.
name|bool
name|simplifyLoop
parameter_list|(
name|Loop
modifier|*
name|L
parameter_list|,
name|DominatorTree
modifier|*
name|DT
parameter_list|,
name|LoopInfo
modifier|*
name|LI
parameter_list|,
name|Pass
modifier|*
name|PP
parameter_list|,
name|AliasAnalysis
modifier|*
name|AA
init|=
name|nullptr
parameter_list|,
name|ScalarEvolution
modifier|*
name|SE
init|=
name|nullptr
parameter_list|,
name|AssumptionCache
modifier|*
name|AC
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// \brief Put loop into LCSSA form.
comment|///
comment|/// Looks at all instructions in the loop which have uses outside of the
comment|/// current loop. For each, an LCSSA PHI node is inserted and the uses outside
comment|/// the loop are rewritten to use this node.
comment|///
comment|/// LoopInfo and DominatorTree are required and preserved.
comment|///
comment|/// If ScalarEvolution is passed in, it will be preserved.
comment|///
comment|/// Returns true if any modifications are made to the loop.
name|bool
name|formLCSSA
parameter_list|(
name|Loop
modifier|&
name|L
parameter_list|,
name|DominatorTree
modifier|&
name|DT
parameter_list|,
name|LoopInfo
modifier|*
name|LI
parameter_list|,
name|ScalarEvolution
modifier|*
name|SE
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// \brief Put a loop nest into LCSSA form.
comment|///
comment|/// This recursively forms LCSSA for a loop nest.
comment|///
comment|/// LoopInfo and DominatorTree are required and preserved.
comment|///
comment|/// If ScalarEvolution is passed in, it will be preserved.
comment|///
comment|/// Returns true if any modifications are made to the loop.
name|bool
name|formLCSSARecursively
parameter_list|(
name|Loop
modifier|&
name|L
parameter_list|,
name|DominatorTree
modifier|&
name|DT
parameter_list|,
name|LoopInfo
modifier|*
name|LI
parameter_list|,
name|ScalarEvolution
modifier|*
name|SE
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// \brief Walk the specified region of the CFG (defined by all blocks
comment|/// dominated by the specified block, and that are in the current loop) in
comment|/// reverse depth first order w.r.t the DominatorTree. This allows us to visit
comment|/// uses before definitions, allowing us to sink a loop body in one pass without
comment|/// iteration. Takes DomTreeNode, AliasAnalysis, LoopInfo, DominatorTree,
comment|/// DataLayout, TargetLibraryInfo, Loop, AliasSet information for all
comment|/// instructions of the loop and loop safety information as arguments.
comment|/// It returns changed status.
name|bool
name|sinkRegion
parameter_list|(
name|DomTreeNode
modifier|*
parameter_list|,
name|AliasAnalysis
modifier|*
parameter_list|,
name|LoopInfo
modifier|*
parameter_list|,
name|DominatorTree
modifier|*
parameter_list|,
name|TargetLibraryInfo
modifier|*
parameter_list|,
name|Loop
modifier|*
parameter_list|,
name|AliasSetTracker
modifier|*
parameter_list|,
name|LICMSafetyInfo
modifier|*
parameter_list|)
function_decl|;
comment|/// \brief Walk the specified region of the CFG (defined by all blocks
comment|/// dominated by the specified block, and that are in the current loop) in depth
comment|/// first order w.r.t the DominatorTree.  This allows us to visit definitions
comment|/// before uses, allowing us to hoist a loop body in one pass without iteration.
comment|/// Takes DomTreeNode, AliasAnalysis, LoopInfo, DominatorTree, DataLayout,
comment|/// TargetLibraryInfo, Loop, AliasSet information for all instructions of the
comment|/// loop and loop safety information as arguments. It returns changed status.
name|bool
name|hoistRegion
parameter_list|(
name|DomTreeNode
modifier|*
parameter_list|,
name|AliasAnalysis
modifier|*
parameter_list|,
name|LoopInfo
modifier|*
parameter_list|,
name|DominatorTree
modifier|*
parameter_list|,
name|TargetLibraryInfo
modifier|*
parameter_list|,
name|Loop
modifier|*
parameter_list|,
name|AliasSetTracker
modifier|*
parameter_list|,
name|LICMSafetyInfo
modifier|*
parameter_list|)
function_decl|;
comment|/// \brief Try to promote memory values to scalars by sinking stores out of
comment|/// the loop and moving loads to before the loop.  We do this by looping over
comment|/// the stores in the loop, looking for stores to Must pointers which are
comment|/// loop invariant. It takes AliasSet, Loop exit blocks vector, loop exit blocks
comment|/// insertion point vector, PredIteratorCache, LoopInfo, DominatorTree, Loop,
comment|/// AliasSet information for all instructions of the loop and loop safety
comment|/// information as arguments. It returns changed status.
name|bool
name|promoteLoopAccessesToScalars
argument_list|(
name|AliasSet
operator|&
argument_list|,
name|SmallVectorImpl
operator|<
name|BasicBlock
operator|*
operator|>
operator|&
argument_list|,
name|SmallVectorImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
argument_list|,
name|PredIteratorCache
operator|&
argument_list|,
name|LoopInfo
operator|*
argument_list|,
name|DominatorTree
operator|*
argument_list|,
name|Loop
operator|*
argument_list|,
name|AliasSetTracker
operator|*
argument_list|,
name|LICMSafetyInfo
operator|*
argument_list|)
decl_stmt|;
comment|/// \brief Computes safety information for a loop
comment|/// checks loop body& header for the possiblity of may throw
comment|/// exception, it takes LICMSafetyInfo and loop as argument.
comment|/// Updates safety information in LICMSafetyInfo argument.
name|void
name|computeLICMSafetyInfo
parameter_list|(
name|LICMSafetyInfo
modifier|*
parameter_list|,
name|Loop
modifier|*
parameter_list|)
function_decl|;
comment|/// \brief Checks if the given PHINode in a loop header is an induction
comment|/// variable. Returns true if this is an induction PHI along with the step
comment|/// value.
name|bool
name|isInductionPHI
parameter_list|(
name|PHINode
modifier|*
parameter_list|,
name|ScalarEvolution
modifier|*
parameter_list|,
name|ConstantInt
modifier|*
modifier|&
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

