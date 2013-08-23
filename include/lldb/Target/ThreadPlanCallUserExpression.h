begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadPlanCallUserExpression.h --------------------------------*- C++ -*-===//
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
name|liblldb_ThreadPlanCallUserExpression_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadPlanCallUserExpression_h_
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
file|"lldb/Expression/ClangUserExpression.h"
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

begin_include
include|#
directive|include
file|"lldb/Target/ThreadPlanCallFunction.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ThreadPlanCallUserExpression
range|:
name|public
name|ThreadPlanCallFunction
block|{
name|public
operator|:
name|ThreadPlanCallUserExpression
argument_list|(
argument|Thread&thread
argument_list|,
argument|Address&function
argument_list|,
argument|lldb::addr_t arg
argument_list|,
argument|bool stop_other_threads
argument_list|,
argument|bool unwind_on_error
argument_list|,
argument|bool ignore_breakpoints
argument_list|,
argument|lldb::addr_t *this_arg
argument_list|,
argument|lldb::addr_t *cmd_arg
argument_list|,
argument|ClangUserExpression::ClangUserExpressionSP&user_expression_sp
argument_list|)
block|;
name|virtual
operator|~
name|ThreadPlanCallUserExpression
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
name|void
name|WillPop
argument_list|()
block|{
name|ThreadPlanCallFunction
operator|::
name|WillPop
argument_list|()
block|;
if|if
condition|(
name|m_user_expression_sp
condition|)
name|m_user_expression_sp
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
name|virtual
name|lldb
operator|::
name|StopInfoSP
name|GetRealStopInfo
argument_list|()
block|;
name|protected
operator|:
name|private
operator|:
name|ClangUserExpression
operator|::
name|ClangUserExpressionSP
name|m_user_expression_sp
block|;
comment|// This is currently just used to ensure the
comment|// User expression the initiated this ThreadPlan
comment|// lives as long as the thread plan does.
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadPlanCallUserExpression
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
comment|// liblldb_ThreadPlanCallUserExpression_h_
end_comment

end_unit

