begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMHazardRecognizer.h - ARM Hazard Recognizers ----------*- C++ -*-===//
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
comment|// This file defines hazard recognizers for scheduling ARM functions.
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
name|ARMHAZARDRECOGNIZER_H
end_ifndef

begin_define
define|#
directive|define
name|ARMHAZARDRECOGNIZER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScoreboardHazardRecognizer.h"
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
name|ARMSubtarget
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|ARMHazardRecognizer
range|:
name|public
name|ScoreboardHazardRecognizer
block|{
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
name|ARMSubtarget
operator|&
name|STI
block|;
name|MachineInstr
operator|*
name|LastMI
block|;
name|unsigned
name|FpMLxStalls
block|;
name|unsigned
name|ITBlockSize
block|;
comment|// No. of MIs in current IT block yet to be scheduled.
name|MachineInstr
operator|*
name|ITBlockMIs
index|[
literal|4
index|]
block|;
name|public
operator|:
name|ARMHazardRecognizer
argument_list|(
specifier|const
name|InstrItineraryData
operator|*
name|ItinData
argument_list|,
specifier|const
name|ARMBaseInstrInfo
operator|&
name|tii
argument_list|,
specifier|const
name|ARMBaseRegisterInfo
operator|&
name|tri
argument_list|,
specifier|const
name|ARMSubtarget
operator|&
name|sti
argument_list|,
specifier|const
name|ScheduleDAG
operator|*
name|DAG
argument_list|)
operator|:
name|ScoreboardHazardRecognizer
argument_list|(
name|ItinData
argument_list|,
name|DAG
argument_list|,
literal|"post-RA-sched"
argument_list|)
block|,
name|TII
argument_list|(
name|tii
argument_list|)
block|,
name|TRI
argument_list|(
name|tri
argument_list|)
block|,
name|STI
argument_list|(
name|sti
argument_list|)
block|,
name|LastMI
argument_list|(
literal|0
argument_list|)
block|,
name|ITBlockSize
argument_list|(
literal|0
argument_list|)
block|{}
name|virtual
name|HazardType
name|getHazardType
argument_list|(
argument|SUnit *SU
argument_list|,
argument|int Stalls
argument_list|)
block|;
name|virtual
name|void
name|Reset
argument_list|()
block|;
name|virtual
name|void
name|EmitInstruction
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
block|;
name|virtual
name|void
name|AdvanceCycle
argument_list|()
block|;
name|virtual
name|void
name|RecedeCycle
argument_list|()
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
comment|// ARMHAZARDRECOGNIZER_H
end_comment

end_unit

