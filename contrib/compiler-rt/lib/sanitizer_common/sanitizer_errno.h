begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_errno.h ---------------------------------------*- C++ -*-===//
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
comment|// This file is shared between sanitizers run-time libraries.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Defines errno to avoid including errno.h and its dependencies into sensitive
end_comment

begin_comment
comment|// files (e.g. interceptors are not supposed to include any system headers).
end_comment

begin_comment
comment|// It's ok to use errno.h directly when your file already depend on other system
end_comment

begin_comment
comment|// includes though.
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
name|SANITIZER_ERRNO_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_ERRNO_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_errno_codes.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_platform.h"
end_include

begin_if
if|#
directive|if
name|SANITIZER_FREEBSD
operator|||
name|SANITIZER_MAC
end_if

begin_define
define|#
directive|define
name|__errno_location
value|__error
end_define

begin_elif
elif|#
directive|elif
name|SANITIZER_ANDROID
end_elif

begin_define
define|#
directive|define
name|__errno_location
value|__errno
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_extern
extern|extern
literal|"C"
name|int
modifier|*
name|__errno_location
parameter_list|()
function_decl|;
end_extern

begin_define
define|#
directive|define
name|errno
value|(*__errno_location())
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_ERRNO_H
end_comment

end_unit

