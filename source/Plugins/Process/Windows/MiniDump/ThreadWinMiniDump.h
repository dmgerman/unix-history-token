begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadWinMiniDump.h -------------------------------------*- C++ -*-===//
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
name|liblldb_ThreadWinMiniDump_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadWinMiniDump_h_
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"lldb/Core/DataExtractor.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Thread.h"
end_include

begin_decl_stmt
name|class
name|ThreadWinMiniDump
range|:
name|public
name|lldb_private
operator|::
name|Thread
block|{
name|public
operator|:
name|ThreadWinMiniDump
argument_list|(
argument|lldb_private::Process&process
argument_list|,
argument|lldb::tid_t tid
argument_list|)
block|;
name|virtual
operator|~
name|ThreadWinMiniDump
argument_list|()
block|;
name|void
name|RefreshStateAfterStop
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
name|void
name|ClearStackFrames
argument_list|()
name|override
block|;
name|void
name|SetContext
argument_list|(
specifier|const
name|void
operator|*
name|context
argument_list|)
block|;
name|protected
operator|:
name|lldb
operator|::
name|RegisterContextSP
name|m_reg_context_sp
block|;
name|class
name|Data
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|Data
operator|>
name|m_data
block|;
comment|// for WinAPI-specific data
name|bool
name|CalculateStopInfo
argument_list|()
name|override
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

