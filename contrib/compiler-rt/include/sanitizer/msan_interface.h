begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- msan_interface.h --------------------------------------------------===//
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
comment|// This file is a part of MemorySanitizer.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Public interface header.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MSAN_INTERFACE_H
end_ifndef

begin_define
define|#
directive|define
name|MSAN_INTERFACE_H
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
comment|/* Set raw origin for the memory range. */
name|void
name|__msan_set_origin
parameter_list|(
specifier|const
specifier|volatile
name|void
modifier|*
name|a
parameter_list|,
name|size_t
name|size
parameter_list|,
name|uint32_t
name|origin
parameter_list|)
function_decl|;
comment|/* Get raw origin for an address. */
name|uint32_t
name|__msan_get_origin
parameter_list|(
specifier|const
specifier|volatile
name|void
modifier|*
name|a
parameter_list|)
function_decl|;
comment|/* Returns non-zero if tracking origins. */
name|int
name|__msan_get_track_origins
parameter_list|()
function_decl|;
comment|/* Returns the origin id of the latest UMR in the calling thread. */
name|uint32_t
name|__msan_get_umr_origin
parameter_list|()
function_decl|;
comment|/* Make memory region fully initialized (without changing its contents). */
name|void
name|__msan_unpoison
parameter_list|(
specifier|const
specifier|volatile
name|void
modifier|*
name|a
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
comment|/* Make a null-terminated string fully initialized (without changing its      contents). */
name|void
name|__msan_unpoison_string
parameter_list|(
specifier|const
specifier|volatile
name|char
modifier|*
name|a
parameter_list|)
function_decl|;
comment|/* Make memory region fully uninitialized (without changing its contents).      This is a legacy interface that does not update origin information. Use      __msan_allocated_memory() instead. */
name|void
name|__msan_poison
parameter_list|(
specifier|const
specifier|volatile
name|void
modifier|*
name|a
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
comment|/* Make memory region partially uninitialized (without changing its contents).    */
name|void
name|__msan_partial_poison
parameter_list|(
specifier|const
specifier|volatile
name|void
modifier|*
name|data
parameter_list|,
name|void
modifier|*
name|shadow
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
comment|/* Returns the offset of the first (at least partially) poisoned byte in the      memory range, or -1 if the whole range is good. */
name|intptr_t
name|__msan_test_shadow
parameter_list|(
specifier|const
specifier|volatile
name|void
modifier|*
name|x
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
comment|/* Checks that memory range is fully initialized, and reports an error if it    * is not. */
name|void
name|__msan_check_mem_is_initialized
parameter_list|(
specifier|const
specifier|volatile
name|void
modifier|*
name|x
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
comment|/* Set exit code when error(s) were detected.      Value of 0 means don't change the program exit code. */
name|void
name|__msan_set_exit_code
parameter_list|(
name|int
name|exit_code
parameter_list|)
function_decl|;
comment|/* For testing:      __msan_set_expect_umr(1);      ... some buggy code ...      __msan_set_expect_umr(0);      The last line will verify that a UMR happened. */
name|void
name|__msan_set_expect_umr
parameter_list|(
name|int
name|expect_umr
parameter_list|)
function_decl|;
comment|/* Change the value of keep_going flag. Non-zero value means don't terminate      program execution when an error is detected. This will not affect error in      modules that were compiled without the corresponding compiler flag. */
name|void
name|__msan_set_keep_going
parameter_list|(
name|int
name|keep_going
parameter_list|)
function_decl|;
comment|/* Print shadow and origin for the memory range to stderr in a human-readable      format. */
name|void
name|__msan_print_shadow
parameter_list|(
specifier|const
specifier|volatile
name|void
modifier|*
name|x
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
comment|/* Print shadow for the memory range to stderr in a minimalistic      human-readable format. */
name|void
name|__msan_dump_shadow
parameter_list|(
specifier|const
specifier|volatile
name|void
modifier|*
name|x
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
comment|/* Returns true if running under a dynamic tool (DynamoRio-based). */
name|int
name|__msan_has_dynamic_component
parameter_list|()
function_decl|;
comment|/* Tell MSan about newly allocated memory (ex.: custom allocator).      Memory will be marked uninitialized, with origin at the call site. */
name|void
name|__msan_allocated_memory
parameter_list|(
specifier|const
specifier|volatile
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
comment|/* This function may be optionally provided by user and should return      a string containing Msan runtime options. See msan_flags.h for details. */
specifier|const
name|char
modifier|*
name|__msan_default_options
parameter_list|()
function_decl|;
comment|/* Sets the callback to be called right before death on error.      Passing 0 will unset the callback. */
name|void
name|__msan_set_death_callback
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

end_unit

