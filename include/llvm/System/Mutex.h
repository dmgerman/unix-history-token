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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
comment|/// @brief Platform agnostic Mutex class.
name|class
name|Mutex
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
name|Mutex
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
name|Mutex
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
ifdef|#
directive|ifdef
name|ENABLE_THREADS
name|void
modifier|*
name|data_
decl_stmt|;
comment|///< We don't know what the data will be
endif|#
directive|endif
comment|/// @}
comment|/// @name Do Not Implement
comment|/// @{
name|private
label|:
name|Mutex
argument_list|(
specifier|const
name|Mutex
operator|&
name|original
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|Mutex
operator|&
operator|)
decl_stmt|;
comment|/// @}
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

