begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AArch64InstructionSelector --------------------------------*- C++ -*-==//
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
comment|/// \file
end_comment

begin_comment
comment|/// This file declares the targeting of the InstructionSelector class for
end_comment

begin_comment
comment|/// AArch64.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_AARCH64_AARCH64INSTRUCTIONSELECTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AARCH64_AARCH64INSTRUCTIONSELECTOR_H
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
name|AArch64InstrInfo
decl_stmt|;
name|class
name|AArch64RegisterBankInfo
decl_stmt|;
name|class
name|AArch64RegisterInfo
decl_stmt|;
name|class
name|AArch64Subtarget
decl_stmt|;
name|class
name|AArch64TargetMachine
decl_stmt|;
name|class
name|AArch64InstructionSelector
range|:
name|public
name|InstructionSelector
block|{
name|public
operator|:
name|AArch64InstructionSelector
argument_list|(
specifier|const
name|AArch64TargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|AArch64Subtarget
operator|&
name|STI
argument_list|,
specifier|const
name|AArch64RegisterBankInfo
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
comment|/// tblgen-erated 'select' implementation, used as the initial selector for
comment|/// the patterns that don't require complex C++.
name|bool
name|selectImpl
argument_list|(
argument|MachineInstr&I
argument_list|)
specifier|const
block|;
specifier|const
name|AArch64TargetMachine
operator|&
name|TM
block|;
specifier|const
name|AArch64Subtarget
operator|&
name|STI
block|;
specifier|const
name|AArch64InstrInfo
operator|&
name|TII
block|;
specifier|const
name|AArch64RegisterInfo
operator|&
name|TRI
block|;
specifier|const
name|AArch64RegisterBankInfo
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
comment|// LLVM_LIB_TARGET_AARCH64_AARCH64INSTRUCTIONSELECTOR_H
end_comment

end_unit

