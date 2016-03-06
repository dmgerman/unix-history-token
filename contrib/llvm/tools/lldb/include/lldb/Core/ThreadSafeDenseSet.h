begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadSafeDenseSet.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_ThreadSafeDenseSet_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadSafeDenseSet_h_
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
file|"llvm/ADT/DenseSet.h"
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
name|_ElementType
operator|>
name|class
name|ThreadSafeDenseSet
block|{
name|public
operator|:
typedef|typedef
name|llvm
operator|::
name|DenseSet
operator|<
name|_ElementType
operator|>
name|LLVMSetType
expr_stmt|;
name|ThreadSafeDenseSet
argument_list|(
argument|unsigned set_initial_capacity =
literal|0
argument_list|,
argument|Mutex::Type mutex_type = Mutex::eMutexTypeNormal
argument_list|)
operator|:
name|m_set
argument_list|(
name|set_initial_capacity
argument_list|)
operator|,
name|m_mutex
argument_list|(
argument|mutex_type
argument_list|)
block|{         }
name|void
name|Insert
argument_list|(
argument|_ElementType e
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
name|m_set
operator|.
name|insert
argument_list|(
name|e
argument_list|)
block|;         }
name|void
name|Erase
argument_list|(
argument|_ElementType e
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
name|m_set
operator|.
name|erase
argument_list|(
name|e
argument_list|)
block|;         }
name|bool
name|Lookup
argument_list|(
argument|_ElementType e
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
operator|(
name|m_set
operator|.
name|count
argument_list|(
name|e
argument_list|)
operator|>
literal|0
operator|)
return|;
block|}
name|void
name|Clear
parameter_list|()
block|{
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
name|m_set
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|protected
label|:
name|LLVMSetType
name|m_set
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
comment|// liblldb_ThreadSafeDenseSet_h_
end_comment

end_unit

