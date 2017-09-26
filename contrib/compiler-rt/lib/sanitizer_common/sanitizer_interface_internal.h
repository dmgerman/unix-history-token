begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_interface_internal.h --------------------------*- C++ -*-===//
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
comment|// This file is shared between run-time libraries of sanitizers.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This header declares the sanitizer runtime interface functions.
end_comment

begin_comment
comment|// The runtime library has to define these functions so the instrumented program
end_comment

begin_comment
comment|// could call them.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// See also include/sanitizer/common_interface_defs.h
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_INTERFACE_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_INTERFACE_INTERNAL_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_extern
extern|extern
literal|"C"
block|{
comment|// Tell the tools to write their reports to "path.<pid>" instead of stderr.
comment|// The special values are "stdout" and "stderr".
name|SANITIZER_INTERFACE_ATTRIBUTE
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
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__sanitizer_set_report_fd
parameter_list|(
name|void
modifier|*
name|fd
parameter_list|)
function_decl|;
typedef|typedef
struct|struct
block|{
name|int
name|coverage_sandboxed
decl_stmt|;
name|__sanitizer
operator|::
name|sptr
name|coverage_fd
expr_stmt|;
name|unsigned
name|int
name|coverage_max_block_size
decl_stmt|;
block|}
name|__sanitizer_sandbox_arguments
typedef|;
comment|// Notify the tools that the sandbox is going to be turned on.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
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
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
name|void
name|__sanitizer_report_error_summary
parameter_list|(
specifier|const
name|char
modifier|*
name|error_summary
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__sanitizer_cov_init
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__sanitizer_cov_dump
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__sanitizer_dump_coverage
argument_list|(
specifier|const
name|__sanitizer
operator|::
name|uptr
operator|*
name|pcs
argument_list|,
specifier|const
name|__sanitizer
operator|::
name|uptr
name|len
argument_list|)
decl_stmt|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__sanitizer_dump_trace_pc_guard_coverage
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__sanitizer_cov
argument_list|(
name|__sanitizer
operator|::
name|u32
operator|*
name|guard
argument_list|)
decl_stmt|;
name|SANITIZER_INTERFACE_ATTRIBUTE
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
name|SANITIZER_INTERFACE_ATTRIBUTE
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
name|SANITIZER_INTERFACE_ATTRIBUTE
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
name|SANITIZER_INTERFACE_ATTRIBUTE
name|int
name|__sanitizer_get_module_and_offset_for_pc
argument_list|(
name|__sanitizer
operator|::
name|uptr
name|pc
argument_list|,
name|char
operator|*
name|module_path
argument_list|,
name|__sanitizer
operator|::
name|uptr
name|module_path_len
argument_list|,
name|__sanitizer
operator|::
name|uptr
operator|*
name|pc_offset
argument_list|)
decl_stmt|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
name|void
name|__sanitizer_cov_trace_cmp
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
name|void
name|__sanitizer_cov_trace_cmp1
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
name|void
name|__sanitizer_cov_trace_cmp2
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
name|void
name|__sanitizer_cov_trace_cmp4
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
name|void
name|__sanitizer_cov_trace_cmp8
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
name|void
name|__sanitizer_cov_trace_switch
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
name|void
name|__sanitizer_cov_trace_div4
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
name|void
name|__sanitizer_cov_trace_div8
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
name|void
name|__sanitizer_cov_trace_gep
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
name|void
name|__sanitizer_cov_trace_pc_indir
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
name|void
name|__sanitizer_cov_trace_pc_guard
argument_list|(
name|__sanitizer
operator|::
name|u32
operator|*
argument_list|)
decl_stmt|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
name|void
name|__sanitizer_cov_trace_pc_guard_init
argument_list|(
name|__sanitizer
operator|::
name|u32
operator|*
argument_list|,
name|__sanitizer
operator|::
name|u32
operator|*
argument_list|)
decl_stmt|;
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
comment|// SANITIZER_INTERFACE_INTERNAL_H
end_comment

end_unit

