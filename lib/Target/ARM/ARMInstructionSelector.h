begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ARMInstructionSelector -----------------------------------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// This file declares the targeting of the InstructionSelector class for ARM.
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
name|LLVM_LIB_TARGET_ARM_ARMINSTRUCTIONSELECTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_ARM_ARMINSTRUCTIONSELECTOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/GlobalISel/InstructionSelector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ARMBaseInstrInfo
decl_stmt|;
name|class
name|ARMBaseRegisterInfo
decl_stmt|;
name|class
name|ARMRegisterBankInfo
decl_stmt|;
name|class
name|ARMSubtarget
decl_stmt|;
name|class
name|ARMInstructionSelector
range|:
name|public
name|InstructionSelector
block|{
name|public
operator|:
name|ARMInstructionSelector
argument_list|(
specifier|const
name|ARMSubtarget
operator|&
name|STI
argument_list|,
specifier|const
name|ARMRegisterBankInfo
operator|&
name|RBI
argument_list|)
block|;
name|bool
name|select
argument_list|(
argument|MachineInstr&I
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
specifier|const
name|ARMBaseInstrInfo
operator|&
name|TII
block|;
specifier|const
name|ARMBaseRegisterInfo
operator|&
name|TRI
block|;
specifier|const
name|ARMRegisterBankInfo
operator|&
name|RBI
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
comment|// LLVM_LIB_TARGET_ARM_ARMINSTRUCTIONSELECTOR_H
end_comment

end_unit

