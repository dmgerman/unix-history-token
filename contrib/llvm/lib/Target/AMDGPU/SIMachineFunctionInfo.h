begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SIMachineFunctionInfo.h - SIMachineFunctionInfo interface -*- C++ -*-==//
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
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_R600_SIMACHINEFUNCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_R600_SIMACHINEFUNCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"AMDGPUMachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"SIRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineRegisterInfo
decl_stmt|;
comment|/// This class keeps track of the SPI_SP_INPUT_ADDR config register, which
comment|/// tells the hardware which interpolation parameters to load.
name|class
name|SIMachineFunctionInfo
range|:
name|public
name|AMDGPUMachineFunction
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|unsigned
name|TIDReg
block|;
name|bool
name|HasSpilledVGPRs
block|;
name|public
operator|:
expr|struct
name|SpilledReg
block|{
name|unsigned
name|VGPR
block|;
name|int
name|Lane
block|;
name|SpilledReg
argument_list|(
argument|unsigned R
argument_list|,
argument|int L
argument_list|)
operator|:
name|VGPR
argument_list|(
name|R
argument_list|)
block|,
name|Lane
argument_list|(
argument|L
argument_list|)
block|{ }
name|SpilledReg
argument_list|()
operator|:
name|VGPR
argument_list|(
literal|0
argument_list|)
block|,
name|Lane
argument_list|(
argument|-
literal|1
argument_list|)
block|{ }
name|bool
name|hasLane
argument_list|()
block|{
return|return
name|Lane
operator|!=
operator|-
literal|1
return|;
block|}
expr|}
block|;
comment|// SIMachineFunctionInfo definition
name|SIMachineFunctionInfo
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|SpilledReg
name|getSpilledReg
argument_list|(
argument|MachineFunction *MF
argument_list|,
argument|unsigned FrameIndex
argument_list|,
argument|unsigned SubIdx
argument_list|)
block|;
name|unsigned
name|PSInputAddr
block|;
name|unsigned
name|NumUserSGPRs
block|;
name|std
operator|::
name|map
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|LaneVGPRs
block|;
name|unsigned
name|LDSWaveSpillSize
block|;
name|unsigned
name|ScratchOffsetReg
block|;
name|bool
name|hasCalculatedTID
argument_list|()
specifier|const
block|{
return|return
name|TIDReg
operator|!=
name|AMDGPU
operator|::
name|NoRegister
return|;
block|}
block|;
name|unsigned
name|getTIDReg
argument_list|()
specifier|const
block|{
return|return
name|TIDReg
return|;
block|}
block|;
name|void
name|setTIDReg
argument_list|(
argument|unsigned Reg
argument_list|)
block|{
name|TIDReg
operator|=
name|Reg
block|; }
name|bool
name|hasSpilledVGPRs
argument_list|()
specifier|const
block|{
return|return
name|HasSpilledVGPRs
return|;
block|}
name|void
name|setHasSpilledVGPRs
argument_list|(
argument|bool Spill = true
argument_list|)
block|{
name|HasSpilledVGPRs
operator|=
name|Spill
block|; }
name|unsigned
name|getMaximumWorkGroupSize
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|; }
block|;  }
end_decl_stmt

begin_comment
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

