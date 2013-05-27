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
if|#
directive|if
name|__has_feature
argument_list|(
name|memory_sanitizer
argument_list|)
comment|/* Returns a string describing a stack origin.      Return NULL if the origin is invalid, or is not a stack origin. */
specifier|const
name|char
modifier|*
name|__msan_get_origin_descr_if_stack
parameter_list|(
name|uint32_t
name|id
parameter_list|)
function_decl|;
comment|/* Set raw origin for the memory range. */
name|void
name|__msan_set_origin
parameter_list|(
specifier|const
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
name|void
modifier|*
name|a
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
comment|/* Make memory region fully uninitialized (without changing its contents). */
name|void
name|__msan_poison
parameter_list|(
specifier|const
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
comment|/* Print shadow and origin for the memory range to stdout in a human-readable      format. */
name|void
name|__msan_print_shadow
parameter_list|(
specifier|const
name|void
modifier|*
name|x
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
comment|/* Print current function arguments shadow and origin to stdout in a      human-readable format. */
name|void
name|__msan_print_param_shadow
parameter_list|()
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
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
else|#
directive|else
comment|// __has_feature(memory_sanitizer)
define|#
directive|define
name|__msan_get_origin_descr_if_stack
parameter_list|(
name|id
parameter_list|)
value|((const char*)0)
define|#
directive|define
name|__msan_set_origin
parameter_list|(
name|a
parameter_list|,
name|size
parameter_list|,
name|origin
parameter_list|)
define|#
directive|define
name|__msan_get_origin
parameter_list|(
name|a
parameter_list|)
value|((uint32_t)-1)
define|#
directive|define
name|__msan_get_track_origins
parameter_list|()
value|(0)
define|#
directive|define
name|__msan_get_umr_origin
parameter_list|()
value|((uint32_t)-1)
define|#
directive|define
name|__msan_unpoison
parameter_list|(
name|a
parameter_list|,
name|size
parameter_list|)
define|#
directive|define
name|__msan_poison
parameter_list|(
name|a
parameter_list|,
name|size
parameter_list|)
define|#
directive|define
name|__msan_partial_poison
parameter_list|(
name|data
parameter_list|,
name|shadow
parameter_list|,
name|size
parameter_list|)
define|#
directive|define
name|__msan_test_shadow
parameter_list|(
name|x
parameter_list|,
name|size
parameter_list|)
value|((intptr_t)-1)
define|#
directive|define
name|__msan_set_exit_code
parameter_list|(
name|exit_code
parameter_list|)
define|#
directive|define
name|__msan_set_expect_umr
parameter_list|(
name|expect_umr
parameter_list|)
define|#
directive|define
name|__msan_print_shadow
parameter_list|(
name|x
parameter_list|,
name|size
parameter_list|)
define|#
directive|define
name|__msan_print_param_shadow
parameter_list|()
define|#
directive|define
name|__msan_has_dynamic_component
parameter_list|()
value|(0)
define|#
directive|define
name|__msan_allocated_memory
parameter_list|(
name|data
parameter_list|,
name|size
parameter_list|)
endif|#
directive|endif
comment|// __has_feature(memory_sanitizer)
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

