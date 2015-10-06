begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_mac.h -----------------------------------------*- C++ -*-===//
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
comment|// This file is shared between various sanitizers' runtime libraries and
end_comment

begin_comment
comment|// provides definitions for OSX-specific functions.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_MAC_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_MAC_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_platform.h"
end_include

begin_if
if|#
directive|if
name|SANITIZER_MAC
end_if

begin_include
include|#
directive|include
file|"sanitizer_posix.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
enum|enum
name|MacosVersion
block|{
name|MACOS_VERSION_UNINITIALIZED
init|=
literal|0
block|,
name|MACOS_VERSION_UNKNOWN
block|,
name|MACOS_VERSION_LEOPARD
block|,
name|MACOS_VERSION_SNOW_LEOPARD
block|,
name|MACOS_VERSION_LION
block|,
name|MACOS_VERSION_MOUNTAIN_LION
block|,
name|MACOS_VERSION_MAVERICKS
block|,
name|MACOS_VERSION_YOSEMITE
block|,
name|MACOS_VERSION_UNKNOWN_NEWER
block|}
enum|;
name|MacosVersion
name|GetMacosVersion
parameter_list|()
function_decl|;
name|char
modifier|*
modifier|*
name|GetEnviron
parameter_list|()
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
comment|// SANITIZER_MAC
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_MAC_H
end_comment

end_unit

