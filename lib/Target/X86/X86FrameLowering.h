begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86TargetFrameLowering.h - Define frame lowering for X86 -*- C++ -*-==//
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
comment|// This class implements X86-specific bits of TargetFrameLowering class.
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
name|LLVM_LIB_TARGET_X86_X86FRAMELOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_X86_X86FRAMELOWERING_H
end_define

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
name|X86FrameLowering
range|:
name|public
name|TargetFrameLowering
block|{
name|public
operator|:
name|explicit
name|X86FrameLowering
argument_list|(
argument|StackDirection D
argument_list|,
argument|unsigned StackAl
argument_list|,
argument|int LAO
argument_list|)
operator|:
name|TargetFrameLowering
argument_list|(
argument|StackGrowsDown
argument_list|,
argument|StackAl
argument_list|,
argument|LAO
argument_list|)
block|{}
comment|/// Emit a call to the target's stack probe function. This is required for all
comment|/// large stack allocations on Windows. The caller is required to materialize
comment|/// the number of bytes to probe in RAX/EAX.
specifier|static
name|void
name|emitStackProbeCall
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
argument_list|,
argument|DebugLoc DL
argument_list|)
block|;
name|void
name|emitCalleeSavedFrameMoves
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
argument_list|,
argument|DebugLoc DL
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
name|void
name|adjustForSegmentedStacks
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&PrologueMBB
argument_list|)
specifier|const
name|override
block|;
name|void
name|adjustForHiPEPrologue
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&PrologueMBB
argument_list|)
specifier|const
name|override
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
name|bool
name|assignCalleeSavedSpillSlots
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|,
argument|std::vector<CalleeSavedInfo>&CSI
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
name|hasFP
argument_list|(
argument|const MachineFunction&MF
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
name|bool
name|canSimplifyCallFramePseudos
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|bool
name|needsFrameIndexResolution
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|int
name|getFrameIndexOffset
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|int FI
argument_list|)
specifier|const
name|override
block|;
name|int
name|getFrameIndexReference
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|int FI
argument_list|,
argument|unsigned&FrameReg
argument_list|)
specifier|const
name|override
block|;
name|int
name|getFrameIndexOffsetFromSP
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|int FI
argument_list|)
specifier|const
block|;
name|int
name|getFrameIndexReferenceFromSP
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|int FI
argument_list|,
argument|unsigned&FrameReg
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
comment|/// Check the instruction before/after the passed instruction. If
comment|/// it is an ADD/SUB/LEA instruction it is deleted argument and the
comment|/// stack adjustment is returned as a positive value for ADD/LEA and
comment|/// a negative for SUB.
specifier|static
name|int
name|mergeSPUpdates
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator&MBBI
argument_list|,
argument|unsigned StackPtr
argument_list|,
argument|bool doMergeWithPrevious
argument_list|)
block|;
comment|/// Emit a series of instructions to increment / decrement the stack
comment|/// pointer by a constant value.
specifier|static
name|void
name|emitSPUpdate
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator&MBBI
argument_list|,
argument|unsigned StackPtr
argument_list|,
argument|int64_t NumBytes
argument_list|,
argument|bool Is64BitTarget
argument_list|,
argument|bool Is64BitStackPtr
argument_list|,
argument|bool UseLEA
argument_list|,
argument|const TargetInstrInfo&TII
argument_list|,
argument|const TargetRegisterInfo&TRI
argument_list|)
block|;
comment|/// Check that LEA can be used on SP in an epilogue sequence for \p MF.
name|bool
name|canUseLEAForSPInEpilogue
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
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
name|private
operator|:
comment|/// convertArgMovsToPushes - This method tries to convert a call sequence
comment|/// that uses sub and mov instructions to put the argument onto the stack
comment|/// into a series of pushes.
comment|/// Returns true if the transformation succeeded, false if not.
name|bool
name|convertArgMovsToPushes
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|uint64_t Amount
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

