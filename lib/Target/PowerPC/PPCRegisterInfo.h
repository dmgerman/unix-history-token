begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PPCRegisterInfo.h - PowerPC Register Information Impl -----*- C++ -*-==//
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
comment|// This file contains the PowerPC implementation of the TargetRegisterInfo
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
name|POWERPC32_REGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|POWERPC32_REGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"PPC.h"
end_include

begin_include
include|#
directive|include
file|"PPCGenRegisterInfo.h.inc"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PPCSubtarget
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|PPCRegisterInfo
range|:
name|public
name|PPCGenRegisterInfo
block|{
name|std
operator|::
name|map
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|ImmToIdxMap
block|;
specifier|const
name|PPCSubtarget
operator|&
name|Subtarget
block|;
specifier|const
name|TargetInstrInfo
operator|&
name|TII
block|;
name|public
operator|:
name|PPCRegisterInfo
argument_list|(
specifier|const
name|PPCSubtarget
operator|&
name|SubTarget
argument_list|,
specifier|const
name|TargetInstrInfo
operator|&
name|tii
argument_list|)
block|;
comment|/// getRegisterNumbering - Given the enum value for some register, e.g.
comment|/// PPC::F14, return the number that it corresponds to (e.g. 14).
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
argument|unsigned Kind=
literal|0
argument_list|)
specifier|const
block|;
comment|/// Code Generation virtual methods...
specifier|const
name|unsigned
operator|*
name|getCalleeSavedRegs
argument_list|(
argument|const MachineFunction* MF =
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
comment|/// targetHandlesStackFrameRounding - Returns true if the target is
comment|/// responsible for rounding up the stack frame (probably at emitPrologue
comment|/// time).
name|bool
name|targetHandlesStackFrameRounding
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// requiresRegisterScavenging - We require a register scavenger.
comment|/// FIXME (64-bit): Should be inlined.
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
name|lowerDynamicAlloc
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|int SPAdj
argument_list|,
argument|RegScavenger *RS
argument_list|)
specifier|const
block|;
name|void
name|lowerCRSpilling
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|unsigned FrameIndex
argument_list|,
argument|int SPAdj
argument_list|,
argument|RegScavenger *RS
argument_list|)
specifier|const
block|;
name|unsigned
name|eliminateFrameIndex
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|int SPAdj
argument_list|,
argument|int *Value = NULL
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
name|processFunctionBeforeFrameFinalized
argument_list|(
argument|MachineFunction&MF
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
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|void
name|getInitialFrameState
argument_list|(
argument|std::vector<MachineMove>&Moves
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

