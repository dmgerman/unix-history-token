begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadPlanStepOverRange.h -------------------------------*- C++ -*-===//
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
name|liblldb_ThreadPlanStepOverRange_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadPlanStepOverRange_h_
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

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ThreadPlanStepOverRange
range|:
name|public
name|ThreadPlanStepRange
decl_stmt|,
name|ThreadPlanShouldStopHere
block|{
name|public
label|:
name|ThreadPlanStepOverRange
argument_list|(
argument|Thread&thread
argument_list|,
argument|const AddressRange&range
argument_list|,
argument|const SymbolContext&addr_context
argument_list|,
argument|lldb::RunMode stop_others
argument_list|,
argument|LazyBool step_out_avoids_no_debug
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|ThreadPlanStepOverRange
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
name|protected
label|:
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
name|ThreadPlanStepOverRange
operator|::
name|s_default_flag_values
argument_list|)
expr_stmt|;
block|}
name|private
label|:
specifier|static
name|uint32_t
name|s_default_flag_values
decl_stmt|;
name|void
name|SetupAvoidNoDebug
parameter_list|(
name|LazyBool
name|step_out_avoids_code_without_debug_info
parameter_list|)
function_decl|;
name|bool
name|IsEquivalentContext
parameter_list|(
specifier|const
name|SymbolContext
modifier|&
name|context
parameter_list|)
function_decl|;
name|bool
name|m_first_resume
decl_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadPlanStepOverRange
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
comment|// liblldb_ThreadPlanStepOverRange_h_
end_comment

end_unit

