begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SIRegisterInfo.h - SI Register Info Interface ----------*- C++ -*--===//
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
comment|/// \brief Interface definition for SIRegisterInfo
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
name|SIREGISTERINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|SIREGISTERINFO_H_
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
name|struct
name|SIRegisterInfo
range|:
name|public
name|AMDGPURegisterInfo
block|{
name|SIRegisterInfo
argument_list|(
specifier|const
name|AMDGPUSubtarget
operator|&
name|st
argument_list|)
block|;
name|BitVector
name|getReservedRegs
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getRegPressureLimit
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|,
argument|MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|bool
name|requiresRegisterScavenging
argument_list|(
argument|const MachineFunction&Fn
argument_list|)
specifier|const
name|override
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
argument|RegScavenger *RS
argument_list|)
specifier|const
name|override
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
name|override
block|;
name|unsigned
name|getHWRegIndex
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Return the 'base' register class for this register.
comment|/// e.g. SGPR0 => SReg_32, VGPR => VReg_32 SGPR0_SGPR1 -> SReg_32, etc.
specifier|const
name|TargetRegisterClass
operator|*
name|getPhysRegClass
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
block|;
comment|/// \returns true if this class contains only SGPR registers
name|bool
name|isSGPRClass
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
block|;
comment|/// \returns true if this class contains VGPR registers.
name|bool
name|hasVGPRs
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
block|;
comment|/// \returns A VGPR reg class with the same width as \p SRC
specifier|const
name|TargetRegisterClass
operator|*
name|getEquivalentVGPRClass
argument_list|(
argument|const TargetRegisterClass *SRC
argument_list|)
specifier|const
block|;
comment|/// \returns The register class that is used for a sub-register of \p RC for
comment|/// the given \p SubIdx.  If \p SubIdx equals NoSubRegister, \p RC will
comment|/// be returned.
specifier|const
name|TargetRegisterClass
operator|*
name|getSubRegClass
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|,
argument|unsigned SubIdx
argument_list|)
specifier|const
block|;
comment|/// \p Channel This is the register channel (e.g. a value from 0-16), not the
comment|///            SubReg index.
comment|/// \returns The sub-register of Reg that is in Channel.
name|unsigned
name|getPhysRegSubReg
argument_list|(
argument|unsigned Reg
argument_list|,
argument|const TargetRegisterClass *SubRC
argument_list|,
argument|unsigned Channel
argument_list|)
specifier|const
block|;
comment|/// \returns True if operands defined with this register class can accept
comment|/// inline immediates.
name|bool
name|regClassCanUseImmediate
argument_list|(
argument|int RCID
argument_list|)
specifier|const
block|;
comment|/// \returns True if operands defined with this register class can accept
comment|/// inline immediates.
name|bool
name|regClassCanUseImmediate
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
block|;    enum
name|PreloadedValue
block|{
name|TGID_X
block|,
name|TGID_Y
block|,
name|TGID_Z
block|,
name|SCRATCH_WAVE_OFFSET
block|,
name|SCRATCH_PTR
block|}
block|;
comment|/// \brief Returns the physical register that \p Value is stored in.
name|unsigned
name|getPreloadedValue
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|enum PreloadedValue Value
argument_list|)
specifier|const
block|;  }
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

begin_comment
comment|// SIREGISTERINFO_H_
end_comment

end_unit

