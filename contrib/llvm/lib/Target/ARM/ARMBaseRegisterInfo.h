begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMBaseRegisterInfo.h - ARM Register Information Impl ---*- C++ -*-===//
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
name|LLVM_LIB_TARGET_ARM_ARMBASEREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_ARM_ARMBASEREGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/ARMBaseInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineInstr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallingConv.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_define
define|#
directive|define
name|GET_REGINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"ARMGenRegisterInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
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
comment|// end namespace ARMRI
comment|/// isARMArea1Register - Returns true if the register is a low register (r0-r7)
comment|/// or a stack/pc register that we should push/pop.
specifier|static
specifier|inline
name|bool
name|isARMArea1Register
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|bool
name|isIOS
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
case|case
name|LR
case|:
case|case
name|SP
case|:
case|case
name|PC
case|:
return|return
name|true
return|;
case|case
name|R8
case|:
case|case
name|R9
case|:
case|case
name|R10
case|:
case|case
name|R11
case|:
case|case
name|R12
case|:
comment|// For iOS we want r7 and lr to be next to each other.
return|return
operator|!
name|isIOS
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
specifier|static
specifier|inline
name|bool
name|isARMArea2Register
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|bool
name|isIOS
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
name|R8
case|:
case|case
name|R9
case|:
case|case
name|R10
case|:
case|case
name|R11
case|:
case|case
name|R12
case|:
comment|// iOS has this second area.
return|return
name|isIOS
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
specifier|static
specifier|inline
name|bool
name|isARMArea3Register
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|bool
name|isIOS
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
name|D15
case|:
case|case
name|D14
case|:
case|case
name|D13
case|:
case|case
name|D12
case|:
case|case
name|D11
case|:
case|case
name|D10
case|:
case|case
name|D9
case|:
case|case
name|D8
case|:
case|case
name|D7
case|:
case|case
name|D6
case|:
case|case
name|D5
case|:
case|case
name|D4
case|:
case|case
name|D3
case|:
case|case
name|D2
case|:
case|case
name|D1
case|:
case|case
name|D0
case|:
case|case
name|D31
case|:
case|case
name|D30
case|:
case|case
name|D29
case|:
case|case
name|D28
case|:
case|case
name|D27
case|:
case|case
name|D26
case|:
case|case
name|D25
case|:
case|case
name|D24
case|:
case|case
name|D23
case|:
case|case
name|D22
case|:
case|case
name|D21
case|:
case|case
name|D20
case|:
case|case
name|D19
case|:
case|case
name|D18
case|:
case|case
name|D17
case|:
case|case
name|D16
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
specifier|static
specifier|inline
name|bool
name|isCalleeSavedRegister
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
specifier|const
name|MCPhysReg
modifier|*
name|CSRegs
parameter_list|)
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|CSRegs
index|[
name|i
index|]
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|Reg
operator|==
name|CSRegs
index|[
name|i
index|]
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
name|class
name|ARMBaseRegisterInfo
range|:
name|public
name|ARMGenRegisterInfo
block|{
name|protected
operator|:
comment|/// BasePtr - ARM physical register used as a base ptr in complex stack
comment|/// frames. I.e., when we need a 3rd base, not just SP and FP, due to
comment|/// variable size stack objects.
name|unsigned
name|BasePtr
operator|=
name|ARM
operator|::
name|R6
block|;
comment|// Can be only subclassed.
name|explicit
name|ARMBaseRegisterInfo
argument_list|()
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
comment|/// Code Generation virtual methods...
specifier|const
name|MCPhysReg
operator|*
name|getCalleeSavedRegs
argument_list|(
argument|const MachineFunction *MF
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|MCPhysReg
operator|*
name|getCalleeSavedRegsViaCopy
argument_list|(
argument|const MachineFunction *MF
argument_list|)
specifier|const
block|;
specifier|const
name|uint32_t
operator|*
name|getCallPreservedMask
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|CallingConv::ID
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|uint32_t
operator|*
name|getNoPreservedMask
argument_list|()
specifier|const
name|override
block|;
specifier|const
name|uint32_t
operator|*
name|getTLSCallPreservedMask
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
specifier|const
name|uint32_t
operator|*
name|getSjLjDispatchPreservedMask
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|/// getThisReturnPreservedMask - Returns a call preserved mask specific to the
comment|/// case that 'returned' is on an i32 first argument if the calling convention
comment|/// is one that can (partially) model this attribute with a preserved mask
comment|/// (i.e. it is a calling convention that uses the same register for the first
comment|/// i32 argument and an i32 return value)
comment|///
comment|/// Should return NULL in the case that the calling convention does not have
comment|/// this property
specifier|const
name|uint32_t
operator|*
name|getThisReturnPreservedMask
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|CallingConv::ID
argument_list|)
specifier|const
block|;
name|BitVector
name|getReservedRegs
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
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
name|override
block|;
specifier|const
name|TargetRegisterClass
operator|*
name|getCrossCopyRegClass
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|TargetRegisterClass
operator|*
name|getLargestLegalSuperClass
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|,
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getRegPressureLimit
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|,
argument|MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|void
name|getRegAllocationHints
argument_list|(
argument|unsigned VirtReg
argument_list|,
argument|ArrayRef<MCPhysReg> Order
argument_list|,
argument|SmallVectorImpl<MCPhysReg>&Hints
argument_list|,
argument|const MachineFunction&MF
argument_list|,
argument|const VirtRegMap *VRM
argument_list|,
argument|const LiveRegMatrix *Matrix
argument_list|)
specifier|const
name|override
block|;
name|void
name|updateRegAllocHint
argument_list|(
argument|unsigned Reg
argument_list|,
argument|unsigned NewReg
argument_list|,
argument|MachineFunction&MF
argument_list|)
specifier|const
name|override
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
name|override
block|;
name|int64_t
name|getFrameIndexInstrOffset
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int Idx
argument_list|)
specifier|const
name|override
block|;
name|bool
name|needsFrameBaseReg
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
name|override
block|;
name|void
name|materializeFrameBaseRegister
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|,
argument|unsigned BaseReg
argument_list|,
argument|int FrameIdx
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
name|override
block|;
name|void
name|resolveFrameIndex
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|unsigned BaseReg
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isFrameOffsetLegal
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned BaseReg
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
name|override
block|;
name|bool
name|cannotEliminateFrame
argument_list|(
argument|const MachineFunction&MF
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
name|override
block|;
name|unsigned
name|getBaseRegister
argument_list|()
specifier|const
block|{
return|return
name|BasePtr
return|;
block|}
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
argument|const DebugLoc&dl
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
argument_list|,
argument|unsigned MIFlags = MachineInstr::NoFlags
argument_list|)
specifier|const
block|;
comment|/// Code Generation virtual methods...
name|bool
name|requiresRegisterScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|bool
name|trackLivenessAfterRegAlloc
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|bool
name|requiresFrameIndexScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|bool
name|requiresVirtualBaseRegisters
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|void
name|eliminateFrameIndex
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|int SPAdj
argument_list|,
argument|unsigned FIOperandNum
argument_list|,
argument|RegScavenger *RS = nullptr
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief SrcRC and DstRC will be morphed into NewRC if this returns true
name|bool
name|shouldCoalesce
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|const TargetRegisterClass *SrcRC
argument_list|,
argument|unsigned SubReg
argument_list|,
argument|const TargetRegisterClass *DstRC
argument_list|,
argument|unsigned DstSubReg
argument_list|,
argument|const TargetRegisterClass *NewRC
argument_list|)
specifier|const
name|override
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

begin_comment
comment|// LLVM_LIB_TARGET_ARM_ARMBASEREGISTERINFO_H
end_comment

end_unit

