begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadMemory.h ------------------------------------------*- C++ -*-===//
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

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<string>
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
argument|llvm::StringRef name
argument_list|,
argument|llvm::StringRef queue
argument_list|,
argument|lldb::addr_t register_data_addr
argument_list|)
block|;
operator|~
name|ThreadMemory
argument_list|()
name|override
block|;
name|lldb
operator|::
name|RegisterContextSP
name|GetRegisterContext
argument_list|()
name|override
block|;
name|lldb
operator|::
name|RegisterContextSP
name|CreateRegisterContextForFrame
argument_list|(
argument|lldb_private::StackFrame *frame
argument_list|)
name|override
block|;
name|bool
name|CalculateStopInfo
argument_list|()
name|override
block|;
specifier|const
name|char
operator|*
name|GetInfo
argument_list|()
name|override
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
name|nullptr
return|;
block|}
end_decl_stmt

begin_function
specifier|const
name|char
modifier|*
name|GetName
parameter_list|()
function|override
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
name|nullptr
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|GetQueueName
parameter_list|()
function|override
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
name|nullptr
return|;
block|}
end_function

begin_decl_stmt
name|void
name|WillResume
argument_list|(
name|lldb
operator|::
name|StateType
name|resume_state
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|DidResume
parameter_list|()
function|override
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
name|lldb
operator|::
name|user_id_t
name|GetProtocolID
argument_list|()
specifier|const
name|override
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

begin_macro
unit|}    void
name|RefreshStateAfterStop
argument_list|()
end_macro

begin_expr_stmt
name|override
expr_stmt|;
end_expr_stmt

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

begin_expr_stmt
name|void
name|ClearStackFrames
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|ClearBackingThread
parameter_list|()
function|override
block|{
name|m_backing_thread_sp
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
end_function

begin_decl_stmt
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
name|override
block|{
comment|// printf ("Thread 0x%llx is being backed by thread 0x%llx\n", GetID(),
comment|// thread_sp->GetID());
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
name|lldb
operator|::
name|ThreadSP
name|GetBackingThread
argument_list|()
specifier|const
name|override
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
name|bool
name|IsOperatingSystemPluginThread
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

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

