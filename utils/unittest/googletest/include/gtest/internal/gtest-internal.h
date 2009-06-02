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
comment|// This header file declares functions and macros used internally by
end_comment

begin_comment
comment|// Google Test.  They are subject to change without notice.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_INCLUDE_GTEST_INTERNAL_GTEST_INTERNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|GTEST_INCLUDE_GTEST_INTERNAL_GTEST_INTERNAL_H_
end_define

begin_include
include|#
directive|include
file|<gtest/internal/gtest-port.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|GTEST_OS_LINUX
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_OS_LINUX
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<iomanip>
end_include

begin_include
include|#
directive|include
file|<limits>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|<gtest/internal/gtest-string.h>
end_include

begin_include
include|#
directive|include
file|<gtest/internal/gtest-filepath.h>
end_include

begin_include
include|#
directive|include
file|<gtest/internal/gtest-type-util.h>
end_include

begin_comment
comment|// Due to C++ preprocessor weirdness, we need double indirection to
end_comment

begin_comment
comment|// concatenate two tokens when one of them is __LINE__.  Writing
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   foo ## __LINE__
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// will result in the token foo__LINE__, instead of foo followed by
end_comment

begin_comment
comment|// the current line number.  For more details, see
end_comment

begin_comment
comment|// http://www.parashift.com/c++-faq-lite/misc-technical-issues.html#faq-39.6
end_comment

begin_define
define|#
directive|define
name|GTEST_CONCAT_TOKEN_
parameter_list|(
name|foo
parameter_list|,
name|bar
parameter_list|)
value|GTEST_CONCAT_TOKEN_IMPL_(foo, bar)
end_define

begin_define
define|#
directive|define
name|GTEST_CONCAT_TOKEN_IMPL_
parameter_list|(
name|foo
parameter_list|,
name|bar
parameter_list|)
value|foo ## bar
end_define

begin_comment
comment|// Google Test defines the testing::Message class to allow construction of
end_comment

begin_comment
comment|// test messages via the<< operator.  The idea is that anything
end_comment

begin_comment
comment|// streamable to std::ostream can be streamed to a testing::Message.
end_comment

begin_comment
comment|// This allows a user to use his own types in Google Test assertions by
end_comment

begin_comment
comment|// overloading the<< operator.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// util/gtl/stl_logging-inl.h overloads<< for STL containers.  These
end_comment

begin_comment
comment|// overloads cannot be defined in the std namespace, as that will be
end_comment

begin_comment
comment|// undefined behavior.  Therefore, they are defined in the global
end_comment

begin_comment
comment|// namespace instead.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// C++'s symbol lookup rule (i.e. Koenig lookup) says that these
end_comment

begin_comment
comment|// overloads are visible in either the std namespace or the global
end_comment

begin_comment
comment|// namespace, but not other namespaces, including the testing
end_comment

begin_comment
comment|// namespace which Google Test's Message class is in.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// To allow STL containers (and other types that has a<< operator
end_comment

begin_comment
comment|// defined in the global namespace) to be used in Google Test assertions,
end_comment

begin_comment
comment|// testing::Message must access the custom<< operator from the global
end_comment

begin_comment
comment|// namespace.  Hence this helper function.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note: Jeffrey Yasskin suggested an alternative fix by "using
end_comment

begin_comment
comment|// ::operator<<;" in the definition of Message's operator<<.  That fix
end_comment

begin_comment
comment|// doesn't require a helper function, but unfortunately doesn't
end_comment

begin_comment
comment|// compile with MSVC.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|void
name|GTestStreamToHelper
argument_list|(
argument|std::ostream* os
argument_list|,
argument|const T& val
argument_list|)
block|{
operator|*
name|os
operator|<<
name|val
block|; }
name|namespace
name|testing
block|{
comment|// Forward declaration of classes.
name|class
name|Message
block|;
comment|// Represents a failure message.
name|class
name|Test
block|;
comment|// Represents a test.
name|class
name|TestCase
block|;
comment|// A collection of related tests.
name|class
name|TestPartResult
block|;
comment|// Result of a test part.
name|class
name|TestInfo
block|;
comment|// Information about a test.
name|class
name|UnitTest
block|;
comment|// A collection of test cases.
name|class
name|UnitTestEventListenerInterface
block|;
comment|// Listens to Google Test events.
name|class
name|AssertionResult
block|;
comment|// Result of an assertion.
name|namespace
name|internal
block|{  struct
name|TraceInfo
block|;
comment|// Information about a trace point.
name|class
name|ScopedTrace
block|;
comment|// Implements scoped trace.
name|class
name|TestInfoImpl
block|;
comment|// Opaque implementation of TestInfo
name|class
name|TestResult
block|;
comment|// Result of a single Test.
name|class
name|UnitTestImpl
block|;
comment|// Opaque implementation of UnitTest
name|template
operator|<
name|typename
name|E
operator|>
name|class
name|List
block|;
comment|// A generic list.
name|template
operator|<
name|typename
name|E
operator|>
name|class
name|ListNode
block|;
comment|// A node in a generic list.
comment|// How many times InitGoogleTest() has been called.
specifier|extern
name|int
name|g_init_gtest_count
block|;
comment|// The text used in failure messages to indicate the start of the
comment|// stack trace.
specifier|extern
specifier|const
name|char
name|kStackTraceMarker
index|[]
block|;
comment|// A secret type that Google Test users don't know about.  It has no
comment|// definition on purpose.  Therefore it's impossible to create a
comment|// Secret object, which is what we want.
name|class
name|Secret
block|;
comment|// Two overloaded helpers for checking at compile time whether an
comment|// expression is a null pointer literal (i.e. NULL or any 0-valued
comment|// compile-time integral constant).  Their return values have
comment|// different sizes, so we can use sizeof() to test which version is
comment|// picked by the compiler.  These helpers have no implementations, as
comment|// we only need their signatures.
comment|//
comment|// Given IsNullLiteralHelper(x), the compiler will pick the first
comment|// version if x can be implicitly converted to Secret*, and pick the
comment|// second version otherwise.  Since Secret is a secret and incomplete
comment|// type, the only expression a user can write that has type Secret* is
comment|// a null pointer literal.  Therefore, we know that x is a null
comment|// pointer literal if and only if the first version is picked by the
comment|// compiler.
name|char
name|IsNullLiteralHelper
argument_list|(
name|Secret
operator|*
name|p
argument_list|)
block|;
name|char
argument_list|(
operator|&
name|IsNullLiteralHelper
argument_list|(
operator|...
argument_list|)
argument_list|)
index|[
literal|2
index|]
block|;
comment|// NOLINT
comment|// A compile-time bool constant that is true if and only if x is a
comment|// null pointer literal (i.e. NULL or any 0-valued compile-time
comment|// integral constant).
ifdef|#
directive|ifdef
name|GTEST_ELLIPSIS_NEEDS_COPY_
comment|// Passing non-POD classes through ellipsis (...) crashes the ARM
comment|// compiler.  The Nokia Symbian and the IBM XL C/C++ compiler try to
comment|// instantiate a copy constructor for objects passed through ellipsis
comment|// (...), failing for uncopyable objects.  Hence we define this to
comment|// false (and lose support for NULL detection).
define|#
directive|define
name|GTEST_IS_NULL_LITERAL_
parameter_list|(
name|x
parameter_list|)
value|false
else|#
directive|else
define|#
directive|define
name|GTEST_IS_NULL_LITERAL_
parameter_list|(
name|x
parameter_list|)
define|\
value|(sizeof(::testing::internal::IsNullLiteralHelper(x)) == 1)
endif|#
directive|endif
comment|// GTEST_ELLIPSIS_NEEDS_COPY_
comment|// Appends the user-supplied message to the Google-Test-generated message.
name|String
name|AppendUserMessage
argument_list|(
specifier|const
name|String
operator|&
name|gtest_msg
argument_list|,
specifier|const
name|Message
operator|&
name|user_msg
argument_list|)
block|;
comment|// A helper class for creating scoped traces in user programs.
name|class
name|ScopedTrace
block|{
name|public
operator|:
comment|// The c'tor pushes the given source file location and message onto
comment|// a trace stack maintained by Google Test.
name|ScopedTrace
argument_list|(
argument|const char* file
argument_list|,
argument|int line
argument_list|,
argument|const Message& message
argument_list|)
block|;
comment|// The d'tor pops the info pushed by the c'tor.
comment|//
comment|// Note that the d'tor is not virtual in order to be efficient.
comment|// Don't inherit from ScopedTrace!
operator|~
name|ScopedTrace
argument_list|()
block|;
name|private
operator|:
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ScopedTrace
argument_list|)
block|; }
name|GTEST_ATTRIBUTE_UNUSED_
block|;
comment|// A ScopedTrace object does its job in its
comment|// c'tor and d'tor.  Therefore it doesn't
comment|// need to be used otherwise.
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
block|;
comment|// Formats a value to be used in a failure message.
ifdef|#
directive|ifdef
name|GTEST_NEEDS_IS_POINTER_
comment|// These are needed as the Nokia Symbian and IBM XL C/C++ compilers
comment|// cannot decide between const T& and const T* in a function template.
comment|// These compilers _can_ decide between class template specializations
comment|// for T and T*, so a tr1::type_traits-like is_pointer works, and we
comment|// can overload on that.
comment|// This overload makes sure that all pointers (including
comment|// those to char or wchar_t) are printed as raw pointers.
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|String
name|FormatValueForFailureMessage
argument_list|(
argument|internal::true_type dummy
argument_list|,
argument|T* pointer
argument_list|)
block|{
return|return
name|StreamableToString
argument_list|(
name|static_cast
operator|<
specifier|const
name|void
operator|*
operator|>
operator|(
name|pointer
operator|)
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|String
name|FormatValueForFailureMessage
argument_list|(
argument|internal::false_type dummy
argument_list|,
argument|const T& value
argument_list|)
block|{
return|return
name|StreamableToString
argument_list|(
name|value
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|String
name|FormatForFailureMessage
argument_list|(
argument|const T& value
argument_list|)
block|{
return|return
name|FormatValueForFailureMessage
argument_list|(
argument|typename internal::is_pointer<T>::type()
argument_list|,
argument|value
argument_list|)
return|;
block|}
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|// These are needed as the above solution using is_pointer has the
end_comment

begin_comment
comment|// limitation that T cannot be a type without external linkage, when
end_comment

begin_comment
comment|// compiled using MSVC.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|String
name|FormatForFailureMessage
argument_list|(
argument|const T& value
argument_list|)
block|{
return|return
name|StreamableToString
argument_list|(
name|value
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// This overload makes sure that all pointers (including
end_comment

begin_comment
comment|// those to char or wchar_t) are printed as raw pointers.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|String
name|FormatForFailureMessage
argument_list|(
argument|T* pointer
argument_list|)
block|{
return|return
name|StreamableToString
argument_list|(
name|static_cast
operator|<
specifier|const
name|void
operator|*
operator|>
operator|(
name|pointer
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_NEEDS_IS_POINTER_
end_comment

begin_comment
comment|// These overloaded versions handle narrow and wide characters.
end_comment

begin_function_decl
name|String
name|FormatForFailureMessage
parameter_list|(
name|char
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|String
name|FormatForFailureMessage
parameter_list|(
name|wchar_t
name|wchar
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// When this operand is a const char* or char*, and the other operand
end_comment

begin_comment
comment|// is a ::std::string or ::string, we print this operand as a C string
end_comment

begin_comment
comment|// rather than a pointer.  We do the same for wide strings.
end_comment

begin_comment
comment|// This internal macro is used to avoid duplicated code.
end_comment

begin_define
define|#
directive|define
name|GTEST_FORMAT_IMPL_
parameter_list|(
name|operand2_type
parameter_list|,
name|operand1_printer
parameter_list|)
define|\
value|inline String FormatForComparisonFailureMessage(\     operand2_type::value_type* str, const operand2_type&
comment|/*operand2*/
value|) {\   return operand1_printer(str);\ }\ inline String FormatForComparisonFailureMessage(\     const operand2_type::value_type* str, const operand2_type&
comment|/*operand2*/
value|) {\   return operand1_printer(str);\ }
end_define

begin_if
if|#
directive|if
name|GTEST_HAS_STD_STRING
end_if

begin_macro
name|GTEST_FORMAT_IMPL_
argument_list|(
argument|::std::string
argument_list|,
argument|String::ShowCStringQuoted
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_STD_STRING
end_comment

begin_if
if|#
directive|if
name|GTEST_HAS_STD_WSTRING
end_if

begin_macro
name|GTEST_FORMAT_IMPL_
argument_list|(
argument|::std::wstring
argument_list|,
argument|String::ShowWideCStringQuoted
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_STD_WSTRING
end_comment

begin_if
if|#
directive|if
name|GTEST_HAS_GLOBAL_STRING
end_if

begin_macro
name|GTEST_FORMAT_IMPL_
argument_list|(
argument|::string
argument_list|,
argument|String::ShowCStringQuoted
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_GLOBAL_STRING
end_comment

begin_if
if|#
directive|if
name|GTEST_HAS_GLOBAL_WSTRING
end_if

begin_macro
name|GTEST_FORMAT_IMPL_
argument_list|(
argument|::wstring
argument_list|,
argument|String::ShowWideCStringQuoted
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_GLOBAL_WSTRING
end_comment

begin_undef
undef|#
directive|undef
name|GTEST_FORMAT_IMPL_
end_undef

begin_comment
comment|// Constructs and returns the message for an equality assertion
end_comment

begin_comment
comment|// (e.g. ASSERT_EQ, EXPECT_STREQ, etc) failure.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The first four parameters are the expressions used in the assertion
end_comment

begin_comment
comment|// and their values, as strings.  For example, for ASSERT_EQ(foo, bar)
end_comment

begin_comment
comment|// where foo is 5 and bar is 6, we have:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   expected_expression: "foo"
end_comment

begin_comment
comment|//   actual_expression:   "bar"
end_comment

begin_comment
comment|//   expected_value:      "5"
end_comment

begin_comment
comment|//   actual_value:        "6"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The ignoring_case parameter is true iff the assertion is a
end_comment

begin_comment
comment|// *_STRCASEEQ*.  When it's true, the string " (ignoring case)" will
end_comment

begin_comment
comment|// be inserted into the message.
end_comment

begin_function_decl
name|AssertionResult
name|EqFailure
parameter_list|(
specifier|const
name|char
modifier|*
name|expected_expression
parameter_list|,
specifier|const
name|char
modifier|*
name|actual_expression
parameter_list|,
specifier|const
name|String
modifier|&
name|expected_value
parameter_list|,
specifier|const
name|String
modifier|&
name|actual_value
parameter_list|,
name|bool
name|ignoring_case
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// This template class represents an IEEE floating-point number
end_comment

begin_comment
comment|// (either single-precision or double-precision, depending on the
end_comment

begin_comment
comment|// template parameters).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The purpose of this class is to do more sophisticated number
end_comment

begin_comment
comment|// comparison.  (Due to round-off error, etc, it's very unlikely that
end_comment

begin_comment
comment|// two floating-points will be equal exactly.  Hence a naive
end_comment

begin_comment
comment|// comparison by the == operation often doesn't work.)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Format of IEEE floating-point:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   The most-significant bit being the leftmost, an IEEE
end_comment

begin_comment
comment|//   floating-point looks like
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     sign_bit exponent_bits fraction_bits
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   Here, sign_bit is a single bit that designates the sign of the
end_comment

begin_comment
comment|//   number.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   For float, there are 8 exponent bits and 23 fraction bits.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   For double, there are 11 exponent bits and 52 fraction bits.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   More details can be found at
end_comment

begin_comment
comment|//   http://en.wikipedia.org/wiki/IEEE_floating-point_standard.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Template parameter:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   RawType: the raw floating-point type (either float or double)
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|RawType
operator|>
name|class
name|FloatingPoint
block|{
name|public
operator|:
comment|// Defines the unsigned integer type that has the same size as the
comment|// floating point number.
typedef|typedef
name|typename
name|TypeWithSize
operator|<
sizeof|sizeof
argument_list|(
name|RawType
argument_list|)
operator|>
operator|::
name|UInt
name|Bits
expr_stmt|;
comment|// Constants.
comment|// # of bits in a number.
specifier|static
specifier|const
name|size_t
name|kBitCount
operator|=
literal|8
operator|*
sizeof|sizeof
argument_list|(
name|RawType
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// # of fraction bits in a number.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|size_t
name|kFractionBitCount
init|=
name|std
operator|::
name|numeric_limits
operator|<
name|RawType
operator|>
operator|::
name|digits
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// # of exponent bits in a number.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|size_t
name|kExponentBitCount
init|=
name|kBitCount
operator|-
literal|1
operator|-
name|kFractionBitCount
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The mask for the sign bit.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|Bits
name|kSignBitMask
init|=
name|static_cast
operator|<
name|Bits
operator|>
operator|(
literal|1
operator|)
operator|<<
operator|(
name|kBitCount
operator|-
literal|1
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The mask for the fraction bits.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|Bits
name|kFractionBitMask
init|=
operator|~
name|static_cast
operator|<
name|Bits
operator|>
operator|(
literal|0
operator|)
operator|>>
operator|(
name|kExponentBitCount
operator|+
literal|1
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The mask for the exponent bits.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|Bits
name|kExponentBitMask
init|=
operator|~
operator|(
name|kSignBitMask
operator||
name|kFractionBitMask
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// How many ULP's (Units in the Last Place) we want to tolerate when
end_comment

begin_comment
comment|// comparing two numbers.  The larger the value, the more error we
end_comment

begin_comment
comment|// allow.  A 0 value means that two numbers must be exactly the same
end_comment

begin_comment
comment|// to be considered equal.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The maximum error of a single floating-point operation is 0.5
end_comment

begin_comment
comment|// units in the last place.  On Intel CPU's, all floating-point
end_comment

begin_comment
comment|// calculations are done with 80-bit precision, while double has 64
end_comment

begin_comment
comment|// bits.  Therefore, 4 should be enough for ordinary use.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// See the following article for more details on ULP:
end_comment

begin_comment
comment|// http://www.cygnus-software.com/papers/comparingfloats/comparingfloats.htm.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|size_t
name|kMaxUlps
init|=
literal|4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Constructs a FloatingPoint from a raw floating-point number.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// On an Intel CPU, passing a non-normalized NAN (Not a Number)
end_comment

begin_comment
comment|// around may change its bits, although the new value is guaranteed
end_comment

begin_comment
comment|// to be also a NAN.  Therefore, don't expect this constructor to
end_comment

begin_comment
comment|// preserve the bits in x when x is a NAN.
end_comment

begin_macro
name|explicit
end_macro

begin_expr_stmt
name|FloatingPoint
argument_list|(
specifier|const
name|RawType
operator|&
name|x
argument_list|)
operator|:
name|value_
argument_list|(
argument|x
argument_list|)
block|{}
comment|// Static methods
comment|// Reinterprets a bit pattern as a floating-point number.
comment|//
comment|// This function is needed to test the AlmostEquals() method.
specifier|static
name|RawType
name|ReinterpretBits
argument_list|(
argument|const Bits bits
argument_list|)
block|{
name|FloatingPoint
name|fp
argument_list|(
literal|0
argument_list|)
block|;
name|fp
operator|.
name|bits_
operator|=
name|bits
block|;
return|return
name|fp
operator|.
name|value_
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns the floating-point number that represent positive infinity.
end_comment

begin_function
specifier|static
name|RawType
name|Infinity
parameter_list|()
block|{
return|return
name|ReinterpretBits
argument_list|(
name|kExponentBitMask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Non-static methods
end_comment

begin_comment
comment|// Returns the bits that represents this number.
end_comment

begin_expr_stmt
specifier|const
name|Bits
operator|&
name|bits
argument_list|()
specifier|const
block|{
return|return
name|bits_
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns the exponent bits of this number.
end_comment

begin_expr_stmt
name|Bits
name|exponent_bits
argument_list|()
specifier|const
block|{
return|return
name|kExponentBitMask
operator|&
name|bits_
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns the fraction bits of this number.
end_comment

begin_expr_stmt
name|Bits
name|fraction_bits
argument_list|()
specifier|const
block|{
return|return
name|kFractionBitMask
operator|&
name|bits_
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns the sign bit of this number.
end_comment

begin_expr_stmt
name|Bits
name|sign_bit
argument_list|()
specifier|const
block|{
return|return
name|kSignBitMask
operator|&
name|bits_
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns true iff this is NAN (not a number).
end_comment

begin_expr_stmt
name|bool
name|is_nan
argument_list|()
specifier|const
block|{
comment|// It's a NAN if the exponent bits are all ones and the fraction
comment|// bits are not entirely zeros.
return|return
operator|(
name|exponent_bits
argument_list|()
operator|==
name|kExponentBitMask
operator|)
operator|&&
operator|(
name|fraction_bits
argument_list|()
operator|!=
literal|0
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns true iff this number is at most kMaxUlps ULP's away from
end_comment

begin_comment
comment|// rhs.  In particular, this function:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   - returns false if either number is (or both are) NAN.
end_comment

begin_comment
comment|//   - treats really large numbers as almost equal to infinity.
end_comment

begin_comment
comment|//   - thinks +0.0 and -0.0 are 0 DLP's apart.
end_comment

begin_decl_stmt
name|bool
name|AlmostEquals
argument_list|(
specifier|const
name|FloatingPoint
operator|&
name|rhs
argument_list|)
decl|const
block|{
comment|// The IEEE standard says that any comparison operation involving
comment|// a NAN must return false.
if|if
condition|(
name|is_nan
argument_list|()
operator|||
name|rhs
operator|.
name|is_nan
argument_list|()
condition|)
return|return
name|false
return|;
return|return
name|DistanceBetweenSignAndMagnitudeNumbers
argument_list|(
name|bits_
argument_list|,
name|rhs
operator|.
name|bits_
argument_list|)
operator|<=
name|kMaxUlps
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// Converts an integer from the sign-and-magnitude representation to
end_comment

begin_comment
comment|// the biased representation.  More precisely, let N be 2 to the
end_comment

begin_comment
comment|// power of (kBitCount - 1), an integer x is represented by the
end_comment

begin_comment
comment|// unsigned number x + N.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For instance,
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   -N + 1 (the most negative number representable using
end_comment

begin_comment
comment|//          sign-and-magnitude) is represented by 1;
end_comment

begin_comment
comment|//   0      is represented by N; and
end_comment

begin_comment
comment|//   N - 1  (the biggest number representable using
end_comment

begin_comment
comment|//          sign-and-magnitude) is represented by 2N - 1.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Read http://en.wikipedia.org/wiki/Signed_number_representations
end_comment

begin_comment
comment|// for more details on signed number representations.
end_comment

begin_function
specifier|static
name|Bits
name|SignAndMagnitudeToBiased
parameter_list|(
specifier|const
name|Bits
modifier|&
name|sam
parameter_list|)
block|{
if|if
condition|(
name|kSignBitMask
operator|&
name|sam
condition|)
block|{
comment|// sam represents a negative number.
return|return
operator|~
name|sam
operator|+
literal|1
return|;
block|}
else|else
block|{
comment|// sam represents a positive number.
return|return
name|kSignBitMask
operator||
name|sam
return|;
block|}
block|}
end_function

begin_comment
comment|// Given two numbers in the sign-and-magnitude representation,
end_comment

begin_comment
comment|// returns the distance between them as an unsigned number.
end_comment

begin_function
specifier|static
name|Bits
name|DistanceBetweenSignAndMagnitudeNumbers
parameter_list|(
specifier|const
name|Bits
modifier|&
name|sam1
parameter_list|,
specifier|const
name|Bits
modifier|&
name|sam2
parameter_list|)
block|{
specifier|const
name|Bits
name|biased1
init|=
name|SignAndMagnitudeToBiased
argument_list|(
name|sam1
argument_list|)
decl_stmt|;
specifier|const
name|Bits
name|biased2
init|=
name|SignAndMagnitudeToBiased
argument_list|(
name|sam2
argument_list|)
decl_stmt|;
return|return
operator|(
name|biased1
operator|>=
name|biased2
operator|)
condition|?
operator|(
name|biased1
operator|-
name|biased2
operator|)
else|:
operator|(
name|biased2
operator|-
name|biased1
operator|)
return|;
block|}
end_function

begin_union
union|union
block|{
name|RawType
name|value_
decl_stmt|;
comment|// The raw floating-point number.
name|Bits
name|bits_
decl_stmt|;
comment|// The bits that represent the number.
block|}
union|;
end_union

begin_comment
unit|};
comment|// Typedefs the instances of the FloatingPoint template class that we
end_comment

begin_comment
comment|// care to use.
end_comment

begin_typedef
typedef|typedef
name|FloatingPoint
operator|<
name|float
operator|>
name|Float
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|FloatingPoint
operator|<
name|double
operator|>
name|Double
expr_stmt|;
end_typedef

begin_comment
comment|// In order to catch the mistake of putting tests that use different
end_comment

begin_comment
comment|// test fixture classes in the same test case, we need to assign
end_comment

begin_comment
comment|// unique IDs to fixture classes and compare them.  The TypeId type is
end_comment

begin_comment
comment|// used to hold such IDs.  The user should treat TypeId as an opaque
end_comment

begin_comment
comment|// type: the only operation allowed on TypeId values is to compare
end_comment

begin_comment
comment|// them for equality using the == operator.
end_comment

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
name|TypeId
typedef|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|TypeIdHelper
block|{
name|public
operator|:
comment|// dummy_ must not have a const type.  Otherwise an overly eager
comment|// compiler (e.g. MSVC 7.1& 8.0) may try to merge
comment|// TypeIdHelper<T>::dummy_ for different Ts as an "optimization".
specifier|static
name|bool
name|dummy_
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|TypeIdHelper
operator|<
name|T
operator|>
operator|::
name|dummy_
operator|=
name|false
expr_stmt|;
end_expr_stmt

begin_comment
comment|// GetTypeId<T>() returns the ID of type T.  Different values will be
end_comment

begin_comment
comment|// returned for different types.  Calling the function twice with the
end_comment

begin_comment
comment|// same type argument is guaranteed to return the same ID.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|TypeId
name|GetTypeId
argument_list|()
block|{
comment|// The compiler is required to allocate a different
comment|// TypeIdHelper<T>::dummy_ variable for each T used to instantiate
comment|// the template.  Therefore, the address of dummy_ is guaranteed to
comment|// be unique.
return|return
operator|&
operator|(
name|TypeIdHelper
operator|<
name|T
operator|>
operator|::
name|dummy_
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns the type ID of ::testing::Test.  Always call this instead
end_comment

begin_comment
comment|// of GetTypeId< ::testing::Test>() to get the type ID of
end_comment

begin_comment
comment|// ::testing::Test, as the latter may give the wrong result due to a
end_comment

begin_comment
comment|// suspected linker bug when compiling Google Test as a Mac OS X
end_comment

begin_comment
comment|// framework.
end_comment

begin_function_decl
name|TypeId
name|GetTestTypeId
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Defines the abstract factory interface that creates instances
end_comment

begin_comment
comment|// of a Test object.
end_comment

begin_decl_stmt
name|class
name|TestFactoryBase
block|{
name|public
label|:
name|virtual
operator|~
name|TestFactoryBase
argument_list|()
block|{}
comment|// Creates a test instance to run. The instance is both created and destroyed
comment|// within TestInfoImpl::Run()
name|virtual
name|Test
operator|*
name|CreateTest
argument_list|()
operator|=
literal|0
expr_stmt|;
name|protected
label|:
name|TestFactoryBase
argument_list|()
block|{}
name|private
label|:
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|TestFactoryBase
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// This class provides implementation of TeastFactoryBase interface.
end_comment

begin_comment
comment|// It is used in TEST and TEST_F macros.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|TestClass
operator|>
name|class
name|TestFactoryImpl
operator|:
name|public
name|TestFactoryBase
block|{
name|public
operator|:
name|virtual
name|Test
operator|*
name|CreateTest
argument_list|()
block|{
return|return
name|new
name|TestClass
return|;
block|}
end_expr_stmt

begin_ifdef
unit|};
ifdef|#
directive|ifdef
name|GTEST_OS_WINDOWS
end_ifdef

begin_comment
comment|// Predicate-formatters for implementing the HRESULT checking macros
end_comment

begin_comment
comment|// {ASSERT|EXPECT}_HRESULT_{SUCCEEDED|FAILED}
end_comment

begin_comment
comment|// We pass a long instead of HRESULT to avoid causing an
end_comment

begin_comment
comment|// include dependency for the HRESULT type.
end_comment

begin_function_decl
name|AssertionResult
name|IsHRESULTSuccess
parameter_list|(
specifier|const
name|char
modifier|*
name|expr
parameter_list|,
name|long
name|hr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// NOLINT
end_comment

begin_function_decl
name|AssertionResult
name|IsHRESULTFailure
parameter_list|(
specifier|const
name|char
modifier|*
name|expr
parameter_list|,
name|long
name|hr
parameter_list|)
function_decl|;
end_function_decl

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
comment|// Formats a source file path and a line number as they would appear
end_comment

begin_comment
comment|// in a compiler error message.
end_comment

begin_function
specifier|inline
name|String
name|FormatFileLocation
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
specifier|const
name|char
modifier|*
specifier|const
name|file_name
init|=
name|file
operator|==
name|NULL
condition|?
literal|"unknown file"
else|:
name|file
decl_stmt|;
if|if
condition|(
name|line
operator|<
literal|0
condition|)
block|{
return|return
name|String
operator|::
name|Format
argument_list|(
literal|"%s:"
argument_list|,
name|file_name
argument_list|)
return|;
block|}
ifdef|#
directive|ifdef
name|_MSC_VER
return|return
name|String
operator|::
name|Format
argument_list|(
literal|"%s(%d):"
argument_list|,
name|file_name
argument_list|,
name|line
argument_list|)
return|;
else|#
directive|else
return|return
name|String
operator|::
name|Format
argument_list|(
literal|"%s:%d:"
argument_list|,
name|file_name
argument_list|,
name|line
argument_list|)
return|;
endif|#
directive|endif
comment|// _MSC_VER
block|}
end_function

begin_comment
comment|// Types of SetUpTestCase() and TearDownTestCase() functions.
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|SetUpTestCaseFunc
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|TearDownTestCaseFunc
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_comment
comment|// Creates a new TestInfo object and registers it with Google Test;
end_comment

begin_comment
comment|// returns the created object.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Arguments:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   test_case_name:   name of the test case
end_comment

begin_comment
comment|//   name:             name of the test
end_comment

begin_comment
comment|//   test_case_comment: a comment on the test case that will be included in
end_comment

begin_comment
comment|//                      the test output
end_comment

begin_comment
comment|//   comment:          a comment on the test that will be included in the
end_comment

begin_comment
comment|//                     test output
end_comment

begin_comment
comment|//   fixture_class_id: ID of the test fixture class
end_comment

begin_comment
comment|//   set_up_tc:        pointer to the function that sets up the test case
end_comment

begin_comment
comment|//   tear_down_tc:     pointer to the function that tears down the test case
end_comment

begin_comment
comment|//   factory:          pointer to the factory that creates a test object.
end_comment

begin_comment
comment|//                     The newly created TestInfo instance will assume
end_comment

begin_comment
comment|//                     ownership of the factory object.
end_comment

begin_function_decl
name|TestInfo
modifier|*
name|MakeAndRegisterTestInfo
parameter_list|(
specifier|const
name|char
modifier|*
name|test_case_name
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|test_case_comment
parameter_list|,
specifier|const
name|char
modifier|*
name|comment
parameter_list|,
name|TypeId
name|fixture_class_id
parameter_list|,
name|SetUpTestCaseFunc
name|set_up_tc
parameter_list|,
name|TearDownTestCaseFunc
name|tear_down_tc
parameter_list|,
name|TestFactoryBase
modifier|*
name|factory
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|GTEST_HAS_TYPED_TEST
argument_list|)
operator|||
name|defined
argument_list|(
name|GTEST_HAS_TYPED_TEST_P
argument_list|)
end_if

begin_comment
comment|// State of the definition of a type-parameterized test case.
end_comment

begin_decl_stmt
name|class
name|TypedTestCasePState
block|{
name|public
label|:
name|TypedTestCasePState
argument_list|()
operator|:
name|registered_
argument_list|(
argument|false
argument_list|)
block|{}
comment|// Adds the given test name to defined_test_names_ and return true
comment|// if the test case hasn't been registered; otherwise aborts the
comment|// program.
name|bool
name|AddTestName
argument_list|(
argument|const char* file
argument_list|,
argument|int line
argument_list|,
argument|const char* case_name
argument_list|,
argument|const char* test_name
argument_list|)
block|{
if|if
condition|(
name|registered_
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s Test %s must be defined before "
literal|"REGISTER_TYPED_TEST_CASE_P(%s, ...).\n"
argument_list|,
name|FormatFileLocation
argument_list|(
name|file
argument_list|,
name|line
argument_list|)
operator|.
name|c_str
argument_list|()
argument_list|,
name|test_name
argument_list|,
name|case_name
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
name|defined_test_names_
operator|.
name|insert
argument_list|(
name|test_name
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_decl_stmt

begin_comment
comment|// Verifies that registered_tests match the test names in
end_comment

begin_comment
comment|// defined_test_names_; returns registered_tests if successful, or
end_comment

begin_comment
comment|// aborts the program otherwise.
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|VerifyRegisteredTestNames
parameter_list|(
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
name|registered_tests
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|bool
name|registered_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
operator|::
name|std
operator|::
name|set
operator|<
specifier|const
name|char
operator|*
operator|>
name|defined_test_names_
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Skips to the first non-space char after the first comma in 'str';
end_comment

begin_comment
comment|// returns NULL if no comma is found in 'str'.
end_comment

begin_function
specifier|inline
specifier|const
name|char
modifier|*
name|SkipComma
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|comma
init|=
name|strchr
argument_list|(
name|str
argument_list|,
literal|','
argument_list|)
decl_stmt|;
if|if
condition|(
name|comma
operator|==
name|NULL
condition|)
block|{
return|return
name|NULL
return|;
block|}
while|while
condition|(
name|isspace
argument_list|(
operator|*
operator|(
operator|++
name|comma
operator|)
argument_list|)
condition|)
block|{}
return|return
name|comma
return|;
block|}
end_function

begin_comment
comment|// Returns the prefix of 'str' before the first comma in it; returns
end_comment

begin_comment
comment|// the entire string if it contains no comma.
end_comment

begin_function
specifier|inline
name|String
name|GetPrefixUntilComma
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|comma
init|=
name|strchr
argument_list|(
name|str
argument_list|,
literal|','
argument_list|)
decl_stmt|;
return|return
name|comma
operator|==
name|NULL
condition|?
name|String
argument_list|(
name|str
argument_list|)
else|:
name|String
argument_list|(
name|str
argument_list|,
name|comma
operator|-
name|str
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// TypeParameterizedTest<Fixture, TestSel, Types>::Register()
end_comment

begin_comment
comment|// registers a list of type-parameterized tests with Google Test.  The
end_comment

begin_comment
comment|// return value is insignificant - we just need to return something
end_comment

begin_comment
comment|// such that we can call this function in a namespace scope.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Implementation note: The GTEST_TEMPLATE_ macro declares a template
end_comment

begin_comment
comment|// template parameter.  It's defined in gtest-type-util.h.
end_comment

begin_expr_stmt
name|template
operator|<
name|GTEST_TEMPLATE_
name|Fixture
operator|,
name|class
name|TestSel
operator|,
name|typename
name|Types
operator|>
name|class
name|TypeParameterizedTest
block|{
name|public
operator|:
comment|// 'index' is the index of the test in the type list 'Types'
comment|// specified in INSTANTIATE_TYPED_TEST_CASE_P(Prefix, TestCase,
comment|// Types).  Valid values for 'index' are [0, N - 1] where N is the
comment|// length of Types.
specifier|static
name|bool
name|Register
argument_list|(
argument|const char* prefix
argument_list|,
argument|const char* case_name
argument_list|,
argument|const char* test_names
argument_list|,
argument|int index
argument_list|)
block|{
typedef|typedef
name|typename
name|Types
operator|::
name|Head
name|Type
expr_stmt|;
typedef|typedef
name|Fixture
operator|<
name|Type
operator|>
name|FixtureClass
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|GTEST_BIND_
argument_list|(
name|TestSel
argument_list|,
name|Type
argument_list|)
name|TestClass
typedef|;
end_typedef

begin_comment
comment|// First, registers the first type-parameterized test in the type
end_comment

begin_comment
comment|// list.
end_comment

begin_macro
name|MakeAndRegisterTestInfo
argument_list|(
argument|String::Format(
literal|"%s%s%s/%d"
argument|, prefix, prefix[
literal|0
argument|] ==
literal|'\0'
argument|?
literal|""
argument|:
literal|"/"
argument|,                        case_name, index).c_str()
argument_list|,
argument|GetPrefixUntilComma(test_names).c_str()
argument_list|,
argument|String::Format(
literal|"TypeParam = %s"
argument|, GetTypeName<Type>().c_str()).c_str()
argument_list|,
literal|""
argument_list|,
argument|GetTypeId<FixtureClass>()
argument_list|,
argument|TestClass::SetUpTestCase
argument_list|,
argument|TestClass::TearDownTestCase
argument_list|,
argument|new TestFactoryImpl<TestClass>
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Next, recurses (at compile time) with the tail of the type list.
end_comment

begin_return
return|return
name|TypeParameterizedTest
operator|<
name|Fixture
operator|,
name|TestSel
operator|,
name|typename
name|Types
operator|::
name|Tail
operator|>
operator|::
name|Register
argument_list|(
name|prefix
argument_list|,
name|case_name
argument_list|,
name|test_names
argument_list|,
name|index
operator|+
literal|1
argument_list|)
return|;
end_return

begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt

begin_comment
comment|// The base case for the compile time recursion.
end_comment

begin_expr_stmt
name|template
operator|<
name|GTEST_TEMPLATE_
name|Fixture
operator|,
name|class
name|TestSel
operator|>
name|class
name|TypeParameterizedTest
operator|<
name|Fixture
operator|,
name|TestSel
operator|,
name|Types0
operator|>
block|{
name|public
operator|:
specifier|static
name|bool
name|Register
argument_list|(
argument|const char*
comment|/*prefix*/
argument_list|,
argument|const char*
comment|/*case_name*/
argument_list|,
argument|const char*
comment|/*test_names*/
argument_list|,
argument|int
comment|/*index*/
argument_list|)
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// TypeParameterizedTestCase<Fixture, Tests, Types>::Register()
end_comment

begin_comment
comment|// registers *all combinations* of 'Tests' and 'Types' with Google
end_comment

begin_comment
comment|// Test.  The return value is insignificant - we just need to return
end_comment

begin_comment
comment|// something such that we can call this function in a namespace scope.
end_comment

begin_expr_stmt
name|template
operator|<
name|GTEST_TEMPLATE_
name|Fixture
operator|,
name|typename
name|Tests
operator|,
name|typename
name|Types
operator|>
name|class
name|TypeParameterizedTestCase
block|{
name|public
operator|:
specifier|static
name|bool
name|Register
argument_list|(
argument|const char* prefix
argument_list|,
argument|const char* case_name
argument_list|,
argument|const char* test_names
argument_list|)
block|{
typedef|typedef
name|typename
name|Tests
operator|::
name|Head
name|Head
expr_stmt|;
comment|// First, register the first test in 'Test' for each type in 'Types'.
name|TypeParameterizedTest
operator|<
name|Fixture
operator|,
name|Head
operator|,
name|Types
operator|>
operator|::
name|Register
argument_list|(
name|prefix
argument_list|,
name|case_name
argument_list|,
name|test_names
argument_list|,
literal|0
argument_list|)
block|;
comment|// Next, recurses (at compile time) with the tail of the test list.
return|return
name|TypeParameterizedTestCase
operator|<
name|Fixture
operator|,
name|typename
name|Tests
operator|::
name|Tail
operator|,
name|Types
operator|>
operator|::
name|Register
argument_list|(
name|prefix
argument_list|,
name|case_name
argument_list|,
name|SkipComma
argument_list|(
name|test_names
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// The base case for the compile time recursion.
end_comment

begin_expr_stmt
name|template
operator|<
name|GTEST_TEMPLATE_
name|Fixture
operator|,
name|typename
name|Types
operator|>
name|class
name|TypeParameterizedTestCase
operator|<
name|Fixture
operator|,
name|Templates0
operator|,
name|Types
operator|>
block|{
name|public
operator|:
specifier|static
name|bool
name|Register
argument_list|(
argument|const char* prefix
argument_list|,
argument|const char* case_name
argument_list|,
argument|const char* test_names
argument_list|)
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_TYPED_TEST || GTEST_HAS_TYPED_TEST_P
end_comment

begin_comment
comment|// Returns the current OS stack trace as a String.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The maximum number of stack frames to be included is specified by
end_comment

begin_comment
comment|// the gtest_stack_trace_depth flag.  The skip_count parameter
end_comment

begin_comment
comment|// specifies the number of top frames to be skipped, which doesn't
end_comment

begin_comment
comment|// count against the number of frames to be included.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For example, if Foo() calls Bar(), which in turn calls
end_comment

begin_comment
comment|// GetCurrentOsStackTraceExceptTop(..., 1), Foo() will be included in
end_comment

begin_comment
comment|// the trace but Bar() and GetCurrentOsStackTraceExceptTop() won't.
end_comment

begin_function_decl
name|String
name|GetCurrentOsStackTraceExceptTop
parameter_list|(
name|UnitTest
modifier|*
name|unit_test
parameter_list|,
name|int
name|skip_count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Returns the number of failed test parts in the given test result object.
end_comment

begin_function_decl
name|int
name|GetFailedPartCount
parameter_list|(
specifier|const
name|TestResult
modifier|*
name|result
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

begin_define
define|#
directive|define
name|GTEST_MESSAGE_
parameter_list|(
name|message
parameter_list|,
name|result_type
parameter_list|)
define|\
value|::testing::internal::AssertHelper(result_type, __FILE__, __LINE__, message) \     = ::testing::Message()
end_define

begin_define
define|#
directive|define
name|GTEST_FATAL_FAILURE_
parameter_list|(
name|message
parameter_list|)
define|\
value|return GTEST_MESSAGE_(message, ::testing::TPRT_FATAL_FAILURE)
end_define

begin_define
define|#
directive|define
name|GTEST_NONFATAL_FAILURE_
parameter_list|(
name|message
parameter_list|)
define|\
value|GTEST_MESSAGE_(message, ::testing::TPRT_NONFATAL_FAILURE)
end_define

begin_define
define|#
directive|define
name|GTEST_SUCCESS_
parameter_list|(
name|message
parameter_list|)
define|\
value|GTEST_MESSAGE_(message, ::testing::TPRT_SUCCESS)
end_define

begin_define
define|#
directive|define
name|GTEST_TEST_THROW_
parameter_list|(
name|statement
parameter_list|,
name|expected_exception
parameter_list|,
name|fail
parameter_list|)
define|\
value|GTEST_AMBIGUOUS_ELSE_BLOCKER_ \   if (const char* gtest_msg = "") { \     bool gtest_caught_expected = false; \     try { \       statement; \     } \     catch (expected_exception const&) { \       gtest_caught_expected = true; \     } \     catch (...) { \       gtest_msg = "Expected: " #statement " throws an exception of type " \                   #expected_exception ".\n  Actual: it throws a different " \                   "type."; \       goto GTEST_CONCAT_TOKEN_(gtest_label_testthrow_, __LINE__); \     } \     if (!gtest_caught_expected) { \       gtest_msg = "Expected: " #statement " throws an exception of type " \                   #expected_exception ".\n  Actual: it throws nothing."; \       goto GTEST_CONCAT_TOKEN_(gtest_label_testthrow_, __LINE__); \     } \   } else \     GTEST_CONCAT_TOKEN_(gtest_label_testthrow_, __LINE__): \       fail(gtest_msg)
end_define

begin_define
define|#
directive|define
name|GTEST_TEST_NO_THROW_
parameter_list|(
name|statement
parameter_list|,
name|fail
parameter_list|)
define|\
value|GTEST_AMBIGUOUS_ELSE_BLOCKER_ \   if (const char* gtest_msg = "") { \     try { \       statement; \     } \     catch (...) { \       gtest_msg = "Expected: " #statement " doesn't throw an exception.\n" \                   "  Actual: it throws."; \       goto GTEST_CONCAT_TOKEN_(gtest_label_testnothrow_, __LINE__); \     } \   } else \     GTEST_CONCAT_TOKEN_(gtest_label_testnothrow_, __LINE__): \       fail(gtest_msg)
end_define

begin_define
define|#
directive|define
name|GTEST_TEST_ANY_THROW_
parameter_list|(
name|statement
parameter_list|,
name|fail
parameter_list|)
define|\
value|GTEST_AMBIGUOUS_ELSE_BLOCKER_ \   if (const char* gtest_msg = "") { \     bool gtest_caught_any = false; \     try { \       statement; \     } \     catch (...) { \       gtest_caught_any = true; \     } \     if (!gtest_caught_any) { \       gtest_msg = "Expected: " #statement " throws an exception.\n" \                   "  Actual: it doesn't."; \       goto GTEST_CONCAT_TOKEN_(gtest_label_testanythrow_, __LINE__); \     } \   } else \     GTEST_CONCAT_TOKEN_(gtest_label_testanythrow_, __LINE__): \       fail(gtest_msg)
end_define

begin_define
define|#
directive|define
name|GTEST_TEST_BOOLEAN_
parameter_list|(
name|boolexpr
parameter_list|,
name|booltext
parameter_list|,
name|actual
parameter_list|,
name|expected
parameter_list|,
name|fail
parameter_list|)
define|\
value|GTEST_AMBIGUOUS_ELSE_BLOCKER_ \   if (boolexpr) \     ; \   else \     fail("Value of: " booltext "\n  Actual: " #actual "\nExpected: " #expected)
end_define

begin_define
define|#
directive|define
name|GTEST_TEST_NO_FATAL_FAILURE_
parameter_list|(
name|statement
parameter_list|,
name|fail
parameter_list|)
define|\
value|GTEST_AMBIGUOUS_ELSE_BLOCKER_ \   if (const char* gtest_msg = "") { \     ::testing::internal::HasNewFatalFailureHelper gtest_fatal_failure_checker; \     { statement; } \     if (gtest_fatal_failure_checker.has_new_fatal_failure()) { \       gtest_msg = "Expected: " #statement " doesn't generate new fatal " \                   "failures in the current thread.\n" \                   "  Actual: it does."; \       goto GTEST_CONCAT_TOKEN_(gtest_label_testnofatal_, __LINE__); \     } \   } else \     GTEST_CONCAT_TOKEN_(gtest_label_testnofatal_, __LINE__): \       fail(gtest_msg)
end_define

begin_comment
comment|// Expands to the name of the class that implements the given test.
end_comment

begin_define
define|#
directive|define
name|GTEST_TEST_CLASS_NAME_
parameter_list|(
name|test_case_name
parameter_list|,
name|test_name
parameter_list|)
define|\
value|test_case_name##_##test_name##_Test
end_define

begin_comment
comment|// Helper macro for defining tests.
end_comment

begin_define
define|#
directive|define
name|GTEST_TEST_
parameter_list|(
name|test_case_name
parameter_list|,
name|test_name
parameter_list|,
name|parent_class
parameter_list|,
name|parent_id
parameter_list|)
define|\
value|class GTEST_TEST_CLASS_NAME_(test_case_name, test_name) : public parent_class {\  public:\   GTEST_TEST_CLASS_NAME_(test_case_name, test_name)() {}\  private:\   virtual void TestBody();\   static ::testing::TestInfo* const test_info_;\   GTEST_DISALLOW_COPY_AND_ASSIGN_(\       GTEST_TEST_CLASS_NAME_(test_case_name, test_name));\ };\ \ ::testing::TestInfo* const GTEST_TEST_CLASS_NAME_(test_case_name, test_name)\   ::test_info_ =\     ::testing::internal::MakeAndRegisterTestInfo(\         #test_case_name, #test_name, "", "", \         (parent_id), \         parent_class::SetUpTestCase, \         parent_class::TearDownTestCase, \         new ::testing::internal::TestFactoryImpl<\             GTEST_TEST_CLASS_NAME_(test_case_name, test_name)>);\ void GTEST_TEST_CLASS_NAME_(test_case_name, test_name)::TestBody()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_INCLUDE_GTEST_INTERNAL_GTEST_INTERNAL_H_
end_comment

end_unit

