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
comment|// Tell the tools to write their reports to the provided file descriptor
comment|// (casted to void *).
name|void
name|__sanitizer_set_report_fd
parameter_list|(
name|void
modifier|*
name|fd
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
comment|// Similar to __sanitizer_verify_contiguous_container but returns the address
comment|// of the first improperly poisoned byte otherwise. Returns null if the area
comment|// is poisoned properly.
specifier|const
name|void
modifier|*
name|__sanitizer_contiguous_container_find_bad_address
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
comment|// Symbolizes the supplied 'pc' using the format string 'fmt'.
comment|// Outputs at most 'out_buf_size' bytes into 'out_buf'.
comment|// The format syntax is described in
comment|// lib/sanitizer_common/sanitizer_stacktrace_printer.h.
name|void
name|__sanitizer_symbolize_pc
parameter_list|(
name|void
modifier|*
name|pc
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|char
modifier|*
name|out_buf
parameter_list|,
name|size_t
name|out_buf_size
parameter_list|)
function_decl|;
comment|// Same as __sanitizer_symbolize_pc, but for data section (i.e. globals).
name|void
name|__sanitizer_symbolize_global
parameter_list|(
name|void
modifier|*
name|data_ptr
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|char
modifier|*
name|out_buf
parameter_list|,
name|size_t
name|out_buf_size
parameter_list|)
function_decl|;
comment|// Sets the callback to be called right before death on error.
comment|// Passing 0 will unset the callback.
name|void
name|__sanitizer_set_death_callback
parameter_list|(
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
comment|// Interceptor hooks.
comment|// Whenever a libc function interceptor is called it checks if the
comment|// corresponding weak hook is defined, and it so -- calls it.
comment|// The primary use case is data-flow-guided fuzzing, where the fuzzer needs
comment|// to know what is being passed to libc functions, e.g. memcmp.
comment|// FIXME: implement more hooks.
name|void
name|__sanitizer_weak_hook_memcmp
parameter_list|(
name|void
modifier|*
name|called_pc
parameter_list|,
specifier|const
name|void
modifier|*
name|s1
parameter_list|,
specifier|const
name|void
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|,
name|int
name|result
parameter_list|)
function_decl|;
name|void
name|__sanitizer_weak_hook_strncmp
parameter_list|(
name|void
modifier|*
name|called_pc
parameter_list|,
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|,
name|int
name|result
parameter_list|)
function_decl|;
name|void
name|__sanitizer_weak_hook_strncasecmp
parameter_list|(
name|void
modifier|*
name|called_pc
parameter_list|,
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|,
name|int
name|result
parameter_list|)
function_decl|;
name|void
name|__sanitizer_weak_hook_strcmp
parameter_list|(
name|void
modifier|*
name|called_pc
parameter_list|,
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|,
name|int
name|result
parameter_list|)
function_decl|;
name|void
name|__sanitizer_weak_hook_strcasecmp
parameter_list|(
name|void
modifier|*
name|called_pc
parameter_list|,
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|,
name|int
name|result
parameter_list|)
function_decl|;
name|void
name|__sanitizer_weak_hook_strstr
parameter_list|(
name|void
modifier|*
name|called_pc
parameter_list|,
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|,
name|char
modifier|*
name|result
parameter_list|)
function_decl|;
name|void
name|__sanitizer_weak_hook_strcasestr
parameter_list|(
name|void
modifier|*
name|called_pc
parameter_list|,
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|,
name|char
modifier|*
name|result
parameter_list|)
function_decl|;
name|void
name|__sanitizer_weak_hook_memmem
parameter_list|(
name|void
modifier|*
name|called_pc
parameter_list|,
specifier|const
name|void
modifier|*
name|s1
parameter_list|,
name|size_t
name|len1
parameter_list|,
specifier|const
name|void
modifier|*
name|s2
parameter_list|,
name|size_t
name|len2
parameter_list|,
name|void
modifier|*
name|result
parameter_list|)
function_decl|;
comment|// Prints stack traces for all live heap allocations ordered by total
comment|// allocation size until `top_percent` of total live heap is shown.
comment|// `top_percent` should be between 1 and 100.
comment|// At most `max_number_of_contexts` contexts (stack traces) is printed.
comment|// Experimental feature currently available only with asan on Linux/x86_64.
name|void
name|__sanitizer_print_memory_profile
parameter_list|(
name|size_t
name|top_percent
parameter_list|,
name|size_t
name|max_number_of_contexts
parameter_list|)
function_decl|;
comment|// Fiber annotation interface.
comment|// Before switching to a different stack, one must call
comment|// __sanitizer_start_switch_fiber with a pointer to the bottom of the
comment|// destination stack and its size. When code starts running on the new stack,
comment|// it must call __sanitizer_finish_switch_fiber to finalize the switch.
comment|// The start_switch function takes a void** to store the current fake stack if
comment|// there is one (it is needed when detect_stack_use_after_return is enabled).
comment|// When restoring a stack, this pointer must be given to the finish_switch
comment|// function. In most cases, this void* can be stored on the stack just before
comment|// switching.  When leaving a fiber definitely, null must be passed as first
comment|// argument to the start_switch function so that the fake stack is destroyed.
comment|// If you do not want support for stack use-after-return detection, you can
comment|// always pass null to these two functions.
comment|// Note that the fake stack mechanism is disabled during fiber switch, so if a
comment|// signal callback runs during the switch, it will not benefit from the stack
comment|// use-after-return detection.
name|void
name|__sanitizer_start_switch_fiber
parameter_list|(
name|void
modifier|*
modifier|*
name|fake_stack_save
parameter_list|,
specifier|const
name|void
modifier|*
name|bottom
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
name|void
name|__sanitizer_finish_switch_fiber
parameter_list|(
name|void
modifier|*
name|fake_stack_save
parameter_list|,
specifier|const
name|void
modifier|*
modifier|*
name|bottom_old
parameter_list|,
name|size_t
modifier|*
name|size_old
parameter_list|)
function_decl|;
comment|// Get full module name and calculate pc offset within it.
comment|// Returns 1 if pc belongs to some module, 0 if module was not found.
name|int
name|__sanitizer_get_module_and_offset_for_pc
parameter_list|(
name|void
modifier|*
name|pc
parameter_list|,
name|char
modifier|*
name|module_path
parameter_list|,
name|size_t
name|module_path_len
parameter_list|,
name|void
modifier|*
modifier|*
name|pc_offset
parameter_list|)
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

