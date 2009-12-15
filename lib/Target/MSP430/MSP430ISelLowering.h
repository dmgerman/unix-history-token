begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- MSP430ISelLowering.h - MSP430 DAG Lowering Interface ------*- C++ -*-==//
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
comment|// This file defines the interfaces that MSP430 uses to lower LLVM code into a
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
name|LLVM_TARGET_MSP430_ISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_MSP430_ISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"MSP430.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|MSP430ISD
block|{
enum|enum
block|{
name|FIRST_NUMBER
init|=
name|ISD
operator|::
name|BUILTIN_OP_END
block|,
comment|/// Return with a flag operand. Operand 0 is the chain operand.
name|RET_FLAG
block|,
comment|/// Same as RET_FLAG, but used for returning from ISRs.
name|RETI_FLAG
block|,
comment|/// Y = R{R,L}A X, rotate right (left) arithmetically
name|RRA
block|,
name|RLA
block|,
comment|/// Y = RRC X, rotate right via carry
name|RRC
block|,
comment|/// CALL - These operations represent an abstract call
comment|/// instruction, which includes a bunch of information.
name|CALL
block|,
comment|/// Wrapper - A wrapper node for TargetConstantPool, TargetExternalSymbol,
comment|/// and TargetGlobalAddress.
name|Wrapper
block|,
comment|/// CMP - Compare instruction.
name|CMP
block|,
comment|/// SetCC - Operand 0 is condition code, and operand 1 is the flag
comment|/// operand produced by a CMP instruction.
name|SETCC
block|,
comment|/// MSP430 conditional branches. Operand 0 is the chain operand, operand 1
comment|/// is the block to branch if condition is true, operand 2 is the
comment|/// condition code, and operand 3 is the flag operand produced by a CMP
comment|/// instruction.
name|BR_CC
block|,
comment|/// SELECT_CC - Operand 0 and operand 1 are selection variable, operand 3
comment|/// is condition code and operand 4 is flag operand.
name|SELECT_CC
block|,
comment|/// SHL, SRA, SRL - Non-constant shifts.
name|SHL
block|,
name|SRA
block|,
name|SRL
block|}
enum|;
block|}
name|class
name|MSP430Subtarget
decl_stmt|;
name|class
name|MSP430TargetMachine
decl_stmt|;
name|class
name|MSP430TargetLowering
range|:
name|public
name|TargetLowering
block|{
name|public
operator|:
name|explicit
name|MSP430TargetLowering
argument_list|(
name|MSP430TargetMachine
operator|&
name|TM
argument_list|)
block|;
comment|/// LowerOperation - Provide custom lowering hooks for some operations.
name|virtual
name|SDValue
name|LowerOperation
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
comment|/// getTargetNodeName - This method returns the name of a target specific
comment|/// DAG node.
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
comment|/// getFunctionAlignment - Return the Log2 alignment of this function.
name|virtual
name|unsigned
name|getFunctionAlignment
argument_list|(
argument|const Function *F
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
block|;
name|SDValue
name|LowerGlobalAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerExternalSymbol
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerBR_CC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerSETCC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerSELECT_CC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerSIGN_EXTEND
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerRETURNADDR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerFRAMEADDR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|getReturnAddressFrameIndex
argument_list|(
name|SelectionDAG
operator|&
name|DAG
argument_list|)
block|;
name|TargetLowering
operator|::
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
name|MachineBasicBlock
operator|*
name|EmitInstrWithCustomInserter
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|DenseMap<MachineBasicBlock*
argument_list|,
argument|MachineBasicBlock*> *EM
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|EmitShiftInstr
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|DenseMap<MachineBasicBlock*
argument_list|,
argument|MachineBasicBlock*> *EM
argument_list|)
specifier|const
block|;
name|private
operator|:
name|SDValue
name|LowerCCCCallTo
argument_list|(
argument|SDValue Chain
argument_list|,
argument|SDValue Callee
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool isVarArg
argument_list|,
argument|bool isTailCall
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
block|;
name|SDValue
name|LowerCCCArguments
argument_list|(
argument|SDValue Chain
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool isVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
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
argument|DebugLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
block|;
name|virtual
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
argument|DebugLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
block|;
name|virtual
name|SDValue
name|LowerCall
argument_list|(
argument|SDValue Chain
argument_list|,
argument|SDValue Callee
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool isVarArg
argument_list|,
argument|bool isTailCall
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
block|;
name|virtual
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
argument|DebugLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
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
specifier|const
name|MSP430Subtarget
operator|&
name|Subtarget
block|;
specifier|const
name|MSP430TargetMachine
operator|&
name|TM
block|;
specifier|const
name|TargetData
operator|*
name|TD
block|;   }
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
comment|// LLVM_TARGET_MSP430_ISELLOWERING_H
end_comment

end_unit

