begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- R600RegisterInfo.h - R600 Register Info Interface ------*- C++ -*--===//
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
comment|/// \brief Interface definition for R600RegisterInfo
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
name|LLVM_LIB_TARGET_AMDGPU_R600REGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_R600REGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"AMDGPURegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AMDGPUSubtarget
decl_stmt|;
name|struct
name|R600RegisterInfo
name|final
range|:
name|public
name|AMDGPURegisterInfo
block|{
name|RegClassWeight
name|RCW
block|;
name|R600RegisterInfo
argument_list|()
block|;
name|BitVector
name|getReservedRegs
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|MCPhysReg
operator|*
name|getCalleeSavedRegs
argument_list|(
argument|const MachineFunction *MF
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getFrameRegister
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief get the HW encoding for a register's channel.
name|unsigned
name|getHWRegChan
argument_list|(
argument|unsigned reg
argument_list|)
specifier|const
block|;
name|unsigned
name|getHWRegIndex
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
block|;
comment|/// \brief get the register class of the specified type to use in the
comment|/// CFGStructurizer
specifier|const
name|TargetRegisterClass
operator|*
name|getCFGStructurizerRegClass
argument_list|(
argument|MVT VT
argument_list|)
specifier|const
block|;
specifier|const
name|RegClassWeight
operator|&
name|getRegClassWeight
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
name|override
block|;
comment|// \returns true if \p Reg can be defined in one ALU clause and used in
comment|// another.
name|bool
name|isPhysRegLiveAcrossClauses
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
block|;
name|void
name|eliminateFrameIndex
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|int SPAdj
argument_list|,
argument|unsigned FIOperandNum
argument_list|,
argument|RegScavenger *RS = nullptr
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

