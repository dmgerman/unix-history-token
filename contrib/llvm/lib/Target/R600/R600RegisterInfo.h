begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- R600RegisterInfo.h - R600 Register Info Interface ------*- C++ -*--===//
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
comment|/// \brief Interface definition for R600RegisterInfo
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
name|R600REGISTERINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|R600REGISTERINFO_H_
end_define

begin_include
include|#
directive|include
file|"AMDGPURegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"AMDGPUTargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|R600TargetMachine
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|struct
name|R600RegisterInfo
range|:
name|public
name|AMDGPURegisterInfo
block|{
name|AMDGPUTargetMachine
operator|&
name|TM
block|;
specifier|const
name|TargetInstrInfo
operator|&
name|TII
block|;
name|R600RegisterInfo
argument_list|(
name|AMDGPUTargetMachine
operator|&
name|tm
argument_list|,
specifier|const
name|TargetInstrInfo
operator|&
name|tii
argument_list|)
block|;
name|virtual
name|BitVector
name|getReservedRegs
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|/// \param RC is an AMDIL reg class.
comment|///
comment|/// \returns the R600 reg class that is equivalent to \p RC.
name|virtual
specifier|const
name|TargetRegisterClass
operator|*
name|getISARegClass
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
block|;
comment|/// \brief get the HW encoding for a register's channel.
name|unsigned
name|getHWRegChan
argument_list|(
argument|unsigned reg
argument_list|)
specifier|const
block|;
comment|/// \brief get the register class of the specified type to use in the
comment|/// CFGStructurizer
name|virtual
specifier|const
name|TargetRegisterClass
operator|*
name|getCFGStructurizerRegClass
argument_list|(
argument|MVT VT
argument_list|)
specifier|const
block|;
comment|/// \returns the sub reg enum value for the given \p Channel
comment|/// (e.g. getSubRegFromChannel(0) -> AMDGPU::sel_x)
name|unsigned
name|getSubRegFromChannel
argument_list|(
argument|unsigned Channel
argument_list|)
specifier|const
block|;  }
decl_stmt|;
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
comment|// AMDIDSAREGISTERINFO_H_
end_comment

end_unit

