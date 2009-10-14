begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright 2005, Google Inc.
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
comment|// Authors: wan@google.com (Zhanyong Wan)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Low-level types and utilities for porting Google Test to various
end_comment

begin_comment
comment|// platforms.  They are subject to change without notice.  DO NOT USE
end_comment

begin_comment
comment|// THEM IN USER CODE.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_INCLUDE_GTEST_INTERNAL_GTEST_PORT_H_
end_ifndef

begin_define
define|#
directive|define
name|GTEST_INCLUDE_GTEST_INTERNAL_GTEST_PORT_H_
end_define

begin_comment
comment|// The user can define the following macros in the build script to
end_comment

begin_comment
comment|// control Google Test's behavior.  If the user doesn't define a macro
end_comment

begin_comment
comment|// in this list, Google Test will define it.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   GTEST_HAS_CLONE          - Define it to 1/0 to indicate that clone(2)
end_comment

begin_comment
comment|//                              is/isn't available.
end_comment

begin_comment
comment|//   GTEST_HAS_GLOBAL_STRING  - Define it to 1/0 to indicate that ::string
end_comment

begin_comment
comment|//                              is/isn't available (some systems define
end_comment

begin_comment
comment|//                              ::string, which is different to std::string).
end_comment

begin_comment
comment|//   GTEST_HAS_GLOBAL_WSTRING - Define it to 1/0 to indicate that ::string
end_comment

begin_comment
comment|//                              is/isn't available (some systems define
end_comment

begin_comment
comment|//                              ::wstring, which is different to std::wstring).
end_comment

begin_comment
comment|//   GTEST_HAS_PTHREAD        - Define it to 1/0 to indicate that<pthread.h>
end_comment

begin_comment
comment|//                              is/isn't available.
end_comment

begin_comment
comment|//   GTEST_HAS_RTTI           - Define it to 1/0 to indicate that RTTI is/isn't
end_comment

begin_comment
comment|//                              enabled.
end_comment

begin_comment
comment|//   GTEST_HAS_STD_STRING     - Define it to 1/0 to indicate that
end_comment

begin_comment
comment|//                              std::string does/doesn't work (Google Test can
end_comment

begin_comment
comment|//                              be used where std::string is unavailable).
end_comment

begin_comment
comment|//   GTEST_HAS_STD_WSTRING    - Define it to 1/0 to indicate that
end_comment

begin_comment
comment|//                              std::wstring does/doesn't work (Google Test can
end_comment

begin_comment
comment|//                              be used where std::wstring is unavailable).
end_comment

begin_comment
comment|//   GTEST_HAS_TR1_TUPLE 1    - Define it to 1/0 to indicate tr1::tuple
end_comment

begin_comment
comment|//                              is/isn't available.
end_comment

begin_comment
comment|// This header defines the following utilities:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Macros indicating the name of the Google C++ Testing Framework project:
end_comment

begin_comment
comment|//   GTEST_NAME              - a string literal of the project name.
end_comment

begin_comment
comment|//   GTEST_FLAG_PREFIX       - a string literal of the prefix all Google
end_comment

begin_comment
comment|//                             Test flag names share.
end_comment

begin_comment
comment|//   GTEST_FLAG_PREFIX_UPPER - a string literal of the prefix all Google
end_comment

begin_comment
comment|//                             Test flag names share, in upper case.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Macros indicating the current platform:
end_comment

begin_comment
comment|//   GTEST_OS_CYGWIN   - defined iff compiled on Cygwin.
end_comment

begin_comment
comment|//   GTEST_OS_LINUX    - defined iff compiled on Linux.
end_comment

begin_comment
comment|//   GTEST_OS_MAC      - defined iff compiled on Mac OS X.
end_comment

begin_comment
comment|//   GTEST_OS_SOLARIS  - defined iff compiled on Sun Solaris.
end_comment

begin_comment
comment|//   GTEST_OS_SYMBIAN  - defined iff compiled for Symbian.
end_comment

begin_comment
comment|//   GTEST_OS_WINDOWS  - defined iff compiled on Windows.
end_comment

begin_comment
comment|//   GTEST_OS_ZOS      - defined iff compiled on IBM z/OS.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Among the platforms, Cygwin, Linux, Max OS X, and Windows have the
end_comment

begin_comment
comment|// most stable support.  Since core members of the Google Test project
end_comment

begin_comment
comment|// don't have access to other platforms, support for them may be less
end_comment

begin_comment
comment|// stable.  If you notice any problems on your platform, please notify
end_comment

begin_comment
comment|// googletestframework@googlegroups.com (patches for fixing them are
end_comment

begin_comment
comment|// even more welcome!).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that it is possible that none of the GTEST_OS_ macros are defined.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Macros indicating available Google Test features:
end_comment

begin_comment
comment|//   GTEST_HAS_COMBINE      - defined iff Combine construct is supported
end_comment

begin_comment
comment|//                            in value-parameterized tests.
end_comment

begin_comment
comment|//   GTEST_HAS_DEATH_TEST   - defined iff death tests are supported.
end_comment

begin_comment
comment|//   GTEST_HAS_PARAM_TEST   - defined iff value-parameterized tests are
end_comment

begin_comment
comment|//                            supported.
end_comment

begin_comment
comment|//   GTEST_HAS_TYPED_TEST   - defined iff typed tests are supported.
end_comment

begin_comment
comment|//   GTEST_HAS_TYPED_TEST_P - defined iff type-parameterized tests are
end_comment

begin_comment
comment|//                            supported.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Macros for basic C++ coding:
end_comment

begin_comment
comment|//   GTEST_AMBIGUOUS_ELSE_BLOCKER_ - for disabling a gcc warning.
end_comment

begin_comment
comment|//   GTEST_ATTRIBUTE_UNUSED_  - declares that a class' instances don't have to
end_comment

begin_comment
comment|//                              be used.
end_comment

begin_comment
comment|//   GTEST_DISALLOW_COPY_AND_ASSIGN_ - disables copy ctor and operator=.
end_comment

begin_comment
comment|//   GTEST_MUST_USE_RESULT_   - declares that a function's result must be used.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Synchronization:
end_comment

begin_comment
comment|//   Mutex, MutexLock, ThreadLocal, GetThreadCount()
end_comment

begin_comment
comment|//                  - synchronization primitives.
end_comment

begin_comment
comment|//   GTEST_IS_THREADSAFE - defined to 1 to indicate that the above
end_comment

begin_comment
comment|//                         synchronization primitives have real implementations
end_comment

begin_comment
comment|//                         and Google Test is thread-safe; or 0 otherwise.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Template meta programming:
end_comment

begin_comment
comment|//   is_pointer     - as in TR1; needed on Symbian and IBM XL C/C++ only.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Smart pointers:
end_comment

begin_comment
comment|//   scoped_ptr     - as in TR2.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Regular expressions:
end_comment

begin_comment
comment|//   RE             - a simple regular expression class using the POSIX
end_comment

begin_comment
comment|//                    Extended Regular Expression syntax.  Not available on
end_comment

begin_comment
comment|//                    Windows.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Logging:
end_comment

begin_comment
comment|//   GTEST_LOG_()   - logs messages at the specified severity level.
end_comment

begin_comment
comment|//   LogToStderr()  - directs all log messages to stderr.
end_comment

begin_comment
comment|//   FlushInfoLog() - flushes informational log messages.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Stderr capturing:
end_comment

begin_comment
comment|//   CaptureStderr()     - starts capturing stderr.
end_comment

begin_comment
comment|//   GetCapturedStderr() - stops capturing stderr and returns the captured
end_comment

begin_comment
comment|//                         string.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Integer types:
end_comment

begin_comment
comment|//   TypeWithSize   - maps an integer to a int type.
end_comment

begin_comment
comment|//   Int32, UInt32, Int64, UInt64, TimeInMillis
end_comment

begin_comment
comment|//                  - integers of known sizes.
end_comment

begin_comment
comment|//   BiggestInt     - the biggest signed integer type.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Command-line utilities:
end_comment

begin_comment
comment|//   GTEST_FLAG()       - references a flag.
end_comment

begin_comment
comment|//   GTEST_DECLARE_*()  - declares a flag.
end_comment

begin_comment
comment|//   GTEST_DEFINE_*()   - defines a flag.
end_comment

begin_comment
comment|//   GetArgvs()         - returns the command line as a vector of strings.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Environment variable utilities:
end_comment

begin_comment
comment|//   GetEnv()             - gets the value of an environment variable.
end_comment

begin_comment
comment|//   BoolFromGTestEnv()   - parses a bool environment variable.
end_comment

begin_comment
comment|//   Int32FromGTestEnv()  - parses an Int32 environment variable.
end_comment

begin_comment
comment|//   StringFromGTestEnv() - parses a string environment variable.
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<iostream>
end_include

begin_comment
comment|// Used for GTEST_CHECK_
end_comment

begin_define
define|#
directive|define
name|GTEST_NAME
value|"Google Test"
end_define

begin_define
define|#
directive|define
name|GTEST_FLAG_PREFIX
value|"gtest_"
end_define

begin_define
define|#
directive|define
name|GTEST_FLAG_PREFIX_UPPER
value|"GTEST_"
end_define

begin_comment
comment|// Determines the version of gcc that is used to compile this.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_comment
comment|// 40302 means version 4.3.2.
end_comment

begin_define
define|#
directive|define
name|GTEST_GCC_VER_
define|\
value|(__GNUC__*10000 + __GNUC_MINOR__*100 + __GNUC_PATCHLEVEL__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __GNUC__
end_comment

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
end_define

begin_elif
elif|#
directive|elif
name|__SYMBIAN32__
end_elif

begin_define
define|#
directive|define
name|GTEST_OS_SYMBIAN
end_define

begin_elif
elif|#
directive|elif
name|defined
name|_MSC_VER
end_elif

begin_comment
comment|// TODO(kenton@google.com): GTEST_OS_WINDOWS is currently used to mean
end_comment

begin_comment
comment|//   both "The OS is Windows" and "The compiler is MSVC".  These
end_comment

begin_comment
comment|//   meanings really should be separated in order to better support
end_comment

begin_comment
comment|//   Windows compilers other than MSVC.
end_comment

begin_define
define|#
directive|define
name|GTEST_OS_WINDOWS
end_define

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
end_define

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
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _MSC_VER
end_comment

begin_comment
comment|// Determines whether ::std::string and ::string are available.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_HAS_STD_STRING
end_ifndef

begin_comment
comment|// The user didn't tell us whether ::std::string is available, so we
end_comment

begin_comment
comment|// need to figure it out.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GTEST_OS_WINDOWS
end_ifdef

begin_comment
comment|// Assumes that exceptions are enabled by default.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HAS_EXCEPTIONS
end_ifndef

begin_define
define|#
directive|define
name|_HAS_EXCEPTIONS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _HAS_EXCEPTIONS
end_comment

begin_comment
comment|// GTEST_HAS_EXCEPTIONS is non-zero iff exceptions are enabled.  It is
end_comment

begin_comment
comment|// always defined, while _HAS_EXCEPTIONS is defined only on Windows.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_EXCEPTIONS
value|_HAS_EXCEPTIONS
end_define

begin_comment
comment|// On Windows, we can use ::std::string if the compiler version is VS
end_comment

begin_comment
comment|// 2005 or above, or if exceptions are enabled.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_STD_STRING
value|((_MSC_VER>= 1400) || GTEST_HAS_EXCEPTIONS)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// We are on Linux or Mac OS.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_EXCEPTIONS
value|0
end_define

begin_define
define|#
directive|define
name|GTEST_HAS_STD_STRING
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_OS_WINDOWS
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_STD_STRING
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_HAS_GLOBAL_STRING
end_ifndef

begin_comment
comment|// The user didn't tell us whether ::string is available, so we need
end_comment

begin_comment
comment|// to figure it out.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_GLOBAL_STRING
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_GLOBAL_STRING
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_HAS_STD_WSTRING
end_ifndef

begin_comment
comment|// The user didn't tell us whether ::std::wstring is available, so we need
end_comment

begin_comment
comment|// to figure it out.
end_comment

begin_comment
comment|// TODO(wan@google.com): uses autoconf to detect whether ::std::wstring
end_comment

begin_comment
comment|//   is available.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|GTEST_OS_CYGWIN
argument_list|)
operator|||
name|defined
argument_list|(
name|GTEST_OS_SOLARIS
argument_list|)
operator|||
name|defined
argument_list|(
name|GTEST_OS_HAIKU
argument_list|)
end_if

begin_comment
comment|// At least some versions of cygwin don't support ::std::wstring.
end_comment

begin_comment
comment|// Solaris' libc++ doesn't support it either.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_STD_WSTRING
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_HAS_STD_WSTRING
value|GTEST_HAS_STD_STRING
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined(GTEST_OS_CYGWIN) || defined(GTEST_OS_SOLARIS)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_STD_WSTRING
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_HAS_GLOBAL_WSTRING
end_ifndef

begin_comment
comment|// The user didn't tell us whether ::wstring is available, so we need
end_comment

begin_comment
comment|// to figure it out.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_GLOBAL_WSTRING
value|GTEST_HAS_GLOBAL_STRING
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_GLOBAL_WSTRING
end_comment

begin_if
if|#
directive|if
name|GTEST_HAS_STD_STRING
operator|||
name|GTEST_HAS_GLOBAL_STRING
operator|||
expr|\
name|GTEST_HAS_STD_WSTRING
operator|||
name|GTEST_HAS_GLOBAL_WSTRING
end_if

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// NOLINT
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_STD_STRING || GTEST_HAS_GLOBAL_STRING ||
end_comment

begin_comment
comment|// GTEST_HAS_STD_WSTRING || GTEST_HAS_GLOBAL_WSTRING
end_comment

begin_if
if|#
directive|if
name|GTEST_HAS_STD_STRING
end_if

begin_include
include|#
directive|include
file|<sstream>
end_include

begin_comment
comment|// NOLINT
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strstream>
end_include

begin_comment
comment|// NOLINT
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_STD_STRING
end_comment

begin_comment
comment|// Determines whether RTTI is available.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_HAS_RTTI
end_ifndef

begin_comment
comment|// The user didn't tell us whether RTTI is enabled, so we need to
end_comment

begin_comment
comment|// figure it out.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_CPPRTTI
end_ifdef

begin_comment
comment|// MSVC defines this macro iff RTTI is enabled.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_RTTI
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_HAS_RTTI
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _CPPRTTI
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_elif

begin_comment
comment|// Starting with version 4.3.2, gcc defines __GXX_RTTI iff RTTI is enabled.
end_comment

begin_if
if|#
directive|if
name|GTEST_GCC_VER_
operator|>=
literal|40302
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__GXX_RTTI
end_ifdef

begin_define
define|#
directive|define
name|GTEST_HAS_RTTI
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_HAS_RTTI
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __GXX_RTTI
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// For gcc versions smaller than 4.3.2, we assume RTTI is enabled.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_RTTI
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_GCC_VER>= 40302
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// Unknown compiler - assume RTTI is enabled.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_RTTI
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _MSC_VER
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_RTTI
end_comment

begin_comment
comment|// Determines whether<pthread.h> is available.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_HAS_PTHREAD
end_ifndef

begin_comment
comment|// The user didn't tell us, so we need to figure it out.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|GTEST_OS_LINUX
argument_list|)
operator|||
name|defined
argument_list|(
name|GTEST_OS_MAC
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_HAS_PTHREAD
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_HAS_PTHREAD
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_OS_LINUX || GTEST_OS_MAC
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_PTHREAD
end_comment

begin_comment
comment|// Determines whether tr1/tuple is available.  If you have tr1/tuple
end_comment

begin_comment
comment|// on your platform, define GTEST_HAS_TR1_TUPLE=1 for both the Google
end_comment

begin_comment
comment|// Test project and your tests. If you would like Google Test to detect
end_comment

begin_comment
comment|// tr1/tuple on your platform automatically, please open an issue
end_comment

begin_comment
comment|// ticket at http://code.google.com/p/googletest.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_HAS_TR1_TUPLE
end_ifndef

begin_comment
comment|// The user didn't tell us, so we need to figure it out.
end_comment

begin_comment
comment|// GCC provides<tr1/tuple> since 4.0.0.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|GTEST_GCC_VER_
operator|>=
literal|40000
operator|)
end_if

begin_define
define|#
directive|define
name|GTEST_HAS_TR1_TUPLE
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_HAS_TR1_TUPLE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __GNUC__
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_TR1_TUPLE
end_comment

begin_comment
comment|// To avoid conditional compilation everywhere, we make it
end_comment

begin_comment
comment|// gtest-port.h's responsibility to #include the header implementing
end_comment

begin_comment
comment|// tr1/tuple.
end_comment

begin_if
if|#
directive|if
name|GTEST_HAS_TR1_TUPLE
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_comment
comment|// GCC implements tr1/tuple in the<tr1/tuple> header.  This does not
end_comment

begin_comment
comment|// conform to the TR1 spec, which requires the header to be<tuple>.
end_comment

begin_include
include|#
directive|include
file|<tr1/tuple>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|// If the compiler is not GCC, we assume the user is using a
end_comment

begin_comment
comment|// spec-conforming TR1 implementation.
end_comment

begin_include
include|#
directive|include
file|<tuple>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __GNUC__
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_TR1_TUPLE
end_comment

begin_comment
comment|// Determines whether clone(2) is supported.
end_comment

begin_comment
comment|// Usually it will only be available on Linux, excluding
end_comment

begin_comment
comment|// Linux on the Itanium architecture.
end_comment

begin_comment
comment|// Also see http://linux.die.net/man/2/clone.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_HAS_CLONE
end_ifndef

begin_comment
comment|// The user didn't tell us, so we need to figure it out.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|GTEST_OS_LINUX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ia64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_HAS_CLONE
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_HAS_CLONE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined(GTEST_OS_LINUX)&& !defined(__ia64__)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_CLONE
end_comment

begin_comment
comment|// Determines whether to support death tests.
end_comment

begin_if
if|#
directive|if
name|GTEST_HAS_STD_STRING
operator|&&
name|GTEST_HAS_CLONE
end_if

begin_define
define|#
directive|define
name|GTEST_HAS_DEATH_TEST
end_define

begin_comment
comment|// On some platforms,<regex.h> needs someone to define size_t, and
end_comment

begin_comment
comment|// won't compile otherwise.  We can #include it here as we already
end_comment

begin_comment
comment|// included<stdlib.h>, which is guaranteed to define size_t through
end_comment

begin_comment
comment|//<stddef.h>.
end_comment

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_STD_STRING&& GTEST_HAS_CLONE
end_comment

begin_comment
comment|// Determines whether to support value-parameterized tests.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
operator|(
name|_MSC_VER
operator|>=
literal|1400
operator|)
end_if

begin_comment
comment|// TODO(vladl@google.com): get the implementation rid of vector and list
end_comment

begin_comment
comment|// to compile on MSVC 7.1.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_PARAM_TEST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined(__GNUC__) || (_MSC_VER>= 1400)
end_comment

begin_comment
comment|// Determines whether to support type-driven tests.
end_comment

begin_comment
comment|// Typed tests need<typeinfo> and variadic macros, which gcc and VC
end_comment

begin_comment
comment|// 8.0+ support.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
operator|(
name|_MSC_VER
operator|>=
literal|1400
operator|)
end_if

begin_define
define|#
directive|define
name|GTEST_HAS_TYPED_TEST
end_define

begin_define
define|#
directive|define
name|GTEST_HAS_TYPED_TEST_P
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined(__GNUC__) || (_MSC_VER>= 1400)
end_comment

begin_comment
comment|// Determines whether to support Combine(). This only makes sense when
end_comment

begin_comment
comment|// value-parameterized tests are enabled.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|GTEST_HAS_PARAM_TEST
argument_list|)
operator|&&
name|GTEST_HAS_TR1_TUPLE
end_if

begin_define
define|#
directive|define
name|GTEST_HAS_COMBINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined(GTEST_HAS_PARAM_TEST)&& GTEST_HAS_TR1_TUPLE
end_comment

begin_comment
comment|// Determines whether the system compiler uses UTF-16 for encoding wide strings.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|GTEST_OS_WINDOWS
argument_list|)
operator|||
name|defined
argument_list|(
name|GTEST_OS_CYGWIN
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|GTEST_OS_SYMBIAN
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_WIDE_STRING_USES_UTF16_
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Defines some utility macros.
end_comment

begin_comment
comment|// The GNU compiler emits a warning if nested "if" statements are followed by
end_comment

begin_comment
comment|// an "else" statement and braces are not used to explicitly disambiguate the
end_comment

begin_comment
comment|// "else" binding.  This leads to problems with code like:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   if (gate)
end_comment

begin_comment
comment|//     ASSERT_*(condition)<< "Some message";
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The "switch (0) case 0:" idiom is used to suppress this.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INTEL_COMPILER
end_ifdef

begin_define
define|#
directive|define
name|GTEST_AMBIGUOUS_ELSE_BLOCKER_
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_AMBIGUOUS_ELSE_BLOCKER_
value|switch (0) case 0:
end_define

begin_comment
comment|// NOLINT
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Use this annotation at the end of a struct / class definition to
end_comment

begin_comment
comment|// prevent the compiler from optimizing away instances that are never
end_comment

begin_comment
comment|// used.  This is useful when all interesting logic happens inside the
end_comment

begin_comment
comment|// c'tor and / or d'tor.  Example:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   struct Foo {
end_comment

begin_comment
comment|//     Foo() { ... }
end_comment

begin_comment
comment|//   } GTEST_ATTRIBUTE_UNUSED_;
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|COMPILER_ICC
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_ATTRIBUTE_UNUSED_
value|__attribute__ ((unused))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_ATTRIBUTE_UNUSED_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// A macro to disallow the evil copy constructor and operator= functions
end_comment

begin_comment
comment|// This should be used in the private: declarations for a class.
end_comment

begin_define
define|#
directive|define
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
parameter_list|(
name|type
parameter_list|)
define|\
value|type(const type&);\   void operator=(const type&)
end_define

begin_comment
comment|// Tell the compiler to warn about unused return values for functions declared
end_comment

begin_comment
comment|// with this macro.  The macro should be used on function declarations
end_comment

begin_comment
comment|// following the argument list:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   Sprocket* AllocateSprocket() GTEST_MUST_USE_RESULT_;
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|GTEST_GCC_VER_
operator|>=
literal|30400
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|COMPILER_ICC
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_MUST_USE_RESULT_
value|__attribute__ ((warn_unused_result))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_MUST_USE_RESULT_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __GNUC__&& (GTEST_GCC_VER_>= 30400)&& !COMPILER_ICC
end_comment

begin_decl_stmt
name|namespace
name|testing
block|{
name|class
name|Message
decl_stmt|;
name|namespace
name|internal
block|{
name|class
name|String
decl_stmt|;
comment|// std::strstream is deprecated.  However, we have to use it on
comment|// Windows as std::stringstream won't compile on Windows when
comment|// exceptions are disabled.  We use std::stringstream on other
comment|// platforms to avoid compiler warnings there.
if|#
directive|if
name|GTEST_HAS_STD_STRING
typedef|typedef
operator|::
name|std
operator|::
name|stringstream
name|StrStream
expr_stmt|;
else|#
directive|else
typedef|typedef
operator|::
name|std
operator|::
name|strstream
name|StrStream
expr_stmt|;
endif|#
directive|endif
comment|// GTEST_HAS_STD_STRING
comment|// Defines scoped_ptr.
comment|// This implementation of scoped_ptr is PARTIAL - it only contains
comment|// enough stuff to satisfy Google Test's need.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|scoped_ptr
block|{
name|public
operator|:
name|explicit
name|scoped_ptr
argument_list|(
name|T
operator|*
name|p
operator|=
name|NULL
argument_list|)
operator|:
name|ptr_
argument_list|(
argument|p
argument_list|)
block|{}
operator|~
name|scoped_ptr
argument_list|()
block|{
name|reset
argument_list|()
block|; }
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|ptr_
return|;
block|}
name|T
operator|*
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
return|return
name|ptr_
return|;
block|}
name|T
operator|*
name|get
argument_list|()
specifier|const
block|{
return|return
name|ptr_
return|;
block|}
name|T
operator|*
name|release
argument_list|()
block|{
name|T
operator|*
specifier|const
name|ptr
operator|=
name|ptr_
block|;
name|ptr_
operator|=
name|NULL
block|;
return|return
name|ptr
return|;
block|}
name|void
name|reset
argument_list|(
argument|T* p = NULL
argument_list|)
block|{
if|if
condition|(
name|p
operator|!=
name|ptr_
condition|)
block|{
if|if
condition|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|>
literal|0
condition|)
block|{
comment|// Makes sure T is a complete type.
name|delete
name|ptr_
decl_stmt|;
block|}
name|ptr_
operator|=
name|p
expr_stmt|;
block|}
block|}
name|private
operator|:
name|T
operator|*
name|ptr_
expr_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|scoped_ptr
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
ifdef|#
directive|ifdef
name|GTEST_HAS_DEATH_TEST
comment|// Defines RE.
comment|// A simple C++ wrapper for<regex.h>.  It uses the POSIX Enxtended
comment|// Regular Expression syntax.
name|class
name|RE
block|{
name|public
label|:
comment|// Constructs an RE from a string.
if|#
directive|if
name|GTEST_HAS_STD_STRING
name|RE
argument_list|(
argument|const ::std::string& regex
argument_list|)
block|{
name|Init
argument_list|(
name|regex
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// NOLINT
endif|#
directive|endif
comment|// GTEST_HAS_STD_STRING
if|#
directive|if
name|GTEST_HAS_GLOBAL_STRING
name|RE
argument_list|(
argument|const ::string& regex
argument_list|)
block|{
name|Init
argument_list|(
name|regex
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// NOLINT
endif|#
directive|endif
comment|// GTEST_HAS_GLOBAL_STRING
name|RE
argument_list|(
argument|const char* regex
argument_list|)
block|{
name|Init
argument_list|(
name|regex
argument_list|)
expr_stmt|;
block|}
comment|// NOLINT
operator|~
name|RE
argument_list|()
expr_stmt|;
comment|// Returns the string representation of the regex.
specifier|const
name|char
operator|*
name|pattern
argument_list|()
specifier|const
block|{
return|return
name|pattern_
return|;
block|}
comment|// FullMatch(str, re) returns true iff regular expression re matches
comment|// the entire str.
comment|// PartialMatch(str, re) returns true iff regular expression re
comment|// matches a substring of str (including str itself).
comment|//
comment|// TODO(wan@google.com): make FullMatch() and PartialMatch() work
comment|// when str contains NUL characters.
if|#
directive|if
name|GTEST_HAS_STD_STRING
specifier|static
name|bool
name|FullMatch
argument_list|(
specifier|const
operator|::
name|std
operator|::
name|string
operator|&
name|str
argument_list|,
specifier|const
name|RE
operator|&
name|re
argument_list|)
block|{
return|return
name|FullMatch
argument_list|(
name|str
operator|.
name|c_str
argument_list|()
argument_list|,
name|re
argument_list|)
return|;
block|}
specifier|static
name|bool
name|PartialMatch
argument_list|(
specifier|const
operator|::
name|std
operator|::
name|string
operator|&
name|str
argument_list|,
specifier|const
name|RE
operator|&
name|re
argument_list|)
block|{
return|return
name|PartialMatch
argument_list|(
name|str
operator|.
name|c_str
argument_list|()
argument_list|,
name|re
argument_list|)
return|;
block|}
endif|#
directive|endif
comment|// GTEST_HAS_STD_STRING
if|#
directive|if
name|GTEST_HAS_GLOBAL_STRING
specifier|static
name|bool
name|FullMatch
argument_list|(
specifier|const
operator|::
name|string
operator|&
name|str
argument_list|,
specifier|const
name|RE
operator|&
name|re
argument_list|)
block|{
return|return
name|FullMatch
argument_list|(
name|str
operator|.
name|c_str
argument_list|()
argument_list|,
name|re
argument_list|)
return|;
block|}
specifier|static
name|bool
name|PartialMatch
argument_list|(
specifier|const
operator|::
name|string
operator|&
name|str
argument_list|,
specifier|const
name|RE
operator|&
name|re
argument_list|)
block|{
return|return
name|PartialMatch
argument_list|(
name|str
operator|.
name|c_str
argument_list|()
argument_list|,
name|re
argument_list|)
return|;
block|}
endif|#
directive|endif
comment|// GTEST_HAS_GLOBAL_STRING
specifier|static
name|bool
name|FullMatch
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|RE
modifier|&
name|re
parameter_list|)
function_decl|;
specifier|static
name|bool
name|PartialMatch
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|RE
modifier|&
name|re
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|Init
parameter_list|(
specifier|const
name|char
modifier|*
name|regex
parameter_list|)
function_decl|;
comment|// We use a const char* instead of a string, as Google Test may be used
comment|// where string is not available.  We also do not use Google Test's own
comment|// String type here, in order to simplify dependencies between the
comment|// files.
specifier|const
name|char
modifier|*
name|pattern_
decl_stmt|;
name|regex_t
name|full_regex_
decl_stmt|;
comment|// For FullMatch().
name|regex_t
name|partial_regex_
decl_stmt|;
comment|// For PartialMatch().
name|bool
name|is_valid_
decl_stmt|;
block|}
empty_stmt|;
endif|#
directive|endif
comment|// GTEST_HAS_DEATH_TEST
comment|// Defines logging utilities:
comment|//   GTEST_LOG_()   - logs messages at the specified severity level.
comment|//   LogToStderr()  - directs all log messages to stderr.
comment|//   FlushInfoLog() - flushes informational log messages.
enum|enum
name|GTestLogSeverity
block|{
name|GTEST_INFO
block|,
name|GTEST_WARNING
block|,
name|GTEST_ERROR
block|,
name|GTEST_FATAL
block|}
enum|;
name|void
name|GTestLog
parameter_list|(
name|GTestLogSeverity
name|severity
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
define|#
directive|define
name|GTEST_LOG_
parameter_list|(
name|severity
parameter_list|,
name|msg
parameter_list|)
define|\
value|::testing::internal::GTestLog(\         ::testing::internal::GTEST_##severity, __FILE__, __LINE__, \         (::testing::Message()<< (msg)).GetString().c_str())
specifier|inline
name|void
name|LogToStderr
parameter_list|()
block|{}
specifier|inline
name|void
name|FlushInfoLog
parameter_list|()
block|{
name|fflush
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
block|}
comment|// Defines the stderr capturer:
comment|//   CaptureStderr     - starts capturing stderr.
comment|//   GetCapturedStderr - stops capturing stderr and returns the captured string.
ifdef|#
directive|ifdef
name|GTEST_HAS_DEATH_TEST
comment|// A copy of all command line arguments.  Set by InitGoogleTest().
extern|extern ::std::vector<String> g_argvs;
name|void
name|CaptureStderr
parameter_list|()
function_decl|;
comment|// GTEST_HAS_DEATH_TEST implies we have ::std::string.
operator|::
name|std
operator|::
name|string
name|GetCapturedStderr
argument_list|()
expr_stmt|;
specifier|const
operator|::
name|std
operator|::
name|vector
operator|<
name|String
operator|>
operator|&
name|GetArgvs
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|// GTEST_HAS_DEATH_TEST
comment|// Defines synchronization primitives.
comment|// A dummy implementation of synchronization primitives (mutex, lock,
comment|// and thread-local variable).  Necessary for compiling Google Test where
comment|// mutex is not supported - using Google Test in multiple threads is not
comment|// supported on such platforms.
name|class
name|Mutex
block|{
name|public
label|:
name|Mutex
argument_list|()
block|{}
name|explicit
name|Mutex
parameter_list|(
name|int
comment|/*unused*/
parameter_list|)
block|{}
name|void
name|AssertHeld
argument_list|()
specifier|const
block|{}
expr|enum
block|{
name|NO_CONSTRUCTOR_NEEDED_FOR_STATIC_MUTEX
operator|=
literal|0
block|}
expr_stmt|;
block|}
empty_stmt|;
comment|// We cannot call it MutexLock directly as the ctor declaration would
comment|// conflict with a macro named MutexLock, which is defined on some
comment|// platforms.  Hence the typedef trick below.
name|class
name|GTestMutexLock
block|{
name|public
label|:
name|explicit
name|GTestMutexLock
parameter_list|(
name|Mutex
modifier|*
parameter_list|)
block|{}
comment|// NOLINT
block|}
empty_stmt|;
typedef|typedef
name|GTestMutexLock
name|MutexLock
typedef|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ThreadLocal
block|{
name|public
operator|:
name|ThreadLocal
argument_list|()
operator|:
name|value_
argument_list|()
block|{}
name|explicit
name|ThreadLocal
argument_list|(
specifier|const
name|T
operator|&
name|value
argument_list|)
operator|:
name|value_
argument_list|(
argument|value
argument_list|)
block|{}
name|T
operator|*
name|pointer
argument_list|()
block|{
return|return
operator|&
name|value_
return|;
block|}
specifier|const
name|T
operator|*
name|pointer
argument_list|()
specifier|const
block|{
return|return
operator|&
name|value_
return|;
block|}
specifier|const
name|T
operator|&
name|get
argument_list|()
specifier|const
block|{
return|return
name|value_
return|;
block|}
name|void
name|set
argument_list|(
argument|const T& value
argument_list|)
block|{
name|value_
operator|=
name|value
block|; }
name|private
operator|:
name|T
name|value_
block|; }
expr_stmt|;
comment|// There's no portable way to detect the number of threads, so we just
comment|// return 0 to indicate that we cannot detect it.
specifier|inline
name|size_t
name|GetThreadCount
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
comment|// The above synchronization primitives have dummy implementations.
comment|// Therefore Google Test is not thread-safe.
define|#
directive|define
name|GTEST_IS_THREADSAFE
value|0
if|#
directive|if
name|defined
argument_list|(
name|__SYMBIAN32__
argument_list|)
operator|||
name|defined
argument_list|(
name|__IBMCPP__
argument_list|)
comment|// Passing non-POD classes through ellipsis (...) crashes the ARM
comment|// compiler.  The Nokia Symbian and the IBM XL C/C++ compiler try to
comment|// instantiate a copy constructor for objects passed through ellipsis
comment|// (...), failing for uncopyable objects.  We define this to indicate
comment|// the fact.
define|#
directive|define
name|GTEST_ELLIPSIS_NEEDS_COPY_
value|1
comment|// The Nokia Symbian and IBM XL C/C++ compilers cannot decide between
comment|// const T& and const T* in a function template.  These compilers
comment|// _can_ decide between class template specializations for T and T*,
comment|// so a tr1::type_traits-like is_pointer works.
define|#
directive|define
name|GTEST_NEEDS_IS_POINTER_
value|1
endif|#
directive|endif
comment|// defined(__SYMBIAN32__) || defined(__IBMCPP__)
name|template
operator|<
name|bool
name|bool_value
operator|>
expr|struct
name|bool_constant
block|{
typedef|typedef
name|bool_constant
operator|<
name|bool_value
operator|>
name|type
expr_stmt|;
specifier|static
specifier|const
name|bool
name|value
operator|=
name|bool_value
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|bool
name|bool_value
operator|>
specifier|const
name|bool
name|bool_constant
operator|<
name|bool_value
operator|>
operator|::
name|value
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|bool_constant
operator|<
name|false
operator|>
name|false_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|bool_constant
operator|<
name|true
operator|>
name|true_type
expr_stmt|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|is_pointer
operator|:
name|public
name|false_type
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|is_pointer
operator|<
name|T
operator|*
operator|>
operator|:
name|public
name|true_type
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Defines BiggestInt as the biggest signed integer type the compiler
end_comment

begin_comment
comment|// supports.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GTEST_OS_WINDOWS
end_ifdef

begin_typedef
typedef|typedef
name|__int64
name|BiggestInt
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|long
name|long
name|BiggestInt
typedef|;
end_typedef

begin_comment
comment|// NOLINT
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_OS_WINDOWS
end_comment

begin_comment
comment|// The maximum number a BiggestInt can represent.  This definition
end_comment

begin_comment
comment|// works no matter BiggestInt is represented in one's complement or
end_comment

begin_comment
comment|// two's complement.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// We cannot rely on numeric_limits in STL, as __int64 and long long
end_comment

begin_comment
comment|// are not part of standard C++ and numeric_limits doesn't need to be
end_comment

begin_comment
comment|// defined for them.
end_comment

begin_decl_stmt
specifier|const
name|BiggestInt
name|kMaxBiggestInt
init|=
operator|~
operator|(
name|static_cast
operator|<
name|BiggestInt
operator|>
operator|(
literal|1
operator|)
operator|<<
operator|(
literal|8
operator|*
sizeof|sizeof
argument_list|(
name|BiggestInt
argument_list|)
operator|-
literal|1
operator|)
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// This template class serves as a compile-time function from size to
end_comment

begin_comment
comment|// type.  It maps a size in bytes to a primitive type with that
end_comment

begin_comment
comment|// size. e.g.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   TypeWithSize<4>::UInt
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// is typedef-ed to be unsigned int (unsigned integer made up of 4
end_comment

begin_comment
comment|// bytes).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Such functionality should belong to STL, but I cannot find it
end_comment

begin_comment
comment|// there.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Google Test uses this class in the implementation of floating-point
end_comment

begin_comment
comment|// comparison.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For now it only handles UInt (unsigned int) as that's all Google Test
end_comment

begin_comment
comment|// needs.  Other types can be easily added in the future if need
end_comment

begin_comment
comment|// arises.
end_comment

begin_expr_stmt
name|template
operator|<
name|size_t
name|size
operator|>
name|class
name|TypeWithSize
block|{
name|public
operator|:
comment|// This prevents the user from using TypeWithSize<N> with incorrect
comment|// values of N.
typedef|typedef
name|void
name|UInt
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// The specialization for size 4.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|TypeWithSize
operator|<
literal|4
operator|>
block|{
name|public
operator|:
comment|// unsigned int has size 4 in both gcc and MSVC.
comment|//
comment|// As base/basictypes.h doesn't compile on Windows, we cannot use
comment|// uint32, uint64, and etc here.
typedef|typedef
name|int
name|Int
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UInt
typedef|;
end_typedef

begin_comment
unit|};
comment|// The specialization for size 8.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|TypeWithSize
operator|<
literal|8
operator|>
block|{
name|public
operator|:
ifdef|#
directive|ifdef
name|GTEST_OS_WINDOWS
typedef|typedef
name|__int64
name|Int
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|UInt
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|long
name|long
name|Int
typedef|;
end_typedef

begin_comment
comment|// NOLINT
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|UInt
typedef|;
end_typedef

begin_comment
comment|// NOLINT
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_OS_WINDOWS
end_comment

begin_comment
unit|};
comment|// Integer types of known sizes.
end_comment

begin_typedef
typedef|typedef
name|TypeWithSize
operator|<
literal|4
operator|>
operator|::
name|Int
name|Int32
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|TypeWithSize
operator|<
literal|4
operator|>
operator|::
name|UInt
name|UInt32
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|TypeWithSize
operator|<
literal|8
operator|>
operator|::
name|Int
name|Int64
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|TypeWithSize
operator|<
literal|8
operator|>
operator|::
name|UInt
name|UInt64
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|TypeWithSize
operator|<
literal|8
operator|>
operator|::
name|Int
name|TimeInMillis
expr_stmt|;
end_typedef

begin_comment
comment|// Represents time in milliseconds.
end_comment

begin_comment
comment|// Utilities for command line flags and environment variables.
end_comment

begin_comment
comment|// A wrapper for getenv() that works on Linux, Windows, and Mac OS.
end_comment

begin_function
specifier|inline
specifier|const
name|char
modifier|*
name|GetEnv
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|_WIN32_WCE
comment|// We are on Windows CE.
comment|// CE has no environment variables.
return|return
name|NULL
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|GTEST_OS_WINDOWS
argument_list|)
comment|// We are on Windows proper.
comment|// MSVC 8 deprecates getenv(), so we want to suppress warning 4996
comment|// (deprecated function) there.
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
comment|// Saves the current warning state.
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4996
name|)
comment|// Temporarily disables warning 4996.
return|return
name|getenv
argument_list|(
name|name
argument_list|)
return|;
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
comment|// Restores the warning state.
else|#
directive|else
comment|// We are on Linux or Mac OS.
return|return
name|getenv
argument_list|(
name|name
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32_WCE
end_ifdef

begin_comment
comment|// Windows CE has no C library. The abort() function is used in
end_comment

begin_comment
comment|// several places in Google Test. This implementation provides a reasonable
end_comment

begin_comment
comment|// imitation of standard behaviour.
end_comment

begin_function_decl
name|void
name|abort
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function
specifier|inline
name|void
name|abort
parameter_list|()
block|{
operator|::
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _WIN32_WCE
end_comment

begin_comment
comment|// INTERNAL IMPLEMENTATION - DO NOT USE.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GTEST_CHECK_ is an all-mode assert. It aborts the program if the condition
end_comment

begin_comment
comment|// is not satisfied.
end_comment

begin_comment
comment|//  Synopsys:
end_comment

begin_comment
comment|//    GTEST_CHECK_(boolean_condition);
end_comment

begin_comment
comment|//     or
end_comment

begin_comment
comment|//    GTEST_CHECK_(boolean_condition)<< "Additional message";
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    This checks the condition and if the condition is not satisfied
end_comment

begin_comment
comment|//    it prints message about the condition violation, including the
end_comment

begin_comment
comment|//    condition itself, plus additional message streamed into it, if any,
end_comment

begin_comment
comment|//    and then it aborts the program. It aborts the program irrespective of
end_comment

begin_comment
comment|//    whether it is built in the debug mode or not.
end_comment

begin_decl_stmt
name|class
name|GTestCheckProvider
block|{
name|public
label|:
name|GTestCheckProvider
argument_list|(
argument|const char* condition
argument_list|,
argument|const char* file
argument_list|,
argument|int line
argument_list|)
block|{
name|FormatFileLocation
argument_list|(
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
operator|::
name|std
operator|::
name|cerr
operator|<<
literal|" ERROR: Condition "
operator|<<
name|condition
operator|<<
literal|" failed. "
expr_stmt|;
block|}
operator|~
name|GTestCheckProvider
argument_list|()
block|{
operator|::
name|std
operator|::
name|cerr
operator|<<
operator|::
name|std
operator|::
name|endl
block|;
name|abort
argument_list|()
block|;   }
name|void
name|FormatFileLocation
argument_list|(
argument|const char* file
argument_list|,
argument|int line
argument_list|)
block|{
if|if
condition|(
name|file
operator|==
name|NULL
condition|)
name|file
operator|=
literal|"unknown file"
expr_stmt|;
if|if
condition|(
name|line
operator|<
literal|0
condition|)
block|{
operator|::
name|std
operator|::
name|cerr
operator|<<
name|file
operator|<<
literal|":"
expr_stmt|;
block|}
else|else
block|{
if|#
directive|if
name|_MSC_VER
operator|::
name|std
operator|::
name|cerr
operator|<<
name|file
operator|<<
literal|"("
operator|<<
name|line
operator|<<
literal|"):"
expr_stmt|;
else|#
directive|else
operator|::
name|std
operator|::
name|cerr
operator|<<
name|file
operator|<<
literal|":"
operator|<<
name|line
operator|<<
literal|":"
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_decl_stmt

begin_expr_stmt
operator|::
name|std
operator|::
name|ostream
operator|&
name|GetStream
argument_list|()
block|{
return|return
operator|::
name|std
operator|::
name|cerr
return|;
block|}
end_expr_stmt

begin_define
unit|};
define|#
directive|define
name|GTEST_CHECK_
parameter_list|(
name|condition
parameter_list|)
define|\
value|GTEST_AMBIGUOUS_ELSE_BLOCKER_ \     if (condition) \       ; \     else \       ::testing::internal::GTestCheckProvider(\           #condition, __FILE__, __LINE__).GetStream()
end_define

begin_comment
comment|// Macro for referencing flags.
end_comment

begin_define
define|#
directive|define
name|GTEST_FLAG
parameter_list|(
name|name
parameter_list|)
value|FLAGS_gtest_##name
end_define

begin_comment
comment|// Macros for declaring flags.
end_comment

begin_define
define|#
directive|define
name|GTEST_DECLARE_bool_
parameter_list|(
name|name
parameter_list|)
value|extern bool GTEST_FLAG(name)
end_define

begin_define
define|#
directive|define
name|GTEST_DECLARE_int32_
parameter_list|(
name|name
parameter_list|)
define|\
value|extern ::testing::internal::Int32 GTEST_FLAG(name)
end_define

begin_define
define|#
directive|define
name|GTEST_DECLARE_string_
parameter_list|(
name|name
parameter_list|)
define|\
value|extern ::testing::internal::String GTEST_FLAG(name)
end_define

begin_comment
comment|// Macros for defining flags.
end_comment

begin_define
define|#
directive|define
name|GTEST_DEFINE_bool_
parameter_list|(
name|name
parameter_list|,
name|default_val
parameter_list|,
name|doc
parameter_list|)
define|\
value|bool GTEST_FLAG(name) = (default_val)
end_define

begin_define
define|#
directive|define
name|GTEST_DEFINE_int32_
parameter_list|(
name|name
parameter_list|,
name|default_val
parameter_list|,
name|doc
parameter_list|)
define|\
value|::testing::internal::Int32 GTEST_FLAG(name) = (default_val)
end_define

begin_define
define|#
directive|define
name|GTEST_DEFINE_string_
parameter_list|(
name|name
parameter_list|,
name|default_val
parameter_list|,
name|doc
parameter_list|)
define|\
value|::testing::internal::String GTEST_FLAG(name) = (default_val)
end_define

begin_comment
comment|// Parses 'str' for a 32-bit signed integer.  If successful, writes the result
end_comment

begin_comment
comment|// to *value and returns true; otherwise leaves *value unchanged and returns
end_comment

begin_comment
comment|// false.
end_comment

begin_comment
comment|// TODO(chandlerc): Find a better way to refactor flag and environment parsing
end_comment

begin_comment
comment|// out of both gtest-port.cc and gtest.cc to avoid exporting this utility
end_comment

begin_comment
comment|// function.
end_comment

begin_function_decl
name|bool
name|ParseInt32
parameter_list|(
specifier|const
name|Message
modifier|&
name|src_text
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|Int32
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Parses a bool/Int32/string from the environment variable
end_comment

begin_comment
comment|// corresponding to the given Google Test flag.
end_comment

begin_function_decl
name|bool
name|BoolFromGTestEnv
parameter_list|(
specifier|const
name|char
modifier|*
name|flag
parameter_list|,
name|bool
name|default_val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Int32
name|Int32FromGTestEnv
parameter_list|(
specifier|const
name|char
modifier|*
name|flag
parameter_list|,
name|Int32
name|default_val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|StringFromGTestEnv
parameter_list|(
specifier|const
name|char
modifier|*
name|flag
parameter_list|,
specifier|const
name|char
modifier|*
name|default_val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|}
comment|// namespace internal
end_comment

begin_comment
unit|}
comment|// namespace testing
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_INCLUDE_GTEST_INTERNAL_GTEST_PORT_H_
end_comment

end_unit

