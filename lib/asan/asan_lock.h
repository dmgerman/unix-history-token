begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_lock.h ---------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of AddressSanitizer, an address sanity checker.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A wrapper for a simple lock.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_LOCK_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_LOCK_H
end_define

begin_include
include|#
directive|include
file|"asan_internal.h"
end_include

begin_comment
comment|// The locks in ASan are global objects and they are never destroyed to avoid
end_comment

begin_comment
comment|// at-exit races (that is, a lock is being used by other threads while the main
end_comment

begin_comment
comment|// thread is doing atexit destructors).
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<libkern/OSAtomic.h>
end_include

begin_decl_stmt
name|namespace
name|__asan
block|{
name|class
name|AsanLock
block|{
name|public
label|:
name|explicit
name|AsanLock
argument_list|(
name|LinkerInitialized
argument_list|)
operator|:
name|mu_
argument_list|(
name|OS_SPINLOCK_INIT
argument_list|)
operator|,
name|owner_
argument_list|(
literal|0
argument_list|)
operator|,
name|is_locked_
argument_list|(
argument|false
argument_list|)
block|{}
name|void
name|Lock
argument_list|()
block|{
name|CHECK
argument_list|(
name|owner_
operator|!=
name|pthread_self
argument_list|()
argument_list|)
block|;
name|OSSpinLockLock
argument_list|(
operator|&
name|mu_
argument_list|)
block|;
name|is_locked_
operator|=
name|true
block|;
name|owner_
operator|=
name|pthread_self
argument_list|()
block|;   }
name|void
name|Unlock
argument_list|()
block|{
name|owner_
operator|=
literal|0
block|;
name|is_locked_
operator|=
name|false
block|;
name|OSSpinLockUnlock
argument_list|(
operator|&
name|mu_
argument_list|)
block|;   }
name|bool
name|IsLocked
argument_list|()
block|{
comment|// This is not atomic, e.g. one thread may get different values if another
comment|// one is about to release the lock.
return|return
name|is_locked_
return|;
block|}
name|private
label|:
name|OSSpinLock
name|mu_
decl_stmt|;
specifier|volatile
name|pthread_t
name|owner_
decl_stmt|;
comment|// for debugging purposes
name|bool
name|is_locked_
decl_stmt|;
comment|// for silly malloc_introspection_t interface
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __asan
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// assume linux
end_comment

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_decl_stmt
name|namespace
name|__asan
block|{
name|class
name|AsanLock
block|{
name|public
label|:
name|explicit
name|AsanLock
parameter_list|(
name|LinkerInitialized
parameter_list|)
block|{
comment|// We assume that pthread_mutex_t initialized to all zeroes is a valid
comment|// unlocked mutex. We can not use PTHREAD_MUTEX_INITIALIZER as it triggers
comment|// a gcc warning:
comment|// extended initializer lists only available with -std=c++0x or -std=gnu++0x
block|}
name|void
name|Lock
parameter_list|()
block|{
name|pthread_mutex_lock
argument_list|(
operator|&
name|mu_
argument_list|)
expr_stmt|;
comment|// pthread_spin_lock(&mu_);
block|}
name|void
name|Unlock
parameter_list|()
block|{
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mu_
argument_list|)
expr_stmt|;
comment|// pthread_spin_unlock(&mu_);
block|}
name|private
label|:
name|pthread_mutex_t
name|mu_
decl_stmt|;
comment|// pthread_spinlock_t mu_;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __asan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|__asan
block|{
name|class
name|ScopedLock
block|{
name|public
label|:
name|explicit
name|ScopedLock
argument_list|(
name|AsanLock
operator|*
name|mu
argument_list|)
operator|:
name|mu_
argument_list|(
argument|mu
argument_list|)
block|{
name|mu_
operator|->
name|Lock
argument_list|()
block|;   }
operator|~
name|ScopedLock
argument_list|()
block|{
name|mu_
operator|->
name|Unlock
argument_list|()
block|;   }
name|private
operator|:
name|AsanLock
operator|*
name|mu_
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __asan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_LOCK_H
end_comment

end_unit

