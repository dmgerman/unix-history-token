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
block|{
name|public
operator|:
name|ThreadPlanStepOverRange
argument_list|(
argument|Thread&thread
argument_list|,
argument|const AddressRange&range
argument_list|,
argument|const SymbolContext&addr_context
argument_list|,
argument|lldb::RunMode stop_others
argument_list|)
block|;
name|virtual
operator|~
name|ThreadPlanStepOverRange
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
name|ShouldStop
argument_list|(
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|bool
name|DoPlanExplainsStop
argument_list|(
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
name|virtual
name|bool
name|DoWillResume
argument_list|(
argument|lldb::StateType resume_state
argument_list|,
argument|bool current_plan
argument_list|)
block|;
name|private
operator|:
name|bool
name|IsEquivalentContext
argument_list|(
specifier|const
name|SymbolContext
operator|&
name|context
argument_list|)
block|;
name|bool
name|m_first_resume
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadPlanStepOverRange
argument_list|)
block|;  }
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
comment|// liblldb_ThreadPlanStepOverRange_h_
end_comment

end_unit

