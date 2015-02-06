begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBThread.h ----------------------------------------------*- C++ -*-===//
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
name|LLDB_SBThreadPlan_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBThreadPlan_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBThreadPlan
block|{
name|friend
name|class
name|lldb_private
operator|::
name|ThreadPlan
expr_stmt|;
name|public
label|:
name|SBThreadPlan
argument_list|()
expr_stmt|;
name|SBThreadPlan
argument_list|(
specifier|const
name|lldb
operator|::
name|SBThreadPlan
operator|&
name|threadPlan
argument_list|)
expr_stmt|;
name|SBThreadPlan
argument_list|(
specifier|const
name|lldb
operator|::
name|ThreadPlanSP
operator|&
name|lldb_object_sp
argument_list|)
expr_stmt|;
name|SBThreadPlan
argument_list|(
name|lldb
operator|::
name|SBThread
operator|&
name|thread
argument_list|,
specifier|const
name|char
operator|*
name|class_name
argument_list|)
expr_stmt|;
operator|~
name|SBThreadPlan
argument_list|()
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|lldb
operator|::
name|StopReason
name|GetStopReason
argument_list|()
expr_stmt|;
comment|/// Get the number of words associated with the stop reason.
comment|/// See also GetStopReasonDataAtIndex().
name|size_t
name|GetStopReasonDataCount
parameter_list|()
function_decl|;
comment|//--------------------------------------------------------------------------
comment|/// Get information associated with a stop reason.
comment|///
comment|/// Breakpoint stop reasons will have data that consists of pairs of
comment|/// breakpoint IDs followed by the breakpoint location IDs (they always come
comment|/// in pairs).
comment|///
comment|/// Stop Reason              Count Data Type
comment|/// ======================== ===== =========================================
comment|/// eStopReasonNone          0
comment|/// eStopReasonTrace         0
comment|/// eStopReasonBreakpoint    N     duple: {breakpoint id, location id}
comment|/// eStopReasonWatchpoint    1     watchpoint id
comment|/// eStopReasonSignal        1     unix signal number
comment|/// eStopReasonException     N     exception data
comment|/// eStopReasonExec          0
comment|/// eStopReasonPlanComplete  0
comment|//--------------------------------------------------------------------------
name|uint64_t
name|GetStopReasonDataAtIndex
parameter_list|(
name|uint32_t
name|idx
parameter_list|)
function_decl|;
name|SBThread
name|GetThread
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|lldb
operator|::
name|SBThreadPlan
operator|&
name|operator
operator|=
operator|(
specifier|const
name|lldb
operator|::
name|SBThreadPlan
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|GetDescription
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|description
argument_list|)
decl|const
decl_stmt|;
name|void
name|SetPlanComplete
parameter_list|(
name|bool
name|success
parameter_list|)
function_decl|;
name|bool
name|IsPlanComplete
parameter_list|()
function_decl|;
name|bool
name|IsValid
parameter_list|()
function_decl|;
comment|// This section allows an SBThreadPlan to push another of the common types of plans...
name|SBThreadPlan
name|QueueThreadPlanForStepOverRange
argument_list|(
name|SBAddress
operator|&
name|start_address
argument_list|,
name|lldb
operator|::
name|addr_t
name|range_size
argument_list|)
decl_stmt|;
name|SBThreadPlan
name|QueueThreadPlanForStepInRange
argument_list|(
name|SBAddress
operator|&
name|start_address
argument_list|,
name|lldb
operator|::
name|addr_t
name|range_size
argument_list|)
decl_stmt|;
name|SBThreadPlan
name|QueueThreadPlanForStepOut
parameter_list|(
name|uint32_t
name|frame_idx_to_step_to
parameter_list|,
name|bool
name|first_insn
init|=
name|false
parameter_list|)
function_decl|;
name|SBThreadPlan
name|QueueThreadPlanForRunToAddress
parameter_list|(
name|SBAddress
name|address
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|SWIG
name|lldb_private
operator|::
name|ThreadPlan
operator|*
name|get
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|protected
label|:
name|friend
name|class
name|SBBreakpoint
decl_stmt|;
name|friend
name|class
name|SBBreakpointLocation
decl_stmt|;
name|friend
name|class
name|SBFrame
decl_stmt|;
name|friend
name|class
name|SBProcess
decl_stmt|;
name|friend
name|class
name|SBDebugger
decl_stmt|;
name|friend
name|class
name|SBValue
decl_stmt|;
name|friend
name|class
name|lldb_private
operator|::
name|QueueImpl
expr_stmt|;
name|friend
name|class
name|SBQueueItem
decl_stmt|;
ifndef|#
directive|ifndef
name|SWIG
name|void
name|SetThreadPlan
argument_list|(
specifier|const
name|lldb
operator|::
name|ThreadPlanSP
operator|&
name|lldb_object_sp
argument_list|)
decl_stmt|;
endif|#
directive|endif
name|private
label|:
name|lldb
operator|::
name|ThreadPlanSP
name|m_opaque_sp
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBThreadPlan_h_
end_comment

end_unit

