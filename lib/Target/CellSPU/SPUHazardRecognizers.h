begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SPUHazardRecognizers.h - Cell SPU Hazard Recognizer -----*- C++ -*-===//
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
comment|// This file defines hazard recognizers for scheduling on the Cell SPU
end_comment

begin_comment
comment|// processor.
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
name|SPUHAZRECS_H
end_ifndef

begin_define
define|#
directive|define
name|SPUHAZRECS_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleHazardRecognizer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|TargetInstrInfo
decl_stmt|;
comment|/// SPUHazardRecognizer
name|class
name|SPUHazardRecognizer
range|:
name|public
name|ScheduleHazardRecognizer
block|{
name|private
operator|:
specifier|const
name|TargetInstrInfo
operator|&
name|TII
block|;
name|int
name|EvenOdd
block|;
name|public
operator|:
name|SPUHazardRecognizer
argument_list|(
specifier|const
name|TargetInstrInfo
operator|&
name|TII
argument_list|)
block|;
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
name|EmitNoop
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

end_unit

