begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- R600InstrInfo.h - R600 Instruction Info Interface -------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// \brief Interface definition for R600InstrInfo
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
name|R600INSTRUCTIONINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|R600INSTRUCTIONINFO_H_
end_define

begin_include
include|#
directive|include
file|"AMDGPUInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"AMDIL.h"
end_include

begin_include
include|#
directive|include
file|"R600Defines.h"
end_include

begin_include
include|#
directive|include
file|"R600RegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AMDGPUTargetMachine
decl_stmt|;
name|class
name|DFAPacketizer
decl_stmt|;
name|class
name|ScheduleDAG
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineInstrBuilder
decl_stmt|;
name|class
name|R600InstrInfo
range|:
name|public
name|AMDGPUInstrInfo
block|{
name|private
operator|:
specifier|const
name|R600RegisterInfo
name|RI
block|;
specifier|const
name|AMDGPUSubtarget
operator|&
name|ST
block|;
name|int
name|getBranchInstr
argument_list|(
argument|const MachineOperand&op
argument_list|)
specifier|const
block|;
name|public
operator|:
name|explicit
name|R600InstrInfo
argument_list|(
name|AMDGPUTargetMachine
operator|&
name|tm
argument_list|)
block|;
specifier|const
name|R600RegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|copyPhysReg
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|DebugLoc DL
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|bool KillSrc
argument_list|)
specifier|const
block|;
name|bool
name|isTrig
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isPlaceHolderOpcode
argument_list|(
argument|unsigned opcode
argument_list|)
specifier|const
block|;
name|bool
name|isReductionOp
argument_list|(
argument|unsigned opcode
argument_list|)
specifier|const
block|;
name|bool
name|isCubeOp
argument_list|(
argument|unsigned opcode
argument_list|)
specifier|const
block|;
comment|/// \returns true if this \p Opcode represents an ALU instruction.
name|bool
name|isALUInstr
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|isTransOnly
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|isTransOnly
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
name|bool
name|usesVertexCache
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|usesVertexCache
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
name|bool
name|usesTextureCache
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|usesTextureCache
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
name|bool
name|fitsConstReadLimitations
argument_list|(
argument|const std::vector<unsigned>&
argument_list|)
specifier|const
block|;
name|bool
name|canBundle
argument_list|(
argument|const std::vector<MachineInstr *>&
argument_list|)
specifier|const
block|;
comment|/// \breif Vector instructions are instructions that must fill all
comment|/// instruction slots within an instruction group.
name|bool
name|isVector
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|virtual
name|MachineInstr
operator|*
name|getMovImmInstr
argument_list|(
argument|MachineFunction *MF
argument_list|,
argument|unsigned DstReg
argument_list|,
argument|int64_t Imm
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getIEQOpcode
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|isMov
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|DFAPacketizer
operator|*
name|CreateTargetScheduleState
argument_list|(
argument|const TargetMachine *TM
argument_list|,
argument|const ScheduleDAG *DAG
argument_list|)
specifier|const
block|;
name|bool
name|ReverseBranchCondition
argument_list|(
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
block|;
name|bool
name|AnalyzeBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *&TBB
argument_list|,
argument|MachineBasicBlock *&FBB
argument_list|,
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|,
argument|bool AllowModify
argument_list|)
specifier|const
block|;
name|unsigned
name|InsertBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *TBB
argument_list|,
argument|MachineBasicBlock *FBB
argument_list|,
argument|const SmallVectorImpl<MachineOperand>&Cond
argument_list|,
argument|DebugLoc DL
argument_list|)
specifier|const
block|;
name|unsigned
name|RemoveBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
block|;
name|bool
name|isPredicated
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
name|bool
name|isPredicable
argument_list|(
argument|MachineInstr *MI
argument_list|)
specifier|const
block|;
name|bool
name|isProfitableToDupForIfCvt
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|unsigned NumCyles
argument_list|,
argument|const BranchProbability&Probability
argument_list|)
specifier|const
block|;
name|bool
name|isProfitableToIfCvt
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|unsigned NumCyles
argument_list|,
argument|unsigned ExtraPredCycles
argument_list|,
argument|const BranchProbability&Probability
argument_list|)
specifier|const
block|;
name|bool
name|isProfitableToIfCvt
argument_list|(
argument|MachineBasicBlock&TMBB
argument_list|,
argument|unsigned NumTCycles
argument_list|,
argument|unsigned ExtraTCycles
argument_list|,
argument|MachineBasicBlock&FMBB
argument_list|,
argument|unsigned NumFCycles
argument_list|,
argument|unsigned ExtraFCycles
argument_list|,
argument|const BranchProbability&Probability
argument_list|)
specifier|const
block|;
name|bool
name|DefinesPredicate
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|std::vector<MachineOperand>&Pred
argument_list|)
specifier|const
block|;
name|bool
name|SubsumesPredicate
argument_list|(
argument|const SmallVectorImpl<MachineOperand>&Pred1
argument_list|,
argument|const SmallVectorImpl<MachineOperand>&Pred2
argument_list|)
specifier|const
block|;
name|bool
name|isProfitableToUnpredicate
argument_list|(
argument|MachineBasicBlock&TMBB
argument_list|,
argument|MachineBasicBlock&FMBB
argument_list|)
specifier|const
block|;
name|bool
name|PredicateInstruction
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|const SmallVectorImpl<MachineOperand>&Pred
argument_list|)
specifier|const
block|;
name|unsigned
name|int
name|getInstrLatency
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|const MachineInstr *MI
argument_list|,
argument|unsigned *PredCost =
literal|0
argument_list|)
specifier|const
block|;
name|virtual
name|int
name|getInstrLatency
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|SDNode *Node
argument_list|)
specifier|const
block|{
return|return
literal|1
return|;
block|}
comment|/// \returns a list of all the registers that may be accesed using indirect
comment|/// addressing.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|getIndirectReservedRegs
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|virtual
name|int
name|getIndirectIndexBegin
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|virtual
name|int
name|getIndirectIndexEnd
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|calculateIndirectAddress
argument_list|(
argument|unsigned RegIndex
argument_list|,
argument|unsigned Channel
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|TargetRegisterClass
operator|*
name|getIndirectAddrStoreRegClass
argument_list|(
argument|unsigned SourceReg
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|TargetRegisterClass
operator|*
name|getIndirectAddrLoadRegClass
argument_list|()
specifier|const
block|;
name|virtual
name|MachineInstrBuilder
name|buildIndirectWrite
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned ValueReg
argument_list|,
argument|unsigned Address
argument_list|,
argument|unsigned OffsetReg
argument_list|)
specifier|const
block|;
name|virtual
name|MachineInstrBuilder
name|buildIndirectRead
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned ValueReg
argument_list|,
argument|unsigned Address
argument_list|,
argument|unsigned OffsetReg
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|TargetRegisterClass
operator|*
name|getSuperIndirectRegClass
argument_list|()
specifier|const
block|;
name|unsigned
name|getMaxAlusPerClause
argument_list|()
specifier|const
block|;
comment|///buildDefaultInstruction - This function returns a MachineInstr with
comment|/// all the instruction modifiers initialized to their default values.
comment|/// You can use this function to avoid manually specifying each instruction
comment|/// modifier operand when building a new instruction.
comment|///
comment|/// \returns a MachineInstr with all the instruction modifiers initialized
comment|/// to their default values.
name|MachineInstrBuilder
name|buildDefaultInstruction
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned Opcode
argument_list|,
argument|unsigned DstReg
argument_list|,
argument|unsigned Src0Reg
argument_list|,
argument|unsigned Src1Reg =
literal|0
argument_list|)
specifier|const
block|;
name|MachineInstr
operator|*
name|buildMovImm
argument_list|(
argument|MachineBasicBlock&BB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned DstReg
argument_list|,
argument|uint64_t Imm
argument_list|)
specifier|const
block|;
comment|/// \brief Get the index of Op in the MachineInstr.
comment|///
comment|/// \returns -1 if the Instruction does not contain the specified \p Op.
name|int
name|getOperandIdx
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|R600Operands::Ops Op
argument_list|)
specifier|const
block|;
comment|/// \brief Get the index of \p Op for the given Opcode.
comment|///
comment|/// \returns -1 if the Instruction does not contain the specified \p Op.
name|int
name|getOperandIdx
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|R600Operands::Ops Op
argument_list|)
specifier|const
block|;
comment|/// \brief Helper function for setting instruction flag values.
name|void
name|setImmOperand
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|R600Operands::Ops Op
argument_list|,
argument|int64_t Imm
argument_list|)
specifier|const
block|;
comment|/// \returns true if this instruction has an operand for storing target flags.
name|bool
name|hasFlagOperand
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
comment|///\brief Add one of the MO_FLAG* flags to the specified \p Operand.
name|void
name|addFlag
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|unsigned Operand
argument_list|,
argument|unsigned Flag
argument_list|)
specifier|const
block|;
comment|///\brief Determine if the specified \p Flag is set on this \p Operand.
name|bool
name|isFlagSet
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned Operand
argument_list|,
argument|unsigned Flag
argument_list|)
specifier|const
block|;
comment|/// \param SrcIdx The register source to set the flag on (e.g src0, src1, src2)
comment|/// \param Flag The flag being set.
comment|///
comment|/// \returns the operand containing the flags for this instruction.
name|MachineOperand
operator|&
name|getFlagOp
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|unsigned SrcIdx =
literal|0
argument_list|,
argument|unsigned Flag =
literal|0
argument_list|)
specifier|const
block|;
comment|/// \brief Clear the specified flag on the instruction.
name|void
name|clearFlag
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|unsigned Operand
argument_list|,
argument|unsigned Flag
argument_list|)
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// R600INSTRINFO_H_
end_comment

end_unit

