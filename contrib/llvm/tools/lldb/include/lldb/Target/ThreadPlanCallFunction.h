begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadPlanCallFunction.h --------------------------------*- C++ -*-===//
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
name|liblldb_ThreadPlanCallFunction_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadPlanCallFunction_h_
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
file|"lldb/lldb-private.h"
end_include

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
name|ThreadPlanCallFunction
range|:
name|public
name|ThreadPlan
block|{
comment|// Create a thread plan to call a function at the address passed in the "function"
comment|// argument.  If you plan to call GetReturnValueObject, then pass in the
comment|// return type, otherwise just pass in an invalid ClangASTType.
name|public
operator|:
name|ThreadPlanCallFunction
argument_list|(
argument|Thread&thread
argument_list|,
argument|const Address&function
argument_list|,
argument|const ClangASTType&return_type
argument_list|,
argument|lldb::addr_t arg
argument_list|,
argument|bool stop_other_threads
argument_list|,
argument|bool unwind_on_error = true
argument_list|,
argument|bool ignore_breakpoints = false
argument_list|,
argument|lldb::addr_t *this_arg =
literal|0
argument_list|,
argument|lldb::addr_t *cmd_arg =
literal|0
argument_list|)
block|;
name|ThreadPlanCallFunction
argument_list|(
argument|Thread&thread
argument_list|,
argument|const Address&function
argument_list|,
argument|const ClangASTType&return_type
argument_list|,
argument|bool stop_other_threads
argument_list|,
argument|bool unwind_on_error
argument_list|,
argument|bool ignore_breakpoints
argument_list|,
argument|lldb::addr_t *arg1_ptr = NULL
argument_list|,
argument|lldb::addr_t *arg2_ptr = NULL
argument_list|,
argument|lldb::addr_t *arg3_ptr = NULL
argument_list|,
argument|lldb::addr_t *arg4_ptr = NULL
argument_list|,
argument|lldb::addr_t *arg5_ptr = NULL
argument_list|,
argument|lldb::addr_t *arg6_ptr = NULL
argument_list|)
block|;
name|virtual
operator|~
name|ThreadPlanCallFunction
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
name|Vote
name|ShouldReportStop
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
name|void
name|SetStopOthers
argument_list|(
argument|bool new_value
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|StateType
name|GetPlanRunState
argument_list|()
block|;
name|virtual
name|void
name|DidPush
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
comment|// To get the return value from a function call you must create a
comment|// lldb::ValueSP that contains a valid clang type in its context and call
comment|// RequestReturnValue. The ValueSP will be stored and when the function is
comment|// done executing, the object will check if there is a requested return
comment|// value. If there is, the return value will be retrieved using the
comment|// ABI::GetReturnValue() for the ABI in the process. Then after the thread
comment|// plan is complete, you can call "GetReturnValue()" to retrieve the value
comment|// that was extracted.
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
comment|// Return the stack pointer that the function received
comment|// on entry.  Any stack address below this should be
comment|// considered invalid after the function has been
comment|// cleaned up.
name|lldb
operator|::
name|addr_t
name|GetFunctionStackPointer
argument_list|()
block|{
return|return
name|m_function_sp
return|;
block|}
comment|// Classes that derive from ClangFunction, and implement
comment|// their own WillPop methods should call this so that the
comment|// thread state gets restored if the plan gets discarded.
name|virtual
name|void
name|WillPop
argument_list|()
block|;
comment|// If the thread plan stops mid-course, this will be the stop reason that interrupted us.
comment|// Once DoTakedown is called, this will be the real stop reason at the end of the function call.
comment|// If it hasn't been set for one or the other of these reasons, we'll return the PrivateStopReason.
comment|// This is needed because we want the CallFunction thread plans not to show up as the stop reason.
comment|// But if something bad goes wrong, it is nice to be able to tell the user what really happened.
name|virtual
name|lldb
operator|::
name|StopInfoSP
name|GetRealStopInfo
argument_list|()
block|{
if|if
condition|(
name|m_real_stop_info_sp
condition|)
return|return
name|m_real_stop_info_sp
return|;
else|else
return|return
name|GetPrivateStopInfo
argument_list|()
return|;
block|}
name|lldb
operator|::
name|addr_t
name|GetStopAddress
argument_list|()
block|{
return|return
name|m_stop_address
return|;
block|}
name|virtual
name|bool
name|RestoreThreadState
argument_list|()
block|;
name|virtual
name|void
name|ThreadDestroyed
argument_list|()
block|{
name|m_takedown_done
operator|=
name|true
block|;     }
name|protected
operator|:
name|void
name|ReportRegisterState
argument_list|(
specifier|const
name|char
operator|*
name|message
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
name|private
operator|:
name|bool
name|ConstructorSetup
argument_list|(
name|Thread
operator|&
name|thread
argument_list|,
name|ABI
operator|*
operator|&
name|abi
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|start_load_addr
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|function_load_addr
argument_list|)
block|;
name|void
name|DoTakedown
argument_list|(
argument|bool success
argument_list|)
block|;
name|void
name|SetBreakpoints
argument_list|()
block|;
name|void
name|ClearBreakpoints
argument_list|()
block|;
name|bool
name|BreakpointsExplainStop
argument_list|()
block|;
name|bool
name|m_valid
block|;
name|bool
name|m_stop_other_threads
block|;
name|Address
name|m_function_addr
block|;
name|Address
name|m_start_addr
block|;
name|lldb
operator|::
name|addr_t
name|m_function_sp
block|;
name|Thread
operator|::
name|RegisterCheckpoint
name|m_register_backup
block|;
name|lldb
operator|::
name|ThreadPlanSP
name|m_subplan_sp
block|;
name|LanguageRuntime
operator|*
name|m_cxx_language_runtime
block|;
name|LanguageRuntime
operator|*
name|m_objc_language_runtime
block|;
name|Thread
operator|::
name|ThreadStateCheckpoint
name|m_stored_thread_state
block|;
name|lldb
operator|::
name|StopInfoSP
name|m_real_stop_info_sp
block|;
comment|// In general we want to hide call function
comment|// thread plans, but for reporting purposes,
comment|// it's nice to know the real stop reason.
comment|// This gets set in DoTakedown.
name|StreamString
name|m_constructor_errors
block|;
name|ClangASTType
name|m_return_type
block|;
name|lldb
operator|::
name|ValueObjectSP
name|m_return_valobj_sp
block|;
comment|// If this contains a valid pointer, use the ABI to extract values when complete
name|bool
name|m_takedown_done
block|;
comment|// We want to ensure we only do the takedown once.  This ensures that.
name|lldb
operator|::
name|addr_t
name|m_stop_address
block|;
comment|// This is the address we stopped at.  Also set in DoTakedown;
name|bool
name|m_unwind_on_error
block|;
name|bool
name|m_ignore_breakpoints
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadPlanCallFunction
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
comment|// liblldb_ThreadPlanCallFunction_h_
end_comment

end_unit

