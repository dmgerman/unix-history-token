begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsRegisterInfo.h - Mips Register Information Impl -----*- C++ -*-===//
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
comment|// This file contains the Mips implementation of the TargetRegisterInfo class.
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
name|MIPSREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|MIPSREGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"Mips.h"
end_include

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
file|"MipsGenRegisterInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MipsSubtarget
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|MipsRegisterInfo
range|:
name|public
name|MipsGenRegisterInfo
block|{
name|protected
operator|:
specifier|const
name|MipsSubtarget
operator|&
name|Subtarget
block|;
name|public
operator|:
name|MipsRegisterInfo
argument_list|(
specifier|const
name|MipsSubtarget
operator|&
name|Subtarget
argument_list|)
block|;
comment|/// getRegisterNumbering - Given the enum value for some register, e.g.
comment|/// Mips::RA, return the number that it corresponds to (e.g. 31).
specifier|static
name|unsigned
name|getRegisterNumbering
argument_list|(
argument|unsigned RegEnum
argument_list|)
block|;
comment|/// Get PIC indirect call register
specifier|static
name|unsigned
name|getPICCallReg
argument_list|()
block|;
comment|/// Adjust the Mips stack frame.
name|void
name|adjustMipsStackFrame
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|/// Code Generation virtual methods...
specifier|const
name|TargetRegisterClass
operator|*
name|getPointerRegClass
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|unsigned Kind
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
specifier|const
name|uint16_t
operator|*
name|getCalleeSavedRegs
argument_list|(
argument|const MachineFunction *MF =
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
specifier|static
specifier|const
name|uint32_t
operator|*
name|getMips16RetHelperMask
argument_list|()
block|;
name|BitVector
name|getReservedRegs
argument_list|(
argument|const MachineFunction&MF
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
name|trackLivenessAfterRegAlloc
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|/// Stack Frame Processing Methods
name|void
name|eliminateFrameIndex
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|int SPAdj
argument_list|,
argument|unsigned FIOperandNum
argument_list|,
argument|RegScavenger *RS = NULL
argument_list|)
specifier|const
block|;
name|void
name|processFunctionBeforeFrameFinalized
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|RegScavenger *RS = NULL
argument_list|)
specifier|const
block|;
comment|/// Debug information queries.
name|unsigned
name|getFrameRegister
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|/// \brief Return GPR register class.
name|virtual
specifier|const
name|TargetRegisterClass
operator|*
name|intRegClass
argument_list|(
argument|unsigned Size
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|private
operator|:
name|virtual
name|void
name|eliminateFI
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|int FrameIndex
argument_list|,
argument|uint64_t StackSize
argument_list|,
argument|int64_t SPOffset
argument_list|)
specifier|const
operator|=
literal|0
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

