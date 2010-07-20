begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Thumb2HazardRecognizer.h - Thumb2 Hazard Recognizers ----*- C++ -*-===//
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
comment|// This file defines hazard recognizers for scheduling Thumb2 functions on
end_comment

begin_comment
comment|// ARM processors.
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
name|THUMB2HAZARDRECOGNIZER_H
end_ifndef

begin_define
define|#
directive|define
name|THUMB2HAZARDRECOGNIZER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/PostRAHazardRecognizer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineInstr
decl_stmt|;
name|class
name|Thumb2HazardRecognizer
range|:
name|public
name|PostRAHazardRecognizer
block|{
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
name|Thumb2HazardRecognizer
argument_list|(
specifier|const
name|InstrItineraryData
operator|&
name|ItinData
argument_list|)
operator|:
name|PostRAHazardRecognizer
argument_list|(
argument|ItinData
argument_list|)
block|{}
name|virtual
name|HazardType
name|getHazardType
argument_list|(
name|SUnit
operator|*
name|SU
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
comment|// THUMB2HAZARDRECOGNIZER_H
end_comment

end_unit

