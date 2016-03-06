begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- HexagonRegisterInfo.h - Hexagon Register Information Impl --*- C++ -*-==//
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
comment|// This file contains the Hexagon implementation of the TargetRegisterInfo
end_comment

begin_comment
comment|// class.
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
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONREGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MachineLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_define
define|#
directive|define
name|GET_REGINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"HexagonGenRegisterInfo.inc"
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|//  We try not to hard code the reserved registers in our code,
end_comment

begin_comment
comment|//  so the following two macros were defined. However, there
end_comment

begin_comment
comment|//  are still a few places that R11 and R10 are hard wired.
end_comment

begin_comment
comment|//  See below. If, in the future, we decided to change the reserved
end_comment

begin_comment
comment|//  register. Don't forget changing the following places.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  1. the "Defs" set of STriw_pred in HexagonInstrInfo.td
end_comment

begin_comment
comment|//  2. the "Defs" set of LDri_pred in HexagonInstrInfo.td
end_comment

begin_comment
comment|//  3. the definition of "IntRegs" in HexagonRegisterInfo.td
end_comment

begin_comment
comment|//  4. the definition of "DoubleRegs" in HexagonRegisterInfo.td
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|HEXAGON_RESERVED_REG_1
value|Hexagon::R10
end_define

begin_define
define|#
directive|define
name|HEXAGON_RESERVED_REG_2
value|Hexagon::R11
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|HexagonRegisterInfo
range|:
name|public
name|HexagonGenRegisterInfo
block|{
name|public
operator|:
name|HexagonRegisterInfo
argument_list|()
block|;
comment|/// Code Generation virtual methods...
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
name|BitVector
name|getReservedRegs
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|void
name|eliminateFrameIndex
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|int SPAdj
argument_list|,
argument|unsigned FIOperandNum
argument_list|,
argument|RegScavenger *RS = nullptr
argument_list|)
specifier|const
name|override
block|;
comment|/// Returns true since we may need scavenging for a temporary register
comment|/// when generating hardware loop instructions.
name|bool
name|requiresRegisterScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
comment|/// Returns true. Spill code for predicate registers might need an extra
comment|/// register.
name|bool
name|requiresFrameIndexScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
comment|/// Returns true if the frame pointer is valid.
name|bool
name|useFPForScavengingIndex
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|bool
name|trackLivenessAfterRegAlloc
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
comment|// Debug information queries.
name|unsigned
name|getRARegister
argument_list|()
specifier|const
block|;
name|unsigned
name|getFrameRegister
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getFrameRegister
argument_list|()
specifier|const
block|;
name|unsigned
name|getStackRegister
argument_list|()
specifier|const
block|;
specifier|const
name|MCPhysReg
operator|*
name|getCallerSavedRegs
argument_list|(
argument|const MachineFunction *MF
argument_list|)
specifier|const
block|;
name|unsigned
name|getFirstCallerSavedNonParamReg
argument_list|()
specifier|const
block|;
name|bool
name|isEHReturnCalleeSaveReg
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
block|;
name|bool
name|isCalleeSaveReg
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
block|; }
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

end_unit

