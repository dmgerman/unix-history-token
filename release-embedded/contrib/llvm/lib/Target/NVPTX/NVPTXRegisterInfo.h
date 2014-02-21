begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- NVPTXRegisterInfo.h - NVPTX Register Information Impl ----*- C++ -*-===//
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
comment|// This file contains the NVPTX implementation of the TargetRegisterInfo class.
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
name|NVPTXREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|NVPTXREGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"ManagedStringPool.h"
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
file|"NVPTXGenRegisterInfo.inc"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|<sstream>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Forward Declarations.
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|NVPTXSubtarget
decl_stmt|;
name|class
name|NVPTXRegisterInfo
range|:
name|public
name|NVPTXGenRegisterInfo
block|{
name|private
operator|:
name|bool
name|Is64Bit
block|;
comment|// Hold Strings that can be free'd all together with NVPTXRegisterInfo
name|ManagedStringPool
name|ManagedStrPool
block|;
name|public
operator|:
name|NVPTXRegisterInfo
argument_list|(
specifier|const
name|NVPTXSubtarget
operator|&
name|st
argument_list|)
block|;
comment|//------------------------------------------------------
comment|// Pure virtual functions from TargetRegisterInfo
comment|//------------------------------------------------------
comment|// NVPTX callee saved registers
name|virtual
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
comment|// NVPTX callee saved register classes
name|virtual
specifier|const
name|TargetRegisterClass
operator|*
specifier|const
operator|*
name|getCalleeSavedRegClasses
argument_list|(
argument|const MachineFunction *MF
argument_list|)
specifier|const
block|;
name|virtual
name|BitVector
name|getReservedRegs
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|virtual
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
name|virtual
name|int
name|getDwarfRegNum
argument_list|(
argument|unsigned RegNum
argument_list|,
argument|bool isEH
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
block|;
name|virtual
name|unsigned
name|getRARegister
argument_list|()
specifier|const
block|;
name|ManagedStringPool
operator|*
name|getStrPool
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|ManagedStringPool
operator|*
operator|>
operator|(
operator|&
name|ManagedStrPool
operator|)
return|;
block|}
specifier|const
name|char
operator|*
name|getName
argument_list|(
argument|unsigned RegNo
argument_list|)
specifier|const
block|{
name|std
operator|::
name|stringstream
name|O
block|;
name|O
operator|<<
literal|"reg"
operator|<<
name|RegNo
block|;
return|return
name|getStrPool
argument_list|()
operator|->
name|getManagedString
argument_list|(
name|O
operator|.
name|str
argument_list|()
operator|.
name|c_str
argument_list|()
argument_list|)
operator|->
name|c_str
argument_list|()
return|;
block|}
expr|}
block|;
name|std
operator|::
name|string
name|getNVPTXRegClassName
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
block|;
name|std
operator|::
name|string
name|getNVPTXRegClassStr
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

