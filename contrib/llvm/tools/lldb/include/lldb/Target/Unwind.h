begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Unwind.h ------------------------------------------------*- C++ -*-===//
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
name|liblldb_Unwind_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Unwind_h_
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
file|"lldb/Host/Mutex.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Unwind
block|{
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from Unwind can see and modify these
comment|//------------------------------------------------------------------
name|Unwind
argument_list|(
name|Thread
operator|&
name|thread
argument_list|)
operator|:
name|m_thread
argument_list|(
name|thread
argument_list|)
operator|,
name|m_unwind_mutex
argument_list|(
argument|Mutex::eMutexTypeRecursive
argument_list|)
block|{     }
name|public
operator|:
name|virtual
operator|~
name|Unwind
argument_list|()
block|{     }
name|void
name|Clear
argument_list|()
block|{
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_unwind_mutex
argument_list|)
block|;
name|DoClear
argument_list|()
block|;          }
name|uint32_t
name|GetFrameCount
argument_list|()
block|{
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_unwind_mutex
argument_list|)
block|;
return|return
name|DoGetFrameCount
argument_list|()
return|;
block|}
name|uint32_t
name|GetFramesUpTo
parameter_list|(
name|uint32_t
name|end_idx
parameter_list|)
block|{
name|lldb
operator|::
name|addr_t
name|cfa
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|pc
expr_stmt|;
name|uint32_t
name|idx
decl_stmt|;
for|for
control|(
name|idx
operator|=
literal|0
init|;
name|idx
operator|<
name|end_idx
condition|;
name|idx
operator|++
control|)
block|{
if|if
condition|(
operator|!
name|DoGetFrameInfoAtIndex
argument_list|(
name|idx
argument_list|,
name|cfa
argument_list|,
name|pc
argument_list|)
condition|)
block|{
break|break;
block|}
block|}
return|return
name|idx
return|;
block|}
name|bool
name|GetFrameInfoAtIndex
argument_list|(
name|uint32_t
name|frame_idx
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|cfa
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|pc
argument_list|)
block|{
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_unwind_mutex
argument_list|)
expr_stmt|;
return|return
name|DoGetFrameInfoAtIndex
argument_list|(
name|frame_idx
argument_list|,
name|cfa
argument_list|,
name|pc
argument_list|)
return|;
block|}
name|lldb
operator|::
name|RegisterContextSP
name|CreateRegisterContextForFrame
argument_list|(
argument|StackFrame *frame
argument_list|)
block|{
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_unwind_mutex
argument_list|)
block|;
return|return
name|DoCreateRegisterContextForFrame
argument_list|(
name|frame
argument_list|)
return|;
block|}
name|Thread
modifier|&
name|GetThread
parameter_list|()
block|{
return|return
name|m_thread
return|;
block|}
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from Unwind can see and modify these
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DoClear
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|uint32_t
name|DoGetFrameCount
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|DoGetFrameInfoAtIndex
argument_list|(
name|uint32_t
name|frame_idx
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|cfa
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|pc
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|lldb
operator|::
name|RegisterContextSP
name|DoCreateRegisterContextForFrame
argument_list|(
name|StackFrame
operator|*
name|frame
argument_list|)
operator|=
literal|0
expr_stmt|;
name|Thread
modifier|&
name|m_thread
decl_stmt|;
name|Mutex
name|m_unwind_mutex
decl_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Unwind
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
comment|// liblldb_Unwind_h_
end_comment

end_unit

