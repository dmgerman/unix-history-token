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
comment|// platforms.  All macros ending with _ and symbols defined in an
end_comment

begin_comment
comment|// internal namespace are subject to change without notice.  Code
end_comment

begin_comment
comment|// outside Google Test MUST NOT USE THEM DIRECTLY.  Macros that don't
end_comment

begin_comment
comment|// end with _ are part of Google Test's public API and can be used by
end_comment

begin_comment
comment|// code outside Google Test.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is fundamental to Google Test.  All other Google Test source
end_comment

begin_comment
comment|// files are expected to #include this.  Therefore, it cannot #include
end_comment

begin_comment
comment|// any other Google Test header.
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
comment|// Environment-describing macros
end_comment

begin_comment
comment|// -----------------------------
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Google Test can be used in many different environments.  Macros in
end_comment

begin_comment
comment|// this section tell Google Test what kind of environment it is being
end_comment

begin_comment
comment|// used in, such that Google Test can provide environment-specific
end_comment

begin_comment
comment|// features and implementations.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Google Test tries to automatically detect the properties of its
end_comment

begin_comment
comment|// environment, so users usually don't need to worry about these
end_comment

begin_comment
comment|// macros.  However, the automatic detection is not perfect.
end_comment

begin_comment
comment|// Sometimes it's necessary for a user to define some of the following
end_comment

begin_comment
comment|// macros in the build script to override Google Test's decisions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If the user doesn't define a macro in the list, Google Test will
end_comment

begin_comment
comment|// provide a default definition.  After this header is #included, all
end_comment

begin_comment
comment|// macros in this list will be defined to either 1 or 0.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Notes to maintainers:
end_comment

begin_comment
comment|//   - Each macro here is a user-tweakable knob; do not grow the list
end_comment

begin_comment
comment|//     lightly.
end_comment

begin_comment
comment|//   - Use #if to key off these macros.  Don't use #ifdef or "#if
end_comment

begin_comment
comment|//     defined(...)", which will not work as these macros are ALWAYS
end_comment

begin_comment
comment|//     defined.
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
comment|//   GTEST_HAS_EXCEPTIONS     - Define it to 1/0 to indicate that exceptions
end_comment

begin_comment
comment|//                              are enabled.
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
comment|//   GTEST_HAS_POSIX_RE       - Define it to 1/0 to indicate that POSIX regular
end_comment

begin_comment
comment|//                              expressions are/aren't available.
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
comment|//   GTEST_HAS_STD_WSTRING    - Define it to 1/0 to indicate that
end_comment

begin_comment
comment|//                              std::wstring does/doesn't work (Google Test can
end_comment

begin_comment
comment|//                              be used where std::wstring is unavailable).
end_comment

begin_comment
comment|//   GTEST_HAS_TR1_TUPLE      - Define it to 1/0 to indicate tr1::tuple
end_comment

begin_comment
comment|//                              is/isn't available.
end_comment

begin_comment
comment|//   GTEST_HAS_SEH            - Define it to 1/0 to indicate whether the
end_comment

begin_comment
comment|//                              compiler supports Microsoft's "Structured
end_comment

begin_comment
comment|//                              Exception Handling".
end_comment

begin_comment
comment|//   GTEST_HAS_STREAM_REDIRECTION
end_comment

begin_comment
comment|//                            - Define it to 1/0 to indicate whether the
end_comment

begin_comment
comment|//                              platform supports I/O stream redirection using
end_comment

begin_comment
comment|//                              dup() and dup2().
end_comment

begin_comment
comment|//   GTEST_USE_OWN_TR1_TUPLE  - Define it to 1/0 to indicate whether Google
end_comment

begin_comment
comment|//                              Test's own tr1 tuple implementation should be
end_comment

begin_comment
comment|//                              used.  Unused when the user sets
end_comment

begin_comment
comment|//                              GTEST_HAS_TR1_TUPLE to 0.
end_comment

begin_comment
comment|//   GTEST_LANG_CXX11         - Define it to 1/0 to indicate that Google Test
end_comment

begin_comment
comment|//                              is building in C++11/C++98 mode.
end_comment

begin_comment
comment|//   GTEST_LINKED_AS_SHARED_LIBRARY
end_comment

begin_comment
comment|//                            - Define to 1 when compiling tests that use
end_comment

begin_comment
comment|//                              Google Test as a shared library (known as
end_comment

begin_comment
comment|//                              DLL on Windows).
end_comment

begin_comment
comment|//   GTEST_CREATE_SHARED_LIBRARY
end_comment

begin_comment
comment|//                            - Define to 1 when compiling Google Test itself
end_comment

begin_comment
comment|//                              as a shared library.
end_comment

begin_comment
comment|// Platform-indicating macros
end_comment

begin_comment
comment|// --------------------------
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Macros indicating the platform on which Google Test is being used
end_comment

begin_comment
comment|// (a macro is defined to 1 if compiled on the given platform;
end_comment

begin_comment
comment|// otherwise UNDEFINED -- it's never defined to 0.).  Google Test
end_comment

begin_comment
comment|// defines these macros automatically.  Code outside Google Test MUST
end_comment

begin_comment
comment|// NOT define them.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   GTEST_OS_AIX      - IBM AIX
end_comment

begin_comment
comment|//   GTEST_OS_CYGWIN   - Cygwin
end_comment

begin_comment
comment|//   GTEST_OS_FREEBSD  - FreeBSD
end_comment

begin_comment
comment|//   GTEST_OS_HAIKU    - Haiku
end_comment

begin_comment
comment|//   GTEST_OS_HPUX     - HP-UX
end_comment

begin_comment
comment|//   GTEST_OS_LINUX    - Linux
end_comment

begin_comment
comment|//     GTEST_OS_LINUX_ANDROID - Google Android
end_comment

begin_comment
comment|//   GTEST_OS_MAC      - Mac OS X
end_comment

begin_comment
comment|//     GTEST_OS_IOS    - iOS
end_comment

begin_comment
comment|//   GTEST_OS_MINIX    - Minix
end_comment

begin_comment
comment|//   GTEST_OS_NACL     - Google Native Client (NaCl)
end_comment

begin_comment
comment|//   GTEST_OS_OPENBSD  - OpenBSD
end_comment

begin_comment
comment|//   GTEST_OS_QNX      - QNX
end_comment

begin_comment
comment|//   GTEST_OS_SOLARIS  - Sun Solaris
end_comment

begin_comment
comment|//   GTEST_OS_SYMBIAN  - Symbian
end_comment

begin_comment
comment|//   GTEST_OS_WINDOWS  - Windows (Desktop, MinGW, or Mobile)
end_comment

begin_comment
comment|//     GTEST_OS_WINDOWS_DESKTOP  - Windows Desktop
end_comment

begin_comment
comment|//     GTEST_OS_WINDOWS_MINGW    - MinGW
end_comment

begin_comment
comment|//     GTEST_OS_WINDOWS_MOBILE   - Windows Mobile
end_comment

begin_comment
comment|//     GTEST_OS_WINDOWS_PHONE    - Windows Phone
end_comment

begin_comment
comment|//     GTEST_OS_WINDOWS_RT       - Windows Store App/WinRT
end_comment

begin_comment
comment|//   GTEST_OS_ZOS      - z/OS
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
comment|// It is possible that none of the GTEST_OS_* macros are defined.
end_comment

begin_comment
comment|// Feature-indicating macros
end_comment

begin_comment
comment|// -------------------------
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Macros indicating which Google Test features are available (a macro
end_comment

begin_comment
comment|// is defined to 1 if the corresponding feature is supported;
end_comment

begin_comment
comment|// otherwise UNDEFINED -- it's never defined to 0.).  Google Test
end_comment

begin_comment
comment|// defines these macros automatically.  Code outside Google Test MUST
end_comment

begin_comment
comment|// NOT define them.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// These macros are public so that portable tests can be written.
end_comment

begin_comment
comment|// Such tests typically surround code using a feature with an #if
end_comment

begin_comment
comment|// which controls that code.  For example:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// #if GTEST_HAS_DEATH_TEST
end_comment

begin_comment
comment|//   EXPECT_DEATH(DoSomethingDeadly());
end_comment

begin_comment
comment|// #endif
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   GTEST_HAS_COMBINE      - the Combine() function (for value-parameterized
end_comment

begin_comment
comment|//                            tests)
end_comment

begin_comment
comment|//   GTEST_HAS_DEATH_TEST   - death tests
end_comment

begin_comment
comment|//   GTEST_HAS_PARAM_TEST   - value-parameterized tests
end_comment

begin_comment
comment|//   GTEST_HAS_TYPED_TEST   - typed tests
end_comment

begin_comment
comment|//   GTEST_HAS_TYPED_TEST_P - type-parameterized tests
end_comment

begin_comment
comment|//   GTEST_IS_THREADSAFE    - Google Test is thread-safe.
end_comment

begin_comment
comment|//   GTEST_USES_POSIX_RE    - enhanced POSIX regex is used. Do not confuse with
end_comment

begin_comment
comment|//                            GTEST_HAS_POSIX_RE (see above) which users can
end_comment

begin_comment
comment|//                            define themselves.
end_comment

begin_comment
comment|//   GTEST_USES_SIMPLE_RE   - our own simple regex is used;
end_comment

begin_comment
comment|//                            the above two are mutually exclusive.
end_comment

begin_comment
comment|//   GTEST_CAN_COMPARE_NULL - accepts untyped NULL in EXPECT_EQ().
end_comment

begin_comment
comment|// Misc public macros
end_comment

begin_comment
comment|// ------------------
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   GTEST_FLAG(flag_name)  - references the variable corresponding to
end_comment

begin_comment
comment|//                            the given Google Test flag.
end_comment

begin_comment
comment|// Internal utilities
end_comment

begin_comment
comment|// ------------------
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The following macros and utilities are for Google Test's INTERNAL
end_comment

begin_comment
comment|// use only.  Code outside Google Test MUST NOT USE THEM DIRECTLY.
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
comment|//   GTEST_ATTRIBUTE_UNUSED_  - declares that a class' instances or a
end_comment

begin_comment
comment|//                              variable don't have to be used.
end_comment

begin_comment
comment|//   GTEST_DISALLOW_ASSIGN_   - disables operator=.
end_comment

begin_comment
comment|//   GTEST_DISALLOW_COPY_AND_ASSIGN_ - disables copy ctor and operator=.
end_comment

begin_comment
comment|//   GTEST_MUST_USE_RESULT_   - declares that a function's result must be used.
end_comment

begin_comment
comment|//   GTEST_INTENTIONAL_CONST_COND_PUSH_ - start code section where MSVC C4127 is
end_comment

begin_comment
comment|//                                        suppressed (constant conditional).
end_comment

begin_comment
comment|//   GTEST_INTENTIONAL_CONST_COND_POP_  - finish code section where MSVC C4127
end_comment

begin_comment
comment|//                                        is suppressed.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// C++11 feature wrappers:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   testing::internal::move  - portability wrapper for std::move.
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
comment|//                            - synchronization primitives.
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
comment|//   IteratorTraits - partial implementation of std::iterator_traits, which
end_comment

begin_comment
comment|//                    is not available in libCstd when compiled with Sun C++.
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
comment|//                    Extended Regular Expression syntax on UNIX-like
end_comment

begin_comment
comment|//                    platforms, or a reduced regular exception syntax on
end_comment

begin_comment
comment|//                    other platforms, including Windows.
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
comment|// Stdout and stderr capturing:
end_comment

begin_comment
comment|//   CaptureStdout()     - starts capturing stdout.
end_comment

begin_comment
comment|//   GetCapturedStdout() - stops capturing stdout and returns the captured
end_comment

begin_comment
comment|//                         string.
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
comment|//   GTEST_DECLARE_*()  - declares a flag.
end_comment

begin_comment
comment|//   GTEST_DEFINE_*()   - defines a flag.
end_comment

begin_comment
comment|//   GetInjectableArgvs() - returns the command line as a vector of strings.
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
file|<ctype.h>
end_include

begin_comment
comment|// for isspace, etc
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for ptrdiff_t
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
file|<string.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32_WCE
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !_WIN32_WCE
end_comment

begin_if
if|#
directive|if
name|defined
name|__APPLE__
end_if

begin_include
include|#
directive|include
file|<AvailabilityMacros.h>
end_include

begin_include
include|#
directive|include
file|<TargetConditionals.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_comment
comment|// NOLINT
end_comment

begin_include
include|#
directive|include
file|<iostream>
end_include

begin_comment
comment|// NOLINT
end_comment

begin_include
include|#
directive|include
file|<sstream>
end_include

begin_comment
comment|// NOLINT
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// NOLINT
end_comment

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// NOLINT
end_comment

begin_include
include|#
directive|include
file|"gtest/internal/gtest-port-arch.h"
end_include

begin_include
include|#
directive|include
file|"gtest/internal/custom/gtest-port.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GTEST_DEV_EMAIL_
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_DEV_EMAIL_
value|"googletestframework@@googlegroups.com"
end_define

begin_define
define|#
directive|define
name|GTEST_FLAG_PREFIX_
value|"gtest_"
end_define

begin_define
define|#
directive|define
name|GTEST_FLAG_PREFIX_DASH_
value|"gtest-"
end_define

begin_define
define|#
directive|define
name|GTEST_FLAG_PREFIX_UPPER_
value|"GTEST_"
end_define

begin_define
define|#
directive|define
name|GTEST_NAME_
value|"Google Test"
end_define

begin_define
define|#
directive|define
name|GTEST_PROJECT_URL_
value|"https://github.com/google/googletest/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GTEST_DEV_EMAIL_)
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GTEST_INIT_GOOGLE_TEST_NAME_
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_INIT_GOOGLE_TEST_NAME_
value|"testing::InitGoogleTest"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GTEST_INIT_GOOGLE_TEST_NAME_)
end_comment

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
comment|// Macros for disabling Microsoft Visual C++ warnings.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   GTEST_DISABLE_MSC_WARNINGS_PUSH_(4800 4385)
end_comment

begin_comment
comment|//   /* code that triggers warnings C4800 and C4385 */
end_comment

begin_comment
comment|//   GTEST_DISABLE_MSC_WARNINGS_POP_()
end_comment

begin_if
if|#
directive|if
name|_MSC_VER
operator|>=
literal|1500
end_if

begin_define
define|#
directive|define
name|GTEST_DISABLE_MSC_WARNINGS_PUSH_
parameter_list|(
name|warnings
parameter_list|)
define|\
value|__pragma(warning(push))                        \     __pragma(warning(disable: warnings))
end_define

begin_define
define|#
directive|define
name|GTEST_DISABLE_MSC_WARNINGS_POP_
parameter_list|()
define|\
value|__pragma(warning(pop))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// Older versions of MSVC don't have __pragma.
end_comment

begin_define
define|#
directive|define
name|GTEST_DISABLE_MSC_WARNINGS_PUSH_
parameter_list|(
name|warnings
parameter_list|)
end_define

begin_define
define|#
directive|define
name|GTEST_DISABLE_MSC_WARNINGS_POP_
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_LANG_CXX11
end_ifndef

begin_comment
comment|// gcc and clang define __GXX_EXPERIMENTAL_CXX0X__ when
end_comment

begin_comment
comment|// -std={c,gnu}++{0x,11} is passed.  The C++11 standard specifies a
end_comment

begin_comment
comment|// value for __cplusplus, and recent versions of clang, gcc, and
end_comment

begin_comment
comment|// probably other compilers set that too in C++11 mode.
end_comment

begin_if
if|#
directive|if
name|__GXX_EXPERIMENTAL_CXX0X__
operator|||
name|__cplusplus
operator|>=
literal|201103L
end_if

begin_comment
comment|// Compiling in at least C++11 mode.
end_comment

begin_define
define|#
directive|define
name|GTEST_LANG_CXX11
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_LANG_CXX11
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Distinct from C++11 language support, some environments don't provide
end_comment

begin_comment
comment|// proper C++11 library support. Notably, it's possible to build in
end_comment

begin_comment
comment|// C++11 mode when targeting Mac OS X 10.6, which has an old libstdc++
end_comment

begin_comment
comment|// with no C++11 support.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// libstdc++ has sufficient C++11 support as of GCC 4.6.0, __GLIBCXX__
end_comment

begin_comment
comment|// 20110325, but maintenance releases in the 4.4 and 4.5 series followed
end_comment

begin_comment
comment|// this date, so check for those versions by their date stamps.
end_comment

begin_comment
comment|// https://gcc.gnu.org/onlinedocs/libstdc++/manual/abi.html#abi.versioning
end_comment

begin_if
if|#
directive|if
name|GTEST_LANG_CXX11
operator|&&
expr|\
operator|(
operator|!
name|defined
argument_list|(
name|__GLIBCXX__
argument_list|)
operator|||
operator|(
expr|\
name|__GLIBCXX__
operator|>=
literal|20110325ul
operator|&&
comment|/* GCC>= 4.6.0 */
expr|\
comment|/* Blacklist of patch releases of older branches: */
expr|\
name|__GLIBCXX__
operator|!=
literal|20110416ul
operator|&&
comment|/* GCC 4.4.6 */
expr|\
name|__GLIBCXX__
operator|!=
literal|20120313ul
operator|&&
comment|/* GCC 4.4.7 */
expr|\
name|__GLIBCXX__
operator|!=
literal|20110428ul
operator|&&
comment|/* GCC 4.5.3 */
expr|\
name|__GLIBCXX__
operator|!=
literal|20120702ul
operator|)
operator|)
end_if

begin_comment
comment|/* GCC 4.5.4 */
end_comment

begin_define
define|#
directive|define
name|GTEST_STDLIB_CXX11
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Only use C++11 library features if the library provides them.
end_comment

begin_if
if|#
directive|if
name|GTEST_STDLIB_CXX11
end_if

begin_define
define|#
directive|define
name|GTEST_HAS_STD_BEGIN_AND_END_
value|1
end_define

begin_define
define|#
directive|define
name|GTEST_HAS_STD_FORWARD_LIST_
value|1
end_define

begin_define
define|#
directive|define
name|GTEST_HAS_STD_FUNCTION_
value|1
end_define

begin_define
define|#
directive|define
name|GTEST_HAS_STD_INITIALIZER_LIST_
value|1
end_define

begin_define
define|#
directive|define
name|GTEST_HAS_STD_MOVE_
value|1
end_define

begin_define
define|#
directive|define
name|GTEST_HAS_STD_SHARED_PTR_
value|1
end_define

begin_define
define|#
directive|define
name|GTEST_HAS_STD_TYPE_TRAITS_
value|1
end_define

begin_define
define|#
directive|define
name|GTEST_HAS_STD_UNIQUE_PTR_
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// C++11 specifies that<tuple> provides std::tuple.
end_comment

begin_comment
comment|// Some platforms still might not have it, however.
end_comment

begin_if
if|#
directive|if
name|GTEST_LANG_CXX11
end_if

begin_define
define|#
directive|define
name|GTEST_HAS_STD_TUPLE_
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__clang__
argument_list|)
end_if

begin_comment
comment|// Inspired by http://clang.llvm.org/docs/LanguageExtensions.html#__has_include
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__has_include
argument_list|)
operator|&&
operator|!
name|__has_include
argument_list|(
operator|<
name|tuple
operator|>
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|GTEST_HAS_STD_TUPLE_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_comment
comment|// Inspired by boost/config/stdlib/dinkumware.hpp
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_CPPLIB_VER
argument_list|)
operator|&&
name|_CPPLIB_VER
operator|<
literal|520
end_if

begin_undef
undef|#
directive|undef
name|GTEST_HAS_STD_TUPLE_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GLIBCXX__
argument_list|)
end_elif

begin_comment
comment|// Inspired by boost/config/stdlib/libstdcpp3.hpp,
end_comment

begin_comment
comment|// http://gcc.gnu.org/gcc-4.2/changes.html and
end_comment

begin_comment
comment|// http://gcc.gnu.org/onlinedocs/libstdc++/manual/bk01pt01ch01.html#manual.intro.status.standard.200x
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|4
operator|||
operator|(
name|__GNUC__
operator|==
literal|4
operator|&&
name|__GNUC_MINOR__
operator|<
literal|2
operator|)
end_if

begin_undef
undef|#
directive|undef
name|GTEST_HAS_STD_TUPLE_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Brings in definitions for functions used in the testing::internal::posix
end_comment

begin_comment
comment|// namespace (read, write, close, chdir, isatty, stat). We do not currently
end_comment

begin_comment
comment|// use them on Windows Mobile.
end_comment

begin_if
if|#
directive|if
name|GTEST_OS_WINDOWS
end_if

begin_if
if|#
directive|if
operator|!
name|GTEST_OS_WINDOWS_MOBILE
end_if

begin_include
include|#
directive|include
file|<direct.h>
end_include

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// In order to avoid having to include<windows.h>, use forward declaration
end_comment

begin_comment
comment|// assuming CRITICAL_SECTION is a typedef of _RTL_CRITICAL_SECTION.
end_comment

begin_comment
comment|// This assumption is verified by
end_comment

begin_comment
comment|// WindowsTypesTest.CRITICAL_SECTIONIs_RTL_CRITICAL_SECTION.
end_comment

begin_struct_decl
struct_decl|struct
name|_RTL_CRITICAL_SECTION
struct_decl|;
end_struct_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|// This assumes that non-Windows OSes provide unistd.h. For OSes where this
end_comment

begin_comment
comment|// is not the case, we need to include headers that provide the functions
end_comment

begin_comment
comment|// mentioned above.
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_OS_WINDOWS
end_comment

begin_if
if|#
directive|if
name|GTEST_OS_LINUX_ANDROID
end_if

begin_comment
comment|// Used to define __ANDROID_API__ matching the target NDK API level.
end_comment

begin_include
include|#
directive|include
file|<android/api-level.h>
end_include

begin_comment
comment|// NOLINT
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Defines this to true iff Google Test can use POSIX regular expressions.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_HAS_POSIX_RE
end_ifndef

begin_if
if|#
directive|if
name|GTEST_OS_LINUX_ANDROID
end_if

begin_comment
comment|// On Android,<regex.h> is only available starting with Gingerbread.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_POSIX_RE
value|(__ANDROID_API__>= 9)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_HAS_POSIX_RE
value|(!GTEST_OS_WINDOWS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GTEST_USES_PCRE
end_if

begin_comment
comment|// The appropriate headers have already been included.
end_comment

begin_elif
elif|#
directive|elif
name|GTEST_HAS_POSIX_RE
end_elif

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

begin_comment
comment|// NOLINT
end_comment

begin_define
define|#
directive|define
name|GTEST_USES_POSIX_RE
value|1
end_define

begin_elif
elif|#
directive|elif
name|GTEST_OS_WINDOWS
end_elif

begin_comment
comment|//<regex.h> is not available on Windows.  Use our own simple regex
end_comment

begin_comment
comment|// implementation instead.
end_comment

begin_define
define|#
directive|define
name|GTEST_USES_SIMPLE_RE
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|//<regex.h> may not be available on this platform.  Use our own
end_comment

begin_comment
comment|// simple regex implementation instead.
end_comment

begin_define
define|#
directive|define
name|GTEST_USES_SIMPLE_RE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_USES_PCRE
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_HAS_EXCEPTIONS
end_ifndef

begin_comment
comment|// The user didn't tell us whether exceptions are enabled, so we need
end_comment

begin_comment
comment|// to figure it out.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
end_if

begin_comment
comment|// MSVC's and C++Builder's implementations of the STL use the _HAS_EXCEPTIONS
end_comment

begin_comment
comment|// macro to enable exceptions, so we'll do the same.
end_comment

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

begin_define
define|#
directive|define
name|GTEST_HAS_EXCEPTIONS
value|_HAS_EXCEPTIONS
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__clang__
argument_list|)
end_elif

begin_comment
comment|// clang defines __EXCEPTIONS iff exceptions are enabled before clang 220714,
end_comment

begin_comment
comment|// but iff cleanups are enabled after that. In Obj-C++ files, there can be
end_comment

begin_comment
comment|// cleanups for ObjC exceptions which also need cleanups, even if C++ exceptions
end_comment

begin_comment
comment|// are disabled. clang has __has_feature(cxx_exceptions) which checks for C++
end_comment

begin_comment
comment|// exceptions starting at clang r206352, but which checked for cleanups prior to
end_comment

begin_comment
comment|// that. To reliably check for C++ exception availability with clang, check for
end_comment

begin_comment
comment|// __EXCEPTIONS&& __has_feature(cxx_exceptions).
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_EXCEPTIONS
value|(__EXCEPTIONS&& __has_feature(cxx_exceptions))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|__EXCEPTIONS
end_elif

begin_comment
comment|// gcc defines __EXCEPTIONS to 1 iff exceptions are enabled.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_EXCEPTIONS
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__SUNPRO_CC
argument_list|)
end_elif

begin_comment
comment|// Sun Pro CC supports exceptions.  However, there is no compile-time way of
end_comment

begin_comment
comment|// detecting whether they are enabled or not.  Therefore, we assume that
end_comment

begin_comment
comment|// they are enabled unless the user tells us otherwise.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_EXCEPTIONS
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__IBMCPP__
argument_list|)
operator|&&
name|__EXCEPTIONS
end_elif

begin_comment
comment|// xlC defines __EXCEPTIONS to 1 iff exceptions are enabled.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_EXCEPTIONS
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__HP_aCC
argument_list|)
end_elif

begin_comment
comment|// Exception handling is in effect by default in HP aCC compiler. It has to
end_comment

begin_comment
comment|// be turned of by +noeh compiler option if desired.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_EXCEPTIONS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// For other compilers, we assume exceptions are disabled to be
end_comment

begin_comment
comment|// conservative.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_EXCEPTIONS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined(_MSC_VER) || defined(__BORLANDC__)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_EXCEPTIONS
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GTEST_HAS_STD_STRING
argument_list|)
end_if

begin_comment
comment|// Even though we don't use this macro any longer, we keep it in case
end_comment

begin_comment
comment|// some clients still depend on it.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_STD_STRING
value|1
end_define

begin_elif
elif|#
directive|elif
operator|!
name|GTEST_HAS_STD_STRING
end_elif

begin_comment
comment|// The user told us that ::std::string isn't available.
end_comment

begin_error
error|#
directive|error
literal|"Google Test cannot be used where ::std::string isn't available."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GTEST_HAS_STD_STRING)
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

begin_comment
comment|// Cygwin 1.7 and below doesn't support ::std::wstring.
end_comment

begin_comment
comment|// Solaris' libc++ doesn't support it either.  Android has
end_comment

begin_comment
comment|// no support for it at least as recent as Froyo (2.2).
end_comment

begin_comment
comment|// Minix currently doesn't support it either.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_STD_WSTRING
define|\
value|(!(GTEST_OS_LINUX_ANDROID || GTEST_OS_CYGWIN || GTEST_OS_SOLARIS || GTEST_OS_HAIKU || GTEST_OS_MINIX))
end_define

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
define|\
value|(GTEST_HAS_STD_WSTRING&& GTEST_HAS_GLOBAL_STRING)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_GLOBAL_WSTRING
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
comment|// Starting with version 4.3.2, gcc defines __GXX_RTTI iff RTTI is enabled.
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|GTEST_GCC_VER_
operator|>=
literal|40302
operator|)
end_elif

begin_ifdef
ifdef|#
directive|ifdef
name|__GXX_RTTI
end_ifdef

begin_comment
comment|// When building against STLport with the Android NDK and with
end_comment

begin_comment
comment|// -frtti -fno-exceptions, the build fails at link time with undefined
end_comment

begin_comment
comment|// references to __cxa_bad_typeid. Note sure if STL or toolchain bug,
end_comment

begin_comment
comment|// so disable RTTI when detected.
end_comment

begin_if
if|#
directive|if
name|GTEST_OS_LINUX_ANDROID
operator|&&
name|defined
argument_list|(
name|_STLPORT_MAJOR
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|__EXCEPTIONS
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_HAS_RTTI
value|0
end_define

begin_else
else|#
directive|else
end_else

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
comment|// GTEST_OS_LINUX_ANDROID&& __STLPORT_MAJOR&& !__EXCEPTIONS
end_comment

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

begin_comment
comment|// Clang defines __GXX_RTTI starting with version 3.0, but its manual recommends
end_comment

begin_comment
comment|// using has_feature instead. has_feature(cxx_rtti) is supported since 2.7, the
end_comment

begin_comment
comment|// first version with C++ support.
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__clang__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|GTEST_HAS_RTTI
value|__has_feature(cxx_rtti)
end_define

begin_comment
comment|// Starting with version 9.0 IBM Visual Age defines __RTTI_ALL__ to 1 if
end_comment

begin_comment
comment|// both the typeid and dynamic_cast features are present.
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__IBMCPP__
argument_list|)
operator|&&
operator|(
name|__IBMCPP__
operator|>=
literal|900
operator|)
end_elif

begin_ifdef
ifdef|#
directive|ifdef
name|__RTTI_ALL__
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|// For all other compilers, we assume RTTI is enabled.
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
comment|// It's this header's responsibility to #include<typeinfo> when RTTI
end_comment

begin_comment
comment|// is enabled.
end_comment

begin_if
if|#
directive|if
name|GTEST_HAS_RTTI
end_if

begin_include
include|#
directive|include
file|<typeinfo>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Determines whether Google Test can use the pthreads library.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_HAS_PTHREAD
end_ifndef

begin_comment
comment|// The user didn't tell us explicitly, so we make reasonable assumptions about
end_comment

begin_comment
comment|// which platforms have pthreads support.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// To disable threading support in Google Test, add -DGTEST_HAS_PTHREAD=0
end_comment

begin_comment
comment|// to your compiler flags.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_PTHREAD
value|(GTEST_OS_LINUX || GTEST_OS_MAC || GTEST_OS_HPUX \     || GTEST_OS_QNX || GTEST_OS_FREEBSD || GTEST_OS_NACL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_PTHREAD
end_comment

begin_if
if|#
directive|if
name|GTEST_HAS_PTHREAD
end_if

begin_comment
comment|// gtest-port.h guarantees to #include<pthread.h> when GTEST_HAS_PTHREAD is
end_comment

begin_comment
comment|// true.
end_comment

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_comment
comment|// NOLINT
end_comment

begin_comment
comment|// For timespec and nanosleep, used below.
end_comment

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|// NOLINT
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Determines if hash_map/hash_set are available.
end_comment

begin_comment
comment|// Only used for testing against those containers.
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GTEST_HAS_HASH_MAP_
argument_list|)
end_if

begin_if
if|#
directive|if
name|_MSC_VER
end_if

begin_define
define|#
directive|define
name|GTEST_HAS_HASH_MAP_
value|1
end_define

begin_comment
comment|// Indicates that hash_map is available.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_HASH_SET_
value|1
end_define

begin_comment
comment|// Indicates that hash_set is available.
end_comment

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
comment|// !defined(GTEST_HAS_HASH_MAP_)
end_comment

begin_comment
comment|// Determines whether Google Test can use tr1/tuple.  You can define
end_comment

begin_comment
comment|// this macro to 0 to prevent Google Test from using tuple (any
end_comment

begin_comment
comment|// feature depending on tuple with be disabled in this mode).
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_HAS_TR1_TUPLE
end_ifndef

begin_if
if|#
directive|if
name|GTEST_OS_LINUX_ANDROID
operator|&&
name|defined
argument_list|(
name|_STLPORT_MAJOR
argument_list|)
end_if

begin_comment
comment|// STLport, provided with the Android NDK, has neither<tr1/tuple> or<tuple>.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_TR1_TUPLE
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// The user didn't tell us not to do it, so we assume it's OK.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_TR1_TUPLE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_TR1_TUPLE
end_comment

begin_comment
comment|// Determines whether Google Test's own tr1 tuple implementation
end_comment

begin_comment
comment|// should be used.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_USE_OWN_TR1_TUPLE
end_ifndef

begin_comment
comment|// The user didn't tell us, so we need to figure it out.
end_comment

begin_comment
comment|// We use our own TR1 tuple if we aren't sure the user has an
end_comment

begin_comment
comment|// implementation of it already.  At this time, libstdc++ 4.0.0+ and
end_comment

begin_comment
comment|// MSVC 2010 are the only mainstream standard libraries that come
end_comment

begin_comment
comment|// with a TR1 tuple implementation.  NVIDIA's CUDA NVCC compiler
end_comment

begin_comment
comment|// pretends to be GCC by defining __GNUC__ and friends, but cannot
end_comment

begin_comment
comment|// compile GCC's tuple implementation.  MSVC 2008 (9.0) provides TR1
end_comment

begin_comment
comment|// tuple in a 323 MB Feature Pack download, which we cannot assume the
end_comment

begin_comment
comment|// user has.  QNX's QCC compiler is a modified GCC but it doesn't
end_comment

begin_comment
comment|// support TR1 tuple.  libc++ only provides std::tuple, in C++11 mode,
end_comment

begin_comment
comment|// and it can be used with some compilers that define __GNUC__.
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CUDACC__
argument_list|)
operator|&&
operator|(
name|GTEST_GCC_VER_
operator|>=
literal|40000
operator|)
expr|\
operator|&&
operator|!
name|GTEST_OS_QNX
operator|&&
operator|!
name|defined
argument_list|(
name|_LIBCPP_VERSION
argument_list|)
operator|)
operator|||
name|_MSC_VER
operator|>=
literal|1600
end_if

begin_define
define|#
directive|define
name|GTEST_ENV_HAS_TR1_TUPLE_
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// C++11 specifies that<tuple> provides std::tuple. Use that if gtest is used
end_comment

begin_comment
comment|// in C++11 mode and libstdc++ isn't very old (binaries targeting OS X 10.6
end_comment

begin_comment
comment|// can build with clang but need to use gcc4.2's libstdc++).
end_comment

begin_if
if|#
directive|if
name|GTEST_LANG_CXX11
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|__GLIBCXX__
argument_list|)
operator|||
name|__GLIBCXX__
operator|>
literal|20110325
operator|)
end_if

begin_define
define|#
directive|define
name|GTEST_ENV_HAS_STD_TUPLE_
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GTEST_ENV_HAS_TR1_TUPLE_
operator|||
name|GTEST_ENV_HAS_STD_TUPLE_
end_if

begin_define
define|#
directive|define
name|GTEST_USE_OWN_TR1_TUPLE
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_USE_OWN_TR1_TUPLE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_USE_OWN_TR1_TUPLE
end_comment

begin_comment
comment|// To avoid conditional compilation everywhere, we make it
end_comment

begin_comment
comment|// gtest-port.h's responsibility to #include the header implementing
end_comment

begin_comment
comment|// tuple.
end_comment

begin_if
if|#
directive|if
name|GTEST_HAS_STD_TUPLE_
end_if

begin_include
include|#
directive|include
file|<tuple>
end_include

begin_comment
comment|// IWYU pragma: export
end_comment

begin_define
define|#
directive|define
name|GTEST_TUPLE_NAMESPACE_
value|::std
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_STD_TUPLE_
end_comment

begin_comment
comment|// We include tr1::tuple even if std::tuple is available to define printers for
end_comment

begin_comment
comment|// them.
end_comment

begin_if
if|#
directive|if
name|GTEST_HAS_TR1_TUPLE
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_TUPLE_NAMESPACE_
end_ifndef

begin_define
define|#
directive|define
name|GTEST_TUPLE_NAMESPACE_
value|::std::tr1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_TUPLE_NAMESPACE_
end_comment

begin_if
if|#
directive|if
name|GTEST_USE_OWN_TR1_TUPLE
end_if

begin_include
include|#
directive|include
file|"gtest/internal/gtest-tuple.h"
end_include

begin_comment
comment|// IWYU pragma: export  // NOLINT
end_comment

begin_elif
elif|#
directive|elif
name|GTEST_ENV_HAS_STD_TUPLE_
end_elif

begin_include
include|#
directive|include
file|<tuple>
end_include

begin_comment
comment|// C++11 puts its tuple into the ::std namespace rather than
end_comment

begin_comment
comment|// ::std::tr1.  gtest expects tuple to live in ::std::tr1, so put it there.
end_comment

begin_comment
comment|// This causes undefined behavior, but supported compilers react in
end_comment

begin_comment
comment|// the way we intend.
end_comment

begin_decl_stmt
name|namespace
name|std
block|{
name|namespace
name|tr1
block|{
name|using
operator|::
name|std
operator|::
name|get
expr_stmt|;
name|using
operator|::
name|std
operator|::
name|make_tuple
expr_stmt|;
name|using
operator|::
name|std
operator|::
name|tuple
expr_stmt|;
name|using
operator|::
name|std
operator|::
name|tuple_element
expr_stmt|;
name|using
operator|::
name|std
operator|::
name|tuple_size
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_elif
elif|#
directive|elif
name|GTEST_OS_SYMBIAN
end_elif

begin_comment
comment|// On Symbian, BOOST_HAS_TR1_TUPLE causes Boost's TR1 tuple library to
end_comment

begin_comment
comment|// use STLport's tuple implementation, which unfortunately doesn't
end_comment

begin_comment
comment|// work as the copy of STLport distributed with Symbian is incomplete.
end_comment

begin_comment
comment|// By making sure BOOST_HAS_TR1_TUPLE is undefined, we force Boost to
end_comment

begin_comment
comment|// use its own tuple implementation.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BOOST_HAS_TR1_TUPLE
end_ifdef

begin_undef
undef|#
directive|undef
name|BOOST_HAS_TR1_TUPLE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// BOOST_HAS_TR1_TUPLE
end_comment

begin_comment
comment|// This prevents<boost/tr1/detail/config.hpp>, which defines
end_comment

begin_comment
comment|// BOOST_HAS_TR1_TUPLE, from being #included by Boost's<tuple>.
end_comment

begin_define
define|#
directive|define
name|BOOST_TR1_DETAIL_CONFIG_HPP_INCLUDED
end_define

begin_include
include|#
directive|include
file|<tuple>
end_include

begin_comment
comment|// IWYU pragma: export  // NOLINT
end_comment

begin_elif
elif|#
directive|elif
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
end_elif

begin_comment
comment|// GCC 4.0+ implements tr1/tuple in the<tr1/tuple> header.  This does
end_comment

begin_comment
comment|// not conform to the TR1 spec, which requires the header to be<tuple>.
end_comment

begin_if
if|#
directive|if
operator|!
name|GTEST_HAS_RTTI
operator|&&
name|GTEST_GCC_VER_
operator|<
literal|40302
end_if

begin_comment
comment|// Until version 4.3.2, gcc has a bug that causes<tr1/functional>,
end_comment

begin_comment
comment|// which is #included by<tr1/tuple>, to not compile when RTTI is
end_comment

begin_comment
comment|// disabled.  _TR1_FUNCTIONAL is the header guard for
end_comment

begin_comment
comment|//<tr1/functional>.  Hence the following #define is a hack to prevent
end_comment

begin_comment
comment|//<tr1/functional> from being included.
end_comment

begin_define
define|#
directive|define
name|_TR1_FUNCTIONAL
value|1
end_define

begin_include
include|#
directive|include
file|<tr1/tuple>
end_include

begin_undef
undef|#
directive|undef
name|_TR1_FUNCTIONAL
end_undef

begin_comment
comment|// Allows the user to #include
end_comment

begin_comment
comment|//<tr1/functional> if he chooses to.
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<tr1/tuple>
end_include

begin_comment
comment|// NOLINT
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !GTEST_HAS_RTTI&& GTEST_GCC_VER_< 40302
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// If the compiler is not GCC 4.0+, we assume the user is using a
end_comment

begin_comment
comment|// spec-conforming TR1 implementation.
end_comment

begin_include
include|#
directive|include
file|<tuple>
end_include

begin_comment
comment|// IWYU pragma: export  // NOLINT
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_USE_OWN_TR1_TUPLE
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
name|GTEST_OS_LINUX
operator|&&
operator|!
name|defined
argument_list|(
name|__ia64__
argument_list|)
end_if

begin_if
if|#
directive|if
name|GTEST_OS_LINUX_ANDROID
end_if

begin_comment
comment|// On Android, clone() is only available on ARM starting with Gingerbread.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|&&
name|__ANDROID_API__
operator|>=
literal|9
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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_HAS_CLONE
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
name|GTEST_HAS_CLONE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_OS_LINUX&& !defined(__ia64__)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_CLONE
end_comment

begin_comment
comment|// Determines whether to support stream redirection. This is used to test
end_comment

begin_comment
comment|// output correctness and to implement death tests.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_HAS_STREAM_REDIRECTION
end_ifndef

begin_comment
comment|// By default, we assume that stream redirection is supported on all
end_comment

begin_comment
comment|// platforms except known mobile ones.
end_comment

begin_if
if|#
directive|if
name|GTEST_OS_WINDOWS_MOBILE
operator|||
name|GTEST_OS_SYMBIAN
operator|||
expr|\
name|GTEST_OS_WINDOWS_PHONE
operator|||
name|GTEST_OS_WINDOWS_RT
end_if

begin_define
define|#
directive|define
name|GTEST_HAS_STREAM_REDIRECTION
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_HAS_STREAM_REDIRECTION
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !GTEST_OS_WINDOWS_MOBILE&& !GTEST_OS_SYMBIAN
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_STREAM_REDIRECTION
end_comment

begin_comment
comment|// Determines whether to support death tests.
end_comment

begin_comment
comment|// Google Test does not support death tests for VC 7.1 and earlier as
end_comment

begin_comment
comment|// abort() in a VC 7.1 application compiled as GUI in debug config
end_comment

begin_comment
comment|// pops up a dialog window that cannot be suppressed programmatically.
end_comment

begin_if
if|#
directive|if
operator|(
name|GTEST_OS_LINUX
operator|||
name|GTEST_OS_CYGWIN
operator|||
name|GTEST_OS_SOLARIS
operator|||
expr|\
operator|(
name|GTEST_OS_MAC
operator|&&
operator|!
name|GTEST_OS_IOS
operator|)
operator|||
expr|\
operator|(
name|GTEST_OS_WINDOWS_DESKTOP
operator|&&
name|_MSC_VER
operator|>=
literal|1400
operator|)
operator|||
expr|\
name|GTEST_OS_WINDOWS_MINGW
operator|||
name|GTEST_OS_AIX
operator|||
name|GTEST_OS_HPUX
operator|||
expr|\
name|GTEST_OS_OPENBSD
operator|||
name|GTEST_OS_QNX
operator|||
name|GTEST_OS_FREEBSD
operator|||
name|GTEST_OS_NETBSD
operator|)
end_if

begin_define
define|#
directive|define
name|GTEST_HAS_DEATH_TEST
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// We don't support MSVC 7.1 with exceptions disabled now.  Therefore
end_comment

begin_comment
comment|// all the compilers we care about are adequate for supporting
end_comment

begin_comment
comment|// value-parameterized tests.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_PARAM_TEST
value|1
end_define

begin_comment
comment|// Determines whether to support type-driven tests.
end_comment

begin_comment
comment|// Typed tests need<typeinfo> and variadic macros, which GCC, VC++ 8.0,
end_comment

begin_comment
comment|// Sun Pro CC, IBM Visual Age, and HP aCC support.
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
operator|||
name|defined
argument_list|(
name|__SUNPRO_CC
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__IBMCPP__
argument_list|)
operator|||
name|defined
argument_list|(
name|__HP_aCC
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_HAS_TYPED_TEST
value|1
end_define

begin_define
define|#
directive|define
name|GTEST_HAS_TYPED_TEST_P
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Determines whether to support Combine(). This only makes sense when
end_comment

begin_comment
comment|// value-parameterized tests are enabled.  The implementation doesn't
end_comment

begin_comment
comment|// work on Sun Studio since it doesn't understand templated conversion
end_comment

begin_comment
comment|// operators.
end_comment

begin_if
if|#
directive|if
name|GTEST_HAS_PARAM_TEST
operator|&&
name|GTEST_HAS_TR1_TUPLE
operator|&&
operator|!
name|defined
argument_list|(
name|__SUNPRO_CC
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_HAS_COMBINE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Determines whether the system compiler uses UTF-16 for encoding wide strings.
end_comment

begin_define
define|#
directive|define
name|GTEST_WIDE_STRING_USES_UTF16_
define|\
value|(GTEST_OS_WINDOWS || GTEST_OS_CYGWIN || GTEST_OS_SYMBIAN || GTEST_OS_AIX)
end_define

begin_comment
comment|// Determines whether test results can be streamed to a socket.
end_comment

begin_if
if|#
directive|if
name|GTEST_OS_LINUX
end_if

begin_define
define|#
directive|define
name|GTEST_CAN_STREAM_RESULTS_
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
value|switch (0) case 0: default:
end_define

begin_comment
comment|// NOLINT
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Use this annotation at the end of a struct/class definition to
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

begin_comment
comment|//
end_comment

begin_comment
comment|// Also use it after a variable or parameter declaration to tell the
end_comment

begin_comment
comment|// compiler the variable/parameter does not have to be used.
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

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__clang__
argument_list|)
end_elif

begin_if
if|#
directive|if
name|__has_attribute
argument_list|(
name|unused
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_ATTRIBUTE_UNUSED_
value|__attribute__ ((unused))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_ATTRIBUTE_UNUSED_
end_ifndef

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
comment|// A macro to disallow operator=
end_comment

begin_comment
comment|// This should be used in the private: declarations for a class.
end_comment

begin_define
define|#
directive|define
name|GTEST_DISALLOW_ASSIGN_
parameter_list|(
name|type
parameter_list|)
define|\
value|void operator=(type const&)
end_define

begin_comment
comment|// A macro to disallow copy constructor and operator=
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
value|type(type const&);\   GTEST_DISALLOW_ASSIGN_(type)
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

begin_comment
comment|// MS C++ compiler emits warning when a conditional expression is compile time
end_comment

begin_comment
comment|// constant. In some contexts this warning is false positive and needs to be
end_comment

begin_comment
comment|// suppressed. Use the following two macros in such cases:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GTEST_INTENTIONAL_CONST_COND_PUSH_()
end_comment

begin_comment
comment|// while (true) {
end_comment

begin_comment
comment|// GTEST_INTENTIONAL_CONST_COND_POP_()
end_comment

begin_comment
comment|// }
end_comment

begin_define
define|#
directive|define
name|GTEST_INTENTIONAL_CONST_COND_PUSH_
parameter_list|()
define|\
value|GTEST_DISABLE_MSC_WARNINGS_PUSH_(4127)
end_define

begin_define
define|#
directive|define
name|GTEST_INTENTIONAL_CONST_COND_POP_
parameter_list|()
define|\
value|GTEST_DISABLE_MSC_WARNINGS_POP_()
end_define

begin_comment
comment|// Determine whether the compiler supports Microsoft's Structured Exception
end_comment

begin_comment
comment|// Handling.  This is supported by several Windows compilers but generally
end_comment

begin_comment
comment|// does not exist on any other system.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_HAS_SEH
end_ifndef

begin_comment
comment|// The user didn't tell us, so we need to figure it out.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
end_if

begin_comment
comment|// These two compilers are known to support SEH.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_SEH
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// Assume no SEH.
end_comment

begin_define
define|#
directive|define
name|GTEST_HAS_SEH
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_SEH
end_comment

begin_define
define|#
directive|define
name|GTEST_IS_THREADSAFE
define|\
value|(GTEST_HAS_MUTEX_AND_THREAD_LOCAL_ \      || (GTEST_OS_WINDOWS&& !GTEST_OS_WINDOWS_PHONE&& !GTEST_OS_WINDOWS_RT) \      || GTEST_HAS_PTHREAD)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_if
if|#
directive|if
name|GTEST_LINKED_AS_SHARED_LIBRARY
end_if

begin_define
define|#
directive|define
name|GTEST_API_
value|__declspec(dllimport)
end_define

begin_elif
elif|#
directive|elif
name|GTEST_CREATE_SHARED_LIBRARY
end_elif

begin_define
define|#
directive|define
name|GTEST_API_
value|__declspec(dllexport)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|__GNUC__
operator|>=
literal|4
operator|||
name|defined
argument_list|(
name|__clang__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|GTEST_API_
value|__attribute__((visibility ("default")))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _MSC_VER
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_API_
end_ifndef

begin_define
define|#
directive|define
name|GTEST_API_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_comment
comment|// Ask the compiler to never inline a given function.
end_comment

begin_define
define|#
directive|define
name|GTEST_NO_INLINE_
value|__attribute__((noinline))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_NO_INLINE_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_VERSION is defined by the libc++ library from the LLVM project.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__has_include
argument_list|)
end_if

begin_if
if|#
directive|if
name|__has_include
argument_list|(
operator|<
name|cxxabi
operator|.
name|h
operator|>
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_HAS_CXXABI_H_
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_HAS_CXXABI_H_
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GLIBCXX__
argument_list|)
operator|||
name|defined
argument_list|(
name|_LIBCPP_VERSION
argument_list|)
end_elif

begin_define
define|#
directive|define
name|GTEST_HAS_CXXABI_H_
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_HAS_CXXABI_H_
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// A function level attribute to disable checking for use of uninitialized
end_comment

begin_comment
comment|// memory when built with MemorySanitizer.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__clang__
argument_list|)
end_if

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|memory_sanitizer
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_ATTRIBUTE_NO_SANITIZE_MEMORY_
define|\
value|__attribute__((no_sanitize_memory))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_ATTRIBUTE_NO_SANITIZE_MEMORY_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __has_feature(memory_sanitizer)
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_ATTRIBUTE_NO_SANITIZE_MEMORY_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __clang__
end_comment

begin_comment
comment|// A function level attribute to disable AddressSanitizer instrumentation.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__clang__
argument_list|)
end_if

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|address_sanitizer
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_ATTRIBUTE_NO_SANITIZE_ADDRESS_
define|\
value|__attribute__((no_sanitize_address))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_ATTRIBUTE_NO_SANITIZE_ADDRESS_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __has_feature(address_sanitizer)
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_ATTRIBUTE_NO_SANITIZE_ADDRESS_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __clang__
end_comment

begin_comment
comment|// A function level attribute to disable ThreadSanitizer instrumentation.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__clang__
argument_list|)
end_if

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|thread_sanitizer
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_ATTRIBUTE_NO_SANITIZE_THREAD_
define|\
value|__attribute__((no_sanitize_thread))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_ATTRIBUTE_NO_SANITIZE_THREAD_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __has_feature(thread_sanitizer)
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_ATTRIBUTE_NO_SANITIZE_THREAD_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __clang__
end_comment

begin_decl_stmt
name|namespace
name|testing
block|{
name|class
name|Message
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|GTEST_TUPLE_NAMESPACE_
argument_list|)
comment|// Import tuple and friends into the ::testing namespace.
comment|// It is part of our interface, having them in ::testing allows us to change
comment|// their types as needed.
name|using
name|GTEST_TUPLE_NAMESPACE_
operator|::
name|get
expr_stmt|;
name|using
name|GTEST_TUPLE_NAMESPACE_
operator|::
name|make_tuple
expr_stmt|;
name|using
name|GTEST_TUPLE_NAMESPACE_
operator|::
name|tuple
expr_stmt|;
name|using
name|GTEST_TUPLE_NAMESPACE_
operator|::
name|tuple_size
expr_stmt|;
name|using
name|GTEST_TUPLE_NAMESPACE_
operator|::
name|tuple_element
expr_stmt|;
endif|#
directive|endif
comment|// defined(GTEST_TUPLE_NAMESPACE_)
name|namespace
name|internal
block|{
comment|// A secret type that Google Test users don't know about.  It has no
comment|// definition on purpose.  Therefore it's impossible to create a
comment|// Secret object, which is what we want.
name|class
name|Secret
decl_stmt|;
comment|// The GTEST_COMPILE_ASSERT_ macro can be used to verify that a compile time
comment|// expression is true. For example, you could use it to verify the
comment|// size of a static array:
comment|//
comment|//   GTEST_COMPILE_ASSERT_(GTEST_ARRAY_SIZE_(names) == NUM_NAMES,
comment|//                         names_incorrect_size);
comment|//
comment|// or to make sure a struct is smaller than a certain size:
comment|//
comment|//   GTEST_COMPILE_ASSERT_(sizeof(foo)< 128, foo_too_large);
comment|//
comment|// The second argument to the macro is the name of the variable. If
comment|// the expression is false, most compilers will issue a warning/error
comment|// containing the name of the variable.
if|#
directive|if
name|GTEST_LANG_CXX11
define|#
directive|define
name|GTEST_COMPILE_ASSERT_
parameter_list|(
name|expr
parameter_list|,
name|msg
parameter_list|)
value|static_assert(expr, #msg)
else|#
directive|else
comment|// !GTEST_LANG_CXX11
name|template
operator|<
name|bool
operator|>
expr|struct
name|CompileAssert
block|{ }
expr_stmt|;
define|#
directive|define
name|GTEST_COMPILE_ASSERT_
parameter_list|(
name|expr
parameter_list|,
name|msg
parameter_list|)
define|\
value|typedef ::testing::internal::CompileAssert<(static_cast<bool>(expr))> \       msg[static_cast<bool>(expr) ? 1 : -1] GTEST_ATTRIBUTE_UNUSED_
endif|#
directive|endif
comment|// !GTEST_LANG_CXX11
comment|// Implementation details of GTEST_COMPILE_ASSERT_:
comment|//
comment|// (In C++11, we simply use static_assert instead of the following)
comment|//
comment|// - GTEST_COMPILE_ASSERT_ works by defining an array type that has -1
comment|//   elements (and thus is invalid) when the expression is false.
comment|//
comment|// - The simpler definition
comment|//
comment|//    #define GTEST_COMPILE_ASSERT_(expr, msg) typedef char msg[(expr) ? 1 : -1]
comment|//
comment|//   does not work, as gcc supports variable-length arrays whose sizes
comment|//   are determined at run-time (this is gcc's extension and not part
comment|//   of the C++ standard).  As a result, gcc fails to reject the
comment|//   following code with the simple definition:
comment|//
comment|//     int foo;
comment|//     GTEST_COMPILE_ASSERT_(foo, msg); // not supposed to compile as foo is
comment|//                                      // not a compile-time constant.
comment|//
comment|// - By using the type CompileAssert<(bool(expr))>, we ensures that
comment|//   expr is a compile-time constant.  (Template arguments must be
comment|//   determined at compile-time.)
comment|//
comment|// - The outter parentheses in CompileAssert<(bool(expr))> are necessary
comment|//   to work around a bug in gcc 3.4.4 and 4.0.1.  If we had written
comment|//
comment|//     CompileAssert<bool(expr)>
comment|//
comment|//   instead, these compilers will refuse to compile
comment|//
comment|//     GTEST_COMPILE_ASSERT_(5> 0, some_message);
comment|//
comment|//   (They seem to think the ">" in "5> 0" marks the end of the
comment|//   template argument list.)
comment|//
comment|// - The array size is (bool(expr) ? 1 : -1), instead of simply
comment|//
comment|//     ((expr) ? 1 : -1).
comment|//
comment|//   This is to avoid running into a bug in MS VC 7.1, which
comment|//   causes ((0.0) ? 1 : -1) to incorrectly evaluate to 1.
comment|// StaticAssertTypeEqHelper is used by StaticAssertTypeEq defined in gtest.h.
comment|//
comment|// This template is declared, but intentionally undefined.
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
expr|struct
name|StaticAssertTypeEqHelper
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|StaticAssertTypeEqHelper
operator|<
name|T
operator|,
name|T
operator|>
block|{   enum
block|{
name|value
operator|=
name|true
block|}
block|; }
expr_stmt|;
comment|// Evaluates to the number of elements in 'array'.
define|#
directive|define
name|GTEST_ARRAY_SIZE_
parameter_list|(
name|array
parameter_list|)
value|(sizeof(array) / sizeof(array[0]))
if|#
directive|if
name|GTEST_HAS_GLOBAL_STRING
typedef|typedef
operator|::
name|string
name|string
expr_stmt|;
else|#
directive|else
typedef|typedef
operator|::
name|std
operator|::
name|string
name|string
expr_stmt|;
endif|#
directive|endif
comment|// GTEST_HAS_GLOBAL_STRING
if|#
directive|if
name|GTEST_HAS_GLOBAL_WSTRING
typedef|typedef
operator|::
name|wstring
name|wstring
expr_stmt|;
elif|#
directive|elif
name|GTEST_HAS_STD_WSTRING
typedef|typedef
operator|::
name|std
operator|::
name|wstring
name|wstring
expr_stmt|;
endif|#
directive|endif
comment|// GTEST_HAS_GLOBAL_WSTRING
comment|// A helper for suppressing warnings on constant condition.  It just
comment|// returns 'condition'.
name|GTEST_API_
name|bool
name|IsTrue
parameter_list|(
name|bool
name|condition
parameter_list|)
function_decl|;
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
typedef|typedef
name|T
name|element_type
typedef|;
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
decl|const
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
modifier|*
name|release
parameter_list|()
block|{
name|T
modifier|*
specifier|const
name|ptr
init|=
name|ptr_
decl_stmt|;
name|ptr_
operator|=
name|NULL
expr_stmt|;
return|return
name|ptr
return|;
block|}
name|void
name|reset
parameter_list|(
name|T
modifier|*
name|p
init|=
name|NULL
parameter_list|)
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
name|IsTrue
argument_list|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|>
literal|0
argument_list|)
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
name|friend
name|void
name|swap
parameter_list|(
name|scoped_ptr
modifier|&
name|a
parameter_list|,
name|scoped_ptr
modifier|&
name|b
parameter_list|)
block|{
name|using
name|std
operator|::
name|swap
expr_stmt|;
name|swap
argument_list|(
name|a
operator|.
name|ptr_
argument_list|,
name|b
operator|.
name|ptr_
argument_list|)
expr_stmt|;
block|}
name|private
label|:
name|T
modifier|*
name|ptr_
decl_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|scoped_ptr
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Defines RE.
end_comment

begin_comment
comment|// A simple C++ wrapper for<regex.h>.  It uses the POSIX Extended
end_comment

begin_comment
comment|// Regular Expression syntax.
end_comment

begin_decl_stmt
name|class
name|GTEST_API_
name|RE
block|{
name|public
label|:
comment|// A copy constructor is required by the Standard to initialize object
comment|// references from r-values.
name|RE
argument_list|(
argument|const RE& other
argument_list|)
block|{
name|Init
argument_list|(
name|other
operator|.
name|pattern
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Constructs an RE from a string.
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
comment|// We use a const char* instead of an std::string, as Google Test used to be
comment|// used where std::string is not available.  TODO(wan@google.com): change to
comment|// std::string.
specifier|const
name|char
modifier|*
name|pattern_
decl_stmt|;
name|bool
name|is_valid_
decl_stmt|;
if|#
directive|if
name|GTEST_USES_POSIX_RE
name|regex_t
name|full_regex_
decl_stmt|;
comment|// For FullMatch().
name|regex_t
name|partial_regex_
decl_stmt|;
comment|// For PartialMatch().
else|#
directive|else
comment|// GTEST_USES_SIMPLE_RE
specifier|const
name|char
modifier|*
name|full_pattern_
decl_stmt|;
comment|// For FullMatch();
endif|#
directive|endif
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|RE
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Formats a source file path and a line number as they would appear
end_comment

begin_comment
comment|// in an error message from the compiler used to compile this code.
end_comment

begin_expr_stmt
name|GTEST_API_
operator|::
name|std
operator|::
name|string
name|FormatFileLocation
argument_list|(
argument|const char* file
argument_list|,
argument|int line
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Formats a file location for compiler-independent XML output.
end_comment

begin_comment
comment|// Although this function is not platform dependent, we put it next to
end_comment

begin_comment
comment|// FormatFileLocation in order to contrast the two functions.
end_comment

begin_expr_stmt
name|GTEST_API_
operator|::
name|std
operator|::
name|string
name|FormatCompilerIndependentFileLocation
argument_list|(
argument|const char* file
argument_list|,
argument|int line
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Defines logging utilities:
end_comment

begin_comment
comment|//   GTEST_LOG_(severity) - logs messages at the specified severity level. The
end_comment

begin_comment
comment|//                          message itself is streamed into the macro.
end_comment

begin_comment
comment|//   LogToStderr()  - directs all log messages to stderr.
end_comment

begin_comment
comment|//   FlushInfoLog() - flushes informational log messages.
end_comment

begin_enum
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
end_enum

begin_comment
comment|// Formats log entry severity, provides a stream object for streaming the
end_comment

begin_comment
comment|// log message, and terminates the message with a newline when going out of
end_comment

begin_comment
comment|// scope.
end_comment

begin_decl_stmt
name|class
name|GTEST_API_
name|GTestLog
block|{
name|public
label|:
name|GTestLog
argument_list|(
argument|GTestLogSeverity severity
argument_list|,
argument|const char* file
argument_list|,
argument|int line
argument_list|)
empty_stmt|;
comment|// Flushes the buffers and, if severity is GTEST_FATAL, aborts the program.
operator|~
name|GTestLog
argument_list|()
expr_stmt|;
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
name|private
label|:
specifier|const
name|GTestLogSeverity
name|severity_
decl_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|GTestLog
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GTEST_LOG_
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_LOG_
parameter_list|(
name|severity
parameter_list|)
define|\
value|::testing::internal::GTestLog(::testing::internal::GTEST_##severity, \                                   __FILE__, __LINE__).GetStream()
end_define

begin_function
specifier|inline
name|void
name|LogToStderr
parameter_list|()
block|{}
end_function

begin_function
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
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GTEST_LOG_)
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GTEST_CHECK_
argument_list|)
end_if

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

begin_define
define|#
directive|define
name|GTEST_CHECK_
parameter_list|(
name|condition
parameter_list|)
define|\
value|GTEST_AMBIGUOUS_ELSE_BLOCKER_ \     if (::testing::internal::IsTrue(condition)) \       ; \     else \       GTEST_LOG_(FATAL)<< "Condition " #condition " failed. "
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GTEST_CHECK_)
end_comment

begin_comment
comment|// An all-mode assert to verify that the given POSIX-style function
end_comment

begin_comment
comment|// call returns 0 (indicating success).  Known limitation: this
end_comment

begin_comment
comment|// doesn't expand to a balanced 'if' statement, so enclose the macro
end_comment

begin_comment
comment|// in {} if you need to use it as the only statement in an 'if'
end_comment

begin_comment
comment|// branch.
end_comment

begin_define
define|#
directive|define
name|GTEST_CHECK_POSIX_SUCCESS_
parameter_list|(
name|posix_call
parameter_list|)
define|\
value|if (const int gtest_error = (posix_call)) \     GTEST_LOG_(FATAL)<< #posix_call<< "failed with error " \<< gtest_error
end_define

begin_if
if|#
directive|if
name|GTEST_HAS_STD_MOVE_
end_if

begin_expr_stmt
name|using
name|std
operator|::
name|move
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|// GTEST_HAS_STD_MOVE_
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|const
name|T
operator|&
name|move
argument_list|(
argument|const T& t
argument_list|)
block|{
return|return
name|t
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_STD_MOVE_
end_comment

begin_comment
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN USER CODE.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Use ImplicitCast_ as a safe version of static_cast for upcasting in
end_comment

begin_comment
comment|// the type hierarchy (e.g. casting a Foo* to a SuperclassOfFoo* or a
end_comment

begin_comment
comment|// const Foo*).  When you use ImplicitCast_, the compiler checks that
end_comment

begin_comment
comment|// the cast is safe.  Such explicit ImplicitCast_s are necessary in
end_comment

begin_comment
comment|// surprisingly many situations where C++ demands an exact type match
end_comment

begin_comment
comment|// instead of an argument type convertable to a target type.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The syntax for using ImplicitCast_ is the same as for static_cast:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   ImplicitCast_<ToType>(expr)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ImplicitCast_ would have been part of the C++ standard library,
end_comment

begin_comment
comment|// but the proposal was submitted too late.  It will probably make
end_comment

begin_comment
comment|// its way into the language in the future.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This relatively ugly name is intentional. It prevents clashes with
end_comment

begin_comment
comment|// similar functions users may have (e.g., implicit_cast). The internal
end_comment

begin_comment
comment|// namespace alone is not enough because the function can be found by ADL.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|To
operator|>
specifier|inline
name|To
name|ImplicitCast_
argument_list|(
argument|To x
argument_list|)
block|{
return|return
name|x
return|;
block|}
end_expr_stmt

begin_comment
comment|// When you upcast (that is, cast a pointer from type Foo to type
end_comment

begin_comment
comment|// SuperclassOfFoo), it's fine to use ImplicitCast_<>, since upcasts
end_comment

begin_comment
comment|// always succeed.  When you downcast (that is, cast a pointer from
end_comment

begin_comment
comment|// type Foo to type SubclassOfFoo), static_cast<> isn't safe, because
end_comment

begin_comment
comment|// how do you know the pointer is really of type SubclassOfFoo?  It
end_comment

begin_comment
comment|// could be a bare Foo, or of type DifferentSubclassOfFoo.  Thus,
end_comment

begin_comment
comment|// when you downcast, you should use this macro.  In debug mode, we
end_comment

begin_comment
comment|// use dynamic_cast<> to double-check the downcast is legal (we die
end_comment

begin_comment
comment|// if it's not).  In normal mode, we do the efficient static_cast<>
end_comment

begin_comment
comment|// instead.  Thus, it's important to test in debug mode to make sure
end_comment

begin_comment
comment|// the cast is legal!
end_comment

begin_comment
comment|//    This is the only place in the code we should use dynamic_cast<>.
end_comment

begin_comment
comment|// In particular, you SHOULDN'T be using dynamic_cast<> in order to
end_comment

begin_comment
comment|// do RTTI (eg code like this:
end_comment

begin_comment
comment|//    if (dynamic_cast<Subclass1>(foo)) HandleASubclass1Object(foo);
end_comment

begin_comment
comment|//    if (dynamic_cast<Subclass2>(foo)) HandleASubclass2Object(foo);
end_comment

begin_comment
comment|// You should design the code some other way not to need this.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This relatively ugly name is intentional. It prevents clashes with
end_comment

begin_comment
comment|// similar functions users may have (e.g., down_cast). The internal
end_comment

begin_comment
comment|// namespace alone is not enough because the function can be found by ADL.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|To
operator|,
name|typename
name|From
operator|>
comment|// use like this: DownCast_<T*>(foo);
specifier|inline
name|To
name|DownCast_
argument_list|(
argument|From* f
argument_list|)
block|{
comment|// so we only accept pointers
comment|// Ensures that To is a sub-type of From *.  This test is here only
comment|// for compile-time type checking, and has no overhead in an
comment|// optimized build at run-time, as it will be optimized away
comment|// completely.
name|GTEST_INTENTIONAL_CONST_COND_PUSH_
argument_list|()
if|if
condition|(
name|false
condition|)
block|{
name|GTEST_INTENTIONAL_CONST_COND_POP_
argument_list|()
specifier|const
name|To
name|to
init|=
name|NULL
decl_stmt|;
operator|::
name|testing
operator|::
name|internal
operator|::
name|ImplicitCast_
operator|<
name|From
operator|*
operator|>
operator|(
name|to
operator|)
expr_stmt|;
block|}
if|#
directive|if
name|GTEST_HAS_RTTI
comment|// RTTI: debug mode only!
name|GTEST_CHECK_
argument_list|(
name|f
operator|==
name|NULL
operator|||
name|dynamic_cast
operator|<
name|To
operator|>
operator|(
name|f
operator|)
operator|!=
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_return
return|return
name|static_cast
operator|<
name|To
operator|>
operator|(
name|f
operator|)
return|;
end_return

begin_comment
unit|}
comment|// Downcasts the pointer of type Base to Derived.
end_comment

begin_comment
comment|// Derived must be a subclass of Base. The parameter MUST
end_comment

begin_comment
comment|// point to a class of type Derived, not any subclass of it.
end_comment

begin_comment
comment|// When RTTI is available, the function performs a runtime
end_comment

begin_comment
comment|// check to enforce this.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|Derived
operator|,
name|class
name|Base
operator|>
name|Derived
operator|*
name|CheckedDowncastToActualType
argument_list|(
argument|Base* base
argument_list|)
block|{
if|#
directive|if
name|GTEST_HAS_RTTI
name|GTEST_CHECK_
argument_list|(
name|typeid
argument_list|(
operator|*
name|base
argument_list|)
operator|==
name|typeid
argument_list|(
name|Derived
argument_list|)
argument_list|)
block|;
endif|#
directive|endif
if|#
directive|if
name|GTEST_HAS_DOWNCAST_
return|return
operator|::
name|down_cast
operator|<
name|Derived
operator|*
operator|>
operator|(
name|base
operator|)
return|;
end_expr_stmt

begin_elif
elif|#
directive|elif
name|GTEST_HAS_RTTI
end_elif

begin_return
return|return
name|dynamic_cast
operator|<
name|Derived
operator|*
operator|>
operator|(
name|base
operator|)
return|;
end_return

begin_comment
comment|// NOLINT
end_comment

begin_else
else|#
directive|else
end_else

begin_return
return|return
name|static_cast
operator|<
name|Derived
operator|*
operator|>
operator|(
name|base
operator|)
return|;
end_return

begin_comment
comment|// Poor man's downcast.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
unit|}
if|#
directive|if
name|GTEST_HAS_STREAM_REDIRECTION
end_if

begin_comment
comment|// Defines the stderr capturer:
end_comment

begin_comment
comment|//   CaptureStdout     - starts capturing stdout.
end_comment

begin_comment
comment|//   GetCapturedStdout - stops capturing stdout and returns the captured string.
end_comment

begin_comment
comment|//   CaptureStderr     - starts capturing stderr.
end_comment

begin_comment
comment|//   GetCapturedStderr - stops capturing stderr and returns the captured string.
end_comment

begin_comment
comment|//
end_comment

begin_function_decl
unit|GTEST_API_
name|void
name|CaptureStdout
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|GTEST_API_
name|std
operator|::
name|string
name|GetCapturedStdout
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
name|GTEST_API_
name|void
name|CaptureStderr
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|GTEST_API_
name|std
operator|::
name|string
name|GetCapturedStderr
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_STREAM_REDIRECTION
end_comment

begin_comment
comment|// Returns a path to temporary directory.
end_comment

begin_expr_stmt
name|GTEST_API_
name|std
operator|::
name|string
name|TempDir
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Returns the size (in bytes) of a file.
end_comment

begin_function_decl
name|GTEST_API_
name|size_t
name|GetFileSize
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Reads the entire content of a file as a string.
end_comment

begin_expr_stmt
name|GTEST_API_
name|std
operator|::
name|string
name|ReadEntireFile
argument_list|(
name|FILE
operator|*
name|file
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// All command line arguments.
end_comment

begin_expr_stmt
name|GTEST_API_
specifier|const
operator|::
name|std
operator|::
name|vector
operator|<
name|testing
operator|::
name|internal
operator|::
name|string
operator|>
operator|&
name|GetArgvs
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|GTEST_HAS_DEATH_TEST
end_if

begin_expr_stmt
specifier|const
operator|::
name|std
operator|::
name|vector
operator|<
name|testing
operator|::
name|internal
operator|::
name|string
operator|>
operator|&
name|GetInjectableArgvs
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|SetInjectableArgvs
argument_list|(
specifier|const
operator|::
name|std
operator|::
name|vector
operator|<
name|testing
operator|::
name|internal
operator|::
name|string
operator|>
operator|*
name|new_argvs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_DEATH_TEST
end_comment

begin_comment
comment|// Defines synchronization primitives.
end_comment

begin_if
if|#
directive|if
name|GTEST_IS_THREADSAFE
end_if

begin_if
if|#
directive|if
name|GTEST_HAS_PTHREAD
end_if

begin_comment
comment|// Sleeps for (roughly) n milliseconds.  This function is only for testing
end_comment

begin_comment
comment|// Google Test's own constructs.  Don't use it in user tests, either
end_comment

begin_comment
comment|// directly or indirectly.
end_comment

begin_function
specifier|inline
name|void
name|SleepMilliseconds
parameter_list|(
name|int
name|n
parameter_list|)
block|{
specifier|const
name|timespec
name|time
init|=
block|{
literal|0
block|,
comment|// 0 seconds.
name|n
operator|*
literal|1000L
operator|*
literal|1000L
block|,
comment|// And n ms.
block|}
decl_stmt|;
name|nanosleep
argument_list|(
operator|&
name|time
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_PTHREAD
end_comment

begin_if
if|#
directive|if
name|GTEST_HAS_NOTIFICATION_
end_if

begin_comment
comment|// Notification has already been imported into the namespace.
end_comment

begin_comment
comment|// Nothing to do here.
end_comment

begin_elif
elif|#
directive|elif
name|GTEST_HAS_PTHREAD
end_elif

begin_comment
comment|// Allows a controller thread to pause execution of newly created
end_comment

begin_comment
comment|// threads until notified.  Instances of this class must be created
end_comment

begin_comment
comment|// and destroyed in the controller thread.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This class is only for testing Google Test's own constructs. Do not
end_comment

begin_comment
comment|// use it in user tests, either directly or indirectly.
end_comment

begin_decl_stmt
name|class
name|Notification
block|{
name|public
label|:
name|Notification
argument_list|()
operator|:
name|notified_
argument_list|(
argument|false
argument_list|)
block|{
name|GTEST_CHECK_POSIX_SUCCESS_
argument_list|(
name|pthread_mutex_init
argument_list|(
operator|&
name|mutex_
argument_list|,
name|NULL
argument_list|)
argument_list|)
block|;   }
operator|~
name|Notification
argument_list|()
block|{
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mutex_
argument_list|)
block|;   }
comment|// Notifies all threads created with this notification to start. Must
comment|// be called from the controller thread.
name|void
name|Notify
argument_list|()
block|{
name|pthread_mutex_lock
argument_list|(
operator|&
name|mutex_
argument_list|)
block|;
name|notified_
operator|=
name|true
block|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mutex_
argument_list|)
block|;   }
comment|// Blocks until the controller thread notifies. Must be called from a test
comment|// thread.
name|void
name|WaitForNotification
argument_list|()
block|{
for|for
control|(
init|;
condition|;
control|)
block|{
name|pthread_mutex_lock
argument_list|(
operator|&
name|mutex_
argument_list|)
expr_stmt|;
specifier|const
name|bool
name|notified
init|=
name|notified_
decl_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mutex_
argument_list|)
expr_stmt|;
if|if
condition|(
name|notified
condition|)
break|break;
name|SleepMilliseconds
argument_list|(
literal|10
argument_list|)
expr_stmt|;
block|}
block|}
name|private
operator|:
name|pthread_mutex_t
name|mutex_
expr_stmt|;
name|bool
name|notified_
decl_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|Notification
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_elif
elif|#
directive|elif
name|GTEST_OS_WINDOWS
operator|&&
operator|!
name|GTEST_OS_WINDOWS_PHONE
operator|&&
operator|!
name|GTEST_OS_WINDOWS_RT
end_elif

begin_function_decl
name|GTEST_API_
name|void
name|SleepMilliseconds
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Provides leak-safe Windows kernel handle ownership.
end_comment

begin_comment
comment|// Used in death tests and in threading support.
end_comment

begin_decl_stmt
name|class
name|GTEST_API_
name|AutoHandle
block|{
name|public
label|:
comment|// Assume that Win32 HANDLE type is equivalent to void*. Doing so allows us to
comment|// avoid including<windows.h> in this header file. Including<windows.h> is
comment|// undesirable because it defines a lot of symbols and macros that tend to
comment|// conflict with client code. This assumption is verified by
comment|// WindowsTypesTest.HANDLEIsVoidStar.
typedef|typedef
name|void
modifier|*
name|Handle
typedef|;
name|AutoHandle
argument_list|()
expr_stmt|;
name|explicit
name|AutoHandle
parameter_list|(
name|Handle
name|handle
parameter_list|)
function_decl|;
operator|~
name|AutoHandle
argument_list|()
expr_stmt|;
name|Handle
name|Get
argument_list|()
specifier|const
expr_stmt|;
name|void
name|Reset
parameter_list|()
function_decl|;
name|void
name|Reset
parameter_list|(
name|Handle
name|handle
parameter_list|)
function_decl|;
name|private
label|:
comment|// Returns true iff the handle is a valid handle object that can be closed.
name|bool
name|IsCloseable
parameter_list|()
function_decl|const;
name|Handle
name|handle_
decl_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|AutoHandle
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Allows a controller thread to pause execution of newly created
end_comment

begin_comment
comment|// threads until notified.  Instances of this class must be created
end_comment

begin_comment
comment|// and destroyed in the controller thread.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This class is only for testing Google Test's own constructs. Do not
end_comment

begin_comment
comment|// use it in user tests, either directly or indirectly.
end_comment

begin_decl_stmt
name|class
name|GTEST_API_
name|Notification
block|{
name|public
label|:
name|Notification
argument_list|()
expr_stmt|;
name|void
name|Notify
parameter_list|()
function_decl|;
name|void
name|WaitForNotification
parameter_list|()
function_decl|;
name|private
label|:
name|AutoHandle
name|event_
decl_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|Notification
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_NOTIFICATION_
end_comment

begin_comment
comment|// On MinGW, we can have both GTEST_OS_WINDOWS and GTEST_HAS_PTHREAD
end_comment

begin_comment
comment|// defined, but we don't want to use MinGW's pthreads implementation, which
end_comment

begin_comment
comment|// has conformance problems with some versions of the POSIX standard.
end_comment

begin_if
if|#
directive|if
name|GTEST_HAS_PTHREAD
operator|&&
operator|!
name|GTEST_OS_WINDOWS_MINGW
end_if

begin_comment
comment|// As a C-function, ThreadFuncWithCLinkage cannot be templated itself.
end_comment

begin_comment
comment|// Consequently, it cannot select a correct instantiation of ThreadWithParam
end_comment

begin_comment
comment|// in order to call its Run(). Introducing ThreadWithParamBase as a
end_comment

begin_comment
comment|// non-templated base class for ThreadWithParam allows us to bypass this
end_comment

begin_comment
comment|// problem.
end_comment

begin_decl_stmt
name|class
name|ThreadWithParamBase
block|{
name|public
label|:
name|virtual
operator|~
name|ThreadWithParamBase
argument_list|()
block|{}
name|virtual
name|void
name|Run
argument_list|()
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// pthread_create() accepts a pointer to a function type with the C linkage.
end_comment

begin_comment
comment|// According to the Standard (7.5/1), function types with different linkages
end_comment

begin_comment
comment|// are different even if they are otherwise identical.  Some compilers (for
end_comment

begin_comment
comment|// example, SunStudio) treat them as different types.  Since class methods
end_comment

begin_comment
comment|// cannot be defined with C-linkage we need to define a free C-function to
end_comment

begin_comment
comment|// pass into pthread_create().
end_comment

begin_extern
extern|extern
literal|"C"
specifier|inline
name|void
modifier|*
name|ThreadFuncWithCLinkage
parameter_list|(
name|void
modifier|*
name|thread
parameter_list|)
block|{
name|static_cast
operator|<
name|ThreadWithParamBase
operator|*
operator|>
operator|(
name|thread
operator|)
operator|->
name|Run
argument_list|()
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_extern

begin_comment
comment|// Helper class for testing Google Test's multi-threading constructs.
end_comment

begin_comment
comment|// To use it, write:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   void ThreadFunc(int param) { /* Do things with param */ }
end_comment

begin_comment
comment|//   Notification thread_can_start;
end_comment

begin_comment
comment|//   ...
end_comment

begin_comment
comment|//   // The thread_can_start parameter is optional; you can supply NULL.
end_comment

begin_comment
comment|//   ThreadWithParam<int> thread(&ThreadFunc, 5,&thread_can_start);
end_comment

begin_comment
comment|//   thread_can_start.Notify();
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// These classes are only for testing Google Test's own constructs. Do
end_comment

begin_comment
comment|// not use them in user tests, either directly or indirectly.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ThreadWithParam
operator|:
name|public
name|ThreadWithParamBase
block|{
name|public
operator|:
typedef|typedef
name|void
name|UserThreadFunc
parameter_list|(
name|T
parameter_list|)
function_decl|;
name|ThreadWithParam
argument_list|(
argument|UserThreadFunc* func
argument_list|,
argument|T param
argument_list|,
argument|Notification* thread_can_start
argument_list|)
operator|:
name|func_
argument_list|(
name|func
argument_list|)
operator|,
name|param_
argument_list|(
name|param
argument_list|)
operator|,
name|thread_can_start_
argument_list|(
name|thread_can_start
argument_list|)
operator|,
name|finished_
argument_list|(
argument|false
argument_list|)
block|{
name|ThreadWithParamBase
operator|*
specifier|const
name|base
operator|=
name|this
block|;
comment|// The thread can be created only after all fields except thread_
comment|// have been initialized.
name|GTEST_CHECK_POSIX_SUCCESS_
argument_list|(
name|pthread_create
argument_list|(
operator|&
name|thread_
argument_list|,
literal|0
argument_list|,
operator|&
name|ThreadFuncWithCLinkage
argument_list|,
name|base
argument_list|)
argument_list|)
block|;   }
operator|~
name|ThreadWithParam
argument_list|()
block|{
name|Join
argument_list|()
block|; }
name|void
name|Join
argument_list|()
block|{
if|if
condition|(
operator|!
name|finished_
condition|)
block|{
name|GTEST_CHECK_POSIX_SUCCESS_
argument_list|(
name|pthread_join
argument_list|(
name|thread_
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|finished_
operator|=
name|true
expr_stmt|;
block|}
end_expr_stmt

begin_function
unit|}    virtual
name|void
name|Run
parameter_list|()
block|{
if|if
condition|(
name|thread_can_start_
operator|!=
name|NULL
condition|)
name|thread_can_start_
operator|->
name|WaitForNotification
argument_list|()
expr_stmt|;
name|func_
argument_list|(
name|param_
argument_list|)
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|UserThreadFunc
modifier|*
specifier|const
name|func_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// User-supplied thread function.
end_comment

begin_decl_stmt
specifier|const
name|T
name|param_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// User-supplied parameter to the thread function.
end_comment

begin_comment
comment|// When non-NULL, used to block execution until the controller thread
end_comment

begin_comment
comment|// notifies.
end_comment

begin_decl_stmt
name|Notification
modifier|*
specifier|const
name|thread_can_start_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|finished_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// true iff we know that the thread function has finished.
end_comment

begin_decl_stmt
name|pthread_t
name|thread_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The native thread object.
end_comment

begin_expr_stmt
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ThreadWithParam
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// !GTEST_OS_WINDOWS&& GTEST_HAS_PTHREAD ||
end_comment

begin_comment
comment|// GTEST_HAS_MUTEX_AND_THREAD_LOCAL_
end_comment

begin_if
if|#
directive|if
name|GTEST_HAS_MUTEX_AND_THREAD_LOCAL_
end_if

begin_comment
comment|// Mutex and ThreadLocal have already been imported into the namespace.
end_comment

begin_comment
comment|// Nothing to do here.
end_comment

begin_elif
elif|#
directive|elif
name|GTEST_OS_WINDOWS
operator|&&
operator|!
name|GTEST_OS_WINDOWS_PHONE
operator|&&
operator|!
name|GTEST_OS_WINDOWS_RT
end_elif

begin_comment
comment|// Mutex implements mutex on Windows platforms.  It is used in conjunction
end_comment

begin_comment
comment|// with class MutexLock:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   Mutex mutex;
end_comment

begin_comment
comment|//   ...
end_comment

begin_comment
comment|//   MutexLock lock(&mutex);  // Acquires the mutex and releases it at the
end_comment

begin_comment
comment|//                            // end of the current scope.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A static Mutex *must* be defined or declared using one of the following
end_comment

begin_comment
comment|// macros:
end_comment

begin_comment
comment|//   GTEST_DEFINE_STATIC_MUTEX_(g_some_mutex);
end_comment

begin_comment
comment|//   GTEST_DECLARE_STATIC_MUTEX_(g_some_mutex);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// (A non-static Mutex is defined/declared in the usual way).
end_comment

begin_decl_stmt
name|class
name|GTEST_API_
name|Mutex
block|{
name|public
label|:
enum|enum
name|MutexType
block|{
name|kStatic
init|=
literal|0
block|,
name|kDynamic
init|=
literal|1
block|}
enum|;
comment|// We rely on kStaticMutex being 0 as it is to what the linker initializes
comment|// type_ in static mutexes.  critical_section_ will be initialized lazily
comment|// in ThreadSafeLazyInit().
enum|enum
name|StaticConstructorSelector
block|{
name|kStaticMutex
init|=
literal|0
block|}
enum|;
comment|// This constructor intentionally does nothing.  It relies on type_ being
comment|// statically initialized to 0 (effectively setting it to kStatic) and on
comment|// ThreadSafeLazyInit() to lazily initialize the rest of the members.
name|explicit
name|Mutex
parameter_list|(
name|StaticConstructorSelector
comment|/*dummy*/
parameter_list|)
block|{}
name|Mutex
argument_list|()
expr_stmt|;
operator|~
name|Mutex
argument_list|()
expr_stmt|;
name|void
name|Lock
parameter_list|()
function_decl|;
name|void
name|Unlock
parameter_list|()
function_decl|;
comment|// Does nothing if the current thread holds the mutex. Otherwise, crashes
comment|// with high probability.
name|void
name|AssertHeld
parameter_list|()
function_decl|;
name|private
label|:
comment|// Initializes owner_thread_id_ and critical_section_ in static mutexes.
name|void
name|ThreadSafeLazyInit
parameter_list|()
function_decl|;
comment|// Per http://blogs.msdn.com/b/oldnewthing/archive/2004/02/23/78395.aspx,
comment|// we assume that 0 is an invalid value for thread IDs.
name|unsigned
name|int
name|owner_thread_id_
decl_stmt|;
comment|// For static mutexes, we rely on these members being initialized to zeros
comment|// by the linker.
name|MutexType
name|type_
decl_stmt|;
name|long
name|critical_section_init_phase_
decl_stmt|;
comment|// NOLINT
name|_RTL_CRITICAL_SECTION
modifier|*
name|critical_section_
decl_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|Mutex
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|GTEST_DECLARE_STATIC_MUTEX_
parameter_list|(
name|mutex
parameter_list|)
define|\
value|extern ::testing::internal::Mutex mutex
end_define

begin_define
define|#
directive|define
name|GTEST_DEFINE_STATIC_MUTEX_
parameter_list|(
name|mutex
parameter_list|)
define|\
value|::testing::internal::Mutex mutex(::testing::internal::Mutex::kStaticMutex)
end_define

begin_comment
comment|// We cannot name this class MutexLock because the ctor declaration would
end_comment

begin_comment
comment|// conflict with a macro named MutexLock, which is defined on some
end_comment

begin_comment
comment|// platforms. That macro is used as a defensive measure to prevent against
end_comment

begin_comment
comment|// inadvertent misuses of MutexLock like "MutexLock(&mu)" rather than
end_comment

begin_comment
comment|// "MutexLock l(&mu)".  Hence the typedef trick below.
end_comment

begin_decl_stmt
name|class
name|GTestMutexLock
block|{
name|public
label|:
name|explicit
name|GTestMutexLock
argument_list|(
name|Mutex
operator|*
name|mutex
argument_list|)
operator|:
name|mutex_
argument_list|(
argument|mutex
argument_list|)
block|{
name|mutex_
operator|->
name|Lock
argument_list|()
block|; }
operator|~
name|GTestMutexLock
argument_list|()
block|{
name|mutex_
operator|->
name|Unlock
argument_list|()
block|; }
name|private
operator|:
name|Mutex
operator|*
specifier|const
name|mutex_
expr_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|GTestMutexLock
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|GTestMutexLock
name|MutexLock
typedef|;
end_typedef

begin_comment
comment|// Base class for ValueHolder<T>.  Allows a caller to hold and delete a value
end_comment

begin_comment
comment|// without knowing its type.
end_comment

begin_decl_stmt
name|class
name|ThreadLocalValueHolderBase
block|{
name|public
label|:
name|virtual
operator|~
name|ThreadLocalValueHolderBase
argument_list|()
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Provides a way for a thread to send notifications to a ThreadLocal
end_comment

begin_comment
comment|// regardless of its parameter type.
end_comment

begin_decl_stmt
name|class
name|ThreadLocalBase
block|{
name|public
label|:
comment|// Creates a new ValueHolder<T> object holding a default value passed to
comment|// this ThreadLocal<T>'s constructor and returns it.  It is the caller's
comment|// responsibility not to call this when the ThreadLocal<T> instance already
comment|// has a value on the current thread.
name|virtual
name|ThreadLocalValueHolderBase
operator|*
name|NewValueForCurrentThread
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|protected
label|:
name|ThreadLocalBase
argument_list|()
block|{}
name|virtual
operator|~
name|ThreadLocalBase
argument_list|()
block|{}
name|private
operator|:
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ThreadLocalBase
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Maps a thread to a set of ThreadLocals that have values instantiated on that
end_comment

begin_comment
comment|// thread and notifies them when the thread exits.  A ThreadLocal instance is
end_comment

begin_comment
comment|// expected to persist until all threads it has values on have terminated.
end_comment

begin_decl_stmt
name|class
name|GTEST_API_
name|ThreadLocalRegistry
block|{
name|public
label|:
comment|// Registers thread_local_instance as having value on the current thread.
comment|// Returns a value that can be used to identify the thread from other threads.
specifier|static
name|ThreadLocalValueHolderBase
modifier|*
name|GetValueOnCurrentThread
parameter_list|(
specifier|const
name|ThreadLocalBase
modifier|*
name|thread_local_instance
parameter_list|)
function_decl|;
comment|// Invoked when a ThreadLocal instance is destroyed.
specifier|static
name|void
name|OnThreadLocalDestroyed
parameter_list|(
specifier|const
name|ThreadLocalBase
modifier|*
name|thread_local_instance
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|GTEST_API_
name|ThreadWithParamBase
block|{
name|public
label|:
name|void
name|Join
parameter_list|()
function_decl|;
name|protected
label|:
name|class
name|Runnable
block|{
name|public
label|:
name|virtual
operator|~
name|Runnable
argument_list|()
block|{}
name|virtual
name|void
name|Run
argument_list|()
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
name|ThreadWithParamBase
argument_list|(
name|Runnable
operator|*
name|runnable
argument_list|,
name|Notification
operator|*
name|thread_can_start
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|ThreadWithParamBase
argument_list|()
expr_stmt|;
name|private
label|:
name|AutoHandle
name|thread_
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Helper class for testing Google Test's multi-threading constructs.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ThreadWithParam
operator|:
name|public
name|ThreadWithParamBase
block|{
name|public
operator|:
typedef|typedef
name|void
name|UserThreadFunc
parameter_list|(
name|T
parameter_list|)
function_decl|;
name|ThreadWithParam
argument_list|(
argument|UserThreadFunc* func
argument_list|,
argument|T param
argument_list|,
argument|Notification* thread_can_start
argument_list|)
operator|:
name|ThreadWithParamBase
argument_list|(
argument|new RunnableImpl(func, param)
argument_list|,
argument|thread_can_start
argument_list|)
block|{   }
name|virtual
operator|~
name|ThreadWithParam
argument_list|()
block|{}
name|private
operator|:
name|class
name|RunnableImpl
operator|:
name|public
name|Runnable
block|{
name|public
operator|:
name|RunnableImpl
argument_list|(
argument|UserThreadFunc* func
argument_list|,
argument|T param
argument_list|)
operator|:
name|func_
argument_list|(
name|func
argument_list|)
block|,
name|param_
argument_list|(
argument|param
argument_list|)
block|{     }
name|virtual
operator|~
name|RunnableImpl
argument_list|()
block|{}
name|virtual
name|void
name|Run
argument_list|()
block|{
name|func_
argument_list|(
name|param_
argument_list|)
block|;     }
name|private
operator|:
name|UserThreadFunc
operator|*
specifier|const
name|func_
block|;
specifier|const
name|T
name|param_
block|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|RunnableImpl
argument_list|)
block|;   }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ThreadWithParam
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements thread-local storage on Windows systems.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   // Thread 1
end_comment

begin_comment
comment|//   ThreadLocal<int> tl(100);  // 100 is the default value for each thread.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   // Thread 2
end_comment

begin_comment
comment|//   tl.set(150);  // Changes the value for thread 2 only.
end_comment

begin_comment
comment|//   EXPECT_EQ(150, tl.get());
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   // Thread 1
end_comment

begin_comment
comment|//   EXPECT_EQ(100, tl.get());  // In thread 1, tl has the original value.
end_comment

begin_comment
comment|//   tl.set(200);
end_comment

begin_comment
comment|//   EXPECT_EQ(200, tl.get());
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The template type argument T must have a public copy constructor.
end_comment

begin_comment
comment|// In addition, the default ThreadLocal constructor requires T to have
end_comment

begin_comment
comment|// a public default constructor.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The users of a TheadLocal instance have to make sure that all but one
end_comment

begin_comment
comment|// threads (including the main one) using that instance have exited before
end_comment

begin_comment
comment|// destroying it. Otherwise, the per-thread objects managed for them by the
end_comment

begin_comment
comment|// ThreadLocal instance are not guaranteed to be destroyed on all platforms.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Google Test only uses global ThreadLocal objects.  That means they
end_comment

begin_comment
comment|// will die after main() has returned.  Therefore, no per-thread
end_comment

begin_comment
comment|// object managed by Google Test will be leaked as long as all threads
end_comment

begin_comment
comment|// using Google Test have exited when main() returns.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ThreadLocal
operator|:
name|public
name|ThreadLocalBase
block|{
name|public
operator|:
name|ThreadLocal
argument_list|()
operator|:
name|default_factory_
argument_list|(
argument|new DefaultValueHolderFactory()
argument_list|)
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
name|default_factory_
argument_list|(
argument|new InstanceValueHolderFactory(value)
argument_list|)
block|{}
operator|~
name|ThreadLocal
argument_list|()
block|{
name|ThreadLocalRegistry
operator|::
name|OnThreadLocalDestroyed
argument_list|(
name|this
argument_list|)
block|; }
name|T
operator|*
name|pointer
argument_list|()
block|{
return|return
name|GetOrCreateValue
argument_list|()
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
name|GetOrCreateValue
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|T
operator|&
name|get
argument_list|()
specifier|const
block|{
return|return
operator|*
name|pointer
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|void
name|set
parameter_list|(
specifier|const
name|T
modifier|&
name|value
parameter_list|)
block|{
operator|*
name|pointer
argument_list|()
operator|=
name|value
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_comment
comment|// Holds a value of T.  Can be deleted via its base class without the caller
end_comment

begin_comment
comment|// knowing the type of T.
end_comment

begin_decl_stmt
name|class
name|ValueHolder
range|:
name|public
name|ThreadLocalValueHolderBase
block|{
name|public
operator|:
name|ValueHolder
argument_list|()
operator|:
name|value_
argument_list|()
block|{}
name|explicit
name|ValueHolder
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
name|private
operator|:
name|T
name|value_
block|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ValueHolder
argument_list|)
block|;   }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|T
operator|*
name|GetOrCreateValue
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|ValueHolder
operator|*
operator|>
operator|(
name|ThreadLocalRegistry
operator|::
name|GetValueOnCurrentThread
argument_list|(
name|this
argument_list|)
operator|)
operator|->
name|pointer
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|virtual
name|ThreadLocalValueHolderBase
operator|*
name|NewValueForCurrentThread
argument_list|()
specifier|const
block|{
return|return
name|default_factory_
operator|->
name|MakeNewHolder
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|class
name|ValueHolderFactory
block|{
name|public
label|:
name|ValueHolderFactory
argument_list|()
block|{}
name|virtual
operator|~
name|ValueHolderFactory
argument_list|()
block|{}
name|virtual
name|ValueHolder
operator|*
name|MakeNewHolder
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|private
label|:
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ValueHolderFactory
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|DefaultValueHolderFactory
range|:
name|public
name|ValueHolderFactory
block|{
name|public
operator|:
name|DefaultValueHolderFactory
argument_list|()
block|{}
name|virtual
name|ValueHolder
operator|*
name|MakeNewHolder
argument_list|()
specifier|const
block|{
return|return
name|new
name|ValueHolder
argument_list|()
return|;
block|}
name|private
operator|:
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|DefaultValueHolderFactory
argument_list|)
block|;   }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|InstanceValueHolderFactory
range|:
name|public
name|ValueHolderFactory
block|{
name|public
operator|:
name|explicit
name|InstanceValueHolderFactory
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
name|virtual
name|ValueHolder
operator|*
name|MakeNewHolder
argument_list|()
specifier|const
block|{
return|return
name|new
name|ValueHolder
argument_list|(
name|value_
argument_list|)
return|;
block|}
name|private
operator|:
specifier|const
name|T
name|value_
block|;
comment|// The value for each thread.
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|InstanceValueHolderFactory
argument_list|)
block|;   }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|scoped_ptr
operator|<
name|ValueHolderFactory
operator|>
name|default_factory_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ThreadLocal
argument_list|)
expr_stmt|;
end_expr_stmt

begin_elif
unit|};
elif|#
directive|elif
name|GTEST_HAS_PTHREAD
end_elif

begin_comment
comment|// MutexBase and Mutex implement mutex on pthreads-based platforms.
end_comment

begin_decl_stmt
name|class
name|MutexBase
block|{
name|public
label|:
comment|// Acquires this mutex.
name|void
name|Lock
parameter_list|()
block|{
name|GTEST_CHECK_POSIX_SUCCESS_
argument_list|(
name|pthread_mutex_lock
argument_list|(
operator|&
name|mutex_
argument_list|)
argument_list|)
expr_stmt|;
name|owner_
operator|=
name|pthread_self
argument_list|()
expr_stmt|;
name|has_owner_
operator|=
name|true
expr_stmt|;
block|}
comment|// Releases this mutex.
name|void
name|Unlock
parameter_list|()
block|{
comment|// Since the lock is being released the owner_ field should no longer be
comment|// considered valid. We don't protect writing to has_owner_ here, as it's
comment|// the caller's responsibility to ensure that the current thread holds the
comment|// mutex when this is called.
name|has_owner_
operator|=
name|false
expr_stmt|;
name|GTEST_CHECK_POSIX_SUCCESS_
argument_list|(
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mutex_
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Does nothing if the current thread holds the mutex. Otherwise, crashes
comment|// with high probability.
name|void
name|AssertHeld
argument_list|()
specifier|const
block|{
name|GTEST_CHECK_
argument_list|(
name|has_owner_
operator|&&
name|pthread_equal
argument_list|(
name|owner_
argument_list|,
name|pthread_self
argument_list|()
argument_list|)
argument_list|)
operator|<<
literal|"The current thread is not holding the mutex @"
operator|<<
name|this
block|;   }
comment|// A static mutex may be used before main() is entered.  It may even
comment|// be used before the dynamic initialization stage.  Therefore we
comment|// must be able to initialize a static mutex object at link time.
comment|// This means MutexBase has to be a POD and its member variables
comment|// have to be public.
name|public
operator|:
name|pthread_mutex_t
name|mutex_
expr_stmt|;
comment|// The underlying pthread mutex.
comment|// has_owner_ indicates whether the owner_ field below contains a valid thread
comment|// ID and is therefore safe to inspect (e.g., to use in pthread_equal()). All
comment|// accesses to the owner_ field should be protected by a check of this field.
comment|// An alternative might be to memset() owner_ to all zeros, but there's no
comment|// guarantee that a zero'd pthread_t is necessarily invalid or even different
comment|// from pthread_self().
name|bool
name|has_owner_
decl_stmt|;
name|pthread_t
name|owner_
decl_stmt|;
comment|// The thread holding the mutex.
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Forward-declares a static mutex.
end_comment

begin_define
define|#
directive|define
name|GTEST_DECLARE_STATIC_MUTEX_
parameter_list|(
name|mutex
parameter_list|)
define|\
value|extern ::testing::internal::MutexBase mutex
end_define

begin_comment
comment|// Defines and statically (i.e. at link time) initializes a static mutex.
end_comment

begin_define
define|#
directive|define
name|GTEST_DEFINE_STATIC_MUTEX_
parameter_list|(
name|mutex
parameter_list|)
define|\
value|::testing::internal::MutexBase mutex = { PTHREAD_MUTEX_INITIALIZER, false, pthread_t() }
end_define

begin_comment
comment|// The Mutex class can only be used for mutexes created at runtime. It
end_comment

begin_comment
comment|// shares its API with MutexBase otherwise.
end_comment

begin_decl_stmt
name|class
name|Mutex
range|:
name|public
name|MutexBase
block|{
name|public
operator|:
name|Mutex
argument_list|()
block|{
name|GTEST_CHECK_POSIX_SUCCESS_
argument_list|(
name|pthread_mutex_init
argument_list|(
operator|&
name|mutex_
argument_list|,
name|NULL
argument_list|)
argument_list|)
block|;
name|has_owner_
operator|=
name|false
block|;   }
operator|~
name|Mutex
argument_list|()
block|{
name|GTEST_CHECK_POSIX_SUCCESS_
argument_list|(
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mutex_
argument_list|)
argument_list|)
block|;   }
name|private
operator|:
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|Mutex
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|// We cannot name this class MutexLock because the ctor declaration would
end_comment

begin_comment
comment|// conflict with a macro named MutexLock, which is defined on some
end_comment

begin_comment
comment|// platforms. That macro is used as a defensive measure to prevent against
end_comment

begin_comment
comment|// inadvertent misuses of MutexLock like "MutexLock(&mu)" rather than
end_comment

begin_comment
comment|// "MutexLock l(&mu)".  Hence the typedef trick below.
end_comment

begin_decl_stmt
name|class
name|GTestMutexLock
block|{
name|public
label|:
name|explicit
name|GTestMutexLock
argument_list|(
name|MutexBase
operator|*
name|mutex
argument_list|)
operator|:
name|mutex_
argument_list|(
argument|mutex
argument_list|)
block|{
name|mutex_
operator|->
name|Lock
argument_list|()
block|; }
operator|~
name|GTestMutexLock
argument_list|()
block|{
name|mutex_
operator|->
name|Unlock
argument_list|()
block|; }
name|private
operator|:
name|MutexBase
operator|*
specifier|const
name|mutex_
expr_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|GTestMutexLock
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|GTestMutexLock
name|MutexLock
typedef|;
end_typedef

begin_comment
comment|// Helpers for ThreadLocal.
end_comment

begin_comment
comment|// pthread_key_create() requires DeleteThreadLocalValue() to have
end_comment

begin_comment
comment|// C-linkage.  Therefore it cannot be templatized to access
end_comment

begin_comment
comment|// ThreadLocal<T>.  Hence the need for class
end_comment

begin_comment
comment|// ThreadLocalValueHolderBase.
end_comment

begin_decl_stmt
name|class
name|ThreadLocalValueHolderBase
block|{
name|public
label|:
name|virtual
operator|~
name|ThreadLocalValueHolderBase
argument_list|()
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Called by pthread to delete thread-local data stored by
end_comment

begin_comment
comment|// pthread_setspecific().
end_comment

begin_extern
extern|extern
literal|"C"
specifier|inline
name|void
name|DeleteThreadLocalValue
parameter_list|(
name|void
modifier|*
name|value_holder
parameter_list|)
block|{
name|delete
name|static_cast
operator|<
name|ThreadLocalValueHolderBase
operator|*
operator|>
operator|(
name|value_holder
operator|)
expr_stmt|;
block|}
end_extern

begin_comment
comment|// Implements thread-local storage on pthreads-based systems.
end_comment

begin_expr_stmt
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
name|key_
argument_list|(
name|CreateKey
argument_list|()
argument_list|)
block|,
name|default_factory_
argument_list|(
argument|new DefaultValueHolderFactory()
argument_list|)
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
name|key_
argument_list|(
name|CreateKey
argument_list|()
argument_list|)
block|,
name|default_factory_
argument_list|(
argument|new InstanceValueHolderFactory(value)
argument_list|)
block|{}
operator|~
name|ThreadLocal
argument_list|()
block|{
comment|// Destroys the managed object for the current thread, if any.
name|DeleteThreadLocalValue
argument_list|(
name|pthread_getspecific
argument_list|(
name|key_
argument_list|)
argument_list|)
block|;
comment|// Releases resources associated with the key.  This will *not*
comment|// delete managed objects for other threads.
name|GTEST_CHECK_POSIX_SUCCESS_
argument_list|(
name|pthread_key_delete
argument_list|(
name|key_
argument_list|)
argument_list|)
block|;   }
name|T
operator|*
name|pointer
argument_list|()
block|{
return|return
name|GetOrCreateValue
argument_list|()
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
name|GetOrCreateValue
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|T
operator|&
name|get
argument_list|()
specifier|const
block|{
return|return
operator|*
name|pointer
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|void
name|set
parameter_list|(
specifier|const
name|T
modifier|&
name|value
parameter_list|)
block|{
operator|*
name|pointer
argument_list|()
operator|=
name|value
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_comment
comment|// Holds a value of type T.
end_comment

begin_decl_stmt
name|class
name|ValueHolder
range|:
name|public
name|ThreadLocalValueHolderBase
block|{
name|public
operator|:
name|ValueHolder
argument_list|()
operator|:
name|value_
argument_list|()
block|{}
name|explicit
name|ValueHolder
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
name|private
operator|:
name|T
name|value_
block|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ValueHolder
argument_list|)
block|;   }
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|pthread_key_t
name|CreateKey
parameter_list|()
block|{
name|pthread_key_t
name|key
decl_stmt|;
comment|// When a thread exits, DeleteThreadLocalValue() will be called on
comment|// the object managed for that thread.
name|GTEST_CHECK_POSIX_SUCCESS_
argument_list|(
name|pthread_key_create
argument_list|(
operator|&
name|key
argument_list|,
operator|&
name|DeleteThreadLocalValue
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|key
return|;
block|}
end_function

begin_expr_stmt
name|T
operator|*
name|GetOrCreateValue
argument_list|()
specifier|const
block|{
name|ThreadLocalValueHolderBase
operator|*
specifier|const
name|holder
operator|=
name|static_cast
operator|<
name|ThreadLocalValueHolderBase
operator|*
operator|>
operator|(
name|pthread_getspecific
argument_list|(
name|key_
argument_list|)
operator|)
block|;
if|if
condition|(
name|holder
operator|!=
name|NULL
condition|)
block|{
return|return
name|CheckedDowncastToActualType
operator|<
name|ValueHolder
operator|>
operator|(
name|holder
operator|)
operator|->
name|pointer
argument_list|()
return|;
block|}
name|ValueHolder
operator|*
specifier|const
name|new_holder
operator|=
name|default_factory_
operator|->
name|MakeNewHolder
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|ThreadLocalValueHolderBase
modifier|*
specifier|const
name|holder_base
init|=
name|new_holder
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_CHECK_POSIX_SUCCESS_
argument_list|(
name|pthread_setspecific
argument_list|(
name|key_
argument_list|,
name|holder_base
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|new_holder
operator|->
name|pointer
argument_list|()
return|;
end_return

begin_macro
unit|}    class
name|ValueHolderFactory
end_macro

begin_block
block|{
name|public
label|:
name|ValueHolderFactory
argument_list|()
block|{}
name|virtual
operator|~
name|ValueHolderFactory
argument_list|()
block|{}
name|virtual
name|ValueHolder
operator|*
name|MakeNewHolder
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|private
label|:
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ValueHolderFactory
argument_list|)
expr_stmt|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|DefaultValueHolderFactory
range|:
name|public
name|ValueHolderFactory
block|{
name|public
operator|:
name|DefaultValueHolderFactory
argument_list|()
block|{}
name|virtual
name|ValueHolder
operator|*
name|MakeNewHolder
argument_list|()
specifier|const
block|{
return|return
name|new
name|ValueHolder
argument_list|()
return|;
block|}
name|private
operator|:
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|DefaultValueHolderFactory
argument_list|)
block|;   }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|InstanceValueHolderFactory
range|:
name|public
name|ValueHolderFactory
block|{
name|public
operator|:
name|explicit
name|InstanceValueHolderFactory
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
name|virtual
name|ValueHolder
operator|*
name|MakeNewHolder
argument_list|()
specifier|const
block|{
return|return
name|new
name|ValueHolder
argument_list|(
name|value_
argument_list|)
return|;
block|}
name|private
operator|:
specifier|const
name|T
name|value_
block|;
comment|// The value for each thread.
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|InstanceValueHolderFactory
argument_list|)
block|;   }
decl_stmt|;
end_decl_stmt

begin_comment
comment|// A key pthreads uses for looking up per-thread values.
end_comment

begin_decl_stmt
specifier|const
name|pthread_key_t
name|key_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|scoped_ptr
operator|<
name|ValueHolderFactory
operator|>
name|default_factory_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ThreadLocal
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_MUTEX_AND_THREAD_LOCAL_
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// GTEST_IS_THREADSAFE
end_comment

begin_comment
comment|// A dummy implementation of synchronization primitives (mutex, lock,
end_comment

begin_comment
comment|// and thread-local variable).  Necessary for compiling Google Test where
end_comment

begin_comment
comment|// mutex is not supported - using Google Test in multiple threads is not
end_comment

begin_comment
comment|// supported on such platforms.
end_comment

begin_decl_stmt
name|class
name|Mutex
block|{
name|public
label|:
name|Mutex
argument_list|()
block|{}
name|void
name|Lock
parameter_list|()
block|{}
name|void
name|Unlock
parameter_list|()
block|{}
name|void
name|AssertHeld
argument_list|()
specifier|const
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|GTEST_DECLARE_STATIC_MUTEX_
parameter_list|(
name|mutex
parameter_list|)
define|\
value|extern ::testing::internal::Mutex mutex
end_define

begin_define
define|#
directive|define
name|GTEST_DEFINE_STATIC_MUTEX_
parameter_list|(
name|mutex
parameter_list|)
value|::testing::internal::Mutex mutex
end_define

begin_comment
comment|// We cannot name this class MutexLock because the ctor declaration would
end_comment

begin_comment
comment|// conflict with a macro named MutexLock, which is defined on some
end_comment

begin_comment
comment|// platforms. That macro is used as a defensive measure to prevent against
end_comment

begin_comment
comment|// inadvertent misuses of MutexLock like "MutexLock(&mu)" rather than
end_comment

begin_comment
comment|// "MutexLock l(&mu)".  Hence the typedef trick below.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|GTestMutexLock
name|MutexLock
typedef|;
end_typedef

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_function
name|void
name|set
parameter_list|(
specifier|const
name|T
modifier|&
name|value
parameter_list|)
block|{
name|value_
operator|=
name|value
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|T
name|value_
decl_stmt|;
end_decl_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_IS_THREADSAFE
end_comment

begin_comment
comment|// Returns the number of threads running in the process, or 0 to indicate that
end_comment

begin_comment
comment|// we cannot detect it.
end_comment

begin_function_decl
name|GTEST_API_
name|size_t
name|GetThreadCount
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Passing non-POD classes through ellipsis (...) crashes the ARM
end_comment

begin_comment
comment|// compiler and generates a warning in Sun Studio.  The Nokia Symbian
end_comment

begin_comment
comment|// and the IBM XL C/C++ compiler try to instantiate a copy constructor
end_comment

begin_comment
comment|// for objects passed through ellipsis (...), failing for uncopyable
end_comment

begin_comment
comment|// objects.  We define this to ensure that only POD is passed through
end_comment

begin_comment
comment|// ellipsis on these systems.
end_comment

begin_if
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
operator|||
name|defined
argument_list|(
name|__SUNPRO_CC
argument_list|)
end_if

begin_comment
comment|// We lose support for NULL detection where the compiler doesn't like
end_comment

begin_comment
comment|// passing non-POD classes through ellipsis (...).
end_comment

begin_define
define|#
directive|define
name|GTEST_ELLIPSIS_NEEDS_POD_
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_CAN_COMPARE_NULL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// The Nokia Symbian and IBM XL C/C++ compilers cannot decide between
end_comment

begin_comment
comment|// const T& and const T* in a function template.  These compilers
end_comment

begin_comment
comment|// _can_ decide between class template specializations for T and T*,
end_comment

begin_comment
comment|// so a tr1::type_traits-like is_pointer works.
end_comment

begin_if
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
end_if

begin_define
define|#
directive|define
name|GTEST_NEEDS_IS_POINTER_
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
unit|};
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

begin_expr_stmt
name|template
operator|<
name|typename
name|Iterator
operator|>
expr|struct
name|IteratorTraits
block|{
typedef|typedef
name|typename
name|Iterator
operator|::
name|value_type
name|value_type
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|IteratorTraits
operator|<
name|T
operator|*
operator|>
block|{
typedef|typedef
name|T
name|value_type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|IteratorTraits
operator|<
specifier|const
name|T
operator|*
operator|>
block|{
typedef|typedef
name|T
name|value_type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_if
if|#
directive|if
name|GTEST_OS_WINDOWS
end_if

begin_define
define|#
directive|define
name|GTEST_PATH_SEP_
value|"\\"
end_define

begin_define
define|#
directive|define
name|GTEST_HAS_ALT_PATH_SEP_
value|1
end_define

begin_comment
comment|// The biggest signed integer type the compiler supports.
end_comment

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

begin_define
define|#
directive|define
name|GTEST_PATH_SEP_
value|"/"
end_define

begin_define
define|#
directive|define
name|GTEST_HAS_ALT_PATH_SEP_
value|0
end_define

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
comment|// Utilities for char.
end_comment

begin_comment
comment|// isspace(int ch) and friends accept an unsigned char or EOF.  char
end_comment

begin_comment
comment|// may be signed, depending on the compiler (or compiler flags).
end_comment

begin_comment
comment|// Therefore we need to cast a char to unsigned char before calling
end_comment

begin_comment
comment|// isspace(), etc.
end_comment

begin_function
specifier|inline
name|bool
name|IsAlpha
parameter_list|(
name|char
name|ch
parameter_list|)
block|{
return|return
name|isalpha
argument_list|(
argument|static_cast<unsigned char>(ch)
argument_list|)
operator|!=
literal|0
return|;
block|}
end_function

begin_function
specifier|inline
name|bool
name|IsAlNum
parameter_list|(
name|char
name|ch
parameter_list|)
block|{
return|return
name|isalnum
argument_list|(
argument|static_cast<unsigned char>(ch)
argument_list|)
operator|!=
literal|0
return|;
block|}
end_function

begin_function
specifier|inline
name|bool
name|IsDigit
parameter_list|(
name|char
name|ch
parameter_list|)
block|{
return|return
name|isdigit
argument_list|(
argument|static_cast<unsigned char>(ch)
argument_list|)
operator|!=
literal|0
return|;
block|}
end_function

begin_function
specifier|inline
name|bool
name|IsLower
parameter_list|(
name|char
name|ch
parameter_list|)
block|{
return|return
name|islower
argument_list|(
argument|static_cast<unsigned char>(ch)
argument_list|)
operator|!=
literal|0
return|;
block|}
end_function

begin_function
specifier|inline
name|bool
name|IsSpace
parameter_list|(
name|char
name|ch
parameter_list|)
block|{
return|return
name|isspace
argument_list|(
argument|static_cast<unsigned char>(ch)
argument_list|)
operator|!=
literal|0
return|;
block|}
end_function

begin_function
specifier|inline
name|bool
name|IsUpper
parameter_list|(
name|char
name|ch
parameter_list|)
block|{
return|return
name|isupper
argument_list|(
argument|static_cast<unsigned char>(ch)
argument_list|)
operator|!=
literal|0
return|;
block|}
end_function

begin_function
specifier|inline
name|bool
name|IsXDigit
parameter_list|(
name|char
name|ch
parameter_list|)
block|{
return|return
name|isxdigit
argument_list|(
argument|static_cast<unsigned char>(ch)
argument_list|)
operator|!=
literal|0
return|;
block|}
end_function

begin_function
specifier|inline
name|bool
name|IsXDigit
parameter_list|(
name|wchar_t
name|ch
parameter_list|)
block|{
specifier|const
name|unsigned
name|char
name|low_byte
init|=
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
name|ch
operator|)
decl_stmt|;
return|return
name|ch
operator|==
name|low_byte
operator|&&
name|isxdigit
argument_list|(
name|low_byte
argument_list|)
operator|!=
literal|0
return|;
block|}
end_function

begin_function
specifier|inline
name|char
name|ToLower
parameter_list|(
name|char
name|ch
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|char
operator|>
operator|(
name|tolower
argument_list|(
argument|static_cast<unsigned char>(ch)
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|inline
name|char
name|ToUpper
parameter_list|(
name|char
name|ch
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|char
operator|>
operator|(
name|toupper
argument_list|(
argument|static_cast<unsigned char>(ch)
argument_list|)
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|inline
name|std
operator|::
name|string
name|StripTrailingSpaces
argument_list|(
argument|std::string str
argument_list|)
block|{
name|std
operator|::
name|string
operator|::
name|iterator
name|it
operator|=
name|str
operator|.
name|end
argument_list|()
block|;
while|while
condition|(
name|it
operator|!=
name|str
operator|.
name|begin
argument_list|()
operator|&&
name|IsSpace
argument_list|(
operator|*
operator|--
name|it
argument_list|)
condition|)
name|it
operator|=
name|str
operator|.
name|erase
argument_list|(
name|it
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|str
return|;
end_return

begin_comment
unit|}
comment|// The testing::internal::posix namespace holds wrappers for common
end_comment

begin_comment
comment|// POSIX functions.  These wrappers hide the differences between
end_comment

begin_comment
comment|// Windows/MSVC and POSIX systems.  Since some compilers define these
end_comment

begin_comment
comment|// standard functions as macros, the wrapper cannot have the same name
end_comment

begin_comment
comment|// as the wrapped function.
end_comment

begin_macro
unit|namespace
name|posix
end_macro

begin_block
block|{
comment|// Functions with a different name on Windows.
if|#
directive|if
name|GTEST_OS_WINDOWS
typedef|typedef
name|struct
name|_stat
name|StatStruct
typedef|;
ifdef|#
directive|ifdef
name|__BORLANDC__
specifier|inline
name|int
name|IsATTY
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
return|return
name|isatty
argument_list|(
name|fd
argument_list|)
return|;
block|}
specifier|inline
name|int
name|StrCaseCmp
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
block|{
return|return
name|stricmp
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|)
return|;
block|}
specifier|inline
name|char
modifier|*
name|StrDup
parameter_list|(
specifier|const
name|char
modifier|*
name|src
parameter_list|)
block|{
return|return
name|strdup
argument_list|(
name|src
argument_list|)
return|;
block|}
else|#
directive|else
comment|// !__BORLANDC__
if|#
directive|if
name|GTEST_OS_WINDOWS_MOBILE
specifier|inline
name|int
name|IsATTY
parameter_list|(
name|int
comment|/* fd */
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
else|#
directive|else
specifier|inline
name|int
name|IsATTY
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
return|return
name|_isatty
argument_list|(
name|fd
argument_list|)
return|;
block|}
endif|#
directive|endif
comment|// GTEST_OS_WINDOWS_MOBILE
specifier|inline
name|int
name|StrCaseCmp
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
block|{
return|return
name|_stricmp
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|)
return|;
block|}
specifier|inline
name|char
modifier|*
name|StrDup
parameter_list|(
specifier|const
name|char
modifier|*
name|src
parameter_list|)
block|{
return|return
name|_strdup
argument_list|(
name|src
argument_list|)
return|;
block|}
endif|#
directive|endif
comment|// __BORLANDC__
if|#
directive|if
name|GTEST_OS_WINDOWS_MOBILE
specifier|inline
name|int
name|FileNo
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|int
operator|>
operator|(
name|_fileno
argument_list|(
name|file
argument_list|)
operator|)
return|;
block|}
comment|// Stat(), RmDir(), and IsDir() are not needed on Windows CE at this
comment|// time and thus not defined there.
else|#
directive|else
specifier|inline
name|int
name|FileNo
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|)
block|{
return|return
name|_fileno
argument_list|(
name|file
argument_list|)
return|;
block|}
specifier|inline
name|int
name|Stat
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|StatStruct
modifier|*
name|buf
parameter_list|)
block|{
return|return
name|_stat
argument_list|(
name|path
argument_list|,
name|buf
argument_list|)
return|;
block|}
specifier|inline
name|int
name|RmDir
parameter_list|(
specifier|const
name|char
modifier|*
name|dir
parameter_list|)
block|{
return|return
name|_rmdir
argument_list|(
name|dir
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|IsDir
parameter_list|(
specifier|const
name|StatStruct
modifier|&
name|st
parameter_list|)
block|{
return|return
operator|(
name|_S_IFDIR
operator|&
name|st
operator|.
name|st_mode
operator|)
operator|!=
literal|0
return|;
block|}
endif|#
directive|endif
comment|// GTEST_OS_WINDOWS_MOBILE
else|#
directive|else
typedef|typedef
name|struct
name|stat
name|StatStruct
typedef|;
specifier|inline
name|int
name|FileNo
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|)
block|{
return|return
name|fileno
argument_list|(
name|file
argument_list|)
return|;
block|}
specifier|inline
name|int
name|IsATTY
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
return|return
name|isatty
argument_list|(
name|fd
argument_list|)
return|;
block|}
specifier|inline
name|int
name|Stat
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|StatStruct
modifier|*
name|buf
parameter_list|)
block|{
return|return
name|stat
argument_list|(
name|path
argument_list|,
name|buf
argument_list|)
return|;
block|}
specifier|inline
name|int
name|StrCaseCmp
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
block|{
return|return
name|strcasecmp
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|)
return|;
block|}
specifier|inline
name|char
modifier|*
name|StrDup
parameter_list|(
specifier|const
name|char
modifier|*
name|src
parameter_list|)
block|{
return|return
name|strdup
argument_list|(
name|src
argument_list|)
return|;
block|}
specifier|inline
name|int
name|RmDir
parameter_list|(
specifier|const
name|char
modifier|*
name|dir
parameter_list|)
block|{
return|return
name|rmdir
argument_list|(
name|dir
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|IsDir
parameter_list|(
specifier|const
name|StatStruct
modifier|&
name|st
parameter_list|)
block|{
return|return
name|S_ISDIR
argument_list|(
name|st
operator|.
name|st_mode
argument_list|)
return|;
block|}
endif|#
directive|endif
comment|// GTEST_OS_WINDOWS
comment|// Functions deprecated by MSVC 8.0.
name|GTEST_DISABLE_MSC_WARNINGS_PUSH_
argument_list|(
literal|4996
comment|/* deprecated function */
argument_list|)
specifier|inline
specifier|const
name|char
modifier|*
name|StrNCpy
parameter_list|(
name|char
modifier|*
name|dest
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
return|return
name|strncpy
argument_list|(
name|dest
argument_list|,
name|src
argument_list|,
name|n
argument_list|)
return|;
block|}
comment|// ChDir(), FReopen(), FDOpen(), Read(), Write(), Close(), and
comment|// StrError() aren't needed on Windows CE at this time and thus not
comment|// defined there.
if|#
directive|if
operator|!
name|GTEST_OS_WINDOWS_MOBILE
operator|&&
operator|!
name|GTEST_OS_WINDOWS_PHONE
operator|&&
operator|!
name|GTEST_OS_WINDOWS_RT
specifier|inline
name|int
name|ChDir
parameter_list|(
specifier|const
name|char
modifier|*
name|dir
parameter_list|)
block|{
return|return
name|chdir
argument_list|(
name|dir
argument_list|)
return|;
block|}
endif|#
directive|endif
specifier|inline
name|FILE
modifier|*
name|FOpen
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|mode
parameter_list|)
block|{
return|return
name|fopen
argument_list|(
name|path
argument_list|,
name|mode
argument_list|)
return|;
block|}
if|#
directive|if
operator|!
name|GTEST_OS_WINDOWS_MOBILE
specifier|inline
name|FILE
modifier|*
name|FReopen
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|mode
parameter_list|,
name|FILE
modifier|*
name|stream
parameter_list|)
block|{
return|return
name|freopen
argument_list|(
name|path
argument_list|,
name|mode
argument_list|,
name|stream
argument_list|)
return|;
block|}
specifier|inline
name|FILE
modifier|*
name|FDOpen
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
name|mode
parameter_list|)
block|{
return|return
name|fdopen
argument_list|(
name|fd
argument_list|,
name|mode
argument_list|)
return|;
block|}
endif|#
directive|endif
specifier|inline
name|int
name|FClose
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|)
block|{
return|return
name|fclose
argument_list|(
name|fp
argument_list|)
return|;
block|}
if|#
directive|if
operator|!
name|GTEST_OS_WINDOWS_MOBILE
specifier|inline
name|int
name|Read
parameter_list|(
name|int
name|fd
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|unsigned
name|int
name|count
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|read
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
name|count
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|int
name|Write
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|unsigned
name|int
name|count
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|write
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
name|count
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|int
name|Close
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
return|return
name|close
argument_list|(
name|fd
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|char
modifier|*
name|StrError
parameter_list|(
name|int
name|errnum
parameter_list|)
block|{
return|return
name|strerror
argument_list|(
name|errnum
argument_list|)
return|;
block|}
endif|#
directive|endif
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
if|#
directive|if
name|GTEST_OS_WINDOWS_MOBILE
operator|||
name|GTEST_OS_WINDOWS_PHONE
operator||
name|GTEST_OS_WINDOWS_RT
comment|// We are on Windows CE, which has no environment variables.
name|static_cast
operator|<
name|void
operator|>
operator|(
name|name
operator|)
expr_stmt|;
comment|// To prevent 'unused argument' warning.
return|return
name|NULL
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__SunOS_5_8
argument_list|)
operator|||
name|defined
argument_list|(
name|__SunOS_5_9
argument_list|)
comment|// Environment variables which we programmatically clear will be set to the
comment|// empty string rather than unset (NULL).  Handle that case.
specifier|const
name|char
modifier|*
specifier|const
name|env
init|=
name|getenv
argument_list|(
name|name
argument_list|)
decl_stmt|;
return|return
operator|(
name|env
operator|!=
name|NULL
operator|&&
name|env
index|[
literal|0
index|]
operator|!=
literal|'\0'
operator|)
condition|?
name|env
else|:
name|NULL
return|;
else|#
directive|else
return|return
name|getenv
argument_list|(
name|name
argument_list|)
return|;
endif|#
directive|endif
block|}
name|GTEST_DISABLE_MSC_WARNINGS_POP_
argument_list|()
if|#
directive|if
name|GTEST_OS_WINDOWS_MOBILE
comment|// Windows CE has no C library. The abort() function is used in
comment|// several places in Google Test. This implementation provides a reasonable
comment|// imitation of standard behaviour.
name|void
name|Abort
parameter_list|()
function_decl|;
else|#
directive|else
specifier|inline
name|void
name|Abort
parameter_list|()
block|{
name|abort
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
comment|// GTEST_OS_WINDOWS_MOBILE
block|}
end_block

begin_comment
comment|// namespace posix
end_comment

begin_comment
comment|// MSVC "deprecates" snprintf and issues warnings wherever it is used.  In
end_comment

begin_comment
comment|// order to avoid these warnings, we need to use _snprintf or _snprintf_s on
end_comment

begin_comment
comment|// MSVC-based platforms.  We map the GTEST_SNPRINTF_ macro to the appropriate
end_comment

begin_comment
comment|// function in order to achieve that.  We use macro definition here because
end_comment

begin_comment
comment|// snprintf is a variadic function.
end_comment

begin_if
if|#
directive|if
name|_MSC_VER
operator|>=
literal|1400
operator|&&
operator|!
name|GTEST_OS_WINDOWS_MOBILE
end_if

begin_comment
comment|// MSVC 2005 and above support variadic macros.
end_comment

begin_define
define|#
directive|define
name|GTEST_SNPRINTF_
parameter_list|(
name|buffer
parameter_list|,
name|size
parameter_list|,
name|format
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_snprintf_s(buffer, size, size, format, __VA_ARGS__)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_comment
comment|// Windows CE does not define _snprintf_s and MSVC prior to 2005 doesn't
end_comment

begin_comment
comment|// complain about _snprintf.
end_comment

begin_define
define|#
directive|define
name|GTEST_SNPRINTF_
value|_snprintf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GTEST_SNPRINTF_
value|snprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

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
if|#
directive|if
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
comment|// Macro for referencing flags.
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GTEST_FLAG
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_FLAG
parameter_list|(
name|name
parameter_list|)
value|FLAGS_gtest_##name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GTEST_FLAG)
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GTEST_USE_OWN_FLAGFILE_FLAG_
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_USE_OWN_FLAGFILE_FLAG_
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GTEST_USE_OWN_FLAGFILE_FLAG_)
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GTEST_DECLARE_bool_
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_FLAG_SAVER_
value|::testing::internal::GTestFlagSaver
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
value|GTEST_API_ extern bool GTEST_FLAG(name)
end_define

begin_define
define|#
directive|define
name|GTEST_DECLARE_int32_
parameter_list|(
name|name
parameter_list|)
define|\
value|GTEST_API_ extern ::testing::internal::Int32 GTEST_FLAG(name)
end_define

begin_define
define|#
directive|define
name|GTEST_DECLARE_string_
parameter_list|(
name|name
parameter_list|)
define|\
value|GTEST_API_ extern ::std::string GTEST_FLAG(name)
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
value|GTEST_API_ bool GTEST_FLAG(name) = (default_val)
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
value|GTEST_API_ ::testing::internal::Int32 GTEST_FLAG(name) = (default_val)
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
value|GTEST_API_ ::std::string GTEST_FLAG(name) = (default_val)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GTEST_DECLARE_bool_)
end_comment

begin_comment
comment|// Thread annotations
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GTEST_EXCLUSIVE_LOCK_REQUIRED_
argument_list|)
end_if

begin_define
define|#
directive|define
name|GTEST_EXCLUSIVE_LOCK_REQUIRED_
parameter_list|(
name|locks
parameter_list|)
end_define

begin_define
define|#
directive|define
name|GTEST_LOCK_EXCLUDED_
parameter_list|(
name|locks
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GTEST_EXCLUSIVE_LOCK_REQUIRED_)
end_comment

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
name|GTEST_API_
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

begin_expr_stmt
name|std
operator|::
name|string
name|StringFromGTestEnv
argument_list|(
specifier|const
name|char
operator|*
name|flag
argument_list|,
specifier|const
name|char
operator|*
name|default_val
argument_list|)
expr_stmt|;
end_expr_stmt

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

