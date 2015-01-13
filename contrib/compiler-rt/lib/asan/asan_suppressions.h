begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_suppressions.h -------------------------------------*- C++ -*-===//
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
comment|// ASan-private header for asan_suppressions.cc.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_SUPPRESSIONS_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_SUPPRESSIONS_H
end_define

begin_include
include|#
directive|include
file|"asan_internal.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_stacktrace.h"
end_include

begin_decl_stmt
name|namespace
name|__asan
block|{
name|void
name|InitializeSuppressions
parameter_list|()
function_decl|;
name|bool
name|IsInterceptorSuppressed
parameter_list|(
specifier|const
name|char
modifier|*
name|interceptor_name
parameter_list|)
function_decl|;
name|bool
name|HaveStackTraceBasedSuppressions
parameter_list|()
function_decl|;
name|bool
name|IsStackTraceSuppressed
parameter_list|(
specifier|const
name|StackTrace
modifier|*
name|stack
parameter_list|)
function_decl|;
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
comment|// ASAN_SUPPRESSIONS_H
end_comment

end_unit

