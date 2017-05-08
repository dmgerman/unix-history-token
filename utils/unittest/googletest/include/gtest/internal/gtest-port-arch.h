begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright 2015, Google Inc.
end_comment

begin_comment
comment|// All rights reserved.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Redistribution and use in source and binary forms, with or without
end_comment

begin_comment
comment|// modification, are permitted provided that the following conditions are
end_comment

begin_comment
comment|// met:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     * Redistributions of source code must retain the above copyright
end_comment

begin_comment
comment|// notice, this list of conditions and the following disclaimer.
end_comment

begin_comment
comment|//     * Redistributions in binary form must reproduce the above
end_comment

begin_comment
comment|// copyright notice, this list of conditions and the following disclaimer
end_comment

begin_comment
comment|// in the documentation and/or other materials provided with the
end_comment

begin_comment
comment|// distribution.
end_comment

begin_comment
comment|//     * Neither the name of Google Inc. nor the names of its
end_comment

begin_comment
comment|// contributors may be used to endorse or promote products derived from
end_comment

begin_comment
comment|// this software without specific prior written permission.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
end_comment

begin_comment
comment|// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
end_comment

begin_comment
comment|// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
end_comment

begin_comment
comment|// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
end_comment

begin_comment
comment|// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
end_comment

begin_comment
comment|// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
end_comment

begin_comment
comment|// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
end_comment

begin_comment
comment|// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
end_comment

begin_comment
comment|// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
end_comment

begin_comment
comment|// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
end_comment

begin_comment
comment|// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The Google C++ Testing Framework (Google Test)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This header file defines the GTEST_OS_* macro.
end_comment

begin_comment
comment|// It is separate from gtest-port.h so that custom/gtest-port.h can include it.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_INCLUDE_GTEST_INTERNAL_GTEST_PORT_ARCH_H_
end_ifndef

begin_define
define|#
directive|define
name|GTEST_INCLUDE_GTEST_INTERNAL_GTEST_PORT_ARCH_H_
end_define

begin_comment
comment|// Determines the platform on which Google Test is compiled.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__CYGWIN__
end_ifdef

begin_define
define|#
directive|define
name|GTEST_OS_CYGWIN
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
name|__SYMBIAN32__
end_elif

begin_define
define|#
directive|define
name|GTEST_OS_SYMBIAN
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
name|_WIN32
end_elif

begin_define
define|#
directive|define
name|GTEST_OS_WINDOWS
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32_WCE
end_ifdef

begin_define
define|#
directive|define
name|GTEST_OS_WINDOWS_MOBILE
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__MINGW__
argument_list|)
operator|||
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|GTEST_OS_WINDOWS_MINGW
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|WINAPI_FAMILY
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<winapifamily.h>
end_include

begin_if
if|#
directive|if
name|WINAPI_FAMILY_PARTITION
argument_list|(
name|WINAPI_PARTITION_DESKTOP
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_OS_WINDOWS_DESKTOP
value|1
end_define

begin_elif
elif|#
directive|elif
name|WINAPI_FAMILY_PARTITION
argument_list|(
name|WINAPI_PARTITION_PHONE_APP
argument_list|)
end_elif

begin_define
define|#
directive|define
name|GTEST_OS_WINDOWS_PHONE
value|1
end_define

begin_elif
elif|#
directive|elif
name|WINAPI_FAMILY_PARTITION
argument_list|(
name|WINAPI_PARTITION_APP
argument_list|)
end_elif

begin_define
define|#
directive|define
name|GTEST_OS_WINDOWS_RT
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// WINAPI_FAMILY defined but no known partition matched.
end_comment

begin_comment
comment|// Default to desktop.
end_comment

begin_define
define|#
directive|define
name|GTEST_OS_WINDOWS_DESKTOP
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_OS_WINDOWS_DESKTOP
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _WIN32_WCE
end_comment

begin_elif
elif|#
directive|elif
name|defined
name|__APPLE__
end_elif

begin_define
define|#
directive|define
name|GTEST_OS_MAC
value|1
end_define

begin_if
if|#
directive|if
name|TARGET_OS_IPHONE
end_if

begin_define
define|#
directive|define
name|GTEST_OS_IOS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
name|__FreeBSD__
end_elif

begin_define
define|#
directive|define
name|GTEST_OS_FREEBSD
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
name|__linux__
end_elif

begin_define
define|#
directive|define
name|GTEST_OS_LINUX
value|1
end_define

begin_if
if|#
directive|if
name|defined
name|__ANDROID__
end_if

begin_define
define|#
directive|define
name|GTEST_OS_LINUX_ANDROID
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
name|__MVS__
end_elif

begin_define
define|#
directive|define
name|GTEST_OS_ZOS
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sun
argument_list|)
operator|&&
name|defined
argument_list|(
name|__SVR4
argument_list|)
end_elif

begin_define
define|#
directive|define
name|GTEST_OS_SOLARIS
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_AIX
argument_list|)
end_elif

begin_define
define|#
directive|define
name|GTEST_OS_AIX
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__hpux
argument_list|)
end_elif

begin_define
define|#
directive|define
name|GTEST_OS_HPUX
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
name|__native_client__
end_elif

begin_define
define|#
directive|define
name|GTEST_OS_NACL
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
name|__NetBSD__
end_elif

begin_define
define|#
directive|define
name|GTEST_OS_NETBSD
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
name|__OpenBSD__
end_elif

begin_define
define|#
directive|define
name|GTEST_OS_OPENBSD
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
name|__QNX__
end_elif

begin_define
define|#
directive|define
name|GTEST_OS_QNX
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__HAIKU__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|GTEST_OS_HAIKU
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MINIX
argument_list|)
end_elif

begin_define
define|#
directive|define
name|GTEST_OS_MINIX
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __CYGWIN__
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_INCLUDE_GTEST_INTERNAL_GTEST_PORT_ARCH_H_
end_comment

end_unit

