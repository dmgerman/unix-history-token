begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_errno_codes.h ---------------------------------*- C++ -*-===//
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
comment|// Defines errno codes to avoid including errno.h and its dependencies into
end_comment

begin_comment
comment|// sensitive files (e.g. interceptors are not supposed to include any system
end_comment

begin_comment
comment|// headers).
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
name|SANITIZER_ERRNO_CODES_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_ERRNO_CODES_H
end_define

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
define|#
directive|define
name|errno_ENOMEM
value|12
define|#
directive|define
name|errno_EBUSY
value|16
define|#
directive|define
name|errno_EINVAL
value|22
comment|// Those might not present or their value differ on different platforms.
specifier|extern
specifier|const
name|int
name|errno_EOWNERDEAD
decl_stmt|;
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
comment|// SANITIZER_ERRNO_CODES_H
end_comment

end_unit

