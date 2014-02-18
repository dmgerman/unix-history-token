begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBQueueItem.h -------------------------------------------*- C++ -*-===//
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
name|LLDB_SBQueueItem_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBQueueItem_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBAddress.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBThread.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBQueueItem
block|{
name|public
label|:
name|SBQueueItem
argument_list|()
expr_stmt|;
name|SBQueueItem
argument_list|(
specifier|const
name|lldb
operator|::
name|QueueItemSP
operator|&
name|queue_item_sp
argument_list|)
expr_stmt|;
operator|~
name|SBQueueItem
argument_list|()
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|lldb
operator|::
name|QueueItemKind
name|GetKind
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetKind
argument_list|(
name|lldb
operator|::
name|QueueItemKind
name|kind
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|SBAddress
name|GetAddress
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetAddress
argument_list|(
name|lldb
operator|::
name|SBAddress
name|addr
argument_list|)
decl_stmt|;
name|void
name|SetQueueItem
argument_list|(
specifier|const
name|lldb
operator|::
name|QueueItemSP
operator|&
name|queue_item_sp
argument_list|)
decl_stmt|;
name|SBThread
name|GetExtendedBacktraceThread
parameter_list|(
specifier|const
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
name|private
label|:
name|lldb
operator|::
name|QueueItemSP
name|m_queue_item_sp
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBQueueItem_h_
end_comment

end_unit

