begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PPCFrameLowering.h - Define frame lowering for PowerPC --*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_POWERPC_PPCFRAMELOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_POWERPC_PPCFRAMELOWERING_H
end_define

begin_include
include|#
directive|include
file|"PPC.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PPCSubtarget
decl_stmt|;
name|class
name|PPCFrameLowering
range|:
name|public
name|TargetFrameLowering
block|{
specifier|const
name|PPCSubtarget
operator|&
name|Subtarget
block|;
name|public
operator|:
name|PPCFrameLowering
argument_list|(
specifier|const
name|PPCSubtarget
operator|&
name|STI
argument_list|)
block|;
name|unsigned
name|determineFrameLayout
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|bool UpdateMF = true
argument_list|,
argument|bool UseEstimate = false
argument_list|)
specifier|const
block|;
comment|/// emitProlog/emitEpilog - These methods insert prolog and epilog code into
comment|/// the function.
name|void
name|emitPrologue
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|void
name|emitEpilogue
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
name|override
block|;
name|bool
name|hasFP
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|bool
name|needsFP
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|void
name|replaceFPWithRealFP
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
name|void
name|processFunctionBeforeCalleeSavedScan
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|RegScavenger *RS = nullptr
argument_list|)
specifier|const
name|override
block|;
name|void
name|processFunctionBeforeFrameFinalized
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|RegScavenger *RS = nullptr
argument_list|)
specifier|const
name|override
block|;
name|void
name|addScavengingSpillSlot
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|RegScavenger *RS
argument_list|)
specifier|const
block|;
name|bool
name|spillCalleeSavedRegisters
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|const std::vector<CalleeSavedInfo>&CSI
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
name|override
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
name|override
block|;
name|bool
name|restoreCalleeSavedRegisters
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|const std::vector<CalleeSavedInfo>&CSI
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
name|override
block|;
comment|/// targetHandlesStackFrameRounding - Returns true if the target is
comment|/// responsible for rounding up the stack frame (probably at emitPrologue
comment|/// time).
name|bool
name|targetHandlesStackFrameRounding
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
comment|/// getReturnSaveOffset - Return the previous frame offset to save the
comment|/// return address.
specifier|static
name|unsigned
name|getReturnSaveOffset
argument_list|(
argument|bool isPPC64
argument_list|,
argument|bool isDarwinABI
argument_list|)
block|{
if|if
condition|(
name|isDarwinABI
condition|)
return|return
name|isPPC64
operator|?
literal|16
operator|:
literal|8
return|;
comment|// SVR4 ABI:
return|return
name|isPPC64
condition|?
literal|16
else|:
literal|4
return|;
block|}
comment|/// getTOCSaveOffset - Return the previous frame offset to save the
comment|/// TOC register -- 64-bit SVR4 ABI only.
specifier|static
name|unsigned
name|getTOCSaveOffset
parameter_list|(
name|bool
name|isELFv2ABI
parameter_list|)
block|{
return|return
name|isELFv2ABI
condition|?
literal|24
else|:
literal|40
return|;
block|}
comment|/// getFramePointerSaveOffset - Return the previous frame offset to save the
comment|/// frame pointer.
specifier|static
name|unsigned
name|getFramePointerSaveOffset
parameter_list|(
name|bool
name|isPPC64
parameter_list|,
name|bool
name|isDarwinABI
parameter_list|)
block|{
comment|// For the Darwin ABI:
comment|// We cannot use the TOC save slot (offset +20) in the PowerPC linkage area
comment|// for saving the frame pointer (if needed.)  While the published ABI has
comment|// not used this slot since at least MacOSX 10.2, there is older code
comment|// around that does use it, and that needs to continue to work.
if|if
condition|(
name|isDarwinABI
condition|)
return|return
name|isPPC64
condition|?
operator|-
literal|8U
else|:
operator|-
literal|4U
return|;
comment|// SVR4 ABI: First slot in the general register save area.
return|return
name|isPPC64
condition|?
operator|-
literal|8U
else|:
operator|-
literal|4U
return|;
block|}
comment|/// getBasePointerSaveOffset - Return the previous frame offset to save the
comment|/// base pointer.
specifier|static
name|unsigned
name|getBasePointerSaveOffset
parameter_list|(
name|bool
name|isPPC64
parameter_list|,
name|bool
name|isDarwinABI
parameter_list|,
name|bool
name|isPIC
parameter_list|)
block|{
if|if
condition|(
name|isDarwinABI
condition|)
return|return
name|isPPC64
condition|?
operator|-
literal|16U
else|:
operator|-
literal|8U
return|;
comment|// SVR4 ABI: First slot in the general register save area.
return|return
name|isPPC64
condition|?
operator|-
literal|16U
else|:
name|isPIC
condition|?
operator|-
literal|12U
else|:
operator|-
literal|8U
return|;
block|}
comment|/// getLinkageSize - Return the size of the PowerPC ABI linkage area.
comment|///
specifier|static
name|unsigned
name|getLinkageSize
parameter_list|(
name|bool
name|isPPC64
parameter_list|,
name|bool
name|isDarwinABI
parameter_list|,
name|bool
name|isELFv2ABI
parameter_list|)
block|{
if|if
condition|(
name|isDarwinABI
operator|||
name|isPPC64
condition|)
return|return
operator|(
name|isELFv2ABI
condition|?
literal|4
else|:
literal|6
operator|)
operator|*
operator|(
name|isPPC64
condition|?
literal|8
else|:
literal|4
operator|)
return|;
comment|// SVR4 ABI:
return|return
literal|8
return|;
block|}
specifier|const
name|SpillSlot
modifier|*
name|getCalleeSavedSpillSlots
argument_list|(
name|unsigned
operator|&
name|NumEntries
argument_list|)
decl|const
name|override
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

