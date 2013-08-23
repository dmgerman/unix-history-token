begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadPlanStepUntil.h -----------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_ThreadPlanStepUntil_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadPlanStepUntil_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Target/Thread.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ThreadPlan.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ThreadPlanStepUntil
range|:
name|public
name|ThreadPlan
block|{
name|public
operator|:
name|virtual
operator|~
name|ThreadPlanStepUntil
argument_list|()
block|;
name|virtual
name|void
name|GetDescription
argument_list|(
argument|Stream *s
argument_list|,
argument|lldb::DescriptionLevel level
argument_list|)
block|;
name|virtual
name|bool
name|ValidatePlan
argument_list|(
name|Stream
operator|*
name|error
argument_list|)
block|;
name|virtual
name|bool
name|ShouldStop
argument_list|(
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
name|virtual
name|bool
name|StopOthers
argument_list|()
block|;
name|virtual
name|lldb
operator|::
name|StateType
name|GetPlanRunState
argument_list|()
block|;
name|virtual
name|bool
name|WillStop
argument_list|()
block|;
name|virtual
name|bool
name|MischiefManaged
argument_list|()
block|;
name|protected
operator|:
name|virtual
name|bool
name|DoWillResume
argument_list|(
argument|lldb::StateType resume_state
argument_list|,
argument|bool current_plan
argument_list|)
block|;
name|virtual
name|bool
name|DoPlanExplainsStop
argument_list|(
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
name|ThreadPlanStepUntil
argument_list|(
argument|Thread&thread
argument_list|,
argument|lldb::addr_t *address_list
argument_list|,
argument|size_t num_addresses
argument_list|,
argument|bool stop_others
argument_list|,
argument|uint32_t frame_idx =
literal|0
argument_list|)
block|;
name|void
name|AnalyzeStop
argument_list|(
name|void
argument_list|)
block|;
name|private
operator|:
name|StackID
name|m_stack_id
block|;
name|lldb
operator|::
name|addr_t
name|m_step_from_insn
block|;
name|lldb
operator|::
name|break_id_t
name|m_return_bp_id
block|;
name|lldb
operator|::
name|addr_t
name|m_return_addr
block|;
name|bool
name|m_stepped_out
block|;
name|bool
name|m_should_stop
block|;
name|bool
name|m_ran_analyze
block|;
name|bool
name|m_explains_stop
block|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|lldb
operator|::
name|break_id_t
operator|>
name|until_collection
expr_stmt|;
name|until_collection
name|m_until_points
decl_stmt|;
name|bool
name|m_stop_others
decl_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|friend
name|lldb
operator|::
name|ThreadPlanSP
name|Thread
operator|::
name|QueueThreadPlanForStepUntil
argument_list|(
argument|bool abort_other_plans
argument_list|,
argument|lldb::addr_t *address_list
argument_list|,
argument|size_t num_addresses
argument_list|,
argument|bool stop_others
argument_list|,
argument|uint32_t frame_idx
argument_list|)
expr_stmt|;
comment|// Need an appropriate marker for the current stack so we can tell step out
comment|// from step in.
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadPlanStepUntil
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ThreadPlanStepUntil_h_
end_comment

end_unit

