begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=-- lsan_common.h -------------------------------------------------------===//
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
comment|// This file is a part of LeakSanitizer.
end_comment

begin_comment
comment|// Private LSan header.
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
name|LSAN_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|LSAN_COMMON_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_allocator.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_common.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_internal_defs.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_platform.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_symbolizer.h"
end_include

begin_if
if|#
directive|if
name|SANITIZER_LINUX
operator|&&
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|CAN_SANITIZE_LEAKS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CAN_SANITIZE_LEAKS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|__lsan
block|{
comment|// Chunk tags.
enum|enum
name|ChunkTag
block|{
name|kDirectlyLeaked
init|=
literal|0
block|,
comment|// default
name|kIndirectlyLeaked
init|=
literal|1
block|,
name|kReachable
init|=
literal|2
block|,
name|kIgnored
init|=
literal|3
block|}
enum|;
struct|struct
name|Flags
block|{
name|uptr
name|pointer_alignment
argument_list|()
specifier|const
block|{
return|return
name|use_unaligned
operator|?
literal|1
operator|:
sizeof|sizeof
argument_list|(
name|uptr
argument_list|)
return|;
block|}
comment|// Print addresses of leaked objects after main leak report.
name|bool
name|report_objects
decl_stmt|;
comment|// Aggregate two objects into one leak if this many stack frames match. If
comment|// zero, the entire stack trace must match.
name|int
name|resolution
decl_stmt|;
comment|// The number of leaks reported.
name|int
name|max_leaks
decl_stmt|;
comment|// If nonzero kill the process with this exit code upon finding leaks.
name|int
name|exitcode
decl_stmt|;
comment|// Suppressions file name.
specifier|const
name|char
modifier|*
name|suppressions
decl_stmt|;
comment|// Flags controlling the root set of reachable memory.
comment|// Global variables (.data and .bss).
name|bool
name|use_globals
decl_stmt|;
comment|// Thread stacks.
name|bool
name|use_stacks
decl_stmt|;
comment|// Thread registers.
name|bool
name|use_registers
decl_stmt|;
comment|// TLS and thread-specific storage.
name|bool
name|use_tls
decl_stmt|;
comment|// Consider unaligned pointers valid.
name|bool
name|use_unaligned
decl_stmt|;
comment|// User-visible verbosity.
name|int
name|verbosity
decl_stmt|;
comment|// Debug logging.
name|bool
name|log_pointers
decl_stmt|;
name|bool
name|log_threads
decl_stmt|;
block|}
struct|;
specifier|extern
name|Flags
name|lsan_flags
decl_stmt|;
specifier|inline
name|Flags
modifier|*
name|flags
parameter_list|()
block|{
return|return
operator|&
name|lsan_flags
return|;
block|}
struct|struct
name|Leak
block|{
name|uptr
name|hit_count
decl_stmt|;
name|uptr
name|total_size
decl_stmt|;
name|u32
name|stack_trace_id
decl_stmt|;
name|bool
name|is_directly_leaked
decl_stmt|;
name|bool
name|is_suppressed
decl_stmt|;
block|}
struct|;
comment|// Aggregates leaks by stack trace prefix.
name|class
name|LeakReport
block|{
name|public
label|:
name|LeakReport
argument_list|()
operator|:
name|leaks_
argument_list|(
literal|1
argument_list|)
block|{}
name|void
name|Add
argument_list|(
argument|u32 stack_trace_id
argument_list|,
argument|uptr leaked_size
argument_list|,
argument|ChunkTag tag
argument_list|)
expr_stmt|;
name|void
name|PrintLargest
parameter_list|(
name|uptr
name|max_leaks
parameter_list|)
function_decl|;
name|void
name|PrintSummary
parameter_list|()
function_decl|;
name|bool
name|IsEmpty
parameter_list|()
block|{
return|return
name|leaks_
operator|.
name|size
argument_list|()
operator|==
literal|0
return|;
block|}
name|uptr
name|ApplySuppressions
parameter_list|()
function_decl|;
name|private
label|:
name|InternalMmapVector
operator|<
name|Leak
operator|>
name|leaks_
expr_stmt|;
block|}
empty_stmt|;
typedef|typedef
name|InternalMmapVector
operator|<
name|uptr
operator|>
name|Frontier
expr_stmt|;
comment|// Platform-specific functions.
name|void
name|InitializePlatformSpecificModules
parameter_list|()
function_decl|;
name|void
name|ProcessGlobalRegions
parameter_list|(
name|Frontier
modifier|*
name|frontier
parameter_list|)
function_decl|;
name|void
name|ProcessPlatformSpecificAllocations
parameter_list|(
name|Frontier
modifier|*
name|frontier
parameter_list|)
function_decl|;
name|void
name|ScanRangeForPointers
parameter_list|(
name|uptr
name|begin
parameter_list|,
name|uptr
name|end
parameter_list|,
name|Frontier
modifier|*
name|frontier
parameter_list|,
specifier|const
name|char
modifier|*
name|region_type
parameter_list|,
name|ChunkTag
name|tag
parameter_list|)
function_decl|;
enum|enum
name|IgnoreObjectResult
block|{
name|kIgnoreObjectSuccess
block|,
name|kIgnoreObjectAlreadyIgnored
block|,
name|kIgnoreObjectInvalid
block|}
enum|;
comment|// Functions called from the parent tool.
name|void
name|InitCommonLsan
parameter_list|()
function_decl|;
name|void
name|DoLeakCheck
parameter_list|()
function_decl|;
name|bool
name|DisabledInThisThread
parameter_list|()
function_decl|;
comment|// The following must be implemented in the parent tool.
name|void
name|ForEachChunk
parameter_list|(
name|ForEachChunkCallback
name|callback
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|// Returns the address range occupied by the global allocator object.
name|void
name|GetAllocatorGlobalRange
parameter_list|(
name|uptr
modifier|*
name|begin
parameter_list|,
name|uptr
modifier|*
name|end
parameter_list|)
function_decl|;
comment|// Wrappers for allocator's ForceLock()/ForceUnlock().
name|void
name|LockAllocator
parameter_list|()
function_decl|;
name|void
name|UnlockAllocator
parameter_list|()
function_decl|;
comment|// Wrappers for ThreadRegistry access.
name|void
name|LockThreadRegistry
parameter_list|()
function_decl|;
name|void
name|UnlockThreadRegistry
parameter_list|()
function_decl|;
name|bool
name|GetThreadRangesLocked
parameter_list|(
name|uptr
name|os_id
parameter_list|,
name|uptr
modifier|*
name|stack_begin
parameter_list|,
name|uptr
modifier|*
name|stack_end
parameter_list|,
name|uptr
modifier|*
name|tls_begin
parameter_list|,
name|uptr
modifier|*
name|tls_end
parameter_list|,
name|uptr
modifier|*
name|cache_begin
parameter_list|,
name|uptr
modifier|*
name|cache_end
parameter_list|)
function_decl|;
name|void
name|ForEachExtraStackRange
parameter_list|(
name|uptr
name|os_id
parameter_list|,
name|RangeIteratorCallback
name|callback
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|// If called from the main thread, updates the main thread's TID in the thread
comment|// registry. We need this to handle processes that fork() without a subsequent
comment|// exec(), which invalidates the recorded TID. To update it, we must call
comment|// gettid() from the main thread. Our solution is to call this function before
comment|// leak checking and also before every call to pthread_create() (to handle cases
comment|// where leak checking is initiated from a non-main thread).
name|void
name|EnsureMainThreadIDIsCorrect
parameter_list|()
function_decl|;
comment|// If p points into a chunk that has been allocated to the user, returns its
comment|// user-visible address. Otherwise, returns 0.
name|uptr
name|PointsIntoChunk
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
comment|// Returns address of user-visible chunk contained in this allocator chunk.
name|uptr
name|GetUserBegin
parameter_list|(
name|uptr
name|chunk
parameter_list|)
function_decl|;
comment|// Helper for __lsan_ignore_object().
name|IgnoreObjectResult
name|IgnoreObjectLocked
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
comment|// Wrapper for chunk metadata operations.
name|class
name|LsanMetadata
block|{
name|public
label|:
comment|// Constructor accepts address of user-visible chunk.
name|explicit
name|LsanMetadata
parameter_list|(
name|uptr
name|chunk
parameter_list|)
function_decl|;
name|bool
name|allocated
argument_list|()
specifier|const
expr_stmt|;
name|ChunkTag
name|tag
argument_list|()
specifier|const
expr_stmt|;
name|void
name|set_tag
parameter_list|(
name|ChunkTag
name|value
parameter_list|)
function_decl|;
name|uptr
name|requested_size
argument_list|()
specifier|const
expr_stmt|;
name|u32
name|stack_trace_id
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|void
modifier|*
name|metadata_
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __lsan
end_comment

begin_extern
extern|extern
literal|"C"
block|{
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
name|int
name|__lsan_is_turned_off
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
specifier|const
name|char
modifier|*
name|__lsan_default_suppressions
parameter_list|()
function_decl|;
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LSAN_COMMON_H
end_comment

end_unit

