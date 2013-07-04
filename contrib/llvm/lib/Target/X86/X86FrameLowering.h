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
name|X86_FRAMELOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|X86_FRAMELOWERING_H
end_define

begin_include
include|#
directive|include
file|"X86Subtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCDwarf.h"
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
name|namespace
name|CU
block|{
comment|/// Compact unwind encoding values.
enum|enum
name|CompactUnwindEncodings
block|{
comment|/// [RE]BP based frame where [RE]BP is pused on the stack immediately after
comment|/// the return address, then [RE]SP is moved to [RE]BP.
name|UNWIND_MODE_BP_FRAME
init|=
literal|0x01000000
block|,
comment|/// A frameless function with a small constant stack size.
name|UNWIND_MODE_STACK_IMMD
init|=
literal|0x02000000
block|,
comment|/// A frameless function with a large constant stack size.
name|UNWIND_MODE_STACK_IND
init|=
literal|0x03000000
block|,
comment|/// No compact unwind encoding is available.
name|UNWIND_MODE_DWARF
init|=
literal|0x04000000
block|,
comment|/// Mask for encoding the frame registers.
name|UNWIND_BP_FRAME_REGISTERS
init|=
literal|0x00007FFF
block|,
comment|/// Mask for encoding the frameless registers.
name|UNWIND_FRAMELESS_STACK_REG_PERMUTATION
init|=
literal|0x000003FF
block|}
enum|;
block|}
comment|// end CU namespace
name|class
name|MCSymbol
decl_stmt|;
name|class
name|X86TargetMachine
decl_stmt|;
name|class
name|X86FrameLowering
range|:
name|public
name|TargetFrameLowering
block|{
specifier|const
name|X86TargetMachine
operator|&
name|TM
block|;
specifier|const
name|X86Subtarget
operator|&
name|STI
block|;
name|public
operator|:
name|explicit
name|X86FrameLowering
argument_list|(
specifier|const
name|X86TargetMachine
operator|&
name|tm
argument_list|,
specifier|const
name|X86Subtarget
operator|&
name|sti
argument_list|)
operator|:
name|TargetFrameLowering
argument_list|(
name|StackGrowsDown
argument_list|,
name|sti
operator|.
name|getStackAlignment
argument_list|()
argument_list|,
operator|(
name|sti
operator|.
name|is64Bit
argument_list|()
condition|?
operator|-
literal|8
else|:
operator|-
literal|4
operator|)
argument_list|)
block|,
name|TM
argument_list|(
name|tm
argument_list|)
block|,
name|STI
argument_list|(
argument|sti
argument_list|)
block|{   }
name|void
name|emitCalleeSavedFrameMoves
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MCSymbol *Label
argument_list|,
argument|unsigned FramePtr
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
name|void
name|adjustForSegmentedStacks
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
name|void
name|adjustForHiPEPrologue
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
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|int
name|getFrameIndexOffset
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|int FI
argument_list|)
specifier|const
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
block|;
name|uint32_t
name|getCompactUnwindEncoding
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
argument|MachineBasicBlock::iterator MI
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

