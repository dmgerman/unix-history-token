begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SPURegisterInfo.h - Cell SPU Register Information Impl ----*- C++ -*-==//
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
comment|// This file contains the Cell SPU implementation of the TargetRegisterInfo
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
name|SPU_REGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|SPU_REGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"SPU.h"
end_include

begin_include
include|#
directive|include
file|"SPUGenRegisterInfo.h.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SPUSubtarget
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|SPURegisterInfo
range|:
name|public
name|SPUGenRegisterInfo
block|{
name|private
operator|:
specifier|const
name|SPUSubtarget
operator|&
name|Subtarget
block|;
specifier|const
name|TargetInstrInfo
operator|&
name|TII
block|;
comment|//! Predicate: Does the machine function use the link register?
name|bool
name|usesLR
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
name|public
operator|:
name|SPURegisterInfo
argument_list|(
specifier|const
name|SPUSubtarget
operator|&
name|subtarget
argument_list|,
specifier|const
name|TargetInstrInfo
operator|&
name|tii
argument_list|)
block|;
comment|//! Translate a register's enum value to a register number
comment|/*!       This method translates a register's enum value to it's regiser number,       e.g. SPU::R14 -> 14.      */
specifier|static
name|unsigned
name|getRegisterNumbering
argument_list|(
argument|unsigned RegEnum
argument_list|)
block|;
comment|/// getPointerRegClass - Return the register class to use to hold pointers.
comment|/// This is used for addressing modes.
name|virtual
specifier|const
name|TargetRegisterClass
operator|*
name|getPointerRegClass
argument_list|(
argument|unsigned Kind =
literal|0
argument_list|)
specifier|const
block|;
comment|//! Return the array of callee-saved registers
name|virtual
specifier|const
name|unsigned
operator|*
name|getCalleeSavedRegs
argument_list|(
argument|const MachineFunction *MF
argument_list|)
specifier|const
block|;
comment|//! Allow for scavenging, so we can get scratch registers when needed.
name|virtual
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
comment|//! Return the reserved registers
name|BitVector
name|getReservedRegs
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|//! Eliminate the call frame setup pseudo-instructions
name|void
name|eliminateCallFramePseudoInstr
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|)
specifier|const
block|;
comment|//! Convert frame indicies into machine operands
name|void
name|eliminateFrameIndex
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|int SPAdj
argument_list|,
argument|RegScavenger *RS = NULL
argument_list|)
specifier|const
block|;
comment|//! Get return address register (LR, aka R0)
name|unsigned
name|getRARegister
argument_list|()
specifier|const
block|;
comment|//! Get the stack frame register (SP, aka R1)
name|unsigned
name|getFrameRegister
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|//------------------------------------------------------------------------
comment|// New methods added:
comment|//------------------------------------------------------------------------
comment|//! Get DWARF debugging register number
name|int
name|getDwarfRegNum
argument_list|(
argument|unsigned RegNum
argument_list|,
argument|bool isEH
argument_list|)
specifier|const
block|;
comment|//! Convert D-form load/store to X-form load/store
comment|/*!       Converts a regiser displacement load/store into a register-indexed       load/store for large stack frames, when the stack frame exceeds the       range of a s10 displacement.      */
name|int
name|convertDFormToXForm
argument_list|(
argument|int dFormOpcode
argument_list|)
specifier|const
block|;
comment|//! Acquire an unused register in an emergency.
name|unsigned
name|findScratchRegister
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|RegScavenger *RS
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|int SPAdj
argument_list|)
specifier|const
block|;        }
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

