begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ARMRegisterInfo.h - ARM Register Information Impl --------*- C++ -*-===//
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
comment|// This file contains the ARM implementation of the TargetRegisterInfo class.
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
name|ARMREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|ARMREGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"ARMGenRegisterInfo.h.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ARMSubtarget
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|struct
name|ARMRegisterInfo
range|:
name|public
name|ARMGenRegisterInfo
block|{
specifier|const
name|TargetInstrInfo
operator|&
name|TII
block|;
specifier|const
name|ARMSubtarget
operator|&
name|STI
block|;
name|private
operator|:
comment|/// FramePtr - ARM physical register used as frame ptr.
name|unsigned
name|FramePtr
block|;
name|public
operator|:
name|ARMRegisterInfo
argument_list|(
specifier|const
name|TargetInstrInfo
operator|&
name|tii
argument_list|,
specifier|const
name|ARMSubtarget
operator|&
name|STI
argument_list|)
block|;
comment|/// emitLoadConstPool - Emits a load from constpool to materialize the
comment|/// specified immediate.
name|void
name|emitLoadConstPool
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator&MBBI
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|int Val
argument_list|,
argument|unsigned Pred
argument_list|,
argument|unsigned PredReg
argument_list|,
argument|const TargetInstrInfo *TII
argument_list|,
argument|bool isThumb
argument_list|,
argument|DebugLoc dl
argument_list|)
specifier|const
block|;
comment|/// getRegisterNumbering - Given the enum value for some register, e.g.
comment|/// ARM::LR, return the number that it corresponds to (e.g. 14).
specifier|static
name|unsigned
name|getRegisterNumbering
argument_list|(
argument|unsigned RegEnum
argument_list|)
block|;
comment|/// Same as previous getRegisterNumbering except it returns true in isSPVFP
comment|/// if the register is a single precision VFP register.
specifier|static
name|unsigned
name|getRegisterNumbering
argument_list|(
argument|unsigned RegEnum
argument_list|,
argument|bool&isSPVFP
argument_list|)
block|;
comment|/// getPointerRegClass - Return the register class to use to hold pointers.
comment|/// This is used for addressing modes.
specifier|const
name|TargetRegisterClass
operator|*
name|getPointerRegClass
argument_list|()
specifier|const
block|;
comment|/// Code Generation virtual methods...
specifier|const
name|TargetRegisterClass
operator|*
name|getPhysicalRegisterRegClass
argument_list|(
argument|unsigned Reg
argument_list|,
argument|MVT VT = MVT::Other
argument_list|)
specifier|const
block|;
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
name|bool
name|isReservedReg
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|unsigned Reg
argument_list|)
specifier|const
block|;
name|bool
name|requiresRegisterScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|bool
name|hasFP
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|bool
name|hasReservedCallFrame
argument_list|(
argument|MachineFunction&MF
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
name|void
name|processFunctionBeforeCalleeSavedScan
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|RegScavenger *RS = NULL
argument_list|)
specifier|const
block|;
name|void
name|emitPrologue
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
name|void
name|emitEpilogue
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
block|;
comment|// Debug information queries.
name|unsigned
name|getRARegister
argument_list|()
specifier|const
block|;
name|unsigned
name|getFrameRegister
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|// Exception handling queries.
name|unsigned
name|getEHExceptionRegister
argument_list|()
specifier|const
block|;
name|unsigned
name|getEHHandlerRegister
argument_list|()
specifier|const
block|;
name|int
name|getDwarfRegNum
argument_list|(
argument|unsigned RegNum
argument_list|,
argument|bool isEH
argument_list|)
specifier|const
block|;
name|bool
name|isLowRegister
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

