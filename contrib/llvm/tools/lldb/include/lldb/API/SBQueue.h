begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBQueue.h -----------------------------------------------*- C++ -*-===//
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
name|LLDB_SBQueue_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBQueue_h_
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBQueueItem.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBQueue
block|{
name|public
label|:
name|SBQueue
argument_list|()
expr_stmt|;
name|SBQueue
argument_list|(
specifier|const
name|QueueSP
operator|&
name|queue_sp
argument_list|)
expr_stmt|;
name|SBQueue
argument_list|(
specifier|const
name|SBQueue
operator|&
name|rhs
argument_list|)
expr_stmt|;
specifier|const
name|SBQueue
modifier|&
name|operator
init|=
operator|(
specifier|const
name|lldb
operator|::
name|SBQueue
operator|&
name|rhs
operator|)
decl_stmt|;
operator|~
name|SBQueue
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
name|SBProcess
name|GetProcess
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|queue_id_t
name|GetQueueID
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
operator|*
name|GetName
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|GetIndexID
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|GetNumThreads
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBThread
name|GetThreadAtIndex
argument_list|(
name|uint32_t
argument_list|)
expr_stmt|;
name|uint32_t
name|GetNumPendingItems
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBQueueItem
name|GetPendingItemAtIndex
argument_list|(
name|uint32_t
argument_list|)
expr_stmt|;
name|protected
label|:
name|friend
name|class
name|SBProcess
decl_stmt|;
name|void
name|SetQueue
argument_list|(
specifier|const
name|lldb
operator|::
name|QueueSP
operator|&
name|queue_sp
argument_list|)
decl_stmt|;
name|void
name|FetchThreads
parameter_list|()
function_decl|;
name|void
name|FetchItems
parameter_list|()
function_decl|;
name|private
label|:
name|std
operator|::
name|shared_ptr
operator|<
name|lldb_private
operator|::
name|QueueImpl
operator|>
name|m_opaque_sp
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
comment|// LLDB_SBQueue_h_
end_comment

end_unit

