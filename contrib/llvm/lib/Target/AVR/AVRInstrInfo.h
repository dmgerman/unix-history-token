begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AVRInstrInfo.h - AVR Instruction Information ------------*- C++ -*-===//
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
comment|// This file contains the AVR implementation of the TargetInstrInfo class.
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
name|LLVM_AVR_INSTR_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AVR_INSTR_INFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"AVRRegisterInfo.h"
end_include

begin_define
define|#
directive|define
name|GET_INSTRINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"AVRGenInstrInfo.inc"
end_include

begin_undef
undef|#
directive|undef
name|GET_INSTRINFO_HEADER
end_undef

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|AVRCC
block|{
comment|/// AVR specific condition codes.
comment|/// These correspond to `AVR_*_COND` in `AVRInstrInfo.td`.
comment|/// They must be kept in synch.
enum|enum
name|CondCodes
block|{
name|COND_EQ
block|,
comment|//!< Equal
name|COND_NE
block|,
comment|//!< Not equal
name|COND_GE
block|,
comment|//!< Greater than or equal
name|COND_LT
block|,
comment|//!< Less than
name|COND_SH
block|,
comment|//!< Unsigned same or higher
name|COND_LO
block|,
comment|//!< Unsigned lower
name|COND_MI
block|,
comment|//!< Minus
name|COND_PL
block|,
comment|//!< Plus
name|COND_INVALID
block|}
enum|;
block|}
comment|// end of namespace AVRCC
name|namespace
name|AVRII
block|{
comment|/// Specifies a target operand flag.
enum|enum
name|TOF
block|{
name|MO_NO_FLAG
block|,
comment|/// On a symbol operand, this represents the lo part.
name|MO_LO
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
comment|/// On a symbol operand, this represents the hi part.
name|MO_HI
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
comment|/// On a symbol operand, this represents it has to be negated.
name|MO_NEG
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|}
enum|;
block|}
comment|// end of namespace AVRII
comment|/// Utilities related to the AVR instruction set.
name|class
name|AVRInstrInfo
range|:
name|public
name|AVRGenInstrInfo
block|{
name|public
operator|:
name|explicit
name|AVRInstrInfo
argument_list|()
block|;
specifier|const
name|AVRRegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|RI
return|;
block|}
specifier|const
name|MCInstrDesc
operator|&
name|getBrCond
argument_list|(
argument|AVRCC::CondCodes CC
argument_list|)
specifier|const
block|;
name|AVRCC
operator|::
name|CondCodes
name|getCondFromBranchOpc
argument_list|(
argument|unsigned Opc
argument_list|)
specifier|const
block|;
name|AVRCC
operator|::
name|CondCodes
name|getOppositeCondition
argument_list|(
argument|AVRCC::CondCodes CC
argument_list|)
specifier|const
block|;
name|unsigned
name|getInstSizeInBytes
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
name|void
name|copyPhysReg
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|const DebugLoc&DL
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
argument|MachineBasicBlock::iterator MI
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
argument|MachineBasicBlock::iterator MI
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
name|unsigned
name|isLoadFromStackSlot
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|isStoreToStackSlot
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
name|override
block|;
comment|// Branch analysis.
name|bool
name|analyzeBranch
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
name|insertBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *TBB
argument_list|,
argument|MachineBasicBlock *FBB
argument_list|,
argument|ArrayRef<MachineOperand> Cond
argument_list|,
argument|const DebugLoc&DL
argument_list|,
argument|int *BytesAdded = nullptr
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|removeBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|int *BytesRemoved = nullptr
argument_list|)
specifier|const
name|override
block|;
name|bool
name|reverseBranchCondition
argument_list|(
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
name|override
block|;
name|MachineBasicBlock
operator|*
name|getBranchDestBlock
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isBranchOffsetInRange
argument_list|(
argument|unsigned BranchOpc
argument_list|,
argument|int64_t BrOffset
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
specifier|const
name|AVRRegisterInfo
name|RI
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
comment|// LLVM_AVR_INSTR_INFO_H
end_comment

end_unit

