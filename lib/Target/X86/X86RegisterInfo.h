begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- X86RegisterInfo.h - X86 Register Information Impl --------*- C++ -*-===//
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
comment|// This file contains the X86 implementation of the TargetRegisterInfo class.
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
name|X86REGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|X86REGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"X86GenRegisterInfo.h.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Type
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|X86TargetMachine
decl_stmt|;
comment|/// N86 namespace - Native X86 register numbers
comment|///
name|namespace
name|N86
block|{
enum|enum
block|{
name|EAX
init|=
literal|0
block|,
name|ECX
init|=
literal|1
block|,
name|EDX
init|=
literal|2
block|,
name|EBX
init|=
literal|3
block|,
name|ESP
init|=
literal|4
block|,
name|EBP
init|=
literal|5
block|,
name|ESI
init|=
literal|6
block|,
name|EDI
init|=
literal|7
block|}
enum|;
block|}
name|namespace
name|X86
block|{
comment|/// SubregIndex - The index of various sized subregister classes. Note that
comment|/// these indices must be kept in sync with the class indices in the
comment|/// X86RegisterInfo.td file.
enum|enum
name|SubregIndex
block|{
name|SUBREG_8BIT
init|=
literal|1
block|,
name|SUBREG_8BIT_HI
init|=
literal|2
block|,
name|SUBREG_16BIT
init|=
literal|3
block|,
name|SUBREG_32BIT
init|=
literal|4
block|}
enum|;
block|}
comment|/// DWARFFlavour - Flavour of dwarf regnumbers
comment|///
name|namespace
name|DWARFFlavour
block|{
enum|enum
block|{
name|X86_64
init|=
literal|0
block|,
name|X86_32_DarwinEH
init|=
literal|1
block|,
name|X86_32_Generic
init|=
literal|2
block|}
enum|;
block|}
name|class
name|X86RegisterInfo
range|:
name|public
name|X86GenRegisterInfo
block|{
name|public
operator|:
name|X86TargetMachine
operator|&
name|TM
block|;
specifier|const
name|TargetInstrInfo
operator|&
name|TII
block|;
name|private
operator|:
comment|/// Is64Bit - Is the target 64-bits.
comment|///
name|bool
name|Is64Bit
block|;
comment|/// IsWin64 - Is the target on of win64 flavours
comment|///
name|bool
name|IsWin64
block|;
comment|/// SlotSize - Stack slot size in bytes.
comment|///
name|unsigned
name|SlotSize
block|;
comment|/// StackAlign - Default stack alignment.
comment|///
name|unsigned
name|StackAlign
block|;
comment|/// StackPtr - X86 physical register used as stack ptr.
comment|///
name|unsigned
name|StackPtr
block|;
comment|/// FramePtr - X86 physical register used as frame ptr.
comment|///
name|unsigned
name|FramePtr
block|;
name|public
operator|:
name|X86RegisterInfo
argument_list|(
name|X86TargetMachine
operator|&
name|tm
argument_list|,
specifier|const
name|TargetInstrInfo
operator|&
name|tii
argument_list|)
block|;
comment|/// getX86RegNum - Returns the native X86 register number for the given LLVM
comment|/// register identifier.
specifier|static
name|unsigned
name|getX86RegNum
argument_list|(
argument|unsigned RegNo
argument_list|)
block|;
name|unsigned
name|getStackAlignment
argument_list|()
specifier|const
block|{
return|return
name|StackAlign
return|;
block|}
comment|/// getDwarfRegNum - allows modification of X86GenRegisterInfo::getDwarfRegNum
comment|/// (created by TableGen) for target dependencies.
name|int
name|getDwarfRegNum
argument_list|(
argument|unsigned RegNum
argument_list|,
argument|bool isEH
argument_list|)
specifier|const
block|;
comment|/// Code Generation virtual methods...
comment|///
comment|/// getMatchingSuperRegClass - Return a subclass of the specified register
comment|/// class A so that each register in it has a sub-register of the
comment|/// specified sub-register index which is in the specified register class B.
name|virtual
specifier|const
name|TargetRegisterClass
operator|*
name|getMatchingSuperRegClass
argument_list|(
argument|const TargetRegisterClass *A
argument_list|,
argument|const TargetRegisterClass *B
argument_list|,
argument|unsigned Idx
argument_list|)
specifier|const
block|;
comment|/// getPointerRegClass - Returns a TargetRegisterClass used for pointer
comment|/// values.
specifier|const
name|TargetRegisterClass
operator|*
name|getPointerRegClass
argument_list|(
argument|unsigned Kind =
literal|0
argument_list|)
specifier|const
block|;
comment|/// getCrossCopyRegClass - Returns a legal register class to copy a register
comment|/// in the specified class to or from. Returns NULL if it is possible to copy
comment|/// between a two registers of the specified class.
specifier|const
name|TargetRegisterClass
operator|*
name|getCrossCopyRegClass
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
block|;
comment|/// getCalleeSavedRegs - Return a null-terminated list of all of the
comment|/// callee-save registers on this target.
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
comment|/// getCalleeSavedRegClasses - Return a null-terminated list of the preferred
comment|/// register classes to spill each callee-saved register with.  The order and
comment|/// length of this list match the getCalleeSavedRegs() list.
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
comment|/// getReservedRegs - Returns a bitset indexed by physical register number
comment|/// indicating if a register is a special register that has particular uses and
comment|/// should be considered unavailable at all times, e.g. SP, RA. This is used by
comment|/// register scavenger to determine what registers are free.
name|BitVector
name|getReservedRegs
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
name|needsStackRealignment
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
name|bool
name|hasReservedSpillSlot
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|unsigned Reg
argument_list|,
argument|int&FrameIdx
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
name|unsigned
name|eliminateFrameIndex
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|int SPAdj
argument_list|,
argument|int *Value = NULL
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
name|emitCalleeSavedFrameMoves
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|unsigned LabelId
argument_list|,
argument|unsigned FramePtr
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
name|int
name|getFrameIndexOffset
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|int FI
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
block|; }
decl_stmt|;
comment|// getX86SubSuperRegister - X86 utility function. It returns the sub or super
comment|// register of a specific X86 register.
comment|// e.g. getX86SubSuperRegister(X86::EAX, EVT::i16) return X86:AX
name|unsigned
name|getX86SubSuperRegister
parameter_list|(
name|unsigned
parameter_list|,
name|EVT
parameter_list|,
name|bool
name|High
init|=
name|false
parameter_list|)
function_decl|;
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

