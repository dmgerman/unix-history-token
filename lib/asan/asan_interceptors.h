begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_interceptors.h -------------------------------------*- C++ -*-===//
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
comment|// ASan-private header for asan_interceptors.cc
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_INTERCEPTORS_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_INTERCEPTORS_H
end_define

begin_include
include|#
directive|include
file|"asan_internal.h"
end_include

begin_include
include|#
directive|include
file|"interception/interception.h"
end_include

begin_macro
name|DECLARE_REAL
argument_list|(
argument|int
argument_list|,
argument|memcmp
argument_list|,
argument|const void *a1
argument_list|,
argument|const void *a2
argument_list|,
argument|uptr size
argument_list|)
end_macro

begin_macro
name|DECLARE_REAL
argument_list|(
argument|void*
argument_list|,
argument|memcpy
argument_list|,
argument|void *to
argument_list|,
argument|const void *from
argument_list|,
argument|uptr size
argument_list|)
end_macro

begin_macro
name|DECLARE_REAL
argument_list|(
argument|void*
argument_list|,
argument|memset
argument_list|,
argument|void *block
argument_list|,
argument|int c
argument_list|,
argument|uptr size
argument_list|)
end_macro

begin_macro
name|DECLARE_REAL
argument_list|(
argument|char*
argument_list|,
argument|strchr
argument_list|,
argument|const char *str
argument_list|,
argument|int c
argument_list|)
end_macro

begin_macro
name|DECLARE_REAL
argument_list|(
argument|uptr
argument_list|,
argument|strlen
argument_list|,
argument|const char *s
argument_list|)
end_macro

begin_macro
name|DECLARE_REAL
argument_list|(
argument|char*
argument_list|,
argument|strncpy
argument_list|,
argument|char *to
argument_list|,
argument|const char *from
argument_list|,
argument|uptr size
argument_list|)
end_macro

begin_macro
name|DECLARE_REAL
argument_list|(
argument|uptr
argument_list|,
argument|strnlen
argument_list|,
argument|const char *s
argument_list|,
argument|uptr maxlen
argument_list|)
end_macro

begin_struct_decl
struct_decl|struct
name|sigaction
struct_decl|;
end_struct_decl

begin_macro
name|DECLARE_REAL
argument_list|(
argument|int
argument_list|,
argument|sigaction
argument_list|,
argument|int signum
argument_list|,
argument|const struct sigaction *act
argument_list|,
argument|struct sigaction *oldact
argument_list|)
end_macro

begin_decl_stmt
name|namespace
name|__asan
block|{
name|void
name|InitializeAsanInterceptors
parameter_list|()
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
name|void
name|InitializeMacInterceptors
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|// __APPLE__
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
comment|// ASAN_INTERCEPTORS_H
end_comment

end_unit

