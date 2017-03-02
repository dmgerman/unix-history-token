begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadSafeSTLVector.h ------------------------------------*- C++
end_comment

begin_comment
comment|//-*-===//
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
name|liblldb_ThreadSafeSTLVector_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadSafeSTLVector_h_
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
file|<mutex>
end_include

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
file|"lldb/lldb-defines.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|template
operator|<
name|typename
name|_Object
operator|>
name|class
name|ThreadSafeSTLVector
block|{
name|public
operator|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|_Object
operator|>
name|collection
expr_stmt|;
typedef|typedef
name|typename
name|collection
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|typename
name|collection
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|ThreadSafeSTLVector
argument_list|()
operator|:
name|m_collection
argument_list|()
operator|,
name|m_mutex
argument_list|()
block|{}
operator|~
name|ThreadSafeSTLVector
argument_list|()
operator|=
expr|default
expr_stmt|;
name|bool
name|IsEmpty
argument_list|()
specifier|const
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|recursive_mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
block|;
return|return
name|m_collection
operator|.
name|empty
argument_list|()
return|;
block|}
name|void
name|Clear
parameter_list|()
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|recursive_mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
return|return
name|m_collection
operator|.
name|clear
argument_list|()
return|;
block|}
name|size_t
name|GetCount
parameter_list|()
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|recursive_mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
return|return
name|m_collection
operator|.
name|size
argument_list|()
return|;
block|}
name|void
name|AppendObject
parameter_list|(
name|_Object
modifier|&
name|object
parameter_list|)
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|recursive_mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
name|m_collection
operator|.
name|push_back
argument_list|(
name|object
argument_list|)
expr_stmt|;
block|}
name|_Object
name|GetObject
parameter_list|(
name|size_t
name|index
parameter_list|)
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|recursive_mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
return|return
name|m_collection
operator|.
name|at
argument_list|(
name|index
argument_list|)
return|;
block|}
name|void
name|SetObject
parameter_list|(
name|size_t
name|index
parameter_list|,
specifier|const
name|_Object
modifier|&
name|object
parameter_list|)
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|recursive_mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
name|m_collection
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|=
name|object
expr_stmt|;
block|}
name|std
operator|::
name|recursive_mutex
operator|&
name|GetMutex
argument_list|()
block|{
return|return
name|m_mutex
return|;
block|}
name|private
label|:
name|collection
name|m_collection
decl_stmt|;
name|mutable
name|std
operator|::
name|recursive_mutex
name|m_mutex
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// For ThreadSafeSTLVector only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadSafeSTLVector
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ThreadSafeSTLVector_h_
end_comment

end_unit

