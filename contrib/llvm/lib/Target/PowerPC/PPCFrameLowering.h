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
specifier|const
name|unsigned
name|ReturnSaveOffset
block|;
specifier|const
name|unsigned
name|TOCSaveOffset
block|;
specifier|const
name|unsigned
name|FramePointerSaveOffset
block|;
specifier|const
name|unsigned
name|LinkageSize
block|;
specifier|const
name|unsigned
name|BasePointerSaveOffset
block|;
comment|/**    * \brief Find register[s] that can be used in function prologue and epilogue    *    * Find register[s] that can be use as scratch register[s] in function    * prologue and epilogue to save various registers (Link Register, Base    * Pointer, etc.). Prefer R0/R12, if available. Otherwise choose whatever    * register[s] are available.    *    * This method will return true if it is able to find enough unique scratch    * registers (1 or 2 depending on the requirement). If it is unable to find    * enough available registers in the block, it will return false and set    * any passed output parameter that corresponds to a required unique register    * to PPC::NoRegister.    *    * \param[in] MBB The machine basic block to find an available register for    * \param[in] UseAtEnd Specify whether the scratch register will be used at    *                     the end of the basic block (i.e., will the scratch    *                     register kill a register defined in the basic block)    * \param[in] TwoUniqueRegsRequired Specify whether this basic block will    *                                  require two unique scratch registers.    * \param[out] SR1 The scratch register to use    * \param[out] SR2 The second scratch register. If this pointer is not null    *                 the function will attempt to set it to an available    *                 register regardless of whether there is a hard requirement    *                 for two unique scratch registers.    * \return true if the required number of registers was found.    *         false if the required number of scratch register weren't available.    *         If either output parameter refers to a required scratch register    *         that isn't available, it will be set to an invalid value.    */
name|bool
name|findScratchRegister
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|,
argument|bool UseAtEnd
argument_list|,
argument|bool TwoUniqueRegsRequired = false
argument_list|,
argument|unsigned *SR1 = nullptr
argument_list|,
argument|unsigned *SR2 = nullptr
argument_list|)
specifier|const
block|;
name|bool
name|twoUniqueScratchRegsRequired
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
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
argument_list|,
argument|MachineBasicBlock&MBB
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
name|determineCalleeSaves
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|BitVector&SavedRegs
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
name|unsigned
name|getReturnSaveOffset
argument_list|()
specifier|const
block|{
return|return
name|ReturnSaveOffset
return|;
block|}
comment|/// getTOCSaveOffset - Return the previous frame offset to save the
comment|/// TOC register -- 64-bit SVR4 ABI only.
name|unsigned
name|getTOCSaveOffset
argument_list|()
specifier|const
block|{
return|return
name|TOCSaveOffset
return|;
block|}
comment|/// getFramePointerSaveOffset - Return the previous frame offset to save the
comment|/// frame pointer.
name|unsigned
name|getFramePointerSaveOffset
argument_list|()
specifier|const
block|{
return|return
name|FramePointerSaveOffset
return|;
block|}
comment|/// getBasePointerSaveOffset - Return the previous frame offset to save the
comment|/// base pointer.
name|unsigned
name|getBasePointerSaveOffset
argument_list|()
specifier|const
block|{
return|return
name|BasePointerSaveOffset
return|;
block|}
comment|/// getLinkageSize - Return the size of the PowerPC ABI linkage area.
comment|///
name|unsigned
name|getLinkageSize
argument_list|()
specifier|const
block|{
return|return
name|LinkageSize
return|;
block|}
specifier|const
name|SpillSlot
operator|*
name|getCalleeSavedSpillSlots
argument_list|(
argument|unsigned&NumEntries
argument_list|)
specifier|const
name|override
block|;
name|bool
name|enableShrinkWrapping
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
comment|/// Methods used by shrink wrapping to determine if MBB can be used for the
comment|/// function prologue/epilogue.
name|bool
name|canUseAsPrologue
argument_list|(
argument|const MachineBasicBlock&MBB
argument_list|)
specifier|const
name|override
block|;
name|bool
name|canUseAsEpilogue
argument_list|(
argument|const MachineBasicBlock&MBB
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

