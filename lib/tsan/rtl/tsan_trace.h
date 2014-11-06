begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tsan_trace.h --------------------------------------------*- C++ -*-===//
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
name|TSAN_TRACE_H
end_ifndef

begin_define
define|#
directive|define
name|TSAN_TRACE_H
end_define

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

begin_include
include|#
directive|include
file|"tsan_sync.h"
end_include

begin_include
include|#
directive|include
file|"tsan_mutexset.h"
end_include

begin_decl_stmt
name|namespace
name|__tsan
block|{
specifier|const
name|int
name|kTracePartSizeBits
init|=
literal|14
decl_stmt|;
specifier|const
name|int
name|kTracePartSize
init|=
literal|1
operator|<<
name|kTracePartSizeBits
decl_stmt|;
specifier|const
name|int
name|kTraceParts
init|=
literal|4
operator|*
literal|1024
operator|*
literal|1024
operator|/
name|kTracePartSize
decl_stmt|;
specifier|const
name|int
name|kTraceSize
init|=
name|kTracePartSize
operator|*
name|kTraceParts
decl_stmt|;
comment|// Must fit into 3 bits.
enum|enum
name|EventType
block|{
name|EventTypeMop
block|,
name|EventTypeFuncEnter
block|,
name|EventTypeFuncExit
block|,
name|EventTypeLock
block|,
name|EventTypeUnlock
block|,
name|EventTypeRLock
block|,
name|EventTypeRUnlock
block|}
enum|;
comment|// Represents a thread event (from most significant bit):
comment|// u64 typ  : 3;   // EventType.
comment|// u64 addr : 61;  // Associated pc.
typedef|typedef
name|u64
name|Event
typedef|;
struct|struct
name|TraceHeader
block|{
name|StackTrace
name|stack0
decl_stmt|;
comment|// Start stack for the trace.
name|u64
name|epoch0
decl_stmt|;
comment|// Start epoch for the trace.
name|MutexSet
name|mset0
decl_stmt|;
ifndef|#
directive|ifndef
name|TSAN_GO
name|uptr
name|stack0buf
index|[
name|kTraceStackSize
index|]
decl_stmt|;
endif|#
directive|endif
name|TraceHeader
argument_list|()
ifndef|#
directive|ifndef
name|TSAN_GO
operator|:
name|stack0
argument_list|(
name|stack0buf
argument_list|,
name|kTraceStackSize
argument_list|)
else|#
directive|else
operator|:
name|stack0
argument_list|()
endif|#
directive|endif
operator|,
name|epoch0
argument_list|()
block|{   }
block|}
struct|;
struct|struct
name|Trace
block|{
name|TraceHeader
name|headers
index|[
name|kTraceParts
index|]
decl_stmt|;
name|Mutex
name|mtx
decl_stmt|;
ifndef|#
directive|ifndef
name|TSAN_GO
comment|// Must be last to catch overflow as paging fault.
comment|// Go shadow stack is dynamically allocated.
name|uptr
name|shadow_stack
index|[
name|kShadowStackSize
index|]
decl_stmt|;
endif|#
directive|endif
name|Trace
argument_list|()
operator|:
name|mtx
argument_list|(
argument|MutexTypeTrace
argument_list|,
argument|StatMtxTrace
argument_list|)
block|{   }
block|}
struct|;
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
comment|// TSAN_TRACE_H
end_comment

end_unit

