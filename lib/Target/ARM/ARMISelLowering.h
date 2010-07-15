begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMISelLowering.h - ARM DAG Lowering Interface ----------*- C++ -*-===//
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
comment|// This file defines the interfaces that ARM uses to lower LLVM code into a
end_comment

begin_comment
comment|// selection DAG.
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
name|ARMISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|ARMISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"ARMSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLowering.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/CallingConvLower.h"
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
name|ARMConstantPoolValue
decl_stmt|;
name|namespace
name|ARMISD
block|{
comment|// ARM Specific DAG Nodes
enum|enum
name|NodeType
block|{
comment|// Start the numbering where the builtin ops and target ops leave off.
name|FIRST_NUMBER
init|=
name|ISD
operator|::
name|BUILTIN_OP_END
block|,
name|Wrapper
block|,
comment|// Wrapper - A wrapper node for TargetConstantPool,
comment|// TargetExternalSymbol, and TargetGlobalAddress.
name|WrapperJT
block|,
comment|// WrapperJT - A wrapper node for TargetJumpTable
name|CALL
block|,
comment|// Function call.
name|CALL_PRED
block|,
comment|// Function call that's predicable.
name|CALL_NOLINK
block|,
comment|// Function call with branch not branch-and-link.
name|tCALL
block|,
comment|// Thumb function call.
name|BRCOND
block|,
comment|// Conditional branch.
name|BR_JT
block|,
comment|// Jumptable branch.
name|BR2_JT
block|,
comment|// Jumptable branch (2 level - jumptable entry is a jump).
name|RET_FLAG
block|,
comment|// Return with a flag operand.
name|PIC_ADD
block|,
comment|// Add with a PC operand and a PIC label.
name|CMP
block|,
comment|// ARM compare instructions.
name|CMPZ
block|,
comment|// ARM compare that sets only Z flag.
name|CMPFP
block|,
comment|// ARM VFP compare instruction, sets FPSCR.
name|CMPFPw0
block|,
comment|// ARM VFP compare against zero instruction, sets FPSCR.
name|FMSTAT
block|,
comment|// ARM fmstat instruction.
name|CMOV
block|,
comment|// ARM conditional move instructions.
name|CNEG
block|,
comment|// ARM conditional negate instructions.
name|BCC_i64
block|,
name|RBIT
block|,
comment|// ARM bitreverse instruction
name|FTOSI
block|,
comment|// FP to sint within a FP register.
name|FTOUI
block|,
comment|// FP to uint within a FP register.
name|SITOF
block|,
comment|// sint to FP within a FP register.
name|UITOF
block|,
comment|// uint to FP within a FP register.
name|SRL_FLAG
block|,
comment|// V,Flag = srl_flag X -> srl X, 1 + save carry out.
name|SRA_FLAG
block|,
comment|// V,Flag = sra_flag X -> sra X, 1 + save carry out.
name|RRX
block|,
comment|// V = RRX X, Flag     -> srl X, 1 + shift in carry flag.
name|VMOVRRD
block|,
comment|// double to two gprs.
name|VMOVDRR
block|,
comment|// Two gprs to double.
name|EH_SJLJ_SETJMP
block|,
comment|// SjLj exception handling setjmp.
name|EH_SJLJ_LONGJMP
block|,
comment|// SjLj exception handling longjmp.
name|TC_RETURN
block|,
comment|// Tail call return pseudo.
name|THREAD_POINTER
block|,
name|DYN_ALLOC
block|,
comment|// Dynamic allocation on the stack.
name|MEMBARRIER
block|,
comment|// Memory barrier
name|SYNCBARRIER
block|,
comment|// Memory sync barrier
name|VCEQ
block|,
comment|// Vector compare equal.
name|VCGE
block|,
comment|// Vector compare greater than or equal.
name|VCGEU
block|,
comment|// Vector compare unsigned greater than or equal.
name|VCGT
block|,
comment|// Vector compare greater than.
name|VCGTU
block|,
comment|// Vector compare unsigned greater than.
name|VTST
block|,
comment|// Vector test bits.
comment|// Vector shift by immediate:
name|VSHL
block|,
comment|// ...left
name|VSHRs
block|,
comment|// ...right (signed)
name|VSHRu
block|,
comment|// ...right (unsigned)
name|VSHLLs
block|,
comment|// ...left long (signed)
name|VSHLLu
block|,
comment|// ...left long (unsigned)
name|VSHLLi
block|,
comment|// ...left long (with maximum shift count)
name|VSHRN
block|,
comment|// ...right narrow
comment|// Vector rounding shift by immediate:
name|VRSHRs
block|,
comment|// ...right (signed)
name|VRSHRu
block|,
comment|// ...right (unsigned)
name|VRSHRN
block|,
comment|// ...right narrow
comment|// Vector saturating shift by immediate:
name|VQSHLs
block|,
comment|// ...left (signed)
name|VQSHLu
block|,
comment|// ...left (unsigned)
name|VQSHLsu
block|,
comment|// ...left (signed to unsigned)
name|VQSHRNs
block|,
comment|// ...right narrow (signed)
name|VQSHRNu
block|,
comment|// ...right narrow (unsigned)
name|VQSHRNsu
block|,
comment|// ...right narrow (signed to unsigned)
comment|// Vector saturating rounding shift by immediate:
name|VQRSHRNs
block|,
comment|// ...right narrow (signed)
name|VQRSHRNu
block|,
comment|// ...right narrow (unsigned)
name|VQRSHRNsu
block|,
comment|// ...right narrow (signed to unsigned)
comment|// Vector shift and insert:
name|VSLI
block|,
comment|// ...left
name|VSRI
block|,
comment|// ...right
comment|// Vector get lane (VMOV scalar to ARM core register)
comment|// (These are used for 8- and 16-bit element types only.)
name|VGETLANEu
block|,
comment|// zero-extend vector extract element
name|VGETLANEs
block|,
comment|// sign-extend vector extract element
comment|// Vector move immediate and move negated immediate:
name|VMOVIMM
block|,
name|VMVNIMM
block|,
comment|// Vector duplicate:
name|VDUP
block|,
name|VDUPLANE
block|,
comment|// Vector shuffles:
name|VEXT
block|,
comment|// extract
name|VREV64
block|,
comment|// reverse elements within 64-bit doublewords
name|VREV32
block|,
comment|// reverse elements within 32-bit words
name|VREV16
block|,
comment|// reverse elements within 16-bit halfwords
name|VZIP
block|,
comment|// zip (interleave)
name|VUZP
block|,
comment|// unzip (deinterleave)
name|VTRN
block|,
comment|// transpose
comment|// Operands of the standard BUILD_VECTOR node are not legalized, which
comment|// is fine if BUILD_VECTORs are always lowered to shuffles or other
comment|// operations, but for ARM some BUILD_VECTORs are legal as-is and their
comment|// operands need to be legalized.  Define an ARM-specific version of
comment|// BUILD_VECTOR for this purpose.
name|BUILD_VECTOR
block|,
comment|// Floating-point max and min:
name|FMAX
block|,
name|FMIN
block|}
enum|;
block|}
comment|/// Define some predicates that are used for node matching.
name|namespace
name|ARM
block|{
comment|/// getVFPf32Imm / getVFPf64Imm - If the given fp immediate can be
comment|/// materialized with a VMOV.f32 / VMOV.f64 (i.e. fconsts / fconstd)
comment|/// instruction, returns its 8-bit integer representation. Otherwise,
comment|/// returns -1.
name|int
name|getVFPf32Imm
parameter_list|(
specifier|const
name|APFloat
modifier|&
name|FPImm
parameter_list|)
function_decl|;
name|int
name|getVFPf64Imm
parameter_list|(
specifier|const
name|APFloat
modifier|&
name|FPImm
parameter_list|)
function_decl|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|//  ARMTargetLowering - ARM Implementation of the TargetLowering interface
name|class
name|ARMTargetLowering
range|:
name|public
name|TargetLowering
block|{
name|public
operator|:
name|explicit
name|ARMTargetLowering
argument_list|(
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
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
comment|/// ReplaceNodeResults - Replace the results of node with an illegal result
comment|/// type with new values built out of custom code.
comment|///
name|virtual
name|void
name|ReplaceNodeResults
argument_list|(
argument|SDNode *N
argument_list|,
argument|SmallVectorImpl<SDValue>&Results
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
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
name|virtual
name|MachineBasicBlock
operator|*
name|EmitInstrWithCustomInserter
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
comment|/// allowsUnalignedMemoryAccesses - Returns true if the target allows
comment|/// unaligned memory accesses. of the specified type.
comment|/// FIXME: Add getOptimalMemOpType to implement memcpy with NEON?
name|virtual
name|bool
name|allowsUnalignedMemoryAccesses
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
block|;
comment|/// isLegalAddressingMode - Return true if the addressing mode represented
comment|/// by AM is legal for this target, for a load/store of the specified type.
name|virtual
name|bool
name|isLegalAddressingMode
argument_list|(
argument|const AddrMode&AM
argument_list|,
argument|const Type *Ty
argument_list|)
specifier|const
block|;
name|bool
name|isLegalT2ScaledAddressingMode
argument_list|(
argument|const AddrMode&AM
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
block|;
comment|/// isLegalICmpImmediate - Return true if the specified immediate is legal
comment|/// icmp immediate, that is the target has icmp instructions which can
comment|/// compare a register against the immediate without having to materialize
comment|/// the immediate into a register.
name|virtual
name|bool
name|isLegalICmpImmediate
argument_list|(
argument|int64_t Imm
argument_list|)
specifier|const
block|;
comment|/// getPreIndexedAddressParts - returns true by value, base pointer and
comment|/// offset pointer and addressing mode by reference if the node's address
comment|/// can be legally represented as pre-indexed load / store address.
name|virtual
name|bool
name|getPreIndexedAddressParts
argument_list|(
argument|SDNode *N
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|,
argument|ISD::MemIndexedMode&AM
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// getPostIndexedAddressParts - returns true by value, base pointer and
comment|/// offset pointer and addressing mode by reference if this node can be
comment|/// combined with a load / store to form a post-indexed load / store.
name|virtual
name|bool
name|getPostIndexedAddressParts
argument_list|(
argument|SDNode *N
argument_list|,
argument|SDNode *Op
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|,
argument|ISD::MemIndexedMode&AM
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|computeMaskedBitsForTargetNode
argument_list|(
argument|const SDValue Op
argument_list|,
argument|const APInt&Mask
argument_list|,
argument|APInt&KnownZero
argument_list|,
argument|APInt&KnownOne
argument_list|,
argument|const SelectionDAG&DAG
argument_list|,
argument|unsigned Depth
argument_list|)
specifier|const
block|;
name|ConstraintType
name|getConstraintType
argument_list|(
argument|const std::string&Constraint
argument_list|)
specifier|const
block|;
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
argument|const std::string&Constraint
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
block|;
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
block|;
comment|/// LowerAsmOperandForConstraint - Lower the specified operand into the Ops
comment|/// vector.  If it is invalid, don't add anything to Ops. If hasMemory is
comment|/// true it means one of the asm constraint of the inline asm instruction
comment|/// being processed is 'm'.
name|virtual
name|void
name|LowerAsmOperandForConstraint
argument_list|(
argument|SDValue Op
argument_list|,
argument|char ConstraintLetter
argument_list|,
argument|std::vector<SDValue>&Ops
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
specifier|const
name|ARMSubtarget
operator|*
name|getSubtarget
argument_list|()
specifier|const
block|{
return|return
name|Subtarget
return|;
block|}
comment|/// getRegClassFor - Return the register class that should be used for the
comment|/// specified value type.
name|virtual
name|TargetRegisterClass
operator|*
name|getRegClassFor
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
block|;
comment|/// getFunctionAlignment - Return the Log2 alignment of this function.
name|virtual
name|unsigned
name|getFunctionAlignment
argument_list|(
argument|const Function *F
argument_list|)
specifier|const
block|;
name|Sched
operator|::
name|Preference
name|getSchedulingPreference
argument_list|(
argument|SDNode *N
argument_list|)
specifier|const
block|;
name|bool
name|isShuffleMaskLegal
argument_list|(
argument|const SmallVectorImpl<int>&M
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
block|;
name|bool
name|isOffsetFoldingLegal
argument_list|(
argument|const GlobalAddressSDNode *GA
argument_list|)
specifier|const
block|;
comment|/// isFPImmLegal - Returns true if the target can instruction select the
comment|/// specified FP immediate natively. If false, the legalizer will
comment|/// materialize the FP immediate as a load from a constant pool.
name|virtual
name|bool
name|isFPImmLegal
argument_list|(
argument|const APFloat&Imm
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
block|;
name|private
operator|:
comment|/// Subtarget - Keep a pointer to the ARMSubtarget around so that we can
comment|/// make the right decision when generating code for different targets.
specifier|const
name|ARMSubtarget
operator|*
name|Subtarget
block|;
comment|/// ARMPCLabelIndex - Keep track of the number of ARM PC labels created.
comment|///
name|unsigned
name|ARMPCLabelIndex
block|;
name|void
name|addTypeForNEON
argument_list|(
argument|EVT VT
argument_list|,
argument|EVT PromotedLdStVT
argument_list|,
argument|EVT PromotedBitwiseVT
argument_list|)
block|;
name|void
name|addDRTypeForNEON
argument_list|(
argument|EVT VT
argument_list|)
block|;
name|void
name|addQRTypeForNEON
argument_list|(
argument|EVT VT
argument_list|)
block|;
typedef|typedef
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|SDValue
operator|>
operator|,
literal|8
operator|>
name|RegsToPassVector
expr_stmt|;
name|void
name|PassF64ArgInRegs
argument_list|(
argument|DebugLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue&Arg
argument_list|,
argument|RegsToPassVector&RegsToPass
argument_list|,
argument|CCValAssign&VA
argument_list|,
argument|CCValAssign&NextVA
argument_list|,
argument|SDValue&StackPtr
argument_list|,
argument|SmallVector<SDValue
argument_list|,
literal|8
argument|>&MemOpChains
argument_list|,
argument|ISD::ArgFlagsTy Flags
argument_list|)
specifier|const
decl_stmt|;
name|SDValue
name|GetF64FormalArgument
argument_list|(
name|CCValAssign
operator|&
name|VA
argument_list|,
name|CCValAssign
operator|&
name|NextVA
argument_list|,
name|SDValue
operator|&
name|Root
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|DebugLoc
name|dl
argument_list|)
decl|const
decl_stmt|;
name|CCAssignFn
modifier|*
name|CCAssignFnForNode
argument_list|(
name|CallingConv
operator|::
name|ID
name|CC
argument_list|,
name|bool
name|Return
argument_list|,
name|bool
name|isVarArg
argument_list|)
decl|const
decl_stmt|;
name|SDValue
name|LowerMemOpCallTo
argument_list|(
name|SDValue
name|Chain
argument_list|,
name|SDValue
name|StackPtr
argument_list|,
name|SDValue
name|Arg
argument_list|,
name|DebugLoc
name|dl
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
specifier|const
name|CCValAssign
operator|&
name|VA
argument_list|,
name|ISD
operator|::
name|ArgFlagsTy
name|Flags
argument_list|)
decl|const
decl_stmt|;
name|SDValue
name|LowerEH_SJLJ_SETJMP
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
name|SDValue
name|LowerEH_SJLJ_LONGJMP
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
name|SDValue
name|LowerINTRINSIC_WO_CHAIN
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
specifier|const
name|ARMSubtarget
operator|*
name|Subtarget
argument_list|)
decl|const
decl_stmt|;
name|SDValue
name|LowerBlockAddress
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
name|SDValue
name|LowerGlobalAddressDarwin
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
name|SDValue
name|LowerGlobalAddressELF
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
name|SDValue
name|LowerGlobalTLSAddress
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
name|SDValue
name|LowerToTLSGeneralDynamicModel
argument_list|(
name|GlobalAddressSDNode
operator|*
name|GA
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
name|SDValue
name|LowerToTLSExecModels
argument_list|(
name|GlobalAddressSDNode
operator|*
name|GA
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
name|SDValue
name|LowerGLOBAL_OFFSET_TABLE
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
name|SDValue
name|LowerBR_JT
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
name|SDValue
name|LowerSELECT_CC
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
name|SDValue
name|LowerBR_CC
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
name|SDValue
name|LowerFCOPYSIGN
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
name|SDValue
name|LowerRETURNADDR
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
name|SDValue
name|LowerFRAMEADDR
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
name|SDValue
name|LowerDYNAMIC_STACKALLOC
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
name|SDValue
name|LowerShiftRightParts
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
name|SDValue
name|LowerShiftLeftParts
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
name|SDValue
name|LowerCallResult
argument_list|(
name|SDValue
name|Chain
argument_list|,
name|SDValue
name|InFlag
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
decl|const
decl_stmt|;
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
decl|const
decl_stmt|;
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
operator|&
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
name|SDValue
operator|>
operator|&
name|OutVals
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
decl|const
decl_stmt|;
comment|/// IsEligibleForTailCallOptimization - Check whether the call is eligible
comment|/// for tail call optimization. Targets which want to do tail call
comment|/// optimization should implement this function.
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
name|bool
name|isCalleeStructRet
argument_list|,
name|bool
name|isCallerStructRet
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
name|SDValue
operator|>
operator|&
name|OutVals
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
decl_stmt|;
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
specifier|const
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|OutVals
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
name|getARMCmp
argument_list|(
name|SDValue
name|LHS
argument_list|,
name|SDValue
name|RHS
argument_list|,
name|ISD
operator|::
name|CondCode
name|CC
argument_list|,
name|SDValue
operator|&
name|ARMcc
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|DebugLoc
name|dl
argument_list|)
decl|const
decl_stmt|;
name|SDValue
name|getVFPCmp
argument_list|(
name|SDValue
name|LHS
argument_list|,
name|SDValue
name|RHS
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|DebugLoc
name|dl
argument_list|)
decl|const
decl_stmt|;
name|SDValue
name|OptimizeVFPBrcond
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
name|MachineBasicBlock
modifier|*
name|EmitAtomicCmpSwap
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|BB
argument_list|,
name|unsigned
name|Size
argument_list|)
decl|const
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|EmitAtomicBinary
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|BB
argument_list|,
name|unsigned
name|Size
argument_list|,
name|unsigned
name|BinOpcode
argument_list|)
decl|const
decl_stmt|;
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
comment|// ARMISELLOWERING_H
end_comment

end_unit

