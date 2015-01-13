begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer/common_interface_defs.h -----------------------*- C++ -*-===//
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
comment|// Common part of the public sanitizer interface.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_COMMON_INTERFACE_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_COMMON_INTERFACE_DEFS_H
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// GCC does not understand __has_feature.
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__has_feature
argument_list|)
end_if

begin_define
define|#
directive|define
name|__has_feature
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|// Arguments for __sanitizer_sandbox_on_notify() below.
typedef|typedef
struct|struct
block|{
comment|// Enable sandbox support in sanitizer coverage.
name|int
name|coverage_sandboxed
decl_stmt|;
comment|// File descriptor to write coverage data to. If -1 is passed, a file will
comment|// be pre-opened by __sanitizer_sandobx_on_notify(). This field has no
comment|// effect if coverage_sandboxed == 0.
name|intptr_t
name|coverage_fd
decl_stmt|;
comment|// If non-zero, split the coverage data into well-formed blocks. This is
comment|// useful when coverage_fd is a socket descriptor. Each block will contain
comment|// a header, allowing data from multiple processes to be sent over the same
comment|// socket.
name|unsigned
name|int
name|coverage_max_block_size
decl_stmt|;
block|}
name|__sanitizer_sandbox_arguments
typedef|;
comment|// Tell the tools to write their reports to "path.<pid>" instead of stderr.
name|void
name|__sanitizer_set_report_path
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
comment|// Notify the tools that the sandbox is going to be turned on. The reserved
comment|// parameter will be used in the future to hold a structure with functions
comment|// that the tools may call to bypass the sandbox.
name|void
name|__sanitizer_sandbox_on_notify
parameter_list|(
name|__sanitizer_sandbox_arguments
modifier|*
name|args
parameter_list|)
function_decl|;
comment|// This function is called by the tool when it has just finished reporting
comment|// an error. 'error_summary' is a one-line string that summarizes
comment|// the error message. This function can be overridden by the client.
name|void
name|__sanitizer_report_error_summary
parameter_list|(
specifier|const
name|char
modifier|*
name|error_summary
parameter_list|)
function_decl|;
comment|// Some of the sanitizers (e.g. asan/tsan) may miss bugs that happen
comment|// in unaligned loads/stores. In order to find such bugs reliably one needs
comment|// to replace plain unaligned loads/stores with these calls.
name|uint16_t
name|__sanitizer_unaligned_load16
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
name|uint32_t
name|__sanitizer_unaligned_load32
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
name|uint64_t
name|__sanitizer_unaligned_load64
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
name|void
name|__sanitizer_unaligned_store16
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|uint16_t
name|x
parameter_list|)
function_decl|;
name|void
name|__sanitizer_unaligned_store32
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|uint32_t
name|x
parameter_list|)
function_decl|;
name|void
name|__sanitizer_unaligned_store64
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|uint64_t
name|x
parameter_list|)
function_decl|;
comment|// Initialize coverage.
name|void
name|__sanitizer_cov_init
parameter_list|()
function_decl|;
comment|// Record and dump coverage info.
name|void
name|__sanitizer_cov_dump
parameter_list|()
function_decl|;
comment|// Open<name>.sancov.packed in the coverage directory and return the file
comment|// descriptor. Returns -1 on failure, or if coverage dumping is disabled.
comment|// This is intended for use by sandboxing code.
name|intptr_t
name|__sanitizer_maybe_open_cov_file
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|// Get the number of total unique covered entities (blocks, edges, calls).
comment|// This can be useful for coverage-directed in-process fuzzers.
name|uintptr_t
name|__sanitizer_get_total_unique_coverage
parameter_list|()
function_decl|;
comment|// Annotate the current state of a contiguous container, such as
comment|// std::vector, std::string or similar.
comment|// A contiguous container is a container that keeps all of its elements
comment|// in a contiguous region of memory. The container owns the region of memory
comment|// [beg, end); the memory [beg, mid) is used to store the current elements
comment|// and the memory [mid, end) is reserved for future elements;
comment|// beg<= mid<= end. For example, in "std::vector<> v"
comment|//   beg =&v[0];
comment|//   end = beg + v.capacity() * sizeof(v[0]);
comment|//   mid = beg + v.size()     * sizeof(v[0]);
comment|//
comment|// This annotation tells the Sanitizer tool about the current state of the
comment|// container so that the tool can report errors when memory from [mid, end)
comment|// is accessed. Insert this annotation into methods like push_back/pop_back.
comment|// Supply the old and the new values of mid (old_mid/new_mid).
comment|// In the initial state mid == end and so should be the final
comment|// state when the container is destroyed or when it reallocates the storage.
comment|//
comment|// Use with caution and don't use for anything other than vector-like classes.
comment|//
comment|// For AddressSanitizer, 'beg' should be 8-aligned and 'end' should
comment|// be either 8-aligned or it should point to the end of a separate heap-,
comment|// stack-, or global- allocated buffer. I.e. the following will not work:
comment|//   int64_t x[2];  // 16 bytes, 8-aligned.
comment|//   char *beg = (char *)&x[0];
comment|//   char *end = beg + 12;  // Not 8 aligned, not the end of the buffer.
comment|// This however will work fine:
comment|//   int32_t x[3];  // 12 bytes, but 8-aligned under AddressSanitizer.
comment|//   char *beg = (char*)&x[0];
comment|//   char *end = beg + 12;  // Not 8-aligned, but is the end of the buffer.
name|void
name|__sanitizer_annotate_contiguous_container
parameter_list|(
specifier|const
name|void
modifier|*
name|beg
parameter_list|,
specifier|const
name|void
modifier|*
name|end
parameter_list|,
specifier|const
name|void
modifier|*
name|old_mid
parameter_list|,
specifier|const
name|void
modifier|*
name|new_mid
parameter_list|)
function_decl|;
comment|// Returns true if the contiguous container [beg, end) is properly poisoned
comment|// (e.g. with __sanitizer_annotate_contiguous_container), i.e. if
comment|//  - [beg, mid) is addressable,
comment|//  - [mid, end) is unaddressable.
comment|// Full verification requires O(end-beg) time; this function tries to avoid
comment|// such complexity by touching only parts of the container around beg/mid/end.
name|int
name|__sanitizer_verify_contiguous_container
parameter_list|(
specifier|const
name|void
modifier|*
name|beg
parameter_list|,
specifier|const
name|void
modifier|*
name|mid
parameter_list|,
specifier|const
name|void
modifier|*
name|end
parameter_list|)
function_decl|;
comment|// Print the stack trace leading to this call. Useful for debugging user code.
name|void
name|__sanitizer_print_stack_trace
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_COMMON_INTERFACE_DEFS_H
end_comment

end_unit

