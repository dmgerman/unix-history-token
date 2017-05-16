begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MSP430InstrInfo.h - MSP430 Instruction Information ------*- C++ -*-===//
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
comment|// This file contains the MSP430 implementation of the TargetInstrInfo class.
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
name|LLVM_LIB_TARGET_MSP430_MSP430INSTRINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MSP430_MSP430INSTRINFO_H
end_define

begin_include
include|#
directive|include
file|"MSP430RegisterInfo.h"
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
file|"MSP430GenInstrInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MSP430Subtarget
decl_stmt|;
comment|/// MSP430II - This namespace holds all of the target specific flags that
comment|/// instruction info tracks.
comment|///
name|namespace
name|MSP430II
block|{
enum|enum
block|{
name|SizeShift
init|=
literal|2
block|,
name|SizeMask
init|=
literal|7
operator|<<
name|SizeShift
block|,
name|SizeUnknown
init|=
literal|0
operator|<<
name|SizeShift
block|,
name|SizeSpecial
init|=
literal|1
operator|<<
name|SizeShift
block|,
name|Size2Bytes
init|=
literal|2
operator|<<
name|SizeShift
block|,
name|Size4Bytes
init|=
literal|3
operator|<<
name|SizeShift
block|,
name|Size6Bytes
init|=
literal|4
operator|<<
name|SizeShift
block|}
enum|;
block|}
name|class
name|MSP430InstrInfo
range|:
name|public
name|MSP430GenInstrInfo
block|{
specifier|const
name|MSP430RegisterInfo
name|RI
block|;
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|explicit
name|MSP430InstrInfo
argument_list|(
name|MSP430Subtarget
operator|&
name|STI
argument_list|)
block|;
comment|/// getRegisterInfo - TargetInstrInfo is a superset of MRegister info.  As
comment|/// such, whenever a client has an instance of instruction info, it should
comment|/// always be able to get register info as well (through this method).
comment|///
specifier|const
name|TargetRegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|RI
return|;
block|}
name|void
name|copyPhysReg
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
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
argument|int FrameIdx
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getInstSizeInBytes
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
comment|// Branch folding goodness
name|bool
name|reverseBranchCondition
argument_list|(
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isUnpredicatedTerminator
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
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
argument|bool AllowModify
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
name|int64_t
name|getFramePoppedByCallee
argument_list|(
argument|const MachineInstr&I
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|isFrameInstr
argument_list|(
name|I
argument_list|)
operator|&&
literal|"Not a frame instruction"
argument_list|)
block|;
name|assert
argument_list|(
name|I
operator|.
name|getOperand
argument_list|(
literal|1
argument_list|)
operator|.
name|getImm
argument_list|()
operator|>=
literal|0
operator|&&
literal|"Size must not be negative"
argument_list|)
block|;
return|return
name|I
operator|.
name|getOperand
argument_list|(
literal|1
argument_list|)
operator|.
name|getImm
argument_list|()
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

