begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- XCoreISelLowering.h - XCore DAG Lowering Interface ------*- C++ -*-===//
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
comment|// This file defines the interfaces that XCore uses to lower LLVM code into a
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
name|LLVM_LIB_TARGET_XCORE_XCOREISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_XCORE_XCOREISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"XCore.h"
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
comment|// Forward delcarations
name|class
name|XCoreSubtarget
decl_stmt|;
name|class
name|XCoreTargetMachine
decl_stmt|;
name|namespace
name|XCoreISD
block|{
enum|enum
name|NodeType
enum|:
name|unsigned
block|{
comment|// Start the numbering where the builtin ops and target ops leave off.
name|FIRST_NUMBER
init|=
name|ISD
operator|::
name|BUILTIN_OP_END
block|,
comment|// Branch and link (call)
name|BL
block|,
comment|// pc relative address
name|PCRelativeWrapper
block|,
comment|// dp relative address
name|DPRelativeWrapper
block|,
comment|// cp relative address
name|CPRelativeWrapper
block|,
comment|// Load word from stack
name|LDWSP
block|,
comment|// Store word to stack
name|STWSP
block|,
comment|// Corresponds to retsp instruction
name|RETSP
block|,
comment|// Corresponds to LADD instruction
name|LADD
block|,
comment|// Corresponds to LSUB instruction
name|LSUB
block|,
comment|// Corresponds to LMUL instruction
name|LMUL
block|,
comment|// Corresponds to MACCU instruction
name|MACCU
block|,
comment|// Corresponds to MACCS instruction
name|MACCS
block|,
comment|// Corresponds to CRC8 instruction
name|CRC8
block|,
comment|// Jumptable branch.
name|BR_JT
block|,
comment|// Jumptable branch using long branches for each entry.
name|BR_JT32
block|,
comment|// Offset from frame pointer to the first (possible) on-stack argument
name|FRAME_TO_ARGS_OFFSET
block|,
comment|// Exception handler return. The stack is restored to the first
comment|// followed by a jump to the second argument.
name|EH_RETURN
block|,
comment|// Memory barrier.
name|MEMBARRIER
block|}
enum|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// TargetLowering Implementation
comment|//===--------------------------------------------------------------------===//
name|class
name|XCoreTargetLowering
range|:
name|public
name|TargetLowering
block|{
name|public
operator|:
name|explicit
name|XCoreTargetLowering
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|XCoreSubtarget
operator|&
name|Subtarget
argument_list|)
block|;
name|using
name|TargetLowering
operator|::
name|isZExtFree
block|;
name|bool
name|isZExtFree
argument_list|(
argument|SDValue Val
argument_list|,
argument|EVT VT2
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getJumpTableEncoding
argument_list|()
specifier|const
name|override
block|;
name|MVT
name|getScalarShiftAmountTy
argument_list|(
argument|const DataLayout&DL
argument_list|,
argument|EVT
argument_list|)
specifier|const
name|override
block|{
return|return
name|MVT
operator|::
name|i32
return|;
block|}
comment|/// LowerOperation - Provide custom lowering hooks for some operations.
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
comment|/// ReplaceNodeResults - Replace the results of node with an illegal result
comment|/// type with new values built out of custom code.
comment|///
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
comment|/// getTargetNodeName - This method returns the name of a target specific
comment|//  DAG node.
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
comment|/// If a physical register, this returns the register that receives the
comment|/// exception address on entry to an EH pad.
name|unsigned
name|getExceptionPointerRegister
argument_list|(
argument|const Constant *PersonalityFn
argument_list|)
specifier|const
name|override
block|{
return|return
name|XCore
operator|::
name|R0
return|;
block|}
comment|/// If a physical register, this returns the register that receives the
comment|/// exception typeid on entry to a landing pad.
name|unsigned
name|getExceptionSelectorRegister
argument_list|(
argument|const Constant *PersonalityFn
argument_list|)
specifier|const
name|override
block|{
return|return
name|XCore
operator|::
name|R1
return|;
block|}
name|private
operator|:
specifier|const
name|TargetMachine
operator|&
name|TM
block|;
specifier|const
name|XCoreSubtarget
operator|&
name|Subtarget
block|;
comment|// Lower Operand helpers
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
argument|const SDLoc&dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
block|;
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
argument|const SmallVectorImpl<SDValue>&OutVals
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
name|SDValue
name|getReturnAddressFrameIndex
argument_list|(
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|getGlobalAddressWrapper
argument_list|(
argument|SDValue GA
argument_list|,
argument|const GlobalValue *GV
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerLoadWordFromAlignedBasePlusOffset
argument_list|(
argument|const SDLoc&DL
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Base
argument_list|,
argument|int64_t Offset
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|// Lower Operand specifics
name|SDValue
name|LowerLOAD
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSTORE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerEH_RETURN
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
name|LowerGlobalTLSAddress
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
name|LowerConstantPool
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerBR_JT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerVAARG
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
name|SDValue
name|LowerUMUL_LOHI
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSMUL_LOHI
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
name|LowerFRAME_TO_ARGS_OFFSET
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
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
name|LowerINIT_TRAMPOLINE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerADJUST_TRAMPOLINE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerINTRINSIC_WO_CHAIN
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
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
name|LowerATOMIC_LOAD
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
comment|// Inline asm support
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
comment|// Expand specifics
name|SDValue
name|TryExpandADDWithMul
argument_list|(
argument|SDNode *Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|ExpandADDSUB
argument_list|(
argument|SDNode *Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|PerformDAGCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
name|override
block|;
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
name|bool
name|CanLowerReturn
argument_list|(
argument|CallingConv::ID CallConv
argument_list|,
argument|MachineFunction&MF
argument_list|,
argument|bool isVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&ArgsFlags
argument_list|,
argument|LLVMContext&Context
argument_list|)
specifier|const
name|override
block|;
name|bool
name|shouldInsertFencesForAtomic
argument_list|(
argument|const Instruction *I
argument_list|)
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

