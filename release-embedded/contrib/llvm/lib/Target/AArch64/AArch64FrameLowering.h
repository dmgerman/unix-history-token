begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- AArch64FrameLowering.h - Define frame lowering for AArch64 -*- C++ -*--=//
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
comment|// This class implements the AArch64-specific parts of the TargetFrameLowering
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
name|LLVM_AARCH64_FRAMEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AARCH64_FRAMEINFO_H
end_define

begin_include
include|#
directive|include
file|"AArch64Subtarget.h"
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
name|AArch64Subtarget
decl_stmt|;
name|class
name|AArch64FrameLowering
range|:
name|public
name|TargetFrameLowering
block|{
name|private
operator|:
comment|// In order to unify the spilling and restoring of callee-saved registers into
comment|// emitFrameMemOps, we need to be able to specify which instructions to use
comment|// for the relevant memory operations on each register class. An array of the
comment|// following struct is populated and passed in to achieve this.
expr|struct
name|LoadStoreMethod
block|{
specifier|const
name|TargetRegisterClass
operator|*
name|RegClass
block|;
comment|// E.g. GPR64RegClass
comment|// The preferred instruction.
name|unsigned
name|PairOpcode
block|;
comment|// E.g. LSPair64_STR
comment|// Sometimes only a single register can be handled at once.
name|unsigned
name|SingleOpcode
block|;
comment|// E.g. LS64_STR
block|}
block|;
name|protected
operator|:
specifier|const
name|AArch64Subtarget
operator|&
name|STI
block|;
name|public
operator|:
name|explicit
name|AArch64FrameLowering
argument_list|(
specifier|const
name|AArch64Subtarget
operator|&
name|sti
argument_list|)
operator|:
name|TargetFrameLowering
argument_list|(
name|TargetFrameLowering
operator|::
name|StackGrowsDown
argument_list|,
literal|16
argument_list|,
literal|0
argument_list|,
literal|16
argument_list|)
block|,
name|STI
argument_list|(
argument|sti
argument_list|)
block|{   }
comment|/// emitProlog/emitEpilog - These methods insert prolog and epilog code into
comment|/// the function.
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
comment|/// Decides how much stack adjustment to perform in each phase of the prologue
comment|/// and epilogue.
name|void
name|splitSPAdjustments
argument_list|(
argument|uint64_t Total
argument_list|,
argument|uint64_t&Initial
argument_list|,
argument|uint64_t&Residual
argument_list|)
specifier|const
block|;
name|int64_t
name|resolveFrameIndexReference
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|int FrameIndex
argument_list|,
argument|unsigned&FrameReg
argument_list|,
argument|int SPAdj
argument_list|,
argument|bool IsCalleeSaveOp
argument_list|)
specifier|const
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
block|;
name|virtual
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
block|;
name|virtual
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
block|;
comment|/// If the register is X30 (i.e. LR) and the return address is used in the
comment|/// function then the callee-save store doesn't actually kill the register,
comment|/// otherwise it does.
name|bool
name|determinePrologueDeath
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|unsigned Reg
argument_list|)
specifier|const
block|;
comment|/// This function emits the loads or stores required during prologue and
comment|/// epilogue as efficiently as possible.
comment|///
comment|/// The operations involved in setting up and tearing down the frame are
comment|/// similar enough to warrant a shared function, particularly as discrepancies
comment|/// between the two would be disastrous.
name|void
name|emitFrameMemOps
argument_list|(
argument|bool isStore
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|const std::vector<CalleeSavedInfo>&CSI
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|,
argument|const LoadStoreMethod PossibleClasses[]
argument_list|,
argument|unsigned NumClasses
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
name|bool
name|useFPForAddressing
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|/// On AA
name|virtual
name|bool
name|hasReservedCallFrame
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;  }
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

