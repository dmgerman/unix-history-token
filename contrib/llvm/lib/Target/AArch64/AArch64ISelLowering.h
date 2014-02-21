begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- AArch64ISelLowering.h - AArch64 DAG Lowering Interface ----*- C++ -*-==//
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
comment|// This file defines the interfaces that AArch64 uses to lower LLVM code into a
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
name|LLVM_TARGET_AARCH64_ISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_AARCH64_ISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"Utils/AArch64BaseInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/CallingConvLower.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLowering.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Intrinsics.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|AArch64ISD
block|{
enum|enum
name|NodeType
block|{
comment|// Start the numbering from where ISD NodeType finishes.
name|FIRST_NUMBER
init|=
name|ISD
operator|::
name|BUILTIN_OP_END
block|,
comment|// This is a conditional branch which also notes the flag needed
comment|// (eq/sgt/...). A64 puts this information on the branches rather than
comment|// compares as LLVM does.
name|BR_CC
block|,
comment|// A node to be selected to an actual call operation: either BL or BLR in
comment|// the absence of tail calls.
name|Call
block|,
comment|// Indicates a floating-point immediate which fits into the format required
comment|// by the FMOV instructions. First (and only) operand is the 8-bit encoded
comment|// value of that immediate.
name|FPMOV
block|,
comment|// Corresponds directly to an EXTR instruction. Operands are an LHS an RHS
comment|// and an LSB.
name|EXTR
block|,
comment|// Wraps a load from the GOT, which should always be performed with a 64-bit
comment|// load instruction. This prevents the DAG combiner folding a truncate to
comment|// form a smaller memory access.
name|GOTLoad
block|,
comment|// Performs a bitfield insert. Arguments are: the value being inserted into;
comment|// the value being inserted; least significant bit changed; width of the
comment|// field.
name|BFI
block|,
comment|// Simply a convenient node inserted during ISelLowering to represent
comment|// procedure return. Will almost certainly be selected to "RET".
name|Ret
block|,
comment|/// Extracts a field of contiguous bits from the source and sign extends
comment|/// them into a single register. Arguments are: source; immr; imms. Note
comment|/// these are pre-encoded since DAG matching can't cope with combining LSB
comment|/// and Width into these values itself.
name|SBFX
block|,
comment|/// This is an A64-ification of the standard LLVM SELECT_CC operation. The
comment|/// main difference is that it only has the values and an A64 condition,
comment|/// which will be produced by a setcc instruction.
name|SELECT_CC
block|,
comment|/// This serves most of the functions of the LLVM SETCC instruction, for two
comment|/// purposes. First, it prevents optimisations from fiddling with the
comment|/// compare after we've moved the CondCode information onto the SELECT_CC or
comment|/// BR_CC instructions. Second, it gives a legal instruction for the actual
comment|/// comparison.
comment|///
comment|/// It keeps a record of the condition flags asked for because certain
comment|/// instructions are only valid for a subset of condition codes.
name|SETCC
block|,
comment|// Designates a node which is a tail call: both a call and a return
comment|// instruction as far as selction is concerned. It should be selected to an
comment|// unconditional branch. Has the usual plethora of call operands, but: 1st
comment|// is callee, 2nd is stack adjustment required immediately before branch.
name|TC_RETURN
block|,
comment|// Designates a call used to support the TLS descriptor ABI. The call itself
comment|// will be indirect ("BLR xN") but a relocation-specifier (".tlsdesccall
comment|// var") must be attached somehow during code generation. It takes two
comment|// operands: the callee and the symbol to be relocated against.
name|TLSDESCCALL
block|,
comment|// Leaf node which will be lowered to an appropriate MRS to obtain the
comment|// thread pointer: TPIDR_EL0.
name|THREAD_POINTER
block|,
comment|/// Extracts a field of contiguous bits from the source and zero extends
comment|/// them into a single register. Arguments are: source; immr; imms. Note
comment|/// these are pre-encoded since DAG matching can't cope with combining LSB
comment|/// and Width into these values itself.
name|UBFX
block|,
comment|// Wraps an address which the ISelLowering phase has decided should be
comment|// created using the large memory model style: i.e. a sequence of four
comment|// movz/movk instructions.
name|WrapperLarge
block|,
comment|// Wraps an address which the ISelLowering phase has decided should be
comment|// created using the small memory model style: i.e. adrp/add or
comment|// adrp/mem-op. This exists to prevent bare TargetAddresses which may never
comment|// get selected.
name|WrapperSmall
block|,
comment|// Vector bitwise select
name|NEON_BSL
block|,
comment|// Vector move immediate
name|NEON_MOVIMM
block|,
comment|// Vector Move Inverted Immediate
name|NEON_MVNIMM
block|,
comment|// Vector FP move immediate
name|NEON_FMOVIMM
block|,
comment|// Vector permute
name|NEON_UZP1
block|,
name|NEON_UZP2
block|,
name|NEON_ZIP1
block|,
name|NEON_ZIP2
block|,
name|NEON_TRN1
block|,
name|NEON_TRN2
block|,
comment|// Vector Element reverse
name|NEON_REV64
block|,
name|NEON_REV32
block|,
name|NEON_REV16
block|,
comment|// Vector compare
name|NEON_CMP
block|,
comment|// Vector compare zero
name|NEON_CMPZ
block|,
comment|// Vector compare bitwise test
name|NEON_TST
block|,
comment|// Vector saturating shift
name|NEON_QSHLs
block|,
name|NEON_QSHLu
block|,
comment|// Vector dup
name|NEON_VDUP
block|,
comment|// Vector dup by lane
name|NEON_VDUPLANE
block|,
comment|// Vector extract
name|NEON_VEXTRACT
block|,
comment|// NEON duplicate lane loads
name|NEON_LD2DUP
init|=
name|ISD
operator|::
name|FIRST_TARGET_MEMORY_OPCODE
block|,
name|NEON_LD3DUP
block|,
name|NEON_LD4DUP
block|,
comment|// NEON loads with post-increment base updates:
name|NEON_LD1_UPD
block|,
name|NEON_LD2_UPD
block|,
name|NEON_LD3_UPD
block|,
name|NEON_LD4_UPD
block|,
name|NEON_LD1x2_UPD
block|,
name|NEON_LD1x3_UPD
block|,
name|NEON_LD1x4_UPD
block|,
comment|// NEON stores with post-increment base updates:
name|NEON_ST1_UPD
block|,
name|NEON_ST2_UPD
block|,
name|NEON_ST3_UPD
block|,
name|NEON_ST4_UPD
block|,
name|NEON_ST1x2_UPD
block|,
name|NEON_ST1x3_UPD
block|,
name|NEON_ST1x4_UPD
block|,
comment|// NEON duplicate lane loads with post-increment base updates:
name|NEON_LD2DUP_UPD
block|,
name|NEON_LD3DUP_UPD
block|,
name|NEON_LD4DUP_UPD
block|,
comment|// NEON lane loads with post-increment base updates:
name|NEON_LD2LN_UPD
block|,
name|NEON_LD3LN_UPD
block|,
name|NEON_LD4LN_UPD
block|,
comment|// NEON lane store with post-increment base updates:
name|NEON_ST2LN_UPD
block|,
name|NEON_ST3LN_UPD
block|,
name|NEON_ST4LN_UPD
block|}
enum|;
block|}
name|class
name|AArch64Subtarget
decl_stmt|;
name|class
name|AArch64TargetMachine
decl_stmt|;
name|class
name|AArch64TargetLowering
range|:
name|public
name|TargetLowering
block|{
name|public
operator|:
name|explicit
name|AArch64TargetLowering
argument_list|(
name|AArch64TargetMachine
operator|&
name|TM
argument_list|)
block|;
specifier|const
name|char
operator|*
name|getTargetNodeName
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|CCAssignFn
operator|*
name|CCAssignFnForNode
argument_list|(
argument|CallingConv::ID CC
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFormalArguments
argument_list|(
argument|SDValue Chain
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool isVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|SDLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerReturn
argument_list|(
argument|SDValue Chain
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool isVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|const SmallVectorImpl<SDValue>&OutVals
argument_list|,
argument|SDLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerCall
argument_list|(
argument|CallLoweringInfo&CLI
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerCallResult
argument_list|(
argument|SDValue Chain
argument_list|,
argument|SDValue InFlag
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool IsVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|SDLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
block|;
name|bool
name|isKnownShuffleVector
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SDValue&Res
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerBUILD_VECTOR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|const AArch64Subtarget *ST
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerVECTOR_SHUFFLE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|void
name|SaveVarArgRegisters
argument_list|(
argument|CCState&CCInfo
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SDValue&Chain
argument_list|)
specifier|const
block|;
comment|/// IsEligibleForTailCallOptimization - Check whether the call is eligible
comment|/// for tail call optimization. Targets which want to do tail call
comment|/// optimization should implement this function.
name|bool
name|IsEligibleForTailCallOptimization
argument_list|(
argument|SDValue Callee
argument_list|,
argument|CallingConv::ID CalleeCC
argument_list|,
argument|bool IsVarArg
argument_list|,
argument|bool IsCalleeStructRet
argument_list|,
argument|bool IsCallerStructRet
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|const SmallVectorImpl<SDValue>&OutVals
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|SelectionDAG& DAG
argument_list|)
specifier|const
block|;
comment|/// Finds the incoming stack arguments which overlap the given fixed stack
comment|/// object and incorporates their load into the current chain. This prevents
comment|/// an upcoming store from clobbering the stack argument before it's used.
name|SDValue
name|addTokenForArgument
argument_list|(
argument|SDValue Chain
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|MachineFrameInfo *MFI
argument_list|,
argument|int ClobberedFI
argument_list|)
specifier|const
block|;
name|EVT
name|getSetCCResultType
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
block|;
name|bool
name|DoesCalleeRestoreStack
argument_list|(
argument|CallingConv::ID CallCC
argument_list|,
argument|bool TailCallOpt
argument_list|)
specifier|const
block|;
name|bool
name|IsTailCallConvention
argument_list|(
argument|CallingConv::ID CallCC
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerOperation
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|bool
name|isLegalICmpImmediate
argument_list|(
argument|int64_t Val
argument_list|)
specifier|const
block|;
name|SDValue
name|getSelectableIntSetCC
argument_list|(
argument|SDValue LHS
argument_list|,
argument|SDValue RHS
argument_list|,
argument|ISD::CondCode CC
argument_list|,
argument|SDValue&A64cc
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc&dl
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
name|MachineBasicBlock
operator|*
name|emitAtomicBinary
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|,
argument|unsigned Size
argument_list|,
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitAtomicBinaryMinMax
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|unsigned Size
argument_list|,
argument|unsigned CmpOp
argument_list|,
argument|A64CC::CondCodes Cond
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitAtomicCmpSwap
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|unsigned Size
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|EmitF128CSEL
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerATOMIC_FENCE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerATOMIC_STORE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerBlockAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerBRCOND
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerBR_CC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerF128ToCall
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|RTLIB::Libcall Call
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFP_EXTEND
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFP_ROUND
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFP_TO_INT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|bool IsSigned
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerRETURNADDR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFRAMEADDR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerGlobalAddressELFSmall
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerGlobalAddressELFLarge
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerGlobalAddressELF
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerTLSDescCall
argument_list|(
argument|SDValue SymAddr
argument_list|,
argument|SDValue DescAddr
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerGlobalTLSAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerINT_TO_FP
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|bool IsSigned
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerJumpTable
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSELECT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSELECT_CC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSETCC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerVACOPY
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerVASTART
argument_list|(
argument|SDValue Op
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
comment|/// isFMAFasterThanFMulAndFAdd - Return true if an FMA operation is faster
comment|/// than a pair of fmul and fadd instructions. fmuladd intrinsics will be
comment|/// expanded to FMAs when this method returns true, otherwise fmuladd is
comment|/// expanded to fmul + fadd.
name|virtual
name|bool
name|isFMAFasterThanFMulAndFAdd
argument_list|(
argument|EVT VT
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
name|ConstraintWeight
name|getSingleConstraintMatchWeight
argument_list|(
argument|AsmOperandInfo&Info
argument_list|,
argument|const char *Constraint
argument_list|)
specifier|const
block|;
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
argument|MVT VT
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|getTgtMemIntrinsic
argument_list|(
argument|IntrinsicInfo&Info
argument_list|,
argument|const CallInst&I
argument_list|,
argument|unsigned Intrinsic
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|protected
operator|:
name|std
operator|::
name|pair
operator|<
specifier|const
name|TargetRegisterClass
operator|*
block|,
name|uint8_t
operator|>
name|findRepresentativeClass
argument_list|(
argument|MVT VT
argument_list|)
specifier|const
block|;
name|private
operator|:
specifier|const
name|InstrItineraryData
operator|*
name|Itins
block|;
specifier|const
name|AArch64Subtarget
operator|*
name|getSubtarget
argument_list|()
specifier|const
block|{
return|return
operator|&
name|getTargetMachine
argument_list|()
operator|.
name|getSubtarget
operator|<
name|AArch64Subtarget
operator|>
operator|(
operator|)
return|;
block|}
expr|}
block|; enum
name|NeonModImmType
block|{
name|Neon_Mov_Imm
block|,
name|Neon_Mvn_Imm
block|}
block|;
specifier|extern
name|SDValue
name|ScanBUILD_VECTOR
argument_list|(
argument|SDValue Op
argument_list|,
argument|bool&isOnlyLowElement
argument_list|,
argument|bool&usesOnlyOneValue
argument_list|,
argument|bool&hasDominantValue
argument_list|,
argument|bool&isConstant
argument_list|,
argument|bool&isUNDEF
argument_list|)
block|; }
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TARGET_AARCH64_ISELLOWERING_H
end_comment

end_unit

