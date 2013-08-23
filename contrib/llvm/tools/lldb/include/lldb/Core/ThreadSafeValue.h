begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadSafeValue.h ---------------------------------------*- C++ -*-===//
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
name|liblldb_ThreadSafeValue_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadSafeValue_h_
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
name|class
name|T
operator|>
name|class
name|ThreadSafeValue
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|ThreadSafeValue
argument_list|()
operator|:
name|m_value
argument_list|()
block|,
name|m_mutex
argument_list|(
argument|Mutex::eMutexTypeRecursive
argument_list|)
block|{     }
name|ThreadSafeValue
argument_list|(
specifier|const
name|T
operator|&
name|value
argument_list|)
operator|:
name|m_value
argument_list|(
name|value
argument_list|)
block|,
name|m_mutex
argument_list|(
argument|Mutex::eMutexTypeRecursive
argument_list|)
block|{     }
operator|~
name|ThreadSafeValue
argument_list|()
block|{     }
name|T
name|GetValue
argument_list|()
specifier|const
block|{
name|T
name|value
block|;
block|{
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_mutex
argument_list|)
block|;
name|value
operator|=
name|m_value
block|;         }
return|return
name|value
return|;
block|}
comment|// Call this if you have already manually locked the mutex using the
comment|// GetMutex() accessor
specifier|const
name|T
operator|&
name|GetValueNoLock
argument_list|()
specifier|const
block|{
return|return
name|m_value
return|;
block|}
name|void
name|SetValue
argument_list|(
argument|const T& value
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
name|m_value
operator|=
name|value
block|;     }
comment|// Call this if you have already manually locked the mutex using the
comment|// GetMutex() accessor
name|void
name|SetValueNoLock
argument_list|(
argument|const T& value
argument_list|)
block|{
name|m_value
operator|=
name|value
block|;     }
name|Mutex
operator|&
name|GetMutex
argument_list|()
block|{
return|return
name|m_mutex
return|;
block|}
name|private
operator|:
name|T
name|m_value
block|;
name|mutable
name|Mutex
name|m_mutex
block|;
comment|//------------------------------------------------------------------
comment|// For ThreadSafeValue only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadSafeValue
argument_list|)
block|; }
expr_stmt|;
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
comment|// liblldb_ThreadSafeValue_h_
end_comment

end_unit

