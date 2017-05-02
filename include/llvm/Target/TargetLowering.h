begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetLowering.h - Target Lowering Info -----*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// This file describes how to lower LLVM code to machine code.  This has two
end_comment

begin_comment
comment|/// main components:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///  1. Which ValueTypes are natively supported by the target.
end_comment

begin_comment
comment|///  2. Which operations are supported for supported ValueTypes.
end_comment

begin_comment
comment|///  3. Cost thresholds for alternative implementations of certain operations.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In addition it has a few other components, like information about FP
end_comment

begin_comment
comment|/// immediates.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TARGET_TARGETLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETLOWERING_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
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
file|"llvm/CodeGen/DAGCombine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ISDOpcodes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineValueType.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/RuntimeLibcalls.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAGNodes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ValueTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Attributes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallSite.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallingConv.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DerivedTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/IRBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/InlineAsm.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instruction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/AtomicOrdering.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetCallingConv.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<climits>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BranchProbability
decl_stmt|;
name|class
name|CCState
decl_stmt|;
name|class
name|CCValAssign
decl_stmt|;
name|class
name|FastISel
decl_stmt|;
name|class
name|FunctionLoweringInfo
decl_stmt|;
name|class
name|IntrinsicInst
decl_stmt|;
struct_decl|struct
name|KnownBits
struct_decl|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineJumpTableInfo
decl_stmt|;
name|class
name|MachineLoop
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|class
name|TargetLibraryInfo
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|namespace
name|Sched
block|{
enum|enum
name|Preference
block|{
name|None
block|,
comment|// No preference
name|Source
block|,
comment|// Follow source order.
name|RegPressure
block|,
comment|// Scheduling for lowest register pressure.
name|Hybrid
block|,
comment|// Scheduling for both latency and register pressure.
name|ILP
block|,
comment|// Scheduling for ILP in low register pressure mode.
name|VLIW
comment|// Scheduling for VLIW targets.
block|}
enum|;
block|}
comment|// end namespace Sched
comment|/// This base class for TargetLowering contains the SelectionDAG-independent
comment|/// parts that can be used from the rest of CodeGen.
name|class
name|TargetLoweringBase
block|{
name|public
label|:
comment|/// This enum indicates whether operations are valid for a target, and if not,
comment|/// what action should be used to make them valid.
enum|enum
name|LegalizeAction
enum|:
name|uint8_t
block|{
name|Legal
block|,
comment|// The target natively supports this operation.
name|Promote
block|,
comment|// This operation should be executed in a larger type.
name|Expand
block|,
comment|// Try to expand this to other ops, otherwise use a libcall.
name|LibCall
block|,
comment|// Don't try to expand this to other ops, always use a libcall.
name|Custom
comment|// Use the LowerOperation hook to implement custom lowering.
block|}
enum|;
comment|/// This enum indicates whether a types are legal for a target, and if not,
comment|/// what action should be used to make them valid.
enum|enum
name|LegalizeTypeAction
enum|:
name|uint8_t
block|{
name|TypeLegal
block|,
comment|// The target natively supports this type.
name|TypePromoteInteger
block|,
comment|// Replace this integer with a larger one.
name|TypeExpandInteger
block|,
comment|// Split this integer into two of half the size.
name|TypeSoftenFloat
block|,
comment|// Convert this float to a same size integer type,
comment|// if an operation is not supported in target HW.
name|TypeExpandFloat
block|,
comment|// Split this float into two of half the size.
name|TypeScalarizeVector
block|,
comment|// Replace this one-element vector with its element.
name|TypeSplitVector
block|,
comment|// Split this vector into two of half the size.
name|TypeWidenVector
block|,
comment|// This vector should be widened into a larger vector.
name|TypePromoteFloat
comment|// Replace this float with a larger one.
block|}
enum|;
comment|/// LegalizeKind holds the legalization kind that needs to happen to EVT
comment|/// in order to type-legalize it.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|LegalizeTypeAction
operator|,
name|EVT
operator|>
name|LegalizeKind
expr_stmt|;
comment|/// Enum that describes how the target represents true/false values.
enum|enum
name|BooleanContent
block|{
name|UndefinedBooleanContent
block|,
comment|// Only bit 0 counts, the rest can hold garbage.
name|ZeroOrOneBooleanContent
block|,
comment|// All bits zero except for bit 0.
name|ZeroOrNegativeOneBooleanContent
comment|// All bits equal to bit 0.
block|}
enum|;
comment|/// Enum that describes what type of support for selects the target has.
enum|enum
name|SelectSupportKind
block|{
name|ScalarValSelect
block|,
comment|// The target supports scalar selects (ex: cmov).
name|ScalarCondVectorVal
block|,
comment|// The target supports selects with a scalar condition
comment|// and vector values (ex: cmov).
name|VectorMaskSelect
comment|// The target supports vector selects with a vector
comment|// mask (ex: x86 blends).
block|}
enum|;
comment|/// Enum that specifies what an atomic load/AtomicRMWInst is expanded
comment|/// to, if at all. Exists because different targets have different levels of
comment|/// support for these atomic instructions, and also have different options
comment|/// w.r.t. what they should expand to.
name|enum
name|class
name|AtomicExpansionKind
block|{
name|None
operator|,
comment|// Don't expand the instruction.
name|LLSC
operator|,
comment|// Expand the instruction into loadlinked/storeconditional; used
comment|// by ARM/AArch64.
name|LLOnly
operator|,
comment|// Expand the (load) instruction into just a load-linked, which has
comment|// greater atomic guarantees than a normal load.
name|CmpXChg
operator|,
comment|// Expand the instruction into cmpxchg; used by at least X86.
block|}
empty_stmt|;
comment|/// Enum that specifies when a multiplication should be expanded.
name|enum
name|class
name|MulExpansionKind
block|{
name|Always
operator|,
comment|// Always expand the instruction.
name|OnlyLegalOrCustom
operator|,
comment|// Only expand when the resulting instructions are legal
comment|// or custom.
block|}
empty_stmt|;
name|class
name|ArgListEntry
block|{
name|public
label|:
name|Value
modifier|*
name|Val
init|=
name|nullptr
decl_stmt|;
name|SDValue
name|Node
init|=
name|SDValue
argument_list|()
decl_stmt|;
name|Type
modifier|*
name|Ty
init|=
name|nullptr
decl_stmt|;
name|bool
name|IsSExt
range|:
literal|1
decl_stmt|;
name|bool
name|IsZExt
range|:
literal|1
decl_stmt|;
name|bool
name|IsInReg
range|:
literal|1
decl_stmt|;
name|bool
name|IsSRet
range|:
literal|1
decl_stmt|;
name|bool
name|IsNest
range|:
literal|1
decl_stmt|;
name|bool
name|IsByVal
range|:
literal|1
decl_stmt|;
name|bool
name|IsInAlloca
range|:
literal|1
decl_stmt|;
name|bool
name|IsReturned
range|:
literal|1
decl_stmt|;
name|bool
name|IsSwiftSelf
range|:
literal|1
decl_stmt|;
name|bool
name|IsSwiftError
range|:
literal|1
decl_stmt|;
name|uint16_t
name|Alignment
init|=
literal|0
decl_stmt|;
name|ArgListEntry
argument_list|()
operator|:
name|IsSExt
argument_list|(
name|false
argument_list|)
operator|,
name|IsZExt
argument_list|(
name|false
argument_list|)
operator|,
name|IsInReg
argument_list|(
name|false
argument_list|)
operator|,
name|IsSRet
argument_list|(
name|false
argument_list|)
operator|,
name|IsNest
argument_list|(
name|false
argument_list|)
operator|,
name|IsByVal
argument_list|(
name|false
argument_list|)
operator|,
name|IsInAlloca
argument_list|(
name|false
argument_list|)
operator|,
name|IsReturned
argument_list|(
name|false
argument_list|)
operator|,
name|IsSwiftSelf
argument_list|(
name|false
argument_list|)
operator|,
name|IsSwiftError
argument_list|(
argument|false
argument_list|)
block|{}
name|void
name|setAttributes
argument_list|(
argument|ImmutableCallSite *CS
argument_list|,
argument|unsigned ArgIdx
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|ArgListEntry
operator|>
name|ArgListTy
expr_stmt|;
name|virtual
name|void
name|markLibCallAttributes
argument_list|(
name|MachineFunction
operator|*
name|MF
argument_list|,
name|unsigned
name|CC
argument_list|,
name|ArgListTy
operator|&
name|Args
argument_list|)
decl|const
block|{}
empty_stmt|;
specifier|static
name|ISD
operator|::
name|NodeType
name|getExtendForContent
argument_list|(
argument|BooleanContent Content
argument_list|)
block|{
switch|switch
condition|(
name|Content
condition|)
block|{
case|case
name|UndefinedBooleanContent
case|:
comment|// Extend by adding rubbish bits.
return|return
name|ISD
operator|::
name|ANY_EXTEND
return|;
case|case
name|ZeroOrOneBooleanContent
case|:
comment|// Extend by adding zero bits.
return|return
name|ISD
operator|::
name|ZERO_EXTEND
return|;
case|case
name|ZeroOrNegativeOneBooleanContent
case|:
comment|// Extend by copying the sign bit.
return|return
name|ISD
operator|::
name|SIGN_EXTEND
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Invalid content kind"
argument_list|)
expr_stmt|;
block|}
comment|/// NOTE: The TargetMachine owns TLOF.
name|explicit
name|TargetLoweringBase
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
expr_stmt|;
name|TargetLoweringBase
argument_list|(
specifier|const
name|TargetLoweringBase
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|TargetLoweringBase
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|virtual
operator|~
name|TargetLoweringBase
argument_list|()
operator|=
expr|default
expr_stmt|;
name|protected
label|:
comment|/// \brief Initialize all of the actions to default values.
name|void
name|initActions
parameter_list|()
function_decl|;
name|public
label|:
specifier|const
name|TargetMachine
operator|&
name|getTargetMachine
argument_list|()
specifier|const
block|{
return|return
name|TM
return|;
block|}
name|virtual
name|bool
name|useSoftFloat
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return the pointer type for the given address space, defaults to
comment|/// the pointer type from the data layout.
comment|/// FIXME: The default needs to be removed once all the code is updated.
name|MVT
name|getPointerTy
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
name|uint32_t
name|AS
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|MVT
operator|::
name|getIntegerVT
argument_list|(
name|DL
operator|.
name|getPointerSizeInBits
argument_list|(
name|AS
argument_list|)
argument_list|)
return|;
block|}
comment|/// Return the type for frame index, which is determined by
comment|/// the alloca address space specified through the data layout.
name|MVT
name|getFrameIndexTy
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
decl|const
block|{
return|return
name|getPointerTy
argument_list|(
name|DL
argument_list|,
name|DL
operator|.
name|getAllocaAddrSpace
argument_list|()
argument_list|)
return|;
block|}
comment|/// Return the type for operands of fence.
comment|/// TODO: Let fence operands be of i32 type and remove this.
name|virtual
name|MVT
name|getFenceOperandTy
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
decl|const
block|{
return|return
name|getPointerTy
argument_list|(
name|DL
argument_list|)
return|;
block|}
comment|/// EVT is not used in-tree, but is used by out-of-tree target.
comment|/// A documentation for this function would be nice...
name|virtual
name|MVT
name|getScalarShiftAmountTy
argument_list|(
specifier|const
name|DataLayout
operator|&
argument_list|,
name|EVT
argument_list|)
decl|const
decl_stmt|;
name|EVT
name|getShiftAmountTy
argument_list|(
name|EVT
name|LHSTy
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns the type to be used for the index operand of:
comment|/// ISD::INSERT_VECTOR_ELT, ISD::EXTRACT_VECTOR_ELT,
comment|/// ISD::INSERT_SUBVECTOR, and ISD::EXTRACT_SUBVECTOR
name|virtual
name|MVT
name|getVectorIdxTy
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
decl|const
block|{
return|return
name|getPointerTy
argument_list|(
name|DL
argument_list|)
return|;
block|}
name|virtual
name|bool
name|isSelectSupported
argument_list|(
name|SelectSupportKind
comment|/*kind*/
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
comment|/// Return true if multiple condition registers are available.
name|bool
name|hasMultipleConditionRegisters
argument_list|()
specifier|const
block|{
return|return
name|HasMultipleConditionRegisters
return|;
block|}
comment|/// Return true if the target has BitExtract instructions.
name|bool
name|hasExtractBitsInsn
argument_list|()
specifier|const
block|{
return|return
name|HasExtractBitsInsn
return|;
block|}
comment|/// Return the preferred vector type legalization action.
name|virtual
name|TargetLoweringBase
operator|::
name|LegalizeTypeAction
name|getPreferredVectorAction
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
block|{
comment|// The default action for one element vectors is to scalarize
if|if
condition|(
name|VT
operator|.
name|getVectorNumElements
argument_list|()
operator|==
literal|1
condition|)
return|return
name|TypeScalarizeVector
return|;
comment|// The default action for other vectors is to promote
return|return
name|TypePromoteInteger
return|;
block|}
comment|// There are two general methods for expanding a BUILD_VECTOR node:
comment|//  1. Use SCALAR_TO_VECTOR on the defined scalar values and then shuffle
comment|//     them together.
comment|//  2. Build the vector on the stack and then load it.
comment|// If this function returns true, then method (1) will be used, subject to
comment|// the constraint that all of the necessary shuffles are legal (as determined
comment|// by isShuffleMaskLegal). If this function returns false, then method (2) is
comment|// always used. The vector type, and the number of defined values, are
comment|// provided.
name|virtual
name|bool
name|shouldExpandBuildVectorWithShuffles
argument_list|(
name|EVT
comment|/* VT */
argument_list|,
name|unsigned
name|DefinedValues
argument_list|)
decl|const
block|{
return|return
name|DefinedValues
operator|<
literal|3
return|;
block|}
comment|/// Return true if integer divide is usually cheaper than a sequence of
comment|/// several shifts, adds, and multiplies for this target.
comment|/// The definition of "cheaper" may depend on whether we're optimizing
comment|/// for speed or for size.
name|virtual
name|bool
name|isIntDivCheap
argument_list|(
name|EVT
name|VT
argument_list|,
name|AttributeList
name|Attr
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return true if the target can handle a standalone remainder operation.
name|virtual
name|bool
name|hasStandaloneRem
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
comment|/// Return true if SQRT(X) shouldn't be replaced with X*RSQRT(X).
name|virtual
name|bool
name|isFsqrtCheap
argument_list|(
name|SDValue
name|X
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
block|{
comment|// Default behavior is to replace SQRT(X) with X*RSQRT(X).
return|return
name|false
return|;
block|}
comment|/// Reciprocal estimate status values used by the functions below.
enum|enum
name|ReciprocalEstimate
enum|:
name|int
block|{
name|Unspecified
init|=
operator|-
literal|1
block|,
name|Disabled
init|=
literal|0
block|,
name|Enabled
init|=
literal|1
block|}
enum|;
comment|/// Return a ReciprocalEstimate enum value for a square root of the given type
comment|/// based on the function's attributes. If the operation is not overridden by
comment|/// the function's attributes, "Unspecified" is returned and target defaults
comment|/// are expected to be used for instruction selection.
name|int
name|getRecipEstimateSqrtEnabled
argument_list|(
name|EVT
name|VT
argument_list|,
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
decl_stmt|;
comment|/// Return a ReciprocalEstimate enum value for a division of the given type
comment|/// based on the function's attributes. If the operation is not overridden by
comment|/// the function's attributes, "Unspecified" is returned and target defaults
comment|/// are expected to be used for instruction selection.
name|int
name|getRecipEstimateDivEnabled
argument_list|(
name|EVT
name|VT
argument_list|,
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the refinement step count for a square root of the given type based
comment|/// on the function's attributes. If the operation is not overridden by
comment|/// the function's attributes, "Unspecified" is returned and target defaults
comment|/// are expected to be used for instruction selection.
name|int
name|getSqrtRefinementSteps
argument_list|(
name|EVT
name|VT
argument_list|,
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the refinement step count for a division of the given type based
comment|/// on the function's attributes. If the operation is not overridden by
comment|/// the function's attributes, "Unspecified" is returned and target defaults
comment|/// are expected to be used for instruction selection.
name|int
name|getDivRefinementSteps
argument_list|(
name|EVT
name|VT
argument_list|,
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns true if target has indicated at least one type should be bypassed.
name|bool
name|isSlowDivBypassed
argument_list|()
specifier|const
block|{
return|return
operator|!
name|BypassSlowDivWidths
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// Returns map of slow types for division or remainder with corresponding
comment|/// fast types
specifier|const
name|DenseMap
operator|<
name|unsigned
name|int
operator|,
name|unsigned
name|int
operator|>
operator|&
name|getBypassSlowDivWidths
argument_list|()
specifier|const
block|{
return|return
name|BypassSlowDivWidths
return|;
block|}
comment|/// Return true if Flow Control is an expensive operation that should be
comment|/// avoided.
name|bool
name|isJumpExpensive
argument_list|()
specifier|const
block|{
return|return
name|JumpIsExpensive
return|;
block|}
comment|/// Return true if selects are only cheaper than branches if the branch is
comment|/// unlikely to be predicted right.
name|bool
name|isPredictableSelectExpensive
argument_list|()
specifier|const
block|{
return|return
name|PredictableSelectIsExpensive
return|;
block|}
comment|/// If a branch or a select condition is skewed in one direction by more than
comment|/// this factor, it is very likely to be predicted correctly.
name|virtual
name|BranchProbability
name|getPredictableBranchThreshold
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return true if the following transform is beneficial:
comment|/// fold (conv (load x)) -> (load (conv*)x)
comment|/// On architectures that don't natively support some vector loads
comment|/// efficiently, casting the load to a smaller vector of larger types and
comment|/// loading is more efficient, however, this can be undone by optimizations in
comment|/// dag combiner.
name|virtual
name|bool
name|isLoadBitCastBeneficial
argument_list|(
name|EVT
name|LoadVT
argument_list|,
name|EVT
name|BitcastVT
argument_list|)
decl|const
block|{
comment|// Don't do if we could do an indexed load on the original type, but not on
comment|// the new one.
if|if
condition|(
operator|!
name|LoadVT
operator|.
name|isSimple
argument_list|()
operator|||
operator|!
name|BitcastVT
operator|.
name|isSimple
argument_list|()
condition|)
return|return
name|true
return|;
name|MVT
name|LoadMVT
init|=
name|LoadVT
operator|.
name|getSimpleVT
argument_list|()
decl_stmt|;
comment|// Don't bother doing this if it's just going to be promoted again later, as
comment|// doing so might interfere with other combines.
if|if
condition|(
name|getOperationAction
argument_list|(
name|ISD
operator|::
name|LOAD
argument_list|,
name|LoadMVT
argument_list|)
operator|==
name|Promote
operator|&&
name|getTypeToPromoteTo
argument_list|(
name|ISD
operator|::
name|LOAD
argument_list|,
name|LoadMVT
argument_list|)
operator|==
name|BitcastVT
operator|.
name|getSimpleVT
argument_list|()
condition|)
return|return
name|false
return|;
return|return
name|true
return|;
block|}
comment|/// Return true if the following transform is beneficial:
comment|/// (store (y (conv x)), y*)) -> (store x, (x*))
name|virtual
name|bool
name|isStoreBitCastBeneficial
argument_list|(
name|EVT
name|StoreVT
argument_list|,
name|EVT
name|BitcastVT
argument_list|)
decl|const
block|{
comment|// Default to the same logic as loads.
return|return
name|isLoadBitCastBeneficial
argument_list|(
name|StoreVT
argument_list|,
name|BitcastVT
argument_list|)
return|;
block|}
comment|/// Return true if it is expected to be cheaper to do a store of a non-zero
comment|/// vector constant with the given size and type for the address space than to
comment|/// store the individual scalar element constants.
name|virtual
name|bool
name|storeOfVectorConstantIsCheap
argument_list|(
name|EVT
name|MemVT
argument_list|,
name|unsigned
name|NumElem
argument_list|,
name|unsigned
name|AddrSpace
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Returns if it's reasonable to merge stores to MemVT size.
name|virtual
name|bool
name|canMergeStoresTo
argument_list|(
name|EVT
name|MemVT
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
comment|/// \brief Return true if it is cheap to speculate a call to intrinsic cttz.
name|virtual
name|bool
name|isCheapToSpeculateCttz
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Return true if it is cheap to speculate a call to intrinsic ctlz.
name|virtual
name|bool
name|isCheapToSpeculateCtlz
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Return true if ctlz instruction is fast.
name|virtual
name|bool
name|isCtlzFast
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return true if it is safe to transform an integer-domain bitwise operation
comment|/// into the equivalent floating-point operation. This should be set to true
comment|/// if the target has IEEE-754-compliant fabs/fneg operations for the input
comment|/// type.
name|virtual
name|bool
name|hasBitPreservingFPLogic
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Return true if it is cheaper to split the store of a merged int val
comment|/// from a pair of smaller values into multiple stores.
name|virtual
name|bool
name|isMultiStoresCheaperThanBitsMerge
argument_list|(
name|EVT
name|LTy
argument_list|,
name|EVT
name|HTy
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Return if the target supports combining a
comment|/// chain like:
comment|/// \code
comment|///   %andResult = and %val1, #mask
comment|///   %icmpResult = icmp %andResult, 0
comment|/// \endcode
comment|/// into a single machine instruction of a form like:
comment|/// \code
comment|///   cc = test %register, #mask
comment|/// \endcode
name|virtual
name|bool
name|isMaskAndCmp0FoldingBeneficial
argument_list|(
specifier|const
name|Instruction
operator|&
name|AndI
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Use bitwise logic to make pairs of compares more efficient. For example:
comment|/// and (seteq A, B), (seteq C, D) --> seteq (or (xor A, B), (xor C, D)), 0
comment|/// This should be true when it takes more than one instruction to lower
comment|/// setcc (cmp+set on x86 scalar), when bitwise ops are faster than logic on
comment|/// condition bits (crand on PowerPC), and/or when reducing cmp+br is a win.
name|virtual
name|bool
name|convertSetCCLogicToBitwiseLogic
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return the preferred operand type if the target has a quick way to compare
comment|/// integer values of the given size. Assume that any legal integer type can
comment|/// be compared efficiently. Targets may override this to allow illegal wide
comment|/// types to return a vector type if there is support to compare that type.
name|virtual
name|MVT
name|hasFastEqualityCompare
argument_list|(
name|unsigned
name|NumBits
argument_list|)
decl|const
block|{
name|MVT
name|VT
init|=
name|MVT
operator|::
name|getIntegerVT
argument_list|(
name|NumBits
argument_list|)
decl_stmt|;
return|return
name|isTypeLegal
argument_list|(
name|VT
argument_list|)
condition|?
name|VT
else|:
name|MVT
operator|::
name|INVALID_SIMPLE_VALUE_TYPE
return|;
block|}
comment|/// Return true if the target should transform:
comment|/// (X& Y) == Y ---> (~X& Y) == 0
comment|/// (X& Y) != Y ---> (~X& Y) != 0
comment|///
comment|/// This may be profitable if the target has a bitwise and-not operation that
comment|/// sets comparison flags. A target may want to limit the transformation based
comment|/// on the type of Y or if Y is a constant.
comment|///
comment|/// Note that the transform will not occur if Y is known to be a power-of-2
comment|/// because a mask and compare of a single bit can be handled by inverting the
comment|/// predicate, for example:
comment|/// (X& 8) == 8 ---> (X& 8) != 0
name|virtual
name|bool
name|hasAndNotCompare
argument_list|(
name|SDValue
name|Y
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return true if the target has a bitwise and-not operation:
comment|/// X = ~A& B
comment|/// This can be used to simplify select or other instructions.
name|virtual
name|bool
name|hasAndNot
argument_list|(
name|SDValue
name|X
argument_list|)
decl|const
block|{
comment|// If the target has the more complex version of this operation, assume that
comment|// it has this operation too.
return|return
name|hasAndNotCompare
argument_list|(
name|X
argument_list|)
return|;
block|}
comment|/// \brief Return true if the target wants to use the optimization that
comment|/// turns ext(promotableInst1(...(promotableInstN(load)))) into
comment|/// promotedInst1(...(promotedInstN(ext(load)))).
name|bool
name|enableExtLdPromotion
argument_list|()
specifier|const
block|{
return|return
name|EnableExtLdPromotion
return|;
block|}
comment|/// Return true if the target can combine store(extractelement VectorTy,
comment|/// Idx).
comment|/// \p Cost[out] gives the cost of that transformation when this is true.
name|virtual
name|bool
name|canCombineStoreAndExtract
argument_list|(
name|Type
operator|*
name|VectorTy
argument_list|,
name|Value
operator|*
name|Idx
argument_list|,
name|unsigned
operator|&
name|Cost
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return true if target supports floating point exceptions.
name|bool
name|hasFloatingPointExceptions
argument_list|()
specifier|const
block|{
return|return
name|HasFloatingPointExceptions
return|;
block|}
comment|/// Return true if target always beneficiates from combining into FMA for a
comment|/// given value type. This must typically return false on targets where FMA
comment|/// takes more cycles to execute than FADD.
name|virtual
name|bool
name|enableAggressiveFMAFusion
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return the ValueType of the result of SETCC operations.
name|virtual
name|EVT
name|getSetCCResultType
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
name|LLVMContext
operator|&
name|Context
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the ValueType for comparison libcalls. Comparions libcalls include
comment|/// floating point comparion calls, and Ordered/Unordered check calls on
comment|/// floating point numbers.
name|virtual
name|MVT
operator|::
name|SimpleValueType
name|getCmpLibcallReturnType
argument_list|()
specifier|const
expr_stmt|;
comment|/// For targets without i1 registers, this gives the nature of the high-bits
comment|/// of boolean values held in types wider than i1.
comment|///
comment|/// "Boolean values" are special true/false values produced by nodes like
comment|/// SETCC and consumed (as the condition) by nodes like SELECT and BRCOND.
comment|/// Not to be confused with general values promoted from i1.  Some cpus
comment|/// distinguish between vectors of boolean and scalars; the isVec parameter
comment|/// selects between the two kinds.  For example on X86 a scalar boolean should
comment|/// be zero extended from i1, while the elements of a vector of booleans
comment|/// should be sign extended from i1.
comment|///
comment|/// Some cpus also treat floating point types the same way as they treat
comment|/// vectors instead of the way they treat scalars.
name|BooleanContent
name|getBooleanContents
argument_list|(
name|bool
name|isVec
argument_list|,
name|bool
name|isFloat
argument_list|)
decl|const
block|{
if|if
condition|(
name|isVec
condition|)
return|return
name|BooleanVectorContents
return|;
return|return
name|isFloat
condition|?
name|BooleanFloatContents
else|:
name|BooleanContents
return|;
block|}
name|BooleanContent
name|getBooleanContents
argument_list|(
name|EVT
name|Type
argument_list|)
decl|const
block|{
return|return
name|getBooleanContents
argument_list|(
name|Type
operator|.
name|isVector
argument_list|()
argument_list|,
name|Type
operator|.
name|isFloatingPoint
argument_list|()
argument_list|)
return|;
block|}
comment|/// Return target scheduling preference.
name|Sched
operator|::
name|Preference
name|getSchedulingPreference
argument_list|()
specifier|const
block|{
return|return
name|SchedPreferenceInfo
return|;
block|}
comment|/// Some scheduler, e.g. hybrid, can switch to different scheduling heuristics
comment|/// for different nodes. This function returns the preference (or none) for
comment|/// the given node.
name|virtual
name|Sched
operator|::
name|Preference
name|getSchedulingPreference
argument_list|(
argument|SDNode *
argument_list|)
specifier|const
block|{
return|return
name|Sched
operator|::
name|None
return|;
block|}
comment|/// Return the register class that should be used for the specified value
comment|/// type.
name|virtual
specifier|const
name|TargetRegisterClass
modifier|*
name|getRegClassFor
argument_list|(
name|MVT
name|VT
argument_list|)
decl|const
block|{
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
init|=
name|RegClassForVT
index|[
name|VT
operator|.
name|SimpleTy
index|]
decl_stmt|;
name|assert
argument_list|(
name|RC
operator|&&
literal|"This value type is not natively supported!"
argument_list|)
expr_stmt|;
return|return
name|RC
return|;
block|}
comment|/// Return the 'representative' register class for the specified value
comment|/// type.
comment|///
comment|/// The 'representative' register class is the largest legal super-reg
comment|/// register class for the register class of the value type.  For example, on
comment|/// i386 the rep register class for i8, i16, and i32 are GR32; while the rep
comment|/// register class is GR64 on x86_64.
name|virtual
specifier|const
name|TargetRegisterClass
modifier|*
name|getRepRegClassFor
argument_list|(
name|MVT
name|VT
argument_list|)
decl|const
block|{
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
init|=
name|RepRegClassForVT
index|[
name|VT
operator|.
name|SimpleTy
index|]
decl_stmt|;
return|return
name|RC
return|;
block|}
comment|/// Return the cost of the 'representative' register class for the specified
comment|/// value type.
name|virtual
name|uint8_t
name|getRepRegClassCostFor
argument_list|(
name|MVT
name|VT
argument_list|)
decl|const
block|{
return|return
name|RepRegClassCostForVT
index|[
name|VT
operator|.
name|SimpleTy
index|]
return|;
block|}
comment|/// Return true if the target has native support for the specified value type.
comment|/// This means that it has a register that directly holds it without
comment|/// promotions or expansions.
name|bool
name|isTypeLegal
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
block|{
name|assert
argument_list|(
operator|!
name|VT
operator|.
name|isSimple
argument_list|()
operator|||
operator|(
name|unsigned
operator|)
name|VT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
operator|<
name|array_lengthof
argument_list|(
name|RegClassForVT
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|VT
operator|.
name|isSimple
argument_list|()
operator|&&
name|RegClassForVT
index|[
name|VT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
index|]
operator|!=
name|nullptr
return|;
block|}
name|class
name|ValueTypeActionImpl
block|{
comment|/// ValueTypeActions - For each value type, keep a LegalizeTypeAction enum
comment|/// that indicates how instruction selection should deal with the type.
name|LegalizeTypeAction
name|ValueTypeActions
index|[
name|MVT
operator|::
name|LAST_VALUETYPE
index|]
decl_stmt|;
name|public
label|:
name|ValueTypeActionImpl
argument_list|()
block|{
name|std
operator|::
name|fill
argument_list|(
name|std
operator|::
name|begin
argument_list|(
name|ValueTypeActions
argument_list|)
argument_list|,
name|std
operator|::
name|end
argument_list|(
name|ValueTypeActions
argument_list|)
argument_list|,
name|TypeLegal
argument_list|)
expr_stmt|;
block|}
name|LegalizeTypeAction
name|getTypeAction
argument_list|(
name|MVT
name|VT
argument_list|)
decl|const
block|{
return|return
name|ValueTypeActions
index|[
name|VT
operator|.
name|SimpleTy
index|]
return|;
block|}
name|void
name|setTypeAction
parameter_list|(
name|MVT
name|VT
parameter_list|,
name|LegalizeTypeAction
name|Action
parameter_list|)
block|{
name|ValueTypeActions
index|[
name|VT
operator|.
name|SimpleTy
index|]
operator|=
name|Action
expr_stmt|;
block|}
block|}
empty_stmt|;
specifier|const
name|ValueTypeActionImpl
operator|&
name|getValueTypeActions
argument_list|()
specifier|const
block|{
return|return
name|ValueTypeActions
return|;
block|}
comment|/// Return how we should legalize values of this type, either it is already
comment|/// legal (return 'Legal') or we need to promote it to a larger type (return
comment|/// 'Promote'), or we need to expand it into multiple registers of smaller
comment|/// integer type (return 'Expand').  'Custom' is not an option.
name|LegalizeTypeAction
name|getTypeAction
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
block|{
return|return
name|getTypeConversion
argument_list|(
name|Context
argument_list|,
name|VT
argument_list|)
operator|.
name|first
return|;
block|}
name|LegalizeTypeAction
name|getTypeAction
argument_list|(
name|MVT
name|VT
argument_list|)
decl|const
block|{
return|return
name|ValueTypeActions
operator|.
name|getTypeAction
argument_list|(
name|VT
argument_list|)
return|;
block|}
comment|/// For types supported by the target, this is an identity function.  For
comment|/// types that must be promoted to larger types, this returns the larger type
comment|/// to promote to.  For integer types that are larger than the largest integer
comment|/// register, this contains one step in the expansion to get to the smaller
comment|/// register. For illegal floating point types, this returns the integer type
comment|/// to transform to.
name|EVT
name|getTypeToTransformTo
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
block|{
return|return
name|getTypeConversion
argument_list|(
name|Context
argument_list|,
name|VT
argument_list|)
operator|.
name|second
return|;
block|}
comment|/// For types supported by the target, this is an identity function.  For
comment|/// types that must be expanded (i.e. integer types that are larger than the
comment|/// largest integer register or illegal floating point types), this returns
comment|/// the largest legal type it will be expanded to.
name|EVT
name|getTypeToExpandTo
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
block|{
name|assert
argument_list|(
operator|!
name|VT
operator|.
name|isVector
argument_list|()
argument_list|)
expr_stmt|;
while|while
condition|(
name|true
condition|)
block|{
switch|switch
condition|(
name|getTypeAction
argument_list|(
name|Context
argument_list|,
name|VT
argument_list|)
condition|)
block|{
case|case
name|TypeLegal
case|:
return|return
name|VT
return|;
case|case
name|TypeExpandInteger
case|:
name|VT
operator|=
name|getTypeToTransformTo
argument_list|(
name|Context
argument_list|,
name|VT
argument_list|)
expr_stmt|;
break|break;
default|default:
name|llvm_unreachable
argument_list|(
literal|"Type is not legal nor is it to be expanded!"
argument_list|)
expr_stmt|;
block|}
block|}
block|}
comment|/// Vector types are broken down into some number of legal first class types.
comment|/// For example, EVT::v8f32 maps to 2 EVT::v4f32 with Altivec or SSE1, or 8
comment|/// promoted EVT::f64 values with the X86 FP stack.  Similarly, EVT::v2i64
comment|/// turns into 4 EVT::i32 values with both PPC and X86.
comment|///
comment|/// This method returns the number of registers needed, and the VT for each
comment|/// register.  It also returns the VT and quantity of the intermediate values
comment|/// before they are promoted/expanded.
name|unsigned
name|getVectorTypeBreakdown
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|EVT
name|VT
argument_list|,
name|EVT
operator|&
name|IntermediateVT
argument_list|,
name|unsigned
operator|&
name|NumIntermediates
argument_list|,
name|MVT
operator|&
name|RegisterVT
argument_list|)
decl|const
decl_stmt|;
struct|struct
name|IntrinsicInfo
block|{
name|unsigned
name|opc
init|=
literal|0
decl_stmt|;
comment|// target opcode
name|EVT
name|memVT
decl_stmt|;
comment|// memory VT
specifier|const
name|Value
modifier|*
name|ptrVal
init|=
name|nullptr
decl_stmt|;
comment|// value representing memory location
name|int
name|offset
init|=
literal|0
decl_stmt|;
comment|// offset off of ptrVal
name|unsigned
name|size
init|=
literal|0
decl_stmt|;
comment|// the size of the memory location
comment|// (taken from memVT if zero)
name|unsigned
name|align
init|=
literal|1
decl_stmt|;
comment|// alignment
name|bool
name|vol
init|=
name|false
decl_stmt|;
comment|// is volatile?
name|bool
name|readMem
init|=
name|false
decl_stmt|;
comment|// reads memory?
name|bool
name|writeMem
init|=
name|false
decl_stmt|;
comment|// writes memory?
name|IntrinsicInfo
argument_list|()
operator|=
expr|default
expr_stmt|;
block|}
struct|;
comment|/// Given an intrinsic, checks if on the target the intrinsic will need to map
comment|/// to a MemIntrinsicNode (touches memory). If this is the case, it returns
comment|/// true and store the intrinsic information into the IntrinsicInfo that was
comment|/// passed to the function.
name|virtual
name|bool
name|getTgtMemIntrinsic
argument_list|(
name|IntrinsicInfo
operator|&
argument_list|,
specifier|const
name|CallInst
operator|&
argument_list|,
name|unsigned
comment|/*Intrinsic*/
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Returns true if the target can instruction select the specified FP
comment|/// immediate natively. If false, the legalizer will materialize the FP
comment|/// immediate as a load from a constant pool.
name|virtual
name|bool
name|isFPImmLegal
argument_list|(
specifier|const
name|APFloat
operator|&
comment|/*Imm*/
argument_list|,
name|EVT
comment|/*VT*/
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Targets can use this to indicate that they only support *some*
comment|/// VECTOR_SHUFFLE operations, those with specific masks.  By default, if a
comment|/// target supports the VECTOR_SHUFFLE node, all mask values are assumed to be
comment|/// legal.
name|virtual
name|bool
name|isShuffleMaskLegal
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
comment|/*Mask*/
argument_list|,
name|EVT
comment|/*VT*/
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
comment|/// Returns true if the operation can trap for the value type.
comment|///
comment|/// VT must be a legal type. By default, we optimistically assume most
comment|/// operations don't trap except for integer divide and remainder.
name|virtual
name|bool
name|canOpTrap
argument_list|(
name|unsigned
name|Op
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
decl_stmt|;
comment|/// Similar to isShuffleMaskLegal. This is used by Targets can use this to
comment|/// indicate if there is a suitable VECTOR_SHUFFLE that can be used to replace
comment|/// a VAND with a constant pool entry.
name|virtual
name|bool
name|isVectorClearMaskLegal
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
comment|/*Mask*/
argument_list|,
name|EVT
comment|/*VT*/
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return how this operation should be treated: either it is legal, needs to
comment|/// be promoted to a larger size, needs to be expanded to some other code
comment|/// sequence, or the target has a custom expander for it.
name|LegalizeAction
name|getOperationAction
argument_list|(
name|unsigned
name|Op
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
block|{
if|if
condition|(
name|VT
operator|.
name|isExtended
argument_list|()
condition|)
return|return
name|Expand
return|;
comment|// If a target-specific SDNode requires legalization, require the target
comment|// to provide custom legalization for it.
if|if
condition|(
name|Op
operator|>
name|array_lengthof
argument_list|(
name|OpActions
index|[
literal|0
index|]
argument_list|)
condition|)
return|return
name|Custom
return|;
return|return
name|OpActions
index|[
operator|(
name|unsigned
operator|)
name|VT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
index|]
index|[
name|Op
index|]
return|;
block|}
comment|/// Return true if the specified operation is legal on this target or can be
comment|/// made legal with custom lowering. This is used to help guide high-level
comment|/// lowering decisions.
name|bool
name|isOperationLegalOrCustom
argument_list|(
name|unsigned
name|Op
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
block|{
return|return
operator|(
name|VT
operator|==
name|MVT
operator|::
name|Other
operator|||
name|isTypeLegal
argument_list|(
name|VT
argument_list|)
operator|)
operator|&&
operator|(
name|getOperationAction
argument_list|(
name|Op
argument_list|,
name|VT
argument_list|)
operator|==
name|Legal
operator|||
name|getOperationAction
argument_list|(
name|Op
argument_list|,
name|VT
argument_list|)
operator|==
name|Custom
operator|)
return|;
block|}
comment|/// Return true if the specified operation is legal on this target or can be
comment|/// made legal using promotion. This is used to help guide high-level lowering
comment|/// decisions.
name|bool
name|isOperationLegalOrPromote
argument_list|(
name|unsigned
name|Op
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
block|{
return|return
operator|(
name|VT
operator|==
name|MVT
operator|::
name|Other
operator|||
name|isTypeLegal
argument_list|(
name|VT
argument_list|)
operator|)
operator|&&
operator|(
name|getOperationAction
argument_list|(
name|Op
argument_list|,
name|VT
argument_list|)
operator|==
name|Legal
operator|||
name|getOperationAction
argument_list|(
name|Op
argument_list|,
name|VT
argument_list|)
operator|==
name|Promote
operator|)
return|;
block|}
comment|/// Return true if the specified operation is legal on this target or can be
comment|/// made legal with custom lowering or using promotion. This is used to help
comment|/// guide high-level lowering decisions.
name|bool
name|isOperationLegalOrCustomOrPromote
argument_list|(
name|unsigned
name|Op
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
block|{
return|return
operator|(
name|VT
operator|==
name|MVT
operator|::
name|Other
operator|||
name|isTypeLegal
argument_list|(
name|VT
argument_list|)
operator|)
operator|&&
operator|(
name|getOperationAction
argument_list|(
name|Op
argument_list|,
name|VT
argument_list|)
operator|==
name|Legal
operator|||
name|getOperationAction
argument_list|(
name|Op
argument_list|,
name|VT
argument_list|)
operator|==
name|Custom
operator|||
name|getOperationAction
argument_list|(
name|Op
argument_list|,
name|VT
argument_list|)
operator|==
name|Promote
operator|)
return|;
block|}
comment|/// Return true if the specified operation is illegal but has a custom lowering
comment|/// on that type. This is used to help guide high-level lowering
comment|/// decisions.
name|bool
name|isOperationCustom
argument_list|(
name|unsigned
name|Op
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
block|{
return|return
operator|(
operator|!
name|isTypeLegal
argument_list|(
name|VT
argument_list|)
operator|&&
name|getOperationAction
argument_list|(
name|Op
argument_list|,
name|VT
argument_list|)
operator|==
name|Custom
operator|)
return|;
block|}
comment|/// Return true if lowering to a jump table is allowed.
name|bool
name|areJTsAllowed
argument_list|(
specifier|const
name|Function
operator|*
name|Fn
argument_list|)
decl|const
block|{
if|if
condition|(
name|Fn
operator|->
name|getFnAttribute
argument_list|(
literal|"no-jump-tables"
argument_list|)
operator|.
name|getValueAsString
argument_list|()
operator|==
literal|"true"
condition|)
return|return
name|false
return|;
return|return
name|isOperationLegalOrCustom
argument_list|(
name|ISD
operator|::
name|BR_JT
argument_list|,
name|MVT
operator|::
name|Other
argument_list|)
operator|||
name|isOperationLegalOrCustom
argument_list|(
name|ISD
operator|::
name|BRIND
argument_list|,
name|MVT
operator|::
name|Other
argument_list|)
return|;
block|}
comment|/// Check whether the range [Low,High] fits in a machine word.
name|bool
name|rangeFitsInWord
argument_list|(
specifier|const
name|APInt
operator|&
name|Low
argument_list|,
specifier|const
name|APInt
operator|&
name|High
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
decl|const
block|{
comment|// FIXME: Using the pointer type doesn't seem ideal.
name|uint64_t
name|BW
init|=
name|DL
operator|.
name|getPointerSizeInBits
argument_list|()
decl_stmt|;
name|uint64_t
name|Range
init|=
operator|(
name|High
operator|-
name|Low
operator|)
operator|.
name|getLimitedValue
argument_list|(
name|UINT64_MAX
operator|-
literal|1
argument_list|)
operator|+
literal|1
decl_stmt|;
return|return
name|Range
operator|<=
name|BW
return|;
block|}
comment|/// Return true if lowering to a jump table is suitable for a set of case
comment|/// clusters which may contain \p NumCases cases, \p Range range of values.
comment|/// FIXME: This function check the maximum table size and density, but the
comment|/// minimum size is not checked. It would be nice if the the minimum size is
comment|/// also combined within this function. Currently, the minimum size check is
comment|/// performed in findJumpTable() in SelectionDAGBuiler and
comment|/// getEstimatedNumberOfCaseClusters() in BasicTTIImpl.
name|bool
name|isSuitableForJumpTable
argument_list|(
specifier|const
name|SwitchInst
operator|*
name|SI
argument_list|,
name|uint64_t
name|NumCases
argument_list|,
name|uint64_t
name|Range
argument_list|)
decl|const
block|{
specifier|const
name|bool
name|OptForSize
init|=
name|SI
operator|->
name|getParent
argument_list|()
operator|->
name|getParent
argument_list|()
operator|->
name|optForSize
argument_list|()
decl_stmt|;
specifier|const
name|unsigned
name|MinDensity
init|=
name|getMinimumJumpTableDensity
argument_list|(
name|OptForSize
argument_list|)
decl_stmt|;
specifier|const
name|unsigned
name|MaxJumpTableSize
init|=
name|OptForSize
operator|||
name|getMaximumJumpTableSize
argument_list|()
operator|==
literal|0
condition|?
name|UINT_MAX
else|:
name|getMaximumJumpTableSize
argument_list|()
decl_stmt|;
comment|// Check whether a range of clusters is dense enough for a jump table.
if|if
condition|(
name|Range
operator|<=
name|MaxJumpTableSize
operator|&&
operator|(
name|NumCases
operator|*
literal|100
operator|>=
name|Range
operator|*
name|MinDensity
operator|)
condition|)
block|{
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
comment|/// Return true if lowering to a bit test is suitable for a set of case
comment|/// clusters which contains \p NumDests unique destinations, \p Low and
comment|/// \p High as its lowest and highest case values, and expects \p NumCmps
comment|/// case value comparisons. Check if the number of destinations, comparison
comment|/// metric, and range are all suitable.
name|bool
name|isSuitableForBitTests
argument_list|(
name|unsigned
name|NumDests
argument_list|,
name|unsigned
name|NumCmps
argument_list|,
specifier|const
name|APInt
operator|&
name|Low
argument_list|,
specifier|const
name|APInt
operator|&
name|High
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
decl|const
block|{
comment|// FIXME: I don't think NumCmps is the correct metric: a single case and a
comment|// range of cases both require only one branch to lower. Just looking at the
comment|// number of clusters and destinations should be enough to decide whether to
comment|// build bit tests.
comment|// To lower a range with bit tests, the range must fit the bitwidth of a
comment|// machine word.
if|if
condition|(
operator|!
name|rangeFitsInWord
argument_list|(
name|Low
argument_list|,
name|High
argument_list|,
name|DL
argument_list|)
condition|)
return|return
name|false
return|;
comment|// Decide whether it's profitable to lower this range with bit tests. Each
comment|// destination requires a bit test and branch, and there is an overall range
comment|// check branch. For a small number of clusters, separate comparisons might
comment|// be cheaper, and for many destinations, splitting the range might be
comment|// better.
return|return
operator|(
name|NumDests
operator|==
literal|1
operator|&&
name|NumCmps
operator|>=
literal|3
operator|)
operator|||
operator|(
name|NumDests
operator|==
literal|2
operator|&&
name|NumCmps
operator|>=
literal|5
operator|)
operator|||
operator|(
name|NumDests
operator|==
literal|3
operator|&&
name|NumCmps
operator|>=
literal|6
operator|)
return|;
block|}
comment|/// Return true if the specified operation is illegal on this target or
comment|/// unlikely to be made legal with custom lowering. This is used to help guide
comment|/// high-level lowering decisions.
name|bool
name|isOperationExpand
argument_list|(
name|unsigned
name|Op
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
block|{
return|return
operator|(
operator|!
name|isTypeLegal
argument_list|(
name|VT
argument_list|)
operator|||
name|getOperationAction
argument_list|(
name|Op
argument_list|,
name|VT
argument_list|)
operator|==
name|Expand
operator|)
return|;
block|}
comment|/// Return true if the specified operation is legal on this target.
name|bool
name|isOperationLegal
argument_list|(
name|unsigned
name|Op
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
block|{
return|return
operator|(
name|VT
operator|==
name|MVT
operator|::
name|Other
operator|||
name|isTypeLegal
argument_list|(
name|VT
argument_list|)
operator|)
operator|&&
name|getOperationAction
argument_list|(
name|Op
argument_list|,
name|VT
argument_list|)
operator|==
name|Legal
return|;
block|}
comment|/// Return how this load with extension should be treated: either it is legal,
comment|/// needs to be promoted to a larger size, needs to be expanded to some other
comment|/// code sequence, or the target has a custom expander for it.
name|LegalizeAction
name|getLoadExtAction
argument_list|(
name|unsigned
name|ExtType
argument_list|,
name|EVT
name|ValVT
argument_list|,
name|EVT
name|MemVT
argument_list|)
decl|const
block|{
if|if
condition|(
name|ValVT
operator|.
name|isExtended
argument_list|()
operator|||
name|MemVT
operator|.
name|isExtended
argument_list|()
condition|)
return|return
name|Expand
return|;
name|unsigned
name|ValI
init|=
operator|(
name|unsigned
operator|)
name|ValVT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
decl_stmt|;
name|unsigned
name|MemI
init|=
operator|(
name|unsigned
operator|)
name|MemVT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
decl_stmt|;
name|assert
argument_list|(
name|ExtType
operator|<
name|ISD
operator|::
name|LAST_LOADEXT_TYPE
operator|&&
name|ValI
operator|<
name|MVT
operator|::
name|LAST_VALUETYPE
operator|&&
name|MemI
operator|<
name|MVT
operator|::
name|LAST_VALUETYPE
operator|&&
literal|"Table isn't big enough!"
argument_list|)
expr_stmt|;
name|unsigned
name|Shift
init|=
literal|4
operator|*
name|ExtType
decl_stmt|;
return|return
call|(
name|LegalizeAction
call|)
argument_list|(
operator|(
name|LoadExtActions
index|[
name|ValI
index|]
index|[
name|MemI
index|]
operator|>>
name|Shift
operator|)
operator|&
literal|0xf
argument_list|)
return|;
block|}
comment|/// Return true if the specified load with extension is legal on this target.
name|bool
name|isLoadExtLegal
argument_list|(
name|unsigned
name|ExtType
argument_list|,
name|EVT
name|ValVT
argument_list|,
name|EVT
name|MemVT
argument_list|)
decl|const
block|{
return|return
name|getLoadExtAction
argument_list|(
name|ExtType
argument_list|,
name|ValVT
argument_list|,
name|MemVT
argument_list|)
operator|==
name|Legal
return|;
block|}
comment|/// Return true if the specified load with extension is legal or custom
comment|/// on this target.
name|bool
name|isLoadExtLegalOrCustom
argument_list|(
name|unsigned
name|ExtType
argument_list|,
name|EVT
name|ValVT
argument_list|,
name|EVT
name|MemVT
argument_list|)
decl|const
block|{
return|return
name|getLoadExtAction
argument_list|(
name|ExtType
argument_list|,
name|ValVT
argument_list|,
name|MemVT
argument_list|)
operator|==
name|Legal
operator|||
name|getLoadExtAction
argument_list|(
name|ExtType
argument_list|,
name|ValVT
argument_list|,
name|MemVT
argument_list|)
operator|==
name|Custom
return|;
block|}
comment|/// Return how this store with truncation should be treated: either it is
comment|/// legal, needs to be promoted to a larger size, needs to be expanded to some
comment|/// other code sequence, or the target has a custom expander for it.
name|LegalizeAction
name|getTruncStoreAction
argument_list|(
name|EVT
name|ValVT
argument_list|,
name|EVT
name|MemVT
argument_list|)
decl|const
block|{
if|if
condition|(
name|ValVT
operator|.
name|isExtended
argument_list|()
operator|||
name|MemVT
operator|.
name|isExtended
argument_list|()
condition|)
return|return
name|Expand
return|;
name|unsigned
name|ValI
init|=
operator|(
name|unsigned
operator|)
name|ValVT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
decl_stmt|;
name|unsigned
name|MemI
init|=
operator|(
name|unsigned
operator|)
name|MemVT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
decl_stmt|;
name|assert
argument_list|(
name|ValI
operator|<
name|MVT
operator|::
name|LAST_VALUETYPE
operator|&&
name|MemI
operator|<
name|MVT
operator|::
name|LAST_VALUETYPE
operator|&&
literal|"Table isn't big enough!"
argument_list|)
expr_stmt|;
return|return
name|TruncStoreActions
index|[
name|ValI
index|]
index|[
name|MemI
index|]
return|;
block|}
comment|/// Return true if the specified store with truncation is legal on this
comment|/// target.
name|bool
name|isTruncStoreLegal
argument_list|(
name|EVT
name|ValVT
argument_list|,
name|EVT
name|MemVT
argument_list|)
decl|const
block|{
return|return
name|isTypeLegal
argument_list|(
name|ValVT
argument_list|)
operator|&&
name|getTruncStoreAction
argument_list|(
name|ValVT
argument_list|,
name|MemVT
argument_list|)
operator|==
name|Legal
return|;
block|}
comment|/// Return true if the specified store with truncation has solution on this
comment|/// target.
name|bool
name|isTruncStoreLegalOrCustom
argument_list|(
name|EVT
name|ValVT
argument_list|,
name|EVT
name|MemVT
argument_list|)
decl|const
block|{
return|return
name|isTypeLegal
argument_list|(
name|ValVT
argument_list|)
operator|&&
operator|(
name|getTruncStoreAction
argument_list|(
name|ValVT
argument_list|,
name|MemVT
argument_list|)
operator|==
name|Legal
operator|||
name|getTruncStoreAction
argument_list|(
name|ValVT
argument_list|,
name|MemVT
argument_list|)
operator|==
name|Custom
operator|)
return|;
block|}
comment|/// Return how the indexed load should be treated: either it is legal, needs
comment|/// to be promoted to a larger size, needs to be expanded to some other code
comment|/// sequence, or the target has a custom expander for it.
name|LegalizeAction
name|getIndexedLoadAction
argument_list|(
name|unsigned
name|IdxMode
argument_list|,
name|MVT
name|VT
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|IdxMode
operator|<
name|ISD
operator|::
name|LAST_INDEXED_MODE
operator|&&
name|VT
operator|.
name|isValid
argument_list|()
operator|&&
literal|"Table isn't big enough!"
argument_list|)
expr_stmt|;
name|unsigned
name|Ty
init|=
operator|(
name|unsigned
operator|)
name|VT
operator|.
name|SimpleTy
decl_stmt|;
return|return
call|(
name|LegalizeAction
call|)
argument_list|(
operator|(
name|IndexedModeActions
index|[
name|Ty
index|]
index|[
name|IdxMode
index|]
operator|&
literal|0xf0
operator|)
operator|>>
literal|4
argument_list|)
return|;
block|}
comment|/// Return true if the specified indexed load is legal on this target.
name|bool
name|isIndexedLoadLegal
argument_list|(
name|unsigned
name|IdxMode
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
block|{
return|return
name|VT
operator|.
name|isSimple
argument_list|()
operator|&&
operator|(
name|getIndexedLoadAction
argument_list|(
name|IdxMode
argument_list|,
name|VT
operator|.
name|getSimpleVT
argument_list|()
argument_list|)
operator|==
name|Legal
operator|||
name|getIndexedLoadAction
argument_list|(
name|IdxMode
argument_list|,
name|VT
operator|.
name|getSimpleVT
argument_list|()
argument_list|)
operator|==
name|Custom
operator|)
return|;
block|}
comment|/// Return how the indexed store should be treated: either it is legal, needs
comment|/// to be promoted to a larger size, needs to be expanded to some other code
comment|/// sequence, or the target has a custom expander for it.
name|LegalizeAction
name|getIndexedStoreAction
argument_list|(
name|unsigned
name|IdxMode
argument_list|,
name|MVT
name|VT
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|IdxMode
operator|<
name|ISD
operator|::
name|LAST_INDEXED_MODE
operator|&&
name|VT
operator|.
name|isValid
argument_list|()
operator|&&
literal|"Table isn't big enough!"
argument_list|)
expr_stmt|;
name|unsigned
name|Ty
init|=
operator|(
name|unsigned
operator|)
name|VT
operator|.
name|SimpleTy
decl_stmt|;
return|return
call|(
name|LegalizeAction
call|)
argument_list|(
name|IndexedModeActions
index|[
name|Ty
index|]
index|[
name|IdxMode
index|]
operator|&
literal|0x0f
argument_list|)
return|;
block|}
comment|/// Return true if the specified indexed load is legal on this target.
name|bool
name|isIndexedStoreLegal
argument_list|(
name|unsigned
name|IdxMode
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
block|{
return|return
name|VT
operator|.
name|isSimple
argument_list|()
operator|&&
operator|(
name|getIndexedStoreAction
argument_list|(
name|IdxMode
argument_list|,
name|VT
operator|.
name|getSimpleVT
argument_list|()
argument_list|)
operator|==
name|Legal
operator|||
name|getIndexedStoreAction
argument_list|(
name|IdxMode
argument_list|,
name|VT
operator|.
name|getSimpleVT
argument_list|()
argument_list|)
operator|==
name|Custom
operator|)
return|;
block|}
comment|/// Return how the condition code should be treated: either it is legal, needs
comment|/// to be expanded to some other code sequence, or the target has a custom
comment|/// expander for it.
name|LegalizeAction
name|getCondCodeAction
argument_list|(
name|ISD
operator|::
name|CondCode
name|CC
argument_list|,
name|MVT
name|VT
argument_list|)
decl|const
block|{
name|assert
argument_list|(
operator|(
name|unsigned
operator|)
name|CC
operator|<
name|array_lengthof
argument_list|(
name|CondCodeActions
argument_list|)
operator|&&
operator|(
operator|(
name|unsigned
operator|)
name|VT
operator|.
name|SimpleTy
operator|>>
literal|3
operator|)
operator|<
name|array_lengthof
argument_list|(
name|CondCodeActions
index|[
literal|0
index|]
argument_list|)
operator|&&
literal|"Table isn't big enough!"
argument_list|)
expr_stmt|;
comment|// See setCondCodeAction for how this is encoded.
name|uint32_t
name|Shift
init|=
literal|4
operator|*
operator|(
name|VT
operator|.
name|SimpleTy
operator|&
literal|0x7
operator|)
decl_stmt|;
name|uint32_t
name|Value
init|=
name|CondCodeActions
index|[
name|CC
index|]
index|[
name|VT
operator|.
name|SimpleTy
operator|>>
literal|3
index|]
decl_stmt|;
name|LegalizeAction
name|Action
init|=
call|(
name|LegalizeAction
call|)
argument_list|(
operator|(
name|Value
operator|>>
name|Shift
operator|)
operator|&
literal|0xF
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|Action
operator|!=
name|Promote
operator|&&
literal|"Can't promote condition code!"
argument_list|)
expr_stmt|;
return|return
name|Action
return|;
block|}
comment|/// Return true if the specified condition code is legal on this target.
name|bool
name|isCondCodeLegal
argument_list|(
name|ISD
operator|::
name|CondCode
name|CC
argument_list|,
name|MVT
name|VT
argument_list|)
decl|const
block|{
return|return
name|getCondCodeAction
argument_list|(
name|CC
argument_list|,
name|VT
argument_list|)
operator|==
name|Legal
operator|||
name|getCondCodeAction
argument_list|(
name|CC
argument_list|,
name|VT
argument_list|)
operator|==
name|Custom
return|;
block|}
comment|/// If the action for this operation is to promote, this method returns the
comment|/// ValueType to promote to.
name|MVT
name|getTypeToPromoteTo
argument_list|(
name|unsigned
name|Op
argument_list|,
name|MVT
name|VT
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|getOperationAction
argument_list|(
name|Op
argument_list|,
name|VT
argument_list|)
operator|==
name|Promote
operator|&&
literal|"This operation isn't promoted!"
argument_list|)
expr_stmt|;
comment|// See if this has an explicit type specified.
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|MVT
operator|::
name|SimpleValueType
operator|>
operator|,
name|MVT
operator|::
name|SimpleValueType
operator|>
operator|::
name|const_iterator
name|PTTI
operator|=
name|PromoteToType
operator|.
name|find
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Op
argument_list|,
name|VT
operator|.
name|SimpleTy
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|PTTI
operator|!=
name|PromoteToType
operator|.
name|end
argument_list|()
condition|)
return|return
name|PTTI
operator|->
name|second
return|;
name|assert
argument_list|(
operator|(
name|VT
operator|.
name|isInteger
argument_list|()
operator|||
name|VT
operator|.
name|isFloatingPoint
argument_list|()
operator|)
operator|&&
literal|"Cannot autopromote this type, add it with AddPromotedToType."
argument_list|)
expr_stmt|;
name|MVT
name|NVT
init|=
name|VT
decl_stmt|;
do|do
block|{
name|NVT
operator|=
operator|(
name|MVT
operator|::
name|SimpleValueType
operator|)
operator|(
name|NVT
operator|.
name|SimpleTy
operator|+
literal|1
operator|)
expr_stmt|;
name|assert
argument_list|(
name|NVT
operator|.
name|isInteger
argument_list|()
operator|==
name|VT
operator|.
name|isInteger
argument_list|()
operator|&&
name|NVT
operator|!=
name|MVT
operator|::
name|isVoid
operator|&&
literal|"Didn't find type to promote to!"
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
operator|!
name|isTypeLegal
argument_list|(
name|NVT
argument_list|)
operator|||
name|getOperationAction
argument_list|(
name|Op
argument_list|,
name|NVT
argument_list|)
operator|==
name|Promote
condition|)
do|;
return|return
name|NVT
return|;
block|}
comment|/// Return the EVT corresponding to this LLVM type.  This is fixed by the LLVM
comment|/// operations except for the pointer size.  If AllowUnknown is true, this
comment|/// will return MVT::Other for types with no EVT counterpart (e.g. structs),
comment|/// otherwise it will assert.
name|EVT
name|getValueType
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
name|Type
operator|*
name|Ty
argument_list|,
name|bool
name|AllowUnknown
operator|=
name|false
argument_list|)
decl|const
block|{
comment|// Lower scalar pointers to native pointer types.
if|if
condition|(
name|PointerType
modifier|*
name|PTy
init|=
name|dyn_cast
operator|<
name|PointerType
operator|>
operator|(
name|Ty
operator|)
condition|)
return|return
name|getPointerTy
argument_list|(
name|DL
argument_list|,
name|PTy
operator|->
name|getAddressSpace
argument_list|()
argument_list|)
return|;
if|if
condition|(
name|Ty
operator|->
name|isVectorTy
argument_list|()
condition|)
block|{
name|VectorType
modifier|*
name|VTy
init|=
name|cast
operator|<
name|VectorType
operator|>
operator|(
name|Ty
operator|)
decl_stmt|;
name|Type
modifier|*
name|Elm
init|=
name|VTy
operator|->
name|getElementType
argument_list|()
decl_stmt|;
comment|// Lower vectors of pointers to native pointer types.
if|if
condition|(
name|PointerType
modifier|*
name|PT
init|=
name|dyn_cast
operator|<
name|PointerType
operator|>
operator|(
name|Elm
operator|)
condition|)
block|{
name|EVT
name|PointerTy
argument_list|(
name|getPointerTy
argument_list|(
name|DL
argument_list|,
name|PT
operator|->
name|getAddressSpace
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|Elm
operator|=
name|PointerTy
operator|.
name|getTypeForEVT
argument_list|(
name|Ty
operator|->
name|getContext
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
name|EVT
operator|::
name|getVectorVT
argument_list|(
name|Ty
operator|->
name|getContext
argument_list|()
argument_list|,
name|EVT
operator|::
name|getEVT
argument_list|(
name|Elm
argument_list|,
name|false
argument_list|)
argument_list|,
name|VTy
operator|->
name|getNumElements
argument_list|()
argument_list|)
return|;
block|}
return|return
name|EVT
operator|::
name|getEVT
argument_list|(
name|Ty
argument_list|,
name|AllowUnknown
argument_list|)
return|;
block|}
comment|/// Return the MVT corresponding to this LLVM type. See getValueType.
name|MVT
name|getSimpleValueType
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
name|Type
operator|*
name|Ty
argument_list|,
name|bool
name|AllowUnknown
operator|=
name|false
argument_list|)
decl|const
block|{
return|return
name|getValueType
argument_list|(
name|DL
argument_list|,
name|Ty
argument_list|,
name|AllowUnknown
argument_list|)
operator|.
name|getSimpleVT
argument_list|()
return|;
block|}
comment|/// Return the desired alignment for ByVal or InAlloca aggregate function
comment|/// arguments in the caller parameter area.  This is the actual alignment, not
comment|/// its logarithm.
name|virtual
name|unsigned
name|getByValTypeAlignment
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the type of registers that this ValueType will eventually require.
name|MVT
name|getRegisterType
argument_list|(
name|MVT
name|VT
argument_list|)
decl|const
block|{
name|assert
argument_list|(
operator|(
name|unsigned
operator|)
name|VT
operator|.
name|SimpleTy
operator|<
name|array_lengthof
argument_list|(
name|RegisterTypeForVT
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|RegisterTypeForVT
index|[
name|VT
operator|.
name|SimpleTy
index|]
return|;
block|}
comment|/// Return the type of registers that this ValueType will eventually require.
name|MVT
name|getRegisterType
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
block|{
if|if
condition|(
name|VT
operator|.
name|isSimple
argument_list|()
condition|)
block|{
name|assert
argument_list|(
operator|(
name|unsigned
operator|)
name|VT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
operator|<
name|array_lengthof
argument_list|(
name|RegisterTypeForVT
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|RegisterTypeForVT
index|[
name|VT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
index|]
return|;
block|}
if|if
condition|(
name|VT
operator|.
name|isVector
argument_list|()
condition|)
block|{
name|EVT
name|VT1
decl_stmt|;
name|MVT
name|RegisterVT
decl_stmt|;
name|unsigned
name|NumIntermediates
decl_stmt|;
operator|(
name|void
operator|)
name|getVectorTypeBreakdown
argument_list|(
name|Context
argument_list|,
name|VT
argument_list|,
name|VT1
argument_list|,
name|NumIntermediates
argument_list|,
name|RegisterVT
argument_list|)
expr_stmt|;
return|return
name|RegisterVT
return|;
block|}
if|if
condition|(
name|VT
operator|.
name|isInteger
argument_list|()
condition|)
block|{
return|return
name|getRegisterType
argument_list|(
name|Context
argument_list|,
name|getTypeToTransformTo
argument_list|(
name|Context
argument_list|,
name|VT
argument_list|)
argument_list|)
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Unsupported extended type!"
argument_list|)
expr_stmt|;
block|}
comment|/// Return the number of registers that this ValueType will eventually
comment|/// require.
comment|///
comment|/// This is one for any types promoted to live in larger registers, but may be
comment|/// more than one for types (like i64) that are split into pieces.  For types
comment|/// like i140, which are first promoted then expanded, it is the number of
comment|/// registers needed to hold all the bits of the original type.  For an i140
comment|/// on a 32 bit machine this means 5 registers.
name|unsigned
name|getNumRegisters
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
block|{
if|if
condition|(
name|VT
operator|.
name|isSimple
argument_list|()
condition|)
block|{
name|assert
argument_list|(
operator|(
name|unsigned
operator|)
name|VT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
operator|<
name|array_lengthof
argument_list|(
name|NumRegistersForVT
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|NumRegistersForVT
index|[
name|VT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
index|]
return|;
block|}
if|if
condition|(
name|VT
operator|.
name|isVector
argument_list|()
condition|)
block|{
name|EVT
name|VT1
decl_stmt|;
name|MVT
name|VT2
decl_stmt|;
name|unsigned
name|NumIntermediates
decl_stmt|;
return|return
name|getVectorTypeBreakdown
argument_list|(
name|Context
argument_list|,
name|VT
argument_list|,
name|VT1
argument_list|,
name|NumIntermediates
argument_list|,
name|VT2
argument_list|)
return|;
block|}
if|if
condition|(
name|VT
operator|.
name|isInteger
argument_list|()
condition|)
block|{
name|unsigned
name|BitWidth
init|=
name|VT
operator|.
name|getSizeInBits
argument_list|()
decl_stmt|;
name|unsigned
name|RegWidth
init|=
name|getRegisterType
argument_list|(
name|Context
argument_list|,
name|VT
argument_list|)
operator|.
name|getSizeInBits
argument_list|()
decl_stmt|;
return|return
operator|(
name|BitWidth
operator|+
name|RegWidth
operator|-
literal|1
operator|)
operator|/
name|RegWidth
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Unsupported extended type!"
argument_list|)
expr_stmt|;
block|}
comment|/// If true, then instruction selection should seek to shrink the FP constant
comment|/// of the specified type to a smaller type in order to save space and / or
comment|/// reduce runtime.
name|virtual
name|bool
name|ShouldShrinkFPConstant
argument_list|(
name|EVT
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
comment|// Return true if it is profitable to reduce the given load node to a smaller
comment|// type.
comment|//
comment|// e.g. (i16 (trunc (i32 (load x))) -> i16 load x should be performed
name|virtual
name|bool
name|shouldReduceLoadWidth
argument_list|(
name|SDNode
operator|*
name|Load
argument_list|,
name|ISD
operator|::
name|LoadExtType
name|ExtTy
argument_list|,
name|EVT
name|NewVT
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
comment|/// When splitting a value of the specified type into parts, does the Lo
comment|/// or Hi part come first?  This usually follows the endianness, except
comment|/// for ppcf128, where the Hi part always comes first.
name|bool
name|hasBigEndianPartOrdering
argument_list|(
name|EVT
name|VT
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
decl|const
block|{
return|return
name|DL
operator|.
name|isBigEndian
argument_list|()
operator|||
name|VT
operator|==
name|MVT
operator|::
name|ppcf128
return|;
block|}
comment|/// If true, the target has custom DAG combine transformations that it can
comment|/// perform for the specified node.
name|bool
name|hasTargetDAGCombine
argument_list|(
name|ISD
operator|::
name|NodeType
name|NT
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|NT
operator|>>
literal|3
argument_list|)
operator|<
name|array_lengthof
argument_list|(
name|TargetDAGCombineArray
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|TargetDAGCombineArray
index|[
name|NT
operator|>>
literal|3
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
name|NT
operator|&
literal|7
operator|)
operator|)
return|;
block|}
name|unsigned
name|getGatherAllAliasesMaxDepth
argument_list|()
specifier|const
block|{
return|return
name|GatherAllAliasesMaxDepth
return|;
block|}
comment|/// Returns the size of the platform's va_list object.
name|virtual
name|unsigned
name|getVaListSizeInBits
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
decl|const
block|{
return|return
name|getPointerTy
argument_list|(
name|DL
argument_list|)
operator|.
name|getSizeInBits
argument_list|()
return|;
block|}
comment|/// \brief Get maximum # of store operations permitted for llvm.memset
comment|///
comment|/// This function returns the maximum number of store operations permitted
comment|/// to replace a call to llvm.memset. The value is set by the target at the
comment|/// performance threshold for such a replacement. If OptSize is true,
comment|/// return the limit for functions that have OptSize attribute.
name|unsigned
name|getMaxStoresPerMemset
argument_list|(
name|bool
name|OptSize
argument_list|)
decl|const
block|{
return|return
name|OptSize
condition|?
name|MaxStoresPerMemsetOptSize
else|:
name|MaxStoresPerMemset
return|;
block|}
comment|/// \brief Get maximum # of store operations permitted for llvm.memcpy
comment|///
comment|/// This function returns the maximum number of store operations permitted
comment|/// to replace a call to llvm.memcpy. The value is set by the target at the
comment|/// performance threshold for such a replacement. If OptSize is true,
comment|/// return the limit for functions that have OptSize attribute.
name|unsigned
name|getMaxStoresPerMemcpy
argument_list|(
name|bool
name|OptSize
argument_list|)
decl|const
block|{
return|return
name|OptSize
condition|?
name|MaxStoresPerMemcpyOptSize
else|:
name|MaxStoresPerMemcpy
return|;
block|}
comment|/// \brief Get maximum # of store operations permitted for llvm.memmove
comment|///
comment|/// This function returns the maximum number of store operations permitted
comment|/// to replace a call to llvm.memmove. The value is set by the target at the
comment|/// performance threshold for such a replacement. If OptSize is true,
comment|/// return the limit for functions that have OptSize attribute.
name|unsigned
name|getMaxStoresPerMemmove
argument_list|(
name|bool
name|OptSize
argument_list|)
decl|const
block|{
return|return
name|OptSize
condition|?
name|MaxStoresPerMemmoveOptSize
else|:
name|MaxStoresPerMemmove
return|;
block|}
comment|/// \brief Determine if the target supports unaligned memory accesses.
comment|///
comment|/// This function returns true if the target allows unaligned memory accesses
comment|/// of the specified type in the given address space. If true, it also returns
comment|/// whether the unaligned memory access is "fast" in the last argument by
comment|/// reference. This is used, for example, in situations where an array
comment|/// copy/move/set is converted to a sequence of store operations. Its use
comment|/// helps to ensure that such replacements don't generate code that causes an
comment|/// alignment error (trap) on the target machine.
name|virtual
name|bool
name|allowsMisalignedMemoryAccesses
argument_list|(
name|EVT
argument_list|,
name|unsigned
name|AddrSpace
operator|=
literal|0
argument_list|,
name|unsigned
name|Align
operator|=
literal|1
argument_list|,
name|bool
operator|*
comment|/*Fast*/
operator|=
name|nullptr
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return true if the target supports a memory access of this type for the
comment|/// given address space and alignment. If the access is allowed, the optional
comment|/// final parameter returns if the access is also fast (as defined by the
comment|/// target).
name|bool
name|allowsMemoryAccess
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
name|EVT
name|VT
argument_list|,
name|unsigned
name|AddrSpace
operator|=
literal|0
argument_list|,
name|unsigned
name|Alignment
operator|=
literal|1
argument_list|,
name|bool
operator|*
name|Fast
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns the target specific optimal type for load and store operations as
comment|/// a result of memset, memcpy, and memmove lowering.
comment|///
comment|/// If DstAlign is zero that means it's safe to destination alignment can
comment|/// satisfy any constraint. Similarly if SrcAlign is zero it means there isn't
comment|/// a need to check it against alignment requirement, probably because the
comment|/// source does not need to be loaded. If 'IsMemset' is true, that means it's
comment|/// expanding a memset. If 'ZeroMemset' is true, that means it's a memset of
comment|/// zero. 'MemcpyStrSrc' indicates whether the memcpy source is constant so it
comment|/// does not need to be loaded.  It returns EVT::Other if the type should be
comment|/// determined using generic target-independent logic.
name|virtual
name|EVT
name|getOptimalMemOpType
argument_list|(
name|uint64_t
comment|/*Size*/
argument_list|,
name|unsigned
comment|/*DstAlign*/
argument_list|,
name|unsigned
comment|/*SrcAlign*/
argument_list|,
name|bool
comment|/*IsMemset*/
argument_list|,
name|bool
comment|/*ZeroMemset*/
argument_list|,
name|bool
comment|/*MemcpyStrSrc*/
argument_list|,
name|MachineFunction
operator|&
comment|/*MF*/
argument_list|)
decl|const
block|{
return|return
name|MVT
operator|::
name|Other
return|;
block|}
comment|/// Returns true if it's safe to use load / store of the specified type to
comment|/// expand memcpy / memset inline.
comment|///
comment|/// This is mostly true for all types except for some special cases. For
comment|/// example, on X86 targets without SSE2 f64 load / store are done with fldl /
comment|/// fstpl which also does type conversion. Note the specified type doesn't
comment|/// have to be legal as the hook is used before type legalization.
name|virtual
name|bool
name|isSafeMemOpType
argument_list|(
name|MVT
comment|/*VT*/
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
comment|/// Determine if we should use _setjmp or setjmp to implement llvm.setjmp.
name|bool
name|usesUnderscoreSetJmp
argument_list|()
specifier|const
block|{
return|return
name|UseUnderscoreSetJmp
return|;
block|}
comment|/// Determine if we should use _longjmp or longjmp to implement llvm.longjmp.
name|bool
name|usesUnderscoreLongJmp
argument_list|()
specifier|const
block|{
return|return
name|UseUnderscoreLongJmp
return|;
block|}
comment|/// Return lower limit for number of blocks in a jump table.
name|unsigned
name|getMinimumJumpTableEntries
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return lower limit of the density in a jump table.
name|unsigned
name|getMinimumJumpTableDensity
argument_list|(
name|bool
name|OptForSize
argument_list|)
decl|const
decl_stmt|;
comment|/// Return upper limit for number of entries in a jump table.
comment|/// Zero if no limit.
name|unsigned
name|getMaximumJumpTableSize
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|bool
name|isJumpTableRelative
argument_list|()
specifier|const
block|{
return|return
name|TM
operator|.
name|isPositionIndependent
argument_list|()
return|;
block|}
comment|/// If a physical register, this specifies the register that
comment|/// llvm.savestack/llvm.restorestack should save and restore.
name|unsigned
name|getStackPointerRegisterToSaveRestore
argument_list|()
specifier|const
block|{
return|return
name|StackPointerRegisterToSaveRestore
return|;
block|}
comment|/// If a physical register, this returns the register that receives the
comment|/// exception address on entry to an EH pad.
name|virtual
name|unsigned
name|getExceptionPointerRegister
argument_list|(
specifier|const
name|Constant
operator|*
name|PersonalityFn
argument_list|)
decl|const
block|{
comment|// 0 is guaranteed to be the NoRegister value on all targets
return|return
literal|0
return|;
block|}
comment|/// If a physical register, this returns the register that receives the
comment|/// exception typeid on entry to a landing pad.
name|virtual
name|unsigned
name|getExceptionSelectorRegister
argument_list|(
specifier|const
name|Constant
operator|*
name|PersonalityFn
argument_list|)
decl|const
block|{
comment|// 0 is guaranteed to be the NoRegister value on all targets
return|return
literal|0
return|;
block|}
name|virtual
name|bool
name|needsFixedCatchObjects
argument_list|()
specifier|const
block|{
name|report_fatal_error
argument_list|(
literal|"Funclet EH is not implemented for this target"
argument_list|)
block|;   }
comment|/// Returns the target's jmp_buf size in bytes (if never set, the default is
comment|/// 200)
name|unsigned
name|getJumpBufSize
argument_list|()
specifier|const
block|{
return|return
name|JumpBufSize
return|;
block|}
comment|/// Returns the target's jmp_buf alignment in bytes (if never set, the default
comment|/// is 0)
name|unsigned
name|getJumpBufAlignment
argument_list|()
specifier|const
block|{
return|return
name|JumpBufAlignment
return|;
block|}
comment|/// Return the minimum stack alignment of an argument.
name|unsigned
name|getMinStackArgumentAlignment
argument_list|()
specifier|const
block|{
return|return
name|MinStackArgumentAlignment
return|;
block|}
comment|/// Return the minimum function alignment.
name|unsigned
name|getMinFunctionAlignment
argument_list|()
specifier|const
block|{
return|return
name|MinFunctionAlignment
return|;
block|}
comment|/// Return the preferred function alignment.
name|unsigned
name|getPrefFunctionAlignment
argument_list|()
specifier|const
block|{
return|return
name|PrefFunctionAlignment
return|;
block|}
comment|/// Return the preferred loop alignment.
name|virtual
name|unsigned
name|getPrefLoopAlignment
argument_list|(
name|MachineLoop
operator|*
name|ML
operator|=
name|nullptr
argument_list|)
decl|const
block|{
return|return
name|PrefLoopAlignment
return|;
block|}
comment|/// If the target has a standard location for the stack protector guard,
comment|/// returns the address of that location. Otherwise, returns nullptr.
comment|/// DEPRECATED: please override useLoadStackGuardNode and customize
comment|///             LOAD_STACK_GUARD, or customize @llvm.stackguard().
name|virtual
name|Value
modifier|*
name|getIRStackGuard
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|IRB
argument_list|)
decl|const
decl_stmt|;
comment|/// Inserts necessary declarations for SSP (stack protection) purpose.
comment|/// Should be used only when getIRStackGuard returns nullptr.
name|virtual
name|void
name|insertSSPDeclarations
argument_list|(
name|Module
operator|&
name|M
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the variable that's previously inserted by insertSSPDeclarations,
comment|/// if any, otherwise return nullptr. Should be used only when
comment|/// getIRStackGuard returns nullptr.
name|virtual
name|Value
modifier|*
name|getSDagStackGuard
argument_list|(
specifier|const
name|Module
operator|&
name|M
argument_list|)
decl|const
decl_stmt|;
comment|/// If the target has a standard stack protection check function that
comment|/// performs validation and error handling, returns the function. Otherwise,
comment|/// returns nullptr. Must be previously inserted by insertSSPDeclarations.
comment|/// Should be used only when getIRStackGuard returns nullptr.
name|virtual
name|Value
modifier|*
name|getSSPStackGuardCheck
argument_list|(
specifier|const
name|Module
operator|&
name|M
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
name|Value
modifier|*
name|getDefaultSafeStackPointerLocation
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|IRB
argument_list|,
name|bool
name|UseTLS
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
comment|/// Returns the target-specific address of the unsafe stack pointer.
name|virtual
name|Value
modifier|*
name|getSafeStackPointerLocation
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|IRB
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns true if a cast between SrcAS and DestAS is a noop.
name|virtual
name|bool
name|isNoopAddrSpaceCast
argument_list|(
name|unsigned
name|SrcAS
argument_list|,
name|unsigned
name|DestAS
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Returns true if a cast from SrcAS to DestAS is "cheap", such that e.g. we
comment|/// are happy to sink it into basic blocks.
name|virtual
name|bool
name|isCheapAddrSpaceCast
argument_list|(
name|unsigned
name|SrcAS
argument_list|,
name|unsigned
name|DestAS
argument_list|)
decl|const
block|{
return|return
name|isNoopAddrSpaceCast
argument_list|(
name|SrcAS
argument_list|,
name|DestAS
argument_list|)
return|;
block|}
comment|/// Return true if the pointer arguments to CI should be aligned by aligning
comment|/// the object whose address is being passed. If so then MinSize is set to the
comment|/// minimum size the object must be to be aligned and PrefAlign is set to the
comment|/// preferred alignment.
name|virtual
name|bool
name|shouldAlignPointerArgs
argument_list|(
name|CallInst
operator|*
comment|/*CI*/
argument_list|,
name|unsigned
operator|&
comment|/*MinSize*/
argument_list|,
name|unsigned
operator|&
comment|/*PrefAlign*/
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|/// \name Helpers for TargetTransformInfo implementations
comment|/// @{
comment|/// Get the ISD node that corresponds to the Instruction class opcode.
name|int
name|InstructionOpcodeToISD
argument_list|(
name|unsigned
name|Opcode
argument_list|)
decl|const
decl_stmt|;
comment|/// Estimate the cost of type-legalization and the legalized type.
name|std
operator|::
name|pair
operator|<
name|int
operator|,
name|MVT
operator|>
name|getTypeLegalizationCost
argument_list|(
argument|const DataLayout&DL
argument_list|,
argument|Type *Ty
argument_list|)
specifier|const
expr_stmt|;
comment|/// @}
comment|//===--------------------------------------------------------------------===//
comment|/// \name Helpers for atomic expansion.
comment|/// @{
comment|/// Returns the maximum atomic operation size (in bits) supported by
comment|/// the backend. Atomic operations greater than this size (as well
comment|/// as ones that are not naturally aligned), will be expanded by
comment|/// AtomicExpandPass into an __atomic_* library call.
name|unsigned
name|getMaxAtomicSizeInBitsSupported
argument_list|()
specifier|const
block|{
return|return
name|MaxAtomicSizeInBitsSupported
return|;
block|}
comment|/// Returns the size of the smallest cmpxchg or ll/sc instruction
comment|/// the backend supports.  Any smaller operations are widened in
comment|/// AtomicExpandPass.
comment|///
comment|/// Note that *unlike* operations above the maximum size, atomic ops
comment|/// are still natively supported below the minimum; they just
comment|/// require a more complex expansion.
name|unsigned
name|getMinCmpXchgSizeInBits
argument_list|()
specifier|const
block|{
return|return
name|MinCmpXchgSizeInBits
return|;
block|}
comment|/// Whether AtomicExpandPass should automatically insert fences and reduce
comment|/// ordering for this atomic. This should be true for most architectures with
comment|/// weak memory ordering. Defaults to false.
name|virtual
name|bool
name|shouldInsertFencesForAtomic
argument_list|(
specifier|const
name|Instruction
operator|*
name|I
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Perform a load-linked operation on Addr, returning a "Value *" with the
comment|/// corresponding pointee type. This may entail some non-trivial operations to
comment|/// truncate or reconstruct types that will be illegal in the backend. See
comment|/// ARMISelLowering for an example implementation.
name|virtual
name|Value
modifier|*
name|emitLoadLinked
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|Builder
argument_list|,
name|Value
operator|*
name|Addr
argument_list|,
name|AtomicOrdering
name|Ord
argument_list|)
decl|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Load linked unimplemented on this target"
argument_list|)
expr_stmt|;
block|}
comment|/// Perform a store-conditional operation to Addr. Return the status of the
comment|/// store. This should be 0 if the store succeeded, non-zero otherwise.
name|virtual
name|Value
modifier|*
name|emitStoreConditional
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|Builder
argument_list|,
name|Value
operator|*
name|Val
argument_list|,
name|Value
operator|*
name|Addr
argument_list|,
name|AtomicOrdering
name|Ord
argument_list|)
decl|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Store conditional unimplemented on this target"
argument_list|)
expr_stmt|;
block|}
comment|/// Inserts in the IR a target-specific intrinsic specifying a fence.
comment|/// It is called by AtomicExpandPass before expanding an
comment|///   AtomicRMW/AtomicCmpXchg/AtomicStore/AtomicLoad
comment|///   if shouldInsertFencesForAtomic returns true.
comment|/// RMW and CmpXchg set both IsStore and IsLoad to true.
comment|/// This function should either return a nullptr, or a pointer to an IR-level
comment|///   Instruction*. Even complex fence sequences can be represented by a
comment|///   single Instruction* through an intrinsic to be lowered later.
comment|/// Backends should override this method to produce target-specific intrinsic
comment|///   for their fences.
comment|/// FIXME: Please note that the default implementation here in terms of
comment|///   IR-level fences exists for historical/compatibility reasons and is
comment|///   *unsound* ! Fences cannot, in general, be used to restore sequential
comment|///   consistency. For example, consider the following example:
comment|/// atomic<int> x = y = 0;
comment|/// int r1, r2, r3, r4;
comment|/// Thread 0:
comment|///   x.store(1);
comment|/// Thread 1:
comment|///   y.store(1);
comment|/// Thread 2:
comment|///   r1 = x.load();
comment|///   r2 = y.load();
comment|/// Thread 3:
comment|///   r3 = y.load();
comment|///   r4 = x.load();
comment|///  r1 = r3 = 1 and r2 = r4 = 0 is impossible as long as the accesses are all
comment|///  seq_cst. But if they are lowered to monotonic accesses, no amount of
comment|///  IR-level fences can prevent it.
comment|/// @{
name|virtual
name|Instruction
modifier|*
name|emitLeadingFence
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|Builder
argument_list|,
name|AtomicOrdering
name|Ord
argument_list|,
name|bool
name|IsStore
argument_list|,
name|bool
name|IsLoad
argument_list|)
decl|const
block|{
if|if
condition|(
name|isReleaseOrStronger
argument_list|(
name|Ord
argument_list|)
operator|&&
name|IsStore
condition|)
return|return
name|Builder
operator|.
name|CreateFence
argument_list|(
name|Ord
argument_list|)
return|;
else|else
return|return
name|nullptr
return|;
block|}
name|virtual
name|Instruction
modifier|*
name|emitTrailingFence
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|Builder
argument_list|,
name|AtomicOrdering
name|Ord
argument_list|,
name|bool
name|IsStore
argument_list|,
name|bool
name|IsLoad
argument_list|)
decl|const
block|{
if|if
condition|(
name|isAcquireOrStronger
argument_list|(
name|Ord
argument_list|)
condition|)
return|return
name|Builder
operator|.
name|CreateFence
argument_list|(
name|Ord
argument_list|)
return|;
else|else
return|return
name|nullptr
return|;
block|}
comment|/// @}
comment|// Emits code that executes when the comparison result in the ll/sc
comment|// expansion of a cmpxchg instruction is such that the store-conditional will
comment|// not execute.  This makes it possible to balance out the load-linked with
comment|// a dedicated instruction, if desired.
comment|// E.g., on ARM, if ldrex isn't followed by strex, the exclusive monitor would
comment|// be unnecessarily held, except if clrex, inserted by this hook, is executed.
name|virtual
name|void
name|emitAtomicCmpXchgNoStoreLLBalance
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|Builder
argument_list|)
decl|const
block|{}
comment|/// Returns true if the given (atomic) store should be expanded by the
comment|/// IR-level AtomicExpand pass into an "atomic xchg" which ignores its input.
name|virtual
name|bool
name|shouldExpandAtomicStoreInIR
argument_list|(
name|StoreInst
operator|*
name|SI
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Returns true if arguments should be sign-extended in lib calls.
name|virtual
name|bool
name|shouldSignExtendTypeInLibCall
argument_list|(
name|EVT
name|Type
argument_list|,
name|bool
name|IsSigned
argument_list|)
decl|const
block|{
return|return
name|IsSigned
return|;
block|}
comment|/// Returns how the given (atomic) load should be expanded by the
comment|/// IR-level AtomicExpand pass.
name|virtual
name|AtomicExpansionKind
name|shouldExpandAtomicLoadInIR
argument_list|(
name|LoadInst
operator|*
name|LI
argument_list|)
decl|const
block|{
return|return
name|AtomicExpansionKind
operator|::
name|None
return|;
block|}
comment|/// Returns true if the given atomic cmpxchg should be expanded by the
comment|/// IR-level AtomicExpand pass into a load-linked/store-conditional sequence
comment|/// (through emitLoadLinked() and emitStoreConditional()).
name|virtual
name|bool
name|shouldExpandAtomicCmpXchgInIR
argument_list|(
name|AtomicCmpXchgInst
operator|*
name|AI
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Returns how the IR-level AtomicExpand pass should expand the given
comment|/// AtomicRMW, if at all. Default is to never expand.
name|virtual
name|AtomicExpansionKind
name|shouldExpandAtomicRMWInIR
argument_list|(
name|AtomicRMWInst
operator|*
argument_list|)
decl|const
block|{
return|return
name|AtomicExpansionKind
operator|::
name|None
return|;
block|}
comment|/// On some platforms, an AtomicRMW that never actually modifies the value
comment|/// (such as fetch_add of 0) can be turned into a fence followed by an
comment|/// atomic load. This may sound useless, but it makes it possible for the
comment|/// processor to keep the cacheline shared, dramatically improving
comment|/// performance. And such idempotent RMWs are useful for implementing some
comment|/// kinds of locks, see for example (justification + benchmarks):
comment|/// http://www.hpl.hp.com/techreports/2012/HPL-2012-68.pdf
comment|/// This method tries doing that transformation, returning the atomic load if
comment|/// it succeeds, and nullptr otherwise.
comment|/// If shouldExpandAtomicLoadInIR returns true on that load, it will undergo
comment|/// another round of expansion.
name|virtual
name|LoadInst
modifier|*
name|lowerIdempotentRMWIntoFencedLoad
argument_list|(
name|AtomicRMWInst
operator|*
name|RMWI
argument_list|)
decl|const
block|{
return|return
name|nullptr
return|;
block|}
comment|/// Returns how the platform's atomic operations are extended (ZERO_EXTEND,
comment|/// SIGN_EXTEND, or ANY_EXTEND).
name|virtual
name|ISD
operator|::
name|NodeType
name|getExtendForAtomicOps
argument_list|()
specifier|const
block|{
return|return
name|ISD
operator|::
name|ZERO_EXTEND
return|;
block|}
comment|/// @}
comment|/// Returns true if we should normalize
comment|/// select(N0&N1, X, Y) => select(N0, select(N1, X, Y), Y) and
comment|/// select(N0|N1, X, Y) => select(N0, select(N1, X, Y, Y)) if it is likely
comment|/// that it saves us from materializing N0 and N1 in an integer register.
comment|/// Targets that are able to perform and/or on flags should return false here.
name|virtual
name|bool
name|shouldNormalizeToSelectSequence
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
block|{
comment|// If a target has multiple condition registers, then it likely has logical
comment|// operations on those registers.
if|if
condition|(
name|hasMultipleConditionRegisters
argument_list|()
condition|)
return|return
name|false
return|;
comment|// Only do the transform if the value won't be split into multiple
comment|// registers.
name|LegalizeTypeAction
name|Action
init|=
name|getTypeAction
argument_list|(
name|Context
argument_list|,
name|VT
argument_list|)
decl_stmt|;
return|return
name|Action
operator|!=
name|TypeExpandInteger
operator|&&
name|Action
operator|!=
name|TypeExpandFloat
operator|&&
name|Action
operator|!=
name|TypeSplitVector
return|;
block|}
comment|/// Return true if a select of constants (select Cond, C1, C2) should be
comment|/// transformed into simple math ops with the condition value. For example:
comment|/// select Cond, C1, C1-1 --> add (zext Cond), C1-1
name|virtual
name|bool
name|convertSelectOfConstantsToMath
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// TargetLowering Configuration Methods - These methods should be invoked by
comment|// the derived class constructor to configure this object for the target.
comment|//
name|protected
label|:
comment|/// Specify how the target extends the result of integer and floating point
comment|/// boolean values from i1 to a wider type.  See getBooleanContents.
name|void
name|setBooleanContents
parameter_list|(
name|BooleanContent
name|Ty
parameter_list|)
block|{
name|BooleanContents
operator|=
name|Ty
expr_stmt|;
name|BooleanFloatContents
operator|=
name|Ty
expr_stmt|;
block|}
comment|/// Specify how the target extends the result of integer and floating point
comment|/// boolean values from i1 to a wider type.  See getBooleanContents.
name|void
name|setBooleanContents
parameter_list|(
name|BooleanContent
name|IntTy
parameter_list|,
name|BooleanContent
name|FloatTy
parameter_list|)
block|{
name|BooleanContents
operator|=
name|IntTy
expr_stmt|;
name|BooleanFloatContents
operator|=
name|FloatTy
expr_stmt|;
block|}
comment|/// Specify how the target extends the result of a vector boolean value from a
comment|/// vector of i1 to a wider type.  See getBooleanContents.
name|void
name|setBooleanVectorContents
parameter_list|(
name|BooleanContent
name|Ty
parameter_list|)
block|{
name|BooleanVectorContents
operator|=
name|Ty
expr_stmt|;
block|}
comment|/// Specify the target scheduling preference.
name|void
name|setSchedulingPreference
argument_list|(
name|Sched
operator|::
name|Preference
name|Pref
argument_list|)
block|{
name|SchedPreferenceInfo
operator|=
name|Pref
expr_stmt|;
block|}
comment|/// Indicate whether this target prefers to use _setjmp to implement
comment|/// llvm.setjmp or the version without _.  Defaults to false.
name|void
name|setUseUnderscoreSetJmp
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|UseUnderscoreSetJmp
operator|=
name|Val
expr_stmt|;
block|}
comment|/// Indicate whether this target prefers to use _longjmp to implement
comment|/// llvm.longjmp or the version without _.  Defaults to false.
name|void
name|setUseUnderscoreLongJmp
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|UseUnderscoreLongJmp
operator|=
name|Val
expr_stmt|;
block|}
comment|/// Indicate the minimum number of blocks to generate jump tables.
name|void
name|setMinimumJumpTableEntries
parameter_list|(
name|unsigned
name|Val
parameter_list|)
function_decl|;
comment|/// Indicate the maximum number of entries in jump tables.
comment|/// Set to zero to generate unlimited jump tables.
name|void
name|setMaximumJumpTableSize
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
comment|/// If set to a physical register, this specifies the register that
comment|/// llvm.savestack/llvm.restorestack should save and restore.
name|void
name|setStackPointerRegisterToSaveRestore
parameter_list|(
name|unsigned
name|R
parameter_list|)
block|{
name|StackPointerRegisterToSaveRestore
operator|=
name|R
expr_stmt|;
block|}
comment|/// Tells the code generator that the target has multiple (allocatable)
comment|/// condition registers that can be used to store the results of comparisons
comment|/// for use by selects and conditional branches. With multiple condition
comment|/// registers, the code generator will not aggressively sink comparisons into
comment|/// the blocks of their users.
name|void
name|setHasMultipleConditionRegisters
parameter_list|(
name|bool
name|hasManyRegs
init|=
name|true
parameter_list|)
block|{
name|HasMultipleConditionRegisters
operator|=
name|hasManyRegs
expr_stmt|;
block|}
comment|/// Tells the code generator that the target has BitExtract instructions.
comment|/// The code generator will aggressively sink "shift"s into the blocks of
comment|/// their users if the users will generate "and" instructions which can be
comment|/// combined with "shift" to BitExtract instructions.
name|void
name|setHasExtractBitsInsn
parameter_list|(
name|bool
name|hasExtractInsn
init|=
name|true
parameter_list|)
block|{
name|HasExtractBitsInsn
operator|=
name|hasExtractInsn
expr_stmt|;
block|}
comment|/// Tells the code generator not to expand logic operations on comparison
comment|/// predicates into separate sequences that increase the amount of flow
comment|/// control.
name|void
name|setJumpIsExpensive
parameter_list|(
name|bool
name|isExpensive
init|=
name|true
parameter_list|)
function_decl|;
comment|/// Tells the code generator that this target supports floating point
comment|/// exceptions and cares about preserving floating point exception behavior.
name|void
name|setHasFloatingPointExceptions
parameter_list|(
name|bool
name|FPExceptions
init|=
name|true
parameter_list|)
block|{
name|HasFloatingPointExceptions
operator|=
name|FPExceptions
expr_stmt|;
block|}
comment|/// Tells the code generator which bitwidths to bypass.
name|void
name|addBypassSlowDiv
parameter_list|(
name|unsigned
name|int
name|SlowBitWidth
parameter_list|,
name|unsigned
name|int
name|FastBitWidth
parameter_list|)
block|{
name|BypassSlowDivWidths
index|[
name|SlowBitWidth
index|]
operator|=
name|FastBitWidth
expr_stmt|;
block|}
comment|/// Add the specified register class as an available regclass for the
comment|/// specified value type. This indicates the selector can handle values of
comment|/// that class natively.
name|void
name|addRegisterClass
parameter_list|(
name|MVT
name|VT
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|)
block|{
name|assert
argument_list|(
operator|(
name|unsigned
operator|)
name|VT
operator|.
name|SimpleTy
operator|<
name|array_lengthof
argument_list|(
name|RegClassForVT
argument_list|)
argument_list|)
expr_stmt|;
name|RegClassForVT
index|[
name|VT
operator|.
name|SimpleTy
index|]
operator|=
name|RC
expr_stmt|;
block|}
comment|/// Return the largest legal super-reg register class of the register class
comment|/// for the specified type and its associated "cost".
name|virtual
name|std
operator|::
name|pair
operator|<
specifier|const
name|TargetRegisterClass
operator|*
operator|,
name|uint8_t
operator|>
name|findRepresentativeClass
argument_list|(
argument|const TargetRegisterInfo *TRI
argument_list|,
argument|MVT VT
argument_list|)
specifier|const
expr_stmt|;
comment|/// Once all of the register classes are added, this allows us to compute
comment|/// derived properties we expose.
name|void
name|computeRegisterProperties
parameter_list|(
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
parameter_list|)
function_decl|;
comment|/// Indicate that the specified operation does not work with the specified
comment|/// type and indicate what to do about it. Note that VT may refer to either
comment|/// the type of a result or that of an operand of Op.
name|void
name|setOperationAction
parameter_list|(
name|unsigned
name|Op
parameter_list|,
name|MVT
name|VT
parameter_list|,
name|LegalizeAction
name|Action
parameter_list|)
block|{
name|assert
argument_list|(
name|Op
operator|<
name|array_lengthof
argument_list|(
name|OpActions
index|[
literal|0
index|]
argument_list|)
operator|&&
literal|"Table isn't big enough!"
argument_list|)
expr_stmt|;
name|OpActions
index|[
operator|(
name|unsigned
operator|)
name|VT
operator|.
name|SimpleTy
index|]
index|[
name|Op
index|]
operator|=
name|Action
expr_stmt|;
block|}
comment|/// Indicate that the specified load with extension does not work with the
comment|/// specified type and indicate what to do about it.
name|void
name|setLoadExtAction
parameter_list|(
name|unsigned
name|ExtType
parameter_list|,
name|MVT
name|ValVT
parameter_list|,
name|MVT
name|MemVT
parameter_list|,
name|LegalizeAction
name|Action
parameter_list|)
block|{
name|assert
argument_list|(
name|ExtType
operator|<
name|ISD
operator|::
name|LAST_LOADEXT_TYPE
operator|&&
name|ValVT
operator|.
name|isValid
argument_list|()
operator|&&
name|MemVT
operator|.
name|isValid
argument_list|()
operator|&&
literal|"Table isn't big enough!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|unsigned
operator|)
name|Action
operator|<
literal|0x10
operator|&&
literal|"too many bits for bitfield array"
argument_list|)
expr_stmt|;
name|unsigned
name|Shift
init|=
literal|4
operator|*
name|ExtType
decl_stmt|;
name|LoadExtActions
index|[
name|ValVT
operator|.
name|SimpleTy
index|]
index|[
name|MemVT
operator|.
name|SimpleTy
index|]
operator|&=
operator|~
operator|(
operator|(
name|uint16_t
operator|)
literal|0xF
operator|<<
name|Shift
operator|)
expr_stmt|;
name|LoadExtActions
index|[
name|ValVT
operator|.
name|SimpleTy
index|]
index|[
name|MemVT
operator|.
name|SimpleTy
index|]
operator||=
operator|(
name|uint16_t
operator|)
name|Action
operator|<<
name|Shift
expr_stmt|;
block|}
comment|/// Indicate that the specified truncating store does not work with the
comment|/// specified type and indicate what to do about it.
name|void
name|setTruncStoreAction
parameter_list|(
name|MVT
name|ValVT
parameter_list|,
name|MVT
name|MemVT
parameter_list|,
name|LegalizeAction
name|Action
parameter_list|)
block|{
name|assert
argument_list|(
name|ValVT
operator|.
name|isValid
argument_list|()
operator|&&
name|MemVT
operator|.
name|isValid
argument_list|()
operator|&&
literal|"Table isn't big enough!"
argument_list|)
expr_stmt|;
name|TruncStoreActions
index|[
operator|(
name|unsigned
operator|)
name|ValVT
operator|.
name|SimpleTy
index|]
index|[
name|MemVT
operator|.
name|SimpleTy
index|]
operator|=
name|Action
expr_stmt|;
block|}
comment|/// Indicate that the specified indexed load does or does not work with the
comment|/// specified type and indicate what to do abort it.
comment|///
comment|/// NOTE: All indexed mode loads are initialized to Expand in
comment|/// TargetLowering.cpp
name|void
name|setIndexedLoadAction
parameter_list|(
name|unsigned
name|IdxMode
parameter_list|,
name|MVT
name|VT
parameter_list|,
name|LegalizeAction
name|Action
parameter_list|)
block|{
name|assert
argument_list|(
name|VT
operator|.
name|isValid
argument_list|()
operator|&&
name|IdxMode
operator|<
name|ISD
operator|::
name|LAST_INDEXED_MODE
operator|&&
operator|(
name|unsigned
operator|)
name|Action
operator|<
literal|0xf
operator|&&
literal|"Table isn't big enough!"
argument_list|)
expr_stmt|;
comment|// Load action are kept in the upper half.
name|IndexedModeActions
index|[
operator|(
name|unsigned
operator|)
name|VT
operator|.
name|SimpleTy
index|]
index|[
name|IdxMode
index|]
operator|&=
operator|~
literal|0xf0
expr_stmt|;
name|IndexedModeActions
index|[
operator|(
name|unsigned
operator|)
name|VT
operator|.
name|SimpleTy
index|]
index|[
name|IdxMode
index|]
operator||=
operator|(
operator|(
name|uint8_t
operator|)
name|Action
operator|)
operator|<<
literal|4
expr_stmt|;
block|}
comment|/// Indicate that the specified indexed store does or does not work with the
comment|/// specified type and indicate what to do about it.
comment|///
comment|/// NOTE: All indexed mode stores are initialized to Expand in
comment|/// TargetLowering.cpp
name|void
name|setIndexedStoreAction
parameter_list|(
name|unsigned
name|IdxMode
parameter_list|,
name|MVT
name|VT
parameter_list|,
name|LegalizeAction
name|Action
parameter_list|)
block|{
name|assert
argument_list|(
name|VT
operator|.
name|isValid
argument_list|()
operator|&&
name|IdxMode
operator|<
name|ISD
operator|::
name|LAST_INDEXED_MODE
operator|&&
operator|(
name|unsigned
operator|)
name|Action
operator|<
literal|0xf
operator|&&
literal|"Table isn't big enough!"
argument_list|)
expr_stmt|;
comment|// Store action are kept in the lower half.
name|IndexedModeActions
index|[
operator|(
name|unsigned
operator|)
name|VT
operator|.
name|SimpleTy
index|]
index|[
name|IdxMode
index|]
operator|&=
operator|~
literal|0x0f
expr_stmt|;
name|IndexedModeActions
index|[
operator|(
name|unsigned
operator|)
name|VT
operator|.
name|SimpleTy
index|]
index|[
name|IdxMode
index|]
operator||=
operator|(
operator|(
name|uint8_t
operator|)
name|Action
operator|)
expr_stmt|;
block|}
comment|/// Indicate that the specified condition code is or isn't supported on the
comment|/// target and indicate what to do about it.
name|void
name|setCondCodeAction
argument_list|(
name|ISD
operator|::
name|CondCode
name|CC
argument_list|,
name|MVT
name|VT
argument_list|,
name|LegalizeAction
name|Action
argument_list|)
block|{
name|assert
argument_list|(
name|VT
operator|.
name|isValid
argument_list|()
operator|&&
operator|(
name|unsigned
operator|)
name|CC
operator|<
name|array_lengthof
argument_list|(
name|CondCodeActions
argument_list|)
operator|&&
literal|"Table isn't big enough!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|unsigned
operator|)
name|Action
operator|<
literal|0x10
operator|&&
literal|"too many bits for bitfield array"
argument_list|)
expr_stmt|;
comment|/// The lower 3 bits of the SimpleTy index into Nth 4bit set from the 32-bit
comment|/// value and the upper 29 bits index into the second dimension of the array
comment|/// to select what 32-bit value to use.
name|uint32_t
name|Shift
init|=
literal|4
operator|*
operator|(
name|VT
operator|.
name|SimpleTy
operator|&
literal|0x7
operator|)
decl_stmt|;
name|CondCodeActions
index|[
name|CC
index|]
index|[
name|VT
operator|.
name|SimpleTy
operator|>>
literal|3
index|]
operator|&=
operator|~
operator|(
operator|(
name|uint32_t
operator|)
literal|0xF
operator|<<
name|Shift
operator|)
expr_stmt|;
name|CondCodeActions
index|[
name|CC
index|]
index|[
name|VT
operator|.
name|SimpleTy
operator|>>
literal|3
index|]
operator||=
operator|(
name|uint32_t
operator|)
name|Action
operator|<<
name|Shift
expr_stmt|;
block|}
comment|/// If Opc/OrigVT is specified as being promoted, the promotion code defaults
comment|/// to trying a larger integer/fp until it can find one that works. If that
comment|/// default is insufficient, this method can be used by the target to override
comment|/// the default.
name|void
name|AddPromotedToType
parameter_list|(
name|unsigned
name|Opc
parameter_list|,
name|MVT
name|OrigVT
parameter_list|,
name|MVT
name|DestVT
parameter_list|)
block|{
name|PromoteToType
index|[
name|std
operator|::
name|make_pair
argument_list|(
name|Opc
argument_list|,
name|OrigVT
operator|.
name|SimpleTy
argument_list|)
index|]
operator|=
name|DestVT
operator|.
name|SimpleTy
expr_stmt|;
block|}
comment|/// Convenience method to set an operation to Promote and specify the type
comment|/// in a single call.
name|void
name|setOperationPromotedToType
parameter_list|(
name|unsigned
name|Opc
parameter_list|,
name|MVT
name|OrigVT
parameter_list|,
name|MVT
name|DestVT
parameter_list|)
block|{
name|setOperationAction
argument_list|(
name|Opc
argument_list|,
name|OrigVT
argument_list|,
name|Promote
argument_list|)
expr_stmt|;
name|AddPromotedToType
argument_list|(
name|Opc
argument_list|,
name|OrigVT
argument_list|,
name|DestVT
argument_list|)
expr_stmt|;
block|}
comment|/// Targets should invoke this method for each target independent node that
comment|/// they want to provide a custom DAG combiner for by implementing the
comment|/// PerformDAGCombine virtual method.
name|void
name|setTargetDAGCombine
argument_list|(
name|ISD
operator|::
name|NodeType
name|NT
argument_list|)
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|NT
operator|>>
literal|3
argument_list|)
operator|<
name|array_lengthof
argument_list|(
name|TargetDAGCombineArray
argument_list|)
argument_list|)
expr_stmt|;
name|TargetDAGCombineArray
index|[
name|NT
operator|>>
literal|3
index|]
operator||=
literal|1
operator|<<
operator|(
name|NT
operator|&
literal|7
operator|)
expr_stmt|;
block|}
comment|/// Set the target's required jmp_buf buffer size (in bytes); default is 200
name|void
name|setJumpBufSize
parameter_list|(
name|unsigned
name|Size
parameter_list|)
block|{
name|JumpBufSize
operator|=
name|Size
expr_stmt|;
block|}
comment|/// Set the target's required jmp_buf buffer alignment (in bytes); default is
comment|/// 0
name|void
name|setJumpBufAlignment
parameter_list|(
name|unsigned
name|Align
parameter_list|)
block|{
name|JumpBufAlignment
operator|=
name|Align
expr_stmt|;
block|}
comment|/// Set the target's minimum function alignment (in log2(bytes))
name|void
name|setMinFunctionAlignment
parameter_list|(
name|unsigned
name|Align
parameter_list|)
block|{
name|MinFunctionAlignment
operator|=
name|Align
expr_stmt|;
block|}
comment|/// Set the target's preferred function alignment.  This should be set if
comment|/// there is a performance benefit to higher-than-minimum alignment (in
comment|/// log2(bytes))
name|void
name|setPrefFunctionAlignment
parameter_list|(
name|unsigned
name|Align
parameter_list|)
block|{
name|PrefFunctionAlignment
operator|=
name|Align
expr_stmt|;
block|}
comment|/// Set the target's preferred loop alignment. Default alignment is zero, it
comment|/// means the target does not care about loop alignment.  The alignment is
comment|/// specified in log2(bytes). The target may also override
comment|/// getPrefLoopAlignment to provide per-loop values.
name|void
name|setPrefLoopAlignment
parameter_list|(
name|unsigned
name|Align
parameter_list|)
block|{
name|PrefLoopAlignment
operator|=
name|Align
expr_stmt|;
block|}
comment|/// Set the minimum stack alignment of an argument (in log2(bytes)).
name|void
name|setMinStackArgumentAlignment
parameter_list|(
name|unsigned
name|Align
parameter_list|)
block|{
name|MinStackArgumentAlignment
operator|=
name|Align
expr_stmt|;
block|}
comment|/// Set the maximum atomic operation size supported by the
comment|/// backend. Atomic operations greater than this size (as well as
comment|/// ones that are not naturally aligned), will be expanded by
comment|/// AtomicExpandPass into an __atomic_* library call.
name|void
name|setMaxAtomicSizeInBitsSupported
parameter_list|(
name|unsigned
name|SizeInBits
parameter_list|)
block|{
name|MaxAtomicSizeInBitsSupported
operator|=
name|SizeInBits
expr_stmt|;
block|}
comment|// Sets the minimum cmpxchg or ll/sc size supported by the backend.
name|void
name|setMinCmpXchgSizeInBits
parameter_list|(
name|unsigned
name|SizeInBits
parameter_list|)
block|{
name|MinCmpXchgSizeInBits
operator|=
name|SizeInBits
expr_stmt|;
block|}
name|public
label|:
comment|//===--------------------------------------------------------------------===//
comment|// Addressing mode description hooks (used by LSR etc).
comment|//
comment|/// CodeGenPrepare sinks address calculations into the same BB as Load/Store
comment|/// instructions reading the address. This allows as much computation as
comment|/// possible to be done in the address mode for that operand. This hook lets
comment|/// targets also pass back when this should be done on intrinsics which
comment|/// load/store.
name|virtual
name|bool
name|getAddrModeArguments
argument_list|(
name|IntrinsicInst
operator|*
comment|/*I*/
argument_list|,
name|SmallVectorImpl
operator|<
name|Value
operator|*
operator|>
operator|&
comment|/*Ops*/
argument_list|,
name|Type
operator|*
operator|&
comment|/*AccessTy*/
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// This represents an addressing mode of:
comment|///    BaseGV + BaseOffs + BaseReg + Scale*ScaleReg
comment|/// If BaseGV is null,  there is no BaseGV.
comment|/// If BaseOffs is zero, there is no base offset.
comment|/// If HasBaseReg is false, there is no base register.
comment|/// If Scale is zero, there is no ScaleReg.  Scale of 1 indicates a reg with
comment|/// no scale.
struct|struct
name|AddrMode
block|{
name|GlobalValue
modifier|*
name|BaseGV
init|=
name|nullptr
decl_stmt|;
name|int64_t
name|BaseOffs
init|=
literal|0
decl_stmt|;
name|bool
name|HasBaseReg
init|=
name|false
decl_stmt|;
name|int64_t
name|Scale
init|=
literal|0
decl_stmt|;
name|AddrMode
argument_list|()
operator|=
expr|default
expr_stmt|;
block|}
struct|;
comment|/// Return true if the addressing mode represented by AM is legal for this
comment|/// target, for a load/store of the specified type.
comment|///
comment|/// The type may be VoidTy, in which case only return true if the addressing
comment|/// mode is legal for a load/store of any legal type.  TODO: Handle
comment|/// pre/postinc as well.
comment|///
comment|/// If the address space cannot be determined, it will be -1.
comment|///
comment|/// TODO: Remove default argument
name|virtual
name|bool
name|isLegalAddressingMode
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
specifier|const
name|AddrMode
operator|&
name|AM
argument_list|,
name|Type
operator|*
name|Ty
argument_list|,
name|unsigned
name|AddrSpace
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return the cost of the scaling factor used in the addressing mode
comment|/// represented by AM for this target, for a load/store of the specified type.
comment|///
comment|/// If the AM is supported, the return value must be>= 0.
comment|/// If the AM is not supported, it returns a negative value.
comment|/// TODO: Handle pre/postinc as well.
comment|/// TODO: Remove default argument
name|virtual
name|int
name|getScalingFactorCost
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
specifier|const
name|AddrMode
operator|&
name|AM
argument_list|,
name|Type
operator|*
name|Ty
argument_list|,
name|unsigned
name|AS
operator|=
literal|0
argument_list|)
decl|const
block|{
comment|// Default: assume that any scaling factor used in a legal AM is free.
if|if
condition|(
name|isLegalAddressingMode
argument_list|(
name|DL
argument_list|,
name|AM
argument_list|,
name|Ty
argument_list|,
name|AS
argument_list|)
condition|)
return|return
literal|0
return|;
return|return
operator|-
literal|1
return|;
block|}
name|virtual
name|bool
name|isFoldableMemAccessOffset
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
name|int64_t
name|Offset
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
comment|/// Return true if the specified immediate is legal icmp immediate, that is
comment|/// the target has icmp instructions which can compare a register against the
comment|/// immediate without having to materialize the immediate into a register.
name|virtual
name|bool
name|isLegalICmpImmediate
argument_list|(
name|int64_t
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
comment|/// Return true if the specified immediate is legal add immediate, that is the
comment|/// target has add instructions which can add a register with the immediate
comment|/// without having to materialize the immediate into a register.
name|virtual
name|bool
name|isLegalAddImmediate
argument_list|(
name|int64_t
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
comment|/// Return true if it's significantly cheaper to shift a vector by a uniform
comment|/// scalar than by an amount which will vary across each lane. On x86, for
comment|/// example, there is a "psllw" instruction for the former case, but no simple
comment|/// instruction for a general "a<< b" operation on vectors.
name|virtual
name|bool
name|isVectorShiftByScalarCheap
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return true if it's free to truncate a value of type FromTy to type
comment|/// ToTy. e.g. On x86 it's free to truncate a i32 value in register EAX to i16
comment|/// by referencing its sub-register AX.
comment|/// Targets must return false when FromTy<= ToTy.
name|virtual
name|bool
name|isTruncateFree
argument_list|(
name|Type
operator|*
name|FromTy
argument_list|,
name|Type
operator|*
name|ToTy
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return true if a truncation from FromTy to ToTy is permitted when deciding
comment|/// whether a call is in tail position. Typically this means that both results
comment|/// would be assigned to the same register or stack slot, but it could mean
comment|/// the target performs adequate checks of its own before proceeding with the
comment|/// tail call.  Targets must return false when FromTy<= ToTy.
name|virtual
name|bool
name|allowTruncateForTailCall
argument_list|(
name|Type
operator|*
name|FromTy
argument_list|,
name|Type
operator|*
name|ToTy
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isTruncateFree
argument_list|(
name|EVT
name|FromVT
argument_list|,
name|EVT
name|ToVT
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isProfitableToHoist
argument_list|(
name|Instruction
operator|*
name|I
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
comment|/// Return true if the extension represented by \p I is free.
comment|/// Unlikely the is[Z|FP]ExtFree family which is based on types,
comment|/// this method can use the context provided by \p I to decide
comment|/// whether or not \p I is free.
comment|/// This method extends the behavior of the is[Z|FP]ExtFree family.
comment|/// In other words, if is[Z|FP]Free returns true, then this method
comment|/// returns true as well. The converse is not true.
comment|/// The target can perform the adequate checks by overriding isExtFreeImpl.
comment|/// \pre \p I must be a sign, zero, or fp extension.
name|bool
name|isExtFree
argument_list|(
specifier|const
name|Instruction
operator|*
name|I
argument_list|)
decl|const
block|{
switch|switch
condition|(
name|I
operator|->
name|getOpcode
argument_list|()
condition|)
block|{
case|case
name|Instruction
operator|::
name|FPExt
case|:
if|if
condition|(
name|isFPExtFree
argument_list|(
name|EVT
operator|::
name|getEVT
argument_list|(
name|I
operator|->
name|getType
argument_list|()
argument_list|)
argument_list|)
condition|)
return|return
name|true
return|;
break|break;
case|case
name|Instruction
operator|::
name|ZExt
case|:
if|if
condition|(
name|isZExtFree
argument_list|(
name|I
operator|->
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|->
name|getType
argument_list|()
argument_list|,
name|I
operator|->
name|getType
argument_list|()
argument_list|)
condition|)
return|return
name|true
return|;
break|break;
case|case
name|Instruction
operator|::
name|SExt
case|:
break|break;
default|default:
name|llvm_unreachable
argument_list|(
literal|"Instruction is not an extension"
argument_list|)
expr_stmt|;
block|}
return|return
name|isExtFreeImpl
argument_list|(
name|I
argument_list|)
return|;
block|}
comment|/// Return true if any actual instruction that defines a value of type FromTy
comment|/// implicitly zero-extends the value to ToTy in the result register.
comment|///
comment|/// The function should return true when it is likely that the truncate can
comment|/// be freely folded with an instruction defining a value of FromTy. If
comment|/// the defining instruction is unknown (because you're looking at a
comment|/// function argument, PHI, etc.) then the target may require an
comment|/// explicit truncate, which is not necessarily free, but this function
comment|/// does not deal with those cases.
comment|/// Targets must return false when FromTy>= ToTy.
name|virtual
name|bool
name|isZExtFree
argument_list|(
name|Type
operator|*
name|FromTy
argument_list|,
name|Type
operator|*
name|ToTy
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isZExtFree
argument_list|(
name|EVT
name|FromTy
argument_list|,
name|EVT
name|ToTy
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return true if the target supplies and combines to a paired load
comment|/// two loaded values of type LoadedType next to each other in memory.
comment|/// RequiredAlignment gives the minimal alignment constraints that must be met
comment|/// to be able to select this paired load.
comment|///
comment|/// This information is *not* used to generate actual paired loads, but it is
comment|/// used to generate a sequence of loads that is easier to combine into a
comment|/// paired load.
comment|/// For instance, something like this:
comment|/// a = load i64* addr
comment|/// b = trunc i64 a to i32
comment|/// c = lshr i64 a, 32
comment|/// d = trunc i64 c to i32
comment|/// will be optimized into:
comment|/// b = load i32* addr1
comment|/// d = load i32* addr2
comment|/// Where addr1 = addr2 +/- sizeof(i32).
comment|///
comment|/// In other words, unless the target performs a post-isel load combining,
comment|/// this information should not be provided because it will generate more
comment|/// loads.
name|virtual
name|bool
name|hasPairedLoad
argument_list|(
name|EVT
comment|/*LoadedType*/
argument_list|,
name|unsigned
operator|&
comment|/*RequiredAligment*/
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Get the maximum supported factor for interleaved memory accesses.
comment|/// Default to be the minimum interleave factor: 2.
name|virtual
name|unsigned
name|getMaxSupportedInterleaveFactor
argument_list|()
specifier|const
block|{
return|return
literal|2
return|;
block|}
comment|/// \brief Lower an interleaved load to target specific intrinsics. Return
comment|/// true on success.
comment|///
comment|/// \p LI is the vector load instruction.
comment|/// \p Shuffles is the shufflevector list to DE-interleave the loaded vector.
comment|/// \p Indices is the corresponding indices for each shufflevector.
comment|/// \p Factor is the interleave factor.
name|virtual
name|bool
name|lowerInterleavedLoad
argument_list|(
name|LoadInst
operator|*
name|LI
argument_list|,
name|ArrayRef
operator|<
name|ShuffleVectorInst
operator|*
operator|>
name|Shuffles
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Indices
argument_list|,
name|unsigned
name|Factor
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Lower an interleaved store to target specific intrinsics. Return
comment|/// true on success.
comment|///
comment|/// \p SI is the vector store instruction.
comment|/// \p SVI is the shufflevector to RE-interleave the stored vector.
comment|/// \p Factor is the interleave factor.
name|virtual
name|bool
name|lowerInterleavedStore
argument_list|(
name|StoreInst
operator|*
name|SI
argument_list|,
name|ShuffleVectorInst
operator|*
name|SVI
argument_list|,
name|unsigned
name|Factor
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return true if zero-extending the specific node Val to type VT2 is free
comment|/// (either because it's implicitly zero-extended such as ARM ldrb / ldrh or
comment|/// because it's folded such as X86 zero-extending loads).
name|virtual
name|bool
name|isZExtFree
argument_list|(
name|SDValue
name|Val
argument_list|,
name|EVT
name|VT2
argument_list|)
decl|const
block|{
return|return
name|isZExtFree
argument_list|(
name|Val
operator|.
name|getValueType
argument_list|()
argument_list|,
name|VT2
argument_list|)
return|;
block|}
comment|/// Return true if an fpext operation is free (for instance, because
comment|/// single-precision floating-point numbers are implicitly extended to
comment|/// double-precision).
name|virtual
name|bool
name|isFPExtFree
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|VT
operator|.
name|isFloatingPoint
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
comment|/// Return true if folding a vector load into ExtVal (a sign, zero, or any
comment|/// extend node) is profitable.
name|virtual
name|bool
name|isVectorLoadExtDesirable
argument_list|(
name|SDValue
name|ExtVal
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return true if an fneg operation is free to the point where it is never
comment|/// worthwhile to replace it with a bitwise operation.
name|virtual
name|bool
name|isFNegFree
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|VT
operator|.
name|isFloatingPoint
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
comment|/// Return true if an fabs operation is free to the point where it is never
comment|/// worthwhile to replace it with a bitwise operation.
name|virtual
name|bool
name|isFAbsFree
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|VT
operator|.
name|isFloatingPoint
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
comment|/// Return true if an FMA operation is faster than a pair of fmul and fadd
comment|/// instructions. fmuladd intrinsics will be expanded to FMAs when this method
comment|/// returns true, otherwise fmuladd is expanded to fmul + fadd.
comment|///
comment|/// NOTE: This may be called before legalization on types for which FMAs are
comment|/// not legal, but should return true if those types will eventually legalize
comment|/// to types that support FMAs. After legalization, it will only be called on
comment|/// types that support FMAs (via Legal or Custom actions)
name|virtual
name|bool
name|isFMAFasterThanFMulAndFAdd
argument_list|(
name|EVT
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return true if it's profitable to narrow operations of type VT1 to
comment|/// VT2. e.g. on x86, it's profitable to narrow from i32 to i8 but not from
comment|/// i32 to i16.
name|virtual
name|bool
name|isNarrowingProfitable
argument_list|(
name|EVT
comment|/*VT1*/
argument_list|,
name|EVT
comment|/*VT2*/
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Return true if it is beneficial to convert a load of a constant to
comment|/// just the constant itself.
comment|/// On some targets it might be more efficient to use a combination of
comment|/// arithmetic instructions to materialize the constant instead of loading it
comment|/// from a constant pool.
name|virtual
name|bool
name|shouldConvertConstantLoadToIntImm
argument_list|(
specifier|const
name|APInt
operator|&
name|Imm
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return true if EXTRACT_SUBVECTOR is cheap for this result type
comment|/// with this index. This is needed because EXTRACT_SUBVECTOR usually
comment|/// has custom lowering that depends on the index of the first element,
comment|/// and only the target knows which lowering is cheap.
name|virtual
name|bool
name|isExtractSubvectorCheap
argument_list|(
name|EVT
name|ResVT
argument_list|,
name|unsigned
name|Index
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|// Return true if it is profitable to use a scalar input to a BUILD_VECTOR
comment|// even if the vector itself has multiple uses.
name|virtual
name|bool
name|aggressivelyPreferBuildVectorSources
argument_list|(
name|EVT
name|VecVT
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Runtime Library hooks
comment|//
comment|/// Rename the default libcall routine name for the specified libcall.
name|void
name|setLibcallName
argument_list|(
name|RTLIB
operator|::
name|Libcall
name|Call
argument_list|,
specifier|const
name|char
operator|*
name|Name
argument_list|)
block|{
name|LibcallRoutineNames
index|[
name|Call
index|]
operator|=
name|Name
expr_stmt|;
block|}
comment|/// Get the libcall routine name for the specified libcall.
specifier|const
name|char
modifier|*
name|getLibcallName
argument_list|(
name|RTLIB
operator|::
name|Libcall
name|Call
argument_list|)
decl|const
block|{
return|return
name|LibcallRoutineNames
index|[
name|Call
index|]
return|;
block|}
comment|/// Override the default CondCode to be used to test the result of the
comment|/// comparison libcall against zero.
name|void
name|setCmpLibcallCC
argument_list|(
name|RTLIB
operator|::
name|Libcall
name|Call
argument_list|,
name|ISD
operator|::
name|CondCode
name|CC
argument_list|)
block|{
name|CmpLibcallCCs
index|[
name|Call
index|]
operator|=
name|CC
expr_stmt|;
block|}
comment|/// Get the CondCode that's to be used to test the result of the comparison
comment|/// libcall against zero.
name|ISD
operator|::
name|CondCode
name|getCmpLibcallCC
argument_list|(
argument|RTLIB::Libcall Call
argument_list|)
specifier|const
block|{
return|return
name|CmpLibcallCCs
index|[
name|Call
index|]
return|;
block|}
comment|/// Set the CallingConv that should be used for the specified libcall.
name|void
name|setLibcallCallingConv
argument_list|(
name|RTLIB
operator|::
name|Libcall
name|Call
argument_list|,
name|CallingConv
operator|::
name|ID
name|CC
argument_list|)
block|{
name|LibcallCallingConvs
index|[
name|Call
index|]
operator|=
name|CC
expr_stmt|;
block|}
comment|/// Get the CallingConv that should be used for the specified libcall.
name|CallingConv
operator|::
name|ID
name|getLibcallCallingConv
argument_list|(
argument|RTLIB::Libcall Call
argument_list|)
specifier|const
block|{
return|return
name|LibcallCallingConvs
index|[
name|Call
index|]
return|;
block|}
comment|/// Execute target specific actions to finalize target lowering.
comment|/// This is used to set extra flags in MachineFrameInformation and freezing
comment|/// the set of reserved registers.
comment|/// The default implementation just freezes the set of reserved registers.
name|virtual
name|void
name|finalizeLowering
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
specifier|const
name|TargetMachine
modifier|&
name|TM
decl_stmt|;
comment|/// Tells the code generator that the target has multiple (allocatable)
comment|/// condition registers that can be used to store the results of comparisons
comment|/// for use by selects and conditional branches. With multiple condition
comment|/// registers, the code generator will not aggressively sink comparisons into
comment|/// the blocks of their users.
name|bool
name|HasMultipleConditionRegisters
decl_stmt|;
comment|/// Tells the code generator that the target has BitExtract instructions.
comment|/// The code generator will aggressively sink "shift"s into the blocks of
comment|/// their users if the users will generate "and" instructions which can be
comment|/// combined with "shift" to BitExtract instructions.
name|bool
name|HasExtractBitsInsn
decl_stmt|;
comment|/// Tells the code generator to bypass slow divide or remainder
comment|/// instructions. For example, BypassSlowDivWidths[32,8] tells the code
comment|/// generator to bypass 32-bit integer div/rem with an 8-bit unsigned integer
comment|/// div/rem when the operands are positive and less than 256.
name|DenseMap
operator|<
name|unsigned
name|int
operator|,
name|unsigned
name|int
operator|>
name|BypassSlowDivWidths
expr_stmt|;
comment|/// Tells the code generator that it shouldn't generate extra flow control
comment|/// instructions and should attempt to combine flow control instructions via
comment|/// predication.
name|bool
name|JumpIsExpensive
decl_stmt|;
comment|/// Whether the target supports or cares about preserving floating point
comment|/// exception behavior.
name|bool
name|HasFloatingPointExceptions
decl_stmt|;
comment|/// This target prefers to use _setjmp to implement llvm.setjmp.
comment|///
comment|/// Defaults to false.
name|bool
name|UseUnderscoreSetJmp
decl_stmt|;
comment|/// This target prefers to use _longjmp to implement llvm.longjmp.
comment|///
comment|/// Defaults to false.
name|bool
name|UseUnderscoreLongJmp
decl_stmt|;
comment|/// Information about the contents of the high-bits in boolean values held in
comment|/// a type wider than i1. See getBooleanContents.
name|BooleanContent
name|BooleanContents
decl_stmt|;
comment|/// Information about the contents of the high-bits in boolean values held in
comment|/// a type wider than i1. See getBooleanContents.
name|BooleanContent
name|BooleanFloatContents
decl_stmt|;
comment|/// Information about the contents of the high-bits in boolean vector values
comment|/// when the element type is wider than i1. See getBooleanContents.
name|BooleanContent
name|BooleanVectorContents
decl_stmt|;
comment|/// The target scheduling preference: shortest possible total cycles or lowest
comment|/// register usage.
name|Sched
operator|::
name|Preference
name|SchedPreferenceInfo
expr_stmt|;
comment|/// The size, in bytes, of the target's jmp_buf buffers
name|unsigned
name|JumpBufSize
decl_stmt|;
comment|/// The alignment, in bytes, of the target's jmp_buf buffers
name|unsigned
name|JumpBufAlignment
decl_stmt|;
comment|/// The minimum alignment that any argument on the stack needs to have.
name|unsigned
name|MinStackArgumentAlignment
decl_stmt|;
comment|/// The minimum function alignment (used when optimizing for size, and to
comment|/// prevent explicitly provided alignment from leading to incorrect code).
name|unsigned
name|MinFunctionAlignment
decl_stmt|;
comment|/// The preferred function alignment (used when alignment unspecified and
comment|/// optimizing for speed).
name|unsigned
name|PrefFunctionAlignment
decl_stmt|;
comment|/// The preferred loop alignment.
name|unsigned
name|PrefLoopAlignment
decl_stmt|;
comment|/// Size in bits of the maximum atomics size the backend supports.
comment|/// Accesses larger than this will be expanded by AtomicExpandPass.
name|unsigned
name|MaxAtomicSizeInBitsSupported
decl_stmt|;
comment|/// Size in bits of the minimum cmpxchg or ll/sc operation the
comment|/// backend supports.
name|unsigned
name|MinCmpXchgSizeInBits
decl_stmt|;
comment|/// If set to a physical register, this specifies the register that
comment|/// llvm.savestack/llvm.restorestack should save and restore.
name|unsigned
name|StackPointerRegisterToSaveRestore
decl_stmt|;
comment|/// This indicates the default register class to use for each ValueType the
comment|/// target supports natively.
specifier|const
name|TargetRegisterClass
modifier|*
name|RegClassForVT
index|[
name|MVT
operator|::
name|LAST_VALUETYPE
index|]
decl_stmt|;
name|unsigned
name|char
name|NumRegistersForVT
index|[
name|MVT
operator|::
name|LAST_VALUETYPE
index|]
decl_stmt|;
name|MVT
name|RegisterTypeForVT
index|[
name|MVT
operator|::
name|LAST_VALUETYPE
index|]
decl_stmt|;
comment|/// This indicates the "representative" register class to use for each
comment|/// ValueType the target supports natively. This information is used by the
comment|/// scheduler to track register pressure. By default, the representative
comment|/// register class is the largest legal super-reg register class of the
comment|/// register class of the specified type. e.g. On x86, i8, i16, and i32's
comment|/// representative class would be GR32.
specifier|const
name|TargetRegisterClass
modifier|*
name|RepRegClassForVT
index|[
name|MVT
operator|::
name|LAST_VALUETYPE
index|]
decl_stmt|;
comment|/// This indicates the "cost" of the "representative" register class for each
comment|/// ValueType. The cost is used by the scheduler to approximate register
comment|/// pressure.
name|uint8_t
name|RepRegClassCostForVT
index|[
name|MVT
operator|::
name|LAST_VALUETYPE
index|]
decl_stmt|;
comment|/// For any value types we are promoting or expanding, this contains the value
comment|/// type that we are changing to.  For Expanded types, this contains one step
comment|/// of the expand (e.g. i64 -> i32), even if there are multiple steps required
comment|/// (e.g. i64 -> i16).  For types natively supported by the system, this holds
comment|/// the same type (e.g. i32 -> i32).
name|MVT
name|TransformToType
index|[
name|MVT
operator|::
name|LAST_VALUETYPE
index|]
decl_stmt|;
comment|/// For each operation and each value type, keep a LegalizeAction that
comment|/// indicates how instruction selection should deal with the operation.  Most
comment|/// operations are Legal (aka, supported natively by the target), but
comment|/// operations that are not should be described.  Note that operations on
comment|/// non-legal value types are not described here.
name|LegalizeAction
name|OpActions
index|[
name|MVT
operator|::
name|LAST_VALUETYPE
index|]
index|[
name|ISD
operator|::
name|BUILTIN_OP_END
index|]
decl_stmt|;
comment|/// For each load extension type and each value type, keep a LegalizeAction
comment|/// that indicates how instruction selection should deal with a load of a
comment|/// specific value type and extension type. Uses 4-bits to store the action
comment|/// for each of the 4 load ext types.
name|uint16_t
name|LoadExtActions
index|[
name|MVT
operator|::
name|LAST_VALUETYPE
index|]
index|[
name|MVT
operator|::
name|LAST_VALUETYPE
index|]
decl_stmt|;
comment|/// For each value type pair keep a LegalizeAction that indicates whether a
comment|/// truncating store of a specific value type and truncating type is legal.
name|LegalizeAction
name|TruncStoreActions
index|[
name|MVT
operator|::
name|LAST_VALUETYPE
index|]
index|[
name|MVT
operator|::
name|LAST_VALUETYPE
index|]
decl_stmt|;
comment|/// For each indexed mode and each value type, keep a pair of LegalizeAction
comment|/// that indicates how instruction selection should deal with the load /
comment|/// store.
comment|///
comment|/// The first dimension is the value_type for the reference. The second
comment|/// dimension represents the various modes for load store.
name|uint8_t
name|IndexedModeActions
index|[
name|MVT
operator|::
name|LAST_VALUETYPE
index|]
index|[
name|ISD
operator|::
name|LAST_INDEXED_MODE
index|]
decl_stmt|;
comment|/// For each condition code (ISD::CondCode) keep a LegalizeAction that
comment|/// indicates how instruction selection should deal with the condition code.
comment|///
comment|/// Because each CC action takes up 4 bits, we need to have the array size be
comment|/// large enough to fit all of the value types. This can be done by rounding
comment|/// up the MVT::LAST_VALUETYPE value to the next multiple of 8.
name|uint32_t
name|CondCodeActions
index|[
name|ISD
operator|::
name|SETCC_INVALID
index|]
index|[
operator|(
name|MVT
operator|::
name|LAST_VALUETYPE
operator|+
literal|7
operator|)
operator|/
literal|8
index|]
decl_stmt|;
name|protected
label|:
name|ValueTypeActionImpl
name|ValueTypeActions
decl_stmt|;
name|private
label|:
name|LegalizeKind
name|getTypeConversion
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
decl_stmt|;
comment|/// Targets can specify ISD nodes that they would like PerformDAGCombine
comment|/// callbacks for by calling setTargetDAGCombine(), which sets a bit in this
comment|/// array.
name|unsigned
name|char
name|TargetDAGCombineArray
index|[
operator|(
name|ISD
operator|::
name|BUILTIN_OP_END
operator|+
name|CHAR_BIT
operator|-
literal|1
operator|)
operator|/
name|CHAR_BIT
index|]
decl_stmt|;
comment|/// For operations that must be promoted to a specific type, this holds the
comment|/// destination type.  This map should be sparse, so don't hold it as an
comment|/// array.
comment|///
comment|/// Targets add entries to this map with AddPromotedToType(..), clients access
comment|/// this with getTypeToPromoteTo(..).
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|MVT
operator|::
name|SimpleValueType
operator|>
operator|,
name|MVT
operator|::
name|SimpleValueType
operator|>
name|PromoteToType
expr_stmt|;
comment|/// Stores the name each libcall.
specifier|const
name|char
modifier|*
name|LibcallRoutineNames
index|[
name|RTLIB
operator|::
name|UNKNOWN_LIBCALL
index|]
decl_stmt|;
comment|/// The ISD::CondCode that should be used to test the result of each of the
comment|/// comparison libcall against zero.
name|ISD
operator|::
name|CondCode
name|CmpLibcallCCs
index|[
name|RTLIB
operator|::
name|UNKNOWN_LIBCALL
index|]
expr_stmt|;
comment|/// Stores the CallingConv that should be used for each libcall.
name|CallingConv
operator|::
name|ID
name|LibcallCallingConvs
index|[
name|RTLIB
operator|::
name|UNKNOWN_LIBCALL
index|]
expr_stmt|;
name|protected
label|:
comment|/// Return true if the extension represented by \p I is free.
comment|/// \pre \p I is a sign, zero, or fp extension and
comment|///      is[Z|FP]ExtFree of the related types is not true.
name|virtual
name|bool
name|isExtFreeImpl
argument_list|(
specifier|const
name|Instruction
operator|*
name|I
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Depth that GatherAllAliases should should continue looking for chain
comment|/// dependencies when trying to find a more preferable chain. As an
comment|/// approximation, this should be more than the number of consecutive stores
comment|/// expected to be merged.
name|unsigned
name|GatherAllAliasesMaxDepth
decl_stmt|;
comment|/// \brief Specify maximum number of store instructions per memset call.
comment|///
comment|/// When lowering \@llvm.memset this field specifies the maximum number of
comment|/// store operations that may be substituted for the call to memset. Targets
comment|/// must set this value based on the cost threshold for that target. Targets
comment|/// should assume that the memset will be done using as many of the largest
comment|/// store operations first, followed by smaller ones, if necessary, per
comment|/// alignment restrictions. For example, storing 9 bytes on a 32-bit machine
comment|/// with 16-bit alignment would result in four 2-byte stores and one 1-byte
comment|/// store.  This only applies to setting a constant array of a constant size.
name|unsigned
name|MaxStoresPerMemset
decl_stmt|;
comment|/// Maximum number of stores operations that may be substituted for the call
comment|/// to memset, used for functions with OptSize attribute.
name|unsigned
name|MaxStoresPerMemsetOptSize
decl_stmt|;
comment|/// \brief Specify maximum bytes of store instructions per memcpy call.
comment|///
comment|/// When lowering \@llvm.memcpy this field specifies the maximum number of
comment|/// store operations that may be substituted for a call to memcpy. Targets
comment|/// must set this value based on the cost threshold for that target. Targets
comment|/// should assume that the memcpy will be done using as many of the largest
comment|/// store operations first, followed by smaller ones, if necessary, per
comment|/// alignment restrictions. For example, storing 7 bytes on a 32-bit machine
comment|/// with 32-bit alignment would result in one 4-byte store, a one 2-byte store
comment|/// and one 1-byte store. This only applies to copying a constant array of
comment|/// constant size.
name|unsigned
name|MaxStoresPerMemcpy
decl_stmt|;
comment|/// Maximum number of store operations that may be substituted for a call to
comment|/// memcpy, used for functions with OptSize attribute.
name|unsigned
name|MaxStoresPerMemcpyOptSize
decl_stmt|;
comment|/// \brief Specify maximum bytes of store instructions per memmove call.
comment|///
comment|/// When lowering \@llvm.memmove this field specifies the maximum number of
comment|/// store instructions that may be substituted for a call to memmove. Targets
comment|/// must set this value based on the cost threshold for that target. Targets
comment|/// should assume that the memmove will be done using as many of the largest
comment|/// store operations first, followed by smaller ones, if necessary, per
comment|/// alignment restrictions. For example, moving 9 bytes on a 32-bit machine
comment|/// with 8-bit alignment would result in nine 1-byte stores.  This only
comment|/// applies to copying a constant array of constant size.
name|unsigned
name|MaxStoresPerMemmove
decl_stmt|;
comment|/// Maximum number of store instructions that may be substituted for a call to
comment|/// memmove, used for functions with OptSize attribute.
name|unsigned
name|MaxStoresPerMemmoveOptSize
decl_stmt|;
comment|/// Tells the code generator that select is more expensive than a branch if
comment|/// the branch is usually predicted right.
name|bool
name|PredictableSelectIsExpensive
decl_stmt|;
comment|/// \see enableExtLdPromotion.
name|bool
name|EnableExtLdPromotion
decl_stmt|;
comment|/// Return true if the value types that can be represented by the specified
comment|/// register class are all legal.
name|bool
name|isLegalRC
argument_list|(
specifier|const
name|TargetRegisterInfo
operator|&
name|TRI
argument_list|,
specifier|const
name|TargetRegisterClass
operator|&
name|RC
argument_list|)
decl|const
decl_stmt|;
comment|/// Replace/modify any TargetFrameIndex operands with a targte-dependent
comment|/// sequence of memory operands that is recognized by PrologEpilogInserter.
name|MachineBasicBlock
modifier|*
name|emitPatchPoint
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// This class defines information used to lower LLVM code to legal SelectionDAG
end_comment

begin_comment
comment|/// operators that the target instruction selector can accept natively.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This class also defines callbacks that targets must implement to lower
end_comment

begin_comment
comment|/// target-specific constructs to SelectionDAG operators.
end_comment

begin_decl_stmt
name|class
name|TargetLowering
range|:
name|public
name|TargetLoweringBase
block|{
name|public
operator|:
expr|struct
name|DAGCombinerInfo
block|;
name|TargetLowering
argument_list|(
specifier|const
name|TargetLowering
operator|&
argument_list|)
operator|=
name|delete
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|TargetLowering
operator|&
operator|)
operator|=
name|delete
block|;
comment|/// NOTE: The TargetMachine owns TLOF.
name|explicit
name|TargetLowering
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
name|bool
name|isPositionIndependent
argument_list|()
specifier|const
block|;
comment|/// Returns true by value, base pointer and offset pointer and addressing mode
comment|/// by reference if the node's address can be legally represented as
comment|/// pre-indexed load / store address.
name|virtual
name|bool
name|getPreIndexedAddressParts
argument_list|(
argument|SDNode *
comment|/*N*/
argument_list|,
argument|SDValue&
comment|/*Base*/
argument_list|,
argument|SDValue&
comment|/*Offset*/
argument_list|,
argument|ISD::MemIndexedMode&
comment|/*AM*/
argument_list|,
argument|SelectionDAG&
comment|/*DAG*/
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Returns true by value, base pointer and offset pointer and addressing mode
comment|/// by reference if this node can be combined with a load / store to form a
comment|/// post-indexed load / store.
name|virtual
name|bool
name|getPostIndexedAddressParts
argument_list|(
argument|SDNode *
comment|/*N*/
argument_list|,
argument|SDNode *
comment|/*Op*/
argument_list|,
argument|SDValue&
comment|/*Base*/
argument_list|,
argument|SDValue&
comment|/*Offset*/
argument_list|,
argument|ISD::MemIndexedMode&
comment|/*AM*/
argument_list|,
argument|SelectionDAG&
comment|/*DAG*/
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return the entry encoding for a jump table in the current function.  The
comment|/// returned value is a member of the MachineJumpTableInfo::JTEntryKind enum.
name|virtual
name|unsigned
name|getJumpTableEncoding
argument_list|()
specifier|const
block|;
name|virtual
specifier|const
name|MCExpr
operator|*
name|LowerCustomJumpTableEntry
argument_list|(
argument|const MachineJumpTableInfo *
comment|/*MJTI*/
argument_list|,
argument|const MachineBasicBlock *
comment|/*MBB*/
argument_list|,
argument|unsigned
comment|/*uid*/
argument_list|,
argument|MCContext&
comment|/*Ctx*/
argument_list|)
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Need to implement this hook if target has custom JTIs"
argument_list|)
block|;   }
comment|/// Returns relocation base for the given PIC jumptable.
name|virtual
name|SDValue
name|getPICJumpTableRelocBase
argument_list|(
argument|SDValue Table
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// This returns the relocation base for the given PIC jumptable, the same as
comment|/// getPICJumpTableRelocBase, but as an MCExpr.
name|virtual
specifier|const
name|MCExpr
operator|*
name|getPICJumpTableRelocBaseExpr
argument_list|(
argument|const MachineFunction *MF
argument_list|,
argument|unsigned JTI
argument_list|,
argument|MCContext&Ctx
argument_list|)
specifier|const
block|;
comment|/// Return true if folding a constant offset with the given GlobalAddress is
comment|/// legal.  It is frequently not legal in PIC relocation models.
name|virtual
name|bool
name|isOffsetFoldingLegal
argument_list|(
argument|const GlobalAddressSDNode *GA
argument_list|)
specifier|const
block|;
name|bool
name|isInTailCallPosition
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDNode *Node
argument_list|,
argument|SDValue&Chain
argument_list|)
specifier|const
block|;
name|void
name|softenSetCCOperands
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|EVT VT
argument_list|,
argument|SDValue&NewLHS
argument_list|,
argument|SDValue&NewRHS
argument_list|,
argument|ISD::CondCode&CCCode
argument_list|,
argument|const SDLoc&DL
argument_list|)
specifier|const
block|;
comment|/// Returns a pair of (return value, chain).
comment|/// It is an error to pass RTLIB::UNKNOWN_LIBCALL as \p LC.
name|std
operator|::
name|pair
operator|<
name|SDValue
block|,
name|SDValue
operator|>
name|makeLibCall
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|RTLIB::Libcall LC
argument_list|,
argument|EVT RetVT
argument_list|,
argument|ArrayRef<SDValue> Ops
argument_list|,
argument|bool isSigned
argument_list|,
argument|const SDLoc&dl
argument_list|,
argument|bool doesNotReturn = false
argument_list|,
argument|bool isReturnValueUsed = true
argument_list|)
specifier|const
block|;
comment|/// Check whether parameters to a call that are passed in callee saved
comment|/// registers are the same as from the calling function.  This needs to be
comment|/// checked for tail call eligibility.
name|bool
name|parametersInCSRMatch
argument_list|(
argument|const MachineRegisterInfo&MRI
argument_list|,
argument|const uint32_t *CallerPreservedMask
argument_list|,
argument|const SmallVectorImpl<CCValAssign>&ArgLocs
argument_list|,
argument|const SmallVectorImpl<SDValue>&OutVals
argument_list|)
specifier|const
block|;
comment|//===--------------------------------------------------------------------===//
comment|// TargetLowering Optimization Methods
comment|//
comment|/// A convenience struct that encapsulates a DAG, and two SDValues for
comment|/// returning information from TargetLowering to its clients that want to
comment|/// combine.
block|struct
name|TargetLoweringOpt
block|{
name|SelectionDAG
operator|&
name|DAG
block|;
name|bool
name|LegalTys
block|;
name|bool
name|LegalOps
block|;
name|SDValue
name|Old
block|;
name|SDValue
name|New
block|;
name|explicit
name|TargetLoweringOpt
argument_list|(
argument|SelectionDAG&InDAG
argument_list|,
argument|bool LT
argument_list|,
argument|bool LO
argument_list|)
operator|:
name|DAG
argument_list|(
name|InDAG
argument_list|)
block|,
name|LegalTys
argument_list|(
name|LT
argument_list|)
block|,
name|LegalOps
argument_list|(
argument|LO
argument_list|)
block|{}
name|bool
name|LegalTypes
argument_list|()
specifier|const
block|{
return|return
name|LegalTys
return|;
block|}
name|bool
name|LegalOperations
argument_list|()
specifier|const
block|{
return|return
name|LegalOps
return|;
block|}
name|bool
name|CombineTo
argument_list|(
argument|SDValue O
argument_list|,
argument|SDValue N
argument_list|)
block|{
name|Old
operator|=
name|O
block|;
name|New
operator|=
name|N
block|;
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// Check to see if the specified operand of the specified instruction is a
comment|/// constant integer.  If so, check to see if there are any bits set in the
comment|/// constant that are not demanded.  If so, shrink the constant and return
comment|/// true.
name|bool
name|ShrinkDemandedConstant
argument_list|(
argument|SDValue Op
argument_list|,
argument|const APInt&Demanded
argument_list|,
argument|TargetLoweringOpt&TLO
argument_list|)
specifier|const
block|;
comment|// Target hook to do target-specific const optimization, which is called by
comment|// ShrinkDemandedConstant. This function should return true if the target
comment|// doesn't want ShrinkDemandedConstant to further optimize the constant.
name|virtual
name|bool
name|targetShrinkDemandedConstant
argument_list|(
argument|SDValue Op
argument_list|,
argument|const APInt&Demanded
argument_list|,
argument|TargetLoweringOpt&TLO
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Convert x+y to (VT)((SmallVT)x+(SmallVT)y) if the casts are free.  This
comment|/// uses isZExtFree and ZERO_EXTEND for the widening cast, but it could be
comment|/// generalized for targets with other types of implicit widening casts.
name|bool
name|ShrinkDemandedOp
argument_list|(
argument|SDValue Op
argument_list|,
argument|unsigned BitWidth
argument_list|,
argument|const APInt&Demanded
argument_list|,
argument|TargetLoweringOpt&TLO
argument_list|)
specifier|const
block|;
comment|/// Helper for SimplifyDemandedBits that can simplify an operation with
comment|/// multiple uses.  This function simplifies operand \p OpIdx of \p User and
comment|/// then updates \p User with the simplified version. No other uses of
comment|/// \p OpIdx are updated. If \p User is the only user of \p OpIdx, this
comment|/// function behaves exactly like function SimplifyDemandedBits declared
comment|/// below except that it also updates the DAG by calling
comment|/// DCI.CommitTargetLoweringOpt.
name|bool
name|SimplifyDemandedBits
argument_list|(
argument|SDNode *User
argument_list|,
argument|unsigned OpIdx
argument_list|,
argument|const APInt&Demanded
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|,
argument|TargetLoweringOpt&TLO
argument_list|)
specifier|const
block|;
comment|/// Look at Op.  At this point, we know that only the DemandedMask bits of the
comment|/// result of Op are ever used downstream.  If we can use this information to
comment|/// simplify Op, create a new simplified DAG node and return true, returning
comment|/// the original and new nodes in Old and New.  Otherwise, analyze the
comment|/// expression and return a mask of KnownOne and KnownZero bits for the
comment|/// expression (used to simplify the caller).  The KnownZero/One bits may only
comment|/// be accurate for those bits in the DemandedMask.
comment|/// \p AssumeSingleUse When this parameter is true, this function will
comment|///    attempt to simplify \p Op even if there are multiple uses.
comment|///    Callers are responsible for correctly updating the DAG based on the
comment|///    results of this function, because simply replacing replacing TLO.Old
comment|///    with TLO.New will be incorrect when this parameter is true and TLO.Old
comment|///    has multiple uses.
name|bool
name|SimplifyDemandedBits
argument_list|(
argument|SDValue Op
argument_list|,
argument|const APInt&DemandedMask
argument_list|,
argument|KnownBits&Known
argument_list|,
argument|TargetLoweringOpt&TLO
argument_list|,
argument|unsigned Depth =
literal|0
argument_list|,
argument|bool AssumeSingleUse = false
argument_list|)
specifier|const
block|;
comment|/// Helper wrapper around SimplifyDemandedBits
name|bool
name|SimplifyDemandedBits
argument_list|(
argument|SDValue Op
argument_list|,
argument|APInt&DemandedMask
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
comment|/// Determine which of the bits specified in Mask are known to be either zero
comment|/// or one and return them in the KnownZero/KnownOne bitsets. The DemandedElts
comment|/// argument allows us to only collect the known bits that are shared by the
comment|/// requested vector elements.
name|virtual
name|void
name|computeKnownBitsForTargetNode
argument_list|(
argument|const SDValue Op
argument_list|,
argument|KnownBits&Known
argument_list|,
argument|const APInt&DemandedElts
argument_list|,
argument|const SelectionDAG&DAG
argument_list|,
argument|unsigned Depth =
literal|0
argument_list|)
specifier|const
block|;
comment|/// This method can be implemented by targets that want to expose additional
comment|/// information about sign bits to the DAG Combiner. The DemandedElts
comment|/// argument allows us to only collect the minimum sign bits that are shared
comment|/// by the requested vector elements.
name|virtual
name|unsigned
name|ComputeNumSignBitsForTargetNode
argument_list|(
argument|SDValue Op
argument_list|,
argument|const APInt&DemandedElts
argument_list|,
argument|const SelectionDAG&DAG
argument_list|,
argument|unsigned Depth =
literal|0
argument_list|)
specifier|const
block|;    struct
name|DAGCombinerInfo
block|{
name|void
operator|*
name|DC
block|;
comment|// The DAG Combiner object.
name|CombineLevel
name|Level
block|;
name|bool
name|CalledByLegalizer
block|;
name|public
operator|:
name|SelectionDAG
operator|&
name|DAG
block|;
name|DAGCombinerInfo
argument_list|(
argument|SelectionDAG&dag
argument_list|,
argument|CombineLevel level
argument_list|,
argument|bool cl
argument_list|,
argument|void *dc
argument_list|)
operator|:
name|DC
argument_list|(
name|dc
argument_list|)
block|,
name|Level
argument_list|(
name|level
argument_list|)
block|,
name|CalledByLegalizer
argument_list|(
name|cl
argument_list|)
block|,
name|DAG
argument_list|(
argument|dag
argument_list|)
block|{}
name|bool
name|isBeforeLegalize
argument_list|()
specifier|const
block|{
return|return
name|Level
operator|==
name|BeforeLegalizeTypes
return|;
block|}
name|bool
name|isBeforeLegalizeOps
argument_list|()
specifier|const
block|{
return|return
name|Level
operator|<
name|AfterLegalizeVectorOps
return|;
block|}
name|bool
name|isAfterLegalizeVectorOps
argument_list|()
specifier|const
block|{
return|return
name|Level
operator|==
name|AfterLegalizeDAG
return|;
block|}
name|CombineLevel
name|getDAGCombineLevel
argument_list|()
block|{
return|return
name|Level
return|;
block|}
name|bool
name|isCalledByLegalizer
argument_list|()
specifier|const
block|{
return|return
name|CalledByLegalizer
return|;
block|}
name|void
name|AddToWorklist
argument_list|(
name|SDNode
operator|*
name|N
argument_list|)
block|;
name|SDValue
name|CombineTo
argument_list|(
argument|SDNode *N
argument_list|,
argument|ArrayRef<SDValue> To
argument_list|,
argument|bool AddTo = true
argument_list|)
block|;
name|SDValue
name|CombineTo
argument_list|(
argument|SDNode *N
argument_list|,
argument|SDValue Res
argument_list|,
argument|bool AddTo = true
argument_list|)
block|;
name|SDValue
name|CombineTo
argument_list|(
argument|SDNode *N
argument_list|,
argument|SDValue Res0
argument_list|,
argument|SDValue Res1
argument_list|,
argument|bool AddTo = true
argument_list|)
block|;
name|void
name|CommitTargetLoweringOpt
argument_list|(
specifier|const
name|TargetLoweringOpt
operator|&
name|TLO
argument_list|)
block|;   }
block|;
comment|/// Return if the N is a constant or constant vector equal to the true value
comment|/// from getBooleanContents().
name|bool
name|isConstTrueVal
argument_list|(
argument|const SDNode *N
argument_list|)
specifier|const
block|;
comment|/// Return if the N is a constant or constant vector equal to the false value
comment|/// from getBooleanContents().
name|bool
name|isConstFalseVal
argument_list|(
argument|const SDNode *N
argument_list|)
specifier|const
block|;
comment|/// Return a constant of type VT that contains a true value that respects
comment|/// getBooleanContents()
name|SDValue
name|getConstTrueVal
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|EVT VT
argument_list|,
argument|const SDLoc&DL
argument_list|)
specifier|const
block|;
comment|/// Return if \p N is a True value when extended to \p VT.
name|bool
name|isExtendedTrueVal
argument_list|(
argument|const ConstantSDNode *N
argument_list|,
argument|EVT VT
argument_list|,
argument|bool Signed
argument_list|)
specifier|const
block|;
comment|/// Try to simplify a setcc built with the specified operands and cc. If it is
comment|/// unable to simplify it, return a null SDValue.
name|SDValue
name|SimplifySetCC
argument_list|(
argument|EVT VT
argument_list|,
argument|SDValue N0
argument_list|,
argument|SDValue N1
argument_list|,
argument|ISD::CondCode Cond
argument_list|,
argument|bool foldBooleans
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|,
argument|const SDLoc&dl
argument_list|)
specifier|const
block|;
comment|/// Returns true (and the GlobalValue and the offset) if the node is a
comment|/// GlobalAddress + offset.
name|virtual
name|bool
name|isGAPlusOffset
argument_list|(
argument|SDNode *N
argument_list|,
argument|const GlobalValue*&GA
argument_list|,
argument|int64_t&Offset
argument_list|)
specifier|const
block|;
comment|/// This method will be invoked for all target nodes and for any
comment|/// target-independent nodes that the target has registered with invoke it
comment|/// for.
comment|///
comment|/// The semantics are as follows:
comment|/// Return Value:
comment|///   SDValue.Val == 0   - No change was made
comment|///   SDValue.Val == N   - N was replaced, is dead, and is already handled.
comment|///   otherwise          - N should be replaced by the returned Operand.
comment|///
comment|/// In addition, methods provided by DAGCombinerInfo may be used to perform
comment|/// more complex transformations.
comment|///
name|virtual
name|SDValue
name|PerformDAGCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
comment|/// Return true if it is profitable to move a following shift through this
comment|//  node, adjusting any immediate operands as necessary to preserve semantics.
comment|//  This transformation may not be desirable if it disrupts a particularly
comment|//  auspicious target-specific tree (e.g. bitfield extraction in AArch64).
comment|//  By default, it returns true.
name|virtual
name|bool
name|isDesirableToCommuteWithShift
argument_list|(
argument|const SDNode *N
comment|/*Op*/
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// Return true if the target has native support for the specified value type
comment|/// and it is 'desirable' to use the type for the given node type. e.g. On x86
comment|/// i16 is legal, but undesirable since i16 instruction encodings are longer
comment|/// and some i16 instructions are slow.
name|virtual
name|bool
name|isTypeDesirableForOp
argument_list|(
argument|unsigned
comment|/*Opc*/
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
block|{
comment|// By default, assume all legal types are desirable.
return|return
name|isTypeLegal
argument_list|(
name|VT
argument_list|)
return|;
block|}
comment|/// Return true if it is profitable for dag combiner to transform a floating
comment|/// point op of specified opcode to a equivalent op of an integer
comment|/// type. e.g. f32 load -> i32 load can be profitable on ARM.
name|virtual
name|bool
name|isDesirableToTransformToIntegerOp
argument_list|(
argument|unsigned
comment|/*Opc*/
argument_list|,
argument|EVT
comment|/*VT*/
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// This method query the target whether it is beneficial for dag combiner to
comment|/// promote the specified node. If true, it should return the desired
comment|/// promotion type by reference.
name|virtual
name|bool
name|IsDesirableToPromoteOp
argument_list|(
argument|SDValue
comment|/*Op*/
argument_list|,
argument|EVT&
comment|/*PVT*/
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return true if the target supports swifterror attribute. It optimizes
comment|/// loads and stores to reading and writing a specific register.
name|virtual
name|bool
name|supportSwiftError
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return true if the target supports that a subset of CSRs for the given
comment|/// machine function is handled explicitly via copies.
name|virtual
name|bool
name|supportSplitCSR
argument_list|(
argument|MachineFunction *MF
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Perform necessary initialization to handle a subset of CSRs explicitly
comment|/// via copies. This function is called at the beginning of instruction
comment|/// selection.
name|virtual
name|void
name|initializeSplitCSR
argument_list|(
argument|MachineBasicBlock *Entry
argument_list|)
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Not Implemented"
argument_list|)
block|;   }
comment|/// Insert explicit copies in entry and exit blocks. We copy a subset of
comment|/// CSRs to virtual registers in the entry block, and copy them back to
comment|/// physical registers in the exit blocks. This function is called at the end
comment|/// of instruction selection.
name|virtual
name|void
name|insertCopiesSplitCSR
argument_list|(
argument|MachineBasicBlock *Entry
argument_list|,
argument|const SmallVectorImpl<MachineBasicBlock *>&Exits
argument_list|)
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Not Implemented"
argument_list|)
block|;   }
comment|//===--------------------------------------------------------------------===//
comment|// Lowering methods - These methods must be implemented by targets so that
comment|// the SelectionDAGBuilder code knows how to lower these.
comment|//
comment|/// This hook must be implemented to lower the incoming (formal) arguments,
comment|/// described by the Ins array, into the specified DAG. The implementation
comment|/// should fill in the InVals array with legal-type argument values, and
comment|/// return the resulting token chain value.
comment|///
name|virtual
name|SDValue
name|LowerFormalArguments
argument_list|(
argument|SDValue
comment|/*Chain*/
argument_list|,
argument|CallingConv::ID
comment|/*CallConv*/
argument_list|,
argument|bool
comment|/*isVarArg*/
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&
comment|/*Ins*/
argument_list|,
argument|const SDLoc&
comment|/*dl*/
argument_list|,
argument|SelectionDAG&
comment|/*DAG*/
argument_list|,
argument|SmallVectorImpl<SDValue>&
comment|/*InVals*/
argument_list|)
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Not Implemented"
argument_list|)
block|;   }
comment|/// This structure contains all information that is necessary for lowering
comment|/// calls. It is passed to TLI::LowerCallTo when the SelectionDAG builder
comment|/// needs to lower a call, and targets will see this struct in their LowerCall
comment|/// implementation.
expr|struct
name|CallLoweringInfo
block|{
name|SDValue
name|Chain
block|;
name|Type
operator|*
name|RetTy
block|;
name|bool
name|RetSExt
operator|:
literal|1
block|;
name|bool
name|RetZExt
operator|:
literal|1
block|;
name|bool
name|IsVarArg
operator|:
literal|1
block|;
name|bool
name|IsInReg
operator|:
literal|1
block|;
name|bool
name|DoesNotReturn
operator|:
literal|1
block|;
name|bool
name|IsReturnValueUsed
operator|:
literal|1
block|;
name|bool
name|IsConvergent
operator|:
literal|1
block|;
comment|// IsTailCall should be modified by implementations of
comment|// TargetLowering::LowerCall that perform tail call conversions.
name|bool
name|IsTailCall
block|;
name|unsigned
name|NumFixedArgs
block|;
name|CallingConv
operator|::
name|ID
name|CallConv
block|;
name|SDValue
name|Callee
block|;
name|ArgListTy
name|Args
block|;
name|SelectionDAG
operator|&
name|DAG
block|;
name|SDLoc
name|DL
block|;
name|ImmutableCallSite
operator|*
name|CS
block|;
name|bool
name|IsPatchPoint
block|;
name|SmallVector
operator|<
name|ISD
operator|::
name|OutputArg
block|,
literal|32
operator|>
name|Outs
block|;
name|SmallVector
operator|<
name|SDValue
block|,
literal|32
operator|>
name|OutVals
block|;
name|SmallVector
operator|<
name|ISD
operator|::
name|InputArg
block|,
literal|32
operator|>
name|Ins
block|;
name|SmallVector
operator|<
name|SDValue
block|,
literal|4
operator|>
name|InVals
block|;
name|CallLoweringInfo
argument_list|(
name|SelectionDAG
operator|&
name|DAG
argument_list|)
operator|:
name|RetTy
argument_list|(
name|nullptr
argument_list|)
block|,
name|RetSExt
argument_list|(
name|false
argument_list|)
block|,
name|RetZExt
argument_list|(
name|false
argument_list|)
block|,
name|IsVarArg
argument_list|(
name|false
argument_list|)
block|,
name|IsInReg
argument_list|(
name|false
argument_list|)
block|,
name|DoesNotReturn
argument_list|(
name|false
argument_list|)
block|,
name|IsReturnValueUsed
argument_list|(
name|true
argument_list|)
block|,
name|IsConvergent
argument_list|(
name|false
argument_list|)
block|,
name|IsTailCall
argument_list|(
name|false
argument_list|)
block|,
name|NumFixedArgs
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|CallConv
argument_list|(
name|CallingConv
operator|::
name|C
argument_list|)
block|,
name|DAG
argument_list|(
name|DAG
argument_list|)
block|,
name|CS
argument_list|(
name|nullptr
argument_list|)
block|,
name|IsPatchPoint
argument_list|(
argument|false
argument_list|)
block|{     }
name|CallLoweringInfo
operator|&
name|setDebugLoc
argument_list|(
argument|const SDLoc&dl
argument_list|)
block|{
name|DL
operator|=
name|dl
block|;
return|return
operator|*
name|this
return|;
block|}
name|CallLoweringInfo
operator|&
name|setChain
argument_list|(
argument|SDValue InChain
argument_list|)
block|{
name|Chain
operator|=
name|InChain
block|;
return|return
operator|*
name|this
return|;
block|}
comment|// setCallee with target/module-specific attributes
name|CallLoweringInfo
operator|&
name|setLibCallee
argument_list|(
argument|CallingConv::ID CC
argument_list|,
argument|Type *ResultType
argument_list|,
argument|SDValue Target
argument_list|,
argument|ArgListTy&&ArgsList
argument_list|)
block|{
name|RetTy
operator|=
name|ResultType
block|;
name|Callee
operator|=
name|Target
block|;
name|CallConv
operator|=
name|CC
block|;
name|NumFixedArgs
operator|=
name|Args
operator|.
name|size
argument_list|()
block|;
name|Args
operator|=
name|std
operator|::
name|move
argument_list|(
name|ArgsList
argument_list|)
block|;
name|DAG
operator|.
name|getTargetLoweringInfo
argument_list|()
operator|.
name|markLibCallAttributes
argument_list|(
operator|&
operator|(
name|DAG
operator|.
name|getMachineFunction
argument_list|()
operator|)
argument_list|,
name|CC
argument_list|,
name|Args
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|CallLoweringInfo
operator|&
name|setCallee
argument_list|(
argument|CallingConv::ID CC
argument_list|,
argument|Type *ResultType
argument_list|,
argument|SDValue Target
argument_list|,
argument|ArgListTy&&ArgsList
argument_list|)
block|{
name|RetTy
operator|=
name|ResultType
block|;
name|Callee
operator|=
name|Target
block|;
name|CallConv
operator|=
name|CC
block|;
name|NumFixedArgs
operator|=
name|Args
operator|.
name|size
argument_list|()
block|;
name|Args
operator|=
name|std
operator|::
name|move
argument_list|(
name|ArgsList
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|CallLoweringInfo
operator|&
name|setCallee
argument_list|(
argument|Type *ResultType
argument_list|,
argument|FunctionType *FTy
argument_list|,
argument|SDValue Target
argument_list|,
argument|ArgListTy&&ArgsList
argument_list|,
argument|ImmutableCallSite&Call
argument_list|)
block|{
name|RetTy
operator|=
name|ResultType
block|;
name|IsInReg
operator|=
name|Call
operator|.
name|hasRetAttr
argument_list|(
name|Attribute
operator|::
name|InReg
argument_list|)
block|;
name|DoesNotReturn
operator|=
name|Call
operator|.
name|doesNotReturn
argument_list|()
operator|||
operator|(
operator|!
name|Call
operator|.
name|isInvoke
argument_list|()
operator|&&
name|isa
operator|<
name|UnreachableInst
operator|>
operator|(
name|Call
operator|.
name|getInstruction
argument_list|()
operator|->
name|getNextNode
argument_list|()
operator|)
operator|)
block|;
name|IsVarArg
operator|=
name|FTy
operator|->
name|isVarArg
argument_list|()
block|;
name|IsReturnValueUsed
operator|=
operator|!
name|Call
operator|.
name|getInstruction
argument_list|()
operator|->
name|use_empty
argument_list|()
block|;
name|RetSExt
operator|=
name|Call
operator|.
name|hasRetAttr
argument_list|(
name|Attribute
operator|::
name|SExt
argument_list|)
block|;
name|RetZExt
operator|=
name|Call
operator|.
name|hasRetAttr
argument_list|(
name|Attribute
operator|::
name|ZExt
argument_list|)
block|;
name|Callee
operator|=
name|Target
block|;
name|CallConv
operator|=
name|Call
operator|.
name|getCallingConv
argument_list|()
block|;
name|NumFixedArgs
operator|=
name|FTy
operator|->
name|getNumParams
argument_list|()
block|;
name|Args
operator|=
name|std
operator|::
name|move
argument_list|(
name|ArgsList
argument_list|)
block|;
name|CS
operator|=
operator|&
name|Call
block|;
return|return
operator|*
name|this
return|;
block|}
name|CallLoweringInfo
operator|&
name|setInRegister
argument_list|(
argument|bool Value = true
argument_list|)
block|{
name|IsInReg
operator|=
name|Value
block|;
return|return
operator|*
name|this
return|;
block|}
name|CallLoweringInfo
operator|&
name|setNoReturn
argument_list|(
argument|bool Value = true
argument_list|)
block|{
name|DoesNotReturn
operator|=
name|Value
block|;
return|return
operator|*
name|this
return|;
block|}
name|CallLoweringInfo
operator|&
name|setVarArg
argument_list|(
argument|bool Value = true
argument_list|)
block|{
name|IsVarArg
operator|=
name|Value
block|;
return|return
operator|*
name|this
return|;
block|}
name|CallLoweringInfo
operator|&
name|setTailCall
argument_list|(
argument|bool Value = true
argument_list|)
block|{
name|IsTailCall
operator|=
name|Value
block|;
return|return
operator|*
name|this
return|;
block|}
name|CallLoweringInfo
operator|&
name|setDiscardResult
argument_list|(
argument|bool Value = true
argument_list|)
block|{
name|IsReturnValueUsed
operator|=
operator|!
name|Value
block|;
return|return
operator|*
name|this
return|;
block|}
name|CallLoweringInfo
operator|&
name|setConvergent
argument_list|(
argument|bool Value = true
argument_list|)
block|{
name|IsConvergent
operator|=
name|Value
block|;
return|return
operator|*
name|this
return|;
block|}
name|CallLoweringInfo
operator|&
name|setSExtResult
argument_list|(
argument|bool Value = true
argument_list|)
block|{
name|RetSExt
operator|=
name|Value
block|;
return|return
operator|*
name|this
return|;
block|}
name|CallLoweringInfo
operator|&
name|setZExtResult
argument_list|(
argument|bool Value = true
argument_list|)
block|{
name|RetZExt
operator|=
name|Value
block|;
return|return
operator|*
name|this
return|;
block|}
name|CallLoweringInfo
operator|&
name|setIsPatchPoint
argument_list|(
argument|bool Value = true
argument_list|)
block|{
name|IsPatchPoint
operator|=
name|Value
block|;
return|return
operator|*
name|this
return|;
block|}
name|ArgListTy
operator|&
name|getArgs
argument_list|()
block|{
return|return
name|Args
return|;
block|}
expr|}
block|;
comment|/// This function lowers an abstract call to a function into an actual call.
comment|/// This returns a pair of operands.  The first element is the return value
comment|/// for the function (if RetTy is not VoidTy).  The second element is the
comment|/// outgoing token chain. It calls LowerCall to do the actual lowering.
name|std
operator|::
name|pair
operator|<
name|SDValue
block|,
name|SDValue
operator|>
name|LowerCallTo
argument_list|(
argument|CallLoweringInfo&CLI
argument_list|)
specifier|const
block|;
comment|/// This hook must be implemented to lower calls into the specified
comment|/// DAG. The outgoing arguments to the call are described by the Outs array,
comment|/// and the values to be returned by the call are described by the Ins
comment|/// array. The implementation should fill in the InVals array with legal-type
comment|/// return values from the call, and return the resulting token chain value.
name|virtual
name|SDValue
name|LowerCall
argument_list|(
argument|CallLoweringInfo&
comment|/*CLI*/
argument_list|,
argument|SmallVectorImpl<SDValue>&
comment|/*InVals*/
argument_list|)
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Not Implemented"
argument_list|)
block|;   }
comment|/// Target-specific cleanup for formal ByVal parameters.
name|virtual
name|void
name|HandleByVal
argument_list|(
argument|CCState *
argument_list|,
argument|unsigned&
argument_list|,
argument|unsigned
argument_list|)
specifier|const
block|{}
comment|/// This hook should be implemented to check whether the return values
comment|/// described by the Outs array can fit into the return registers.  If false
comment|/// is returned, an sret-demotion is performed.
name|virtual
name|bool
name|CanLowerReturn
argument_list|(
argument|CallingConv::ID
comment|/*CallConv*/
argument_list|,
argument|MachineFunction&
comment|/*MF*/
argument_list|,
argument|bool
comment|/*isVarArg*/
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&
comment|/*Outs*/
argument_list|,
argument|LLVMContext&
comment|/*Context*/
argument_list|)
specifier|const
block|{
comment|// Return true by default to get preexisting behavior.
return|return
name|true
return|;
block|}
comment|/// This hook must be implemented to lower outgoing return values, described
comment|/// by the Outs array, into the specified DAG. The implementation should
comment|/// return the resulting token chain value.
name|virtual
name|SDValue
name|LowerReturn
argument_list|(
argument|SDValue
comment|/*Chain*/
argument_list|,
argument|CallingConv::ID
comment|/*CallConv*/
argument_list|,
argument|bool
comment|/*isVarArg*/
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&
comment|/*Outs*/
argument_list|,
argument|const SmallVectorImpl<SDValue>&
comment|/*OutVals*/
argument_list|,
argument|const SDLoc&
comment|/*dl*/
argument_list|,
argument|SelectionDAG&
comment|/*DAG*/
argument_list|)
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Not Implemented"
argument_list|)
block|;   }
comment|/// Return true if result of the specified node is used by a return node
comment|/// only. It also compute and return the input chain for the tail call.
comment|///
comment|/// This is used to determine whether it is possible to codegen a libcall as
comment|/// tail call at legalization time.
name|virtual
name|bool
name|isUsedByReturnOnly
argument_list|(
argument|SDNode *
argument_list|,
argument|SDValue&
comment|/*Chain*/
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return true if the target may be able emit the call instruction as a tail
comment|/// call. This is used by optimization passes to determine if it's profitable
comment|/// to duplicate return instructions to enable tailcall optimization.
name|virtual
name|bool
name|mayBeEmittedAsTailCall
argument_list|(
argument|const CallInst *
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return the builtin name for the __builtin___clear_cache intrinsic
comment|/// Default is to invoke the clear cache library call
name|virtual
specifier|const
name|char
operator|*
name|getClearCacheBuiltinName
argument_list|()
specifier|const
block|{
return|return
literal|"__clear_cache"
return|;
block|}
comment|/// Return the register ID of the name passed in. Used by named register
comment|/// global variables extension. There is no target-independent behaviour
comment|/// so the default action is to bail.
name|virtual
name|unsigned
name|getRegisterByName
argument_list|(
argument|const char* RegName
argument_list|,
argument|EVT VT
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|{
name|report_fatal_error
argument_list|(
literal|"Named registers not implemented for this target"
argument_list|)
block|;   }
comment|/// Return the type that should be used to zero or sign extend a
comment|/// zeroext/signext integer return value.  FIXME: Some C calling conventions
comment|/// require the return type to be promoted, but this is not true all the time,
comment|/// e.g. i1/i8/i16 on x86/x86_64. It is also not necessary for non-C calling
comment|/// conventions. The frontend should handle this and include all of the
comment|/// necessary information.
name|virtual
name|EVT
name|getTypeForExtReturn
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|EVT VT
argument_list|,
argument|ISD::NodeType
comment|/*ExtendKind*/
argument_list|)
specifier|const
block|{
name|EVT
name|MinVT
operator|=
name|getRegisterType
argument_list|(
name|Context
argument_list|,
name|MVT
operator|::
name|i32
argument_list|)
block|;
return|return
name|VT
operator|.
name|bitsLT
argument_list|(
name|MinVT
argument_list|)
condition|?
name|MinVT
else|:
name|VT
return|;
block|}
comment|/// For some targets, an LLVM struct type must be broken down into multiple
comment|/// simple types, but the calling convention specifies that the entire struct
comment|/// must be passed in a block of consecutive registers.
name|virtual
name|bool
name|functionArgumentNeedsConsecutiveRegisters
argument_list|(
argument|Type *Ty
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool isVarArg
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Returns a 0 terminated array of registers that can be safely used as
comment|/// scratch registers.
name|virtual
specifier|const
name|MCPhysReg
operator|*
name|getScratchRegisters
argument_list|(
argument|CallingConv::ID CC
argument_list|)
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
comment|/// This callback is used to prepare for a volatile or atomic load.
comment|/// It takes a chain node as input and returns the chain for the load itself.
comment|///
comment|/// Having a callback like this is necessary for targets like SystemZ,
comment|/// which allows a CPU to reuse the result of a previous load indefinitely,
comment|/// even if a cache-coherent store is performed by another CPU.  The default
comment|/// implementation does nothing.
name|virtual
name|SDValue
name|prepareVolatileOrAtomicLoad
argument_list|(
argument|SDValue Chain
argument_list|,
argument|const SDLoc&DL
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|{
return|return
name|Chain
return|;
block|}
comment|/// This callback is invoked by the type legalizer to legalize nodes with an
comment|/// illegal operand type but legal result types.  It replaces the
comment|/// LowerOperation callback in the type Legalizer.  The reason we can not do
comment|/// away with LowerOperation entirely is that LegalizeDAG isn't yet ready to
comment|/// use this callback.
comment|///
comment|/// TODO: Consider merging with ReplaceNodeResults.
comment|///
comment|/// The target places new result values for the node in Results (their number
comment|/// and types must exactly match those of the original return values of
comment|/// the node), or leaves Results empty, which indicates that the node is not
comment|/// to be custom lowered after all.
comment|/// The default implementation calls LowerOperation.
name|virtual
name|void
name|LowerOperationWrapper
argument_list|(
argument|SDNode *N
argument_list|,
argument|SmallVectorImpl<SDValue>&Results
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// This callback is invoked for operations that are unsupported by the
comment|/// target, which are registered to use 'custom' lowering, and whose defined
comment|/// values are all legal.  If the target has no operations that require custom
comment|/// lowering, it need not implement this.  The default implementation of this
comment|/// aborts.
name|virtual
name|SDValue
name|LowerOperation
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// This callback is invoked when a node result type is illegal for the
comment|/// target, and the operation was registered to use 'custom' lowering for that
comment|/// result type.  The target places new result values for the node in Results
comment|/// (their number and types must exactly match those of the original return
comment|/// values of the node), or leaves Results empty, which indicates that the
comment|/// node is not to be custom lowered after all.
comment|///
comment|/// If the target has no operations that require custom lowering, it need not
comment|/// implement this.  The default implementation aborts.
name|virtual
name|void
name|ReplaceNodeResults
argument_list|(
argument|SDNode *
comment|/*N*/
argument_list|,
argument|SmallVectorImpl<SDValue>&
comment|/*Results*/
argument_list|,
argument|SelectionDAG&
comment|/*DAG*/
argument_list|)
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"ReplaceNodeResults not implemented for this target!"
argument_list|)
block|;   }
comment|/// This method returns the name of a target specific DAG node.
name|virtual
specifier|const
name|char
operator|*
name|getTargetNodeName
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
comment|/// This method returns a target specific FastISel object, or null if the
comment|/// target does not support "fast" ISel.
name|virtual
name|FastISel
operator|*
name|createFastISel
argument_list|(
argument|FunctionLoweringInfo&
argument_list|,
argument|const TargetLibraryInfo *
argument_list|)
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
name|bool
name|verifyReturnAddressArgumentIsConstant
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|//===--------------------------------------------------------------------===//
comment|// Inline Asm Support hooks
comment|//
comment|/// This hook allows the target to expand an inline asm call to be explicit
comment|/// llvm code if it wants to.  This is useful for turning simple inline asms
comment|/// into LLVM intrinsics, which gives the compiler more information about the
comment|/// behavior of the code.
name|virtual
name|bool
name|ExpandInlineAsm
argument_list|(
argument|CallInst *
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
expr|enum
name|ConstraintType
block|{
name|C_Register
block|,
comment|// Constraint represents specific register(s).
name|C_RegisterClass
block|,
comment|// Constraint represents any of register(s) in class.
name|C_Memory
block|,
comment|// Memory constraint.
name|C_Other
block|,
comment|// Something else.
name|C_Unknown
comment|// Unsupported constraint.
block|}
block|;    enum
name|ConstraintWeight
block|{
comment|// Generic weights.
name|CW_Invalid
operator|=
operator|-
literal|1
block|,
comment|// No match.
name|CW_Okay
operator|=
literal|0
block|,
comment|// Acceptable.
name|CW_Good
operator|=
literal|1
block|,
comment|// Good weight.
name|CW_Better
operator|=
literal|2
block|,
comment|// Better weight.
name|CW_Best
operator|=
literal|3
block|,
comment|// Best weight.
comment|// Well-known weights.
name|CW_SpecificReg
operator|=
name|CW_Okay
block|,
comment|// Specific register operands.
name|CW_Register
operator|=
name|CW_Good
block|,
comment|// Register operands.
name|CW_Memory
operator|=
name|CW_Better
block|,
comment|// Memory operands.
name|CW_Constant
operator|=
name|CW_Best
block|,
comment|// Constant operand.
name|CW_Default
operator|=
name|CW_Okay
comment|// Default or don't know type.
block|}
block|;
comment|/// This contains information for each constraint that we are lowering.
block|struct
name|AsmOperandInfo
operator|:
name|public
name|InlineAsm
operator|::
name|ConstraintInfo
block|{
comment|/// This contains the actual string for the code, like "m".  TargetLowering
comment|/// picks the 'best' code from ConstraintInfo::Codes that most closely
comment|/// matches the operand.
name|std
operator|::
name|string
name|ConstraintCode
block|;
comment|/// Information about the constraint code, e.g. Register, RegisterClass,
comment|/// Memory, Other, Unknown.
name|TargetLowering
operator|::
name|ConstraintType
name|ConstraintType
block|;
comment|/// If this is the result output operand or a clobber, this is null,
comment|/// otherwise it is the incoming operand to the CallInst.  This gets
comment|/// modified as the asm is processed.
name|Value
operator|*
name|CallOperandVal
block|;
comment|/// The ValueType for the operand value.
name|MVT
name|ConstraintVT
block|;
comment|/// Return true of this is an input operand that is a matching constraint
comment|/// like "4".
name|bool
name|isMatchingInputConstraint
argument_list|()
specifier|const
block|;
comment|/// If this is an input matching constraint, this method returns the output
comment|/// operand it matches.
name|unsigned
name|getMatchedOperand
argument_list|()
specifier|const
block|;
comment|/// Copy constructor for copying from a ConstraintInfo.
name|AsmOperandInfo
argument_list|(
argument|InlineAsm::ConstraintInfo Info
argument_list|)
operator|:
name|InlineAsm
operator|::
name|ConstraintInfo
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Info
argument_list|)
argument_list|)
block|,
name|ConstraintType
argument_list|(
name|TargetLowering
operator|::
name|C_Unknown
argument_list|)
block|,
name|CallOperandVal
argument_list|(
name|nullptr
argument_list|)
block|,
name|ConstraintVT
argument_list|(
argument|MVT::Other
argument_list|)
block|{}
block|}
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|AsmOperandInfo
operator|>
name|AsmOperandInfoVector
expr_stmt|;
comment|/// Split up the constraint string from the inline assembly value into the
comment|/// specific constraints and their prefixes, and also tie in the associated
comment|/// operand values.  If this returns an empty vector, and if the constraint
comment|/// string itself isn't empty, there was an error parsing.
name|virtual
name|AsmOperandInfoVector
name|ParseConstraints
argument_list|(
argument|const DataLayout&DL
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|,
argument|ImmutableCallSite CS
argument_list|)
specifier|const
block|;
comment|/// Examine constraint type and operand type and determine a weight value.
comment|/// The operand object must already have been set up with the operand type.
name|virtual
name|ConstraintWeight
name|getMultipleConstraintMatchWeight
argument_list|(
argument|AsmOperandInfo&info
argument_list|,
argument|int maIndex
argument_list|)
specifier|const
block|;
comment|/// Examine constraint string and operand type and determine a weight value.
comment|/// The operand object must already have been set up with the operand type.
name|virtual
name|ConstraintWeight
name|getSingleConstraintMatchWeight
argument_list|(
argument|AsmOperandInfo&info
argument_list|,
argument|const char *constraint
argument_list|)
specifier|const
block|;
comment|/// Determines the constraint code and constraint type to use for the specific
comment|/// AsmOperandInfo, setting OpInfo.ConstraintCode and OpInfo.ConstraintType.
comment|/// If the actual operand being passed in is available, it can be passed in as
comment|/// Op, otherwise an empty SDValue can be passed.
name|virtual
name|void
name|ComputeConstraintToUse
argument_list|(
argument|AsmOperandInfo&OpInfo
argument_list|,
argument|SDValue Op
argument_list|,
argument|SelectionDAG *DAG = nullptr
argument_list|)
specifier|const
block|;
comment|/// Given a constraint, return the type of constraint it is for this target.
name|virtual
name|ConstraintType
name|getConstraintType
argument_list|(
argument|StringRef Constraint
argument_list|)
specifier|const
block|;
comment|/// Given a physical register constraint (e.g.  {edx}), return the register
comment|/// number and the register class for the register.
comment|///
comment|/// Given a register class constraint, like 'r', if this corresponds directly
comment|/// to an LLVM register class, return a register of 0 and the register class
comment|/// pointer.
comment|///
comment|/// This should only be used for C_Register constraints.  On error, this
comment|/// returns a register number of 0 and a null register class pointer.
name|virtual
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
specifier|const
name|TargetRegisterClass
operator|*
operator|>
name|getRegForInlineAsmConstraint
argument_list|(
argument|const TargetRegisterInfo *TRI
argument_list|,
argument|StringRef Constraint
argument_list|,
argument|MVT VT
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getInlineAsmMemConstraint
argument_list|(
argument|StringRef ConstraintCode
argument_list|)
specifier|const
block|{
if|if
condition|(
name|ConstraintCode
operator|==
literal|"i"
condition|)
return|return
name|InlineAsm
operator|::
name|Constraint_i
return|;
elseif|else
if|if
condition|(
name|ConstraintCode
operator|==
literal|"m"
condition|)
return|return
name|InlineAsm
operator|::
name|Constraint_m
return|;
return|return
name|InlineAsm
operator|::
name|Constraint_Unknown
return|;
block|}
comment|/// Try to replace an X constraint, which matches anything, with another that
comment|/// has more specific requirements based on the type of the corresponding
comment|/// operand.  This returns null if there is no replacement to make.
name|virtual
specifier|const
name|char
operator|*
name|LowerXConstraint
argument_list|(
argument|EVT ConstraintVT
argument_list|)
specifier|const
block|;
comment|/// Lower the specified operand into the Ops vector.  If it is invalid, don't
comment|/// add anything to Ops.
name|virtual
name|void
name|LowerAsmOperandForConstraint
argument_list|(
argument|SDValue Op
argument_list|,
argument|std::string&Constraint
argument_list|,
argument|std::vector<SDValue>&Ops
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|//===--------------------------------------------------------------------===//
comment|// Div utility functions
comment|//
name|SDValue
name|BuildSDIV
argument_list|(
argument|SDNode *N
argument_list|,
argument|const APInt&Divisor
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|bool IsAfterLegalization
argument_list|,
argument|std::vector<SDNode *> *Created
argument_list|)
specifier|const
block|;
name|SDValue
name|BuildUDIV
argument_list|(
argument|SDNode *N
argument_list|,
argument|const APInt&Divisor
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|bool IsAfterLegalization
argument_list|,
argument|std::vector<SDNode *> *Created
argument_list|)
specifier|const
block|;
comment|/// Targets may override this function to provide custom SDIV lowering for
comment|/// power-of-2 denominators.  If the target returns an empty SDValue, LLVM
comment|/// assumes SDIV is expensive and replaces it with a series of other integer
comment|/// operations.
name|virtual
name|SDValue
name|BuildSDIVPow2
argument_list|(
argument|SDNode *N
argument_list|,
argument|const APInt&Divisor
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|std::vector<SDNode *> *Created
argument_list|)
specifier|const
block|;
comment|/// Indicate whether this target prefers to combine FDIVs with the same
comment|/// divisor. If the transform should never be done, return zero. If the
comment|/// transform should be done, return the minimum number of divisor uses
comment|/// that must exist.
name|virtual
name|unsigned
name|combineRepeatedFPDivisors
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// Hooks for building estimates in place of slower divisions and square
comment|/// roots.
comment|/// Return either a square root or its reciprocal estimate value for the input
comment|/// operand.
comment|/// \p Enabled is a ReciprocalEstimate enum with value either 'Unspecified' or
comment|/// 'Enabled' as set by a potential default override attribute.
comment|/// If \p RefinementSteps is 'Unspecified', the number of Newton-Raphson
comment|/// refinement iterations required to generate a sufficient (though not
comment|/// necessarily IEEE-754 compliant) estimate is returned in that parameter.
comment|/// The boolean UseOneConstNR output is used to select a Newton-Raphson
comment|/// algorithm implementation that uses either one or two constants.
comment|/// The boolean Reciprocal is used to select whether the estimate is for the
comment|/// square root of the input operand or the reciprocal of its square root.
comment|/// A target may choose to implement its own refinement within this function.
comment|/// If that's true, then return '0' as the number of RefinementSteps to avoid
comment|/// any further refinement of the estimate.
comment|/// An empty SDValue return means no estimate sequence can be created.
name|virtual
name|SDValue
name|getSqrtEstimate
argument_list|(
argument|SDValue Operand
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|int Enabled
argument_list|,
argument|int&RefinementSteps
argument_list|,
argument|bool&UseOneConstNR
argument_list|,
argument|bool Reciprocal
argument_list|)
specifier|const
block|{
return|return
name|SDValue
argument_list|()
return|;
block|}
comment|/// Return a reciprocal estimate value for the input operand.
comment|/// \p Enabled is a ReciprocalEstimate enum with value either 'Unspecified' or
comment|/// 'Enabled' as set by a potential default override attribute.
comment|/// If \p RefinementSteps is 'Unspecified', the number of Newton-Raphson
comment|/// refinement iterations required to generate a sufficient (though not
comment|/// necessarily IEEE-754 compliant) estimate is returned in that parameter.
comment|/// A target may choose to implement its own refinement within this function.
comment|/// If that's true, then return '0' as the number of RefinementSteps to avoid
comment|/// any further refinement of the estimate.
comment|/// An empty SDValue return means no estimate sequence can be created.
name|virtual
name|SDValue
name|getRecipEstimate
argument_list|(
argument|SDValue Operand
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|int Enabled
argument_list|,
argument|int&RefinementSteps
argument_list|)
specifier|const
block|{
return|return
name|SDValue
argument_list|()
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Legalization utility functions
comment|//
comment|/// Expand a MUL or [US]MUL_LOHI of n-bit values into two or four nodes,
comment|/// respectively, each computing an n/2-bit part of the result.
comment|/// \param Result A vector that will be filled with the parts of the result
comment|///        in little-endian order.
comment|/// \param LL Low bits of the LHS of the MUL.  You can use this parameter
comment|///        if you want to control how low bits are extracted from the LHS.
comment|/// \param LH High bits of the LHS of the MUL.  See LL for meaning.
comment|/// \param RL Low bits of the RHS of the MUL.  See LL for meaning
comment|/// \param RH High bits of the RHS of the MUL.  See LL for meaning.
comment|/// \returns true if the node has been expanded, false if it has not
name|bool
name|expandMUL_LOHI
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|EVT VT
argument_list|,
argument|SDLoc dl
argument_list|,
argument|SDValue LHS
argument_list|,
argument|SDValue RHS
argument_list|,
argument|SmallVectorImpl<SDValue>&Result
argument_list|,
argument|EVT HiLoVT
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|MulExpansionKind Kind
argument_list|,
argument|SDValue LL = SDValue()
argument_list|,
argument|SDValue LH = SDValue()
argument_list|,
argument|SDValue RL = SDValue()
argument_list|,
argument|SDValue RH = SDValue()
argument_list|)
specifier|const
block|;
comment|/// Expand a MUL into two nodes.  One that computes the high bits of
comment|/// the result and one that computes the low bits.
comment|/// \param HiLoVT The value type to use for the Lo and Hi nodes.
comment|/// \param LL Low bits of the LHS of the MUL.  You can use this parameter
comment|///        if you want to control how low bits are extracted from the LHS.
comment|/// \param LH High bits of the LHS of the MUL.  See LL for meaning.
comment|/// \param RL Low bits of the RHS of the MUL.  See LL for meaning
comment|/// \param RH High bits of the RHS of the MUL.  See LL for meaning.
comment|/// \returns true if the node has been expanded. false if it has not
name|bool
name|expandMUL
argument_list|(
argument|SDNode *N
argument_list|,
argument|SDValue&Lo
argument_list|,
argument|SDValue&Hi
argument_list|,
argument|EVT HiLoVT
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|MulExpansionKind Kind
argument_list|,
argument|SDValue LL = SDValue()
argument_list|,
argument|SDValue LH = SDValue()
argument_list|,
argument|SDValue RL = SDValue()
argument_list|,
argument|SDValue RH = SDValue()
argument_list|)
specifier|const
block|;
comment|/// Expand float(f32) to SINT(i64) conversion
comment|/// \param N Node to expand
comment|/// \param Result output after conversion
comment|/// \returns True, if the expansion was successful, false otherwise
name|bool
name|expandFP_TO_SINT
argument_list|(
argument|SDNode *N
argument_list|,
argument|SDValue&Result
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// Turn load of vector type into a load of the individual elements.
comment|/// \param LD load to expand
comment|/// \returns MERGE_VALUEs of the scalar loads with their chains.
name|SDValue
name|scalarizeVectorLoad
argument_list|(
argument|LoadSDNode *LD
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|// Turn a store of a vector type into stores of the individual elements.
comment|/// \param ST Store with a vector value type
comment|/// \returns MERGE_VALUs of the individual store chains.
name|SDValue
name|scalarizeVectorStore
argument_list|(
argument|StoreSDNode *ST
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// Expands an unaligned load to 2 half-size loads for an integer, and
comment|/// possibly more for vectors.
name|std
operator|::
name|pair
operator|<
name|SDValue
block|,
name|SDValue
operator|>
name|expandUnalignedLoad
argument_list|(
argument|LoadSDNode *LD
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// Expands an unaligned store to 2 half-size stores for integer values, and
comment|/// possibly more for vectors.
name|SDValue
name|expandUnalignedStore
argument_list|(
argument|StoreSDNode *ST
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// Increments memory address \p Addr according to the type of the value
comment|/// \p DataVT that should be stored. If the data is stored in compressed
comment|/// form, the memory address should be incremented according to the number of
comment|/// the stored elements. This number is equal to the number of '1's bits
comment|/// in the \p Mask.
comment|/// \p DataVT is a vector type. \p Mask is a vector value.
comment|/// \p DataVT and \p Mask have the same number of vector elements.
name|SDValue
name|IncrementMemoryAddress
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue Mask
argument_list|,
argument|const SDLoc&DL
argument_list|,
argument|EVT DataVT
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|bool IsCompressedMemory
argument_list|)
specifier|const
block|;
comment|/// Get a pointer to vector element \p Idx located in memory for a vector of
comment|/// type \p VecVT starting at a base address of \p VecPtr. If \p Idx is out of
comment|/// bounds the returned pointer is unspecified, but will be within the vector
comment|/// bounds.
name|SDValue
name|getVectorElementPointer
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDValue VecPtr
argument_list|,
argument|EVT VecVT
argument_list|,
argument|SDValue Idx
argument_list|)
specifier|const
block|;
comment|//===--------------------------------------------------------------------===//
comment|// Instruction Emitting Hooks
comment|//
comment|/// This method should be implemented by targets that mark instructions with
comment|/// the 'usesCustomInserter' flag.  These instructions are special in various
comment|/// ways, which require special support to insert.  The specified MachineInstr
comment|/// is created but not inserted into any basic blocks, and this method is
comment|/// called to expand it into a sequence of instructions, potentially also
comment|/// creating new basic blocks and control flow.
comment|/// As long as the returned basic block is different (i.e., we created a new
comment|/// one), the custom inserter is free to modify the rest of \p MBB.
name|virtual
name|MachineBasicBlock
operator|*
name|EmitInstrWithCustomInserter
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
comment|/// This method should be implemented by targets that mark instructions with
comment|/// the 'hasPostISelHook' flag. These instructions must be adjusted after
comment|/// instruction selection by target hooks.  e.g. To fill in optional defs for
comment|/// ARM 's' setting instructions.
name|virtual
name|void
name|AdjustInstrPostInstrSelection
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|SDNode *Node
argument_list|)
specifier|const
block|;
comment|/// If this function returns true, SelectionDAGBuilder emits a
comment|/// LOAD_STACK_GUARD node when it is lowering Intrinsic::stackprotector.
name|virtual
name|bool
name|useLoadStackGuardNode
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Lower TLS global address SDNode for target independent emulated TLS model.
name|virtual
name|SDValue
name|LowerToTLSEmulatedModel
argument_list|(
argument|const GlobalAddressSDNode *GA
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|// seteq(x, 0) -> truncate(srl(ctlz(zext(x)), log2(#bits)))
comment|// If we're comparing for equality to zero and isCtlzFast is true, expose the
comment|// fact that this can be implemented as a ctlz/srl pair, so that the dag
comment|// combiner can fold the new nodes.
name|SDValue
name|lowerCmpEqZeroToCtlzSrl
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|private
operator|:
name|SDValue
name|simplifySetCCWithAnd
argument_list|(
argument|EVT VT
argument_list|,
argument|SDValue N0
argument_list|,
argument|SDValue N1
argument_list|,
argument|ISD::CondCode Cond
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|,
argument|const SDLoc&DL
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Given an LLVM IR type and return type attributes, compute the return value
end_comment

begin_comment
comment|/// EVTs and flags, and optionally also the offsets, if the return value is
end_comment

begin_comment
comment|/// being lowered to memory.
end_comment

begin_decl_stmt
name|void
name|GetReturnInfo
argument_list|(
name|Type
operator|*
name|ReturnType
argument_list|,
name|AttributeList
name|attr
argument_list|,
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|OutputArg
operator|>
operator|&
name|Outs
argument_list|,
specifier|const
name|TargetLowering
operator|&
name|TLI
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TARGET_TARGETLOWERING_H
end_comment

end_unit

