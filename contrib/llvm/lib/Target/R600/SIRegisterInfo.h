begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SIRegisterInfo.h - SI Register Info Interface ----------*- C++ -*--===//
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
comment|/// \brief Interface definition for SIRegisterInfo
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
name|SIREGISTERINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|SIREGISTERINFO_H_
end_define

begin_include
include|#
directive|include
file|"AMDGPURegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AMDGPUTargetMachine
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|struct
name|SIRegisterInfo
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
name|SIRegisterInfo
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
name|virtual
name|unsigned
name|getRegPressureLimit
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|,
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|/// \param RC is an AMDIL reg class.
comment|///
comment|/// \returns the SI register class that is equivalent to \p RC.
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
block|; }
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
comment|// SIREGISTERINFO_H_
end_comment

end_unit

