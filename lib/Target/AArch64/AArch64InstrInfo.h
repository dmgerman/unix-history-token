begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AArch64InstrInfo.h - AArch64 Instruction Information -----*- C++ -*-===//
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
comment|// This file contains the AArch64 implementation of the TargetInstrInfo class.
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
name|LLVM_TARGET_AArch64INSTRINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_AArch64INSTRINFO_H
end_define

begin_include
include|#
directive|include
file|"AArch64.h"
end_include

begin_include
include|#
directive|include
file|"AArch64RegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_define
define|#
directive|define
name|GET_INSTRINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"AArch64GenInstrInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AArch64Subtarget
decl_stmt|;
name|class
name|AArch64TargetMachine
decl_stmt|;
name|class
name|AArch64InstrInfo
range|:
name|public
name|AArch64GenInstrInfo
block|{
comment|// Reserve bits in the MachineMemOperand target hint flags, starting at 1.
comment|// They will be shifted into MOTargetHintStart when accessed.
block|enum
name|TargetMemOperandFlags
block|{
name|MOSuppressPair
operator|=
literal|1
block|}
block|;
specifier|const
name|AArch64RegisterInfo
name|RI
block|;
specifier|const
name|AArch64Subtarget
operator|&
name|Subtarget
block|;
name|public
operator|:
name|explicit
name|AArch64InstrInfo
argument_list|(
specifier|const
name|AArch64Subtarget
operator|&
name|STI
argument_list|)
block|;
comment|/// getRegisterInfo - TargetInstrInfo is a superset of MRegister info.  As
comment|/// such, whenever a client has an instance of instruction info, it should
comment|/// always be able to get register info as well (through this method).
specifier|const
name|AArch64RegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|RI
return|;
block|}
name|unsigned
name|GetInstSizeInBytes
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
name|bool
name|isCoalescableExtInstr
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned&SrcReg
argument_list|,
argument|unsigned&DstReg
argument_list|,
argument|unsigned&SubIdx
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|isLoadFromStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|isStoreToStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
name|override
block|;
comment|/// Returns true if there is a shiftable register and that the shift value
comment|/// is non-zero.
name|bool
name|hasShiftedReg
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
comment|/// Returns true if there is an extendable register and that the extending
comment|/// value is non-zero.
name|bool
name|hasExtendedReg
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
comment|/// \brief Does this instruction set its full destination register to zero?
name|bool
name|isGPRZero
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
comment|/// \brief Does this instruction rename a GPR without modifying bits?
name|bool
name|isGPRCopy
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
comment|/// \brief Does this instruction rename an FPR without modifying bits?
name|bool
name|isFPRCopy
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
comment|/// Return true if this is load/store scales or extends its register offset.
comment|/// This refers to scaling a dynamic index as opposed to scaled immediates.
comment|/// MI should be a memory op that allows scaled addressing.
name|bool
name|isScaledAddr
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
comment|/// Return true if pairing the given load or store is hinted to be
comment|/// unprofitable.
name|bool
name|isLdStPairSuppressed
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
comment|/// Hint that pairing the given load or store is unprofitable.
name|void
name|suppressLdStPair
argument_list|(
argument|MachineInstr *MI
argument_list|)
specifier|const
block|;
name|bool
name|getLdStBaseRegImmOfs
argument_list|(
argument|MachineInstr *LdSt
argument_list|,
argument|unsigned&BaseReg
argument_list|,
argument|unsigned&Offset
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
name|override
block|;
name|bool
name|enableClusterLoads
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|shouldClusterLoads
argument_list|(
argument|MachineInstr *FirstLdSt
argument_list|,
argument|MachineInstr *SecondLdSt
argument_list|,
argument|unsigned NumLoads
argument_list|)
specifier|const
name|override
block|;
name|bool
name|shouldScheduleAdjacent
argument_list|(
argument|MachineInstr *First
argument_list|,
argument|MachineInstr *Second
argument_list|)
specifier|const
name|override
block|;
name|MachineInstr
operator|*
name|emitFrameIndexDebugValue
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|int FrameIx
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|const MDNode *MDPtr
argument_list|,
argument|DebugLoc DL
argument_list|)
specifier|const
block|;
name|void
name|copyPhysRegTuple
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|DebugLoc DL
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|bool KillSrc
argument_list|,
argument|unsigned Opcode
argument_list|,
argument|llvm::ArrayRef<unsigned> Indices
argument_list|)
specifier|const
block|;
name|void
name|copyPhysReg
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|DebugLoc DL
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|bool KillSrc
argument_list|)
specifier|const
name|override
block|;
name|void
name|storeRegToStackSlot
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|bool isKill
argument_list|,
argument|int FrameIndex
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
name|override
block|;
name|void
name|loadRegFromStackSlot
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|int FrameIndex
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
name|override
block|;
name|MachineInstr
operator|*
name|foldMemoryOperandImpl
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineInstr *MI
argument_list|,
argument|const SmallVectorImpl<unsigned>&Ops
argument_list|,
argument|int FrameIndex
argument_list|)
specifier|const
name|override
block|;
name|bool
name|AnalyzeBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *&TBB
argument_list|,
argument|MachineBasicBlock *&FBB
argument_list|,
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|,
argument|bool AllowModify = false
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|RemoveBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|InsertBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *TBB
argument_list|,
argument|MachineBasicBlock *FBB
argument_list|,
argument|const SmallVectorImpl<MachineOperand>&Cond
argument_list|,
argument|DebugLoc DL
argument_list|)
specifier|const
name|override
block|;
name|bool
name|ReverseBranchCondition
argument_list|(
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
name|override
block|;
name|bool
name|canInsertSelect
argument_list|(
argument|const MachineBasicBlock&
argument_list|,
argument|const SmallVectorImpl<MachineOperand>&Cond
argument_list|,
argument|unsigned
argument_list|,
argument|unsigned
argument_list|,
argument|int&
argument_list|,
argument|int&
argument_list|,
argument|int&
argument_list|)
specifier|const
name|override
block|;
name|void
name|insertSelect
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|DebugLoc DL
argument_list|,
argument|unsigned DstReg
argument_list|,
argument|const SmallVectorImpl<MachineOperand>&Cond
argument_list|,
argument|unsigned TrueReg
argument_list|,
argument|unsigned FalseReg
argument_list|)
specifier|const
name|override
block|;
name|void
name|getNoopForMachoTarget
argument_list|(
argument|MCInst&NopInst
argument_list|)
specifier|const
name|override
block|;
comment|/// analyzeCompare - For a comparison instruction, return the source registers
comment|/// in SrcReg and SrcReg2, and the value it compares against in CmpValue.
comment|/// Return true if the comparison instruction can be analyzed.
name|bool
name|analyzeCompare
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned&SrcReg
argument_list|,
argument|unsigned&SrcReg2
argument_list|,
argument|int&CmpMask
argument_list|,
argument|int&CmpValue
argument_list|)
specifier|const
name|override
block|;
comment|/// optimizeCompareInstr - Convert the instruction supplying the argument to
comment|/// the comparison into one that sets the zero bit in the flags register.
name|bool
name|optimizeCompareInstr
argument_list|(
argument|MachineInstr *CmpInstr
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|unsigned SrcReg2
argument_list|,
argument|int CmpMask
argument_list|,
argument|int CmpValue
argument_list|,
argument|const MachineRegisterInfo *MRI
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|void
name|instantiateCondBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|DebugLoc DL
argument_list|,
argument|MachineBasicBlock *TBB
argument_list|,
argument|const SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
block|; }
decl_stmt|;
comment|/// emitFrameOffset - Emit instructions as needed to set DestReg to SrcReg
comment|/// plus Offset.  This is intended to be used from within the prolog/epilog
comment|/// insertion (PEI) pass, where a virtual scratch register may be allocated
comment|/// if necessary, to be replaced by the scavenger at the end of PEI.
name|void
name|emitFrameOffset
argument_list|(
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|MBBI
argument_list|,
name|DebugLoc
name|DL
argument_list|,
name|unsigned
name|DestReg
argument_list|,
name|unsigned
name|SrcReg
argument_list|,
name|int
name|Offset
argument_list|,
specifier|const
name|TargetInstrInfo
operator|*
name|TII
argument_list|,
name|MachineInstr
operator|::
name|MIFlag
operator|=
name|MachineInstr
operator|::
name|NoFlags
argument_list|,
name|bool
name|SetNZCV
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// rewriteAArch64FrameIndex - Rewrite MI to access 'Offset' bytes from the
comment|/// FP. Return false if the offset could not be handled directly in MI, and
comment|/// return the left-over portion by reference.
name|bool
name|rewriteAArch64FrameIndex
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|,
name|unsigned
name|FrameRegIdx
parameter_list|,
name|unsigned
name|FrameReg
parameter_list|,
name|int
modifier|&
name|Offset
parameter_list|,
specifier|const
name|AArch64InstrInfo
modifier|*
name|TII
parameter_list|)
function_decl|;
comment|/// \brief Use to report the frame offset status in isAArch64FrameOffsetLegal.
enum|enum
name|AArch64FrameOffsetStatus
block|{
name|AArch64FrameOffsetCannotUpdate
init|=
literal|0x0
block|,
comment|///< Offset cannot apply.
name|AArch64FrameOffsetIsLegal
init|=
literal|0x1
block|,
comment|///< Offset is legal.
name|AArch64FrameOffsetCanUpdate
init|=
literal|0x2
comment|///< Offset can apply, at least partly.
block|}
enum|;
comment|/// \brief Check if the @p Offset is a valid frame offset for @p MI.
comment|/// The returned value reports the validity of the frame offset for @p MI.
comment|/// It uses the values defined by AArch64FrameOffsetStatus for that.
comment|/// If result == AArch64FrameOffsetCannotUpdate, @p MI cannot be updated to
comment|/// use an offset.eq
comment|/// If result& AArch64FrameOffsetIsLegal, @p Offset can completely be
comment|/// rewriten in @p MI.
comment|/// If result& AArch64FrameOffsetCanUpdate, @p Offset contains the
comment|/// amount that is off the limit of the legal offset.
comment|/// If set, @p OutUseUnscaledOp will contain the whether @p MI should be
comment|/// turned into an unscaled operator, which opcode is in @p OutUnscaledOp.
comment|/// If set, @p EmittableOffset contains the amount that can be set in @p MI
comment|/// (possibly with @p OutUnscaledOp if OutUseUnscaledOp is true) and that
comment|/// is a legal offset.
name|int
name|isAArch64FrameOffsetLegal
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|,
name|int
modifier|&
name|Offset
parameter_list|,
name|bool
modifier|*
name|OutUseUnscaledOp
init|=
name|nullptr
parameter_list|,
name|unsigned
modifier|*
name|OutUnscaledOp
init|=
name|nullptr
parameter_list|,
name|int
modifier|*
name|EmittableOffset
init|=
name|nullptr
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|bool
name|isUncondBranchOpcode
parameter_list|(
name|int
name|Opc
parameter_list|)
block|{
return|return
name|Opc
operator|==
name|AArch64
operator|::
name|B
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isCondBranchOpcode
parameter_list|(
name|int
name|Opc
parameter_list|)
block|{
switch|switch
condition|(
name|Opc
condition|)
block|{
case|case
name|AArch64
operator|::
name|Bcc
case|:
case|case
name|AArch64
operator|::
name|CBZW
case|:
case|case
name|AArch64
operator|::
name|CBZX
case|:
case|case
name|AArch64
operator|::
name|CBNZW
case|:
case|case
name|AArch64
operator|::
name|CBNZX
case|:
case|case
name|AArch64
operator|::
name|TBZW
case|:
case|case
name|AArch64
operator|::
name|TBZX
case|:
case|case
name|AArch64
operator|::
name|TBNZW
case|:
case|case
name|AArch64
operator|::
name|TBNZX
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
name|isIndirectBranchOpcode
parameter_list|(
name|int
name|Opc
parameter_list|)
block|{
return|return
name|Opc
operator|==
name|AArch64
operator|::
name|BR
return|;
block|}
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

