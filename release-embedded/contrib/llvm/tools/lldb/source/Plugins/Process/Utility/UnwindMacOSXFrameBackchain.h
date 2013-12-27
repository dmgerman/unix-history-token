begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- UnwindMacOSXFrameBackchain.h ----------------------------*- C++ -*-===//
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
name|lldb_UnwindMacOSXFrameBackchain_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_UnwindMacOSXFrameBackchain_h_
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
file|"lldb/Target/Unwind.h"
end_include

begin_decl_stmt
name|class
name|UnwindMacOSXFrameBackchain
range|:
name|public
name|lldb_private
operator|::
name|Unwind
block|{
name|public
operator|:
name|UnwindMacOSXFrameBackchain
argument_list|(
name|lldb_private
operator|::
name|Thread
operator|&
name|thread
argument_list|)
block|;
name|virtual
operator|~
name|UnwindMacOSXFrameBackchain
argument_list|()
block|{     }
name|protected
operator|:
name|virtual
name|void
name|DoClear
argument_list|()
block|{
name|m_cursors
operator|.
name|clear
argument_list|()
block|;     }
name|virtual
name|uint32_t
name|DoGetFrameCount
argument_list|()
block|;
name|bool
name|DoGetFrameInfoAtIndex
argument_list|(
argument|uint32_t frame_idx
argument_list|,
argument|lldb::addr_t& cfa
argument_list|,
argument|lldb::addr_t& pc
argument_list|)
block|;
name|lldb
operator|::
name|RegisterContextSP
name|DoCreateRegisterContextForFrame
argument_list|(
name|lldb_private
operator|::
name|StackFrame
operator|*
name|frame
argument_list|)
block|;
name|friend
name|class
name|RegisterContextMacOSXFrameBackchain
block|;      struct
name|Cursor
block|{
name|lldb
operator|::
name|addr_t
name|pc
block|;
comment|// Program counter
name|lldb
operator|::
name|addr_t
name|fp
block|;
comment|// Frame pointer for us with backchain
block|}
block|;
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|Cursor
operator|>
name|m_cursors
block|;
name|size_t
name|GetStackFrameData_i386
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|)
block|;
name|size_t
name|GetStackFrameData_x86_64
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// For UnwindMacOSXFrameBackchain only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|UnwindMacOSXFrameBackchain
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_UnwindMacOSXFrameBackchain_h_
end_comment

end_unit

