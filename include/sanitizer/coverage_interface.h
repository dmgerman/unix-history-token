begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer/coverage_interface.h --------------------------*- C++ -*-===//
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
comment|// Public interface for sanitizer coverage.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_COVERAG_INTERFACE_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_COVERAG_INTERFACE_H
end_define

begin_include
include|#
directive|include
file|<sanitizer/common_interface_defs.h>
end_include

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
comment|// Reset the basic-block (edge) coverage to the initial state.
comment|// Useful for in-process fuzzing to start collecting coverage from scratch.
comment|// Experimental, will likely not work for multi-threaded process.
name|void
name|__sanitizer_reset_coverage
parameter_list|()
function_decl|;
comment|// Set *data to the array of covered PCs and return the size of that array.
comment|// Some of the entries in *data will be zero.
name|uintptr_t
name|__sanitizer_get_coverage_guards
parameter_list|(
name|uintptr_t
modifier|*
modifier|*
name|data
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
comment|// SANITIZER_COVERAG_INTERFACE_H
end_comment

end_unit

