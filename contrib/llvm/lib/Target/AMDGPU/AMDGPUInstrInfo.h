begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPUInstrInfo.h - AMDGPU Instruction Information ------*- C++ -*-===//
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
comment|/// \brief Contains the definition of a TargetInstrInfo class that is common
end_comment

begin_comment
comment|/// to all AMD GPUs.
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
name|LLVM_LIB_TARGET_R600_AMDGPUINSTRINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_R600_AMDGPUINSTRINFO_H
end_define

begin_include
include|#
directive|include
file|"AMDGPURegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_define
define|#
directive|define
name|GET_INSTRINFO_HEADER
end_define

begin_define
define|#
directive|define
name|GET_INSTRINFO_ENUM
end_define

begin_define
define|#
directive|define
name|GET_INSTRINFO_OPERAND_ENUM
end_define

begin_include
include|#
directive|include
file|"AMDGPUGenInstrInfo.inc"
end_include

begin_define
define|#
directive|define
name|OPCODE_IS_ZERO_INT
value|AMDGPU::PRED_SETE_INT
end_define

begin_define
define|#
directive|define
name|OPCODE_IS_NOT_ZERO_INT
value|AMDGPU::PRED_SETNE_INT
end_define

begin_define
define|#
directive|define
name|OPCODE_IS_ZERO
value|AMDGPU::PRED_SETE
end_define

begin_define
define|#
directive|define
name|OPCODE_IS_NOT_ZERO
value|AMDGPU::PRED_SETNE
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AMDGPUSubtarget
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
name|AMDGPUInstrInfo
range|:
name|public
name|AMDGPUGenInstrInfo
block|{
name|private
operator|:
specifier|const
name|AMDGPURegisterInfo
name|RI
block|;
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|protected
operator|:
specifier|const
name|AMDGPUSubtarget
operator|&
name|ST
block|;
name|public
operator|:
name|explicit
name|AMDGPUInstrInfo
argument_list|(
specifier|const
name|AMDGPUSubtarget
operator|&
name|st
argument_list|)
block|;
name|virtual
specifier|const
name|AMDGPURegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|bool
name|isCoalescableExtInstr
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned&SrcReg
argument_list|,
argument|unsigned&DstReg
argument_list|,
argument|unsigned&SubIdx
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|isLoadFromStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|isLoadFromStackSlotPostFE
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
name|override
block|;
name|bool
name|hasLoadFromStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|const MachineMemOperand *&MMO
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|isStoreFromStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|;
name|unsigned
name|isStoreFromStackSlotPostFE
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|;
name|bool
name|hasStoreFromStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|const MachineMemOperand *&MMO
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|;
name|MachineInstr
operator|*
name|convertToThreeAddress
argument_list|(
argument|MachineFunction::iterator&MFI
argument_list|,
argument|MachineBasicBlock::iterator&MBBI
argument_list|,
argument|LiveVariables *LV
argument_list|)
specifier|const
name|override
block|;
name|bool
name|expandPostRAPseudo
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|)
specifier|const
name|override
block|;
name|void
name|storeRegToStackSlot
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|bool isKill
argument_list|,
argument|int FrameIndex
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
name|override
block|;
name|void
name|loadRegFromStackSlot
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|int FrameIndex
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
name|override
block|;
name|protected
operator|:
name|MachineInstr
operator|*
name|foldMemoryOperandImpl
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineInstr *MI
argument_list|,
argument|ArrayRef<unsigned> Ops
argument_list|,
argument|MachineBasicBlock::iterator InsertPt
argument_list|,
argument|int FrameIndex
argument_list|)
specifier|const
name|override
block|;
name|MachineInstr
operator|*
name|foldMemoryOperandImpl
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineInstr *MI
argument_list|,
argument|ArrayRef<unsigned> Ops
argument_list|,
argument|MachineBasicBlock::iterator InsertPt
argument_list|,
argument|MachineInstr *LoadMI
argument_list|)
specifier|const
name|override
block|;
name|public
operator|:
comment|/// \returns the smallest register index that will be accessed by an indirect
comment|/// read or write or -1 if indirect addressing is not used by this program.
name|int
name|getIndirectIndexBegin
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|/// \returns the largest register index that will be accessed by an indirect
comment|/// read or write or -1 if indirect addressing is not used by this program.
name|int
name|getIndirectIndexEnd
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|bool
name|unfoldMemoryOperand
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineInstr *MI
argument_list|,
argument|unsigned Reg
argument_list|,
argument|bool UnfoldLoad
argument_list|,
argument|bool UnfoldStore
argument_list|,
argument|SmallVectorImpl<MachineInstr *>&NewMIs
argument_list|)
specifier|const
name|override
block|;
name|bool
name|unfoldMemoryOperand
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDNode *N
argument_list|,
argument|SmallVectorImpl<SDNode *>&NewNodes
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getOpcodeAfterMemoryUnfold
argument_list|(
argument|unsigned Opc
argument_list|,
argument|bool UnfoldLoad
argument_list|,
argument|bool UnfoldStore
argument_list|,
argument|unsigned *LoadRegIndex = nullptr
argument_list|)
specifier|const
name|override
block|;
name|bool
name|enableClusterLoads
argument_list|()
specifier|const
name|override
block|;
name|bool
name|shouldScheduleLoadsNear
argument_list|(
argument|SDNode *Load1
argument_list|,
argument|SDNode *Load2
argument_list|,
argument|int64_t Offset1
argument_list|,
argument|int64_t Offset2
argument_list|,
argument|unsigned NumLoads
argument_list|)
specifier|const
name|override
block|;
name|bool
name|ReverseBranchCondition
argument_list|(
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
name|override
block|;
name|void
name|insertNoop
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isPredicated
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
name|override
block|;
name|bool
name|SubsumesPredicate
argument_list|(
argument|ArrayRef<MachineOperand> Pred1
argument_list|,
argument|ArrayRef<MachineOperand> Pred2
argument_list|)
specifier|const
name|override
block|;
name|bool
name|DefinesPredicate
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|std::vector<MachineOperand>&Pred
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isPredicable
argument_list|(
argument|MachineInstr *MI
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isSafeToMoveRegClassDefs
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
name|override
block|;
comment|// Helper functions that check the opcode for status information
name|bool
name|isRegisterStore
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isRegisterLoad
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
comment|/// \brief Return a target-specific opcode if Opcode is a pseudo instruction.
comment|/// Return -1 if the target-specific opcode for the pseudo instruction does
comment|/// not exist. If Opcode is not a pseudo instruction, this is identity.
name|int
name|pseudoToMCOpcode
argument_list|(
argument|int Opcode
argument_list|)
specifier|const
block|;
comment|/// \brief Return the descriptor of the target-specific machine instruction
comment|/// that corresponds to the specified pseudo or native opcode.
specifier|const
name|MCInstrDesc
operator|&
name|getMCOpcodeFromPseudo
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|pseudoToMCOpcode
argument_list|(
name|Opcode
argument_list|)
argument_list|)
return|;
block|}
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
name|int
block|,
specifier|const
name|char
operator|*
operator|>>
name|getSerializableTargetIndices
argument_list|()
specifier|const
name|override
block|;
comment|//===---------------------------------------------------------------------===//
comment|// Pure virtual funtions to be implemented by sub-classes.
comment|//===---------------------------------------------------------------------===//
name|virtual
name|bool
name|isMov
argument_list|(
argument|unsigned opcode
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// \brief Calculate the "Indirect Address" for the given \p RegIndex and
comment|///        \p Channel
comment|///
comment|/// We model indirect addressing using a virtual address space that can be
comment|/// accesed with loads and stores.  The "Indirect Address" is the memory
comment|/// address in this virtual address space that maps to the given \p RegIndex
comment|/// and \p Channel.
name|virtual
name|unsigned
name|calculateIndirectAddress
argument_list|(
argument|unsigned RegIndex
argument_list|,
argument|unsigned Channel
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// \returns The register class to be used for loading and storing values
comment|/// from an "Indirect Address" .
name|virtual
specifier|const
name|TargetRegisterClass
operator|*
name|getIndirectAddrRegClass
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// \brief Build instruction(s) for an indirect register write.
comment|///
comment|/// \returns The instruction that performs the indirect register write
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
operator|=
literal|0
block|;
comment|/// \brief Build instruction(s) for an indirect register read.
comment|///
comment|/// \returns The instruction that performs the indirect register read
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
operator|=
literal|0
block|;
comment|/// \brief Build a MOV instruction.
name|virtual
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
operator|=
literal|0
block|;
comment|/// \brief Given a MIMG \p Opcode that writes all 4 channels, return the
comment|/// equivalent opcode that writes \p Channels Channels.
name|int
name|getMaskedMIMGOp
argument_list|(
argument|uint16_t Opcode
argument_list|,
argument|unsigned Channels
argument_list|)
specifier|const
block|;  }
decl_stmt|;
name|namespace
name|AMDGPU
block|{
name|LLVM_READONLY
name|int16_t
name|getNamedOperandIdx
parameter_list|(
name|uint16_t
name|Opcode
parameter_list|,
name|uint16_t
name|NamedIndex
parameter_list|)
function_decl|;
block|}
comment|// End namespace AMDGPU
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_define
define|#
directive|define
name|AMDGPU_FLAG_REGISTER_LOAD
value|(UINT64_C(1)<< 63)
end_define

begin_define
define|#
directive|define
name|AMDGPU_FLAG_REGISTER_STORE
value|(UINT64_C(1)<< 62)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

