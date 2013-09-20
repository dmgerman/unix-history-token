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
comment|// method), call InvokeShouldStopHereCallback, and if that returns a non-NULL plan, execute that
comment|// plan instead of stopping.
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
name|eAvoidNoDebug
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|}
enum|;
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|ThreadPlanShouldStopHere
argument_list|(
argument|ThreadPlan *owner
argument_list|,
argument|ThreadPlanShouldStopHereCallback callback = NULL
argument_list|,
argument|void *baton = NULL
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|ThreadPlanShouldStopHere
argument_list|()
expr_stmt|;
name|void
name|SetShouldStopHereCallback
parameter_list|(
name|ThreadPlanShouldStopHereCallback
name|callback
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
name|lldb
operator|::
name|ThreadPlanSP
name|InvokeShouldStopHereCallback
argument_list|()
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
name|ThreadPlanShouldStopHereCallback
name|m_callback
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

