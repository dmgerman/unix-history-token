begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SystemZFrameLowering.h - Frame lowering for SystemZ -----*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|SYSTEMZFRAMELOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|SYSTEMZFRAMELOWERING_H
end_define

begin_include
include|#
directive|include
file|"SystemZSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IndexedMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetFrameLowering.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SystemZTargetMachine
decl_stmt|;
name|class
name|SystemZSubtarget
decl_stmt|;
name|class
name|SystemZFrameLowering
range|:
name|public
name|TargetFrameLowering
block|{
name|IndexedMap
operator|<
name|unsigned
operator|>
name|RegSpillOffsets
block|;
name|protected
operator|:
specifier|const
name|SystemZTargetMachine
operator|&
name|TM
block|;
specifier|const
name|SystemZSubtarget
operator|&
name|STI
block|;
name|public
operator|:
name|SystemZFrameLowering
argument_list|(
specifier|const
name|SystemZTargetMachine
operator|&
name|tm
argument_list|,
specifier|const
name|SystemZSubtarget
operator|&
name|sti
argument_list|)
block|;
comment|// Override TargetFrameLowering.
name|virtual
name|bool
name|isFPCloseToIncomingSP
argument_list|()
specifier|const
name|LLVM_OVERRIDE
block|{
return|return
name|false
return|;
block|}
name|virtual
specifier|const
name|SpillSlot
operator|*
name|getCalleeSavedSpillSlots
argument_list|(
argument|unsigned&NumEntries
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|void
name|processFunctionBeforeCalleeSavedScan
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|RegScavenger *RS
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|bool
name|spillCalleeSavedRegisters
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
argument_list|,
argument|const std::vector<CalleeSavedInfo>&CSI
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|bool
name|restoreCalleeSavedRegisters
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBII
argument_list|,
argument|const std::vector<CalleeSavedInfo>&CSI
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|void
name|processFunctionBeforeFrameFinalized
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|RegScavenger *RS
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
name|LLVM_OVERRIDE
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
name|LLVM_OVERRIDE
block|;
name|virtual
name|bool
name|hasFP
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|int
name|getFrameIndexOffset
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|int FI
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|bool
name|hasReservedCallFrame
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|void
name|eliminateCallFramePseudoInstr
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
comment|// Return the number of bytes in the callee-allocated part of the frame.
name|uint64_t
name|getAllocatedStackSize
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|// Return the byte offset from the incoming stack pointer of Reg's
comment|// ABI-defined save slot.  Return 0 if no slot is defined for Reg.
name|unsigned
name|getRegSpillOffset
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
block|{
return|return
name|RegSpillOffsets
index|[
name|Reg
index|]
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

