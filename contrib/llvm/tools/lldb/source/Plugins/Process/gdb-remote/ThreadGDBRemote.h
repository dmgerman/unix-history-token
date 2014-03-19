begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadGDBRemote.h ---------------------------------------*- C++ -*-===//
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
name|liblldb_ThreadGDBRemote_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadGDBRemote_h_
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Thread.h"
end_include

begin_decl_stmt
name|class
name|StringExtractor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|ProcessGDBRemote
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|ThreadGDBRemote
range|:
name|public
name|lldb_private
operator|::
name|Thread
block|{
name|public
operator|:
name|ThreadGDBRemote
argument_list|(
argument|lldb_private::Process&process
argument_list|,
argument|lldb::tid_t tid
argument_list|)
block|;
name|virtual
operator|~
name|ThreadGDBRemote
argument_list|()
block|;
name|virtual
name|void
name|WillResume
argument_list|(
argument|lldb::StateType resume_state
argument_list|)
block|;
name|virtual
name|void
name|RefreshStateAfterStop
argument_list|()
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetName
argument_list|()
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetQueueName
argument_list|()
block|;
name|virtual
name|lldb
operator|::
name|queue_id_t
name|GetQueueID
argument_list|()
block|;
name|virtual
name|lldb
operator|::
name|RegisterContextSP
name|GetRegisterContext
argument_list|()
block|;
name|virtual
name|lldb
operator|::
name|RegisterContextSP
name|CreateRegisterContextForFrame
argument_list|(
name|lldb_private
operator|::
name|StackFrame
operator|*
name|frame
argument_list|)
block|;
name|void
name|Dump
argument_list|(
argument|lldb_private::Log *log
argument_list|,
argument|uint32_t index
argument_list|)
block|;
specifier|static
name|bool
name|ThreadIDIsValid
argument_list|(
argument|lldb::tid_t thread
argument_list|)
block|;
name|bool
name|ShouldStop
argument_list|(
name|bool
operator|&
name|step_more
argument_list|)
block|;
specifier|const
name|char
operator|*
name|GetBasicInfoAsString
argument_list|()
block|;
name|void
name|SetName
argument_list|(
argument|const char *name
argument_list|)
block|{
if|if
condition|(
name|name
operator|&&
name|name
index|[
literal|0
index|]
condition|)
name|m_thread_name
operator|.
name|assign
argument_list|(
name|name
argument_list|)
expr_stmt|;
else|else
name|m_thread_name
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|lldb
operator|::
name|addr_t
name|GetThreadDispatchQAddr
argument_list|()
block|{
return|return
name|m_thread_dispatch_qaddr
return|;
block|}
name|void
name|SetThreadDispatchQAddr
argument_list|(
argument|lldb::addr_t thread_dispatch_qaddr
argument_list|)
block|{
name|m_thread_dispatch_qaddr
operator|=
name|thread_dispatch_qaddr
block|;     }
name|protected
operator|:
name|friend
name|class
name|ProcessGDBRemote
block|;
name|bool
name|PrivateSetRegisterValue
argument_list|(
argument|uint32_t reg
argument_list|,
argument|StringExtractor&response
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|std
operator|::
name|string
name|m_thread_name
block|;
name|std
operator|::
name|string
name|m_dispatch_queue_name
block|;
name|lldb
operator|::
name|addr_t
name|m_thread_dispatch_qaddr
block|;
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|void
name|SetStopInfoFromPacket
argument_list|(
argument|StringExtractor&stop_packet
argument_list|,
argument|uint32_t stop_id
argument_list|)
block|;
name|virtual
name|bool
name|CalculateStopInfo
argument_list|()
block|;   }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ThreadGDBRemote_h_
end_comment

end_unit

