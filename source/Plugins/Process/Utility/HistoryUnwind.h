begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HistoryUnwind.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_HistoryUnwind_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_HistoryUnwind_h_
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

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

begin_include
include|#
directive|include
file|"lldb/Target/Unwind.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|HistoryUnwind
range|:
name|public
name|lldb_private
operator|::
name|Unwind
block|{
name|public
operator|:
name|HistoryUnwind
argument_list|(
argument|Thread&thread
argument_list|,
argument|std::vector<lldb::addr_t> pcs
argument_list|,
argument|uint32_t stop_id
argument_list|,
argument|bool stop_id_is_valid
argument_list|)
block|;
name|virtual
operator|~
name|HistoryUnwind
argument_list|()
block|;
name|protected
operator|:
name|void
name|DoClear
argument_list|()
block|;
name|lldb
operator|::
name|RegisterContextSP
name|DoCreateRegisterContextForFrame
argument_list|(
name|StackFrame
operator|*
name|frame
argument_list|)
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
name|uint32_t
name|DoGetFrameCount
argument_list|()
block|;
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|addr_t
operator|>
name|m_pcs
block|;
name|uint32_t
name|m_stop_id
block|;
name|bool
name|m_stop_id_is_valid
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
comment|// liblldb_HistoryUnwind_h_
end_comment

end_unit

