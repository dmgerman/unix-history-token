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
comment|// Authors: wan@google.com (Zhanyong Wan), eefacm@gmail.com (Sean Mcafee)
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
comment|// This header file declares the String class and functions used internally by
end_comment

begin_comment
comment|// Google Test.  They are subject to change without notice. They should not used
end_comment

begin_comment
comment|// by code external to Google Test.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This header file is #included by<gtest/internal/gtest-internal.h>.
end_comment

begin_comment
comment|// It should not be #included by other files.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_INCLUDE_GTEST_INTERNAL_GTEST_STRING_H_
end_ifndef

begin_define
define|#
directive|define
name|GTEST_INCLUDE_GTEST_INTERNAL_GTEST_STRING_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__BORLANDC__
end_ifdef

begin_comment
comment|// string.h is not guaranteed to provide strcpy on C++ Builder.
end_comment

begin_include
include|#
directive|include
file|<mem.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"gtest/internal/gtest-port.h"
end_include

begin_decl_stmt
name|namespace
name|testing
block|{
name|namespace
name|internal
block|{
comment|// String - an abstract class holding static string utilities.
name|class
name|GTEST_API_
name|String
block|{
name|public
label|:
comment|// Static utility methods
comment|// Clones a 0-terminated C string, allocating memory using new.  The
comment|// caller is responsible for deleting the return value using
comment|// delete[].  Returns the cloned string, or NULL if the input is
comment|// NULL.
comment|//
comment|// This is different from strdup() in string.h, which allocates
comment|// memory using malloc().
specifier|static
specifier|const
name|char
modifier|*
name|CloneCString
parameter_list|(
specifier|const
name|char
modifier|*
name|c_str
parameter_list|)
function_decl|;
if|#
directive|if
name|GTEST_OS_WINDOWS_MOBILE
comment|// Windows CE does not have the 'ANSI' versions of Win32 APIs. To be
comment|// able to pass strings to Win32 APIs on CE we need to convert them
comment|// to 'Unicode', UTF-16.
comment|// Creates a UTF-16 wide string from the given ANSI string, allocating
comment|// memory using new. The caller is responsible for deleting the return
comment|// value using delete[]. Returns the wide string, or NULL if the
comment|// input is NULL.
comment|//
comment|// The wide string is created using the ANSI codepage (CP_ACP) to
comment|// match the behaviour of the ANSI versions of Win32 calls and the
comment|// C runtime.
specifier|static
name|LPCWSTR
name|AnsiToUtf16
parameter_list|(
specifier|const
name|char
modifier|*
name|c_str
parameter_list|)
function_decl|;
comment|// Creates an ANSI string from the given wide string, allocating
comment|// memory using new. The caller is responsible for deleting the return
comment|// value using delete[]. Returns the ANSI string, or NULL if the
comment|// input is NULL.
comment|//
comment|// The returned string is created using the ANSI codepage (CP_ACP) to
comment|// match the behaviour of the ANSI versions of Win32 calls and the
comment|// C runtime.
specifier|static
specifier|const
name|char
modifier|*
name|Utf16ToAnsi
parameter_list|(
name|LPCWSTR
name|utf16_str
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// Compares two C strings.  Returns true iff they have the same content.
comment|//
comment|// Unlike strcmp(), this function can handle NULL argument(s).  A
comment|// NULL C string is considered different to any non-NULL C string,
comment|// including the empty string.
specifier|static
name|bool
name|CStringEquals
parameter_list|(
specifier|const
name|char
modifier|*
name|lhs
parameter_list|,
specifier|const
name|char
modifier|*
name|rhs
parameter_list|)
function_decl|;
comment|// Converts a wide C string to a String using the UTF-8 encoding.
comment|// NULL will be converted to "(null)".  If an error occurred during
comment|// the conversion, "(failed to convert from wide string)" is
comment|// returned.
specifier|static
name|std
operator|::
name|string
name|ShowWideCString
argument_list|(
specifier|const
name|wchar_t
operator|*
name|wide_c_str
argument_list|)
expr_stmt|;
comment|// Compares two wide C strings.  Returns true iff they have the same
comment|// content.
comment|//
comment|// Unlike wcscmp(), this function can handle NULL argument(s).  A
comment|// NULL C string is considered different to any non-NULL C string,
comment|// including the empty string.
specifier|static
name|bool
name|WideCStringEquals
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|lhs
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|rhs
parameter_list|)
function_decl|;
comment|// Compares two C strings, ignoring case.  Returns true iff they
comment|// have the same content.
comment|//
comment|// Unlike strcasecmp(), this function can handle NULL argument(s).
comment|// A NULL C string is considered different to any non-NULL C string,
comment|// including the empty string.
specifier|static
name|bool
name|CaseInsensitiveCStringEquals
parameter_list|(
specifier|const
name|char
modifier|*
name|lhs
parameter_list|,
specifier|const
name|char
modifier|*
name|rhs
parameter_list|)
function_decl|;
comment|// Compares two wide C strings, ignoring case.  Returns true iff they
comment|// have the same content.
comment|//
comment|// Unlike wcscasecmp(), this function can handle NULL argument(s).
comment|// A NULL C string is considered different to any non-NULL wide C string,
comment|// including the empty string.
comment|// NB: The implementations on different platforms slightly differ.
comment|// On windows, this method uses _wcsicmp which compares according to LC_CTYPE
comment|// environment variable. On GNU platform this method uses wcscasecmp
comment|// which compares according to LC_CTYPE category of the current locale.
comment|// On MacOS X, it uses towlower, which also uses LC_CTYPE category of the
comment|// current locale.
specifier|static
name|bool
name|CaseInsensitiveWideCStringEquals
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|lhs
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|rhs
parameter_list|)
function_decl|;
comment|// Returns true iff the given string ends with the given suffix, ignoring
comment|// case. Any string is considered to end with an empty suffix.
specifier|static
name|bool
name|EndsWithCaseInsensitive
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|str
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|suffix
argument_list|)
decl_stmt|;
comment|// Formats an int value as "%02d".
specifier|static
name|std
operator|::
name|string
name|FormatIntWidth2
argument_list|(
argument|int value
argument_list|)
expr_stmt|;
comment|// "%02d" for width == 2
comment|// Formats an int value as "%X".
specifier|static
name|std
operator|::
name|string
name|FormatHexInt
argument_list|(
argument|int value
argument_list|)
expr_stmt|;
comment|// Formats a byte as "%02X".
specifier|static
name|std
operator|::
name|string
name|FormatByte
argument_list|(
argument|unsigned char value
argument_list|)
expr_stmt|;
name|private
label|:
name|String
argument_list|()
expr_stmt|;
comment|// Not meant to be instantiated.
block|}
empty_stmt|;
comment|// class String
comment|// Gets the content of the stringstream's buffer as an std::string.  Each '\0'
comment|// character in the buffer is replaced with "\\0".
name|GTEST_API_
name|std
operator|::
name|string
name|StringStreamToString
argument_list|(
operator|::
name|std
operator|::
name|stringstream
operator|*
name|stream
argument_list|)
expr_stmt|;
block|}
comment|// namespace internal
block|}
end_decl_stmt

begin_comment
comment|// namespace testing
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_INCLUDE_GTEST_INTERNAL_GTEST_STRING_H_
end_comment

end_unit

