begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AppleThreadPlanStepThroughObjCTrampoline.h --------------*- C++ -*-===//
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
name|lldb_AppleThreadPlanStepThroughObjCTrampoline_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_AppleThreadPlanStepThroughObjCTrampoline_h_
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
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Value.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ThreadPlan.h"
end_include

begin_include
include|#
directive|include
file|"AppleObjCTrampolineHandler.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|AppleThreadPlanStepThroughObjCTrampoline
range|:
name|public
name|ThreadPlan
block|{
name|public
operator|:
name|AppleThreadPlanStepThroughObjCTrampoline
argument_list|(
argument|Thread&thread
argument_list|,
argument|AppleObjCTrampolineHandler *trampoline_handler
argument_list|,
argument|ValueList&values
argument_list|,
argument|lldb::addr_t isa_addr
argument_list|,
argument|lldb::addr_t sel_addr
argument_list|,
argument|bool stop_others
argument_list|)
block|;
operator|~
name|AppleThreadPlanStepThroughObjCTrampoline
argument_list|()
name|override
block|;
specifier|static
name|bool
name|PreResumeInitializeFunctionCaller
argument_list|(
name|void
operator|*
name|myself
argument_list|)
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
name|lldb
operator|::
name|StateType
name|GetPlanRunState
argument_list|()
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
name|StopOthers
argument_list|()
name|override
block|{
return|return
name|m_stop_others
return|;
block|}
comment|// The base class MischiefManaged does some cleanup - so you have to call it
comment|// in your MischiefManaged derived class.
name|bool
name|MischiefManaged
argument_list|()
name|override
block|;
name|void
name|DidPush
argument_list|()
name|override
block|;
name|bool
name|WillStop
argument_list|()
name|override
block|;
name|protected
operator|:
name|bool
name|DoPlanExplainsStop
argument_list|(
argument|Event *event_ptr
argument_list|)
name|override
block|;
name|private
operator|:
name|bool
name|InitializeFunctionCaller
argument_list|()
block|;
name|AppleObjCTrampolineHandler
operator|*
name|m_trampoline_handler
block|;
comment|// FIXME - ensure this doesn't go away on us?  SP maybe?
name|lldb
operator|::
name|addr_t
name|m_args_addr
block|;
comment|// Stores the address for our step through function result structure.
comment|//lldb::addr_t m_object_addr;  // This is only for Description.
name|ValueList
name|m_input_values
block|;
name|lldb
operator|::
name|addr_t
name|m_isa_addr
block|;
comment|// isa_addr and sel_addr are the keys we will use to cache the implementation.
name|lldb
operator|::
name|addr_t
name|m_sel_addr
block|;
name|lldb
operator|::
name|ThreadPlanSP
name|m_func_sp
block|;
comment|// This is the function call plan.  We fill it at start, then set it
comment|// to NULL when this plan is done.  That way we know to go to:
name|lldb
operator|::
name|ThreadPlanSP
name|m_run_to_sp
block|;
comment|// The plan that runs to the target.
name|FunctionCaller
operator|*
name|m_impl_function
block|;
comment|// This is a pointer to a impl function that
comment|// is owned by the client that pushes this plan.
name|bool
name|m_stop_others
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
comment|// lldb_AppleThreadPlanStepThroughObjCTrampoline_h_
end_comment

end_unit

