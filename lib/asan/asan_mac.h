begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_mac.h ----------------------------------------------*- C++ -*-===//
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
comment|// Mac-specific ASan definitions.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_MAC_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_MAC_H
end_define

begin_comment
comment|// CF_RC_BITS, the layout of CFRuntimeBase and __CFStrIsConstant are internal
end_comment

begin_comment
comment|// and subject to change in further CoreFoundation versions. Apple does not
end_comment

begin_comment
comment|// guarantee any binary compatibility from release to release.
end_comment

begin_comment
comment|// See http://opensource.apple.com/source/CF/CF-635.15/CFInternal.h
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN__
argument_list|)
end_if

begin_define
define|#
directive|define
name|CF_RC_BITS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN__
argument_list|)
end_if

begin_define
define|#
directive|define
name|CF_RC_BITS
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// See http://opensource.apple.com/source/CF/CF-635.15/CFRuntime.h
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__CFRuntimeBase
block|{
name|uptr
name|_cfisa
decl_stmt|;
name|u8
name|_cfinfo
index|[
literal|4
index|]
decl_stmt|;
if|#
directive|if
name|__LP64__
name|u32
name|_rc
decl_stmt|;
endif|#
directive|endif
block|}
name|CFRuntimeBase
typedef|;
end_typedef

begin_enum
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
block|}
enum|;
end_enum

begin_comment
comment|// Used by asan_malloc_mac.cc and asan_mac.cc
end_comment

begin_extern
extern|extern
literal|"C"
name|void
name|__CFInitialize
parameter_list|()
function_decl|;
end_extern

begin_decl_stmt
name|namespace
name|__asan
block|{
name|MacosVersion
name|GetMacosVersion
parameter_list|()
function_decl|;
name|void
name|MaybeReplaceCFAllocator
parameter_list|()
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
comment|// ASAN_MAC_H
end_comment

end_unit

