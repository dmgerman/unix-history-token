begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PThreadMutex.h ------------------------------------------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|//  Created by Greg Clayton on 6/16/07.
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
name|__PThreadMutex_h__
end_ifndef

begin_define
define|#
directive|define
name|__PThreadMutex_h__
end_define

begin_include
include|#
directive|include
file|<assert.h>
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

begin_comment
comment|//#define DEBUG_PTHREAD_MUTEX_DEADLOCKS 1
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUG_PTHREAD_MUTEX_DEADLOCKS
argument_list|)
end_if

begin_define
define|#
directive|define
name|PTHREAD_MUTEX_LOCKER
parameter_list|(
name|var
parameter_list|,
name|mutex
parameter_list|)
define|\
value|PThreadMutex::Locker var(mutex, __FUNCTION__, __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PTHREAD_MUTEX_LOCKER
parameter_list|(
name|var
parameter_list|,
name|mutex
parameter_list|)
value|PThreadMutex::Locker var(mutex)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|class
name|PThreadMutex
block|{
name|public
label|:
name|class
name|Locker
block|{
name|public
label|:
if|#
directive|if
name|defined
argument_list|(
name|DEBUG_PTHREAD_MUTEX_DEADLOCKS
argument_list|)
name|Locker
argument_list|(
argument|PThreadMutex&m
argument_list|,
argument|const char *function
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
empty_stmt|;
name|Locker
argument_list|(
argument|PThreadMutex *m
argument_list|,
argument|const char *function
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
empty_stmt|;
name|Locker
argument_list|(
argument|pthread_mutex_t *mutex
argument_list|,
argument|const char *function
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
empty_stmt|;
operator|~
name|Locker
argument_list|()
expr_stmt|;
name|void
name|Lock
parameter_list|()
function_decl|;
name|void
name|Unlock
parameter_list|()
function_decl|;
else|#
directive|else
name|Locker
argument_list|(
name|PThreadMutex
operator|&
name|m
argument_list|)
operator|:
name|m_pMutex
argument_list|(
argument|m.Mutex()
argument_list|)
block|{
name|Lock
argument_list|()
block|; }
name|Locker
argument_list|(
name|PThreadMutex
operator|*
name|m
argument_list|)
operator|:
name|m_pMutex
argument_list|(
argument|m ? m->Mutex() : NULL
argument_list|)
block|{
name|Lock
argument_list|()
block|; }
name|Locker
argument_list|(
name|pthread_mutex_t
operator|*
name|mutex
argument_list|)
operator|:
name|m_pMutex
argument_list|(
argument|mutex
argument_list|)
block|{
name|Lock
argument_list|()
block|; }
name|void
name|Lock
argument_list|()
block|{
if|if
condition|(
name|m_pMutex
condition|)
operator|::
name|pthread_mutex_lock
argument_list|(
name|m_pMutex
argument_list|)
expr_stmt|;
block|}
name|void
name|Unlock
parameter_list|()
block|{
if|if
condition|(
name|m_pMutex
condition|)
operator|::
name|pthread_mutex_unlock
argument_list|(
name|m_pMutex
argument_list|)
expr_stmt|;
block|}
operator|~
name|Locker
argument_list|()
block|{
name|Unlock
argument_list|()
block|; }
endif|#
directive|endif
comment|// unlock any the current mutex and lock the new one if it is valid
name|void
name|Reset
argument_list|(
argument|pthread_mutex_t *pMutex = NULL
argument_list|)
block|{
name|Unlock
argument_list|()
block|;
name|m_pMutex
operator|=
name|pMutex
block|;
name|Lock
argument_list|()
block|;     }
name|pthread_mutex_t
operator|*
name|m_pMutex
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|DEBUG_PTHREAD_MUTEX_DEADLOCKS
argument_list|)
specifier|const
name|char
modifier|*
name|m_function
decl_stmt|;
specifier|const
name|char
modifier|*
name|m_file
decl_stmt|;
name|int
name|m_line
decl_stmt|;
name|uint64_t
name|m_lock_time
decl_stmt|;
endif|#
directive|endif
block|}
empty_stmt|;
name|PThreadMutex
argument_list|()
block|{
name|int
name|err
decl_stmt|;
name|err
operator|=
operator|::
name|pthread_mutex_init
argument_list|(
operator|&
name|m_mutex
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|err
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
name|PThreadMutex
argument_list|(
argument|int type
argument_list|)
block|{
name|int
name|err
decl_stmt|;
operator|::
name|pthread_mutexattr_t
name|attr
expr_stmt|;
name|err
operator|=
operator|::
name|pthread_mutexattr_init
argument_list|(
operator|&
name|attr
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|err
operator|==
literal|0
argument_list|)
expr_stmt|;
name|err
operator|=
operator|::
name|pthread_mutexattr_settype
argument_list|(
operator|&
name|attr
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|err
operator|==
literal|0
argument_list|)
expr_stmt|;
name|err
operator|=
operator|::
name|pthread_mutex_init
argument_list|(
operator|&
name|m_mutex
argument_list|,
operator|&
name|attr
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|err
operator|==
literal|0
argument_list|)
expr_stmt|;
name|err
operator|=
operator|::
name|pthread_mutexattr_destroy
argument_list|(
operator|&
name|attr
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|err
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
operator|~
name|PThreadMutex
argument_list|()
block|{
name|int
name|err
block|;
name|err
operator|=
operator|::
name|pthread_mutex_destroy
argument_list|(
operator|&
name|m_mutex
argument_list|)
block|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
block|{
name|err
operator|=
name|Unlock
argument_list|()
expr_stmt|;
if|if
condition|(
name|err
operator|==
literal|0
condition|)
operator|::
name|pthread_mutex_destroy
argument_list|(
operator|&
name|m_mutex
argument_list|)
expr_stmt|;
block|}
block|}
name|pthread_mutex_t
operator|*
name|Mutex
argument_list|()
block|{
return|return
operator|&
name|m_mutex
return|;
block|}
name|int
name|Lock
parameter_list|()
block|{
return|return
operator|::
name|pthread_mutex_lock
argument_list|(
operator|&
name|m_mutex
argument_list|)
return|;
block|}
name|int
name|Unlock
parameter_list|()
block|{
return|return
operator|::
name|pthread_mutex_unlock
argument_list|(
operator|&
name|m_mutex
argument_list|)
return|;
block|}
name|protected
label|:
name|pthread_mutex_t
name|m_mutex
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

