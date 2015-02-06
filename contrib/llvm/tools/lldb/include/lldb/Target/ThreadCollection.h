begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadCollection.h --------------------------------------*- C++ -*-===//
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
name|liblldb_ThreadCollection_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadCollection_h_
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
file|"lldb/Utility/Iterable.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ThreadCollection
block|{
name|public
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|ThreadSP
operator|>
name|collection
expr_stmt|;
typedef|typedef
name|LockingAdaptedIterable
operator|<
name|collection
operator|,
name|lldb
operator|::
name|ThreadSP
operator|,
name|vector_adapter
operator|>
name|ThreadIterable
expr_stmt|;
name|ThreadCollection
argument_list|()
expr_stmt|;
name|ThreadCollection
argument_list|(
argument|collection threads
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|ThreadCollection
argument_list|()
block|{     }
name|uint32_t
name|GetSize
argument_list|()
expr_stmt|;
name|void
name|AddThread
argument_list|(
specifier|const
name|lldb
operator|::
name|ThreadSP
operator|&
name|thread_sp
argument_list|)
decl_stmt|;
name|void
name|InsertThread
argument_list|(
specifier|const
name|lldb
operator|::
name|ThreadSP
operator|&
name|thread_sp
argument_list|,
name|uint32_t
name|idx
argument_list|)
decl_stmt|;
comment|// Note that "idx" is not the same as the "thread_index". It is a zero
comment|// based index to accessing the current threads, whereas "thread_index"
comment|// is a unique index assigned
name|lldb
operator|::
name|ThreadSP
name|GetThreadAtIndex
argument_list|(
argument|uint32_t idx
argument_list|)
expr_stmt|;
name|virtual
name|ThreadIterable
name|Threads
parameter_list|()
block|{
return|return
name|ThreadIterable
argument_list|(
name|m_threads
argument_list|,
name|GetMutex
argument_list|()
argument_list|)
return|;
block|}
name|virtual
name|Mutex
modifier|&
name|GetMutex
parameter_list|()
block|{
return|return
name|m_mutex
return|;
block|}
name|protected
label|:
name|collection
name|m_threads
decl_stmt|;
name|Mutex
name|m_mutex
decl_stmt|;
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
comment|// liblldb_ThreadCollection_h_
end_comment

end_unit

