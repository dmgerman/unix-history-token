begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SparcISelLowering.h - Sparc DAG Lowering Interface ------*- C++ -*-===//
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
comment|// This file defines the interfaces that Sparc uses to lower LLVM code into a
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
name|SPARC_ISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|SPARC_ISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"Sparc.h"
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
name|class
name|SparcSubtarget
decl_stmt|;
name|namespace
name|SPISD
block|{
enum|enum
block|{
name|FIRST_NUMBER
init|=
name|ISD
operator|::
name|BUILTIN_OP_END
block|,
name|CMPICC
block|,
comment|// Compare two GPR operands, set icc+xcc.
name|CMPFCC
block|,
comment|// Compare two FP operands, set fcc.
name|BRICC
block|,
comment|// Branch to dest on icc condition
name|BRXCC
block|,
comment|// Branch to dest on xcc condition (64-bit only).
name|BRFCC
block|,
comment|// Branch to dest on fcc condition
name|SELECT_ICC
block|,
comment|// Select between two values using the current ICC flags.
name|SELECT_XCC
block|,
comment|// Select between two values using the current XCC flags.
name|SELECT_FCC
block|,
comment|// Select between two values using the current FCC flags.
name|Hi
block|,
name|Lo
block|,
comment|// Hi/Lo operations, typically on a global address.
name|FTOI
block|,
comment|// FP to Int within a FP register.
name|ITOF
block|,
comment|// Int to FP within a FP register.
name|FTOX
block|,
comment|// FP to Int64 within a FP register.
name|XTOF
block|,
comment|// Int64 to FP within a FP register.
name|CALL
block|,
comment|// A call instruction.
name|RET_FLAG
block|,
comment|// Return with a flag operand.
name|GLOBAL_BASE_REG
block|,
comment|// Global base reg for PIC.
name|FLUSHW
block|,
comment|// FLUSH register windows to stack.
name|TLS_ADD
block|,
comment|// For Thread Local Storage (TLS).
name|TLS_LD
block|,
name|TLS_CALL
block|}
enum|;
block|}
name|class
name|SparcTargetLowering
range|:
name|public
name|TargetLowering
block|{
specifier|const
name|SparcSubtarget
operator|*
name|Subtarget
block|;
name|public
operator|:
name|SparcTargetLowering
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
comment|/// computeMaskedBitsForTargetNode - Determine which of the bits specified
comment|/// in Mask are known to be either zero or one and return them in the
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
argument|AsmOperandInfo&info
argument_list|,
argument|const char *constraint
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
name|isOffsetFoldingLegal
argument_list|(
argument|const GlobalAddressSDNode *GA
argument_list|)
specifier|const
block|;
name|virtual
name|MVT
name|getScalarShiftAmountTy
argument_list|(
argument|EVT LHSTy
argument_list|)
specifier|const
block|{
return|return
name|MVT
operator|::
name|i32
return|;
block|}
comment|/// getSetCCResultType - Return the ISD::SETCC ValueType
name|virtual
name|EVT
name|getSetCCResultType
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
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
argument|SDLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFormalArguments_32
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
name|LowerFormalArguments_64
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
name|virtual
name|SDValue
name|LowerCall
argument_list|(
argument|TargetLowering::CallLoweringInfo&CLI
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerCall_32
argument_list|(
argument|TargetLowering::CallLoweringInfo&CLI
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerCall_64
argument_list|(
argument|TargetLowering::CallLoweringInfo&CLI
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
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
argument|const SmallVectorImpl<SDValue>&OutVals
argument_list|,
argument|SDLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerReturn_32
argument_list|(
argument|SDValue Chain
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool IsVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|const SmallVectorImpl<SDValue>&OutVals
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerReturn_64
argument_list|(
argument|SDValue Chain
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool IsVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|const SmallVectorImpl<SDValue>&OutVals
argument_list|,
argument|SDLoc DL
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
name|LowerGlobalTLSAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerConstantPool
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
name|unsigned
name|getSRetArgSize
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDValue Callee
argument_list|)
specifier|const
block|;
name|SDValue
name|withTargetFlags
argument_list|(
argument|SDValue Op
argument_list|,
argument|unsigned TF
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|makeHiLoPair
argument_list|(
argument|SDValue Op
argument_list|,
argument|unsigned HiTF
argument_list|,
argument|unsigned LoTF
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|makeAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerF128_LibCallArg
argument_list|(
argument|SDValue Chain
argument_list|,
argument|ArgListTy&Args
argument_list|,
argument|SDValue Arg
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerF128Op
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|const char *LibFuncName
argument_list|,
argument|unsigned numArgs
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerF128Compare
argument_list|(
argument|SDValue LHS
argument_list|,
argument|SDValue RHS
argument_list|,
argument|unsigned&SPCC
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|bool
name|ShouldShrinkFPConstant
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
block|{
comment|// Do not shrink FP constpool if VT == MVT::f128.
comment|// (ldd, call _Q_fdtoq) is more expensive than two ldds.
return|return
name|VT
operator|!=
name|MVT
operator|::
name|f128
return|;
block|}
name|virtual
name|void
name|ReplaceNodeResults
argument_list|(
argument|SDNode *N
argument_list|,
argument|SmallVectorImpl<SDValue>& Results
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|expandSelectCC
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|unsigned BROpcode
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|expandAtomicRMW
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|unsigned Opcode
argument_list|,
argument|unsigned CondCode =
literal|0
argument_list|)
specifier|const
block|;   }
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
comment|// SPARC_ISELLOWERING_H
end_comment

end_unit

