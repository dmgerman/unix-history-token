begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ARMInstrInfo.h - ARM Instruction Information -------------*- C++ -*-===//
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
comment|// This file contains the ARM implementation of the TargetInstrInfo class.
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
name|ARMINSTRUCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|ARMINSTRUCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"ARMBaseInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"ARMRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"ARMSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"ARM.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ARMSubtarget
decl_stmt|;
name|class
name|ARMInstrInfo
range|:
name|public
name|ARMBaseInstrInfo
block|{
name|ARMRegisterInfo
name|RI
block|;
name|public
operator|:
name|explicit
name|ARMInstrInfo
argument_list|(
specifier|const
name|ARMSubtarget
operator|&
name|STI
argument_list|)
block|;
comment|// Return the non-pre/post incrementing version of 'Opc'. Return 0
comment|// if there is not such an opcode.
name|unsigned
name|getUnindexedOpcode
argument_list|(
argument|unsigned Opc
argument_list|)
specifier|const
block|;
name|void
name|reMaterialize
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned SubIdx
argument_list|,
argument|const MachineInstr *Orig
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
block|;
comment|/// getRegisterInfo - TargetInstrInfo is a superset of MRegister info.  As
comment|/// such, whenever a client has an instance of instruction info, it should
comment|/// always be able to get register info as well (through this method).
comment|///
specifier|const
name|ARMRegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|RI
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

