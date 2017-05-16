begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Transforms/Utils/LoopUtils.h - Loop utilities -------*- C++ -*-===//
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
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
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
file|"llvm/IR/IRBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/InstrTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Operator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
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
name|BasicBlock
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|Loop
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
name|class
name|OptimizationRemarkEmitter
decl_stmt|;
name|class
name|PredicatedScalarEvolution
decl_stmt|;
name|class
name|PredIteratorCache
decl_stmt|;
name|class
name|ScalarEvolution
decl_stmt|;
name|class
name|SCEV
decl_stmt|;
name|class
name|TargetLibraryInfo
decl_stmt|;
name|class
name|TargetTransformInfo
decl_stmt|;
comment|/// \brief Captures loop safety information.
comment|/// It keep information for loop& its header may throw exception.
struct|struct
name|LoopSafetyInfo
block|{
name|bool
name|MayThrow
init|=
name|false
decl_stmt|;
comment|// The current loop contains an instruction which
comment|// may throw.
name|bool
name|HeaderMayThrow
init|=
name|false
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
name|LoopSafetyInfo
argument_list|()
operator|=
expr|default
expr_stmt|;
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
operator|=
expr|default
expr_stmt|;
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
block|:
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
comment|/// Returns true if Phi is a first-order recurrence. A first-order recurrence
comment|/// is a non-reduction recurrence relation in which the value of the
comment|/// recurrence in the current loop iteration equals a value defined in the
comment|/// previous iteration.
specifier|static
name|bool
name|isFirstOrderRecurrence
parameter_list|(
name|PHINode
modifier|*
name|Phi
parameter_list|,
name|Loop
modifier|*
name|TheLoop
parameter_list|,
name|DominatorTree
modifier|*
name|DT
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
init|=
name|nullptr
decl_stmt|;
comment|// The kind of the recurrence.
name|RecurrenceKind
name|Kind
init|=
name|RK_NoRecurrence
decl_stmt|;
comment|// If this a min/max recurrence the kind of recurrence.
name|MinMaxRecurrenceKind
name|MinMaxKind
init|=
name|MRK_Invalid
decl_stmt|;
comment|// First occurrence of unasfe algebra in the PHI's use-chain.
name|Instruction
modifier|*
name|UnsafeAlgebraInst
init|=
name|nullptr
decl_stmt|;
comment|// The type of the recurrence.
name|Type
modifier|*
name|RecurrenceType
init|=
name|nullptr
decl_stmt|;
comment|// True if all source operands of the recurrence are SExtInsts.
name|bool
name|IsSigned
init|=
name|false
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
block|,
comment|///< Pointer induction var. Step = C / sizeof(elem).
name|IK_FpInduction
comment|///< Floating point induction variable.
block|}
enum|;
name|public
label|:
comment|/// Default constructor - creates an invalid induction.
name|InductionDescriptor
argument_list|()
operator|=
expr|default
expr_stmt|;
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
argument_list|,
name|ScalarEvolution
operator|*
name|SE
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
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
specifier|const
name|SCEV
operator|*
name|getStep
argument_list|()
specifier|const
block|{
return|return
name|Step
return|;
block|}
name|ConstantInt
operator|*
name|getConstIntStepValue
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns true if \p Phi is an induction in the loop \p L. If \p Phi is an
comment|/// induction, the induction descriptor \p D will contain the data describing
comment|/// this induction. If by some other means the caller has a better SCEV
comment|/// expression for \p Phi than the one returned by the ScalarEvolution
comment|/// analysis, it can be passed through \p Expr.
specifier|static
name|bool
name|isInductionPHI
parameter_list|(
name|PHINode
modifier|*
name|Phi
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
parameter_list|,
name|ScalarEvolution
modifier|*
name|SE
parameter_list|,
name|InductionDescriptor
modifier|&
name|D
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|Expr
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Returns true if \p Phi is a floating point induction in the loop \p L.
comment|/// If \p Phi is an induction, the induction descriptor \p D will contain
comment|/// the data describing this induction.
specifier|static
name|bool
name|isFPInductionPHI
parameter_list|(
name|PHINode
modifier|*
name|Phi
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
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
comment|/// Returns true if \p Phi is a loop \p L induction, in the context associated
comment|/// with the run-time predicate of PSE. If \p Assume is true, this can add
comment|/// further SCEV predicates to \p PSE in order to prove that \p Phi is an
comment|/// induction.
comment|/// If \p Phi is an induction, \p D will contain the data describing this
comment|/// induction.
specifier|static
name|bool
name|isInductionPHI
parameter_list|(
name|PHINode
modifier|*
name|Phi
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
parameter_list|,
name|PredicatedScalarEvolution
modifier|&
name|PSE
parameter_list|,
name|InductionDescriptor
modifier|&
name|D
parameter_list|,
name|bool
name|Assume
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Returns true if the induction type is FP and the binary operator does
comment|/// not have the "fast-math" property. Such operation requires a relaxed FP
comment|/// mode.
name|bool
name|hasUnsafeAlgebra
parameter_list|()
block|{
return|return
name|InductionBinOp
operator|&&
operator|!
name|cast
operator|<
name|FPMathOperator
operator|>
operator|(
name|InductionBinOp
operator|)
operator|->
name|hasUnsafeAlgebra
argument_list|()
return|;
block|}
comment|/// Returns induction operator that does not have "fast-math" property
comment|/// and requires FP unsafe mode.
name|Instruction
modifier|*
name|getUnsafeAlgebraInst
parameter_list|()
block|{
if|if
condition|(
operator|!
name|InductionBinOp
operator|||
name|cast
operator|<
name|FPMathOperator
operator|>
operator|(
name|InductionBinOp
operator|)
operator|->
name|hasUnsafeAlgebra
argument_list|()
condition|)
return|return
name|nullptr
return|;
return|return
name|InductionBinOp
return|;
block|}
comment|/// Returns binary opcode of the induction operator.
name|Instruction
operator|::
name|BinaryOps
name|getInductionOpcode
argument_list|()
specifier|const
block|{
return|return
name|InductionBinOp
operator|?
name|InductionBinOp
operator|->
name|getOpcode
argument_list|()
operator|:
name|Instruction
operator|::
name|BinaryOpsEnd
return|;
block|}
name|private
label|:
comment|/// Private constructor - used by \c isInductionPHI.
name|InductionDescriptor
argument_list|(
argument|Value *Start
argument_list|,
argument|InductionKind K
argument_list|,
argument|const SCEV *Step
argument_list|,
argument|BinaryOperator *InductionBinOp = nullptr
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
init|=
name|IK_NoInduction
decl_stmt|;
comment|/// Step value.
specifier|const
name|SCEV
modifier|*
name|Step
init|=
name|nullptr
decl_stmt|;
comment|// Instruction that advances induction variable.
name|BinaryOperator
modifier|*
name|InductionBinOp
init|=
name|nullptr
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
comment|/// Ensures LCSSA form for every instruction from the Worklist in the scope of
comment|/// innermost containing loop.
comment|///
comment|/// For the given instruction which have uses outside of the loop, an LCSSA PHI
comment|/// node is inserted and the uses outside the loop are rewritten to use this
comment|/// node.
comment|///
comment|/// LoopInfo and DominatorTree are required and, since the routine makes no
comment|/// changes to CFG, preserved.
comment|///
comment|/// Returns true if any modifications are made.
name|bool
name|formLCSSAForInstructions
argument_list|(
name|SmallVectorImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|Worklist
argument_list|,
name|DominatorTree
operator|&
name|DT
argument_list|,
name|LoopInfo
operator|&
name|LI
argument_list|)
decl_stmt|;
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
comment|/// instructions of the loop and loop safety information as
comment|/// arguments. Diagnostics is emitted via \p ORE. It returns changed status.
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
name|LoopSafetyInfo
modifier|*
parameter_list|,
name|OptimizationRemarkEmitter
modifier|*
name|ORE
parameter_list|)
function_decl|;
comment|/// \brief Walk the specified region of the CFG (defined by all blocks
comment|/// dominated by the specified block, and that are in the current loop) in depth
comment|/// first order w.r.t the DominatorTree.  This allows us to visit definitions
comment|/// before uses, allowing us to hoist a loop body in one pass without iteration.
comment|/// Takes DomTreeNode, AliasAnalysis, LoopInfo, DominatorTree, DataLayout,
comment|/// TargetLibraryInfo, Loop, AliasSet information for all instructions of the
comment|/// loop and loop safety information as arguments. Diagnostics is emitted via \p
comment|/// ORE. It returns changed status.
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
name|LoopSafetyInfo
modifier|*
parameter_list|,
name|OptimizationRemarkEmitter
modifier|*
name|ORE
parameter_list|)
function_decl|;
comment|/// \brief Try to promote memory values to scalars by sinking stores out of
comment|/// the loop and moving loads to before the loop.  We do this by looping over
comment|/// the stores in the loop, looking for stores to Must pointers which are
comment|/// loop invariant. It takes AliasSet, Loop exit blocks vector, loop exit blocks
comment|/// insertion point vector, PredIteratorCache, LoopInfo, DominatorTree, Loop,
comment|/// AliasSet information for all instructions of the loop and loop safety
comment|/// information as arguments. Diagnostics is emitted via \p ORE. It returns
comment|/// changed status.
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
specifier|const
name|TargetLibraryInfo
operator|*
argument_list|,
name|Loop
operator|*
argument_list|,
name|AliasSetTracker
operator|*
argument_list|,
name|LoopSafetyInfo
operator|*
argument_list|,
name|OptimizationRemarkEmitter
operator|*
argument_list|)
decl_stmt|;
comment|/// \brief Computes safety information for a loop
comment|/// checks loop body& header for the possibility of may throw
comment|/// exception, it takes LoopSafetyInfo and loop as argument.
comment|/// Updates safety information in LoopSafetyInfo argument.
name|void
name|computeLoopSafetyInfo
parameter_list|(
name|LoopSafetyInfo
modifier|*
parameter_list|,
name|Loop
modifier|*
parameter_list|)
function_decl|;
comment|/// Returns true if the instruction in a loop is guaranteed to execute at least
comment|/// once.
name|bool
name|isGuaranteedToExecute
parameter_list|(
specifier|const
name|Instruction
modifier|&
name|Inst
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
parameter_list|,
specifier|const
name|Loop
modifier|*
name|CurLoop
parameter_list|,
specifier|const
name|LoopSafetyInfo
modifier|*
name|SafetyInfo
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
comment|/// \brief Find string metadata for loop
comment|///
comment|/// If it has a value (e.g. {"llvm.distribute", 1} return the value as an
comment|/// operand or null otherwise.  If the string metadata is not found return
comment|/// Optional's not-a-value.
name|Optional
operator|<
specifier|const
name|MDOperand
operator|*
operator|>
name|findStringMetadataForLoop
argument_list|(
argument|Loop *TheLoop
argument_list|,
argument|StringRef Name
argument_list|)
expr_stmt|;
comment|/// \brief Set input string into loop metadata by keeping other values intact.
name|void
name|addStringMetadataToLoop
parameter_list|(
name|Loop
modifier|*
name|TheLoop
parameter_list|,
specifier|const
name|char
modifier|*
name|MDString
parameter_list|,
name|unsigned
name|V
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// \brief Get a loop's estimated trip count based on branch weight metadata.
comment|/// Returns 0 when the count is estimated to be 0, or None when a meaningful
comment|/// estimate can not be made.
name|Optional
operator|<
name|unsigned
operator|>
name|getLoopEstimatedTripCount
argument_list|(
name|Loop
operator|*
name|L
argument_list|)
expr_stmt|;
comment|/// Helper to consistently add the set of standard passes to a loop pass's \c
comment|/// AnalysisUsage.
comment|///
comment|/// All loop passes should call this as part of implementing their \c
comment|/// getAnalysisUsage.
name|void
name|getLoopAnalysisUsage
parameter_list|(
name|AnalysisUsage
modifier|&
name|AU
parameter_list|)
function_decl|;
comment|/// Returns true if the hoister and sinker can handle this instruction.
comment|/// If SafetyInfo is null, we are checking for sinking instructions from
comment|/// preheader to loop body (no speculation).
comment|/// If SafetyInfo is not null, we are checking for hoisting/sinking
comment|/// instructions from loop body to preheader/exit. Check if the instruction
comment|/// can execute speculatively.
comment|/// If \p ORE is set use it to emit optimization remarks.
name|bool
name|canSinkOrHoistInst
parameter_list|(
name|Instruction
modifier|&
name|I
parameter_list|,
name|AAResults
modifier|*
name|AA
parameter_list|,
name|DominatorTree
modifier|*
name|DT
parameter_list|,
name|Loop
modifier|*
name|CurLoop
parameter_list|,
name|AliasSetTracker
modifier|*
name|CurAST
parameter_list|,
name|LoopSafetyInfo
modifier|*
name|SafetyInfo
parameter_list|,
name|OptimizationRemarkEmitter
modifier|*
name|ORE
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Generates a vector reduction using shufflevectors to reduce the value.
name|Value
modifier|*
name|getShuffleReduction
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|Builder
argument_list|,
name|Value
operator|*
name|Src
argument_list|,
name|unsigned
name|Op
argument_list|,
name|RecurrenceDescriptor
operator|::
name|MinMaxRecurrenceKind
name|MinMaxKind
operator|=
name|RecurrenceDescriptor
operator|::
name|MRK_Invalid
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|RedOps
operator|=
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
operator|(
operator|)
argument_list|)
decl_stmt|;
comment|/// Create a target reduction of the given vector. The reduction operation
comment|/// is described by the \p Opcode parameter. min/max reductions require
comment|/// additional information supplied in \p Flags.
comment|/// The target is queried to determine if intrinsics or shuffle sequences are
comment|/// required to implement the reduction.
name|Value
modifier|*
name|createSimpleTargetReduction
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|TargetTransformInfo
operator|*
name|TTI
argument_list|,
name|unsigned
name|Opcode
argument_list|,
name|Value
operator|*
name|Src
argument_list|,
name|TargetTransformInfo
operator|::
name|ReductionFlags
name|Flags
operator|=
name|TargetTransformInfo
operator|::
name|ReductionFlags
argument_list|()
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|RedOps
operator|=
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
operator|(
operator|)
argument_list|)
decl_stmt|;
comment|/// Create a generic target reduction using a recurrence descriptor \p Desc
comment|/// The target is queried to determine if intrinsics or shuffle sequences are
comment|/// required to implement the reduction.
name|Value
modifier|*
name|createTargetReduction
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|TargetTransformInfo
operator|*
name|TTI
argument_list|,
name|RecurrenceDescriptor
operator|&
name|Desc
argument_list|,
name|Value
operator|*
name|Src
argument_list|,
name|bool
name|NoNaN
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// Get the intersection (logical and) of all of the potential IR flags
comment|/// of each scalar operation (VL) that will be converted into a vector (I).
comment|/// Flag set: NSW, NUW, exact, and all of fast-math.
name|void
name|propagateIRFlags
argument_list|(
name|Value
operator|*
name|I
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|VL
argument_list|)
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

begin_comment
comment|// LLVM_TRANSFORMS_UTILS_LOOPUTILS_H
end_comment

end_unit

