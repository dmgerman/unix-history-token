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
file|"sanitizer_common/sanitizer_stoptheworld.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_symbolizer.h"
end_include

begin_comment
comment|// LeakSanitizer relies on some Glibc's internals (e.g. TLS machinery) thus
end_comment

begin_comment
comment|// supported for Linux only. Also, LSan doesn't like 32 bit architectures
end_comment

begin_comment
comment|// because of "small" (4 bytes) pointer size that leads to high false negative
end_comment

begin_comment
comment|// ratio on large leaks. But we still want to have it for some 32 bit arches
end_comment

begin_comment
comment|// (e.g. x86), see https://github.com/google/sanitizers/issues/403.
end_comment

begin_comment
comment|// To enable LeakSanitizer on new architecture, one need to implement
end_comment

begin_comment
comment|// internal_clone function as well as (probably) adjust TLS machinery for
end_comment

begin_comment
comment|// new architecture inside sanitizer library.
end_comment

begin_if
if|#
directive|if
operator|(
name|SANITIZER_LINUX
operator|&&
operator|!
name|SANITIZER_ANDROID
operator|||
name|SANITIZER_MAC
operator|)
operator|&&
expr|\
operator|(
name|SANITIZER_WORDSIZE
operator|==
literal|64
operator|)
operator|&&
expr|\
operator|(
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips64
argument_list|)
operator|||
name|defined
argument_list|(
name|__aarch64__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|CAN_SANITIZE_LEAKS
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|&&
expr|\
operator|(
name|SANITIZER_LINUX
operator|&&
operator|!
name|SANITIZER_ANDROID
operator|||
name|SANITIZER_MAC
operator|)
end_elif

begin_define
define|#
directive|define
name|CAN_SANITIZE_LEAKS
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|&&
expr|\
name|SANITIZER_LINUX
operator|&&
operator|!
name|SANITIZER_ANDROID
end_elif

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
name|__sanitizer
block|{
name|class
name|FlagParser
decl_stmt|;
struct_decl|struct
name|DTLS
struct_decl|;
block|}
end_decl_stmt

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
specifier|const
name|u32
name|kInvalidTid
init|=
operator|(
name|u32
operator|)
operator|-
literal|1
decl_stmt|;
struct|struct
name|Flags
block|{
define|#
directive|define
name|LSAN_FLAG
parameter_list|(
name|Type
parameter_list|,
name|Name
parameter_list|,
name|DefaultValue
parameter_list|,
name|Description
parameter_list|)
value|Type Name;
include|#
directive|include
file|"lsan_flags.inc"
undef|#
directive|undef
name|LSAN_FLAG
name|void
name|SetDefaults
parameter_list|()
function_decl|;
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
name|void
name|RegisterLsanFlags
parameter_list|(
name|FlagParser
modifier|*
name|parser
parameter_list|,
name|Flags
modifier|*
name|f
parameter_list|)
function_decl|;
struct|struct
name|Leak
block|{
name|u32
name|id
decl_stmt|;
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
struct|struct
name|LeakedObject
block|{
name|u32
name|leak_id
decl_stmt|;
name|uptr
name|addr
decl_stmt|;
name|uptr
name|size
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
name|next_id_
argument_list|(
literal|0
argument_list|)
operator|,
name|leaks_
argument_list|(
literal|1
argument_list|)
operator|,
name|leaked_objects_
argument_list|(
literal|1
argument_list|)
block|{}
name|void
name|AddLeakedChunk
argument_list|(
argument|uptr chunk
argument_list|,
argument|u32 stack_trace_id
argument_list|,
argument|uptr leaked_size
argument_list|,
argument|ChunkTag tag
argument_list|)
expr_stmt|;
name|void
name|ReportTopLeaks
parameter_list|(
name|uptr
name|max_leaks
parameter_list|)
function_decl|;
name|void
name|PrintSummary
parameter_list|()
function_decl|;
name|void
name|ApplySuppressions
parameter_list|()
function_decl|;
name|uptr
name|UnsuppressedLeakCount
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|PrintReportForLeak
parameter_list|(
name|uptr
name|index
parameter_list|)
function_decl|;
name|void
name|PrintLeakedObjectsForLeak
parameter_list|(
name|uptr
name|index
parameter_list|)
function_decl|;
name|u32
name|next_id_
decl_stmt|;
name|InternalMmapVector
operator|<
name|Leak
operator|>
name|leaks_
expr_stmt|;
name|InternalMmapVector
operator|<
name|LeakedObject
operator|>
name|leaked_objects_
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
struct|struct
name|RootRegion
block|{
name|uptr
name|begin
decl_stmt|;
name|uptr
name|size
decl_stmt|;
block|}
struct|;
name|InternalMmapVector
operator|<
name|RootRegion
operator|>
specifier|const
operator|*
name|GetRootRegions
argument_list|()
expr_stmt|;
name|void
name|ScanRootRegion
parameter_list|(
name|Frontier
modifier|*
name|frontier
parameter_list|,
name|RootRegion
specifier|const
modifier|&
name|region
parameter_list|,
name|uptr
name|region_begin
parameter_list|,
name|uptr
name|region_end
parameter_list|,
name|bool
name|is_readable
parameter_list|)
function_decl|;
comment|// Run stoptheworld while holding any platform-specific locks.
name|void
name|DoStopTheWorld
parameter_list|(
name|StopTheWorldCallback
name|callback
parameter_list|,
name|void
modifier|*
name|argument
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
name|void
name|ScanGlobalRange
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
name|void
name|DisableCounterUnderflow
parameter_list|()
function_decl|;
name|bool
name|DisabledInThisThread
parameter_list|()
function_decl|;
comment|// Used to implement __lsan::ScopedDisabler.
name|void
name|DisableInThisThread
parameter_list|()
function_decl|;
name|void
name|EnableInThisThread
parameter_list|()
function_decl|;
comment|// Can be used to ignore memory allocated by an intercepted
comment|// function.
struct|struct
name|ScopedInterceptorDisabler
block|{
name|ScopedInterceptorDisabler
argument_list|()
block|{
name|DisableInThisThread
argument_list|()
expr_stmt|;
block|}
operator|~
name|ScopedInterceptorDisabler
argument_list|()
block|{
name|EnableInThisThread
argument_list|()
block|; }
block|}
struct|;
comment|// According to Itanium C++ ABI array cookie is a one word containing
comment|// size of allocated array.
specifier|static
specifier|inline
name|bool
name|IsItaniumABIArrayCookie
parameter_list|(
name|uptr
name|chunk_beg
parameter_list|,
name|uptr
name|chunk_size
parameter_list|,
name|uptr
name|addr
parameter_list|)
block|{
return|return
name|chunk_size
operator|==
sizeof|sizeof
argument_list|(
name|uptr
argument_list|)
operator|&&
name|chunk_beg
operator|+
name|chunk_size
operator|==
name|addr
operator|&&
operator|*
name|reinterpret_cast
operator|<
name|uptr
operator|*
operator|>
operator|(
name|chunk_beg
operator|)
operator|==
literal|0
return|;
block|}
comment|// According to ARM C++ ABI array cookie consists of two words:
comment|// struct array_cookie {
comment|//   std::size_t element_size; // element_size != 0
comment|//   std::size_t element_count;
comment|// };
specifier|static
specifier|inline
name|bool
name|IsARMABIArrayCookie
parameter_list|(
name|uptr
name|chunk_beg
parameter_list|,
name|uptr
name|chunk_size
parameter_list|,
name|uptr
name|addr
parameter_list|)
block|{
return|return
name|chunk_size
operator|==
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|uptr
argument_list|)
operator|&&
name|chunk_beg
operator|+
name|chunk_size
operator|==
name|addr
operator|&&
operator|*
name|reinterpret_cast
operator|<
name|uptr
operator|*
operator|>
operator|(
name|chunk_beg
operator|+
sizeof|sizeof
argument_list|(
name|uptr
argument_list|)
operator|)
operator|==
literal|0
return|;
block|}
comment|// Special case for "new T[0]" where T is a type with DTOR.
comment|// new T[0] will allocate a cookie (one or two words) for the array size (0)
comment|// and store a pointer to the end of allocated chunk. The actual cookie layout
comment|// varies between platforms according to their C++ ABI implementation.
specifier|inline
name|bool
name|IsSpecialCaseOfOperatorNew0
parameter_list|(
name|uptr
name|chunk_beg
parameter_list|,
name|uptr
name|chunk_size
parameter_list|,
name|uptr
name|addr
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|__arm__
argument_list|)
return|return
name|IsARMABIArrayCookie
argument_list|(
name|chunk_beg
argument_list|,
name|chunk_size
argument_list|,
name|addr
argument_list|)
return|;
else|#
directive|else
return|return
name|IsItaniumABIArrayCookie
argument_list|(
name|chunk_beg
argument_list|,
name|chunk_size
argument_list|,
name|addr
argument_list|)
return|;
endif|#
directive|endif
block|}
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
comment|// Returns true if [addr, addr + sizeof(void *)) is poisoned.
name|bool
name|WordIsPoisoned
parameter_list|(
name|uptr
name|addr
parameter_list|)
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
name|tid_t
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
parameter_list|,
name|DTLS
modifier|*
modifier|*
name|dtls
parameter_list|)
function_decl|;
name|void
name|ForEachExtraStackRange
parameter_list|(
name|tid_t
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
comment|// Return the linker module, if valid for the platform.
name|LoadedModule
modifier|*
name|GetLinker
parameter_list|()
function_decl|;
comment|// Return true if LSan has finished leak checking and reported leaks.
name|bool
name|HasReportedLeaks
parameter_list|()
function_decl|;
comment|// Run platform-specific leak handlers.
name|void
name|HandleLeaks
parameter_list|()
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

