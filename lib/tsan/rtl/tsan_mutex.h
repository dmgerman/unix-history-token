begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tsan_mutex.h --------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of ThreadSanitizer (TSan), a race detector.
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
name|TSAN_MUTEX_H
end_ifndef

begin_define
define|#
directive|define
name|TSAN_MUTEX_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_atomic.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_mutex.h"
end_include

begin_include
include|#
directive|include
file|"tsan_defs.h"
end_include

begin_decl_stmt
name|namespace
name|__tsan
block|{
enum|enum
name|MutexType
block|{
name|MutexTypeInvalid
block|,
name|MutexTypeTrace
block|,
name|MutexTypeThreads
block|,
name|MutexTypeReport
block|,
name|MutexTypeSyncVar
block|,
name|MutexTypeSyncTab
block|,
name|MutexTypeSlab
block|,
name|MutexTypeAnnotations
block|,
name|MutexTypeAtExit
block|,
name|MutexTypeMBlock
block|,
name|MutexTypeJavaMBlock
block|,
name|MutexTypeDDetector
block|,
comment|// This must be the last.
name|MutexTypeCount
block|}
enum|;
name|class
name|Mutex
block|{
name|public
label|:
name|explicit
name|Mutex
parameter_list|(
name|MutexType
name|type
parameter_list|,
name|StatType
name|stat_type
parameter_list|)
function_decl|;
operator|~
name|Mutex
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
name|void
name|ReadLock
parameter_list|()
function_decl|;
name|void
name|ReadUnlock
parameter_list|()
function_decl|;
name|void
name|CheckLocked
parameter_list|()
function_decl|;
name|private
label|:
name|atomic_uintptr_t
name|state_
decl_stmt|;
if|#
directive|if
name|TSAN_DEBUG
name|MutexType
name|type_
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|TSAN_COLLECT_STATS
name|StatType
name|stat_type_
decl_stmt|;
endif|#
directive|endif
name|Mutex
argument_list|(
specifier|const
name|Mutex
operator|&
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
block|}
empty_stmt|;
typedef|typedef
name|GenericScopedLock
operator|<
name|Mutex
operator|>
name|Lock
expr_stmt|;
typedef|typedef
name|GenericScopedReadLock
operator|<
name|Mutex
operator|>
name|ReadLock
expr_stmt|;
name|class
name|InternalDeadlockDetector
block|{
name|public
label|:
name|InternalDeadlockDetector
argument_list|()
expr_stmt|;
name|void
name|Lock
parameter_list|(
name|MutexType
name|t
parameter_list|)
function_decl|;
name|void
name|Unlock
parameter_list|(
name|MutexType
name|t
parameter_list|)
function_decl|;
name|void
name|CheckNoLocks
parameter_list|()
function_decl|;
name|private
label|:
name|u64
name|seq_
decl_stmt|;
name|u64
name|locked_
index|[
name|MutexTypeCount
index|]
decl_stmt|;
block|}
empty_stmt|;
name|void
name|InitializeMutex
parameter_list|()
function_decl|;
comment|// Checks that the current thread does not hold any runtime locks
comment|// (e.g. when returning from an interceptor).
name|void
name|CheckNoLocks
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __tsan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TSAN_MUTEX_H
end_comment

end_unit

