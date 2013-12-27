begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadPlanRunToAddress.h --------------------------------*- C++ -*-===//
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
name|liblldb_ThreadPlanRunToAddress_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadPlanRunToAddress_h_
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
file|<vector>
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
file|"lldb/lldb-private.h"
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
name|ThreadPlanRunToAddress
range|:
name|public
name|ThreadPlan
block|{
name|public
operator|:
name|ThreadPlanRunToAddress
argument_list|(
argument|Thread&thread
argument_list|,
argument|Address&address
argument_list|,
argument|bool stop_others
argument_list|)
block|;
name|ThreadPlanRunToAddress
argument_list|(
argument|Thread&thread
argument_list|,
argument|lldb::addr_t address
argument_list|,
argument|bool stop_others
argument_list|)
block|;
name|ThreadPlanRunToAddress
argument_list|(
argument|Thread&thread
argument_list|,
argument|const std::vector<lldb::addr_t>&addresses
argument_list|,
argument|bool stop_others
argument_list|)
block|;
name|virtual
operator|~
name|ThreadPlanRunToAddress
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
name|bool
name|WillStop
argument_list|()
block|;
name|virtual
name|bool
name|MischiefManaged
argument_list|()
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
name|void
name|SetInitialBreakpoints
argument_list|()
block|;
name|bool
name|AtOurAddress
argument_list|()
block|;
name|private
operator|:
name|bool
name|m_stop_others
block|;
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|addr_t
operator|>
name|m_addresses
block|;
comment|// This is the address we are going to run to.
comment|// TODO: Would it be useful to have multiple addresses?
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|break_id_t
operator|>
name|m_break_ids
block|;
comment|// This is the breakpoint we are using to stop us at m_address.
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadPlanRunToAddress
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
comment|// liblldb_ThreadPlanRunToAddress_h_
end_comment

end_unit

