begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lldb-windows.h ------------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLDB_lldb_windows_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_lldb_windows_h_
end_define

begin_define
define|#
directive|define
name|NTDDI_VERSION
value|NTDDI_VISTA
end_define

begin_undef
undef|#
directive|undef
name|_WIN32_WINNT
end_undef

begin_comment
comment|// undef a previous definition to avoid warning
end_comment

begin_define
define|#
directive|define
name|_WIN32_WINNT
value|_WIN32_WINNT_VISTA
end_define

begin_define
define|#
directive|define
name|WIN32_LEAN_AND_MEAN
end_define

begin_define
define|#
directive|define
name|NOGDI
end_define

begin_undef
undef|#
directive|undef
name|NOMINMAX
end_undef

begin_comment
comment|// undef a previous definition to avoid warning
end_comment

begin_define
define|#
directive|define
name|NOMINMAX
end_define

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_undef
undef|#
directive|undef
name|GetUserName
end_undef

begin_undef
undef|#
directive|undef
name|LoadImage
end_undef

begin_undef
undef|#
directive|undef
name|CreateProcess
end_undef

begin_undef
undef|#
directive|undef
name|far
end_undef

begin_undef
undef|#
directive|undef
name|near
end_undef

begin_undef
undef|#
directive|undef
name|FAR
end_undef

begin_undef
undef|#
directive|undef
name|NEAR
end_undef

begin_define
define|#
directive|define
name|FAR
end_define

begin_define
define|#
directive|define
name|NEAR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_lldb_windows_h_
end_comment

end_unit

