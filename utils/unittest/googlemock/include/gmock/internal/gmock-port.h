begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright 2008, Google Inc.
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
comment|// Author: vadimb@google.com (Vadim Berman)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Low-level types and utilities for porting Google Mock to various
end_comment

begin_comment
comment|// platforms.  All macros ending with _ and symbols defined in an
end_comment

begin_comment
comment|// internal namespace are subject to change without notice.  Code
end_comment

begin_comment
comment|// outside Google Mock MUST NOT USE THEM DIRECTLY.  Macros that don't
end_comment

begin_comment
comment|// end with _ are part of Google Mock's public API and can be used by
end_comment

begin_comment
comment|// code outside Google Mock.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_PORT_H_
end_ifndef

begin_define
define|#
directive|define
name|GMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_PORT_H_
end_define

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<iostream>
end_include

begin_comment
comment|// Most of the utilities needed for porting Google Mock are also
end_comment

begin_comment
comment|// required for Google Test and are defined in gtest-port.h.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note to maintainers: to reduce code duplication, prefer adding
end_comment

begin_comment
comment|// portability utilities to Google Test's gtest-port.h instead of
end_comment

begin_comment
comment|// here, as Google Mock depends on Google Test.  Only add a utility
end_comment

begin_comment
comment|// here if it's truly specific to Google Mock.
end_comment

begin_include
include|#
directive|include
file|"gtest/internal/gtest-linked_ptr.h"
end_include

begin_include
include|#
directive|include
file|"gtest/internal/gtest-port.h"
end_include

begin_include
include|#
directive|include
file|"gmock/internal/custom/gmock-port.h"
end_include

begin_comment
comment|// To avoid conditional compilation everywhere, we make it
end_comment

begin_comment
comment|// gmock-port.h's responsibility to #include the header implementing
end_comment

begin_comment
comment|// tr1/tuple.  gmock-port.h does this via gtest-port.h, which is
end_comment

begin_comment
comment|// guaranteed to pull in the tuple header.
end_comment

begin_comment
comment|// For MS Visual C++, check the compiler version. At least VS 2003 is
end_comment

begin_comment
comment|// required to compile Google Mock.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|<
literal|1310
end_if

begin_error
error|#
directive|error
literal|"At least Visual C++ 2003 (7.1) is required to compile Google Mock."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Macro for referencing flags.  This is public as we want the user to
end_comment

begin_comment
comment|// use this syntax to reference Google Mock flags.
end_comment

begin_define
define|#
directive|define
name|GMOCK_FLAG
parameter_list|(
name|name
parameter_list|)
value|FLAGS_gmock_##name
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GMOCK_DECLARE_bool_
argument_list|)
end_if

begin_comment
comment|// Macros for declaring flags.
end_comment

begin_define
define|#
directive|define
name|GMOCK_DECLARE_bool_
parameter_list|(
name|name
parameter_list|)
value|extern GTEST_API_ bool GMOCK_FLAG(name)
end_define

begin_define
define|#
directive|define
name|GMOCK_DECLARE_int32_
parameter_list|(
name|name
parameter_list|)
define|\
value|extern GTEST_API_ ::testing::internal::Int32 GMOCK_FLAG(name)
end_define

begin_define
define|#
directive|define
name|GMOCK_DECLARE_string_
parameter_list|(
name|name
parameter_list|)
define|\
value|extern GTEST_API_ ::std::string GMOCK_FLAG(name)
end_define

begin_comment
comment|// Macros for defining flags.
end_comment

begin_define
define|#
directive|define
name|GMOCK_DEFINE_bool_
parameter_list|(
name|name
parameter_list|,
name|default_val
parameter_list|,
name|doc
parameter_list|)
define|\
value|GTEST_API_ bool GMOCK_FLAG(name) = (default_val)
end_define

begin_define
define|#
directive|define
name|GMOCK_DEFINE_int32_
parameter_list|(
name|name
parameter_list|,
name|default_val
parameter_list|,
name|doc
parameter_list|)
define|\
value|GTEST_API_ ::testing::internal::Int32 GMOCK_FLAG(name) = (default_val)
end_define

begin_define
define|#
directive|define
name|GMOCK_DEFINE_string_
parameter_list|(
name|name
parameter_list|,
name|default_val
parameter_list|,
name|doc
parameter_list|)
define|\
value|GTEST_API_ ::std::string GMOCK_FLAG(name) = (default_val)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GMOCK_DECLARE_bool_)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_PORT_H_
end_comment

end_unit

