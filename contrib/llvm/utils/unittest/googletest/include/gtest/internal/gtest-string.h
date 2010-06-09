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
comment|// This header file is #included by testing/base/internal/gtest-internal.h.
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

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<gtest/internal/gtest-port.h>
end_include

begin_if
if|#
directive|if
name|GTEST_HAS_GLOBAL_STRING
operator|||
name|GTEST_HAS_STD_STRING
end_if

begin_include
include|#
directive|include
file|<string>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_GLOBAL_STRING || GTEST_HAS_STD_STRING
end_comment

begin_decl_stmt
name|namespace
name|testing
block|{
name|namespace
name|internal
block|{
comment|// String - a UTF-8 string class.
comment|//
comment|// We cannot use std::string as Microsoft's STL implementation in
comment|// Visual C++ 7.1 has problems when exception is disabled.  There is a
comment|// hack to work around this, but we've seen cases where the hack fails
comment|// to work.
comment|//
comment|// Also, String is different from std::string in that it can represent
comment|// both NULL and the empty string, while std::string cannot represent
comment|// NULL.
comment|//
comment|// NULL and the empty string are considered different.  NULL is less
comment|// than anything (including the empty string) except itself.
comment|//
comment|// This class only provides minimum functionality necessary for
comment|// implementing Google Test.  We do not intend to implement a full-fledged
comment|// string class here.
comment|//
comment|// Since the purpose of this class is to provide a substitute for
comment|// std::string on platforms where it cannot be used, we define a copy
comment|// constructor and assignment operators such that we don't need
comment|// conditional compilation in a lot of places.
comment|//
comment|// In order to make the representation efficient, the d'tor of String
comment|// is not virtual.  Therefore DO NOT INHERIT FROM String.
name|class
name|String
block|{
name|public
label|:
comment|// Static utility methods
comment|// Returns the input if it's not NULL, otherwise returns "(null)".
comment|// This function serves two purposes:
comment|//
comment|// 1. ShowCString(NULL) has type 'const char *', instead of the
comment|// type of NULL (which is int).
comment|//
comment|// 2. In MSVC, streaming a null char pointer to StrStream generates
comment|// an access violation, so we need to convert NULL to "(null)"
comment|// before streaming it.
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|ShowCString
parameter_list|(
specifier|const
name|char
modifier|*
name|c_str
parameter_list|)
block|{
return|return
name|c_str
condition|?
name|c_str
else|:
literal|"(null)"
return|;
block|}
comment|// Returns the input enclosed in double quotes if it's not NULL;
comment|// otherwise returns "(null)".  For example, "\"Hello\"" is returned
comment|// for input "Hello".
comment|//
comment|// This is useful for printing a C string in the syntax of a literal.
comment|//
comment|// Known issue: escape sequences are not handled yet.
specifier|static
name|String
name|ShowCStringQuoted
parameter_list|(
specifier|const
name|char
modifier|*
name|c_str
parameter_list|)
function_decl|;
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
ifdef|#
directive|ifdef
name|_WIN32_WCE
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
name|String
name|ShowWideCString
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|wide_c_str
parameter_list|)
function_decl|;
comment|// Similar to ShowWideCString(), except that this function encloses
comment|// the converted string in double quotes.
specifier|static
name|String
name|ShowWideCStringQuoted
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|wide_c_str
parameter_list|)
function_decl|;
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
comment|// Formats a list of arguments to a String, using the same format
comment|// spec string as for printf.
comment|//
comment|// We do not use the StringPrintf class as it is not universally
comment|// available.
comment|//
comment|// The result is limited to 4096 characters (including the tailing
comment|// 0).  If 4096 characters are not enough to format the input,
comment|// "<buffer exceeded>" is returned.
specifier|static
name|String
name|Format
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
comment|// C'tors
comment|// The default c'tor constructs a NULL string.
name|String
argument_list|()
operator|:
name|c_str_
argument_list|(
argument|NULL
argument_list|)
block|{}
comment|// Constructs a String by cloning a 0-terminated C string.
name|String
argument_list|(
specifier|const
name|char
operator|*
name|c_str
argument_list|)
operator|:
name|c_str_
argument_list|(
argument|NULL
argument_list|)
block|{
comment|// NOLINT
operator|*
name|this
operator|=
name|c_str
block|;   }
comment|// Constructs a String by copying a given number of chars from a
comment|// buffer.  E.g. String("hello", 3) will create the string "hel".
name|String
argument_list|(
argument|const char* buffer
argument_list|,
argument|size_t len
argument_list|)
expr_stmt|;
comment|// The copy c'tor creates a new copy of the string.  The two
comment|// String objects do not share content.
name|String
argument_list|(
specifier|const
name|String
operator|&
name|str
argument_list|)
operator|:
name|c_str_
argument_list|(
argument|NULL
argument_list|)
block|{
operator|*
name|this
operator|=
name|str
block|;   }
comment|// D'tor.  String is intended to be a final class, so the d'tor
comment|// doesn't need to be virtual.
operator|~
name|String
argument_list|()
block|{
name|delete
index|[]
name|c_str_
block|; }
comment|// Allows a String to be implicitly converted to an ::std::string or
comment|// ::string, and vice versa.  Converting a String containing a NULL
comment|// pointer to ::std::string or ::string is undefined behavior.
comment|// Converting a ::std::string or ::string containing an embedded NUL
comment|// character to a String will result in the prefix up to the first
comment|// NUL character.
if|#
directive|if
name|GTEST_HAS_STD_STRING
name|String
argument_list|(
specifier|const
operator|::
name|std
operator|::
name|string
operator|&
name|str
argument_list|)
operator|:
name|c_str_
argument_list|(
argument|NULL
argument_list|)
block|{
operator|*
name|this
operator|=
name|str
operator|.
name|c_str
argument_list|()
block|; }
name|operator
operator|::
name|std
operator|::
name|string
argument_list|()
specifier|const
block|{
return|return
operator|::
name|std
operator|::
name|string
argument_list|(
name|c_str_
argument_list|)
return|;
block|}
endif|#
directive|endif
comment|// GTEST_HAS_STD_STRING
if|#
directive|if
name|GTEST_HAS_GLOBAL_STRING
name|String
argument_list|(
specifier|const
operator|::
name|string
operator|&
name|str
argument_list|)
operator|:
name|c_str_
argument_list|(
argument|NULL
argument_list|)
block|{
operator|*
name|this
operator|=
name|str
operator|.
name|c_str
argument_list|()
block|; }
name|operator
operator|::
name|string
argument_list|()
specifier|const
block|{
return|return
operator|::
name|string
argument_list|(
name|c_str_
argument_list|)
return|;
block|}
endif|#
directive|endif
comment|// GTEST_HAS_GLOBAL_STRING
comment|// Returns true iff this is an empty string (i.e. "").
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
operator|(
name|c_str_
operator|!=
name|NULL
operator|)
operator|&&
operator|(
operator|*
name|c_str_
operator|==
literal|'\0'
operator|)
return|;
block|}
comment|// Compares this with another String.
comment|// Returns< 0 if this is less than rhs, 0 if this is equal to rhs, or> 0
comment|// if this is greater than rhs.
name|int
name|Compare
argument_list|(
specifier|const
name|String
operator|&
name|rhs
argument_list|)
decl|const
decl_stmt|;
comment|// Returns true iff this String equals the given C string.  A NULL
comment|// string and a non-NULL string are considered not equal.
name|bool
name|operator
operator|==
operator|(
specifier|const
name|char
operator|*
name|c_str
operator|)
specifier|const
block|{
return|return
name|CStringEquals
argument_list|(
name|c_str_
argument_list|,
name|c_str
argument_list|)
return|;
block|}
comment|// Returns true iff this String is less than the given C string.  A NULL
comment|// string is considered less than "".
name|bool
name|operator
operator|<
operator|(
specifier|const
name|String
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
name|Compare
argument_list|(
name|rhs
argument_list|)
operator|<
literal|0
return|;
block|}
comment|// Returns true iff this String doesn't equal the given C string.  A NULL
comment|// string and a non-NULL string are considered not equal.
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|char
operator|*
name|c_str
operator|)
specifier|const
block|{
return|return
operator|!
name|CStringEquals
argument_list|(
name|c_str_
argument_list|,
name|c_str
argument_list|)
return|;
block|}
comment|// Returns true iff this String ends with the given suffix.  *Any*
comment|// String is considered to end with a NULL or empty suffix.
name|bool
name|EndsWith
argument_list|(
specifier|const
name|char
operator|*
name|suffix
argument_list|)
decl|const
decl_stmt|;
comment|// Returns true iff this String ends with the given suffix, not considering
comment|// case. Any String is considered to end with a NULL or empty suffix.
name|bool
name|EndsWithCaseInsensitive
argument_list|(
specifier|const
name|char
operator|*
name|suffix
argument_list|)
decl|const
decl_stmt|;
comment|// Returns the length of the encapsulated string, or -1 if the
comment|// string is NULL.
name|int
name|GetLength
argument_list|()
specifier|const
block|{
return|return
name|c_str_
operator|?
name|static_cast
operator|<
name|int
operator|>
operator|(
name|strlen
argument_list|(
name|c_str_
argument_list|)
operator|)
operator|:
operator|-
literal|1
return|;
block|}
comment|// Gets the 0-terminated C string this String object represents.
comment|// The String object still owns the string.  Therefore the caller
comment|// should NOT delete the return value.
specifier|const
name|char
operator|*
name|c_str
argument_list|()
specifier|const
block|{
return|return
name|c_str_
return|;
block|}
comment|// Sets the 0-terminated C string this String object represents.
comment|// The old string in this object is deleted, and this object will
comment|// own a clone of the input string.  This function copies only up to
comment|// length bytes (plus a terminating null byte), or until the first
comment|// null byte, whichever comes first.
comment|//
comment|// This function works even when the c_str parameter has the same
comment|// value as that of the c_str_ field.
name|void
name|Set
parameter_list|(
specifier|const
name|char
modifier|*
name|c_str
parameter_list|,
name|size_t
name|length
parameter_list|)
function_decl|;
comment|// Assigns a C string to this object.  Self-assignment works.
specifier|const
name|String
modifier|&
name|operator
init|=
operator|(
specifier|const
name|char
operator|*
name|c_str
operator|)
decl_stmt|;
comment|// Assigns a String object to this object.  Self-assignment works.
specifier|const
name|String
modifier|&
name|operator
init|=
operator|(
specifier|const
name|String
operator|&
name|rhs
operator|)
block|{
operator|*
name|this
operator|=
name|rhs
operator|.
name|c_str_
block|;
return|return
operator|*
name|this
return|;
block|}
name|private
label|:
specifier|const
name|char
modifier|*
name|c_str_
decl_stmt|;
block|}
empty_stmt|;
comment|// Streams a String to an ostream.
specifier|inline
operator|::
name|std
operator|::
name|ostream
operator|&
name|operator
operator|<<
operator|(
operator|::
name|std
operator|::
name|ostream
operator|&
name|os
operator|,
specifier|const
name|String
operator|&
name|str
operator|)
block|{
comment|// We call String::ShowCString() to convert NULL to "(null)".
comment|// Otherwise we'll get an access violation on Windows.
return|return
name|os
operator|<<
name|String
operator|::
name|ShowCString
argument_list|(
name|str
operator|.
name|c_str
argument_list|()
argument_list|)
return|;
block|}
comment|// Gets the content of the StrStream's buffer as a String.  Each '\0'
comment|// character in the buffer is replaced with "\\0".
name|String
name|StrStreamToString
parameter_list|(
name|StrStream
modifier|*
name|stream
parameter_list|)
function_decl|;
comment|// Converts a streamable value to a String.  A NULL pointer is
comment|// converted to "(null)".  When the input value is a ::string,
comment|// ::std::string, ::wstring, or ::std::wstring object, each NUL
comment|// character in it is replaced with "\\0".
comment|// Declared here but defined in gtest.h, so that it has access
comment|// to the definition of the Message class, required by the ARM
comment|// compiler.
name|template
operator|<
name|typename
name|T
operator|>
name|String
name|StreamableToString
argument_list|(
specifier|const
name|T
operator|&
name|streamable
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

