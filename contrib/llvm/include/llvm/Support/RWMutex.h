begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- RWMutex.h - Reader/Writer Mutual Exclusion Lock ----------*- C++ -*-===//
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
comment|// This file declares the llvm::sys::RWMutex class.
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
name|LLVM_SUPPORT_RWMUTEX_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_RWMUTEX_H
end_define

begin_include
include|#
directive|include
file|"llvm/Config/llvm-config.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Threading.h"
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
comment|/// @brief Platform agnostic RWMutex class.
name|class
name|RWMutexImpl
block|{
comment|/// @name Constructors
comment|/// @{
name|public
label|:
comment|/// Initializes the lock but doesn't acquire it.
comment|/// @brief Default Constructor.
name|explicit
name|RWMutexImpl
parameter_list|()
function_decl|;
comment|/// @}
comment|/// @name Do Not Implement
comment|/// @{
name|RWMutexImpl
argument_list|(
specifier|const
name|RWMutexImpl
operator|&
name|original
argument_list|)
operator|=
name|delete
expr_stmt|;
name|RWMutexImpl
modifier|&
name|operator
init|=
operator|(
specifier|const
name|RWMutexImpl
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
comment|/// @}
comment|/// Releases and removes the lock
comment|/// @brief Destructor
operator|~
name|RWMutexImpl
argument_list|()
expr_stmt|;
comment|/// @}
comment|/// @name Methods
comment|/// @{
name|public
label|:
comment|/// Attempts to unconditionally acquire the lock in reader mode. If the
comment|/// lock is held by a writer, this method will wait until it can acquire
comment|/// the lock.
comment|/// @returns false if any kind of error occurs, true otherwise.
comment|/// @brief Unconditionally acquire the lock in reader mode.
name|bool
name|reader_acquire
parameter_list|()
function_decl|;
comment|/// Attempts to release the lock in reader mode.
comment|/// @returns false if any kind of error occurs, true otherwise.
comment|/// @brief Unconditionally release the lock in reader mode.
name|bool
name|reader_release
parameter_list|()
function_decl|;
comment|/// Attempts to unconditionally acquire the lock in reader mode. If the
comment|/// lock is held by any readers, this method will wait until it can
comment|/// acquire the lock.
comment|/// @returns false if any kind of error occurs, true otherwise.
comment|/// @brief Unconditionally acquire the lock in writer mode.
name|bool
name|writer_acquire
parameter_list|()
function_decl|;
comment|/// Attempts to release the lock in writer mode.
comment|/// @returns false if any kind of error occurs, true otherwise.
comment|/// @brief Unconditionally release the lock in write mode.
name|bool
name|writer_release
parameter_list|()
function_decl|;
comment|//@}
comment|/// @name Platform Dependent Data
comment|/// @{
name|private
label|:
if|#
directive|if
name|defined
argument_list|(
name|LLVM_ENABLE_THREADS
argument_list|)
operator|&&
name|LLVM_ENABLE_THREADS
operator|!=
literal|0
name|void
modifier|*
name|data_
init|=
name|nullptr
decl_stmt|;
comment|///< We don't know what the data will be
endif|#
directive|endif
block|}
empty_stmt|;
comment|/// SmartMutex - An R/W mutex with a compile time constant parameter that
comment|/// indicates whether this mutex should become a no-op when we're not
comment|/// running in multithreaded mode.
name|template
operator|<
name|bool
name|mt_only
operator|>
name|class
name|SmartRWMutex
block|{
name|RWMutexImpl
name|impl
block|;
name|unsigned
name|readers
operator|=
literal|0
block|;
name|unsigned
name|writers
operator|=
literal|0
block|;
name|public
operator|:
name|explicit
name|SmartRWMutex
argument_list|()
operator|=
expr|default
block|;
name|SmartRWMutex
argument_list|(
specifier|const
name|SmartRWMutex
operator|<
name|mt_only
operator|>
operator|&
name|original
argument_list|)
operator|=
name|delete
block|;
name|SmartRWMutex
operator|<
name|mt_only
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|SmartRWMutex
operator|<
name|mt_only
operator|>
operator|&
operator|)
operator|=
name|delete
block|;
name|bool
name|lock_shared
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
name|impl
operator|.
name|reader_acquire
argument_list|()
return|;
comment|// Single-threaded debugging code.  This would be racy in multithreaded
comment|// mode, but provides not sanity checks in single threaded mode.
operator|++
name|readers
block|;
return|return
name|true
return|;
block|}
name|bool
name|unlock_shared
parameter_list|()
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
name|impl
operator|.
name|reader_release
argument_list|()
return|;
comment|// Single-threaded debugging code.  This would be racy in multithreaded
comment|// mode, but provides not sanity checks in single threaded mode.
name|assert
argument_list|(
name|readers
operator|>
literal|0
operator|&&
literal|"Reader lock not acquired before release!"
argument_list|)
expr_stmt|;
operator|--
name|readers
expr_stmt|;
return|return
name|true
return|;
block|}
name|bool
name|lock
parameter_list|()
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
name|impl
operator|.
name|writer_acquire
argument_list|()
return|;
comment|// Single-threaded debugging code.  This would be racy in multithreaded
comment|// mode, but provides not sanity checks in single threaded mode.
name|assert
argument_list|(
name|writers
operator|==
literal|0
operator|&&
literal|"Writer lock already acquired!"
argument_list|)
expr_stmt|;
operator|++
name|writers
expr_stmt|;
return|return
name|true
return|;
block|}
name|bool
name|unlock
parameter_list|()
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
name|impl
operator|.
name|writer_release
argument_list|()
return|;
comment|// Single-threaded debugging code.  This would be racy in multithreaded
comment|// mode, but provides not sanity checks in single threaded mode.
name|assert
argument_list|(
name|writers
operator|==
literal|1
operator|&&
literal|"Writer lock not acquired before release!"
argument_list|)
expr_stmt|;
operator|--
name|writers
expr_stmt|;
return|return
name|true
return|;
block|}
block|}
empty_stmt|;
typedef|typedef
name|SmartRWMutex
operator|<
name|false
operator|>
name|RWMutex
expr_stmt|;
comment|/// ScopedReader - RAII acquisition of a reader lock
name|template
operator|<
name|bool
name|mt_only
operator|>
expr|struct
name|SmartScopedReader
block|{
name|SmartRWMutex
operator|<
name|mt_only
operator|>
operator|&
name|mutex
block|;
name|explicit
name|SmartScopedReader
argument_list|(
name|SmartRWMutex
operator|<
name|mt_only
operator|>
operator|&
name|m
argument_list|)
operator|:
name|mutex
argument_list|(
argument|m
argument_list|)
block|{
name|mutex
operator|.
name|lock_shared
argument_list|()
block|;       }
operator|~
name|SmartScopedReader
argument_list|()
block|{
name|mutex
operator|.
name|unlock_shared
argument_list|()
block|;       }
block|}
expr_stmt|;
typedef|typedef
name|SmartScopedReader
operator|<
name|false
operator|>
name|ScopedReader
expr_stmt|;
comment|/// ScopedWriter - RAII acquisition of a writer lock
name|template
operator|<
name|bool
name|mt_only
operator|>
expr|struct
name|SmartScopedWriter
block|{
name|SmartRWMutex
operator|<
name|mt_only
operator|>
operator|&
name|mutex
block|;
name|explicit
name|SmartScopedWriter
argument_list|(
name|SmartRWMutex
operator|<
name|mt_only
operator|>
operator|&
name|m
argument_list|)
operator|:
name|mutex
argument_list|(
argument|m
argument_list|)
block|{
name|mutex
operator|.
name|lock
argument_list|()
block|;       }
operator|~
name|SmartScopedWriter
argument_list|()
block|{
name|mutex
operator|.
name|unlock
argument_list|()
block|;       }
block|}
expr_stmt|;
typedef|typedef
name|SmartScopedWriter
operator|<
name|false
operator|>
name|ScopedWriter
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace sys
end_comment

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_RWMUTEX_H
end_comment

end_unit

