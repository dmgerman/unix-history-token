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
name|HexagonREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|HexagonREGISTERINFO_H
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
name|HexagonSubtarget
decl_stmt|;
name|class
name|HexagonInstrInfo
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|struct
name|HexagonRegisterInfo
range|:
name|public
name|HexagonGenRegisterInfo
block|{
name|HexagonSubtarget
operator|&
name|Subtarget
block|;
name|HexagonRegisterInfo
argument_list|(
name|HexagonSubtarget
operator|&
name|st
argument_list|)
block|;
comment|/// Code Generation virtual methods...
specifier|const
name|uint16_t
operator|*
name|getCalleeSavedRegs
argument_list|(
argument|const MachineFunction *MF =
literal|0
argument_list|)
specifier|const
block|;
specifier|const
name|TargetRegisterClass
operator|*
specifier|const
operator|*
name|getCalleeSavedRegClasses
argument_list|(
argument|const MachineFunction *MF =
literal|0
argument_list|)
specifier|const
block|;
name|BitVector
name|getReservedRegs
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
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
argument|RegScavenger *RS = NULL
argument_list|)
specifier|const
block|;
comment|/// determineFrameLayout - Determine the size of the frame and maximum call
comment|/// frame size.
name|void
name|determineFrameLayout
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|/// requiresRegisterScavenging - returns true since we may need scavenging for
comment|/// a temporary register when generating hardware loop instructions.
name|bool
name|requiresRegisterScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
name|bool
name|trackLivenessAfterRegAlloc
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
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

