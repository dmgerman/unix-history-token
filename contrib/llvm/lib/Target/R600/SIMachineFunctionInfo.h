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
name|SIMACHINEFUNCTIONINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|SIMACHINEFUNCTIONINFO_H_
end_define

begin_include
include|#
directive|include
file|"AMDGPUMachineFunction.h"
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
block|;    struct
name|RegSpillTracker
block|{
name|private
operator|:
name|unsigned
name|CurrentLane
block|;
name|std
operator|::
name|map
operator|<
name|unsigned
block|,
name|SpilledReg
operator|>
name|SpilledRegisters
block|;
name|public
operator|:
name|unsigned
name|LaneVGPR
block|;
name|RegSpillTracker
argument_list|()
operator|:
name|CurrentLane
argument_list|(
literal|0
argument_list|)
block|,
name|SpilledRegisters
argument_list|()
block|,
name|LaneVGPR
argument_list|(
literal|0
argument_list|)
block|{ }
comment|/// \p NumRegs The number of consecutive registers what need to be spilled.
comment|///            This function will ensure that all registers are stored in
comment|///            the same VGPR.
comment|/// \returns The lane to be used for storing the first register.
name|unsigned
name|reserveLanes
argument_list|(
argument|MachineRegisterInfo&MRI
argument_list|,
argument|MachineFunction *MF
argument_list|,
argument|unsigned NumRegs =
literal|1
argument_list|)
block|;
name|void
name|addSpilledReg
argument_list|(
argument|unsigned FrameIndex
argument_list|,
argument|unsigned Reg
argument_list|,
argument|int Lane = -
literal|1
argument_list|)
block|;
specifier|const
name|SpilledReg
operator|&
name|getSpilledReg
argument_list|(
argument|unsigned FrameIndex
argument_list|)
block|;
name|bool
name|programSpillsRegisters
argument_list|()
block|{
return|return
operator|!
name|SpilledRegisters
operator|.
name|empty
argument_list|()
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
name|unsigned
name|PSInputAddr
block|;   struct
name|RegSpillTracker
name|SpillTracker
block|;
name|unsigned
name|NumUserSGPRs
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

begin_comment
comment|//_SIMACHINEFUNCTIONINFO_H_
end_comment

end_unit

