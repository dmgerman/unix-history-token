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
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/EHPersonalities.h"
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
comment|// Used to update funclet bundle operands.
name|DenseMap
operator|<
name|BasicBlock
operator|*
operator|,
name|ColorVector
operator|>
name|BlockColors
expr_stmt|;
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
comment|/// The RecurrenceDescriptor is used to identify recurrences variables in a
comment|/// loop. Reduction is a special case of recurrence that has uses of the
comment|/// recurrence variable outside the loop. The method isReductionPHI identifies
comment|/// reductions that are basic recurrences.
comment|///
comment|/// Basic recurrences are defined as the summation, product, OR, AND, XOR, min,
comment|/// or max of a set of terms. For example: for(i=0; i<n; i++) { total +=
comment|/// array[i]; } is a summation of array elements. Basic recurrences are a
comment|/// special case of chains of recurrences (CR). See ScalarEvolution for CR
comment|/// references.
comment|/// This struct holds information about recurrence variables.
name|class
name|RecurrenceDescriptor
block|{
name|public
label|:
comment|/// This enum represents the kinds of recurrences that we support.
enum|enum
name|RecurrenceKind
block|{
name|RK_NoRecurrence
block|,
comment|///< Not a recurrence.
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
comment|// This enum represents the kind of minmax recurrence.
enum|enum
name|MinMaxRecurrenceKind
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
name|RecurrenceDescriptor
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
name|RK_NoRecurrence
argument_list|)
operator|,
name|MinMaxKind
argument_list|(
name|MRK_Invalid
argument_list|)
operator|,
name|UnsafeAlgebraInst
argument_list|(
name|nullptr
argument_list|)
operator|,
name|RecurrenceType
argument_list|(
name|nullptr
argument_list|)
operator|,
name|IsSigned
argument_list|(
argument|false
argument_list|)
block|{}
name|RecurrenceDescriptor
argument_list|(
argument|Value *Start
argument_list|,
argument|Instruction *Exit
argument_list|,
argument|RecurrenceKind K
argument_list|,
argument|MinMaxRecurrenceKind MK
argument_list|,
argument|Instruction *UAI
argument_list|,
argument|Type *RT
argument_list|,
argument|bool Signed
argument_list|,
argument|SmallPtrSetImpl<Instruction *>&CI
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
name|MK
argument_list|)
operator|,
name|UnsafeAlgebraInst
argument_list|(
name|UAI
argument_list|)
operator|,
name|RecurrenceType
argument_list|(
name|RT
argument_list|)
operator|,
name|IsSigned
argument_list|(
argument|Signed
argument_list|)
block|{
name|CastInsts
operator|.
name|insert
argument_list|(
name|CI
operator|.
name|begin
argument_list|()
argument_list|,
name|CI
operator|.
name|end
argument_list|()
argument_list|)
block|;   }
comment|/// This POD struct holds information about a potential recurrence operation.
name|class
name|InstDesc
block|{
name|public
operator|:
name|InstDesc
argument_list|(
argument|bool IsRecur
argument_list|,
argument|Instruction *I
argument_list|,
argument|Instruction *UAI = nullptr
argument_list|)
operator|:
name|IsRecurrence
argument_list|(
name|IsRecur
argument_list|)
block|,
name|PatternLastInst
argument_list|(
name|I
argument_list|)
block|,
name|MinMaxKind
argument_list|(
name|MRK_Invalid
argument_list|)
block|,
name|UnsafeAlgebraInst
argument_list|(
argument|UAI
argument_list|)
block|{}
name|InstDesc
argument_list|(
argument|Instruction *I
argument_list|,
argument|MinMaxRecurrenceKind K
argument_list|,
argument|Instruction *UAI = nullptr
argument_list|)
operator|:
name|IsRecurrence
argument_list|(
name|true
argument_list|)
block|,
name|PatternLastInst
argument_list|(
name|I
argument_list|)
block|,
name|MinMaxKind
argument_list|(
name|K
argument_list|)
block|,
name|UnsafeAlgebraInst
argument_list|(
argument|UAI
argument_list|)
block|{}
name|bool
name|isRecurrence
argument_list|()
block|{
return|return
name|IsRecurrence
return|;
block|}
name|bool
name|hasUnsafeAlgebra
argument_list|()
block|{
return|return
name|UnsafeAlgebraInst
operator|!=
name|nullptr
return|;
block|}
name|Instruction
operator|*
name|getUnsafeAlgebraInst
argument_list|()
block|{
return|return
name|UnsafeAlgebraInst
return|;
block|}
name|MinMaxRecurrenceKind
name|getMinMaxKind
argument_list|()
block|{
return|return
name|MinMaxKind
return|;
block|}
name|Instruction
operator|*
name|getPatternInst
argument_list|()
block|{
return|return
name|PatternLastInst
return|;
block|}
name|private
operator|:
comment|// Is this instruction a recurrence candidate.
name|bool
name|IsRecurrence
block|;
comment|// The last instruction in a min/max pattern (select of the select(icmp())
comment|// pattern), or the current recurrence instruction otherwise.
name|Instruction
operator|*
name|PatternLastInst
block|;
comment|// If this is a min/max pattern the comparison predicate.
name|MinMaxRecurrenceKind
name|MinMaxKind
block|;
comment|// Recurrence has unsafe algebra.
name|Instruction
operator|*
name|UnsafeAlgebraInst
block|;   }
expr_stmt|;
comment|/// Returns a struct describing if the instruction 'I' can be a recurrence
comment|/// variable of type 'Kind'. If the recurrence is a min/max pattern of
comment|/// select(icmp()) this function advances the instruction pointer 'I' from the
comment|/// compare instruction to the select instruction and stores this pointer in
comment|/// 'PatternLastInst' member of the returned struct.
specifier|static
name|InstDesc
name|isRecurrenceInstr
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|,
name|RecurrenceKind
name|Kind
parameter_list|,
name|InstDesc
modifier|&
name|Prev
parameter_list|,
name|bool
name|HasFunNoNaNAttr
parameter_list|)
function_decl|;
comment|/// Returns true if instruction I has multiple uses in Insts
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
name|InstDesc
name|isMinMaxSelectCmpPattern
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|,
name|InstDesc
modifier|&
name|Prev
parameter_list|)
function_decl|;
comment|/// Returns identity corresponding to the RecurrenceKind.
specifier|static
name|Constant
modifier|*
name|getRecurrenceIdentity
parameter_list|(
name|RecurrenceKind
name|K
parameter_list|,
name|Type
modifier|*
name|Tp
parameter_list|)
function_decl|;
comment|/// Returns the opcode of binary operation corresponding to the
comment|/// RecurrenceKind.
specifier|static
name|unsigned
name|getRecurrenceBinOp
parameter_list|(
name|RecurrenceKind
name|Kind
parameter_list|)
function_decl|;
comment|/// Returns a Min/Max operation corresponding to MinMaxRecurrenceKind.
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
name|MinMaxRecurrenceKind
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
comment|/// RecurrenceDescriptor.
specifier|static
name|bool
name|AddReductionVar
parameter_list|(
name|PHINode
modifier|*
name|Phi
parameter_list|,
name|RecurrenceKind
name|Kind
parameter_list|,
name|Loop
modifier|*
name|TheLoop
parameter_list|,
name|bool
name|HasFunNoNaNAttr
parameter_list|,
name|RecurrenceDescriptor
modifier|&
name|RedDes
parameter_list|)
function_decl|;
comment|/// Returns true if Phi is a reduction in TheLoop. The RecurrenceDescriptor is
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
name|RecurrenceDescriptor
modifier|&
name|RedDes
parameter_list|)
function_decl|;
name|RecurrenceKind
name|getRecurrenceKind
parameter_list|()
block|{
return|return
name|Kind
return|;
block|}
name|MinMaxRecurrenceKind
name|getMinMaxRecurrenceKind
parameter_list|()
block|{
return|return
name|MinMaxKind
return|;
block|}
name|TrackingVH
operator|<
name|Value
operator|>
name|getRecurrenceStartValue
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
comment|/// Returns true if the recurrence has unsafe algebra which requires a relaxed
comment|/// floating-point model.
name|bool
name|hasUnsafeAlgebra
parameter_list|()
block|{
return|return
name|UnsafeAlgebraInst
operator|!=
name|nullptr
return|;
block|}
comment|/// Returns first unsafe algebra instruction in the PHI node's use-chain.
name|Instruction
modifier|*
name|getUnsafeAlgebraInst
parameter_list|()
block|{
return|return
name|UnsafeAlgebraInst
return|;
block|}
comment|/// Returns true if the recurrence kind is an integer kind.
specifier|static
name|bool
name|isIntegerRecurrenceKind
parameter_list|(
name|RecurrenceKind
name|Kind
parameter_list|)
function_decl|;
comment|/// Returns true if the recurrence kind is a floating point kind.
specifier|static
name|bool
name|isFloatingPointRecurrenceKind
parameter_list|(
name|RecurrenceKind
name|Kind
parameter_list|)
function_decl|;
comment|/// Returns true if the recurrence kind is an arithmetic kind.
specifier|static
name|bool
name|isArithmeticRecurrenceKind
parameter_list|(
name|RecurrenceKind
name|Kind
parameter_list|)
function_decl|;
comment|/// Determines if Phi may have been type-promoted. If Phi has a single user
comment|/// that ANDs the Phi with a type mask, return the user. RT is updated to
comment|/// account for the narrower bit width represented by the mask, and the AND
comment|/// instruction is added to CI.
specifier|static
name|Instruction
modifier|*
name|lookThroughAnd
argument_list|(
name|PHINode
operator|*
name|Phi
argument_list|,
name|Type
operator|*
operator|&
name|RT
argument_list|,
name|SmallPtrSetImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|Visited
argument_list|,
name|SmallPtrSetImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|CI
argument_list|)
decl_stmt|;
comment|/// Returns true if all the source operands of a recurrence are either
comment|/// SExtInsts or ZExtInsts. This function is intended to be used with
comment|/// lookThroughAnd to determine if the recurrence has been type-promoted. The
comment|/// source operands are added to CI, and IsSigned is updated to indicate if
comment|/// all source operands are SExtInsts.
specifier|static
name|bool
name|getSourceExtensionKind
argument_list|(
name|Instruction
operator|*
name|Start
argument_list|,
name|Instruction
operator|*
name|Exit
argument_list|,
name|Type
operator|*
name|RT
argument_list|,
name|bool
operator|&
name|IsSigned
argument_list|,
name|SmallPtrSetImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|Visited
argument_list|,
name|SmallPtrSetImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|CI
argument_list|)
decl_stmt|;
comment|/// Returns the type of the recurrence. This type can be narrower than the
comment|/// actual type of the Phi if the recurrence has been type-promoted.
name|Type
modifier|*
name|getRecurrenceType
parameter_list|()
block|{
return|return
name|RecurrenceType
return|;
block|}
comment|/// Returns a reference to the instructions used for type-promoting the
comment|/// recurrence.
name|SmallPtrSet
operator|<
name|Instruction
operator|*
operator|,
literal|8
operator|>
operator|&
name|getCastInsts
argument_list|()
block|{
return|return
name|CastInsts
return|;
block|}
comment|/// Returns true if all source operands of the recurrence are SExtInsts.
name|bool
name|isSigned
parameter_list|()
block|{
return|return
name|IsSigned
return|;
block|}
name|private
label|:
comment|// The starting value of the recurrence.
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
comment|// The kind of the recurrence.
name|RecurrenceKind
name|Kind
decl_stmt|;
comment|// If this a min/max recurrence the kind of recurrence.
name|MinMaxRecurrenceKind
name|MinMaxKind
decl_stmt|;
comment|// First occurance of unasfe algebra in the PHI's use-chain.
name|Instruction
modifier|*
name|UnsafeAlgebraInst
decl_stmt|;
comment|// The type of the recurrence.
name|Type
modifier|*
name|RecurrenceType
decl_stmt|;
comment|// True if all source operands of the recurrence are SExtInsts.
name|bool
name|IsSigned
decl_stmt|;
comment|// Instructions used for type-promoting the recurrence.
name|SmallPtrSet
operator|<
name|Instruction
operator|*
operator|,
literal|8
operator|>
name|CastInsts
expr_stmt|;
block|}
empty_stmt|;
comment|/// A struct for saving information about induction variables.
name|class
name|InductionDescriptor
block|{
name|public
label|:
comment|/// This enum represents the kinds of inductions that we support.
enum|enum
name|InductionKind
block|{
name|IK_NoInduction
block|,
comment|///< Not an induction variable.
name|IK_IntInduction
block|,
comment|///< Integer induction variable. Step = C.
name|IK_PtrInduction
comment|///< Pointer induction var. Step = C / sizeof(elem).
block|}
enum|;
name|public
label|:
comment|/// Default constructor - creates an invalid induction.
name|InductionDescriptor
argument_list|()
operator|:
name|StartValue
argument_list|(
name|nullptr
argument_list|)
operator|,
name|IK
argument_list|(
name|IK_NoInduction
argument_list|)
operator|,
name|StepValue
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|/// Get the consecutive direction. Returns:
comment|///   0 - unknown or non-consecutive.
comment|///   1 - consecutive and increasing.
comment|///  -1 - consecutive and decreasing.
name|int
name|getConsecutiveDirection
argument_list|()
specifier|const
expr_stmt|;
comment|/// Compute the transformed value of Index at offset StartValue using step
comment|/// StepValue.
comment|/// For integer induction, returns StartValue + Index * StepValue.
comment|/// For pointer induction, returns StartValue[Index * StepValue].
comment|/// FIXME: The newly created binary instructions should contain nsw/nuw
comment|/// flags, which can be found from the original scalar operations.
name|Value
modifier|*
name|transform
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
name|Value
operator|*
name|Index
argument_list|)
decl|const
decl_stmt|;
name|Value
operator|*
name|getStartValue
argument_list|()
specifier|const
block|{
return|return
name|StartValue
return|;
block|}
name|InductionKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|IK
return|;
block|}
name|ConstantInt
operator|*
name|getStepValue
argument_list|()
specifier|const
block|{
return|return
name|StepValue
return|;
block|}
specifier|static
name|bool
name|isInductionPHI
parameter_list|(
name|PHINode
modifier|*
name|Phi
parameter_list|,
name|ScalarEvolution
modifier|*
name|SE
parameter_list|,
name|InductionDescriptor
modifier|&
name|D
parameter_list|)
function_decl|;
name|private
label|:
comment|/// Private constructor - used by \c isInductionPHI.
name|InductionDescriptor
argument_list|(
argument|Value *Start
argument_list|,
argument|InductionKind K
argument_list|,
argument|ConstantInt *Step
argument_list|)
empty_stmt|;
comment|/// Start value.
name|TrackingVH
operator|<
name|Value
operator|>
name|StartValue
expr_stmt|;
comment|/// Induction kind.
name|InductionKind
name|IK
decl_stmt|;
comment|/// Step value.
name|ConstantInt
modifier|*
name|StepValue
decl_stmt|;
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
name|DominatorTree
modifier|*
name|DT
parameter_list|,
name|LoopInfo
modifier|*
name|LI
parameter_list|,
name|bool
name|PreserveLCSSA
parameter_list|)
function_decl|;
comment|/// \brief Simplify each loop in a loop nest recursively.
comment|///
comment|/// This takes a potentially un-simplified loop L (and its children) and turns
comment|/// it into a simplified loop nest with preheaders and single backedges. It will
comment|/// update \c AliasAnalysis and \c ScalarEvolution analyses if they're non-null.
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
name|ScalarEvolution
modifier|*
name|SE
parameter_list|,
name|AssumptionCache
modifier|*
name|AC
parameter_list|,
name|bool
name|PreserveLCSSA
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
comment|/// checks loop body& header for the possibility of may throw
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
comment|/// \brief Returns the instructions that use values defined in the loop.
name|SmallVector
operator|<
name|Instruction
operator|*
operator|,
literal|8
operator|>
name|findDefsUsedOutsideOfLoop
argument_list|(
name|Loop
operator|*
name|L
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

