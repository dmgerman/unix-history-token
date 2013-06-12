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
comment|//
end_comment

begin_comment
comment|// This file describes how to lower LLVM code to machine code.  This has two
end_comment

begin_comment
comment|// main components:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  1. Which ValueTypes are natively supported by the target.
end_comment

begin_comment
comment|//  2. Which operations are supported for supported ValueTypes.
end_comment

begin_comment
comment|//  3. Cost thresholds for alternative implementations of certain operations.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// In addition it has a few other components, like information about FP
end_comment

begin_comment
comment|// immediates.
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
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/DAGCombine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/RuntimeLibcalls.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAGNodes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Attributes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallingConv.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/InlineAsm.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CallSite.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DebugLoc.h"
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
file|<climits>
end_include

begin_include
include|#
directive|include
file|<map>
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
name|CallInst
decl_stmt|;
name|class
name|CCState
decl_stmt|;
name|class
name|FastISel
decl_stmt|;
name|class
name|FunctionLoweringInfo
decl_stmt|;
name|class
name|ImmutableCallSite
decl_stmt|;
name|class
name|IntrinsicInst
decl_stmt|;
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
name|MCContext
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|class
name|TargetLibraryInfo
decl_stmt|;
name|class
name|TargetLoweringObjectFile
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
comment|/// TargetLoweringBase - This base class for TargetLowering contains the
comment|/// SelectionDAG-independent parts that can be used from the rest of CodeGen.
name|class
name|TargetLoweringBase
block|{
name|TargetLoweringBase
argument_list|(
argument|const TargetLoweringBase&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|TargetLoweringBase
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|public
label|:
comment|/// LegalizeAction - This enum indicates whether operations are valid for a
comment|/// target, and if not, what action should be used to make them valid.
enum|enum
name|LegalizeAction
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
name|Custom
comment|// Use the LowerOperation hook to implement custom lowering.
block|}
enum|;
comment|/// LegalizeTypeAction - This enum indicates whether a types are legal for a
comment|/// target, and if not, what action should be used to make them valid.
enum|enum
name|LegalizeTypeAction
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
comment|// Convert this float to a same size integer type.
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
comment|// This vector should be widened into a larger vector.
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
enum|enum
name|BooleanContent
block|{
comment|// How the target represents true/false values.
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
comment|/// NOTE: The constructor takes ownership of TLOF.
name|explicit
name|TargetLoweringBase
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|TargetLoweringObjectFile
operator|*
name|TLOF
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|TargetLoweringBase
argument_list|()
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
specifier|const
name|DataLayout
operator|*
name|getDataLayout
argument_list|()
specifier|const
block|{
return|return
name|TD
return|;
block|}
specifier|const
name|TargetLoweringObjectFile
operator|&
name|getObjFileLowering
argument_list|()
specifier|const
block|{
return|return
name|TLOF
return|;
block|}
name|bool
name|isBigEndian
argument_list|()
specifier|const
block|{
return|return
operator|!
name|IsLittleEndian
return|;
block|}
name|bool
name|isLittleEndian
argument_list|()
specifier|const
block|{
return|return
name|IsLittleEndian
return|;
block|}
comment|// Return the pointer type for the given address space, defaults to
comment|// the pointer type from the data layout.
comment|// FIXME: The default needs to be removed once all the code is updated.
name|virtual
name|MVT
name|getPointerTy
argument_list|(
name|uint32_t
name|AS
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|PointerTy
return|;
block|}
name|virtual
name|MVT
name|getScalarShiftAmountTy
argument_list|(
name|EVT
name|LHSTy
argument_list|)
decl|const
decl_stmt|;
name|EVT
name|getShiftAmountTy
argument_list|(
name|EVT
name|LHSTy
argument_list|)
decl|const
decl_stmt|;
comment|/// isSelectExpensive - Return true if the select operation is expensive for
comment|/// this target.
name|bool
name|isSelectExpensive
argument_list|()
specifier|const
block|{
return|return
name|SelectIsExpensive
return|;
block|}
name|virtual
name|bool
name|isSelectSupported
argument_list|(
name|SelectSupportKind
name|kind
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
comment|/// shouldSplitVectorElementType - Return true if a vector of the given type
comment|/// should be split (TypeSplitVector) instead of promoted
comment|/// (TypePromoteInteger) during type legalization.
name|virtual
name|bool
name|shouldSplitVectorElementType
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
comment|/// isIntDivCheap() - Return true if integer divide is usually cheaper than
comment|/// a sequence of several shifts, adds, and multiplies for this target.
name|bool
name|isIntDivCheap
argument_list|()
specifier|const
block|{
return|return
name|IntDivIsCheap
return|;
block|}
comment|/// isSlowDivBypassed - Returns true if target has indicated at least one
comment|/// type should be bypassed.
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
comment|/// getBypassSlowDivTypes - Returns map of slow types for division or
comment|/// remainder with corresponding fast types
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
comment|/// isPow2DivCheap() - Return true if pow2 div is cheaper than a chain of
comment|/// srl/add/sra.
name|bool
name|isPow2DivCheap
argument_list|()
specifier|const
block|{
return|return
name|Pow2DivIsCheap
return|;
block|}
comment|/// isJumpExpensive() - Return true if Flow Control is an expensive operation
comment|/// that should be avoided.
name|bool
name|isJumpExpensive
argument_list|()
specifier|const
block|{
return|return
name|JumpIsExpensive
return|;
block|}
comment|/// isPredictableSelectExpensive - Return true if selects are only cheaper
comment|/// than branches if the branch is unlikely to be predicted right.
name|bool
name|isPredictableSelectExpensive
argument_list|()
specifier|const
block|{
return|return
name|PredictableSelectIsExpensive
return|;
block|}
comment|/// getSetCCResultType - Return the ValueType of the result of SETCC
comment|/// operations.  Also used to obtain the target's preferred type for
comment|/// the condition operand of SELECT and BRCOND nodes.  In the case of
comment|/// BRCOND the argument passed is MVT::Other since there are no other
comment|/// operands to get a type hint from.
name|virtual
name|EVT
name|getSetCCResultType
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
decl_stmt|;
comment|/// getCmpLibcallReturnType - Return the ValueType for comparison
comment|/// libcalls. Comparions libcalls include floating point comparion calls,
comment|/// and Ordered/Unordered check calls on floating point numbers.
name|virtual
name|MVT
operator|::
name|SimpleValueType
name|getCmpLibcallReturnType
argument_list|()
specifier|const
expr_stmt|;
comment|/// getBooleanContents - For targets without i1 registers, this gives the
comment|/// nature of the high-bits of boolean values held in types wider than i1.
comment|/// "Boolean values" are special true/false values produced by nodes like
comment|/// SETCC and consumed (as the condition) by nodes like SELECT and BRCOND.
comment|/// Not to be confused with general values promoted from i1.
comment|/// Some cpus distinguish between vectors of boolean and scalars; the isVec
comment|/// parameter selects between the two kinds.  For example on X86 a scalar
comment|/// boolean should be zero extended from i1, while the elements of a vector
comment|/// of booleans should be sign extended from i1.
name|BooleanContent
name|getBooleanContents
argument_list|(
name|bool
name|isVec
argument_list|)
decl|const
block|{
return|return
name|isVec
condition|?
name|BooleanVectorContents
else|:
name|BooleanContents
return|;
block|}
comment|/// getSchedulingPreference - Return target scheduling preference.
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
comment|/// getSchedulingPreference - Some scheduler, e.g. hybrid, can switch to
comment|/// different scheduling heuristics for different nodes. This function returns
comment|/// the preference (or none) for the given node.
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
comment|/// getRegClassFor - Return the register class that should be used for the
comment|/// specified value type.
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
comment|/// getRepRegClassFor - Return the 'representative' register class for the
comment|/// specified value type. The 'representative' register class is the largest
comment|/// legal super-reg register class for the register class of the value type.
comment|/// For example, on i386 the rep register class for i8, i16, and i32 are GR32;
comment|/// while the rep register class is GR64 on x86_64.
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
comment|/// getRepRegClassCostFor - Return the cost of the 'representative' register
comment|/// class for the specified value type.
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
comment|/// isTypeLegal - Return true if the target has native support for the
comment|/// specified value type.  This means that it has a register that directly
comment|/// holds it without promotions or expansions.
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
literal|0
return|;
block|}
name|class
name|ValueTypeActionImpl
block|{
comment|/// ValueTypeActions - For each value type, keep a LegalizeTypeAction enum
comment|/// that indicates how instruction selection should deal with the type.
name|uint8_t
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
name|ValueTypeActions
argument_list|,
name|array_endof
argument_list|(
name|ValueTypeActions
argument_list|)
argument_list|,
literal|0
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
operator|(
name|LegalizeTypeAction
operator|)
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
name|unsigned
name|I
init|=
name|VT
operator|.
name|SimpleTy
decl_stmt|;
name|ValueTypeActions
index|[
name|I
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
comment|/// getTypeAction - Return how we should legalize values of this type, either
comment|/// it is already legal (return 'Legal') or we need to promote it to a larger
comment|/// type (return 'Promote'), or we need to expand it into multiple registers
comment|/// of smaller integer type (return 'Expand').  'Custom' is not an option.
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
comment|/// getTypeToTransformTo - For types supported by the target, this is an
comment|/// identity function.  For types that must be promoted to larger types, this
comment|/// returns the larger type to promote to.  For integer types that are larger
comment|/// than the largest integer register, this contains one step in the expansion
comment|/// to get to the smaller register. For illegal floating point types, this
comment|/// returns the integer type to transform to.
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
comment|/// getTypeToExpandTo - For types supported by the target, this is an
comment|/// identity function.  For types that must be expanded (i.e. integer types
comment|/// that are larger than the largest integer register or illegal floating
comment|/// point types), this returns the largest legal type it will be expanded to.
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
comment|/// getVectorTypeBreakdown - Vector types are broken down into some number of
comment|/// legal first class types.  For example, EVT::v8f32 maps to 2 EVT::v4f32
comment|/// with Altivec or SSE1, or 8 promoted EVT::f64 values with the X86 FP stack.
comment|/// Similarly, EVT::v2i64 turns into 4 EVT::i32 values with both PPC and X86.
comment|///
comment|/// This method returns the number of registers needed, and the VT for each
comment|/// register.  It also returns the VT and quantity of the intermediate values
comment|/// before they are promoted/expanded.
comment|///
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
comment|/// getTgtMemIntrinsic: Given an intrinsic, checks if on the target the
comment|/// intrinsic will need to map to a MemIntrinsicNode (touches memory). If
comment|/// this is the case, it returns true and store the intrinsic
comment|/// information into the IntrinsicInfo that was passed to the function.
struct|struct
name|IntrinsicInfo
block|{
name|unsigned
name|opc
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
decl_stmt|;
comment|// value representing memory location
name|int
name|offset
decl_stmt|;
comment|// offset off of ptrVal
name|unsigned
name|align
decl_stmt|;
comment|// alignment
name|bool
name|vol
decl_stmt|;
comment|// is volatile?
name|bool
name|readMem
decl_stmt|;
comment|// reads memory?
name|bool
name|writeMem
decl_stmt|;
comment|// writes memory?
block|}
struct|;
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
comment|/// isFPImmLegal - Returns true if the target can instruction select the
comment|/// specified FP immediate natively. If false, the legalizer will materialize
comment|/// the FP immediate as a load from a constant pool.
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
comment|/// isShuffleMaskLegal - Targets can use this to indicate that they only
comment|/// support *some* VECTOR_SHUFFLE operations, those with specific masks.
comment|/// By default, if a target supports the VECTOR_SHUFFLE node, all mask values
comment|/// are assumed to be legal.
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
comment|/// canOpTrap - Returns true if the operation can trap for the value type.
comment|/// VT must be a legal type. By default, we optimistically assume most
comment|/// operations don't trap except for divide and remainder.
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
comment|/// isVectorClearMaskLegal - Similar to isShuffleMaskLegal. This is
comment|/// used by Targets can use this to indicate if there is a suitable
comment|/// VECTOR_SHUFFLE that can be used to replace a VAND with a constant
comment|/// pool entry.
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
comment|/// getOperationAction - Return how this operation should be treated: either
comment|/// it is legal, needs to be promoted to a larger size, needs to be
comment|/// expanded to some other code sequence, or the target has a custom expander
comment|/// for it.
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
name|unsigned
name|I
init|=
operator|(
name|unsigned
operator|)
name|VT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
decl_stmt|;
return|return
operator|(
name|LegalizeAction
operator|)
name|OpActions
index|[
name|I
index|]
index|[
name|Op
index|]
return|;
block|}
comment|/// isOperationLegalOrCustom - Return true if the specified operation is
comment|/// legal on this target or can be made legal with custom lowering. This
comment|/// is used to help guide high-level lowering decisions.
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
comment|/// isOperationLegalOrPromote - Return true if the specified operation is
comment|/// legal on this target or can be made legal using promotion. This
comment|/// is used to help guide high-level lowering decisions.
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
comment|/// isOperationExpand - Return true if the specified operation is illegal on
comment|/// this target or unlikely to be made legal with custom lowering. This is
comment|/// used to help guide high-level lowering decisions.
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
comment|/// isOperationLegal - Return true if the specified operation is legal on this
comment|/// target.
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
comment|/// getLoadExtAction - Return how this load with extension should be treated:
comment|/// either it is legal, needs to be promoted to a larger size, needs to be
comment|/// expanded to some other code sequence, or the target has a custom expander
comment|/// for it.
name|LegalizeAction
name|getLoadExtAction
argument_list|(
name|unsigned
name|ExtType
argument_list|,
name|MVT
name|VT
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|ExtType
operator|<
name|ISD
operator|::
name|LAST_LOADEXT_TYPE
operator|&&
name|VT
operator|<
name|MVT
operator|::
name|LAST_VALUETYPE
operator|&&
literal|"Table isn't big enough!"
argument_list|)
expr_stmt|;
return|return
operator|(
name|LegalizeAction
operator|)
name|LoadExtActions
index|[
name|VT
operator|.
name|SimpleTy
index|]
index|[
name|ExtType
index|]
return|;
block|}
comment|/// isLoadExtLegal - Return true if the specified load with extension is legal
comment|/// on this target.
name|bool
name|isLoadExtLegal
argument_list|(
name|unsigned
name|ExtType
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
name|getLoadExtAction
argument_list|(
name|ExtType
argument_list|,
name|VT
operator|.
name|getSimpleVT
argument_list|()
argument_list|)
operator|==
name|Legal
return|;
block|}
comment|/// getTruncStoreAction - Return how this store with truncation should be
comment|/// treated: either it is legal, needs to be promoted to a larger size, needs
comment|/// to be expanded to some other code sequence, or the target has a custom
comment|/// expander for it.
name|LegalizeAction
name|getTruncStoreAction
argument_list|(
name|MVT
name|ValVT
argument_list|,
name|MVT
name|MemVT
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|ValVT
operator|<
name|MVT
operator|::
name|LAST_VALUETYPE
operator|&&
name|MemVT
operator|<
name|MVT
operator|::
name|LAST_VALUETYPE
operator|&&
literal|"Table isn't big enough!"
argument_list|)
expr_stmt|;
return|return
operator|(
name|LegalizeAction
operator|)
name|TruncStoreActions
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
return|;
block|}
comment|/// isTruncStoreLegal - Return true if the specified store with truncation is
comment|/// legal on this target.
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
name|MemVT
operator|.
name|isSimple
argument_list|()
operator|&&
name|getTruncStoreAction
argument_list|(
name|ValVT
operator|.
name|getSimpleVT
argument_list|()
argument_list|,
name|MemVT
operator|.
name|getSimpleVT
argument_list|()
argument_list|)
operator|==
name|Legal
return|;
block|}
comment|/// getIndexedLoadAction - Return how the indexed load should be treated:
comment|/// either it is legal, needs to be promoted to a larger size, needs to be
comment|/// expanded to some other code sequence, or the target has a custom expander
comment|/// for it.
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
operator|<
name|MVT
operator|::
name|LAST_VALUETYPE
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
comment|/// isIndexedLoadLegal - Return true if the specified indexed load is legal
comment|/// on this target.
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
comment|/// getIndexedStoreAction - Return how the indexed store should be treated:
comment|/// either it is legal, needs to be promoted to a larger size, needs to be
comment|/// expanded to some other code sequence, or the target has a custom expander
comment|/// for it.
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
operator|<
name|MVT
operator|::
name|LAST_VALUETYPE
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
comment|/// isIndexedStoreLegal - Return true if the specified indexed load is legal
comment|/// on this target.
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
comment|/// getCondCodeAction - Return how the condition code should be treated:
comment|/// either it is legal, needs to be expanded to some other code sequence,
comment|/// or the target has a custom expander for it.
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
name|unsigned
operator|)
name|VT
operator|.
name|SimpleTy
operator|<
sizeof|sizeof
argument_list|(
name|CondCodeActions
index|[
literal|0
index|]
argument_list|)
operator|*
literal|4
operator|&&
literal|"Table isn't big enough!"
argument_list|)
expr_stmt|;
comment|/// The lower 5 bits of the SimpleTy index into Nth 2bit set from the 64bit
comment|/// value and the upper 27 bits index into the second dimension of the
comment|/// array to select what 64bit value to use.
name|LegalizeAction
name|Action
init|=
call|(
name|LegalizeAction
call|)
argument_list|(
operator|(
name|CondCodeActions
index|[
name|CC
index|]
index|[
name|VT
operator|.
name|SimpleTy
operator|>>
literal|5
index|]
operator|>>
operator|(
literal|2
operator|*
operator|(
name|VT
operator|.
name|SimpleTy
operator|&
literal|0x1F
operator|)
operator|)
operator|)
operator|&
literal|3
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
comment|/// isCondCodeLegal - Return true if the specified condition code is legal
comment|/// on this target.
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
comment|/// getTypeToPromoteTo - If the action for this operation is to promote, this
comment|/// method returns the ValueType to promote to.
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
comment|/// getValueType - Return the EVT corresponding to this LLVM type.
comment|/// This is fixed by the LLVM operations except for the pointer size.  If
comment|/// AllowUnknown is true, this will return MVT::Other for types with no EVT
comment|/// counterpart (e.g. structs), otherwise it will assert.
name|EVT
name|getValueType
argument_list|(
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
name|Ty
operator|->
name|isPointerTy
argument_list|()
condition|)
return|return
name|PointerTy
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
name|Elm
operator|->
name|isPointerTy
argument_list|()
condition|)
name|Elm
operator|=
name|EVT
argument_list|(
name|PointerTy
argument_list|)
operator|.
name|getTypeForEVT
argument_list|(
name|Ty
operator|->
name|getContext
argument_list|()
argument_list|)
expr_stmt|;
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
name|Ty
argument_list|,
name|AllowUnknown
argument_list|)
operator|.
name|getSimpleVT
argument_list|()
return|;
block|}
comment|/// getByValTypeAlignment - Return the desired alignment for ByVal aggregate
comment|/// function arguments in the caller parameter area.  This is the actual
comment|/// alignment, not its logarithm.
name|virtual
name|unsigned
name|getByValTypeAlignment
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// getRegisterType - Return the type of registers that this ValueType will
comment|/// eventually require.
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
comment|/// getRegisterType - Return the type of registers that this ValueType will
comment|/// eventually require.
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
comment|/// getNumRegisters - Return the number of registers that this ValueType will
comment|/// eventually require.  This is one for any types promoted to live in larger
comment|/// registers, but may be more than one for types (like i64) that are split
comment|/// into pieces.  For types like i140, which are first promoted then expanded,
comment|/// it is the number of registers needed to hold all the bits of the original
comment|/// type.  For an i140 on a 32 bit machine this means 5 registers.
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
comment|/// ShouldShrinkFPConstant - If true, then instruction selection should
comment|/// seek to shrink the FP constant of the specified type to a smaller type
comment|/// in order to save space and / or reduce runtime.
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
comment|/// hasTargetDAGCombine - If true, the target has custom DAG combine
comment|/// transformations that it can perform for the specified node.
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
comment|/// This function returns the maximum number of store operations permitted
comment|/// to replace a call to llvm.memset. The value is set by the target at the
comment|/// performance threshold for such a replacement. If OptSize is true,
comment|/// return the limit for functions that have OptSize attribute.
comment|/// @brief Get maximum # of store operations permitted for llvm.memset
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
comment|/// This function returns the maximum number of store operations permitted
comment|/// to replace a call to llvm.memcpy. The value is set by the target at the
comment|/// performance threshold for such a replacement. If OptSize is true,
comment|/// return the limit for functions that have OptSize attribute.
comment|/// @brief Get maximum # of store operations permitted for llvm.memcpy
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
comment|/// This function returns the maximum number of store operations permitted
comment|/// to replace a call to llvm.memmove. The value is set by the target at the
comment|/// performance threshold for such a replacement. If OptSize is true,
comment|/// return the limit for functions that have OptSize attribute.
comment|/// @brief Get maximum # of store operations permitted for llvm.memmove
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
comment|/// This function returns true if the target allows unaligned memory accesses.
comment|/// of the specified type. If true, it also returns whether the unaligned
comment|/// memory access is "fast" in the second argument by reference. This is used,
comment|/// for example, in situations where an array copy/move/set is  converted to a
comment|/// sequence of store operations. It's use helps to ensure that such
comment|/// replacements don't generate code that causes an alignment error  (trap) on
comment|/// the target machine.
comment|/// @brief Determine if the target supports unaligned memory accesses.
name|virtual
name|bool
name|allowsUnalignedMemoryAccesses
argument_list|(
name|EVT
argument_list|,
name|bool
operator|*
name|Fast
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// getOptimalMemOpType - Returns the target specific optimal type for load
comment|/// and store operations as a result of memset, memcpy, and memmove
comment|/// lowering. If DstAlign is zero that means it's safe to destination
comment|/// alignment can satisfy any constraint. Similarly if SrcAlign is zero it
comment|/// means there isn't a need to check it against alignment requirement,
comment|/// probably because the source does not need to be loaded. If 'IsMemset' is
comment|/// true, that means it's expanding a memset. If 'ZeroMemset' is true, that
comment|/// means it's a memset of zero. 'MemcpyStrSrc' indicates whether the memcpy
comment|/// source is constant so it does not need to be loaded.
comment|/// It returns EVT::Other if the type should be determined using generic
comment|/// target-independent logic.
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
comment|/// isSafeMemOpType - Returns true if it's safe to use load / store of the
comment|/// specified type to expand memcpy / memset inline. This is mostly true
comment|/// for all types except for some special cases. For example, on X86
comment|/// targets without SSE2 f64 load / store are done with fldl / fstpl which
comment|/// also does type conversion. Note the specified type doesn't have to be
comment|/// legal as the hook is used before type legalization.
name|virtual
name|bool
name|isSafeMemOpType
argument_list|(
name|MVT
name|VT
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
comment|/// usesUnderscoreSetJmp - Determine if we should use _setjmp or setjmp
comment|/// to implement llvm.setjmp.
name|bool
name|usesUnderscoreSetJmp
argument_list|()
specifier|const
block|{
return|return
name|UseUnderscoreSetJmp
return|;
block|}
comment|/// usesUnderscoreLongJmp - Determine if we should use _longjmp or longjmp
comment|/// to implement llvm.longjmp.
name|bool
name|usesUnderscoreLongJmp
argument_list|()
specifier|const
block|{
return|return
name|UseUnderscoreLongJmp
return|;
block|}
comment|/// supportJumpTables - return whether the target can generate code for
comment|/// jump tables.
name|bool
name|supportJumpTables
argument_list|()
specifier|const
block|{
return|return
name|SupportJumpTables
return|;
block|}
comment|/// getMinimumJumpTableEntries - return integer threshold on number of
comment|/// blocks to use jump tables rather than if sequence.
name|int
name|getMinimumJumpTableEntries
argument_list|()
specifier|const
block|{
return|return
name|MinimumJumpTableEntries
return|;
block|}
comment|/// getStackPointerRegisterToSaveRestore - If a physical register, this
comment|/// specifies the register that llvm.savestack/llvm.restorestack should save
comment|/// and restore.
name|unsigned
name|getStackPointerRegisterToSaveRestore
argument_list|()
specifier|const
block|{
return|return
name|StackPointerRegisterToSaveRestore
return|;
block|}
comment|/// getExceptionPointerRegister - If a physical register, this returns
comment|/// the register that receives the exception address on entry to a landing
comment|/// pad.
name|unsigned
name|getExceptionPointerRegister
argument_list|()
specifier|const
block|{
return|return
name|ExceptionPointerRegister
return|;
block|}
comment|/// getExceptionSelectorRegister - If a physical register, this returns
comment|/// the register that receives the exception typeid on entry to a landing
comment|/// pad.
name|unsigned
name|getExceptionSelectorRegister
argument_list|()
specifier|const
block|{
return|return
name|ExceptionSelectorRegister
return|;
block|}
comment|/// getJumpBufSize - returns the target's jmp_buf size in bytes (if never
comment|/// set, the default is 200)
name|unsigned
name|getJumpBufSize
argument_list|()
specifier|const
block|{
return|return
name|JumpBufSize
return|;
block|}
comment|/// getJumpBufAlignment - returns the target's jmp_buf alignment in bytes
comment|/// (if never set, the default is 0)
name|unsigned
name|getJumpBufAlignment
argument_list|()
specifier|const
block|{
return|return
name|JumpBufAlignment
return|;
block|}
comment|/// getMinStackArgumentAlignment - return the minimum stack alignment of an
comment|/// argument.
name|unsigned
name|getMinStackArgumentAlignment
argument_list|()
specifier|const
block|{
return|return
name|MinStackArgumentAlignment
return|;
block|}
comment|/// getMinFunctionAlignment - return the minimum function alignment.
comment|///
name|unsigned
name|getMinFunctionAlignment
argument_list|()
specifier|const
block|{
return|return
name|MinFunctionAlignment
return|;
block|}
comment|/// getPrefFunctionAlignment - return the preferred function alignment.
comment|///
name|unsigned
name|getPrefFunctionAlignment
argument_list|()
specifier|const
block|{
return|return
name|PrefFunctionAlignment
return|;
block|}
comment|/// getPrefLoopAlignment - return the preferred loop alignment.
comment|///
name|unsigned
name|getPrefLoopAlignment
argument_list|()
specifier|const
block|{
return|return
name|PrefLoopAlignment
return|;
block|}
comment|/// getInsertFencesFor - return whether the DAG builder should automatically
comment|/// insert fences and reduce ordering for atomics.
comment|///
name|bool
name|getInsertFencesForAtomic
argument_list|()
specifier|const
block|{
return|return
name|InsertFencesForAtomic
return|;
block|}
comment|/// getStackCookieLocation - Return true if the target stores stack
comment|/// protector cookies at a fixed offset in some non-standard address
comment|/// space, and populates the address space and offset as
comment|/// appropriate.
name|virtual
name|bool
name|getStackCookieLocation
argument_list|(
name|unsigned
operator|&
comment|/*AddressSpace*/
argument_list|,
name|unsigned
operator|&
comment|/*Offset*/
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// getMaximalGlobalOffset - Returns the maximal possible offset which can be
comment|/// used for loads / stores from the global.
name|virtual
name|unsigned
name|getMaximalGlobalOffset
argument_list|()
specifier|const
block|{
return|return
literal|0
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
name|unsigned
operator|,
name|MVT
operator|>
name|getTypeLegalizationCost
argument_list|(
argument|Type *Ty
argument_list|)
specifier|const
expr_stmt|;
comment|/// @}
comment|//===--------------------------------------------------------------------===//
comment|// TargetLowering Configuration Methods - These methods should be invoked by
comment|// the derived class constructor to configure this object for the target.
comment|//
comment|/// \brief Reset the operation actions based on target options.
name|virtual
name|void
name|resetOperationActions
parameter_list|()
block|{}
name|protected
label|:
comment|/// setBooleanContents - Specify how the target extends the result of a
comment|/// boolean value from i1 to a wider type.  See getBooleanContents.
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
block|}
comment|/// setBooleanVectorContents - Specify how the target extends the result
comment|/// of a vector boolean value from a vector of i1 to a wider type.  See
comment|/// getBooleanContents.
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
comment|/// setSchedulingPreference - Specify the target scheduling preference.
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
comment|/// setUseUnderscoreSetJmp - Indicate whether this target prefers to
comment|/// use _setjmp to implement llvm.setjmp or the non _ version.
comment|/// Defaults to false.
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
comment|/// setUseUnderscoreLongJmp - Indicate whether this target prefers to
comment|/// use _longjmp to implement llvm.longjmp or the non _ version.
comment|/// Defaults to false.
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
comment|/// setSupportJumpTables - Indicate whether the target can generate code for
comment|/// jump tables.
name|void
name|setSupportJumpTables
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|SupportJumpTables
operator|=
name|Val
expr_stmt|;
block|}
comment|/// setMinimumJumpTableEntries - Indicate the number of blocks to generate
comment|/// jump tables rather than if sequence.
name|void
name|setMinimumJumpTableEntries
parameter_list|(
name|int
name|Val
parameter_list|)
block|{
name|MinimumJumpTableEntries
operator|=
name|Val
expr_stmt|;
block|}
comment|/// setStackPointerRegisterToSaveRestore - If set to a physical register, this
comment|/// specifies the register that llvm.savestack/llvm.restorestack should save
comment|/// and restore.
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
comment|/// setExceptionPointerRegister - If set to a physical register, this sets
comment|/// the register that receives the exception address on entry to a landing
comment|/// pad.
name|void
name|setExceptionPointerRegister
parameter_list|(
name|unsigned
name|R
parameter_list|)
block|{
name|ExceptionPointerRegister
operator|=
name|R
expr_stmt|;
block|}
comment|/// setExceptionSelectorRegister - If set to a physical register, this sets
comment|/// the register that receives the exception typeid on entry to a landing
comment|/// pad.
name|void
name|setExceptionSelectorRegister
parameter_list|(
name|unsigned
name|R
parameter_list|)
block|{
name|ExceptionSelectorRegister
operator|=
name|R
expr_stmt|;
block|}
comment|/// SelectIsExpensive - Tells the code generator not to expand operations
comment|/// into sequences that use the select operations if possible.
name|void
name|setSelectIsExpensive
parameter_list|(
name|bool
name|isExpensive
init|=
name|true
parameter_list|)
block|{
name|SelectIsExpensive
operator|=
name|isExpensive
expr_stmt|;
block|}
comment|/// JumpIsExpensive - Tells the code generator not to expand sequence of
comment|/// operations into a separate sequences that increases the amount of
comment|/// flow control.
name|void
name|setJumpIsExpensive
parameter_list|(
name|bool
name|isExpensive
init|=
name|true
parameter_list|)
block|{
name|JumpIsExpensive
operator|=
name|isExpensive
expr_stmt|;
block|}
comment|/// setIntDivIsCheap - Tells the code generator that integer divide is
comment|/// expensive, and if possible, should be replaced by an alternate sequence
comment|/// of instructions not containing an integer divide.
name|void
name|setIntDivIsCheap
parameter_list|(
name|bool
name|isCheap
init|=
name|true
parameter_list|)
block|{
name|IntDivIsCheap
operator|=
name|isCheap
expr_stmt|;
block|}
comment|/// addBypassSlowDiv - Tells the code generator which bitwidths to bypass.
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
comment|/// setPow2DivIsCheap - Tells the code generator that it shouldn't generate
comment|/// srl/add/sra for a signed divide by power of two, and let the target handle
comment|/// it.
name|void
name|setPow2DivIsCheap
parameter_list|(
name|bool
name|isCheap
init|=
name|true
parameter_list|)
block|{
name|Pow2DivIsCheap
operator|=
name|isCheap
expr_stmt|;
block|}
comment|/// addRegisterClass - Add the specified register class as an available
comment|/// regclass for the specified value type.  This indicates the selector can
comment|/// handle values of that class natively.
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
name|AvailableRegClasses
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|VT
argument_list|,
name|RC
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
comment|/// clearRegisterClasses - Remove all register classes.
name|void
name|clearRegisterClasses
parameter_list|()
block|{
name|memset
argument_list|(
name|RegClassForVT
argument_list|,
literal|0
argument_list|,
name|MVT
operator|::
name|LAST_VALUETYPE
operator|*
sizeof|sizeof
argument_list|(
name|TargetRegisterClass
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|AvailableRegClasses
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|/// \brief Remove all operation actions.
name|void
name|clearOperationActions
parameter_list|()
block|{   }
comment|/// findRepresentativeClass - Return the largest legal super-reg register class
comment|/// of the register class for the specified type and its associated "cost".
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
argument|MVT VT
argument_list|)
specifier|const
expr_stmt|;
comment|/// computeRegisterProperties - Once all of the register classes are added,
comment|/// this allows us to compute derived properties we expose.
name|void
name|computeRegisterProperties
parameter_list|()
function_decl|;
comment|/// setOperationAction - Indicate that the specified operation does not work
comment|/// with the specified type and indicate what to do about it.
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
operator|(
name|uint8_t
operator|)
name|Action
expr_stmt|;
block|}
comment|/// setLoadExtAction - Indicate that the specified load with extension does
comment|/// not work with the specified type and indicate what to do about it.
name|void
name|setLoadExtAction
parameter_list|(
name|unsigned
name|ExtType
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
name|ExtType
operator|<
name|ISD
operator|::
name|LAST_LOADEXT_TYPE
operator|&&
name|VT
operator|<
name|MVT
operator|::
name|LAST_VALUETYPE
operator|&&
literal|"Table isn't big enough!"
argument_list|)
expr_stmt|;
name|LoadExtActions
index|[
name|VT
operator|.
name|SimpleTy
index|]
index|[
name|ExtType
index|]
operator|=
operator|(
name|uint8_t
operator|)
name|Action
expr_stmt|;
block|}
comment|/// setTruncStoreAction - Indicate that the specified truncating store does
comment|/// not work with the specified type and indicate what to do about it.
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
operator|<
name|MVT
operator|::
name|LAST_VALUETYPE
operator|&&
name|MemVT
operator|<
name|MVT
operator|::
name|LAST_VALUETYPE
operator|&&
literal|"Table isn't big enough!"
argument_list|)
expr_stmt|;
name|TruncStoreActions
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
operator|=
operator|(
name|uint8_t
operator|)
name|Action
expr_stmt|;
block|}
comment|/// setIndexedLoadAction - Indicate that the specified indexed load does or
comment|/// does not work with the specified type and indicate what to do abort
comment|/// it. NOTE: All indexed mode loads are initialized to Expand in
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
operator|<
name|MVT
operator|::
name|LAST_VALUETYPE
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
comment|/// setIndexedStoreAction - Indicate that the specified indexed store does or
comment|/// does not work with the specified type and indicate what to do about
comment|/// it. NOTE: All indexed mode stores are initialized to Expand in
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
operator|<
name|MVT
operator|::
name|LAST_VALUETYPE
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
comment|/// setCondCodeAction - Indicate that the specified condition code is or isn't
comment|/// supported on the target and indicate what to do about it.
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
operator|<
name|MVT
operator|::
name|LAST_VALUETYPE
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
comment|/// The lower 5 bits of the SimpleTy index into Nth 2bit set from the 64bit
comment|/// value and the upper 27 bits index into the second dimension of the
comment|/// array to select what 64bit value to use.
name|CondCodeActions
index|[
operator|(
name|unsigned
operator|)
name|CC
index|]
index|[
name|VT
operator|.
name|SimpleTy
operator|>>
literal|5
index|]
operator|&=
operator|~
operator|(
name|uint64_t
argument_list|(
literal|3UL
argument_list|)
operator|<<
operator|(
name|VT
operator|.
name|SimpleTy
operator|&
literal|0x1F
operator|)
operator|*
literal|2
operator|)
expr_stmt|;
name|CondCodeActions
index|[
operator|(
name|unsigned
operator|)
name|CC
index|]
index|[
name|VT
operator|.
name|SimpleTy
operator|>>
literal|5
index|]
operator||=
operator|(
name|uint64_t
operator|)
name|Action
operator|<<
operator|(
name|VT
operator|.
name|SimpleTy
operator|&
literal|0x1F
operator|)
operator|*
literal|2
expr_stmt|;
block|}
comment|/// AddPromotedToType - If Opc/OrigVT is specified as being promoted, the
comment|/// promotion code defaults to trying a larger integer/fp until it can find
comment|/// one that works.  If that default is insufficient, this method can be used
comment|/// by the target to override the default.
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
comment|/// setTargetDAGCombine - Targets should invoke this method for each target
comment|/// independent node that they want to provide a custom DAG combiner for by
comment|/// implementing the PerformDAGCombine virtual method.
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
comment|/// setJumpBufSize - Set the target's required jmp_buf buffer size (in
comment|/// bytes); default is 200
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
comment|/// setJumpBufAlignment - Set the target's required jmp_buf buffer
comment|/// alignment (in bytes); default is 0
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
comment|/// setMinFunctionAlignment - Set the target's minimum function alignment (in
comment|/// log2(bytes))
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
comment|/// setPrefFunctionAlignment - Set the target's preferred function alignment.
comment|/// This should be set if there is a performance benefit to
comment|/// higher-than-minimum alignment (in log2(bytes))
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
comment|/// setPrefLoopAlignment - Set the target's preferred loop alignment. Default
comment|/// alignment is zero, it means the target does not care about loop alignment.
comment|/// The alignment is specified in log2(bytes).
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
comment|/// setMinStackArgumentAlignment - Set the minimum stack alignment of an
comment|/// argument (in log2(bytes)).
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
comment|/// setInsertFencesForAtomic - Set if the DAG builder should
comment|/// automatically insert fences and reduce the order of atomic memory
comment|/// operations to Monotonic.
name|void
name|setInsertFencesForAtomic
parameter_list|(
name|bool
name|fence
parameter_list|)
block|{
name|InsertFencesForAtomic
operator|=
name|fence
expr_stmt|;
block|}
name|public
label|:
comment|//===--------------------------------------------------------------------===//
comment|// Addressing mode description hooks (used by LSR etc).
comment|//
comment|/// GetAddrModeArguments - CodeGenPrepare sinks address calculations into the
comment|/// same BB as Load/Store instructions reading the address.  This allows as
comment|/// much computation as possible to be done in the address mode for that
comment|/// operand.  This hook lets targets also pass back when this should be done
comment|/// on intrinsics which load/store.
name|virtual
name|bool
name|GetAddrModeArguments
argument_list|(
name|IntrinsicInst
operator|*
name|I
argument_list|,
name|SmallVectorImpl
operator|<
name|Value
operator|*
operator|>
operator|&
name|Ops
argument_list|,
name|Type
operator|*
operator|&
name|AccessTy
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// AddrMode - This represents an addressing mode of:
comment|///    BaseGV + BaseOffs + BaseReg + Scale*ScaleReg
comment|/// If BaseGV is null,  there is no BaseGV.
comment|/// If BaseOffs is zero, there is no base offset.
comment|/// If HasBaseReg is false, there is no base register.
comment|/// If Scale is zero, there is no ScaleReg.  Scale of 1 indicates a reg with
comment|/// no scale.
comment|///
struct|struct
name|AddrMode
block|{
name|GlobalValue
modifier|*
name|BaseGV
decl_stmt|;
name|int64_t
name|BaseOffs
decl_stmt|;
name|bool
name|HasBaseReg
decl_stmt|;
name|int64_t
name|Scale
decl_stmt|;
name|AddrMode
argument_list|()
operator|:
name|BaseGV
argument_list|(
literal|0
argument_list|)
operator|,
name|BaseOffs
argument_list|(
literal|0
argument_list|)
operator|,
name|HasBaseReg
argument_list|(
name|false
argument_list|)
operator|,
name|Scale
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
comment|/// isLegalAddressingMode - Return true if the addressing mode represented by
comment|/// AM is legal for this target, for a load/store of the specified type.
comment|/// The type may be VoidTy, in which case only return true if the addressing
comment|/// mode is legal for a load/store of any legal type.
comment|/// TODO: Handle pre/postinc as well.
name|virtual
name|bool
name|isLegalAddressingMode
argument_list|(
specifier|const
name|AddrMode
operator|&
name|AM
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// isLegalICmpImmediate - Return true if the specified immediate is legal
comment|/// icmp immediate, that is the target has icmp instructions which can compare
comment|/// a register against the immediate without having to materialize the
comment|/// immediate into a register.
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
comment|/// isLegalAddImmediate - Return true if the specified immediate is legal
comment|/// add immediate, that is the target has add instructions which can add
comment|/// a register with the immediate without having to materialize the
comment|/// immediate into a register.
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
comment|/// isTruncateFree - Return true if it's free to truncate a value of
comment|/// type Ty1 to type Ty2. e.g. On x86 it's free to truncate a i32 value in
comment|/// register EAX to i16 by referencing its sub-register AX.
name|virtual
name|bool
name|isTruncateFree
argument_list|(
name|Type
operator|*
comment|/*Ty1*/
argument_list|,
name|Type
operator|*
comment|/*Ty2*/
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
comment|/// isZExtFree - Return true if any actual instruction that defines a
comment|/// value of type Ty1 implicitly zero-extends the value to Ty2 in the result
comment|/// register. This does not necessarily include registers defined in
comment|/// unknown ways, such as incoming arguments, or copies from unknown
comment|/// virtual registers. Also, if isTruncateFree(Ty2, Ty1) is true, this
comment|/// does not necessarily apply to truncate instructions. e.g. on x86-64,
comment|/// all instructions that define 32-bit values implicit zero-extend the
comment|/// result out to 64 bits.
name|virtual
name|bool
name|isZExtFree
argument_list|(
name|Type
operator|*
comment|/*Ty1*/
argument_list|,
name|Type
operator|*
comment|/*Ty2*/
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
comment|/// isZExtFree - Return true if zero-extending the specific node Val to type
comment|/// VT2 is free (either because it's implicitly zero-extended such as ARM
comment|/// ldrb / ldrh or because it's folded such as X86 zero-extending loads).
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
comment|/// isFNegFree - Return true if an fneg operation is free to the point where
comment|/// it is never worthwhile to replace it with a bitwise operation.
name|virtual
name|bool
name|isFNegFree
argument_list|(
name|EVT
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// isFAbsFree - Return true if an fneg operation is free to the point where
comment|/// it is never worthwhile to replace it with a bitwise operation.
name|virtual
name|bool
name|isFAbsFree
argument_list|(
name|EVT
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// isFMAFasterThanMulAndAdd - Return true if an FMA operation is faster than
comment|/// a pair of mul and add instructions. fmuladd intrinsics will be expanded to
comment|/// FMAs when this method returns true (and FMAs are legal), otherwise fmuladd
comment|/// is expanded to mul + add.
name|virtual
name|bool
name|isFMAFasterThanMulAndAdd
argument_list|(
name|EVT
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// isNarrowingProfitable - Return true if it's profitable to narrow
comment|/// operations of type VT1 to VT2. e.g. on x86, it's profitable to narrow
comment|/// from i32 to i8 but not from i32 to i16.
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
comment|//===--------------------------------------------------------------------===//
comment|// Runtime Library hooks
comment|//
comment|/// setLibcallName - Rename the default libcall routine name for the specified
comment|/// libcall.
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
comment|/// getLibcallName - Get the libcall routine name for the specified libcall.
comment|///
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
comment|/// setCmpLibcallCC - Override the default CondCode to be used to test the
comment|/// result of the comparison libcall against zero.
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
comment|/// getCmpLibcallCC - Get the CondCode that's to be used to test the result of
comment|/// the comparison libcall against zero.
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
comment|/// setLibcallCallingConv - Set the CallingConv that should be used for the
comment|/// specified libcall.
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
comment|/// getLibcallCallingConv - Get the CallingConv that should be used for the
comment|/// specified libcall.
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
name|private
label|:
specifier|const
name|TargetMachine
modifier|&
name|TM
decl_stmt|;
specifier|const
name|DataLayout
modifier|*
name|TD
decl_stmt|;
specifier|const
name|TargetLoweringObjectFile
modifier|&
name|TLOF
decl_stmt|;
comment|/// PointerTy - The type to use for pointers for the default address space,
comment|/// usually i32 or i64.
comment|///
name|MVT
name|PointerTy
decl_stmt|;
comment|/// IsLittleEndian - True if this is a little endian target.
comment|///
name|bool
name|IsLittleEndian
decl_stmt|;
comment|/// SelectIsExpensive - Tells the code generator not to expand operations
comment|/// into sequences that use the select operations if possible.
name|bool
name|SelectIsExpensive
decl_stmt|;
comment|/// IntDivIsCheap - Tells the code generator not to expand integer divides by
comment|/// constants into a sequence of muls, adds, and shifts.  This is a hack until
comment|/// a real cost model is in place.  If we ever optimize for size, this will be
comment|/// set to true unconditionally.
name|bool
name|IntDivIsCheap
decl_stmt|;
comment|/// BypassSlowDivMap - Tells the code generator to bypass slow divide or
comment|/// remainder instructions. For example, BypassSlowDivWidths[32,8] tells the
comment|/// code generator to bypass 32-bit integer div/rem with an 8-bit unsigned
comment|/// integer div/rem when the operands are positive and less than 256.
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
comment|/// Pow2DivIsCheap - Tells the code generator that it shouldn't generate
comment|/// srl/add/sra for a signed divide by power of two, and let the target handle
comment|/// it.
name|bool
name|Pow2DivIsCheap
decl_stmt|;
comment|/// JumpIsExpensive - Tells the code generator that it shouldn't generate
comment|/// extra flow control instructions and should attempt to combine flow
comment|/// control instructions via predication.
name|bool
name|JumpIsExpensive
decl_stmt|;
comment|/// UseUnderscoreSetJmp - This target prefers to use _setjmp to implement
comment|/// llvm.setjmp.  Defaults to false.
name|bool
name|UseUnderscoreSetJmp
decl_stmt|;
comment|/// UseUnderscoreLongJmp - This target prefers to use _longjmp to implement
comment|/// llvm.longjmp.  Defaults to false.
name|bool
name|UseUnderscoreLongJmp
decl_stmt|;
comment|/// SupportJumpTables - Whether the target can generate code for jumptables.
comment|/// If it's not true, then each jumptable must be lowered into if-then-else's.
name|bool
name|SupportJumpTables
decl_stmt|;
comment|/// MinimumJumpTableEntries - Number of blocks threshold to use jump tables.
name|int
name|MinimumJumpTableEntries
decl_stmt|;
comment|/// BooleanContents - Information about the contents of the high-bits in
comment|/// boolean values held in a type wider than i1.  See getBooleanContents.
name|BooleanContent
name|BooleanContents
decl_stmt|;
comment|/// BooleanVectorContents - Information about the contents of the high-bits
comment|/// in boolean vector values when the element type is wider than i1.  See
comment|/// getBooleanContents.
name|BooleanContent
name|BooleanVectorContents
decl_stmt|;
comment|/// SchedPreferenceInfo - The target scheduling preference: shortest possible
comment|/// total cycles or lowest register usage.
name|Sched
operator|::
name|Preference
name|SchedPreferenceInfo
expr_stmt|;
comment|/// JumpBufSize - The size, in bytes, of the target's jmp_buf buffers
name|unsigned
name|JumpBufSize
decl_stmt|;
comment|/// JumpBufAlignment - The alignment, in bytes, of the target's jmp_buf
comment|/// buffers
name|unsigned
name|JumpBufAlignment
decl_stmt|;
comment|/// MinStackArgumentAlignment - The minimum alignment that any argument
comment|/// on the stack needs to have.
comment|///
name|unsigned
name|MinStackArgumentAlignment
decl_stmt|;
comment|/// MinFunctionAlignment - The minimum function alignment (used when
comment|/// optimizing for size, and to prevent explicitly provided alignment
comment|/// from leading to incorrect code).
comment|///
name|unsigned
name|MinFunctionAlignment
decl_stmt|;
comment|/// PrefFunctionAlignment - The preferred function alignment (used when
comment|/// alignment unspecified and optimizing for speed).
comment|///
name|unsigned
name|PrefFunctionAlignment
decl_stmt|;
comment|/// PrefLoopAlignment - The preferred loop alignment.
comment|///
name|unsigned
name|PrefLoopAlignment
decl_stmt|;
comment|/// InsertFencesForAtomic - Whether the DAG builder should automatically
comment|/// insert fences and reduce ordering for atomics.  (This will be set for
comment|/// for most architectures with weak memory ordering.)
name|bool
name|InsertFencesForAtomic
decl_stmt|;
comment|/// StackPointerRegisterToSaveRestore - If set to a physical register, this
comment|/// specifies the register that llvm.savestack/llvm.restorestack should save
comment|/// and restore.
name|unsigned
name|StackPointerRegisterToSaveRestore
decl_stmt|;
comment|/// ExceptionPointerRegister - If set to a physical register, this specifies
comment|/// the register that receives the exception address on entry to a landing
comment|/// pad.
name|unsigned
name|ExceptionPointerRegister
decl_stmt|;
comment|/// ExceptionSelectorRegister - If set to a physical register, this specifies
comment|/// the register that receives the exception typeid on entry to a landing
comment|/// pad.
name|unsigned
name|ExceptionSelectorRegister
decl_stmt|;
comment|/// RegClassForVT - This indicates the default register class to use for
comment|/// each ValueType the target supports natively.
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
comment|/// RepRegClassForVT - This indicates the "representative" register class to
comment|/// use for each ValueType the target supports natively. This information is
comment|/// used by the scheduler to track register pressure. By default, the
comment|/// representative register class is the largest legal super-reg register
comment|/// class of the register class of the specified type. e.g. On x86, i8, i16,
comment|/// and i32's representative class would be GR32.
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
comment|/// RepRegClassCostForVT - This indicates the "cost" of the "representative"
comment|/// register class for each ValueType. The cost is used by the scheduler to
comment|/// approximate register pressure.
name|uint8_t
name|RepRegClassCostForVT
index|[
name|MVT
operator|::
name|LAST_VALUETYPE
index|]
decl_stmt|;
comment|/// TransformToType - For any value types we are promoting or expanding, this
comment|/// contains the value type that we are changing to.  For Expanded types, this
comment|/// contains one step of the expand (e.g. i64 -> i32), even if there are
comment|/// multiple steps required (e.g. i64 -> i16).  For types natively supported
comment|/// by the system, this holds the same type (e.g. i32 -> i32).
name|MVT
name|TransformToType
index|[
name|MVT
operator|::
name|LAST_VALUETYPE
index|]
decl_stmt|;
comment|/// OpActions - For each operation and each value type, keep a LegalizeAction
comment|/// that indicates how instruction selection should deal with the operation.
comment|/// Most operations are Legal (aka, supported natively by the target), but
comment|/// operations that are not should be described.  Note that operations on
comment|/// non-legal value types are not described here.
name|uint8_t
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
comment|/// LoadExtActions - For each load extension type and each value type,
comment|/// keep a LegalizeAction that indicates how instruction selection should deal
comment|/// with a load of a specific value type and extension type.
name|uint8_t
name|LoadExtActions
index|[
name|MVT
operator|::
name|LAST_VALUETYPE
index|]
index|[
name|ISD
operator|::
name|LAST_LOADEXT_TYPE
index|]
decl_stmt|;
comment|/// TruncStoreActions - For each value type pair keep a LegalizeAction that
comment|/// indicates whether a truncating store of a specific value type and
comment|/// truncating type is legal.
name|uint8_t
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
comment|/// IndexedModeActions - For each indexed mode and each value type,
comment|/// keep a pair of LegalizeAction that indicates how instruction
comment|/// selection should deal with the load / store.  The first dimension is the
comment|/// value_type for the reference. The second dimension represents the various
comment|/// modes for load store.
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
comment|/// CondCodeActions - For each condition code (ISD::CondCode) keep a
comment|/// LegalizeAction that indicates how instruction selection should
comment|/// deal with the condition code.
comment|/// Because each CC action takes up 2 bits, we need to have the array size
comment|/// be large enough to fit all of the value types. This can be done by
comment|/// dividing the MVT::LAST_VALUETYPE by 32 and adding one.
name|uint64_t
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
operator|/
literal|32
operator|)
operator|+
literal|1
index|]
decl_stmt|;
name|ValueTypeActionImpl
name|ValueTypeActions
decl_stmt|;
name|public
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
block|{
comment|// If this is a simple type, use the ComputeRegisterProp mechanism.
if|if
condition|(
name|VT
operator|.
name|isSimple
argument_list|()
condition|)
block|{
name|MVT
name|SVT
init|=
name|VT
operator|.
name|getSimpleVT
argument_list|()
decl_stmt|;
name|assert
argument_list|(
operator|(
name|unsigned
operator|)
name|SVT
operator|.
name|SimpleTy
operator|<
name|array_lengthof
argument_list|(
name|TransformToType
argument_list|)
argument_list|)
expr_stmt|;
name|MVT
name|NVT
init|=
name|TransformToType
index|[
name|SVT
operator|.
name|SimpleTy
index|]
decl_stmt|;
name|LegalizeTypeAction
name|LA
init|=
name|ValueTypeActions
operator|.
name|getTypeAction
argument_list|(
name|SVT
argument_list|)
decl_stmt|;
name|assert
argument_list|(
operator|(
name|LA
operator|==
name|TypeLegal
operator|||
name|ValueTypeActions
operator|.
name|getTypeAction
argument_list|(
name|NVT
argument_list|)
operator|!=
name|TypePromoteInteger
operator|)
operator|&&
literal|"Promote may not follow Expand or Promote"
argument_list|)
expr_stmt|;
if|if
condition|(
name|LA
operator|==
name|TypeSplitVector
condition|)
return|return
name|LegalizeKind
argument_list|(
name|LA
argument_list|,
name|EVT
operator|::
name|getVectorVT
argument_list|(
name|Context
argument_list|,
name|SVT
operator|.
name|getVectorElementType
argument_list|()
argument_list|,
name|SVT
operator|.
name|getVectorNumElements
argument_list|()
operator|/
literal|2
argument_list|)
argument_list|)
return|;
if|if
condition|(
name|LA
operator|==
name|TypeScalarizeVector
condition|)
return|return
name|LegalizeKind
argument_list|(
name|LA
argument_list|,
name|SVT
operator|.
name|getVectorElementType
argument_list|()
argument_list|)
return|;
return|return
name|LegalizeKind
argument_list|(
name|LA
argument_list|,
name|NVT
argument_list|)
return|;
block|}
comment|// Handle Extended Scalar Types.
if|if
condition|(
operator|!
name|VT
operator|.
name|isVector
argument_list|()
condition|)
block|{
name|assert
argument_list|(
name|VT
operator|.
name|isInteger
argument_list|()
operator|&&
literal|"Float types must be simple"
argument_list|)
expr_stmt|;
name|unsigned
name|BitSize
init|=
name|VT
operator|.
name|getSizeInBits
argument_list|()
decl_stmt|;
comment|// First promote to a power-of-two size, then expand if necessary.
if|if
condition|(
name|BitSize
operator|<
literal|8
operator|||
operator|!
name|isPowerOf2_32
argument_list|(
name|BitSize
argument_list|)
condition|)
block|{
name|EVT
name|NVT
init|=
name|VT
operator|.
name|getRoundIntegerType
argument_list|(
name|Context
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|NVT
operator|!=
name|VT
operator|&&
literal|"Unable to round integer VT"
argument_list|)
expr_stmt|;
name|LegalizeKind
name|NextStep
init|=
name|getTypeConversion
argument_list|(
name|Context
argument_list|,
name|NVT
argument_list|)
decl_stmt|;
comment|// Avoid multi-step promotion.
if|if
condition|(
name|NextStep
operator|.
name|first
operator|==
name|TypePromoteInteger
condition|)
return|return
name|NextStep
return|;
comment|// Return rounded integer type.
return|return
name|LegalizeKind
argument_list|(
name|TypePromoteInteger
argument_list|,
name|NVT
argument_list|)
return|;
block|}
return|return
name|LegalizeKind
argument_list|(
name|TypeExpandInteger
argument_list|,
name|EVT
operator|::
name|getIntegerVT
argument_list|(
name|Context
argument_list|,
name|VT
operator|.
name|getSizeInBits
argument_list|()
operator|/
literal|2
argument_list|)
argument_list|)
return|;
block|}
comment|// Handle vector types.
name|unsigned
name|NumElts
init|=
name|VT
operator|.
name|getVectorNumElements
argument_list|()
decl_stmt|;
name|EVT
name|EltVT
init|=
name|VT
operator|.
name|getVectorElementType
argument_list|()
decl_stmt|;
comment|// Vectors with only one element are always scalarized.
if|if
condition|(
name|NumElts
operator|==
literal|1
condition|)
return|return
name|LegalizeKind
argument_list|(
name|TypeScalarizeVector
argument_list|,
name|EltVT
argument_list|)
return|;
comment|// Try to widen vector elements until a legal type is found.
if|if
condition|(
name|EltVT
operator|.
name|isInteger
argument_list|()
condition|)
block|{
comment|// Vectors with a number of elements that is not a power of two are always
comment|// widened, for example<3 x float> -><4 x float>.
if|if
condition|(
operator|!
name|VT
operator|.
name|isPow2VectorType
argument_list|()
condition|)
block|{
name|NumElts
operator|=
operator|(
name|unsigned
operator|)
name|NextPowerOf2
argument_list|(
name|NumElts
argument_list|)
expr_stmt|;
name|EVT
name|NVT
init|=
name|EVT
operator|::
name|getVectorVT
argument_list|(
name|Context
argument_list|,
name|EltVT
argument_list|,
name|NumElts
argument_list|)
decl_stmt|;
return|return
name|LegalizeKind
argument_list|(
name|TypeWidenVector
argument_list|,
name|NVT
argument_list|)
return|;
block|}
comment|// Examine the element type.
name|LegalizeKind
name|LK
init|=
name|getTypeConversion
argument_list|(
name|Context
argument_list|,
name|EltVT
argument_list|)
decl_stmt|;
comment|// If type is to be expanded, split the vector.
comment|//<4 x i140> -><2 x i140>
if|if
condition|(
name|LK
operator|.
name|first
operator|==
name|TypeExpandInteger
condition|)
return|return
name|LegalizeKind
argument_list|(
name|TypeSplitVector
argument_list|,
name|EVT
operator|::
name|getVectorVT
argument_list|(
name|Context
argument_list|,
name|EltVT
argument_list|,
name|NumElts
operator|/
literal|2
argument_list|)
argument_list|)
return|;
comment|// Promote the integer element types until a legal vector type is found
comment|// or until the element integer type is too big. If a legal type was not
comment|// found, fallback to the usual mechanism of widening/splitting the
comment|// vector.
name|EVT
name|OldEltVT
init|=
name|EltVT
decl_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
comment|// Increase the bitwidth of the element to the next pow-of-two
comment|// (which is greater than 8 bits).
name|EltVT
operator|=
name|EVT
operator|::
name|getIntegerVT
argument_list|(
name|Context
argument_list|,
literal|1
operator|+
name|EltVT
operator|.
name|getSizeInBits
argument_list|()
argument_list|)
operator|.
name|getRoundIntegerType
argument_list|(
name|Context
argument_list|)
expr_stmt|;
comment|// Stop trying when getting a non-simple element type.
comment|// Note that vector elements may be greater than legal vector element
comment|// types. Example: X86 XMM registers hold 64bit element on 32bit systems.
if|if
condition|(
operator|!
name|EltVT
operator|.
name|isSimple
argument_list|()
condition|)
break|break;
comment|// Build a new vector type and check if it is legal.
name|MVT
name|NVT
init|=
name|MVT
operator|::
name|getVectorVT
argument_list|(
name|EltVT
operator|.
name|getSimpleVT
argument_list|()
argument_list|,
name|NumElts
argument_list|)
decl_stmt|;
comment|// Found a legal promoted vector type.
if|if
condition|(
name|NVT
operator|!=
name|MVT
argument_list|()
operator|&&
name|ValueTypeActions
operator|.
name|getTypeAction
argument_list|(
name|NVT
argument_list|)
operator|==
name|TypeLegal
condition|)
return|return
name|LegalizeKind
argument_list|(
name|TypePromoteInteger
argument_list|,
name|EVT
operator|::
name|getVectorVT
argument_list|(
name|Context
argument_list|,
name|EltVT
argument_list|,
name|NumElts
argument_list|)
argument_list|)
return|;
block|}
comment|// Reset the type to the unexpanded type if we did not find a legal vector
comment|// type with a promoted vector element type.
name|EltVT
operator|=
name|OldEltVT
expr_stmt|;
block|}
comment|// Try to widen the vector until a legal type is found.
comment|// If there is no wider legal type, split the vector.
while|while
condition|(
literal|1
condition|)
block|{
comment|// Round up to the next power of 2.
name|NumElts
operator|=
operator|(
name|unsigned
operator|)
name|NextPowerOf2
argument_list|(
name|NumElts
argument_list|)
expr_stmt|;
comment|// If there is no simple vector type with this many elements then there
comment|// cannot be a larger legal vector type.  Note that this assumes that
comment|// there are no skipped intermediate vector types in the simple types.
if|if
condition|(
operator|!
name|EltVT
operator|.
name|isSimple
argument_list|()
condition|)
break|break;
name|MVT
name|LargerVector
init|=
name|MVT
operator|::
name|getVectorVT
argument_list|(
name|EltVT
operator|.
name|getSimpleVT
argument_list|()
argument_list|,
name|NumElts
argument_list|)
decl_stmt|;
if|if
condition|(
name|LargerVector
operator|==
name|MVT
argument_list|()
condition|)
break|break;
comment|// If this type is legal then widen the vector.
if|if
condition|(
name|ValueTypeActions
operator|.
name|getTypeAction
argument_list|(
name|LargerVector
argument_list|)
operator|==
name|TypeLegal
condition|)
return|return
name|LegalizeKind
argument_list|(
name|TypeWidenVector
argument_list|,
name|LargerVector
argument_list|)
return|;
block|}
comment|// Widen odd vectors to next power of two.
if|if
condition|(
operator|!
name|VT
operator|.
name|isPow2VectorType
argument_list|()
condition|)
block|{
name|EVT
name|NVT
init|=
name|VT
operator|.
name|getPow2VectorType
argument_list|(
name|Context
argument_list|)
decl_stmt|;
return|return
name|LegalizeKind
argument_list|(
name|TypeWidenVector
argument_list|,
name|NVT
argument_list|)
return|;
block|}
comment|// Vectors with illegal element types are expanded.
name|EVT
name|NVT
init|=
name|EVT
operator|::
name|getVectorVT
argument_list|(
name|Context
argument_list|,
name|EltVT
argument_list|,
name|VT
operator|.
name|getVectorNumElements
argument_list|()
operator|/
literal|2
argument_list|)
decl_stmt|;
return|return
name|LegalizeKind
argument_list|(
name|TypeSplitVector
argument_list|,
name|NVT
argument_list|)
return|;
block|}
name|private
label|:
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|MVT
operator|,
specifier|const
name|TargetRegisterClass
operator|*
operator|>
expr|>
name|AvailableRegClasses
expr_stmt|;
comment|/// TargetDAGCombineArray - Targets can specify ISD nodes that they would
comment|/// like PerformDAGCombine callbacks for by calling setTargetDAGCombine(),
comment|/// which sets a bit in this array.
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
comment|/// PromoteToType - For operations that must be promoted to a specific type,
comment|/// this holds the destination type.  This map should be sparse, so don't hold
comment|/// it as an array.
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
comment|/// LibcallRoutineNames - Stores the name each libcall.
comment|///
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
comment|/// CmpLibcallCCs - The ISD::CondCode that should be used to test the result
comment|/// of each of the comparison libcall against zero.
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
comment|/// LibcallCallingConvs - Stores the CallingConv that should be used for each
comment|/// libcall.
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
comment|/// When lowering \@llvm.memset this field specifies the maximum number of
comment|/// store operations that may be substituted for the call to memset. Targets
comment|/// must set this value based on the cost threshold for that target. Targets
comment|/// should assume that the memset will be done using as many of the largest
comment|/// store operations first, followed by smaller ones, if necessary, per
comment|/// alignment restrictions. For example, storing 9 bytes on a 32-bit machine
comment|/// with 16-bit alignment would result in four 2-byte stores and one 1-byte
comment|/// store.  This only applies to setting a constant array of a constant size.
comment|/// @brief Specify maximum number of store instructions per memset call.
name|unsigned
name|MaxStoresPerMemset
decl_stmt|;
comment|/// Maximum number of stores operations that may be substituted for the call
comment|/// to memset, used for functions with OptSize attribute.
name|unsigned
name|MaxStoresPerMemsetOptSize
decl_stmt|;
comment|/// When lowering \@llvm.memcpy this field specifies the maximum number of
comment|/// store operations that may be substituted for a call to memcpy. Targets
comment|/// must set this value based on the cost threshold for that target. Targets
comment|/// should assume that the memcpy will be done using as many of the largest
comment|/// store operations first, followed by smaller ones, if necessary, per
comment|/// alignment restrictions. For example, storing 7 bytes on a 32-bit machine
comment|/// with 32-bit alignment would result in one 4-byte store, a one 2-byte store
comment|/// and one 1-byte store. This only applies to copying a constant array of
comment|/// constant size.
comment|/// @brief Specify maximum bytes of store instructions per memcpy call.
name|unsigned
name|MaxStoresPerMemcpy
decl_stmt|;
comment|/// Maximum number of store operations that may be substituted for a call
comment|/// to memcpy, used for functions with OptSize attribute.
name|unsigned
name|MaxStoresPerMemcpyOptSize
decl_stmt|;
comment|/// When lowering \@llvm.memmove this field specifies the maximum number of
comment|/// store instructions that may be substituted for a call to memmove. Targets
comment|/// must set this value based on the cost threshold for that target. Targets
comment|/// should assume that the memmove will be done using as many of the largest
comment|/// store operations first, followed by smaller ones, if necessary, per
comment|/// alignment restrictions. For example, moving 9 bytes on a 32-bit machine
comment|/// with 8-bit alignment would result in nine 1-byte stores.  This only
comment|/// applies to copying a constant array of constant size.
comment|/// @brief Specify maximum bytes of store instructions per memmove call.
name|unsigned
name|MaxStoresPerMemmove
decl_stmt|;
comment|/// Maximum number of store instructions that may be substituted for a call
comment|/// to memmove, used for functions with OpSize attribute.
name|unsigned
name|MaxStoresPerMemmoveOptSize
decl_stmt|;
comment|/// PredictableSelectIsExpensive - Tells the code generator that select is
comment|/// more expensive than a branch if the branch is usually predicted right.
name|bool
name|PredictableSelectIsExpensive
decl_stmt|;
name|protected
label|:
comment|/// isLegalRC - Return true if the value types that can be represented by the
comment|/// specified register class are all legal.
name|bool
name|isLegalRC
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// TargetLowering - This class defines information used to lower LLVM code to
comment|/// legal SelectionDAG operators that the target instruction selector can accept
comment|/// natively.
comment|///
comment|/// This class also defines callbacks that targets must implement to lower
comment|/// target-specific constructs to SelectionDAG operators.
comment|///
name|class
name|TargetLowering
range|:
name|public
name|TargetLoweringBase
block|{
name|TargetLowering
argument_list|(
argument|const TargetLowering&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|TargetLowering
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
name|public
operator|:
comment|/// NOTE: The constructor takes ownership of TLOF.
name|explicit
name|TargetLowering
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|TargetLoweringObjectFile
operator|*
name|TLOF
argument_list|)
block|;
comment|/// getPreIndexedAddressParts - returns true by value, base pointer and
comment|/// offset pointer and addressing mode by reference if the node's address
comment|/// can be legally represented as pre-indexed load / store address.
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
comment|/// getPostIndexedAddressParts - returns true by value, base pointer and
comment|/// offset pointer and addressing mode by reference if this node can be
comment|/// combined with a load / store to form a post-indexed load / store.
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
comment|/// getJumpTableEncoding - Return the entry encoding for a jump table in the
comment|/// current function.  The returned value is a member of the
comment|/// MachineJumpTableInfo::JTEntryKind enum.
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
comment|/// getPICJumpTableRelocaBase - Returns relocation base for the given PIC
comment|/// jumptable.
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
comment|/// getPICJumpTableRelocBaseExpr - This returns the relocation base for the
comment|/// given PIC jumptable, the same as getPICJumpTableRelocBase, but as an
comment|/// MCExpr.
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
comment|/// isOffsetFoldingLegal - Return true if folding a constant offset
comment|/// with the given GlobalAddress is legal.  It is frequently not legal in
comment|/// PIC relocation models.
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
argument|DebugLoc DL
argument_list|)
specifier|const
block|;
name|SDValue
name|makeLibCall
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|RTLIB::Libcall LC
argument_list|,
argument|EVT RetVT
argument_list|,
argument|const SDValue *Ops
argument_list|,
argument|unsigned NumOps
argument_list|,
argument|bool isSigned
argument_list|,
argument|DebugLoc dl
argument_list|)
specifier|const
block|;
comment|//===--------------------------------------------------------------------===//
comment|// TargetLowering Optimization Methods
comment|//
comment|/// TargetLoweringOpt - A convenience struct that encapsulates a DAG, and two
comment|/// SDValues for returning information from TargetLowering to its clients
comment|/// that want to combine
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
comment|/// ShrinkDemandedConstant - Check to see if the specified operand of the
comment|/// specified instruction is a constant integer.  If so, check to see if
comment|/// there are any bits set in the constant that are not demanded.  If so,
comment|/// shrink the constant and return true.
name|bool
name|ShrinkDemandedConstant
argument_list|(
argument|SDValue Op
argument_list|,
argument|const APInt&Demanded
argument_list|)
block|;
comment|/// ShrinkDemandedOp - Convert x+y to (VT)((SmallVT)x+(SmallVT)y) if the
comment|/// casts are free.  This uses isZExtFree and ZERO_EXTEND for the widening
comment|/// cast, but it could be generalized for targets with other types of
comment|/// implicit widening casts.
name|bool
name|ShrinkDemandedOp
argument_list|(
argument|SDValue Op
argument_list|,
argument|unsigned BitWidth
argument_list|,
argument|const APInt&Demanded
argument_list|,
argument|DebugLoc dl
argument_list|)
block|;   }
block|;
comment|/// SimplifyDemandedBits - Look at Op.  At this point, we know that only the
comment|/// DemandedMask bits of the result of Op are ever used downstream.  If we can
comment|/// use this information to simplify Op, create a new simplified DAG node and
comment|/// return true, returning the original and new nodes in Old and New.
comment|/// Otherwise, analyze the expression and return a mask of KnownOne and
comment|/// KnownZero bits for the expression (used to simplify the caller).
comment|/// The KnownZero/One bits may only be accurate for those bits in the
comment|/// DemandedMask.
name|bool
name|SimplifyDemandedBits
argument_list|(
argument|SDValue Op
argument_list|,
argument|const APInt&DemandedMask
argument_list|,
argument|APInt&KnownZero
argument_list|,
argument|APInt&KnownOne
argument_list|,
argument|TargetLoweringOpt&TLO
argument_list|,
argument|unsigned Depth =
literal|0
argument_list|)
specifier|const
block|;
comment|/// computeMaskedBitsForTargetNode - Determine which of the bits specified in
comment|/// Mask are known to be either zero or one and return them in the
comment|/// KnownZero/KnownOne bitsets.
name|virtual
name|void
name|computeMaskedBitsForTargetNode
argument_list|(
argument|const SDValue Op
argument_list|,
argument|APInt&KnownZero
argument_list|,
argument|APInt&KnownOne
argument_list|,
argument|const SelectionDAG&DAG
argument_list|,
argument|unsigned Depth =
literal|0
argument_list|)
specifier|const
block|;
comment|/// ComputeNumSignBitsForTargetNode - This method can be implemented by
comment|/// targets that want to expose additional information about sign bits to the
comment|/// DAG Combiner.
name|virtual
name|unsigned
name|ComputeNumSignBitsForTargetNode
argument_list|(
argument|SDValue Op
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
name|void
name|RemoveFromWorklist
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
argument|const std::vector<SDValue>&To
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
comment|/// SimplifySetCC - Try to simplify a setcc built with the specified operands
comment|/// and cc. If it is unable to simplify it, return a null SDValue.
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
argument|DebugLoc dl
argument_list|)
specifier|const
block|;
comment|/// isGAPlusOffset - Returns true (and the GlobalValue and the offset) if the
comment|/// node is a GlobalAddress + offset.
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
comment|/// PerformDAGCombine - This method will be invoked for all target nodes and
comment|/// for any target-independent nodes that the target has registered with
comment|/// invoke it for.
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
comment|/// isTypeDesirableForOp - Return true if the target has native support for
comment|/// the specified value type and it is 'desirable' to use the type for the
comment|/// given node type. e.g. On x86 i16 is legal, but undesirable since i16
comment|/// instruction encodings are longer and some i16 instructions are slow.
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
comment|/// isDesirableToPromoteOp - Return true if it is profitable for dag combiner
comment|/// to transform a floating point op of specified opcode to a equivalent op of
comment|/// an integer type. e.g. f32 load -> i32 load can be profitable on ARM.
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
comment|/// IsDesirableToPromoteOp - This method query the target whether it is
comment|/// beneficial for dag combiner to promote the specified node. If true, it
comment|/// should return the desired promotion type by reference.
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
comment|//===--------------------------------------------------------------------===//
comment|// Lowering methods - These methods must be implemented by targets so that
comment|// the SelectionDAGBuilder code knows how to lower these.
comment|//
comment|/// LowerFormalArguments - This hook must be implemented to lower the
comment|/// incoming (formal) arguments, described by the Ins array, into the
comment|/// specified DAG. The implementation should fill in the InVals array
comment|/// with legal-type argument values, and return the resulting token
comment|/// chain value.
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
argument|DebugLoc
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
expr|struct
name|ArgListEntry
block|{
name|SDValue
name|Node
block|;
name|Type
operator|*
name|Ty
block|;
name|bool
name|isSExt
operator|:
literal|1
block|;
name|bool
name|isZExt
operator|:
literal|1
block|;
name|bool
name|isInReg
operator|:
literal|1
block|;
name|bool
name|isSRet
operator|:
literal|1
block|;
name|bool
name|isNest
operator|:
literal|1
block|;
name|bool
name|isByVal
operator|:
literal|1
block|;
name|bool
name|isReturned
operator|:
literal|1
block|;
name|uint16_t
name|Alignment
block|;
name|ArgListEntry
argument_list|()
operator|:
name|isSExt
argument_list|(
name|false
argument_list|)
block|,
name|isZExt
argument_list|(
name|false
argument_list|)
block|,
name|isInReg
argument_list|(
name|false
argument_list|)
block|,
name|isSRet
argument_list|(
name|false
argument_list|)
block|,
name|isNest
argument_list|(
name|false
argument_list|)
block|,
name|isByVal
argument_list|(
name|false
argument_list|)
block|,
name|isReturned
argument_list|(
name|false
argument_list|)
block|,
name|Alignment
argument_list|(
literal|0
argument_list|)
block|{ }
block|}
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|ArgListEntry
operator|>
name|ArgListTy
expr_stmt|;
comment|/// CallLoweringInfo - This structure contains all information that is
comment|/// necessary for lowering calls. It is passed to TLI::LowerCallTo when the
comment|/// SelectionDAG builder needs to lower a call, and targets will see this
comment|/// struct in their LowerCall implementation.
block|struct
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
operator|&
name|Args
block|;
name|SelectionDAG
operator|&
name|DAG
block|;
name|DebugLoc
name|DL
block|;
name|ImmutableCallSite
operator|*
name|CS
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
comment|/// CallLoweringInfo - Constructs a call lowering context based on the
comment|/// ImmutableCallSite \p cs.
name|CallLoweringInfo
argument_list|(
argument|SDValue chain
argument_list|,
argument|Type *retTy
argument_list|,
argument|FunctionType *FTy
argument_list|,
argument|bool isTailCall
argument_list|,
argument|SDValue callee
argument_list|,
argument|ArgListTy&args
argument_list|,
argument|SelectionDAG&dag
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|ImmutableCallSite&cs
argument_list|)
operator|:
name|Chain
argument_list|(
name|chain
argument_list|)
block|,
name|RetTy
argument_list|(
name|retTy
argument_list|)
block|,
name|RetSExt
argument_list|(
name|cs
operator|.
name|paramHasAttr
argument_list|(
literal|0
argument_list|,
name|Attribute
operator|::
name|SExt
argument_list|)
argument_list|)
block|,
name|RetZExt
argument_list|(
name|cs
operator|.
name|paramHasAttr
argument_list|(
literal|0
argument_list|,
name|Attribute
operator|::
name|ZExt
argument_list|)
argument_list|)
block|,
name|IsVarArg
argument_list|(
name|FTy
operator|->
name|isVarArg
argument_list|()
argument_list|)
block|,
name|IsInReg
argument_list|(
name|cs
operator|.
name|paramHasAttr
argument_list|(
literal|0
argument_list|,
name|Attribute
operator|::
name|InReg
argument_list|)
argument_list|)
block|,
name|DoesNotReturn
argument_list|(
name|cs
operator|.
name|doesNotReturn
argument_list|()
argument_list|)
block|,
name|IsReturnValueUsed
argument_list|(
operator|!
name|cs
operator|.
name|getInstruction
argument_list|()
operator|->
name|use_empty
argument_list|()
argument_list|)
block|,
name|IsTailCall
argument_list|(
name|isTailCall
argument_list|)
block|,
name|NumFixedArgs
argument_list|(
name|FTy
operator|->
name|getNumParams
argument_list|()
argument_list|)
block|,
name|CallConv
argument_list|(
name|cs
operator|.
name|getCallingConv
argument_list|()
argument_list|)
block|,
name|Callee
argument_list|(
name|callee
argument_list|)
block|,
name|Args
argument_list|(
name|args
argument_list|)
block|,
name|DAG
argument_list|(
name|dag
argument_list|)
block|,
name|DL
argument_list|(
name|dl
argument_list|)
block|,
name|CS
argument_list|(
argument|&cs
argument_list|)
block|{}
comment|/// CallLoweringInfo - Constructs a call lowering context based on the
comment|/// provided call information.
name|CallLoweringInfo
argument_list|(
argument|SDValue chain
argument_list|,
argument|Type *retTy
argument_list|,
argument|bool retSExt
argument_list|,
argument|bool retZExt
argument_list|,
argument|bool isVarArg
argument_list|,
argument|bool isInReg
argument_list|,
argument|unsigned numFixedArgs
argument_list|,
argument|CallingConv::ID callConv
argument_list|,
argument|bool isTailCall
argument_list|,
argument|bool doesNotReturn
argument_list|,
argument|bool isReturnValueUsed
argument_list|,
argument|SDValue callee
argument_list|,
argument|ArgListTy&args
argument_list|,
argument|SelectionDAG&dag
argument_list|,
argument|DebugLoc dl
argument_list|)
operator|:
name|Chain
argument_list|(
name|chain
argument_list|)
block|,
name|RetTy
argument_list|(
name|retTy
argument_list|)
block|,
name|RetSExt
argument_list|(
name|retSExt
argument_list|)
block|,
name|RetZExt
argument_list|(
name|retZExt
argument_list|)
block|,
name|IsVarArg
argument_list|(
name|isVarArg
argument_list|)
block|,
name|IsInReg
argument_list|(
name|isInReg
argument_list|)
block|,
name|DoesNotReturn
argument_list|(
name|doesNotReturn
argument_list|)
block|,
name|IsReturnValueUsed
argument_list|(
name|isReturnValueUsed
argument_list|)
block|,
name|IsTailCall
argument_list|(
name|isTailCall
argument_list|)
block|,
name|NumFixedArgs
argument_list|(
name|numFixedArgs
argument_list|)
block|,
name|CallConv
argument_list|(
name|callConv
argument_list|)
block|,
name|Callee
argument_list|(
name|callee
argument_list|)
block|,
name|Args
argument_list|(
name|args
argument_list|)
block|,
name|DAG
argument_list|(
name|dag
argument_list|)
block|,
name|DL
argument_list|(
name|dl
argument_list|)
block|,
name|CS
argument_list|(
argument|NULL
argument_list|)
block|{}
block|}
decl_stmt|;
comment|/// LowerCallTo - This function lowers an abstract call to a function into an
comment|/// actual call.  This returns a pair of operands.  The first element is the
comment|/// return value for the function (if RetTy is not VoidTy).  The second
comment|/// element is the outgoing token chain. It calls LowerCall to do the actual
comment|/// lowering.
name|std
operator|::
name|pair
operator|<
name|SDValue
operator|,
name|SDValue
operator|>
name|LowerCallTo
argument_list|(
argument|CallLoweringInfo&CLI
argument_list|)
specifier|const
expr_stmt|;
comment|/// LowerCall - This hook must be implemented to lower calls into the
comment|/// the specified DAG. The outgoing arguments to the call are described
comment|/// by the Outs array, and the values to be returned by the call are
comment|/// described by the Ins array. The implementation should fill in the
comment|/// InVals array with legal-type return values from the call, and return
comment|/// the resulting token chain value.
name|virtual
name|SDValue
name|LowerCall
argument_list|(
name|CallLoweringInfo
operator|&
comment|/*CLI*/
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
comment|/*InVals*/
argument_list|)
decl|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Not Implemented"
argument_list|)
expr_stmt|;
block|}
comment|/// HandleByVal - Target-specific cleanup for formal ByVal parameters.
name|virtual
name|void
name|HandleByVal
argument_list|(
name|CCState
operator|*
argument_list|,
name|unsigned
operator|&
argument_list|,
name|unsigned
argument_list|)
decl|const
block|{}
comment|/// CanLowerReturn - This hook should be implemented to check whether the
comment|/// return values described by the Outs array can fit into the return
comment|/// registers.  If false is returned, an sret-demotion is performed.
comment|///
name|virtual
name|bool
name|CanLowerReturn
argument_list|(
name|CallingConv
operator|::
name|ID
comment|/*CallConv*/
argument_list|,
name|MachineFunction
operator|&
comment|/*MF*/
argument_list|,
name|bool
comment|/*isVarArg*/
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|OutputArg
operator|>
operator|&
comment|/*Outs*/
argument_list|,
name|LLVMContext
operator|&
comment|/*Context*/
argument_list|)
decl|const
block|{
comment|// Return true by default to get preexisting behavior.
return|return
name|true
return|;
block|}
comment|/// LowerReturn - This hook must be implemented to lower outgoing
comment|/// return values, described by the Outs array, into the specified
comment|/// DAG. The implementation should return the resulting token chain
comment|/// value.
comment|///
name|virtual
name|SDValue
name|LowerReturn
argument_list|(
name|SDValue
comment|/*Chain*/
argument_list|,
name|CallingConv
operator|::
name|ID
comment|/*CallConv*/
argument_list|,
name|bool
comment|/*isVarArg*/
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|OutputArg
operator|>
operator|&
comment|/*Outs*/
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
comment|/*OutVals*/
argument_list|,
name|DebugLoc
comment|/*dl*/
argument_list|,
name|SelectionDAG
operator|&
comment|/*DAG*/
argument_list|)
decl|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Not Implemented"
argument_list|)
expr_stmt|;
block|}
comment|/// isUsedByReturnOnly - Return true if result of the specified node is used
comment|/// by a return node only. It also compute and return the input chain for the
comment|/// tail call.
comment|/// This is used to determine whether it is possible
comment|/// to codegen a libcall as tail call at legalization time.
name|virtual
name|bool
name|isUsedByReturnOnly
argument_list|(
name|SDNode
operator|*
argument_list|,
name|SDValue
operator|&
name|Chain
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// mayBeEmittedAsTailCall - Return true if the target may be able emit the
comment|/// call instruction as a tail call. This is used by optimization passes to
comment|/// determine if it's profitable to duplicate return instructions to enable
comment|/// tailcall optimization.
name|virtual
name|bool
name|mayBeEmittedAsTailCall
argument_list|(
name|CallInst
operator|*
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// getTypeForExtArgOrReturn - Return the type that should be used to zero or
comment|/// sign extend a zeroext/signext integer argument or return value.
comment|/// FIXME: Most C calling convention requires the return type to be promoted,
comment|/// but this is not true all the time, e.g. i1 on x86-64. It is also not
comment|/// necessary for non-C calling conventions. The frontend should handle this
comment|/// and include all of the necessary information.
name|virtual
name|MVT
name|getTypeForExtArgOrReturn
argument_list|(
name|MVT
name|VT
argument_list|,
name|ISD
operator|::
name|NodeType
comment|/*ExtendKind*/
argument_list|)
decl|const
block|{
name|MVT
name|MinVT
init|=
name|getRegisterType
argument_list|(
name|MVT
operator|::
name|i32
argument_list|)
decl_stmt|;
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
comment|/// LowerOperationWrapper - This callback is invoked by the type legalizer
comment|/// to legalize nodes with an illegal operand type but legal result types.
comment|/// It replaces the LowerOperation callback in the type Legalizer.
comment|/// The reason we can not do away with LowerOperation entirely is that
comment|/// LegalizeDAG isn't yet ready to use this callback.
comment|/// TODO: Consider merging with ReplaceNodeResults.
comment|/// The target places new result values for the node in Results (their number
comment|/// and types must exactly match those of the original return values of
comment|/// the node), or leaves Results empty, which indicates that the node is not
comment|/// to be custom lowered after all.
comment|/// The default implementation calls LowerOperation.
name|virtual
name|void
name|LowerOperationWrapper
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|Results
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
comment|/// LowerOperation - This callback is invoked for operations that are
comment|/// unsupported by the target, which are registered to use 'custom' lowering,
comment|/// and whose defined values are all legal.
comment|/// If the target has no operations that require custom lowering, it need not
comment|/// implement this.  The default implementation of this aborts.
name|virtual
name|SDValue
name|LowerOperation
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
comment|/// ReplaceNodeResults - This callback is invoked when a node result type is
comment|/// illegal for the target, and the operation was registered to use 'custom'
comment|/// lowering for that result type.  The target places new result values for
comment|/// the node in Results (their number and types must exactly match those of
comment|/// the original return values of the node), or leaves Results empty, which
comment|/// indicates that the node is not to be custom lowered after all.
comment|///
comment|/// If the target has no operations that require custom lowering, it need not
comment|/// implement this.  The default implementation aborts.
name|virtual
name|void
name|ReplaceNodeResults
argument_list|(
name|SDNode
operator|*
comment|/*N*/
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
comment|/*Results*/
argument_list|,
name|SelectionDAG
operator|&
comment|/*DAG*/
argument_list|)
decl|const
block|{
name|llvm_unreachable
argument_list|(
literal|"ReplaceNodeResults not implemented for this target!"
argument_list|)
expr_stmt|;
block|}
comment|/// getTargetNodeName() - This method returns the name of a target specific
comment|/// DAG node.
name|virtual
specifier|const
name|char
modifier|*
name|getTargetNodeName
argument_list|(
name|unsigned
name|Opcode
argument_list|)
decl|const
decl_stmt|;
comment|/// createFastISel - This method returns a target specific FastISel object,
comment|/// or null if the target does not support "fast" ISel.
name|virtual
name|FastISel
modifier|*
name|createFastISel
argument_list|(
name|FunctionLoweringInfo
operator|&
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
argument_list|)
decl|const
block|{
return|return
literal|0
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Inline Asm Support hooks
comment|//
comment|/// ExpandInlineAsm - This hook allows the target to expand an inline asm
comment|/// call to be explicit llvm code if it wants to.  This is useful for
comment|/// turning simple inline asms into LLVM intrinsics, which gives the
comment|/// compiler more information about the behavior of the code.
name|virtual
name|bool
name|ExpandInlineAsm
argument_list|(
name|CallInst
operator|*
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
enum|enum
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
enum|;
enum|enum
name|ConstraintWeight
block|{
comment|// Generic weights.
name|CW_Invalid
init|=
operator|-
literal|1
block|,
comment|// No match.
name|CW_Okay
init|=
literal|0
block|,
comment|// Acceptable.
name|CW_Good
init|=
literal|1
block|,
comment|// Good weight.
name|CW_Better
init|=
literal|2
block|,
comment|// Better weight.
name|CW_Best
init|=
literal|3
block|,
comment|// Best weight.
comment|// Well-known weights.
name|CW_SpecificReg
init|=
name|CW_Okay
block|,
comment|// Specific register operands.
name|CW_Register
init|=
name|CW_Good
block|,
comment|// Register operands.
name|CW_Memory
init|=
name|CW_Better
block|,
comment|// Memory operands.
name|CW_Constant
init|=
name|CW_Best
block|,
comment|// Constant operand.
name|CW_Default
init|=
name|CW_Okay
comment|// Default or don't know type.
block|}
enum|;
comment|/// AsmOperandInfo - This contains information for each constraint that we are
comment|/// lowering.
name|struct
name|AsmOperandInfo
range|:
name|public
name|InlineAsm
operator|::
name|ConstraintInfo
block|{
comment|/// ConstraintCode - This contains the actual string for the code, like "m".
comment|/// TargetLowering picks the 'best' code from ConstraintInfo::Codes that
comment|/// most closely matches the operand.
name|std
operator|::
name|string
name|ConstraintCode
block|;
comment|/// ConstraintType - Information about the constraint code, e.g. Register,
comment|/// RegisterClass, Memory, Other, Unknown.
name|TargetLowering
operator|::
name|ConstraintType
name|ConstraintType
block|;
comment|/// CallOperandval - If this is the result output operand or a
comment|/// clobber, this is null, otherwise it is the incoming operand to the
comment|/// CallInst.  This gets modified as the asm is processed.
name|Value
operator|*
name|CallOperandVal
block|;
comment|/// ConstraintVT - The ValueType for the operand value.
name|MVT
name|ConstraintVT
block|;
comment|/// isMatchingInputConstraint - Return true of this is an input operand that
comment|/// is a matching constraint like "4".
name|bool
name|isMatchingInputConstraint
argument_list|()
specifier|const
block|;
comment|/// getMatchedOperand - If this is an input matching constraint, this method
comment|/// returns the output operand it matches.
name|unsigned
name|getMatchedOperand
argument_list|()
specifier|const
block|;
comment|/// Copy constructor for copying from an AsmOperandInfo.
name|AsmOperandInfo
argument_list|(
specifier|const
name|AsmOperandInfo
operator|&
name|info
argument_list|)
operator|:
name|InlineAsm
operator|::
name|ConstraintInfo
argument_list|(
name|info
argument_list|)
block|,
name|ConstraintCode
argument_list|(
name|info
operator|.
name|ConstraintCode
argument_list|)
block|,
name|ConstraintType
argument_list|(
name|info
operator|.
name|ConstraintType
argument_list|)
block|,
name|CallOperandVal
argument_list|(
name|info
operator|.
name|CallOperandVal
argument_list|)
block|,
name|ConstraintVT
argument_list|(
argument|info.ConstraintVT
argument_list|)
block|{     }
comment|/// Copy constructor for copying from a ConstraintInfo.
name|AsmOperandInfo
argument_list|(
specifier|const
name|InlineAsm
operator|::
name|ConstraintInfo
operator|&
name|info
argument_list|)
operator|:
name|InlineAsm
operator|::
name|ConstraintInfo
argument_list|(
name|info
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
literal|0
argument_list|)
block|,
name|ConstraintVT
argument_list|(
argument|MVT::Other
argument_list|)
block|{     }
block|}
decl_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|AsmOperandInfo
operator|>
name|AsmOperandInfoVector
expr_stmt|;
comment|/// ParseConstraints - Split up the constraint string from the inline
comment|/// assembly value into the specific constraints and their prefixes,
comment|/// and also tie in the associated operand values.
comment|/// If this returns an empty vector, and if the constraint string itself
comment|/// isn't empty, there was an error parsing.
name|virtual
name|AsmOperandInfoVector
name|ParseConstraints
argument_list|(
name|ImmutableCallSite
name|CS
argument_list|)
decl|const
decl_stmt|;
comment|/// Examine constraint type and operand type and determine a weight value.
comment|/// The operand object must already have been set up with the operand type.
name|virtual
name|ConstraintWeight
name|getMultipleConstraintMatchWeight
argument_list|(
name|AsmOperandInfo
operator|&
name|info
argument_list|,
name|int
name|maIndex
argument_list|)
decl|const
decl_stmt|;
comment|/// Examine constraint string and operand type and determine a weight value.
comment|/// The operand object must already have been set up with the operand type.
name|virtual
name|ConstraintWeight
name|getSingleConstraintMatchWeight
argument_list|(
name|AsmOperandInfo
operator|&
name|info
argument_list|,
specifier|const
name|char
operator|*
name|constraint
argument_list|)
decl|const
decl_stmt|;
comment|/// ComputeConstraintToUse - Determines the constraint code and constraint
comment|/// type to use for the specific AsmOperandInfo, setting
comment|/// OpInfo.ConstraintCode and OpInfo.ConstraintType.  If the actual operand
comment|/// being passed in is available, it can be passed in as Op, otherwise an
comment|/// empty SDValue can be passed.
name|virtual
name|void
name|ComputeConstraintToUse
argument_list|(
name|AsmOperandInfo
operator|&
name|OpInfo
argument_list|,
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|*
name|DAG
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// getConstraintType - Given a constraint, return the type of constraint it
comment|/// is for this target.
name|virtual
name|ConstraintType
name|getConstraintType
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Constraint
argument_list|)
decl|const
decl_stmt|;
comment|/// getRegForInlineAsmConstraint - Given a physical register constraint (e.g.
comment|/// {edx}), return the register number and the register class for the
comment|/// register.
comment|///
comment|/// Given a register class constraint, like 'r', if this corresponds directly
comment|/// to an LLVM register class, return a register of 0 and the register class
comment|/// pointer.
comment|///
comment|/// This should only be used for C_Register constraints.  On error,
comment|/// this returns a register number of 0 and a null register class pointer..
name|virtual
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
specifier|const
name|TargetRegisterClass
operator|*
operator|>
name|getRegForInlineAsmConstraint
argument_list|(
argument|const std::string&Constraint
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
expr_stmt|;
comment|/// LowerXConstraint - try to replace an X constraint, which matches anything,
comment|/// with another that has more specific requirements based on the type of the
comment|/// corresponding operand.  This returns null if there is no replacement to
comment|/// make.
name|virtual
specifier|const
name|char
modifier|*
name|LowerXConstraint
argument_list|(
name|EVT
name|ConstraintVT
argument_list|)
decl|const
decl_stmt|;
comment|/// LowerAsmOperandForConstraint - Lower the specified operand into the Ops
comment|/// vector.  If it is invalid, don't add anything to Ops.
name|virtual
name|void
name|LowerAsmOperandForConstraint
argument_list|(
name|SDValue
name|Op
argument_list|,
name|std
operator|::
name|string
operator|&
name|Constraint
argument_list|,
name|std
operator|::
name|vector
operator|<
name|SDValue
operator|>
operator|&
name|Ops
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// Div utility functions
comment|//
name|SDValue
name|BuildExactSDIV
argument_list|(
name|SDValue
name|Op1
argument_list|,
name|SDValue
name|Op2
argument_list|,
name|DebugLoc
name|dl
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
name|SDValue
name|BuildSDIV
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|bool
name|IsAfterLegalization
argument_list|,
name|std
operator|::
name|vector
operator|<
name|SDNode
operator|*
operator|>
operator|*
name|Created
argument_list|)
decl|const
decl_stmt|;
name|SDValue
name|BuildUDIV
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|bool
name|IsAfterLegalization
argument_list|,
name|std
operator|::
name|vector
operator|<
name|SDNode
operator|*
operator|>
operator|*
name|Created
argument_list|)
decl|const
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// Instruction Emitting Hooks
comment|//
comment|// EmitInstrWithCustomInserter - This method should be implemented by targets
comment|// that mark instructions with the 'usesCustomInserter' flag.  These
comment|// instructions are special in various ways, which require special support to
comment|// insert.  The specified MachineInstr is created but not inserted into any
comment|// basic blocks, and this method is called to expand it into a sequence of
comment|// instructions, potentially also creating new basic blocks and control flow.
name|virtual
name|MachineBasicBlock
modifier|*
name|EmitInstrWithCustomInserter
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
decl_stmt|;
comment|/// AdjustInstrPostInstrSelection - This method should be implemented by
comment|/// targets that mark instructions with the 'hasPostISelHook' flag. These
comment|/// instructions must be adjusted after instruction selection by target hooks.
comment|/// e.g. To fill in optional defs for ARM 's' setting instructions.
name|virtual
name|void
name|AdjustInstrPostInstrSelection
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
name|SDNode
operator|*
name|Node
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// GetReturnInfo - Given an LLVM IR type and return type attributes,
end_comment

begin_comment
comment|/// compute the return value EVTs and flags, and optionally also
end_comment

begin_comment
comment|/// the offsets, if the return value is being lowered to memory.
end_comment

begin_decl_stmt
name|void
name|GetReturnInfo
argument_list|(
name|Type
operator|*
name|ReturnType
argument_list|,
name|AttributeSet
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
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

