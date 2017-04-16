begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Support/UniqueLock.h - Acquire/Release Mutex In Scope ----*- C++ -*-===//
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
comment|// This file defines a guard for a block of code that ensures a Mutex is locked
end_comment

begin_comment
comment|// upon construction and released upon destruction.
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
name|LLVM_SUPPORT_UNIQUE_LOCK_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_UNIQUE_LOCK_H
end_define

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// A pared-down imitation of std::unique_lock from C++11. Contrary to the
comment|/// name, it's really more of a wrapper for a lock. It may or may not have
comment|/// an associated mutex, which is guaranteed to be locked upon creation
comment|/// and unlocked after destruction. unique_lock can also unlock the mutex
comment|/// and re-lock it freely during its lifetime.
comment|/// @brief Guard a section of code with a mutex.
name|template
operator|<
name|typename
name|MutexT
operator|>
name|class
name|unique_lock
block|{
name|MutexT
operator|*
name|M
operator|=
name|nullptr
block|;
name|bool
name|locked
operator|=
name|false
block|;
name|public
operator|:
name|unique_lock
argument_list|()
operator|=
expr|default
block|;
name|explicit
name|unique_lock
argument_list|(
name|MutexT
operator|&
name|m
argument_list|)
operator|:
name|M
argument_list|(
operator|&
name|m
argument_list|)
block|,
name|locked
argument_list|(
argument|true
argument_list|)
block|{
name|M
operator|->
name|lock
argument_list|()
block|; }
name|unique_lock
argument_list|(
specifier|const
name|unique_lock
operator|&
argument_list|)
operator|=
name|delete
block|;
name|unique_lock
operator|&
name|operator
operator|=
operator|(
specifier|const
name|unique_lock
operator|&
operator|)
operator|=
name|delete
block|;
name|void
name|operator
operator|=
operator|(
name|unique_lock
operator|&&
name|o
operator|)
block|{
if|if
condition|(
name|owns_lock
argument_list|()
condition|)
name|M
operator|->
name|unlock
argument_list|()
expr_stmt|;
name|M
operator|=
name|o
operator|.
name|M
block|;
name|locked
operator|=
name|o
operator|.
name|locked
block|;
name|o
operator|.
name|M
operator|=
name|nullptr
block|;
name|o
operator|.
name|locked
operator|=
name|false
block|;     }
operator|~
name|unique_lock
argument_list|()
block|{
if|if
condition|(
name|owns_lock
argument_list|()
condition|)
name|M
operator|->
name|unlock
argument_list|()
expr_stmt|;
block|}
name|void
name|lock
parameter_list|()
block|{
name|assert
argument_list|(
operator|!
name|locked
operator|&&
literal|"mutex already locked!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|M
operator|&&
literal|"no associated mutex!"
argument_list|)
expr_stmt|;
name|M
operator|->
name|lock
argument_list|()
expr_stmt|;
name|locked
operator|=
name|true
expr_stmt|;
block|}
name|void
name|unlock
parameter_list|()
block|{
name|assert
argument_list|(
name|locked
operator|&&
literal|"unlocking a mutex that isn't locked!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|M
operator|&&
literal|"no associated mutex!"
argument_list|)
expr_stmt|;
name|M
operator|->
name|unlock
argument_list|()
expr_stmt|;
name|locked
operator|=
name|false
expr_stmt|;
block|}
name|bool
name|owns_lock
parameter_list|()
block|{
return|return
name|locked
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_UNIQUE_LOCK_H
end_comment

end_unit

