begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PPCRegisterInfo.h - PowerPC Register Information Impl ---*- C++ -*-===//
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
name|LLVM_LIB_TARGET_POWERPC_PPCREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_POWERPC_PPCREGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"PPC.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_define
define|#
directive|define
name|GET_REGINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"PPCGenRegisterInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
specifier|inline
specifier|static
name|unsigned
name|getCRFromCRBit
parameter_list|(
name|unsigned
name|SrcReg
parameter_list|)
block|{
name|unsigned
name|Reg
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|SrcReg
operator|==
name|PPC
operator|::
name|CR0LT
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR0GT
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR0EQ
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR0UN
condition|)
name|Reg
operator|=
name|PPC
operator|::
name|CR0
expr_stmt|;
elseif|else
if|if
condition|(
name|SrcReg
operator|==
name|PPC
operator|::
name|CR1LT
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR1GT
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR1EQ
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR1UN
condition|)
name|Reg
operator|=
name|PPC
operator|::
name|CR1
expr_stmt|;
elseif|else
if|if
condition|(
name|SrcReg
operator|==
name|PPC
operator|::
name|CR2LT
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR2GT
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR2EQ
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR2UN
condition|)
name|Reg
operator|=
name|PPC
operator|::
name|CR2
expr_stmt|;
elseif|else
if|if
condition|(
name|SrcReg
operator|==
name|PPC
operator|::
name|CR3LT
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR3GT
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR3EQ
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR3UN
condition|)
name|Reg
operator|=
name|PPC
operator|::
name|CR3
expr_stmt|;
elseif|else
if|if
condition|(
name|SrcReg
operator|==
name|PPC
operator|::
name|CR4LT
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR4GT
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR4EQ
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR4UN
condition|)
name|Reg
operator|=
name|PPC
operator|::
name|CR4
expr_stmt|;
elseif|else
if|if
condition|(
name|SrcReg
operator|==
name|PPC
operator|::
name|CR5LT
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR5GT
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR5EQ
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR5UN
condition|)
name|Reg
operator|=
name|PPC
operator|::
name|CR5
expr_stmt|;
elseif|else
if|if
condition|(
name|SrcReg
operator|==
name|PPC
operator|::
name|CR6LT
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR6GT
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR6EQ
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR6UN
condition|)
name|Reg
operator|=
name|PPC
operator|::
name|CR6
expr_stmt|;
elseif|else
if|if
condition|(
name|SrcReg
operator|==
name|PPC
operator|::
name|CR7LT
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR7GT
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR7EQ
operator|||
name|SrcReg
operator|==
name|PPC
operator|::
name|CR7UN
condition|)
name|Reg
operator|=
name|PPC
operator|::
name|CR7
expr_stmt|;
name|assert
argument_list|(
name|Reg
operator|!=
literal|0
operator|&&
literal|"Invalid CR bit register"
argument_list|)
expr_stmt|;
return|return
name|Reg
return|;
block|}
name|class
name|PPCRegisterInfo
range|:
name|public
name|PPCGenRegisterInfo
block|{
name|DenseMap
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|ImmToIdxMap
block|;
specifier|const
name|PPCTargetMachine
operator|&
name|TM
block|;
name|public
operator|:
name|PPCRegisterInfo
argument_list|(
specifier|const
name|PPCTargetMachine
operator|&
name|TM
argument_list|)
block|;
comment|/// getPointerRegClass - Return the register class to use to hold pointers.
comment|/// This is used for addressing modes.
specifier|const
name|TargetRegisterClass
operator|*
name|getPointerRegClass
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|unsigned Kind=
literal|0
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
argument|CallingConv::ID CC
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
name|void
name|adjustStackMapLiveOutMask
argument_list|(
argument|uint32_t *Mask
argument_list|)
specifier|const
name|override
block|;
name|BitVector
name|getReservedRegs
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isCallerPreservedPhysReg
argument_list|(
argument|unsigned PhysReg
argument_list|,
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
comment|/// We require the register scavenger.
name|bool
name|requiresRegisterScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|requiresFrameIndexScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|trackLivenessAfterRegAlloc
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|requiresVirtualBaseRegisters
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|void
name|lowerDynamicAlloc
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|)
specifier|const
block|;
name|void
name|lowerDynamicAreaOffset
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|)
specifier|const
block|;
name|void
name|lowerCRSpilling
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|unsigned FrameIndex
argument_list|)
specifier|const
block|;
name|void
name|lowerCRRestore
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|unsigned FrameIndex
argument_list|)
specifier|const
block|;
name|void
name|lowerCRBitSpilling
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|unsigned FrameIndex
argument_list|)
specifier|const
block|;
name|void
name|lowerCRBitRestore
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|unsigned FrameIndex
argument_list|)
specifier|const
block|;
name|void
name|lowerVRSAVESpilling
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|unsigned FrameIndex
argument_list|)
specifier|const
block|;
name|void
name|lowerVRSAVERestore
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|unsigned FrameIndex
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
comment|// Support for virtual base registers.
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
comment|// Debug information queries.
name|unsigned
name|getFrameRegister
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
comment|// Base pointer (stack realignment) support.
name|unsigned
name|getBaseRegister
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

