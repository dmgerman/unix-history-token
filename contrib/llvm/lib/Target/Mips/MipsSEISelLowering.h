begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsSEISelLowering.h - MipsSE DAG Lowering Interface ----*- C++ -*-===//
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
comment|// Subclass of MipsTargetLowering specialized for mips32/64.
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
name|LLVM_LIB_TARGET_MIPS_MIPSSEISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MIPS_MIPSSEISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"MipsISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"MipsRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MipsSETargetLowering
range|:
name|public
name|MipsTargetLowering
block|{
name|public
operator|:
name|explicit
name|MipsSETargetLowering
argument_list|(
specifier|const
name|MipsTargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|MipsSubtarget
operator|&
name|STI
argument_list|)
block|;
comment|/// \brief Enable MSA support for the given integer type and Register
comment|/// class.
name|void
name|addMSAIntType
argument_list|(
argument|MVT::SimpleValueType Ty
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|)
block|;
comment|/// \brief Enable MSA support for the given floating-point type and
comment|/// Register class.
name|void
name|addMSAFloatType
argument_list|(
argument|MVT::SimpleValueType Ty
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|)
block|;
name|bool
name|allowsMisalignedMemoryAccesses
argument_list|(
argument|EVT VT
argument_list|,
argument|unsigned AS =
literal|0
argument_list|,
argument|unsigned Align =
literal|1
argument_list|,
argument|bool *Fast = nullptr
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
name|MachineBasicBlock
operator|*
name|EmitInstrWithCustomInserter
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isShuffleMaskLegal
argument_list|(
argument|const SmallVectorImpl<int>&Mask
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
specifier|const
name|TargetRegisterClass
operator|*
name|getRepRegClassFor
argument_list|(
argument|MVT VT
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|bool
name|isEligibleForTailCallOptimization
argument_list|(
argument|const CCState&CCInfo
argument_list|,
argument|unsigned NextStackOffset
argument_list|,
argument|const MipsFunctionInfo&FI
argument_list|)
specifier|const
name|override
block|;
name|void
name|getOpndList
argument_list|(
argument|SmallVectorImpl<SDValue>&Ops
argument_list|,
argument|std::deque< std::pair<unsigned
argument_list|,
argument|SDValue>>&RegsToPass
argument_list|,
argument|bool IsPICCall
argument_list|,
argument|bool GlobalOrExternal
argument_list|,
argument|bool InternalLinkage
argument_list|,
argument|bool IsCallReloc
argument_list|,
argument|CallLoweringInfo&CLI
argument_list|,
argument|SDValue Callee
argument_list|,
argument|SDValue Chain
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|lowerLOAD
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerSTORE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerMulDiv
argument_list|(
argument|SDValue Op
argument_list|,
argument|unsigned NewOpc
argument_list|,
argument|bool HasLo
argument_list|,
argument|bool HasHi
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerINTRINSIC_WO_CHAIN
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerINTRINSIC_W_CHAIN
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerINTRINSIC_VOID
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerEXTRACT_VECTOR_ELT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerBUILD_VECTOR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// \brief Lower VECTOR_SHUFFLE into one of a number of instructions
comment|/// depending on the indices in the shuffle.
name|SDValue
name|lowerVECTOR_SHUFFLE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitBPOSGE32
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitMSACBranchPseudo
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|unsigned BranchOp
argument_list|)
specifier|const
block|;
comment|/// \brief Emit the COPY_FW pseudo instruction
name|MachineBasicBlock
operator|*
name|emitCOPY_FW
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
comment|/// \brief Emit the COPY_FD pseudo instruction
name|MachineBasicBlock
operator|*
name|emitCOPY_FD
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
comment|/// \brief Emit the INSERT_FW pseudo instruction
name|MachineBasicBlock
operator|*
name|emitINSERT_FW
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
comment|/// \brief Emit the INSERT_FD pseudo instruction
name|MachineBasicBlock
operator|*
name|emitINSERT_FD
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
comment|/// \brief Emit the INSERT_([BHWD]|F[WD])_VIDX pseudo instruction
name|MachineBasicBlock
operator|*
name|emitINSERT_DF_VIDX
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|unsigned EltSizeInBytes
argument_list|,
argument|bool IsFP
argument_list|)
specifier|const
block|;
comment|/// \brief Emit the FILL_FW pseudo instruction
name|MachineBasicBlock
operator|*
name|emitFILL_FW
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
comment|/// \brief Emit the FILL_FD pseudo instruction
name|MachineBasicBlock
operator|*
name|emitFILL_FD
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
comment|/// \brief Emit the FEXP2_W_1 pseudo instructions.
name|MachineBasicBlock
operator|*
name|emitFEXP2_W_1
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
comment|/// \brief Emit the FEXP2_D_1 pseudo instructions.
name|MachineBasicBlock
operator|*
name|emitFEXP2_D_1
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

