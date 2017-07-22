begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- xray_utils.h --------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of XRay, a dynamic runtime instrumentation system.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Some shared utilities for the XRay runtime implementation.
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
name|XRAY_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|XRAY_UTILS_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|__xray
block|{
comment|// Default implementation of the reporting interface for sanitizer errors.
name|void
name|printToStdErr
parameter_list|(
specifier|const
name|char
modifier|*
name|Buffer
parameter_list|)
function_decl|;
comment|// EINTR-safe write routine, provided a file descriptor and a character range.
name|void
name|retryingWriteAll
parameter_list|(
name|int
name|Fd
parameter_list|,
name|char
modifier|*
name|Begin
parameter_list|,
name|char
modifier|*
name|End
parameter_list|)
function_decl|;
comment|// Reads a long long value from a provided file.
name|bool
name|readValueFromFile
parameter_list|(
specifier|const
name|char
modifier|*
name|Filename
parameter_list|,
name|long
name|long
modifier|*
name|Value
parameter_list|)
function_decl|;
comment|// EINTR-safe read routine, providing a file descriptor and a character range.
name|std
operator|::
name|pair
operator|<
name|ssize_t
operator|,
name|bool
operator|>
name|retryingReadSome
argument_list|(
argument|int Fd
argument_list|,
argument|char *Begin
argument_list|,
argument|char *End
argument_list|)
expr_stmt|;
comment|// EINTR-safe open routine, uses flag-provided values for initialising a log
comment|// file.
name|int
name|getLogFD
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __xray
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// XRAY_UTILS_H
end_comment

end_unit

