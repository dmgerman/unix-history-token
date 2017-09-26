begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ScheduleDAGMutation.h - MachineInstr Scheduling ----------*- C++ -*-===//
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
comment|// This file implements the ScheduleDAGMutation class, which represents
end_comment

begin_comment
comment|// a target-specific mutation of the dependency graph for scheduling.
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
name|LLVM_CODEGEN_SCHEDULEDAGMUTATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SCHEDULEDAGMUTATION_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ScheduleDAGInstrs
decl_stmt|;
comment|/// Mutate the DAG as a postpass after normal DAG building.
name|class
name|ScheduleDAGMutation
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
name|virtual
operator|~
name|ScheduleDAGMutation
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
name|void
name|apply
parameter_list|(
name|ScheduleDAGInstrs
modifier|*
name|DAG
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
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
comment|// LLVM_CODEGEN_SCHEDULEDAGMUTATION_H
end_comment

end_unit

