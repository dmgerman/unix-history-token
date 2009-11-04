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
file|"llvm/CallingConv.h"
end_include

begin_include
include|#
directive|include
file|"llvm/InlineAsm.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAGNodes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/RuntimeLibcalls.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/APFloat.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DebugLoc.h"
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
name|AllocaInst
decl_stmt|;
name|class
name|CallInst
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|FastISel
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineFrameInfo
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineModuleInfo
decl_stmt|;
name|class
name|DwarfWriter
decl_stmt|;
name|class
name|SDNode
decl_stmt|;
name|class
name|SDValue
decl_stmt|;
name|class
name|SelectionDAG
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|class
name|TargetSubtarget
decl_stmt|;
name|class
name|TargetLoweringObjectFile
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|// FIXME: should this be here?
name|namespace
name|TLSModel
block|{
enum|enum
name|Model
block|{
name|GeneralDynamic
block|,
name|LocalDynamic
block|,
name|InitialExec
block|,
name|LocalExec
block|}
enum|;
block|}
name|TLSModel
operator|::
name|Model
name|getTLSModel
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|Reloc::Model reloc
argument_list|)
expr_stmt|;
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
block|{
name|TargetLowering
argument_list|(
specifier|const
name|TargetLowering
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|TargetLowering
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
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
name|SchedPreference
block|{
name|SchedulingForLatency
block|,
comment|// Scheduling for shortest total latency.
name|SchedulingForRegPressure
comment|// Scheduling for lowest register pressure.
block|}
enum|;
comment|/// NOTE: The constructor takes ownership of TLOF.
name|explicit
name|TargetLowering
parameter_list|(
name|TargetMachine
modifier|&
name|TM
parameter_list|,
name|TargetLoweringObjectFile
modifier|*
name|TLOF
parameter_list|)
function_decl|;
name|virtual
operator|~
name|TargetLowering
argument_list|()
expr_stmt|;
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
name|TargetData
operator|*
name|getTargetData
argument_list|()
specifier|const
block|{
return|return
name|TD
return|;
block|}
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
name|MVT
name|getPointerTy
argument_list|()
specifier|const
block|{
return|return
name|PointerTy
return|;
block|}
name|MVT
name|getShiftAmountTy
argument_list|()
specifier|const
block|{
return|return
name|ShiftAmountTy
return|;
block|}
comment|/// usesGlobalOffsetTable - Return true if this target uses a GOT for PIC
comment|/// codegen.
name|bool
name|usesGlobalOffsetTable
argument_list|()
specifier|const
block|{
return|return
name|UsesGlobalOffsetTable
return|;
block|}
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
comment|/// getSetCCResultType - Return the ValueType of the result of SETCC
comment|/// operations.  Also used to obtain the target's preferred type for
comment|/// the condition operand of SELECT and BRCOND nodes.  In the case of
comment|/// BRCOND the argument passed is MVT::Other since there are no other
comment|/// operands to get a type hint from.
name|virtual
name|MVT
operator|::
name|SimpleValueType
name|getSetCCResultType
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
expr_stmt|;
comment|/// getBooleanContents - For targets without i1 registers, this gives the
comment|/// nature of the high-bits of boolean values held in types wider than i1.
comment|/// "Boolean values" are special true/false values produced by nodes like
comment|/// SETCC and consumed (as the condition) by nodes like SELECT and BRCOND.
comment|/// Not to be confused with general values promoted from i1.
name|BooleanContent
name|getBooleanContents
argument_list|()
specifier|const
block|{
return|return
name|BooleanContents
return|;
block|}
comment|/// getSchedulingPreference - Return target scheduling preference.
name|SchedPreference
name|getSchedulingPreference
argument_list|()
specifier|const
block|{
return|return
name|SchedPreferenceInfo
return|;
block|}
comment|/// getRegClassFor - Return the register class that should be used for the
comment|/// specified value type.  This may only be called on legal types.
name|TargetRegisterClass
modifier|*
name|getRegClassFor
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
name|isSimple
argument_list|()
operator|&&
literal|"getRegClassFor called on illegal type!"
argument_list|)
expr_stmt|;
name|TargetRegisterClass
modifier|*
name|RC
init|=
name|RegClassForVT
index|[
name|VT
operator|.
name|getSimpleVT
argument_list|()
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
comment|/// ValueTypeActions - This is a bitvector that contains two bits for each
comment|/// value type, where the two bits correspond to the LegalizeAction enum.
comment|/// This can be queried with "getTypeAction(VT)".
comment|/// dimension by (MVT::MAX_ALLOWED_VALUETYPE/32) * 2
name|uint32_t
name|ValueTypeActions
index|[
operator|(
name|MVT
operator|::
name|MAX_ALLOWED_VALUETYPE
operator|/
literal|32
operator|)
operator|*
literal|2
index|]
decl_stmt|;
name|public
label|:
name|ValueTypeActionImpl
argument_list|()
block|{
name|ValueTypeActions
index|[
literal|0
index|]
operator|=
name|ValueTypeActions
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
name|ValueTypeActions
index|[
literal|2
index|]
operator|=
name|ValueTypeActions
index|[
literal|3
index|]
operator|=
literal|0
expr_stmt|;
block|}
name|ValueTypeActionImpl
argument_list|(
argument|const ValueTypeActionImpl&RHS
argument_list|)
block|{
name|ValueTypeActions
index|[
literal|0
index|]
operator|=
name|RHS
operator|.
name|ValueTypeActions
index|[
literal|0
index|]
expr_stmt|;
name|ValueTypeActions
index|[
literal|1
index|]
operator|=
name|RHS
operator|.
name|ValueTypeActions
index|[
literal|1
index|]
expr_stmt|;
name|ValueTypeActions
index|[
literal|2
index|]
operator|=
name|RHS
operator|.
name|ValueTypeActions
index|[
literal|2
index|]
expr_stmt|;
name|ValueTypeActions
index|[
literal|3
index|]
operator|=
name|RHS
operator|.
name|ValueTypeActions
index|[
literal|3
index|]
expr_stmt|;
block|}
name|LegalizeAction
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
if|if
condition|(
name|VT
operator|.
name|isExtended
argument_list|()
condition|)
block|{
if|if
condition|(
name|VT
operator|.
name|isVector
argument_list|()
condition|)
block|{
return|return
name|VT
operator|.
name|isPow2VectorType
argument_list|()
condition|?
name|Expand
else|:
name|Promote
return|;
block|}
if|if
condition|(
name|VT
operator|.
name|isInteger
argument_list|()
condition|)
comment|// First promote to a power-of-two size, then expand if necessary.
return|return
name|VT
operator|==
name|VT
operator|.
name|getRoundIntegerType
argument_list|(
name|Context
argument_list|)
condition|?
name|Expand
else|:
name|Promote
return|;
name|assert
argument_list|(
literal|0
operator|&&
literal|"Unsupported extended type!"
argument_list|)
expr_stmt|;
return|return
name|Legal
return|;
block|}
name|unsigned
name|I
init|=
name|VT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
decl_stmt|;
name|assert
argument_list|(
name|I
operator|<
literal|4
operator|*
name|array_lengthof
argument_list|(
name|ValueTypeActions
argument_list|)
operator|*
sizeof|sizeof
argument_list|(
name|ValueTypeActions
index|[
literal|0
index|]
argument_list|)
argument_list|)
expr_stmt|;
return|return
call|(
name|LegalizeAction
call|)
argument_list|(
operator|(
name|ValueTypeActions
index|[
name|I
operator|>>
literal|4
index|]
operator|>>
operator|(
operator|(
literal|2
operator|*
name|I
operator|)
operator|&
literal|31
operator|)
operator|)
operator|&
literal|3
argument_list|)
return|;
block|}
name|void
name|setTypeAction
parameter_list|(
name|EVT
name|VT
parameter_list|,
name|LegalizeAction
name|Action
parameter_list|)
block|{
name|unsigned
name|I
init|=
name|VT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
decl_stmt|;
name|assert
argument_list|(
name|I
operator|<
literal|4
operator|*
name|array_lengthof
argument_list|(
name|ValueTypeActions
argument_list|)
operator|*
sizeof|sizeof
argument_list|(
name|ValueTypeActions
index|[
literal|0
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|ValueTypeActions
index|[
name|I
operator|>>
literal|4
index|]
operator||=
name|Action
operator|<<
operator|(
operator|(
name|I
operator|*
literal|2
operator|)
operator|&
literal|31
operator|)
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
name|LegalizeAction
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
name|ValueTypeActions
operator|.
name|getTypeAction
argument_list|(
name|Context
argument_list|,
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
name|TransformToType
argument_list|)
argument_list|)
expr_stmt|;
name|EVT
name|NVT
init|=
name|TransformToType
index|[
name|VT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
index|]
decl_stmt|;
name|assert
argument_list|(
name|getTypeAction
argument_list|(
name|Context
argument_list|,
name|NVT
argument_list|)
operator|!=
name|Promote
operator|&&
literal|"Promote may not follow Expand or Promote"
argument_list|)
expr_stmt|;
return|return
name|NVT
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
name|NVT
init|=
name|VT
operator|.
name|getPow2VectorType
argument_list|(
name|Context
argument_list|)
decl_stmt|;
if|if
condition|(
name|NVT
operator|==
name|VT
condition|)
block|{
comment|// Vector length is a power of 2 - split to half the size.
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
return|return
operator|(
name|NumElts
operator|==
literal|1
operator|)
condition|?
name|EltVT
else|:
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
return|;
block|}
comment|// Promote to a power of two size, avoiding multi-step promotion.
return|return
name|getTypeAction
argument_list|(
name|Context
argument_list|,
name|NVT
argument_list|)
operator|==
name|Promote
condition|?
name|getTypeToTransformTo
argument_list|(
name|Context
argument_list|,
name|NVT
argument_list|)
else|:
name|NVT
return|;
block|}
elseif|else
if|if
condition|(
name|VT
operator|.
name|isInteger
argument_list|()
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
if|if
condition|(
name|NVT
operator|==
name|VT
condition|)
comment|// Size is a power of two - expand to half the size.
return|return
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
return|;
else|else
comment|// Promote to a power of two size, avoiding multi-step promotion.
return|return
name|getTypeAction
argument_list|(
name|Context
argument_list|,
name|NVT
argument_list|)
operator|==
name|Promote
condition|?
name|getTypeToTransformTo
argument_list|(
name|Context
argument_list|,
name|NVT
argument_list|)
else|:
name|NVT
return|;
block|}
name|assert
argument_list|(
literal|0
operator|&&
literal|"Unsupported extended type!"
argument_list|)
expr_stmt|;
return|return
name|MVT
argument_list|(
name|MVT
operator|::
name|Other
argument_list|)
return|;
comment|// Not reached
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
name|Legal
case|:
return|return
name|VT
return|;
case|case
name|Expand
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
name|assert
argument_list|(
name|false
operator|&&
literal|"Type is not legal nor is it to be expanded!"
argument_list|)
expr_stmt|;
return|return
name|VT
return|;
block|}
block|}
return|return
name|VT
return|;
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
name|EVT
operator|&
name|RegisterVT
argument_list|)
decl|const
decl_stmt|;
comment|/// getTgtMemIntrinsic: Given an intrinsic, checks if on the target the
comment|/// intrinsic will need to map to a MemIntrinsicNode (touches memory). If
comment|/// this is the case, it returns true and store the intrinsic
comment|/// information into the IntrinsicInfo that was passed to the function.
typedef|typedef
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
name|IntrinisicInfo
typedef|;
name|virtual
name|bool
name|getTgtMemIntrinsic
parameter_list|(
name|IntrinsicInfo
modifier|&
name|Info
parameter_list|,
name|CallInst
modifier|&
name|I
parameter_list|,
name|unsigned
name|Intrinsic
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// getWidenVectorType: given a vector type, returns the type to widen to
comment|/// (e.g., v7i8 to v8i8). If the vector type is legal, it returns itself.
comment|/// If there is no vector type that we want to widen to, returns MVT::Other
comment|/// When and were to widen is target dependent based on the cost of
comment|/// scalarizing vs using the wider vector type.
name|virtual
name|EVT
name|getWidenVectorType
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
decl_stmt|;
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
name|Imm
argument_list|,
name|EVT
name|VT
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
name|Mask
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
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
name|Mask
argument_list|,
name|EVT
name|VT
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
sizeof|sizeof
argument_list|(
name|OpActions
index|[
literal|0
index|]
index|[
literal|0
index|]
argument_list|)
operator|*
literal|8
operator|&&
literal|"Table isn't big enough!"
argument_list|)
expr_stmt|;
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
name|unsigned
name|J
init|=
name|I
operator|&
literal|31
decl_stmt|;
name|I
operator|=
name|I
operator|>>
literal|5
expr_stmt|;
return|return
call|(
name|LegalizeAction
call|)
argument_list|(
operator|(
name|OpActions
index|[
name|I
index|]
index|[
name|Op
index|]
operator|>>
operator|(
name|J
operator|*
literal|2
operator|)
operator|)
operator|&
literal|3
argument_list|)
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
name|LType
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|LType
operator|<
name|array_lengthof
argument_list|(
name|LoadExtActions
argument_list|)
operator|&&
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
sizeof|sizeof
argument_list|(
name|LoadExtActions
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
return|return
call|(
name|LegalizeAction
call|)
argument_list|(
operator|(
name|LoadExtActions
index|[
name|LType
index|]
operator|>>
operator|(
literal|2
operator|*
name|VT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
operator|)
operator|)
operator|&
literal|3
argument_list|)
return|;
block|}
comment|/// isLoadExtLegal - Return true if the specified load with extension is legal
comment|/// on this target.
name|bool
name|isLoadExtLegal
argument_list|(
name|unsigned
name|LType
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
name|getLoadExtAction
argument_list|(
name|LType
argument_list|,
name|VT
argument_list|)
operator|==
name|Legal
operator|||
name|getLoadExtAction
argument_list|(
name|LType
argument_list|,
name|VT
argument_list|)
operator|==
name|Custom
operator|)
return|;
block|}
comment|/// getTruncStoreAction - Return how this store with truncation should be
comment|/// treated: either it is legal, needs to be promoted to a larger size, needs
comment|/// to be expanded to some other code sequence, or the target has a custom
comment|/// expander for it.
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
name|assert
argument_list|(
operator|(
name|unsigned
operator|)
name|ValVT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
operator|<
name|array_lengthof
argument_list|(
name|TruncStoreActions
argument_list|)
operator|&&
operator|(
name|unsigned
operator|)
name|MemVT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
operator|<
sizeof|sizeof
argument_list|(
name|TruncStoreActions
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
return|return
call|(
name|LegalizeAction
call|)
argument_list|(
operator|(
name|TruncStoreActions
index|[
name|ValVT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
index|]
operator|>>
operator|(
literal|2
operator|*
name|MemVT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
operator|)
operator|)
operator|&
literal|3
argument_list|)
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
name|EVT
name|VT
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|IdxMode
operator|<
name|array_lengthof
argument_list|(
name|IndexedModeActions
index|[
literal|0
index|]
index|[
literal|0
index|]
argument_list|)
operator|&&
operator|(
operator|(
name|unsigned
operator|)
name|VT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
operator|)
operator|<
name|MVT
operator|::
name|LAST_VALUETYPE
operator|&&
literal|"Table isn't big enough!"
argument_list|)
expr_stmt|;
return|return
call|(
name|LegalizeAction
call|)
argument_list|(
operator|(
name|IndexedModeActions
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
literal|0
index|]
index|[
name|IdxMode
index|]
operator|)
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
argument_list|)
operator|==
name|Legal
operator|||
name|getIndexedLoadAction
argument_list|(
name|IdxMode
argument_list|,
name|VT
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
name|EVT
name|VT
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|IdxMode
operator|<
name|array_lengthof
argument_list|(
name|IndexedModeActions
index|[
literal|0
index|]
index|[
literal|1
index|]
argument_list|)
operator|&&
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
name|MVT
operator|::
name|LAST_VALUETYPE
operator|&&
literal|"Table isn't big enough!"
argument_list|)
expr_stmt|;
return|return
call|(
name|LegalizeAction
call|)
argument_list|(
operator|(
name|IndexedModeActions
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
literal|1
index|]
index|[
name|IdxMode
index|]
operator|)
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
argument_list|)
operator|==
name|Legal
operator|||
name|getIndexedStoreAction
argument_list|(
name|IdxMode
argument_list|,
name|VT
argument_list|)
operator|==
name|Custom
operator|)
return|;
block|}
comment|/// getConvertAction - Return how the conversion should be treated:
comment|/// either it is legal, needs to be promoted to a larger size, needs to be
comment|/// expanded to some other code sequence, or the target has a custom expander
comment|/// for it.
name|LegalizeAction
name|getConvertAction
argument_list|(
name|EVT
name|FromVT
argument_list|,
name|EVT
name|ToVT
argument_list|)
decl|const
block|{
name|assert
argument_list|(
operator|(
name|unsigned
operator|)
name|FromVT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
operator|<
name|array_lengthof
argument_list|(
name|ConvertActions
argument_list|)
operator|&&
operator|(
name|unsigned
operator|)
name|ToVT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
operator|<
sizeof|sizeof
argument_list|(
name|ConvertActions
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
return|return
call|(
name|LegalizeAction
call|)
argument_list|(
operator|(
name|ConvertActions
index|[
name|FromVT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
index|]
operator|>>
operator|(
literal|2
operator|*
name|ToVT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
operator|)
operator|)
operator|&
literal|3
argument_list|)
return|;
block|}
comment|/// isConvertLegal - Return true if the specified conversion is legal
comment|/// on this target.
name|bool
name|isConvertLegal
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
name|isTypeLegal
argument_list|(
name|FromVT
argument_list|)
operator|&&
name|isTypeLegal
argument_list|(
name|ToVT
argument_list|)
operator|&&
operator|(
name|getConvertAction
argument_list|(
name|FromVT
argument_list|,
name|ToVT
argument_list|)
operator|==
name|Legal
operator|||
name|getConvertAction
argument_list|(
name|FromVT
argument_list|,
name|ToVT
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
name|EVT
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
name|getSimpleVT
argument_list|()
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
operator|>>
operator|(
literal|2
operator|*
name|VT
operator|.
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
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
name|EVT
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
name|EVT
name|getTypeToPromoteTo
argument_list|(
name|unsigned
name|Op
argument_list|,
name|EVT
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
name|getSimpleVT
argument_list|()
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
name|EVT
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
name|getSimpleVT
argument_list|()
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
specifier|const
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
name|EVT
name|VT
init|=
name|EVT
operator|::
name|getEVT
argument_list|(
name|Ty
argument_list|,
name|AllowUnknown
argument_list|)
decl_stmt|;
return|return
name|VT
operator|==
name|MVT
operator|::
name|iPTR
condition|?
name|PointerTy
else|:
name|VT
return|;
block|}
comment|/// getByValTypeAlignment - Return the desired alignment for ByVal aggregate
comment|/// function arguments in the caller parameter area.  This is the actual
comment|/// alignment, not its logarithm.
name|virtual
name|unsigned
name|getByValTypeAlignment
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// getRegisterType - Return the type of registers that this ValueType will
comment|/// eventually require.
name|EVT
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
name|EVT
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
decl_stmt|,
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
name|assert
argument_list|(
literal|0
operator|&&
literal|"Unsupported extended type!"
argument_list|)
expr_stmt|;
return|return
name|EVT
argument_list|(
name|MVT
operator|::
name|Other
argument_list|)
return|;
comment|// Not reached
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
decl_stmt|,
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
name|assert
argument_list|(
literal|0
operator|&&
literal|"Unsupported extended type!"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
comment|// Not reached
block|}
comment|/// ShouldShrinkFPConstant - If true, then instruction selection should
comment|/// seek to shrink the FP constant of the specified type to a smaller type
comment|/// in order to save space and / or reduce runtime.
name|virtual
name|bool
name|ShouldShrinkFPConstant
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
comment|/// performance threshold for such a replacement.
comment|/// @brief Get maximum # of store operations permitted for llvm.memset
name|unsigned
name|getMaxStoresPerMemset
argument_list|()
specifier|const
block|{
return|return
name|maxStoresPerMemset
return|;
block|}
comment|/// This function returns the maximum number of store operations permitted
comment|/// to replace a call to llvm.memcpy. The value is set by the target at the
comment|/// performance threshold for such a replacement.
comment|/// @brief Get maximum # of store operations permitted for llvm.memcpy
name|unsigned
name|getMaxStoresPerMemcpy
argument_list|()
specifier|const
block|{
return|return
name|maxStoresPerMemcpy
return|;
block|}
comment|/// This function returns the maximum number of store operations permitted
comment|/// to replace a call to llvm.memmove. The value is set by the target at the
comment|/// performance threshold for such a replacement.
comment|/// @brief Get maximum # of store operations permitted for llvm.memmove
name|unsigned
name|getMaxStoresPerMemmove
argument_list|()
specifier|const
block|{
return|return
name|maxStoresPerMemmove
return|;
block|}
comment|/// This function returns true if the target allows unaligned memory accesses.
comment|/// of the specified type. This is used, for example, in situations where an
comment|/// array copy/move/set is  converted to a sequence of store operations. It's
comment|/// use helps to ensure that such replacements don't generate code that causes
comment|/// an alignment error  (trap) on the target machine.
comment|/// @brief Determine if the target supports unaligned memory accesses.
name|virtual
name|bool
name|allowsUnalignedMemoryAccesses
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
comment|/// This function returns true if the target would benefit from code placement
comment|/// optimization.
comment|/// @brief Determine if the target should perform code placement optimization.
name|bool
name|shouldOptimizeCodePlacement
argument_list|()
specifier|const
block|{
return|return
name|benefitFromCodePlacementOpt
return|;
block|}
comment|/// getOptimalMemOpType - Returns the target specific optimal type for load
comment|/// and store operations as a result of memset, memcpy, and memmove lowering.
comment|/// It returns EVT::iAny if SelectionDAG should be responsible for
comment|/// determining it.
name|virtual
name|EVT
name|getOptimalMemOpType
argument_list|(
name|uint64_t
name|Size
argument_list|,
name|unsigned
name|Align
argument_list|,
name|bool
name|isSrcConst
argument_list|,
name|bool
name|isSrcStr
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
block|{
return|return
name|MVT
operator|::
name|iAny
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
comment|/// getExceptionAddressRegister - If a physical register, this returns
comment|/// the register that receives the exception address on entry to a landing
comment|/// pad.
name|unsigned
name|getExceptionAddressRegister
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
comment|/// getIfCvtBlockLimit - returns the target specific if-conversion block size
comment|/// limit. Any block whose size is greater should not be predicated.
name|unsigned
name|getIfCvtBlockSizeLimit
argument_list|()
specifier|const
block|{
return|return
name|IfCvtBlockSizeLimit
return|;
block|}
comment|/// getIfCvtDupBlockLimit - returns the target specific size limit for a
comment|/// block to be considered for duplication. Any block whose size is greater
comment|/// should not be duplicated to facilitate its predication.
name|unsigned
name|getIfCvtDupBlockSizeLimit
argument_list|()
specifier|const
block|{
return|return
name|IfCvtDupBlockSizeLimit
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
comment|/// getPreIndexedAddressParts - returns true by value, base pointer and
comment|/// offset pointer and addressing mode by reference if the node's address
comment|/// can be legally represented as pre-indexed load / store address.
name|virtual
name|bool
name|getPreIndexedAddressParts
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|SDValue
operator|&
name|Base
argument_list|,
name|SDValue
operator|&
name|Offset
argument_list|,
name|ISD
operator|::
name|MemIndexedMode
operator|&
name|AM
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
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
name|SDNode
operator|*
name|N
argument_list|,
name|SDNode
operator|*
name|Op
argument_list|,
name|SDValue
operator|&
name|Base
argument_list|,
name|SDValue
operator|&
name|Offset
argument_list|,
name|ISD
operator|::
name|MemIndexedMode
operator|&
name|AM
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// getPICJumpTableRelocaBase - Returns relocation base for the given PIC
comment|/// jumptable.
name|virtual
name|SDValue
name|getPICJumpTableRelocBase
argument_list|(
name|SDValue
name|Table
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
comment|/// isOffsetFoldingLegal - Return true if folding a constant offset
comment|/// with the given GlobalAddress is legal.  It is frequently not legal in
comment|/// PIC relocation models.
name|virtual
name|bool
name|isOffsetFoldingLegal
argument_list|(
specifier|const
name|GlobalAddressSDNode
operator|*
name|GA
argument_list|)
decl|const
decl_stmt|;
comment|/// getFunctionAlignment - Return the Log2 alignment of this function.
name|virtual
name|unsigned
name|getFunctionAlignment
argument_list|(
specifier|const
name|Function
operator|*
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// TargetLowering Optimization Methods
comment|//
comment|/// TargetLoweringOpt - A convenience struct that encapsulates a DAG, and two
comment|/// SDValues for returning information from TargetLowering to its clients
comment|/// that want to combine
struct|struct
name|TargetLoweringOpt
block|{
name|SelectionDAG
modifier|&
name|DAG
decl_stmt|;
name|SDValue
name|Old
decl_stmt|;
name|SDValue
name|New
decl_stmt|;
name|explicit
name|TargetLoweringOpt
argument_list|(
name|SelectionDAG
operator|&
name|InDAG
argument_list|)
operator|:
name|DAG
argument_list|(
argument|InDAG
argument_list|)
block|{}
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
parameter_list|(
name|SDValue
name|Op
parameter_list|,
specifier|const
name|APInt
modifier|&
name|Demanded
parameter_list|)
function_decl|;
comment|/// ShrinkDemandedOp - Convert x+y to (VT)((SmallVT)x+(SmallVT)y) if the
comment|/// casts are free.  This uses isZExtFree and ZERO_EXTEND for the widening
comment|/// cast, but it could be generalized for targets with other types of
comment|/// implicit widening casts.
name|bool
name|ShrinkDemandedOp
parameter_list|(
name|SDValue
name|Op
parameter_list|,
name|unsigned
name|BitWidth
parameter_list|,
specifier|const
name|APInt
modifier|&
name|Demanded
parameter_list|,
name|DebugLoc
name|dl
parameter_list|)
function_decl|;
block|}
struct|;
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
name|SDValue
name|Op
argument_list|,
specifier|const
name|APInt
operator|&
name|DemandedMask
argument_list|,
name|APInt
operator|&
name|KnownZero
argument_list|,
name|APInt
operator|&
name|KnownOne
argument_list|,
name|TargetLoweringOpt
operator|&
name|TLO
argument_list|,
name|unsigned
name|Depth
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// computeMaskedBitsForTargetNode - Determine which of the bits specified in
comment|/// Mask are known to be either zero or one and return them in the
comment|/// KnownZero/KnownOne bitsets.
name|virtual
name|void
name|computeMaskedBitsForTargetNode
argument_list|(
specifier|const
name|SDValue
name|Op
argument_list|,
specifier|const
name|APInt
operator|&
name|Mask
argument_list|,
name|APInt
operator|&
name|KnownZero
argument_list|,
name|APInt
operator|&
name|KnownOne
argument_list|,
specifier|const
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|unsigned
name|Depth
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// ComputeNumSignBitsForTargetNode - This method can be implemented by
comment|/// targets that want to expose additional information about sign bits to the
comment|/// DAG Combiner.
name|virtual
name|unsigned
name|ComputeNumSignBitsForTargetNode
argument_list|(
name|SDValue
name|Op
argument_list|,
name|unsigned
name|Depth
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
struct|struct
name|DAGCombinerInfo
block|{
name|void
modifier|*
name|DC
decl_stmt|;
comment|// The DAG Combiner object.
name|bool
name|BeforeLegalize
decl_stmt|;
name|bool
name|BeforeLegalizeOps
decl_stmt|;
name|bool
name|CalledByLegalizer
decl_stmt|;
name|public
label|:
name|SelectionDAG
modifier|&
name|DAG
decl_stmt|;
name|DAGCombinerInfo
argument_list|(
argument|SelectionDAG&dag
argument_list|,
argument|bool bl
argument_list|,
argument|bool blo
argument_list|,
argument|bool cl
argument_list|,
argument|void *dc
argument_list|)
block|:
name|DC
argument_list|(
name|dc
argument_list|)
operator|,
name|BeforeLegalize
argument_list|(
name|bl
argument_list|)
operator|,
name|BeforeLegalizeOps
argument_list|(
name|blo
argument_list|)
operator|,
name|CalledByLegalizer
argument_list|(
name|cl
argument_list|)
operator|,
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
name|BeforeLegalize
return|;
block|}
name|bool
name|isBeforeLegalizeOps
argument_list|()
specifier|const
block|{
return|return
name|BeforeLegalizeOps
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
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
name|SDValue
name|CombineTo
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|SDValue
operator|>
operator|&
name|To
argument_list|,
name|bool
name|AddTo
operator|=
name|true
argument_list|)
decl_stmt|;
name|SDValue
name|CombineTo
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|,
name|SDValue
name|Res
parameter_list|,
name|bool
name|AddTo
init|=
name|true
parameter_list|)
function_decl|;
name|SDValue
name|CombineTo
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|,
name|SDValue
name|Res0
parameter_list|,
name|SDValue
name|Res1
parameter_list|,
name|bool
name|AddTo
init|=
name|true
parameter_list|)
function_decl|;
name|void
name|CommitTargetLoweringOpt
parameter_list|(
specifier|const
name|TargetLoweringOpt
modifier|&
name|TLO
parameter_list|)
function_decl|;
block|}
struct|;
comment|/// SimplifySetCC - Try to simplify a setcc built with the specified operands
comment|/// and cc. If it is unable to simplify it, return a null SDValue.
name|SDValue
name|SimplifySetCC
argument_list|(
name|EVT
name|VT
argument_list|,
name|SDValue
name|N0
argument_list|,
name|SDValue
name|N1
argument_list|,
name|ISD
operator|::
name|CondCode
name|Cond
argument_list|,
name|bool
name|foldBooleans
argument_list|,
name|DAGCombinerInfo
operator|&
name|DCI
argument_list|,
name|DebugLoc
name|dl
argument_list|)
decl|const
decl_stmt|;
comment|/// isGAPlusOffset - Returns true (and the GlobalValue and the offset) if the
comment|/// node is a GlobalAddress + offset.
name|virtual
name|bool
name|isGAPlusOffset
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|GlobalValue
operator|*
operator|&
name|GA
argument_list|,
name|int64_t
operator|&
name|Offset
argument_list|)
decl|const
decl_stmt|;
comment|/// isConsecutiveLoad - Return true if LD is loading 'Bytes' bytes from a
comment|/// location that is 'Dist' units away from the location that the 'Base' load
comment|/// is loading from.
name|bool
name|isConsecutiveLoad
argument_list|(
name|LoadSDNode
operator|*
name|LD
argument_list|,
name|LoadSDNode
operator|*
name|Base
argument_list|,
name|unsigned
name|Bytes
argument_list|,
name|int
name|Dist
argument_list|,
specifier|const
name|MachineFrameInfo
operator|*
name|MFI
argument_list|)
decl|const
decl_stmt|;
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
name|SDNode
operator|*
name|N
argument_list|,
name|DAGCombinerInfo
operator|&
name|DCI
argument_list|)
decl|const
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// TargetLowering Configuration Methods - These methods should be invoked by
comment|// the derived class constructor to configure this object for the target.
comment|//
name|protected
label|:
comment|/// setUsesGlobalOffsetTable - Specify that this target does or doesn't use a
comment|/// GOT for PC-relative code.
name|void
name|setUsesGlobalOffsetTable
parameter_list|(
name|bool
name|V
parameter_list|)
block|{
name|UsesGlobalOffsetTable
operator|=
name|V
expr_stmt|;
block|}
comment|/// setShiftAmountType - Describe the type that should be used for shift
comment|/// amounts.  This type defaults to the pointer type.
name|void
name|setShiftAmountType
parameter_list|(
name|MVT
name|VT
parameter_list|)
block|{
name|ShiftAmountTy
operator|=
name|VT
expr_stmt|;
block|}
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
comment|/// setSchedulingPreference - Specify the target scheduling preference.
name|void
name|setSchedulingPreference
parameter_list|(
name|SchedPreference
name|Pref
parameter_list|)
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
parameter_list|()
block|{
name|SelectIsExpensive
operator|=
name|true
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
name|EVT
name|VT
parameter_list|,
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
name|getSimpleVT
argument_list|()
operator|.
name|SimpleTy
index|]
operator|=
name|RC
expr_stmt|;
block|}
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
name|unsigned
name|I
init|=
operator|(
name|unsigned
operator|)
name|VT
operator|.
name|SimpleTy
decl_stmt|;
name|unsigned
name|J
init|=
name|I
operator|&
literal|31
decl_stmt|;
name|I
operator|=
name|I
operator|>>
literal|5
expr_stmt|;
name|OpActions
index|[
name|I
index|]
index|[
name|Op
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
name|J
operator|*
literal|2
operator|)
operator|)
expr_stmt|;
name|OpActions
index|[
name|I
index|]
index|[
name|Op
index|]
operator||=
operator|(
name|uint64_t
operator|)
name|Action
operator|<<
operator|(
name|J
operator|*
literal|2
operator|)
expr_stmt|;
block|}
comment|/// setLoadExtAction - Indicate that the specified load with extension does
comment|/// not work with the with specified type and indicate what to do about it.
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
operator|(
name|unsigned
operator|)
name|VT
operator|.
name|SimpleTy
operator|<
sizeof|sizeof
argument_list|(
name|LoadExtActions
index|[
literal|0
index|]
argument_list|)
operator|*
literal|4
operator|&&
name|ExtType
operator|<
name|array_lengthof
argument_list|(
name|LoadExtActions
argument_list|)
operator|&&
literal|"Table isn't big enough!"
argument_list|)
expr_stmt|;
name|LoadExtActions
index|[
name|ExtType
index|]
operator|&=
operator|~
operator|(
name|uint64_t
argument_list|(
literal|3UL
argument_list|)
operator|<<
name|VT
operator|.
name|SimpleTy
operator|*
literal|2
operator|)
expr_stmt|;
name|LoadExtActions
index|[
name|ExtType
index|]
operator||=
operator|(
name|uint64_t
operator|)
name|Action
operator|<<
name|VT
operator|.
name|SimpleTy
operator|*
literal|2
expr_stmt|;
block|}
comment|/// setTruncStoreAction - Indicate that the specified truncating store does
comment|/// not work with the with specified type and indicate what to do about it.
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
operator|(
name|unsigned
operator|)
name|ValVT
operator|.
name|SimpleTy
operator|<
name|array_lengthof
argument_list|(
name|TruncStoreActions
argument_list|)
operator|&&
operator|(
name|unsigned
operator|)
name|MemVT
operator|.
name|SimpleTy
operator|<
sizeof|sizeof
argument_list|(
name|TruncStoreActions
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
name|TruncStoreActions
index|[
name|ValVT
operator|.
name|SimpleTy
index|]
operator|&=
operator|~
operator|(
name|uint64_t
argument_list|(
literal|3UL
argument_list|)
operator|<<
name|MemVT
operator|.
name|SimpleTy
operator|*
literal|2
operator|)
expr_stmt|;
name|TruncStoreActions
index|[
name|ValVT
operator|.
name|SimpleTy
index|]
operator||=
operator|(
name|uint64_t
operator|)
name|Action
operator|<<
name|MemVT
operator|.
name|SimpleTy
operator|*
literal|2
expr_stmt|;
block|}
comment|/// setIndexedLoadAction - Indicate that the specified indexed load does or
comment|/// does not work with the with specified type and indicate what to do abort
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
operator|(
name|unsigned
operator|)
name|VT
operator|.
name|SimpleTy
operator|<
name|MVT
operator|::
name|LAST_VALUETYPE
operator|&&
name|IdxMode
operator|<
name|array_lengthof
argument_list|(
name|IndexedModeActions
index|[
literal|0
index|]
index|[
literal|0
index|]
argument_list|)
operator|&&
literal|"Table isn't big enough!"
argument_list|)
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
literal|0
index|]
index|[
name|IdxMode
index|]
operator|=
operator|(
name|uint8_t
operator|)
name|Action
expr_stmt|;
block|}
comment|/// setIndexedStoreAction - Indicate that the specified indexed store does or
comment|/// does not work with the with specified type and indicate what to do about
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
operator|(
name|unsigned
operator|)
name|VT
operator|.
name|SimpleTy
operator|<
name|MVT
operator|::
name|LAST_VALUETYPE
operator|&&
name|IdxMode
operator|<
name|array_lengthof
argument_list|(
name|IndexedModeActions
index|[
literal|0
index|]
index|[
literal|1
index|]
argument_list|)
operator|&&
literal|"Table isn't big enough!"
argument_list|)
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
literal|1
index|]
index|[
name|IdxMode
index|]
operator|=
operator|(
name|uint8_t
operator|)
name|Action
expr_stmt|;
block|}
comment|/// setConvertAction - Indicate that the specified conversion does or does
comment|/// not work with the with specified type and indicate what to do about it.
name|void
name|setConvertAction
parameter_list|(
name|MVT
name|FromVT
parameter_list|,
name|MVT
name|ToVT
parameter_list|,
name|LegalizeAction
name|Action
parameter_list|)
block|{
name|assert
argument_list|(
operator|(
name|unsigned
operator|)
name|FromVT
operator|.
name|SimpleTy
operator|<
name|array_lengthof
argument_list|(
name|ConvertActions
argument_list|)
operator|&&
operator|(
name|unsigned
operator|)
name|ToVT
operator|.
name|SimpleTy
operator|<
sizeof|sizeof
argument_list|(
name|ConvertActions
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
name|ConvertActions
index|[
name|FromVT
operator|.
name|SimpleTy
index|]
operator|&=
operator|~
operator|(
name|uint64_t
argument_list|(
literal|3UL
argument_list|)
operator|<<
name|ToVT
operator|.
name|SimpleTy
operator|*
literal|2
operator|)
expr_stmt|;
name|ConvertActions
index|[
name|FromVT
operator|.
name|SimpleTy
index|]
operator||=
operator|(
name|uint64_t
operator|)
name|Action
operator|<<
name|ToVT
operator|.
name|SimpleTy
operator|*
literal|2
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
name|CondCodeActions
index|[
operator|(
name|unsigned
operator|)
name|CC
index|]
operator|&=
operator|~
operator|(
name|uint64_t
argument_list|(
literal|3UL
argument_list|)
operator|<<
name|VT
operator|.
name|SimpleTy
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
operator||=
operator|(
name|uint64_t
operator|)
name|Action
operator|<<
name|VT
operator|.
name|SimpleTy
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
comment|/// setIfCvtBlockSizeLimit - Set the target's if-conversion block size
comment|/// limit (in number of instructions); default is 2.
name|void
name|setIfCvtBlockSizeLimit
parameter_list|(
name|unsigned
name|Limit
parameter_list|)
block|{
name|IfCvtBlockSizeLimit
operator|=
name|Limit
expr_stmt|;
block|}
comment|/// setIfCvtDupBlockSizeLimit - Set the target's block size limit (in number
comment|/// of instructions) to be considered for code duplication during
comment|/// if-conversion; default is 2.
name|void
name|setIfCvtDupBlockSizeLimit
parameter_list|(
name|unsigned
name|Limit
parameter_list|)
block|{
name|IfCvtDupBlockSizeLimit
operator|=
name|Limit
expr_stmt|;
block|}
comment|/// setPrefLoopAlignment - Set the target's preferred loop alignment. Default
comment|/// alignment is zero, it means the target does not care about loop alignment.
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
name|public
label|:
name|virtual
specifier|const
name|TargetSubtarget
modifier|*
name|getSubtarget
parameter_list|()
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Not Implemented"
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
comment|// this is here to silence compiler errors
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Lowering methods - These methods must be implemented by targets so that
comment|// the SelectionDAGLowering code knows how to lower these.
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
name|SDValue
name|Chain
argument_list|,
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
name|bool
name|isVarArg
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|Ins
argument_list|,
name|DebugLoc
name|dl
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|InVals
argument_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Not Implemented"
argument_list|)
expr_stmt|;
return|return
name|SDValue
argument_list|()
return|;
comment|// this is here to silence compiler errors
block|}
comment|/// LowerCallTo - This function lowers an abstract call to a function into an
comment|/// actual call.  This returns a pair of operands.  The first element is the
comment|/// return value for the function (if RetTy is not VoidTy).  The second
comment|/// element is the outgoing token chain. It calls LowerCall to do the actual
comment|/// lowering.
struct|struct
name|ArgListEntry
block|{
name|SDValue
name|Node
decl_stmt|;
specifier|const
name|Type
modifier|*
name|Ty
decl_stmt|;
name|bool
name|isSExt
range|:
literal|1
decl_stmt|;
name|bool
name|isZExt
range|:
literal|1
decl_stmt|;
name|bool
name|isInReg
range|:
literal|1
decl_stmt|;
name|bool
name|isSRet
range|:
literal|1
decl_stmt|;
name|bool
name|isNest
range|:
literal|1
decl_stmt|;
name|bool
name|isByVal
range|:
literal|1
decl_stmt|;
name|uint16_t
name|Alignment
decl_stmt|;
name|ArgListEntry
argument_list|()
operator|:
name|isSExt
argument_list|(
name|false
argument_list|)
operator|,
name|isZExt
argument_list|(
name|false
argument_list|)
operator|,
name|isInReg
argument_list|(
name|false
argument_list|)
operator|,
name|isSRet
argument_list|(
name|false
argument_list|)
operator|,
name|isNest
argument_list|(
name|false
argument_list|)
operator|,
name|isByVal
argument_list|(
name|false
argument_list|)
operator|,
name|Alignment
argument_list|(
literal|0
argument_list|)
block|{ }
block|}
struct|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|ArgListEntry
operator|>
name|ArgListTy
expr_stmt|;
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
argument|SDValue Chain
argument_list|,
argument|const Type *RetTy
argument_list|,
argument|bool RetSExt
argument_list|,
argument|bool RetZExt
argument_list|,
argument|bool isVarArg
argument_list|,
argument|bool isInreg
argument_list|,
argument|unsigned NumFixedArgs
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool isTailCall
argument_list|,
argument|bool isReturnValueUsed
argument_list|,
argument|SDValue Callee
argument_list|,
argument|ArgListTy&Args
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|DebugLoc dl
argument_list|)
expr_stmt|;
comment|/// LowerCall - This hook must be implemented to lower calls into the
comment|/// the specified DAG. The outgoing arguments to the call are described
comment|/// by the Outs array, and the values to be returned by the call are
comment|/// described by the Ins array. The implementation should fill in the
comment|/// InVals array with legal-type return values from the call, and return
comment|/// the resulting token chain value.
comment|///
comment|/// The isTailCall flag here is normative. If it is true, the
comment|/// implementation must emit a tail call. The
comment|/// IsEligibleForTailCallOptimization hook should be used to catch
comment|/// cases that cannot be handled.
comment|///
name|virtual
name|SDValue
name|LowerCall
argument_list|(
name|SDValue
name|Chain
argument_list|,
name|SDValue
name|Callee
argument_list|,
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
name|bool
name|isVarArg
argument_list|,
name|bool
name|isTailCall
argument_list|,
specifier|const
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
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|Ins
argument_list|,
name|DebugLoc
name|dl
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|InVals
argument_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Not Implemented"
argument_list|)
expr_stmt|;
return|return
name|SDValue
argument_list|()
return|;
comment|// this is here to silence compiler errors
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
name|Chain
argument_list|,
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
name|bool
name|isVarArg
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|OutputArg
operator|>
operator|&
name|Outs
argument_list|,
name|DebugLoc
name|dl
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Not Implemented"
argument_list|)
expr_stmt|;
return|return
name|SDValue
argument_list|()
return|;
comment|// this is here to silence compiler errors
block|}
comment|/// EmitTargetCodeForMemcpy - Emit target-specific code that performs a
comment|/// memcpy. This can be used by targets to provide code sequences for cases
comment|/// that don't fit the target's parameters for simple loads/stores and can be
comment|/// more efficient than using a library call. This function can return a null
comment|/// SDValue if the target declines to use custom code and a different
comment|/// lowering strategy should be used.
comment|///
comment|/// If AlwaysInline is true, the size is constant and the target should not
comment|/// emit any calls and is strongly encouraged to attempt to emit inline code
comment|/// even if it is beyond the usual threshold because this intrinsic is being
comment|/// expanded in a place where calls are not feasible (e.g. within the prologue
comment|/// for another call). If the target chooses to decline an AlwaysInline
comment|/// request here, legalize will resort to using simple loads and stores.
name|virtual
name|SDValue
name|EmitTargetCodeForMemcpy
parameter_list|(
name|SelectionDAG
modifier|&
name|DAG
parameter_list|,
name|DebugLoc
name|dl
parameter_list|,
name|SDValue
name|Chain
parameter_list|,
name|SDValue
name|Op1
parameter_list|,
name|SDValue
name|Op2
parameter_list|,
name|SDValue
name|Op3
parameter_list|,
name|unsigned
name|Align
parameter_list|,
name|bool
name|AlwaysInline
parameter_list|,
specifier|const
name|Value
modifier|*
name|DstSV
parameter_list|,
name|uint64_t
name|DstOff
parameter_list|,
specifier|const
name|Value
modifier|*
name|SrcSV
parameter_list|,
name|uint64_t
name|SrcOff
parameter_list|)
block|{
return|return
name|SDValue
argument_list|()
return|;
block|}
comment|/// EmitTargetCodeForMemmove - Emit target-specific code that performs a
comment|/// memmove. This can be used by targets to provide code sequences for cases
comment|/// that don't fit the target's parameters for simple loads/stores and can be
comment|/// more efficient than using a library call. This function can return a null
comment|/// SDValue if the target declines to use custom code and a different
comment|/// lowering strategy should be used.
name|virtual
name|SDValue
name|EmitTargetCodeForMemmove
parameter_list|(
name|SelectionDAG
modifier|&
name|DAG
parameter_list|,
name|DebugLoc
name|dl
parameter_list|,
name|SDValue
name|Chain
parameter_list|,
name|SDValue
name|Op1
parameter_list|,
name|SDValue
name|Op2
parameter_list|,
name|SDValue
name|Op3
parameter_list|,
name|unsigned
name|Align
parameter_list|,
specifier|const
name|Value
modifier|*
name|DstSV
parameter_list|,
name|uint64_t
name|DstOff
parameter_list|,
specifier|const
name|Value
modifier|*
name|SrcSV
parameter_list|,
name|uint64_t
name|SrcOff
parameter_list|)
block|{
return|return
name|SDValue
argument_list|()
return|;
block|}
comment|/// EmitTargetCodeForMemset - Emit target-specific code that performs a
comment|/// memset. This can be used by targets to provide code sequences for cases
comment|/// that don't fit the target's parameters for simple stores and can be more
comment|/// efficient than using a library call. This function can return a null
comment|/// SDValue if the target declines to use custom code and a different
comment|/// lowering strategy should be used.
name|virtual
name|SDValue
name|EmitTargetCodeForMemset
parameter_list|(
name|SelectionDAG
modifier|&
name|DAG
parameter_list|,
name|DebugLoc
name|dl
parameter_list|,
name|SDValue
name|Chain
parameter_list|,
name|SDValue
name|Op1
parameter_list|,
name|SDValue
name|Op2
parameter_list|,
name|SDValue
name|Op3
parameter_list|,
name|unsigned
name|Align
parameter_list|,
specifier|const
name|Value
modifier|*
name|DstSV
parameter_list|,
name|uint64_t
name|DstOff
parameter_list|)
block|{
return|return
name|SDValue
argument_list|()
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
decl_stmt|;
comment|/// LowerOperation - This callback is invoked for operations that are
comment|/// unsupported by the target, which are registered to use 'custom' lowering,
comment|/// and whose defined values are all legal.
comment|/// If the target has no operations that require custom lowering, it need not
comment|/// implement this.  The default implementation of this aborts.
name|virtual
name|SDValue
name|LowerOperation
parameter_list|(
name|SDValue
name|Op
parameter_list|,
name|SelectionDAG
modifier|&
name|DAG
parameter_list|)
function_decl|;
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
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"ReplaceNodeResults not implemented for this target!"
argument_list|)
expr_stmt|;
block|}
comment|/// IsEligibleForTailCallOptimization - Check whether the call is eligible for
comment|/// tail call optimization. Targets which want to do tail call optimization
comment|/// should override this function.
name|virtual
name|bool
name|IsEligibleForTailCallOptimization
argument_list|(
name|SDValue
name|Callee
argument_list|,
name|CallingConv
operator|::
name|ID
name|CalleeCC
argument_list|,
name|bool
name|isVarArg
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|Ins
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
block|{
comment|// Conservative default: no calls are eligible.
return|return
name|false
return|;
block|}
comment|/// GetPossiblePreceedingTailCall - Get preceeding TailCallNodeOpCode node if
comment|/// it exists. Skip a possible ISD::TokenFactor.
specifier|static
name|SDValue
name|GetPossiblePreceedingTailCall
parameter_list|(
name|SDValue
name|Chain
parameter_list|,
name|unsigned
name|TailCallNodeOpCode
parameter_list|)
block|{
if|if
condition|(
name|Chain
operator|.
name|getOpcode
argument_list|()
operator|==
name|TailCallNodeOpCode
condition|)
block|{
return|return
name|Chain
return|;
block|}
elseif|else
if|if
condition|(
name|Chain
operator|.
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TokenFactor
condition|)
block|{
if|if
condition|(
name|Chain
operator|.
name|getNumOperands
argument_list|()
operator|&&
name|Chain
operator|.
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|.
name|getOpcode
argument_list|()
operator|==
name|TailCallNodeOpCode
condition|)
return|return
name|Chain
operator|.
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
return|return
name|Chain
return|;
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
name|MachineFunction
operator|&
argument_list|,
name|MachineModuleInfo
operator|*
argument_list|,
name|DwarfWriter
operator|*
argument_list|,
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
argument_list|,
name|unsigned
operator|>
operator|&
argument_list|,
name|DenseMap
operator|<
specifier|const
name|BasicBlock
operator|*
argument_list|,
name|MachineBasicBlock
operator|*
operator|>
operator|&
argument_list|,
name|DenseMap
operator|<
specifier|const
name|AllocaInst
operator|*
argument_list|,
name|int
operator|>
operator|&
ifndef|#
directive|ifndef
name|NDEBUG
argument_list|,
name|SmallSet
operator|<
name|Instruction
operator|*
argument_list|,
literal|8
operator|>
operator|&
name|CatchInfoLost
endif|#
directive|endif
argument_list|)
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
name|CI
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
name|EVT
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
comment|/// ComputeConstraintToUse - Determines the constraint code and constraint
comment|/// type to use for the specific AsmOperandInfo, setting
comment|/// OpInfo.ConstraintCode and OpInfo.ConstraintType.  If the actual operand
comment|/// being passed in is available, it can be passed in as Op, otherwise an
comment|/// empty SDValue can be passed. If hasMemory is true it means one of the asm
comment|/// constraint of the inline asm instruction being processed is 'm'.
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
name|bool
name|hasMemory
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
comment|/// getRegClassForInlineAsmConstraint - Given a constraint letter (e.g. "r"),
comment|/// return a list of registers that can be used to satisfy the constraint.
comment|/// This should only be used for C_RegisterClass constraints.
name|virtual
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|getRegClassForInlineAsmConstraint
argument_list|(
argument|const std::string&Constraint
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
expr_stmt|;
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
comment|/// vector.  If it is invalid, don't add anything to Ops. If hasMemory is true
comment|/// it means one of the asm constraint of the inline asm instruction being
comment|/// processed is 'm'.
name|virtual
name|void
name|LowerAsmOperandForConstraint
argument_list|(
name|SDValue
name|Op
argument_list|,
name|char
name|ConstraintLetter
argument_list|,
name|bool
name|hasMemory
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
comment|// Instruction Emitting Hooks
comment|//
comment|// EmitInstrWithCustomInserter - This method should be implemented by targets
comment|// that mark instructions with the 'usesCustomInserter' flag.  These
comment|// instructions are special in various ways, which require special support to
comment|// insert.  The specified MachineInstr is created but not inserted into any
comment|// basic blocks, and this method is called to expand it into a sequence of
comment|// instructions, potentially also creating new basic blocks and control flow.
comment|// When new basic blocks are inserted and the edges from MBB to its successors
comment|// are modified, the method should insert pairs of<OldSucc, NewSucc> into the
comment|// DenseMap.
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
argument_list|,
name|DenseMap
operator|<
name|MachineBasicBlock
operator|*
argument_list|,
name|MachineBasicBlock
operator|*
operator|>
operator|*
name|EM
argument_list|)
decl|const
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// Addressing mode description hooks (used by LSR etc).
comment|//
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
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// isTruncateFree - Return true if it's free to truncate a value of
comment|/// type Ty1 to type Ty2. e.g. On x86 it's free to truncate a i32 value in
comment|/// register EAX to i16 by referencing its sub-register AX.
name|virtual
name|bool
name|isTruncateFree
argument_list|(
specifier|const
name|Type
operator|*
name|Ty1
argument_list|,
specifier|const
name|Type
operator|*
name|Ty2
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
name|VT1
argument_list|,
name|EVT
name|VT2
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// isZExtFree - Return true if any actual instruction that defines a
comment|/// value of type Ty1 implicit zero-extends the value to Ty2 in the result
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
specifier|const
name|Type
operator|*
name|Ty1
argument_list|,
specifier|const
name|Type
operator|*
name|Ty2
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
name|VT1
argument_list|,
name|EVT
name|VT2
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
name|VT1
argument_list|,
name|EVT
name|VT2
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Div utility functions
comment|//
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
name|TargetMachine
modifier|&
name|TM
decl_stmt|;
specifier|const
name|TargetData
modifier|*
name|TD
decl_stmt|;
name|TargetLoweringObjectFile
modifier|&
name|TLOF
decl_stmt|;
comment|/// PointerTy - The type to use for pointers, usually i32 or i64.
comment|///
name|MVT
name|PointerTy
decl_stmt|;
comment|/// IsLittleEndian - True if this is a little endian target.
comment|///
name|bool
name|IsLittleEndian
decl_stmt|;
comment|/// UsesGlobalOffsetTable - True if this target uses a GOT for PIC codegen.
comment|///
name|bool
name|UsesGlobalOffsetTable
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
comment|/// Pow2DivIsCheap - Tells the code generator that it shouldn't generate
comment|/// srl/add/sra for a signed divide by power of two, and let the target handle
comment|/// it.
name|bool
name|Pow2DivIsCheap
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
comment|/// ShiftAmountTy - The type to use for shift amounts, usually i8 or whatever
comment|/// PointerTy is.
name|MVT
name|ShiftAmountTy
decl_stmt|;
comment|/// BooleanContents - Information about the contents of the high-bits in
comment|/// boolean values held in a type wider than i1.  See getBooleanContents.
name|BooleanContent
name|BooleanContents
decl_stmt|;
comment|/// SchedPreferenceInfo - The target scheduling preference: shortest possible
comment|/// total cycles or lowest register usage.
name|SchedPreference
name|SchedPreferenceInfo
decl_stmt|;
comment|/// JumpBufSize - The size, in bytes, of the target's jmp_buf buffers
name|unsigned
name|JumpBufSize
decl_stmt|;
comment|/// JumpBufAlignment - The alignment, in bytes, of the target's jmp_buf
comment|/// buffers
name|unsigned
name|JumpBufAlignment
decl_stmt|;
comment|/// IfCvtBlockSizeLimit - The maximum allowed size for a block to be
comment|/// if-converted.
name|unsigned
name|IfCvtBlockSizeLimit
decl_stmt|;
comment|/// IfCvtDupBlockSizeLimit - The maximum allowed size for a block to be
comment|/// duplicated during if-conversion.
name|unsigned
name|IfCvtDupBlockSizeLimit
decl_stmt|;
comment|/// PrefLoopAlignment - The perferred loop alignment.
comment|///
name|unsigned
name|PrefLoopAlignment
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
name|EVT
name|RegisterTypeForVT
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
name|EVT
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
comment|/// This array is accessed using VT.getSimpleVT(), so it is subject to
comment|/// the MVT::MAX_ALLOWED_VALUETYPE * 2 bits.
name|uint64_t
name|OpActions
index|[
name|MVT
operator|::
name|MAX_ALLOWED_VALUETYPE
operator|/
operator|(
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
operator|*
literal|4
operator|)
index|]
index|[
name|ISD
operator|::
name|BUILTIN_OP_END
index|]
decl_stmt|;
comment|/// LoadExtActions - For each load of load extension type and each value type,
comment|/// keep a LegalizeAction that indicates how instruction selection should deal
comment|/// with the load.
name|uint64_t
name|LoadExtActions
index|[
name|ISD
operator|::
name|LAST_LOADEXT_TYPE
index|]
decl_stmt|;
comment|/// TruncStoreActions - For each truncating store, keep a LegalizeAction that
comment|/// indicates how instruction selection should deal with the store.
name|uint64_t
name|TruncStoreActions
index|[
name|MVT
operator|::
name|LAST_VALUETYPE
index|]
decl_stmt|;
comment|/// IndexedModeActions - For each indexed mode and each value type,
comment|/// keep a pair of LegalizeAction that indicates how instruction
comment|/// selection should deal with the load / store.  The first
comment|/// dimension is now the value_type for the reference.  The second
comment|/// dimension is the load [0] vs. store[1].  The third dimension
comment|/// represents the various modes for load store.
name|uint8_t
name|IndexedModeActions
index|[
name|MVT
operator|::
name|LAST_VALUETYPE
index|]
index|[
literal|2
index|]
index|[
name|ISD
operator|::
name|LAST_INDEXED_MODE
index|]
decl_stmt|;
comment|/// ConvertActions - For each conversion from source type to destination type,
comment|/// keep a LegalizeAction that indicates how instruction selection should
comment|/// deal with the conversion.
comment|/// Currently, this is used only for floating->floating conversions
comment|/// (FP_EXTEND and FP_ROUND).
name|uint64_t
name|ConvertActions
index|[
name|MVT
operator|::
name|LAST_VALUETYPE
index|]
decl_stmt|;
comment|/// CondCodeActions - For each condition code (ISD::CondCode) keep a
comment|/// LegalizeAction that indicates how instruction selection should
comment|/// deal with the condition code.
name|uint64_t
name|CondCodeActions
index|[
name|ISD
operator|::
name|SETCC_INVALID
index|]
decl_stmt|;
name|ValueTypeActionImpl
name|ValueTypeActions
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|EVT
operator|,
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
name|maxStoresPerMemset
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
name|maxStoresPerMemcpy
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
name|maxStoresPerMemmove
decl_stmt|;
comment|/// This field specifies whether the target can benefit from code placement
comment|/// optimization.
name|bool
name|benefitFromCodePlacementOpt
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

