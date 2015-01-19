begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AMDGPUMCInstLower.h MachineInstr Lowering Interface ------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AMDGPU_MCINSTLOWER_H
end_ifndef

begin_define
define|#
directive|define
name|AMDGPU_MCINSTLOWER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AMDGPUSubtarget
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|AMDGPUMCInstLower
block|{
comment|// This must be kept in sync with the SISubtarget class in SIInstrInfo.td
enum|enum
name|SISubtarget
block|{
name|SI
init|=
literal|0
block|}
enum|;
name|MCContext
modifier|&
name|Ctx
decl_stmt|;
specifier|const
name|AMDGPUSubtarget
modifier|&
name|ST
decl_stmt|;
comment|/// Convert a member of the AMDGPUSubtarget::Generation enum to the
comment|/// SISubtarget enum.
name|enum
name|SISubtarget
name|AMDGPUSubtargetToSISubtarget
argument_list|(
name|unsigned
name|Gen
argument_list|)
decl|const
decl_stmt|;
comment|/// Get the MC opcode for this MachineInstr.
name|unsigned
name|getMCOpcode
argument_list|(
name|unsigned
name|MIOpcode
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
name|AMDGPUMCInstLower
argument_list|(
name|MCContext
operator|&
name|ctx
argument_list|,
specifier|const
name|AMDGPUSubtarget
operator|&
name|ST
argument_list|)
expr_stmt|;
comment|/// \brief Lower a MachineInstr to an MCInst
name|void
name|lower
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|MCInst
operator|&
name|OutMI
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//AMDGPU_MCINSTLOWER_H
end_comment

end_unit

