begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tsan_sync.h ---------------------------------------------*- C++ -*-===//
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
name|TSAN_SYNC_H
end_ifndef

begin_define
define|#
directive|define
name|TSAN_SYNC_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_atomic.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_common.h"
end_include

begin_include
include|#
directive|include
file|"tsan_clock.h"
end_include

begin_include
include|#
directive|include
file|"tsan_defs.h"
end_include

begin_include
include|#
directive|include
file|"tsan_mutex.h"
end_include

begin_decl_stmt
name|namespace
name|__tsan
block|{
name|class
name|SlabCache
decl_stmt|;
name|class
name|StackTrace
block|{
name|public
label|:
name|StackTrace
argument_list|()
expr_stmt|;
comment|// Initialized the object in "static mode",
comment|// in this mode it never calls malloc/free but uses the provided buffer.
name|StackTrace
argument_list|(
argument|uptr *buf
argument_list|,
argument|uptr cnt
argument_list|)
empty_stmt|;
operator|~
name|StackTrace
argument_list|()
expr_stmt|;
name|void
name|Reset
parameter_list|()
function_decl|;
name|void
name|Init
parameter_list|(
specifier|const
name|uptr
modifier|*
name|pcs
parameter_list|,
name|uptr
name|cnt
parameter_list|)
function_decl|;
name|void
name|ObtainCurrent
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|toppc
parameter_list|)
function_decl|;
name|bool
name|IsEmpty
argument_list|()
specifier|const
expr_stmt|;
name|uptr
name|Size
argument_list|()
specifier|const
expr_stmt|;
name|uptr
name|Get
argument_list|(
name|uptr
name|i
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|uptr
operator|*
name|Begin
argument_list|()
specifier|const
expr_stmt|;
name|void
name|CopyFrom
parameter_list|(
specifier|const
name|StackTrace
modifier|&
name|other
parameter_list|)
function_decl|;
name|private
label|:
name|uptr
name|n_
decl_stmt|;
name|uptr
modifier|*
name|s_
decl_stmt|;
specifier|const
name|uptr
name|c_
decl_stmt|;
name|StackTrace
argument_list|(
specifier|const
name|StackTrace
operator|&
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|StackTrace
operator|&
operator|)
decl_stmt|;
block|}
empty_stmt|;
struct|struct
name|SyncVar
block|{
name|explicit
name|SyncVar
parameter_list|(
name|uptr
name|addr
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|int
name|kInvalidTid
init|=
operator|-
literal|1
decl_stmt|;
name|Mutex
name|mtx
decl_stmt|;
specifier|const
name|uptr
name|addr
decl_stmt|;
name|SyncClock
name|clock
decl_stmt|;
name|SyncClock
name|read_clock
decl_stmt|;
comment|// Used for rw mutexes only.
name|StackTrace
name|creation_stack
decl_stmt|;
name|int
name|owner_tid
decl_stmt|;
comment|// Set only by exclusive owners.
name|int
name|recursion
decl_stmt|;
name|bool
name|is_rw
decl_stmt|;
name|bool
name|is_recursive
decl_stmt|;
name|bool
name|is_broken
decl_stmt|;
name|SyncVar
modifier|*
name|next
decl_stmt|;
comment|// In SyncTab hashtable.
name|uptr
name|GetMemoryConsumption
parameter_list|()
function_decl|;
block|}
struct|;
name|class
name|SyncTab
block|{
name|public
label|:
name|SyncTab
argument_list|()
expr_stmt|;
operator|~
name|SyncTab
argument_list|()
expr_stmt|;
comment|// If the SyncVar does not exist yet, it is created.
name|SyncVar
modifier|*
name|GetAndLock
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|uptr
name|addr
parameter_list|,
name|bool
name|write_lock
parameter_list|)
function_decl|;
comment|// If the SyncVar does not exist, returns 0.
name|SyncVar
modifier|*
name|GetAndRemove
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|uptr
name|addr
parameter_list|)
function_decl|;
name|uptr
name|GetMemoryConsumption
parameter_list|(
name|uptr
modifier|*
name|nsync
parameter_list|)
function_decl|;
name|private
label|:
struct|struct
name|Part
block|{
name|Mutex
name|mtx
decl_stmt|;
name|SyncVar
modifier|*
name|val
decl_stmt|;
name|char
name|pad
index|[
name|kCacheLineSize
operator|-
sizeof|sizeof
argument_list|(
name|Mutex
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|SyncVar
operator|*
argument_list|)
index|]
decl_stmt|;
comment|// NOLINT
name|Part
argument_list|()
expr_stmt|;
block|}
struct|;
comment|// FIXME: Implement something more sane.
specifier|static
specifier|const
name|int
name|kPartCount
init|=
literal|1009
decl_stmt|;
name|Part
name|tab_
index|[
name|kPartCount
index|]
decl_stmt|;
name|int
name|PartIdx
parameter_list|(
name|uptr
name|addr
parameter_list|)
function_decl|;
name|SyncTab
argument_list|(
specifier|const
name|SyncTab
operator|&
argument_list|)
expr_stmt|;
comment|// Not implemented.
name|void
name|operator
init|=
operator|(
specifier|const
name|SyncTab
operator|&
operator|)
decl_stmt|;
comment|// Not implemented.
block|}
empty_stmt|;
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
comment|// TSAN_SYNC_H
end_comment

end_unit

