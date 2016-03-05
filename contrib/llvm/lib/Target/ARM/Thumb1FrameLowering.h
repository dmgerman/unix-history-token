begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Thumb1FrameLowering.h - Thumb1-specific frame info stuff --*- C++ -*-=//
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
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_ARM_THUMB1FRAMELOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_ARM_THUMB1FRAMELOWERING_H
end_define

begin_include
include|#
directive|include
file|"ARMFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"Thumb1InstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"ThumbRegisterInfo.h"
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
name|Thumb1FrameLowering
range|:
name|public
name|ARMFrameLowering
block|{
name|public
operator|:
name|explicit
name|Thumb1FrameLowering
argument_list|(
specifier|const
name|ARMSubtarget
operator|&
name|sti
argument_list|)
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
name|bool
name|hasReservedCallFrame
argument_list|(
argument|const MachineFunction&MF
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
argument|MachineBasicBlock::iterator MI
argument_list|)
specifier|const
name|override
block|;
comment|/// Check whether or not the given \p MBB can be used as a epilogue
comment|/// for the target.
comment|/// The epilogue will be inserted before the first terminator of that block.
comment|/// This method is used by the shrink-wrapping pass to decide if
comment|/// \p MBB will be correctly handled by the target.
name|bool
name|canUseAsEpilogue
argument_list|(
argument|const MachineBasicBlock&MBB
argument_list|)
specifier|const
name|override
block|;
comment|/// Disable shrink wrap as tBfar/BL will be used to adjust for long jumps.
name|bool
name|enableShrinkWrapping
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
name|private
operator|:
comment|/// Check if the frame lowering of \p MF needs a special fixup
comment|/// code sequence for the epilogue.
comment|/// Unlike T2 and ARM mode, the T1 pop instruction cannot restore
comment|/// to LR, and we can't pop the value directly to the PC when
comment|/// we need to update the SP after popping the value. So instead
comment|/// we have to emit:
comment|///   POP {r3}
comment|///   ADD sp, #offset
comment|///   BX r3
comment|/// If this would clobber a return value, then generate this sequence instead:
comment|///   MOV ip, r3
comment|///   POP {r3}
comment|///   ADD sp, #offset
comment|///   MOV lr, r3
comment|///   MOV r3, ip
comment|///   BX lr
name|bool
name|needPopSpecialFixUp
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|/// Emit the special fixup code sequence for the epilogue.
comment|/// \see needPopSpecialFixUp for more details.
comment|/// \p DoIt, tells this method whether or not to actually insert
comment|/// the code sequence in \p MBB. I.e., when \p DoIt is false,
comment|/// \p MBB is left untouched.
comment|/// \returns For \p DoIt == true: True when the emission succeeded
comment|/// false otherwise. For \p DoIt == false: True when the emission
comment|/// would have been possible, false otherwise.
name|bool
name|emitPopSpecialFixUp
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|bool DoIt
argument_list|)
specifier|const
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

