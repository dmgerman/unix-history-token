begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadPlanStepInRange.h ---------------------------------*- C++ -*-===//
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
name|liblldb_ThreadPlanStepInRange_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadPlanStepInRange_h_
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
file|"lldb/Core/AddressRange.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/StackID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Thread.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ThreadPlanStepRange.h"
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
name|ThreadPlanStepInRange
range|:
name|public
name|ThreadPlanStepRange
decl_stmt|,
name|public
name|ThreadPlanShouldStopHere
block|{
name|public
label|:
name|ThreadPlanStepInRange
argument_list|(
argument|Thread&thread
argument_list|,
argument|const AddressRange&range
argument_list|,
argument|const SymbolContext&addr_context
argument_list|,
argument|lldb::RunMode stop_others
argument_list|)
empty_stmt|;
name|ThreadPlanStepInRange
argument_list|(
argument|Thread&thread
argument_list|,
argument|const AddressRange&range
argument_list|,
argument|const SymbolContext&addr_context
argument_list|,
argument|const char *step_into_function_name
argument_list|,
argument|lldb::RunMode stop_others
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|ThreadPlanStepInRange
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
name|ShouldStop
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
function_decl|;
name|void
name|SetAvoidRegexp
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|void
name|SetStepInTarget
parameter_list|(
specifier|const
name|char
modifier|*
name|target
parameter_list|)
block|{
name|m_step_into_target
operator|.
name|SetCString
argument_list|(
name|target
argument_list|)
expr_stmt|;
block|}
specifier|static
name|lldb
operator|::
name|ThreadPlanSP
name|DefaultShouldStopHereCallback
argument_list|(
name|ThreadPlan
operator|*
name|current_plan
argument_list|,
name|Flags
operator|&
name|flags
argument_list|,
name|void
operator|*
name|baton
argument_list|)
expr_stmt|;
specifier|static
name|void
name|SetDefaultFlagValue
parameter_list|(
name|uint32_t
name|new_value
parameter_list|)
function_decl|;
name|bool
name|IsVirtualStep
parameter_list|()
function_decl|;
name|protected
label|:
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
name|void
name|SetFlagsToDefault
parameter_list|()
function_decl|;
name|bool
name|FrameMatchesAvoidCriteria
parameter_list|()
function_decl|;
name|private
label|:
name|friend
name|lldb
operator|::
name|ThreadPlanSP
name|Thread
operator|::
name|QueueThreadPlanForStepOverRange
argument_list|(
argument|bool abort_other_plans
argument_list|,
argument|const AddressRange&range
argument_list|,
argument|const SymbolContext&addr_context
argument_list|,
argument|lldb::RunMode stop_others
argument_list|)
expr_stmt|;
name|friend
name|lldb
operator|::
name|ThreadPlanSP
name|Thread
operator|::
name|QueueThreadPlanForStepInRange
argument_list|(
argument|bool abort_other_plans
argument_list|,
argument|const AddressRange&range
argument_list|,
argument|const SymbolContext&addr_context
argument_list|,
argument|const char *step_in_target
argument_list|,
argument|lldb::RunMode stop_others
argument_list|,
argument|bool avoid_code_without_debug_info
argument_list|)
expr_stmt|;
comment|// Need an appropriate marker for the current stack so we can tell step out
comment|// from step in.
specifier|static
name|uint32_t
name|s_default_flag_values
decl_stmt|;
name|lldb
operator|::
name|ThreadPlanSP
name|m_sub_plan_sp
expr_stmt|;
comment|// Keep track of the last plan we were running.  If it fails, we should stop.
name|std
operator|::
name|unique_ptr
operator|<
name|RegularExpression
operator|>
name|m_avoid_regexp_ap
expr_stmt|;
name|bool
name|m_step_past_prologue
decl_stmt|;
comment|// FIXME: For now hard-coded to true, we could put a switch in for this if there's
comment|// demand for that.
name|bool
name|m_virtual_step
decl_stmt|;
comment|// true if we've just done a "virtual step", i.e. just moved the inline stack depth.
name|ConstString
name|m_step_into_target
decl_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadPlanStepInRange
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
comment|// liblldb_ThreadPlanStepInRange_h_
end_comment

end_unit

