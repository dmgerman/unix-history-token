begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86RegisterInfo.h - X86 Register Information Impl -------*- C++ -*-===//
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

begin_define
define|#
directive|define
name|GET_REGINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"X86GenRegisterInfo.inc"
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
comment|/// BasePtr - X86 physical register used as a base ptr in complex stack
comment|/// frames. I.e., when we need a 3rd base, not just SP and FP, due to
comment|/// variable size stack objects.
name|unsigned
name|BasePtr
block|;
name|public
operator|:
name|X86RegisterInfo
argument_list|(
name|X86TargetMachine
operator|&
name|tm
argument_list|)
block|;
comment|// FIXME: This should be tablegen'd like getDwarfRegNum is
name|int
name|getSEHRegNum
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|;
comment|/// getCompactUnwindRegNum - This function maps the register to the number for
comment|/// compact unwind encoding. Return -1 if the register isn't valid.
name|int
name|getCompactUnwindRegNum
argument_list|(
argument|unsigned RegNum
argument_list|,
argument|bool isEH
argument_list|)
specifier|const
block|;
comment|/// Code Generation virtual methods...
comment|///
name|virtual
name|bool
name|trackLivenessAfterRegAlloc
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
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
name|virtual
specifier|const
name|TargetRegisterClass
operator|*
name|getSubClassWithSubReg
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|,
argument|unsigned Idx
argument_list|)
specifier|const
block|;
specifier|const
name|TargetRegisterClass
operator|*
name|getLargestLegalSuperClass
argument_list|(
argument|const TargetRegisterClass *RC
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
argument|const MachineFunction&MF
argument_list|,
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
name|unsigned
name|getRegPressureLimit
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|,
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|/// getCalleeSavedRegs - Return a null-terminated list of all of the
comment|/// callee-save registers on this target.
specifier|const
name|uint16_t
operator|*
name|getCalleeSavedRegs
argument_list|(
argument|const MachineFunction* MF =
literal|0
argument_list|)
specifier|const
block|;
specifier|const
name|uint32_t
operator|*
name|getCallPreservedMask
argument_list|(
argument|CallingConv::ID
argument_list|)
specifier|const
block|;
specifier|const
name|uint32_t
operator|*
name|getNoPreservedMask
argument_list|()
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
name|hasBasePointer
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|bool
name|canRealignStack
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
name|hasReservedSpillSlot
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|unsigned Reg
argument_list|,
argument|int&FrameIdx
argument_list|)
specifier|const
block|;
name|void
name|eliminateFrameIndex
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|int SPAdj
argument_list|,
argument|unsigned FIOperandNum
argument_list|,
argument|RegScavenger *RS = NULL
argument_list|)
specifier|const
block|;
comment|// Debug information queries.
name|unsigned
name|getFrameRegister
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|unsigned
name|getStackRegister
argument_list|()
specifier|const
block|{
return|return
name|StackPtr
return|;
block|}
name|unsigned
name|getBaseRegister
argument_list|()
specifier|const
block|{
return|return
name|BasePtr
return|;
block|}
comment|// FIXME: Move to FrameInfok
name|unsigned
name|getSlotSize
argument_list|()
specifier|const
block|{
return|return
name|SlotSize
return|;
block|}
expr|}
block|;
comment|// getX86SubSuperRegister - X86 utility function. It returns the sub or super
comment|// register of a specific X86 register.
comment|// e.g. getX86SubSuperRegister(X86::EAX, MVT::i16) return X86:AX
name|unsigned
name|getX86SubSuperRegister
argument_list|(
argument|unsigned
argument_list|,
argument|MVT::SimpleValueType
argument_list|,
argument|bool High=false
argument_list|)
block|;
comment|//get512BitRegister - X86 utility - returns 512-bit super register
name|unsigned
name|get512BitSuperRegister
argument_list|(
argument|unsigned Reg
argument_list|)
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

