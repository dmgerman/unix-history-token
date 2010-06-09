begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/System/Mutex.h - Mutex Operating System Concept -----*- C++ -*-===//
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
comment|// This file declares the llvm::sys::Mutex class.
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
name|LLVM_SYSTEM_MUTEX_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SYSTEM_MUTEX_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/Threading.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
comment|/// @brief Platform agnostic Mutex class.
name|class
name|MutexImpl
block|{
comment|/// @name Constructors
comment|/// @{
name|public
label|:
comment|/// Initializes the lock but doesn't acquire it. if \p recursive is set
comment|/// to false, the lock will not be recursive which makes it cheaper but
comment|/// also more likely to deadlock (same thread can't acquire more than
comment|/// once).
comment|/// @brief Default Constructor.
name|explicit
name|MutexImpl
parameter_list|(
name|bool
name|recursive
init|=
name|true
parameter_list|)
function_decl|;
comment|/// Releases and removes the lock
comment|/// @brief Destructor
operator|~
name|MutexImpl
argument_list|()
expr_stmt|;
comment|/// @}
comment|/// @name Methods
comment|/// @{
name|public
label|:
comment|/// Attempts to unconditionally acquire the lock. If the lock is held by
comment|/// another thread, this method will wait until it can acquire the lock.
comment|/// @returns false if any kind of error occurs, true otherwise.
comment|/// @brief Unconditionally acquire the lock.
name|bool
name|acquire
parameter_list|()
function_decl|;
comment|/// Attempts to release the lock. If the lock is held by the current
comment|/// thread, the lock is released allowing other threads to acquire the
comment|/// lock.
comment|/// @returns false if any kind of error occurs, true otherwise.
comment|/// @brief Unconditionally release the lock.
name|bool
name|release
parameter_list|()
function_decl|;
comment|/// Attempts to acquire the lock without blocking. If the lock is not
comment|/// available, this function returns false quickly (without blocking). If
comment|/// the lock is available, it is acquired.
comment|/// @returns false if any kind of error occurs or the lock is not
comment|/// available, true otherwise.
comment|/// @brief Try to acquire the lock.
name|bool
name|tryacquire
parameter_list|()
function_decl|;
comment|//@}
comment|/// @name Platform Dependent Data
comment|/// @{
name|private
label|:
name|void
modifier|*
name|data_
decl_stmt|;
comment|///< We don't know what the data will be
comment|/// @}
comment|/// @name Do Not Implement
comment|/// @{
name|private
label|:
name|MutexImpl
argument_list|(
specifier|const
name|MutexImpl
operator|&
name|original
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|MutexImpl
operator|&
operator|)
decl_stmt|;
comment|/// @}
block|}
empty_stmt|;
comment|/// SmartMutex - A mutex with a compile time constant parameter that
comment|/// indicates whether this mutex should become a no-op when we're not
comment|/// running in multithreaded mode.
name|template
operator|<
name|bool
name|mt_only
operator|>
name|class
name|SmartMutex
operator|:
name|public
name|MutexImpl
block|{
name|unsigned
name|acquired
block|;
name|bool
name|recursive
block|;
name|public
operator|:
name|explicit
name|SmartMutex
argument_list|(
argument|bool rec = true
argument_list|)
operator|:
name|MutexImpl
argument_list|(
name|rec
argument_list|)
block|,
name|acquired
argument_list|(
literal|0
argument_list|)
block|,
name|recursive
argument_list|(
argument|rec
argument_list|)
block|{ }
name|bool
name|acquire
argument_list|()
block|{
if|if
condition|(
operator|!
name|mt_only
operator|||
name|llvm_is_multithreaded
argument_list|()
condition|)
block|{
return|return
name|MutexImpl
operator|::
name|acquire
argument_list|()
return|;
block|}
else|else
block|{
comment|// Single-threaded debugging code.  This would be racy in
comment|// multithreaded mode, but provides not sanity checks in single
comment|// threaded mode.
name|assert
argument_list|(
operator|(
name|recursive
operator|||
name|acquired
operator|==
literal|0
operator|)
operator|&&
literal|"Lock already acquired!!"
argument_list|)
expr_stmt|;
operator|++
name|acquired
expr_stmt|;
return|return
name|true
return|;
block|}
block|}
name|bool
name|release
argument_list|()
block|{
if|if
condition|(
operator|!
name|mt_only
operator|||
name|llvm_is_multithreaded
argument_list|()
condition|)
block|{
return|return
name|MutexImpl
operator|::
name|release
argument_list|()
return|;
block|}
else|else
block|{
comment|// Single-threaded debugging code.  This would be racy in
comment|// multithreaded mode, but provides not sanity checks in single
comment|// threaded mode.
name|assert
argument_list|(
operator|(
operator|(
name|recursive
operator|&&
name|acquired
operator|)
operator|||
operator|(
name|acquired
operator|==
literal|1
operator|)
operator|)
operator|&&
literal|"Lock not acquired before release!"
argument_list|)
expr_stmt|;
operator|--
name|acquired
expr_stmt|;
return|return
name|true
return|;
block|}
block|}
name|bool
name|tryacquire
argument_list|()
block|{
if|if
condition|(
operator|!
name|mt_only
operator|||
name|llvm_is_multithreaded
argument_list|()
condition|)
return|return
name|MutexImpl
operator|::
name|tryacquire
argument_list|()
return|;
else|else
return|return
name|true
return|;
block|}
name|private
operator|:
name|SmartMutex
argument_list|(
specifier|const
name|SmartMutex
operator|<
name|mt_only
operator|>
operator|&
name|original
argument_list|)
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|SmartMutex
operator|<
name|mt_only
operator|>
operator|&
operator|)
block|;     }
expr_stmt|;
comment|/// Mutex - A standard, always enforced mutex.
typedef|typedef
name|SmartMutex
operator|<
name|false
operator|>
name|Mutex
expr_stmt|;
name|template
operator|<
name|bool
name|mt_only
operator|>
name|class
name|SmartScopedLock
block|{
name|SmartMutex
operator|<
name|mt_only
operator|>
operator|&
name|mtx
block|;
name|public
operator|:
name|SmartScopedLock
argument_list|(
name|SmartMutex
operator|<
name|mt_only
operator|>
operator|&
name|m
argument_list|)
operator|:
name|mtx
argument_list|(
argument|m
argument_list|)
block|{
name|mtx
operator|.
name|acquire
argument_list|()
block|;       }
operator|~
name|SmartScopedLock
argument_list|()
block|{
name|mtx
operator|.
name|release
argument_list|()
block|;       }
block|}
expr_stmt|;
typedef|typedef
name|SmartScopedLock
operator|<
name|false
operator|>
name|ScopedLock
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

