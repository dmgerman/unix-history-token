begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SIInstrInfo.h - SI Instruction Info Interface ---------------------===//
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
comment|/// \brief Interface definition for SIInstrInfo.
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
name|SIINSTRINFO_H
end_ifndef

begin_define
define|#
directive|define
name|SIINSTRINFO_H
end_define

begin_include
include|#
directive|include
file|"AMDGPUInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"SIRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SIInstrInfo
range|:
name|public
name|AMDGPUInstrInfo
block|{
name|private
operator|:
specifier|const
name|SIRegisterInfo
name|RI
block|;
name|public
operator|:
name|explicit
name|SIInstrInfo
argument_list|(
name|AMDGPUTargetMachine
operator|&
name|tm
argument_list|)
block|;
specifier|const
name|SIRegisterInfo
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
name|unsigned
name|commuteOpcode
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|virtual
name|MachineInstr
operator|*
name|commuteInstruction
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|bool NewMI=false
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
block|{
name|assert
argument_list|(
operator|!
literal|"Implement"
argument_list|)
block|;
return|return
literal|0
return|;
block|}
name|virtual
name|bool
name|isMov
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isSafeToMoveRegClassDefs
argument_list|(
argument|const TargetRegisterClass *RC
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
block|;   }
decl_stmt|;
name|namespace
name|AMDGPU
block|{
name|int
name|getVOPe64
parameter_list|(
name|uint16_t
name|Opcode
parameter_list|)
function_decl|;
name|int
name|getCommuteRev
parameter_list|(
name|uint16_t
name|Opcode
parameter_list|)
function_decl|;
name|int
name|getCommuteOrig
parameter_list|(
name|uint16_t
name|Opcode
parameter_list|)
function_decl|;
name|int
name|isMIMG
parameter_list|(
name|uint16_t
name|Opcode
parameter_list|)
function_decl|;
block|}
comment|// End namespace AMDGPU
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm
end_comment

begin_decl_stmt
name|namespace
name|SIInstrFlags
block|{
enum|enum
name|Flags
block|{
comment|// First 4 bits are the instruction encoding
name|VM_CNT
init|=
literal|1
operator|<<
literal|0
block|,
name|EXP_CNT
init|=
literal|1
operator|<<
literal|1
block|,
name|LGKM_CNT
init|=
literal|1
operator|<<
literal|2
block|}
enum|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//SIINSTRINFO_H
end_comment

end_unit

