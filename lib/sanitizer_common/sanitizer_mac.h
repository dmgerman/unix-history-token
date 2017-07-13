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
file|"sanitizer_common.h"
end_include

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
name|void
name|RestrictMemoryToMaxAddress
parameter_list|(
name|uptr
name|max_address
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_extern
extern|extern
literal|"C"
block|{
specifier|static
name|char
name|__crashreporter_info_buff__
index|[
name|__sanitizer
operator|::
name|kErrorMessageBufferSize
index|]
init|=
block|{}
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|__crashreporter_info__
name|__attribute__
argument_list|(
operator|(
name|__used__
operator|)
argument_list|)
init|=
operator|&
name|__crashreporter_info_buff__
index|[
literal|0
index|]
decl_stmt|;
asm|asm(".desc ___crashreporter_info__, 0x10");
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
specifier|static
name|BlockingMutex
name|crashreporter_info_mutex
parameter_list|(
name|LINKER_INITIALIZED
parameter_list|)
function_decl|;
name|INLINE
name|void
name|CRAppendCrashLogMessage
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
block|{
name|BlockingMutexLock
name|l
argument_list|(
operator|&
name|crashreporter_info_mutex
argument_list|)
decl_stmt|;
name|internal_strlcat
argument_list|(
name|__crashreporter_info_buff__
argument_list|,
name|msg
argument_list|,
sizeof|sizeof
argument_list|(
name|__crashreporter_info_buff__
argument_list|)
argument_list|)
expr_stmt|;
block|}
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

