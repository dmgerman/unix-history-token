begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadPlanShouldStopHere.h ------------------------------*- C++ -*-===//
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
name|liblldb_ThreadPlanShouldStopHere_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadPlanShouldStopHere_h_
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
file|"lldb/Target/ThreadPlan.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|// This is an interface that ThreadPlans can adopt to allow flexible modifications of the behavior
comment|// when a thread plan comes to a place where it would ordinarily stop.  If such modification makes
comment|// sense for your plan, inherit from this class, and when you would be about to stop (in your ShouldStop
comment|// method), call InvokeShouldStopHereCallback, passing in the frame comparison between where the step operation
comment|// started and where you arrived.  If it returns true, then QueueStepOutFromHere will queue the plan
comment|// to execute instead of stopping.
comment|//
comment|// The classic example of the use of this is ThreadPlanStepInRange not stopping in frames that have
comment|// no debug information.
comment|//
comment|// This class also defines a set of flags to control general aspects of this "ShouldStop" behavior.
comment|// A class implementing this protocol needs to define a default set of flags, and can provide access to
comment|// changing that default flag set if it wishes.
name|class
name|ThreadPlanShouldStopHere
block|{
name|public
label|:
struct|struct
name|ThreadPlanShouldStopHereCallbacks
block|{
name|ThreadPlanShouldStopHereCallbacks
argument_list|()
block|{
name|should_stop_here_callback
operator|=
name|nullptr
expr_stmt|;
name|step_from_here_callback
operator|=
name|nullptr
expr_stmt|;
block|}
name|ThreadPlanShouldStopHereCallbacks
argument_list|(
argument|ThreadPlanShouldStopHereCallback should_stop
argument_list|,
argument|ThreadPlanStepFromHereCallback step_from_here
argument_list|)
block|{
name|should_stop_here_callback
operator|=
name|should_stop
expr_stmt|;
name|step_from_here_callback
operator|=
name|step_from_here
expr_stmt|;
block|}
name|void
name|Clear
parameter_list|()
block|{
name|should_stop_here_callback
operator|=
name|nullptr
expr_stmt|;
name|step_from_here_callback
operator|=
name|nullptr
expr_stmt|;
block|}
name|ThreadPlanShouldStopHereCallback
name|should_stop_here_callback
decl_stmt|;
name|ThreadPlanStepFromHereCallback
name|step_from_here_callback
decl_stmt|;
block|}
struct|;
enum|enum
block|{
name|eNone
init|=
literal|0
block|,
name|eAvoidInlines
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|eStepInAvoidNoDebug
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|eStepOutAvoidNoDebug
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|}
enum|;
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|ThreadPlanShouldStopHere
argument_list|(
name|ThreadPlan
operator|*
name|owner
argument_list|)
expr_stmt|;
name|ThreadPlanShouldStopHere
argument_list|(
name|ThreadPlan
operator|*
name|owner
argument_list|,
specifier|const
name|ThreadPlanShouldStopHereCallbacks
operator|*
name|callbacks
argument_list|,
name|void
operator|*
name|baton
operator|=
name|NULL
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|ThreadPlanShouldStopHere
argument_list|()
expr_stmt|;
comment|// Set the ShouldStopHere callbacks.  Pass in null to clear them and have no special behavior (though you
comment|// can also call ClearShouldStopHereCallbacks for that purpose.  If you pass in a valid pointer, it will
comment|// adopt the non-null fields, and any null fields will be set to the default values.
name|void
name|SetShouldStopHereCallbacks
parameter_list|(
specifier|const
name|ThreadPlanShouldStopHereCallbacks
modifier|*
name|callbacks
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
block|{
if|if
condition|(
name|callbacks
condition|)
block|{
name|m_callbacks
operator|=
operator|*
name|callbacks
expr_stmt|;
if|if
condition|(
operator|!
name|m_callbacks
operator|.
name|should_stop_here_callback
condition|)
name|m_callbacks
operator|.
name|should_stop_here_callback
operator|=
name|ThreadPlanShouldStopHere
operator|::
name|DefaultShouldStopHereCallback
expr_stmt|;
if|if
condition|(
operator|!
name|m_callbacks
operator|.
name|step_from_here_callback
condition|)
name|m_callbacks
operator|.
name|step_from_here_callback
operator|=
name|ThreadPlanShouldStopHere
operator|::
name|DefaultStepFromHereCallback
expr_stmt|;
block|}
else|else
block|{
name|ClearShouldStopHereCallbacks
argument_list|()
expr_stmt|;
block|}
name|m_baton
operator|=
name|baton
expr_stmt|;
block|}
name|void
name|ClearShouldStopHereCallbacks
parameter_list|()
block|{
name|m_callbacks
operator|.
name|Clear
argument_list|()
expr_stmt|;
block|}
name|bool
name|InvokeShouldStopHereCallback
argument_list|(
name|lldb
operator|::
name|FrameComparison
name|operation
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|ThreadPlanSP
name|CheckShouldStopHereAndQueueStepOut
argument_list|(
argument|lldb::FrameComparison operation
argument_list|)
expr_stmt|;
name|lldb_private
operator|::
name|Flags
operator|&
name|GetFlags
argument_list|()
block|{
return|return
name|m_flags
return|;
block|}
specifier|const
name|lldb_private
operator|::
name|Flags
operator|&
name|GetFlags
argument_list|()
specifier|const
block|{
return|return
name|m_flags
return|;
block|}
name|protected
label|:
specifier|static
name|bool
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
name|lldb
operator|::
name|FrameComparison
name|operation
argument_list|,
name|void
operator|*
name|baton
argument_list|)
decl_stmt|;
specifier|static
name|lldb
operator|::
name|ThreadPlanSP
name|DefaultStepFromHereCallback
argument_list|(
argument|ThreadPlan *current_plan
argument_list|,
argument|Flags&flags
argument_list|,
argument|lldb::FrameComparison operation
argument_list|,
argument|void *baton
argument_list|)
expr_stmt|;
name|virtual
name|lldb
operator|::
name|ThreadPlanSP
name|QueueStepOutFromHerePlan
argument_list|(
argument|Flags&flags
argument_list|,
argument|lldb::FrameComparison operation
argument_list|)
expr_stmt|;
comment|// Implement this, and call it in the plan's constructor to set the default flags.
name|virtual
name|void
name|SetFlagsToDefault
parameter_list|()
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|// Classes that inherit from ThreadPlanShouldStopHere can see and modify these
comment|//------------------------------------------------------------------
name|ThreadPlanShouldStopHereCallbacks
name|m_callbacks
decl_stmt|;
name|void
modifier|*
name|m_baton
decl_stmt|;
name|ThreadPlan
modifier|*
name|m_owner
decl_stmt|;
name|lldb_private
operator|::
name|Flags
name|m_flags
expr_stmt|;
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For ThreadPlanShouldStopHere only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadPlanShouldStopHere
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
comment|// liblldb_ThreadPlanShouldStopHere_h_
end_comment

end_unit

