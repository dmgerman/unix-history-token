begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- dd_rtl.h ----------------------------------------------------------===//
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
name|DD_RTL_H
end_ifndef

begin_define
define|#
directive|define
name|DD_RTL_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_internal_defs.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_deadlock_detector_interface.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_flags.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_allocator_internal.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_addrhashmap.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_mutex.h"
end_include

begin_decl_stmt
name|namespace
name|__dsan
block|{
typedef|typedef
name|DDFlags
name|Flags
typedef|;
struct|struct
name|Mutex
block|{
name|DDMutex
name|dd
decl_stmt|;
block|}
struct|;
struct|struct
name|Thread
block|{
name|DDPhysicalThread
modifier|*
name|dd_pt
decl_stmt|;
name|DDLogicalThread
modifier|*
name|dd_lt
decl_stmt|;
name|bool
name|ignore_interceptors
decl_stmt|;
block|}
struct|;
name|struct
name|Callback
range|:
name|DDCallback
block|{
name|Thread
operator|*
name|thr
block|;
name|Callback
argument_list|(
name|Thread
operator|*
name|thr
argument_list|)
block|;
name|virtual
name|u32
name|Unwind
argument_list|()
block|; }
decl_stmt|;
typedef|typedef
name|AddrHashMap
operator|<
name|Mutex
operator|,
literal|31051
operator|>
name|MutexHashMap
expr_stmt|;
struct|struct
name|Context
block|{
name|DDetector
modifier|*
name|dd
decl_stmt|;
name|BlockingMutex
name|report_mutex
decl_stmt|;
name|MutexHashMap
name|mutex_map
decl_stmt|;
block|}
struct|;
specifier|inline
name|Flags
modifier|*
name|flags
parameter_list|()
block|{
specifier|static
name|Flags
name|flags
decl_stmt|;
return|return
operator|&
name|flags
return|;
block|}
name|void
name|Initialize
parameter_list|()
function_decl|;
name|void
name|InitializeInterceptors
parameter_list|()
function_decl|;
name|void
name|ThreadInit
parameter_list|(
name|Thread
modifier|*
name|thr
parameter_list|)
function_decl|;
name|void
name|ThreadDestroy
parameter_list|(
name|Thread
modifier|*
name|thr
parameter_list|)
function_decl|;
name|void
name|MutexBeforeLock
parameter_list|(
name|Thread
modifier|*
name|thr
parameter_list|,
name|uptr
name|m
parameter_list|,
name|bool
name|writelock
parameter_list|)
function_decl|;
name|void
name|MutexAfterLock
parameter_list|(
name|Thread
modifier|*
name|thr
parameter_list|,
name|uptr
name|m
parameter_list|,
name|bool
name|writelock
parameter_list|,
name|bool
name|trylock
parameter_list|)
function_decl|;
name|void
name|MutexBeforeUnlock
parameter_list|(
name|Thread
modifier|*
name|thr
parameter_list|,
name|uptr
name|m
parameter_list|,
name|bool
name|writelock
parameter_list|)
function_decl|;
name|void
name|MutexDestroy
parameter_list|(
name|Thread
modifier|*
name|thr
parameter_list|,
name|uptr
name|m
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __dsan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// DD_RTL_H
end_comment

end_unit

