begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadMemory.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_ThreadMemory_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadMemory_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Target/Thread.h"
end_include

begin_decl_stmt
name|class
name|ThreadMemory
range|:
name|public
name|lldb_private
operator|::
name|Thread
block|{
name|public
operator|:
name|ThreadMemory
argument_list|(
argument|lldb_private::Process&process
argument_list|,
argument|lldb::tid_t tid
argument_list|,
argument|const lldb::ValueObjectSP&thread_info_valobj_sp
argument_list|)
block|;
name|ThreadMemory
argument_list|(
argument|lldb_private::Process&process
argument_list|,
argument|lldb::tid_t tid
argument_list|,
argument|const char *name
argument_list|,
argument|const char *queue
argument_list|,
argument|lldb::addr_t register_data_addr
argument_list|)
block|;
name|virtual
operator|~
name|ThreadMemory
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|// lldb_private::Thread methods
comment|//------------------------------------------------------------------
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
name|virtual
name|bool
name|CalculateStopInfo
argument_list|()
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetInfo
argument_list|()
block|{
if|if
condition|(
name|m_backing_thread_sp
condition|)
name|m_backing_thread_sp
operator|->
name|GetInfo
argument_list|()
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_decl_stmt

begin_function
name|virtual
specifier|const
name|char
modifier|*
name|GetName
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_name
operator|.
name|empty
argument_list|()
condition|)
return|return
name|m_name
operator|.
name|c_str
argument_list|()
return|;
if|if
condition|(
name|m_backing_thread_sp
condition|)
name|m_backing_thread_sp
operator|->
name|GetName
argument_list|()
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

begin_function
name|virtual
specifier|const
name|char
modifier|*
name|GetQueueName
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_queue
operator|.
name|empty
argument_list|()
condition|)
return|return
name|m_queue
operator|.
name|c_str
argument_list|()
return|;
if|if
condition|(
name|m_backing_thread_sp
condition|)
name|m_backing_thread_sp
operator|->
name|GetQueueName
argument_list|()
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

begin_decl_stmt
name|virtual
name|void
name|WillResume
argument_list|(
name|lldb
operator|::
name|StateType
name|resume_state
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|virtual
name|void
name|DidResume
parameter_list|()
block|{
if|if
condition|(
name|m_backing_thread_sp
condition|)
name|m_backing_thread_sp
operator|->
name|DidResume
argument_list|()
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|virtual
name|lldb
operator|::
name|user_id_t
name|GetProtocolID
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_backing_thread_sp
condition|)
return|return
name|m_backing_thread_sp
operator|->
name|GetProtocolID
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|Thread
operator|::
name|GetProtocolID
argument_list|()
return|;
end_return

begin_function_decl
unit|}      virtual
name|void
name|RefreshStateAfterStop
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|lldb
operator|::
name|ValueObjectSP
operator|&
name|GetValueObject
argument_list|()
block|{
return|return
name|m_thread_info_valobj_sp
return|;
block|}
end_expr_stmt

begin_function_decl
name|virtual
name|void
name|ClearStackFrames
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|virtual
name|void
name|ClearBackingThread
parameter_list|()
block|{
name|m_backing_thread_sp
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|virtual
name|bool
name|SetBackingThread
argument_list|(
specifier|const
name|lldb
operator|::
name|ThreadSP
operator|&
name|thread_sp
argument_list|)
block|{
comment|//printf ("Thread 0x%llx is being backed by thread 0x%llx\n", GetID(), thread_sp->GetID());
name|m_backing_thread_sp
operator|=
name|thread_sp
expr_stmt|;
return|return
operator|(
name|bool
operator|)
name|thread_sp
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|virtual
name|lldb
operator|::
name|ThreadSP
name|GetBackingThread
argument_list|()
specifier|const
block|{
return|return
name|m_backing_thread_sp
return|;
block|}
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|virtual
name|bool
name|IsOperatingSystemPluginThread
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// For ThreadMemory and subclasses
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// If this memory thread is actually represented by a thread from the
end_comment

begin_comment
comment|// lldb_private::Process subclass, then fill in the thread here and
end_comment

begin_comment
comment|// all APIs will be routed through this thread object. If m_backing_thread_sp
end_comment

begin_comment
comment|// is empty, then this thread is simply in memory with no representation
end_comment

begin_comment
comment|// through the process plug-in.
end_comment

begin_expr_stmt
name|lldb
operator|::
name|ThreadSP
name|m_backing_thread_sp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|ValueObjectSP
name|m_thread_info_valobj_sp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|m_name
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|m_queue
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|addr_t
name|m_register_data_addr
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// For ThreadMemory only
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadMemory
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ThreadMemory_h_
end_comment

end_unit

