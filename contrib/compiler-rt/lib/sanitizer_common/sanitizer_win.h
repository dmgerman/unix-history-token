begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_win.h -----------------------------------------*- C++ -*-===//
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
comment|// Windows-specific declarations.
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
name|SANITIZER_WIN_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_WIN_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_platform.h"
end_include

begin_if
if|#
directive|if
name|SANITIZER_WINDOWS
end_if

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
comment|// Check based on flags if we should handle the exception.
name|bool
name|IsHandledDeadlyException
parameter_list|(
name|DWORD
name|exceptionCode
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_WINDOWS
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_WIN_H
end_comment

end_unit

