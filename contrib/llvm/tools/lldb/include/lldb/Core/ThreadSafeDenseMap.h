begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadSafeDenseMap.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_ThreadSafeDenseMap_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadSafeDenseMap_h_
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

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Host/Mutex.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|template
operator|<
name|typename
name|_KeyType
operator|,
name|typename
name|_ValueType
operator|>
name|class
name|ThreadSafeDenseMap
block|{
name|public
operator|:
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|_KeyType
operator|,
name|_ValueType
operator|>
name|LLVMMapType
expr_stmt|;
name|ThreadSafeDenseMap
argument_list|(
argument|unsigned map_initial_capacity =
literal|0
argument_list|,
argument|Mutex::Type mutex_type = Mutex::eMutexTypeNormal
argument_list|)
operator|:
name|m_map
argument_list|(
name|map_initial_capacity
argument_list|)
operator|,
name|m_mutex
argument_list|(
argument|mutex_type
argument_list|)
block|{     }
name|void
name|Insert
argument_list|(
argument|_KeyType k
argument_list|,
argument|_ValueType v
argument_list|)
block|{
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_mutex
argument_list|)
block|;
name|m_map
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|k
argument_list|,
name|v
argument_list|)
argument_list|)
block|;     }
name|void
name|Erase
argument_list|(
argument|_KeyType k
argument_list|)
block|{
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_mutex
argument_list|)
block|;
name|m_map
operator|.
name|erase
argument_list|(
name|k
argument_list|)
block|;     }
name|_ValueType
name|Lookup
argument_list|(
argument|_KeyType k
argument_list|)
block|{
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_mutex
argument_list|)
block|;
return|return
name|m_map
operator|.
name|lookup
argument_list|(
name|k
argument_list|)
return|;
block|}
name|protected
label|:
name|LLVMMapType
name|m_map
decl_stmt|;
name|Mutex
name|m_mutex
decl_stmt|;
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
comment|// liblldb_ThreadSafeSTLMap_h_
end_comment

end_unit

