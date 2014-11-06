begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_flags.h ---------------------------------------*- C++ -*-===//
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
comment|// This file is a part of ThreadSanitizer/AddressSanitizer runtime.
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
name|SANITIZER_FLAGS_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_FLAGS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
name|void
name|ParseFlag
parameter_list|(
specifier|const
name|char
modifier|*
name|env
parameter_list|,
name|bool
modifier|*
name|flag
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|void
name|ParseFlag
parameter_list|(
specifier|const
name|char
modifier|*
name|env
parameter_list|,
name|int
modifier|*
name|flag
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|void
name|ParseFlag
parameter_list|(
specifier|const
name|char
modifier|*
name|env
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|flag
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
struct|struct
name|CommonFlags
block|{
comment|// If set, use the online symbolizer from common sanitizer runtime.
name|bool
name|symbolize
decl_stmt|;
comment|// Path to external symbolizer.
specifier|const
name|char
modifier|*
name|external_symbolizer_path
decl_stmt|;
comment|// Strips this prefix from file paths in error reports.
specifier|const
name|char
modifier|*
name|strip_path_prefix
decl_stmt|;
comment|// Use fast (frame-pointer-based) unwinder on fatal errors (if available).
name|bool
name|fast_unwind_on_fatal
decl_stmt|;
comment|// Use fast (frame-pointer-based) unwinder on malloc/free (if available).
name|bool
name|fast_unwind_on_malloc
decl_stmt|;
comment|// Intercept and handle ioctl requests.
name|bool
name|handle_ioctl
decl_stmt|;
comment|// Max number of stack frames kept for each allocation/deallocation.
name|int
name|malloc_context_size
decl_stmt|;
comment|// Write logs to "log_path.pid".
comment|// The special values are "stdout" and "stderr".
comment|// The default is "stderr".
specifier|const
name|char
modifier|*
name|log_path
decl_stmt|;
comment|// Verbosity level (0 - silent, 1 - a bit of output, 2+ - more output).
name|int
name|verbosity
decl_stmt|;
comment|// Enable memory leak detection.
name|bool
name|detect_leaks
decl_stmt|;
comment|// Invoke leak checking in an atexit handler. Has no effect if
comment|// detect_leaks=false, or if __lsan_do_leak_check() is called before the
comment|// handler has a chance to run.
name|bool
name|leak_check_at_exit
decl_stmt|;
comment|// If false, the allocator will crash instead of returning 0 on out-of-memory.
name|bool
name|allocator_may_return_null
decl_stmt|;
comment|// If false, disable printing error summaries in addition to error reports.
name|bool
name|print_summary
decl_stmt|;
block|}
struct|;
specifier|inline
name|CommonFlags
modifier|*
name|common_flags
parameter_list|()
block|{
specifier|static
name|CommonFlags
name|f
decl_stmt|;
return|return
operator|&
name|f
return|;
block|}
name|void
name|SetCommonFlagDefaults
parameter_list|()
function_decl|;
name|void
name|ParseCommonFlagsFromString
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
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
comment|// SANITIZER_FLAGS_H
end_comment

end_unit

