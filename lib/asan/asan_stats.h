begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_stats.h --------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of AddressSanitizer, an address sanity checker.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ASan-private header for statistics.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_STATS_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_STATS_H
end_define

begin_include
include|#
directive|include
file|"asan_allocator.h"
end_include

begin_include
include|#
directive|include
file|"asan_internal.h"
end_include

begin_decl_stmt
name|namespace
name|__asan
block|{
comment|// AsanStats struct is NOT thread-safe.
comment|// Each AsanThread has its own AsanStats, which are sometimes flushed
comment|// to the accumulated AsanStats.
struct|struct
name|AsanStats
block|{
comment|// AsanStats must be a struct consisting of uptr fields only.
comment|// When merging two AsanStats structs, we treat them as arrays of uptr.
name|uptr
name|mallocs
decl_stmt|;
name|uptr
name|malloced
decl_stmt|;
name|uptr
name|malloced_redzones
decl_stmt|;
name|uptr
name|frees
decl_stmt|;
name|uptr
name|freed
decl_stmt|;
name|uptr
name|real_frees
decl_stmt|;
name|uptr
name|really_freed
decl_stmt|;
name|uptr
name|really_freed_redzones
decl_stmt|;
name|uptr
name|reallocs
decl_stmt|;
name|uptr
name|realloced
decl_stmt|;
name|uptr
name|mmaps
decl_stmt|;
name|uptr
name|mmaped
decl_stmt|;
name|uptr
name|mmaped_by_size
index|[
name|kNumberOfSizeClasses
index|]
decl_stmt|;
name|uptr
name|malloced_by_size
index|[
name|kNumberOfSizeClasses
index|]
decl_stmt|;
name|uptr
name|freed_by_size
index|[
name|kNumberOfSizeClasses
index|]
decl_stmt|;
name|uptr
name|really_freed_by_size
index|[
name|kNumberOfSizeClasses
index|]
decl_stmt|;
name|uptr
name|malloc_large
decl_stmt|;
name|uptr
name|malloc_small_slow
decl_stmt|;
comment|// Ctor for global AsanStats (accumulated stats and main thread stats).
name|explicit
name|AsanStats
parameter_list|(
name|LinkerInitialized
parameter_list|)
block|{ }
comment|// Default ctor for thread-local stats.
name|AsanStats
argument_list|()
expr_stmt|;
comment|// Prints formatted stats to stderr.
name|void
name|Print
parameter_list|()
function_decl|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __asan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_STATS_H
end_comment

end_unit

