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
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|int
block|,
name|unsigned
operator|>
expr|>
name|ExtractSrcs
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|const DenseMap<unsigned
argument_list|,
argument|unsigned>&PV
argument_list|,
argument|unsigned&ConstCount
argument_list|)
specifier|const
block|;
name|public
operator|:
expr|enum
name|BankSwizzle
block|{
name|ALU_VEC_012_SCL_210
operator|=
literal|0
block|,
name|ALU_VEC_021_SCL_122
block|,
name|ALU_VEC_120_SCL_212
block|,
name|ALU_VEC_102_SCL_221
block|,
name|ALU_VEC_201
block|,
name|ALU_VEC_210
block|}
block|;
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
name|isLegalToSplitMBBAt
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
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
name|hasInstrModifiers
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|isLDSInstr
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|isLDSNoRetInstr
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|isLDSRetInstr
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
comment|/// \returns true if this \p Opcode represents an ALU instruction or an
comment|/// instruction that will be lowered in ExpandSpecialInstrs Pass.
name|bool
name|canBeConsideredALU
argument_list|(
argument|const MachineInstr *MI
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
name|isVectorOnly
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|isVectorOnly
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
name|bool
name|isExport
argument_list|(
argument|unsigned Opcode
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
name|mustBeLastInClause
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|usesAddressRegister
argument_list|(
argument|MachineInstr *MI
argument_list|)
specifier|const
block|;
name|bool
name|definesAddressRegister
argument_list|(
argument|MachineInstr *MI
argument_list|)
specifier|const
block|;
name|bool
name|readsLDSSrcReg
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
comment|/// \returns The operand index for the given source number.  Legal values
comment|/// for SrcNum are 0, 1, and 2.
name|int
name|getSrcIdx
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|unsigned SrcNum
argument_list|)
specifier|const
block|;
comment|/// \returns The operand Index for the Sel operand given an index to one
comment|/// of the instruction's src operands.
name|int
name|getSelIdx
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|unsigned SrcIdx
argument_list|)
specifier|const
block|;
comment|/// \returns a pair for each src of an ALU instructions.
comment|/// The first member of a pair is the register id.
comment|/// If register is ALU_CONST, second member is SEL.
comment|/// If register is ALU_LITERAL, second member is IMM.
comment|/// Otherwise, second member value is undefined.
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|MachineOperand
operator|*
block|,
name|int64_t
operator|>
block|,
literal|3
operator|>
name|getSrcs
argument_list|(
argument|MachineInstr *MI
argument_list|)
specifier|const
block|;
name|unsigned
name|isLegalUpTo
argument_list|(
argument|const std::vector<std::vector<std::pair<int
argument_list|,
argument|unsigned>>>&IGSrcs
argument_list|,
argument|const std::vector<R600InstrInfo::BankSwizzle>&Swz
argument_list|,
argument|const std::vector<std::pair<int
argument_list|,
argument|unsigned>>&TransSrcs
argument_list|,
argument|R600InstrInfo::BankSwizzle TransSwz
argument_list|)
specifier|const
block|;
name|bool
name|FindSwizzleForVectorSlot
argument_list|(
argument|const std::vector<std::vector<std::pair<int
argument_list|,
argument|unsigned>>>&IGSrcs
argument_list|,
argument|std::vector<R600InstrInfo::BankSwizzle>&SwzCandidate
argument_list|,
argument|const std::vector<std::pair<int
argument_list|,
argument|unsigned>>&TransSrcs
argument_list|,
argument|R600InstrInfo::BankSwizzle TransSwz
argument_list|)
specifier|const
block|;
comment|/// Given the order VEC_012< VEC_021< VEC_120< VEC_102< VEC_201< VEC_210
comment|/// returns true and the first (in lexical order) BankSwizzle affectation
comment|/// starting from the one already provided in the Instruction Group MIs that
comment|/// fits Read Port limitations in BS if available. Otherwise returns false
comment|/// and undefined content in BS.
comment|/// isLastAluTrans should be set if the last Alu of MIs will be executed on
comment|/// Trans ALU. In this case, ValidTSwizzle returns the BankSwizzle value to
comment|/// apply to the last instruction.
comment|/// PV holds GPR to PV registers in the Instruction Group MIs.
name|bool
name|fitsReadPortLimitations
argument_list|(
argument|const std::vector<MachineInstr *>&MIs
argument_list|,
argument|const DenseMap<unsigned
argument_list|,
argument|unsigned>&PV
argument_list|,
argument|std::vector<BankSwizzle>&BS
argument_list|,
argument|bool isLastAluTrans
argument_list|)
specifier|const
block|;
comment|/// An instruction group can only access 2 channel pair (either [XY] or [ZW])
comment|/// from KCache bank on R700+. This function check if MI set in input meet
comment|/// this limitations
name|bool
name|fitsConstReadLimitations
argument_list|(
argument|const std::vector<MachineInstr *>&
argument_list|)
specifier|const
block|;
comment|/// Same but using const index set instead of MI set.
name|bool
name|fitsConstReadLimitations
argument_list|(
argument|const std::vector<unsigned>&
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
name|getPredicationCost
argument_list|(
argument|const MachineInstr *
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
comment|/// \brief Reserve the registers that may be accesed using indirect addressing.
name|void
name|reserveIndirectRegisters
argument_list|(
argument|BitVector&Reserved
argument_list|,
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
name|getIndirectAddrRegClass
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
name|buildSlotOfVectorInstruction
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineInstr *MI
argument_list|,
argument|unsigned Slot
argument_list|,
argument|unsigned DstReg
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
name|MachineInstr
operator|*
name|buildMovInstr
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned DstReg
argument_list|,
argument|unsigned SrcReg
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
argument|unsigned Op
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
argument|unsigned Op
argument_list|)
specifier|const
block|;
comment|/// \brief Helper function for setting instruction flag values.
name|void
name|setImmOperand
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|unsigned Op
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
name|namespace
name|AMDGPU
block|{
name|int
name|getLDSNoRetOp
parameter_list|(
name|uint16_t
name|Opcode
parameter_list|)
function_decl|;
block|}
comment|//End namespace AMDGPU
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

