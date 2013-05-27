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
comment|// Tell the tools to write their reports to given file descriptor instead of
comment|// stderr.
name|void
name|__sanitizer_set_report_fd
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
comment|// Notify the tools that the sandbox is going to be turned on. The reserved
comment|// parameter will be used in the future to hold a structure with functions
comment|// that the tools may call to bypass the sandbox.
name|void
name|__sanitizer_sandbox_on_notify
parameter_list|(
name|void
modifier|*
name|reserved
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

