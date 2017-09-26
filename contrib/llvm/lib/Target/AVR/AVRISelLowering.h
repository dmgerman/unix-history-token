begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AVRISelLowering.h - AVR DAG Lowering Interface ----------*- C++ -*-===//
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
comment|// This file defines the interfaces that AVR uses to lower LLVM code into a
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
name|LLVM_AVR_ISEL_LOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AVR_ISEL_LOWERING_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/CallingConvLower.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLowering.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|AVRISD
block|{
comment|/// AVR Specific DAG Nodes
enum|enum
name|NodeType
block|{
comment|/// Start the numbering where the builtin ops leave off.
name|FIRST_NUMBER
init|=
name|ISD
operator|::
name|BUILTIN_OP_END
block|,
comment|/// Return from subroutine.
name|RET_FLAG
block|,
comment|/// Return from ISR.
name|RETI_FLAG
block|,
comment|/// Represents an abstract call instruction,
comment|/// which includes a bunch of information.
name|CALL
block|,
comment|/// A wrapper node for TargetConstantPool,
comment|/// TargetExternalSymbol, and TargetGlobalAddress.
name|WRAPPER
block|,
name|LSL
block|,
comment|///< Logical shift left.
name|LSR
block|,
comment|///< Logical shift right.
name|ASR
block|,
comment|///< Arithmetic shift right.
name|ROR
block|,
comment|///< Bit rotate right.
name|ROL
block|,
comment|///< Bit rotate left.
name|LSLLOOP
block|,
comment|///< A loop of single logical shift left instructions.
name|LSRLOOP
block|,
comment|///< A loop of single logical shift right instructions.
name|ROLLOOP
block|,
comment|///< A loop of single left bit rotate instructions.
name|RORLOOP
block|,
comment|///< A loop of single right bit rotate instructions.
name|ASRLOOP
block|,
comment|///< A loop of single arithmetic shift right instructions.
comment|/// AVR conditional branches. Operand 0 is the chain operand, operand 1
comment|/// is the block to branch if condition is true, operand 2 is the
comment|/// condition code, and operand 3 is the flag operand produced by a CMP
comment|/// or TEST instruction.
name|BRCOND
block|,
comment|/// Compare instruction.
name|CMP
block|,
comment|/// Compare with carry instruction.
name|CMPC
block|,
comment|/// Test for zero or minus instruction.
name|TST
block|,
comment|/// Operand 0 and operand 1 are selection variable, operand 2
comment|/// is condition code and operand 3 is flag operand.
name|SELECT_CC
block|}
enum|;
block|}
comment|// end of namespace AVRISD
name|class
name|AVRTargetMachine
decl_stmt|;
comment|/// Performs target lowering for the AVR.
name|class
name|AVRTargetLowering
range|:
name|public
name|TargetLowering
block|{
name|public
operator|:
name|explicit
name|AVRTargetLowering
argument_list|(
name|AVRTargetMachine
operator|&
name|TM
argument_list|)
block|;
name|public
operator|:
name|MVT
name|getScalarShiftAmountTy
argument_list|(
argument|const DataLayout&
argument_list|,
argument|EVT LHSTy
argument_list|)
specifier|const
name|override
block|{
return|return
name|MVT
operator|::
name|i8
return|;
block|}
specifier|const
name|char
operator|*
name|getTargetNodeName
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|LowerOperation
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
name|override
block|;
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
name|override
block|;
name|bool
name|isLegalAddressingMode
argument_list|(
argument|const DataLayout&DL
argument_list|,
argument|const AddrMode&AM
argument_list|,
argument|Type *Ty
argument_list|,
argument|unsigned AS
argument_list|)
specifier|const
name|override
block|;
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
name|override
block|;
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
name|override
block|;
name|bool
name|isOffsetFoldingLegal
argument_list|(
argument|const GlobalAddressSDNode *GA
argument_list|)
specifier|const
name|override
block|;
name|EVT
name|getSetCCResultType
argument_list|(
argument|const DataLayout&DL
argument_list|,
argument|LLVMContext&Context
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
name|MachineBasicBlock
operator|*
name|EmitInstrWithCustomInserter
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
name|override
block|;
name|ConstraintType
name|getConstraintType
argument_list|(
argument|StringRef Constraint
argument_list|)
specifier|const
name|override
block|;
name|ConstraintWeight
name|getSingleConstraintMatchWeight
argument_list|(
argument|AsmOperandInfo&info
argument_list|,
argument|const char *constraint
argument_list|)
specifier|const
name|override
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
argument|const TargetRegisterInfo *TRI
argument_list|,
argument|StringRef Constraint
argument_list|,
argument|MVT VT
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getInlineAsmMemConstraint
argument_list|(
argument|StringRef ConstraintCode
argument_list|)
specifier|const
name|override
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
name|override
block|;
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
name|override
block|;
name|private
operator|:
name|SDValue
name|getAVRCmp
argument_list|(
argument|SDValue LHS
argument_list|,
argument|SDValue RHS
argument_list|,
argument|ISD::CondCode CC
argument_list|,
argument|SDValue&AVRcc
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc dl
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerShifts
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerDivRem
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerGlobalAddress
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
name|LowerBR_CC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerINLINEASM
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
name|LowerVASTART
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|CCAssignFn
operator|*
name|CCAssignFnForReturn
argument_list|(
argument|CallingConv::ID CC
argument_list|)
specifier|const
block|;
name|bool
name|CanLowerReturn
argument_list|(
argument|CallingConv::ID CallConv
argument_list|,
argument|MachineFunction&MF
argument_list|,
argument|bool isVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|LLVMContext&Context
argument_list|)
specifier|const
name|override
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
argument|const SDLoc&dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
name|override
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
argument|const SDLoc&dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|LowerCall
argument_list|(
argument|TargetLowering::CallLoweringInfo&CLI
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
name|override
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
argument|bool isVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|const SDLoc&dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
block|;
name|private
operator|:
name|MachineBasicBlock
operator|*
name|insertShift
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|insertMul
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|; }
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
comment|// LLVM_AVR_ISEL_LOWERING_H
end_comment

end_unit

