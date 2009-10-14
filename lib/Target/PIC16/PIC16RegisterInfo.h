begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PIC16RegisterInfo.h - PIC16 Register Information Impl ----*- C++ -*-===//
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
comment|// This file contains the PIC16 implementation of the TargetRegisterInfo class.
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
name|PIC16REGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|PIC16REGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"PIC16GenRegisterInfo.h.inc"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Forward Declarations.
name|class
name|PIC16Subtarget
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|PIC16RegisterInfo
range|:
name|public
name|PIC16GenRegisterInfo
block|{
name|private
operator|:
specifier|const
name|TargetInstrInfo
operator|&
name|TII
block|;
specifier|const
name|PIC16Subtarget
operator|&
name|ST
block|;
name|public
operator|:
name|PIC16RegisterInfo
argument_list|(
specifier|const
name|TargetInstrInfo
operator|&
name|tii
argument_list|,
specifier|const
name|PIC16Subtarget
operator|&
name|st
argument_list|)
block|;
comment|//------------------------------------------------------
comment|// Pure virtual functions from TargetRegisterInfo
comment|//------------------------------------------------------
comment|// PIC16 callee saved registers
name|virtual
specifier|const
name|unsigned
operator|*
name|getCalleeSavedRegs
argument_list|(
argument|const MachineFunction *MF =
literal|0
argument_list|)
specifier|const
block|;
comment|// PIC16 callee saved register classes
name|virtual
specifier|const
name|TargetRegisterClass
operator|*
specifier|const
operator|*
name|getCalleeSavedRegClasses
argument_list|(
argument|const MachineFunction *MF
argument_list|)
specifier|const
block|;
name|virtual
name|BitVector
name|getReservedRegs
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|hasFP
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|eliminateFrameIndex
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|int SPAdj
argument_list|,
argument|int *Value = NULL
argument_list|,
argument|RegScavenger *RS=NULL
argument_list|)
specifier|const
block|;
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
name|virtual
name|void
name|emitPrologue
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|emitEpilogue
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
block|;
name|virtual
name|int
name|getDwarfRegNum
argument_list|(
argument|unsigned RegNum
argument_list|,
argument|bool isEH
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getFrameRegister
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getRARegister
argument_list|()
specifier|const
block|;  }
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

