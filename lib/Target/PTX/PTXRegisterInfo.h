begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PTXRegisterInfo.h - PTX Register Information Impl --------*- C++ -*-===//
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
comment|// This file contains the PTX implementation of the MRegisterInfo class.
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
name|PTX_REGISTER_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|PTX_REGISTER_INFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_define
define|#
directive|define
name|GET_REGINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"PTXGenRegisterInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PTXTargetMachine
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|struct
name|PTXRegisterInfo
range|:
name|public
name|PTXGenRegisterInfo
block|{
name|private
operator|:
specifier|const
name|TargetInstrInfo
operator|&
name|TII
block|;
name|public
operator|:
name|PTXRegisterInfo
argument_list|(
name|PTXTargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|TargetInstrInfo
operator|&
name|tii
argument_list|)
block|;
name|virtual
specifier|const
name|unsigned
operator|*
name|getCalleeSavedRegs
argument_list|(
argument|const MachineFunction *MF =
literal|0
argument_list|)
specifier|const
block|{
specifier|static
specifier|const
name|unsigned
name|CalleeSavedRegs
index|[]
operator|=
block|{
literal|0
block|}
block|;
return|return
name|CalleeSavedRegs
return|;
comment|// save nothing
block|}
name|virtual
name|BitVector
name|getReservedRegs
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|{
name|BitVector
name|Reserved
argument_list|(
name|getNumRegs
argument_list|()
argument_list|)
block|;
return|return
name|Reserved
return|;
comment|// reserve no regs
block|}
name|virtual
name|void
name|eliminateFrameIndex
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|int SPAdj
argument_list|,
argument|RegScavenger *RS = NULL
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getFrameRegister
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"PTX does not have a frame register"
argument_list|)
block|;
return|return
literal|0
return|;
block|}
expr|}
block|;
comment|// struct PTXRegisterInfo
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PTX_REGISTER_INFO_H
end_comment

end_unit

