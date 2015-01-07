begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_deadlock_detector_interface.h -----------------*- C++ -*-===//
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
comment|// This file is a part of Sanitizer runtime.
end_comment

begin_comment
comment|// Abstract deadlock detector interface.
end_comment

begin_comment
comment|// FIXME: this is work in progress, nothing really works yet.
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
name|SANITIZER_DEADLOCK_DETECTOR_INTERFACE_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_DEADLOCK_DETECTOR_INTERFACE_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_DEADLOCK_DETECTOR_VERSION
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_DEADLOCK_DETECTOR_VERSION
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_atomic.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
comment|// dd - deadlock detector.
comment|// lt - logical (user) thread.
comment|// pt - physical (OS) thread.
struct_decl|struct
name|DDPhysicalThread
struct_decl|;
struct_decl|struct
name|DDLogicalThread
struct_decl|;
struct|struct
name|DDMutex
block|{
if|#
directive|if
name|SANITIZER_DEADLOCK_DETECTOR_VERSION
operator|==
literal|1
name|uptr
name|id
decl_stmt|;
name|u32
name|stk
decl_stmt|;
comment|// creation stack
elif|#
directive|elif
name|SANITIZER_DEADLOCK_DETECTOR_VERSION
operator|==
literal|2
name|u32
name|id
decl_stmt|;
name|u32
name|recursion
decl_stmt|;
name|atomic_uintptr_t
name|owner
decl_stmt|;
else|#
directive|else
error|#
directive|error
literal|"BAD SANITIZER_DEADLOCK_DETECTOR_VERSION"
endif|#
directive|endif
name|u64
name|ctx
decl_stmt|;
block|}
struct|;
struct|struct
name|DDFlags
block|{
name|bool
name|second_deadlock_stack
decl_stmt|;
block|}
struct|;
struct|struct
name|DDReport
block|{
enum|enum
block|{
name|kMaxLoopSize
init|=
literal|8
block|}
enum|;
name|int
name|n
decl_stmt|;
comment|// number of entries in loop
struct|struct
block|{
name|u64
name|thr_ctx
decl_stmt|;
comment|// user thread context
name|u64
name|mtx_ctx0
decl_stmt|;
comment|// user mutex context, start of the edge
name|u64
name|mtx_ctx1
decl_stmt|;
comment|// user mutex context, end of the edge
name|u32
name|stk
index|[
literal|2
index|]
decl_stmt|;
comment|// stack ids for the edge
block|}
name|loop
index|[
name|kMaxLoopSize
index|]
struct|;
block|}
struct|;
struct|struct
name|DDCallback
block|{
name|DDPhysicalThread
modifier|*
name|pt
decl_stmt|;
name|DDLogicalThread
modifier|*
name|lt
decl_stmt|;
name|virtual
name|u32
name|Unwind
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|int
name|UniqueTid
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
block|}
struct|;
struct|struct
name|DDetector
block|{
specifier|static
name|DDetector
modifier|*
name|Create
parameter_list|(
specifier|const
name|DDFlags
modifier|*
name|flags
parameter_list|)
function_decl|;
name|virtual
name|DDPhysicalThread
modifier|*
name|CreatePhysicalThread
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|void
name|DestroyPhysicalThread
parameter_list|(
name|DDPhysicalThread
modifier|*
name|pt
parameter_list|)
block|{}
name|virtual
name|DDLogicalThread
modifier|*
name|CreateLogicalThread
parameter_list|(
name|u64
name|ctx
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|void
name|DestroyLogicalThread
parameter_list|(
name|DDLogicalThread
modifier|*
name|lt
parameter_list|)
block|{}
name|virtual
name|void
name|MutexInit
parameter_list|(
name|DDCallback
modifier|*
name|cb
parameter_list|,
name|DDMutex
modifier|*
name|m
parameter_list|)
block|{}
name|virtual
name|void
name|MutexBeforeLock
parameter_list|(
name|DDCallback
modifier|*
name|cb
parameter_list|,
name|DDMutex
modifier|*
name|m
parameter_list|,
name|bool
name|wlock
parameter_list|)
block|{}
name|virtual
name|void
name|MutexAfterLock
parameter_list|(
name|DDCallback
modifier|*
name|cb
parameter_list|,
name|DDMutex
modifier|*
name|m
parameter_list|,
name|bool
name|wlock
parameter_list|,
name|bool
name|trylock
parameter_list|)
block|{}
name|virtual
name|void
name|MutexBeforeUnlock
parameter_list|(
name|DDCallback
modifier|*
name|cb
parameter_list|,
name|DDMutex
modifier|*
name|m
parameter_list|,
name|bool
name|wlock
parameter_list|)
block|{}
name|virtual
name|void
name|MutexDestroy
parameter_list|(
name|DDCallback
modifier|*
name|cb
parameter_list|,
name|DDMutex
modifier|*
name|m
parameter_list|)
block|{}
name|virtual
name|DDReport
modifier|*
name|GetReport
parameter_list|(
name|DDCallback
modifier|*
name|cb
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_DEADLOCK_DETECTOR_INTERFACE_H
end_comment

end_unit

