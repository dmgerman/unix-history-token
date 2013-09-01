begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcessRunLock.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_ProcessRunLock_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ProcessRunLock_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|"lldb/Host/Mutex.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Condition.h"
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|/// Enumerations for broadcasting.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class ProcessRunLock ProcessRunLock.h "lldb/Host/ProcessRunLock.h"
comment|/// @brief A class used to prevent the process from starting while other
comment|/// threads are accessing its data, and prevent access to its data while
comment|/// it is running.
comment|//----------------------------------------------------------------------
name|class
name|ProcessRunLock
block|{
name|public
label|:
name|ProcessRunLock
argument_list|()
operator|:
name|m_rwlock
argument_list|()
operator|,
name|m_running
argument_list|(
argument|false
argument_list|)
block|{
name|int
name|err
operator|=
operator|::
name|pthread_rwlock_init
argument_list|(
operator|&
name|m_rwlock
argument_list|,
name|NULL
argument_list|)
block|;
operator|(
name|void
operator|)
name|err
block|;
comment|//#if LLDB_CONFIGURATION_DEBUG
comment|//        assert(err == 0);
comment|//#endif
block|}
operator|~
name|ProcessRunLock
argument_list|()
block|{
name|int
name|err
operator|=
operator|::
name|pthread_rwlock_destroy
argument_list|(
operator|&
name|m_rwlock
argument_list|)
block|;
operator|(
name|void
operator|)
name|err
block|;
comment|//#if LLDB_CONFIGURATION_DEBUG
comment|//        assert(err == 0);
comment|//#endif
block|}
name|bool
name|ReadTryLock
argument_list|()
block|{
operator|::
name|pthread_rwlock_rdlock
argument_list|(
operator|&
name|m_rwlock
argument_list|)
block|;
if|if
condition|(
name|m_running
operator|==
name|false
condition|)
block|{
return|return
name|true
return|;
block|}
operator|::
name|pthread_rwlock_unlock
argument_list|(
operator|&
name|m_rwlock
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
name|bool
name|ReadUnlock
parameter_list|()
block|{
return|return
operator|::
name|pthread_rwlock_unlock
argument_list|(
operator|&
name|m_rwlock
argument_list|)
operator|==
literal|0
return|;
block|}
name|bool
name|SetRunning
parameter_list|()
block|{
operator|::
name|pthread_rwlock_wrlock
argument_list|(
operator|&
name|m_rwlock
argument_list|)
expr_stmt|;
name|m_running
operator|=
name|true
expr_stmt|;
operator|::
name|pthread_rwlock_unlock
argument_list|(
operator|&
name|m_rwlock
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
name|bool
name|TrySetRunning
parameter_list|()
block|{
name|bool
name|r
decl_stmt|;
if|if
condition|(
operator|::
name|pthread_rwlock_trywrlock
argument_list|(
operator|&
name|m_rwlock
argument_list|)
operator|==
literal|0
condition|)
block|{
name|r
operator|=
operator|!
name|m_running
expr_stmt|;
name|m_running
operator|=
name|true
expr_stmt|;
operator|::
name|pthread_rwlock_unlock
argument_list|(
operator|&
name|m_rwlock
argument_list|)
expr_stmt|;
return|return
name|r
return|;
block|}
return|return
name|false
return|;
block|}
name|bool
name|SetStopped
parameter_list|()
block|{
operator|::
name|pthread_rwlock_wrlock
argument_list|(
operator|&
name|m_rwlock
argument_list|)
expr_stmt|;
name|m_running
operator|=
name|false
expr_stmt|;
operator|::
name|pthread_rwlock_unlock
argument_list|(
operator|&
name|m_rwlock
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
name|class
name|ProcessRunLocker
block|{
name|public
label|:
name|ProcessRunLocker
argument_list|()
operator|:
name|m_lock
argument_list|(
argument|NULL
argument_list|)
block|{         }
operator|~
name|ProcessRunLocker
argument_list|()
block|{
name|Unlock
argument_list|()
block|;         }
comment|// Try to lock the read lock, but only do so if there are no writers.
name|bool
name|TryLock
argument_list|(
argument|ProcessRunLock *lock
argument_list|)
block|{
if|if
condition|(
name|m_lock
condition|)
block|{
if|if
condition|(
name|m_lock
operator|==
name|lock
condition|)
return|return
name|true
return|;
comment|// We already have this lock locked
else|else
name|Unlock
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|lock
condition|)
block|{
if|if
condition|(
name|lock
operator|->
name|ReadTryLock
argument_list|()
condition|)
block|{
name|m_lock
operator|=
name|lock
expr_stmt|;
return|return
name|true
return|;
block|}
block|}
return|return
name|false
return|;
block|}
name|protected
label|:
name|void
name|Unlock
parameter_list|()
block|{
if|if
condition|(
name|m_lock
condition|)
block|{
name|m_lock
operator|->
name|ReadUnlock
argument_list|()
expr_stmt|;
name|m_lock
operator|=
name|NULL
expr_stmt|;
block|}
block|}
name|ProcessRunLock
modifier|*
name|m_lock
decl_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ProcessRunLocker
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
name|protected
label|:
name|pthread_rwlock_t
name|m_rwlock
decl_stmt|;
name|bool
name|m_running
decl_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ProcessRunLock
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
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_ProcessRunLock_h_
end_comment

end_unit

