begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ARMBaseRegisterInfo.h - ARM Register Information Impl ----*- C++ -*-===//
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
comment|// This file contains the base ARM implementation of TargetRegisterInfo class.
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
name|ARMBASEREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|ARMBASEREGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"ARM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"ARMGenRegisterInfo.h.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ARMSubtarget
decl_stmt|;
name|class
name|ARMBaseInstrInfo
decl_stmt|;
name|class
name|Type
decl_stmt|;
comment|/// Register allocation hints.
name|namespace
name|ARMRI
block|{
enum|enum
block|{
name|RegPairOdd
init|=
literal|1
block|,
name|RegPairEven
init|=
literal|2
block|}
enum|;
block|}
comment|/// isARMLowRegister - Returns true if the register is low register r0-r7.
comment|///
specifier|static
specifier|inline
name|bool
name|isARMLowRegister
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
name|using
name|namespace
name|ARM
decl_stmt|;
switch|switch
condition|(
name|Reg
condition|)
block|{
case|case
name|R0
case|:
case|case
name|R1
case|:
case|case
name|R2
case|:
case|case
name|R3
case|:
case|case
name|R4
case|:
case|case
name|R5
case|:
case|case
name|R6
case|:
case|case
name|R7
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
name|struct
name|ARMBaseRegisterInfo
range|:
name|public
name|ARMGenRegisterInfo
block|{
name|protected
operator|:
specifier|const
name|ARMBaseInstrInfo
operator|&
name|TII
block|;
specifier|const
name|ARMSubtarget
operator|&
name|STI
block|;
comment|/// FramePtr - ARM physical register used as frame ptr.
name|unsigned
name|FramePtr
block|;
comment|// Can be only subclassed.
name|explicit
name|ARMBaseRegisterInfo
argument_list|(
specifier|const
name|ARMBaseInstrInfo
operator|&
name|tii
argument_list|,
specifier|const
name|ARMSubtarget
operator|&
name|STI
argument_list|)
block|;
comment|// Return the opcode that implements 'Op', or 0 if no opcode
name|unsigned
name|getOpcode
argument_list|(
argument|int Op
argument_list|)
specifier|const
block|;
name|public
operator|:
comment|/// getRegisterNumbering - Given the enum value for some register, e.g.
comment|/// ARM::LR, return the number that it corresponds to (e.g. 14). It
comment|/// also returns true in isSPVFP if the register is a single precision
comment|/// VFP register.
specifier|static
name|unsigned
name|getRegisterNumbering
argument_list|(
argument|unsigned RegEnum
argument_list|,
argument|bool *isSPVFP =
literal|0
argument_list|)
block|;
comment|/// Code Generation virtual methods...
specifier|const
name|unsigned
operator|*
name|getCalleeSavedRegs
argument_list|(
argument|const MachineFunction *MF =
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
name|std
operator|::
name|pair
operator|<
name|TargetRegisterClass
operator|::
name|iterator
block|,
name|TargetRegisterClass
operator|::
name|iterator
operator|>
name|getAllocationOrder
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|,
argument|unsigned HintType
argument_list|,
argument|unsigned HintReg
argument_list|,
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|unsigned
name|ResolveRegAllocHint
argument_list|(
argument|unsigned Type
argument_list|,
argument|unsigned Reg
argument_list|,
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|void
name|UpdateRegAllocHint
argument_list|(
argument|unsigned Reg
argument_list|,
argument|unsigned NewReg
argument_list|,
argument|MachineFunction&MF
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
name|cannotEliminateFrame
argument_list|(
argument|const MachineFunction&MF
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
comment|// Debug information queries.
name|unsigned
name|getRARegister
argument_list|()
specifier|const
block|;
name|unsigned
name|getFrameRegister
argument_list|(
argument|MachineFunction&MF
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
block|;
name|bool
name|isLowRegister
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
block|;
comment|/// emitLoadConstPool - Emits a load from constpool to materialize the
comment|/// specified immediate.
name|virtual
name|void
name|emitLoadConstPool
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator&MBBI
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned SubIdx
argument_list|,
argument|int Val
argument_list|,
argument|ARMCC::CondCodes Pred = ARMCC::AL
argument_list|,
argument|unsigned PredReg =
literal|0
argument_list|)
specifier|const
block|;
comment|/// Code Generation virtual methods...
name|virtual
name|bool
name|isReservedReg
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|unsigned Reg
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|requiresRegisterScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|requiresFrameIndexScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|hasReservedCallFrame
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
name|virtual
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
name|virtual
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
name|private
operator|:
name|unsigned
name|estimateRSStackSizeLimit
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
name|unsigned
name|getRegisterPairEven
argument_list|(
argument|unsigned Reg
argument_list|,
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|unsigned
name|getRegisterPairOdd
argument_list|(
argument|unsigned Reg
argument_list|,
argument|const MachineFunction&MF
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

