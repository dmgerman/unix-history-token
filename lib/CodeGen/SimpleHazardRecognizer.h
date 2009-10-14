begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- llvm/CodeGen/SimpleHazardRecognizer.h - Scheduling Support -*- C++ -*-=//
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
comment|// This file implements the SimpleHazardRecognizer class, which
end_comment

begin_comment
comment|// implements hazard-avoidance heuristics for scheduling, based on the
end_comment

begin_comment
comment|// scheduling itineraries specified for the target.
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
name|LLVM_CODEGEN_SIMPLEHAZARDRECOGNIZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SIMPLEHAZARDRECOGNIZER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleHazardRecognizer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// SimpleHazardRecognizer - A *very* simple hazard recognizer. It uses
comment|/// a coarse classification and attempts to avoid that instructions of
comment|/// a given class aren't grouped too densely together.
name|class
name|SimpleHazardRecognizer
range|:
name|public
name|ScheduleHazardRecognizer
block|{
comment|/// Class - A simple classification for SUnits.
block|enum
name|Class
block|{
name|Other
block|,
name|Load
block|,
name|Store
block|}
block|;
comment|/// Window - The Class values of the most recently issued
comment|/// instructions.
name|Class
name|Window
index|[
literal|8
index|]
block|;
comment|/// getClass - Classify the given SUnit.
name|Class
name|getClass
argument_list|(
argument|const SUnit *SU
argument_list|)
block|{
specifier|const
name|MachineInstr
operator|*
name|MI
operator|=
name|SU
operator|->
name|getInstr
argument_list|()
block|;
specifier|const
name|TargetInstrDesc
operator|&
name|TID
operator|=
name|MI
operator|->
name|getDesc
argument_list|()
block|;
if|if
condition|(
name|TID
operator|.
name|mayLoad
argument_list|()
condition|)
return|return
name|Load
return|;
if|if
condition|(
name|TID
operator|.
name|mayStore
argument_list|()
condition|)
return|return
name|Store
return|;
return|return
name|Other
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Step - Rotate the existing entries in Window and insert the
end_comment

begin_comment
comment|/// given class value in position as the most recent.
end_comment

begin_function
name|void
name|Step
parameter_list|(
name|Class
name|C
parameter_list|)
block|{
name|std
operator|::
name|copy
argument_list|(
name|Window
operator|+
literal|1
argument_list|,
name|array_endof
argument_list|(
name|Window
argument_list|)
argument_list|,
name|Window
argument_list|)
expr_stmt|;
name|Window
index|[
name|array_lengthof
argument_list|(
name|Window
argument_list|)
operator|-
literal|1
index|]
operator|=
name|C
expr_stmt|;
block|}
end_function

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|SimpleHazardRecognizer
argument_list|()
operator|:
name|Window
argument_list|()
block|{
name|Reset
argument_list|()
block|;     }
name|virtual
name|HazardType
name|getHazardType
argument_list|(
argument|SUnit *SU
argument_list|)
block|{
name|Class
name|C
operator|=
name|getClass
argument_list|(
name|SU
argument_list|)
block|;
if|if
condition|(
name|C
operator|==
name|Other
condition|)
return|return
name|NoHazard
return|;
name|unsigned
name|Score
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|array_lengthof
argument_list|(
name|Window
argument_list|)
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|Window
index|[
name|i
index|]
operator|==
name|C
condition|)
name|Score
operator|+=
name|i
operator|+
literal|1
expr_stmt|;
end_for

begin_if
if|if
condition|(
name|Score
operator|>
name|array_lengthof
argument_list|(
name|Window
argument_list|)
operator|*
literal|2
condition|)
return|return
name|Hazard
return|;
end_if

begin_return
return|return
name|NoHazard
return|;
end_return

begin_function
unit|}      virtual
name|void
name|Reset
parameter_list|()
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|array_lengthof
argument_list|(
name|Window
argument_list|)
condition|;
operator|++
name|i
control|)
name|Window
index|[
name|i
index|]
operator|=
name|Other
expr_stmt|;
block|}
end_function

begin_function
name|virtual
name|void
name|EmitInstruction
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
block|{
name|Step
argument_list|(
name|getClass
argument_list|(
name|SU
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|virtual
name|void
name|AdvanceCycle
parameter_list|()
block|{
name|Step
argument_list|(
name|Other
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
unit|}; }
endif|#
directive|endif
end_endif

end_unit

