begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DNBThreadResumeActions.h --------------------------------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|//  Created by Greg Clayton on 03/13/2010
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
name|__DNBThreadResumeActions_h__
end_ifndef

begin_define
define|#
directive|define
name|__DNBThreadResumeActions_h__
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"DNBDefs.h"
end_include

begin_decl_stmt
name|class
name|DNBThreadResumeActions
block|{
name|public
label|:
name|DNBThreadResumeActions
argument_list|()
expr_stmt|;
name|DNBThreadResumeActions
argument_list|(
argument|nub_state_t default_action
argument_list|,
argument|int signal
argument_list|)
empty_stmt|;
name|DNBThreadResumeActions
argument_list|(
argument|const DNBThreadResumeAction *actions
argument_list|,
argument|size_t num_actions
argument_list|)
empty_stmt|;
name|bool
name|IsEmpty
argument_list|()
specifier|const
block|{
return|return
name|m_actions
operator|.
name|empty
argument_list|()
return|;
block|}
name|void
name|Append
parameter_list|(
specifier|const
name|DNBThreadResumeAction
modifier|&
name|action
parameter_list|)
function_decl|;
name|void
name|AppendAction
parameter_list|(
name|nub_thread_t
name|tid
parameter_list|,
name|nub_state_t
name|state
parameter_list|,
name|int
name|signal
init|=
literal|0
parameter_list|,
name|nub_addr_t
name|addr
init|=
name|INVALID_NUB_ADDRESS
parameter_list|)
function_decl|;
name|void
name|AppendResumeAll
parameter_list|()
block|{
name|AppendAction
argument_list|(
name|INVALID_NUB_THREAD
argument_list|,
name|eStateRunning
argument_list|)
expr_stmt|;
block|}
name|void
name|AppendSuspendAll
parameter_list|()
block|{
name|AppendAction
argument_list|(
name|INVALID_NUB_THREAD
argument_list|,
name|eStateStopped
argument_list|)
expr_stmt|;
block|}
name|void
name|AppendStepAll
parameter_list|()
block|{
name|AppendAction
argument_list|(
name|INVALID_NUB_THREAD
argument_list|,
name|eStateStepping
argument_list|)
expr_stmt|;
block|}
specifier|const
name|DNBThreadResumeAction
modifier|*
name|GetActionForThread
argument_list|(
name|nub_thread_t
name|tid
argument_list|,
name|bool
name|default_ok
argument_list|)
decl|const
decl_stmt|;
name|size_t
name|NumActionsWithState
argument_list|(
name|nub_state_t
name|state
argument_list|)
decl|const
decl_stmt|;
name|bool
name|SetDefaultThreadActionIfNeeded
parameter_list|(
name|nub_state_t
name|action
parameter_list|,
name|int
name|signal
parameter_list|)
function_decl|;
name|void
name|SetSignalHandledForThread
argument_list|(
name|nub_thread_t
name|tid
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|DNBThreadResumeAction
operator|*
name|GetFirst
argument_list|()
specifier|const
block|{
return|return
name|m_actions
operator|.
name|data
argument_list|()
return|;
block|}
name|size_t
name|GetSize
argument_list|()
specifier|const
block|{
return|return
name|m_actions
operator|.
name|size
argument_list|()
return|;
block|}
name|void
name|Clear
parameter_list|()
block|{
name|m_actions
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_signal_handled
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|protected
label|:
name|std
operator|::
name|vector
operator|<
name|DNBThreadResumeAction
operator|>
name|m_actions
expr_stmt|;
name|mutable
name|std
operator|::
name|vector
operator|<
name|bool
operator|>
name|m_signal_handled
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef __DNBThreadResumeActions_h__
end_comment

end_unit

