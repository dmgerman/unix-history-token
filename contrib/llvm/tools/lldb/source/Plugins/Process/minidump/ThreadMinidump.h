begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadMinidump.h ---------------------------------------*- C++ -*-===//
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
name|liblldb_ThreadMinidump_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadMinidump_h_
end_define

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"MinidumpTypes.h"
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Target/Thread.h"
end_include

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|minidump
block|{
name|class
name|ThreadMinidump
range|:
name|public
name|Thread
block|{
name|public
operator|:
name|ThreadMinidump
argument_list|(
name|Process
operator|&
name|process
argument_list|,
specifier|const
name|MinidumpThread
operator|&
name|td
argument_list|,
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|gpregset_data
argument_list|)
block|;
operator|~
name|ThreadMinidump
argument_list|()
name|override
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
argument|StackFrame *frame
argument_list|)
name|override
block|;
name|void
name|ClearStackFrames
argument_list|()
name|override
block|;
name|protected
operator|:
name|lldb
operator|::
name|RegisterContextSP
name|m_thread_reg_ctx_sp
block|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|m_gpregset_data
block|;
name|bool
name|CalculateStopInfo
argument_list|()
name|override
block|; }
decl_stmt|;
block|}
comment|// namespace minidump
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
comment|// liblldb_ThreadMinidump_h_
end_comment

end_unit

