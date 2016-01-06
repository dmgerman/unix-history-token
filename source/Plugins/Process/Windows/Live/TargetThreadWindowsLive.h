begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- TargetThreadWindowsLive.h -------------------------------*- C++ -*-===//
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
name|liblldb_Plugins_Process_Windows_TargetThreadWindowsLive_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Plugins_Process_Windows_TargetThreadWindowsLive_H_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/HostThread.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Thread.h"
end_include

begin_include
include|#
directive|include
file|"Plugins/Process/Windows/Common/TargetThreadWindows.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ProcessWindows
decl_stmt|;
name|class
name|HostThread
decl_stmt|;
name|class
name|StackFrame
decl_stmt|;
name|class
name|TargetThreadWindowsLive
range|:
name|public
name|lldb_private
operator|::
name|TargetThreadWindows
block|{
name|public
operator|:
name|TargetThreadWindowsLive
argument_list|(
name|ProcessWindows
operator|&
name|process
argument_list|,
specifier|const
name|HostThread
operator|&
name|thread
argument_list|)
block|;
name|virtual
operator|~
name|TargetThreadWindowsLive
argument_list|()
block|;
comment|// lldb_private::Thread overrides
name|void
name|RefreshStateAfterStop
argument_list|()
name|override
block|;
name|void
name|WillResume
argument_list|(
argument|lldb::StateType resume_state
argument_list|)
name|override
block|;
name|void
name|DidStop
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
argument|StackFrame *frame
argument_list|)
name|override
block|;
name|bool
name|CalculateStopInfo
argument_list|()
name|override
block|;
name|Unwind
operator|*
name|GetUnwinder
argument_list|()
name|override
block|;
name|bool
name|DoResume
argument_list|()
block|;
name|HostThread
name|GetHostThread
argument_list|()
specifier|const
block|{
return|return
name|m_host_thread
return|;
block|}
name|private
operator|:
name|lldb
operator|::
name|RegisterContextSP
name|CreateRegisterContextForFrameIndex
argument_list|(
argument|uint32_t idx
argument_list|)
block|;
name|HostThread
name|m_host_thread
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

