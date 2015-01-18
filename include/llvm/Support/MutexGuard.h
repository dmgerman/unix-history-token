begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Support/MutexGuard.h - Acquire/Release Mutex In Scope ---*- C++ -*-===//
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
name|LLVM_SUPPORT_MUTEXGUARD_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_MUTEXGUARD_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Mutex.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Instances of this class acquire a given Mutex Lock when constructed and
comment|/// hold that lock until destruction. The intention is to instantiate one of
comment|/// these on the stack at the top of some scope to be assured that C++
comment|/// destruction of the object will always release the Mutex and thus avoid
comment|/// a host of nasty multi-threading problems in the face of exceptions, etc.
comment|/// @brief Guard a section of code with a Mutex.
name|class
name|MutexGuard
block|{
name|sys
operator|::
name|Mutex
operator|&
name|M
expr_stmt|;
name|MutexGuard
argument_list|(
argument|const MutexGuard&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|MutexGuard
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|public
label|:
name|MutexGuard
argument_list|(
name|sys
operator|::
name|Mutex
operator|&
name|m
argument_list|)
operator|:
name|M
argument_list|(
argument|m
argument_list|)
block|{
name|M
operator|.
name|lock
argument_list|()
block|; }
operator|~
name|MutexGuard
argument_list|()
block|{
name|M
operator|.
name|unlock
argument_list|()
block|; }
comment|/// holds - Returns true if this locker instance holds the specified lock.
comment|/// This is mostly used in assertions to validate that the correct mutex
comment|/// is held.
name|bool
name|holds
argument_list|(
argument|const sys::Mutex& lock
argument_list|)
specifier|const
block|{
return|return
operator|&
name|M
operator|==
operator|&
name|lock
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_MUTEXGUARD_H
end_comment

end_unit

