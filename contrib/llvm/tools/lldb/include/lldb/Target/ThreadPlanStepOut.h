begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadPlanStepOut.h -------------------------------------*- C++ -*-===//
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
name|liblldb_ThreadPlanStepOut_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadPlanStepOut_h_
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

begin_include
include|#
directive|include
file|"lldb/Target/ThreadPlanShouldStopHere.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ThreadPlanStepOut
range|:
name|public
name|ThreadPlan
decl_stmt|,
name|public
name|ThreadPlanShouldStopHere
block|{
name|public
label|:
name|ThreadPlanStepOut
argument_list|(
argument|Thread&thread
argument_list|,
argument|SymbolContext *addr_context
argument_list|,
argument|bool first_insn
argument_list|,
argument|bool stop_others
argument_list|,
argument|Vote stop_vote
argument_list|,
argument|Vote run_vote
argument_list|,
argument|uint32_t frame_idx
argument_list|,
argument|LazyBool step_out_avoids_code_without_debug_info
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|ThreadPlanStepOut
argument_list|()
expr_stmt|;
name|virtual
name|void
name|GetDescription
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|level
argument_list|)
decl_stmt|;
name|virtual
name|bool
name|ValidatePlan
parameter_list|(
name|Stream
modifier|*
name|error
parameter_list|)
function_decl|;
name|virtual
name|bool
name|ShouldStop
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
function_decl|;
name|virtual
name|bool
name|StopOthers
parameter_list|()
function_decl|;
name|virtual
name|lldb
operator|::
name|StateType
name|GetPlanRunState
argument_list|()
expr_stmt|;
name|virtual
name|bool
name|WillStop
parameter_list|()
function_decl|;
name|virtual
name|bool
name|MischiefManaged
parameter_list|()
function_decl|;
name|virtual
name|void
name|DidPush
parameter_list|()
function_decl|;
name|virtual
name|bool
name|IsPlanStale
parameter_list|()
function_decl|;
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|GetReturnValueObject
argument_list|()
block|{
return|return
name|m_return_valobj_sp
return|;
block|}
name|protected
label|:
name|virtual
name|void
name|SetFlagsToDefault
parameter_list|()
block|{
name|GetFlags
argument_list|()
operator|.
name|Set
argument_list|(
name|ThreadPlanStepOut
operator|::
name|s_default_flag_values
argument_list|)
expr_stmt|;
block|}
name|virtual
name|bool
name|DoPlanExplainsStop
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
function_decl|;
name|virtual
name|bool
name|DoWillResume
argument_list|(
name|lldb
operator|::
name|StateType
name|resume_state
argument_list|,
name|bool
name|current_plan
argument_list|)
decl_stmt|;
name|bool
name|QueueInlinedStepPlan
parameter_list|(
name|bool
name|queue_now
parameter_list|)
function_decl|;
name|private
label|:
specifier|static
name|uint32_t
name|s_default_flag_values
decl_stmt|;
comment|// These are the default flag values for the ThreadPlanStepThrough.
name|lldb
operator|::
name|addr_t
name|m_step_from_insn
expr_stmt|;
name|StackID
name|m_step_out_to_id
decl_stmt|;
name|StackID
name|m_immediate_step_from_id
decl_stmt|;
name|lldb
operator|::
name|break_id_t
name|m_return_bp_id
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|m_return_addr
expr_stmt|;
name|bool
name|m_stop_others
decl_stmt|;
name|lldb
operator|::
name|ThreadPlanSP
name|m_step_out_to_inline_plan_sp
expr_stmt|;
comment|// This plan implements step out to the real function containing
comment|// an inlined frame so we can then step out of that.
name|lldb
operator|::
name|ThreadPlanSP
name|m_step_through_inline_plan_sp
expr_stmt|;
comment|// This plan then steps past the inlined frame(s).
name|lldb
operator|::
name|ThreadPlanSP
name|m_step_out_further_plan_sp
expr_stmt|;
comment|// This plan keeps stepping out if ShouldStopHere told us to.
name|Function
modifier|*
name|m_immediate_step_from_function
decl_stmt|;
name|lldb
operator|::
name|ValueObjectSP
name|m_return_valobj_sp
expr_stmt|;
name|friend
name|lldb
operator|::
name|ThreadPlanSP
name|Thread
operator|::
name|QueueThreadPlanForStepOut
argument_list|(
argument|bool abort_other_plans
argument_list|,
argument|SymbolContext *addr_context
argument_list|,
argument|bool first_insn
argument_list|,
argument|bool stop_others
argument_list|,
argument|Vote stop_vote
argument_list|,
argument|Vote run_vote
argument_list|,
argument|uint32_t frame_idx
argument_list|,
argument|LazyBool step_out_avoids_code_without_debug_info
argument_list|)
expr_stmt|;
name|void
name|SetupAvoidNoDebug
parameter_list|(
name|LazyBool
name|step_out_avoids_code_without_debug_info
parameter_list|)
function_decl|;
comment|// Need an appropriate marker for the current stack so we can tell step out
comment|// from step in.
name|void
name|CalculateReturnValue
parameter_list|()
function_decl|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadPlanStepOut
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ThreadPlanStepOut_h_
end_comment

end_unit

