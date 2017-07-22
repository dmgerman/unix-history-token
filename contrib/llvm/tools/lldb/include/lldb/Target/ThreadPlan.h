begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadPlan.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_ThreadPlan_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadPlan_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/StopInfo.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Target.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Thread.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ThreadPlanTracer.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/UserID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//------------------------------------------------------------------
comment|//  ThreadPlan:
comment|//  This is the pure virtual base class for thread plans.
comment|//
comment|//  The thread plans provide the "atoms" of behavior that
comment|//  all the logical process control, either directly from commands or through
comment|//  more complex composite plans will rely on.
comment|//
comment|//  Plan Stack:
comment|//
comment|//  The thread maintaining a thread plan stack, and you program the actions of a
comment|//  particular thread
comment|//  by pushing plans onto the plan stack.
comment|//  There is always a "Current" plan, which is the top of the plan stack,
comment|//  though in some cases
comment|//  a plan may defer to plans higher in the stack for some piece of information
comment|//  (let us define that the plan stack grows downwards).
comment|//
comment|//  The plan stack is never empty, there is always a Base Plan which persists
comment|//  through the life
comment|//  of the running process.
comment|//
comment|//
comment|//  Creating Plans:
comment|//
comment|//  The thread plan is generally created and added to the plan stack through the
comment|//  QueueThreadPlanFor... API
comment|//  in lldb::Thread.  Those API's will return the plan that performs the named
comment|//  operation in a manner
comment|//  appropriate for the current process.  The plans in lldb/source/Target are
comment|//  generic
comment|//  implementations, but a Process plugin can override them.
comment|//
comment|//  ValidatePlan is then called.  If it returns false, the plan is unshipped.
comment|//  This is a little
comment|//  convenience which keeps us from having to error out of the constructor.
comment|//
comment|//  Then the plan is added to the plan stack.  When the plan is added to the
comment|//  plan stack its DidPush
comment|//  will get called.  This is useful if a plan wants to push any additional
comment|//  plans as it is constructed,
comment|//  since you need to make sure you're already on the stack before you push
comment|//  additional plans.
comment|//
comment|//  Completed Plans:
comment|//
comment|//  When the target process stops the plans are queried, among other things, for
comment|//  whether their job is done.
comment|//  If it is they are moved from the plan stack to the Completed Plan stack in
comment|//  reverse order from their position
comment|//  on the plan stack (since multiple plans may be done at a given stop.)  This
comment|//  is used primarily so that
comment|//  the lldb::Thread::StopInfo for the thread can be set properly.  If one plan
comment|//  pushes another to achieve part of
comment|//  its job, but it doesn't want that sub-plan to be the one that sets the
comment|//  StopInfo, then call SetPrivate on the
comment|//  sub-plan when you create it, and the Thread will pass over that plan in
comment|//  reporting the reason for the stop.
comment|//
comment|//  Discarded plans:
comment|//
comment|//  Your plan may also get discarded, i.e. moved from the plan stack to the
comment|//  "discarded plan stack".  This can
comment|//  happen, for instance, if the plan is calling a function and the function
comment|//  call crashes and you want
comment|//  to unwind the attempt to call.  So don't assume that your plan will always
comment|//  successfully stop.  Which leads to:
comment|//
comment|//  Cleaning up after your plans:
comment|//
comment|//  When the plan is moved from the plan stack its WillPop method is always
comment|//  called, no matter why.  Once it is
comment|//  moved off the plan stack it is done, and won't get a chance to run again.
comment|//  So you should
comment|//  undo anything that affects target state in this method.  But be sure to
comment|//  leave the plan able to correctly
comment|//  fill the StopInfo, however.
comment|//  N.B. Don't wait to do clean up target state till the destructor, since that
comment|//  will usually get called when
comment|//  the target resumes, and you want to leave the target state correct for new
comment|//  plans in the time between when
comment|//  your plan gets unshipped and the next resume.
comment|//
comment|//  Thread State Checkpoint:
comment|//
comment|//  Note that calling functions on target process (ThreadPlanCallFunction) changes
comment|//  current thread state. The function can be called either by direct user demand or
comment|//  internally, for example lldb allocates memory on device to calculate breakpoint
comment|//  condition expression - on Linux it is performed by calling mmap on device.
comment|//  ThreadStateCheckpoint saves Thread state (stop info and completed
comment|//  plan stack) to restore it after completing function call.
comment|//
comment|//  Over the lifetime of the plan, various methods of the ThreadPlan are then
comment|//  called in response to changes of state in
comment|//  the process we are debugging as follows:
comment|//
comment|//  Resuming:
comment|//
comment|//  When the target process is about to be restarted, the plan's WillResume
comment|//  method is called,
comment|//  giving the plan a chance to prepare for the run.  If WillResume returns
comment|//  false, then the
comment|//  process is not restarted.  Be sure to set an appropriate error value in the
comment|//  Process if
comment|//  you have to do this.  Note, ThreadPlans actually implement DoWillResume,
comment|//  WillResume wraps that call.
comment|//
comment|//  Next the "StopOthers" method of all the threads are polled, and if one
comment|//  thread's Current plan
comment|//  returns "true" then only that thread gets to run.  If more than one returns
comment|//  "true" the threads that want to run solo
comment|//  get run one by one round robin fashion.  Otherwise all are let to run.
comment|//
comment|//  Note, the way StopOthers is implemented, the base class implementation just
comment|//  asks the previous plan.  So if your plan
comment|//  has no opinion about whether it should run stopping others or not, just
comment|//  don't implement StopOthers, and the parent
comment|//  will be asked.
comment|//
comment|//  Finally, for each thread that is running, it run state is set to the return
comment|//  of RunState from the
comment|//  thread's Current plan.
comment|//
comment|//  Responding to a stop:
comment|//
comment|//  When the target process stops, the plan is called in the following stages:
comment|//
comment|//  First the thread asks the Current Plan if it can handle this stop by calling
comment|//  PlanExplainsStop.
comment|//  If the Current plan answers "true" then it is asked if the stop should
comment|//  percolate all the way to the
comment|//  user by calling the ShouldStop method.  If the current plan doesn't explain
comment|//  the stop, then we query up
comment|//  the plan stack for a plan that does explain the stop.  The plan that does
comment|//  explain the stop then needs to
comment|//  figure out what to do about the plans below it in the stack.  If the stop is
comment|//  recoverable, then the plan that
comment|//  understands it can just do what it needs to set up to restart, and then
comment|//  continue.
comment|//  Otherwise, the plan that understood the stop should call DiscardPlanStack to
comment|//  clean up the stack below it.
comment|//  Note, plans actually implement DoPlanExplainsStop, the result is cached in
comment|//  PlanExplainsStop so the DoPlanExplainsStop
comment|//  itself will only get called once per stop.
comment|//
comment|//  Master plans:
comment|//
comment|//  In the normal case, when we decide to stop, we will  collapse the plan stack
comment|//  up to the point of the plan that understood
comment|//  the stop reason.  However, if a plan wishes to stay on the stack after an
comment|//  event it didn't directly handle
comment|//  it can designate itself a "Master" plan by responding true to IsMasterPlan,
comment|//  and then if it wants not to be
comment|//  discarded, it can return false to OkayToDiscard, and it and all its dependent
comment|//  plans will be preserved when
comment|//  we resume execution.
comment|//
comment|//  The other effect of being a master plan is that when the Master plan is done
comment|//  , if it has set "OkayToDiscard" to false,
comment|//  then it will be popped& execution will stop and return to the user.
comment|//  Remember that if OkayToDiscard is false, the
comment|//  plan will be popped and control will be given to the next plan above it on
comment|//  the stack  So setting OkayToDiscard to
comment|//  false means the user will regain control when the MasterPlan is completed.
comment|//
comment|//  Between these two controls this allows things like: a MasterPlan/DontDiscard
comment|//  Step Over to hit a breakpoint, stop and
comment|//  return control to the user, but then when the user continues, the step out
comment|//  succeeds.
comment|//  Even more tricky, when the breakpoint is hit, the user can continue to step
comment|//  in/step over/etc, and finally when they
comment|//  continue, they will finish up the Step Over.
comment|//
comment|//  FIXME: MasterPlan& OkayToDiscard aren't really orthogonal.  MasterPlan
comment|//  designation means that this plan controls
comment|//  it's fate and the fate of plans below it.  OkayToDiscard tells whether the
comment|//  MasterPlan wants to stay on the stack.  I
comment|//  originally thought "MasterPlan-ness" would need to be a fixed characteristic
comment|//  of a ThreadPlan, in which case you needed
comment|//  the extra control.  But that doesn't seem to be true.  So we should be able
comment|//  to convert to only MasterPlan status to mean
comment|//  the current "MasterPlan/DontDiscard".  Then no plans would be MasterPlans by
comment|//  default, and you would set the ones you
comment|//  wanted to be "user level" in this way.
comment|//
comment|//
comment|//  Actually Stopping:
comment|//
comment|//  If a plan says responds "true" to ShouldStop, then it is asked if it's job
comment|//  is complete by calling
comment|//  MischiefManaged.  If that returns true, the plan is popped from the plan
comment|//  stack and added to the
comment|//  Completed Plan Stack.  Then the next plan in the stack is asked if it
comment|//  ShouldStop, and  it returns "true",
comment|//  it is asked if it is done, and if yes popped, and so on till we reach a plan
comment|//  that is not done.
comment|//
comment|//  Since you often know in the ShouldStop method whether your plan is complete,
comment|//  as a convenience you can call
comment|//  SetPlanComplete and the ThreadPlan implementation of MischiefManaged will
comment|//  return "true", without your having
comment|//  to redo the calculation when your sub-classes MischiefManaged is called.  If
comment|//  you call SetPlanComplete, you can
comment|//  later use IsPlanComplete to determine whether the plan is complete.  This is
comment|//  only a convenience for sub-classes,
comment|//  the logic in lldb::Thread will only call MischiefManaged.
comment|//
comment|//  One slightly tricky point is you have to be careful using SetPlanComplete in
comment|//  PlanExplainsStop because you
comment|//  are not guaranteed that PlanExplainsStop for a plan will get called before
comment|//  ShouldStop gets called.  If your sub-plan
comment|//  explained the stop and then popped itself, only your ShouldStop will get
comment|//  called.
comment|//
comment|//  If ShouldStop for any thread returns "true", then the WillStop method of the
comment|//  Current plan of
comment|//  all threads will be called, the stop event is placed on the Process's public
comment|//  broadcaster, and
comment|//  control returns to the upper layers of the debugger.
comment|//
comment|//  Reporting the stop:
comment|//
comment|//  When the process stops, the thread is given a StopReason, in the form of a
comment|//  StopInfo object.  If there is a completed
comment|//  plan corresponding to the stop, then the "actual" stop reason can be
comment|//  suppressed, and instead a StopInfoThreadPlan
comment|//  object will be cons'ed up from the top completed plan in the stack.
comment|//  However, if the plan doesn't want to be
comment|//  the stop reason, then it can call SetPlanComplete and pass in "false" for
comment|//  the "success" parameter.  In that case,
comment|//  the real stop reason will be used instead.  One exapmle of this is the
comment|//  "StepRangeStepIn" thread plan.  If it stops
comment|//  because of a crash or breakpoint hit, it wants to unship itself, because it
comment|//  isn't so useful to have step in keep going
comment|//  after a breakpoint hit.  But it can't be the reason for the stop or no-one
comment|//  would see that they had hit a breakpoint.
comment|//
comment|//  Cleaning up the plan stack:
comment|//
comment|//  One of the complications of MasterPlans is that you may get past the limits
comment|//  of a plan without triggering it to clean
comment|//  itself up.  For instance, if you are doing a MasterPlan StepOver, and hit a
comment|//  breakpoint in a called function, then
comment|//  step over enough times to step out of the initial StepOver range, each of
comment|//  the step overs will explain the stop&
comment|//  take themselves off the stack, but control would never be returned to the
comment|//  original StepOver.  Eventually, the user
comment|//  will continue, and when that continue stops, the old stale StepOver plan
comment|//  that was left on the stack will get woken
comment|//  up and notice it is done. But that can leave junk on the stack for a while.
comment|//  To avoid that, the plans implement a
comment|//  "IsPlanStale" method, that can check whether it is relevant anymore.  On
comment|//  stop, after the regular plan negotiation,
comment|//  the remaining plan stack is consulted and if any plan says it is stale, it
comment|//  and the plans below it are discarded from
comment|//  the stack.
comment|//
comment|//  Automatically Resuming:
comment|//
comment|//  If ShouldStop for all threads returns "false", then the target process will
comment|//  resume.  This then cycles back to
comment|//  Resuming above.
comment|//
comment|//  Reporting eStateStopped events when the target is restarted:
comment|//
comment|//  If a plan decides to auto-continue the target by returning "false" from
comment|//  ShouldStop, then it will be asked
comment|//  whether the Stopped event should still be reported.  For instance, if you
comment|//  hit a breakpoint that is a User set
comment|//  breakpoint, but the breakpoint callback said to continue the target process,
comment|//  you might still want to inform
comment|//  the upper layers of lldb that the stop had happened.
comment|//  The way this works is every thread gets to vote on whether to report the
comment|//  stop.  If all votes are eVoteNoOpinion,
comment|//  then the thread list will decide what to do (at present it will pretty much
comment|//  always suppress these stopped events.)
comment|//  If there is an eVoteYes, then the event will be reported regardless of the
comment|//  other votes.  If there is an eVoteNo
comment|//  and no eVoteYes's, then the event won't be reported.
comment|//
comment|//  One other little detail here, sometimes a plan will push another plan onto
comment|//  the plan stack to do some part of
comment|//  the first plan's job, and it would be convenient to tell that plan how it
comment|//  should respond to ShouldReportStop.
comment|//  You can do that by setting the stop_vote in the child plan when you create
comment|//  it.
comment|//
comment|//  Suppressing the initial eStateRunning event:
comment|//
comment|//  The private process running thread will take care of ensuring that only one
comment|//  "eStateRunning" event will be
comment|//  delivered to the public Process broadcaster per public eStateStopped event.
comment|//  However there are some cases
comment|//  where the public state of this process is eStateStopped, but a thread plan
comment|//  needs to restart the target, but
comment|//  doesn't want the running event to be publicly broadcast.  The obvious
comment|//  example of this is running functions
comment|//  by hand as part of expression evaluation.  To suppress the running event
comment|//  return eVoteNo from ShouldReportStop,
comment|//  to force a running event to be reported return eVoteYes, in general though
comment|//  you should return eVoteNoOpinion
comment|//  which will allow the ThreadList to figure out the right thing to do.
comment|//  The run_vote argument to the constructor works like stop_vote, and is a way
comment|//  for a plan to instruct a sub-plan
comment|//  on how to respond to ShouldReportStop.
comment|//
comment|//------------------------------------------------------------------
name|class
name|ThreadPlan
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|ThreadPlan
operator|>
decl_stmt|,
name|public
name|UserID
block|{
name|public
label|:
typedef|typedef
enum|enum
block|{
name|eAllThreads
block|,
name|eSomeThreads
block|,
name|eThisThread
block|}
name|ThreadScope
typedef|;
comment|// We use these enums so that we can cast a base thread plan to it's real type
comment|// without having to resort
comment|// to dynamic casting.
typedef|typedef
enum|enum
block|{
name|eKindGeneric
block|,
name|eKindNull
block|,
name|eKindBase
block|,
name|eKindCallFunction
block|,
name|eKindPython
block|,
name|eKindStepInstruction
block|,
name|eKindStepOut
block|,
name|eKindStepOverBreakpoint
block|,
name|eKindStepOverRange
block|,
name|eKindStepInRange
block|,
name|eKindRunToAddress
block|,
name|eKindStepThrough
block|,
name|eKindStepUntil
block|,
name|eKindTestCondition
block|}
name|ThreadPlanKind
typedef|;
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|ThreadPlan
argument_list|(
argument|ThreadPlanKind kind
argument_list|,
argument|const char *name
argument_list|,
argument|Thread&thread
argument_list|,
argument|Vote stop_vote
argument_list|,
argument|Vote run_vote
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|ThreadPlan
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns the name of this thread plan.
comment|///
comment|/// @return
comment|///   A const char * pointer to the thread plan's name.
comment|//------------------------------------------------------------------
specifier|const
name|char
operator|*
name|GetName
argument_list|()
specifier|const
block|{
return|return
name|m_name
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Returns the Thread that is using this thread plan.
comment|///
comment|/// @return
comment|///   A  pointer to the thread plan's owning thread.
comment|//------------------------------------------------------------------
name|Thread
modifier|&
name|GetThread
parameter_list|()
block|{
return|return
name|m_thread
return|;
block|}
specifier|const
name|Thread
operator|&
name|GetThread
argument_list|()
specifier|const
block|{
return|return
name|m_thread
return|;
block|}
name|Target
modifier|&
name|GetTarget
parameter_list|()
block|{
return|return
name|m_thread
operator|.
name|GetProcess
argument_list|()
operator|->
name|GetTarget
argument_list|()
return|;
block|}
specifier|const
name|Target
operator|&
name|GetTarget
argument_list|()
specifier|const
block|{
return|return
name|m_thread
operator|.
name|GetProcess
argument_list|()
operator|->
name|GetTarget
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Print a description of this thread to the stream \a s.
comment|/// \a thread.
comment|///
comment|/// @param[in] s
comment|///    The stream to which to print the description.
comment|///
comment|/// @param[in] level
comment|///    The level of description desired.  Note that eDescriptionLevelBrief
comment|///    will be used in the stop message printed when the plan is complete.
comment|//------------------------------------------------------------------
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
init|=
literal|0
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns whether this plan could be successfully created.
comment|///
comment|/// @param[in] error
comment|///    A stream to which to print some reason why the plan could not be
comment|///    created.
comment|///    Can be NULL.
comment|///
comment|/// @return
comment|///   \b true if the plan should be queued, \b false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|ValidatePlan
parameter_list|(
name|Stream
modifier|*
name|error
parameter_list|)
init|=
literal|0
function_decl|;
name|bool
name|TracerExplainsStop
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_tracer_sp
condition|)
return|return
name|false
return|;
else|else
return|return
name|m_tracer_sp
operator|->
name|TracerExplainsStop
argument_list|()
return|;
block|}
name|lldb
operator|::
name|StateType
name|RunState
argument_list|()
expr_stmt|;
name|bool
name|PlanExplainsStop
parameter_list|(
name|Event
modifier|*
name|event_ptr
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
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|ShouldAutoContinue
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|// Whether a "stop class" event should be reported to the "outside world".  In
comment|// general
comment|// if a thread plan is active, events should not be reported.
name|virtual
name|Vote
name|ShouldReportStop
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
function_decl|;
name|virtual
name|Vote
name|ShouldReportRun
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
function_decl|;
name|virtual
name|void
name|SetStopOthers
parameter_list|(
name|bool
name|new_value
parameter_list|)
function_decl|;
name|virtual
name|bool
name|StopOthers
parameter_list|()
function_decl|;
comment|// This is the wrapper for DoWillResume that does generic ThreadPlan logic,
comment|// then
comment|// calls DoWillResume.
name|bool
name|WillResume
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
name|WillStop
parameter_list|()
init|=
literal|0
function_decl|;
name|bool
name|IsMasterPlan
parameter_list|()
block|{
return|return
name|m_is_master_plan
return|;
block|}
name|bool
name|SetIsMasterPlan
parameter_list|(
name|bool
name|value
parameter_list|)
block|{
name|bool
name|old_value
init|=
name|m_is_master_plan
decl_stmt|;
name|m_is_master_plan
operator|=
name|value
expr_stmt|;
return|return
name|old_value
return|;
block|}
name|virtual
name|bool
name|OkayToDiscard
parameter_list|()
function_decl|;
name|void
name|SetOkayToDiscard
parameter_list|(
name|bool
name|value
parameter_list|)
block|{
name|m_okay_to_discard
operator|=
name|value
expr_stmt|;
block|}
comment|// The base class MischiefManaged does some cleanup - so you have to call it
comment|// in your MischiefManaged derived class.
name|virtual
name|bool
name|MischiefManaged
parameter_list|()
function_decl|;
name|virtual
name|void
name|ThreadDestroyed
parameter_list|()
block|{
comment|// Any cleanup that a plan might want to do in case the thread goes away
comment|// in the middle of the plan being queued on a thread can be done here.
block|}
name|bool
name|GetPrivate
parameter_list|()
block|{
return|return
name|m_plan_private
return|;
block|}
name|void
name|SetPrivate
parameter_list|(
name|bool
name|input
parameter_list|)
block|{
name|m_plan_private
operator|=
name|input
expr_stmt|;
block|}
name|virtual
name|void
name|DidPush
parameter_list|()
function_decl|;
name|virtual
name|void
name|WillPop
parameter_list|()
function_decl|;
comment|// This pushes a plan onto the plan stack of the current plan's thread.
name|void
name|PushPlan
argument_list|(
name|lldb
operator|::
name|ThreadPlanSP
operator|&
name|thread_plan_sp
argument_list|)
block|{
name|m_thread
operator|.
name|PushPlan
argument_list|(
name|thread_plan_sp
argument_list|)
expr_stmt|;
block|}
name|ThreadPlanKind
name|GetKind
argument_list|()
specifier|const
block|{
return|return
name|m_kind
return|;
block|}
name|bool
name|IsPlanComplete
parameter_list|()
function_decl|;
name|void
name|SetPlanComplete
parameter_list|(
name|bool
name|success
init|=
name|true
parameter_list|)
function_decl|;
name|virtual
name|bool
name|IsPlanStale
parameter_list|()
block|{
return|return
name|false
return|;
block|}
name|bool
name|PlanSucceeded
parameter_list|()
block|{
return|return
name|m_plan_succeeded
return|;
block|}
name|virtual
name|bool
name|IsBasePlan
parameter_list|()
block|{
return|return
name|false
return|;
block|}
name|lldb
operator|::
name|ThreadPlanTracerSP
operator|&
name|GetThreadPlanTracer
argument_list|()
block|{
return|return
name|m_tracer_sp
return|;
block|}
name|void
name|SetThreadPlanTracer
argument_list|(
name|lldb
operator|::
name|ThreadPlanTracerSP
name|new_tracer_sp
argument_list|)
block|{
name|m_tracer_sp
operator|=
name|new_tracer_sp
expr_stmt|;
block|}
name|void
name|DoTraceLog
parameter_list|()
block|{
if|if
condition|(
name|m_tracer_sp
operator|&&
name|m_tracer_sp
operator|->
name|TracingEnabled
argument_list|()
condition|)
name|m_tracer_sp
operator|->
name|Log
argument_list|()
expr_stmt|;
block|}
comment|// Some thread plans hide away the actual stop info which caused any
comment|// particular stop.  For
comment|// instance the ThreadPlanCallFunction restores the original stop reason so
comment|// that stopping and
comment|// calling a few functions won't lose the history of the run.
comment|// This call can be implemented to get you back to the real stop info.
name|virtual
name|lldb
operator|::
name|StopInfoSP
name|GetRealStopInfo
argument_list|()
block|{
return|return
name|m_thread
operator|.
name|GetStopInfo
argument_list|()
return|;
block|}
comment|// If the completion of the thread plan stepped out of a function, the return
comment|// value of the function
comment|// might have been captured by the thread plan (currently only
comment|// ThreadPlanStepOut does this.)
comment|// If so, the ReturnValueObject can be retrieved from here.
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|GetReturnValueObject
argument_list|()
block|{
return|return
name|lldb
operator|::
name|ValueObjectSP
argument_list|()
return|;
block|}
comment|// If the thread plan managing the evaluation of a user expression lives
comment|// longer than the command
comment|// that instigated the expression (generally because the expression evaluation
comment|// hit a breakpoint, and
comment|// the user regained control at that point) a subsequent process control
comment|// command step/continue/etc. might
comment|// complete the expression evaluations.  If so, the result of the expression
comment|// evaluation will show up here.
name|virtual
name|lldb
operator|::
name|ExpressionVariableSP
name|GetExpressionVariable
argument_list|()
block|{
return|return
name|lldb
operator|::
name|ExpressionVariableSP
argument_list|()
return|;
block|}
comment|// If a thread plan stores the state before it was run, then you might
comment|// want to restore the state when it is done.  This will do that job.
comment|// This is mostly useful for artificial plans like CallFunction plans.
name|virtual
name|bool
name|RestoreThreadState
parameter_list|()
block|{
comment|// Nothing to do in general.
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|IsVirtualStep
parameter_list|()
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|SetIterationCount
parameter_list|(
name|size_t
name|count
parameter_list|)
block|{
if|if
condition|(
name|m_takes_iteration_count
condition|)
block|{
comment|// Don't tell me to do something 0 times...
if|if
condition|(
name|count
operator|==
literal|0
condition|)
return|return
name|false
return|;
name|m_iteration_count
operator|=
name|count
expr_stmt|;
block|}
return|return
name|m_takes_iteration_count
return|;
block|}
name|virtual
name|size_t
name|GetIterationCount
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_takes_iteration_count
condition|)
return|return
literal|0
return|;
else|else
return|return
name|m_iteration_count
return|;
block|}
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from ThreadPlan can see and modify these
comment|//------------------------------------------------------------------
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
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|DoPlanExplainsStop
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
init|=
literal|0
function_decl|;
comment|// This gets the previous plan to the current plan (for forwarding requests).
comment|// This is mostly a formal requirement, it allows us to make the Thread's
comment|// GetPreviousPlan protected, but only friend ThreadPlan to thread.
name|ThreadPlan
modifier|*
name|GetPreviousPlan
parameter_list|()
block|{
return|return
name|m_thread
operator|.
name|GetPreviousPlan
argument_list|(
name|this
argument_list|)
return|;
block|}
comment|// This forwards the private Thread::GetPrivateStopInfo which is generally
comment|// what
comment|// ThreadPlan's need to know.
name|lldb
operator|::
name|StopInfoSP
name|GetPrivateStopInfo
argument_list|()
block|{
return|return
name|m_thread
operator|.
name|GetPrivateStopInfo
argument_list|()
return|;
block|}
name|void
name|SetStopInfo
argument_list|(
name|lldb
operator|::
name|StopInfoSP
name|stop_reason_sp
argument_list|)
block|{
name|m_thread
operator|.
name|SetStopInfo
argument_list|(
name|stop_reason_sp
argument_list|)
expr_stmt|;
block|}
name|void
name|CachePlanExplainsStop
parameter_list|(
name|bool
name|does_explain
parameter_list|)
block|{
name|m_cached_plan_explains_stop
operator|=
name|does_explain
condition|?
name|eLazyBoolYes
else|:
name|eLazyBoolNo
expr_stmt|;
block|}
name|LazyBool
name|GetCachedPlanExplainsStop
argument_list|()
specifier|const
block|{
return|return
name|m_cached_plan_explains_stop
return|;
block|}
name|virtual
name|lldb
operator|::
name|StateType
name|GetPlanRunState
argument_list|()
operator|=
literal|0
expr_stmt|;
name|bool
name|IsUsuallyUnexplainedStopReason
argument_list|(
name|lldb
operator|::
name|StopReason
argument_list|)
decl_stmt|;
name|Thread
modifier|&
name|m_thread
decl_stmt|;
name|Vote
name|m_stop_vote
decl_stmt|;
name|Vote
name|m_run_vote
decl_stmt|;
name|bool
name|m_takes_iteration_count
init|=
name|false
decl_stmt|;
name|int32_t
name|m_iteration_count
init|=
literal|1
decl_stmt|;
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For ThreadPlan only
comment|//------------------------------------------------------------------
specifier|static
name|lldb
operator|::
name|user_id_t
name|GetNextID
argument_list|()
expr_stmt|;
name|ThreadPlanKind
name|m_kind
decl_stmt|;
name|std
operator|::
name|string
name|m_name
expr_stmt|;
name|std
operator|::
name|recursive_mutex
name|m_plan_complete_mutex
expr_stmt|;
name|LazyBool
name|m_cached_plan_explains_stop
decl_stmt|;
name|bool
name|m_plan_complete
decl_stmt|;
name|bool
name|m_plan_private
decl_stmt|;
name|bool
name|m_okay_to_discard
decl_stmt|;
name|bool
name|m_is_master_plan
decl_stmt|;
name|bool
name|m_plan_succeeded
decl_stmt|;
name|lldb
operator|::
name|ThreadPlanTracerSP
name|m_tracer_sp
expr_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadPlan
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|// ThreadPlanNull:
comment|// Threads are assumed to always have at least one plan on the plan stack.
comment|// This is put on the plan stack when a thread is destroyed so that if you
comment|// accidentally access a thread after it is destroyed you won't crash.
comment|// But asking questions of the ThreadPlanNull is definitely an error.
comment|//----------------------------------------------------------------------
name|class
name|ThreadPlanNull
range|:
name|public
name|ThreadPlan
block|{
name|public
operator|:
name|ThreadPlanNull
argument_list|(
name|Thread
operator|&
name|thread
argument_list|)
block|;
operator|~
name|ThreadPlanNull
argument_list|()
name|override
block|;
name|void
name|GetDescription
argument_list|(
argument|Stream *s
argument_list|,
argument|lldb::DescriptionLevel level
argument_list|)
name|override
block|;
name|bool
name|ValidatePlan
argument_list|(
argument|Stream *error
argument_list|)
name|override
block|;
name|bool
name|ShouldStop
argument_list|(
argument|Event *event_ptr
argument_list|)
name|override
block|;
name|bool
name|MischiefManaged
argument_list|()
name|override
block|;
name|bool
name|WillStop
argument_list|()
name|override
block|;
name|bool
name|IsBasePlan
argument_list|()
name|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|OkayToDiscard
argument_list|()
name|override
block|{
return|return
name|false
return|;
block|}
name|protected
operator|:
name|bool
name|DoPlanExplainsStop
argument_list|(
argument|Event *event_ptr
argument_list|)
name|override
block|;
name|lldb
operator|::
name|StateType
name|GetPlanRunState
argument_list|()
name|override
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadPlanNull
argument_list|)
block|; }
decl_stmt|;
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
comment|// liblldb_ThreadPlan_h_
end_comment

end_unit

